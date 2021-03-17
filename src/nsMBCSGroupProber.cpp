/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Universal charset detector code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 2001
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *          Shy Shalom <shooshX@gmail.com>
 *			Proofpoint, Inc.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */
#include <stdio.h>

#include "nsMBCSGroupProber.h"
#include "nsUniversalDetector.h"

#if defined(DEBUG_chardet) || defined(DEBUG_jgmyers)
const char *ProberName[] = 
{
  "UTF-8",
  "SJIS",
  "EUC-JP",
  "GB18030",
  "EUC-KR",
  "Big5",
  "EUC-TW",
};

#endif

nsMBCSGroupProber::nsMBCSGroupProber(PRUint32 aLanguageFilter)
{
  for (PRUint32 i = 0; i < NUM_OF_PROBERS; i++)
  {
    mProbers[i]            = nsnull;
    codePointBuffer[i]     = nsnull;
    codePointBufferSize[i] = 0;
    codePointBufferIdx[i]  = 0;
  }

  mProbers[0] = new nsUTF8Prober();
  if (aLanguageFilter & NS_FILTER_JAPANESE) 
  {
    mProbers[1] = new nsSJISProber(aLanguageFilter == NS_FILTER_JAPANESE);
    mProbers[2] = new nsEUCJPProber(aLanguageFilter == NS_FILTER_JAPANESE);
  }
  if (aLanguageFilter & NS_FILTER_CHINESE_SIMPLIFIED)
    mProbers[3] = new nsGB18030Prober(aLanguageFilter == NS_FILTER_CHINESE_SIMPLIFIED);
  if (aLanguageFilter & NS_FILTER_KOREAN)
    mProbers[4] = new nsEUCKRProber(aLanguageFilter == NS_FILTER_KOREAN);
  if (aLanguageFilter & NS_FILTER_CHINESE_TRADITIONAL) 
  {
    mProbers[5] = new nsBig5Prober(aLanguageFilter == NS_FILTER_CHINESE_TRADITIONAL);
    mProbers[6] = new nsEUCTWProber(aLanguageFilter == NS_FILTER_CHINESE_TRADITIONAL);
  }

  for (PRUint32 i = 0; i < NUM_OF_PROBERS; i++)
  {
    if (mProbers[i]->DecodeToUnicode())
    {
      int j = 0;

      langDetectors[i][j++] = new nsLanguageDetector(&ArabicModel);
      langDetectors[i][j++] = new nsLanguageDetector(&CroatianModel);
      langDetectors[i][j++] = new nsLanguageDetector(&CzechModel);
      langDetectors[i][j++] = new nsLanguageDetector(&DanishModel);
      langDetectors[i][j++] = new nsLanguageDetector(&EsperantoModel);
      langDetectors[i][j++] = new nsLanguageDetector(&EstonianModel);
      langDetectors[i][j++] = new nsLanguageDetector(&FinnishModel);
      langDetectors[i][j++] = new nsLanguageDetector(&FrenchModel);
      langDetectors[i][j++] = new nsLanguageDetector(&GermanModel);
      langDetectors[i][j++] = new nsLanguageDetector(&GreekModel);
      langDetectors[i][j++] = new nsLanguageDetector(&HungarianModel);
      langDetectors[i][j++] = new nsLanguageDetector(&IrishModel);
      langDetectors[i][j++] = new nsLanguageDetector(&ItalianModel);
      langDetectors[i][j++] = new nsLanguageDetector(&LatvianModel);
      langDetectors[i][j++] = new nsLanguageDetector(&LithuanianModel);
      langDetectors[i][j++] = new nsLanguageDetector(&MalteseModel);
      langDetectors[i][j++] = new nsLanguageDetector(&PolishModel);
      langDetectors[i][j++] = new nsLanguageDetector(&PortugueseModel);
      langDetectors[i][j++] = new nsLanguageDetector(&RomanianModel);
      langDetectors[i][j++] = new nsLanguageDetector(&SlovakModel);
      langDetectors[i][j++] = new nsLanguageDetector(&SloveneModel);
      langDetectors[i][j++] = new nsLanguageDetector(&SpanishModel);
      langDetectors[i][j++] = new nsLanguageDetector(&SwedishModel);
      langDetectors[i][j++] = new nsLanguageDetector(&ThaiModel);
      langDetectors[i][j++] = new nsLanguageDetector(&TurkishModel);
      langDetectors[i][j++] = new nsLanguageDetector(&VietnameseModel);
    }
    else
    {
      for (PRUint32 j = 0; j < NUM_OF_LANGUAGES; j++)
        langDetectors[i][j] = nsnull;
    }
  }
  Reset();
}

nsMBCSGroupProber::~nsMBCSGroupProber()
{
  for (PRUint32 i = 0; i < NUM_OF_PROBERS; i++)
  {
    delete mProbers[i];

    if (codePointBufferSize[i] != 0)
      delete [] codePointBuffer[i];

    for (PRUint32 j = 0; j < NUM_OF_LANGUAGES; j++)
      if (langDetectors[i][j])
        delete langDetectors[i][j];
  }
}

const char* nsMBCSGroupProber::GetCharSetName()
{
  if (mBestGuess == -1)
  {
    GetConfidence();
    if (mBestGuess == -1)
      mBestGuess = 0;
  }
  return mProbers[mBestGuess]->GetCharSetName();
}

const char* nsMBCSGroupProber::GetLanguage(void)
{
  const char* maxLang       = NULL;
  int         maxLangIdx    = -1;
  float       maxConfidence = 0.0;

  if (mBestGuess == -1)
    return NULL;
  else
    maxLang = mProbers[mBestGuess]->GetLanguage();

  if (maxLang == NULL && mProbers[mBestGuess]->DecodeToUnicode())
  {
    for (PRUint32 j = 0; j < NUM_OF_LANGUAGES; j++)
    {
      float conf = langDetectors[mBestGuess][j]->GetConfidence();

      if (conf > maxConfidence)
      {
        maxLangIdx = j;
        maxConfidence = conf;
      }
    }
    if (maxLangIdx != -1)
      maxLang = langDetectors[mBestGuess][maxLangIdx]->GetLanguage();
  }

  return maxLang;
}

void nsMBCSGroupProber::Reset(void)
{
  mActiveNum = 0;
  for (PRUint32 i = 0; i < NUM_OF_PROBERS; i++)
  {
    if (mProbers[i])
    {
      mProbers[i]->Reset();
      mIsActive[i] = PR_TRUE;
      ++mActiveNum;

      if (codePointBufferSize[i] == 0 && mProbers[i]->DecodeToUnicode())
      {
        codePointBufferSize[i] = 1024;
        codePointBuffer[i] = new int[codePointBufferSize[i]];
      }
      codePointBufferIdx[i] = 0;
    }
    else
      mIsActive[i] = PR_FALSE;
  }
  mBestGuess = -1;
  mState = eDetecting;
  mKeepNext = 0;
}

nsProbingState nsMBCSGroupProber::HandleData(const char* aBuf, PRUint32 aLen,
                                             int** cpBuffer,
                                             int*  cpBufferIdx)
{
  nsProbingState st;
  PRUint32 start = 0;
  PRUint32 keepNext = mKeepNext;

  //do filtering to reduce load to probers
  for (PRUint32 pos = 0; pos < aLen; ++pos)
  {
    if (aBuf[pos] & 0x80)
    {
      if (!keepNext)
        start = pos;
      keepNext = 2;
    }
    else if (keepNext)
    {
      if (--keepNext == 0)
      {
        for (PRUint32 i = 0; i < NUM_OF_PROBERS; i++)
        {
          if (!mIsActive[i])
            continue;

          if (codePointBuffer[i])
            st = mProbers[i]->HandleData(aBuf + start, pos + 1 - start,
                                         &(codePointBuffer[i]), &(codePointBufferIdx[i]));
          else
            st = mProbers[i]->HandleData(aBuf + start, pos + 1 - start, NULL, NULL);

          if (codePointBufferIdx[i] > 0 && codePointBuffer[i])
          {
            for (PRUint32 j = 0; j < NUM_OF_LANGUAGES; j++)
              langDetectors[i][j]->HandleData(codePointBuffer[i], codePointBufferIdx[i]);
            codePointBufferIdx[i] = 0;
          }

          if (st == eFoundIt)
          {
            mBestGuess = i;
            mState = eFoundIt;
            return mState;
          }
        }
      }
    }
    else
    {
      for (PRUint32 i = 0; i < NUM_OF_PROBERS; i++)
        if (codePointBuffer[i])
          codePointBuffer[i][(codePointBufferIdx[i])++] = aBuf[pos];
    }
  }

  if (keepNext) {
    for (PRUint32 i = 0; i < NUM_OF_PROBERS; i++)
    {
      if (!mIsActive[i])
        continue;

      if (codePointBuffer[i])
        st = mProbers[i]->HandleData(aBuf + start, aLen - start,
                                     &(codePointBuffer[i]), &(codePointBufferIdx[i]));
      else
        st = mProbers[i]->HandleData(aBuf + start, aLen - start, NULL, NULL);

      if (codePointBufferIdx[i] > 0 && codePointBuffer[i])
      {
        for (PRUint32 j = 0; j < NUM_OF_LANGUAGES; j++)
          langDetectors[i][j]->HandleData(codePointBuffer[i], codePointBufferIdx[i]);
        codePointBufferIdx[i] = 0;
      }

      if (st == eFoundIt)
      {
        mBestGuess = i;
        mState = eFoundIt;
        return mState;
      }
    }
  }
  mKeepNext = keepNext;

  return mState;
}

float nsMBCSGroupProber::GetConfidence(void)
{
  PRUint32 i;
  float bestConf = 0.0, cf;

  switch (mState)
  {
  case eFoundIt:
    return (float)0.99;
  case eNotMe:
    return (float)0.01;
  default:
    for (i = 0; i < NUM_OF_PROBERS; i++)
    {
      if (!mIsActive[i])
        continue;
      cf = mProbers[i]->GetConfidence();
      if (bestConf < cf)
      {
        bestConf = cf;
        mBestGuess = i;
      }
    }
  }
  return bestConf;
}

#ifdef DEBUG_chardet
void nsMBCSGroupProber::DumpStatus()
{
  PRUint32 i;
  float cf;
  
  GetConfidence();
  for (i = 0; i < NUM_OF_PROBERS; i++)
  {
    if (!mIsActive[i])
      printf("  MBCS inactive: [%s] (confidence is too low).\r\n", ProberName[i]);
    else
    {
      cf = mProbers[i]->GetConfidence();
      printf("  MBCS %1.3f: [%s]\r\n", cf, ProberName[i]);
    }
  }
}
#endif

#ifdef DEBUG_jgmyers
void nsMBCSGroupProber::GetDetectorState(nsUniversalDetector::DetectorState (&states)[nsUniversalDetector::NumDetectors], PRUint32 &offset)
{
  for (PRUint32 i = 0; i < NUM_OF_PROBERS; ++i) {
    states[offset].name = ProberName[i];
    states[offset].isActive = mIsActive[i];
    states[offset].confidence = mIsActive[i] ? mProbers[i]->GetConfidence() : 0.0;
    ++offset;
  }
}
#endif /* DEBUG_jgmyers */
