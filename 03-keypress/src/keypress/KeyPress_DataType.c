/*  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-08-04 GMT
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

#include "KeyPress_DataType.h"

void KeyPress_DataType_Initialize(
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t* const instance )
{
  instance->issueId = 0;

  instance->countA=
  instance->countB=
  instance->countC=
  instance->countOdd=
  instance->countEven= 0;

  for(size_t i=0; i < sizeof(instance->countDigit)/sizeof(instance->countDigit[0]); ++i)
  {
    instance->countDigit[i]= 0;
  }
}

void KeyPress_DataType_Deinitialize(
  __attribute__( ( unused ) ) S_SM_KeyPress_DataType_t* const instance )
{
  /* do nothing */
}

/* End of KeyPress_DataType.c */
