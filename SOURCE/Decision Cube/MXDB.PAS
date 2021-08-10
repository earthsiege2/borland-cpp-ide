{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxDB;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Menus, Bde, DB, DBTables, mxArrays, mxStore, mxConsts, mxcommon, mxtables,
  mxqparse, mxqedcom;

type
  EArrayError = class(Exception);
  EDimIndexError = class(Exception);

  TDimGroup = (dgRow, dgCol, dgSum, dgPage, dgNone);

  TRowStates = (rcNextOpen, rcPrevOpen, rcNextClosed, rcPrevClosed);
  TRowState = set of TRowStates;

  TDimState = (dmClosed, dmOpen, dmDrilled, dmPaged, dmNone);

  TDecisionControlType = (xtCheck, xtRadio, xtRadioEx);

  TIArray = class
  private
    FLimit: Integer;
    FAutoIncr: Boolean;
    FElements: Pointer;
    FBlockSize: Integer;
    FCapacity: Integer;
    procedure Alloc(ALimit: Integer);
    procedure Realloc(ALimit: Integer);
  protected
    function GetItem(Index: Integer): Integer;
    procedure SetItem(Index: Integer; Value: Integer);
  public
    constructor Create(ALimit: Integer; ABlockSize: Integer);
    destructor Destroy; override;
    procedure Assign(Value: TIArray);
    procedure InsertAt(Index: Integer; Value: Integer);
    function RemoveItem(Index: Integer): Integer;                
    property AutoSize: Boolean read FAutoIncr write FAutoIncr;
    property Limit: Integer read FLimit;
    property Items[Index: Integer]: Integer read GetItem write SetItem; default;  

  end;

  PArrayInt = ^TArrayInt;
  TArrayInt = array[0..MaxInt div 8] of Integer;

  TDimInfo = Record
    iState: TDimState;
    iValue: Integer;
    iIndex: Integer;
    iActiveIndex: Integer;
    iRowState: TRowState;
    iGroup: TDimGroup;
  end;

  TDimRange = Record
    First: Integer;
    Last: Integer;
  end;

  TBigStr = array[0..100000] of Char;
  PDimInfo = ^TDimInfo;
  TArrayDimInfo = array[0..999] of TDimInfo;
  PArrayDimInfo = ^TArrayDimInfo;

  TDimInfoArray = class
  private
    FLimit: Integer;
    FElements: pointer;
    AllXDim: TIArray;
    FDimNames: TStringList;
  protected
    function  GetItem(Index: Integer): PDimInfo;
    function Find(Name: string; var pos: Integer): Boolean;
  public
    constructor Create(ALimit: Integer);
    destructor Destroy; override;
    procedure Assign( Value: TDimInfoArray);
    function GetGroupItem(Group: TDimGroup; Index: Integer; bOpen: Boolean): PDimInfo;
    function GetGroupIndex(Group: TDimGroup; Index: Integer; bOpen: Boolean): Integer;
    function GetGroupSize(Group: TDimGroup; bOpen: Boolean): Integer;
    function GetGroupArray(Group: TDimGroup; bOpen: Boolean): TIArray;
    function IsEqual( Value: TDimInfoArray): Boolean;
    property Limit: Integer read FLimit;
    property Items[Index: Integer]: PDimInfo read GetItem; default;
  end;

  TPivotState = class
  protected
    procedure Assign(Value: TPivotState);
    function IsEqual(Value: TPivotState): Boolean;
  public
    FDims: Integer;
    FSums: Integer;
    FCurrentSum: Integer;
    FRowSubs: Boolean;
    FColSubs: Boolean;
    FRowSparse: Boolean;					
    FColSparse: Boolean;
    DimInfo: TDimInfoArray;
    constructor Create;
    destructor Destroy; override;
  end;


  TDecisionCube = class;
  TDecisionSource = class;
  TDecisionDataEvent = (xeStateChanged, xeSummaryChanged, xePivot, xeNewMetaData, xeSourceChange);


  TDecisionDataLink = class(TPersistent)
  private
  protected
    FDecisionSource: TDecisionSource;
    FBlocked: Boolean;
    procedure SetDecisionSource(source: TDecisionSource);
    procedure DecisionDataEvent(Event: TDecisionDataEvent); virtual;
  public
    constructor Create;
    destructor Destroy; override;
    property DecisionSource: TDecisionSource read FDecisionSource write SetDecisionSource;
  end;

  TDecisionSource = class(TComponent)
  private
    FChangeCount: Integer;
    FState: TCubeState;
    bActivated: Boolean;
    FBlocked: Boolean;
    FDecisionCube: TDecisionCube;
    FControlType: TDecisionControlType;
    FDecisionDataLinks: TList;
    FSavePivotState: TPivotState;
    FData: TPivotState;
    RowLookup: TTwoDimArray;
    ColLookup: TTwoDimArray;
    FRowMax: Integer;
    FColMax: Integer;							
    FActiveRows: Integer;
    FActiveCols: Integer;
    FAllRows: Integer;
    FAllPages: Integer;
    FAllCols: Integer;
    procedure SetUpData;
    procedure RebuildPivotState;
    procedure BuildLookups;
    function GetReady: Boolean;
    procedure AddDatalink (link: TDecisionDatalink);
    procedure RemoveDatalink (link: TDecisionDatalink);
    procedure NotifyDataLinks(Event: TDecisionDataEvent);
    procedure ReadDimCount(Reader: TReader);
    procedure WriteDimCount(Writer: TWriter);
    procedure ReadSumCount(Reader: TReader);
    procedure WriteSumCount(Writer: TWriter);
    procedure ReadCurrentSum(Reader: TReader);
    procedure WriteCurrentSum(Writer: TWriter);
    procedure ReadRowSparse(Reader: TReader);
    procedure WriteRowSparse(Writer: TWriter);
    procedure ReadColSparse(Reader: TReader);
    procedure WriteColSparse(Writer: TWriter);
    procedure ReadDimInfo(Reader: TReader);
    procedure WriteDimInfo(Writer: TWriter);
    function GetExampleRepCount(dimGroup: TDimGroup; level: Integer): Integer;
    procedure DrillValue(iDim: Integer; ValueIndex: Integer);
    procedure DecisionDataEvent(Event: TDecisionDataEvent);
    procedure EnforceConstraints(dimGroup: TDimGroup; PreserveIndex: Integer);
    function GetRowSparsing: Boolean;
    function GetColSparsing: Boolean;
    procedure SetRowSparsing(Value: Boolean);
    procedure SetColSparsing(Value: Boolean);
    function GetDecisionCube: TDecisionCube;
    procedure SetDecisionCube(Value: TDecisionCube);
    function GetDims: Integer;
    function GetSums: Integer;
    function GetCurrentSum: Integer;
    procedure ProcessPivotState(FState: TPivotState);
    procedure FetchPivotState (var FState: TPivotState); virtual;
    procedure StorePivotState(FState: TPivotState); virtual;
    procedure BeginChange; virtual;
    procedure EndChange(event: TDecisionDataEvent); virtual;
  protected
    procedure SetDimGroup(iDim: Integer; Group: TDimGroup; Index: Integer; bOpen: Boolean);
    procedure SetDimState(iDim: Integer; State: TDimState; ValueIndex: Integer);
  public
    FOnBeforePivot: TNotifyEvent;
    FOnAfterPivot: TNotifyEvent;
    FOnStateChange: TNotifyEvent;
    FOnNewDimensions: TNotifyEvent;
    FOnLayoutChange: TNotifyEvent;
    FonSummaryChange: TNotifyEvent;
    constructor Create( AOwner: TComponent ); override;
    destructor Destroy; override;
    procedure DefineProperties(Filer: TFiler); override;
    { Meta data and data fetching }
    function GetMemberAsString(iDim: Integer; ValueIndex: Integer): String;
    function GetMemberAsVariant(iDim: Integer; ValueIndex: Integer): Variant;
    function GetDimensionName(iDim: Integer): String;
    function GetDimensionMemberCount(iDim: Integer): Integer;
    function GetSummaryName(iSum: Integer): String;
    procedure SetCurrentSummary(Value: Integer);
    { Graph specific data fetching }
    function Get2DDataAsVariant(iDimA, iDimB: Integer; aValueIndex, bValueIndex:Integer): Variant;
    { Grid specific data fetching }
    function GetDataAsString(ARow, ACol:Integer; var SubLevel: Integer): String;
    function GetDataAsVariant(Arow, ACol: Integer; var SubLevel: Integer): Variant;
    function GetValueIndex(dimGroup: TDimGroup; Index: Integer; Cell: Integer; var isBreak: Boolean; var isSum: Boolean) : Integer;
    function GetValueArray(ACol, ARow: Integer; var ValueArray: TSmallIntArray): Boolean;
    function GetGroupExtent(dimGroup: TDimGroup; Index: Integer; Cell: Integer): TDimRange;
    { Active or Inactive Row/Col relative pivoting functions }
    function GetActiveDim(dimGroup: TDimGroup; index: Integer; bOpen: Boolean): Integer;
    procedure OpenDimIndexRight(dimGroup: TDimGroup; Index: Integer; bOpen: Boolean);
    procedure CloseDimIndexRight(dimGroup: TDimGroup; Index: Integer; bOpen: Boolean);
    procedure OpenDimIndexLeft(dimGroup: TDimGroup; Index: Integer; bOpen: Boolean);
    procedure ToggleDimIndex(dimGroup: TDimGroup; Index: Integer; bOpen: Boolean);
    procedure DrillDimIndex(dimGroup: TDimGroup; Index: Integer; ValueIndex: Integer; bOpen:Boolean);
    procedure MoveDimIndexes(SdimGroup, DdimGroup: TDimGroup; SIndex, DIndex: Integer; bOpen:Boolean);
    procedure SwapDimIndexes(SdimGroup, DdimGroup: TDimGroup; SIndex, DIndex: Integer; bOpen:Boolean);
    function GetGroupCount(dimGroup: TDimGroup; bOpen: Boolean):Integer;
    function GetGroup(iDim: Integer):TDimGroup;
    function GetIndex(iDim: Integer; bOpen: Boolean): Integer;
    function GetState(iDim: Integer): TDimState;
    function GetValue(iDim: Integer): Integer;
    function GetRowState(iDim: Integer): TRowState;
    property Ready: Boolean read GetReady;
    { pivot State Information } 
    property nDims: Integer read GetDims;
    property nSums: Integer read GetSums;
    property nRowDims: Integer read FAllRows;
    property nColDims: Integer read FAllCols;
    property nOpenRowDims: Integer read FActiveRows;
    property nOpenColDims: Integer read FActiveCols;
    property nDataRows: Integer read FRowMax;
    property nDataCols: Integer read FColMax;
    property CurrentSum: Integer read GetCurrentSum;
  published
    property DecisionCube: TDecisionCube read GetDecisionCube write SetDecisionCube;
    property ControlType: TDecisionControlType read FControlType write FControlType;
    property Name;
    property SparseRows: Boolean read GetRowSparsing write SetRowSparsing;
    property SparseCols: Boolean read GetColSparsing write SetColSparsing;
    property OnStateChange: TNotifyEvent read FOnStateChange write FOnStateChange;
    property OnNewDimensions: TNotifyEvent read FOnNewDimensions write FOnNewDimensions;
    property OnLayoutChange: TNotifyEvent read FOnLayoutChange write FOnLayoutChange;
    property OnSummaryChange: TNotifyEvent read FOnSummaryChange write FOnSummaryChange;
    property OnBeforePivot: TNotifyEvent read FOnBeforePivot write FOnBeforePivot;
    property OnAfterPivot: TNotifyEvent read FOnAfterPivot write FOnAfterPivot;
  end;

  TQADecisionSource = class(TDecisionSource);

  TDecisionCube = class(TCustomDataStore)
  private
    FDecisionSources: TList;				
    FBlocked: Boolean;
    FState: TCubeState;
    FStreamedActive: Boolean;
    procedure CubeSetActive(Value: Boolean );
    function CubeGetActive: Boolean;
    function GetSparsing: Boolean;
    procedure SetSparsing(Value: Boolean );
    procedure AddDataSource(source: TDecisionSource);
    procedure RemoveDataSource(source: TDecisionSource);
    procedure NotifyDataSources(Event: TDecisionDataEvent);
    function GetAnySQL(ValueArray: TSmallIntArray; SelectList: string; bActive: Boolean; bGrouped: Boolean): string;
    property Sparsing: Boolean read GetSparsing write SetSparsing;
  protected
    function CanDimBeClosed(iMapIndex: Integer): Boolean; override;
    function CanSumBeClosed(iMapIndex: Integer): Boolean; override;
  public
    constructor Create( AOwner: TComponent ); override;
    destructor Destroy; override;
    property DesignState;
    function GetSQL(ValueArray: TSmallIntArray; bActive: Boolean): string;
    function GetDetailSQL(ValueArray: TSmallIntArray; SelectList: string; bActive: Boolean): string;
    procedure ShowCubeDialog;
    procedure StateChanged; override;
    {$IFDEF PDEBUGS}
    procedure ShowSQLDialog(SQL: string);
    procedure ShowQueryDialog;
    {$ENDIF}
    {$IFDEF PROFILE}
    procedure CreateIndexTable(Const Filename: String);
    function GetLogFile: string;
    procedure SetLogFile(fName: string);
    {$ENDIF}
    property Active: Boolean read CubeGetActive write CubeSetActive;
  published
    property DataSet;
    property DimensionMap;
    property ShowProgressDialog;
    property MaxDimensions;
    property MaxSummaries;
    property MaxCells;
    property OnLowCapacity;
    property BeforeOpen;
    property AfterOpen;
    property BeforeClose;
    property AfterClose;
    property OnRefresh;
    {$IFDEF PROFILE}
    property ProfileLogFile: string read GetLogFile write SetLogFile;
    {$ENDIF}
  end;

implementation

{ TDecisionCube }

uses Math, mxdcube
{$IFDEF PDEBUGS}
  ,mxdssqry, mxdsql
{$ENDIF};

  const
    defDimSize = 20;

procedure TDecisionSource.SetDimGroup(iDim: Integer; Group: TDimGroup; Index: Integer; bOpen: Boolean);
var
  aDimInfo: pDImInfo;
  oldIndex: Integer;
begin
  aDimInfo := FData.DimInfo.GetGroupItem(Group, Index, bOpen);
  if (bOpen) then
    oldIndex := aDimInfo.iActiveIndex
  else
    oldIndex := aDimInfo.iIndex;
  MoveDimIndexes(aDimInfo.iGroup, Group, oldIndex, index, bOpen);
end;

procedure TDecisionSource.SetDimState(iDim: Integer; State: TDimState; ValueIndex: Integer);
var
  aDimInfo: pDimInfo;
begin
  aDimInfo := FData.DimInfo[iDim];
  if (aDimInfo.iState = State) and (aDimInfo.iValue = ValueIndex) then Exit;
  BeginChange;
  aDimInfo.iState := State;
  if (State = dmDrilled) then
    aDimInfo.iValue := ValueIndex
  else if (State = dmPaged) then
    aDimInfo.iValue := 0
  else aDimInfo.iValue := -1;
  EndChange(xePivot);
end;

function TDecisionSOurce.GetGroupCount(dimGroup: TDimGroup; bOpen: Boolean): Integer;
begin
  Result := FData.DimInfo.GetGroupSize(dimGroup, bOpen);
end;

function TDecisionSource.GetGroup(iDim: Integer): TDimGroup;
begin
  Result := FData.DimInfo[iDim].iGroup;
end;

function TDecisionSource.GetIndex(iDim: Integer; bOpen: Boolean): Integer;
begin
  if bOpen then
    Result := FData.DimInfo[iDim].iActiveIndex
  else
    Result := FData.DimInfo[iDim].iIndex;
end;

function TDecisionSource.GetState(iDim: Integer): TDimState;
begin
  Result := FData.DimInfo[iDim].iState;
end;

function TDecisionSource.GetRowState(iDim: Integer): TRowState;
begin
  Result := FData.DimInfo[iDim].iRowState;
end;

function TDecisionSource.GetValue(iDim: Integer): Integer;
begin
  Result := FData.DimInfo[iDim].iValue;
end;

function TDecisionSource.GetDims: Integer;
begin
  Result := FData.FDims;
end;

function TDecisionSource.GetSums: Integer;
begin
  Result := FData.FSums;
end;

function TDecisionSource.GetCurrentSum: Integer;
begin
  Result := FData.FCurrentSum;
end;

constructor TDecisionCube.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDecisionSources := TList.Create;
  FState := dcInActive;
  FBlocked := False;
  FStreamedActive := False;
  DesignState := dsAllData;
  RCS;
end;

destructor TDecisionCube.Destroy;
begin
  while FDecisionSources.Count > 0 do
    TDecisionSource(FDecisionSources.Last).DecisionCube := nil;
  assert(FDecisionSources.count = 0, 'Decision Sources did not free correctly');  //$$$ leave asserts? [adm]
  FDecisionSources.Free;
  inherited Destroy;
end;

function TDecisionCube.CanDimBeClosed(iMapIndex: Integer): Boolean;
var
  x, i: Integer;
begin
  Result := False;
  if (iMapIndex < DimensionMap.count) and DimensionMap[iMapIndex].Loaded then
  begin
    x := 0;
    for i := 0 to iMapIndex do
    begin
      if (DimensionMap[i].Loaded) and (DimensionMap[i].DimensionType = dimDimension) then
        x := x + 1;
    end;
    for i := 0 to FDecisionSources.count-1 do
    begin
      with TDecisionSource(FDecisionSources[i]) do
      begin
        if assigned(FData) and assigned(Fdata.DimInfo) and ((x-1) < FData.DimInfo.limit) then
        begin
          if Fdata.DimInfo[x-1].iState <> dmClosed then Exit;
        end;
      end;
    end;
  end;
  Result := True;
end;

function TDecisionCube.CanSumBeClosed(iMapIndex: Integer): Boolean;
var
  x, i: Integer;
begin
  Result := False;
  if (iMapIndex < DimensionMap.count) and DimensionMap[iMapIndex].Loaded then
  begin
    x := 0;
    for i := 0 to iMapIndex do
    begin
      if (DimensionMap[i].Loaded) and (DimensionMap[i].DimensionType <> dimDimension) then
        x := x + 1;
    end;
    for i := 0 to FDecisionSources.count-1 do
    begin
      with TDecisionSource(FDecisionSources[i]) do
      begin
        if assigned(FData) and assigned(Fdata.DimInfo) and ((x-1) < FData.DimInfo.limit) then
        begin
          if (FData.FCurrentSum = x-1) then Exit;
        end;
      end;
    end;
  end;
  Result := True;
end;

{$IFDEF PROFILE}
function TDecisionCube.GetLogFile: string;
begin
  Result := DataCache.ProfileLogFile;
end;

procedure TDecisionCube.SetLogFile(fName: string);
begin
  DataCache.ProfileLogFile := fName;
end;

procedure TDecisionCube.CreateIndexTable(Const Filename: String);
begin
  DataCache.CreateTable(FileName);
end;
{$ENDIF}

procedure TDecisionCube.AddDataSource(source: TDecisionSource);
begin
  FDecisionSources.Add(source);
  source.FDecisionCube := self;
end;

procedure TDecisionCube.RemoveDataSource(source: TDecisionSource);
begin
  Source.FDecisionCube := nil;
  FDecisionSources.Remove(Source);
end;

procedure TDecisionCube.NotifyDataSources(Event: TDecisionDataEvent);
var
  I: Integer;
begin
  for I := FDecisionSources.Count - 1 downto 0 do
    with TDecisionSource(FDecisionSources[I]) do
    begin
      DecisionDataEvent(Event);
    end;
end;

procedure TDecisionCube.CubeSetActive(Value: Boolean);
begin
  if (csReading in ComponentState) then
  begin
    FStreamedActive := Value;
    Exit;
  end;
  if (Value <> FStreamedActive) then inherited Active := Value;
  FStreamedActive := inherited Active;
end;

function TDecisionCube.CubeGetActive: Boolean;
begin
  if (csReading in ComponentState) then
    Result := FStreamedActive
  else
    Result := inherited Active;
end;

procedure TDecisionCube.StateChanged;
var
  iActive, i: Integer;
begin
  if (FState <> State) then
  Begin
    FState := State;
    if FState <> dcInactive then
    begin
      iActive := 0;
      for i := 0 to DimensionMap.Count-1 do
      begin
        if (DimensionMap[i].loaded) and (DimensionMap[i].DimensionType = dimDimension) then
        begin
          DimensionMap[i].ValueCount := GetDimensionMemberCount(iActive);
          iActive := iActive + 1;
        end;
      end;
    end;
    NotifyDataSources(xeStateChanged);
  end;
end;

function TDecisionCube.GetSparsing: Boolean;
begin
  Result := DataCache.Sparsing;
end;

procedure TDecisionCube.ShowCubeDialog;
var
  aWindow: TDSSCubeEditor;
  x,y: Integer;
begin
  aWindow := TDSSCubeEditor.Create(application);
  try
    if aWindow.SInitialize(nil, self) then
    begin
      x := (Screen.Width - aWindow.Width) div 2;
      y := (Screen.Height - aWindow.Height) div 2;
      if (x < 0) then x := 0;
      if (y < 0) then y := 0;
      aWindow.Left := x;
      aWindow.Top := y;
      aWindow.ShowModal;
    end;
  finally
    aWindow.free;
  end;
end;

function TDecisionCube.GetSQL(ValueArray: TSmallIntArray; bActive: Boolean): string;
begin
  Result := GetAnySQL(ValueArray, '', bActive, True);
end;

function TDecisionCube.GetDetailSQL(ValueArray: TSmallIntArray; SelectList: string; bActive: Boolean): string;
begin
  Result := GetAnySQL(ValueArray, SelectList, bActive, False);
end;

function TDecisionCube.GetAnySQL(ValueArray: TSmallIntArray; SelectList: string;
                                 bActive: Boolean; bGrouped: Boolean): string;
var
  Map: TCubeDims;
  anError: TQueryError;
  vCondition: Variant;
  i,j: Integer;
  qParse: TXTabQuery;
  myDB: TDataBase;
  aPos, count: Integer;
  myQuery: tQuery;
  aString: string;
  bDataSetMatch: Boolean;
begin
  Result := '';
  if not assigned(DataSet) or not(DataSet is TQuery) then Exit;
  myQuery := TQuery(DataSet);
  if not assigned (myQuery.SQL) or (myQuery.SQL.Text = '') then Exit;
  myDB := myQuery.DBSession.OpenDataBase(myQuery.dataBaseName);
  if (myDB = nil) then Exit;
  myDB.connected := True;
  qParse := TXTabQuery.create;
  qParse.canDelete := False;
  Map := TCubeDims.create(self,TCubeDim);
  try
    Map.Assign(DimensionMap);
    qParse.DBHandle := myDB.Handle;
    qParse.SQLString := MyQuery.SQL.Text;
    anError := VerifyRTQuery(myQUery, Map, bDataSetMatch);
    if anError = tqeNotInitialized then
      raise exception.createRes(@SQryNotInitialized);
    { add where clauses for the non-summary members of the valuearray }
    for i := ValueArray.limit-1 downto 0 do
    begin
      if (ValueArray[i] >= 0) and (Map[i].DimensionType = dimDimension) then
      begin
        if (Map[i].BinType in [binYear, binQuarter, binMonth]) then
        begin
          VCondition := Map[i].GetBinValues( GetMemberAsVariant(i, ValueArray[i]));
          qParse.AddWhereOp(Map[i].BaseName,vcondition[0], qnodeGreaterEq);
          qParse.AddWhereOp(Map[i].basename, vCondition[1], qnodeLess);
        end
        else if Map[i].BinType = binSet then
        begin
          VCondition := Map[i].GetBinValues( GetMemberAsVariant(i, ValueArray[i]));
          for j:= VarArrayLowBound(vCondition,1) to VarArrayHighBound(vCondition,1) do
            qParse.AddWhereOp(Map[i].basename, vCondition[j], qnodeEqual);
        end
        else
        begin
          vCondition := GetMemberAsVariant(i, ValueArray[i]);
          qParse.AddWhereOp(Map[i].basename, vCondition, qnodeEqual);
        end;
      end;
    end;
    { Remove non-active summaries and dimensions if bActive is False }
    for i := Map.count-1 downto 0 do
    begin
      if (bActive and (not Map[i].loaded)) or ((not bGrouped) and (Map[i].DimensionType <> dimDimension)) then
      begin
        if Map[i].DerivedFrom < 0 then
          qParse.DeleteProjector(i);
      end;
    end;
    if not bGrouped then
    begin
      qParse.DeleteGroupBys;
      aPos := 1;
      count := 0;
      while (aPos > 0) do
      begin
        aString := NextArg(aPos, SelectList);
        if aPos > 0 then
        begin
          if (Count = 0) and (SelectList = '*') then
            qParse.DeleteDimensions;
          qParse.AddNewItem(aString, dimDimension, count, False, '');
          count := count + 1;
        end;
      end;
    end;
    if bGrouped then qParse.FixupGroupBys;
    Result := qParse.GetDialectSQLString;
  finally
    qParse.free;
    Map.Free;
  end;
end;

{$IFDEF PDEBUGS}
procedure TDecisionCube.ShowSQLDialog(SQL: string);
begin
  if not (DataSet is TQuery) then Exit;
  ShowSQLWindow(TQuery(DataSet).DataBaseName,SQL);
end;

procedure TDecisionCube.ShowQueryDialog;
var
  aWindow: TDSSQueryEditor;
  x,y: Integer;
  aQuery: TQuery;
begin
  if not assigned(DataSet) or not (DataSet is TQuery) then
    Exit
  else
    aQuery := TQuery(DataSet);
  aWindow := TDSSQueryEditor.Create(application);
  try
    if aWindow.SInitialize(nil, aQuery) then
    begin
      x := (Screen.Width - aWindow.Width) div 2;
      y := (Screen.Height - aWindow.Height) div 2;
      if (x < 0) then x := 0;
      if (y < 0) then y := 0;
      aWindow.Left := x;
      aWindow.Top := y;
      aWindow.ShowModal;
    end;
  finally
    aWindow.free;
  end;
end;

{$ENDIF}
procedure TDecisionCube.SetSparsing(Value: Boolean);
begin
  DataCache.Sparsing := Value;
end;

{ TDecisionSource }

constructor TDecisionSource.Create( AOwner: TComponent );
begin
  inherited Create(AOwner);
  FDecisionDataLinks := TList.Create;
  FState := dcInactive;
  FBlocked := False;
  FData := TPivotState.create;
  FSavePivotState := TPivotState.Create;
  SetUpData;
  RCS;
end;

destructor TDecisionSource.Destroy;
begin
  while FDecisionDataLinks.Count > 0 do
  begin
    TDecisionDataLink(FDecisionDataLinks.Last).DecisionSource := nil;
  end;
  assert(FDecisionDataLinks.count = 0, 'Data Links did not free correctly');
  FDecisionDataLinks.Free;
  DecisionCube := nil;    { frees the cube link }
  FData.Free;
  FData := nil;
  FSavePivotState.Free;
  FSavePivotState := nil;
  RowLookup.free;
  RowLookup := nil;
  ColLookup.free;
  ColLookup := nil;
  inherited Destroy;
end;

function TDecisionSource.GetRowSparsing: Boolean;
begin
  Result := FData.FRowSparse;
end;

procedure TDecisionSource.SetRowSparsing(Value: Boolean);
begin
  if FData.FRowSparse <> Value then
  begin
    if Ready then
    begin
      BeginChange;
      FData.FRowSparse := Value;
      EndChange(xePivot);
      UpdateDesigner(self);
    end;
  end;
end;

function TDecisionSource.GetColSparsing: Boolean;
begin
  Result := FData.FColSparse;
end;

procedure TDecisionSource.SetColSparsing(Value: Boolean);
begin
  if FData.FColSparse <> Value then
  begin
    if Ready then
    begin
      BeginChange;
      FData.FColSparse := Value;
      EndChange(xePivot);
      UpdateDesigner(self);
    end;
  end;
end;

procedure TDecisionSource.DefineProperties(Filer: TFiler);
begin
  inherited;
  Filer.DefineProperty('DimensionCount',ReadDimCount,WriteDimCount,True);
  Filer.DefineProperty('SummaryCount',ReadSumCount,WriteSumCount,True);
  Filer.DefineProperty('CurrentSummary',ReadCurrentSum,WriteCurrentSum,True);
  Filer.DefineProperty('SparseRows',ReadRowSparse,WriteRowSparse,True);
  Filer.DefineProperty('SparseCols',ReadColSparse,WriteColSparse,True);
  Filer.DefineProperty('DimensionInfo',ReadDimInfo,WriteDimInfo,True);
end;

procedure TDecisionSource.ReadDimCount(Reader: TReader);
begin
  FSavePivotState.FDims := Reader.ReadInteger;
end;

procedure TDecisionSource.WriteDimCount(Writer: TWriter);
begin
  if Assigned(FData.DimInfo) then
    Writer.WriteInteger(FData.DimInfo.limit)
  else
    Writer.WriteInteger(0);
end;

procedure TDecisionSource.ReadSumCount(Reader: TReader);
begin
  FSavePivotState.FSums := Reader.ReadInteger;
end;

procedure TDecisionSource.WriteSumCount(Writer: TWriter);
begin
  Writer.WriteInteger(Fdata.FSums);
end;
procedure TDecisionSource.ReadCurrentSum(Reader: TReader);
begin
  FSavePivotState.FCurrentSum := Reader.ReadInteger;
end;

procedure TDecisionSource.WriteCurrentSum(Writer: TWriter);
begin
  Writer.WriteInteger(FData.FCurrentSum)
end;

procedure TDecisionSource.ReadRowSparse(Reader: TReader);
begin
  FSavePivotState.FRowSparse := Reader.ReadBoolean;
end;

procedure TDecisionSource.WriteRowSparse(Writer: TWriter);
begin
  Writer.WriteBoolean(FData.FRowSparse)
end;

procedure TDecisionSource.ReadColSparse(Reader: TReader);
begin
  FSavePivotState.FColSparse := Reader.ReadBoolean;
end;

procedure TDecisionSource.WriteColSparse(Writer: TWriter);
begin
  Writer.WriteBoolean(FData.FColSparse)
end;

procedure TDecisionSource.ReadDimInfo(Reader: TReader);
var
  i,x: Integer;
  aDimInfo: PDimInfo;
begin
  Reader.ReadListBegin;
  FSavePivotState.DimInfo.Free;
  FSavePivotState.DimInfo := TDimInfoArray.Create(FSavePivotState.FDims);
  with FData do
  begin
    for i := 0 to FSavePivotState.DimInfo.Limit-1 do
    begin
      aDimInfo := FSavePivotState.DimInfo[i];
      x := Reader.ReadInteger;
      case x of
        0: aDimInfo.iGroup := dgNone;
        1: aDimInfo.iGroup := dgRow;
        2: aDimInfo.iGroup := dgCol;
        3: aDimINfo.iGroup := dgSum;
      end;
      aDimInfo.iActiveIndex := Reader.ReadInteger;
      case Reader.ReadInteger of
        0: aDimInfo.iState := dmNone;
        1: aDimInfo.iState := dmOpen;
        2: aDimInfo.iState := dmClosed;
        3: aDimInfo.iState := dmDrilled;
        4: aDimInfo.iState := dmPaged;
      end;
      aDimINfo.iIndex := Reader.ReadInteger;
      aDimInfo.iValue := Reader.ReadInteger;
    end;
    Reader.ReadListEnd;
    ProcessPivotState(FSavePivotState);
    FSavePivotState.DimInfo.Free;
    FSavePivotState.DimInfo := nil;
    RebuildPivotState;
    Buildlookups;
    NotifyDataLinks(xeNewMetaData);
  end;
end;

procedure TDecisionSource.WriteDimInfo(Writer: TWriter);
var
  i: Integer;
  aValue: Integer;
  aDimInfo: PDimInfo;
begin
  Writer.WriteListBegin;
  if Assigned(FData.DimInfo) then
    with FData do
    begin
      for i := 0 to FData.DimInfo.limit-1 do
      begin
        aDimInfo := DimInfo[i];
        if aDimInfo.iGroup = dgRow then
          aValue := 1
        else if aDimInfo.iGroup = dgCol then
          aValue := 2
        else if aDimInfo.iGroup = dgSum then
          aValue := 3
        else
          aValue := 0;
        Writer.WriteInteger(aValue);
        Writer.WriteInteger(aDimInfo.iActiveIndex);
        if aDimInfo.iState = dmOpen then
          aValue := 1
        else if aDimInfo.iState = dmClosed then
          aValue := 2
        else if aDimInfo.iState = dmDrilled then
          aValue := 3
        else if aDimInfo.iState = dmPaged then
          aValue := 4
        else
          aValue := 0;
        Writer.WriteInteger(aValue);
        Writer.WriteInteger(aDimINfo.iIndex);
        Writer.WriteInteger(aDimInfo.iValue);
      end;
    end;
  Writer.WriteListEnd;
end;

procedure TDecisionSource.BeginChange;
begin
  FChangeCount := FChangeCount + 1;
end;

procedure TDecisionSource.EndChange(Event: TDecisionDataEvent);
begin
  RebuildPivotState;
  if FChangeCount <= 1 then
  begin
    if assigned (FOnBeforePivot) then
    begin
      FOnBeforePivot(self);
      RebuildPivotState;
    end;
    BuildLookups;
    FChangeCount := 0;
    NotifyDataLinks(Event);
    if assigned (FOnAfterPivot) then FOnAfterPivot(self);
  end
  else
    FChangeCount := FChangeCount-1;
end;

procedure TDecisionSource.EnforceConstraints(dimGroup: TDimGroup; PreserveIndex: Integer);
var
  AllXDim: TIArray;
  i: Integer;
  bFound: Boolean;
begin
  Exit;
  AllXDim := FData.DimInfo.GetGroupArray(dimGroup, False);
  if (AllXDim.limit = 0) then Exit;
  {
    Check with xtRadio and xtRadioEx types to be sure that not more than one
    dimension is on.  If PreserveIndex is set to a legal index, try to preserve
    it's state active if it is already so.
  }
  if (FControlType in [xtRadio, xtRadioEx]) then    { at most one can be active }
  begin
    bFound := False;
    if (PreserveIndex >= 0) and (PreserveIndex < AllXDim.limit) then
    begin
      if FData.DimInfo[AllXDim[PreserveIndex]].IState = dmOpen then bFound := True
    end;
    { if Preserve Index not set, let the first one found stay on }
    for i := 0 to AllXDim.limit-1 do
    begin
      if FData.DimInfo[AllXDim[i]].IState = dmOpen then
      begin
        if bFound and (i <> PreserveIndex) then
          FData.DimInfo[AllXDim[i]].IState := dmClosed;
        bFound := True;
      end;
    end;
    {
      if RadioEx, be sure one dimension is turned on.  If possible, preserve
      the state of Preserve Index, but not at the expense of the constraint
    }
    if (FControlType = xtRadioEx) and (not bFound) then
    begin
      if (PreserveIndex <> 0) or (AllXDim.limit = 1) then
        FData.DimInfo[AllXDim[0]].IState := dmOpen
      else
        FData.DimInfo[AllXDim[1]].IState := dmOpen;
    end;
  end;
end;

{
  SetUpData's function is to check to respond to large scale changes in the
  cube state (active/inactive changes, data availability, changes in
  meta data) and to restructure the dimension and row and column info
  as needed.

  SetUpData will not destroy state or pivot information unless
  there is new information to replace it.

  Setup the DecisionData Information, except that which requires pivot state
  FDims: Integer;
  FSums: Integer;
  RowSubs: Boolean;
  ColSubs: Boolean;
  RowSparse: Boolean;
  ColSparse: Boolean;
  DimInfo: TDimInfoArray;

  SetUpData will rebuild the Lookups as needed.
}

procedure TDecisionSource.SetUpData;
var
  I,J,OldI: Integer;
  DM: TCubeDim;
  aDimInfo: pDimInfo;
  OldArray: TDimInfoArray;
  bAccept: Boolean;
begin
  BeginChange;
  if Ready and (DecisionCube.DimensionCount>0) and (DecisionCube.SummaryCount>0) then
    with FData do
    begin
      bAccept := assigned(DimInfo) and (DimInfo.FDimNames.count = 0)
                                   and (DecisionCube.DimensionCount = FDims)
                                   and (DecisionCube.SummaryCount = FSums);
      if (FCurrentSum >= DecisionCube.SummaryCount) then
        FCurrentSum := 0;
      FDims := DecisionCube.DimensionCount;
      FSums := DecisionCube.SummaryCount;
      FActiveROws := 0;
      FActiveCols := 0;
      FAllRows := 0;
      FAllCols := 0;
      FAllPages := 0;
      { set up the diminfo and row and column arrays }
      oldArray := DimInfo;
      DimInfo := TDimInfoArray.Create(FDims);
      for I := 0 to DimInfo.Limit-1 do
      begin
	aDimInfo := DimInfo[i];
	aDimInfo.iValue := 0;
	DM := DecisionCube.DimensionMap[i];
	DimInfo.FDimNames.Add(DM.Fieldname);
	if bAccept then
	begin
	  aDimInfo.iGroup := OldArray[i].iGroup;
	  aDimInfo.iState := OldArray[i].iState;
	  aDimInfo.iValue := OldArray[i].iValue;
          aDimInfo.IIndex := OldArray[i].IIndex;
          aDimInfo.IActiveIndex := OldArray[i].IActiveIndex;
	end
        else if (assigned(oldArray) and OldArray.Find(DM.Fieldname, oldi)) then
	begin
	  aDimInfo.iGroup := OldArray[oldi].iGroup;
	  aDimInfo.iState := OldArray[oldi].iState;
	  aDimInfo.iValue := OldArray[oldi].iValue;
	end
	else if (DM.BinType = Binset) and (DM.StartValue <> '') then
        begin
	  aDimInfo.iState := dmPaged;
        end
	else
        begin
          if FActiveCols = 0 then
          begin
            aDimInfo.iGroup := dgCol;
	    aDimInfo.IState := dmOpen;
	    aDimInfo.iValue := -1;
          end
	  else
          begin
            aDimInfo.iGroup := dgRow;
            aDimInfo.iValue := -1;
	    if FActiveRows = 0 then
	      aDimInfo.IState := dmOpen
  	    else
              aDimInfo.Istate := dmClosed;
          end;
        end;
	if (DM.BinType = Binset) and (DM.StartValue <> '') then
        begin
	  aDimInfo.iState := dmPaged;
	  aDimInfo.IGroup := dgPage;
	  aDimInfo.iValue := 0;
	  for J := 0 to GetDimensionMemberCount(i)-1 do
          begin
	    if GetMemberAsString(i,j) <> DM.BinData.OtherBinName then
            begin
	      aDimInfo.iValue := j;
              break;
	    end;
          end;
        end
        else if (aDimInfo.iGroup = dgPage) then
        begin
          aDimInfo.IGroup := dgRow;
          aDimInfo.iState := dmOpen;
        end;
        { now set the active indexex }
        if not bAccept then
        begin
          if (aDimInfo.iGroup = dgRow) then
          begin
	    aDimInfo.iIndex := FAllRows;
	    FAllRows := FAllRows + 1;
    	    if aDimInfo.iState = dmOpen then
            begin
              aDimInfo.iActiveIndex := FActiveRows;
	      FActiveRows := FActiveRows + 1;
            end
            else
              aDimInfo.iActiveIndex := -1;
          end
          else if aDimInfo.iGroup = dgCol then
          begin
	    aDimInfo.iIndex := FAllCols;
    	    FAllCols := FAllCols + 1;
            if aDimInfo.iState = dmOpen then
            begin
              aDimInfo.iActiveIndex := FActiveCols;
	      FActiveCols := FActiveCols + 1;
            end
            else
              aDimInfo.iActiveIndex := -1;
            end
            else
            begin
	      aDimInfo.iIndex := FAllPages;
              aDimInfo.iActiveIndex := FAllPages;
	      FAllPages := FAllPages + 1;
            end;
          end;
    	end;
	OldArray.free;
        EnforceConstraints(dgRow, -1);
        EnforceConstraints(dgCol, -1);
        {
          finally, the rest of the Decision data structure.  Note the GetExampleRepCount
          depends on the rest being set up
        }
        FRowSubs := True;
    	FColSubs := True;
      end;
  EndChange(xeNewMetaData);
end;

{
  Reset the DimInfo information IIndex and IRowState

  Coming here, RowAllDim and ColAllDim contain the information about
  row and column placement, and DimInfo is correct for everything else.
  This routine brings these two into correspondence, and also resets
  FAllRows, FAllCols, FActiveRows, FActiveCols
}

procedure TDecisionSource.RebuildPivotState;
var
  I, IDim, IActive: Integer;
  aInfo: PDimInfo;
  pState,aState: TDimState;
  AllXDim: TIArray;
begin
  {
    rebuild the lookup tables from the Row and Col Dimension Info
    This needs to be done at every pivot or drill
  }
  if (not Ready) or (FData.FDims = 0) or (FData.FSums = 0) then
    with FData do
    begin
      FActiveRows := 0;
      FActiveCols := 0;
      FAllRows := 0;
      FAllCols := 0;
    end
  else
    with FData do
    begin
      pState := dmNone;
      AllXDim := DimInfo.GetGroupArray(dgRow, False);
      for I := AllXDim.Limit-1 downto 0 do
      begin
        IDim := AllXDim[i];
	aInfo := DimInfo[IDim];
	if pState = dmOpen then
          aInfo.iRowState := [rcNextOpen]
	else if (pState = dmClosed) then
          aInfo.iRowState := [rcNextClosed]
        else aInfo.iRowState := [];
	aState := aInfo.Istate;
    	if (aState = dmClosed) then pState := dmClosed;
    	if (aState = dmOpen) then pState := dmOpen;
      end;
      IActive := 0;
      pState := dmNone;
      for I := 0 to AllXDim.Limit-1 do
      begin
        IDim := AllXDim[i];
	aInfo := DimInfo[IDim];
	if (pState = dmOpen) then
          aInfo.iRowState := aInfo.iRowState + [rcPrevOpen]
	else if (pState = dmClosed) then
          aInfo.iRowState := aInfo.iRowState + [rcPrevClosed];
	aState := aInfo.Istate;
        aInfo.IActiveIndex := -1;
	if (aState = dmOpen) then
        begin
	  aInfo.iRowState := aInfo.iRowState + [rcPrevOpen];
	  aInfo.iActiveIndex := IActive;
	  IActive := IActive + 1;
  	end;
    	if (aState = dmClosed) then pState := dmClosed;
   	if (aState = dmOpen) then pState := dmOpen;
      end;
      FActiveRows := IActive;
      FAllRows := AllXDim.limit;
      AllXDim := DimInfo.GetGroupArray(dgCol, False);
      pState := dmNone;
      for I := AllXDim.Limit-1 downto 0 do
      begin
        IDim := AllXDim[i];
	aInfo := DimInfo[IDim];
        if (pState = dmOpen) then
          aInfo.iRowState := [rcNextOpen]
        else if (pState = dmClosed) then
          aInfo.iRowState := [rcNextClosed]
	else aInfo.iRowState := [];
	aState := aInfo.Istate;
    	if (aState = dmClosed) then pState := dmClosed;
        if (aState = dmOpen) then pState := dmOpen;
      end;
      IActive := 0;
      pState := dmNone;
      for I := 0 to AllXDim.Limit-1 do
      begin
        IDim := AllXDim[i];
	aInfo := DimInfo[IDim];
	if (pState = dmOpen) then
          aInfo.iRowState := aInfo.iRowState + [rcPrevOpen]
	else if (pState = dmClosed) then
          aInfo.iRowState := aInfo.iRowState + [rcPrevClosed];
        aState := aInfo.Istate;
        aInfo.IActiveIndex := -1;
    	if (aState = dmOpen) then
        begin
	  aInfo.iActiveIndex := IActive;
	  IActive := IActive + 1;
  	end;
    	if (aState = dmClosed) then pState := dmClosed;
    	if (aState = dmOpen) then pState := dmOpen;
      end;
      FActiveCols := IActive;
      FAllCols := AllXDIm.limit;
      { Now initialize the summaries to reflect the correct FActiveSum }
      if FCurrentSum >= FSums then FCurrentSum := 0;
    end;
end;

procedure TDecisionSource.BuildLookups;
var
  iDim: Integer;
  I: Integer;
  RowDim, ColDim: TIntArray;
begin
  {
    rebuild the lookup tables from the Row and Col Dimension Info
    This needs to be done at every pivot or drill
  }
  if (not Ready) or (FData.FDims = 0) or (FData.FSums = 0) then
  begin
    FRowMax := 1;
    FColMax := 1;
    RowLookup.free;
    ColLookup.Free;
    RowLookup := nil;
    ColLookup := nil;
  end
  else
    with FData do
    begin
      { Now initialize the summaries to reflect the correct FActiveSum }
      if (FCurrentSum >= FSums) then
        FCurrentSum := 0;
      DecisionCube.SetCurrentSummary(FCurrentSum);
      if Ready and ((FState = dcBrowseAllData)  or (FState = dcBrowseMemberData)) then
      begin
        RowDim := TIntArray.Create(0,0);
	ColDim := TIntArray.Create(0,0);
	try
	  iDim := 0;
	  for i := 0 to FActiveRows-1 do
            RowDim.InsertAt(0,iDim);
          for i := 0 to FActiveCols-1 do
            ColDim.InsertAt(0,iDim);
	  for i := 0 to DimInfo.limit-1 do
          begin
	    if (DimInfo[i].iState = dmOpen) then
            begin
	      if (DimInfo[i].iGroup = dgRow) then
              begin
	        assert(DimInfo[i].iActiveIndex < FActiveRows, 'Error is active rows');
                if (DimInfo[i].iActiveIndex >= FActiveRows) then
                  raise exception.createRes(@sRowError);
                RowDim[DimInfo[i].iActiveIndex] := i;
	      end;
	      if (DimInfo[i].iGroup = dgCol) then
              begin
	        assert(DimInfo[i].iActiveIndex < FActiveCols, 'Error is active cols');
                if (DimInfo[i].iActiveIndex >= FActiveCols) then
                  raise exception.createRes(@sRowError);
                ColDim[DimInfo[i].iActiveIndex] := i;
              end;
            end;
          end;
	  RowLookup.free;
	  RowLookup := nil;
    	  ColLookUp.free;
      	  ColLookUp := nil;
       	  RowLookup := TTwoDimArray.Create;
          ColLookup := TTwoDimArray.Create;
          if (FState <> dcBrowseAllData) then
            FDecisionCube.Sparsing := False
	  else
            FDecisionCube.Sparsing := not FRowSparse;
          FRowMax := FDecisionCube.GetDomain(RowDim,FRowSubs,RowLookup);
	  if (FState <> dcBrowseAllData) then
            FDecisionCube.Sparsing := False
	  else
            FDecisionCube.Sparsing := not FColSparse;
	  FColMax := FDecisionCube.GetDomain(ColDim,FColSubs,ColLookup);
	finally
	  RowDim.free;
	  ColDim.free;
	end;
      end
      else if Ready and (FState = dcBrowseMetaData) then
      begin
        FRowMax := 1;
        if (FActiveCols = 0) then
          FColMax := 1
        else
          FColMax := FActiveCols;
	RowLookup.free;
	ColLookup.Free;
	RowLookup := nil;
        ColLookup := nil;
      end
      else
      begin
	FRowMax := 1;
    	FColMax := 1;
	RowLookup.free;
	ColLookup.Free;
	RowLookup := nil;
        ColLookup := nil;
      end;
    end;
end;

procedure TDecisionSource.FetchPivotState(var FState: TPivotState);
begin
  FState.Assign(FData);
end;

procedure TDecisionSource.StorePivotState(FState: TPivotState);
begin
  BeginChange;
  ProcessPivotState(FState);
  EndChange(xeNewMetaData);
end;

procedure TDecisionSource.ProcessPivotState(FState: TPivotState);
var
  i: Integer;
  aDimInfo: PDimInfo;
begin
  with FData do
  begin
    FDims := FState.FDims;
    if not assigned(DimInfo) then
      DimInfo := TDimInfoArray.create(FDims);
    DimInfo.Assign(FState.DimInfo);
    FCurrentSum := FState.FCurrentSum;
    FSums := FState.FSums;
    FRowSparse := FState.FRowSparse;
    FColSparse := FState.FColSparse;
    FRowSubs := True;
    FColSubs := True;
    FAllRows := 0;
    FAllCols:= 0;
    FActiveRows:= 0;
    FActiveCols:= 0;
    for i := 0 to DimInfo.limit -1 do
    begin
      aDimInfo := DimInfo[i];
      if aDimInfo.iGroup = dgRow then
      begin
        FAllRows:= FAllRows + 1;
        if (aDimInfo.IState = dmOpen) then
          FActiveRows := FActiveRows + 1;
      end;
      if (aDimInfo.iGroup = dgCol) then
      begin
        FAllCols := FAllCols + 1;
        if (aDimInfo.IState = dmOpen) then
          FActiveCols := FActiveCols + 1;
      end;
    end;
    FDims := FAllRows + FAllCols;
    SetupData;
  end;
end;

procedure TDecisionSource.AddDataLink(Link: TDecisionDataLink);
begin
  FDecisionDataLinks.Add(Link);
  Link.FDecisionSource := Self;
end;

procedure TDecisionSource.RemoveDataLink(Link: TDecisionDataLink);
begin
  link.FDecisionSource := nil;
  FDecisionDataLinks.Remove(Link);
end;

procedure TDecisionSource.NotifyDataLinks(Event: TDecisionDataEvent);
var
  I: Integer;
begin
  if (FChangeCount > 0) then Exit;
  for I := FDecisionDataLinks.Count - 1 downto 0 do
    with TDecisionDataLink(FDecisionDataLinks[I]) do
    begin
      DecisionDataEvent(Event);
    end;
    if (csDesigning in ComponentState) and not (csLoading in ComponentState) then
    begin
      if Event in [xePivot, xeSummaryChanged] then
      begin
        UpdateDesigner(self);
      end;
    end;
    case Event of
      xePivot:
      begin
        if assigned(FOnLayoutChange) then
          FOnLayoutChange(self);
      end;
      xeNewMetaData:
      begin
        if assigned(FOnNewDimensions) then
          FOnNewDimensions(self);
      end;
      xeStateChanged:
      begin
        if assigned (FOnStateChange) then
          FOnStateChange(self);
      end;
      xeSummaryChanged:
      begin
        if assigned(FOnSummaryChange) then
          FOnSummaryChange(self);
      end;
    end;
end;

{
  Pivoting functions

  open the first inactive row/col to the immediate right of the Active row/col = Index
  if Index = -1, it means open the first row
}

procedure TDecisionSource.OpenDimIndexRight(dimGroup: TDimGroup; Index: Integer; bOpen: Boolean);
var
  i,j: Integer;
  aDimInfo: PDimInfo;
  AllXDim: TIArray;
begin
  with FData do
  begin
    if (Index < 0) then
      i := -1
    else
      i := DimInfo.GetGroupItem(dimGroup,Index,bOpen).iIndex;
    AllXDim := DimInfo.GetGroupArray(dimGroup, False);
    if (i < AllXDim.Limit-1) then
    begin
      for j := i+1 to AllXDim.limit-1 do
      begin
        aDimInfo := DimInfo[AllXDim[j]];
	if (aDimInfo.IState = dmClosed) then
        begin
	  BeginChange;
	  aDimInfo.IState := dmOpen;
	  aDimInfo.IValue := 0;
          EnforceConstraints(dimGroup, j);
          EndChange(xePivot);
      	  Exit;
	end;
      end;
    end;
  end;
end;

{
  close all active rows/cols to the immediate right of the Active row/col = Index
  if Index = -1, it means start with the first row/col
}

procedure TDecisionSource.CloseDimIndexRight(dimGroup: TDimGroup; Index: Integer; bOpen: Boolean);
var
  i,j,count: Integer;
  aDimInfo: PDimInfo;
  AllXDim: TIArray;
begin
  with FData do
  begin
    if (Index = -1) then
      i := -1
    else
      i := DimInfo.GetGroupItem(dimGroup,Index,bOpen).iIndex;
    count := 0;
    AllxDim := DimInfo.GetGroupArray(dimGroup, True);
    if (i < AllxDim.Limit-1) then
    begin
      for j := i+1 to AllxDim.limit-1 do
      begin
        aDimInfo := DimInfo[AllxDim[j]];
        if (aDimInfo.IState = dmOpen) then
        begin
          if (count = 0) then
            BeginChange;
          aDimInfo.IState := dmClosed;
          aDimInfo.IValue := 0;
          count := count + 1;
        end;
      end;
      if (count > 0) then
      begin
        EnforceConstraints(dimGroup, -1);
        EndChange(xePivot);
      end;
    end;
  end;
end;

procedure TDecisionSource.OpenDimIndexLeft(dimGroup: TDimGroup; Index: Integer; bOpen: Boolean);
var
  i,j: Integer;
  aDimInfo: PDimInfo;
  Allxdim: TIArray;
begin
  with FData do
  begin
    i := DimInfo.GetGroupItem(dimGroup,Index,bOpen).iIndex;
    if (i < 1) then Exit;
    AllxDim := DimInfo.GetGroupArray(dimGroup, False);
    if (dimGroup = dgRow) then
    begin
      for j := i-1 downto 0 do
      begin
        aDimInfo := DimInfo[AllxDim[j]];
        if aDimInfo.IState = dmClosed then
        begin
          BeginChange;
          aDimInfo.IState := dmOpen;
          aDimInfo.IValue := 0;
          EnforceConstraints(dimGroup, j);
          EndChange(xePivot);
        end;
      end;
    end;
  end;
end;

procedure TDecisionSource.ToggleDimIndex(dimGroup: TDimGroup; Index: Integer; bOpen: Boolean);
var
  aDimInfo: PDimInfo;
  iDim: Integer;
begin
  with FData do
  begin
    iDim := GetActiveDim(dimGroup, Index, bOpen);
    if (iDim >= 0) then
    begin
      aDimInfo := Diminfo[iDim];
      if aDimInfo.IState = dmPaged then Exit;
      BeginChange;
      if (aDimInfo.IState = dmOpen) then
        aDimInfo.IState := dmClosed
      else
      begin
        aDimInfo.IState := dmOpen;
	aDimInfo.IValue := 0;
      end;
      EnforceConstraints(aDimInfo.IGroup, aDimInfo.IIndex);
      EndChange(xePivot);
    end;
  end;
end;

{ Data Access Functions }

function  TDecisionSource.GetReady: Boolean;
begin
  Result := bActivated;
end;

function  TDecisionSource.GetDataAsString(ARow, ACol: Integer; var SubLevel: Integer): String;
var
  I, iLook: Integer;
  DI: pDimInfo;
  Coord: TSmallIntArray;
begin
  if Ready and (FState = dcBrowseAllData) then
    with FData do
    begin
      Coord := TSmallIntArray.Create(FDims, 0);
      try
        SubLevel := 0;
        for i := 0 to FData.DimInfo.limit-1 do
        begin
          DI := DimInfo[i];
          if (DI.IState = dmOpen) and (DI.iGroup = dgRow) then
          begin
            iLook := RowLookup[DI.iActiveIndex, aRow];
            if (iLook = Subtotal) then SubLevel := SubLevel + 1;
          end
          else if (DI.IState = dmOpen) and (DI.iGroup = dgCol) then
          begin
            iLook := ColLookup[DI.iActiveIndex, aCol];
            if (iLook = Subtotal) then SubLevel := SubLevel + 1;
          end
          else if (DimInfo[I].IState in [dmDrilled, dmPaged]) then
            iLook := DimInfo[I].IValue
          else
            iLook := subtotal;
          Coord[i] := iLook;
        end;
        Result := FDecisionCube.GetSummaryAsString(Coord);
      finally
        Coord.free;
      end;
  end
  else
    Result := '';
end;

function TDecisionSource.GetMemberAsString(iDim: Integer; ValueIndex: Integer): String;
begin
  if Ready and ((FState = dcBrowseAllData) or (FState = dcBrowseMemberData)) then
    Result := FDecisionCube.GetMemberAsString(iDim, ValueIndex)
  else
    Result := '';
end;

function TDecisionSource.GetMemberAsVariant(iDim: Integer; ValueIndex: Integer): Variant;
begin
  if Ready and ((FState = dcBrowseAllData) or (FState = dcBrowseMemberData)) then
    Result := FDecisionCube.GetMemberAsVariant(iDim, ValueIndex)
  else
    Result := '';
end;

function TDecisionSOurce.GetSummaryName(iSum: Integer): String;
begin
  if Ready then
    Result := FDecisionCube.GetSummaryName(iSum)
  else
    Result := '';
end;

procedure TDecisionSource.SetCurrentSummary(Value: Integer);
begin
  if assigned(DecisionCube) and (Value < DecisionCube.SummaryCount) and (Value >= 0) then
  begin
    DecisionCube.SetCurrentSummary(Value);
  end;
  FData.FCurrentSum := Value;
  NotifyDataLinks(xeSummaryChanged);
end;

function  TDecisionSource.GetDimensionName(iDim: Integer): String;
begin
  Result := '';
  if Ready then
    Result := FDecisionCube.GetDimensionName(iDim);
end;

function TDecisionSource.GetDimensionMemberCount(iDim: Integer): Integer;
begin
  if Ready and ((FState = dcBrowseAllData) or (FState = dcBrowseMemberData)) then
    Result := FDecisionCube.GetDimensionMemberCount(iDim)
  else
    Result := 0;
end;

function  TDecisionSource.GetDataAsVariant(ARow, ACol: Integer; var SubLevel: Integer): Variant;
var
  I, iLook: Integer;
  DI: pDimInfo;
  Coord: TSmallIntArray;
begin
  if Ready and (FState = dcBrowseAllData) then
    with FData do
    begin
      Coord := TSmallIntArray.Create(FDims, 0);
      try
        SubLevel := 0;
	for i := 0 to FData.DimInfo.limit-1 do
      	begin
	  DI := DimInfo[i];
	  if (DI.IState = dmOpen) and (DI.iGroup = dgRow) then
          begin
            iLook := RowLookup[DI.iActiveIndex, aRow];
	    if (iLook = Subtotal) then SubLevel := SubLevel + 1;
          end
          else if (DI.IState = dmOpen) and (DI.iGroup = dgCol) then
          begin
            iLook := ColLookup[DI.iActiveIndex, aCol];
	    if (iLook = Subtotal) then SubLevel := SubLevel + 1;
	  end
	  else if (DimInfo[I].IState in [dmDrilled, dmPaged]) then
            iLook := DimInfo[I].IValue
          else
            iLook := subtotal;
	  Coord[i] := iLook;
	end;
	Result := FDecisionCube.GetSummaryAsVariant(Coord);
      finally
	Coord.free;
      end;
    end
  else
    Result := '';
end;

function TDecisionSource.Get2DDataAsVariant(iDimA, iDimB: Integer;
         aValueIndex, bValueIndex: Integer): Variant;
var
  I: Integer;
  Coord: TSmallIntArray;
begin
  if Ready and (FState = dcBrowseAllData) then
    with FData do
    begin
      Coord := TSmallIntArray.Create(FDims, 0);
      try
        for I := 0 to Coord.Limit-1 do
        begin
          if (DimInfo[I].IState in [dmDrilled, dmPaged]) then
            Coord[I] := DimInfo[I].IValue
          else if (I = iDimA) then
            Coord[i] := aValueIndex
          else if (I = iDimB) then
            Coord[i] := bValueIndex
          else
            Coord[I] := Subtotal;
        end;
	Result := FDecisionCube.GetSummaryAsVariant(Coord);
      finally
	Coord.free;
      end;
    end
  else
    Result := 0;
end;

function TDecisionSource.GetValueIndex(dimGroup: TDimGroup; Index: Integer; Cell:
         Integer; var isBreak: Boolean; var isSum: Boolean) : Integer;
var
  I,J,Temp: Integer;
  subs: Boolean;
  LastVal: Integer;
begin
  with FData do
    if (dimGroup = dgRow) then
      subs := FrowSubs
    else
      subs := FcolSubs;
  if Ready and (FState = dcBrowseAllData) or (FState = dcBrowseMemberData) then
  begin
    if (dimGroup = dgRow) then
      Result := RowLookup[Index,Cell]
    else
      Result := ColLookup[Index,Cell];
    if (Result < 0) then
      isSum := True
    else
      isSum := False;
    if (Cell = 0) then
      isBreak := True
    else
    begin
      if (dimGroup = dgRow) then
        LastVal := RowLookup[Index,Cell-1]
      else
        LastVal := ColLookup[Index,Cell-1];
      isBreak := Result <> LastVal;
    end;
  end
  else
  begin
    Temp := Cell;
    for I := 0 to Index do
    begin
      j := GetExampleRepCount(dimGroup, I);
      Temp := Temp mod j;
      if (Temp = j-1) then
        if subs then
	begin
	  isSum := True;
          if (I = Index) then
            isBreak := True
          else
            isBreak := False;
	  Result := Subtotal;
          Exit;
        end;
    end;
    j := GetExampleRepCount(dimGroup, Index+1);
    if ((Temp mod j) = 0) then
      isBreak := True
    else
      isBreak := False;
    Temp := Temp div j;
    Result := Temp;
    isSum := False;
  end;
end;

{
  Find the extent of the Group (including the sum) which is within Row or Column
  Dimension Index and at the Position Cell.
}

function TDecisionSource.GetGroupExtent(dimGroup: TDimGroup; Index: Integer; Cell: Integer): TDimRange;
var
  isBreak, isSum: Boolean;
  iMax: Integer;
begin
  Result.Last := Cell;
  Result.First := Cell;
  isBreak := False;
  {  Scan backward for the first group break which is not a sum }
  while (Result.First > 0) and (not isBreak) do
  begin
    GetValueIndex(dimGroup,Index,Result.First,isBreak,isSum);
    if (not isBreak) then
      Result.First := Result.First - 1;
  end;
  { Scan forward for the first break, then back off }
  if (dimGroup = dgRow) then
    iMax := FRowMax
  else
    iMax := FColMax;
  isBreak := False;
  while (Result.Last < iMax-1) and (not isBreak) do
  begin
    GetValueIndex(dimGroup,Index,Result.Last+1,isBreak,isSum);
    if (not isBreak) then
      Result.Last := Result.Last + 1;
  end;
end;

{
  These are the functions which are calls to the data cube through the source.
  They are not allowed if the source is not active.
}

function TDecisionSource.GetValueArray(ACol, ARow: Integer; var ValueArray: TSmallIntArray): Boolean;
var
  i: Integer;
begin
  with FData do
  begin
    ValueArray.clear;
    for i := 0 to FDims-1 do
    begin
      if (DimInfo[i].iState in [dmDrilled, dmPaged]) then
        ValueArray.Add(DimInfo[i].iValue)
      else if (DimInfo[i].iState = dmClosed) then
        ValueArray.add(subtotal)
      else if (DimInfo[i].iGroup = dgRow) then
      begin
        if (ARow < 0) then
          ValueArray.add(subtotal)
        else
          ValueArray.add(RowLookup[DimInfo[i].iActiveIndex, ARow]);
      end
      else
      begin
        if (ACol < 0) then
          ValueArray.add(subtotal)
        else
          ValueArray.add(ColLookup[DimInfo[i].iActiveIndex, ACol]);
      end;
    end;
    Result := True;
  end;
end;

function TDecisionSource.GetDecisionCube: TDecisionCube;
begin
  Result := FDecisionCube;
end;

procedure TDecisionSource.SetDecisionCube(Value: TDecisionCube);
begin
  if (FDecisionCube <> Value) then
  begin
    if (FDecisionCube <> nil) then
      FDecisionCube.RemoveDataSource(Self);
    if (Value <> nil) then
    begin
      Value.AddDataSource(Self);
    end;
    FDecisionCube := Value;
    DecisionDataEvent(xeStateChanged);
  end;
end;

procedure TDecisionSource.DecisionDataEvent(Event: TDecisionDataEvent);
begin
  if FBlocked then Exit;
  FBlocked := True;
  if (Event = xeStateChanged) then
  begin
    if not assigned(DecisionCube) then
    begin
      bActivated := False;
    end
    else
    begin
      FState := DecisionCube.State;
      if (FState = dcInactive) then
        bActivated := False
      else
        bActivated := True;
      SetUpData;
    end;
  end;
  NotifyDataLinks(Event);
  FBlocked := False;
end;

{ TDecisionDataLink }

constructor TDecisionDataLink.Create;
begin
  FBlocked := False;
end;

destructor TDecisionDataLink.Destroy;
begin
  SetDecisionSource(nil);
  inherited Destroy;
end;

procedure TDecisionDataLink.DecisionDataEvent(Event: TDecisionDataEvent);
begin
end;

procedure TDecisionDataLink.SetDecisionSource(source: TDecisionSource);
begin
  if (FDecisionSource <> Source) then
  begin
    if (FDecisionSource <> nil) then
      FDecisionSource.RemoveDataLink(Self);
    if (Source <> nil) then Source.AddDataLink(Self);
    FDecisionSource := source;
    DecisionDataEvent(xeSourceChange);
  end;
end;

{ TDimInfoArray }

constructor tDimInfoArray.Create(ALimit: Integer);
begin
  FLimit := ALimit;
  GetMem(FElements,FLimit*SizeOf(TDimInfo));
  FDimNames := TStringList.Create;
end;

destructor TDimInfoArray.Destroy;
begin
  AllXDim.free;
  FreeMem(FElements);
  FDimNames.free;
  FDimNames := nil;
  inherited;
end;

procedure TDimInfoArray.Assign(Value: TDimInfoArray);
begin
  if (FLimit <> Value.Flimit) then
  begin
    FreeMem(FElements);
    FElements := nil;
    FLimit := Value.Flimit;
    GetMem(FElements,Flimit*SizeOf(TDimInfo));
  end;
  CopyMemory(FElements,Value.FElements,FLimit * SizeOf(TDimInfo));
  FDimNames.assign(Value.FDimNames);
end;

function TDimInfoArray.isEqual(Value: TDimInfoArray): Boolean;
var
  i: Integer;
  ptr1, ptr2: pchar;
begin
  Result := False;
  if (FLimit <> Value.FLimit) then Exit;
  ptr1 := pChar(FElements);
  ptr2 := pChar(Value.FElements);
  for i := 0 to (sizeOf(TDimInfo)*FLimit)-1 do
  begin
    if (@ptr1 <> @ptr2) then Exit;
    ptr1 := ptr1 + 1;
    ptr2 := ptr2 + 1;
  end;
  Result := True;
end;

function TDimInfoArray.GetGroupIndex(Group: TDimGroup; Index: Integer; bOpen: Boolean): Integer;
var
  i: Integer;
begin
  for i := 0 to limit-1 do
  begin
    if (items[i].iGroup <> Group) then Continue;
    if bOpen then
    begin
      if (items[i].iActiveIndex <> index) then Continue;
    end
    else
    begin
      if (items[i].iIndex <> index) then Continue;
    end;
    Result := i;
    Exit;
  end;
  Result := -1;
end;

function TDimInfoArray.GetGroupItem(Group: TDimGroup; Index: Integer; bOpen: Boolean): PDimInfo;
var
  i: Integer;
begin
  i := GetGroupIndex(Group, Index, bOpen);
  if (i < 0) then
    Result := nil
  else
    Result := items[i];
end;

function TDimInfoArray.GetGroupSize(Group: TDimGroup; bOpen: Boolean): Integer;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to limit-1 do
  begin
    if (items[i].iGroup <> Group) then Continue;

    if bOpen then
    begin
      if (items[i].iState <> dmOpen) then Continue;
    end;
    Result := Result + 1;
  end;
end;

function TDimInfoArray.GetGroupArray(Group: TDimGroup; bOpen: Boolean): TIArray;
var
  i: Integer;
begin
  if not assigned(AllXDim) then AllXDim := TIArray.create(0, 0);
  Result := AllXDim;
  Result.ReAlloc(0);
  Result.AutoSize := True;
  if bOpen then
  begin
    for i := 0 to limit-1 do
    begin
      if (Items[i].iGroup = Group) and (Items[i].iState = dmOpen) then
      begin
        Result[Items[i].iActiveIndex] := i;
      end;
    end;
  end
  else
  begin
    for i := 0 to limit-1 do
    begin
      if (items[i].iGroup = Group) then
        Result[items[i].iIndex]:= i;
    end;
  end;
  Result.autosize := False;
end;

function TDimInfoArray.GetItem(Index: Integer): PDimInfo;
begin
  if (Index < 0) or (Index >= FLimit) then
    raise EArrayError.CreateRes(@sOutOfbounds)
  else
    Result := @PArrayDimInfo(FElements)^[Index];
end;

function TDimInfoArray.Find(Name: string; var pos: Integer): Boolean;
var
  i: Integer;
begin
  for i := 0 to FDimNames.count-1 do
  begin
    if (FDimNames[i] = Name) then
    begin
      pos := i;
      Result := True;
      Exit;
    end;
  end;
  Result := False;
end;

constructor TIArray.Create(ALimit: Integer; aBlocksize: Integer);
begin
  if (aBlocksize <= 0) then
    FBlockSize := defDimSize
  else
    FBlockSize := aBlockSize;
  Alloc(ALimit);
end;

destructor TIArray.Destroy;
begin
  FreeMem(FElements);
  inherited;
end;

procedure TIArray.Alloc(ALimit: Integer);
begin
  FreeMem(FElements);
  FLimit := ALimit;
  if (FBlocksize = 1) then
    FCapacity := ALimit
  else
    FCapacity := ((FLimit div FBlocksize) + 1) * FBlocksize;
  GetMem(FElements,FCapacity * SizeOf(Integer));
end;

procedure TIArray.Realloc(ALimit: Integer);
var
  L: Integer;
  P: Pointer;
begin
  if (ALimit > FCapacity) or (ALimit < (FCapacity-FBlocksize)) then
  begin
    L := Min(FLimit,ALimit);
    P := FElements;
    FElements := nil;
    Alloc(ALimit);
    CopyMemory(FElements,P,L * SizeOf(Integer));
    FreeMem(P);
  end;
  FLimit := ALimit;
end;

procedure TIArray.Assign(Value: TIArray);
begin
  if (FLimit <> Value.FLimit) then
    Alloc(Value.FLimit);
  CopyMemory(FElements,Value.FElements,FLimit * SizeOf(Integer));
end;

function TIArray.GetItem(Index: Integer): Integer;
begin
  if (FElements = nil) or (Index < 0) or (Index >= FLimit) then
    raise EArrayError.CreateRes(@sOutOfbounds);
  Result := PArrayInt(FElements)^[Index];
end;

procedure TIArray.SetItem(Index: Integer; Value: Integer);
begin
  if (FElements = nil) or (Index < 0) or (Index >= FLimit) then
  begin
    if (FElements <> nil) and FAutoIncr and (Index >= FLimit) then
      Realloc(Index + 1)
    else
      raise EArrayError.CreateRes(@sOutOfbounds);
  end;
  PArrayInt(FElements)^[Index] := Value;
end;

procedure TIArray.InsertAt(Index: Integer; Value: Integer);
begin
  if (Index < 0) or (Index > FLimit) then
    raise EArrayError.CreateRes(@sOutOfbounds);
  Realloc(FLimit+1);
  if (Index+1 < FLimit) then
    CopyMemory(@PArrayInt(FElements)^[Index+1], @PArrayInt(FElements)^[Index], (FLimit-Index-1) * SizeOf(Integer));
  SetItem(Index,Value);
end;

function TIArray.RemoveItem(Index: Integer): Integer;
begin
  if (Index < 0) or (Index+1 > FLimit) then
    raise EArrayError.CreateRes(@sOutOfbounds);
  Result := GetItem(Index);
  if ((Index + 1) < FLimit) then
    CopyMemory(@PArrayInt(FElements)^[Index], @PArrayInt(FElements)^[Index+1], (FLimit-Index-1) * SizeOf(Integer));
  Realloc(FLimit-1);
end;

function TDecisionSource.GetExampleRepCount(dimGroup: TDimGroup; level: Integer): Integer;
var
  max, times: Integer;
  subs: Boolean;
  Elements: array[0..4] of Integer;
begin
  Elements[0] := 2;
  Elements[1] := 3;
  Elements[2] := 4;
  Elements[3] := 3;
  Elements[4] := 2;
  with FData do
  begin
    if (dimGroup = dgRow) then
    begin
      max := fActiveRows;
      subs := FrowSubs;
    end
    else
    begin
      max := fActiveCols;
      subs := FcolSubs;
    end;
    if (level >= max) then Result := 1
    else
    begin
      times := Elements[GetActiveDim(dimGroup, level,True)];
      Result := GetExampleRepCount(dimGroup, level+1)*times;
      if subs then Result := Result + 1;
    end;
  end;
end;

{ Row/Col oriented Access Functions }

function TDecisionSource.GetActiveDim(dimGroup: TDimGroup; index: Integer; bOpen: Boolean): Integer;
begin
  Result := FData.DimInfo.GetGroupIndex(dimGroup, Index, bOpen);
end;

procedure TDecisionSource.DrillDimIndex(dimGroup: TDimGroup; Index: Integer; ValueIndex: Integer; bOpen: Boolean);
var
  iDim: Integer;
begin
  with FData do
  begin
    iDim := GetActiveDim(dimGroup, Index, bOpen);
    if (iDim >= 0) then DrillValue(iDim, ValueIndex);
  end;
end;

procedure TDecisionSource.MoveDimIndexes(SdimGroup, DdimGroup: TDimGroup; SIndex, DIndex: Integer; bOpen: Boolean);
var
  Index, i: Integer;
  iDim, sDim, dDim: Integer;
  AllXDim: TIArray;
begin
  with FData do
  begin
    if (SdimGroup = DdimGroup) and (SIndex = DIndex) then Exit;
    sDim := GetActiveDim(SdimGroup, sIndex, bOpen);
    dDim := GetActiveDim(DdimGroup, dIndex, bOpen);
    BeginChange;
    AllXDim := DimInfo.GetGroupArray(SdimGroup, False);
    Index := DimInfo[sDim].iIndex;
    for i := 0 to AllXDim.limit-1 do
    begin
      iDim := AllXDim[i];
      if (DimInfo[iDim].iIndex > index) then
        DimInfo[iDim].iIndex := DimInfo[iDim].iIndex - 1;
    end;
    AllXDim := DimInfo.GetGroupArray(DdimGroup, False);
    if (dDim < 0) or (DIndex >= AllXDim.Limit) then
      Index := AllXDim.Limit
    else
      index := DimInfo[dDim].iIndex;
    for i := 0 to AllxDim.limit-1 do
    begin
      iDim := AllXDim[i];
      if (DimInfo[iDim].iIndex >= index) then
        DimInfo[iDim].iIndex := DimInfo[iDim].iIndex + 1;
    end;
    DimInfo[sDim].iGroup := DdimGroup;
    DimInfo[sDim].iIndex := Index;
    EnforceConstraints(DdimGroup, Index);
    if (DdimGroup <> SdimGroup) then
      EnforceConstraints(SdimGroup, -1);
    EndChange(xePivot);
  end;
end;

procedure TDecisionSource.SwapDimIndexes(SdimGroup, DdimGroup: TDimGroup; SIndex, DIndex: Integer; bOpen: Boolean);
var
  Index: Integer;
  sDim, dDim: Integer;
begin
  with FData do
  begin
    if (SdimGroup = DdimGroup) and (SIndex = DIndex) then Exit;
    sDim := GetActiveDim(SdimGroup, sIndex, bOpen);
    dDim := GetActiveDim(DdimGroup, dIndex, bOpen);
    BeginChange;
    DimInfo[sDim].iGroup := DdimGroup;
    index := DimInfo[sDim].iIndex;
    DimInfo[sDim].iIndex := DimInfo[dDim].iIndex;
    DimInfo[dDim].iGroup := SdimGroup;
    DimInfo[dDim].iIndex := index;
    EnforceConstraints(DdimGroup, Index);
    if (DdimGroup <> SdimGroup) then
      EnforceConstraints(SdimGroup, -1);
    EndChange(xePivot);
  end;
end;

procedure TDecisionSource.DrillValue(iDim: Integer; ValueIndex: Integer);
var
  PreserveIndex: Integer;
begin
  assert(ValueIndex<GetDimensionMemberCount(iDim), 'Illegal value selected');
  if (iDim >= 0) then
    with FData do
    begin
      if (DimInfo[iDim].istate = dmPaged) then Exit;
      BeginChange;
      DimInfo[iDim].IValue := ValueIndex;
      if (DimInfo[iDim].Istate <> dmPaged) then
        DimInfo[iDim].IState := dmDrilled;
      PreserveIndex := DimInfo[iDim].IIndex;
      EnforceConstraints(DimInfo[iDim].IGroup, PreserveIndex);
      EndChange(xePivot);
    end;
end;

constructor TPivotState.Create;
begin
  DimInfo := TDimInfoArray.Create(0);
  FSums := 0;
  FDims := 0;
  FCurrentSum := 0;
  FRowSparse := False;
  FRowSubs := True;
  FColSparse := False;
  FColSubs := True;
end;

destructor TPivotState.Destroy;
begin
  DimInfo.free;
  DimInfo := nil;
  inherited;
end;

procedure TPivotState.Assign(Value: TPivotState);
begin
  FDims := Value.FDims;
  FSums := Value.FSums;
  FCurrentSum := Value.FCurrentSum;
  FRowSparse := Value.FRowSparse;
  FColSparse := Value.FColSparse;
  FRowSubs := Value.FRowSubs;
  FColSubs := Value.FColSubs;
  DimInfo.Assign(Value.DimInfo);
end;

function TPivotState.IsEqual(Value: TPivotState): Boolean;
begin
  Result := False;
  if (FDims <> Value.FDims) then Exit;
  if (FSums <> Value.FSums) then Exit;
  if (FCurrentSum <> Value.FCurrentSum) then Exit;
  if (FRowSparse <> Value.FRowSparse) then Exit;
  if (FColSparse <> Value.FColSparse) then Exit;
  if (FRowSubs <> Value.FRowSubs) then Exit;
  if (FColSubs <> Value.FColSubs) then Exit;
  Result := DimInfo.isEqual(Value.DimInfo);
end;

end.

