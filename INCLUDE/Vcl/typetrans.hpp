// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TypeTrans.pas' rev: 6.00

#ifndef TypeTransHPP
#define TypeTransHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <InvokeRegistry.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <IntfInfo.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Typetrans
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTypeTranslator;
class PASCALIMPLEMENTATION TTypeTranslator : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	__fastcall TTypeTranslator(void);
	__fastcall virtual ~TTypeTranslator(void);
	bool __fastcall CastSoapToNative(Typinfo::PTypeInfo Info, WideString SoapData, void * NatData, bool IsNull);
	void __fastcall CastNativeToSoap(Typinfo::PTypeInfo Info, WideString &SoapData, void * NatData, bool &IsNull);
	void __fastcall CastSoapToVariant(Typinfo::PTypeInfo SoapInfo, WideString SoapData, void * NatData)/* overload */;
	Variant __fastcall CastSoapToVariant(Typinfo::PTypeInfo SoapInfo, WideString SoapData)/* overload */;
	void __fastcall Base64ToVar(void * NatData, WideString SoapData)/* overload */;
	void __fastcall Base64ToVar(Variant &V, WideString SoapData)/* overload */;
};


class DELPHICLASS ETypeTransException;
class PASCALIMPLEMENTATION ETypeTransException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ETypeTransException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ETypeTransException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ETypeTransException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ETypeTransException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ETypeTransException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ETypeTransException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ETypeTransException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ETypeTransException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ETypeTransException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TTypeTranslator* TypeTranslator;
extern PACKAGE int __fastcall GetEnumValueEx(Typinfo::PTypeInfo TypInfo, const AnsiString Name);
extern PACKAGE Extended __fastcall StrToFloatEx(const AnsiString S);
extern PACKAGE AnsiString __fastcall FloatToStrEx(Extended Value);

}	/* namespace Typetrans */
using namespace Typetrans;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TypeTrans
