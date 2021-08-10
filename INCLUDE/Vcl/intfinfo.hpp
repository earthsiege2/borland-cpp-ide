// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IntfInfo.pas' rev: 6.00

#ifndef IntfInfoHPP
#define IntfInfoHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Intfinfo
{
//-- type declarations -------------------------------------------------------
struct TIntfParamEntry;
typedef TIntfParamEntry *PIntfParamEntry;

#pragma pack(push, 4)
struct TIntfParamEntry
{
	Typinfo::TParamFlags Flags;
	AnsiString Name;
	Typinfo::TTypeInfo *Info;
} ;
#pragma pack(pop)

typedef DynamicArray<TIntfParamEntry >  TIntfParamEntryArray;

#pragma option push -b-
enum TCallConv { ccReg, ccCdecl, ccPascal, ccStdCall, ccSafeCall };
#pragma option pop

struct TIntfMethEntry;
typedef TIntfMethEntry *PIntfMethEntry;

#pragma pack(push, 4)
struct TIntfMethEntry
{
	AnsiString Name;
	TCallConv CC;
	int Pos;
	int ParamCount;
	Typinfo::TTypeInfo *ResultInfo;
	Typinfo::TTypeInfo *SelfInfo;
	DynamicArray<TIntfParamEntry >  Params;
	bool HasRTTI;
} ;
#pragma pack(pop)

typedef DynamicArray<TIntfMethEntry >  TIntfMethEntryArray;

typedef DynamicArray<PIntfMethEntry >  TPIntfMethEntryArray;

#pragma option push -b-
enum TFillMethodArrayOpt { fmoAllBaseMethods, fmoRTTIBaseMethods, fmoNoBaseMethods };
#pragma option pop

struct TIntfMetaData;
typedef TIntfMetaData *PIntfMetaData;

#pragma pack(push, 4)
struct TIntfMetaData
{
	AnsiString Name;
	AnsiString UnitName;
	DynamicArray<TIntfMethEntry >  MDA;
	GUID IID;
	Typinfo::TTypeInfo *Info;
	Typinfo::TTypeInfo *AncInfo;
	int NumAnc;
} ;
#pragma pack(pop)

class DELPHICLASS EInterfaceRTTIException;
class PASCALIMPLEMENTATION EInterfaceRTTIException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInterfaceRTTIException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInterfaceRTTIException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInterfaceRTTIException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInterfaceRTTIException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInterfaceRTTIException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInterfaceRTTIException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInterfaceRTTIException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInterfaceRTTIException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInterfaceRTTIException(void) { }
	#pragma option pop
	
};


typedef AnsiString IntfInfo__2[5];

typedef AnsiString IntfInfo__3[34];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString CallingConventionName[5];
extern PACKAGE AnsiString TypeInfoNames[34];
extern PACKAGE int __fastcall GetMethNum(const TIntfMetaData &IntfMD, const AnsiString MethName);
extern PACKAGE void __fastcall GetIntfMetaData(Typinfo::PTypeInfo Info, TIntfMetaData &IntfMD, TFillMethodArrayOpt MethodArrayOpt)/* overload */;
extern PACKAGE void __fastcall GetIntfMetaData(Typinfo::PTypeInfo Info, TIntfMetaData &IntfMD, bool IncludeAllAncMethods = false)/* overload */;
extern PACKAGE void __fastcall GetDynArrayElTypeInfo(Typinfo::PTypeInfo typeInfo, Typinfo::PTypeInfo &EltInfo, int &Dims);
extern PACKAGE Typinfo::PTypeInfo __fastcall GetDynArrayNextInfo(Typinfo::PTypeInfo typeInfo);
extern PACKAGE Typinfo::PTypeInfo __fastcall GetDynArrayNextInfo2(Typinfo::PTypeInfo typeInfo, AnsiString &Name);
extern PACKAGE bool __fastcall SameTypeInfo(const Typinfo::PTypeInfo RegInfo, const Typinfo::PTypeInfo OtherInfo);
extern PACKAGE bool __fastcall TypeNamesMatch(const AnsiString RegName, const AnsiString OtherName);
extern PACKAGE AnsiString __fastcall OtherTypeName(const AnsiString TypeName);
extern PACKAGE int __fastcall GetPropListFlat(Typinfo::PTypeInfo TypeInfo, /* out */ Typinfo::PPropList &PropList);
extern PACKAGE bool __fastcall IsStoredPropConst(System::TObject* Instance, Typinfo::PPropInfo PropInfo);
extern PACKAGE Typinfo::PTypeInfo __fastcall GetClsMemberTypeInfo(const Typinfo::PTypeInfo ObjectTypeInfo, const AnsiString MemberName = "");

}	/* namespace Intfinfo */
using namespace Intfinfo;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IntfInfo
