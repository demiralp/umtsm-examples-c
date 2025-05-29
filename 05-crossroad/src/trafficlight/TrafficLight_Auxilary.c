/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-09-09 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
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

#include "TrafficLight_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <Crossroad.h>
#include <ExecutionDirector.h>
#include <Lane.h>
#include <Monitor.h>

#define RUN_FLASHING_US ( 500000 )

/* The implementation of the guards */
bool TrafficLight_IsCheckAndGo(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInstance )
{
  bool const result = Lane_IsIn_CheckAndGo_State( pInstance->pLane )
    && Lane_IsIn_Uncontrolled_State(pInstance->pLane)
    && Lane_IsIn_Available_State(pInstance->pLane);
  return result;
} /* End of guard function: TrafficLight_IsCheckAndGo */

bool TrafficLight_IsLaneAvailable(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInstance )
{
  bool const result = Lane_IsIn_Available_State( pInstance->pLane );
  return result;
} /* End of guard function: TrafficLight_IsLaneAvailable */

bool TrafficLight_IsLaneClose(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInstance )
{
  bool const result = Lane_IsIn_Close_State( pInstance->pLane )
    && Lane_IsIn_Controlled_State( pInstance->pLane )
    && Lane_IsIn_Available_State( pInstance->pLane );
  return result;
} /* End of guard function: TrafficLight_IsLaneClose */

bool TrafficLight_IsLaneOnClosing(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInstance )
{
  bool const result = Lane_IsIn_PrepareToStop_State( pInstance->pLane )
    && Lane_IsIn_Controlled_State( pInstance->pLane )
    && Lane_IsIn_Available_State( pInstance->pLane );
  return result;
} /* End of guard function: TrafficLight_IsLaneOnClosing */

bool TrafficLight_IsLaneOnOpening(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInstance )
{
  bool const result = Lane_IsIn_Ready_State( pInstance->pLane )
    && Lane_IsIn_Controlled_State( pInstance->pLane )
    && Lane_IsIn_Available_State( pInstance->pLane );
  return result;
} /* End of guard function: TrafficLight_IsLaneOnOpening */

bool TrafficLight_IsLaneOpen(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInstance )
{
  bool const result = Lane_IsIn_Open_State( pInstance->pLane )
    && Lane_IsIn_Controlled_State( pInstance->pLane )
    && Lane_IsIn_Available_State( pInstance->pLane );
  return result;
} /* End of guard function: TrafficLight_IsLaneOpen */

bool TrafficLight_IsStopCheckAndGo(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInstance )
{
  bool const result = Lane_IsIn_StopAndCheck_State( pInstance->pLane )
    && Lane_IsIn_Uncontrolled_State(pInstance->pLane)
    && Lane_IsIn_Available_State(pInstance->pLane);
  return result;
} /* End of guard function: TrafficLight_IsStopCheckAndGo */

bool TrafficLight_IsSystemOperational(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInstance )
{
  bool const result = ExecutionDirector_IsIn_Operational_State( pInstance->pExecutionDirector );
  return result;
} /* End of guard function: TrafficLight_IsSystemOperational */

bool TrafficLight_IsSystemSwitching(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInstance )
{
  bool const result = ExecutionDirector_IsIn_SwitchSystem_State( pInstance->pExecutionDirector );
  return result;
} /* End of guard function: TrafficLight_IsSystemSwitching */

/* The implementation of the actions */
void TrafficLight_CountForFlashing(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t* const pOutputData )
{
  usleep( RUN_FLASHING_US );
} /* End of action function: TrafficLight_CountForFlashing */

void TrafficLight_SwitchAmberLightOff(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: TrafficLight_SwitchAmberLightOff */

void TrafficLight_SwitchAmberLightOn(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: TrafficLight_SwitchAmberLightOn */

void TrafficLight_SwitchGreenLightOff(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: TrafficLight_SwitchGreenLightOff */

void TrafficLight_SwitchGreenLightOn(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: TrafficLight_SwitchGreenLightOn */

void TrafficLight_SwitchRedLightOff(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: TrafficLight_SwitchRedLightOff */

void TrafficLight_SwitchRedLightOn(
  __attribute__( ( unused ) ) S_SM_TrafficLight_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_TrafficLight_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: TrafficLight_SwitchRedLightOn */

/* End of TrafficLight_Auxilary.c */
