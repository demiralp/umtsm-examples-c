/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-07-28 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
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

#include <Paroot.h>

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

S_SM_Paroot_t parabole;

void signal_handler( int sig )
{
  switch( sig )
  {
    case SIGINT:
    {
      Paroot_Deinitialize( &parabole );
      break;
    }
  }
}

int main( )
{
  // Initilaize entire the state machines */
  Paroot_Initialize( &parabole );

  /* Start entire the State Machines */
  Paroot_Start( &parabole );

  signal( SIGINT, signal_handler );

  while( Paroot_IsIn_Main_Region( &parabole ) )
  {
    sleep( 1 );
  }

  /* exit the application */
  printf( "Exited!\n" );

  Paroot_Deinitialize( &parabole );

  return EXIT_SUCCESS;
}
