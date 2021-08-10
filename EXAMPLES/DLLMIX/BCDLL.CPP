//----------------------------------------------------------------------------
// Mixing BC++ built 32-bit DLL's with non-BC applications.
// Copyright (c) 1996 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <windows.h>
#define BCDLL_BLD
#include "bcdll.h"

//
// Display a message passed from the calling application
//
bool BCDLL_EXP __stdcall Message(const char * msg)
   {
   return MessageBox(NULL, msg, "Borland C++ DLL", MB_OK|MB_APPLMODAL);
   }

//
// Verify calling convention match
//
long BCDLL_EXP __cdecl Multiply(short s, int i)
   {
   return s * (long)i;
   }

//
// Verify compatible handling of real numbers
//
long double BCDLL_EXP __stdcall Average(double d, float f)
   {
   return (d + (long double) f) / 2;
   }

//
// Verify that handling exceptions within the DLL has no side effects on
// the calling application.
//
void BCDLL_EXP __cdecl ExceptionTest()
   {
   bool handled = false;
   char bfr [25];
   try{
      throw 1;
      }
   catch (int exCode)
      {
      handled = true;
      }
   wsprintf(bfr, "%s ExceptionTest", ((handled==true) ? "Passed" : "Failed"));
   MessageBox(NULL, bfr, "Borland C++ DLL", MB_OK|MB_APPLMODAL);
   }

//
// Verify applications behavior if an exception is thrown in the DLL and allowed
// to propagate beyond the scope of the DLL.
//
void BCDLL_EXP __stdcall UnhandledException()
   {
   throw "Exception message thrown from a Borland C++ DLL.";
   }

///////////////// The Visual Basic versions //////////////////////////////
//
// Visual Basic does not support Cdecl, so stdcall versions of Multiply and
// ExceptionTest must be provided. Also, VB does not appear to have a type
// equivalent to long double, so a version of Average is provided that returns a
// double. For simplicity, the VB application will expect all exported functions
// to have a VB prepended to the name, so we will export Message and
// UnhandledException by alias in the Module Definition File.
//
long BCDLL_EXP __stdcall VBMultiply(short s, int i)
   {
   return s * (long)i;
   }

double BCDLL_EXP __stdcall VBAverage(double d, float f)
   {
   return (d + f) / 2;
   }

void BCDLL_EXP __stdcall VBExceptionTest()
   {
   bool handled = false;
   char bfr [25];
   try{
      throw 1;
      }
   catch (int exCode)
      {
      handled = true;
      }
   wsprintf(bfr, "%s ExceptionTest", ((handled==true) ? "Passed" : "Failed"));
   MessageBox(NULL, bfr, "Borland C++ DLL", MB_OK|MB_APPLMODAL);
   }

