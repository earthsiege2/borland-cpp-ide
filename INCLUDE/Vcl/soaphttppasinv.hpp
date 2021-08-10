// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPHTTPPasInv.pas' rev: 6.00

#ifndef SOAPHTTPPasInvHPP
#define SOAPHTTPPasInvHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SOAPHTTPDisp.hpp>	// Pascal unit
#include <SOAPPasInv.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Invoker.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soaphttppasinv
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THTTPSoapPascalInvoker;
class PASCALIMPLEMENTATION THTTPSoapPascalInvoker : public Soappasinv::TSoapPascalInvoker 
{
	typedef Soappasinv::TSoapPascalInvoker inherited;
	
public:
	virtual void __fastcall DispatchSOAP(const WideString Path, const WideString SoapAction, const Classes::TStream* Request, Classes::TStream* Response);
public:
	#pragma option push -w-inl
	/* TSoapPascalInvoker.Create */ inline __fastcall virtual THTTPSoapPascalInvoker(Classes::TComponent* AOwner) : Soappasinv::TSoapPascalInvoker(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSoapPascalInvoker.Destroy */ inline __fastcall virtual ~THTTPSoapPascalInvoker(void) { }
	#pragma option pop
	
private:
	void *__IHTTPSoapDispatch;	/* Soaphttpdisp::IHTTPSoapDispatch */
	
public:
	operator IHTTPSoapDispatch*(void) { return (IHTTPSoapDispatch*)&__IHTTPSoapDispatch; }
	
};


class DELPHICLASS THTTPSoapCppInvoker;
class PASCALIMPLEMENTATION THTTPSoapCppInvoker : public THTTPSoapPascalInvoker 
{
	typedef THTTPSoapPascalInvoker inherited;
	
public:
	#pragma option push -w-inl
	/* TSoapPascalInvoker.Create */ inline __fastcall virtual THTTPSoapCppInvoker(Classes::TComponent* AOwner) : THTTPSoapPascalInvoker(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSoapPascalInvoker.Destroy */ inline __fastcall virtual ~THTTPSoapCppInvoker(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soaphttppasinv */
using namespace Soaphttppasinv;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPHTTPPasInv
