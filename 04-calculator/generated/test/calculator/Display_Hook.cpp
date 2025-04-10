/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-11-02 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
 *
 *  This file is generated by UMTSM using the code generator `CGen`
 *
 *  Released under the MIT License
 *  ============================================================================
 */

/*
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
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

#include "Display_Fixture.hh"

#include <Display_Auxilary.h.template>

using namespace ::sm::test;

extern "C"
{
  // The implementation of the hook function of the actions
  void Display_DisplayUpdate( S_SM_Display_t* const smInfo, S_SM_Display_DataType_t const * const pInputData, S_SM_Display_DataType_t* const pOutputData )
  {
    Display_Fixture::GetMock( ).Display_DisplayUpdate( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Display_DisplayOverflowError( S_SM_Display_t* const smInfo, S_SM_Display_DataType_t const * const pInputData, S_SM_Display_DataType_t* const pOutputData )
  {
    Display_Fixture::GetMock( ).Display_DisplayOverflowError( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Display_DisplayDivisionByZeroError( S_SM_Display_t* const smInfo, S_SM_Display_DataType_t const * const pInputData, S_SM_Display_DataType_t* const pOutputData )
  {
    Display_Fixture::GetMock( ).Display_DisplayDivisionByZeroError( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Display_DisplayFaultyError( S_SM_Display_t* const smInfo, S_SM_Display_DataType_t const * const pInputData, S_SM_Display_DataType_t* const pOutputData )
  {
    Display_Fixture::GetMock( ).Display_DisplayFaultyError( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }
}

// End of Display_Hook.cpp

