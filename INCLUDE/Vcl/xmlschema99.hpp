// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XMLSchema99.pas' rev: 6.00

#ifndef XMLSchema99HPP
#define XMLSchema99HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <XMLSchema.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xmlschema99
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TXMLSchema1999TranslatorFactory;
class PASCALIMPLEMENTATION TXMLSchema1999TranslatorFactory : public Xmlschema::TXMLSchemaTranslatorFactory 
{
	typedef Xmlschema::TXMLSchemaTranslatorFactory inherited;
	
protected:
	virtual bool __fastcall CanImportFile(const WideString FileName);
public:
	#pragma option push -w-inl
	/* TXMLSchemaTranslatorFactory.Create */ inline __fastcall TXMLSchema1999TranslatorFactory(TMetaClass* ImportClass, TMetaClass* ExportClass, const WideString Extension, const WideString Description) : Xmlschema::TXMLSchemaTranslatorFactory(ImportClass, ExportClass, Extension, Description) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLSchema1999TranslatorFactory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLSchema1999Translator;
class PASCALIMPLEMENTATION TXMLSchema1999Translator : public Xmlschema::TXMLSchemaTranslator 
{
	typedef Xmlschema::TXMLSchemaTranslator inherited;
	
private:
	Xmlschema::_di_IXMLSchemaDef FOldSchema;
	
protected:
	void __fastcall CopyAttrNodes(const Xmlintf::_di_IXMLNode SourceNode, const Xmlintf::_di_IXMLNode DestNode);
	void __fastcall CopyChildNodes(const Xmlintf::_di_IXMLNode SourceNode, const Xmlintf::_di_IXMLNode DestNode);
	void __fastcall CopyComplexType(const Xmlschema::_di_IXMLComplexTypeDef ComplexTypeDef, const Xmlintf::_di_IXMLNode DestNode);
	void __fastcall CopySimpleType(const Xmlschema::_di_IXMLSimpleTypeDef SimpleTypeDef, const Xmlintf::_di_IXMLNode DestNode);
	__property Xmlschema::_di_IXMLSchemaDef OldSchema = {read=FOldSchema};
	
public:
	virtual void __fastcall Translate(const WideString FileName, const Xmlschema::_di_IXMLSchemaDef SchemaDef);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TXMLSchema1999Translator(void) : Xmlschema::TXMLSchemaTranslator() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLSchema1999Translator(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLComplexTypeDef99;
class PASCALIMPLEMENTATION TXMLComplexTypeDef99 : public Xmlschema::TXMLComplexTypeDef 
{
	typedef Xmlschema::TXMLComplexTypeDef inherited;
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLComplexTypeDef99(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmlschema::TXMLComplexTypeDef(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLComplexTypeDef99(Xmldoc::TXMLNode* HostNode) : Xmlschema::TXMLComplexTypeDef(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLComplexTypeDef99(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLSchemaDoc99;
class PASCALIMPLEMENTATION TXMLSchemaDoc99 : public Xmlschema::TXMLSchemaDoc 
{
	typedef Xmlschema::TXMLSchemaDoc inherited;
	
protected:
	virtual TMetaClass* __fastcall GetChildNodeClass(const Xmldom::_di_IDOMNode Node);
	virtual void __fastcall CheckSchemaVersion(void);
	DYNAMIC void __fastcall LoadData(void);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLDocument.Create */ inline __fastcall TXMLSchemaDoc99(const WideString AFileName)/* overload */ : Xmlschema::TXMLSchemaDoc(AFileName) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLDocument.Destroy */ inline __fastcall virtual ~TXMLSchemaDoc99(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Xmlschema99 */
using namespace Xmlschema99;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XMLSchema99
