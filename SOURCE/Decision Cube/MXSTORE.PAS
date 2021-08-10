{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Mxstore;

interface

uses
  Windows, Variants, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  BDE, DB, DBCommon, DBTables, Mxarrays, Menus,
  MXPBAR, MXCOMMON, MXTABLES;

const
  SubTotal  = -1;
  NonSparseAgg = -4;
  SparseUnknown = -3;
  SparseAgg = -2;
  SparseSum = -1;
  MaxBinDimensions = 16;
  LargeValueCount = 50;
  
type
  TMultiDimDataLink = class;
  TDataCache = class;
  TCustomDataStore = class;
  TCubeDims = class;
  TCubeDim = class;

  TErrorAction = (eaFail, eaContinue);

  TCapacityErrorEvent = procedure(var EAction: TErrorAction) of object;
  TCubeNotifyEvent  = procedure(DataCube: TCustomDataStore) of object;
  TCubeRefreshEvent = procedure(DataCube: TCustomDataStore; DimMap: TCubeDims) of object;

  { Designtime state }
  TCubeDataState = (dsNoData, dsMetaData, dsDimensionData, dsAllData);

  TBuildType = (btHardRebuild, btSoftRebuild, btNoRebuild);

  { Public cube state }
  TCubeState = (dcInactive, dcBrowseMetaData, dcBrowseMemberData, dcBrowseAllData);

  { These flags govern some of the behaviour of dimensions and summaries }
  TDimFlagSet = set of TDimFlags;

  TCubeDimTransformEvent = procedure(var Value: Variant; Data: TCubeDim) of object;

  TCubeDim = class(TDimensionItem)
  private
    FBinType: TBinType;
    FTransform: TCubeDimTransformEvent;
    FStartDate: TDate;
    FBinFormat: string;
    FStartValue: string;
    FDirty: Boolean;
    FBinData: TBinData;
    FValues: Integer;
    bWasActive:	Boolean;
    procedure SetBin(Value: TBinType);
    function GetBin: TBinType;
    procedure SetDate(Value: TDate);
    procedure SetStart(Value: string);
    procedure ReadDateBin(Reader: TReader);
    procedure ReadStartDate(Reader: TReader);
    procedure ReadStartValue(Reader: TReader);
    procedure WriteStartValue(Writer: TWriter);
    procedure ReadActive(Reader: TReader);
    procedure WriteActive(Writer: TWriter);
  protected
    procedure YearTransform(var Value: Variant; CubeDim: TCubeDim);
    procedure QuarterTransform(var Value: Variant; CubeDim: TCubeDim);
    procedure MonthTransform(var Value: Variant; CubeDim: TCubeDim);
    procedure DataSetTransform(var Value: Variant; CubeDim: TCubeDim);
    function AssignBinTypeTransform(Bins: TBinType): TCubeDimTransformEvent;
    function AssignBinTypeFormat(Bins: TBinType): string;
    procedure NotifyCollection(aType: TCDNotifyType); override;
    procedure InitializeRange; override;
    procedure DoTransform(var Value: Variant); virtual;
    property Dirty: Boolean read FDirty write FDirty;
    function GetLoaded:	Boolean;
    procedure SetLoaded(Value: Boolean);
    property wasActive: Boolean read bWasActive write bWasActive;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Value: TPersistent); override;
    procedure DefineProperties(Filer: TFiler); override;
    function GetBinValues(Value: Variant): Variant;
    function IsBinData: Boolean;
    property BinFormat: string read FBinformat write FBinformat;
    property StartDate: TDate read FStartDate write SetDate;
    property Loaded: Boolean read GetLoaded write SetLoaded;
    property StartValue: String read FStartValue write SetStart;
    property BinData: TBinData read FBinData;
    property OnTransform: TCubeDimTransformEvent read FTransform write FTransform;
  published
    property BinType: TBinType read GetBin write SetBin;
    property ValueCount: Integer read FValues write FValues;
  end;

  TCubeDimClass = class of TCubeDim;

  TCubeDims = class(TDimensionItems)
  private
    function GetCubeDim(Index: Integer): TCubeDim;
    procedure SetCubeDim(Index: Integer; Value: TCubeDim);
  protected
    function Add: TCubeDim;
    function GetDirtyFlag: Boolean;
    function GetOwner: TPersistent; override;
  public
    constructor Create(FOwner: TPersistent; ItemClass: TCubeDimClass);
    procedure Assign(Source: TPersistent);override;
    property IsDirty: Boolean read GetDirtyFlag;
    property Items[Index: Integer]: TCubeDim read GetCubeDim write SetCubeDim; default;
  end;

  { This is the multi-dimensional data store component }

  TCustomDataStore = class(TComponent)
  private
    FCache: TDataCache;          { The data cache object }
    FDataLink: TMultiDimDataLink;	{ Links this component to a dataset }
    FState: TCubeState;
    FDesignState: TCubeDataState;
    FDimensionMap: TCubeDims;
    FDataSet: TDataSet;
    FShowProgress: Boolean;
    FBinData: Boolean;
    FDirty: Boolean;
    FMaxDims: Integer;
    FMaxSums: Integer;
    FMaxCells:Integer;
    FInternalDataSource: TDataSource;
    FOnCapacityError: TCapacityErrorEvent;
    FBeforeOpen: TCubeNotifyEvent;
    FAfterOpen: TCubeNotifyEvent;
    FBeforeClose: TCubeNotifyEvent;
    FAfterClose: TCubeNotifyEvent;
    FOnRefresh: TCubeRefreshEvent;
    function GetDataSource: TDataSource;
    procedure SetDataSource(Value: TDataSource);
    procedure SetActive(Value: Boolean);
    function GetDimensionCount: Integer;
    function GetSummaryCount: Integer;
    function GetDimensionMapCount: Integer;
    function GetActive: Boolean;
    procedure SetState(Value: TCubeState);
    procedure SetDesignState(Value: TCubeDataState);
    function GetCubeState: Boolean;
    procedure OpenCache;
    procedure CloseCache;
    procedure SetCapacity(Value: Integer);
    function GetCapacity: Integer;
    procedure SetMaxDims(Value: Integer);
    procedure SetMaxSums(Value: Integer);
    procedure SetBinData(Value: Boolean);
    function CheckDimensionMap(DimMap: TCubeDims; var BuildType: TBuildType): Boolean;
    procedure SetLoadMap(DimMap, OldMap: TCubeDims);
  protected
    procedure ActiveChanged; virtual;
    procedure StateChanged; virtual;
    procedure DoBeforeOpen; virtual;
    procedure DoAfterOpen; virtual;
    procedure DoBeforeClose; virtual;
    procedure DoAfterClose; virtual;
    procedure DoOnRefresh(DimMap: TCubeDims); virtual;
    function GetDataSet: TDataSet;
    function GetDomain(DimensionIDs: TIntArray; ATotals: Boolean; Domain: TTwoDimArray): Integer;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetDataSet(ADataSet: TDataSet);
    function GetCurrentSummary: Integer;
    procedure SetCurrentSummary(Value: Integer);
    procedure LayoutChanged; virtual;
    function BinMapHasBinData: Boolean;
    function CanDimBeClosed(iMapIndex: Integer): Boolean; virtual;
    function CanSumBeClosed(iMapIndex: Integer): Boolean; virtual;
    property DataCache: TDataCache read FCache;
    property DataLink: TMultiDimDataLink read FDataLink;
    property InternalDataSource: TDataSource read FInTernalDataSource;
    property DesignState: TCubeDataState read FDesignState write SetDesignState;
    property DataSource: TDataSource read GetDataSource write SetDataSource;
    property Active: Boolean read GetActive write SetActive default False;
    property State: TCubeState read FState; { Returns the cube state }
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CalcSubTotals;
    procedure Refresh(DimMap: TCubeDims; bForce: Boolean); 
    function GetMemoryUsage: Integer;		                                { Gets the total memory consumed by the DecisionCube}
    function GetDimensionName(Dimension: Integer): String; virtual;	        { Returns the name of the dimension as a string }
    function GetDimensionMemberCount(Dimension: Integer): Integer; virtual;	{ Returns the number of members of a dimension }
    function GetMemberAsString(Dimension, Index: Integer): String; virtual;  { Returns the value of the member at index as a string }
    function GetMemberAsVariant(Dimension, Index: Integer): Variant;		{ Returns the value of the member at index as a variant }
    function GetSummaryName(ISum: Integer): String; virtual;			{ Returns the name of the summary }
    function GetSummaryAsString(Coord: TSmallIntArray): String; virtual;	{ Gets the summary value as a string }
    function GetSummaryAsVariant(Coord: TSmallIntArray): Variant; virtual;	{ Gets the summary value as a variant }
    property DimensionMapCount: Integer read GetDimensionMapCount;		{ Gets the number of dimensions in TCubeDims }
    property DimensionCount: Integer read GetDimensionCount;			  { Gets the number of dimensions }
    property SummaryCount: Integer read GetSummaryCount;			      { Get the number of summaries }
    property CurrentSummary: Integer read GetCurrentSummary write SetCurrentSummary;  { Returns the active summary }
    property Capacity: Integer read GetCapacity write SetCapacity; { Sets the Internal capacity limit for the cache }
    property BinData: Boolean read FBinData write SetBinData;                     { Reports if the data set is being binned or not }
    property DataSet: TDataSet read GetDataSet write SetDataSet;		              { Reads and sets the data set }
    property DimensionMap: TCubeDims read FDimensionMap write FDimensionMap;     { Reads or sets TCubeDims }
    property ShowProgressDialog: Boolean read FShowProgress write FShowProgress;
    property MaxDimensions: Integer read FMaxDims write SetMaxDims;
    property MaxSummaries: Integer read FMaxSums write SetMaxSums;
    property MaxCells: Integer read FMaxCells write FMaxCells;
    property OnLowCapacity: TCapacityErrorEvent read FOnCapacityError write FOnCapacityError;
    property BeforeOpen: TCubeNotifyEvent read FBeforeOpen write FBeforeOpen;
    property AfterOpen: TCubeNotifyEvent read FAfterOpen write FAfterOpen;
    property BeforeClose: TCubeNotifyEvent read FBeforeClose write FBeforeClose;
    property AfterClose: TCubeNotifyEvent read FAfterClose write FAfterClose;
    property OnRefresh: TCubeRefreshEvent read FOnRefresh write FOnRefresh;
  end;

  { This object handles the interface to a datasource, be it a table or a query. }
  
  TMultiDimDataLink = class(TDataLink)
  private
    FDataStore: TCustomDataStore;
    FDataSource: TDataSource;
    function EstimateCapacity(RangeCnt: Integer): Integer;
    procedure DoUpdateCache;
  protected
    function AddDimension(DimMap: TCubeDim; Fld: TField): Integer;
    procedure AddSummary(DimMap: TCubeDim; Fld: TField);
    procedure ActiveChanged; override;
    procedure LayoutChanged; override;
    procedure UpdateCache(Sender: TObject);
    procedure UpdateDimensions(DimAllList: TList);
    procedure FetchValues(DimAllList: TList);
    procedure FetchAndBinValues(DimAllList: TList);
    procedure CreateSummaryIndex(DimAllList: TList);
    procedure UpdateFormatStrings;
  public
    constructor Create(AStore: TCustomDataStore);
    destructor Destroy; override;
  end;

  { The basic field definition, dependent on DB implementation. }

  TFormatType = (fxNone, fxFloat, fxCurrency, fxDateTime, fxTime, fxDate, fxString, fxInteger, fxBoolean);

  TFieldDefinition = class
  private
    FFormatString: string;
    FFieldType: TFieldType;
    FWidth: Integer;
    FName: String;
    FFormatType: TFormatType;
    FPrecision: Integer;
    FFieldNo: Integer;
  public
    constructor Create;
    function FormatVariantToStr(Value: Variant): string;
    procedure SetFieldType(FType: TFieldType);
    procedure SetName(Value: String);
    property Width: Integer read FWidth write FWidth;
    property FormatString: string read FFormatString write FFormatString;
    property FieldType: TFieldType read FFieldType write SetFieldType;
    property Precision: Integer read FPrecision write FPrecision;
    property DisplayName:  String read FName write SetName;
    property FieldNo: Integer read FFieldNo write FFieldNo;
  end;

  { This is the dimension object that contains unique members for a field }

  TDimension = class(TCustomArray)
  private
    FPosition: Integer;     { The position of the field in the data set. Can be different from FieldNo. }
    FRange: Integer;     { This is the group range for a value, Used in summery calculations }
    FFlags: TDimFlagSet; { Flags that determine the attributes for the dimension. }
    FFieldDef: TFieldDefinition;
    FFieldName: string;        { used for matching with the dataset name }
    procedure SetFieldType(Value: TFieldType);
    function GetFieldType: TFieldType;
    procedure SetPosition(Value: Integer);
    procedure SetName(Value: String);
    function GetName: string;
    procedure SetRange(Value: Integer);
  public
    constructor Create(Items: Cardinal; DataType: TFieldType);
    destructor Destroy; override;
    function IsString: Boolean;
    procedure SetFlag(aFlag: TDimFlags);
    function HasFlag(aFlag: TDimFlags): Boolean;
    procedure ClearFlag(aFlag: TDimFlags);
    procedure SetRangeCounting(bRange: Boolean);
    procedure AssignSorted(Dim: TDimension; bUnique: Boolean);
    property Range: Integer read FRange write SetRange;
    property Attributes: TDimFlags write SetFlag;
    property DimensionName: String read GetName write SetName;
    property FieldType: TFieldType read GetFieldType write SetFieldType;
    property Position: Integer read FPosition write SetPosition;
    property FieldDefinition: TFieldDefinition read FFieldDef;
    property FieldName: string read FFieldName write FFieldName;
  end;

  TIndexFlag = (idxNormal, idxSparsed, idxFiltered, idxSubTotals, idxDeleted);
  TIndexFlags = set of TIndexFlag;

  PIndexInfoRec = ^TIndexInfoRec;
  TIndexInfoRec = Record
    SparseCnt,
    SubTotalCnt,
    AggOffset: Integer;
    Flags: TIndexFlags;
  end;

  TIndexInfo = class
  private
    FSparseCnt: Integer;
    FSubTotalCnt: Integer;
    FCount: Integer;
    FExtInfo: Boolean;
    FOffset: TIntArray;
    FAddAggs: Boolean;
    FLock: TRTLCriticalSection;
  public
    constructor Create;
    destructor Destroy; override;
    procedure SetCapacity(Value: Integer);
    function GetCapacity: Integer;
    function Add(pIdxRec: PIndexInfoRec): Integer;
    function IsSparse(Index: Integer): Boolean;
    function IsSparseAgg(Index: Integer): Boolean;
    procedure AddOffset(Index, IdxType: Integer);
    function LockIndex: TIntArray;
    procedure UnlockIndex;
    property Count: Integer read FCount;
    property Capacity: Integer read GetCapacity write SetCapacity;
    property AddAggs: Boolean read FAddAggs write FAddAggs;
  end;

  TDerivedAggProc = function(Val1, Val2: Variant): Variant;
  TFieldArgs = array[0..255] of Byte;

  TAggDefinition = class
  private
    FSummaryIdx: TFieldArgs;
    FAggProc: TDerivedAggProc;
  public
    property AggProc: TDerivedAggProc read FAggProc write FAggProc;
  end;

  TSummary = class;
  TSumMethod = function (SumIndex: TSmallIntArray; Summary: TSummary; var Value: Variant): Boolean of object;

  { This is the summary object that contains the summary data and sub-totals }

  TSummary = class(TCustomArray)
  private
    FPosition: Integer;       { The position of the field in the data set. Can be different from TField.FieldNo. }
    FCubeDimIndex: Integer;      { The index into the TCubeDim }
    FFlags: TDimFlagSet;   { Flags that determine the attributes for the dimension. }
    FIndexInfo: TIndexInfo;    { Just a copy of the master index info }
    FTotals: TThreadCustomArray;  { Separate array that holds sub-totals }
    FIndexMap: TIndexArray;         { Just a copy of the master map from the data cache }
    FFieldDef: TFieldDefinition;
    FFieldName: string;              { used for matching with the dataset name }
    FAggDef: TAggDefinition;
    FSumMethod: TSumMethod;
    procedure SetFieldType(Value: TFieldType);
    function GetFieldType: TFieldType;
    procedure SetPosition(Value: Integer);
    procedure SetFlag(aFlag: TDimFlags);
    procedure SetName(Value: String);
    function GetName: string;
    function GetDerived: Boolean;
  protected
    function HasFlag(aFlag: TDimFlags): Boolean;
    function SetAggregator(aName: string; DimMap: TCubeDims; dimType: TDimFlags; var dIdx: Integer): Boolean;
  public
    constructor Create(Items: Cardinal; DataType: TFieldType);
    destructor Destroy; override;
    procedure ClearTotals;
    function MemoryUsage: Integer; override;
    function IsSparse(Index: Integer): Boolean;
    procedure UpdateIndexInfo(Index: Integer; Value: Variant);
    function AddIndexInfo(BTotal, bSparse: Boolean; iAggOffset: Integer): Integer;
    function AddSubTotal(Value: Variant): Integer;
    procedure AddSum(var SumIndex: TSmallIntArray; vNew: Variant);
    property Name: String read GetName write SetName;
    property Attributes: TDimFlags write SetFlag;
    property FieldType: TFieldType read GetFieldType write SetFieldType;
    property Position: Integer read FPosition write SetPosition;
    property FieldDefinition: TFieldDefinition read FFieldDef;
    property FieldName: string read FFieldName write FFieldName;
    property SumMethod: TSumMethod read FSumMethod write FSumMethod;
    property CubeDimIndex: Integer read FCubeDimIndex write FCubeDimIndex;
    property AggDefinition: TAggDefinition read FAggDef write FAggDef;
    property IsDerived: Boolean read GetDerived;
  end;

  { This class contains the main summary data cache }

  ECacheError = class(Exception);
  TAggProc = function (eCnt, Range: Integer; Summary: TSummary; SumIndex: TSmallIntArray; var vNew: Variant): Boolean;

  { These flags govern the general build state of the cache. }
  TCacheStateFlags = (csHasIndex, csDirty, csSuccess, csShowProgress, csRefreshing);
  TCacheState = set of TCacheStateFlags;

  { These flags govern the building of lookups for pivoting }
  TLookupStateFlags = (lsSparsing, lsCursor, lsShowProgress);
  TLookupState = set of TLookupStateFlags;

  { These flags govern how totals will be calculated and stored }
  TCalcTotalsFlags = (ctPreCalc, ctRunning, ctNone);
  TCalcTotals = set of TCalcTotalsFlags;

  TDataCache = class
  private
    FSummaryData: TList;           { This is where we cache the summary data }
    FDimensions: TList;           { The list of TDimensions }
    FActiveSummary: Integer;      { The current summary }
    FIndexMap: TIndexArray;  { The index for the cube. }
    FIndexInfo: TIndexInfo;   { Index info, about sparing, etc. }
    FAggProc: TAggProc;
    FErrorCode: Integer;
    FCalcTotals: TCalcTotals;   { How to calculate the totals }
    FLookupState: TLookupState;
    FActive: Boolean;
    FState: TCacheState;   { Cache state flags }
    {$IFDEF PROFILE}
    FTicks: TTicks;
    FProfileLogFile: string;
    {$ENDIF}
    procedure Init;
    function IsBlankSummary: Boolean;
    function GetDimensionCount: Integer;
    function GetDimension(Index: Integer): TDimension;
    procedure SetDimension(Index: Integer; Value: TDimension);
    function GetSummaryCount: Integer;
    function GetSummary(Index: Integer): TSummary;
    procedure SetActiveSummary(Index: Integer);
    procedure GetScope(var OffsetIdx, AggIdx, AggRange: Integer; SumIndex: TSmallIntArray);
    function IsIndexSparse(SumIndex: TSmallIntArray): Boolean;
    function GetSuccess: Boolean;
    procedure SetSuccess(Value: Boolean);
    function GetPreCalcTotals: Boolean;
    procedure SetPreCalcTotals(Value: Boolean);
    function GetSparsing: Boolean;
    procedure SetSparsing(Value: Boolean);
    function GetHasIndex: Boolean;
    procedure SetHasIndex(Value: Boolean);
    function GetAggSummary(SumIndex: TSmallIntArray; Summary: TSummary; var Value: Variant): Boolean;
    function GetBaseSummary(SumIndex: TSmallIntArray; Summary: TSummary; var Value: Variant): Boolean;
  protected
    procedure FreeCache;
  public
    constructor Create;
    destructor Destroy; override;
    function GetMemoryUsage: Integer;
    procedure CalcSubTotals;
    procedure ClearIndexInfo;
    function AddAggIndex(SumIndex: TSmallIntArray; BuilderDims: TList):Integer;
    function AddIndex(SumIndex: TSmallIntArray; bSparse: Boolean):Integer;
    function IsDimension(Position: Integer): Boolean;
    function IsSummary(Position: Integer): Boolean;
    function SummaryFromPosition(Position: Integer): TSummary;
    function SummaryFromFieldName(FldName: string): TSummary;
    function SummaryFromCubeDimIndex(Index: Integer): TSummary;
    function DimensionFromFieldName(FldName: string): TDimension;
    function AppendDimension(Value: TDimension): Integer;
    function AppendSummary(Value: TSummary): Integer;
    function GetDimensionName(DimIndex: Integer): String;
    function GetSummaryName(ISum: Integer): String;
    function GetDimensionMember(DimIndex, MemberIndex: Integer): String;
    function GetDimensionMemberAsVariant(DimIndex, MemberIndex: Integer): Variant;
    function GetDimensionMemberCount(DimIndex : Integer): Integer;
    function GetIndexCount: Integer;
    function IncSummaryIndex(Summary: TSummary; SumIndex, rangeCount: TSmallIntArray; var bGroupBreak: Boolean): Boolean;
    function HasSubTotals(SumIndex: TSmallIntArray): Boolean;
    function HasValidSubTotals(Summary: TSummary ; SumIndex: TSmallIntArray): Boolean;
    function GetSummaryAsString(SumIndex: TSmallIntArray): String;
    function GetSummaryAsVariant(SumIndex: TSmallIntArray): Variant;
    procedure CreateTable(Const Filename: String);
    function GetDomain(DimensionIDs: TIntArray; nDims: Integer; ATotals: Boolean; Domain: TTwoDimArray): Integer;
    property PreCalculateTotals: Boolean read GetPreCalcTotals write SetPreCalcTotals;
    property CurrentSummary: Integer read FActiveSummary write SetActiveSummary;
    property DimensionCount: Integer read GetDimensionCount;
    property SummaryCount: Integer read GetSummaryCount;
    property Summaries[Index: Integer]: TSummary read GetSummary;
    property Dimensions[Index: Integer]: TDimension read GetDimension write SetDimension;
    property Active: Boolean read FActive write FActive;
    property Sparsing: Boolean read GetSparsing write SetSparsing;
    property IndexCount: Integer read GetIndexCount;
    property Success: Boolean read GetSuccess write SetSuccess;
    property ErrorCode: Integer read FErrorCode write FErrorCode;
    property HasIndex: Boolean read GetHasIndex write SetHasIndex;
    {$IFDEF PROFILE}
    property Ticks: TTicks read FTicks;
    property ProfileLogFile: string read FProfileLogFile write FProfileLogFile;
    {$ENDIF}
  end;

  TBuilderDim = class(TDimension)
  private
    FGroupBreak: Boolean;
    FActiveIndex: Integer;
    FSummary: TCustomArray;
    FLastVal: Variant;
    FValueList: TStringArray;
    FSummaryDataType: Integer;
  protected
    function GetLastVal: Variant;
    procedure SetLastVal(Value: Variant);
  public
    constructor Create(Items: Cardinal; DataType: TFieldType);
    destructor Destroy; override;
    function GetSumCount: Integer;
    function GetSummary(Value: Variant): Variant;
    procedure InitSummary(DataType: Integer);
    procedure Add(Value: Variant);         { Add the value }
    procedure AddSummary(Value: Variant);  { Add to the running summary }
    function MatchLastVal(Value: Variant): Boolean;
    property GroupBreak: Boolean read FGroupBreak write FGroupBreak;
    property LastVal: Variant read GetLastVal write SetLastVal;
    property SumCount: Integer read GetSumCount;
  end;

  function TestMatch(SumIdx: TSmallIntArray): Boolean;

implementation

uses
  Math, DBConsts, bdeconst, Mxconsts;

  { Helper functions for this Unit }

function TestMatch(SumIdx: TSmallIntArray): Boolean;
var
  mIdx: TSmallIntArray;
  i: Integer;
begin
  Result := True;
  mIdx := TSmallIntArray.Create(0,0);
  mIdx[0] := 1;
  mIdx[1] := 1;
  mIdx[2] := 1;
  mIdx[3] := -1;
  mIdx[4] := -1;
  for i := 0 to SumIdx.Count-1 do
  begin
    if (SumIdx[i] <> mIdx[i]) then
    begin
      Result := False;
      break;
    end;
  end;
  mIdx.Free;
end;

function GetDisplayFormat(fld: TField): string;
begin
  case fld.DataType of
    ftCurrency,
    ftFloat,
    ftBCD,
    ftInteger : Result := TNumericField(fld).DisplayFormat;
    ftDate,
    ftTime,
    ftDateTime: Result := TDateTimeField(fld).DisplayFormat;
    else
      Result := '';
  end;
end;

function GetPrecision(fld: TField): Integer;
begin
  case fld.DataType of
    ftCurrency,
    ftFloat: Result := TFloatField(fld).Precision;
    else
      Result := 0;
  end;
end;

function IsDateField(FldType: TFieldType): Boolean;
begin
  case FldType of
    ftUnknown,
    ftDate,
    ftDateTime: Result := True;
    else
      Result := False;
  end;
end;

function CalcTotals1(eCnt, Range: Integer; Summary: TSummary; SumIndex: TSmallIntArray; var vNew: Variant): Boolean;
var
  iOffSet, agg: Integer;
  V: Variant;

  function MatchIndex(Idx: Integer; SumIndex: TSmallIntArray): Boolean;
  var
    i: Integer;
    IMap: TSmallIntArray;
  begin
    Result := True;
    IMap := Summary.FIndexMap[Idx];
    for i := 0 to IMap.Count-1 do
    begin
      { Return false if the index is a subtotal }
      if (IMap[i] = SubTotal) then
      begin
        Result := False;
        break;
      end;
      { Ignore the columns with the subtotals }
      if (SumIndex[i] = SubTotal) then Continue;
      if (IMap[i] <> SumIndex[i]) then
      begin
        Result := False;
        break;
      end;
    end;
  end;

  function VarScan: Variant;
  var
    vTmp: Variant;
    I: Integer;
  begin
    vTmp := 0;
    for I := 0 to eCnt do
    begin
      iOffSet := Summary.FindexInfo.FOffset[I];
      if (iOffSet < 0) then Continue;
      if MatchIndex(I, SumIndex) then vTmp := vTmp + Summary[iOffSet];
    end;
    Result := vTmp;
  end;

  function CurrencyScan: Variant;
  var
    cTmp: Currency;
    ptr: Pointer;
    I: Integer;
  begin
    cTmp := 0;
    ptr  := Summary.List;
    for I := 0 to eCnt do
    begin
      iOffSet := Summary.FindexInfo.FOffset[I];
      if (iOffSet < 0) then Continue;
      if MatchIndex(I, SumIndex) then
        cTmp := cTmp + TCurrencyArray(ptr).GetItem(iOffSet);
    end;
    Result := cTmp;
  end;

  function IntScan: Variant;
  var
    iTmp: Integer;
    ptr: Pointer;
    I: Integer;
  begin
    iTmp := 0;
    ptr  := Summary.List;
    for I := 0 to eCnt do
    begin
      iOffSet := Summary.FindexInfo.FOffset[I];
      if (iOffSet < 0) then Continue;
      if MatchIndex(I, SumIndex) then
        iTmp := iTmp + TIntArray(ptr).GetItem(iOffSet);
    end;
    Result := iTmp;
  end;

  function DoubleScan: Variant;
  var
    dTmp: double;
    ptr: Pointer;
    I: Integer;
  begin
    dTmp := 0;
    ptr  := Summary.List;
    for I := 0 to eCnt do
    begin
      iOffSet := Summary.FindexInfo.FOffset[I];
      if (iOffSet < 0) then Continue;
      if MatchIndex(I, SumIndex) then
        dTmp := dTmp + TDoubleArray(ptr).GetItem(iOffSet);
    end;
    Result := dTmp;
  end;

begin
  V := 0;
  agg := Summary.FindexInfo.FOffset[eCnt];
  Assert(eCnt < Summary.FIndexInfo.Count);
  if (agg = SparseAgg) then    { Sparse, just return }
  begin
    Result := False;
    Exit;
  end
  else if (agg >= 0) then
  begin
    V := Summary.FTotals.GetItem(agg);
  end
  else
  begin
    case Summary.DataType of
      varInteger:  V := IntScan;
      varDouble:   V := DoubleScan;
      varCurrency: V := CurrencyScan;
      else
        V := VarScan;
    end;
  end;
  vNew := V;
  Result := (V <> 0);
  if (agg = SparseUnknown) then Summary.UpdateIndexInfo(eCnt, V);
end;

function CalcTotals2(eCnt, Range: Integer; Summary: TSummary; SumIndex: TSmallIntArray; var vNew: Variant): Boolean;
var
  iOffSet, sCnt, agg : Integer;
  V: Variant;

  function VarScan: Variant;
  var
    vTmp: Variant;
    I: Integer;
  begin
    vTmp := 0;
    for I := sCnt to eCnt-1 do
    begin
      if Summary.FindexInfo.IsSparse(I) then Continue;
      iOffSet := Summary.FindexInfo.FOffset[I];
      if (iOffSet >= 0) then vTmp := vTmp + Summary[iOffSet];
    end;
    Result := vTmp;
  end;

  function CurrencyScan: Variant;
  var
    cTmp: Currency;
    I: Integer;
    ptr: Pointer;
  begin
    cTmp := 0;
    ptr := Summary.List;
    for I := sCnt to eCnt-1 do
    begin
      if Summary.FindexInfo.IsSparse(I) then Continue;
      iOffSet := Summary.FindexInfo.FOffset[I];
      if (iOffSet >= 0) then
        cTmp := cTmp + TCurrencyArray(ptr).GetItem(iOffSet);
    end;
    Result := cTmp;
  end;

  function IntScan: Variant;
  var
    iTmp: Integer;
    I: Integer;
    ptr: Pointer;    
  begin
    iTmp := 0;
    ptr := Summary.List;
    for I := sCnt to eCnt-1 do
    begin
      if Summary.FindexInfo.IsSparse(I) then Continue;
      iOffSet := Summary.FindexInfo.FOffset[I];
      if (iOffSet >= 0) then
        iTmp := iTmp + TIntArray(ptr).GetItem(iOffSet);
    end;
    Result := iTmp;
  end;

  function DoubleScan: Variant;
  var
    dTmp: Double;
    I: Integer;
    ptr: Pointer;

  begin
    dTmp := 0;
    ptr := Summary.List;
    for I := sCnt to eCnt-1 do
    begin
      if Summary.FindexInfo.IsSparse(I) then Continue;
      iOffSet := Summary.FindexInfo.FOffset[I];
      if (iOffSet >= 0) then
        dTmp := dTmp + TDoubleArray(ptr).GetItem(iOffSet);
    end;    
    Result := dTmp;
  end;

begin
  Assert(eCnt < Summary.FIndexInfo.Count);
  V := 0;
  agg := Summary.FindexInfo.FOffset[eCnt];
  if (agg = SparseAgg) then
  begin
    Result := False;
    Exit;
  end
  else if (agg >= 0) then
  begin
    V := Summary.FTotals.GetItem(agg);
  end
  else
  begin
    sCnt := eCnt - Range;
    case Summary.DataType of
      varInteger:  V := IntScan;
      varDouble:   V := DoubleScan;
      varCurrency: V := CurrencyScan;
      else
        V := VarScan;
    end;
  end;
  vNew := V;
  Result := (V <> 0);
  if (agg = SparseUnknown) then Summary.UpdateIndexInfo(eCnt, V);
end;

  { TCustomDataStore }

constructor TCustomDataStore.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDataLink := TMultiDimDataLink.Create(Self);
  FInternalDataSource := TDataSource.Create(Self);
  FCache := TDataCache.Create;
  FDesignState := dsAllData;
  FShowProgress := True;
  FMaxDims := 5;
  FMaxSums := 10;
  FMaxCells := 0;
  FBinData := False;
  FDirty := False;
  FDimensionMap := TCubeDims.Create(self, TCubeDim);
  DataSource := FInternalDataSource; { must be the last thing }
end;

destructor TCustomDataStore.Destroy;
begin
  FDataLink.Free;
  FDataLink := nil;
  FInternalDataSource.Free;
  FInternalDataSource := nil;
  FCache.Free;
  FDimensionMap.Free;
  inherited Destroy;
end;

procedure TCustomDataStore.SetDesignState(Value: TCubeDataState);
begin
  if (FDesignState <> Value) then
  begin
    FDesignState := Value;
    FDirty := True;
  end;
end;

function TCustomDataStore.GetCubeState: Boolean;
begin
  if (csDesigning in ComponentState) then
  begin
    case FDesignState of
       dsNoData: SetState(dcInactive);
       dsMetaData: SetState(dcBrowseMetaData);
       dsDimensionData: SetState(dcBrowseMemberData);
       else
         SetState(dcBrowseAllData);
    end;
  end
  else
    SetState(dcBrowseAllData);
  Result := FState <> dcInactive;
end;

procedure TCustomDataStore.SetState(Value: TCubeState);
begin
  if (FState <> Value) then FState := Value;
end;

function TCustomDataStore.GetActive: Boolean;
begin
  Result := State <> dcInactive;
end;

  { Sets the cache active or inactive. }

procedure TCustomDataStore.SetActive(Value: Boolean);
begin
  if (Active <> Value) then
  begin
    if Value then
    begin
      DoBeforeOpen;
      try
        OpenCache;
      except
        SetState(dcInactive);
        CloseCache;
        Assert(FCache.ErrorCode = 0, Format(sFatalCacheError , [FCache.ErrorCode]));
        raise;
      end;
      DoAfterOpen;
    end
    else
    begin
      if not (csDestroying in ComponentState) then DoBeforeClose;
      SetState(dcInactive);
      CloseCache;
      if not (csDestroying in ComponentState) then DoAfterClose;
    end;
    StateChanged;
  end;
end;

  { Opens the cache only if there is a live datalink. }

procedure TCustomDataStore.OpenCache;
begin
  if not FCache.Active then
  begin
    if (Assigned(FDatalink.Datasource)) and
    (FDataLink.Active = True) and
    (GetCubeState = True) then
    begin
      FCache.Init;
      FDataLink.DoUpdateCache;
      FCache.Active := True;
    end
    else
      SetState(dcInactive);
  end;
end;

procedure TCustomDataStore.CloseCache;
begin
  FCache.FreeCache;
  FCache.Active := False
end;

function TCustomDataStore.GetDataSource: TDataSource;
begin
  Result := FDataLink.DataSource;
end;

procedure TCustomDataStore.SetDataSource(Value: TDataSource);
begin
  { Already attached to the datasource, just exit }
  if Value = FDatalink.Datasource then Exit;
  { New datasource. Try to open/reopen the cache if the datasource.dataset is active }
  FDataLink.DataSource := Value;
  if (Value <> nil) then Value.FreeNotification(Self);
  if (Value <> nil) then SetActive(FDataLink.Active);
end;

procedure TCustomDataStore.SetDataSet(ADataSet: TDataSet);
begin
  if (FDataSet <> ADataSet) then
  begin
    if (ADataSet <> nil) then
      ADataSet.FreeNotification(Self);
    FDataSet := ADataSet;
    InternalDataSource.DataSet := FDataSet;
  end;
end;

procedure TCustomDataStore.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDataSet) then
    FDataSet := nil;
end;

function TCustomDataStore.GetDataSet: TDataSet;
begin
  Result := FDataSet;
end;

procedure TCustomDataStore.LayoutChanged;
begin
  DataLink.LayoutChanged;
end;

procedure TCustomDataStore.ActiveChanged;
begin
end;

procedure TCustomDataStore.StateChanged;
begin
end;

function TCustomDataStore.GetDimensionName(Dimension: Integer): String;
var
  i, iActive: Integer;
begin
  Result := '';
  if assigned (DimensionMap) then
  begin
    iActive := 0;
    for i := 0 to DimensionMap.count-1 do
    begin
      if DimensionMap[i].active and (DimensionMap[i].DimensionType = dimDimension) then
      begin
        if (Dimension = iActive) then Result := DimensionMap[i].Name;
        iActive := iActive + 1;
      end;
    end;
  end;
  if (Result = '') then
    Result := FCache.GetDimensionName(Dimension);
end;

function TCustomDataStore.GetMemberAsString(Dimension, Index: Integer): String;
begin
  Result := FCache.GetDimensionMember(Dimension, Index);
end;

function TCustomDataStore.GetMemberAsVariant(Dimension, Index: Integer): Variant;
begin
  Result := FCache.GetDimensionMemberAsVariant(Dimension, Index);
end;

function TCustomDataStore.GetDomain(DimensionIDs: TIntArray; ATotals: Boolean; Domain: TTwoDimArray): Integer;
begin
  Result := FCache.GetDomain(DimensionIDs, DimensionCount, ATotals, Domain);
end;

function TCustomDataStore.GetDimensionMemberCount(Dimension: Integer): Integer;
begin
  Result := FCache.GetDimensionMemberCount(Dimension);
end;

function TCustomDataStore.GetDimensionCount: Integer;
begin
  Result := FCache.DimensionCount;
end;

function TCustomDataStore.GetSummaryCount: Integer;
begin
  Result := FCache.SummaryCount;
end;

function TCustomDataStore.GetSummaryName(ISum: Integer): String;
var
  i, iActive: Integer;
begin
  Result := '';
  if assigned (DimensionMap) then
  begin
    iActive := 0;
    for i := 0 to DimensionMap.count-1 do
    begin
      if DimensionMap[i].active and (DimensionMap[i].DimensionType <> dimDimension) then
      begin
        if (iSum = iActive) then Result := DimensionMap[i].Name;
        iActive := iActive + 1;
      end;
    end;
  end;
  if (Result = '') then Result := FCache.GetSummaryName(ISum);
end;

function TCustomDataStore.GetSummaryAsString(Coord: TSmallIntArray): String;
begin
  Result := FCache.GetSummaryAsString(Coord);
end;

function TCustomDataStore.GetSummaryAsVariant(Coord: TSmallIntArray): Variant;
begin
  Result := FCache.GetSummaryAsVariant(Coord);
end;

function TCustomDataStore.GetCurrentSummary: Integer;
begin
  Result := FCache.CurrentSummary;
end;

procedure TCustomDataStore.SetCurrentSummary(Value: Integer);
begin
  if (FCache.CurrentSummary <> Value) then
  begin
    FCache.CurrentSummary := Value;
    StateChanged;
  end;
end;

function TCustomDataStore.GetMemoryUsage: Integer;
begin
  Result := 0;
  if Assigned(FCache) then Result := FCache.GetMemoryUsage;
end;

function TCustomDataStore.BinMapHasBinData: Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to FDimensionMap.Count-1 do
  begin
    if FDimensionMap[I].IsBinData or (FDimensionMap[I].active = False) then
    begin
      Result := True;
      break;
    end;
  end;
end;

function TCustomDataStore.GetDimensionMapCount: Integer;
begin
  Result := FDimensionMap.Count;
end;

procedure TCustomDataStore.SetCapacity(Value: Integer);
begin
  SetMemoryCapacity(Value);
end;

function TCustomDataStore.GetCapacity: Integer;
begin
  Result := GetMemoryCapacity;
end;

procedure TCustomDataStore.DoBeforeOpen;
begin
  if Assigned(FBeforeOpen) then
    FBeforeOpen(Self);
end;

procedure TCustomDataStore.DoAfterOpen;
begin
  if Assigned(FAfterOpen) then
    FAfterOpen(Self);
end;

procedure TCustomDataStore.DoBeforeClose;
begin
  if Assigned(FBeforeClose) then
    FBeforeClose(Self);
end;

procedure TCustomDataStore.DoAfterClose;
begin
  if Assigned(FAfterClose) then
    FAfterClose(Self);
end;

procedure TCustomDataStore.DoOnRefresh(DimMap: TCubeDims);
begin
  if Assigned(FOnRefresh) then
    FOnRefresh(Self, DimMap);
end;

procedure TCustomDataStore.SetMaxDims(Value: Integer);
begin
  if (Value <> FMaxDims) then
  begin
    if (Value >= MaxBinDimensions) then  { This is the absolute limit }
      FMaxDims := MaxBinDimensions
    else
      FMaxDims := Value;
  end;
end;

procedure TCustomDataStore.SetMaxSums(Value: Integer);
begin
  if (Value <> FMaxSums) then FMaxSums := Value;
end;

procedure TCustomDataStore.SetBinData(Value: Boolean);
begin
  if (Value <> FBinData) then FBinData := Value;
end;


function TCustomDataStore.CheckDimensionMap(DimMap: TCubeDims; var BuildType: TBuildType): Boolean;
var
  OldMap: TCubeDims;
  I: Integer;
  Dim: TDimension;
  Summary: TSummary;
begin
  Result := False;
  if not Assigned(DimensionMap) or (DimensionMap.Count = 0) then Exit;
  if FDirty then
  begin
    FDirty := False;
    Result := True;
    BuildType := btHardRebuild;
    Exit;
  end;
  OldMap := DimensionMap;
  for I := 0 to DimMap.Count-1 do
  begin
    if (OldMap[I].FieldName = DimMap[I].FieldName) then
    begin
      if (OldMap[I].active <> DimMap[I].active) then
      begin
        Result := True;
        BuildType := btHardRebuild;
        break;
      end;
      if (DimMap[I].FieldType = ftDateTime) or (DimMap[I].FieldType = ftDate) then
      begin
        if (OldMap[I].StartDate <> DimMap[I].StartDate) then
        begin
          Result := True;
          BuildType := btHardRebuild;
          break;
        end;
      end;
      if (OldMap[I].BinType <> DimMap[I].BinType) then
      begin
        Result := True;
        BuildType := btHardRebuild;
        break;
      end;
      if (OldMap[I].Name <> DimMap[I].Name) then Result := True;
      if (OldMap[I].Format <> DimMap[I].Format) then
      begin
        if DimMap[I].IsDimension then
        begin
          Dim := DataCache.DimensionFromFieldName(DimMap[I].FieldName);
          if Assigned(Dim) then
            Dim.FieldDefinition.FormatString := DimMap[I].Format;
        end
        else
        begin
          Summary := DataCache.SummaryFromFieldName(DimMap[I].FieldName);
          if Assigned(Summary) then
            Summary.FieldDefinition.FormatString := DimMap[I].Format;
        end;
        Result := True;
      end;
    end
    else
    begin
      Result := True;
      BuildType := btHardRebuild;
      break;
    end;
  end;
end;

{
  SetLoadMap:  on entry, dimMap contains a new map with Loaded set
  on dimensions which must be loaded.  If a previous map existed,
  it is passed in OldMap
}

procedure TCustomDataStore.SetLoadMap(DimMap, OldMap: TCubeDims);
var
  i, si, ci, iDims, iSums, maxCells: Integer;
  iCells, x: Integer;
  DM: TCubeDim;
begin
  maxCells := self.maxCells;
  if (maxCells <= 0) then maxCells := 2000000000;
  { Initially set the active flase on dimensions and summaries }
  { which must be loaded.  Override this flag if incompatible with ActiveTypes }
  iDims := 0; iSums := 0;
  for i := 0 to DimMap.count-1 do
  begin
    DM := DimMap[i];
    if assigned(OldMap) and (i < OldMap.Count) then
      DM.wasActive := OldMap[i].Active and (DM.ActiveFlag <> diInactive);
    case DM.ActiveFlag of
      diInactive: DM.active := false;
      diActive: DM.active := true;
    end;
    if DM.Active then
    begin
      if DM.IsDimension then
        iDims := iDims + 1
      else if (DM.DerivedFrom < 0) then
        iSums := iSums + 1;
    end;
  end;
  { pre-calculate the number of dimensions that need to be loaded }
  { Try to load all dimensions that were active before or that are being requested }
  iCells := iSums;
  if (iCells <= 0) then iCells := 1;    { always assume one summary }
  { Multiply out the ValueCounts for the already marked dimensions }
  for i := 0 to DimMap.count-1 do
  begin
    DM := DimMap[i];
    if DM.isDimension and (DM.ActiveFlag <> diInactive) then
    begin
      if DM.Active then
      begin
        if (DM.ValueCount > 0) then
          iCells := iCells * DM.ValueCount
        else
          iCells := iCells * LargeValueCount;
      end;
    end;
  end;
  { start by loading the ones that are already open somewhere }
  for i := DimMap.count-1 downto 0 do
  begin
    DM := DimMap[i];
    if DM.Active then Continue;   { already loaded }
    if DM.isDimension and CanDimBeClosed(i) then Continue;
    if DM.isSummary and CanSumBeClosed(i) then Continue;
    if DM.IsDimension then
    begin
      if (IDims < MaxDimensions) and (iCells < maxCells) then
      begin
        x := iCells;
        if (DM.ValueCount > 0) then
          x := x * DM.ValueCount
        else
          x:= x*LargeValueCount;
        if (x > MaxCells) then
          Continue;
        iCells := x;
        IDims := IDims + 1;
        DM.active := true;
      end;
    end
    else
    begin
      if (iSums < MaxSummaries) and (iCells < maxCells) then
      begin
        if (iSums > 0) then   { the first one is always precalculated }
        begin
          x := (iCells * (iSums+1)) div iSums;
          if (x > maxCells) then Continue;
          iCells := x;
        end;
        iSums := iSums + 1;
        DM.active := true;
      end;
    end;
  end;
  { Now try to load the dimensions which were formerly active }
  for i := DimMap.count-1 downto 0 do
  begin
    DM := DimMap[i];
    if DM.Active then Continue;   { already loaded }
    if not DM.wasActive then Continue;
    if DM.IsDimension then
    begin
      if (IDims < MaxDimensions) and (iCells < maxCells) then
      begin
        x := iCells;
        if (DM.ValueCount > 0) then
          x := x * DM.ValueCount
        else
          x := x*LargeValueCount;
        if (x > MaxCells) then Continue;
        iCells := x;
        IDims := IDims + 1;
        DM.active := true;
      end;
    end
    else
    begin
      if (iSums < MaxSummaries) and (iCells < maxCells) then
      begin
        if (iSums > 0) then   { the first one is always precalculated }
        begin
          x := (iCells * (iSums+1)) div iSums;
          if (x > maxCells) then Continue;
          iCells := x;
        end;
        iSums := iSums + 1;
        DM.active := true;
      end;
    end;
  end;
  for i := DimMap.count-1 downto 0 do
  begin
    DM := DimMap[i];
    if DM.Active then Continue;   { already loaded }
    if (DM.ActiveFlag <> diAsNeeded) then Continue;
    if DM.IsDimension then
    begin
      if (IDims < MaxDimensions) and (iCells < maxCells) then
      begin
        x := iCells;
        if (DM.ValueCount > 0) then
          x := x * DM.ValueCount
        else
          x:= x*LargeValueCount;
        if (x > MaxCells) then Continue;
        iCells := x;
        IDims := IDims + 1;
        DM.active := true;
      end;
    end
    else
    begin
      if (iSums < MaxSummaries) and (iCells < maxCells) then
      begin
        if (iSums > 0) then    { the first one is always precalculated }
        begin
          x := (iCells * (iSums+1)) div iSums;
          if (x > maxCells) then Continue;
          iCells := x;
        end;
        iSums := iSums + 1;
        DM.active := true;
      end;
    end;
  end;
  { Now test to see if limits were met }
  { Enable derived summaries }
  for i := 0 to DimMap.count-1 do
  begin
    DM := DimMap[i];
    if (DM.dimensionType <> dimDimension) and (DM.derivedFrom >= 0) then
    begin
      DM.Active := DimMap.AverageFieldCheck(i, si, ci) and DimMap[si].active and DimMap[ci].active;
    end;
  end;
  { Only raise an exception if in Design Mode. }
  if (csDesigning in ComponentState) then
  begin
    if (iSums > MaxSummaries) then
      raise EDimensionMapError.CreateFMT(sMaxAllowedSums, [MaxSummaries]);
    if (iDims > MaxDimensions) then
      raise EDimensionMapError.CreateFMT(sMaxAllowedDims, [MaxDimensions]);
    if (MaxCells > 0) and (iCells > MaxCells) then
      raise EDimensionMapError.createFMT(sMaxAllowedCells, [iCells,maxCells]);
  end;
  if (iSums = 0) then
  begin
    for i := 0 to DimMap.count-1 do
    begin
      if DimMap[i].isSummary and (DimMap[i].ActiveFlag <> diInactive) then
        iSums := iSums + 1;
    end;
    if (iSums = 0) then
      raise EDimensionMapError.Create(sNoSumsAvailable)
    else
      raise EDimensionMapError.Create(sNoSumsCouldBeLoaded);
  end;
  if (iDims = 0) then
  begin
    for i := 0 to DimMap.count-1 do
    begin
      if DimMap[i].isDimension and (DimMap[i].ActiveFlag<>diInactive) then
        iDims := iDims + 1;
    end;
    if (iDims = 0) then
      raise EDimensionMapError.Create(sNoDimsAvailable)
    else
      raise EDimensionMapError.Create(sNoDimsCouldBeLoaded);
  end;
end;

function TCustomDataStore.CanDimBeClosed(iMapIndex: Integer): Boolean;
begin
  Result := true;
end;

function TCustomDataStore.CanSumBeClosed(iMapIndex: Integer): Boolean;
begin
  Result := true;
end;

procedure TCustomDataStore.Refresh(DimMap: TCubeDims; bForce: Boolean);	//pg
var
  BuildType: TBuildType;

  procedure HardRebuild;
  begin
    SetActive(False);
    SetActive(True);
  end;

begin
  BuildType := btNoRebuild;
  if not Assigned(DimMap) then
  begin
    HardRebuild;
    Exit;
  end;
  { Give the developer a chance to change the dimension map and/or the data set }
  DoOnRefresh(DimMap);
  { Set up the load states for the dimensions }
  SetLoadMap(DimMap, DimensionMap);
  { Check the DimensionMap to see if we need to rebuild or not }
  if CheckDimensionMap(DimMap, BuildType) or bForce then
  begin
    if bForce then BuildType := btHardRebuild;
    DimensionMap.Assign(DimMap);
    case BuildType of
      btSoftRebuild,
      btHardRebuild: HardRebuild;
      btNoRebuild:
      begin
        SetState(dcInactive);
        StateChanged;
        SetState(dcBrowseAllData);
      end;
    end;
    if (BuildType <> btHardRebuild) then StateChanged;
  end
  else
    DimensionMap.Assign(DimMap);
end;

procedure TCustomDataStore.CalcSubTotals;
begin
  FCache.CalcSubTotals;
end;

  { TBinTable }

type
  PFieldDescList = ^TFieldDescList;
  TFieldDescList = array[0..1023] of FLDDesc;

  TBinTable = class(TDBDataSet)
  private
    FTableName: TFileName;
    FTmpHandle: HDBICur;
    FTableLevel: Integer;
    FTableType: TTableType;
    FGroupBreak: Boolean;
    FDimensionMap: TCubeDims;
    FDBHandle: HDBIDB;
    function GetDriverTypeName(Buffer: PChar): PChar;
    function GetTableTypeName: PChar;
    procedure SetTableName(const Value: TFileName);
    procedure SetTableType(Value: TTableType);
    function GetTableLevel: Integer;
    procedure EncodeFieldDesc(var FieldDesc: FLDDesc; const Name: string; DataType: TFieldType; Size: Word);
    procedure HandleKeyViol;
  protected
    function CreateHandle: HDBICur; override;
    function GetCanModify: Boolean; override;
    function GetHandle: HDBICur;
  public
    procedure CleanUp;
    procedure Attach(ASource: TMultiDimDataLink);
    function CreateTempTable: HDBICur;
    procedure CreateIndexTable(Cache: TDataCache);
    procedure save(TabName: TFileName);
    procedure EmptyTable;
    procedure BinPost;
    function CheckKeyViol(Status: DBIResult): Boolean;
    function FillRecord(ASource: TDataSet): Boolean;
    function IsDBaseTable: Boolean;
    property TableName: TFileName read FTableName write SetTableName;
    property TableType: TTableType read FTableType write SetTableType default ttDefault;
    property TableLevel: Integer read GetTableLevel write FTableLevel;
    property TempHandle: HDBICur read GetHandle write FTmpHandle;
    property GroupBreak: Boolean read FGroupBreak write FGroupBreak default False;
    property DimensionMap: TCubeDims read FDimensionMap;
  end;

function GetIntProp(const Handle: Pointer; PropName: Integer): Integer;
var
  Length: Word;
  Value: Integer;
begin
  Value := 0;
  Check(DbiGetProp(HDBIObj(Handle), propName, @Value, SizeOf(Value), Length));
  Result := Value;
end;

var
  MXDBLocale: TLocale;

procedure TBinTable.CleanUp;
begin
  if Assigned(FDimensionMap) then FDimensionMap.Free;
end;

procedure TBinTable.Attach(ASource: TMultiDimDataLink);
var
  I, Cnt: Integer;
  OrigDimMap: TCubeDim;
  newDim: TCubeDim;

  function GetDimFromFieldName(FldName: string): TCubeDim;
  var
    I: Integer;
  begin
    result := nil;
    for I := 0 to Asource.FDataStore.FDimensionMap.Count-1 do
    begin
      if (Asource.FDataStore.FDimensionMap[I].FieldName = FldName) then
      begin
        Result := Asource.FDataStore.FDimensionMap[I];
        break;
      end;
    end;
  end;

begin
  Cnt := 0;
  { Force to the highest table level }
  TableLevel := 7;
  { Get the table descriptor from the source table }
  TableName  := 'TmpTab';  { Do not localize }
  { Reorder The original dimension map so that the active dimensions are ordered first }
  FDimensionMap  := TCubeDims.Create(self, TCubeDim);
  for I := 0 to ASource.DataSet.FieldCount - 1 do
  begin
    with Asource.DataSet.Fields[I] do
    begin
      OrigDimMap := GetDimFromFieldName(FieldName);
      if (OrigDimMap.active = True) and (OrigDimMap.IsDimension) then
      begin
        Inc(Cnt);
        if (Cnt > MaxBinDimensions) then
        begin
          FDimensionMap.Free;
          raise ECacheError.CreateFMT(sMaxAllowedDims, [MaxBinDimensions]);
        end;
        { Set up field types }
        FDimensionMap.Add;
        newDim := FDimensionMap[FDimensionMap.Count-1];
        newDim.Assign(OrigDimMap);
        if (FieldKind = fkData) or (FieldKind = fkCalculated) then
        begin
          if OrigDimMap.BinType = binSet then
            FieldDefs.Add(FieldName, OrigDimMap.FBinData.GetBinNameDataType,
                          OrigDimMap.FBinData.GetMaxBinNameSize, Required)
          else
            FieldDefs.Add(FieldName, DataType, Size, Required);
        end;
      end;
    end;
  end;
  { Scan sumnmaries }
  for I := 0 to ASource.DataSet.FieldCount - 1 do
  begin
    with Asource.DataSet.Fields[I] do
    begin
      OrigDimMap := GetDimFromFieldName(FieldName);
      if (OrigDimMap.active = True) and (OrigDimMap.IsSummary) then
      begin
        FDimensionMap.Add;
        newDim := FDimensionMap[FDimensionMap.Count-1];
        newDim.Assign(OrigDimMap);
        if (FieldKind = fkData) or (FieldKind = fkCalculated)  then
          FieldDefs.Add(FieldName, DataType, Size, Required);
      end;
    end;
  end;
  if (ASource.DataSet is TDBDataSet) then
    with TDBDataSet(ASource.DataSet) do
    begin
      if DataBase.IsSQLBased then
        FDBHandle := nil
      else
        FDBHandle := DataBase.Handle;
    end
  else
    FDBHandle := nil;
  { Create the table TDataSet }
  FTmpHandle := CreateTempTable;
  { Give us logical field types }
  Check(DbiSetProp(hDbiObj(FTmpHandle), curXLTMODE, Longint(xltFIELD)));
  { Set active to true. }
  Self.Active := True;
end;

function TBinTable.CreateTempTable: HDBICur;
var
  I: Integer;
  FieldDescs: PFLDDesc;
  DriverTypeName: DBINAME;
  TableDesc: CRTblDesc;
  LDName: DBIName;           
  LName: string;
  TempLocale, OldLocale: TLocale;
  SQLLName: DBIName;
  PSQLLName: PChar;
  Level: string;
  pOptDesc, pOrigDesc: pFLDDesc;
  pOrigData: pBYTE;

  function GetStandardLanguageDriver: string;
  var
    DriverName: string;
    Buffer: array[0..DBIMAXNAMELEN - 1] of Char;
  begin
    if not Database.IsSQLBased then
    begin
      DriverName := GetTableTypeName;
      if (DriverName = '') then
        if IsDBaseTable then
          DriverName := szDBASE
        else
          DriverName := szPARADOX;
      if (DbiGetLdName(PChar(DriverName), nil, Buffer) = 0) then
        Result := Buffer;
    end
    else
      Result := '';
  end;

begin
  FieldDescs := nil;
  pOrigDesc  := nil;
  pOrigData  := nil;
  { Fill the table descriptor }
  FillChar(TableDesc, SizeOf(TableDesc), 0);
  with TableDesc do
  begin
    SetDBFlag(dbfTable, True);
    try
      { Add the table names }
      OldLocale := Locale;
      if (MXDBLocale <> nil) then SetLocale(MXDBLocale);
      AnsiToNative(Locale, TableName, szTblName, SizeOf(szTblName) - 1);
      if (GetTableTypeName <> nil) then StrCopy(szTblType, GetTableTypeName);
      iFldCount := FieldDefs.Count;
      { Setup and add the field descriptors }
      FieldDescs := AllocMem(iFldCount * SizeOf(FLDDesc));
      TempLocale := nil;
      LName := '';
      if (Locale <> nil) then
        if (OsLdGetSymbName(Locale, @LDName) = 0) then LName := LDName;
      if (LName = '') then LName := GetStandardLanguageDriver;
      if (LName <> '') and (OsLdLoadBySymbName(PChar(LName), TempLocale) = 0) then
        SetLocale(TempLocale);
      try
        for I := 0 to FieldDefs.Count - 1 do
          with FieldDefs[I] do
          begin
            EncodeFieldDesc(PFieldDescList(FieldDescs)^[I], Name, DataType, Size);
            if Required then Inc(iValChkCount);
          end;
      finally
        if (TempLocale <> nil) then
        begin
          OsLdUnloadObj(TempLocale);
          SetLocale(OldLocale);
        end;
      end;
      pFldDesc := AllocMem(iFldCount * SizeOf(FLDDesc));
      PSQLLName := nil;
      if Database.IsSQLBased then
        if (DbiGetLdNameFromDB(DBHandle, nil, SQLLName) = 0) then
          PSQLLName := SQLLName;
      Check(DbiTranslateRecordStructure(nil, iFldCount, FieldDescs,
            GetDriverTypeName(DriverTypeName), PSQLLName, pFLDDesc, False));
      iValChkCount := 0;
      { Add the primary index }
      if Assigned(FDimensionMap) and (FDimensionMap.Count > 0) then
      begin
        iIdxCount := 1;
        pIdxDesc := AllocMem(iIdxCount * SizeOf(IDXDesc));
        pIdxDesc^.bPrimary := True;
        for I := 0 to FDimensionMap.Count-1 do
        begin
          if FDimensionMap[I].IsDimension then
          begin
            pIdxDesc.aiKeyFld[pIdxDesc.iFldsInKey] := FieldDefs[I].FieldNo;
            Inc(pIdxDesc.iFldsInKey);
          end;
        end;
      end;
      with TableDesc do
      begin
        iOptParams := 2;
        pOptDesc := AllocMem(iOptParams * sizeof(FLDDesc));
        pOrigDesc := pOptDesc;
        pOptData := AllocMem(Length(LName) + 2);
        pOrigData := pOptData;
        { Table level }
        Level := IntToStr(TableLevel);
        pOptDesc.iOffset := 0;
        pOptDesc.iLen := Length(Level) + 1;
        StrCopy(pOptDesc.szName, szCFGDRVLEVEL);
        StrPCopy(PChar(pOptData), Level);
        Inc(PChar(pOptData), Length(Level) + 1);
        Inc(pOptDesc);
        { language driver }
        pOptDesc.iOffset := Length(Level) + 1;
        pOptDesc.iLen := Length(Level) + 1 + Length(LName) + 1;
        StrCopy(pOptDesc.szName, szCFGDRVLANGDRIVER);
        StrPCopy(PChar(pOptData), LName);
        Inc(PChar(pOptData), Length(LName) + 1);
        pFldOptParams := pOrigDesc;
        pOptData := pOrigData;
      end;
      Check(DbiCreateTempTable(FDBHandle, TableDesc, Result));
    finally
      if (pFldDesc <> nil) then
        FreeMem(pFldDesc, iFldCount * SizeOf(FLDDesc));
      if (FieldDescs <> nil) then
        FreeMem(FieldDescs, iFldCount * SizeOf(FLDDesc));
      if (pIdxDesc <> nil) then
        FreeMem(pIdxDesc, iIdxCount * SizeOf(IDXDesc));
      FreeMem(pOrigDesc, 3 * sizeof(FLDDesc));
      FreeMem(pOrigData, 20);
      SetDBFlag(dbfTable, False);
    end;
  end;
end;

procedure TBinTable.CreateIndexTable(Cache: TDataCache);
var
  I: Integer;
  FieldName: string;
begin
  { Get the table descriptor from the source table }
  TableName  := 'IdxTab'; { Do not localize }
  TableLevel := 7;
  if FieldDefs.Count = 0 then
  begin
    FieldDefs.Add('Position', ftInteger, 0, False); { Do not localize }
    for I := 0 to Cache.DimensionCount - 1 do
    begin
      FieldName := Cache.GetDimensionName(I);
      FieldDefs.Add(FieldName, ftSmallint, 0, False);
    end;
    FieldDefs.Add('Offset', ftInteger, 0, False); { Do not localize }
    FieldDefs.Add('Sparse', ftBoolean, 0, False); { Do not localize }
    FieldDefs.Add(Cache.GetSummaryName(Cache.CurrentSummary), ftFloat, 0, False);
  end;
  { Create the table  TDataSet }
  FTmpHandle := CreateTempTable;
  { Give us logical field types }
  Check(DbiSetProp(hDbiObj(FTmpHandle), curXLTMODE, Longint(xltFIELD)));
  { Set active to true. }
  Self.Active := True;
end;

procedure TBinTable.Save(TabName: TFileName);
begin
  Check(DbiMakePermanent(FTmpHandle, PChar(TabName), True));
end;

function TBinTable.GetTableTypeName: PChar;
const
  Names: array[TTableType] of PChar = (szPARADOX, szPARADOX, szDBASE, szDBASE, szASCII);
var
  TblType: TTableType;
  Extension: string;
begin
  Result := nil;
  TblType := TableType;
  if not Database.IsSQLBased then
  begin
    if (TblType = ttDefault) then
    begin
      Extension := ExtractFileExt(FTableName);
      if (CompareText(Extension, '.DBF') = 0) then TblType := ttDBase;
      if (CompareText(Extension, '.TXT') = 0) then TblType := ttASCII;
    end;
    Result := Names[TblType];
  end;
  TableType := TblType;
end;

procedure TBinTable.EncodeFieldDesc(var FieldDesc: FLDDesc; const Name: string; DataType: TFieldType; Size: Word);
begin
  with FieldDesc do
  begin
    AnsiToNative(Locale, Name, szName, SizeOf(szName) - 1);
    iFldType := FldTypeMap[DataType];
    iSubType := FldSubTypeMap[DataType];
    case DataType of
      ftString,
      ftBytes,
      ftVarBytes,
      ftBlob,
      ftMemo,
      ftGraphic,
      ftFmtMemo,
      ftParadoxOle,
      ftDBaseOle,
      ftTypedBinary: iUnits1 := Size;
      ftBCD:
      begin
        iUnits1 := 32;
        iUnits2 := Size;
      end;
    end;
  end;
end;

function TBinTable.GetHandle: HDBICur;
begin
  Result := FTmpHandle;
end;

function TBinTable.CreateHandle: HDBICur;
begin
  if (FTableName = '') then DatabaseError(SNoTableName);
  Result := GetHandle;
end;

function TBinTable.GetTableLevel: Integer;
begin
  if (Handle <> nil) then
    Result := GetIntProp(Handle, curTABLELEVEL)
  else
    Result := FTableLevel;
end;

procedure TBinTable.EmptyTable;
var
  STableName: array[0..DBIMAXTBLNAMELEN - 1] of Char;
begin
  if Active then
  begin
    CheckBrowseMode;
    Check(DbiEmptyTable(DBHandle, Handle, nil, nil));
    ClearBuffers;
    DataEvent(deDataSetChange, 0);
  end
  else
  begin
    SetDBFlag(dbfTable, True);
    try
      Check(DbiEmptyTable(DBHandle, nil, AnsiToNative(DBLocale, TableName,
            STableName, SizeOf(STableName) - 1), GetTableTypeName));
    finally
      SetDBFlag(dbfTable, False);
    end;
  end;
end;

procedure TBinTable.SetTableName(const Value: TFileName);
begin
  CheckInactive;
  FTableName := Value;
  DataEvent(dePropertyChange, 0);
end;

procedure TBinTable.SetTableType(Value: TTableType);
begin
  CheckInactive;
  FTableType := Value;
end;

function TBinTable.IsDBaseTable: Boolean;
begin
  Result := (TableType = ttDBase) or
            (CompareText(ExtractFileExt(TableName), '.DBF') = 0);
end;

function TBinTable.GetDriverTypeName(Buffer: PChar): PChar;
var
  Length: Word;
begin
  Result := Buffer;
  Check(DbiGetProp(HDBIOBJ(DBHandle), dbDATABASETYPE, Buffer,
                   SizeOf(DBINAME), Length));
  if (StrIComp(Buffer, szCFGDBSTANDARD) = 0) then
  begin
    Result := GetTableTypeName;
    if (Result <> nil) then Result := StrCopy(Buffer, Result);
  end;
end;

function TBinTable.GetCanModify: Boolean;
begin
  Result := True;
end;

function TBinTable.FillRecord(ASource: TDataSet): Boolean;
var
  I, flds: Integer;
  Value: Variant;
  CubeDim: TCubeDim;

  function GetDimFromFieldName(FldName: string): TCubeDim;
  var
    I: Integer;
  begin
    result := nil;
    for I := 0 to FDimensionMap.Count-1 do
    begin
      if (FDimensionMap[I].FieldName = FldName) then
      begin
        Result := FDimensionMap[I];
        break;
      end;
    end;
  end;
  
begin
  Result := ASource.EOF;
  if (Result = True) then Exit;
  { Add a new record }
  Append;
  { Get the field values }
  flds := ASource.FieldCount;
  for I := 0 to flds-1 do
  begin
    { Get the value from the data set }
    Value := ASource.FieldValues[ASource.Fields[I].FieldName];
    CubeDim := GetDimFromFieldName(ASource.Fields[I].FieldName);
    if (CubeDim = nil) then Continue;
    if CubeDim.IsBinData then CubeDim.DoTransform(Value);
    FieldValues[ASource.Fields[I].FieldName] := Value;
  end;
  { Post the values to the bin table. }
  BinPost;
end;

procedure TBinTable.HandleKeyViol;
var
  ValSumRecord, ValDimRecord: Variant;
  DimNames: string;
  I, SumRecCnt: Integer;
begin
  if (FDimensionMap.DimensionCount > 1) then
    ValDimRecord := VarArrayCreate([0, FDimensionMap.DimensionCount-1], varVariant);
  ValSumRecord := VarArrayCreate([0, FDimensionMap.SummaryCount-1], varVariant);
  SumRecCnt := 0;
  for I := 0 to FDimensionMap.Count-1 do
  begin
    if FDimensionMap[I].IsDimension then
    begin
      DimNames := DimNames + Fields[I].FieldName + ';';
      if (FDimensionMap.DimensionCount > 1) then
        ValDimRecord[I] := FieldValues[Fields[I].FieldName]
      else
        ValDimRecord := FieldValues[Fields[I].FieldName];
    end
    else
    begin
      ValSumRecord[SumRecCnt] := FieldValues[Fields[I].FieldName];
      Inc(SumRecCnt);
    end;
  end;
  { Cancel changes }
  Cancel;
  First;
  {  Locate the duplicate record }
  Locate(DimNames, ValDimRecord, []);
  Edit;
  { Apply the summary }
  SumRecCnt := 0;
  for I := 0 to FDimensionMap.Count-1 do
    if FDimensionMap[I].IsSummary then
    begin
      FieldValues[Fields[I].FieldName] := FieldValues[Fields[I].FieldName] +
      ValSumRecord[SumRecCnt];
      Inc(SumRecCnt);
    end;
end;

procedure TBinTable.BinPost;
var
  Done: Boolean;
begin
  UpdateRecord;
  DataEvent(deCheckBrowseMode, 0);
  repeat
    UpdateCursorPos;
    if (State = dsEdit) then
      Done := CheckKeyViol(DbiModifyRecord(Handle, ActiveBuffer, True))
    else
      Done := CheckKeyViol(DbiInsertRecord(Handle, dbiNoLock, ActiveBuffer));
  until Done;
  inherited FreeFieldBuffers;
  SetState(dsBrowse);
  Resync([]);
end;

function TBinTable.CheckKeyViol(Status: DBIResult): Boolean;
begin
  Result := True;
  if (Status = DBIERR_KEYVIOL) then
  begin
    HandleKeyViol;
    Result := False;
  end
  else
    if (Status <> 0) then
      DbiError(Status);
end;

  { TMultiDimDataLink }

constructor TMultiDimDataLink.Create(AStore: TCustomDataStore);
begin
  inherited Create;
  FDataStore := AStore;
  FDataSource := nil;
end;

destructor TMultiDimDataLink.Destroy;
begin
  inherited Destroy;
end;

function DBCompareString(Var item1, item2): Integer;
begin
  Result := NativeCompareStrBuf(MXDBLocale, PChar(item1), PChar(item2), 0);
end;

procedure TMultiDimDataLink.DoUpdateCache;
var
  OldCursor: HCursor;
begin
  if FDataStore.ShowProgressDialog then
    OldCursor := GetCursor
  else
    OldCursor := SetCursor(LoadCursor(0, IDC_WAIT));
  try
    if FDataStore.ShowProgressDialog then
    begin
      ProgressDlg := TProgressDialog.Create(Application);
      try
        ProgressDlg.OnPerformBuild := UpdateCache;
        ProgressDlg.Caption := sBuildingDataStore;
        ProgressDlg.ShowModal;
        if (ProgressDlg.ExceptMessage <> '') then
          raise ECacheError.Create(ProgressDlg.ExceptMessage);  { reraise any exceptions that occured in the dlg }
      finally
        ProgressDlg.Free;
        ProgressDlg := nil;
      end;
    end
    else
      UpdateCache(Self);
  finally
    SetCursor(OldCursor);
  end;
end;

procedure TMultiDimDataLink.UpdateCache(Sender: TObject);
var
  i: Integer;
  Dim: TDimension;
  DimAllVals: TBuilderDim;
  DimAllList: TList;
  rString: string;
  bDataSetMatch: Boolean;
  bHaveBDE: Boolean;
  EAction: TErrorAction;

  procedure CleanUp;
  begin
    if Assigned(DimAllList) then
    begin
      while (DimAllList.Count > 0) do
      begin
        Dim := DimAllList.Last;
        DimAllList.Remove(Dim);
        Dim.Free;
      end;
    end;
    DimAllList.Free;
    DimAllList := nil;
  end;

  function SumsOrdered: Boolean;
  var
    I: Integer;
  begin
    Result := True;
    for I := 0 to FDataStore.FDimensionMap.Count-1 do
      if FDataStore.FDimensionMap[I].IsDimension then
        Result := False
      else
        Result := True;
  end;

begin
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('CacheVerification');
  {$ENDIF}
  { Set some initial state flags }
  FDataStore.DataCache.Success := False;
  bHaveBDE := True;
  { 1. Create and verify dimension map }
  if(FDataStore.DataSet is TDecisionQuery) then
    rString := SDecisionQueryError
  else if (FDataStore.DataSet is TQuery) then
    rString := SQueryError
  else
    rString := SDataSetError;

  case VerifyRTQuery(FDataStore.DataSet, FDataStore.DimensionMap, bDataSetMatch) of
    tqeOK           : ;
    tqeNoAggs       : raise EDimensionMapError.create(SNoAggs + ' ' + rString);
    tqeNotGrouped   : raise EDimensionMapError.create(SGroupsMissing + ' ' + rString);
    tqeNoDimensions : raise EDimensionMapError.create(SNoDims + ' ' + rString);
    tqeUnknownDims  : raise EDimensionMapError.create(sUnknownDims);
  else
    raise EDimensionMapError.create(rString);
  end;
  FDataStore.SetLoadMap(FDataStore.DimensionMap, nil);
  if (FDataStore.DimensionMap.ActiveDimensionCount > FDataStore.MaxDimensions) then
    raise EDimensionMapError.CreateFmt(sMaxAllowedDims, [FDataStore.MaxDimensions]);
  if (FDataStore.DimensionMap.ActiveSummaryCount > FDataStore.MaxSummaries) then
    raise EDimensionMapError.CreateFmt(sMaxAllowedSums, [FDataStore.MaxSummaries]);
  { Stop on empty data sets }
  if FDataStore.DataSet.RecordCount <= 1 then raise ECacheError.Create(sEmptyDataSet);
  { Determine if we must bin data. }
  { True : If any of the cube dims are inactive }
  { True : If the logical data set field mapping does }
  { not match the SQL field mapping or the physical structure of a table }
  if (FDataStore.BinData = False) then
  begin
    if FDataStore.BinMapHasBinData or (bDataSetMatch = False) then
      FDataStore.BinData := True;
  end;
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('CacheVerification');
  {$ENDIF}
  if (csDesigning in FDataStore.ComponentState) and
  (FDataStore.DesignState = dsNoData) then
    Exit;
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('CreateDimensionObjects');
  {$ENDIF}
  if DataSet is TBDEDataSet then
    MXDBLocale := TBDEDataSet(DataSet).Locale
  else
    MXDBLocale := nil;
  DimAllList := TList.Create;
  { 2. Initialize the dimension and summary objects TDataSet }
  UpdateDimensions(DimAllList);
  Assert(FDataStore.DimensionCount >= 1);
  Assert(FDataStore.SummaryCount > 0);
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('CreateDimensionObjects');
  {$ENDIF}
  if (csDesigning in FDataStore.ComponentState) and
  (FDataStore.DesignState = dsMetaData) then
  begin
    CleanUp;
    Exit;
  end;
  try
    { 3. Fill the dimension store with unique values and summary data }
    if not (FDataStore.DataSet is TBDEDataSet) then
      bHaveBDE := IsBDEAvailable;
    if (FDataStore.BinData) and (bHaveBDE) then
      FetchAndBinValues(DimAllList) { Bins values as it scans datasets, used with histograms, will be slower }
    else
      FetchValues(DimAllList);
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('SortAndCompressDimensions');
  {$ENDIF}
    { 4.  Sort and compress to unique values the dimension data members. }
    for i := 0 to FDataStore.DimensionCount-1 do
    begin
      Dim := FDataStore.DataCache.Dimensions[i];
      DimAllVals := DimAllList[i];
      if (MXDBLocale <> nil) and (Dim.IsString) then
        Dim.CompareProc := DBCompareString;
      try
        Dim.AssignSorted(DimAllVals, True);
      except
        on E: ELowCapacityError do
        begin
          EAction := eaFail;
          if not (csDesigning in FDataStore.ComponentState) and
            Assigned(FDataStore.FOnCapacityError) then FDataStore.FOnCapacityError(EAction);
          if (EAction = eaFail) then
          begin
            Cleanup;
            raise;
          end;
        end
        else
        begin
          FDataStore.DataCache.ErrorCode := 105;
          CleanUp;
          raise;
        end;
      end;
    end;
    if (csDesigning in FDataStore.ComponentState) and
    (FDataStore.DesignState = dsDimensionData) then
    begin
      CleanUp;
      exit;
    end;

  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('SortAndCompressDimensions');
  {$ENDIF}
  { 5. Create the summary index, precalculate totals if needed }
  CreateSummaryIndex(DimAllList);
  FDataStore.DataCache.Success := True;

  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.NumberOfValues := FDataStore.DataCache.IndexCount;
  {$ENDIF}

  finally
    { 6. cleanup }
    CleanUp;
  end;
end;

procedure TMultiDimDataLink.UpdateDimensions(DimAllList: TList);
var
  I: Integer;
  DimMap: TCubeDims;
  Map: TCubeDim;
  Fld: TField;
  DimAllVals: TBuilderDim;
  EAction: TErrorAction;

  procedure TypeError(Fld: TField);
  begin
    raise EUnsupportedTypeError.CreateFMT(sUnsupportedFieldType,
      [Fld.FieldName, FieldTypeNames[Fld.DataType]]);
  end;

  procedure AddDim;
  var
    Pos: Integer;
    fldType: TFieldType;
  begin
    Pos := 0;
    try
      if (Map.BinType = binSet) then
        fldType := Map.FBinData.GetBinNameDataType
      else
        fldType := Fld.DataType;
      Pos := AddDimension(Map, Fld);
      try
        DimAllVals := TBuilderDim.Create(DataSet.RecordCount, fldType);
      except
        on E: ELowCapacityError do
        begin
          EAction := eaFail;
          if not (csDesigning in FDataStore.ComponentState) and
          Assigned(FDataStore.FOnCapacityError) then
            FDataStore.FOnCapacityError(EAction);
          if (EAction = eaFail) then raise;
        end;
      end;
      DimAllVals.FValueList.CompareProc := DBCompareString;
      DimAllVals.FValueList.SortOrder := tsNone;
      DimAllVals.Position := Fld.Index;
      DimAllVals.FieldName := Fld.FieldName;
    except
      on EUnsupportedTypeError do TypeError(Fld);
      else
      begin
        FDataStore.DataCache.ErrorCode := 35;
        raise;
      end;
    end;
    { Sorted according to physical field order }
    DimAllList.Insert(Pos, DimAllVals);
  end;

  procedure AddSum;
  begin
    try
      AddSummary(Map, Fld);
    except
      on EUnsupportedTypeError do TypeError(Fld);
      else
      begin
        FDataStore.DataCache.ErrorCode := 36;

        raise;
      end;
    end;
  end;

begin
  Map := nil;
  DimMap := FDataStore.DimensionMap;
  { Scan the fields in the data set }
  for I := 0 to DataSet.FieldCount-1  do
  begin
    { Get the TField from the data set }
    Fld := DataSet.Fields[I];
    Map := DimMap[i];
    if (Map.active = True) then
    begin
      if Map.IsDimension then
      begin
        AddDim;
      end
      else
      begin
        AddSum;
      end;
    end;
  end;
  { Add derived summaries }
  for I := 0 to DimMap.Count-1 do
    if (DimMap[I].DerivedFrom >= 0) and DimMap[I].IsSummary and dimMap[i].active then
      AddSummary(DimMap[I], nil);
end;

procedure TMultiDimDataLink.FetchValues(DimAllList: TList);
var
  flds, mCnt, i: Integer;
  K: Integer;
  Summary: TSummary;
  DimAllVals: TBuilderDim;
  vNew: Variant;
  DimMap: TCubeDims;
  EAction: TErrorAction;

  function FromFieldPos(Value: Integer): TBuilderDim;
  var
    I: Integer;
    BDim: TBuilderDim;
  begin
    Result := nil;
    for I := 0 to DimAllList.Count-1 do
    begin
      BDim := DimAllList[i];
      if (BDim.Position = Value) then Result := BDim;
    end;
  end;
  
begin
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('FetchValues');
  {$ENDIF}
  if FDataStore.DataCache.PreCalculateTotals then
  begin
    Summary := FDataStore.DataCache.Summaries[FDataStore.CurrentSummary];
    for K := 0 to FDataStore.DimensionCount-1 do
    begin
      DimAllVals := DimAllList[K];
      DimAllVals.InitSummary(Summary.DataType);
    end;
  end;
  DimMap := FDataStore.DimensionMap;
  flds := DataSet.FieldCount;
  if Assigned(ProgressDlg) then
  begin
    ProgressDlg.Max := DataSet.RecordCount;
    ProgressDlg.Caption := sFetchValues;
  end;
  with DataSet do
  begin
    { Move to the first record in the data set }
    mCnt := 0;
    First;
    with FDataStore.DataCache do
    begin
      while not EOF do
      begin
        { Update the progress bar }
        if Assigned(ProgressDlg) then
        begin
          if (ProgressDlg.UpdateProgress = -1) then
            raise EUserCanceled.Create(sUserCanceled);
        end;
        { scan all the fields }
        for i := 0 to flds - 1 do
        begin
          { If its a dimension, then attempt to store the value }
          if (DimMap[i].active = True) then
          begin
            try
            { Get the value from the data set }
              vNew := FieldValues[Fields[i].FieldName];
            except
              ErrorCode := 115;
              raise;
            end;
            if DimMap[i].IsDimension then
            begin
              try
                { Get the cooresponding dimension for the field in the data set }
                DimAllVals := FromFieldPos(Fields[i].Index);
                { Assign the data set value to the dimension array }
                DimAllVals[mCnt] := vNew;
                { See if we are at a group break for the dimension }
                if PreCalculateTotals then
                begin
                  if DimAllVals.MatchLastVal(vNew) then
                    DimAllVals.GroupBreak := False
                  else
                    DimAllVals.GroupBreak := True;
                  DimAllVals.LastVal := vNew;
                end;
              except
                ErrorCode := 120;
                raise;
              end;
            end;
            if DimMap[i].IsSummary then
            begin
              try
                { Get the summary object based on the field position in the data set }
                Summary := SummaryFromPosition(Fields[i].Index);
                { Store the value in the summary object }
                Summary[mCnt] := vNew;
                { Bin vNew into each dimensions running summary }
                if PreCalculateTotals then
                begin
                  for K := 0 to DimensionCount-1 do
                  begin
                    DimAllVals := DimAllList[K];
                    DimAllVals.AddSummary(vNew);
                  end;
                end;
              except
                on E: ELowCapacityError do
                begin
                  EAction := eaFail;
                  if not (csDesigning in FDataStore.ComponentState) and
                  Assigned(FDataStore.FOnCapacityError) then
                    FDataStore.FOnCapacityError(EAction);
                  if (EAction = eaFail) then raise;
                end
                else
                begin
                  ErrorCode := 130;
                  raise;
                end;
              end;
            end;
          end;
        end;
        { Move to the next record }
        Inc(mCnt);
        Next;
      end;
    end;
  end;
  { Assign format strings }
  if FDataStore.FDimensionMap.IsDirty then UpdateFormatStrings;
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('FetchValues');
  {$ENDIF}
end;

procedure TMultiDimDataLink.FetchAndBinValues(DimAllList: TList);
var
  mCnt, I, k:   Integer;
  bGroupBreak: Boolean;
  Summary:    TSummary;
  DimAllVals: TBuilderDim;
  vNew:   Variant;
  BinTable: TBinTable;
  DimMap: TCubeDims;
  EAction: TErrorAction;

  function FromFieldPos(Value: Integer): TBuilderDim;
  var
    I: Integer;
    BDim: TBuilderDim;
  begin
    Result := nil;
    for I := 0 to DimAllList.Count-1 do
    begin
      BDim := DimAllList[i];
      if (BDim.Position = Value) then Result := BDim;
    end;
  end;

  function FromFieldName(Value: string): TBuilderDim;
  var
    J: Integer;
    BDim: TBuilderDim;    
  begin
    Result := nil;    
    for J := 0 to DimAllList.Count-1 do
    begin
      BDim := DimAllList[J];
      if (BDim.FieldName = Value) then Result := BDim;
    end;
  end;

  procedure CleanUp;
  begin
    BinTable.CleanUp;
    BinTable.Close;
    BinTable.Free;
  end;

begin
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('FetchAndBinValues');
  {$ENDIF}
  if FDataStore.DataCache.PreCalculateTotals then
  begin
    Summary := FDataStore.DataCache.Summaries[FDataStore.CurrentSummary];
    for K := 0 to FDataStore.DimensionCount-1 do
    begin
      DimAllVals := DimAllList[K];
      DimAllVals.InitSummary(Summary.DataType);
    end;
  end;
  BinTable := nil;
  if Assigned(ProgressDlg) then
  begin
    ProgressDlg.Max := DataSet.RecordCount;
    ProgressDlg.Caption := sBinningValues;
  end;
  with DataSet do
  begin
    { Move to the first record in the data set }
    First;
    mCnt := 0;
    { Create the bin table once }
    try
      BinTable := TBinTable.Create(Application);
      BinTable.Attach(Self);
    except
      FDataStore.DataCache.ErrorCode := 180;
      raise;
    end;
    { Put er in edit mode }
    BinTable.Edit;
    { If false, scans the whole table at once. }
    BinTable.GroupBreak := False;
    DimMap := BinTable.FDimensionMap;
    while not EOF do
    begin
      bGroupBreak := False;
      { Scan all the fields in the Data set }
      { assinging each to the bin table }
      { Turn Group breaks off if the data set is a table ... to scan and sort the whole table }
      while not bGroupBreak do
      begin
        try
          { Get the working dimension }
          bGroupBreak := BinTable.FillRecord(DataSet);
          { Move to the next record }
          Next;
        except
          FDataStore.DataCache.ErrorCode := 150;
          CleanUp;
          raise;
        end;
        { Update the progress bar }
        if Assigned(ProgressDlg) then
        begin
          if (ProgressDlg.UpdateProgress = -1) then
          begin
            CleanUp;
            raise EUserCanceled.Create(sUserCanceled);
          end;
        end;
      end;
      if Assigned(ProgressDlg)then
      begin
        ProgressDlg.Max := BinTable.RecordCount;
        ProgressDlg.Caption := sFetchValues;
      end;
      { Scan the bin table }
      BinTable.First;
      while not BinTable.EOF do
      begin
        { Update the progress bar }
        if Assigned(ProgressDlg) then
        begin
          if (ProgressDlg.UpdateProgress = -1) then
          begin
            CleanUp;
            raise EUserCanceled.Create(sUserCanceled);
          end;
        end;
        for I := 0 to BinTable.FieldCount-1 do
        begin
          with FDataStore.DataCache do
          begin
            if (DimMap[I].active = True) then
            begin
              { Get the value from the data set }
              vNew := BinTable.FieldValues[BinTable.Fields[i].FieldName];
              { If its a dimension, then attempt to store the value }
              if DimMap[I].IsDimension then
              begin
                try
                  { Get the dimensions }
                  DimAllVals := FromFieldName(BinTable.Fields[i].FieldName);
                  { Store the value in the builder dim }
                  DimAllVals[mCnt] := vNew;
                  { See if we are at a group break for the dimension }
                  if PreCalculateTotals then
                  begin
                    if DimAllVals.MatchLastVal(vNew) then
                      DimAllVals.GroupBreak := False
                    else
                      DimAllVals.GroupBreak := True;
                    DimAllVals.LastVal := vNew;
                  end;
                except
                  ErrorCode := 160;
                  CleanUp;
                  raise;
                end;
              end;
              { Store summary data. }
              if DimMap[I].IsSummary then
              begin
                try
                  { Get the summary object based on the field position in the data set }
                  Summary := SummaryFromFieldName(BinTable.Fields[i].FieldName);
                  { Store the value in the summary object }
                  Summary[mCnt] := vNew;
                  { Bin vNew into each dimensions running summary }
                  if PreCalculateTotals then
                  begin
                    for K := 0 to DimensionCount-1 do
                    begin
                      DimAllVals := DimAllList[K];
                      DimAllVals.AddSummary(vNew);
                    end;
                  end;
                except
                  on E: ELowCapacityError do
                  begin
                    EAction := eaFail;
                    if not (csDesigning in FDataStore.ComponentState) and
                    Assigned(FDataStore.FOnCapacityError) then
                      FDataStore.FOnCapacityError(EAction);
                    if (EAction = eaFail) then raise;
                  end
                  else
                  begin
                    ErrorCode := 170;
                    CleanUp;
                    raise;
                  end;
                end;
              end;
            end;
          end;
        end;
        BinTable.Next;
        Inc(mCnt);   { inc the count if one of the dims is on a group break }
      end;
      BinTable.EmptyTable;
    end;
    { Assign the binData back to the stores DimensionMap }
    for I := 0 to BinTable.DimensionMap.Count-1 do
    begin
      if (BinTable.DimensionMap[I].FieldName = FDataStore.FDimensionMap[I].FieldName) and
      Assigned(BinTable.DimensionMap[I].BinData) then
      begin
        FDataStore.FDimensionMap[I].BinData.Clear;
        FDataStore.FDimensionMap[I].BinData.Assign(TBinData(BinTable.DimensionMap[I].BinData));
      end;
    end;
    CleanUp;
  end;
  { Assign format strings }
  if FDataStore.FDimensionMap.IsDirty then UpdateFormatStrings;
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('FetchAndBinValues');
  {$ENDIF}
end;

procedure TMultiDimDataLink.CreateSummaryIndex(DimAllList: TList);
var
  i, k, iCnt, idx, sIdx, cRange: Integer;
  SumIndex, rangeCount: TSmallIntArray;
  Dim, DimAllVals: TDimension;
  Summary: TSummary;
  bSparsed, bGrpBreak: Boolean;
  SavedActiveSummary: Integer;
  EAction: TErrorAction;

  procedure CleanUp;
  begin
    rangeCount.Free;
    SumIndex.Free;
  end;

  procedure ShowProgress;
  begin
    if Assigned(ProgressDlg) then
    begin
      if (ProgressDlg.UpdateProgress = -1) then
      begin
        CleanUp;
        raise EUserCanceled.Create(sUserCanceled);
      end;
    end;
  end;

begin
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('CreateSummaryIndex');
  {$ENDIF}
  with FDataStore do
  begin
    try
      SumIndex  := TSmallIntArray.Create(DimensionCount, 0);
      { Create the range counter array }
      rangeCount := TSmallIntArray.Create(DimensionCount, 0);
    except
      FDataStore.DataCache.ErrorCode := 200;
      raise;
    end;
    { Determine the range for each dimension }
    cRange := 1;
    for i := DimensionCount-1 downto 0 do
    begin
      Dim := DataCache.Dimensions[i];
      Dim.Range := cRange;
      cRange := cRange * (Dim.MemberCount + 1);
    end;
    if (cRange < 0) then
    begin
      Cleanup;
      raise ECacheError.Create(sDataSetTooLarge);
    end;
    try
      EstimateCapacity(CRange);
      DataCache.FIndexMap.Capacity := cRange;
    except
      on E: ELowCapacityError do
      begin
        EAction := eaFail;
        if not (csDesigning in FDataStore.ComponentState) and
        Assigned(FDataStore.FOnCapacityError) then
          FDataStore.FOnCapacityError(EAction);
        if (EAction = eaFail) then
        begin
          CleanUp;
          raise;
        end;
      end
      else
      begin
        FDataStore.DataCache.ErrorCode := 210;
        CleanUp;
        raise;
      end;
    end;
    DataCache.FIndexMap.AutoSize := True;
    { Scan each summary }
    SavedActiveSummary := DataCache.CurrentSummary;
    for sIdx := 0 to DataCache.SummaryCount-1 do
    begin
      bGrpBreak := False;
      Summary := DataCache.Summaries[sIdx];
      { Derived summaries ignored }
      if Summary.IsDerived then Continue;
      { If we already have an index at this point, then }
      { assign FIndexInfo and FIndexMap and continue }
      Summary.FIndexMap := DataCache.FIndexMap;
      Summary.FIndexInfo := DataCache.FIndexInfo;
      if DataCache.HasIndex then Continue;
      if Assigned(ProgressDlg) then
      begin
        ProgressDlg.Max := CRange;
        ProgressDlg.Caption := Format(sCreatingIndexes, [Summary.FieldName]);
      end;
      DataCache.CurrentSummary := sIdx;
      try
        for i := 0 to DimensionCount-1 do
          SumIndex[i] := 0;
        for i := 0 to DimensionCount-1 do
          rangeCount[i] := 1; { Fill the rangeCount with 1's }
      except
        FDataStore.DataCache.ErrorCode := 220;
        CleanUp;
        raise;
      end;
      { Expand capacity of objects ... to save later reallocs } 
      try
        DataCache.FIndexInfo.Capacity := cRange;
      except
        on E: ELowCapacityError do
        begin
          EAction := eaFail;
          if not (csDesigning in FDataStore.ComponentState) and
          Assigned(FDataStore.FOnCapacityError) then
            FDataStore.FOnCapacityError(EAction);
          if (EAction = eaFail) then
          begin
            CleanUp;
            raise;
          end;
        end
        else
        begin
          FDataStore.DataCache.ErrorCode := 230;
          CleanUp;
          raise;
        end;
      end;
      { Generate the summary index }
      i := 0;
      iCnt := 0;
      while (iCnt < CRange-1) do
      begin
        { If a summary does not exist at subindex then add the summary index as sparsed }
        repeat
          bSparsed := False;
          for k := 0 to DimensionCount-1 do
          begin
            Dim := DataCache.Dimensions[k];
            DimAllVals := DimAllList[k];
            idx := Dim.IndexOf(DimAllVals[i]);
            if (SumIndex[k] <> idx) then
            begin
              bSparsed := True;
              break;
            end;
          end;
          try
            iCnt := DataCache.AddIndex(SumIndex, bSparsed);
          except
            on E: ELowCapacityError do
            begin
              EAction := eaFail;
              if not (csDesigning in FDataStore.ComponentState) and
              Assigned(FDataStore.FOnCapacityError) then
                FDataStore.FOnCapacityError(EAction);
              if (EAction = eaFail) then
              begin
                CleanUp;
                raise;
              end;
            end
            else
            begin
              FDataStore.DataCache.ErrorCode := 240;
              CleanUp;
              raise;
            end;
          end;
          if (DataCache.IncSummaryIndex(Summary, SumIndex, rangeCount, bGrpBreak) = False) then
          begin
            { Make sure that we are subtotaling on non-sparse data. }
            if DataCache.HasValidSubTotals(Summary, SumIndex) then
            begin
              repeat
                try
                  iCnt := DataCache.AddAggIndex(SumIndex, DimAllList);
                except
                  on E: ELowCapacityError do
                  begin
                    EAction := eaFail;
                    if not (csDesigning in FDataStore.ComponentState) and
                    Assigned(FDataStore.FOnCapacityError) then
                      FDataStore.FOnCapacityError(EAction);
                    if (EAction = eaFail) then
                    begin
                      CleanUp;
                      raise;
                    end;
                  end
                  else
                  begin
                    FDataStore.DataCache.ErrorCode := 250;
                    CleanUp;
                    raise;
                  end;
                end;
                ShowProgress;
              until DataCache.IncSummaryIndex(Summary, SumIndex, rangeCount, bGrpBreak);  { Break out when theres not a sub total }
            end;
          end;
          { Update the progress bar }
          ShowProgress;
          if (iCnt = CRange) then Break;
        until not bSparsed;
        if (i < Summary.MemberCount-1) then Inc(i);
      end;
      DataCache.HasIndex := True;
      Summary.FIndexMap := DataCache.FIndexMap;
    end;
    DataCache.CurrentSummary := SavedActiveSummary;
    CleanUp;
  end;
  {$IFDEF PROFILE}
  FDataStore.DataCache.FTicks.Ticks('CreateSummaryIndex');
  {$ENDIF}
end;

function TMultiDimDataLink.EstimateCapacity(RangeCnt: Integer): Integer;
var
  I, TotalSize, iIndexMap: Integer;
begin
  iIndexMap := 0;
  with FDataStore do
  begin
    for I := 0 to DimensionCount-1 do
    begin
      Inc(iIndexMap, sizeof(TSmallIntArray));
    end;
    TotalSize := (RangeCnt * iIndexMap);
    TotalSize := TotalSize + GetMemoryUsage;
  end;
  Result := TotalSize;
  if (Result < 0) or (Result > FDataStore.Capacity) then
    raise ELowCapacityError.Create(sLowCapacityError);
end;

function TMultiDimDataLink.AddDimension(DimMap: TCubeDim; Fld: TField): Integer;
var
  Dim: TDimension;
  fldType: TFieldType;
begin
  if (DimMap.BinType = binSet) then
    fldType := DimMap.FBinData.GetBinNameDataType
  else
    fldType := Fld.DataType;
  Dim := TDimension.Create(1, fldType);
  { Set info from TCubeDim, user configurable settings }
  Dim.SetFlag(DimMap.DimensionType);
  { Set info from the TField object }
  Dim.Position := Fld.Index;
  Dim.FieldName := Fld.FieldName;
  Dim.FieldDefinition.Width := Fld.DisplayWidth;
  Dim.FieldDefinition.FieldType := fldType;
  Dim.FieldDefinition.Precision := GetPrecision(fld);
  Dim.FieldDefinition.FieldNo := Fld.FieldNo;
  { Get any pre-existing display formats }
  if Assigned(DimMap) and (DimMap.Format <> '') then
    Dim.FieldDefinition.FormatString := DimMap.Format
  else
    Dim.FieldDefinition.FormatString := GetDisplayFormat(Fld);
  Result := FDataStore.DataCache.AppendDimension(Dim);
end;

procedure TMultiDimDataLink.AddSummary(DimMap: TCubeDim; Fld: TField);
var
  Summary, derivedSummary: TSummary;
  derivedIdx: Integer;
begin
  { Block string types }
  if (Assigned(Fld)) and (Fld.DataType = ftString) then
    raise EUnsupportedTypeError.Create(sStringTypeNoSupported);
  if (DimMap.DerivedFrom < 0) then
    Summary := TSummary.Create(DataSet.RecordCount, Fld.DataType)
  else
    Summary := TSummary.Create(1, ftFloat);
  { Set info from TCubeDim, user configurable settings }
  Summary.SetFlag(DimMap.DimensionType);
  if (DimMap.DerivedFrom < 0) then
  begin
    { Set info from Tfield }
    Summary.Position := Fld.Index;
    Summary.FieldName := Fld.FieldName;
    Summary.CubeDimIndex := DimMap.Index;
    Summary.FSumMethod := FDataStore.DataCache.GetBaseSummary;
    { Get formatting info }
    Summary.FieldDefinition.Width := Fld.DisplayWidth;
    Summary.FieldDefinition.FieldType := Fld.DataType;
    Summary.FieldDefinition.Precision := GetPrecision(fld);
    Summary.FieldDefinition.FieldNo := Fld.FieldNo;
    if (DimMap.Format <> '') then
      Summary.FieldDefinition.FormatString := DimMap.Format
    else
      Summary.FieldDefinition.FormatString := GetDisplayFormat(Fld);
  end
  else
  begin
    { Define the agg fields, if we can not then raise error }
    if not Summary.SetAggregator(DimMap.BaseName, FDataStore.FDimensionMap, DimMap.DimensionType, derivedIdx) then
    begin
      Summary.Free;
      raise ECacheError.Create(sCreateDerivedSummaryError);
    end;
    Summary.Position := -1;  { Signifies its a derived summary }
    Summary.Name := DimMap.FieldName;
    Summary.FieldName := DimMap.BaseName;
    Summary.CubeDimIndex := DimMap.Index;
    { Get formatting info from the derived field }
    derivedSummary := FDataStore.DataCache.SummaryFromCubeDimIndex(derivedIdx);
    Summary.FieldDefinition.Width := derivedSummary.FieldDefinition.Width;
    Summary.FieldDefinition.FieldType := derivedSummary.FieldDefinition.FieldType;
    Summary.FieldDefinition.Precision := derivedSummary.FieldDefinition.Precision;
    Summary.FieldDefinition.FormatString := derivedSummary.FieldDefinition.FormatString;
    Summary.FSumMethod := FDataStore.DataCache.GetAggSummary;
  end;
  FDataStore.DataCache.AppendSummary(Summary);
end;

procedure TMultiDimDataLink.UpdateFormatStrings;
var
  I: Integer;
  Dim: TDimension;
begin
  with FDataStore do
  begin
    for I := 0 to DimensionMap.Count-1 do
    begin
      if DimensionMap[I].IsDimension then
      begin
        Dim := FDataStore.DataCache.DimensionFromFieldName(DataSet.Fields[I].FieldName);
        if (Dim = nil) then Continue;
        if (DimensionMap[I].Format <> '') then
          Dim.FieldDefinition.FormatString := DimensionMap[I].Format;
        if DimensionMap[I].IsBinData then
          Dim.FieldDefinition.FormatString := DimensionMap[I].FBinFormat;
      end;
    end;
  end;
end;

{
 ActiveChanged

 Synopsis :
   Called from the data set whenever the data sets Active property gets changed, that
   includes at form startup

 Parameters :

 Return value :
}

procedure TMultiDimDataLink.ActiveChanged;
begin
  FDataStore.SetActive(Self.Active);
end;

{
 LayoutChanged

 Synopsis :
    Called from the data set whenever a column changes. Rebuild the cube.

 Parameters :

 Return value :
}
procedure TMultiDimDataLink.LayoutChanged;
begin
end;

  { TDataCache }

constructor TDataCache.Create;
begin
  inherited Create;
  FDimensions := nil;
  FSummaryData := nil;
  FActiveSummary := 0;
  Include(FCalcTotals, ctNone);
  FAggProc := CalcTotals1;
end;

destructor TDataCache.Destroy;
begin
  FreeCache;
  inherited Destroy;
end;

procedure TDataCache.Init;
begin
  {$IFDEF PROFILE}
  FTicks := TTicks.Create(FProfileLogFile);
  {$ENDIF}
  ErrorCode := 0;
  if not Assigned(FDimensions) then FDimensions := TList.Create;
  if not Assigned(FSummaryData) then FSummaryData := TList.Create;
  if not Assigned(FIndexMap) then FIndexMap := TIndexArray.Create;
  if not Assigned(FIndexInfo) then FIndexInfo := TIndexInfo.Create;
end;

procedure TDataCache.FreeCache;
var
  Dim: TDimension;
  Summary: TSummary;
begin
  {$IFDEF PROFILE}
  if Assigned(FTicks) then FTicks.Ticks('FreeCache');
  {$ENDIF}
  if Assigned(FDimensions) then
  begin
    while (FDimensions.Count > 0) do
    begin
      Dim := FDimensions.Last;
      FDimensions.Remove(Dim);
      Dim.Free;
    end;
    FDimensions.Free;
    FDimensions := nil;
  end;
  if Assigned(FSummaryData) then
  begin
    while (FSummaryData.Count > 0) do
    begin
      Summary := FSummaryData.Last;
      FSummaryData.Remove(Summary);
      Summary.Free;
    end;
    FSummaryData.Free;
    FSummaryData := nil;
  end;
  if Assigned(FIndexMap) then
  begin
    FIndexMap.Free;
    FIndexMap := nil;
    HasIndex := False;
  end;
  if Assigned(FIndexInfo) then
  begin
    FIndexInfo.Free;
    FIndexInfo := nil;
  end;
  FActiveSummary := 0;
  {$IFDEF PROFILE}
  if Assigned(FTicks) then FTicks.Ticks('FreeCache');
  {$ENDIF}
  {$IFDEF PROFILE}
  if Assigned(FTicks) then
  begin
    FTicks.Free;
    FTicks := nil;
  end;
  {$ENDIF}
end;

function TDataCache.GetDimensionCount: Integer;
begin
  if Assigned(FDimensions) then
    Result := FDimensions.Count
  else
    Result := 0;
end;

function TDataCache.GetSummaryCount: Integer;
begin
  if Assigned(FSummaryData) then
    Result := FSummaryData.Count
  else
    Result := 0;
end;

function TDataCache.GetDimension(Index: Integer): TDimension;
begin
  if Assigned(FDimensions) then
    Result := FDimensions[Index]
  else
    Result := nil;
end;

procedure TDataCache.SetDimension(Index: Integer; Value: TDimension);
begin
  FDimensions.Insert(Index, Value);
end;

function TDataCache.GetSummary(Index: Integer): TSummary;
begin
  if Assigned(FSummaryData) then
    Result := FSummaryData[Index]
  else
    Result := nil;
end;

function TDataCache.AppendDimension(Value: TDimension): Integer;
var
  I: Integer;
begin
  Result := -1;
  { Dimensions must be sorted by the FieldNo in the physical table }
  for I := 0 to FDimensions.Count-1 do
  begin
    if (Value.Position > TDimension(FDimensions[I]).Position) then
    begin
      Continue;
    end
    else if (Value.Position < TDimension(FDimensions[I]).Position) then
    begin
      Result := FDimensions.Add(Value);
      FDimensions.Exchange(Result, I);
      Result := I;
      break;
    end;
  end;
  if (Result = -1) then Result := FDimensions.Add(Value);
end;

function TDataCache.AppendSummary(Value: TSummary): Integer;
var
  I: Integer;
begin
  Result := -1;
  if (Value.Position = -1) then
  begin
    Result := FSummaryData.Add(Value);
    Exit;
  end;
  { summaries must be sorted by the FieldNo in the physical table }
  for I := 0 to FSummaryData.Count-1 do
  begin
    if (Value.Position > TDimension(FSummaryData[I]).Position) then
    begin
      Continue;
    end
    else if (Value.Position < TDimension(FSummaryData[I]).Position) then
    begin
      Result := FSummaryData.Add(Value);
      FSummaryData.Exchange(Result, I);
      Result := I;
      break;
    end;
  end;
  if (Result = -1) then Result := FSummaryData.Add(Value);
end;

function TDataCache.IsDimension(Position: Integer): Boolean;
var
  i: Integer;
  Dim: TDimension;
  foundIt: Boolean;
begin
  foundIt := False;
  for i := 0 to FDimensions.Count-1 do
  begin
    Dim := GetDimension(i);
    if (Dim.Position = Position) then foundIt := True;
  end;
  Result := foundIt;
end;

function TDataCache.IsSummary(Position: Integer): Boolean;
var
  i: Integer;
  Summary: TSummary;
  foundIt: Boolean;
begin
  foundIt := False;
  for i := 0 to FSummaryData.Count-1 do
  begin
    Summary := GetSummary(i);
    if (Summary.Position = Position) then foundIt := True;
  end;
  Result := foundIt;
end;

function TDataCache.SummaryFromPosition(Position: Integer): TSummary;
var
  i: Integer;
  Summary: TSummary;
begin
  Result := nil;
  for i := 0 to FSummaryData.Count-1 do
  begin
    Summary := GetSummary(i);
    if (Summary.Position = Position) then Result := Summary;
  end;
end;

function TDataCache.SummaryFromFieldName(FldName: string): TSummary;
var
  i: Integer;
  Summary: TSummary;
begin
  Result := nil;
  for i := 0 to FSummaryData.Count-1 do
  begin
    Summary := GetSummary(i);
    if (Summary.FieldName = FldName) then Result := Summary;
  end;
end;

function TDataCache.SummaryFromCubeDimIndex(Index: Integer): TSummary;
var
  i: Integer;
  Summary: TSummary;
begin
  Result := nil;
  for i := 0 to FSummaryData.Count-1 do
  begin
    Summary := GetSummary(i);
    if (Summary.CubeDimIndex = Index) then Result := Summary;
  end;
end;

function TDataCache.GetSummaryName(ISum: Integer): String;
var
  Summary: TSummary;
begin
  if Assigned(FSummaryData) then
  begin
    Summary := FSummaryData[ISum];
    Result := Summary.Name;
  end
  else
    Result := '';
end;

function TDataCache.GetDimensionName(DimIndex: Integer): String;
var
  Dim: TDimension;
begin
  if Assigned(FDimensions) then
  begin
    Dim := FDimensions[DimIndex];
    Result := Dim.DimensionName;
  end
  else
    Result := '';
end;

function TDataCache.GetDimensionMember(DimIndex, MemberIndex: Integer): String;
var
  Dim: TDimension;
  V: Variant;
begin
  Result := '';
  if Assigned(FDimensions) then
  begin
    Dim := FDimensions[DimIndex];
    if Dim.IsBlank(MemberIndex) then Exit;
    V := Dim[MemberIndex];
    Result := V;
    if (VarType(V) <> varString) then
      Result := Dim.FieldDefinition.FormatVariantToStr(V);
  end;
end;

function TDataCache.GetDimensionMemberAsVariant(DimIndex, MemberIndex: Integer): Variant;
var
  Dim: TDimension;
  V: Variant;
begin
  if Assigned(FDimensions) then
  begin
    Dim := FDimensions[DimIndex];
    if Dim.IsBlank(MemberIndex) then Exit;
    V := Dim[MemberIndex];
    if (VarType(V) <> varString) then
      Dim.FieldDefinition.FormatVariantToStr(V);
  end;
  Result := V;
end;

function TDataCache.GetDimensionMemberCount(DimIndex: Integer): Integer;
var
  Dim: TDimension;
begin
  if Assigned(FDimensions) then
  begin
    Dim := FDimensions[DimIndex];
    Result := Dim.MemberCount;
  end
  else
    Result := 0;
end;

function TDataCache.HasSubTotals(SumIndex: TSmallIntArray): Boolean;
var
  i: Integer;
begin
  Result := False;
  for i := 0 to SumIndex.Count-1 do
  begin
    if (SumIndex[i] = SubTotal) then
    begin
      Result := True;
      break;
    end;
  end;
end;

function TDataCache.HasValidSubTotals(Summary: TSummary ; SumIndex: TSmallIntArray): Boolean;
var
  i, j, iCount: Integer;
  Dim: TDimension;
begin
  Result := False;
  for i := 0 to SumIndex.Count-1 do
  begin
    if (SumIndex[i] = SubTotal) then
    begin
      Dim := Dimensions[i];
      iCount := (IndexCount-1) - (Dim.Range * (Dim.MemberCount-1));
      if (iCount < 0) then iCount := 0;
      for j := Summary.FIndexInfo.Count-1 downto iCount do
      begin
        { Exit on the first non-sparsed index }
        if not Summary.FIndexInfo.IsSparse(j) then
        begin
          Result := True;
          Exit;
        end;
      end;
    end;
  end;
end;

procedure TDataCache.GetScope(var OffsetIdx, AggIdx, AggRange: Integer; SumIndex: TSmallIntArray);
var
  i, lastDim, AggCnt: Integer;
  Dim: TDimension;
  bContigousIdx, bIdx: Boolean;
begin
  AggCnt := 0;
  AggRange := 0;
  AggIdx := 1;    { Used by agg indexes }
  OffsetIdx := 0;    { Used by non-agg indexes }
  bContigousIdx := False;
  bIdx := True;
  lastDim := DimensionCount-1;
  for i := lastDim downto 0 do
  begin
    Dim := Dimensions[i];
    if (SumIndex[i] <> SubTotal) then
    begin
      bIdx := False;
      AggIdx := AggIdx + (Dim.Range * SumIndex[i]);
      OffsetIdx := OffsetIdx + (Dim.Range * SumIndex[i]);
    end
    else
    begin
      Inc(AggCnt);
      if (bIdx = False) then
        bContigousIdx := False
      else
        bContigousIdx := True;
      if (i > 0) then AggRange := Dimensions[i-1].Range-1;
      if (i = lastDim) then
        AggIdx := AggIdx * (Dim.MemberCount + 1)
      else
        AggIdx := AggIdx + (Dim.Range * Dim.MemberCount);
    end;
  end;
  if (AggCnt > 0) then
  begin
    OffsetIdx := -1;
    Dec(AggIdx);
    if (bContigousIdx and (AggCnt <> DimensionCount)) then
      FAggProc := CalcTotals2
    else
      FAggProc := CalcTotals1;
  end;
end;

function TDataCache.IncSummaryIndex(Summary: TSummary; SumIndex, rangeCount: TSmallIntArray; var bGroupBreak: Boolean): Boolean;
var
  Dim: TDimension;
  dmIdx, sumLimit,
  i, range: Integer;
begin
  bGroupBreak := False;
  { Scan the summary index, from the dimension with the most detail to the dimension with the least }
  sumLimit := SumIndex.Count-1;
  for i := sumLimit downto 0 do
  begin
    Dim := FDimensions[i];
    { Get the index to the dimensions data member }
    dmIdx := SumIndex[i];
    { Get the range (group) where all data members are the same }
    range := Dim.Range;
    { Try incrementing the index }
    if (rangeCount[i] >= range) or (range = 1) then
    begin
      bGroupBreak := True;
      Inc(dmIdx);
      rangeCount[i] := 1;
      if (range = 1) then
      begin
        if dmIdx >= Dim.MemberCount then dmIdx := SubTotal;
      end
      else
      begin
        if (dmIdx >= Dim.MemberCount) then dmIdx := SubTotal;
      end;
    end
    else
      rangeCount[i] := Succ(rangeCount[i]);
    SumIndex[i] := dmIdx;
  end;
  Result := not HasSubTotals(SumIndex);
end;

function TDataCache.GetAggSummary(SumIndex: TSmallIntArray; Summary: TSummary; var Value: Variant): Boolean;
var
  sum1, sum2: TSummary;
  val1, val2: Variant;
begin
  { For each field, get the summary value }
  sum1 := SummaryFromCubeDimIndex(Summary.AggDefinition.FSummaryIdx[0]);
  Result := GetBaseSummary(SumIndex, sum1, val1);
  if (Result = False) then Exit;
  { For each field, get the summary value }
  sum2 := SummaryFromCubeDimIndex(Summary.AggDefinition.FSummaryIdx[1]);
  Result := GetBaseSummary(SumIndex, sum2, val2);
  if (Result = False) then Exit;
  Value := Summary.AggDefinition.AggProc(val1, val2);
end;

function TDataCache.GetBaseSummary(SumIndex: TSmallIntArray; Summary: TSummary; var Value: Variant): Boolean;
var
  offsetIndex, aggIndex, iOffSet, aggRange: Integer;
begin
  Result := False;
  GetScope(offsetIndex, aggIndex, aggRange, SumIndex);
  if (offsetIndex = SubTotal) then
    Result := FAggProc(aggIndex, aggRange, Summary, SumIndex, Value)
  else
  begin
    iOffset := Summary.FIndexInfo.FOffset[offsetIndex];
    if not Summary.FIndexInfo.IsSparse(offsetIndex) then
    begin
      Value := Summary[iOffSet];
      Result := True;
    end;
  end;
end;

function TDataCache.GetSummaryAsString(SumIndex: TSmallIntArray): String;
var
  Summary: TSummary;
  V: Variant;
  bValue: Boolean;
begin
  {$IFDEF PROFILE}
  FTicks.TicksSmallIntArray('GetSummaryAsString', SumIndex);
  {$ENDIF}
  Result := '';
  if not Assigned(FSummaryData) then Exit;
  Summary := FSummaryData[CurrentSummary];
  bValue := Summary.SumMethod(SumIndex, Summary, V);
  if bValue then Result := Summary.FieldDefinition.FormatVariantToStr(V);
  {$IFDEF PROFILE}
  FTicks.TicksSmallIntArray('GetSummaryAsString', SumIndex);
  {$ENDIF}
end;

function TDataCache.GetSummaryAsVariant(SumIndex: TSmallIntArray): Variant;
var
  Summary: TSummary;
  V: Variant;
  bValue: Boolean;
begin
  if not Assigned(FSummaryData) then Exit;
  Summary := FSummaryData[CurrentSummary];
  Result := VarAsType(0, Summary.DataType);
  bValue := Summary.SumMethod(SumIndex, Summary, V);
  if bValue then Result := V;
end;

function TDataCache.IsIndexSparse(SumIndex: TSmallIntArray): Boolean;
var
  Summary: TSummary;
  V: Variant;
  bValue: Boolean;
begin
  Summary := FSummaryData[CurrentSummary];
  bValue := Summary.SumMethod(SumIndex, Summary, V);
  Result := not bValue;
end;
{
 GetDomain

 Synopsis :
 GetDomain is called once for Rows and Columns.

 Parameters :
            DimensionIds [In] The array of dimension ID's
            Coord     [In]
            ATotals   [In] Turn On/Off the sum of rows or columns
            Domain    [Out] The lookup array used by by the client

 Return value : The # of columns or rows Contained in the slice
}
function TDataCache.GetDomain(DimensionIDs: TIntArray; nDims: Integer; ATotals: Boolean; Domain: TTwoDimArray): Integer;
var
  I,
  Index,                      { A row or column # depending on the context }
  DimID,                      { The dimension ID }
  IDim,                       { The row/col dimension index, 0 is the first dim, 1 is the second ... }
  DMember,                    { The dimension member }
  LastDMember,                { The number for the last dimension member }
  MaxDim,
  Range: Integer;
  bSparse, bNewIndex: Boolean;
  Dim: TDimension;
  SumIndex: TSmallIntArray;
  savedCursor: TCursor;

  procedure InitIndex;
  var
    j: Integer;
  begin
    SumIndex := TSmallIntArray.Create(DimensionCount, 0);
    for j:= 0 to DimensionCount-1 do
      SumIndex[j] := SubTotal;
  end;

  function GetRange: Integer;
  var
    cRange, K: Integer;
    DimR: TDimension;
  begin
    { Determine the range for each dimension }
    cRange := 1;
    for K := DimensionIDs.Count-1 downto 0 do
    begin
      DimR := FDimensions[DimensionIds[K]];
      cRange := cRange * (DimR.MemberCount + 1);
    end;
    Result := CRange;
  end;

begin
  Index := 0;
  savedCursor := 0;
  {$IFDEF PROFILE}
  FTicks.TicksIntArray('BuildLookups', DimensionIDs);
  {$ENDIF}
  if (DimensionIDs.Count > 0) then
  begin
    try
      savedCursor := screen.Cursor;
      Screen.Cursor := crHourglass;
      { Set the size of the lookup }
      Assert(Assigned(Domain));
      Range := GetRange;
      Domain.SetSize(DimensionIds.Count, Range);
      { Get the ID for the dimension from a row or col array }
      IDim := 0;
      DimID := DimensionIds[IDim];       { Get the first dimension ID }
      { Get the dimension range, from 0 to n.Count }
      Dim := FDimensions[DimID];
      DMember := 0;
      LastDMember := Dim.MemberCount;
      MaxDim := DimensionIDs.Count - 1;  { The dimension count for this row or column }
      bNewIndex := False;
      bSparse  := False;
      { Check for summaries with all blank values }
      if Sparsing then Sparsing := not IsBlankSummary;
      if Sparsing then InitIndex;
      repeat
      { Scan all the members for the dimension, from 0 to n.Count-1 }
        while (DMember < LastDMember) do
        begin
          if Sparsing then
          begin
            { Assign a data point to the active dimension. }
            SumIndex[DimID] := DMember;
            bSparse := IsIndexSparse(SumIndex);
          end;
          { If found a non sparsed value then assign the member to the lookup }
          if not bSparse then
          begin
            if bNewIndex then
            begin
              bNewIndex := False;
              Inc(Index);
              for I:= 0 to IDim-1 do
                Domain[I,Index] := Domain[I,Index-1];
            end;
            Domain[IDim,Index] := DMember;
          end;
          { Move to a new dimension or data member }
          if (IDim < MaxDim) then
          begin
            { Increment to the next dimension, and get its member range }
            if not bSparse then
            begin
              Inc(IDim);
              DimID := DimensionIds[IDim];
              Dim := FDimensions[DimID];
              DMember := 0;
              LastDMember := Dim.MemberCount;
            end
            else
            begin
              Inc(DMember);
              Continue;
            end;
          end
          else
          begin
           { Increment to the next dimension member }
            Inc(DMember);
            if not bSparse then bNewIndex := True;
          end;
        end;  { scaning the dimension members }
        { Assign sub-totals }
        if Sparsing then SumIndex[DimID] := SubTotal;
        if ATotals then
        begin
          Inc(Index);
          for I := 0 to IDim-1 do
            Domain[I,Index] := Domain[I,Index-1];
          for I := IDim to MaxDim do
            Domain[I,Index] := SubTotal;
        end;
        if (IDim = 0) then break;
        { move to the previous dimension }
        Dec(IDim);
        DimID := DimensionIDs[IDim];
        Dim := FDimensions[DimID];
        LastDMember := Dim.MemberCount;
        { Get the current member for this dim }
        DMember := Domain[IDim,Index];
        Inc(DMember);
        bNewIndex := True;
      until False;
    finally
      if Sparsing and (Assigned(SumIndex)) then SumIndex.Free;
      Screen.Cursor := savedCursor;
    end;
  end;
  Inc(Index);
  Result := Index;
  {$IFDEF PROFILE}
  FTicks.TicksIntArray('BuildLookups', DimensionIDs);
  {$ENDIF}
end;

procedure TDataCache.SetActiveSummary(Index: Integer);
var
  Sum: TSummary;
begin
  if (Index <> FActiveSummary) then
  begin
    Assert(Index <= SummaryCount ,'Error in summary selection');  { Do not localize }
    { Clear subtotals }
    Sum := FSummaryData[FActiveSummary];
    Sum.ClearTotals;
    FActiveSummary := Index;
    ClearIndexInfo;
  end;
end;

function CalcThreadProc(Cache: TDataCache): Integer;
var
  Summary: TSummary;
  SumIndex: TSmallIntArray;
  Cnt, I: Integer;
  V: Variant;
begin
  Result := 1;
  try
    Summary := Cache.FSummaryData[Cache.CurrentSummary];
    Summary.FIndexInfo.AddAggs := True;
    Cnt := Cache.FIndexMap.Count;
    for I := 0 to Cnt-1 do
    begin
      // Get the index value for the dimension
      SumIndex := Cache.FIndexMap[I];
      Summary.SumMethod(SumIndex, Summary, V);
    end;
    Summary.FIndexInfo.AddAggs := False;
  finally
    EndThread(Result);
  end;
end;

procedure TDataCache.CalcSubTotals;
var
  Handle, ThreadID: DWORD;
begin
  Handle := BeginThread(nil, 0, @CalcThreadProc, Pointer(Self), 0, ThreadID);
  if (Handle <> 0) then CloseHandle(Handle);
end;

procedure TDataCache.CreateTable(Const Filename: String);
var
  I,k, Cnt: Integer;
  tbl: TBinTable;
  Summary: TSummary;
  SumIndex: TSmallIntArray;
  FieldName: string;
  Value: Variant;
begin
  tbl := nil;
  try
    tbl := TBinTable.Create(Application);
    tbl.CreateIndexTable(Self);
    tbl.Save(Filename);
    tbl.Edit;
    Summary := FSummaryData[CurrentSummary];
    Cnt := FIndexMap.Count;
    for I := 0 to Cnt-1 do
    begin
      tbl.Append;
      { Get the position }
      tbl.FieldValues['Position'] := I;  { Do not localize }
      { Get the index value for the dimension }
      SumIndex := FIndexMap[I];
      for K := 0 to DimensionCount-1 do
      begin
        FieldName := GetDimensionName(K);
        Value := SumIndex[K];
        tbl.FieldValues[FieldName] := Value;
      end;
      { Get the sparse flag }
      Value := Summary.FIndexInfo.IsSparse(I);
      tbl.FieldValues['Sparse'] := Value; { Do not localize }
      { Get the Summary value }
      Value := GetSummaryAsVariant(SumIndex);
      if not (VarIsClear(Value)) or (Value <> 0) then
      begin
        VarCast(Value, Value, varDouble);
        tbl.FieldValues[GetSummaryName(CurrentSummary)] := Value;
      end;
      { Get the offset }
      Value := Summary.FIndexInfo.FOffset[I];
      tbl.FieldValues['Offset'] := Value;   { Do not localize }
      tbl.Post;
    end;
  finally
    if Assigned(tbl) then tbl.Close;
    tbl.Free;
  end;
end;

function TDataCache.GetIndexCount: Integer;
begin
  Result := FIndexMap.Count;
end;

function TDataCache.AddAggIndex(SumIndex: TSmallIntArray; BuilderDims: TList):Integer;
var
  I, DimCnt, iAggOffset: Integer;
  newIndex: TSmallIntArray;
  Summary: TSummary;
  BDim: TBuilderDim;
  Value: Variant;
begin
  Summary := Summaries[FActiveSummary];
  VarClear(Value);
  BDim := nil;
  DimCnt := 0;
  { Create the index }
  newIndex := TSmallIntArray.Create(SumIndex.Count, 0);
  for I := 0 to SumIndex.Count-1 do
  begin
    newIndex[I] := SumIndex[I];
    if PreCalculateTotals then
    begin
      if (SumIndex[I] <> SubTotal) then
      begin
        Inc(DimCnt);
        BDim := BuilderDims[I];
        if (BDim.SumCount > 0) and (DimCnt = 1) then
          Value := BDim.GetSummary(GetDimensionMemberAsVariant(I, SumIndex[I]));
      end;
    end;
  end;
  { Count indexes with subtotals }
  Inc(Summary.FIndexInfo.FSubTotalCnt);
  { Add the Index map only once }
  if not HasIndex then
    FIndexMap.Add(newIndex)
  else
    newIndex.Free;
  { Try to add the agg'd value }
  iAggOffset := SparseUnknown;
  if Assigned(BDim) and (BDim.SumCount > 0) and (DimCnt = 1) then
  begin
    if not VarIsClear(Value) then
      iAggOffset := Summary.AddSubTotal(Value)
    else
      iAggOffset := SparseAgg;
  end;
  { Create the index info object }
  Result := Summary.AddIndexInfo(True, False, iAggOffset);
end;

function TDataCache.AddIndex(SumIndex: TSmallIntArray; bSparse: Boolean):Integer;
var
  I: Integer;
  newIndex: TSmallIntArray;
  Summary: TSummary;
begin
  Summary := Summaries[FActiveSummary];
  { Create the index }
  newIndex := TSmallIntArray.Create(SumIndex.Count, 0);
  for I := 0 to SumIndex.Count-1 do
  begin
    newIndex[I] := SumIndex[I];
  end;
  { count sparsed indexes }
  if bSparse then Inc(FIndexInfo.FSparseCnt);
  { Add the Index map }
  if not HasIndex then
    FIndexMap.Add(newIndex)
  else
    newIndex.Free;
  Result := Summary.AddIndexInfo(False, bSparse, 0);
end;

function TDataCache.GetMemoryUsage: Integer;
var
  I: Integer;
begin
  Result := 0;
  { Get dimension memory usage }
  if Assigned(FDimensions) then
    for I := 0 to DimensionCount - 1 do
      Result := Result + Dimensions[I].MemoryUsage;
  { get summary memory usage }
  if Assigned(FSummaryData) then
    for I := 0 to SummaryCount - 1 do
    begin
      Result := Result + Summaries[I].MemoryUsage;
    end;
  { IndexMap }
  if Assigned(FIndexMap) then
    Result := Result + FIndexMap.MemoryUsage;
  Result := Max(Result, AllocMemSize);
end;

function TDataCache.GetSuccess: Boolean;
begin
  Result := csSuccess In FState;
end;

procedure TDataCache.SetSuccess(Value: Boolean);
begin
  if Value then
    Include(FState, csSuccess)
  else
    Exclude(FState, csSuccess);
end;

function TDataCache.GetPreCalcTotals: Boolean;
begin
  Result := ctPreCalc in FCalcTotals;
end;

procedure TDataCache.SetPreCalcTotals(Value: Boolean);
begin
  if Value then
    Include(FCalcTotals, ctPreCalc)
  else
    Exclude(FCalcTotals, ctPreCalc);
end;

function TDataCache.GetSparsing: Boolean;
begin
  Result := lsSparsing in FLookupState;
end;

procedure TDataCache.SetSparsing(Value: Boolean);
begin
  if Value then
    Include(FLookupState, lsSparsing)
  else
    Exclude(FLookupState, lsSparsing);
end;

function TDataCache.GetHasIndex: Boolean;
begin
  Result := csHasIndex in FState;
end;

procedure TDataCache.SetHasIndex(Value: Boolean);
begin
  if Value then
    Include(FState, csHasIndex)
  else
    Exclude(FState, csHasIndex);
end;

function TDataCache.DimensionFromFieldName(FldName: string): TDimension;
var
  I: Integer;
  Dim: TDimension;
begin
  Result := nil;
  if Assigned(FDimensions) then
  begin
    for I := 0 to FDimensions.Count-1 do
    begin
      Dim := FDimensions[I];
      if (Dim.FieldName = FldName) then Result := Dim;
    end;
  end;
end;

procedure TDataCache.ClearIndexInfo;
var
  Cnt, I: Integer;
begin
  { Scan the index, change all SubTotal indexes to sparse unknown }
  Cnt   := FIndexMap.Count;
  for I := 0 to Cnt-1 do
  begin
    { Get the index value for the dimension }
    if HasSubTotals(FIndexMap[I]) then
      FIndexInfo.AddOffset(I, sparseUnknown);
  end;
end;

function  TDataCache.IsBlankSummary: Boolean;
var
  Sum: TSummary;
begin
  Sum := Summaries[FActiveSummary];
  Result := Sum.MemberCount = Sum.BlankCount;
end;

  {  TSummary }

function AggAverage(Val1, Val2: Variant): Variant;
begin
  try
    Result := Val1 { count } / Val2;  { summary }
  except
    on EDivByZero do Result := 0;
    else
      raise;
  end;
end;


constructor TSummary.Create(Items: Cardinal; DataType: TFieldType);
begin
  inherited Create(Items, FieldTypeToVarType(DataType));
  FTotals := TThreadCustomArray.Create(1, FieldTypeToVarType(DataType));
  FFieldDef := TFieldDefinition.Create;
  FAggDef := TAggDefinition.Create;
  FIndexInfo := nil;
end;

destructor TSummary.Destroy;
begin
  FPosition := 0;
  if Assigned(FTotals) then FTotals.Free;
  FTotals := nil;
  if Assigned(FFieldDef) then FFieldDef.Free;
  FFieldDef := nil;
  if Assigned(FAggDef) then FAggDef.Free;
  FAggDef := nil;
  inherited Destroy;
end;

procedure TSummary.SetFieldType(Value: TFieldType);
begin
  FFieldDef.FieldType := Value;
end;

function TSummary.GetFieldType: TFieldType;
begin
  Result := FFieldDef.FieldType;
end;

procedure TSummary.SetPosition(Value: Integer);
begin
  FPosition := Value;
end;

procedure TSummary.SetFlag(aFlag: TDimFlags);
begin
   Include(FFLags, aFlag);
end;

procedure TSummary.AddSum(var SumIndex: TSmallIntArray; vNew: Variant);
begin
  SetItem(MemberCount, vNew);
end;

function TSummary.AddSubTotal(Value: Variant): Integer;
begin
  Result := FTotals.Add(Value);
end;

function TSummary.AddIndexInfo(BTotal, bSparse: Boolean; iAggOffset: Integer): Integer;
var
  pIndexInfo: PIndexInfoRec;
begin
  pIndexInfo := nil;
  try
    New(pIndexInfo);
    pIndexInfo^.SparseCnt := FIndexInfo.FSparseCnt;
    pIndexInfo^.SubTotalCnt := FIndexInfo.FSubTotalCnt;
    { Add the flags }
    if bTotal then
    begin
      pIndexInfo^.Flags := [idxSubTotals];
      pIndexInfo^.AggOffset := iAggOffset;
    end
    else
      pIndexInfo^.Flags := [idxNormal];
    if bSparse then pIndexInfo^.Flags := pIndexInfo^.Flags + [idxSparsed];
    Result := FIndexInfo.Add(pIndexInfo);
  finally
    Dispose(pIndexInfo);
  end;
end;

function TSummary.HasFlag(aFlag: TDimFlags): Boolean;
begin
   Result := aFlag in FFlags;
end;

procedure TSummary.SetName(Value: String);
begin
  FFieldDef.DisplayName := Value;
end;

function TSummary.GetName: string;
begin
  Result := FieldName;
end;

function TSummary.IsSparse(Index: Integer): Boolean;
begin
  Result := FIndexInfo.IsSparse(Index);
end;

function TSummary.MemoryUsage: Integer;
begin
  Result := 0;
  if Assigned(FIndexInfo) then
    Result := Result + (FIndexInfo.FOffset.Capacity * FIndexInfo.FOffset.ItemSize);
  Result := Result + FTotals.MemoryUsage;
  Result := Result + inherited MemoryUsage;
end;

procedure TSummary.UpdateIndexInfo(Index: Integer; Value: Variant);
var
  iOffset: Integer;
begin
  if (Value <> 0) then
  begin
    if (FIndexInfo.AddAggs = True) then
    begin
      iOffset := AddSubtotal(Value);
      FIndexInfo.AddOffset(Index, iOffset);
    end
    else
      FIndexInfo.AddOffset(Index, NonSparseAgg);
  end
  else
    FIndexInfo.AddOffset(Index, SparseAgg);
end;

function TSummary.SetAggregator(aName: string; DimMap: TCubeDims; dimType: TDimFlags; var dIdx: Integer): Boolean;
var
  SumIndex, CountIndex: Integer;
  I: Integer;
begin
  SumIndex := -1;
  CountIndex := -1;
  dIdx := -1;
  Result := False;
  { Find the count index }
  if (CountIndex < 0) then
  begin
    for I := 0 to DimMap.Count-1 do
    begin
      if (DimMap[I].DimensionType = dimCount) then
      begin
        if (aName = DimMap[I].BaseName) then
        begin
          CountIndex := I;      { look for a count in the list which matches }
        end
        else if (sCountStar = AnsiUpperCase(DimMap[I].Name)) then
        begin
          CountIndex := I;      { but give preference to a count(*) }
          break;
        end;
      end;
    end;
  end;
  { Find the summary index }
  if (SumIndex < 0) then
  begin
    for I := 0 to DimMap.Count-1 do
    begin
      if (aName = DimMap[I].BaseName) then
      begin
        if (DimMap[I].DimensionType = dimSum) then
        begin
          SumIndex := I;
          break;
        end;
      end;
    end;
  end;
  if (CountIndex = -1) or (SumIndex = -1) then Exit;
  if (dimType = dimAverage) then
  begin
    FAggDef.FAggProc := AggAverage;
    FAggDef.FSummaryIdx[0] := SumIndex;
    FAggDef.FSummaryIdx[1] := CountIndex;
    dIdx := SumIndex;
  end;
  Result := True;
end;

function TSummary.GetDerived: Boolean;
begin
  Result := (FPosition = -1);
end;

procedure TSummary.ClearTotals;
begin
  if Assigned(FTotals) then FTotals.Free;
  FTotals := TThreadCustomArray.Create(1, FieldTypeToVarType(FieldDefinition.FieldType));
end;

  { TDimension }

constructor TDimension.Create(Items: Cardinal; DataType: TFieldType);
begin
  inherited Create(Items, FieldTypeToVarType(DataType));
  FPosition := 0;
  FFieldDef := TFieldDefinition.Create;
end;

destructor TDimension.Destroy;
begin
  FFieldDef.Free;
  FPosition := 0;
  inherited Destroy;
end;

procedure TDimension.SetFieldType(Value: TFieldType);
begin
  FFieldDef.FieldType := Value;
end;

function TDimension.GetFieldType: TFieldType;
begin
  Result := FFieldDef.FieldType;
end;

procedure TDimension.SetPosition(Value: Integer);
begin
  FPosition := Value;
end;

procedure TDimension.SetName(Value: String);
begin
  FFieldDef.DisplayName := Value;
end;

function TDimension.GetName: String;
begin
  Result := FFieldDef.DisplayName;
end;

procedure TDimension.SetFlag(aFlag: TDimFlags);
begin
   Include(FFLags, aFlag);
end;

function TDimension.HasFlag(aFlag: TDimFlags): Boolean;
Begin
   Result := aFlag in FFlags;
End;

procedure TDimension.ClearFlag(aFlag: TDimFlags);
Begin
   Exclude(FFLags, aFlag);
End;

procedure TDimension.SetRangeCounting(bRange: Boolean);
begin
  if bRange then
    FRange := MemberCount
  else
    FRange := MemberCount - FRange;
end;

procedure TDimension.AssignSorted(Dim: TDimension; bUnique: Boolean);
begin
  Assign(TCustomArray(Dim), True, bUnique);
end;

function TDimension.IsString: Boolean;
begin
  Result := (FFieldDef.FieldType = ftString);
end;

procedure TDimension.SetRange(Value: Integer);
begin
  FRange := Value;
end;

  { TFieldDefinition }

constructor TFieldDefinition.Create;
begin
  inherited Create;
  FFormatType := fxNone;
end;

function TFieldDefinition.FormatVariantToStr(Value: Variant): string;
begin
  case FFormatType of
    fxFloat:
    begin
      if (FFormatString <> '') then
        Result := FormatFloat(FFormatString, Value)
      else
        Result := FloatToStrF(Value, ffGeneral, FPrecision, 2);
    end;
    fxCurrency:
    begin
      if (FFormatString <> '') then
        Result := FormatFloat(FFormatString, Value)
      else
        Result := FloatToStrF(Value, ffCurrency, FPrecision, 2);
    end;
    fxDateTime:
    begin
      if (FFormatString <> '') then
        Result := FormatDateTime(FFormatString, Value)
      else
        Result := DateTimeToStr(Value);
    end;
    fxDate:
    begin
      if (FFormatString <> '') then
        Result := FormatDateTime(FFormatString, Value)
      else
        Result := DateToStr(Value);
    end;
    fxTime:
    begin
      if (FFormatString <> '') then
        Result := FormatDateTime(FFormatString, Value)
      else
        Result := TimeToStr(Value);
    end;
    fxBoolean:
    begin
      VarCast(Value, Value, varBoolean);
      if (Value = True) then
        Result := sTrue
      else
        Result := sFalse;
    end;
    else
      Result := VarToStr(Value);
   end;
end;

procedure TFieldDefinition.SetFieldType(FType: TFieldType);
const
  TypeMap: array[ftUnknown..ftAutoInc] of TFormatType = (
    fxNone, fxString, fxInteger, fxInteger, fxInteger, fxBoolean,
    fxFloat, fxCurrency, fxCurrency, fxDate, fxTime, fxDateTime,
    fxNone, fxNone, fxInteger);

begin
  if (FFieldType <> FType) then
  begin
    FFieldType  := FType;
    if (FType <= ftAutoInc) then
      FFormatType := TypeMap[FType]
    else
      FFormatType := fxNone;
  end;
end;

procedure TFieldDefinition.SetName(Value: String);
begin
  FName := Value;
end;

  { TBuilderDim }

constructor TBuilderDim.Create(Items: Cardinal; DataType: TFieldType);
begin
  inherited Create(Items, DataType);
  FGroupBreak := False;
  FActiveIndex := 0;
  FValueList := TStringArray.Create(0,0);
end;

destructor TBuilderDim.Destroy;
begin
  FSummary.Free;
  FSummary := nil;
  FValueList.Free;
  FValueList := nil;
  inherited destroy;
end;

procedure TBuilderDim.InitSummary(DataType: Integer);
begin
  FSummary := TCustomArray.Create(1, DataType);
  FSummaryDataType := DataType;
end;

procedure TBuilderDim.Add(Value: Variant);
begin
  inherited items[MemberCount] := Value;
end;

procedure TBuilderDim.AddSummary(Value: Variant);
var
  vSum: Variant;
begin
  vSum := FSummary[FActiveIndex];
  if (TVarData(Value).VType <> varNull) then
    FSummary[FActiveIndex] := vSum + Value;
end;

function TBuilderDim.MatchLastVal(Value: Variant): Boolean;
begin
  Result := True;
  if not VarIsClear(LastVal) then Result := (Value = LastVal);
end;

procedure TBuilderDim.SetLastVal(Value: Variant);
var
  Idx: Integer;
  bFind: Boolean;

  function VarToCubeStr(Value: Variant): string;
  begin
    case TVarData(Value).VType of
      varEmpty,
      varNull:
      begin
        if (DataType <> varString) then
          Result := '0'
        else
          Result := '';
      end;
      else
        Result := VarToStr(Value);
    end;
  end;

begin
  FLastVal := Value;
  bFind := False;
  for Idx := 0 to FValueList.Count-1 do
    if (FValueList[Idx] = VarToCubeStr(Value)) then
    begin
      bFind := True;
      break;
    end;
    if bFind then
      FActiveIndex := Idx
    else
    begin
      FActiveIndex := FValueList.Add(VarToCubeStr(Value));
      FSummary[FActiveIndex] := VarAsType(0, FSummaryDataType);
    end;
end;

function TBuilderDim.GetLastVal: Variant;
begin
  Result := FLastVal;
end;

function TBuilderDim.GetSummary(Value: Variant): Variant;
var
  Idx: Integer;
  str: string;
begin
  if VarIsClear(Value) then
    str := ''
  else
    str := VarToStr(Value);
  for Idx := 0 to FValueList.Count-1 do
  begin
    if FValueList[Idx] = str then
      break;
  end;
  Result := FSummary[Idx];
end;

function TBuilderDim.GetSumCount: Integer;
begin
  Result := FSummary.MemberCount;
end;

  { DataCube Collection Definition }

constructor TCubeDims.Create(FOwner: TPersistent; ItemClass: TCubeDimClass);
begin
  inherited Create(FOwner, ItemClass);
end;

function TCubeDims.GetOwner: TPersistent;
begin
  Result := inherited GetOwner;
end;

function TCubeDims.GetCubeDim(Index: Integer): TCubeDim;
begin
  Result := TCubeDim(inherited Items[Index]);
end;

procedure TCubeDims.SetCubeDim(Index: Integer; Value: TCubeDim);
begin
  Items[Index].Assign(Value);
end;

function TCubeDims.Add: TCubeDim;
begin
  Result := TCubeDim(inherited Add);
end;

procedure TCubeDims.Assign(Source: TPersistent);
begin
  inherited;
end;

function TCubeDims.GetDirtyFlag: Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Count-1 do
    if Items[I].FDirty then
    begin
      Items[I].FDirty := False;
      Result := True;
      break;
    end;
end;

  { TCubeDim }

constructor TCubeDim.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FBinType := binNone;
  FDirty := False;
  FTransform := nil;
  FBinData := nil;
  FValues := -1;
  bWasActive := false;
end;

destructor TCubeDim.Destroy;
begin
  if Assigned(FBinData) then FBinData.Destroy;
  inherited Destroy;
end;

procedure TCubeDim.Assign(Value: TPersistent);
begin
  inherited;
  FBinType := TCubeDim(Value).FBinType;
  FStartDate := TCubeDim(Value).FStartDate;
  FTransform := TCubeDim(Value).FTransform;
  FBinFormat := TCubeDim(Value).FBinFormat;
  FStartValue := TCubeDim(Value).FStartValue;
  FValues := TCubeDim(Value).FValues;
  bWasActive := TCubeDim(Value).bWasActive;
  if Assigned(TCubeDim(Value).FBinData) then
  begin
    FBinData := TBinData.Create;
    FBinData.Assign(TCubeDim(Value).FBinData);
  end;
end;

procedure TCubeDim.InitializeRange;
var
  sDate, sNow: TDateTime;
  Year, Month, Day: Word;
begin
  if (FieldType in [ftDate, ftDateTime]) then
  begin
    BinType := binYear;
    sNow := Now;
    DecodeDate(sNow, Year, Month, Day);
    sDate := EncodeDate(Year, 1, 1);
    StartDate := TDate(sDate);
  end;
end;

function TCubeDim.GetLoaded: Boolean;
begin
  Result := Active;
end;

procedure TCubeDim.SetLoaded(Value: Boolean);
begin
  if TCubeDims(Owner).GetOwner is TCustomDataStore then
  begin
    if (TCustomDataStore(TCubeDims(Owner).GetOwner).DimensionMap = TCubeDims(Owner)) then
      raise Exception.CreateRes(@SDimMapActiveError);
  end;
  Active := Value;
end;

procedure TCubeDim.NotifyCollection(aType: TCDNotifyType);
begin
  FDirty := True;
  inherited NotifyCollection(aType);
end;

procedure TCubeDim.DataSetTransform(var Value: Variant; CubeDim: TCubeDim);
var
  I, K, cnt, nameCnt: Integer;
  binData: TBinData;
  custAr: TCustomArray;
  bName: string;
begin
  binData := CubeDim.FBinData;
  if (binData = nil) then Exit;
  nameCnt := binData.NameList.Count;
  for I := 0 to nameCnt-1 do
  begin
    bName := binData.NameList[I];
    custAr := binData.ValueList[I];
    { Try to guard against Variant type mismatch }
    if (custAr.DataType <> TVarData(Value).VType) then
      Value := custAr.ConvertVar(Value);
    cnt := custAr.MemberCount;
    for K := 0 to cnt-1 do
    begin
      if custAr[K] = Value then
      begin
        Value := bName;
        exit;
      end;
    end;
  end;
  binData.AddBinValue(binData.OtherBinName, Value);
  Value := binData.OtherBinName;
end;

procedure TCubeDim.YearTransform(var Value: Variant; CubeDim: TCubeDim);
var
  Present: TDateTime;
  Year, Month, Day: Word;
  Y, M, D: Word;
  sDate: TDateTime;
  DoFiscalYear: Boolean;
begin
  if (VarType(Value) <> varDate) then Exit;
  DoFiscalYear := False;
  sDate := CubeDim.StartDate;
  if (sDate <> 0) then
  begin
    DecodeDate(sDate, Y, M, D);
    if (M <> 1) or (D <> 1) then DoFiscalYear := True;
  end;
  Present := Value;
  DecodeDate(Present, Year, Month, Day);
  if DoFiscalYear then
  begin
    if (Month = M) then
    begin
      if (Day >= D) then Inc(Year);
    end
    else if (Month > M) then Inc(Year);
  end;
  Month := 1;
  Day := 1;
  Value := EncodeDate(Year, Month, Day);
end;

procedure TCubeDim.MonthTransform(var Value: Variant; CubeDim: TCubeDim);
var
  Present: TDateTime;
  Year, Month, Day: Word;
  Y, M, D: Word;
  sDate: TDateTime;
  DoFiscalYear: Boolean;
begin
  if (VarType(Value) <> varDate) then Exit;
  DoFiscalYear := False;
  sDate := CubeDim.StartDate;
  if (sDate <> 0) then
  begin
    DecodeDate(sDate, Y, M, D);
    if (M <> 1) or (D <> 1) then DoFiscalYear := True;
  end;
  Present := Value;
  DecodeDate(Present, Year, Month, Day);
  if DoFiscalYear then
  begin
    if (Month = M) then
    begin
      if (Day >= D) then Inc(Year);
    end
    else if (Month > M) then Inc(Year);
  end;
  Day := 1;
  Value := EncodeDate(Year, Month, Day);
end;

procedure TCubeDim.QuarterTransform(var Value: Variant; CubeDim: TCubeDim);
var
  Present: TDateTime;
  Year, Month, Day: Word;

  procedure GetQuarterRange(var Mon, Yr: Word);
  var
    I: Integer;
    Q, K, YQ, MQ, DQ: Word;
    sDate: TDateTime;
  begin
    sDate := CubeDim.StartDate;
    if (sDate = 0) then
      MQ := 1
    else
      DecodeDate(sDate, YQ, MQ, DQ);
    Q := 1;
    K := MQ;
    repeat
      for I := 1 to 3 do
      begin
        if (Mon = K) then
        begin
          if (Mon >= MQ) then Inc(Yr);
          Mon := Q;
          Exit;
        end;
        Inc(K);
      end;
      if (K >= 12) then K := 1;
      Inc(Q);
    until (Q > 4);
    if (Mon >= MQ) then Inc(Yr);
    Mon := MQ;
  end;
  
begin
  if (VarType(Value) <> varDate) then Exit;
  Present := Value;
  DecodeDate(Present, Year, Month, Day);
  Day := 1;
  GetQuarterRange(Month, Year);
  Value := EncodeDate(Year, Month, Day);
end;

function TCubeDim.AssignBinTypeTransform(Bins: TBinType): TCubeDimTransformEvent;
begin
  if (bins = binYear) then
    Result := YearTransform
  else if (bins = binMonth) then
    Result := MonthTransform
  else if (bins = binQuarter) then
    Result := QuarterTransform
  else
    Result := nil;
end;

function TCubeDim.AssignBinTypeFormat(Bins: TBinType): string;
begin
  if (bins = binYear) then
    Result := 'yyyy'
  else if (bins = binMonth) then
    Result := 'mmm, yyyy'
  else if (bins = binQuarter) then
    Result := '"Q"m, yyyy'
  else
    Result := '';
end;

procedure TCubeDim.SetBin(Value: TBinType);
begin
  if (FBinType <> Value) then
  begin
    case Value of
      binYear,
      binMonth,
      binQuarter:
      begin
        if not IsDateField(FieldType) then
          raise ECacheError.CreateRes(@sBinTypeMismatch);
        FTransform := AssignBinTypeTransform(Value);
        FBinFormat := AssignBinTypeFormat(Value);
      end;
      binSet:
      begin
        FTransform := DataSetTransform;
        FBinData := TBinData.Create;
      end;
      binCustom:
      else
      begin
        FTransform := nil;
        FBinFormat := '';
      end;
    end;
    if (Value <> binSet) then
    begin
      FBinData.free;
      FBinData := nil;
    end;
    FBinType := Value;
  end;
end;

function TCubeDim.GetBin: TBinType;
begin
  Result := FBinType
end;

procedure TCubeDim.SetDate(Value: TDate);
begin
  FStartDate := Value;
  FStartValue := DateToStr(Value);
end;

procedure TCubeDim.SetStart(Value: string);
var
  aVariant: Variant;
begin
  FStartValue := Value;
  if (Value <> '') and (BinType = binSet) then
  begin
    VarCast(aVariant, Value, FieldTypeToVarType(FieldType));
    BinType := binNone;
    BinType := binSet;
    BinData.AddBin('SingleValue', varType(aVariant));
    BinData.AddIBinValue(0, aVariant);
  end
  else if (BinType in [BinYear, BinQuarter, BinMonth]) then
  begin
    SetDate(StrToDate(Value));
  end;
end;

procedure TCubeDim.DefineProperties(Filer: TFiler);
begin
  inherited;
  Filer.DefineProperty('Active', ReadActive, WriteActive, true);
  Filer.DefineProperty('DateBin', ReadDateBin, nil, false);
  Filer.DefineProperty('StartDate', ReadStartDate, nil, false);
  Filer.DefineProperty('StartValue', ReadStartValue, WriteStartValue, StartValue <> '');
end;

procedure TCubeDim.ReadDateBin(Reader: TReader);
var
  temp: string;
begin
  temp := Reader.ReadIdent;
  if (temp = 'binNone') then
    binType := binNone
  else if (temp = 'binYear') then
    binType := binYear
  else if (temp = 'binQuarter') then
    binType := binQuarter
  else if (temp = 'binMonth') then
    binType := binMonth
  else if (temp = 'binSet') then
    binType := binSet
  else if (temp = 'binCustom') then
    binType := binCustom;
end;

procedure TCubeDim.ReadStartDate(Reader: TReader);
begin
  SetDate(Reader.ReadFloat);
end;

procedure TCubeDim.ReadStartValue(Reader: TReader);
var
  vType: TValueType;
begin
  vType := Reader.NextValue;
  case vType of
    vaExtended: StartValue := DateToStr(Reader.ReadFloat);
    vaInt32: StartValue := DateToStr(Reader.ReadFloat);
    vaString: StartValue := Reader.ReadString;
  end;
end;

procedure TCubeDim.WriteStartValue (Writer: TWriter);
begin
  if FieldType in [ftDate, ftDateTime] then
  begin
    Writer.WriteFloat(strtoDate(StartValue));
  end
  else
    Writer.WriteString(StartValue);
end;

procedure TCubeDim.ReadActive(Reader: TReader);
begin
  Active := Reader.ReadBoolean;
end;

procedure TCubeDim.WriteActive (Writer: TWriter);
begin
  Writer.WriteBoolean(Active);
end;

function TCubeDim.IsBinData: Boolean;
begin
  Result := not (FBinType = binNone);
end;

procedure TCubeDim.DoTransform(var Value: Variant);
begin
  if Assigned(FTransform) then FTransform(Value, self);
end;

function TCubeDim.GetBinValues(Value: Variant): Variant;
var
  Present: TDateTime;
  Year, Month, Day: Word;
begin
  { Process dates }
  if (FBinType = binYear) or (FBinType = binMonth) or (FBinType = binQuarter) then
  begin
    if (VarType(Value) <> varDate) then
    begin
      Result := 0;
      exit;
    end;
    Result := VarArrayCreate([0, 1], varVariant);
    Result[0] := Value;
    Present := Value;
    DecodeDate(Present, Year, Month, Day);
    case FBinType of
      binYear:	Year := Year + 1;
      binQuarter: Month := Month + 3;
      binMonth: Month := Month + 1;
      else;
    end;
    Result[1] := EncodeDate(Year, Month, Day);
  end
  else if (binType = binSet) and assigned(FBinData) then
  begin
    Result := FBinData.GetBinValues(FormatVariant(Value,''));
  end
  else
    Result := 0;
end;

  { TIndexInfo }

constructor TIndexInfo.Create;
begin
  inherited Create;
  FSparseCnt := 0;
  FSubTotalCnt := 0;
  FCount := 0;
  FExtInfo := False;
  FAddAggs := False;
  InitializeCriticalSection(FLock);
  FOffset := TIntArray.Create(1, 0);
end;

destructor TIndexInfo.Destroy;
begin
  LockIndex;
  try
    FOffset.Free;
    FOffset := nil;
    inherited destroy;
  finally
    UnlockIndex;
    DeleteCriticalSection(FLock);
  end;
end;

function TIndexInfo.Add(pIdxRec: PIndexInfoRec): Integer;
var
  iOffset: Integer;
begin
  LockIndex;
  try
    if (idxSparsed in pIdxRec^.Flags) then
      iOffset := SparseSum
    else if (idxSubTotals in pIdxRec^.Flags) then
      iOffset := pIdxRec^.AggOffset
    else
      iOffset := FCount - (pIdxRec^.SparseCnt + pIdxRec^.SubTotalCnt);
    AddOffset(FCount, iOffset);
    Inc(FCount);
    Result := FCount;
  finally
    UnlockIndex;
  end;
end;

function TIndexInfo.IsSparse(Index: Integer): Boolean;
begin
  Result := (FOffset[Index] = SparseSum);
end;

procedure TIndexInfo.SetCapacity(Value: Integer);
begin
  LockIndex;
  try
    FOffset.Capacity := Value;
  finally
    UnlockIndex;
  end;
end;

function TIndexInfo.GetCapacity: Integer;
begin
  Result := FOffset.Capacity;
end;

function TIndexInfo.IsSparseAgg(Index: Integer): Boolean;
begin
  Result := (FOffset[Index] = SparseAgg);
end;

procedure TIndexInfo.AddOffset(Index, IdxType: Integer);
begin
  LockIndex;
  try
    FOffSet[Index] := idxType;
  finally
    UnlockIndex;
  end;
end;

function TIndexInfo.LockIndex: TIntArray;
begin
  EnterCriticalSection(FLock);
  Result := TIntArray(FOffSet);
end;

procedure TIndexInfo.UnlockIndex;
begin
  LeaveCriticalSection(FLock);
end;

end.
