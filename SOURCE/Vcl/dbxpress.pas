{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 1999, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit DBXpress;

{$Z+}

interface

{$IFDEF MSWINDOWS}
uses Windows, DB;
{$ENDIF}
{$IFDEF LINUX}
uses Libc, DB;
{$ENDIF}

const

  MAXNAMELEN       = 64;
  SQL_ERROR        = -1;
  SQL_NULL_DATA    = 100;
  SQL_ERROR_EOF    = 101;

  SQL_SUCCESS                      = $0000;
  DBXERR_NOMEMORY                  = $0001;
  DBXERR_INVALIDFLDTYPE            = $0002;
  DBXERR_INVALIDHNDL               = $0003;
  DBXERR_INVALIDTIME               = $0004;
  DBXERR_NOTSUPPORTED              = $0005;
  DBXERR_INVALIDXLATION            = $0006;
  DBXERR_INVALIDPARAM              = $0007;
  DBXERR_OUTOFRANGE                = $0008;
  DBXERR_SQLPARAMNOTSET            = $0009;
  DBXERR_EOF                       = $000A;
  DBXERR_INVALIDUSRPASS            = $000B;
  DBXERR_INVALIDPRECISION          = $000C;
  DBXERR_INVALIDLEN                = $000D;
  DBXERR_INVALIDXISOLEVEL          = $000E;
  DBXERR_INVALIDXTXNID             = $000F;
  DBXERR_DUPLICATETXNID            = $0010;
  DBXERR_DRIVERRESTRICTED          = $0011;
  DBX_MAXSTATICERRORS              = $0012;
  MaxReservedStaticErrors          = 255;
// traceFlags 

    trUNKNOWN   = $0000;
    trQPREPARE  = $0001;             { prepared query statements }
    trQEXECUTE  = $0002;             { executed query statements }
    trERROR     = $0004;             { vendor errors }
    trSTMT      = $0008;             { statement ops (i.e. allocate, free) }
    trCONNECT   = $0010;             { connect / disconnect }
    trTRANSACT  = $0020;             { transaction }
    trBLOB      = $0040;             { blob i/o }
    trMISC      = $0080;             { misc. }
    trVENDOR    = $0100;             { vendor calls }
    trDATAIN    = $0200;             { parameter bound data }
    trDATAOUT   = $0400;             { trace fetched data }

// eSQLTableType
    eSQLTable       = $0001;
    eSQLView        = $0002;
    eSQLSystemTable = $0004;
    eSQLSynonym     = $0008;
    eSQLTempTable   = $0010;
    eSQLLocal       = $0020;

// eSQLProcType
    eSQLProcedure   = $0001;
    eSQLFunction    = $0002;
    eSQLPackage     = $0004;
    eSQLSysProcedure = $0008;

// eSQLColType
    eSQLRowId       = $0001;
    eSQLRowVersion  = $0002;
    eSQLAutoIncr    = $0004;
    eSQLDefault     = $0008;

// eSQLIndexType
    eSQLNonUnique   = $0001;
    eSQLUnique      = $0002;
    eSQLPrimaryKey  = $0004;

{ Field Types (Logical) }

  fldUNKNOWN         = 0;
  fldZSTRING         = 1;               { Null terminated string }
  fldDATE            = 2;               { Date     (32 bit) }
  fldBLOB            = 3;               { Blob }
  fldBOOL            = 4;               { Boolean  (16 bit) }
  fldINT16           = 5;               { 16 bit signed number }
  fldINT32           = 6;               { 32 bit signed number }
  fldFLOAT           = 7;               { 64 bit floating point }
  fldBCD             = 8;               { BCD }
  fldBYTES           = 9;               { Fixed number of bytes }
  fldTIME            = 10;              { Time        (32 bit) }
  fldTIMESTAMP       = 11;              { Time-stamp  (64 bit) }
  fldUINT16          = 12;              { Unsigned 16 bit Integer }
  fldUINT32          = 13;              { Unsigned 32 bit Integer }
  fldFLOATIEEE       = 14;              { 80-bit IEEE float }
  fldVARBYTES        = 15;              { Length prefixed var bytes }
  fldLOCKINFO        = 16;              { Look for LOCKINFO typedef }
  fldCURSOR          = 17;              { For Oracle Cursor type }
  fldINT64           = 18;              { 64 bit signed number }
  fldUINT64          = 19;              { Unsigned 64 bit Integer }
  fldADT             = 20;              { Abstract datatype (structure) }
  fldARRAY           = 21;              { Array field type }
  fldREF             = 22;              { Reference to ADT }
  fldTABLE           = 23;              { Nested table (reference) }
  fldDATETIME        = 24;              { DateTime structure field }
  fldFMTBCD          = 25;              { BCD Variant type: required by Midas, same as BCD for DBExpress}

  MAXLOGFLDTYPES     = 26;              { Number of logical fieldtypes }

{ Sub Types (Logical) }

{ fldFLOAT subtype }

  fldstMONEY         = 21;              { Money }

{ fldBLOB subtypes }

  fldstMEMO          = 22;              { Text Memo }
  fldstBINARY        = 23;              { Binary data }
  fldstFMTMEMO       = 24;              { Formatted Text }
  fldstOLEOBJ        = 25;              { OLE object (Paradox) }
  fldstGRAPHIC       = 26;              { Graphics object }
  fldstDBSOLEOBJ     = 27;              { dBASE OLE object }
  fldstTYPEDBINARY   = 28;              { Typed Binary data }
  fldstACCOLEOBJ     = 30;              { Access OLE object }
  fldstHMEMO         = 33;              { CLOB }
  fldstHBINARY       = 34;              { BLOB }
  fldstBFILE         = 36;              { BFILE }

{ fldZSTRING subtype }

  fldstPASSWORD      = 1;               { Password }
  fldstFIXED         = 31;              { CHAR type }
  fldstUNICODE       = 32;              { Unicode }

{ fldINT32 subtype }

  fldstAUTOINC       = 29;

{ fldADT subtype }

  fldstADTNestedTable = 35;             { ADT for nested table (has no name) }

{ fldDATE subtype }
  fldstADTDATE       = 37;              { DATE (OCIDate) with in an ADT }

type

  DBINAME            = packed array [0..31] of Char; { holds a name }

  FLDVchk = (                          { Field Val Check type }
    fldvNOCHECKS,                       { Does not have explicit val checks }
    fldvHASCHECKS,                      { One or more val checks on the field }
    fldvUNKNOWN                         { Dont know at this time }
 );

  FLDRights = (                        { Field Rights }
    fldrREADWRITE,                      { Field can be Read/Written }
    fldrREADONLY,                       { Field is Read only }
    fldrNONE,                           { No Rights on this field }
    fldrUNKNOWN                         { Dont know at this time }
 );

  PFLDDesc = ^FLDDesc;
  FLDDesc = packed record               { Field Descriptor }
    iFldNum         : Word;             { Field number (1..n) }
    szName          : DBINAME;          { Field name }
    iFldType        : Word;             { Field type }
    iSubType        : Word;             { Field subtype (if applicable) }
    iUnits1         : SmallInt;         { Number of Chars, digits etc }
    iUnits2         : SmallInt;         { Decimal places etc. }
    iOffset         : Word;             { Offset in the record (computed) }
    iLen            : LongWord;             { Length in bytes (computed) }
    iNullOffset     : Word;             { For Null bits (computed) }
    efldvVchk       : FLDVchk;          { Field Has vcheck (computed) }
    efldrRights     : FLDRights;        { Field Rights (computed) }
    bCalcField      : WordBool;         { Is Calculated field (computed) }
    iUnUsed         : packed array [0..1] of Word;
  end;

  PSPParamDesc = ^SPParamDesc;
  SPParamDesc = packed record               { Stored Proc Descriptor }
    iParamNum       : Word;             { Field number (1..n) }
    szName          : string;           { Field name }
    iArgType        : TParamType;       { Field type }
    iDataType       : TFieldType;       { Field type }
    iUnits1         : SmallInt;         { Number of Chars, digits etc }
    iUnits2         : SmallInt;         { Decimal places etc. }
    iLen            : LongWord;         { Length in bytes  }
  end;

  pObjAttrDesc = ^ObjAttrDesc;
  ObjAttrDesc = packed record
    iFldNum    : Word;                  { Field id }
    pszAttributeName: PChar;           { Object attribute name }
  end;

  pObjTypeDesc = ^ObjTypeDesc;
  ObjTypeDesc = packed record
    iFldNum    : Word;                  { Field id }
    szTypeName : DBINAME;               { Object type name }
  end;

  pObjParentDesc = ^ObjParentDesc;
  ObjParentDesc = packed record
    iFldNum    : Word;                  { Field id }
    iParentFldNum : Word;               { Parent Field id }
  end;

  SQLResult      = Word;

var

getSQLDriver : function(VendorLib, SResourceFile: PChar; out pDriver): SQLResult; stdcall;

type

  pCBType            = ^CBType;
  CBType = (                            { Call back type }
    cbGENERAL,                          { General purpose }
    cbRESERVED1,
    cbRESERVED2,
    cbINPUTREQ,                         { Input requested }
    cbRESERVED4,
    cbRESERVED5,
    cbBATCHRESULT,                      { Batch processing rslts }
    cbRESERVED7,
    cbRESTRUCTURE,                      { Restructure }
    cbRESERVED9,
    cbRESERVED10,
    cbRESERVED11,
    cbRESERVED12,
    cbRESERVED13,
    cbRESERVED14,
    cbRESERVED15,
    cbRESERVED16,
    cbRESERVED17,
    cbTABLECHANGED,                     { Table changed notification }
    cbRESERVED19,
    cbCANCELQRY,                        { Allow user to cancel Query }
    cbSERVERCALL,                       { Server Call }
    cbRESERVED22,
    cbGENPROGRESS,                      { Generic Progress report. }
    cbDBASELOGIN,                       { dBASE Login }
    cbDELAYEDUPD,                       { Delayed Updates }
    cbFIELDRECALC,                      { Field(s) recalculation }
    cbTRACE,                            { Trace }
    cbDBLOGIN,                          { Database login }
    cbDETACHNOTIFY,                     { DLL Detach Notification }
    cbNBROFCBS                          { Number of cbs }
  );

TSQLDriverOption = (eDrvBlobSize, eDrvCallBack, eDrvCallBackInfo, eDrvRestrict);

TSQLConnectionOption = (
      eConnAutoCommit, eConnBlockingMode, eConnBlobSize, eConnRoleName,
      eConnWaitOnLocks, eConnCommitRetain, eConnTxnIsoLevel,
      eConnNativeHandle, eConnServerVersion, eConnCallBack, eConnHostName,
      eConnDatabaseName, eConnCallBackInfo, eConnObjectMode, 
      eConnMaxActiveConnection, eConnServerCharSet, eConnSqlDialect);

TSQLCommandOption = (
      eCommRowsetSize, eCommBlobSize, eCommBlockRead, eCommBlockWrite,
      eCommParamCount, eCommNativeHandle, eCommCursorName, eCommStoredProc,
      eCommSQLDialect, eCommTransactionID);

TSQLCursorOption = (eCurObjectAttrName, eCurObjectTypeName, eCurParentFieldID);

CBRType = (cbrUSEDEF, cbrCONTINUE, cbrABORT, cbrCHKINPUT,
      cbrYES, cbrNO, cbrPARTIALASSIST, cbrSKIP, cbrRETRY);

TSQLMetaDataOption = (eMetaCatalogName, eMetaSchemaName, eMetaDatabaseName,
                  eMetaDatabaseVersion, eMetaTransactionIsoLevel, eMetaSupportsTransaction,
                  eMetaMaxObjectNameLength, eMetaMaxColumnsInTable, eMetaMaxColumnsInSelect,
                  eMetaMaxRowSize, eMetaMaxSQLLength, eMetaObjectQuoteChar,
                  eMetaSQLEscapeChar, eMetaProcSupportsCursor, eMetaProcSupportsCursors, 
                  eMetaSupportsTransactions);

TSQLObjectType = (eObjTypeDatabase, eObjTypeDataType, eObjTypeTable,
                  eObjTypeView, eObjTypeSynonym, eObjTypeProcedure, eObjTypeUser,
                  eObjTypeRole, eObjTypeUDT);

TTransIsolationLevel = (xilREADCOMMITTED, xilREPEATABLEREAD, xilDIRTYREAD, xilCUSTOM);

  pTTransactionDesc = ^TTransactionDesc;
  TTransactionDesc = packed record
    TransactionID    : LongWord;             { Transaction id }
    GlobalID         : LongWord;             { Global transaction id }
    IsolationLevel   : TTransIsolationLevel; {Transaction Isolation level}
    CustomIsolation  : LongWord;             { DB specific custom isolation }
  end;

TSTMTParamType = (paramUNKNOWN, paramIN, paramOUT, paramINOUT, paramRET);

   { Function Result }
   TypedEnum      = Integer; 
   SQLDATE        = Longint;
   SQLTIME        = Longint; 

  pTRACECat = ^TRACECat;                { trace categories }
  TRACECat = TypedEnum;

type

{ forward declarations }

   ISQLDriver = interface; 
   ISQLConnection = interface; 
   ISQLCommand = interface;
   ISQLCursor = interface;
   ISQLMetaData = interface; 

{ Trace callback }

  TSQLCallbackEvent = function(
     CallType: TRACECat; 
     CBInfo: Pointer): CBRType; stdcall;
     
{ class Pointers }

  pSQLDriver     = ^ISQLDriver;
  pSQLConnection = ^ISQLConnection;
  pSQLCommand    = ^ISQLCommand;
  pSQLCursor     = ^ISQLCursor;

ISQLDriver = interface
   function getSQLConnection(out pConn: ISQLConnection): SQLResult; stdcall;
   function SetOption(eDOption: TSQLDriverOption; 
                     PropValue: LongInt): SQLResult; stdcall;
   function GetOption(eDOption: TSQLDriverOption; PropValue: Pointer; 
                     MaxLength: SmallInt; out Length: SmallInt): SQLResult; stdcall;
end;

ISQLConnection = interface

   function connect(ServerName: PChar; UserName: PChar;
                          Password: PChar): SQLResult; stdcall;
   function disconnect: SQLResult; stdcall;
   function getSQLCommand(out pComm: ISQLCommand): SQLResult; stdcall;
   function getSQLMetaData(out pMetaData: ISQLMetaData): SQLResult; stdcall;
   function SetOption(eConnectOption: TSQLConnectionOption;
            lValue: LongInt): SQLResult; stdcall;
   function GetOption(eDOption: TSQLConnectionOption; PropValue: Pointer; 
            MaxLength: SmallInt; out Length: SmallInt): SQLResult; stdcall;
   function beginTransaction(TranID: LongWord): SQLResult; stdcall;
   function commit(TranID: LongWord): SQLResult; stdcall;
   function rollback(TranID: LongWord): SQLResult; stdcall;
   function getErrorMessage(Error: PChar): SQLResult; overload; stdcall;
   function getErrorMessageLen(out ErrorLen: SmallInt): SQLResult; stdcall;
end;

ISQLCommand = interface
   function SetOption(
      eSqlCommandOption: TSQLCommandOption;
      ulValue: Integer): SQLResult; stdcall;
   function GetOption(eSqlCommandOption: TSQLCommandOption;
      var pValue: Integer;
      MaxLength: SmallInt; out Length: SmallInt): SQLResult; stdcall;
   function setParameter(
      ulParameter: Word ;
      ulChildPos: Word ;
      eParamType: TSTMTParamType ;
      uLogType: Word;
      uSubType: Word;
      iPrecision: Integer;
      iScale: Integer;
      Length: LongWord ;
      pBuffer: Pointer;
      lInd: Integer): SQLResult; stdcall;
   function getParameter(ParameterNumber: Word; ulChildPos: Word; Value: Pointer;
      Length: Integer; var IsBlank: Integer): SQLResult; stdcall;
   function prepare(SQL: PChar; ParamCount: Word): SQLResult; stdcall;
   function execute(var Cursor: ISQLCursor): SQLResult; stdcall;
   function executeImmediate(SQL: PChar; var Cursor: ISQLCursor): SQLResult; stdcall;
   function getNextCursor(var Cursor: ISQLCursor): SQLResult; stdcall;
   function getRowsAffected(var Rows: LongWord): SQLResult; stdcall;
   function close: SQLResult; stdcall;
   function getErrorMessage(Error: PChar): SQLResult; overload; stdcall;
   function getErrorMessageLen(out ErrorLen: SmallInt): SQLResult; stdcall;
end;

ISQLCursor = interface
   function SetOption(eOption: TSQLCursorOption;
                     PropValue: LongInt): SQLResult; stdcall;
   function GetOption(eOption: TSQLCursorOption; PropValue: Pointer; 
                     MaxLength: SmallInt; out Length: SmallInt): SQLResult; stdcall;
   function getErrorMessage(Error: PChar): SQLResult; overload; stdcall;
   function getErrorMessageLen(out ErrorLen: SmallInt): SQLResult; stdcall;
   function getColumnCount(var pColumns: Word): SQLResult; stdcall;
   function getColumnNameLength(
      ColumnNumber: Word;
      var pLen: Word): SQLResult; stdcall;
   function getColumnName(ColumnNumber: Word; pColumnName: PChar): SQLResult; stdcall;
   function getColumnType(ColumnNumber: Word; var puType: Word;
      var puSubType: Word): SQLResult; stdcall;
   function  getColumnLength(ColumnNumber: Word; var pLength: LongWord): SQLResult; stdcall;
   function getColumnPrecision(ColumnNumber: Word;
      var piPrecision: SmallInt): SQLResult; stdcall;
   function getColumnScale(ColumnNumber: Word; var piScale: SmallInt): SQLResult; stdcall;
   function isNullable(ColumnNumber: Word; var Nullable: LongBool): SQLResult; stdcall;
   function isAutoIncrement(ColumnNumber: Word; var AutoIncr: LongBool): SQLResult; stdcall;
   function isReadOnly(ColumnNumber: Word; var ReadOnly: LongBool): SQLResult; stdcall;
   function isSearchable(ColumnNumber: Word; var Searchable: LongBool): SQLResult; stdcall;
   function isBlobSizeExact(ColumnNumber: Word; var IsExact: LongBool): SQLResult; stdcall;
   function next: SQLResult; stdcall;
   function getString(ColumnNumber: Word; Value: Pointer;
      var IsBlank: LongBool): SQLResult; stdcall;
   function getShort(ColumnNumber: Word; Value: Pointer;
      var IsBlank: LongBool): SQLResult; stdcall;
   function getLong(ColumnNumber: Word; Value: Pointer;
      var IsBlank: LongBool): SQLResult; stdcall;
   function getDouble(ColumnNumber: Word; Value: Pointer; 
      var IsBlank: LongBool): SQLResult; stdcall;
   function getBcd(ColumnNumber: Word; Value: Pointer;
      var IsBlank: LongBool): SQLResult; stdcall;
   function getTimeStamp(ColumnNumber: Word; Value: Pointer;
      var IsBlank: LongBool): SQLResult; stdcall;
   function getTime(ColumnNumber: Word; Value: Pointer;
      var IsBlank: LongBool): SQLResult; stdcall;
   function getDate(ColumnNumber: Word; Value: Pointer;
      var IsBlank: LongBool): SQLResult; stdcall;
   function getBytes(ColumnNumber: Word; Value: Pointer;
      var IsBlank: LongBool): SQLResult; stdcall;
   function getBlobSize(ColumnNumber: Word; var Length: LongWord;
      var IsBlank: LongBool): SQLResult; stdcall;
   function getBlob(ColumnNumber: Word; Value: Pointer;
      var IsBlank: LongBool; Length: LongWord): SQLResult; stdcall;
end;

ISQLMetaData = interface
   function SetOption(eDOption: TSQLMetaDataOption;
                     PropValue: LongInt): SQLResult; stdcall;
   function GetOption(eDOption: TSQLMetaDataOption; PropValue: Pointer; 
                     MaxLength: SmallInt; out Length: SmallInt): SQLResult; stdcall;
   function getObjectList(eObjType: TSQLObjectType; out Cursor: ISQLCursor):
                     SQLResult; stdcall;
   function getTables(TableName: PChar; TableType: LongWord;
                     out Cursor: ISQLCursor): SQLResult; stdcall;
   function getProcedures(ProcedureName: PChar; ProcType: LongWord;
                     out Cursor: ISQLCursor): SQLResult; stdcall;
   function getColumns(TableName: PChar; ColumnName: PChar; 
                     ColType: LongWord; Out Cursor: ISQLCursor): SQLResult; stdcall;
   function getProcedureParams(ProcName: PChar; ParamName: PChar; 
                     out Cursor: ISQLCursor): SQLResult; stdcall;
   function getIndices(TableName: PChar; IndexType: LongWord; 
                     out Cursor: ISQLCursor): SQLResult; stdcall;
   function getErrorMessage(Error: PChar): SQLResult; overload; stdcall;
   function getErrorMessageLen(out ErrorLen: SmallInt): SQLResult; stdcall;
end;

implementation

end.

