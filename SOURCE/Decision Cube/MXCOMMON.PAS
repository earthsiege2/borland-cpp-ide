{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxcommon;

interface

uses
  dialogs, Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  inifiles, db, dbtables, dbcommon, bde, mxarrays, mxconsts;

type
  EDimensionMapError = class(Exception);

  TQueryError = (tqeOK, tqeNoDimensions, tqeNoAggs, tqeNotGrouped,
  		 tqeNotInitialized, tqeMapCorrupt, tqeUnKnownDims);

  TBinType = (binNone, binYear, binQuarter, binMonth, binSet, binCustom);
  TBinTypes = set of TBinType;

  TActiveFlags = (diActive, diAsNeeded, diInactive);

  TDimFlags = (dimDimension, dimSum, dimCount, dimAverage, dimMin, dimMax, dimGenericAgg, dimUnknown);

  TCDNotifyType = (tdChanged);

  TDimensionItem = class(TCollectionItem)
  private
    FDerivedFrom: Integer;
    FFormat: String;
    FName: String;
    FFieldName: String;
    FBaseName: String;
    FFieldType: TFieldType;
    FActive: Boolean;
    FActiveFlag:  TActiveFlags;
    FOwner: TCollection;
    FType:  TDimFlags;
    procedure SetName(Value: string);
    procedure SetBaseName(Value: string);
    procedure SetFieldName(Value: string);
    procedure SetDerivedFrom(Value: Integer);
    procedure SetFormat(Value: String);
    procedure SetFieldType(Value: TFieldType);
    procedure SetType( Value: TDimFlags );
    procedure SetActive(Value: Boolean);
    procedure SetActiveFlag( Value: TActiveFlags );
  protected
    procedure InitializeRange; virtual;
    procedure NotifyCollection(aType: TCDNotifyType); virtual;
    property Active: Boolean read FActive write SetActive;
    property Owner: TCollection read FOwner;
  public
    constructor Create(Collection: TCollection); override;
    procedure Assign(Value: TPersistent); override;
    function IsDimension: Boolean;
    function IsSummary: Boolean;
  published
    property ActiveFlag: TActiveFlags read FActiveFlag write SetActiveFlag;
    property Format: String read FFormat write SetFormat;
    property FieldType: TFieldType read FFieldType write SetFieldType;
    property Fieldname: string read Ffieldname write Setfieldname;
    property BaseName: string read FBaseName write setBaseName;
    property Name: string read FName write SetName;
    property DerivedFrom: Integer read FDerivedFrom write SetDerivedFrom;
    property DimensionType: TDimFlags read FType write SetType;
  end;

  TDimensionItemClass = class of TDimensionItem;

  TDimensionItems = class(TCollection)
  private
    FOwner: TPersistent;
    bQuiet: Boolean;
    function GetDimensionItem(Index: Integer): TDimensionItem;
    procedure SetDimensionItem(Index: Integer; Value: TDimensionItem);
    function GetDimCount: Integer;
    function GetSumCount: Integer;
    function GetActiveDimCount: Integer;
    function GetActiveSumCount: Integer;
  protected
    function GetOwner: TPersistent; override;
    procedure NotifyOwner(aType: TCDNotifyType);
  public
    constructor Create(Owner: TPersistent; ItemClass: TDimensionItemClass);
    function Add: TDimensionItem;
    procedure Assign(Source: TPersistent); override;
    function AddDerivedField(Index: Integer; dimType: tDimFlags): Integer;
    Function AverageFieldCheck(Index: Integer; var SumIndex, CountIndex: Integer): Boolean;
    function AlreadyExists(BaseName: String; sType: TDimFlags): Boolean;
    property Items[Index: Integer]:TDimensionItem read GetDimensionItem write SetDimensionItem; default;
    property DimensionCount: Integer read GetDimCount;
    property SummaryCount: Integer read GetSumCount;
    property ActiveDimensionCount: Integer read GetActiveDimCount;
    property ActiveSummaryCount: Integer read GetActiveSumCount;
  end;


  PTickInfoRec = ^TTickInfoRec;
  TTickInfoRec = Record
    StartTicks,
    EndTicks,
    TotalTicks: Integer;
    SName: string;
  end;

  TTicks = class
  private
    FTicksList: TList;
    FLogFile: TIniFile;
    FNumValues: Integer;
  public
   constructor Create(FileName: string);
   destructor Destroy; override;
   procedure Dump(bDetail: Boolean);
   procedure Clear;
   procedure Ticks(SectionName: string);
   procedure TicksIntArray(SectionName: string; IntArray: TIntArray);
   procedure TicksSmallIntArray(SectionName: string; IntArray: TSmallIntArray);
   property NumberOfValues: Integer read FNumValues write FNumValues;
 end;

  TBinData = class(TPersistent)
  private
    FNameList: TStringList;
    FValueList: TList;
    FOtherStr: string;
    function FindName(BinName: string; var pos: Integer): Boolean;
  public
    constructor create;
    destructor destroy; override;
    procedure Clear;
    procedure Assign(Value: TPersistent); override;
    procedure AddBinValues(BinName: string; const Values: array of const);
    function AddBinValue(BinName: string; Value: Variant): Integer;
    function BinValueCount(BinName: string): Integer;
    function GetAllBinValueCount: Integer;
    function GetBinValue(BinName: string; Index: Integer): Variant;
    function GetBinValues(BinName: string): Variant;
    function GetBinName(Index: Integer): string;
    function GetBinCount: Integer;
    function GetBinNameDataType: TFieldType;
    function GetMaxBinNameSize: Integer;
    function AddBin( BinName: string; vType: Integer ): Integer;
    function AddIBinValue( iBin: Integer; value: variant): Integer;
    function GetIBinValue( iBin: Integer; ValueIndex: Integer): variant;
    function GetIBinValueCount( iBin: Integer): Integer;
    property OtherBinName: string read FOtherStr write FOtherStr;
    property BinName[ Index:Integer ]: string read GetBinName;
    property BinCount: Integer read GetBinCount;
    property NameList: TStringList read FNameList;
    property ValueList: TList read FValueList;
  end;

  function FieldTypeToVarType(DataType: TFieldType): Integer;
  function VerifyRTQuery(aDataSet: TDataSet; Map: TDimensionItems; var bDataSetMatch: Boolean): TQueryError;
  function BuildDataSetMap(aDataSet: TDataSet; Map: TDimensionItems; var bParsed: Boolean; var bDataSetMatch: Boolean): TQueryError;
  function GetAggName(aType: TDimFlags; FieldName: string): string;
  function IsAggValid(AggType: TDimFlags; FieldType: TFieldType): Boolean;
  procedure AddToQuerySelect(var SQLString: string; Select: string);
  function CheckIfEmptyQuery(var SQLString: string): Boolean;
  procedure UpdateDesigner(Sender: TComponent);
  function FormatVariant(Value: Variant; FFormat: String): string;
  function NextArg(var aPos: Integer; Source: string): string;
  function HookToDataBase(aDataSet: TDataSet): TDataBase;
  function IsBDEAvailable: Boolean;

implementation

uses
  mxqparse, mxstore;

type
  THackQuery = class(TDBDataSet)
  end;

function IsBDEAvailable: Boolean;
var
  Status: DBIResult;
  Env: DbiEnv;
begin
  Result := Session.Active;
  if (Result = False) then
  begin
    FillChar(Env, SizeOf(Env), 0);
    StrPLCopy(Env.szLang, SIDAPILangID, SizeOf(Env.szLang) - 1);
    Status := DbiInit(@Env);
    if (Status = DBIERR_CANTLOADIDAPI) then Result := False;
  end;
end;

function GetAggName(aType: TDimFlags; FieldName: string): string;
begin
  Result := FieldName;
  case aType of
    dimSum     : Result := Format(sSumLabel, [Result]);
    dimCount   : Result := Format(sCountLabel, [Result]);
    dimAverage : Result := Format(sAverageLabel, [Result]);
    dimMax     : Result := Format(sMaxLabel, [Result]);
    dimMin     : Result := Format(sMinLabel, [Result]);
    else
      Result := Format(sAggLabel, [Result]);
   end;
end;

function FieldTypeToVarType( DataType: TFieldType ): Integer;
begin
  Result := FieldTypeVarMap[DataType];
end;

{ DataCube Collection Definition }

constructor TDimensionItems.Create(Owner: TPersistent; ItemClass: TDimensionItemClass);
begin
  inherited Create(ItemClass);
  FOwner := Owner;
  bQuiet := True;
end;

function TDimensionItems.GetOwner: TPersistent;
begin
  Result := FOwner;
end;

function TDimensionItems.GetDimensionItem(Index: Integer): TDimensionItem;
begin
  Result := TDimensionItem(inherited Items[Index]);
end;

procedure TDimensionItems.NotifyOwner(aType: TCDNotifyType);
begin
  if bQuiet then Exit;
end;

procedure TDimensionItems.SetDimensionItem(Index: Integer; Value: TDimensionItem);
begin
  Items[Index].Assign(Value);
end;

function TDimensionItems.Add: TDimensionItem;
begin
  Result := TDimensionItem(inherited Add);
end;

procedure TDimensionItems.Assign(Source: TPersistent);
begin
  inherited;
end;

function TDimensionItems.GetDimCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to Count-1 do
    if Items[I].IsDimension then
      Inc(Result);
end;

function TDimensionItems.GetSumCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to Count-1 do
    if Items[I].IsSummary then
      Inc(Result);
end;

function TDimensionItems.GetActiveDimCount: Integer;
var
  I: Integer;  
begin
  Result := 0;  
  for I := 0 to Count-1 do
    if (Items[I].IsDimension) and (Items[i].Active) then
      Inc(Result);
end;

function TDimensionItems.GetActiveSumCount: Integer;
var
  I: Integer;  
begin
  Result := 0;  
  for I := 0 to Count-1 do
    if (Items[I].IsSummary) and (Items[I].Active) then
      Inc(Result);
end;

function TDimensionItems.AlreadyExists(BaseName: String; sType: TDimFlags): Boolean;
var
  i: Integer;  
begin
  Result := False;
  for i := 0 to self.count-1 do
  begin
    if (BaseName = self[i].BaseName) and (sType = self[i].DimensionType) then
    begin
      Result := True;
      break;
    end;
  end;
end;

function TDimensionItems.AddDerivedField(Index: Integer; dimType: tDimFlags): Integer;
var
  SumIndex, CountIndex: Integer;
  NewItem: TDimensionItem;  
begin
  Result := -1;
  if not AverageFieldCheck(index, SumIndex, CountIndex) then Exit;    
  NewItem := Add;
  NewItem.index := Count-1;
  NewItem.active := True;
  NewItem.DimensionType := dimAverage;
  NewItem.Name := GetAggName(dimAverage, Items[index].BaseName);
  NewItem.FieldName := NewItem.Name;
  NewItem.DerivedFrom := Index;
  NewItem.FBaseName := Items[index].BaseName;
  NewItem.FActiveFlag := diAsNeeded;
  Result := NewItem.index;
end;

Function TDimensionItems.AVerageFieldCheck(Index: Integer; var SumIndex, CountIndex: Integer): Boolean;
var
  i: Integer;
  aName: string; 
begin
  Result := False;
  if Index >= Count then Exit;   
  SumIndex := -1;
  CountIndex := -1;
  aName := Items[index].BaseName;  
  if (Items[Index].DimensionType = dimSum) then
    SumIndex := Index
  else if (Items[Index].DimensionType = dimCount) then
    CountIndex := Index;
  if (CountIndex < 0) then
  begin
    for i := 0 to Count-1 do
    begin
      if (Items[i].DimensionType = dimCount) then
      begin
        if (aName = Items[i].BaseName) then
        begin
          CountIndex := i;
        end
        else if (AnsiUpperCase(Items[i].Name) = sCountStar) then
        begin
          CountIndex := i;
          break;
        end;
      end;
    end;
  end;
  if (SumIndex < 0) then
  begin
    for i := 0 to Count-1 do
    begin
      if (aName = Items[i].BaseName) then
      begin
        if (Items[i].DimensionType = dimSum) then
        begin
          SumIndex := i;
          break;
        end;
      end;
    end;
  end;
  if (CountIndex = -1) or (SumIndex = -1) then
  begin
    Exit;
  end;
  Result := True;
end;

  { TDimensionItem }

constructor TDimensionItem.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FOwner := Collection;
  FName := '';
  FFormat := '';
  FActive := False;
  Ffieldname := '';
  FDerivedFrom := -1;
  FType := dimDimension;
  FActiveFlag := diAsNeeded;
end;

procedure TDimensionItem.assign(Value: TPersistent);
begin
  if (Value is TDimensionItem) then
  begin
    FName := TDimensionItem(Value).FName;
    FFormat := TDimensionItem(Value).FFormat;
    FActive := TDimensionItem(Value).FActive;
    Ffieldname := TDimensionItem(Value).FFieldName;
    FDerivedFrom := TDimensionItem(Value).FDerivedFrom;
    FType := TDimensionItem(Value).FType;
    FFieldTYpe := TDimensionItem(Value).FFieldtype;
    FBaseName := TDimensionItem(Value).FBaseName;
    FActiveFlag := TDimensionItem(Value).FActiveFlag;
  end;
end;

procedure TDimensionItem.SetName(Value: string);
begin
  fName := Value;
  NotifyCollection(tdChanged);
end;

procedure TDimensionItem.SetBaseName(Value: string);
begin
  fBaseName := Value;
  NotifyCollection(tdChanged);
end;

procedure TDimensionItem.SetFieldName(Value: string);
begin
  fFieldName := Value;
  NotifyCollection(tdChanged);
end;

procedure TDimensionItem.SetDerivedFrom(Value: Integer);
begin
  fDerivedFrom := Value;
  NotifyCollection(tdChanged);
end;

procedure TDimensionItem.SetFormat(Value: String);
begin
  FFormat := Value;
  NotifyCollection(tdChanged);
end;

procedure TDimensionItem.SetFieldType(Value: TFieldType);
begin
  FFieldType := Value;
  NotifyCollection(tdChanged);
end;

procedure TDimensionItem.SetType(Value: TDimFlags);
begin
  FType := Value;
  NotifyCollection(tdChanged);
end;

procedure TDimensionItem.SetActive(Value: Boolean);
begin
  FActive := Value;
  NotifyCollection(tdChanged);
end;

procedure TDimensionItem.SetActiveFlag(Value: TActiveFlags);
begin
  if (FActiveFlag <> Value) then
  begin
    FActiveFlag := Value;
    NotifyCollection(tdChanged);
  end;
  FActive := (FActiveFlag = diActive);
end;


procedure TDimensionItem.InitializeRange;
begin
end;

procedure TDimensionItem.NotifyCollection(aType: TCDNotifyType);
begin
  TDimensionItems(FOwner).NotifyOwner(aType);
end;

Function TDimensionItem.IsDimension: Boolean;
begin
  Result := (FType = dimDimension);
end;

Function TDimensionItem.IsSummary: Boolean;
begin
  Result := (FType <> dimDimension);
end;

{ TTicks }

constructor TTicks.Create(FileName: string);
begin
  inherited Create;
  FNumValues := 0;
  FLogFile := TIniFile.Create(FileName);
  FTicksList := TList.Create;
end;

destructor TTicks.Destroy;
begin
  Dump(False);
  Clear;
  FLogFile.Free;
  inherited destroy;
end;

procedure TTicks.Clear;
var
  tRec: PTickInfoRec;
begin
  if Assigned(FTicksList) then
  begin
    while (FTicksList.Count > 0) do
    begin
      tRec := FTicksList.Last;
      FTicksList.Remove(tRec);
      Dispose(tRec);
    end;
    FTicksList.Free;
  end;
end;

procedure TTicks.Ticks(SectionName: string);
var
  I: Integer;
  t: LongInt;
  tRec: PTickInfoRec;
  bFound: Boolean;
begin
  t := GetTickCount;
  tRec := nil;
  bFound := False;  
  for I := 0 to FTicksList.Count-1 do
  begin
    tRec := FTicksList[I];
    if (tRec.sName = SectionName) then
    begin
      bFound := True;
      break;
    end;
  end;
  if bFound then
  begin
    if (tRec.EndTicks = 0) then
      tRec.EndTicks := t;
    tRec.TotalTicks := tRec.EndTicks - tRec.StartTicks;
  end
  else
  begin
    New(tRec);
    tRec.sName := SectionName;
    tRec.StartTicks := t;
    tRec.EndTicks := 0;
    tRec.TotalTicks := 0;
    FTicksList.Add(tRec);
  end;
end;

procedure TTicks.TicksIntArray(SectionName: string; IntArray: TIntArray);
var
  I: Integer;
  name: string;
begin
  for I := 0 to IntArray.Count-1 do
    name := name + ';' + IntToStr(IntArray[I]);
  name := SectionName + name;
  Ticks(name);
end;

procedure TTicks.TicksSmallIntArray(SectionName: string; IntArray: TSmallIntArray);
var
  I: Integer;
  name: string;
begin
  for I := 0 to IntArray.Count-1 do
    name := name + ';' + IntToStr(IntArray[I]);
  name := SectionName + name;
  Ticks(name);
end;

procedure TTicks.Dump(bDetail: Boolean);
var
  I, SummaryTicks: Integer;
  tRec: PTickInfoRec;
begin
  SummaryTicks := 0;
  for I := 0 to FTicksList.Count-1 do
  begin
    tRec := FTicksList[I];
    if not bDetail then
    begin
      if Pos('SummaryAs',  tRec.sName) > 0 then
      begin
        SummaryTicks := SummaryTicks + tRec.TotalTicks;
        Continue;
      end;
    end;
    FLogFile.WriteInteger(tRec.sName, 'TicksInMilliSeconds', tRec.TotalTicks);
  end;
  if not bDetail then
  begin
    FLogFile.WriteInteger('TotalGetSummaryAsString', 'TicksInMilliSeconds', SummaryTicks);
    { Dump number of cells : TotalSparseValues, TotalNonSparseValues }
    FLogFile.WriteInteger('TotalValues', 'NumberOfValues', FNumValues);
  end;
end;

{
  Simply reports if the logical data set ( Changed via Field mapping )
  matchs the query projection or the physical data set ( TTable, TClientDataSet )
}

function LogicalDataSetMatch(aDataSet: TDataset; myQuery: TXTAbQuery): Boolean;
var
  I: Integer;
  CursorProps: CurProps;
  Cursor: HDBICur;
begin
  Result := True;
  myQuery := nil;
  if assigned(myQuery) then
  begin
    if (myQuery.isLegal = tqenotInitialized) then
      Result := False;
      { Check the order }
    if (Result = True) then
    begin
      for I := 0 to aDataSet.FieldCount-1 do
      begin
        if (aDataSet.Fields[I].FieldName <> myQuery.Projector[I].OutputName) then
        begin
          Result := False;
          break;
        end;
      end;
    end;
    { Check the count }
    if (Result = True) then
    begin
      if (myQuery.NProjectors <> aDataSet.FieldCount) then
        Result := False;
    end;
  end
  else
  begin
    if (aDataSet is TTable) or (aDataSet is TQuery) then
    begin
      { Get the field count from the table }
      Cursor := TDBDataSet( aDataSet ).Handle;
      DbiGetCursorProps( Cursor, CursorProps );
      if (aDataSet.FieldCount <> CursorProps.iFields) then
        Result := False;
    end;
  end;
end;

function BuildMap(aDataSet: TDataset; Map: TDimensionItems; var bParsed: Boolean;
                  var bDataSetMatch: Boolean): TQueryError;
var
  j,ci,si,k: Integer;
  myQuery: TXTabQuery;
  bFound: Boolean;
  NewItem: TDimensionItem;
  x: Integer;
  new: Integer;
  aString: string;
begin
  bParsed := False;
  Result := tqeNotInitialized;
  if not assigned(Map) then Exit;
  {
    first see if a Query parse can be done for this dataset.  If not, don't
    fail, but rely on the assignments in the Map
  }
  myQuery := nil;
  if (aDataSet is TQuery) then
  begin
    try
      myQuery := TXtabQuery.create;
      myQuery.DBHandle := TQuery(aDataSet).Database.Handle;
      myQuery.canDelete := False;
      myQuery.SQLString := TQuery(aDataSet).SQL.Text;
    except
      on e: exception do
      begin
        aString := e.message;
        myQuery.Free;
        myQuery := nil;
      end;
    end;
  end;
  bParsed := assigned(myQuery);
  try
    if assigned(myQuery) then
    begin
      Result := myQuery.isLegal;
    end
    else
      Result := tqeOK;
    {
      If the query is an OK crosstab query, fix up the dimension map to place
      the map in the same order as the query.  If the map was built before, this
      will simply be reshuffling.  If not, all or part of the map may need to be
      created.
    }
    if (Result <> tqenotInitialized) then
    begin
      for j := 0 to aDataSet.fieldCount-1 do
      begin
        bFound := False;
        x := aDataSet.Fields[j].FieldNo-1;
        {
          First try to match against an existing map item.  Either the dataset field
          name must match, or the type, comparename, and outputname of Randy's parse
        }
        if (j < Map.count) then for k := j to Map.count-1 do
        begin
	  if (Map[k].FieldName <> aDataSet.Fields[j].FieldName) then
          begin
            if assigned(myQuery) and (x >= 0) then
            begin
              if (Map[k].FieldName <> myQuery.Projector[x].CompareName) then
                Continue;
            end
            else
              Continue;
          end;
          if assigned(myQuery) and (x >= 0) then
          begin
            if (Map[k].DimensionType <> myQuery.Projector[x].projType) then
              Continue;
          end;
          bFound := True;
	  if (j <> k) then Map[k].index := j;    { match found }
          break;
        end;
        { if not found, set up a new map with the defaults. }
        if not bFound then
        begin
	  NewItem := Map.Add;
    	  if (NewItem.index <> j) then NewItem.Index := j;
          Map[j].active := False;
          Map[j].DimensionType := dimUnknown;   { don't know until it's typed }
        end;
        {
          Now set the fieldname and datatype from the dataset field array
          If possible, set the dimension type from Randy's parse
        }
   	if (Map[j].Name = '') then
          Map[j].Name := aDataSet.Fields[j].FieldName;
        Map[j].FieldName := aDataSet.Fields[j].FieldName;
        Map[j].FFieldType := aDataSet.Fields[j].DataType;
        if not bFound then Map[j].InitializeRange;
        if assigned(myQuery) and (x >= 0) then
        begin
    	  Map[j].DimensionType := MyQuery.Projector[x].ProjType;
          Map[j].BaseName := MyQuery.Projector[x].BaseName;
        end;
      end;
    end;
    j := Map.Count-1;
    { Cleanout the map if entries are not in the dataset }
    for k := j downto aDataSet.FieldCount do
    begin
      if Map[k].DerivedFrom < 0 then
        Map[k].free;
    end;
    j := Map.Count-1;
    { Remove derived fields which no longer apply }
    for k := j downto aDataSet.FieldCount do
    begin
      if (map[k].DimensionType = dimAverage) and (map[k].DerivedFrom >= 0) then
      begin
        if Map.AverageFieldCheck(k,si,ci) then
        begin
          Map[k].DerivedFrom := si; { update derived from if changed }
          Map[k].active := Map[si].active and Map[ci].active;
          Continue;
	end;
      end;
      Map[k].free;
    end;
    for k := 0 to aDataSet.FieldCount-1 do
    begin
      if (Map[k].DimensionType = dimSum) then
      begin
        if not Map.AverageFieldCheck(k, si, ci) then Continue;
        if (Map.AlreadyExists(Map[k].BaseName, dimAverage)) then Continue;
        new := Map.AddDerivedField(k, dimAverage);
	Map[new].active := map[si].active and map[ci].active;
      end;
    end;
  finally
    begin
      bDataSetMatch := LogicalDataSetMatch(aDataSet, myQuery);
      myQuery.free;
    end;
  end;
end;

function isMapLegal(Map: TDimensionItems): TQueryError;
var
  bUnknowns, bSums, bDims: Boolean;
  i: Integer;
begin
  Result := tqeOK;
  bUnknowns := False;
  bSums := False;
  bDims := False;
  for i := 0 to Map.count-1 do
  begin
    if (Map[i].activeFlag <> diInactive) then
    begin
      if (Map[i].DimensionType = dimDimension) then
        bDims := True
      else if (Map[i].DimensionType = dimUnknown) then
        bUnknowns := True
      else
        bSums := True;
    end;
  end;
  if bUnknowns then
    Result := tqeUnknownDims
  else if not bDims then
    Result := tqeNoDimensions
  else if not bSums then
    Result := tqeNoAggs;
end;
{
  VerityRTQuery works on an active dataset (it will not open a Database)
  As a final pass through the database, it forces the dimension map to be
  in the same order as the executing query, and checks for validity and
  name matching.  If parse info is available, it also sets agg types
}
function VerifyRTQuery(aDataSet: TDataSet; Map: TDimensionItems; var bDataSetMatch: Boolean): TQueryError;
var
  bParsed: Boolean;

  function Min(X, Y: Integer): Integer;
  begin
    Result := X;
    if X > Y then Result := Y;
  end;

begin
  { Build or modify the dimmap based on the current data set }
  Result := BuildDataSetMap( aDataSet, Map, bParsed, bDataSetMatch);
  { Check to see if we have the minimum requirements for a valid map }
  if (Result = tqeOK) then Result := isMapLegal(Map);
end;

function BuildDataSetMap(aDataSet: TDataset; Map: TDimensionItems; var bParsed: Boolean; var bDataSetMatch: Boolean): TQueryError;
var
  wasActive: Boolean;
begin
  wasActive := aDataSet.active;
  try
    if not aDataSet.active then
      THackQuery(aDataSet).opencursor(False);
    Result := BuildMap(aDataSet, Map, bParsed, bDataSetMatch);
  finally
    if not wasActive then
      THackQuery(aDataSet).CloseCursor;
  end;
end;

function IsAggValid(AggType: TDimFlags; FieldType: tFieldType): Boolean;
begin
  case AggType of
    dimDimension:
    begin
      Result := not (FieldType in [ftBlob, ftBytes, ftUnknown]);
    end;
    dimCount: Result := True;
    dimGenericAgg, dimUnknown: Result := False;
    dimSum, dimAverage:
    begin
      Result := FieldType in [ftSmallint, ftInteger, ftWord, ftBoolean, ftFloat,
                              ftCurrency, ftBCD, ftAutoInc, ftDateTime, ftDate, ftTime];
    end;
    else
    begin
      Result := FieldType in [ftString, ftSmallint, ftInteger, ftWord, ftFloat,
                              ftCurrency, ftBCD, ftDate, ftTime, ftDateTime, ftAutoInc];
    end;
  end;
end;

procedure AddToQuerySelect(var SQLString: string; Select: string);
var
  aString: string;
  aPos, bPos, i: Integer;
  bAdd: Boolean;
begin
  bAdd := False;
  aString := AnsiUpperCase(SQLString);
  aPos := Pos('SELECT',aString);
  bPos := Pos('FROM',aString);  
  if (aPos <= 0) or (bPos <= 0) or (aPos>bPos) then
    raise exception.createRes(@sSelectFromError);    
  Select := ' ' + Select;
  for i := (aPos + 6) to bPos-1 do
  begin
    if ord(aString[i]) > 32 then
    begin
      bAdd := True;
      break;
    end;
  end;
  if bAdd then
    Select := Select + ','
  else
    Select := Select + ' ';
  Insert(Select,SQLString, aPos+6);
end;

function CheckIfEmptyQuery(var SQLString: string): Boolean;
var
  aString: string;
  aPos, bPos, i: Integer;
begin
  Result := False;
  aString := AnsiUpperCase(SQLString);
  aPos := Pos('SELECT',aString); { intl ok }
  bPos := Pos('FROM',aString);   { intl ok }
  if (aPos <= 0) or (bPos <= 0) or (aPos > bPos) then
  begin
    raise exception.createRes(@sSelectFromError);
  end
  else for i := (aPos + 6) to bPos-1 do
  begin
    if ord(aString[i]) > 32 then Exit;
  end;
  Result := True;
end;

procedure UpdateDesigner(Sender: TComponent);
var
  NextParent: TComponent;
begin
  if (csDesigning in Sender.ComponentState) and not (csUpdating in Sender.ComponentState) then
  begin
    NextParent := Sender;
    while assigned(NextParent) and not (NextParent is TCustomForm) do
      NextParent := NextParent.Owner;
    if Assigned(NextParent) and Assigned(TCustomForm(NextParent).Designer) then
    begin
      TCustomForm(NextParent).Designer.Modified;
    end;
  end;
end;

function FormatVariant(Value: Variant; FFormat: String): string;
var
  VarData: TVarData;
begin
  VarData := TVarData(Value);
  case TVarData(Value).vType of
    varDouble   : Result := FormatFloat(FFormat, Value);
    varCurrency : Result := FormatCurr(FFormat, Value);
    varDate     : Result := FormatDateTime(FFormat, Value);
    varInteger  : Result := FormatFloat(FFormat, Value);
    else
       Result := Value;
  end;
end;

function NextArg(var aPos: Integer; Source: string): string;
var
  iStart, iCount, ilen: Integer;
begin
  ilen := Length(Source);
  Result := '';
  while (aPos < iLen+1) and (ord(Source[aPos]) <= 32) do
    aPos := aPos + 1;
  if (aPos > iLen) then
  begin
    aPos := -1;  { end found }
    Exit;
  end;
  iStart := aPos;
  while ((aPos < iLen+1) and (Source[aPos] <> ',')) do
    aPos := aPos + 1;
  iCount := aPos - iStart;
  aPos := aPos+1;
  while Source[iStart + iCount] = ' ' do
    iCount := iCount - 1;
  Result := Copy(Source, iStart, iCount);
end;
  { TBinData }

function ConvertToVariant(const Value: TVarRec): Variant;
begin
  with Value do
    case VType of
      vtInteger    : Result := VInteger;
      vtBoolean    : Result := VBoolean;
      vtChar       : Result := VChar;
      vtExtended   : Result := VExtended^;
      vtString     : Result := VString^;
      vtPChar      : Result := VPChar^;
      vtAnsiString : Result := string(VAnsiString);
      vtCurrency   : Result := VCurrency^;
      vtVariant    : if not VarIsEmpty(VVariant^) then
                       Result := VVariant^;
      else
        EUnsupportedTypeError.CreateResFmt(@sUnsupportedVarType, [Value.VType]); 
    end;
end;

constructor TBinData.Create;
begin
  inherited Create;
  FNameList  := TStringList.Create;
  FValueList := TList.Create;
  FOtherStr  := sOtherValues;
end;

destructor TBinData.destroy;
var
  custAr: TCustomArray;
begin
  if Assigned(FValueList) then
  begin
    while (FValueList.Count > 0) do
    begin
      custAr := FValueList.Last;
      FValueList.Remove(custAr);
      custAr.Free;
    end;
    FValueList.Free;
    FValueList := nil;
  end;
  FNameList.Free;
  FNameList := nil;
  inherited Destroy;
end;

procedure TBinData.Assign(Value: TPersistent);
var
  custAr, newCustAr: TCustomArray;
  I: Integer;
begin
  Clear;
  FNameList.Assign(TBinData(Value).FNameList);
  FOtherStr := TBinData(Value).FOtherStr;
  for I := 0 to TBinData(Value).FValueList.Count-1 do
  begin
    custAr := TBinData(Value).FValueList[I];
    newCustAr := TCustomArray.Create(custAr.MemberCount, custAr.DataType);
    newCustAr.Assign(custAr, False, False);
    FValueList.Add(newCustAr);
  end;
end;

function TBinData.AddBinValue( BinName: string; Value: Variant ): Integer;
var
  custAr: TCustomArray;
  pos: Integer;
begin
  { Add the bin name if needed, otherwise get the position of the bin name in the string list }
  if not FindName(BinName, pos) then
  begin
    pos := FNameList.add(BinName);
    custAr := TCustomArray.Create(1, VarType(Value));
    custAr.Duplicates := dupIgnore;
    custAr.Sorted := True;
    if custAr <> nil then
      FValueList.Add(custAr);
  end;
  { Get the value array }
  custAr := FValueList[pos];
  Result := custAr.Add(Value);
end;

procedure TBinData.AddBinValues(BinName: string; const Values: array of const);
var
  I: Integer;
begin
  for I := 0 to High(Values) do
    AddBinValue(BinName, ConvertToVariant(Values[I]));
end;

function TBinData.BinValueCount(BinName: string): Integer;
var
  pos: Integer;
  custAr: TCustomArray;
begin
  Result := 0;  
  if FindName(BinName, pos) then
  begin
    custAr := FValueList[pos];
    Result := custAr.MemberCount;
  end;
end;

function TBinData.GetAllBinValueCount: Integer;
var
  I : Integer;
begin
  Result := 0;
  for i := 0 to GetBinCount-1 do
    Result := Result + GetIBinValueCount(i);
end;

function TBinData.GetBinValue(BinName: string; Index: Integer): Variant;
var
  pos: Integer;
  custAr: TCustomArray;
begin
  if FindName(BinName, pos) then
  begin
    custAr := FValueList[pos];
    Result := custAr[Index];
  end;
end;

function TBinData.GetBinValues(BinName: string): Variant;
var
  pos: Integer;
  custAr: TCustomArray;
  I: Integer;
begin
  if FindName(BinName, pos) then
  begin
    custAr := FValueList[pos];
    Result := VarArrayCreate([0, custAr.MemberCount-1], varVariant);
    for I := 0 to custAr.MemberCount-1 do
      Result[I] := custAr[I];
  end;
end;

function TBinData.GetBinName(Index: Integer): string;
begin
  Result := FNameList[Index];
end;

function TBinData.GetBinCount: Integer;
begin
  Result := FNameList.Count;
end;

function TBinData.GetBinNameDataType: TFieldType;
begin
  Result := ftString;
end;


function TBinData.GetMaxBinNameSize: Integer;
var
  I : Integer;

  function Max(X, Y: Integer): Integer;
  begin
    Result := Y;
    if (X > Y) then Result := X;
  end;

begin
  Result := Length(FOtherStr);
  for I := 0 to FNameList.Count-1 do
    Result := Max(Result , Length(FNameList[I]));
end;

procedure TBinData.Clear;
var
  custAr: TCustomArray;
begin
  if Assigned(FValueList) then
  begin
    while (FValueList.Count > 0) do
    begin
      custAr := FValueList.Last;
      FValueList.Remove(custAr);
      custAr.Free;
    end;
  end;  
  FNameList.Clear;
end;

function TBinData.AddBin(BinName: string; vType: Integer): Integer;
var
  custAr: TCustomArray;
  pos: Integer;  
begin
  { Add the bin name if needed, otherwise get the position of the bin name in the string list }
  if not FindName(BinName, pos) then
  begin
    pos := FNameList.add(BinName);
    custAr := TCustomArray.Create(0, VType);
    if (custAr <> nil) then FValueList.Add(custAr);
  end;
  Result := pos;
end;

function TBinData.FindName(BinName: string; var pos: Integer): Boolean;
var
  i: Integer;
begin
  Result := False;
  for i := 0 to FNameList.count-1 do
  begin
    if (FNameList[i] = BinName) then
    begin
      pos := i;
      Result := True;
      Exit;
    end;
  end;
end;

function TBinData.GetIBinValue(iBin: Integer; ValueIndex: Integer): variant;
begin
  Result := GetBinValue(GetBinName(iBin), ValueIndex);
end;

function TBinData.GetIBinValueCount(iBin: Integer): Integer;
begin
  Result := BinValueCount(GetBinName(iBin));
end;

function TBinData.AddIBinValue(iBin: Integer; value: variant): Integer;
begin
  Result := AddBinValue(GetBinName(iBin), value);
end;

function HookToDataBase(aDataSet: TDataSet): TDataBase;
var
  aliasname: string;
begin
  Result := nil;
  if (aDataSet is TQuery) then
  begin
    Result := TQuery(aDataset).Database;
    if (Result = nil) then
    begin
      aliasname := TQuery(aDataSet).DataBaseName;
      if (aliasName = '') then Exit;
      Result := TQuery(aDataSet).DBSession.OpenDataBase(aliasName);
    end;
  end;
end;

end.
