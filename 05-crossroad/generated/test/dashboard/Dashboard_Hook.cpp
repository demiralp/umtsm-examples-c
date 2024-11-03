/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-11-03 GMT
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

#include "Dashboard_Fixture.hh"

#include <Dashboard_Auxilary.h.template>

using namespace ::sm::test;

extern "C"
{
  // The implementation of the hook function of the guards
  bool Dashboard_IsKey_R( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_R( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_S( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_S( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_C( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_C( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_U( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_U( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_1( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_1( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_2( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_2( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_3( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_3( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_4( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_4( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_P( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_P( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_Q( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_Q( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_E( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_E( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_D( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_D( smInfo, &smInfo->instanceData );
    return result;
  }

  bool Dashboard_IsKey_Space( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInstance )
  {
    bool const result = Dashboard_Fixture::GetMock( ).Dashboard_IsKey_Space( smInfo, &smInfo->instanceData );
    return result;
  }

  // The implementation of the hook function of the actions
  void Dashboard_ReadCommand( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_ReadCommand( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_RunTheSystem( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_RunTheSystem( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_StandbyTheSystem( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_StandbyTheSystem( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_SwitchToControlledProgram( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_SwitchToControlledProgram( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_SwitchToUncontrolledProgram( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_SwitchToUncontrolledProgram( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_OpenLane1( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_OpenLane1( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_OpenLane2( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_OpenLane2( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_OpenLane3( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_OpenLane3( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_OpenLane4( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_OpenLane4( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_OpenPedestrianLanes( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_OpenPedestrianLanes( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_Quit( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_Quit( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_UpdateScreen( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_UpdateScreen( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_ReadLaneNumber( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_ReadLaneNumber( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_EnableLane1( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_EnableLane1( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_EnableLane2( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_EnableLane2( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_EnableLane3( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_EnableLane3( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_EnableLane4( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_EnableLane4( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_DisableLane1( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_DisableLane1( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_DisableLane2( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_DisableLane2( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_DisableLane3( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_DisableLane3( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void Dashboard_DisableLane4( S_SM_Dashboard_t* const smInfo, S_SM_Dashboard_DataType_t const * const pInputData, S_SM_Dashboard_DataType_t* const pOutputData )
  {
    Dashboard_Fixture::GetMock( ).Dashboard_DisableLane4( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }
}

// End of Dashboard_Hook.cpp
