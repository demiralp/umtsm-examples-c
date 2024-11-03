/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2024-09-09 GMT.
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

#include "PedestrianLights_Auxilary.h"
#include "PedestrianLights.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include <Crossroad.h>
#include <ExecutionDirector.h>
#include <Monitor.h>

#define RUN_FLASHING_US ( 500000 )

/* The implementation of the guards */
bool PedestrianLights_IsCheckAndGo(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInstance )
{
  bool const result = ExecutionDirector_IsIn_Uncontrolled_State( pInstance->pExecutionDirector );
  return result;
} /* End of guard function: PedestrianLights_IsCheckAndGo */

bool PedestrianLights_IsLaneClose(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInstance )
{
  S_SM_Lane_t* pPedestrianLanes = Crossroad_GetSubSM_PedestrianLanes( pInstance->pCrossroad );

  bool const result = Lane_IsIn_Close_State( pPedestrianLanes )
    && Lane_IsIn_Controlled_State( pPedestrianLanes )
    && Lane_IsIn_Available_State( pPedestrianLanes );

  return result;
} /* End of guard function: PedestrianLights_IsLaneClose */

bool PedestrianLights_IsLaneOpen(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInstance )
{
  S_SM_Lane_t* pPedestrianLanes = Crossroad_GetSubSM_PedestrianLanes( pInstance->pCrossroad );

  bool const result = Lane_IsIn_Open_State( pPedestrianLanes )
    && Lane_IsIn_Controlled_State( pPedestrianLanes )
    && Lane_IsIn_Available_State( pPedestrianLanes );

  return result;
} /* End of guard function: PedestrianLights_IsLaneOpen */

bool PedestrianLights_IsStopCheckAndGo(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInstance )
{
  bool const result = ExecutionDirector_IsIn_Uncontrolled_State( pInstance->pExecutionDirector );
  return result;
} /* End of guard function: PedestrianLights_IsStopCheckAndGo */

bool PedestrianLights_IsSystemOperational(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInstance )
{
  bool const result = ExecutionDirector_IsIn_Operational_State( pInstance->pExecutionDirector );
  return result;
} /* End of guard function: PedestrianLights_IsSystemOperational */

bool PedestrianLights_IsSystemSwitching(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInstance )
{
  bool const result = ExecutionDirector_IsIn_SwitchSystem_State( pInstance->pExecutionDirector );
  return result;
} /* End of guard function: PedestrianLights_IsSystemSwitching */

/* The implementation of the actions */
void PedestrianLights_CountForFlashing(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t* const pOutputData )
{
  usleep( RUN_FLASHING_US );
} /* End of action function: PedestrianLights_CountForFlashing */

void PedestrianLights_SwitchGreenLightOff(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: PedestrianLights_SwitchGreenLightOff */

void PedestrianLights_SwitchGreenLightOn(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: PedestrianLights_SwitchGreenLightOn */

void PedestrianLights_SwitchRedLightOff(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: PedestrianLights_SwitchRedLightOff */

void PedestrianLights_SwitchRedLightOn(
  __attribute__( ( unused ) ) S_SM_PedestrianLights_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_PedestrianLights_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: PedestrianLights_SwitchRedLightOn */

/* End of PedestrianLights_Auxilary.c */