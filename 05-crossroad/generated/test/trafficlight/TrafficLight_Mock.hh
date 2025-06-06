/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-11-03 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  This file is generated by UMTSM using the code generator `CGen`
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

#ifndef TrafficLight_Mock_hh__INCLUDED
#define TrafficLight_Mock_hh__INCLUDED

#include <TrafficLight_Interface.hh>

#include <gmock/gmock.h>

namespace sm
{
  namespace test
  {
    class TrafficLight_Mock
      : public TrafficLight_Interface
    {
      public:
        // The mock of the guards
        MOCK_METHOD( bool, TrafficLight_IsSystemSwitching, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData ), ( override ) );
        MOCK_METHOD( bool, TrafficLight_IsStopCheckAndGo, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData ), ( override ) );
        MOCK_METHOD( bool, TrafficLight_IsCheckAndGo, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData ), ( override ) );
        MOCK_METHOD( bool, TrafficLight_IsLaneClose, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData ), ( override ) );
        MOCK_METHOD( bool, TrafficLight_IsLaneAvailable, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData ), ( override ) );
        MOCK_METHOD( bool, TrafficLight_IsSystemOperational, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData ), ( override ) );
        MOCK_METHOD( bool, TrafficLight_IsLaneOpen, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData ), ( override ) );
        MOCK_METHOD( bool, TrafficLight_IsLaneOnClosing, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData ), ( override ) );
        MOCK_METHOD( bool, TrafficLight_IsLaneOnOpening, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData ), ( override ) );

        // The mock of the actions
        MOCK_METHOD( void, TrafficLight_SwitchRedLightOff, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData, S_SM_TrafficLight_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, TrafficLight_CountForFlashing, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData, S_SM_TrafficLight_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, TrafficLight_SwitchRedLightOn, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData, S_SM_TrafficLight_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, TrafficLight_SwitchAmberLightOff, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData, S_SM_TrafficLight_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, TrafficLight_SwitchAmberLightOn, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData, S_SM_TrafficLight_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, TrafficLight_SwitchGreenLightOff, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData, S_SM_TrafficLight_DataType_t* const pOutputData ), ( override ) );
        MOCK_METHOD( void, TrafficLight_SwitchGreenLightOn, ( S_SM_TrafficLight_t* const smInfo, S_SM_TrafficLight_DataType_t const* const pInputData, S_SM_TrafficLight_DataType_t* const pOutputData ), ( override ) );
    }; // End Of the class `TrafficLight_Mock`
  } // End namespace test
} // End namespace sm

#endif // End Of TrafficLight_Mock_hh__INCLUDED

// End of TrafficLight_Mock.hh

