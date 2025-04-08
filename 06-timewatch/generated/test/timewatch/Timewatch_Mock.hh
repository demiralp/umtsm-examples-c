/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2025-04-08 GMT
 *  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *  
 *  This file is generated by UMTSM using the code generator `CGen`
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

#ifndef Timewatch_Mock_hh__INCLUDED
#define Timewatch_Mock_hh__INCLUDED

#include <Timewatch_Interface.hh>

#include <gmock/gmock.h>

namespace sm
{
  namespace test
  {
    class Timewatch_Mock
      : public Timewatch_Interface
    {
      public:
        // The mock of the actions
        MOCK_METHOD( void, Timewatch_PrintHelp, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_Exit, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_InitWatchProperties, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_PrintStatusReset, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_PrintElapsedTime, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_InitPauseTime, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_PrintStatusPause, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_UpdateSuspendentDuration, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_PrintStatusResume, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_PrintStatusIdle, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_PrintStatusRun, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, Timewatch_ReportTotalTime, ( S_SM_Timewatch_t* const smInfo, S_SM_Timewatch_DataType_t const* const pInputData, S_SM_Timewatch_DataType_t* const pOutputData ), ( override ) );
    }; // End Of the class `Timewatch_Mock`
  } // End namespace test
} // End namespace sm

#endif // End Of Timewatch_Mock_hh__INCLUDED

// End of Timewatch_Mock.hh

