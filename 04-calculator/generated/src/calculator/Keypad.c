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

#include "Keypad.h"
#include "Keypad_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static void Keypad_Finalize_Main( S_SM_Keypad_t* pStateMachine );

static void Keypad_Terminate( S_SM_Keypad_t* pStateMachine );

static void* Keypad_DoAction_Main( void* statemachinePtr );

static void Keypad_Enter_Main( S_SM_Keypad_t* pStateMachine );

static void Keypad_Exit_Main( S_SM_Keypad_t* pStateMachine );


static pthread_t Keypad_LanchDoAction( void *(*threadStart)(void *), S_SM_Keypad_t* pStateMachine, void *stackAddr, size_t stackSize );
static void Keypad_HaltDoAction( pthread_t thr );

void Keypad_Initialize( S_SM_Keypad_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    memset( pStateMachine, 0, sizeof( *pStateMachine ) );

    pthread_mutexattr_t attr;
    pthread_mutexattr_init( &attr );
    pthread_mutex_init( &pStateMachine->guard, &attr );

    pthread_mutex_lock( &pStateMachine->guard );

    Keypad_DataType_Initialize( &pStateMachine->instanceData );

    pStateMachine->runningState.Main = E_Keypad_init;

    pthread_mutex_unlock( &pStateMachine->guard );
    pthread_mutexattr_destroy( &attr );
  }
}

void Keypad_Deinitialize( S_SM_Keypad_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    pthread_mutex_lock( &pStateMachine->guard );

    Keypad_Terminate( pStateMachine );
    pStateMachine->runningState.Main = E_Keypad_final;

    Keypad_DataType_Deinitialize( &pStateMachine->instanceData );

    pthread_mutex_unlock( &pStateMachine->guard );
    pthread_mutex_destroy( &pStateMachine->guard );
  }
}

void Keypad_Start( S_SM_Keypad_t* pStateMachine )
{
  if ( pStateMachine != NULL && ! Keypad_IsIn_Main_Region( pStateMachine ) )
  {
    pthread_mutex_lock( &pStateMachine->guard );

    Keypad_Enter_Main( pStateMachine );
    pStateMachine->runningState.Main = E_Keypad_Main;

    pthread_mutex_unlock( &pStateMachine->guard );
  }
}

bool Keypad_IsIn_Main_Region( S_SM_Keypad_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.Main != E_Keypad_init ) &&
                      ( pStateMachine->runningState.Main != E_Keypad_final );

  return result;
}

bool Keypad_IsIn_Main_State( S_SM_Keypad_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Keypad_IsIn_Main_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Main == E_Keypad_Main );

  return result;
}

S_SM_Keypad_DataType_t* Keypad_GetData( S_SM_Keypad_t* const pStateMachine )
{
  S_SM_Keypad_DataType_t* const pCustomData = ( pStateMachine != NULL ) ? &pStateMachine->instanceData : NULL;
  return pCustomData;
}

void Keypad_Run_Notify( S_SM_Keypad_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;

    pthread_mutex_lock( &pStateMachine->guard );

    if ( Keypad_IsIn_Main_State( pStateMachine ) )
    {
      if ( Keypad_IsReset( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyReset( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsClear( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyClear( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsBackspace( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyBackspce( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsDigit( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyDigit( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsDot( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyDot( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsExponent( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyExponent( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsPlus( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyPlus( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsMinus( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyMinus( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsMultiplay( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyMultiplay( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsDivisor( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyDivisor( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsEnter( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifyEnter( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else if ( Keypad_IsSignature( pStateMachine, &pStateMachine->instanceData ) )
      {
        Keypad_NotifySignatureChange( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );
      }
      else
      {
        /* left blank. the else block at the end is required by MISRA */
      }
    }

    pthread_mutex_unlock( &pStateMachine->guard );
  }
}

static void Keypad_Finalize_Main(S_SM_Keypad_t* pStateMachine )
{
  if ( Keypad_IsIn_Main_Region( pStateMachine ) )
  {
    pStateMachine->runningState.Main = E_Keypad_final;
  }
}

static void Keypad_Terminate( S_SM_Keypad_t* pStateMachine )
{
  Keypad_Finalize_Main( pStateMachine );
}

static void* Keypad_DoAction_Main( void* statemachinePtr )
{
  S_SM_Keypad_t* pStateMachine = (S_SM_Keypad_t*)statemachinePtr;

  Keypad_ReadKey( pStateMachine, &pStateMachine->instanceData, &pStateMachine->instanceData );

  pStateMachine->doFunctionHandler.Main.threadHandle = 0;

  return NULL;
}

static void Keypad_Enter_Main(S_SM_Keypad_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Keypad_Main;

  pStateMachine->doFunctionHandler.Main.threadHandle = Keypad_LanchDoAction( Keypad_DoAction_Main, pStateMachine, pStateMachine->doFunctionHandler.Main.stack, sizeof( pStateMachine->doFunctionHandler.Main.stack) );
}

static void Keypad_Exit_Main(S_SM_Keypad_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Keypad_Main;

  Keypad_HaltDoAction( pStateMachine->doFunctionHandler.Main.threadHandle );
  pStateMachine->doFunctionHandler.Main.threadHandle = 0;
}

static pthread_t Keypad_LanchDoAction( void *(*threadStart)(void *), S_SM_Keypad_t* pStateMachine, void *stackAddr, size_t stackSize )
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

static void Keypad_HaltDoAction( pthread_t thr )
{
  if ( thr != 0 && ! pthread_equal( thr, pthread_self( ) ) )
  {
    pthread_cancel( thr );
  }
}

/* End of Keypad.c */
