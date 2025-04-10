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

#ifndef Crossroad_h__INCLUDED
#define Crossroad_h__INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
#include <stdbool.h>
#include <stdint.h>

#include <Crossroad_DataType.h>

#include <Lane.h>
#include <PedestrianLights.h>
#include <TrafficLight.h>

typedef enum E_Crossroad_Main_States
{
  E_Crossroad_init,
  E_Crossroad_Main,
  E_Crossroad_final
} E_Crossroad_Main_States_t;

typedef enum E_Crossroad_RgLane1_States
{
  E_Crossroad_RgLane1_init,
  E_Crossroad_Lane1,
  E_Crossroad_RgLane1_final
} E_Crossroad_RgLane1_States_t;

typedef enum E_Crossroad_RgLane2_States
{
  E_Crossroad_RgLane2_init,
  E_Crossroad_Lane2,
  E_Crossroad_RgLane2_final
} E_Crossroad_RgLane2_States_t;

typedef enum E_Crossroad_RgLane3_States
{
  E_Crossroad_RgLane3_init,
  E_Crossroad_Lane3,
  E_Crossroad_RgLane3_final
} E_Crossroad_RgLane3_States_t;

typedef enum E_Crossroad_RgLane4_States
{
  E_Crossroad_RgLane4_init,
  E_Crossroad_Lane4,
  E_Crossroad_RgLane4_final
} E_Crossroad_RgLane4_States_t;

typedef enum E_Crossroad_RgPedestrianLanes_States
{
  E_Crossroad_RgPedestrianLanes_init,
  E_Crossroad_PedestrianLanes,
  E_Crossroad_RgPedestrianLanes_final
} E_Crossroad_RgPedestrianLanes_States_t;

typedef enum E_Crossroad_RgTrafficLight1_States
{
  E_Crossroad_RgTrafficLight1_init,
  E_Crossroad_TrafficLight1,
  E_Crossroad_RgTrafficLight1_final
} E_Crossroad_RgTrafficLight1_States_t;

typedef enum E_Crossroad_RgTrafficLight2_States
{
  E_Crossroad_RgTrafficLight2_init,
  E_Crossroad_TrafficLight2,
  E_Crossroad_RgTrafficLight2_final
} E_Crossroad_RgTrafficLight2_States_t;

typedef enum E_Crossroad_RgTrafficLight3_States
{
  E_Crossroad_RgTrafficLight3_init,
  E_Crossroad_TrafficLight3,
  E_Crossroad_RgTrafficLight3_final
} E_Crossroad_RgTrafficLight3_States_t;

typedef enum E_Crossroad_RgTrafficLight4_States
{
  E_Crossroad_RgTrafficLight4_init,
  E_Crossroad_TrafficLight4,
  E_Crossroad_RgTrafficLight4_final
} E_Crossroad_RgTrafficLight4_States_t;

typedef enum E_Crossroad_RgPedestrianLights_States
{
  E_Crossroad_RgPedestrianLights_init,
  E_Crossroad_PedestrianLights,
  E_Crossroad_RgPedestrianLights_final
} E_Crossroad_RgPedestrianLights_States_t;

typedef enum E_Crossroad_SubstateMachines
{
  E_Crossroad_Self,
  E_Crossroad_SubSM_Lane1,
  E_Crossroad_SubSM_Lane2,
  E_Crossroad_SubSM_Lane3,
  E_Crossroad_SubSM_Lane4,
  E_Crossroad_SubSM_PedestrianLanes,
  E_Crossroad_SubSM_TrafficLight1,
  E_Crossroad_SubSM_TrafficLight2,
  E_Crossroad_SubSM_TrafficLight3,
  E_Crossroad_SubSM_TrafficLight4,
  E_Crossroad_SubSM_PedestrianLights
} E_Crossroad_SubstateMachines_t;

typedef struct S_SM_Crossroad
{
  struct
  {
    E_Crossroad_Main_States_t Main;
    E_Crossroad_RgLane1_States_t RgLane1;
    E_Crossroad_RgLane2_States_t RgLane2;
    E_Crossroad_RgLane3_States_t RgLane3;
    E_Crossroad_RgLane4_States_t RgLane4;
    E_Crossroad_RgPedestrianLanes_States_t RgPedestrianLanes;
    E_Crossroad_RgTrafficLight1_States_t RgTrafficLight1;
    E_Crossroad_RgTrafficLight2_States_t RgTrafficLight2;
    E_Crossroad_RgTrafficLight3_States_t RgTrafficLight3;
    E_Crossroad_RgTrafficLight4_States_t RgTrafficLight4;
    E_Crossroad_RgPedestrianLights_States_t RgPedestrianLights;
  } runningState;
  struct
  {
    S_SM_Lane_t Lane1;
    S_SM_Lane_t Lane2;
    S_SM_Lane_t Lane3;
    S_SM_Lane_t Lane4;
    S_SM_Lane_t PedestrianLanes;
    S_SM_TrafficLight_t TrafficLight1;
    S_SM_TrafficLight_t TrafficLight2;
    S_SM_TrafficLight_t TrafficLight3;
    S_SM_TrafficLight_t TrafficLight4;
    S_SM_PedestrianLights_t PedestrianLights;
  } subsm;
  S_SM_Crossroad_DataType_t instanceData;
} S_SM_Crossroad_t;

void Crossroad_Initialize( S_SM_Crossroad_t* const pStateMachine );
void Crossroad_Deinitialize( S_SM_Crossroad_t* const pStateMachine );

void Crossroad_Start( S_SM_Crossroad_t* pStateMachine );

bool Crossroad_IsIn_Main_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgLane1_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgLane2_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgLane3_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgLane4_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgPedestrianLanes_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgTrafficLight1_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgTrafficLight2_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgTrafficLight3_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgTrafficLight4_Region( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_RgPedestrianLights_Region( S_SM_Crossroad_t* const pStateMachine );

bool Crossroad_IsIn_Main_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_Lane1_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_Lane2_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_Lane3_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_Lane4_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_PedestrianLanes_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_TrafficLight1_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_TrafficLight2_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_TrafficLight3_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_TrafficLight4_State( S_SM_Crossroad_t* const pStateMachine );
bool Crossroad_IsIn_PedestrianLights_State( S_SM_Crossroad_t* const pStateMachine );

void Crossroad_Run_Allowed( S_SM_Crossroad_t* pStateMachine );
void Crossroad_Run_Check( S_SM_Crossroad_t* pStateMachine );
void Crossroad_Run_Close( S_SM_Crossroad_t* pStateMachine );
void Crossroad_Run_Disallowed( S_SM_Crossroad_t* pStateMachine );
void Crossroad_Run_Open( S_SM_Crossroad_t* pStateMachine );
void Crossroad_Run_Prepare( S_SM_Crossroad_t* pStateMachine );
void Crossroad_Run_StartControlling( S_SM_Crossroad_t* pStateMachine );
void Crossroad_Run_StopControlling( S_SM_Crossroad_t* pStateMachine );
void Crossroad_Run_SystemDisabled( S_SM_Crossroad_t* pStateMachine );
void Crossroad_Run_SystemEnabled( S_SM_Crossroad_t* pStateMachine );

S_SM_Crossroad_DataType_t* Crossroad_GetData( S_SM_Crossroad_t* const pStateMachine );

S_SM_Lane_DataType_t* Crossroad_GetSMData_Lane1( S_SM_Crossroad_t* const pStateMachine );
S_SM_Lane_DataType_t* Crossroad_GetSMData_Lane2( S_SM_Crossroad_t* const pStateMachine );
S_SM_Lane_DataType_t* Crossroad_GetSMData_Lane3( S_SM_Crossroad_t* const pStateMachine );
S_SM_Lane_DataType_t* Crossroad_GetSMData_Lane4( S_SM_Crossroad_t* const pStateMachine );
S_SM_Lane_DataType_t* Crossroad_GetSMData_PedestrianLanes( S_SM_Crossroad_t* const pStateMachine );
S_SM_TrafficLight_DataType_t* Crossroad_GetSMData_TrafficLight1( S_SM_Crossroad_t* const pStateMachine );
S_SM_TrafficLight_DataType_t* Crossroad_GetSMData_TrafficLight2( S_SM_Crossroad_t* const pStateMachine );
S_SM_TrafficLight_DataType_t* Crossroad_GetSMData_TrafficLight3( S_SM_Crossroad_t* const pStateMachine );
S_SM_TrafficLight_DataType_t* Crossroad_GetSMData_TrafficLight4( S_SM_Crossroad_t* const pStateMachine );
S_SM_PedestrianLights_DataType_t* Crossroad_GetSMData_PedestrianLights( S_SM_Crossroad_t* const pStateMachine );

S_SM_Lane_t* Crossroad_GetSubSM_Lane1( S_SM_Crossroad_t* const pStateMachine );
S_SM_Lane_t* Crossroad_GetSubSM_Lane2( S_SM_Crossroad_t* const pStateMachine );
S_SM_Lane_t* Crossroad_GetSubSM_Lane3( S_SM_Crossroad_t* const pStateMachine );
S_SM_Lane_t* Crossroad_GetSubSM_Lane4( S_SM_Crossroad_t* const pStateMachine );
S_SM_Lane_t* Crossroad_GetSubSM_PedestrianLanes( S_SM_Crossroad_t* const pStateMachine );
S_SM_TrafficLight_t* Crossroad_GetSubSM_TrafficLight1( S_SM_Crossroad_t* const pStateMachine );
S_SM_TrafficLight_t* Crossroad_GetSubSM_TrafficLight2( S_SM_Crossroad_t* const pStateMachine );
S_SM_TrafficLight_t* Crossroad_GetSubSM_TrafficLight3( S_SM_Crossroad_t* const pStateMachine );
S_SM_TrafficLight_t* Crossroad_GetSubSM_TrafficLight4( S_SM_Crossroad_t* const pStateMachine );
S_SM_PedestrianLights_t* Crossroad_GetSubSM_PedestrianLights( S_SM_Crossroad_t* const pStateMachine );

void Crossroad_SubSM_Run_Allowed( S_SM_Crossroad_t* pStateMachine, E_Crossroad_SubstateMachines_t subsm );
void Crossroad_SubSM_Run_Check( S_SM_Crossroad_t* pStateMachine, E_Crossroad_SubstateMachines_t subsm );
void Crossroad_SubSM_Run_Close( S_SM_Crossroad_t* pStateMachine, E_Crossroad_SubstateMachines_t subsm );
void Crossroad_SubSM_Run_Disallowed( S_SM_Crossroad_t* pStateMachine, E_Crossroad_SubstateMachines_t subsm );
void Crossroad_SubSM_Run_Open( S_SM_Crossroad_t* pStateMachine, E_Crossroad_SubstateMachines_t subsm );
void Crossroad_SubSM_Run_Prepare( S_SM_Crossroad_t* pStateMachine, E_Crossroad_SubstateMachines_t subsm );
void Crossroad_SubSM_Run_StartControlling( S_SM_Crossroad_t* pStateMachine, E_Crossroad_SubstateMachines_t subsm );
void Crossroad_SubSM_Run_StopControlling( S_SM_Crossroad_t* pStateMachine, E_Crossroad_SubstateMachines_t subsm );
void Crossroad_SubSM_Run_SystemEnabled( S_SM_Crossroad_t* pStateMachine, E_Crossroad_SubstateMachines_t subsm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* Crossroad_h__INCLUDED */

/* End of Crossroad.h */
