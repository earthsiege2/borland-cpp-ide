// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBUtils.pas' rev: 5.00

#ifndef IBUtilsHPP
#define IBUtilsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibutils
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define CRLF "\r\n"
static const char CR = '\xd';
static const char LF = '\xa';
static const char TAB = '\x9';
static const char NULL_TERMINATOR = '\x0';
extern PACKAGE int __fastcall Max(int n1, int n2);
extern PACKAGE int __fastcall Min(int n1, int n2);
extern PACKAGE AnsiString __fastcall RandomString(int iLength);
extern PACKAGE int __fastcall RandomInteger(int iLow, int iHigh);
extern PACKAGE AnsiString __fastcall StripString(AnsiString st, AnsiString CharsToStrip);
extern PACKAGE AnsiString __fastcall FormatIdentifier(int Dialect, AnsiString Value);
extern PACKAGE AnsiString __fastcall FormatIdentifierValue(int Dialect, AnsiString Value);
extern PACKAGE AnsiString __fastcall ExtractIdentifier(int Dialect, AnsiString Value);

}	/* namespace Ibutils */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibutils;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBUtils
