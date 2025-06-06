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

#include <Door_Helper.hh>

namespace
{
  using namespace ::std;
  using namespace ::testing;
  using namespace ::sm::test;
  using ::testing::_;
} // namespace

namespace
{
  typedef struct StoredStateStatus
  {
    E_Door_Main_States_t shallow_Main;
  } StoredStateStatus_t;

  using Door_InititalizationTest = TestFixture_Door< Door_Fixture, StoredStateStatus_t >;

  TEST_P( Door_InititalizationTest, DISABLED_Initialize )
  {
    auto const testcase = GetParam( );

    ON_CALL( GetMock( ), Door_Load_Shallow_Main( _ ) )
      .WillByDefault( Return( testcase.shallow_Main ) );
    S_SM_Door_t sm;

    Door_Initialize( &sm );

    EXPECT_EQ( sm.runningState.Main, E_Door_init );

    EXPECT_EQ( sm.storedState.shallow_Main, testcase.shallow_Main );
  }

  StoredStateStatus_t SampleDataValues[ ] =
  {
    { E_Door_init },
    { E_Door_Open },
    { E_Door_Closing },
    { E_Door_Close },
    { E_Door_Opening }
  };

  INSTANTIATE_TEST_SUITE_P( Door_InititalizationTestDataSet,
    Door_InititalizationTest, ValuesIn( SampleDataValues ) );
} // namespace

// End of Door_InitTests.cpp
