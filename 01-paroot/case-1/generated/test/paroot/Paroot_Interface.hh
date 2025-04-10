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

#ifndef Paroot_Interface_hh__INCLUDED
#define Paroot_Interface_hh__INCLUDED

#include <Paroot.h>

namespace sm
{
  namespace test
  {
    class Paroot_Interface
    {
      public:
        virtual ~Paroot_Interface( );

        // The mock interface of the actions
        virtual void Paroot_ReadParameters( S_SM_Paroot_t* const smInfo, S_SM_Paroot_DataType_t const * const pInputData, S_SM_Paroot_DataType_t * const pOutputData ) = 0;
        virtual void Paroot_FindTheRoots( S_SM_Paroot_t* const smInfo, S_SM_Paroot_DataType_t const * const pInputData, S_SM_Paroot_DataType_t * const pOutputData ) = 0;
        virtual void Paroot_WriteSolutions( S_SM_Paroot_t* const smInfo, S_SM_Paroot_DataType_t const * const pInputData, S_SM_Paroot_DataType_t * const pOutputData ) = 0;
    }; // End Of the class `Paroot_Interface`
  } // End namespace test
} // End namespace sm

#endif // End Of Paroot_Interface_hh__INCLUDED

// End of Paroot_Interface.hh

