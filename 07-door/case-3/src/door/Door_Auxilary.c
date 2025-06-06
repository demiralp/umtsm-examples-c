/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2025-05-29 GMT
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

#include "Door_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

#include <Engine.h>

#define KEEP_DOOR_OPEN ( 5 )

/* The implementation of the actions */
void Door_engineRunACCW(
  __attribute__( ( unused ) ) S_SM_Door_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t* const pOutputData )
{
  time( &pOutputData->doorActionTimeStart  );
  Engine_Run_runACCW( pOutputData->pEngine );
} /* End of action function: Door_engineRunACCW */

void Door_engineRunCCW(
  __attribute__( ( unused ) ) S_SM_Door_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t* const pOutputData )
{
  time( &pOutputData->doorActionTimeStart );
  Engine_Run_runCCW( pOutputData->pEngine );
} /* End of action function: Door_engineRunCCW */

void Door_engineStop(
  __attribute__( ( unused ) ) S_SM_Door_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t* const pOutputData )
{
  Engine_Run_stop( pOutputData->pEngine );
} /* End of action function: Door_engineStop */

void Door_resetWaitingTime(
  __attribute__( ( unused ) ) S_SM_Door_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t* const pOutputData )
{
  time( &pOutputData->waitUntil  );
  pOutputData->waitUntil += KEEP_DOOR_OPEN;
} /* End of action function: Door_resetWaitingTime */

void Door_wait(
  __attribute__( ( unused ) ) S_SM_Door_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t* const pOutputData )
{
  do
  {
    time_t now;
    time( &now );
    if( now >= pOutputData->waitUntil )
    {
      break;
    }
    useconds_t usec = 1000000 * ( pOutputData->waitUntil - now );
    usleep( usec );
  } while( true );
} /* End of action function: Door_wait */

/* The implementation of the Persistency Functions */
void Door_Store_Deep_Main(
  __attribute__( ( unused ) ) E_Door_Main_States_t state,
  __attribute__( ( unused ) ) S_SM_Door_DataType_t* const pInstance )
{
  static char const* const regfile = "door";
  char const* folder               = getenv( "TMPDIR" );
  char path[ 256 ];
  if( folder == 0 )
  {
    folder = "/tmp";
  }

  strcpy( path, folder );
  strcat( path, "/" );
  strcat( path, regfile );
  strcat( path, "-" );
  strcat( path, pInstance->id );
  strcat( path, ".bin" );

  FILE* fd = fopen( path, "wb" );
  if( fd != NULL )
  {
    uint16_t sdata = (uint16_t)state;
    fwrite( &sdata, sizeof( sdata ), 1, fd );
    fclose( fd );
  }
} /* End of action function: Door_Store_Deep_Main */

E_Door_Main_States_t Door_Load_Deep_Main(
  __attribute__( ( unused ) ) S_SM_Door_DataType_t* const pInstance )
{
  E_Door_Main_States_t result = E_Door_init;

  static char const* const regfile = "door";
  char const* folder               = getenv( "TMPDIR" );
  char path[ 256 ];
  if( folder == 0 )
  {
    folder = "/tmp";
  }

  strcpy( path, folder );
  strcat( path, "/" );
  strcat( path, regfile );
  strcat( path, "-" );
  strcat( path, pInstance->id );
  strcat( path, ".bin" );

  FILE* fd = fopen( path, "rb" );
  if( fd != NULL )
  {
    uint16_t sdata;
    fread( &sdata, sizeof( sdata ), 1, fd );
    result = (E_Door_Main_States_t)sdata;
    fclose( fd );
  }

  return result;
} /* End of loader function: Door_Load_Deep_Main */

/* End of Door_Auxilary.c */
