/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2024-09-10 GMT.
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

#include "Monitor_Auxilary.h"
#include "Monitor_DataType.h"

#include <assert.h>
#include <memory.h>
#include <ncurses.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include <Crossroad.h>
#include <ExecutionDirector.h>
#include <Lane.h>
#include <PedestrianLights.h>
#include <TrafficLight.h>

#include <ExecutionDirector_Auxilary.h>

static char const* LaneNo2Name( int no );
static void PrintHelpLine( char const * const key, char const * const summary );
static void PrintHelp(
  __attribute__( ( unused ) ) S_SM_Monitor_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Monitor_DataType_t const* const pInstanceData );

/* The implementation of the actions */
void Monitor_ClearMessage(
  __attribute__( ( unused ) ) S_SM_Monitor_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Monitor_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Monitor_DataType_t* const pOutputData )
{
  pOutputData->Message[ 0 ] = '\0';
} /* End of action function: Monitor_ClearMessage */

void Monitor_DisplayStatusOfLanes(
  __attribute__( ( unused ) ) S_SM_Monitor_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Monitor_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Monitor_DataType_t* const pOutputData )
{
  S_SM_Lane_t* pLane[ 4 ];

  pLane[ 0 ] = Crossroad_GetSubSM_Lane1( pOutputData->pCrossroad );
  pLane[ 1 ] = Crossroad_GetSubSM_Lane2( pOutputData->pCrossroad );
  pLane[ 2 ] = Crossroad_GetSubSM_Lane3( pOutputData->pCrossroad );
  pLane[ 3 ] = Crossroad_GetSubSM_Lane4( pOutputData->pCrossroad );

  S_SM_ExecutionDirector_DataType_t* pExecutorData = ExecutionDirector_GetData( pOutputData->pExecutionDirector );

  S_SM_TrafficLight_t* pTrafficLight[ 4 ];
  pTrafficLight[ 0 ] = Crossroad_GetSubSM_TrafficLight1( pOutputData->pCrossroad );
  pTrafficLight[ 1 ] = Crossroad_GetSubSM_TrafficLight2( pOutputData->pCrossroad );
  pTrafficLight[ 2 ] = Crossroad_GetSubSM_TrafficLight3( pOutputData->pCrossroad );
  pTrafficLight[ 3 ] = Crossroad_GetSubSM_TrafficLight4( pOutputData->pCrossroad );

  S_SM_PedestrianLights_t* pPedestrianLights = Crossroad_GetSubSM_PedestrianLights( pOutputData->pCrossroad );

  while( true )
  {
    while( ! pInputData->UpdateStatus )
    {
      usleep( 10000 );
    }

    clear( );

    attron( COLOR_PAIR( 1 ) );
    printw( "System State     : " );
    attroff( COLOR_PAIR( 1 ) );

    attron( COLOR_PAIR( 2 ) );
    if( ExecutionDirector_IsIn_OnCloseLane1_State( pOutputData->pExecutionDirector ) )
    {
      printw( "LANE1 IS ON CLOSING" );
    }
    else if( ExecutionDirector_IsIn_OnCloseLane2_State( pOutputData->pExecutionDirector ) )
    {
      printw( "LANE2 IS ON CLOSING" );
    }
    else if( ExecutionDirector_IsIn_OnCloseLane3_State( pOutputData->pExecutionDirector ) )
    {
      printw( "LANE3 IS ON CLOSING" );
    }
    else if( ExecutionDirector_IsIn_OnCloseLane4_State( pOutputData->pExecutionDirector ) )
    {
      printw( "LANE4 IS ON CLOSING" );
    }
    else if( ExecutionDirector_IsIn_OnClosePedestrianLanes_State( pOutputData->pExecutionDirector ) )
    {
      printw( "PEDESTRIAN LANES ARE ON CLOSING" );
    }
    else if( ExecutionDirector_IsIn_OpenLane1_State( pOutputData->pExecutionDirector ) )
    {
      printw( "LANE1" );
    }
    else if( ExecutionDirector_IsIn_OpenLane2_State( pOutputData->pExecutionDirector ) )
    {
      printw( "LANE2" );
    }
    else if( ExecutionDirector_IsIn_OpenLane3_State( pOutputData->pExecutionDirector ) )
    {
      printw( "LANE3" );
    }
    else if( ExecutionDirector_IsIn_OpenLane4_State( pOutputData->pExecutionDirector ) )
    {
      printw( "LANE4" );
    }
    else if( ExecutionDirector_IsIn_OpenPedestrianLanes_State( pOutputData->pExecutionDirector ) )
    {
      printw( "PEDESTRIAN LANES" );
    }
    else if( ExecutionDirector_IsIn_Uncontrolled_State( pOutputData->pExecutionDirector ) )
    {
      printw( "UNCONTROLLED" );
    }
    else if( ExecutionDirector_IsIn_SwitchControlState_State( pOutputData->pExecutionDirector ) )
    {
      if( ExecutionDirector_IsControlledModeRequested( pOutputData->pExecutionDirector, pExecutorData ) )
      {
        printw( "SWITCHING TO CONTROLLED MODE" );
      }
      else if( ExecutionDirector_IsUncontrolledModeRequested( pOutputData->pExecutionDirector, pExecutorData ) )
      {
        printw( "SWITCHING TO UNCONTROLLED MODE" );
      }
      else
      {
        printw( "RESTORING CONTROL MODE BACK" );
      }
    }
    else if( ExecutionDirector_IsIn_GoesToOperational_State( pOutputData->pExecutionDirector ) )
    {
      if( ExecutionDirector_IsControlledModeRequested( pOutputData->pExecutionDirector, pExecutorData ) )
      {
        printw( "GOES TO CONTROLLED MODE" );
      }
      else if( ExecutionDirector_IsUncontrolledModeRequested( pOutputData->pExecutionDirector, pExecutorData ) )
      {
        printw( "GOES TO UNCONTROLLED MODE" );
      }
      else
      {
        printw( "GOES TO OPERATIONAL" );
      }
    }
    else if( ExecutionDirector_IsIn_GoesToStandby_State( pOutputData->pExecutionDirector ) )
    {
      printw( "GOES TO STANDBY" );
    }
    else if( ExecutionDirector_IsIn_StandBy_State( pOutputData->pExecutionDirector ) )
    {
      printw( "STANDBY" );
    }
    else
    {
      printw( "UNKNOWN" );
    }
    attroff( COLOR_PAIR( 2 ) );

    printw( "\n" );

    for( int lane = 0; lane < 4; ++lane )
    {
      bool const available = Lane_IsIn_Available_State( pLane[ lane ] );
      bool const red       = TrafficLight_IsIn_Red_On_State( pTrafficLight[ lane ] )
        || TrafficLight_IsIn_Red_On_Flashing_State( pTrafficLight[ lane ] );
      bool const amber = TrafficLight_IsIn_Amber_On_State( pTrafficLight[ lane ] )
        || TrafficLight_IsIn_Amber_On_Flashing_State( pTrafficLight[ lane ] );
      bool const green = TrafficLight_IsIn_Green_On_State( pTrafficLight[ lane ] )
        || TrafficLight_IsIn_Green_On_Flashing_State( pTrafficLight[ lane ] );

      int const redColor   = red ? 3 : 6;
      int const amberColor = amber ? 4 : 6;
      int const greenColor = green ? 5 : 6;

      attron( COLOR_PAIR( 1 ) );
      printw( "LANE%d            : ", lane + 1 );
      attroff( COLOR_PAIR( 1 ) );

      attron( COLOR_PAIR( 2 ) );
      printw( "%s ", ( available ? "   " : "N/A" ) );
      attroff( COLOR_PAIR( 2 ) );

      attron( COLOR_PAIR( redColor ) );
      printw( " " );
      attroff( COLOR_PAIR( redColor ) );

      attron( COLOR_PAIR( amberColor ) );
      printw( " " );
      attroff( COLOR_PAIR( amberColor ) );

      attron( COLOR_PAIR( greenColor ) );
      printw( " " );
      attroff( COLOR_PAIR( greenColor ) );

      printw( "\n" );
    }

    // Pedestrian lane
    bool const red = PedestrianLights_IsIn_Red_On_State( pPedestrianLights )
      || PedestrianLights_IsIn_Red_On_Flashing_State( pPedestrianLights );
    bool const green = PedestrianLights_IsIn_Green_On_State( pPedestrianLights )
      || PedestrianLights_IsIn_Green_On_Flashing_State( pPedestrianLights );

    int const redColor   = red ? 3 : 6;
    int const greenColor = green ? 5 : 6;

    attron( COLOR_PAIR( 1 ) );
    printw( "PEDESTRIAN LANES :     " );
    attroff( COLOR_PAIR( 1 ) );

    attron( COLOR_PAIR( redColor ) );
    printw( " " );
    attroff( COLOR_PAIR( redColor ) );

    printw( " " );

    attron( COLOR_PAIR( greenColor ) );
    printw( " " );
    attroff( COLOR_PAIR( greenColor ) );

    printw( "\n" );

    attron( COLOR_PAIR( 1 ) );
    printw( "PLAN             : " );
    attroff( COLOR_PAIR( 1 ) );

    attron( COLOR_PAIR( 2 ) );
    printw( "Next -> %s Requested -> %s\n", LaneNo2Name( pExecutorData->NextLane ), LaneNo2Name( pExecutorData->LaneRequested ) );
    attroff( COLOR_PAIR( 2 ) );

    attron( COLOR_PAIR( 1 ) );
    printw( "MESSAGE          : " );
    attroff( COLOR_PAIR( 1 ) );

    attron( COLOR_PAIR( 2 ) );
    printw( "%s\n", pInputData->Message );
    attroff( COLOR_PAIR( 2 ) );

    PrintHelp(smInfo, pInputData ); 

    refresh( );
    pOutputData->UpdateStatus = false;

  }
} /* End of action function: Monitor_DisplayStatusOfLanes */

void Monitor_RequestUpdate(
  __attribute__( ( unused ) ) S_SM_Monitor_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Monitor_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Monitor_DataType_t* const pOutputData )
{
  pOutputData->UpdateStatus = true;
} /* End of action function: Monitor_RequestUpdate */

/* internal functions */
static char const* LaneNo2Name( int no )
{
  static char const* const name[] = {
    "Pedestrian Lanes",
    "Lane1",
    "Lane2",
    "Lane3",
    "Lane4",
    "N/A"
  };

  return name[ ( no < 0 || no > 4 ) ? 5 : no ];
}

static void PrintHelpLine( char const * const key, char const * const summary)
{
  attron( COLOR_PAIR( 7 ) );
  printw( "%-6s :", key );
  attroff( COLOR_PAIR( 7 ) );

  attron( COLOR_PAIR( 8 ) );
  printw( " %s\n", summary );
  attroff( COLOR_PAIR( 8 ) );
}

static void PrintHelp(
  __attribute__( ( unused ) ) S_SM_Monitor_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Monitor_DataType_t const* const pInstanceData )
{
  S_SM_Lane_t* pLane[ 4 ];

  pLane[ 0 ] = Crossroad_GetSubSM_Lane1( pInstanceData->pCrossroad );
  pLane[ 1 ] = Crossroad_GetSubSM_Lane2( pInstanceData->pCrossroad );
  pLane[ 2 ] = Crossroad_GetSubSM_Lane3( pInstanceData->pCrossroad );
  pLane[ 3 ] = Crossroad_GetSubSM_Lane4( pInstanceData->pCrossroad );
   
  printw("\n");
  printw("Keys for controlling the lanes\n");

  if( ExecutionDirector_IsIn_StandBy_State( pInstanceData->pExecutionDirector ) )
  {
    PrintHelpLine( "R", "Start running the system" );
    PrintHelpLine( "C", "Start running the system in CONTROLLED mode" );
    PrintHelpLine( "U", "Start running the system in UNCONTROLLED mode" );
  }
  else
  {
    if ( ExecutionDirector_IsIn_Controlled_State( pInstanceData->pExecutionDirector ) )
    {
      PrintHelpLine( "U", "Switching to UNCONTROLLED mode" );
    }
    else if ( ExecutionDirector_IsIn_Uncontrolled_State( pInstanceData->pExecutionDirector ) )
    {
      PrintHelpLine( "C", "Switching to CONTROLLED mode" );
    }
    else
    {
      PrintHelpLine( "C", "Switching to CONTROLLED mode" );
      PrintHelpLine( "U", "Switching to UNCONTROLLED mode" );
    }
    PrintHelpLine( "S", "Switching to STANDBY mode" );
  }

  for( int lane = 0; lane < 4; ++lane )
  {
    char key[8];
    char summary[128];
    
    bool const available = Lane_IsIn_Available_State( pLane[ lane ] );
    
    if( available )
    {
      sprintf( key, "D-%d", lane+1 );
      sprintf( summary, "Disable lane %d", lane+1 );
    }
    else
    {
      sprintf( key, "E-%d", lane+1 );
      sprintf( summary, "Enable lane %d", lane+1 );
    }
    PrintHelpLine( key, summary );
  }

  if ( ExecutionDirector_IsIn_Controlled_State( pInstanceData->pExecutionDirector ) )
  {
    for( int lane = 0; lane < 4; ++lane )
    {
      char key[8];
      char summary[128];
      
      bool const available = Lane_IsIn_Available_State( pLane[ lane ] );
      
      if( available )
      {
        sprintf( key, "%d", lane+1 );
        sprintf( summary, "Open the lane %d", lane+1 );
        PrintHelpLine( key, summary );
      }
    }
  }

  PrintHelpLine( "Q", "Quit" );
  PrintHelpLine( "Ctrl+C", "Terminate immediately" );
  PrintHelpLine( "SPACE", "Update this screen" );
}

/* End of Monitor_Auxilary.c */
