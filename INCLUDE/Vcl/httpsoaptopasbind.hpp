// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'HTTPSOAPToPasBind.pas' rev: 6.00

#ifndef HTTPSOAPToPasBindHPP
#define HTTPSOAPToPasBindHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TypInfo.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Httpsoaptopasbind
{
//-- type declarations -------------------------------------------------------
__interface IHTTPSOAPToPasBind;
typedef System::DelphiInterface<IHTTPSOAPToPasBind> _di_IHTTPSOAPToPasBind;
__interface INTERFACE_UUID("{FDA9957E-F8A1-4E46-9107-9DB7E90E0DBE}") IHTTPSOAPToPasBind  : public IInterface 
{
	
public:
	virtual bool __fastcall BindToPascalByAction(const WideString Action, TMetaClass* &AClass, Typinfo::PTypeInfo &IntfInfo, AnsiString &AMeth) = 0 ;
	virtual bool __fastcall BindToPascalByPath(AnsiString Path, TMetaClass* &AClass, Typinfo::PTypeInfo &IntfInfo, AnsiString &AMeth) = 0 ;
};

class DELPHICLASS THTTPSOAPToPasBind;
class PASCALIMPLEMENTATION THTTPSOAPToPasBind : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	virtual bool __fastcall BindToPascalByAction(const WideString Action, TMetaClass* &AClass, Typinfo::PTypeInfo &IntfInfo, AnsiString &AMeth);
	virtual bool __fastcall BindToPascalByPath(AnsiString Path, TMetaClass* &AClass, Typinfo::PTypeInfo &IntfInfo, AnsiString &AMeth);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall THTTPSOAPToPasBind(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~THTTPSOAPToPasBind(void) { }
	#pragma option pop
	
private:
	void *__IHTTPSOAPToPasBind;	/* Httpsoaptopasbind::IHTTPSOAPToPasBind */
	
public:
	operator IHTTPSOAPToPasBind*(void) { return (IHTTPSOAPToPasBind*)&__IHTTPSOAPToPasBind; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Httpsoaptopasbind */
using namespace Httpsoaptopasbind;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// HTTPSOAPToPasBind
