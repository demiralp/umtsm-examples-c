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

#include "PedestrianLights_Fixture.hh"

#include <PedestrianLights_Auxilary.h.template>

using namespace ::sm::test;

extern "C"
{
  // The implementation of the hook function of the guards
  bool PedestrianLights_IsStopCheckAndGo( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInstance )
  {
    bool const result = PedestrianLights_Fixture::GetMock( ).PedestrianLights_IsStopCheckAndGo( smInfo, &smInfo->instanceData );
    return result;
  }

  bool PedestrianLights_IsCheckAndGo( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInstance )
  {
    bool const result = PedestrianLights_Fixture::GetMock( ).PedestrianLights_IsCheckAndGo( smInfo, &smInfo->instanceData );
    return result;
  }

  bool PedestrianLights_IsSystemSwitching( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInstance )
  {
    bool const result = PedestrianLights_Fixture::GetMock( ).PedestrianLights_IsSystemSwitching( smInfo, &smInfo->instanceData );
    return result;
  }

  bool PedestrianLights_IsLaneClose( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInstance )
  {
    bool const result = PedestrianLights_Fixture::GetMock( ).PedestrianLights_IsLaneClose( smInfo, &smInfo->instanceData );
    return result;
  }

  bool PedestrianLights_IsSystemOperational( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInstance )
  {
    bool const result = PedestrianLights_Fixture::GetMock( ).PedestrianLights_IsSystemOperational( smInfo, &smInfo->instanceData );
    return result;
  }

  bool PedestrianLights_IsLaneOpen( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInstance )
  {
    bool const result = PedestrianLights_Fixture::GetMock( ).PedestrianLights_IsLaneOpen( smInfo, &smInfo->instanceData );
    return result;
  }

  // The implementation of the hook function of the actions
  void PedestrianLights_SwitchRedLightOff( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInputData, S_SM_PedestrianLights_DataType_t* const pOutputData )
  {
    PedestrianLights_Fixture::GetMock( ).PedestrianLights_SwitchRedLightOff( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void PedestrianLights_CountForFlashing( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInputData, S_SM_PedestrianLights_DataType_t* const pOutputData )
  {
    PedestrianLights_Fixture::GetMock( ).PedestrianLights_CountForFlashing( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void PedestrianLights_SwitchRedLightOn( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInputData, S_SM_PedestrianLights_DataType_t* const pOutputData )
  {
    PedestrianLights_Fixture::GetMock( ).PedestrianLights_SwitchRedLightOn( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void PedestrianLights_SwitchGreenLightOff( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInputData, S_SM_PedestrianLights_DataType_t* const pOutputData )
  {
    PedestrianLights_Fixture::GetMock( ).PedestrianLights_SwitchGreenLightOff( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }

  void PedestrianLights_SwitchGreenLightOn( S_SM_PedestrianLights_t* const smInfo, S_SM_PedestrianLights_DataType_t const * const pInputData, S_SM_PedestrianLights_DataType_t* const pOutputData )
  {
    PedestrianLights_Fixture::GetMock( ).PedestrianLights_SwitchGreenLightOn( smInfo, &smInfo->instanceData, &smInfo->instanceData );
  }
}

// End of PedestrianLights_Hook.cpp

