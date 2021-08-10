// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMExtstr.pas' rev: 5.00

#ifndef NMExtstrHPP
#define NMExtstrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmextstr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TExStringList;
class PASCALIMPLEMENTATION TExStringList : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
protected:
	HIDESBASE int __fastcall IndexOfName(const AnsiString Name);
	HIDESBASE AnsiString __fastcall GetValue(const AnsiString Name);
	HIDESBASE void __fastcall SetValue(const AnsiString Name, const AnsiString Value);
	
public:
	__property AnsiString Values[AnsiString Name] = {read=GetValue, write=SetValue};
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TExStringList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TExStringList(void) : Classes::TStringList() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Nmextstr */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmextstr;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMExtstr
