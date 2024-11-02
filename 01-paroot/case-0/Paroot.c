/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2024-07-28 GMT.
 * Copyright (C) 2023-2024 FEDEM (Fehmi Demiralp) <f.demiralp@gmail.com>.
 *
 * Released under the MIT License:
 *============================================================================*/

/*
Copyright (c) 2023-2024 Fedem (Fehmi Demiralp)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

#define EPSILON (1e-8)

typedef enum E_Paroot_Solution
{
  UNDEFINED,
  MONO,
  REAL,
  COMPLEX
} E_Paroot_Solution_t;

double paramA;
double paramB;
double paramC;

double root1Real;
double root1Imag;
double root2Real;
double root2Imag;
E_Paroot_Solution_t solutionType;

static void FindTheRoots( );
static void ReadParameters( );
static void WriteSolutions( );

static bool ReadParameter( double * const param );
static void PrintComplexNumber( double real, double imag );

int main( int const, char const * const * )
{
    ReadParameters( );
    FindTheRoots( );
    WriteSolutions( );

    return EXIT_SUCCESS;
}

static void ReadParameters( )
{
  bool readingOkay = false;
  do
  {
    printf( "Enter parameter A : ");
    fflush(stdout);
    readingOkay = ReadParameter(&paramA) && fabs( paramA ) > EPSILON;
  } while (!readingOkay );

  do
  {
    printf( "Enter parameter B : " );
    fflush(stdout);
    readingOkay = ReadParameter(&paramB);
  } while (!readingOkay );

  do
  {
    printf( "Enter parameter C : " );
    fflush(stdout);
    readingOkay = ReadParameter(&paramC);
  } while (!readingOkay );
}

static void FindTheRoots( )
{
  double delta = (paramB*paramB-4.0*paramA*paramC);

  if ( fabs(delta) <= EPSILON )
  {
    delta = 0.0;
    root1Real = root2Real = -paramB / (2.0*paramA);
    root1Imag= root2Imag = 0.0;
    solutionType = MONO;
  }
  else if ( delta > 0.0 )
  {
    double deltaSq = sqrt( delta);
    root1Real = (-paramB - deltaSq)/(2.0*paramA);
    root2Real = (-paramB + deltaSq)/(2.0*paramA);
    root1Imag= root2Imag = 0.0;
    solutionType = REAL;
  }
  else
  {
    double deltaSq = sqrt( -delta);
    root1Real = -paramB / (2.0*paramA);
    root1Imag = -deltaSq / (2.0*paramA);
    root2Real = -paramB / (2.0*paramA);    
    root2Imag = deltaSq/(2.0*paramA);
    solutionType = COMPLEX;
  }
}

static void WriteSolutions( )
{
  switch (solutionType )
  {
    case MONO:
    {
      printf( "both roots are equal to : %g\n", root1Real );
      break;
    }
    case REAL:
    {
      printf( "root1 : %g\n", root1Real );
      printf( "root2 : %g\n", root2Real );
      break;
    }
    case COMPLEX:
    {
      printf( "root1 : " );
      PrintComplexNumber( root1Real, root1Imag );
      printf("\n");
      printf( "root2 : " );
      PrintComplexNumber( root2Real, root2Imag );
      printf("\n");
      break;
    }
  }
}

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

static void PrintComplexNumber( double real, double imag )
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
