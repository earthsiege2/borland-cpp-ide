// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebServExp.pas' rev: 6.00

#ifndef WebServExpHPP
#define WebServExpHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLSchemaTags.hpp>	// Pascal unit
#include <WSDLBind.hpp>	// Pascal unit
#include <WSDLIntf.hpp>	// Pascal unit
#include <XMLSchema.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <IntfInfo.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webservexp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum ArgumentType { argIn, argOut, argInOut, argReturn };
#pragma option pop

#pragma pack(push, 4)
struct TSchemaType
{
	WideString TypeName;
	WideString NameSpace;
	Typinfo::TTypeInfo *TypeInfo;
	WideString NSPrefix;
	bool XSGenerated;
} ;
#pragma pack(pop)

typedef DynamicArray<TSchemaType >  TSchemaTypeArray;

class DELPHICLASS TWebServExp;
class PASCALIMPLEMENTATION TWebServExp : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Wsdlbind::_di_IDefinition Definition;
	Classes::TStringList* ComplexTypeList;
	bool bHasComplexTypes;
	WideString FServiceAddress;
	Wsdlintf::TBindingType FBindingType;
	Wsdlintf::TWSDLElements FWSDLElements;
	Wsdlintf::TWideStrings* FImportNames;
	Wsdlintf::TWideStrings* FImportLocation;
	bool FArrayAsComplexContent;
	DynamicArray<TSchemaType >  SchemaArray;
	WideString FTargetNameSpace;
	void __fastcall GenerateWSDL(const Intfinfo::TIntfMetaData &IntfMD, Wsdlbind::_di_IWSDLDocument WSDLDoc, const WideString * PortNames, const int PortNames_Size, const WideString * Locations, const int Locations_Size);
	void __fastcall GenerateNestedArraySchema(Xmlschema::_di_IXMLSchemaDef SchemaDef, Xmlschema::_di_IXMLComplexTypeDef ComplexType, const Typinfo::PTypeInfo ObjectTypeInfo, int &Dimension, WideString Namespace);
	void __fastcall AddImports(const Intfinfo::TIntfMetaData &IntfMD, Wsdlbind::_di_IWSDLDocument WSDLDoc);
	void __fastcall AddTypes(const Intfinfo::TIntfMetaData &IntfMD, Wsdlbind::_di_IWSDLDocument WSDLDoc);
	void __fastcall AddMessages(const Intfinfo::TIntfMetaData &IntfMD, Wsdlbind::_di_IWSDLDocument WSDLDoc);
	void __fastcall AddPortTypes(const Intfinfo::TIntfMetaData &IntfMD, Wsdlbind::_di_IWSDLDocument WSDLDoc);
	void __fastcall AddBinding(const Intfinfo::TIntfMetaData &IntfMD, Wsdlbind::_di_IWSDLDocument WSDLDoc);
	void __fastcall AddServices(const Intfinfo::TIntfMetaData &IntfMD, Wsdlbind::_di_IWSDLDocument WSDLDoc, const WideString * PortNames, const int PortNames_Size, const WideString * Locations, const int Locations_Size);
	AnsiString __fastcall GetXMLSchemaType(const Typinfo::PTypeInfo ParamTypeInfo);
	WideString __fastcall GetXMLSchemaTypeName(const Typinfo::PTypeInfo ParamTypeInfo);
	bool __fastcall IsComplexType(const Typinfo::TTypeKind ParamType);
	void __fastcall SetBindingType(const Wsdlintf::TBindingType Value);
	void __fastcall SetServiceAddress(const WideString Value);
	WideString __fastcall GetImportNamespace(const int Index);
	void __fastcall SetImportNamespace(const int Index, const WideString Value);
	WideString __fastcall GetImportLocation(const int Index);
	void __fastcall SetImportLocation(const int Index, const WideString Value);
	void __fastcall SetArrayType(const bool Value);
	WideString __fastcall GetPrefixForURI(Xmlschema::_di_IXMLSchemaDef SchemaDef, WideString URI)/* overload */;
	WideString __fastcall GetPrefixForURI(Wsdlbind::_di_IDefinition Def, WideString URI)/* overload */;
	WideString __fastcall GetPrefixForTypeInfo(const Typinfo::PTypeInfo ObjectTypeInfo)/* overload */;
	WideString __fastcall AddNamespaceURI(Xmlintf::_di_IXMLNode RootNode, WideString URI);
	WideString __fastcall GetNodeNameForURI(Xmlschema::_di_IXMLSchemaDef SchemaDef, WideString URI);
	void __fastcall GenerateArraySchema(Xmlschema::_di_IXMLSchemaDef SchemaDef, const Typinfo::PTypeInfo ObjectTypeInfo, WideString Namespace);
	void __fastcall GenerateEnumSchema(Xmlschema::_di_IXMLSchemaDef SchemaDef, const Typinfo::PTypeInfo ObjectTypeInfo, WideString Namespace);
	void __fastcall GenerateClassSchema(Xmlschema::_di_IXMLSchemaDef SchemaDef, const Typinfo::PTypeInfo ObjectTypeInfo, const Typinfo::PTypeInfo ParentInfo, WideString Namespace);
	void __fastcall GenerateDerivedClassSchema(Xmlschema::_di_IXMLSchemaDef SchemaDef, const Typinfo::PTypeInfo ParentTypeInfo, WideString Namespace);
	void __fastcall GetAllSchemaTypes(const Intfinfo::TIntfMetaData &IntfMD);
	void __fastcall GetSchemaTypes(const Typinfo::PTypeInfo ObjectTypeInfo, const Typinfo::PTypeInfo ParentInfo);
	bool __fastcall FindOrAddSchema(const Typinfo::PTypeInfo ObjectTypeInfo, const AnsiString TnsURI);
	void __fastcall GetClassSchema(const Typinfo::PTypeInfo ObjectTypeInfo, const Typinfo::PTypeInfo ParentInfo);
	void __fastcall GetDerivedClassSchema(const Typinfo::PTypeInfo ParentTypeInfo);
	bool __fastcall IsSchemaGenerated(const Typinfo::PTypeInfo ObjectTypeInfo, const WideString TnsURI);
	void __fastcall GetArraySchema(const Typinfo::PTypeInfo ObjectTypeInfo);
	
public:
	__fastcall TWebServExp(void);
	__fastcall virtual ~TWebServExp(void);
	void __fastcall GetWSDLForInterface(const void * IntfTypeInfo, Wsdlbind::_di_IWSDLDocument WSDLDoc, const WideString * PortNames, const int PortNames_Size, const WideString * Locations, const int Locations_Size);
	void __fastcall GenerateXMLSchema(Xmlschema::_di_IXMLSchemaDef SchemaDef, const Typinfo::PTypeInfo ObjectTypeInfo, const Typinfo::PTypeInfo ParentInfo, WideString Namespace);
	__property WideString ImportNames[int Index] = {read=GetImportNamespace, write=SetImportNamespace};
	__property WideString ImportLocations[int Index] = {read=GetImportLocation, write=SetImportLocation};
	__property WideString TargetNameSpace = {read=FTargetNameSpace, write=FTargetNameSpace};
	
__published:
	__property bool ArrayAsComplexContent = {read=FArrayAsComplexContent, write=SetArrayType, nodefault};
	__property Wsdlintf::TBindingType BindingType = {read=FBindingType, write=SetBindingType, nodefault};
	__property WideString ServiceAddress = {read=FServiceAddress, write=SetServiceAddress};
	__property Wsdlintf::TWSDLElements WSDLElements = {read=FWSDLElements, write=FWSDLElements, default=1};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Webservexp */
using namespace Webservexp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebServExp
