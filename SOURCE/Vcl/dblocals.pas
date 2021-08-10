{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 1997, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit DBLocalS;

{$R-,T-,H+,X+}

interface

{$IFDEF MSWINDOWS}
uses Windows, SysUtils, Variants, Classes, Db, DBCommon, Midas, 
     SqlTimSt, DBClient, DBLocal, Provider, SqlExpr;
{$ENDIF}
{$IFDEF LINUX}
uses Libc, SysUtils, Variants, Classes, DB, DBCommon, Midas, SqlTimSt, 
     DBClient, DBLocal, Provider, SqlExpr;
{$ENDIF}

type

{ TSQLClientDataSet }

  TSQLClientDataSet = class(TCustomCachedDataSet)
  private
    FLocalParams: TParams;
    FDataSet: TSQLDataSet;
    FLocalCommandText: string;
    FSQLConnection: TSQLConnection;
{$IFDEF MSWINDOWS}
    FCommandType: TSQLCommandType;
    FStreamedActive: Boolean;
{$ENDIF}
    function GetCommandType: TSQLCommandType;
    function GetConnection: TSQLConnection;
    function GetConnectionName: string;
    function GetMasterFields: string;
    function GetObjectView: Boolean;
    procedure SetCommandType(const Value: TSQLCommandType);
    procedure SetConnection(const Value: TSQLConnection);
    procedure SetConnectionName(const Value: string);
    procedure SetInternalCommandText(Value: string);
    procedure SetLocalParams;
    procedure SetMasterFields(const Value: string);
    procedure SetObjectView(const Value: Boolean);
{$IFDEF MSWINDOWS}
    function GetMasterSource: TDataSource; 
    procedure SetDataSource(Value: TDataSource);
{$ENDIF}
  protected
    procedure Loaded; override;
    function GetCommandText: string; override;
    procedure SetActive(Value: Boolean); override;
    procedure SetCommandText(Value: string); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CloneCursor(Source: TCustomClientDataSet; Reset: Boolean;
      KeepSettings: Boolean = False); override;
    function GetQuoteChar: string;
  published
    property CommandText: string read GetCommandText write SetCommandText;
    property CommandType: TSQLCommandType read GetCommandType write SetCommandType default ctQuery;
    property DBConnection: TSQLConnection read GetConnection write SetConnection;
    property ConnectionName: string read GetConnectionName write SetConnectionName;
    property MasterFields read GetMasterFields write SetMasterFields;
{$IFDEF MSWINDOWS}
    property MasterSource: TDataSource read GetMasterSource write SetDataSource;
{$ENDIF}
    property ObjectView read GetObjectView write SetObjectView default False;
  end;

implementation

uses MidConst, SqlConst;

const
  ProvDataSetName = 'DataSet1';

{ Utility functions }

{ TSQLCDSParams }

type

{ TInternalSQLDataset }

  TInternalSQLDataset = class(TSQLDataSet)
  private
    FKeyFields: string;
  protected
    function PSGetDefaultOrder: TIndexDef; override;
  end;

  TSQLCDSParams = class(TParams)
  private
    FFieldName: TStrings;
  protected
    procedure ParseSelect(SQL: string);
  public
    constructor Create(Owner: TPersistent);
    Destructor Destroy; override;
  end;

constructor TSQLCDSParams.Create(Owner: TPersistent);
begin
  inherited;
  FFieldName := TStringList.Create;
end;

destructor TSQLCDSParams.Destroy;
begin
  FreeAndNil(FFieldName);
  inherited;
end;

procedure TSQLCDSParams.ParseSelect(SQL: string);
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

{ TInternalSQLDataset }

function TInternalSQLDataset.PSGetDefaultOrder: TIndexDef;
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

{ TSQLClientDataSet }

constructor TSQLClientDataSet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDataSet := TInternalSQLDataSet.Create(nil);
  FDataSet.Name := Self.Name + ProvDataSetName;
  Provider.DataSet := FDataSet;
  SqlDBType := typeDBX;
  FSQLConnection := nil;
  FLocalParams := TParams.Create;
end;

destructor TSQLClientDataSet.Destroy;
begin
  inherited Destroy;
  if Assigned(FDataSet) then
    FreeAndNil(FDataSet);
  if Assigned(FSQLConnection) then
    FreeAndNil(FSQLConnection);
  if Assigned(FLocalParams) then
    FreeAndNil(FLocalParams);
end;

function TSQLClientDataSet.GetCommandType: TSQLCommandType;
begin
{$IFDEF MSWINDOWS}
  Result := FCommandType;
{$ENDIF}
{$IFDEF LINUX}
  Result := FDataSet.CommandType;
{$ENDIF}
end;

procedure TSQLClientDataSet.SetCommandType(const Value: TSQLCommandType);
begin
  if Value <> CommandType then
  begin
{$IFDEF MSWINDOWS}
    FCommandType := Value;
{$ENDIF}
{$IFDEF LINUX}
    FDataSet.CommandType := Value;
{$ENDIF}
    if not (csLoading in ComponentState) then
      CommandText := '';
  end;
end;

function TSQLClientDataSet.GetCommandText: string;
begin
  Result := FLocalCommandText;
end;

procedure TSQLClientDataSet.SetInternalCommandText(Value: string);
var
  Q,FCurrentCommand: string;
begin
  if Assigned(Provider.DataSet) then
  begin
    if Assigned(TSQLDataSet(Provider.DataSet).SqlConnection) and (Value <> TSQLDataSet(Provider.DataSet).CommandText) then
    begin
      if CommandType = ctTable then
      begin
        { cannot get quote char if Connection not open }
        if not TSQLDataSet(Provider.DataSet).SqlConnection.Connected then
          TSQLDataSet(Provider.DataSet).SqlConnection.Connected := True;
        Q := TSQLDataSet(Provider.DataSet).GetQuoteChar;
        TSQLDataSet(Provider.DataSet).CommandType := ctQuery;
        if Pos(Q, Value) = 0 then
          FCurrentCommand := 'select * from ' + Q + Value + Q
        else
          FCurrentCommand := 'select * from ' + Value;
      end else
      begin
        TSQLDataSet(Provider.DataSet).CommandType := TSQLCommandType(CommandType);
        FCurrentCommand := Value;
      end;
      if (FLocalParams.Count > 0) and (Self.MasterFields <> '') then
        FCurrentCommand := FCurrentCommand + AddParamSQLForDetail(FLocalParams, '', True);
      TSQLDataSet(Provider.DataSet).CommandText := FCurrentCommand;
      inherited SetCommandText(TSQLDataSet(Provider.DataSet).CommandText);
    end;
  end else
    DataBaseError(SNoDataProvider);
end;

procedure TSQLClientDataSet.SetCommandText(Value: string);  

  procedure SetParamsFromSQL(const Value: string);
  var
    DataSet: TSQLDataSet;
    TableName: string;
    TempQuery: string;
    List: TSQLCDSParams;
    I: Integer;
    Field: TField;
    Q: string;
  begin
    TableName := GetTableNameFromSQL(Value);
    if TableName <> '' then
    begin
      TempQuery := Value;
      List := TSQLCDSParams.Create(Self);
      try
        List.ParseSelect(TempQuery);
          List.AssignValues(Params);
        for I := 0 to List.Count - 1 do
          List[I].ParamType := ptInput;
        DataSet := TSQLDataSet.Create(nil);
        try
          DataSet.SQLConnection := FDataSet.SQLConnection;
          Q := DataSet.GetQuoteChar;
          DataSet.CommandText := 'select * from ' + Q + TableName + Q + ' where 0 = 1'; { do not localize }
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
            // ignore cannot open error
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

begin
  if Value <> CommandText then
  begin
    CheckInactive;
    FLocalCommandText := Value;
    if not (csLoading in ComponentState) then
    begin
      TInternalSQLDataSet(FDataSet).FKeyFields := '';
      IndexFieldNames := '';
      MasterFields := '';
      IndexName := '';
      IndexDefs.Clear;
      Params.Clear;
      if (csDesigning in ComponentState) and Assigned(DBConnection)
{$IFDEF LINUX}
          and (DBConnection.Connected)
{$ENDIF}
          and (Value <> '') then
        SetParamsFromSQL(Value);
    end;
  end;
end;

function TSQLClientDataSet.GetConnection: TSQLConnection;
begin
  if Assigned(FSQLConnection) then Result := FSQLConnection
  else Result := FDataSet.SQLConnection as TSQLConnection;
end;

procedure TSQLClientDataSet.SetConnection(const Value: TSQLConnection);
begin
  if FDataSet.SQLConnection <> Value then
  begin
    CheckInactive;
    if Assigned(Value) then
      SetConnectionName('');
    FDataSet.SQLConnection := Value;
  end;
end;

function TSQLClientDataSet.GetConnectionName: string;
begin
  if Assigned(FSQLConnection) then
    Result := FSQLConnection.ConnectionName
  else
    Result := '';
end;

procedure TSQLClientDataSet.SetConnectionName(const Value: string);
begin
  if Value <> '' then
  begin
    CheckInactive;
    if Assigned(FDataSet.SQLConnection) then
    begin
      FDataSet.SQLConnection.Close;
      FDataSet.SQLConnection := Nil;
    end;
    if Assigned(FSQLConnection) then
    begin
      FSQLConnection.Close;
      if Value = FSQLConnection.ConnectionName then 
        exit
      else
        FreeAndNil(FSQLConnection);
    end;
    FSQLConnection := TSQLConnection.Create(nil);
    FSQLConnection.LoadParamsOnConnect := True;
    FSQLConnection.ConnectionName := Value;
    FDataSet.SQLConnection := FSQLConnection;
  end else
  begin
    if Assigned(FSQLConnection) then
    begin
      FDataSet.SQLConnection := nil;
      FreeAndNil(FSQLConnection);
    end;
  end;
end;

function TSQLClientDataSet.GetQuoteChar: string;
begin
  if Assigned(FDataSet) then
    Result := FDataSet.GetQuoteChar;
end;

function TSQLClientDataSet.GetMasterFields: string;
begin
  Result := inherited MasterFields;
end;

procedure TSQLClientDataSet.SetMasterFields(const Value: string);
begin
  inherited MasterFields := Value;
  if Value <> '' then
    IndexFieldNames := Value;
  TInternalSQLDataSet(FDataSet).FKeyFields := '';
end;

procedure TSQLClientDataSet.SetLocalParams;

  procedure CreateParamsFromMasterFields(Create: Boolean);
  var
    I: Integer;
    List: TStrings;
  begin
    List := TStringList.Create;
    try
      if Create then
        FLocalParams.Clear;
      List.CommaText := StringReplace(MasterFields, ';', ',', [rfReplaceAll]);
      TInternalSQLDataSet(FDataSet).FKeyFields := MasterFields;
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
  end;
end;

procedure TSQLClientDataSet.SetActive(Value: Boolean);

  procedure CheckMasterSourceActive(const MasterSource: TDataSource);
  begin
    if Assigned(MasterSource) and Assigned(MasterSource.DataSet) then
      if not MasterSource.DataSet.Active then
        DatabaseError(SMasterNotOpen);
  end;

  procedure SetDetailsActive(const Value: Boolean);
  var
    DetailList: TList;
    I: Integer;
  begin
    DetailList := TList.Create;
    try
      GetDetailDataSets(DetailList);
      for I := 0 to DetailList.Count -1 do
      if TDataSet(DetailList[I]) is TSQLClientDataSet then
        TSQLClientDataSet(TDataSet(DetailList[I])).Active := Value;
    finally
      DetailList.Free;
    end;
  end;

{$IFDEF LINUX}
var
  SaveCommandType: TSQLCommandType;
{$ENDIF}
begin
{$IFDEF LINUX}
  SaveCommandType := CommandType;
  try
{$ENDIF}
  if Value then
  begin
    if csLoading in ComponentState then
    begin
  {$IFDEF MSWINDOWS}
      FStreamedActive := True;
  {$ENDIF}
      exit;
    end;
    if MasterFields <> '' then
    begin
  {$IFDEF LINUX}
      if PacketRecords = -1 then PacketRecords := 0;
  {$ENDIF}
      if not (csLoading in ComponentState) then
        CheckMasterSourceActive(MasterSource);
      SetLocalParams;
      SetInternalCommandText(CommandText);
      Params := FLocalParams;
      FetchParams;
    end else
    begin
      SetInternalCommandText(FLocalCommandText);
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
  {$IFDEF LINUX}
  finally
    if FDataSet.CommandType <> SaveCommandType then
      FDataSet.CommandType := SaveCommandType;
  end;
  {$ENDIF}
end;

procedure TSQLClientDataSet.SetObjectView(const Value: Boolean);
begin
  inherited ObjectView := Value;
end;

function TSQLClientDataSet.GetObjectView: Boolean;
begin
  Result := inherited ObjectView; 
end;

{$IFDEF MSWINDOWS}
procedure TSQLClientDataSet.SetDataSource(Value: TDataSource);
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

function TSQLClientDataSet.GetMasterSource: TDataSource;
begin
  Result := inherited GetDataSource;
end;
{$ENDIF}

procedure TSQLClientDataSet.Loaded;

begin
  inherited Loaded;
{$IFDEF MSWINDOWS}
  if FStreamedActive then
  begin
    try 
      FStreamedActive := False;
      SetActive(True);
    except
      if csDesigning in ComponentState then
        InternalHandleException else
        raise;
    end;
  end;  
{$ENDIF}
end;

procedure TSQLClientDataSet.CloneCursor(Source: TCustomClientDataSet; Reset: Boolean;
   KeepSettings: Boolean = False); 
begin
  if not (Source is TSQLClientDataSet) then
    DatabaseError(SInvalidClone);
  Provider.DataSet := TSQLClientDataSet(Source).Provider.DataSet;
  DBConnection := TSQLClientDataSet(Source).DBConnection;
  FLocalCommandText := TSQLClientDataSet(Source).CommandText;
  inherited CloneCursor(Source, Reset, KeepSettings);
end;

end.
