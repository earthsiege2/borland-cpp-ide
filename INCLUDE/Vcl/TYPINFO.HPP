// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TypInfo.pas' rev: 6.00

#ifndef TypInfoHPP
#define TypInfoHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Typinfo
{
  enum TParamFlag {pfVar, pfConst, pfArray, pfAddress, pfReference, pfOut};
  enum TIntfFlag {ifHasGuid, ifDispInterface, ifDispatch};
  typedef SetBase<TParamFlag, pfVar, pfOut> TParamFlagsBase;
  typedef SetBase<TIntfFlag, ifHasGuid, ifDispatch> TIntfFlagsBase;
}

namespace Typinfo
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TTypeKind { tkUnknown, tkInteger, tkChar, tkEnumeration, tkFloat, tkString, tkSet, tkClass, tkMethod, tkWChar, tkLString, tkWString, tkVariant, tkArray, tkRecord, tkInterface, tkInt64, tkDynArray };
#pragma option pop

class DELPHICLASS TPublishableVariantType;
class PASCALIMPLEMENTATION TPublishableVariantType : public Variants::TInvokeableVariantType 
{
	typedef Variants::TInvokeableVariantType inherited;
	
protected:
	virtual System::TObject* __fastcall GetInstance(const TVarData &V) = 0 ;
	
public:
	virtual bool __fastcall GetProperty(TVarData &Dest, const TVarData &V, const AnsiString Name);
	virtual bool __fastcall SetProperty(const TVarData &V, const AnsiString Name, const TVarData &Value);
public:
	#pragma option push -w-inl
	/* TCustomVariantType.Create */ inline __fastcall TPublishableVariantType(void)/* overload */ : Variants::TInvokeableVariantType() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomVariantType.Destroy */ inline __fastcall virtual ~TPublishableVariantType(void) { }
	#pragma option pop
	
private:
	void *__IVarInstanceReference;	/* Variants::IVarInstanceReference */
	
public:
	operator IVarInstanceReference*(void) { return (IVarInstanceReference*)&__IVarInstanceReference; }
	
};


typedef Set<TTypeKind, tkUnknown, tkDynArray>  TTypeKinds;

#pragma option push -b-
enum TOrdType { otSByte, otUByte, otSWord, otUWord, otSLong, otULong };
#pragma option pop

#pragma option push -b-
enum TFloatType { ftSingle, ftDouble, ftExtended, ftComp, ftCurr };
#pragma option pop

#pragma option push -b-
enum TMethodKind { mkProcedure, mkFunction, mkConstructor, mkDestructor, mkClassProcedure, mkClassFunction, mkSafeProcedure, mkSafeFunction };
#pragma option pop

typedef Set<TParamFlag, pfVar, pfOut>  TParamFlags;

typedef Set<TIntfFlag, ifHasGuid, ifDispatch>  TIntfFlags;

struct TTypeInfo;
typedef TTypeInfo *PTypeInfo;

typedef PTypeInfo *PPTypeInfo;

#pragma pack(push, 1)
struct TTypeInfo
{
	TTypeKind Kind;
	System::ShortString Name;
} ;
#pragma pack(pop)

struct TTypeData;
typedef TTypeData *PTypeData;

#pragma pack(push, 1)
struct TTypeData
{
	
	union
	{
		struct 
		{
			int elSize;
			PTypeInfo *elType;
			int varType;
			PTypeInfo *elType2;
			ShortStringBase DynUnitName;
			
		};
		struct 
		{
			__int64 MinInt64Value;
			__int64 MaxInt64Value;
			
		};
		struct 
		{
			PTypeInfo *IntfParent;
			TIntfFlagsBase IntfFlags;
			GUID Guid;
			ShortStringBase IntfUnit;
			
		};
		struct 
		{
			TMethodKind MethodKind;
			Byte ParamCount;
			char ParamList[1024];
			
		};
		struct 
		{
			TMetaClass*ClassType;
			PTypeInfo *ParentInfo;
			short PropCount;
			ShortStringBase UnitName;
			
		};
		struct 
		{
			Byte MaxLength;
			
		};
		struct 
		{
			TFloatType FloatType;
			
		};
		struct 
		{
			TOrdType OrdType;
			union
			{
				struct 
				{
					PTypeInfo *CompType;
					
				};
				struct 
				{
					int MinValue;
					int MaxValue;
					union
					{
						struct 
						{
							PTypeInfo *BaseType;
							ShortStringBase NameList;
							ShortStringBase EnumUnitName;
							
						};
						
					};
				};
				
			};
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TypInfo__2
{
	
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TPropData
{
	Word PropCount;
	TypInfo__2 PropList;
} ;
#pragma pack(pop)

struct TPropInfo;
typedef TPropInfo *PPropInfo;

#pragma pack(push, 1)
struct TPropInfo
{
	PTypeInfo *PropType;
	void *GetProc;
	void *SetProc;
	void *StoredProc;
	int Index;
	int Default;
	short NameIndex;
	System::ShortString Name;
} ;
#pragma pack(pop)

typedef void __fastcall (__closure *TPropInfoProc)(PPropInfo PropInfo);

typedef TPropInfo *TPropList[16380];

typedef PPropInfo *PPropList;

class DELPHICLASS EPropertyError;
class PASCALIMPLEMENTATION EPropertyError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EPropertyError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EPropertyError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EPropertyError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPropertyError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPropertyError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPropertyError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPropertyError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPropertyError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPropertyError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EPropertyConvertError;
class PASCALIMPLEMENTATION EPropertyConvertError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EPropertyConvertError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EPropertyConvertError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EPropertyConvertError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPropertyConvertError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPropertyConvertError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPropertyConvertError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPropertyConvertError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPropertyConvertError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPropertyConvertError(void) { }
	#pragma option pop
	
};


typedef AnsiString TypInfo__5[2];

//-- var, const, procedure ---------------------------------------------------
#define tkAny (System::Set<TTypeKind, tkUnknown, tkDynArray> () << TTypeKind(0) << TTypeKind(1) << TTypeKind(2) << TTypeKind(3) << TTypeKind(4) << TTypeKind(5) << TTypeKind(6) << TTypeKind(7) << TTypeKind(8) << TTypeKind(9) << TTypeKind(10) << TTypeKind(11) << TTypeKind(12) << TTypeKind(13) << TTypeKind(14) << TTypeKind(15) << TTypeKind(16) << TTypeKind(17) )
#define tkMethods (System::Set<TTypeKind, tkUnknown, tkDynArray> () << TTypeKind(8) )
#define tkProperties (System::Set<TTypeKind, tkUnknown, tkDynArray> () << TTypeKind(1) << TTypeKind(2) << TTypeKind(3) << TTypeKind(4) << TTypeKind(5) << TTypeKind(6) << TTypeKind(7) << TTypeKind(9) << TTypeKind(10) << TTypeKind(11) << TTypeKind(12) << TTypeKind(13) << TTypeKind(14) << TTypeKind(15) << TTypeKind(16) << TTypeKind(17) )
extern PACKAGE AnsiString BooleanIdents[2];
extern PACKAGE AnsiString DotSep;
extern PACKAGE bool __fastcall IsPublishedProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE bool __fastcall IsPublishedProp(TMetaClass* AClass, const AnsiString PropName)/* overload */;
extern PACKAGE PPropInfo __fastcall GetPropInfo(System::TObject* Instance, const AnsiString PropName, TTypeKinds AKinds = System::Set<TTypeKind, tkUnknown, tkDynArray> () )/* overload */;
extern PACKAGE PPropInfo __fastcall GetPropInfo(TMetaClass* AClass, const AnsiString PropName, TTypeKinds AKinds = System::Set<TTypeKind, tkUnknown, tkDynArray> () )/* overload */;
extern PACKAGE bool __fastcall PropIsType(System::TObject* Instance, const AnsiString PropName, TTypeKind TypeKind)/* overload */;
extern PACKAGE bool __fastcall PropIsType(TMetaClass* AClass, const AnsiString PropName, TTypeKind TypeKind)/* overload */;
extern PACKAGE TTypeKind __fastcall PropType(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE TTypeKind __fastcall PropType(TMetaClass* AClass, const AnsiString PropName)/* overload */;
extern PACKAGE bool __fastcall IsStoredProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE int __fastcall GetOrdProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE void __fastcall SetOrdProp(System::TObject* Instance, const AnsiString PropName, int Value)/* overload */;
extern PACKAGE AnsiString __fastcall GetEnumProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE void __fastcall SetEnumProp(System::TObject* Instance, const AnsiString PropName, const AnsiString Value)/* overload */;
extern PACKAGE AnsiString __fastcall GetSetProp(System::TObject* Instance, const AnsiString PropName, bool Brackets = false)/* overload */;
extern PACKAGE void __fastcall SetSetProp(System::TObject* Instance, const AnsiString PropName, const AnsiString Value)/* overload */;
extern PACKAGE System::TObject* __fastcall GetObjectProp(System::TObject* Instance, const AnsiString PropName, TMetaClass* MinClass = 0x0)/* overload */;
extern PACKAGE void __fastcall SetObjectProp(System::TObject* Instance, const AnsiString PropName, System::TObject* Value)/* overload */;
extern PACKAGE TMetaClass* __fastcall GetObjectPropClass(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE AnsiString __fastcall GetStrProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE void __fastcall SetStrProp(System::TObject* Instance, const AnsiString PropName, const AnsiString Value)/* overload */;
extern PACKAGE WideString __fastcall GetWideStrProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE void __fastcall SetWideStrProp(System::TObject* Instance, const AnsiString PropName, const WideString Value)/* overload */;
extern PACKAGE Extended __fastcall GetFloatProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE void __fastcall SetFloatProp(System::TObject* Instance, const AnsiString PropName, const Extended Value)/* overload */;
extern PACKAGE Variant __fastcall GetVariantProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE void __fastcall SetVariantProp(System::TObject* Instance, const AnsiString PropName, const Variant &Value)/* overload */;
extern PACKAGE System::TMethod __fastcall GetMethodProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE void __fastcall SetMethodProp(System::TObject* Instance, const AnsiString PropName, const System::TMethod &Value)/* overload */;
extern PACKAGE __int64 __fastcall GetInt64Prop(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE void __fastcall SetInt64Prop(System::TObject* Instance, const AnsiString PropName, const __int64 Value)/* overload */;
extern PACKAGE Variant __fastcall GetPropValue(System::TObject* Instance, const AnsiString PropName, bool PreferStrings = true);
extern PACKAGE void __fastcall SetPropValue(System::TObject* Instance, const AnsiString PropName, const Variant &Value);
extern PACKAGE void __fastcall FreeAndNilProperties(System::TObject* AObject);
extern PACKAGE PTypeData __fastcall GetTypeData(PTypeInfo TypeInfo);
extern PACKAGE AnsiString __fastcall GetEnumName(PTypeInfo TypeInfo, int Value);
extern PACKAGE int __fastcall GetEnumValue(PTypeInfo TypeInfo, const AnsiString Name);
extern PACKAGE PPropInfo __fastcall GetPropInfo(PTypeInfo TypeInfo, const AnsiString PropName)/* overload */;
extern PACKAGE PPropInfo __fastcall GetPropInfo(PTypeInfo TypeInfo, const AnsiString PropName, TTypeKinds AKinds)/* overload */;
extern PACKAGE void __fastcall GetPropInfos(PTypeInfo TypeInfo, PPropList PropList);
extern PACKAGE void __fastcall SortPropList(PPropList PropList, int PropCount);
extern PACKAGE int __fastcall GetPropList(PTypeInfo TypeInfo, TTypeKinds TypeKinds, PPropList PropList, bool SortList = true)/* overload */;
extern PACKAGE int __fastcall GetPropList(PTypeInfo TypeInfo, /* out */ PPropList &PropList)/* overload */;
extern PACKAGE int __fastcall GetPropList(System::TObject* AObject, /* out */ PPropList &PropList)/* overload */;
extern PACKAGE bool __fastcall IsStoredProp(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE int __fastcall GetOrdProp(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE void __fastcall SetOrdProp(System::TObject* Instance, PPropInfo PropInfo, int Value)/* overload */;
extern PACKAGE AnsiString __fastcall GetEnumProp(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE void __fastcall SetEnumProp(System::TObject* Instance, PPropInfo PropInfo, const AnsiString Value)/* overload */;
extern PACKAGE AnsiString __fastcall GetSetProp(System::TObject* Instance, PPropInfo PropInfo, bool Brackets = false)/* overload */;
extern PACKAGE AnsiString __fastcall SetToString(PPropInfo PropInfo, int Value, bool Brackets = false);
extern PACKAGE int __fastcall StringToSet(PPropInfo PropInfo, const AnsiString Value);
extern PACKAGE void __fastcall SetSetProp(System::TObject* Instance, PPropInfo PropInfo, const AnsiString Value)/* overload */;
extern PACKAGE System::TObject* __fastcall GetObjectProp(System::TObject* Instance, PPropInfo PropInfo, TMetaClass* MinClass = 0x0)/* overload */;
extern PACKAGE void __fastcall SetObjectProp(System::TObject* Instance, PPropInfo PropInfo, System::TObject* Value, bool ValidateClass = true)/* overload */;
extern PACKAGE TMetaClass* __fastcall GetObjectPropClass(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE TMetaClass* __fastcall GetObjectPropClass(PPropInfo PropInfo)/* overload */;
extern PACKAGE AnsiString __fastcall GetStrProp(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE void __fastcall SetStrProp(System::TObject* Instance, PPropInfo PropInfo, const AnsiString Value)/* overload */;
extern PACKAGE WideString __fastcall GetWideStrProp(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE void __fastcall SetWideStrProp(System::TObject* Instance, PPropInfo PropInfo, const WideString Value)/* overload */;
extern PACKAGE Extended __fastcall GetFloatProp(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE void __fastcall SetFloatProp(System::TObject* Instance, PPropInfo PropInfo, const Extended Value)/* overload */;
extern PACKAGE Variant __fastcall GetVariantProp(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE void __fastcall SetVariantProp(System::TObject* Instance, PPropInfo PropInfo, const Variant &Value)/* overload */;
extern PACKAGE System::TMethod __fastcall GetMethodProp(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE void __fastcall SetMethodProp(System::TObject* Instance, PPropInfo PropInfo, const System::TMethod &Value)/* overload */;
extern PACKAGE __int64 __fastcall GetInt64Prop(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE void __fastcall SetInt64Prop(System::TObject* Instance, PPropInfo PropInfo, const __int64 Value)/* overload */;
extern PACKAGE System::_di_IInterface __fastcall GetInterfaceProp(System::TObject* Instance, const AnsiString PropName)/* overload */;
extern PACKAGE void __fastcall SetInterfaceProp(System::TObject* Instance, const AnsiString PropName, const System::_di_IInterface Value)/* overload */;
extern PACKAGE System::_di_IInterface __fastcall GetInterfaceProp(System::TObject* Instance, PPropInfo PropInfo)/* overload */;
extern PACKAGE void __fastcall SetInterfaceProp(System::TObject* Instance, PPropInfo PropInfo, const System::_di_IInterface Value)/* overload */;

}	/* namespace Typinfo */
using namespace Typinfo;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TypInfo
