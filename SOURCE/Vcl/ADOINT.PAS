
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       ADO Interface Unit                              }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit ADOInt;

// ********************************************************************* //
// Type Lib: C:\PROGRAM FILES\COMMON FILES\SYSTEM\ADO\MSADO15.DLL        //
// IID\LCID: {00000200-0000-0010-8000-00AA006D2EA4}\0                    //
// PASTLWTR : $Revision:   1.3.1.1  $                                        //
// HelpString: Microsoft ActiveX Data Objects 2.1 Library                //
// Version:    2.1                                                       //
// ********************************************************************* //

interface

uses Windows, ActiveX;

// ********************************************************************* //
// GUIDS declared in the TypeLibrary. Following prefixes are used:       //
//   Type Libraries     : LIBID_xxxx                                     //
//   CoClasses          : CLASS_xxxx                                     //
//   DISPInterfaces     : DIID_xxxx                                      //
//   Non-DISP interfaces: IID_xxxx                                       //
// ********************************************************************* //
const
  LIBID_ADODB: TGUID = '{00000201-0000-0010-8000-00AA006D2EA4}';
  CLASS_Connection: TGUID = '{00000514-0000-0010-8000-00AA006D2EA4}';
  CLASS_Command: TGUID = '{00000507-0000-0010-8000-00AA006D2EA4}';
  CLASS_Recordset: TGUID = '{00000535-0000-0010-8000-00AA006D2EA4}';
  CLASS_Parameter: TGUID = '{0000050B-0000-0010-8000-00AA006D2EA4}';
  CLASS_DataSpace: TGUID = '{BD96C556-65A3-11D0-983A-00C04FC29E36}';
  CLASS_DataFactory: TGUID = '{9381D8F5-0288-11D0-9501-00AA00B911A5}';
  IID__Collection: TGUID = '{00000512-0000-0010-8000-00AA006D2EA4}';
  IID__DynaCollection: TGUID = '{00000513-0000-0010-8000-00AA006D2EA4}';
  IID__ADO: TGUID = '{00000534-0000-0010-8000-00AA006D2EA4}';
  IID_Properties: TGUID = '{00000504-0000-0010-8000-00AA006D2EA4}';
  IID_Property_: TGUID = '{00000503-0000-0010-8000-00AA006D2EA4}';
  IID_Error: TGUID = '{00000500-0000-0010-8000-00AA006D2EA4}';
  IID_Errors: TGUID = '{00000501-0000-0010-8000-00AA006D2EA4}';
  IID_Command15: TGUID = '{00000508-0000-0010-8000-00AA006D2EA4}';
  IID_Connection15: TGUID = '{00000515-0000-0010-8000-00AA006D2EA4}';
  IID__Connection: TGUID = '{00000550-0000-0010-8000-00AA006D2EA4}';
  IID_Recordset15: TGUID = '{0000050E-0000-0010-8000-00AA006D2EA4}';
  IID_Recordset20: TGUID = '{0000054F-0000-0010-8000-00AA006D2EA4}';
  IID__Recordset: TGUID = '{00000555-0000-0010-8000-00AA006D2EA4}';
  IID_Fields15: TGUID = '{00000506-0000-0010-8000-00AA006D2EA4}';
  IID_Fields: TGUID = '{0000054D-0000-0010-8000-00AA006D2EA4}';
  IID_Field: TGUID = '{0000054C-0000-0010-8000-00AA006D2EA4}';
  IID__Parameter: TGUID = '{0000050C-0000-0010-8000-00AA006D2EA4}';
  IID_Parameters: TGUID = '{0000050D-0000-0010-8000-00AA006D2EA4}';
  IID__Command: TGUID = '{0000054E-0000-0010-8000-00AA006D2EA4}';
  IID_ConnectionEventsVt: TGUID = '{00000402-0000-0010-8000-00AA006D2EA4}';
  DIID_ConnectionEvents: TGUID = '{00000400-0000-0010-8000-00AA006D2EA4}';
  IID_RecordsetEventsVt: TGUID = '{00000403-0000-0010-8000-00AA006D2EA4}';
  DIID_RecordsetEvents: TGUID = '{00000266-0000-0010-8000-00AA006D2EA4}';
  IID_ADOConnectionConstruction15: TGUID = '{00000516-0000-0010-8000-00AA006D2EA4}';
  IID_ADOConnectionConstruction: TGUID = '{00000551-0000-0010-8000-00AA006D2EA4}';
  IID_ADOCommandConstruction: TGUID = '{00000517-0000-0010-8000-00AA006D2EA4}';
  IID_ADORecordsetConstruction: TGUID = '{00000283-0000-0010-8000-00AA006D2EA4}';
  IID_Field15: TGUID = '{00000505-0000-0010-8000-00AA006D2EA4}';
  IID_IDataspace: TGUID = '{BD96C556-65A3-11D0-983A-00C04FC29E34}';

// *********************************************************************//
// Misc. Constants (not from Type Library)                              //
// *********************************************************************//

// ConnectionString Tags
const
  CT_USERID = 'USER ID=';     { Do not localize }
  CT_PROVIDER = 'PROVIDER=';  { Do not localize }
  CT_FILENAME = 'FILE NAME='; { Do not localize }

// *********************************************************************//
// Declaration of Enumerations defined in Type Library                  //
// *********************************************************************//

// CursorTypeEnum constants
type
  CursorTypeEnum = TOleEnum;
  {$EXTERNALSYM CursorTypeEnum}
const
  adOpenUnspecified = -1;
  {$EXTERNALSYM adOpenUnspecified}
  adOpenForwardOnly = $00000000;
  {$EXTERNALSYM adOpenForwardOnly}
  adOpenKeyset = $00000001;
  {$EXTERNALSYM adOpenKeyset}
  adOpenDynamic = $00000002;
  {$EXTERNALSYM adOpenDynamic}
  adOpenStatic = $00000003;
  {$EXTERNALSYM adOpenStatic}

// CursorOptionEnum constants
type
  CursorOptionEnum = TOleEnum;
  {$EXTERNALSYM CursorOptionEnum}
const
  adHoldRecords = $00000100;
  {$EXTERNALSYM adHoldRecords}
  adMovePrevious = $00000200;
  {$EXTERNALSYM adMovePrevious}
  adAddNew = $01000400;
  {$EXTERNALSYM adAddNew}
  adDelete = $01000800;
  {$EXTERNALSYM adDelete}
  adUpdate = $01008000;
  {$EXTERNALSYM adUpdate}
  adBookmark = $00002000;
  {$EXTERNALSYM adBookmark}
  adApproxPosition = $00004000;
  {$EXTERNALSYM adApproxPosition}
  adUpdateBatch = $00010000;
  {$EXTERNALSYM adUpdateBatch}
  adResync = $00020000;
  {$EXTERNALSYM adResync}
  adNotify = $00040000;
  {$EXTERNALSYM adNotify}
  adFind = $00080000;
  {$EXTERNALSYM adFind}
  adSeek = $00400000;
  {$EXTERNALSYM adSeek}
  adIndex = $00800000;
  {$EXTERNALSYM adIndex}

// LockTypeEnum constants
type
  LockTypeEnum = TOleEnum;
  {$EXTERNALSYM LockTypeEnum}
const
  adLockUnspecified = -1;
  {$EXTERNALSYM adLockUnspecified}
  adLockReadOnly = $00000001;
  {$EXTERNALSYM adLockReadOnly}
  adLockPessimistic = $00000002;
  {$EXTERNALSYM adLockPessimistic}
  adLockOptimistic = $00000003;
  {$EXTERNALSYM adLockOptimistic}
  adLockBatchOptimistic = $00000004;
  {$EXTERNALSYM adLockBatchOptimistic}

// ExecuteOptionEnum constants
type
  ExecuteOptionEnum = TOleEnum;
  {$EXTERNALSYM ExecuteOptionEnum}
const
  adOptionUnspecified = -1;
  {$EXTERNALSYM adOptionUnspecified}
  adAsyncExecute = $00000010;
  {$EXTERNALSYM adAsyncExecute}
  adAsyncFetch = $00000020;
  {$EXTERNALSYM adAsyncFetch}
  adAsyncFetchNonBlocking = $00000040;
  {$EXTERNALSYM adAsyncFetchNonBlocking}
  adExecuteNoRecords = $00000080;
  {$EXTERNALSYM adExecuteNoRecords}

// ConnectOptionEnum constants
type
  ConnectOptionEnum = TOleEnum;
  {$EXTERNALSYM ConnectOptionEnum}
const
  adConnectUnspecified = -1;
  {$EXTERNALSYM adConnectUnspecified}
  adAsyncConnect = $00000010;
  {$EXTERNALSYM adAsyncConnect}

// ObjectStateEnum constants
type
  ObjectStateEnum = TOleEnum;
  {$EXTERNALSYM ObjectStateEnum}
const
  adStateClosed = $00000000;
  {$EXTERNALSYM adStateClosed}
  adStateOpen = $00000001;
  {$EXTERNALSYM adStateOpen}
  adStateConnecting = $00000002;
  {$EXTERNALSYM adStateConnecting}
  adStateExecuting = $00000004;
  {$EXTERNALSYM adStateExecuting}
  adStateFetching = $00000008;
  {$EXTERNALSYM adStateFetching}

// CursorLocationEnum constants
type
  CursorLocationEnum = TOleEnum;
  {$EXTERNALSYM CursorLocationEnum}
const
  adUseNone = $00000001;
  {$EXTERNALSYM adUseNone}
  adUseServer = $00000002;
  {$EXTERNALSYM adUseServer}
  adUseClient = $00000003;
  {$EXTERNALSYM adUseClient}
  adUseClientBatch = $00000003;
  {$EXTERNALSYM adUseClientBatch}

// DataTypeEnum constants
type
  DataTypeEnum = TOleEnum;
  {$EXTERNALSYM DataTypeEnum}
const
  adEmpty = $00000000;
  {$EXTERNALSYM adEmpty}
  adTinyInt = $00000010;
  {$EXTERNALSYM adTinyInt}
  adSmallInt = $00000002;
  {$EXTERNALSYM adSmallInt}
  adInteger = $00000003;
  {$EXTERNALSYM adInteger}
  adBigInt = $00000014;
  {$EXTERNALSYM adBigInt}
  adUnsignedTinyInt = $00000011;
  {$EXTERNALSYM adUnsignedTinyInt}
  adUnsignedSmallInt = $00000012;
  {$EXTERNALSYM adUnsignedSmallInt}
  adUnsignedInt = $00000013;
  {$EXTERNALSYM adUnsignedInt}
  adUnsignedBigInt = $00000015;
  {$EXTERNALSYM adUnsignedBigInt}
  adSingle = $00000004;
  {$EXTERNALSYM adSingle}
  adDouble = $00000005;
  {$EXTERNALSYM adDouble}
  adCurrency = $00000006;
  {$EXTERNALSYM adCurrency}
  adDecimal = $0000000E;
  {$EXTERNALSYM adDecimal}
  adNumeric = $00000083;
  {$EXTERNALSYM adNumeric}
  adBoolean = $0000000B;
  {$EXTERNALSYM adBoolean}
  adError = $0000000A;
  {$EXTERNALSYM adError}
  adUserDefined = $00000084;
  {$EXTERNALSYM adUserDefined}
  adVariant = $0000000C;
  {$EXTERNALSYM adVariant}
  adIDispatch = $00000009;
  {$EXTERNALSYM adIDispatch}
  adIUnknown = $0000000D;
  {$EXTERNALSYM adIUnknown}
  adGUID = $00000048;
  {$EXTERNALSYM adGUID}
  adDate = $00000007;
  {$EXTERNALSYM adDate}
  adDBDate = $00000085;
  {$EXTERNALSYM adDBDate}
  adDBTime = $00000086;
  {$EXTERNALSYM adDBTime}
  adDBTimeStamp = $00000087;
  {$EXTERNALSYM adDBTimeStamp}
  adBSTR = $00000008;
  {$EXTERNALSYM adBSTR}
  adChar = $00000081;
  {$EXTERNALSYM adChar}
  adVarChar = $000000C8;
  {$EXTERNALSYM adVarChar}
  adLongVarChar = $000000C9;
  {$EXTERNALSYM adLongVarChar}
  adWChar = $00000082;
  {$EXTERNALSYM adWChar}
  adVarWChar = $000000CA;
  {$EXTERNALSYM adVarWChar}
  adLongVarWChar = $000000CB;
  {$EXTERNALSYM adLongVarWChar}
  adBinary = $00000080;
  {$EXTERNALSYM adBinary}
  adVarBinary = $000000CC;
  {$EXTERNALSYM adVarBinary}
  adLongVarBinary = $000000CD;
  {$EXTERNALSYM adLongVarBinary}
  adChapter = $00000088;
  {$EXTERNALSYM adChapter}
  adFileTime = $00000040;
  {$EXTERNALSYM adFileTime}
  adDBFileTime = $00000089;
  {$EXTERNALSYM adDBFileTime}
  adPropVariant = $0000008A;
  {$EXTERNALSYM adPropVariant}
  adVarNumeric = $0000008B;
  {$EXTERNALSYM adVarNumeric}

// FieldAttributeEnum constants
type
  FieldAttributeEnum = TOleEnum;
  {$EXTERNALSYM FieldAttributeEnum}
const
  adFldUnspecified = -1;
  {$EXTERNALSYM adFldUnspecified}
  adFldMayDefer = $00000002;
  {$EXTERNALSYM adFldMayDefer}
  adFldUpdatable = $00000004;
  {$EXTERNALSYM adFldUpdatable}
  adFldUnknownUpdatable = $00000008;
  {$EXTERNALSYM adFldUnknownUpdatable}
  adFldFixed = $00000010;
  {$EXTERNALSYM adFldFixed}
  adFldIsNullable = $00000020;
  {$EXTERNALSYM adFldIsNullable}
  adFldMayBeNull = $00000040;
  {$EXTERNALSYM adFldMayBeNull}
  adFldLong = $00000080;
  {$EXTERNALSYM adFldLong}
  adFldRowID = $00000100;
  {$EXTERNALSYM adFldRowID}
  adFldRowVersion = $00000200;
  {$EXTERNALSYM adFldRowVersion}
  adFldCacheDeferred = $00001000;
  {$EXTERNALSYM adFldCacheDeferred}
  adFldNegativeScale = $00004000;
  {$EXTERNALSYM adFldNegativeScale}
  adFldKeyColumn = $00008000;
  {$EXTERNALSYM adFldKeyColumn}

// EditModeEnum constants
type
  EditModeEnum = TOleEnum;
  {$EXTERNALSYM EditModeEnum}
const
  adEditNone = $00000000;
  {$EXTERNALSYM adEditNone}
  adEditInProgress = $00000001;
  {$EXTERNALSYM adEditInProgress}
  adEditAdd = $00000002;
  {$EXTERNALSYM adEditAdd}
  adEditDelete = $00000004;
  {$EXTERNALSYM adEditDelete}

// RecordStatusEnum constants
type
  RecordStatusEnum = TOleEnum;
  {$EXTERNALSYM RecordStatusEnum}
const
  adRecOK = $00000000;
  {$EXTERNALSYM adRecOK}
  adRecNew = $00000001;
  {$EXTERNALSYM adRecNew}
  adRecModified = $00000002;
  {$EXTERNALSYM adRecModified}
  adRecDeleted = $00000004;
  {$EXTERNALSYM adRecDeleted}
  adRecUnmodified = $00000008;
  {$EXTERNALSYM adRecUnmodified}
  adRecInvalid = $00000010;
  {$EXTERNALSYM adRecInvalid}
  adRecMultipleChanges = $00000040;
  {$EXTERNALSYM adRecMultipleChanges}
  adRecPendingChanges = $00000080;
  {$EXTERNALSYM adRecPendingChanges}
  adRecCanceled = $00000100;
  {$EXTERNALSYM adRecCanceled}
  adRecCantRelease = $00000400;
  {$EXTERNALSYM adRecCantRelease}
  adRecConcurrencyViolation = $00000800;
  {$EXTERNALSYM adRecConcurrencyViolation}
  adRecIntegrityViolation = $00001000;
  {$EXTERNALSYM adRecIntegrityViolation}
  adRecMaxChangesExceeded = $00002000;
  {$EXTERNALSYM adRecMaxChangesExceeded}
  adRecObjectOpen = $00004000;
  {$EXTERNALSYM adRecObjectOpen}
  adRecOutOfMemory = $00008000;
  {$EXTERNALSYM adRecOutOfMemory}
  adRecPermissionDenied = $00010000;
  {$EXTERNALSYM adRecPermissionDenied}
  adRecSchemaViolation = $00020000;
  {$EXTERNALSYM adRecSchemaViolation}
  adRecDBDeleted = $00040000;
  {$EXTERNALSYM adRecDBDeleted}

// GetRowsOptionEnum constants
type
  GetRowsOptionEnum = TOleEnum;
  {$EXTERNALSYM GetRowsOptionEnum}
const
  adGetRowsRest = -1;
  {$EXTERNALSYM adGetRowsRest}

// PositionEnum constants
type
  PositionEnum = TOleEnum;
  {$EXTERNALSYM PositionEnum}
const
  adPosUnknown = -1;
  {$EXTERNALSYM adPosUnknown}
  adPosBOF = $FFFFFFFE;
  {$EXTERNALSYM adPosBOF}
  adPosEOF = $FFFFFFFD;
  {$EXTERNALSYM adPosEOF}

// BookmarkEnum constants
type
  BookmarkEnum = TOleEnum;
  {$EXTERNALSYM BookmarkEnum}
const
  adBookmarkCurrent = $00000000;
  {$EXTERNALSYM adBookmarkCurrent}
  adBookmarkFirst = $00000001;
  {$EXTERNALSYM adBookmarkFirst}
  adBookmarkLast = $00000002;
  {$EXTERNALSYM adBookmarkLast}

// MarshalOptionsEnum constants
type
  MarshalOptionsEnum = TOleEnum;
  {$EXTERNALSYM MarshalOptionsEnum}
const
  adMarshalAll = $00000000;
  {$EXTERNALSYM adMarshalAll}
  adMarshalModifiedOnly = $00000001;
  {$EXTERNALSYM adMarshalModifiedOnly}

// AffectEnum constants
type
  AffectEnum = TOleEnum;
  {$EXTERNALSYM AffectEnum}
const
  adAffectCurrent = $00000001;
  {$EXTERNALSYM adAffectCurrent}
  adAffectGroup = $00000002;
  {$EXTERNALSYM adAffectGroup}
  adAffectAll = $00000003;
  {$EXTERNALSYM adAffectAll}
  adAffectAllChapters = $00000004;
  {$EXTERNALSYM adAffectAllChapters}

// ResyncEnum constants
type
  ResyncEnum = TOleEnum;
  {$EXTERNALSYM ResyncEnum}
const
  adResyncUnderlyingValues = $00000001;
  {$EXTERNALSYM adResyncUnderlyingValues}
  adResyncAllValues = $00000002;
  {$EXTERNALSYM adResyncAllValues}

// CompareEnum constants
type
  CompareEnum = TOleEnum;
  {$EXTERNALSYM CompareEnum}
const
  adCompareLessThan = $00000000;
  {$EXTERNALSYM adCompareLessThan}
  adCompareEqual = $00000001;
  {$EXTERNALSYM adCompareEqual}
  adCompareGreaterThan = $00000002;
  {$EXTERNALSYM adCompareGreaterThan}
  adCompareNotEqual = $00000003;
  {$EXTERNALSYM adCompareNotEqual}
  adCompareNotComparable = $00000004;
  {$EXTERNALSYM adCompareNotComparable}

// FilterGroupEnum constants
type
  FilterGroupEnum = TOleEnum;
  {$EXTERNALSYM FilterGroupEnum}
const
  adFilterNone = $00000000;
  {$EXTERNALSYM adFilterNone}
  adFilterPendingRecords = $00000001;
  {$EXTERNALSYM adFilterPendingRecords}
  adFilterAffectedRecords = $00000002;
  {$EXTERNALSYM adFilterAffectedRecords}
  adFilterFetchedRecords = $00000003;
  {$EXTERNALSYM adFilterFetchedRecords}
  adFilterPredicate = $00000004;
  {$EXTERNALSYM adFilterPredicate}
  adFilterConflictingRecords = $00000005;
  {$EXTERNALSYM adFilterConflictingRecords}

// SearchDirectionEnum constants
type
  SearchDirectionEnum = TOleEnum;
  {$EXTERNALSYM SearchDirectionEnum}
const
  adSearchForward = $00000001;
  {$EXTERNALSYM adSearchForward}
  adSearchBackward = -1;
  {$EXTERNALSYM adSearchBackward}

// PersistFormatEnum constants
type
  PersistFormatEnum = TOleEnum;
  {$EXTERNALSYM PersistFormatEnum}
const
  adPersistADTG = $00000000;
  {$EXTERNALSYM adPersistADTG}
  adPersistXML = $00000001;
  {$EXTERNALSYM adPersistXML}

// StringFormatEnum constants
type
  StringFormatEnum = TOleEnum;
  {$EXTERNALSYM StringFormatEnum}
const
  adClipString = $00000002;
  {$EXTERNALSYM adClipString}

// ConnectPromptEnum constants
type
  ConnectPromptEnum = TOleEnum;
  {$EXTERNALSYM ConnectPromptEnum}
const
  adPromptAlways = $00000001;
  {$EXTERNALSYM adPromptAlways}
  adPromptComplete = $00000002;
  {$EXTERNALSYM adPromptComplete}
  adPromptCompleteRequired = $00000003;
  {$EXTERNALSYM adPromptCompleteRequired}
  adPromptNever = $00000004;
  {$EXTERNALSYM adPromptNever}

// ConnectModeEnum constants
type
  ConnectModeEnum = TOleEnum;
  {$EXTERNALSYM ConnectModeEnum}
const
  adModeUnknown = $00000000;
  {$EXTERNALSYM adModeUnknown}
  adModeRead = $00000001;
  {$EXTERNALSYM adModeRead}
  adModeWrite = $00000002;
  {$EXTERNALSYM adModeWrite}
  adModeReadWrite = $00000003;
  {$EXTERNALSYM adModeReadWrite}
  adModeShareDenyRead = $00000004;
  {$EXTERNALSYM adModeShareDenyRead}
  adModeShareDenyWrite = $00000008;
  {$EXTERNALSYM adModeShareDenyWrite}
  adModeShareExclusive = $0000000C;
  {$EXTERNALSYM adModeShareExclusive}
  adModeShareDenyNone = $00000010;
  {$EXTERNALSYM adModeShareDenyNone}

// IsolationLevelEnum constants
type
  IsolationLevelEnum = TOleEnum;
  {$EXTERNALSYM IsolationLevelEnum}
const
  adXactUnspecified = -1;
  {$EXTERNALSYM adXactUnspecified}
  adXactChaos = $00000010;
  {$EXTERNALSYM adXactChaos}
  adXactReadUncommitted = $00000100;
  {$EXTERNALSYM adXactReadUncommitted}
  adXactBrowse = $00000100;
  {$EXTERNALSYM adXactBrowse}
  adXactCursorStability = $00001000;
  {$EXTERNALSYM adXactCursorStability}
  adXactReadCommitted = $00001000;
  {$EXTERNALSYM adXactReadCommitted}
  adXactRepeatableRead = $00010000;
  {$EXTERNALSYM adXactRepeatableRead}
  adXactSerializable = $00100000;
  {$EXTERNALSYM adXactSerializable}
  adXactIsolated = $00100000;
  {$EXTERNALSYM adXactIsolated}

// XactAttributeEnum constants
type
  XactAttributeEnum = TOleEnum;
  {$EXTERNALSYM XactAttributeEnum}
const
  adXactCommitRetaining = $00020000;
  {$EXTERNALSYM adXactCommitRetaining}
  adXactAbortRetaining = $00040000;
  {$EXTERNALSYM adXactAbortRetaining}
  adXactAsyncPhaseOne = $00080000;
  {$EXTERNALSYM adXactAsyncPhaseOne}
  adXactSyncPhaseOne = $00100000;
  {$EXTERNALSYM adXactSyncPhaseOne}

// PropertyAttributesEnum constants
type
  PropertyAttributesEnum = TOleEnum;
  {$EXTERNALSYM PropertyAttributesEnum}
const
  adPropNotSupported = $00000000;
  {$EXTERNALSYM adPropNotSupported}
  adPropRequired = $00000001;
  {$EXTERNALSYM adPropRequired}
  adPropOptional = $00000002;
  {$EXTERNALSYM adPropOptional}
  adPropRead = $00000200;
  {$EXTERNALSYM adPropRead}
  adPropWrite = $00000400;
  {$EXTERNALSYM adPropWrite}

// ErrorValueEnum constants
type
  ErrorValueEnum = TOleEnum;
  {$EXTERNALSYM ErrorValueEnum}
const
  adErrInvalidArgument = $00000BB9;
  {$EXTERNALSYM adErrInvalidArgument}
  adErrNoCurrentRecord = $00000BCD;
  {$EXTERNALSYM adErrNoCurrentRecord}
  adErrIllegalOperation = $00000C93;
  {$EXTERNALSYM adErrIllegalOperation}
  adErrInTransaction = $00000CAE;
  {$EXTERNALSYM adErrInTransaction}
  adErrFeatureNotAvailable = $00000CB3;
  {$EXTERNALSYM adErrFeatureNotAvailable}
  adErrItemNotFound = $00000CC1;
  {$EXTERNALSYM adErrItemNotFound}
  adErrObjectInCollection = $00000D27;
  {$EXTERNALSYM adErrObjectInCollection}
  adErrObjectNotSet = $00000D5C;
  {$EXTERNALSYM adErrObjectNotSet}
  adErrDataConversion = $00000D5D;
  {$EXTERNALSYM adErrDataConversion}
  adErrObjectClosed = $00000E78;
  {$EXTERNALSYM adErrObjectClosed}
  adErrObjectOpen = $00000E79;
  {$EXTERNALSYM adErrObjectOpen}
  adErrProviderNotFound = $00000E7A;
  {$EXTERNALSYM adErrProviderNotFound}
  adErrBoundToCommand = $00000E7B;
  {$EXTERNALSYM adErrBoundToCommand}
  adErrInvalidParamInfo = $00000E7C;
  {$EXTERNALSYM adErrInvalidParamInfo}
  adErrInvalidConnection = $00000E7D;
  {$EXTERNALSYM adErrInvalidConnection}
  adErrNotReentrant = $00000E7E;
  {$EXTERNALSYM adErrNotReentrant}
  adErrStillExecuting = $00000E7F;
  {$EXTERNALSYM adErrStillExecuting}
  adErrOperationCancelled = $00000E80;
  {$EXTERNALSYM adErrOperationCancelled}
  adErrStillConnecting = $00000E81;
  {$EXTERNALSYM adErrStillConnecting}
  adErrNotExecuting = $00000E83;
  {$EXTERNALSYM adErrNotExecuting}
  adErrUnsafeOperation = $00000E84;
  {$EXTERNALSYM adErrUnsafeOperation}

// ParameterAttributesEnum constants
type
  ParameterAttributesEnum = TOleEnum;
  {$EXTERNALSYM ParameterAttributesEnum}
const
  adParamSigned = $00000010;
  {$EXTERNALSYM adParamSigned}
  adParamNullable = $00000040;
  {$EXTERNALSYM adParamNullable}
  adParamLong = $00000080;
  {$EXTERNALSYM adParamLong}

// ParameterDirectionEnum constants
type
  ParameterDirectionEnum = TOleEnum;
  {$EXTERNALSYM ParameterDirectionEnum}
const
  adParamUnknown = $00000000;
  {$EXTERNALSYM adParamUnknown}
  adParamInput = $00000001;
  {$EXTERNALSYM adParamInput}
  adParamOutput = $00000002;
  {$EXTERNALSYM adParamOutput}
  adParamInputOutput = $00000003;
  {$EXTERNALSYM adParamInputOutput}
  adParamReturnValue = $00000004;
  {$EXTERNALSYM adParamReturnValue}

// CommandTypeEnum constants
type
  CommandTypeEnum = TOleEnum;
  {$EXTERNALSYM CommandTypeEnum}
const
  adCmdUnspecified = -1;
  {$EXTERNALSYM adCmdUnspecified}
  adCmdUnknown = $00000008;
  {$EXTERNALSYM adCmdUnknown}
  adCmdText = $00000001;
  {$EXTERNALSYM adCmdText}
  adCmdTable = $00000002;
  {$EXTERNALSYM adCmdTable}
  adCmdStoredProc = $00000004;
  {$EXTERNALSYM adCmdStoredProc}
  adCmdFile = $00000100;
  {$EXTERNALSYM adCmdFile}
  adCmdTableDirect = $00000200;
  {$EXTERNALSYM adCmdTableDirect}

// EventStatusEnum constants
type
  EventStatusEnum = TOleEnum;
  {$EXTERNALSYM EventStatusEnum}
const
  adStatusOK = $00000001;
  {$EXTERNALSYM adStatusOK}
  adStatusErrorsOccurred = $00000002;
  {$EXTERNALSYM adStatusErrorsOccurred}
  adStatusCantDeny = $00000003;
  {$EXTERNALSYM adStatusCantDeny}
  adStatusCancel = $00000004;
  {$EXTERNALSYM adStatusCancel}
  adStatusUnwantedEvent = $00000005;
  {$EXTERNALSYM adStatusUnwantedEvent}

// EventReasonEnum constants
type
  EventReasonEnum = TOleEnum;
  {$EXTERNALSYM EventReasonEnum}
const
  adRsnAddNew = $00000001;
  {$EXTERNALSYM adRsnAddNew}
  adRsnDelete = $00000002;
  {$EXTERNALSYM adRsnDelete}
  adRsnUpdate = $00000003;
  {$EXTERNALSYM adRsnUpdate}
  adRsnUndoUpdate = $00000004;
  {$EXTERNALSYM adRsnUndoUpdate}
  adRsnUndoAddNew = $00000005;
  {$EXTERNALSYM adRsnUndoAddNew}
  adRsnUndoDelete = $00000006;
  {$EXTERNALSYM adRsnUndoDelete}
  adRsnRequery = $00000007;
  {$EXTERNALSYM adRsnRequery}
  adRsnResynch = $00000008;
  {$EXTERNALSYM adRsnResynch}
  adRsnClose = $00000009;
  {$EXTERNALSYM adRsnClose}
  adRsnMove = $0000000A;
  {$EXTERNALSYM adRsnMove}
  adRsnFirstChange = $0000000B;
  {$EXTERNALSYM adRsnFirstChange}
  adRsnMoveFirst = $0000000C;
  {$EXTERNALSYM adRsnMoveFirst}
  adRsnMoveNext = $0000000D;
  {$EXTERNALSYM adRsnMoveNext}
  adRsnMovePrevious = $0000000E;
  {$EXTERNALSYM adRsnMovePrevious}
  adRsnMoveLast = $0000000F;
  {$EXTERNALSYM adRsnMoveLast}

// SchemaEnum constants
type
  SchemaEnum = TOleEnum;
  {$EXTERNALSYM SchemaEnum}
const
  adSchemaProviderSpecific = -1;
  {$EXTERNALSYM adSchemaProviderSpecific}
  adSchemaAsserts = $00000000;
  {$EXTERNALSYM adSchemaAsserts}
  adSchemaCatalogs = $00000001;
  {$EXTERNALSYM adSchemaCatalogs}
  adSchemaCharacterSets = $00000002;
  {$EXTERNALSYM adSchemaCharacterSets}
  adSchemaCollations = $00000003;
  {$EXTERNALSYM adSchemaCollations}
  adSchemaColumns = $00000004;
  {$EXTERNALSYM adSchemaColumns}
  adSchemaCheckConstraints = $00000005;
  {$EXTERNALSYM adSchemaCheckConstraints}
  adSchemaConstraintColumnUsage = $00000006;
  {$EXTERNALSYM adSchemaConstraintColumnUsage}
  adSchemaConstraintTableUsage = $00000007;
  {$EXTERNALSYM adSchemaConstraintTableUsage}
  adSchemaKeyColumnUsage = $00000008;
  {$EXTERNALSYM adSchemaKeyColumnUsage}
  adSchemaReferentialConstraints = $00000009;
  {$EXTERNALSYM adSchemaReferentialConstraints}
  adSchemaTableConstraints = $0000000A;
  {$EXTERNALSYM adSchemaTableConstraints}
  adSchemaColumnsDomainUsage = $0000000B;
  {$EXTERNALSYM adSchemaColumnsDomainUsage}
  adSchemaIndexes = $0000000C;
  {$EXTERNALSYM adSchemaIndexes}
  adSchemaColumnPrivileges = $0000000D;
  {$EXTERNALSYM adSchemaColumnPrivileges}
  adSchemaTablePrivileges = $0000000E;
  {$EXTERNALSYM adSchemaTablePrivileges}
  adSchemaUsagePrivileges = $0000000F;
  {$EXTERNALSYM adSchemaUsagePrivileges}
  adSchemaProcedures = $00000010;
  {$EXTERNALSYM adSchemaProcedures}
  adSchemaSchemata = $00000011;
  {$EXTERNALSYM adSchemaSchemata}
  adSchemaSQLLanguages = $00000012;
  {$EXTERNALSYM adSchemaSQLLanguages}
  adSchemaStatistics = $00000013;
  {$EXTERNALSYM adSchemaStatistics}
  adSchemaTables = $00000014;
  {$EXTERNALSYM adSchemaTables}
  adSchemaTranslations = $00000015;
  {$EXTERNALSYM adSchemaTranslations}
  adSchemaProviderTypes = $00000016;
  {$EXTERNALSYM adSchemaProviderTypes}
  adSchemaViews = $00000017;
  {$EXTERNALSYM adSchemaViews}
  adSchemaViewColumnUsage = $00000018;
  {$EXTERNALSYM adSchemaViewColumnUsage}
  adSchemaViewTableUsage = $00000019;
  {$EXTERNALSYM adSchemaViewTableUsage}
  adSchemaProcedureParameters = $0000001A;
  {$EXTERNALSYM adSchemaProcedureParameters}
  adSchemaForeignKeys = $0000001B;
  {$EXTERNALSYM adSchemaForeignKeys}
  adSchemaPrimaryKeys = $0000001C;
  {$EXTERNALSYM adSchemaPrimaryKeys}
  adSchemaProcedureColumns = $0000001D;
  {$EXTERNALSYM adSchemaProcedureColumns}
  adSchemaDBInfoKeywords = $0000001E;
  {$EXTERNALSYM adSchemaDBInfoKeywords}
  adSchemaDBInfoLiterals = $0000001F;
  {$EXTERNALSYM adSchemaDBInfoLiterals}
  adSchemaCubes = $00000020;
  {$EXTERNALSYM adSchemaCubes}
  adSchemaDimensions = $00000021;
  {$EXTERNALSYM adSchemaDimensions}
  adSchemaHierarchies = $00000022;
  {$EXTERNALSYM adSchemaHierarchies}
  adSchemaLevels = $00000023;
  {$EXTERNALSYM adSchemaLevels}
  adSchemaMeasures = $00000024;
  {$EXTERNALSYM adSchemaMeasures}
  adSchemaProperties = $00000025;
  {$EXTERNALSYM adSchemaProperties}
  adSchemaMembers = $00000026;
  {$EXTERNALSYM adSchemaMembers}
  adSchemaTrustees = $00000027;
  {$EXTERNALSYM adSchemaTrustees}

// SeekEnum constants
type
  SeekEnum = TOleEnum;
  {$EXTERNALSYM SeekEnum}
const
  adSeekFirstEQ = $00000001;
  {$EXTERNALSYM adSeekFirstEQ}
  adSeekLastEQ = $00000002;
  {$EXTERNALSYM adSeekLastEQ}
  adSeekAfterEQ = $00000004;
  {$EXTERNALSYM adSeekAfterEQ}
  adSeekAfter = $00000008;
  {$EXTERNALSYM adSeekAfter}
  adSeekBeforeEQ = $00000010;
  {$EXTERNALSYM adSeekBeforeEQ}
  adSeekBefore = $00000020;
  {$EXTERNALSYM adSeekBefore}

// ADCPROP_UPDATECRITERIA_ENUM constants
type
  ADCPROP_UPDATECRITERIA_ENUM = TOleEnum;
  {$EXTERNALSYM ADCPROP_UPDATECRITERIA_ENUM}
const
  adCriteriaKey = $00000000;
  {$EXTERNALSYM adCriteriaKey}
  adCriteriaAllCols = $00000001;
  {$EXTERNALSYM adCriteriaAllCols}
  adCriteriaUpdCols = $00000002;
  {$EXTERNALSYM adCriteriaUpdCols}
  adCriteriaTimeStamp = $00000003;
  {$EXTERNALSYM adCriteriaTimeStamp}

// ADCPROP_ASYNCTHREADPRIORITY_ENUM constants
type
  ADCPROP_ASYNCTHREADPRIORITY_ENUM = TOleEnum;
  {$EXTERNALSYM ADCPROP_ASYNCTHREADPRIORITY_ENUM}
const
  adPriorityLowest = $00000001;
  {$EXTERNALSYM adPriorityLowest}
  adPriorityBelowNormal = $00000002;
  {$EXTERNALSYM adPriorityBelowNormal}
  adPriorityNormal = $00000003;
  {$EXTERNALSYM adPriorityNormal}
  adPriorityAboveNormal = $00000004;
  {$EXTERNALSYM adPriorityAboveNormal}
  adPriorityHighest = $00000005;
  {$EXTERNALSYM adPriorityHighest}

// CEResyncEnum constants
type
  CEResyncEnum = TOleEnum;
  {$EXTERNALSYM CEResyncEnum}
const
  adResyncNone = $00000000;
  {$EXTERNALSYM adResyncNone}
  adResyncAutoIncrement = $00000001;
  {$EXTERNALSYM adResyncAutoIncrement}
  adResyncConflicts = $00000002;
  {$EXTERNALSYM adResyncConflicts}
  adResyncUpdates = $00000004;
  {$EXTERNALSYM adResyncUpdates}
  adResyncInserts = $00000008;
  {$EXTERNALSYM adResyncInserts}
  adResyncAll = $0000000F;
  {$EXTERNALSYM adResyncAll}

// ADCPROP_AUTORECALC_ENUM constants
type
  ADCPROP_AUTORECALC_ENUM = TOleEnum;
  {$EXTERNALSYM ADCPROP_AUTORECALC_ENUM}
const
  adRecalcUpFront = $00000000;
  {$EXTERNALSYM adRecalcUpFront}
  adRecalcAlways = $00000001;
  {$EXTERNALSYM adRecalcAlways}

type

// *********************************************************************//
// Forward declaration of interfaces defined in Type Library            //
// *********************************************************************//

  _Collection = interface;
  _CollectionDisp = dispinterface;

  _DynaCollection = interface;
  _DynaCollectionDisp = dispinterface;

  _ADO = interface;
  _ADODisp = dispinterface;

  Properties = interface;
  PropertiesDisp = dispinterface;

  Property_ = interface;
  Property_Disp = dispinterface;

  Error = interface;
  ErrorDisp = dispinterface;

  Errors = interface;
  ErrorsDisp = dispinterface;

  Command15 = interface;
  Command15Disp = dispinterface;

  Connection15 = interface;
  Connection15Disp = dispinterface;

  _Connection = interface;
  _ConnectionDisp = dispinterface;

  Recordset15 = interface;
  Recordset15Disp = dispinterface;

  Recordset20 = interface;
  Recordset20Disp = dispinterface;

  _Recordset = interface;
  _RecordsetDisp = dispinterface;

  Fields15 = interface;
  Fields15Disp = dispinterface;

  Fields = interface;
  FieldsDisp = dispinterface;

  Field = interface;
  FieldDisp = dispinterface;

  _Parameter = interface;
  _ParameterDisp = dispinterface;

  Parameters = interface;
  ParametersDisp = dispinterface;

  _Command = interface;
  _CommandDisp = dispinterface;

  ConnectionEventsVt = interface;
  RecordsetEventsVt = interface;

  ConnectionEvents = dispinterface;
  RecordsetEvents = dispinterface;

  ADOConnectionConstruction15 = interface;
  ADOConnectionConstruction = interface;

  ADOCommandConstruction = interface;
  ADORecordsetConstruction = interface;

  Field15 = interface;
  Field15Disp = dispinterface;

  IDataspace = interface;
  IDataspaceDisp = dispinterface;

// *********************************************************************//
// Declaration of structures, unions and aliases.                       //
// *********************************************************************//

  SearchDirection = SearchDirectionEnum;
  {$EXTERNALSYM SearchDirection}
  
// *********************************************************************//
// Interface: _Collection
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000512-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _Collection = interface(IDispatch)
    ['{00000512-0000-0010-8000-00AA006D2EA4}']
    function Get_Count: Integer; safecall;
    function _NewEnum: IUnknown; safecall;
    procedure Refresh; safecall;
    property Count: Integer read Get_Count;
  end;

// *********************************************************************//
// DispIntf:  _CollectionDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000512-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _CollectionDisp = dispinterface
    ['{00000512-0000-0010-8000-00AA006D2EA4}']
    property Count: Integer readonly dispid 1610743808;
    function _NewEnum: IUnknown; dispid -4;
    procedure Refresh; dispid 1610743810;
  end;

// *********************************************************************//
// Interface: _DynaCollection
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000513-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _DynaCollection = interface(_Collection)
    ['{00000513-0000-0010-8000-00AA006D2EA4}']
    procedure Append(const Object_: IDispatch); safecall;
    procedure Delete(Index: OleVariant); safecall;
  end;

// *********************************************************************//
// DispIntf:  _DynaCollectionDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000513-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _DynaCollectionDisp = dispinterface
    ['{00000513-0000-0010-8000-00AA006D2EA4}']
    procedure Append(const Object_: IDispatch); dispid 1610809344;
    procedure Delete(Index: OleVariant); dispid 1610809345;
    property Count: Integer readonly dispid 1610743808;
    function _NewEnum: IUnknown; dispid -4;
    procedure Refresh; dispid 1610743810;
  end;

// *********************************************************************//
// Interface: _ADO
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000534-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _ADO = interface(IDispatch)
    ['{00000534-0000-0010-8000-00AA006D2EA4}']
    function Get_Properties: Properties; safecall;
    property Properties: Properties read Get_Properties;
  end;

// *********************************************************************//
// DispIntf:  _ADODisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000534-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _ADODisp = dispinterface
    ['{00000534-0000-0010-8000-00AA006D2EA4}']
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: Properties
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000504-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Properties = interface(_Collection)
    ['{00000504-0000-0010-8000-00AA006D2EA4}']
    function Get_Item(Index: OleVariant): Property_; safecall;
    property Item[Index: OleVariant]: Property_ read Get_Item; default;
  end;

// *********************************************************************//
// DispIntf:  PropertiesDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000504-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  PropertiesDisp = dispinterface
    ['{00000504-0000-0010-8000-00AA006D2EA4}']
    property Item[Index: OleVariant]: Property_ readonly dispid 0; default;
    property Count: Integer readonly dispid 1610743808;
    function _NewEnum: IUnknown; dispid -4;
    procedure Refresh; dispid 1610743810;
  end;

// *********************************************************************//
// Interface: Property_
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000503-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Property_ = interface(IDispatch)
    ['{00000503-0000-0010-8000-00AA006D2EA4}']
    function Get_Value: OleVariant; safecall;
    procedure Set_Value(pval: OleVariant); safecall;
    function Get_Name: WideString; safecall;
    function Get_Type_: DataTypeEnum; safecall;
    function Get_Attributes: Integer; safecall;
    procedure Set_Attributes(plAttributes: Integer); safecall;
    property Value: OleVariant read Get_Value write Set_Value;
    property Name: WideString read Get_Name;
    property Type_: DataTypeEnum read Get_Type_;
    property Attributes: Integer read Get_Attributes write Set_Attributes;
  end;

// *********************************************************************//
// DispIntf:  Property_Disp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000503-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Property_Disp = dispinterface
    ['{00000503-0000-0010-8000-00AA006D2EA4}']
    property Value: OleVariant dispid 0;
    property Name: WideString readonly dispid 1610743810;
    property Type_: DataTypeEnum readonly dispid 1610743811;
    property Attributes: Integer dispid 1610743812;
  end;

// *********************************************************************//
// Interface: Error
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000500-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Error = interface(IDispatch)
    ['{00000500-0000-0010-8000-00AA006D2EA4}']
    function Get_Number: Integer; safecall;
    function Get_Source: WideString; safecall;
    function Get_Description: WideString; safecall;
    function Get_HelpFile: WideString; safecall;
    function Get_HelpContext: Integer; safecall;
    function Get_SQLState: WideString; safecall;
    function Get_NativeError: Integer; safecall;
    property Number: Integer read Get_Number;
    property Source: WideString read Get_Source;
    property Description: WideString read Get_Description;
    property HelpFile: WideString read Get_HelpFile;
    property HelpContext: Integer read Get_HelpContext;
    property SQLState: WideString read Get_SQLState;
    property NativeError: Integer read Get_NativeError;
  end;

// *********************************************************************//
// DispIntf:  ErrorDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000500-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  ErrorDisp = dispinterface
    ['{00000500-0000-0010-8000-00AA006D2EA4}']
    property Number: Integer readonly dispid 1610743808;
    property Source: WideString readonly dispid 1610743809;
    property Description: WideString readonly dispid 0;
    property HelpFile: WideString readonly dispid 1610743811;
    property HelpContext: Integer readonly dispid 1610743812;
    property SQLState: WideString readonly dispid 1610743813;
    property NativeError: Integer readonly dispid 1610743814;
  end;

// *********************************************************************//
// Interface: Errors
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000501-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Errors = interface(_Collection)
    ['{00000501-0000-0010-8000-00AA006D2EA4}']
    function Get_Item(Index: OleVariant): Error; safecall;
    procedure Clear; safecall;
    property Item[Index: OleVariant]: Error read Get_Item; default;
  end;

// *********************************************************************//
// DispIntf:  ErrorsDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000501-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  ErrorsDisp = dispinterface
    ['{00000501-0000-0010-8000-00AA006D2EA4}']
    property Item[Index: OleVariant]: Error readonly dispid 0; default;
    procedure Clear; dispid 1610809345;
    property Count: Integer readonly dispid 1610743808;
    function _NewEnum: IUnknown; dispid -4;
    procedure Refresh; dispid 1610743810;
  end;

// *********************************************************************//
// Interface: Command15
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000508-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Command15 = interface(_ADO)
    ['{00000508-0000-0010-8000-00AA006D2EA4}']
    function Get_ActiveConnection: _Connection; safecall;
    procedure Set_ActiveConnection(const ppvObject: _Connection); safecall;
    procedure _Set_ActiveConnection(ppvObject: OleVariant); safecall;
    function Get_CommandText: WideString; safecall;
    procedure Set_CommandText(const pbstr: WideString); safecall;
    function Get_CommandTimeout: Integer; safecall;
    procedure Set_CommandTimeout(pl: Integer); safecall;
    function Get_Prepared: WordBool; safecall;
    procedure Set_Prepared(pfPrepared: WordBool); safecall;
    function Execute(out RecordsAffected: OleVariant; const Parameters: OleVariant; Options: Integer): _Recordset; safecall;
    function CreateParameter(const Name: WideString; Type_: DataTypeEnum; 
      Direction: ParameterDirectionEnum; Size: Integer; Value: OleVariant): _Parameter; safecall;
    function Get_Parameters: Parameters; safecall;
    procedure Set_CommandType(plCmdType: CommandTypeEnum); safecall;
    function Get_CommandType: CommandTypeEnum; safecall;
    function Get_Name: WideString; safecall;
    procedure Set_Name(const pbstrName: WideString); safecall;
    property CommandText: WideString read Get_CommandText write Set_CommandText;
    property CommandTimeout: Integer read Get_CommandTimeout write Set_CommandTimeout;
    property Prepared: WordBool read Get_Prepared write Set_Prepared;
    property Parameters: Parameters read Get_Parameters;
    property CommandType: CommandTypeEnum read Get_CommandType write Set_CommandType;
    property Name: WideString read Get_Name write Set_Name;
  end;

// *********************************************************************//
// DispIntf:  Command15Disp
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000508-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Command15Disp = dispinterface
    ['{00000508-0000-0010-8000-00AA006D2EA4}']
    function ActiveConnection: _Connection; dispid 1610809344;
    property CommandText: WideString dispid 1610809347;
    property CommandTimeout: Integer dispid 1610809349;
    property Prepared: WordBool dispid 1610809351;
    function Execute(out RecordsAffected: OleVariant; const Parameters: OleVariant; Options: Integer): _Recordset; dispid 1610809353;
    function CreateParameter(const Name: WideString; Type_: DataTypeEnum; 
      Direction: ParameterDirectionEnum; Size: Integer; Value: OleVariant): _Parameter; dispid 1610809354;
    property Parameters: Parameters readonly dispid 0;
    property CommandType: CommandTypeEnum dispid 1610809356;
    property Name: WideString dispid 1610809358;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: Connection15
// Flags:     (4432) Hidden Dual OleAutomation Dispatchable
// GUID:      {00000515-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Connection15 = interface(_ADO)
    ['{00000515-0000-0010-8000-00AA006D2EA4}']
    function Get_ConnectionString: WideString; safecall;
    procedure Set_ConnectionString(const pbstr: WideString); safecall;
    function Get_CommandTimeout: Integer; safecall;
    procedure Set_CommandTimeout(plTimeout: Integer); safecall;
    function Get_ConnectionTimeout: Integer; safecall;
    procedure Set_ConnectionTimeout(plTimeout: Integer); safecall;
    function Get_Version: WideString; safecall;
    procedure Close; safecall;
    function Execute(const CommandText: WideString; out RecordsAffected: OleVariant;
      Options: Integer): _Recordset; safecall;
    function BeginTrans: Integer; safecall;
    procedure CommitTrans; safecall;
    procedure RollbackTrans; safecall;
    procedure Open(const ConnectionString: WideString; const UserID: WideString;
      const Password: WideString; Options: Integer); safecall;
    function Get_Errors: Errors; safecall;
    function Get_DefaultDatabase: WideString; safecall;
    procedure Set_DefaultDatabase(const pbstr: WideString); safecall;
    function Get_IsolationLevel: IsolationLevelEnum; safecall;
    procedure Set_IsolationLevel(Level: IsolationLevelEnum); safecall;
    function Get_Attributes: Integer; safecall;
    procedure Set_Attributes(plAttr: Integer); safecall;
    function Get_CursorLocation: CursorLocationEnum; safecall;
    procedure Set_CursorLocation(plCursorLoc: CursorLocationEnum); safecall;
    function Get_Mode: ConnectModeEnum; safecall;
    procedure Set_Mode(plMode: ConnectModeEnum); safecall;
    function Get_Provider: WideString; safecall;
    procedure Set_Provider(const pbstr: WideString); safecall;
    function Get_State: Integer; safecall;
    function OpenSchema(Schema: SchemaEnum; Restrictions: OleVariant; SchemaID: OleVariant): _Recordset; safecall;
    property ConnectionString: WideString read Get_ConnectionString write Set_ConnectionString;
    property CommandTimeout: Integer read Get_CommandTimeout write Set_CommandTimeout;
    property ConnectionTimeout: Integer read Get_ConnectionTimeout write Set_ConnectionTimeout;
    property Version: WideString read Get_Version;
    property Errors: Errors read Get_Errors;
    property DefaultDatabase: WideString read Get_DefaultDatabase write Set_DefaultDatabase;
    property IsolationLevel: IsolationLevelEnum read Get_IsolationLevel write Set_IsolationLevel;
    property Attributes: Integer read Get_Attributes write Set_Attributes;
    property CursorLocation: CursorLocationEnum read Get_CursorLocation write Set_CursorLocation;
    property Mode: ConnectModeEnum read Get_Mode write Set_Mode;
    property Provider: WideString read Get_Provider write Set_Provider;
    property State: Integer read Get_State;
  end;

// *********************************************************************//
// DispIntf:  Connection15Disp
// Flags:     (4432) Hidden Dual OleAutomation Dispatchable
// GUID:      {00000515-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Connection15Disp = dispinterface
    ['{00000515-0000-0010-8000-00AA006D2EA4}']
    property ConnectionString: WideString dispid 0;
    property CommandTimeout: Integer dispid 2;
    property ConnectionTimeout: Integer dispid 3;
    property Version: WideString readonly dispid 4;
    procedure Close; dispid 5;
    function Execute(const CommandText: WideString; out RecordsAffected: OleVariant; 
      Options: Integer): _Recordset; dispid 6;
    function BeginTrans: Integer; dispid 7;
    procedure CommitTrans; dispid 8;
    procedure RollbackTrans; dispid 9;
    procedure Open(const ConnectionString: WideString; const UserID: WideString;
      const Password: WideString; Options: Integer); dispid 10;
    property Errors: Errors readonly dispid 11;
    property DefaultDatabase: WideString dispid 12;
    property IsolationLevel: IsolationLevelEnum dispid 13;
    property Attributes: Integer dispid 14;
    property CursorLocation: CursorLocationEnum dispid 15;
    property Mode: ConnectModeEnum dispid 16;
    property Provider: WideString dispid 17;
    property State: Integer readonly dispid 18;
    function OpenSchema(Schema: SchemaEnum; Restrictions: OleVariant; SchemaID: OleVariant): _Recordset; dispid 19;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: _Connection
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {00000550-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _Connection = interface(Connection15)
    ['{00000550-0000-0010-8000-00AA006D2EA4}']
    procedure Cancel; safecall;
  end;

// *********************************************************************//
// DispIntf:  _ConnectionDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {00000550-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _ConnectionDisp = dispinterface
    ['{00000550-0000-0010-8000-00AA006D2EA4}']
    procedure Cancel; dispid 21;
    property ConnectionString: WideString dispid 0;
    property CommandTimeout: Integer dispid 2;
    property ConnectionTimeout: Integer dispid 3;
    property Version: WideString readonly dispid 4;
    procedure Close; dispid 5;
    function Execute(const CommandText: WideString; out RecordsAffected: OleVariant;
      Options: Integer): _Recordset; dispid 6;
    function BeginTrans: Integer; dispid 7;
    procedure CommitTrans; dispid 8;
    procedure RollbackTrans; dispid 9;
    procedure Open(const ConnectionString: WideString; const UserID: WideString;
      const Password: WideString; Options: Integer); dispid 10;
    property Errors: Errors readonly dispid 11;
    property DefaultDatabase: WideString dispid 12;
    property IsolationLevel: IsolationLevelEnum dispid 13;
    property Attributes: Integer dispid 14;
    property CursorLocation: CursorLocationEnum dispid 15;
    property Mode: ConnectModeEnum dispid 16;
    property Provider: WideString dispid 17;
    property State: Integer readonly dispid 18;
    function OpenSchema(Schema: SchemaEnum; Restrictions: OleVariant; SchemaID: OleVariant): _Recordset; dispid 19;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: Recordset15
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000050E-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Recordset15 = interface(_ADO)
    ['{0000050E-0000-0010-8000-00AA006D2EA4}']
    function Get_AbsolutePosition: PositionEnum; safecall;
    procedure Set_AbsolutePosition(pl: PositionEnum); safecall;
    procedure Set_ActiveConnection(const pvar: IDispatch); safecall;
    procedure _Set_ActiveConnection(pvar: OleVariant); safecall;
    function Get_ActiveConnection: OleVariant; safecall;
    function Get_BOF: WordBool; safecall;
    function Get_Bookmark: OleVariant; safecall;
    procedure Set_Bookmark(pvBookmark: OleVariant); safecall;
    function Get_CacheSize: Integer; safecall;
    procedure Set_CacheSize(pl: Integer); safecall;
    function Get_CursorType: CursorTypeEnum; safecall;
    procedure Set_CursorType(plCursorType: CursorTypeEnum); safecall;
    function Get_EOF: WordBool; safecall;
    function Get_Fields: Fields; safecall;
    function Get_LockType: LockTypeEnum; safecall;
    procedure Set_LockType(plLockType: LockTypeEnum); safecall;
    function Get_MaxRecords: Integer; safecall;
    procedure Set_MaxRecords(plMaxRecords: Integer); safecall;
    function Get_RecordCount: Integer; safecall;
    procedure Set_Source(const pvSource: IDispatch); safecall;
    procedure _Set_Source(const pvSource: WideString); safecall;
    function Get_Source: OleVariant; safecall;
    procedure AddNew(FieldList: OleVariant; Values: OleVariant); safecall;
    procedure CancelUpdate; safecall;
    procedure Close; safecall;
    procedure Delete(AffectRecords: AffectEnum); safecall;
    function GetRows(Rows: Integer; Start: OleVariant; Fields: OleVariant): OleVariant; safecall;
    procedure Move(NumRecords: Integer; Start: OleVariant); safecall;
    procedure MoveNext; safecall;
    procedure MovePrevious; safecall;
    procedure MoveFirst; safecall;
    procedure MoveLast; safecall;
    procedure Open(Source: OleVariant; ActiveConnection: OleVariant; CursorType: CursorTypeEnum;
      LockType: LockTypeEnum; Options: Integer); safecall;
    procedure Requery(Options: Integer); safecall;
    procedure _xResync(AffectRecords: AffectEnum); safecall;
    procedure Update(Fields: OleVariant; Values: OleVariant); safecall;
    function Get_AbsolutePage: PositionEnum; safecall;
    procedure Set_AbsolutePage(pl: PositionEnum); safecall;
    function Get_EditMode: EditModeEnum; safecall;
    function Get_Filter: OleVariant; safecall;
    procedure Set_Filter(Criteria: OleVariant); safecall;
    function Get_PageCount: Integer; safecall;
    function Get_PageSize: Integer; safecall;
    procedure Set_PageSize(pl: Integer); safecall;
    function Get_Sort: WideString; safecall;
    procedure Set_Sort(const Criteria: WideString); safecall;
    function Get_Status: Integer; safecall;
    function Get_State: Integer; safecall;
    function _xClone: _Recordset; safecall;
    procedure UpdateBatch(AffectRecords: AffectEnum); safecall;
    procedure CancelBatch(AffectRecords: AffectEnum); safecall;
    function Get_CursorLocation: CursorLocationEnum; safecall;
    procedure Set_CursorLocation(plCursorLoc: CursorLocationEnum); safecall;
    function NextRecordset(out RecordsAffected: OleVariant): _Recordset; safecall;
    function Supports(CursorOptions: CursorOptionEnum): WordBool; safecall;
    function Get_Collect(Index: OleVariant): OleVariant; safecall;
    procedure Set_Collect(Index: OleVariant; pvar: OleVariant); safecall;
    function Get_MarshalOptions: MarshalOptionsEnum; safecall;
    procedure Set_MarshalOptions(peMarshal: MarshalOptionsEnum); safecall;
    procedure Find(const Criteria: WideString; SkipRecords: Integer;
      SearchDirection: SearchDirectionEnum; Start: OleVariant); safecall;
    property AbsolutePosition: PositionEnum read Get_AbsolutePosition write Set_AbsolutePosition;
    property BOF: WordBool read Get_BOF;
    property Bookmark: OleVariant read Get_Bookmark write Set_Bookmark;
    property CacheSize: Integer read Get_CacheSize write Set_CacheSize;
    property CursorType: CursorTypeEnum read Get_CursorType write Set_CursorType;
    property EOF: WordBool read Get_EOF;
    property Fields: Fields read Get_Fields;
    property LockType: LockTypeEnum read Get_LockType write Set_LockType;
    property MaxRecords: Integer read Get_MaxRecords write Set_MaxRecords;
    property RecordCount: Integer read Get_RecordCount;
    property AbsolutePage: PositionEnum read Get_AbsolutePage write Set_AbsolutePage;
    property EditMode: EditModeEnum read Get_EditMode;
    property Filter: OleVariant read Get_Filter write Set_Filter;
    property PageCount: Integer read Get_PageCount;
    property PageSize: Integer read Get_PageSize write Set_PageSize;
    property Sort: WideString read Get_Sort write Set_Sort;
    property Status: Integer read Get_Status;
    property State: Integer read Get_State;
    property CursorLocation: CursorLocationEnum read Get_CursorLocation write Set_CursorLocation;
    property Collect[Index: OleVariant]: OleVariant read Get_Collect write Set_Collect;
    property MarshalOptions: MarshalOptionsEnum read Get_MarshalOptions write Set_MarshalOptions;
  end;

// *********************************************************************//
// DispIntf:  Recordset15Disp
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000050E-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Recordset15Disp = dispinterface
    ['{0000050E-0000-0010-8000-00AA006D2EA4}']
    property AbsolutePosition: PositionEnum dispid 1000;
    function ActiveConnection: IDispatch; dispid 1001;
    property BOF: WordBool readonly dispid 1002;
    property Bookmark: OleVariant dispid 1003;
    property CacheSize: Integer dispid 1004;
    property CursorType: CursorTypeEnum dispid 1005;
    property EOF: WordBool readonly dispid 1006;
    property Fields: Fields readonly dispid 0;
    property LockType: LockTypeEnum dispid 1008;
    property MaxRecords: Integer dispid 1009;
    property RecordCount: Integer readonly dispid 1010;
    function Source: IDispatch; dispid 1011;
    procedure AddNew(FieldList: OleVariant; Values: OleVariant); dispid 1012;
    procedure CancelUpdate; dispid 1013;
    procedure Close; dispid 1014;
    procedure Delete(AffectRecords: AffectEnum); dispid 1015;
    function GetRows(Rows: Integer; Start: OleVariant; Fields: OleVariant): OleVariant; dispid 1016;
    procedure Move(NumRecords: Integer; Start: OleVariant); dispid 1017;
    procedure MoveNext; dispid 1018;
    procedure MovePrevious; dispid 1019;
    procedure MoveFirst; dispid 1020;
    procedure MoveLast; dispid 1021;
    procedure Open(Source: OleVariant; ActiveConnection: OleVariant; CursorType: CursorTypeEnum;
      LockType: LockTypeEnum; Options: Integer); dispid 1022;
    procedure Requery(Options: Integer); dispid 1023;
    procedure _xResync(AffectRecords: AffectEnum); dispid 1610809378;
    procedure Update(Fields: OleVariant; Values: OleVariant); dispid 1025;
    property AbsolutePage: PositionEnum dispid 1047;
    property EditMode: EditModeEnum readonly dispid 1026;
    property Filter: OleVariant dispid 1030;
    property PageCount: Integer readonly dispid 1050;
    property PageSize: Integer dispid 1048;
    property Sort: WideString dispid 1031;
    property Status: Integer readonly dispid 1029;
    property State: Integer readonly dispid 1054;
    function _xClone: _Recordset; dispid 1610809392;
    procedure UpdateBatch(AffectRecords: AffectEnum); dispid 1035;
    procedure CancelBatch(AffectRecords: AffectEnum); dispid 1049;
    property CursorLocation: CursorLocationEnum dispid 1051;
    function NextRecordset(out RecordsAffected: OleVariant): _Recordset; dispid 1052;
    function Supports(CursorOptions: CursorOptionEnum): WordBool; dispid 1036;
    property Collect[Index: OleVariant]: OleVariant dispid -8;
    property MarshalOptions: MarshalOptionsEnum dispid 1053;
    procedure Find(const Criteria: WideString; SkipRecords: Integer;
      SearchDirection: SearchDirectionEnum; Start: OleVariant); dispid 1058;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: Recordset20
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000054F-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Recordset20 = interface(Recordset15)
    ['{0000054F-0000-0010-8000-00AA006D2EA4}']
    procedure Cancel; safecall;
    function Get_DataSource: IUnknown; safecall;
    procedure Set_DataSource(const ppunkDataSource: IUnknown); safecall;
    procedure Save(const FileName: WideString; PersistFormat: PersistFormatEnum); safecall;
    function Get_ActiveCommand: IDispatch; safecall;
    procedure Set_StayInSync(pbStayInSync: WordBool); safecall;
    function Get_StayInSync: WordBool; safecall;
    function GetString(StringFormat: StringFormatEnum; NumRows: Integer; 
      const ColumnDelimeter: WideString; const RowDelimeter: WideString;
      const NullExpr: WideString): WideString; safecall;
    function Get_DataMember: WideString; safecall;
    procedure Set_DataMember(const pbstrDataMember: WideString); safecall;
    function CompareBookmarks(Bookmark1: OleVariant; Bookmark2: OleVariant): CompareEnum; safecall;
    function Clone(LockType: LockTypeEnum): _Recordset; safecall;
    procedure Resync(AffectRecords: AffectEnum; ResyncValues: ResyncEnum); safecall;
    property DataSource: IUnknown read Get_DataSource write Set_DataSource;
    property ActiveCommand: IDispatch read Get_ActiveCommand;
    property StayInSync: WordBool read Get_StayInSync write Set_StayInSync;
    property DataMember: WideString read Get_DataMember write Set_DataMember;
  end;

// *********************************************************************//
// DispIntf:  Recordset20Disp
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000054F-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Recordset20Disp = dispinterface
    ['{0000054F-0000-0010-8000-00AA006D2EA4}']
    procedure Cancel; dispid 1055;
    property DataSource: IUnknown dispid 1056;
    procedure Save(const FileName: WideString; PersistFormat: PersistFormatEnum); dispid 1057;
    property ActiveCommand: IDispatch readonly dispid 1061;
    property StayInSync: WordBool dispid 1063;
    function GetString(StringFormat: StringFormatEnum; NumRows: Integer;
      const ColumnDelimeter: WideString; const RowDelimeter: WideString;
      const NullExpr: WideString): WideString; dispid 1062;
    property DataMember: WideString dispid 1064;
    function CompareBookmarks(Bookmark1: OleVariant; Bookmark2: OleVariant): CompareEnum; dispid 1065;
    function Clone(LockType: LockTypeEnum): _Recordset; dispid 1034;
    procedure Resync(AffectRecords: AffectEnum; ResyncValues: ResyncEnum); dispid 1024;
    property AbsolutePosition: PositionEnum dispid 1000;
    function ActiveConnection: IDispatch; dispid 1001;
    property BOF: WordBool readonly dispid 1002;
    property Bookmark: OleVariant dispid 1003;
    property CacheSize: Integer dispid 1004;
    property CursorType: CursorTypeEnum dispid 1005;
    property EOF: WordBool readonly dispid 1006;
    property Fields: Fields readonly dispid 0;
    property LockType: LockTypeEnum dispid 1008;
    property MaxRecords: Integer dispid 1009;
    property RecordCount: Integer readonly dispid 1010;
    function Source: IDispatch; dispid 1011;
    procedure AddNew(FieldList: OleVariant; Values: OleVariant); dispid 1012;
    procedure CancelUpdate; dispid 1013;
    procedure Close; dispid 1014;
    procedure Delete(AffectRecords: AffectEnum); dispid 1015;
    function GetRows(Rows: Integer; Start: OleVariant; Fields: OleVariant): OleVariant; dispid 1016;
    procedure Move(NumRecords: Integer; Start: OleVariant); dispid 1017;
    procedure MoveNext; dispid 1018;
    procedure MovePrevious; dispid 1019;
    procedure MoveFirst; dispid 1020;
    procedure MoveLast; dispid 1021;
    procedure Open(Source: OleVariant; ActiveConnection: OleVariant; CursorType: CursorTypeEnum; 
      LockType: LockTypeEnum; Options: Integer); dispid 1022;
    procedure Requery(Options: Integer); dispid 1023;
    procedure _xResync(AffectRecords: AffectEnum); dispid 1610809378;
    procedure Update(Fields: OleVariant; Values: OleVariant); dispid 1025;
    property AbsolutePage: PositionEnum dispid 1047;
    property EditMode: EditModeEnum readonly dispid 1026;
    property Filter: OleVariant dispid 1030;
    property PageCount: Integer readonly dispid 1050;
    property PageSize: Integer dispid 1048;
    property Sort: WideString dispid 1031;
    property Status: Integer readonly dispid 1029;
    property State: Integer readonly dispid 1054;
    function _xClone: _Recordset; dispid 1610809392;
    procedure UpdateBatch(AffectRecords: AffectEnum); dispid 1035;
    procedure CancelBatch(AffectRecords: AffectEnum); dispid 1049;
    property CursorLocation: CursorLocationEnum dispid 1051;
    function NextRecordset(out RecordsAffected: OleVariant): _Recordset; dispid 1052;
    function Supports(CursorOptions: CursorOptionEnum): WordBool; dispid 1036;
    property Collect[Index: OleVariant]: OleVariant dispid -8;
    property MarshalOptions: MarshalOptionsEnum dispid 1053;
    procedure Find(const Criteria: WideString; SkipRecords: Integer; 
      SearchDirection: SearchDirectionEnum; Start: OleVariant); dispid 1058;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: Fields15
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000506-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Fields15 = interface(_Collection)
    ['{00000506-0000-0010-8000-00AA006D2EA4}']
    function Get_Item(Index: OleVariant): Field; safecall;
    property Item[Index: OleVariant]: Field read Get_Item; default;
  end;

// *********************************************************************//
// DispIntf:  Fields15Disp
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000506-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Fields15Disp = dispinterface
    ['{00000506-0000-0010-8000-00AA006D2EA4}']
    property Item[Index: OleVariant]: Field readonly dispid 0; default;
    property Count: Integer readonly dispid 1610743808;
    function _NewEnum: IUnknown; dispid -4;
    procedure Refresh; dispid 1610743810;
  end;

// *********************************************************************//
// Interface: Fields
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000054D-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Fields = interface(Fields15)
    ['{0000054D-0000-0010-8000-00AA006D2EA4}']
    procedure Append(const Name: WideString; Type_: DataTypeEnum; DefinedSize: Integer;
      Attrib: FieldAttributeEnum); safecall;
    procedure Delete(Index: OleVariant); safecall;
  end;

// *********************************************************************//
// DispIntf:  FieldsDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000054D-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  FieldsDisp = dispinterface
    ['{0000054D-0000-0010-8000-00AA006D2EA4}']
    procedure Append(const Name: WideString; Type_: DataTypeEnum;
      DefinedSize: Integer; Attrib: FieldAttributeEnum); dispid 1610874880;
    procedure Delete(Index: OleVariant); dispid 1610874881;
    property Item[Index: OleVariant]: Field readonly dispid 0; default;
    property Count: Integer readonly dispid 1610743808;
    function _NewEnum: IUnknown; dispid -4;
    procedure Refresh; dispid 1610743810;
  end;

// *********************************************************************//
// Interface: Field
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000054C-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Field = interface(_ADO)
    ['{0000054C-0000-0010-8000-00AA006D2EA4}']
    function Get_ActualSize: Integer; safecall;
    function Get_Attributes: Integer; safecall;
    function Get_DefinedSize: Integer; safecall;
    function Get_Name: WideString; safecall;
    function Get_Type_: DataTypeEnum; safecall;
    function Get_Value: OleVariant; safecall;
    procedure Set_Value(pvar: OleVariant); safecall;
    function Get_Precision: Byte; safecall;
    function Get_NumericScale: Byte; safecall;
    procedure AppendChunk(Data: OleVariant); safecall;
    function GetChunk(Length: Integer): OleVariant; safecall;
    function Get_OriginalValue: OleVariant; safecall;
    function Get_UnderlyingValue: OleVariant; safecall;
    function Get_DataFormat: IUnknown; safecall;
    procedure Set_DataFormat(const ppiDF: IUnknown); safecall;
    procedure Set_Precision(pbPrecision: Byte); safecall;
    procedure Set_NumericScale(pbNumericScale: Byte); safecall;
    procedure Set_Type_(pDataType: DataTypeEnum); safecall;
    procedure Set_DefinedSize(pl: Integer); safecall;
    procedure Set_Attributes(pl: Integer); safecall;
    property ActualSize: Integer read Get_ActualSize;
    property Attributes: Integer read Get_Attributes write Set_Attributes;
    property DefinedSize: Integer read Get_DefinedSize write Set_DefinedSize;
    property Name: WideString read Get_Name;
    property Type_: DataTypeEnum read Get_Type_ write Set_Type_;
    property Value: OleVariant read Get_Value write Set_Value;
    property Precision: Byte read Get_Precision write Set_Precision;
    property NumericScale: Byte read Get_NumericScale write Set_NumericScale;
    property OriginalValue: OleVariant read Get_OriginalValue;
    property UnderlyingValue: OleVariant read Get_UnderlyingValue;
    property DataFormat: IUnknown read Get_DataFormat write Set_DataFormat;
  end;

// *********************************************************************//
// DispIntf:  FieldDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000054C-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  FieldDisp = dispinterface
    ['{0000054C-0000-0010-8000-00AA006D2EA4}']
    property ActualSize: Integer readonly dispid 1109;
    property Attributes: Integer dispid 1036;
    property DefinedSize: Integer dispid 1103;
    property Name: WideString readonly dispid 1100;
    property Type_: DataTypeEnum dispid 1102;
    property Value: OleVariant dispid 0;
    property Precision: Byte dispid 1610809351;
    property NumericScale: Byte dispid 1610809352;
    procedure AppendChunk(Data: OleVariant); dispid 1107;
    function GetChunk(Length: Integer): OleVariant; dispid 1108;
    property OriginalValue: OleVariant readonly dispid 1104;
    property UnderlyingValue: OleVariant readonly dispid 1105;
    property DataFormat: IUnknown dispid 1610809357;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: Field15
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000505-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Field15 = interface(_ADO)
    ['{00000505-0000-0010-8000-00AA006D2EA4}']
    function Get_ActualSize: Integer; safecall;
    function Get_Attributes: Integer; safecall;
    function Get_DefinedSize: Integer; safecall;
    function Get_Name: WideString; safecall;
    function Get_Type_: DataTypeEnum; safecall;
    function Get_Value: OleVariant; safecall;
    procedure Set_Value(pvar: OleVariant); safecall;
    function Get_Precision: Byte; safecall;
    function Get_NumericScale: Byte; safecall;
    procedure AppendChunk(Data: OleVariant); safecall;
    function GetChunk(Length: Integer): OleVariant; safecall;
    function Get_OriginalValue: OleVariant; safecall;
    function Get_UnderlyingValue: OleVariant; safecall;
    property ActualSize: Integer read Get_ActualSize;
    property Attributes: Integer read Get_Attributes;
    property DefinedSize: Integer read Get_DefinedSize;
    property Name: WideString read Get_Name;
    property Type_: DataTypeEnum read Get_Type_;
    property Value: OleVariant read Get_Value write Set_Value;
    property Precision: Byte read Get_Precision;
    property NumericScale: Byte read Get_NumericScale;
    property OriginalValue: OleVariant read Get_OriginalValue;
    property UnderlyingValue: OleVariant read Get_UnderlyingValue;
  end;

// *********************************************************************//
// DispIntf:  Field15Disp
// Flags:     (4560) Hidden Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000505-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Field15Disp = dispinterface
    ['{00000505-0000-0010-8000-00AA006D2EA4}']
    property ActualSize: Integer readonly dispid 1109;
    property Attributes: Integer readonly dispid 1036;
    property DefinedSize: Integer readonly dispid 1103;
    property Name: WideString readonly dispid 1100;
    property Type_: DataTypeEnum readonly dispid 1102;
    property Value: OleVariant dispid 0;
    property Precision: Byte readonly dispid 1610809351;
    property NumericScale: Byte readonly dispid 1610809352;
    procedure AppendChunk(Data: OleVariant); dispid 1107;
    function GetChunk(Length: Integer): OleVariant; dispid 1108;
    property OriginalValue: OleVariant readonly dispid 1104;
    property UnderlyingValue: OleVariant readonly dispid 1105;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: _Parameter
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000050C-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _Parameter = interface(_ADO)
    ['{0000050C-0000-0010-8000-00AA006D2EA4}']
    function Get_Name: WideString; safecall;
    procedure Set_Name(const pbstr: WideString); safecall;
    function Get_Value: OleVariant; safecall;
    procedure Set_Value(pvar: OleVariant); safecall;
    function Get_Type_: DataTypeEnum; safecall;
    procedure Set_Type_(psDataType: DataTypeEnum); safecall;
    procedure Set_Direction(plParmDirection: ParameterDirectionEnum); safecall;
    function Get_Direction: ParameterDirectionEnum; safecall;
    procedure Set_Precision(pbPrecision: Byte); safecall;
    function Get_Precision: Byte; safecall;
    procedure Set_NumericScale(pbScale: Byte); safecall;
    function Get_NumericScale: Byte; safecall;
    procedure Set_Size(pl: Integer); safecall;
    function Get_Size: Integer; safecall;
    procedure AppendChunk(Val: OleVariant); safecall;
    function Get_Attributes: Integer; safecall;
    procedure Set_Attributes(plParmAttribs: Integer); safecall;
    property Name: WideString read Get_Name write Set_Name;
    property Value: OleVariant read Get_Value write Set_Value;
    property Type_: DataTypeEnum read Get_Type_ write Set_Type_;
    property Direction: ParameterDirectionEnum read Get_Direction write Set_Direction;
    property Precision: Byte read Get_Precision write Set_Precision;
    property NumericScale: Byte read Get_NumericScale write Set_NumericScale;
    property Size: Integer read Get_Size write Set_Size;
    property Attributes: Integer read Get_Attributes write Set_Attributes;
  end;

// *********************************************************************//
// DispIntf:  _ParameterDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000050C-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _ParameterDisp = dispinterface
    ['{0000050C-0000-0010-8000-00AA006D2EA4}']
    property Name: WideString dispid 1610809344;
    property Value: OleVariant dispid 0;
    property Type_: DataTypeEnum dispid 1610809348;
    property Direction: ParameterDirectionEnum dispid 1610809350;
    property Precision: Byte dispid 1610809352;
    property NumericScale: Byte dispid 1610809354;
    property Size: Integer dispid 1610809356;
    procedure AppendChunk(Val: OleVariant); dispid 1610809358;
    property Attributes: Integer dispid 1610809359;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: Parameters
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000050D-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  Parameters = interface(_DynaCollection)
    ['{0000050D-0000-0010-8000-00AA006D2EA4}']
    function Get_Item(Index: OleVariant): _Parameter; safecall;
    property Item[Index: OleVariant]: _Parameter read Get_Item; default;
  end;

// *********************************************************************//
// DispIntf:  ParametersDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000050D-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  ParametersDisp = dispinterface
    ['{0000050D-0000-0010-8000-00AA006D2EA4}']
    property Item[Index: OleVariant]: _Parameter readonly dispid 0; default;
    procedure Append(const Object_: IDispatch); dispid 1610809344;
    procedure Delete(Index: OleVariant); dispid 1610809345;
    property Count: Integer readonly dispid 1610743808;
    function _NewEnum: IUnknown; dispid -4;
    procedure Refresh; dispid 1610743810;
  end;

// *********************************************************************//
// Interface: _Command
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000054E-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _Command = interface(Command15)
    ['{0000054E-0000-0010-8000-00AA006D2EA4}']
    function Get_State: Integer; safecall;
    procedure Cancel; safecall;
    property State: Integer read Get_State;
  end;

// *********************************************************************//
// DispIntf:  _CommandDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {0000054E-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _CommandDisp = dispinterface
    ['{0000054E-0000-0010-8000-00AA006D2EA4}']
    property State: Integer readonly dispid 1610874880;
    procedure Cancel; dispid 1610874881;
    function ActiveConnection: _Connection; dispid 1610809344;
    property CommandText: WideString dispid 1610809347;
    property CommandTimeout: Integer dispid 1610809349;
    property Prepared: WordBool dispid 1610809351;
    function Execute(out RecordsAffected: OleVariant; const Parameters: OleVariant; Options: Integer): _Recordset; dispid 1610809353;
    function CreateParameter(const Name: WideString; Type_: DataTypeEnum;
      Direction: ParameterDirectionEnum; Size: Integer; Value: OleVariant): _Parameter; dispid 1610809354;
    property Parameters: Parameters readonly dispid 0;
    property CommandType: CommandTypeEnum dispid 1610809356;
    property Name: WideString dispid 1610809358;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Interface: ConnectionEventsVt
// Flags:     (16) Hidden
// GUID:      {00000402-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  ConnectionEventsVt = interface(IUnknown)
    ['{00000402-0000-0010-8000-00AA006D2EA4}']
    procedure InfoMessage(const pError: Error; var adStatus: EventStatusEnum;
      const pConnection: _Connection); safecall;
    procedure BeginTransComplete(TransactionLevel: Integer; const pError: Error;
      var adStatus: EventStatusEnum; const pConnection: _Connection); safecall;
    procedure CommitTransComplete(const pError: Error; var adStatus: EventStatusEnum;
      const pConnection: _Connection); safecall;
    procedure RollbackTransComplete(const pError: Error; var adStatus: EventStatusEnum;
      const pConnection: _Connection); safecall;
    procedure WillExecute(var Source: WideString; var CursorType: CursorTypeEnum;
      var LockType: LockTypeEnum; var Options: Integer;
      var adStatus: EventStatusEnum; const pCommand: _Command;
      const pRecordset: _Recordset; const pConnection: _Connection); safecall;
    procedure ExecuteComplete(RecordsAffected: Integer; const pError: Error;
      var adStatus: EventStatusEnum; const pCommand: _Command;
      const pRecordset: _Recordset; const pConnection: _Connection); safecall;
    procedure WillConnect(var ConnectionString: WideString; var UserID: WideString;
      var Password: WideString; var Options: Integer;
      var adStatus: EventStatusEnum; const pConnection: _Connection); safecall;
    procedure ConnectComplete(const pError: Error; var adStatus: EventStatusEnum;
      const pConnection: _Connection); safecall;
    procedure Disconnect(var adStatus: EventStatusEnum; const pConnection: _Connection); safecall;
  end;

// *********************************************************************//
// Interface: RecordsetEventsVt
// Flags:     (16) Hidden
// GUID:      {00000403-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  RecordsetEventsVt = interface(IUnknown)
    ['{00000403-0000-0010-8000-00AA006D2EA4}']
    procedure WillChangeField(cFields: Integer; Fields: OleVariant;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); safecall;
    procedure FieldChangeComplete(cFields: Integer; Fields: OleVariant;
      const pError: Error; var adStatus: EventStatusEnum;
      const pRecordset: _Recordset); safecall;
    procedure WillChangeRecord(adReason: EventReasonEnum;
      cRecords: Integer; var adStatus: EventStatusEnum;
      const pRecordset: _Recordset); safecall;
    procedure RecordChangeComplete(adReason: EventReasonEnum;
      cRecords: Integer; const pError: Error;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); safecall;
    procedure WillChangeRecordset(adReason: EventReasonEnum;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); safecall;
    procedure RecordsetChangeComplete(adReason: EventReasonEnum;
      const pError: Error; var adStatus: EventStatusEnum;
      const pRecordset: _Recordset); safecall;
    procedure WillMove(adReason: EventReasonEnum;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); safecall;
    procedure MoveComplete(adReason: EventReasonEnum; const pError: Error;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); safecall;
    procedure EndOfRecordset(var fMoreData: WordBool;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); safecall;
    procedure FetchProgress(Progress, MaxProgress: Integer;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); safecall;
    procedure FetchComplete(const pError: Error;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); safecall;
  end;

// *********************************************************************//
// DispIntf:  ConnectionEvents
// Flags:     (4096) Dispatchable
// GUID:      {00000400-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  ConnectionEvents = dispinterface
    ['{00000400-0000-0010-8000-00AA006D2EA4}']
    procedure InfoMessage(const pError: Error; var adStatus: EventStatusEnum;
      const pConnection: _Connection); dispid 0;
    procedure BeginTransComplete(TransactionLevel: Integer; const pError: Error;
      var adStatus: EventStatusEnum; const pConnection: _Connection); dispid 1;
    procedure CommitTransComplete(const pError: Error; var adStatus: EventStatusEnum;
      const pConnection: _Connection); dispid 3;
    procedure RollbackTransComplete(const pError: Error; var adStatus: EventStatusEnum;
      const pConnection: _Connection); dispid 2;
    procedure WillExecute(var Source: WideString; var CursorType: CursorTypeEnum;
      var LockType: LockTypeEnum; var Options: Integer;
      var adStatus: EventStatusEnum; const pCommand: _Command;
      const pRecordset: _Recordset; const pConnection: _Connection); dispid 4;
    procedure ExecuteComplete(RecordsAffected: Integer; const pError: Error;
      var adStatus: EventStatusEnum; const pCommand: _Command;
      const pRecordset: _Recordset; const pConnection: _Connection); dispid 5;
    procedure WillConnect(var ConnectionString: WideString; var UserID: WideString;
      var Password: WideString; var Options: Integer;
      var adStatus: EventStatusEnum; const pConnection: _Connection); dispid 6;
    procedure ConnectComplete(const pError: Error; var adStatus: EventStatusEnum;
      const pConnection: _Connection); dispid 7;
    procedure Disconnect(var adStatus: EventStatusEnum; const pConnection: _Connection); dispid 8;
  end;

// *********************************************************************//
// DispIntf:  RecordsetEvents
// Flags:     (4096) Dispatchable
// GUID:      {00000266-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  RecordsetEvents = dispinterface
    ['{00000266-0000-0010-8000-00AA006D2EA4}']
    procedure WillChangeField(cFields: Integer; Fields: OleVariant; var adStatus: EventStatusEnum; 
      const pRecordset: _Recordset); dispid 9;
    procedure FieldChangeComplete(cFields: Integer; Fields: OleVariant; const pError: Error;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); dispid 10;
    procedure WillChangeRecord(adReason: EventReasonEnum; cRecords: Integer;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); dispid 11;
    procedure RecordChangeComplete(adReason: EventReasonEnum; cRecords: Integer;
      const pError: Error; var adStatus: EventStatusEnum;
      const pRecordset: _Recordset); dispid 12;
    procedure WillChangeRecordset(adReason: EventReasonEnum; var adStatus: EventStatusEnum;
      const pRecordset: _Recordset); dispid 13;
    procedure RecordsetChangeComplete(adReason: EventReasonEnum; const pError: Error;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); dispid 14;
    procedure WillMove(adReason: EventReasonEnum; var adStatus: EventStatusEnum;
      const pRecordset: _Recordset); dispid 15;
    procedure MoveComplete(adReason: EventReasonEnum; const pError: Error;
      var adStatus: EventStatusEnum; const pRecordset: _Recordset); dispid 16;
    procedure EndOfRecordset(var fMoreData: WordBool; var adStatus: EventStatusEnum;
      const pRecordset: _Recordset); dispid 17;
    procedure FetchProgress(Progress: Integer; MaxProgress: Integer; var adStatus: EventStatusEnum;
      const pRecordset: _Recordset); dispid 18;
    procedure FetchComplete(const pError: Error; var adStatus: EventStatusEnum;
      const pRecordset: _Recordset); dispid 19;
  end;

// *********************************************************************//
// Interface: ADOConnectionConstruction15
// Flags:     (512) Restricted
// GUID:      {00000516-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  ADOConnectionConstruction15 = interface(IUnknown)
    ['{00000516-0000-0010-8000-00AA006D2EA4}']
    function Get_DSO: IUnknown; safecall;
    function Get_Session: IUnknown; safecall;
    procedure WrapDSOandSession(const pDSO: IUnknown; const pSession: IUnknown); safecall;
  end;

// *********************************************************************//
// Interface: ADOConnectionConstruction
// Flags:     (512) Restricted
// GUID:      {00000551-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  ADOConnectionConstruction = interface(ADOConnectionConstruction15)
    ['{00000551-0000-0010-8000-00AA006D2EA4}']
  end;

// *********************************************************************//
// Interface: ADOCommandConstruction
// Flags:     (512) Restricted
// GUID:      {00000517-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  ADOCommandConstruction = interface(IUnknown)
    ['{00000517-0000-0010-8000-00AA006D2EA4}']
    function Get_OLEDBCommand: IUnknown; safecall;
    procedure Set_OLEDBCommand(const ppOLEDBCommand: IUnknown); safecall;
    property OLEDBCommand: IUnknown read Get_OLEDBCommand write Set_OLEDBCommand;
  end;

// *********************************************************************//
// Interface: ADORecordsetConstruction
// Flags:     (4608) Restricted Dispatchable
// GUID:      {00000283-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  ADORecordsetConstruction = interface(IDispatch)
    ['{00000283-0000-0010-8000-00AA006D2EA4}']
    function Get_Rowset: IUnknown; safecall;
    procedure Set_Rowset(const ppRowset: IUnknown); safecall;
    function Get_Chapter: Integer; safecall;
    procedure Set_Chapter(plChapter: Integer); safecall;
    function Get_RowPosition: IUnknown; safecall;
    procedure Set_RowPosition(const ppRowPos: IUnknown); safecall;
    property Rowset: IUnknown read Get_Rowset write Set_Rowset;
    property Chapter: Integer read Get_Chapter write Set_Chapter;
    property RowPosition: IUnknown read Get_RowPosition write Set_RowPosition;
  end;

// *********************************************************************//
// Interface: IDataspace
// Flags:     (4432) Hidden Dual OleAutomation Dispatchable
// GUID:      {BD96C556-65A3-11D0-983A-00C04FC29E34}
// *********************************************************************//
  IDataspace = interface(IDispatch)
    ['{BD96C556-65A3-11D0-983A-00C04FC29E34}']
    function  CreateObject(const bstrProgid: WideString;
      const bstrConnection: WideString): OleVariant; safecall;
    function  Get_InternetTimeout: Integer; safecall;
    procedure Set_InternetTimeout(plInetTimeout: Integer); safecall;
    property InternetTimeout: Integer read Get_InternetTimeout write Set_InternetTimeout;
  end;

// *********************************************************************//
// DispIntf:  IDataspaceDisp
// Flags:     (4432) Hidden Dual OleAutomation Dispatchable
// GUID:      {BD96C556-65A3-11D0-983A-00C04FC29E34}
// *********************************************************************//
  IDataspaceDisp = dispinterface
    ['{BD96C556-65A3-11D0-983A-00C04FC29E34}']
    function  CreateObject(const bstrProgid: WideString;
      const bstrConnection: WideString): OleVariant; dispid 1;
    property InternetTimeout: Integer dispid 222;
  end;

// *********************************************************************//
// Interface: _Recordset
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000555-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _Recordset = interface(Recordset20)
    ['{00000555-0000-0010-8000-00AA006D2EA4}']
    procedure Seek(KeyValues: OleVariant; SeekOption: SeekEnum); safecall;
    procedure Set_Index(const pbstrIndex: WideString); safecall;
    function Get_Index: WideString; safecall;
    property Index: WideString read Get_Index write Set_Index;
  end;

// *********************************************************************//
// DispIntf:  _RecordsetDisp
// Flags:     (4544) Dual NonExtensible OleAutomation Dispatchable
// GUID:      {00000555-0000-0010-8000-00AA006D2EA4}
// *********************************************************************//
  _RecordsetDisp = dispinterface
    ['{00000555-0000-0010-8000-00AA006D2EA4}']
    procedure Seek(KeyValues: OleVariant; SeekOption: SeekEnum); dispid 1066;
    property Index: WideString dispid 1067;
    procedure Cancel; dispid 1055;
    property DataSource: IUnknown dispid 1056;
    procedure Save(const FileName: WideString; PersistFormat: PersistFormatEnum); dispid 1057;
    property ActiveCommand: IDispatch readonly dispid 1061;
    property StayInSync: WordBool dispid 1063;
    function GetString(StringFormat: StringFormatEnum; NumRows: Integer; 
      const ColumnDelimeter: WideString; const RowDelimeter: WideString;
      const NullExpr: WideString): WideString; dispid 1062;
    property DataMember: WideString dispid 1064;
    function CompareBookmarks(Bookmark1: OleVariant; Bookmark2: OleVariant): CompareEnum; dispid 1065;
    function Clone(LockType: LockTypeEnum): _Recordset; dispid 1034;
    procedure Resync(AffectRecords: AffectEnum; ResyncValues: ResyncEnum); dispid 1024;
    property AbsolutePosition: PositionEnum dispid 1000;
    function ActiveConnection: IDispatch; dispid 1001;
    property BOF: WordBool readonly dispid 1002;
    property Bookmark: OleVariant dispid 1003;
    property CacheSize: Integer dispid 1004;
    property CursorType: CursorTypeEnum dispid 1005;
    property EOF: WordBool readonly dispid 1006;
    property Fields: Fields readonly dispid 0;
    property LockType: LockTypeEnum dispid 1008;
    property MaxRecords: Integer dispid 1009;
    property RecordCount: Integer readonly dispid 1010;
    function Source: IDispatch; dispid 1011;
    procedure AddNew(FieldList: OleVariant; Values: OleVariant); dispid 1012;
    procedure CancelUpdate; dispid 1013;
    procedure Close; dispid 1014;
    procedure Delete(AffectRecords: AffectEnum); dispid 1015;
    function GetRows(Rows: Integer; Start: OleVariant; Fields: OleVariant): OleVariant; dispid 1016;
    procedure Move(NumRecords: Integer; Start: OleVariant); dispid 1017;
    procedure MoveNext; dispid 1018;
    procedure MovePrevious; dispid 1019;
    procedure MoveFirst; dispid 1020;
    procedure MoveLast; dispid 1021;
    procedure Open(Source: OleVariant; ActiveConnection: OleVariant; CursorType: CursorTypeEnum;
      LockType: LockTypeEnum; Options: Integer); dispid 1022;
    procedure Requery(Options: Integer); dispid 1023;
    procedure _xResync(AffectRecords: AffectEnum); dispid 1610809378;
    procedure Update(Fields: OleVariant; Values: OleVariant); dispid 1025;
    property AbsolutePage: PositionEnum dispid 1047;
    property EditMode: EditModeEnum readonly dispid 1026;
    property Filter: OleVariant dispid 1030;
    property PageCount: Integer readonly dispid 1050;
    property PageSize: Integer dispid 1048;
    property Sort: WideString dispid 1031;
    property Status: Integer readonly dispid 1029;
    property State: Integer readonly dispid 1054;
    function _xClone: _Recordset; dispid 1610809392;
    procedure UpdateBatch(AffectRecords: AffectEnum); dispid 1035;
    procedure CancelBatch(AffectRecords: AffectEnum); dispid 1049;
    property CursorLocation: CursorLocationEnum dispid 1051;
    function NextRecordset(out RecordsAffected: OleVariant): _Recordset; dispid 1052;
    function Supports(CursorOptions: CursorOptionEnum): WordBool; dispid 1036;
    property Collect[Index: OleVariant]: OleVariant dispid -8;
    property MarshalOptions: MarshalOptionsEnum dispid 1053;
    procedure Find(const Criteria: WideString; SkipRecords: Integer;
      SearchDirection: SearchDirectionEnum; Start: OleVariant); dispid 1058;
    property Properties: Properties readonly dispid 500;
  end;

// *********************************************************************//
// Declaration of CoClasses defined in Type Library                     //
// (NOTE: Here we map each CoClass to its Default Interface)            //
// *********************************************************************//

  Connection = _Connection;
  Command = _Command;
  Recordset = _Recordset;
  Parameter = _Parameter;
  DataSpace = IDataspace;

{ CoClass Creators }

  CoConnection = class
    class function Create: _Connection;
    class function CreateRemote(const MachineName: string): _Connection;
  end;

  CoCommand = class
    class function Create: _Command;
    class function CreateRemote(const MachineName: string): _Command;
  end;

  CoRecordset = class
    class function Create: _Recordset;
    class function CreateRemote(const MachineName: string): _Recordset;
  end;

  CoParameter = class
    class function Create: _Parameter;
    class function CreateRemote(const MachineName: string): _Parameter;
  end;

implementation

uses ComObj;

{ CoClass Creators }

class function CoConnection.Create: _Connection;
begin
  Result := CreateComObject(CLASS_Connection) as _Connection;
end;

class function CoConnection.CreateRemote(const MachineName: string): _Connection;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_Connection) as _Connection;
end;

class function CoCommand.Create: _Command;
begin
  Result := CreateComObject(CLASS_Command) as _Command;
end;

class function CoCommand.CreateRemote(const MachineName: string): _Command;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_Command) as _Command;
end;

class function CoRecordset.Create: _Recordset;
begin
  Result := CreateComObject(CLASS_Recordset) as _Recordset;
end;

class function CoRecordset.CreateRemote(const MachineName: string): _Recordset;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_Recordset) as _Recordset;
end;

class function CoParameter.Create: _Parameter;
begin
  Result := CreateComObject(CLASS_Parameter) as _Parameter;
end;

class function CoParameter.CreateRemote(const MachineName: string): _Parameter;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_Parameter) as _Parameter;
end;

end.
