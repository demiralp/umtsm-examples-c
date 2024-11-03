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

#include "Crossroad_Fixture.hh"

namespace sm
{
  namespace test
  {
    ::testing::NiceMock< Crossroad_Mock > * Crossroad_Fixture::mock = nullptr;

    ::testing::NiceMock< Crossroad_Mock >& Crossroad_Fixture::GetMock() noexcept
    {
      if (mock == nullptr)
      {
        mock = new ::testing::NiceMock< Crossroad_Mock >;
      }

      return *mock;
    }

    void Crossroad_Fixture::SetUp()
    {
      if (mock == nullptr)
      {
        mock = new ::testing::NiceMock< Crossroad_Mock >;
      }
    }

    void Crossroad_Fixture::TearDown()
    {
      if (mock != nullptr)
      {
        delete mock;
        mock = nullptr;
      }
    }
  } // End namespace test
} // End namespace sm
// End of Crossroad_Fixture.cpp

