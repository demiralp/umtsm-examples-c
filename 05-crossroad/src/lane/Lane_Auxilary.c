/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-09-09 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
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

#include "Lane_Auxilary.h"

#include <assert.h>
#include <memory.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/* The implementation of the guards */
bool Lane_IsCheckAndGo(
  __attribute__( ( unused ) ) S_SM_Lane_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Lane_DataType_t const * const pInstance )
{
  bool const result = pInstance->UncontrolMode == E_CHECK;
  return result;
} /* End of guard function: Lane_IsCheckAndGo */

/* The implementation of the Persistency Functions */
void Lane_Store_Shallow_Availability(
  __attribute__( ( unused ) ) E_Lane_Availability_States_t state,
  __attribute__( ( unused ) ) S_SM_Lane_DataType_t* const pInstance )
{
  static char const* const regfile = "crossroad-lane";
  char const* folder               = getenv( "TMPDIR" );
  char path[ 256 ];
  if( folder == 0 )
  {
    folder = "/tmp";
  }

  strcpy( path, folder );
  strcat( path, "/" );
  strcat( path, regfile );
  strcat( path, pInstance->Id );
  strcat( path, ".bin" );

  FILE* fd = fopen( path, "wb" );
  if( fd != NULL )
  {
    uint16_t sdata = (uint16_t)state;
    fwrite( &sdata, sizeof( sdata ), 1, fd );
    fclose( fd );
  }
} /* End of action function: Lane_Store_Shallow_Availability */

E_Lane_Availability_States_t Lane_Load_Shallow_Availability(
  __attribute__( ( unused ) ) S_SM_Lane_DataType_t* const pInstance )
{
  E_Lane_Availability_States_t result = E_Lane_Availability_init;

  static char const* const regfile = "crossroad-lane";
  char const* folder               = getenv( "TMPDIR" );
  char path[ 256 ];
  if( folder == 0 )
  {
    folder = "/tmp";
  }

  strcpy( path, folder );
  strcat( path, "/" );
  strcat( path, regfile );
  strcat( path, pInstance->Id );
  strcat( path, ".bin" );

  FILE* fd = fopen( path, "rb" );
  if( fd != NULL )
  {
    uint16_t sdata;
    fread( &sdata, sizeof( sdata ), 1, fd );
    result = (E_Lane_Main_States_t)sdata;
    fclose( fd );
  }

  return result;
} /* End of loader function: Lane_Load_Shallow_Availability */

/* End of Lane_Auxilary.c */
