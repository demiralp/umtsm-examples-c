/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-11-02 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  This file is generated by UMTSM using the code generator `CGen`
 *
 *  !!! It is highly recommended that DO NOT EDIT THIS GENERATED FILE !!!
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

#ifndef KeyPress_h__INCLUDED
#define KeyPress_h__INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
#include <stdbool.h>
#include <stdint.h>

#include <KeyPress_DataType.h>

typedef enum E_KeyPress_Main_States
{
  E_KeyPress_init,
  E_KeyPress_Main,
  E_KeyPress_WaitABit,
  E_KeyPress_JoinSyncronize,
  E_KeyPress_final
} E_KeyPress_Main_States_t;

typedef enum E_KeyPress_Alpha_States
{
  E_KeyPress_Alpha_init,
  E_KeyPress_ReadLetters,
  E_KeyPress_Pause,
  E_KeyPress_Alpha_final
} E_KeyPress_Alpha_States_t;

typedef enum E_KeyPress_Numeric_States
{
  E_KeyPress_Numeric_init,
  E_KeyPress_ReadDigits,
  E_KeyPress_Numeric_final
} E_KeyPress_Numeric_States_t;

typedef enum E_KeyPress_Log_States
{
  E_KeyPress_Log_init,
  E_KeyPress_PrintLog,
  E_KeyPress_Log_final
} E_KeyPress_Log_States_t;

typedef struct S_SM_KeyPress
{
  struct
  {
    E_KeyPress_Main_States_t Main;
    E_KeyPress_Alpha_States_t Alpha;
    E_KeyPress_Numeric_States_t Numeric;
    E_KeyPress_Log_States_t Log;
  } runningState;
  S_SM_KeyPress_DataType_t instanceData;
} S_SM_KeyPress_t;

void KeyPress_Initialize( S_SM_KeyPress_t* const pStateMachine );
void KeyPress_Deinitialize( S_SM_KeyPress_t* const pStateMachine );

void KeyPress_Start( S_SM_KeyPress_t* pStateMachine );

bool KeyPress_IsIn_Main_Region( S_SM_KeyPress_t* const pStateMachine );
bool KeyPress_IsIn_Alpha_Region( S_SM_KeyPress_t* const pStateMachine );
bool KeyPress_IsIn_Numeric_Region( S_SM_KeyPress_t* const pStateMachine );
bool KeyPress_IsIn_Log_Region( S_SM_KeyPress_t* const pStateMachine );

bool KeyPress_IsIn_Main_State( S_SM_KeyPress_t* const pStateMachine );
bool KeyPress_IsIn_ReadLetters_State( S_SM_KeyPress_t* const pStateMachine );
bool KeyPress_IsIn_Pause_State( S_SM_KeyPress_t* const pStateMachine );
bool KeyPress_IsIn_ReadDigits_State( S_SM_KeyPress_t* const pStateMachine );
bool KeyPress_IsIn_PrintLog_State( S_SM_KeyPress_t* const pStateMachine );
bool KeyPress_IsIn_WaitABit_State( S_SM_KeyPress_t* const pStateMachine );

void KeyPress_Run_clock4log( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_key1( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_key2( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_key3( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_key4( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_key5( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_key6( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_key7( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_key8( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_key9( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_keyA( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_keyB( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_keyBackspace( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_keyC( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_keyDelete( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_keyF1( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_keyF12( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_keyF2( S_SM_KeyPress_t* pStateMachine );
void KeyPress_Run_space( S_SM_KeyPress_t* pStateMachine );

S_SM_KeyPress_DataType_t* KeyPress_GetData( S_SM_KeyPress_t* const pStateMachine );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* KeyPress_h__INCLUDED */

/* End of KeyPress.h */
