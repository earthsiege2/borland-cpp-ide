// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdHeaderList.pas' rev: 6.00

#ifndef IdHeaderListHPP
#define IdHeaderListHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idheaderlist
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHeaderList;
class PASCALIMPLEMENTATION TIdHeaderList : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
protected:
	AnsiString FNameValueSeparator;
	bool FCaseSensitive;
	bool FUnfoldLines;
	bool FFoldLines;
	int FFoldLinesLength;
	void __fastcall DeleteFoldedLines(int Index);
	Classes::TStringList* __fastcall FoldLine(AnsiString AString);
	void __fastcall FoldAndInsert(AnsiString AString, int Index);
	HIDESBASE AnsiString __fastcall GetName(int Index);
	HIDESBASE AnsiString __fastcall GetValue(const AnsiString Name);
	HIDESBASE void __fastcall SetValue(const AnsiString Name, const AnsiString Value);
	AnsiString __fastcall GetValueFromLine(int ALine);
	AnsiString __fastcall GetNameFromLine(int ALine);
	
public:
	__fastcall TIdHeaderList(void);
	void __fastcall Extract(const AnsiString AName, Classes::TStrings* ADest);
	HIDESBASE int __fastcall IndexOfName(const AnsiString Name);
	__property AnsiString Names[int Index] = {read=GetName};
	__property AnsiString Values[AnsiString Name] = {read=GetValue, write=SetValue};
	__property AnsiString NameValueSeparator = {read=FNameValueSeparator, write=FNameValueSeparator};
	__property bool CaseSensitive = {read=FCaseSensitive, write=FCaseSensitive, nodefault};
	__property bool UnfoldLines = {read=FUnfoldLines, write=FUnfoldLines, nodefault};
	__property bool FoldLines = {read=FFoldLines, write=FFoldLines, nodefault};
	__property int FoldLength = {read=FFoldLinesLength, write=FFoldLinesLength, nodefault};
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TIdHeaderList(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idheaderlist */
using namespace Idheaderlist;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdHeaderList
