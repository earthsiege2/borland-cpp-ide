// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'HTTPUtil.pas' rev: 6.00

#ifndef HTTPUtilHPP
#define HTTPUtilHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Httputil
{
//-- type declarations -------------------------------------------------------
__interface IStringTokenizer;
typedef System::DelphiInterface<IStringTokenizer> _di_IStringTokenizer;
__interface INTERFACE_UUID("{8C216E9D-984E-4E38-893F-0A222AC547DA}") IStringTokenizer  : public IInterface 
{
	
public:
	virtual int __fastcall getTokenCounts(void) = 0 ;
	virtual bool __fastcall hasMoreTokens(void) = 0 ;
	virtual WideString __fastcall nextToken(void) = 0 ;
	__property int countTokens = {read=getTokenCounts};
};

__interface IStreamLoader;
typedef System::DelphiInterface<IStreamLoader> _di_IStreamLoader;
__interface INTERFACE_UUID("{395CDFB2-1D10-4A37-AC16-393D569676F0}") IStreamLoader  : public IInterface 
{
	
public:
	virtual void __fastcall Load(const WideString WSDLFileName, Classes::TMemoryStream* Stream) = 0 ;
	virtual AnsiString __fastcall GetProxy(void) = 0 ;
	virtual void __fastcall SetProxy(const AnsiString Proxy) = 0 ;
	virtual AnsiString __fastcall GetUserName(void) = 0 ;
	virtual void __fastcall SetUserName(const AnsiString UserName) = 0 ;
	virtual AnsiString __fastcall GetPassword(void) = 0 ;
	virtual void __fastcall SetPassword(const AnsiString Password) = 0 ;
	__property AnsiString Proxy = {read=GetProxy, write=SetProxy};
	__property AnsiString UserName = {read=GetUserName, write=SetUserName};
	__property AnsiString Password = {read=GetPassword, write=SetPassword};
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE _di_IStreamLoader __fastcall GetDefaultStreamLoader();
extern PACKAGE bool __fastcall StartsWith(const AnsiString str, const AnsiString sub);
extern PACKAGE int __fastcall FirstDelimiter(const AnsiString delimiters, const AnsiString Str)/* overload */;
extern PACKAGE int __fastcall FirstDelimiter(const WideString delimiters, const WideString Str)/* overload */;
extern PACKAGE _di_IStringTokenizer __fastcall StringTokenizer(const AnsiString str, const AnsiString delim);
extern PACKAGE TStringDynArray __fastcall StringToStringArray(const AnsiString str, const AnsiString delim);
extern PACKAGE AnsiString __fastcall HTMLEscape(const AnsiString Str);

}	/* namespace Httputil */
using namespace Httputil;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// HTTPUtil
