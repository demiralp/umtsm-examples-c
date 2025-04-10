/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2024-08-11 GMT.
 * Copyright (C) 2023-2024 FEDEM (Fehmi Demiralp) <f.demiralp@gmail.com>.
 *
 * Released under the MIT License:
 *============================================================================*/

/*
Copyright (c) 2023-2024 Fedem (Fehmi Demiralp)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Calculator_Auxilary.h"

#include "Calculator.h"
#include "Calculator_DataType.h"
#include "Calculator_Utilities.h"

#include "Display.h"
#include "Display_DataType.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#include <ncurses.h>

/* The implementation of the guards */
bool Calculator_HasDivisionByZeroError(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInstance )
{
  bool result = pInstance->ErrorNo == E_DIVISION_BY_ZERO;
  return result;
}

bool Calculator_HasOverflowError(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInstance )
{
  bool result = pInstance->ErrorNo == E_OVERFLOW;
  return result;
}

bool Calculator_IsBaseZero(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInstance )
{
  bool result = true;
  char const * pStr= &smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits[0];
  while( result && *pStr != '\0')
  {
    result = (*pStr == '0');
    pStr++;
  }

  return result;
}

bool Calculator_IsExponentZero(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInstance )
{
  bool result = true;
  char const * pStr= &smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalDigits[0];
  while( result && *pStr != '\0')
  {
    result = (*pStr == '0');
    pStr++;
  }

  return result;
}

bool Calculator_IsFaulty(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInstance )
{
  bool const result = pInstance->ErrorNo == E_FAULTY;
  return result;
}

bool Calculator_IsFractionZero(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInstance )
{
  bool result = true;
  char const * pStr= &smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits[0];
  while( result && *pStr != '\0')
  {
    result = (*pStr == '0');
    pStr++;
  }

  return result;
}

bool Calculator_IsThereSpaceForExponent(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInstance )
{
  size_t const baseLen = greatest(1, strlen( smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits ) ) + 1;
  bool const isFracZero = Calculator_IsFractionZero(smInfo, pInstance );
  size_t const fractionLen = isFracZero? 0 : ( strlen( smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits ) + 1 );

  bool result = (baseLen+fractionLen) < 18;
  return result;
}


/* The implementation of the actions */
void Calculator_Additions(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Calculator_CalculateAccumulator( smInfo, pInputData, pOutputData, E_OP_PLUS );
}

void Calculator_Calculate(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Calculator_CalculateAccumulator( smInfo, pInputData, pOutputData, E_OP_ENTER );
}

void Calculator_ChangeBaseSign(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  smInfo->subsm.CalculatorDisplay.instanceData.BaseSignaturePositive = ! smInfo->subsm.CalculatorDisplay.instanceData.BaseSignaturePositive;
}

void Calculator_ChangeExponetSign(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalSignaturePositive = ! smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalSignaturePositive;
}

void Calculator_CheckErrorStatus(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  while (pInputData->ErrorNo == E_NO_ERROR)
  {
    usleep(500000);
  }
}

void Calculator_ClearExponent(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  smInfo->subsm.CalculatorDisplay.instanceData.ExponentStart = false;
  smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalSignaturePositive= true;
  smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalDigits[0] = '\0';
}

void Calculator_ClearFraction(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  smInfo->subsm.CalculatorDisplay.instanceData.FractinalStart= false;
  smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits[0] = '\0';
}

void Calculator_ClearLastEntry(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Display_DataType_Initialize(&smInfo->subsm.CalculatorDisplay.instanceData);
}

void Calculator_Divides(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Calculator_CalculateAccumulator( smInfo, pInputData, pOutputData, E_OP_DIVIDE );
}

void Calculator_DrawSpliteLine(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  printw("\n");
  for(int i=20; i; --i)
  {
    printw("-");
  }
  printw("\n");
}

void Calculator_EraseBaseDigit(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  size_t len= strlen(smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits);
  if ( len > 0 )
  {
    len--;
    smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits[len]= '\0';
  }
}

void Calculator_EraseExponentDigit(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  size_t len= strlen(smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalDigits);
  if ( len > 0 )
  {
    len--;
    smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalDigits[len]= '\0';
  }
  else
  {
    smInfo->subsm.CalculatorDisplay.instanceData.ExponentStart= false;
  }
}

void Calculator_EraseFractionDigit(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  size_t len= strlen(smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits);
  if ( len > 0 )
  {
    len--;
    smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits[len]= '\0';
  }
  else
  {
    smInfo->subsm.CalculatorDisplay.instanceData.FractinalStart= false;
  }
}

void Calculator_Multiplications(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Calculator_CalculateAccumulator( smInfo, pInputData, pOutputData, E_OP_MULTIPLY );
}

void Calculator_NotifyDisplayUpdate(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Display_Run_Update(&smInfo->subsm.CalculatorDisplay);
}

void Calculator_NotifyDivisionByZeroError(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Display_Run_DivisionByZero(&smInfo->subsm.CalculatorDisplay);
}

void Calculator_NotifyFaultError(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Display_Run_Faulty(&smInfo->subsm.CalculatorDisplay);
}

void Calculator_NotifyOverflowError(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
    Display_Run_Overflow(&smInfo->subsm.CalculatorDisplay);
}

void Calculator_NotifyReset(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Display_Run_Reset(&smInfo->subsm.CalculatorDisplay);
}

void Calculator_PushBaseDigit(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  size_t const allowence = least( 19, sizeof( smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits )-2 );

  size_t baseLen= strlen( smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits);

  if ( baseLen == 1 && smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits[0] == '0')
  {
    smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits[0]= (char)smInfo->subsm.CalculatorKeypad.instanceData.LastInputKey;
  }
  else if ((baseLen < allowence) &&
           (baseLen > 0 || smInfo->subsm.CalculatorKeypad.instanceData.LastInputKey != '0'))
  {
    smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits[baseLen]= (char)smInfo->subsm.CalculatorKeypad.instanceData.LastInputKey;
    smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits[baseLen+1]= '\0';
  }
  else
  {
    /* do nothing */
  }
}

void Calculator_PushExponentDigit(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  size_t const baseLen = greatest(1, strlen( smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits ) ) + 1;
  bool const isFracZero = Calculator_IsFractionZero(smInfo, pInputData );
  size_t const fractionLen = isFracZero? 0 : ( strlen( smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits ) + 1 );

  size_t const allowence = least( sizeof( smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalDigits ) - 1, 18 - (baseLen+fractionLen) );

  size_t expLen= strlen( smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalDigits);

  if ((expLen < allowence) &&
      (expLen > 0 || smInfo->subsm.CalculatorKeypad.instanceData.LastInputKey != '0'))
  {
    smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalDigits[expLen]= (char)smInfo->subsm.CalculatorKeypad.instanceData.LastInputKey;
    smInfo->subsm.CalculatorDisplay.instanceData.ExponantionalDigits[expLen+1]= '\0';
  }
}

void Calculator_PushFractionDigit(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  size_t const allowence = least( 17-strlen(smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits), sizeof( smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits ) - 1 );

  size_t baseLen= strlen( smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits);
  if (baseLen < allowence)
  {
    smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits[baseLen]= (char)smInfo->subsm.CalculatorKeypad.instanceData.LastInputKey;
    smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits[baseLen+1]= '\0';
  }
}

void Calculator_RemoveZerosFromFraction(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  size_t tLen= strlen(smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits);
  while( tLen > 0 )
  {
    --tLen;
    if ( smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits[tLen] == '0' )
    {
      smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits[tLen] = '\0';
    }
    else
    {
     break;
    }
  }
  if ( smInfo->subsm.CalculatorDisplay.instanceData.FractionalDigits[0] == '\0')
  {
    smInfo->subsm.CalculatorDisplay.instanceData.FractinalStart= false;
  }
}

void Calculator_ResetAccumulations(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Calculator_DataType_Initialize(pOutputData);
}

void Calculator_SetExponentEntry(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  smInfo->subsm.CalculatorDisplay.instanceData.ExponentStart = true;
}

void Calculator_SetFractionEntry(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  size_t const baseLen= strlen( smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits);
  if (baseLen == 0 )
  {
    smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits[0] = '0';
    smInfo->subsm.CalculatorDisplay.instanceData.BaseDigits[1] = '\0';
  }

  smInfo->subsm.CalculatorDisplay.instanceData.FractinalStart= true;
}

void Calculator_Substractions(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData )
{
  Calculator_CalculateAccumulator( smInfo, pInputData, pOutputData, E_OP_MINUS );
}

/* End of Calculator_Auxilary.c */
