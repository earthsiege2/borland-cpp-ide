{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 1997, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit DBLocal;

{$R-,T-,H+,X+}

interface

{$IFDEF MSWINDOWS}
uses Windows, SysUtils, Variants, Classes, DB, DBCommon, Midas, SqlTimSt, DBClient, Provider;
{$ENDIF}
{$IFDEF LINUX}
uses Libc, SysUtils, Variants, Classes, DB, DBCommon, Midas, SqlTimSt, DBClient, Provider;
{$ENDIF}

type

  TSqlDBType = (typeDBX, typeBDE, typeADO, typeIBX);

{ TCustomCachedDataSet }

  TCustomCachedDataSet = class(TCustomClientDataSet)
  private
    FProvider: TDataSetProvider;
    FSqlDBType: TSqlDBType;
    function GetBeforeUpdateRecord : TBeforeUpdateRecordEvent;
    procedure SetBeforeUpdateRecord( Value: TBeforeUpdateRecordEvent);
    function GetAfterUpdateRecord: TAfterUpdateRecordEvent;
    procedure SetAfterUpdateRecord(Value: TAfterUpdateRecordEvent);
    function GetOnGetTableName: TGetTableNameEvent;
    procedure SetOnGetTableName(Value: TGetTableNameEvent);
    function GetOnUpdateData: TProviderDataEvent;
    procedure SetOnUpdateData(Value: TProviderDataEvent);
    function GetOnUpdateError: TResolverErrorEvent;
    procedure SetOnUpdateError(Value: TResolverErrorEvent);
  protected
    procedure CloseCursor; override;
    function GetCommandText: string; virtual;
    function GetOptions: TProviderOptions;
    function GetUpdateMode: TUpdateMode;
    procedure SetActive(Value: Boolean); override;
    procedure SetAggregates(Value: TAggregates); override;
    procedure SetCommandText(Value: string); override;
    procedure SetOptions(Value: TProviderOptions);
    procedure SetUpdateMode(Value: TUpdateMode);
    property Provider: TDataSetProvider read FProvider write FProvider;
    property SqlDBType: TSqlDBType read FSqlDBType write FSqlDBType;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure LoadFromFile(const AFileName: string = '');
  published
    { overridden by TCustomCachedDataSet descendants }
    property Active;
    property CommandText;
    { public in TClientDataSet }
    property Aggregates;
    property AggregatesActive;
    property AutoCalcFields;
    property Constraints stored ConstraintsStored;
    property DisableStringTrim;
    property FetchOnDemand;
    property FieldDefs;
    property FileName;
    property Filter;
    property Filtered;
    property FilterOptions;
    property IndexDefs;
    property IndexFieldNames;
    property IndexName;
    property MasterFields;
    property MasterSource;
    { from TDataSetProvider }
    property Options: TProviderOptions read GetOptions write SetOptions default [];
    { more public in TClientDataSet }
    property ObjectView;
    property PacketRecords;
    property Params;
    property ReadOnly;
    { from TDataSetProvider again}
    property UpdateMode: TUpdateMode read GetUpdateMode write SetUpdateMode default upWhereAll;
    { TClientDataSet events }
    property BeforeOpen;
    property AfterOpen;
    property BeforeClose;
    property AfterClose;
    property BeforeInsert;
    property AfterInsert;
    property BeforeEdit;
    property AfterEdit;
    property BeforePost;
    property AfterPost;
    property BeforeCancel;
    property AfterCancel;
    property BeforeDelete;
    property AfterDelete;
    property BeforeScroll;
    property AfterScroll;
    property BeforeRefresh;
    property AfterRefresh;
    property OnCalcFields;
    property OnDeleteError;
    property OnEditError;
    property OnFilterRecord;
    property OnNewRecord;
    property OnPostError;
    property OnReconcileError;
    property BeforeApplyUpdates;
    property AfterApplyUpdates;
    property BeforeGetRecords;
    property AfterGetRecords;
    property BeforeRowRequest;
    property AfterRowRequest;
    property BeforeExecute;
    property AfterExecute;
    property BeforeGetParams;
    property AfterGetParams;
    { TDataSetProvider events }
    property BeforeUpdateRecord: TBeforeUpdateRecordEvent read GetBeforeUpdateRecord
      write SetBeforeUpdateRecord;
    property AfterUpdateRecord: TAfterUpdateRecordEvent read GetAfterUpdateRecord
      write SetAfterUpdateRecord;
    property OnGetTableName: TGetTableNameEvent read GetOnGetTableName write SetOnGetTableName;
    property OnUpdateData: TProviderDataEvent read GetOnUpdateData write SetOnUpdateData;
    property OnUpdateError: TResolverErrorEvent read GetOnUpdateError write SetOnUpdateError;
  end;

implementation

uses DBConsts;

{ TCustomCachedDataSet }

constructor TCustomCachedDataSet.Create(AOwner: TComponent);
begin
  inherited;
  FProvider := TDataSetProvider.Create(nil);
  FProvider.Name := Self.Name + 'Provider1';
  FProvider.Options := [poAllowCommandText];
  FProvider.UpdateMode := upWhereAll;
  SetProvider(FProvider);
end;

destructor TCustomCachedDataSet.Destroy;
begin
  if Assigned(FProvider) then
     FreeAndNil(FProvider);
  inherited;
end;

function TCustomCachedDataSet.GetCommandText: String;
begin
  Result := '';
end;

procedure TCustomCachedDataSet.CloseCursor;
begin
  inherited;
  SetProvider(FProvider);
end;

procedure TCustomCachedDataSet.SetCommandText(Value: String);
begin
  if inherited CommandText <> Value then
    inherited SetCommandText(Value);
end;

procedure TCustomCachedDataSet.SetAggregates(Value: TAggregates);
begin
  if Active then DatabaseError(SDataSetOpen);
  inherited SetAggregates(Value);
end;

procedure TCustomCachedDataSet.SetActive(Value: Boolean);
begin
  if Value then
  begin
    if (FileName <> '') and (CommandText = '') then
      SetProvider(Nil)
    else if Assigned(FProvider) then
      SetProvider(FProvider);
  end;
  inherited SetActive(Value);
  if (not Value) and Assigned(FProvider) then
    SetProvider(FProvider);
end;

function TCustomCachedDataSet.GetOptions: TProviderOptions;
begin
  Result := FProvider.Options;
end;

procedure TCustomCachedDataSet.SetOptions(Value: TProviderOptions);
begin
  FProvider.Options := Value;
end;

procedure TCustomCachedDataSet.SetUpdateMode(Value: TUpdateMode);
begin
  FProvider.UpdateMode := Value;
end;

function TCustomCachedDataSet.GetUpdateMode: TUpdateMode;
begin
  Result := FProvider.UpdateMode;
end;

function TCustomCachedDataSet.GetBeforeUpdateRecord : TBeforeUpdateRecordEvent;
begin
  Result := FProvider.BeforeUpdateRecord;
end;
procedure TCustomCachedDataSet.SetBeforeUpdateRecord( Value: TBeforeUpdateRecordEvent);
begin
  FProvider.BeforeUpdateRecord := Value;
end;
function TCustomCachedDataSet.GetAfterUpdateRecord: TAfterUpdateRecordEvent;
begin
  Result := FProvider.AfterUpdateRecord;
end;
procedure TCustomCachedDataSet.SetAfterUpdateRecord( Value: TAfterUpdateRecordEvent );
begin
  FProvider.AfterUpdateRecord := Value;
end;
function TCustomCachedDataSet.GetOnGetTableName: TGetTableNameEvent;
begin
  Result := FProvider.OnGetTableName;
end;
procedure TCustomCachedDataSet.SetOnGetTableName( Value: TGetTableNameEvent );
begin
  FProvider.OnGetTableName := Value;
end;
function TCustomCachedDataSet.GetOnUpdateData: TProviderDataEvent;
begin
  Result := FProvider.OnUpdateData;
end;
procedure TCustomCachedDataSet.SetOnUpdateData(Value: TProviderDataEvent);
begin
  FProvider.OnUpdateData := Value;
end;
function TCustomCachedDataSet.GetOnUpdateError: TResolverErrorEvent;
begin
  Result := FProvider.OnUpdateError;
end;
procedure TCustomCachedDataSet.SetOnUpdateError(Value: TResolverErrorEvent);
begin
  FProvider.OnUpdateError := Value;
end;
procedure TCustomCachedDataSet.LoadFromFile(const AFileName: string = '');
var
  SaveFile: string;
begin
  SaveFile := AFileName;
  inherited FileName := AFileName;
  inherited LoadFromFile(AFileName);
  inherited FileName := SaveFile;
end;
end.
