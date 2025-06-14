/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-08-11 GMT
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

#include "Display_Auxilary.h"
#include "Display_DataType.h"
#include "Display_Utilities.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>

#include <ncurses.h>

/* The implementation of the actions */
void Display_DisplayDivisionByZeroError(
  __attribute__( ( unused ) ) S_SM_Display_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Display_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Display_DataType_t* const pOutputData )
{
  printw("\r<<DIVISION BY ZERO>>");
} /* End of action function: Display_DisplayDivisionByZeroError */

void Display_DisplayFaultyError(
  __attribute__( ( unused ) ) S_SM_Display_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Display_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Display_DataType_t* const pOutputData )
{
  printw("\r<<ERROR>>");
} /* End of action function: Display_DisplayFaultyError */

void Display_DisplayOverflowError(
  __attribute__( ( unused ) ) S_SM_Display_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Display_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Display_DataType_t* const pOutputData )
{
  printw("\r<<OVERFLOW ERROR>>");
} /* End of action function: Display_DisplayOverflowError */

void Display_DisplayUpdate(
  __attribute__( ( unused ) ) S_SM_Display_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Display_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Display_DataType_t* const pOutputData )
{
  char accdata[20];
  Display_GetAccumulatorData(pInputData, accdata, sizeof(accdata));

  printw("\r%-20s", accdata);
} /* End of action function: Display_DisplayUpdate */

/* End of Display_Auxilary.c */
