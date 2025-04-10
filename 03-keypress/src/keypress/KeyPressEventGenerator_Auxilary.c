/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2024-08-04 GMT.
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

#include "KeyPressEventGenerator_Auxilary.h"
#include "KeyPress.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include <ncurses.h>

/* The implementation of the actions */
void KeyPressEventGenerator_ReadKey(
  __attribute__( ( unused ) ) S_SM_KeyPressEventGenerator_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPressEventGenerator_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPressEventGenerator_DataType_t * const pOutputData )
{
  char prev= 0;

  while( true )
  {
    int c = wgetch(stdscr);

    clrtoeol();
    refresh();

    switch ( c )
    {
      case 'A':
      [[fallthrough]];
      case 'a':
      {
        KeyPress_Run_keyA( pInputData->sm_keypress );
        break;
      }
      case 'B':
      [[fallthrough]];
      case 'b':
      {
        KeyPress_Run_keyB( pInputData->sm_keypress );
        break;
      }
      case 'C':
      [[fallthrough]];
      case 'c':
      {
        KeyPress_Run_keyC( pInputData->sm_keypress );
        break;
      }
      case 'R':
      [[fallthrough]];
      case 'r':
      {
        KeyPress_Run_space( pInputData->sm_keypress );
        break;
      }
      case '1':
      {
        KeyPress_Run_key1( pInputData->sm_keypress );
        break;
      }
      case '2':
      {
        KeyPress_Run_key2( pInputData->sm_keypress );
        break;
      }
      case '3':
      {
        KeyPress_Run_key3( pInputData->sm_keypress );
        break;
      }
      case '4':
      {
        KeyPress_Run_key4( pInputData->sm_keypress );
        break;
      }
      case '5':
      {
        KeyPress_Run_key5( pInputData->sm_keypress );
        break;
      }
      case '6':
      {
        KeyPress_Run_key6( pInputData->sm_keypress );
        break;
      }
      case '7':
      {
        KeyPress_Run_key7( pInputData->sm_keypress );
        break;
      }
      case '8':
      {
        KeyPress_Run_key8( pInputData->sm_keypress );
        break;
      }
      case '9':
      {
        KeyPress_Run_key9( pInputData->sm_keypress );
        break;
      }
      case KEY_BACKSPACE:
      [[fallthrough]];
      case KEY_DC:
      {
        KeyPress_Run_keyDelete( pInputData->sm_keypress );
        break;
      }
      case ' ':
      {
        KeyPress_Run_space( pInputData->sm_keypress );
        break;
      }
      case KEY_F(1):
      {
        KeyPress_Run_keyF1( pInputData->sm_keypress );
        break;
      }
      case KEY_F(2):
      {
        KeyPress_Run_keyF2( pInputData->sm_keypress );
        break;
      }
      case KEY_F(12):
      {
        printw("   F12");
        KeyPress_Run_keyF12( pInputData->sm_keypress );
        break;
      }
      default:
      {
        prev= 0;
        break;
      }
    }
  }
} /* End of action function: KeyPressEventGenerator_ReadKey */

void KeyPressEventGenerator_TimeBaseEventGenerator(
  __attribute__( ( unused ) ) S_SM_KeyPressEventGenerator_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_KeyPressEventGenerator_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_KeyPressEventGenerator_DataType_t * const pOutputData )
{
  clock_t start, end;
  double duration;

  while(true)
  {
    start = clock();
    KeyPress_Run_clock4log(pInputData->sm_keypress);
    end = clock();
    duration= 1000000.0 * (end-start) / CLOCKS_PER_SEC;
    usleep(20000-duration);
  }
} /* End of action function: KeyPressEventGenerator_TimeBaseEventGenerator */

/* End of KeyPressEventGenerator_Auxilary.c */
