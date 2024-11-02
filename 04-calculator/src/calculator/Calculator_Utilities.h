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

#ifndef Calculator_Utilities_h__INCLUDED
#define Calculator_Utilities_h__INCLUDED

#include <Calculator.h>
#include <Calculator_DataType.h>


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

void Calculator_CalculateAccumulator(
  S_SM_Calculator_t* const smInfo,
  S_SM_Calculator_DataType_t const * const pInputData,
  S_SM_Calculator_DataType_t * const pOutputData,
  E_Calculator_Operator_t currentOp );

size_t least( size_t a, size_t b );
size_t greatest( size_t a, size_t b );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* Calculator_Utilities_h__INCLUDED */

/* End of Calculator_Utilities.h */
