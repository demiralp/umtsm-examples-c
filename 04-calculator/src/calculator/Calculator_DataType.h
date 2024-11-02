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

#ifndef Calculator_DataType_h__INCLUDED
#define Calculator_DataType_h__INCLUDED

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

typedef enum E_Calculator_Error
{
  E_NO_ERROR,
  E_OVERFLOW,
  E_DIVISION_BY_ZERO,
  E_FAULTY
} E_Calculator_Error_t;

typedef enum E_Calculator_Operator
{
  E_OP_NONE,
  E_OP_PLUS,
  E_OP_MINUS,
  E_OP_MULTIPLY,
  E_OP_DIVIDE,
  E_OP_ENTER
} E_Calculator_Operator_t;

typedef struct S_SM_Calculator_DataType
{
  long double Accumulator;
  E_Calculator_Operator_t Operator;
  E_Calculator_Error_t ErrorNo;
} S_SM_Calculator_DataType_t;

void Calculator_DataType_Initialize( S_SM_Calculator_DataType_t* const instance );
void Calculator_DataType_Deinitialize( S_SM_Calculator_DataType_t* const instance );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* Calculator_DataType_h__INCLUDED */

/* End of Calculator_DataType.h */
