// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBXpress.pas' rev: 6.00

#ifndef DBXpressHPP
#define DBXpressHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DB.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbxpress
{
//-- type declarations -------------------------------------------------------
typedef char DBINAME[32];

#pragma option push -b
enum FLDVchk { fldvNOCHECKS, fldvHASCHECKS, fldvUNKNOWN };
#pragma option pop

#pragma option push -b
enum FLDRights { fldrREADWRITE, fldrREADONLY, fldrNONE, fldrUNKNOWN };
#pragma option pop

struct FLDDesc;
typedef FLDDesc *PFLDDesc;

#pragma pack(push, 1)
struct FLDDesc
{
	Word iFldNum;
	char szName[32];
	Word iFldType;
	Word iSubType;
	short iUnits1;
	short iUnits2;
	Word iOffset;
	unsigned iLen;
	Word iNullOffset;
	FLDVchk efldvVchk;
	FLDRights efldrRights;
	Word bCalcField;
	Word iUnUsed[2];
} ;
#pragma pack(pop)

struct SPParamDesc;
typedef SPParamDesc *PSPParamDesc;

#pragma pack(push, 1)
struct SPParamDesc
{
	Word iParamNum;
	AnsiString szName;
	Db::TParamType iArgType;
	Db::TFieldType iDataType;
	short iUnits1;
	short iUnits2;
	unsigned iLen;
} ;
#pragma pack(pop)

struct ObjAttrDesc;
typedef ObjAttrDesc *pObjAttrDesc;

#pragma pack(push, 1)
struct ObjAttrDesc
{
	Word iFldNum;
	char *pszAttributeName;
} ;
#pragma pack(pop)

struct ObjTypeDesc;
typedef ObjTypeDesc *pObjTypeDesc;

#pragma pack(push, 1)
struct ObjTypeDesc
{
	Word iFldNum;
	char szTypeName[32];
} ;
#pragma pack(pop)

struct ObjParentDesc;
typedef ObjParentDesc *pObjParentDesc;

#pragma pack(push, 1)
struct ObjParentDesc
{
	Word iFldNum;
	Word iParentFldNum;
} ;
#pragma pack(pop)

typedef Word SQLResult;

#pragma option push -b
enum CBType { cbGENERAL, cbRESERVED1, cbRESERVED2, cbINPUTREQ, cbRESERVED4, cbRESERVED5, cbBATCHRESULT, cbRESERVED7, cbRESTRUCTURE, cbRESERVED9, cbRESERVED10, cbRESERVED11, cbRESERVED12, cbRESERVED13, cbRESERVED14, cbRESERVED15, cbRESERVED16, cbRESERVED17, cbTABLECHANGED, cbRESERVED19, cbCANCELQRY, cbSERVERCALL, cbRESERVED22, cbGENPROGRESS, cbDBASELOGIN, cbDELAYEDUPD, cbFIELDRECALC, cbTRACE, cbDBLOGIN, cbDETACHNOTIFY, cbNBROFCBS };
#pragma option pop

typedef CBType *pCBType;

#pragma option push -b
enum TSQLDriverOption { eDrvBlobSize, eDrvCallBack, eDrvCallBackInfo, eDrvRestrict };
#pragma option pop

#pragma option push -b
enum TSQLConnectionOption { eConnAutoCommit, eConnBlockingMode, eConnBlobSize, eConnRoleName, eConnWaitOnLocks, eConnCommitRetain, eConnTxnIsoLevel, eConnNativeHandle, eConnServerVersion, eConnCallBack, eConnHostName, eConnDatabaseName, eConnCallBackInfo, eConnObjectMode, eConnMaxActiveConnection, eConnServerCharSet, eConnSqlDialect };
#pragma option pop

#pragma option push -b
enum TSQLCommandOption { eCommRowsetSize, eCommBlobSize, eCommBlockRead, eCommBlockWrite, eCommParamCount, eCommNativeHandle, eCommCursorName, eCommStoredProc, eCommSQLDialect, eCommTransactionID };
#pragma option pop

#pragma option push -b
enum TSQLCursorOption { eCurObjectAttrName, eCurObjectTypeName, eCurParentFieldID };
#pragma option pop

#pragma option push -b
enum CBRType { cbrUSEDEF, cbrCONTINUE, cbrABORT, cbrCHKINPUT, cbrYES, cbrNO, cbrPARTIALASSIST, cbrSKIP, cbrRETRY };
#pragma option pop

#pragma option push -b
enum TSQLMetaDataOption { eMetaCatalogName, eMetaSchemaName, eMetaDatabaseName, eMetaDatabaseVersion, eMetaTransactionIsoLevel, eMetaSupportsTransaction, eMetaMaxObjectNameLength, eMetaMaxColumnsInTable, eMetaMaxColumnsInSelect, eMetaMaxRowSize, eMetaMaxSQLLength, eMetaObjectQuoteChar, eMetaSQLEscapeChar, eMetaProcSupportsCursor, eMetaProcSupportsCursors, eMetaSupportsTransactions };
#pragma option pop

#pragma option push -b
enum TSQLObjectType { eObjTypeDatabase, eObjTypeDataType, eObjTypeTable, eObjTypeView, eObjTypeSynonym, eObjTypeProcedure, eObjTypeUser, eObjTypeRole, eObjTypeUDT };
#pragma option pop

#pragma option push -b
enum TTransIsolationLevel { xilREADCOMMITTED, xilREPEATABLEREAD, xilDIRTYREAD, xilCUSTOM };
#pragma option pop

struct TTransactionDesc;
typedef TTransactionDesc *pTTransactionDesc;

#pragma pack(push, 1)
struct TTransactionDesc
{
	unsigned TransactionID;
	unsigned GlobalID;
	TTransIsolationLevel IsolationLevel;
	unsigned CustomIsolation;
} ;
#pragma pack(pop)

#pragma option push -b
enum TSTMTParamType { paramUNKNOWN, paramIN, paramOUT, paramINOUT, paramRET };
#pragma option pop

typedef int TypedEnum;

typedef int SQLDATE;

typedef int SQLTIME;

typedef int *pTRACECat;

typedef int TRACECat;

typedef CBRType __stdcall (*TSQLCallbackEvent)(int CallType, void * CBInfo);

__interface ISQLDriver;
typedef System::DelphiInterface<ISQLDriver> _di_ISQLDriver;
typedef _di_ISQLDriver *pSQLDriver;

__interface ISQLConnection;
typedef System::DelphiInterface<ISQLConnection> _di_ISQLConnection;
typedef _di_ISQLConnection *pSQLConnection;

__interface ISQLCommand;
typedef System::DelphiInterface<ISQLCommand> _di_ISQLCommand;
typedef _di_ISQLCommand *pSQLCommand;

__interface ISQLCursor;
typedef System::DelphiInterface<ISQLCursor> _di_ISQLCursor;
typedef _di_ISQLCursor *pSQLCursor;

__interface ISQLDriver  : public IInterface 
{
	
public:
	virtual Word __stdcall getSQLConnection(/* out */ _di_ISQLConnection &pConn) = 0 ;
	virtual Word __stdcall SetOption(TSQLDriverOption eDOption, int PropValue) = 0 ;
	virtual Word __stdcall GetOption(TSQLDriverOption eDOption, void * PropValue, short MaxLength, /* out */ short &Length) = 0 ;
};

__interface ISQLMetaData;
typedef System::DelphiInterface<ISQLMetaData> _di_ISQLMetaData;
__interface ISQLConnection  : public IInterface 
{
	
public:
	virtual Word __stdcall connect(char * ServerName, char * UserName, char * Password) = 0 ;
	virtual Word __stdcall disconnect(void) = 0 ;
	virtual Word __stdcall getSQLCommand(/* out */ _di_ISQLCommand &pComm) = 0 ;
	virtual Word __stdcall getSQLMetaData(/* out */ _di_ISQLMetaData &pMetaData) = 0 ;
	virtual Word __stdcall SetOption(TSQLConnectionOption eConnectOption, int lValue) = 0 ;
	virtual Word __stdcall GetOption(TSQLConnectionOption eDOption, void * PropValue, short MaxLength, /* out */ short &Length) = 0 ;
	virtual Word __stdcall beginTransaction(unsigned TranID) = 0 ;
	virtual Word __stdcall commit(unsigned TranID) = 0 ;
	virtual Word __stdcall rollback(unsigned TranID) = 0 ;
	virtual Word __stdcall getErrorMessage(char * Error) = 0 /* overload */;
	virtual Word __stdcall getErrorMessageLen(/* out */ short &ErrorLen) = 0 ;
};

__interface ISQLCommand  : public IInterface 
{
	
public:
	virtual Word __stdcall SetOption(TSQLCommandOption eSqlCommandOption, int ulValue) = 0 ;
	virtual Word __stdcall GetOption(TSQLCommandOption eSqlCommandOption, int &pValue, short MaxLength, /* out */ short &Length) = 0 ;
	virtual Word __stdcall setParameter(Word ulParameter, Word ulChildPos, TSTMTParamType eParamType, Word uLogType, Word uSubType, int iPrecision, int iScale, unsigned Length, void * pBuffer, int lInd) = 0 ;
	virtual Word __stdcall getParameter(Word ParameterNumber, Word ulChildPos, void * Value, int Length, int &IsBlank) = 0 ;
	virtual Word __stdcall prepare(char * SQL, Word ParamCount) = 0 ;
	virtual Word __stdcall execute(_di_ISQLCursor &Cursor) = 0 ;
	virtual Word __stdcall executeImmediate(char * SQL, _di_ISQLCursor &Cursor) = 0 ;
	virtual Word __stdcall getNextCursor(_di_ISQLCursor &Cursor) = 0 ;
	virtual Word __stdcall getRowsAffected(unsigned &Rows) = 0 ;
	virtual Word __stdcall close(void) = 0 ;
	virtual Word __stdcall getErrorMessage(char * Error) = 0 /* overload */;
	virtual Word __stdcall getErrorMessageLen(/* out */ short &ErrorLen) = 0 ;
};

__interface ISQLCursor  : public IInterface 
{
	
public:
	virtual Word __stdcall SetOption(TSQLCursorOption eOption, int PropValue) = 0 ;
	virtual Word __stdcall GetOption(TSQLCursorOption eOption, void * PropValue, short MaxLength, /* out */ short &Length) = 0 ;
	virtual Word __stdcall getErrorMessage(char * Error) = 0 /* overload */;
	virtual Word __stdcall getErrorMessageLen(/* out */ short &ErrorLen) = 0 ;
	virtual Word __stdcall getColumnCount(Word &pColumns) = 0 ;
	virtual Word __stdcall getColumnNameLength(Word ColumnNumber, Word &pLen) = 0 ;
	virtual Word __stdcall getColumnName(Word ColumnNumber, char * pColumnName) = 0 ;
	virtual Word __stdcall getColumnType(Word ColumnNumber, Word &puType, Word &puSubType) = 0 ;
	virtual Word __stdcall getColumnLength(Word ColumnNumber, unsigned &pLength) = 0 ;
	virtual Word __stdcall getColumnPrecision(Word ColumnNumber, short &piPrecision) = 0 ;
	virtual Word __stdcall getColumnScale(Word ColumnNumber, short &piScale) = 0 ;
	virtual Word __stdcall isNullable(Word ColumnNumber, BOOL &Nullable) = 0 ;
	virtual Word __stdcall isAutoIncrement(Word ColumnNumber, BOOL &AutoIncr) = 0 ;
	virtual Word __stdcall isReadOnly(Word ColumnNumber, BOOL &ReadOnly) = 0 ;
	virtual Word __stdcall isSearchable(Word ColumnNumber, BOOL &Searchable) = 0 ;
	virtual Word __stdcall isBlobSizeExact(Word ColumnNumber, BOOL &IsExact) = 0 ;
	virtual Word __stdcall next(void) = 0 ;
	virtual Word __stdcall getString(Word ColumnNumber, void * Value, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getShort(Word ColumnNumber, void * Value, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getLong(Word ColumnNumber, void * Value, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getDouble(Word ColumnNumber, void * Value, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getBcd(Word ColumnNumber, void * Value, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getTimeStamp(Word ColumnNumber, void * Value, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getTime(Word ColumnNumber, void * Value, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getDate(Word ColumnNumber, void * Value, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getBytes(Word ColumnNumber, void * Value, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getBlobSize(Word ColumnNumber, unsigned &Length, BOOL &IsBlank) = 0 ;
	virtual Word __stdcall getBlob(Word ColumnNumber, void * Value, BOOL &IsBlank, unsigned Length) = 0 ;
};

__interface ISQLMetaData  : public IInterface 
{
	
public:
	virtual Word __stdcall SetOption(TSQLMetaDataOption eDOption, int PropValue) = 0 ;
	virtual Word __stdcall GetOption(TSQLMetaDataOption eDOption, void * PropValue, short MaxLength, /* out */ short &Length) = 0 ;
	virtual Word __stdcall getObjectList(TSQLObjectType eObjType, /* out */ _di_ISQLCursor &Cursor) = 0 ;
	virtual Word __stdcall getTables(char * TableName, unsigned TableType, /* out */ _di_ISQLCursor &Cursor) = 0 ;
	virtual Word __stdcall getProcedures(char * ProcedureName, unsigned ProcType, /* out */ _di_ISQLCursor &Cursor) = 0 ;
	virtual Word __stdcall getColumns(char * TableName, char * ColumnName, unsigned ColType, /* out */ _di_ISQLCursor &Cursor) = 0 ;
	virtual Word __stdcall getProcedureParams(char * ProcName, char * ParamName, /* out */ _di_ISQLCursor &Cursor) = 0 ;
	virtual Word __stdcall getIndices(char * TableName, unsigned IndexType, /* out */ _di_ISQLCursor &Cursor) = 0 ;
	virtual Word __stdcall getErrorMessage(char * Error) = 0 /* overload */;
	virtual Word __stdcall getErrorMessageLen(/* out */ short &ErrorLen) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
static const Shortint MAXNAMELEN = 0x40;
static const Shortint SQL_ERROR = 0xffffffff;
static const Shortint SQL_NULL_DATA = 0x64;
static const Shortint SQL_ERROR_EOF = 0x65;
static const Shortint SQL_SUCCESS = 0x0;
static const Shortint DBXERR_NOMEMORY = 0x1;
static const Shortint DBXERR_INVALIDFLDTYPE = 0x2;
static const Shortint DBXERR_INVALIDHNDL = 0x3;
static const Shortint DBXERR_INVALIDTIME = 0x4;
static const Shortint DBXERR_NOTSUPPORTED = 0x5;
static const Shortint DBXERR_INVALIDXLATION = 0x6;
static const Shortint DBXERR_INVALIDPARAM = 0x7;
static const Shortint DBXERR_OUTOFRANGE = 0x8;
static const Shortint DBXERR_SQLPARAMNOTSET = 0x9;
static const Shortint DBXERR_EOF = 0xa;
static const Shortint DBXERR_INVALIDUSRPASS = 0xb;
static const Shortint DBXERR_INVALIDPRECISION = 0xc;
static const Shortint DBXERR_INVALIDLEN = 0xd;
static const Shortint DBXERR_INVALIDXISOLEVEL = 0xe;
static const Shortint DBXERR_INVALIDXTXNID = 0xf;
static const Shortint DBXERR_DUPLICATETXNID = 0x10;
static const Shortint DBXERR_DRIVERRESTRICTED = 0x11;
static const Shortint DBX_MAXSTATICERRORS = 0x12;
static const Byte MaxReservedStaticErrors = 0xff;
static const Shortint trUNKNOWN = 0x0;
static const Shortint trQPREPARE = 0x1;
static const Shortint trQEXECUTE = 0x2;
static const Shortint trERROR = 0x4;
static const Shortint trSTMT = 0x8;
static const Shortint trCONNECT = 0x10;
static const Shortint trTRANSACT = 0x20;
static const Shortint trBLOB = 0x40;
static const Byte trMISC = 0x80;
static const Word trVENDOR = 0x100;
static const Word trDATAIN = 0x200;
static const Word trDATAOUT = 0x400;
static const Shortint eSQLTable = 0x1;
static const Shortint eSQLView = 0x2;
static const Shortint eSQLSystemTable = 0x4;
static const Shortint eSQLSynonym = 0x8;
static const Shortint eSQLTempTable = 0x10;
static const Shortint eSQLLocal = 0x20;
static const Shortint eSQLProcedure = 0x1;
static const Shortint eSQLFunction = 0x2;
static const Shortint eSQLPackage = 0x4;
static const Shortint eSQLSysProcedure = 0x8;
static const Shortint eSQLRowId = 0x1;
static const Shortint eSQLRowVersion = 0x2;
static const Shortint eSQLAutoIncr = 0x4;
static const Shortint eSQLDefault = 0x8;
static const Shortint eSQLNonUnique = 0x1;
static const Shortint eSQLUnique = 0x2;
static const Shortint eSQLPrimaryKey = 0x4;
static const Shortint fldUNKNOWN = 0x0;
static const Shortint fldZSTRING = 0x1;
static const Shortint fldDATE = 0x2;
static const Shortint fldBLOB = 0x3;
static const Shortint fldBOOL = 0x4;
static const Shortint fldINT16 = 0x5;
static const Shortint fldINT32 = 0x6;
static const Shortint fldFLOAT = 0x7;
static const Shortint fldBCD = 0x8;
static const Shortint fldBYTES = 0x9;
static const Shortint fldTIME = 0xa;
static const Shortint fldTIMESTAMP = 0xb;
static const Shortint fldUINT16 = 0xc;
static const Shortint fldUINT32 = 0xd;
static const Shortint fldFLOATIEEE = 0xe;
static const Shortint fldVARBYTES = 0xf;
static const Shortint fldLOCKINFO = 0x10;
static const Shortint fldCURSOR = 0x11;
static const Shortint fldINT64 = 0x12;
static const Shortint fldUINT64 = 0x13;
static const Shortint fldADT = 0x14;
static const Shortint fldARRAY = 0x15;
static const Shortint fldREF = 0x16;
static const Shortint fldTABLE = 0x17;
static const Shortint fldDATETIME = 0x18;
static const Shortint fldFMTBCD = 0x19;
static const Shortint MAXLOGFLDTYPES = 0x1a;
static const Shortint fldstMONEY = 0x15;
static const Shortint fldstMEMO = 0x16;
static const Shortint fldstBINARY = 0x17;
static const Shortint fldstFMTMEMO = 0x18;
static const Shortint fldstOLEOBJ = 0x19;
static const Shortint fldstGRAPHIC = 0x1a;
static const Shortint fldstDBSOLEOBJ = 0x1b;
static const Shortint fldstTYPEDBINARY = 0x1c;
static const Shortint fldstACCOLEOBJ = 0x1e;
static const Shortint fldstHMEMO = 0x21;
static const Shortint fldstHBINARY = 0x22;
static const Shortint fldstBFILE = 0x24;
static const Shortint fldstPASSWORD = 0x1;
static const Shortint fldstFIXED = 0x1f;
static const Shortint fldstUNICODE = 0x20;
static const Shortint fldstAUTOINC = 0x1d;
static const Shortint fldstADTNestedTable = 0x23;
static const Shortint fldstADTDATE = 0x25;
extern PACKAGE Word __stdcall (*getSQLDriver)(char * VendorLib, char * SResourceFile, /* out */ void *pDriver);

}	/* namespace Dbxpress */
using namespace Dbxpress;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBXpress
