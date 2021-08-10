// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPEnv.pas' rev: 6.00

#ifndef SOAPEnvHPP
#define SOAPEnvHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <OPConvert.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soapenv
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSoapEnvelope;
class PASCALIMPLEMENTATION TSoapEnvelope : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Xmlintf::_di_IXMLNode __fastcall MakeEnvelope(Xmlintf::_di_IXMLDocument Doc, Opconvert::TSOAPConvertOptions Options);
	Xmlintf::_di_IXMLNode __fastcall MakeHeader(Xmlintf::_di_IXMLNode ParentNode);
	Xmlintf::_di_IXMLNode __fastcall MakeBody(Xmlintf::_di_IXMLNode ParentNode);
	Xmlintf::_di_IXMLNode __fastcall MakeFault(Xmlintf::_di_IXMLNode ParentNode);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSoapEnvelope(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSoapEnvelope(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soapenv */
using namespace Soapenv;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPEnv
