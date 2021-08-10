// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StrUtils.pas' rev: 6.00

#ifndef StrUtilsHPP
#define StrUtilsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Strutils
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TStringSeachOption { soDown, soMatchCase, soWholeWord };
#pragma option pop

typedef Set<TStringSeachOption, soDown, soWholeWord>  TStringSearchOptions;

typedef int TSoundexLength;

typedef Shortint TSoundexIntLength;

typedef bool __fastcall (*TCompareTextProc)(const AnsiString AText, const AnsiString AOther);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Set<char, 0, 255>  WordDelimiters;
extern PACKAGE TCompareTextProc AnsiResemblesProc;
extern PACKAGE bool __fastcall AnsiResemblesText(const AnsiString AText, const AnsiString AOther);
extern PACKAGE bool __fastcall AnsiContainsText(const AnsiString AText, const AnsiString ASubText);
extern PACKAGE bool __fastcall AnsiStartsText(const AnsiString ASubText, const AnsiString AText);
extern PACKAGE bool __fastcall AnsiEndsText(const AnsiString ASubText, const AnsiString AText);
extern PACKAGE AnsiString __fastcall AnsiReplaceStr(const AnsiString AText, const AnsiString AFromText, const AnsiString AToText);
extern PACKAGE AnsiString __fastcall AnsiReplaceText(const AnsiString AText, const AnsiString AFromText, const AnsiString AToText);
extern PACKAGE bool __fastcall AnsiMatchText(const AnsiString AText, const AnsiString * AValues, const int AValues_Size);
extern PACKAGE int __fastcall AnsiIndexText(const AnsiString AText, const AnsiString * AValues, const int AValues_Size);
extern PACKAGE bool __fastcall AnsiContainsStr(const AnsiString AText, const AnsiString ASubText);
extern PACKAGE bool __fastcall AnsiStartsStr(const AnsiString ASubText, const AnsiString AText);
extern PACKAGE bool __fastcall AnsiEndsStr(const AnsiString ASubText, const AnsiString AText);
extern PACKAGE bool __fastcall AnsiMatchStr(const AnsiString AText, const AnsiString * AValues, const int AValues_Size);
extern PACKAGE int __fastcall AnsiIndexStr(const AnsiString AText, const AnsiString * AValues, const int AValues_Size);
extern PACKAGE AnsiString __fastcall DupeString(const AnsiString AText, int ACount);
extern PACKAGE AnsiString __fastcall ReverseString(const AnsiString AText);
extern PACKAGE AnsiString __fastcall StuffString(const AnsiString AText, unsigned AStart, unsigned ALength, const AnsiString ASubText);
extern PACKAGE AnsiString __fastcall RandomFrom(const AnsiString * AValues, const int AValues_Size)/* overload */;
extern PACKAGE AnsiString __fastcall IfThen(bool AValue, const AnsiString ATrue, AnsiString AFalse = "")/* overload */;
extern PACKAGE AnsiString __fastcall LeftStr(const AnsiString AText, const int ACount);
extern PACKAGE AnsiString __fastcall RightStr(const AnsiString AText, const int ACount);
extern PACKAGE AnsiString __fastcall MidStr(const AnsiString AText, const int AStart, const int ACount);
extern PACKAGE char * __fastcall SearchBuf(char * Buf, int BufLen, int SelStart, int SelLength, AnsiString SearchString, TStringSearchOptions Options = (System::Set<TStringSeachOption, soDown, soWholeWord> () << TStringSeachOption(0) ));
extern PACKAGE AnsiString __fastcall Soundex(const AnsiString AText, TSoundexLength ALength = (TSoundexLength)(0x4));
extern PACKAGE int __fastcall SoundexInt(const AnsiString AText, TSoundexIntLength ALength = (TSoundexIntLength)(0x4));
extern PACKAGE AnsiString __fastcall DecodeSoundexInt(int AValue);
extern PACKAGE Word __fastcall SoundexWord(const AnsiString AText);
extern PACKAGE AnsiString __fastcall DecodeSoundexWord(Word AValue);
extern PACKAGE bool __fastcall SoundexSimilar(const AnsiString AText, const AnsiString AOther, TSoundexLength ALength = (TSoundexLength)(0x4));
extern PACKAGE int __fastcall SoundexCompare(const AnsiString AText, const AnsiString AOther, TSoundexLength ALength = (TSoundexLength)(0x4));
extern PACKAGE bool __fastcall SoundexProc(const AnsiString AText, const AnsiString AOther);

}	/* namespace Strutils */
using namespace Strutils;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StrUtils
