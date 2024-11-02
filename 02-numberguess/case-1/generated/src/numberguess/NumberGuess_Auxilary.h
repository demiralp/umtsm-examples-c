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

#ifndef NumberGuess_Auxilary_h__INCLUDED
#define NumberGuess_Auxilary_h__INCLUDED

#include <NumberGuess.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 
/* The interface of the guards */
bool NumberGuess_AreNumbersEqual( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance );
bool NumberGuess_IsAnswerNo( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance );
bool NumberGuess_IsAnswerYes( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance );
bool NumberGuess_IsANumberRead( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance );
bool NumberGuess_IsNumberInRange( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInstance );

/* The interface of the actions */
void NumberGuess_AskEstimation( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_PrintAskNewDeal( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_PrintConguratulation( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_PrintGoodBye( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_PrintHints( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_PrintNoNumberIsRead( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_PrintNumberIsNotInRange( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_PrintVola( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_PrintWarning( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_ReadAnswerToContinue( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_ReadEstimation( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_Salute( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );
void NumberGuess_SetANumber( S_SM_NumberGuess_t* const smInfo, S_SM_NumberGuess_DataType_t const * const pInputData, S_SM_NumberGuess_DataType_t * const pOutputData );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NumberGuess_Auxilary_h__INCLUDED */

/* End of NumberGuess_Auxilary.h */