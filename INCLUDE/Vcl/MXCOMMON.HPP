// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'mxcommon.pas' rev: 5.00

#ifndef mxcommonHPP
#define mxcommonHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <mxConsts.hpp>	// Pascal unit
#include <mxarrays.hpp>	// Pascal unit
#include <Bde.hpp>	// Pascal unit
#include <DBCommon.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <IniFiles.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxcommon
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EDimensionMapError;
class PASCALIMPLEMENTATION EDimensionMapError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDimensionMapError(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDimensionMapError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDimensionMapError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDimensionMapError(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDimensionMapError(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDimensionMapError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDimensionMapError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDimensionMapError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDimensionMapError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TQueryError { tqeOK, tqeNoDimensions, tqeNoAggs, tqeNotGrouped, tqeNotInitialized, tqeMapCorrupt, 
	tqeUnKnownDims };
#pragma option pop

#pragma option push -b-
enum TBinType { binNone, binYear, binQuarter, binMonth, binSet, binCustom };
#pragma option pop

typedef Set<TBinType, binNone, binCustom>  TBinTypes;

#pragma option push -b-
enum TActiveFlags { diActive, diAsNeeded, diInactive };
#pragma option pop

#pragma option push -b-
enum TDimFlags { dimDimension, dimSum, dimCount, dimAverage, dimMin, dimMax, dimGenericAgg, dimUnknown 
	};
#pragma option pop

#pragma option push -b-
enum TCDNotifyType { tdChanged };
#pragma option pop

class DELPHICLASS TDimensionItem;
class PASCALIMPLEMENTATION TDimensionItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	int FDerivedFrom;
	AnsiString FFormat;
	AnsiString FName;
	AnsiString FFieldName;
	AnsiString FBaseName;
	Db::TFieldType FFieldType;
	bool FActive;
	TActiveFlags FActiveFlag;
	Classes::TCollection* FOwner;
	TDimFlags FType;
	void __fastcall SetName(AnsiString Value);
	void __fastcall SetBaseName(AnsiString Value);
	void __fastcall SetFieldName(AnsiString Value);
	void __fastcall SetDerivedFrom(int Value);
	void __fastcall SetFormat(AnsiString Value);
	void __fastcall SetFieldType(Db::TFieldType Value);
	void __fastcall SetType(TDimFlags Value);
	void __fastcall SetActive(bool Value);
	void __fastcall SetActiveFlag(TActiveFlags Value);
	
protected:
	virtual void __fastcall InitializeRange(void);
	virtual void __fastcall NotifyCollection(TCDNotifyType aType);
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property Classes::TCollection* Owner = {read=FOwner};
	
public:
	__fastcall virtual TDimensionItem(Classes::TCollection* Collection);
	virtual void __fastcall Assign(Classes::TPersistent* Value);
	bool __fastcall IsDimension(void);
	bool __fastcall IsSummary(void);
	
__published:
	__property TActiveFlags ActiveFlag = {read=FActiveFlag, write=SetActiveFlag, nodefault};
	__property AnsiString Format = {read=FFormat, write=SetFormat};
	__property Db::TFieldType FieldType = {read=FFieldType, write=SetFieldType, nodefault};
	__property AnsiString Fieldname = {read=FFieldName, write=SetFieldName};
	__property AnsiString BaseName = {read=FBaseName, write=SetBaseName};
	__property AnsiString Name = {read=FName, write=SetName};
	__property int DerivedFrom = {read=FDerivedFrom, write=SetDerivedFrom, nodefault};
	__property TDimFlags DimensionType = {read=FType, write=SetType, nodefault};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TDimensionItem(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TDimensionItemClass;

class DELPHICLASS TDimensionItems;
class PASCALIMPLEMENTATION TDimensionItems : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
private:
	Classes::TPersistent* FOwner;
	bool bQuiet;
	TDimensionItem* __fastcall GetDimensionItem(int Index);
	void __fastcall SetDimensionItem(int Index, TDimensionItem* Value);
	int __fastcall GetDimCount(void);
	int __fastcall GetSumCount(void);
	int __fastcall GetActiveDimCount(void);
	int __fastcall GetActiveSumCount(void);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall NotifyOwner(TCDNotifyType aType);
	
public:
	__fastcall TDimensionItems(Classes::TPersistent* Owner, TMetaClass* ItemClass);
	HIDESBASE TDimensionItem* __fastcall Add(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall AddDerivedField(int Index, TDimFlags dimType);
	bool __fastcall AverageFieldCheck(int Index, int &SumIndex, int &CountIndex);
	bool __fastcall AlreadyExists(AnsiString BaseName, TDimFlags sType);
	__property TDimensionItem* Items[int Index] = {read=GetDimensionItem, write=SetDimensionItem/*, default
		*/};
	__property int DimensionCount = {read=GetDimCount, nodefault};
	__property int SummaryCount = {read=GetSumCount, nodefault};
	__property int ActiveDimensionCount = {read=GetActiveDimCount, nodefault};
	__property int ActiveSummaryCount = {read=GetActiveSumCount, nodefault};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TDimensionItems(void) { }
	#pragma option pop
	
};


struct TTickInfoRec;
typedef TTickInfoRec *PTickInfoRec;

struct TTickInfoRec
{
	int StartTicks;
	int EndTicks;
	int TotalTicks;
	AnsiString SName;
} ;

class DELPHICLASS TTicks;
class PASCALIMPLEMENTATION TTicks : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FTicksList;
	Inifiles::TIniFile* FLogFile;
	int FNumValues;
	
public:
	__fastcall TTicks(AnsiString FileName);
	__fastcall virtual ~TTicks(void);
	void __fastcall Dump(bool bDetail);
	void __fastcall Clear(void);
	void __fastcall Ticks(AnsiString SectionName);
	void __fastcall TicksIntArray(AnsiString SectionName, Mxarrays::TIntArray* IntArray);
	void __fastcall TicksSmallIntArray(AnsiString SectionName, Mxarrays::TSmallIntArray* IntArray);
	__property int NumberOfValues = {read=FNumValues, write=FNumValues, nodefault};
};


class DELPHICLASS TBinData;
class PASCALIMPLEMENTATION TBinData : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TStringList* FNameList;
	Classes::TList* FValueList;
	AnsiString FOtherStr;
	bool __fastcall FindName(AnsiString BinName, int &pos);
	
public:
	__fastcall TBinData(void);
	__fastcall virtual ~TBinData(void);
	void __fastcall Clear(void);
	virtual void __fastcall Assign(Classes::TPersistent* Value);
	void __fastcall AddBinValues(AnsiString BinName, const System::TVarRec * Values, const int Values_Size
		);
	int __fastcall AddBinValue(AnsiString BinName, const Variant &Value);
	int __fastcall BinValueCount(AnsiString BinName);
	int __fastcall GetAllBinValueCount(void);
	Variant __fastcall GetBinValue(AnsiString BinName, int Index);
	Variant __fastcall GetBinValues(AnsiString BinName);
	AnsiString __fastcall GetBinName(int Index);
	int __fastcall GetBinCount(void);
	Db::TFieldType __fastcall GetBinNameDataType(void);
	int __fastcall GetMaxBinNameSize(void);
	int __fastcall AddBin(AnsiString BinName, int vType);
	int __fastcall AddIBinValue(int iBin, const Variant &value);
	Variant __fastcall GetIBinValue(int iBin, int ValueIndex);
	int __fastcall GetIBinValueCount(int iBin);
	__property AnsiString OtherBinName = {read=FOtherStr, write=FOtherStr};
	__property AnsiString BinName[int Index] = {read=GetBinName};
	__property int BinCount = {read=GetBinCount, nodefault};
	__property Classes::TStringList* NameList = {read=FNameList};
	__property Classes::TList* ValueList = {read=FValueList};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IsBDEAvailable(void);
extern PACKAGE AnsiString __fastcall GetAggName(TDimFlags aType, AnsiString FieldName);
extern PACKAGE int __fastcall FieldTypeToVarType(Db::TFieldType DataType);
extern PACKAGE TQueryError __fastcall VerifyRTQuery(Db::TDataSet* aDataSet, TDimensionItems* Map, bool 
	&bDataSetMatch);
extern PACKAGE TQueryError __fastcall BuildDataSetMap(Db::TDataSet* aDataSet, TDimensionItems* Map, 
	bool &bParsed, bool &bDataSetMatch);
extern PACKAGE bool __fastcall IsAggValid(TDimFlags AggType, Db::TFieldType FieldType);
extern PACKAGE void __fastcall AddToQuerySelect(AnsiString &SQLString, AnsiString Select);
extern PACKAGE bool __fastcall CheckIfEmptyQuery(AnsiString &SQLString);
extern PACKAGE void __fastcall UpdateDesigner(Classes::TComponent* Sender);
extern PACKAGE AnsiString __fastcall FormatVariant(const Variant &Value, AnsiString FFormat);
extern PACKAGE AnsiString __fastcall NextArg(int &aPos, AnsiString Source);
extern PACKAGE Dbtables::TDatabase* __fastcall HookToDataBase(Db::TDataSet* aDataSet);

}	/* namespace Mxcommon */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mxcommon;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// mxcommon
