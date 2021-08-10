// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XMLSchema.pas' rev: 6.00

#ifndef XMLSchemaHPP
#define XMLSchemaHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLIntf.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Xmlschema {
using Xmlintf::IXMLDocument;
};

namespace Xmlschema
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ESchemaError;
class PASCALIMPLEMENTATION ESchemaError : public Xmlintf::EXMLDocError 
{
	typedef Xmlintf::EXMLDocError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESchemaError(const AnsiString Msg) : Xmlintf::EXMLDocError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESchemaError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Xmlintf::EXMLDocError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESchemaError(int Ident)/* overload */ : Xmlintf::EXMLDocError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESchemaError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Xmlintf::EXMLDocError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESchemaError(const AnsiString Msg, int AHelpContext) : Xmlintf::EXMLDocError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESchemaError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Xmlintf::EXMLDocError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESchemaError(int Ident, int AHelpContext)/* overload */ : Xmlintf::EXMLDocError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESchemaError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Xmlintf::EXMLDocError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESchemaError(void) { }
	#pragma option pop
	
};


class DELPHICLASS ESchemaValidation;
class PASCALIMPLEMENTATION ESchemaValidation : public ESchemaError 
{
	typedef ESchemaError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESchemaValidation(const AnsiString Msg) : ESchemaError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESchemaValidation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : ESchemaError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESchemaValidation(int Ident)/* overload */ : ESchemaError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESchemaValidation(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : ESchemaError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESchemaValidation(const AnsiString Msg, int AHelpContext) : ESchemaError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESchemaValidation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : ESchemaError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESchemaValidation(int Ident, int AHelpContext)/* overload */ : ESchemaError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESchemaValidation(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : ESchemaError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESchemaValidation(void) { }
	#pragma option pop
	
};


class DELPHICLASS ESchemaParse;
class PASCALIMPLEMENTATION ESchemaParse : public ESchemaError 
{
	typedef ESchemaError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESchemaParse(const AnsiString Msg) : ESchemaError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESchemaParse(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : ESchemaError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESchemaParse(int Ident)/* overload */ : ESchemaError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESchemaParse(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : ESchemaError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESchemaParse(const AnsiString Msg, int AHelpContext) : ESchemaError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESchemaParse(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : ESchemaError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESchemaParse(int Ident, int AHelpContext)/* overload */ : ESchemaError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESchemaParse(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : ESchemaError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESchemaParse(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFormChoice { fcQualified, fcUnqualified };
#pragma option pop

#pragma option push -b-
enum TCompositorType { ctAll, ctChoice, ctSequence };
#pragma option pop

#pragma option push -b-
enum TContentModel { cmALL, cmChoice, cmSequence, cmGroupRef, cmEmpty };
#pragma option pop

#pragma option push -b-
enum TDerivationMethod { dmNone, dmComplexExtension, dmComplexRestriction, dmSimpleExtension, dmSimpleRestriction };
#pragma option pop

__interface IXMLElementDefList;
typedef System::DelphiInterface<IXMLElementDefList> _di_IXMLElementDefList;
__interface IXMLElementDef;
typedef System::DelphiInterface<IXMLElementDef> _di_IXMLElementDef;
__interface INTERFACE_UUID("{BA009DE0-8372-11D4-8E37-00C0F056BC66}") IXMLElementDefList  : public IInterfaceList 
{
	
public:
	_di_IXMLElementDef operator[](int Index) { return ElementDefs[Index]; }
	
public:
	virtual _di_IXMLElementDef __fastcall GetElementDef(const int Index) = 0 ;
	__property _di_IXMLElementDef ElementDefs[int Index] = {read=GetElementDef/*, default*/};
};

__interface IXMLAttributeDefList;
typedef System::DelphiInterface<IXMLAttributeDefList> _di_IXMLAttributeDefList;
__interface IXMLAttributeDef;
typedef System::DelphiInterface<IXMLAttributeDef> _di_IXMLAttributeDef;
__interface INTERFACE_UUID("{6C15F622-846C-11D4-8E37-00C0F056BC66}") IXMLAttributeDefList  : public IInterfaceList 
{
	
public:
	_di_IXMLAttributeDef operator[](int Index) { return AttributeDefs[Index]; }
	
public:
	virtual _di_IXMLAttributeDef __fastcall GetAttributeDef(const int Index) = 0 ;
	__property _di_IXMLAttributeDef AttributeDefs[int Index] = {read=GetAttributeDef/*, default*/};
};

__interface IXMLSchemaNode;
typedef System::DelphiInterface<IXMLSchemaNode> _di_IXMLSchemaNode;
__interface IXMLSchemaDef;
typedef System::DelphiInterface<IXMLSchemaDef> _di_IXMLSchemaDef;
__interface INTERFACE_UUID("{2DF0AEF7-6A69-45DB-8F4D-C00D6BE3F0AA}") IXMLSchemaNode  : public IXMLNode 
{
	
public:
	virtual _di_IXMLSchemaDef __fastcall GetSchemaDef(void) = 0 ;
	__property _di_IXMLSchemaDef SchemaDef = {read=GetSchemaDef};
};

__interface IXMLAnnotatedItem;
typedef System::DelphiInterface<IXMLAnnotatedItem> _di_IXMLAnnotatedItem;
__interface IXMLAppInfoCollection;
typedef System::DelphiInterface<IXMLAppInfoCollection> _di_IXMLAppInfoCollection;
__interface IXMLDocumentationCollection;
typedef System::DelphiInterface<IXMLDocumentationCollection> _di_IXMLDocumentationCollection;
__interface INTERFACE_UUID("{7EDFC120-4C43-11D4-83DA-00C04F60B2DD}") IXMLAnnotatedItem  : public IXMLSchemaNode 
{
	
public:
	virtual _di_IXMLAppInfoCollection __fastcall GetAppInfoCollection(void) = 0 ;
	virtual _di_IXMLDocumentationCollection __fastcall GetDocumentationCollection(void) = 0 ;
	virtual bool __fastcall HasAnnotation(void) = 0 ;
	virtual void __fastcall RemoveAnnotation(bool OnlyIfEmpty = true) = 0 ;
	__property _di_IXMLAppInfoCollection AppInfo = {read=GetAppInfoCollection};
	__property _di_IXMLDocumentationCollection Documentation = {read=GetDocumentationCollection};
};

__interface IXMLSchemaDocRef;
typedef System::DelphiInterface<IXMLSchemaDocRef> _di_IXMLSchemaDocRef;
__interface INTERFACE_UUID("{501411A9-74B8-46AF-A145-12E3A46A7DA4}") IXMLSchemaDocRef  : public IXMLAnnotatedItem 
{
	
public:
	virtual WideString __fastcall GetSchemaLocation(void) = 0 ;
	virtual _di_IXMLSchemaDef __fastcall GetSchemaRef(void) = 0 ;
	virtual void __fastcall SetSchemaLocation(const WideString Value) = 0 ;
	__property _di_IXMLSchemaDef SchemaRef = {read=GetSchemaRef};
	__property WideString SchemaLocation = {read=GetSchemaLocation, write=SetSchemaLocation};
};

__interface IXMLSchemaImport;
typedef System::DelphiInterface<IXMLSchemaImport> _di_IXMLSchemaImport;
__interface INTERFACE_UUID("{C15D7ABA-CAB6-4230-A732-BFC3C95F7B1A}") IXMLSchemaImport  : public IXMLSchemaDocRef 
{
	
};

__interface IXMLSchemaInclude;
typedef System::DelphiInterface<IXMLSchemaInclude> _di_IXMLSchemaInclude;
__interface INTERFACE_UUID("{9C3A2E64-8CA5-403D-B557-1E28A9570720}") IXMLSchemaInclude  : public IXMLSchemaDocRef 
{
	
};

__interface IXMLSchemaItem;
typedef System::DelphiInterface<IXMLSchemaItem> _di_IXMLSchemaItem;
__interface INTERFACE_UUID("{7EDFC120-4C43-11D4-83DA-00C04F60B2DD}") IXMLSchemaItem  : public IXMLAnnotatedItem 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual void __fastcall SetName(const WideString Value) = 0 ;
	virtual bool __fastcall IsGlobal(void) = 0 ;
	virtual WideString __fastcall ItemLocalName(void) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
};

__interface IXMLTypeDef;
typedef System::DelphiInterface<IXMLTypeDef> _di_IXMLTypeDef;
__interface IXMLEnumerationCollection;
typedef System::DelphiInterface<IXMLEnumerationCollection> _di_IXMLEnumerationCollection;
__interface INTERFACE_UUID("{7EDFC121-4C43-11D4-83DA-00C04F60B2DD}") IXMLTypeDef  : public IXMLSchemaItem 
{
	
public:
	virtual _di_IXMLTypeDef __fastcall GetBaseType(void) = 0 ;
	virtual WideString __fastcall GetBaseTypeName(void) = 0 ;
	virtual Variant __fastcall GetBounded(void) = 0 ;
	virtual Variant __fastcall GetCardinality(void) = 0 ;
	virtual _di_IXMLEnumerationCollection __fastcall GetEnumerations(void) = 0 ;
	virtual Variant __fastcall GetFractionalDigits(void) = 0 ;
	virtual Variant __fastcall GetLength(void) = 0 ;
	virtual Variant __fastcall GetMaxExclusive(void) = 0 ;
	virtual Variant __fastcall GetMaxInclusive(void) = 0 ;
	virtual Variant __fastcall GetMaxLength(void) = 0 ;
	virtual Variant __fastcall GetMinExclusive(void) = 0 ;
	virtual Variant __fastcall GetMinInclusive(void) = 0 ;
	virtual Variant __fastcall GetMinLength(void) = 0 ;
	virtual Variant __fastcall GetNumeric(void) = 0 ;
	virtual Variant __fastcall GetOrdered(void) = 0 ;
	virtual Variant __fastcall GetPattern(void) = 0 ;
	virtual Variant __fastcall GetTotalDigits(void) = 0 ;
	virtual Variant __fastcall GetWhitespace(void) = 0 ;
	virtual void __fastcall SetBaseTypeName(const WideString Value) = 0 ;
	virtual void __fastcall SetBounded(const Variant &Value) = 0 ;
	virtual void __fastcall SetCardinality(const Variant &Value) = 0 ;
	virtual void __fastcall SetFractionalDigits(const Variant &Value) = 0 ;
	virtual void __fastcall SetLength(const Variant &Value) = 0 ;
	virtual void __fastcall SetMaxExclusive(const Variant &Value) = 0 ;
	virtual void __fastcall SetMaxInclusive(const Variant &Value) = 0 ;
	virtual void __fastcall SetMaxLength(const Variant &Value) = 0 ;
	virtual void __fastcall SetMinExclusive(const Variant &Value) = 0 ;
	virtual void __fastcall SetMinInclusive(const Variant &Value) = 0 ;
	virtual void __fastcall SetMinLength(const Variant &Value) = 0 ;
	virtual void __fastcall SetNumeric(const Variant &Value) = 0 ;
	virtual void __fastcall SetOrdered(const Variant &Value) = 0 ;
	virtual void __fastcall SetPattern(const Variant &Value) = 0 ;
	virtual void __fastcall SetTotalDigits(const Variant &Value) = 0 ;
	virtual void __fastcall SetWhitespace(const Variant &Value) = 0 ;
	virtual bool __fastcall IsAnonymous(void) = 0 ;
	virtual bool __fastcall IsComplex(void) = 0 ;
	__property _di_IXMLTypeDef BaseType = {read=GetBaseType};
	__property WideString BaseTypeName = {read=GetBaseTypeName, write=SetBaseTypeName};
	__property _di_IXMLEnumerationCollection Enumerations = {read=GetEnumerations};
	__property Variant Ordered = {read=GetOrdered, write=SetOrdered};
	__property Variant Bounded = {read=GetBounded, write=SetBounded};
	__property Variant Cardinality = {read=GetCardinality, write=SetCardinality};
	__property Variant Numeric = {read=GetNumeric, write=SetNumeric};
	__property Variant Length = {read=GetLength, write=SetLength};
	__property Variant MinLength = {read=GetMinLength, write=SetMinLength};
	__property Variant MaxLength = {read=GetMaxLength, write=SetMaxLength};
	__property Variant Pattern = {read=GetPattern, write=SetPattern};
	__property Variant Whitespace = {read=GetWhitespace, write=SetWhitespace};
	__property Variant MaxInclusive = {read=GetMaxInclusive, write=SetMaxInclusive};
	__property Variant MaxExclusive = {read=GetMaxExclusive, write=SetMaxExclusive};
	__property Variant MinInclusive = {read=GetMinInclusive, write=SetMinInclusive};
	__property Variant MinExclusive = {read=GetMinExclusive, write=SetMinExclusive};
	__property Variant TotalDigits = {read=GetTotalDigits, write=SetTotalDigits};
	__property Variant FractionalDigits = {read=GetFractionalDigits, write=SetFractionalDigits};
};

__interface IXMLTypeRestriction;
typedef System::DelphiInterface<IXMLTypeRestriction> _di_IXMLTypeRestriction;
__interface INTERFACE_UUID("{7BE665E6-9D59-4E27-AF37-587A8CCA6306}") IXMLTypeRestriction  : public IXMLSchemaNode 
{
	
public:
	virtual WideString __fastcall GetBaseName(void) = 0 ;
	virtual void __fastcall SetBaseName(const WideString Value) = 0 ;
	__property WideString BaseName = {read=GetBaseName, write=SetBaseName};
};

__interface IXMLSimpleTypeDef;
typedef System::DelphiInterface<IXMLSimpleTypeDef> _di_IXMLSimpleTypeDef;
__interface INTERFACE_UUID("{7EDFC122-4C43-11D4-83DA-00C04F60B2DD}") IXMLSimpleTypeDef  : public IXMLTypeDef 
{
	
public:
	virtual _di_IXMLTypeRestriction __fastcall GetRestrictionNode(void) = 0 ;
	virtual bool __fastcall IsBuiltInType(void) = 0 ;
	__property _di_IXMLTypeRestriction RestrictionNode = {read=GetRestrictionNode};
};

__interface IXMLBaseTypeIndicator;
typedef System::DelphiInterface<IXMLBaseTypeIndicator> _di_IXMLBaseTypeIndicator;
__interface INTERFACE_UUID("{3DD57E4A-43AC-4C12-B878-B10C7BFE19D4}") IXMLBaseTypeIndicator  : public IXMLSchemaNode 
{
	
public:
	virtual Variant __fastcall GetMixed(void) = 0 ;
	virtual void __fastcall SetMixed(const Variant &Value) = 0 ;
	__property Variant Mixed = {read=GetMixed, write=SetMixed};
};

__interface IXMLComplexTypeDef;
typedef System::DelphiInterface<IXMLComplexTypeDef> _di_IXMLComplexTypeDef;
__interface IXMLAttributeDefs;
typedef System::DelphiInterface<IXMLAttributeDefs> _di_IXMLAttributeDefs;
__interface IXMLAttributeGroups;
typedef System::DelphiInterface<IXMLAttributeGroups> _di_IXMLAttributeGroups;
__interface IXMLElementCompositor;
typedef System::DelphiInterface<IXMLElementCompositor> _di_IXMLElementCompositor;
__interface IXMLElementCompositors;
typedef System::DelphiInterface<IXMLElementCompositors> _di_IXMLElementCompositors;
__interface IXMLElementDefs;
typedef System::DelphiInterface<IXMLElementDefs> _di_IXMLElementDefs;
__interface IXMLElementGroups;
typedef System::DelphiInterface<IXMLElementGroups> _di_IXMLElementGroups;
__interface IXMLElementGroup;
typedef System::DelphiInterface<IXMLElementGroup> _di_IXMLElementGroup;
__interface INTERFACE_UUID("{7EDFC123-4C43-11D4-83DA-00C04F60B2DD}") IXMLComplexTypeDef  : public IXMLTypeDef 
{
	
public:
	virtual bool __fastcall GetAbstract(void) = 0 ;
	virtual _di_IXMLAttributeDefList __fastcall GetAttributeDefList(void) = 0 ;
	virtual _di_IXMLAttributeDefs __fastcall GetAttributeDefs(void) = 0 ;
	virtual _di_IXMLAttributeGroups __fastcall GetAttributeGroups(void) = 0 ;
	virtual _di_IXMLBaseTypeIndicator __fastcall GetBaseTypeIndicator(void) = 0 ;
	virtual _di_IXMLElementCompositor __fastcall GetCompositorNode(void) = 0 ;
	virtual _di_IXMLElementCompositors __fastcall GetCompositors(void) = 0 ;
	virtual TContentModel __fastcall GetContentModel(void) = 0 ;
	virtual TDerivationMethod __fastcall GetDerivationMethod(void) = 0 ;
	virtual _di_IXMLElementDefList __fastcall GetElementDefList(void) = 0 ;
	virtual _di_IXMLElementDefs __fastcall GetElementDefs(void) = 0 ;
	virtual _di_IXMLElementGroups __fastcall GetElementGroups(void) = 0 ;
	virtual _di_IXMLElementGroup __fastcall GetGroupRef(void) = 0 ;
	virtual void __fastcall SetAbstract(const bool Value) = 0 ;
	virtual void __fastcall SetContentModel(const TContentModel Value) = 0 ;
	virtual void __fastcall SetDerivationMethod(const TDerivationMethod Value) = 0 ;
	__property bool AbstractType = {read=GetAbstract, write=SetAbstract};
	__property _di_IXMLAttributeDefs AttributeDefs = {read=GetAttributeDefs};
	__property _di_IXMLAttributeDefList AttributeDefList = {read=GetAttributeDefList};
	__property _di_IXMLAttributeGroups AttributeGroups = {read=GetAttributeGroups};
	__property _di_IXMLBaseTypeIndicator BaseTypeIndicator = {read=GetBaseTypeIndicator};
	__property _di_IXMLElementCompositor CompositorNode = {read=GetCompositorNode};
	__property TContentModel ContentModel = {read=GetContentModel, write=SetContentModel};
	__property TDerivationMethod DerivationMethod = {read=GetDerivationMethod, write=SetDerivationMethod};
	__property _di_IXMLElementCompositors ElementCompositors = {read=GetCompositors};
	__property _di_IXMLElementDefList ElementDefList = {read=GetElementDefList};
	__property _di_IXMLElementDefs ElementDefs = {read=GetElementDefs};
	__property _di_IXMLElementGroups ElementGroups = {read=GetElementGroups};
	__property _di_IXMLElementGroup GroupRef = {read=GetGroupRef};
};

__interface IXMLSchemaRefItem;
typedef System::DelphiInterface<IXMLSchemaRefItem> _di_IXMLSchemaRefItem;
__interface IXMLSchemaItems;
typedef System::DelphiInterface<IXMLSchemaItems> _di_IXMLSchemaItems;
__interface INTERFACE_UUID("{41465201-D39A-4C39-ACBE-C3AF64F0720D}") IXMLSchemaRefItem  : public IXMLSchemaItem 
{
	
public:
	virtual WideString __fastcall GetRefName(void) = 0 ;
	virtual void __fastcall SetRefName(const WideString Value) = 0 ;
	virtual _di_IXMLSchemaItems __fastcall GlobalCollection(void) = 0 ;
	__property WideString RefName = {read=GetRefName, write=SetRefName};
};

__interface IXMLTypedSchemaItem;
typedef System::DelphiInterface<IXMLTypedSchemaItem> _di_IXMLTypedSchemaItem;
__interface INTERFACE_UUID("{75D91C7E-6DFF-44CA-91E0-34E4314AE9D4}") IXMLTypedSchemaItem  : public IXMLSchemaRefItem 
{
	
public:
	virtual _di_IXMLTypeDef __fastcall GetDataType(void) = 0 ;
	virtual WideString __fastcall GetDataTypeName(void) = 0 ;
	virtual void __fastcall SetDataType(const _di_IXMLTypeDef Value) = 0 ;
	virtual void __fastcall SetDataTypeName(const WideString Value) = 0 ;
	__property _di_IXMLTypeDef DataType = {read=GetDataType, write=SetDataType};
	__property WideString DataTypeName = {read=GetDataTypeName, write=SetDataTypeName};
};

__interface INTERFACE_UUID("{7EDFC125-4C43-11D4-83DA-00C04F60B2DD}") IXMLAttributeDef  : public IXMLTypedSchemaItem 
{
	
public:
	virtual _di_IXMLAttributeDef __fastcall GetRef(void) = 0 ;
	virtual Variant __fastcall GetUse(void) = 0 ;
	virtual Variant __fastcall GetDefault(void) = 0 ;
	virtual Variant __fastcall GetFixed(void) = 0 ;
	virtual void __fastcall SetRef(const _di_IXMLAttributeDef Value) = 0 ;
	virtual void __fastcall SetUse(const Variant &Value) = 0 ;
	virtual void __fastcall SetDefault(const Variant &Value) = 0 ;
	virtual void __fastcall SetFixed(const Variant &Value) = 0 ;
	__property _di_IXMLAttributeDef Ref = {read=GetRef, write=SetRef};
	__property Variant Use = {read=GetUse, write=SetUse};
	__property Variant Default = {read=GetDefault, write=SetDefault};
	__property Variant Fixed = {read=GetFixed, write=SetFixed};
};

__interface INTERFACE_UUID("{7EDFC124-4C43-11D4-83DA-00C04F60B2DD}") IXMLElementDef  : public IXMLTypedSchemaItem 
{
	
public:
	virtual _di_IXMLAttributeDefList __fastcall GetAttributeDefList(void) = 0 ;
	virtual _di_IXMLElementDefList __fastcall GetChildElementList(void) = 0 ;
	virtual Variant __fastcall GetMaxOccurs(void) = 0 ;
	virtual Variant __fastcall GetMinOccurs(void) = 0 ;
	virtual _di_IXMLElementDef __fastcall GetRef(void) = 0 ;
	virtual void __fastcall SetMaxOccurs(const Variant &Value) = 0 ;
	virtual void __fastcall SetMinOccurs(const Variant &Value) = 0 ;
	virtual void __fastcall SetRef(const _di_IXMLElementDef Value) = 0 ;
	virtual bool __fastcall IsRepeating(void) = 0 ;
	__property _di_IXMLAttributeDefList AttributeDefs = {read=GetAttributeDefList};
	__property _di_IXMLElementDefList ChildElements = {read=GetChildElementList};
	__property Variant MaxOccurs = {read=GetMaxOccurs, write=SetMaxOccurs};
	__property Variant MinOccurs = {read=GetMinOccurs, write=SetMinOccurs};
	__property _di_IXMLElementDef Ref = {read=GetRef, write=SetRef};
};

__interface INTERFACE_UUID("{0B007C80-648B-11D4-83DA-00C04F60B2DD}") IXMLElementCompositor  : public IXMLAnnotatedItem 
{
	
public:
	virtual _di_IXMLElementCompositors __fastcall GetCompositors(void) = 0 ;
	virtual TCompositorType __fastcall GetCompositorType(void) = 0 ;
	virtual _di_IXMLElementDefs __fastcall GetElementDefs(void) = 0 ;
	virtual _di_IXMLElementGroups __fastcall GetElementGroups(void) = 0 ;
	virtual Variant __fastcall GetMaxOccurs(void) = 0 ;
	virtual Variant __fastcall GetMinOccurs(void) = 0 ;
	virtual void __fastcall SetMaxOccurs(const Variant &Value) = 0 ;
	virtual void __fastcall SetMinOccurs(const Variant &Value) = 0 ;
	__property _di_IXMLElementCompositors Compositors = {read=GetCompositors};
	__property TCompositorType CompositorType = {read=GetCompositorType};
	__property _di_IXMLElementDefs ElementDefs = {read=GetElementDefs};
	__property _di_IXMLElementGroups ElementGroups = {read=GetElementGroups};
	__property Variant MaxOccurs = {read=GetMaxOccurs, write=SetMaxOccurs};
	__property Variant MinOccurs = {read=GetMinOccurs, write=SetMinOccurs};
};

__interface IXMLAttributeGroup;
typedef System::DelphiInterface<IXMLAttributeGroup> _di_IXMLAttributeGroup;
__interface INTERFACE_UUID("{8E5DB500-63C5-11D4-83DA-00C04F60B2DD}") IXMLAttributeGroup  : public IXMLSchemaRefItem 
{
	
public:
	virtual _di_IXMLAttributeDefs __fastcall GetAttributeDefs(void) = 0 ;
	virtual _di_IXMLAttributeGroups __fastcall GetAttributeGroups(void) = 0 ;
	virtual _di_IXMLAttributeGroup __fastcall GetRef(void) = 0 ;
	virtual void __fastcall SetRef(const _di_IXMLAttributeGroup Value) = 0 ;
	__property _di_IXMLAttributeDefs AttributeDefs = {read=GetAttributeDefs};
	__property _di_IXMLAttributeGroups AttributeGroups = {read=GetAttributeGroups};
	__property _di_IXMLAttributeGroup Ref = {read=GetRef, write=SetRef};
};

__interface INTERFACE_UUID("{53F27080-4DAF-11D4-83DA-00C04F60B2DD}") IXMLElementGroup  : public IXMLSchemaRefItem 
{
	
public:
	virtual _di_IXMLElementCompositor __fastcall GetCompositorNode(void) = 0 ;
	virtual _di_IXMLElementCompositors __fastcall GetElementCompositors(void) = 0 ;
	virtual _di_IXMLElementDefs __fastcall GetElementDefs(void) = 0 ;
	virtual _di_IXMLElementGroups __fastcall GetElementGroups(void) = 0 ;
	virtual _di_IXMLElementGroup __fastcall GetRef(void) = 0 ;
	virtual void __fastcall SetRef(const _di_IXMLElementGroup Value) = 0 ;
	__property _di_IXMLElementCompositor CompositorNode = {read=GetCompositorNode};
	__property _di_IXMLElementCompositors ElementCompositors = {read=GetElementCompositors};
	__property _di_IXMLElementDefs ElementDefs = {read=GetElementDefs};
	__property _di_IXMLElementGroups ElementGroups = {read=GetElementGroups};
	__property _di_IXMLElementGroup Ref = {read=GetRef, write=SetRef};
};

__interface IXMLNotation;
typedef System::DelphiInterface<IXMLNotation> _di_IXMLNotation;
__interface INTERFACE_UUID("{6BC9D168-3AA1-4F00-A025-DAD2CD02E5B3}") IXMLNotation  : public IXMLSchemaItem 
{
	
public:
	virtual void __fastcall SetPublicID(const Variant &Value) = 0 ;
	virtual void __fastcall SetSystemID(const Variant &Value) = 0 ;
	virtual Variant __fastcall GetPublicID(void) = 0 ;
	virtual Variant __fastcall GetSystemID(void) = 0 ;
	__property Variant PublicID = {read=GetPublicID, write=SetPublicID};
	__property Variant SystemID = {read=GetSystemID, write=SetSystemID};
};

__interface IXMLAnnotation;
typedef System::DelphiInterface<IXMLAnnotation> _di_IXMLAnnotation;
__interface INTERFACE_UUID("{F3A9316D-4AF3-4CD7-8C5B-DBFEF236A8DA}") IXMLAnnotation  : public IXMLSchemaNode 
{
	
public:
	virtual _di_IXMLAppInfoCollection __fastcall GetAppInfoCollection(void) = 0 ;
	virtual _di_IXMLDocumentationCollection __fastcall GetDocumentationCollection(void) = 0 ;
	virtual bool __fastcall HasAppInfo(void) = 0 ;
	virtual bool __fastcall HasDocumentation(void) = 0 ;
	__property _di_IXMLAppInfoCollection AppInfo = {read=GetAppInfoCollection};
	__property _di_IXMLDocumentationCollection Documentation = {read=GetDocumentationCollection};
};

__interface IXMLAppInfo;
typedef System::DelphiInterface<IXMLAppInfo> _di_IXMLAppInfo;
__interface INTERFACE_UUID("{FE7435C8-806F-441F-9195-A23F777D1954}") IXMLAppInfo  : public IXMLSchemaNode 
{
	
public:
	virtual Variant __fastcall GetSource(void) = 0 ;
	virtual void __fastcall SetSource(const Variant &Value) = 0 ;
	__property Variant Source = {read=GetSource, write=SetSource};
};

__interface IXMLDocumentation;
typedef System::DelphiInterface<IXMLDocumentation> _di_IXMLDocumentation;
__interface INTERFACE_UUID("{A1562492-BC31-4727-A690-17631848C2AF}") IXMLDocumentation  : public IXMLSchemaNode 
{
	
public:
	virtual Variant __fastcall GetSource(void) = 0 ;
	virtual void __fastcall SetSource(const Variant &Value) = 0 ;
	__property Variant Source = {read=GetSource, write=SetSource};
};

__interface IXMLEnumeration;
typedef System::DelphiInterface<IXMLEnumeration> _di_IXMLEnumeration;
__interface INTERFACE_UUID("{FBF0F414-AA54-4ADD-BD64-EA15D5AD380E}") IXMLEnumeration  : public IXMLSchemaNode 
{
	
public:
	virtual Variant __fastcall GetValue(void) = 0 ;
	virtual void __fastcall SetValue(const Variant &Value) = 0 ;
	__property Variant Value = {read=GetValue, write=SetValue};
};

__interface IXMLSchemaDocRefs;
typedef System::DelphiInterface<IXMLSchemaDocRefs> _di_IXMLSchemaDocRefs;
__interface INTERFACE_UUID("{3C32E7BD-5CEE-4757-9C1D-266BB11983FE}") IXMLSchemaDocRefs  : public IXMLNodeCollection 
{
	
public:
	_di_IXMLSchemaDocRef operator[](int Index) { return SchemaDocRef[Index]; }
	
public:
	virtual _di_IXMLSchemaDocRef __fastcall GetSchemaDocRef(int Index) = 0 ;
	__property _di_IXMLSchemaDocRef SchemaDocRef[int Index] = {read=GetSchemaDocRef/*, default*/};
};

__interface IXMLSchemaImports;
typedef System::DelphiInterface<IXMLSchemaImports> _di_IXMLSchemaImports;
__interface INTERFACE_UUID("{7EDFC126-4C43-11D4-83DA-00C04F60B2DD}") IXMLSchemaImports  : public IXMLSchemaDocRefs 
{
	
public:
	_di_IXMLSchemaImport operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLSchemaImport __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLSchemaImport __fastcall Add(const WideString SchemaLocation) = 0 /* overload */;
	virtual _di_IXMLSchemaImport __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLSchemaImport Items[int Index] = {read=GetItem/*, default*/};
};

__interface IXMLSchemaIncludes;
typedef System::DelphiInterface<IXMLSchemaIncludes> _di_IXMLSchemaIncludes;
__interface INTERFACE_UUID("{7D9A30D4-007E-47C1-9BC1-AF8A1919777B}") IXMLSchemaIncludes  : public IXMLSchemaDocRefs 
{
	
public:
	_di_IXMLSchemaInclude operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLSchemaInclude __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLSchemaInclude __fastcall Add(const WideString SchemaLocation) = 0 /* overload */;
	virtual _di_IXMLSchemaInclude __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLSchemaInclude Items[int Index] = {read=GetItem/*, default*/};
};

__interface INTERFACE_UUID("{7EDFC126-4C43-11D4-83DA-00C04F60B2DD}") IXMLSchemaItems  : public IXMLNodeCollection 
{
	
public:
	_di_IXMLSchemaItem operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLSchemaItem __fastcall GetSchemaItem(int Index) = 0 ;
	virtual _di_IXMLSchemaItem __fastcall FindItem(const WideString Name) = 0 ;
	virtual int __fastcall IndexOfItem(const WideString Name) = 0 ;
	__property _di_IXMLSchemaItem Items[int Index] = {read=GetSchemaItem/*, default*/};
};

__interface IXMLSimpleTypeDefs;
typedef System::DelphiInterface<IXMLSimpleTypeDefs> _di_IXMLSimpleTypeDefs;
__interface INTERFACE_UUID("{7EDFC127-4C43-11D4-83DA-00C04F60B2DD}") IXMLSimpleTypeDefs  : public IXMLSchemaItems 
{
	
public:
	_di_IXMLSimpleTypeDef operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLSimpleTypeDef __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLSimpleTypeDef __fastcall Add(const WideString Name, WideString BaseTypeName = L"") = 0 /* overload */;
	virtual _di_IXMLSimpleTypeDef __fastcall Find(const WideString Name) = 0 ;
	virtual _di_IXMLSimpleTypeDef __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLSimpleTypeDef Items[int Index] = {read=GetItem/*, default*/};
};

__interface IXMLComplexTypeDefs;
typedef System::DelphiInterface<IXMLComplexTypeDefs> _di_IXMLComplexTypeDefs;
__interface INTERFACE_UUID("{7EDFC128-4C43-11D4-83DA-00C04F60B2DD}") IXMLComplexTypeDefs  : public IXMLSchemaItems 
{
	
public:
	_di_IXMLComplexTypeDef operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLComplexTypeDef __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLComplexTypeDef __fastcall Add(const WideString Name, TContentModel ContentModel = (TContentModel)(0x2)) = 0 /* overload */;
	virtual _di_IXMLComplexTypeDef __fastcall Add(const WideString Name, const WideString BaseTypeName, TDerivationMethod DerivationMethod = (TDerivationMethod)(0x1), TContentModel ContentModel = (TContentModel)(0x2)) = 0 /* overload */;
	virtual _di_IXMLComplexTypeDef __fastcall Find(const WideString Name) = 0 ;
	virtual _di_IXMLComplexTypeDef __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLComplexTypeDef Items[int Index] = {read=GetItem/*, default*/};
};

__interface INTERFACE_UUID("{7EDFC131-4C43-11D4-83DA-00C04F60B2DD}") IXMLAttributeDefs  : public IXMLSchemaItems 
{
	
public:
	_di_IXMLAttributeDef operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLAttributeDef __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLAttributeDef __fastcall Add(const WideString RefName) = 0 /* overload */;
	virtual _di_IXMLAttributeDef __fastcall Add(const WideString Name, const WideString DataType) = 0 /* overload */;
	virtual _di_IXMLAttributeDef __fastcall Add(const WideString Name, bool LocalSimpleType, WideString BaseTypeName = L"") = 0 /* overload */;
	virtual _di_IXMLAttributeDef __fastcall Find(const WideString Name) = 0 ;
	virtual _di_IXMLAttributeDef __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLAttributeDef Items[int Index] = {read=GetItem/*, default*/};
};

__interface INTERFACE_UUID("{7EDFC130-4C43-11D4-83DA-00C04F60B2DD}") IXMLElementDefs  : public IXMLSchemaItems 
{
	
public:
	_di_IXMLElementDef operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLElementDef __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLElementDef __fastcall Add(const WideString RefName) = 0 /* overload */;
	virtual _di_IXMLElementDef __fastcall Add(const WideString Name, const WideString DataType) = 0 /* overload */;
	virtual _di_IXMLElementDef __fastcall Add(const WideString Name, bool ComplexLocalType, WideString BaseTypeName = L"") = 0 /* overload */;
	virtual _di_IXMLElementDef __fastcall Find(const WideString Name) = 0 ;
	virtual _di_IXMLElementDef __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLElementDef Items[int Index] = {read=GetItem/*, default*/};
};

__interface INTERFACE_UUID("{8E5DB501-63C5-11D4-83DA-00C04F60B2DD}") IXMLAttributeGroups  : public IXMLSchemaItems 
{
	
public:
	_di_IXMLAttributeGroup operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLAttributeGroup __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLAttributeGroup __fastcall Add(void) = 0 ;
	virtual _di_IXMLAttributeGroup __fastcall Find(const WideString Name) = 0 ;
	virtual _di_IXMLAttributeGroup __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLAttributeGroup Items[int Index] = {read=GetItem/*, default*/};
};

__interface INTERFACE_UUID("{7EDFC129-4C43-11D4-83DA-00C04F60B2DD}") IXMLElementGroups  : public IXMLSchemaItems 
{
	
public:
	_di_IXMLElementGroup operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLElementGroup __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLElementGroup __fastcall Add(const WideString NameOrRef) = 0 /* overload */;
	virtual _di_IXMLElementGroup __fastcall Find(const WideString Name) = 0 ;
	virtual _di_IXMLElementGroup __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLElementGroup Items[int Index] = {read=GetItem/*, default*/};
};

__interface INTERFACE_UUID("{0B007C81-648B-11D4-83DA-00C04F60B2DD}") IXMLElementCompositors  : public IXMLSchemaItems 
{
	
public:
	_di_IXMLElementCompositor operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLElementCompositor __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLElementCompositor __fastcall Add(TCompositorType CompositorType = (TCompositorType)(0x2)) = 0 ;
	virtual _di_IXMLElementCompositor __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLElementCompositor Items[int Index] = {read=GetItem/*, default*/};
};

__interface IXMLNotationDefs;
typedef System::DelphiInterface<IXMLNotationDefs> _di_IXMLNotationDefs;
__interface INTERFACE_UUID("{6388BD4A-9E83-4249-A7F0-C8438F47D0AD}") IXMLNotationDefs  : public IXMLSchemaItems 
{
	
public:
	_di_IXMLNotation operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLNotation __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLNotation __fastcall Add(const WideString Name, const WideString APublicID = L"", const WideString ASystemID = L"") = 0 /* overload */;
	virtual _di_IXMLNotation __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLNotation Items[int Index] = {read=GetItem/*, default*/};
};

__interface IXMLAnnotationItems;
typedef System::DelphiInterface<IXMLAnnotationItems> _di_IXMLAnnotationItems;
__interface INTERFACE_UUID("{C6414FE7-A7AD-495B-9302-2E65537FE0A1}") IXMLAnnotationItems  : public IXMLNodeCollection 
{
	
public:
	virtual _di_IXMLAnnotation __fastcall Add(void) = 0 ;
	virtual _di_IXMLAnnotation __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLAnnotation __fastcall Insert(int Index) = 0 ;
};

__interface INTERFACE_UUID("{6C5C9808-FE59-4A7E-A38A-A17F710C0BE7}") IXMLAppInfoCollection  : public IXMLNodeCollection 
{
	
public:
	_di_IXMLAppInfo operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLAppInfo __fastcall Add(void) = 0 ;
	virtual _di_IXMLAppInfo __fastcall GetAppInfo(const GUID &AppInfoType, TMetaClass* AppInfoClassType = 0x0) = 0 ;
	virtual _di_IXMLAppInfo __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLAppInfo __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLAppInfo Items[int Index] = {read=GetItem/*, default*/};
};

__interface INTERFACE_UUID("{F7820DA4-7C00-40D0-9F2C-AF726D8D4353}") IXMLDocumentationCollection  : public IXMLNodeCollection 
{
	
public:
	_di_IXMLDocumentation operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLDocumentation __fastcall Add(void) = 0 ;
	virtual _di_IXMLDocumentation __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLDocumentation __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLDocumentation Items[int Index] = {read=GetItem/*, default*/};
};

__interface INTERFACE_UUID("{3EB8EB97-1343-40E1-9E85-5E29C4EDD8C4}") IXMLEnumerationCollection  : public IXMLNodeCollection 
{
	
public:
	_di_IXMLEnumeration operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_IXMLEnumeration __fastcall Add(const WideString Value) = 0 ;
	virtual _di_IXMLEnumeration __fastcall GetItem(int Index) = 0 ;
	virtual _di_IXMLEnumeration __fastcall Insert(int Index) = 0 ;
	__property _di_IXMLEnumeration Items[int Index] = {read=GetItem/*, default*/};
};

__interface IXMLSchemaDoc;
typedef System::DelphiInterface<IXMLSchemaDoc> _di_IXMLSchemaDoc;
__interface INTERFACE_UUID("{7EDFC132-4C43-11D4-83DA-00C04F60B2DD}") IXMLSchemaDef  : public IXMLNode 
{
	
public:
	virtual _di_IXMLAnnotationItems __fastcall GetAnnotations(void) = 0 ;
	virtual _di_IXMLAttributeDefs __fastcall GetAttributeDefs(void) = 0 ;
	virtual TFormChoice __fastcall GetAttributeFormDefault(void) = 0 ;
	virtual _di_IXMLAttributeGroups __fastcall GetAttributeGroups(void) = 0 ;
	virtual _di_IXMLSimpleTypeDefs __fastcall GetBuiltInTypes(void) = 0 ;
	virtual _di_IXMLComplexTypeDefs __fastcall GetComplexTypes(void) = 0 ;
	virtual _di_IXMLElementDef __fastcall GetDocElementDef(void) = 0 ;
	virtual _di_IXMLElementDefs __fastcall GetElementDefs(void) = 0 ;
	virtual TFormChoice __fastcall GetElementFormDefault(void) = 0 ;
	virtual _di_IXMLElementGroups __fastcall GetElementGroups(void) = 0 ;
	virtual _di_IXMLNotationDefs __fastcall GetNotationDefs(void) = 0 ;
	virtual _di_IXMLSchemaDoc __fastcall GetSchemaDoc(void) = 0 ;
	virtual _di_IXMLSchemaImports __fastcall GetSchemaImports(void) = 0 ;
	virtual _di_IXMLSchemaIncludes __fastcall GetSchemaIncludes(void) = 0 ;
	virtual _di_IXMLSimpleTypeDefs __fastcall GetSimpleTypes(void) = 0 ;
	virtual bool __fastcall GetStrictFormat(void) = 0 ;
	virtual OleVariant __fastcall GetTargetNamespace(void) = 0 ;
	virtual WideString __fastcall GetTargetNSPrefix(void) = 0 ;
	virtual WideString __fastcall GetVersion(void) = 0 ;
	virtual void __fastcall SetAttributeformDefault(const TFormChoice Value) = 0 ;
	virtual void __fastcall SetDocElementDef(const _di_IXMLElementDef Value) = 0 ;
	virtual void __fastcall SetElementformDefault(const TFormChoice Value) = 0 ;
	virtual void __fastcall SetStrictFormat(const bool Value) = 0 ;
	virtual void __fastcall SetVersion(const WideString Value) = 0 ;
	virtual WideString __fastcall PrefixedTypeName(const WideString TypeName) = 0 ;
	virtual void __fastcall RegisterAppInfo(const WideString NamespaceURI, const WideString Prefix, TMetaClass* NodeClass) = 0 ;
	virtual void __fastcall SetTargetNamespace(const WideString NamespaceURI, const WideString NSPrefix) = 0 ;
	__property _di_IXMLAnnotationItems Annotations = {read=GetAnnotations};
	__property _di_IXMLAttributeDefs AttributeDefs = {read=GetAttributeDefs};
	__property TFormChoice AttributeFormDefault = {read=GetAttributeFormDefault, write=SetAttributeformDefault};
	__property _di_IXMLAttributeGroups AttributeGroups = {read=GetAttributeGroups};
	__property _di_IXMLSimpleTypeDefs BuiltInTypes = {read=GetBuiltInTypes};
	__property _di_IXMLComplexTypeDefs ComplexTypes = {read=GetComplexTypes};
	__property _di_IXMLElementDef DocElementDef = {read=GetDocElementDef, write=SetDocElementDef};
	__property _di_IXMLElementDefs ElementDefs = {read=GetElementDefs};
	__property TFormChoice ElementFormDefault = {read=GetElementFormDefault, write=SetElementformDefault};
	__property _di_IXMLElementGroups ElementGroups = {read=GetElementGroups};
	__property _di_IXMLNotationDefs NotationDefs = {read=GetNotationDefs};
	__property _di_IXMLSchemaDoc SchemaDoc = {read=GetSchemaDoc};
	__property _di_IXMLSchemaImports SchemaImports = {read=GetSchemaImports};
	__property _di_IXMLSchemaIncludes SchemaIncludes = {read=GetSchemaIncludes};
	__property _di_IXMLSimpleTypeDefs SimpleTypes = {read=GetSimpleTypes};
	__property bool StrictFormat = {read=GetStrictFormat, write=SetStrictFormat};
	__property OleVariant TargetNamespace = {read=GetTargetNamespace};
	__property WideString TargetNSPrefix = {read=GetTargetNSPrefix};
	__property WideString Version = {read=GetVersion, write=SetVersion};
};

__interface INTERFACE_UUID("{4E6B683C-15F4-4F62-9B4B-DF3130420F62}") IXMLSchemaDoc  : public IXMLDocument 
{
	
public:
	virtual _di_IXMLSchemaDef __fastcall GetSchemaDef(void) = 0 ;
	virtual bool __fastcall GetWasImported(void) = 0 ;
	__property _di_IXMLSchemaDef SchemaDef = {read=GetSchemaDef};
	__property bool WasImported = {read=GetWasImported};
};

__interface IXMLSchemaTranslator;
typedef System::DelphiInterface<IXMLSchemaTranslator> _di_IXMLSchemaTranslator;
__interface INTERFACE_UUID("{9C4DB79C-1D60-4BF2-95EE-63FDF98237D0}") IXMLSchemaTranslator  : public IInterface 
{
	
public:
	virtual void __fastcall Translate(const WideString FileName, const _di_IXMLSchemaDef SchemaDef) = 0 ;
};

__interface IXMLSchemaTranslatorFactory;
typedef System::DelphiInterface<IXMLSchemaTranslatorFactory> _di_IXMLSchemaTranslatorFactory;
__interface INTERFACE_UUID("{AAB226EE-51C1-4902-B883-FE538EB1F27E}") IXMLSchemaTranslatorFactory  : public IInterface 
{
	
public:
	virtual bool __fastcall CanExportFile(const WideString FileName) = 0 ;
	virtual bool __fastcall CanImportFile(const WideString FileName) = 0 ;
	virtual _di_IXMLSchemaTranslator __fastcall GetExportTranslator(void) = 0 ;
	virtual _di_IXMLSchemaTranslator __fastcall GetImportTranslator(void) = 0 ;
	virtual WideString __fastcall GetTranslatorDescription(void) = 0 ;
};

class DELPHICLASS TXMLAttributeDefList;
class PASCALIMPLEMENTATION TXMLAttributeDefList : public Classes::TInterfaceList 
{
	typedef Classes::TInterfaceList inherited;
	
public:
	_di_IXMLAttributeDef __fastcall GetAttributeDef(const int Index);
public:
	#pragma option push -w-inl
	/* TInterfaceList.Create */ inline __fastcall TXMLAttributeDefList(void) : Classes::TInterfaceList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TInterfaceList.Destroy */ inline __fastcall virtual ~TXMLAttributeDefList(void) { }
	#pragma option pop
	
private:
	void *__IXMLAttributeDefList;	/* Xmlschema::IXMLAttributeDefList */
	
public:
	operator IXMLAttributeDefList*(void) { return (IXMLAttributeDefList*)&__IXMLAttributeDefList; }
	
};


class DELPHICLASS TXMLElementDefList;
class PASCALIMPLEMENTATION TXMLElementDefList : public Classes::TInterfaceList 
{
	typedef Classes::TInterfaceList inherited;
	
public:
	_di_IXMLElementDef __fastcall GetElementDef(const int Index);
public:
	#pragma option push -w-inl
	/* TInterfaceList.Create */ inline __fastcall TXMLElementDefList(void) : Classes::TInterfaceList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TInterfaceList.Destroy */ inline __fastcall virtual ~TXMLElementDefList(void) { }
	#pragma option pop
	
private:
	void *__IXMLElementDefList;	/* Xmlschema::IXMLElementDefList */
	
public:
	operator IXMLElementDefList*(void) { return (IXMLElementDefList*)&__IXMLElementDefList; }
	
};


class DELPHICLASS TXMLSchemaNode;
class DELPHICLASS TXMLSchemaDef;
class PASCALIMPLEMENTATION TXMLSchemaNode : public Xmldoc::TXMLNode 
{
	typedef Xmldoc::TXMLNode inherited;
	
protected:
	TXMLSchemaDef* __fastcall SchemaObject(void);
	_di_IXMLSchemaDef __fastcall GetSchemaDef();
	__property _di_IXMLSchemaDef SchemaDef = {read=GetSchemaDef};
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaNode(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaNode(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaNode(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaNode;	/* Xmlschema::IXMLSchemaNode */
	
public:
	operator IXMLSchemaNode*(void) { return (IXMLSchemaNode*)&__IXMLSchemaNode; }
	
};


class DELPHICLASS TXMLSchemaItem;
class PASCALIMPLEMENTATION TXMLSchemaItem : public TXMLSchemaNode 
{
	typedef TXMLSchemaNode inherited;
	
private:
	_di_IXMLSchemaRefItem FRefItem;
	_di_IXMLAnnotation FAnnotation;
	
protected:
	virtual _di_IXMLSchemaItems __fastcall GlobalCollection();
	_di_IXMLSchemaRefItem __fastcall GetRefItem();
	virtual void __fastcall SetRefItem(const _di_IXMLSchemaRefItem Value);
	bool __fastcall IsGlobal(void);
	_di_IXMLAnnotation __fastcall GetAnnotation();
	_di_IXMLAppInfoCollection __fastcall GetAppInfoCollection();
	_di_IXMLDocumentationCollection __fastcall GetDocumentationCollection();
	virtual WideString __fastcall GetName();
	WideString __fastcall GetRefName();
	virtual void __fastcall SetName(const WideString Value);
	void __fastcall SetRefName(const WideString Value);
	bool __fastcall HasAnnotation(void);
	WideString __fastcall ItemLocalName();
	void __fastcall RemoveAnnotation(bool OnlyIfEmpty = true);
	__property _di_IXMLAnnotation Annotation = {read=GetAnnotation};
	__property _di_IXMLSchemaRefItem RefItem = {read=GetRefItem, write=SetRefItem};
	__property _di_IXMLSchemaDef SchemaDef = {read=GetSchemaDef};
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaItem(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaItem(Xmldoc::TXMLNode* HostNode) : TXMLSchemaNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaItem(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaRefItem;	/* Xmlschema::IXMLSchemaRefItem */
	
public:
	operator IXMLSchemaRefItem*(void) { return (IXMLSchemaRefItem*)&__IXMLSchemaRefItem; }
	operator IXMLSchemaItem*(void) { return (IXMLSchemaItem*)&__IXMLSchemaRefItem; }
	operator IXMLAnnotatedItem*(void) { return (IXMLAnnotatedItem*)&__IXMLSchemaRefItem; }
	
};


class DELPHICLASS TXMLSchemaDocRef;
class PASCALIMPLEMENTATION TXMLSchemaDocRef : public TXMLSchemaItem 
{
	typedef TXMLSchemaItem inherited;
	
private:
	_di_IXMLSchemaDef FSchemaRef;
	
protected:
	WideString __fastcall GetSchemaLocation();
	_di_IXMLSchemaDef __fastcall GetSchemaRef();
	void __fastcall SetSchemaLocation(const WideString Value);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaDocRef(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaDocRef(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaDocRef(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaDocRef;	/* Xmlschema::IXMLSchemaDocRef */
	
public:
	operator IXMLSchemaDocRef*(void) { return (IXMLSchemaDocRef*)&__IXMLSchemaDocRef; }
	
};


class DELPHICLASS TXMLSchemaImport;
class PASCALIMPLEMENTATION TXMLSchemaImport : public TXMLSchemaDocRef 
{
	typedef TXMLSchemaDocRef inherited;
	
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaImport(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaDocRef(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaImport(Xmldoc::TXMLNode* HostNode) : TXMLSchemaDocRef(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaImport(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaImport;	/* Xmlschema::IXMLSchemaImport */
	
public:
	operator IXMLSchemaImport*(void) { return (IXMLSchemaImport*)&__IXMLSchemaImport; }
	
};


class DELPHICLASS TXMLSchemaInclude;
class PASCALIMPLEMENTATION TXMLSchemaInclude : public TXMLSchemaDocRef 
{
	typedef TXMLSchemaDocRef inherited;
	
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaInclude(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaDocRef(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaInclude(Xmldoc::TXMLNode* HostNode) : TXMLSchemaDocRef(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaInclude(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaInclude;	/* Xmlschema::IXMLSchemaInclude */
	
public:
	operator IXMLSchemaInclude*(void) { return (IXMLSchemaInclude*)&__IXMLSchemaInclude; }
	
};


class DELPHICLASS TXMLTypeDef;
class PASCALIMPLEMENTATION TXMLTypeDef : public TXMLSchemaItem 
{
	typedef TXMLSchemaItem inherited;
	
private:
	_di_IXMLEnumerationCollection FEnumerations;
	
protected:
	virtual Variant __fastcall ReadFacet(const AnsiString FacetName);
	virtual Xmlintf::_di_IXMLNode __fastcall GetFacetParentNode(const bool Required = true) = 0 ;
	virtual WideString __fastcall GetName();
	virtual void __fastcall SetName(const WideString Value);
	virtual _di_IXMLTypeDef __fastcall GetBaseType(void) = 0 ;
	WideString __fastcall GetBaseTypeName();
	Variant __fastcall GetBounded();
	Variant __fastcall GetCardinality();
	_di_IXMLEnumerationCollection __fastcall GetEnumerations();
	Variant __fastcall GetFractionalDigits();
	Variant __fastcall GetLength();
	Variant __fastcall GetMaxExclusive();
	Variant __fastcall GetMaxInclusive();
	Variant __fastcall GetMaxLength();
	Variant __fastcall GetMinExclusive();
	Variant __fastcall GetMinInclusive();
	Variant __fastcall GetMinLength();
	Variant __fastcall GetNumeric();
	Variant __fastcall GetOrdered();
	Variant __fastcall GetPattern();
	Variant __fastcall GetTotalDigits();
	Variant __fastcall GetWhitespace();
	bool __fastcall IsAnonymous(void);
	virtual bool __fastcall IsComplex(void);
	virtual void __fastcall SetBaseTypeName(const WideString Value) = 0 ;
	void __fastcall SetBounded(const Variant &Value);
	void __fastcall SetCardinality(const Variant &Value);
	void __fastcall SetFractionalDigits(const Variant &Value);
	void __fastcall SetLength(const Variant &Value);
	void __fastcall SetMaxExclusive(const Variant &Value);
	void __fastcall SetMaxInclusive(const Variant &Value);
	void __fastcall SetMaxLength(const Variant &Value);
	void __fastcall SetMinExclusive(const Variant &Value);
	void __fastcall SetMinInclusive(const Variant &Value);
	void __fastcall SetMinLength(const Variant &Value);
	void __fastcall SetNumeric(const Variant &Value);
	void __fastcall SetOrdered(const Variant &Value);
	void __fastcall SetPattern(const Variant &Value);
	void __fastcall SetTotalDigits(const Variant &Value);
	void __fastcall SetWhitespace(const Variant &Value);
	void __fastcall WriteFacet(const AnsiString FacetName, const Variant &Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLTypeDef(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLTypeDef(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLTypeDef(void) { }
	#pragma option pop
	
private:
	void *__IXMLTypeDef;	/* Xmlschema::IXMLTypeDef */
	
public:
	operator IXMLTypeDef*(void) { return (IXMLTypeDef*)&__IXMLTypeDef; }
	
};


class DELPHICLASS TXMLTypeRestriction;
class PASCALIMPLEMENTATION TXMLTypeRestriction : public TXMLSchemaNode 
{
	typedef TXMLSchemaNode inherited;
	
protected:
	WideString __fastcall GetBaseName();
	void __fastcall SetBaseName(const WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLTypeRestriction(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLTypeRestriction(Xmldoc::TXMLNode* HostNode) : TXMLSchemaNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLTypeRestriction(void) { }
	#pragma option pop
	
private:
	void *__IXMLTypeRestriction;	/* Xmlschema::IXMLTypeRestriction */
	
public:
	operator IXMLTypeRestriction*(void) { return (IXMLTypeRestriction*)&__IXMLTypeRestriction; }
	
};


class DELPHICLASS TXMLSimpleTypeDef;
class PASCALIMPLEMENTATION TXMLSimpleTypeDef : public TXMLTypeDef 
{
	typedef TXMLTypeDef inherited;
	
protected:
	virtual Xmlintf::_di_IXMLNode __fastcall GetFacetParentNode(const bool Required = true);
	_di_IXMLTypeRestriction __fastcall GetRestrictionNode();
	virtual _di_IXMLTypeDef __fastcall GetBaseType();
	HIDESBASE bool __fastcall IsAnonymous(void);
	bool __fastcall IsBuiltInType(void);
	virtual void __fastcall SetBaseTypeName(const WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSimpleTypeDef(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLTypeDef(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSimpleTypeDef(Xmldoc::TXMLNode* HostNode) : TXMLTypeDef(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSimpleTypeDef(void) { }
	#pragma option pop
	
private:
	void *__IXMLSimpleTypeDef;	/* Xmlschema::IXMLSimpleTypeDef */
	
public:
	operator IXMLSimpleTypeDef*(void) { return (IXMLSimpleTypeDef*)&__IXMLSimpleTypeDef; }
	
};


__interface IXMLComplexContent;
typedef System::DelphiInterface<IXMLComplexContent> _di_IXMLComplexContent;
__interface INTERFACE_UUID("{33A54303-05F7-4BF3-B2BB-61F9CD3C1CBB}") IXMLComplexContent  : public IXMLSchemaNode 
{
	
public:
	virtual _di_IXMLAttributeDefs __fastcall GetAttributeDefs(void) = 0 ;
	virtual _di_IXMLAttributeGroups __fastcall GetAttributeGroups(void) = 0 ;
	virtual _di_IXMLElementCompositor __fastcall GetCompositorNode(void) = 0 ;
	virtual _di_IXMLElementCompositors __fastcall GetCompositors(void) = 0 ;
	virtual TContentModel __fastcall GetContentModel(void) = 0 ;
	virtual _di_IXMLElementDefs __fastcall GetElementDefs(void) = 0 ;
	virtual _di_IXMLElementGroups __fastcall GetElementGroups(void) = 0 ;
	virtual _di_IXMLElementGroup __fastcall GetGroupRef(void) = 0 ;
	virtual void __fastcall SetContentModel(const TContentModel Value) = 0 ;
};

class DELPHICLASS TXMLComplexContent;
class PASCALIMPLEMENTATION TXMLComplexContent : public TXMLSchemaNode 
{
	typedef TXMLSchemaNode inherited;
	
private:
	_di_IXMLAttributeDefs FAttributeDefs;
	_di_IXMLAttributeGroups FAttributeGroups;
	_di_IXMLElementCompositor FCompositorNode;
	TContentModel FContentModel;
	_di_IXMLElementGroup FGroupRef;
	
protected:
	_di_IXMLElementCompositor __fastcall GetCompositorNode();
	_di_IXMLAttributeDefs __fastcall GetAttributeDefs();
	_di_IXMLAttributeGroups __fastcall GetAttributeGroups();
	_di_IXMLElementCompositors __fastcall GetCompositors();
	TContentModel __fastcall GetContentModel(void);
	_di_IXMLElementDefs __fastcall GetElementDefs();
	_di_IXMLElementGroups __fastcall GetElementGroups();
	_di_IXMLElementGroup __fastcall GetGroupRef();
	void __fastcall SetContentModel(const TContentModel Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
	__property _di_IXMLElementCompositor CompositorNode = {read=GetCompositorNode};
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLComplexContent(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLComplexContent(Xmldoc::TXMLNode* HostNode) : TXMLSchemaNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLComplexContent(void) { }
	#pragma option pop
	
private:
	void *__IXMLComplexContent;	/* Xmlschema::IXMLComplexContent */
	
public:
	operator IXMLComplexContent*(void) { return (IXMLComplexContent*)&__IXMLComplexContent; }
	
};


class DELPHICLASS TXMLBaseTypeIndicator;
class PASCALIMPLEMENTATION TXMLBaseTypeIndicator : public TXMLSchemaNode 
{
	typedef TXMLSchemaNode inherited;
	
protected:
	Variant __fastcall GetMixed();
	void __fastcall SetMixed(const Variant &Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLBaseTypeIndicator(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLBaseTypeIndicator(Xmldoc::TXMLNode* HostNode) : TXMLSchemaNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLBaseTypeIndicator(void) { }
	#pragma option pop
	
private:
	void *__IXMLBaseTypeIndicator;	/* Xmlschema::IXMLBaseTypeIndicator */
	
public:
	operator IXMLBaseTypeIndicator*(void) { return (IXMLBaseTypeIndicator*)&__IXMLBaseTypeIndicator; }
	
};


class DELPHICLASS TXMLComplexTypeDef;
class PASCALIMPLEMENTATION TXMLComplexTypeDef : public TXMLTypeDef 
{
	typedef TXMLTypeDef inherited;
	
private:
	_di_IXMLComplexContent FContentNode;
	TDerivationMethod FDerivationMethod;
	_di_IXMLAttributeDefList FAttributeDefList;
	_di_IXMLElementDefList FElementDefList;
	
protected:
	void __fastcall AttributesChanged(void);
	void __fastcall ChildElementsChanged(void);
	void __fastcall CheckContent(void);
	_di_IXMLComplexContent __fastcall GetContentNode();
	virtual Xmlintf::_di_IXMLNode __fastcall GetFacetParentNode(const bool Required = true);
	bool __fastcall GetAbstract(void);
	_di_IXMLAttributeDefList __fastcall GetAttributeDefList();
	_di_IXMLAttributeDefs __fastcall GetAttributeDefs();
	_di_IXMLAttributeGroups __fastcall GetAttributeGroups();
	virtual _di_IXMLTypeDef __fastcall GetBaseType();
	_di_IXMLBaseTypeIndicator __fastcall GetBaseTypeIndicator();
	_di_IXMLElementCompositor __fastcall GetCompositorNode();
	_di_IXMLElementCompositors __fastcall GetCompositors();
	TContentModel __fastcall GetContentModel(void);
	TDerivationMethod __fastcall GetDerivationMethod(void);
	_di_IXMLElementDefs __fastcall GetElementDefs();
	_di_IXMLElementDefList __fastcall GetElementDefList();
	_di_IXMLElementGroups __fastcall GetElementGroups();
	_di_IXMLElementGroup __fastcall GetGroupRef();
	virtual bool __fastcall IsComplex(void);
	void __fastcall SetAbstract(const bool Value);
	virtual void __fastcall SetBaseTypeName(const WideString Value);
	void __fastcall SetContentModel(const TContentModel Value);
	void __fastcall SetDerivationMethod(const TDerivationMethod Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
	__property _di_IXMLComplexContent ContentNode = {read=GetContentNode};
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLComplexTypeDef(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLTypeDef(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLComplexTypeDef(Xmldoc::TXMLNode* HostNode) : TXMLTypeDef(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLComplexTypeDef(void) { }
	#pragma option pop
	
private:
	void *__IXMLComplexTypeDef;	/* Xmlschema::IXMLComplexTypeDef */
	
public:
	operator IXMLComplexTypeDef*(void) { return (IXMLComplexTypeDef*)&__IXMLComplexTypeDef; }
	
};


class DELPHICLASS TXMLTypedSchemaItem;
class PASCALIMPLEMENTATION TXMLTypedSchemaItem : public TXMLSchemaItem 
{
	typedef TXMLSchemaItem inherited;
	
private:
	_di_IXMLTypeDef FTypeDef;
	
protected:
	void __fastcall RemoveTypeInfo(void);
	virtual void __fastcall SetRefItem(const _di_IXMLSchemaRefItem Value);
	_di_IXMLTypeDef __fastcall GetDataType();
	WideString __fastcall GetDataTypeName();
	void __fastcall SetDataType(const _di_IXMLTypeDef Value);
	void __fastcall SetDataTypeName(const WideString Value);
	__property _di_IXMLTypeDef DataType = {read=GetDataType};
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLTypedSchemaItem(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLTypedSchemaItem(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLTypedSchemaItem(void) { }
	#pragma option pop
	
private:
	void *__IXMLTypedSchemaItem;	/* Xmlschema::IXMLTypedSchemaItem */
	
public:
	operator IXMLTypedSchemaItem*(void) { return (IXMLTypedSchemaItem*)&__IXMLTypedSchemaItem; }
	
};


class DELPHICLASS TXMLAttributeDef;
class PASCALIMPLEMENTATION TXMLAttributeDef : public TXMLTypedSchemaItem 
{
	typedef TXMLTypedSchemaItem inherited;
	
protected:
	virtual _di_IXMLSchemaItems __fastcall GlobalCollection();
	_di_IXMLAttributeDef __fastcall GetRef();
	Variant __fastcall GetUse();
	Variant __fastcall GetDefault();
	Variant __fastcall GetFixed();
	void __fastcall SetRef(const _di_IXMLAttributeDef Value);
	void __fastcall SetUse(const Variant &Value);
	void __fastcall SetDefault(const Variant &Value);
	void __fastcall SetFixed(const Variant &Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLAttributeDef(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLTypedSchemaItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLAttributeDef(Xmldoc::TXMLNode* HostNode) : TXMLTypedSchemaItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLAttributeDef(void) { }
	#pragma option pop
	
private:
	void *__IXMLAttributeDef;	/* Xmlschema::IXMLAttributeDef */
	
public:
	operator IXMLAttributeDef*(void) { return (IXMLAttributeDef*)&__IXMLAttributeDef; }
	
};


class DELPHICLASS TXMLElementDef;
class PASCALIMPLEMENTATION TXMLElementDef : public TXMLTypedSchemaItem 
{
	typedef TXMLTypedSchemaItem inherited;
	
protected:
	virtual _di_IXMLSchemaItems __fastcall GlobalCollection();
	_di_IXMLAttributeDefList __fastcall GetAttributeDefList();
	_di_IXMLElementDefList __fastcall GetChildElementList();
	Variant __fastcall GetMaxOccurs();
	Variant __fastcall GetMinOccurs();
	_di_IXMLElementDef __fastcall GetRef();
	bool __fastcall IsRepeating(void);
	void __fastcall SetMaxOccurs(const Variant &Value);
	void __fastcall SetMinOccurs(const Variant &Value);
	void __fastcall SetRef(const _di_IXMLElementDef Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLElementDef(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLTypedSchemaItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLElementDef(Xmldoc::TXMLNode* HostNode) : TXMLTypedSchemaItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLElementDef(void) { }
	#pragma option pop
	
private:
	void *__IXMLElementDef;	/* Xmlschema::IXMLElementDef */
	
public:
	operator IXMLElementDef*(void) { return (IXMLElementDef*)&__IXMLElementDef; }
	
};


class DELPHICLASS TXMLElementCompositor;
class PASCALIMPLEMENTATION TXMLElementCompositor : public TXMLSchemaItem 
{
	typedef TXMLSchemaItem inherited;
	
private:
	TCompositorType FCompositorType;
	_di_IXMLElementCompositors FCompositors;
	_di_IXMLElementDefs FElementDefs;
	_di_IXMLElementGroups FElementGroups;
	
protected:
	_di_IXMLElementCompositors __fastcall GetCompositors();
	TCompositorType __fastcall GetCompositorType(void);
	_di_IXMLElementDefs __fastcall GetElementDefs();
	_di_IXMLElementGroups __fastcall GetElementGroups();
	Variant __fastcall GetMaxOccurs();
	Variant __fastcall GetMinOccurs();
	void __fastcall SetMaxOccurs(const Variant &Value);
	void __fastcall SetMinOccurs(const Variant &Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLElementCompositor(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLElementCompositor(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLElementCompositor(void) { }
	#pragma option pop
	
private:
	void *__IXMLElementCompositor;	/* Xmlschema::IXMLElementCompositor */
	
public:
	operator IXMLElementCompositor*(void) { return (IXMLElementCompositor*)&__IXMLElementCompositor; }
	
};


class DELPHICLASS TXMLAttributeGroup;
class PASCALIMPLEMENTATION TXMLAttributeGroup : public TXMLSchemaItem 
{
	typedef TXMLSchemaItem inherited;
	
private:
	_di_IXMLAttributeDefs FAttributeDefs;
	_di_IXMLAttributeGroups FAttributeGroups;
	
protected:
	virtual _di_IXMLSchemaItems __fastcall GlobalCollection();
	_di_IXMLAttributeDefs __fastcall GetAttributeDefs();
	_di_IXMLAttributeGroups __fastcall GetAttributeGroups();
	_di_IXMLAttributeGroup __fastcall GetRef();
	void __fastcall SetRef(const _di_IXMLAttributeGroup Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLAttributeGroup(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLAttributeGroup(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLAttributeGroup(void) { }
	#pragma option pop
	
private:
	void *__IXMLAttributeGroup;	/* Xmlschema::IXMLAttributeGroup */
	
public:
	operator IXMLAttributeGroup*(void) { return (IXMLAttributeGroup*)&__IXMLAttributeGroup; }
	
};


class DELPHICLASS TXMLElementGroup;
class PASCALIMPLEMENTATION TXMLElementGroup : public TXMLSchemaItem 
{
	typedef TXMLSchemaItem inherited;
	
private:
	_di_IXMLElementCompositor FContentNode;
	
protected:
	virtual _di_IXMLSchemaItems __fastcall GlobalCollection();
	_di_IXMLElementCompositor __fastcall GetCompositorNode();
	_di_IXMLElementCompositors __fastcall GetElementCompositors();
	_di_IXMLElementDefs __fastcall GetElementDefs();
	_di_IXMLElementGroups __fastcall GetElementGroups();
	_di_IXMLElementGroup __fastcall GetRef();
	void __fastcall SetRef(const _di_IXMLElementGroup Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
	__property _di_IXMLElementCompositor ContentNode = {read=GetCompositorNode};
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLElementGroup(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLElementGroup(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLElementGroup(void) { }
	#pragma option pop
	
private:
	void *__IXMLElementGroup;	/* Xmlschema::IXMLElementGroup */
	
public:
	operator IXMLElementGroup*(void) { return (IXMLElementGroup*)&__IXMLElementGroup; }
	
};


class DELPHICLASS TXMLNotationDef;
class PASCALIMPLEMENTATION TXMLNotationDef : public TXMLSchemaItem 
{
	typedef TXMLSchemaItem inherited;
	
protected:
	void __fastcall SetPublicID(const Variant &Value);
	void __fastcall SetSystemID(const Variant &Value);
	Variant __fastcall GetPublicID();
	Variant __fastcall GetSystemID();
	__property Variant PublicID = {read=GetPublicID, write=SetPublicID};
	__property Variant SystemID = {read=GetSystemID, write=SetSystemID};
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLNotationDef(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLNotationDef(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLNotationDef(void) { }
	#pragma option pop
	
private:
	void *__IXMLNotation;	/* Xmlschema::IXMLNotation */
	
public:
	operator IXMLNotation*(void) { return (IXMLNotation*)&__IXMLNotation; }
	
};


class DELPHICLASS TXMLAnnotationItem;
class PASCALIMPLEMENTATION TXMLAnnotationItem : public TXMLSchemaNode 
{
	typedef TXMLSchemaNode inherited;
	
protected:
	Variant __fastcall GetSource();
	void __fastcall SetSource(const Variant &Value);
	__property Variant Source = {read=GetSource, write=SetSource};
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLAnnotationItem(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLAnnotationItem(Xmldoc::TXMLNode* HostNode) : TXMLSchemaNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLAnnotationItem(void) { }
	#pragma option pop
	
private:
	void *__IXMLAppInfo;	/* Xmlschema::IXMLAppInfo */
	void *__IXMLDocumentation;	/* Xmlschema::IXMLDocumentation */
	
public:
	operator IXMLDocumentation*(void) { return (IXMLDocumentation*)&__IXMLDocumentation; }
	operator IXMLAppInfo*(void) { return (IXMLAppInfo*)&__IXMLAppInfo; }
	
};


class DELPHICLASS TXMLAnnotation;
class PASCALIMPLEMENTATION TXMLAnnotation : public TXMLSchemaNode 
{
	typedef TXMLSchemaNode inherited;
	
private:
	_di_IXMLAppInfoCollection FAppInfo;
	_di_IXMLDocumentationCollection FDocumentation;
	
protected:
	virtual Xmlintf::_di_IXMLNode __fastcall CreateChildNode(const Xmldom::_di_IDOMNode ADOMNode);
	bool __fastcall HasAppInfo(void);
	bool __fastcall HasDocumentation(void);
	_di_IXMLAppInfoCollection __fastcall GetAppInfoCollection();
	_di_IXMLDocumentationCollection __fastcall GetDocumentationCollection();
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLAnnotation(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLAnnotation(Xmldoc::TXMLNode* HostNode) : TXMLSchemaNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLAnnotation(void) { }
	#pragma option pop
	
private:
	void *__IXMLAnnotation;	/* Xmlschema::IXMLAnnotation */
	
public:
	operator IXMLAnnotation*(void) { return (IXMLAnnotation*)&__IXMLAnnotation; }
	
};


class DELPHICLASS TXMLEnumeration;
class PASCALIMPLEMENTATION TXMLEnumeration : public TXMLSchemaNode 
{
	typedef TXMLSchemaNode inherited;
	
protected:
	Variant __fastcall GetValue();
	void __fastcall SetValue(const Variant &Value);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLEnumeration(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLEnumeration(Xmldoc::TXMLNode* HostNode) : TXMLSchemaNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLEnumeration(void) { }
	#pragma option pop
	
private:
	void *__IXMLEnumeration;	/* Xmlschema::IXMLEnumeration */
	
public:
	operator IXMLEnumeration*(void) { return (IXMLEnumeration*)&__IXMLEnumeration; }
	
};


class DELPHICLASS TXMLSchemaDocRefs;
class PASCALIMPLEMENTATION TXMLSchemaDocRefs : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IXMLSchemaDocRef __fastcall GetSchemaDocRef(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaDocRefs(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaDocRefs(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaDocRefs(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaDocRefs;	/* Xmlschema::IXMLSchemaDocRefs */
	
public:
	operator IXMLSchemaDocRefs*(void) { return (IXMLSchemaDocRefs*)&__IXMLSchemaDocRefs; }
	
};


class DELPHICLASS TXMLSchemaImports;
class PASCALIMPLEMENTATION TXMLSchemaImports : public TXMLSchemaDocRefs 
{
	typedef TXMLSchemaDocRefs inherited;
	
protected:
	_di_IXMLSchemaImport __fastcall Add(const WideString SchemaLocation)/* overload */;
	_di_IXMLSchemaImport __fastcall Insert(int Index);
	_di_IXMLSchemaImport __fastcall GetItem(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaImports(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaDocRefs(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaImports(Xmldoc::TXMLNode* HostNode) : TXMLSchemaDocRefs(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaImports(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaImports;	/* Xmlschema::IXMLSchemaImports */
	
public:
	operator IXMLSchemaImports*(void) { return (IXMLSchemaImports*)&__IXMLSchemaImports; }
	
};


class DELPHICLASS TXMLSchemaIncludes;
class PASCALIMPLEMENTATION TXMLSchemaIncludes : public TXMLSchemaDocRefs 
{
	typedef TXMLSchemaDocRefs inherited;
	
protected:
	_di_IXMLSchemaInclude __fastcall Add(const WideString SchemaLocation)/* overload */;
	_di_IXMLSchemaInclude __fastcall Insert(int Index);
	_di_IXMLSchemaInclude __fastcall GetItem(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaIncludes(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaDocRefs(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaIncludes(Xmldoc::TXMLNode* HostNode) : TXMLSchemaDocRefs(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaIncludes(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaIncludes;	/* Xmlschema::IXMLSchemaIncludes */
	
public:
	operator IXMLSchemaIncludes*(void) { return (IXMLSchemaIncludes*)&__IXMLSchemaIncludes; }
	
};


class DELPHICLASS TXMLSchemaItems;
class PASCALIMPLEMENTATION TXMLSchemaItems : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
private:
	bool FIsGlobal;
	Xmldoc::TXMLNode* FSchemaDef;
	TMetaClass*FCollectionClassType;
	
protected:
	_di_IXMLSchemaDef __fastcall GetSchemaDef();
	_di_IXMLSchemaItem __fastcall GetSchemaItem(int Index);
	_di_IXMLSchemaItem __fastcall FindItem(const WideString Name);
	int __fastcall IndexOfItem(const WideString Name);
	void __fastcall SetSchemaDef(const _di_IXMLSchemaDef Value);
	virtual Xmlintf::_di_IXMLNode __fastcall AddItem(int Index);
	void __fastcall CheckParent(void);
	__property _di_IXMLSchemaDef SchemaDef = {read=GetSchemaDef, write=SetSchemaDef};
	__property bool IsGlobal = {read=FIsGlobal, nodefault};
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaItems(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaItems(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaItems(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaItems;	/* Xmlschema::IXMLSchemaItems */
	
public:
	operator IXMLSchemaItems*(void) { return (IXMLSchemaItems*)&__IXMLSchemaItems; }
	
};


class DELPHICLASS TXMLSimpleTypeDefs;
class PASCALIMPLEMENTATION TXMLSimpleTypeDefs : public TXMLSchemaItems 
{
	typedef TXMLSchemaItems inherited;
	
protected:
	_di_IXMLSimpleTypeDef __fastcall Add(const WideString Name, WideString BaseTypeName = L"");
	_di_IXMLSimpleTypeDef __fastcall Find(const WideString Name);
	_di_IXMLSimpleTypeDef __fastcall GetItem(int Index);
	_di_IXMLSimpleTypeDef __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSimpleTypeDefs(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItems(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSimpleTypeDefs(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItems(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSimpleTypeDefs(void) { }
	#pragma option pop
	
private:
	void *__IXMLSimpleTypeDefs;	/* Xmlschema::IXMLSimpleTypeDefs */
	
public:
	operator IXMLSimpleTypeDefs*(void) { return (IXMLSimpleTypeDefs*)&__IXMLSimpleTypeDefs; }
	
};


class DELPHICLASS TXMLBuiltInTypes;
class PASCALIMPLEMENTATION TXMLBuiltInTypes : public TXMLSimpleTypeDefs 
{
	typedef TXMLSimpleTypeDefs inherited;
	
protected:
	HIDESBASE int __fastcall IndexOfItem(const WideString Name);
	bool __fastcall IsBuiltInTypeName(const WideString Name);
	HIDESBASE _di_IXMLSimpleTypeDef __fastcall Add(const WideString Name, WideString BaseTypeName = L"");
	HIDESBASE _di_IXMLSimpleTypeDef __fastcall Find(const WideString Name);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLBuiltInTypes(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSimpleTypeDefs(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLBuiltInTypes(Xmldoc::TXMLNode* HostNode) : TXMLSimpleTypeDefs(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLBuiltInTypes(void) { }
	#pragma option pop
	
private:
	void *__IXMLSimpleTypeDefs;	/* Xmlschema::IXMLSimpleTypeDefs */
	
public:
	operator IXMLSimpleTypeDefs*(void) { return (IXMLSimpleTypeDefs*)&__IXMLSimpleTypeDefs; }
	
};


class DELPHICLASS TXMLComplexTypeDefs;
class PASCALIMPLEMENTATION TXMLComplexTypeDefs : public TXMLSchemaItems 
{
	typedef TXMLSchemaItems inherited;
	
protected:
	_di_IXMLComplexTypeDef __fastcall Add(const WideString Name, TContentModel ContentModel = (TContentModel)(0x2))/* overload */;
	_di_IXMLComplexTypeDef __fastcall Add(const WideString Name, const WideString BaseTypeName, TDerivationMethod DerivationMethod = (TDerivationMethod)(0x1), TContentModel ContentModel = (TContentModel)(0x2))/* overload */;
	_di_IXMLComplexTypeDef __fastcall Find(const WideString Name);
	_di_IXMLComplexTypeDef __fastcall GetItem(int Index);
	_di_IXMLComplexTypeDef __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLComplexTypeDefs(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItems(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLComplexTypeDefs(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItems(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLComplexTypeDefs(void) { }
	#pragma option pop
	
private:
	void *__IXMLComplexTypeDefs;	/* Xmlschema::IXMLComplexTypeDefs */
	
public:
	operator IXMLComplexTypeDefs*(void) { return (IXMLComplexTypeDefs*)&__IXMLComplexTypeDefs; }
	
};


class DELPHICLASS TXMLAttributeDefs;
class PASCALIMPLEMENTATION TXMLAttributeDefs : public TXMLSchemaItems 
{
	typedef TXMLSchemaItems inherited;
	
protected:
	virtual void __fastcall ChildListNotify(Xmldoc::TNodeListOperation Operation, Xmlintf::_di_IXMLNode &Node, const OleVariant &IndexOrName, bool BeforeOperation);
	_di_IXMLAttributeDef __fastcall Add(const WideString RefName)/* overload */;
	_di_IXMLAttributeDef __fastcall Add(const WideString Name, const WideString DataType)/* overload */;
	_di_IXMLAttributeDef __fastcall Add(const WideString Name, bool LocalSimpleType, WideString BaseTypeName = L"")/* overload */;
	_di_IXMLAttributeDef __fastcall Find(const WideString Name);
	_di_IXMLAttributeDef __fastcall GetItem(int Index);
	_di_IXMLAttributeDef __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLAttributeDefs(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItems(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLAttributeDefs(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItems(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLAttributeDefs(void) { }
	#pragma option pop
	
private:
	void *__IXMLAttributeDefs;	/* Xmlschema::IXMLAttributeDefs */
	
public:
	operator IXMLAttributeDefs*(void) { return (IXMLAttributeDefs*)&__IXMLAttributeDefs; }
	
};


class DELPHICLASS TXMLElementDefs;
class PASCALIMPLEMENTATION TXMLElementDefs : public TXMLSchemaItems 
{
	typedef TXMLSchemaItems inherited;
	
protected:
	virtual void __fastcall ChildListNotify(Xmldoc::TNodeListOperation Operation, Xmlintf::_di_IXMLNode &Node, const OleVariant &IndexOrName, bool BeforeOperation);
	void __fastcall InternalAdd(const _di_IXMLElementDef AElementDef);
	_di_IXMLElementDef __fastcall Add(const WideString RefName)/* overload */;
	_di_IXMLElementDef __fastcall Add(const WideString Name, const WideString DataType)/* overload */;
	_di_IXMLElementDef __fastcall Add(const WideString Name, bool ComplexLocalType, WideString BaseTypeName = L"")/* overload */;
	_di_IXMLElementDef __fastcall Find(const WideString Name);
	_di_IXMLElementDef __fastcall GetItem(int Index);
	_di_IXMLElementDef __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLElementDefs(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItems(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLElementDefs(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItems(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLElementDefs(void) { }
	#pragma option pop
	
private:
	void *__IXMLElementDefs;	/* Xmlschema::IXMLElementDefs */
	
public:
	operator IXMLElementDefs*(void) { return (IXMLElementDefs*)&__IXMLElementDefs; }
	
};


class DELPHICLASS TXMLElementCompositors;
class PASCALIMPLEMENTATION TXMLElementCompositors : public TXMLSchemaItems 
{
	typedef TXMLSchemaItems inherited;
	
protected:
	_di_IXMLElementCompositor __fastcall Add(TCompositorType CompositorType = (TCompositorType)(0x2));
	_di_IXMLElementCompositor __fastcall GetItem(int Index);
	_di_IXMLElementCompositor __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLElementCompositors(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItems(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLElementCompositors(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItems(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLElementCompositors(void) { }
	#pragma option pop
	
private:
	void *__IXMLElementCompositors;	/* Xmlschema::IXMLElementCompositors */
	
public:
	operator IXMLElementCompositors*(void) { return (IXMLElementCompositors*)&__IXMLElementCompositors; }
	
};


class DELPHICLASS TXMLAttributeGroups;
class PASCALIMPLEMENTATION TXMLAttributeGroups : public TXMLSchemaItems 
{
	typedef TXMLSchemaItems inherited;
	
protected:
	_di_IXMLAttributeGroup __fastcall Add();
	_di_IXMLAttributeGroup __fastcall Find(const WideString Name);
	_di_IXMLAttributeGroup __fastcall GetItem(int Index);
	_di_IXMLAttributeGroup __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLAttributeGroups(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItems(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLAttributeGroups(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItems(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLAttributeGroups(void) { }
	#pragma option pop
	
private:
	void *__IXMLAttributeGroups;	/* Xmlschema::IXMLAttributeGroups */
	
public:
	operator IXMLAttributeGroups*(void) { return (IXMLAttributeGroups*)&__IXMLAttributeGroups; }
	
};


class DELPHICLASS TXMLElementGroups;
class PASCALIMPLEMENTATION TXMLElementGroups : public TXMLSchemaItems 
{
	typedef TXMLSchemaItems inherited;
	
protected:
	_di_IXMLElementGroup __fastcall Add(const WideString NameOrRef);
	_di_IXMLElementGroup __fastcall Find(const WideString Name);
	_di_IXMLElementGroup __fastcall GetItem(int Index);
	_di_IXMLElementGroup __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLElementGroups(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItems(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLElementGroups(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItems(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLElementGroups(void) { }
	#pragma option pop
	
private:
	void *__IXMLElementGroups;	/* Xmlschema::IXMLElementGroups */
	
public:
	operator IXMLElementGroups*(void) { return (IXMLElementGroups*)&__IXMLElementGroups; }
	
};


class DELPHICLASS TXMLNotationDefs;
class PASCALIMPLEMENTATION TXMLNotationDefs : public TXMLSchemaItems 
{
	typedef TXMLSchemaItems inherited;
	
protected:
	_di_IXMLNotation __fastcall Add(const WideString Name, const WideString APublicID = L"", const WideString ASystemID = L"");
	_di_IXMLNotation __fastcall GetItem(int Index);
	_di_IXMLNotation __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLNotationDefs(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TXMLSchemaItems(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLNotationDefs(Xmldoc::TXMLNode* HostNode) : TXMLSchemaItems(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLNotationDefs(void) { }
	#pragma option pop
	
private:
	void *__IXMLNotationDefs;	/* Xmlschema::IXMLNotationDefs */
	
public:
	operator IXMLNotationDefs*(void) { return (IXMLNotationDefs*)&__IXMLNotationDefs; }
	
};


class DELPHICLASS TXMLAnnotationCollection;
class PASCALIMPLEMENTATION TXMLAnnotationCollection : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IXMLAnnotation __fastcall Add();
	_di_IXMLAnnotation __fastcall GetItem(int Index);
	_di_IXMLAnnotation __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLAnnotationCollection(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLAnnotationCollection(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLAnnotationCollection(void) { }
	#pragma option pop
	
private:
	void *__IXMLAnnotationItems;	/* Xmlschema::IXMLAnnotationItems */
	
public:
	operator IXMLAnnotationItems*(void) { return (IXMLAnnotationItems*)&__IXMLAnnotationItems; }
	
};


class DELPHICLASS TXMLAppInfoCollection;
class PASCALIMPLEMENTATION TXMLAppInfoCollection : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IXMLAppInfo __fastcall GetAppInfo(const GUID &AppInfoType, TMetaClass* AppInfoClassType = 0x0);
	_di_IXMLAppInfo __fastcall Add();
	_di_IXMLAppInfo __fastcall GetItem(int Index);
	_di_IXMLAppInfo __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLAppInfoCollection(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLAppInfoCollection(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLAppInfoCollection(void) { }
	#pragma option pop
	
private:
	void *__IXMLAppInfoCollection;	/* Xmlschema::IXMLAppInfoCollection */
	
public:
	operator IXMLAppInfoCollection*(void) { return (IXMLAppInfoCollection*)&__IXMLAppInfoCollection; }
	
};


class DELPHICLASS TXMLDocumentationCollection;
class PASCALIMPLEMENTATION TXMLDocumentationCollection : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IXMLDocumentation __fastcall Add();
	_di_IXMLDocumentation __fastcall GetItem(int Index);
	_di_IXMLDocumentation __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLDocumentationCollection(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLDocumentationCollection(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLDocumentationCollection(void) { }
	#pragma option pop
	
private:
	void *__IXMLDocumentationCollection;	/* Xmlschema::IXMLDocumentationCollection */
	
public:
	operator IXMLDocumentationCollection*(void) { return (IXMLDocumentationCollection*)&__IXMLDocumentationCollection; }
	
};


class DELPHICLASS TXMLEnumerationCollection;
class PASCALIMPLEMENTATION TXMLEnumerationCollection : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IXMLEnumeration __fastcall Add(const WideString Value);
	_di_IXMLEnumeration __fastcall GetItem(int Index);
	_di_IXMLEnumeration __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLEnumerationCollection(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLEnumerationCollection(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLEnumerationCollection(void) { }
	#pragma option pop
	
private:
	void *__IXMLEnumerationCollection;	/* Xmlschema::IXMLEnumerationCollection */
	
public:
	operator IXMLEnumerationCollection*(void) { return (IXMLEnumerationCollection*)&__IXMLEnumerationCollection; }
	
};


#pragma pack(push, 4)
struct TAppInfoClassInfo
{
	WideString Prefix;
	WideString NamespaceURI;
	TMetaClass*NodeClass;
} ;
#pragma pack(pop)

typedef DynamicArray<TAppInfoClassInfo >  TAppInfoClassArray;

class PASCALIMPLEMENTATION TXMLSchemaDef : public Xmldoc::TXMLNode 
{
	typedef Xmldoc::TXMLNode inherited;
	
private:
	_di_IXMLAnnotationItems FAnnotations;
	_di_IXMLAttributeDefs FAttributeDefs;
	_di_IXMLAttributeGroups FAttributeGroups;
	_di_IXMLSimpleTypeDefs FBuiltInTypes;
	_di_IXMLComplexTypeDefs FComplexTypes;
	_di_IXMLElementDef FDocElementDef;
	_di_IXMLElementDefs FElementDefs;
	_di_IXMLElementGroups FElementGroups;
	_di_IXMLSimpleTypeDefs FSimpleTypes;
	_di_IXMLNotationDefs FNotationDefs;
	DynamicArray<TAppInfoClassInfo >  FAppInfoClasses;
	_di_IXMLSchemaImports FSchemaImports;
	_di_IXMLSchemaIncludes FSchemaIncludes;
	WideString FTargetNSPrefix;
	bool FStrictFormat;
	bool FLegacyFormat;
	
protected:
	TMetaClass* __fastcall FindAppInfoClass(const WideString NamespaceURI);
	TFormChoice __fastcall GetFormChoice(const WideString ChoiceName);
	_di_IXMLSchemaDef __fastcall LoadSchemaRef(WideString SchemaLoc);
	bool __fastcall LocateAppInfo(const WideString NamespaceURI, TAppInfoClassInfo &AppInfoClassInfo);
	void __fastcall SetFormChoice(const WideString ChoiceName, const TFormChoice Value);
	_di_IXMLAnnotationItems __fastcall GetAnnotations();
	_di_IXMLAttributeDefs __fastcall GetAttributeDefs();
	TFormChoice __fastcall GetAttributeFormDefault(void);
	_di_IXMLAttributeGroups __fastcall GetAttributeGroups();
	_di_IXMLSimpleTypeDefs __fastcall GetBuiltInTypes();
	_di_IXMLComplexTypeDefs __fastcall GetComplexTypes();
	_di_IXMLElementDef __fastcall GetDocElementDef();
	_di_IXMLElementDefs __fastcall GetElementDefs();
	TFormChoice __fastcall GetElementFormDefault(void);
	_di_IXMLElementGroups __fastcall GetElementGroups();
	_di_IXMLNotationDefs __fastcall GetNotationDefs();
	_di_IXMLSchemaDoc __fastcall GetSchemaDoc();
	_di_IXMLSchemaImports __fastcall GetSchemaImports();
	_di_IXMLSchemaIncludes __fastcall GetSchemaIncludes();
	_di_IXMLSimpleTypeDefs __fastcall GetSimpleTypes();
	bool __fastcall GetStrictFormat(void);
	OleVariant __fastcall GetTargetNamespace();
	WideString __fastcall GetTargetNSPrefix();
	WideString __fastcall GetVersion();
	WideString __fastcall PrefixedTypeName(const WideString TypeName);
	void __fastcall RegisterAppInfo(const WideString NamespaceURI, const WideString Prefix, TMetaClass* NodeClass);
	void __fastcall SetAttributeformDefault(const TFormChoice Value);
	void __fastcall SetDocElementDef(const _di_IXMLElementDef Value);
	void __fastcall SetElementformDefault(const TFormChoice Value);
	void __fastcall SetStrictFormat(const bool Value);
	void __fastcall SetTargetNamespace(const WideString NamespaceURI, const WideString NSPrefix);
	void __fastcall SetVersion(const WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
	__property TFormChoice AttributeFormDefault = {read=GetAttributeFormDefault, write=SetAttributeformDefault, nodefault};
	__property _di_IXMLElementDef DocElementDef = {read=GetDocElementDef, write=SetDocElementDef};
	__property TFormChoice ElementFormDefault = {read=GetElementFormDefault, write=SetElementformDefault, nodefault};
	__property bool IsLegacyFormat = {read=FLegacyFormat, nodefault};
	__property OleVariant TargetNamespace = {read=GetTargetNamespace};
	__property WideString TargetNSPrefix = {read=GetTargetNSPrefix};
	__property WideString Version = {read=GetVersion, write=SetVersion};
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaDef(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaDef(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaDef(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaDef;	/* Xmlschema::IXMLSchemaDef */
	
public:
	operator IXMLSchemaDef*(void) { return (IXMLSchemaDef*)&__IXMLSchemaDef; }
	
};


class DELPHICLASS TXMLSchemaDoc;
class PASCALIMPLEMENTATION TXMLSchemaDoc : public Xmldoc::TXMLDocument 
{
	typedef Xmldoc::TXMLDocument inherited;
	
private:
	bool FWasImported;
	bool FEnableTranslation;
	
protected:
	bool __fastcall GetWasImported(void);
	_di_IXMLSchemaDef __fastcall GetSchemaDef();
	virtual void __fastcall CheckSchemaVersion(void);
	DYNAMIC void __fastcall DoAfterOpen(void);
	DYNAMIC void __fastcall LoadData(void);
	virtual void __fastcall PrepareNewSchema(void);
	__property bool EnableTranslation = {read=FEnableTranslation, write=FEnableTranslation, nodefault};
	
public:
	virtual void __fastcall AfterConstruction(void);
	DYNAMIC void __fastcall SaveToFile(const WideString AFileName = L"");
public:
	#pragma option push -w-inl
	/* TXMLDocument.Create */ inline __fastcall TXMLSchemaDoc(const WideString AFileName)/* overload */ : Xmldoc::TXMLDocument(AFileName) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLDocument.Destroy */ inline __fastcall virtual ~TXMLSchemaDoc(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaDoc;	/* Xmlschema::IXMLSchemaDoc */
	
public:
	operator IXMLSchemaDoc*(void) { return (IXMLSchemaDoc*)&__IXMLSchemaDoc; }
	
};


class DELPHICLASS TXMLSchemaTranslator;
class PASCALIMPLEMENTATION TXMLSchemaTranslator : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	WideString FFileName;
	_di_IXMLSchemaDef FSchemaDef;
	
protected:
	virtual void __fastcall Translate(const WideString FileName, const _di_IXMLSchemaDef SchemaDef);
	__property WideString FileName = {read=FFileName};
	__property _di_IXMLSchemaDef SchemaDef = {read=FSchemaDef};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TXMLSchemaTranslator(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLSchemaTranslator(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaTranslator;	/* Xmlschema::IXMLSchemaTranslator */
	
public:
	operator IXMLSchemaTranslator*(void) { return (IXMLSchemaTranslator*)&__IXMLSchemaTranslator; }
	
};


typedef TMetaClass*TSchemaTranslatorClass;

class DELPHICLASS TXMLSchemaTranslatorFactory;
class PASCALIMPLEMENTATION TXMLSchemaTranslatorFactory : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	WideString FDescription;
	WideString FExtension;
	TMetaClass*FExportTranslatorClass;
	TMetaClass*FImportTranslatorClass;
	
protected:
	virtual bool __fastcall CanExportFile(const WideString FileName);
	virtual bool __fastcall CanImportFile(const WideString FileName);
	_di_IXMLSchemaTranslator __fastcall GetExportTranslator();
	_di_IXMLSchemaTranslator __fastcall GetImportTranslator();
	WideString __fastcall GetTranslatorDescription();
	
public:
	__fastcall TXMLSchemaTranslatorFactory(TMetaClass* ImportClass, TMetaClass* ExportClass, const WideString Extension, const WideString Description);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLSchemaTranslatorFactory(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaTranslatorFactory;	/* Xmlschema::IXMLSchemaTranslatorFactory */
	
public:
	operator IXMLSchemaTranslatorFactory*(void) { return (IXMLSchemaTranslatorFactory*)&__IXMLSchemaTranslatorFactory; }
	
};


//-- var, const, procedure ---------------------------------------------------
#define SXMLSchemaExt ".xsd"
#define SXMLSchemaPrefix "xs"
#define SXMLSchemaLocation "schemaLocation"
#define SXMLNoNSSchemaLocation "noNamespaceSchemaLocation"
#define SXMLSchemaURI_1999 "http://www.w3.org/1999/XMLSchema"
#define SXMLSchemaInstURI_1999 "http://www.w3.org/1999/XMLSchema-instance"
#define SXMLSchemaURI_2000_10 "http://www.w3.org/2000/10/XMLSchema"
#define SXMLSchemaInstURI_2000_10 "http://www.w3.org/2000/10/XMLSchema-instance"
#define SXMLSchemaURI_2001 "http://www.w3.org/2001/XMLSchema"
#define SXMLSchemaInstURI "http://www.w3.org/2001/XMLSchema-instance"
extern PACKAGE Classes::_di_IInterfaceList TranslatorList;
extern PACKAGE WideString XMLSchemaURI;
extern PACKAGE AnsiString __fastcall GetDocumentation(_di_IXMLSchemaItem SchemaItem, bool AllEntries = false);
extern PACKAGE _di_IXMLSchemaDoc __fastcall GetXMLSchema(Xmldom::_di_IDOMDocument DOMDocument);
extern PACKAGE _di_IXMLSchemaDoc __fastcall LoadXMLSchema(const WideString FileName);
extern PACKAGE _di_IXMLSchemaDoc __fastcall LoadXMLSchemaStr(const WideString XML);
extern PACKAGE _di_IXMLSchemaDoc __fastcall NewXMLSchema(const WideString TargetNamespace = L"", const WideString TNSPrefix = L"", const WideString XSDPrefix = L"xs");
extern PACKAGE void __fastcall SchemaValidationError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE void __fastcall SchemaParseError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE void __fastcall RegisterSchemaTranslator(const _di_IXMLSchemaTranslatorFactory TranslatorFactory);
extern PACKAGE void __fastcall UnRegisterSchemaTranslator(const _di_IXMLSchemaTranslatorFactory TranslatorFactory);
extern PACKAGE _di_IXMLSchemaTranslator __fastcall FindSchemaExporter(const AnsiString FileName);
extern PACKAGE _di_IXMLSchemaTranslator __fastcall FindSchemaImporter(const AnsiString FileName);
extern PACKAGE _di_IXMLSchemaItem __fastcall FindItemNS(TXMLSchemaItems* SchemaItems, const WideString Name, const WideString ItemNS);

}	/* namespace Xmlschema */
using namespace Xmlschema;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XMLSchema
