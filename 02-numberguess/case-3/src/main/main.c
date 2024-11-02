/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2024-07-28 GMT.
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

/**********************************************/
/*               CASE 3                       */
/**********************************************/

#include <NumberGuess.h>

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

S_SM_NumberGuess_t numberguess;

void signal_handler( int sig )
{
  switch( sig )
  {
    case SIGINT:
    {
      NumberGuess_Run_abort( &numberguess );
      break;
    }
    case SIGUSR1:
    {
      NumberGuess_Run_show( &numberguess );
      break;
    }
    case SIGUSR2:
    {
      NumberGuess_Run_newgame( &numberguess );
      break;
    }
  }
}

int main( )
{
  NumberGuess_Initialize( &numberguess );
  NumberGuess_Start( &numberguess );

  signal( SIGINT, signal_handler );
  signal( SIGUSR1, signal_handler );
  signal( SIGUSR2, signal_handler );

  while( NumberGuess_IsIn_Main_Region( &numberguess ) )
  {
    sleep( 1 );
    NumberGuess_Run_clock1sec( &numberguess );
  }

  return EXIT_SUCCESS;
}