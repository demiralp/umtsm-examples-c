/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-12-03 GMT
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

#include "KeyPressEventGenerator.h"
#include "KeyPressEventGenerator_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static void KeyPressEventGenerator_Finalize_Main( S_SM_KeyPressEventGenerator_t* pStateMachine );
static void KeyPressEventGenerator_Finalize_KeyBaseEvent( S_SM_KeyPressEventGenerator_t* pStateMachine );
static void KeyPressEventGenerator_Finalize_TimeBaseEvent( S_SM_KeyPressEventGenerator_t* pStateMachine );

static void KeyPressEventGenerator_Terminate( S_SM_KeyPressEventGenerator_t* pStateMachine );

static void* KeyPressEventGenerator_DoAction_KeyEvent( void* statemachinePtr );
static void* KeyPressEventGenerator_DoAction_TimeCounter( void* statemachinePtr );

static void KeyPressEventGenerator_Enter_KeyEvent( S_SM_KeyPressEventGenerator_t* pStateMachine );
static void KeyPressEventGenerator_Enter_TimeCounter( S_SM_KeyPressEventGenerator_t* pStateMachine );

static void KeyPressEventGenerator_Exit_KeyEvent( S_SM_KeyPressEventGenerator_t* pStateMachine );
static void KeyPressEventGenerator_Exit_TimeCounter( S_SM_KeyPressEventGenerator_t* pStateMachine );

static void KeyPressEventGenerator_Init_Main( S_SM_KeyPressEventGenerator_t* pStateMachine );
static void KeyPressEventGenerator_Init_KeyBaseEvent( S_SM_KeyPressEventGenerator_t* pStateMachine );
static void KeyPressEventGenerator_Init_TimeBaseEvent( S_SM_KeyPressEventGenerator_t* pStateMachine );

static pthread_t KeyPressEventGenerator_LanchDoAction( void *(*threadStart)(void *), S_SM_KeyPressEventGenerator_t* pStateMachine, void *stackAddr, size_t stackSize );
static void KeyPressEventGenerator_HaltDoAction( pthread_t thr );

void KeyPressEventGenerator_Initialize( S_SM_KeyPressEventGenerator_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    memset( pStateMachine, 0, sizeof( *pStateMachine ) );

    pthread_mutexattr_t attr;
    pthread_mutexattr_init( &attr );
    pthread_mutex_init( &pStateMachine->guard, &attr );

    pthread_mutex_lock( &pStateMachine->guard );

    KeyPressEventGenerator_DataType_Initialize( &pStateMachine->instanceData );

    pStateMachine->runningState.Main = E_KeyPressEventGenerator_init;

    pthread_mutex_unlock( &pStateMachine->guard );
    pthread_mutexattr_destroy( &attr );
  }
}

void KeyPressEventGenerator_Deinitialize( S_SM_KeyPressEventGenerator_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    pthread_mutex_lock( &pStateMachine->guard );

    KeyPressEventGenerator_Terminate( pStateMachine );
    pStateMachine->runningState.Main = E_KeyPressEventGenerator_final;

    KeyPressEventGenerator_DataType_Deinitialize( &pStateMachine->instanceData );

    pthread_mutex_unlock( &pStateMachine->guard );
    pthread_mutex_destroy( &pStateMachine->guard );
  }
}

void KeyPressEventGenerator_Start( S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  if ( pStateMachine != NULL && ! KeyPressEventGenerator_IsIn_Main_Region( pStateMachine ) )
  {
    pthread_mutex_lock( &pStateMachine->guard );

    KeyPressEventGenerator_Init_Main( pStateMachine );

    pStateMachine->runningState.Main = E_KeyPressEventGenerator_Main;

    pthread_mutex_unlock( &pStateMachine->guard );
  }
}

bool KeyPressEventGenerator_IsIn_Main_Region( S_SM_KeyPressEventGenerator_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.Main != E_KeyPressEventGenerator_init ) &&
                      ( pStateMachine->runningState.Main != E_KeyPressEventGenerator_final );

  return result;
}

bool KeyPressEventGenerator_IsIn_KeyBaseEvent_Region( S_SM_KeyPressEventGenerator_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.KeyBaseEvent != E_KeyPressEventGenerator_KeyBaseEvent_init ) &&
                      ( pStateMachine->runningState.KeyBaseEvent != E_KeyPressEventGenerator_KeyBaseEvent_final ) &&
                      KeyPressEventGenerator_IsIn_Main_State( pStateMachine );

  return result;
}

bool KeyPressEventGenerator_IsIn_TimeBaseEvent_Region( S_SM_KeyPressEventGenerator_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.TimeBaseEvent != E_KeyPressEventGenerator_TimeBaseEvent_init ) &&
                      ( pStateMachine->runningState.TimeBaseEvent != E_KeyPressEventGenerator_TimeBaseEvent_final ) &&
                      KeyPressEventGenerator_IsIn_Main_State( pStateMachine );

  return result;
}

bool KeyPressEventGenerator_IsIn_Main_State( S_SM_KeyPressEventGenerator_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    KeyPressEventGenerator_IsIn_Main_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Main == E_KeyPressEventGenerator_Main );

  return result;
}

bool KeyPressEventGenerator_IsIn_KeyEvent_State( S_SM_KeyPressEventGenerator_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    KeyPressEventGenerator_IsIn_KeyBaseEvent_Region( pStateMachine ) &&
    ( pStateMachine->runningState.KeyBaseEvent == E_KeyPressEventGenerator_KeyEvent );

  return result;
}

bool KeyPressEventGenerator_IsIn_TimeCounter_State( S_SM_KeyPressEventGenerator_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    KeyPressEventGenerator_IsIn_TimeBaseEvent_Region( pStateMachine ) &&
    ( pStateMachine->runningState.TimeBaseEvent == E_KeyPressEventGenerator_TimeCounter );

  return result;
}

S_SM_KeyPressEventGenerator_DataType_t* KeyPressEventGenerator_GetData( S_SM_KeyPressEventGenerator_t* const pStateMachine )
{
  S_SM_KeyPressEventGenerator_DataType_t* const pCustomData = ( pStateMachine != NULL ) ? &pStateMachine->instanceData : NULL;
  return pCustomData;
}

static void KeyPressEventGenerator_Finalize_Main(S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  if ( KeyPressEventGenerator_IsIn_Main_Region( pStateMachine ) )
  {
    pStateMachine->runningState.Main = E_KeyPressEventGenerator_final;
  }
}

static void KeyPressEventGenerator_Finalize_KeyBaseEvent(S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  if ( KeyPressEventGenerator_IsIn_KeyBaseEvent_Region( pStateMachine ) )
  {
    if ( KeyPressEventGenerator_IsIn_KeyEvent_State( pStateMachine ) )
    {
      if ( pStateMachine->doFunctionHandler.KeyEvent.threadHandle != 0 && ! pthread_equal( pStateMachine->doFunctionHandler.KeyEvent.threadHandle, pthread_self( ) ) )
      {
        pthread_cancel( pStateMachine->doFunctionHandler.KeyEvent.threadHandle );
        pStateMachine->doFunctionHandler.KeyEvent.threadHandle = 0;
      }
    }
    pStateMachine->runningState.KeyBaseEvent = E_KeyPressEventGenerator_KeyBaseEvent_final;
  }
}

static void KeyPressEventGenerator_Finalize_TimeBaseEvent(S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  if ( KeyPressEventGenerator_IsIn_TimeBaseEvent_Region( pStateMachine ) )
  {
    if ( KeyPressEventGenerator_IsIn_TimeCounter_State( pStateMachine ) )
    {
      if ( pStateMachine->doFunctionHandler.TimeCounter.threadHandle != 0 && ! pthread_equal( pStateMachine->doFunctionHandler.TimeCounter.threadHandle, pthread_self( ) ) )
      {
        pthread_cancel( pStateMachine->doFunctionHandler.TimeCounter.threadHandle );
        pStateMachine->doFunctionHandler.TimeCounter.threadHandle = 0;
      }
    }
    pStateMachine->runningState.TimeBaseEvent = E_KeyPressEventGenerator_TimeBaseEvent_final;
  }
}

static void KeyPressEventGenerator_Terminate( S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  KeyPressEventGenerator_Finalize_Main( pStateMachine );
}

static void KeyPressEventGenerator_Init_Main( S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  KeyPressEventGenerator_Init_KeyBaseEvent( pStateMachine );
  KeyPressEventGenerator_Init_TimeBaseEvent( pStateMachine );
}

static void KeyPressEventGenerator_Init_KeyBaseEvent( S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  KeyPressEventGenerator_Enter_KeyEvent( pStateMachine );
  pStateMachine->runningState.KeyBaseEvent = E_KeyPressEventGenerator_KeyEvent;
}

static void KeyPressEventGenerator_Init_TimeBaseEvent( S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  KeyPressEventGenerator_Enter_TimeCounter( pStateMachine );
  pStateMachine->runningState.TimeBaseEvent = E_KeyPressEventGenerator_TimeCounter;
}

static void* KeyPressEventGenerator_DoAction_KeyEvent( void* statemachinePtr )
{
  S_SM_KeyPressEventGenerator_t* pStateMachine = (S_SM_KeyPressEventGenerator_t*)statemachinePtr;

  KeyPressEventGenerator_ReadKey( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

  pthread_mutex_lock( &pStateMachine->guard );

  if ( KeyPressEventGenerator_IsIn_KeyEvent_State( pStateMachine ) )
  {
    KeyPressEventGenerator_Exit_KeyEvent( pStateMachine );
    KeyPressEventGenerator_Enter_KeyEvent( pStateMachine );
    pStateMachine->runningState.KeyBaseEvent = E_KeyPressEventGenerator_KeyEvent;
  }

  pthread_mutex_unlock( &pStateMachine->guard );

  return NULL;
}

static void* KeyPressEventGenerator_DoAction_TimeCounter( void* statemachinePtr )
{
  S_SM_KeyPressEventGenerator_t* pStateMachine = (S_SM_KeyPressEventGenerator_t*)statemachinePtr;

  KeyPressEventGenerator_TimeBaseEventGenerator( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

  pthread_mutex_lock( &pStateMachine->guard );

  if ( KeyPressEventGenerator_IsIn_TimeCounter_State( pStateMachine ) )
  {
    KeyPressEventGenerator_Exit_TimeCounter( pStateMachine );
    KeyPressEventGenerator_Enter_TimeCounter( pStateMachine );
    pStateMachine->runningState.TimeBaseEvent = E_KeyPressEventGenerator_TimeCounter;
  }

  pthread_mutex_unlock( &pStateMachine->guard );

  return NULL;
}

static void KeyPressEventGenerator_Enter_KeyEvent(S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  pStateMachine->runningState.KeyBaseEvent = E_KeyPressEventGenerator_KeyEvent;

  pStateMachine->doFunctionHandler.KeyEvent.threadHandle = KeyPressEventGenerator_LanchDoAction( KeyPressEventGenerator_DoAction_KeyEvent, pStateMachine, pStateMachine->doFunctionHandler.KeyEvent.stack, sizeof( pStateMachine->doFunctionHandler.KeyEvent.stack) );
}

static void KeyPressEventGenerator_Enter_TimeCounter(S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  pStateMachine->runningState.TimeBaseEvent = E_KeyPressEventGenerator_TimeCounter;

  pStateMachine->doFunctionHandler.TimeCounter.threadHandle = KeyPressEventGenerator_LanchDoAction( KeyPressEventGenerator_DoAction_TimeCounter, pStateMachine, pStateMachine->doFunctionHandler.TimeCounter.stack, sizeof( pStateMachine->doFunctionHandler.TimeCounter.stack) );
}

static void KeyPressEventGenerator_Exit_KeyEvent(S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  pStateMachine->runningState.KeyBaseEvent = E_KeyPressEventGenerator_KeyEvent;

  KeyPressEventGenerator_HaltDoAction( pStateMachine->doFunctionHandler.KeyEvent.threadHandle );
  pStateMachine->doFunctionHandler.KeyEvent.threadHandle = 0;
}

static void KeyPressEventGenerator_Exit_TimeCounter(S_SM_KeyPressEventGenerator_t* pStateMachine )
{
  pStateMachine->runningState.TimeBaseEvent = E_KeyPressEventGenerator_TimeCounter;

  KeyPressEventGenerator_HaltDoAction( pStateMachine->doFunctionHandler.TimeCounter.threadHandle );
  pStateMachine->doFunctionHandler.TimeCounter.threadHandle = 0;
}

static pthread_t KeyPressEventGenerator_LanchDoAction( void *(*threadStart)(void *), S_SM_KeyPressEventGenerator_t* pStateMachine, void *stackAddr, size_t stackSize )
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

static void KeyPressEventGenerator_HaltDoAction( pthread_t thr )
{
  if ( thr != 0 && ! pthread_equal( thr, pthread_self( ) ) )
  {
    pthread_cancel( thr );
  }
}

/* End of KeyPressEventGenerator.c */
