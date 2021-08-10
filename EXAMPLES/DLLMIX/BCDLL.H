//----------------------------------------------------------------------------
// Mixing BC++ built 32-bit DLL's with non-BC applications.
// Copyright (c) 1996 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#ifndef BCDLL_H
#define BCDLL_H

#if defined( __cplusplus)
#define CFUNC extern "C"
#endif

//
// Functions are exported from the DLL and imported to the calling application.
// Visual C++ 4.1 does not support the __import keyword.
//
#if defined(BCDLL_BLD)
# define BCDLL_EXP __export
#else
# if defined(__BORLANDC__)
#  define BCDLL_EXP __import
# else
#  define BCDLL_EXP
# endif
#endif

//
// Visual C++ 4.1 does not support the C++ bool type nor its predefined values.
//
#if defined(_MSC_VER)
#  define bool BOOL
#  define true TRUE
#  define false FALSE
#endif

CFUNC bool        BCDLL_EXP __stdcall  Message(const char * msg);
CFUNC long        BCDLL_EXP __cdecl    Multiply(short s, int i);
CFUNC long double BCDLL_EXP __stdcall  Average(double d, float f);
CFUNC void        BCDLL_EXP __cdecl    ExceptionTest();
CFUNC void        BCDLL_EXP __stdcall  UnhandledException();


//
// Note: The following versions of the test functions specifically accomodate
// Visual Basic 4.0, which does not support Cdecl calling convention and does
// not have an equivalent data type to long double.
//

CFUNC bool        BCDLL_EXP __stdcall  VBMessage(const char * msg);
CFUNC long        BCDLL_EXP __stdcall  VBMultiply(short s, int i);
CFUNC double      BCDLL_EXP __stdcall  VBAverage(double d, float f);
CFUNC void        BCDLL_EXP __stdcall  VBExceptionTest();
CFUNC void        BCDLL_EXP __stdcall  VBUnhandledException();

#endif  // BCDLL_H
