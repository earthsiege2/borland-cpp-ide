// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XMLBindGen.pas' rev: 6.00

#ifndef XMLBindGenHPP
#define XMLBindGenHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <xmldom.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <XMLSchema.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xmlbindgen
{
//-- type declarations -------------------------------------------------------
typedef AnsiString XMLBindGen__1[21];

#pragma option push -b-
enum TXMLBindingType { btComplexType, btSimpleType, btComplexElement, btCollectionElement, btSimpleElement, btAttribute, btComplexTypeList, btSimpleTypeList, btNone };
#pragma option pop

typedef void __fastcall (__closure *TOptionChangeEvent)(const AnsiString SectionName, const AnsiString OptionName, const Variant &Value);

class DELPHICLASS TBindingOptions;
class PASCALIMPLEMENTATION TBindingOptions : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	Variant operator[](AnsiString Name) { return Options[Name]; }
	
private:
	AnsiString FSectionName;
	Classes::TStringList* FOptions;
	TOptionChangeEvent FOnOptionChange;
	System::TObject* __fastcall GetOptionData(const AnsiString Name);
	void __fastcall SetOptionData(const AnsiString Name, const System::TObject* Value);
	
protected:
	void __fastcall SetOption(const AnsiString Name, const Variant &Value);
	__property AnsiString SectionName = {read=FSectionName};
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall DoOptionChange(const AnsiString OptionName, const Variant &Value);
	
public:
	__fastcall TBindingOptions(const AnsiString SectionName, TOptionChangeEvent OnChangeEvent);
	__fastcall virtual ~TBindingOptions(void);
	void __fastcall EnsureOption(const AnsiString OptionStr);
	Variant __fastcall GetOptionValue(const AnsiString Name);
	Variant __fastcall GetOption(const AnsiString Name, const Variant &Default);
	void __fastcall InitializeOptions(const AnsiString * Values, const int Values_Size)/* overload */;
	void __fastcall InitializeOptions(const Classes::TStrings* Values)/* overload */;
	bool __fastcall IsTrue(const AnsiString Name);
	__property Variant Options[AnsiString Name] = {read=GetOptionValue, write=SetOption/*, default*/};
	__property System::TObject* OptionData[AnsiString Name] = {read=GetOptionData, write=SetOptionData};
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Clear(void);
	__property TOptionChangeEvent OnOptionChange = {read=FOnOptionChange, write=FOnOptionChange};
};


__interface IXMLBindingAppInfo;
typedef System::DelphiInterface<IXMLBindingAppInfo> _di_IXMLBindingAppInfo;
__interface INTERFACE_UUID("{3FF5455B-C787-4EA8-ADCF-AB0F66874D13}") IXMLBindingAppInfo  : public IXMLAppInfo 
{
	
public:
	virtual WideString __fastcall GetBindingAppInfoURI(void) = 0 ;
	virtual Variant __fastcall GetBound(void) = 0 ;
	virtual Variant __fastcall GetDataType(void) = 0 ;
	virtual Variant __fastcall GetDocElement(void) = 0 ;
	virtual Variant __fastcall GetIdentifierName(void) = 0 ;
	virtual Variant __fastcall GetPropReadOnly(void) = 0 ;
	virtual Variant __fastcall GetRepeated(void) = 0 ;
	virtual void __fastcall SetBindingAppInfoURI(const WideString Value) = 0 ;
	virtual void __fastcall SetBound(const Variant &Value) = 0 ;
	virtual void __fastcall SetDataType(const Variant &Value) = 0 ;
	virtual void __fastcall SetDocElement(const Variant &Value) = 0 ;
	virtual void __fastcall SetIdentifierName(const Variant &Value) = 0 ;
	virtual void __fastcall SetPropReadOnly(const Variant &Value) = 0 ;
	virtual void __fastcall SetRepeated(const Variant &Value) = 0 ;
	virtual bool __fastcall HasValueFor(const WideString AttrName) = 0 ;
	virtual void __fastcall RemoveValue(const WideString AttrName) = 0 ;
	__property WideString BindingAppInfoURI = {read=GetBindingAppInfoURI, write=SetBindingAppInfoURI};
	__property Variant Bound = {read=GetBound, write=SetBound};
	__property Variant DataType = {read=GetDataType, write=SetDataType};
	__property Variant DocElement = {read=GetDocElement, write=SetDocElement};
	__property Variant IdentifierName = {read=GetIdentifierName, write=SetIdentifierName};
	__property Variant PropReadOnly = {read=GetPropReadOnly, write=SetPropReadOnly};
	__property Variant Repeated = {read=GetRepeated, write=SetRepeated};
};

__interface IXMLBindingInfo;
typedef System::DelphiInterface<IXMLBindingInfo> _di_IXMLBindingInfo;
__interface INTERFACE_UUID("{1937F2F8-298E-42A6-983C-EA6BA68D30B8}") IXMLBindingInfo  : public IInterface 
{
	
public:
	virtual TXMLBindingType __fastcall GetBindingType(void) = 0 ;
	virtual bool __fastcall GetBound(void) = 0 ;
	virtual AnsiString __fastcall GetDataType(void) = 0 ;
	virtual AnsiString __fastcall GetDocumentation(void) = 0 ;
	virtual AnsiString __fastcall GetIdentifierName(void) = 0 ;
	virtual AnsiString __fastcall GetSourceName(void) = 0 ;
	virtual AnsiString __fastcall GetSourceType(void) = 0 ;
	virtual void __fastcall SetBindingType(const TXMLBindingType Value) = 0 ;
	virtual void __fastcall SetBound(const bool Value) = 0 ;
	virtual void __fastcall SetDataType(const AnsiString Value) = 0 ;
	virtual void __fastcall SetDocumentation(const AnsiString Value) = 0 ;
	virtual void __fastcall SetIdentifierName(const AnsiString Value) = 0 ;
	__property TXMLBindingType BindingType = {read=GetBindingType, write=SetBindingType};
	__property bool Bound = {read=GetBound, write=SetBound};
	__property AnsiString DataType = {read=GetDataType, write=SetDataType};
	__property AnsiString Documentation = {read=GetDocumentation, write=SetDocumentation};
	__property AnsiString IdentifierName = {read=GetIdentifierName, write=SetIdentifierName};
	__property AnsiString SourceName = {read=GetSourceName};
	__property AnsiString SourceType = {read=GetSourceType};
};

__interface IXMLDataTypeBinding;
typedef System::DelphiInterface<IXMLDataTypeBinding> _di_IXMLDataTypeBinding;
__interface INTERFACE_UUID("{24C2FDBD-58BB-443A-9AD6-9256B9668026}") IXMLDataTypeBinding  : public IXMLBindingInfo 
{
	
public:
	virtual bool __fastcall GetRepeated(void) = 0 ;
	virtual void __fastcall SetRepeated(const bool Value) = 0 ;
	virtual Xmlschema::_di_IXMLTypeDef __fastcall TypeDef(void) = 0 ;
	__property bool Repeated = {read=GetRepeated, write=SetRepeated};
};

__interface IXMLComplexTypeBinding;
typedef System::DelphiInterface<IXMLComplexTypeBinding> _di_IXMLComplexTypeBinding;
__interface IXMLPropertyBinding;
typedef System::DelphiInterface<IXMLPropertyBinding> _di_IXMLPropertyBinding;
__interface INTERFACE_UUID("{87908153-1958-48D0-98CE-B0FF93337113}") IXMLComplexTypeBinding  : public IXMLDataTypeBinding 
{
	
public:
	virtual WideString __fastcall GetDocElementName(void) = 0 ;
	virtual void __fastcall SetDocElementName(const WideString Value) = 0 ;
	virtual AnsiString __fastcall AncestorClass(void) = 0 ;
	virtual AnsiString __fastcall AncestorInterface(void) = 0 ;
	virtual AnsiString __fastcall ClassIdent(void) = 0 ;
	virtual _di_IXMLPropertyBinding __fastcall CollectionItem(void) = 0 ;
	virtual AnsiString __fastcall CollectionItemName(void) = 0 ;
	virtual Xmlschema::_di_IXMLComplexTypeDef __fastcall ComplexTypeDef(void) = 0 ;
	virtual bool __fastcall IsDocElement(void) = 0 ;
	virtual bool __fastcall PureCollection(void) = 0 ;
	__property WideString DocElementName = {read=GetDocElementName, write=SetDocElementName};
};

__interface IXMLDataTypeListBinding;
typedef System::DelphiInterface<IXMLDataTypeListBinding> _di_IXMLDataTypeListBinding;
__interface INTERFACE_UUID("{80994C17-4BDE-4A6F-A506-026CE43746BC}") IXMLDataTypeListBinding  : public IXMLComplexTypeBinding 
{
	
public:
	virtual _di_IXMLDataTypeBinding __fastcall ItemBindInfo(void) = 0 ;
};

__interface INTERFACE_UUID("{565D9C12-E6E5-4F47-8264-1AF2459D7BBF}") IXMLPropertyBinding  : public IXMLBindingInfo 
{
	
public:
	virtual bool __fastcall GetPropReadOnly(void) = 0 ;
	virtual Xmlschema::_di_IXMLTypedSchemaItem __fastcall GetSchemaItem(void) = 0 ;
	virtual void __fastcall SetPropReadOnly(const bool Value) = 0 ;
	HIDESBASE virtual void __fastcall SetDataType(const AnsiString Value) = 0 ;
	virtual bool __fastcall IsListProp(void) = 0 ;
	virtual _di_IXMLDataTypeBinding __fastcall TypeBindInfo(void) = 0 ;
	__property AnsiString DataType = {read=GetDataType, write=SetDataType};
	__property Xmlschema::_di_IXMLTypedSchemaItem SchemaItem = {read=GetSchemaItem};
	__property bool PropReadOnly = {read=GetPropReadOnly, write=SetPropReadOnly};
};

typedef TMetaClass*TCodeWriterClass;

typedef void __fastcall (__closure *TIdentifierCheckEvent)(AnsiString &Identifier);

__interface IXMLBindingManager;
typedef System::DelphiInterface<IXMLBindingManager> _di_IXMLBindingManager;
__interface IXMLBindingManager  : public IInterface 
{
	
public:
	virtual WideString __fastcall GetBindingAppInfoURI(void) = 0 ;
	virtual AnsiString __fastcall GetClassNameStr(void) = 0 ;
	virtual TBindingOptions* __fastcall GetCodeGenOptions(void) = 0 ;
	virtual TBindingOptions* __fastcall GetNativeTypeMap(void) = 0 ;
	virtual void __fastcall SetBindingAppInfoURI(const WideString Value) = 0 ;
	virtual void __fastcall SetClassNameStr(const AnsiString Value) = 0 ;
	virtual void __fastcall DoIdentifierCheck(AnsiString &Identifier) = 0 ;
	virtual Classes::_di_IInterfaceList __fastcall GetBindableItems(const Xmlschema::_di_IXMLSchemaDef Schema) = 0 ;
	virtual _di_IXMLBindingInfo __fastcall GetBindingInfo(const System::_di_IInterface ASchemaItem) = 0 /* overload */;
	virtual _di_IXMLDataTypeBinding __fastcall GetBindingInfo(const Xmlschema::_di_IXMLTypeDef TypeDef) = 0 /* overload */;
	virtual _di_IXMLComplexTypeBinding __fastcall GetBindingInfo(const Xmlschema::_di_IXMLComplexTypeDef ComplexTypeDef) = 0 /* overload */;
	virtual _di_IXMLPropertyBinding __fastcall GetBindingInfo(const Xmlschema::_di_IXMLTypedSchemaItem PropertyItem) = 0 /* overload */;
	virtual _di_IXMLDataTypeListBinding __fastcall GetListBindingInfo(const Xmlschema::_di_IXMLTypeDef TypeDef) = 0 ;
	virtual AnsiString __fastcall GenerateBinding(const Classes::_di_IInterfaceList BindableItems, TMetaClass* * Writers, const int Writers_Size) = 0 /* overload */;
	virtual AnsiString __fastcall GenerateBinding(const Xmlschema::_di_IXMLComplexTypeDef BindableItem, TMetaClass* * Writers, const int Writers_Size) = 0 /* overload */;
	virtual void __fastcall SetOnIdentifierCheck(const TIdentifierCheckEvent Value) = 0 ;
	virtual AnsiString __fastcall SchemaTypeToNativeType(const Variant &XMLType) = 0 ;
	__property WideString BindingAppInfoURI = {read=GetBindingAppInfoURI, write=SetBindingAppInfoURI};
	__property AnsiString ClassNameStr = {read=GetClassNameStr, write=SetClassNameStr};
	__property TBindingOptions* CodeGenOptions = {read=GetCodeGenOptions};
	__property TBindingOptions* NativeTypeMap = {read=GetNativeTypeMap};
};

class DELPHICLASS TXMLBindingAppInfo;
class PASCALIMPLEMENTATION TXMLBindingAppInfo : public Xmlschema::TXMLAnnotationItem 
{
	typedef Xmlschema::TXMLAnnotationItem inherited;
	
private:
	WideString FBindingAppInfoURI;
	
protected:
	Variant __fastcall GetValue(const WideString AttrName);
	void __fastcall SetValue(const WideString AttrName, const Variant &Value);
	WideString __fastcall GetBindingAppInfoURI();
	Variant __fastcall GetBound();
	Variant __fastcall GetDataType();
	Variant __fastcall GetDocElement();
	Variant __fastcall GetIdentifierName();
	Variant __fastcall GetPropReadOnly();
	Variant __fastcall GetRepeated();
	bool __fastcall HasValueFor(const WideString AttrName);
	void __fastcall RemoveValue(const WideString AttrName);
	void __fastcall SetBindingAppInfoURI(const WideString Value);
	void __fastcall SetBound(const Variant &Value);
	void __fastcall SetDataType(const Variant &Value);
	void __fastcall SetDocElement(const Variant &Value);
	void __fastcall SetIdentifierName(const Variant &Value);
	void __fastcall SetPropReadOnly(const Variant &Value);
	void __fastcall SetRepeated(const Variant &Value);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLBindingAppInfo(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmlschema::TXMLAnnotationItem(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLBindingAppInfo(Xmldoc::TXMLNode* HostNode) : Xmlschema::TXMLAnnotationItem(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLBindingAppInfo(void) { }
	#pragma option pop
	
private:
	void *__IXMLBindingAppInfo;	/* Xmlbindgen::IXMLBindingAppInfo */
	
public:
	operator IXMLBindingAppInfo*(void) { return (IXMLBindingAppInfo*)&__IXMLBindingAppInfo; }
	
};


class DELPHICLASS TXMLBindingInfo;
class PASCALIMPLEMENTATION TXMLBindingInfo : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_IXMLBindingManager FBindingManager;
	Xmlschema::_di_IXMLSchemaItem FSchemaItem;
	_di_IXMLBindingAppInfo FBindingAppInfo;
	
protected:
	_di_IXMLBindingAppInfo __fastcall GetBindingAppInfo();
	bool __fastcall HasAppInfo(const AnsiString AppInfoName);
	virtual AnsiString __fastcall MakeIdentifier();
	void __fastcall RemoveAppInfo(const AnsiString AppInfoName);
	__property _di_IXMLBindingManager BindingManager = {read=FBindingManager};
	virtual TXMLBindingType __fastcall GetBindingType(void) = 0 ;
	virtual bool __fastcall GetBound(void);
	virtual AnsiString __fastcall GetDataType(void) = 0 ;
	AnsiString __fastcall GetDocumentation();
	virtual AnsiString __fastcall GetIdentifierName();
	AnsiString __fastcall GetSourceName();
	virtual AnsiString __fastcall GetSourceType(void) = 0 ;
	virtual void __fastcall SetBindingType(const TXMLBindingType Value);
	void __fastcall SetBound(const bool Value);
	void __fastcall SetDataType(const AnsiString Value);
	void __fastcall SetDocumentation(const AnsiString Value);
	virtual void __fastcall SetIdentifierName(const AnsiString Value);
	__property _di_IXMLBindingAppInfo BindingAppInfo = {read=GetBindingAppInfo};
	__property Xmlschema::_di_IXMLSchemaItem SchemaItem = {read=FSchemaItem};
	
public:
	__fastcall TXMLBindingInfo(const Xmlschema::_di_IXMLSchemaItem ASchemaItem, const _di_IXMLBindingManager BindingManager);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLBindingInfo(void) { }
	#pragma option pop
	
private:
	void *__IXMLBindingInfo;	/* Xmlbindgen::IXMLBindingInfo */
	
public:
	operator IXMLBindingInfo*(void) { return (IXMLBindingInfo*)&__IXMLBindingInfo; }
	
};


class DELPHICLASS TXMLDataTypeBinding;
class PASCALIMPLEMENTATION TXMLDataTypeBinding : public TXMLBindingInfo 
{
	typedef TXMLBindingInfo inherited;
	
private:
	Xmlschema::_di_IXMLTypeDef FTypeDef;
	
protected:
	virtual bool __fastcall GetRepeated(void);
	Xmlschema::_di_IXMLTypeDef __fastcall TypeDef();
	void __fastcall SetRepeated(const bool Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLBindingInfo.Create */ inline __fastcall TXMLDataTypeBinding(const Xmlschema::_di_IXMLSchemaItem ASchemaItem, const _di_IXMLBindingManager BindingManager) : TXMLBindingInfo(ASchemaItem, BindingManager) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLDataTypeBinding(void) { }
	#pragma option pop
	
private:
	void *__IXMLDataTypeBinding;	/* Xmlbindgen::IXMLDataTypeBinding */
	
public:
	operator IXMLDataTypeBinding*(void) { return (IXMLDataTypeBinding*)&__IXMLDataTypeBinding; }
	
};


class DELPHICLASS TXMLSimpleTypeBinding;
class PASCALIMPLEMENTATION TXMLSimpleTypeBinding : public TXMLDataTypeBinding 
{
	typedef TXMLDataTypeBinding inherited;
	
private:
	Xmlschema::_di_IXMLSimpleTypeDef FSimpleTypeDef;
	
protected:
	virtual TXMLBindingType __fastcall GetBindingType(void);
	virtual AnsiString __fastcall GetDataType();
	virtual AnsiString __fastcall GetIdentifierName();
	virtual AnsiString __fastcall GetSourceType();
	Xmlschema::_di_IXMLSimpleTypeDef __fastcall SimpleTypeDef();
	virtual void __fastcall SetIdentifierName(const AnsiString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLBindingInfo.Create */ inline __fastcall TXMLSimpleTypeBinding(const Xmlschema::_di_IXMLSchemaItem ASchemaItem, const _di_IXMLBindingManager BindingManager) : TXMLDataTypeBinding(ASchemaItem, BindingManager) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLSimpleTypeBinding(void) { }
	#pragma option pop
	
private:
	void *__IXMLDataTypeBinding;	/* Xmlbindgen::IXMLDataTypeBinding */
	
public:
	operator IXMLDataTypeBinding*(void) { return (IXMLDataTypeBinding*)&__IXMLDataTypeBinding; }
	
};


class DELPHICLASS TXMLComplexTypeBinding;
class PASCALIMPLEMENTATION TXMLComplexTypeBinding : public TXMLDataTypeBinding 
{
	typedef TXMLDataTypeBinding inherited;
	
private:
	Xmlschema::_di_IXMLComplexTypeDef FComplexTypeDef;
	
protected:
	_di_IXMLComplexTypeBinding __fastcall BaseBindingInfo();
	bool __fastcall HasComplexBase(void);
	virtual AnsiString __fastcall MakeIdentifier();
	virtual TXMLBindingType __fastcall GetBindingType(void);
	virtual AnsiString __fastcall GetDataType();
	virtual AnsiString __fastcall GetSourceType();
	virtual AnsiString __fastcall AncestorClass();
	virtual AnsiString __fastcall AncestorInterface();
	virtual AnsiString __fastcall ClassIdent();
	_di_IXMLPropertyBinding __fastcall CollectionItem();
	AnsiString __fastcall CollectionItemName();
	Xmlschema::_di_IXMLComplexTypeDef __fastcall ComplexTypeDef();
	WideString __fastcall GetDocElementName();
	bool __fastcall IsDocElement(void);
	bool __fastcall PureCollection(void);
	void __fastcall SetDocElementName(const WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLBindingInfo.Create */ inline __fastcall TXMLComplexTypeBinding(const Xmlschema::_di_IXMLSchemaItem ASchemaItem, const _di_IXMLBindingManager BindingManager) : TXMLDataTypeBinding(ASchemaItem, BindingManager) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLComplexTypeBinding(void) { }
	#pragma option pop
	
private:
	void *__IXMLComplexTypeBinding;	/* Xmlbindgen::IXMLComplexTypeBinding */
	
public:
	operator IXMLComplexTypeBinding*(void) { return (IXMLComplexTypeBinding*)&__IXMLComplexTypeBinding; }
	
};


class DELPHICLASS TXMLDataTypeListBinding;
class PASCALIMPLEMENTATION TXMLDataTypeListBinding : public TXMLComplexTypeBinding 
{
	typedef TXMLComplexTypeBinding inherited;
	
private:
	AnsiString FListTypeSuffix;
	bool FSimpleType;
	
protected:
	virtual AnsiString __fastcall AncestorClass();
	virtual AnsiString __fastcall AncestorInterface();
	virtual AnsiString __fastcall ClassIdent();
	HIDESBASE AnsiString __fastcall CollectionItemName();
	virtual AnsiString __fastcall GetIdentifierName();
	virtual bool __fastcall GetRepeated(void);
	_di_IXMLDataTypeBinding __fastcall ItemBindInfo();
	HIDESBASE bool __fastcall PureCollection(void);
	__property AnsiString ListTypeSuffix = {read=FListTypeSuffix, write=FListTypeSuffix};
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLBindingInfo.Create */ inline __fastcall TXMLDataTypeListBinding(const Xmlschema::_di_IXMLSchemaItem ASchemaItem, const _di_IXMLBindingManager BindingManager) : TXMLComplexTypeBinding(ASchemaItem, BindingManager) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLDataTypeListBinding(void) { }
	#pragma option pop
	
private:
	void *__IXMLDataTypeListBinding;	/* Xmlbindgen::IXMLDataTypeListBinding */
	
public:
	operator IXMLDataTypeListBinding*(void) { return (IXMLDataTypeListBinding*)&__IXMLDataTypeListBinding; }
	
};


class DELPHICLASS TXMLPropertyBinding;
class PASCALIMPLEMENTATION TXMLPropertyBinding : public TXMLBindingInfo 
{
	typedef TXMLBindingInfo inherited;
	
private:
	Xmlschema::_di_IXMLTypedSchemaItem FSchemaItem;
	
protected:
	AnsiString __fastcall ReadDataType();
	virtual TXMLBindingType __fastcall GetBindingType(void);
	virtual bool __fastcall GetBound(void);
	virtual AnsiString __fastcall GetDataType();
	Xmlschema::_di_IXMLTypedSchemaItem __fastcall GetSchemaItem();
	virtual AnsiString __fastcall GetSourceType();
	virtual void __fastcall SetBindingType(const TXMLBindingType Value);
	_di_IXMLDataTypeBinding __fastcall TypeBindInfo();
	bool __fastcall GetPropReadOnly(void);
	bool __fastcall IsListProp(void);
	void __fastcall SetPropReadOnly(const bool Value);
	HIDESBASE void __fastcall SetDataType(const AnsiString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLBindingInfo.Create */ inline __fastcall TXMLPropertyBinding(const Xmlschema::_di_IXMLSchemaItem ASchemaItem, const _di_IXMLBindingManager BindingManager) : TXMLBindingInfo(ASchemaItem, BindingManager) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXMLPropertyBinding(void) { }
	#pragma option pop
	
private:
	void *__IXMLPropertyBinding;	/* Xmlbindgen::IXMLPropertyBinding */
	
public:
	operator IXMLPropertyBinding*(void) { return (IXMLPropertyBinding*)&__IXMLPropertyBinding; }
	
};


class DELPHICLASS TCodeWriter;
class PASCALIMPLEMENTATION TCodeWriter : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	_di_IXMLBindingManager FBindingManager;
	bool FModified;
	
protected:
	AnsiString __fastcall PropGetPrefix();
	AnsiString __fastcall PropSetPrefix();
	__property _di_IXMLBindingManager BindingManager = {read=FBindingManager};
	
public:
	__fastcall TCodeWriter(_di_IXMLBindingManager BindingManager);
	virtual void __fastcall Generate(const _di_IXMLComplexTypeBinding BindingInfo);
	virtual void __fastcall Changed(void);
	void __fastcall Write(const AnsiString Code, int Indent = 0x0)/* overload */;
	void __fastcall Write(const AnsiString FmtLine, const System::TVarRec * Params, const int Params_Size, int Indent = 0x0)/* overload */;
	void __fastcall WriteLine(void);
	void __fastcall WriteAfterConstruction(const AnsiString OverrideStr = "", int Indent = 0x0);
	void __fastcall WriteRegisterChildNode(const AnsiString TagName, const AnsiString ChildClass);
	void __fastcall WriteClassDecl(const AnsiString Name, const AnsiString AncestorName, const AnsiString IntfName);
	void __fastcall WriteCollCreate(const AnsiString DataMember, const AnsiString CollClass, const AnsiString ItemInterface, const AnsiString ItemTag, const AnsiString CollInterface);
	void __fastcall WriteCollGetItem(const AnsiString DataType, int Indent = 0x0);
	void __fastcall WriteCollItemInit(const AnsiString ItemTag, const AnsiString ItemInterface);
	void __fastcall WriteCollItemProp(const AnsiString DataType);
	void __fastcall WriteComment(const AnsiString Comment, int Indent = 0x0, int LinePadding = 0x0);
	void __fastcall WriteDataMember(const AnsiString Name, const AnsiString DataType);
	void __fastcall WriteDataProperty(const AnsiString Name, const AnsiString DataType, bool HasWriter);
	void __fastcall WriteDeclComment(const AnsiString Comment, int LinePadding = 0x2);
	void __fastcall WriteFunction(const AnsiString FuncCode, const AnsiString DataType, int Indent = 0x0)/* overload */;
	void __fastcall WriteFunction(const AnsiString FuncName, const AnsiString DataType, const AnsiString * ParamNames, const int ParamNames_Size, const AnsiString * ParamTypes, const int ParamTypes_Size, int Indent = 0x0)/* overload */;
	void __fastcall WriteGetMethod(const AnsiString Name, const AnsiString DataType, int Indent, bool Indexed = false);
	void __fastcall WriteGetBindFunc(const AnsiString SourceName, const AnsiString DataType);
	void __fastcall WriteLoadBindFunc(const AnsiString SourceName, const AnsiString DataType);
	void __fastcall WriteNewBindFunc(const AnsiString SourceName, const AnsiString DataType);
	void __fastcall WriteGuid(void);
	void __fastcall WriteIntfDecl(const AnsiString Name, const AnsiString AncestorType);
	void __fastcall WriteMethodBody(const AnsiString Template, const System::TVarRec * Params, const int Params_Size);
	void __fastcall WriteProperty(const AnsiString Name, const AnsiString DataType, bool HasWriter, bool Indexed = false);
	void __fastcall WriteSetMethod(const AnsiString Name, const AnsiString DataType, int Indent, bool Indexed = false);
	__property bool Modified = {read=FModified, write=FModified, nodefault};
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TCodeWriter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TForwardDecl;
class PASCALIMPLEMENTATION TForwardDecl : public TCodeWriter 
{
	typedef TCodeWriter inherited;
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TCodeWriter.Create */ inline __fastcall TForwardDecl(_di_IXMLBindingManager BindingManager) : TCodeWriter(BindingManager) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TForwardDecl(void) { }
	#pragma option pop
	
};


typedef TCodeWriter* *PCodeWriter;

typedef DynamicArray<TCodeWriter* >  TCodeWriterArray;

class DELPHICLASS TPropertyContainer;
class PASCALIMPLEMENTATION TPropertyContainer : public TCodeWriter 
{
	typedef TCodeWriter inherited;
	
private:
	DynamicArray<TCodeWriter* >  FCodeWriters;
	_di_IXMLComplexTypeBinding FBindingInfo;
	Xmlschema::_di_IXMLComplexTypeDef FTypeDef;
	
protected:
	void __fastcall AppendCode(void)/* overload */;
	void __fastcall AppendCode(const TCodeWriter* * CodeLists, const int CodeLists_Size)/* overload */;
	void __fastcall InitCodeWriters(const PCodeWriter const * CodeWriters, const int CodeWriters_Size, const AnsiString * CodeLines, const int CodeLines_Size);
	virtual void __fastcall WriteCollectionMethods(TCodeWriter* Writer, _di_IXMLDataTypeBinding ItemInfo, int Indent);
	virtual void __fastcall WriteCollAdd(TCodeWriter* Writer, _di_IXMLDataTypeBinding ItemInfo, int Indent);
	virtual void __fastcall WriteCollInsert(TCodeWriter* Writer, _di_IXMLDataTypeBinding ItemInfo, int Indent);
	virtual void __fastcall WriteListBinding(const _di_IXMLDataTypeBinding ItemInfo);
	virtual void __fastcall WriteMethods(void);
	virtual void __fastcall WriteProperties(void);
	HIDESBASE virtual void __fastcall WriteProperty(const _di_IXMLPropertyBinding PropBindInfo, const bool Indexed);
	__property _di_IXMLComplexTypeBinding BindingInfo = {read=FBindingInfo};
	__property TCodeWriterArray CodeWriters = {read=FCodeWriters};
	__property Xmlschema::_di_IXMLComplexTypeDef TypeDef = {read=FTypeDef};
	
public:
	__fastcall virtual ~TPropertyContainer(void);
	virtual void __fastcall Generate(const _di_IXMLComplexTypeBinding BindingInfo);
public:
	#pragma option push -w-inl
	/* TCodeWriter.Create */ inline __fastcall TPropertyContainer(_di_IXMLBindingManager BindingManager) : TCodeWriter(BindingManager) { }
	#pragma option pop
	
};


class DELPHICLASS TIntfSectionEntry;
class PASCALIMPLEMENTATION TIntfSectionEntry : public TPropertyContainer 
{
	typedef TPropertyContainer inherited;
	
protected:
	TCodeWriter* GetMethods;
	TCodeWriter* SetMethods;
	TCodeWriter* PrivateItems;
	TCodeWriter* ProtectedItems;
	TCodeWriter* PublicItems;
	TCodeWriter* PublishedItems;
	virtual void __fastcall WriteDecl(void);
	
public:
	virtual void __fastcall Generate(const _di_IXMLComplexTypeBinding BindingInfo);
public:
	#pragma option push -w-inl
	/* TPropertyContainer.Destroy */ inline __fastcall virtual ~TIntfSectionEntry(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCodeWriter.Create */ inline __fastcall TIntfSectionEntry(_di_IXMLBindingManager BindingManager) : TPropertyContainer(BindingManager) { }
	#pragma option pop
	
};


class DELPHICLASS TIntfForward;
class PASCALIMPLEMENTATION TIntfForward : public TForwardDecl 
{
	typedef TForwardDecl inherited;
	
public:
	virtual void __fastcall Generate(const _di_IXMLComplexTypeBinding BindingInfo);
public:
	#pragma option push -w-inl
	/* TCodeWriter.Create */ inline __fastcall TIntfForward(_di_IXMLBindingManager BindingManager) : TForwardDecl(BindingManager) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TIntfForward(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIntfDecl;
class PASCALIMPLEMENTATION TIntfDecl : public TIntfSectionEntry 
{
	typedef TIntfSectionEntry inherited;
	
protected:
	virtual void __fastcall WriteDecl(void);
	virtual void __fastcall WriteListBinding(const _di_IXMLDataTypeBinding ItemInfo);
	virtual void __fastcall WriteProperty(const _di_IXMLPropertyBinding PropBindInfo, const bool Indexed);
public:
	#pragma option push -w-inl
	/* TPropertyContainer.Destroy */ inline __fastcall virtual ~TIntfDecl(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCodeWriter.Create */ inline __fastcall TIntfDecl(_di_IXMLBindingManager BindingManager) : TIntfSectionEntry(BindingManager) { }
	#pragma option pop
	
};


class DELPHICLASS TClassForward;
class PASCALIMPLEMENTATION TClassForward : public TForwardDecl 
{
	typedef TForwardDecl inherited;
	
public:
	virtual void __fastcall Generate(const _di_IXMLComplexTypeBinding BindingInfo);
public:
	#pragma option push -w-inl
	/* TCodeWriter.Create */ inline __fastcall TClassForward(_di_IXMLBindingManager BindingManager) : TForwardDecl(BindingManager) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TClassForward(void) { }
	#pragma option pop
	
};


class DELPHICLASS TClassDecl;
class PASCALIMPLEMENTATION TClassDecl : public TIntfSectionEntry 
{
	typedef TIntfSectionEntry inherited;
	
private:
	bool FNeedsRegCode;
	
protected:
	virtual void __fastcall WriteDecl(void);
	virtual void __fastcall WriteListBinding(const _di_IXMLDataTypeBinding ItemInfo);
	virtual void __fastcall WriteProperties(void);
	virtual void __fastcall WriteProperty(const _di_IXMLPropertyBinding PropBindInfo, const bool Indexed);
	__property bool NeedsRegCode = {read=FNeedsRegCode, write=FNeedsRegCode, nodefault};
public:
	#pragma option push -w-inl
	/* TPropertyContainer.Destroy */ inline __fastcall virtual ~TClassDecl(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCodeWriter.Create */ inline __fastcall TClassDecl(_di_IXMLBindingManager BindingManager) : TIntfSectionEntry(BindingManager) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLBindingManager;
class PASCALIMPLEMENTATION TXMLBindingManager : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	WideString FBindingAppInfoURI;
	AnsiString FClassNameStr;
	TBindingOptions* FCodeGenOptions;
	TBindingOptions* FNativeTypeMap;
	TIdentifierCheckEvent FOnIdentifierCheck;
	
protected:
	AnsiString __fastcall GetClassNameStr();
	WideString __fastcall GetBindingAppInfoURI();
	TBindingOptions* __fastcall GetCodeGenOptions(void);
	TBindingOptions* __fastcall GetNativeTypeMap(void);
	void __fastcall SetBindingAppInfoURI(const WideString Value);
	void __fastcall SetClassNameStr(const AnsiString Value);
	void __fastcall DoIdentifierCheck(AnsiString &Identifier);
	Classes::_di_IInterfaceList __fastcall GetBindableItems(const Xmlschema::_di_IXMLSchemaDef Schema);
	_di_IXMLBindingInfo __fastcall GetBindingInfo(const System::_di_IInterface ASchemaItem)/* overload */;
	_di_IXMLDataTypeBinding __fastcall GetBindingInfo(const Xmlschema::_di_IXMLTypeDef TypeDef)/* overload */;
	_di_IXMLComplexTypeBinding __fastcall GetBindingInfo(const Xmlschema::_di_IXMLComplexTypeDef ComplexTypeDef)/* overload */;
	_di_IXMLPropertyBinding __fastcall GetBindingInfo(const Xmlschema::_di_IXMLTypedSchemaItem PropertyItem)/* overload */;
	_di_IXMLDataTypeListBinding __fastcall GetListBindingInfo(const Xmlschema::_di_IXMLTypeDef TypeDef);
	AnsiString __fastcall GenerateBinding(const Classes::_di_IInterfaceList BindableItems, TMetaClass* * Writers, const int Writers_Size)/* overload */;
	AnsiString __fastcall GenerateBinding(const Xmlschema::_di_IXMLComplexTypeDef BindableItem, TMetaClass* * Writers, const int Writers_Size)/* overload */;
	AnsiString __fastcall SchemaTypeToNativeType(const Variant &XMLType);
	void __fastcall SetOnIdentifierCheck(const TIdentifierCheckEvent Value);
	
public:
	__fastcall virtual ~TXMLBindingManager(void);
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TXMLBindingManager(void) : System::TInterfacedObject() { }
	#pragma option pop
	
private:
	void *__IXMLBindingManager;	/* Xmlbindgen::IXMLBindingManager */
	
public:
	operator IXMLBindingManager*(void) { return (IXMLBindingManager*)&__IXMLBindingManager; }
	
};


//-- var, const, procedure ---------------------------------------------------
#define aiDBWizPrefix "xdb"
#define aiIdentifierName "identifierName"
#define aiDataType "dataType"
#define aiBound "bound"
#define aiReadOnly "ReadOnly"
#define aiRepeated "repeated"
#define aiDocElement "docElement"
#define SIndex "Index"
#define SInteger "Integer"
#define SIndexCode "Index: Integer"
#define SBegin "begin"
#define SEnd "end;"
#define SAdd "Add"
#define SInsert "Insert"
#define SOverride " override;"
#define SPrivate "private"
#define SProtected "protected"
#define SPublic "public"
#define SPublished "published"
#define STrue "True"
#define SFalse "False"
#define SCodeGen "CodeGen"
#define SDataTypeMap "DataTypeMap"
#define cgPropGetPrefix "PropGetPrefix"
#define cgPropSetPrefix "PropSetPrefix"
#define cgClassPrefix "ClassPrefix"
#define cgInterfacePrefix "IntfPrefix"
#define cgListTypeSuffix "NodeListSuffix"
#define cgNodeIntfBase "NodeIntfBase"
#define cgNodeClassBase "NodeClassBase"
#define cgCollIntfBase "CollIntfBase"
#define cgCollClassBase "CollClassBase"
#define cgDefaultDataType "DefDataType"
extern PACKAGE AnsiString NativeTypes[21];
extern PACKAGE System::ResourceString _SPropertyAccessors;
#define Xmlbindgen_SPropertyAccessors System::LoadResourceString(&Xmlbindgen::_SPropertyAccessors)
extern PACKAGE System::ResourceString _SMethodsAndProps;
#define Xmlbindgen_SMethodsAndProps System::LoadResourceString(&Xmlbindgen::_SMethodsAndProps)
extern PACKAGE System::ResourceString _SForwardDecl;
#define Xmlbindgen_SForwardDecl System::LoadResourceString(&Xmlbindgen::_SForwardDecl)
extern PACKAGE System::ResourceString _SGlobalFunctions;
#define Xmlbindgen_SGlobalFunctions System::LoadResourceString(&Xmlbindgen::_SGlobalFunctions)
extern PACKAGE void __fastcall MakeValidIdent(AnsiString &Ident);

}	/* namespace Xmlbindgen */
using namespace Xmlbindgen;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XMLBindGen
