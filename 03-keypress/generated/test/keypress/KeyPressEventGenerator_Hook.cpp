/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-11-02 GMT
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

#include "KeyPressEventGenerator_Fixture.hh"

#include <KeyPressEventGenerator_Auxilary.h.template>

using namespace ::sm::test;

extern "C"
{
  // The implementation of the hook function of the actions
  void KeyPressEventGenerator_ReadKey( S_SM_KeyPressEventGenerator_t* const smInfo, S_SM_KeyPressEventGenerator_DataType_t const * const pInputData, S_SM_KeyPressEventGenerator_DataType_t* const pOutputData )
  {
    KeyPressEventGenerator_Fixture::GetMock( ).KeyPressEventGenerator_ReadKey( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void KeyPressEventGenerator_TimeBaseEventGenerator( S_SM_KeyPressEventGenerator_t* const smInfo, S_SM_KeyPressEventGenerator_DataType_t const * const pInputData, S_SM_KeyPressEventGenerator_DataType_t* const pOutputData )
  {
    KeyPressEventGenerator_Fixture::GetMock( ).KeyPressEventGenerator_TimeBaseEventGenerator( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }
}

// End of KeyPressEventGenerator_Hook.cpp

