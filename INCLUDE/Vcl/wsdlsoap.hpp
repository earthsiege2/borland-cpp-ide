// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WSDLSOAP.pas' rev: 6.00

#ifndef WSDLSOAPHPP
#define WSDLSOAPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <InvokeRegistry.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Wsdlsoap
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TWSDLSOAPPort;
class PASCALIMPLEMENTATION TWSDLSOAPPort : public Invokeregistry::TRemotable 
{
	typedef Invokeregistry::TRemotable inherited;
	
private:
	WideString FPortName;
	DynamicArray<WideString >  FAddresses;
	
__published:
	__property WideString PortName = {read=FPortName, write=FPortName};
	__property TWideStringDynArray Addresses = {read=FAddresses, write=FAddresses};
public:
	#pragma option push -w-inl
	/* TRemotable.Create */ inline __fastcall virtual TWSDLSOAPPort(void) : Invokeregistry::TRemotable() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TRemotable.Destroy */ inline __fastcall virtual ~TWSDLSOAPPort(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TWSDLSOAPPort* >  TWSDLSOAPPortArray;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Wsdlsoap */
using namespace Wsdlsoap;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WSDLSOAP
