// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ConvUtils.pas' rev: 6.00

#ifndef ConvUtilsHPP
#define ConvUtilsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Convutils
{
//-- type declarations -------------------------------------------------------
typedef Word TConvFamily;

typedef Word TConvType;

typedef double __fastcall (*TConversionProc)(const double AValue);

typedef DynamicArray<TConvType >  TConvTypeArray;

typedef DynamicArray<TConvFamily >  TConvFamilyArray;

class DELPHICLASS EConversionError;
class PASCALIMPLEMENTATION EConversionError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EConversionError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EConversionError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EConversionError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EConversionError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EConversionError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EConversionError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EConversionError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EConversionError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EConversionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TConvTypeInfo;
class PASCALIMPLEMENTATION TConvTypeInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FDescription;
	TConvFamily FConvFamily;
	TConvType FConvType;
	
public:
	__fastcall TConvTypeInfo(const TConvFamily AConvFamily, const AnsiString ADescription);
	virtual double __fastcall ToCommon(const double AValue) = 0 ;
	virtual double __fastcall FromCommon(const double AValue) = 0 ;
	__property TConvFamily ConvFamily = {read=FConvFamily, nodefault};
	__property TConvType ConvType = {read=FConvType, nodefault};
	__property AnsiString Description = {read=FDescription};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TConvTypeInfo(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TConvTypeInfo* >  TConvTypeList;

class DELPHICLASS TConvTypeFactor;
class PASCALIMPLEMENTATION TConvTypeFactor : public TConvTypeInfo 
{
	typedef TConvTypeInfo inherited;
	
private:
	double FFactor;
	
protected:
	__property double Factor = {read=FFactor};
	
public:
	__fastcall TConvTypeFactor(const TConvFamily AConvFamily, const AnsiString ADescription, const double AFactor);
	virtual double __fastcall ToCommon(const double AValue);
	virtual double __fastcall FromCommon(const double AValue);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TConvTypeFactor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TConvTypeProcs;
class PASCALIMPLEMENTATION TConvTypeProcs : public TConvTypeInfo 
{
	typedef TConvTypeInfo inherited;
	
private:
	TConversionProc FToCommonProc;
	TConversionProc FFromCommonProc;
	
public:
	__fastcall TConvTypeProcs(const TConvFamily AConvFamily, const AnsiString ADescription, const TConversionProc AToCommonProc, const TConversionProc AFromCommonProc);
	virtual double __fastcall ToCommon(const double AValue);
	virtual double __fastcall FromCommon(const double AValue);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TConvTypeProcs(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TConvFamily CIllegalConvFamily;
extern PACKAGE TConvType CIllegalConvType;
extern PACKAGE AnsiString GConvUnitToStrFmt;
extern PACKAGE void __fastcall RaiseConversionError(const AnsiString AText)/* overload */;
extern PACKAGE void __fastcall RaiseConversionError(const AnsiString AText, const System::TVarRec * AArgs, const int AArgs_Size)/* overload */;
extern PACKAGE void __fastcall RaiseConversionRegError(TConvFamily AFamily, const AnsiString ADescription);
extern PACKAGE TConvFamily __fastcall ConvTypeToFamily(const TConvType AType)/* overload */;
extern PACKAGE bool __fastcall TryConvTypeToFamily(const TConvType AType, /* out */ TConvFamily &AFamily)/* overload */;
extern PACKAGE TConvFamily __fastcall ConvTypeToFamily(const TConvType AFrom, const TConvType ATo)/* overload */;
extern PACKAGE bool __fastcall TryConvTypeToFamily(const TConvType AFrom, const TConvType ATo, /* out */ TConvFamily &AFamily)/* overload */;
extern PACKAGE bool __fastcall CompatibleConversionTypes(const TConvType AFrom, const TConvType ATo);
extern PACKAGE bool __fastcall CompatibleConversionType(const TConvType AType, const TConvFamily AFamily);
extern PACKAGE double __fastcall Convert(const double AValue, const TConvType AFrom, const TConvType ATo)/* overload */;
extern PACKAGE double __fastcall Convert(const double AValue, const TConvType AFrom1, const TConvType AFrom2, const TConvType ATo1, const TConvType ATo2)/* overload */;
extern PACKAGE double __fastcall ConvertFrom(const TConvType AFrom, const double AValue);
extern PACKAGE double __fastcall ConvertTo(const double AValue, const TConvType ATo);
extern PACKAGE double __fastcall ConvUnitAdd(const double AValue1, const TConvType AType1, const double AValue2, const TConvType AType2, const TConvType AResultType);
extern PACKAGE double __fastcall ConvUnitDiff(const double AValue1, const TConvType AType1, const double AValue2, const TConvType AType2, const TConvType AResultType);
extern PACKAGE double __fastcall ConvUnitInc(const double AValue, const TConvType AType, const TConvType AAmountType)/* overload */;
extern PACKAGE double __fastcall ConvUnitInc(const double AValue, const TConvType AType, const double AAmount, const TConvType AAmountType)/* overload */;
extern PACKAGE double __fastcall ConvUnitDec(const double AValue, const TConvType AType, const TConvType AAmountType)/* overload */;
extern PACKAGE double __fastcall ConvUnitDec(const double AValue, const TConvType AType, const double AAmount, const TConvType AAmountType)/* overload */;
extern PACKAGE bool __fastcall ConvUnitWithinPrevious(const double AValue, const double ATest, const TConvType AType, const double AAmount, const TConvType AAmountType);
extern PACKAGE bool __fastcall ConvUnitWithinNext(const double AValue, const double ATest, const TConvType AType, const double AAmount, const TConvType AAmountType);
extern PACKAGE Types::TValueRelationship __fastcall ConvUnitCompareValue(const double AValue1, const TConvType AType1, const double AValue2, const TConvType AType2);
extern PACKAGE bool __fastcall ConvUnitSameValue(const double AValue1, const TConvType AType1, const double AValue2, const TConvType AType2);
extern PACKAGE bool __fastcall RegisterConversionType(TConvTypeInfo* AConvTypeInfo, /* out */ TConvType &AType)/* overload */;
extern PACKAGE TConvType __fastcall RegisterConversionType(const TConvFamily AFamily, const AnsiString ADescription, const double AFactor)/* overload */;
extern PACKAGE TConvType __fastcall RegisterConversionType(const TConvFamily AFamily, const AnsiString ADescription, const TConversionProc AToCommonProc, const TConversionProc AFromCommonProc)/* overload */;
extern PACKAGE void __fastcall UnregisterConversionType(const TConvType AType);
extern PACKAGE TConvFamily __fastcall RegisterConversionFamily(const AnsiString ADescription);
extern PACKAGE void __fastcall UnregisterConversionFamily(const TConvFamily AFamily);
extern PACKAGE double __fastcall StrToConvUnit(AnsiString AText, /* out */ TConvType &AType);
extern PACKAGE bool __fastcall TryStrToConvUnit(AnsiString AText, /* out */ double &AValue, /* out */ TConvType &AType);
extern PACKAGE AnsiString __fastcall ConvUnitToStr(const double AValue, const TConvType AType);
extern PACKAGE void __fastcall GetConvTypes(const TConvFamily AFamily, /* out */ TConvTypeArray &ATypes);
extern PACKAGE void __fastcall GetConvFamilies(/* out */ TConvFamilyArray &AFamilies);
extern PACKAGE AnsiString __fastcall ConvTypeToDescription(const TConvType AType);
extern PACKAGE AnsiString __fastcall ConvFamilyToDescription(const TConvFamily AFamily);
extern PACKAGE bool __fastcall DescriptionToConvType(const AnsiString ADescription, /* out */ TConvType &AType)/* overload */;
extern PACKAGE bool __fastcall DescriptionToConvType(const TConvFamily AFamily, const AnsiString ADescription, /* out */ TConvType &AType)/* overload */;
extern PACKAGE bool __fastcall DescriptionToConvFamily(const AnsiString ADescription, /* out */ TConvFamily &AFamily);

}	/* namespace Convutils */
using namespace Convutils;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ConvUtils
