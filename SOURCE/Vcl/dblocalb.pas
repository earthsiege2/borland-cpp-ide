
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Local Client DataSet - BDE                      }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DBLocalB;

{$R-,T-,H+,X+}

interface
{$IFDEF MSWINDOWS}
uses Windows, SysUtils, Variants, Classes, DB, DBCommon, Midas, 
SqlTimSt, DBClient, DBLocal, Provider, DBTables;

type

{ TBDEQuery }

  TBDEQuery = class(TQuery)
  private
    FKeyFields: string;
  protected
    function PSGetDefaultOrder: TIndexDef; override;
  end;

{ TBDEClientDataSet }

  TBDEClientDataSet = class(TCustomCachedDataSet)
  private
    FCommandText: string;
    FCurrentCommand: string;
    FDataSet: TBDEQuery;
    FDatabase: TDataBase;
    FLocalParams: TParams;
    FStreamedActive: Boolean;
    procedure CheckMasterSourceActive(MasterSource: TDataSource);
    procedure SetDetailsActive(Value: Boolean);
    function GetConnection: TDataBase;
    function GetMasterSource: TDataSource; 
    function GetMasterFields: string;
    procedure SetConnection(Value: TDataBase);
    procedure SetDataSource(Value: TDataSource);
    procedure SetLocalParams;
    procedure SetMasterFields(const Value: string);
    procedure SetParamsFromSQL(const Value: string);
    procedure SetSQL(const Value: string);
  protected
    function GetCommandText: String; override;
    procedure Loaded; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetActive(Value: Boolean); override;
    procedure SetCommandText(Value: string); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CloneCursor(Source: TCustomClientDataSet; Reset: Boolean;
      KeepSettings: Boolean = False); override;
    function GetQuoteChar: String;
  published
    property Active;
    property CommandText: string read GetCommandText write SetCommandText;
    property DBConnection: TDataBase read GetConnection write SetConnection;
    property MasterFields read GetMasterFields write SetMasterFields;
    property MasterSource: TDataSource read GetMasterSource write SetDataSource;
  end;

implementation

uses BDEConst, MidConst;

type

{ TBDECDSParams }

  TBDECDSParams = class(TParams)
  private
    FFieldName: TStrings;
  protected
    procedure ParseSelect(SQL: string);
  public
    constructor Create(Owner: TPersistent);
    Destructor Destroy; override;
  end;

constructor TBDECDSParams.Create(Owner: TPersistent);
begin
  inherited;
  FFieldName := TStringList.Create;
end;

destructor TBDECDSParams.Destroy;
begin
  FreeAndNil(FFieldName);
  inherited;
end;

procedure TBDECDSParams.ParseSelect(SQL: string);
const
  SSelect = 'select';
var
  FWhereFound: Boolean;
  Start: PChar;
  FName, Value: string;
  SQLToken, CurSection, LastToken: TSQLToken;
  Params: Integer;
begin
  if Pos(' ' + SSelect + ' ', LowerCase(string(PChar(SQL)+8))) > 1 then Exit;  // can't parse sub queries
  Start := PChar(ParseSQL(PChar(SQL), True));
  CurSection := stUnknown;
  LastToken := stUnknown;
  FWhereFound := False;
  Params := 0;
  repeat
    repeat
      SQLToken := NextSQLToken(Start, FName, CurSection);
      if SQLToken in [stWhere] then
      begin
        FWhereFound := True;
        LastToken := stWhere;
      end else if SQLToken in [stTableName] then
      begin
        { Check for owner qualified table name }
        if Start^ = '.' then
          NextSQLToken(Start, FName, CurSection);
      end else
      if (SQLToken = stValue) and (LastToken = stWhere) then
        SQLToken := stFieldName;
      if SQLToken in SQLSections then CurSection := SQLToken;
    until SQLToken in [stFieldName, stEnd];
    if FWhereFound and (SQLToken in [stFieldName]) then
      repeat
        SQLToken := NextSQLToken(Start, Value, CurSection);
          if SQLToken in SQLSections then CurSection := SQLToken;
      until SQLToken in [stEnd,stValue,stIsNull,stIsNotNull,stFieldName];
    if Value='?' then
    begin
      FFieldName.Add(FName);
      Inc(Params);
    end;
  until (Params = Count) or (SQLToken in [stEnd]);
end;

{ TBDEQuery }

  function TBDEQuery.PSGetDefaultOrder: TIndexDef;
  begin
    if FKeyFields = '' then
      Result := inherited PSGetDefaultOrder
    else
    begin  // detail table default order
      Result := TIndexDef.Create(nil);
      Result.Options := [ixUnique];      // keyfield is unique
      Result.Name := StringReplace(FKeyFields, ';', '_', [rfReplaceAll]);
      Result.Fields := FKeyFields;
    end;
  end;

{ TBDEClientDataSet }

constructor TBDEClientDataSet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDataSet := TBDEQuery.Create(nil);
  FDataSet.Name := Self.Name + 'DataSet1';
  Provider.DataSet := FDataSet;
  SqlDBType := typeBDE;
  FLocalParams := TParams.Create;
end;

destructor TBDEClientDataSet.Destroy;
begin
  FreeAndNil(FLocalParams);
  FDataSet.Close;
  FreeAndNil(FDataSet);
  inherited Destroy;
end;

function TBDEClientDataSet.GetCommandText: string;
begin
  Result := FCommandText;
end;

procedure TBDEClientDataSet.CheckMasterSourceActive(MasterSource: TDataSource);
begin
  if Assigned(MasterSource) and Assigned(MasterSource.DataSet) then
    if not MasterSource.DataSet.Active then
      DatabaseError(SMasterNotOpen);
end;

procedure TBDEClientDataSet.SetParamsFromSQL(const Value: string);
var
  DataSet: TQuery;
  TableName, TempQuery, Q: string;
  List: TBDECDSParams;
  I: Integer;
  Field: TField;
begin
  TableName := GetTableNameFromSQL(Value);
  if TableName <> '' then
  begin
    TempQuery := Value;
    List := TBDECDSParams.Create(Self);
    try
      List.ParseSelect(TempQuery);
        List.AssignValues(Params);
      for I := 0 to List.Count - 1 do
        List[I].ParamType := ptInput;
      DataSet := TQuery.Create(nil);
      try
        DataSet.DatabaseName := FDataSet.DatabaseName;
        if Assigned(FDataSet) then
          Q := FDataSet.PSGetQuoteChar
        else
          Q := '';
        DataSet.SQL.Add('select * from ' + Q + TableName + Q + ' where 0 = 1'); { do not localize }
        try
          DataSet.Open;
          for I := 0 to List.Count - 1 do
          begin
            if List.FFieldName.Count > I then
            begin
              try 
                Field := DataSet.FieldByName(List.FFieldName[I]);
              except
                Field := nil;
              end;
            end else
              Field := nil;
            if Assigned(Field) then
            begin
              if Field.DataType <> ftString then
                List[I].DataType := Field.DataType
              else if TStringField(Field).FixedChar then
                List[I].DataType := ftFixedChar
              else
                List[I].DataType := ftString;
            end;
          end;
        except
          // ignore all exceptions
        end;
      finally
        DataSet.Free;
      end;
    finally
      if List.Count > 0 then
        Params.Assign(List);
      List.Free;
    end;
  end;
end;

procedure TBDEClientDataSet.SetSQL(const Value: string);
begin
  if Assigned(Provider.DataSet) then
  begin
    TQuery(Provider.DataSet).SQL.Clear;
    if Value <> '' then
      TQuery(Provider.DataSet).SQL.Add(Value);
    inherited SetCommandText(Value);
  end else
    DataBaseError(SNoDataProvider);
end;



procedure TBDEClientDataSet.Loaded; 
begin
  inherited Loaded;
  if FStreamedActive then
  begin
    SetActive(True);
    FStreamedActive := False;
  end;  
end;

function TBDEClientDataSet.GetMasterFields: string;
begin
  Result := inherited MasterFields;
end;

procedure TBDEClientDataSet.SetMasterFields(const Value: string);
begin
  inherited MasterFields := Value;
  if Value <> '' then
    IndexFieldNames := Value;
  FDataSet.FKeyFields := '';
end;

procedure TBDEClientDataSet.SetCommandText(Value: String);
begin
  inherited SetCommandText(Value);
  FCommandText := Value;
  if not (csLoading in ComponentState) then
  begin
    FDataSet.FKeyFields := '';
    IndexFieldNames := '';
    MasterFields := '';
    IndexName := '';
    IndexDefs.Clear;
    Params.Clear;
    if (csDesigning in ComponentState) and (Value <> '') then
      SetParamsFromSQL(Value);
  end;
end;

function TBDEClientDataSet.GetConnection: TDatabase;
begin
  Result := FDataBase;
end;

procedure TBDEClientDataSet.SetConnection(Value: TDataBase);
begin
  if Value = FDatabase then exit;
  CheckInactive;
  if Assigned(Value) then
  begin
    if not (csLoading in ComponentState) and (Value.DatabaseName = '') then
      DatabaseError(SDatabaseNameMissing);
    FDataSet.DatabaseName := Value.DatabaseName;
  end else
    FDataSet.DataBaseName := '';
  FDataBase := Value;
end;

function TBDEClientDataSet.GetQuoteChar: String;
begin
  Result := '';
end;

procedure TBDEClientDataSet.CloneCursor(Source: TCustomClientDataSet; Reset: Boolean;
   KeepSettings: Boolean = False); 
begin
  if not (Source is TBDEClientDataSet) then
    DatabaseError(SInvalidClone);
  Provider.DataSet := TBDEClientDataSet(Source).Provider.DataSet;
  DBConnection := TBDEClientDataSet(Source).DBConnection;
  CommandText := TBDEClientDataSet(Source).CommandText;
  inherited CloneCursor(Source, Reset, KeepSettings);
end;

procedure TBDEClientDataSet.Notification(AComponent: TComponent; Operation: TOperation); 
begin
  inherited Notification(AComponent, Operation);
  if Operation = opRemove then
    if AComponent = FDatabase then
    begin
      FDataBase := nil;
      SetActive(False);
    end;
end;

procedure TBDEClientDataSet.SetLocalParams;

  procedure CreateParamsFromMasterFields(Create: Boolean);
  var
    I: Integer;
    List: TStrings;
  begin
    List := TStringList.Create;
    try
      if Create then
        FLocalParams.Clear;
      FDataSet.FKeyFields := MasterFields;
      List.CommaText := MasterFields;
      for I := 0 to List.Count -1 do
      begin
        if Create then
          FLocalParams.CreateParam( ftUnknown, MasterSource.DataSet.FieldByName(List[I]).FieldName,
                     ptInput);
        FLocalParams[I].AssignField(MasterSource.DataSet.FieldByName(List[I]));
      end;
    finally
      List.Free;
    end;
  end;

begin
  if (MasterFields <> '') and Assigned(MasterSource) and Assigned(MasterSource.DataSet) then
  begin
    CreateParamsFromMasterFields(True);
    FCurrentCommand := AddParamSQLForDetail(FLocalParams, CommandText, True);
  end;
end;

procedure TBDEClientDataSet.SetDataSource(Value: TDataSource);
begin
  inherited MasterSource := Value;
  if Assigned(Value) then
  begin
    if PacketRecords = -1 then PacketRecords := 0;
  end else
  begin
    if PacketRecords = 0 then PacketRecords := -1;
  end;
end;

function TBDEClientDataSet.GetMasterSource: TDataSource;
begin
  Result := inherited MasterSource;
end;

procedure TBDEClientDataSet.SetDetailsActive(Value: Boolean);
var
  DetailList: TList;
  I: Integer;
begin
  DetailList := TList.Create;
  try
    GetDetailDataSets(DetailList);
    for I := 0 to DetailList.Count -1 do
    if TDataSet(DetailList[I]) is TBDEClientDataSet then
      TBDEClientDataSet(TDataSet(DetailList[I])).Active := Value;
  finally
    DetailList.Free;
  end;
end;

procedure TBDEClientDataSet.SetActive(Value: Boolean);
begin
  if Value then
  begin
    if csLoading in ComponentState then
    begin
      FStreamedActive := True;
      exit;
    end;
    if MasterFields <> '' then
    begin
      if not (csLoading in ComponentState) then
        CheckMasterSourceActive(MasterSource);
      SetLocalParams;
      SetSQL(FCurrentCommand);
      Params := FLocalParams;
      FetchParams;
    end else
    begin
      SetSQL(FCommandText);
      if Params.Count > 0 then
      begin
        FDataSet.Params := Params;
        FetchParams;
      end;
    end;
  end;
  if Value and (FDataSet.ObjectView <> ObjectView) then
    FDataSet.ObjectView := ObjectView;
  inherited SetActive(Value);
  SetDetailsActive(Value);
end;

{$ENDIF}
{$IFDEF LINUX}
 implementation
{$ENDIF}

end.
