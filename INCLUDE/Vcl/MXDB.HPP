// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXDB.pas' rev: 6.00

#ifndef MXDBHPP
#define MXDBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <MXQEDCOM.hpp>	// Pascal unit
#include <MXQPARSE.hpp>	// Pascal unit
#include <MXTABLES.hpp>	// Pascal unit
#include <MXCOMMON.hpp>	// Pascal unit
#include <Mxconsts.hpp>	// Pascal unit
#include <Mxstore.hpp>	// Pascal unit
#include <Mxarrays.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <BDE.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxdb
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EArrayError;
class PASCALIMPLEMENTATION EArrayError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EArrayError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EArrayError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EArrayError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EArrayError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EArrayError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EArrayError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EArrayError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EArrayError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EArrayError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EDimIndexError;
class PASCALIMPLEMENTATION EDimIndexError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDimIndexError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDimIndexError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDimIndexError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDimIndexError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDimIndexError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDimIndexError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDimIndexError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDimIndexError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDimIndexError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDimGroup { dgRow, dgCol, dgSum, dgPage, dgNone };
#pragma option pop

#pragma option push -b-
enum TRowStates { rcNextOpen, rcPrevOpen, rcNextClosed, rcPrevClosed };
#pragma option pop

typedef Set<TRowStates, rcNextOpen, rcPrevClosed>  TRowState;

#pragma option push -b-
enum TDimState { dmClosed, dmOpen, dmDrilled, dmPaged, dmNone };
#pragma option pop

#pragma option push -b-
enum TDecisionControlType { xtCheck, xtRadio, xtRadioEx };
#pragma option pop

class DELPHICLASS TIArray;
class PASCALIMPLEMENTATION TIArray : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int operator[](int Index) { return Items[Index]; }
	
private:
	int FLimit;
	bool FAutoIncr;
	void *FElements;
	int FBlockSize;
	int FCapacity;
	void __fastcall Alloc(int ALimit);
	void __fastcall Realloc(int ALimit);
	
protected:
	int __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, int Value);
	
public:
	__fastcall TIArray(int ALimit, int ABlockSize);
	__fastcall virtual ~TIArray(void);
	void __fastcall Assign(TIArray* Value);
	void __fastcall InsertAt(int Index, int Value);
	int __fastcall RemoveItem(int Index);
	__property bool AutoSize = {read=FAutoIncr, write=FAutoIncr, nodefault};
	__property int Limit = {read=FLimit, nodefault};
	__property int Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
};


typedef int TArrayInt[268435456];

typedef int *PArrayInt;

#pragma pack(push, 4)
struct TDimInfo
{
	TDimState iState;
	int iValue;
	int iIndex;
	int iActiveIndex;
	TRowState iRowState;
	TDimGroup iGroup;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TDimRange
{
	int First;
	int Last;
} ;
#pragma pack(pop)

typedef char TBigStr[100001];

typedef TDimInfo *PDimInfo;

typedef TDimInfo TArrayDimInfo[1000];

typedef TDimInfo *PArrayDimInfo;

class DELPHICLASS TDimInfoArray;
class PASCALIMPLEMENTATION TDimInfoArray : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	PDimInfo operator[](int Index) { return Items[Index]; }
	
private:
	int FLimit;
	void *FElements;
	TIArray* AllXDim;
	Classes::TStringList* FDimNames;
	
protected:
	PDimInfo __fastcall GetItem(int Index);
	bool __fastcall Find(AnsiString Name, int &pos);
	
public:
	__fastcall TDimInfoArray(int ALimit);
	__fastcall virtual ~TDimInfoArray(void);
	void __fastcall Assign(TDimInfoArray* Value);
	PDimInfo __fastcall GetGroupItem(TDimGroup Group, int Index, bool bOpen);
	int __fastcall GetGroupIndex(TDimGroup Group, int Index, bool bOpen);
	int __fastcall GetGroupSize(TDimGroup Group, bool bOpen);
	TIArray* __fastcall GetGroupArray(TDimGroup Group, bool bOpen);
	bool __fastcall IsEqual(TDimInfoArray* Value);
	__property int Limit = {read=FLimit, nodefault};
	__property PDimInfo Items[int Index] = {read=GetItem/*, default*/};
};


class DELPHICLASS TPivotState;
class PASCALIMPLEMENTATION TPivotState : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	void __fastcall Assign(TPivotState* Value);
	bool __fastcall IsEqual(TPivotState* Value);
	
public:
	int FDims;
	int FSums;
	int FCurrentSum;
	bool FRowSubs;
	bool FColSubs;
	bool FRowSparse;
	bool FColSparse;
	TDimInfoArray* DimInfo;
	__fastcall TPivotState(void);
	__fastcall virtual ~TPivotState(void);
};


#pragma option push -b-
enum TDecisionDataEvent { xeStateChanged, xeSummaryChanged, xePivot, xeNewMetaData, xeSourceChange };
#pragma option pop

class DELPHICLASS TDecisionDataLink;
class DELPHICLASS TDecisionSource;
class DELPHICLASS TDecisionCube;
class PASCALIMPLEMENTATION TDecisionCube : public Mxstore::TCustomDataStore 
{
	typedef Mxstore::TCustomDataStore inherited;
	
private:
	Classes::TList* FDecisionSources;
	bool FBlocked;
	Mxstore::TCubeState FState;
	bool FStreamedActive;
	void __fastcall CubeSetActive(bool Value);
	bool __fastcall CubeGetActive(void);
	bool __fastcall GetSparsing(void);
	void __fastcall SetSparsing(bool Value);
	void __fastcall AddDataSource(TDecisionSource* source);
	void __fastcall RemoveDataSource(TDecisionSource* source);
	void __fastcall NotifyDataSources(TDecisionDataEvent Event);
	AnsiString __fastcall GetAnySQL(Mxarrays::TSmallIntArray* ValueArray, AnsiString SelectList, bool bActive, bool bGrouped);
	__property bool Sparsing = {read=GetSparsing, write=SetSparsing, nodefault};
	
protected:
	virtual bool __fastcall CanDimBeClosed(int iMapIndex);
	virtual bool __fastcall CanSumBeClosed(int iMapIndex);
	
public:
	__fastcall virtual TDecisionCube(Classes::TComponent* AOwner);
	__fastcall virtual ~TDecisionCube(void);
	__property DesignState ;
	AnsiString __fastcall GetSQL(Mxarrays::TSmallIntArray* ValueArray, bool bActive);
	AnsiString __fastcall GetDetailSQL(Mxarrays::TSmallIntArray* ValueArray, AnsiString SelectList, bool bActive);
	void __fastcall ShowCubeDialog(void);
	virtual void __fastcall StateChanged(void);
	__property bool Active = {read=CubeGetActive, write=CubeSetActive, nodefault};
	
__published:
	__property DataSet ;
	__property DimensionMap ;
	__property ShowProgressDialog ;
	__property MaxDimensions ;
	__property MaxSummaries ;
	__property MaxCells ;
	__property OnLowCapacity ;
	__property BeforeOpen ;
	__property AfterOpen ;
	__property BeforeClose ;
	__property AfterClose ;
	__property OnRefresh ;
};


class PASCALIMPLEMENTATION TDecisionSource : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	int FChangeCount;
	Mxstore::TCubeState FState;
	bool bActivated;
	bool FBlocked;
	TDecisionCube* FDecisionCube;
	TDecisionControlType FControlType;
	Classes::TList* FDecisionDataLinks;
	TPivotState* FSavePivotState;
	TPivotState* FData;
	Mxarrays::TTwoDimArray* RowLookup;
	Mxarrays::TTwoDimArray* ColLookup;
	int FRowMax;
	int FColMax;
	int FActiveRows;
	int FActiveCols;
	int FAllRows;
	int FAllPages;
	int FAllCols;
	void __fastcall SetUpData(void);
	void __fastcall RebuildPivotState(void);
	void __fastcall BuildLookups(void);
	bool __fastcall GetReady(void);
	void __fastcall AddDatalink(TDecisionDataLink* link);
	void __fastcall RemoveDatalink(TDecisionDataLink* link);
	void __fastcall NotifyDataLinks(TDecisionDataEvent Event);
	void __fastcall ReadDimCount(Classes::TReader* Reader);
	void __fastcall WriteDimCount(Classes::TWriter* Writer);
	void __fastcall ReadSumCount(Classes::TReader* Reader);
	void __fastcall WriteSumCount(Classes::TWriter* Writer);
	void __fastcall ReadCurrentSum(Classes::TReader* Reader);
	void __fastcall WriteCurrentSum(Classes::TWriter* Writer);
	void __fastcall ReadRowSparse(Classes::TReader* Reader);
	void __fastcall WriteRowSparse(Classes::TWriter* Writer);
	void __fastcall ReadColSparse(Classes::TReader* Reader);
	void __fastcall WriteColSparse(Classes::TWriter* Writer);
	void __fastcall ReadDimInfo(Classes::TReader* Reader);
	void __fastcall WriteDimInfo(Classes::TWriter* Writer);
	int __fastcall GetExampleRepCount(TDimGroup dimGroup, int level);
	void __fastcall DrillValue(int iDim, int ValueIndex);
	void __fastcall DecisionDataEvent(TDecisionDataEvent Event);
	void __fastcall EnforceConstraints(TDimGroup dimGroup, int PreserveIndex);
	bool __fastcall GetRowSparsing(void);
	bool __fastcall GetColSparsing(void);
	void __fastcall SetRowSparsing(bool Value);
	void __fastcall SetColSparsing(bool Value);
	TDecisionCube* __fastcall GetDecisionCube(void);
	void __fastcall SetDecisionCube(TDecisionCube* Value);
	int __fastcall GetDims(void);
	int __fastcall GetSums(void);
	int __fastcall GetCurrentSum(void);
	void __fastcall ProcessPivotState(TPivotState* FState);
	virtual void __fastcall FetchPivotState(TPivotState* &FState);
	virtual void __fastcall StorePivotState(TPivotState* FState);
	virtual void __fastcall BeginChange(void);
	virtual void __fastcall EndChange(TDecisionDataEvent event);
	
protected:
	void __fastcall SetDimGroup(int iDim, TDimGroup Group, int Index, bool bOpen);
	void __fastcall SetDimState(int iDim, TDimState State, int ValueIndex);
	
public:
	Classes::TNotifyEvent FOnBeforePivot;
	Classes::TNotifyEvent FOnAfterPivot;
	Classes::TNotifyEvent FOnStateChange;
	Classes::TNotifyEvent FOnNewDimensions;
	Classes::TNotifyEvent FOnLayoutChange;
	Classes::TNotifyEvent FonSummaryChange;
	__fastcall virtual TDecisionSource(Classes::TComponent* AOwner);
	__fastcall virtual ~TDecisionSource(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	AnsiString __fastcall GetMemberAsString(int iDim, int ValueIndex);
	Variant __fastcall GetMemberAsVariant(int iDim, int ValueIndex);
	AnsiString __fastcall GetDimensionName(int iDim);
	int __fastcall GetDimensionMemberCount(int iDim);
	AnsiString __fastcall GetSummaryName(int iSum);
	void __fastcall SetCurrentSummary(int Value);
	Variant __fastcall Get2DDataAsVariant(int iDimA, int iDimB, int aValueIndex, int bValueIndex);
	AnsiString __fastcall GetDataAsString(int ARow, int ACol, int &SubLevel);
	Variant __fastcall GetDataAsVariant(int Arow, int ACol, int &SubLevel);
	int __fastcall GetValueIndex(TDimGroup dimGroup, int Index, int Cell, bool &isBreak, bool &isSum);
	bool __fastcall GetValueArray(int ACol, int ARow, Mxarrays::TSmallIntArray* &ValueArray);
	TDimRange __fastcall GetGroupExtent(TDimGroup dimGroup, int Index, int Cell);
	int __fastcall GetActiveDim(TDimGroup dimGroup, int index, bool bOpen);
	void __fastcall OpenDimIndexRight(TDimGroup dimGroup, int Index, bool bOpen);
	void __fastcall CloseDimIndexRight(TDimGroup dimGroup, int Index, bool bOpen);
	void __fastcall OpenDimIndexLeft(TDimGroup dimGroup, int Index, bool bOpen);
	void __fastcall ToggleDimIndex(TDimGroup dimGroup, int Index, bool bOpen);
	void __fastcall DrillDimIndex(TDimGroup dimGroup, int Index, int ValueIndex, bool bOpen);
	void __fastcall MoveDimIndexes(TDimGroup SdimGroup, TDimGroup DdimGroup, int SIndex, int DIndex, bool bOpen);
	void __fastcall SwapDimIndexes(TDimGroup SdimGroup, TDimGroup DdimGroup, int SIndex, int DIndex, bool bOpen);
	int __fastcall GetGroupCount(TDimGroup dimGroup, bool bOpen);
	TDimGroup __fastcall GetGroup(int iDim);
	int __fastcall GetIndex(int iDim, bool bOpen);
	TDimState __fastcall GetState(int iDim);
	int __fastcall GetValue(int iDim);
	TRowState __fastcall GetRowState(int iDim);
	__property bool Ready = {read=GetReady, nodefault};
	__property int nDims = {read=GetDims, nodefault};
	__property int nSums = {read=GetSums, nodefault};
	__property int nRowDims = {read=FAllRows, nodefault};
	__property int nColDims = {read=FAllCols, nodefault};
	__property int nOpenRowDims = {read=FActiveRows, nodefault};
	__property int nOpenColDims = {read=FActiveCols, nodefault};
	__property int nDataRows = {read=FRowMax, nodefault};
	__property int nDataCols = {read=FColMax, nodefault};
	__property int CurrentSum = {read=GetCurrentSum, nodefault};
	
__published:
	__property TDecisionCube* DecisionCube = {read=GetDecisionCube, write=SetDecisionCube};
	__property TDecisionControlType ControlType = {read=FControlType, write=FControlType, nodefault};
	__property Name ;
	__property bool SparseRows = {read=GetRowSparsing, write=SetRowSparsing, nodefault};
	__property bool SparseCols = {read=GetColSparsing, write=SetColSparsing, nodefault};
	__property Classes::TNotifyEvent OnStateChange = {read=FOnStateChange, write=FOnStateChange};
	__property Classes::TNotifyEvent OnNewDimensions = {read=FOnNewDimensions, write=FOnNewDimensions};
	__property Classes::TNotifyEvent OnLayoutChange = {read=FOnLayoutChange, write=FOnLayoutChange};
	__property Classes::TNotifyEvent OnSummaryChange = {read=FonSummaryChange, write=FonSummaryChange};
	__property Classes::TNotifyEvent OnBeforePivot = {read=FOnBeforePivot, write=FOnBeforePivot};
	__property Classes::TNotifyEvent OnAfterPivot = {read=FOnAfterPivot, write=FOnAfterPivot};
};


class PASCALIMPLEMENTATION TDecisionDataLink : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
protected:
	TDecisionSource* FDecisionSource;
	bool FBlocked;
	void __fastcall SetDecisionSource(TDecisionSource* source);
	virtual void __fastcall DecisionDataEvent(TDecisionDataEvent Event);
	
public:
	__fastcall TDecisionDataLink(void);
	__fastcall virtual ~TDecisionDataLink(void);
	__property TDecisionSource* DecisionSource = {read=FDecisionSource, write=SetDecisionSource};
};


class DELPHICLASS TQADecisionSource;
class PASCALIMPLEMENTATION TQADecisionSource : public TDecisionSource 
{
	typedef TDecisionSource inherited;
	
public:
	#pragma option push -w-inl
	/* TDecisionSource.Create */ inline __fastcall virtual TQADecisionSource(Classes::TComponent* AOwner) : TDecisionSource(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDecisionSource.Destroy */ inline __fastcall virtual ~TQADecisionSource(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Mxdb */
using namespace Mxdb;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXDB
