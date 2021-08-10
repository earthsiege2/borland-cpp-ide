
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       BDE Data Access                                 }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DBTables;

{$R-,T-,H+,X+}

interface

uses Variants, Windows, SysUtils, Classes, DB, DBCommon, BDE, SMINTF;

const

{ SQL Trace buffer size }

  smTraceBufSize = 32767 + SizeOf(TraceDesc);

{ TDBDataSet flags }

  dbfOpened     = 0;
  dbfPrepared   = 1;
  dbfExecSQL    = 2;
  dbfTable      = 3;
  dbfFieldList  = 4;
  dbfIndexList  = 5;
  dbfStoredProc = 6;
  dbfExecProc   = 7;
  dbfProcDesc   = 8;
  dbfDatabase   = 9;
  dbfProvider   = 10;

{ FieldType Mappings }

const
  FldTypeMap: TFieldMap = (
    fldUNKNOWN, fldZSTRING, fldINT16, fldINT32, fldUINT16, fldBOOL,
    fldFLOAT, fldFLOAT, fldBCD, fldDATE, fldTIME, fldTIMESTAMP, fldBYTES,
    fldVARBYTES, fldINT32, fldBLOB, fldBLOB, fldBLOB, fldBLOB, fldBLOB,
    fldBLOB, fldBLOB, fldCURSOR, fldZSTRING, fldZSTRING, fldINT64, fldADT,
    fldArray, fldREF, fldTABLE, fldBLOB, fldBLOB, fldUNKNOWN, fldUNKNOWN,
    fldUNKNOWN, fldZSTRING, fldDATETIME,fldBCD);

  FldSubTypeMap: array[TFieldType] of Word = (
    0, 0, 0, 0, 0, 0, 0, fldstMONEY, 0, 0, 0, 0, 0, 0, fldstAUTOINC,
    fldstBINARY, fldstMEMO, fldstGRAPHIC, fldstFMTMEMO, fldstOLEOBJ,
    fldstDBSOLEOBJ, fldstTYPEDBINARY, 0, fldstFIXED, fldstUNICODE,
    0, 0, 0, 0, 0, fldstHBINARY, fldstHMEMO, 0, 0, 0, 0, 0, 0);

  DataTypeMap: array[0..MAXLOGFLDTYPES - 1] of TFieldType = (
    ftUnknown, ftString, ftDate, ftBlob, ftBoolean, ftSmallint,
    ftInteger, ftFloat, ftBCD, ftBytes, ftTime, ftDateTime,
    ftWord, ftInteger, ftUnknown, ftVarBytes, ftUnknown, ftUnknown,
    ftLargeInt, ftLargeInt, ftADT, ftArray, ftReference, ftDataSet, 
    ftTimeStamp);

  BlobTypeMap: array[fldstMEMO..fldstBFILE] of TFieldType = (
    ftMemo, ftBlob, ftFmtMemo, ftParadoxOle, ftGraphic, ftDBaseOle,
    ftTypedBinary, ftBlob, ftBlob, ftBlob, ftBlob, ftOraClob, ftOraBlob,
    ftBlob, ftBlob);

type

{ Forward declarations }

  TDBError = class;
  TSession = class;
  TDatabase = class;
  TBDEDataSet = class;
  TDBDataSet = class;
  TTable = class;

{ Exception classes }

  EDBEngineError = class(EDatabaseError)
  private
    FErrors: TList;
    function GetError(Index: Integer): TDBError;
    function GetErrorCount: Integer;
  public
    constructor Create(ErrorCode: DBIResult);
    destructor Destroy; override;
    property ErrorCount: Integer read GetErrorCount;
    property Errors[Index: Integer]: TDBError read GetError;
  end;

  ENoResultSet = class(EDatabaseError);

{ BDE error information type }

  TDBError = class
  private
    FErrorCode: DBIResult;
    FNativeError: Longint;
    FMessage: string;
    function GetCategory: Byte;
    function GetSubCode: Byte;
  public
    constructor Create(Owner: EDBEngineError; ErrorCode: DBIResult;
      NativeError: Longint; Message: PChar);
    property Category: Byte read GetCategory;
    property ErrorCode: DBIResult read FErrorCode;
    property SubCode: Byte read GetSubCode;
    property Message: string read FMessage;
    property NativeError: Longint read FNativeError;
  end;

{ TLocale }

  TLocale = Pointer;

{ TBDECallback }

  TBDECallbackEvent = function(CBInfo: Pointer): CBRType of Object;

  TBDECallback = class
  private
    FHandle: hDBICur;
    FOwner: TObject;
    FCBType: CBType;
    FOldCBData: Longint;
    FOldCBBuf: Pointer;
    FOldCBBufLen: Word;
    FOldCBFunc: pfDBICallBack;
    FInstalled: Boolean;
    FCallbackEvent: TBDECallbackEvent;
  protected
    function Invoke(CallType: CBType; CBInfo: Pointer): CBRType;
  public
    constructor Create(AOwner: TObject; Handle: hDBICur; CBType: CBType;
      CBBuf: Pointer; CBBufSize: Integer; CallbackEvent: TBDECallbackEvent;
      Chain: Boolean);
    destructor Destroy; override;
  end;

{ TSessionList }

  TSessionList = class(TObject)
  private
    FSessions: TThreadList;
    FSessionNumbers: TBits;
    procedure AddSession(ASession: TSession);
    procedure CloseAll;
    function GetCount: Integer;
    function GetSession(Index: Integer): TSession;
    function GetCurrentSession: TSession;
    function GetSessionByName(const SessionName: string): TSession;
    procedure SetCurrentSession(Value: TSession);
  public
    constructor Create;
    destructor Destroy; override;
    property CurrentSession: TSession read GetCurrentSession write SetCurrentSession;
    function FindSession(const SessionName: string): TSession;
    procedure GetSessionNames(List: TStrings);
    function OpenSession(const SessionName: string): TSession;
    property Count: Integer read GetCount;
    property Sessions[Index: Integer]: TSession read GetSession; default;
    property List[const SessionName: string]: TSession read GetSessionByName;
  end;

{ TSession }

  TConfigModes = (cfmVirtual, cfmPersistent, cfmSession);
  TConfigMode = set of TConfigModes;

  TPasswordEvent = procedure(Sender: TObject; var Continue: Boolean) of Object;

  TDatabaseEvent = (dbOpen, dbClose, dbAdd, dbRemove, dbAddAlias, dbDeleteAlias,
    dbAddDriver, dbDeleteDriver);

  TDatabaseNotifyEvent = procedure(DBEvent: TDatabaseEvent; const Param) of object;

  TBDEInitProc = procedure(Session: TSession);

  TTraceFlag = (tfQPrepare, tfQExecute, tfError, tfStmt, tfConnect,
    tfTransact, tfBlob, tfMisc, tfVendor, tfDataIn, tfDataOut);

  TTraceFlags = set of TTraceFlag;

  TSession = class(TComponent, IDBSession)
  private
    FHandle: HDBISes;
    FDatabases: TList;
    FCallbacks: TList;
    FLocale: TLocale;
    FSMClient: ISMClient;
    FSMBuffer: PTraceDesc;
    FTraceFlags: TTraceFlags;
    FSMLoadFailed: Boolean;
    FStreamedActive: Boolean;
    FKeepConnections: Boolean;
    FDefault: Boolean;
    FSQLHourGlass: Boolean;
    FAutoSessionName: Boolean;
    FUpdatingAutoSessionName: Boolean;
    FDLLDetach: Boolean;
    FBDEOwnsLoginCbDb: Boolean;
    FSessionName: string;
    FSessionNumber: Integer;
    FNetFileDir: string;
    FPrivateDir: string;
    FCBSCType: CBSCType;
    FLockCount: Integer;
    FReserved: Integer;
    FCBDBLogin: TCBDBLogin;
    FOnPassword: TPasswordEvent;
    FOnStartup: TNotifyEvent;
    FOnDBNotify: TDatabaseNotifyEvent;
    procedure AddDatabase(Value: TDatabase);
    procedure CallBDEInitProcs;
    procedure CheckInactive;
    procedure CheckConfigMode(CfgMode: TConfigMode);
    procedure CloseDatabaseHandle(Database: TDatabase);
    function DBLoginCallback(CBInfo: Pointer): CBRType;
    procedure DBNotification(DBEvent: TDatabaseEvent; const Param);
    procedure DeleteConfigPath(const Path, Node: string);
    function DoFindDatabase(const DatabaseName: string; AOwner: TComponent): TDatabase;
    function DoOpenDatabase(const DatabaseName: string; AOwner: TComponent): TDatabase;
    function FindDatabaseHandle(const DatabaseName: string): HDBIDB;
    function GetActive: Boolean;
    function GetConfigMode: TConfigMode;
    function GetDatabase(Index: Integer): TDatabase;
    function GetDatabaseCount: Integer;
    function GetHandle: HDBISes;
    function GetNetFileDir: string;
    function GetPrivateDir: string;
    procedure InitializeBDE;
    procedure InternalAddAlias(const Name, Driver: string; List: TStrings;
      CfgMode: TConfigMode; RestoreMode: Boolean);
    procedure InternalDeleteAlias(const Name: string; CfgMode: TConfigMode;
      RestoreMode: Boolean);
    function SessionNameStored: Boolean;
    procedure LoadSMClient(DesignTime: Boolean);
    procedure LockSession;
    procedure MakeCurrent;
    procedure RegisterCallbacks(Value: Boolean);
    procedure RemoveDatabase(Value: TDatabase);
    function ServerCallback(CBInfo: Pointer): CBRType;
    procedure SetActive(Value: Boolean);
    procedure SetAutoSessionName(Value: Boolean);
    procedure SetConfigMode(Value: TConfigMode);
    procedure SetConfigParams(const Path, Node: string; List: TStrings);
    procedure SetNetFileDir(const Value: string);
    procedure SetPrivateDir(const Value: string);
    procedure SetSessionName(const Value: string);
    procedure SetSessionNames;
    procedure SetTraceFlags(Value: TTraceFlags);
    procedure SMClientSignal(Sender: TObject; Data: Integer);
    function SqlTraceCallback(CBInfo: Pointer): CBRType;
    procedure StartSession(Value: Boolean);
    procedure UnlockSession;
    procedure UpdateAutoSessionName;
    procedure ValidateAutoSession(AOwner: TComponent; AllSessions: Boolean);
  protected
    procedure Loaded; override;
    procedure ModifyConfigParams(const Path, Node: string; List: TStrings);
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    property OnDBNotify: TDatabaseNotifyEvent read FOnDBNotify write FOnDBNotify;
    property BDEOwnsLoginCbDb: Boolean read FBDEOwnsLoginCbDb write FBDEOwnsLoginCbDb;
    procedure SetName(const NewName: TComponentName); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure AddAlias(const Name, Driver: string; List: TStrings);
    procedure AddDriver(const Name: string; List: TStrings);
    procedure AddStandardAlias(const Name, Path, DefaultDriver: string);
    property ConfigMode: TConfigMode read GetConfigMode write SetConfigMode;
    procedure AddPassword(const Password: string);
    procedure Close;
    procedure CloseDatabase(Database: TDatabase);
    procedure DeleteAlias(const Name: string);
    procedure DeleteDriver(const Name: string);
    procedure DropConnections;
    function FindDatabase(const DatabaseName: string): TDatabase;
    procedure GetAliasNames(List: TStrings);
    procedure GetAliasParams(const AliasName: string; List: TStrings);
    function GetAliasDriverName(const AliasName: string): string;
    procedure GetConfigParams(const Path, Section: string; List: TStrings);
    procedure GetDatabaseNames(List: TStrings);
    procedure GetDriverNames(List: TStrings);
    procedure GetDriverParams(const DriverName: string; List: TStrings);
    procedure GetFieldNames(const DatabaseName, TableName: string;
      List: TStrings);
    function GetPassword: Boolean;
    procedure GetTableNames(const DatabaseName, Pattern: string;
      Extensions, SystemTables: Boolean; List: TStrings);
    procedure GetStoredProcNames(const DatabaseName: string; List: TStrings);
    function IsAlias(const Name: string): Boolean;
    procedure ModifyAlias(Name: string; List: TStrings);
    procedure ModifyDriver(Name: string; List: TStrings);
    procedure Open;
    function OpenDatabase(const DatabaseName: string): TDatabase;
    procedure RemoveAllPasswords;
    procedure RemovePassword(const Password: string);
    procedure SaveConfigFile;
    property DatabaseCount: Integer read GetDatabaseCount;
    property Databases[Index: Integer]: TDatabase read GetDatabase;
    property Handle: HDBISES read GetHandle;
    property Locale: TLocale read FLocale;
    property TraceFlags: TTraceFlags read FTraceFlags write SetTraceFlags;
  published
    property Active: Boolean read GetActive write SetActive default False;
    property AutoSessionName: Boolean read FAutoSessionName write SetAutoSessionName default False;
    property KeepConnections: Boolean read FKeepConnections write FKeepConnections default True;
    property NetFileDir: string read GetNetFileDir write SetNetFileDir;
    property PrivateDir: string read GetPrivateDir write SetPrivateDir;
    property SessionName: string read FSessionName write SetSessionName stored SessionNameStored;
    property SQLHourGlass: Boolean read FSQLHourGlass write FSQLHourGlass default True;
    property OnPassword: TPasswordEvent read FOnPassword write FOnPassword;
    property OnStartup: TNotifyEvent read FOnStartup write FOnStartup;
  end;

{ TParamList }

  TFieldDescList = array of FLDDesc;

  TParamList = class(TObject)
  private
    FFieldCount: Integer;
    FFieldDescs: TFieldDescList;
    FBuffer: PChar;
    FBufSize: Word;
  public
    constructor Create(Params: TStrings);
    destructor Destroy; override;
    property Buffer: PChar read FBuffer;
    property FieldCount: Integer read FFieldCount;
    property FieldDescs: TFieldDescList read FFieldDescs;
  end;

{ TDatabase }

  TTransIsolation = (tiDirtyRead, tiReadCommitted, tiRepeatableRead);

  TDatabaseLoginEvent = procedure(Database: TDatabase;
    LoginParams: TStrings) of object;

  TDatabase = class(TCustomConnection)
  private
    FTransIsolation: TTransIsolation;
    FKeepConnection: Boolean;
    FTemporary: Boolean;
    FSessionAlias: Boolean;
    FLocaleLoaded: Boolean;
    FAliased: Boolean;
    FSQLBased: Boolean;
    FAcquiredHandle: Boolean;
    FPseudoIndexes: Boolean;
    FHandleShared: Boolean;
    FExclusive: Boolean;
    FReadOnly: Boolean;
    FRefCount: Integer;
    FHandle: HDBIDB;
    FLocale: TLocale;
    FSession: TSession;
    FParams: TStrings;
    FStmtList: TList;
    FSessionName: string;
    FDatabaseName: string;
    FDatabaseType: string;
    FOnLogin: TDatabaseLoginEvent;
    procedure CheckActive;
    procedure CheckInactive;
    procedure CheckDatabaseName;
    procedure CheckDatabaseAlias(var Password: string);
    procedure CheckSessionName(Required: Boolean);
    procedure ClearStatements;
    procedure EndTransaction(TransEnd: EXEnd);
    function GetAliasName: string;
    function GetDirectory: string;
    function GetDriverName: string;
    function GetInTransaction: Boolean;
{$HPPEMIT '#ifdef GetObjectContext'}
{$HPPEMIT '#undef GetObjectContext'}
{$HPPEMIT '#endif'}
    function GetObjectContext: IUnknown;
    function GetTraceFlags: TTraceFlags;
    procedure LoadLocale;
    procedure Login(LoginParams: TStrings);
    function OpenFromExistingDB: Boolean;
    procedure ParamsChanging(Sender: TObject);
    procedure SetAliasName(const Value: string);
    procedure SetDatabaseFlags;
    procedure SetDatabaseName(const Value: string);
    procedure SetDatabaseType(const Value: string; Aliased: Boolean);
    procedure SetDirectory(const Value: string);
    procedure SetDriverName(const Value: string);
    procedure SetExclusive(Value: Boolean);
    procedure SetHandle(Value: HDBIDB);
    procedure SetKeepConnection(Value: Boolean);
    procedure SetParams(Value: TStrings);
    procedure SetReadOnly(Value: Boolean);
    procedure SetTraceFlags(Value: TTraceFlags);
    procedure SetSessionName(const Value: string);
  protected
    procedure DoConnect; override;
    procedure DoDisconnect; override;
    function GetConnected: Boolean; override;
    function GetDataSet(Index: Integer): TDBDataSet; reintroduce;
    procedure Loaded; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure ApplyUpdates(const DataSets: array of TDBDataSet);
    procedure CloseDataSets;
    procedure Commit; 
    function Execute(const SQL: string; Params: TParams = nil;
      Cache: Boolean = False; Cursor: phDBICur = nil): Integer;
    procedure FlushSchemaCache(const TableName: string);
    procedure GetFieldNames(const TableName: string; List: TStrings);
    procedure GetTableNames(List: TStrings; SystemTables: Boolean = False);
    procedure Rollback; 
    procedure StartTransaction;
    procedure ValidateName(const Name: string);
    property DataSets[Index: Integer]: TDBDataSet read GetDataSet;
    property Directory: string read GetDirectory write SetDirectory;
    property Handle: HDBIDB read FHandle write SetHandle;
    property IsSQLBased: Boolean read FSQLBased;
    property InTransaction: Boolean read GetInTransaction;
    property Locale: TLocale read FLocale;
    property Session: TSession read FSession;
    property Temporary: Boolean read FTemporary write FTemporary;
    property SessionAlias: Boolean read FSessionAlias;
    property TraceFlags: TTraceFlags read GetTraceFlags write SetTraceFlags;
  published
    property AliasName: string read GetAliasName write SetAliasName;
    property Connected;
    property DatabaseName: string read FDatabaseName write SetDatabaseName;
    property DriverName: string read GetDriverName write SetDriverName;
    property Exclusive: Boolean read FExclusive write SetExclusive default False;
    property HandleShared: Boolean read FHandleShared write FHandleShared default False;
    property KeepConnection: Boolean read FKeepConnection write SetKeepConnection default True;
    property LoginPrompt default True;
    property Params: TStrings read FParams write SetParams;
    property ReadOnly: Boolean read FReadOnly write SetReadOnly default False;
    property SessionName: string read FSessionName write SetSessionName;
    property TransIsolation: TTransIsolation read FTransIsolation write FTransIsolation default tiReadCommitted;
    property AfterConnect;
    property AfterDisconnect;
    property BeforeConnect;
    property BeforeDisconnect;
    property OnLogin: TDatabaseLoginEvent read FOnLogin write FOnLogin;
  end;

{ TBDEDataSet }

  TRecNoStatus = (rnDbase, rnParadox, rnNotSupported);
  
  TDataSetUpdateObject = class(TComponent)
  protected
    function GetDataSet: TDataSet; virtual; abstract;
    procedure SetDataSet(ADataSet: TDataSet); virtual; abstract;
    procedure Apply(UpdateKind: TUpdateKind); virtual; abstract;
    property DataSet: TDataSet read GetDataSet write SetDataSet;
  end;

  TSQLUpdateObject = class(TDataSetUpdateObject)
  protected
     function GetSQL(UpdateKind: TUpdateKind): TStrings; virtual; abstract;
  end;

  TKeyIndex = (kiLookup, kiRangeStart, kiRangeEnd, kiCurRangeStart,
    kiCurRangeEnd, kiSave);

  PKeyBuffer = ^TKeyBuffer;
  TKeyBuffer = packed record
    Modified: Boolean;
    Exclusive: Boolean;
    FieldCount: Integer;
  end;

  PRecInfo = ^TRecInfo;
  TRecInfo = packed record
    RecordNumber: Longint;
    UpdateStatus: TUpdateStatus;
    BookmarkFlag: TBookmarkFlag;
  end;

  TBlobDataArray = array of TBlobData;

  TBDEDataSet = class(TDataSet)
  private
    FHandle: HDBICur;
    FStmtHandle: HDBIStmt;
    FRecProps: RecProps;
    FLocale: TLocale;
    FExprFilter: HDBIFilter;
    FFuncFilter: HDBIFilter;
    FFilterBuffer: PChar;
    FIndexFieldMap: DBIKey;
    FExpIndex: Boolean;
    FCaseInsIndex: Boolean;
    FCachedUpdates: Boolean;
    FInUpdateCallback: Boolean;
    FCanModify: Boolean;
    FCacheBlobs: Boolean;
    FKeySize: Word;
    FUpdateCBBuf: PDELAYUPDCbDesc;
    FUpdateCallback: TBDECallback;
    FKeyBuffers: array[TKeyIndex] of PKeyBuffer;
    FKeyBuffer: PKeyBuffer;
    FRecNoStatus: TRecNoStatus;
    FIndexFieldCount: Integer;
    FConstDisableCount: Integer;
    FRecordSize: Word;
    FBookmarkOfs: Word;
    FRecInfoOfs: Word;
    FBlobCacheOfs: Word;
    FRecBufSize: Word;
    FConstraintLayer: Boolean;
    FBlockBufSize: Integer;
    FBlockBufOfs: Integer;
    FBlockBufCount: Integer;
    FBlockReadCount: Integer;
    FLastParentPos: Integer;
    FBlockReadBuf: PChar;
    FParentDataSet: TBDEDataSet;
    FUpdateObject: TDataSetUpdateObject;
    FOnUpdateError: TUpdateErrorEvent;
    FOnUpdateRecord: TUpdateRecordEvent;
    procedure ClearBlobCache(Buffer: PChar);
    function GetActiveRecBuf(var RecBuf: PChar): Boolean;
    function GetBlobData(Field: TField; Buffer: PChar): TBlobData;
    function GetOldRecord: PChar;
    procedure InitBufferPointers(GetProps: Boolean);
    function RecordFilter(RecBuf: Pointer; RecNo: Integer): Smallint; stdcall;
    procedure SetBlobData(Field: TField; Buffer: PChar; Value: TBlobData);
    function HasConstraints: Boolean;
  protected
    { IProviderSupport }
    function PSGetUpdateException(E: Exception; Prev: EUpdateError): EUpdateError; override;
    function PSIsSQLSupported: Boolean; override;
    procedure PSReset; override;
    function PSUpdateRecord(UpdateKind: TUpdateKind; Delta: TDataSet): Boolean; override;
  protected
    procedure ActivateFilters;
    procedure AddFieldDesc(FieldDescs: TFieldDescList; var DescNo: Integer;
      var FieldID: Integer; RequiredFields: TBits; FieldDefs: TFieldDefs);
    procedure AllocCachedUpdateBuffers(Allocate: Boolean);
    procedure AllocKeyBuffers;
    function AllocRecordBuffer: PChar; override;
    function CachedUpdateCallBack(CBInfo: Pointer): CBRType;
    procedure CheckCachedUpdateMode;
    procedure CheckSetKeyMode;
    procedure ClearCalcFields(Buffer: PChar); override;
    procedure CloseCursor; override;
    procedure CloseBlob(Field: TField); override;
    function CreateExprFilter(const Expr: string;
      Options: TFilterOptions; Priority: Integer): HDBIFilter;
    function CreateFuncFilter(FilterFunc: Pointer;
      Priority: Integer): HDBIFilter;
    function CreateHandle: HDBICur; virtual;
    function CreateLookupFilter(Fields: TList; const Values: Variant;
      Options: TLocateOptions; Priority: Integer): HDBIFilter;
    procedure DataEvent(Event: TDataEvent; Info: Longint); override;
    procedure DeactivateFilters;
    procedure DestroyHandle; virtual;
    procedure DestroyLookupCursor; virtual;
    function FindRecord(Restart, GoForward: Boolean): Boolean; override;
    function ForceUpdateCallback: Boolean;
    procedure FreeKeyBuffers;
    procedure FreeRecordBuffer(var Buffer: PChar); override;
    procedure GetBookmarkData(Buffer: PChar; Data: Pointer); override;
    function GetBookmarkFlag(Buffer: PChar): TBookmarkFlag; override;
    function GetCanModify: Boolean; override;
    function GetFieldFullName(Field: TField): string; override;
    function GetHandle: HDBICur;
    function GetIndexField(Index: Integer): TField;
    function GetIndexFieldCount: Integer;
    function GetIsIndexField(Field: TField): Boolean; override;
    function GetKeyBuffer(KeyIndex: TKeyIndex): PKeyBuffer;
    function GetKeyExclusive: Boolean;
    function GetKeyFieldCount: Integer;
    function GetLookupCursor(const KeyFields: string;
      CaseInsensitive: Boolean): HDBICur; virtual;
    function GetRecord(Buffer: PChar; GetMode: TGetMode; DoCheck: Boolean): TGetResult; override;
    function GetRecordCount: Integer; override;
    function GetRecNo: Integer; override;
    function GetRecordSize: Word; override;
    function GetStateFieldValue(State: TDataSetState; Field: TField): Variant; override;
    procedure GetObjectTypeNames(Fields: TFields);
    function GetUpdatesPending: Boolean;
    function GetUpdateRecordSet: TUpdateRecordTypes;
    function InitKeyBuffer(Buffer: PKeyBuffer): PKeyBuffer;
    procedure InitRecord(Buffer: PChar); override;
    procedure InternalAddRecord(Buffer: Pointer; Append: Boolean); override;
    procedure InternalCancel; override;
    procedure InternalClose; override;
    procedure InternalDelete; override;
    procedure InternalEdit; override;
    procedure InternalFirst; override;
    procedure InternalGotoBookmark(Bookmark: TBookmark); override;
    procedure InternalHandleException; override;
    procedure InternalInitFieldDefs; override;
    procedure InternalInitRecord(Buffer: PChar); override;
    procedure InternalInsert; override;
    procedure InternalLast; override;
    procedure InternalOpen; override;
    procedure InternalPost; override;
    procedure InternalRefresh; override;
    procedure InternalSetToRecord(Buffer: PChar); override;
    function IsCursorOpen: Boolean; override;
    function LocateRecord(const KeyFields: string; const KeyValues: Variant;
      Options: TLocateOptions; SyncCursor: Boolean): Boolean;
    function MapsToIndex(Fields: TList; CaseInsensitive: Boolean): Boolean;
    procedure OpenCursor(InfoQuery: Boolean); override;
    procedure PostKeyBuffer(Commit: Boolean);
    procedure PrepareCursor; virtual;
    function ProcessUpdates(UpdCmd: DBIDelayedUpdCmd): DBIResult;
    function ResetCursorRange: Boolean;
    procedure BlockReadNext; override;
    procedure SetBookmarkData(Buffer: PChar; Data: Pointer); override;
    procedure SetBookmarkFlag(Buffer: PChar; Value: TBookmarkFlag); override;
    procedure SetCachedUpdates(Value: Boolean);
    function SetCursorRange: Boolean;
    procedure SetBlockReadSize(Value: Integer); override;
    procedure SetFieldData(Field: TField; Buffer: Pointer); override;
    procedure SetFilterData(const Text: string; Options: TFilterOptions);
    procedure SetFilterHandle(var Filter: HDBIFilter; Value: HDBIFilter);
    procedure SetFiltered(Value: Boolean); override;
    procedure SetFilterOptions(Value: TFilterOptions); override;
    procedure SetFilterText(const Value: string); override;
    procedure SetIndexField(Index: Integer; Value: TField);
    procedure SetKeyBuffer(KeyIndex: TKeyIndex; Clear: Boolean);
    procedure SetKeyExclusive(Value: Boolean);
    procedure SetKeyFieldCount(Value: Integer);
    procedure SetKeyFields(KeyIndex: TKeyIndex; const Values: array of const);
    procedure SetLinkRanges(MasterFields: TList);
    procedure SetLocale(Value: TLocale);
    procedure SetStateFieldValue(State: TDataSetState; Field: TField; const Value: Variant); override;
    procedure SetOnFilterRecord(const Value: TFilterRecordEvent); override;
    procedure SetOnUpdateError(UpdateEvent: TUpdateErrorEvent);
    procedure SetRecNo(Value: Integer); override;
    procedure SetupCallBack(Value: Boolean);
    procedure SetUpdateRecordSet(RecordTypes: TUpdateRecordTypes);
    procedure SetUpdateObject(Value: TDataSetUpdateObject);
    procedure SwitchToIndex(const IndexName, TagName: string);
    function UpdateCallbackRequired: Boolean;
    property StmtHandle: HDBIStmt read FStmtHandle write FStmtHandle;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure ApplyUpdates;
    function BookmarkValid(Bookmark: TBookmark): Boolean; override;
    procedure Cancel; override;
    procedure CancelUpdates;
    property CacheBlobs: Boolean read FCacheBlobs write FCacheBlobs default True;
    function CompareBookmarks(Bookmark1, Bookmark2: TBookmark): Integer; override;
    procedure CommitUpdates;
    function ConstraintCallBack(Req: DsInfoReq; var ADataSources: DataSources): DBIResult; stdcall;
    function ConstraintsDisabled: Boolean;
    function CreateBlobStream(Field: TField; Mode: TBlobStreamMode): TStream; override;
    procedure DisableConstraints;
    procedure EnableConstraints;
    procedure FetchAll;
    procedure FlushBuffers;
    function GetCurrentRecord(Buffer: PChar): Boolean; override;
    function GetBlobFieldData(FieldNo: Integer; var Buffer: TBlobByteData): Integer; override;
    function GetFieldData(Field: TField; Buffer: Pointer): Boolean; overload; override;
    function GetFieldData(FieldNo: Integer; Buffer: Pointer): Boolean; overload; override;
    procedure GetIndexInfo;
    function Locate(const KeyFields: string; const KeyValues: Variant;
      Options: TLocateOptions): Boolean; override;
    function Lookup(const KeyFields: string; const KeyValues: Variant;
      const ResultFields: string): Variant; override;
    function IsSequenced: Boolean; override;
    procedure Post; override;
    procedure RevertRecord;
    function UpdateStatus: TUpdateStatus; override;
    function Translate(Src, Dest: PChar; ToOem: Boolean): Integer;  override;
    property ExpIndex: Boolean read FExpIndex;
    property Handle: HDBICur read FHandle;
    property KeySize: Word read FKeySize;
    property Locale: TLocale read FLocale;
    property UpdateObject: TDataSetUpdateObject read FUpdateObject write SetUpdateObject;
    property UpdatesPending: Boolean read GetUpdatesPending;
    property UpdateRecordTypes: TUpdateRecordTypes read GetUpdateRecordSet write SetUpdateRecordSet;
  published
    property Active;
    property AutoCalcFields;
    property CachedUpdates: Boolean read FCachedUpdates write SetCachedUpdates default False;
    property ObjectView default False;
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
    property OnNewRecord;
    property OnPostError;
    property OnUpdateError: TUpdateErrorEvent read FOnUpdateError write SetOnUpdateError;
    property OnUpdateRecord: TUpdateRecordEvent read FOnUpdateRecord write FOnUpdateRecord;
  end;

{ TNestedTable }

  TNestedTable = class(TBDEDataSet)
  protected
    function CreateHandle: HDBICur; override;
    procedure DoAfterPost; override;
    procedure DoBeforeInsert; override;
    procedure InternalPost; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property DataSetField;
    property ObjectView default True;
  end;

{ TDBDataSet }

  TDBFlags = set of 0..15;

  TDBDataSet = class(TBDEDataSet)
  private
    FAutoRefresh: Boolean;
    FDBFlags: TDBFlags;
    FUpdateMode: TUpdateMode;
    FDatabase: TDatabase;
    FDatabaseName: string;
    FSessionName: string;
    procedure CheckDBSessionName;
    function GetDBHandle: HDBIDB;
    function GetDBLocale: TLocale;
    function GetDBSession: TSession;
    procedure SetDatabaseName(const Value: string);
    procedure SetSessionName(const Value: string);
    procedure SetUpdateMode(const Value: TUpdateMode);
    procedure SetAutoRefresh(const Value: Boolean);
    procedure SetupAutoRefresh;
  protected
    { IProviderSupport }
    procedure PSEndTransaction(Commit: Boolean); override;
    function PSExecuteStatement(const ASQL: string; AParams: TParams;
      ResultSet: Pointer = nil): Integer; override;
    procedure PSGetAttributes(List: TList); override;
    function PSGetQuoteChar: string; override;
    function PSInTransaction: Boolean; override;
    function PSIsSQLBased: Boolean; override;
    procedure PSStartTransaction; override;
    function PSUpdateRecord(UpdateKind: TUpdateKind; Delta: TDataSet): Boolean; override;
  protected
    procedure CloseCursor; override;
    function ConstraintsStored: Boolean;
    procedure Disconnect; virtual;
    procedure OpenCursor(InfoQuery: Boolean); override;
    function SetDBFlag(Flag: Integer; Value: Boolean): Boolean; virtual;
    procedure SetHandle(Value: HDBICur);
    property DBFlags: TDBFlags read FDBFlags;
    property UpdateMode: TUpdateMode read FUpdateMode write SetUpdateMode default upWhereAll;
  public
    constructor Create(AOwner: TComponent); override;
    function CheckOpen(Status: DBIResult): Boolean;
    procedure CloseDatabase(Database: TDatabase);
    function OpenDatabase: TDatabase;
    property Database: TDatabase read FDatabase;
    property DBHandle: HDBIDB read GetDBHandle;
    property DBLocale: TLocale read GetDBLocale;
    property DBSession: TSession read GetDBSession;
    property Handle: HDBICur read GetHandle write SetHandle;
  published
    property AutoRefresh: Boolean read FAutoRefresh write SetAutoRefresh default False;
    property DatabaseName: string read FDatabaseName write SetDatabaseName;
    property Filter;
    property Filtered;
    property FilterOptions;
    property SessionName: string read FSessionName write SetSessionName;
    property OnFilterRecord;
  end;

{ TTable }

  TBatchMode = (batAppend, batUpdate, batAppendUpdate, batDelete, batCopy);
  TTableType = (ttDefault, ttParadox, ttDBase, ttFoxPro, ttASCII);
  TLockType = (ltReadLock, ltWriteLock);
  TIndexName = type string;

  TIndexDescList = array of IDXDesc;

  TValCheckList = array of VCHKDesc;

  TIndexFiles = class(TStringList)
  private
    FOwner: TTable;
  public
    constructor Create(AOwner: TTable);
    function Add(const S: string): Integer; override;
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Insert(Index: Integer; const S: string); override;
  end;

  TTable = class(TDBDataSet)
  private
    FStoreDefs: Boolean;
    FIndexDefs: TIndexDefs;
    FMasterLink: TMasterDataLink;
    FDefaultIndex: Boolean;
    FExclusive: Boolean;
    FReadOnly: Boolean;
    FTableType: TTableType;
    FFieldsIndex: Boolean;
    FTableName: TFileName;
    FIndexName: TIndexName;
    FIndexFiles: TStrings;
    FLookupHandle: HDBICur;
    FLookupKeyFields: string;
    FTableLevel: Integer;
    FLookupCaseIns: Boolean;
    FNativeTableName: DBITBLNAME;
    procedure CheckMasterRange;
    procedure DecodeIndexDesc(const IndexDesc: IDXDesc;
      var Source, Name, FieldExpression, DescFields: string;
      var Options: TIndexOptions);
    function FieldDefsStored: Boolean;
    function GetDriverTypeName(Buffer: PChar): PChar;
    function GetExists: Boolean;
    function GetIndexFieldNames: string;
    function GetIndexName: string;
    procedure GetIndexParams(const IndexName: string; FieldsIndex: Boolean;
      var IndexedName, IndexTag: string);
    function GetMasterFields: string;
    function GetTableTypeName: PChar;
    function GetTableLevel: Integer;
    function IndexDefsStored: Boolean;
    function IsXBaseTable: Boolean;
    procedure MasterChanged(Sender: TObject);
    procedure MasterDisabled(Sender: TObject);
    procedure SetDataSource(Value: TDataSource);
    procedure SetExclusive(Value: Boolean);
    procedure SetIndexDefs(Value: TIndexDefs);
    procedure SetIndex(const Value: string; FieldsIndex: Boolean);
    procedure SetIndexFieldNames(const Value: string);
    procedure SetIndexFiles(Value: TStrings);
    procedure SetIndexName(const Value: string);
    procedure SetMasterFields(const Value: string);
    procedure SetReadOnly(Value: Boolean);
    procedure SetTableLock(LockType: TLockType; Lock: Boolean);
    procedure SetTableName(const Value: TFileName);
    procedure SetTableType(Value: TTableType);
    function SetTempLocale(ActiveCheck: Boolean): TLocale;
    procedure RestoreLocale(LocaleSave: TLocale);
    procedure UpdateRange;
  protected
    { IProviderSupport }
    function PSGetDefaultOrder: TIndexDef; override;
    function PSGetKeyFields: string; override;
    function PSGetTableName: string; override;
    function PSGetIndexDefs(IndexTypes: TIndexOptions): TIndexDefs; override;
    procedure PSSetCommandText(const CommandText: string); override;
    procedure PSSetParams(AParams: TParams); override;
  protected
    function CreateHandle: HDBICur; override;
    procedure DataEvent(Event: TDataEvent; Info: Longint); override;
    procedure DefChanged(Sender: TObject); override;
    procedure DestroyHandle; override;
    procedure DestroyLookupCursor; override;
    procedure DoOnNewRecord; override;
    procedure EncodeFieldDesc(var FieldDesc: FLDDesc;
      const Name: string; DataType: TFieldType; Size, Precision: Integer);
    procedure EncodeIndexDesc(var IndexDesc: IDXDesc;
      const Name, FieldExpression: string; Options: TIndexOptions;
      const DescFields: string = '');
    function GetCanModify: Boolean; override;
    function GetDataSource: TDataSource; override;
    function GetHandle(const IndexName, IndexTag: string): HDBICur;
    function GetLanguageDriverName: string;
    function GetLookupCursor(const KeyFields: string;
      CaseInsensitive: Boolean): HDBICur; override;
    procedure InitFieldDefs; override;
    function GetFileName: string;
    function GetTableType: TTableType;
    function IsProductionIndex(const IndexName: string): Boolean;
    function NativeTableName: PChar;
    procedure PrepareCursor; override;
    procedure UpdateIndexDefs; override;
    property MasterLink: TMasterDataLink read FMasterLink;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function BatchMove(ASource: TBDEDataSet; AMode: TBatchMode): Longint;
    procedure AddIndex(const Name, Fields: string; Options: TIndexOptions;
      const DescFields: string = '');
    procedure ApplyRange;
    procedure CancelRange;
    procedure CloseIndexFile(const IndexFileName: string);
    procedure CreateTable;
    procedure DeleteIndex(const Name: string);
    procedure DeleteTable;
    procedure EditKey;
    procedure EditRangeEnd;
    procedure EditRangeStart;
    procedure EmptyTable;
    function FindKey(const KeyValues: array of const): Boolean;
    procedure FindNearest(const KeyValues: array of const);
    procedure GetDetailLinkFields(MasterFields, DetailFields: TList); override;
    procedure GetIndexNames(List: TStrings);
    procedure GotoCurrent(Table: TTable);
    function GotoKey: Boolean;
    procedure GotoNearest;
    procedure LockTable(LockType: TLockType);
    procedure OpenIndexFile(const IndexName: string);
    procedure RenameTable(const NewTableName: string);
    procedure SetKey;
    procedure SetRange(const StartValues, EndValues: array of const);
    procedure SetRangeEnd;
    procedure SetRangeStart;
    procedure UnlockTable(LockType: TLockType);
    property Exists: Boolean read GetExists;
    property IndexFieldCount: Integer read GetIndexFieldCount;
    property IndexFields[Index: Integer]: TField read GetIndexField write SetIndexField;
    property KeyExclusive: Boolean read GetKeyExclusive write SetKeyExclusive;
    property KeyFieldCount: Integer read GetKeyFieldCount write SetKeyFieldCount;
    property TableLevel: Integer read GetTableLevel write FTableLevel;
  published
    property Constraints stored ConstraintsStored;
    property DefaultIndex: Boolean read FDefaultIndex write FDefaultIndex default True;
    property Exclusive: Boolean read FExclusive write SetExclusive default False;
    property FieldDefs stored FieldDefsStored;
    property IndexDefs: TIndexDefs read FIndexDefs write SetIndexDefs stored IndexDefsStored;
    property IndexFieldNames: string read GetIndexFieldNames write SetIndexFieldNames;
    property IndexFiles: TStrings read FIndexFiles write SetIndexFiles;
    property IndexName: string read GetIndexName write SetIndexName;
    property MasterFields: string read GetMasterFields write SetMasterFields;
    property MasterSource: TDataSource read GetDataSource write SetDataSource;
    property ReadOnly: Boolean read FReadOnly write SetReadOnly default False;
    property StoreDefs: Boolean read FStoreDefs write FStoreDefs default False;
    property TableName: TFileName read FTableName write SetTableName;
    property TableType: TTableType read FTableType write SetTableType default ttDefault;
    property UpdateMode;
    property UpdateObject;
  end;

{ TBatchMove }

  TBatchMove = class(TComponent)
  private
    FDestination: TTable;
    FSource: TBDEDataSet;
    FMode: TBatchMode;
    FAbortOnKeyViol: Boolean;
    FAbortOnProblem: Boolean;
    FTransliterate: Boolean;
    FRecordCount: Longint;
    FMovedCount: Longint;
    FKeyViolCount: Longint;
    FProblemCount: Longint;
    FChangedCount: Longint;
    FMappings: TStrings;
    FKeyViolTableName: TFileName;
    FProblemTableName: TFileName;
    FChangedTableName: TFileName;
    FCommitCount: Integer;
    function ConvertName(const Name: string; Buffer: PChar): PChar;
    procedure SetMappings(Value: TStrings);
    procedure SetSource(Value: TBDEDataSet);
  protected
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Execute;
  public
    property ChangedCount: Longint read FChangedCount;
    property KeyViolCount: Longint read FKeyViolCount;
    property MovedCount: Longint read FMovedCount;
    property ProblemCount: Longint read FProblemCount;
  published
    property AbortOnKeyViol: Boolean read FAbortOnKeyViol write FAbortOnKeyViol default True;
    property AbortOnProblem: Boolean read FAbortOnProblem write FAbortOnProblem default True;
    property CommitCount: Integer read FCommitCount write FCommitCount default 0;
    property ChangedTableName: TFileName read FChangedTableName write FChangedTableName;
    property Destination: TTable read FDestination write FDestination;
    property KeyViolTableName: TFileName read FKeyViolTableName write FKeyViolTableName;
    property Mappings: TStrings read FMappings write SetMappings;
    property Mode: TBatchMode read FMode write FMode default batAppend;
    property ProblemTableName: TFileName read FProblemTableName write FProblemTableName;
    property RecordCount: Longint read FRecordCount write FRecordCount default 0;
    property Source: TBDEDataSet read FSource write SetSource;
    property Transliterate: Boolean read FTransliterate write FTransliterate default True;
  end;

{ TStoredProc }

  TParamBindMode = (pbByName, pbByNumber);

  TServerDesc = record
    ParamName: string[DBIMAXSPNAMELEN];
    BindType: TFieldType;
  end;

  TServerDescList = array of TServerDesc;
  TSPParamDescList = array of SPParamDesc;

  TStoredProc = class(TDBDataSet)
  private
    FProcName: string;
    FParams: TParams;
    FParamDescs: TSPParamDescList;
    FServerDescs: TServerDescList;
    FRecordBuffer: array of Char;
    FOverLoad: Word;
    FPrepared: Boolean;
    FQueryMode: Boolean;
    FBindMode: TParamBindMode;
    procedure BindParams;
    function CheckServerParams: Boolean;
    function CreateCursor(GenHandle: Boolean): HDBICur;
    procedure CreateParamDesc;
    procedure FreeStatement;
    function GetCursor(GenHandle: Boolean): HDBICur;
    procedure PrepareProc;
    procedure ReadParamData(Reader: TReader);
    procedure SetParamsList(Value: TParams);
    procedure SetServerParams;
    procedure WriteParamData(Writer: TWriter);
  protected
    { IProviderSupport }
    procedure PSExecute; override;
    function PSGetTableName: string; override;
    function PSGetParams: TParams; override;
    procedure PSSetCommandText(const CommandText: string); override;
    procedure PSSetParams(AParams: TParams); override;
  protected
    function CreateHandle: HDBICur; override;
    procedure DefineProperties(Filer: TFiler); override;
    procedure Disconnect; override;
    function GetParamsCount: Word;
    function SetDBFlag(Flag: Integer; Value: Boolean): Boolean; override;
    procedure SetOverLoad(Value: Word);
    procedure SetProcName(const Value: string);
    procedure SetPrepared(Value: Boolean);
    procedure SetPrepare(Value: Boolean);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CopyParams(Value: TParams);
    function DescriptionsAvailable: Boolean;
    procedure ExecProc;
    function ParamByName(const Value: string): TParam;
    procedure Prepare;
    procedure GetResults;
    procedure UnPrepare;
    property Handle: HDBICur read GetHandle;
    property ParamCount: Word read GetParamsCount;
    property StmtHandle;
    property Prepared: Boolean read FPrepared write SetPrepare;
  published
    property StoredProcName: string read FProcName write SetProcName;
    property Overload: Word read FOverload write SetOverload default 0;
    property Params: TParams read FParams write SetParamsList stored False;
    property ParamBindMode: TParamBindMode read FBindMode write FBindMode default pbByName;
    property UpdateObject;
  end;

{ TQuery }

  TQuery = class(TDBDataSet)
  private
    FSQL: TStrings;
    FPrepared: Boolean;
    FParams: TParams;
    FText: string;
    FDataLink: TDataLink;
    FLocal: Boolean;
    FRowsAffected: Integer;
    FUniDirectional: Boolean;
    FRequestLive: Boolean;
    FSQLBinary: PChar;
    FConstrained: Boolean;
    FParamCheck: Boolean;
    FExecSQL: Boolean;
    FCheckRowsAffected: Boolean;
    function CreateCursor(GenHandle: Boolean): HDBICur;
    function GetQueryCursor(GenHandle: Boolean): HDBICur;
    function GetRowsAffected: Integer;
    procedure PrepareSQL(Value: PChar);
    procedure QueryChanged(Sender: TObject);
    procedure ReadBinaryData(Stream: TStream);
    procedure ReadParamData(Reader: TReader);
    procedure RefreshParams;
    procedure SetDataSource(Value: TDataSource);
    procedure SetQuery(Value: TStrings);
    procedure SetParamsList(Value: TParams);
    procedure SetParamsFromCursor;
    procedure SetPrepared(Value: Boolean);
    procedure SetPrepare(Value: Boolean);
    procedure WriteBinaryData(Stream: TStream);
    procedure WriteParamData(Writer: TWriter);
  protected
    { IProviderSupport }
    procedure PSExecute; override;
    function PSGetDefaultOrder: TIndexDef; override;
    function PSGetParams: TParams; override;
    function PSGetTableName: string; override;
    procedure PSSetCommandText(const CommandText: string); override;
    procedure PSSetParams(AParams: TParams); override;
  protected
    function CreateHandle: HDBICur; override;
    procedure DefineProperties(Filer: TFiler); override;
    procedure Disconnect; override;
    procedure FreeStatement; virtual;
    function GetDataSource: TDataSource; override;
    function GetParamsCount: Word;
    function SetDBFlag(Flag: Integer; Value: Boolean): Boolean; override;
    procedure GetStatementHandle(SQLText: PChar); virtual;
    property DataLink: TDataLink read FDataLink;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure ExecSQL;
    procedure GetDetailLinkFields(MasterFields, DetailFields: TList); override;
    function ParamByName(const Value: string): TParam;
    procedure Prepare;
    procedure UnPrepare;
    property Prepared: Boolean read FPrepared write SetPrepare;
    property ParamCount: Word read GetParamsCount;
    property Local: Boolean read FLocal;
    property StmtHandle;
    property Text: string read FText;
    property RowsAffected: Integer read GetRowsAffected;
    property SQLBinary: PChar read FSQLBinary write FSQLBinary;
  published
    property Constrained: Boolean read FConstrained write FConstrained default False;
    property Constraints stored ConstraintsStored;
    property DataSource: TDataSource read GetDataSource write SetDataSource;
    property ParamCheck: Boolean read FParamCheck write FParamCheck default True;
    property RequestLive: Boolean read FRequestLive write FRequestLive default False;
    property SQL: TStrings read FSQL write SetQuery;
    { This property must be listed after the SQL property for Delphi 1.0 compatibility }
    property Params: TParams read FParams write SetParamsList stored False;
    property UniDirectional: Boolean read FUniDirectional write FUniDirectional default False;
    property UpdateMode;
    property UpdateObject;
end;

{ TUpdateSQL }

  TUpdateSQL = class(TSQLUpdateObject)
  private
    FDataSet: TDataSet;
    FDatabaseName: string;
    FSessionName: string;
    FQueries: array[TUpdateKind] of TQuery;
    FSQLText: array[TUpdateKind] of TStrings;
    function GetQuery(UpdateKind: TUpdateKind): TQuery;
    function GetSQLIndex(Index: Integer): TStrings;
    procedure SetSQL(UpdateKind: TUpdateKind; Value: TStrings);
    procedure SetSQLIndex(Index: Integer; Value: TStrings);
  protected
    function GetSQL(UpdateKind: TUpdateKind): TStrings; override;
    function GetDataSet: TDataSet; override;
    procedure SetDataSet(ADataSet: TDataSet); override;
    procedure SQLChanged(Sender: TObject);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Apply(UpdateKind: TUpdateKind); override;
    procedure ExecSQL(UpdateKind: TUpdateKind); virtual; 
    procedure SetParams(UpdateKind: TUpdateKind); virtual; 
    property DatabaseName: string read FDatabaseName write FDatabaseName; 
    property DataSet;
    property Query[UpdateKind: TUpdateKind]: TQuery read GetQuery;
    property SQL[UpdateKind: TUpdateKind]: TStrings read GetSQL write SetSQL;
    property SessionName: string read FSessionName write FSessionName; 
  published
    property ModifySQL: TStrings index 0 read GetSQLIndex write SetSQLIndex;
    property InsertSQL: TStrings index 1 read GetSQLIndex write SetSQLIndex;
    property DeleteSQL: TStrings index 2 read GetSQLIndex write SetSQLIndex;
  end;

{ TBlobStream }

  TBlobStream = class(TStream)
  private
    FField: TBlobField;
    FDataSet: TBDEDataSet;
    FBuffer: PChar;
    FMode: TBlobStreamMode;
    FFieldNo: Integer;
    FOpened: Boolean;
    FModified: Boolean;
    FPosition: Longint;
    FBlobData: TBlobData;
    FCached: Boolean;
    FCacheSize: Longint;
    function GetBlobSize: Longint;
  public
    constructor Create(Field: TBlobField; Mode: TBlobStreamMode);
    destructor Destroy; override;
    function Read(var Buffer; Count: Longint): Longint; override;
    function Write(const Buffer; Count: Longint): Longint; override;
    function Seek(Offset: Longint; Origin: Word): Longint; override;
    procedure Truncate;
  end;

function AnsiToNative(Locale: TLocale; const AnsiStr: string;
  NativeStr: PChar; MaxLen: Integer): PChar;
procedure NativeToAnsi(Locale: TLocale; NativeStr: PChar;
  var AnsiStr: string);
procedure AnsiToNativeBuf(Locale: TLocale; Source, Dest: PChar; Len: Integer);
procedure NativeToAnsiBuf(Locale: TLocale; Source, Dest: PChar; Len: Integer);

function NativeCompareStr(Locale: TLocale; const S1, S2: string; Len: Integer): Integer;
function NativeCompareStrBuf(Locale: TLocale; const S1, S2: PChar; Len: Integer): Integer;
function NativeCompareText(Locale: TLocale; const S1, S2: string; Len: Integer): Integer;
function NativeCompareTextBuf(Locale: TLocale; const S1, S2: PChar; Len: Integer): Integer;

function GetFieldSource(ADataSet: TDataSet; var ADataSources:  DataSources): Boolean;

procedure DbiError(ErrorCode: DBIResult);
procedure Check(Status: DBIResult);
procedure RegisterBDEInitProc(const InitProc: TBDEInitProc);

const
  { Backward compatibility for TConfigMode }
  cmVirtual = [cfmVirtual];
  cmPersistent = [cfmPersistent];
  cmSession = [cfmSession];
  cmAll = [cfmVirtual, cfmPersistent, cfmSession];

var
  Session: TSession;
  Sessions: TSessionList;
  GetObjectContextProc: function: IUnknown;

implementation

uses DBConsts, bdeconst, ActiveX;

const
  TableTypeDriverNames: array[TTableType] of PChar =
    (szPARADOX, szPARADOX, szDBASE, szFOXPRO, szASCII);

var
  FCSect: TRTLCriticalSection;
  CSNativeToAnsi: TRTLCriticalSection;
  CSAnsiToNative: TRTLCriticalSection;
  TimerID: Word = 0;
  SQLDelay: DWORD = 50;
  StartTime: DWORD = 0;
  BDEInitProcs: TList;

{ TQueryDataLink }

type
  TQueryDataLink = class(TDetailDataLink)
  private
    FQuery: TQuery;
  protected
    procedure ActiveChanged; override;
    procedure RecordChanged(Field: TField); override;
    function GetDetailDataSet: TDataSet; override;
    procedure CheckBrowseMode; override;
  public
    constructor Create(AQuery: TQuery);
  end;

{ Utility routines }

function DefaultSession: TSession;
begin
  Result := DBTables.Session;
end;

procedure RegisterBDEInitProc(const InitProc: TBDEInitProc);
begin
  if not Assigned(BDEInitProcs) then
    BDEInitProcs := TList.Create;
  BDEInitProcs.Add(@InitProc);
end;

procedure CheckIndexOpen(Status: DBIResult);
begin
  if (Status <> 0) and (Status <> DBIERR_INDEXOPEN) then
    DbiError(Status);
end;

function GetFieldSource(ADataSet: TDataSet; var ADataSources:  DataSources): Boolean;
var
  Current: PChar;
  Field: TField;
  Values: array[0..4] of string;
  I: Integer;

  function GetPChar(const S: string): PChar;
  begin
    if S <> '' then Result := PChar(Pointer(S)) else Result := '';
  end;

  procedure Split(const S: string);
  begin
    Current := PChar(Pointer(S));
  end;

  function NextItem: string;
  var
    C: PChar;
    I: PChar;
    Terminator: Char;
    Ident: array[0..1023] of Char;
  begin
    Result := '';
    C := Current;
    I := Ident;
    while C^ in ['.',' ',#0] do
      if C^ = #0 then Exit else Inc(C);
    Terminator := '.';
    if C^ = '"' then
    begin
      Terminator := '"';
      Inc(C);
    end;
    while not (C^ in [Terminator, #0]) do
    begin
      if C^ in LeadBytes then
      begin
        I^ := C^;
        Inc(C);
        Inc(I);
      end
      else if C^ = '\' then
      begin
        Inc(C);
        if C^ in LeadBytes then
        begin
          I^ := C^;
          Inc(C);
          Inc(I);
        end;
        if C^ = #0 then Dec(C);
      end;
      I^ := C^;
      Inc(C);
      Inc(I);
    end;
    SetString(Result, Ident, I - Ident);
    if (Terminator = '"') and (C^ <> #0) then Inc(C);
    Current := C;
  end;

  function PopValue: PChar;
  begin
    if I >= 0 then
    begin
      Result := GetPChar(Values[I]);
      Dec(I);
    end else Result := '';
  end;

begin
  Result := False;
  Field := ADataSet.FindField(ADataSources.szSourceFldName);
  if (Field = nil) or (Field.Origin = '') then Exit;
  Split(Field.Origin);
  I := -1;
  repeat
    Inc(I);
    Values[I] := NextItem;
  until (Values[I] = '') or (I = High(Values));
  if I = High(Values) then Exit;
  Dec(I);
  StrCopy(ADataSources.szOrigFldName, PopValue);
  StrCopy(ADataSources.szTblName, PopValue);
  StrCopy(ADataSources.szDbName, PopValue);
  Result := (ADataSources.szOrigFldName[0] <> #0) and
    (ADataSources.szTblName[0] <> #0);
end;

procedure ApplicationHandleException(Sender: TObject);
begin
  if Assigned(Classes.ApplicationHandleException) then
    Classes.ApplicationHandleException(Sender);
end;

{ Parameter binding routines }

function GetParamDataSize(Param: TParam): Integer;
begin
  with Param do
    if ((DataType in [ftString, ftFixedChar]) and (Length(VarToStr(Value)) > 255)) or
       (DataType in [ftBlob..ftTypedBinary,ftOraBlob,ftOraClob]) then
      Result := SizeOf(BlobParamDesc) else
      Result := GetDataSize;
end;

procedure GetParamData(Param: TParam; Buffer: Pointer; const DrvLocale: TLocale);

  function GetNativeStr: PChar;
  begin
    Param.NativeStr := VarToStr(Param.Value);
    Result := PChar(Param.NativeStr);
    if DrvLocale <> nil then
      AnsiToNativeBuf(DrvLocale, Result, Result, StrLen(Result));
  end;

begin
  with Param do
    if DataType in [ftString, ftFixedChar, ftMemo]  then
    begin
      NativeStr := VarToStr(Value);
      if (Length(NativeStr) > 255) or (DataType = ftMemo) then
      begin
        with BlobParamDesc(Buffer^) do
        begin
          if DrvLocale <> nil then
            AnsiToNativeBuf(DrvLocale, PChar(NativeStr), PChar(NativeStr), Length(NativeStr));
          pBlobBuffer := PChar(NativeStr);
          ulBlobLen := StrLen(pBlobBuffer);
        end;
      end else
      begin
        if (DrvLocale <> nil) then
          AnsiToNativeBuf(DrvLocale, PChar(NativeStr), Buffer, Length(NativeStr) + 1) else
          GetData(Buffer);
      end;
    end
    else if (DataType in [ftBlob..ftTypedBinary,ftOraBlob,ftOraClob]) then
    begin
      with BlobParamDesc(Buffer^) do
      begin
        NativeStr := VarToStr(Value);
        ulBlobLen := Length(NativeStr);
        pBlobBuffer := PChar(NativeStr);
      end;
    end else
      GetData(Buffer);
end;

function GetStatementLocale(StmtHandle: HDBIStmt): TLocale;
var
  DrvName: DBINAME;
  NumBytes: Word;
begin
  DrvName[0] := #0;
  Result := nil;
  DbiGetProp(HDBIOBJ(StmtHandle), stmtLANGDRVNAME, @DrvName, SizeOf(DrvName), NumBytes);
  if StrLen(DrvName) > 0 then OsLdLoadBySymbName(DrvName, Result);
end;

procedure FreeStatementLocale(var Value: TLocale);
begin
  if Value <> nil then OsLdUnloadObj(Value);
  Value := nil;
end;

{ Any fixes made to this utility procedure should also be investigated for the
  TStoredProcedure. }
procedure SetQueryParams(Sender: TComponent; StmtHandle: HDBIStmt; Params: TParams);
var
  I: Integer;
  NumBytes: Word;
  FieldDescs: TFieldDescList;
  RecBuffer: PChar;
  CurPtr, NullPtr: PChar;
  DrvLocale: TLocale;
begin
  SetLength(FieldDescs, Params.Count);
  NumBytes := SizeOf(SmallInt);
  for I := 0 to Params.Count - 1 do
    Inc(NumBytes, GetParamDataSize(Params[I]));
  RecBuffer := AllocMem(NumBytes);
  NullPtr := RecBuffer + NumBytes - SizeOf(SmallInt);
  Smallint(Pointer(NullPtr)^) := -1;
  CurPtr := RecBuffer;
  try
    DrvLocale := GetStatementLocale(StmtHandle);
    try
      for I := 0 to Params.Count - 1 do
        with FieldDescs[I], Params[I] do
        begin
          iFldType := FldTypeMap[DataType];
          if iFldType in [fldBlob, fldZString] then
            iSubType := FldSubTypeMap[DataType]
          else if iFldType = fldUNKNOWN then
            DatabaseErrorFmt(SNoParameterValue, [Name], Sender);
          iFldNum := I + 1;
          iLen := GetParamDataSize(Params[I]);
          GetParamData(Params[i], CurPtr, DrvLocale);
          iOffset := CurPtr - RecBuffer;
          if IsNull then
            iNullOffset := NullPtr - RecBuffer
          else if iFldType = fldZString then
            iUnits1 := GetDataSize - 1 {Do not include null terminator}
          else if iFldType = fldBYTES then
            iUnits1 := GetDataSize
          else if iFldType = fldVARBYTES then
            iUnits1 := GetDataSize - 2
          else if iFldType = fldBlob then
            iSubType := FldSubTypeMap[DataType];
          Inc(CurPtr, iLen);
        end;
      Check(DbiQSetParams(StmtHandle, High(FieldDescs)+1,
        PFLDDesc(FieldDescs), RecBuffer));
    finally
      FreeStatementLocale(DrvLocale);
    end;
  finally
    FreeMem(RecBuffer);
  end;
end;

{ Timer callback function }

procedure FreeTimer(ForceKill: Boolean = False);
begin
  if (TimerID <> 0) and (ForceKill or (GetTickCount - StartTime > SQLDelay)) then
  begin
    KillTimer(0, TimerID);
    TimerID := 0;
    StartTime := 0;
    if Assigned(DBScreen) then
      DBScreen.Cursor := dcrDefault;
  end;
end;

procedure TimerCallBack(hWnd: HWND; Message: Word; TimerID: Word;
  SysTime: LongInt); stdcall;
begin
  FreeTimer;
end;

{ BdeCallbacks }

function BdeCallBack(CallType: CBType; Data: Longint;
  CBInfo: Pointer): CBRType; stdcall;
begin
  if (Data <> 0) then
    Result := TBDECallback(Data).Invoke(CallType, CBInfo) else
    Result := cbrUSEDEF;
end;

function DLLDetachCallBack(CallType: CBType; Data: Longint;
  CBInfo: Pointer): CBRType; stdcall;
begin
  Session.FDLLDetach := True;
  Sessions.CloseAll;
  Result := cbrUSEDEF
end;

constructor TBDECallback.Create(AOwner: TObject; Handle: hDBICur; CBType: CBType;
  CBBuf: Pointer; CBBufSize: Integer; CallbackEvent: TBDECallbackEvent;
  Chain: Boolean);
begin
  FOwner := AOwner;
  FHandle := Handle;
  FCBType := CBType;
  FCallbackEvent := CallbackEvent;
  DbiGetCallBack(Handle, FCBType, @FOldCBData, @FOldCBBufLen, @FOldCBBuf, FOldCBFunc);
  if not Assigned(FOldCBFunc) or Chain then
  begin
    Check(DbiRegisterCallback(FHandle, FCBType, Longint(Self), CBBufSize,
      CBBuf, BdeCallBack));
    FInstalled := True;
  end;
end;

destructor TBDECallback.Destroy;
begin
  if FInstalled then
  begin
    if Assigned(FOldCBFunc) then
    try
      DbiRegisterCallback(FHandle, FCBType, FOldCBData, FOldCBBufLen,
        FOldCBBuf, FOldCBFunc);
    except
    end
    else
      DbiRegisterCallback(FHandle, FCBType, 0, 0, nil, nil);
  end;
end;

function TBDECallback.Invoke(CallType: CBType; CBInfo: Pointer): CBRType;
begin
  if CallType = FCBType then
    Result := FCallbackEvent(CBInfo) else
    Result := cbrUSEDEF;
  if Assigned(FOldCBFunc)
    then Result := FOldCBFunc(CallType, FOldCBData, CBInfo);
end;

{ Utility routines }

function StrToOem(const AnsiStr: string): string;
begin
  SetLength(Result, Length(AnsiStr));
  if Length(Result) > 0 then
    CharToOem(PChar(AnsiStr), PChar(Result));
end;

function AnsiToNative(Locale: TLocale; const AnsiStr: string;
  NativeStr: PChar; MaxLen: Integer): PChar;
var
  Len: Integer;
begin
  Len := Length(AnsiStr);
  if Len > MaxLen then
  begin
    Len := MaxLen;
    if SysLocale.FarEast and (ByteType(AnsiStr, Len) = mbLeadByte) then
      Dec(Len);
  end;
  NativeStr[Len] := #0;
  if Len > 0 then AnsiToNativeBuf(Locale, Pointer(AnsiStr), NativeStr, Len);
  Result := NativeStr;
end;

procedure NativeToAnsi(Locale: TLocale; NativeStr: PChar;
  var AnsiStr: string);
var
  Len: Integer;
begin
  Len := StrLen(NativeStr);
  SetString(AnsiStr, nil, Len);
  if Len > 0 then NativeToAnsiBuf(Locale, NativeStr, Pointer(AnsiStr), Len);
end;

procedure AnsiToNativeBuf(Locale: TLocale; Source, Dest: PChar; Len: Integer);
var
  DataLoss: LongBool;
begin
  if Len > 0 then
    if Locale <> nil then
    begin
      EnterCriticalSection(CSAnsiToNative);
      try
        DbiAnsiToNative(Locale, Dest, Source, Len, DataLoss);
      finally
        LeaveCriticalSection(CSAnsiToNative);
      end;
    end else
      CharToOemBuff(Source, Dest, Len);
end;

procedure NativeToAnsiBuf(Locale: TLocale; Source, Dest: PChar; Len: Integer);
var
  DataLoss: LongBool;
begin
  if Len > 0 then
    if Locale <> nil then
    begin
      EnterCriticalSection(CSNativeToAnsi);
      try
        DbiNativeToAnsi(Locale, Dest, Source, Len, DataLoss);
      finally
        LeaveCriticalSection(CSNativeToAnsi);
      end;
    end else
      OemToCharBuff(Source, Dest, Len)
end;

function NativeCompareStr(Locale: TLocale; const S1, S2: string; Len: Integer): Integer;
begin
  Result := NativeCompareStrBuf(Locale, PChar(S1), PChar(S2), Len);
end;

function NativeCompareStrBuf(Locale: TLocale; const S1, S2: PChar; Len: Integer): Integer;
begin
  if Len > 0 then
    Result := OsLdStrnCmp(Locale, S1, S2, Len) else
    Result := OsLdStrCmp(Locale, S1, S2);
end;

function NativeCompareText(Locale: TLocale; const S1, S2: string; Len: Integer): Integer;
begin
  Result := NativeCompareTextBuf(Locale, PChar(S1), PChar(S2), Len);
end;

function NativeCompareTextBuf(Locale: TLocale; const S1, S2: PChar; Len: Integer): Integer;
begin
  if Len > 0 then
    Result := OsLdStrnCmpi(Locale, S1, S2, Len) else
    Result := OsLdStrCmpi(Locale, S1, S2);
end;

function IsDirectory(const DatabaseName: string): Boolean;
var
  I: Integer;
begin
  Result := True;
  if (DatabaseName = '') then Exit;
  I := 1;
  while I <= Length(DatabaseName) do
  begin
    if DatabaseName[I] in [':','\'] then Exit;
    if DatabaseName[I] in LeadBytes then Inc(I, 2)
    else Inc(I);
  end;
  Result := False;
end;

function IsStandardType(AType: PChar): Boolean;
begin
  Result := (StrIComp(AType, szPARADOX) = 0) or
    (StrIComp(AType, szDBASE) = 0) or
    (StrIComp(AType, szFOXPRO) = 0);
    { Note: szASCII not included }
end;

function GetIntProp(const Handle: Pointer; PropName: Integer): Integer;
var
  Length: Word;
  Value: Integer;
begin
  Value := 0;
  if DbiGetProp(HDBIObj(Handle), PropName, @Value, SizeOf(Value), Length) = DBIERR_NONE then
    Result := Value
  else
    Result := 0;
end;

function SetBoolProp(const Handle: Pointer; PropName: Integer; Value: Bool): Boolean;
begin
  Result := DbiSetProp(HDBIObj(Handle), PropName, Abs(Integer(Value))) = DBIERR_NONE;
end;

function StringListToParams(List: TStrings): string;
var
  S: String;
  P, I: Integer;
begin
  for I := 0 to List.Count - 1 do
  begin
    S := List[I];
    P := Pos('=', S);
    if (P >= 0) and (P < Length(S)) then
      Result := Format('%s%s:"%s";', [Result, Copy(S, 1, P-1), Copy(S, P+1, 255)]);
  end;
  Result := StrToOem(Result);
  SetLength(Result, Length(Result) - 1);
end;

procedure DbiError(ErrorCode: DBIResult);
begin
  raise EDBEngineError.Create(ErrorCode);
end;

procedure Check(Status: DBIResult);
begin
  if Status <> 0 then DbiError(Status);
end;

{ TDBError }

constructor TDBError.Create(Owner: EDBEngineError; ErrorCode: DBIResult;
  NativeError: Longint; Message: PChar);
begin
  Owner.FErrors.Add(Self);
  FErrorCode := ErrorCode;
  FNativeError := NativeError;
  FMessage := Message;
end;

function TDBError.GetCategory: Byte;
begin
  Result := Hi(FErrorCode);
end;

function TDBError.GetSubCode: Byte;
begin
  Result := Lo(FErrorCode);
end;

{ EDBEngineError }

constructor EDBEngineError.Create(ErrorCode: DBIResult);
var
  ErrorIndex: Integer;
  EntryCode: DBIResult;
  NativeError: Longint;
  ContextBuf: DBIMSG;
  Messages: TStrings;

  procedure AddMessage(const Msg: string);
  begin
    if (Msg <> '') and (Messages.IndexOf(Msg) = -1) then
      Messages.Add(Msg);
  end;

  function GetErrorString(Code: DBIResult): string;
  var
    Msg: DBIMSG;
  begin
    DbiGetErrorString(Code, Msg);
    Result := Msg;
    Trim(Result);
  end;

begin
  FreeTimer(True);
  FErrors := TList.Create;
  if not DefaultSession.Active and (ErrorCode <> DBIERR_INTERFACEVER) then
  begin
    Message := Format(SInitError, [ErrorCode]);
    TDBError.Create(Self, ErrorCode, 0, PChar(Message));
  end else
  begin
    TDBError.Create(Self, ErrorCode, 0, PChar(GetErrorString(ErrorCode)));
    Messages := TStringList.Create;
    try
      if ErrorCode <> DBIERR_USERCONSTRERR then
        AddMessage(Errors[0].Message);
      ErrorIndex := 1;
      while True do
      begin
        EntryCode := DbiGetErrorEntry(ErrorIndex, NativeError, ContextBuf);
        if (EntryCode = DBIERR_NONE) or (EntryCode = DBIERR_NOTINITIALIZED) then
          Break;
        TDBError.Create(Self, EntryCode, NativeError, ContextBuf);
        if (NativeError = 0) and (ErrorCode <> DBIERR_USERCONSTRERR) then
          AddMessage(GetErrorString(EntryCode));
        AddMessage(Trim(ContextBuf));
        Inc(ErrorIndex);
      end;
      Message := Messages.Text;
      if Message <> '' then
        Message := Copy(Message, 1, Length(Message)-2) else
        Message := Format(SBDEError, [ErrorCode]);
    finally
      Messages.Free;
    end;
 end;
end;

destructor EDBEngineError.Destroy;
var
  I: Integer;
begin
  if FErrors <> nil then
  begin
    for I := FErrors.Count - 1 downto 0 do TDBError(FErrors[I]).Free;
    FErrors.Free;
  end;
  inherited Destroy;
end;

function EDBEngineError.GetError(Index: Integer): TDBError;
begin
  Result := FErrors[Index];
end;

function EDBEngineError.GetErrorCount: Integer;
begin
  Result := FErrors.Count;
end;

{ TSessionList }

constructor TSessionList.Create;
begin
  inherited Create;
  FSessions := TThreadList.Create;
  FSessionNumbers := TBits.Create;
  InitializeCriticalSection(FCSect);
end;

destructor TSessionList.Destroy;
begin
  CloseAll;
  DeleteCriticalSection(FCSect);
  FSessionNumbers.Free;
  FSessions.Free;
  inherited Destroy;
end;

procedure TSessionList.AddSession(ASession: TSession);
var
  List: TList;
begin
  List := FSessions.LockList;
  try
    if List.Count = 0 then ASession.FDefault := True;
    List.Add(ASession);
  finally
    FSessions.UnlockList;
  end;
end;

procedure TSessionList.CloseAll;
var
  I: Integer;
  List: TList;
begin
  List := FSessions.LockList;
  try
    for I := List.Count-1 downto 0 do
      TSession(List[I]).Free;
  finally
    FSessions.UnlockList;
  end;
end;

function TSessionList.GetCount: Integer;
var
  List: TList;
begin
  List := FSessions.LockList;
  try
    Result := List.Count;
  finally
    FSessions.UnlockList;
  end;
end;

function TSessionList.GetCurrentSession: TSession;
var
  Handle: HDBISes;
  I: Integer;
  List: TList;
begin
  List := FSessions.LockList;
  try
    Check(DbiGetCurrSession(Handle));
    for I := 0 to List.Count - 1 do
      if TSession(List[I]).Handle = Handle then
      begin
        Result := TSession(List[I]);
        Exit;
      end;
    Result := nil;
  finally
    FSessions.UnlockList;
  end;
end;

function TSessionList.GetSession(Index: Integer): TSession;
var
  List: TList;
begin
  List := FSessions.LockList;
  try
    Result := TSession(List[Index]);
  finally
    FSessions.UnlockList;
  end;
end;

function TSessionList.GetSessionByName(const SessionName: string): TSession;
begin
  if SessionName = '' then
    Result := Session
  else
    Result := FindSession(SessionName);
  if Result = nil then
    DatabaseErrorFmt(SInvalidSessionName, [SessionName]);
end;

function TSessionList.FindSession(const SessionName: string): TSession;
var
  I: Integer;
  List: TList;
begin
  if SessionName = '' then
    Result := Session
  else
  begin
    List := FSessions.LockList;
    try
      for I := 0 to List.Count - 1 do
      begin
        Result := List[I];
        if AnsiCompareText(Result.SessionName, SessionName) = 0 then Exit;
      end;
      Result := nil;
    finally
      FSessions.UnlockList;
    end;
  end;
end;

procedure TSessionList.GetSessionNames(List: TStrings);
var
  I: Integer;
  SList: TList;
begin
  List.BeginUpdate;
  try
    List.Clear;
    SList := FSessions.LockList;
    try
      for I := 0 to SList.Count - 1 do
        with TSession(SList[I]) do
          List.Add(SessionName);
    finally
      FSessions.UnlockList;
    end;
  finally
    List.EndUpdate;
  end;
end;

function TSessionList.OpenSession(const SessionName: string): TSession;
begin
  Result := FindSession(SessionName);
  if Result = nil then
  begin
    Result := TSession.Create(nil);
    Result.SessionName := SessionName;
  end;
  Result.SetActive(True);
end;

procedure TSessionList.SetCurrentSession(Value: TSession);
begin
  Check(DbiSetCurrSession(Value.FHandle))
end;

{ TSession }

constructor TSession.Create(AOwner: TComponent);
begin
  ValidateAutoSession(AOwner, False);
  inherited Create(AOwner);
  FDatabases := TList.Create;
  FCallbacks := TList.Create;
  FKeepConnections := True;
  FSQLHourGlass := True;
  Sessions.AddSession(Self);
  FReserved := 0;
  FHandle := nil;
end;

destructor TSession.Destroy;
begin
  SetActive(False);
  Sessions.FSessions.Remove(Self);
  inherited Destroy;
  FDatabases.Free;
  FCallbacks.Free;
end;

procedure TSession.AddAlias(const Name, Driver: string; List: TStrings);
begin
  InternalAddAlias(Name, Driver, List, ConfigMode, True);
end;

procedure TSession.AddDriver(const Name: string; List: TStrings);
var
  Params: string;
  CfgModeSave: TConfigMode;
begin
  Params := StringListToParams(List);
  LockSession;
  try
    CfgModeSave := ConfigMode;
    try
      CheckConfigMode(ConfigMode);
      Check(DbiAddDriver(nil, PChar(StrToOem(Name)), PChar(Params), Bool(-1)));
    finally
      ConfigMode := cfgModeSave;
    end;
  finally
    UnlockSession;
  end;
  DBNotification(dbAddDriver, Pointer(Name));
end;

procedure TSession.AddDatabase(Value: TDatabase);
begin
  FDatabases.Add(Value);
  DBNotification(dbAdd, Value);
end;

procedure TSession.AddStandardAlias(const Name, Path, DefaultDriver: string);
var
  AliasParams: TStringList;
begin
  AliasParams := TStringList.Create;
  try
    AliasParams.Add(Format('%s=%s', [szCFGDBPATH, Path]));
    AliasParams.Add(Format('%s=%s', [szCFGDBDEFAULTDRIVER, DefaultDriver]));
    AddAlias(Name, szCFGDBSTANDARD, AliasParams);
  finally
    AliasParams.Free;
  end;
end;

procedure TSession.AddPassword(const Password: string);
var
  Buffer: array[0..255] of Char;
begin
  LockSession;
  try
    if Password <> '' then
      Check(DbiAddPassword(AnsiToNative(Locale, Password, Buffer,
        SizeOf(Buffer) - 1)));
  finally
    UnlockSession;
  end;
end;

procedure TSession.CallBDEInitProcs;
var
  I: Integer;
begin
  if Assigned(BDEInitProcs) then
    for I := 0 to BDEInitProcs.Count - 1 do
      TBDEInitProc(BDEInitProcs[I])(Self);
end;

procedure TSession.CheckInactive;
begin
  if Active then
    DatabaseError(SSessionActive, Self);
end;

procedure TSession.CheckConfigMode(CfgMode: TConfigMode);
begin
  if CfgMode = cmAll then CfgMode := cmPersistent;
  ConfigMode := CfgMode;
end;

procedure TSession.Close;
begin
  SetActive(False);
end;

procedure TSession.CloseDatabase(Database: TDatabase);
begin
  with Database do
  begin
    if FRefCount <> 0 then Dec(FRefCount);
    if (FRefCount = 0) and not KeepConnection then
      if not Temporary then Close else
         if not (csDestroying in ComponentState) then Free;
  end;
end;

procedure TSession.CloseDatabaseHandle(Database: TDatabase);
var
  I: Integer;
  DB: TDatabase;
begin
  for I := 0 to FDatabases.Count - 1 do
  begin
    DB := FDatabases[I];
    if (DB <> Database) and (DB.Handle <> nil) and
       (AnsiCompareText(DB.DatabaseName, Database.DatabaseName) = 0) then
      Exit;
  end;
  DbiCloseDatabase(Database.FHandle);
end;

function TSession.DBLoginCallback(CBInfo: Pointer): CBRType;
var
  Database: TDatabase;
  UserName, Password: string;
  AliasParams: TStringList;
begin
  Result := cbrYES;
  with PCBDBLogin(CBInfo)^ do
  try
    if hDB = nil then
    begin
      if not FBDEOwnsLoginCbDb then
      begin
        Database := OpenDatabase(szDbName);
        if not Database.HandleShared then
        begin
          hDb := Database.Handle;
          bCallbackToClose := True;
        end else
        begin
          CloseDatabase(Database);
          Result := cbrAbort;
        end;
      end else
      begin
        AliasParams := TStringList.Create;
        try
          GetAliasParams(szDbName, AliasParams);
          UserName := AliasParams.Values[szUSERNAME];
        finally
          AliasParams.Free;
        end;
        Password := '';
        if Assigned(LoginDialogExProc) then
          if LoginDialogExProc(szDbName, UserName, Password, True) then
          begin
            AnsiToNative(Locale, Password, szPassword, SizeOf(szPassword) - 1);
            bCallbackToClose := False;
          end
          else
            Result :=cbrAbort;
      end
    end else
    begin
      Database := FindDatabase(szDbName);
      if Assigned(Database) and (hDB = Database.Handle) then
        CloseDatabase(Database);
    end;
  except
    Result := cbrAbort;
  end;
end;

procedure TSession.DBNotification(DBEvent: TDatabaseEvent; const Param);
begin
  if Assigned(FOnDBNotify) then FOnDBNotify(DBEvent, Param);
end;

procedure TSession.DeleteAlias(const Name: string);
begin
  InternalDeleteAlias(Name, ConfigMode, True);
end;

procedure TSession.DeleteDriver(const Name: string);
begin
  DBNotification(dbDeleteDriver, Pointer(Name));
  LockSession;
  try
    DbiDeleteDriver(nil, PChar(StrToOem(Name)), False);
  finally
    UnlockSession;
  end;
end;

procedure TSession.DeleteConfigPath(const Path, Node: string);
var
  CfgPath: string;
begin
  CfgPath := Format(Path, [Node]);
  if DbiCfgPosition(nil, PChar(CfgPath)) = 0 then
    Check(DbiCfgDropRecord(nil, PChar(CfgPath)));
end;

procedure TSession.DropConnections;
var
  I: Integer;
begin
  for I := FDatabases.Count - 1 downto 0 do
    with TDatabase(FDatabases[I]) do
      if Temporary and (FRefCount = 0) then Free;
end;

function TSession.FindDatabase(const DatabaseName: string): TDatabase;
var
  I: Integer;
begin
  for I := 0 to FDatabases.Count - 1 do
  begin
    Result := FDatabases[I];
    if ((Result.DatabaseName <> '') or Result.Temporary) and
      (AnsiCompareText(Result.DatabaseName, DatabaseName) = 0) then Exit;
  end;
  Result := nil;
end;

function TSession.DoFindDatabase(const DatabaseName: string;
  AOwner: TComponent): TDatabase;
var
  I: Integer;
begin
  if AOwner <> nil then
    for I := 0 to FDatabases.Count - 1 do
    begin
      Result := FDatabases[I];
      if (Result.Owner = AOwner) and (Result.HandleShared) and
        (AnsiCompareText(Result.DatabaseName, DatabaseName) = 0) then Exit;
    end;
  Result := FindDatabase(DatabaseName);
end;

function TSession.FindDatabaseHandle(const DatabaseName: string): HDBIDB;
var
  I: Integer;
  DB: TDatabase;
begin
  for I := 0 to FDatabases.Count - 1 do
  begin
    DB := FDatabases[I];
    if (DB.Handle <> nil) and
       (AnsiCompareText(DB.DatabaseName, DatabaseName) = 0) and
       DB.HandleShared then
    begin
      Result := DB.Handle;
      Exit;
    end;
  end;
  Result := nil;
end;

function TSession.GetActive: Boolean;
begin
  Result := FHandle <> nil;
end;

function TSession.GetAliasDriverName(const AliasName: string): string;
var
  Desc: DBDesc;
begin
  LockSession;
  try
    if DbiGetDatabaseDesc(PChar(StrToOem(AliasName)), @Desc) <> 0 then
      DatabaseErrorFmt(SInvalidAliasName, [AliasName]);
  finally
    UnlockSession;
  end;
  if Desc.szDBType[sizeOf(Desc.szDBType) - 1] <> #0 then
    Desc.szDBType[sizeOf(Desc.szDBType) - 1] := #0;
  OemToChar(Desc.szDBType, Desc.szDBType);
  Result := Desc.szDBType;
end;

procedure TSession.GetAliasNames(List: TStrings);
var
  Cursor: HDBICur;
  Desc: DBDesc;
begin
  List.BeginUpdate;
  try
    List.Clear;
    LockSession;
    try
      Check(DbiOpenDatabaseList(Cursor));
    finally
      UnlockSession;
    end;
    try
      while DbiGetNextRecord(Cursor, dbiNOLOCK, @Desc, nil) = 0 do
      begin
        OemToChar(Desc.szName, Desc.szName);
        List.Add(Desc.szName);
      end;
    finally
      DbiCloseCursor(Cursor);
    end;
  finally
    List.EndUpdate;
  end;
end;

procedure TSession.GetAliasParams(const AliasName: string; List: TStrings);
var
  SAlias: DBIName;
  Desc: DBDesc;
begin
  List.BeginUpdate;
  try
    List.Clear;
    StrPLCopy(SAlias, AliasName, SizeOf(SAlias) - 1);
    CharToOEM(SAlias, SAlias);
    LockSession;
    try
      Check(DbiGetDatabaseDesc(SAlias, @Desc));
    finally
      UnlockSession;
    end;
    if Desc.szDBType[sizeOf(Desc.szDBType) - 1] <> #0 then
      Desc.szDBType[sizeOf(Desc.szDBType) - 1] := #0;
    if StrIComp(Desc.szDbType, szCFGDBSTANDARD) = 0 then
    begin
      GetConfigParams('\DATABASES\%s\DB INFO', SAlias, List);
      List.Values[szCFGDBTYPE] := '';
    end
    else
      GetConfigParams('\DATABASES\%s\DB OPEN', SAlias, List);
  finally
    List.EndUpdate;
  end;
end;

procedure TSession.GetConfigParams(const Path, Section: string; List: TStrings);
var
  Cursor: HDBICur;
  ConfigDesc: CFGDesc;
begin
  LockSession;
  try
    Check(DbiOpenCfgInfoList(nil, dbiREADONLY, cfgPERSISTENT, PChar(Format(Path,
      [Section])), Cursor));
  finally
    UnlockSession;
  end;
  try
    while DbiGetNextRecord(Cursor, dbiNOLOCK, @ConfigDesc, nil) = 0 do
      with ConfigDesc do
      begin
        OemToChar(szValue, szValue);
        List.Add(Format('%s=%s', [szNodeName, szValue]));
      end;
  finally
    DbiCloseCursor(Cursor);
  end;
end;

function TSession.GetDatabase(Index: Integer): TDatabase;
begin
  Result := FDatabases[Index];
end;

function TSession.GetDatabaseCount: Integer;
begin
  Result := FDatabases.Count;
end;

procedure TSession.GetDatabaseNames(List: TStrings);
var
  I: Integer;
  Names: TStringList;
begin
  Names := TStringList.Create;
  try
    Names.Sorted := True;
    GetAliasNames(Names);
    for I := 0 to FDatabases.Count - 1 do
      with TDatabase(FDatabases[I]) do
        if not IsDirectory(DatabaseName) then Names.Add(DatabaseName);
    List.Assign(Names);
  finally
    Names.Free;
  end;
end;

procedure TSession.GetDriverNames(List: TStrings);
var
  Cursor: HDBICur;
  Name: DBINAME;
begin
  List.BeginUpdate;
  try
    List.Clear;
    List.Add(szCFGDBSTANDARD);
    LockSession;
    try
      Check(DbiOpenDriverList(Cursor));
    finally
      UnlockSession;
    end;
    try
      while DbiGetNextRecord(Cursor, dbiNOLOCK, @Name, nil) = 0 do
        if not IsStandardType(Name) then
        begin
          OemToChar(Name, Name);
          List.Add(Name);
        end;
    finally
      DbiCloseCursor(Cursor);
    end;
  finally
    List.EndUpdate;
  end;
end;

procedure TSession.GetDriverParams(const DriverName: string;
  List: TStrings);
begin
  List.BeginUpdate;
  try
    List.Clear;
    if CompareText(DriverName, szCFGDBSTANDARD) = 0 then
    begin
      List.Add(Format('%s=', [szCFGDBPATH]));
      List.Add(Format('%s=%s', [szCFGDBDEFAULTDRIVER, szPARADOX]));
      List.Add(Format('%s=%s', [szCFGDBENABLEBCD, szCFGFALSE]));
    end
    else
      GetConfigParams('\DRIVERS\%s\DB OPEN', StrToOem(DriverName), List);
  finally
    List.EndUpdate;
  end;
end;

function TSession.GetHandle: HDBISes;
begin
  if FHandle <> nil then
    Check(DbiSetCurrSession(FHandle))
  else
    SetActive(True);
  Result := FHandle;
end;

function TSession.GetNetFileDir: string;
var
  Length: Word;
  Buffer: DBIPATH;
begin
  if Active and not (csWriting in ComponentState) then
  begin
    LockSession;
    try
      Check(DbiGetProp(HDBIOBJ(FHandle), sesNETFILE, @Buffer, SizeOf(Buffer),
        Length));
    finally
      UnLockSession;
    end;
    NativeToAnsi(nil, Buffer, Result);
  end else
    Result := FNetFileDir;
  Result := AnsiUpperCaseFileName(Result);
end;

function TSession.GetPrivateDir: string;
var
  SessionInfo: SESInfo;
begin
  if Active and not (csWriting in ComponentState) then
  begin
    LockSession;
    try
      Check(DbiGetSesInfo(SessionInfo));
    finally
      UnlockSession;
    end;
    NativeToAnsi(nil, SessionInfo.szPrivDir, Result);
  end else
    Result := FPrivateDir;
  Result := AnsiUpperCaseFileName(Result);
end;

function TSession.GetPassword: Boolean;
begin
  if Assigned(FOnPassword) then
  begin
    Result := False;
    FOnPassword(Self, Result)
  end else if Assigned(DB.PasswordDialog) then
    Result := DB.PasswordDialog(Self as IDBSession)
  else
    Result := False;  
end;

procedure TSession.GetTableNames(const DatabaseName, Pattern: string;
  Extensions, SystemTables: Boolean; List: TStrings);
var
  Database: TDatabase;
  Cursor: HDBICur;
  WildCard: PChar;
  Name: string;
  SPattern: DBITBLNAME;
  Desc: TBLBaseDesc;
begin
  List.BeginUpdate;
  try
    List.Clear;
    Database := OpenDatabase(DatabaseName);
    try
      WildCard := nil;
      if Pattern <> '' then
        WildCard := AnsiToNative(Database.Locale, Pattern, SPattern,
          SizeOf(SPattern) - 1);
      Check(DbiOpenTableList(Database.Handle, False, SystemTables,
        WildCard, Cursor));
      try
        while DbiGetNextRecord(Cursor, dbiNOLOCK, @Desc, nil) = 0 do
          with Desc do
          begin
            if Extensions and (szExt[0] <> #0) then
              StrCat(StrCat(szName, '.'), szExt);
            NativeToAnsi(Database.Locale, szName, Name);
            List.Add(Name);
          end;
      finally
        DbiCloseCursor(Cursor);
      end;
    finally
      CloseDatabase(Database);
    end;
  finally
    List.EndUpdate;
  end;
end;

procedure TSession.GetFieldNames(const DatabaseName, TableName: string;
  List: TStrings);
var
  Database: TDatabase;
  Cursor: HDBICur;
  Name: string;
  Desc: FLDDesc;
begin
  List.BeginUpdate;
  try
    List.Clear;
    Database := OpenDatabase(DatabaseName);
    try
      Check(DbiOpenFieldList(Database.Handle, PChar(TableName), '', False, Cursor));
      try
        while DbiGetNextRecord(Cursor, dbiNOLOCK, @Desc, nil) = 0 do
          with Desc do
          begin
            NativeToAnsi(Database.Locale, szName, Name);
            List.Add(Name);
          end;
      finally
        DbiCloseCursor(Cursor);
      end;
    finally
      CloseDatabase(Database);
    end;
  finally
    List.EndUpdate;
  end;
end;

procedure TSession.GetStoredProcNames(const DatabaseName: string; List: TStrings);
var
  Database: TDatabase;
  Cursor: HDBICur;
  Name: string;
  Desc: SPDesc;
begin
  List.BeginUpdate;
  try
    List.Clear;
    Database := OpenDatabase(DatabaseName);
    try
      Check(DbiOpenSPList(Database.Handle, False, True, nil, Cursor));
      try
        while DbiGetNextRecord(Cursor, dbiNOLOCK, @Desc, nil) = 0 do
          with Desc do
          begin
            NativeToAnsi(Database.Locale, szName, Name);
            List.Add(Name);
          end;
      finally
        DbiCloseCursor(Cursor);
      end;
    finally
      CloseDatabase(Database);
    end;
  finally
    List.EndUpdate;
  end;
end;

procedure TSession.InitializeBDE;
var
  Status: DBIResult;
  Env: DbiEnv;
  ClientHandle: hDBIObj;
  SetCursor: Boolean;
begin
  SetCursor := (GetCurrentThreadID = MainThreadID) and (DBScreen.Cursor = dcrDefault);
  if SetCursor then
    DBScreen.Cursor := dcrHourGlass;
  try
    FillChar(Env, SizeOf(Env), 0);
    StrPLCopy(Env.szLang, SIDAPILangID, SizeOf(Env.szLang) - 1);
    Status := DbiInit(@Env);
    if (Status <> DBIERR_NONE) and (Status <> DBIERR_MULTIPLEINIT) then
      Check(Status);
    Check(DbiGetCurrSession(FHandle));
    if DbiGetObjFromName(objCLIENT, nil, ClientHandle) = 0 then
      DbiSetProp(ClientHandle, Integer(clSQLRESTRICT), GDAL);
    if IsLibrary then
      DbiRegisterCallback(nil, cbDETACHNOTIFY, 0, 0, nil, DLLDetachCallBack);
  finally
    if SetCursor and (DBScreen.Cursor = dcrHourGlass) then
      DBScreen.Cursor := dcrDefault;
  end;
end;

procedure TSession.InternalAddAlias(const Name, Driver: string; List: TStrings;
  CfgMode: TConfigMode; RestoreMode: Boolean);
var
  Params: string;
  DrvName: string;
  CfgModeSave: TConfigMode;
begin
  Params := StringListToParams(List);
  DrvName := List.Values[szCFGDBDEFAULTDRIVER];
  if (DrvName = '') then
  begin
    if (CompareText(Driver, szCFGDBSTANDARD) = 0) then
      DrvName := szPARADOX else
      DrvName := Driver;
  end;
  LockSession;
  try
    CfgModeSave := ConfigMode;
    try
      CheckConfigMode(CfgMode);
      Check(DbiAddAlias(nil, PChar(StrToOem(Name)), PChar(StrToOem(DrvName)), PChar(Params), Bool(-1)));
    finally
      if RestoreMode then ConfigMode := CfgModeSave;
    end;
  finally
    UnlockSession;
  end;
  DBNotification(dbAddAlias, Pointer(Name));
end;

procedure TSession.InternalDeleteAlias(const Name: string;
  CfgMode: TConfigMode; RestoreMode: Boolean);
var
  CfgModeSave: TConfigMode;
begin
  DBNotification(dbDeleteAlias, Pointer(Name));
  LockSession;
  try
    CfgModeSave := ConfigMode;
    try
      CheckConfigMode(CfgMode);
      DeleteConfigPath('\DATABASES\%s', StrToOem(Name));
    finally
      if RestoreMode then ConfigMode := cfgModeSave;
    end;
  finally
    UnlockSession;
  end;
end;

function TSession.IsAlias(const Name: string): Boolean;
begin
  LockSession;
  try
    Result := (Name <> '') and
      (DbiCfgPosition(nil, PChar(Format('\DATABASES\%s', [StrToOem(Name)]))) = 0);
  finally
    UnlockSession;
  end;
end;

procedure TSession.Loaded;
begin
  inherited Loaded;
  try
    if AutoSessionName then SetSessionNames;
    if FStreamedActive then SetActive(True);
  except
    if csDesigning in ComponentState then
      ApplicationHandleException(Self)
    else
      raise;
  end;
end;

procedure TSession.LockSession;
begin
  if FLockCount = 0 then
  begin
    EnterCriticalSection(FCSect);
    Inc(FLockCount);
    MakeCurrent;
  end
  else
    Inc(FLockCount);
end;

procedure TSession.UnLockSession;
begin
  Dec(FLockCount);
  if FLockCount = 0 then
    LeaveCriticalSection(FCSect);
end;

procedure TSession.MakeCurrent;
begin
  if FHandle <> nil then
    Check(DbiSetCurrSession(FHandle))
  else
    SetActive(True);
end;

procedure TSession.ModifyAlias(Name: string; List: TStrings);
var
  DriverName: string;
  OemName: string;
  CfgModeSave: TConfigMode;
begin
  LockSession;
  try
    CfgModeSave := ConfigMode;
    try
      CheckConfigMode(ConfigMode);
      DriverName := GetAliasDriverName(Name);
      OemName := StrToOem(Name);
      ModifyConfigParams('\DATABASES\%s\DB INFO', OemName, List);
      if CompareText(DriverName, szCFGDBSTANDARD) <> 0 then
        ModifyConfigParams('\DATABASES\%s\DB OPEN', OemName, List);
    finally
      ConfigMode := CfgModeSave;
    end;
  finally
    UnLockSession;
  end;
end;

procedure TSession.ModifyDriver(Name: string; List: TStrings);
var
  CfgModeSave: TConfigMode;
  OemName: string;
begin
  LockSession;
  try
    CfgModeSave := ConfigMode;
    try
      CheckConfigMode(ConfigMode);
      OemName := StrToOem(Name);
      ModifyConfigParams('\DRIVERS\%s\INIT', OemName, List);
      if IsStandardType(PChar(Name)) then
        ModifyConfigParams('\DRIVERS\%s\TABLE CREATE', OemName, List) else
        ModifyConfigParams('\DRIVERS\%s\DB OPEN', OemName, List);
    finally
      ConfigMode := CfgModeSave;
    end;
  finally
    UnLockSession;
  end;
end;

procedure TSession.ModifyConfigParams(const Path, Node: string; List: TStrings);
var
  I, J, C: Integer;
  Params: TStrings;
begin
  Params := TStringList.Create;
  try
    GetConfigParams(Path, Node, Params);
    C := 0;
    for I := 0 to Params.Count - 1 do
    begin
      J := List.IndexOfName(Params.Names[I]);
      if J >= 0 then
      begin
        Params[I] := List[J];
        Inc(C);
      end;
    end;
    if C > 0 then SetConfigParams(Path, Node, Params);
  finally
    Params.Free;
  end;
end;

procedure TSession.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if AutoSessionName and (Operation = opInsert) then
    if AComponent is TDBDataSet then
      TDBDataSet(AComponent).FSessionName := Self.SessionName
    else if AComponent is TDatabase then
      TDatabase(AComponent).FSession := Self;
end;

procedure TSession.Open;
begin
  SetActive(True);
end;

function TSession.DoOpenDatabase(const DatabaseName: string; AOwner: TComponent): TDatabase;
var
  TempDatabase: TDatabase;
begin
  Result := nil;
  LockSession;
  try
    TempDatabase := nil;
    try
      Result := DoFindDatabase(DatabaseName, AOwner);
      if Result = nil then
      begin
        TempDatabase := TDatabase.Create(Self);
        TempDatabase.DatabaseName := DatabaseName;
        TempDatabase.KeepConnection := FKeepConnections;
        TempDatabase.Temporary := True;
        Result := TempDatabase;
      end;
      Result.Open;
      Inc(Result.FRefCount);
    except
      TempDatabase.Free;
      raise;
    end;
  finally
    UnLockSession;
  end;
end;

function TSession.OpenDatabase(const DatabaseName: string): TDatabase;
begin
  Result := DoOpenDatabase(DatabaseName, nil);
end;

function TSession.SessionNameStored: Boolean;
begin
  Result := not FAutoSessionName;
end;

procedure TSession.LoadSMClient(DesignTime: Boolean);
var
  FM: THandle;
  ClientName: string;
  FOldCBFunc: pfDBICallBack;
begin
  try
    if Assigned(FSMClient) or (DbiGetCallBack(nil, cbTrace, nil, nil, nil,
      FOldCBFunc) = DBIERR_NONE) or FSMLoadFailed then Exit;
    if not DesignTime then
    begin
      FM := OpenFileMapping(FILE_MAP_READ, False, 'SMBuffer'); { Do not localize }
      if FM = 0 then Exit;
      CloseHandle(FM);
    end;
    if not Assigned(FSMClient) then
    begin
      if not Assigned(DefaultSession.FSMClient) then
        CoCreateInstance(Class_SMClient, nil, CLSCTX_INPROC_SERVER, ISMClient,
          DefaultSession.FSMClient);
      if not FDefault then
        FSMClient := DefaultSession.FSMClient;
    end;
    if Assigned(FSMClient) then
    begin
      ClientName := DBApplication.Title;
      if ClientName = '' then  ClientName := SUntitled;
      if not FDefault then
        ClientName := Format('%s.%s', [ClientName, SessionName]);
      if FSMClient.RegisterClient(Integer(FHandle), PChar(ClientName), Self,
         @TSession.SMClientSignal) then
      begin
        GetMem(FSMBuffer, smTraceBufSize);
        FCallbacks.Add(TBDECallback.Create(Self, nil, cbTRACE,
          FSMBuffer, smTraceBufSize, SqlTraceCallBack, False));
      end else
        FSMClient := nil;
      FSMLoadFailed := FSMClient = nil;;
    end;
  except
    FSMLoadFailed := True;
  end;
end;

procedure TSession.RegisterCallbacks(Value: Boolean);
var
  I: Integer;
begin
  if Value then
  begin
    { Do not register any callbacks if we are not in the MainThread }
    if GetCurrentThreadID <> MainThreadID then Exit;
    if FSQLHourGlass then
      FCallbacks.Add(TBDECallback.Create(Self, nil, cbSERVERCALL,
        @FCBSCType, SizeOf(CBSCType), ServerCallBack, False));

    FCallbacks.Add(TBDECallback.Create(Self, nil, cbDBLOGIN,
      @FCBDBLogin, SizeOf(TCBDBLogin), DBLoginCallBack, False));
  end else
  begin
    for I := FCallbacks.Count - 1 downto 0 do
      TBDECallback(FCallbacks[I]).Free;
    FCallbacks.Clear;
    if Assigned(FSMClient) then
    try
      FreeMem(FSMBuffer, smTraceBufSize);
      FSMClient := nil;
    except
    end;
  end;
end;

procedure TSession.RemoveDatabase(Value: TDatabase);
begin
  FDatabases.Remove(Value);
  DBNotification(dbRemove, Value);
end;

procedure TSession.RemoveAllPasswords;
begin
  LockSession;
  try
    DbiDropPassword(nil);
  finally
    UnlockSession;
  end;
end;

procedure TSession.RemovePassword(const Password: string);
var
  Buffer: array[0..255] of Char;
begin
  LockSession;
  try
    if Password <> '' then
      DbiDropPassword(AnsiToNative(Locale, Password, Buffer, SizeOf(Buffer)-1));
  finally
    UnlockSession;
  end;
end;

procedure TSession.SaveConfigFile;
var
  CfgModeSave: TConfigMode;
begin
  CfgModeSave := ConfigMode;
  try
    ConfigMode := cmPersistent;
    Check(DbiCfgSave(nil, nil, Bool(-1)));
  finally
    ConfigMode := CfgModeSave;
  end;
end;

function TSession.ServerCallBack(CBInfo: Pointer): CBRType;
begin
  Result := cbrUSEDEF;
  if (GetCurrentThreadID <> MainThreadID) then Exit;
  if (FCBSCType = cbscSQL) then
  begin
    if TimerID = 0 then
      TimerID := SetTimer(0, 0, SQLDelay, @TimerCallBack);
    if Assigned(DBScreen) and (DBScreen.Cursor <> dcrSQLWait) then
      DBScreen.Cursor := dcrSQLWait;
    StartTime := GetTickCount;
  end;
end;

procedure TSession.SetActive(Value: Boolean);
begin
  if csReading in ComponentState then
    FStreamedActive := Value
  else
    if Active <> Value then
      StartSession(Value);
end;

procedure TSession.SetAutoSessionName(Value: Boolean);
begin
  if Value <> FAutoSessionName then
  begin
    if Value then
    begin
      CheckInActive;
      ValidateAutoSession(Owner, True);
      FSessionNumber := -1;
      EnterCriticalSection(FCSect);
      try
        with Sessions do
        begin
          FSessionNumber := FSessionNumbers.OpenBit;
          FSessionNumbers[FSessionNumber] := True;
        end;
      finally
        LeaveCriticalSection(FCSect);
      end;
      UpdateAutoSessionName;
    end
    else
    begin
      if FSessionNumber > -1 then
      begin
        EnterCriticalSection(FCSect);
        try
          Sessions.FSessionNumbers[FSessionNumber] := False;
        finally
          LeaveCriticalSection(FCSect);
        end;
      end;
    end;
    FAutoSessionName := Value;
  end;
end;

function TSession.GetConfigMode: TConfigMode;
begin
  LockSession;
  try
    Result := TConfigMode(Byte(GetIntProp(FHandle, sesCFGMODE2)));
  finally
    UnlockSession;
  end;
end;

procedure TSession.SetConfigMode(Value: TConfigMode);
begin
  LockSession;
  try
    Check(DbiSetProp(hDBIObj(FHandle), sesCFGMODE2, Longint(Byte(Value))));
  finally
    UnlockSession;
  end;
end;

procedure TSession.SetConfigParams(const Path, Node: string; List: TStrings);
var
  ParamList: TParamList;
begin
  ParamList := TParamList.Create(List);
  try
    with ParamList do
      Check(DbiCfgModifyRecord(nil, PChar(Format(Path, [Node])), FieldCount,
        PFLDDesc(FieldDescs), Buffer));
  finally
    ParamList.Free;
  end;
end;

procedure TSession.SetName(const NewName: TComponentName);
begin
  inherited SetName(NewName);
  if FAutoSessionName then UpdateAutoSessionName;
end;

procedure TSession.SetNetFileDir(const Value: string);
var
  Buffer: DBIPATH;
begin
  if Active then
  begin
    LockSession;
    try
      Check(DbiSetProp(HDBIOBJ(Handle), sesNETFILE, Longint(AnsiToNative(nil,
        Value, Buffer, SizeOf(Buffer) - 1))));
    finally
      UnLockSession;
    end;
  end;
  FNetFileDir := Value;
end;

procedure TSession.SetPrivateDir(const Value: string);
var
  Buffer: DBIPATH;
begin
  if Active then
  begin
    LockSession;
    try
      Check(DbiSetPrivateDir(AnsiToNative(nil, Value, Buffer,
        SizeOf(Buffer) - 1)));
    finally
      UnlockSession;
    end;
  end;
  FPrivateDir := Value;
end;

procedure TSession.SetSessionName(const Value: string);
var
  Ses: TSession;
begin
  if FAutoSessionName and not FUpdatingAutoSessionName then
    DatabaseError(SAutoSessionActive, Self);
  CheckInActive;
  if Value <> '' then
  begin
    Ses := Sessions.FindSession(Value);
    if not ((Ses = nil) or (Ses = Self)) then
      DatabaseErrorFmt(SDuplicateSessionName, [Value], Self);
  end;
  FSessionName := Value
end;

procedure TSession.SetSessionNames;
var
  I: Integer;
  Component: TComponent;
begin
  if Owner <> nil then
    for I := 0 to Owner.ComponentCount - 1 do
    begin
      Component := Owner.Components[I];
      if (Component is TDBDataSet) and
        (AnsiCompareText(TDBDataSet(Component).SessionName, Self.SessionName) <> 0) then
        TDBDataSet(Component).SessionName := Self.SessionName
      else if (Component is TDataBase) and
        (AnsiCompareText(TDatabase(Component).SessionName, Self.SessionName) <> 0) then
        TDataBase(Component).SessionName := Self.SessionName
    end;
end;

procedure TSession.SetTraceFlags(Value: TTraceFlags);
var
  I: Integer;
begin
  FTraceFlags := Value;
  for I := FDatabases.Count - 1 downto 0 do
    with TDatabase(FDatabases[I]) do
      TraceFlags := FTraceFlags;
end;

procedure TSession.SMClientSignal(Sender: TObject; Data: Integer);
begin
  SetTraceFlags(TTraceFlags(Word(Data)));
end;

function TSession.SqlTraceCallBack(CBInfo: Pointer): CBRType;
var
  Data: Pointer;
begin
  try
    Data := @PTraceDesc(CBInfo).pszTrace;
    FSMClient.AddStatement(Data, StrLen(Data));
  except
    SetTraceFlags([]);
  end;
  Result := cbrUSEDEF;
end;

procedure TSession.StartSession(Value: Boolean);
var
  I: Integer;
begin
  EnterCriticalSection(FCSect);
  try
    if Value then
    begin
      if Assigned(FOnStartup) then FOnStartup(Self);
      if FSessionName = '' then DatabaseError(SSessionNameMissing, Self);
      if (DefaultSession <> Self) then DefaultSession.Active := True;
      if FDefault then
        InitializeBDE
      else
        Check(DbiStartSession(nil, FHandle, nil));
      try
        RegisterCallbacks(True);
        if FNetFileDir <> '' then SetNetFileDir(FNetFileDir);
        if FPrivateDir <> '' then SetPrivateDir(FPrivateDir);
        ConfigMode := cmAll;
        CallBDEInitProcs;
      except
        StartSession(False);
        raise;
      end;
    end else
    begin
      DbiSetCurrSession(FHandle);
      for I := FDatabases.Count - 1 downto 0 do
        with TDatabase(FDatabases[I]) do
          if Temporary then Free else Close;
      RegisterCallbacks(False);
      if FDefault then
      begin
        if not FDLLDetach then
        begin
          if IsLibrary then
          begin
            DbiRegisterCallback(nil, cbDETACHNOTIFY, 0, 0, @DLLDetachCallBack, nil);
            DbiDLLExit;
          end;
          DbiExit;
        end;
      end
      else
      begin
        Check(DbiCloseSession(FHandle));
        DbiSetCurrSession(DefaultSession.FHandle);
      end;
      FHandle := nil;
    end;
  finally
    LeaveCriticalSection(FCSect);
  end;
end;

procedure TSession.UpdateAutoSessionName;
begin
  FUpdatingAutoSessionName := True;
  try
    SessionName := Format('%s_%d', [Name, FSessionNumber + 1]);
  finally
    FUpdatingAutoSessionName := False;
  end;
  SetSessionNames;
end;

procedure TSession.ValidateAutoSession(AOwner: TComponent; AllSessions: Boolean);
var
  I: Integer;
  Component: TComponent;
begin
  if AOwner <> nil then
    for I := 0 to AOwner.ComponentCount - 1 do
    begin
      Component := AOwner.Components[I];
      if (Component <> Self) and (Component is TSession) then
        if AllSessions then DatabaseError(SAutoSessionExclusive, Self)
        else if TSession(Component).AutoSessionName then
          DatabaseErrorFmt(SAutoSessionExists, [Component.Name]);
    end;
end;

{ TParamList }

constructor TParamList.Create(Params: TStrings);
var
  I, P, FieldNo: Integer;
  BufPtr: PChar;
  S: string;
begin
  for I := 0 to Params.Count - 1 do
  begin
    S := Params[I];
    P := Pos('=', S);
    if P <> 0 then
    begin
      Inc(FFieldCount);
      Inc(FBufSize, Length(S) - P + 1);
    end;
  end;
  if FFieldCount > 0 then
  begin
    SetLength(FFieldDescs, FFieldCount);
    FBuffer := AllocMem(FBufSize);
    FieldNo := 0;
    BufPtr := FBuffer;
    for I := 0 to Params.Count - 1 do
    begin
      S := Params[I];
      P := Pos('=', S);
      if P <> 0 then
        with FFieldDescs[FieldNo] do
        begin
          Inc(FieldNo);
          iFldNum := FieldNo;
          StrPLCopy(szName, Copy(S, 1, P - 1), SizeOf(szName) - 1);
          iFldType := fldZSTRING;
          iOffset := BufPtr - FBuffer;
          iLen := Length(S) - P + 1;
          StrCopy(BufPtr, PChar(Copy(S, P + 1, 255)));
          CharToOem(BufPtr, BufPtr);
          Inc(BufPtr, iLen);
        end;
    end;
  end;
end;

destructor TParamList.Destroy;
begin
  DisposeMem(FBuffer, FBufSize);
end;

{ TDatabase }

constructor TDatabase.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  if FSession = nil then
    if AOwner is TSession then
      FSession := TSession(AOwner) else
      FSession := DefaultSession;
  SessionName := FSession.SessionName;
  FSession.AddDatabase(Self);
  FParams := TStringList.Create;
  TStringList(FParams).OnChanging := ParamsChanging;
  LoginPrompt := True;
  FKeepConnection := True;
  FLocale := FSession.Locale;
  FTransIsolation := tiReadCommitted;
end;

destructor TDatabase.Destroy;
begin
  Destroying;
  Close;
  if FSession <> nil then
    FSession.RemoveDatabase(Self);
  inherited Destroy;
  FParams.Free;
  FStmtList.Free;
end;

procedure TDatabase.ApplyUpdates(const DataSets: array of TDBDataSet);
var
  I: Integer;
  DS: TDBDataSet;
begin
  StartTransaction;
  try
    for I := 0 to High(DataSets) do
    begin
      DS := DataSets[I];
      if DS.Database <> Self then
        DatabaseError(Format(SUpdateWrongDB, [DS.Name, Name]));
      DataSets[I].ApplyUpdates;
    end;
    Commit;
  except
    Rollback;
    raise;
  end;
  for I := 0 to High(DataSets) do
    DataSets[I].CommitUpdates;
end;

type
  PStmtInfo = ^TStmtInfo;
  TStmtInfo = packed record
    HashCode: Integer;
    StmtHandle: HDBIStmt;
    SQLText: string;
  end;

procedure TDatabase.ClearStatements;
var
  i: Integer;
begin
  if Assigned(FStmtList) then
  begin
    for i := 0 to FStmtList.Count - 1 do
    begin
      DbiQFree(PStmtInfo(FStmtList[i]).StmtHandle);
      Dispose(PStmtInfo(FStmtList[i]));
    end;
    FStmtList.Clear;
  end;
end;

function TDatabase.Execute(const SQL: string; Params: TParams = nil;
  Cache: Boolean = False; Cursor: phDBICur = nil): Integer;

  function GetStmtInfo(SQL: PChar): PStmtInfo;

    function GetHashCode(Str: PChar): Integer;
    var
      Off, Len, Skip, I: Integer;
    begin
      Result := 0;
      Off := 1;
      Len := StrLen(Str);
      if Len < 16 then
        for I := (Len - 1) downto 0 do
        begin
          Result := (Result * 37) + Ord(Str[Off]);
          Inc(Off);
        end
      else
      begin
        { Only sample some characters }
        Skip := Len div 8;
        I := Len - 1;
        while I >= 0 do
        begin
          Result := (Result * 39) + Ord(Str[Off]);
          Dec(I, Skip);
          Inc(Off, Skip);
        end;
      end;
    end;

  var
    HashCode, i: Integer;
    Info: PStmtInfo;
  begin
    if not Assigned(FStmtList) then
      FStmtList := TList.Create;
    Result := nil;
    HashCode := GetHashCode(SQL);
    for i := 0 to FStmtList.Count - 1 do
    begin
      Info := PStmtInfo(FStmtList[i]);
      if (Info.HashCode = HashCode) and
         (AnsiStrIComp(PChar(Info.SQLText), SQL) = 0) then
      begin
        Result := Info;
        break;
      end;
    end;
    if not Assigned(Result) then
    begin
      New(Result);
      FStmtList.Add(Result);
      FillChar(Result^, SizeOf(Result^), 0);
      Result.HashCode := HashCode;
    end;
  end;

  function GetStatementHandle: HDBIStmt;
  var
    Info: PStmtInfo;
    Status: DBIResult;
  begin
    Info := nil;
    Result := nil;
    if Cache then
    begin
      Info := GetStmtInfo(PChar(SQL));
      Result := Info.StmtHandle;
    end;
    if not Assigned(Result) then
    begin
      Check(DbiQAlloc(Handle, qrylangSQL, Result));
      if Cursor <> nil then
        Check(DbiSetProp(hDbiObj(Result), stmtLIVENESS, Ord(wantCanned)));
      if not IsSQLBased then
      begin
        SetBoolProp(Result, stmtAUXTBLS, False);
        SetBoolProp(Result, stmtCANNEDREADONLY, True);
      end else
        SetBoolProp(Result, stmtUNIDIRECTIONAL, True);
      while True do
      begin
        Status := DbiQPrepare(Result, PChar(SQL));
        case Status of
        DBIERR_NONE: break;
        DBIERR_NOTSUFFTABLERIGHTS:
          if not FSession.GetPassword then DbiError(Status);
        else
          DbiError(Status);
        end;
      end;
      if Assigned(Info) then
      begin
        Info.SQLText := SQL;
        Info.StmtHandle := Result;
      end;
    end;
  end;

var
  StmtHandle: HDBIStmt;
  Len: Word;
begin
  Open;
  if Assigned(Params) and (Params.Count > 0) then
  begin
    StmtHandle := GetStatementHandle;
    try
      SetQueryParams(Self, StmtHandle, Params);
      Check(DbiQExec(StmtHandle, Cursor));
    finally
      if not Cache then DbiQFree(StmtHandle);
    end;
  end else
    Check(DbiQExecDirect(Handle, qrylangSQL, PChar(SQL), Cursor));
  if (Cursor = nil) and (DbiGetProp(hDBIObj(StmtHandle), stmtROWCOUNT,
                          @Result, SizeOf(Result), Len) <> 0) then
    Result := 0;
end;

procedure TDatabase.CheckActive;
begin
  if FHandle = nil then DatabaseError(SDatabaseClosed, Self);
end;

procedure TDatabase.CheckInactive;
begin
  if FHandle <> nil then
    if csDesigning in ComponentState then
      Close else
      DatabaseError(SDatabaseOpen, Self);
end;

procedure TDatabase.CheckDatabaseName;
begin
  if (FDatabaseName = '') and not Temporary then
    DatabaseError(SDatabaseNameMissing, Self);
end;

procedure TDatabase.CheckSessionName(Required: Boolean);
var
  NewSession: TSession;
begin
  if Required then
    NewSession := Sessions.List[FSessionName]
  else
    NewSession := Sessions.FindSession(FSessionName);
  if (NewSession <> nil) and (NewSession <> FSession) then
  begin
    if (FSession <> nil) then FSession.RemoveDatabase(Self);
    FSession := NewSession;
    FSession.FreeNotification(Self);
    FSession.AddDatabase(Self);
    try
      ValidateName(FDatabaseName);
    except
      FDatabaseName := '';
      raise;
    end;
  end;
  if Required then FSession.Active := True;
end;

procedure TDatabase.DoDisconnect;
begin
  if FHandle <> nil then
  begin
    ClearStatements;
    Session.DBNotification(dbClose, Self);
    CloseDataSets;
    if FLocaleLoaded then OsLdUnloadObj(FLocale);
    FLocaleLoaded := False;
    FLocale := DefaultSession.Locale;
    if not FAcquiredHandle then
      FSession.CloseDatabaseHandle(Self) else
      FAcquiredHandle := False;
    FSQLBased := False;
    FHandle := nil;
    FRefCount := 0;
    if FSessionAlias then
    begin
      FSession.InternalDeleteAlias(FDatabaseName, cmSession, True);
      FSessionAlias := False;
    end;
  end;
end;

procedure TDatabase.CloseDataSets;
begin
  while DataSetCount <> 0 do TDBDataSet(DataSets[DataSetCount-1]).Disconnect;
end;

procedure TDatabase.Commit;
begin
  CheckActive;
  EndTransaction(xendCOMMIT);
end;

procedure TDatabase.EndTransaction(TransEnd: EXEnd);
begin
  Check(DbiEndTran(FHandle, nil, TransEnd));
end;

function TDatabase.GetAliasName: string;
begin
  if FAliased then Result := FDatabaseType else Result := '';
end;

function TDatabase.GetConnected: Boolean;
begin
  Result := FHandle <> nil;
end;

function TDatabase.GetDataSet(Index: Integer): TDBDataSet;
begin
  Result := inherited GetDataSet(Index) as TDBDataSet;
end;

function TDatabase.GetDirectory: string;
var
  SDirectory: DBIPATH;
begin
  if Handle <> nil then
  begin
    Check(DbiGetDirectory(Handle, False, SDirectory));
    SetLength(Result, StrLen(SDirectory));
    OemToChar(SDirectory, PChar(Result));
  end else
    Result := '';
end;

procedure TDatabase.GetFieldNames(const TableName: string; List: TStrings);
begin
  if Assigned(FSession) then
    FSession.GetFieldNames(Self.DatabaseName, TableName, List);
end;

procedure TDatabase.GetTableNames(List: TStrings; SystemTables: Boolean = False);
begin
  if Assigned(FSession) then
    FSession.GetTableNames(Self.DatabaseName, '', False, SystemTables, List);
end;

function TDatabase.GetDriverName: string;
begin
  if FAliased then Result := '' else Result := FDatabaseType;
end;

procedure TDatabase.SetDatabaseFlags;
var
  Length: Word;
  Buffer: DBINAME;
  SupportsPseudoIndexes: Bool;
begin
  Check(DbiGetProp(HDBIOBJ(FHandle), dbDATABASETYPE, @Buffer,
    SizeOf(Buffer), Length));
  FSQLBased := StrIComp(Buffer, szCFGDBSTANDARD) <> 0;
  FPseudoIndexes := (DbiGetProp(HDBIOBJ(FHandle), Integer(drvPSEUDOINDEX),
    @SupportsPseudoIndexes, SizeOf(SupportsPseudoIndexes),
    Length) = DBIERR_NONE) and SupportsPseudoIndexes;
end;

function TDatabase.GetTraceFlags: TTraceFlags;
begin
  if Connected and IsSQLBased then
    Result := TTraceFlags(Word(GetIntProp(FHandle, dbTraceMode)))
  else
    Result := [];
end;

function TDatabase.GetObjectContext: IUnknown;
begin
  if Assigned(GetObjectContextProc) then
    Result := GetObjectContextProc
  else
    Result := nil;
end;

function TDatabase.GetInTransaction: Boolean;
var
  X: XInfo;
begin
  Result := (Handle <> nil) and (DbiGetTranInfo(Handle, nil, @X) = DBIERR_NONE)
    and (X.exState = xsActive);
end;

procedure TDatabase.Loaded;
begin
  inherited Loaded;
  if not StreamedConnected then CheckSessionName(False);
end;

procedure TDatabase.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FSession) and
    (FSession <> DefaultSession) then
  begin
    Close;
    SessionName := '';
  end;
end;

procedure TDatabase.LoadLocale;
var
  LName: DBIName;
  DBLocale: TLocale;
begin
  if IsSQLBased and (DbiGetLdNameFromDB(FHandle, nil, LName) = 0) and
    (OsLdLoadBySymbName(LName, DBLocale) = 0) then
  begin
    FLocale := DBLocale;
    FLocaleLoaded := True;
  end;
end;

procedure TDatabase.Login(LoginParams: TStrings);
var
  UserName, Password: string;
begin
  if Assigned(FOnLogin) then FOnLogin(Self, LoginParams) else
  begin
    UserName := LoginParams.Values[szUSERNAME];
    if Assigned(LoginDialogExProc) then
      if not LoginDialogExProc(DatabaseName, UserName, Password, False) then
        DatabaseErrorFmt(SLoginError, [DatabaseName]);
    LoginParams.Values[szUSERNAME] := UserName;
    LoginParams.Values[szPASSWORD] := Password;
  end;
end;

procedure TDatabase.CheckDatabaseAlias(var Password: string);
var
  Desc: DBDesc;
  Aliased: Boolean;
  DBName: string;
  DriverType: string;
  AliasParams: TStringList;
  LoginParams: TStringList;

  function NeedsDBAlias: Boolean;
  var
    I: Integer;
    PName: String;
  begin
    Result := not Aliased or ((FDatabaseType <> '') and
      (FDatabaseName <> FDatabaseType));
    for I := 0 to FParams.Count - 1 do
    begin
      if AliasParams.IndexOf(FParams[I]) > -1 then continue;
      PName := FParams.Names[I];
      if (CompareText(PName, szPASSWORD) = 0) then continue;
      if AliasParams.IndexOfName(PName) > -1 then
      begin
        Result := True;
        AliasParams.Values[PName] := FParams.Values[PName];
      end;
    end;
  end;

begin
  Password := '';
  FSessionAlias := False;
  AliasParams := TStringList.Create;
  try
    begin
      if FDatabaseType <> '' then
      begin
        DBName := FDatabaseType;
        Aliased := FAliased;
      end else
      begin
        DBName := FDatabaseName;
        Aliased := True;
      end;
      if Aliased then
      begin
        if DbiGetDatabaseDesc(PChar(StrToOem(DBName)), @Desc) <> 0 then Exit;
        if Desc.szDBType[sizeOf(Desc.szDBType) - 1] <> #0 then
          Desc.szDBType[sizeOf(Desc.szDBType) - 1] := #0;
        OemToChar(Desc.szDbType, Desc.szDbType);
        DriverType := Desc.szDbType;
        FSession.GetAliasParams(DBName, AliasParams);
      end else
      begin
        FSession.GetDriverParams(DBName, AliasParams);
        DriverType := FDatabaseType;
      end;
      if AliasParams.IndexOfName(szUSERNAME) <> -1 then
      begin
        if LoginPrompt then
        begin
          LoginParams := TStringList.Create;
          try
            if FParams.Values[szUSERNAME] = '' then
              FParams.Values[szUSERNAME] := AliasParams.Values[szUSERNAME];
            LoginParams.Values[szUSERNAME] := FParams.Values[szUSERNAME];
            Login(LoginParams);
            Password := LoginParams.Values[szPASSWORD];
            FParams.Values[szUSERNAME] := LoginParams.Values[szUSERNAME];
          finally
            LoginParams.Free;
          end;
        end else
          Password := FParams.Values[szPASSWORD];
      end;
    end;
    if NeedsDBAlias then
    begin
      FSession.InternalAddAlias(FDatabaseName, DriverType, AliasParams,
        cmSession, False);
      FSessionAlias := True;
    end;
  finally
    AliasParams.Free;
  end;
end;

function TDatabase.OpenFromExistingDB: Boolean;
begin
  Handle := FSession.FindDatabaseHandle(DatabaseName);
  FAcquiredHandle := False;
  Result := (Handle <> nil);
end;

procedure TDatabase.DoConnect;
const
  OpenModes: array[Boolean] of DbiOpenMode = (dbiReadWrite, dbiReadOnly);
  ShareModes: array[Boolean] of DbiShareMode = (dbiOpenShared, dbiOpenExcl);
var
  DBName: string;
  DBPassword: string;
  CfgModeSave: TConfigMode;
  OptParam: Pointer;
  OptFldDesc: pFldDesc;
  OptParamCount: Integer;
  ObjectContextDesc: FldDesc;
  OpenModeFlag: Word;
begin
  if FHandle = nil then
  begin
    CheckDatabaseName;
    CheckSessionName(True);
    if not (HandleShared and OpenFromExistingDB) then
    begin
      FSession.LockSession;
      try
        CfgModeSave := FSession.ConfigMode;
        try
          CheckDatabaseAlias(DBPassword);
          try
            if (FDatabaseType = '') and IsDirectory(FDatabaseName) then
              DBName := '' else
              DBName := StrToOem(FDatabaseName);
            OptParam := Pointer(GetObjectContext);
            OpenModeFlag := 0;
            if Assigned(OptParam) then
            begin
              OptParamCount := 1;
              ObjectContextDesc.iLen := sizeof(Pointer);
              ObjectContextDesc.iOffset := 0;
              StrCopy(ObjectContextDesc.szName, szMTXCONTEXTOBJ);
              OptFldDesc := @ObjectContextDesc;
              { Set a flag to indicate how bde will handle transactions started
               under MTS.  BDE will handle the case of
               (TransIsolation <> tiDirtyRead) and not IsSQLBased. }
              case TransIsolation of
                tiDirtyRead:      OpenModeFlag := OPENMODEFLAG_DIRTYREAD;
                tiReadCommitted:  OpenModeFlag := OPENMODEFLAG_READCOMMITTED;
                tiRepeatableRead: OpenModeFlag := OPENMODEFLAG_REPEATABLEREAD;
              end
            end
            else
            begin
              OptParamCount := 0;
              OptFldDesc := nil;
            end;
            Check(DbiOpenDatabase(Pointer(DBName), nil,
              DBIOpenMode(Integer(OpenModes[FReadOnly]) or OpenModeFlag),
              ShareModes[FExclusive], Pointer(StrToOem(DBPassword)), OptParamCount, OptFldDesc,
              OptParam, FHandle));
            if DBName = '' then SetDirectory(FDatabaseName);
            SetBoolProp(FHandle, dbUSESCHEMAFILE, True);
            SetBoolProp(FHandle, dbPARAMFMTQMARK, True);
            SetBoolProp(FHandle, dbCOMPRESSARRAYFLDDESC, True);
            SetDatabaseFlags;
            LoadLocale;
            if IsSQLBased then FSession.LoadSMClient(csDesigning in ComponentState);
            TraceFlags := FSession.FTraceFlags;
            Session.DBNotification(dbOpen, Self);
          except
            if FSessionAlias then
              FSession.InternalDeleteAlias(FDatabaseName, cmSession, False);
            raise;
          end;
        finally
          FSession.ConfigMode := CfgModeSave;
        end;
      finally
        FSession.UnlockSession;
      end;
    end;
  end;
end;

procedure TDatabase.ParamsChanging(Sender: TObject);
begin
  CheckInactive;
end;

procedure TDatabase.Rollback;
begin
  CheckActive;
  EndTransaction(xendABORT);
end;

procedure TDatabase.SetAliasName(const Value: string);
begin
  SetDatabaseType(Value, True);
end;

procedure TDatabase.SetDatabaseName(const Value: string);
begin
  if csReading in ComponentState then
    FDatabaseName := Value else
  if FDatabaseName <> Value then
  begin
    CheckInactive;
    ValidateName(Value);
    FDatabaseName := Value;
  end;
end;

procedure TDatabase.SetDatabaseType(const Value: string;
  Aliased: Boolean);
begin
  CheckInactive;
  FDatabaseType := Value;
  FAliased := Aliased;
end;

procedure TDatabase.SetDirectory(const Value: string);
begin
  if Handle <> nil then
    Check(DbiSetDirectory(Handle, Pointer(StrToOem(Value))));
end;

procedure TDatabase.SetDriverName(const Value: string);
begin
  SetDatabaseType(Value, False);
end;

procedure TDatabase.SetHandle(Value: HDBIDB);
var
  DBSession: HDBISes;
begin
  if Connected then Close;
  if Value <> nil then
  begin
    Check(DbiGetObjFromObj(HDBIObj(Value), objSESSION, HDBIObj(DBSession)));
    CheckDatabaseName;
    CheckSessionName(True);
    if FSession.Handle <> DBSession then
      DatabaseError(SDatabaseHandleSet, Self);
    FHandle := Value;
    SetDatabaseFlags;
    LoadLocale;
    Session.DBNotification(dbOpen, Self);
    FAcquiredHandle := True;
  end;
end;

procedure TDatabase.SetKeepConnection(Value: Boolean);
begin
  if FKeepConnection <> Value then
  begin
    FKeepConnection := Value;
    if not Value and (FRefCount = 0) then Close;
  end;
end;

procedure TDatabase.SetParams(Value: TStrings);
begin
  CheckInactive;
  FParams.Assign(Value);
end;

procedure TDatabase.SetSessionName(const Value: string);
begin
  if csReading in ComponentState then
    FSessionName := Value
  else
  begin
    CheckInactive;
    if FSessionName <> Value then
    begin
      FSessionName := Value;
      if not (csDestroying in ComponentState) then
        CheckSessionName(False);
    end;
  end;
end;

procedure TDatabase.SetTraceFlags(Value: TTraceFlags);
begin
  if Connected and IsSQLBased then
    DbiSetProp(hDBIObj(FHandle), dbTraceMode, Integer(Word(Value)));
end;

procedure TDatabase.SetExclusive(Value: Boolean);
begin
  CheckInactive;
  FExclusive := Value;
end;

procedure TDatabase.SetReadOnly(Value: Boolean);
begin
  CheckInactive;
  FReadOnly := Value;
end;

procedure TDatabase.StartTransaction;
var
  TransHandle:  HDBIXAct;
begin
  CheckActive;
  if not IsSQLBased and (TransIsolation <> tiDirtyRead) then
    DatabaseError(SLocalTransDirty, Self);
  Check(DbiBeginTran(FHandle, EXILType(FTransIsolation), TransHandle));
end;

procedure TDatabase.ValidateName(const Name: string);
var
  Database: TDatabase;
begin
  if (Name <> '') and (FSession <> nil) then
  begin
    Database := FSession.FindDatabase(Name);
    if (Database <> nil) and (Database <> Self) and
      not (Database.HandleShared and HandleShared) then
    begin
      if not Database.Temporary or (Database.FRefCount <> 0) then
        DatabaseErrorFmt(SDuplicateDatabaseName, [Name]);
      Database.Free;
    end;
  end;
end;

procedure TDatabase.FlushSchemaCache(const TableName: string);
begin
  if Connected and IsSQLBased then
    Check(DbiSchemaCacheFlush(FHandle, PChar(TableName)));
end;

{ TBDEDataSet }

constructor TBDEDataSet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  SetLocale(DefaultSession.Locale);
  FCacheBlobs := True;
  NestedDataSetClass := TNestedTable;
end;

destructor TBDEDataSet.Destroy;
begin
  inherited Destroy;
  if FBlockReadBuf <> nil then
  begin
    FreeMem(FBlockReadBuf);
    FBlockReadBuf := nil;
  end;
  SetUpdateObject(nil);
end;

procedure TBDEDataSet.OpenCursor(InfoQuery: Boolean);
var
  CursorLocale: TLocale;
begin
  if FHandle = nil then
    FHandle := CreateHandle;
  if FHandle = nil then
  begin
    FreeTimer(True);
    raise ENoResultSet.Create(SHandleError);
  end;
  if DbiGetLdObj(FHandle, CursorLocale) = 0 then SetLocale(CursorLocale);
  inherited OpenCursor(InfoQuery);
end;

procedure TBDEDataSet.CloseCursor;
begin
  inherited CloseCursor;
  SetLocale(DefaultSession.Locale);
  if FHandle <> nil then
  begin
    DestroyHandle;
    FHandle := nil;
  end;
  FParentDataSet := nil;
end;

function TBDEDataSet.CreateHandle: HDBICur;
begin
  Result := nil;
end;

procedure TBDEDataSet.DestroyHandle;
begin
  DbiRelRecordLock(FHandle, False);
  DbiCloseCursor(FHandle);
end;

function TBDEDataSet.GetHandle: HDBICur;
begin
  Result := FHandle;
end;

procedure TBDEDataSet.InternalInitFieldDefs;
var
  I, FieldID: Integer;
  FieldDescs: TFieldDescList;
  ValCheckDesc: VCHKDesc;
  RequiredFields: TBits;
  CursorProps: CurProps;
  FldDescCount,
  MaxFieldID,
  HiddenFieldCount: Integer;
begin
  DbiGetCursorProps(FHandle, CursorProps);
  FldDescCount := CursorProps.iFields;
  HiddenFieldCount := 0;
  if FieldDefs.HiddenFields then
  begin
    if SetBoolProp(Handle, curGETHIDDENCOLUMNS, True) then
    begin
      DbiGetCursorProps(FHandle, CursorProps);
      HiddenFieldCount := CursorProps.iFields - FldDescCount;
      FldDescCount := CursorProps.iFields;
    end;
  end;
  RequiredFields := TBits.Create;
  try
    MaxFieldID := GetIntProp(Handle, curMAXFIELDID);
    if MaxFieldID > 0 then
      RequiredFields.Size := MaxFieldID + 1 else
      RequiredFields.Size := FldDescCount + 1;
    for I := 1 to CursorProps.iValChecks do
    begin
      DbiGetVChkDesc(FHandle, I, @ValCheckDesc);
      if ValCheckDesc.bRequired and not ValCheckDesc.bHasDefVal then
        RequiredFields[ValCheckDesc.iFldNum] := True;
    end;
    SetLength(FieldDescs, FldDescCount);
    DbiGetFieldDescs(FHandle, PFLDDesc(FieldDescs));
    FieldID := FieldNoOfs;
    I := FieldID - 1;
    FieldDefs.Clear;
    while I < FldDescCount do
      AddFieldDesc(FieldDescs, I, FieldID, RequiredFields, FieldDefs);
    if FieldDefs.HiddenFields then
    begin
      SetBoolProp(Handle, curGETHIDDENCOLUMNS, False);
      if HiddenFieldCount > 0 then
        for I := FldDescCount - HiddenFieldCount to FldDescCount - 1 do
          FieldDefs[I].Attributes := FieldDefs[I].Attributes + [faHiddenCol];
    end;
  finally
    RequiredFields.Free;
  end;
end;

procedure TBDEDataSet.GetObjectTypeNames(Fields: TFields);
var
  Len: Word;
  I: Integer;
  TypeDesc: ObjTypeDesc;
  ObjectField: TObjectField;
begin
  for I := 0 to Fields.Count - 1 do
    if Fields[I] is TObjectField then
    begin
      ObjectField := TObjectField(Fields[I]);
      TypeDesc.iFldNum := ObjectField.FieldNo;
      if (DbiGetProp(hDBIObj(Handle), curFIELDTYPENAME, @TypeDesc,
        SizeOf(TypeDesc), Len) = DBIERR_NONE) and (Len > 0) then
        ObjectField.ObjectType := TypeDesc.szTypeName;
      with ObjectField do
        if DataType in [ftADT, ftArray] then
        begin
          if (DataType = ftArray) and SparseArrays and
             (Fields[0].DataType = ftADT) then
            GetObjectTypeNames(TObjectField(Fields[0]).Fields) else
            GetObjectTypeNames(Fields);
        end;
    end
end;

procedure TBDEDataSet.InternalOpen;
var
  CursorProps: CurProps;
begin
  if CachedUpdates then Check(DbiBeginDelayedUpdates(FHandle));
  DbiGetCursorProps(FHandle, CursorProps);
  FRecordSize := CursorProps.iRecBufSize;
  BookmarkSize := CursorProps.iBookmarkSize;
  FCanModify := (CursorProps.eOpenMode = dbiReadWrite)
    and not CursorProps.bTempTable;
  FConstraintLayer := HasConstraints and CanModify;
  if FConstraintLayer then
    Check(DbiBeginConstraintLayer(nil, FHandle, @TBDEDataSet.ConstraintCallBack,
      Integer(Pointer(Self))));
  FRecNoStatus := TRecNoStatus(CursorProps.ISeqNums);
  FieldDefs.Updated := False;
  FieldDefs.Update;
  GetIndexInfo;
  if DefaultFields then CreateFields;
  BindFields(True);
  if ObjectView then GetObjectTypeNames(Fields);
  InitBufferPointers(False);
  if CachedUpdates then
  begin
    AllocCachedUpdateBuffers(True);
    SetupCallBack(UpdateCallBackRequired);
  end;
  AllocKeyBuffers;
  DbiSetToBegin(FHandle);
  PrepareCursor;
  if Filter <> '' then
    FExprFilter := CreateExprFilter(Filter, FilterOptions, 0);
  if Assigned(OnFilterRecord) then
    FFuncFilter := CreateFuncFilter(@TBDEDataSet.RecordFilter, 1);
  if Filtered then ActivateFilters;
end;

procedure TBDEDataSet.InternalClose;
begin
  FFuncFilter := nil;
  FExprFilter := nil;
  FreeKeyBuffers;
  if CachedUpdates then
  begin
    SetupCallBack(False);
    AllocCachedUpdateBuffers(False);
    if FConstraintLayer then DbiEndConstraintLayer(FHandle);
    if FHandle <> nil then
      DbiEndDelayedUpdates(FHandle);
  end;
  BindFields(False);
  if DefaultFields then DestroyFields;
  FIndexFieldCount := 0;
  FKeySize := 0;
  FExpIndex := False;
  FCaseInsIndex := False;
  FCanModify := False;
end;

procedure TBDEDataSet.PrepareCursor;
begin
end;

function TBDEDataSet.IsCursorOpen: Boolean;
begin
  Result := Handle <> nil;
end;

procedure TBDEDataSet.InternalHandleException;
begin
  ApplicationHandleException(Self)
end;

procedure TBDEDataSet.SetLocale(Value: TLocale);
begin
  FLocale := Value;
end;

{ Record Functions }

procedure TBDEDataSet.InitBufferPointers(GetProps: Boolean);
var
  CursorProps: CurProps;
begin
  if GetProps then
  begin
    Check(DbiGetCursorProps(FHandle, CursorProps));
    BookmarkSize := CursorProps.iBookmarkSize;
    FRecordSize := CursorProps.iRecBufSize;
  end;
  FBlobCacheOfs := FRecordSize + CalcFieldsSize;
  FRecInfoOfs := FBlobCacheOfs + BlobFieldCount * SizeOf(Pointer);
  FBookmarkOfs := FRecInfoOfs + SizeOf(TRecInfo);
  FRecBufSize := FBookmarkOfs + BookmarkSize;
end;

function TBDEDataSet.AllocRecordBuffer: PChar;
begin
   Result := AllocMem(FRecBufSize);
end;

procedure TBDEDataSet.FreeRecordBuffer(var Buffer: PChar);
begin
  ClearBlobCache(Buffer);
  FreeMem(Buffer);
end;

procedure TBDEDataSet.InternalInitRecord(Buffer: PChar);
begin
  DbiInitRecord(FHandle, Buffer);
end;

procedure TBDEDataSet.ClearBlobCache(Buffer: PChar);
var
  I: Integer;
begin
  if FCacheBlobs then
    for I := 0 to BlobFieldCount - 1 do
      TBlobDataArray(Buffer + FBlobCacheOfs)[I] := '';
end;

procedure TBDEDataSet.ClearCalcFields(Buffer: PChar);
begin
  FillChar(Buffer[RecordSize], CalcFieldsSize, 0);
end;

procedure TBDEDataSet.InitRecord(Buffer: PChar);
begin
  inherited InitRecord(Buffer);
  ClearBlobCache(Buffer);
  with PRecInfo(Buffer + FRecInfoOfs)^ do
  begin
    UpdateStatus := TUpdateStatus(usInserted);
    BookMarkFlag := bfInserted;
    RecordNumber := -1;
  end;
end;

function TBDEDataSet.GetRecord(Buffer: PChar; GetMode: TGetMode;
  DoCheck: Boolean): TGetResult;
var
  Status: DBIResult;
begin
  case GetMode of
    gmCurrent:
      Status := DbiGetRecord(FHandle, dbiNoLock, Buffer, @FRecProps);
    gmNext:
      Status := DbiGetNextRecord(FHandle, dbiNoLock, Buffer, @FRecProps);
    gmPrior:
      Status := DbiGetPriorRecord(FHandle, dbiNoLock, Buffer, @FRecProps);
  else
    Status := DBIERR_NONE;
  end;
  case Status of
    DBIERR_NONE:
      begin
        with PRecInfo(Buffer + FRecInfoOfs)^ do
        begin
          UpdateStatus := TUpdateStatus(FRecProps.iRecStatus);
          BookmarkFlag := bfCurrent;
          case FRecNoStatus of
            rnParadox: RecordNumber := FRecProps.iSeqNum;
            rnDBase: RecordNumber := FRecProps.iPhyRecNum;
          else
            RecordNumber := -1;
          end;
        end;
        ClearBlobCache(Buffer);
        GetCalcFields(Buffer);
        Check(DbiGetBookmark(FHandle, Buffer + FBookmarkOfs));
        Result := grOK;
      end;
    DBIERR_BOF: Result := grBOF;
    DBIERR_EOF: Result := grEOF;
  else
    Result := grError;
    if DoCheck then Check(Status);
  end;
end;

function TBDEDataSet.GetCurrentRecord(Buffer: PChar): Boolean;
begin
  if not IsEmpty and (GetBookmarkFlag(ActiveBuffer) = bfCurrent) then
  begin
    UpdateCursorPos;
    Result := (DbiGetRecord(FHandle, dbiNoLock, Buffer, nil) = DBIERR_NONE);
  end else
    Result := False;
end;

function TBDEDataSet.GetOldRecord: PChar;
begin
  UpdateCursorPos;
  if SetBoolProp(Handle, curDELAYUPDGETOLDRECORD, True) then
  try
    Check(DbiGetRecord(FHandle, dbiNoLock, FUpdateCBBuf.pOldRecBuf, nil));
    Result := FUpdateCBBuf.pOldRecBuf;
  finally
    SetBoolProp(Handle, curDELAYUPDGETOLDRECORD, False);
  end
  else
    Result := nil;
end;

procedure TBDEDataSet.FetchAll;
begin
  if not EOF then
  begin
    CheckBrowseMode;
    Check(DbiSetToEnd(Handle));
    Check(DbiGetPriorRecord(FHandle, dbiNoLock, nil, nil));
    CursorPosChanged;
  end;
end;

procedure TBDEDataSet.FlushBuffers;
begin
  CheckBrowseMode;
  Check(DbiSaveChanges(Handle));
end;

function TBDEDataSet.GetRecordCount: Integer;
begin
  CheckActive;
  if (DbiGetExactRecordCount(FHandle, Result) <> DBIERR_NONE) and
     (DbiGetRecordCount(FHandle, Result) <> DBIERR_NONE) then
    Result := -1;
end;

function TBDEDataSet.GetRecNo: Integer;
var
  BufPtr: PChar;
begin
  CheckActive;
  if State = dsCalcFields then
    BufPtr := CalcBuffer else
    BufPtr := ActiveBuffer;
  Result := PRecInfo(BufPtr + FRecInfoOfs).RecordNumber;
end;

procedure TBDEDataSet.SetRecNo(Value: Integer);
begin
  CheckBrowseMode;
  if (FRecNoStatus = rnParadox) and (Value <> RecNo) then
  begin
    DoBeforeScroll;
    if DbiSetToSeqNo(Handle, Value) = DBIERR_NONE then
    begin
      Resync([rmCenter]);
      DoAfterScroll;
    end;
  end;
end;

function TBDEDataSet.GetRecordSize: Word;
begin
  Result := FRecordSize;
end;

function TBDEDataSet.GetActiveRecBuf(var RecBuf: PChar): Boolean;
begin
  case State of
    dsBlockRead: RecBuf := FBlockReadBuf + (FBlockBufOfs * FRecordSize);
    dsBrowse: if IsEmpty then RecBuf := nil else RecBuf := ActiveBuffer;
    dsEdit, dsInsert: RecBuf := ActiveBuffer;
    dsSetKey: RecBuf := PChar(FKeyBuffer) + SizeOf(TKeyBuffer);
    dsCalcFields: RecBuf := CalcBuffer;
    dsFilter: RecBuf := FFilterBuffer;
    dsNewValue: if FInUpdateCallback then
                  RecBuf := FUpdateCBBuf.pNewRecBuf else
                  RecBuf := ActiveBuffer;
    dsOldValue: if FInUpdateCallback then
                  RecBuf := FUpdateCBBuf.pOldRecBuf else
                  RecBuf := GetOldRecord;
  else
    RecBuf := nil;
  end;
  Result := RecBuf <> nil;
end;

{ Field Related }

procedure TBDEDataSet.AddFieldDesc(FieldDescs: TFieldDescList; var DescNo: Integer;
  var FieldID: Integer; RequiredFields: TBits; FieldDefs: TFieldDefs);
var
  FType: TFieldType;
  FSize: Word;
  FRequired: Boolean;
  FPrecision, I: Integer;
  FieldName, FName: string;
  FieldDesc: FLDDesc;
begin
  FieldDesc := FieldDescs[DescNo];
  Inc(DescNo);
  with FieldDesc do
  begin
    NativeToAnsi(Locale, szName, FieldName);
    I := 0;
    FName := FieldName;
    while FieldDefs.IndexOf(FName) >= 0 do
    begin
      Inc(I);
      FName := Format('%s_%d', [FieldName, I]);
    end;
    if iFldType < MAXLOGFLDTYPES then
      FType := DataTypeMap[iFldType] else
      FType := ftUnknown;
    FSize := 0;
    FPrecision := 0;
    if RequiredFields.Size > FieldID then
      FRequired := RequiredFields[FieldID] else
      FRequired := False;
    case iFldType of
      fldZSTRING, fldBYTES, fldVARBYTES, fldADT, fldArray, fldRef:
        begin
          if iUnits1 = 0 then { Ignore MLSLABEL field type on Oracle }
            FType := ftUnknown else
            FSize := iUnits1;
        end;
      fldINT16, fldUINT16:
        if iLen <> 2 then FType := ftUnknown;
      fldINT32:
        if iSubType = fldstAUTOINC then
        begin
          FType := ftAutoInc;
          FRequired := False;
        end;
      fldFLOAT:
        if iSubType = fldstMONEY then FType := ftCurrency;
      fldBCD:
        begin
          FSize := Abs(iUnits2);
          FPrecision := iUnits1;
        end;
      fldBLOB:
        begin
          FSize := iUnits1;
          if (iSubType >= fldstMEMO) and (iSubType <= fldstBFILE) then
            FType := BlobTypeMap[iSubType];
        end;
    end;
    with FieldDefs.AddFieldDef do
    begin
      FieldNo := FieldID;
      Inc(FieldID);
      Name := FName;
      DataType := FType;
      Size := FSize;
      Precision := FPrecision;
      if FRequired then
        Attributes := [faRequired];
      if efldrRights = fldrREADONLY then
        Attributes := Attributes + [faReadonly];
      if iSubType = fldstFIXED then
        Attributes := Attributes + [faFixed];
      InternalCalcField := bCalcField;
      case FType of
        ftADT:
          begin
            if iSubType = fldstADTNestedTable then
              Attributes := Attributes + [faUnNamed];
            for I := 0 to iUnits1 - 1 do
              AddFieldDesc(FieldDescs, DescNo, FieldID, RequiredFields, ChildDefs);
          end;
        ftArray:
          begin
            I := FieldID;
            StrCat(StrCopy(FieldDescs[DescNo].szName, FieldDesc.szName),'[0]');
            AddFieldDesc(FieldDescs, DescNo, I, RequiredFields, ChildDefs);
            Inc(FieldID, iUnits2);
          end;
      end;
    end;
  end;
end;

function TBDEDataSet.GetBlobFieldData(FieldNo: Integer; var Buffer: TBlobByteData): Integer;
var
  RecBuf: PChar;
  Status: DBIResult;
  DoCheck: Boolean;
begin
  Result := 0;
  DoCheck := BlockReadSize = 0;
  if BlockReadSize > 0 then
    RecBuf := FBlockReadBuf + (FBlockBufOfs * FRecordSize) else
    if not GetActiveRecBuf(RecBuf) then Exit;
  Status := DbiOpenBlob(FHandle, RecBuf, FieldNo, dbiReadOnly);
  if Status <> DBIERR_NONE then Exit;
  try
    Status := DbiGetBlobSize(FHandle, RecBuf, FieldNo, Result);
    if (Status <> DBIERR_NONE) or (Result = 0) then Exit;
    if Length(Buffer) <= Result then
      SetLength(Buffer, Result + Result div 4);
    Status := DbiGetBlob(FHandle, RecBuf, FieldNo, 0, Result, Buffer, Result);
  finally
    if Status <> DBIERR_NONE then Result := 0;
    DbiFreeBlob(FHandle, RecBuf, FieldNo);
    if DoCheck then Check(Status)
  end;
end;

function TBDEDataSet.GetFieldData(FieldNo: Integer; Buffer: Pointer): Boolean;
var
  IsBlank: LongBool;
  RecBuf: PChar;
  Status: DBIResult;
begin
  if BlockReadSize > 0 then
  begin
    { Optimized for speed.  If error, just return false }
    Status := DbiGetField(FHandle, FieldNo, FBlockReadBuf +
      (FBlockBufOfs * FRecordSize), Buffer, IsBlank);
    Result := (Status = DBIERR_NONE) and not IsBlank;
  end else
  begin
    Result := GetActiveRecBuf(RecBuf);
    if Result then
    begin
      Check(DbiGetField(FHandle, FieldNo, RecBuf, Buffer, IsBlank));
      Result := not IsBlank;
    end
  end;
end;

function TBDEDataSet.GetFieldData(Field: TField; Buffer: Pointer): Boolean;
var
  RecBuf: PChar;
begin
  if Field.FieldNo > 0 then
    Result := GetFieldData(Field.FieldNo, Buffer)
  else
  begin
    if State = dsBlockRead then
    begin
      RecBuf := TempBuffer;
      Result := True;
    end else
      Result := GetActiveRecBuf(RecBuf);
    if Result and (State in [dsBrowse, dsEdit, dsInsert, dsCalcFields, dsBlockRead]) then
    begin
      Inc(RecBuf, FRecordSize + Field.Offset);
      Result := Boolean(RecBuf[0]);
      if Result and (Buffer <> nil) then
        Move(RecBuf[1], Buffer^, Field.DataSize);
    end;
  end;
end;

procedure TBDEDataSet.SetFieldData(Field: TField; Buffer: Pointer);
var
  RecBuf: PChar;
  Blank: LongBool;
begin
  with Field do
  begin
    if not (State in dsWriteModes) then DatabaseError(SNotEditing, Self);
    if (State = dsSetKey) and ((FieldNo < 0) or (FIndexFieldCount > 0) and
      not IsIndexField) then DatabaseErrorFmt(SNotIndexField, [DisplayName]);
    GetActiveRecBuf(RecBuf);
    if FieldNo > 0 then
    begin
      if State = dsCalcFields then DatabaseError(SNotEditing, Self);
      if ReadOnly and not (State in [dsSetKey, dsFilter]) then
        DatabaseErrorFmt(SFieldReadOnly, [DisplayName]);
      Validate(Buffer);
      if FieldKind <> fkInternalCalc then
      begin
        if FConstraintLayer and Field.HasConstraints and (State in [dsEdit, dsInsert]) then
          Check(DbiVerifyField(FHandle, FieldNo, Buffer, Blank));
        Check(DbiPutField(FHandle, FieldNo, RecBuf, Buffer));
      end;
    end else {fkCalculated, fkLookup}
    begin
      Inc(RecBuf, FRecordSize + Offset);
      Boolean(RecBuf[0]) := LongBool(Buffer);
      if Boolean(RecBuf[0]) then Move(Buffer^, RecBuf[1], DataSize);
    end;
    if not (State in [dsCalcFields, dsFilter, dsNewValue]) then
      DataEvent(deFieldChange, Longint(Field));
  end;
end;

function TBDEDataSet.GetBlobData(Field: TField; Buffer: PChar): TBlobData;
begin
  Result := TBlobDataArray(Buffer + FBlobCacheOfs)[Field.Offset];
end;

procedure TBDEDataSet.SetBlobData(Field: TField; Buffer: PChar; Value: TBlobData);
begin
  if Buffer = ActiveBuffer then
    TBlobDataArray(Buffer + FBlobCacheOfs)[Field.Offset] := Value;
end;

function TBDEDataSet.CreateBlobStream(Field: TField; Mode: TBlobStreamMode): TStream;
begin
  Result := TBlobStream.Create(Field as TBlobField, Mode);
end;

procedure TBDEDataSet.CloseBlob(Field: TField);
begin
  DbiFreeBlob(Handle, ActiveBuffer, Field.FieldNo);
end;

function TBDEDataSet.GetStateFieldValue(State: TDataSetState; Field: TField): Variant;
begin
  CheckCachedUpdateMode;
  Result := inherited GetStateFieldValue(State, Field);
end;

procedure TBDEDataSet.SetStateFieldValue(State: TDataSetState; Field: TField; const Value: Variant);
begin
  CheckCachedUpdateMode;
  inherited SetStateFieldValue(State, Field, Value);
end;

function TBDEDataSet.Translate(Src, Dest: PChar; ToOem: Boolean): Integer;
begin
  Result := StrLen(Src);
  if ToOem then
    AnsiToNativeBuf(Locale, Src, Dest, Result) else
    NativeToAnsiBuf(Locale, Src, Dest, Result);
  if Src <> Dest then Dest[Result] := #0;
end;

function TBDEDataSet.GetFieldFullName(Field: TField): string;
var
  Len: Word;
  AttrDesc: ObjAttrDesc;
  Buffer: array[0..1024] of Char;
begin
  if Field.FieldNo > 0 then
  begin
    AttrDesc.iFldNum := Field.FieldNo;
    AttrDesc.pszAttributeName := Buffer;
    Check(DbiGetProp(HDBIOBJ(Handle), curFIELDFULLNAME, @AttrDesc,
      SizeOf(Buffer), Len));
    NativeToAnsi(Locale, Buffer, Result);
  end else
    Result := inherited GetFieldFullName(Field);
end;

{ Navigation / Editing }

procedure TBDEDataSet.InternalFirst;
begin
  Check(DbiSetToBegin(FHandle));
end;

procedure TBDEDataSet.InternalLast;
begin
  Check(DbiSetToEnd(FHandle));
end;

procedure TBDEDataSet.InternalEdit;
begin
  Check(DbiGetRecord(FHandle, dbiWriteLock, ActiveBuffer, nil));
  ClearBlobCache(ActiveBuffer);
end;

procedure TBDEDataSet.InternalInsert;
begin
  SetBoolProp(Handle, curMAKECRACK, True);
  CursorPosChanged;
end;

procedure TBDEDataSet.InternalPost;
begin
  inherited;
  if State = dsEdit then
    Check(DbiModifyRecord(FHandle, ActiveBuffer, True)) else
    Check(DbiInsertRecord(FHandle, dbiNoLock, ActiveBuffer));
end;

procedure TBDEDataSet.InternalDelete;
var
  Result: DBIResult;
begin
  Result := DbiDeleteRecord(FHandle, nil);
  if (Result <> DBIERR_NONE) and (ErrCat(Result) <> ERRCAT_NOTFOUND) then
    Check(Result);
end;

function TBDEDataSet.IsSequenced: Boolean;
begin
  Result := (FRecNoStatus = rnParadox) and (not Filtered);
end;

function TBDEDataSet.GetCanModify: Boolean;
begin
  Result := FCanModify or ForceUpdateCallback;
end;

procedure TBDEDataSet.InternalRefresh;
begin
  if (DataSetField <> nil) and (DataSetField.DataType = ftReference) then
    Check(DbiForceRecordReread(FHandle, ActiveBuffer)) else
    Check(DbiForceReread(FHandle));
end;

procedure TBDEDataSet.Post;
begin
  inherited Post;
  if State = dsSetKey then
    PostKeyBuffer(True);
end;

procedure TBDEDataSet.Cancel;
begin
  inherited Cancel;
  if State = dsSetKey then
    PostKeyBuffer(False);
end;

procedure TBDEDataSet.InternalCancel;
begin
  if State = dsEdit then
    DbiRelRecordLock(FHandle, False);
end;

procedure TBDEDataSet.InternalAddRecord(Buffer: Pointer; Append: Boolean);
begin
  if Append then
    Check(DbiAppendRecord(FHandle, Buffer)) else
    Check(DbiInsertRecord(FHandle, dbiNoLock, Buffer));
end;

procedure TBDEDataSet.InternalGotoBookmark(Bookmark: TBookmark);
begin
  Check(DbiSetToBookmark(FHandle, Bookmark));
end;

procedure TBDEDataSet.InternalSetToRecord(Buffer: PChar);
begin
  InternalGotoBookmark(Buffer + FBookmarkOfs);
end;

function TBDEDataSet.GetBookmarkFlag(Buffer: PChar): TBookmarkFlag;
begin
  Result := PRecInfo(Buffer + FRecInfoOfs).BookmarkFlag;
end;

procedure TBDEDataSet.SetBookmarkFlag(Buffer: PChar; Value: TBookmarkFlag);
begin
  PRecInfo(Buffer + FRecInfoOfs).BookmarkFlag := Value;
end;

procedure TBDEDataSet.GetBookmarkData(Buffer: PChar; Data: Pointer);
begin
  Move(Buffer[FBookmarkOfs], Data^, BookmarkSize);
end;

procedure TBDEDataset.SetBookmarkData(Buffer: PChar; Data: Pointer);
begin
  Move(Data^, Buffer[FBookmarkOfs], BookmarkSize);
end;

function TBDEDataSet.CompareBookmarks(Bookmark1, Bookmark2: TBookmark): Integer;
const
  RetCodes: array[Boolean, Boolean] of ShortInt = ((2,CMPLess),(CMPGtr,CMPEql));
begin
  { Check for uninitialized bookmarks }
  Result := RetCodes[Bookmark1 = nil, Bookmark2 = nil];
  if Result = 2 then
  begin
    if Handle <> nil then
      DbiCompareBookmarks(Handle, Bookmark1, Bookmark2, Result);
    if Result = CMPKeyEql then Result := CMPEql;
  end;
end;

function TBDEDataSet.BookmarkValid(Bookmark: TBookmark): Boolean;
begin
  Result := Handle <> nil;
  if Result then
  begin
    CursorPosChanged;
    Result := (DbiSetToBookmark(FHandle, Bookmark) = DBIERR_NONE) and
      (DbiGetRecord(FHandle, dbiNOLOCK, nil, nil) = DBIERR_NONE)
  end;
end;

procedure TBDEDataSet.SetBlockReadSize(Value: Integer);

  function CanBlockRead: Boolean;
  var
    i: Integer;
  begin
    Result := (BufferCount <= 1) and (DataSetField = nil);
    if Result then
      for i := 0 to FieldCount - 1 do
        if (Fields[i].DataType in [ftDataSet, ftReference]) then
        begin
          Result := False;
          break;
        end;
  end;

  procedure FreeBuffer;
  begin
    if FBlockReadBuf <> nil then
    begin
      FreeMem(FBlockReadBuf);
      FBlockReadBuf := nil;
    end;
  end;

const
  DEFBLOCKSIZE  = 64 * 1024;
var
  Size: Integer;
begin
  if Value <> BlockReadSize then
  begin
    if Value > 0 then
    begin
      if EOF or not CanBlockRead then Exit;
      FreeBuffer;
      UpdateCursorPos;
      DbiSetProp(HDBIObj(FHandle), curMAKECRACK, 0);
      if Value = MaxInt then
        Size := DEFBLOCKSIZE else
        Size := Value * FRecordSize;
      FBlockReadBuf := AllocMem(Size);
      FBlockBufSize := Size div FRecordSize;
      FBlockBufOfs := FBlockBufSize; { Force read of data }
      FBlockBufCount := FBlockBufSize;
      FBlockReadCount := 0;
      inherited;
      BlockReadNext;
    end else
    begin
      inherited;
//      CursorPosChanged;
//      Resync([]);
      FreeBuffer;
    end;
  end;
end;

procedure TBDEDataSet.BlockReadNext;
var
  Status: DbiResult;
begin
  if FBlockBufOfs >= FBlockBufCount - 1 then
  begin
    if FBlockBufCount < FBlockBufSize then Last else
    begin
      Status := DbiReadBlock(FHandle, FBlockBufCount, FBlockReadBuf);
      if (Status <> DBIERR_NONE) and (Status <> DBIERR_EOF) then
        Check(Status);
      if (FBlockBufCount = 0) and (Status = DBIERR_EOF) then Last;
      Inc(FBlockReadCount, FBlockBufCount);
      FBlockBufOfs := 0;
    end
  end else
    Inc(FBlockBufOfs);
  if CalcFieldsSize > 0 then
    GetCalcFields(TempBuffer);
  DataEvent(deDataSetScroll, -1);
end;

{ Index / Ranges }

procedure TBDEDataSet.GetIndexInfo;
var
  IndexDesc: IDXDesc;
begin
  if DbiGetIndexDesc(FHandle, 0, IndexDesc) = DBIERR_NONE then
  begin
    FExpIndex := IndexDesc.bExpIdx;
    FCaseInsIndex := IndexDesc.bCaseInsensitive;
    if not ExpIndex then
    begin
      FIndexFieldCount := IndexDesc.iFldsInKey;
      FIndexFieldMap := IndexDesc.aiKeyFld;
    end;
    FKeySize := IndexDesc.iKeyLen;
  end;
end;

procedure TBDEDataSet.SwitchToIndex(const IndexName, TagName: string);
var
  Status: DBIResult;
begin
  ResetCursorRange;
  UpdateCursorPos;
  Status := DbiSwitchToIndex(FHandle, PChar(IndexName),
    PChar(TagName), 0, True);
  if Status = DBIERR_NOCURRREC then
    Status := DbiSwitchToIndex(FHandle, PChar(IndexName),
    PChar(TagName), 0, False);
  Check(Status);
  FKeySize := 0;
  FExpIndex := False;
  FCaseInsIndex := False;
  FIndexFieldCount := 0;
  SetBufListSize(0);
  InitBufferPointers(True);
  try
    SetBufListSize(BufferCount + 1);
  except
    SetState(dsInactive);
    CloseCursor;
    raise;
  end;
  GetIndexInfo;
end;

function TBDEDataSet.GetIndexField(Index: Integer): TField;
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

procedure TBDEDataSet.SetIndexField(Index: Integer; Value: TField);
begin
  GetIndexField(Index).Assign(Value);
end;

function TBDEDataSet.GetIndexFieldCount: Integer;
begin
  Result := FIndexFieldCount;
end;

procedure TBDEDataSet.AllocKeyBuffers;
var
  KeyIndex: TKeyIndex;
begin
  try
    for KeyIndex := Low(TKeyIndex) to High(TKeyIndex) do
      FKeyBuffers[KeyIndex] := InitKeyBuffer(
        AllocMem(SizeOf(TKeyBuffer) + FRecordSize));
  except
    FreeKeyBuffers;
    raise;
  end;
end;

procedure TBDEDataSet.FreeKeyBuffers;
var
  KeyIndex: TKeyIndex;
begin
  for KeyIndex := Low(TKeyIndex) to High(TKeyIndex) do
    DisposeMem(FKeyBuffers[KeyIndex], SizeOf(TKeyBuffer) + FRecordSize);
end;

function TBDEDataSet.InitKeyBuffer(Buffer: PKeyBuffer): PKeyBuffer;
begin
  FillChar(Buffer^, SizeOf(TKeyBuffer) + FRecordSize, 0);
  DbiInitRecord(FHandle, PChar(Buffer) + SizeOf(TKeyBuffer));
  Result := Buffer;
end;

procedure TBDEDataSet.CheckSetKeyMode;
begin
  if State <> dsSetKey then DatabaseError(SNotEditing, Self);
end;

function TBDEDataSet.SetCursorRange: Boolean;
var
  RangeStart, RangeEnd: PKeyBuffer;
  StartKey, EndKey: PChar;
  IndexBuffer: PChar;
  UseStartKey, UseEndKey, UseKey: Boolean;
begin
  Result := False;
  if not (
    BuffersEqual(FKeyBuffers[kiRangeStart], FKeyBuffers[kiCurRangeStart],
    SizeOf(TKeyBuffer) + FRecordSize) and
    BuffersEqual(FKeyBuffers[kiRangeEnd], FKeyBuffers[kiCurRangeEnd],
    SizeOf(TKeyBuffer) + FRecordSize)) then
  begin
    IndexBuffer := AllocMem(KeySize * 2);
    try
      UseStartKey := True;
      UseEndKey := True;
      RangeStart := FKeyBuffers[kiRangeStart];
      if RangeStart.Modified then
      begin
        StartKey := PChar(RangeStart) + SizeOf(TKeyBuffer);
        UseStartKey := DbiExtractKey(Handle, StartKey, IndexBuffer) = 0;
      end
      else StartKey := nil;
      RangeEnd := FKeyBuffers[kiRangeEnd];
      if RangeEnd.Modified then
      begin
        EndKey := PChar(RangeEnd) + SizeOf(TKeyBuffer);
        UseEndKey := DbiExtractKey(Handle, EndKey, IndexBuffer + KeySize) = 0;
      end
      else EndKey := nil;
      UseKey := UseStartKey and UseEndKey;
      if UseKey then
      begin
        if StartKey <> nil then StartKey := IndexBuffer;
        if EndKey <> nil then EndKey := IndexBuffer + KeySize;
      end;
      Check(DbiSetRange(FHandle, UseKey,
        RangeStart.FieldCount, 0, StartKey, not RangeStart.Exclusive,
        RangeEnd.FieldCount, 0, EndKey, not RangeEnd.Exclusive));
      Move(FKeyBuffers[kiRangeStart]^, FKeyBuffers[kiCurRangeStart]^,
        SizeOf(TKeyBuffer) + FRecordSize);
      Move(FKeyBuffers[kiRangeEnd]^, FKeyBuffers[kiCurRangeEnd]^,
        SizeOf(TKeyBuffer) + FRecordSize);
      DestroyLookupCursor;
      Result := True;
    finally
      FreeMem(IndexBuffer, KeySize * 2);
    end;
  end;
end;

function TBDEDataSet.ResetCursorRange: Boolean;
begin
  Result := False;
  if FKeyBuffers[kiCurRangeStart].Modified or
    FKeyBuffers[kiCurRangeEnd].Modified then
  begin
    Check(DbiResetRange(FHandle));
    InitKeyBuffer(FKeyBuffers[kiCurRangeStart]);
    InitKeyBuffer(FKeyBuffers[kiCurRangeEnd]);
    DestroyLookupCursor;
    Result := True;
  end;
end;

procedure TBDEDataSet.SetLinkRanges(MasterFields: TList);
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

function TBDEDataSet.GetKeyBuffer(KeyIndex: TKeyIndex): PKeyBuffer;
begin
  Result := FKeyBuffers[KeyIndex];
end;

procedure TBDEDataSet.SetKeyBuffer(KeyIndex: TKeyIndex; Clear: Boolean);
begin
  CheckBrowseMode;
  FKeyBuffer := FKeyBuffers[KeyIndex];
  Move(FKeyBuffer^, FKeyBuffers[kiSave]^, SizeOf(TKeyBuffer) + FRecordSize);
  if Clear then InitKeyBuffer(FKeyBuffer);
  SetState(dsSetKey);
  SetModified(FKeyBuffer.Modified);
  DataEvent(deDataSetChange, 0);
end;

procedure TBDEDataSet.PostKeyBuffer(Commit: Boolean);
begin
  DataEvent(deCheckBrowseMode, 0);
  if Commit then
    FKeyBuffer.Modified := Modified else
    Move(FKeyBuffers[kiSave]^, FKeyBuffer^, SizeOf(TKeyBuffer) + FRecordSize);
  SetState(dsBrowse);
  DataEvent(deDataSetChange, 0);
end;

function TBDEDataSet.GetKeyExclusive: Boolean;
begin
  CheckSetKeyMode;
  Result := FKeyBuffer.Exclusive;
end;

procedure TBDEDataSet.SetKeyExclusive(Value: Boolean);
begin
  CheckSetKeyMode;
  FKeyBuffer.Exclusive := Value;
end;

function TBDEDataSet.GetKeyFieldCount: Integer;
begin
  CheckSetKeyMode;
  Result := FKeyBuffer.FieldCount;
end;

procedure TBDEDataSet.SetKeyFieldCount(Value: Integer);
begin
  CheckSetKeyMode;
  FKeyBuffer.FieldCount := Value;
end;

procedure TBDEDataSet.SetKeyFields(KeyIndex: TKeyIndex;
  const Values: array of const);
var
  I: Integer;
  SaveState: TDataSetState;
begin
  if ExpIndex then DatabaseError(SCompositeIndexError, Self);
  if FIndexFieldCount = 0 then DatabaseError(SNoFieldIndexes, Self);
  SaveState := SetTempState(dsSetKey);
  try
    FKeyBuffer := InitKeyBuffer(FKeyBuffers[KeyIndex]);
    for I := 0 to High(Values) do GetIndexField(I).AssignValue(Values[I]);
    FKeyBuffer^.FieldCount := High(Values) + 1;
    FKeyBuffer^.Modified := Modified;
  finally
    RestoreState(SaveState);
  end;
end;

function TBDEDataSet.GetIsIndexField(Field: TField): Boolean;
var
  I: Integer;
begin
  if (State = dsSetKey) and (FIndexFieldCount = 0) and FExpIndex then
    Result := True else
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
end;

function TBDEDataSet.MapsToIndex(Fields: TList;
  CaseInsensitive: Boolean): Boolean;
var
  I: Integer;
  HasStr: Boolean;
begin
  Result := False;
  HasStr := False;
  for I := 0 to Fields.Count - 1 do
  begin
    HasStr := TField(Fields[I]).DataType in [ftString, ftFixedChar, ftWideString];
    if HasStr then break;
  end;
  if (CaseInsensitive <> FCaseInsIndex) and HasStr then Exit;
  if Fields.Count > FIndexFieldCount then Exit;
  for I := 0 to Fields.Count - 1 do
    if TField(Fields[I]).FieldNo <> FIndexFieldMap[I] then Exit;
  Result := True;
end;

{ Filters }

procedure TBDEDataSet.ActivateFilters;
begin
  if FExprFilter <> nil then
  begin
    if DbiActivateFilter(FHandle, FExprFilter) <> DBIERR_NONE then
    begin
      DbiDropFilter(FHandle, FExprFilter);
      FExprFilter := CreateExprFilter(Filter, FilterOptions, 0);
      Check(DbiActivateFilter(FHandle, FExprFilter));
    end;
  end;
  if FFuncFilter <> nil then
  begin
    if DbiActivateFilter(FHandle, FFuncFilter) <> DBIERR_NONE then
    begin
      DbiDropFilter(FHandle, FFuncFilter);
      FFuncFilter := CreateFuncFilter(@TBDEDataSet.RecordFilter, 1);
      Check(DbiActivateFilter(FHandle, FFuncFilter));
    end;
  end;
end;

procedure TBDEDataSet.DeactivateFilters;
begin
  if FFuncFilter <> nil then Check(DbiDeactivateFilter(FHandle, FFuncFilter));
  if FExprFilter <> nil then Check(DbiDeactivateFilter(FHandle, FExprFilter));
end;

function TBDEDataSet.CreateExprFilter(const Expr: string;
  Options: TFilterOptions; Priority: Integer): HDBIFilter;
var
  Parser: TExprParser;
begin
  Parser := TExprParser.Create(Self, Expr, Options, [], '', nil, FldTypeMap);
  try
    Check(DbiAddFilter(FHandle, 0, Priority, False, PCANExpr(Parser.FilterData),
      nil, Result));
  finally
    Parser.Free;
  end;
end;

function TBDEDataSet.CreateFuncFilter(FilterFunc: Pointer;
  Priority: Integer): HDBIFilter;
begin
  Check(DbiAddFilter(FHandle, Integer(Self), Priority, False, nil,
    PFGENFilter(FilterFunc), Result));
end;

{$WARNINGS OFF}
function TBDEDataSet.CreateLookupFilter(Fields: TList; const Values: Variant;
  Options: TLocateOptions; Priority: Integer): HDBIFilter;
var
  I: Integer;
  Filter: TFilterExpr;
  Expr, Node: PExprNode;
  FilterOptions: TFilterOptions;
begin
  if loCaseInsensitive in Options then
    FilterOptions := [foNoPartialCompare, foCaseInsensitive] else
    FilterOptions := [foNoPartialCompare];
  Filter := TFilterExpr.Create(Self, FilterOptions, [], '', nil, FldTypeMap);
  try
    if Fields.Count = 1 then
    begin
      Node := Filter.NewCompareNode(TField(Fields[0]), coEQ, Values);
      Expr := Node;
    end else
      for I := 0 to Fields.Count - 1 do
      begin
        Node := Filter.NewCompareNode(TField(Fields[I]), coEQ, Values[I]);
        if I = 0 then
          Expr := Node else
          Expr := Filter.NewNode(enOperator, coAND, Unassigned, Expr, Node);
      end;
    if loPartialKey in Options then Node^.FPartial := True;
    Check(DbiAddFilter(FHandle, 0, Priority, False,
      PCANExpr(Filter.GetFilterData(Expr)), nil, Result));
  finally
    Filter.Free;
  end;
end;
{$WARNINGS ON}

procedure TBDEDataSet.SetFilterHandle(var Filter: HDBIFilter;
  Value: HDBIFilter);
begin
  if Filtered then
  begin
    CursorPosChanged;
    DestroyLookupCursor;
    DbiSetToBegin(FHandle);
    if Filter <> nil then DbiDropFilter(FHandle, Filter);
    Filter := Value;
    if Filter <> nil then DbiActivateFilter(FHandle, Filter);
  end else
  begin
    if Filter <> nil then DbiDropFilter(FHandle, Filter);
    Filter := Value;
  end;
end;

procedure TBDEDataSet.SetFilterData(const Text: string; Options: TFilterOptions);
var
  HFilter: HDBIFilter;
begin
  if Active then
  begin
    CheckBrowseMode;
    if (Filter <> Text) or (FilterOptions <> Options) then
    begin
      if Text <> '' then
        HFilter := CreateExprFilter(Text, Options, 0) else
        HFilter := nil;
      SetFilterHandle(FExprFilter, HFilter);
    end;
  end;
  inherited SetFilterText(Text);
  inherited SetFilterOptions(Options);
  if Active and Filtered then First;
end;

procedure TBDEDataSet.SetFilterText(const Value: string);
begin
  SetFilterData(Value, FilterOptions);
end;

procedure TBDEDataSet.SetFiltered(Value: Boolean);
begin
  if Active then
  begin
    CheckBrowseMode;
    if Filtered <> Value then
    begin
      DestroyLookupCursor;
      DbiSetToBegin(FHandle);
      if Value then ActivateFilters else DeactivateFilters;
      inherited SetFiltered(Value);
    end;
    First;
  end else
    inherited SetFiltered(Value);
end;

procedure TBDEDataSet.SetFilterOptions(Value: TFilterOptions);
begin
  SetFilterData(Filter, Value);
end;

procedure TBDEDataSet.SetOnFilterRecord(const Value: TFilterRecordEvent);
var
  Filter: HDBIFilter;
begin
  if Active then
  begin
    CheckBrowseMode;
    if Assigned(OnFilterRecord) <> Assigned(Value) then
    begin
      if Assigned(Value) then
        Filter := CreateFuncFilter(@TBDEDataSet.RecordFilter, 1) else
        Filter := nil;
      SetFilterHandle(FFuncFilter, Filter);
    end;
    inherited SetOnFilterRecord(Value);
    if Filtered then First;
  end else
    inherited SetOnFilterRecord(Value);
end;

function TBDEDataSet.FindRecord(Restart, GoForward: Boolean): Boolean;
var
  Status: DBIResult;
begin
  CheckBrowseMode;
  DoBeforeScroll;
  SetFound(False);
  UpdateCursorPos;
  CursorPosChanged;
  if not Filtered then ActivateFilters;
  try
    if GoForward then
    begin
      if Restart then Check(DbiSetToBegin(FHandle));
      Status := DbiGetNextRecord(FHandle, dbiNoLock, nil, nil);
    end else
    begin
      if Restart then Check(DbiSetToEnd(FHandle));
      Status := DbiGetPriorRecord(FHandle, dbiNoLock, nil, nil);
    end;
  finally
    if not Filtered then DeactivateFilters;
  end;
  if Status = DBIERR_NONE then
  begin
    Resync([rmExact, rmCenter]);
    SetFound(True);
  end;
  Result := Found;
  if Result then DoAfterScroll;
end;

function TBDEDataSet.RecordFilter(RecBuf: Pointer; RecNo: Integer): Smallint;
var
  Accept: Boolean;
  SaveState: TDataSetState;
begin
  SaveState := SetTempState(dsFilter);
  FFilterBuffer := RecBuf;
  try
    Accept := True;
    OnFilterRecord(Self, Accept);
  except
    ApplicationHandleException(Self);
  end;
  RestoreState(SaveState);
  Result := Ord(Accept);
end;

function TBDEDataSet.LocateRecord(const KeyFields: string;
  const KeyValues: Variant; Options: TLocateOptions;
  SyncCursor: Boolean): Boolean;
var
  I, FieldCount, PartialLength: Integer;
  Buffer: PChar;
  Fields: TList;
  LookupCursor: HDBICur;
  Filter: HDBIFilter;
  Status: DBIResult;
  CaseInsensitive: Boolean;
begin
  CheckBrowseMode;
  CursorPosChanged;
  Buffer := TempBuffer;
  Fields := TList.Create;
  try
    GetFieldList(Fields, KeyFields);
    CaseInsensitive := loCaseInsensitive in Options;
    if CachedUpdates then
      LookupCursor := nil
    else
      if MapsToIndex(Fields, CaseInsensitive) then
        LookupCursor := FHandle else
        LookupCursor := GetLookupCursor(KeyFields, CaseInsensitive);
    if (LookupCursor <> nil) then
    begin
      SetTempState(dsFilter);
      FFilterBuffer := Buffer;
      try
        DbiInitRecord(LookupCursor, Buffer);
        FieldCount := Fields.Count;
        if FieldCount = 1 then
        begin
          if VarIsArray(KeyValues) then
            TField(Fields.First).Value := KeyValues[0] else
            TField(Fields.First).Value := KeyValues;
        end else
          for I := 0 to FieldCount - 1 do
            TField(Fields[I]).Value := KeyValues[I];
        PartialLength := 0;
        if (loPartialKey in Options) and
          (TField(Fields.Last).DataType = ftString) then
        begin
          Dec(FieldCount);
          PartialLength := Length(TField(Fields.Last).AsString);
        end;
        Status := DbiGetRecordForKey(LookupCursor, False, FieldCount,
          PartialLength, Buffer, Buffer);
      finally
        RestoreState(dsBrowse);
      end;
      if (Status = DBIERR_NONE) and SyncCursor and
        (LookupCursor <> FHandle) then
        Status := DbiSetToCursor(FHandle, LookupCursor);
    end else
    begin
      Check(DbiSetToBegin(FHandle));
      Filter := CreateLookupFilter(Fields, KeyValues, Options, 2);
      DbiActivateFilter(FHandle, Filter);
      Status := DbiGetNextRecord(FHandle, dbiNoLock, Buffer, nil);
      DbiDropFilter(FHandle, Filter);
    end;
  finally
    Fields.Free;
  end;
  Result := Status = DBIERR_NONE;
end;

function TBDEDataSet.Lookup(const KeyFields: string; const KeyValues: Variant;
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

function TBDEDataSet.Locate(const KeyFields: string;
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

function TBDEDataSet.GetLookupCursor(const KeyFields: string;
  CaseInsensitive: Boolean): HDBICur;
begin
  Result := nil;
end;

procedure TBDEDataSet.DestroyLookupCursor;
begin
end;

function TBDEDataSet.HasConstraints: Boolean;
var
  I: Integer;
begin
  Result := True;
  if Constraints.Count > 0 then Exit;
  for I := 0 to FieldCount - 1 do
    if Fields[I].HasConstraints then Exit;
  Result := False;
end;

function TBDEDataSet.ConstraintsDisabled: Boolean;
begin
  Result := FConstDisableCount > 0;
end;

procedure TBDEDataSet.DisableConstraints;
begin
  if FConstDisableCount = 0 then
    SetBoolProp(Handle, curCONSTSTATE, False);
  Inc(FConstDisableCount);
end;

procedure TBDEDataSet.EnableConstraints;
begin
  if FConstDisableCount <> 0 then
  begin
    Dec(FConstDisableCount);
    if FConstDisableCount = 0 then
      SetBoolProp(Handle, curCONSTSTATE, True);
  end;
end;

function TBDEDataSet.ConstraintCallBack(Req: DsInfoReq;
  var ADataSources: DataSources): DBIResult;

  function GetPChar(const S: string): PChar;
  begin
    if S <> '' then Result := PChar(Pointer(S)) else Result := '';
  end;

  function GetFieldConstraint: Boolean;
  var
    Field: TField;
  begin
    Result := False;
    Field := FindField(ADataSources.szSourceFldName);
    if (Field <> nil) and (Field.Required or (Field.ImportedConstraint <> '') or
      (Field.CustomConstraint <> '')) then
    begin
      StrCopy(ADataSources.szSQLExprImport, GetPChar(Field.ImportedConstraint));
      StrCopy(ADataSources.szSQLExprCustom, GetPChar(Field.CustomConstraint));
      StrCopy(ADataSources.szErrStrCustom, GetPChar(Field.ConstraintErrorMessage));
      StrCopy(ADataSources.szErrStrImport, GetPChar(Field.ConstraintErrorMessage));
      ADataSources.bRequired := Field.Required;
      Result := True;
    end;
  end;

  procedure GetTableConstraint;
  begin
    with ADataSources, Constraints[iNumElem - 1] do
    begin
      StrCopy(szSQLExprImport, GetPChar(ImportedConstraint));
      StrCopy(szSQLExprCustom, GetPChar(CustomConstraint));
      StrCopy(szErrStrCustom, GetPChar(ErrorMessage));
      StrCopy(szErrStrImport, GetPChar(ErrorMessage));
    end;
  end;

  function GetDefaultExpression: Boolean;
  var
    Field: TField;
  begin
    Result := False;
    Field := FindField(ADataSources.szSourceFldName);
    if (Field <> nil) and (Field.DefaultExpression <> '') then
    begin
      StrCopy(ADataSources.szSQLExprImport, GetPChar(Field.DefaultExpression));
      Result := True;
    end;
  end;

begin
  Result := DBIERR_NA;
  try
    case Req of
      dsFieldSource: if GetFieldSource(Self, ADataSources) then Result := DBIERR_NONE;
      dsFieldDomainExpr: if GetFieldConstraint then Result := DBIERR_NONE;
      dsFieldDefault: if GetDefaultExpression then Result := DBIERR_NONE;
      dsNumTblConstraint:
        begin
          ADataSources.iNumElem := Constraints.Count;
          Result := DBIERR_NONE;
        end;
      dsTblConstraint:
        begin
          GetTableConstraint;
          Result := DBIERR_NONE;
        end;
    end;
  except
  end;
end;

{ Cached Updates }

procedure TBDEDataSet.AllocCachedUpdateBuffers(Allocate: Boolean);
begin
  if Allocate then
  begin
    FUpdateCBBuf := AllocMem(SizeOf(DELAYUPDCbDesc));
    FUpdateCBBuf.pNewRecBuf := AllocMem(FRecBufSize);
    FUpdateCBBuf.pOldRecBuf := AllocMem(FRecBufSize);
    FUpdateCBBuf.iRecBufSize := FRecordSize;
  end else
  begin
    if Assigned(FUpdateCBBuf) then
    begin
      FreeMem(FUpdateCBBuf.pNewRecBuf);
      FreeMem(FUpdateCBBuf.pOldRecBuf);
      DisposeMem(FUpdateCBBuf, SizeOf(DELAYUPDCbDesc));
    end;
  end;
end;

procedure TBDEDataSet.CheckCachedUpdateMode;
begin
  if not CachedUpdates then DatabaseError(SNoCachedUpdates, Self);
end;

function TBDEDataSet.UpdateCallbackRequired: Boolean;
begin
  Result := FCachedUpdates and (Assigned(FOnUpdateError) or
    Assigned(FOnUpdateRecord) or Assigned(FUpdateObject));
end;

function TBDEDataSet.ForceUpdateCallback: Boolean;
begin
  Result := FCachedUpdates and (Assigned(FOnUpdateRecord) or
    Assigned(FUpdateObject));
end;

procedure TBDEDataSet.SetCachedUpdates(Value: Boolean);

  procedure ReAllocBuffers;
  begin
    FreeFieldBuffers;
    FreeKeyBuffers;
    SetBufListSize(0);
    try
      InitBufferPointers(True);
      SetBufListSize(BufferCount + 1);
      AllocKeyBuffers;
    except
      SetState(dsInactive);
      CloseCursor;
      raise;
    end;
  end;

begin
  if (State = dsInActive) or (csDesigning in ComponentState) then
    FCachedUpdates := Value
  else if FCachedUpdates <> Value then
  begin
    CheckBrowseMode;
    UpdateCursorPos;
    if FConstraintLayer then DbiEndConstraintLayer(FHandle);
    if FCachedUpdates then
      Check(DbiEndDelayedUpdates(FHandle)) else
      Check(DbiBeginDelayedUpdates(FHandle));
    if FConstraintLayer then
      Check(DbiBeginConstraintLayer(nil, FHandle,
        @TBDEDataSet.ConstraintCallBack, Integer(Pointer(Self))));
    FCachedUpdates := Value;
    ReAllocBuffers;
    AllocCachedUpdateBuffers(Value);
    SetupCallBack(UpdateCallBackRequired);
    Resync([]);
  end;
end;

procedure TBDEDataSet.SetupCallBack(Value: Boolean);
begin
  if Value then
  begin
    if (csDesigning in ComponentState) then Exit;
    if not Assigned(FUpdateCallback) then
      FUpdateCallback := TBDECallback.Create(Self, Self.Handle, cbDELAYEDUPD,
        FUpdateCBBuf, SizeOf(DELAYUPDCbDesc), CachedUpdateCallBack, True);
  end
  else
  begin
    if Assigned(FUpdateCallback) then
    begin
      FUpdateCallback.Free;
      FUpdateCallback := nil;
    end;
  end;
end;

function TBDEDataSet.ProcessUpdates(UpdCmd: DBIDelayedUpdCmd): DBIResult;
begin
  CheckCachedUpdateMode;
  UpdateCursorPos;
  Result := DbiApplyDelayedUpdates(Handle, UpdCmd);
end;

procedure TBDEDataSet.ApplyUpdates;
var
  Status: DBIResult;
begin
  if State <> dsBrowse then Post;
  Status := ProcessUpdates(dbiDelayedUpdPrepare);
  if Status <> DBIERR_NONE then
    if Status = DBIERR_UPDATEABORT then SysUtils.Abort
    else DbiError(Status);
end;

procedure TBDEDataSet.CommitUpdates;
begin
  Check(ProcessUpdates(dbiDelayedUpdCommit));
  Resync([]);
end;

procedure TBDEDataSet.CancelUpdates;
begin
  Cancel;
  ProcessUpdates(dbiDelayedUpdCancel);
  if Active then
    Resync([]);
end;

procedure TBDEDataSet.RevertRecord;
var
  Status: DBIResult;
begin
  if State in dsEditModes then Cancel;
  Status := ProcessUpdates(dbiDelayedUpdCancelCurrent);
  if not ((Status = DBIERR_NONE) or (Status = DBIERR_NOTSUPPORTED)) then
    Check(Status);
  Resync([]);
end;

function TBDEDataSet.UpdateStatus: TUpdateStatus;
var
  BufPtr: PChar;
begin
  if CachedUpdates then
  begin
    if State = dsCalcFields then
      BufPtr := CalcBuffer else
      BufPtr := ActiveBuffer;
    Result := PRecInfo(BufPtr + FRecInfoOfs).UpdateStatus;
  end else
    Result := usUnModified;
end;

function TBDEDataSet.CachedUpdateCallBack(CBInfo: Pointer): CBRType;
const
  CBRetCode: array[TUpdateAction] of CBRType = (cbrAbort, cbrAbort,
    cbrSkip, cbrRetry, cbrPartialAssist);
var
  UpdateAction: TUpdateAction;
  UpdateKind: TUpdateKind;
begin
  FInUpdateCallBack := True;
  UpdateAction := uaFail;
  UpdateKind := TUpdateKind(ord(FUpdateCBBuf.eDelayUpdOpType)-1);
  try
    if Assigned(FOnUpdateRecord) then
      FOnUpdateRecord(Self, UpdateKind, UpdateAction)
    else
      if Assigned(FUpdateObject) then
      begin
        FUpdateObject.Apply(UpdateKind);
        UpdateAction := uaApplied;
      end
    else
      DbiError(FUpdateCBBuf.iErrCode);
  except
    on E: Exception do
    begin
      if E is EDBEngineError then
        FUpdateCBBuf.iErrCode := EDBEngineError(E).Errors[0].ErrorCode;
      if (E is EDatabaseError) and Assigned(FOnUpdateError) then
        FOnUpdateError(Self, EDatabaseError(E), UpdateKind, UpdateAction)
      else
      begin
        ApplicationHandleException(Self);
        UpdateAction := uaAbort;
      end;
    end;
  end;
  Result := CBRetCode[UpdateAction];
  if UpdateAction = uaAbort then FUpdateCBBuf.iErrCode := DBIERR_UPDATEABORT;
  FInUpdateCallBack := False;
end;

function TBDEDataSet.GetUpdateRecordSet: TUpdateRecordTypes;
begin
  if Active then
  begin
    CheckCachedUpdateMode;
    Result := TUpdateRecordTypes(Byte(GetIntProp(FHandle, curDELAYUPDDISPLAYOPT)));
  end
  else
    Result := [];
end;

procedure TBDEDataSet.SetUpdateRecordSet(RecordTypes: TUpdateRecordTypes);
begin
  CheckCachedUpdateMode;
  CheckBrowseMode;
  UpdateCursorPos;
  Check(DbiSetProp(hDbiObj(Handle), curDELAYUPDDISPLAYOPT, Longint(Byte(RecordTypes))));
  Resync([]);
end;

procedure TBDEDataSet.SetUpdateObject(Value: TDataSetUpdateObject);
begin
  if Value <> FUpdateObject then
  begin
    if Assigned(FUpdateObject) and (FUpdateObject.DataSet = Self) then
      FUpdateObject.DataSet := nil;
    FUpdateObject := Value;
    if Assigned(FUpdateObject) then
    begin
      { If another dataset already references this updateobject, then
        remove the reference }
      if Assigned(FUpdateObject.DataSet) and
        (FUpdateObject.Dataset is TBDEDataset) and 
        (FUpdateObject.DataSet <> Self) then
        TBDEDataset(FUpdateObject.DataSet).UpdateObject := nil; 
      FUpdateObject.DataSet := Self;
    end;
  end;
end;

procedure TBDEDataSet.SetOnUpdateError(UpdateEvent: TUpdateErrorEvent);
begin
  if Active then SetupCallback(UpdateCallBackRequired);
  FOnUpdateError := UpdateEvent;
end;

function TBDEDataSet.GetUpdatesPending: Boolean;
begin
  Result := GetIntProp(FHandle, curDELAYUPDNUMUPDATES) > 0;
end;

procedure TBDEDataSet.DataEvent(Event: TDataEvent; Info: Integer);

  procedure CheckIfParentScrolled;
  var
    ParentPosition, I: Integer;
  begin
    ParentPosition := 0;
    with FParentDataSet do
      if not IsEmpty then
        for I := 0 to BookmarkSize - 1 do
          ParentPosition := ParentPosition + Byte(ActiveBuffer[FBookmarkOfs+I]);
    if (FLastParentPos = 0) or (ParentPosition <> FLastParentPos) then
    begin
      First;
      FLastParentPos := ParentPosition;
    end else
    begin
      UpdateCursorPos;
      Resync([]);
    end;
  end;

begin
  if Event = deParentScroll then CheckIfParentScrolled;
  inherited DataEvent(Event, Info);
end;

{ TBDEDataSet.IProviderSupport}

function TBDEDataSet.PSGetUpdateException(E: Exception; Prev: EUpdateError): EUpdateError;
var
  PrevErr: Integer;
begin
  if E is EDBEngineError then
  begin
    if Prev <> nil then
      PrevErr := Prev.ErrorCode else
      PrevErr := 0;
    with EDBEngineError(E).Errors[0] do
      Result := EUpdateError.Create(E.Message, '', ErrorCode, PrevErr, E);
  end else
    Result := inherited PSGetUpdateException(E, Prev);
end;

function TBDEDataSet.PSIsSQLSupported: Boolean;
begin
  Result := True;
end;

procedure TBDEDataSet.PSReset;
begin
  inherited PSReset;
  if Handle <> nil then
    DbiForceReread(Handle);
end;

function TBDEDataSet.PSUpdateRecord(UpdateKind: TUpdateKind; Delta: TDataSet): Boolean;
var
  UpdateAction: TUpdateAction;
begin
  Result := False;
  if Assigned(OnUpdateRecord) then
  begin
    UpdateAction := uaFail;
    if Assigned(FOnUpdateRecord) then
    begin
      FOnUpdateRecord(Delta, UpdateKind, UpdateAction);
      Result := UpdateAction = uaApplied;
    end;
  end;
end;

{ TNestedTable }

constructor TNestedTable.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ObjectView := True;
end;

function TNestedTable.CreateHandle: HDBICur;
var
  PHandle: HDBICur;
begin
  if not Assigned(DataSetField) then DatabaseError(SNoDataSetField, Self);
  FParentDataSet := (DataSetField.DataSet as TBDEDataSet);
  OpenParentDataSet(FParentDataSet);
  PHandle := FParentDataSet.Handle;
  with DataSetField do
    if DataType = ftDataSet then
      Check(DbiOpenNestedTable(PHandle, FieldNo, ReadOnly, False, Result)) else
      Check(DbiOpenRef(PHandle, FieldNo, ReadOnly, False, Result));
  FieldDefs.HiddenFields := FParentDataSet.FieldDefs.HiddenFields;
  if DataSetField.IncludeObjectField then
    FieldNoOfs := 1 else
    FieldNoOfs := 2;
end;

procedure TNestedTable.DoAfterPost;
var
  DataPtr: Pointer;
  RefData: Variant;
  RefSize: Word;
  RefBuffer: array[0..255] of Byte;
begin
  { Assign the reference ID to the DataSetField }
  if DataSetField.DataType = ftReference then
  begin
    Check(DbiGetProp(hDBIObj(FHandle), curGETREF, @RefBuffer, SizeOf(RefBuffer), RefSize));
    if RefSize <= DataSetField.DataSize then
    begin
      RefData := VarArrayCreate([0, DataSetField.DataSize - 1], varByte);
      DataPtr := VarArrayLock(RefData);
      try
        Move(RefBuffer, DataPtr^, RefSize);
      finally
        VarArrayUnlock(RefData);
      end;
      DataSetField.AsVariant := RefData;
    end;
  end;
  inherited;
end;

procedure TNestedTable.DoBeforeInsert;
begin
  inherited DoBeforeInsert;
  if (DataSetField.DataType = ftDataSet) and (FParentDataSet.State = dsInsert) then
    FParentDataSet.Post;
end;

procedure TNestedTable.InternalPost;
begin
  inherited;
  if (DataSetField.DataType = ftReference) and (State = dsInsert) then
  begin
    if TReferenceField(DataSetField).ReferenceTableName = '' then
      DatabaseErrorFmt(SNoReferenceTableName, [DataSetField.DisplayName]);
    Check(DbiSetProp(hDBIObj(FHandle), curREFINSERTTABLENAME,
      Integer(PChar(TReferenceField(DataSetField).ReferenceTableName))));
  end;
  inherited;
end;

{ TDBDataSet }

constructor TDBDataSet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  if AOwner is TDatabase then
  begin
    DatabaseName := TDatabase(AOwner).DatabaseName;
    SessionName := TDatabase(AOwner).SessionName;
  end;
  FAutoRefresh := False;
end;

procedure TDBDataSet.SetHandle(Value: HDBICur);
begin
  Close;
  FHandle := Value;
  if Assigned(Value) then
  try
    Open;
  except
    FHandle := nil;
    raise;
  end;
end;

procedure TDBDataSet.OpenCursor(InfoQuery: Boolean);
begin
  SetDBFlag(dbfOpened, True);
  inherited OpenCursor(InfoQuery);
  SetUpdateMode(FUpdateMode);
  if Database.IsSQLBased then
    SetupAutoRefresh
end;

procedure TDBDataSet.CloseCursor;
begin
  inherited CloseCursor;
  SetDBFlag(dbfOpened, False);
end;

procedure TDBDataSet.CheckDBSessionName;
var
  S: TSession;
  Database: TDatabase;
begin
  if (SessionName <> '') and (DatabaseName <> '') then
  begin
    S := Sessions.FindSession(SessionName);
    if Assigned(S) and not Assigned(S.DoFindDatabase(DatabaseName, Self)) then
    begin
      Database := DefaultSession.DoFindDatabase(DatabaseName, Self);
      if Assigned(Database) then Database.CheckSessionName(True);
    end;
  end;
end;

function TDBDataSet.CheckOpen(Status: DBIResult): Boolean;
begin
  case Status of
    DBIERR_NONE:
      Result := True;
    DBIERR_NOTSUFFTABLERIGHTS:
      begin
        if not DBSession.GetPassword then DbiError(Status);
        Result := False;
      end;
  else
    DbiError(Status);
    Result := False;
  end;
end;

function TDBDataSet.ConstraintsStored: Boolean;
begin
  Result := Constraints.Count > 0;
end;

procedure TDBDataSet.Disconnect;
begin
  Close;
end;

function TDBDataSet.GetDBHandle: HDBIDB;
begin
  if FDatabase <> nil then
    Result := FDatabase.Handle else
    Result := nil;
end;

function TDBDataSet.GetDBLocale: TLocale;
begin
  if Database <> nil then
    Result := Database.Locale else
    Result := nil;
end;

function TDBDataSet.GetDBSession: TSession;
begin
  if (FDatabase <> nil) then
    Result := FDatabase.Session else
    Result := Sessions.FindSession(SessionName);
  if Result = nil then Result := DefaultSession;
end;

function TDBDataSet.OpenDatabase: TDatabase;
begin
  with Sessions.List[FSessionName] do
    Result := DoOpenDatabase(FDatabasename, Self.Owner);
end;

procedure TDBDataSet.CloseDatabase(Database: TDatabase);
begin
  if Assigned(Database) then
    Database.Session.CloseDatabase(Database);
end;

procedure TDBDataSet.SetDatabaseName(const Value: string);
begin
  if csReading in ComponentState then
    FDatabaseName := Value
  else if FDatabaseName <> Value then
  begin
    CheckInactive;
    if FDatabase <> nil then DatabaseError(SDatabaseOpen, Self);
    FDatabaseName := Value;
    DataEvent(dePropertyChange, 0);
  end;
end;

function TDBDataSet.SetDBFlag(Flag: Integer; Value: Boolean): Boolean;
begin
  Result := Flag in DBFlags;
  if Value then
  begin
    if not Result then
    begin
      if FDBFlags = [] then
      begin
        CheckDBSessionName;
        FDatabase := OpenDatabase;
        FDatabase.RegisterClient(Self);
        SetLocale(FDatabase.Locale);
        if FDatabase.Temporary and (csDesigning in ComponentState) then
          FDatabase.Session.LoadSMClient(True);
      end;
      Include(FDBFlags, Flag);
    end;
  end else
  begin
    if Result then
    begin
      Exclude(FDBFlags, Flag);
      if FDBFlags = [] then
      begin
        SetLocale(DBLocale);
        FDatabase.UnregisterClient(Self);
        FDatabase.Session.CloseDatabase(FDatabase);
        FDatabase := nil;
      end;
    end;
  end;
end;

procedure TDBDataSet.SetSessionName(const Value: string);
begin
  CheckInactive;
  FSessionName := Value;
  DataEvent(dePropertyChange, 0);
end;

procedure TDBDataSet.SetUpdateMode(const Value: TUpdateMode);
begin
  if (FHandle <> nil) and Database.IsSQLBased and CanModify then
    Check(DbiSetProp(hDbiObj(FHandle), curUPDLOCKMODE, Longint(Value)));
  FUpdateMode := Value;
end;

{ AutoRefresh }
procedure TDBDataSet.SetAutoRefresh(const Value: Boolean);
begin
  CheckInactive;
  FAutoRefresh := Value;
end;

procedure TDBDataSet.SetupAutoRefresh;
const
  PropFlags: array[TAutoRefreshFlag] of LongInt = (0, curFIELDISAUTOINCR, curFIELDISDEFAULT);
var
  I: Integer;
  ColDesc: ServerColDesc;
begin
  if AutoRefresh then
    Check(DbiSetProp(hDbiObj(FHandle), curAUTOREFETCH, Longint(True)));

  for I := 0 to Fields.Count - 1 do
    with Fields[I] do
      if AutoGenerateValue <> arNone then
      begin
        ColDesc.iFldNum := I + 1;
        ColDesc.bServerCol := True;
        Check(DbiSetProp(hDbiObj(FHandle), PropFlags[AutoGenerateValue], LongInt(@ColDesc)));
      end;
end;

{ TDBDataSet.IProviderSupport }

procedure TDBDataSet.PSGetAttributes(List: TList);
var
  Attr: PPacketAttribute;
begin
  inherited PSGetAttributes(List);
  if Locale <> nil then
  begin
    New(Attr);
    List.Add(Attr);
    with Attr^ do
    begin
      Name := 'LCID';
      Value := Integer(TOSBLObj(Locale^).LdLCID);
      IncludeInDelta := False;
    end;
  end;
end;

function TDBDataSet.PSIsSQLBased: Boolean;
var
  InProvider: Boolean;
begin
  InProvider := SetDBFlag(dbfProvider, True);
  try
    Result := Database.IsSQLBased;
  finally
    SetDBFlag(dbfProvider, InProvider);
  end;
end;

function TDBDataSet.PSGetQuoteChar: string;
var
  Q: Char;
  Len: Word;
  InProvider: Boolean;
begin
  InProvider := SetDBFlag(dbfProvider, True);
  try
    Result := '';
    if PSIsSQLBased then
    begin
      Q := #0;
      DbiGetProp(HDBIObj(Database.Handle), dbQUOTECHAR, @Q, SizeOf(Q), Len);
      if Q <> #0 then
        Result := Q;
    end else
      Result := '"';
  finally
    SetDBFlag(dbfProvider, InProvider);
  end;
end;

function TDBDataSet.PSInTransaction: Boolean;
var
  Database: TDatabase;
begin
  Result := False;
  if Assigned(Sessions.List[SessionName]) then
  begin
    Database := Sessions.List[SessionName].DoFindDatabase(DatabaseName, Owner);
    Result := Assigned(Database) and Database.InTransaction;
  end;
end;

procedure TDBDataSet.PSStartTransaction;
begin
  SetDBFlag(dbfProvider, True);
  try
    if not PSIsSQLBased then
      Database.TransIsolation := tiDirtyRead;
    Database.StartTransaction;
  except
    SetDBFlag(dbfProvider, False);
    raise;
  end;
end;

procedure TDBDataSet.PSEndTransaction(Commit: Boolean);
const
  EndType: array[Boolean] of eXEnd = (xendABORT, xendCOMMIT);
begin
  try
    Database.ClearStatements;
    Database.EndTransaction(EndType[Commit]);
  finally
    SetDBFlag(dbfProvider, False);
  end;
end;

function TDBDataSet.PSExecuteStatement(const ASQL: string; AParams: TParams;
  ResultSet: Pointer = nil): Integer;
var
  InProvider: Boolean;
  Cursor: hDBICur;
begin
  InProvider := SetDBFlag(dbfProvider, True);
  try
    if Assigned(ResultSet) then
    begin
      Result := Database.Execute(ASQL, AParams, True, @Cursor);
      TDataSet(ResultSet^) := TDBDataSet.Create(nil);
      TDBDataSet(ResultSet^).SetHandle(Cursor);
    end else
      Result := Database.Execute(ASQL, AParams, True, nil);
  finally
    SetDBFlag(dbfProvider, InProvider);
  end;
end;

function TDBDataSet.PSUpdateRecord(UpdateKind: TUpdateKind; Delta: TDataSet): Boolean;

{  procedure AssignParams(DataSet: TDataSet; Params: TParams);
  var
    I: Integer;
    Old: Boolean;
    Param: TParam;
    PName: string;
    Field: TField;
    Value: Variant;
  begin
    for I := 0 to Params.Count - 1 do
    begin
      Param := Params[I];
      PName := Param.Name;
      Old := CompareText(Copy(PName, 1, 4), 'OLD_') = 0;
      if Old then System.Delete(PName, 1, 4);
      Field := DataSet.FindField(PName);
      if not Assigned(Field) then Continue;
      if Old then Param.AssignFieldValue(Field, Field.OldValue) else
      begin
        Value := Field.NewValue;
        if VarIsClear(Value) then Value := Field.OldValue;
        Param.AssignFieldValue(Field, Value);
      end;
    end;
  end;

var
  SQL: string;
  Params: TParams; }   
begin
  Result := inherited PSUpdateRecord(UpdateKind, Delta);
  if not Result and Assigned(FUpdateObject) and (FUpdateObject is TUpdateSQL) then 
  begin
    TUpdateSQL(FUpdateObject).Dataset := Delta; 
    TUpdateSQL(FUpdateObject).DatabaseName := DatabaseName; 
    TUpdateSQL(FUpdateObject).SessionName := SessionName; 
    TUpdateSQL(FUpdateObject).Apply(UpdateKind); 
    // USQL.Apply calls USQL.ExecSQL, which raises an exception if RowsAffected<>1
    Result := True; 
{    SQL := TSQLUpdateObject(FUpdateObject).GetSQL(UpdateKind).Text;
    if SQL <> '' then
    begin
      Params := TParams.Create;
      try
        Params.ParseSQL(SQL, True);
        TSQLUpdateObject(FUpdateObject).Dataset := Delta;
        TSQLUpdateObject(FUpdateObject).DatabaseName := '';
        TSQLUpdateObject(FUpdateObject).SetParams(UpdateKind);
        TSQLUpdateObject(FUpdateObject).ExecSQL;
        if PSExecuteStatement(SQL, Params) = 0 then
          DatabaseError(SRecordChanged);
        Result := True;
      finally
        Params.Free;
      end;
    end;} 
  end;
end;

{ TBatchMove }

constructor TBatchMove.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FAbortOnKeyViol := True;
  FAbortOnProblem := True;
  FTransliterate := True;
  FMappings := TStringList.Create;
end;

destructor TBatchMove.Destroy;
begin
  FMappings.Free;
  inherited Destroy;
end;

function TBatchMove.ConvertName(const Name: string; Buffer: PChar): PChar;
begin
  if Name <> '' then
    Result := AnsiToNative(nil, Name, Buffer, DBIMAXTBLNAMELEN) else
    Result := nil;
end;

procedure TBatchMove.Execute;
type
  TFieldMap = array of Word;
var
  SourceActive, DestinationActive: Boolean;
  BatchMode: TBatchMode;
  I: Integer;
  FieldCount: Word;
  FieldMap: TFieldMap;
  DestName, SourceName: string;
  SKeyViolName, SProblemName, SChangedName: DBITBLNAME;

  procedure GetMappingNames;
  var
    P: Integer;
    Mapping: string;
  begin
    Mapping := FMappings[I];
    P := Pos('=', Mapping);
    if P > 0 then
    begin
      DestName := Copy(Mapping, 1, P - 1);
      SourceName := Copy(Mapping, P + 1, 255);
    end else
    begin
      DestName := Mapping;
      SourceName := Mapping;
    end;
  end;

begin
  if (Destination = nil) or (Source = nil) or (Destination = Source) then
    DatabaseError(SInvalidBatchMove, Self);
  SourceActive := Source.Active;
  DestinationActive := Destination.Active;
  FieldCount := 0;
  FieldMap := nil;
  try
    Source.DisableControls;
    Destination.DisableControls;
    Source.Open;
    Source.CheckBrowseMode;
    Source.UpdateCursorPos;
    BatchMode := FMode;
    if BatchMode = batCopy then
    begin
      Destination.Close;
      if FMappings.Count = 0 then
        Destination.FieldDefs := Source.FieldDefs
      else
      begin
        Destination.FieldDefs.Clear;
        for I := 0 to FMappings.Count - 1 do
        begin
          GetMappingNames;
          with Source.FieldDefs.Find(SourceName) do
            Destination.FieldDefs.Add(DestName, DataType, Size, Required);
        end;
      end;
      Destination.IndexDefs.Clear;
      Destination.CreateTable;
      BatchMode := batAppend;
    end;
    Destination.Open;
    Destination.CheckBrowseMode;
    if FMappings.Count <> 0 then
    begin
      FieldCount := Destination.FieldDefs.Count;
      SetLength(FieldMap, FieldCount);
      for I := 0 to FMappings.Count - 1 do
      begin
        GetMappingNames;
        FieldMap[Destination.FieldDefs.Find(DestName).FieldNo-1] :=
          Source.FieldDefs.Find(SourceName).FieldNo;
      end;
    end;
    if FRecordCount > 0 then
    begin
      Source.UpdateCursorPos;
      FMovedCount := FRecordCount;
    end else
    begin
      Check(DbiSetToBegin(Source.Handle));
      FMovedCount := MaxLongint;
    end;
    Source.CursorPosChanged;
    try
      if CommitCount > 0 then
        Check(DbiSetProp(hDBIObj(Destination.DBHandle), dbBATCHCOUNT, CommitCount));
      Check(DbiBatchMove(nil, Source.Handle, nil, Destination.Handle,
        EBATMode(BatchMode), FieldCount, PWord(FieldMap), nil, nil, 0,
        ConvertName(FKeyViolTableName, SKeyViolName),
        ConvertName(FProblemTableName, SProblemName),
        ConvertName(FChangedTableName, SChangedName),
        @FProblemCount, @FKeyViolCount, @FChangedCount,
        FAbortOnProblem, FAbortOnKeyViol, FMovedCount, FTransliterate));
    finally
      if DestinationActive then Destination.First;
    end;
  finally
    if not DestinationActive then Destination.Close;
    if not SourceActive then Source.Close;
    Destination.EnableControls;
    Source.EnableControls;
  end;
end;

procedure TBatchMove.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Operation = opRemove then
  begin
    if Destination = AComponent then Destination := nil;
    if Source = AComponent then Source := nil;
  end;
end;

procedure TBatchMove.SetMappings(Value: TStrings);
begin
  FMappings.Assign(Value);
end;

procedure TBatchMove.SetSource(Value: TBDEDataSet);
begin
  FSource := Value;
  if Value <> nil then Value.FreeNotification(Self);
end;

{ TIndexFiles }

constructor TIndexFiles.Create(AOwner: TTable);
begin
  inherited Create;
  FOwner := AOwner;
end;

function TIndexFiles.Add(const S: string): Integer;
begin
  with FOwner do
  begin
    if Active then OpenIndexFile(S);
    IndexDefs.Updated := False;
  end;
  Result := inherited Add(S);
end;

procedure TIndexFiles.Clear;
var
  I: Integer;
begin
  with FOwner do
    if Active then
      for I := 0 to Count - 1 do CloseIndexFile(Strings[I]);
  inherited Clear;
end;

procedure TIndexFiles.Insert(Index: Integer; const S: string);
begin
  inherited Insert(Index, S);
  with FOwner do
  begin
    if Active then OpenIndexFile(S);
    IndexDefs.Updated := False;
  end;
end;

procedure TIndexFiles.Delete(Index: Integer);
begin
  with FOwner do
  begin
    if Active then CloseIndexFile(Strings[Index]);
    IndexDefs.Updated := False;
  end;
  inherited Delete(Index);
end;

{ TTable }

constructor TTable.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FIndexDefs := TIndexDefs.Create(Self);
  FMasterLink := TMasterDataLink.Create(Self);
  FMasterLink.OnMasterChange := MasterChanged;
  FMasterLink.OnMasterDisable := MasterDisabled;
  FIndexFiles := TIndexFiles.Create(Self);
  FDefaultIndex := True;
end;

destructor TTable.Destroy;
begin
  inherited Destroy;
  FIndexFiles.Free;
  FMasterLink.Free;
  FIndexDefs.Free;
end;

function TTable.GetHandle(const IndexName, IndexTag: string): HDBICur;
const
  OpenModes: array[Boolean] of DbiOpenMode = (dbiReadWrite, dbiReadOnly);
  ShareModes: array[Boolean] of DbiShareMode = (dbiOpenShared, dbiOpenExcl);
var
  SIndexName: DBITBLNAME;
  OpenMode: DbiOpenMode;
  RetCode: DbiResult;
  IndexID: Word;
  I: Integer;
begin
  Result := nil;
  OpenMode := OpenModes[FReadOnly or ForceUpdateCallback];
  if DefaultIndex then
    IndexID := 0 else
    IndexID := NODEFAULTINDEX;
  while True do
  begin
    RetCode := DbiOpenTable(DBHandle, NativeTableName, GetTableTypeName,
      PChar(IndexName), PChar(IndexTag), IndexID, OpenMode, ShareModes[FExclusive],
      xltField, False, nil, Result);
    if RetCode = DBIERR_TABLEREADONLY then
      OpenMode := dbiReadOnly
    else if CheckOpen(RetCode) then Break;
  end;
  if IsXBaseTable then
    for I := 0 to IndexFiles.Count - 1 do
    begin
      CharToOem(PChar(IndexFiles[I]), SIndexName);
      CheckIndexOpen(DbiOpenIndex(Result, SIndexName, 0));
    end;
end;

function TTable.CreateHandle: HDBICur;
var
  CursorLocale: TLocale;
  IndexName, IndexTag: string;
begin
  if FTableName = '' then DatabaseError(SNoTableName, Self);
  IndexDefs.Updated := False;
  if Database.IsSQLBased then
  begin
    GetIndexParams(FIndexName, FFieldsIndex, IndexName, IndexTag);
    Result := GetHandle(IndexName, IndexTag);
  end else
  begin
    { For local tables, open the table first then switch the index }
    Result := GetHandle('', '');
    { Set the FHandle & Locale before calling GetIndexParams }
    FHandle := Result;
    if DbiGetLdObj(Result, CursorLocale) = 0 then SetLocale(CursorLocale);
    GetIndexParams(FIndexName, FFieldsIndex, IndexName, IndexTag);
    if (IndexName <> '') and IsProductionIndex(IndexName) then
       Check(DbiSwitchToIndex(Result, PChar(IndexName), PChar(IndexTag), 0, False));
  end;
end;

function TTable.GetLanguageDriverName: string;
var
  TblName: DBITBLNAME;
  LdName: DBINAME;
  DriverName: PChar;
  S: string;
  FDb: Boolean;
begin
  TblName[0] := #0;
  FDb := SetDBFlag(dbfDatabase, True);
  try
    if Database.IsSQLBased then
    begin
      DriverName := PChar(DBSession.GetAliasDriverName(DatabaseName));
      FmtStr(S, ':%s:%s', [DatabaseName, TableName]);
      AnsiToNative(DBLocale, S, TblName, SizeOf(TblName) - 1);
    end
    else begin
      DbiFormFullName(Database.Handle, NativeTableName, nil, TblName);
      DriverName := GetTableTypeName;
    end;
    { If the table does not exist, get the language driver for the driver }
    if DbiGetLdName(DriverName, @TblName, @LdName) <> 0 then
      DbiGetLdName(DriverName, nil, @LdName);
  finally
    SetDBFlag(dbfDatabase, FDb);
  end;
  Result := LdName;
end;

function TTable.SetTempLocale(ActiveCheck: Boolean): TLocale;
var
  LName: string;
  TempLocale: TLocale;
begin
  if not ActiveCheck or (FHandle = nil) then
  begin
    Result := Locale;
    LName := GetLanguageDriverName;
    if (LName <> '') and (OsLdLoadBySymbName(PChar(LName), TempLocale) = 0) then
      if TempLocale <> Locale then
        SetLocale(TempLocale) else
        OsLdUnloadObj(TempLocale);
  end else
  begin
    if DbiGetLdObj(FHandle, TempLocale) = 0 then SetLocale(TempLocale);
    Result := TempLocale;
  end;
end;

procedure TTable.RestoreLocale(LocaleSave: TLocale);
begin
  if (LocaleSave <> Locale) and (Locale <> nil) then
  begin
    OsLdUnloadObj(FLocale);
    SetLocale(LocaleSave);
  end;
end;

procedure TTable.PrepareCursor;
var
  IndexName, IndexTag: string;
begin
  if IsXBaseTable then
  begin
    GetIndexParams(FIndexName, FFieldsIndex, IndexName, IndexTag);
    if not IsProductionIndex(IndexName) then SwitchToIndex(IndexName, IndexTag);
  end;
  CheckMasterRange;
end;

procedure TTable.DefChanged(Sender: TObject);
begin
  StoreDefs := True;
end;

procedure TTable.InitFieldDefs;
var
  I, FieldID, FldDescCount: Integer;
  FieldDescs: TFieldDescList;
  FCursor, VCursor: HDBICur;
  RequiredFields: TBits;
  ValCheckDesc: VCHKDesc;
  LocaleSave: TLocale;
begin
  if (FHandle <> nil) then InternalInitFieldDefs else
  begin
    SetDBFlag(dbfFieldList, True);
    try
      if FTableName = '' then DatabaseError(SNoTableName, Self);
      LocaleSave := SetTempLocale(True);
      try
        while not CheckOpen(DbiOpenFieldList(DBHandle, NativeTableName,
          GetTableTypeName, False, FCursor)) do {Retry};
        try
          Check(DbiGetRecordCount(FCursor, FldDescCount));
          SetLength(FieldDescs, FldDescCount);
          { Create an array of field descriptors }
          for I := 0 to FldDescCount - 1 do
            Check(DbiGetNextRecord(FCursor, dbiNoLock, @FieldDescs[I], nil));
          { Initialize list of required fields }
          RequiredFields := TBits.Create;
          try
            if FieldDescs[FldDescCount-1].iFldNum > FldDescCount then
              RequiredFields.Size := FieldDescs[FldDescCount-1].iFldNum + 1 else
              RequiredFields.Size := FldDescCount + 1;
            if DbiOpenVChkList(DBHandle, NativeTableName, GetTableTypeName,
              VCursor) = 0 then
            try
              while DbiGetNextRecord(VCursor, dbiNoLock, @ValCheckDesc, nil) = 0 do
                if ValCheckDesc.bRequired and not ValCheckDesc.bHasDefVal then
                begin
                  { Grow the RequiredFields bits if needed for array fields }
                  if ValCheckDesc.iFldNum > (RequiredFields.Size - 1) then
                    RequiredFields.Size := RequiredFields.Size + 100;
                  RequiredFields[ValCheckDesc.iFldNum] := True;
                end;
            finally
              DbiCloseCursor(VCursor);
            end;
            { Initialize the FieldDefs }
            FieldDefs.BeginUpdate;
            try
              FieldDefs.Clear;
              I := 0;
              FieldID := 1;
              while I < FldDescCount do
                AddFieldDesc(FieldDescs, I, FieldID, RequiredFields, FieldDefs);
            finally
              FieldDefs.EndUpdate;
            end;
          finally
            RequiredFields.Free;
          end;
        finally
          DbiCloseCursor(FCursor);
        end;
      finally
        RestoreLocale(LocaleSave);
      end;
    finally
      SetDBFlag(dbfFieldList, False);
    end;
  end;
end;

procedure TTable.DestroyHandle;
begin
  DestroyLookupCursor;
  inherited DestroyHandle;
end;

{ Index / Ranges / Keys }

procedure TTable.DecodeIndexDesc(const IndexDesc: IDXDesc;
  var Source, Name, FieldExpression, DescFields: string;
  var Options: TIndexOptions);

  procedure ConcatField(var FieldList: string; const FieldName: string);
  begin
    if FieldList = '' then
      FieldList := FieldName else
      FieldList := Format('%s;%s', [FieldList, FieldName]);
  end;


var
  IndexOptions: TIndexOptions;
  I: Integer;
  SSource, SName: PChar;
  FieldName: string;
begin
  with IndexDesc do
  begin
    if szTagName[0] = #0 then
    begin
      SName := szName;
      Source := '';
    end
    else begin
      SSource := szName;
      SName := szTagName;
      NativeToAnsi(nil, SSource, Source);
    end;
    NativeToAnsi(Locale, SName, Name);
    Name := ExtractFileName(Name);
    Source := ExtractFileName(Source);
    IndexOptions := [];
    if bPrimary then Include(IndexOptions, ixPrimary);
    if bUnique then Include(IndexOptions, ixUnique);
    if bDescending then Include(IndexOptions, ixDescending);
    if bCaseInsensitive then Include(IndexOptions, ixCaseInsensitive);
    if not bMaintained then Include(IndexOptions, ixNonMaintained);
    if bExpIdx then
    begin
      NativeToAnsi(Locale, szKeyExp, FieldExpression);
      Include(IndexOptions, ixExpression);
    end else
    begin
      FieldExpression := '';
      DescFields := '';
      for I := 0 to iFldsInKey - 1 do
      begin
        FieldName := FieldDefList[aiKeyFld[I] - 1].Name;
        ConcatField(FieldExpression, FieldName);
        if abDescending[I] then
          ConcatField(DescFields, FieldName);
      end;
      if bDescending and (DescFields = FieldExpression) then
        DescFields := '';
    end;
    Options := IndexOptions;
  end;
end;

procedure TTable.EncodeIndexDesc(var IndexDesc: IDXDesc;
  const Name, FieldExpression: string; Options: TIndexOptions;
  const DescFields: string);

  function IndexFieldOfs(const FieldName: string): Integer;
  var
    FieldNo: Integer;
  begin
    FieldNo := FieldDefs.Find(FieldName).FieldNo;
    for Result := 0 to IndexDesc.iFldsInKey - 1 do
      if IndexDesc.aiKeyFld[Result] = FieldNo then Exit;
    DatabaseErrorFmt(SIndexFieldMissing, [FieldName], Self);
    Result := -1;
  end;

var
  Pos: Integer;
begin
  FillChar(IndexDesc, SizeOf(IndexDesc), 0);
  with IndexDesc do
  begin
    bPrimary := ixPrimary in Options;
    bUnique := ixUnique in Options;
    bDescending := (ixDescending in Options) and (DescFields = '');
    bMaintained := not (ixNonMaintained in Options);
    { -1 for True is ignored in the Paradox driver }
    Word(bCaseInsensitive) := Word(ixCaseInsensitive in Options);
    if IsXBaseTable then
    begin
      if bMaintained then
        AnsiToNative(Locale, Name, szTagName, SizeOf(szTagName) - 1) else
        AnsiToNative(Locale, Name, szName, SizeOf(szName) - 1);
    end else
      AnsiToNative(Locale, Name, szName, SizeOf(szName) - 1);
    if ixExpression in Options then
    begin
      bExpIdx := True;
      AnsiToNative(Locale, FieldExpression, szKeyExp, SizeOf(szKeyExp) - 1);
    end else
    begin
      Pos := 1;
      while (Pos <= Length(FieldExpression)) and (iFldsInKey < DBIMAXFLDSINKEY) do
      begin
        aiKeyFld[iFldsInKey] :=
          FieldDefs.Find(ExtractFieldName(FieldExpression, Pos)).FieldNo;
        abDescending[iFldsInKey] := bDescending;
        Inc(iFldsInKey);
      end;
      if (DescFields <> '') then
      begin
        bDescending := True;
        Pos := 1;
        while Pos <= Length(DescFields) do
          abDescending[IndexFieldOfs(ExtractFieldName(DescFields, Pos))] := True;
      end;
    end;
  end;
end;

procedure TTable.AddIndex(const Name, Fields: string; Options: TIndexOptions;
  const DescFields: string);
var
  IndexDesc: IDXDesc;
  LocaleSave: TLocale;
begin
  FieldDefs.Update;
  if Active then
  begin
    EncodeIndexDesc(IndexDesc, Name, Fields, Options, DescFields);
    CheckBrowseMode;
    CursorPosChanged;
    Check(DbiAddIndex(DBHandle, Handle, nil, nil, IndexDesc, nil));
  end else
  begin
    LocaleSave := SetTempLocale(False);
    try
      EncodeIndexDesc(IndexDesc, Name, Fields, Options, DescFields);
    finally
      RestoreLocale(LocaleSave);
    end;
    SetDBFlag(dbfTable, True);
    try
      Check(DbiAddIndex(DBHandle, nil, NativeTableName, GetTableTypeName,
        IndexDesc, nil));
    finally
      SetDBFlag(dbfTable, False);
    end;
  end;
  IndexDefs.Updated := False;
end;

procedure TTable.DeleteIndex(const Name: string);
var
  IndexName, IndexTag: string;
begin
  if Active then
  begin
    GetIndexParams(Name, False, IndexName, IndexTag);
    CheckBrowseMode;
    Check(DbiDeleteIndex(DBHandle, Handle, nil, nil, PChar(IndexName),
      PChar(IndexTag), 0));
  end else
  begin
    GetIndexParams(Name, False, IndexName, IndexTag);
    SetDBFlag(dbfTable, True);
    try
      Check(DbiDeleteIndex(DBHandle, nil, NativeTableName, GetTableTypeName,
        PChar(IndexName), PChar(IndexTag), 0));
    finally
      SetDBFlag(dbfTable, False);
    end;
  end;
  IndexDefs.Updated := False;
end;

function TTable.GetIndexFieldNames: string;
begin
  if FFieldsIndex then Result := FIndexName else Result := '';
end;

function TTable.GetIndexName: string;
begin
  if FFieldsIndex then Result := '' else Result := FIndexName;
end;

procedure TTable.GetIndexNames(List: TStrings);
begin
  IndexDefs.Update;
  IndexDefs.GetItemNames(List);
end;

procedure TTable.GetIndexParams(const IndexName: string;
  FieldsIndex: Boolean; var IndexedName, IndexTag: string);
var
  I: Integer;
  IndexStr: TIndexName;
  SIndexName: DBIMSG;
  SIndexTag: DBINAME;
  LocaleSave: TLocale;
begin
  SIndexName[0] := #0;
  SIndexTag[0] := #0;
  if IndexName <> '' then
  begin
    IndexDefs.Update;
    IndexStr := IndexName;
    LocaleSave := SetTempLocale(True);
    try
      if FieldsIndex then
        if Database.FPseudoIndexes then
        begin
          for I := 1 to Length(IndexStr) do
            if IndexStr[I] = ';' then IndexStr[I] := '@';
          IndexStr := '@' + IndexStr;
        end else
          IndexStr := IndexDefs.FindIndexForFields(IndexName).Name;
      if IsXBaseTable and (UpperCase(ExtractFileExt(IndexStr)) <> '.NDX') then
      begin
        AnsiToNative(Locale, IndexStr, SIndexTag, SizeOf(SIndexTag) - 1);
        with IndexDefs do
        begin
          I := IndexOf(IndexStr);
          if I <> -1 then
            IndexStr := Items[I].Source else
            DatabaseErrorFmt(SIndexDoesNotExist, [IndexName], Self);
          AnsiToNative(nil, IndexStr, SIndexName, SizeOf(SIndexName) - 1);
        end;
      end else
        AnsiToNative(Locale, IndexStr, SIndexName, SizeOf(SIndexName) - 1);
    finally
      RestoreLocale(LocaleSave);
    end;
  end;
  IndexedName := SIndexName;
  IndexTag := SIndexTag;
end;

procedure TTable.SetIndexDefs(Value: TIndexDefs);
begin
  IndexDefs.Assign(Value);
end;

procedure TTable.SetIndex(const Value: string; FieldsIndex: Boolean);
var
  IndexName, IndexTag: string;
begin
  if Active then CheckBrowseMode;
  if (FIndexName <> Value) or (FFieldsIndex <> FieldsIndex) then
  begin
    if Active then
    begin
      GetIndexParams(Value, FieldsIndex, IndexName, IndexTag);
      SwitchToIndex(IndexName, IndexTag);
      CheckMasterRange;
    end;
    FIndexName := Value;
    FFieldsIndex := FieldsIndex;
    if Active then Resync([]);
  end;
end;

procedure TTable.SetIndexFieldNames(const Value: string);
begin
  SetIndex(Value, Value <> '');
end;

procedure TTable.SetIndexName(const Value: string);
begin
  SetIndex(Value, False);
end;

procedure TTable.SetIndexFiles(Value: TStrings);
begin
  FIndexFiles.Assign(Value);
end;

procedure TTable.OpenIndexFile(const IndexName: string);
var
  Buffer: DBINAME;
begin
  CheckIndexOpen(DbiOpenIndex(Handle,
    AnsiToNative(Locale, IndexName, Buffer, SizeOf(Buffer) - 1), 0));
end;

procedure TTable.CloseIndexFile(const IndexFileName: string);
var
  IndexName, IndexTag: string;
  Buffer: DBINAME;
begin
  GetIndexParams(FIndexName, FFieldsIndex, IndexName, IndexTag);
  if AnsiUpperCaseFileName(IndexName) = AnsiUpperCaseFileName(IndexFileName) then
    Self.IndexName := '';
  Check(DbiCloseIndex(Handle,
    AnsiToNative(Locale, IndexFileName, Buffer, SizeOf(Buffer) - 1), 0));
end;

procedure TTable.UpdateIndexDefs;
var
  Opts: TIndexOptions;
  IdxName, Src, Flds, DescFlds: string;

  procedure UpdateFromCursor;
  var
    I: Integer;
    Cursor: HDBICur;
    CursorProps: CurProps;
    IndexDescs: TIndexDescList;
    OldLocale, CursorLocale: TLocale;
  begin
    OldLocale := Locale;
    if Handle = nil then
    begin
      Cursor := GetHandle('', '');
      { For Local tables (i.e. Paradox & dBase) we need to get the locale
        from the actual Table }
      if DbiGetLdObj(Cursor, CursorLocale) = 0 then SetLocale(CursorLocale);
    end else
      Cursor := Handle;
    try
      DbiGetCursorProps(Cursor, CursorProps);
      if CursorProps.iIndexes > 0 then
      begin
        SetLength(IndexDescs, CursorProps.iIndexes);
        DbiGetIndexDescs(Cursor, PIDXDesc(IndexDescs));
        for I := 0 to CursorProps.iIndexes - 1 do
        begin
          DecodeIndexDesc(IndexDescs[I], Src, IdxName, Flds, DescFlds, Opts);
          with IndexDefs.AddIndexDef do
          begin
            Name := IdxName;
            Fields := Flds;
            DescFields := DescFlds;
            Options := Opts;
            if Src <> '' then
              Source := Src;
          end;
        end;
      end;
    finally
      if (Cursor <> nil) and (Cursor <> Handle) then DbiCloseCursor(Cursor);
      if Locale <> OldLocale then SetLocale(OldLocale);
    end;
  end;

  procedure UpdateFromIndexList;
  var
    FCursor: HDBICur;
    IndexDesc: IDXDesc;
  begin
    while not CheckOpen(DbiOpenIndexList(DBHandle, NativeTableName,
      GetTableTypeName, FCursor)) do {Retry};
    try
      while DbiGetNextRecord(FCursor, dbiNoLock, @IndexDesc, nil) = 0 do
        if IndexDesc.bMaintained then
        begin
          DecodeIndexDesc(IndexDesc, Src, IdxName, Flds, DescFlds, Opts);
          with IndexDefs.AddIndexDef do
          begin
            Name := IdxName;
            Fields := Flds;
            DescFields := DescFlds;
            Options := Opts;
          end;
        end;
    finally
      DbiCloseCursor(FCursor);
    end;
  end;

begin
  SetDBFlag(dbfIndexList, True);
  try
    FieldDefs.Update;
    IndexDefs.Clear;
    if IsCursorOpen or not Database.IsSQLBased then
      UpdateFromCursor else
      UpdateFromIndexList;
  finally
    SetDBFlag(dbfIndexList, False);
  end;
end;

function TTable.IsProductionIndex(const IndexName: string): Boolean;
begin
  Result := True;
  if IsXBaseTable and (IndexName <> '') then
    if AnsiUpperCase(ExtractFileExt(IndexName)) = '.NDX' then
      Result := False
    else Result := AnsiUpperCaseFileName(ChangeFileExt(NativeTableName, '')) =
      AnsiUpperCaseFileName(ChangeFileExt(IndexName, ''));
end;

function TTable.GetExists: Boolean;
var
  H: HDBICur;
  E: DBIResult;
begin
  Result := Active;
  if Result or (TableName = '') then Exit;
  SetDBFlag(dbfTable, True);
  try
    if Database.IsSQLBased then
    begin
      { Assume (get fields) faster than (get tables & find this table) }
      E := DbiOpenFieldList(DBHandle, NativeTableName, nil, False, H);
      Result := E = DBIERR_NONE;
      if Result then DbiCloseCursor(H)
      else if (E <> DBIERR_NOSUCHTABLE) and (E <> DBIERR_OBJNOTFOUND) then DbiError(E);
    end else Result := FileExists(GetFileName);
  finally
    SetDBFlag(dbfTable, False);
  end;
end;

function TTable.FindKey(const KeyValues: array of const): Boolean;
begin
  CheckBrowseMode;
  SetKeyFields(kiLookup, KeyValues);
  Result := GotoKey;
end;

procedure TTable.FindNearest(const KeyValues: array of const);
begin
  CheckBrowseMode;
  SetKeyFields(kiLookup, KeyValues);
  GotoNearest;
end;

function TTable.GotoKey: Boolean;
var
  KeyBuffer: PKeyBuffer;
  IndexBuffer, RecBuffer: PChar;
  UseKey: Boolean;
begin
  CheckBrowseMode;
  DoBeforeScroll;
  CursorPosChanged;
  KeyBuffer := GetKeyBuffer(kiLookup);
  IndexBuffer := AllocMem(KeySize);
  try
    RecBuffer := PChar(KeyBuffer) + SizeOf(TKeyBuffer);
    UseKey := DbiExtractKey(Handle, RecBuffer, IndexBuffer) = 0;
    if UseKey then RecBuffer := IndexBuffer;
    Result := DbiGetRecordForKey(Handle, UseKey, KeyBuffer^.FieldCount, 0,
      RecBuffer, nil) = 0;
    if Result then Resync([rmExact, rmCenter]);
    if Result then DoAfterScroll;
  finally
    FreeMem(IndexBuffer, KeySize);
  end;
end;

procedure TTable.GotoNearest;
var
  SearchCond: DBISearchCond;
  KeyBuffer: PKeyBuffer;
  IndexBuffer, RecBuffer: PChar;
  UseKey: Boolean;
begin
  CheckBrowseMode;
  CursorPosChanged;
  KeyBuffer := GetKeyBuffer(kiLookup);
  if KeyBuffer^.Exclusive then
    SearchCond := keySEARCHGT else
    SearchCond := keySEARCHGEQ;
  IndexBuffer := AllocMem(KeySize);
  try
    RecBuffer := PChar(KeyBuffer) + SizeOf(TKeyBuffer);
    UseKey := DbiExtractKey(Handle, RecBuffer, IndexBuffer) = 0;
    if UseKey then RecBuffer := IndexBuffer;
    Check(DbiSetToKey(Handle, SearchCond, UseKey, KeyBuffer^.FieldCount, 0,
      RecBuffer));
    Resync([rmCenter]);
  finally
    FreeMem(IndexBuffer, KeySize);
  end;
end;

procedure TTable.SetKey;
begin
  SetKeyBuffer(kiLookup, True);
end;

procedure TTable.EditKey;
begin
  SetKeyBuffer(kiLookup, False);
end;

procedure TTable.ApplyRange;
begin
  CheckBrowseMode;
  if SetCursorRange then First;
end;

procedure TTable.CancelRange;
begin
  CheckBrowseMode;
  UpdateCursorPos;
  if ResetCursorRange then Resync([]);
end;

procedure TTable.SetRange(const StartValues, EndValues: array of const);
begin
  CheckBrowseMode;
  SetKeyFields(kiRangeStart, StartValues);
  SetKeyFields(kiRangeEnd, EndValues);
  ApplyRange;
end;

procedure TTable.SetRangeEnd;
begin
  SetKeyBuffer(kiRangeEnd, True);
end;

procedure TTable.SetRangeStart;
begin
  SetKeyBuffer(kiRangeStart, True);
end;

procedure TTable.EditRangeEnd;
begin
  SetKeyBuffer(kiRangeEnd, False);
end;

procedure TTable.EditRangeStart;
begin
  SetKeyBuffer(kiRangeStart, False);
end;

procedure TTable.UpdateRange;
begin
  SetLinkRanges(FMasterLink.Fields);
end;

function TTable.GetLookupCursor(const KeyFields: string;
  CaseInsensitive: Boolean): HDBICur;
var
  IndexFound, FieldsIndex: Boolean;
  KeyIndexName, IndexName, IndexTag: string;
  KeyIndex: TIndexDef;
begin
  if (KeyFields <> FLookupKeyFields) or
     (CaseInsensitive <> FLookupCaseIns) then
  begin
    DestroyLookupCursor;
    IndexFound := False;
    FieldsIndex := False;
    { If a range is active, don't use a lookup cursor }
    if not FKeyBuffers[kiCurRangeStart].Modified and
       not FKeyBuffers[kiCurRangeEnd].Modified then
    begin
      if Database.FPseudoIndexes then
      begin
        if not CaseInsensitive then
        begin
          KeyIndexName := KeyFields;
          FieldsIndex := True;
          IndexFound := True;
        end;
      end else
      begin
        KeyIndex := IndexDefs.GetIndexForFields(KeyFields, CaseInsensitive);
        if (KeyIndex <> nil) and
           (CaseInsensitive = (ixCaseInsensitive in KeyIndex.Options)) then
        begin
          KeyIndexName := KeyIndex.Name;
          FieldsIndex := False;
          IndexFound := True;
        end;
      end;
      if IndexFound and (Length(KeyFields) < DBIMAXMSGLEN) then
      begin
        Check(DbiCloneCursor(Handle, True, False, FLookupHandle));
        GetIndexParams(KeyIndexName, FieldsIndex, IndexName, IndexTag);
        Check(DbiSwitchToIndex(FLookupHandle, PChar(IndexName),
          PChar(IndexTag), 0, False));
      end;
      FLookupKeyFields := KeyFields;
      FLookupCaseIns := CaseInsensitive;
    end;
  end;
  Result := FLookupHandle;
end;

procedure TTable.DestroyLookupCursor;
begin
  if FLookupHandle <> nil then
  begin
    DbiCloseCursor(FLookupHandle);
    FLookupHandle := nil;
    FLookupKeyFields := '';
  end;
end;

procedure TTable.GotoCurrent(Table: TTable);
begin
  CheckBrowseMode;
  Table.CheckBrowseMode;
  if (AnsiCompareText(DatabaseName, Table.DatabaseName) <> 0) or
    (AnsiCompareText(TableName, Table.TableName) <> 0) then
    DatabaseError(STableMismatch, Self);
  Table.UpdateCursorPos;
  Check(DbiSetToCursor(Handle, Table.Handle));
  DoBeforeScroll;
  Resync([rmExact, rmCenter]);
  DoAfterScroll;
end;

procedure TTable.GetDetailLinkFields(MasterFields, DetailFields: TList);
var
  i: Integer;
  Idx: TIndexDef;
begin
  MasterFields.Clear;
  DetailFields.Clear;
  if (MasterSource <> nil) and (MasterSource.DataSet <> nil) and
     (Self.MasterFields <> '') then
  begin
    Idx := nil;
    MasterSource.DataSet.GetFieldList(MasterFields, Self.MasterFields);
    UpdateIndexDefs;
    if IndexName <> '' then
      Idx := IndexDefs.Find(IndexName)
    else if IndexFieldNames <> '' then
      Idx := IndexDefs.GetIndexForFields(IndexFieldNames, False)
    else
      for i := 0 to IndexDefs.Count - 1 do
        if ixPrimary in IndexDefs[i].Options then
        begin
          Idx := IndexDefs[i];
          break;
        end;
    if Idx <> nil then
      GetFieldList(DetailFields, Idx.Fields);
  end;
end;

{ Master / Detail }

procedure TTable.CheckMasterRange;
begin
  if FMasterLink.Active and (FMasterLink.Fields.Count > 0) then
  begin
    SetLinkRanges(FMasterLink.Fields);
    SetCursorRange;
  end;
end;

procedure TTable.MasterChanged(Sender: TObject);
begin
  CheckBrowseMode;
  UpdateRange;
  ApplyRange;
end;

procedure TTable.MasterDisabled(Sender: TObject);
begin
  CancelRange;
end;

function TTable.GetDataSource: TDataSource;
begin
  Result := FMasterLink.DataSource;
end;

procedure TTable.SetDataSource(Value: TDataSource);
begin
  if IsLinkedTo(Value) then DatabaseError(SCircularDataLink, Self);
  FMasterLink.DataSource := Value;
end;

function TTable.GetMasterFields: string;
begin
  Result := FMasterLink.FieldNames;
end;

procedure TTable.SetMasterFields(const Value: string);
begin
  FMasterLink.FieldNames := Value;
end;

procedure TTable.DoOnNewRecord;
var
  I: Integer;
begin
  if FMasterLink.Active and (FMasterLink.Fields.Count > 0) then
    for I := 0 to FMasterLink.Fields.Count - 1 do
      IndexFields[I] := TField(FMasterLink.Fields[I]);
  inherited DoOnNewRecord;
end;

{ Table Manipulation }

function TTable.BatchMove(ASource: TBDEDataSet; AMode: TBatchMode): Longint;
begin
  with TBatchMove.Create(nil) do
  try
    Destination := Self;
    Source := ASource;
    Mode := AMode;
    Execute;
    Result := MovedCount;
  finally
    Free;
  end;
end;

procedure TTable.CreateTable;
var
  LocaleSave: TLocale;
  IndexDescs: TIndexDescList;
  TableDesc: CRTblDesc;
  FieldDescs: TFieldDescList;
  ValChecks: TValCheckList;
  DriverTypeName: DBINAME;
  SQLLName: DBINAME;
  PSQLLName: PChar;
  LvlFldDesc: FLDDesc;
  Level: DBINAME;

  procedure InitTableSettings;
  var
    PTblType: PChar;
  begin
    FillChar(TableDesc, SizeOf(TableDesc), 0);
    with TableDesc do
    begin
      AnsiToNative(Locale, TableName, szTblName, SizeOf(szTblName) - 1);
      PTblType := GetTableTypeName;
      if Assigned(PTblType) then StrCopy(szTblType, PTblType);
      if FTableLevel > 0 then
      begin
        iOptParams := 1;
        StrCopy(@Level, PChar(IntToStr(FTableLevel)));
        pOptData := @Level;
        StrCopy(LvlFldDesc.szName, szCFGDRVLEVEL);
        LvlFldDesc.iLen := StrLen(Level) + 1;
        LvlFldDesc.iOffset := 0;
        pfldOptParams :=  @LvlFldDesc;
      end;
    end;
  end;

  procedure InitFieldDescriptors;
  var
    I: Integer;
    TempFieldDescs: TFieldDescList;
  begin
    with TableDesc do
    begin
      InitFieldDefsFromFields;
      iFldCount := FieldDefs.Count;
      SetLength(TempFieldDescs, iFldCount);
      for I := 0 to FieldDefs.Count - 1 do
      with FieldDefs[I] do
      begin
        EncodeFieldDesc(TempFieldDescs[I], Name, DataType, Size, Precision);
        if Required then Inc(iValChkCount);
      end;
      SetLength(FieldDescs, iFldCount);
      pFldDesc := BDE.PFLDDesc(FieldDescs);
      PSQLLName := nil;
      if Database.IsSQLBased then
        if DbiGetLdNameFromDB(DBHandle, nil, SQLLName) = 0 then
          PSQLLName := SQLLName;
      Check(DbiTranslateRecordStructure(nil, iFldCount, BDE.PFLDDesc(TempFieldDescs),
        GetDriverTypeName(DriverTypeName), PSQLLName, pFLDDesc, False));
    end;
  end;

  procedure InitIndexDescriptors;
  var
    I: Integer;
  begin
    TableDesc.iIdxCount := IndexDefs.Count;
    SetLength(IndexDescs, TableDesc.iIdxCount);
    TableDesc.pIdxDesc := PIDXDesc(IndexDescs);
    for I := 0 to IndexDefs.Count - 1 do
    with IndexDefs[I] do
      EncodeIndexDesc(IndexDescs[I], Name, FieldExpression, Options, DescFields);
  end;

  procedure InitValChecks;
  var
    I, ValCheckNo: Integer;
  begin
    with TableDesc do
    if iValChkCount > 0 then
    begin
      SetLength(ValChecks, iValChkCount);
      ValCheckNo := 0;
      for I := 0 to FieldDefs.Count - 1 do
        if FieldDefs[I].Required then
        begin
          ValChecks[ValCheckNo].iFldNum := I + 1;
          ValChecks[ValCheckNo].bRequired := True;
          Inc(ValCheckNo);
        end;
      pvchkDesc := BDE.pVCHKDesc(ValChecks);
    end;
  end;

begin
  CheckInactive;
  SetDBFlag(dbfTable, True);
  try
    InitTableSettings;
    LocaleSave := SetTempLocale(False);
    try
      InitFieldDescriptors;
      InitIndexDescriptors;
      InitValChecks;
      Check(DbiCreateTable(DBHandle, True, TableDesc));
    finally
      RestoreLocale(LocaleSave);
    end;
  finally
    SetDBFlag(dbfTable, False);
  end;
end;

procedure TTable.DeleteTable;
begin
  CheckInactive;
  SetDBFlag(dbfTable, True);
  try
    Check(DbiDeleteTable(DBHandle, NativeTableName, GetTableTypeName));
  finally
    SetDBFlag(dbfTable, False);
  end;
end;

procedure TTable.EmptyTable;
begin
  if Active then
  begin
    CheckBrowseMode;
    Check(DbiEmptyTable(DBHandle, Handle, nil, nil));
    ClearBuffers;
    DataEvent(deDataSetChange, 0);
  end else
  begin
    SetDBFlag(dbfTable, True);
    try
      Check(DbiEmptyTable(DBHandle, nil, NativeTableName, GetTableTypeName));
    finally
      SetDBFlag(dbfTable, False);
    end;
  end;
end;

procedure TTable.LockTable(LockType: TLockType);
begin
  SetTableLock(LockType, True);
end;

procedure TTable.SetTableLock(LockType: TLockType; Lock: Boolean);
var
  L: DBILockType;
begin
  CheckActive;
  if LockType = ltReadLock then L := dbiREADLOCK else L := dbiWRITELOCK;
  if Lock then
    Check(DbiAcqTableLock(Handle, L)) else
    Check(DbiRelTableLock(Handle, False, L));
end;

procedure TTable.UnlockTable(LockType: TLockType);
begin
  SetTableLock(LockType, False);
end;

procedure TTable.RenameTable(const NewTableName: string);
var
  SNewTableName: DBITBLNAME;
begin
  CheckInactive;
  SetDBFlag(dbfTable, True);
  try
    Check(DbiRenameTable(DBHandle, NativeTableName, GetTableTypeName,
      AnsiToNative(DBLocale, NewTableName, SNewTableName,
      SizeOf(SNewTableName) - 1)));
  finally
    SetDBFlag(dbfTable, False);
  end;
  TableName := NewTableName;
end;

procedure TTable.EncodeFieldDesc(var FieldDesc: FLDDesc;
  const Name: string; DataType: TFieldType; Size, Precision: Integer);
begin
  with FieldDesc do
  begin
    AnsiToNative(Locale, Name, szName, SizeOf(szName) - 1);
    iFldType := FldTypeMap[DataType];
    iSubType := FldSubTypeMap[DataType];
    case DataType of
      ftString, ftFixedChar, ftBytes, ftVarBytes, ftBlob..ftTypedBinary:
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

procedure TTable.DataEvent(Event: TDataEvent; Info: Longint);
begin
  if (Event = dePropertyChange) and Assigned(IndexDefs) then IndexDefs.Updated := False;
  inherited DataEvent(Event, Info);
end;

{ Informational & Property }

function TTable.GetCanModify: Boolean;
begin
  Result := inherited GetCanModify and not ReadOnly;
end;

function TTable.GetDriverTypeName(Buffer: PChar): PChar;
var
  Length: Word;
begin
  Result := Buffer;
  Check(DbiGetProp(HDBIOBJ(DBHandle), dbDATABASETYPE, Buffer,
    SizeOf(DBINAME), Length));
  if StrIComp(Buffer, szCFGDBSTANDARD) = 0 then
  begin
    Result := GetTableTypeName;
    if Result <> nil then Result := StrCopy(Buffer, Result);
  end;
end;

function TTable.GetTableTypeName: PChar;
begin
  if Database.IsSQLBased then Result := nil
  else Result := TableTypeDriverNames[GetTableType];
end;

function TTable.GetTableLevel: Integer;
begin
  if Handle <> nil then
    Result := GetIntProp(Handle, curTABLELEVEL) else
    Result := FTableLevel;
end;

function TTable.FieldDefsStored: Boolean;
begin
  Result := StoreDefs and (FieldDefs.Count > 0);
end;

function TTable.IndexDefsStored: Boolean;
begin
  Result := StoreDefs and (IndexDefs.Count > 0);
end;

function TTable.IsXBaseTable: Boolean;
begin
  Result := (TableType in [ttDBase, ttFoxPro]) or
    (CompareText(ExtractFileExt(TableName), '.DBF') = 0);
end;

function TTable.GetFileName: string;
const
  Exts: array [TTableType] of string = ('.DB', '.DB', '.DBF', '.DBF', '.TXT');
var
  FDb: Boolean;
begin
  FDb := SetDBFlag(dbfDatabase, True);
  try
    Result := Database.Directory;
    if (Result <> '') and (not IsPathDelimiter(Result, Length(Result))) then
      Result := Result + '\';
    if ExtractFileExt(TableName) = '' then
      Result := Result + ChangeFileExt(TableName, Exts[TableType]) else
      Result := Result + TableName;
  finally
    SetDBFlag(dbfDatabase, FDb);
  end;
end;

function TTable.GetTableType: TTableType;
var
  Name, Extension: string;
  FDb: Boolean;
begin
  Result := ttDefault;
  FDb := SetDBFlag(dbfDatabase, True);
  try
    if not Database.IsSQLBased then
      if TableType = ttDefault then
      begin
        Extension := ExtractFileExt(TableName);
        if CompareText(Extension, '.DB') = 0 then Result := ttParadox
        else if CompareText(Extension, '.DBF') = 0 then
        begin
          Name := GetFileName;
          if FileExists(ChangeFileExt(Name, '.FPT')) or
             FileExists(ChangeFileExt(Name, '.CDX')) then
            Result := ttFoxPro else
            Result := ttDBase;
        end
        else if CompareText(Extension, '.TXT') = 0 then Result := ttASCII
      end else Result := TableType;
  finally
    if not FDb then SetDBFlag(dbfDatabase, False);
  end;
end;

function TTable.NativeTableName: PChar;
begin
  if FNativeTableName[0] = #0 then
    AnsiToNative(DBLocale, FTableName, FNativeTableName, SizeOf(FNativeTableName) - 1);
  Result := FNativeTableName;
end;

procedure TTable.SetExclusive(Value: Boolean);
begin
  CheckInactive;
  FExclusive := Value;
end;

procedure TTable.SetReadOnly(Value: Boolean);
begin
  CheckInactive;
  FReadOnly := Value;
end;

procedure TTable.SetTableName(const Value: TFileName);
begin
  if csReading in ComponentState then
    FTableName := Value
  else if (FTableName <> Value) then
  begin
    CheckInactive;
    IndexFiles.Clear;
    FTableName := Value;
    FNativeTableName[0] := #0;
    DataEvent(dePropertyChange, 0);
  end;
end;

procedure TTable.SetTableType(Value: TTableType);
begin
  CheckInactive;
  FTableType := Value;
end;

{ TTable.IProviderSupport }

function TTable.PSGetDefaultOrder: TIndexDef;

  function GetIdx(IdxType: TIndexOption): TIndexDef;
  var
    i: Integer;
  begin
    Result := nil;
    for i := 0 to IndexDefs.Count - 1 do
      if IdxType in IndexDefs[i].Options then
      try
        Result := IndexDefs[i];
        GetFieldList(nil, Result.Fields);
        break;
      except
        Result := nil;
      end;
  end;

var
  DefIdx: TIndexDef;
begin
  DefIdx := nil;
  IndexDefs.Update;
  try
    if IndexName <> '' then
      DefIdx := IndexDefs.Find(IndexName)
    else if IndexFieldNames <> '' then
      DefIdx := IndexDefs.FindIndexForFields(IndexFieldNames);
    if Assigned(DefIdx) then
      GetFieldList(nil, DefIdx.Fields);
  except
    DefIdx := nil;
  end;
  if not Assigned(DefIdx) then
    DefIdx := GetIdx(ixPrimary);
  if not Assigned(DefIdx) then
    DefIdx := GetIdx(ixUnique);
  if Assigned(DefIdx) then
  begin
    Result := TIndexDef.Create(nil);
    Result.Assign(DefIdx);
  end else
    Result := nil;
end;

function TTable.PSGetIndexDefs(IndexTypes: TIndexOptions): TIndexDefs;
begin
  Result := GetIndexDefs(IndexDefs, IndexTypes);
end;

function TTable.PSGetTableName: string;
begin
  Result := TableName;
end;

procedure TTable.PSSetParams(AParams: TParams);

  procedure AssignFields;
  var
    I: Integer;
  begin
    for I := 0 to AParams.Count - 1 do
      if AParams[I].Name <> '' then
        FieldByName(AParams[I].Name).Value := AParams[I].Value else
        IndexFields[I].Value := AParams[I].Value;
  end;

begin
  if AParams.Count > 0 then
  begin
    Open;
    SetRangeStart;
    AssignFields;
    SetRangeEnd;
    AssignFields;
    ApplyRange;
  end else
    if Active then CancelRange;
  PSReset;
end;

procedure TTable.PSSetCommandText(const CommandText: string);
begin
  if CommandText <> '' then
    TableName := CommandText;
end;

function TTable.PSGetKeyFields: string;
var
  i, Pos: Integer;
  IndexFound: Boolean;
begin
  Result := inherited PSGetKeyFields;
  if Result = '' then
  begin
    if not Exists then Exit;
    IndexFound := False;
    IndexDefs.Update;
    for i := 0 to IndexDefs.Count - 1 do
      if ixUnique in IndexDefs[I].Options then
      begin
        Result := IndexDefs[I].Fields;
        IndexFound := (FieldCount = 0);
        if not IndexFound then
        begin
          Pos := 1;
          while Pos <= Length(Result) do
          begin
            IndexFound := FindField(ExtractFieldName(Result, Pos)) <> nil;
            if not IndexFound then Break;
          end;
        end;
        if IndexFound then Break;
      end;
    if not IndexFound then
      Result := '';
  end;
end;

{ TQueryDataLink }

constructor TQueryDataLink.Create(AQuery: TQuery);
begin
  inherited Create;
  FQuery := AQuery;
end;

procedure TQueryDataLink.ActiveChanged;
begin
  if FQuery.Active then FQuery.RefreshParams;
end;

function TQueryDataLink.GetDetailDataSet: TDataSet;
begin
  Result := FQuery;
end;

procedure TQueryDataLink.RecordChanged(Field: TField);
begin
  if (Field = nil) and FQuery.Active then FQuery.RefreshParams;
end;

procedure TQueryDataLink.CheckBrowseMode;
begin
  if FQuery.Active then FQuery.CheckBrowseMode;
end;

{ TStoredProc }

constructor TStoredProc.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FParams := TParams.Create(Self);
end;

destructor TStoredProc.Destroy;
begin
  Destroying;
  Disconnect;
  FParams.Free;
  inherited Destroy;
end;

procedure TStoredProc.DefineProperties(Filer: TFiler);

  function WriteData: Boolean;
  begin
    if Filer.Ancestor <> nil then
      Result := not FParams.IsEqual(TStoredProc(Filer.Ancestor).FParams) else
      Result := FParams.Count > 0;
  end;

begin
  inherited DefineProperties(Filer);
  Filer.DefineProperty('ParamData', ReadParamData, WriteParamData, WriteData);
end;

procedure TStoredProc.WriteParamData(Writer: TWriter);
begin
  Writer.WriteCollection(Params);
end;

procedure TStoredProc.ReadParamData(Reader: TReader);
begin
  Reader.ReadValue;
  Reader.ReadCollection(Params);
end;

procedure TStoredProc.Disconnect;
begin
  Close;
  UnPrepare;
end;

function TStoredProc.CreateCursor(GenHandle: Boolean): HDBICur;
begin
  if StoredProcName <> '' then
  begin
    SetPrepared(True);
    Result := GetCursor(GenHandle);
  end else
    Result := nil;
end;

function TStoredProc.CreateHandle: HDBICur;
begin
  Result := CreateCursor(True);
end;

function TStoredProc.GetCursor(GenHandle: Boolean): HDBICur;
var
  PCursor: phDBICur;
begin
  Result := nil;
  if GenHandle then PCursor := @Result
  else PCursor := nil;
  BindParams;
  Check(DbiQExec(StmtHandle, PCursor));
  GetResults;
end;

procedure TStoredProc.ExecProc;
begin
  CheckInActive;
  SetDBFlag(dbfExecProc, True);
  try
    CreateCursor(False);
  finally
    SetDBFlag(dbfExecProc, False);
  end;
end;

procedure TStoredProc.SetProcName(const Value: string);
begin
  if not (csReading in ComponentState) then
  begin
    CheckInactive;
    if Value <> FProcName then
    begin
      FProcName := Value;
      FreeStatement;
      FParams.Clear;
    end;
  end else
    FProcName := Value;
end;

procedure TStoredProc.SetOverLoad(Value: Word);
begin
  if not (csReading in ComponentState) then
  begin
    CheckInactive;
    if Value <> OverLoad then
    begin
      FOverLoad := Value;
      FreeStatement;
      FParams.Clear;
    end
  end else
    FOverLoad := Value;
end;

function TStoredProc.GetParamsCount: Word;
begin
  Result := FParams.Count;
end;

procedure TStoredProc.CreateParamDesc;
var
  Desc: SPParamDesc;
  Cursor: HDBICur;
  Buffer: DBISPNAME;
  ParamName: string;
  ParamDataType: TFieldType;
begin
  AnsiToNative(DBLocale, StoredProcName, Buffer, SizeOf(Buffer)-1);
  if DbiOpenSPParamList(DBHandle, Buffer, False, OverLoad, Cursor) = 0 then
  try
    while DbiGetNextRecord(Cursor, dbiNOLOCK, @Desc, nil) = 0 do
      with Desc do
      begin
        NativeToAnsi(DBLocale, szName, ParamName);
        if (TParamType(eParamType) = ptResult) and (ParamName = '') then
          ParamName := SResultName;
        if uFldType < MAXLOGFLDTYPES then ParamDataType := DataTypeMap[uFldType]
        else ParamDataType := ftUnknown;
        case uFldtype of
          fldFloat:
             if uSubType = fldstMONEY then ParamDataType := ftCurrency;
          fldBlob:
             if (uSubType >= fldstMEMO) and (uSubType <= fldstBFILE) then
               ParamDataType := BlobTypeMap[uSubType];
        end;
        with TParam(FParams.Add) do
        begin
          ParamType := TParamType(eParamType);
          DataType := ParamDataType;
          Name := ParamName;
        end;
      end;
    SetServerParams;
  finally
    DbiCloseCursor(Cursor);
  end;
end;

procedure TStoredProc.SetServerParams;
var
  I: Integer;
begin
  SetLength(FServerDescs, Params.Count);
  for I := 0 to Params.Count - 1 do
    with TParam(Params[I]), FServerDescs[I] do
    begin
      ParamName := Name;
      BindType := DataType;
    end;
end;

function TStoredProc.CheckServerParams: Boolean;
var
  Low, I, J: Integer;
begin
  if FServerDescs = nil then
  begin
    SetServerParams;
    Result := False;
  end else
  begin
    Low := 0;
    for I := 0 to High(FServerDescs) do
    begin
      for J := Low to Params.Count - 1 do
        with TParam(Params[J]), FServerDescs[I] do
          if Name = ParamName then
            if (DataType <> BindType) then
            begin
              Result := False;
              Exit;
            end else
            begin
              if J = Low then inc(Low);
              Break;
            end;
    end;
    Result := True;
  end;
end;

function TStoredProc.DescriptionsAvailable: Boolean;
var
  Cursor: HDBICur;
  Buffer: DBISPNAME;
begin
  SetDBFlag(dbfProcDesc, True);
  try
    AnsiToNative(DBLocale, StoredProcName, Buffer, SizeOf(Buffer)-1);
    Result := DbiOpenSPParamList(DBHandle, Buffer, False, OverLoad, Cursor) = 0;
    if Result then DbiCloseCursor(Cursor);
  finally
    SetDBFlag(dbfProcDesc, False);
  end;
end;

procedure TStoredProc.PrepareProc;
var
  I: Integer;
  NumBytes, Offset: Word;
  Buffer: DBISPNAME;
begin
  SetLength(FParamDescs, FParams.Count);
  NumBytes := 0;
  for I := 0 to FParams.Count - 1 do
    with Params[I] do
      if DataType in [ftString, ftFixedChar] then Inc(NumBytes, 255 + 2)
      else Inc(NumBytes, GetParamDataSize(Params[I]) + 2);
  SetLength(FRecordBuffer, NumBytes);
  Offset := 0;
  for I := 0 to FParams.Count - 1 do
  begin
    with Params[I], FParamDescs[I] do
    begin
      if DataType = ftUnknown then
        DatabaseErrorFmt(SNoParameterValue, [Name], Self);
      if ParamType = ptUnknown then
        DatabaseErrorFmt(SNoParameterType, [Name], Self);
      if FBindMode = pbByName then
        AnsiToNative(Locale, Name, szName, SizeOf(szName) - 1)
      else uParamNum := I + 1;
      eParamType := STMTParamType(ParamType);
      uFldType := FldTypeMap[DataType];
      uSubType := FldSubTypeMap[DataType];
      if uFldType = fldZString then
      begin
        uLen := 255;
        iUnits1 := 255;
      end
      else if uFldType = fldADT then
      begin
        iUnits1 := Value;
        iUnits2 := Value;
        AnsiToNative(Locale, Name, szName, SizeOf(szName) - 1)
      end else
        uLen := GetParamDataSize(Params[I]);
      uOffset := Offset;
      Inc(Offset, uLen);
      uNullOffset := NumBytes - 2 * (I + 1);
      if ParamType in [ptInput, ptInputOutput] then
        PSmallint(@FRecordBuffer[NumBytes - 2 * (I + 1)])^ := IndNull;
    end;
  end;
  AnsiToNative(Locale, StoredProcName, Buffer, SizeOf(Buffer)-1);
  Check(DbiQPrepareProc(DBHandle, Buffer, High(FParamDescs)+1,
    PSPParamDesc(FParamDescs), nil, FStmtHandle));
end;

procedure TStoredProc.GetResults;
var
  I: Integer;
  CurPtr: PChar;
  IntPtr: ^SmallInt;
  NumBytes: Word;
begin
  if FRecordBuffer <> nil then
  begin
    CurPtr := PChar(FRecordBuffer);
    NumBytes := High(FRecordBuffer) + 1;
    for I := 0 to FParams.Count - 1 do
      with Params[I] do
      begin
        if ParamType in [ptOutput, ptInputOutput, ptResult] then
        begin
          if DataType in [ftString, ftFixedChar] then
            NativeToAnsiBuf(Locale, CurPtr, CurPtr, StrLen(CurPtr));
          IntPtr := @FRecordBuffer[NumBytes - 2 * (I + 1)];
          if IntPtr^ = IndNull then Value := NULL
          else if IntPtr^ = IndTrunc then DatabaseErrorFmt(STruncationError, [Name])
          else SetData(CurPtr);
        end;
        if DataType in [ftString, ftFixedChar] then Inc(CurPtr, 255)
        else Inc(CurPtr, GetParamDataSize(Params[I]));
      end;
  end;
end;

procedure TStoredProc.BindParams;
var
  I: Integer;
  CurPtr: PChar;
  NumBytes: Word;
  IntPtr: ^SmallInt;
  DrvLocale: TLocale;
begin
  if FRecordBuffer = nil then Exit;
  if not CheckServerParams then
  begin
    SetPrepared(False);
    SetPrepared(True);
  end;
  NumBytes := High(FRecordBuffer) + 1;
  CurPtr := PChar(FRecordBuffer);
  DrvLocale := GetStatementLocale(StmtHandle);
  try
    for I := 0 to FParams.Count - 1 do
    begin
      with Params[I] do
      begin
        if ParamType in [ptInput, ptInputOutput] then
        begin
          GetParamData(Params[i], CurPtr, DrvLocale);
          IntPtr := @FRecordBuffer[NumBytes - 2 * (I + 1)];
          if IsNull then IntPtr^ := IndNull
          else IntPtr^ := 0;
        end;
        if DataType in [ftString, ftFixedChar] then
        begin
          Inc(CurPtr, 255);
          { Adjust param descriptor for string pseudo blobs }
          if ParamType = ptInput then
            with FParamDescs[I] do
            begin
              uLen := GetParamDataSize(Params[I]);
              if uFldType = fldZString then
                iUnits1 := GetDataSize - 1 {Do not include null terminator} else
                iUnits1 := GetDataSize;
            end
        end
        else
          Inc(CurPtr, GetParamDataSize(Params[I]));
      end;
    end;
    Check(DbiQSetProcParams(StmtHandle, High(FParamDescs)+1,
      PSPParamDesc(FParamDescs), FRecordBuffer));
  finally
    FreeStatementLocale(DrvLocale);
  end;
end;

procedure TStoredProc.SetPrepared(Value: Boolean);
begin
  if Handle <> nil then DatabaseError(SDataSetOpen, Self);
  if Prepared <> Value then
  begin
    if Value then
      try
        if FParams.Count = 0 then CreateParamDesc
        else SetServerParams;
        if not FQueryMode then PrepareProc;
        FPrepared := True;
      except
        FreeStatement;
        raise;
      end
    else FreeStatement;
  end;
end;

procedure TStoredProc.Prepare;
begin
  SetDBFlag(dbfStoredProc, True);
  SetPrepared(True);
end;

procedure TStoredProc.UnPrepare;
begin
  SetPrepared(False);
  SetDBFlag(dbfStoredProc, False);
end;

procedure TStoredProc.FreeStatement;
begin
  if StmtHandle <> nil then DbiQFree(FStmtHandle);
  FParamDescs := nil;
  FServerDescs := nil;
  FRecordBuffer := nil;
  FPrepared := False;
end;

procedure TStoredProc.SetPrepare(Value: Boolean);
begin
  if Value then Prepare
  else UnPrepare;
end;

function TStoredProc.SetDBFlag(Flag: Integer; Value: Boolean): Boolean;
begin
  if not Value and (DBFlags - [Flag] = []) then SetPrepared(False);
  Result := inherited SetDBFlag(Flag, Value);
end;

procedure TStoredProc.CopyParams(Value: TParams);
begin
  if not Prepared and (FParams.Count = 0) then
  try
    FQueryMode := True;
    Prepare;
    Value.Assign(FParams);
  finally
    UnPrepare;
    FQueryMode := False;
  end else
    Value.Assign(FParams);
end;

procedure TStoredProc.SetParamsList(Value: TParams);
begin
  CheckInactive;
  if Prepared then
  begin
    SetPrepared(False);
    FParams.Assign(Value);
    SetPrepared(True);
  end else
    FParams.Assign(Value);
end;

function TStoredProc.ParamByName(const Value: string): TParam;
begin
  Result := FParams.ParamByName(Value);
end;

{ TStoredProc.IProviderSupport }

function TStoredProc.PSGetParams: TParams;
begin
  Result := Params;
end;

procedure TStoredProc.PSSetParams(AParams: TParams);
begin
  if AParams.Count > 0 then
    Params.Assign(AParams);
  Close;
end;

function TStoredProc.PSGetTableName: string;
begin
  Result := inherited PSGetTableName;
end;

procedure TStoredProc.PSExecute;
begin
  ExecProc;
end;

procedure TStoredProc.PSSetCommandText(const CommandText: string);
begin
  if CommandText <> '' then
    StoredProcName := CommandText;
end;

{ TQuery }

constructor TQuery.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FSQL := TStringList.Create;
  TStringList(SQL).OnChange := QueryChanged;
  FParams := TParams.Create(Self);
  FDataLink := TQueryDataLink.Create(Self);
  RequestLive := False;
  ParamCheck := True;
  FRowsAffected := -1;
end;

destructor TQuery.Destroy;
begin
  Destroying;
  Disconnect;
  SQL.Free;
  FParams.Free;
  FDataLink.Free;
  StrDispose(SQLBinary);
  inherited Destroy;
end;

procedure TQuery.Disconnect;
begin
  Close;
  UnPrepare;
end;

procedure TQuery.SetPrepare(Value: Boolean);
begin
  if Value then Prepare
  else UnPrepare;
end;

procedure TQuery.Prepare;
begin
  SetDBFlag(dbfPrepared, True);
  SetPrepared(True);
end;

procedure TQuery.UnPrepare;
begin
  SetPrepared(False);
  SetDBFlag(dbfPrepared, False);
end;

procedure TQuery.SetDataSource(Value: TDataSource);
begin
  if IsLinkedTo(Value) then DatabaseError(SCircularDataLink, Self);
  FDataLink.DataSource := Value;
end;

function TQuery.GetDataSource: TDataSource;
begin
  Result := FDataLink.DataSource;
end;

procedure TQuery.SetQuery(Value: TStrings);
begin
  if SQL.Text <> Value.Text then
  begin
    Disconnect;
    SQL.BeginUpdate;
    try
      SQL.Assign(Value);
    finally
      SQL.EndUpdate;
    end;
  end;
end;

procedure TQuery.QueryChanged(Sender: TObject);
var
  List: TParams;
begin
  if not (csReading in ComponentState) then
  begin
    Disconnect;
    StrDispose(SQLBinary);
    SQLBinary := nil;
    if ParamCheck or (csDesigning in ComponentState) then
    begin
      List := TParams.Create(Self);
      try
        FText := List.ParseSQL(SQL.Text, True);
        List.AssignValues(FParams);
        FParams.Clear;
        FParams.Assign(List);
      finally
        List.Free;
      end;
    end else
      FText := SQL.Text;
    DataEvent(dePropertyChange, 0);
  end else
    FText := FParams.ParseSQL(SQL.Text, False);
end;

procedure TQuery.SetParamsList(Value: TParams);
begin
  FParams.AssignValues(Value);
end;

function TQuery.GetParamsCount: Word;
begin
  Result := FParams.Count;
end;

procedure TQuery.DefineProperties(Filer: TFiler);

  function WriteData: Boolean;
  begin
    if Filer.Ancestor <> nil then
      Result := not FParams.IsEqual(TQuery(Filer.Ancestor).FParams) else
      Result := FParams.Count > 0;
  end;

begin
  inherited DefineProperties(Filer);
  Filer.DefineBinaryProperty('Data', ReadBinaryData, WriteBinaryData, SQLBinary <> nil);
  Filer.DefineProperty('ParamData', ReadParamData, WriteParamData, WriteData);
end;

procedure TQuery.ReadParamData(Reader: TReader);
begin
  Reader.ReadValue;
  Reader.ReadCollection(FParams);
end;

procedure TQuery.WriteParamData(Writer: TWriter);
begin
  Writer.WriteCollection(Params);
end;

procedure TQuery.ReadBinaryData(Stream: TStream);
begin
  SQLBinary := StrAlloc(Stream.Size);
  Stream.ReadBuffer(SQLBinary^, Stream.Size);
end;

procedure TQuery.WriteBinaryData(Stream: TStream);
begin
  Stream.WriteBuffer(SQLBinary^, StrBufSize(SQLBinary));
end;

procedure TQuery.SetPrepared(Value: Boolean);
begin
  if Handle <> nil then DatabaseError(SDataSetOpen, Self);
  if Value <> Prepared then
  begin
    if Value then
    begin
      FRowsAffected := -1;
      FCheckRowsAffected := True;
      if Length(Text) > 1 then PrepareSQL(PChar(Text))
      else DatabaseError(SEmptySQLStatement, Self);
    end
    else
    begin
      if FCheckRowsAffected then
        FRowsAffected := RowsAffected;
      FreeStatement;
    end;
    FPrepared := Value;
  end;
end;

procedure TQuery.FreeStatement;
var
  Result: DbiResult;
begin
  if StmtHandle <> nil then
  begin
    Result := DbiQFree(FStmtHandle);
    if not (csDestroying in ComponentState) then
      Check(Result);
  end;
end;

procedure TQuery.SetParamsFromCursor;
var
  I: Integer;
  DataSet: TDataSet;
begin
  if FDataLink.DataSource <> nil then
  begin
    DataSet := FDataLink.DataSource.DataSet;
    if DataSet <> nil then
    begin
      DataSet.FieldDefs.Update;
      for I := 0 to FParams.Count - 1 do
        with FParams[I] do
          if not Bound then
          begin
            AssignField(DataSet.FieldByName(Name));
            Bound := False;
          end;
    end;
  end;
end;

procedure TQuery.RefreshParams;
var
  DataSet: TDataSet;
begin
  DisableControls;
  try
    if FDataLink.DataSource <> nil then
    begin
      DataSet := FDataLink.DataSource.DataSet;
      if DataSet <> nil then
        if DataSet.Active and (DataSet.State <> dsSetKey) then
        begin
          Close;
          Open;
        end;
    end;
  finally
    EnableControls;
  end;
end;

function TQuery.ParamByName(const Value: string): TParam;
begin
  Result := FParams.ParamByName(Value);
end;

function TQuery.CreateCursor(GenHandle: Boolean): HDBICur;
begin
  if SQL.Count > 0 then
  begin
    FExecSQL := not GenHandle;
    try
      SetPrepared(True);
    finally
      FExecSQL := False;
    end;
    if FDataLink.DataSource <> nil then SetParamsFromCursor;
    Result := GetQueryCursor(GenHandle);
  end else
  begin
    DatabaseError(SEmptySQLStatement, Self);
    Result := nil;
  end;
  FCheckRowsAffected := (Result = nil);
end;

function TQuery.CreateHandle: HDBICur;
begin
  Result := CreateCursor(True)
end;

procedure TQuery.ExecSQL;
begin
  CheckInActive;
  SetDBFlag(dbfExecSQL, True);
  try
    CreateCursor(False);
  finally
    SetDBFlag(dbfExecSQL, False);
  end;
end;

function TQuery.GetQueryCursor(GenHandle: Boolean): HDBICur;
var
  PCursor: phDBICur;
begin
  Result := nil;
  if GenHandle then PCursor := @Result
  else PCursor := nil;
  if FParams.Count > 0 then SetQueryParams(Self, StmtHandle, Params);
  Check(DbiQExec(StmtHandle, PCursor));
end;

function TQuery.SetDBFlag(Flag: Integer; Value: Boolean): Boolean;
var
  NewConnection: Boolean;
begin
  if Value then
  begin
    NewConnection := DBFlags = [];
    Result := inherited SetDBFlag(Flag, Value);
    if not (csReading in ComponentState) and NewConnection then
      FLocal := not Database.IsSQLBased;
  end
  else begin
    if DBFlags - [Flag] = [] then SetPrepared(False);
    Result := inherited SetDBFlag(Flag, Value);
  end;
end;

procedure TQuery.PrepareSQL(Value: PChar);
begin
  GetStatementHandle(Value);
  if not Local then
    SetBoolProp(StmtHandle, stmtUNIDIRECTIONAL, FUniDirectional);
end;

procedure TQuery.GetStatementHandle(SQLText: PChar);
const
  DataType: array[Boolean] of LongInt = (Ord(wantCanned), Ord(wantLive));
begin
  Check(DbiQAlloc(DBHandle, qrylangSQL, FStmtHandle));
  try
    if not FExecSQL then
      Check(DBiSetProp(hDbiObj(StmtHandle), stmtLIVENESS,
        DataType[RequestLive and not ForceUpdateCallback]));
    if Local then
    begin
      SetBoolProp(StmtHandle, stmtAUXTBLS, False);
      if RequestLive and Constrained then
        SetBoolProp(StmtHandle, stmtCONSTRAINED, True);
      SetBoolProp(StmtHandle, stmtCANNEDREADONLY, True);
    end;
    while not CheckOpen(DbiQPrepare(FStmtHandle, SQLText)) do
      {Retry};
  except
    DbiQFree(FStmtHandle);
    FStmtHandle := nil;
    raise;
  end;
end;

function TQuery.GetRowsAffected: Integer;
var
  Length: Word;
begin
  if Prepared then
    if DbiGetProp(hDBIObj(StmtHandle), stmtROWCOUNT, @Result, SizeOf(Result),
      Length) <> 0 then
      Result := -1
    else
  else Result := FRowsAffected;
end;

procedure TQuery.GetDetailLinkFields(MasterFields, DetailFields: TList);

  function AddFieldToList(const FieldName: string; DataSet: TDataSet;
    List: TList): Boolean;
  var
    Field: TField;
  begin
    Field := DataSet.FindField(FieldName);
    if (Field <> nil) then
      List.Add(Field);
    Result := Field <> nil;
  end;

var
  i: Integer;
begin
  MasterFields.Clear;
  DetailFields.Clear;
  if (DataSource <> nil) and (DataSource.DataSet <> nil) then
    for i := 0 to Params.Count - 1 do
      if AddFieldToList(Params[i].Name, DataSource.DataSet, MasterFields) then
        AddFieldToList(Params[i].Name, Self, DetailFields);
end;

{ TQuery.IProviderSupport }

function TQuery.PSGetDefaultOrder: TIndexDef;
begin
  Result := inherited PSGetDefaultOrder;
  if not Assigned(Result) then
    Result := GetIndexForOrderBy(SQL.Text, Self);
end;

function TQuery.PSGetParams: TParams;
begin
  Result := Params;
end;

procedure TQuery.PSSetParams(AParams: TParams);
begin
  if AParams.Count <> 0 then
    Params.Assign(AParams);
  Close;
end;

function TQuery.PSGetTableName: string;
begin
  Result := GetTableNameFromSQL(SQL.Text);
end;

procedure TQuery.PSExecute;
begin
  ExecSQL;
end;

procedure TQuery.PSSetCommandText(const CommandText: string);
begin
  if CommandText <> '' then
    SQL.Text := CommandText;
end;

{ TUpdateSQL }

constructor TUpdateSQL.Create(AOwner: TComponent);
var
  UpdateKind: TUpdateKind;
begin
  inherited Create(AOwner);
  for UpdateKind := Low(TUpdateKind) to High(TUpdateKind) do
  begin
    FSQLText[UpdateKind] := TStringList.Create;
    TStringList(FSQLText[UpdateKind]).OnChange := SQLChanged;
  end;
end;

destructor TUpdateSQL.Destroy;
var
  UpdateKind: TUpdateKind;
begin
  if Assigned(FDataSet) and (FDataset is TBDEDataset) and 
    (TBDEDataset(FDataSet).UpdateObject = Self) then 
    TBDEDataset(FDataSet).UpdateObject := nil;
  for UpdateKind := Low(TUpdateKind) to High(TUpdateKind) do
    FSQLText[UpdateKind].Free;
  inherited Destroy;
end;

procedure TUpdateSQL.ExecSQL(UpdateKind: TUpdateKind);
begin
  with Query[UpdateKind] do
  begin
    Prepare;
    ExecSQL;
    if RowsAffected <> 1 then DatabaseError(SUpdateFailed);
  end;
end;

function TUpdateSQL.GetQuery(UpdateKind: TUpdateKind): TQuery;
begin
  if not Assigned(FQueries[UpdateKind]) then
  begin
    FQueries[UpdateKind] := TQuery.Create(Self);
    FQueries[UpdateKind].SQL.Assign(FSQLText[UpdateKind]);
    if (FDataSet is TDBDataSet) then
    begin
      FQueries[UpdateKind].SessionName := TDBDataSet(FDataSet).SessionName;
      FQueries[UpdateKind].DatabaseName := TDBDataSet(FDataSet).DataBaseName;
    end
    else begin 
      FQueries[UpdateKind].SessionName := Self.SessionName; 
      FQueries[UpdateKind].DatabaseName := Self.DataBaseName; 
    end; 
  end;
  Result := FQueries[UpdateKind];
end;

function TUpdateSQL.GetSQL(UpdateKind: TUpdateKind): TStrings;
begin
  Result := FSQLText[UpdateKind];
end;

function TUpdateSQL.GetSQLIndex(Index: Integer): TStrings;
begin
  Result := FSQLText[TUpdateKind(Index)];
end;

function TUpdateSQL.GetDataSet: TDataSet;
begin
  Result := FDataSet;
end;

procedure TUpdateSQL.SetDataSet(ADataSet: TDataSet);
begin
  FDataSet := ADataSet;
end;

procedure TUpdateSQL.SetSQL(UpdateKind: TUpdateKind; Value: TStrings);
begin
  FSQLText[UpdateKind].Assign(Value);
end;

procedure TUpdateSQL.SetSQLIndex(Index: Integer; Value: TStrings);
begin
  SetSQL(TUpdateKind(Index), Value);
end;

procedure TUpdateSQL.SQLChanged(Sender: TObject);
var
  UpdateKind: TUpdateKind;
begin
  for UpdateKind := Low(TUpdateKind) to High(TUpdateKind) do
    if Sender = FSQLText[UpdateKind] then
    begin
      if Assigned(FQueries[UpdateKind]) then
      begin
        FQueries[UpdateKind].Params.Clear;
        FQueries[UpdateKind].SQL.Assign(FSQLText[UpdateKind]);
      end;
      Break;
    end;
end;

procedure TUpdateSQL.SetParams(UpdateKind: TUpdateKind);
var
  I: Integer;
  Old: Boolean;
  Param: TParam;
  PName: string;
  Field: TField;
  Value: Variant;
begin
  if not Assigned(FDataSet) then Exit;
  with Query[UpdateKind] do
  begin
    for I := 0 to Params.Count - 1 do
    begin
      Param := Params[I];
      PName := Param.Name;
      Old := CompareText(Copy(PName, 1, 4), 'OLD_') = 0;
      if Old then System.Delete(PName, 1, 4);
      Field := FDataSet.FindField(PName);
      if not Assigned(Field) then Continue;
      if Old then Param.AssignFieldValue(Field, Field.OldValue) else
      begin
        Value := Field.NewValue;
        if VarIsClear(Value) then Value := Field.OldValue;
        Param.AssignFieldValue(Field, Value);
      end;
    end;
  end;
end;

procedure TUpdateSQL.Apply(UpdateKind: TUpdateKind);
begin
  SetParams(UpdateKind);
  ExecSQL(UpdateKind);
end;

{ TBlobStream }

constructor TBlobStream.Create(Field: TBlobField; Mode: TBlobStreamMode);
var
  OpenMode: DbiOpenMode;
begin
  FMode := Mode;
  FField := Field;
  FDataSet := FField.DataSet as TBDEDataSet;
  FFieldNo := FField.FieldNo;
  if not FDataSet.GetActiveRecBuf(FBuffer) then Exit;
  if FDataSet.State = dsFilter then
    DatabaseErrorFmt(SNoFieldAccess, [FField.DisplayName], FDataSet);
  if not FField.Modified then
  begin
    if Mode = bmRead then
    begin
      FCached := FDataSet.FCacheBlobs and (FBuffer = FDataSet.ActiveBuffer) and
        (FField.IsNull or (FDataSet.GetBlobData(FField, FBuffer) <> ''));
      OpenMode := dbiReadOnly;
    end else
    begin
      FDataSet.SetBlobData(FField, FBuffer, '');
      if FField.ReadOnly then DatabaseErrorFmt(SFieldReadOnly,
        [FField.DisplayName], FDataSet);
      if not (FDataSet.State in [dsEdit, dsInsert]) then
        DatabaseError(SNotEditing, FDataSet);
      OpenMode := dbiReadWrite;
    end;
    if not FCached then
    begin
      if FDataSet.State = dsBrowse then
        FDataSet.GetCurrentRecord(FDataSet.ActiveBuffer);
      Check(DbiOpenBlob(FDataSet.Handle, FBuffer, FFieldNo, OpenMode));
    end;
  end;
  FOpened := True;
  if Mode = bmWrite then Truncate;
end;

destructor TBlobStream.Destroy;
begin
  if FOpened then
  begin
    if FModified then FField.Modified := True;
    if not FField.Modified and not FCached then
      DbiFreeBlob(FDataSet.Handle, FBuffer, FFieldNo);
  end;
  if FModified then
  try
    FDataSet.DataEvent(deFieldChange, Longint(FField));
  except
    ApplicationHandleException(Self);
  end;
end;

function TBlobStream.Read(var Buffer; Count: Longint): Longint;
var
  Status: DBIResult;
begin
  Result := 0;
  if FOpened then
  begin
    if FCached then
    begin
      if Count > Size - FPosition then
        Result := Size - FPosition else
        Result := Count;
      if Result > 0 then
      begin
        Move(PChar(FDataSet.GetBlobData(FField, FBuffer))[FPosition], Buffer, Result);
        Inc(FPosition, Result);
      end;
    end else
    begin
      Status := DbiGetBlob(FDataSet.Handle, FBuffer, FFieldNo, FPosition,
        Count, @Buffer, Result);
      case Status of
        DBIERR_NONE, DBIERR_ENDOFBLOB:
          begin
            if FField.Transliterate then
              NativeToAnsiBuf(FDataSet.Locale, @Buffer, @Buffer, Result);
            if FDataset.FCacheBlobs and (FBuffer = FDataSet.ActiveBuffer) and
              (FMode = bmRead) and not FField.Modified and (FPosition = FCacheSize) then
            begin
              FCacheSize := FPosition + Result;
              SetLength(FBlobData, FCacheSize);
              Move(Buffer, PChar(FBlobData)[FPosition], Result);
              if FCacheSize = Size then
              begin
                FDataSet.SetBlobData(FField, FBuffer, FBlobData);
                FBlobData := '';
                FCached := True;
                DbiFreeBlob(FDataSet.Handle, FBuffer, FFieldNo);
              end;
            end;
            Inc(FPosition, Result);
          end;
        DBIERR_INVALIDBLOBOFFSET:
          {Nothing};
      else
        DbiError(Status);
      end;
    end;
  end;
end;

function TBlobStream.Write(const Buffer; Count: Longint): Longint;
var
  Temp: Pointer;
begin
  Result := 0;
  if FOpened then
  begin
    if FField.Transliterate then
    begin
      GetMem(Temp, Count);
      try
        AnsiToNativeBuf(FDataSet.Locale, @Buffer, Temp, Count);
        Check(DbiPutBlob(FDataSet.Handle, FBuffer, FFieldNo, FPosition,
          Count, Temp));
      finally
        FreeMem(Temp, Count);
      end;
    end else
      Check(DbiPutBlob(FDataSet.Handle, FBuffer, FFieldNo, FPosition,
        Count, @Buffer));
    Inc(FPosition, Count);
    Result := Count;
    FModified := True;
    FDataSet.SetBlobData(FField, FBuffer, '');
  end;
end;

function TBlobStream.Seek(Offset: Longint; Origin: Word): Longint;
begin
  case Origin of
    0: FPosition := Offset;
    1: Inc(FPosition, Offset);
    2: FPosition := GetBlobSize + Offset;
  end;
  Result := FPosition;
end;

procedure TBlobStream.Truncate;
begin
  if FOpened then
  begin
    Check(DbiTruncateBlob(FDataSet.Handle, FBuffer, FFieldNo, FPosition));
    FModified := True;
    FDataSet.SetBlobData(FField, FBuffer, '');
  end;
end;

function TBlobStream.GetBlobSize: Longint;
begin
  Result := 0;
  if FOpened then
    if FCached then
      Result := Length(FDataSet.GetBlobData(FField, FBuffer)) else
      Check(DbiGetBlobSize(FDataSet.Handle, FBuffer, FFieldNo, Result));
end;

var
  SaveInitProc: Pointer;
  NeedToUninitialize: Boolean;

procedure InitDBTables;
begin
  if SaveInitProc <> nil then TProcedure(SaveInitProc);
  NeedToUninitialize := Succeeded(CoInitialize(nil));
end;

initialization
  if not IsLibrary then
  begin
    SaveInitProc := InitProc;
    InitProc := @InitDBTables;
  end;
  Sessions := TSessionList.Create;
  Session := TSession.Create(nil);
  Session.SessionName := 'Default'; { Do not localize }
  InitializeCriticalSection(CSNativeToAnsi);
  InitializeCriticalSection(CSAnsiToNative);
finalization
  DeleteCriticalSection(CSAnsiToNative);
  DeleteCriticalSection(CSNativeToAnsi);
  Sessions.Free;
  Sessions := nil;
  FreeAndNil(BDEInitProcs);
  FreeTimer(True);
  if NeedToUninitialize then CoUninitialize;
end.
