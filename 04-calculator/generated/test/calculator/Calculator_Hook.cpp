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

#include "Calculator_Fixture.hh"

#include <Calculator_Auxilary.h.template>

using namespace ::sm::test;

extern "C"
{
  // The implementation of the hook function of the guards
  bool Calculator_IsBaseZero( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInstance )
  {
    bool const result = Calculator_Fixture::GetMock( ).Calculator_IsBaseZero( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Calculator_IsFractionZero( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInstance )
  {
    bool const result = Calculator_Fixture::GetMock( ).Calculator_IsFractionZero( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Calculator_IsThereSpaceForExponent( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInstance )
  {
    bool const result = Calculator_Fixture::GetMock( ).Calculator_IsThereSpaceForExponent( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Calculator_IsExponentZero( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInstance )
  {
    bool const result = Calculator_Fixture::GetMock( ).Calculator_IsExponentZero( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Calculator_HasDivisionByZeroError( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInstance )
  {
    bool const result = Calculator_Fixture::GetMock( ).Calculator_HasDivisionByZeroError( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Calculator_HasOverflowError( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInstance )
  {
    bool const result = Calculator_Fixture::GetMock( ).Calculator_HasOverflowError( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Calculator_IsFaulty( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInstance )
  {
    bool const result = Calculator_Fixture::GetMock( ).Calculator_IsFaulty( smInfo, &smInfo->instanceData );
    return result;
  }

  // The implementation of the hook function of the actions
  void Calculator_ResetAccumulations( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_ResetAccumulations( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_NotifyDisplayUpdate( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_NotifyDisplayUpdate( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_CheckErrorStatus( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_CheckErrorStatus( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_ClearLastEntry( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_ClearLastEntry( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_DrawSpliteLine( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_DrawSpliteLine( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_Additions( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_Additions( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_Substractions( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_Substractions( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_Multiplications( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_Multiplications( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_Divides( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_Divides( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_Calculate( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_Calculate( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_ClearFraction( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_ClearFraction( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_ClearExponent( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_ClearExponent( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_PushBaseDigit( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_PushBaseDigit( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_EraseBaseDigit( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_EraseBaseDigit( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_ChangeBaseSign( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_ChangeBaseSign( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_SetFractionEntry( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_SetFractionEntry( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_PushFractionDigit( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_PushFractionDigit( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_EraseFractionDigit( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_EraseFractionDigit( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_RemoveZerosFromFraction( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_RemoveZerosFromFraction( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_SetExponentEntry( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_SetExponentEntry( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_PushExponentDigit( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_PushExponentDigit( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_EraseExponentDigit( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_EraseExponentDigit( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_ChangeExponetSign( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_ChangeExponetSign( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_NotifyReset( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_NotifyReset( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_NotifyFaultError( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_NotifyFaultError( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_NotifyDivisionByZeroError( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_NotifyDivisionByZeroError( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Calculator_NotifyOverflowError( S_SM_Calculator_t* const smInfo, S_SM_Calculator_DataType_t const * const pInputData, S_SM_Calculator_DataType_t* const pOutputData )
  {
    Calculator_Fixture::GetMock( ).Calculator_NotifyOverflowError( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }
}

// End of Calculator_Hook.cpp
