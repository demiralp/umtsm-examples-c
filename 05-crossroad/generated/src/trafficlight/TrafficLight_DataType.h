/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2025-06-03 GMT
 *  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  This file is generated by UMTSM using the code generator `CGen`
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

#ifndef TrafficLight_DataType_h__INCLUDED
#define TrafficLight_DataType_h__INCLUDED

#include <TrafficLight_UserType.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
typedef struct S_SM_Lane S_SM_Lane_t;
typedef struct S_SM_Monitor S_SM_Monitor_t;
typedef struct S_SM_ExecutionDirector S_SM_ExecutionDirector_t;

typedef struct S_SM_TrafficLight_DataType
{
  S_SM_Lane_t *pLane;
  S_SM_Monitor_t *pMonitor;
  S_SM_ExecutionDirector_t *pExecutionDirector;
} S_SM_TrafficLight_DataType_t;

void TrafficLight_DataType_Initialize( S_SM_TrafficLight_DataType_t* const instance );
void TrafficLight_DataType_Deinitialize( S_SM_TrafficLight_DataType_t* const instance );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TrafficLight_DataType_h__INCLUDED */

/* End of TrafficLight_DataType.h */
