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

#ifndef Lane_Auxilary_h__INCLUDED
#define Lane_Auxilary_h__INCLUDED

#include <Lane.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
/* The interface of the guards */
bool Lane_IsCheckAndGo( S_SM_Lane_t* const smInfo, S_SM_Lane_DataType_t const * const pInstance );

/* The interface of the Persistency Functions */
void Lane_Store_Availability( E_Lane_Availability_States_t state, S_SM_Lane_DataType_t* const pInstance );
E_Lane_Availability_States_t Lane_Load_Availability( S_SM_Lane_DataType_t* const pInstance );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* Lane_Auxilary_h__INCLUDED */

/* End of Lane_Auxilary.h */
