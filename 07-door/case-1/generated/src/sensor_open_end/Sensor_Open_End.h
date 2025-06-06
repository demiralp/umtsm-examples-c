/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2025-05-29 GMT
 *  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  This file is generated by UMTSM using the code generator `CGen`
 *
 *  !!! It is highly recommended that DO NOT EDIT THIS GENERATED FILE !!!
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

#ifndef Sensor_Open_End_h__INCLUDED
#define Sensor_Open_End_h__INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
#include <stdbool.h>
#include <stdint.h>

#include <pthread.h>

#include <Sensor_Open_End_DataType.h>

typedef enum E_Sensor_Open_End_Main_States
{
  E_Sensor_Open_End_init,
  E_Sensor_Open_End_Main,
  E_Sensor_Open_End_Idle,
  E_Sensor_Open_End_Check,
  E_Sensor_Open_End_final
} E_Sensor_Open_End_Main_States_t;

typedef struct S_SM_Sensor_Open_End
{
  pthread_mutex_t guard;
  struct
  {
    E_Sensor_Open_End_Main_States_t Main;
  } runningState;
  struct
  {
    union
    {
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } Idle;
      struct
      {
        pthread_t threadHandle;
        uint8_t stack[4224U];
      } Check;
    };
  } doFunctionHandler;
  S_SM_Sensor_Open_End_DataType_t instanceData;
} S_SM_Sensor_Open_End_t;

void Sensor_Open_End_Initialize( S_SM_Sensor_Open_End_t* const pStateMachine );
void Sensor_Open_End_Deinitialize( S_SM_Sensor_Open_End_t* const pStateMachine );

void Sensor_Open_End_Start( S_SM_Sensor_Open_End_t* pStateMachine );

bool Sensor_Open_End_IsIn_Main_Region( S_SM_Sensor_Open_End_t* const pStateMachine );

bool Sensor_Open_End_IsIn_Main_State( S_SM_Sensor_Open_End_t* const pStateMachine );
bool Sensor_Open_End_IsIn_Idle_State( S_SM_Sensor_Open_End_t* const pStateMachine );
bool Sensor_Open_End_IsIn_Check_State( S_SM_Sensor_Open_End_t* const pStateMachine );

S_SM_Sensor_Open_End_DataType_t* Sensor_Open_End_GetData( S_SM_Sensor_Open_End_t* const pStateMachine );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* Sensor_Open_End_h__INCLUDED */

/* End of Sensor_Open_End.h */
