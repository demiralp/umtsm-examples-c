/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2024-08-04 GMT.
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

#ifndef KeyPressEventGenerator_DataType_h__INCLUDED
#define KeyPressEventGenerator_DataType_h__INCLUDED

#include <KeyPress.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
typedef struct S_SM_KeyPressEventGenerator_DataType
{
  S_SM_KeyPress_t * sm_keypress;
} S_SM_KeyPressEventGenerator_DataType_t;

void KeyPressEventGenerator_DataType_Initialize( S_SM_KeyPressEventGenerator_DataType_t* const instance );
void KeyPressEventGenerator_DataType_Deinitialize( S_SM_KeyPressEventGenerator_DataType_t* const instance );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* KeyPressEventGenerator_DataType_h__INCLUDED */

/* End of KeyPressEventGenerator_DataType.h */