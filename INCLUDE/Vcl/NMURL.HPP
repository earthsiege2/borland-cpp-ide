// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMURL.pas' rev: 5.00

#ifndef NMURLHPP
#define NMURLHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmurl
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TOnErrorEvent)(System::TObject* Sender, AnsiString Operation, AnsiString 
	ErrMsg);

class DELPHICLASS TNMURL;
class PASCALIMPLEMENTATION TNMURL : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	AnsiString FInputString;
	TOnErrorEvent FOnError;
	AnsiString __fastcall GetEncodeString();
	AnsiString __fastcall GetDecodeString();
	AnsiString __fastcall URLDecode(const AnsiString InString);
	AnsiString __fastcall URLEncode(const AnsiString InString);
	
public:
	__fastcall virtual TNMURL(Classes::TComponent* AOwner);
	__fastcall virtual ~TNMURL(void);
	__property AnsiString Encode = {read=GetEncodeString};
	__property AnsiString Decode = {read=GetDecodeString};
	
__published:
	__property AnsiString InputString = {read=FInputString, write=FInputString};
	__property TOnErrorEvent OnError = {read=FOnError, write=FOnError};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Nmurl */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmurl;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMURL
