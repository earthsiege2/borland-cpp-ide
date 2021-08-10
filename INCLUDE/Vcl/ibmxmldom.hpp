// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ibmxmldom.pas' rev: 6.00

#ifndef ibmxmldomHPP
#define ibmxmldomHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <xmldom.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibmxmldom
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBMDOMImplementationFactory;
class PASCALIMPLEMENTATION TIBMDOMImplementationFactory : public Xmldom::TDOMVendor 
{
	typedef Xmldom::TDOMVendor inherited;
	
private:
	int FLibHandle;
	
public:
	__fastcall virtual ~TIBMDOMImplementationFactory(void);
	virtual Xmldom::_di_IDOMImplementation __fastcall DOMImplementation();
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIBMDOMImplementationFactory(void) : Xmldom::TDOMVendor() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TIBMDOMImplementationFactory* IBMXML_DOM;

}	/* namespace Ibmxmldom */
using namespace Ibmxmldom;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ibmxmldom
