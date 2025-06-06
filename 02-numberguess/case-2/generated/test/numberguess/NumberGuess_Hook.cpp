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

#include "NumberGuess_Fixture.hh"

#include <NumberGuess_Auxilary.h.template>

using namespace ::sm::test;

extern "C"
{
  // The implementation of the hook function of the guards
  bool NumberGuess_IsDraw( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance )
  {
    bool const result = NumberGuess_Fixture::GetMock( ).NumberGuess_IsDraw( smInfo, &smInfo->instanceData );
    return result;
  }

  bool NumberGuess_IsOnLeave( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance )
  {
    bool const result = NumberGuess_Fixture::GetMock( ).NumberGuess_IsOnLeave( smInfo, &smInfo->instanceData );
    return result;
  }

  bool NumberGuess_IsANumberRead( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance )
  {
    bool const result = NumberGuess_Fixture::GetMock( ).NumberGuess_IsANumberRead( smInfo, &smInfo->instanceData );
    return result;
  }

  bool NumberGuess_IsNumberInRange( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance )
  {
    bool const result = NumberGuess_Fixture::GetMock( ).NumberGuess_IsNumberInRange( smInfo, &smInfo->instanceData );
    return result;
  }

  bool NumberGuess_AreNumbersEqual( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance )
  {
    bool const result = NumberGuess_Fixture::GetMock( ).NumberGuess_AreNumbersEqual( smInfo, &smInfo->instanceData );
    return result;
  }

  bool NumberGuess_IsAnswerYes( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance )
  {
    bool const result = NumberGuess_Fixture::GetMock( ).NumberGuess_IsAnswerYes( smInfo, &smInfo->instanceData );
    return result;
  }

  bool NumberGuess_IsAnswerNo( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance )
  {
    bool const result = NumberGuess_Fixture::GetMock( ).NumberGuess_IsAnswerNo( smInfo, &smInfo->instanceData );
    return result;
  }

  // The implementation of the hook function of the actions
  void NumberGuess_Salute( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_Salute( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_SetANumber( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_SetANumber( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_AskEstimation( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_AskEstimation( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_ReadEstimation( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_ReadEstimation( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_PrintShowNumber( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_PrintShowNumber( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_PrintGoodBye( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_PrintGoodBye( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_PrintNoNumberIsRead( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_PrintNoNumberIsRead( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_PrintNumberIsNotInRange( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_PrintNumberIsNotInRange( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_PrintConguratulation( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_PrintConguratulation( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_PrintHints( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_PrintHints( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_PrintAskNewDeal( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_PrintAskNewDeal( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_ReadAnswerToContinue( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_ReadAnswerToContinue( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_PrintVola( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_PrintVola( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void NumberGuess_PrintWarning( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t* const pOutputData )
  {
    NumberGuess_Fixture::GetMock( ).NumberGuess_PrintWarning( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }
}

// End of NumberGuess_Hook.cpp

