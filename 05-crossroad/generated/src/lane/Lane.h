/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-12-03 GMT
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

#ifndef Lane_h__INCLUDED
#define Lane_h__INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
#include <stdbool.h>
#include <stdint.h>

#include <Lane_DataType.h>

typedef enum E_Lane_Main_States
{
  E_Lane_init,
  E_Lane_Main,
  E_Lane_final
} E_Lane_Main_States_t;

typedef enum E_Lane_Availability_States
{
  E_Lane_Availability_init,
  E_Lane_Available,
  E_Lane_Unavailable,
  E_Lane_Availability_final
} E_Lane_Availability_States_t;

typedef enum E_Lane_Controlling_States
{
  E_Lane_Controlling_init,
  E_Lane_Unmanaged,
  E_Lane_Managed,
  E_Lane_Uncontrolled,
  E_Lane_CheckAndGo,
  E_Lane_StopAndCheck,
  E_Lane_Controlled,
  E_Lane_Controlling_final
} E_Lane_Controlling_States_t;

typedef enum E_Lane_Status_States
{
  E_Lane_Status_init,
  E_Lane_Close,
  E_Lane_Ready,
  E_Lane_Open,
  E_Lane_PrepareToStop,
  E_Lane_Status_final
} E_Lane_Status_States_t;

typedef struct S_SM_Lane
{
  struct
  {
    E_Lane_Main_States_t Main;
    E_Lane_Availability_States_t Availability;
    E_Lane_Controlling_States_t Controlling;
    E_Lane_Status_States_t Status;
  } runningState;
  struct
  {
    E_Lane_Availability_States_t shallow_Availability;
  } storedState;
  S_SM_Lane_DataType_t instanceData;
} S_SM_Lane_t;

void Lane_Initialize( S_SM_Lane_t* const pStateMachine );
void Lane_Deinitialize( S_SM_Lane_t* const pStateMachine );

void Lane_Start( S_SM_Lane_t* pStateMachine );

bool Lane_IsIn_Main_Region( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Availability_Region( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Controlling_Region( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Status_Region( S_SM_Lane_t* const pStateMachine );

bool Lane_IsIn_Main_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Available_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Unavailable_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Unmanaged_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Managed_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Uncontrolled_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_CheckAndGo_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_StopAndCheck_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Controlled_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Close_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Ready_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_Open_State( S_SM_Lane_t* const pStateMachine );
bool Lane_IsIn_PrepareToStop_State( S_SM_Lane_t* const pStateMachine );

void Lane_Run_Allowed( S_SM_Lane_t* pStateMachine );
void Lane_Run_Close( S_SM_Lane_t* pStateMachine );
void Lane_Run_Disallowed( S_SM_Lane_t* pStateMachine );
void Lane_Run_Open( S_SM_Lane_t* pStateMachine );
void Lane_Run_Prepare( S_SM_Lane_t* pStateMachine );
void Lane_Run_StartControlling( S_SM_Lane_t* pStateMachine );
void Lane_Run_StopControlling( S_SM_Lane_t* pStateMachine );
void Lane_Run_SystemDisabled( S_SM_Lane_t* pStateMachine );

S_SM_Lane_DataType_t* Lane_GetData( S_SM_Lane_t* const pStateMachine );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* Lane_h__INCLUDED */

/* End of Lane.h */
