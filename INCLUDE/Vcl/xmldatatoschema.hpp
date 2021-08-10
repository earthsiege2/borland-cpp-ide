// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XMLDataToSchema.pas' rev: 6.00

#ifndef XMLDataToSchemaHPP
#define XMLDataToSchemaHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLSchema.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xmldatatoschema
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TXMLDataImporter;
class PASCALIMPLEMENTATION TXMLDataImporter : public Xmlschema::TXMLSchemaTranslator 
{
	typedef Xmlschema::TXMLSchemaTranslator inherited;
	
private:
	Xmlintf::_di_IXMLDocument FXMLDoc;
	
protected:
	WideString __fastcall AddComplexType(const Xmlintf::_di_IXMLNode Node);
	WideString __fastcall GetDataType(const Xmlintf::_di_IXMLNode Node);
	bool __fastcall IsComplexType(const Xmlintf::_di_IXMLNode Node);
	virtual void __fastcall Translate(const WideString FileName, const Xmlschema::_di_IXMLSchemaDef SchemaDef);
	void __fastcall ValidateExistingType(const Xmlschema::_di_IXMLComplexTypeDef ExistingType, const Xmlintf::_di_IXMLNode Node);
	__property Xmlintf::_di_IXMLDocument XMLDoc = {read=FXMLDoc};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TXMLDataImporter(void) : Xmlschema::TXMLSchemaTranslator() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLDataImporter(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define SXMLDataExtension ".xml"

}	/* namespace Xmldatatoschema */
using namespace Xmldatatoschema;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XMLDataToSchema
