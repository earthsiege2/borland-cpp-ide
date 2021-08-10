// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DTDSchema.pas' rev: 6.00

#ifndef DTDSchemaHPP
#define DTDSchemaHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <xmldom.hpp>	// Pascal unit
#include <XMLSchema.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dtdschema
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDTDBaseTranslator;
class PASCALIMPLEMENTATION TDTDBaseTranslator : public Xmlschema::TXMLSchemaTranslator 
{
	typedef Xmlschema::TXMLSchemaTranslator inherited;
	
private:
	Classes::TStrings* FDTDLines;
	
protected:
	__property Classes::TStrings* DTDLines = {read=FDTDLines};
	
public:
	__fastcall virtual ~TDTDBaseTranslator(void);
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TDTDBaseTranslator(void) : Xmlschema::TXMLSchemaTranslator() { }
	#pragma option pop
	
};


class DELPHICLASS TDTDImportTranslator;
class PASCALIMPLEMENTATION TDTDImportTranslator : public TDTDBaseTranslator 
{
	typedef TDTDBaseTranslator inherited;
	
protected:
	AnsiString __fastcall Expand(AnsiString Dtd, AnsiString &RootName, AnsiString SrcPath);
	void __fastcall ExtractDtdParts(AnsiString Str, AnsiString StrBeg, AnsiString StrEnd, Classes::TStrings* Parts);
	void __fastcall Parse(AnsiString Dtd);
	void __fastcall ParseAttributeDefinitions(Classes::TStrings* AttributeList);
	void __fastcall ParseAttributeDefinition(AnsiString AttrStr);
	void __fastcall ParseChildElements(Xmlschema::_di_IXMLComplexTypeDef ComplexDef, Xmlschema::_di_IXMLElementCompositors ParentCompositors, AnsiString &Str);
	void __fastcall ParseElementDefinitions(Classes::TStrings* ElementList, Classes::TStrings* ElementsWithAttributes);
	void __fastcall ParseTokens(AnsiString Str, Classes::TStrings* Tokens);
	AnsiString __fastcall PreParseChildElements(AnsiString Str, AnsiString &Suffix, AnsiString &GroupType);
	void __fastcall PreparseAttributeDefinitions(Classes::TStrings* AttributeList, Classes::TStrings* AttrDefs);
	virtual void __fastcall Translate(const WideString FileName, const Xmlschema::_di_IXMLSchemaDef SchemaDef);
public:
	#pragma option push -w-inl
	/* TDTDBaseTranslator.Destroy */ inline __fastcall virtual ~TDTDImportTranslator(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TDTDImportTranslator(void) : TDTDBaseTranslator() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define DTDExtension ".dtd"

}	/* namespace Dtdschema */
using namespace Dtdschema;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DTDSchema
