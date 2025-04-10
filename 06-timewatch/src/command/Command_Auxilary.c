/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2025-04-05 GMT
 *  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  Released under the MIT License
 *  ============================================================================
 */

/*
 *  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
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

#include "Command_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include <ncurses.h>

#include <Timewatch.h>

/* The implementation of the guards */
bool Command_isKeyHPressed(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInstance )
{
  bool const result = (pInstance->key == 'h' || pInstance->key == 'H');
  return result;
} /* End of guard function: Command_isKeyHPressed */

bool Command_isKeyPPressed(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInstance )
{
  bool const result = (pInstance->key == 'p' || pInstance->key == 'P');
  return result;
} /* End of guard function: Command_isKeyPPressed */

bool Command_isKeyQPressed(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInstance )
{
  bool const result = (pInstance->key == 'q' || pInstance->key == 'Q');
  return result;
} /* End of guard function: Command_isKeyQPressed */

bool Command_isKeyRPressed(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInstance )
{
  bool const result = (pInstance->key == 'r' || pInstance->key == 'R');
  return result;
} /* End of guard function: Command_isKeyRPressed */

bool Command_isKeySPressed(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInstance )
{
  bool const result = (pInstance->key == 's' || pInstance->key == 'S');
  return result;
} /* End of guard function: Command_isKeySPressed */

bool Command_isKeyXPressed(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInstance )
{
  bool const result = (pInstance->key == 'x' || pInstance->key == 'X');
  return result;
} /* End of guard function: Command_isKeyXPressed */

bool Command_isKeyZPressed(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInstance )
{
  bool const result = (pInstance->key == 'z' || pInstance->key == 'Z');
  return result;
} /* End of guard function: Command_isKeyZPressed */

bool Command_isSpacePressed(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInstance )
{
  bool const result = (pInstance->key == ' ');
  return result;
} /* End of guard function: Command_isSpacePressed */

/* The implementation of the actions */
void Command_ReadKey(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t * const pOutputData )
{
  pOutputData->key= wgetch(stdscr);
} /* End of action function: Command_ReadKey */

void Command_SendAbortEvent(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t * const pOutputData )
{
  Timewatch_Run_abort( pInputData->timer );
} /* End of action function: Command_SendAbortEvent */

void Command_SendHelpEvent(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t * const pOutputData )
{
  Timewatch_Run_help( pInputData->timer );
} /* End of action function: Command_SendHelpEvent */

void Command_SendPauseEvent(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t * const pOutputData )
{
  Timewatch_Run_pause( pInputData->timer );
} /* End of action function: Command_SendPauseEvent */

void Command_SendPrintLapsEvent(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t * const pOutputData )
{
  Timewatch_Run_print( pInputData->timer );
} /* End of action function: Command_SendPrintLapsEvent */

void Command_SendRestartEvent(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t * const pOutputData )
{
  Timewatch_Run_restart( pInputData->timer );
} /* End of action function: Command_SendRestartEvent */

void Command_SendResumeEvent(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t * const pOutputData )
{
  Timewatch_Run_resume( pInputData->timer );
} /* End of action function: Command_SendResumeEvent */

void Command_SendStartEvent(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t * const pOutputData )
{
  Timewatch_Run_start( pInputData->timer );
} /* End of action function: Command_SendStartEvent */

void Command_SendStopEvent(
  __attribute__( ( unused ) ) S_SM_Command_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Command_DataType_t * const pOutputData )
{
  Timewatch_Run_stop( pInputData->timer );
} /* End of action function: Command_SendStopEvent */

/* End of Command_Auxilary.c */
