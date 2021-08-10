// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'InvokeRegistry.pas' rev: 6.00

#ifndef InvokeRegistryHPP
#define InvokeRegistryHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLSchema.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <IntfInfo.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#if defined(__WIN32__)
#pragma link "wininet.lib"
#endif
namespace Invokeregistry {
struct TDynToClear;
};
using Invokeregistry::TDynToClear;

namespace Invokeregistry
{
//-- type declarations -------------------------------------------------------
typedef WideString InvString;

class DELPHICLASS TInvokableClass;
class PASCALIMPLEMENTATION TInvokableClass : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	__fastcall virtual TInvokableClass(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TInvokableClass(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TInvokableClassClass;

#pragma option push -b-
enum SerializationOptions { xoHolderClass, xoAttributeOnLastMember, xoInlineArrays, xoLiteralParam, xoOption5, xoOption6, xoOption7, xoOption8, xoOption9, xoOptionA, xoOptionB, xoOptionC, xoOptionD, xoOptionE, xoOptionF, xoOptionG, xoOptionH, xoOptionI };
#pragma option pop

typedef Set<SerializationOptions, xoHolderClass, xoOptionI>  TSerializationOptions;

class DELPHICLASS TRemotable;
class DELPHICLASS TDataContext;
typedef DynamicArray<System::TObject* >  InvokeRegistry__51;

typedef DynamicArray<Byte >  InvokeRegistry__61;

typedef DynamicArray<void * >  InvokeRegistry__71;

typedef DynamicArray<void * >  InvokeRegistry__81;

typedef DynamicArray<TDynToClear >  InvokeRegistry__91;

typedef DynamicArray<void * >  InvokeRegistry__02;

class PASCALIMPLEMENTATION TDataContext : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	DynamicArray<System::TObject* >  FObjsToDestroy;
	int DataOffset;
	DynamicArray<Byte >  Data;
	DynamicArray<void * >  DataP;
	DynamicArray<void * >  VarToClear;
	DynamicArray<TDynToClear >  DynArrayToClear;
	DynamicArray<void * >  StrToClear;
	
public:
	__fastcall TDataContext(void);
	__fastcall virtual ~TDataContext(void);
	void * __fastcall AllocData(int Size);
	void __fastcall SetDataPointer(int Index, void * P);
	void * __fastcall GetDataPointer(int Index);
	void __fastcall AddObjectToDestroy(System::TObject* Obj);
	void __fastcall RemoveObjectToDestroy(System::TObject* Obj);
	void __fastcall AddDynArrayToClear(void * P, Typinfo::PTypeInfo Info);
	void __fastcall AddVariantToClear(PVarData P);
	void __fastcall AddStrToClear(void * P);
};


class PASCALIMPLEMENTATION TRemotable : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TDataContext* FDataContext;
	void __fastcall SetDataContext(TDataContext* Value);
	
protected:
	TSerializationOptions FSerializationOptions;
	
public:
	__fastcall virtual TRemotable(void);
	__fastcall virtual ~TRemotable(void);
	__property TDataContext* DataContext = {read=FDataContext, write=SetDataContext};
	__property TSerializationOptions SerializationOptions = {read=FSerializationOptions, nodefault};
};


class DELPHICLASS TRemotableXS;
class PASCALIMPLEMENTATION TRemotableXS : public TRemotable 
{
	typedef TRemotable inherited;
	
public:
	virtual WideString __fastcall NativeToXS();
	virtual void __fastcall XSToNative(WideString Data);
public:
	#pragma option push -w-inl
	/* TRemotable.Create */ inline __fastcall virtual TRemotableXS(void) : TRemotable() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TRemotable.Destroy */ inline __fastcall virtual ~TRemotableXS(void) { }
	#pragma option pop
	
};


typedef TRemotable* *PTRemotable;

typedef TMetaClass*TRemotableClass;

typedef TMetaClass*TRemotableXSClass;

class DELPHICLASS ERemotableException;
class PASCALIMPLEMENTATION ERemotableException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
private:
	WideString FFaultActor;
	WideString FFaultCode;
	WideString FFaultDetail;
	
public:
	__fastcall virtual ERemotableException(void);
	__property WideString FaultActor = {read=FFaultActor, write=FFaultActor};
	__property WideString FaultCode = {read=FFaultCode, write=FFaultCode};
	__property WideString FaultDetail = {read=FFaultDetail, write=FFaultDetail};
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ERemotableException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ERemotableException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ERemotableException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ERemotableException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ERemotableException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ERemotableException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ERemotableException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ERemotableException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ERemotableException(void) { }
	#pragma option pop
	
};


typedef TMetaClass*ERemotableExceptionClass;

typedef void __fastcall (*TCreateInstanceProc)(/* out */ System::TObject* &obj);

#pragma pack(push, 4)
struct InvRegClassEntry
{
	TMetaClass*ClassType;
	TCreateInstanceProc Proc;
	AnsiString URI;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct ExtNameMapItem
{
	AnsiString Name;
	WideString ExtName;
} ;
#pragma pack(pop)

typedef DynamicArray<ExtNameMapItem >  InvokeRegistry__5;

#pragma pack(push, 4)
struct MethParamNameMapItem
{
	AnsiString MethName;
	DynamicArray<ExtNameMapItem >  ParamNameMap;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TIntfInvokeOption { ioDefault, ioDocument, ioLiteral, ioHasDefaultSOAPAction, ioHasReturnParamNames, ioHasNamespace };
#pragma option pop

typedef Set<TIntfInvokeOption, ioDefault, ioHasNamespace>  TIntfInvokeOptions;

typedef DynamicArray<ExtNameMapItem >  InvokeRegistry__6;

typedef DynamicArray<MethParamNameMapItem >  InvokeRegistry__7;

#pragma pack(push, 4)
struct InvRegIntfEntry
{
	AnsiString Name;
	WideString ExtName;
	AnsiString UnitName;
	GUID GUID;
	Typinfo::TTypeInfo *Info;
	TMetaClass*DefImpl;
	WideString Namespace;
	WideString WSDLEncoding;
	AnsiString Documentation;
	AnsiString DefaultSOAPAction;
	AnsiString ReturnParamNames;
	TIntfInvokeOptions InvokeOptions;
	DynamicArray<ExtNameMapItem >  MethNameMap;
	DynamicArray<MethParamNameMapItem >  MethParamNameMap;
} ;
#pragma pack(pop)

typedef DynamicArray<InvRegIntfEntry >  TInvRegIntfEntryArray;

typedef DynamicArray<InvRegClassEntry >  InvokeRegistry__9;

typedef DynamicArray<InvRegIntfEntry >  InvokeRegistry__01;

class DELPHICLASS TInvokableClassRegistry;
class PASCALIMPLEMENTATION TInvokableClassRegistry : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_RTL_CRITICAL_SECTION FLock;
	DynamicArray<InvRegClassEntry >  FRegClasses;
	DynamicArray<InvRegIntfEntry >  FRegIntfs;
	void __fastcall DeleteFromReg(TMetaClass* AClass, Typinfo::PTypeInfo Info);
	
public:
	__fastcall TInvokableClassRegistry(void);
	__fastcall virtual ~TInvokableClassRegistry(void);
	void __fastcall RegisterInterface(Typinfo::PTypeInfo Info, const WideString Namespace, const WideString WSDLEncoding, const AnsiString Doc, const WideString ExtName)/* overload */;
	void __fastcall RegisterInterface(Typinfo::PTypeInfo Info, const WideString Namespace, const WideString WSDLEncoding, const AnsiString Doc)/* overload */;
	void __fastcall RegisterInterface(Typinfo::PTypeInfo Info, const WideString Namespace, const WideString WSDLEncoding)/* overload */;
	void __fastcall RegisterInterface(Typinfo::PTypeInfo Info, const WideString Namespace)/* overload */;
	void __fastcall RegisterInterface(Typinfo::PTypeInfo Info)/* overload */;
	void __fastcall RegisterExternalMethName(Typinfo::PTypeInfo Info, AnsiString InternalName, const WideString ExternalName);
	void __fastcall RegisterExternalParamName(Typinfo::PTypeInfo Info, AnsiString MethodName, AnsiString InternalName, const WideString ExternalName);
	void __fastcall RegisterInvokableClass(TMetaClass* AClass, TCreateInstanceProc CreateProc)/* overload */;
	void __fastcall RegisterInvokableClass(TMetaClass* AClass)/* overload */;
	void __fastcall RegisterDefaultSOAPAction(Typinfo::PTypeInfo Info, const WideString DefSOAPAction);
	AnsiString __fastcall GetActionURIOfInfo(const Typinfo::PTypeInfo IntfInfo, const WideString MethodName);
	AnsiString __fastcall GetActionURIOfIID(const GUID &AGUID);
	void __fastcall RegisterReturnParamNames(Typinfo::PTypeInfo Info, const AnsiString RetParamNames);
	AnsiString __fastcall GetReturnParamNames(const Typinfo::PTypeInfo IntfInfo);
	void __fastcall RegisterInvokeOptions(Typinfo::PTypeInfo Info, const TIntfInvokeOption InvokeOption)/* overload */;
	void __fastcall RegisterInvokeOptions(Typinfo::PTypeInfo Info, const TIntfInvokeOptions InvokeOptions)/* overload */;
	
private:
	virtual void __fastcall Lock(void);
	virtual void __fastcall UnLock(void);
	
public:
	AnsiString __fastcall GetNamespaceByGUID(const GUID &AGUID);
	bool __fastcall GetInfoForURI(const AnsiString PathURI, const AnsiString ActionURI, TMetaClass* &ACLass, Typinfo::PTypeInfo &IntfInfo, AnsiString &AMeth);
	TIntfInvokeOptions __fastcall GetIntfInvokeOptions(const Typinfo::PTypeInfo IntfInfo)/* overload */;
	TIntfInvokeOptions __fastcall GetIntfInvokeOptions(const GUID &AGUID)/* overload */;
	void __fastcall GetInterfaceInfoFromName(const AnsiString UnitName, const AnsiString IntfName, Typinfo::PTypeInfo &Info, GUID &IID);
	void * __fastcall GetInterfaceTypeInfo(const GUID &AGUID);
	System::TObject* __fastcall GetInvokableObjectFromClass(TMetaClass* AClass);
	InvRegIntfEntry __fastcall GetRegInterfaceEntry(int Index);
	void __fastcall GetClassFromIntfInfo(Typinfo::PTypeInfo Info, TMetaClass* &AClass);
	int __fastcall GetInterfaceCount(void);
	WideString __fastcall GetInterfaceExternalName(Typinfo::PTypeInfo Info, AnsiString Namespace, AnsiString InternalIntfName)/* overload */;
	WideString __fastcall GetInterfaceExternalName(Typinfo::PTypeInfo Info, AnsiString Namespace)/* overload */;
	WideString __fastcall GetInterfaceExternalName(Typinfo::PTypeInfo Info)/* overload */;
	WideString __fastcall GetWSDLEncoding(Typinfo::PTypeInfo Info, AnsiString Namespace, AnsiString InternalIntfName)/* overload */;
	WideString __fastcall GetWSDLEncoding(Typinfo::PTypeInfo Info, AnsiString Namespace)/* overload */;
	WideString __fastcall GetWSDLEncoding(Typinfo::PTypeInfo Info)/* overload */;
	void __fastcall UnRegisterInterface(Typinfo::PTypeInfo Info);
	void __fastcall UnRegisterInvokableClass(TMetaClass* AClass);
	WideString __fastcall GetParamExternalName(Typinfo::PTypeInfo Info, AnsiString MethodName, AnsiString InternalParamName);
	AnsiString __fastcall GetParamInternalName(Typinfo::PTypeInfo Info, AnsiString MethodName, WideString ExternalParamName);
	WideString __fastcall GetMethExternalName(Typinfo::PTypeInfo Info, AnsiString MethodIntName);
	AnsiString __fastcall GetMethInternalName(Typinfo::PTypeInfo Info, WideString MethodExtName);
};


#pragma option push -b-
enum TObjMultiOptions { ocDefault, ocMultiRef, ocNoMultiRef };
#pragma option pop

#pragma pack(push, 4)
struct TRemRegEntry
{
	TMetaClass*ClassType;
	Typinfo::TTypeInfo *Info;
	WideString URI;
	WideString Name;
	WideString ExtName;
	bool IsScalar;
	TObjMultiOptions MultiRefOpt;
	TSerializationOptions SerializationOpt;
} ;
#pragma pack(pop)

class DELPHICLASS ETypeRegistryException;
class PASCALIMPLEMENTATION ETypeRegistryException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ETypeRegistryException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ETypeRegistryException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ETypeRegistryException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ETypeRegistryException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ETypeRegistryException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ETypeRegistryException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ETypeRegistryException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ETypeRegistryException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ETypeRegistryException(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TRemRegEntry >  InvokeRegistry__31;

class DELPHICLASS TRemotableTypeRegistry;
class PASCALIMPLEMENTATION TRemotableTypeRegistry : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FAutoRegister;
	_RTL_CRITICAL_SECTION FLock;
	DynamicArray<TRemRegEntry >  URIMap;
	int __fastcall GetEntry(Typinfo::PTypeInfo Info, bool &Found, WideString Name = L"");
	void __fastcall DeleteEntryFromURIMap(Typinfo::PTypeInfo Info);
	Typinfo::PTypeInfo __fastcall GetSimpleBuiltInXSDType(const WideString URI, const WideString TypeName);
	TMetaClass* __fastcall GetRegisteredClassForBuiltInXSD(const WideString TypeName);
	
protected:
	virtual void __fastcall Lock(void);
	virtual void __fastcall UnLock(void);
	
public:
	__fastcall TRemotableTypeRegistry(void);
	__fastcall virtual ~TRemotableTypeRegistry(void);
	void __fastcall RegisterXSClass(TMetaClass* AClass, WideString URI, WideString Name, WideString ExtName, bool IsScalar, TObjMultiOptions MultiRefOpt)/* overload */;
	void __fastcall RegisterXSClass(TMetaClass* AClass, WideString URI, WideString Name, WideString ExtName, bool IsScalar)/* overload */;
	void __fastcall RegisterXSClass(TMetaClass* AClass, WideString URI, WideString Name, WideString ExtName)/* overload */;
	void __fastcall RegisterXSClass(TMetaClass* AClass, WideString URI, WideString Name)/* overload */;
	void __fastcall RegisterXSClass(TMetaClass* AClass, WideString URI)/* overload */;
	void __fastcall RegisterXSClass(TMetaClass* AClass)/* overload */;
	void __fastcall RegisterXSInfo(Typinfo::PTypeInfo Info, WideString URI, WideString Name, WideString ExtName)/* overload */;
	void __fastcall RegisterXSInfo(Typinfo::PTypeInfo Info, WideString URI, WideString Name)/* overload */;
	void __fastcall RegisterXSInfo(Typinfo::PTypeInfo Info, WideString URI)/* overload */;
	void __fastcall RegisterXSInfo(Typinfo::PTypeInfo Info)/* overload */;
	void __fastcall RegisterHolderClsMember(Typinfo::PTypeInfo ClsTypeInfo, WideString URI = L"", WideString Name = L"", WideString ExtName = L"");
	bool __fastcall ClassToURI(TMetaClass* AClass, WideString &URI, WideString &Name, bool &IsScalar, bool tryToRegister = true);
	bool __fastcall InfoToURI(Typinfo::PTypeInfo Info, WideString &URI, WideString &Name, bool &IsScalar, bool tryToRegister = true);
	bool __fastcall TypeInfoToXSD(Typinfo::PTypeInfo Info, WideString &URI, WideString &TypeName);
	void __fastcall GetXSDInfoForClass(Typinfo::PTypeInfo Info, WideString &URI, WideString &TypeName);
	TMetaClass* __fastcall URIToClass(WideString URI, WideString Name, bool &IsScalar);
	Typinfo::PTypeInfo __fastcall XSDToTypeInfo(WideString URI, WideString TypeName);
	Typinfo::PTypeInfo __fastcall URIToInfo(const WideString URI, const WideString Name);
	int __fastcall GetURICount(void);
	TRemRegEntry __fastcall GetURIMap(int Index)/* overload */;
	bool __fastcall GetURIMap(int Index, /* out */ TRemRegEntry &RegEntry)/* overload */;
	bool __fastcall IsClassScalar(TMetaClass* AClass);
	TObjMultiOptions __fastcall ClassOptions(TMetaClass* AClass);
	Typinfo::PTypeInfo __fastcall VariantToInfo(const Variant &V, bool TryAllSchema);
	Word __fastcall GetVarTypeFromXSD(WideString URI, WideString TypeName);
	void __fastcall RegisterSerializeOptions(TMetaClass* AClass, TSerializationOptions SerialOpt);
	TSerializationOptions __fastcall SerializeOptions(TMetaClass* AClass);
	void __fastcall UnRegisterXSClass(TMetaClass* AClass);
	void __fastcall UnRegisterXSInfo(Typinfo::PTypeInfo Info);
	void __fastcall RegisterExternalPropName(Typinfo::PTypeInfo Info, AnsiString InternalName, const WideString ExternalName);
	WideString __fastcall GetExternalPropName(Typinfo::PTypeInfo Info, AnsiString InternalName);
	AnsiString __fastcall GetInternalPropName(Typinfo::PTypeInfo Info, WideString ExternalName);
	__property bool AutoRegisterNativeTypes = {read=FAutoRegister, write=FAutoRegister, nodefault};
};


typedef TRemotableTypeRegistry TRemotableClassRegistry;
;

typedef TRemotableTypeRegistry TPascalRemotableTypeRegistry;
;

typedef TRemotableTypeRegistry TPascalRemotableClassRegistry;
;

#pragma pack(push, 4)
struct TDynToClear
{
	void *P;
	Typinfo::TTypeInfo *Info;
} ;
#pragma pack(pop)

class DELPHICLASS TInvContext;
class PASCALIMPLEMENTATION TInvContext : public TDataContext 
{
	typedef TDataContext inherited;
	
private:
	void *ResultP;
	
public:
	void __fastcall SetMethodInfo(const Intfinfo::TIntfMethEntry &MD);
	void __fastcall SetParamPointer(int Param, void * P);
	void * __fastcall GetParamPointer(int Param);
	void * __fastcall GetResultPointer(void);
	void __fastcall SetResultPointer(void * P);
	void __fastcall AllocServerData(const Intfinfo::TIntfMethEntry &MD);
public:
	#pragma option push -w-inl
	/* TDataContext.Create */ inline __fastcall TInvContext(void) : TDataContext() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataContext.Destroy */ inline __fastcall virtual ~TInvContext(void) { }
	#pragma option pop
	
};


typedef WideString InvokeRegistry__22[3];

typedef WideString InvokeRegistry__32[3];

typedef WideString InvokeRegistry__42[2];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString AppNameSpacePrefix;
extern PACKAGE WideString XMLSchemaInstNamepspaces[3];
extern PACKAGE WideString XMLSchemaNamepspaces[3];
extern PACKAGE WideString XMLBase64Types[2];
static const bool AS_ATTRIBUTE = false;
extern PACKAGE WideString __fastcall SubstituteStrings(const WideString InputString, const WideString SubString, const WideString Replacement);
extern PACKAGE TInvokableClassRegistry* __fastcall InvRegistry(void);
extern PACKAGE TRemotableTypeRegistry* __fastcall RemClassRegistry(void);
extern PACKAGE TRemotableTypeRegistry* __fastcall RemTypeRegistry(void);
extern PACKAGE void * __fastcall GetRemotableDataContext(void);
extern PACKAGE void __fastcall SetRemotableDataContext(void * Value);

}	/* namespace Invokeregistry */
using namespace Invokeregistry;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// InvokeRegistry
