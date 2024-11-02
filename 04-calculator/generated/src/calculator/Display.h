/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-11-02 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *  
 *  This file is generated by UMTSM using the code generator `CGen`
 *  
 *  !!! It is highly recommended that DO NOT EDIT THIS GENERATED FILE !!!
 *  
 *  Released under the MIT License
 *  ============================================================================
 */

/*
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
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

#ifndef Display_h__INCLUDED
#define Display_h__INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
#include <stdbool.h>
#include <stdint.h>

#include <Display_DataType.h>

typedef enum E_Display_Main_States
{
  E_Display_init,
  E_Display_Main,
  E_Display_DisplayEntry,
  E_Display_ErrorMessages,
  E_Display_OverflowError,
  E_Display_DivisionByZeroError,
  E_Display_FaultyError,
  E_Display_final
} E_Display_Main_States_t;

typedef struct S_SM_Display
{
  struct
  {
    E_Display_Main_States_t Main;
  } runningState;
  S_SM_Display_DataType_t instanceData;
} S_SM_Display_t;

void Display_Initialize( S_SM_Display_t* const pStateMachine );
void Display_Deinitialize( S_SM_Display_t* const pStateMachine );

void Display_Start( S_SM_Display_t* pStateMachine );

bool Display_IsIn_Main_Region( S_SM_Display_t* const pStateMachine );

bool Display_IsIn_Main_State( S_SM_Display_t* const pStateMachine );
bool Display_IsIn_DisplayEntry_State( S_SM_Display_t* const pStateMachine );
bool Display_IsIn_ErrorMessages_State( S_SM_Display_t* const pStateMachine );
bool Display_IsIn_OverflowError_State( S_SM_Display_t* const pStateMachine );
bool Display_IsIn_DivisionByZeroError_State( S_SM_Display_t* const pStateMachine );
bool Display_IsIn_FaultyError_State( S_SM_Display_t* const pStateMachine );

void Display_Run_Clear( S_SM_Display_t* pStateMachine );
void Display_Run_DivisionByZero( S_SM_Display_t* pStateMachine );
void Display_Run_Faulty( S_SM_Display_t* pStateMachine );
void Display_Run_Overflow( S_SM_Display_t* pStateMachine );
void Display_Run_Reset( S_SM_Display_t* pStateMachine );
void Display_Run_SwitchOff( S_SM_Display_t* pStateMachine );
void Display_Run_Update( S_SM_Display_t* pStateMachine );

S_SM_Display_DataType_t* Display_GetData( S_SM_Display_t* const pStateMachine );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* Display_h__INCLUDED */

/* End of Display.h */
