/*
 *  ==============================================================================
 *  Created by Fehmi Demiralp(Fedem) on 2024-10-09 GMT
 *  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
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

#include "Paroot_Auxilary.h"
#include "Paroot_DataType.h"

#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

#define EPSILON (1e-8)

static bool ReadParameter( double * const param );
static void printComplexNumber( double real, double imag );

/* The implementation of the actions */
void Paroot_FindTheRoots(
  __attribute__( ( unused ) ) S_SM_Paroot_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Paroot_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Paroot_DataType_t * const pOutputData )
{
  pOutputData->delta = (pInputData->paramB*pInputData->paramB-4.0*pInputData->paramA*pInputData->paramC);

  if ( fabs(pOutputData->delta) <= EPSILON )
  {
    pOutputData->delta = 0.0;
    pOutputData->root1Real = pOutputData->root2Real = -pOutputData->paramB / (2.0*pOutputData->paramA);
    pOutputData->root1Imag= pOutputData->root2Imag = 0.0;
    pOutputData->solutionType = MONO;
  }
  else if ( pOutputData->delta > 0.0 )
  {
    double deltaSq = sqrt( pOutputData->delta);
    pOutputData->root1Real = (-pOutputData->paramB - deltaSq)/(2.0*pOutputData->paramA);
    pOutputData->root2Real = (-pOutputData->paramB + deltaSq)/(2.0*pOutputData->paramA);
    pOutputData->root1Imag= pOutputData->root2Imag = 0.0;
    pOutputData->solutionType = REAL;
  }
  else
  {
    double deltaSq = sqrt( -pOutputData->delta);
    pOutputData->root1Real = -pOutputData->paramB / (2.0*pOutputData->paramA);
    pOutputData->root1Imag = -deltaSq / (2.0*pOutputData->paramA);
    pOutputData->root2Real = -pOutputData->paramB / (2.0*pOutputData->paramA);
    pOutputData->root2Imag = deltaSq/(2.0*pOutputData->paramA);
    pOutputData->solutionType = COMPLEX;
  }
} /* End of action function: Paroot_FindTheRoots */

void Paroot_ReadParameters(
  __attribute__( ( unused ) ) S_SM_Paroot_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Paroot_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Paroot_DataType_t * const pOutputData )
{
  bool readingOkay = false;
  do
  {
    printf( "Enter parameter A : ");
    fflush(stdout);
    readingOkay = ReadParameter(&pOutputData->paramA) && fabs( pOutputData->paramA ) > EPSILON;
  } while (!readingOkay );

  do
  {
    printf( "Enter parameter B : " );
    fflush(stdout);
    readingOkay = ReadParameter(&pOutputData->paramB);
  } while (!readingOkay );

  do
  {
    printf( "Enter parameter C : " );
    fflush(stdout);
    readingOkay = ReadParameter(&pOutputData->paramC);
  } while (!readingOkay );

} /* End of action function: Paroot_ReadParameters */

void Paroot_WriteSolutions(
  __attribute__( ( unused ) ) S_SM_Paroot_t* const smInfo,
  __attribute__( ( unused ) ) S_SM_Paroot_DataType_t const * const pInputData,
  __attribute__( ( unused ) ) S_SM_Paroot_DataType_t * const pOutputData )
{
  switch (pInputData->solutionType )
  {
    case MONO:
    {
      printf( "both roots are equal to : %g\n", pInputData->root1Real );
      break;
    }
    case REAL:
    {
      printf( "root1 : %g\n", pInputData->root1Real );
      printf( "root2 : %g\n", pInputData->root2Real );
      break;
    }
    case COMPLEX:
    {
      printf( "root1 : " );
      printComplexNumber( pInputData->root1Real, pInputData->root1Imag );
      printf("\n");
      printf( "root2 : " );
      printComplexNumber( pInputData->root2Real, pInputData->root2Imag );
      printf("\n");
      break;
    }
  }
} /* End of action function: Paroot_WriteSolutions */

static bool ReadParameter( double * const param)
{
  char buffer[256];
  int readByte= read( 0, buffer, sizeof(buffer)-1 );
  bool result = (readByte > 0);
  if (result)
  {
    buffer[readByte]= '\0';
    double p;
    result = sscanf( buffer, "%lf", &p) == 1;
    *param = p;
  }

  fflush(stdin);

  return result;
}

static void printComplexNumber( double real, double imag )
{
  printf("%g", real );
  if ( fabs(imag) > EPSILON)
  {
    if (imag > 0 )
    {
      printf("+");
    }
    printf( "%gi", imag );
  }
}

/* End of Paroot_Auxilary.c */
