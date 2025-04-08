/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2025-04-08 GMT
 *  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *  
 *  This file is generated by UMTSM using the code generator `CGen`
 *  
 *  !!! It is highly recommended that DO NOT EDIT THIS GENERATED FILE !!!
 *  
 *  Released under the MIT License
 *  ============================================================================
 */

/*
 *  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
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

#include "Timewatch.h"
#include "Timewatch_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <stdbool.h>
#include <stddef.h>

static void Timewatch_Finalize_Main( S_SM_Timewatch_t* pStateMachine );

static void Timewatch_Terminate( S_SM_Timewatch_t* pStateMachine );

static void Timewatch_Enter_Main( S_SM_Timewatch_t* pStateMachine );
static void Timewatch_Enter_Run( S_SM_Timewatch_t* pStateMachine );
static void Timewatch_Enter_Pause( S_SM_Timewatch_t* pStateMachine );
static void Timewatch_Enter_Idle( S_SM_Timewatch_t* pStateMachine );
static void Timewatch_Enter_ReportTotalTime( S_SM_Timewatch_t* pStateMachine );

static void Timewatch_Exit_Pause( S_SM_Timewatch_t* pStateMachine );

static void Timewatch_Init_Main( S_SM_Timewatch_t* pStateMachine );

void Timewatch_Initialize( S_SM_Timewatch_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    memset( pStateMachine, 0, sizeof( *pStateMachine ) );

    Timewatch_DataType_Initialize( &pStateMachine->instanceData );

    pStateMachine->runningState.Main = E_Timewatch_init;
  }
}

void Timewatch_Deinitialize( S_SM_Timewatch_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    Timewatch_Terminate( pStateMachine );
    pStateMachine->runningState.Main = E_Timewatch_final;

    Timewatch_DataType_Deinitialize( &pStateMachine->instanceData );
  }
}

void Timewatch_Start( S_SM_Timewatch_t* pStateMachine )
{
  if ( pStateMachine != NULL && ! Timewatch_IsIn_Main_Region( pStateMachine ) )
  {
    Timewatch_Enter_Main( pStateMachine );
    Timewatch_Init_Main( pStateMachine );
  }
}

bool Timewatch_IsIn_Main_Region( S_SM_Timewatch_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.Main != E_Timewatch_init ) &&
                      ( pStateMachine->runningState.Main != E_Timewatch_final );

  return result;
}

bool Timewatch_IsIn_Main_State( S_SM_Timewatch_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Timewatch_IsIn_Main_Region( pStateMachine ) &&
    ( ( pStateMachine->runningState.Main == E_Timewatch_Main ) || 
      ( pStateMachine->runningState.Main == E_Timewatch_Run ) || 
      ( pStateMachine->runningState.Main == E_Timewatch_Idle ) || 
      ( pStateMachine->runningState.Main == E_Timewatch_Pause ) || 
      ( pStateMachine->runningState.Main == E_Timewatch_ReportTotalTime ) );

  return result;
}

bool Timewatch_IsIn_Run_State( S_SM_Timewatch_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Timewatch_IsIn_Main_Region( pStateMachine ) &&
    ( ( pStateMachine->runningState.Main == E_Timewatch_Run ) || 
      ( pStateMachine->runningState.Main == E_Timewatch_Pause ) );

  return result;
}

bool Timewatch_IsIn_Pause_State( S_SM_Timewatch_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Timewatch_IsIn_Main_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Main == E_Timewatch_Pause );

  return result;
}

bool Timewatch_IsIn_Idle_State( S_SM_Timewatch_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Timewatch_IsIn_Main_Region( pStateMachine ) &&
    ( ( pStateMachine->runningState.Main == E_Timewatch_Idle ) || 
      ( pStateMachine->runningState.Main == E_Timewatch_ReportTotalTime ) );

  return result;
}

bool Timewatch_IsIn_ReportTotalTime_State( S_SM_Timewatch_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Timewatch_IsIn_Main_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Main == E_Timewatch_ReportTotalTime );

  return result;
}

S_SM_Timewatch_DataType_t* Timewatch_GetData( S_SM_Timewatch_t* const pStateMachine )
{
  S_SM_Timewatch_DataType_t* const pCustomData = ( pStateMachine != NULL ) ? &pStateMachine->instanceData : NULL;
  return pCustomData;
}

void Timewatch_Run_abort( S_SM_Timewatch_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    if ( Timewatch_IsIn_Main_State( pStateMachine ) )
    {
      if ( Timewatch_IsIn_Run_State( pStateMachine ) )
      {
        if ( Timewatch_IsIn_Pause_State( pStateMachine ) )
        {
          Timewatch_Exit( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

          Timewatch_Terminate( pStateMachine );
        }
        else
        {
          Timewatch_Exit( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

          Timewatch_Terminate( pStateMachine );
        }
      }
      else if ( Timewatch_IsIn_Idle_State( pStateMachine ) )
      {
        if ( Timewatch_IsIn_ReportTotalTime_State( pStateMachine ) )
        {
          Timewatch_Exit( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

          Timewatch_Terminate( pStateMachine );
        }
        else
        {
          Timewatch_Exit( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

          Timewatch_Terminate( pStateMachine );
        }
      }
      else
      {
        Timewatch_Exit( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

        Timewatch_Terminate( pStateMachine );
      }
    }
  }
}

void Timewatch_Run_help( S_SM_Timewatch_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    if ( Timewatch_IsIn_Main_State( pStateMachine ) )
    {
      if ( Timewatch_IsIn_Run_State( pStateMachine ) )
      {
        if ( Timewatch_IsIn_Pause_State( pStateMachine ) )
        {
          Timewatch_PrintHelp( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
        }
        else
        {
          Timewatch_PrintHelp( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
        }
      }
      else if ( Timewatch_IsIn_Idle_State( pStateMachine ) )
      {
        if ( Timewatch_IsIn_ReportTotalTime_State( pStateMachine ) )
        {
          Timewatch_PrintHelp( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
        }
        else
        {
          Timewatch_PrintHelp( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
        }
      }
      else
      {
        Timewatch_PrintHelp( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
    }
  }
}

void Timewatch_Run_pause( S_SM_Timewatch_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    if ( Timewatch_IsIn_Run_State( pStateMachine ) )
    {
      if ( Timewatch_IsIn_Pause_State( pStateMachine ) )
      {
      }
      else
      {
        Timewatch_Enter_Pause( pStateMachine );
        pStateMachine->runningState.Main = E_Timewatch_Pause;
      }
    }
  }
}

void Timewatch_Run_print( S_SM_Timewatch_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    if ( Timewatch_IsIn_Run_State( pStateMachine ) )
    {
      if ( Timewatch_IsIn_Pause_State( pStateMachine ) )
      {
        Timewatch_PrintElapsedTime( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else
      {
        Timewatch_PrintElapsedTime( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
    }
  }
}

void Timewatch_Run_restart( S_SM_Timewatch_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    if ( Timewatch_IsIn_Run_State( pStateMachine ) )
    {
      if ( Timewatch_IsIn_Pause_State( pStateMachine ) )
      {
        Timewatch_PrintStatusReset( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

        Timewatch_Exit_Pause( pStateMachine );
        Timewatch_Enter_Run( pStateMachine );
        pStateMachine->runningState.Main = E_Timewatch_Run;
      }
      else
      {
        Timewatch_PrintStatusReset( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

        Timewatch_Enter_Run( pStateMachine );
        pStateMachine->runningState.Main = E_Timewatch_Run;
      }
    }
  }
}

void Timewatch_Run_resume( S_SM_Timewatch_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    if ( Timewatch_IsIn_Pause_State( pStateMachine ) )
    {
      Timewatch_PrintStatusResume( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

      Timewatch_Exit_Pause( pStateMachine );
      pStateMachine->runningState.Main = E_Timewatch_Run;
    }
  }
}

void Timewatch_Run_start( S_SM_Timewatch_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    if ( Timewatch_IsIn_Idle_State( pStateMachine ) )
    {
      if ( Timewatch_IsIn_ReportTotalTime_State( pStateMachine ) )
      {
        Timewatch_PrintStatusRun( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

        Timewatch_Enter_Run( pStateMachine );
        pStateMachine->runningState.Main = E_Timewatch_Run;
      }
      else
      {
        Timewatch_PrintStatusRun( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

        Timewatch_Enter_Run( pStateMachine );
        pStateMachine->runningState.Main = E_Timewatch_Run;
      }
    }
  }
}

void Timewatch_Run_stop( S_SM_Timewatch_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    if ( Timewatch_IsIn_Run_State( pStateMachine ) )
    {
      if ( Timewatch_IsIn_Pause_State( pStateMachine ) )
      {
        Timewatch_Exit_Pause( pStateMachine );
        Timewatch_Enter_Idle( pStateMachine );
        Timewatch_Enter_ReportTotalTime( pStateMachine );
        pStateMachine->runningState.Main = E_Timewatch_ReportTotalTime;
      }
      else
      {
        Timewatch_Enter_Idle( pStateMachine );
        Timewatch_Enter_ReportTotalTime( pStateMachine );
        pStateMachine->runningState.Main = E_Timewatch_ReportTotalTime;
      }
    }
  }
}

static void Timewatch_Finalize_Main(S_SM_Timewatch_t* pStateMachine )
{
  if ( Timewatch_IsIn_Main_Region( pStateMachine ) )
  {
    pStateMachine->runningState.Main = E_Timewatch_final;
  }
}

static void Timewatch_Terminate( S_SM_Timewatch_t* pStateMachine )
{
  Timewatch_Finalize_Main( pStateMachine );
}

static void Timewatch_Init_Main( S_SM_Timewatch_t* pStateMachine )
{
  Timewatch_Enter_Idle( pStateMachine );
  pStateMachine->runningState.Main = E_Timewatch_Idle;
}

static void Timewatch_Enter_Main(S_SM_Timewatch_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Timewatch_Main;

  Timewatch_PrintHelp( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
}

static void Timewatch_Enter_Run(S_SM_Timewatch_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Timewatch_Run;

  Timewatch_InitWatchProperties( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
}

static void Timewatch_Enter_Pause(S_SM_Timewatch_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Timewatch_Pause;

  Timewatch_InitPauseTime( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

  Timewatch_PrintStatusPause( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
}

static void Timewatch_Enter_Idle(S_SM_Timewatch_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Timewatch_Idle;

  Timewatch_PrintStatusIdle( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
}

static void Timewatch_Enter_ReportTotalTime(S_SM_Timewatch_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Timewatch_ReportTotalTime;

  Timewatch_ReportTotalTime( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
}

static void Timewatch_Exit_Pause(S_SM_Timewatch_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Timewatch_Pause;

  Timewatch_UpdateSuspendentDuration( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
}

/* End of Timewatch.c */
