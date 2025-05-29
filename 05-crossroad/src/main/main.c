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

#include <Crossroad.h>
#include <Dashboard.h>
#include <ExecutionDirector.h>
#include <Monitor.h>

#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <ncurses.h>

pthread_mutex_t blocker;

S_SM_Crossroad_t crossroad;
S_SM_ExecutionDirector_t executor;
S_SM_Dashboard_t dashboard;
S_SM_Monitor_t monitor;

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

  if( has_colors( ) == FALSE )
  {
    endwin( );
    printf( "Your terminal does not support color\n" );
    return EXIT_FAILURE;
  }

  start_color( );
  init_pair( 1, COLOR_BLUE, 0 );
  init_pair( 2, COLOR_MAGENTA, 0 );

  init_pair( 3, 0, COLOR_RED );
  init_pair( 4, 0, COLOR_YELLOW );
  init_pair( 5, 0, COLOR_GREEN );
  init_pair( 6, 0, 0 );

  init_pair( 7, COLOR_YELLOW, 0 );
  init_pair( 8, COLOR_GREEN, 0 );

  noecho( );
  cbreak( );
  // keypad( stdscr, true );
  // nodelay( stdscr, true );
  // notimeout( stdscr, true );
  set_escdelay( 0 );
  // clrtobot();
  clear( );
  refresh( );

  /* Initilaize entire the state machines */
  Monitor_Initialize( &monitor );
  Dashboard_Initialize( &dashboard );
  ExecutionDirector_Initialize( &executor );
  Crossroad_Initialize( &crossroad );

  /* Configure Monitor */
  S_SM_Monitor_DataType_t* pMonitorData = Monitor_GetData( &monitor );
  pMonitorData->pCrossroad              = &crossroad;
  pMonitorData->pExecutionDirector      = &executor;

  /* Configure Dashboard */
  S_SM_Dashboard_DataType_t* pDashboardData = Dashboard_GetData( &dashboard );
  pDashboardData->pMonitor                  = &monitor;
  pDashboardData->pExecutionDirector        = &executor;
  pDashboardData->pCrossroad                = &crossroad;

  /* Configure ExecutionDirector */
  S_SM_ExecutionDirector_DataType_t* pExecutor = ExecutionDirector_GetData( &executor );
  pExecutor->pCrossroad                        = &crossroad;
  pExecutor->pMonitor                          = &monitor;

  /* Configure Crossroad */
  /* Configure Crossroad.Lane1 */
  S_SM_Lane_DataType_t* pLane1 = Crossroad_GetSMData_Lane1( &crossroad );
  strcpy( pLane1->Id, "1" );
  pLane1->UncontrolMode = E_STOP_AND_CHECK;
  /* Configure Crossroad.Lane2 */
  S_SM_Lane_DataType_t* pLane2 = Crossroad_GetSMData_Lane2( &crossroad );
  strcpy( pLane2->Id, "2" );
  pLane2->UncontrolMode = E_STOP_AND_CHECK;
  /* Configure Crossroad.Lane3 */
  S_SM_Lane_DataType_t* pLane3 = Crossroad_GetSMData_Lane3( &crossroad );
  strcpy( pLane3->Id, "3" );
  pLane3->UncontrolMode = E_CHECK;
  /* Configure Crossroad.Lane4 */
  S_SM_Lane_DataType_t* pLane4 = Crossroad_GetSMData_Lane4( &crossroad );
  strcpy( pLane4->Id, "4" );
  pLane4->UncontrolMode = E_CHECK;
  /* Configure Crossroad.PedestrianLanes */
  S_SM_Lane_DataType_t* pPedestrianLanes = Crossroad_GetSMData_PedestrianLanes( &crossroad );
  strcpy( pPedestrianLanes->Id, "P" );
  /* Configure Crossroad.TraficLight1 */
  S_SM_TrafficLight_DataType_t* pTrafficLight1 = Crossroad_GetSMData_TrafficLight1( &crossroad );
  pTrafficLight1->pLane                        = Crossroad_GetSubSM_Lane1( &crossroad );
  pTrafficLight1->pMonitor                     = &monitor;
  pTrafficLight1->pExecutionDirector           = &executor;
  /* Configure Crossroad.TraficLight2 */
  S_SM_TrafficLight_DataType_t* pTrafficLight2 = Crossroad_GetSMData_TrafficLight2( &crossroad );
  pTrafficLight2->pLane                        = Crossroad_GetSubSM_Lane2( &crossroad );
  pTrafficLight2->pMonitor                     = &monitor;
  pTrafficLight2->pExecutionDirector           = &executor;
  /* Configure Crossroad.TraficLight3 */
  S_SM_TrafficLight_DataType_t* pTrafficLight3 = Crossroad_GetSMData_TrafficLight3( &crossroad );
  pTrafficLight3->pLane                        = Crossroad_GetSubSM_Lane3( &crossroad );
  pTrafficLight3->pMonitor                     = &monitor;
  pTrafficLight3->pExecutionDirector           = &executor;
  /* Configure Crossroad.TraficLight4 */
  S_SM_TrafficLight_DataType_t* pTrafficLight4 = Crossroad_GetSMData_TrafficLight4( &crossroad );
  pTrafficLight4->pLane                        = Crossroad_GetSubSM_Lane4( &crossroad );
  pTrafficLight4->pMonitor                     = &monitor;
  pTrafficLight4->pExecutionDirector           = &executor;
  /* Configure Crossroad.PedestrianLights */
  S_SM_PedestrianLights_DataType_t* pPedestrianLights = Crossroad_GetSMData_PedestrianLights( &crossroad );
  pPedestrianLights->pExecutionDirector               = &executor;
  pPedestrianLights->pMonitor                         = &monitor;
  pPedestrianLights->pCrossroad                       = &crossroad;

  /* Start entire the State Machines */
  Monitor_Start( &monitor );
  Dashboard_Start( &dashboard );
  ExecutionDirector_Start( &executor );
  Crossroad_Start( &crossroad );

  /* Allow entire the state machines run for  indefinite time until CTRL-C is pressed */
  pthread_mutex_lock( &blocker );

  signal( SIGINT, signal_handler );

  pthread_mutex_lock( &blocker );
  pthread_mutex_unlock( &blocker );

  /* exit the application */
  clear( );
  printw( "Exited!\n" );
  refresh( );

  ExecutionDirector_Deinitialize( &executor );
  Crossroad_Deinitialize( &crossroad );
  Monitor_Deinitialize( &monitor );

  endwin( );

  return EXIT_SUCCESS;
}
