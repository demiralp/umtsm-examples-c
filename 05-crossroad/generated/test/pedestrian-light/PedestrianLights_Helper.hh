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

#ifndef PedestrianLights_Helper_hh__INCLUDED
#define PedestrianLights_Helper_hh__INCLUDED

#include <PedestrianLights_Fixture.hh>

#include <gtest/gtest.h>

namespace sm
{
  namespace test
  {
    template < class FixtureType, class TestDataType>
    class TestFixture_PedestrianLights
      : public FixtureType,
        public ::testing::WithParamInterface< TestDataType >
    {
      protected:
        static void JumpInState( S_SM_PedestrianLights_t* sm, E_PedestrianLights_Main_States_t state );
        static void JumpInState( S_SM_PedestrianLights_t* sm, E_PedestrianLights_Top_States_t state );
        static void JumpInState( S_SM_PedestrianLights_t* sm, E_PedestrianLights_Bottom_States_t state );
    };

    template< class FixtureType, class TestDataType >
    inline void TestFixture_PedestrianLights< FixtureType, TestDataType >::JumpInState( S_SM_PedestrianLights_t* sm, E_PedestrianLights_Main_States_t state )
    {
      sm->runningState.Main = state;
    }

    template< class FixtureType, class TestDataType >
    inline void TestFixture_PedestrianLights< FixtureType, TestDataType >::JumpInState( S_SM_PedestrianLights_t* sm, E_PedestrianLights_Top_States_t state )
    {
      sm->runningState.Main = E_PedestrianLights_Main;
      sm->runningState.Main = E_PedestrianLights_Main;
      sm->runningState.Top = state;
    }

    template< class FixtureType, class TestDataType >
    inline void TestFixture_PedestrianLights< FixtureType, TestDataType >::JumpInState( S_SM_PedestrianLights_t* sm, E_PedestrianLights_Bottom_States_t state )
    {
      sm->runningState.Main = E_PedestrianLights_Main;
      sm->runningState.Main = E_PedestrianLights_Main;
      sm->runningState.Bottom = state;
    }
  } // End namespace test
} // End namespace sm

#endif

// End of PedestrianLights_InitTests.cpp
