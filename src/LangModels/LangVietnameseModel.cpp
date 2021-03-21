/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
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
 * The Original Code is Mozilla Communicator client code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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

#include "../nsSBCharSetProber.h"
#include "../nsLanguageDetector.h"

/********* Language model for: Vietnamese *********/

/**
 * Generated by BuildLangModel.py
 * On: 2021-03-21 15:20:14.350353
 **/

/* Character Mapping Table:
 * ILL: illegal character.
 * CTR: control character specific to the charset.
 * RET: carriage/return.
 * SYM: symbol (punctuation) that does not belong to word.
 * NUM: 0 - 9.
 *
 * Other characters are ordered by probabilities
 * (0 is the most common character in the language).
 *
 * Orders are generic to a language. So the codepoint with order X in
 * CHARSET1 maps to the same character as the codepoint with the same
 * order X in CHARSET2 for the same language.
 * As such, it is possible to get missing order. For instance the
 * ligature of 'o' and 'e' exists in ISO-8859-15 but not in ISO-8859-1
 * even though they are both used for French. Same for the euro sign.
 */
static const unsigned char Windows_1258_CharToOrderMap[] =
{
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, /* 0X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 1X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* 2X */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, /* 3X */
  SYM,  6, 18,  3, 21, 24, 71,  5,  1,  4, 78, 22, 14,  8,  0,  9, /* 4X */
   16, 32, 13, 19,  2,  7, 12, 74, 53, 20, 83,SYM,SYM,SYM,SYM,SYM, /* 5X */
  SYM,  6, 18,  3, 21, 24, 71,  5,  1,  4, 78, 22, 14,  8,  0,  9, /* 6X */
   16, 32, 13, 19,  2,  7, 12, 74, 53, 20, 83,SYM,SYM,SYM,SYM,CTR, /* 7X */
  SYM,ILL,SYM,105,SYM,SYM,SYM,SYM,SYM,SYM,ILL,SYM, 97,ILL,ILL,ILL, /* 8X */
  ILL,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,ILL,SYM, 97,ILL,ILL,104, /* 9X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* AX */
  SYM,SYM,SYM,SYM,SYM,107,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* BX */
   11, 15, 27, 44,101,106, 95, 92, 90, 73, 28,108,SYM, 39,103,102, /* CX */
   10,100,SYM, 35, 29, 47, 98,SYM, 96, 62, 61,109, 93, 17,SYM, 99, /* DX */
   11, 15, 27, 44,101,106, 95, 92, 90, 73, 28,110,SYM, 39,103,102, /* EX */
   10,100,SYM, 35, 29, 47, 98,SYM, 96, 62, 61,111, 93, 17,112,104, /* FX */
};
/*X0  X1  X2  X3  X4  X5  X6  X7  X8  X9  XA  XB  XC  XD  XE  XF */

static const unsigned char Viscii_CharToOrderMap[] =
{
  CTR,CTR, 86,CTR,CTR, 91, 77,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, /* 0X */
  CTR,CTR,CTR,CTR, 82,CTR,CTR,CTR,CTR, 84,CTR,CTR,CTR,CTR, 94,CTR, /* 1X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* 2X */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, /* 3X */
  SYM,  6, 18,  3, 21, 24, 71,  5,  1,  4, 78, 22, 14,  8,  0,  9, /* 4X */
   16, 32, 13, 19,  2,  7, 12, 74, 53, 20, 83,SYM,SYM,SYM,SYM,SYM, /* 5X */
  SYM,  6, 18,  3, 21, 24, 71,  5,  1,  4, 78, 22, 14,  8,  0,  9, /* 6X */
   16, 32, 13, 19,  2,  7, 12, 74, 53, 20, 83,SYM,SYM,SYM,SYM,CTR, /* 7X */
   31, 60, 68, 64, 42, 51, 76, 46, 80, 89, 23, 38, 43, 72, 26, 30, /* 8X */
   49, 59, 81, 25, 41, 37, 40, 57, 45, 75, 54, 70, 36, 69, 50, 79, /* 9X */
   85, 60, 68, 64, 42, 51, 76, 46, 80, 89, 23, 38, 43, 72, 26, 30, /* AX */
   49, 59, 81, 87, 47, 25, 40, 57, 45, 48, 55, 58, 65, 47, 37, 17, /* BX */
   11, 15, 27, 56, 33, 44, 86, 91, 90, 73, 28, 88, 52, 39, 67, 79, /* CX */
   10, 55, 63, 35, 29, 31, 82, 58, 65, 62, 61, 84, 94, 66, 87, 17, /* DX */
   11, 15, 27, 56, 33, 44, 34, 77, 90, 73, 28, 88, 52, 39, 67, 70, /* EX */
   10, 48, 63, 35, 29, 85, 75, 54, 50, 62, 61, 69, 36, 66, 41, 34, /* FX */
};
/*X0  X1  X2  X3  X4  X5  X6  X7  X8  X9  XA  XB  XC  XD  XE  XF */

static const int Unicode_Char_size = 190;
static const unsigned int Unicode_CharOrder[] =
{
    65,  6,   66, 18,   67,  3,   68, 21,   69, 24,   70, 71,   71,  5,  72,  1,
    73,  4,   74, 78,   75, 22,   76, 14,   77,  8,   78,  0,   79,  9,  80, 16,
    81, 32,   82, 13,   83, 19,   84,  2,   85,  7,   86, 12,   87, 74,  88, 53,
    89, 20,   90, 83,   97,  6,   98, 18,   99,  3,  100, 21,  101, 24, 102, 71,
   103,  5,  104,  1,  105,  4,  106, 78,  107, 22,  108, 14,  109,  8, 110,  0,
   111,  9,  112, 16,  113, 32,  114, 13,  115, 19,  116,  2,  117,  7, 118, 12,
   119, 74,  120, 53,  121, 20,  122, 83,  192, 11,  193, 15,  194, 27, 195, 56,
   199, 92,  200, 90,  201, 73,  202, 28,  204, 52,  205, 39,  210, 63, 211, 35,
   212, 29,  213, 85,  217, 62,  218, 61,  220, 93,  221, 66,  224, 11, 225, 15,
   226, 27,  227, 56,  231, 92,  232, 90,  233, 73,  234, 28,  236, 52, 237, 39,
   242, 63,  243, 35,  244, 29,  245, 85,  249, 62,  250, 61,  252, 93, 253, 66,
   258, 44,  259, 44,  272, 10,  273, 10,  296, 67,  297, 67,  360, 69, 361, 69,
   416, 47,  417, 47,  431, 17,  432, 17, 7840, 31, 7841, 31, 7842, 33,7843, 33,
  7844, 42, 7845, 42, 7846, 51, 7847, 51, 7848, 76, 7849, 76, 7850, 77,7851, 77,
  7852, 46, 7853, 46, 7854, 60, 7855, 60, 7856, 68, 7857, 68, 7858, 86,7859, 86,
  7860, 91, 7861, 91, 7862, 64, 7863, 64, 7864, 89, 7865, 89, 7866, 88,7867, 88,
  7868, 80, 7869, 80, 7870, 23, 7871, 23, 7872, 38, 7873, 38, 7874, 43,7875, 43,
  7876, 72, 7877, 72, 7878, 26, 7879, 26, 7880, 70, 7881, 70, 7882, 45,7883, 45,
  7884, 54, 7885, 54, 7886, 75, 7887, 75, 7888, 30, 7889, 30, 7890, 49,7891, 49,
  7892, 59, 7893, 59, 7894, 81, 7895, 81, 7896, 25, 7897, 25, 7898, 37,7899, 37,
  7900, 40, 7901, 40, 7902, 57, 7903, 57, 7904, 87, 7905, 87, 7906, 41,7907, 41,
  7908, 50, 7909, 50, 7910, 36, 7911, 36, 7912, 55, 7913, 55, 7914, 58,7915, 58,
  7916, 65, 7917, 65, 7918, 34, 7919, 34, 7920, 48, 7921, 48, 7922, 79,7923, 79,
  7924, 94, 7925, 94, 7926, 82, 7927, 82, 7928, 84, 7929, 84,
};


/* Model Table:
 * Total considered sequences: 1892 / 9025
 * - Positive sequences: first 1119 (0.9950141222722985)
 * - Probable sequences: next 364 (1483-1119) (0.003989870519062855)
 * - Neutral sequences: last 7542 (0.0009960072086386829)
 * - Negative sequences: 7133 (off-ratio)
 * Negative sequences: TODO
 */
static const PRUint8 VietnameseLangModel[] =
{
  3,3,3,3,3,3,3,3,2,3,2,3,2,3,3,3,1,3,2,3,3,3,3,3,3,3,1,3,3,3,3,3,3,1,3,3,0,2,3,2,0,2,2,0,3,1,2,
   3,0,2,0,2,0,3,2,2,2,1,0,3,3,3,2,2,3,3,0,0,3,0,0,3,0,3,2,0,0,0,3,0,0,3,0,3,0,0,0,1,0,0,2,3,3,1,0,
  3,1,3,2,3,0,3,3,3,3,1,3,1,3,3,3,2,3,1,2,3,3,1,3,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
   3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,0,3,3,1,3,2,0,3,1,3,3,2,0,0,3,3,2,2,0,1,3,2,2,3,3,2,0,0,0,
  3,3,3,3,3,1,3,3,3,3,0,3,3,3,3,3,2,3,1,3,3,3,2,3,3,3,3,3,3,3,3,3,0,3,0,3,2,3,2,3,3,0,3,0,3,3,3,
   1,3,3,3,3,3,1,2,3,2,0,3,3,3,3,3,3,2,3,1,3,0,0,3,2,1,3,3,3,2,0,0,1,0,0,3,2,0,1,0,0,1,0,2,0,0,1,1,
  3,3,3,3,3,0,3,3,2,3,3,3,2,3,3,3,3,3,2,3,3,3,3,0,3,3,0,3,0,3,3,3,2,3,1,3,3,1,0,2,3,1,3,0,3,0,3,
   3,3,0,3,3,0,1,1,3,3,1,2,3,3,3,3,3,3,3,0,0,1,3,0,0,0,1,3,2,3,0,1,0,0,2,0,1,0,1,1,2,0,0,1,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,2,3,3,2,3,3,3,3,0,3,2,3,3,3,1,3,3,3,3,0,3,3,0,3,0,3,3,1,0,2,
   1,0,0,1,1,0,3,3,0,2,0,0,0,0,3,1,0,3,0,0,0,0,1,0,3,3,2,0,2,0,2,2,0,1,1,0,3,0,0,0,1,1,1,2,0,1,0,0,
  3,3,2,1,3,2,3,3,2,3,1,3,2,3,3,3,2,3,1,3,3,2,2,2,3,3,0,3,1,3,3,3,0,2,3,3,2,1,0,0,3,3,2,0,3,2,2,
   2,3,3,3,3,3,1,3,0,3,1,3,1,3,0,0,3,3,3,0,0,1,3,0,1,0,2,1,1,1,1,0,0,0,2,0,0,0,3,0,2,0,0,2,0,0,1,0,
  3,3,3,3,3,3,2,3,3,3,2,0,3,3,3,0,3,0,3,3,3,3,3,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
   0,0,0,0,0,0,3,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,0,3,0,0,0,0,2,0,0,0,0,0,0,0,0,3,1,0,
  3,2,3,3,3,3,3,2,3,3,0,2,2,3,3,3,3,0,3,3,3,3,3,3,3,3,2,3,3,3,3,3,1,3,0,0,0,1,1,2,2,0,3,0,1,0,3,
   2,0,3,0,3,0,2,1,0,2,2,0,3,0,0,0,0,2,0,3,0,0,0,0,2,0,2,1,0,3,3,2,3,1,3,3,3,2,0,0,0,1,0,1,0,1,0,2,
  3,1,2,3,3,1,3,3,3,3,0,3,1,3,3,3,3,3,3,3,2,2,1,2,3,3,3,3,2,3,3,3,0,3,0,3,1,3,3,1,3,0,3,0,2,2,3,
   2,3,3,3,3,3,2,3,3,3,3,3,0,3,2,3,2,3,0,0,3,1,3,1,2,0,3,1,2,2,3,1,1,2,3,0,0,3,1,0,0,1,3,1,0,0,0,1,
  3,3,3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,0,3,3,2,3,3,0,3,0,0,0,0,0,0,3,2,3,0,0,0,0,0,0,0,0,0,0,3,0,0,
   0,0,0,0,0,0,3,0,0,3,0,0,0,3,0,0,0,3,0,0,0,1,0,0,3,0,1,3,0,0,0,2,0,0,0,0,3,0,0,0,0,2,0,2,1,0,0,0,
  0,3,1,0,3,0,3,3,0,3,0,3,0,2,0,3,0,3,1,0,0,0,1,3,3,3,3,3,3,3,3,3,0,3,0,3,3,2,3,3,3,3,3,3,3,3,3,
   3,3,3,2,3,3,0,3,3,3,0,2,3,3,3,2,3,3,0,0,2,2,1,3,0,0,1,0,3,3,1,0,0,0,3,0,0,0,0,3,3,2,3,2,0,0,0,0,
  3,0,0,0,3,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,2,1,0,3,1,3,3,0,3,0,3,0,2,1,3,1,3,0,2,2,2,2,2,3,1,3,3,2,3,3,3,0,2,3,1,0,3,3,3,1,3,3,0,3,3,3,
   1,3,0,3,3,3,0,3,1,2,3,3,0,3,0,3,3,1,0,0,3,0,3,1,0,0,2,0,2,1,3,1,0,3,2,0,0,2,3,0,2,3,3,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3,3,3,3,3,3,1,3,3,2,2,3,3,3,3,2,3,3,2,2,0,0,3,3,3,3,1,3,3,3,
   2,3,3,3,3,3,3,3,2,3,3,3,2,3,3,3,3,1,3,0,0,3,0,1,2,2,3,2,1,1,0,1,0,2,2,0,1,0,3,0,0,3,0,1,0,1,1,0,
  2,3,3,3,3,3,3,3,3,3,0,3,3,1,3,3,3,3,3,3,3,3,2,0,3,3,3,3,3,3,3,3,1,0,3,2,0,3,1,3,3,3,3,0,3,3,3,
   1,3,1,3,3,1,2,3,0,3,0,2,0,3,3,2,3,3,3,3,3,0,2,0,3,3,3,1,2,0,3,1,0,3,3,0,0,0,1,0,0,2,1,1,0,0,1,2,
  3,0,3,3,3,1,0,3,3,3,0,0,1,2,2,0,3,0,2,1,3,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,3,3,1,3,2,3,3,2,3,0,0,0,3,3,2,3,1,1,3,2,2,0,0,3,0,0,1,1,2,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,
   0,0,1,0,0,0,1,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
  3,1,3,1,2,0,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,3,3,0,0,0,0,0,
   3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,
  3,2,1,3,3,0,3,3,2,3,0,3,1,3,3,3,0,3,3,3,3,2,1,3,3,3,3,3,3,2,3,3,0,3,2,3,0,3,3,3,3,0,3,1,3,3,3,
   2,1,3,2,3,3,1,3,3,3,3,1,3,3,3,3,2,0,2,0,0,3,0,3,1,0,3,1,3,2,0,2,0,1,2,0,0,0,1,0,1,0,1,2,0,0,1,0,
  2,3,3,3,3,2,3,3,3,3,0,3,1,2,3,3,3,3,3,3,3,2,3,0,3,1,0,3,1,3,3,2,2,3,1,3,2,3,0,1,1,3,3,0,1,0,1,
   3,3,2,2,1,1,0,0,3,2,3,0,2,3,3,3,0,1,3,0,3,0,0,0,2,0,3,2,0,0,0,2,0,3,0,0,2,2,0,0,0,2,0,1,3,0,0,0,
  3,0,2,3,2,2,3,3,3,3,0,0,0,3,3,0,3,0,3,3,2,2,2,3,3,0,3,0,3,0,0,0,0,0,0,1,0,0,3,0,0,0,0,3,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
  3,2,1,3,3,3,3,3,2,3,0,3,1,3,3,2,2,3,2,3,2,2,1,0,3,2,2,3,1,0,2,3,0,2,3,2,0,0,2,3,2,0,3,1,0,3,3,
   1,3,2,3,3,2,0,3,3,3,2,2,0,2,0,3,3,3,0,0,3,1,2,0,2,3,2,3,0,0,3,2,0,0,1,0,3,0,2,2,1,2,1,2,0,0,0,0,
  3,3,2,0,3,0,3,3,3,3,0,0,3,3,2,2,0,0,1,3,2,1,1,3,3,0,1,0,3,3,0,1,0,0,0,1,2,0,0,3,0,0,0,3,1,3,0,
   2,0,0,1,1,3,0,0,1,0,0,0,0,0,0,0,0,0,0,3,2,0,0,2,0,0,3,2,0,0,0,0,3,2,0,3,1,3,0,0,0,3,2,3,0,0,0,1,
  3,0,3,3,0,0,0,3,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,0,0,3,3,3,0,3,0,3,3,3,3,3,0,3,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,1,0,0,
  3,0,3,3,3,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,0,0,0,3,3,0,0,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,2,2,0,0,0,3,3,0,0,0,0,0,1,0,1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,2,2,1,2,0,3,3,0,2,0,0,3,0,0,2,0,0,3,0,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,2,2,3,1,0,0,3,0,0,0,0,2,0,0,2,0,1,0,0,1,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,3,0,0,0,2,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,3,0,0,0,3,3,0,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,1,0,0,1,0,1,3,0,2,2,0,0,2,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,3,0,3,1,3,0,0,0,0,2,0,0,3,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,1,0,2,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,3,0,0,1,3,0,0,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,0,1,3,1,3,1,0,0,0,1,1,0,2,0,0,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,3,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,2,2,0,0,3,3,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,2,2,0,0,0,0,3,0,0,0,0,0,1,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,0,0,3,3,1,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,0,0,0,3,3,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,2,1,3,0,0,2,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,3,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,2,3,2,0,1,0,3,0,0,0,0,0,0,0,3,0,0,0,3,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,1,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,2,3,2,3,0,3,3,1,3,0,1,3,0,2,3,2,3,0,0,2,1,0,3,3,1,0,3,2,3,0,2,0,3,0,3,0,0,0,3,0,0,3,0,1,1,0,
   1,0,0,0,0,1,3,0,3,3,1,0,0,0,3,1,0,0,3,0,0,0,0,1,2,0,3,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,
  3,0,2,3,3,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,1,0,0,3,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,3,0,3,0,1,0,0,0,0,1,1,0,3,0,2,1,3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,3,0,2,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,3,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,3,3,0,0,0,0,2,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,0,0,0,3,0,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,3,3,2,3,1,3,2,1,3,0,0,0,3,2,2,1,1,1,1,0,0,0,0,3,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,
   0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,3,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
  3,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,1,3,2,1,2,1,0,3,3,0,0,2,3,2,0,3,0,2,3,0,2,1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  2,3,1,2,3,0,3,2,1,3,0,0,0,3,2,0,1,0,1,3,3,2,1,0,3,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,
   1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
  3,0,0,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,0,3,2,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,0,0,0,3,1,3,3,1,3,0,0,0,2,0,0,1,0,0,1,1,0,1,0,3,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   1,0,0,0,0,1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,1,0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,2,0,0,3,0,3,3,0,3,0,1,0,0,0,2,0,0,0,1,2,0,1,3,3,0,0,2,0,0,0,2,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,
   0,0,0,2,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,2,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,2,1,0,1,0,0,3,3,0,0,2,2,1,0,0,0,1,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};


const SequenceModel Windows_1258VietnameseModel =
{
  Windows_1258_CharToOrderMap,
  VietnameseLangModel,
  95,
  (float)0.9990039927913613,
  PR_FALSE,
  "WINDOWS-1258",
  "vi"
};

const SequenceModel VisciiVietnameseModel =
{
  Viscii_CharToOrderMap,
  VietnameseLangModel,
  95,
  (float)0.9990039927913613,
  PR_FALSE,
  "VISCII",
  "vi"
};

const LanguageModel VietnameseModel =
{
  "vi",
  Unicode_CharOrder,
  190,
  VietnameseLangModel,
  95,
  (float)0.9999159700479902,
};
