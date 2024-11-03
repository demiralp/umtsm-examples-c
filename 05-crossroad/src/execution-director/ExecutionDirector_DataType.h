/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2024-09-09 GMT.
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

#ifndef ExecutionDirector_DataType_h__INCLUDED
#define ExecutionDirector_DataType_h__INCLUDED

#include <stdbool.h>
#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

  typedef enum E_ControlMode
  {
    PERSISTENT_CONTROL_MODE,
    CONTROLLED,
    UNCONTROLLED
  } E_ControlMode_t;

  typedef enum E_Lane_Command
  {
    E_CMD_NOPE,
    E_CMD_DISABLE_LANE,
    E_CMD_ENABLE_LANE
  } E_Lane_Command_t;

  typedef struct S_SM_Crossroad S_SM_Crossroad_t;
  typedef struct S_SM_Monitor S_SM_Monitor_t;

  typedef struct S_SM_ExecutionDirector_DataType
  {
      E_ControlMode_t ControlMode;
      time_t StartSwitchingTime;
      bool LaneClosingCompleted;
      S_SM_Crossroad_t* pCrossroad;
      S_SM_Monitor_t* pMonitor;
      int LaneRequested;
      int NextLane;
      E_Lane_Command_t LaneCmd1;
      E_Lane_Command_t LaneCmd2;
      E_Lane_Command_t LaneCmd3;
      E_Lane_Command_t LaneCmd4;
  } S_SM_ExecutionDirector_DataType_t;

  void ExecutionDirector_DataType_Initialize( S_SM_ExecutionDirector_DataType_t* const instance );
  void ExecutionDirector_DataType_Deinitialize( S_SM_ExecutionDirector_DataType_t* const instance );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ExecutionDirector_DataType_h__INCLUDED */

/* End of ExecutionDirector_DataType.h */
