/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2025-04-05 GMT
 *  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  Released under the MIT License
 *  ==============================================================================
 */

/*  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
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

#include "Timewatch_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <signal.h>

#include <ncurses.h>

/* The implementation of the actions */
void Timewatch_Exit(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  raise( SIGINT );
} /* End of action function: Timewatch_Exit */

void Timewatch_InitPauseTime(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  time( &pOutputData->Run.Pause.start_pause_time );
} /* End of action function: Timewatch_InitPauseTime */

void Timewatch_InitWatchProperties(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  time( &pOutputData->Run.start_time );
  pOutputData->Run.suspended_duration= 0.0;
} /* End of action function: Timewatch_InitWatchProperties */

void Timewatch_PrintElapsedTime(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  time_t now;
  time( &now );
  double totalTime= totalTime = difftime(now, pInputData->Run.start_time) - pInputData->Run.suspended_duration;
  if ( Timewatch_IsIn_Pause_State(smInfo))
  {
    totalTime -= difftime(now, pInputData->Run.Pause.start_pause_time);
  }

  printw( "%1.0fs\n", totalTime);
  refresh( );
} /* End of action function: Timewatch_PrintElapsedTime */

void Timewatch_PrintHelp(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  printw( "H - Print help menu\n");
  refresh( );
  printw( "S - Start timer\n");
  refresh( );
  printw( "Z - Stop timer\n");
  refresh( );
  printw( "P - Pause timer\n");
  refresh( );
  printw( "R - Resume timer\n");
  refresh( );
  printw( "X - Restart timer\n");
  refresh( );
  printw( "Q - Exit\n");
  refresh( );
  printw( "SPACE - Print counter\n");
  refresh( );
} /* End of action function: Timewatch_PrintHelp */

void Timewatch_PrintStatusIdle(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  printw( "<IDLE>\n");
  refresh( );
} /* End of action function: Timewatch_PrintStatusIdle */

void Timewatch_PrintStatusPause(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  printw( "<PAUSE>\n");
  refresh( );
} /* End of action function: Timewatch_PrintStatusPause */

void Timewatch_PrintStatusReset(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  printw( "<RESTART>\n");
  refresh( );
} /* End of action function: Timewatch_PrintStatusReset */

void Timewatch_PrintStatusResume(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  printw( "<RESUME>\n");
} /* End of action function: Timewatch_PrintStatusResume */

void Timewatch_PrintStatusRun(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  printw( "<RUN>\n");
  refresh( );
} /* End of action function: Timewatch_PrintStatusRun */

void Timewatch_ReportTotalTime(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  time_t now;
  time( &now );
  double totalTime = difftime(now, pInputData->Run.start_time) - pInputData->Run.suspended_duration;

  printw( "total time : %1.0fs\n", totalTime);
  refresh( );
} /* End of action function: Timewatch_ReportTotalTime */

void Timewatch_UpdateSuspendentDuration(
  __attribute__( ( unused ) ) S_SM_Timewatch_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Timewatch_DataType_t* const pOutputData )
{
  time_t now;
  time( &now );
  pOutputData->Run.suspended_duration+=difftime( now, pInputData->Run.Pause.start_pause_time );
  pOutputData->Run.Pause.start_pause_time= now;
} /* End of action function: Timewatch_UpdateSuspendentDuration */

/* End of Timewatch_Auxilary.c */
