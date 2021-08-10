// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VCLCom.pas' rev: 6.00

#ifndef VCLComHPP
#define VCLComHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vclcom
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TComponentFactory;
class PASCALIMPLEMENTATION TComponentFactory : public TAutoObjectFactory 
{
	typedef TAutoObjectFactory inherited;
	
protected:
	HIDESBASE HRESULT __stdcall CreateInstance(const System::_di_IInterface UnkOuter, const GUID &IID, /* out */ void *Obj);
	
public:
	__fastcall TComponentFactory(Comobj::TComServerObject* ComServer, TMetaClass* ComponentClass, const GUID &ClassID, Comobj::TClassInstancing Instancing, Comobj::TThreadingModel ThreadingModel);
	virtual TComObject* __fastcall CreateComObject(const System::_di_IInterface Controller);
	virtual void __fastcall UpdateRegistry(bool Register);
public:
	#pragma option push -w-inl
	/* TComObjectFactory.Destroy */ inline __fastcall virtual ~TComponentFactory(void) { }
	#pragma option pop
	
private:
	void *__IClassFactory;	/* IClassFactory */
	
public:
	operator IClassFactory*(void) { return (IClassFactory*)&__IClassFactory; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Vclcom */
using namespace Vclcom;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VCLCom
