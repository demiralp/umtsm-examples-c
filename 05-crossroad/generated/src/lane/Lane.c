/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-11-02 GMT
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

#include "Lane.h"
#include "Lane_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <stdbool.h>
#include <stddef.h>

static void Lane_Finalize_Main( S_SM_Lane_t* pStateMachine );
static void Lane_Finalize_Availability( S_SM_Lane_t* pStateMachine );
static void Lane_Finalize_Controlling( S_SM_Lane_t* pStateMachine );
static void Lane_Finalize_Status( S_SM_Lane_t* pStateMachine );

static void Lane_Terminate( S_SM_Lane_t* pStateMachine );
static void Lane_StoreEntireStates( S_SM_Lane_t* pStateMachine );

static void Lane_Init_Main( S_SM_Lane_t* pStateMachine );
static void Lane_Init_Availability( S_SM_Lane_t* pStateMachine );
static void Lane_Init_Uncontrolled( S_SM_Lane_t* pStateMachine );
static void Lane_Init_Status( S_SM_Lane_t* pStateMachine );

void Lane_Initialize( S_SM_Lane_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    memset( pStateMachine, 0, sizeof( *pStateMachine ) );

    Lane_DataType_Initialize( &pStateMachine->instanceData );

    pStateMachine->runningState.Main = E_Lane_init;
  }
}

void Lane_Deinitialize( S_SM_Lane_t* const pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    Lane_Terminate( pStateMachine );
    pStateMachine->runningState.Main = E_Lane_final;

    Lane_DataType_Deinitialize( &pStateMachine->instanceData );
  }
}

void Lane_Start( S_SM_Lane_t* pStateMachine )
{
  if ( pStateMachine != NULL && ! Lane_IsIn_Main_Region( pStateMachine ) )
  {
    pStateMachine->storedState.Availability = Lane_Load_Availability( &pStateMachine->instanceData );

    Lane_Init_Main( pStateMachine );
  }
}

bool Lane_IsIn_Main_Region( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.Main != E_Lane_init ) &&
                      ( pStateMachine->runningState.Main != E_Lane_final );

  return result;
}

bool Lane_IsIn_Availability_Region( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.Availability != E_Lane_Availability_init ) &&
                      ( pStateMachine->runningState.Availability != E_Lane_Availability_final ) &&
                      Lane_IsIn_Main_State( pStateMachine );

  return result;
}

bool Lane_IsIn_Controlling_Region( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.Controlling != E_Lane_Controlling_init ) &&
                      ( pStateMachine->runningState.Controlling != E_Lane_Controlling_final ) &&
                      Lane_IsIn_Main_State( pStateMachine );

  return result;
}

bool Lane_IsIn_Status_Region( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
                      ( pStateMachine->runningState.Status != E_Lane_Status_init ) &&
                      ( pStateMachine->runningState.Status != E_Lane_Status_final ) &&
                      Lane_IsIn_Main_State( pStateMachine );

  return result;
}

bool Lane_IsIn_Main_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Main_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Main == E_Lane_Main );

  return result;
}

bool Lane_IsIn_Available_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Availability_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Availability == E_Lane_Available );

  return result;
}

bool Lane_IsIn_Unavailable_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Availability_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Availability == E_Lane_Unavailable );

  return result;
}

bool Lane_IsIn_Unmanaged_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Controlling_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Controlling == E_Lane_Unmanaged );

  return result;
}

bool Lane_IsIn_Managed_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Controlling_Region( pStateMachine ) &&
    ( ( pStateMachine->runningState.Controlling == E_Lane_Managed ) || 
      ( pStateMachine->runningState.Controlling == E_Lane_Uncontrolled ) || 
      ( pStateMachine->runningState.Controlling == E_Lane_Controlled ) || 
      ( pStateMachine->runningState.Controlling == E_Lane_CheckAndGo ) || 
      ( pStateMachine->runningState.Controlling == E_Lane_StopAndCheck ) );

  return result;
}

bool Lane_IsIn_Uncontrolled_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Controlling_Region( pStateMachine ) &&
    ( ( pStateMachine->runningState.Controlling == E_Lane_Uncontrolled ) || 
      ( pStateMachine->runningState.Controlling == E_Lane_CheckAndGo ) || 
      ( pStateMachine->runningState.Controlling == E_Lane_StopAndCheck ) );

  return result;
}

bool Lane_IsIn_CheckAndGo_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Controlling_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Controlling == E_Lane_CheckAndGo );

  return result;
}

bool Lane_IsIn_StopAndCheck_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Controlling_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Controlling == E_Lane_StopAndCheck );

  return result;
}

bool Lane_IsIn_Controlled_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Controlling_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Controlling == E_Lane_Controlled );

  return result;
}

bool Lane_IsIn_Close_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Status_Region( pStateMachine ) &&
    ( ( pStateMachine->runningState.Status == E_Lane_Close ) || 
      ( pStateMachine->runningState.Status == E_Lane_Ready ) );

  return result;
}

bool Lane_IsIn_Ready_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Status_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Status == E_Lane_Ready );

  return result;
}

bool Lane_IsIn_Open_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Status_Region( pStateMachine ) &&
    ( ( pStateMachine->runningState.Status == E_Lane_Open ) || 
      ( pStateMachine->runningState.Status == E_Lane_PrepareToStop ) );

  return result;
}

bool Lane_IsIn_PrepareToStop_State( S_SM_Lane_t* const pStateMachine )
{
  bool const result = ( pStateMachine != NULL ) &&
    Lane_IsIn_Status_Region( pStateMachine ) &&
    ( pStateMachine->runningState.Status == E_Lane_PrepareToStop );

  return result;
}

S_SM_Lane_DataType_t* Lane_GetData( S_SM_Lane_t* const pStateMachine )
{
  S_SM_Lane_DataType_t* const pCustomData = ( pStateMachine != NULL ) ? &pStateMachine->instanceData : NULL;
  return pCustomData;
}

void Lane_Run_Allowed( S_SM_Lane_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;
    __attribute__( ( unused ) ) bool doneAvailability = false;

    if ( Lane_IsIn_Availability_Region( pStateMachine ) )
    {
      doneAvailability = true;

      if ( Lane_IsIn_Unavailable_State( pStateMachine ) )
      {
        pStateMachine->runningState.Availability = E_Lane_Available;
        pStateMachine->storedState.Availability = E_Lane_Available;
        Lane_Store_Availability( pStateMachine->storedState.Availability, &pStateMachine->instanceData );
      }
      else
      {
        doneAvailability = false;
      }
    }
  }
}

void Lane_Run_Close( S_SM_Lane_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;
    __attribute__( ( unused ) ) bool doneStatus = false;

    if ( Lane_IsIn_Status_Region( pStateMachine ) )
    {
      doneStatus = true;

      if ( Lane_IsIn_Open_State( pStateMachine ) )
      {
        if ( Lane_IsIn_PrepareToStop_State( pStateMachine ) )
        {
          pStateMachine->runningState.Status = E_Lane_Close;
        }
        else
        {
          pStateMachine->runningState.Status = E_Lane_Close;
        }
      }
      else
      {
        doneStatus = false;
      }
    }
  }
}

void Lane_Run_Disallowed( S_SM_Lane_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;
    __attribute__( ( unused ) ) bool doneAvailability = false;

    if ( Lane_IsIn_Availability_Region( pStateMachine ) )
    {
      doneAvailability = true;

      if ( Lane_IsIn_Available_State( pStateMachine ) )
      {
        pStateMachine->runningState.Availability = E_Lane_Unavailable;
        pStateMachine->storedState.Availability = E_Lane_Unavailable;
        Lane_Store_Availability( pStateMachine->storedState.Availability, &pStateMachine->instanceData );
      }
      else
      {
        doneAvailability = false;
      }
    }
  }
}

void Lane_Run_Open( S_SM_Lane_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;
    __attribute__( ( unused ) ) bool doneStatus = false;

    if ( Lane_IsIn_Status_Region( pStateMachine ) )
    {
      doneStatus = true;

      if ( Lane_IsIn_Close_State( pStateMachine ) )
      {
        if ( Lane_IsIn_Ready_State( pStateMachine ) )
        {
          pStateMachine->runningState.Status = E_Lane_Open;
        }
        else
        {
          pStateMachine->runningState.Status = E_Lane_Open;
        }
      }
      else
      {
        doneStatus = false;
      }
    }
  }
}

void Lane_Run_Prepare( S_SM_Lane_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;
    __attribute__( ( unused ) ) bool doneStatus = false;

    if ( Lane_IsIn_Status_Region( pStateMachine ) )
    {
      doneStatus = true;

      if ( Lane_IsIn_Close_State( pStateMachine ) )
      {
        if ( Lane_IsIn_Ready_State( pStateMachine ) )
        {
        }
        else
        {
          pStateMachine->runningState.Status = E_Lane_Ready;
        }
      }
      else if ( Lane_IsIn_Open_State( pStateMachine ) )
      {
        if ( Lane_IsIn_PrepareToStop_State( pStateMachine ) )
        {
        }
        else
        {
          pStateMachine->runningState.Status = E_Lane_PrepareToStop;
        }
      }
      else
      {
        doneStatus = false;
      }
    }
  }
}

void Lane_Run_StartControlling( S_SM_Lane_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;
    __attribute__( ( unused ) ) bool doneControlling = false;

    if ( Lane_IsIn_Controlling_Region( pStateMachine ) )
    {
      doneControlling = true;

      if ( Lane_IsIn_Unmanaged_State( pStateMachine ) )
      {
        pStateMachine->runningState.Controlling = E_Lane_Controlled;
      }

      if ( Lane_IsIn_Uncontrolled_State( pStateMachine ) )
      {
        if ( Lane_IsIn_CheckAndGo_State( pStateMachine ) )
        {
          pStateMachine->runningState.Controlling = E_Lane_Controlled;
        }
        else if ( Lane_IsIn_StopAndCheck_State( pStateMachine ) )
        {
          pStateMachine->runningState.Controlling = E_Lane_Controlled;
        }
        else
        {
          pStateMachine->runningState.Controlling = E_Lane_Controlled;
        }
      }
      else
      {
        doneControlling = false;
      }
    }
  }
}

void Lane_Run_StopControlling( S_SM_Lane_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;
    __attribute__( ( unused ) ) bool doneControlling = false;

    if ( Lane_IsIn_Controlling_Region( pStateMachine ) )
    {
      doneControlling = true;

      if ( Lane_IsIn_Unmanaged_State( pStateMachine ) )
      {
        Lane_Init_Uncontrolled( pStateMachine );
      }

      if ( Lane_IsIn_Controlled_State( pStateMachine ) )
      {
        Lane_Init_Uncontrolled( pStateMachine );
      }
      else
      {
        doneControlling = false;
      }
    }
  }
}

void Lane_Run_SystemDisabled( S_SM_Lane_t* pStateMachine )
{
  if ( pStateMachine != NULL )
  {
    __attribute__( ( unused ) ) bool doneMain = false;
    __attribute__( ( unused ) ) bool doneControlling = false;

    if ( Lane_IsIn_Controlling_Region( pStateMachine ) )
    {
      doneControlling = true;

      if ( Lane_IsIn_Managed_State( pStateMachine ) )
      {
        if ( Lane_IsIn_Uncontrolled_State( pStateMachine ) )
        {
          if ( Lane_IsIn_CheckAndGo_State( pStateMachine ) )
          {
            pStateMachine->runningState.Controlling = E_Lane_Unmanaged;
          }
          else if ( Lane_IsIn_StopAndCheck_State( pStateMachine ) )
          {
            pStateMachine->runningState.Controlling = E_Lane_Unmanaged;
          }
          else
          {
            pStateMachine->runningState.Controlling = E_Lane_Unmanaged;
          }
        }
        else if ( Lane_IsIn_Controlled_State( pStateMachine ) )
        {
          pStateMachine->runningState.Controlling = E_Lane_Unmanaged;
        }
        else
        {
          pStateMachine->runningState.Controlling = E_Lane_Unmanaged;
        }
      }
      else
      {
        doneControlling = false;
      }
    }
  }
}

static void Lane_Finalize_Main(S_SM_Lane_t* pStateMachine )
{
  if ( Lane_IsIn_Main_Region( pStateMachine ) )
  {
    pStateMachine->runningState.Main = E_Lane_final;
  }
}

static void Lane_Finalize_Availability(S_SM_Lane_t* pStateMachine )
{
  if ( Lane_IsIn_Availability_Region( pStateMachine ) )
  {
    pStateMachine->runningState.Availability = E_Lane_Availability_final;
  }
}

static void Lane_Finalize_Controlling(S_SM_Lane_t* pStateMachine )
{
  if ( Lane_IsIn_Controlling_Region( pStateMachine ) )
  {
    pStateMachine->runningState.Controlling = E_Lane_Controlling_final;
  }
}

static void Lane_Finalize_Status(S_SM_Lane_t* pStateMachine )
{
  if ( Lane_IsIn_Status_Region( pStateMachine ) )
  {
    pStateMachine->runningState.Status = E_Lane_Status_final;
  }
}

static void Lane_Terminate( S_SM_Lane_t* pStateMachine )
{
  Lane_StoreEntireStates( pStateMachine );
  Lane_Finalize_Main( pStateMachine );
}

static void Lane_StoreEntireStates( S_SM_Lane_t* pStateMachine )
{
  Lane_Store_Availability( pStateMachine->storedState.Availability, &pStateMachine->instanceData );
}

static void Lane_Init_Main( S_SM_Lane_t* pStateMachine )
{
  pStateMachine->runningState.Main = E_Lane_Main;
  Lane_Init_Availability( pStateMachine );
  Lane_Init_Status( pStateMachine );
  pStateMachine->runningState.Controlling = E_Lane_Unmanaged;
}

static void Lane_Init_Availability( S_SM_Lane_t* pStateMachine )
{
  // started by history stored
  switch ( pStateMachine->storedState.Availability )
  {
    case E_Lane_Available:
    {
      pStateMachine->runningState.Availability = E_Lane_Available;
      break;
    }
    case E_Lane_Unavailable:
    {
      pStateMachine->runningState.Availability = E_Lane_Unavailable;
      break;
    }
    default:
    {
      pStateMachine->runningState.Availability = E_Lane_Available;
      pStateMachine->storedState.Availability = E_Lane_Available;
      Lane_Store_Availability( pStateMachine->storedState.Availability, &pStateMachine->instanceData );
      break;
    }
  }
}

static void Lane_Init_Uncontrolled( S_SM_Lane_t* pStateMachine )
{
  if ( Lane_IsCheckAndGo( pStateMachine, &pStateMachine->instanceData ) )
  {
    pStateMachine->runningState.Controlling = E_Lane_CheckAndGo;
  }
  else
  {
    pStateMachine->runningState.Controlling = E_Lane_StopAndCheck;
  }
}

static void Lane_Init_Status( S_SM_Lane_t* pStateMachine )
{
  pStateMachine->runningState.Status = E_Lane_Close;
}

/* End of Lane.c */