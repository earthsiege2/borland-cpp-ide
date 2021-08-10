// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'mxstore.pas' rev: 5.00

#ifndef mxstoreHPP
#define mxstoreHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <mxtables.hpp>	// Pascal unit
#include <mxcommon.hpp>	// Pascal unit
#include <mxpbar.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <mxarrays.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DBCommon.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Bde.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxstore
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TErrorAction { eaFail, eaContinue };
#pragma option pop

typedef void __fastcall (__closure *TCapacityErrorEvent)(TErrorAction &EAction);

class DELPHICLASS TCustomDataStore;
typedef void __fastcall (__closure *TCubeNotifyEvent)(TCustomDataStore* DataCube);

class DELPHICLASS TCubeDims;
typedef void __fastcall (__closure *TCubeRefreshEvent)(TCustomDataStore* DataCube, TCubeDims* DimMap
	);

#pragma option push -b-
enum TCubeDataState { dsNoData, dsMetaData, dsDimensionData, dsAllData };
#pragma option pop

#pragma option push -b-
enum TBuildType { btHardRebuild, btSoftRebuild, btNoRebuild };
#pragma option pop

#pragma option push -b-
enum TCubeState { dcInactive, dcBrowseMetaData, dcBrowseMemberData, dcBrowseAllData };
#pragma option pop

typedef Set<Mxcommon::TDimFlags, dimDimension, dimUnknown>  TDimFlagSet;

class DELPHICLASS TCubeDim;
typedef void __fastcall (__closure *TCubeDimTransformEvent)(Variant &Value, TCubeDim* Data);

class PASCALIMPLEMENTATION TCubeDim : public Mxcommon::TDimensionItem 
{
	typedef Mxcommon::TDimensionItem inherited;
	
private:
	Mxcommon::TBinType FBinType;
	TCubeDimTransformEvent FTransform;
	TDate FStartDate;
	AnsiString FBinFormat;
	AnsiString FStartValue;
	bool FDirty;
	Mxcommon::TBinData* FBinData;
	int FValues;
	bool bWasActive;
	void __fastcall SetBin(Mxcommon::TBinType Value);
	Mxcommon::TBinType __fastcall GetBin(void);
	void __fastcall SetDate(TDate Value);
	void __fastcall SetStart(AnsiString Value);
	void __fastcall ReadDateBin(Classes::TReader* Reader);
	void __fastcall ReadStartDate(Classes::TReader* Reader);
	void __fastcall ReadStartValue(Classes::TReader* Reader);
	void __fastcall WriteStartValue(Classes::TWriter* Writer);
	void __fastcall ReadActive(Classes::TReader* Reader);
	void __fastcall WriteActive(Classes::TWriter* Writer);
	
protected:
	void __fastcall YearTransform(Variant &Value, TCubeDim* CubeDim);
	void __fastcall QuarterTransform(Variant &Value, TCubeDim* CubeDim);
	void __fastcall MonthTransform(Variant &Value, TCubeDim* CubeDim);
	void __fastcall DataSetTransform(Variant &Value, TCubeDim* CubeDim);
	TCubeDimTransformEvent __fastcall AssignBinTypeTransform(Mxcommon::TBinType Bins);
	AnsiString __fastcall AssignBinTypeFormat(Mxcommon::TBinType Bins);
	virtual void __fastcall NotifyCollection(Mxcommon::TCDNotifyType aType);
	virtual void __fastcall InitializeRange(void);
	virtual void __fastcall DoTransform(Variant &Value);
	__property bool Dirty = {read=FDirty, write=FDirty, nodefault};
	bool __fastcall GetLoaded(void);
	void __fastcall SetLoaded(bool Value);
	__property bool wasActive = {read=bWasActive, write=bWasActive, nodefault};
	
public:
	__fastcall virtual TCubeDim(Classes::TCollection* Collection);
	__fastcall virtual ~TCubeDim(void);
	virtual void __fastcall Assign(Classes::TPersistent* Value);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	Variant __fastcall GetBinValues(const Variant &Value);
	bool __fastcall IsBinData(void);
	__property AnsiString BinFormat = {read=FBinFormat, write=FBinFormat};
	__property TDate StartDate = {read=FStartDate, write=SetDate};
	__property bool Loaded = {read=GetLoaded, write=SetLoaded, nodefault};
	__property AnsiString StartValue = {read=FStartValue, write=SetStart};
	__property Mxcommon::TBinData* BinData = {read=FBinData};
	__property TCubeDimTransformEvent OnTransform = {read=FTransform, write=FTransform};
	
__published:
	__property Mxcommon::TBinType BinType = {read=GetBin, write=SetBin, nodefault};
	__property int ValueCount = {read=FValues, write=FValues, nodefault};
};


typedef TMetaClass*TCubeDimClass;

class PASCALIMPLEMENTATION TCubeDims : public Mxcommon::TDimensionItems 
{
	typedef Mxcommon::TDimensionItems inherited;
	
private:
	TCubeDim* __fastcall GetCubeDim(int Index);
	void __fastcall SetCubeDim(int Index, TCubeDim* Value);
	
protected:
	HIDESBASE TCubeDim* __fastcall Add(void);
	bool __fastcall GetDirtyFlag(void);
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TCubeDims(Classes::TPersistent* FOwner, TMetaClass* ItemClass);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property bool IsDirty = {read=GetDirtyFlag, nodefault};
	__property TCubeDim* Items[int Index] = {read=GetCubeDim, write=SetCubeDim/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TCubeDims(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataCache;
class DELPHICLASS TIndexInfo;
struct TIndexInfoRec;
typedef TIndexInfoRec *PIndexInfoRec;

class PASCALIMPLEMENTATION TIndexInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FSparseCnt;
	int FSubTotalCnt;
	int FCount;
	bool FExtInfo;
	Mxarrays::TIntArray* FOffset;
	bool FAddAggs;
	_RTL_CRITICAL_SECTION FLock;
	
public:
	__fastcall TIndexInfo(void);
	__fastcall virtual ~TIndexInfo(void);
	void __fastcall SetCapacity(int Value);
	int __fastcall GetCapacity(void);
	int __fastcall Add(PIndexInfoRec pIdxRec);
	bool __fastcall IsSparse(int Index);
	bool __fastcall IsSparseAgg(int Index);
	void __fastcall AddOffset(int Index, int IdxType);
	Mxarrays::TIntArray* __fastcall LockIndex(void);
	void __fastcall UnlockIndex(void);
	__property int Count = {read=FCount, nodefault};
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property bool AddAggs = {read=FAddAggs, write=FAddAggs, nodefault};
};


class DELPHICLASS TSummary;
typedef bool __fastcall (*TAggProc)(int eCnt, int Range, TSummary* Summary, Mxarrays::TSmallIntArray* 
	SumIndex, Variant &vNew);

#pragma option push -b-
enum TCalcTotalsFlags { ctPreCalc, ctRunning, ctNone };
#pragma option pop

typedef Set<TCalcTotalsFlags, ctPreCalc, ctNone>  TCalcTotals;

#pragma option push -b-
enum TLookupStateFlags { lsSparsing, lsCursor, lsShowProgress };
#pragma option pop

typedef Set<TLookupStateFlags, lsSparsing, lsShowProgress>  TLookupState;

#pragma option push -b-
enum TCacheStateFlags { csHasIndex, csDirty, csSuccess, csShowProgress, csRefreshing };
#pragma option pop

typedef Set<TCacheStateFlags, csHasIndex, csRefreshing>  TCacheState;

class DELPHICLASS TDimension;
class PASCALIMPLEMENTATION TDataCache : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FSummaryData;
	Classes::TList* FDimensions;
	int FActiveSummary;
	Mxarrays::TIndexArray* FIndexMap;
	TIndexInfo* FIndexInfo;
	TAggProc FAggProc;
	int FErrorCode;
	TCalcTotals FCalcTotals;
	TLookupState FLookupState;
	bool FActive;
	TCacheState FState;
	void __fastcall Init(void);
	bool __fastcall IsBlankSummary(void);
	int __fastcall GetDimensionCount(void);
	TDimension* __fastcall GetDimension(int Index);
	void __fastcall SetDimension(int Index, TDimension* Value);
	int __fastcall GetSummaryCount(void);
	TSummary* __fastcall GetSummary(int Index);
	void __fastcall SetActiveSummary(int Index);
	void __fastcall GetScope(int &OffsetIdx, int &AggIdx, int &AggRange, Mxarrays::TSmallIntArray* SumIndex
		);
	bool __fastcall IsIndexSparse(Mxarrays::TSmallIntArray* SumIndex);
	bool __fastcall GetSuccess(void);
	void __fastcall SetSuccess(bool Value);
	bool __fastcall GetPreCalcTotals(void);
	void __fastcall SetPreCalcTotals(bool Value);
	bool __fastcall GetSparsing(void);
	void __fastcall SetSparsing(bool Value);
	bool __fastcall GetHasIndex(void);
	void __fastcall SetHasIndex(bool Value);
	bool __fastcall GetAggSummary(Mxarrays::TSmallIntArray* SumIndex, TSummary* Summary, Variant &Value
		);
	bool __fastcall GetBaseSummary(Mxarrays::TSmallIntArray* SumIndex, TSummary* Summary, Variant &Value
		);
	
protected:
	void __fastcall FreeCache(void);
	
public:
	__fastcall TDataCache(void);
	__fastcall virtual ~TDataCache(void);
	int __fastcall GetMemoryUsage(void);
	void __fastcall CalcSubTotals(void);
	void __fastcall ClearIndexInfo(void);
	int __fastcall AddAggIndex(Mxarrays::TSmallIntArray* SumIndex, Classes::TList* BuilderDims);
	int __fastcall AddIndex(Mxarrays::TSmallIntArray* SumIndex, bool bSparse);
	bool __fastcall IsDimension(int Position);
	bool __fastcall IsSummary(int Position);
	TSummary* __fastcall SummaryFromPosition(int Position);
	TSummary* __fastcall SummaryFromFieldName(AnsiString FldName);
	TSummary* __fastcall SummaryFromCubeDimIndex(int Index);
	TDimension* __fastcall DimensionFromFieldName(AnsiString FldName);
	int __fastcall AppendDimension(TDimension* Value);
	int __fastcall AppendSummary(TSummary* Value);
	AnsiString __fastcall GetDimensionName(int DimIndex);
	AnsiString __fastcall GetSummaryName(int ISum);
	AnsiString __fastcall GetDimensionMember(int DimIndex, int MemberIndex);
	Variant __fastcall GetDimensionMemberAsVariant(int DimIndex, int MemberIndex);
	int __fastcall GetDimensionMemberCount(int DimIndex);
	int __fastcall GetIndexCount(void);
	bool __fastcall IncSummaryIndex(TSummary* Summary, Mxarrays::TSmallIntArray* SumIndex, Mxarrays::TSmallIntArray* 
		rangeCount, bool &bGroupBreak);
	bool __fastcall HasSubTotals(Mxarrays::TSmallIntArray* SumIndex);
	bool __fastcall HasValidSubTotals(TSummary* Summary, Mxarrays::TSmallIntArray* SumIndex);
	AnsiString __fastcall GetSummaryAsString(Mxarrays::TSmallIntArray* SumIndex);
	Variant __fastcall GetSummaryAsVariant(Mxarrays::TSmallIntArray* SumIndex);
	void __fastcall CreateTable(const AnsiString Filename);
	int __fastcall GetDomain(Mxarrays::TIntArray* DimensionIDs, int nDims, bool ATotals, Mxarrays::TTwoDimArray* 
		Domain);
	__property bool PreCalculateTotals = {read=GetPreCalcTotals, write=SetPreCalcTotals, nodefault};
	__property int CurrentSummary = {read=FActiveSummary, write=SetActiveSummary, nodefault};
	__property int DimensionCount = {read=GetDimensionCount, nodefault};
	__property int SummaryCount = {read=GetSummaryCount, nodefault};
	__property TSummary* Summaries[int Index] = {read=GetSummary};
	__property TDimension* Dimensions[int Index] = {read=GetDimension, write=SetDimension};
	__property bool Active = {read=FActive, write=FActive, nodefault};
	__property bool Sparsing = {read=GetSparsing, write=SetSparsing, nodefault};
	__property int IndexCount = {read=GetIndexCount, nodefault};
	__property bool Success = {read=GetSuccess, write=SetSuccess, nodefault};
	__property int ErrorCode = {read=FErrorCode, write=FErrorCode, nodefault};
	__property bool HasIndex = {read=GetHasIndex, write=SetHasIndex, nodefault};
};


class DELPHICLASS TMultiDimDataLink;
class PASCALIMPLEMENTATION TMultiDimDataLink : public Db::TDataLink 
{
	typedef Db::TDataLink inherited;
	
private:
	TCustomDataStore* FDataStore;
	Db::TDataSource* FDataSource;
	int __fastcall EstimateCapacity(int RangeCnt);
	void __fastcall DoUpdateCache(void);
	
protected:
	int __fastcall AddDimension(TCubeDim* DimMap, Db::TField* Fld);
	void __fastcall AddSummary(TCubeDim* DimMap, Db::TField* Fld);
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall LayoutChanged(void);
	void __fastcall UpdateCache(System::TObject* Sender);
	void __fastcall UpdateDimensions(Classes::TList* DimAllList);
	void __fastcall FetchValues(Classes::TList* DimAllList);
	void __fastcall FetchAndBinValues(Classes::TList* DimAllList);
	void __fastcall CreateSummaryIndex(Classes::TList* DimAllList);
	void __fastcall UpdateFormatStrings(void);
	
public:
	__fastcall TMultiDimDataLink(TCustomDataStore* AStore);
	__fastcall virtual ~TMultiDimDataLink(void);
};


class PASCALIMPLEMENTATION TCustomDataStore : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TDataCache* FCache;
	TMultiDimDataLink* FDataLink;
	TCubeState FState;
	TCubeDataState FDesignState;
	TCubeDims* FDimensionMap;
	Db::TDataSet* FDataSet;
	bool FShowProgress;
	bool FBinData;
	bool FDirty;
	int FMaxDims;
	int FMaxSums;
	int FMaxCells;
	Db::TDataSource* FInternalDataSource;
	TCapacityErrorEvent FOnCapacityError;
	TCubeNotifyEvent FBeforeOpen;
	TCubeNotifyEvent FAfterOpen;
	TCubeNotifyEvent FBeforeClose;
	TCubeNotifyEvent FAfterClose;
	TCubeRefreshEvent FOnRefresh;
	Db::TDataSource* __fastcall GetDataSource(void);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetActive(bool Value);
	int __fastcall GetDimensionCount(void);
	int __fastcall GetSummaryCount(void);
	int __fastcall GetDimensionMapCount(void);
	bool __fastcall GetActive(void);
	void __fastcall SetState(TCubeState Value);
	void __fastcall SetDesignState(TCubeDataState Value);
	bool __fastcall GetCubeState(void);
	void __fastcall OpenCache(void);
	void __fastcall CloseCache(void);
	void __fastcall SetCapacity(int Value);
	int __fastcall GetCapacity(void);
	void __fastcall SetMaxDims(int Value);
	void __fastcall SetMaxSums(int Value);
	void __fastcall SetBinData(bool Value);
	bool __fastcall CheckDimensionMap(TCubeDims* DimMap, TBuildType &BuildType);
	void __fastcall SetLoadMap(TCubeDims* DimMap, TCubeDims* OldMap);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall StateChanged(void);
	virtual void __fastcall DoBeforeOpen(void);
	virtual void __fastcall DoAfterOpen(void);
	virtual void __fastcall DoBeforeClose(void);
	virtual void __fastcall DoAfterClose(void);
	virtual void __fastcall DoOnRefresh(TCubeDims* DimMap);
	Db::TDataSet* __fastcall GetDataSet(void);
	int __fastcall GetDomain(Mxarrays::TIntArray* DimensionIDs, bool ATotals, Mxarrays::TTwoDimArray* Domain
		);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall SetDataSet(Db::TDataSet* ADataSet);
	int __fastcall GetCurrentSummary(void);
	void __fastcall SetCurrentSummary(int Value);
	virtual void __fastcall LayoutChanged(void);
	bool __fastcall BinMapHasBinData(void);
	virtual bool __fastcall CanDimBeClosed(int iMapIndex);
	virtual bool __fastcall CanSumBeClosed(int iMapIndex);
	__property TDataCache* DataCache = {read=FCache};
	__property TMultiDimDataLink* DataLink = {read=FDataLink};
	__property Db::TDataSource* InternalDataSource = {read=FInternalDataSource};
	__property TCubeDataState DesignState = {read=FDesignState, write=SetDesignState, nodefault};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property TCubeState State = {read=FState, nodefault};
	
public:
	__fastcall virtual TCustomDataStore(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDataStore(void);
	void __fastcall CalcSubTotals(void);
	void __fastcall Refresh(TCubeDims* DimMap, bool bForce);
	int __fastcall GetMemoryUsage(void);
	virtual AnsiString __fastcall GetDimensionName(int Dimension);
	virtual int __fastcall GetDimensionMemberCount(int Dimension);
	virtual AnsiString __fastcall GetMemberAsString(int Dimension, int Index);
	Variant __fastcall GetMemberAsVariant(int Dimension, int Index);
	virtual AnsiString __fastcall GetSummaryName(int ISum);
	virtual AnsiString __fastcall GetSummaryAsString(Mxarrays::TSmallIntArray* Coord);
	virtual Variant __fastcall GetSummaryAsVariant(Mxarrays::TSmallIntArray* Coord);
	__property int DimensionMapCount = {read=GetDimensionMapCount, nodefault};
	__property int DimensionCount = {read=GetDimensionCount, nodefault};
	__property int SummaryCount = {read=GetSummaryCount, nodefault};
	__property int CurrentSummary = {read=GetCurrentSummary, write=SetCurrentSummary, nodefault};
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property bool BinData = {read=FBinData, write=SetBinData, nodefault};
	__property Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
	__property TCubeDims* DimensionMap = {read=FDimensionMap, write=FDimensionMap};
	__property bool ShowProgressDialog = {read=FShowProgress, write=FShowProgress, nodefault};
	__property int MaxDimensions = {read=FMaxDims, write=SetMaxDims, nodefault};
	__property int MaxSummaries = {read=FMaxSums, write=SetMaxSums, nodefault};
	__property int MaxCells = {read=FMaxCells, write=FMaxCells, nodefault};
	__property TCapacityErrorEvent OnLowCapacity = {read=FOnCapacityError, write=FOnCapacityError};
	__property TCubeNotifyEvent BeforeOpen = {read=FBeforeOpen, write=FBeforeOpen};
	__property TCubeNotifyEvent AfterOpen = {read=FAfterOpen, write=FAfterOpen};
	__property TCubeNotifyEvent BeforeClose = {read=FBeforeClose, write=FBeforeClose};
	__property TCubeNotifyEvent AfterClose = {read=FAfterClose, write=FAfterClose};
	__property TCubeRefreshEvent OnRefresh = {read=FOnRefresh, write=FOnRefresh};
};


#pragma option push -b-
enum TFormatType { fxNone, fxFloat, fxCurrency, fxDateTime, fxTime, fxDate, fxString, fxInteger, fxBoolean 
	};
#pragma option pop

class DELPHICLASS TFieldDefinition;
class PASCALIMPLEMENTATION TFieldDefinition : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FFormatString;
	Db::TFieldType FFieldType;
	int FWidth;
	AnsiString FName;
	TFormatType FFormatType;
	int FPrecision;
	int FFieldNo;
	
public:
	__fastcall TFieldDefinition(void);
	AnsiString __fastcall FormatVariantToStr(const Variant &Value);
	void __fastcall SetFieldType(Db::TFieldType FType);
	void __fastcall SetName(AnsiString Value);
	__property int Width = {read=FWidth, write=FWidth, nodefault};
	__property AnsiString FormatString = {read=FFormatString, write=FFormatString};
	__property Db::TFieldType FieldType = {read=FFieldType, write=SetFieldType, nodefault};
	__property int Precision = {read=FPrecision, write=FPrecision, nodefault};
	__property AnsiString DisplayName = {read=FName, write=SetName};
	__property int FieldNo = {read=FFieldNo, write=FFieldNo, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TFieldDefinition(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDimension : public Mxarrays::TCustomArray 
{
	typedef Mxarrays::TCustomArray inherited;
	
private:
	int FPosition;
	int FRange;
	TDimFlagSet FFlags;
	TFieldDefinition* FFieldDef;
	AnsiString FFieldName;
	void __fastcall SetFieldType(Db::TFieldType Value);
	Db::TFieldType __fastcall GetFieldType(void);
	void __fastcall SetPosition(int Value);
	void __fastcall SetName(AnsiString Value);
	AnsiString __fastcall GetName();
	void __fastcall SetRange(int Value);
	
public:
	__fastcall TDimension(unsigned Items, Db::TFieldType DataType);
	__fastcall virtual ~TDimension(void);
	bool __fastcall IsString(void);
	void __fastcall SetFlag(Mxcommon::TDimFlags aFlag);
	bool __fastcall HasFlag(Mxcommon::TDimFlags aFlag);
	void __fastcall ClearFlag(Mxcommon::TDimFlags aFlag);
	void __fastcall SetRangeCounting(bool bRange);
	void __fastcall AssignSorted(TDimension* Dim, bool bUnique);
	__property int Range = {read=FRange, write=SetRange, nodefault};
	__property Mxcommon::TDimFlags Attributes = {write=SetFlag, nodefault};
	__property AnsiString DimensionName = {read=GetName, write=SetName};
	__property Db::TFieldType FieldType = {read=GetFieldType, write=SetFieldType, nodefault};
	__property int Position = {read=FPosition, write=SetPosition, nodefault};
	__property TFieldDefinition* FieldDefinition = {read=FFieldDef};
	__property AnsiString FieldName = {read=FFieldName, write=FFieldName};
};


#pragma option push -b-
enum TIndexFlag { idxNormal, idxSparsed, idxFiltered, idxSubTotals, idxDeleted };
#pragma option pop

typedef Set<TIndexFlag, idxNormal, idxDeleted>  TIndexFlags;

struct TIndexInfoRec
{
	int SparseCnt;
	int SubTotalCnt;
	int AggOffset;
	TIndexFlags Flags;
} ;

typedef Variant __fastcall (*TDerivedAggProc)(const Variant &Val1, const Variant &Val2);

typedef Byte TFieldArgs[256];

class DELPHICLASS TAggDefinition;
class PASCALIMPLEMENTATION TAggDefinition : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Byte FSummaryIdx[256];
	TDerivedAggProc FAggProc;
	
public:
	__property TDerivedAggProc AggProc = {read=FAggProc, write=FAggProc};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAggDefinition(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAggDefinition(void) { }
	#pragma option pop
	
};


typedef bool __fastcall (__closure *TSumMethod)(Mxarrays::TSmallIntArray* SumIndex, TSummary* Summary
	, Variant &Value);

class PASCALIMPLEMENTATION TSummary : public Mxarrays::TCustomArray 
{
	typedef Mxarrays::TCustomArray inherited;
	
private:
	int FPosition;
	int FCubeDimIndex;
	TDimFlagSet FFlags;
	TIndexInfo* FIndexInfo;
	Mxarrays::TThreadCustomArray* FTotals;
	Mxarrays::TIndexArray* FIndexMap;
	TFieldDefinition* FFieldDef;
	AnsiString FFieldName;
	TAggDefinition* FAggDef;
	TSumMethod FSumMethod;
	void __fastcall SetFieldType(Db::TFieldType Value);
	Db::TFieldType __fastcall GetFieldType(void);
	void __fastcall SetPosition(int Value);
	void __fastcall SetFlag(Mxcommon::TDimFlags aFlag);
	void __fastcall SetName(AnsiString Value);
	AnsiString __fastcall GetName();
	bool __fastcall GetDerived(void);
	
protected:
	bool __fastcall HasFlag(Mxcommon::TDimFlags aFlag);
	bool __fastcall SetAggregator(AnsiString aName, TCubeDims* DimMap, Mxcommon::TDimFlags dimType, int 
		&dIdx);
	
public:
	__fastcall TSummary(unsigned Items, Db::TFieldType DataType);
	__fastcall virtual ~TSummary(void);
	void __fastcall ClearTotals(void);
	virtual int __fastcall MemoryUsage(void);
	bool __fastcall IsSparse(int Index);
	void __fastcall UpdateIndexInfo(int Index, const Variant &Value);
	int __fastcall AddIndexInfo(bool BTotal, bool bSparse, int iAggOffset);
	int __fastcall AddSubTotal(const Variant &Value);
	void __fastcall AddSum(Mxarrays::TSmallIntArray* &SumIndex, const Variant &vNew);
	__property AnsiString Name = {read=GetName, write=SetName};
	__property Mxcommon::TDimFlags Attributes = {write=SetFlag, nodefault};
	__property Db::TFieldType FieldType = {read=GetFieldType, write=SetFieldType, nodefault};
	__property int Position = {read=FPosition, write=SetPosition, nodefault};
	__property TFieldDefinition* FieldDefinition = {read=FFieldDef};
	__property AnsiString FieldName = {read=FFieldName, write=FFieldName};
	__property TSumMethod SumMethod = {read=FSumMethod, write=FSumMethod};
	__property int CubeDimIndex = {read=FCubeDimIndex, write=FCubeDimIndex, nodefault};
	__property TAggDefinition* AggDefinition = {read=FAggDef, write=FAggDef};
	__property bool IsDerived = {read=GetDerived, nodefault};
};


class DELPHICLASS ECacheError;
class PASCALIMPLEMENTATION ECacheError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ECacheError(const AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ECacheError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ECacheError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ECacheError(int Ident, const System::TVarRec * Args, 
		const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ECacheError(const AnsiString Msg, int AHelpContext) : 
		Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ECacheError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ECacheError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ECacheError(System::PResStringRec ResStringRec, 
		const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ECacheError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBuilderDim;
class PASCALIMPLEMENTATION TBuilderDim : public TDimension 
{
	typedef TDimension inherited;
	
private:
	bool FGroupBreak;
	int FActiveIndex;
	Mxarrays::TCustomArray* FSummary;
	Variant FLastVal;
	Mxarrays::TStringArray* FValueList;
	int FSummaryDataType;
	
protected:
	Variant __fastcall GetLastVal();
	void __fastcall SetLastVal(const Variant &Value);
	
public:
	__fastcall TBuilderDim(unsigned Items, Db::TFieldType DataType);
	__fastcall virtual ~TBuilderDim(void);
	int __fastcall GetSumCount(void);
	Variant __fastcall GetSummary(const Variant &Value);
	void __fastcall InitSummary(int DataType);
	HIDESBASE void __fastcall Add(const Variant &Value);
	void __fastcall AddSummary(const Variant &Value);
	bool __fastcall MatchLastVal(const Variant &Value);
	__property bool GroupBreak = {read=FGroupBreak, write=FGroupBreak, nodefault};
	__property Variant LastVal = {read=GetLastVal, write=SetLastVal};
	__property int SumCount = {read=GetSumCount, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint SubTotal = 0xffffffff;
static const Shortint NonSparseAgg = 0xfffffffc;
static const Shortint SparseUnknown = 0xfffffffd;
static const Shortint SparseAgg = 0xfffffffe;
static const Shortint SparseSum = 0xffffffff;
static const Shortint MaxBinDimensions = 0x10;
static const Shortint LargeValueCount = 0x32;
extern PACKAGE bool __fastcall TestMatch(Mxarrays::TSmallIntArray* SumIdx);

}	/* namespace Mxstore */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mxstore;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// mxstore
