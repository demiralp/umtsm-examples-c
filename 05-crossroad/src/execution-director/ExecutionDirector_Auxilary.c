/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-09-13 GMT
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

#include "ExecutionDirector_Auxilary.h"
#include "ExecutionDirector_DataType.h"

#include <assert.h>
#include <math.h>
#include <memory.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

#include <Crossroad.h>
#include <Monitor.h>

#define SEC_IN_US(SEC)            ( 1000000 * (SEC) )

#define RUN_LANE_US               SEC_IN_US( 10 )
#define RUN_LANE1_US              ( RUN_LANE_US )
#define RUN_LANE2_US              ( RUN_LANE_US )
#define RUN_LANE3_US              ( RUN_LANE_US )
#define RUN_LANE4_US              ( RUN_LANE_US )
#define RUN_PEDESTRIAN_LANES_US   SEC_IN_US( 8 )
#define RUN_PREPARING_US          SEC_IN_US( 4 )
#define RUN_STOPING_TRAFFIC_US    ( RUN_LANE_US )
#define RUN_SWITCHING_TIME_US     SEC_IN_US( 7 )
#define RUN_MIN_SWITCHING_TIME_US SEC_IN_US( 5 )
#define RUN_INTERVAL_TIME_US      SEC_IN_US( 3  )

static void TellLaneAvailability(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData );

/* The implementation of the guards */
bool ExecutionDirector_IsControlledModeRequested(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInstance )
{
  bool const result = pInstance->ControlModeStatus == CONTROLLED;
  return result;
} /* End of guard function: ExecutionDirector_IsControlledModeRequested */

bool ExecutionDirector_IsNextLane1(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInstance )
{
  bool const result = pInstance->NextLane == 1;
  return result;
} /* End of guard function: ExecutionDirector_IsNextLane1 */

bool ExecutionDirector_IsNextLane2(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInstance )
{
  bool const result = pInstance->NextLane == 2;
  return result;
} /* End of guard function: ExecutionDirector_IsNextLane2 */

bool ExecutionDirector_IsNextLane3(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInstance )
{
  bool const result = pInstance->NextLane == 3;
  return result;
} /* End of guard function: ExecutionDirector_IsNextLane3 */

bool ExecutionDirector_IsNextLane4(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInstance )
{
  bool const result = pInstance->NextLane == 4;
  return result;
} /* End of guard function: ExecutionDirector_IsNextLane4 */

bool ExecutionDirector_IsNextLanePedestrianLanes(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInstance )
{
  bool const result = pInstance->NextLane == 0;
  return result;
} /* End of guard function: ExecutionDirector_IsNextLanePedestrianLanes */

bool ExecutionDirector_IsUncontrolledModeRequested(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInstance )
{
  bool const result = pInstance->ControlModeStatus == UNCONTROLLED;
  return result;
} /* End of guard function: ExecutionDirector_IsUncontrolledModeRequested */

/* The implementation of the actions */
void ExecutionDirector_CheckRouteRequest(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t * const pOutputData )
{
  pOutputData->NextLane      = pInputData->LaneRequested;
  pOutputData->LaneRequested = -1;

  TellLaneAvailability( smInfo, pInputData, pOutputData );
 } /* End of action function: ExecutionDirector_CheckRouteRequest */

void ExecutionDirector_ClearControlMode(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->ControlModeStatus = PERSISTENT_CONTROL_MODE;
} /* End of action function: ExecutionDirector_ClearControlMode */

void ExecutionDirector_DisableSystem(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_Run_SystemDisabled( pOutputData->pCrossroad );
} /* End of action function: ExecutionDirector_DisableSystem */

void ExecutionDirector_EnableSystem(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_Run_SystemEnabled( pOutputData->pCrossroad );
} /* End of action function: ExecutionDirector_EnableSystem */

void ExecutionDirector_NotifyCrossroad(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_Run_Check( pOutputData->pCrossroad );
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: ExecutionDirector_NotifyCrossroad */

void ExecutionDirector_OrderCloseLane1(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  /// @todo
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
} /* End of action function: ExecutionDirector_OrderCloseLane1 */

void ExecutionDirector_OrderCloseLane2(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
} /* End of action function: ExecutionDirector_OrderCloseLane2 */

void ExecutionDirector_OrderCloseLane3(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
} /* End of action function: ExecutionDirector_OrderCloseLane3 */

void ExecutionDirector_OrderCloseLane4(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
} /* End of action function: ExecutionDirector_OrderCloseLane4 */

void ExecutionDirector_OrderClosePedestrianLanes(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_PedestrianLanes );
} /* End of action function: ExecutionDirector_OrderClosePedestrianLanes */

void ExecutionDirector_OrderClosingLane1(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_SubSM_Run_Prepare( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );  
} /* End of action function: ExecutionDirector_OrderClosingLane1 */

void ExecutionDirector_OrderClosingLane2(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_SubSM_Run_Prepare( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );  
} /* End of action function: ExecutionDirector_OrderClosingLane2 */

void ExecutionDirector_OrderClosingLane3(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_SubSM_Run_Prepare( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );  
} /* End of action function: ExecutionDirector_OrderClosingLane3 */

void ExecutionDirector_OrderClosingLane4(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_SubSM_Run_Prepare( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );  
} /* End of action function: ExecutionDirector_OrderClosingLane4 */

void ExecutionDirector_OrderOpeningLane1(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
    Crossroad_SubSM_Run_Prepare( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );  
} /* End of action function: ExecutionDirector_OrderOpeningLane1 */

void ExecutionDirector_OrderOpeningLane2(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
    Crossroad_SubSM_Run_Prepare( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );  
} /* End of action function: ExecutionDirector_OrderOpeningLane2 */

void ExecutionDirector_OrderOpeningLane3(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
    Crossroad_SubSM_Run_Prepare( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );  
} /* End of action function: ExecutionDirector_OrderOpeningLane3 */

void ExecutionDirector_OrderOpeningLane4(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_SubSM_Run_Prepare( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );  
} /* End of action function: ExecutionDirector_OrderOpeningLane4 */

void ExecutionDirector_OrderOpenLane1(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( pOutputData->NextLane == 1 )
  {
    pOutputData->NextLane = -1;
  }
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_PedestrianLanes );

  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane1( pOutputData->pCrossroad ) ) )
  {
    Crossroad_SubSM_Run_Open( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
    pOutputData->CurrentLane = 1;
  }
  else
  {
    Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
  }
} /* End of action function: ExecutionDirector_OrderOpenLane1 */

void ExecutionDirector_OrderOpenLane2(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( pOutputData->NextLane == 2 )
  {
    pOutputData->NextLane = -1;
  }
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_PedestrianLanes );

  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane2( pOutputData->pCrossroad ) ) )
  {
    Crossroad_SubSM_Run_Open( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
    pOutputData->CurrentLane = 2;
  }
  else
  {
    Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
  }
} /* End of action function: ExecutionDirector_OrderOpenLane2 */

void ExecutionDirector_OrderOpenLane3(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( pOutputData->NextLane == 3 )
  {
    pOutputData->NextLane = -1;
  }
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_PedestrianLanes );

  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane3( pOutputData->pCrossroad ) ) )
  {
    Crossroad_SubSM_Run_Open( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
    pOutputData->CurrentLane = 3;
  }
  else
  {
    Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
  }
} /* End of action function: ExecutionDirector_OrderOpenLane3 */

void ExecutionDirector_OrderOpenLane4(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( pOutputData->NextLane == 4 )
  {
    pOutputData->NextLane = -1;
  }
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_PedestrianLanes );

  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane4( pOutputData->pCrossroad ) ) )
  {
    Crossroad_SubSM_Run_Open( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
    pOutputData->CurrentLane = 4;
  }
  else
  {
    Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
  }
} /* End of action function: ExecutionDirector_OrderOpenLane4 */

void ExecutionDirector_OrderOpenPedestrianLanes(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( pOutputData->NextLane == 0 )
  {
    pOutputData->NextLane = -1;
  }
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
  Crossroad_SubSM_Run_Open( pOutputData->pCrossroad, E_Crossroad_SubSM_PedestrianLanes );
  pOutputData->CurrentLane = 0;
} /* End of action function: ExecutionDirector_OrderOpenPedestrianLanes */

void ExecutionDirector_PrepareForNextLane(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  S_SM_Lane_t* pLane1           = Crossroad_GetSubSM_Lane1( pOutputData->pCrossroad );
  S_SM_Lane_t* pLane2           = Crossroad_GetSubSM_Lane2( pOutputData->pCrossroad );
  S_SM_Lane_t* pLane3           = Crossroad_GetSubSM_Lane3( pOutputData->pCrossroad );
  S_SM_Lane_t* pLane4           = Crossroad_GetSubSM_Lane4( pOutputData->pCrossroad );
  S_SM_Lane_t* pPedestrianLanes = Crossroad_GetSubSM_PedestrianLanes( pOutputData->pCrossroad );

  pOutputData->NextLane      = pInputData->LaneRequested;
  pOutputData->LaneRequested = -1;

  TellLaneAvailability( smInfo, pInputData, pOutputData );

  bool possiblyLane1 = Lane_IsIn_Available_State( pLane1 ) && ( pOutputData->NextLane == -1 || pOutputData->NextLane == 1 );
  bool possiblyLane2 = Lane_IsIn_Available_State( pLane2 ) && ( pOutputData->NextLane == -1 || pOutputData->NextLane == 2 );
  bool possiblyLane3 = Lane_IsIn_Available_State( pLane3 ) && ( pOutputData->NextLane == -1 || pOutputData->NextLane == 3 );
  bool possiblyLane4 = Lane_IsIn_Available_State( pLane4 ) && ( pOutputData->NextLane == -1 || pOutputData->NextLane == 4 );
  bool possiblyLaneP = Lane_IsIn_Available_State( pPedestrianLanes ) && ( pOutputData->NextLane == -1 || pOutputData->NextLane == 0 );

  if( pOutputData->CurrentLane == 1 )
  {
    if( possiblyLane2 )
    {
      pOutputData->NextLane = 2;
    }
    else if( possiblyLane3 )
    {
      pOutputData->NextLane = 3;
    }
    else if( possiblyLane4 )
    {
      pOutputData->NextLane = 4;
    }
    else if( possiblyLaneP )
    {
      pOutputData->NextLane = 0;
    }
    else
    {
      /* No other available lanes */
    }
  }
  else if( pOutputData->CurrentLane == 2 )
  {
    if( possiblyLane3 )
    {
      pOutputData->NextLane = 3;
    }
    else if( possiblyLane4 )
    {
      pOutputData->NextLane = 4;
    }
    else if( possiblyLaneP )
    {
      pOutputData->NextLane = 0;
    }
    else if( possiblyLane1 )
    {
      pOutputData->NextLane = 1;
    }
    else
    {
      /* No other available lanes */
    }
  }
  else if( pOutputData->CurrentLane == 3 )
  {
    if( possiblyLane4 )
    {
      pOutputData->NextLane = 4;
    }
    else if( possiblyLaneP )
    {
      pOutputData->NextLane = 0;
    }
    else if( possiblyLane1 )
    {
      pOutputData->NextLane = 1;
    }
    else if( possiblyLane2 )
    {
      pOutputData->NextLane = 2;
    }
    else
    {
      /* No other available lanes */
    }
  }
  else if( pOutputData->CurrentLane == 4 )
  {
    if( possiblyLaneP )
    {
      pOutputData->NextLane = 0;
    }
    else if( possiblyLane1 )
    {
      pOutputData->NextLane = 1;
    }
    else if( possiblyLane2 )
    {
      pOutputData->NextLane = 2;
    }
    else if( possiblyLane3 )
    {
      pOutputData->NextLane = 3;
    }
    else
    {
      /* No other available lanes */
    }
  }
  else if( pOutputData->CurrentLane == 0 )
  {
    if( possiblyLane1 )
    {
      pOutputData->NextLane = 1;
    }
    else if( possiblyLane2 )
    {
      pOutputData->NextLane = 2;
    }
    else if( possiblyLane3 )
    {
      pOutputData->NextLane = 3;
    }
    else if( possiblyLane4 )
    {
      pOutputData->NextLane = 4;
    }
    else
    {
      /* No other available lanes */
    }
  }
  else
  {
    if( possiblyLane1 )
    {
      pOutputData->NextLane = 1;
    }
    else if( possiblyLane2 )
    {
      pOutputData->NextLane = 2;
    }
    else if( possiblyLane3 )
    {
      pOutputData->NextLane = 3;
    }
    else if( possiblyLane4 )
    {
      pOutputData->NextLane = 4;
    }
    else if( possiblyLaneP )
    {
      pOutputData->NextLane = 0;
    }
    else
    {
      // No other available lanes
    }
  }
} /* End of action function: ExecutionDirector_PrepareForNextLane */

void ExecutionDirector_SetControlledMode(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->ControlModeStatus = CONTROLLED;
} /* End of action function: ExecutionDirector_SetControlledMode */

void ExecutionDirector_SetDisableLane1(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneCmd1 = E_CMD_DISABLE_LANE;
  if( ! ExecutionDirector_IsIn_Operational_State( smInfo ) )
  {
    TellLaneAvailability( smInfo, pInputData, pOutputData );
    Monitor_Run_Update( pOutputData->pMonitor );
  }
} /* End of action function: ExecutionDirector_SetDisableLane1 */

void ExecutionDirector_SetDisableLane2(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneCmd2 = E_CMD_DISABLE_LANE;
  if( ! ExecutionDirector_IsIn_Operational_State( smInfo ) )
  {
    TellLaneAvailability( smInfo, pInputData, pOutputData );
    Monitor_Run_Update( pOutputData->pMonitor );
  }
} /* End of action function: ExecutionDirector_SetDisableLane2 */

void ExecutionDirector_SetDisableLane3(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneCmd3 = E_CMD_DISABLE_LANE;
  if( ! ExecutionDirector_IsIn_Operational_State( smInfo ) )
  {
    TellLaneAvailability( smInfo, pInputData, pOutputData );
    Monitor_Run_Update( pOutputData->pMonitor );
  }
} /* End of action function: ExecutionDirector_SetDisableLane3 */

void ExecutionDirector_SetDisableLane4(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneCmd4 = E_CMD_DISABLE_LANE;
  if( ! ExecutionDirector_IsIn_Operational_State( smInfo ) )
  {
    TellLaneAvailability( smInfo, pInputData, pOutputData );
    Monitor_Run_Update( pOutputData->pMonitor );
  }
} /* End of action function: ExecutionDirector_SetDisableLane4 */

void ExecutionDirector_SetEnableLane1(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneCmd1 = E_CMD_ENABLE_LANE;
  if( ! ExecutionDirector_IsIn_Operational_State( smInfo ) )
  {
    TellLaneAvailability( smInfo, pInputData, pOutputData );
    Monitor_Run_Update( pOutputData->pMonitor );
  }
} /* End of action function: ExecutionDirector_SetEnableLane1 */

void ExecutionDirector_SetEnableLane2(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneCmd2 = E_CMD_ENABLE_LANE;
  if( ! ExecutionDirector_IsIn_Operational_State( smInfo ) )
  {
    TellLaneAvailability( smInfo, pInputData, pOutputData );
    Monitor_Run_Update( pOutputData->pMonitor );
  }
} /* End of action function: ExecutionDirector_SetEnableLane2 */

void ExecutionDirector_SetEnableLane3(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneCmd3 = E_CMD_ENABLE_LANE;
  if( ! ExecutionDirector_IsIn_Operational_State( smInfo ) )
  {
    TellLaneAvailability( smInfo, pInputData, pOutputData );
    Monitor_Run_Update( pOutputData->pMonitor );
  }
} /* End of action function: ExecutionDirector_SetEnableLane3 */

void ExecutionDirector_SetEnableLane4(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneCmd4 = E_CMD_ENABLE_LANE;
  if( ! ExecutionDirector_IsIn_Operational_State( smInfo ) )
  {
    TellLaneAvailability( smInfo, pInputData, pOutputData );
    Monitor_Run_Update( pOutputData->pMonitor );
  }
} /* End of action function: ExecutionDirector_SetEnableLane4 */

void ExecutionDirector_SetNextOpenLane1(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneRequested = 1;
} /* End of action function: ExecutionDirector_SetNextOpenLane1 */

void ExecutionDirector_SetNextOpenLane2(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneRequested = 2;
} /* End of action function: ExecutionDirector_SetNextOpenLane2 */

void ExecutionDirector_SetNextOpenLane3(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneRequested = 3;
} /* End of action function: ExecutionDirector_SetNextOpenLane3 */

void ExecutionDirector_SetNextOpenLane4(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneRequested = 4;
} /* End of action function: ExecutionDirector_SetNextOpenLane4 */

void ExecutionDirector_SetNextOpenLanePedestrianLanes(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneRequested = 0;
} /* End of action function: ExecutionDirector_SetNextOpenLanePedestrianLanes */

void ExecutionDirector_SetUncontrolledMode(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->ControlModeStatus = UNCONTROLLED;
} /* End of action function: ExecutionDirector_SetUncontrolledMode */

void ExecutionDirector_StartControlMode(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneClosingCompleted = false;
  Crossroad_Run_StartControlling( pOutputData->pCrossroad );
} /* End of action function: ExecutionDirector_StartControlMode */

void ExecutionDirector_StartSystemSwitchingTimer(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  time( &pOutputData->StartSwitchingTime );
} /* End of action function: ExecutionDirector_StartSystemSwitchingTimer */

void ExecutionDirector_StartUncontrolledMode(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Crossroad_Run_StopControlling( pOutputData->pCrossroad );
  pOutputData->LaneRequested = -1;
  pOutputData->CurrentLane = -1;
} /* End of action function: ExecutionDirector_StartUncontrolledMode */

void ExecutionDirector_StopTraffic(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneClosingCompleted = false;
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
  Crossroad_SubSM_Run_Close( pOutputData->pCrossroad, E_Crossroad_SubSM_PedestrianLanes );
  Crossroad_Run_Check( pOutputData->pCrossroad );
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: ExecutionDirector_StopTraffic */

void ExecutionDirector_Update(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: ExecutionDirector_Update */

void ExecutionDirector_WaitForClosingLane(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  usleep( RUN_INTERVAL_TIME_US );
} /* End of action function: ExecutionDirector_WaitForClosingLane */

void ExecutionDirector_WaitForInterval(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  usleep( RUN_INTERVAL_TIME_US );
} /* End of action function: ExecutionDirector_WaitForInterval */

void ExecutionDirector_WaitForLane1(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane1( pOutputData->pCrossroad ) ) )
  {
    pOutputData->LaneClosingCompleted = false;
    usleep( RUN_LANE1_US );
  }
} /* End of action function: ExecutionDirector_WaitForLane1 */

void ExecutionDirector_WaitForLane2(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane2( pOutputData->pCrossroad ) ) )
  {
    pOutputData->LaneClosingCompleted = false;
    usleep( RUN_LANE2_US );
  }
} /* End of action function: ExecutionDirector_WaitForLane2 */

void ExecutionDirector_WaitForLane3(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane3( pOutputData->pCrossroad ) ) )
  {
    pOutputData->LaneClosingCompleted = false;
    usleep( RUN_LANE3_US );
  }
} /* End of action function: ExecutionDirector_WaitForLane3 */

void ExecutionDirector_WaitForLane4(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane4( pOutputData->pCrossroad ) ) )
  {
    pOutputData->LaneClosingCompleted = false;
    usleep( RUN_LANE4_US );
  }
} /* End of action function: ExecutionDirector_WaitForLane4 */

void ExecutionDirector_WaitForPedestrians(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( ! pInputData->LaneClosingCompleted )
  {
    usleep( RUN_PREPARING_US );
    pOutputData->LaneClosingCompleted = true;
  }
} /* End of action function: ExecutionDirector_WaitForPedestrians */

void ExecutionDirector_WaitForSafety(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  pOutputData->LaneClosingCompleted = false;
  usleep( RUN_PEDESTRIAN_LANES_US );
} /* End of action function: ExecutionDirector_WaitForSafety */

void ExecutionDirector_WaitForSystemSwitchingTimer(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  time_t now;
  time( &now );
  double remainingTime = ceil( RUN_SWITCHING_TIME_US - difftime( now, pInputData->StartSwitchingTime ) );
  if( remainingTime < RUN_MIN_SWITCHING_TIME_US )
  {
    remainingTime = RUN_MIN_SWITCHING_TIME_US;
  }

  usleep( remainingTime );
} /* End of action function: ExecutionDirector_WaitForSystemSwitchingTimer */

void ExecutionDirector_WaitForTrafficStops(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  usleep( RUN_STOPING_TRAFFIC_US );
} /* End of action function: ExecutionDirector_WaitForTrafficStops */

/* The implementation of the Persistency Functions */
void ExecutionDirector_Store_Shallow_Operational(
  __attribute__( ( unused ) ) E_ExecutionDirector_Main_States_t state,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pInstance )
{
  static char const* const regfile = "crossroad-executor.bin";
  char const* folder               = getenv( "TMPDIR" );
  char path[ 256 ];
  if( folder == 0 )
  {
    folder = "/tmp";
  }

  strcpy( path, folder );
  strcat( path, "/" );
  strcat( path, regfile );

  FILE* fd = fopen( path, "wb" );
  if( fd != NULL )
  {
    uint16_t sdata = (uint16_t)state;
    fwrite( &sdata, sizeof( sdata ), 1, fd );
    fclose( fd );
  }
} /* End of action function: ExecutionDirector_Store_Shallow_Operational */

E_ExecutionDirector_Main_States_t ExecutionDirector_Load_Shallow_Operational(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pInstance )
{
  E_ExecutionDirector_Main_States_t result = E_ExecutionDirector_init;

  static char const* const regfile = "crossroad-executor.bin";
  char const* folder               = getenv( "TMPDIR" );
  char path[ 256 ];
  if( folder == 0 )
  {
    folder = "/tmp";
  }

  strcpy( path, folder );
  strcat( path, "/" );
  strcat( path, regfile );

  FILE* fd = fopen( path, "rb" );
  if( fd != NULL )
  {
    uint16_t sdata;
    if ( fread( &sdata, sizeof( sdata ), 1, fd ) )
    {
      result = (E_ExecutionDirector_Main_States_t)sdata;
    }
    fclose( fd );
  }

  return result;
} /* End of loader function: ExecutionDirector_Load_Shallow_Operational */

/* internal functions */
static void TellLaneAvailability(
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_ExecutionDirector_DataType_t* const pOutputData )
{
  if( pInputData->LaneCmd1 == E_CMD_DISABLE_LANE )
  {
    Crossroad_SubSM_Run_Disallowed( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
  }
  else if( pInputData->LaneCmd1 == E_CMD_ENABLE_LANE )
  {
    Crossroad_SubSM_Run_Allowed( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane1 );
  }
  else
  {
    /* Nope */
  }

  if( pInputData->LaneCmd2 == E_CMD_DISABLE_LANE )
  {
    Crossroad_SubSM_Run_Disallowed( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
  }
  else if( pInputData->LaneCmd2 == E_CMD_ENABLE_LANE )
  {
    Crossroad_SubSM_Run_Allowed( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane2 );
  }
  else
  {
    /* Nope */
  }

  if( pInputData->LaneCmd3 == E_CMD_DISABLE_LANE )
  {
    Crossroad_SubSM_Run_Disallowed( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
  }
  else if( pInputData->LaneCmd3 == E_CMD_ENABLE_LANE )
  {
    Crossroad_SubSM_Run_Allowed( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane3 );
  }
  else
  {
    /* Nope */
  }

  if( pInputData->LaneCmd4 == E_CMD_DISABLE_LANE )
  {
    Crossroad_SubSM_Run_Disallowed( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
  }
  else if( pInputData->LaneCmd4 == E_CMD_ENABLE_LANE )
  {
    Crossroad_SubSM_Run_Allowed( pOutputData->pCrossroad, E_Crossroad_SubSM_Lane4 );
  }
  else
  {
    /* Nope */
  }

  pOutputData->LaneCmd1 = E_CMD_NOPE;
  pOutputData->LaneCmd2 = E_CMD_NOPE;
  pOutputData->LaneCmd3 = E_CMD_NOPE;
  pOutputData->LaneCmd4 = E_CMD_NOPE;

  Crossroad_Run_Check( pOutputData->pCrossroad );
}

/* End of ExecutionDirector_Auxilary.c */
