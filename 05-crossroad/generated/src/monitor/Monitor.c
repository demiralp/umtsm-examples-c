/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-12-03 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  This file is generated by UMTSM using the code generator `CGen`
 *
 *  !!! It is highly recommended that DO NOT EDIT THIS GENERATED FILE !!!
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

#include "Monitor.h"
#include "Monitor_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static void Monitor_Finalize_Main( S_SM_Monitor_t* pStateMachine );

static void Monitor_Terminate( S_SM_Monitor_t* pStateMachine );

static void* Monitor_DoAction_Main( void* statemachinePtr );

static void Monitor_Enter_Main( S_SM_Monitor_t* pStateMachine );

static void Monitor_Exit_Main( S_SM_Monitor_t* pStateMachine );


static pthread_t Monitor_LaunchDoAction( void *(*threadStart)(void *), S_SM_Monitor_t* pStateMachine, void *stackAddr, size_t stackSize );
static void Monitor_HaltDoAction( pthread_t thr );

void Monitor_Initialize( S_SM_Monitor_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    memset( pStateMachine, 0, sizeof( *pStateMachine ) );

    pthread_mutexattr_t attr;
    pthread_mutexattr_init( &attr );
    pthread_mutex_init( &pStateMachine->guard, &attr );

    pthread_mutex_lock( &pStateMachine->guard );

    Monitor_DataType_Initialize( &pStateMachine->instanceData );

    pStateMachine->runningState.Main = E_Monitor_init;

    pthread_mutex_unlock( &pStateMachine->guard );
    pthread_mutexattr_destroy( &attr );
  }
}

void Monitor_Deinitialize( S_SM_Monitor_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    pthread_mutex_lock( &pStateMachine->guard );

    Monitor_Terminate( pStateMachine );
    pStateMachine->runningState.Main = E_Monitor_final;

    Monitor_DataType_Deinitialize( &pStateMachine->instanceData );

    pthread_mutex_unlock( &pStateMachine->guard );
    pthread_mutex_destroy( &pStateMachine->guard );
  }
}

void Monitor_Start( S_SM_Monitor_t* pStateMachine )
{
  if ( pStateMachine != NULL && ! Monitor_IsIn_Main_Region( pStateMachine ) )
  {
    pthread_mutex_lock( &pStateMachine->guard );

    Monitor_Enter_Main( pStateMachine );
    pStateMachine->runningState.Main = E_Monitor_Main;

    pthread_mutex_unlock( &pStateMachine->guard );
  }
}

bool Monitor_IsIn_Main_Region( S_SM_Monitor_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.Main != E_Monitor_init ) &&
                      ( pStateMachine->runningState.Main != E_Monitor_final );

  return result;
}

bool Monitor_IsIn_Main_State( S_SM_Monitor_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Monitor_IsIn_Main_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Main == E_Monitor_Main );

  return result;
}

S_SM_Monitor_DataType_t* Monitor_GetData( S_SM_Monitor_t* const pStateMachine )
{
  S_SM_Monitor_DataType_t* const pCustomData = ( pStateMachine != NULL ) ? &pStateMachine->instanceData : NULL;
  return pCustomData;
}

void Monitor_Run_ClearMessage( S_SM_Monitor_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    pthread_mutex_lock( &pStateMachine->guard );

    if ( Monitor_IsIn_Main_State( pStateMachine ) )
    {
      Monitor_ClearMessage( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
    }

    pthread_mutex_unlock( &pStateMachine->guard );
  }
}

void Monitor_Run_Update( S_SM_Monitor_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    pthread_mutex_lock( &pStateMachine->guard );

    if ( Monitor_IsIn_Main_State( pStateMachine ) )
    {
      Monitor_RequestUpdate( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
    }

    pthread_mutex_unlock( &pStateMachine->guard );
  }
}

static void Monitor_Finalize_Main(S_SM_Monitor_t* pStateMachine )
{
  if ( Monitor_IsIn_Main_Region( pStateMachine ) )
  {
    pStateMachine->runningState.Main = E_Monitor_final;
  }
}

static void Monitor_Terminate( S_SM_Monitor_t* pStateMachine )
{
  Monitor_Finalize_Main( pStateMachine );
}

static void* Monitor_DoAction_Main( void* statemachinePtr )
{
  S_SM_Monitor_t* pStateMachine = (S_SM_Monitor_t*)statemachinePtr;

  Monitor_DisplayStatusOfLanes( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

  pStateMachine->doFunctionHandler.Main.threadHandle = 0;

  return NULL;
}

static void Monitor_Enter_Main(S_SM_Monitor_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Monitor_Main;

  pStateMachine->doFunctionHandler.Main.threadHandle = Monitor_LaunchDoAction( Monitor_DoAction_Main, pStateMachine, pStateMachine->doFunctionHandler.Main.stack, sizeof( pStateMachine->doFunctionHandler.Main.stack) );
}

static void Monitor_Exit_Main(S_SM_Monitor_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Monitor_Main;

  Monitor_HaltDoAction( pStateMachine->doFunctionHandler.Main.threadHandle );
  pStateMachine->doFunctionHandler.Main.threadHandle = 0;
}

static pthread_t Monitor_LaunchDoAction( void *(*threadStart)(void *), S_SM_Monitor_t* pStateMachine, void *stackAddr, size_t stackSize )
{
  pthread_t thr = 0;

  if ( threadStart != NULL )
  {
    pthread_attr_t attr;

    int err = pthread_attr_init( &attr );
    if ( err == 0 )
    {
      err = pthread_attr_setdetachstate( &attr, PTHREAD_CREATE_DETACHED );

      if ( err == 0 )
      {
        err = pthread_attr_setinheritsched( &attr, PTHREAD_EXPLICIT_SCHED );
      }

      if ( err == 0 )
      {
        err = pthread_attr_setstack( &attr, stackAddr, stackSize );
        err = 0;
      }

      if ( err == 0 )
      {
        err = pthread_create( &thr, &attr, threadStart, pStateMachine);
      }

      if ( err != 0 )
      {
        thr = 0;
      }

      pthread_attr_destroy( &attr );
    }
  }

  return thr;
}

static void Monitor_HaltDoAction( pthread_t thr )
{
  if ( thr != 0 && ! pthread_equal( thr, pthread_self( ) ) )
  {
    pthread_cancel( thr );
  }
}

/* End of Monitor.c */
