/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-07-29 GMT
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

/**********************************************/
/*               CASE 1                       */
/**********************************************/

#include "NumberGuess_Auxilary.h"

#include <assert.h>
#include <ctype.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* The implementation of the guards */
bool NumberGuess_AreNumbersEqual(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInstance )
{
  bool const result = ( pInstance->guess == pInstance->number );
  return result;
}

bool NumberGuess_IsAnswerNo(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInstance )
{
  bool const result = (pInstance->answer == 'N' || pInstance->answer == 'n');
  return result;
}

bool NumberGuess_IsAnswerYes(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInstance )
{
  bool const result = (pInstance->answer == 'Y' || pInstance->answer == 'y');
  return result;
}

bool NumberGuess_IsANumberRead(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInstance )
{
  bool const result = (pInstance->scan_result == 1);
  return result;
}

bool NumberGuess_IsNumberInRange(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInstance )
{
  bool const result = ( pInstance->guess > 0 && pInstance->guess < 100);
  return result;
}

/* The implementation of the actions */
void NumberGuess_AskEstimation(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  printf( "Please make an estimation : " );
  fflush(stdout);
}

void NumberGuess_PrintAskNewDeal(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  printf( "Do you wanna play more game? " );
  fflush(stdout);
}

void NumberGuess_PrintConguratulation(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  printf( "\n   *** Done. Congratulations! ***\n\n");
}

void NumberGuess_PrintGoodBye(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  printf( "\nSee you next time. Bye bye\n" );
}

void NumberGuess_PrintHints(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
   if ( pInputData->number > pInputData->guess )
   {
     printf( "Your guess, %u, is smaller\n", pInputData->guess );
   }
   else if ( pInputData->number < pInputData->guess )
   {
     printf( "Your guess, %u, is bigger\n", pInputData->guess );
   }
}

void NumberGuess_PrintNoNumberIsRead(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  printf( "Please enter a number!\n" );
}

void NumberGuess_PrintNumberIsNotInRange(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  printf( "Please enter a number betwen 1 and 100!\n");
}

void NumberGuess_PrintVola(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  printf( "Heyooo!\n");
}

void NumberGuess_PrintWarning(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  printf( "please answer pressing the key either 'Y' or 'N' only\n" );
}

void NumberGuess_ReadAnswerToContinue(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  char buffer[256];
  int readByte= read( 0, buffer, sizeof(buffer)-1 );
  pOutputData->answer= 0;
  if (readByte)
  {
    buffer[readByte]= '\0';
    size_t i = 0;
    while( i < readByte-1 && isspace( buffer[i]))
    {
      ++i;
    }
    pOutputData->answer= buffer[i];
  }
  fflush(stdin);
}

void NumberGuess_ReadEstimation(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  char buffer[256];
  int readByte= read( 0, buffer, sizeof(buffer)-1 );
  pOutputData->answer= 0;
  if (readByte)
  {
    buffer[readByte]= '\0';
    pOutputData->scan_result = sscanf( buffer, "%u", &pOutputData->guess);
    if (pOutputData->scan_result == 0 )
    {
      size_t i = 0;
      while( i < readByte-1 && isspace( buffer[i]))
      {
        ++i;
      }
      pOutputData->answer= buffer[i];
    }
  }
  fflush(stdin);
}

void NumberGuess_Salute(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  printf("\nHello there. Let's play. I will pick a number between 1 and 100. And you will guess the number I picked\n");
}

void NumberGuess_SetANumber(
  __attribute__((unused)) S_SM_NumberGuess_t* const smInfo,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_NumberGuess_DataType_t * const pOutputData )
{
  srand(time(0));
  pOutputData->number = (rand() % 100) + 1;
}

/* End of NumberGuess_Auxilary.c */
