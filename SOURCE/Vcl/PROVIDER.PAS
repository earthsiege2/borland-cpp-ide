
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Provider - Resolver framework                   }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Provider;

{$T-,H+,X+}

interface

uses Windows, SysUtils, Classes, DbClient, DB, DsIntf, ActiveX, Midas;

type

{ EDSWriter }

  EDSWriter = class(Exception)
  private
    FErrorCode: Integer;
  public
    constructor Create(ErrMsg: string; Status: Integer);
    property ErrorCode: Integer read FErrorCode;
  end;
{$EXTERNALSYM EDSWriter}

(*$HPPEMIT 'namespace Provider' *)
(*$HPPEMIT '{' *)
(*$HPPEMIT 'class DELPHICLASS EDSWriter;' *)
(*$HPPEMIT '#pragma pack(push, 4)' *)
(*$HPPEMIT 'class PASCALIMPLEMENTATION EDSWriter : public Sysutils::Exception' *)
(*$HPPEMIT '{' *)
(*$HPPEMIT '  typedef Sysutils::Exception inherited;' *)
(*$HPPEMIT '' *)
(*$HPPEMIT 'private:' *)
(*$HPPEMIT '  int FErrorCode;' *)
(*$HPPEMIT '' *)
(*$HPPEMIT 'public:' *)
(*$HPPEMIT '  __fastcall EDSWriter(AnsiString ErrMsg, long Status);' *)
(*$HPPEMIT '  __property int ErrorCode = {read=FErrorCode, nodefault};' *)
(*$HPPEMIT 'public:' *)
(*$HPPEMIT '  /* Exception.CreateFmt */ inline __fastcall EDSWriter(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }' *)
(*$HPPEMIT '  /* Exception.CreateRes */ inline __fastcall EDSWriter(int Ident, Extended Dummy) : Sysutils::Exception(Ident, Dummy) { }' *)
(*$HPPEMIT '  /* Exception.CreateResFmt */ inline __fastcall EDSWriter(int Ident, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }' *)
(*$HPPEMIT '  /* Exception.CreateHelp */ inline __fastcall EDSWriter(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }' *)
(*$HPPEMIT '  /* Exception.CreateFmtHelp */ inline __fastcall EDSWriter(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }' *)
(*$HPPEMIT '  /* Exception.CreateResHelp */ inline __fastcall EDSWriter(int Ident, int AHelpContext) : Sysutils::Exception(Ident, AHelpContext) { }' *)
(*$HPPEMIT '  /* Exception.CreateResFmtHelp */ inline __fastcall EDSWriter(int Ident, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }' *)
(*$HPPEMIT '' *)
(*$HPPEMIT 'public:' *)
(*$HPPEMIT '  /* TObject.Destroy */ inline __fastcall virtual ~EDSWriter(void) { }' *)
(*$HPPEMIT '' *)
(*$HPPEMIT '};' *)
(*$HPPEMIT '' *)
(*$HPPEMIT '#pragma pack(pop)' *)
(*$HPPEMIT '}' *)

{ TCustomPacketWriter }

  TCustomPacketWriter = class(TObject)
  private
    FIDSWriter: IDSWriter;
    FBuffer: array of Byte;
  protected
    procedure AddAttribute(Area: TPcktAttrArea; const ParamName: string;
      const Value: OleVariant; IncludeInDelta: Boolean);
    procedure Check(Status: Integer);
    property DSWriter: IDSWriter read FIDSWriter;
  public
    constructor Create; virtual;
    destructor Destroy; override;
  end;

{ TDataPacketWriter }

type

  TGetRecordOption = (grMetaData, grReset, grXML);
  TGetRecordOptions = set of TGetRecordOption;

  TDataRequestEvent = function(Sender: TObject; Input: OleVariant): OleVariant of object;

  TProviderOption = (poFetchBlobsOnDemand, poFetchDetailsOnDemand,
    poIncFieldProps, poCascadeDeletes, poCascadeUpdates, poReadOnly,
    poAllowMultiRecordUpdates, poDisableInserts, poDisableEdits,
    poDisableDeletes, poNoReset, poAutoRefresh, poPropogateChanges,
    poAllowCommandText);
  TProviderOptions = set of TProviderOption;

  PPutFieldInfo = ^TPutFieldInfo;
  TPutFieldProc = procedure(Info: PPutFieldInfo) of object;
  TPutFieldInfo = record
    FieldNo: Integer;
    Field: TField;
    DataSet: TDataSet;
    Size: Integer;
    IsDetail: Boolean;
    Opened: Boolean;
    PutProc: TPutFieldProc;
    LocalFieldIndex: Integer;
    FieldInfos: Pointer;
  end;

  TInfoArray = array of TPutFieldInfo;

  TGetParamsEvent = procedure(DataSet: TDataSet; Params: TList) of object;

  TDataPacketWriter = class(TCustomPacketWriter)
  private
    FConstraints: Boolean;
    FPutFieldInfo: TInfoArray;
    FOptions: TProviderOptions;
    FPacketOptions: TGetRecordOptions;
    FOnGetParams: TGetParamsEvent;
    procedure FreeInfoRecords(var Info: TInfoArray);
    function GetFieldIdx(const FieldName: string; const Info: TInfoArray): Integer;
    procedure AddExtraFieldProps(Field: TField);
    function InitPutProcs(ADataSet: TDataSet; var GlobalIdx: Integer): TInfoArray;
    procedure RefreshPutProcs(ADataSet: TDataSet; var Info: TInfoArray);
  protected
    procedure AddColumn(const Info: TPutFieldInfo);
    procedure AddConstraints(DataSet: TDataSet);
    procedure AddDataSetAttributes(DataSet: TDataSet);
    procedure AddFieldLinks(const Info: TInfoArray);
    procedure AddIndexDefs(DataSet: TDataSet; const Info: TInfoArray);
    procedure PutADTField(Info: PPutFieldInfo);
    procedure PutArrayField(Info: PPutFieldInfo);
    procedure PutBlobField(Info: PPutFieldInfo);
    procedure PutCalcField(Info: PPutFieldInfo);
    procedure PutDataSetField(Info: PPutFieldInfo);
    procedure PutField(Info: PPutFieldInfo);
    procedure PutStringField(Info: PPutFieldInfo);
    procedure PutWideStringField(Info: PPutFieldInfo);
    procedure PutVarBytesField(Info: PPutFieldInfo);
    procedure WriteMetaData(DataSet: TDataSet; const Info: TInfoArray;
      IsReference: Boolean = False);
    function WriteDataSet(DataSet: TDataSet; var Info: TInfoArray;
      RecsOut: Integer): Integer;
    property OnGetParams: TGetParamsEvent read FOnGetParams write FOnGetParams;
  public
    destructor Destroy; override;
    procedure GetDataPacket(DataSet: TDataSet; var RecsOut: Integer;
      out Data: OleVariant);
    property Constraints: Boolean read FConstraints write FConstraints;
    property PacketOptions: TGetRecordOptions read FPacketOptions write FPacketOptions;
    property Options: TProviderOptions read FOptions write FOptions;
  end;

{ TPacketDataSet }

  TPacketDataSet = class(TClientDataSet)
  private
    FOldRecBuf: PChar;
    FCurRecBuf: PChar;
    FCurValues: PChar;
    FUseCurValues: Boolean;
    FWritingCurValues: Boolean;
    FNewValuesModified: Boolean;
    function GetStreamMetaData: Boolean;
    procedure SetStreamMetaData(Value: Boolean);
    procedure SetWritingCurValues(const Value: Boolean);
  protected
    procedure DataEvent(Event: TDataEvent; Info: Longint); override;
    function GetStateFieldValue(State: TDataSetState; Field: TField): Variant; override;
    procedure InternalClose; override;
    procedure InternalOpen; override;
    procedure InternalInitRecord(Buffer: PChar); override;
    procedure SetFieldData(Field: TField; Buffer: Pointer); override;
    property WritingCurValues: Boolean read FWritingCurValues write SetWritingCurValues;
  public
    constructor Create(AOwner: TComponent); override;
    procedure AssignCurValues(Source: TDataSet); overload;
    procedure AssignCurValues(const CurValues: Variant); overload;
    procedure CreateFromDelta(Source: TPacketDataSet);
    function HasCurValues: Boolean;
    function HasMergeConflicts: Boolean;
    procedure InitAltRecBuffers(CheckModified: Boolean = True);
    function UpdateKind: TUpdateKind;
    property NewValuesModified: Boolean read FNewValuesModified;
    property StreamMetaData: Boolean read GetStreamMetaData write SetStreamMetaData;
    property UseCurValues: Boolean read FUseCurValues write FUseCurValues;
  end;

{ TCustomProvider }

  TCustomProvider = class(TComponent)
  private
    FExported: Boolean;
    FOnDataRequest: TDataRequestEvent;
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
    function GetData: OleVariant;
  protected

    function InternalApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
      out ErrorCount: Integer): OleVariant; virtual; abstract;
    function InternalGetRecords(Count: Integer; out RecsOut: Integer;
      Options: TGetRecordOptions; const CommandText: WideString;
      var Params: OleVariant): OleVariant; virtual;
    function InternalRowRequest(const Row: OleVariant; RequestType: TFetchOptions): OleVariant; virtual;
    procedure InternalExecute(const CommandText: WideString; var Params: OleVariant); virtual;
    function InternalGetParams(Types: TParamTypes = AllParamTypes): OleVariant; virtual;

  { Event overrides }
    procedure DoBeforeGetRecords(Count: Integer; Options: Integer;
      const CommandText: WideString; var Params, OwnerData: OleVariant); virtual;
    procedure DoBeforeExecute(const CommandText: WideString; var Params,
      OwnerData: OleVariant); virtual;

  { Events }
    property OnDataRequest: TDataRequestEvent read FOnDataRequest write FOnDataRequest;
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
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    function ApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
      out ErrorCount: Integer): OleVariant; overload;
    function ApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
      out ErrorCount: Integer; var OwnerData: OleVariant): OleVariant; overload;
    function GetRecords(Count: Integer; out RecsOut: Integer;
      Options: Integer): OleVariant; overload;
    function GetRecords(Count: Integer; out RecsOut: Integer; Options: Integer;
      const CommandText: WideString; var Params,
      OwnerData: OleVariant): OleVariant; overload;
    function RowRequest(const Row: OleVariant; RequestType: Integer;
      var OwnerData: OleVariant): OleVariant;
    procedure Execute(const CommandText: WideString; var Params,
      OwnerData: OleVariant);
    function GetParams(var OwnerData: OleVariant): OleVariant;
    function DataRequest(Input: OleVariant): OleVariant; virtual;

    property Data: OleVariant read GetData;
    property Exported: Boolean read FExported write FExported default True;
  end;

{ TBaseProvider }

type

  TCustomResolver = class;
  TResolverResponse = (rrSkip, rrAbort, rrMerge, rrApply, rrIgnore);
  TProviderDataEvent = procedure(Sender: TObject; DataSet: TClientDataSet) of object;
  TBeforeUpdateRecordEvent = procedure(Sender: TObject; SourceDS: TDataSet;
    DeltaDS: TClientDataSet; UpdateKind: TUpdateKind; var Applied: Boolean) of object;
  TAfterUpdateRecordEvent = procedure(Sender: TObject; SourceDS: TDataSet;
    DeltaDS: TClientDataSet; UpdateKind: TUpdateKind) of object;
  TResolverErrorEvent = procedure(Sender: TObject; DataSet: TClientDataSet;
    E: EUpdateError; UpdateKind: TUpdateKind; var Response: TResolverResponse) of object;

  TBaseProvider = class(TCustomProvider)
  private
    FDataDS: TPacketDataSet;
    FUpdateMode: TUpdateMode;
    FResolver: TCustomResolver;
    FOnGetData: TProviderDataEvent;
    FOnUpdateData: TProviderDataEvent;
    FOnUpdateError: TResolverErrorEvent;
    FBeforeUpdateRecord: TBeforeUpdateRecordEvent;
    FAfterUpdateRecord: TAfterUpdateRecordEvent;
    FProviderOptions: TProviderOptions;
  protected
    procedure CheckResolver;
    function CreateResolver: TCustomResolver; virtual;
    procedure FreeResolver;
    procedure CreateDataPacket(PacketOpts: TGetRecordOptions;
      ProvOpts: TProviderOptions; var RecsOut: Integer; var Data: OleVariant); virtual;
    procedure DoOnGetData(var Data: OleVariant);
    procedure DoOnUpdateData(Delta: TPacketDataSet);
    procedure LocateRecord(Source, Delta: TDataSet); virtual;
    procedure UpdateRecord(Source, Delta: TDataSet; BlobsOnly, KeyOnly: Boolean); virtual;
    procedure FetchDetails(Source, Delta: TDataSet); virtual;

    function InternalRowRequest(const Row: OleVariant;
      RequestType: TFetchOptions): OleVariant; override;
    function InternalApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
      out ErrorCount: Integer): OleVariant; override;
    function InternalGetRecords(Count: Integer; out RecsOut: Integer;
      Options: TGetRecordOptions; const CommandText: WideString;
      var Params: OleVariant): OleVariant; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Resolver: TCustomResolver read FResolver;
    property Options: TProviderOptions read FProviderOptions
      write FProviderOptions default [];
    property UpdateMode: TUpdateMode read FUpdateMode write FUpdateMode default upWhereAll;
    property OnDataRequest;
    property OnGetData: TProviderDataEvent read FOnGetData write FOnGetData;
    property OnUpdateData: TProviderDataEvent read FOnUpdateData write FOnUpdateData;
    property OnUpdateError: TResolverErrorEvent read FOnUpdateError write FOnUpdateError;
    property BeforeUpdateRecord: TBeforeUpdateRecordEvent read FBeforeUpdateRecord
      write FBeforeUpdateRecord;
    property AfterUpdateRecord: TAfterUpdateRecordEvent read FAfterUpdateRecord
      write FAfterUpdateRecord;
  end;

{ TDataSetProvider }

  TGetTableNameEvent = procedure(Sender: TObject; DataSet: TDataSet; var TableName: string) of object;
  TGetDSProps = procedure(Sender: TObject; DataSet: TDataSet;
    out Properties: OleVariant) of object;

  TDataSetProvider = class(TBaseProvider)
  private
    FDataSet: TDataSet;
    FDataSetOpened: Boolean;
    FDSWriter: TDataPacketWriter;
    FGetDSProps: TGetDSProps;
    FParams: TParams;
    FResolveToDataSet: Boolean;
    FRecordsSent: Integer;
    FConstraints: Boolean;
    FGetTableName: TGetTableNameEvent;
    procedure CheckDataSet;
    function FindRecord(Source, Delta: TDataSet; UpdateMode: TUpdateMode): Boolean;
    procedure Reset;
    procedure SetCommandText(const CommandText: string);
    procedure SetDataSet(ADataSet: TDataSet);
    procedure SetParams(Values: OleVariant);
    procedure SetResolveToDataSet(Value: Boolean);
  protected
    { SQL Resolver support methods }
    procedure DoGetTableName(DataSet: TDataSet; var TableName: string); virtual;
  protected
    { Event overrides }
    procedure DoBeforeGetRecords(Count: Integer; Options: Integer;
      const CommandText: WideString; var Params, OwnerData: OleVariant); override;
    procedure DoBeforeExecute(const CommandText: WideString; var Params,
      OwnerData: OleVariant); override;
  protected
    procedure DoGetProviderAttributes(DataSet: TDataSet; List: TList); virtual;
    function CreateResolver: TCustomResolver; override;
    procedure CreateDataPacket(PacketOpts: TGetRecordOptions;
      ProvOpts: TProviderOptions; var RecsOut: Integer; var Data: OleVariant); override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure LocateRecord(Source, Delta: TDataSet); override;
    procedure UpdateRecord(Source, Delta: TDataSet; BlobsOnly, KeyOnly: Boolean); override;
    procedure FetchDetails(Source, Delta: TDataSet); override;

    function InternalRowRequest(const Row: OleVariant; Options: TFetchOptions): OleVariant; override;
    function InternalGetParams(Types: TParamTypes = AllParamTypes): OleVariant; override;
    procedure InternalExecute(const CommandText: WideString; var Params: OleVariant); override;
    function InternalGetRecords(Count: Integer; out RecsOut: Integer;
      Options: TGetRecordOptions; const CommandText: WideString;
      var Params: OleVariant): OleVariant; override;
    function InternalApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
      out ErrorCount: Integer): OleVariant; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property DataSet: TDataSet read FDataSet write SetDataSet;
    property Constraints: Boolean read FConstraints write FConstraints;
    property ResolveToDataSet: Boolean read FResolveToDataSet write SetResolveToDataSet default False;
    property Exported;
    property Options;
    property UpdateMode;
    property OnDataRequest;
    property OnGetData;
    property OnUpdateData;
    property OnUpdateError;
    property AfterUpdateRecord;
    property BeforeUpdateRecord;
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
    property OnGetTableName: TGetTableNameEvent read FGetTableName write FGetTableName;
    property OnGetDataSetProperties: TGetDSProps read FGetDSProps write FGetDSProps;
  end;

{ TProvider - deprecated }

  TProvider = class(TDataSetProvider)
  end;

{ TUpdateTree }

  TUpdateTree = class(TObject)
  private
    FDeltaDS: TPacketDataSet;
    FErrorDS: TPacketDataSet;
    FOpened: Boolean;
    FSourceDS: TDataSet;
    FParent: TUpdateTree;
    FDetails: TList;
    FData: Pointer;
    FResolver: TCustomResolver;
    FName: string;
    function GetDetailCount: Integer;
    function GetDetail(Index: Integer): TUpdateTree;
    function GetErrorDS: TPacketDataSet;
    function GetHasErrors: Boolean;
    function GetIsNested: Boolean;
    function GetTree(const AName: string): TUpdateTree;
  protected
    procedure Clear;
    function DoUpdates: Boolean;

    procedure RefreshData(Options: TFetchOptions);
    procedure InitErrorPacket(E: EUpdateError; Response: TResolverResponse);
    procedure InitData(ASource: TDataSet);
    procedure InitDelta(const ADelta: OleVariant); overload;
    procedure InitDelta(ADelta: TPacketDataSet); overload;
    property Data: Pointer read FData write FData;
    property Delta: TPacketDataSet read FDeltaDS;
    property DetailCount: Integer read GetDetailCount;
    property Details[Index: Integer]: TUpdateTree read GetDetail;
    property ErrorDS: TPacketDataSet read GetErrorDS;
    property HasErrors: Boolean read GetHasErrors;
    property Name: string read FName write FName;
    property Parent: TUpdateTree read FParent;
    property Source: TDataSet read FSourceDS;
    property IsNested: Boolean read GetIsNested;
  public
    constructor Create(AParent: TUpdateTree; AResolver: TCustomResolver);
    destructor Destroy; override;
  end;

{ TCustomResolver }

  TCustomResolver = class(TComponent)
  private
    FProvider: TBaseProvider;
    FPrevResponse: TResolverResponse;
    FErrorCount: Integer;
    FMaxErrors: Integer;
    FUpdateTree: TUpdateTree;
  protected
    property Provider: TBaseProvider read FProvider;
    function HandleUpdateError(Tree: TUpdateTree; E: EUpdateError;
      var MaxErrors, ErrorCount: Integer): Boolean;
    procedure LogUpdateRecord(Tree: TUpdateTree);
    procedure LogUpdateError(Tree: TUpdateTree; E: EUpdateError;
      Response: TResolverResponse);
    procedure InitKeyFields(Tree: TUpdateTree; ADelta: TPacketDataSet);
    procedure InternalBeforeResolve(Tree: TUpdateTree); virtual;
    function InternalUpdateRecord(Tree: TUpdateTree): Boolean;
    procedure BeginUpdate; virtual;
    procedure EndUpdate; virtual;
    procedure InitTreeData(Tree: TUpdateTree); virtual;
    procedure FreeTreeData(Tree: TUpdateTree); virtual;
    procedure InitializeConflictBuffer(Tree: TUpdateTree); virtual; abstract;
    procedure DoUpdate(Tree: TUpdateTree); virtual; abstract;
    procedure DoDelete(Tree: TUpdateTree); virtual; abstract;
    procedure DoInsert(Tree: TUpdateTree); virtual; abstract;
    function RowRequest(Row: OleVariant; Options: TFetchOptions): OleVariant; virtual;
    function ApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
      out ErrorCount: Integer): OleVariant; virtual;
  public
    constructor Create(AProvider: TBaseProvider); reintroduce;
    destructor Destroy; override;
  end;

{ TDataSetResolver }

  TDataSetResolver = class(TCustomResolver)
  private
    FBookmark: TBookmarkStr;
    FOpened: Boolean;
    function GetProvider: TDataSetProvider;
    procedure PutRecord(Tree: TUpdateTree);
  protected
    property Provider: TDataSetProvider read GetProvider;
    procedure BeginUpdate; override;
    procedure DoUpdate(Tree: TUpdateTree); override;
    procedure DoDelete(Tree: TUpdateTree); override;
    procedure DoInsert(Tree: TUpdateTree); override;
    procedure EndUpdate; override;
    procedure InternalBeforeResolve(Tree: TUpdateTree); override;
    procedure InitializeConflictBuffer(Tree: TUpdateTree); override;
  public
    constructor Create(AProvider: TDataSetProvider); reintroduce;
  end;

{ TSQLResolver }

  TSQLResolver = class(TCustomResolver)
  private
    FSQL: TStringList;
    FParams: TParams;
    function GetProvider: TDataSetProvider;
    procedure GenWhereSQL(Tree: TUpdateTree; SQL: TStrings; Params: TParams;
      GenUpdateMode: TUpdateMode; Alias: string);
    procedure GenInsertSQL(Tree: TUpdateTree; SQL: TStrings; Params: TParams);
    procedure GenDeleteSQL(Tree: TUpdateTree; SQL: TStrings; Params: TParams;
      Alias: string);
    procedure GenUpdateSQL(Tree: TUpdateTree; SQL: TStrings; Params: TParams;
      Alias: string);
    procedure GenSelectSQL(Tree: TUpdateTree; SQL: TStrings; Params: TParams;
      Alias: string);
    function UseFieldInUpdate(Field: TField): Boolean;
    function UseFieldInWhere(Field: TField; Mode: TUpdateMode): Boolean;
    procedure InternalDoUpdate(Tree: TUpdateTree; UpdateKind: TUpdateKind);
  protected
    property Provider: TDataSetProvider read GetProvider;
    procedure InitializeConflictBuffer(Tree: TUpdateTree); override;
    procedure DoExecSQL(SQL: TStringList; Params: TParams); virtual;
    procedure DoGetValues(SQL: TStringList; Params: TParams;
      DataSet: TDataSet); virtual;
    procedure InitTreeData(Tree: TUpdateTree); override;
    procedure FreeTreeData(Tree: TUpdateTree); override;
    procedure DoUpdate(Tree: TUpdateTree); override;
    procedure DoDelete(Tree: TUpdateTree); override;
    procedure DoInsert(Tree: TUpdateTree); override;
  public
    constructor Create(AProvider: TDataSetProvider); reintroduce;
    destructor Destroy; override;
  end;

{ TLocalAppServer }

  TLocalAppServer = class(TInterfacedObject, IAppServer, ISupportErrorInfo)
  private
    FProvider: TCustomProvider;
    FProviderCreated: Boolean;
  protected
    { IDispatch }
    function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
    function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
    function GetIDsOfNames(const IID: TGUID; Names: Pointer;
      NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
    function Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
    { IAppServer }
    function AS_ApplyUpdates(const ProviderName: WideString; Delta: OleVariant; MaxErrors: Integer;
                             out ErrorCount: Integer; var OwnerData: OleVariant): OleVariant; safecall;
    function AS_GetRecords(const ProviderName: WideString; Count: Integer; out RecsOut: Integer;
                           Options: Integer; const CommandText: WideString;
                           var Params: OleVariant; var OwnerData: OleVariant): OleVariant; safecall;
    function AS_DataRequest(const ProviderName: WideString; Data: OleVariant): OleVariant; safecall;
    function AS_GetProviderNames: OleVariant; safecall;
    function AS_GetParams(const ProviderName: WideString; var OwnerData: OleVariant): OleVariant; safecall;
    function AS_RowRequest(const ProviderName: WideString; Row: OleVariant; RequestType: Integer;
                           var OwnerData: OleVariant): OleVariant; safecall;
    procedure AS_Execute(const ProviderName: WideString;  const CommandText: WideString;
                         var Params, OwnerData: OleVariant); safecall;
    { ISupportErrorInfo }
    function InterfaceSupportsErrorInfo(const iid: TIID): HResult; stdcall;
  public
    constructor Create(AProvider: TCustomProvider); overload;
    constructor Create(ADataset: TDataset); overload;
    destructor Destroy; override;
    function SafeCallException(ExceptObject: TObject;
      ExceptAddr: Pointer): HResult; override;
  end;

{ Utility functions }

function GetObjectProperty(Instance: TPersistent; const PropName: string): TObject;
function GetStringProperty(Instance: TPersistent; const PropName: string): string;

implementation

uses MidConst, DBConsts, DBCommon, TypInfo, DataBkr, ComObj;

const
  DEFBUFSIZE = 8192;  { Default size for field data buffer }
  DefAlias   = 'A';
  NestAlias  = 'B';
  tagSERVERCALC = 1;

  PacketTypeMap: array [TFieldType] of Integer =
    (dsfldUNKNOWN, dsfldZSTRING, dsfldINT, dsfldINT, dsfldINT, dsfldBOOL,
     dsfldFLOATIEEE, dsfldFLOATIEEE, dsfldBCD, dsfldDATE, dsfldTIME,
     dsfldTIMESTAMP, dsfldBYTES, dsfldBYTES, dsfldINT, dsfldBYTES, dsfldBYTES,
     dsfldBYTES, dsfldBYTES, dsfldBYTES, dsfldBYTES, dsfldBYTES, dsfldUNKNOWN,
     dsfldZSTRING, dsfldUNICODE, dsfldINT, dsfldADT, dsfldARRAY, dsfldEMBEDDEDTBL,
     dsfldEMBEDDEDTBL, dsfldBYTES, dsfldBYTES, dsfldUNKNOWN, dsfldUNKNOWN,
     dsfldUNKNOWN, dsfldZSTRING);

  ExtraFieldProps: array [0..10] of string = ('Alignment', 'DisplayLabel',
    'DisplayWidth', 'Visible', 'EditMask', 'DisplayFormat', 'EditFormat',
    'MinValue', 'MaxValue', 'currency', 'DisplayValues');

{ Utility functions }

function GetObjectProperty(Instance: TPersistent; const PropName: string): TObject;
var
  PropInfo: PPropInfo;
begin
  Result := nil;
  PropInfo := TypInfo.GetPropInfo(Instance.ClassInfo, PropName);
  if (PropInfo <> nil) and (PropInfo^.PropType^.Kind = tkClass) then
    Result := TObject(GetOrdProp(Instance, PropInfo));
end;

function GetStringProperty(Instance: TPersistent; const PropName: string): string;
var
  PropInfo: PPropInfo;
begin
  Result := '';
  PropInfo := TypInfo.GetPropInfo(Instance.ClassInfo, PropName);
  if (PropInfo <> nil) and (PropInfo^.PropType^.Kind in [tkString, tkLString, tkWString]) then
    Result := GetStrProp(Instance, PropInfo);
end;

{ EDSWriter }

constructor EDSWriter.Create(ErrMsg: string; Status: Integer);
begin
  FErrorCode := Status;
  inherited Create(ErrMsg);
end;

{ TCustomPacketWriter }

constructor TCustomPacketWriter.Create;
begin
  SetLength(FBuffer, DEFBUFSIZE);
end;

destructor TCustomPacketWriter.Destroy;
begin
  FIDSWriter := nil;
  FBuffer := nil;
  inherited Destroy;
end;

procedure TCustomPacketWriter.Check(Status: Integer);
var
  ErrMsg: array[0..2048] of Char;
begin
  if Status <> 0 then
  begin
    FIDSWriter.GetErrorString(Status, ErrMsg);
    raise EDSWriter.Create(ErrMsg, Status);
  end;
end;

procedure TCustomPacketWriter.AddAttribute(Area: TPcktAttrArea; const ParamName: string;
  const Value: OleVariant; IncludeInDelta: Boolean);
const
  ParamTypeMap: array[varSmallInt..varByte] of Integer =
    ( dsfldINT, dsfldINT, dsfldFLOATIEEE, dsfldFLOATIEEE, dsfldBCD,
      dsfldFLOATIEEE, dsfldZSTRING, 0, 0, dsfldBOOL, 0, 0, 0, 0, 0, dsfldINT);
  ParamTypeSize: array[varSmallInt..varByte] of Integer =
    ( SizeOf(SmallInt), SizeOf(Integer), SizeOf(Single), SizeOf(Double),
      SizeOf(Currency), SizeOf(TDateTime), 0, 0, 0, SizeOf(WordBool), 0, 0, 0,
      0, 0, SizeOf(Byte));
var
  ParamType, ParamLen, ElemSize, ElemCount: DWord;
  P: Pointer;
  DateRec: TDateTimeRec;
  TimeStamp: TTimeStamp;
begin
  if ((VarType(Value) and varTypeMask) in [varSmallInt, varInteger, varSingle,
      varDouble, varCurrency, varDate, varOleStr, varBoolean, varByte]) then
  begin
    ParamType := ParamTypeMap[VarType(Value) and varTypeMask];
    ParamLen := ParamTypeSize[VarType(Value) and varTypeMask];
    if ParamType = dsfldZSTRING then
    begin
      ParamType := (dsfldZSTRING shl dsSizeBitsLen) or dsVaryingFldType or SizeOf(Word);
      ParamLen := Length(Value) + 1;
      PWord(FBuffer)^ := ParamLen;
      Inc(ParamLen, SizeOf(Word));
      StrPCopy(@FBuffer[SizeOf(Word)], Value);
    end else
    if ParamType = dsfldTIMESTAMP then
    begin
      TimeStamp := DateTimeToTimeStamp(Value);
      DateRec.DateTime := TimeStampToMSecs(TimeStamp);
      Move(DateRec, PChar(FBuffer)^, ParamLen);
      ParamType := ParamType shl dsSizeBitsLen or SizeOf(TDateTimeRec);
    end else
    if VarIsArray(Value) then
    begin
      if ParamLen = 0 then
        raise EDSWriter.Create(SInvalidOptParamType, 0);
      ElemCount := VarArrayHighBound(Value, 1) + 1;
      ElemSize := ParamLen;
      ParamType := (dsfldUINT shl dsSizeBitsLen) or dsArrayFldType or ElemSize;
      PInteger(FBuffer)^ := ElemCount;
      ParamLen := ElemCount * ElemSize;
      P := VarArrayLock(Value);
      try
        Move(P^, FBuffer[SizeOf(Integer)], ParamLen);
        Inc(ParamLen, SizeOf(Integer));
      finally
        VarArrayUnlock(Value);
      end;
    end else
    begin
      if (VarType(Value) and varByRef) = varByRef then
        P := TVarData(Value).VPointer else
        P := @TVarData(Value).VPointer;
      Move(P^, PByte(FBuffer)^, ParamLen);
      ParamType := ParamType shl dsSizeBitsLen or ParamLen;
    end;
    if IncludeInDelta then
      ParamType := ParamType or dsIncInDelta;
    Check(FIDSWriter.AddAttribute(Area, PChar(ParamName), ParamType, ParamLen, PByte(FBuffer)));
  end else
    raise EDSWriter.Create(SInvalidOptParamType, 0);
end;

{ TDataPacketWriter }

destructor TDataPacketWriter.Destroy;
begin
  FreeInfoRecords(FPutFieldInfo);
  FPutFieldInfo := nil;
  inherited Destroy;
end;

procedure TDataPacketWriter.FreeInfoRecords(var Info: TInfoArray);
var
  i: Integer;
begin
  for i := 0 to High(Info) do
    if Info[i].FieldInfos <> nil then
    begin
      FreeInfoRecords(TInfoArray(Info[i].FieldInfos));
      TInfoArray(Info[i].FieldInfos) := nil;
    end;
end;

{ Writing data }

procedure TDataPacketWriter.PutBlobField(Info: PPutFieldInfo);
begin
  if not (poFetchBlobsOnDemand in Options) then
  begin
    Info.Size := Info.DataSet.GetBlobFieldData(Info.FieldNo, TBlobByteData(FBuffer));
    if Info.Size <> 0 then
    begin
      if Length(FBuffer) <= Info.Size then
        SetLength(FBuffer, Info.Size + 1);
      FBuffer[Info.Size] := 0;
      if TBlobField(Info.Field).Transliterate then
        Info.Size := Info.DataSet.Translate(PChar(FBuffer), PChar(FBuffer), False);
      FIDSWriter.PutField(fldIsChanged, Info.Size, PByte(FBuffer))
    end else
      FIDSWriter.PutField(fldIsNull, 0, nil);
  end else
    FIDSWriter.PutField(fldIsChanged, dsDELAYEDBIT or 1, @Info.Size);
end;

procedure TDataPacketWriter.PutCalcField(Info: PPutFieldInfo);
begin
  if Info.DataSet.GetFieldData(Info.Field, FBuffer) then
  begin
    if (Info.Field is TStringField) then
      if TStringField(Info.Field).Transliterate then
        Info.Size := Info.DataSet.Translate(PChar(FBuffer), PChar(FBuffer), False) else
        Info.Size := StrLen(PChar(FBuffer));
    FIDSWriter.PutField(fldIsChanged, Info.Size, PByte(FBuffer));
  end else
    FIDSWriter.PutField(fldIsNull, 0, nil);
end;

procedure TDataPacketWriter.PutField(Info: PPutFieldInfo);
begin
  if Info.DataSet.GetFieldData(Info.FieldNo, FBuffer) then
    FIDSWriter.PutField(fldIsChanged, Info.Size, PByte(FBuffer)) else
    FIDSWriter.PutField(fldIsNull, 0, nil);
end;

procedure TDataPacketWriter.PutStringField(Info: PPutFieldInfo);
begin
  if Info.DataSet.GetFieldData(Info.FieldNo, FBuffer) then
  begin
    if TStringField(Info.Field).Transliterate then
      Info.Size := Info.DataSet.Translate(PChar(FBuffer), PChar(FBuffer), False) else
      Info.Size := StrLen(PChar(FBuffer));
    FIDSWriter.PutField(fldIsChanged, Info.Size, PByte(FBuffer));
  end else
    FIDSWriter.PutField(fldIsNull, 0, nil);
end;

procedure TDataPacketWriter.PutWideStringField(Info: PPutFieldInfo);
var
  W: WideString;
begin
  if Info.DataSet.GetFieldData(Info.field, @W, False) then
  begin
    Info.Size := Length(W);
    FIDSWriter.PutField(fldIsChanged, Info.Size * 2, PByte(W));
  end else
    FIDSWriter.PutField(fldIsNull, 0, nil);
end;

procedure TDataPacketWriter.PutVarBytesField(Info: PPutFieldInfo);
begin
  if Info.DataSet.GetFieldData(Info.FieldNo, FBuffer) then
    FIDSWriter.PutField(fldIsChanged, PWord(FBuffer)^, @FBuffer[SizeOf(Word)]) else
    FIDSWriter.PutField(fldIsNull, 0, nil);
end;

procedure TDataPacketWriter.PutADTField(Info: PPutFieldInfo);
var
  i: Integer;
begin
  if Info.Field.IsNull then
    FIDSWriter.PutField(fldIsNull, 0, nil) else
    FIDSWriter.PutField(fldIsChanged, 0, nil);
  for i := 0 to High(TInfoArray(Info.FieldInfos)) do
    with TInfoArray(Info^.FieldInfos)[i] do
      PutProc(@TInfoArray(Info.FieldInfos)[i]);
end;

procedure TDataPacketWriter.PutArrayField(Info: PPutFieldInfo);

  procedure RefreshInfos(Src: TField; Dest: PPutFieldInfo);
  var
    i: Integer;
  begin
    with Dest^ do
    begin
      Field := Src;
      FieldNo := Src.FieldNo;
      if (FieldInfos <> nil) then { Must be an ADT }
      begin
        if not (Src is TADTField) then
          raise EDSWriter.CreateFmt(SArrayElementError,[Src.ClassName]);
        with (Src as TADTField) do
          for i := 0 to FieldCount - 1 do
            RefreshInfos(Fields[i], @TInfoArray(FieldInfos)[i]);
      end;
    end;
  end;

var
  i: Integer;
begin
  if Info.Field.IsNull then
    FIDSWriter.PutField(fldIsNull, 0, nil) else
    FIDSWriter.PutField(fldIsChanged, 0, nil);
  for i := 0 to TArrayField(Info.Field).FieldCount - 1 do
    with TInfoArray(Info^.FieldInfos)[0] do
    begin
      RefreshInfos(TArrayField(Info.Field).Fields[i], @TInfoArray(Info.FieldInfos)[0]);
      PutProc(@TInfoArray(Info.FieldInfos)[0]);
    end;
end;

procedure TDataPacketWriter.PutDataSetField(Info: PPutFieldInfo);
var
  Count: DWord;
  DataSet: TDataSet;
begin
  if Info.Field <> nil then
  begin
    if Info.Field.IsNull then
    begin
      FIDSWriter.PutField(fldIsNull, 0, nil);
      Exit;
    end;
    DataSet := TDataSetField(Info.Field).NestedDataSet;
  end else
    DataSet := Info.DataSet;
  if (poFetchDetailsOnDemand in Options) then
    Count := dsDELAYEDBIT else
    Count := DWord(-1);
  FIDSWriter.PutField(fldIsChanged, SizeOf(Count), @Count);
  if (not (poFetchDetailsOnDemand in Options)) and (Count = DWord(-1)) then
  begin
    DataSet.UpdateCursorPos;
    DataSet.First;
    DataSet.BlockReadSize := MaxInt;
    try
      WriteDataSet(DataSet, TInfoArray(Info.FieldInfos), -1);
      FIDSWriter.EndOfNestedRows;
    finally
      DataSet.BlockReadSize := 0;
    end;
  end;
end;

function TDataPacketWriter.WriteDataSet(DataSet: TDataSet; var Info: TInfoArray;
  RecsOut: Integer): Integer;
const
  B: Byte = 0;
var
  i: Integer;
begin
  Result := 0;
  if RecsOut = AllRecords then
    RecsOut := High(Integer);
  if DataSet.DefaultFields then
    RefreshPutProcs(DataSet, Info);
  while (not DataSet.EOF) and (Result < RecsOut) do
  begin
    FIDSWriter.PutField(fldIsChanged, 1, @B);
    for i := 0 to High(Info) do
      Info[i].PutProc(@Info[i]);
    Inc(Result);
    if Result < RecsOut then
      DataSet.Next;
  end;
end;

{ Writing meta data }

procedure TDataPacketWriter.AddDataSetAttributes(DataSet: TDataSet);
var
  i: Integer;
  List: TList;
begin
  if Assigned(FOnGetParams) then
  begin
    List := TList.Create;
    try
      FOnGetParams(DataSet, List);
      for i := 0 to List.Count - 1 do
        with PPacketAttribute(List[i])^ do
        begin
          AddAttribute(pcktAttrArea, Name, Value, IncludeInDelta);
          Dispose(PPacketAttribute(List[i]));
        end;
    finally
      List.Free;
    end;
  end;
end;

function TDataPacketWriter.GetFieldIdx(const FieldName: string; const Info: TInfoArray): Integer;
var
  i: Integer;
begin
  Result := -1;
  for i := 0 to High(Info) do
    if (Info[i].Field <> nil) and (Info[i].Field.FieldName = FieldName) then
    begin
      Result := Info[i].LocalFieldIndex;
      break;
    end;
end;

type
  TPropWriter = class(TWriter);

procedure TDataPacketWriter.AddExtraFieldProps(Field: TField);

  procedure WriteProp(Instance: TPersistent; const PropName: string;
    Writer: TPropWriter);
  var
    PropInfo: PPropInfo;
  begin
    PropInfo := TypInfo.GetPropInfo(Instance.ClassInfo, PropName);
    if (PropInfo <> nil) and IsStoredProp(Instance, PropInfo) then
      Writer.WriteProperty(Instance, PropInfo);
  end;

var
  Writer: TPropWriter;
  Stream: TMemoryStream;
  i, Attr: Integer;
begin
  Stream := TMemoryStream.Create;
  try
    Writer := TPropWriter.Create(Stream, 1024);
    try
      Writer.WriteListBegin;
      for i := 0 to High(ExtraFieldProps) do
        WriteProp(Field, ExtraFieldProps[i], Writer);
      Writer.WriteListEnd;
      Writer.FlushBuffer;
      if Stream.Size > 2 then
      begin
        Attr := (dsfldBYTES shl dsSizeBitsLen) or dsArrayFldType or SizeOf(Byte);
        PInteger(FBuffer)^ := Stream.Size;
        Move(Stream.Memory^, FBuffer[SizeOf(Integer)], Stream.Size);
        Check(FIDSWriter.AddAttribute(fldAttrArea, szFIELDPROPS, Attr,
          Stream.Size + SizeOf(Integer), FBuffer));
      end;
    finally
      Writer.Free;
    end;
  finally
    Stream.Free;
  end;
end;

procedure TDataPacketWriter.AddColumn(const Info: TPutFieldInfo);

  procedure AddFieldDesc(const FldName: string; FldType, Attributes: Integer);
  var
    FldDesc: TDSDataPacketFldDesc;
  begin
    if Length(FldName) > SizeOf(FldDesc.szFieldName) then
      raise EDSWriter.CreateFmt(SFieldNameTooLong,[SizeOf(FldDesc.szFieldName) - 1]);
    FillChar(FldDesc, SizeOf(FldDesc), 0);
    StrCopy(FldDesc.szFieldName, PChar(FldName));
    FldDesc.iFieldType := FldType;
    FldDesc.iAttributes := Attributes;
    Check(FIDSWriter.AddColumnDesc(FldDesc));
  end;

  function ComputeInfoCount(Info: TInfoArray): Integer;
  var
    i: Integer;
  begin
    Result := Length(Info);
    for i := 0 to High(Info) do
      if Info[i].FieldInfos <> nil then
        Inc(Result, ComputeInfoCount(Info[i].FieldInfos));
  end;

  procedure AddMinMax(AField: TField);
  begin
    case AField.DataType of
      ftInteger, ftSmallInt:    
        if (TIntegerField(AField).MinValue <> 0) or 
           (TIntegerField(AField).MaxValue <> 0)  then
           begin
             AddAttribute(fldAttrArea, szMINVALUE, 
                           TIntegerField(AField).MinValue, False);
             AddAttribute(fldAttrArea, szMAXVALUE, 
                          TIntegerField(AField).MaxValue, False);
           end;
      ftCurrency, ftFloat:
        if (TFloatField(AField).MinValue <> 0 ) or 
           (TFloatField(AField).MaxValue <> 0 ) then
           begin
             AddAttribute(fldAttrArea, szMINVALUE, 
                           TFloatField(AField).MinValue, False);
             AddAttribute(fldAttrArea, szMAXVALUE, 
                          TFloatField(AField).MaxValue, False);
           end;
      ftBCD:
        if (TBCDField(AField).MinValue <> 0 ) or 
           (TIntegerField(AField).MaxValue <> 0 ) then
           begin
             AddAttribute(fldAttrArea, szMINVALUE, 
                           TBCDField(AField).MinValue, False);
             AddAttribute(fldAttrArea, szMAXVALUE, 
                          TBCDField(AField).MaxValue, False);
           end;
    end;
  end;

var
  FldType, Prec, Attr, i, Width: Integer;
  TempStr: string;
begin
  if Info.IsDetail and (Info.Field = nil) then
  begin
    FldType := (dsfldEMBEDDEDTBL shl dsSizeBitsLen) or
      ComputeInfoCount(Info.FieldInfos) or dsPseudoFldType;
    AddFieldDesc(Info.DataSet.Name, FldType, 0);
    WriteMetaData(Info.DataSet, TInfoArray(Info.FieldInfos));
  end else
  begin
    Width := 0;
    Attr := 0;
    if Info.Field.ReadOnly or (Info.Field.FieldKind <> fkData) then Attr := Attr or fldAttrREADONLY;
    if Info.Field.Required and (Info.Field.DataType <> ftAutoInc) then Attr := Attr or fldAttrREQUIRED;
    if (pfHidden in Info.Field.ProviderFlags) then Attr := Attr or fldAttrHIDDEN or fldAttrREADONLY;
    FldType := PacketTypeMap[Info.Field.DataType];
    case Info.Field.DataType of
      ftString, ftFixedChar, ftVarBytes, ftGUID, ftWideString:
      begin
        FldType := FldType shl dsSizeBitsLen or dsVaryingFldType;
        if Info.Size < 255 then
          FldType := FldType or SizeOf(Byte) else
          FldType := FldType or SizeOf(Word);
        Width := Info.Size;
      end;
      ftBCD:
      begin
        if TBCDField(Info.Field).Precision = 0 then
          Width := 32 else
          Width := TBCDField(Info.Field).Precision;
        Prec := Width shr 1;
        Inc(Prec, Prec and 1);  { Make an even number }
        FldType := (FldType shl dsSizeBitsLen) or (Prec + 2);
      end;
      ftArray:
        FldType := (FldType shl dsSizeBitsLen) or dsPseudoFldType or
          dsCompArrayFldType or TObjectField(Info.Field).Size;
      ftADT:
        FldType := (FldType shl dsSizeBitsLen) or dsPseudoFldType or
          TObjectField(Info.Field).FieldCount;
      ftDataSet, ftReference:
        FldType := (FldType shl dsSizeBitsLen) or dsPseudoFldType or
          dsEmbeddedFldType or ComputeInfoCount(TInfoArray(Info.FieldInfos));
    else
      if Info.Field.IsBlob then
      begin
        FldType := (FldType shl dsSizeBitsLen) or dsVaryingFldType or SizeOf(Integer);
        Width := Info.Field.Size;
      end else
        FldType := (FldType shl dsSizeBitsLen) or Info.Size;
    end;
    AddFieldDesc(Info.Field.FieldName, FldType, Attr);
    if (Info.Field.FieldKind <> fkData) then
      AddAttribute(fldAttrArea, szSERVERCALC, True, True);
    if Info.Field.ProviderFlags <> [pfInWhere, pfInUpdate] then
      AddAttribute(fldAttrArea, szPROVFLAGS, Byte(Info.Field.ProviderFlags), True);
    if Info.Field.Origin <> '' then
      AddAttribute(fldAttrArea, szORIGIN, Info.Field.Origin, True);
    if Width > 0 then
      AddAttribute(fldAttrArea, szWIDTH, Width, False);
    if (Info.Field is TBCDField) and (TBCDField(Info.Field).Size <> 0) then
      AddAttribute(fldAttrArea, szDECIMALS, TBCDField(Info.Field).Size, False);
    AddMinMax(Info.Field);
    case Info.Field.DataType of
      ftCurrency: TempStr := szstMONEY;
      ftAutoInc: TempStr := szstAUTOINC;
      ftVarBytes, ftBlob: TempStr := szstBINARY;
      ftMemo: TempStr := szstMEMO;
      ftFmtMemo: TempStr := szstFMTMEMO;
      ftParadoxOle: TempStr := szstOLEOBJ;
      ftGraphic: TempStr := szstGRAPHIC;
      ftDBaseOle: TempStr := szstDBSOLEOBJ;
      ftTypedBinary: TempStr := szstTYPEDBINARY;
      ftADT:
        if (Info.Field.ParentField <> nil) and
           (Info.Field.ParentField.DataType in [ftDataSet, ftReference]) then
          TempStr := szstADTNESTEDTABLE;
      ftReference: TempStr := szstREFNESTEDTABLE;
      ftString:
        if TStringField(Info.Field).FixedChar then
          TempStr := szstFIXEDCHAR else
          TempStr := '';
      ftGUID: TempStr := szstGUID;
      ftOraClob: TempStr := szstHMEMO;
      ftOraBlob: TempStr := szstHBINARY;
    else
        TempStr := '';
    end;
    if TempStr <> '' then
      AddAttribute(fldAttrArea, szSUBTYPE, TempStr, False);
    if Info.Field is TObjectField then
      AddAttribute(fldAttrArea, szTYPENAME, TObjectField(Info.Field).ObjectType, False);
    if poIncFieldProps in Options then
      AddExtraFieldProps(Info.Field);
    case Info.Field.DataType of
      ftADT, ftArray: { Array will only have 1 child field }
        for i := 0 to High(TInfoArray(Info.FieldInfos)) do
          AddColumn(TInfoArray(Info.FieldInfos)[i]);
      ftDataSet, ftReference:
        with TDataSetField(Info.Field) do
          WriteMetaData(NestedDataSet, TInfoArray(Info.FieldInfos),
            Info.Field.DataType = ftReference);
    end;
  end;
end;

procedure TDataPacketWriter.AddConstraints(DataSet: TDataSet);
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
    TypeStr: array[TConstraintType] of PChar = (szBDEDOMX, szBDERECX, szBDEDEFX);
    Attr: Integer = dsVaryingFldType or SizeOf(Integer) or (dsfldBYTES shl dsSizeBitsLen);
  var
    ErrorStr: string;
    AttrType: PChar;
    Len, AttrSize: Integer;
    SQLExprInfo: PSQLExprInfo;
    Options: TParserOptions;
  begin
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
    SQLExprInfo := @FBuffer[SizeOf(Integer)];
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
      Move(FilterData[0], FBuffer[SizeOf(TSQLExprInfo) + Len + SizeOf(Integer)], DataSize);
      AttrSize := DataSize + SizeOf(TSQLExprInfo) + Len;
    end;
    PInteger(FBuffer)^ := AttrSize;
    if Len > 0 then
      StrCopy(@FBuffer[SizeOf(TSQLExprInfo) + SizeOf(Integer)], PChar(ErrorStr));
    AttrType := TypeStr[ConstraintType];
    Check(FIDSWriter.AddAttribute(pcktAttrArea, AttrType, Attr, AttrSize + SizeOf(Integer), PByte(FBuffer)));
  end;

var
  i: Integer;
  ExprParser: TExprParser;
  Constraints: TCheckConstraints;
  Obj: TObject;
  ErrMsg: string;
begin
  ExprParser := TExprParser.Create(DataSet, '', [], [], '', nil, FieldTypeMap);
  try
    Obj := GetObjectProperty(DataSet, 'Constraints'); { Do not localize }
    if (Obj <> nil) and (Obj is TCheckConstraints) then
    begin
      Constraints := Obj as TCheckConstraints;
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
          if DataSet.Name <> '' then
            ErrMsg := Format('%s: %s',[DataSet.Name, SRecConstFail]) else
            ErrMsg := SRecConstFail;
          raise EDSWriter.CreateFmt(ErrMsg, [E.Message]);
        end;
      end;
    end;
    for i := 0 to DataSet.FieldList.Count - 1 do
      with DataSet.FieldList[i] do
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
              ErrMsg := Format('%s.%s: %s',[DataSet.Name, FullName, SDefExprFail]) else
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
            if DataSet.Name <> '' then
              ErrMsg := Format('%s.%s: %s',[DataSet.Name, FullName, SFieldConstFail]) else
              ErrMsg := Format('%s: %s',[FullName, SFieldConstFail]);
            raise EDSWriter.CreateFmt(ErrMsg, [E.Message]);
          end;
        end;
      end;
  finally
    ExprParser.Free;
  end;
end;

procedure TDataPacketWriter.AddIndexDefs(DataSet: TDataSet; const Info: TInfoArray);
var
  FieldList, CaseList, DescList: TList;

  function GetKeyData(Index: TIndexDef): OleVariant;
  var
    i: Integer;
    x: SmallInt;
  begin
    with Index do
    begin
      FieldList.Clear;
      CaseList.Clear;
      DescList.Clear;
      DataSet.GetFieldList(FieldList, Fields);
      DataSet.GetFieldList(CaseList, CaseInsFields);
      DataSet.GetFieldList(DescList, DescFields);
      Result := VarArrayCreate([0, FieldList.Count - 1], varSmallInt);
      for i := 0 to FieldList.Count - 1 do
      begin
        x := GetFieldIdx(TField(FieldList[i]).FieldName, Info);
        if (CaseList.IndexOf(FieldList[i]) <> -1) or
           ((i = 0) and (FieldList.Count = 1) and (ixCaseInSensitive in Options)) then
          x := x or dskeyCASEINSENSITIVE;
        if (DescList.IndexOf(FieldList[i]) <> -1) or
           ((i = 0) and (FieldList.Count = 1) and (ixDescending in Options)) then
          x := x or SmallInt(dskeyDESCENDING);
        Result[i] := x;
      end;
    end;
  end;

var
  i: Integer;
  DefIdx, KeyIndex: TIndexDef;
  IndexDefs: TIndexDefs;
  KeyList: OleVariant;
  KeyFields: string;
begin
  FieldList := TList.Create;
  try
    CaseList := TList.Create;
    try
      DescList := TList.Create;
      try
        { Get the DEFAULT_ORDER }
        DefIdx := IProviderSupport(DataSet).PSGetDefaultOrder;
        if Assigned(DefIdx) then
        try
          KeyList := GetKeyData(DefIdx);
          AddAttribute(pcktAttrArea, szDEFAULT_ORDER, KeyList, False);
        finally
          DefIdx.Free;
        end;
        KeyFields := IProviderSupport(DataSet).PSGetKeyFields;
        IndexDefs := IProviderSupport(DataSet).PSGetIndexDefs([ixUnique]);
        try
          if KeyFields <> '' then
          begin
            { PRIMARY_KEY is used to define the keyfields }
            KeyList := NULL;
            if Assigned(IndexDefs) then
            begin
              KeyIndex := IndexDefs.GetIndexForFields(KeyFields, False);
              if Assigned(KeyIndex) then
              begin
                KeyList := GetKeyData(KeyIndex);
                KeyIndex.Free;{ KeyIndex is already used, remove it from the list }
              end;
            end;
            if VarIsNull(KeyList) then
            begin
              DataSet.GetFieldList(FieldList, KeyFields);
              KeyList := VarArrayCreate([0, FieldList.Count - 1], varSmallInt);
              for i := 0 to FieldList.Count - 1 do
                KeyList[i] := GetFieldIdx(TField(FieldList[i]).FieldName, Info);
            end;
            if not VarIsNull(KeyList) then
              AddAttribute(pcktAttrArea, szPRIMARY_KEY, KeyList, False);
          end;
          if Assigned(IndexDefs) then
            for i := 0 to IndexDefs.Count - 1 do
              with IndexDefs[i] do
              begin
                KeyList := GetKeyData(IndexDefs[i]);
                AddAttribute(pcktAttrArea, szUNIQUE_KEY, KeyList, False);
              end;
        finally
          IndexDefs.Free;
        end;
      finally
        DescList.Free;
      end;
    finally
      CaseList.Free;
    end;
  finally
    FieldList.Free;
  end;
end;

procedure TDataPacketWriter.AddFieldLinks(const Info: TInfoArray);
var
  MasterFields, DetailFields: TList;
  i, j: Integer;
  LinkFields: Variant;
begin
  MasterFields := TList.Create;
  try
    DetailFields := TList.Create;
    try
      for i := 0 to High(Info) do
        if Info[i].IsDetail and (Info[i].Field = nil) then
        begin
          Info[i].DataSet.GetDetailLinkFields(MasterFields, DetailFields);
          if (MasterFields.Count > 0) and (MasterFields.Count <= DetailFields.Count) then
          begin
            LinkFields := VarArrayCreate([0, MasterFields.Count * 2], varSmallInt);
            LinkFields[0] := Info[i].LocalFieldIndex;
            for j := 0 to MasterFields.Count - 1 do
              LinkFields[j + 1] := GetFieldIdx(TField(MasterFields[j]).FieldName,
                Info);
            for j := 0 to MasterFields.Count - 1 do
              LinkFields[j + MasterFields.Count + 1] :=
                GetFieldIdx(TField(DetailFields[j]).FieldName, TInfoArray(Info[i].FieldInfos));
            AddAttribute(pcktAttrArea, szMD_FIELDLINKS, LinkFields, False);
          end;
        end;
    finally
      DetailFields.Free;
    end;
  finally
    MasterFields.Free;
  end;
end;

procedure TDataPacketWriter.WriteMetaData(DataSet: TDataSet; const Info: TInfoArray;
  IsReference: Boolean);
var
  i, MDOptions: Integer;
begin
  for i := 0 to High(Info) do
    AddColumn(Info[i]);
  if (poReadOnly in Options) or IsReference then
    AddAttribute(pcktAttrArea, szREADONLY, True, False);
  if (poDisableEdits in Options) then
    AddAttribute(pcktAttrArea, szDISABLE_EDITS, True, False);
  if (poDisableInserts in Options) then
    AddAttribute(pcktAttrArea, szDISABLE_INSERTS, True, False);
  if (poDisableDeletes in Options) then
    AddAttribute(pcktAttrArea, szDISABLE_DELETES, True, False);
  if (poNoReset in Options) then
    AddAttribute(pcktAttrArea, szNO_RESET_CALL, True, False);
  if Constraints then
    AddConstraints(DataSet);
  AddIndexDefs(DataSet, Info);
  AddFieldLinks(Info);
  MDOptions := 0;
  if poCascadeDeletes in Options then MDOptions := dsCASCADEDELETES;
  if poCascadeUpdates in Options then MDOptions := MDOptions or dsCASCADEUPDATES;
  if MDOptions <> 0 then
    AddAttribute(pcktAttrArea, szMD_SEMANTICS, MDOptions, True);
  AddDataSetAttributes(DataSet);
  if Info <> FPutFieldInfo then
    Check(FIDSWriter.AddAttribute(pcktAttrArea, nil, 0, 0, nil));
end;

procedure TDataPacketWriter.RefreshPutProcs(ADataSet: TDataSet; var Info: TInfoArray);

  procedure RefreshInfo(ADataSet: TDataSet; AField: TField; var Info: TPutFieldInfo);
  var
    j: Integer;
  begin
    Info.Field := AField;
    if AField = nil then
      Info.DataSet := ADataSet
    else
    begin
      Info.DataSet := AField.DataSet;
      if AField.DataType = ftADT then
      begin
        with TADTField(AField) do
        for j := 0 to FieldCount - 1 do
          RefreshInfo(ADataSet, Fields[j], TInfoArray(Info.FieldInfos)[j]);
      end;
    end;
  end;

var
  i: Integer;
  List: TList;
begin
  List := TList.Create;
  try
    ADataSet.GetDetailDataSets(List);
    for i := 0 to ADataSet.FieldCount - 1 do
      RefreshInfo(ADataSet, ADataSet.Fields[i], Info[i]);
    for i := 0 to List.Count - 1 do
      RefreshInfo(TDataSet(List[i]), nil, Info[ADataSet.FieldCount + i]);
  finally
    List.Free;
  end;
end;

function TDataPacketWriter.InitPutProcs(ADataSet: TDataSet;
  var GlobalIdx: Integer): TInfoArray;

  procedure InitInfoStruct(var Info: TPutFieldInfo; AField: TField;
    var GlobalIdx, LocalIdx: Integer);
  begin
    FillChar(Info, SizeOf(Info), 0);
    with Info do
    begin
      IsDetail := AField = nil;
      Field := AField;
      Inc(GlobalIdx);
      LocalFieldIndex := LocalIdx;
      Inc(LocalIdx);
      if Field <> nil then
      begin
        FieldNo := Field.FieldNo;
        Size := Field.DataSize;
        DataSet := Field.DataSet;
      end;
    end;
  end;

  procedure InitFieldProc(ADataSet: TDataSet; AField: TField;
    var Info: TPutFieldInfo; var GlobalIdx, LocalIdx: Integer);
  var
    i: Integer;
    NestedIdx: Integer;
  begin
    with Info do
    begin
      InitInfoStruct(Info, AField, GlobalIdx, LocalIdx);
      if AField = nil then { Linked dataset }
      begin
        Opened := not ADataSet.Active;
        if Opened then ADataSet.Open;
        DataSet := ADataSet;
        PutProc := PutDataSetField;
        TInfoArray(FieldInfos) := InitPutProcs(DataSet, GlobalIdx);
      end else
      begin
        case Field.DataType of
          ftString, ftFixedChar, ftGUID:
          begin
            PutProc := PutStringField;
            Dec(Size);  { Don't count the null terminator }
          end;
          ftWideString:
          begin
            PutProc := PutWideStringField;
            Size := AField.Size * 2;
          end;
          ftVarBytes:
          begin
            PutProc := PutVarBytesField;
            Dec(Size, 2); { Don't write size bytes }
          end;
          ftADT:
          with TADTField(Field) do
          begin
            PutProc := PutADTField;
            SetLength(TInfoArray(FieldInfos), FieldCount);
            for i := 0 to FieldCount - 1 do
              InitFieldProc(ADataSet, Fields[i], TInfoArray(FieldInfos)[i],
                GlobalIdx, LocalIdx);
          end;
          ftArray:
          with TArrayField(Field) do
          begin
            PutProc := PutArrayField;
            SetLength(TInfoArray(FieldInfos), 1);
            NestedIdx := LocalIdx;
            InitFieldProc(ADataSet, Fields[0], TInfoArray(FieldInfos)[0],
                GlobalIdx, LocalIdx);
            LocalIdx := (LocalIdx - NestedIdx) * (FieldCount - 1) + LocalIdx;
          end;
          ftDataSet, ftReference:
          with TDataSetField(Field).NestedDataSet do
          begin
            PutProc := PutDataSetField;
            NestedIdx := 1;
            SetLength(TInfoArray(FieldInfos), FieldCount);
            for i := 0 to FieldCount - 1 do
              InitFieldProc(TDataSetField(Field).NestedDataSet, Fields[i],
                TInfoArray(FieldInfos)[i], GlobalIdx, NestedIdx);
          end;
          ftSmallint, ftInteger, ftWord, ftBoolean, ftFloat, ftCurrency, ftBCD,
          ftDate, ftTime, ftDateTime, ftAutoInc, ftLargeint, ftBytes:
            PutProc := PutField;
          ftBlob, ftMemo, ftGraphic, ftFmtMemo, ftParadoxOle, ftDBaseOle, ftTypedBinary, ftOraBlob, ftOraClob:
            PutProc := PutBlobField;
        else
          DatabaseErrorFmt(SUnknownFieldType, [Field.FieldName]);
        end;
        if Field.FieldKind <> fkData then
          PutProc := PutCalcField;
      end;
    end;
  end;

var
  i, LocalIdx: Integer;
  List: TList;
begin
  LocalIdx := 1;
  List := TList.Create;
  try
    ADataSet.GetDetailDataSets(List);
    SetLength(Result, ADataSet.FieldCount + List.Count);
    for i := 0 to ADataSet.FieldCount - 1 do
      InitFieldProc(ADataSet, ADataSet.Fields[i], Result[i], GlobalIdx, LocalIdx);
    for i := 0 to List.Count - 1 do
      InitFieldProc(TDataSet(List[i]), nil, Result[ADataSet.FieldCount + i],
        GlobalIdx, LocalIdx);
  finally
    List.Free;
  end;
end;

procedure TDataPacketWriter.GetDataPacket(DataSet: TDataSet;
  var RecsOut: Integer; out Data: OleVariant);

  procedure CheckMetaData(DataSet: TDataSet);
  var
    Idx: Integer;
    TempPacket: TDataPacket;
    Version: Integer;
  begin
    Idx := 1;
    if (FPutFieldInfo = nil) or (grMetaData in PacketOptions) then
    begin
      CreateDBClientObject(CLSID_DSWriter, IDSWriter, FIDSWriter);
      if FPutFieldInfo <> nil then
      begin
        FreeInfoRecords(FPutFieldInfo);
        FPutFieldInfo := nil;
      end;
      FPutFieldInfo := InitPutProcs(DataSet, Idx);
      if poFetchBlobsOnDemand in Options then
        Version := PACKETVERSION_2 else
        Version := PACKETVERSION_1;
      if grXML in PacketOptions then
        FIDSWriter.SetXMLMode(xmlON) else
        FIDSWriter.SetXMLMode(0);
      Check(FIDSWriter.Init_Sequential(Version, Idx - 1));
      WriteMetaData(DataSet, FPutFieldInfo);
      if not (grMetaData in PacketOptions) then
      begin
        FIDSWriter.GetDataPacket(TempPacket);
        SafeArrayDestroy(TempPacket);
        TempPacket := nil;
      end;
    end;
    if not (grMetaData in PacketOptions) then
      Check(FIDSWriter.Reset);
  end;

var
  DataPacket: TDataPacket;
begin
    CheckMetaData(DataSet);
    RecsOut := WriteDataSet(DataSet, FPutFieldInfo, RecsOut);
    FIDSWriter.GetDataPacket(DataPacket);
    DataPacketToVariant(DataPacket, Data);
end;

{ TPacketDataSet }

constructor TPacketDataSet.Create(AOwner: TComponent);
begin
  inherited;
  FetchOnDemand := False;
end;

procedure TPacketDataSet.CreateFromDelta(Source: TPacketDataSet);
var
  TempBase: IDSBase;
begin
  Source.Check(Source.DSBase.Clone(2, True, False, TempBase));
  DSBase := TempBase;
  Open;
end;

procedure TPacketDataSet.InternalInitRecord(Buffer: PChar);
var
  I: Integer;
begin
  inherited InternalInitRecord(Buffer);
  { Initialize new records in the error result dataset to unchanged values }
  for I := 1 to FieldCount do
    DSBase.PutBlank(PByte(Buffer), 0, I, BLANK_NOTCHANGED);
end;

procedure TPacketDataSet.InternalOpen;
var
  MDSem: DWord;
begin
  inherited InternalOpen;
  FOldRecBuf := AllocRecordBuffer;
  FCurRecBuf := AllocRecordBuffer;
  DSBase.GetProp(dspropMD_SEMANTICS, @MDSem);
  MDSem := MDSem and mdCASCADEMOD;
  DSBase.SetProp(dspropMD_SEMANTICS, MDSem);
end;

procedure TPacketDataSet.InternalClose;
begin
  inherited InternalClose;
  FreeRecordBuffer(FOldRecBuf);
  FreeRecordBuffer(FCurRecBuf);
end;

function TPacketDataSet.GetStateFieldValue(State: TDataSetState; Field: TField): Variant;
begin
  { When reading an OldValue, return the CurValue instead if we have one }
  if FUseCurValues and (State = dsOldValue) and HasCurValues then
  begin
    Result := inherited GetStateFieldValue(dsCurValue, Field);
    if not VarIsEmpty(Result) then Exit;
  end;
  Result := inherited GetStateFieldValue(State, Field);
end;

function TPacketDataSet.GetStreamMetaData: Boolean;
var
  Value: Integer;
begin
  DSBase.GetProp(DSProp(dspropDONTINCLMETADATA), @Value);
  Result := Value <> 0;
end;

procedure TPacketDataSet.SetStreamMetaData(Value: Boolean);
begin
  DSBase.SetProp(DSProp(dspropDONTINCLMETADATA), Integer(not Value));
end;

function TPacketDataSet.UpdateKind: TUpdateKind;
begin
  case UpdateStatus of
    usInserted: Result := ukInsert;
    usDeleted: Result := ukDelete;
  else
    Result := ukModify;
  end;
end;

procedure TPacketDataSet.DataEvent(Event: TDataEvent; Info: Integer);
begin
  if Event in [deDataSetScroll, deDataSetChange] then
  begin
    FNewValuesModified := False;
    FCurValues := nil;
  end;
  inherited DataEvent(Event, Info);
end;

function TPacketDataSet.HasCurValues: Boolean;
begin
  Result := FCurValues <> nil;
end;

procedure TPacketDataSet.InitAltRecBuffers(CheckModified: Boolean);
var
  No: Integer;
begin
  if UpdateStatus in [usUnmodified, usDeleted] then
    GetCurrentRecord(FOldRecBuf);
  if CheckModified and (UpdateStatus = usUnmodified) then
  begin
    No := RecNo;
    Next;
    if UpdateStatus <> usModified then
      RecNo := No;
  end;
  if UpdateStatus = usInserted then
    SetAltRecBuffers(ActiveBuffer, ActiveBuffer, FCurRecBuf) else
    SetAltRecBuffers(FOldRecBuf, ActiveBuffer, FCurRecBuf);
end;

procedure TPacketDataSet.SetFieldData(Field: TField; Buffer: Pointer);
begin
  { Set a flag when any of the field's NewValue properties are modified }
  if State = dsNewValue then
    FNewValuesModified := True;
  if FWritingCurValues then
    Check(DSCursor.PutField(FCurRecBuf, Field.FieldNo, Buffer)) else
    inherited SetFieldData(Field, Buffer);
end;

procedure TPacketDataSet.SetWritingCurValues(const Value: Boolean);
begin
  if Value then
  begin
    FCurValues := FCurRecBuf;
    InitRecord(FCurValues);
  end else
    InitAltRecBuffers;
  FWritingCurValues := Value;
end;

procedure TPacketDataSet.AssignCurValues(Source: TDataSet);
var
  I: Integer;
  NewValue: Variant;
  Field, SourceField: TField;
begin
  WritingCurValues := True;
  try
    for i := 0 to FieldCount - 1 do
    begin
      Field := Fields[i];
      SourceField := Source.FindField(Field.FieldName);
      if (SourceField <> nil) and not Field.IsBlob and
         not (Field.DataType in [ftBytes, ftVarBytes]) and
         (Field.OldValue <> SourceField.Value) then
      begin
        NewValue := Field.NewValue;
        if VarIsEmpty(Field.NewValue) or
           (NewValue <> SourceField.Value) then
          Field.Assign(SourceField);
      end;
    end;
  finally
    WritingCurValues := False;
  end;
end;

procedure TPacketDataSet.AssignCurValues(const CurValues: Variant);
var
  I: Integer;
  Field: TField;
  CurValue: Variant;
begin
  WritingCurValues := True;
  try
    if VarIsNull(CurValues) then
      FCurValues := nil
    else
      for I := VarArrayLowBound(CurValues, 1) to VarArrayHighBound(CurValues, 1) do
      begin
        if VarIsArray(CurValues[I]) then
        begin
          CurValue := CurValues[I][1];
          Field := FieldByName(CurValues[I][0])
        end else
        begin
          CurValue := CurValues[I];
          Field := Fields[I];
        end;
        if not VarIsEmpty(CurValue) then
          if (Field.OldValue <> CurValue) then
            Fields[I].Value := CurValue;
      end;
  finally
    WritingCurValues := False;
  end;
end;

function TPacketDataSet.HasMergeConflicts: Boolean;
var
  I: Integer;
  CurVal, NewVal: Variant;
begin
  Result := False;
  for I := 0 to FieldCount - 1 do
    with Fields[I] do
    begin
      CurVal := CurValue;
      if VarIsEmpty(CurVal) then Continue;
      NewVal := NewValue;
      if VarIsEmpty(NewVal) then Continue;
      if CurVal = NewVal then Continue;
      Result := True;
      Break;
    end;
end;

{ TCustomProvider }

constructor TCustomProvider.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FExported := True;
  if AOwner is TRemoteDataModule then
    TRemoteDataModule(AOwner).RegisterProvider(Self)
  else if AOwner is TCRemoteDataModule then
    TCRemoteDataModule(AOwner).RegisterProvider(Self);
end;

destructor TCustomProvider.Destroy;
begin
  if Owner is TRemoteDataModule then
    TRemoteDataModule(Owner).UnRegisterProvider(Self)
  else if Owner is TCRemoteDataModule then
    TCRemoteDataModule(Owner).UnRegisterProvider(Self);
  inherited Destroy;
end;

function TCustomProvider.GetData: OleVariant;
var
  Recs: Integer;
  Options: TGetRecordOptions;
begin
  Options := [grMetaData];
  Result := GetRecords(-1, Recs, Byte(Options));
end;

function TCustomProvider.ApplyUpdates(Const Delta: OleVariant; MaxErrors: Integer;
  out ErrorCount: Integer): OleVariant;
var
  OwnerData: OleVariant;
begin
  Result := ApplyUpdates(Delta, MaxErrors, ErrorCount, OwnerData);
end;

function TCustomProvider.ApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
  out ErrorCount: Integer; var OwnerData: OleVariant): OleVariant;
begin
  if Assigned(FBeforeApplyUpdates) then FBeforeApplyUpdates(Self, OwnerData);
  Result := InternalApplyUpdates(Delta, MaxErrors, ErrorCount);
  if Assigned(FAfterApplyUpdates) then FAfterApplyUpdates(Self, OwnerData);
end;

procedure TCustomProvider.DoBeforeGetRecords(Count: Integer; Options: Integer;
  const CommandText: WideString; var Params, OwnerData: OleVariant);
begin
  if Assigned(FBeforeGetRecords) then FBeforeGetRecords(Self, OwnerData);
end;

function TCustomProvider.GetRecords(Count: Integer; out RecsOut: Integer; Options: Integer): OleVariant;
var
  Params, OwnerData: OleVariant;
begin
  Result := GetRecords(Count, RecsOut, Options, '', Params, OwnerData);
end;

function TCustomProvider.GetRecords(Count: Integer; out RecsOut: Integer; Options: Integer;
  const CommandText: WideString; var Params, OwnerData: OleVariant): OleVariant;
begin
  DoBeforeGetRecords(Count, Options, CommandText, Params, OwnerData);
  Result := InternalGetRecords(Count, RecsOut, TGetRecordOptions(Byte(Options)),
    CommandText, Params);
  if Assigned(FAfterGetRecords) then FAfterGetRecords(Self, OwnerData);
  Params := InternalGetParams([ptOutput, ptInputOutput]);
end;

function TCustomProvider.RowRequest(const Row: OleVariant; RequestType: Integer;
  var OwnerData: OleVariant): OleVariant;
begin
  if Assigned(FBeforeRowRequest) then FBeforeRowRequest(Self, OwnerData);
  Result := InternalRowRequest(Row, TFetchOptions(Byte(RequestType)));
  if Assigned(FAfterRowRequest) then FAfterRowRequest(Self, OwnerData);
end;

procedure TCustomProvider.DoBeforeExecute(const CommandText: WideString;
  var Params, OwnerData: OleVariant);
begin
  if Assigned(FBeforeExecute) then FBeforeExecute(Self, OwnerData);
end;

procedure TCustomProvider.Execute(const CommandText: WideString;
  var Params, OwnerData: OleVariant);
begin
  DoBeforeExecute(CommandText, Params, OwnerData);
  InternalExecute(CommandText, Params);
  if Assigned(FAfterExecute) then FAfterExecute(Self, OwnerData);
  Params := InternalGetParams([ptOutput, ptInputOutput]);
end;

function TCustomProvider.GetParams(var OwnerData: OleVariant): OleVariant;
begin
  if Assigned(FBeforeGetParams) then FBeforeGetParams(Self, OwnerData);
  Result := InternalGetParams;
  if Assigned(FAfterGetParams) then FAfterGetParams(Self, OwnerData);
end;

function TCustomProvider.InternalGetParams(Types: TParamTypes = AllParamTypes): OleVariant;
begin
  Result := NULL;
end;

procedure TCustomProvider.InternalExecute(const CommandText: WideString; var Params: OleVariant);
begin
end;

function TCustomProvider.InternalGetRecords(Count: Integer; out RecsOut: Integer;
  Options: TGetRecordOptions; const CommandText: WideString;
  var Params: OleVariant): OleVariant;
begin
  Result := NULL;
end;

function TCustomProvider.InternalRowRequest(const Row: OleVariant; RequestType: TFetchOptions): OleVariant;
begin
  Result := NULL;
end;

function TCustomProvider.DataRequest(Input: OleVariant): OleVariant;
begin
  if Assigned(FOnDataRequest) then
    Result := FOnDataRequest(Self, Input) else
    Result := NULL;
end;

{ TBaseProvider }

constructor TBaseProvider.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FProviderOptions := [];
end;

destructor TBaseProvider.Destroy;
begin
  FResolver.Free;
  inherited Destroy;
end;

procedure TBaseProvider.LocateRecord(Source, Delta: TDataSet);
begin
end;

procedure TBaseProvider.UpdateRecord(Source, Delta: TDataSet; BlobsOnly, KeyOnly: Boolean);
begin
end;

procedure TBaseProvider.FetchDetails(Source, Delta: TDataSet);
begin
end;

procedure TBaseProvider.CheckResolver;
begin
  if not Assigned(FResolver) then
    FResolver := CreateResolver;
end;

procedure TBaseProvider.FreeResolver;
begin
  FResolver.Free;
  FResolver := nil;
end;

function TBaseProvider.InternalApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
  out ErrorCount: Integer): OleVariant;
begin
  if poReadOnly in Options then DatabaseError(SReadOnlyProvider);
  CheckResolver;
  Result := Resolver.ApplyUpdates(Delta, MaxErrors, ErrorCount);
end;

function TBaseProvider.InternalRowRequest(const Row: OleVariant; RequestType: TFetchOptions): OleVariant;
begin
  CheckResolver;
  Result := Resolver.RowRequest(Row, RequestType);
end;

function TBaseProvider.InternalGetRecords(Count: Integer; out RecsOut: Integer;
  Options: TGetRecordOptions; const CommandText: WideString;
  var Params: OleVariant): OleVariant;
begin
  if (Count = 0) then
    Include(Options, grMetaData);
  RecsOut := Count;
  CreateDataPacket(Options, Self.Options, RecsOut, Result);
  DoOnGetData(Result);
end;

procedure TBaseProvider.DoOnGetData(var Data: OleVariant);
begin
  if Assigned(OnGetData) then
  begin
    if not Assigned(FDataDS) then
      FDataDS := TPacketDataSet.Create(Self) else
      FDataDS.StreamMetaData := False;
    FDataDS.AppendData(Data, False);
    OnGetData(Self, FDataDS);
    if FDataDS.ChangeCount > 0 then
    begin
      FDataDS.MergeChangeLog;
      Data := FDataDS.Data;
    end;
    FDataDS.EmptyDataSet;
  end;
end;

procedure TBaseProvider.DoOnUpdateData(Delta: TPacketDataSet);
begin
  if Assigned(FOnUpdateData) then
  begin
    Delta.LogChanges := False;
    FOnUpdateData(Self, Delta);
  end;
end;

function TBaseProvider.CreateResolver: TCustomResolver;
begin
  Result := nil;
end;

procedure TBaseProvider.CreateDataPacket(PacketOpts: TGetRecordOptions;
  ProvOpts: TProviderOptions; var RecsOut: Integer; var Data: OleVariant);
begin
  RecsOut := 0;
  Data := NULL;
end;

{ TDataSetProvider }

constructor TDataSetProvider.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FResolveToDataSet := False;
  FUpdateMode := upWhereAll;
  FDSWriter := nil;
  FConstraints := True;
  FRecordsSent := 0;
end;

destructor TDataSetProvider.Destroy;
begin
  FDSWriter.Free;
  if Assigned(FParams) then
    FParams.Free;
  inherited Destroy;
end;

procedure TDataSetProvider.LocateRecord(Source, Delta: TDataSet);
begin
  if not FindRecord(Source, Delta, UpdateMode) then
    DatabaseError(SRecordChanged);
end;

function TDataSetProvider.FindRecord(Source, Delta: TDataSet;
  UpdateMode: TUpdateMode): Boolean;

  procedure GetFieldList(DataSet: TDataSet; UpdateMode: TUpdateMode; List: TList);
  var
    i: Integer;
  begin
    for i := 0 to DataSet.FieldCount - 1 do
      with DataSet.Fields[i] do
      begin
        if (DataType in [ftBytes, ftVarBytes]) or IsBlob or
           (DataSet.Fields[i] is TObjectField) then continue;
        case UpdateMode of
          upWhereKeyOnly:
            if pfInKey in ProviderFlags then List.Add(DataSet.Fields[i]);
          upWhereAll:
            if pfInWhere in ProviderFlags then List.Add(DataSet.Fields[i]);
          upWhereChanged:
            if (pfInKey in ProviderFlags) or (not VarIsEmpty(NewValue)) then
              List.Add(DataSet.Fields[i]);
        end;
      end;
  end;

var
  i: Integer;
  KeyValues: Variant;
  Fields: string;
  FieldList: TList;
  IsDelta: BOOL;
begin
  Result := False;
  TPacketDataSet(Delta).DSBase.GetProp(dspropISDELTA, @IsDelta);
  FieldList := TList.Create;
  try
    GetFieldList(Delta, UpdateMode, FieldList);
    if FieldList.Count > 1 then
    begin
      KeyValues := VarArrayCreate([0, FieldList.Count - 1], varVariant);
      Fields := '';
      for i := 0 to FieldList.Count - 1 do
        with TField(FieldList[i]) do
        begin
          if IsDelta then
            KeyValues[i] := OldValue else
            KeyValues[i] := Value;
          if Fields <> '' then Fields := Fields + ';';
          Fields := Fields + FieldName;
        end;
      Result := Source.Locate(Fields, KeyValues, []);
    end
    else if FieldList.Count = 1 then
    begin
      with TField(FieldList[0]) do
        if IsDelta then
          Result := Source.Locate(FieldName, OldValue, []) else
          Result := Source.Locate(FieldName, Value, []);
    end else
      DatabaseError(SNoKeySpecified);
  finally
    FieldList.Free;
  end;
end;

procedure TDataSetProvider.FetchDetails(Source, Delta: TDataSet);
var
  i: Integer;
  Field: TField;
begin
  Source.First;
  while not Source.EOF do
  begin
    Delta.Insert;
    for i := 0 to Delta.FieldCount - 1 do
    begin
      Field := Source.FindField(Delta.Fields[i].FieldName);
      if Field <> nil then
        Delta.Fields[i].Assign(Field);
    end;
    Delta.Post;
    Source.Next;
  end;
end;

procedure TDataSetProvider.UpdateRecord(Source, Delta: TDataSet; BlobsOnly, KeyOnly: Boolean);
var
  Field: TField;
  i: Integer;
  UseUpMode: TUpdateMode;
begin
  if KeyOnly then
    UseUpMode := upWhereKeyOnly
  else
    UseUpMode := UpdateMode;
  if not FindRecord(Source, Delta, UseUpMode) then
    DatabaseError(SRecordChanged);
  begin
    if not FindRecord(Source, Delta, upWhereKeyOnly) then
      DatabaseError(SRecordChanged);
    with Delta do
    begin
      Edit;
      for i := 0 to FieldCount - 1 do
      begin
        Field := Source.FindField(Fields[i].FieldName);
        if (Field <> nil) and (not BlobsOnly or (Field.IsBlob and VarIsNull(Fields[i].NewValue))) then
          Fields[i].Assign(Field);
      end;
      Post;
    end;
  end;
end;

procedure TDataSetProvider.DoBeforeExecute(const CommandText: WideString;
  var Params, OwnerData: OleVariant);
begin
  SetCommandText(CommandText);
  SetParams(Params);
  inherited DoBeforeExecute(CommandText, Params, OwnerData);
end;

procedure TDataSetProvider.InternalExecute(const CommandText: WideString;
  var Params: OleVariant);
begin
  CheckDataSet;
  IProviderSupport(DataSet).PSExecute;
end;

procedure TDataSetProvider.DoGetTableName(DataSet: TDataSet; var TableName: string);
begin
  if Assigned(OnGetTableName) then
    OnGetTableName(Self, DataSet, TableName);
end;

procedure TDataSetProvider.Reset;
begin
  CheckDataSet;
  if FDataSetOpened then
  begin
    DataSet.Close;
    FDataSetOpened := False;
  end;
  IProviderSupport(DataSet).PSReset;
  if DataSet.Active then
    DataSet.First;
  FRecordsSent := 0;
end;

procedure TDataSetProvider.SetCommandText(const CommandText: string);
begin
  if CommandText = '' then Exit;
  if not (poAllowCommandText in Options) then
    DatabaseError(SCannotChangeCommandText);
  CheckDataSet;
  IProviderSupport(DataSet).PSSetCommandText(CommandText);
end;

procedure TDataSetProvider.SetParams(Values: OleVariant);
begin
  if VarIsEmpty(Values) then Exit;
  CheckDataSet;
  if not Assigned(FParams) then
    FParams := TParams.Create;
  FParams.Clear;
  UnpackParams(Values, FParams);
  IProviderSupport(DataSet).PSSetParams(FParams);
end;

function TDataSetProvider.InternalGetParams(Types: TParamTypes = AllParamTypes): OleVariant;
var
  Params: TParams;
begin
  CheckDataSet;
  Params := IProviderSupport(DataSet).PSGetParams;
  if (Params = nil) or (Params.Count = 0) then
    Result := NULL else
    Result := PackageParams(Params, Types);
end;

function TDataSetProvider.InternalRowRequest(const Row: OleVariant; Options: TFetchOptions): OleVariant;
begin
  CheckResolver;
  CheckDataSet;
  Resolver.FUpdateTree.InitData(DataSet);
  try
    if not DataSet.Active then
    begin
      DataSet.Open;
      FDataSetOpened := True;
    end;     
    Result := inherited InternalRowRequest(Row, Options);
  finally
    Resolver.FUpdateTree.InitData(nil);
    if FDataSetOpened then
    begin
      DataSet.Close;
      FDataSetOpened := False;
    end;    
  end;
end;

function TDataSetProvider.InternalApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
  out ErrorCount: Integer): OleVariant;
var
  TransactionStarted: Boolean;
begin
  CheckDataSet;
  TransactionStarted := not IProviderSupport(DataSet).PSInTransaction;
  if TransactionStarted then
    IProviderSupport(DataSet).PSStartTransaction;
  try
    CheckResolver;
    Resolver.FUpdateTree.InitData(DataSet);
    try
      Result := inherited InternalApplyUpdates(Delta, MaxErrors, ErrorCount);
    finally
      Resolver.FUpdateTree.InitData(nil);
    end;
  finally
    if TransactionStarted then
      IProviderSupport(DataSet).PSEndTransaction((ErrorCount <= MaxErrors) or (MaxErrors = -1));
  end;
end;

procedure TDataSetProvider.SetDataSet(ADataSet: TDataSet);
begin
  FDataSet := ADataSet;
end;

procedure TDataSetProvider.SetResolveToDataSet(Value: Boolean);
begin
  if (Value <> FResolveToDataSet) and Assigned(Resolver) then
    FreeResolver;
  FResolveToDataSet := Value;
end;

function TDataSetProvider.CreateResolver: TCustomResolver;
begin
  if ResolveToDataSet then
    Result := TDataSetResolver.Create(Self) else
    Result := TSQLResolver.Create(Self);
end;

procedure TDataSetProvider.CheckDataSet;
begin
  if not Assigned(DataSet) then DatabaseError(SMissingDataSet);
end;

procedure TDataSetProvider.DoBeforeGetRecords(Count: Integer; Options: Integer;
  const CommandText: WideString; var Params, OwnerData: OleVariant);
begin
  SetCommandText(CommandText);
  SetParams(Params);
  inherited;
end;

function TDataSetProvider.InternalGetRecords(Count: Integer; out RecsOut: Integer;
  Options: TGetRecordOptions; const CommandText: WideString;
  var Params: OleVariant): OleVariant;
begin
  try
    if grReset in Options then
    begin
      Reset;
      { When doing only a reset and not getting more data then exit }
      if Count = 0 then Exit;
    end;
    if not DataSet.Active then
    begin
      DataSet.Open;
      FDataSetOpened := True;
    end;
    if (Count = 0) or (grMetaData in Options) then
    begin
      FDataDS.Free;
      FDataDS := nil;
      FRecordsSent := 0;
    end;
    DataSet.CheckBrowseMode;
    DataSet.BlockReadSize := Count;
    try
      Result := inherited InternalGetRecords(Count, RecsOut, Options,
        CommandText, Params);
      Inc(FRecordsSent, RecsOut);
      if (RecsOut <> Count) then Reset;
    finally
      if DataSet.Active then
      begin
        DataSet.BlockReadSize := 0;
        if (Count <> 0) and (RecsOut = Count) then
          DataSet.Next;
      end;
    end;
  except
    Reset;
    raise;
  end;
end;

procedure TDataSetProvider.DoGetProviderAttributes(DataSet: TDataSet; List: TList);
var
  CustParams: OleVariant;
  Attr: PPacketAttribute;
  i, j: Integer;
begin
  IProviderSupport(DataSet).PSGetAttributes(List);
  if Assigned(FGetDSProps) then
  begin
    FGetDSProps(Self, DataSet, CustParams);
    if VarIsArray(CustParams) then
    begin
      for i := VarArrayLowBound(CustParams, 1) to VarArrayHighBound(CustParams, 1) do
      begin
        if VarIsArray(CustParams[i]) and
          (VarArrayHighBound(CustParams[i], 1) - VarArrayLowBound(CustParams[i], 1) = 2) then
        begin
          j := VarArrayLowBound(CustParams[i], 1);
          New(Attr);
          List.Add(Attr);
          with Attr^ do
          begin
            Name := CustParams[i][j];
            Value := CustParams[i][j + 1];
            IncludeInDelta := CustParams[i][j + 2];
          end;
        end;
      end;
    end;
  end;
end;

procedure TDataSetProvider.CreateDataPacket(PacketOpts: TGetRecordOptions;
  ProvOpts: TProviderOptions; var RecsOut: Integer; var Data: OleVariant);
begin
  if not Assigned(FDSWriter) then
    FDSWriter := TDataPacketWriter.Create;
  FDSWriter.Constraints := Constraints;
  FDSWriter.OnGetParams := DoGetProviderAttributes;
  FDSWriter.PacketOptions := PacketOpts;
  FDSWriter.Options := ProvOpts;
  FDSWriter.GetDataPacket(DataSet, RecsOut, Data);
end;

procedure TDataSetProvider.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (FDataSet <> nil) and
    (AComponent = FDataSet) then FDataSet := nil;
end;

{ TUpdateTree }

constructor TUpdateTree.Create(AParent: TUpdateTree; AResolver: TCustomResolver);
begin
  FResolver := AResolver;
  FParent := AParent;
  FDeltaDS := TPacketDataSet.Create(nil);
  FDeltaDS.ObjectView := True;
  FDeltaDS.FieldDefs.HiddenFields := True;
  FDetails := TList.Create;
  FName := '';
end;

destructor TUpdateTree.Destroy;
begin
  if Assigned(FResolver) then
    FResolver.FreeTreeData(Self);
  Clear;
  FDetails.Free;
  if not Assigned(Parent) then
    FDeltaDS.Free;
  inherited Destroy;
end;

function TUpdateTree.GetIsNested: Boolean;
begin
  Result := Assigned(Source) and Assigned(Source.DataSetField);
end;

procedure TUpdateTree.Clear;
var
  i: Integer;
begin
  for i := 0 to DetailCount - 1 do
    Details[i].Free;
  FDetails.Clear;
  FDeltaDS.Data := NULL;
  if not Assigned(Parent) then
  begin
    FErrorDS.Free;
    FErrorDS := nil;
  end;
end;

function TUpdateTree.GetTree(const AName: string): TUpdateTree;
var
  i: Integer;
begin
  for i := 0 to DetailCount - 1 do
    if AnsiCompareText(Details[i].Name, AName) = 0 then
    begin
      Result := Details[i];
      Exit;
    end;
  Result := TUpdateTree.Create(Self, FResolver);
  Result.Name := AName;
  FDetails.Add(Result);
end;

procedure TUpdateTree.InitData(ASource: TDataSet);
var
  i: Integer;
  Tree: TUpdateTree;
  List: TList;
begin
  if ASource = nil then
  begin
    for i := 0 to FDetails.Count - 1 do
      TUpdateTree(FDetails[i]).InitData(nil);
    if FOpened then FSourceDS.Close;
    FOpened := False;
  end else
  begin
    FSourceDS := ASource;
    FOpened := (FSourceDS.FieldCount = 0) and FSourceDS.ObjectView;
    if FOpened then FSourceDS.Open;
    if FSourceDS.ObjectView then
      for i := 0 to FSourceDS.FieldCount - 1 do
        if FSourceDS.Fields[i].DataType in [ftDataSet] then
          with TDataSetField(FSourceDS.Fields[i]) do
          begin
            Tree := GetTree(FSourceDS.Fields[i].FieldName);
            Tree.InitData(NestedDataSet);
          end;
    List := TList.Create;
    try
      FSourceDS.GetDetailDataSets(List);
      for i := 0 to List.Count - 1 do
      begin
        Tree := GetTree(TDataSet(List[i]).Name);
        Tree.InitData(TDataSet(List[i]));
      end;
    finally
      List.Free;
    end;
  end;
end;

procedure TUpdateTree.InitDelta(ADelta: TPacketDataSet);
var
  i: Integer;
  Attr: Variant;
  KeySet: Boolean;
  Tree: TUpdateTree;
  FieldInfo: TFieldInfo;
begin
  if (FDeltaDS <> nil) and (FDeltaDS <> ADelta) then
    FDeltaDS.Free;
  FDeltaDS := ADelta;
  FDeltaDS.LogChanges := False;
  KeySet := False;
  for i := 0 to FDeltaDS.FieldCount - 1 do
  begin
    Attr := FDeltaDS.InternalGetOptionalParam(szPROVFLAGS, FDeltaDS.Fields[i].FieldNo);
    if not (VarIsNull(Attr) or VarIsEmpty(Attr)) then
      FDeltaDS.Fields[i].ProviderFlags := TProviderFlags(Byte(Attr));
    Attr := FDeltaDS.InternalGetOptionalParam(szORIGIN, FDeltaDS.Fields[i].FieldNo);
    if not (VarIsNull(Attr) or VarIsEmpty(Attr)) then
      FDeltaDS.Fields[i].Origin := Attr;
    Attr := FDeltaDS.InternalGetOptionalParam(szSERVERCALC, FDeltaDS.Fields[i].FieldNo);
    if not (VarIsEmpty(Attr) or VarIsNull(Attr)) and
      (VarType(Attr) = varBoolean) and Boolean(Attr) then
      FDeltaDS.Fields[i].Tag := tagSERVERCALC;
    if GetFieldInfo(FDeltaDS.Fields[i].Origin, FieldInfo) then
      FDeltaDS.Fields[i].Origin := FieldInfo.OriginalFieldName else
      FDeltaDS.Fields[i].Origin := FDeltaDS.Fields[i].FieldName;
    if pfInKey in FDeltaDS.Fields[i].ProviderFlags then
      KeySet := True;
    if Delta.Fields[i].DataType = ftDataSet then
      with TDataSetField(Delta.Fields[i]) do
      begin
        Tree := GetTree(Delta.Fields[i].FieldName);
        Tree.InitDelta(TPacketDataSet(NestedDataSet));
      end;
  end;
  FResolver.InitTreeData(Self);
  if not KeySet then
    FResolver.InitKeyFields(Self, FDeltaDS);
end;

procedure TUpdateTree.InitDelta(const ADelta: OleVariant);
begin
  if FDeltaDS.Active then Clear;
  FDeltaDS.Data := ADelta;
  InitDelta(FDeltaDS);
end;

function TUpdateTree.GetDetailCount: Integer;
begin
  Result := FDetails.Count;
end;

function TUpdateTree.GetDetail(Index: Integer): TUpdateTree;
begin
  Result := TUpdateTree(FDetails[Index]);
end;

procedure TUpdateTree.RefreshData(Options: TFetchOptions);

  function NeedsUpdate(DataSet: TDataSet): Boolean;
  var
    i: Integer;
    Field: TField;
  begin
    Result := False;
    if DataSet.RecordCount = 0 then Exit;
    for i := 0 to DataSet.FieldCount - 1 do
    begin
      Field := DataSet.Fields[i];
      Result := (Field is TDataSetField) and
                (VarIsNull(Field.NewValue) or
                 NeedsUpdate(TDataSetField(Field).NestedDataSet));
      if Result then Exit;
    end;
  end;

var
  i: Integer;
  Tree: TUpdateTree;
  Field: TField;
  Updated: Boolean;
begin
  Updated := False;
  if (foRecord in Options) and (Delta.RecordCount > 0) then
  begin
    Updated := True;
    FResolver.Provider.UpdateRecord(Source, Delta, False, True);
  end;
  for i := 0 to Delta.FieldCount - 1 do
  begin
    Field := Delta.Fields[i];
    if (not Updated) and (foBlobs in Options) and Field.IsBlob and
       VarIsNull(Field.NewValue) then
    begin
      Updated := True;
      FResolver.Provider.UpdateRecord(Source, Delta, True, False);
    end;
    if (Field is TDataSetField) then
    begin
      if not Updated then
        FResolver.Provider.LocateRecord(Source, Delta);
      Tree := GetTree(Field.FieldName);
      if Assigned(Tree) then
      begin
        if not VarIsNull(Field.NewValue) then
        begin
          if Tree.Delta.RecordCount > 0 then
            Tree.RefreshData(Options);
        end else
          FResolver.Provider.FetchDetails(Tree.Source, Tree.Delta);
      end;
    end;
  end;
end;

function TUpdateTree.DoUpdates: Boolean;
var
  i: Integer;
begin
  Result := True;
  Delta.First;
  while not Delta.EOF do
  begin
    Delta.InitAltRecBuffers(False);
    FResolver.InternalBeforeResolve(Self);
    if (Delta.UpdateStatus = usInserted) then
    begin
      Result := FResolver.InternalUpdateRecord(Self);
      if not Result then Exit;
    end;
    for i := 0 to DetailCount - 1 do
    begin
      Result := Details[i].DoUpdates;
      if not Result then Exit;
    end;
    if Delta.UpdateStatus = usUnmodified then
      Delta.InitAltRecBuffers(True);
    if (Delta.UpdateStatus = usModified) then
      Result := FResolver.InternalUpdateRecord(Self);
    if (Delta.UpdateStatus = usDeleted) then
      Result := FResolver.InternalUpdateRecord(Self);
    if not Result then Exit;
    Delta.Next;
  end;
end;

function TUpdateTree.GetErrorDS: TPacketDataSet;
var
  Field: TField;
begin
  if not Assigned(FErrorDS) then
  begin
    if not Assigned(Parent) then
    begin
      FErrorDS := TPacketDataSet.Create(nil);
      FErrorDS.ObjectView := True;
      FErrorDS.CreateFromDelta(Delta);
    end else
    begin
      Field := Parent.ErrorDS.FieldByName(Delta.DataSetField.FieldName);
      FErrorDS := (Field as TDataSetField).NestedDataSet as TPacketDataSet;
    end;
    FErrorDS.LogChanges := False;
    FErrorDS.DSBase.SetProp(DSProp(dspropAUTOINC_DISABLED), Integer(True));
  end;
  Result := FErrorDS;
end;

function TUpdateTree.GetHasErrors: Boolean;
begin
  Result := Assigned(FErrorDS);
end;

procedure TUpdateTree.InitErrorPacket(E: EUpdateError; Response: TResolverResponse);
var
  TrueRecNo: DWord;
begin
  with ErrorDS do
  begin
    if Assigned(Parent) then Parent.InitErrorPacket(nil, rrSkip);
    Self.Delta.UpdateCursorPos;
    Self.Delta.DSCursor.GetRecordNumber(TrueRecNo);
    if not Locate('ERROR_RECORDNO', Integer(TrueRecNo), []) then
      Append else
      Edit;
    if not Assigned(E) then
    begin
      if Response = rrSkip then
      begin
        SetFields([TrueRecNo]);
        Post;
      end else
        SetFields([TrueRecNo, 0, '', '', 0, 0]);
    end else
      SetFields([TrueRecNo, Ord(Response)+1, E.Message, '', 1, E.ErrorCode]);
  end;
end;

{ TCustomResolver }

constructor TCustomResolver.Create(AProvider: TBaseProvider);
begin
  FProvider := AProvider;
  FUpdateTree := TUpdateTree.Create(nil, Self);
end;

destructor TCustomResolver.Destroy;
begin
  FUpdateTree.Free;
  inherited Destroy;
end;

{ Updates }

procedure TCustomResolver.BeginUpdate;
begin
end;

procedure TCustomResolver.EndUpdate;
begin
end;

procedure TCustomResolver.InitKeyFields(Tree: TUpdateTree; ADelta: TPacketDataSet);
var
  Pos, i: Integer;
  KeyFields, FieldName: string;
begin
  KeyFields := IProviderSupport(Tree.Source).PSGetKeyFields;
  Pos := 1;
  while Pos <= Length(KeyFields) do
  begin
    FieldName := ExtractFieldName(KeyFields, Pos);
    for i := 0 to ADelta.FieldCount - 1 do
      if AnsiCompareText(FieldName, ADelta.Fields[i].Origin) = 0 then
      begin
        ADelta.Fields[i].ProviderFlags := ADelta.Fields[i].ProviderFlags + [pfInKey];
        break;
      end;
  end;
end;

procedure TCustomResolver.InitTreeData(Tree: TUpdateTree);
begin
end;

procedure TCustomResolver.FreeTreeData(Tree: TUpdateTree);
begin
end;

procedure TCustomResolver.InternalBeforeResolve(Tree: TUpdateTree);
begin
end;

function TCustomResolver.InternalUpdateRecord(Tree: TUpdateTree): Boolean;
type
  PRaiseFrame = ^TRaiseFrame;
  TRaiseFrame = record
    NextRaise: PRaiseFrame;
    ExceptAddr: Pointer;
    ExceptObject: TObject;
    ExceptionRecord: PExceptionRecord;
  end;
var
  RecNoSave: Integer;
  Applied: Boolean;
  UpdateKind: TUpdateKind;
  E: Exception;
  PrevErr, Err: EUpdateError;
begin
  PrevErr := nil;
  Err := nil;
  Tree.Delta.UseCurValues := False;
  while True do
  try
    UpdateKind := Tree.Delta.UpdateKind;
    if ((UpdateKind = ukInsert) and (FPrevResponse in [rrMerge, rrApply])) or
       ((FPrevResponse = rrMerge) and Tree.Delta.HasMergeConflicts) then
      DatabaseError(SInvalidResponse);
    Applied := False;
    RecNoSave := Tree.Delta.RecNo;
    try
      if Assigned(Provider.BeforeUpdateRecord) then
        Provider.BeforeUpdateRecord(Provider, Tree.Source, Tree.Delta, UpdateKind, Applied);
    finally
      if Tree.Delta.RecNo <> RecNoSave then
        Tree.Delta.RecNo := RecNoSave;
    end;
    if not Applied then
      case UpdateKind of
        ukModify:
        begin
          if poDisableEdits in Provider.Options then
            raise Exception.CreateRes(@SNoEditsAllowed);
          DoUpdate(Tree);
        end;
        ukDelete:
        begin
          if poDisableDeletes in Provider.Options then
            raise Exception.CreateRes(@SNoDeletesAllowed);
          DoDelete(Tree);
        end;
        ukInsert:
        begin
          if poDisableInserts in Provider.Options then
            raise Exception.CreateRes(@SNoInsertsAllowed);
          DoInsert(Tree);
        end;
      end;
    if Assigned(Provider.AfterUpdateRecord) then
      Provider.AfterUpdateRecord(Provider, Tree.Source, Tree.Delta, UpdateKind);
    if (poPropogateChanges in Provider.Options) and Tree.Delta.NewValuesModified then
      LogUpdateRecord(Tree);
    Break;
  except
    if RaiseList <> nil then
    begin
      { Remove the exception }
      E := Exception(PRaiseFrame(RaiseList)^.ExceptObject);
      PRaiseFrame(RaiseList)^.ExceptObject := nil;
      PrevErr.Free;
      PrevErr := Err;
      Err := IProviderSupport(Tree.Source).PSGetUpdateException(E, PrevErr);
      if HandleUpdateError(Tree, Err, FMaxErrors, FErrorCount) then
      begin
        Tree.Delta.UseCurValues := True;
        Continue;
      end else
        break;
    end;
  end;
  PrevErr.Free;
  Err.Free;
  FPrevResponse := rrSkip;
  Result := FErrorCount <= FMaxErrors;
end;

function TCustomResolver.RowRequest(Row: OleVariant; Options: TFetchOptions): OleVariant;
begin
  BeginUpdate;
  try
    FUpdateTree.InitDelta(Row);
    try
      FUpdateTree.RefreshData(Options);
      Result := FUpdateTree.Delta.Data;
    finally
      FUpdateTree.Clear;
    end;
  finally
    EndUpdate;
  end;
end;

function TCustomResolver.ApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
  out ErrorCount: Integer): OleVariant;
begin
  BeginUpdate;
  try
    FUpdateTree.InitDelta(Delta);
    try
      Provider.DoOnUpdateData(FUpdateTree.Delta);
      FPrevResponse := rrSkip;
      if MaxErrors = -1 then MaxErrors := MaxInt;
      FMaxErrors := MaxErrors;
      FErrorCount := 0;
      FUpdateTree.DoUpdates;
      ErrorCount := FErrorCount;
      if FUpdateTree.HasErrors then
        Result := FUpdateTree.ErrorDS.Data else
        Result := Null;
    finally
      FUpdateTree.Clear;
    end;
  finally
    EndUpdate;
  end;
end;

{ Update error handling }

function TCustomResolver.HandleUpdateError(Tree: TUpdateTree;
  E: EUpdateError; var MaxErrors, ErrorCount: Integer): Boolean;
var
  Response: TResolverResponse;
  UpdateKind: TUpdateKind;
begin
  UpdateKind := Tree.Delta.UpdateKind;
  if ErrorCount < MaxErrors then
    Response := rrSkip else
    Response := rrAbort;
  try
    InitializeConflictBuffer(Tree);
  except
    { Ignore errors that occur when initializing the conflict buffer }
  end;
  if Assigned(Provider.OnUpdateError) then
    Provider.OnUpdateError(Provider, Tree.Delta, E, UpdateKind, Response);
  if Response in [rrSkip, rrAbort] then
  begin
    Inc(ErrorCount);
    if ErrorCount > MaxErrors then
      Response := rrAbort;
    if (Response = rrAbort) then
      MaxErrors := ErrorCount - 1;
    if Response in [rrSkip, rrAbort] then
      LogUpdateError(Tree, E, Response);
  end;
  FPrevResponse := Response;
  Result := Response in [rrMerge, rrApply];
end;

procedure TCustomResolver.LogUpdateRecord(Tree: TUpdateTree);
var
  I: Integer;
  CurVal: Variant;
begin
  Tree.InitErrorPacket(nil, rrApply);
  for I := 0 to Tree.Delta.FieldCount - 1 do
  begin
    { Blobs, Bytes and VarBytes are not included in result packet }
    if (Tree.Delta.Fields[I].IsBlob) or
       (Tree.Delta.Fields[I].DataType in [ftBytes, ftVarBytes]) then
      continue;
    CurVal := Tree.Delta.Fields[I].NewValue;
    if not VarIsEmpty(CurVal) then
      Tree.ErrorDS.FieldByName(Tree.Delta.Fields[I].FieldName).Value := CurVal;
  end;
  Tree.ErrorDS.Post;
end;

procedure TCustomResolver.LogUpdateError(Tree: TUpdateTree;
  E: EUpdateError; Response: TResolverResponse);
var
  I: Integer;
  CurVal: Variant;
begin
  Tree.InitErrorPacket(E, Response);
  if Tree.Delta.HasCurValues then
    for I := 0 to Tree.Delta.FieldCount - 1 do
    begin
      { Blobs, Bytes and VarBytes are not included in result packet }
      if (Tree.Delta.Fields[I].IsBlob) or
         (Tree.Delta.Fields[I].DataType in [ftBytes, ftVarBytes]) then
        continue;
      CurVal := Tree.Delta.Fields[I].CurValue;
      if not VarIsEmpty(CurVal) then
        Tree.ErrorDS.FieldByName(Tree.Delta.Fields[I].FieldName).Value := CurVal;
    end;
  Tree.ErrorDS.Post;
end;

{ TDataSetResolver }

constructor TDataSetResolver.Create(AProvider: TDataSetProvider);
begin
  inherited Create(AProvider);
  FOpened := False;
end;

function TDataSetResolver.GetProvider: TDataSetProvider;
begin
  Result := TDataSetProvider(inherited Provider);
end;

procedure TDataSetResolver.BeginUpdate;
begin
  FOpened := not Provider.DataSet.Active;
  if FOpened then
  begin
    Provider.DataSet.Open;
    FBookmark := '';
  end else
    FBookmark := Provider.DataSet.Bookmark;
end;

procedure TDataSetResolver.EndUpdate;
begin
  if FOpened then
  begin
    Provider.DataSet.Close;
    FOpened := False;
  end else
  begin
    if (Length(FBookmark) > 0) and
       Provider.DataSet.BookmarkValid(@FBookmark[1]) then
    Provider.DataSet.Bookmark := FBookmark;
  end;
end;

procedure TDataSetResolver.InitializeConflictBuffer(Tree: TUpdateTree);
begin
  { Set the conflict buffer to the current values of the data }
  if Provider.FindRecord(Tree.Source, Tree.Delta, upWhereKeyOnly) then
    Tree.Delta.AssignCurValues(Tree.Source);
end;

procedure TDataSetResolver.InternalBeforeResolve(Tree: TUpdateTree);
begin
  Provider.FindRecord(Tree.Source, Tree.Delta, Provider.UpdateMode);
end;

procedure TDataSetResolver.PutRecord(Tree: TUpdateTree);

  procedure PutField(Src, Dest: TField); forward;

  procedure PutObjectField(Src, Dest: TObjectField);
  var
    i: Integer;
  begin
    if VarIsNull(Src.NewValue) then
      Dest.Clear else
      for i := 0 to Src.FieldCount - 1 do
        if (not VarIsEmpty(Src.Fields[i].NewValue)) and
           (pfInUpdate in Src.Fields[i].ProviderFlags) then
          PutField(Src.Fields[i], Dest.Fields[i]);
  end;

  procedure PutField(Src, Dest: TField);
  begin
    if (Src.DataType in [ftArray, ftADT]) then
      PutObjectField(TObjectField(Src), TObjectField(Dest)) else
    if (Src.DataType in [ftDataSet, ftReference]) then
      raise Exception.CreateRes(@SNoDataSets) else
    if (not VarIsEmpty(Src.NewValue)) and
       (pfInUpdate in Src.ProviderFlags) then
      Dest.Assign(Src);
  end;

var
  i: Integer;
  Field: TField;
begin
  with Tree do
  try
    for i := 0 to Delta.FieldCount - 1 do
    begin
      Field := Source.FindField(Delta.Fields[i].FieldName);
      if (Field <> nil) then
        PutField(Delta.Fields[i], Field);
    end;
    Source.Post;
  except
    Source.Cancel;
    raise;
  end;
end;

procedure TDataSetResolver.DoUpdate(Tree: TUpdateTree);
begin
  with Tree do
  begin
    if not Provider.FindRecord(Source, Delta, Provider.UpdateMode) then
      DatabaseError(SRecordChanged);
    Source.Edit;
    PutRecord(Tree);
  end;
end;

procedure TDataSetResolver.DoDelete(Tree: TUpdateTree);
begin
  with Tree do
  begin
    if Provider.FindRecord(Tree.Source, Tree.Delta, Provider.UpdateMode) then
      Source.Delete else
      DatabaseError(SRecordChanged);
  end;
end;

procedure TDataSetResolver.DoInsert(Tree: TUpdateTree);
begin
  Tree.Source.Append;
  PutRecord(Tree);
end;

{ TSQLResolver }

type
  PSQLInfo = ^TSQLInfo;
  TSQLInfo = record
    IsSQLBased: Boolean;
    QuoteChar: string;
    QuotedTable: string;
    QuotedTableDot: string;
    Opened: Boolean;
    HasObjects: Boolean;
  end;

constructor TSQLResolver.Create(AProvider: TDataSetProvider);
begin
  inherited Create(AProvider);
  FSQL := TStringList.Create;
  FParams := TParams.Create(nil);
end;

destructor TSQLResolver.Destroy;
begin
  FSQL.Free;
  FParams.Free;
  inherited Destroy;
end;

function TSQLResolver.GetProvider: TDataSetProvider;
begin
  Result := TDataSetProvider(inherited Provider);
end;

procedure TSQLResolver.InitTreeData(Tree: TUpdateTree);

  function GetQuotedTableName(SQLBased: Boolean;
    const QuoteChar, TableName: string): string;
  var
    DotPos: Integer;
  begin
    Result := '';
    if Length(TableName) > 0 then
    begin
      if TableName[1] in ['''','"','`'] then
        Result := TableName else
      begin
        if SQLBased then
        begin
          Result := TableName;
          DotPos := Pos('.', Result);
          if DotPos <> 0 then
          begin
            System.Insert(QuoteChar, Result, DotPos + 1);
            System.Insert(QuoteChar, Result, DotPos);
          end;
          Result := QuoteChar + Result + QuoteChar;
        end else
          Result := QuoteChar + TableName + QuoteChar;
      end;
    end;
  end;

var
  Info: PSQLInfo;
  i: Integer;
  TableName: string;
begin
  if Tree.Data <> nil then
    Dispose(PSQLInfo(Tree.Data));
  New(Info);
  Tree.Data := Info;
  Info.IsSQLBased := IProviderSupport(Tree.Source).PSIsSQLBased;
  Info.QuoteChar := IProviderSupport(Tree.Source).PSGetQuoteChar;
  TableName := VarToStr(Tree.Delta.GetOptionalParam(szTABLE_NAME));
  if TableName = '' then
    TableName := IProviderSupport(Tree.Source).PSGetTableName;
  Provider.DoGetTableName(Tree.Source, TableName);
  if TableName <> '' then
    Info.QuotedTable := GetQuotedTableName(Info.IsSQLBased, Info.QuoteChar, TableName);
  if Info.IsSQLBased then
    Info.QuotedTableDot := '' else
    Info.QuotedTableDot := Info.QuotedTable + '.';
  Info.HasObjects := False;
  for i := 0 to Tree.Delta.FieldCount - 1 do
    if (Tree.Delta.Fields[i] is TObjectField) and
       (TObjectField(Tree.Delta.Fields[i]).ObjectType <> '') then
    begin
      Info.HasObjects := True;
      break;
    end;
end;

procedure TSQLResolver.FreeTreeData(Tree: TUpdateTree);
begin
  Dispose(PSQLInfo(Tree.Data));
  Tree.Data := nil;
end;

procedure TSQLResolver.DoExecSQL(SQL: TStringList; Params: TParams);
var
  RowsAffected: Integer;
begin
  RowsAffected := IProviderSupport(Provider.DataSet).PSExecuteStatement(SQL.Text, Params);
  if not (poAllowMultiRecordUpdates in Provider.Options) and (RowsAffected > 1) then
    DatabaseError(STooManyRecordsModified);
  if RowsAffected < 1 then
    DatabaseError(SRecordChanged);
end;

procedure TSQLResolver.DoGetValues(SQL: TStringList; Params: TParams;
  DataSet: TDataSet);
var
  DS: TDataSet;
begin
  DS := nil;
  IProviderSupport(Provider.DataSet).PSExecuteStatement(SQL.Text, Params, @DS);
  if Assigned(DS) then
  try
    TPacketDataSet(DataSet).AssignCurValues(DS)
  finally
    DS.Free;
  end;
end;

procedure TSQLResolver.InitializeConflictBuffer(Tree: TUpdateTree);
var
  Alias: string;
begin
  if PSQLInfo(Tree.Data)^.HasObjects then Alias := DefAlias else Alias := '';
  FSQL.Clear;
  FParams.Clear;
  GenSelectSQL(Tree, FSQL, FParams, Alias);
  DoGetValues(FSQL, FParams, Tree.Delta);
end;

procedure TSQLResolver.InternalDoUpdate(Tree: TUpdateTree; UpdateKind: TUpdateKind);
var
  Alias: string;
begin
  if not IProviderSupport(Tree.Source).PSUpdateRecord(UpdateKind, Tree.Delta) then
  begin
    if (PSQLInfo(Tree.Data)^.QuotedTable = '') and not Tree.IsNested then
      DatabaseError(SNoTableName);
    if PSQLInfo(Tree.Data)^.HasObjects then Alias := DefAlias else Alias := '';
    FSQL.Clear;
    FParams.Clear;
    case UpdateKind of
      ukModify: GenUpdateSQL(Tree, FSQL, FParams, Alias);
      ukInsert: GenInsertSQL(Tree, FSQL, FParams);
      ukDelete: GenDeleteSQL(Tree, FSQL, FParams, Alias);
    end;
    DoExecSQL(FSQL, FParams);
  end;
end;

procedure TSQLResolver.DoUpdate(Tree: TUpdateTree);
begin
  InternalDoUpdate(Tree, ukModify);
end;

procedure TSQLResolver.DoDelete(Tree: TUpdateTree);
begin
  InternalDoUpdate(Tree, ukDelete);
end;

procedure TSQLResolver.DoInsert(Tree: TUpdateTree);
begin
  InternalDoUpdate(Tree, ukInsert);
end;

{ SQL generation }

function QuoteFullName(const FullName, QuoteChar: string): string;
var
  i: Integer;
  p: PChar;
begin
  if (Length(FullName) > 1) and (FullName[1] in [#0, #1]) then
    p := @FullName[2] else
    p := PChar(FullName);
  Result := Format('%s%s%0:s',[QuoteChar, p]);
  for i := Length(Result) downto 1 do
    if Result[i] = '.' then
    begin
      System.Insert(QuoteChar, Result, i + 1);
      System.Insert(QuoteChar, Result, i);
    end;
end;

function TSQLResolver.UseFieldInUpdate(Field: TField): Boolean;
const
  ExcludedTypes = [ftAutoInc, ftDataSet, ftADT, ftArray, ftReference, ftCursor, ftUnknown];
begin
  with Field do
  begin
    Result := (pfInUpdate in ProviderFlags) and not (DataType in ExcludedTypes) and
      not ReadOnly and (FieldKind = fkData) and not (pfHidden in ProviderFlags) and
      not VarIsEmpty(NewValue) and (Tag <> tagSERVERCALC);
  end;
end;

function TSQLResolver.UseFieldInWhere(Field: TField; Mode: TUpdateMode): Boolean;
const
  ExcludedTypes = [ftDataSet, ftADT, ftArray, ftReference, ftCursor, ftUnknown];
begin
  with Field do
  begin
    Result := not (DataType in ExcludedTypes) and not IsBlob and
      (FieldKind = fkData) and (Tag <> tagSERVERCALC);
    if Result then
      case Mode of
        upWhereAll:
          Result := pfInWhere in ProviderFlags;
        upWhereChanged:
          Result := ((pfInWhere in ProviderFlags) and not VarIsEmpty(NewValue)) or
            (pfInKey in ProviderFlags);
        upWhereKeyOnly:
          Result := pfInKey in ProviderFlags;
      end;
  end;
end;

procedure TSQLResolver.GenWhereSQL(Tree: TUpdateTree; SQL: TStrings; Params: TParams;
  GenUpdateMode: TUpdateMode; Alias: string);

  function AddField(Field: TField; InObject: Boolean): Boolean;
  var
    i: Integer;
    BindText: string;
  begin
    Result := False;
    with PSQLInfo(Tree.Data)^ do
    begin
      if Field.DataType = ftADT then
      begin
        for i := 0 to TObjectField(Field).FieldCount - 1 do
          if AddField(TObjectField(Field).Fields[i], True) then
            Result := True;
      end else
      if UseFieldInWhere(Field, GenUpdateMode) then
      begin
        Result := True;
        if InObject then
        begin
          if VarIsNull(Field.OldValue) then
            BindText := Format(' %s.%s is null and', [Alias,
              QuoteFullName(Field.FullName, QuoteChar)])
          else
          begin
            BindText := Format(' %s.%s = ? and',[Alias,
              QuoteFullName(Field.FullName, QuoteChar)]);
            TParam(Params.Add).AssignFieldValue(Field, Field.OldValue);
          end;
        end else
        begin
          if VarIsNull(Field.OldValue) or (not IsSQLBased and
             (Field.DataType = ftString) and (Length(Field.OldValue) = 0)) then
            BindText := Format(' %s%s%s%1:s is null and', [PSQLInfo(Tree.Data)^.QuotedTableDot,
              QuoteChar, Field.Origin])
          else
          begin
            BindText := Format(' %s%s%s%1:s = ? and',
              [PSQLInfo(Tree.Data)^.QuotedTableDot, QuoteChar, Field.Origin]);
            TParam(Params.Add).AssignFieldValue(Field, Field.OldValue);
          end;
        end;
        SQL.Add(BindText);
      end;
    end;
  end;

var
  I: Integer;
  TempStr: string;
  Added: Boolean;
begin
  with PSQLInfo(Tree.Data)^ do
  begin
    SQL.Add('where');
    Added := False;
    for I := 0 to Tree.Delta.FieldCount - 1 do
      if AddField(Tree.Delta.Fields[I], Alias = NestAlias) then
        Added := True;
    if not Added then
      DatabaseError(SNoKeySpecified);
    { Remove last ' and'}
    TempStr := SQL[SQL.Count-1];
    SQL[SQL.Count-1] := Copy(TempStr, 1, Length(TempStr) - 4);
  end;
end;

procedure TSQLResolver.GenInsertSQL(Tree: TUpdateTree; SQL: TStrings;
  Params: TParams);

  procedure AddField(Field: TField; var FieldLine, ParamLine: string);
  var
    i: Integer;
    TempStr: string;
    Value: Variant;
  begin
    with PSQLInfo(Tree.Data)^ do
    begin
      if Field.DataType in [ftADT, ftArray] then
      begin
        FieldLine := Format('%s%s%s%s%2:s, ', [FieldLine, PSQLInfo(Tree.Data)^.QuotedTableDot,
          QuoteChar, Field.Origin]);
        ParamLine := Format('%s%s(', [ParamLine, TObjectField(Field).ObjectType]);
        for i := 0 to TObjectField(Field).FieldCount - 1 do
          AddField(TObjectField(Field).Fields[i], TempStr, ParamLine);
        ParamLine := Copy(ParamLine, 1, Length(ParamLine) - 2) + '), ';
      end else
      if (Field.DataType = ftDataSet) and (TObjectField(Field).ObjectType <> '') then
      begin
        FieldLine := Format('%s%s%s%s%2:s, ', [FieldLine, PSQLInfo(Tree.Data)^.QuotedTableDot,
          QuoteChar, Field.Origin]);
        ParamLine := Format('%s%s(), ', [ParamLine, TDataSetField(Field).ObjectType]);
      end else
      if UseFieldInUpdate(Field) then
      begin
        if Field.DataType = ftOraBlob then
        begin
          FieldLine := Format('%s%s%s%s%2:s, ', [FieldLine, PSQLInfo(Tree.Data)^.QuotedTableDot,
                    QuoteChar, Field.Origin]);
          ParamLine := ParamLine + 'EMPTY_BLOB(), '
        end 
        else if Field.DataType = ftOraClob then
        begin
          FieldLine := Format('%s%s%s%s%2:s, ', [FieldLine, PSQLInfo(Tree.Data)^.QuotedTableDot,
                    QuoteChar, Field.Origin]);
          ParamLine := ParamLine + 'EMPTY_CLOB(), '
        end else
        begin
          FieldLine := Format('%s%s%s%s%2:s, ', [FieldLine, PSQLInfo(Tree.Data)^.QuotedTableDot,
          QuoteChar, Field.Origin]);
          ParamLine := ParamLine + '?, ';
          Value := Field.NewValue;
          if VarIsEmpty(Value) then Value := Field.OldValue;
          TParam(Params.Add).AssignFieldValue(Field, Value);
        end;
      end;
    end;
  end;

var
  I, J: Integer;
  FieldLine, ParamLine: string;
  OraLobs: Integer;
  Value: Variant;
begin
  OraLobs := 0;
  with PSQLInfo(Tree.Data)^ do
  begin
    SQL.Clear;
    if Tree.IsNested then
    begin
      SQL.Add(Format('insert into the (select %s FROM %s %s',[QuoteFullName(Tree.Name, QuoteChar),
        PSQLInfo(Tree.Parent.Data).QuotedTable, DefAlias]));
      GenWhereSQL(Tree.Parent, SQL, Params, upWhereKeyOnly, DefAlias);
      SQL.Add(')');
    end else
      SQL.Add(Format('insert into %s', [QuotedTable]));
    FieldLine := '  (';
    ParamLine := FieldLine;
    for I := 0 to Tree.Delta.FieldCount - 1 do
    begin
      AddField(Tree.Delta.Fields[I], FieldLine, ParamLine);
      if Tree.Delta.Fields[I].DataType in [ftOraClob, ftOraBlob] then
        Inc(OraLobs);
    end;
    if not Tree.IsNested then
      SQL.Add(Copy(FieldLine, 1, Length(FieldLine)-2)+')');
    SQL.Add('values');
    SQL.Add(Copy(ParamLine, 1, Length(ParamLine)-2)+')');

    if OraLobs > 0 then
    begin
      SQL.Add(' RETURNING ');
      J := OraLobs;
      for I := 0 to Tree.Delta.FieldCount - 1 do
        if (Tree.Delta.Fields[I].DataType in [ftOraClob, ftOraBlob] )
           and UseFieldInUpdate(Tree.Delta.Fields[I])  then
           begin
             Dec(J);
             SQL.Add(Format('%s ', [Tree.Delta.Fields[I].FullName]));
             if J > 0 then SQL.Add(', ');
             Value := Tree.Delta.Fields[I].NewValue;
             if VarIsEmpty(Value) then Value := Tree.Delta.Fields[I].OldValue;
             TParam(Params.Add).AssignFieldValue(Tree.Delta.Fields[I], Value)
           end;
      SQL.Add('INTO ');
      while OraLobs > 0 do
      begin
        SQL.Add('? ');
        Dec(OraLobs);
        if OraLobs > 0 then SQL.Add(', ');
      end;
    end;
  end;
end;

procedure TSQLResolver.GenDeleteSQL(Tree: TUpdateTree; SQL: TStrings;
  Params: TParams; Alias: string);
begin
  with PSQLInfo(Tree.Data)^ do
  begin
    SQL.Clear;
    if Tree.IsNested then
    begin
      Alias := NestAlias;
      SQL.Add(Format('delete the (select %s FROM %s %s',[QuoteFullName(Tree.Name, QuoteChar),
        PSQLInfo(Tree.Parent.Data).QuotedTable, DefAlias]));
      GenWhereSQL(Tree.Parent, SQL, Params, upWhereKeyOnly, DefAlias);
      SQL.Add(Format(') %s',[Alias]));
    end else
      SQL.Add(Format('delete from %s %s', [QuotedTable, Alias]));
    GenWhereSQL(Tree, SQL, Params, Provider.UpdateMode, Alias);
  end;
end;

procedure TSQLResolver.GenUpdateSQL(Tree: TUpdateTree; SQL: TStrings;
  Params: TParams; Alias: string);

  procedure AddField(Field: TField; InObject, InArray: Boolean);
  var
    i: Integer;
    TempStr: string;
    Value: Variant;
    NoParam: Boolean;
  begin
    NoParam := False;
    with PSQLInfo(Tree.Data)^ do
    begin
      if Field.DataType = ftADT then
      begin
        if InArray then
          SQL.Add(Format(' %s(',[TObjectField(Field).ObjectType]));
        for i := 0 to TObjectField(Field).FieldCount - 1 do
          AddField(TObjectField(Field).Fields[i], True, InArray);
        if InArray then
        begin
          TempStr := SQL[SQL.Count-1];
          SQL[SQL.Count-1] := Copy(TempStr, 1, Length(TempStr) - 1);
          SQL.Add('),');
        end;
      end
      else if Field.DataType = ftArray then
      begin
        SQL.Add(Format('%s = %s(',[Field.FullName, TObjectField(Field).ObjectType]));
        for i := 0 to TObjectField(Field).FieldCount - 1 do
          AddField(TObjectField(Field).Fields[i], InObject, True);
        TempStr := SQL[SQL.Count-1];
        SQL[SQL.Count-1] := Copy(TempStr, 1, Length(TempStr) - 1);
        SQL.Add('),');
      end
      else if InArray then
      begin
        SQL.Add(' ?,');
        Value := Field.NewValue;
        if VarIsEmpty(Value) then Value := Field.OldValue;
        TParam(Params.Add).AssignFieldValue(Field, Value);
      end
      else if UseFieldInUpdate(Field) then
      begin
        if Field.DataType = ftOraClob then
        begin
          NoParam := True;
          if InObject then
            SQL.Add(Format(' %s.%s = EMPTY_CLOB(),', [Alias, QuoteFullName(Field.FullName, QuoteChar),
              Field.FullName])) else
            SQL.Add(Format(' %s%s%s%1:s = EMPTY_CLOB(),', [PSQLInfo(Tree.Data)^.QuotedTableDot,
               QuoteChar, Field.Origin]));
        end
        else if Field.DataType = ftOraBlob then
        begin
          NoParam := True;
          if InObject then
            SQL.Add(Format(' %s.%s = EMPTY_BLOB(),', [Alias, QuoteFullName(Field.FullName, QuoteChar),
               Field.FullName])) else
            SQL.Add(Format(' %s%s%s%1:s = EMPTY_BLOB(),', [PSQLInfo(Tree.Data)^.QuotedTableDot,
               QuoteChar, Field.Origin]));
        end
        else if InObject then
          SQL.Add(Format(' %s.%s = ?,', [Alias, QuoteFullName(Field.FullName, QuoteChar),
            Field.FullName])) else
          SQL.Add(Format(' %s%s%s%1:s = ?,', [PSQLInfo(Tree.Data)^.QuotedTableDot,
            QuoteChar, Field.Origin]));
        if not NoParam then
        begin
          Value := Field.NewValue;
          if VarIsEmpty(Value) then Value := Field.OldValue;
          TParam(Params.Add).AssignFieldValue(Field, Value);
        end;
      end;
    end;
  end;

var
  I, J: integer;
  TempStr: string;
  OraLobs: Integer;
  Value: Variant;
begin
  OraLobs := 0;
  with PSQLInfo(Tree.Data)^ do
  begin
    if Tree.IsNested then
    begin
      Alias := NestAlias;
      SQL.Add(Format('update the (select %s FROM %s %s',[QuoteFullName(Tree.Name, QuoteChar),
        PSQLInfo(Tree.Parent.Data).QuotedTable, DefAlias]));
      GenWhereSQL(Tree.Parent, SQL, Params, upWhereKeyOnly, DefAlias);
      SQL.Add(Format(') %s set',[Alias]));
    end else
      SQL.Add(Format('update %s %s set', [QuotedTable, Alias]));

    for I := 0 to Tree.Delta.FieldCount - 1 do
    begin
      if (Tree.Delta.Fields[i].DataType in [ftOraClob, ftOraBlob]) and
          UseFieldInUpdate(Tree.Delta.Fields[I]) then
          Inc(OraLobs);
      AddField(Tree.Delta.Fields[i], Alias = NestAlias, False);
    end;
    { Remove last ',' }
    TempStr := SQL[SQL.Count-1];
    SQL[SQL.Count-1] := Copy(TempStr, 1, Length(TempStr) - 1);

    GenWhereSQL(Tree, SQL, Params, Provider.UpdateMode, Alias);

    if OraLobs > 0 then
    begin
      SQL.Add(' RETURNING ');
      J := OraLobs;
      for I := 0 to Tree.Delta.FieldCount - 1 do
        if (Tree.Delta.Fields[I].DataType in [ftOraClob, ftOraBlob]) 
           and UseFieldInUpdate(Tree.Delta.Fields[I])  then
           begin
             Dec(J);
             SQL.Add(Format('%s ', [Tree.Delta.Fields[I].FullName]));
             if J > 0 then SQL.Add(', ');
             Value := Tree.Delta.Fields[I].NewValue;
             if VarIsEmpty(Value) then Value := Tree.Delta.Fields[I].OldValue;
             TParam(Params.Add).AssignFieldValue(Tree.Delta.Fields[I], Value)
           end;
      SQL.Add('INTO ');
      while OraLobs > 0 do
      begin
        SQL.Add('? ');
        Dec(OraLobs);
        if OraLobs > 0 then SQL.Add(', ');
      end;
    end;
  end;
end;

procedure TSQLResolver.GenSelectSQL(Tree: TUpdateTree; SQL: TStrings;
  Params: TParams; Alias: string);
var
  i: Integer;
  Temp: string;
begin
  with PSQLInfo(Tree.Data)^ do
  begin
    SQL.Add('select');
    for i := 0 to Tree.Delta.FieldCount - 1 do
      with Tree.Delta.Fields[i] do
        if not (DataType in [ftDataSet, ftReference]) and (FieldKind = fkData)
           and (pfInWhere in ProviderFlags) then
          SQL.Add(Format(' %s%s%s%1:s,',[QuotedTableDot, QuoteChar, Origin]));
    { Remove last ',' }
    Temp := SQL[SQL.Count-1];
    SQL[SQL.Count-1] := Copy(Temp, 1, Length(Temp) - 1);
    SQL.Add(Format(' from %s %s',[QuotedTable, Alias]));
    GenWhereSQL(Tree, SQL, Params, upWhereKeyOnly, Alias);
  end;
end;

{ TLocalAppServer }

constructor TLocalAppServer.Create(AProvider: TCustomProvider);
begin
  inherited Create;
  FProvider := AProvider;
end;

destructor TLocalAppServer.Destroy; 
begin
  if FProviderCreated then FProvider.Free;
  inherited Destroy;
end;

constructor TLocalAppServer.Create(ADataset: TDataset);
begin
  inherited Create;
  FProvider := TDatasetProvider.Create(nil);
  TDatasetProvider(FProvider).Dataset := ADataset;
  FProviderCreated := True;
end;

function TLocalAppServer.GetTypeInfoCount(out Count: Integer): HResult;
begin
  Result := E_NOTIMPL;
end;

function TLocalAppServer.GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult;
begin
  Result := E_NOTIMPL;
end;

function TLocalAppServer.GetIDsOfNames(const IID: TGUID; Names: Pointer;
  NameCount, LocaleID: Integer; DispIDs: Pointer): HResult;
begin
  Result := E_NOTIMPL;
end;

function TLocalAppServer.Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
  Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult;
begin
  Result := E_NOTIMPL;
end;

function TLocalAppServer.AS_ApplyUpdates(const ProviderName: WideString;
  Delta: OleVariant; MaxErrors: Integer; out ErrorCount: Integer;
  var OwnerData: OleVariant): OleVariant;
begin
  Result := FProvider.ApplyUpdates(Delta, MaxErrors, ErrorCount, OwnerData);
end;

function TLocalAppServer.AS_GetRecords(const ProviderName: WideString; Count: Integer;
  out RecsOut: Integer; Options: Integer; const CommandText: WideString;
  var Params, OwnerData: OleVariant): OleVariant;
begin
  Result := FProvider.GetRecords(Count, RecsOut, Options, CommandText, Params,
    OwnerData);
end;

function TLocalAppServer.AS_GetProviderNames: OleVariant;
begin
  Result := NULL;
end;

function TLocalAppServer.AS_DataRequest(const ProviderName: WideString;
  Data: OleVariant): OleVariant;
begin
  Result := FProvider.DataRequest(Data);
end;

function TLocalAppServer.AS_GetParams(const ProviderName: WideString;
  var OwnerData: OleVariant): OleVariant;
begin
  Result := FProvider.GetParams(OwnerData);
end;

function TLocalAppServer.AS_RowRequest(const ProviderName: WideString;
  Row: OleVariant; RequestType: Integer; var OwnerData: OleVariant): OleVariant;
begin
  Result := FProvider.RowRequest(Row, RequestType, OwnerData);
end;

procedure TLocalAppServer.AS_Execute(const ProviderName: WideString;
   const CommandText: WideString; var Params, OwnerData: OleVariant);
begin
  FProvider.Execute(CommandText, Params, OwnerData);
end;

function TLocalAppServer.InterfaceSupportsErrorInfo(const iid: TIID): HResult;
begin
  if IsEqualGUID(IAppServer, iid) then
    Result := S_OK else
    Result := S_FALSE;
end;

function TLocalAppServer.SafeCallException(ExceptObject: TObject;
  ExceptAddr: Pointer): HResult;
begin
  Result := HandleSafeCallException(ExceptObject, ExceptAddr, IAppServer, '', '');
end;


end.
