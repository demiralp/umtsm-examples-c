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

#ifndef ExecutionDirector_h__INCLUDED
#define ExecutionDirector_h__INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
#include <stdbool.h>
#include <stdint.h>

#include <pthread.h>

#include <ExecutionDirector_DataType.h>

typedef enum E_ExecutionDirector_Main_States
{
  E_ExecutionDirector_init,
  E_ExecutionDirector_Main,
  E_ExecutionDirector_StandBy,
  E_ExecutionDirector_SwitchSystem,
  E_ExecutionDirector_GoesToOperational,
  E_ExecutionDirector_GoesToStandby,
  E_ExecutionDirector_SwitchControlState,
  E_ExecutionDirector_Operational,
  E_ExecutionDirector_Uncontrolled,
  E_ExecutionDirector_CheckRequests,
  E_ExecutionDirector_Controlled,
  E_ExecutionDirector_OpenLane1,
  E_ExecutionDirector_OnCloseLane1,
  E_ExecutionDirector_OpenLane2,
  E_ExecutionDirector_OnCloseLane2,
  E_ExecutionDirector_OpenLane3,
  E_ExecutionDirector_OnCloseLane3,
  E_ExecutionDirector_OpenLane4,
  E_ExecutionDirector_OnCloseLane4,
  E_ExecutionDirector_OpenPedestrianLanes,
  E_ExecutionDirector_OnClosePedestrianLanes,
  E_ExecutionDirector_final
} E_ExecutionDirector_Main_States_t;

typedef struct S_SM_ExecutionDirector
{
  pthread_mutex_t guard;
  struct
  {
    E_ExecutionDirector_Main_States_t Main;
  } runningState;
  struct
  {
    union
    {
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } GoesToOperational;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } GoesToStandby;
    };
    struct
    {
      pthread_t threadHandle;
      uint8_t stack[4224U];
    } SwitchControlState;
    struct
    {
      pthread_t threadHandle;
      uint8_t stack[4224U];
    } CheckRequests;
    union
    {
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OpenLane1;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OnCloseLane1;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OpenLane2;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OnCloseLane2;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OpenLane3;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OnCloseLane3;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OpenLane4;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OnCloseLane4;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OpenPedestrianLanes;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } OnClosePedestrianLanes;
    };
  } doFunctionHandler;
  struct
  {
    E_ExecutionDirector_Main_States_t Operational;
  } storedState;
  S_SM_ExecutionDirector_DataType_t instanceData;
} S_SM_ExecutionDirector_t;

void ExecutionDirector_Initialize( S_SM_ExecutionDirector_t* const pStateMachine );
void ExecutionDirector_Deinitialize( S_SM_ExecutionDirector_t* const pStateMachine );

void ExecutionDirector_Start( S_SM_ExecutionDirector_t* pStateMachine );

bool ExecutionDirector_IsIn_Main_Region( S_SM_ExecutionDirector_t* const pStateMachine );

bool ExecutionDirector_IsIn_Main_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_StandBy_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_SwitchSystem_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_GoesToOperational_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_GoesToStandby_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_SwitchControlState_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_Operational_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_Uncontrolled_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_CheckRequests_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_Controlled_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OpenLane1_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OnCloseLane1_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OpenLane2_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OnCloseLane2_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OpenLane3_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OnCloseLane3_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OpenLane4_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OnCloseLane4_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OpenPedestrianLanes_State( S_SM_ExecutionDirector_t* const pStateMachine );
bool ExecutionDirector_IsIn_OnClosePedestrianLanes_State( S_SM_ExecutionDirector_t* const pStateMachine );

void ExecutionDirector_Run_DisableLane1( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_DisableLane2( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_DisableLane3( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_DisableLane4( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_EnableLane1( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_EnableLane2( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_EnableLane3( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_EnableLane4( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_OpenLane1( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_OpenLane2( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_OpenLane3( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_OpenLane4( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_OpenPedestrianLanes( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_ReleaseControl( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_SystemDisabled( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_SystemEnabled( S_SM_ExecutionDirector_t* pStateMachine );
void ExecutionDirector_Run_TakeControl( S_SM_ExecutionDirector_t* pStateMachine );

S_SM_ExecutionDirector_DataType_t* ExecutionDirector_GetData( S_SM_ExecutionDirector_t* const pStateMachine );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ExecutionDirector_h__INCLUDED */

/* End of ExecutionDirector.h */