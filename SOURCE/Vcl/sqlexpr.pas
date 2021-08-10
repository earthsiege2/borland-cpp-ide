{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 1999, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit SqlExpr;

{$R-,T-,H+,X+}

interface

{$IFDEF MSWINDOWS}
uses Windows, SysUtils, Variants, Classes, DB, DBCommon, DBXpress, SqlTimSt;
{$ENDIF}
{$IFDEF LINUX}
uses Libc, SysUtils, Variants, Classes, DB, DBCommon, DBXpress, SqlTimSt;
{$ENDIF}

const

  SSelect         =   'select';               { Do not localize }
  SSelectStar     =   ' select * ';           { Do not localize }
  SSelectStarFrom =   ' select * from ';      { Do not localize }
  SWhere          =   ' where ';              { Do not localize }
  SAnd            =   ' and ';                { Do not localize }
  SOrderBy        =   ' order by ';           { Do not localize }
  SParam          =   '?';                    { Do not localize }
  DefaultCursor   =   0;
  HourGlassCursor =   -11;

{ Default Max BlobSize }

  DefaultMaxBlobSize = -1;   // values are in K; -1 means retrieve actual size 

{ Default RowsetSize }

  DefaultRowsetSize = 20;

  TErrorMessageSize = 2048;

{ FieldType Mappings }

  FldTypeMap: TFieldMap = (
    fldUNKNOWN, fldZSTRING, fldINT16, fldINT32, fldUINT16, fldBOOL,
    fldFLOAT, fldFLOAT, fldBCD, fldDATE, fldTIME, fldTIMESTAMP, fldBYTES,
    fldVARBYTES, fldINT32, fldBLOB, fldBLOB, fldBLOB, fldBLOB, fldBLOB,
    fldBLOB, fldBLOB, fldCURSOR, fldZSTRING, fldZSTRING, fldINT64, fldADT,
    fldArray, fldREF, fldTABLE, fldBLOB, fldBLOB, fldUNKNOWN, fldUNKNOWN,
    fldUNKNOWN, fldZSTRING, fldDATETIME, fldFMTBCD);

  FldSubTypeMap: array[TFieldType] of Word = (
    0, 0, 0, 0, 0, 0, 0, fldstMONEY, 0, 0, 0, 0, 0, 0, fldstAUTOINC,
    fldstBINARY, fldstMEMO, fldstGRAPHIC, fldstFMTMEMO, fldstOLEOBJ,
    fldstDBSOLEOBJ, fldstTYPEDBINARY, 0, fldstFIXED, fldstUNICODE,
    0, 0, 0, 0, 0, fldstHBINARY, fldstHMEMO, 0, 0, 0, 0, 0, 0);

  DataTypeMap: array[0..MAXLOGFLDTYPES - 1] of TFieldType = (
    ftUnknown, ftString, ftDate, ftBlob, ftBoolean, ftSmallint,
    ftInteger, ftFloat, ftBCD, ftBytes, ftTime, ftDateTime,
    ftWord, ftInteger, ftUnknown, ftVarBytes, ftUnknown, ftCursor,
    ftLargeInt, ftLargeInt, ftADT, ftArray, ftReference, ftDataSet, 
    ftTimeStamp, ftFMTBCD);

  BlobTypeMap: array[fldstMEMO..fldstBFILE] of TFieldType = (
    ftMemo, ftBlob, ftFmtMemo, ftParadoxOle, ftGraphic, ftDBaseOle,
    ftTypedBinary, ftBlob, ftBlob, ftBlob, ftBlob, ftOraClob, ftOraBlob,
    ftBlob, ftBlob);

type

{ Forward declarations }

  TSQLConnection = class;
  TCustomSQLDataSet = class;
  TSQLDataSet = class;
  TSQLQuery = class;
  TSQLStoredProc = class;
  TSQLTable = class;

  TLocaleCode = Integer;

  TSQLExceptionType = (exceptConnection, exceptCommand, exceptCursor, exceptMetaData, exceptUseLast);

  TSQLTraceFlag = (traceQPREPARE, traceQEXECUTE, traceERROR,
    traceSTMT, traceCONNECT, traceTRANSACT, traceBLOB, traceMISC, traceVENDOR,
    traceDATAIN, traceDATAOUT);

  TSQLTraceFlags = set of TSQLTraceFlag;

{ TSQLBlobStream }

  TSQLBlobStream = class(TMemoryStream)
  private
    FDataSet: TCustomSQLDataSet;
    FField: TBlobField;
    FFieldNo: Integer;
  public
    constructor Create(Field: TBlobField; Mode: TBlobStreamMode = bmRead);
    destructor Destroy; override;
    procedure ReadBlobData;
  end;

  TConnectionUserType = (eUserMonitor, eUserDataSet);

{ TSQLMonitor }

  pSQLTRACEDesc = ^SQLTRACEDesc;
  SQLTRACEDesc = packed record             { trace callback info }
    pszTrace        : array [0..1023] of Char;
    eTraceCat       : TRACECat;
    ClientData      : Integer;
    uTotalMsgLen    : Word;
  end;

  TTraceEvent = procedure(Sender: TObject; CBInfo: pSQLTraceDesc; var LogTrace: Boolean) of object;
  TTraceLogEvent = procedure(Sender: TObject; CBInfo: pSQLTraceDesc) of object;

  TSQLMonitor = class(TComponent)
  private
    FActive: Boolean;
    FAutoSave: Boolean;
    FFileName: string;
    FKeepConnection: Boolean;
    FMaxTraceCount: Integer;
    FOnTrace: TTraceEvent;
    FOnLogTrace: TTraceLogEvent;
    FSQLConnection: TSQLConnection;
    FStreamedActive: Boolean;
    FTraceFlags: TSQLTraceFlags;
    FTraceList: TStrings;
    procedure CheckInactive;
    function GetTraceCount: Integer;
  protected
    function InvokeCallBack(CallType: TRACECat; CBInfo: Pointer): CBRType; stdcall;
    procedure SetActive(Value: Boolean);
    procedure SetSQLConnection(Value: TSQLConnection);
    procedure SetStreamedActive;
    procedure SetTraceList(Value: TStrings);
    procedure SetFileName(const Value: String);
    procedure SwitchConnection(const Value: TSQLConnection);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure LoadFromFile(AFileName: string);
    procedure SaveToFile(AFileName: string);
    property MaxTraceCount: Integer read FMaxTraceCount write FMaxTraceCount;
    property TraceCount: Integer read GetTraceCount;
  published
    property Active: Boolean read FActive write SetActive default False;
    property AutoSave: Boolean read FAutoSave write FAutoSave default False;
    property FileName: string read FFileName write SetFileName;
    property OnLogTrace: TTraceLogEvent read FOnLogTrace write FOnLogTrace;
    property OnTrace: TTraceEvent read FOnTrace write FOnTrace;
{   property TraceFlags not supported in DBExpress 1.0 }
    property TraceList: TStrings read FTraceList write SetTraceList stored False;
    property SQLConnection: TSQLConnection read FSQLConnection write SetSQLConnection;
  end;

{ TSQLConnection }

  TLocale = Pointer;

  EConnectFlag = (eConnect, eReconnect, eDisconnect);

  TSchemaType = (stNoSchema, stTables, stSysTables, stProcedures, stColumns,
    stProcedureParams, stIndexes);

  TConnectionState = (csStateClosed, csStateOpen, csStateConnecting,
    csStateExecuting, csStateFetching, csStateDisconnecting);

  TTableScope = (tsSynonym, tsSysTable, tsTable, tsView);

  TTableScopes = set of TTableScope;

  TLoginEvent = procedure(Sender: TObject; Username, Password: string) of object;
  TConnectChangeEvent = procedure(Sender: TObject; Connecting: Boolean) of object;

  TSQLConnectionLoginEvent = procedure(Database: TSQLConnection;
    LoginParams: TStrings) of object;
  
  TSQLConnection = class(TCustomConnection)
  private
    FActiveStatements: LongWord;
    FAutoClone: Boolean;
    FCloneParent: TSQLConnection;
    FConnectionState: TConnectionState;
    FConnectionName: string;
    FConnectionRegistryFile: string;
    FDriverName: string;
    FDriverRegistryFile: string;
    FGetDriverFunc: string;
    FTransactionCount: Integer;
    FIsCloned: Boolean;
    FISQLConnection: ISQLConnection;
    FKeepConnection: Boolean;
    FLastError: string;  // DBExpress GetError() clears error; need to save last
    FLibraryName: string;
    FLoadParamsOnConnect: Boolean;
    FMonitorUsers: TList;
    FOnLogin: TSQLConnectionLoginEvent;
    FParams: TStrings;
    FParamsLoaded: Boolean;
    FMaxStmtsPerConn: LongWord;
    FQuoteChar: String;
    FRefCount: Integer;
    FSQLDllHandle: THandle;
    FSQLDriver: ISQLDriver;
    FSQLHourGlass: Boolean;
    FSQLMetaData: ISQLMetaData;
    FSupportsMultiTrans: LongBool;
    FTableScope: TTableScopes;
    FTraceCallbackEvent: TSQLCallbackEvent;
    FTraceClientData: Integer;
    FTransactionsSupported: LongBool;
    FVendorLib: string;
    procedure CheckActive;
    procedure CheckInactive;
    procedure CheckLoginParams;
    procedure ClearConnectionUsers;
    procedure ClearMonitors;
    procedure FreeSchemaTable(DataSet: TCustomSQLDataSet);
    function GetConnectionForStatement: TSQLConnection;
    function GetConnectionName: string;
    function GetFDriverRegistryFile: string;
    function GetLocaleCode: TLocaleCode;
    function GetInTransaction: Boolean;
    function GetLibraryName: string;
    procedure GetLoginParams(LoginParams: TStrings);
    function GetQuoteChar: string;
    function GetVendorLib: string;
    procedure Login(LoginParams: TStrings);
    function OpenSchemaTable(eKind: TSchemaType; SInfo: string; SQualifier: string = ''): TCustomSQLDataSet;
    procedure RegisterTraceMonitor(Client: TObject);
    procedure RegisterTraceCallback(Value: Boolean);
    procedure SetConnectionParams;
    procedure SetConnectionName(Value: string);
    procedure SetDriverName(Value: string);
    procedure SetKeepConnection(Value: Boolean);
    procedure SetParams(Value: TStrings);
    procedure SetCursor(CursorType: Integer);
    procedure SetLocaleCode(Value: TLocaleCode);
//    function SQLTraceCallback(CBInfo: Pointer): CBRType;
    procedure UnregisterTraceMonitor(Client: TObject);
  protected
    function Check(status: SQLResult): SQLResult;
    procedure CheckConnection(eFlag: eConnectFlag);
    procedure CheckDisconnect; virtual;
    procedure ConnectionOptions; virtual;
    procedure DoConnect; override;
    procedure DoDisconnect; override;
    function GetConnected: Boolean; override;
    function GetDataSet(Index: Integer): TCustomSQLDataSet; reintroduce;
    procedure Loaded; override;
    procedure LoadSQLDll;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure OpenSchema(eKind: TSchemaType; sInfo: string; List: TStrings);
    procedure SQLError(OpStatus: SQLResult; eType: TSQLExceptionType; const Command: ISQLCommand = nil);
    property Connection: ISQLConnection read FISQLConnection;
    property ConnectionRegistryFile: string read FConnectionRegistryFile;
    property Driver: ISQLDriver read FSQLDriver;
    property DriverRegistryFile: string read GetFDriverRegistryFile;
    property LastError: string read FLastError write FLastError;
    property QuoteChar: String read FQuoteChar;
    property SQLDllHandle: THandle read FSQLDllHandle write FSQlDllHandle;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function CloneConnection: TSQLConnection;
    procedure CloseDataSets;
    procedure Commit( TransDesc: TTransactionDesc);
    function Execute(const SQL: string; Params: TParams;
      ResultSet: Pointer = nil): Integer;
    function ExecuteDirect(const SQL: string): LongWord;
    procedure GetFieldNames(const TableName: string; List: TStrings);
    procedure GetIndexNames(const TableName: string; List: TStrings);
    procedure GetProcedureNames(List: TStrings);
    procedure GetProcedureParams(ProcedureName:string; List: TList);
    procedure GetTableNames(List: TStrings;
      SystemTables: Boolean = False);
    procedure LoadParamsFromIniFile( FFileName: string = '');
    procedure Rollback( TransDesc: TTransactionDesc);
    procedure SetTraceCallbackEvent(Event: TSQLCallbackEvent; IClientInfo: Integer);
    procedure StartTransaction( TransDesc: TTransactionDesc);
    property ActiveStatements: LongWord read FActiveStatements;
    property AutoClone: Boolean read FAutoClone write FAutoClone default True;
    property ConnectionState: TConnectionState read FConnectionState write FConnectionState;
    property DataSets[Index: Integer]: TCustomSQLDataSet read GetDataSet;
    property InTransaction: Boolean read GetInTransaction;
    property LocaleCode: TLocaleCode read GetLocaleCode write SetLocaleCode default TLocaleCode(0);
    property MaxStmtsPerConn: LongWord read FMaxStmtsPerConn;
    property MetaData: ISQLMetaData read FSQLMetaData;
    property ParamsLoaded: Boolean read FParamsLoaded write FParamsLoaded;
    property SQLConnection: ISQLConnection read FISQLConnection write FISQLConnection;
    property SQLHourGlass: Boolean read FSQLHourGlass write FSQLHourGlass default True;
    property TraceCallbackEvent: TSQLCallbackEvent read FTraceCallbackEvent;
    property TransactionsSupported: LongBool read FTransactionsSupported;
//    property Locale: TLocale read FLocale;
  published
    property Connected;
    property ConnectionName: string read GetConnectionName write SetConnectionName;
    property DriverName: string read FDriverName write SetDriverName;
    property GetDriverFunc: string read FGetDriverFunc write FGetDriverFunc;
    property KeepConnection: Boolean read FKeepConnection write SetKeepConnection default True;
    property LibraryName: string read GetLibraryName write FLibraryName;
    property LoadParamsOnConnect: Boolean read FLoadParamsOnConnect write FLoadParamsOnConnect default False;
    property LoginPrompt default True;
    property Params: TStrings read FParams write SetParams;
    property TableScope: TTableScopes read FTableScope write FTableScope default [tsTable, tsView];
    property VendorLib: string read GetVendorLib write FVendorLib;
    property AfterConnect;
    property AfterDisconnect;
    property BeforeConnect;
    property BeforeDisconnect;
    property OnLogin: TSQLConnectionLoginEvent read FOnLogin write FOnLogin;
  end;

{ TSQLDataLink }

  TSQLDataLink = class(TDetailDataLink)
  private
    FSQLDataSet: TCustomSQLDataSet;
  protected
    procedure ActiveChanged; override;
    procedure CheckBrowseMode; override;
    function GetDetailDataSet: TDataSet; override;
    procedure RecordChanged(Field: TField); override;
  public
    constructor Create(ADataSet: TCustomSQLDataSet);
  end;

{ TCustomSQLDataSet }

  TSQLCommandType = (ctQuery, ctTable, ctStoredProc);

  TSQLSchemaInfo = record
    FType: TSchemaType;
    ObjectName: string;
    Pattern: string;
  end;

  TFieldDescList = array of FLDDesc;

  TCustomSQLDataSet = class(TDataSet)
  private
    FBlobBuffer: TBlobByteData;
    FCalcFieldsBuffer: PChar;
    FCheckRowsAffected: Boolean;
    FClonedConnection: TSqlConnection;
    FCommandText: string;
    FCommandType: TSQLCommandType;
    FCurrentBlobSize: LongWord;
    FDataLink: TDataLink;
    FDesignerData: string;
    FFieldBuffer: PChar;
    FGetNextRecordSet: Boolean;
    FIndexDefs: TIndexDefs;
    FIndexDefsLoaded: Boolean;
    FLastError: string;  // DBExpress GetError() clears error; need to save last
    FMaxBlobSize: Integer;
    FMaxColSize: LongWord;
    FNativeCommand: string;
    FNoMetadata: Boolean platform;
    FParamCheck: Boolean;
    FParamCount: Integer;
    FParams: TParams;
    FPrepared: Boolean;
    FProcParams: TList;
    FRecords: Integer;
    FRowsAffected: Integer;
    FSchemaInfo: TSQLSchemaInfo;
    FSortFieldNames: string;
    FSQLCommand: ISQLCommand;
    FSQLConnection: TSQLConnection;
    FSQLCursor: ISQLCursor;
    FStatementOpen: Boolean;
    FTransactionLevel: SmallInt;
    function CheckFieldNames(const FieldNames: string): Boolean;
    procedure CheckConnection(eFlag: eConnectFlag);
    function CheckDetail(SQL: string): string;
    procedure CheckStatement(ForSchema: Boolean = False);
    function GetCalculatedField(Field: TField; var Buffer: Pointer): Boolean;
    function GetDataSetFromSQL(TableName: string): TCustomSQLDataSet;
    function GetProcParams: TList;
    function GetInternalConnection: TSQLConnection;
    function GetObjectProcParamCount: Integer; virtual;
    function GetParamCount: Integer; virtual;
    function GetQueryFromType: string; virtual;
    function GetRowsAffected: Integer;
    procedure InitBuffers;
    procedure LoadFieldDef(FieldID: Word; var FldDesc: FLDDesc);
    procedure ReadDesignerData(Reader: TReader);
    procedure RefreshParams;
    procedure SetConnection(const Value: TSQLConnection); virtual;
    procedure SetCurrentBlobSize(Value: LongWord);
    procedure SetDataSource(Value: TDataSource);
    procedure SetParameters(const Value: TParams);
    procedure SetParamsFromProcedure;
    procedure SetParamsFromSQL(DataSet: TDataSet; bFromFields: Boolean);
    procedure SetPrepared(Value: Boolean);
    procedure SetCommandType(const Value: TSQLCommandType); virtual;
    procedure WriteDesignerData(Writer: TWriter);
  protected
    { IProviderSupport }
    procedure PSEndTransaction(Commit: Boolean); override;
    procedure PSExecute; override;
    function PSExecuteStatement(const ASQL: string; AParams: TParams;
      ResultSet: Pointer = nil): Integer; override;
    procedure PSGetAttributes(List: TList); override;
    function PSGetDefaultOrder: TIndexDef; override;
    function PSGetKeyFields: string; override;
    function PSGetIndexDefs(IndexTypes: TIndexOptions): TIndexDefs; override;
    function PSGetParams: TParams; override;
    function PSGetQuoteChar: string; override;
    function PSGetTableName: string; override;
    function PSGetUpdateException(E: Exception; Prev: EUpdateError): EUpdateError; override;
    function PSInTransaction: Boolean; override;
    function PSIsSQLBased: Boolean; override;
    function PSIsSQLSupported: Boolean; override;
    procedure PSReset; override;
    procedure PSSetCommandText(const ACommandText: string); override;
    procedure PSSetParams(AParams: TParams); override;
    procedure PSStartTransaction; override;
    function PSUpdateRecord(UpdateKind: TUpdateKind; Delta: TDataSet): Boolean; override;
  protected
    { implementation of abstract TDataSet methods }
    procedure InternalClose; override;
    procedure InternalHandleException; override;
    procedure InternalInitFieldDefs; override;
    procedure InternalOpen; override;
    function IsCursorOpen: Boolean; override;
  protected
    procedure AddFieldDesc(FieldDescs: TFieldDescList; DescNo: Integer;
        var FieldID: Integer; RequiredFields: TBits; FieldDefs: TFieldDefs);
    procedure AddIndexDefs(SourceDS: TCustomSQLDataSet; IndexName: string = '') ;
    function Check(status: SQLResult): SQLResult;
    procedure CheckPrepareError;
    procedure ClearIndexDefs;
    procedure CloseCursor; override;
    procedure CloseStatement;
    procedure DefineProperties(Filer: TFiler); override;
    function ExecSQL(ExecDirect: Boolean = False): Integer; virtual;
    procedure ExecuteStatement;
    procedure FreeCursor;
    procedure FreeBuffers;
    procedure FreeStatement;
    function GetCanModify: Boolean; override;
    function GetDataSource: TDataSource; override;
    procedure GetObjectTypeNames(Fields: TFields);
    procedure GetOutputParams(AProcParams: TList);
    function GetRecord(Buffer: PChar; GetMode: TGetMode; DoCheck: Boolean): TGetResult; override;
    function GetSortFieldNames: string;
    procedure InitRecord(Buffer: PChar); override;
    procedure InternalRefresh; override;
    procedure Loaded; override;
    procedure OpenCursor(InfoQuery: Boolean); override;
    procedure OpenSchema; virtual;
    procedure PrepareStatement; virtual;
    procedure PropertyChanged;
    procedure SetBufListSize(Value: Integer); override;
    procedure SetCommandText(const Value: string); virtual;
    procedure SetFieldData(Field: TField; Buffer: Pointer); override;
    procedure SetParamsFromCursor;
    procedure SetSortFieldNames(Value: string);
    procedure SQLError(OpStatus: SQLResult; eType: TSQLExceptionType);
    procedure UpdateIndexDefs; override;
    { protected properties }
    property BlobBuffer: TBlobByteData read FBlobBuffer write FBlobBuffer;
    property CurrentBlobSize: LongWord read FCurrentBlobSize write SetCurrentBlobSize;
    property DataLink: TDataLink read FDataLink;
    property InternalConnection: TSqlConnection read GetInternalConnection;
    property LastError: string read FLastError write FLastError;
    property NativeCommand: string read FNativeCommand write FNativeCommand;
    property ProcParams: TList read GetProcParams write FProcParams;
    property RowsAffected: Integer read GetRowsAffected;
    procedure SetMaxBlobSize(MaxSize: Integer);
    procedure SetFCommandText(const Value: string);
    property ParamCount: Integer read GetParamCount;
    property SchemaInfo: TSQLSchemaInfo read FSchemaInfo write FSchemaInfo;
  protected  { publish in TSQLDataSet }
    property CommandText: string read FCommandText write SetCommandText;
    property CommandType: TSQLCommandType read FCommandType write SetCommandType default ctQuery;
    property DataSource: TDataSource read GetDataSource write SetDataSource;
    property MaxBlobSize: Integer read FMaxBlobSize write SetMaxBlobSize default DefaultMaxBlobSize;
    function GetRecordCount: Integer; override;
    property Params: TParams read FParams write SetParameters;
    property ParamCheck: Boolean read FParamCheck write FParamCheck default True;
    property SortFieldNames: string read GetSortFieldNames write SetSortFieldNames;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function CreateBlobStream(Field: TField; Mode: TBlobStreamMode): TStream; override;
    function GetBlobFieldData(FieldNo: Integer; var Buffer: TBlobByteData): Integer; override;
    procedure GetDetailLinkFields(MasterFields, DetailFields: TList); override;
    function GetFieldData(FieldNo: Integer; Buffer: Pointer): Boolean; overload; override;
    function GetFieldData(Field: TField; Buffer: Pointer): Boolean; overload; override; 
    function GetKeyFieldNames(List: TStrings): Integer;
    function GetQuoteChar: string; virtual;
    function ParamByName(const Value: string): TParam;
    property IndexDefs: TIndexDefs read FIndexDefs write FIndexDefs;
    function IsSequenced: Boolean; override;
    procedure SetSchemaInfo(SchemaType: TSchemaType; SchemaObjectName, SchemaPattern: string);
    property Prepared: Boolean read FPrepared write SetPrepared default False;
    property DesignerData: string read FDesignerData write FDesignerData;
    property RecordCount: Integer read GetRecordCount;
    property TransactionLevel: SmallInt read FTransactionLevel write FTransactionLevel default 0;
  published
    property Active default False;
    property NoMetadata: Boolean read FNoMetadata write FNoMetadata default False;
    property ObjectView default False;
    property BeforeOpen;
    property AfterOpen;
    property BeforeClose;
    property AfterClose;
    property BeforeScroll;
    property AfterScroll;
    property BeforeRefresh;
    property AfterRefresh;
    property OnCalcFields;
    property SQLConnection: TSQLConnection read FSQLConnection write SetConnection;
  end;

{ TSQLDataSet }

  TSQLDataSet = class(TCustomSQLDataSet)
  public
    constructor Create(AOwner: TComponent); override;
    function ExecSQL(ExecDirect: Boolean = False): Integer; override;
  published
    property CommandText;
    property CommandType;
    property DataSource;
    property MaxBlobSize;
    property ParamCheck;
    property Params;
    property SortFieldNames;
  end;

{ TSQLQuery }

  TSQLQuery = class(TCustomSQLDataSet)
  private
    FSQL: TStrings;
    FText: string;
    procedure QueryChanged(Sender: TObject);
    procedure SetSQL(Value: TStrings);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function ExecSQL(ExecDirect: Boolean = False): Integer; override;
    procedure PrepareStatement; override;
    property RowsAffected;
    property Text: string read FText;
  published
    property DataSource;
    property MaxBlobSize;
    property ParamCheck;
    property Params;
    property SQL: TStrings read FSQL write SetSQL;
  end;

{ TSQLStoredProc }

  TSQLStoredProc = class(TCustomSQLDataSet)
  private
    FStoredProcName: string;
    procedure SetStoredProcName(Value: string);
  public
    constructor Create(AOwner: TComponent); override;
    function ExecProc: Integer; virtual;
    function NextRecordSet: TCustomSQLDataSet;
    procedure PrepareStatement; override;
  published
    property MaxBlobSize;
    property ParamCheck;
    property Params;
    property StoredProcName: string read FStoredProcName write SetStoredProcName;
  end;

{ TSQLTable }

  TSQLTable = class(TCustomSQLDataSet)
  private
    FIsDetail: Boolean;
    FIndexFields: TList;
    FIndexFieldNames: string;
    FIndexName: string;
    FMasterLink: TMasterDataLink;
    FTableName: string;
    FIndexFieldCount: Integer;
    procedure AddParamsToQuery;
    function GetMasterFields: string;
    function GetIndexField(Index: Integer): TField;
    function GetIndexFieldCount: Integer;
    function RefreshIndexFields: Integer;
    procedure SetIndexFieldNames(Value: string);
    procedure SetIndexName(Value: string);
    procedure SetMasterFields(Value: string);
    procedure SetTableName(Value: string);
    function GetQueryFromType: string; override;
    procedure SetDataSource(Value: TDataSource);
  protected
    procedure OpenCursor(InfoQuery: Boolean); override;
    procedure SetIndexField(Index: Integer; Value: TField);
    property MasterLink: TMasterDataLink read FMasterLink;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure DeleteRecords;
    procedure GetIndexNames(List: TStrings);
    procedure PrepareStatement; override;
    property IndexFields[Index: Integer]: TField read GetIndexField write SetIndexField;
    property IndexFieldCount: Integer read GetIndexFieldCount;
  published
    property Active default False;
    property IndexFieldNames: string read FIndexFieldNames write SetIndexFieldNames;
    property IndexName: string read FIndexName write SetIndexName;
    property MasterFields: string read GetMasterFields write SetMasterFields;
    property MasterSource: TDataSource read GetDataSource write SetDataSource;
    property MaxBlobSize;
    property TableName: string read FTableName write SetTableName;
  end;

{ Utility Routines }

  procedure LoadParamListItems(Params: TParams; ProcParams: TList);
  procedure FreeProcParams(var ProcParams: TList);
  procedure GetConnectionNames(List: TStrings; Driver: string = ''; DesignMode: Boolean = True);
  procedure GetDriverNames(List: TStrings; DesignMode: Boolean = True);
  function GetDriverRegistryFile(DesignMode: Boolean = False): string;
  function GetConnectionRegistryFile(DesignMode: Boolean = False): string;
var
  GetDriver: function(SVendorLib, SResourceFile: PChar; out Obj): SQLResult; stdcall;
  DllHandle: THandle;
{$IFDEF MSWINDOWS}
  DllGetClassObject: function(const CLSID, IID: TGUID; var Obj): HResult; stdcall;
  procedure RegisterDbXpressLib(GetClassProc: Pointer);
{$ENDIF}

implementation

{$IFDEF MSWINDOWS}
uses Registry, SqlConst, DBConsts, IniFiles, DBConnAdmin, Math, FMTBcd;
{$ENDIF}
{$IFDEF LINUX}
uses SqlConst, DBConsts, IniFiles, Math, DBConnAdmin, FMTBcd;
{$ENDIF}

{ Utility routines }

procedure CheckObject(const Value: IInterface; const eType: TSQLExceptionType);
var
  Message: string;
begin
  if not Assigned(Value) then
  begin
    case eType of 
      exceptConnection: Message := SDBXNOCONNECTION;
      exceptCommand: Message := SDBXNOCOMMAND;
      exceptCursor: Message := SDBXNOCURSOR;
      exceptMetadata: Message := SDBXNOMETAOBJECT;
    end;
    DatabaseError(Message);
  end;
end;

function AddQuoteCharToObjectName(Name, Q: string): string;
var
  P: PChar;
  Required: Boolean;
begin
  Required := False;
  P := PChar(Name);
  if (P[0] = '"') or (P[Length(Name)-1] = '"') then
    Result := Name
  else
  begin
    repeat
      if not (P^ in ['A'..'Z', '0'..'9', '_']) then
      begin
        Required := True;
        Break;
      end;
      Inc(P)
    until P^ = #0;
    if Required then
      Result := Q + Name + Q
    else
      Result := Name;
  end;
end;

function GetTableScope(Scope: TTableScopes): LongWord;
begin
  Result := 0;
  if tsTable in Scope then
    Result := Result OR eSQLTable;
  if tsView in Scope then
    Result := Result OR eSQLView;
  if tsSysTable in Scope then
    Result := Result OR eSQLSystemTable;
  if tsSynonym in Scope then
    Result := Result OR eSQLSynonym;
end;

{$IFDEF LINUX}
function CopyConfFile(Source, Target: string): Boolean;
var
  List: TStrings;
  IniIn, IniOut: TMemIniFile;
begin
  List := TStringList.Create;
  try
    IniIn := TMemIniFile.Create(Source);
    try
      IniOut := TMemIniFile.Create(Target);
      try 
        IniIn.GetStrings(List);
        IniOut.SetStrings(List);
        IniOut.UpdateFile;
        Result := True;
      finally
        IniOut.Free;
      end;
    finally
      IniIn.Free;
    end;
  finally
    List.Free;
  end;
end;
{$ENDIF}

function GetRegistryFile(Setting, Default: string; DesignMode: Boolean): string;
var
{$IFDEF MSWINDOWS}
  Reg: TRegistry;
{$ENDIF}
{$IFDEF LINUX}
  GlobalFile: string;
{$ENDIF}
begin
  {$IFDEF MSWINDOWS}
  Result := '';
  Reg := TRegistry.Create;
  try
    Reg.RootKey := HKEY_CURRENT_USER;
    if Reg.OpenKeyReadOnly(SDBEXPRESSREG_SETTING) then
      Result := Reg.ReadString(Setting);
  finally
    Reg.Free;
  end;
  if Result = '' then
    Result := ExtractFileDir(ParamStr(0)) + '\' + Default;
  {$ENDIF}
  {$IFDEF LINUX}
  Result := getenv('HOME') + SDBEXPRESSREG_USERPATH + Default;    { do not localize }
  if not FileExists(Result) then
  begin
    GlobalFile := SDBEXPRESSREG_GLOBALPATH + Default + SConfExtension;
    if FileExists(GlobalFile) then
    begin
      if DesignMode then
      begin
        if not CopyConfFile(GlobalFile, Result) then
          DatabaseErrorFmt(SConfFileMoveError, [GlobalFile, Result])
      end else
        Result := GlobalFile;
    end else
      DatabaseErrorFmt(SMissingConfFile, [GlobalFile]);
  end;
  {$ENDIF}
end;

function GetDriverRegistryFile(DesignMode: Boolean = False): string;
begin
  Result := GetRegistryFile(SDRIVERREG_SETTING, sDriverConfigFile, DesignMode);
end;

function GetConnectionRegistryFile(DesignMode: Boolean = False): string;
begin
  Result := GetRegistryFile(SCONNECTIONREG_SETTING, sConnectionConfigFile, DesignMode);
end;

function GetBlobSize(DataSet: TCustomSQLDataSet; FieldNo: Integer): LongWord;
var
  IsNull: LongBool;
  Status: SQLResult;
begin
  Result := 0;
  if not DataSet.EOF then 
  begin  
    if DataSet.MaxBlobSize = 0 then exit;
    Status := DataSet.FSQLCursor.GetBlobSize(Word(FieldNo), Result, IsNull);
    if Status <> SQL_SUCCESS then
      DataSet.SQLError(Status, exceptCursor);
    if IsNull then
      Result := 0;
  end;
  DataSet.CurrentBlobSize := Result;
end;

function NextPiece(Start: string; InLiteral: Boolean; QuoteChar: Char; EndParam: Boolean = False): Integer;
var
  P: PChar;
  Ctr: Integer;
  SearchChars: set of char;
begin
  SearchChars := [' ', ')', ',', '=', ':', '>', '<', #13, #10];
  P := (PChar(Start))+1;
  Ctr := 1;
  Result := 0;
  while (Result = 0) and (P^ <> #0) do
  begin
    if (P^ = '''') or (P^ = QuoteChar) then 
      InLiteral := not InLiteral
    else
    if not InLiteral and (P^ in SearchChars) then
    begin
      if EndParam then
      begin
        if not (P^ in ['=', ':', '<', '>']) then
        begin
          Result := Ctr;
          Inc(Result);
        end
      end else
      begin
        if (P^ = ':') then
        begin
          if P[-1] in [' ', ')', ',', '=', '('] then
            Result := Ctr;
        end
        else if (P[1] = ':') then
        begin
          Result := Ctr;
          Inc(Result);
        end;
      end;
    end;
    Inc(P);
    Inc(Ctr);
  end;
end;

// SqlObjects does not support named params: convert to ?
// if not yet converted
function FixParams(SQL: string; Count: Integer; QuoteChar: string): string;
var
  Param, Start: string;
  Pos, EndPos: Integer;
  InLiteral: Boolean;
  Q: Char;
begin
  Q := PChar(QuoteChar)[0];
  if Q in [#0, ' '] then Q := '''';
  InLiteral := False;
  Start := SQL;
  Pos := NextPiece(Start, InLiteral, Q);
  while Pos > 0 do
  begin
    Start := copy(Start, Pos + 1, Length(Start) - Pos);
    EndPos := NextPiece(Start, InLiteral, Q, True);
    if EndPos = 0 then
      Param := copy(Start, 1, Length(Start))
    else
      Param := copy(Start, 1, EndPos-1);
    SQL := stringReplace(SQL, Param, ' ? ', []);
    Pos := NextPiece(Start, InLiteral, Q);
  end;
  Result := SQL;
end;

function GetProfileString(Section, Setting, IniFileName: string): string;
var
  IniFile: TMemIniFile;
  List: TStrings;
begin
  List := TStringList.Create;
  try
    IniFile := TMemIniFile.Create(IniFileName);
    IniFile.ReadSectionValues(Section, List);
    try
      Result := List.Values[ Setting ];
    finally
      IniFile.Free;
    end;
  finally
    List.Free;
  end;
end;

procedure GetDriverNames(List: TStrings; DesignMode: Boolean = True);
var
  ConnectionAdmin: IConnectionAdmin;
begin
  ConnectionAdmin := GetConnectionAdmin;
  ConnectionAdmin.GetDriverNames(List);
end;

procedure GetConnectionNames(List: TStrings; Driver: string = ''; DesignMode: Boolean = True);
var
  I: Integer;
  ConnectionAdmin: IConnectionAdmin;
begin
  ConnectionAdmin := GetConnectionAdmin;
  ConnectionAdmin.GetConnectionNames(List, '');
  if Driver <> '' then
  begin
    List.BeginUpdate;
    try
      I := List.Count - 1;
      while I >= 0 do
      begin
        if AnsiCompareText(GetProfileString(List[I], DRIVERNAME_KEY,
              GetConnectionRegistryFile(DesignMode)), Driver) <> 0 then
           List.Delete(I);
        Dec(I);
      end;
    finally
      List.EndUpdate;
    end;
  end;
end;

procedure GetParamData(Param: TParam; Buffer: Pointer; const DrvLocale: TLocale);

  function GetNativeStr: PChar;
  begin
    Param.NativeStr := VarToStr(Param.Value);
    Result := PChar(Param.NativeStr);
  end;

begin
  if Buffer <> nil then
  begin
    with Param do
      if DataType in [ftString, ftFixedChar, ftMemo]  then
      begin
        NativeStr := VarToStr(Value);
        GetData(Buffer);
      end
      else
        GetData(Buffer);
  end;
end;


procedure CalcUnits( const Params: TParams; const ProcParams: TList;
          const Index: Integer; pArgDesc: pSPParamDesc; var ChildPos: array of Word );
var
  I: Integer;
  ArgDesc: SPParamDesc;
begin
  I := Index + 1;
  ArgDesc := pArgDesc^;
  pArgDesc.iUnits1 := 0;
  pArgDesc.iUnits2 := 0;
  while (I < Params.Count) do
  begin
    ArgDesc := (PSPParamDesc(ProcParams.Items[I]))^;
    if ArgDesc.iParamNum <> pArgDesc.iParamNum then
      break;
    Inc(pArgDesc.iUnits1);
    Inc(pArgDesc.iUnits2);
    ChildPos[I] := I - Index;
    if ArgDesc.iDataType = ftADT then
    begin
      CalcUnits(Params, ProcParams, I, @ArgDesc, ChildPos);
      Inc(pArgDesc.iUnits2, ArgDesc.iUnits2);
      Inc(I, ArgDesc.iUnits2);
    end else
      Inc(I);
  end;
end;

procedure SetProcedureParams(const Sender: TSQLConnection;
  const Command: ISQLCommand; const Params: TParams; ProcParams: TList);
var
  I, IInd, DataLen: Integer;
  iFldNum: LongWord;
  RecBuffer: PChar;
  iFldType, iSubType: Word;
  DrvLocale: TLocale;
  Status: SQLResult;
  ArgDesc: SPParamDesc;
  ChildPosArray: array of Word;
  SBcd: string;
  Bcd: TBcd;
begin
  DrvLocale := nil;
  SetLength(ChildPosArray, Params.Count);
  for I := 0 to Params.Count - 1 do
    begin
      RecBuffer := nil;
      try
        if Params[I].ParamType = ptUnknown then  // Midas assumes its Input
          Params[I].ParamType := ptInput;
        iFldNum := i + 1;
        iFldType := FldTypeMap[Params[I].DataType];
        iSubType := 0;
        if iFldType in [fldBlob, fldZString] then
          iSubType := Word(FldSubTypeMap[Params[I].DataType])
        else if iFldType = fldUNKNOWN then
          DatabaseErrorFmt(SNoParameterValue, [Params[I].Name]);
        ArgDesc := (PSPParamDesc(ProcParams.Items[I]))^;
        iFldType := FldTypeMap[ArgDesc.iDataType];
        if Params[I].ParamType <> ptOutput then
          DataLen := Params[I].GetDataSize
        else
          DataLen := ArgDesc.iLen;
        if DataLen > 0 then
        begin
          iInd := 0;
          RecBuffer := AllocMem(DataLen);
          if Params[I].ParamType <> ptOutput then
            GetParamData(Params[I], RecBuffer, DrvLocale)
          else
            FillChar(RecBuffer^, DataLen, 0);
          if Params[I].ParamType = ptInput then
            Params[I].Size := 0;
          if (Params[I].ParamType = ptOutput) and not(iFldType in [fldFLOAT]) then
            ArgDesc.iLen := 0
          else
            case iFldType of
              fldBlob, fldZString, fldBYTES, fldVARBYTES:
                begin
                  ArgDesc.iLen := DataLen;
                  ArgDesc.iLen := DataLen;
                  ArgDesc.iUnits2 := 0;
                  if (Params[I].ParamType = ptInputOutput) and (DataLen > Params[I].Size) then
                  begin
                    if iFldType = fldVARBYTES then
                      Params[I].Size := DataLen - 2
                    else
                      Params[I].Size := DataLen;
                  end;
                end;
              fldFLOAT:
                begin
                  if Params[I].Precision = 4 then
                    ArgDesc.iLen := 4
                  else
                    ArgDesc.iLen := Sizeof(Double);
                end;
              fldFMTBCD, fldBCD:
                begin
                  iFldType := fldBCD;   { DBExpress does not distinguish }
                  if Params[I].Size = 0 then
                  begin
                    SBcd := BcdToStr(PBcd(RecBuffer)^);
                    Bcd := StrToBcd(SBcd);
                    Params[I].Size := Bcd.Precision;
                    ArgDesc.iUnits2 := Bcd.SignSpecialPlaces AND $3F;
                  end else
                  begin
                    ArgDesc.iUnits2 := Params[I].NumericScale;
                  end;
                end;
              fldADT, fldARRAY:
                begin
                  CalcUnits(Params, ProcParams, I, @ArgDesc, ChildPosArray);
                  ArgDesc.iLen := DataLen;
                end;
            end;
        end else  // leave RecBuffer nil
        begin
          if iFldType in [fldADT, fldARRAY] then
            DatabaseError(SObjectTypenameRequired);
          iInd := 1;
        end;
        Status := Command.setParameter(iFldNum - ChildPosArray[I], ChildPosArray[I], TSTMTParamType(ArgDesc.iArgType),
                iFldType, iSubType, Params[I].Size,
                Integer(ArgDesc.iUnits2), ArgDesc.iLen, RecBuffer, IInd);
        if (Status <> SQL_Success) then
          Sender.SQLError(Status, exceptConnection);
      finally
        if RecBuffer <> nil then FreeMem(RecBuffer);
      end;
    end;
end;

procedure FreeProcParams(var ProcParams: TList);
var
  ArgParam: pSPParamDesc;
  I: Integer;
begin
  if not Assigned(ProcParams) then Exit;
  for I := 0 to ProcParams.Count -1 do
  begin
    ArgParam := ProcParams[I];
    Dispose(ArgParam);
  end;
  FreeAndNil(ProcParams);
end;

procedure LoadParamListItems(Params: TParams; ProcParams: TList);
var
  I: Integer;
  ArgParam: pSPParamDesc;
begin
  for I := 0 to ProcParams.Count -1 do
  begin
    ArgParam := ProcParams.Items[I];
    with TParam(Params.Add) do
    begin
      Name := ArgParam.szName;
      ParamType := ArgParam.iArgType;
      DataType := ArgParam.iDataType;
      if ParamType <> ptInput then
        Size := ArgParam.iLen;
    end;
  end;
end;

{ TSQLBlobStream }

constructor TSQLBlobStream.Create(Field: TBlobField; Mode: TBlobStreamMode = bmRead);
begin
  if not Field.DataSet.Active then
    DataBaseError(SDatasetClosed);
  FField := Field;
  FDataSet := FField.DataSet as TCustomSQLDataSet;
  FFieldNo := FField.FieldNo;
  ReadBlobData;
end;

destructor TSQLBlobStream.Destroy;
begin
  inherited Destroy;
end;

procedure TSQLBlobStream.ReadBlobData;
var
  BlobLength: LongInt;
begin
  Clear;
  BlobLength := GetBlobSize(FDataSet, FFieldNo);
  SetSize(BlobLength);
  if BlobLength = 0 then Exit;
  if FDataSet.GetFieldData(FField, FDataSet.FBlobBuffer, True) then
    Write(pointer(FDataSet.FBlobBuffer)^, FDataSet.FCurrentBlobSize);
  Position := 0;
end;

{ TSQLParams }

type

{ TSQLParams }

  TSQLParams = class(TParams)
  private
    FFieldName: TStrings;
    FBindAllFields: Boolean;
    function ParseSelect(SQL: string; bDeleteQuery: Boolean): string;
    function ParseUpdate(SQL: string): string;
    function ParseInsert(SQL: string): string;
  public
    constructor Create(Owner: TPersistent);
    Destructor Destroy; override;
    function GetFieldName(index: Integer): string;
    function Parse(SQL: string; DoCreate: Boolean): string;
    property BindAllFields: Boolean read FBindAllFields;
  end;

constructor TSQLParams.Create(Owner: TPersistent);
begin
  inherited;
  FBindAllFields := False;
  FFieldName := TStringList.Create;
end;

destructor TSQLParams.Destroy;
begin
  inherited;
  FreeAndNil(FFieldName);
end;

function TSQLParams.GetFieldName(index: Integer): string;
begin
   Result := FFieldName[ index ];
end;

function TSQLParams.Parse(SQL: string; DoCreate: Boolean): string;
const
  SDelete = 'delete';      { Do not localize }
  SUpdate = 'update';      { Do not localize }
  SInsert = 'insert';      { Do not localize }
var
  Start: string;
begin
  Result := ParseSQL(SQL, DoCreate);
  Start := LowerCase(copy(Result, 1, 6));
{ attempt to determine fields and fieldtypes associated with params }
  if Start = SSelect then
    Result := ParseSelect(SQL, False)
  else if Start = SDelete then
    Result := ParseSelect(SQL, True)
  else if Start = SInsert then
    Result := ParseInsert(SQL)
  else if Start = SUpdate then
    Result := ParseUpdate(SQL)
  else
    Result := '';
end;

{ no attempt to match fields clause with values clause :
    types only added if all values are inserted }
function TSQLParams.ParseInsert(SQL: string): string;
var
  Start: PChar;
  Value: string;
  CurSection: TSQLToken;
begin
  Result := '';
  if Pos(' ' + SSelect + ' ', LowerCase(SQL)) > 1 then Exit;  // can't parse sub queries
  Start := PChar(SQL);
  CurSection := stUnknown;
  { move past 'insert ' }
  NextSQLToken(Start, Value, CurSection);
  { move past 'into ' }
  NextSQLToken(Start, Value, CurSection);
  { move past <TableName> }
  NextSQLToken(Start, Value, CurSection);

  { Check for owner qualified table name }
  if Start^ = '.' then
    NextSQLToken(Start, Value, CurSection);
  Result := Value;

  { move past 'set' }
  NextSQLToken(Start, Value, CurSection);
  if (LowerCase(Value) = 'values') then
    FBindAllFields := True;
end;

function TSQLParams.ParseSelect(SQL: string; bDeleteQuery: Boolean): string;
var
  FWhereFound: Boolean;
  Start: PChar;
  FName, Value: string;
  SQLToken, CurSection, LastToken: TSQLToken;
  Params: Integer;
begin
  Result := '';
  if bDeleteQuery = False then
  begin
    if Pos(' ' + SSelect + ' ', LowerCase(string(PChar(SQL)+8))) > 1 then Exit;  // can't parse sub queries
    Start := PChar(SQL);
  end else
  begin
    if Pos(' ' + SSelect + ' ', LowerCase(SQL)) > 1 then Exit;  // can't parse sub queries
    Start := PChar(SSelectStar + Copy(SQL, 8, Length(SQL) -7));
  end;
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
        Result := FName;
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
  if Result = '' then Result := GetTableNameFromSql(SQL);
end;

function TSQLParams.ParseUpdate(SQL: string): string;
var
  Start: PChar;
  FName, Value: string;
  SQLToken, CurSection: TSQLToken;
  Params: Integer;
begin
  Result := '';
  if Pos(' ' + SSelect + ' ', LowerCase(SQL)) > 1 then Exit;  // can't parse sub queries
  Start := PChar(SQL);
  CurSection := stUnknown;
  { move past 'update ' }
  NextSQLToken(Start, FName, CurSection);
  { move past <TableName> }
  NextSQLToken(Start, FName, CurSection);

  { Check for owner qualified table name }
  if Start^ = '.' then
    NextSQLToken(Start, FName, CurSection);
    
  Result := FName;
  { move past 'set ' }
  NextSQLToken(Start, FName, CurSection);
  Params := 0;
  CurSection := stSelect;
  repeat
    repeat
      SQLToken := NextSQLToken(Start, FName, CurSection);
      if SQLToken in SQLSections then CurSection := SQLToken;
    until SQLToken in [stFieldName, stEnd];
    if Pos(LowerCase(FName), 'values(') > 0 then continue;   { do not localize }
    if Pos(LowerCase(FName), 'values (') > 0 then continue;  { do not localize }
    if SQLToken in [stFieldName] then
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

{ TSQLMonitor }

constructor TSQLMonitor.Create(AOwner: TComponent);
begin
  FTraceList := TStringList.Create;
  FMaxTraceCount := -1;
  inherited;
end;

destructor TSQLMonitor.Destroy;
begin
  if Active then SetActive(False);
  SetSQLConnection(nil);
  inherited;
  FreeAndNil(FTraceList);
end;

procedure TSQLMonitor.SetFileName(const Value: String);
begin
  FFileName := ExpandFileName(Value);
end;

procedure TSQLMonitor.CheckInactive;
begin
  if FActive then
  begin
    if (csDesigning in ComponentState) or (csLoading in ComponentState) then
      SetActive(False)
    else
      DatabaseError(SMonitorActive, Self);
  end;
end;

procedure TSQLMonitor.SetSQLConnection(Value: TSQLConnection);
var
  IsActive: Boolean;
begin
  if Value <> FSQLConnection then
  begin
    IsActive := Active;
    CheckInactive;
    if Assigned(FSQLConnection) and not FKeepConnection then
      SQLConnection.UnregisterTraceMonitor(Self);
    FSQLConnection := Value;
    if Assigned(FSQLConnection) then
    begin
      FSQLConnection.RegisterTraceMonitor(Self);
      Active := IsActive;
    end;
  end;
end;

procedure TSQLMonitor.SwitchConnection(const Value: TSQLConnection);
var
  MonitorActive: Boolean;
begin
  FKeepConnection := True;
  MonitorActive := Active;
  if MonitorActive then
    SetActive(False);
  SQLConnection := Value;
  if MonitorActive and Assigned(Value) then
    SetActive(True);
  FKeepConnection := False;
end;

function TSQLMonitor.InvokeCallBack(CallType: TRACECat; CBInfo: Pointer): CBRType; stdcall;
var
  Desc: pSQLTraceDesc;
  FLogTrace: Boolean;
  Msg: string;
begin
  Result := cbrUSEDEF;
  if csDestroying in ComponentState then exit;
  Desc := pSQLTraceDesc(CBInfo);
  FLogTrace := (TSQLTraceFlag(CallType) in FTraceFlags) or (FTraceFlags = []);
  if Assigned(FOnTrace) then
    FOnTrace(Self, Desc, FLogTrace);
  if FLogTrace then
  begin
    SetLength(Msg, StrLen(Desc.pszTrace));
    Move(Desc.pszTrace[0], PChar(Msg)[0], StrLen(Desc.pszTrace));
    if (FMaxTraceCount = -1) or (TraceCount < FMaxTraceCount) then
      FTraceList.Add(Msg);
    if Assigned(FOnLogTrace) then
      FOnLogTrace(Self, Desc);
    if FAutoSave and (FFileName <> '') then
      SaveToFile('');
  end;
end;

function SQLCallBack(CallType: TRACECat; CBInfo: Pointer): CBRType; stdcall;
begin
  Result := cbrUSEDEF;
  if CBInfo <> nil then
    Result := TSQLMonitor(PSQLTraceDesc(CBInfo).ClientData).InvokeCallback(CallType, CBInfo);
end;

procedure TSQLMonitor.SetActive(Value: Boolean);
var
  FileHandle: Integer;
begin
  if FActive <> Value then
  begin
    if (csReading in ComponentState) then
      FStreamedActive := Value
    else begin
      if not (csDestroying in ComponentState) and not Assigned(FSQLConnection) then
        DatabaseError(SConnectionNameMissing)
      else
      begin
        if Value and (FileName <> '') then
        begin
          if not FileExists(FileName) then
          begin
            FileHandle := FileCreate(FileName);
            if FileHandle = -1 then
              DatabaseErrorFmt(SCannotCreateFile, [FileName])
            else
              FileClose(FileHandle);
          end;
        end;
        if Assigned(FSQLConnection) then
        begin
          if Value then
            FSQLConnection.SetTraceCallbackEvent(SQLCallBack, Integer(Self))
          else
            FSQLConnection.SetTraceCallbackEvent(nil, Integer(0));
        end;
        FActive := Value;
      end;
    end;
  end;
end;

procedure TSQLMonitor.SetStreamedActive;
begin
  if FStreamedActive then 
    SetActive(True);
end;

function TSQLMonitor.GetTraceCount: Integer;
begin
  Result := FTraceList.Count;
end;

procedure TSQLMonitor.LoadFromFile(AFileName: string);
begin
  if AFileName <> '' then
    FTraceList.LoadFromFile(ExpandFileName(AFileName))
  else if FFileName <> '' then
    FTraceList.LoadFromFile(string(FFileName))
  else
    DatabaseError(SFileNameBlank);
end;

procedure TSQLMonitor.SaveToFile(AFileName: string);
begin
  if AFileName <> '' then
    FTraceList.SaveToFile(ExpandFileName(AFileName))
  else if FFileName <> '' then
    FTraceList.SaveToFile(FFileName)
  else
    DatabaseError(SFileNameBlank);
end;

procedure TSQLMonitor.SetTraceList(Value: TStrings);
begin
  if FTraceList <> Value then
  begin
    FTraceList.BeginUpdate;
    try
      FTraceList.Assign(Value);
    finally
      FTraceList.EndUpdate;
    end;
  end;
end;


{ TSQLConnection }

constructor TSQLConnection.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FParams := TStringList.Create;
  FAutoClone := True;
  try
    FConnectionRegistryFile := GetConnectionRegistryFile(csDesigning in ComponentState);
  except
    FConnectionRegistryFile := '';
  end;
  FKeepConnection := True;
  FMonitorUsers := TList.Create;
  FSQLHourGlass := True;
  FQuoteChar := '';
  FTableScope := [tsTable, tsView];
  LoginPrompt := True;
end;

destructor TSQLConnection.Destroy;
begin
  Destroying;
  ClearConnectionUsers;
  Close;
  ClearMonitors;
  FreeAndNil(FMonitorUsers);
  inherited Destroy;
  FParams.Free;
end;

{ user registration }

procedure TSQLConnection.ClearConnectionUsers;
begin
  while DataSetCount > 0 do
  begin
    if TCustomSQLDataSet(DataSets[0]).Active then
      TCustomSQLDataSet(DataSets[0]).Close;
    TCustomSQLDataSet(DataSets[0]).FreeStatement;
    TCustomSQLDataSet(DataSets[0]).SetConnection(nil);
  end;
end;

procedure TSQLConnection.ClearMonitors;
var
  I: Integer;
begin
  for I := 0 to FMonitorUsers.Count -1 do
  begin
    if Self.FIsCloned then
      TSQLMonitor(FMonitorUsers[0]).SwitchConnection(Self.FCloneParent)
    else 
    begin
      TSQLMonitor(FMonitorUsers[0]).SetActive(False);
      TSQLMonitor(FMonitorUsers[0]).FSQLConnection := nil;
    end;
  end;
end;

procedure TSQLConnection.RegisterTraceMonitor(Client: TObject);
begin
  FMonitorUsers.Add(Client);
end;

procedure TSQLConnection.UnregisterTraceMonitor(Client: TObject);
begin
  FMonitorUsers.Remove(Client);
end;

{ Exception handling routine }

procedure TSQLConnection.SQLError(OpStatus: SQLResult; eType: TSQLExceptionType; const Command: ISQLCommand = nil);
var
  ExceptionMessage: string;
  Message: PChar;
  Status: SQLResult;
  MessageLen: SmallInt;
begin
  Status := SQL_NULL_DATA;
  ExceptionMessage := SErrorMappingError;
  Message := nil;
  if (OpStatus > 0) and (OpStatus <=  DBX_MAXSTATICERRORS) then
    ExceptionMessage := DbxError[ OpStatus ]
  else if (OpStatus > 0) and (OpStatus < MaxReservedStaticErrors) then
    ExceptionMessage := SDBXUNKNOWNERROR
  else
    begin
      case eType of
        exceptCommand:
          begin
            Status := Command.getErrorMessageLen(MessageLen);
            if (Status = SQL_SUCCESS) and (MessageLen > 0) then
            begin
              Message := AllocMem(MessageLen + 1);
              Status := Command.getErrorMessage(Message);
            end;
          end;
        exceptConnection:
          begin
            Status := FISQLConnection.getErrorMessageLen(MessageLen);
            if (Status = SQL_SUCCESS) and (MessageLen > 0) then
            begin
              Message := AllocMem(MessageLen + 1);
              Status := FISQLConnection.getErrorMessage(Message);
            end;
          end;
        exceptMetaData:
          begin
            Status := FSQLMetaData.getErrorMessageLen(MessageLen);
            if (Status = SQL_SUCCESS) and (MessageLen> 0) then
            begin
              Message := AllocMem(MessageLen + 1);
              Status := FSQLMetaData.getErrorMessage(Message);
            end;
          end;
      end;
      if Status = SQL_SUCCESS then
      begin
        if MessageLen > 0 then
        begin
          SetString(ExceptionMessage, Message, StrLen(Message));
        end else
          ExceptionMessage := SErrorMappingError; 
      end 
      else if LastError <> '' then
        ExceptionMessage := LastError;
      if Assigned(Message) then
        FreeMem(Message);
      if ExceptionMessage = '' then
        ExceptionMessage := LastError;
    end;
  FLastError := ExceptionMessage;
  DatabaseError(ExceptionMessage);
end;

{ loading, connecting and disconnecting }

procedure TSQLConnection.LoadSQLDll;
begin
{$IFDEF MSWINDOWS}
  if DllHandle = THandle(0) then
  begin
{$ENDIF}
  try
    SetCursor(HourGlassCursor);
    if SQLDllHandle = THandle(0) then
      SQLDllHandle := THandle(LoadLibrary(PChar(trim(LibraryName))));
    if SQLDllHandle = THandle(0) then
      DataBaseErrorFmt(sDLLLoadError, [LibraryName]);
    GetDriver := GetProcAddress(HMODULE(SQLDllHandle), PChar(trim(GetDriverFunc)));
    if not Assigned(GetDriver) then
      DataBaseErrorFmt(sDLLProcLoadError, [GetDriverFunc])
  finally
    SetCursor(DefaultCursor);
  end;
{$IFDEF MSWINDOWS}
end;
{$ENDIF}
end;

procedure TSQLConnection.CheckConnection(eFlag: eConnectFlag);
begin
  if (eFlag in [eDisconnect, eReconnect]) then
    Close;
  if (eFlag in [eConnect, eReconnect]) then
    Open
end;

procedure TSQLConnection.Login(LoginParams: TStrings);
var
  UserName, Password: string;

  function Login: Boolean;
  begin
    Result := Assigned(FOnLogin);
    if Result then FOnLogin(Self, LoginParams);
  end;

begin
  if not Login then
  begin
    UserName := LoginParams.Values[szUserName];
    if Assigned(LoginDialogExProc) then
    begin
      SetCursor(DefaultCursor); 
      if not LoginDialogExProc(ConnectionName, UserName, Password, False) then
        DatabaseErrorFmt(SLoginError, [ConnectionName]);
      SetCursor(HourGlassCursor);
      LoginParams.Values[szUSERNAME] := UserName;
      LoginParams.Values[szPASSWORD] := Password;
    end;
  end;
end;

procedure TSQLConnection.CheckLoginParams;
var
  I: Integer;
begin
  if FLoadParamsOnConnect then LoadParamsFromIniFile;
  if LoadParamsOnConnect then FDriverName := GetProfileString(FConnectionName, DRIVERNAME_KEY, ConnectionRegistryFile);
  if FDriverName = '' then DataBaseError(SMissingDriverName);
  if LoadParamsOnConnect then 
    FLibraryName := GetProfileString(FDriverName, DLLLIB_KEY, GetDriverRegistryFile(csDesigning in ComponentState));
  if FLibraryName = '' then DataBaseError(SMissingDLLName, Self);
  if LoadParamsOnConnect then 
    FVendorLib := trim(GetProfileString(FDriverName, VENDORLIB_KEY, GetDriverRegistryFile));
  if FVendorLib = '' then DataBaseError(SMissingDLLName, Self);
  if LoadParamsOnConnect then
    FGetDriverFunc := GetProfileString(FDriverName, GETDRIVERFUNC_KEY, GetDriverRegistryFile);
  if Params.Values[DATABASENAME_KEY] = '' then
  begin
    if FConnectionName = '' then DataBaseError(SConnectionNameMissing)
    else DataBaseError(SMissingDatabaseName);
  end;
  for I := 0 to FMonitorUsers.Count -1 do
    TSQLMonitor(FMonitorUsers[i]).SetStreamedActive;
end;

function TSQLConnection.GetQuoteChar: string;
var
  Status: SQLResult;
  Len: SmallInt;
  Q: Char;
begin
  FQuoteChar := '';
  Len := 1;
  Q := #0;
  Status := FSQLMetadata.getOption(eMetaObjectQuoteChar, @Q, Len, Len);
  if (Q <> #0) and (Status = SQL_SUCCESS) then
    FQuoteChar := Q;
  Result := FQuoteChar;
end;

procedure TSQLConnection.SetCursor(CursorType: Integer);
begin
  if SQLHourGlass or (CursorType = DefaultCursor) then
    if Assigned(ScreenCursorProc) then
      ScreenCursorProc(CursorType);
end;

procedure TSQLConnection.ConnectionOptions;
var
  PropSize: SmallInt;
  SupTransactions: LongBool;
begin
  GetQuoteChar;
  if FParams.Values[MAXBLOBSIZE_KEY] <> '' then
    FISQLConnection.SetOption(eConnBlobSize, LongInt(StrToInt(trim(FParams.Values[MAXBLOBSIZE_KEY]))))
  else
    FISQLConnection.SetOption(eConnBlobSize, LongInt(DefaultMaxBlobSize));
  FSQLMetaData.GetOption(eMetaSupportsTransaction, @SupTransactions, SizeOf(Integer), PropSize);
  if SupTransactions then
    FTransActionsSupported := True
  else
    FTransActionsSupported := False;
  FSQLMetaData.GetOption(eMetaSupportsTransactions, @FSupportsMultiTrans, SizeOf(Integer), PropSize);
end;

procedure TSQLConnection.DoConnect;
var
  Status: SQLResult;
  LoginParams: TStrings;
  PropSize: SmallInt;
  TrimmedUserName: string;
begin
  CheckLoginParams;
  ConnectionState := csStateConnecting;
  LoadSQLDll;
  LoginParams := TStringList.Create;
  try
    SetCursor(HourGlassCursor);
    Status := getDriver(PChar(FVendorLib), PChar(Trim(FParams.Values[ERROR_RESOURCE_KEY])), FSQLDriver);
    if Status <> SQL_SUCCESS then
      DataBaseErrorFmt(sDLLLoadError, [FVendorLib]);
    Check(FSQLDriver.setOption(eDrvRestrict, GDAL));
    Check(FSQLDriver.getSQLConnection(FISQLConnection));
    GetLoginParams(LoginParams);
    SetCursor(HourGlassCursor);
    RegisterTraceCallback(True);
    SetConnectionParams;
    Check(Connection.connect(PChar(trim(LoginParams.Values[DATABASENAME_KEY])), PChar(LoginParams.Values[ szUSERNAME ]),
         PChar(LoginParams.Values[ szPASSWORD ])));
    FISQLConnection.getOption(eConnMaxActiveConnection, @FMaxStmtsPerConn, Sizeof(Integer), PropSize);
    Check(Connection.getSQLMetaData(FSQLMetaData));
    TrimmedUserName := trim(LoginParams.Values[ szUSERNAME ]);
    if TrimmedUserName <> '' then
      FSQLMetaData.SetOption(eMetaSchemaName, LongInt(TrimmedUserName));
    ConnectionOptions;
    ConnectionState := csStateOpen;
  finally
    SetCursor(DefaultCursor);
    LoginParams.Free;
    if ConnectionState = csStateConnecting then
    begin
      ConnectionState := csStateClosed;
      SQLDllHandle := THandle(0);
      if Assigned(FISQLConnection) then
        FISQLConnection := nil;
    end;
  end;
end;

procedure TSQLConnection.GetLoginParams(LoginParams: TStrings);
var
  I: Integer;
  PName: string;
begin
  LoginParams.BeginUpdate;
  try
    LoginParams.Clear;
    for I := 0 to FParams.Count - 1 do
      begin
        if LoginParams.IndexOf(FParams[I]) > -1 then continue;
        PNAME := FParams.Names[I];
        if CompareText(PName, szPASSWORD) = 0 then
           LoginParams.Add(format('%s=%s',[szPASSWORD, FParams.Values[szPASSWORD] ]))
        else if CompareText(PName, szUSERNAME) = 0 then
           LoginParams.Add(format('%s=%s',[szUSERNAME, FParams.Values[szUSERNAME]]))
        else if CompareText(PName, DATABASENAME_KEY) = 0 then
          LoginParams.Add(format('%s=%s',[DATABASENAME_KEY, trim(FParams.Values[DATABASENAME_KEY])]));
      end;
  finally
    LoginParams.EndUpdate;
  end;
  if LoginPrompt then
     Login(LoginParams);
end;

function TSQLConnection.GetConnected: Boolean;
begin
  Result := Assigned(FISQLConnection) and (not
      (ConnectionState in [csStateClosed, csStateConnecting,
      csStateDisconnecting]));
end;

procedure TSQLConnection.DoDisconnect;
begin
  if FSQLDriver <> nil then
  begin
     ConnectionState := csStateDisconnecting;
     CloseDataSets;
     RegisterTraceCallback(False);
     if (FSQLMetaData <> nil) then
        FSQLMetaData := nil;
     if (FISQLConnection <> nil) then
     begin
        FISQLConnection.disconnect;
        FISQLConnection := nil;
     end;
     SQLDllHandle := THandle(0);
     ConnectionState := csStateClosed;
     FSQLDriver := nil;
     FActiveStatements := 0;
  end;
  FParamsLoaded := False;
end;

procedure TSQLConnection.CloseDataSets;
var
  I: Integer;
begin
  for I := 0 to DataSetCount -1 do
  begin
    if TCustomSQLDataSet(DataSets[i]).Active then TCustomSQLDataSet(DataSets[i]).Close;
    TCustomSQLDataSet(DataSets[i]).FreeStatement;
  end;
  for I := 0 to FMonitorUsers.Count -1 do
  begin
    if Self.FIsCloned then
      TSQLMonitor(FMonitorUsers[I]).SwitchConnection( Self.FCloneParent );
  end;
end;

procedure TSQLConnection.CheckDisconnect;
var
  I: Integer;
begin
  if Connected and not (KeepConnection or InTransaction or (csLoading in ComponentState)) then
  begin
    for I := 0 to DataSetCount - 1 do
      if (DataSets[I].State <> dsInActive) then Exit;
    Close;
  end;
end;

procedure TSQLConnection.CheckInactive;
begin
  if FISQLConnection <> nil then
    if csDesigning in ComponentState then
      Close 
    else
      DatabaseError(SdatabaseOpen, Self);
end;

procedure TSQLConnection.CheckActive;
begin
  if FISQLConnection = nil then DatabaseError(SDatabaseClosed, Self);
end;

{ Query execution }

function TSQLConnection.GetConnectionForStatement: TSQLConnection;
begin
  if (FMaxStmtsPerConn > 0) and (FActiveStatements >= FMaxStmtsPerConn) then
  begin
    if not AutoClone then
      DataBaseErrorFmt(SMultiConnNotSupported, [DriverName]);
    Result := CloneConnection;
  end else
    Result := Self;
end;

function TSQLConnection.ExecuteDirect(const SQL: string): LongWord;
var
  Command: ISQLCommand;
  Cursor: ISQLCursor;
  Status: SQLResult;
  Connection: TSQLConnection;
  RowsetSize: Integer;
begin
  CheckConnection(eConnect);
  Cursor := nil;
  Result := 0;
  RowsetSize := defaultRowsetSize;
  Connection := GetConnectionForStatement;
  if Connection.FISQLConnection.getSQLCommand(Command) = SQL_SUCCESS then
  begin

    if Params.Values[ROWSETSIZE_KEY] <> '' then
    try
      RowsetSize := StrToInt(trim(Params.Values[ROWSETSIZE_KEY]));
    except
      RowsetSize := defaultRowsetSize;
    end;
    Command.setOption(eCommRowsetSize, RowsetSize);

    Status := Command.executeImmediate(PChar(SQL), Cursor);
    if Status = SQL_SUCCESS then
    begin
      Status := Command.getRowsAffected(Result);
      if not Assigned(Cursor) then
        Command.Close;
    end;
    if Status <> SQL_SUCCESS then
      SQLError(Status, exceptCommand, Command);
  end;
end;

procedure SetQueryParams(const Sender: TSQLConnection; const Command: ISQLCommand;
  const Params: TParams);
var
  I, IInd: Integer;
  NumBytes, iFldNum: LongWord;
  RecBuffer: PChar;
  iFldType, iSubType: Word;
  iUnits1, iUnits2: Integer;
  DrvLocale: TLocale;
  Status: SQLResult;
  SBcd: string;
  Bcd: TBcd;
begin
  DrvLocale := nil;
  for I := 0 to Params.Count - 1 do
    begin
      RecBuffer := nil;
      if Params[I].IsNull then iInd := 1 else iInd := 0;
      try
        if Params[I].ParamType = ptUnknown then  // Midas assumes its Input
          Params[I].ParamType := ptInput;
        iFldNum := i + 1;
        iFldType := FldTypeMap[Params[I].DataType];
        iSubType := 0;
        iUnits1 := 0;
        iUnits2 := 0;
        if iFldType in [fldBlob, fldZString] then
          iSubType := Word(FldSubTypeMap[Params[I].DataType])
        else if iFldType = fldUNKNOWN then
          DatabaseErrorFmt(SNoParameterValue, [Params[I].Name]);
        NumBytes := Params[I].GetDataSize;
        if iInd = 1 then
          RecBuffer := nil
        else begin
          RecBuffer := AllocMem(NumBytes);
          GetParamData(Params[I], RecBuffer, DrvLocale);
        end;
        case iFldType of
          fldZString:
            begin
              if NumBytes > 0 then
                iUnits1 := Params[I].GetDataSize - 1    {Do not include null terminator}
              else
                iUnits1 := 0;
              iUnits2 := 0;
            end;
          fldBLOB:
            iUnits1 := NumBytes;
          fldBYTES:
            iUnits1 := Params[I].GetDataSize;
          fldVARBYTES:
            iUnits1 := Params[I].GetDataSize - 2;
          fldFLOAT:
            iUnits1 := SizeOf(double);
          fldFMTBCD, fldBCD:
            begin
              iFldType := fldBCD;   { DBExpress does not distinguish }
              if iInd = 0 then
              begin
                SBcd := BcdToStr(PBcd(RecBuffer)^);
                Bcd := StrToBcd(SBcd);
                iUnits1 := Bcd.Precision;
                iUnits2 := Bcd.SignSpecialPlaces AND $3F;
              end;
            end
        end;
        Status := Command.setParameter(iFldNum, 0, TSTMTParamType(Params[I].ParamType),
                iFldType, iSubType, Integer(iUnits1), Integer(iUnits2), NumBytes, RecBuffer, IInd);
        if (Status <> SQL_Success) then
          Sender.SQLError(Status, exceptConnection);
      finally
        if RecBuffer <> nil then FreeMem(RecBuffer);
      end;
    end;
end;

function TSQLConnection.Execute(const SQL: string; Params: TParams;
  ResultSet: Pointer = nil): Integer;
var
  Status: SQLResult;
  SQLText: string;
  RowsAffected: LongWord;
  DS: TCustomSQLDataSet;
  I, ParamCount: Integer;
begin
  Result := 0;
  DS := TCustomSQLDataSet.Create(nil);
  try
    CheckConnection(eConnect);
    SetCursor(HourGlassCursor);
    DS.SQLConnection := Self;
    ConnectionState := csStateExecuting;
    if (Params <> nil) and (Params.Count > 0) then
    begin
      SQLText := FixParams(SQL, Params.Count, Self.GetQuoteChar);
      ParamCount := Params.Count;
    end else
    begin
      SQLText := Copy(SQL, 1, Length(SQL));
      ParamCount := 0;
    end;
    DS.FCommandText := SQLText;
    if ResultSet = nil then
    begin
      DS.CheckStatement;
      Status := DS.FSQLCommand.prepare(PChar(SQLText), ParamCount);
      if Status <> SQL_SUCCESS then
        SQLError(Status, exceptCommand, DS.FSQLCommand);
      if ParamCount > 0 then
        SetQueryParams(Self, DS.FSQLCommand, Params);
      Status := DS.FSQLCommand.execute(DS.FSQLCursor);
      if Status <> SQL_SUCCESS then
        SQLError(Status, exceptCommand, DS.FSQLCommand);
      Status := DS.FSQLCommand.getRowsAffected(RowsAffected);
      if Status <> SQL_SUCCESS then
        SQLError(Status, exceptCommand, DS.FSQLCommand);
      Result := RowsAffected;
    end else
    begin
      if ParamCount > 0 then
      begin
        for I := 0 to ParamCount -1 do
        begin
          DS.Params.CreateParam(Params.Items[I].DataType, format('P%d',[I+1]),
             ptInput);
          DS.Params[I].Value := Params[I].Value;
        end;
      end;
      DS.MaxBlobSize := -1;
      DS.Active := True;
    end;
  finally
    SetCursor(DefaultCursor);
    if ResultSet = nil then
      DS.Free
    else
      TCustomSQLDataSet(ResultSet^) := DS;
    ConnectionState := csStateOpen;
  end;
end;

{ Metadata retrieval }

function TSQLConnection.CloneConnection: TSQLConnection;
var
  SelfParent: TSQLConnection;
  I: Integer;
begin      // do not allow nested clones
  if Self.FIsCloned then
    SelfParent := Self.FCloneParent
  else
    SelfParent := Self;
  Result := TSQLConnection.Create(nil);
  Result.FIsCloned := True;
  Result.FLoadParamsOnConnect := False;
  Result.LoginPrompt := False;
  Result.FDriverName := SelfParent.FDriverName;
  Result.FConnectionName := SelfParent.FConnectionName;
  Result.Name := SelfParent.Name + 'Clone1';
  Result.FParams.AddStrings(SelfParent.FParams);
  Result.FGetDriverFunc := SelfParent.FGetDriverFunc;
  Result.FLibraryName := SelfParent.FLibraryName;
  Result.FVendorLib := SelfParent.VendorLib;
  Result.Connected := Self.Connected;
  Result.FCloneParent := SelfParent;
  for I := 0 to FMonitorUsers.Count -1 do
    TSQLMonitor(FMonitorUsers[I]).SwitchConnection( Result );
end;

function TSQLConnection.OpenSchemaTable(eKind: TSchemaType; SInfo: string; SQualifier: string = ''): TCustomSQLDataSet;
var
  DataSet: TCustomSQLDataSet;
begin
  CheckConnection(eConnect);
  DataSet := TCustomSQLDataSet.Create(nil);
  try
    DataSet.SetConnection(Self);
    DataSet.SetSchemaInfo(eKind, SInfo, SQualifier);
    DataSet.SetActive(True);
  except
    FreeSchemaTable(DataSet);
    DataSet := nil;
  end;
  Result := DataSet;
end;

procedure TSQLConnection.FreeSchemaTable(DataSet: TCustomSQLDataSet);
var
  SaveKeepConnection: Boolean;
begin
  FreeAndNil(DataSet.FClonedConnection);
  SaveKeepConnection := FKeepConnection;
  FKeepConnection := True;  
  if Assigned(Dataset) then
    DataSet.Free;
  FKeepConnection := SaveKeepConnection;
end;

procedure TSQLConnection.OpenSchema(eKind: TSchemaType; sInfo: string; List: TStrings);
const
  TBL_NAME_FIELD = 'TABLE_NAME';           { Do not localize }
  PROC_NAME_FIELD = 'PROC_NAME';           { Do not localize }
  COL_NAME_FIELD = 'COLUMN_NAME';          { Do not localize }
  IDX_NAME_FIELD = 'INDEX_NAME';           { Do not localize }
var
  DataSet: TCustomSQLDataSet;
  NameField: TField;
  ColName: string;
begin
  CheckConnection(eConnect);
  if FISQLConnection = nil then
    DatabaseError(sConnectionNameMissing);
  DataSet := nil;
  NameField := nil;
  try
    CheckActive;
    SetCursor(HourGlassCursor);
    DataSet := OpenSchemaTable(eKind, sInfo);
    if Assigned(DataSet) then
    begin
      case eKind of
        stColumns:
          NameField := DataSet.FieldByName(COL_NAME_FIELD);
        stProcedures:
          begin
            if not Assigned(DataSet) then DatabaseErrorFmt(SStoredProcsNotSupported, [FDriverName]);
            NameField := DataSet.FieldByName(PROC_NAME_FIELD);
          end;
        stIndexes:
          NameField := DataSet.FieldByName(IDX_NAME_FIELD);
        stTables, stSysTables:
          NameField := DataSet.FieldByName(TBL_NAME_FIELD);
      end;
      List.BeginUpdate;
      try
        List.Clear;
        while not DataSet.EOF do
        begin
          ColName := NameField.AsString;
          if Pos(',' + ColName + ',', ',' + List.CommaText + ',') = 0 then
            List.Add(ColName);
          DataSet.Next;
        end;
      finally
        SetCursor(DefaultCursor);
        List.EndUpdate;
      end;
    end;
  finally
    if Assigned(DataSet) then FreeSchemaTable(DataSet);
  end;
end;

procedure TSQLConnection.GetFieldNames(const TableName: string; List: TStrings);
begin
  OpenSchema(stColumns, TableName, List);
end;

procedure TSQLConnection.GetProcedureNames(List: TStrings);
begin
  OpenSchema(stProcedures, '', List);
end;

procedure TSQLConnection.GetTableNames(List: TStrings;
  SystemTables: Boolean = False);
var
  eType: TSchemaType;
begin
  if SystemTables then
    eType := stSysTables
  else
    eType := stTables;
  OpenSchema(eType, '', List);
end;

procedure TSQLConnection.GetIndexNames(const TableName: string; List: TStrings);
begin
  OpenSchema(stIndexes, TableName, List);
end;

procedure TSQLConnection.GetProcedureParams(ProcedureName: string; List: TList);
const
  TypeFieldName = 'PARAM_TYPE';             { do not localize }
  DataTypeFieldName = 'PARAM_DATATYPE';     { do not localize }
  SubTypeFieldName = 'PARAM_SUBTYPE';       { do not localize }
  PosFieldName = 'PARAM_POSITION';          { do not localize }
  PrecisionFieldName = 'PARAM_PRECISION';   { do not localize }
  ScaleFieldName = 'PARAM_SCALE';           { do not localize }
  LengthFieldName = 'PARAM_LENGTH';         { do not localize }
  ParamNameFieldName = 'PARAM_NAME';        { do not localize }
  ResultParam = 'Result';                   { Do not localize }
var
  DataSet: TCustomSQLDataSet;
  ArgDesc: pSPParamDesc;
  V: Variant;
begin
  DataSet := nil;
  try
    DataSet := OpenSchemaTable(stProcedureParams, ProcedureName);
    if not Assigned(DataSet) then SQLError(SQLResult(-1), exceptMetadata);
    while not DataSet.EOF do
    begin
      New(ArgDesc);
      ArgDesc^.iParamNum := DataSet.FieldByName(PosFieldName).Value;
      V := DataSet.FieldByName(TypeFieldName).Value;
      if VarIsNull(V) then
        ArgDesc^.iArgType := ptUnknown
      else
        ArgDesc^.iArgType := V;
      V := DataSet.FieldByName(DataTypeFieldName).Value;
      if VarIsNull(V) then
        ArgDesc^.iDataType := ftUnknown
      else
        ArgDesc^.iDataType := DataTypeMap[Integer(V)];
      V := DataSet.FieldByName(SubTypeFieldName).Value;
      if not VarIsNull(V) then
        if V = fldstFIXED then
          ArgDesc^.iDataType := ftFixedChar;
      V := DataSet.FieldByName(PrecisionFieldName).Value;
      if VarIsNull(V) then
        ArgDesc^.iUnits1 := 0
      else
        ArgDesc^.iUnits1 := V;
      V := DataSet.FieldByName(ScaleFieldName).Value;
      if VarIsNull(V) then
        ArgDesc^.iUnits2 := 0
      else
        ArgDesc^.iUnits2 := V;
      V := DataSet.FieldByName(LengthFieldName).Value;
      if VarIsNull(V) then
        ArgDesc^.iLen := 0
      else
        ArgDesc^.iLen := V;
      V := DataSet.FieldByName(ParamNameFieldName).Value;
      if VarIsNull(V) then
        ArgDesc^.szName := ResultParam
      else
        ArgDesc^.szName := V;
      List.Add(ArgDesc);
      DataSet.next;
    end;
  finally
    FreeSchemaTable(DataSet);
  end;
end;

{ trace }

procedure TSQLConnection.SetTraceCallbackEvent(Event: TSQLCallbackEvent; IClientInfo: Integer); 
begin
  FTraceCallbackEvent := Event;
  FTraceClientData := IClientInfo;
  if Connected and not (csLoading in ComponentState) then
    RegisterTraceCallBack(Assigned(Event) and (IClientInfo > 0));
end;

procedure TSQLConnection.RegisterTraceCallback(Value: Boolean);
begin
  if (Value) then
  begin
    if Assigned(FTraceCallbackEvent) and (FTraceClientData <> 0) then
    begin
      Check(FISQLConnection.SetOption(
           TSQLConnectionOption(eConnCallBack), Integer(@FTraceCallbackEvent)));
      Check(FISQLConnection.SetOption(
           TSQLConnectionOption(eConnCallBackInfo), Integer(FTraceClientData)));
    end;
  end else
  begin
    if Assigned(FISQLConnection) then
    begin
      Check(FISQLConnection.SetOption(
            TSQLConnectionOption(eConnCallback), Integer(0)));
      Check(FISQLConnection.SetOption(
            TSQLConnectionOption(eConnCallBackInfo), Integer(0)));
    end;
  end;
end;

{ transaction support }

function TSQLConnection.GetInTransaction: Boolean;
begin
  Result := FTransactionCount > 0;
end;

procedure TSQLConnection.StartTransaction( TransDesc: TTransactionDesc);
var
  Status: SQLResult;
begin
  CheckConnection(eConnect);
  if Connected then
  begin
    if FTransactionsSupported then
    begin
      CheckActive;
      if (not InTransaction) or FSupportsMultiTrans then
      begin
        Status := FISQLConnection.beginTransaction(LongWord(@TransDesc));
        if not ( Status in [SQL_SUCCESS, DBXERR_NOTSUPPORTED] ) then
          Check(Status);
        Inc(FTransactionCount);
      end else
        DatabaseError(sActiveTrans, self)
    end;
  end else
    DatabaseError(SDatabaseClosed, Self);
end;

procedure TSQLConnection.Rollback( TransDesc: TTransactionDesc);
var
  Status: SQLResult;
begin
  if FTransactionsSupported then
  begin
    if InTransaction then
    begin
      if Assigned(FISQLConnection) then
      begin
        Status := FISQLConnection.rollback(LongWord(@TransDesc));
        if not ( Status in [SQL_SUCCESS, DBXERR_NOTSUPPORTED] ) then
          Check(Status);
        Dec(FTransactionCount);
      end
      else
        DatabaseError(SDatabaseClosed, Self);
    end else
      DatabaseError(sNoActiveTrans, self);
    CheckDisconnect;
  end;
end;

procedure TSQLConnection.Commit(TransDesc: TTransactionDesc);
var
  Status: SQLResult;
begin
  if FTransactionsSupported then
  begin
    if InTransaction then
    begin
      if Assigned(FISQLConnection) then
      begin
        Status := FISQLConnection.Commit(LongWord(@TransDesc));
        if not ( Status in [SQL_SUCCESS, DBXERR_NOTSUPPORTED] ) then
          Check(Status);
        Dec(FTransactionCount);
      end
      else
        DatabaseError(SDatabaseClosed, Self);
    end
    else
      DatabaseError(sNoActiveTrans, self);
    CheckDisconnect;
  end;
end;

function TSQLConnection.GetDataSet(Index: Integer): TCustomSQLDataSet;
begin
  Result := TCustomSQLDataSet(inherited GetDataSet(Index));
end;

{ misc. property set/get }

procedure TSQLConnection.SetDriverName(Value: string);

  procedure LoadDriverParams;
  var
    Index: Integer;
  begin
    FConnectionName := DriverName;
    LoadParamsFromIniFile(DriverRegistryFile);
    FConnectionName := '';
    Index := Params.IndexOfName(VENDORLIB_KEY);
    if Index <> -1 then
      Params.Delete(Index);
    Index := Params.IndexOfName(DLLLIB_KEY);
    if Index <> -1 then
      Params.Delete(Index);
    Index := Params.IndexOfName(GETDRIVERFUNC_KEY);
    if Index <> -1 then
      Params.Delete(Index);
  end;

begin
  if FDriverName <> Value then
  begin
    CheckInactive;
    if FConnectionName = '' then
    begin
      FVendorLib := '';
      FLibraryName := '';
      FGetDriverFunc := '';
      FParams.Clear;
    end;
    FDriverName := Value;
    if (csDesigning in ComponentState) and not (csLoading in ComponentState) then
    begin
      FParams.Clear;
      FParamsLoaded := False;
      if FDriverName <> '' then
      begin
        try
          FVendorLib := GetProfileString(FDriverName, VENDORLIB_KEY, DriverRegistryFile);
          FLibraryName := GetProfileString(FDriverName, DLLLIB_KEY, DriverRegistryFile);
          FGetDriverFunc := GetProfileString(FDriverName, GETDRIVERFUNC_KEY, DriverRegistryFile);
          if FConnectionName = '' then
            LoadDriverParams;
        except
          DatabaseErrorFmt(SDriverNotInConfigFile, [Value, DriverRegistryFile]);
        end;
      end;
    end;
  end;
end;

function TSQLConnection.GetFDriverRegistryFile: string;
begin
  if FDriverRegistryFile = '' then
    FDriverRegistryFile := GetDriverRegistryFile(csDesigning in ComponentState);
  Result := FDriverRegistryFile;
end;

function TSQLConnection.GetConnectionName: string;
begin
  Result := FConnectionName;
end;

procedure TSQLConnection.SetConnectionName(Value: string);
var
  NewDriver: string;
begin
  if FConnectionName <> Value then
  begin
    FLastError := '';
    if not (csLoading in ComponentState) then
      if Connected then Connected := False;
    if (FDriverName = '') and (Value = '') then
    begin
      FVendorLib := '';
      FLibraryName := '';
      FParams.Clear;
    end;
    FParamsLoaded := False;
    FConnectionName := Value;
    if not (csLoading in ComponentState) then
      CloseDataSets;
    if (csDesigning in ComponentState) and not (csLoading in ComponentState) then
    begin
      FParams.Clear;
      if Value <> '' then
      begin
        NewDriver := GetProfileString(FConnectionName, DRIVERNAME_KEY, ConnectionRegistryFile);
        if NewDriver <> DriverName then
          DriverName := NewDriver;
        LoadParamsFromIniFile;
      end;
    end;
  end;
end;

function TSQLConnection.GetVendorLib: string;
begin
  Result := FVendorLib;
  if (Result = '') and (FLoadParamsOnConnect or (csLoading in ComponentState)) then
    Result := trim(GetProfileString(FDriverName, VENDORLIB_KEY, DriverRegistryFile));
end;

function TSQLConnection.GetLibraryName: string;
begin
  Result := FLibraryName;
  if (Result = '') and (FLoadParamsOnConnect or (csLoading in ComponentState)) then
    Result := GetProfileString(FDriverName, DLLLIB_KEY, DriverRegistryFile);
end;

procedure TSQLConnection.SetConnectionParams;
var
  ServerCharSet, STransIsolationKey: string;
  ILevel: TTransIsolationLevel;
begin
  if FParams.Values[HOSTNAME_KEY] <> '' then
    FISQLConnection.SetOption(eConnHostName, LongInt(trim(FParams.Values[HOSTNAME_KEY])));
  if FParams.Values[ROLENAME_KEY] <> '' then
    FISQLConnection.SetOption(eConnRoleName, LongInt(trim(FParams.Values[ROLENAME_KEY])));
  if FParams.Values[WAITONLOCKS_KEY] <> '' then
    FISQLConnection.SetOption(eConnWaitOnLocks, LongInt(UpperCase(trim(FParams.Values[WAITONLOCKS_KEY])) = 'TRUE'));
  if FParams.Values[COMMITRETAIN_KEY] <> '' then
    FISQLConnection.SetOption(eConnCommitRetain, LongInt(UpperCase(trim(FParams.Values[COMMITRETAIN_KEY])) = 'TRUE'));
  if FParams.Values[AUTOCOMMIT_KEY] <> '' then
    FISQLConnection.SetOption(eConnAutoCommit, LongInt(UpperCase(trim(FParams.Values[AUTOCOMMIT_KEY])) = 'TRUE'));
  if FParams.Values[BLOCKINGMODE_KEY] <> '' then
    FISQLConnection.SetOption(eConnBlockingMode, LongInt(UpperCase(trim(FParams.Values[BLOCKINGMODE_KEY])) = 'TRUE'));
  ServerCharSet := trim(FParams.Values[SQLSERVER_CHARSET_KEY]);
  if ServerCharSet <> '' then
    FISQLConnection.SetOption(eConnServerCharSet, LongInt(PChar(ServerCharSet)));
  STransIsolationKey := Format(TRANSISOLATION_KEY, [DriverName]);
  if FParams.Values[STransIsolationKey] <> '' then
  begin
    if LowerCase(FParams.Values[STransIsolationKey]) = SRepeatRead then
      ILevel := xilRepeatableRead
    else if LowerCase(FParams.Values[STransIsolationKey]) = SDirtyRead then
      ILevel := xilDirtyRead
    else
      ILevel := xilReadCommitted;
    FISQLConnection.SetOption(eConnTxnIsoLevel, LongInt(ILevel));
    if FParams.Values[SQLDIALECT_KEY] <> '' then
      FISQLConnection.SetOption(eConnSQLDialect, LongInt(StrToInt(trim(FParams.Values[SQLDIALECT_KEY]))));
  end;
end;

procedure TSQLConnection.LoadParamsFromIniFile(FFileName: string = '');
var
  IniFile: TMemIniFile;
  List: TStrings;
  FIniFileName: string;
begin
  if not FParamsLoaded then
  begin
    if FConnectionName = '' then
      DatabaseError(SConnectionNameMissing);
    List := TStringList.Create;
    try
      if FFileName = '' then
        FIniFileName := ConnectionRegistryFile
      else
        FIniFileName := FFileName;
      IniFile := TMemIniFile.Create(FIniFileName);
      try
        if FileExists(FIniFileName) then
        begin
          IniFile.ReadSectionValues(FConnectionName, List);
          Params.BeginUpdate;
          try
            Params.Clear;
            Params.AddStrings(List);
          finally
            Params.EndUpdate;
          end;
        end else
          DatabaseErrorFmt(sMissingDriverRegFile, [FIniFileName]);
      finally
        IniFile.Free;
      end;
    finally
      List.Free;
    end;
    FParamsLoaded := True;
  end;
end;

procedure TSQLConnection.SetLocaleCode(Value: TLocaleCode);
begin
  FParams.Values[SQLLOCALE_CODE_KEY] := IntToHex(Value, 4);
end;

function TSQLConnection.GetLocaleCode: TLocaleCode;
begin
  if FParams.Values[SQLLOCALE_CODE_KEY] <> '' then
    Result := StrToInt(HexDisplayPrefix + FParams.Values[SQLLOCALE_CODE_KEY])
  else
    Result := 0;
end;

procedure TSQLConnection.SetKeepConnection(Value: Boolean);
begin
  if FKeepConnection <> Value then
  begin
    FKeepConnection := Value;
    if not Value and (FRefCount = 0) then Close;
  end;
end;

procedure TSQLConnection.SetParams(Value: TStrings);
begin
  CheckInactive;
  FParams.Assign(Value);
end;

function TSQLConnection.Check(Status: SQLResult): SQLResult;
begin
  if Status <> 0 then SQLError(Status, exceptConnection);
  Result := Status;
end;

procedure TSQLConnection.Loaded;
begin
  inherited Loaded;
end;

procedure TSQLConnection.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
end;

{ TSQLDataLink }

constructor TSQLDataLink.Create(ADataSet: TCustomSQLDataSet);
begin
  inherited Create;
  FSQLDataSet := ADataSet;
end;

procedure TSQLDataLink.ActiveChanged;
begin
  if FSQLDataSet.Active then FSQLDataSet.RefreshParams;
end;

function TSQLDataLink.GetDetailDataSet: TDataSet;
begin
  Result := FSQLDataSet;
end;

procedure TSQLDataLink.RecordChanged(Field: TField);
begin
  if (Field = nil) and FSQLDataSet.Active then FSQLDataSet.RefreshParams;
end;

procedure TSQLDataLink.CheckBrowseMode;
begin
  if FSQLDataSet.Active then FSQLDataSet.CheckBrowseMode;
end;

{ TCustomSQLDataSet }

constructor TCustomSQLDataSet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FParams := TParams.Create(Self);
  FDataLink := TSQLDataLink.Create(Self);
  FIndexDefs := TIndexDefs.Create(Self);
  FParamCheck := True;
  FRecords := -1;
  FParamCount := -1;
  FSchemaInfo.FType := stNoSchema;
  SetUniDirectional(True);
  ObjectView := False;
end;

destructor TCustomSQLDataSet.Destroy;
begin
  Close;
  if Assigned(FSQLCursor) then FreeCursor;
  if Assigned(FSQLCommand) then FreeStatement;
  FreeAndNil(FParams);
  FreeAndNil(FIndexDefs);
  SetConnection(nil);
  FreeProcParams(FProcParams);
  inherited Destroy;
  FDataLink.Free;
  FreeBuffers;
end;

{ connection management }

procedure TCustomSQLDataSet.CheckConnection(eFlag: eConnectFlag);
begin
  if (FSQLConnection <> nil) then
    FSQLConnection.CheckConnection(eFlag)
  else if (eFlag in [eConnect, eReconnect ]) then
    DatabaseError(SMissingSQLConnection);
end;

procedure TCustomSQLDataSet.SetConnection(const Value: TSQLConnection);
begin
  CheckInactive;
  if Assigned(FSQLConnection) then
    FSQLConnection.UnRegisterClient(Self);
  FSQLConnection := Value;
  if Assigned(FSQLConnection) then
  begin
    FSQLConnection.RegisterClient(Self,nil);
    if FMaxBlobSize = 0 then   // means it hasn't been changed 
    begin
      if FSQLConnection.Params.Values[MAXBLOBSIZE_KEY] <> '' then
      try
        FMaxBlobSize := StrToInt(trim(FSQLConnection.Params.Values[MAXBLOBSIZE_KEY]));
      except
        FMaxBlobSize := DefaultMaxBlobSize;
      end else
        FMaxBlobSize := DefaultMaxBlobSize;
    end;
  end;
end;

function TCustomSQLDataSet.GetInternalConnection: TSQLConnection;
begin
  if Assigned(FClonedConnection) then
    Result := FClonedConnection
  else
    Result := FSQLConnection;
end;

{ Error Handling routine }

procedure TCustomSQLDataSet.SQLError(OpStatus: SQLResult; eType: TSQLExceptionType);
var
  ExceptionMessage: string;
  Message: PChar;
  Status: SQLResult;
  MessageLen: SmallInt;
begin
  Status := SQL_NULL_DATA;
  ExceptionMessage := SErrorMappingError;
  Message := nil;
  if (OpStatus > 0) and (OpStatus <=  DBX_MAXSTATICERRORS) then
    ExceptionMessage := DbxError[ OpStatus ]
  else if (OpStatus > 0) and (OpStatus < MaxReservedStaticErrors) then
    ExceptionMessage := SDBXUNKNOWNERROR
  else 
    begin
      case eType of
      exceptUseLast:
        Status := DBXERR_OUTOFRANGE;
      exceptCursor:
        begin
          Status := FSQLCursor.getErrorMessageLen(MessageLen);
          if (Status = SQL_SUCCESS) and (MessageLen > 0) then
          begin
            Message := AllocMem(MessageLen + 1);
            Status := FSQLCursor.getErrorMessage(Message);
          end;
        end;
      exceptCommand:
        begin
          Status := FSQLCommand.getErrorMessageLen(MessageLen);
          if (Status = SQL_SUCCESS) and (MessageLen > 0) then
          begin
            Message := AllocMem(MessageLen + 1);
            Status := FSQLCommand.getErrorMessage(Message);
          end;
        end;
      end;
      if Status = SQL_SUCCESS then
        begin
          if MessageLen > 0 then
            SetString(ExceptionMessage, Message, StrLen(Message))
          else
            ExceptionMessage := SErrorMappingError; 
        end
      else if LastError <> '' then
        ExceptionMessage := LastError;
      if Assigned(Message) then
        FreeMem(Message);
      if ExceptionMessage = '' then
        ExceptionMessage := LastError;
    end;
  FLastError := ExceptionMessage;
  DatabaseError(ExceptionMessage);
end;

{ open/close Cursors and Statements }

procedure TCustomSQLDataSet.GetObjectTypeNames(Fields: TFields);
var
  Len: SmallInt;
  I: Integer;
  TypeDesc: ObjTypeDesc;
  ObjectField: TObjectField;
begin
  for I := 0 to Fields.Count - 1 do
  begin
    if Fields[I] is TObjectField then
    begin
      ObjectField := TObjectField(Fields[I]);
      TypeDesc.iFldNum := ObjectField.FieldNo;
      if (FSQLCursor.getOption(eCurObjectTypeName, @TypeDesc,
        SizeOf(TypeDesc), Len) = SQL_SUCCESS) then
        ObjectField.ObjectType := TypeDesc.szTypeName;
//        SizeOf(TypeDesc), Len) = SQL_SUCCESS) and (Len > 0) then
      with ObjectField do
        if DataType in [ftADT, ftArray] then
        begin
          if (DataType = ftArray) and SparseArrays and
             (Fields[0].DataType = ftADT) then
            GetObjectTypeNames(TObjectField(Fields[0]).Fields) else
            GetObjectTypeNames(Fields);
        end;
    end;
  end;
end;

procedure TCustomSQLDataSet.InternalOpen;
begin
  ExecuteStatement;
  if not Assigned(FSQLCursor) then
    DataBaseError(SNoCursor,Self);
  FieldDefs.Update;
  if DefaultFields then CreateFields;
  BindFields(True);
  if ObjectView then GetObjectTypeNames(Fields);
  InitBuffers;
end;

function TCustomSQLDataSet.IsCursorOpen: Boolean;
begin
  Result := (FSQLCursor <> nil);
end;

procedure TCustomSQLDataSet.OpenCursor(InfoQuery: Boolean);
begin
  if (SchemaInfo.FType = stNoSchema) and (FCommandText = '') then
    DatabaseError(SNoSQLStatement);
  CheckConnection(eConnect);
  SetPrepared(True);
  CheckPrepareError;
  if FDataLink.DataSource <> nil then
     SetParamsFromCursor;
  inherited OpenCursor;
end;

procedure TCustomSQLDataSet.CloseCursor;
begin
  inherited CloseCursor;
end;

procedure TCustomSQLDataSet.FreeCursor;
begin
  if Assigned(FSQLCursor) then
  begin
    FSQLCursor := nil;
    FStatementOpen := False;   // Releasing Cursor closes associated statement
  end;
end;

procedure TCustomSQLDataSet.FreeStatement;
begin
  if Assigned(FSQLCommand) then
  begin
    CloseStatement;
    FSQLCommand := nil;
    if Assigned(FSQLConnection) then
    begin
      if Assigned(FClonedConnection) then
        FreeAndNil(FClonedConnection)
      else
        Dec(FSQLConnection.FActiveStatements);
    end;
    FPrepared := False;
    FParamCount := -1;
  end else if FSchemaInfo.FType <> stNoSchema then
  begin
    if Assigned(FClonedConnection) then
      FreeAndNil(FClonedConnection)
    else
      Dec(FSQLConnection.FActiveStatements);
  end;
  if Assigned(FieldDefs) then
    FieldDefs.Updated := False;
  ClearIndexDefs;
end;

procedure TCustomSQLDataSet.CloseStatement;
begin
  FParamCount := -1;
  if Assigned(FSQLCommand) and FStatementOpen then
    FSQLCommand.Close;
end;

procedure TCustomSQLDataSet.InternalClose;
var
  DetailList: TList;
  I: Integer;
begin
  BindFields(False);
  if DefaultFields then DestroyFields;
  FreeBuffers;
  DetailList := TList.Create;
  try
    GetDetailDataSets(DetailList);
    for I := 0 to DetailList.Count -1 do
    if TDataSet(DetailList[I]) is TCustomSQLDataSet then
    begin
      TCustomSQLDataSet(TDataSet(DetailList[I])).Close;
      TCustomSQLDataSet(TDataSet(DetailList[I])).SetPrepared(False);
    end;
  finally
    DetailList.Free;
  end;
  if Assigned(FSQLConnection) and ((FSQLConnection.KeepConnection) or
     (FSQLConnection.DataSetCount > 1)) then
    FreeCursor
  else
    SetPrepared(False);
end;

procedure TCustomSQLDataSet.Loaded;
begin
  inherited Loaded;
end;

procedure TCustomSQLDataSet.InternalRefresh;
begin
  SetState(dsInactive);
  CloseCursor;
  OpenCursor(False);
  SetState(dsBrowse);
end;

procedure TCustomSQLDataSet.InitBuffers;
begin
  if (MaxBlobSize > 0) then
    SetLength(FBlobBuffer, MaxBlobSize * 1024);
  if (CalcFieldsSize > 0) then
    FCalcFieldsBuffer := AllocMem(CalcFieldsSize);
end;

procedure TCustomSQLDataSet.ClearIndexDefs;
begin
  FIndexDefs.Clear;
  FIndexDefsLoaded := False;
end;

procedure TCustomSQLDataSet.FreeBuffers;
begin
  if FBlobBuffer <> nil then
    SetLength(FBlobBuffer, 0);
  if FCalcFieldsBuffer <> nil then
  begin
    FreeMem(FCalcFieldsBuffer);
    FCalcFieldsBuffer := nil;
  end;
end;

procedure TCustomSQLDataSet.InitRecord(Buffer: PChar);
begin
  { NOP }
end;

procedure TCustomSQLDataSet.SetBufListSize(Value: Integer);
begin
end;

{ Cursor Level Metadata }

procedure TCustomSQLDataSet.AddFieldDesc(FieldDescs: TFieldDescList; DescNo: Integer;
  var FieldID: Integer; RequiredFields: TBits; FieldDefs: TFieldDefs);
const
  ArrayIndex = '[0]';
var
  FType: TFieldType;
  FSize: LongWord;
  FRequired: Boolean;
  FPrecision, I: Integer;
  FieldName, FName: string;
  FieldDesc: FLDDesc;
  FldDef: TFieldDef;
begin
  FieldDesc := FieldDescs[DescNo];
  with FieldDesc do
  begin
    SetString(FieldName, szName, StrLen(szName));
    FName := FieldName;
    I := 0;
    while FieldDefs.IndexOf(FName) >= 0 do
    begin
      Inc(I);
      FName := Format('%s_%d', [FieldName, I]);
    end;
    if iFldType < MAXLOGFLDTYPES then
      FType := DataTypeMap[iFldType]
    else
      FType := ftUnknown;
    if iFldType in [fldFMTBCD, fldBCD] then
    begin
      iUnits2 := Abs(iUnits2);
      if iUnits1 < iUnits2 then   // iUnits1 indicates Oracle 'usable decimals'
        iUnits1 := iUnits2;
      // ftBCD supports only up to 18-4.  If Prec > 14 or Scale > 4, make FMTBcd
      if (iUnits1 > (MaxBcdPrecision-4)) or (iUnits2 > MaxBcdScale) then
      begin
        FType := ftFMTBcd;
        iFldType := fldFMTBCD;
        if (iUnits1 = 38) and (iUnits2 in [0,38]) then
        begin
          iUnits1 := 32;
          iUnits2 := 8;
        end;
        if iUnits1 > MaxFMTBcdDigits then
          iUnits1 := MaxFMTBcdDigits;
      end;
    end;
    FSize := 0;
    FPrecision := 0;
    if RequiredFields.Size > FieldID then
      FRequired := RequiredFields[FieldID] else
      FRequired := False;
    case iFldType of
      fldZSTRING, fldBYTES, fldVARBYTES, fldRef:
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
      fldFMTBCD, fldBCD:
        begin
          FSize := Abs(iUnits2);
          FPrecision := iUnits1;
        end;
      fldADT, fldARRAY:
        begin
          FSize := iUnits2;
          FPrecision := iUnits1;
        end;
      fldBLOB:
        begin
          FSize := iUnits1;
          if (iSubType >= fldstMEMO) and (iSubType <= fldstBFILE) then
            FType := BlobTypeMap[iSubType];
        end;
    end;
    FldDef := FieldDefs.AddFieldDef;
    with FldDef do
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
            for I := 1 to iUnits1 do
            begin
              LoadFieldDef(Word(FieldNo + I), FieldDescs[1]);
              AddFieldDesc(FieldDescs, 1, FieldID, RequiredFields, ChildDefs);
            end;
          end;
        ftArray:
          begin
            for I := 1 to iUnits1 do
            begin
              LoadFieldDef(Word(FieldNo + I), FieldDescs[1]);
              StrCat(StrLCopy(FieldDescs[1].szName, FieldDesc.szName, 
                     SizeOf(FieldDesc.szName) - Length(ArrayIndex)), ArrayIndex);
              AddFieldDesc(FieldDescs, 1, FieldID, RequiredFields, ChildDefs);
            end;
          end;
      end;
    end;
  end;
end;

procedure TCustomSQLDataSet.LoadFieldDef(FieldID: Word; var FldDesc: FLDDesc);
var
  ReadOnly: LongBool;
begin
  FldDesc.iFldNum := FieldID;
  FSQLCursor.getColumnName(FieldId, FldDesc.szName);
  FSQLCursor.getColumnType(FieldId, FldDesc.iFldType, FldDesc.iSubtype);
  FSQLCursor.getColumnLength(FieldId, FldDesc.iLen);
  FSQLCursor.getColumnPrecision(FieldId, FldDesc.iUnits1);
  FSQLCursor.getColumnScale(FieldId, FldDesc.iUnits2);
  FSQLCursor.isReadOnly(FieldID, ReadOnly);
  if ReadOnly then
    FldDesc.efldrRights := fldrREADONLY;
end;

procedure TCustomSQLDataSet.InternalInitFieldDefs;
var
  FID: Integer;
  FieldDescs: TFieldDescList;
  RequiredFields: TBits;
  Nullable: LongBool;
  FldDescCount: Word;
begin
  if (FSQLCursor <> nil) then
  begin
    RequiredFields := TBits.Create;
    try
      FSQLCursor.getColumnCount(FldDescCount);
      SetLength(FieldDescs, FldDescCount);
      RequiredFields.Size := FldDescCount + 1;
      FieldDefs.Clear;
      FID := 1;
      FMaxColSize := FldDescCount;
      while FID <= FldDescCount do
      begin
        FSQLCursor.IsNullable(Word(FID), Nullable);
        RequiredFields[FID] := Nullable = False;
        LoadFieldDef(Word(FID), FieldDescs[0]);
        if (FieldDescs[0].iLen > FMaxColSize) and 
           (FieldDescs[0].iFldType <> fldBLOB) then
          FMaxColSize := (FMaxColSize + FieldDescs[0].iLen);
        AddFieldDesc(FieldDescs, Integer(0), FID, RequiredFields, FieldDefs);
      end;
    finally
      RequiredFields.Free;
    end;
  end
  else
     DatabaseError(SDataSetClosed, self);
end;

{ Field and Record Access }

procedure NormalizeBcdData(BcdData: PBcd; Precision, Scale: Word);
var
  ABcd: TBcd;
  Success: Boolean;
begin
  if Assigned(BcdData) then
  begin
    if Precision > MaxFMTBcdDigits then Precision := MaxFMTBcdDigits;
    if (BcdData.SignSpecialPlaces = 38) and ((Scale and 63)in [38,0]) then
    begin
      if (Scale and (1 shl 7)) <> 0 then
        Success := NormalizeBcd( BcdData^, ABcd, MaxFMTBcdDigits, Word((DefaultFMTBcdScale and 63) or (1 shl 7)))
      else
        Success := NormalizeBcd( BcdData^, ABcd, MaxFMTBcdDigits, DefaultFMTBcdScale);
    end else
      Success := NormalizeBcd( BcdData^, ABcd, Precision, Scale);
    if Success then
      BcdData^ := ABcd
    else
      DatabaseError(SBcdOverflow);
 end;
end;

function TCustomSQLDataSet.GetFieldData(FieldNo: Integer; Buffer: Pointer): Boolean;
var
  FldType, Subtype: Word;
  Status: SQLResult;
  FBlank: LongBool;
  Field: TField;
  Precision, Scale: Word;
begin
  Result := False;
  if (FSQLCursor = nil) then
    DatabaseError(SDataSetClosed, self);
  if EOF = True then
    Exit;
  FBlank := True;
  Status := FSQLCursor.getColumnType(FieldNo, FldType, SubType);
  if (Status = 0) then
  begin
    case FldType of
      fldZSTRING:
        Status := FSQLCursor.GetString(FieldNo, Buffer, FBlank);
      fldINT16, fldUINT16:
        Status := FSQLCursor.GetShort(FieldNo, Buffer, FBlank);
      fldINT32, fldUINT32:
        Status := FSQLCursor.GetLong(FieldNo, Buffer, FBlank);
      fldFLOAT:
        Status := FSQLCursor.GetDouble(FieldNo, Buffer, FBlank);
      fldFMTBCD, fldBCD:
        begin
          Status := FSQLCursor.GetBcd(FieldNo, Buffer, FBlank);
          Field := FieldByNumber(FieldNo);
          if (not FBlank) and (Status = SQL_SUCCESS) and (Field <> nil) then
          begin
            if Field.DataType = ftBcd then
            begin
              Precision := TBcdField(Field).Precision;
              Scale := TBcdField(Field).Size;
            end else
            begin
              Precision := TFMTBcdField(Field).Precision;
              Scale := TFMTBcdField(Field).Size;
            end;
            NormalizeBcdData(PBcd(Buffer), Precision, Scale);
          end;
        end;
      fldDATE:
        Status := FSQLCursor.GetDate(FieldNo, Buffer, FBlank);
      fldTIME:
        Status := FSQLCursor.GetTime(FieldNo, Buffer, FBlank);
      fldDATETIME:
        Status := FSQLCursor.GetTimeStamp(FieldNo, Buffer, FBlank);
      fldBOOL:
        Status := FSQLCursor.GetShort(FieldNo, Buffer, FBlank);
      fldBYTES, fldVARBYTES:
        Status := FSQLCursor.GetBytes(FieldNo, Buffer, FBlank);
      fldBLOB:
        begin
          GetBlobSize(Self, FieldNo);
          if CurrentBlobSize = 0 then
            FBlank := True
          else
            Status := FSQLCursor.GetBlob(FieldNo, Buffer, FBlank, CurrentBlobSize);
        end;
    end;
  end;
  Check(Status);
  Result := not FBlank;
end;

function TCustomSQLDataSet.GetFieldData(Field: TField; Buffer: Pointer): Boolean;
var
   FieldNo: Word;
   TempBuffer: PChar;
   ThisBuffer: Pointer;
   BlobSize: LongWord;
   BlobNull: LongBool;
begin
  if not Self.Active then
    DataBaseError(SDatasetClosed);
  FieldNo := Field.FieldNo;
  if not Assigned(Buffer) then
  begin
    if Field.IsBlob then
    begin
      if EOF then
        BlobNull := True
      else
        FSQLCursor.GetBlobSize(Word(FieldNo), BlobSize, BlobNull);
      Result := not Boolean(BlobNull);
      Exit;
    end
    else if Field.Size > Field.DataSize then
      TempBuffer := AllocMem(Field.Size)
    else
      TempBuffer := AllocMem(Field.DataSize);
    ThisBuffer := Pointer(TempBuffer);
  end else
  begin
    ThisBuffer := Buffer;
    TempBuffer := nil;
  end;
  try
    if Field.FieldNo < 1 then
      Result := GetCalculatedField(Field, ThisBuffer)
    else
      Result := GetFieldData(FieldNo, ThisBuffer);
  finally
    if Assigned(TempBuffer) then
      FreeMem(TempBuffer);
  end;
end;

procedure TCustomSQLDataSet.SetCurrentBlobSize(Value: LongWord);
begin
  FCurrentBlobSize := Value;
  SetLength(FBlobBuffer, FCurrentBlobSize);
end;

function TCustomSQLDataSet.GetBlobFieldData(FieldNo: Integer; var Buffer: TBlobByteData): Integer;
var
  IsNull: LongBool;
  FldType, SubType: Word;
begin
  Result := 0;
  GetBlobSize(Self, FieldNo);
  if (FSQLCursor = nil) then
    DatabaseError(SDataSetClosed, self);
  if FCurrentBlobSize > 0 then
  begin
    Check(FSQLCursor.getColumnType(LongWord(FieldNo), FldType, SubType));
    if LongWord(Length(Buffer)) < CurrentBlobSize then
      SetLength(Buffer, CurrentBlobSize);
    if FCurrentBlobSize = 0 then
      Result := 0
    else 
      Check(FSQLCursor.GetBlob(LongWord(FieldNo), PChar(Buffer), IsNull, FCurrentBlobSize));
  end;
  if not IsNull then Result := CurrentBlobSize;
end;

function TCustomSQLDataSet.CreateBlobStream(Field: TField; Mode: TBlobStreamMode): TStream;
begin
  Result := TSQLBlobStream.Create(Field as TBlobField, Mode);
end;

procedure TCustomSQLDataSet.SetFieldData(Field: TField; Buffer: Pointer);
var
  RecBuf: PChar;
begin
  RecBuf := FCalcFieldsBuffer;
  with Field do
  begin
    if FieldNo < 1 then   //{fkCalculated}
    begin
      Inc(RecBuf, Offset);
      Boolean(RecBuf[0]) := LongBool(Buffer);
      if Boolean(RecBuf[0]) then Move(Buffer^, RecBuf[1], DataSize);
    end;
  end;
end;

function TCustomSQLDataSet.GetCalculatedField(Field: TField; var Buffer: Pointer): Boolean;
var
  RecBuf: PChar;
begin
  Result := False;
  RecBuf := FCalcFieldsBuffer;
  with Field do
  begin
    if FieldNo < 1 then   //{fkCalculated}
    begin
      Inc(RecBuf, Offset);
      if Boolean(RecBuf[0]) then
      begin
        Move(RecBuf[1], Buffer^, DataSize);
        Result := True;
      end;
    end;
  end;
end;

function TCustomSQLDataSet.GetCanModify: Boolean;
begin
  Result := False;
end;

function TCustomSQLDataSet.GetRecord(Buffer: PChar; GetMode: TGetMode; DoCheck: Boolean): TGetResult; 
var
  Status: SQLResult;
begin
  Status := FSQLCursor.next;
  if (not Status in [SQL_SUCCESS, SQL_NULL_DATA, SQL_ERROR_EOF]) then
     Check(Status);
  if Status = SQL_SUCCESS then
  begin
    GetCalcFields(FCalcFieldsBuffer);
    Result := grOK
  end
  else
    Result := grEOF;
end;

{ CommandText Management }

procedure TCustomSQLDataSet.SetFCommandText(const Value: string);
begin
  CheckInactive;
  FCommandText := Value;
  FNativeCommand := '';
end;

procedure TCustomSQLDataSet.SetCommandText(const Value: string);
var
  HasDataLink: Boolean;
  DataSet: TDataSet;
begin
  if FCommandText <> Value then
  begin
    CheckInactive;
    PropertyChanged;
    FCommandText := TrimLeft(Value);
    if (SQLConnection <> nil) and (Value <> '') then
    begin
      if FParamCheck and (FCommandType <> ctTable) then
      begin
        HasDataLink := (FDataLink.DataSource <> nil) and (FDataLink.DataSource.DataSet is TCustomSQLDataSet);
        if HasDataLink then
          DataSet := FDataLink.DataSource.DataSet
        else
          DataSet := nil;
        SetParamsFromSQL(DataSet, not HasDataLink);
      end;
    end;
    DataEvent(dePropertyChange, 0);
  end;
end;

function TCustomSQLDataSet.GetDataSetFromSQL(TableName: string): TCustomSQLDataSet;
var
  Q: string;
begin
  if TableName = '' then
    TableName := GetTableNameFromSQL(SSelectStarFrom +
              Copy(CommandText, 8, Length(CommandText) - 7));
  if TableName = '' then
    Result := nil
  else
  begin
    Result := TCustomSQLDataSet.Create(nil);
    try
      Result.SetConnection(Self.SQLConnection);
      Q := Self.FSqlConnection.GetQuoteChar;
      Result.CommandText := SSelectStarFrom +
                  Q + TableName + Q +
                  SWhere + ' 0 = 1';    // only metadata is needed
      Result.Active := True;
    except
      FreeAndNil(Result);
    end;
  end;
end;

{ Parameters }

function TCustomSQLDataSet.GetProcParams: TList;
begin
  if (Self.FSQLConnection.Connected) and not Assigned(FProcParams) then
  begin
    FProcParams := TList.Create;
    FSQLConnection.GetProcedureParams(CommandText, FProcParams);
  end;
  Result := FProcParams;
end;

procedure TCustomSQLDataSet.SetParamsFromProcedure;
var
  List: TParams;
begin
  List := TParams.Create;
  try
    try
      { Preserve existing values }
      List.AssignValues(Params);
      if Assigned(FProcParams) then
        FreeProcParams(FProcParams);
      ProcParams := TList.Create;
      FSQLConnection.GetProcedureParams(CommandText, ProcParams);
      LoadParamListItems(List, FProcParams);
    except
      FreeProcParams(FProcParams);
    end;  
    if List.Count > 0 then
      Params.Assign(List);
  finally
    List.Free;
  end;
end;

procedure TCustomSQLDataSet.SetParamsFromSQL(DataSet: TDataSet; bFromFields: Boolean);
var
  Field: TField;
  I: Integer;
  List: TSQLParams;
  WasDatasetActive: Boolean;
  FTblName: string;
  DSCreated: Boolean;
begin
  DSCreated := False;
  FNativeCommand := Copy(CommandText, 1, Length(CommandText));
  if (CommandType = ctStoredProc) then
  begin
    SetParamsFromProcedure;
    Exit;
  end;
  List := TSQLParams.Create(Self);
  try                                              // DBExpress only supports '?', so
    FTblName := List.Parse(FNativeCommand, True);  // save query to avoid
    { Preserve existing values }                   // parsing again with prepare
    List.AssignValues(Params);
    if (Assigned(SQLConnection)) and (List.Count > 0) then 
      begin
        WasDataSetActive := True;
        if DataSet = nil then
        begin
          if FTblName <> '' then
          begin
            if csDesigning in ComponentState then
            begin
              DataSet := GetDataSetFromSQL(FTblName);
              if Assigned(DataSet) then
                DSCreated := True;
            end;
          end;
        end else begin
          WasDataSetActive := DataSet.Active;
          if not DataSet.Active then DataSet.Active := True;
        end;
        for I := 0 to List.Count - 1 do
          List[I].ParamType := ptInput;
        if (DataSet <> nil) and
              ((not List.BindAllFields) or
              (List.Count = DataSet.FieldCount)) then
          try
            for I := 0 to List.Count - 1 do
            begin
              if List.BindAllFields then
                Field := DataSet.Fields[I]
              else if List.FFieldName.Count > I then
              begin
                if (bFromFields) then
                  Field := DataSet.FieldByName(List.GetFieldName(I))
                else
                  Field := DataSet.FieldByName(List[I].Name);
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
            // ignore exception: Column type won't be provided
          end;
        if List.Count > 0 then
          Params.Assign(List);
        if Assigned(DataSet) and (not WasDataSetActive) then DataSet.Active := False;
      end
    else
      Params.clear;
  finally
    List.Free;
    if DSCreated then DataSet.Free;
  end;
end;

procedure TCustomSQLDataSet.RefreshParams;
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

procedure TCustomSQLDataSet.SetParamsFromCursor;
var
  I: Integer;
  DataSet: TDataSet;
begin
  if (FDataLink.DataSource <> nil) and (FParams.Count > 0) then
  begin
    DataSet := FDataLink.DataSource.DataSet;
    if DataSet <> nil then
    begin
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

function TCustomSQLDataSet.ParamByName(const Value: string): TParam;
begin
  Result := FParams.ParamByName(Value);
end;

procedure TCustomSQLDataSet.GetOutputParams(AProcParams: TList);
var
  I: Integer;
  RecBuffer: PChar;
  ArgDesc: SPParamDesc;
  IsNull: Integer;
begin
  for I := 0 to Params.Count - 1 do
  begin
    isNull := 0;
    ArgDesc := (PSPParamDesc(AProcParams.Items[I]))^;
    if (Params[I].ParamType in [ptOutput, ptResult, ptInputOutput]) and
       (ArgDesc.iDataType <> ftCursor) then
    begin
      RecBuffer := AllocMem(Params[I].Size + 1);
      try
        Check(FSQLCommand.getParameter(i+1, 0, RecBuffer, Params[I].Size, IsNull));
        if IsNull = 1 then
          Params[I].Value := Null
        else
          Params[I].SetData(RecBuffer);
      finally
        FreeMem(RecBuffer);
      end;
    end;
  end;
end;

procedure TCustomSQLDataSet.SetParameters(const Value: TParams);
begin
  FParams.AssignValues(Value);
end;

{ Query Management }

procedure TCustomSQLDataSet.SetPrepared(Value: Boolean);
begin
  if Value then CheckConnection(eConnect);
  if FGetNextRecordSet then
    FPrepared := Value
  else
    FreeCursor;
  if SchemaInfo.FType <> stNoSchema then
  begin
    if Value then
      CheckStatement(True)
    else
      FreeStatement;
  end else if Value <> Prepared then
  begin
    try
      if Value then
        begin
          if FSQLCommand <> nil then DatabaseError(SSQLDataSetOpen, Self);
          FRowsAffected := -1;
          FCheckRowsAffected := True;
          PrepareStatement
        end
      else
        begin
          if FCheckRowsAffected then
            FRowsAffected := RowsAffected;
          FreeStatement;
          if Assigned(FSQLConnection) then
            FSQLConnection.CheckDisconnect;
        end;
      FPrepared := Value;
    except
      if Assigned(FSQLCommand) then
        FreeStatement;
      FPrepared := False;
    end;
  end;
end;

procedure TCustomSQLDataSet.CheckStatement(ForSchema: Boolean = False);
var
  Connection: TSqlConnection;
  RowsetSize: Integer;
begin
  FLastError := '';
  RowsetSize := defaultRowsetSize;
  if not Assigned(FSQLConnection) then
    DatabaseError(SMissingSQLConnection);
  Connection := FSQLConnection.GetConnectionForStatement;
  if Connection.FIsCloned then
    FClonedConnection := Connection;
  if Connection.LoadParamsOnConnect then
    Connection.LoadParamsFromIniFile;
  if Assigned(FSQLCommand) then
    FreeStatement;
  if not Assigned(Connection.Connection) then
    DatabaseError(SdatabaseOpen, Self);
  Inc(Connection.FActiveStatements);
  if not ForSchema then
  begin
    if Length(FCommandText) = 0 then
      DatabaseError(SEmptySQLStatement, Self);
    Check(Connection.Connection.getSQLCommand(FSQLCommand));

    if FSQLConnection.Params.Values[ROWSETSIZE_KEY] <> '' then
    try
      RowsetSize := StrToInt(trim(FSQLConnection.Params.Values[ROWSETSIZE_KEY]));
    except
      RowsetSize := defaultRowsetSize;
    end;

    FSQLCommand.setOption(eCommRowsetSize, RowsetSize);

    FStatementOpen := True;
    if FTransactionLevel > 0 then
      FSQLCommand.SetOption(eCommTransactionID, Integer(FTransactionLevel));
    if FNativeCommand = '' then
    begin
      if FParams.Count > 0 then
        FNativeCommand := FixParams(CommandText, FParams.Count, Connection.GetQuoteChar)
      else
        FNativeCommand := CommandText;
    end;
  end;
end;

function TCustomSQLDataSet.GetQueryFromType: string;
begin
  case CommandType of
     ctTable:
       begin
         if FSortFieldNames > '' then
           Result := SSelectStarFrom + AddQuoteCharToObjectName(FCommandText, 
                  FSQLConnection.QuoteChar) + SOrderBy + FSortFieldNames
         else
           if FNativeCommand = '' then
             Result := SSelectStarFrom + AddQuoteCharToObjectName(FCommandText, 
                    FSQLConnection.QuoteChar)
           else
             Result := SSelectStarFrom + AddQuoteCharToObjectName(FNativeCommand,
                    FSQLConnection.QuoteChar);
       end;
     ctStoredProc:
         Result := copy(FCommandText, 1, Length(FCommandText));
     else
       if (FSortFieldNames > '') and (Pos(SOrderBy, 
          LowerCase(FCommandText)) = 0) then
         Result := FNativeCommand + SOrderBy + FSortFieldNames
       else
         Result := FNativeCommand;
  end;
end;

function TCustomSQLDataSet.CheckDetail(SQL: string): string;
begin
  Result := SQL;
  if pos(SParam, SQL) = 0 then
    if pos(SSelect, LowerCase(SQL)) > 0 then // Select Query with no ?, but Parameters are set 
      Result := AddParamSQLForDetail(Params, SQL, True);
end;

procedure TCustomSQLDataSet.PrepareStatement;
var
  SQLText: string;
begin
  if Length(CommandText) = 0 then
    DatabaseError(SEmptySQLStatement, Self);
  CheckStatement;
  SQLText := GetQueryFromType;
  if Params.Count > 0 then
    SQLText := CheckDetail(SQLText);
  if CommandType = ctStoredProc then
    Check(FSQLCommand.SetOption(eCommStoredProc, Integer(True)));
  Check(FSQLCommand.prepare(PChar(SQLText), ParamCount));
end;

procedure TCustomSQLDataSet.CheckPrepareError;
begin
  if (FSQLCommand = nil) and (SchemaInfo.FType = stNoSchema) then
  begin     // prepare has failed
    if FLastError <> '' then     
      SQLError(0, exceptUseLast)
    else if (CommandType = ctQuery) or (SortFieldNames <> '') then
      DatabaseError(sPrepareError)
    else
      DatabaseError(sObjectNameError);
  end;
end;

function TCustomSQLDataSet.ExecSQL(ExecDirect: Boolean = False): Integer;
begin
  CheckInActive;
  CheckConnection(eConnect);
  try
    FRowsAffected := 0;
    if not ExecDirect then
    begin
      SetPrepared(True);
      CheckPrepareError;
      ExecuteStatement;
    end else
    begin
      CheckStatement;
      Check(FSQLCommand.executeImmediate(PChar(CommandText), FSQLCursor));
    end;    
    if FSQLCursor <> nil then
       SetParamsFromCursor;
    Result := RowsAffected;
  finally
    if Assigned(FSQLCursor) then
    begin
      FreeCursor;
      FreeStatement;
    end else if ExecDirect then
      FreeStatement
    else
      CloseStatement;  
  end;
end;

procedure TCustomSQLDataSet.ExecuteStatement;
var
  Status: SQLResult;
begin
  if SchemaInfo.FType = stNoSchema then
    begin
      if Assigned(FParams) and not FGetNextRecordSet then
      begin
        if CommandType = ctStoredProc then
          SetProcedureParams(Self.FSQLConnection, FSQLCommand, Params, ProcParams)
        else
        if (FParams.Count > 0) then
          SetQueryParams(Self.FSQLConnection, FSQLCommand, Params);
      end;
      if FGetNextRecordSet then
      begin
        Status := FSQLCommand.getNextCursor(FSQLCursor);
        if not (Status in [SQL_SUCCESS, SQL_NULL_DATA]) then
          Check(Status);
        if Status <> SQL_SUCCESS then
          Active := False
        else if Params.Count > 0 then
          GetOutputParams(FProcParams);
      end else
      begin
        Check(FSQLCommand.execute(FSQLCursor));
        if (CommandType = ctStoredProc) and (Params.Count > 0) then
          GetOutputParams(FProcParams);
      end;
    end 
  else
    OpenSchema;
  FStatementOpen := True;
  FRecords := -1;
end;

function TCustomSQLDataSet.GetObjectProcParamCount: Integer;
var
  I, LastParamNum: Integer;
  ArgDesc: SPParamDesc;
begin
  GetProcParams;    // make sure FProcParams is loaded.
  Result := 0;
  LastParamNum := 0;
  for I := 0 to Params.Count -1 do
  begin
    ArgDesc := (PSPParamDesc(ProcParams.Items[I]))^;
    if ArgDesc.iParamNum <> LastParamNum then Inc(Result);
    LastParamNum := ArgDesc.iParamNum;
  end;
end;

function TCustomSQLDataSet.GetParamCount: Integer;
var
  I : Integer;
begin
  Result := FParamCount;
  if Result = -1 then
  begin
    Result := 0;
    if Assigned(FParams) then
    begin
      if FCommandType = ctStoredProc then
      begin
        for I := 0 to Params.Count -1 do
        begin
          if Params.Items[I].DataType in [ftADT, ftARRAY] then
          begin
            Result := GetObjectProcParamCount;
            break;
          end;  
        end;
      end;
      if Result = 0 then Result := FParams.Count
    end;
  end;
end;

function GetRows(Query: string; Connection: TSQLConnection): Integer;
var
  DS: TSQLDataSet;
begin
  Result := -1;
  DS := TSQLDataSet.Create(nil);
  try
    DS.SQLConnection := Connection;
    DS.CommandText := Query;
    DS.Active := True;
    if not DS.EOF then
      Result := DS.Fields[0].AsInteger;
  finally
    if Result = -1 then
      DatabaseError(SNotSupported);
    DS.Free;
  end;
end;

function TCustomSQLDataSet.GetRecordCount: Integer;
const
  SDistinct = ' distinct ';                 { do not localize }
  SSelectCount = 'select count(*) from ';   { do not localize }
var
  TableName, Query: string;
  HoldPos: Integer;
begin
  if FRecords <> -1 then 
    Result := FRecords
  else
  begin
    CheckConnection(eConnect);
    if Self.CommandText = '' then
      DatabaseError(SNoSQLStatement);
    case CommandType of
      ctStoredProc:
        DatabaseError(SNotSupported);
      ctTable:
        Query := 'select count(*) from ' + GetQuoteChar + FCommandText + GetQuoteChar;
      ctQuery:
        begin
          TableName := GetTableNameFromSQL(FCommandText);
          if (TableName = '') or (Params.Count > 0) then
            DatabaseError(SNotSupported);
          if Pos(SDistinct, LowerCase(FCommandText)) = 0 then
            Query := SSelectCount
          else
            DatabaseError(SNotSupported);
          HoldPos := Pos(SWhere, LowerCase(FCommandText));
          if HoldPos = 0 then
            Query := Query + GetQuoteChar + TableName + GetQuoteChar
          else begin
            Query := Query + GetQuoteChar + TableName + GetQuoteChar + copy(FCommandText, HoldPos, Length(FCommandText) - (HoldPos-1));
            HoldPos := Pos(sOrderBy, LowerCase(Query));
            if HoldPos > 0 then
              Query := copy(Query, 1, HoldPos - 1);
          end;
        end;
    end;
    FRecords := GetRows(Query, FSQLConnection);
    Result := FRecords;
  end;
end;

function TCustomSQLDataSet.GetRowsAffected: Integer;
var
  UpdateCount: LongWord;
begin
  if FRowsAffected > 0 then
    Result := Integer(FRowsAffected)
  else
    begin
      if FSQLCommand <> nil then
        Check(FSQLCommand.getRowsAffected(UpdateCount))
      else
        UpdateCount := 0;
      FRowsAffected := Integer(UpdateCount);
      Result := Integer(UpdateCount);
    end;
end;

{ Misc. Set/Get Property }

procedure TCustomSQLDataSet.SetDataSource(Value: TDataSource);
begin
  if IsLinkedTo(Value) then DatabaseError(SCircularDataLink, Self);
  if FDataLink.DataSource <> Value then
    FDataLink.DataSource := Value;
end;

function TCustomSQLDataSet.GetDataSource: TDataSource;
begin
  Result := FDataLink.DataSource;
end;

procedure TCustomSQLDataSet.GetDetailLinkFields(MasterFields, DetailFields: TList);

  function AddFieldToList(const FieldName: string; DataSet: TDataSet;
    List: TList): Boolean;
  var
    Field: TField;
  begin
    Field := DataSet.FindField(FieldName);
    if Field <> nil then
      List.Add(Field);
    Result := Field <> nil;
  end;

var
  I: Integer;
begin
  MasterFields.Clear;
  DetailFields.Clear;
  if (DataSource <> nil) and (DataSource.DataSet <> nil) then
    for I := 0 to Params.Count - 1 do
      if AddFieldToList(Params[I].Name, DataSource.DataSet, MasterFields) then
        AddFieldToList(Params[I].Name, Self, DetailFields);
end;

function TCustomSQLDataSet.GetSortFieldNames: string;
begin
  Result := FSortFieldNames;
end;

procedure TCustomSQLDataSet.SetSortFieldNames(Value: string);
begin
  FSortFieldNames := Value;
end;

procedure TCustomSQLDataSet.SetMaxBlobSize(MaxSize: Integer);
begin
  FMaxBlobSize := MaxSize;
  if (FSQLCommand <> nil) then
    FSQLCommand.SetOption(eCommBlobSize, Integer(MaxSize));
end;

procedure TCustomSQLDataSet.SetCommandType(const Value: TSQLCommandType);
begin
  if FCommandType <> Value then
  begin
    CheckInactive;
    FCommandType := Value;
    PropertyChanged;
    DataEvent(dePropertyChange, 0);
  end;
end;

procedure TCustomSQLDataSet.PropertyChanged;
begin
  if not (csLoading in ComponentState) then
  begin
    SetPrepared(False);
    FNativeCommand := '';
    FRecords := -1;
    FreeStatement;
    if SortFieldNames <> '' then
      FSortFieldNames := '';
    if FCommandText <> '' then
      FCommandText := '';
    FParams.Clear;
  end;
end;

{ Miscellaneous }

function TCustomSQLDataSet.IsSequenced: Boolean;
begin
  Result := False;
end;

procedure TCustomSQLDataSet.DefineProperties(Filer: TFiler);

  function DesignerDataStored: Boolean;
  begin
    if Filer.Ancestor <> nil then
      Result := TCustomSQLDataSet(Filer.Ancestor).DesignerData <> DesignerData else
      Result := DesignerData <> '';
  end;

begin
  inherited;
  Filer.DefineProperty('DesignerData', ReadDesignerData, WriteDesignerData,
    DesignerDataStored);
end;

procedure TCustomSQLDataSet.ReadDesignerData(Reader: TReader);
begin
  FDesignerData := Reader.ReadString;
end;

procedure TCustomSQLDataSet.WriteDesignerData(Writer: TWriter);
begin
  Writer.WriteString(FDesignerData);
end;

{ Exception Handling }

function TCustomSQLDataSet.Check(Status: SQLResult): SQLResult;
begin
  if Status <> 0 then SQLError(Status, exceptCommand);
  Result := Status;
end;

procedure TCustomSQLDataSet.InternalHandleException;
begin
end;

{ Index Support }

procedure TCustomSQLDataSet.UpdateIndexDefs;
begin
  AddIndexDefs(Self);
end;

function TCustomSQLDataSet.CheckFieldNames(const FieldNames: string): Boolean;
var
  S: string;
  Pos: Integer;
begin
  Result := True;
  S := FieldNames;
  Pos := 1;
  while Result and (Pos <= Length(S)) do
    Result := FindField(ExtractFieldName(S, Pos)) <> nil;
end;

procedure TCustomSQLDataSet.AddIndexDefs(SourceDS: TCustomSQLDataSet; IndexName: string = '');

  function DontUseIndex: Boolean;
  begin
    Result := CommandType in [ctQuery, ctStoredProc];
    if Result and (CommandType = ctQuery) then
      Result := IsMultiTableQuery(CommandText);
    if Result then FIndexDefsLoaded := True;
  end;
  
const
  IDX_NAME_FIELD = 'INDEX_NAME';           { Do not localize }
  IDX_FLD_FIELD = 'COLUMN_NAME';           { Do not localize }
  IDX_TYPE_FIELD = 'INDEX_TYPE';           { Do not localize }
  IDX_SORT_FIELD = 'SORT_ORDER';           { Do not localize }
  DescendingOrder = 'D';                   { Do not localize }
var
  DataSet: TCustomSQLDataSet;
  TableName, IdxName, SortOrder, FieldNames: string;
  IdxType: Integer;
  Options: TIndexOptions;
  IdxDef: TIndexDef;
begin
  if FNoMetadata then FIndexDefsLoaded := True;
  if FIndexDefsLoaded then Exit;
  if SchemaInfo.FType <> stNoSchema then Exit;
  if DontUseIndex then Exit;
  if FCommandType = ctTable then
    TableName := FCommandText
  else
    TableName := GetTableNameFromSQL(CommandText);
  DataSet := FSQLConnection.OpenSchemaTable(stIndexes, TableName);
  if not Assigned(DataSet) then FSQLConnection.SQLError(SQLResult(-1), exceptMetadata);
  try
    FIndexDefs.Clear;
    IndexDefs.Clear;
    while not DataSet.EOF do
    begin
      begin
        Options := [];
        IdxName := DataSet.FieldByName(IDX_NAME_FIELD).Value;
        if (IndexName = '') or (IdxName = IndexName) then
        begin
          if IndexDefs.IndexOf(IdxName) = -1 then
          begin
            FieldNames := DataSet.FieldByName(IDX_FLD_FIELD).Value;
            // don't add indexes on fields not in result set
            if SourceDS.CheckFieldNames(FieldNames) then
            begin
              IdxType := DataSet.FieldByName(IDX_TYPE_FIELD).Value;
              if (IdxType and eSQLPrimaryKey) = eSQLPrimaryKey then
                Options := Options + [ixPrimary];
              if (IdxType and eSQLUnique) = eSQLUnique then
                Options := Options + [ixUnique];
              SortOrder := DataSet.FieldByName(IDX_SORT_FIELD).Value;
              if SortOrder = DescendingOrder then
                Options := Options + [ixDescending];
              FIndexDefs.Add(IdxName, FieldNames, Options);
            end;
          end else
          begin
            IdxDef := IndexDefs.Find(IdxName);
            IdxDef.Fields := IdxDef.Fields + ';' + DataSet.FieldByName(IDX_FLD_FIELD).Value;
          end;
        end;
      end;
      DataSet.Next;
    end;
  finally
    FSQLConnection.FreeSchemaTable(DataSet);
  end;
  FIndexDefsLoaded := True;
end;

function TCustomSQLDataSet.GetKeyFieldNames(List: TStrings): Integer;
var
  I: Integer;
begin
  if not FIndexDefsLoaded then
    AddIndexDefs(Self);
  Result := IndexDefs.Count;
  List.BeginUpdate;
  try
    List.Clear;
    for I := 0 to Result - 1 do
      List.Add(IndexDefs[I].Fields);
  finally
    List.EndUpdate;
  end;
end;

{ Schema Tables }

procedure TCustomSQLDataSet.SetSchemaInfo(SchemaType: TSchemaType; SchemaObjectName, SchemaPattern: string);
begin
  FreeStatement;
  FSchemaInfo.FType := SchemaType;
  FSchemaInfo.ObjectName := SchemaObjectName;
  FSchemaInfo.Pattern := SchemaPattern;
end;

procedure TCustomSQLDataSet.OpenSchema;

  function ExtractObjectName(Value: string): string;
  var
    NamePos: Integer;
    Q: string;
  begin
    Result := Value;
    Q := GetQuoteChar;
    if (Q = '') or (Q = ' ') then exit;
    NamePos := Pos('.' + Q, Value);
    if NamePos = 0 then
      NamePos := Pos(Q + '.', Value);
    if NamePos = 0 then exit;
    Result := Copy(Value, NamePos + 2, Length(Value) - NamePos);
    if Pos(Q, Result) > 0 then
      Result := Copy(Result, 1, Length(Result) -1);
  end;

var
  Status: SQLResult;
  TblType: LongWord;
  WildCard: PChar;
begin
  Status := SQL_NULL_DATA;
  if FSQLConnection = nil then
    DatabaseError(sConnectionNameMissing);
  if FSchemaInfo.Pattern = '' then
    WildCard := nil
  else
    WildCard := PChar(FSchemaInfo.Pattern);  
  FSchemaInfo.ObjectName := ExtractObjectName(FSchemaInfo.ObjectName);
  case FSchemaInfo.FType of
    stTables:
    begin
      TblType := GetTableScope(GetInternalConnection.FTableScope);
      Status := GetInternalConnection.FSQLMetaData.getTables(
                  WildCard, TblType, FSQLCursor)
    end;
    stSysTables:
      Status := GetInternalConnection.FSQLMetaData.getTables(
                  WildCard, eSQLSystemTable, FSQLCursor);
    stColumns:
      Status := GetInternalConnection.FSQLMetaData.getColumns(
                  PChar(FSchemaInfo.ObjectName),
                  PChar(FSchemaInfo.Pattern), 0, FSQLCursor);
    stProcedures:
      Status := GetInternalConnection.FSQLMetaData.getProcedures(
                  WildCard, eSQLProcedure, FSQLCursor);
    stProcedureParams:
      Status := GetInternalConnection.FSQLMetaData.getProcedureParams(
                  PChar(FSchemaInfo.ObjectName), PChar(FSchemaInfo.Pattern),
                  FSQLCursor);
    stIndexes:
      Status := GetInternalConnection.FSQLMetaData.getIndices(
                  PChar(FSchemaInfo.ObjectName), 0, FSQLCursor);
  end;
  if Status <> SQL_SUCCESS then
    GetInternalConnection.SQLError(Status, exceptMetaData);
end;

{ ProviderSupport }

procedure TCustomSQLDataSet.PSEndTransaction(Commit: Boolean);
var TransDesc: TTransactionDesc;
begin
   FillChar(TransDesc, Sizeof(TransDesc), 0);
   TransDesc.TransactionID := 1;

   if Commit then FSQLConnection.Commit(TransDesc)
   else FSQLConnection.Rollback(TransDesc);
end;

procedure TCustomSQLDataSet.PSExecute;
begin
   ExecSQL;
end;

function TCustomSQLDataSet.PSExecuteStatement(const ASQL: string; AParams: TParams;
  ResultSet: Pointer = nil): Integer;
begin
  if Assigned(ResultSet) then
  begin
    TDataSet(ResultSet^) := TCustomSQLDataSet.Create(nil);
    Result := FSQLConnection.execute(ASQL, AParams, ResultSet);
  end
  else
    Result := FSQLConnection.execute(ASQL, AParams);
end;

procedure TCustomSQLDataSet.PSGetAttributes(List: TList);
var
  Attr: PPacketAttribute;
begin
  inherited PSGetAttributes(List);
  New(Attr);
  List.Add(Attr);
  with Attr^ do
  begin
    Name := SLocaleCode;
    Value := Integer(FSQLConnection.LocaleCode);
    IncludeInDelta := False;
  end;
end;

function TCustomSQLDataSet.PSGetIndexDefs(IndexTypes: TIndexOptions): TIndexDefs;
begin
  if (not FIndexDefsLoaded) and (CommandType <> ctStoredProc)
     and (SchemaInfo.FType = stNoSchema) then
    AddIndexDefs(Self);
  Result := GetIndexDefs(IndexDefs, IndexTypes);
end;

function TCustomSQLDataSet.PSGetDefaultOrder: TIndexDef;

  function FieldsInQuery(IdxFields: string): Boolean;
  var
    I:  Integer;
    IdxFlds, Flds: TStrings;
    FldNames: string;
  begin
    Result := True;
    IdxFlds := TStringList.Create;
    try
      IdxFlds.CommaText := IdxFields;
      Flds := TStringList.Create;
      try
        Fields.GetFieldNames(Flds);
        FldNames := Flds.CommaText;
        for I := 0 to IdxFlds.Count -1 do
        begin
          if pos(IdxFlds[I], FldNames) = 0 then
          begin
            Result := False;
            exit;
          end;
        end;
      finally
        Flds.Free;
      end;
    finally
      IdxFlds.Free;
    end;
  end;
  
var
  I: Integer;
begin
  Result := inherited PSGetDefaultOrder;
  if not Assigned(Result) then
    Result := GetIndexForOrderBy(GetQueryFromType, Self);
  if (not Assigned(Result)) and
     (CommandType <> ctStoredProc) and (SchemaInfo.FType = stNoSchema) then
  begin
    if not FIndexDefsLoaded then
      AddIndexDefs(Self);
    for I := 0 to IndexDefs.Count - 1 do
    begin
      if (ixPrimary in TIndexDef(IndexDefs[I]).Options) and 
         FieldsInQuery(TIndexDef(IndexDefs[I]).Fields) then
      begin
        Result := TIndexDef.Create(nil);
        Result.Assign(IndexDefs[I]);
        Break;
      end;
    end;
  end;
end;

function TCustomSQLDataSet.PSGetKeyFields: string;
var
  HoldPos, I: Integer;
  IndexFound:Boolean;
begin
  if (CommandType = ctStoredProc) or (SchemaInfo.FType <> stNoSchema) then exit;
  Result := inherited PSGetKeyFields;
  IndexFound := False;
  if (Result = '') and (SchemaInfo.FType = stNoSchema) then
  begin
    if not FIndexDefsLoaded then
      AddIndexDefs(Self);
    for I := 0 to IndexDefs.Count - 1 do
      if ixUnique in IndexDefs[I].Options then
      begin
        Result := IndexDefs[I].Fields;
        IndexFound := (FieldCount = 0);
        if not IndexFound then
        begin
          HoldPos := 1;
          while HoldPos <= Length(Result) do
          begin
            IndexFound := FindField(ExtractFieldName(Result, HoldPos)) <> nil;
            if not IndexFound then Break;
          end;
        end;
        if IndexFound then Break;
      end;
    if not IndexFound then
      Result := '';
  end;
end;

function TCustomSQLDataSet.PSGetParams: TParams;
begin
  Result := Params;
end; 

function TCustomSQLDataSet.GetQuoteChar: string;
begin
  Result := PSGetQuoteChar;
end;

function TCustomSQLDataSet.PSGetQuoteChar: string;
begin
  Result := '';
  if FSQLConnection.QuoteChar <> '' then
    Result := FSQLConnection.QuoteChar;
end;

procedure TCustomSQLDataSet.PSReset;
begin
  inherited PSReset;
  if Active and (not BOF) then
    First;
end;

function TCustomSQLDataSet.PSGetTableName: string;
begin
   if CommandType = ctTable then
     Result := CommandText
   else
     Result := GetTableNameFromSQL(CommandText);
end;

function TCustomSQLDataSet.PSGetUpdateException(E: Exception; Prev: EUpdateError): EUpdateError;
begin
  if not Assigned(E) then
    E := EDatabaseError.Create(SErrorMappingError);
  Result := inherited PSGetUpdateException(E, Prev);
end; 

function TCustomSQLDataSet.PSInTransaction: Boolean;
begin
  Result := (FSQLConnection <> nil) and (FSQLConnection.InTransaction);
end;

function TCustomSQLDataSet.PSIsSQLBased: Boolean;
begin
  Result := True;
end;

function TCustomSQLDataSet.PSIsSQLSupported: Boolean;
begin
  Result := True;
end;

procedure TCustomSQLDataSet.PSSetParams(AParams: TParams);
begin
  if AParams.Count <> 0 then
  begin
    Params.Assign(AParams);
    if Prepared and (pos(SParam, FNativeCommand) = 0) then
      SetPrepared(False);
  end;
  Close;
end;

procedure TCustomSQLDataSet.PSSetCommandText(const ACommandText: string);
begin
  if ACommandText <> '' then
    CommandText := ACommandText;
end;

procedure TCustomSQLDataSet.PSStartTransaction;
var TransDesc: TTransactionDesc ;
begin
  FillChar(TransDesc, Sizeof(TransDesc), 0);
  TransDesc.TransactionID := 1;
  FSQLConnection.StartTransaction(TransDesc);
end;

function TCustomSQLDataSet.PSUpdateRecord(UpdateKind: TUpdateKind; Delta: TDataSet): Boolean;
begin
  { OnUpdateRecord is not supported }
  Result := False;
end;

{ TSQLDataSet }

constructor TSQLDataSet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCommandType := ctQuery;
end;

function TSQLDataSet.ExecSQL(ExecDirect: Boolean = False): Integer; 
begin
  Result := inherited ExecSQL(ExecDirect);
end;

{ TSQLQuery }

constructor TSQLQuery.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCommandType := ctQuery;
  FSQL := TStringList.Create;
  FNoMetaData := True;
  TStringList(SQL).OnChange := QueryChanged;
end;

destructor TSQLQuery.Destroy; 
begin
  FSQL.Free;
  inherited Destroy;
end;

function TSQLQuery.ExecSQL(ExecDirect: Boolean = False): Integer;
begin
  Result := inherited ExecSQL(ExecDirect);
end;

procedure TSQLQuery.PrepareStatement;
var
  SQLText: string;
begin
  if FCommandText = '' then
    SetSQL(SQL);
  if Length(CommandText) = 0 then
    DatabaseError(SEmptySQLStatement, Self);
  CheckStatement;
  SQLText := FNativeCommand;
  Check(FSQLCommand.prepare(PChar(SQLText), ParamCount));
end;

procedure TSQLQuery.QueryChanged(Sender: TObject);
var
  List: TSQLParams;
begin
  if not (csReading in ComponentState) then
  begin
    Close;
    SetPrepared(False);
    if ParamCheck or (csDesigning in ComponentState) then
    begin
      List := TSQLParams.Create(Self);
      try
        FText := SQL.Text;
        List.Parse(FText, True);
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
  SetFCommandText(FText);
end;

procedure TSQLQuery.SetSQL(Value: TStrings);
begin
  if SQL.Text <> Value.Text then
  begin
    Close;
    SQL.BeginUpdate;
    try
      SQL.Assign(Value);
    finally
      SQL.EndUpdate;
    end;
  end;
end;

{ TSQLStoredProc }

constructor TSQLStoredProc.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCommandType := ctStoredProc;
end;

function TSQLStoredProc.ExecProc: Integer;
begin
  Result := ExecSQL;
end;

procedure TSQLStoredProc.PrepareStatement;
var
  Q: String;
  SQLText: string;
begin
  Q := FSQLConnection.QuoteChar;
  if FCommandText = '' then
    SetStoredProcName(FStoredProcName);
  if Length(CommandText) = 0 then
    DatabaseError(SEmptySQLStatement, Self);
  CheckStatement;
  SQLText := AddQuoteCharToObjectName(FNativeCommand, Q);
  Check(FSQLCommand.SetOption(eCommStoredProc, Integer(True)));
  Check(FSQLCommand.prepare(PChar(SQLText), ParamCount));
end;

procedure TSQLStoredProc.SetStoredProcName(Value: string);
begin
  if FStoredProcName <> Value then
  begin
    FStoredProcName := Value;
    SetCommandText(Value);
    if Assigned(FProcParams) then  // free output params if any
      FreeProcParams(FProcParams);
  end;
end;

function TSQLStoredProc.NextRecordSet: TCustomSQLDataSet;
begin
  FGetNextRecordSet := True;
  SetState(dsInactive);
  CloseCursor;
  Active := True;
  FGetNextRecordSet := False;
  Result := TCustomSQLDataSet(Self);
end;

{ TSQLTable }

constructor TSQLTable.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCommandType := ctTable;
  FIndexFieldCount := -1;
  FMasterLink := TMasterDataLink.Create(Self);
  FIndexFields := TList.Create;
end;

destructor TSQLTable.Destroy;
begin
  FreeAndNil(FMasterLink);
  FreeAndNil(FIndexFields);
  inherited Destroy;
end;

procedure TSQLTable.DeleteRecords;
begin
  SQLConnection.ExecuteDirect('delete from ' + TableName);   { do not localize }
end;

function TSQLTable.GetIndexField(Index: Integer): TField;
begin
  if IndexName = '' then Result := nil
  else 
  begin
    if FIndexFieldCount = -1 then
      RefreshIndexFields;
    Result := FIndexFields[Index];
  end;
end;

function TSQLTable.GetIndexFieldCount: Integer;
begin
  if IndexName = '' then Result := 0
  else if FIndexFieldCount >= 0 then Result := FIndexFieldCount
  else Result := RefreshIndexFields;
end;

procedure TSQLTable.GetIndexNames(List: TStrings);
begin
  FSQLConnection.GetIndexNames(FTableName,List);
end;

procedure TSQLTable.OpenCursor(InfoQuery: Boolean);
begin
  inherited OpenCursor(InfoQuery);
  if not FIsDetail and not FIndexDefsLoaded then
    AddIndexDefs(Self);
end;

procedure TSQLTable.AddParamsToQuery;
var
  I: Integer;
  Value: string;
begin
  if Pos('?', NativeCommand) = 0 then
  begin
    for I := 0 to Params.Count -1 do
    begin
      if Params[I].IsNull then
        Value := 'is NULL'
      else
        Value := '= ?';
      if I = 0 then
        NativeCommand := format('%s%s(%s %s)', [NativeCommand, SWhere, Params[I].Name, Value])
      else
        NativeCommand := format('%s%s(%s %s)', [NativeCommand, SAnd, Params[I].Name, Value]);
    end;
  end;
end;

procedure TSQLTable.SetDataSource(Value: TDataSource);
begin
  inherited SetDataSource(Value);
end;

function TSQLTable.GetQueryFromType: string;
begin
  if FNativeCommand <> '' then
    Result := FNativeCommand
  else
    Result := inherited GetQueryFromType;
end;

procedure TSQLTable.PrepareStatement;

  function GetFieldsForIndexName(IndexName: string): string;
  const
    IDX_NAME_FIELD = 'INDEX_NAME';           { Do not localize }
    IDX_FLD_FIELD = 'COLUMN_NAME';           { Do not localize }
  var
    DataSet: TCustomSQLDataSet;
    IdxName: string;
  begin
    DataSet := FSQLConnection.OpenSchemaTable(stIndexes, TableName);
    if not Assigned(DataSet) then FSQLConnection.SQLError(SQLResult(-1), exceptMetadata);
    try
      while not DataSet.EOF do
      begin
        IdxName := DataSet.FieldByName(IDX_NAME_FIELD).Value;
        if IdxName = IndexName then
        begin
          if Result = '' then
            Result := DataSet.FieldByName(IDX_FLD_FIELD).Value
          else
            Result := Result + ';' + DataSet.FieldByName(IDX_FLD_FIELD).Value;
        end;
        DataSet.Next;
      end;
    finally
      FSQLConnection.FreeSchemaTable(DataSet);
    end;
  end;

  function GetIndexFieldNames(FieldNames, IndexName: string): string;
  begin
    if (FieldNames = '') and (IndexName = '') then
      Result := ''
    else if FieldNames <> '' then
      Result := FieldNames
    else
      Result := GetFieldsForIndexName(IndexName);
  end;

var
  FDetailWhere, SQLText, IdxFieldNames: string;
  FActiveStatements, FIndex, Pos1, Pos2: Integer;
  FName1, FName2, TempString1, TempString2: string;
  Q: String;
begin  // first, convert TableName into valid Query.
  if Length(FTableName) = 0 then
    DatabaseError(SEmptySQLStatement, Self);
  if FNativeCommand = '' then  // otherwise, already prepared
  begin
    Q := FSQLConnection.QuoteChar;
    if (FDataLink.DataSource <> nil) and (MasterFields <> '') then
    begin
      FIsDetail := True;
      Pos1 := 1;
      Pos2 := 1;
      FIndex := 1;
      TempString1 := MasterFields;
      TempString2 := IndexFieldNames;
      while Pos1 <= Length(TempString1) do
        begin
          FName1 := ExtractFieldName(TempString1, Pos1);
          FName2 := ExtractFieldName(TempString2, Pos2);
          if FName1 = '' then Break;
          if FIndex = 1 then
            FDetailWhere := SWhere
          else
            FDetailWhere := FDetailWhere + SAnd;
          if FName2 = '' then
            FDetailWhere := FDetailWhere + FName1 + ' = :' + FName1
          else
            FDetailWhere := FDetailWhere + FName2 + ' = :' + FName1;
          Inc(FIndex);
        end;
      FCommandType := ctQuery;
      FActiveStatements := FSQLConnection.FActiveStatements;
      SetCommandText(SSelectStarFrom + AddQuoteCharToObjectName(FTableName, Q) 
                      + FDetailWhere);
      FSQLConnection.FActiveStatements := FActiveStatements;
    end else
    begin
      FIsDetail := False;
      IdxFieldNames := GetIndexFieldNames(IndexFieldNames, IndexName);
      if IdxFieldNames = '' then
        FCommandText := SSelectStarFrom + AddQuoteCharToObjectName(FTableName, Q)
      else
        FCommandText := SSelectStarFrom + AddQuoteCharToObjectName(FTableName, Q)
                     + SOrderBy + StringReplace(IdxFieldNames, ';', ',', [rfReplaceAll]);
    end;
  end else if Params.Count > 0 then
    AddParamsToQuery;
  CheckStatement;
  SQLText := FNativeCommand;
  Check(FSQLCommand.prepare(PChar(SQLText), ParamCount));
  FCommandType := ctTable;
  FCommandText := FTableName;
end;

function TSQLTable.RefreshIndexFields: Integer;
var
  I, Pos: Integer;
  Temp: string;
  FField: TField;
begin
  Result := 0;
  if not FIndexDefsLoaded then
    AddIndexDefs(Self);
  FIndexFields.Clear;
  for I := 0 to IndexDefs.Count - 1 do
  begin
    if AnsiCompareText(IndexDefs[I].Name, IndexName) = 0 then
    begin
      Temp := IndexDefs[I].Fields;
      Pos := 1;
      while Pos <= Length(Temp) do
      begin
        FField := FindField(ExtractFieldName(Temp, Pos));
        if FField = nil then
          Break
        else
          FIndexFields.Add(FField);
        Inc(Result);
      end;
      Break;
    end;
  end;
end;

function TSQLTable.GetMasterFields: string;
begin
  Result := FMasterLink.FieldNames;
end;

procedure TSQLTable.SetMasterFields(Value: string);
begin
  FMasterLink.FieldNames := Value;
  if not (csLoading in ComponentState) then
  begin
    Close;
    FreeStatement;
    FNativeCommand := '';
  end;
end;

procedure TSQLTable.SetTableName(Value: string);
begin
  if FTableName <> Value then
  begin
    FNativeCommand := '';
    FTableName := Value;
    SetCommandText(Value);
  end;
end;

procedure TSQLTable.SetIndexFieldNames(Value: string);
begin
  if FIndexFieldNames <> Value then
  begin
    if (csDesigning in ComponentState) and not (csLoading in ComponentState) then
      if TableName = '' then DatabaseError(SNoTableName,Self);
    FIndexFieldNames := Value;
    if FIndexFieldNames <> '' then
      SetIndexName('');
    FNativeCommand := '';
  end;
end;

procedure TSQLTable.SetIndexField(Index: Integer; Value: TField);
begin
  GetIndexField(Index).Assign(Value);
end;

procedure TSQLTable.SetIndexName(Value: string);
begin
  if (csDesigning in ComponentState) and not (csLoading in ComponentState) then
    if TableName = '' then DatabaseError(SNoTableName,Self);
  if FIndexName <> Value then
  begin
    FIndexName := Value;
    FNativeCommand := '';
    if Assigned(FSQLConnection) and (Value <> '') then
    begin
      SetIndexFieldNames('');  // clear out IndexFieldNames
      if (csDesigning in ComponentState) and not (csLoading in ComponentState) then
        AddIndexDefs(Self, Value);
    end;
  end;
  FIndexFieldCount := -1;
end;

{$IFDEF MSWINDOWS}
procedure RegisterDbXpressLib(GetClassProc: Pointer);
begin
  GetDriver := GetClassProc;
  DllHandle := THandle(1);
end;
{$ENDIF}

end.
