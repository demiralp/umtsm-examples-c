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

#include "Dashboard_Auxilary.h"

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

#include <Door.h>
#include <Button.h>
#include <Engine.h>
#include <Sensor_Close_End.h>
#include <Sensor_Open_End.h>

static void PrintHelpLine( char const* const key, char const* const summary );
static void PrintHelp(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstanceData );

  /* The implementation of the guards */
bool Dashboard_IsKey_B(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstance )
{
  bool const result = toupper( pInstance->LastInputKey ) == 'B';
  return result;
} /* End of guard function: Dashboard_IsKey_B */

/* The implementation of the actions */
void Dashboard_ButtonPress(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  Button_Run_Pressed( pOutputData->pButton );
} /* End of action function: Dashboard_ButtonPress */

void Dashboard_DisplayDoorStatus(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  while( true )
  {
    usleep( 200000 );

    clear( );

    /* Door Working Mode */
    {
      char const* const wmode = "Manual";

      attron( COLOR_PAIR( 1 ) );
      printw( "%-19s :", "Door Working Mode" );
      attroff( COLOR_PAIR( 1 ) );

      attron( COLOR_PAIR( 2 ) );
      printw( " %s\n", wmode );
      attroff( COLOR_PAIR( 2 ) );
    }

    /* Door status */
    {
      char* st = NULL;
      int color= 0;

      if( Door_IsIn_Open_State( pOutputData->pDoor ) )
      {
        st = "Open";
        color= 5; // GREEN
      }
      else if( Door_IsIn_Close_State( pOutputData->pDoor ) )
      {
        st = "Closed";
        color= 3; // RED
      }
      else if( Door_IsIn_Opening_State( pOutputData->pDoor ) )
      {
        st = "Opening ...";
        color = 6; // WHITE 
      }
      else if( Door_IsIn_Closing_State( pOutputData->pDoor ) )
      {
        st = "Closing ...";
        color = 4; // YELLOW
      }

      attron( COLOR_PAIR( 1 ) );
      printw( "%-19s :", "Door Status" );
      attroff( COLOR_PAIR( 1 ) );

      attron( COLOR_PAIR( color ) );
      printw( " %s\n", st );
      attroff( COLOR_PAIR( color ) );
    }

    /* Engine Mode */
    {
      char* engmode = NULL;

      if( Engine_IsIn_Idle_State( pOutputData->pEngine ) )
      {
        engmode = "Idle";
      }
      else if( Engine_IsIn_CCW_State( pOutputData->pEngine ) )
      {
        engmode = "CCW";
      }
      else if( Engine_IsIn_ACCW_State( pOutputData->pEngine ) )
      {
        engmode = "Anti CCW";
      }

      attron( COLOR_PAIR( 1 ) );
      printw( "%-19s :", "Engine Working Mode" );
      attroff( COLOR_PAIR( 1 ) );

      attron( COLOR_PAIR( 2 ) );
      printw( " %s\n", engmode );
      attroff( COLOR_PAIR( 2 ) );
    }

    /* Sensor Close End */
    {
      char* sclose = NULL;

      if( Sensor_Close_End_IsIn_Idle_State( pOutputData->pCloseEnd ) )
      {
        sclose = "Idle";
      }
      else if( Sensor_Close_End_IsIn_Check_State( pOutputData->pCloseEnd ) )
      {
        sclose = "Check";
      }

      attron( COLOR_PAIR( 1 ) );
      printw( "%-19s :", "Sensor Close End" );
      attroff( COLOR_PAIR( 1 ) );

      attron( COLOR_PAIR( 2 ) );
      printw( " %s\n", sclose );
      attroff( COLOR_PAIR( 2 ) );
    }

    /* Sensor Open End */
    {
      char* sopen = NULL;

      if( Sensor_Open_End_IsIn_Idle_State( pOutputData->pOpenEnd ) )
      {
        sopen = "Idle";
      }
      else if( Sensor_Open_End_IsIn_Check_State( pOutputData->pOpenEnd ) )
      {
        sopen = "Check";
      }

      attron( COLOR_PAIR( 1 ) );
      printw( "%-19s :", "Sensor Open End" );
      attroff( COLOR_PAIR( 1 ) );

      attron( COLOR_PAIR( 2 ) );
      printw( " %s\n", sopen );
      attroff( COLOR_PAIR( 2 ) );
    }

    PrintHelp( smInfo, pInputData );
    refresh( );
  }
} /* End of action function: Dashboard_DisplayDoorStatus */

void Dashboard_ReadCommand(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInputData,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t* const pOutputData )
{
  static char const* const keyChar = "Bb";
  bool okay                        = false;
  int ch;

  do
  {
    ch   = wgetch( stdscr );
    okay = strchr( keyChar, ch ) != NULL;
  } while( ! okay );

  pOutputData->LastInputKey = ch;
} /* End of action function: Dashboard_ReadCommand */

static void PrintHelpLine( char const* const key, char const* const summary )
{
  attron( COLOR_PAIR( 7 ) );
  printw( "%-6s :", key );
  attroff( COLOR_PAIR( 7 ) );

  attron( COLOR_PAIR( 8 ) );
  printw( " %s\n", summary );
  attroff( COLOR_PAIR( 8 ) );
}

static void PrintHelp(
  __attribute__( ( unused ) ) S_SM_Dashboard_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Dashboard_DataType_t const* const pInstanceData )
{
  printw( "Keys for controlling the door\n" );

  PrintHelpLine( "B", "Button press" );

  PrintHelpLine( "Ctrl+C", "Terminate immediately" );
}

/* End of Dashboard_Auxilary.c */
