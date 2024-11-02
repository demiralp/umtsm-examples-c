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

#include "Keypad_Auxilary.h"
#include "Keypad_DataType.h"
#include "Calculator.h"

#include <assert.h>
#include <ctype.h>
#include <memory.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include <ncurses.h>
#include <wchar.h>

/* The implementation of the guards */
bool Keypad_IsBackspace(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == KEY_BACKSPACE;
  return result;
}

bool Keypad_IsClear(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == KEY_DC;
  return result;
}

bool Keypad_IsDigit(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = isdigit(pInstance->LastInputKey);
  return result;
}

bool Keypad_IsDivisor(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == '/';
  return result;
}

bool Keypad_IsDot(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  /* @todo Missing implementation */
  bool const result = pInstance->LastInputKey == '.' || pInstance->LastInputKey == ',';
  return result;
}

bool Keypad_IsEnter(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == '\n' || pInstance->LastInputKey == KEY_ENTER || pInstance->LastInputKey == '=';
  return result;
}

bool Keypad_IsExponent(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == 'e' || pInstance->LastInputKey == 'E';
  return result;
}

bool Keypad_IsMinus(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == '-';
  return result;
}

bool Keypad_IsMultiplay(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == '*';
  return result;
}

bool Keypad_IsPlus(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == '+';
  return result;
}

bool Keypad_IsReset(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == 'c' || pInstance->LastInputKey == 'C';
  return result;
}

bool Keypad_IsSignature(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInstance )
{
  bool const result = pInstance->LastInputKey == 's' || pInstance->LastInputKey == 'S';
  return result;
}

/* The implementation of the actions */
void Keypad_NotifyBackspce(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Backspace(pOutputData->pCalculator);
}

void Keypad_NotifyClear(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Clear(pOutputData->pCalculator);
}

void Keypad_NotifyDigit(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Digit(pOutputData->pCalculator);
}

void Keypad_NotifyDivisor(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Division(pOutputData->pCalculator);
}

void Keypad_NotifyDot(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Dot(pOutputData->pCalculator);
}

void Keypad_NotifyEnter(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Enter(pOutputData->pCalculator);
}

void Keypad_NotifyExponent(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Exponents(pOutputData->pCalculator);
}

void Keypad_NotifyMinus(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Minus(pOutputData->pCalculator);
}

void Keypad_NotifyMultiplay(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Multiplay(pOutputData->pCalculator);
}

void Keypad_NotifyPlus(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Plus(pOutputData->pCalculator);
}

void Keypad_NotifyReset(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_Reset(pOutputData->pCalculator);
}

void Keypad_NotifySignatureChange(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  Calculator_Run_ChangeSign(pOutputData->pCalculator);
}

void Keypad_ReadKey(
  __attribute__((unused)) S_SM_Keypad_t* const smInfo,
  __attribute__((unused)) S_SM_Keypad_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Keypad_DataType_t * const pOutputData )
{
  static char const * const keyChar = ".,+-/*=eEsScC";
  while( true )
  {
    int ch;
    pOutputData->LastInputKey = ch = wgetch(stdscr);

    if ( isdigit(ch) || 
         strchr(keyChar, ch) != NULL || 
         ch == '\n' || 
         ch == KEY_ENTER ||
         ch == KEY_BACKSPACE || 
         ch == KEY_DC )
    {
      Keypad_Run_Notify( smInfo );
    }
  }
}

/* End of Keypad_Auxilary.c */
