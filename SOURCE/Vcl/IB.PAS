{********************************************************}
{                                                        }
{       Borland Delphi Visual Component Library          }
{       InterBase Express core components                }
{                                                        }
{       Copyright (c) 1998-1999 Inprise Corporation      }
{                                                        }
{    InterBase Express is based in part on the product   }
{    Free IB Components, written by Gregory H. Deatz for }
{    Hoagland, Longo, Moran, Dunst & Doukas Company.     }
{    Free IB Components is used under license.           }
{                                                        }
{********************************************************}

unit IB;

interface

uses
  Windows, SysUtils, Classes, IBHeader, IBExternals, IBUtils, DB;

type
    EIBError                  = class(EDatabaseError)
  private
    FSQLCode: Long;
    FIBErrorCode: Long;
  public
    constructor Create(ASQLCode: Long; Msg: string); overload;
    constructor Create(ASQLCode: Long; AIBErrorCode: Long; Msg: string); overload;
    property SQLCode: Long read FSQLCode;
    property IBErrorCode: Long read FIBErrorCode;
  end;

  EIBInterBaseError         = class(EIBError);
  EIBClientError            = class(EIBError);

  TIBDataBaseErrorMessage    = (ShowSQLCode,
                                ShowIBMessage,
                                ShowSQLMessage);
  TIBDataBaseErrorMessages   = set of TIBDataBaseErrorMessage;
  TIBClientError            = (
    ibxeUnknownError,
    ibxeInterBaseMissing,
    ibxeInterBaseInstallMissing,
    ibxeIB60feature,
    ibxeNotSupported,
    ibxeNotPermitted,
    ibxeFileAccessError,
    ibxeConnectionTimeout,
    ibxeCannotSetDatabase,
    ibxeCannotSetTransaction,
    ibxeOperationCancelled,
    ibxeDPBConstantNotSupported,
    ibxeDPBConstantUnknown,
    ibxeTPBConstantNotSupported,
    ibxeTPBConstantUnknown,
    ibxeDatabaseClosed,
    ibxeDatabaseOpen,
    ibxeDatabaseNameMissing,
    ibxeNotInTransaction,
    ibxeInTransaction,
    ibxeTimeoutNegative,
    ibxeNoDatabasesInTransaction,
    ibxeUpdateWrongDB,
    ibxeUpdateWrongTR,
    ibxeDatabaseNotAssigned,
    ibxeTransactionNotAssigned,
    ibxeXSQLDAIndexOutOfRange,
    ibxeXSQLDANameDoesNotExist,
    ibxeEOF,
    ibxeBOF,
    ibxeInvalidStatementHandle,
    ibxeSQLOpen,
    ibxeSQLClosed,
    ibxeDatasetOpen,
    ibxeDatasetClosed,
    ibxeUnknownSQLDataType,
    ibxeInvalidColumnIndex,
    ibxeInvalidParamColumnIndex,
    ibxeInvalidDataConversion,
    ibxeColumnIsNotNullable,
    ibxeBlobCannotBeRead,
    ibxeBlobCannotBeWritten,
    ibxeEmptyQuery,
    ibxeCannotOpenNonSQLSelect,
    ibxeNoFieldAccess,
    ibxeFieldReadOnly,
    ibxeFieldNotFound,
    ibxeNotEditing,
    ibxeCannotInsert,
    ibxeCannotPost,
    ibxeCannotUpdate,
    ibxeCannotDelete,
    ibxeCannotRefresh,
    ibxeBufferNotSet,
    ibxeCircularReference,
    ibxeSQLParseError,
    ibxeUserAbort,
    ibxeDataSetUniDirectional,
    ibxeCannotCreateSharedResource,
    ibxeWindowsAPIError,
    ibxeColumnListsDontMatch,
    ibxeColumnTypesDontMatch,
    ibxeCantEndSharedTransaction,
    ibxeFieldUnsupportedType,
    ibxeCircularDataLink,
    ibxeEmptySQLStatement,
    ibxeIsASelectStatement,
    ibxeRequiredParamNotSet,
    ibxeNoStoredProcName,
    ibxeIsAExecuteProcedure,
    ibxeUpdateFailed,
    ibxeNotCachedUpdates,
    ibxeNotLiveRequest,
    ibxeNoProvider,
    ibxeNoRecordsAffected,
    ibxeNoTableName,
    ibxeCannotCreatePrimaryIndex,
    ibxeCannotDropSystemIndex,
    ibxeTableNameMismatch,
    ibxeIndexFieldMissing,
    ibxeInvalidCancellation,
    ibxeInvalidEvent,
    ibxeMaximumEvents,
    ibxeNoEventsRegistered,
    ibxeInvalidQueueing,
    ibxeInvalidRegistration,
    ibxeInvalidBatchMove,
    ibxeSQLDialectInvalid,
    ibxeSPBConstantNotSupported,
    ibxeSPBConstantUnknown,
    ibxeServiceActive,
    ibxeServiceInActive,
    ibxeServerNameMissing,
    ibxeQueryParamsError,
    ibxeStartParamsError,
    ibxeOutputParsingError,
    ibxeUseSpecificProcedures,
    ibxeSQLMonitorAlreadyPresent
    );

  TStatusVector              = array[0..19] of ISC_STATUS;
  PStatusVector              = ^TStatusVector;

  { TIBTLGlobals }

  { A single structure will be used to maintain all thread-local "globals" }
  TIBTLGlobals              = record
    FStatusVector: TStatusVector;
  end;
  PIBTLGlobals              = ^TIBTLGlobals;

resourcestring
{ generic strings used in code }
  SIBDatabaseEditor = 'Da&tabase Editor...';
  SIBTransactionEditor = '&Transaction Editor...';
  SDatabaseFilter = 'Database Files (*.gdb)|*.gdb|All files (*.*)|*.*';
  SDisconnectDatabase = 'Database is currently connected. Disconnect and continue?';
  SCommitTransaction = 'Transaction is currently Active. Rollback and continue?';
  SExecute = 'E&xecute';
  SNoDataSet = 'No dataset association';
  SSQLGenSelect = 'Must select at least one key field and one update field';
  SSQLNotGenerated = 'Update SQL statements not generated, exit anyway?';
  SIBUpdateSQLEditor = '&UpdateSQL Editor...';
  SSQLDataSetOpen = 'Unable to determine field names for %s';

{ strings used in error messages}
  SUnknownError = 'Unknown error';
  SInterBaseMissing = 'InterBase library gds32.dll not found in the path. Please install InterBase to use this functionality';
  SInterBaseInstallMissing = 'InterBase Install DLL ibinstall.dll not found in the path. Please install InterBase 6 to use this functionality';
  SIB60feature = '%s is an InterBase6 function. Please upgrade to InterBase6 to use this functonality';
  SNotSupported = 'Unsupported feature';
  SNotPermitted = 'Not permitted';
  SFileAccessError = 'Temporary file access error';
  SConnectionTimeout = 'Database connection timed out';
  SCannotSetDatabase = 'Cannot set database';
  SCannotSetTransaction = 'Cannot set transaction';
  SOperationCancelled = 'Operation cancelled at user''s request';
  SDPBConstantNotSupported = 'DPB Constant (isc_dpb_%s) is unsupported';
  SDPBConstantUnknown = 'DPB Constant (%d) is unknown';
  STPBConstantNotSupported = 'TPB Constant (isc_tpb_%s) is unsupported';
  STPBConstantUnknown = 'TPB Constant (%d) is unknown';
  SDatabaseClosed = 'Cannot perform operation -- DB is not open';
  SDatabaseOpen = 'Cannot perform operation -- DB is currently open';
  SDatabaseNameMissing = 'Database name is missing';
  SNotInTransaction = 'Transaction is not active';
  SInTransaction = 'Transaction is active';
  STimeoutNegative = 'Timeout values cannot be negative';
  SNoDatabasesInTransaction = 'No databases are listed in transaction component';
  SUpdateWrongDB = 'Updating wrong database';
  SUpdateWrongTR = 'Updating wrong transaction. Unique transaction expected in set';
  SDatabaseNotAssigned = 'Database not assigned';
  STransactionNotAssigned = 'Transaction not assigned';
  SXSQLDAIndexOutOfRange = 'XSQLDA index out of range';
  SXSQLDANameDoesNotExist = 'XSQLDA name does not exist (%s)';
  SEOF = 'End of file';
  SBOF = 'Beginning of file';
  SInvalidStatementHandle = 'Invalid statement handle';
  SSQLOpen = 'IBSQL Open';
  SSQLClosed = 'IBSQL Closed';
  SDatasetOpen = 'Dataset open';
  SDatasetClosed = 'Dataset closed';
  SUnknownSQLDataType = 'Unknown SQL Data type (%d)';
  SInvalidColumnIndex = 'Invalid column index (index exceeds permitted range)';
  SInvalidParamColumnIndex = 'Invalid parameter index (index exceeds permitted range)';
  SInvalidDataConversion = 'Invalid data conversion';
  SColumnIsNotNullable = 'Column cannot be set to null (%s)';
  SBlobCannotBeRead = 'Blob stream cannot be read';
  SBlobCannotBeWritten = 'Blob stream cannot be written';
  SEmptyQuery = 'Empty query';
  SCannotOpenNonSQLSelect = 'Cannot "open" a non-select statement. Use ExecQuery';
  SNoFieldAccess = 'No access to field "%s"';
  SFieldReadOnly = 'Field "%s" is read-only';
  SFieldNotFound = 'Field "%s" not found';
  SNotEditing = 'Not editing';
  SCannotInsert = 'Cannot insert into dataset. (No insert query)';
  SCannotPost = 'Cannot post. (No update/insert query)';
  SCannotUpdate = 'Cannot update. (No update query)';
  SCannotDelete = 'Cannot delete from dataset. (No delete query)';
  SCannotRefresh = 'Cannot refresh row. (No refresh query)';
  SBufferNotSet = 'Buffer not set';
  SCircularReference = 'Circular references not permitted';
  SSQLParseError = 'SQL Parse Error:' + CRLF + CRLF + '%s';
  SUserAbort = 'User abort';
  SDataSetUniDirectional = 'Data set is uni-directional';
  SCannotCreateSharedResource = 'Cannot create shared resource. (Windows error %d)';
  SWindowsAPIError = 'Windows API error. (Windows error %d [$%.8x])';
  SColumnListsDontMatch = 'Column lists do not match';
  SColumnTypesDontMatch = 'Column types don''t match. (From index: %d; To index: %d)';
  SCantEndSharedTransaction = 'Can''t end a shared transaction unless it is forced and equal ' +
                             'to the transaction''s TimeoutAction';
  SFieldUnsupportedType = 'Unsupported Field Type';
  SCircularDataLink = 'Circular DataLink Reference';
  SEmptySQLStatement = 'Empty SQL Statement';
  SIsASelectStatement = 'use Open for a Select Statement';
  SRequiredParamNotSet = 'Required Param value not set';
  SNoStoredProcName = 'No Stored Procedure Name assigned';
  SIsAExecuteProcedure = 'use ExecProc for Procedure; use TQuery for Select procedures';
  SUpdateFailed = 'Update Failed';
  SNotCachedUpdates = 'CachedUpdates not enabled';
  SNotLiveRequest = 'Request is not live - cannot modify';
  SNoProvider = 'No Provider';
  SNoRecordsAffected = 'No Records Affected';
  SNoTableName = 'No Table Name assigned';
  SCannotCreatePrimaryIndex = 'Cannot Create Primary Index; are created automatically';
  SCannotDropSystemIndex = 'Cannot Drop System Index';
  STableNameMismatch = 'Table Name Mismatch';
  SIndexFieldMissing = 'Index Field Missing';
  SInvalidCancellation = 'Cannot Cancel events while processing';
  SInvalidEvent = 'Invalid Event';
  SMaximumEvents = 'Exceded Maximum Event limits';
  SNoEventsRegistered = 'No Events Registered';
  SInvalidQueueing = 'Invalid Queueing';
  SInvalidRegistration = 'Invalid Registration';
  SInvalidBatchMove = 'Invalid Batch Move';
  SSQLDialectInvalid = 'SQL Dialect Invalid';
  SSPBConstantNotSupported = 'SPB Constant Not supported';
  SSPBConstantUnknown = 'SPB Constant Unknown';
  SServiceActive = 'Cannot perform operation -- service is not attached';
  SServiceInActive = 'Cannot perform operation -- service is attached';
  SServerNameMissing = 'Server Name Missing';
  SQueryParamsError = 'Query Parameters missing or incorrect';
  SStartParamsError = 'start Parameters missing or incorrect';
  SOutputParsingError = 'Unexpected Output buffer value';
  SUseSpecificProcedures = 'Generic ServiceStart not applicable: Use Specific Procedures to set configuration params';
  SSQLMonitorAlreadyPresent = 'SQL Monitor Instance is already present';

const
  IBPalette1 = 'InterBase'; {do not localize}
  IBPalette2 = 'InterBase Admin'; {do not localize}

  IBLocalBufferLength = 512;
  IBBigLocalBufferLength = IBLocalBufferLength * 2;
  IBHugeLocalBufferLength = IBBigLocalBufferLength * 20;

  IBErrorMessages: array[TIBClientError] of string = (
    SUnknownError,
    SInterBaseMissing,
    SInterBaseInstallMissing,
    SIB60feature,
    SNotSupported,
    SNotPermitted,
    SFileAccessError,
    SConnectionTimeout,
    SCannotSetDatabase,
    SCannotSetTransaction,
    SOperationCancelled,
    SDPBConstantNotSupported,
    SDPBConstantUnknown,
    STPBConstantNotSupported,
    STPBConstantUnknown,
    SDatabaseClosed,
    SDatabaseOpen,
    SDatabaseNameMissing,
    SNotInTransaction,
    SInTransaction,
    STimeoutNegative,
    SNoDatabasesInTransaction,
    SUpdateWrongDB,
    SUpdateWrongTR,
    SDatabaseNotAssigned,
    STransactionNotAssigned,
    SXSQLDAIndexOutOfRange,
    SXSQLDANameDoesNotExist,
    SEOF,
    SBOF,
    SInvalidStatementHandle,
    SSQLOpen,
    SSQLClosed,
    SDatasetOpen,
    SDatasetClosed,
    SUnknownSQLDataType,
    SInvalidColumnIndex,
    SInvalidParamColumnIndex,
    SInvalidDataConversion,
    SColumnIsNotNullable,
    SBlobCannotBeRead,
    SBlobCannotBeWritten,
    SEmptyQuery,
    SCannotOpenNonSQLSelect,
    SNoFieldAccess,
    SFieldReadOnly,
    SFieldNotFound,
    SNotEditing,
    SCannotInsert,
    SCannotPost,
    SCannotUpdate,
    SCannotDelete,
    SCannotRefresh,
    SBufferNotSet,
    SCircularReference,
    SSQLParseError,
    SUserAbort,
    SDataSetUniDirectional,
    SCannotCreateSharedResource,
    SWindowsAPIError,
    SColumnListsDontMatch,
    SColumnTypesDontMatch,
    SCantEndSharedTransaction,
    SFieldUnsupportedType,
    SCircularDataLink,
    SEmptySQLStatement,
    SIsASelectStatement,
    SRequiredParamNotSet,
    SNoStoredProcName,
    SIsAExecuteProcedure,
    SUpdateFailed,
    SNotCachedUpdates,
    SNotLiveRequest,
    SNoProvider,
    SNoRecordsAffected,
    SNoTableName,
    SCannotCreatePrimaryIndex,
    SCannotDropSystemIndex,
    STableNameMismatch,
    SIndexFieldMissing,
    SInvalidCancellation,
    SInvalidEvent,
    SMaximumEvents,
    SNoEventsRegistered,
    SInvalidQueueing,
    SInvalidRegistration,
    SInvalidBatchMove,
    SSQLDialectInvalid,
    SSPBConstantNotSupported,
    SSPBConstantUnknown,
    SServiceActive,
    SServiceInActive,
    SServerNameMissing,
    SQueryParamsError,
    SStartParamsError,
    SOutputParsingError,
    SUseSpecificProcedures,
    SSQLMonitorAlreadyPresent
  );

var
  IBCS: TRTLCriticalSection;
  hIBTLGlobals: DWord;

procedure IBAlloc(var P; OldSize, NewSize: Integer);

procedure IBError(ErrMess: TIBClientError; const Args: array of const);
procedure IBDataBaseError;

procedure InitializeIBTLGlobals;
procedure FreeIBTLGlobals;

function StatusVector: PISC_STATUS;
function StatusVectorArray: PStatusVector;
function CheckStatusVector(ErrorCodes: array of ISC_STATUS): Boolean;
function StatusVectorAsText: string;

procedure SetIBDataBaseErrorMessages(Value: TIBDataBaseErrorMessages);
function GetIBDataBaseErrorMessages: TIBDataBaseErrorMessages;

implementation

uses
  IBIntf;

var
  IBDataBaseErrorMessages: TIBDataBaseErrorMessages;


procedure IBAlloc(var P; OldSize, NewSize: Integer);
var
  i: Integer;
begin
  ReallocMem(Pointer(P), NewSize);
  for i := OldSize to NewSize - 1 do PChar(P)[i] := #0;
end;

procedure IBError(ErrMess: TIBClientError; const Args: array of const);
begin
  raise EIBClientError.Create(Ord(ErrMess),
                              Format(IBErrorMessages[ErrMess], Args));
end;

procedure IBDataBaseError;
var
  sqlcode: Long;
  IBErrorCode: Long;
  local_buffer: array[0..IBHugeLocalBufferLength - 1] of char;
  usr_msg: string;
  status_vector: PISC_STATUS;
  IBDataBaseErrorMessages: TIBDataBaseErrorMessages;
begin
  usr_msg := '';

  { Get a local reference to the status vector.
    Get a local copy of the IBDataBaseErrorMessages options.
    Get the SQL error code }
  status_vector := StatusVector;
  IBErrorCode := StatusVectorArray[1];
  IBDataBaseErrorMessages := GetIBDataBaseErrorMessages;
  sqlcode := isc_sqlcode(status_vector);

  if (ShowSQLCode in IBDataBaseErrorMessages) then
    usr_msg := usr_msg + 'SQLCODE: ' + IntToStr(sqlcode); {do not localize}
  Exclude(IBDataBaseErrorMessages, ShowSQLMessage);
  if (ShowSQLMessage in IBDataBaseErrorMessages) then
  begin
    isc_sql_interprete(sqlcode, local_buffer, IBLocalBufferLength);
    if (ShowSQLCode in IBDataBaseErrorMessages) then
      usr_msg := usr_msg + CRLF;
    usr_msg := usr_msg + string(local_buffer);
  end;

  if (ShowIBMessage in IBDataBaseErrorMessages) then
  begin
    if (ShowSQLCode in IBDataBaseErrorMessages) or
       (ShowSQLMessage in IBDataBaseErrorMessages) then
      usr_msg := usr_msg + CRLF;
    while (isc_interprete(local_buffer, @status_vector) > 0) do
    begin
      if (usr_msg <> '') and (usr_msg[Length(usr_msg)] <> LF) then
        usr_msg := usr_msg + CRLF;
      usr_msg := usr_msg + string(local_buffer);
    end;
  end;
  if (usr_msg <> '') and (usr_msg[Length(usr_msg)] = '.') then
    Delete(usr_msg, Length(usr_msg), 1);
  raise EIBInterBaseError.Create(sqlcode, IBErrorCode, usr_msg);
end;

procedure InitializeIBTLGlobals;
var
  TLGlobals: PIBTLGlobals;
begin
  TLGlobals := nil;
  if TlsGetValue(hIBTLGlobals) <> nil then exit;
  IBAlloc(TLGlobals, 0, SizeOf(TIBTLGlobals));
  TlsSetValue(hIBTLGlobals, Pointer(TLGlobals));
end;

procedure FreeIBTLGlobals;
var
  TLGlobals: PIBTLGlobals;
begin
  TLGlobals := PIBTLGlobals(TlsGetValue(hIBTLGlobals));
  if TLGlobals <> nil then
  begin
    IBAlloc(TLGlobals, 0, 0);
    TlsSetValue(hIBTLGlobals, nil);
  end;
end;

{ Return the status vector for the current thread }
function StatusVector: PISC_STATUS;
var
  TLGlobals: PIBTLGlobals;
begin
  TLGlobals := PIBTLGlobals(TlsGetValue(hIBTLGlobals));
  if TLGlobals = nil then
  begin
    InitializeIBTLGlobals;
    TLGlobals := PIBTLGlobals(TlsGetValue(hIBTLGlobals));
  end;
  result := @(TLGlobals^.FStatusVector);
end;

function StatusVectorArray: PStatusVector;
var
  TLGlobals: PIBTLGlobals;
begin
  TLGlobals := PIBTLGlobals(TlsGetValue(hIBTLGlobals));
  if TLGlobals = nil then
  begin
    InitializeIBTLGlobals;
    TLGlobals := PIBTLGlobals(TlsGetValue(hIBTLGlobals));
  end;
  result := @(TLGlobals^.FStatusVector);
end;

function CheckStatusVector(ErrorCodes: array of ISC_STATUS): Boolean;
var
  p: PISC_STATUS;
  i: Integer;
  procedure NextP(i: Integer);
  begin
    p := PISC_STATUS(PChar(p) + (i * SizeOf(ISC_STATUS)));
  end;
begin
  p := StatusVector;
  result := False;
  while (p^ <> 0) and (not result) do
    case p^ of
      3: NextP(3);
      1, 4:
      begin
        NextP(1);
        i := 0;
        while (i <= High(ErrorCodes)) and (not result) do
        begin
          result := p^ = ErrorCodes[i];
          Inc(i);
        end;
        NextP(1);
      end;
      else
        NextP(2);
    end;
end;

function StatusVectorAsText: string;
var
  p: PISC_STATUS;
  function NextP(i: Integer): PISC_STATUS;
  begin
    p := PISC_STATUS(PChar(p) + (i * SizeOf(ISC_STATUS)));
    result := p;
  end;
begin
  p := StatusVector;
  result := '';
  while (p^ <> 0) do
    if (p^ = 3) then
    begin
      result := result + Format('%d %d %d', [p^, NextP(1)^, NextP(1)^]) + CRLF;
      NextP(1);
    end
    else begin
      result := result + Format('%d %d', [p^, NextP(1)^]) + CRLF;
      NextP(1);
    end;
end;


{ EIBError }
constructor EIBError.Create(ASQLCode: Long; Msg: string);
begin
  inherited Create(Msg);
  FSQLCode := ASQLCode;
end;

constructor EIBError.Create(ASQLCode: Long; AIBErrorCode: Long; Msg: string);
begin
     inherited Create(Msg);
     FSQLCode :=  ASQLCode;
     FIBErrorCode := AIBErrorCode;
end;

procedure SetIBDataBaseErrorMessages(Value: TIBDataBaseErrorMessages);
begin
  EnterCriticalSection(IBCS);
  try
    IBDataBaseErrorMessages := Value;
  finally
    LeaveCriticalSection(IBCS);
  end;
end;

function GetIBDataBaseErrorMessages: TIBDataBaseErrorMessages;
begin
  EnterCriticalSection(IBCS);
  try
    result := IBDataBaseErrorMessages;
  finally
    LeaveCriticalSection(IBCS);
  end;
end;

initialization
  IsMultiThread := True;
  InitializeCriticalSection(IBCS);
  hIBTLGlobals := TlsAlloc;
  IBDataBaseErrorMessages := [ShowSQLMessage, ShowIBMessage];

finalization

  FreeIBTLGlobals;
  TlsFree(hIBTLGlobals);
  DeleteCriticalSection(IBCS);

end.
