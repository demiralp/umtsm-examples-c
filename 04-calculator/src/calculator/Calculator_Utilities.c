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


#include "Calculator_Utilities.h"

#include "Calculator_Auxilary.h"
#include "Calculator_DataType.h"
#include "Display_Utilities.h"

#include <math.h>

#include <ncurses.h>

void Calculator_CalculateAccumulator(
  __attribute__((unused)) S_SM_Calculator_t* const smInfo,
  __attribute__((unused)) S_SM_Calculator_DataType_t const * const pInputData,
  __attribute__((unused)) S_SM_Calculator_DataType_t * const pOutputData,
   E_Calculator_Operator_t currentOp )
{
  static char const OpChar[] = { ' ', '+', '-', '*', '/', '=' };

  char dispdata[20];
  Display_GetAccumulatorData(&smInfo->subsm.CalculatorDisplay.instanceData, dispdata, sizeof(dispdata) );
  long double value;
  int err= sscanf( dispdata, "%Le", &value );

  if ( pInputData->Operator != E_OP_NONE )
  {
    Calculator_DrawSpliteLine(smInfo, pInputData, pOutputData);
  }
  else
  {
    printw("%c", OpChar[currentOp]);
  }

  if ( ( err != 1) && isinf( value ) )
  {
    pOutputData->ErrorNo= E_OVERFLOW;
  }
  else
  {
    switch (pInputData->Operator)
    {
      case E_OP_ENTER:
      __attribute__ ((fallthrough));
      case E_OP_NONE:
      {
        pOutputData->Accumulator= value;
        break;
      }
      case E_OP_PLUS:
      {
        pOutputData->Accumulator += value;
        break;
      }
      case E_OP_MINUS:
      {
        pOutputData->Accumulator -= value;
        break;
      }
      case E_OP_MULTIPLY:
      {
        pOutputData->Accumulator *= value;
        break;
      }
      case E_OP_DIVIDE:
      {
        if ( value == 0.0 )
        {
          pOutputData->ErrorNo= E_DIVISION_BY_ZERO;
        }
        else
        {
          pOutputData->Accumulator /= value;
        }
        break;
      }
    }
  
    if ( pOutputData->ErrorNo == E_NO_ERROR)
    {
      if(isinf(pOutputData->Accumulator))
      {
        pOutputData->ErrorNo= E_OVERFLOW;
      }
      else if ( pOutputData->Operator != E_OP_NONE )
      {
        printw("%-20.15LG%c", pOutputData->Accumulator, OpChar[currentOp]);
      }
    }
  
    if ( pOutputData->ErrorNo == E_NO_ERROR)
    {
      if (currentOp == E_OP_ENTER)
      {
        Calculator_DrawSpliteLine(smInfo, pInputData, pOutputData);
      }
      else
      {
        printw("\n");
      }
  
      pOutputData->Operator = currentOp;
    }
    else if (pOutputData->Operator == E_OP_NONE ) 
    {
      Calculator_DrawSpliteLine(smInfo, pInputData, pOutputData);
    }
    else
    {
      // do nothing
    }
  }
}

size_t least( size_t a, size_t b )
{
  return a < b ? a : b;
}

size_t greatest( size_t a, size_t b )
{
  return a < b ? b : a;
}

/* End of Calculator_Utilities.c */