
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Local Client DataSet - IB                       }
{                                                       }
{       Copyright (c) 1997,01 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DBLocalI;

{$R-,T-,H+,X+}

interface


{$IFDEF MSWINDOWS}
uses Windows, SysUtils, Variants, Classes, Db, DBCommon, Midas,
     IBQuery, IBDatabase, IB, DBClient, DBLocal, Provider;
{$ENDIF}
{$IFDEF LINUX}
uses Libc, SysUtils, Variants, Classes, DB, DBCommon, Midas,
     IBQuery, IBDatabase, IB, DBClient, DBLocal, Provider;
{$ENDIF}

type
  
{ TIBCDSDataset }

  TIBCDSQuery = class(TIBQuery)
  private
    FKeyFields: string;
  protected
    function PSGetDefaultOrder: TIndexDef; override;
  end;

{ TIBClientDataSet }

  TIBClientDataSet = class(TCustomCachedDataSet)
  private
    FCommandText : String;
    FDataSet: TIBCDSQuery;
    FLocalParams: TParams;
    FStreamedActive: Boolean;
    procedure CheckMasterSourceActive(MasterSource: TDataSource);
    procedure SetDetailsActive(Value: Boolean);
    function GetConnection: TIBDatabase;
    function GetMasterFields: String;
    function GetMasterSource: TDataSource;
    function GetTransaction: TIBTransaction;
    procedure SetConnection(Value: TIBDatabase);
    procedure SetDataSource(const Value: TDataSource);
    procedure SetInternalCommandText(Value: string);
    procedure SetLocalParams;
    procedure SetMasterFields(const Value: String);
    procedure SetParamsFromSQL(const Value: string);
    procedure SetTransaction(const Value: TIBTransaction);
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
    property DBConnection: TIBDatabase read GetConnection write SetConnection;
    property DBTransaction : TIBTransaction read GetTransaction write SetTransaction;
    property MasterFields : String read GetMasterFields write SetMasterFields;
    property MasterSource: TDataSource read GetMasterSource write SetDataSource;
  end;

 implementation

uses MidConst, IBUtils;

type

{ TIBCDSParams }

  TIBCDSParams = class(TParams)
  private
    FFieldName: TStrings;
  protected
    procedure ParseSelect(SQL: string);
  public
    constructor Create(Owner: TPersistent);
    Destructor Destroy; override;
  end;

constructor TIBCDSParams.Create(Owner: TPersistent);
begin
  inherited;
  FFieldName := TStringList.Create;
end;

destructor TIBCDSParams.Destroy;
begin
  FreeAndNil(FFieldName);
  inherited;
end;

procedure TIBCDSParams.ParseSelect(SQL: string);
const
  SSelect = 'select';   {Do not localize}
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
        if Start^ = '.' then    {Do not localize}
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
    if Value='?' then    {Do not localize}
    begin
      FFieldName.Add(FName);
      Inc(Params);
    end;
  until (Params = Count) or (SQLToken in [stEnd]);
end;

{ TIBCDSQuery }

function TIBCDSQuery.PSGetDefaultOrder: TIndexDef;
begin
  if FKeyFields = '' then
    Result := inherited PSGetDefaultOrder
  else
  begin  // detail table default order
    Result := TIndexDef.Create(nil);
    Result.Options := [ixUnique];      // keyfield is unique
    Result.Name := StringReplace(FKeyFields, ';', '_', [rfReplaceAll]);  {Do not localize}
    Result.Fields := FKeyFields;
  end;
end;

{ TIBClientDataSet }

constructor TIBClientDataSet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDataSet := TIBCDSQuery.Create(nil);
  FDataSet.Name := Self.Name + 'DataSet1'; {Do not localize}
  Provider.DataSet := FDataSet;
  SqlDBType := typeIBX;
  FLocalParams := TParams.Create;
end;

destructor TIBClientDataSet.Destroy;
begin
  FreeAndNil(FLocalParams);
  FDataSet.Close;
  FreeAndNil(FDataSet);
  inherited Destroy;
end;

function TIBClientDataSet.GetCommandText: String;
begin
 Result := FCommandText;
end;

procedure TIBClientDataSet.SetCommandText(Value: String);
begin
  if Value <> CommandText then
  begin
    CheckInactive;
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
end;

function TIBClientDataSet.GetConnection: TIBDatabase;
begin
  Result := FDataSet.Database;
end;

procedure TIBClientDataSet.SetConnection(Value: TIBDatabase);
begin
  if FDataSet.Database <> Value then
  begin
    CheckInactive;
    FDataSet.Database := Value;
  end;
end;

function TIBClientDataSet.GetQuoteChar: String;
begin
  Result := FDataset.PSGetQuoteChar;
end;

procedure TIBClientDataSet.SetTransaction(const Value: TIBTransaction);
begin
  if FDataSet.Transaction <> Value then
    FDataSet.Transaction := Value;
end;

function TIBClientDataSet.GetTransaction: TIBTransaction;
begin
  Result := FDataSet.Transaction;
end;

procedure TIBClientDataSet.CloneCursor(Source: TCustomClientDataSet; Reset,
  KeepSettings: Boolean);
begin
  if not (Source is TIBClientDataSet) then
    DatabaseError(SInvalidClone);
  Provider.DataSet := TIBClientDataSet(Source).Provider.DataSet;
  DBConnection := TIBClientDataSet(Source).DBConnection;
  DBTransaction := TIBClientDataSet(Source).DBTransaction;
  CommandText := TIBClientDataSet(Source).CommandText;
  inherited CloneCursor(Source, Reset, KeepSettings);
end;

procedure TIBClientDataSet.SetDetailsActive(Value: Boolean);
var
  DetailList: TList;
  I: Integer;
begin
  DetailList := TList.Create;
  try
    GetDetailDataSets(DetailList);
    for I := 0 to DetailList.Count -1 do
    if TDataSet(DetailList[I]) is TIBClientDataSet then
      TIBClientDataSet(TDataSet(DetailList[I])).Active := Value;
  finally
    DetailList.Free;
  end;
end;

procedure TIBClientDataSet.CheckMasterSourceActive(
  MasterSource: TDataSource);
begin
  if Assigned(MasterSource) and Assigned(MasterSource.DataSet) then
    if not MasterSource.DataSet.Active then
{$IFDEF MSWINDOWS}
      DatabaseError(SMasterNotOpen);
{$ENDIF}
{$IFDEF LINUX}
      DatabaseError('Master dataset not open'); {do not localize}
{$ENDIF}
end;

function TIBClientDataSet.GetMasterSource: TDataSource;
begin
  Result := inherited GetDataSource;
end;

procedure TIBClientDataSet.SetDataSource(const Value: TDataSource);
begin
  inherited MasterSource := Value;
  if Assigned(Value) then
  begin
    if PacketRecords = -1 then
      PacketRecords := 0;
  end
  else
    if PacketRecords = 0 then
      PacketRecords := -1;
end;

function TIBClientDataSet.GetMasterFields: String;
begin
  Result := inherited MasterFields;
end;

procedure TIBClientDataSet.SetMasterFields(const Value: String);
begin
  inherited MasterFields := Value;
  if Value <> '' then
    IndexFieldNames := Value;
  FDataSet.FKeyFields := '';
end;

procedure TIBClientDataSet.SetActive(Value: Boolean);
var
  FCurrentCommand: string;
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
      FCurrentCommand := AddIBParamSQLForDetail(FLocalParams, CommandText, false, FDataset.Database.SQLDialect);
      SetInternalCommandText(FCurrentCommand);
      Params := FLocalParams;
      FetchParams;
    end else
    begin
      SetInternalCommandText(FCommandText);
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

procedure TIBClientDataSet.SetInternalCommandText(Value: string);
begin
  if Assigned(Provider.DataSet) then
  begin
    if Assigned(TIBCDSQuery(Provider.DataSet).Database) and (Value <> TIBCDSQuery(Provider.DataSet).SQL.Text) then
    begin
      TIBCDSQuery(Provider.DataSet).SQL.Text := Value;
      inherited SetCommandText(TIBCDSQuery(Provider.DataSet).SQL.Text);
    end;
  end
  else
    DataBaseError(SNoDataProvider);
end;

procedure TIBClientDataSet.SetParamsFromSQL(const Value: string);
var
  DataSet: TIBCDSQuery;
  TableName, TempQuery, Q: string;
  List: TIBCDSParams;
  I: Integer;
  Field: TField;
begin
  TableName := GetTableNameFromSQL(Value);
  if TableName <> '' then
  begin
    TempQuery := Value;
    List := TIBCDSParams.Create(Self);
    try
      List.ParseSelect(TempQuery);
        List.AssignValues(Params);
      for I := 0 to List.Count - 1 do
        List[I].ParamType := ptInput;
      DataSet := TIBCDSQuery.Create(FDataSet.Database);
      try
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

procedure TIBClientDataSet.Loaded;
begin
  inherited Loaded;
  if FStreamedActive then
  begin
    try
      SetActive(True);
      FStreamedActive := False;
    except
      if csDesigning in ComponentState then
        InternalHandleException
      else
        Raise;
    end;
  end;
end;

procedure TIBClientDataSet.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  if (Operation = opRemove) and Assigned(FDataset) then
    if AComponent = FDataset.Database then
    begin
      SetActive(False);
      FDataSet.DataBase := nil;
    end
    else
    if AComponent = FDataSet.Transaction then
    begin
      SetActive(False);
      FDataSet.Transaction := nil;
    end;
  inherited;
end;

procedure TIBClientDataSet.SetLocalParams;

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
    CreateParamsFromMasterFields(True);
end;



end.
