/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-08-04 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  Released under the MIT License
 *  ==============================================================================
 */

/*  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
*/

#include "KeyPress_Auxilary.h"
#include "KeyPress.h"

#include <assert.h>
#include <memory.h>
#include <stdbool.h>
#include <stddef.h>

#include <ncurses.h>

/* The implementation of the guards */
bool KeyPress_IsCountingFinished(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInstance )
{
  bool const result = ! KeyPress_IsIn_Numeric_Region(smInfo) &&
                      ! KeyPress_IsIn_Alpha_Region(smInfo);
  return result;
} /* End of guard function: KeyPress_IsCountingFinished */

/* The implementation of the actions */
void KeyPress_Count1(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countDigit[0] = pInputData->countDigit[0] + 1;
} /* End of action function: KeyPress_Count1 */

void KeyPress_Count2(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countDigit[1] = pInputData->countDigit[1] + 1;
} /* End of action function: KeyPress_Count2 */

void KeyPress_Count3(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countDigit[2] = pInputData->countDigit[2] + 1;
} /* End of action function: KeyPress_Count3 */

void KeyPress_Count4(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countDigit[3] = pInputData->countDigit[3] + 1;
} /* End of action function: KeyPress_Count4 */

void KeyPress_Count5(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countDigit[4] = pInputData->countDigit[4] + 1;
} /* End of action function: KeyPress_Count5 */

void KeyPress_Count6(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countDigit[5] = pInputData->countDigit[5] + 1;
} /* End of action function: KeyPress_Count6 */

void KeyPress_Count7(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countDigit[6] = pInputData->countDigit[6] + 1;
} /* End of action function: KeyPress_Count7 */

void KeyPress_Count8(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countDigit[7] = pInputData->countDigit[7] + 1;
} /* End of action function: KeyPress_Count8 */

void KeyPress_Count9(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countDigit[8] = pInputData->countDigit[8] + 1;
} /* End of action function: KeyPress_Count9 */

void KeyPress_CountA(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countA = pInputData->countA + 1;
} /* End of action function: KeyPress_CountA */

void KeyPress_CountB(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countB = pInputData->countB + 1;
} /* End of action function: KeyPress_CountB */

void KeyPress_CountC(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countC = pInputData->countC + 1;
} /* End of action function: KeyPress_CountC */

void KeyPress_CountEven(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countEven = pInputData->countEven + 1;
} /* End of action function: KeyPress_CountEven */

void KeyPress_CountOdd(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countOdd = pInputData->countOdd + 1;
} /* End of action function: KeyPress_CountOdd */

void KeyPress_LogCounters(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  printw("\r%5u %-4zu %-4zu %-4zu %-4zu %-4zu",
    pInputData->issueId,
    pInputData->countA,
    pInputData->countB,
    pInputData->countC,
    pInputData->countOdd,
    pInputData->countEven );
  for(size_t i=0; i < sizeof(pInputData->countDigit)/sizeof(pInputData->countDigit[0]); ++i)
  {
    printw(" %-4zu", pInputData->countDigit[i] );
  }

  char alphaStatus;
  char numericStatus;

  if ( KeyPress_IsIn_ReadLetters_State(smInfo) )
  {
    alphaStatus= 'Y';
  }
  else if ( KeyPress_IsIn_Pause_State(smInfo))
  {
    alphaStatus='P';
  }
  else {
  alphaStatus= 'N';
  }

  if ( KeyPress_IsIn_ReadDigits_State(smInfo) )
  {
    numericStatus= 'Y';
  }
  else
  {
     numericStatus= 'N';
  }

  printw(" %-2c %-2c", alphaStatus, numericStatus );

  pOutputData->issueId = pInputData->issueId + 1;
} /* End of action function: KeyPress_LogCounters */

void KeyPress_LogHeaders(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  printw("\n%5s %-4s %-4s %-4s %-4s %-4s", "Issue", "A", "B", "C", "Odd", "Even" );
  for(size_t i=0; i < sizeof(pInputData->countDigit)/sizeof(pInputData->countDigit[0]); ++i)
  {
    printw(" %-4zu", i+1 );
  }
  printw(" CA CN\n");

  printw( "----- ---- ---- ---- ---- ----");
  for(size_t i=0; i < sizeof(pInputData->countDigit)/sizeof(pInputData->countDigit[0]); ++i)
  {
    printw(" ----");
  }

  printw(" -- --\n");
} /* End of action function: KeyPress_LogHeaders */

void KeyPress_MessageGoodBye(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  printw("\nSee you next time. Good Bye\n");
} /* End of action function: KeyPress_MessageGoodBye */

void KeyPress_MessageHello(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  printw("Counts letter A, B and C, all are incase sensitive, and mumbers between 1 and 9 pressed using by keyboard.\n");
  printw("Pressing F12 will pause the counting letters A, B and C.\n");
  printw("To resume the counting press F12 again.\n");
  printw("Pressing F1 will stop the counting letters perminantly.\n");
  printw("Pressing F2 key will stop the counting numbers perminantly.\n");
  printw("Pressing DEL or BACKSPACE will be reset the counters for numeric keys.\n");
  printw("Pressing SPACE will be reset the counters for letters keys.\n\n");
}  /* End of action function: KeyPress_MessageHello */

void KeyPress_MessagePressSpaceToExit(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  printw("\nPress SPACE to exit\n");
} /* End of action function: KeyPress_MessagePressSpaceToExit */

void KeyPress_ResetLetterCounters(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countA=
  pOutputData->countB=
  pOutputData->countC= 0;
} /* End of action function: KeyPress_ResetLetterCounters */

void KeyPress_ResetNumericCounters(
  __attribute__( ( unused ) ) S_SM_KeyPress_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t * const pOutputData )
{
  pOutputData->countOdd=
  pOutputData->countEven= 0;

  for(size_t i=0; i < sizeof(pOutputData->countDigit)/sizeof(pOutputData->countDigit[0]); ++i)
  {
    pOutputData->countDigit[i]= 0;
  }
}

/* End of KeyPress_Auxilary.c */
