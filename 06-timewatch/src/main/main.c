/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2025-04-05 GMT.
 * Copyright (C) 2023-2025 FEDEM (Fehmi Demiralp) <f.demiralp@gmail.com>.
 *
 * Released under the MIT License:
 *============================================================================*/

/*
Copyright (c) 2023-2025 Fedem (Fehmi Demiralp)

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

#include <Timewatch.h>
#include <Command.h>

#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <ncurses.h>

pthread_mutex_t blocker;

S_SM_Timewatch_t timewatch;
S_SM_Command_t command;

void signal_handler( int sig )
{
  switch( sig )
  {
    case SIGINT:
    {
      pthread_mutex_unlock( &blocker );
      break;
    }
  }
}

int main( )
{
  initscr( );

  noecho( );
  cbreak( );
  // keypad( stdscr, true );
  // nodelay( stdscr, true );
  // notimeout( stdscr, true );
  set_escdelay( 0 );
  // clrtobot();
  clear( );
  refresh( );

  Command_Initialize( &command );
  Timewatch_Initialize( &timewatch );

  /* Timewatch */

  /* Command */
  command.instanceData.timer= &timewatch;

  /* Start entire the State Machines */
  Command_Start( &command );
  Timewatch_Start( &timewatch );

  /* Allow entire the state machines run for  indefinite time until CTRL-C is pressed */
  pthread_mutex_lock( &blocker );

  signal( SIGINT, signal_handler );

  pthread_mutex_lock( &blocker );
  pthread_mutex_unlock( &blocker );

  /* exit the application */
  Timewatch_Deinitialize( &timewatch );
  Command_Deinitialize( &command );

  clear( );
  refresh( );

  endwin( );

  return EXIT_SUCCESS;
}
