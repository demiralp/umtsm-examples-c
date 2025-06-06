/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2025-05-29 GMT
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

#include "Engine_Fixture.hh"

#include <Engine_Auxilary.h.template>

using namespace ::sm::test;

extern "C"
{
  // The implementation of the hook function of the actions
  void Engine_PowerUpLeftWire( S_SM_Engine_t* const smInfo, S_SM_Engine_DataType_t const * const pInputData, S_SM_Engine_DataType_t* const pOutputData )
  {
    Engine_Fixture::GetMock( ).Engine_PowerUpLeftWire( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Engine_PowerOffLeftWire( S_SM_Engine_t* const smInfo, S_SM_Engine_DataType_t const * const pInputData, S_SM_Engine_DataType_t* const pOutputData )
  {
    Engine_Fixture::GetMock( ).Engine_PowerOffLeftWire( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Engine_PowerUpRightWire( S_SM_Engine_t* const smInfo, S_SM_Engine_DataType_t const * const pInputData, S_SM_Engine_DataType_t* const pOutputData )
  {
    Engine_Fixture::GetMock( ).Engine_PowerUpRightWire( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Engine_PowerOffRightWire( S_SM_Engine_t* const smInfo, S_SM_Engine_DataType_t const * const pInputData, S_SM_Engine_DataType_t* const pOutputData )
  {
    Engine_Fixture::GetMock( ).Engine_PowerOffRightWire( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  // The implementation of the hook function to load and store persistent histories
  void Engine_Store_Deep_Main( E_Engine_Main_States_t state, S_SM_Engine_DataType_t * const pInstanceData )
  {
    Engine_Fixture::GetMock( ).Engine_Store_Deep_Main( state, pInstanceData );
  }

  E_Engine_Main_States_t Engine_Load_Deep_Main( S_SM_Engine_DataType_t * const pInstanceData )
  {
    E_Engine_Main_States_t const result = Engine_Fixture::GetMock( ).Engine_Load_Deep_Main( pInstanceData );
    return result;
  }
}

// End of Engine_Hook.cpp

