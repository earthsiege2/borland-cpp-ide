
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Client DataSet                                  }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DBClient;

{$R-,T-,H+,X+}

interface

uses Windows, SysUtils, ActiveX, Graphics, Classes, Controls, Forms, Db,
  DSIntf, DBCommon, Midas;

type

{ Exceptions }

  EDBClient = class(EDatabaseError)
  private
    FErrorCode: DBResult;
  public
    constructor Create(Message: string; ErrorCode: DBResult);
    property ErrorCode: DBResult read FErrorCode;
  end;

  EReconcileError = class(EDBClient)
  private
    FContext: string;
    FPreviousError: DBResult;
  public
    constructor Create(NativeError, Context: string;
      ErrorCode, PreviousError: DBResult);
    property Context: string read FContext;
    property PreviousError: DBResult read FPreviousError;
  end;

{ TCustomRemoteServer }

  TClientDataSet = class;

  TCustomRemoteServer = class(TCustomConnection)
  protected
    function GetServerList: OleVariant; virtual;
    procedure GetProviderNames(Proc: TGetStrProc); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    function GetServer: IAppServer; virtual;
  end;

{ TAggregate }

  TAggregate = class;
  TAggregates = class;
  TAggUpdateEvent = procedure(Agg: TAggregate) of object;

  TAggregate = class(TCollectionItem)
  private
    FExpression: string;
    FFldDesc: DSFLDDesc;
    FHAggregate: hDSAggregate;
    FAggregateName: String;
    FGroupingLevel: Integer;
    FDataSet: TClientDataSet;
    FIndexName: string;
    FDataBuffer: Array of Byte;
    FDataType: TFieldType;
    FDataSize: Integer;
    FDependentFields: TBits;
    FRecBufOfs: Integer;
    FInUse: Boolean;
    FActive: Boolean;
    FVisible: Boolean;
    FOutOfDate: Boolean;
    FOnUpdate: TAggUpdateEvent;
    procedure SetActive(Value: Boolean);
    procedure SetExpression(const Text: string);
    procedure SetGroupingLevel(GroupingLevel: Integer);
    procedure SetIndexName(Value: String);
  protected
    procedure Activate;
    property DependentFields: TBits read FDependentFields;
    property RecBufOfs: Integer read FRecBufOfs write FRecBufOfs;
  public
    constructor Create(Aggregates: TAggregates; ADataSet: TClientDataSet); reintroduce; overload;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    function GetDisplayName: string; override;
    function Value: Variant;
    property AggHandle: hDSAggregate read FHAggregate write FHAggregate;
    property InUse: Boolean read FInUse write FInUse default false;
    property DataSet: TClientDataSet read FDataSet;
    property DataSize: Integer read FDataSize;
    property DataType: TFieldType read FDataType;
  published
    property Active: Boolean read FActive write SetActive default False;
    property AggregateName: String read FAggregateName write FAggregateName;
    property Expression: string read FExpression write SetExpression;
    property GroupingLevel: Integer read FGroupingLevel write SetGroupingLevel default 0;
    property IndexName: string read FIndexName write SetIndexName;
    property Visible: Boolean read FVisible write FVisible default True;
    property OnUpdate: TAggUpdateEvent read FOnUpdate write FOnUpdate;
  end;

{ TAggregates }

  TAggregates = class(TCollection)
  private
    FOwner: TPersistent;
    function GetItem(Index: Integer): TAggregate;
    procedure SetItem(Index: Integer; Value: TAggregate);
  protected
    function GetOwner: TPersistent; override;
  public
    constructor Create(Owner: TPersistent);
    function Add: TAggregate;
    procedure Clear;
    function Find(const DisplayName: string): TAggregate;
    function IndexOf(const DisplayName: string): Integer;
    property Items[Index: Integer]: TAggregate read GetItem write SetItem; default;
  end;

{ TClientDataSet }

  TFieldDescList = array of DSFLDDesc;

  TKeyIndex = (kiLookup, kiRangeStart, kiRangeEnd, kiCurRangeStart,
    kiCurRangeEnd, kiSave);

  PRecInfo = ^TRecInfo;
  TRecInfo = packed record
    RecordNumber: Longint;
    BookmarkFlag: TBookmarkFlag;
    Attribute: DSAttr;
  end;

  PKeyBuffer = ^TKeyBuffer;
  TKeyBuffer = record
    Modified: Boolean;
    Exclusive: Boolean;
    FieldCount: Integer;
    Data: record end;
  end;

  TDataPacketFormat = (dfBinary, dfXML);
  
  TReconcileAction = (raSkip, raAbort, raMerge, raCorrect, raCancel, raRefresh);
  TReconcileErrorEvent = procedure(DataSet: TClientDataSet; E: EReconcileError;
    UpdateKind: TUpdateKind; var Action: TReconcileAction) of object;
  TRemoteEvent = procedure(Sender: TObject; var OwnerData: OleVariant) of object;

  TDataSetOption = (doDisableInserts, doDisableDeletes, doDisableEdits, doNoResetCall);
  TDataSetOptions = set of TDataSetOption;

  TFetchOption = (foRecord, foBlobs, foDetails);
  TFetchOptions = set of TFetchOption;

  TClientDataSet = class(TDataSet)
  private
    FActiveAggLists: TList;
    FAggFieldsUpdated: TBits;
    FAggFieldsInit: Boolean;
    FAggFieldsSize: Integer;
    FAggGrpIndOfs: Integer;
    FAggFieldsOfs: Integer;
    FAggGrpIndSize: Integer;
    FAggregates: TAggregates;
    FAggregatesActive: Boolean;
    FCommandText: string;
    FDSBase: IDSBase;
    FDSCursor: IDSCursor;
    FDSOptions: TDataSetOptions;
    FFindCursor: IDSCursor;
    FCloneSource: TClientDataSet;
    FReconcileDataSet: TClientDataSet;
    FSavedPacket: TDataPacket;
    FDeltaPacket: TDataPacket;
    FParams: TParams;
    FIndexDefs: TIndexDefs;
    FIndexName: string;
    FExprFilter: HDSFilter;
    FFuncFilter: HDSFilter;
    FFileName: string;
    FFilterBuffer: PChar;
    FGroupingLevel: Integer;
    FLastParentBM: array of byte;
    FMasterLink: TMasterDataLink;
    FIndexFieldMap: DSKEY;
    FKeyBuffers: array[TKeyIndex] of PKeyBuffer;
    FKeyBuffer: PKeyBuffer;
    FNewValueBuffer: PChar;
    FOldValueBuffer: PChar;
    FCurValueBuffer: PChar;
    FIndexFieldCount: Integer;
    FIndexGroupingLevel: Integer;
    FAppServer: IAppServer;
    FProviderName: string;
    FRemoteServer: TCustomRemoteServer;
    FPacketRecords: Integer;
    FConstDisableCount: Integer;
    FMaxAggGroupingLevel: Integer;
    FParentDataSet: TClientDataSet;
    { Word & Byte size data members }
    FKeySize: Word;
    FRecordSize: Word;
    FBookmarkOfs: Word;
    FRecInfoOfs: Word;
    FRecBufSize: Word;
    FReadOnly: Boolean;
    FFieldsIndex: Boolean;
    FCanModify: Boolean;
    FInReconcileCallback: Boolean;
    FNotifyCallback: Boolean;
    FOpeningFile: Boolean;
    FProviderEOF: Boolean;
    FFetchOnDemand: Boolean;
    FStoreDefs: Boolean;
    FSavePacketOnClose: Boolean;
    FOnReconcileError: TReconcileErrorEvent;
    FStatusFilter: TUpdateStatusSet;
    FBeforeApplyUpdates: TRemoteEvent;
    FAfterApplyUpdates: TRemoteEvent;
    FBeforeGetRecords: TRemoteEvent;
    FAfterGetRecords: TRemoteEvent;
    FBeforeRowRequest: TRemoteEvent;
    FAfterRowRequest: TRemoteEvent;
    FBeforeExecute: TRemoteEvent;
    FAfterExecute: TRemoteEvent;
    FBeforeGetParams: TRemoteEvent;
    FAfterGetParams: TRemoteEvent;
    procedure AddExprFilter(const Expr: string; Options: TFilterOptions);
    procedure AddFuncFilter;
    function CalcFieldsCallBack(RecBuf: PChar): DBResult; stdcall;
    procedure CheckFieldProps;
    procedure CheckMasterRange;
    procedure CheckProviderEOF;
    procedure ClearActiveAggs;
    procedure ClearSavedPacket;
    procedure CloseAggs;
    function CreateDSBase: IDSBase;
    function CreateDSCursor(SourceCursor: IDSCursor): IDSCursor;
    procedure DecodeIndexDesc(const IndexDesc: DSIDXDesc;
      var Name, Fields, DescFields, CaseInsFields: string; var Options: TIndexOptions);
    procedure EncodeFieldDesc(var FieldDesc: DSFLDDesc; const Name: string;
      DataType: TFieldType; Size, Precision: Integer; Calculated: Boolean;
      Attributes: TFieldAttributes);
    procedure EncodeIndexDesc(var IndexDesc: DSIDXDesc;
      const Name, Fields, DescFields, CaseInsFields: string; Options: TIndexOptions);
    procedure FetchMoreData(All: Boolean);
    function FilterCallback(RecBuf: PChar): Bool; stdcall;
    procedure DoAggUpdates(IsUpdate: Boolean);
    function  GetActiveAggs(Index: Integer) : TList;
    function GetActiveRecBuf(var RecBuf: PChar): Boolean;
    procedure GetAggFieldData(Buffer: PChar);
    function GetChangeCount: Integer;
    function GetData: OleVariant;
    function GetDataSize: Integer;
    function GetDelta: OleVariant;
    function GetIndexDefs: TIndexDefs;
    function GetIndexFieldNames: string;
    function GetIndexName: string;
    function GetLogChanges: Boolean;
    function GetMasterFields: string;
    function GetAppServer: IAppServer;
    function GetProviderEOF: Boolean;
    function GetSavePoint: Integer;
    function GetHasAppServer: Boolean;
    procedure InitBufferPointers(GetProps: Boolean);
    function InternalGetGroupState(Level: Integer): TGroupPosInds;
    procedure InternalFetch(Options: TFetchOptions);
    procedure MasterChanged(Sender: TObject);
    procedure MasterDisabled(Sender: TObject);
    procedure NotifyCallback; stdcall;
    procedure ReadData(Stream: TStream);
    function ReconcileCallback(iRslt: Integer; iUpdateKind: DSAttr;
      iResAction: dsCBRType; iErrCode: Integer; pErrMessage, pErrContext: PChar;
      pRecUpd, pRecOrg, pRecConflict: Pointer; iLevels: Integer;
      piFieldIDs: PInteger): dsCBRType; stdcall;
    procedure ResetAgg(Agg: TAggregate; DeleteFirst: Boolean);
    procedure ResetAllAggs(Value: Boolean);
    procedure ResetGrouping;
    procedure SetAggsActive(Value: Boolean);
    procedure SaveDataPacket(XMLFormat: Boolean = False);
    procedure SetData(const Value: OleVariant);
    procedure SetDataSource(Value: TDataSource);
    procedure SetIndex(const Value: string; FieldsIndex: Boolean);
    procedure SetIndexDefs(Value: TIndexDefs);
    procedure SetIndexFieldNames(const Value: string);
    procedure SetIndexName(const Value: string);
    procedure SetLogChanges(Value: Boolean);
    procedure SetMasterFields(const Value: string);
    procedure SetNotifyCallback;
    procedure SetParams(Value: TParams);
    procedure SetAppServer(Value: IAppServer);
    procedure SetProviderEOF(Value: Boolean);
    procedure SetProviderName(const Value: string);
    procedure SetReadOnly(Value: Boolean);
    procedure SetSavePoint(Value: Integer);
    procedure SortOnFields(Cursor: IDSCursor; const Fields: string;
      CaseInsensitive, Descending: Boolean);
    procedure SetupConstraints;
    procedure SetupInternalCalcFields(Add: Boolean);
    procedure WriteData(Stream: TStream);
    procedure SetAggregates(Value: TAggregates);
    procedure SetStatusFilter(const Value: TUpdateStatusSet);
  protected
    { DataIntf Helper functions }
    function DoApplyUpdates(Delta: OleVariant; MaxErrors: Integer; out ErrorCount: Integer): OleVariant; virtual;
    function DoGetRecords(Count: Integer; out RecsOut: Integer; Options: Integer;
       const CommandText: WideString; Params: OleVariant): OleVariant; virtual;
    function DoRowRequest(Row: OleVariant; RequestType: Integer): OleVariant; virtual;
    procedure DoExecute(Params: OleVariant); virtual;
    { DataSet methods }
    procedure ResetAggField(Field: TField); override;
    procedure ActivateFilters;
    procedure AddDataPacket(const Data: OleVariant; HitEOF: Boolean); virtual;
    procedure AddFieldDesc(FieldDescs: TFieldDescList; var DescNo: Integer;
      var FieldID: Integer; FieldDefs: TFieldDefs);
    procedure AllocKeyBuffers;
    function AllocRecordBuffer: PChar; override;
    procedure Check(Status: DBResult);
    procedure CheckDetailRecords; virtual;
    procedure CheckSetKeyMode;
    procedure ClearCalcFields(Buffer: PChar); override;
    procedure CloseCursor; override;
    procedure DataConvert(Field: TField; Source, Dest: Pointer; ToNative: Boolean); override;
    procedure DataEvent(Event: TDataEvent; Info: Longint); override;
    procedure DeactivateFilters;
    procedure DefChanged(Sender: TObject); override;
    procedure DefineProperties(Filer: TFiler); override;
    procedure DestroyLookupCursor; virtual;
    procedure DoBeforeInsert; override;
    procedure DoOnNewRecord; override;
    function FindRecord(Restart, GoForward: Boolean): Boolean; override;
    procedure FreeKeyBuffers;
    procedure FreeRecordBuffer(var Buffer: PChar); override;
    function GetAggregateValue(Field: TField): Variant; override;
    procedure GetBookmarkData(Buffer: PChar; Data: Pointer); override;
    function GetBookmarkFlag(Buffer: PChar): TBookmarkFlag; override;
    function GetCanModify: Boolean; override;
    function GetDataSource: TDataSource; override;
    function GetIndexField(Index: Integer): TField;
    function GetIndexFieldCount: Integer;
    function GetIsIndexField(Field: TField): Boolean; override;
    function GetKeyBuffer(KeyIndex: TKeyIndex): PKeyBuffer;
    function GetKeyExclusive: Boolean;
    function GetKeyFieldCount: Integer;
    function GetRecord(Buffer: PChar; GetMode: TGetMode; DoCheck: Boolean): TGetResult; override;
    function GetRecordCount: Integer; override;
    function GetRecNo: Integer; override;
    function GetRecordSize: Word; override;
    function GetRemoteServer: TCustomRemoteServer; virtual;
    function GetStateFieldValue(State: TDataSetState; Field: TField): Variant; override;
    function InitKeyBuffer(Buffer: PKeyBuffer): PKeyBuffer;
    procedure InitRecord(Buffer: PChar); override;
    procedure InternalAddRecord(Buffer: Pointer; Append: Boolean); override;
    procedure InternalCancel; override;
    procedure InternalClose; override;
    procedure InternalDelete; override;
    procedure InternalEdit; override;
    procedure InternalFirst; override;
    function InternalGetOptionalParam(const ParamName: string;
      FieldNo: Integer = 0): OleVariant;
    procedure InternalGotoBookmark(Bookmark: TBookmark); override;
    procedure InternalHandleException; override;
    procedure InternalInitFieldDefs; override;
    procedure InternalInitRecord(Buffer: PChar); override;
    procedure InternalInsert; override;
    procedure InternalLast; override;
    procedure InternalOpen; override;
    procedure InternalRefresh; override;
    procedure InternalPost; override;
    procedure InternalSetToRecord(Buffer: PChar); override;
    function IsCursorOpen: Boolean; override;
    procedure Loaded; override;
    function LocateRecord(const KeyFields: string; const KeyValues: Variant;
      Options: TLocateOptions; SyncCursor: Boolean): Boolean;
    procedure OpenCursor(InfoQuery: Boolean); override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure PostKeyBuffer(Commit: Boolean);
    procedure RefreshInternalCalcFields(Buffer: PChar); override;
    procedure ReadDataPacket(Stream: TStream; ReadSize: Boolean);
    function ResetCursorRange: Boolean;
    procedure SetBookmarkData(Buffer: PChar; Data: Pointer); override;
    procedure SetBookmarkFlag(Buffer: PChar; Value: TBookmarkFlag); override;
    function SetCursorRange: Boolean;
    procedure SetDataSetField(const Value: TDataSetField); override;
    procedure SetFieldData(Field: TField; Buffer: Pointer); override;
    procedure SetFilterData(const Text: string; Options: TFilterOptions);
    procedure SetFiltered(Value: Boolean); override;
    procedure SetFilterOptions(Value: TFilterOptions); override;
    procedure SetFilterText(const Value: string); override;
    procedure SetIndexField(Index: Integer; Value: TField);
    procedure SetKeyBuffer(KeyIndex: TKeyIndex; Clear: Boolean);
    procedure SetKeyExclusive(Value: Boolean);
    procedure SetKeyFieldCount(Value: Integer);
    procedure SetKeyFields(KeyIndex: TKeyIndex; const Values: array of const);
    procedure SetLinkRanges(MasterFields: TList);
    procedure SetOnFilterRecord(const Value: TFilterRecordEvent); override;
    procedure SetRecNo(Value: Integer); override;
    procedure SetRemoteServer(Value: TCustomRemoteServer); virtual;
    procedure SwitchToIndex(const IndexName: string);
    procedure SyncCursors(Cursor1, Cursor2: IDSCursor);
    procedure UpdateIndexDefs; override;
    procedure WriteDataPacket(Stream: TStream; WriteSize: Boolean; XMLFormat: Boolean = False);
    function ConstraintsStored: Boolean;
    property DSBase: IDSBase read FDSBase write FDSBase;
    property DSCursor: IDSCursor read FDSCursor;
    property ProviderEOF: Boolean read GetProviderEOF write SetProviderEOF;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure AddIndex(const Name, Fields: string; Options: TIndexOptions;
      const DescFields: string = ''; const CaseInsFields: string = '';
      const GroupingLevel: Integer = 0);
    procedure AppendData(const Data: OleVariant; HitEOF: Boolean);
    procedure ApplyRange;
    function ApplyUpdates(MaxErrors: Integer): Integer; virtual;
    function BookmarkValid(Bookmark: TBookmark): Boolean; override;
    procedure Cancel; override;
    procedure CancelRange;
    procedure CancelUpdates;
    function CreateBlobStream(Field: TField; Mode: TBlobStreamMode): TStream; override;
    procedure CreateDataSet;
    procedure CloneCursor(Source: TClientDataSet; Reset: Boolean;
      KeepSettings: Boolean = False);
    function CompareBookmarks(Bookmark1, Bookmark2: TBookmark): Integer; override;
    function ConstraintsDisabled: Boolean;
    function DataRequest(Data: OleVariant): OleVariant; virtual;
    procedure DeleteIndex(const Name: string);
    procedure DisableConstraints;
    procedure EnableConstraints;
    procedure EditKey;
    procedure EditRangeEnd;
    procedure EditRangeStart;
    procedure EmptyDataSet;
    procedure Execute; virtual;
    procedure FetchBlobs;
    procedure FetchDetails;
    procedure RefreshRecord;
    procedure FetchParams;
    function FindKey(const KeyValues: array of const): Boolean; virtual;
    procedure FindNearest(const KeyValues: array of const);
    function GetCurrentRecord(Buffer: PChar): Boolean; override;
    function GetFieldData(Field: TField; Buffer: Pointer): Boolean; override;
    function GetFieldData(FieldNo: Integer; Buffer: Pointer): Boolean; overload; override;
    function GetGroupState(Level: Integer): TGroupPosInds;
    procedure GetIndexInfo(IndexName: string);
    procedure GetIndexNames(List: TStrings);
    function GetNextPacket: Integer;
    function GetOptionalParam(const ParamName: string): OleVariant;
    procedure GotoCurrent(DataSet: TClientDataSet);
    function GotoKey: Boolean;
    procedure GotoNearest;
    property HasAppServer: Boolean read GetHasAppServer;
    function Locate(const KeyFields: string; const KeyValues: Variant;
      Options: TLocateOptions): Boolean; override;
    function Lookup(const KeyFields: string; const KeyValues: Variant;
      const ResultFields: string): Variant; override;
    procedure LoadFromFile(const FileName: string = '');
    procedure LoadFromStream(Stream: TStream);
    procedure MergeChangeLog;
    procedure Post; override;
    function Reconcile(const Results: OleVariant): Boolean;
    procedure RevertRecord;
    procedure SaveToFile(const FileName: string = ''; Format: TDataPacketFormat = dfBinary);
    procedure SaveToStream(Stream: TStream; Format: TDataPacketFormat = dfBinary);
    procedure SetAltRecBuffers(Old, New, Cur: PChar);
    procedure SetKey;
    procedure SetOptionalParam(const ParamName: string; const Value: OleVariant;
      IncludeInDelta: Boolean = False);
    procedure SetProvider(Provider: TComponent);
    procedure SetRange(const StartValues, EndValues: array of const);
    procedure SetRangeEnd;
    procedure SetRangeStart;
    function UndoLastChange(FollowChange: Boolean): Boolean;
    function UpdateStatus: TUpdateStatus; override;
    property ActiveAggs[Index: Integer] : TList read GetActiveAggs;
    property ChangeCount: Integer read GetChangeCount;
    property CloneSource: TClientDataSet read FCloneSource;
    property Data: OleVariant read GetData write SetData;
    property AppServer: IAppServer read GetAppServer write SetAppServer;
    property DataSize: Integer read GetDataSize;
    property Delta: OleVariant read GetDelta;
    property GroupingLevel: Integer read FGroupingLevel;
    property IndexFieldCount: Integer read GetIndexFieldCount;
    property IndexFields[Index: Integer]: TField read GetIndexField write SetIndexField;
    property KeyExclusive: Boolean read GetKeyExclusive write SetKeyExclusive;
    property KeyFieldCount: Integer read GetKeyFieldCount write SetKeyFieldCount;
    property KeySize: Word read FKeySize;
    property LogChanges: Boolean read GetLogChanges write SetLogChanges;
    property SavePoint: Integer read GetSavePoint write SetSavePoint;
    property StatusFilter: TUpdateStatusSet read FStatusFilter write SetStatusFilter;
  published
    property Active;
    property Aggregates: TAggregates read FAggregates write SetAggregates;
    property AggregatesActive: Boolean read FAggregatesActive write SetAggsActive default False;
    property AutoCalcFields;
    property CommandText: string read FCommandText write FCommandText;
    property Constraints stored ConstraintsStored;
    property DataSetField;
    property FileName: string read FFileName write FFileName;
    property Filter;
    property Filtered;
    property FilterOptions;
    property FieldDefs stored FStoreDefs;
    property IndexDefs: TIndexDefs read GetIndexDefs write SetIndexDefs stored FStoreDefs;
    property IndexFieldNames: string read GetIndexFieldNames write SetIndexFieldNames;
    property IndexName: string read GetIndexName write SetIndexName;
    property FetchOnDemand: Boolean read FFetchOnDemand write FFetchOnDemand default True;
    property MasterFields: string read GetMasterFields write SetMasterFields;
    property MasterSource: TDataSource read GetDataSource write SetDataSource;
    property ObjectView default True;
    property PacketRecords: Integer read FPacketRecords write FPacketRecords default -1;
    property Params: TParams read FParams write SetParams;
    property ProviderName: string read FProviderName write SetProviderName;
    property ReadOnly: Boolean read FReadOnly write SetReadOnly default False;
    property RemoteServer: TCustomRemoteServer read GetRemoteServer write SetRemoteServer;
    property StoreDefs: Boolean read FStoreDefs write FStoreDefs default False;
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
    property OnReconcileError: TReconcileErrorEvent read FOnReconcileError write FOnReconcileError;
    property BeforeApplyUpdates: TRemoteEvent read FBeforeApplyUpdates write FBeforeApplyUpdates;
    property AfterApplyUpdates: TRemoteEvent read FAfterApplyUpdates write FAfterApplyUpdates;
    property BeforeGetRecords: TRemoteEvent read FBeforeGetRecords write FBeforeGetRecords;
    property AfterGetRecords: TRemoteEvent read FAfterGetRecords write FAfterGetRecords;
    property BeforeRowRequest: TRemoteEvent read FBeforeRowRequest write FBeforeRowRequest;
    property AfterRowRequest: TRemoteEvent read FAfterRowRequest write FAfterRowRequest;
    property BeforeExecute: TRemoteEvent read FBeforeExecute write FBeforeExecute;
    property AfterExecute: TRemoteEvent read FAfterExecute write FAfterExecute;
    property BeforeGetParams: TRemoteEvent read FBeforeGetParams write FBeforeGetParams;
    property AfterGetParams: TRemoteEvent read FAfterGetParams write FAfterGetParams;
  end;

{ TClientBlobStream }

  TClientBlobStream = class(TMemoryStream)
  private
    FField: TBlobField;
    FDataSet: TClientDataSet;
    FBuffer: PChar;
    FFieldNo: Integer;
    FModified: Boolean;
    procedure ReadBlobData;
  public
    constructor Create(Field: TBlobField; Mode: TBlobStreamMode);
    destructor Destroy; override;
    function Write(const Buffer; Count: Longint): Longint; override;
    procedure Truncate;
  end;

const
  AllParamTypes = [ptUnknown, ptInput, ptOutput, ptInputOutput, ptResult];

function PackageParams(Params: TParams; Types: TParamTypes = AllParamTypes): OleVariant;
procedure UnpackParams(const Source: OleVariant; Dest: TParams);

const
  AllRecords = -1;

implementation

uses DBConsts, MidConst, Provider, TypInfo, ComObj;

{ Exceptions }

constructor EDBClient.Create(Message: string; ErrorCode: DBResult);
begin
  FErrorCode := ErrorCode;
  inherited Create(Message);
end;

constructor EReconcileError.Create(NativeError, Context: string;
  ErrorCode, PreviousError: DBResult);
begin
  FContext := Context;
  FPreviousError := PreviousError;
  inherited Create(NativeError, ErrorCode);
end;

{ Utility functions }

function PackageParams(Params: TParams; Types: TParamTypes = AllParamTypes): OleVariant;
var
  I, Idx, Count: Integer;
begin
  Result := NULL;
  Count := 0;
  for I := 0 to Params.Count - 1 do
    if Params[I].ParamType in Types then Inc(Count);
  if Count > 0 then
  begin
    Idx := 0;
    Result := VarArrayCreate([0, Count - 1], varVariant);
    for I := 0 to Params.Count - 1 do
      with Params[I] do
        if ParamType in Types then
        begin
          Result[Idx] := VarArrayOf([Name, Value, Ord(DataType), Ord(ParamType)]);
          Inc(Idx);
        end;
  end;
end;

procedure UnpackParams(const Source: OleVariant; Dest: TParams);
var
  TempParams: TParams;
  i: Integer;
begin
  if not VarIsNull(Source) and VarIsArray(Source) and VarIsArray(Source[0]) then
  begin
    TempParams := TParams.Create;
    try
      for i := 0 to VarArrayHighBound(Source, 1) do
      begin
        with TParam(TempParams.Add) do
        begin
          if VarArrayHighBound(Source[i], 1) > 1 then
            DataType := TFieldType(Source[i][2]);
          if VarArrayHighBound(Source[i], 1) > 2 then
            ParamType := TParamType(Source[i][3]);
          Name := Source[i][0];
          Value := Source[i][1];
        end;
      end;
      Dest.Assign(TempParams);
    finally
      TempParams.Free;
    end;
  end;
end;

{ TCustomRemoteServer }

constructor TCustomRemoteServer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  RCS;
end;

function TCustomRemoteServer.GetServerList: OleVariant;
begin
  Result := NULL;
end;

function TCustomRemoteServer.GetServer: IAppServer;
begin
  Result := nil;
end;

procedure TCustomRemoteServer.GetProviderNames(Proc: TGetStrProc);
begin
end;

{ TClientDataSet }

constructor TClientDataSet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FMasterLink := TMasterDataLink.Create(Self);
  FMasterLink.OnMasterChange := MasterChanged;
  FMasterLink.OnMasterDisable := MasterDisabled;
  FPacketRecords := AllRecords;
  FFetchOnDemand := True;
  FParams := TParams.Create(Self);
  FAggregates := TAggregates.Create(Self);
  FActiveAggLists := TList.Create;
  FOpeningFile := False;
  ObjectView := True;
  RCS;
end;

destructor TClientDataSet.Destroy;
begin
  FSavePacketOnClose := False;
  inherited Destroy;
  ClearSavedPacket;
  FreeDataPacket(FDeltaPacket);
  SetRemoteServer(nil);
  AppServer := nil;
  FMasterLink.Free;
  FIndexDefs.Free;
  FParams.Free;
  FAggregates.Free;
  ClearActiveAggs;
  FActiveAggLists.Free;
  FAggFieldsUpdated.Free;
end;

function TClientDataSet.CreateDSBase: IDSBase;
begin
  CreateDbClientObject(CLSID_DSBase, IDSBase, Result);
end;

function TClientDataSet.CreateDSCursor(SourceCursor: IDSCursor): IDSCursor;
begin
  CreateDbClientObject(CLSID_DSCursor, IDSCursor, Result);
  if Assigned(SourceCursor) then
    Check(Result.CloneCursor(SourceCursor)) else
    Check(Result.InitCursor(FDSBase));
end;

procedure TClientDataSet.SetParams(Value: TParams);
begin
  FParams.Assign(Value);
end;

procedure TClientDataSet.SetOptionalParam(const ParamName: string;
  const Value: OleVariant; IncludeInDelta: Boolean);
const
  ParamTypeMap: array[varSmallInt..varByte] of Integer =
    ( dsfldINT, dsfldINT, dsfldFLOATIEEE, dsfldFLOATIEEE, dsfldBCD,
      dsfldTIMESTAMP, dsfldZSTRING, 0, 0, dsfldBOOL, 0, 0, 0, 0, 0, dsfldINT);
  ParamTypeSize: array[varSmallInt..varByte] of Integer =
    ( SizeOf(SmallInt), SizeOf(Integer), SizeOf(Single), SizeOf(Double),
      SizeOf(Currency), SizeOf(TDateTime), 0, 0, 0, SizeOf(WordBool), 0, 0, 0,
      0, 0, SizeOf(Byte));
var
  ParamType, ParamLen, t, l: DWord;
  S: string;
  P: Pointer;
  Unlock: Boolean;
  V, Name: Pointer;
begin
  CheckActive;
  if ((VarType(Value) and varTypeMask) in [varSmallInt, varInteger, varSingle,
      varDouble, varCurrency, varDate, varOleStr, varBoolean, varByte]) and
     ((not VarIsArray(Value)) or (VarType(Value) and varTypeMask = varByte)) then
  begin
    Unlock := False;
    try
      ParamType := ParamTypeMap[VarType(Value) and varTypeMask];
      ParamLen := ParamTypeSize[VarType(Value) and varTypeMask];
      if ParamType = dsfldZSTRING then
      begin
        S := Value;
        P := PChar(S);
        ParamLen := Length(S) + 1;
      end else
      if VarIsArray(Value) then
      begin
        ParamType := dsfldBYTES;
        ParamLen := VarArrayHighBound(Value, 1) - VarArrayLowBound(Value, 1);
        P := VarArrayLock(Value);
        Unlock := True;
      end else
      if (VarType(Value) and varByRef) = varByRef then
        P := TVarData(Value).VPointer else
        P := @TVarData(Value).VPointer;
      ParamType := ParamType shl dsSizeBitsLen or ParamLen;
      if IncludeInDelta then
        ParamType := ParamType or dsIncInDelta;
      Name := PChar(ParamName);
      if FDSBase.GetOptParameter(0, 0, Name, t, l, v) = 0 then
        Check(FDSBase.DropOptParameter(0, PChar(ParamName)));
      Check(FDSBase.AddOptParameter(0, PChar(ParamName), ParamType, ParamLen, P));
    finally
      if Unlock then
        VarArrayUnlock(Value);
    end;
  end else
    DatabaseError(SInvalidOptParamType, Self);
end;

function TClientDataSet.GetOptionalParam(const ParamName: string): OleVariant;
begin
  Result := InternalGetOptionalParam(ParamName);
end;

function TClientDataSet.InternalGetOptionalParam(const ParamName: string;
  FieldNo: Integer = 0): OleVariant;
var
  ParamType, ParamLen: DWord;
  Name: PChar;
  Value, P: Pointer;
  S: string;
begin
  if not Assigned(FDSBase) then CheckActive;
  VarClear(Result);
  Name := PChar(ParamName);
  if FDSBase.GetOptParameter(0, FieldNo, Pointer(Name), ParamType,
    ParamLen, Value) <> 0 then Exit;
  case (ParamType and dsTypeBitsMask) shr dsSizeBitsLen of
    dsfldINT,
    dsfldUINT:
    begin
      case ParamLen of
        1: Result := Byte(Value^);
        2: Result := SmallInt(Value^);
        4: Result := Integer(Value^);
      end;
    end;
    dsfldBOOL: Result := WordBool(Value^);
    dsfldFLOATIEEE: Result := Double(Value^);
    dsfldBCD: Result := Currency(Value^);
    dsfldDATE: Result := TDateTimeRec(Value^).Date - DateDelta;
    dsfldTIME: Result := TDateTimeRec(Value^).Time / MSecsPerDay;
    dsfldTIMESTAMP: Result := (TDateTimeRec(Value^).DateTime / MSecsPerDay) - DateDelta;
    dsfldZSTRING:
    begin
      SetString(S, PChar(Value), ParamLen-1);
      Result := S;
    end;
    dsfldBYTES:
    begin
      Result := VarArrayCreate([0, ParamLen], varByte);
      P := VarArrayLock(Result);
      try
        Move(Value^, P^, ParamLen);
      finally
        VarArrayUnlock(Result);
      end;
    end;
  else
    VarClear(Result);
  end;
end;

procedure TClientDataSet.OpenCursor(InfoQuery: Boolean);
var
  RecsOut: Integer;
  Options: TGetRecordOptions;
  DataPacket: TDataPacket;
  Stream: TFileStream;
begin
  FProviderEOF := True;
  FSavePacketOnClose := False;
  if not FOpeningFile and (FileName <> '') and FileExists(FileName) then
  begin
    Stream := TFileStream.Create(FileName, fmOpenRead or fmShareDenyWrite);
    try
      ReadDataPacket(Stream, False);
    finally
      Stream.Free;
    end;
  end;
  if DataSetField <> nil then
  begin
    FParentDataSet := DataSetField.DataSet as TClientDataSet;
    OpenParentDataSet(FParentDataSet);
    Check(FParentDataSet.DSBase.GetEmbeddedDS(DataSetField.FieldNo, FDSBase));
    FieldDefs.HiddenFields := FParentDataSet.FieldDefs.HiddenFields;
  end
  else if not Assigned(FDSBase) then
  begin
    if Assigned(FSavedPacket) then DataPacket := FSavedPacket else
    begin
      Options := [grMetaData];
      DataPacket := VarToDataPacket(DoGetRecords(FPacketRecords, RecsOut,
        Byte(Options), CommandText, PackageParams(Params)));
      ProviderEOF := RecsOut <> FPacketRecords;
    end;
    if not Assigned(DataPacket) then DatabaseError(SNoDataProvider, Self);
    FDSBase := CreateDSBase;
    Check(FDSBase.AppendData(DataPacket, ProviderEOF));
  end;
  inherited OpenCursor(InfoQuery);
  if not InfoQuery and Assigned(FCloneSource) and not FCloneSource.BOF then
  begin
    SyncCursors(FDSCursor, FCloneSource.FDSCursor);
    CursorPosChanged;
    Resync([]);
  end;
  { DSBase now has the data packet so we don't need to hold on to it }
  ClearSavedPacket;
  FSavePacketOnClose := True;
end;

procedure TClientDataSet.FetchParams;
var
  OwnerData: OleVariant;
begin
  if Assigned(FBeforeExecute) then FBeforeExecute(Self, OwnerData);
  UnpackParams(AppServer.AS_GetParams(ProviderName, OwnerData), Params);
  if Assigned(FAfterExecute) then FAfterExecute(Self, OwnerData);
end;

procedure TClientDataSet.Check(Status: DBResult);
var
  ErrMsg: array[0..2048] of Char;
begin
  if Status <> 0 then
  begin
    FDSBase.GetErrorString(Status, ErrMsg);
    raise EDBClient.Create(ErrMsg, Status);
  end;
end;

procedure TClientDataSet.CloseCursor;
var
  Params: OleVariant;
  RecsOut: Integer;
  Options: TGetRecordOptions;
begin
  if (FileName <> '') and not (csDesigning in ComponentState) then
    SaveToFile(FileName);
  inherited CloseCursor;
  if HasAppServer then
  begin
    if not (csDestroying in ComponentState) then
    begin
      if FMasterLink.Active and (FMasterLink.Fields.Count > 0) and
        (PacketRecords = 0) then
        Params := Null else
        Params := Unassigned;
      if not (doNoResetCall in FDSOptions) then
      begin
        Options := [grReset];
        DoGetRecords(0, RecsOut, Byte(Options), '', Unassigned);
      end;
      FAppServer := nil;
    end;
  end
  else if FSavePacketOnClose  and (FileName <> '') then
    SaveDataPacket;
  FDSBase := nil;
  FParentDataSet := nil;
end;

procedure TClientDataSet.DefChanged(Sender: TObject);
begin
  FStoreDefs := True;
end;

procedure TClientDataSet.InternalInitFieldDefs;
var
  FieldID, I: Integer;
  FieldDescs: TFieldDescList;
  CursorProps: DSProps;
begin
  FDSBase.SetProp(dspropCOMPRESSARRAYS, Integer(True));
  Check(FDSBase.GetProps(CursorProps));
  SetLength(FieldDescs, CursorProps.iFields);
  Check(FDSBase.GetFieldDescs(PDSFldDesc(FieldDescs)));
  FieldDefs.Clear;
  I := 0;
  FieldID := 1;
  while I < CursorProps.iFields do
    AddFieldDesc(FieldDescs, I, FieldID, FieldDefs);
end;

type
  TPropReader = class(TReader);

procedure TClientDataSet.CheckFieldProps;

  procedure GetTypeName(Field: TObjectField);
  var
    V: Variant;
    i: Integer;
  begin
    V := InternalGetOptionalParam(szTYPENAME, Field.FieldNo);
    if not VarIsNull(V) and not VarIsEmpty(V) then
      Field.ObjectType := V;
    if Field.DataType in [ftADT, ftArray] then
      for i := 0 to Field.FieldCount - 1 do
        if Field.Fields[i] is TObjectField then
          GetTypeName(TObjectField(Field.Fields[i]));
  end;

var
  V: Variant;
  P: Pointer;
  Stream: TMemoryStream;
  Reader: TPropReader;
  i: Integer;
begin
  Stream := TMemoryStream.Create;
  try
    for i := 0 to FieldCount - 1 do
    begin
      if Fields[i] is TObjectField then
        GetTypeName(TObjectField(Fields[i]));
      V := InternalGetOptionalParam(szORIGIN, Fields[i].FieldNo);
      if not VarIsNull(V) and not VarIsEmpty(V) then
        Fields[i].Origin := VarToStr(V);
      V := InternalGetOptionalParam(szFIELDPROPS, Fields[i].FieldNo);
      if VarIsNull(V) or VarIsEmpty(V) or not VarIsArray(V) then continue;
      Stream.Size := VarArrayHighBound(V, 1) - SizeOf(Integer);
      P := VarArrayLock(V);
      try
        Stream.Position := 0;
        Stream.Write(Pointer(Integer(P) + SizeOf(Integer))^, Stream.Size);
        Stream.Position := 0;
      finally
        VarArrayUnlock(V);
      end;
      V := NULL;
      Reader := TPropReader.Create(Stream, 1024);
      try
        Reader.ReadListBegin;
        while not Reader.EndOfList do
          Reader.ReadProperty(Fields[i]);
      finally
        Stream.Clear;
        Reader.Free;
      end;
    end;
  finally
    Stream.Free;
  end;
end;

procedure TClientDataSet.InternalOpen;

  function GetBoolParam(const ParamName: string): Boolean;
  var
    V: OleVariant;
  begin
    V := GetOptionalParam(ParamName);
    Result := not VarIsNull(V) and not VarIsEmpty(V) and (VarType(V) = varBoolean);
    if Result then
      Result := V;
  end;

var
  CursorProps: DSProps;
begin
  if Assigned(FCloneSource) then
    FDSCursor := CreateDSCursor(FCloneSource.FDSCursor)
  else
  begin
    SetupInternalCalcFields(True);
    FDSCursor := CreateDSCursor(nil);
  end;
  if DataSetField <> nil then
    with FParentDataSet do
    begin
      if State = dsInActive then
      begin
        DSCursor.MoveToBOF;
        DSCursor.MoveRelative(1);
      end;
      Check(DSCursor.LinkCursors(0, nil, nil, Self.FDSCursor));
    end;
  FDSOptions := [];
  if GetBoolParam(szDISABLE_EDITS) then
    Include(FDSOptions, doDisableEdits);
  if GetBoolParam(szDISABLE_INSERTS) then
    Include(FDSOptions, doDisableInserts);
  if GetBoolParam(szDISABLE_DELETES) then
    Include(FDSOptions, doDisableDeletes);
  if GetBoolParam(szNO_RESET_CALL) then
    Include(FDSOptions, doNoResetCall);
  Check(FDSCursor.GetCursorProps(CursorProps));
  FRecordSize := CursorProps.iRecBufSize;
  BookmarkSize := CursorProps.iBookmarkSize;
  SetLength(FLastParentBM, BookMarkSize);
  FCanModify := not CursorProps.bReadOnly;
  FieldDefs.Updated := False;
  FieldDefs.Update;
  FieldDefList.Update;
  IndexDefs.Updated := False;
  GetIndexInfo('');
  if DefaultFields then CreateFields;
  BindFields(True);
  CheckFieldProps;
  AllocKeyBuffers;
  FDSCursor.MoveToBOF;
  if not Assigned(FCloneSource) then
  begin
    if InternalCalcFields and not (csDesigning in ComponentState) then
      Check(FDSBase.SetFieldCalculation(Integer(Self),
        @TClientDataSet.CalcFieldsCallback));
    if FIndexName <> '' then
       if FFieldsIndex then
         SortOnFields(FDSCursor, FIndexName, False, False) else
         SwitchToIndex(FIndexName);
    CheckMasterRange;
    if FReadOnly then FDSBase.SetProp(dspropREADONLY, Integer(True));
    ResetAllAggs(FAggregatesActive);
    if Filtered then ActivateFilters;
  end;
  InitBufferPointers(False);
  if (DataSetField <> nil) and FetchOnDemand then
    CheckDetailRecords;
  SetupConstraints;
end;

procedure TClientDataSet.InternalClose;
begin
  if Filtered then DeactivateFilters;
  FreeKeyBuffers;
  if not Assigned(FCloneSource) then
    SetupInternalCalcFields(False);
  BindFields(False);
  if DefaultFields then DestroyFields;
  CloseAggs;
  FIndexFieldCount := 0;
  FKeySize := 0;
  FDSCursor := nil;
  FFindCursor := nil;
  FNotifyCallback := False;
end;

procedure TClientDataSet.InternalRefresh;
const
  Options: TGetRecordOptions = [grReset];
var
  SeqNo: DWord;
  RecCount, RecsOut: Integer;
  DataPacket: TDataPacket;
begin
  CheckBrowseMode;
  if ChangeCount > 0 then
    DatabaseError(SRefreshError, Self);
  if FMasterLink.Active and (FMasterLink.Fields.Count > 0) and
     ((DataSetField <> nil) or (PacketRecords <> -1)) then
  begin
    FDSBase.Reset;
    if FetchOnDemand then CheckDetailRecords;
  end else
  begin
    FDSCursor.GetSequenceNumber(SeqNo);
    if not ProviderEOF then
      FDSBase.GetProp(dspropRECORDSINDS, @RecCount) else
      RecCount := AllRecords;
    DataPacket := VarToDataPacket(DoGetRecords(RecCount, RecsOut, Byte(Options), '', Unassigned));
    ProviderEOF := RecsOut <> RecCount;
    FDSBase.Reset;
    FDSBase.SetProp(dspropDSISPARTIAL, Integer(False));
    Check(FDSBase.AppendData(DataPacket, ProviderEOF));
    FDSCursor.MoveToSeqNo(SeqNo);
  end;
end;

function TClientDataSet.IsCursorOpen: Boolean;
begin
  Result := FDSCursor <> nil;
end;

procedure TClientDataSet.InternalHandleException;
begin
  Application.HandleException(Self)
end;

procedure TClientDataSet.SetData(const Value: OleVariant);
begin
  FSavePacketOnClose := False;
  Close;
  ClearSavedPacket;
  if not VarIsNull(Value) then
  begin
    SafeArrayCopy(VarToDataPacket(Value), FSavedPacket);
    Open;
  end;
end;

function TClientDataSet.GetData: OleVariant;
var
  DataPacket: TDataPacket;
begin
  if Active then
  begin
    CheckBrowseMode;
    Check(FDSBase.StreamDS(DataPacket));
  end else
    DataPacket := FSavedPacket;
  DataPacketToVariant(DataPacket, Result);
end;

procedure TClientDataSet.ClearSavedPacket;
begin
  FreeDataPacket(FSavedPacket);
end;

procedure TClientDataSet.SaveDataPacket(XMLFormat: Boolean = False);
const
  StreamMode: array[Boolean] of DWord = (xmlOFF, xmlON); 
begin
  if Assigned(FDSBase) and (DataSetField = nil) then
  begin
    FDSBase.SetProp(dspropXML_STREAMMODE, StreamMode[XMLFormat]);
    ClearSavedPacket;
    Check(FDSBase.StreamDS(FSavedPacket));
  end;
end;

function TClientDataSet.GetDataSize: Integer;
begin
  if Assigned(DataSetField) then
    Result := -1
  else if Active then
  begin
    SaveDataPacket;
    Result := DataPacketSize(FSavedPacket);
    ClearSavedPacket;
  end
  else if Assigned(FSavedPacket) then
    Result := DataPacketSize(FSavedPacket)
  else
    Result := 0;
end;

procedure TClientDataSet.FetchMoreData(All: Boolean);
var
  Count: Integer;
  RecsOut: Integer;
begin
  if All then Count := AllRecords else Count := FPacketRecords;
  if Count = 0 then Exit;
  AddDataPacket(DoGetRecords(Count, RecsOut, 0, '', Unassigned), RecsOut <> Count);
  ProviderEOF := RecsOut <> Count;
end;

procedure TClientDataSet.InternalFetch(Options: TFetchOptions);
var
  DataPacket: TDataPacket;
  NewData: OleVariant;
  BaseDS: TClientDataSet;
begin
  CheckActive;
  UpdateCursorPos;
  Check(DSCursor.GetRowRequestPacket(foRecord in Options, foBlobs in Options,
    foDetails in Options, True, DataPacket));
  DataPacketToVariant(DataPacket, NewData);
  BaseDS := Self;
  while Assigned(BaseDS.FParentDataSet) do BaseDS := BaseDS.FParentDataSet;
  NewData := BaseDS.DoRowRequest(NewData, Byte(Options));
  UpdateCursorPos;
  Check(DSCursor.RefreshRecord(VarToDataPacket(NewData)));
  DSCursor.GetCurrentRecord(ActiveBuffer);
  if Options = [foDetails] then
    DataEvent(deDataSetChange, 0);
end;

procedure TClientDataSet.FetchBlobs;
begin
  InternalFetch([foBlobs]);
end;

procedure TClientDataSet.FetchDetails;
begin
  InternalFetch([foDetails]);
end;

procedure TClientDataSet.RefreshRecord;
begin
  InternalFetch([foRecord]);
end;

procedure TClientDataSet.CheckProviderEOF;
begin
  if HasAppServer and not ProviderEOF and FFetchOnDemand and (FPacketRecords <> 0) then
    FetchMoreData(True);
end;

procedure TClientDataSet.AddDataPacket(const Data: OleVariant; HitEOF: Boolean);
begin
  Check(FDSBase.AppendData(VarToDataPacket(Data), HitEOF));
end;

procedure TClientDataSet.AppendData(const Data: OleVariant; HitEOF: Boolean);
begin
  if not Active then
  begin
    Self.Data := Data;
    if not HitEOF then
      FDSBase.SetProp(dspropDSISPARTIAL, Integer(False));
  end else
  begin
    AddDataPacket(Data, HitEOF);
    if State <> dsBrowse then Exit;
    if IsEmpty then First else
    begin
      UpdateCursorPos;
      Resync([]);
    end;
  end;
end;

function TClientDataSet.GetNextPacket: Integer;
begin
  CheckActive;
  if ProviderEOF then Result := 0 else
  begin
    UpdateCursorPos;
    if (FPacketRecords = 0) and FMasterLink.Active and
       (FMasterLink.Fields.Count > 0) then CheckDetailRecords else
    begin
      AddDataPacket(DoGetRecords(FPacketRecords, Result, 0, '', Unassigned),
        Result <> FPacketRecords);
      ProviderEOF := Result <> FPacketRecords;
    end;
    Resync([]);
  end;
end;

procedure TClientDataSet.SetProviderName(const Value: string);
begin
  if Value = FProviderName then Exit;
  if (Value <> '') then
  begin
    CheckInactive;
    ClearSavedPacket;
  end;
  FAppServer := nil;
  FProviderName := Value;
end;

procedure TClientDataSet.SetProvider(Provider: TComponent);
begin
  if Provider is TCustomProvider then
    AppServer := TLocalAppServer.Create(TCustomProvider(Provider)) else
    AppServer := nil;
end;

function TClientDataSet.GetAppServer: IAppServer;
var
  ProvComp: TComponent;
  DS: TObject;
begin
  if not HasAppServer then
  begin
    if ProviderName <> '' then
      if Assigned(RemoteServer) then
        FAppServer := RemoteServer.GetServer else
      begin
        if Assigned(Owner) then
        begin
          ProvComp := Owner.FindComponent(ProviderName);
          if Assigned(ProvComp) and (ProvComp is TCustomProvider) then
          begin
            DS := GetObjectProperty(ProvComp, 'DataSet');
            if Assigned(DS) and (DS = Self) then
              DatabaseError(SNoCircularReference, Self);
            FAppServer := TLocalAppServer.Create(TCustomProvider(ProvComp));
          end;
        end;
      end;
    if not HasAppServer then
      DatabaseError(SNoDataProvider, Self);
  end;
  Result := FAppServer;
end;

function TClientDataSet.GetHasAppServer: Boolean;
begin
  Result := Assigned(FAppServer);
end;

procedure TClientDataSet.SetAppServer(Value: IAppServer);
begin
  FAppServer := Value;
  if Assigned(Value) then
    ClearSavedPacket;
end;

procedure TClientDataSet.SetProviderEOF(Value: Boolean);
begin
  FProviderEOF := Value;
  if Assigned(FCloneSource) then
    FCloneSource.ProviderEOF := Value;
end;

function TClientDataSet.GetProviderEOF: Boolean;
begin
  if Assigned(FCloneSource) then
    FProviderEOF := FCloneSource.ProviderEOF;
  Result := FProviderEOF;
end;

function TClientDataSet.GetRemoteServer: TCustomRemoteServer;
begin
  Result := FRemoteServer;
end;

procedure TClientDataSet.SetRemoteServer(Value: TCustomRemoteServer);
begin
  if Value = FRemoteServer then Exit;
  AppServer := nil;
  if Assigned(FRemoteServer) then FRemoteServer.UnRegisterClient(Self);
  if Assigned(Value) then
  begin
    CheckInactive;
    Value.RegisterClient(Self);
    ClearSavedPacket;
    Value.FreeNotification(Self);
  end;
  FRemoteServer := Value;
end;

procedure TClientDataSet.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = RemoteServer) then
    RemoteServer := nil;
  if (Operation = opRemove) and (AComponent = FCloneSource) then
  begin
    FProviderEOF := FCloneSource.ProviderEOF;
    FCloneSource := nil;
  end;
end;

procedure TClientDataSet.DataEvent(Event: TDataEvent; Info: Integer);
begin
  case Event of
    deParentScroll: MasterChanged(Self);
    deDataSetScroll,
    deDataSetChange: SetAltRecBuffers(nil, nil, nil);
    deFieldListChange: FAggFieldsInit := False;
    deConnectChange:
      if not Bool(Info) then
        AppServer := nil;
  end;
  inherited;
end;

function TClientDataSet.GetDelta: OleVariant;
var
  FDeltaDS: IDSBase;
  TempPacket: TDataPacket;
begin
  CheckBrowseMode;
  Check(FDSBase.GetDelta(FDeltaDS));
  FreeDataPacket(FDeltaPacket);
  Check(FDeltaDS.StreamDS(FDeltaPacket));
  SafeArrayCopy(FDeltaPacket, TempPacket);
  DataPacketToVariant(TempPacket, Result);
end;

procedure TClientDataSet.Execute;
begin
  DoExecute(PackageParams(Params));
end;

function TClientDataSet.DataRequest(Data: OleVariant): OleVariant;
begin
  Result := AppServer.AS_DataRequest(ProviderName, Data);
end;

function TClientDataSet.ApplyUpdates(MaxErrors: Integer): Integer;
begin
  CheckBrowseMode;
  if ChangeCount = 0 then
    Result := 0 else
    Reconcile(DoApplyUpdates(Delta, MaxErrors, Result));
end;

procedure TClientDataSet.MergeChangeLog;
begin
  CheckBrowseMode;
  FDSBase.AcceptChanges;
end;

procedure TClientDataSet.SetAltRecBuffers(Old, New, Cur: PChar);
begin
  FOldValueBuffer := Old;
  FNewValueBuffer := New;
  FCurValueBuffer := Cur;
end;

function TClientDataSet.ReconcileCallback(
    iRslt         : Integer;   { Previous error if any }
    iUpdateKind   : DSAttr;    { Update request Insert/Modify/Delete }
    iResAction    : dsCBRType; { Resolver response }
    iErrCode      : Integer;   { Native error-code, (BDE or ..) }
    pErrMessage,               { Native errormessage, if any (otherwise Null) }
    pErrContext   : PChar;     { 1-level error context, if any (otherwise Null) }
    pRecUpd,                   { Record that failed update }
    pRecOrg,                   { Original record, if any }
    pRecConflict  : Pointer;   { Conflicting error, if any }
    iLevels       : Integer;   { Number of levels to error0level }
    piFieldIDs    : PInteger   { Array of fieldIDS to navigate to error-dataset }
): dsCBRType;
var
  I: Integer;
  Action: TReconcileAction;
  UpdateKind: TUpdateKind;
  DataSet: TClientDataSet;
  E: EReconcileError;
begin
  FInReconcileCallback := True;
  try
    if iUpdateKind = dsRecDeleted then
      UpdateKind := ukDelete
    else if iUpdateKind = dsRecNew then
      UpdateKind := ukInsert
    else
      UpdateKind := ukModify;
    if iResAction = dscbrSkip then
      Action := raSkip else
      Action := raAbort;
    FReconcileDataSet.First;
    E := EReconcileError.Create(pErrMessage, pErrContext, iErrCode, iRslt);
    try
      DataSet := FReconcileDataSet;
      for I := 1 to iLevels do
      begin
         DataSet := TClientDataSet((DataSet.Fields.FieldByNumber(piFieldIDs^) as TDataSetField).NestedDataSet);
         inc(piFieldIDs);
      end;
      if UpdateKind = ukDelete then
        DataSet.SetAltRecBuffers(pRecUpd, pRecOrg, pRecConflict) else
        DataSet.SetAltRecBuffers(pRecOrg, pRecUpd, pRecConflict);
      FOnReconcileError(DataSet, E, UpdateKind, Action);
    finally
      E.Free;
    end;
  except
    Application.HandleException(Self);
    Action := raAbort;
  end;
  Result := Ord(Action) + 1;
  FInReconcileCallback := False;
end;

function TClientDataSet.Reconcile(const Results: OleVariant): Boolean;
var
  RCB: Pointer;
begin
  if VarIsNull(Results) then MergeChangeLog else
  begin
    UpdateCursorPos;
    if Assigned(FOnReconcileError) then
      RCB := @TClientDataSet.ReconcileCallback else
      RCB := nil;
    FReconcileDataSet := TClientDataSet.Create(Self);
    try
      Check(FDSBase.Clone(0, True, False, FReconcileDataSet.FDSBase));
      FReconcileDataSet.ObjectView := True;
      FReconcileDataSet.Open;
      Check(FDSBase.Reconcile_MD(FReconcileDataSet.FDSBase, FDeltaPacket,
        VarToDataPacket(Results), Integer(Self), RCB));
    finally
      FReconcileDataSet.Free;
      FReconcileDataSet := nil;
    end;
    Resync([]);
  end;
  Result := (ChangeCount = 0);
end;

procedure TClientDataSet.NotifyCallback;
begin
  try
    if State = dsBrowse then
    begin
      UpdateCursorPos;
      Resync([]);
    end;
  except
  end;
end;

procedure TClientDataSet.SetNotifyCallback;
begin
  if not FNotifyCallback then
  begin
    Check(FDSCursor.SetNotifyCallBack(Integer(Self), @TClientDataSet.NotifyCallback));
    FNotifyCallback := True;
  end;
end;

procedure TClientDataSet.CloneCursor(Source: TClientDataSet; Reset, KeepSettings: Boolean);
begin
  Source.CheckActive;
  Close;
  FDSBase := Source.DSBase;
  Source.UpdateCursorPos;
  FCloneSource := Source;
  FParentDataSet := Source.FParentDataSet;
  if Reset then
  begin
    Filtered := False;
    Filter := '';
    OnFilterRecord := nil;
    IndexName := '';
    MasterSource := nil;
    MasterFields := '';
    ReadOnly := False;
    RemoteServer := nil;
    ProviderName := '';
    AppServer := nil;
  end else
  if not KeepSettings then
  begin
    Filter := Source.Filter;
    OnFilterRecord := Source.OnFilterRecord;
    FilterOptions := Source.FilterOptions;
    Filtered := Source.Filtered;
    if Source.IndexName <> '' then
      IndexName := Source.IndexName else
      IndexFieldNames := Source.IndexFieldNames;
    MasterSource := Source.MasterSource;
    MasterFields := Source.MasterFields;
    ReadOnly := Source.ReadOnly;
    RemoteServer := Source.RemoteServer;
    ProviderName := Source.ProviderName;
    if Source.HasAppServer then
      AppServer := Source.AppServer;
  end;
  Open;
  if Reset then
  begin
    if Source.FExprFilter <> nil then FDSCursor.DropFilter(Source.FExprFilter);
    if Source.FFuncFilter <> nil then FDSCursor.DropFilter(Source.FFuncFilter);
    Resync([]);
  end;
  SetNotifyCallback;
  Source.SetNotifyCallback;
end;

procedure TClientDataSet.EncodeFieldDesc(var FieldDesc: DSFLDDesc;
  const Name: string; DataType: TFieldType; Size, Precision: Integer;
  Calculated: Boolean; Attributes: TFieldAttributes);
begin
  with FieldDesc do
  begin
    FillChar(FieldDesc, SizeOf(FieldDesc), #0);
    StrCopy(szName, PChar(Name));
    if DataType = ftWideString then
      iFldType := fldUNICODE else
      iFldType := FieldTypeMap[DataType];
    iFldSubType := FldSubTypeMap[DataType];
    bCalculated := Calculated;
    iFldAttr := Integer(Byte(Attributes));
    case DataType of
      ftADT, ftArray, ftDataSet, ftString, ftFixedChar, ftGUID, ftBytes,
      ftVarBytes, ftBlob..ftTypedBinary, ftOraClob, ftOraBlob, ftWideString:
        iUnits1 := Size;
      ftBCD:
        begin
          { Default precision is 32, Size = Scale }
          if (Precision > 0) and (Precision <= 32) then
            iUnits1 := Precision else
            iUnits1 := 32;
          iUnits2 := Size;  {Scale}
        end;
    end;
  end;
end;

procedure TClientDataSet.CreateDataSet;

  procedure GetFieldDefCount(FieldDefs: TFieldDefs; var Count: Integer);
  var
    I: Integer;
  begin
    Inc(Count, FieldDefs.Count);
    for I := 0 to FieldDefs.Count - 1 do
    with FieldDefs[I] do
      if HasChildDefs then
        GetFieldDefCount(ChildDefs, Count);
  end;

  procedure EncodeFieldDescs(FieldDefs: TFieldDefs; FieldDescs: TFieldDescList;
    var DescNo: Integer);
  var
    I: Integer;
  begin
    for I := 0 to FieldDefs.Count - 1 do
    with FieldDefs[I] do
    begin
      EncodeFieldDesc(FieldDescs[DescNo], Name, DataType, Size, Precision, False, Attributes);
      Inc(DescNo);
      if HasChildDefs then
      begin
        if DataType = ftDataSet then
          GetFieldDefCount(ChildDefs, FieldDescs[DescNo-1].iUnits2);
        EncodeFieldDescs(ChildDefs, FieldDescs, DescNo);
      end;
    end;
  end;

  procedure CreateIndexes;
  var
    I: Integer;
    IndexDesc: DSIdxDesc;
  begin
    for I := 0 to IndexDefs.Count - 1 do
    begin
      with IndexDefs[I] do
        EncodeIndexDesc(IndexDesc, Name, Fields, DescFields, CaseInsFields, Options);
      Check(FDSBase.CreateIndex(IndexDesc));
    end;
  end;

var
  FieldDefCount, DescNo: Integer;
  FieldDescs: TFieldDescList;
begin
  CheckInactive;
  InitFieldDefsFromFields;
  FieldDefCount := 0;
  GetFieldDefCount(FieldDefs, FieldDefCount);
  if FieldDefCount = 0 then
    DatabaseError(SCannotCreateDataSet);
  SetLength(FieldDescs, FieldDefCount);
  DescNo := 0;
  EncodeFieldDescs(FieldDefs, FieldDescs, DescNo);
  FDSBase := CreateDSBase;
  try
    Check(FDSBase.Create(FieldDefCount, pDSFLDDesc(FieldDescs), PChar(Name)));
    CreateIndexes;
  except
    FDSBase := nil;
    raise;
  end;
  Open;
end;

procedure TClientDataSet.EmptyDataSet;
begin
  CheckBrowseMode;
  Check(FDSBase.Reset);
  ProviderEOF := True;
  Resync([]);
  InitRecord(ActiveBuffer);
end;

procedure TClientDataSet.SetupInternalCalcFields(Add: Boolean);
var
  Precision, I: Integer;
  FieldDesc: DSFLDDesc;
begin
  if Add and not DefaultFields then
  begin
    for I := 0 to FieldCount - 1 do
    begin
      if Fields[I].FieldKind = fkInternalCalc then
        with Fields[I] do
        begin
          if DataType = ftBCD then
            Precision := TBCDField(Fields[I]).Precision else
            Precision := 0;
          EncodeFieldDesc(FieldDesc, FieldName, DataType, Size, Precision, True, []);
          Check(FDSBase.AddField(@FieldDesc));
        end;
    end;
  end
  else if InternalCalcFields then
  begin
    Check(FDSBase.SetFieldCalculation(0, nil));
    Check(FDSBase.AddField(nil));
  end;
end;

procedure TClientDataSet.WriteDataPacket(Stream: TStream; WriteSize: Boolean;
  XMLFormat: Boolean = False);
var
  Size: Integer;
  DataPtr: Pointer;
begin
  RCS;
  if Active then CheckBrowseMode;
  if IsCursorOpen then
  begin
    CheckProviderEOF;
    SaveDataPacket(XMLFormat);
  end;
  if Assigned(FSavedPacket) then
  begin
    Size := DataPacketSize(FSavedPacket);
    SafeArrayAccessData(FSavedPacket, DataPtr);
    try
      if WriteSize then
        Stream.Write(Size, SizeOf(Size));
      Stream.Write(DataPtr^, Size);
    finally
      SafeArrayUnAccessData(FSavedPacket);
    end;
    if Active then ClearSavedPacket;
  end;
end;

procedure TClientDataSet.ReadDataPacket(Stream: TStream; ReadSize: Boolean);
var
  Size: Integer;
  DataPtr: Pointer;
  VarBound: TVarArrayBound;
begin
  RCS;
  if ReadSize then
    Stream.ReadBuffer(Size, SizeOf(Size)) else
    Size := Stream.Size - Stream.Position;
  if Size > 0 then
  begin
    ClearSavedPacket;
    FillChar(VarBound, SizeOf(VarBound), 0);
    VarBound.ElementCount := Size;
    FSavedPacket := TDataPacket(SafeArrayCreate(varByte, 1, VarBound));
    try
      SafeArrayAccessData(FSavedPacket, DataPtr);
      try
        Stream.Read(DataPtr^, Size);
      finally
        SafeArrayUnAccessData(FSavedPacket);
      end;
    except
      ClearSavedPacket;
      raise;
    end;
  end;
end;

procedure TClientDataSet.LoadFromStream(Stream: TStream);
begin
  Close;
  ReadDataPacket(Stream, False);
  Open;
end;

procedure TClientDataSet.SaveToStream(Stream: TStream; Format: TDataPacketFormat = dfBinary);
begin
  WriteDataPacket(Stream, False, (Format=dfXML));
end;

procedure TClientDataSet.LoadFromFile(const FileName: string = '');
var
  Stream: TStream;
begin
  Close;
  if FileName = '' then
    Stream := TFileStream.Create(Self.FileName, fmOpenRead) else
    Stream := TFileStream.Create(FileName, fmOpenRead);
  try
    FOpeningFile := True;
    try
      LoadFromStream(Stream);
    finally
      FOpeningFile := False;
    end;
  finally
    Stream.Free;
  end;
end;

procedure TClientDataSet.SaveToFile(const FileName: string = '';
  Format: TDataPacketFormat = dfBinary);
var
  Stream: TStream;
begin
  if FileName = '' then
    Stream := TFileStream.Create(Self.FileName, fmCreate) else
    Stream := TFileStream.Create(FileName, fmCreate);
  try
    if LowerCase(ExtractFileExt(FileName)) = '.xml' then
      Format := dfXML;
    SaveToStream(Stream, Format);
  finally
    Stream.Free;
  end;
end;

procedure TClientDataSet.SetLogChanges(Value: Boolean);
begin
  CheckBrowseMode;
  Check(FDSBase.SetProp(dspropLOGCHANGES, Integer(Value)));
end;

function TClientDataSet.GetLogChanges: Boolean;
var
  LogChanges: Integer;
begin
  CheckBrowseMode;
  Check(FDSBase.GetProp(dspropLOGCHANGES, @LogChanges));
  Result := Boolean(LogChanges);
end;

function TClientDataSet.GetCanModify: Boolean;
begin
  Result := FCanModify and not ReadOnly;
end;

procedure TClientDataSet.SetReadOnly(Value: Boolean);
begin
  FReadOnly := Value;
  if Assigned(FDSBase) then
  begin
    Check(FDSBase.SetProp(dspropREADONLY, Integer(Value)));
    FCanModify := not Value;
  end;
end;

function TClientDataSet.ConstraintsDisabled: Boolean;
begin
  Result := FConstDisableCount > 0;
end;

procedure TClientDataSet.DisableConstraints;
begin
  if FConstDisableCount = 0 then
    Check(FDSBase.SetProp(dspropCONSTRAINTS_DISABLED, Longint(True)));
  Inc(FConstDisableCount);
end;

procedure TClientDataSet.EnableConstraints;
begin
  if FConstDisableCount <> 0 then
  begin
    Dec(FConstDisableCount);
    if FConstDisableCount = 0 then
      Check(FDSBase.SetProp(dspropCONSTRAINTS_DISABLED, Longint(False)));
  end;
end;

{ Record Functions }

procedure TClientDataSet.InitBufferPointers(GetProps: Boolean);
var
  CursorProps: DSProps;
begin
  if GetProps then
  begin
    Check(FDSCursor.GetCursorProps(CursorProps));
    BookmarkSize := CursorProps.iBookmarkSize;
    SetLength(FLastParentBM, BookMarkSize);
    FRecordSize := CursorProps.iRecBufSize;
  end;
  FRecInfoOfs := FRecordSize + CalcFieldsSize;
  FBookmarkOfs := FRecInfoOfs + SizeOf(TRecInfo);
  FAggGrpIndOfs := FBookmarkOfs + BookMarkSize;
  FAggFieldsOfs := FAggGrpIndOfs + FAggGrpIndSize;
  FRecBufSize := FAggFieldsOfs + FAggFieldsSize;
end;

function TClientDataSet.AllocRecordBuffer: PChar;
begin
  Result := AllocMem(FRecBufSize);
end;

procedure TClientDataSet.FreeRecordBuffer(var Buffer: PChar);
begin
  FreeMem(Buffer);
end;

procedure TClientDataSet.InternalInitRecord(Buffer: PChar);
begin
  Check(FDSCursor.InitRecord(Buffer));
end;

procedure TClientDataSet.ClearCalcFields(Buffer: PChar);
begin
  FillChar(Buffer[RecordSize], CalcFieldsSize, 0);
end;

procedure TClientDataSet.InitRecord(Buffer: PChar);
begin
  inherited InitRecord(Buffer);
  with PRecInfo(Buffer + FRecInfoOfs)^ do
  begin
    BookMarkFlag := bfInserted;
    RecordNumber := -1;
    Attribute := dsRecNew;
  end;
end;

function TClientDataSet.GetRecord(Buffer: PChar; GetMode: TGetMode;
  DoCheck: Boolean): TGetResult;
var
  Status: DBResult;
begin
  with FDSCursor do
  begin
    case GetMode of
      gmNext:
        begin
          Status := MoveRelative(1);
          if (Status = DBERR_EOF) and not ProviderEOF and FFetchOnDemand then
          begin
            MoveRelative(-1);
            FetchMoreData(False);
            Status := MoveRelative(1);
          end;
        end;
      gmPrior: Status := MoveRelative(-1);
    else
      Status := DBERR_NONE;
    end;
    if Status = DBERR_NONE then
      Status := GetCurrentRecord(Buffer);
    case Status of
      DBERR_NONE:
        begin
          if (AggFields.Count > 0) and AggregatesActive then
            GetAggFieldData(Buffer);
          with PRecInfo(Buffer + FRecInfoOfs)^ do
          begin
            BookmarkFlag := bfCurrent;
            GetSequenceNumber(DWord(RecordNumber));
            GetRecordAttribute(Attribute);
          end;
          GetCalcFields(Buffer);
          Check(GetCurrentBookmark(Buffer + FBookmarkOfs));
          Result := grOK;
        end;
      DBERR_BOF: Result := grBOF;
      DBERR_EOF: Result := grEOF;
    else
      Result := grError;
      if DoCheck then Check(Status);
    end;
  end;
end;

function TClientDataSet.GetCurrentRecord(Buffer: PChar): Boolean;
begin
  if not IsEmpty and (GetBookmarkFlag(ActiveBuffer) = bfCurrent) then
  begin
    UpdateCursorPos;
    Result := (FDSCursor.GetCurrentRecord(Buffer) = DBERR_NONE);
  end else
    Result := False;
end;

function TClientDataSet.GetRecordCount: Integer;
var
  Status: DBResult;
begin
  CheckActive;
  if (FParentDataSet <> nil) and (FParentDataSet.State <> dsInsert) then
    FParentDataSet.UpdateCursorPos;
  Status := FDSCursor.GetRecordCount(Result);
  if Status <> DBERR_DETAILSNOTFETCHED then
    Check(Status);
end;

function TClientDataSet.GetRecNo: Integer;
var
  BufPtr: PChar;
begin
  CheckActive;
  if State = dsInternalCalc then
    Result := -1
  else
  begin
    if State = dsCalcFields then
      BufPtr := CalcBuffer else
      BufPtr := ActiveBuffer;
    Result := PRecInfo(BufPtr + FRecInfoOfs).RecordNumber;
  end;
end;

procedure TClientDataSet.SetRecNo(Value: Integer);
begin
  CheckBrowseMode;
  if Value <> RecNo then
  begin
    DoBeforeScroll;
    Check(FDSCursor.MoveToSeqNo(Value));
    Resync([rmCenter]);
    DoAfterScroll;
  end;
end;

function TClientDataSet.GetRecordSize: Word;
begin
  Result := FRecordSize;
end;

function TClientDataSet.GetActiveRecBuf(var RecBuf: PChar): Boolean;

  function GetOriginalBuffer: PChar;
  begin
    UpdateCursorPos;
    Result := TempBuffer;
    if FDSCursor.GetProp(curpropGETORG_RECBUF, Result) <> DBERR_NONE then
      Result := nil;
  end;

begin
  case State of
    dsBlockRead,
    dsBrowse: if IsEmpty then RecBuf := nil else RecBuf := ActiveBuffer;
    dsEdit, dsInsert: RecBuf := ActiveBuffer;
    dsSetKey: RecBuf := PChar(FKeyBuffer) + SizeOf(TKeyBuffer);
    dsCalcFields,
    dsInternalCalc: RecBuf := CalcBuffer;
    dsFilter: RecBuf := FFilterBuffer;
    dsNewValue: RecBuf := FNewValueBuffer;
    dsOldValue: if FOldValueBuffer <> nil then
                  RecBuf := FOldValueBuffer else
                  RecBuf := GetOriginalBuffer;
    dsCurValue: RecBuf := FCurValueBuffer;
    dsInActive: RecBuf := nil;
  else
    RecBuf := nil;
  end;
  Result := RecBuf <> nil;
end;

function TClientDataSet.GetChangeCount: Integer;
begin
  if Active then
    Check(FDSBase.GetProp(dspropNOOFCHANGES, @Result)) else
    Result := 0;
end;

function TClientDataSet.UpdateStatus: TUpdateStatus;
var
  BufPtr: PChar;
  Attr: Byte;
begin
  CheckActive;
  if State = dsInternalCalc then
    Result := usUnModified
  else
  begin
    if State = dsCalcFields then
      BufPtr := CalcBuffer else
      BufPtr := ActiveBuffer;
    Attr := PRecInfo(BufPtr + FRecInfoOfs).Attribute;
    if (Attr and dsRecModified) <> 0 then
      Result := usModified
    else if (Attr and dsRecDeleted) <> 0 then
      Result := usDeleted
    else if (Attr and dsRecNew) <> 0 then
      Result := usInserted
    else
      Result := usUnModified;
  end;
end;

{ Field Related }

procedure TClientDataSet.AddFieldDesc(FieldDescs: TFieldDescList;
  var DescNo: Integer; var FieldID: Integer; FieldDefs: TFieldDefs);
var
  FPrecision, I: Integer;
  FType: TFieldType;
  FSize: Integer;
  FName: string;
  FieldDesc: DSFLDDesc;
begin
  FieldDesc := FieldDescs[DescNo];
  Inc(DescNo);
  with FieldDesc do
  begin
    if ((fldAttrLINK and iFldAttr) <> 0) then
    begin
      Inc(FieldID);
      Exit;
    end;
    FName := szName;
    I := 0;
    while FieldDefs.IndexOf(FName) >= 0 do
    begin
      Inc(I);
      FName := Format('%s_%d', [szName, I]);
    end;
    if iFldType < MAXLOGFLDTYPES then
      FType := DataTypeMap[iFldType] else
    if iFldType = fldUNICODE then
      FType := ftWideString else
      FType := ftUnknown;
    FSize := 0;
    FPrecision := 0;
    case iFldType of
      fldZSTRING, fldBYTES, fldVARBYTES, fldADT, fldArray:
      begin
        FSize := iUnits1;
        if iFldSubType = fldstGuid then
          FType := ftGuid;
      end;
      fldUNICODE:
        FSize := iUnits1 div 2;
      fldINT16, fldUINT16:
        if iFldLen <> 2 then FType := ftUnknown;
      fldINT32:
        if iFldSubType = fldstAUTOINC then FType := ftAutoInc;
      fldFLOAT:
        if iFldSubType = fldstMONEY then FType := ftCurrency;
      fldBCD:
        begin
          FSize := Abs(iUnits2);
          FPrecision := iUnits1;
        end;
      fldBLOB:
        begin
          FSize := iUnits1;
          if ( (iFldSubType >= fldstMEMO) and (iFldSubType <= fldstTYPEDBINARY))
              or (iFldSubType = fldstHMEMO ) or ( iFldSubType = fldstHBINARY) then
            FType := BlobTypeMap[iFldSubType];
        end;
      fldTABLE:
        if iFldSubType = fldstREFERENCE then FType := ftReference;
    end;
    if FType <> ftUnknown then
      with FieldDefs.AddFieldDef do
      begin
        FieldNo := FieldID;
        Inc(FieldID);
        Name := FName;
        DataType := FType;
        Size := FSize;
        Precision := FPrecision;
        Attributes := TFieldAttributes(Byte(iFldAttr));
        if iFldSubType = fldstFIXED then
          Attributes := Attributes + [faFixed];
        InternalCalcField := bCalculated;
        case FType of
          ftADT:
            for I := 0 to iUnits1 - 1 do
              AddFieldDesc(FieldDescs, DescNo, FieldID, ChildDefs);
          ftArray:
            begin
              I := FieldID;
              AddFieldDesc(FieldDescs, DescNo, I, ChildDefs);
              Inc(FieldID, iUnits2);
            end;
        end; { case }
      end;
  end;
end;

function TClientDataSet.GetFieldData(Field: TField; Buffer: Pointer): Boolean;
var
  IsBlank: LongBool;
  RecBuf: PChar;
begin
  Result := False;
  if GetActiveRecBuf(RecBuf) then
    with Field do
      if FieldKind in [fkData, fkInternalCalc] then
      begin
        Check(FDSCursor.GetField(RecBuf, FieldNo, Buffer, IsBlank));
        Result := not IsBlank;
      end else
        if State in [dsBrowse, dsEdit, dsInsert, dsCalcFields] then
        begin
          Inc(RecBuf, FRecordSize + Offset);
          Result := Boolean(RecBuf[0]);
          if Result and (Buffer <> nil) then
            Move(RecBuf[1], Buffer^, DataSize);
        end;
end;

function TClientDataSet.GetFieldData(FieldNo: Integer; Buffer: Pointer): Boolean; 
var
  RecBuf: PChar;
  IsBlank: LongBool;
begin
  Result := GetActiveRecBuf(RecBuf);
  if Result then
  begin
    Check(FDSCursor.GetFIeld(RecBuf, FieldNo, Buffer, IsBlank));
    Result := not IsBlank;
  end;
end;

function TClientDataSet.GetStateFieldValue(State: TDataSetState; Field: TField): Variant;

  function CheckNotChanged(Buffer: PChar): Variant;
  var
    IsBlank: Integer;
  begin
    if (Buffer = nil) then
      IsBlank := BLANK_NOTCHANGED else
      Check(FDSCursor.GetField(Buffer, Field.FieldNo, nil, LongBool(IsBlank)));
    if IsBlank = BLANK_NOTCHANGED then
      Result := UnAssigned
    else if IsBlank =  BLANK_NULL then
      Result := Null else
      Result := inherited GetStateFieldValue(State, Field);
  end;

begin
  case State of
    dsNewValue:
      if FNewValueBuffer = nil then
      begin
        FNewValueBuffer := ActiveBuffer;
        try
          Result := CheckNotChanged(FNewValueBuffer);
        finally
          FNewValueBuffer := nil;
        end;
      end else
        Result := CheckNotChanged(FNewValueBuffer);
    dsCurValue: Result := CheckNotChanged(FCurValueBuffer);
  else
    Result := inherited GetStateFieldValue(State, Field);
  end;
end;

procedure TClientDataSet.SetFieldData(Field: TField; Buffer: Pointer);
var
  RecBuf: PChar;
begin
  with Field do
  begin
    if not (State in dsWriteModes) then DatabaseError(SNotEditing, Self);
    if (State = dsSetKey) and ((FieldNo < 0) or (FIndexFieldCount > 0) and
      not IsIndexField) then DatabaseErrorFmt(SNotIndexField, [DisplayName]);
    GetActiveRecBuf(RecBuf);
    if FieldKind in [fkData, fkInternalCalc] then
    begin
      if ReadOnly and not (State in [dsSetKey, dsFilter]) then
        DatabaseErrorFmt(SFieldReadOnly, [DisplayName]);
      Validate(Buffer);
      if State in [dsEdit, dsInsert] then
        Check(FDSCursor.VerifyField(FieldNo, Buffer));
      Check(FDSCursor.PutField(RecBuf, FieldNo, Buffer));
      if FAggFieldsUpdated <> nil then
        FAggFieldsUpdated[FieldNo-1] := True;
    end else
    begin
      if State = dsInternalCalc then Exit;
      Inc(RecBuf, FRecordSize + Offset);
      Boolean(RecBuf[0]) := LongBool(Buffer);
      if Boolean(RecBuf[0]) then Move(Buffer^, RecBuf[1], DataSize);
    end;
    if not (State in [dsCalcFields, dsInternalCalc, dsFilter, dsNewValue]) then
      DataEvent(deFieldChange, Longint(Field));
  end;
end;

function TClientDataSet.CreateBlobStream(Field: TField; Mode: TBlobStreamMode): TStream;
var
  Status: DBResult;
  BlobLen: DWord;
  Buffer: PChar;
begin
  if GetActiveRecBuf(Buffer) then
  begin
    Status := FDSCursor.GetBlobLen(Buffer, Field.FieldNo, BlobLen);
    if (Status = DBERR_BLOBNOTFETCHED) and FetchOnDemand then
      FetchBlobs;
  end;
  Result := TClientBlobStream.Create(Field as TBlobField, Mode);
end;

procedure TClientDataSet.RefreshInternalCalcFields(Buffer: PChar);
begin
  CalculateFields(Buffer);
end;

function TClientDataSet.CalcFieldsCallBack(RecBuf: PChar): DBResult;
var
  SaveState: TDataSetState;
begin
  try
    SaveState := SetTempState(dsInternalCalc);
    try
      CalculateFields(RecBuf);
    finally
      RestoreState(SaveState);
    end;
  except
  end;
  Result := 0;
end;

procedure TClientDataSet.DataConvert(Field: TField; Source, Dest: Pointer;
  ToNative: Boolean);
begin
  if Field.DataType = ftWideString then
  begin
    if ToNative then
    begin
      Word(Dest^) := Length(PWideString(Source)^)*2;
      Move(PWideChar(Source^)^, (PWideChar(Dest)+1)^, Word(Dest^));
    end else
      PWideChar(Dest^) := SysAllocStringLen(PWideChar(PChar(Source)+2), Word(Source^) div 2);
  end else
    inherited;
end;

{ Navigation / Editing }

procedure TClientDataSet.InternalFirst;
begin
  Check(FDSCursor.MoveToBOF);
end;

procedure TClientDataSet.InternalLast;
begin
  CheckProviderEOF;
  Check(FDSCursor.MoveToEOF);
end;

procedure TClientDataSet.InternalPost;
begin
  if State = dsEdit then
    Check(FDSCursor.ModifyRecord(ActiveBuffer)) else
    Check(FDSCursor.InsertRecord(ActiveBuffer));
  if AggregatesActive then
    DoAggUpdates(State = dsEdit);
end;

procedure TClientDataSet.InternalCancel;
begin
  if BlobFieldCount > 0 then
    FDSBase.ReleaseBlobs(0);
end;

procedure TClientDataSet.InternalDelete;
begin
  if doDisableDeletes in FDSOptions then
    DatabaseError(SNoDeletesAllowed, Self);
  Check(DSCursor.DeleteRecord);
  if AggregatesActive then
    DoAggUpdates(False);
end;

procedure TClientDataSet.InternalEdit;
begin
  if doDisableEdits in FDSOptions then
    DatabaseError(SNoEditsAllowed, Self);
end;

procedure TClientDataSet.DoBeforeInsert;
begin
  if doDisableInserts in FDSOptions then
    DatabaseError(SNoInsertsAllowed, Self);
  inherited DoBeforeInsert;
  if (DataSetField <> nil) then
  begin
    { Force inserted master to post before allowing insert on nested dataset }
    if DataSetField.DataSet.State = dsInsert then
      DataSetField.DataSet.Post;
  end;
end;

procedure TClientDataSet.InternalInsert;
begin
  DSCursor.SetProp(curpropSETCRACK, 0);
  CursorPosChanged;
end;

procedure TClientDataSet.Post;
var
  CursorProps: DSProps;
begin
  Check(FDSBase.GetProps(CursorProps));
  if CursorProps.bDelta and (State in [dsEdit, dsInsert]) then
  begin
    UpdateRecord;
    InternalPost;
    SetState(dsBrowse);
  end else
  begin
    inherited Post;
    if State = dsSetKey then
      PostKeyBuffer(True);
  end;
end;

procedure TClientDataSet.Cancel;
begin
  inherited Cancel;
  if State = dsSetKey then
    PostKeyBuffer(False);
end;

procedure TClientDataSet.InternalAddRecord(Buffer: Pointer; Append: Boolean);
begin
  if Append then FDSCursor.MoveToEOF;
  Check(FDSCursor.InsertRecord(Buffer));
end;

procedure TClientDataSet.InternalGotoBookmark(Bookmark: TBookmark);
begin
  Check(FDSCursor.MoveToBookmark(Bookmark));
end;

procedure TClientDataSet.InternalSetToRecord(Buffer: PChar);
begin
  InternalGotoBookmark(Buffer + FBookmarkOfs);
end;

function TClientDataSet.GetBookmarkFlag(Buffer: PChar): TBookmarkFlag;
begin
  Result := PRecInfo(Buffer + FRecInfoOfs).BookmarkFlag;
end;

procedure TClientDataSet.SetBookmarkFlag(Buffer: PChar; Value: TBookmarkFlag);
begin
  PRecInfo(Buffer + FRecInfoOfs).BookmarkFlag := Value;
end;

procedure TClientDataSet.GetBookmarkData(Buffer: PChar; Data: Pointer);
begin
  Move(Buffer[FBookmarkOfs], Data^, BookmarkSize);
end;

procedure TClientDataSet.SetBookmarkData(Buffer: PChar; Data: Pointer);
begin
  Move(Data^, ActiveBuffer[FBookmarkOfs], BookmarkSize);
end;

function TClientDataSet.CompareBookmarks(Bookmark1, Bookmark2: TBookmark): Integer;
const
  RetCodes: array[Boolean, Boolean] of ShortInt = ((2, -1),(1, 0));
begin
  { Check for uninitialized bookmarks }
  Result := RetCodes[Bookmark1 = nil, Bookmark2 = nil];
  if Result = 2 then
  begin
    Check(FDSCursor.CompareBookmarks(Bookmark1, Bookmark2, Result));
    if Result = 2 then Result := 0;
  end;
end;

function TClientDataSet.BookmarkValid(Bookmark: TBookmark): Boolean;
begin
  Result := FDSCursor <> nil;
  if Result then
  begin
    CursorPosChanged;
    Result := (FDSCursor.MoveToBookmark(Bookmark) = DBERR_NONE) and
      (FDSCursor.GetCurrentRecord(nil) = DBERR_NONE);
  end;
end;

procedure TClientDataSet.SyncCursors(Cursor1, Cursor2: IDSCursor);
var
  BM: DSBOOKMRK;
begin
  Cursor2.GetCurrentBookmark(@BM);
  Cursor1.MoveToBookmark(@BM);
end;

function TClientDataSet.UndoLastChange(FollowChange: Boolean): Boolean;
begin
  Cancel;
  CheckBrowseMode;
  UpdateCursorPos;
  Result := (FDSCursor.UndoLastChange(FollowChange) = DBERR_NONE);
  if Result then
  begin
    if FollowChange then CursorPosChanged;
    Resync([]);
  end;
end;

procedure TClientDataSet.RevertRecord;
begin
  Cancel;
  CheckBrowseMode;
  UpdateCursorPos;
  Check(FDSCursor.RevertRecord);
  Resync([]);
end;

function TClientDataSet.GetSavePoint: Integer;
begin
  CheckBrowseMode;
  FDSBase.GetProp(dspropGETSAVEPOINT, @Result);
end;

procedure TClientDataSet.SetSavePoint(Value: Integer);
begin
  Cancel;
  CheckBrowseMode;
  UpdateCursorPos;
  Check(FDSBase.RollBack(Value));
  CursorPosChanged;
  Resync([]);
end;

procedure TClientDataSet.CancelUpdates;
begin
  SetSavePoint(0);
end;

{ Indexes }

procedure TClientDataSet.UpdateIndexDefs;
var
  I: Integer;
  CursorProps: DSProps;
  IndexDescs: array of DSIDXDesc;
  Opts: TIndexOptions;
  IdxName, Flds: string;
  DescFlds, CaseInsFlds: string;
begin
  if (csDesigning in ComponentState) and (IndexDefs.Count > 0) then Exit;
  if Active and not IndexDefs.Updated then
  begin
    FieldDefs.Update;
    Check(FDSCursor.GetCursorProps(CursorProps));
    SetLength(IndexDescs, CursorProps.iIndexes);
    IndexDefs.Clear;
    Check(FDSBase.GetIndexDescs(PDSIDXDesc(IndexDescs)));
    for I := 0 to CursorProps.iIndexes - 1 do
    begin
      DecodeIndexDesc(IndexDescs[I], IdxName, Flds, DescFlds, CaseInsFlds, Opts);
      with IndexDefs.AddIndexDef do
      begin
        Name := IdxName;
        Fields := Flds;
        DescFields := DescFlds;
        CaseInsFields := CaseInsFlds;
        Options := Opts;
      end;
    end;
    IndexDefs.Updated := True;
  end;
end;

procedure TClientDataSet.DecodeIndexDesc(const IndexDesc: DSIDXDesc;
  var Name, Fields, DescFields, CaseInsFields: string; var Options: TIndexOptions);

  procedure ConcatField(var FieldList: string; const FieldName: string);
  begin
    if FieldList = '' then
      FieldList := FieldName else
      FieldList := Format('%s;%s', [FieldList, FieldName]);
  end;

  procedure CheckOption(const FieldList: string; var OptionFields: string;
    Option: TIndexOption);
  begin
    if (FieldList <> '') and (OptionFields = FieldList) then
    begin
      Include(Options, Option);
      OptionFields := '';
    end;
  end;


var
  I: Integer;
  FieldName: string;
begin
  FieldDefList.Update;
  with IndexDesc do
  begin
    Name := szName;
    Fields := '';
    DescFields := '';
    CaseInsFields := '';
    for I := 0 to iFields - 1 do
    begin
      if iKeyFields[I] <= FieldDefList.Count then
      begin
        FieldName := FieldDefList.Strings[iKeyFields[I] - 1];
        ConcatField(Fields, FieldName);
      end else
        FieldName := '';
      if bDescending[I] then
        ConcatField(DescFields, FieldName);
      if bCaseInsensitive[I] then
        ConcatField(CaseInsFields, FieldName);
    end;
    Options := [];
    if bUnique then Include(Options, ixUnique);
    CheckOption(Fields, DescFields, ixDescending);
    CheckOption(Fields, CaseInsFields, ixCaseInsensitive);
  end;
end;

procedure TClientDataSet.GetIndexNames(List: TStrings);
begin
  IndexDefs.Update;
  IndexDefs.GetItemNames(List);
end;

function TClientDataSet.GetIndexDefs: TIndexDefs;
begin
  if FIndexDefs = nil then
    FIndexDefs := TIndexDefs.Create(Self);
  Result := FIndexDefs;
end;

procedure TClientDataSet.SetIndexDefs(Value: TIndexDefs);
begin
  IndexDefs.Assign(Value);
end;

procedure TClientDataSet.GetIndexInfo(IndexName: string);
var
  Index: Integer;
  IndexDesc: DSIDXDesc;
begin
  if FDSCursor.GetIndexDescs(True, IndexDesc) = 0 then
  begin
    FIndexFieldCount := IndexDesc.iFields;
    FIndexFieldMap := IndexDesc.iKeyFields;
    FKeySize := IndexDesc.iKeyLen;
  end;
  Index := IndexDefs.IndexOf(IndexName);
  if Index <> -1 then
    FIndexGroupingLevel := IndexDefs[Index].GroupingLevel else
    FIndexGroupingLevel := 0;
end;

procedure TClientDataSet.SwitchToIndex(const IndexName: string);
var
  Status: DBResult;
  IndexDesc: DSIDXDesc;
begin
  ResetCursorRange;
  Status := FDSCursor.UseIndexOrder(PChar(IndexName));
  if Status <> DBERR_NONE then
  begin
    if Status = DBERR_NOSUCHINDEX then
    begin
      with IndexDefs.Find(IndexName) do
      begin
        EncodeIndexDesc(IndexDesc, Name, Fields, DescFields, CaseInsFields, Options);
        Check(FDSBase.CreateIndex(IndexDesc));
        Check(FDSCursor.UseIndexOrder(PChar(IndexName)));
      end;
    end else
      Check(Status);
  end;
  GetIndexInfo(IndexName);
end;

procedure TClientDataSet.SetIndex(const Value: string; FieldsIndex: Boolean);
begin
  if Active then
  begin
    CheckBrowseMode;
    UpdateCursorPos;
    CheckProviderEOF;
    if (FIndexName <> Value) or (FFieldsIndex <> FieldsIndex) then
    begin
      if FieldsIndex then
        SortOnFields(FDSCursor, Value, False, False) else
        SwitchToIndex(Value);
      FIndexName := Value;
      FFieldsIndex := FieldsIndex;
      if FAggregatesActive then
      begin
        FAggFieldsInit := False;
        ResetAllAggs(FAggregatesActive);
        SetBufListSize(0);
        InitBufferPointers(True);
        try
          SetBufListSize(BufferCount + 1);
        except
          SetState(dsInactive);
          CloseCursor;
          raise;
        end;
      end;
      ResetCursorRange;
      CheckMasterRange;
      Resync([]);
    end;
  end;
  FIndexName := Value;
  FFieldsIndex := FieldsIndex;
end;

procedure TClientDataSet.EncodeIndexDesc(var IndexDesc: DSIDXDesc;
  const Name, Fields, DescFields, CaseInsFields: string; Options: TIndexOptions);

  function IndexFieldOfs(const FieldName: string): Integer;
  var
    FieldNo: Integer;
  begin
    FieldNo := FieldDefs.Find(FieldName).FieldNo;
    for Result := 0 to IndexDesc.iFields - 1 do
      if IndexDesc.iKeyfields[Result] = FieldNo then Exit;
    DatabaseErrorFmt(SIndexFieldMissing, [FieldName], Self);
    Result := -1;
  end;

var
  Pos: Integer;
  Descending,
  CaseInsensitive: Bool;
begin
  FillChar(IndexDesc, SizeOf(IndexDesc), 0);
  with IndexDesc do
  begin
    StrCopy(szName, PChar(Name));
    bUnique := ixUnique in Options;
    Descending := (ixDescending in Options) and (DescFields = '');
    CaseInsensitive := (ixCaseInsensitive in Options) and (CaseInsFields = '');
    Pos := 1;
    while (Pos <= Length(Fields)) and (iFields < MAXKEYFIELDS) do
    begin
      iKeyFields[iFields] :=
        FieldDefList.FieldByName(ExtractFieldName(Fields, Pos)).FieldNo;
      bDescending[iFields] := Descending;
      bCaseInsensitive[iFields] := CaseInsensitive;
      Inc(iFields);
    end;
    Pos := 1;
    while Pos <= Length(DescFields) do
      bDescending[IndexFieldOfs(ExtractFieldName(DescFields, Pos))] := True;
    Pos := 1;
    while Pos <= Length(CaseInsFields) do
      bCaseInsensitive[IndexFieldOfs(ExtractFieldName(CaseInsFields, Pos))] := True;
  end;
end;

procedure TClientDataSet.AddIndex(const Name, Fields: string;
  Options: TIndexOptions; const DescFields, CaseInsFields: string;
  const GroupingLevel: Integer);
var
  IndexDesc: DSIDXDesc;
  IndexDef: TIndexDef;
begin
  CheckBrowseMode;
  FieldDefs.Update;
  EncodeIndexDesc(IndexDesc, Name, Fields, DescFields, CaseInsFields, Options);
  CursorPosChanged;
  Check(FDSBase.CreateIndex(IndexDesc));
  if GroupingLevel > 0 then
  begin
    IndexDefs.Update;
    IndexDef := IndexDefs.Find(Name);
    if IndexDef <> nil then
      IndexDef.GroupingLevel := GroupingLevel;
  end
  else
    IndexDefs.Updated := False;
end;

procedure TClientDataSet.DeleteIndex(const Name: string);
begin
  CheckBrowseMode;
  if AnsiCompareText(Name, IndexName) = 0 then IndexName := '';
  Check(FDSBase.RemoveIndex(PChar(Name)));
  IndexDefs.Updated := False;
end;

function TClientDataSet.GetIndexField(Index: Integer): TField;
var
  FieldNo: Integer;
begin
  if (Index < 0) or (Index >= FIndexFieldCount) then
    DatabaseError(SFieldIndexError, Self);
  FieldNo := FIndexFieldMap[Index];
  Result := FieldByNumber(FieldNo);
  if Result = nil then
    DatabaseErrorFmt(SIndexFieldMissing, [FieldDefs[FieldNo - 1].Name], Self);
end;

function TClientDataSet.GetIsIndexField(Field: TField): Boolean;
var
  I: Integer;
begin
  Result := False;
  with Field do
    if FieldNo > 0 then
      for I := 0 to FIndexFieldCount - 1 do
        if FIndexFieldMap[I] = FieldNo then
        begin
          Result := True;
          Exit;
        end;
end;

function TClientDataSet.GetIndexName: string;
begin
  if FFieldsIndex then Result := '' else Result := FIndexName;
end;

procedure TClientDataSet.SetIndexName(const Value: string);
begin
  SetIndex(Value, False);
end;

procedure TClientDataSet.SetIndexField(Index: Integer; Value: TField);
begin
  GetIndexField(Index).Assign(Value);
end;

function TClientDataSet.GetIndexFieldNames: string;
begin
  if FFieldsIndex then Result := FIndexName else Result := '';
end;

procedure TClientDataSet.SetIndexFieldNames(const Value: string);
begin
  SetIndex(Value, Value <> '');
end;

function TClientDataSet.GetIndexFieldCount: Integer;
begin
  Result := FIndexFieldCount;
end;

procedure TClientDataSet.SortOnFields(Cursor: IDSCursor; const Fields: string;
  CaseInsensitive, Descending: Boolean);
var
  I: Integer;
  FieldList: TList;
  DescFlags, CaseFlags: DSKEYBOOL;

  function GetFlags(Flag: Bool; var FlagArray: DSKEYBOOL): Pointer;
  var
    J: Integer;
  begin
    if not Flag then Result := nil else
    begin
      for J := 0 to FieldList.Count - 1 do
        FlagArray[J] := True;
      Result := @FlagArray;
    end;
  end;

begin
  FieldList := TList.Create;
  try
    GetFieldList(FieldList, Fields);
    for I := 0 to FieldList.Count - 1 do
      if TField(FieldList[I]).FieldNo > 0 then
        FieldList[I] := Pointer(TField(FieldList[I]).FieldNo) else
        DatabaseError(SFieldIndexError, Self);
    Check(Cursor.SortOnFields(FieldList.Count, PDWord(FieldList.List),
      GetFlags(Descending, DescFlags), GetFlags(CaseInsensitive, CaseFlags)));
    GetIndexInfo('');
  finally
    FieldList.Free;
  end;
end;

{ Ranges / Keys }

procedure TClientDataSet.AllocKeyBuffers;
var
  KeyIndex: TKeyIndex;
begin
  try
    for KeyIndex := Low(TKeyIndex) to High(TKeyIndex) do
      FKeyBuffers[KeyIndex] := AllocMem(SizeOf(TKeyBuffer) + FRecordSize);
    if Assigned(FCloneSource) then
      for KeyIndex := Low(TKeyIndex) to High(TKeyIndex) do
        Move(FCloneSource.FKeyBuffers[KeyIndex]^, FKeyBuffers[KeyIndex]^,
          SizeOf(TKeyBuffer) + FRecordSize);
  except
    FreeKeyBuffers;
    raise;
  end;
end;

function TClientDataSet.GetKeyBuffer(KeyIndex: TKeyIndex): PKeyBuffer;
begin
  Result := FKeyBuffers[KeyIndex];
end;

procedure TClientDataSet.FreeKeyBuffers;
var
  KeyIndex: TKeyIndex;
begin
  for KeyIndex := Low(TKeyIndex) to High(TKeyIndex) do
    DisposeMem(FKeyBuffers[KeyIndex], SizeOf(TKeyBuffer) + FRecordSize);
end;

function TClientDataSet.InitKeyBuffer(Buffer: PKeyBuffer): PKeyBuffer;
begin
  FillChar(Buffer^, SizeOf(TKeyBuffer) + FRecordSize, 0);
  Check(FDSCursor.InitRecord(PChar(Buffer) + SizeOf(TKeyBuffer)));
  Result := Buffer;
end;

procedure TClientDataSet.CheckSetKeyMode;
begin
  if State <> dsSetKey then DatabaseError(SNotEditing, Self);
end;

function TClientDataSet.SetCursorRange: Boolean;
var
  RangeStart, RangeEnd: PKeyBuffer;
  StartKey, EndKey: PChar;
begin
  Result := False;
  if not (
    BuffersEqual(FKeyBuffers[kiRangeStart], FKeyBuffers[kiCurRangeStart],
    SizeOf(TKeyBuffer) + FRecordSize) and
    BuffersEqual(FKeyBuffers[kiRangeEnd], FKeyBuffers[kiCurRangeEnd],
    SizeOf(TKeyBuffer) + FRecordSize)) then
  begin
    CheckProviderEOF;
    RangeStart := FKeyBuffers[kiRangeStart];
    RangeEnd := FKeyBuffers[kiRangeEnd];
    StartKey := PChar(RangeStart) + SizeOf(TKeyBuffer);
    if not RangeStart.Modified then
      StartKey := nil;
    EndKey := PChar(RangeEnd) + SizeOf(TKeyBuffer);
    if not RangeEnd.Modified then
      EndKey := nil;
    Check(FDSCursor.SetRange(RangeStart.FieldCount, StartKey,
      not RangeStart.Exclusive, EndKey, not RangeEnd.Exclusive));
    Move(FKeyBuffers[kiRangeStart]^, FKeyBuffers[kiCurRangeStart]^,
      SizeOf(TKeyBuffer) + FRecordSize);
    Move(FKeyBuffers[kiRangeEnd]^, FKeyBuffers[kiCurRangeEnd]^,
      SizeOf(TKeyBuffer) + FRecordSize);
    DestroyLookupCursor;
    Result := True;
  end;
end;

function TClientDataSet.ResetCursorRange: Boolean;
begin
  Result := False;
  if FKeyBuffers[kiCurRangeStart].Modified or
    FKeyBuffers[kiCurRangeEnd].Modified then
  begin
    Check(FDSCursor.DropRange);
    InitKeyBuffer(FKeyBuffers[kiCurRangeStart]);
    InitKeyBuffer(FKeyBuffers[kiCurRangeEnd]);
    DestroyLookupCursor;
    Result := True;
  end;
end;

procedure TClientDataSet.SetLinkRanges(MasterFields: TList);
var
  I: Integer;
  SaveState: TDataSetState;
begin
  SaveState := SetTempState(dsSetKey);
  try
    FKeyBuffer := InitKeyBuffer(FKeyBuffers[kiRangeStart]);
    FKeyBuffer^.Modified := True;
    for I := 0 to MasterFields.Count - 1 do
      GetIndexField(I).Assign(TField(MasterFields[I]));
    FKeyBuffer^.FieldCount := MasterFields.Count;
  finally
    RestoreState(SaveState);
  end;
  Move(FKeyBuffers[kiRangeStart]^, FKeyBuffers[kiRangeEnd]^,
    SizeOf(TKeyBuffer) + FRecordSize);
end;

procedure TClientDataSet.SetKeyBuffer(KeyIndex: TKeyIndex; Clear: Boolean);
begin
  CheckBrowseMode;
  FKeyBuffer := FKeyBuffers[KeyIndex];
  Move(FKeyBuffer^, FKeyBuffers[kiSave]^, SizeOf(TKeyBuffer) + FRecordSize);
  if Clear then InitKeyBuffer(FKeyBuffer);
  SetState(dsSetKey);
  SetModified(FKeyBuffer.Modified);
  DataEvent(deDataSetChange, 0);
end;

procedure TClientDataSet.PostKeyBuffer(Commit: Boolean);
begin
  DataEvent(deCheckBrowseMode, 0);
  if Commit then
    FKeyBuffer.Modified := Modified else
    Move(FKeyBuffers[kiSave]^, FKeyBuffer^, SizeOf(TKeyBuffer) + FRecordSize);
  SetState(dsBrowse);
  DataEvent(deDataSetChange, 0);
end;

function TClientDataSet.GetKeyExclusive: Boolean;
begin
  CheckSetKeyMode;
  Result := FKeyBuffer.Exclusive;
end;

procedure TClientDataSet.SetKeyExclusive(Value: Boolean);
begin
  CheckSetKeyMode;
  FKeyBuffer.Exclusive := Value;
end;

function TClientDataSet.GetKeyFieldCount: Integer;
begin
  CheckSetKeyMode;
  Result := FKeyBuffer.FieldCount;
end;

procedure TClientDataSet.SetKeyFieldCount(Value: Integer);
begin
  CheckSetKeyMode;
  FKeyBuffer.FieldCount := Value;
end;

procedure TClientDataSet.SetKeyFields(KeyIndex: TKeyIndex;
  const Values: array of const);
var
  I: Integer;
  SaveState: TDataSetState;
begin
  DoBeforeScroll;
  if FIndexFieldCount = 0 then DatabaseError(SNoFieldIndexes, Self);
  SaveState := SetTempState(dsSetKey);
  try
    FKeyBuffer := InitKeyBuffer(FKeyBuffers[KeyIndex]);
    if FParentDataSet = nil then
    begin
      for I := 0 to High(Values) do GetIndexField(I).AssignValue(Values[I]);
      FKeyBuffer^.FieldCount := High(Values) + 1;
    end else
    begin
      { Skip the linking field for nested datasets }
      for I := 0 to High(Values) do GetIndexField(I+1).AssignValue(Values[I]);
      FKeyBuffer^.FieldCount := High(Values);
    end;
    FKeyBuffer^.Modified := Modified;
  finally
    RestoreState(SaveState);
  end;
  DoAfterScroll;
end;

function TClientDataSet.FindKey(const KeyValues: array of const): Boolean;
begin
  CheckBrowseMode;
  SetKeyFields(kiLookup, KeyValues);
  Result := GotoKey;
end;

procedure TClientDataSet.FindNearest(const KeyValues: array of const);
begin
  CheckBrowseMode;
  SetKeyFields(kiLookup, KeyValues);
  GotoNearest
end;

function TClientDataSet.GotoKey: Boolean;
var
  KeyBuffer: PKeyBuffer;
  RecBuffer: PChar;
begin
  CheckBrowseMode;
  CursorPosChanged;
  CheckProviderEOF;
  KeyBuffer := FKeyBuffers[kiLookup];
  RecBuffer := PChar(KeyBuffer) + SizeOf(TKeyBuffer);
  Result := FDSCursor.GetRecordForKey(KeyBuffer.FieldCount, 0, RecBuffer, nil) = 0;
  if Result then Resync([rmExact, rmCenter]);
end;

procedure TClientDataSet.GotoNearest;
var
  SearchCond: DBSearchCond;
  KeyBuffer: PKeyBuffer;
  RecBuffer: PChar;
begin
  CheckBrowseMode;
  CheckProviderEOF;
  KeyBuffer := FKeyBuffers[kiLookup];
  RecBuffer := PChar(KeyBuffer) + SizeOf(TKeyBuffer);
  if KeyBuffer^.Exclusive then
    SearchCond := keySEARCHGT else
    SearchCond := keySEARCHGEQ;
  Check(FDSCursor.MoveToKey(SearchCond, KeyBuffer.FieldCount, 0, RecBuffer));
  Resync([rmCenter]);
end;

procedure TClientDataSet.SetKey;
begin
  SetKeyBuffer(kiLookup, True);
end;

procedure TClientDataSet.EditKey;
begin
  SetKeyBuffer(kiLookup, False);
end;

procedure TClientDataSet.ApplyRange;
begin
  CheckBrowseMode;
  if SetCursorRange then First;
end;

procedure TClientDataSet.CancelRange;
begin
  CheckBrowseMode;
  UpdateCursorPos;
  if ResetCursorRange then Resync([]);
end;

procedure TClientDataSet.SetRange(const StartValues, EndValues: array of const);
begin
  CheckBrowseMode;
  SetKeyFields(kiRangeStart, StartValues);
  SetKeyFields(kiRangeEnd, EndValues);
  ApplyRange;
end;

procedure TClientDataSet.SetRangeEnd;
begin
  SetKeyBuffer(kiRangeEnd, True);
end;

procedure TClientDataSet.SetRangeStart;
begin
  SetKeyBuffer(kiRangeStart, True);
end;

procedure TClientDataSet.EditRangeEnd;
begin
  SetKeyBuffer(kiRangeEnd, False);
end;

procedure TClientDataSet.EditRangeStart;
begin
  SetKeyBuffer(kiRangeStart, False);
end;

{ Master / Detail }

procedure TClientDataSet.CheckDetailRecords;
var
  I, RecCount: Integer;
  MasterValues: OleVariant;
  Status: DBResult;
begin
  Status := FDSCursor.GetRecordCount(RecCount);
  if DataSetField <> nil then
  begin
    if (Status = DBERR_DETAILSNOTFETCHED) and FetchOnDemand then
      FParentDataSet.FetchDetails;
  end else
  begin
    if (RecCount = 0) and HasAppServer and not ProviderEOF and
      (FPacketRecords = 0) and not MasterSource.DataSet.IsEmpty and
      (MasterSource.DataSet.State <> dsInsert) then
    begin
      MasterValues := VarArrayCreate([0, FMasterLink.Fields.Count - 1], varVariant);
      for I := 0 to FMasterLink.Fields.Count - 1 do
        with TField(FMasterLink.Fields[I]) do
          MasterValues[I] := VarArrayOf([IndexFields[I].FieldName, Value]);
      AddDataPacket(DoGetRecords(-1, RecCount, 0, '', MasterValues), False);
      if Active then First;
    end;
  end;
end;

procedure TClientDataSet.CheckMasterRange;
begin
  if FMasterLink.Active and (FMasterLink.Fields.Count > 0) then
  begin
    SetLinkRanges(FMasterLink.Fields);
    SetCursorRange;
    if FetchOnDemand then CheckDetailRecords;
  end;
end;

procedure TClientDataSet.MasterChanged(Sender: TObject);
begin
  CheckBrowseMode;
  if DataSetField = nil then
  begin
    SetLinkRanges(FMasterLink.Fields);
    ApplyRange;
    if FetchOnDemand then CheckDetailRecords;
  end else
  begin
    if FParentDataSet.State = dsInsert then
      First
    else if not CompareMem(FLastParentBM, @FParentDataSet.ActiveBuffer[FParentDataset.FBookmarkOfs], FParentDataSet.BookmarkSize) then
    begin
      if FetchOnDemand then CheckDetailRecords;
      First;
      Move(FParentDataSet.ActiveBuffer[FParentDataSet.FBookmarkOfs], FLastParentBM[0], FParentDataSet.BookmarkSize);
    end else
    begin
      UpdateCursorPos;
      Resync([]);
    end;
  end;
end;

procedure TClientDataSet.MasterDisabled(Sender: TObject);
begin
  CancelRange;
end;

procedure TClientDataSet.SetDataSetField(const Value: TDataSetField);
begin
  if Assigned(Value) then
  begin
    Close;
    ProviderName := '';
    RemoteServer := nil;
    FileName := '';
  end;
  inherited;
end;

procedure TClientDataSet.Loaded;
begin
  inherited Loaded;
  if Active and Assigned(FSavedPacket) then Open;
end;

procedure TClientDataSet.ReadData(Stream: TStream);
begin
  ReadDataPacket(Stream, True);
end;

procedure TClientDataSet.WriteData(Stream: TStream);
begin
  WriteDataPacket(Stream, True);
end;

function TClientDataSet.GetDataSource: TDataSource;
begin
  Result := FMasterLink.DataSource;
end;

procedure TClientDataSet.SetDataSource(Value: TDataSource);
begin
  if (Value <> nil) and (DataSetField <> nil) then
    DatabaseError(SNoNestedMasterSource, Self);
  if IsLinkedTo(Value) then DatabaseError(SCircularDataLink, Self);
  FMasterLink.DataSource := Value;
  if not (csDesigning in ComponentState) or
    (csLoading in ComponentState) then Exit;
  if Assigned(Value) then
  begin
    if FPacketRecords = -1 then FPacketRecords := 0;
  end else
  begin
    if FPacketRecords = 0 then FPacketRecords := -1;
  end;
end;

function TClientDataSet.GetMasterFields: string;
begin
  Result := FMasterLink.FieldNames;
end;

procedure TClientDataSet.SetMasterFields(const Value: string);
begin
  FMasterLink.FieldNames := Value;
end;

procedure TClientDataSet.DoOnNewRecord;
var
  I: Integer;
begin
  if DataSetField = nil then
    if FMasterLink.Active and (FMasterLink.Fields.Count > 0) then
      for I := 0 to FMasterLink.Fields.Count - 1 do
        IndexFields[I] := TField(FMasterLink.Fields[I]);
  if (AggFields.Count > 0) and AggregatesActive then
    GetAggFieldData(ActiveBuffer);
  inherited DoOnNewRecord;
end;

procedure TClientDataSet.DefineProperties(Filer: TFiler);

  function DataStored: Boolean;
  begin
    Result := Active and (DataSetField = nil) and not HasAppServer and
      (ProviderName = '') and (FCloneSource = nil);
    if Result and Assigned(Filer.Ancestor) then
      with TClientDataSet(Filer.Ancestor) do
        Result := not Active or HasAppServer or (ProviderName <> '') or
          (DataSize <> Self.DataSize);
  end;

begin
  inherited DefineProperties(Filer);
  Filer.DefineBinaryProperty('Data', ReadData, WriteData, DataStored);
end;

{ Filters }

procedure TClientDataSet.ActivateFilters;
begin
  if Filter <> '' then
    AddExprFilter(Filter, FilterOptions);
  if Assigned(OnFilterRecord) then
    AddFuncFilter;
end;

procedure TClientDataSet.DeactivateFilters;
begin
  if FFuncFilter <> nil then
  begin
    FDSCursor.DropFilter(FFuncFilter);
    FFuncFilter := nil;
  end;
  if FExprFilter <> nil then
  begin
    FDSCursor.DropFilter(FExprFilter);
    FExprFilter := nil;
  end;
end;

procedure TClientDataSet.AddExprFilter(const Expr: string; Options: TFilterOptions);
begin
  if FExprFilter <> nil then FDSCursor.DropFilter(FExprFilter);
  if Expr <> '' then
    with TExprParser.Create(Self, Expr, Options, [poExtSyntax], '', nil, FieldTypeMap) do
    try
      CheckProviderEOF;
      Check(FDSCursor.AddFilter(FilterData, DataSize, FExprFilter));
    finally
      Free;
    end;
end;

function TClientDataSet.FilterCallback(RecBuf: PChar): Bool;
var
  SaveState: TDataSetState;
  Accept: Boolean;
begin
  SaveState := SetTempState(dsFilter);
  FFilterBuffer := RecBuf;
  try
    Accept := True;
    OnFilterRecord(Self, Accept);
  except
    Application.HandleException(Self);
  end;
  RestoreState(SaveState);
  Result := Accept;
end;

procedure TClientDataSet.AddFuncFilter;
begin
  if FFuncFilter <> nil then FDSCursor.DropFilter(FFuncFilter);
  CheckProviderEOF;
  Check(FDSCursor.AddFilterCallBack(Integer(Self), @TClientDataSet.FilterCallback,
    FFuncFilter));
end;

procedure TClientDataSet.SetFilterData(const Text: string; Options: TFilterOptions);
begin
  if Active and Filtered then
  begin
    CheckBrowseMode;
    if (Filter <> Text) or (FilterOptions <> Options) then
      AddExprFilter(Text, Options);
    DestroyLookupCursor;
    First;
  end;
  inherited SetFilterText(Text);
  inherited SetFilterOptions(Options);
end;

procedure TClientDataSet.SetFilterText(const Value: string);
begin
  SetFilterData(Value, FilterOptions);
end;

procedure TClientDataSet.SetFilterOptions(Value: TFilterOptions);
begin
  SetFilterData(Filter, Value);
end;

procedure TClientDataSet.SetOnFilterRecord(const Value: TFilterRecordEvent);
begin
  if Active and Filtered then
  begin
    CheckBrowseMode;
    if Assigned(OnFilterRecord) <> Assigned(Value) then
    begin
      if Assigned(Value) then
      begin
        inherited SetOnFilterRecord(Value);
        AddFuncFilter;
      end else
        FDSCursor.DropFilter(FFuncFilter);
    end;
    DestroyLookupCursor;
    First;
  end;
  inherited SetOnFilterRecord(Value);
end;

procedure TClientDataSet.SetFiltered(Value: Boolean);
begin
  if Active then
  begin
    CheckBrowseMode;
    if Filtered <> Value then
    begin
      DestroyLookupCursor;
      FDSCursor.MoveToBOF;
      if Value then ActivateFilters else DeactivateFilters;
      inherited SetFiltered(Value);
    end;
    First;
  end else
    inherited SetFiltered(Value);
end;

procedure TClientDataSet.SetStatusFilter(const Value: TUpdateStatusSet);
var
  StatusValues: Integer;
begin
  CheckBrowseMode;
  if Value <> [] then
  begin
    StatusValues := 0;
    if usModified in Value then
      StatusValues := dsRecModified;
    if usInserted in Value then
      StatusValues := StatusValues + dsRecNew;
    if usDeleted in Value then
      StatusValues := StatusValues + dsRecDeleted;
    IndexName := szCHANGEINDEX;
    Check(FDSBase.SetProp(dspropCHANGEINDEX_VIEW, StatusValues));
  end else
  begin
    if IndexName = szCHANGEINDEX then
      IndexName := szDEFAULT_ORDER;
    Check(FDSBase.SetProp(dspropCHANGEINDEX_VIEW, 0));
  end;
  FStatusFilter := Value;
  Resync([]);
end;

function TClientDataSet.FindRecord(Restart, GoForward: Boolean): Boolean;
var
  Status: DBResult;
  Cursor: IDSCursor;
begin
  CheckBrowseMode;
  SetFound(False);
  UpdateCursorPos;
  CursorPosChanged;
  CheckProviderEOF;
  DoBeforeScroll;
  if not Filtered then
  begin
    if Restart then FFindCursor := nil;
    if not Assigned(FFindCursor) then
    begin
      ActivateFilters;
      try
        FFindCursor := CreateDSCursor(FDSCursor)
      finally
        DeactivateFilters;
      end;
    end else
      if not Restart then SyncCursors(FFindCursor, FDSCursor);
    Cursor := FFindCursor;
  end else
    Cursor := FDSCursor;
  if GoForward then
  begin
    if Restart then Check(Cursor.MoveToBOF);
    Status := Cursor.MoveRelative(1);
  end else
  begin
    if Restart then Check(Cursor.MoveToEOF);
    Status := Cursor.MoveRelative(-1);
  end;
  if Cursor <> FDSCursor then
  begin
    SyncCursors(FDSCursor, FFindCursor);
    Status := FDSCursor.GetCurrentRecord(nil);
  end;
  if Status = DBERR_NONE then
  begin
    Resync([rmExact, rmCenter]);
    SetFound(True);
  end;
  Result := Found;
  if Result then DoAfterScroll;
end;

procedure TClientDataSet.DestroyLookupCursor;
begin
  FFindCursor := nil;
end;

function TClientDataSet.LocateRecord(const KeyFields: string;
  const KeyValues: Variant; Options: TLocateOptions;
  SyncCursor: Boolean): Boolean;
var
  Fields: TList;
  I: Integer;
  Status: DBResult;
  FilterOptions: TFilterOptions;
  ExprParser: TExprParser;
  ValStr, Expr: string;
  Value: Variant;
begin
  CheckBrowseMode;
  CursorPosChanged;
  CheckProviderEOF;
  Fields := TList.Create;
  try
    GetFieldList(Fields, KeyFields);
    Expr := '';
    for i := 0 to Fields.Count - 1 do
    begin
      if (Fields.Count = 1) and not VarIsArray(KeyValues) then
        Value := KeyValues else
        Value := KeyValues[i];
      case TField(Fields[i]).DataType of
        ftString, ftFixedChar, ftWideString, ftGUID:
          if (i = Fields.Count - 1) and (loPartialKey in Options) then
            ValStr := Format('''%s*''',[VarToStr(Value)]) else
            ValStr := Format('''%s''',[VarToStr(Value)]);
        ftDate, ftTime, ftDateTime:
          ValStr := Format('''%s''',[VarToStr(Value)]);
        ftSmallint, ftInteger, ftWord, ftAutoInc, ftBoolean, ftFloat, ftCurrency, ftBCD, ftLargeInt:
          ValStr := VarToStr(Value);
      else
        DatabaseErrorFmt(SBadFieldType, [TField(Fields[i]).FieldName]);
      end;
      if Expr <> '' then
        Expr := Expr + ' and ';
      if VarIsNull(Value) then
        Expr := Expr + Format('[%s] IS NULL',[TField(Fields[i]).FieldName]) 
      else
        Expr := Expr + Format('[%s]=%s',[TField(Fields[i]).FieldName, ValStr]);
    end;
    FilterOptions := [];
    if loCaseInsensitive in Options then
      FilterOptions := [foCaseInsensitive];
    if not (loPartialKey in Options) then
      Include(FilterOptions, foNoPartialCompare);
    ExprParser := TExprParser.Create(Self, Expr, FilterOptions, [], '', nil, FieldTypeMap);
    try
      FDSCursor.MoveToBOF;
      Status := FDSCursor.LocateWithFilter(ExprParser.FilterData, ExprParser.DataSize);
      if Status = DBERR_NONE then
        FDSCursor.GetCurrentRecord(TempBuffer);
    finally
      ExprParser.Free;
    end;
  finally
    Fields.Free;
  end;
  Result := Status = DBERR_NONE;
end;

function TClientDataSet.Lookup(const KeyFields: string; const KeyValues: Variant;
  const ResultFields: string): Variant;
begin
  Result := Null;
  if LocateRecord(KeyFields, KeyValues, [], False) then
  begin
    SetTempState(dsCalcFields);
    try
      CalculateFields(TempBuffer);
      Result := FieldValues[ResultFields];
    finally
      RestoreState(dsBrowse);
    end;
  end;
end;

function TClientDataSet.Locate(const KeyFields: string;
  const KeyValues: Variant; Options: TLocateOptions): Boolean;
begin
  DoBeforeScroll;
  Result := LocateRecord(KeyFields, KeyValues, Options, True);
  if Result then
  begin
    Resync([rmExact, rmCenter]);
    DoAfterScroll;
  end;
end;

procedure TClientDataSet.GotoCurrent(DataSet: TClientDataSet);
begin
  CheckBrowseMode;
  CheckProviderEOF;
  DataSet.CheckActive;
  BookMark := DataSet.BookMark;
end;

{ Aggregates }

function AggValueAsVariant(Agg: TAggregate; Buffer: Pointer): Variant;
var
  C: Currency;
begin
  case Agg.DataType of
    ftInteger:
      Result := LongInt(Buffer^);
    ftSmallInt:
      Result := SmallInt(Buffer^);
    ftBoolean:
      Result := WordBool(Buffer^);
    ftFloat:
      Result := Double(Buffer^);
    ftBCD:
      begin
        BCDToCurr(TBcd(Buffer^), C);
        Result := C;
      end;
    ftDate:
      Result := VarFromDateTime(TDateTimeRec(Buffer^).Date - DateDelta);
    ftTime:
      Result := VarFromDateTime(TDateTimeRec(Buffer^).Time / MSecsPerDay);
    ftDateTime:
      Result := VarFromDateTime((TDateTimeRec(Buffer^).DateTime / MSecsPerDay) - DateDelta);
    ftString, ftGUID:
      Result := string(PChar(Buffer));
    ftWideString:
      with TVarData(Result) do
      begin
        VType := varOleStr;
        VOleStr := SysAllocStringLen(PWideChar(PChar(Buffer)+2), Word(Buffer^) div 2);
      end;
    else
      Result := Null;
  end;
end;

procedure TClientDataSet.SetAggregates(Value: TAggregates);
begin
  FAggregates.Assign(Value);
end;

procedure TClientDataSet.SetAggsActive(Value: Boolean);
begin
  if FAggregatesActive <> Value then
  begin
    FAggregatesActive := Value;
    if FAggregatesActive and Active then
    begin
      ResetAllAggs(FAggregatesActive);
      if AggFields.Count > 0 then
      begin
        UpdateCursorPos;
        Resync([]);
      end;
    end;
  end;
end;

procedure TClientDataSet.ClearActiveAggs;
var
  I: Integer;
begin
  if FActiveAggLists <> nil then
    for I:= 0 to FActiveAggLists.Count - 1  do
      if FActiveAggLists[I] <> nil then TList(FActiveAggLists[I]).Free;
  FActiveAggLists.Clear;
end;

procedure TClientDataSet.CloseAggs;
var
  I: Integer;
  Field: TAggregateField;
begin
  for I := 0 to FAggregates.Count - 1 do
    begin
      if (FAggregates[I].AggHandle <> 0) and (FDSCursor <> nil) then
        Check(FDSCursor.DropAggregate(FAggregates[I].AggHandle));
      FAggregates[I].AggHandle := 0;
    end;
  for I := 0 to AggFields.Count - 1 do
  begin
    Field := AggFields[I] as TAggregateField;
    if Field.Handle <> nil then
    begin
       TAggregate(Field.Handle).Free;
       Field.Handle := nil;
    end;
  end;
  FAggFieldsInit := False;
end;

procedure TClientDataSet.ResetGrouping;

  function HasAggs(Level: Integer): Boolean;
  var
    I: Integer;
  begin
    Result := False;
    for I := 0 to FAggregates.Count - 1 do
      if TAggregate(FAggregates[I]).GroupingLevel = Level then
      begin
        Result := True;
        Exit;
      end;
  end;

var
  I: Integer;
  Agg: TAggregate;
begin
  FGroupingLevel := FMaxAggGroupingLevel;
  if FIndexGroupingLevel > FGroupingLevel then
    FGroupingLevel := FIndexGroupingLevel;
  for I:= 1 to FGroupingLevel do
  begin
    if not HasAggs(I) then
    begin
      Agg := FAggregates.Add;
      Agg.GroupingLevel := I;
      Agg.IndexName := FIndexName;
      Agg.Active := True;
      Agg.Activate;
    end;
  end;
end;

procedure TClientDataSet.ResetAgg(Agg: TAggregate; DeleteFirst: Boolean);
var
  I, J: Integer;
begin
  if DeleteFirst then
    for I:=0 to FActiveAggLists.Count - 1 do
    begin
      J := TList(FActiveAggLists.Items[I]).IndexOf(Agg);
      if J <> -1 then
      begin
        with TList(FActiveAggLists.Items[I]) do
        begin
          Delete(J);
          Pack;
          Capacity := Count;
        end;
        Break;
      end;
    end;

  if Agg.Active and ((AnsiCompareText(Agg.IndexName, FIndexName) = 0)
     or (Agg.GroupingLevel = 0)) then
  begin
    if Agg.DataSet = nil then Agg.FDataSet := Self;
    Agg.Activate;
    Agg.FInUse := True;
    if Agg.GroupingLevel > FMaxAggGroupingLevel then
      FMaxAggGroupingLevel := Agg.GroupingLevel;
    while FActiveAggLists.Count <= Agg.GroupingLevel do
      FActiveAggLists.Add(TList.Create);
    if Agg.Expression <> '' then
      TList(FActiveAggLists.Items[Agg.GroupingLevel]).Add(Agg);
  end else
  begin
    Agg.FInUse := False;
    if Agg.AggHandle <> 0 then
    begin
      Check(DSCursor.DropAggregate(Agg.AggHandle));
      Agg.AggHandle := 0;
    end
  end;
  if FMaxAggGroupingLevel > GroupingLevel then
    FGroupingLevel := FMaxAggGroupingLevel;
end;


procedure TClientDataSet.ResetAllAggs(Value: Boolean);

  procedure CreateAggsFromAggFields;
  var
    I, MaxGrp: Integer;
    Agg: TAggregate;
    Field: TAggregateField;
  begin
    { Link persistent aggregate fields with TAggregate objects }
    MaxGrp := 0;
    FAggFieldsSize := 0;
    for I := 0 to AggFields.Count - 1 do
    begin
      Field := AggFields[I] as TAggregateField;
      if (Field.GroupingLevel = 0) or (Field.IndexName = FIndexName) then
      begin
        if Field.GroupingLevel > MaxGrp then
          MaxGrp := Field.GroupingLevel;
        if Field.Handle = nil then
        begin
          Agg := TAggregate.Create(nil, Self);
          Agg.Assign(Field);
          if not Agg.Active and (Agg.Expression <> '') then
          begin
            Agg.Active := True;
            Agg.Active := False;
          end;
          Field.Handle := Pointer(Agg);
          Field.ResultType := Agg.DataType;
        end else
        begin
          Agg := TAggregate(Field.Handle);
          Field.ResultType := Agg.DataType;
        end;
        Agg.RecBufOfs := FAggFieldsSize;
        Inc(FAggFieldsSize, Agg.DataSize + 1); { add one for null ind. }
      end;
    end;
    FAggGrpIndSize := MaxGrp * Sizeof(TGroupPosInds);
    FAggFieldsInit := True;
  end;
var
  I: Integer;
  Agg: TAggregate;
  Field: TAggregateField;
begin
  ClearActiveAggs;
  if FAggFieldsUpdated = nil then
    FAggFieldsUpdated := TBits.Create;
  if AggFields.Count + FAggregates.Count = 0 then Exit;
  FGroupingLevel := 0;
  FMaxAggGroupingLevel := 0;
  if not FAggFieldsInit then
    CreateAggsFromAggFields;
  if Assigned(DSCursor) and FAggregatesActive then
  begin
    for I := 0 to FAggregates.Count - 1 do
    begin
      Agg := FAggregates.GetItem(I);
      if Value then
        ResetAgg(Agg, False) else
        Agg.FInUse := False;
    end;
    for I := 0 to AggFields.Count - 1 do
    begin
      Field := AggFields[I] as TAggregateField;
      if (Field.Handle <> nil) then
      begin
        if (Field.GroupingLevel <> 0) and (Field.IndexName <> FIndexName) then
           TAggregate(Field.Handle).FInUse := False else
           TAggregate(Field.Handle).FInUse := True;
      end;
    end;
    ResetGrouping;
    DoAggUpdates(False);
  end;
end;

function TClientDataSet.InternalGetGroupState(Level: Integer): TGroupPosInds;
var
  Status: DBResult;
  DSGrpState: GROUPSTATE;
begin
  Status := FDSCursor.GetSubGroupState(Level, DSGrpState);
  if (Status = DBERR_NONE) or (Status = DBERR_BOF) or (Status = DBERR_EOF) then
    case DSGrpState of
      grSTATEMIDDLE: Result := [gbMiddle];
      grSTATEFIRST: Result := [gbFirst];
      grSTATELAST: Result := [gbLast];
      grSTATEFIRSTLAST: Result := [gbFirst, gbLast];
    end
  else
    Result := [];
end;

function TClientDataSet.GetGroupState(Level: Integer): TGroupPosInds;
begin
  if not Active or not AggregatesActive or (FIndexName = '') then
    Result := []
  else
  begin
    if Level > FGroupingLevel then
      DatabaseError(SAggsNoSuchLevel, Self);
    UpdateCursorPos;
    Result := InternalGetGroupState(Level);
  end;
end;

function TClientDataSet.GetActiveAggs(Index: Integer): TList;
begin
  if Index < FActiveAggLists.Count then
    Result := FActiveAggLists.Items[Index] else
    Result := nil;
end;

procedure TClientDataSet.DoAggUpdates(IsUpdate: Boolean);

  function Intersect(List1, List2: TBits): Boolean;
  var
    I: Integer;
  begin
    for I := 0 to List1.Size - 1 do
      if List1[I] and List2[I] then
      begin
        Result := True;
        Exit;
      end;
    Result := False;
  end;

var
  I: Integer;
  Agg: TAggregate;
begin
  for I := 0 to FAggregates.Count - 1 do
  begin
    Agg := FAggregates.Items[I];
    if Assigned(Agg.OnUpdate) and Agg.Active and Agg.InUse then
    begin
      if not IsUpdate or Intersect(FAggFieldsUpdated, Agg.DependentFields) then
        Agg.OnUpdate(Agg);
    end;
  end;
  for I := 0 to FAggFieldsUpdated.Size - 1 do
    FAggFieldsUpdated[I] := False;
end;

procedure TClientDataSet.GetAggFieldData(Buffer: PChar);
type
  PTGroupPosInds = ^TGroupPosInds;
var
  I: Integer;
  Agg: TAggregate;
  Blank: Bool;
  PAggData: PChar;
begin
  for I := 0 to AggFields.Count - 1 do
  begin
    Agg := TAggregate(TAggregateField(AggFields[I]).Handle);
    if (Agg <> nil) and Agg.InUse then
    begin
      PAggData := Buffer + FAggFieldsOfs + Agg.RecBufOfs;
      if Agg.InUse  and Agg.Active and (FDSCursor.GetAggregateValue(Agg.AggHandle,
         Pointer(PAggData+1), Blank) = DBERR_NONE) and not Blank then
        PAggData[0] := #0 else
        PAggData[0] := #1;
    end;
  end;
end;

function TClientDataSet.GetAggregateValue(Field: TField): Variant;
var
 Agg: TAggregate;
 RecBuf: PChar;
begin
 Result := NULL;
 if GetActiveRecBuf(RecBuf) then
 begin
   Agg := TAggregate(TAggregateField(Field).Handle);
   if Agg <> nil then
   begin
     if Agg.InUse then
     begin
       Inc(RecBuf, FAggFieldsOfs + Agg.RecBufOfs);
       if RecBuf[0] = #1 then
         Result := NULL else
         Result := AggValueAsVariant(Agg, RecBuf + 1)
     end else
       Result := NULL;
   end;
 end;
end;

procedure TClientDataSet.ResetAggField(Field: TField);
var
  I: Integer;
  Agg: TAggregate;
  AggF: TAggregateField;
begin
  for I := 0 to AggFields.Count - 1 do
    if AggFields[I] = Field then
    begin
      AggF := AggFields[I] as TAggregateField;
      Agg := TAggregate(AggF.Handle);
      if Agg <> nil then
      begin
        Agg.Active := False;
        Agg.Assign(AggF);
      end;
    end;
end;

function TClientDataSet.DoApplyUpdates(Delta: OleVariant; MaxErrors: Integer;
  out ErrorCount: Integer): OleVariant;
var
  OwnerData: OleVariant;
begin
  if Assigned(FBeforeApplyUpdates) then FBeforeApplyUpdates(Self, OwnerData);
  Result := AppServer.AS_ApplyUpdates(ProviderName, Delta, MaxErrors, ErrorCount, OwnerData);
  if Assigned(FAfterApplyUpdates) then FAfterApplyUpdates(Self, OwnerData);
end;

function TClientDataSet.DoGetRecords(Count: Integer; out RecsOut: Integer;
  Options: Integer; const CommandText: WideString; Params: OleVariant): OleVariant;
var
  OwnerData: OleVariant;
begin
  if Assigned(FBeforeGetRecords) then FBeforeGetRecords(Self, OwnerData);
  Result := AppServer.AS_GetRecords(ProviderName, Count, RecsOut, Options,
    CommandText, Params, OwnerData);
  UnPackParams(Params, Self.Params);
  if Assigned(FAfterGetRecords) then FAfterGetRecords(Self, OwnerData);
end;

function TClientDataSet.DoRowRequest(Row: OleVariant; RequestType: Integer): OleVariant;
var
  OwnerData: OleVariant;
begin
  if Assigned(FBeforeRowRequest) then FBeforeRowRequest(Self, OwnerData);
  Result := AppServer.AS_RowRequest(ProviderName, Row, RequestType, OwnerData);
  if Assigned(FAfterRowRequest) then FAfterRowRequest(Self, OwnerData);
end;

procedure TClientDataSet.DoExecute(Params: OleVariant);
var
  OwnerData: OleVariant;
begin
  if Assigned(FBeforeExecute) then FBeforeExecute(Self, OwnerData);
  AppServer.AS_Execute(ProviderName, CommandText, Params, OwnerData);
  UnPackParams(Params, Self.Params);
  if Assigned(FAfterExecute) then FAfterExecute(Self, OwnerData);
end;

function TClientDataSet.ConstraintsStored: Boolean;
begin
  Result := Constraints.Count > 0;
end;

procedure TClientDataSet.SetupConstraints;
type
  TConstraintType = (ctField, ctRecord, ctDefault);

  procedure AddSQLExprAttr(ExprParser: TExprParser; const ExprText, ExprErrMsg,
    FieldName: string; FieldIndex: Integer; ConstraintType: TConstraintType;
    Required: Boolean);
  type
    PSQLExprInfo = ^TSQLExprInfo;
    TSQLExprInfo = packed record
      iErrStrLen: Integer;
      iFldNum: Integer;
      bReqExpr: BYTE;
    end;
  const
    TypeStr: array[TConstraintType] of PChar = (szBDEDOMCL, szBDERECCL, szBDEDEFCL);
    Attr: Integer = dsVaryingFldType or SizeOf(Integer) or (dsfldBYTES shl dsSizeBitsLen);
  var
    ErrorStr: string;
    AttrType: PChar;
    Len, AttrSize: Integer;
    SQLExprInfo: PSQLExprInfo;
    Options: TParserOptions;
    FBuffer: array of Byte;
  begin
    try
      SetLength(FBuffer, 4096);
      if ExprText = '' then Exit;
      if (ConstraintType <> ctDefault) and (ExprErrMsg = '') then
      begin
        if (ConstraintType = ctField) and (FieldName <> '') then
          ErrorStr := Format('%s %s: %s %s',[SConstraintFailed, SField, FieldName, ExprText]) else
          ErrorStr := Format('%s %s',[SConstraintFailed, ExprText]);
      end else
        ErrorStr := ExprErrMsg;
      Len := Length(ErrorStr);
      if (Len > 0) then Inc(Len);
      SQLExprInfo := @FBuffer[0];
      SQLExprInfo.iErrStrLen := Len;
      SQLExprInfo.iFldNum := FieldIndex;
      SQLExprInfo.bReqExpr := Ord(Required);
      Options := [poExtSyntax];
      if ConstraintType = ctDefault then Include(Options, poDefaultExpr);
      if ConstraintType = ctRecord then Include(Options, poUseOrigNames);
      if FieldName <> '' then Include(Options, poFieldNameGiven);
      with ExprParser do
      begin
        SetExprParams(ExprText, [], Options, FieldName);
        Move(FilterData[0], FBuffer[SizeOf(TSQLExprInfo) + Len ], DataSize);
        AttrSize := DataSize + SizeOf(TSQLExprInfo) + Len;
      end;
      if Len > 0 then
        StrCopy(@FBuffer[SizeOf(TSQLExprInfo)], PChar(ErrorStr));
      AttrType := TypeStr[ConstraintType];
      Check(FDSBase.AddOptParameter(0, AttrType, Attr, AttrSize + SizeOf(Integer), PByte(FBuffer)));
    finally
      FBuffer := nil;
    end;
  end;


var
  i: Integer;
  ExprParser: TExprParser;
  ErrMsg: string;
begin
  ExprParser := TExprParser.Create(Self, '', [], [], '', nil, FieldTypeMap);
  try
    if Constraints.Count > 0 then
    begin
      try
        for i := 0 to Constraints.Count - 1 do
          with Constraints[i] do
          begin
            AddSQLExprAttr(ExprParser, ImportedConstraint, ErrorMessage, '', 0,
              ctRecord, False);
            AddSQLExprAttr(ExprParser, CustomConstraint, ErrorMessage, '', 0,
              ctRecord, False);
          end;
      except
        on E: Exception do
        begin
          if Name <> '' then
            ErrMsg := Format('%s: %s',[Name, SRecConstFail]) else
            ErrMsg := SRecConstFail;
          raise EDSWriter.CreateFmt(ErrMsg, [E.Message]);
        end;
      end;
    end;
    for i := 0 to FieldList.Count - 1 do
      with FieldList[i] do
      begin
        try
          AddSQLExprAttr(ExprParser, DefaultExpression, '', FullName, i + 1,
            ctDefault, False);
        except
          on E: Exception do
          begin
            if Name <> '' then
              ErrMsg := Format('%s: %s',[Name, SDefExprFail]) else
            if DataSet.Name <> '' then
              ErrMsg := Format('%s.%s: %s',[Name, FullName, SDefExprFail]) else
              ErrMsg := Format('%s: %s',[FullName, SDefExprFail]);
            raise EDSWriter.CreateFmt(ErrMsg, [E.Message]);
          end;
        end;
        try
          AddSQLExprAttr(ExprParser, ImportedConstraint, ConstraintErrorMessage,
            FullName, i + 1, ctField, False);
          AddSQLExprAttr(ExprParser, CustomConstraint, ConstraintErrorMessage,
            FullName, i + 1, ctField, False);
        except
          on E: Exception do
          begin
            if Name <> '' then
              ErrMsg := Format('%s: %s',[Name, SFieldConstFail]) else
{
            if DataSet.Name <> '' then
              ErrMsg := Format('%s.%s: %s',[DataSet.Name, FullName, SFieldConstFail]) else
              ErrMsg := Format('%s: %s',[FullName, SFieldConstFail]); }
            raise EDSWriter.CreateFmt(ErrMsg, [E.Message]);
          end;
        end;
      end;
  finally
    ExprParser.Free;
  end;
end;

{ TClientBlobStream }

constructor TClientBlobStream.Create(Field: TBlobField; Mode: TBlobStreamMode);
begin
  FField := Field;
  FFieldNo := FField.FieldNo;
  FDataSet := FField.DataSet as TClientDataSet;
  if not FDataSet.GetActiveRecBuf(FBuffer) then Exit;
  if Mode <> bmRead then
  begin
    if FField.ReadOnly then
      DatabaseErrorFmt(SFieldReadOnly, [FField.DisplayName], FDataSet);
    if not (FDataSet.State in [dsEdit, dsInsert, dsNewValue]) then
      DatabaseError(SNotEditing, FDataSet);
  end;
  if Mode = bmWrite then Truncate
  else ReadBlobData;
end;

destructor TClientBlobStream.Destroy;
begin
  if FModified then
  try
    FDataSet.Check(FDataSet.FDSCursor.PutBlob(FBuffer, FFieldNo, 0, Memory, Size));
    FField.Modified := True;
    FDataSet.DataEvent(deFieldChange, Longint(FField));
  except
    Application.HandleException(Self);
  end;
  inherited Destroy;
end;

procedure TClientBlobStream.ReadBlobData;
var
  BlobLen: DWord;
begin
  FDataSet.Check(FDataSet.FDSCursor.GetBlobLen(FBuffer, FFieldNo, BlobLen));
  if BlobLen > 0 then
  begin
    Position := 0;
    SetSize(BlobLen);
    FDataSet.Check(FDataSet.FDSCursor.GetBlob(FBuffer, FFieldNo, 0, Memory, BlobLen));
  end;
end;

function TClientBlobStream.Write(const Buffer; Count: Longint): Longint;
begin
  Result := inherited Write(Buffer, Count);
  FModified := True;
end;

procedure TClientBlobStream.Truncate;
begin
  Clear;
  FModified := True;
end;

{ TAggregates }

constructor TAggregates.Create(Owner: TPersistent);
begin
  inherited Create(TAggregate);
  FOwner := Owner;
end;

function TAggregates.Add: TAggregate;
begin
  Result := TAggregate(inherited Add);
  Result.FDataSet := TClientDataSet(GetOwner);
end;

procedure TAggregates.Clear;
var
  DataSet: TClientDataSet;
begin
  inherited Clear;
  DataSet := TClientDataSet(GetOwner);
  if DataSet <> nil then
    DataSet.ResetAllAggs(DataSet.AggregatesActive);
end;

function TAggregates.GetOwner: TPersistent;
begin
  Result := FOwner;
end;

function TAggregates.GetItem(Index: Integer): TAggregate;
begin
  Result := TAggregate(inherited GetItem(Index));
end;

procedure TAggregates.SetItem(Index: Integer; Value: TAggregate);
begin
  inherited SetItem(Index, Value);
end;

function TAggregates.IndexOf(const DisplayName: string): Integer;
begin
  for Result := 0 to Count - 1 do
    if AnsiCompareText(TAggregate(Items[Result]).DisplayName, DisplayName) = 0 then Exit;
  Result := -1;
end;

function TAggregates.Find(const DisplayName: string): TAggregate;
var
  I: Integer;
begin
  I := IndexOf(DisplayName);
  if I < 0 then Result := nil else Result := TAggregate(Items[I]);
end;

{ TAggregate }

constructor TAggregate.Create(Aggregates: TAggregates; ADataSet: TClientDataSet);
begin
  FDataSet := ADataSet;
  inherited Create(Aggregates);
end;

destructor TAggregate.Destroy;
var
  I: Integer;
begin
  if Assigned(FDataSet) and Assigned(FDataSet.AggFields) then
    for I := 0 to FDataSet.AggFields.Count - 1 do
      with TAggregateField(FDataSet.AggFields[I]) do
      begin
        if FHAggregate <> 0 then
        begin
          FDataset.FDSCursor.DropAggregate(FHAggregate);
          FHAggregate := 0;
        end;
        if Handle = Self then Handle := nil;
      end;
  if FDependentFields <> nil then
    FDependentFields.Free;
  inherited Destroy;
end;

procedure TAggregate.Activate;
var
  Parser: TExprParser;
begin
  if FOutOfDate and (FHAggregate <> 0) then
  begin
    FDataSet.Check(FDataSet.DSCursor.DropAggregate(FHAggregate));
    FHAggregate := 0;
  end;
  FOutOfDate := False;
  if FHAggregate = 0 then
  begin
    if FDependentFields = nil then
      FDependentFields := TBits.Create;
    if FExpression <> '' then
    begin
      Parser := TExprParser.Create(FDataSet, FExpression, [],
        [poExtSyntax, poAggregate, poFieldDepend], '', FDependentFields, FieldTypeMap);
      try
        FDataset.Check(FDataSet.DSCursor.AddAggregate(GroupingLevel,
          Parser.DataSize, Parser.FilterData, FHAggregate));
        FDataset.Check(FDataSet.DSCursor.GetAggregateDesc(FHAggregate, FFldDesc));
        SetLength(FDataBuffer, FFldDesc.iFldLen);
        if FFldDesc.iFldType < MAXLOGFLDTYPES then
          FDataType := DataTypeMap[FFldDesc.iFldType] 
        else if FFldDesc.iFldType = fldUNICODE then
          FDataType := ftWideString else
          FDataType := ftUnknown;
        FDataSize := FFldDesc.iFldLen;
      finally
        Parser.Free;
      end;
    end else
      FDataSet.Check(FDataSet.DSCursor.AddAggregate(GroupingLevel, 0, nil,
        FHAggregate));
  end;
end;

procedure TAggregate.Assign(Source: TPersistent);
begin
  if Source is TAggregate then
  begin
    DisplayName := TAggregate(Source).Displayname;
    Visible := TAggregate(Source).Visible;
    Expression := TAggregate(Source).Expression;
    IndexName := TAggregate(Source).IndexName;
    GroupingLevel := TAggregate(Source).GroupingLevel;
    Active := TAggregate(Source).Active;
  end
  else if Source is TAggregateField then
  begin
    DisplayName := TAggregateField(Source).DisplayName;
    Visible := TAggregateField(Source).Visible;
    Expression := TAggregateField(Source).Expression;
    IndexName := TAggregateField(Source).IndexName;
    GroupingLevel := TAggregateField(Source).GroupingLevel;
    Active := TAggregateField(Source).Active;
  end
  else
    inherited Assign(Source);
end;

function TAggregate.GetDisplayName: string;
begin
  Result := FAggregateName;
  if Result = '' then Result := Expression;
  if Result = '' then Result := inherited GetDisplayName;
end;

procedure TAggregate.SetActive(Value: Boolean);
begin
  if Value <> FActive then
  begin
    FActive := Value;
    if (FDataSet <> nil) and (FDataSet.FDSCursor <> nil) then
    try
      FDataSet.ResetAgg(Self, True);
    except
      FActive := False;
      raise;
    end;
  end;
end;

procedure TAggregate.SetExpression(const Text: string);
begin
  if ( FDataSet <> nil ) and (FExpression <> Text ) and Active
    and not (csLoading in FDataSet.ComponentState) then
    DatabaseError(SAggActive, FDataSet);
  if Text <> FExpression then
    FOutOfDate := True;
  FExpression := Text;
end;

procedure TAggregate.SetGroupingLevel(GroupingLevel: Integer);
begin
  if ( FDataSet <> nil ) and (GroupingLevel <> FGroupingLevel ) and Active
    and not (csLoading in FDataSet.ComponentState) then
    DatabaseError(SAggActive, FDataSet);
  if GroupingLevel <> FGroupingLevel then
    FOutOfDate := True;
  FGroupingLevel := GroupingLevel;
end;

procedure TAggregate.SetIndexName(Value: String);
begin
  if ( FDataSet <> nil ) and (FIndexName <> Value) and Active
    and not (csLoading in FDataSet.ComponentState) then
    DatabaseError(SAggActive, FDataSet);
  FIndexName := Value;
end;

function TAggregate.Value: Variant;
var
  Blank: Bool;
begin
  Result := Null;
  if InUse and Active and Assigned(FDataSet) then
  begin
    FDataSet.UpdateCursorPos;
    FDataSet.DSCursor.GetAggregateValue(FHAggregate, Pointer(FDataBuffer), Blank);
    if Blank then
      Result := NULL else
      Result := AggValueAsVariant(Self, FDataBuffer);
  end;
end;

end.
