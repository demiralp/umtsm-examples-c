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

#include "Dashboard_Auxilary.h"
#include "Crossroad.h"

#include <assert.h>
#include <ctype.h>
#include <memory.h>
#include <ncurses.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include <ExecutionDirector.h>
#include <Lane.h>
#include <Monitor.h>

/* The implementation of the guards */
bool Dashboard_IsKey_1(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = pInstance->LastInputKey == '1';
  return result;
} /* End of guard function: Dashboard_IsKey_1 */

bool Dashboard_IsKey_2(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = pInstance->LastInputKey == '2';
  return result;
} /* End of guard function: Dashboard_IsKey_2 */

bool Dashboard_IsKey_3(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = pInstance->LastInputKey == '3';
  return result;
} /* End of guard function: Dashboard_IsKey_3 */

bool Dashboard_IsKey_4(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = pInstance->LastInputKey == '4';
  return result;
} /* End of guard function: Dashboard_IsKey_4 */

bool Dashboard_IsKey_C(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = toupper( pInstance->LastInputKey ) == 'C';
  return result;
} /* End of guard function: Dashboard_IsKey_C */

bool Dashboard_IsKey_D(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = toupper( pInstance->LastInputKey ) == 'D';
  return result;
} /* End of guard function: Dashboard_IsKey_D */

bool Dashboard_IsKey_E(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = toupper( pInstance->LastInputKey ) == 'E';
  return result;
} /* End of guard function: Dashboard_IsKey_E */

bool Dashboard_IsKey_P(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = toupper( pInstance->LastInputKey ) == 'P';
  return result;
} /* End of guard function: Dashboard_IsKey_P */

bool Dashboard_IsKey_Q(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = toupper( pInstance->LastInputKey ) == 'Q';
  return result;
} /* End of guard function: Dashboard_IsKey_Q */

bool Dashboard_IsKey_R(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = toupper( pInstance->LastInputKey ) == 'R';
  return result;
} /* End of guard function: Dashboard_IsKey_R */

bool Dashboard_IsKey_S(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = toupper( pInstance->LastInputKey ) == 'S';
  return result;
} /* End of guard function: Dashboard_IsKey_S */

bool Dashboard_IsKey_Space(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = pInstance->LastInputKey == ' ';
  return result;
} /* End of guard function: Dashboard_IsKey_Space */

bool Dashboard_IsKey_U(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = toupper( pInstance->LastInputKey ) == 'U';
  return result;
} /* End of guard function: Dashboard_IsKey_U */

/* The implementation of the actions */
void Dashboard_DisableLane1(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_DisableLane1( pOutputData->pExecutionDirector );
} /* End of action function: Dashboard_DisableLane1 */

void Dashboard_DisableLane2(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_DisableLane2( pOutputData->pExecutionDirector );
} /* End of action function: Dashboard_DisableLane2 */

void Dashboard_DisableLane3(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_DisableLane3( pOutputData->pExecutionDirector );
} /* End of action function: Dashboard_DisableLane3 */

void Dashboard_DisableLane4(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_DisableLane4( pOutputData->pExecutionDirector );
} /* End of action function: Dashboard_DisableLane4 */

void Dashboard_EnableLane1(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_EnableLane1( pOutputData->pExecutionDirector );
} /* End of action function: Dashboard_EnableLane1 */

void Dashboard_EnableLane2(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_EnableLane2( pOutputData->pExecutionDirector );
} /* End of action function: Dashboard_EnableLane2 */

void Dashboard_EnableLane3(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_EnableLane3( pOutputData->pExecutionDirector );
} /* End of action function: Dashboard_EnableLane3 */

void Dashboard_EnableLane4(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_EnableLane4( pOutputData->pExecutionDirector );
} /* End of action function: Dashboard_EnableLane4 */

void Dashboard_OpenLane1(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane1( pOutputData->pCrossroad ) ) )
  {
    ExecutionDirector_Run_OpenLane1( pOutputData->pExecutionDirector );
  }
} /* End of action function: Dashboard_OpenLane1 */

void Dashboard_OpenLane2(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane2( pOutputData->pCrossroad ) ) )
  {
    ExecutionDirector_Run_OpenLane2( pOutputData->pExecutionDirector );
  }
} /* End of action function: Dashboard_OpenLane2 */

void Dashboard_OpenLane3(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane3( pOutputData->pCrossroad ) ) )
  {
    ExecutionDirector_Run_OpenLane3( pOutputData->pExecutionDirector );
  }
} /* End of action function: Dashboard_OpenLane3 */

void Dashboard_OpenLane4(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_Lane4( pOutputData->pCrossroad ) ) )
  {
    ExecutionDirector_Run_OpenLane4( pOutputData->pExecutionDirector );
  }
} /* End of action function: Dashboard_OpenLane4 */

void Dashboard_OpenPedestrianLanes(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  if( Lane_IsIn_Available_State( Crossroad_GetSubSM_PedestrianLanes( pOutputData->pCrossroad ) ) )
  {
    ExecutionDirector_Run_OpenPedestrianLanes( pOutputData->pExecutionDirector );
  }
} /* End of action function: Dashboard_OpenPedestrianLanes */

void Dashboard_Quit(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  raise( SIGINT );
} /* End of action function: Dashboard_Quit */

void Dashboard_ReadCommand(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  static char const* const keyChar = "CcDdEeSsPpQqRrUu1234 ";
  bool okay                        = false;
  int ch;

  do
  {
    ch   = wgetch( stdscr );
    okay = strchr( keyChar, ch ) != NULL;
  } while( ! okay );

  pOutputData->LastInputKey = ch;
} /* End of action function: Dashboard_ReadCommand */

void Dashboard_ReadLaneNumber(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  pOutputData->LastInputKey = wgetch( stdscr );
} /* End of action function: Dashboard_ReadLaneNumber */

void Dashboard_RunTheSystem(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_SystemEnabled( pOutputData->pExecutionDirector );
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: Dashboard_RunTheSystem */

void Dashboard_StandbyTheSystem(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_SystemDisabled( pOutputData->pExecutionDirector );
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: Dashboard_StandbyTheSystem */

void Dashboard_SwitchToControlledProgram(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_TakeControl( pOutputData->pExecutionDirector );
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: Dashboard_SwitchToControlledProgram */

void Dashboard_SwitchToUncontrolledProgram(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  ExecutionDirector_Run_ReleaseControl( pOutputData->pExecutionDirector );
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: Dashboard_SwitchToUncontrolledProgram */

void Dashboard_UpdateScreen(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  Monitor_Run_Update( pOutputData->pMonitor );
} /* End of action function: Dashboard_UpdateScreen */

/* End of Dashboard_Auxilary.c */
