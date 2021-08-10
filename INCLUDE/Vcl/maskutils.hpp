// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MaskUtils.pas' rev: 6.00

#ifndef MaskUtilsHPP
#define MaskUtilsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Maskutils
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TMaskCharType { mcNone, mcLiteral, mcIntlLiteral, mcDirective, mcMask, mcMaskOpt, mcFieldSeparator, mcField };
#pragma option pop

#pragma option push -b-
enum MaskUtils__1 { mdReverseDir, mdUpperCase, mdLowerCase, mdLiteralChar };
#pragma option pop

typedef Set<MaskUtils__1, mdReverseDir, mdLiteralChar>  TMaskDirectives;

typedef AnsiString TMaskedText;

typedef AnsiString TEditMask;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE char DefaultBlank;
extern PACKAGE char MaskFieldSeparator;
extern PACKAGE char MaskNoSave;
static const char mDirReverse = '\x21';
static const char mDirUpperCase = '\x3e';
static const char mDirLowerCase = '\x3c';
static const char mDirLiteral = '\x5c';
static const char mMskAlpha = '\x4c';
static const char mMskAlphaOpt = '\x6c';
static const char mMskAlphaNum = '\x41';
static const char mMskAlphaNumOpt = '\x61';
static const char mMskAscii = '\x43';
static const char mMskAsciiOpt = '\x63';
static const char mMskNumeric = '\x30';
static const char mMskNumericOpt = '\x39';
static const char mMskNumSymOpt = '\x23';
static const char mMskTimeSeparator = '\x3a';
static const char mMskDateSeparator = '\x2f';
extern PACKAGE TMaskCharType __fastcall MaskGetCharType(const AnsiString EditMask, int MaskOffset);
extern PACKAGE TMaskDirectives __fastcall MaskGetCurrentDirectives(const AnsiString EditMask, int MaskOffset);
extern PACKAGE char __fastcall MaskIntlLiteralToChar(char IChar);
extern PACKAGE AnsiString __fastcall MaskDoFormatText(const AnsiString EditMask, const AnsiString Value, char Blank);
extern PACKAGE bool __fastcall MaskGetMaskSave(const AnsiString EditMask);
extern PACKAGE char __fastcall MaskGetMaskBlank(const AnsiString EditMask);
extern PACKAGE int __fastcall MaskGetFldSeparator(const AnsiString EditMask);
extern PACKAGE int __fastcall MaskOffsetToOffset(const AnsiString EditMask, int MaskOffset);
extern PACKAGE int __fastcall MaskOffsetToWideOffset(const AnsiString EditMask, int MaskOffset);
extern PACKAGE int __fastcall OffsetToMaskOffset(const AnsiString EditMask, int Offset);
extern PACKAGE bool __fastcall IsLiteralChar(const AnsiString EditMask, int Offset);
extern PACKAGE AnsiString __fastcall PadInputLiterals(const AnsiString EditMask, const AnsiString Value, char Blank);
extern PACKAGE AnsiString __fastcall FormatMaskText(const AnsiString EditMask, const AnsiString Value);

}	/* namespace Maskutils */
using namespace Maskutils;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MaskUtils
