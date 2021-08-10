#pragma option push -b -a8 -pc -A- /*P_O_Push*/

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0266 */
/* at Thu May 27 02:10:44 1999
 */
/* Compiler settings for oledb.idl:
    Oicf (OptLev=i2), W1, Zp2, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __oledb_h__
#define __oledb_h__


#ifndef GUID_DEFS_ONLY

/* Forward Declarations */ 

#ifndef __IAccessor_FWD_DEFINED__
#define __IAccessor_FWD_DEFINED__
typedef interface IAccessor IAccessor;
#endif 	/* __IAccessor_FWD_DEFINED__ */


#ifndef __IRowset_FWD_DEFINED__
#define __IRowset_FWD_DEFINED__
typedef interface IRowset IRowset;
#endif 	/* __IRowset_FWD_DEFINED__ */


#ifndef __IRowsetInfo_FWD_DEFINED__
#define __IRowsetInfo_FWD_DEFINED__
typedef interface IRowsetInfo IRowsetInfo;
#endif 	/* __IRowsetInfo_FWD_DEFINED__ */


#ifndef __IRowsetLocate_FWD_DEFINED__
#define __IRowsetLocate_FWD_DEFINED__
typedef interface IRowsetLocate IRowsetLocate;
#endif 	/* __IRowsetLocate_FWD_DEFINED__ */


#ifndef __IRowsetResynch_FWD_DEFINED__
#define __IRowsetResynch_FWD_DEFINED__
typedef interface IRowsetResynch IRowsetResynch;
#endif 	/* __IRowsetResynch_FWD_DEFINED__ */


#ifndef __IRowsetScroll_FWD_DEFINED__
#define __IRowsetScroll_FWD_DEFINED__
typedef interface IRowsetScroll IRowsetScroll;
#endif 	/* __IRowsetScroll_FWD_DEFINED__ */


#ifndef __IChapteredRowset_FWD_DEFINED__
#define __IChapteredRowset_FWD_DEFINED__
typedef interface IChapteredRowset IChapteredRowset;
#endif 	/* __IChapteredRowset_FWD_DEFINED__ */


#ifndef __IRowsetFind_FWD_DEFINED__
#define __IRowsetFind_FWD_DEFINED__
typedef interface IRowsetFind IRowsetFind;
#endif 	/* __IRowsetFind_FWD_DEFINED__ */


#ifndef __IRowPosition_FWD_DEFINED__
#define __IRowPosition_FWD_DEFINED__
typedef interface IRowPosition IRowPosition;
#endif 	/* __IRowPosition_FWD_DEFINED__ */


#ifndef __IRowPositionChange_FWD_DEFINED__
#define __IRowPositionChange_FWD_DEFINED__
typedef interface IRowPositionChange IRowPositionChange;
#endif 	/* __IRowPositionChange_FWD_DEFINED__ */


#ifndef __IViewRowset_FWD_DEFINED__
#define __IViewRowset_FWD_DEFINED__
typedef interface IViewRowset IViewRowset;
#endif 	/* __IViewRowset_FWD_DEFINED__ */


#ifndef __IViewChapter_FWD_DEFINED__
#define __IViewChapter_FWD_DEFINED__
typedef interface IViewChapter IViewChapter;
#endif 	/* __IViewChapter_FWD_DEFINED__ */


#ifndef __IViewSort_FWD_DEFINED__
#define __IViewSort_FWD_DEFINED__
typedef interface IViewSort IViewSort;
#endif 	/* __IViewSort_FWD_DEFINED__ */


#ifndef __IViewFilter_FWD_DEFINED__
#define __IViewFilter_FWD_DEFINED__
typedef interface IViewFilter IViewFilter;
#endif 	/* __IViewFilter_FWD_DEFINED__ */


#ifndef __IRowsetView_FWD_DEFINED__
#define __IRowsetView_FWD_DEFINED__
typedef interface IRowsetView IRowsetView;
#endif 	/* __IRowsetView_FWD_DEFINED__ */


#ifndef __IRowsetExactScroll_FWD_DEFINED__
#define __IRowsetExactScroll_FWD_DEFINED__
typedef interface IRowsetExactScroll IRowsetExactScroll;
#endif 	/* __IRowsetExactScroll_FWD_DEFINED__ */


#ifndef __IRowsetChange_FWD_DEFINED__
#define __IRowsetChange_FWD_DEFINED__
typedef interface IRowsetChange IRowsetChange;
#endif 	/* __IRowsetChange_FWD_DEFINED__ */


#ifndef __IRowsetUpdate_FWD_DEFINED__
#define __IRowsetUpdate_FWD_DEFINED__
typedef interface IRowsetUpdate IRowsetUpdate;
#endif 	/* __IRowsetUpdate_FWD_DEFINED__ */


#ifndef __IRowsetIdentity_FWD_DEFINED__
#define __IRowsetIdentity_FWD_DEFINED__
typedef interface IRowsetIdentity IRowsetIdentity;
#endif 	/* __IRowsetIdentity_FWD_DEFINED__ */


#ifndef __IRowsetNotify_FWD_DEFINED__
#define __IRowsetNotify_FWD_DEFINED__
typedef interface IRowsetNotify IRowsetNotify;
#endif 	/* __IRowsetNotify_FWD_DEFINED__ */


#ifndef __IRowsetIndex_FWD_DEFINED__
#define __IRowsetIndex_FWD_DEFINED__
typedef interface IRowsetIndex IRowsetIndex;
#endif 	/* __IRowsetIndex_FWD_DEFINED__ */


#ifndef __ICommand_FWD_DEFINED__
#define __ICommand_FWD_DEFINED__
typedef interface ICommand ICommand;
#endif 	/* __ICommand_FWD_DEFINED__ */


#ifndef __IMultipleResults_FWD_DEFINED__
#define __IMultipleResults_FWD_DEFINED__
typedef interface IMultipleResults IMultipleResults;
#endif 	/* __IMultipleResults_FWD_DEFINED__ */


#ifndef __IConvertType_FWD_DEFINED__
#define __IConvertType_FWD_DEFINED__
typedef interface IConvertType IConvertType;
#endif 	/* __IConvertType_FWD_DEFINED__ */


#ifndef __ICommandPrepare_FWD_DEFINED__
#define __ICommandPrepare_FWD_DEFINED__
typedef interface ICommandPrepare ICommandPrepare;
#endif 	/* __ICommandPrepare_FWD_DEFINED__ */


#ifndef __ICommandProperties_FWD_DEFINED__
#define __ICommandProperties_FWD_DEFINED__
typedef interface ICommandProperties ICommandProperties;
#endif 	/* __ICommandProperties_FWD_DEFINED__ */


#ifndef __ICommandText_FWD_DEFINED__
#define __ICommandText_FWD_DEFINED__
typedef interface ICommandText ICommandText;
#endif 	/* __ICommandText_FWD_DEFINED__ */


#ifndef __ICommandWithParameters_FWD_DEFINED__
#define __ICommandWithParameters_FWD_DEFINED__
typedef interface ICommandWithParameters ICommandWithParameters;
#endif 	/* __ICommandWithParameters_FWD_DEFINED__ */


#ifndef __IColumnsRowset_FWD_DEFINED__
#define __IColumnsRowset_FWD_DEFINED__
typedef interface IColumnsRowset IColumnsRowset;
#endif 	/* __IColumnsRowset_FWD_DEFINED__ */


#ifndef __IColumnsInfo_FWD_DEFINED__
#define __IColumnsInfo_FWD_DEFINED__
typedef interface IColumnsInfo IColumnsInfo;
#endif 	/* __IColumnsInfo_FWD_DEFINED__ */


#ifndef __IDBCreateCommand_FWD_DEFINED__
#define __IDBCreateCommand_FWD_DEFINED__
typedef interface IDBCreateCommand IDBCreateCommand;
#endif 	/* __IDBCreateCommand_FWD_DEFINED__ */


#ifndef __IDBCreateSession_FWD_DEFINED__
#define __IDBCreateSession_FWD_DEFINED__
typedef interface IDBCreateSession IDBCreateSession;
#endif 	/* __IDBCreateSession_FWD_DEFINED__ */


#ifndef __ISourcesRowset_FWD_DEFINED__
#define __ISourcesRowset_FWD_DEFINED__
typedef interface ISourcesRowset ISourcesRowset;
#endif 	/* __ISourcesRowset_FWD_DEFINED__ */


#ifndef __IDBProperties_FWD_DEFINED__
#define __IDBProperties_FWD_DEFINED__
typedef interface IDBProperties IDBProperties;
#endif 	/* __IDBProperties_FWD_DEFINED__ */


#ifndef __IDBInitialize_FWD_DEFINED__
#define __IDBInitialize_FWD_DEFINED__
typedef interface IDBInitialize IDBInitialize;
#endif 	/* __IDBInitialize_FWD_DEFINED__ */


#ifndef __IDBInfo_FWD_DEFINED__
#define __IDBInfo_FWD_DEFINED__
typedef interface IDBInfo IDBInfo;
#endif 	/* __IDBInfo_FWD_DEFINED__ */


#ifndef __IDBDataSourceAdmin_FWD_DEFINED__
#define __IDBDataSourceAdmin_FWD_DEFINED__
typedef interface IDBDataSourceAdmin IDBDataSourceAdmin;
#endif 	/* __IDBDataSourceAdmin_FWD_DEFINED__ */


#ifndef __IDBAsynchNotify_FWD_DEFINED__
#define __IDBAsynchNotify_FWD_DEFINED__
typedef interface IDBAsynchNotify IDBAsynchNotify;
#endif 	/* __IDBAsynchNotify_FWD_DEFINED__ */


#ifndef __IDBAsynchStatus_FWD_DEFINED__
#define __IDBAsynchStatus_FWD_DEFINED__
typedef interface IDBAsynchStatus IDBAsynchStatus;
#endif 	/* __IDBAsynchStatus_FWD_DEFINED__ */


#ifndef __ISessionProperties_FWD_DEFINED__
#define __ISessionProperties_FWD_DEFINED__
typedef interface ISessionProperties ISessionProperties;
#endif 	/* __ISessionProperties_FWD_DEFINED__ */


#ifndef __IIndexDefinition_FWD_DEFINED__
#define __IIndexDefinition_FWD_DEFINED__
typedef interface IIndexDefinition IIndexDefinition;
#endif 	/* __IIndexDefinition_FWD_DEFINED__ */


#ifndef __ITableDefinition_FWD_DEFINED__
#define __ITableDefinition_FWD_DEFINED__
typedef interface ITableDefinition ITableDefinition;
#endif 	/* __ITableDefinition_FWD_DEFINED__ */


#ifndef __IOpenRowset_FWD_DEFINED__
#define __IOpenRowset_FWD_DEFINED__
typedef interface IOpenRowset IOpenRowset;
#endif 	/* __IOpenRowset_FWD_DEFINED__ */


#ifndef __IDBSchemaRowset_FWD_DEFINED__
#define __IDBSchemaRowset_FWD_DEFINED__
typedef interface IDBSchemaRowset IDBSchemaRowset;
#endif 	/* __IDBSchemaRowset_FWD_DEFINED__ */


#ifndef __IMDDataset_FWD_DEFINED__
#define __IMDDataset_FWD_DEFINED__
typedef interface IMDDataset IMDDataset;
#endif 	/* __IMDDataset_FWD_DEFINED__ */


#ifndef __IMDFind_FWD_DEFINED__
#define __IMDFind_FWD_DEFINED__
typedef interface IMDFind IMDFind;
#endif 	/* __IMDFind_FWD_DEFINED__ */


#ifndef __IMDRangeRowset_FWD_DEFINED__
#define __IMDRangeRowset_FWD_DEFINED__
typedef interface IMDRangeRowset IMDRangeRowset;
#endif 	/* __IMDRangeRowset_FWD_DEFINED__ */


#ifndef __IAlterTable_FWD_DEFINED__
#define __IAlterTable_FWD_DEFINED__
typedef interface IAlterTable IAlterTable;
#endif 	/* __IAlterTable_FWD_DEFINED__ */


#ifndef __IAlterIndex_FWD_DEFINED__
#define __IAlterIndex_FWD_DEFINED__
typedef interface IAlterIndex IAlterIndex;
#endif 	/* __IAlterIndex_FWD_DEFINED__ */


#ifndef __IRowsetChapterMember_FWD_DEFINED__
#define __IRowsetChapterMember_FWD_DEFINED__
typedef interface IRowsetChapterMember IRowsetChapterMember;
#endif 	/* __IRowsetChapterMember_FWD_DEFINED__ */


#ifndef __ICommandPersist_FWD_DEFINED__
#define __ICommandPersist_FWD_DEFINED__
typedef interface ICommandPersist ICommandPersist;
#endif 	/* __ICommandPersist_FWD_DEFINED__ */


#ifndef __IRowsetRefresh_FWD_DEFINED__
#define __IRowsetRefresh_FWD_DEFINED__
typedef interface IRowsetRefresh IRowsetRefresh;
#endif 	/* __IRowsetRefresh_FWD_DEFINED__ */


#ifndef __IParentRowset_FWD_DEFINED__
#define __IParentRowset_FWD_DEFINED__
typedef interface IParentRowset IParentRowset;
#endif 	/* __IParentRowset_FWD_DEFINED__ */


#ifndef __IErrorRecords_FWD_DEFINED__
#define __IErrorRecords_FWD_DEFINED__
typedef interface IErrorRecords IErrorRecords;
#endif 	/* __IErrorRecords_FWD_DEFINED__ */


#ifndef __IErrorLookup_FWD_DEFINED__
#define __IErrorLookup_FWD_DEFINED__
typedef interface IErrorLookup IErrorLookup;
#endif 	/* __IErrorLookup_FWD_DEFINED__ */


#ifndef __ISQLErrorInfo_FWD_DEFINED__
#define __ISQLErrorInfo_FWD_DEFINED__
typedef interface ISQLErrorInfo ISQLErrorInfo;
#endif 	/* __ISQLErrorInfo_FWD_DEFINED__ */


#ifndef __IGetDataSource_FWD_DEFINED__
#define __IGetDataSource_FWD_DEFINED__
typedef interface IGetDataSource IGetDataSource;
#endif 	/* __IGetDataSource_FWD_DEFINED__ */


#ifndef __ITransactionLocal_FWD_DEFINED__
#define __ITransactionLocal_FWD_DEFINED__
typedef interface ITransactionLocal ITransactionLocal;
#endif 	/* __ITransactionLocal_FWD_DEFINED__ */


#ifndef __ITransactionJoin_FWD_DEFINED__
#define __ITransactionJoin_FWD_DEFINED__
typedef interface ITransactionJoin ITransactionJoin;
#endif 	/* __ITransactionJoin_FWD_DEFINED__ */


#ifndef __ITransactionObject_FWD_DEFINED__
#define __ITransactionObject_FWD_DEFINED__
typedef interface ITransactionObject ITransactionObject;
#endif 	/* __ITransactionObject_FWD_DEFINED__ */


#ifndef __ITrusteeAdmin_FWD_DEFINED__
#define __ITrusteeAdmin_FWD_DEFINED__
typedef interface ITrusteeAdmin ITrusteeAdmin;
#endif 	/* __ITrusteeAdmin_FWD_DEFINED__ */


#ifndef __ITrusteeGroupAdmin_FWD_DEFINED__
#define __ITrusteeGroupAdmin_FWD_DEFINED__
typedef interface ITrusteeGroupAdmin ITrusteeGroupAdmin;
#endif 	/* __ITrusteeGroupAdmin_FWD_DEFINED__ */


#ifndef __IObjectAccessControl_FWD_DEFINED__
#define __IObjectAccessControl_FWD_DEFINED__
typedef interface IObjectAccessControl IObjectAccessControl;
#endif 	/* __IObjectAccessControl_FWD_DEFINED__ */


#ifndef __ISecurityInfo_FWD_DEFINED__
#define __ISecurityInfo_FWD_DEFINED__
typedef interface ISecurityInfo ISecurityInfo;
#endif 	/* __ISecurityInfo_FWD_DEFINED__ */


#ifndef __ITableCreation_FWD_DEFINED__
#define __ITableCreation_FWD_DEFINED__
typedef interface ITableCreation ITableCreation;
#endif 	/* __ITableCreation_FWD_DEFINED__ */


#ifndef __ITableDefinitionWithConstraints_FWD_DEFINED__
#define __ITableDefinitionWithConstraints_FWD_DEFINED__
typedef interface ITableDefinitionWithConstraints ITableDefinitionWithConstraints;
#endif 	/* __ITableDefinitionWithConstraints_FWD_DEFINED__ */


#ifndef __IRow_FWD_DEFINED__
#define __IRow_FWD_DEFINED__
typedef interface IRow IRow;
#endif 	/* __IRow_FWD_DEFINED__ */


#ifndef __IRowChange_FWD_DEFINED__
#define __IRowChange_FWD_DEFINED__
typedef interface IRowChange IRowChange;
#endif 	/* __IRowChange_FWD_DEFINED__ */


#ifndef __IRowSchemaChange_FWD_DEFINED__
#define __IRowSchemaChange_FWD_DEFINED__
typedef interface IRowSchemaChange IRowSchemaChange;
#endif 	/* __IRowSchemaChange_FWD_DEFINED__ */


#ifndef __IGetRow_FWD_DEFINED__
#define __IGetRow_FWD_DEFINED__
typedef interface IGetRow IGetRow;
#endif 	/* __IGetRow_FWD_DEFINED__ */


#ifndef __IBindResource_FWD_DEFINED__
#define __IBindResource_FWD_DEFINED__
typedef interface IBindResource IBindResource;
#endif 	/* __IBindResource_FWD_DEFINED__ */


#ifndef __IScopedOperations_FWD_DEFINED__
#define __IScopedOperations_FWD_DEFINED__
typedef interface IScopedOperations IScopedOperations;
#endif 	/* __IScopedOperations_FWD_DEFINED__ */


#ifndef __ICreateRow_FWD_DEFINED__
#define __ICreateRow_FWD_DEFINED__
typedef interface ICreateRow ICreateRow;
#endif 	/* __ICreateRow_FWD_DEFINED__ */


#ifndef __IDBBinderProperties_FWD_DEFINED__
#define __IDBBinderProperties_FWD_DEFINED__
typedef interface IDBBinderProperties IDBBinderProperties;
#endif 	/* __IDBBinderProperties_FWD_DEFINED__ */


#ifndef __IColumnsInfo2_FWD_DEFINED__
#define __IColumnsInfo2_FWD_DEFINED__
typedef interface IColumnsInfo2 IColumnsInfo2;
#endif 	/* __IColumnsInfo2_FWD_DEFINED__ */


#ifndef __IRegisterProvider_FWD_DEFINED__
#define __IRegisterProvider_FWD_DEFINED__
typedef interface IRegisterProvider IRegisterProvider;
#endif 	/* __IRegisterProvider_FWD_DEFINED__ */


#ifndef __IGetSession_FWD_DEFINED__
#define __IGetSession_FWD_DEFINED__
typedef interface IGetSession IGetSession;
#endif 	/* __IGetSession_FWD_DEFINED__ */


#ifndef __IGetSourceRow_FWD_DEFINED__
#define __IGetSourceRow_FWD_DEFINED__
typedef interface IGetSourceRow IGetSourceRow;
#endif 	/* __IGetSourceRow_FWD_DEFINED__ */


#ifndef __IRowsetCurrentIndex_FWD_DEFINED__
#define __IRowsetCurrentIndex_FWD_DEFINED__
typedef interface IRowsetCurrentIndex IRowsetCurrentIndex;
#endif 	/* __IRowsetCurrentIndex_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "oaidl.h"
#include "ocidl.h"
#include "propidl.h"
#include "transact.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_oledb_0000 */
/* [local] */ 

//+---------------------------------------------------------------------------
//
//  Microsoft OLE DB
//  Copyright (C) Microsoft Corporation, 1994 - 1999.
//
//----------------------------------------------------------------------------

#ifdef _WIN64
#include <pshpack8.h>	// 8-byte structure packing
#else
#include <pshpack2.h>	// 2-byte structure packing
#endif

#endif // GUID_DEFS_ONLY

//
// OLEDBVER
//	OLE DB version number is 2.5 (0x0250); to force a particular version,
//	#define OLEDBVER as required before including this file.
//

// If OLEDBVER is not defined, assume version 2.5
#ifndef OLEDBVER
#define OLEDBVER 0x0250
#endif

#ifndef GUID_DEFS_ONLY

#ifdef _WIN64

// Length of a non-character object, size
typedef ULONGLONG			DBLENGTH;

// Offset within a rowset
typedef LONGLONG				DBROWOFFSET;

// Number of rows
typedef LONGLONG				DBROWCOUNT;

typedef ULONGLONG			DBCOUNTITEM;

// Ordinal (column number, etc.)
typedef ULONGLONG			DBORDINAL;

typedef LONGLONG				DB_LORDINAL;

// Bookmarks
typedef ULONGLONG			DBBKMARK;
// Offset in the buffer

typedef ULONGLONG			DBBYTEOFFSET;
// Reference count of each row/accessor  handle

typedef ULONG				DBREFCOUNT;

// Parameters
typedef ULONGLONG			DB_UPARAMS;

typedef LONGLONG				DB_LPARAMS;

// hash values corresponding to the elements (bookmarks)
typedef DWORDLONG			DBHASHVALUE;

// For reserve
typedef DWORDLONG			DB_DWRESERVE;

typedef LONGLONG				DB_LRESERVE;

typedef ULONGLONG			DB_URESERVE;

#else

// Length of a non-character object, size
typedef ULONG DBLENGTH;

// Offset within a rowset
typedef LONG DBROWOFFSET;

// Number of rows
typedef LONG DBROWCOUNT;

typedef ULONG DBCOUNTITEM;

// Ordinal (column number, etc.)
typedef ULONG DBORDINAL;

typedef LONG DB_LORDINAL;

// Bookmarks
typedef ULONG DBBKMARK;

// Offset in the buffer
typedef ULONG DBBYTEOFFSET;

// Reference count of each row handle
typedef ULONG DBREFCOUNT;

// Parameters
typedef ULONG DB_UPARAMS;

typedef LONG DB_LPARAMS;

// hash values corresponding to the elements (bookmarks)
typedef DWORD DBHASHVALUE;

// For reserve
typedef DWORD DB_DWRESERVE;

typedef LONG DB_LRESERVE;

typedef ULONG DB_URESERVE;

#endif	// _WIN64

#endif // GUID_DEFS_ONLY


extern RPC_IF_HANDLE __MIDL_itf_oledb_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0000_v0_0_s_ifspec;

#ifndef __DBStructureDefinitions_INTERFACE_DEFINED__
#define __DBStructureDefinitions_INTERFACE_DEFINED__

/* interface DBStructureDefinitions */
/* [auto_handle][unique][uuid] */ 

#ifndef UNALIGNED
#if defined(_MIPS_) || defined(_ALPHA_) || defined(_PPC_)
#define UNALIGNED __unaligned
#else
#define UNALIGNED
#endif
#endif //UNALIGNED
#undef OLEDBDECLSPEC
#if (_MSC_VER >= 1100) || defined(__BORLANDC__)
#define OLEDBDECLSPEC __declspec(selectany)
#else
#define OLEDBDECLSPEC 
#endif //_MSC_VER
typedef DWORD DBKIND;


enum DBKINDENUM
    {	DBKIND_GUID_NAME	= 0,
	DBKIND_GUID_PROPID	= DBKIND_GUID_NAME + 1,
	DBKIND_NAME	= DBKIND_GUID_PROPID + 1,
	DBKIND_PGUID_NAME	= DBKIND_NAME + 1,
	DBKIND_PGUID_PROPID	= DBKIND_PGUID_NAME + 1,
	DBKIND_PROPID	= DBKIND_PGUID_PROPID + 1,
	DBKIND_GUID	= DBKIND_PROPID + 1
    };
typedef struct tagDBID
    {
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ GUID guid;
        /* [case()] */ GUID __RPC_FAR *pguid;
        /* [default] */  /* Empty union arm */ 
        }	uGuid;
    DBKIND eKind;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ LPOLESTR pwszName;
        /* [case()] */ ULONG ulPropid;
        /* [default] */  /* Empty union arm */ 
        }	uName;
    }	DBID;

typedef struct tagDB_NUMERIC
    {
    BYTE precision;
    BYTE scale;
    BYTE sign;
    BYTE val[ 16 ];
    }	DB_NUMERIC;

#ifndef GUID_DEFS_ONLY

#ifndef _ULONGLONG_
typedef hyper LONGLONG;

typedef MIDL_uhyper ULONGLONG;

typedef LONGLONG __RPC_FAR *PLONGLONG;

typedef ULONGLONG __RPC_FAR *PULONGLONG;

#endif // _ULONGLONG_
#ifndef DECIMAL_NEG
#ifndef DECIMAL_SETZERO
typedef struct tagDEC {
    USHORT wReserved;
    union {
        struct {
            BYTE scale;
            BYTE sign;
        };
        USHORT signscale;
    };
    ULONG Hi32;
    union {
        struct {
#ifdef _MAC
            ULONG Mid32;
            ULONG Lo32;
#else
            ULONG Lo32;
            ULONG Mid32;
#endif
        };
        ULONGLONG Lo64;
    };
} DECIMAL;
#define DECIMAL_NEG ((BYTE)0x80)
#define DECIMAL_SETZERO(dec) {(dec).Lo64 = 0; (dec).Hi32 = 0; (dec).signscale = 0;}
#endif // DECIMAL_SETZERO
#endif // DECIMAL_NEG
typedef struct tagDBVECTOR
    {
    DBLENGTH size;
    /* [size_is] */ void __RPC_FAR *ptr;
    }	DBVECTOR;

typedef struct tagDBDATE
    {
    SHORT year;
    USHORT month;
    USHORT day;
    }	DBDATE;

typedef struct tagDBTIME
    {
    USHORT hour;
    USHORT minute;
    USHORT second;
    }	DBTIME;

typedef struct tagDBTIMESTAMP
    {
    SHORT year;
    USHORT month;
    USHORT day;
    USHORT hour;
    USHORT minute;
    USHORT second;
    ULONG fraction;
    }	DBTIMESTAMP;

//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
#if !defined(_WINBASE_) && !defined(_FILETIME_)
#define _FILETIME_
typedef struct _FILETIME {
		DWORD dwLowDateTime;
		DWORD dwHighDateTime;
     }	FILETIME;
#endif // !_FILETIME
#ifdef __BORLANDC__  /* This was removed by MS for some reason */
typedef struct  tagDBFILETIME     {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
    }	DBFILETIME;
#endif
typedef signed char SBYTE;

typedef struct tagDB_VARNUMERIC
    {
    BYTE precision;
    SBYTE scale;
    BYTE sign;
    BYTE val[ 1 ];
    }	DB_VARNUMERIC;

#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
typedef struct _SEC_OBJECT_ELEMENT
    {
    GUID guidObjectType;
    DBID ObjectID;
    }	SEC_OBJECT_ELEMENT;

typedef struct _SEC_OBJECT
    {
    DWORD cObjects;
    /* [size_is] */ SEC_OBJECT_ELEMENT __RPC_FAR *prgObjects;
    }	SEC_OBJECT;

typedef struct tagDBIMPLICITSESSION
    {
    IUnknown __RPC_FAR *pUnkOuter;
    IID __RPC_FAR *piid;
    IUnknown __RPC_FAR *pSession;
    }	DBIMPLICITSESSION;

#endif // OLEDBVER >= 0x0210
//@@@- V2.1
typedef WORD DBTYPE;


enum DBTYPEENUM
    {	DBTYPE_EMPTY	= 0,
	DBTYPE_NULL	= 1,
	DBTYPE_I2	= 2,
	DBTYPE_I4	= 3,
	DBTYPE_R4	= 4,
	DBTYPE_R8	= 5,
	DBTYPE_CY	= 6,
	DBTYPE_DATE	= 7,
	DBTYPE_BSTR	= 8,
	DBTYPE_IDISPATCH	= 9,
	DBTYPE_ERROR	= 10,
	DBTYPE_BOOL	= 11,
	DBTYPE_VARIANT	= 12,
	DBTYPE_IUNKNOWN	= 13,
	DBTYPE_DECIMAL	= 14,
	DBTYPE_UI1	= 17,
	DBTYPE_ARRAY	= 0x2000,
	DBTYPE_BYREF	= 0x4000,
	DBTYPE_I1	= 16,
	DBTYPE_UI2	= 18,
	DBTYPE_UI4	= 19,
	DBTYPE_I8	= 20,
	DBTYPE_UI8	= 21,
	DBTYPE_GUID	= 72,
	DBTYPE_VECTOR	= 0x1000,
	DBTYPE_RESERVED	= 0x8000,
	DBTYPE_BYTES	= 128,
	DBTYPE_STR	= 129,
	DBTYPE_WSTR	= 130,
	DBTYPE_NUMERIC	= 131,
	DBTYPE_UDT	= 132,
	DBTYPE_DBDATE	= 133,
	DBTYPE_DBTIME	= 134,
	DBTYPE_DBTIMESTAMP	= 135
    };
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )

enum DBTYPEENUM15
    {	DBTYPE_HCHAPTER	= 136
    };
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBTYPEENUM20
    {	DBTYPE_FILETIME	= 64,
#ifdef __BORLANDC__  /* This was removed by MS for some reason */
    DBTYPE_DBFILETIME = 137,
#endif
	DBTYPE_PROPVARIANT	= 138,
	DBTYPE_VARNUMERIC	= 139
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
typedef DWORD DBPART;


enum DBPARTENUM
    {	DBPART_INVALID	= 0,
	DBPART_VALUE	= 0x1,
	DBPART_LENGTH	= 0x2,
	DBPART_STATUS	= 0x4
    };
typedef DWORD DBPARAMIO;


enum DBPARAMIOENUM
    {	DBPARAMIO_NOTPARAM	= 0,
	DBPARAMIO_INPUT	= 0x1,
	DBPARAMIO_OUTPUT	= 0x2
    };
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )
typedef DWORD DBBINDFLAG;


enum DBBINDFLAGENUM
    {	DBBINDFLAG_HTML	= 0x1
    };
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
typedef DWORD DBMEMOWNER;


enum DBMEMOWNERENUM
    {	DBMEMOWNER_CLIENTOWNED	= 0,
	DBMEMOWNER_PROVIDEROWNED	= 0x1
    };
typedef struct tagDBOBJECT
    {
    DWORD dwFlags;
    IID iid;
    }	DBOBJECT;

typedef DWORD DBSTATUS;


enum DBSTATUSENUM
    {	DBSTATUS_S_OK	= 0,
	DBSTATUS_E_BADACCESSOR	= 1,
	DBSTATUS_E_CANTCONVERTVALUE	= 2,
	DBSTATUS_S_ISNULL	= 3,
	DBSTATUS_S_TRUNCATED	= 4,
	DBSTATUS_E_SIGNMISMATCH	= 5,
	DBSTATUS_E_DATAOVERFLOW	= 6,
	DBSTATUS_E_CANTCREATE	= 7,
	DBSTATUS_E_UNAVAILABLE	= 8,
	DBSTATUS_E_PERMISSIONDENIED	= 9,
	DBSTATUS_E_INTEGRITYVIOLATION	= 10,
	DBSTATUS_E_SCHEMAVIOLATION	= 11,
	DBSTATUS_E_BADSTATUS	= 12,
	DBSTATUS_S_DEFAULT	= 13
    };
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBSTATUSENUM20
    {	MDSTATUS_S_CELLEMPTY	= 14,
	DBSTATUS_S_IGNORE	= 15
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )

enum DBSTATUSENUM21
    {	DBSTATUS_E_DOESNOTEXIST	= 16,
	DBSTATUS_E_INVALIDURL	= 17,
	DBSTATUS_E_RESOURCELOCKED	= 18,
	DBSTATUS_E_RESOURCEEXISTS	= 19,
	DBSTATUS_E_CANNOTCOMPLETE	= 20,
	DBSTATUS_E_VOLUMENOTFOUND	= 21,
	DBSTATUS_E_OUTOFSPACE	= 22,
	DBSTATUS_S_CANNOTDELETESOURCE	= 23,
	DBSTATUS_E_READONLY	= 24,
	DBSTATUS_E_RESOURCEOUTOFSCOPE	= 25,
	DBSTATUS_S_ALREADYEXISTS	= 26
    };
typedef DWORD DBBINDURLFLAG;


enum DBBINDURLFLAGENUM
    {	DBBINDURLFLAG_READ	= 0x1L,
	DBBINDURLFLAG_WRITE	= 0x2L,
	DBBINDURLFLAG_READWRITE	= 0x3L,
	DBBINDURLFLAG_SHARE_DENY_READ	= 0x4L,
	DBBINDURLFLAG_SHARE_DENY_WRITE	= 0x8L,
	DBBINDURLFLAG_SHARE_EXCLUSIVE	= 0xcL,
	DBBINDURLFLAG_SHARE_DENY_NONE	= 0x10L,
	DBBINDURLFLAG_ASYNCHRONOUS	= 0x1000L,
	DBBINDURLFLAG_COLLECTION	= 0x2000L,
	DBBINDURLFLAG_DELAYFETCHSTREAM	= 0x4000L,
	DBBINDURLFLAG_DELAYFETCHCOLUMNS	= 0x8000L,
	DBBINDURLFLAG_RECURSIVE	= 0x400000L,
	DBBINDURLFLAG_OUTPUT	= 0x800000L,
	DBBINDURLFLAG_WAITFORINIT	= 0x1000000L,
	DBBINDURLFLAG_OPENIFEXISTS	= 0x2000000L,
	DBBINDURLFLAG_OVERWRITE	= 0x4000000L,
	DBBINDURLFLAG_ISSTRUCTUREDDOCUMENT	= 0x8000000L
    };
typedef DWORD DBBINDURLSTATUS;


enum DBBINDURLSTATUSENUM
    {	DBBINDURLSTATUS_S_OK	= 0L,
	DBBINDURLSTATUS_S_DENYNOTSUPPORTED	= 0x1L,
	DBBINDURLSTATUS_S_DENYTYPENOTSUPPORTED	= 0x4L,
	DBBINDURLSTATUS_S_REDIRECTED	= 0x8L
    };
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
//@@@+ V2.5
#if( OLEDBVER >= 0x0250 )

enum DBSTATUSENUM25
    {	DBSTATUS_E_CANCELED	= 27,
	DBSTATUS_E_NOTCOLLECTION	= 28
    };
#endif // OLEDBVER >= 0x0250
//@@@- V2.5
typedef struct tagDBBINDEXT
    {
    /* [size_is] */ BYTE __RPC_FAR *pExtension;
    DBCOUNTITEM ulExtension;
    }	DBBINDEXT;

typedef struct tagDBBINDING
    {
    DBORDINAL iOrdinal;
    DBBYTEOFFSET obValue;
    DBBYTEOFFSET obLength;
    DBBYTEOFFSET obStatus;
    ITypeInfo __RPC_FAR *pTypeInfo;
    DBOBJECT __RPC_FAR *pObject;
    DBBINDEXT __RPC_FAR *pBindExt;
    DBPART dwPart;
    DBMEMOWNER dwMemOwner;
    DBPARAMIO eParamIO;
    DBLENGTH cbMaxLen;
    DWORD dwFlags;
    DBTYPE wType;
    BYTE bPrecision;
    BYTE bScale;
    }	DBBINDING;

typedef DWORD DBROWSTATUS;


enum DBROWSTATUSENUM
    {	DBROWSTATUS_S_OK	= 0,
	DBROWSTATUS_S_MULTIPLECHANGES	= 2,
	DBROWSTATUS_S_PENDINGCHANGES	= 3,
	DBROWSTATUS_E_CANCELED	= 4,
	DBROWSTATUS_E_CANTRELEASE	= 6,
	DBROWSTATUS_E_CONCURRENCYVIOLATION	= 7,
	DBROWSTATUS_E_DELETED	= 8,
	DBROWSTATUS_E_PENDINGINSERT	= 9,
	DBROWSTATUS_E_NEWLYINSERTED	= 10,
	DBROWSTATUS_E_INTEGRITYVIOLATION	= 11,
	DBROWSTATUS_E_INVALID	= 12,
	DBROWSTATUS_E_MAXPENDCHANGESEXCEEDED	= 13,
	DBROWSTATUS_E_OBJECTOPEN	= 14,
	DBROWSTATUS_E_OUTOFMEMORY	= 15,
	DBROWSTATUS_E_PERMISSIONDENIED	= 16,
	DBROWSTATUS_E_LIMITREACHED	= 17,
	DBROWSTATUS_E_SCHEMAVIOLATION	= 18,
	DBROWSTATUS_E_FAIL	= 19
    };
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBROWSTATUSENUM20
    {	DBROWSTATUS_S_NOCHANGE	= 20
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
typedef ULONG_PTR HACCESSOR;

#define DB_NULL_HACCESSOR 0x00 // deprecated; use DB_INVALID_HACCESSOR instead
#define DB_INVALID_HACCESSOR 0x00
typedef ULONG_PTR HROW;

#define DB_NULL_HROW 0x00
typedef ULONG_PTR HWATCHREGION;

#define DBWATCHREGION_NULL NULL
typedef ULONG_PTR HCHAPTER;

#define DB_NULL_HCHAPTER 0x00
#define DB_INVALID_HCHAPTER 0x00	// deprecated; use DB_NULL_HCHAPTER instead
typedef struct tagDBFAILUREINFO
    {
    HROW hRow;
    DBORDINAL iColumn;
    HRESULT failure;
    }	DBFAILUREINFO;

typedef DWORD DBCOLUMNFLAGS;


enum DBCOLUMNFLAGSENUM
    {	DBCOLUMNFLAGS_ISBOOKMARK	= 0x1,
	DBCOLUMNFLAGS_MAYDEFER	= 0x2,
	DBCOLUMNFLAGS_WRITE	= 0x4,
	DBCOLUMNFLAGS_WRITEUNKNOWN	= 0x8,
	DBCOLUMNFLAGS_ISFIXEDLENGTH	= 0x10,
	DBCOLUMNFLAGS_ISNULLABLE	= 0x20,
	DBCOLUMNFLAGS_MAYBENULL	= 0x40,
	DBCOLUMNFLAGS_ISLONG	= 0x80,
	DBCOLUMNFLAGS_ISROWID	= 0x100,
	DBCOLUMNFLAGS_ISROWVER	= 0x200,
	DBCOLUMNFLAGS_CACHEDEFERRED	= 0x1000
    };
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBCOLUMNFLAGSENUM20
    {	DBCOLUMNFLAGS_SCALEISNEGATIVE	= 0x4000,
	DBCOLUMNFLAGS_RESERVED	= 0x8000
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ deprecated
#ifdef deprecated
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBCOLUMNFLAGSDEPRECATED
    {	DBCOLUMNFLAGS_KEYCOLUMN	= 0x8000
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
#endif // deprecated
//@@@- deprecated
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )

enum DBCOLUMNFLAGS15ENUM
    {	DBCOLUMNFLAGS_ISCHAPTER	= 0x2000
    };
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )

enum DBCOLUMNFLAGSENUM21
    {	DBCOLUMNFLAGS_ISROWURL	= 0x10000,
	DBCOLUMNFLAGS_ISDEFAULTSTREAM	= 0x20000,
	DBCOLUMNFLAGS_ISCOLLECTION	= 0x40000
    };
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
typedef struct tagDBCOLUMNINFO
    {
    LPOLESTR pwszName;
    ITypeInfo __RPC_FAR *pTypeInfo;
    DBORDINAL iOrdinal;
    DBCOLUMNFLAGS dwFlags;
    DBLENGTH ulColumnSize;
    DBTYPE wType;
    BYTE bPrecision;
    BYTE bScale;
    DBID columnid;
    }	DBCOLUMNINFO;

typedef 
enum tagDBBOOKMARK
    {	DBBMK_INVALID	= 0,
	DBBMK_FIRST	= DBBMK_INVALID + 1,
	DBBMK_LAST	= DBBMK_FIRST + 1
    }	DBBOOKMARK;

#define STD_BOOKMARKLENGTH 1
#ifdef __cplusplus
inline BOOL IsEqualGUIDBase(const GUID &rguid1, const GUID &rguid2)
{ return !memcmp(&(rguid1.Data2), &(rguid2.Data2), sizeof(GUID) - sizeof(rguid1.Data1)); }
#else // !__cplusplus
#define IsEqualGuidBase(rguid1, rguid2) (!memcmp(&((rguid1).Data2), &((rguid2).Data2), sizeof(GUID) - sizeof((rguid1).Data1)))
#endif // __cplusplus
#ifdef _WIN64

#define DB_INVALIDCOLUMN _UI64_MAX

#else

#define DB_INVALIDCOLUMN ULONG_MAX

#endif	// _WIN64

#endif // GUID_DEFS_ONLY
#define DBCIDGUID   {0x0C733A81L,0x2A1C,0x11CE,{0xAD,0xE5,0x00,0xAA,0x00,0x44,0x77,0x3D}}
#define DB_NULLGUID {0x00000000L,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}
#ifdef DBINITCONSTANTS
extern const OLEDBDECLSPEC DBID DB_NULLID                      = {DB_NULLGUID, 0, (LPOLESTR)0};
extern const OLEDBDECLSPEC DBID DBCOLUMN_IDNAME                = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)2};
extern const OLEDBDECLSPEC DBID DBCOLUMN_NAME                  = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)3};
extern const OLEDBDECLSPEC DBID DBCOLUMN_NUMBER                = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)4};
extern const OLEDBDECLSPEC DBID DBCOLUMN_TYPE                  = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)5};
extern const OLEDBDECLSPEC DBID DBCOLUMN_PRECISION             = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)7};
extern const OLEDBDECLSPEC DBID DBCOLUMN_SCALE                 = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)8};
extern const OLEDBDECLSPEC DBID DBCOLUMN_FLAGS                 = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)9};
extern const OLEDBDECLSPEC DBID DBCOLUMN_BASECOLUMNNAME        = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)10};
extern const OLEDBDECLSPEC DBID DBCOLUMN_BASETABLENAME         = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)11};
extern const OLEDBDECLSPEC DBID DBCOLUMN_COLLATINGSEQUENCE     = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)12};
extern const OLEDBDECLSPEC DBID DBCOLUMN_COMPUTEMODE           = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)13};
extern const OLEDBDECLSPEC DBID DBCOLUMN_DEFAULTVALUE          = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)14};
extern const OLEDBDECLSPEC DBID DBCOLUMN_DOMAINNAME            = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)15};
extern const OLEDBDECLSPEC DBID DBCOLUMN_HASDEFAULT            = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)16};
extern const OLEDBDECLSPEC DBID DBCOLUMN_ISAUTOINCREMENT       = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)17};
extern const OLEDBDECLSPEC DBID DBCOLUMN_ISCASESENSITIVE       = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)18};
extern const OLEDBDECLSPEC DBID DBCOLUMN_ISSEARCHABLE          = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)20};
extern const OLEDBDECLSPEC DBID DBCOLUMN_ISUNIQUE              = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)21};
extern const OLEDBDECLSPEC DBID DBCOLUMN_BASECATALOGNAME       = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)23};
extern const OLEDBDECLSPEC DBID DBCOLUMN_BASESCHEMANAME        = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)24};
extern const OLEDBDECLSPEC DBID DBCOLUMN_GUID                  = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)29};
extern const OLEDBDECLSPEC DBID DBCOLUMN_PROPID                = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)30};
extern const OLEDBDECLSPEC DBID DBCOLUMN_TYPEINFO              = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)31};
extern const OLEDBDECLSPEC DBID DBCOLUMN_DOMAINCATALOG         = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)32};
extern const OLEDBDECLSPEC DBID DBCOLUMN_DOMAINSCHEMA          = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)33};
extern const OLEDBDECLSPEC DBID DBCOLUMN_DATETIMEPRECISION     = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)34};
extern const OLEDBDECLSPEC DBID DBCOLUMN_NUMERICPRECISIONRADIX = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)35};
extern const OLEDBDECLSPEC DBID DBCOLUMN_OCTETLENGTH           = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)36};
extern const OLEDBDECLSPEC DBID DBCOLUMN_COLUMNSIZE            = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)37};
extern const OLEDBDECLSPEC DBID DBCOLUMN_CLSID                 = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)38};
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )
extern const OLEDBDECLSPEC DBID DBCOLUMN_MAYSORT               = {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)39};
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
#else // !DBINITCONSTANTS
extern const DBID DB_NULLID;
extern const DBID DBCOLUMN_IDNAME;
extern const DBID DBCOLUMN_NAME;
extern const DBID DBCOLUMN_NUMBER;
extern const DBID DBCOLUMN_TYPE;
extern const DBID DBCOLUMN_PRECISION;
extern const DBID DBCOLUMN_SCALE;
extern const DBID DBCOLUMN_FLAGS;
extern const DBID DBCOLUMN_BASECOLUMNNAME;
extern const DBID DBCOLUMN_BASETABLENAME;
extern const DBID DBCOLUMN_COLLATINGSEQUENCE;
extern const DBID DBCOLUMN_COMPUTEMODE;
extern const DBID DBCOLUMN_DEFAULTVALUE;
extern const DBID DBCOLUMN_DOMAINNAME;
extern const DBID DBCOLUMN_HASDEFAULT;
extern const DBID DBCOLUMN_ISAUTOINCREMENT;
extern const DBID DBCOLUMN_ISCASESENSITIVE;
extern const DBID DBCOLUMN_ISSEARCHABLE;
extern const DBID DBCOLUMN_ISUNIQUE;
extern const DBID DBCOLUMN_BASECATALOGNAME;
extern const DBID DBCOLUMN_BASESCHEMANAME;
extern const DBID DBCOLUMN_GUID;
extern const DBID DBCOLUMN_PROPID;
extern const DBID DBCOLUMN_TYPEINFO;
extern const DBID DBCOLUMN_DOMAINCATALOG;
extern const DBID DBCOLUMN_DOMAINSCHEMA;
extern const DBID DBCOLUMN_DATETIMEPRECISION;
extern const DBID DBCOLUMN_NUMERICPRECISIONRADIX;
extern const DBID DBCOLUMN_OCTETLENGTH;
extern const DBID DBCOLUMN_COLUMNSIZE;
extern const DBID DBCOLUMN_CLSID;
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )
extern const DBID DBCOLUMN_MAYSORT;
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
#endif // DBINITCONSTANTS
#ifdef DBINITCONSTANTS
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
extern const OLEDBDECLSPEC GUID DBSCHEMA_TABLES_INFO                   = {0xc8b522e0,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID MDGUID_MDX                             = {0xa07cccd0,0x8148,0x11d0,{0x87,0xbb,0x00,0xc0,0x4f,0xc3,0x39,0x42}};
extern const OLEDBDECLSPEC GUID DBGUID_MDX                             = {0xa07cccd0,0x8148,0x11d0,{0x87,0xbb,0x00,0xc0,0x4f,0xc3,0x39,0x42}};
extern const OLEDBDECLSPEC GUID MDSCHEMA_CUBES                         = {0xc8b522d8,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID MDSCHEMA_DIMENSIONS                    = {0xc8b522d9,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID MDSCHEMA_HIERARCHIES                   = {0xc8b522da,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID MDSCHEMA_LEVELS                        = {0xc8b522db,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID MDSCHEMA_MEASURES                      = {0xc8b522dc,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID MDSCHEMA_PROPERTIES                    = {0xc8b522dd,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID MDSCHEMA_MEMBERS                       = {0xc8b522de,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC DBID DBCOLUMN_BASETABLEVERSION				= {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)40};
extern const OLEDBDECLSPEC DBID DBCOLUMN_KEYCOLUMN						= {DBCIDGUID, DBKIND_GUID_PROPID, (LPOLESTR)41};
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
#define DBGUID_ROWURL   {0x0C733AB6L,0x2A1C,0x11CE,{0xAD,0xE5,0x00,0xAA,0x00,0x44,0x77,0x3D}}
#define DBGUID_ROWDEFAULTSTREAM   {0x0C733AB7L,0x2A1C,0x11CE,{0xAD,0xE5,0x00,0xAA,0x00,0x44,0x77,0x3D}}
extern const OLEDBDECLSPEC GUID DBPROPSET_TRUSTEE					= {0xc8b522e1,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_TABLE 						= {0xc8b522e2,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_COLUMN 						= {0xc8b522e4,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_DATABASE					= {0xc8b522e5,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_PROCEDURE 					= {0xc8b522e6,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_VIEW	 					= {0xc8b522e7,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_SCHEMA						= {0xc8b522e8,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_DOMAIN	 					= {0xc8b522e9,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_COLLATION 					= {0xc8b522ea,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_TRUSTEE	 					= {0xc8b522eb,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_SCHEMAROWSET				= {0xc8b522ec,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_CHARACTERSET	 			= {0xc8b522ed,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBOBJECT_TRANSLATION 				= {0xc8b522ee,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_TRUSTEE 					= {0xc8b522ef,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_COLUMNALL 					= {0xc8b522f0,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_INDEXALL 					= {0xc8b522f1,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_TABLEALL 					= {0xc8b522f2,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_TRUSTEEALL					= {0xc8b522f3,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_CONSTRAINTALL				= {0xc8b522fa,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBGUID_DSO							= {0xc8b522f4,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBGUID_SESSION						= {0xc8b522f5,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBGUID_ROWSET						= {0xc8b522f6,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBGUID_ROW							= {0xc8b522f7,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBGUID_COMMAND						= {0xc8b522f8,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBGUID_STREAM						= {0xc8b522f9,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC DBID DBROWCOL_ROWURL		         = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)0};
extern const OLEDBDECLSPEC DBID DBROWCOL_PARSENAME            = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)2};
extern const OLEDBDECLSPEC DBID DBROWCOL_PARENTNAME           = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)3};
extern const OLEDBDECLSPEC DBID DBROWCOL_ABSOLUTEPARSENAME    = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)4};
extern const OLEDBDECLSPEC DBID DBROWCOL_ISHIDDEN             = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)5};
extern const OLEDBDECLSPEC DBID DBROWCOL_ISREADONLY           = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)6};
extern const OLEDBDECLSPEC DBID DBROWCOL_CONTENTTYPE          = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)7};
extern const OLEDBDECLSPEC DBID DBROWCOL_CONTENTCLASS         = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)8};
extern const OLEDBDECLSPEC DBID DBROWCOL_CONTENTLANGUAGE      = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)9};
extern const OLEDBDECLSPEC DBID DBROWCOL_CREATIONTIME         = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)10};
extern const OLEDBDECLSPEC DBID DBROWCOL_LASTACCESSTIME       = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)11};
extern const OLEDBDECLSPEC DBID DBROWCOL_LASTWRITETIME        = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)12};
extern const OLEDBDECLSPEC DBID DBROWCOL_STREAMSIZE           = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)13};
extern const OLEDBDECLSPEC DBID DBROWCOL_ISCOLLECTION         = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)14};
extern const OLEDBDECLSPEC DBID DBROWCOL_ISSTRUCTUREDDOCUMENT = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)15};
extern const OLEDBDECLSPEC DBID DBROWCOL_DEFAULTDOCUMENT      = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)16};
extern const OLEDBDECLSPEC DBID DBROWCOL_DISPLAYNAME          = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)17};
extern const OLEDBDECLSPEC DBID DBROWCOL_ISROOT               = {DBGUID_ROWURL, DBKIND_GUID_PROPID, (LPOLESTR)18};
extern const OLEDBDECLSPEC DBID DBROWCOL_DEFAULTSTREAM        = {DBGUID_ROWDEFAULTSTREAM, DBKIND_GUID_PROPID, (LPOLESTR)0};
extern const OLEDBDECLSPEC GUID DBGUID_CONTAINEROBJECT        = {0xc8b522fb,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
extern const OLEDBDECLSPEC GUID DBSCHEMA_ASSERTIONS                    = {0xc8b52210,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_CATALOGS                      = {0xc8b52211,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_CHARACTER_SETS                = {0xc8b52212,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_COLLATIONS                    = {0xc8b52213,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_COLUMNS                       = {0xc8b52214,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_CHECK_CONSTRAINTS             = {0xc8b52215,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_CONSTRAINT_COLUMN_USAGE       = {0xc8b52216,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_CONSTRAINT_TABLE_USAGE        = {0xc8b52217,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_KEY_COLUMN_USAGE              = {0xc8b52218,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_REFERENTIAL_CONSTRAINTS       = {0xc8b52219,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_TABLE_CONSTRAINTS             = {0xc8b5221a,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_COLUMN_DOMAIN_USAGE           = {0xc8b5221b,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_INDEXES                       = {0xc8b5221e,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_COLUMN_PRIVILEGES             = {0xc8b52221,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_TABLE_PRIVILEGES              = {0xc8b52222,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_USAGE_PRIVILEGES              = {0xc8b52223,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_PROCEDURES                    = {0xc8b52224,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_SCHEMATA                      = {0xc8b52225,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_SQL_LANGUAGES                 = {0xc8b52226,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_STATISTICS                    = {0xc8b52227,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_TABLES                        = {0xc8b52229,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_TRANSLATIONS                  = {0xc8b5222a,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_PROVIDER_TYPES                = {0xc8b5222c,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_VIEWS                         = {0xc8b5222d,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_VIEW_COLUMN_USAGE             = {0xc8b5222e,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_VIEW_TABLE_USAGE              = {0xc8b5222f,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_PROCEDURE_PARAMETERS          = {0xc8b522b8,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_FOREIGN_KEYS                  = {0xc8b522c4,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_PRIMARY_KEYS                  = {0xc8b522c5,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBSCHEMA_PROCEDURE_COLUMNS             = {0xc8b522c9,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBCOL_SELFCOLUMNS                      = {0xc8b52231,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBCOL_SPECIALCOL                       = {0xc8b52232,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID PSGUID_QUERY                           = {0x49691c90,0x7e17,0x101a,{0xa9,0x1c,0x08,0x00,0x2b,0x2e,0xcd,0xa9}};
extern const OLEDBDECLSPEC GUID DBPROPSET_COLUMN                       = {0xc8b522b9,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_DATASOURCE                   = {0xc8b522ba,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_DATASOURCEINFO               = {0xc8b522bb,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_DBINIT                       = {0xc8b522bc,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_INDEX                        = {0xc8b522bd,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_ROWSET                       = {0xc8b522be,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_TABLE                        = {0xc8b522bf,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_DATASOURCEALL                = {0xc8b522c0,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_DATASOURCEINFOALL            = {0xc8b522c1,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_ROWSETALL                    = {0xc8b522c2,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_SESSION                      = {0xc8b522c6,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_SESSIONALL                   = {0xc8b522c7,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_DBINITALL                    = {0xc8b522ca,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBPROPSET_PROPERTIESINERROR            = {0xc8b522d4,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )
extern const OLEDBDECLSPEC GUID DBPROPSET_VIEW                         = {0xc8b522df,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
//@@@+ V2.5
#if( OLEDBVER >= 0x0250 )
extern const OLEDBDECLSPEC GUID DBPROPSET_VIEWALL                       = {0xc8b522fc,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
#endif // OLEDBVER >= 0x0250
//@@@- V2.5
// DBGUID_DBSQL is deprecated; use DBGUID_DEFAULT instead
extern const OLEDBDECLSPEC  GUID DBGUID_DBSQL                           = {0xc8b521fb,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBGUID_DEFAULT                         = {0xc8b521fb,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
extern const OLEDBDECLSPEC GUID DBGUID_SQL                             = {0xc8b522d7,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
#else // !DBINITCONSTANTS
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
extern const GUID DBSCHEMA_TABLES_INFO;
extern const GUID MDGUID_MDX;
extern const GUID DBGUID_MDX;
extern const GUID MDSCHEMA_CUBES;
extern const GUID MDSCHEMA_DIMENSIONS;
extern const GUID MDSCHEMA_HIERARCHIES;
extern const GUID MDSCHEMA_LEVELS;
extern const GUID MDSCHEMA_MEASURES;
extern const GUID MDSCHEMA_PROPERTIES;
extern const GUID MDSCHEMA_MEMBERS;
extern const DBID DBCOLUMN_BASETABLEVERSION;
extern const DBID DBCOLUMN_KEYCOLUMN;
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
extern const GUID DBPROPSET_TRUSTEE;
extern const GUID DBOBJECT_TABLE;
extern const GUID DBOBJECT_COLUMN;
extern const GUID DBOBJECT_DATABASE;
extern const GUID DBOBJECT_PROCEDURE;
extern const GUID DBOBJECT_VIEW;
extern const GUID DBOBJECT_SCHEMA;
extern const GUID DBOBJECT_DOMAIN;
extern const GUID DBOBJECT_COLLATION;
extern const GUID DBOBJECT_TRUSTEE;
extern const GUID DBOBJECT_SCHEMAROWSET;
extern const GUID DBOBJECT_CHARACTERSET;
extern const GUID DBOBJECT_TRANSLATION;
extern const GUID DBSCHEMA_TRUSTEE;
extern const GUID DBPROPSET_COLUMNALL;
extern const GUID DBPROPSET_INDEXALL;
extern const GUID DBPROPSET_TABLEALL;
extern const GUID DBPROPSET_TRUSTEEALL;
extern const GUID DBPROPSET_CONSTRAINTALL;
extern const GUID DBGUID_DSO;    
extern const GUID DBGUID_SESSION;
extern const GUID DBGUID_ROWSET; 
extern const GUID DBGUID_ROW;    
extern const GUID DBGUID_COMMAND;
extern const GUID DBGUID_STREAM; 
extern const DBID DBROWCOL_ROWURL;		        
extern const DBID DBROWCOL_PARSENAME;            
extern const DBID DBROWCOL_PARENTNAME;           
extern const DBID DBROWCOL_ABSOLUTEPARSENAME;    
extern const DBID DBROWCOL_ISHIDDEN;             
extern const DBID DBROWCOL_ISREADONLY;           
extern const DBID DBROWCOL_CONTENTTYPE;          
extern const DBID DBROWCOL_CONTENTCLASS;         
extern const DBID DBROWCOL_CONTENTLANGUAGE;      
extern const DBID DBROWCOL_CREATIONTIME;         
extern const DBID DBROWCOL_LASTACCESSTIME;       
extern const DBID DBROWCOL_LASTWRITETIME;        
extern const DBID DBROWCOL_STREAMSIZE;           
extern const DBID DBROWCOL_ISCOLLECTION;         
extern const DBID DBROWCOL_ISSTRUCTUREDDOCUMENT; 
extern const DBID DBROWCOL_DEFAULTDOCUMENT;      
extern const DBID DBROWCOL_DISPLAYNAME;          
extern const DBID DBROWCOL_ISROOT;               
extern const DBID DBROWCOL_DEFAULTSTREAM;        
extern const GUID DBGUID_CONTAINEROBJECT;
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
extern const GUID DBSCHEMA_ASSERTIONS;
extern const GUID DBSCHEMA_CATALOGS;
extern const GUID DBSCHEMA_CHARACTER_SETS;
extern const GUID DBSCHEMA_COLLATIONS;
extern const GUID DBSCHEMA_COLUMNS;
extern const GUID DBSCHEMA_CHECK_CONSTRAINTS;
extern const GUID DBSCHEMA_CONSTRAINT_COLUMN_USAGE;
extern const GUID DBSCHEMA_CONSTRAINT_TABLE_USAGE;
extern const GUID DBSCHEMA_KEY_COLUMN_USAGE;
extern const GUID DBSCHEMA_REFERENTIAL_CONSTRAINTS;
extern const GUID DBSCHEMA_TABLE_CONSTRAINTS;
extern const GUID DBSCHEMA_COLUMN_DOMAIN_USAGE;
extern const GUID DBSCHEMA_INDEXES;
extern const GUID DBSCHEMA_COLUMN_PRIVILEGES;
extern const GUID DBSCHEMA_TABLE_PRIVILEGES;
extern const GUID DBSCHEMA_USAGE_PRIVILEGES;
extern const GUID DBSCHEMA_PROCEDURES;
extern const GUID DBSCHEMA_SCHEMATA;
extern const GUID DBSCHEMA_SQL_LANGUAGES;
extern const GUID DBSCHEMA_STATISTICS;
extern const GUID DBSCHEMA_TABLES;
extern const GUID DBSCHEMA_TRANSLATIONS;
extern const GUID DBSCHEMA_PROVIDER_TYPES;
extern const GUID DBSCHEMA_VIEWS;
extern const GUID DBSCHEMA_VIEW_COLUMN_USAGE;
extern const GUID DBSCHEMA_VIEW_TABLE_USAGE;
extern const GUID DBSCHEMA_PROCEDURE_PARAMETERS;
extern const GUID DBSCHEMA_FOREIGN_KEYS;
extern const GUID DBSCHEMA_PRIMARY_KEYS;
extern const GUID DBSCHEMA_PROCEDURE_COLUMNS;
extern const GUID DBCOL_SELFCOLUMNS;
extern const GUID DBCOL_SPECIALCOL;
extern const GUID PSGUID_QUERY;
extern const GUID DBPROPSET_COLUMN;
extern const GUID DBPROPSET_DATASOURCE;
extern const GUID DBPROPSET_DATASOURCEINFO;
extern const GUID DBPROPSET_DBINIT;
extern const GUID DBPROPSET_INDEX;
extern const GUID DBPROPSET_ROWSET;
extern const GUID DBPROPSET_TABLE;
extern const GUID DBPROPSET_DATASOURCEALL;
extern const GUID DBPROPSET_DATASOURCEINFOALL;
extern const GUID DBPROPSET_ROWSETALL;
extern const GUID DBPROPSET_SESSION;
extern const GUID DBPROPSET_SESSIONALL;
extern const GUID DBPROPSET_DBINITALL;
extern const GUID DBPROPSET_PROPERTIESINERROR;
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )
extern const GUID DBPROPSET_VIEW;
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
//@@@+ V2.5
#if( OLEDBVER >= 0x0250 )
extern const GUID DBPROPSET_VIEWALL;
#endif // OLEDBVER >= 0x0250
//@@@- V2.5
// DBGUID_DBSQL is deprecated; use DBGUID_DEFAULT instead
extern const GUID DBGUID_DBSQL;
extern const GUID DBGUID_DEFAULT;
extern const GUID DBGUID_SQL;
#endif // DBINITCONSTANTS

#ifndef GUID_DEFS_ONLY

enum DBPROPENUM
    {	DBPROP_ABORTPRESERVE	= 0x2L,
	DBPROP_ACTIVESESSIONS	= 0x3L,
	DBPROP_APPENDONLY	= 0xbbL,
	DBPROP_ASYNCTXNABORT	= 0xa8L,
	DBPROP_ASYNCTXNCOMMIT	= 0x4L,
	DBPROP_AUTH_CACHE_AUTHINFO	= 0x5L,
	DBPROP_AUTH_ENCRYPT_PASSWORD	= 0x6L,
	DBPROP_AUTH_INTEGRATED	= 0x7L,
	DBPROP_AUTH_MASK_PASSWORD	= 0x8L,
	DBPROP_AUTH_PASSWORD	= 0x9L,
	DBPROP_AUTH_PERSIST_ENCRYPTED	= 0xaL,
	DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO	= 0xbL,
	DBPROP_AUTH_USERID	= 0xcL,
	DBPROP_BLOCKINGSTORAGEOBJECTS	= 0xdL,
	DBPROP_BOOKMARKS	= 0xeL,
	DBPROP_BOOKMARKSKIPPED	= 0xfL,
	DBPROP_BOOKMARKTYPE	= 0x10L,
	DBPROP_BYREFACCESSORS	= 0x78L,
	DBPROP_CACHEDEFERRED	= 0x11L,
	DBPROP_CANFETCHBACKWARDS	= 0x12L,
	DBPROP_CANHOLDROWS	= 0x13L,
	DBPROP_CANSCROLLBACKWARDS	= 0x15L,
	DBPROP_CATALOGLOCATION	= 0x16L,
	DBPROP_CATALOGTERM	= 0x17L,
	DBPROP_CATALOGUSAGE	= 0x18L,
	DBPROP_CHANGEINSERTEDROWS	= 0xbcL,
	DBPROP_COL_AUTOINCREMENT	= 0x1aL,
	DBPROP_COL_DEFAULT	= 0x1bL,
	DBPROP_COL_DESCRIPTION	= 0x1cL,
	DBPROP_COL_FIXEDLENGTH	= 0xa7L,
	DBPROP_COL_NULLABLE	= 0x1dL,
	DBPROP_COL_PRIMARYKEY	= 0x1eL,
	DBPROP_COL_UNIQUE	= 0x1fL,
	DBPROP_COLUMNDEFINITION	= 0x20L,
	DBPROP_COLUMNRESTRICT	= 0x21L,
	DBPROP_COMMANDTIMEOUT	= 0x22L,
	DBPROP_COMMITPRESERVE	= 0x23L,
	DBPROP_CONCATNULLBEHAVIOR	= 0x24L,
	DBPROP_CURRENTCATALOG	= 0x25L,
	DBPROP_DATASOURCENAME	= 0x26L,
	DBPROP_DATASOURCEREADONLY	= 0x27L,
	DBPROP_DBMSNAME	= 0x28L,
	DBPROP_DBMSVER	= 0x29L,
	DBPROP_DEFERRED	= 0x2aL,
	DBPROP_DELAYSTORAGEOBJECTS	= 0x2bL,
	DBPROP_DSOTHREADMODEL	= 0xa9L,
	DBPROP_GROUPBY	= 0x2cL,
	DBPROP_HETEROGENEOUSTABLES	= 0x2dL,
	DBPROP_IAccessor	= 0x79L,
	DBPROP_IColumnsInfo	= 0x7aL,
	DBPROP_IColumnsRowset	= 0x7bL,
	DBPROP_IConnectionPointContainer	= 0x7cL,
	DBPROP_IConvertType	= 0xc2L,
	DBPROP_IRowset	= 0x7eL,
	DBPROP_IRowsetChange	= 0x7fL,
	DBPROP_IRowsetIdentity	= 0x80L,
	DBPROP_IRowsetIndex	= 0x9fL,
	DBPROP_IRowsetInfo	= 0x81L,
	DBPROP_IRowsetLocate	= 0x82L,
	DBPROP_IRowsetResynch	= 0x84L,
	DBPROP_IRowsetScroll	= 0x85L,
	DBPROP_IRowsetUpdate	= 0x86L,
	DBPROP_ISupportErrorInfo	= 0x87L,
	DBPROP_ILockBytes	= 0x88L,
	DBPROP_ISequentialStream	= 0x89L,
	DBPROP_IStorage	= 0x8aL,
	DBPROP_IStream	= 0x8bL,
	DBPROP_IDENTIFIERCASE	= 0x2eL,
	DBPROP_IMMOBILEROWS	= 0x2fL,
	DBPROP_INDEX_AUTOUPDATE	= 0x30L,
	DBPROP_INDEX_CLUSTERED	= 0x31L,
	DBPROP_INDEX_FILLFACTOR	= 0x32L,
	DBPROP_INDEX_INITIALSIZE	= 0x33L,
	DBPROP_INDEX_NULLCOLLATION	= 0x34L,
	DBPROP_INDEX_NULLS	= 0x35L,
	DBPROP_INDEX_PRIMARYKEY	= 0x36L,
	DBPROP_INDEX_SORTBOOKMARKS	= 0x37L,
	DBPROP_INDEX_TEMPINDEX	= 0xa3L,
	DBPROP_INDEX_TYPE	= 0x38L,
	DBPROP_INDEX_UNIQUE	= 0x39L,
	DBPROP_INIT_DATASOURCE	= 0x3bL,
	DBPROP_INIT_HWND	= 0x3cL,
	DBPROP_INIT_IMPERSONATION_LEVEL	= 0x3dL,
	DBPROP_INIT_LCID	= 0xbaL,
	DBPROP_INIT_LOCATION	= 0x3eL,
	DBPROP_INIT_MODE	= 0x3fL,
	DBPROP_INIT_PROMPT	= 0x40L,
	DBPROP_INIT_PROTECTION_LEVEL	= 0x41L,
	DBPROP_INIT_PROVIDERSTRING	= 0xa0L,
	DBPROP_INIT_TIMEOUT	= 0x42L,
	DBPROP_LITERALBOOKMARKS	= 0x43L,
	DBPROP_LITERALIDENTITY	= 0x44L,
	DBPROP_MARSHALLABLE	= 0xc5L,
	DBPROP_MAXINDEXSIZE	= 0x46L,
	DBPROP_MAXOPENROWS	= 0x47L,
	DBPROP_MAXPENDINGROWS	= 0x48L,
	DBPROP_MAXROWS	= 0x49L,
	DBPROP_MAXROWSIZE	= 0x4aL,
	DBPROP_MAXROWSIZEINCLUDESBLOB	= 0x4bL,
	DBPROP_MAXTABLESINSELECT	= 0x4cL,
	DBPROP_MAYWRITECOLUMN	= 0x4dL,
	DBPROP_MEMORYUSAGE	= 0x4eL,
	DBPROP_MULTIPLEPARAMSETS	= 0xbfL,
	DBPROP_MULTIPLERESULTS	= 0xc4L,
	DBPROP_MULTIPLESTORAGEOBJECTS	= 0x50L,
	DBPROP_MULTITABLEUPDATE	= 0x51L,
	DBPROP_NOTIFICATIONGRANULARITY	= 0xc6L,
	DBPROP_NOTIFICATIONPHASES	= 0x52L,
	DBPROP_NOTIFYCOLUMNSET	= 0xabL,
	DBPROP_NOTIFYROWDELETE	= 0xadL,
	DBPROP_NOTIFYROWFIRSTCHANGE	= 0xaeL,
	DBPROP_NOTIFYROWINSERT	= 0xafL,
	DBPROP_NOTIFYROWRESYNCH	= 0xb1L,
	DBPROP_NOTIFYROWSETCHANGED	= 0xd3L,
	DBPROP_NOTIFYROWSETRELEASE	= 0xb2L,
	DBPROP_NOTIFYROWSETFETCHPOSITIONCHANGE	= 0xb3L,
	DBPROP_NOTIFYROWUNDOCHANGE	= 0xb4L,
	DBPROP_NOTIFYROWUNDODELETE	= 0xb5L,
	DBPROP_NOTIFYROWUNDOINSERT	= 0xb6L,
	DBPROP_NOTIFYROWUPDATE	= 0xb7L,
	DBPROP_NULLCOLLATION	= 0x53L,
	DBPROP_OLEOBJECTS	= 0x54L,
	DBPROP_ORDERBYCOLUMNSINSELECT	= 0x55L,
	DBPROP_ORDEREDBOOKMARKS	= 0x56L,
	DBPROP_OTHERINSERT	= 0x57L,
	DBPROP_OTHERUPDATEDELETE	= 0x58L,
	DBPROP_OUTPUTPARAMETERAVAILABILITY	= 0xb8L,
	DBPROP_OWNINSERT	= 0x59L,
	DBPROP_OWNUPDATEDELETE	= 0x5aL,
	DBPROP_PERSISTENTIDTYPE	= 0xb9L,
	DBPROP_PREPAREABORTBEHAVIOR	= 0x5bL,
	DBPROP_PREPARECOMMITBEHAVIOR	= 0x5cL,
	DBPROP_PROCEDURETERM	= 0x5dL,
	DBPROP_PROVIDERNAME	= 0x60L,
	DBPROP_PROVIDEROLEDBVER	= 0x61L,
	DBPROP_PROVIDERVER	= 0x62L,
	DBPROP_QUICKRESTART	= 0x63L,
	DBPROP_QUOTEDIDENTIFIERCASE	= 0x64L,
	DBPROP_REENTRANTEVENTS	= 0x65L,
	DBPROP_REMOVEDELETED	= 0x66L,
	DBPROP_REPORTMULTIPLECHANGES	= 0x67L,
	DBPROP_RETURNPENDINGINSERTS	= 0xbdL,
	DBPROP_ROWRESTRICT	= 0x68L,
	DBPROP_ROWSETCONVERSIONSONCOMMAND	= 0xc0L,
	DBPROP_ROWTHREADMODEL	= 0x69L,
	DBPROP_SCHEMATERM	= 0x6aL,
	DBPROP_SCHEMAUSAGE	= 0x6bL,
	DBPROP_SERVERCURSOR	= 0x6cL,
	DBPROP_SESS_AUTOCOMMITISOLEVELS	= 0xbeL,
	DBPROP_SQLSUPPORT	= 0x6dL,
	DBPROP_STRONGIDENTITY	= 0x77L,
	DBPROP_STRUCTUREDSTORAGE	= 0x6fL,
	DBPROP_SUBQUERIES	= 0x70L,
	DBPROP_SUPPORTEDTXNDDL	= 0xa1L,
	DBPROP_SUPPORTEDTXNISOLEVELS	= 0x71L,
	DBPROP_SUPPORTEDTXNISORETAIN	= 0x72L,
	DBPROP_TABLETERM	= 0x73L,
	DBPROP_TBL_TEMPTABLE	= 0x8cL,
	DBPROP_TRANSACTEDOBJECT	= 0x74L,
	DBPROP_UPDATABILITY	= 0x75L,
	DBPROP_USERNAME	= 0x76L
    };
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )

enum DBPROPENUM15
    {	DBPROP_FILTERCOMPAREOPS	= 0xd1L,
	DBPROP_FINDCOMPAREOPS	= 0xd2L,
	DBPROP_IChapteredRowset	= 0xcaL,
	DBPROP_IDBAsynchStatus	= 0xcbL,
	DBPROP_IRowsetFind	= 0xccL,
	DBPROP_IRowsetView	= 0xd4L,
	DBPROP_IViewChapter	= 0xd5L,
	DBPROP_IViewFilter	= 0xd6L,
	DBPROP_IViewRowset	= 0xd7L,
	DBPROP_IViewSort	= 0xd8L,
	DBPROP_INIT_ASYNCH	= 0xc8L,
	DBPROP_MAXOPENCHAPTERS	= 0xc7L,
	DBPROP_MAXORSINFILTER	= 0xcdL,
	DBPROP_MAXSORTCOLUMNS	= 0xceL,
	DBPROP_ROWSET_ASYNCH	= 0xc9L,
	DBPROP_SORTONINDEX	= 0xcfL
    };
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
#define DBPROP_PROVIDERFILENAME DBPROP_PROVIDERNAME
#define DBPROP_SERVER_NAME DBPROP_SERVERNAME

enum DBPROPENUM20
    {	DBPROP_IMultipleResults	= 0xd9L,
	DBPROP_DATASOURCE_TYPE	= 0xfbL,
	MDPROP_AXES	= 0xfcL,
	MDPROP_FLATTENING_SUPPORT	= 0xfdL,
	MDPROP_MDX_JOINCUBES	= 0xfeL,
	MDPROP_NAMED_LEVELS	= 0xffL,
	MDPROP_RANGEROWSET	= 0x100L,
	MDPROP_MDX_SLICER	= 0xdaL,
	MDPROP_MDX_CUBEQUALIFICATION	= 0xdbL,
	MDPROP_MDX_OUTERREFERENCE	= 0xdcL,
	MDPROP_MDX_QUERYBYPROPERTY	= 0xddL,
	MDPROP_MDX_CASESUPPORT	= 0xdeL,
	MDPROP_MDX_STRING_COMPOP	= 0xe0L,
	MDPROP_MDX_DESCFLAGS	= 0xe1L,
	MDPROP_MDX_SET_FUNCTIONS	= 0xe2L,
	MDPROP_MDX_MEMBER_FUNCTIONS	= 0xe3L,
	MDPROP_MDX_NUMERIC_FUNCTIONS	= 0xe4L,
	MDPROP_MDX_FORMULAS	= 0xe5L,
	MDPROP_AGGREGATECELL_UPDATE	= 0xe6L,
	MDPROP_MDX_AGGREGATECELL_UPDATE	= MDPROP_AGGREGATECELL_UPDATE,
	MDPROP_MDX_OBJQUALIFICATION	= 0x105L,
	MDPROP_MDX_NONMEASURE_EXPRESSONS	= 0x106L,
	DBPROP_ACCESSORDER	= 0xe7L,
	DBPROP_BOOKMARKINFO	= 0xe8L,
	DBPROP_INIT_CATALOG	= 0xe9L,
	DBPROP_ROW_BULKOPS	= 0xeaL,
	DBPROP_PROVIDERFRIENDLYNAME	= 0xebL,
	DBPROP_LOCKMODE	= 0xecL,
	DBPROP_MULTIPLECONNECTIONS	= 0xedL,
	DBPROP_UNIQUEROWS	= 0xeeL,
	DBPROP_SERVERDATAONINSERT	= 0xefL,
	DBPROP_STORAGEFLAGS	= 0xf0L,
	DBPROP_CONNECTIONSTATUS	= 0xf4L,
	DBPROP_ALTERCOLUMN	= 0xf5L,
	DBPROP_COLUMNLCID	= 0xf6L,
	DBPROP_RESETDATASOURCE	= 0xf7L,
	DBPROP_INIT_OLEDBSERVICES	= 0xf8L,
	DBPROP_IRowsetRefresh	= 0xf9L,
	DBPROP_SERVERNAME	= 0xfaL,
	DBPROP_IParentRowset	= 0x101L,
	DBPROP_HIDDENCOLUMNS	= 0x102L,
	DBPROP_PROVIDERMEMORY	= 0x103L,
	DBPROP_CLIENTCURSOR	= 0x104L
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )

enum DBPROPENUM21
    {	DBPROP_TRUSTEE_USERNAME	= 0xf1L,
	DBPROP_TRUSTEE_AUTHENTICATION	= 0xf2L,
	DBPROP_TRUSTEE_NEWAUTHENTICATION	= 0xf3L,
	DBPROP_IRow	= 0x107L,
	DBPROP_IRowChange	= 0x108L,
	DBPROP_IRowSchemaChange	= 0x109L,
	DBPROP_IGetRow	= 0x10aL,
	DBPROP_IScopedOperations	= 0x10bL,
	DBPROP_IBindResource	= 0x10cL,
	DBPROP_ICreateRow	= 0x10dL,
	DBPROP_INIT_BINDFLAGS	= 0x10eL,
	DBPROP_INIT_LOCKOWNER	= 0x10fL,
	DBPROP_GENERATEURL	= 0x111L,
	DBPROP_IDBBinderProperties	= 0x112L,
	DBPROP_IColumnsInfo2	= 0x113L,
	DBPROP_IRegisterProvider	= 0x114L,
	DBPROP_IGetSession	= 0x115L,
	DBPROP_IGetSourceRow	= 0x116L,
	DBPROP_IRowsetCurrentIndex	= 0x117L,
	DBPROP_OPENROWSETSUPPORT	= 0x118L,
	DBPROP_COL_ISLONG	= 0x119L
    };
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
//@@@+ V2.5
#if( OLEDBVER >= 0x0250 )

enum DBPROPENUM25
    {	DBPROP_COL_SEED	= 0x11aL,
	DBPROP_COL_INCREMENT	= 0x11bL,
	DBPROP_INIT_GENERALTIMEOUT	= 0x11cL,
	DBPROP_COMSERVICES	= 0x11dL
    };
#endif // OLEDBVER >= 0x0250
//@@@- V2.5
//@@@+ deprecated
#ifdef deprecated

enum DBPROPENUMDEPRECATED
    {	DBPROP_IRowsetExactScroll	= 0x9aL,
	DBPROP_FILTEROPS	= 0xd0L
    };
#endif // deprecated
//@@@- deprecated
#define DBPROPVAL_BMK_NUMERIC							 0x00000001L
#define DBPROPVAL_BMK_KEY								 0x00000002L
#define DBPROPVAL_CL_START                                0x00000001L
#define DBPROPVAL_CL_END                                  0x00000002L
#define DBPROPVAL_CU_DML_STATEMENTS						 0x00000001L
#define DBPROPVAL_CU_TABLE_DEFINITION					 0x00000002L
#define DBPROPVAL_CU_INDEX_DEFINITION					 0x00000004L
#define DBPROPVAL_CU_PRIVILEGE_DEFINITION				 0x00000008L
#define DBPROPVAL_CD_NOTNULL								 0x00000001L
#define DBPROPVAL_CB_NULL								 0x00000001L
#define DBPROPVAL_CB_NON_NULL							 0x00000002L
#define DBPROPVAL_FU_NOT_SUPPORTED						 0x00000001L
#define DBPROPVAL_FU_COLUMN								 0x00000002L
#define DBPROPVAL_FU_TABLE								 0x00000004L
#define DBPROPVAL_FU_CATALOG								 0x00000008L
#define DBPROPVAL_GB_NOT_SUPPORTED						 0x00000001L
#define DBPROPVAL_GB_EQUALS_SELECT						 0x00000002L
#define DBPROPVAL_GB_CONTAINS_SELECT						 0x00000004L
#define DBPROPVAL_GB_NO_RELATION							 0x00000008L
#define DBPROPVAL_HT_DIFFERENT_CATALOGS					 0x00000001L
#define DBPROPVAL_HT_DIFFERENT_PROVIDERS					 0x00000002L
#define DBPROPVAL_IC_UPPER								 0x00000001L
#define DBPROPVAL_IC_LOWER								 0x00000002L
#define DBPROPVAL_IC_SENSITIVE							 0x00000004L
#define DBPROPVAL_IC_MIXED								 0x00000008L
//@@@+ deprecated
#ifdef deprecated
#define DBPROPVAL_LM_NONE								 0x00000001L
#define DBPROPVAL_LM_READ								 0x00000002L
#define DBPROPVAL_LM_INTENT								 0x00000004L
#define DBPROPVAL_LM_RITE								 0x00000008L
#endif // deprecated
//@@@- deprecated
#define DBPROPVAL_NP_OKTODO								 0x00000001L
#define DBPROPVAL_NP_ABOUTTODO							 0x00000002L
#define DBPROPVAL_NP_SYNCHAFTER							 0x00000004L
#define DBPROPVAL_NP_FAILEDTODO							 0x00000008L
#define DBPROPVAL_NP_DIDEVENT							 0x00000010L
#define DBPROPVAL_NC_END									 0x00000001L
#define DBPROPVAL_NC_HIGH								 0x00000002L
#define DBPROPVAL_NC_LOW									 0x00000004L
#define DBPROPVAL_NC_START								 0x00000008L
#define DBPROPVAL_OO_BLOB								 0x00000001L
#define DBPROPVAL_OO_IPERSIST							 0x00000002L
#define DBPROPVAL_CB_DELETE								 0x00000001L
#define DBPROPVAL_CB_PRESERVE							 0x00000002L
#define DBPROPVAL_SU_DML_STATEMENTS						 0x00000001L
#define DBPROPVAL_SU_TABLE_DEFINITION					 0x00000002L
#define DBPROPVAL_SU_INDEX_DEFINITION					 0x00000004L
#define DBPROPVAL_SU_PRIVILEGE_DEFINITION				 0x00000008L
#define DBPROPVAL_SQ_CORRELATEDSUBQUERIES				 0x00000001L
#define DBPROPVAL_SQ_COMPARISON							 0x00000002L
#define DBPROPVAL_SQ_EXISTS								 0x00000004L
#define DBPROPVAL_SQ_IN									 0x00000008L
#define DBPROPVAL_SQ_QUANTIFIED							 0x00000010L
#define DBPROPVAL_SQ_TABLE								 0x00000020L
#define DBPROPVAL_SS_ISEQUENTIALSTREAM					 0x00000001L
#define DBPROPVAL_SS_ISTREAM								 0x00000002L
#define DBPROPVAL_SS_ISTORAGE							 0x00000004L
#define DBPROPVAL_SS_ILOCKBYTES							 0x00000008L
#define DBPROPVAL_TI_CHAOS								 0x00000010L
#define DBPROPVAL_TI_READUNCOMMITTED						 0x00000100L
#define DBPROPVAL_TI_BROWSE								 0x00000100L
#define DBPROPVAL_TI_CURSORSTABILITY						 0x00001000L
#define DBPROPVAL_TI_READCOMMITTED						 0x00001000L
#define DBPROPVAL_TI_REPEATABLEREAD						 0x00010000L
#define DBPROPVAL_TI_SERIALIZABLE						 0x00100000L
#define DBPROPVAL_TI_ISOLATED							 0x00100000L
#define DBPROPVAL_TR_COMMIT_DC							 0x00000001L
#define DBPROPVAL_TR_COMMIT								 0x00000002L
#define DBPROPVAL_TR_COMMIT_NO							 0x00000004L
#define DBPROPVAL_TR_ABORT_DC							 0x00000008L
#define DBPROPVAL_TR_ABORT								 0x00000010L
#define DBPROPVAL_TR_ABORT_NO							 0x00000020L
#define DBPROPVAL_TR_DONTCARE							 0x00000040L
#define DBPROPVAL_TR_BOTH								 0x00000080L
#define DBPROPVAL_TR_NONE								 0x00000100L
#define DBPROPVAL_TR_OPTIMISTIC							 0x00000200L
#define DBPROPVAL_RT_FREETHREAD							 0x00000001L
#define DBPROPVAL_RT_APTMTTHREAD							 0x00000002L
#define DBPROPVAL_RT_SINGLETHREAD						 0x00000004L
#define DBPROPVAL_UP_CHANGE								 0x00000001L
#define DBPROPVAL_UP_DELETE								 0x00000002L
#define DBPROPVAL_UP_INSERT								 0x00000004L
#define DBPROPVAL_SQL_NONE								 0x00000000L
#define DBPROPVAL_SQL_ODBC_MINIMUM						 0x00000001L
#define DBPROPVAL_SQL_ODBC_CORE							 0x00000002L
#define DBPROPVAL_SQL_ODBC_EXTENDED						 0x00000004L
#define DBPROPVAL_SQL_ANSI89_IEF							 0x00000008L
#define DBPROPVAL_SQL_ANSI92_ENTRY						 0x00000010L
#define DBPROPVAL_SQL_FIPS_TRANSITIONAL					 0x00000020L
#define DBPROPVAL_SQL_ANSI92_INTERMEDIATE				 0x00000040L
#define DBPROPVAL_SQL_ANSI92_FULL						 0x00000080L
#define DBPROPVAL_SQL_ESCAPECLAUSES						 0x00000100L
#define DBPROPVAL_IT_BTREE                                0x00000001L
#define DBPROPVAL_IT_HASH                                 0x00000002L
#define DBPROPVAL_IT_CONTENT                              0x00000003L
#define DBPROPVAL_IT_OTHER                                0x00000004L
#define DBPROPVAL_IN_DISALLOWNULL                         0x00000001L
#define DBPROPVAL_IN_IGNORENULL                           0x00000002L
#define DBPROPVAL_IN_IGNOREANYNULL                        0x00000004L
#define DBPROPVAL_TC_NONE                                 0x00000000L
#define DBPROPVAL_TC_DML                                  0x00000001L
#define DBPROPVAL_TC_DDL_COMMIT                           0x00000002L
#define DBPROPVAL_TC_DDL_IGNORE                           0x00000004L
#define DBPROPVAL_TC_ALL                                  0x00000008L
#define DBPROPVAL_NP_OKTODO                               0x00000001L
#define DBPROPVAL_NP_ABOUTTODO                            0x00000002L
#define DBPROPVAL_NP_SYNCHAFTER                           0x00000004L
#define DBPROPVAL_OA_NOTSUPPORTED                         0x00000001L
#define DBPROPVAL_OA_ATEXECUTE                            0x00000002L
#define DBPROPVAL_OA_ATROWRELEASE                         0x00000004L
#define DBPROPVAL_MR_NOTSUPPORTED                         0x00000000L
#define DBPROPVAL_MR_SUPPORTED                            0x00000001L
#define DBPROPVAL_MR_CONCURRENT                           0x00000002L
#define DBPROPVAL_PT_GUID_NAME                            0x00000001L
#define DBPROPVAL_PT_GUID_PROPID                          0x00000002L
#define DBPROPVAL_PT_NAME                                 0x00000004L
#define DBPROPVAL_PT_GUID                                 0x00000008L
#define DBPROPVAL_PT_PROPID								 0x00000010L
#define DBPROPVAL_PT_PGUID_NAME                           0x00000020L
#define DBPROPVAL_PT_PGUID_PROPID						 0x00000040L
#define DBPROPVAL_NT_SINGLEROW                            0x00000001L
#define DBPROPVAL_NT_MULTIPLEROWS                         0x00000002L
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )
#define DBPROPVAL_ASYNCH_INITIALIZE                       0x00000001L
#define DBPROPVAL_ASYNCH_SEQUENTIALPOPULATION             0x00000002L
#define DBPROPVAL_ASYNCH_RANDOMPOPULATION                 0x00000004L
#define DBPROPVAL_OP_EQUAL                                0x00000001L
#define DBPROPVAL_OP_RELATIVE                             0x00000002L
#define DBPROPVAL_OP_STRING                               0x00000004L
#define DBPROPVAL_CO_EQUALITY                             0x00000001L
#define DBPROPVAL_CO_STRING                               0x00000002L
#define DBPROPVAL_CO_CASESENSITIVE                        0x00000004L
#define DBPROPVAL_CO_CASEINSENSITIVE                      0x00000008L
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
#define DBPROPVAL_CO_CONTAINS		                     0x00000010L
#define DBPROPVAL_CO_BEGINSWITH		                     0x00000020L
#define DBPROPVAL_ASYNCH_BACKGROUNDPOPULATION			0x00000008L
#define DBPROPVAL_ASYNCH_PREPOPULATE						0x00000010L
#define DBPROPVAL_ASYNCH_POPULATEONDEMAND				0x00000020L
#define DBPROPVAL_LM_NONE								 0x00000001L
#define DBPROPVAL_LM_SINGLEROW							 0x00000002L
#define DBPROPVAL_SQL_SUBMINIMUM 						 0x00000200L
#define DBPROPVAL_DST_TDP                                 0x00000001L
#define DBPROPVAL_DST_MDP                                 0x00000002L
#define DBPROPVAL_DST_TDPANDMDP                           0x00000003L
#define MDPROPVAL_AU_UNSUPPORTED                          0x00000000L
#define MDPROPVAL_AU_UNCHANGED                            0x00000001L
#define MDPROPVAL_AU_UNKNOWN                              0x00000002L
#define MDPROPVAL_MF_WITH_CALCMEMBERS                     0x00000001L
#define MDPROPVAL_MF_WITH_NAMEDSETS                       0x00000002L
#define MDPROPVAL_MF_CREATE_CALCMEMBERS                   0x00000004L
#define MDPROPVAL_MF_CREATE_NAMEDSETS                     0x00000008L
#define MDPROPVAL_MF_SCOPE_SESSION						 0x00000010L
#define MDPROPVAL_MF_SCOPE_GLOBAL                         0x00000020L
#define MDPROPVAL_MMF_COUSIN                              0x00000001L
#define MDPROPVAL_MMF_PARALLELPERIOD                      0x00000002L
#define MDPROPVAL_MMF_OPENINGPERIOD                       0x00000004L
#define MDPROPVAL_MMF_CLOSINGPERIOD                       0x00000008L
#define MDPROPVAL_MNF_MEDIAN								0x00000001L
#define MDPROPVAL_MNF_VAR								0x00000002L
#define MDPROPVAL_MNF_STDDEV								0x00000004L
#define MDPROPVAL_MNF_RANK								0x00000008L
#define MDPROPVAL_MNF_AGGREGATE							0x00000010L
#define MDPROPVAL_MNF_COVARIANCE							0x00000020L
#define MDPROPVAL_MNF_CORRELATION						0x00000040L
#define MDPROPVAL_MNF_LINREGSLOPE						0x00000080L
#define MDPROPVAL_MNF_LINREGVARIANCE						0x00000100L
#define MDPROPVAL_MNF_LINREG2							0x00000200L
#define MDPROPVAL_MNF_LINREGPOINT						0x00000400L
#define MDPROPVAL_MNF_DRILLDOWNLEVEL						0x00000800L
#define MDPROPVAL_MNF_DRILLDOWNMEMBERTOP					0x00001000L
#define MDPROPVAL_MNF_DRILLDOWNMEMBERBOTTOM				0x00002000L
#define MDPROPVAL_MNF_DRILLDOWNLEVELTOP					0x00004000L
#define MDPROPVAL_MNF_DRILLDOWNLEVELBOTTOM				0x00008000L
#define MDPROPVAL_MNF_DRILLUPMEMBER						0x00010000L
#define MDPROPVAL_MNF_DRILLUPLEVEL						0x00020000L
#define MDPROPVAL_MMF_COUSIN								0x00000001L
#define MDPROPVAL_MMF_PARALLELPERIOD						0x00000002L
#define MDPROPVAL_MMF_OPENINGPERIOD						0x00000004L
#define MDPROPVAL_MMF_CLOSINGPERIOD						0x00000008L
#define MDPROPVAL_MSF_TOPPERCENT							0x00000001L
#define MDPROPVAL_MSF_BOTTOMPERCENT						0x00000002L
#define MDPROPVAL_MSF_TOPSUM								0x00000004L
#define MDPROPVAL_MSF_BOTTOMSUM							0x00000008L
#define MDPROPVAL_MSF_PERIODSTODATE						0x00000010L
#define MDPROPVAL_MSF_LASTPERIODS						0x00000020L
#define MDPROPVAL_MSF_YTD								0x00000040L
#define MDPROPVAL_MSF_QTD								0x00000080L
#define MDPROPVAL_MSF_MTD								0x00000100L
#define MDPROPVAL_MSF_WTD								0x00000200L
#define MDPROPVAL_MSF_DRILLDOWNMEMBBER					0x00000400L
#define MDPROPVAL_MSF_DRILLDOWNLEVEL						0x00000800L
#define MDPROPVAL_MSF_DRILLDOWNMEMBERTOP					0x00001000L
#define MDPROPVAL_MSF_DRILLDOWNMEMBERBOTTOM				0x00002000L
#define MDPROPVAL_MSF_DRILLDOWNLEVELTOP					0x00004000L
#define MDPROPVAL_MSF_DRILLDOWNLEVELBOTTOM				0x00008000L
#define MDPROPVAL_MSF_DRILLUPMEMBER						0x00010000L
#define MDPROPVAL_MSF_DRILLUPLEVEL						0x00020000L
#define MDPROPVAL_MSF_TOGGLEDRILLSTATE					0x00040000L
// values for MDPROP_MDX_DESCFLAGS
#define MDPROPVAL_MD_SELF								0x00000001L
#define MDPROPVAL_MD_BEFORE								0x00000002L
#define MDPROPVAL_MD_AFTER								0x00000004L
// values for MDPROP_MDX_STRING_COMPOP
#define MDPROPVAL_MSC_LESSTHAN							0x00000001L
#define MDPROPVAL_MSC_GREATERTHAN						0x00000002L
#define MDPROPVAL_MSC_LESSTHANEQUAL						0x00000004L
#define MDPROPVAL_MSC_GREATERTHANEQUAL					0x00000008L
#define MDPROPVAL_MC_SINGLECASE							0x00000001L
#define MDPROPVAL_MC_SEARCHEDCASE						0x00000002L
#define MDPROPVAL_MOQ_OUTERREFERENCE						0x00000001L
#define MDPROPVAL_MOQ_DATASOURCE_CUBE					0x00000001L
#define MDPROPVAL_MOQ_CATALOG_CUBE						0x00000002L
#define MDPROPVAL_MOQ_SCHEMA_CUBE						0x00000004L
#define MDPROPVAL_MOQ_CUBE_DIM							0x00000008L
#define MDPROPVAL_MOQ_DIM_HIER							0x00000010L
#define MDPROPVAL_MOQ_DIMHIER_LEVEL						0x00000020L
#define MDPROPVAL_MOQ_LEVEL_MEMBER						0x00000040L
#define MDPROPVAL_MOQ_MEMBER_MEMBER						0x00000080L
#define MDPROPVAL_FS_FULL_SUPPORT						0x00000001L
#define MDPROPVAL_FS_GENERATED_COLUMN					0x00000002L
#define MDPROPVAL_FS_GENERATED_DIMENSION					0x00000003L
#define MDPROPVAL_FS_NO_SUPPORT							0x00000004L
#define MDPROPVAL_NL_NAMEDLEVELS							0x00000001L
#define MDPROPVAL_NL_NUMBEREDLEVELS						0x00000002L
#define MDPROPVAL_MJC_SINGLECUBE							0x00000001L
#define MDPROPVAL_MJC_MULTICUBES							0x00000002L
#define MDPROPVAL_MJC_IMPLICITCUBE						0x00000004L
#define MDPROPVAL_RR_NORANGEROWSET						0x00000001L
#define MDPROPVAL_RR_READONLY							0x00000002L
#define MDPROPVAL_RR_UPDATE								0x00000004L
#define MDPROPVAL_MS_MULTIPLETUPLES						0x00000001L
#define MDPROPVAL_MS_SINGLETUPLE						0x00000002L
#define DBPROPVAL_AO_SEQUENTIAL							0x00000000L
#define DBPROPVAL_AO_SEQUENTIALSTORAGEOBJECTS			0x00000001L
#define DBPROPVAL_AO_RANDOM								0x00000002L
#define DBPROPVAL_BD_ROWSET								0x00000000L
#define DBPROPVAL_BD_INTRANSACTION						0x00000001L
#define DBPROPVAL_BD_XTRANSACTION						0x00000002L
#define DBPROPVAL_BD_REORGANIZATION						0x00000003L
#define BMK_DURABILITY_ROWSET							DBPROPVAL_BD_ROWSET
#define BMK_DURABILITY_INTRANSACTION						DBPROPVAL_BD_INTRANSACTION
#define BMK_DURABILITY_XTRANSACTION						DBPROPVAL_BD_XTRANSACTION
#define BMK_DURABILITY_REORGANIZATION					DBPROPVAL_BD_REORGANIZATION
#define DBPROPVAL_BO_NOLOG								0x00000000L
#define DBPROPVAL_BO_NOINDEXUPDATE						0x00000001L
#define DBPROPVAL_BO_REFINTEGRITY						0x00000002L
#if !defined(_WINBASE_)
#define OF_READ             0x00000000
#define OF_WRITE            0x00000001
#define OF_READWRITE        0x00000002
#define OF_SHARE_COMPAT     0x00000000
#define OF_SHARE_EXCLUSIVE  0x00000010
#define OF_SHARE_DENY_WRITE 0x00000020
#define OF_SHARE_DENY_READ  0x00000030
#define OF_SHARE_DENY_NONE  0x00000040
#define OF_PARSE            0x00000100
#define OF_DELETE           0x00000200
#define OF_VERIFY           0x00000400
#define OF_CANCEL           0x00000800
#define OF_CREATE           0x00001000
#define OF_PROMPT           0x00002000
#define OF_EXIST            0x00004000
#define OF_REOPEN           0x00008000
#endif // !_WINBASE_
#define DBPROPVAL_STGM_READ					OF_READ
#define DBPROPVAL_STGM_WRITE					OF_WRITE
#define DBPROPVAL_STGM_READWRITE				OF_READWRITE
#define DBPROPVAL_STGM_SHARE_DENY_NONE		OF_SHARE_DENY_NONE
#define DBPROPVAL_STGM_SHARE_DENY_READ		OF_SHARE_DENY_READ
#define DBPROPVAL_STGM_SHARE_DENY_WRITE		OF_SHARE_DENY_WRITE
#define DBPROPVAL_STGM_SHARE_EXCLUSIVE		OF_SHARE_EXCLUSIVE
#define DBPROPVAL_STGM_DIRECT				0x00010000
#define DBPROPVAL_STGM_TRANSACTED			0x00020000
#define DBPROPVAL_STGM_CREATE				OF_CREATE
#define DBPROPVAL_STGM_CONVERT				0x00040000
#define DBPROPVAL_STGM_FAILIFTHERE			0x00080000
#define DBPROPVAL_STGM_PRIORITY				0x00100000
#define DBPROPVAL_STGM_DELETEONRELEASE		0x00200000
#define DBPROPVAL_GB_COLLATE 				0x00000010L
#define DBPROPVAL_CS_UNINITIALIZED			0x00000000L
#define DBPROPVAL_CS_INITIALIZED				0x00000001L
#define DBPROPVAL_CS_COMMUNICATIONFAILURE	0x00000002L
#define DBPROPVAL_RD_RESETALL		0xffffffffL
#define DBPROPVAL_OS_RESOURCEPOOLING	0x00000001L
#define DBPROPVAL_OS_TXNENLISTMENT	0x00000002L
#define DBPROPVAL_OS_CLIENTCURSOR    0x00000004L
#define DBPROPVAL_OS_ENABLEALL		0xffffffffL
#define DBPROPVAL_BI_CROSSROWSET		0x00000001L
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
#define MDPROPVAL_NL_SCHEMAONLY                          0x00000004L
#define DBPROPVAL_OS_DISABLEALL	0x00000000L
#define DBPROPVAL_OO_ROWOBJECT							0x00000004L
#define DBPROPVAL_OO_SCOPED								0x00000008L
#define DBPROPVAL_OO_DIRECTBIND							0x00000010L
#define DBPROPVAL_DST_DOCSOURCE                          0x00000004L
#define DBPROPVAL_GU_NOTSUPPORTED                         0x00000001L
#define DBPROPVAL_GU_SUFFIX		                         0x00000002L
#define DB_BINDFLAGS_DELAYFETCHCOLUMNS                    0x00000001L
#define DB_BINDFLAGS_DELAYFETCHSTREAM                     0x00000002L
#define DB_BINDFLAGS_RECURSIVE		                     0x00000004L
#define DB_BINDFLAGS_OUTPUT								 0x00000008L
#define DB_BINDFLAGS_COLLECTION							 0x00000010L
#define DB_BINDFLAGS_OPENIFEXISTS						 0x00000020L
#define DB_BINDFLAGS_OVERWRITE							 0x00000040L
#define DB_BINDFLAGS_ISSTRUCTUREDDOCUMENT				 0x00000080L
#define DBPROPVAL_ORS_TABLE								 0x00000000L
#define DBPROPVAL_ORS_INDEX                               0x00000001L
#define DBPROPVAL_ORS_INTEGRATEDINDEX		             0x00000002L
#define DBPROPVAL_TC_DDL_LOCK							 0x00000010L
#define DBPROPVAL_ORS_STOREDPROC							 0x00000004L
#define DBPROPVAL_IN_ALLOWNULL	                         0x00000000L
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
//@@@+ V2.5
#if( OLEDBVER >= 0x0250 )
#define DBPROPVAL_OO_SINGLETON							0x00000020L
#define DBPROPVAL_OS_AGR_AFTERSESSION					0x00000008L
#define DBPROPVAL_CM_TRANSACTIONS						0x00000001L
#endif // OLEDBVER >= 0x0250
//@@@- V2.5
#define DB_IMP_LEVEL_ANONYMOUS       0x00
#define DB_IMP_LEVEL_IDENTIFY        0x01
#define DB_IMP_LEVEL_IMPERSONATE     0x02
#define DB_IMP_LEVEL_DELEGATE        0x03
#define DBPROMPT_PROMPT              0x01
#define DBPROMPT_COMPLETE            0x02
#define DBPROMPT_COMPLETEREQUIRED    0x03
#define DBPROMPT_NOPROMPT            0x04
#define DB_PROT_LEVEL_NONE           0x00
#define DB_PROT_LEVEL_CONNECT        0x01
#define DB_PROT_LEVEL_CALL           0x02
#define DB_PROT_LEVEL_PKT            0x03
#define DB_PROT_LEVEL_PKT_INTEGRITY  0x04
#define DB_PROT_LEVEL_PKT_PRIVACY    0x05
#define DB_MODE_READ                 0x01
#define DB_MODE_WRITE                0x02
#define DB_MODE_READWRITE            0x03
#define DB_MODE_SHARE_DENY_READ      0x04
#define DB_MODE_SHARE_DENY_WRITE     0x08
#define DB_MODE_SHARE_EXCLUSIVE		0x0c
#define DB_MODE_SHARE_DENY_NONE		0x10
#define DBCOMPUTEMODE_COMPUTED       0x01
#define DBCOMPUTEMODE_DYNAMIC        0x02
#define DBCOMPUTEMODE_NOTCOMPUTED    0x03
#define DBPROPVAL_DF_INITIALLY_DEFERRED      0x01
#define DBPROPVAL_DF_INITIALLY_IMMEDIATE     0x02
#define DBPROPVAL_DF_NOT_DEFERRABLE		    0x03
typedef struct tagDBPARAMS
    {
    void __RPC_FAR *pData;
    DB_UPARAMS cParamSets;
    HACCESSOR hAccessor;
    }	DBPARAMS;

typedef DWORD DBPARAMFLAGS;


enum DBPARAMFLAGSENUM
    {	DBPARAMFLAGS_ISINPUT	= 0x1,
	DBPARAMFLAGS_ISOUTPUT	= 0x2,
	DBPARAMFLAGS_ISSIGNED	= 0x10,
	DBPARAMFLAGS_ISNULLABLE	= 0x40,
	DBPARAMFLAGS_ISLONG	= 0x80
    };
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBPARAMFLAGSENUM20
    {	DBPARAMFLAGS_SCALEISNEGATIVE	= 0x100
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
typedef struct tagDBPARAMINFO
    {
    DBPARAMFLAGS dwFlags;
    DBORDINAL iOrdinal;
    LPOLESTR pwszName;
    ITypeInfo __RPC_FAR *pTypeInfo;
    DBLENGTH ulParamSize;
    DBTYPE wType;
    BYTE bPrecision;
    BYTE bScale;
    }	DBPARAMINFO;

typedef DWORD DBPROPID;

typedef struct tagDBPROPIDSET
    {
    /* [size_is] */ DBPROPID __RPC_FAR *rgPropertyIDs;
    ULONG cPropertyIDs;
    GUID guidPropertySet;
    }	DBPROPIDSET;

typedef DWORD DBPROPFLAGS;


enum DBPROPFLAGSENUM
    {	DBPROPFLAGS_NOTSUPPORTED	= 0,
	DBPROPFLAGS_COLUMN	= 0x1,
	DBPROPFLAGS_DATASOURCE	= 0x2,
	DBPROPFLAGS_DATASOURCECREATE	= 0x4,
	DBPROPFLAGS_DATASOURCEINFO	= 0x8,
	DBPROPFLAGS_DBINIT	= 0x10,
	DBPROPFLAGS_INDEX	= 0x20,
	DBPROPFLAGS_ROWSET	= 0x40,
	DBPROPFLAGS_TABLE	= 0x80,
	DBPROPFLAGS_COLUMNOK	= 0x100,
	DBPROPFLAGS_READ	= 0x200,
	DBPROPFLAGS_WRITE	= 0x400,
	DBPROPFLAGS_REQUIRED	= 0x800,
	DBPROPFLAGS_SESSION	= 0x1000
    };
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )

enum DBPROPFLAGSENUM21
    {	DBPROPFLAGS_TRUSTEE	= 0x2000
    };
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
//@@@+ V2.5
#if( OLEDBVER >= 0x0250 )

enum DBPROPFLAGSENUM25
    {	DBPROPFLAGS_VIEW	= 0x4000
    };
#endif // OLEDBVER >= 0x0250
//@@@- V2.5
typedef struct tagDBPROPINFO
    {
    LPOLESTR pwszDescription;
    DBPROPID dwPropertyID;
    DBPROPFLAGS dwFlags;
    VARTYPE vtType;
    VARIANT vValues;
    }	DBPROPINFO;

#if 0 
//DBPROPINFO is an unaligned structure. MIDL workaround. 42212352
typedef DBPROPINFO __RPC_FAR *PDBPROPINFO;

#else
typedef DBPROPINFO UNALIGNED __RPC_FAR * PDBPROPINFO;
#endif
typedef struct tagDBPROPINFOSET
    {
    /* [size_is] */ PDBPROPINFO rgPropertyInfos;
    ULONG cPropertyInfos;
    GUID guidPropertySet;
    }	DBPROPINFOSET;

typedef DWORD DBPROPOPTIONS;

// DBPROPOPTIONS_SETIFCHEAP is deprecated; use DBPROPOPTIONS_OPTIONAL instead.

enum DBPROPOPTIONSENUM
    {	DBPROPOPTIONS_REQUIRED	= 0,
	DBPROPOPTIONS_SETIFCHEAP	= 0x1,
	DBPROPOPTIONS_OPTIONAL	= 0x1
    };
typedef DWORD DBPROPSTATUS;


enum DBPROPSTATUSENUM
    {	DBPROPSTATUS_OK	= 0,
	DBPROPSTATUS_NOTSUPPORTED	= 1,
	DBPROPSTATUS_BADVALUE	= 2,
	DBPROPSTATUS_BADOPTION	= 3,
	DBPROPSTATUS_BADCOLUMN	= 4,
	DBPROPSTATUS_NOTALLSETTABLE	= 5,
	DBPROPSTATUS_NOTSETTABLE	= 6,
	DBPROPSTATUS_NOTSET	= 7,
	DBPROPSTATUS_CONFLICTING	= 8
    };
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )

enum DBPROPSTATUSENUM21
    {	DBPROPSTATUS_NOTAVAILABLE	= 9
    };
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
typedef struct tagDBPROP
    {
    DBPROPID dwPropertyID;
    DBPROPOPTIONS dwOptions;
    DBPROPSTATUS dwStatus;
    DBID colid;
    VARIANT vValue;
    }	DBPROP;

typedef struct tagDBPROPSET
    {
    /* [size_is] */ DBPROP __RPC_FAR *rgProperties;
    ULONG cProperties;
    GUID guidPropertySet;
    }	DBPROPSET;

#define DBPARAMTYPE_INPUT			0x01
#define DBPARAMTYPE_INPUTOUTPUT		0x02
#define DBPARAMTYPE_OUTPUT			0x03
#define DBPARAMTYPE_RETURNVALUE		0x04
#define DB_PT_UNKNOWN				0x01
#define DB_PT_PROCEDURE				0x02
#define DB_PT_FUNCTION				0x03
#define DB_REMOTE					0x01
#define DB_LOCAL_SHARED				0x02
#define DB_LOCAL_EXCLUSIVE			0x03
#define DB_COLLATION_ASC				0x01
#define DB_COLLATION_DESC			0x02
#define DB_UNSEARCHABLE				0x01
#define DB_LIKE_ONLY					0x02
#define DB_ALL_EXCEPT_LIKE			0x03
#define DB_SEARCHABLE				0x04
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
#define MDTREEOP_CHILDREN            0x01
#define MDTREEOP_SIBLINGS            0x02
#define MDTREEOP_PARENT              0x04
#define MDTREEOP_SELF                0x08
#define MDTREEOP_DESCENDANTS         0x10
#define MDTREEOP_ANCESTORS			0x20
#define MD_DIMTYPE_UNKNOWN           0x00
#define MD_DIMTYPE_TIME              0x01
#define MD_DIMTYPE_MEASURE           0x02
#define MD_DIMTYPE_OTHER             0x03
#define MDLEVEL_TYPE_UNKNOWN         0x0000
#define MDLEVEL_TYPE_REGULAR         0x0000
#define MDLEVEL_TYPE_ALL             0x0001
#define MDLEVEL_TYPE_CALCULATED      0x0002
#define MDLEVEL_TYPE_TIME            0x0004
#define MDLEVEL_TYPE_RESERVED1       0x0008
#define MDLEVEL_TYPE_TIME_YEARS      0x0014
#define MDLEVEL_TYPE_TIME_HALF_YEAR  0x0024
#define MDLEVEL_TYPE_TIME_QUARTERS   0x0044
#define MDLEVEL_TYPE_TIME_MONTHS     0x0084
#define MDLEVEL_TYPE_TIME_WEEKS      0x0104
#define MDLEVEL_TYPE_TIME_DAYS       0x0204
#define MDLEVEL_TYPE_TIME_HOURS      0x0304
#define MDLEVEL_TYPE_TIME_MINUTES    0x0404
#define MDLEVEL_TYPE_TIME_SECONDS    0x0804
#define MDLEVEL_TYPE_TIME_UNDEFINED  0x1004
#define MDMEASURE_AGGR_UNKNOWN       0x00
#define MDMEASURE_AGGR_SUM           0x01
#define MDMEASURE_AGGR_COUNT         0x02
#define MDMEASURE_AGGR_MIN           0x03
#define MDMEASURE_AGGR_MAX           0x04
#define MDMEASURE_AGGR_AVG           0x05
#define MDMEASURE_AGGR_VAR           0x06
#define MDMEASURE_AGGR_STD           0x07
#define MDMEASURE_AGGR_CALCULATED    0x7f
#define MDPROP_MEMBER                0x01
#define MDPROP_CELL                  0x02
#define MDMEMBER_TYPE_UNKNOWN        0x00
#define MDMEMBER_TYPE_REGULAR        0x01
#define MDMEMBER_TYPE_ALL            0x02
#define MDMEMBER_TYPE_MEASURE        0x03
#define MDMEMBER_TYPE_FORMULA        0x04
#define MDMEMBER_TYPE_RESERVE1       0x05
#define MDMEMBER_TYPE_RESERVE2       0x06
#define MDMEMBER_TYPE_RESERVE3       0x07
#define MDMEMBER_TYPE_RESERVE4       0x08
#define MDDISPINFO_DRILLED_DOWN				0x00010000
#define MDDISPINFO_PARENT_SAME_AS_PREV		0x00020000
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
typedef DWORD DBINDEX_COL_ORDER;


enum DBINDEX_COL_ORDERENUM
    {	DBINDEX_COL_ORDER_ASC	= 0,
	DBINDEX_COL_ORDER_DESC	= DBINDEX_COL_ORDER_ASC + 1
    };
typedef struct tagDBINDEXCOLUMNDESC
    {
    DBID __RPC_FAR *pColumnID;
    DBINDEX_COL_ORDER eIndexColOrder;
    }	DBINDEXCOLUMNDESC;

typedef struct tagDBCOLUMNDESC
    {
    LPOLESTR pwszTypeName;
    ITypeInfo __RPC_FAR *pTypeInfo;
    /* [size_is] */ DBPROPSET __RPC_FAR *rgPropertySets;
    CLSID __RPC_FAR *pclsid;
    ULONG cPropertySets;
    DBLENGTH ulColumnSize;
    DBID dbcid;
    DBTYPE wType;
    BYTE bPrecision;
    BYTE bScale;
    }	DBCOLUMNDESC;

//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
typedef struct tagDBCOLUMNACCESS
    {
    void __RPC_FAR *pData;
    DBID columnid;
    DBLENGTH cbDataLen;
    DBSTATUS dwStatus;
    DBLENGTH cbMaxLen;
    DB_DWRESERVE dwReserved;
    DBTYPE wType;
    BYTE bPrecision;
    BYTE bScale;
    }	DBCOLUMNACCESS;

#endif // OLEDBVER >= 0x0210
//@@@- V2.1
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
typedef DWORD DBCOLUMNDESCFLAGS;


enum DBCOLUMNDESCFLAGSENUM
    {	DBCOLUMNDESCFLAGS_TYPENAME	= 0x1,
	DBCOLUMNDESCFLAGS_ITYPEINFO	= 0x2,
	DBCOLUMNDESCFLAGS_PROPERTIES	= 0x4,
	DBCOLUMNDESCFLAGS_CLSID	= 0x8,
	DBCOLUMNDESCFLAGS_COLSIZE	= 0x10,
	DBCOLUMNDESCFLAGS_DBCID	= 0x20,
	DBCOLUMNDESCFLAGS_WTYPE	= 0x40,
	DBCOLUMNDESCFLAGS_PRECISION	= 0x80,
	DBCOLUMNDESCFLAGS_SCALE	= 0x100
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
typedef DWORD DBEVENTPHASE;


enum DBEVENTPHASEENUM
    {	DBEVENTPHASE_OKTODO	= 0,
	DBEVENTPHASE_ABOUTTODO	= DBEVENTPHASE_OKTODO + 1,
	DBEVENTPHASE_SYNCHAFTER	= DBEVENTPHASE_ABOUTTODO + 1,
	DBEVENTPHASE_FAILEDTODO	= DBEVENTPHASE_SYNCHAFTER + 1,
	DBEVENTPHASE_DIDEVENT	= DBEVENTPHASE_FAILEDTODO + 1
    };
typedef DWORD DBREASON;


enum DBREASONENUM
    {	DBREASON_ROWSET_FETCHPOSITIONCHANGE	= 0,
	DBREASON_ROWSET_RELEASE	= DBREASON_ROWSET_FETCHPOSITIONCHANGE + 1,
	DBREASON_COLUMN_SET	= DBREASON_ROWSET_RELEASE + 1,
	DBREASON_COLUMN_RECALCULATED	= DBREASON_COLUMN_SET + 1,
	DBREASON_ROW_ACTIVATE	= DBREASON_COLUMN_RECALCULATED + 1,
	DBREASON_ROW_RELEASE	= DBREASON_ROW_ACTIVATE + 1,
	DBREASON_ROW_DELETE	= DBREASON_ROW_RELEASE + 1,
	DBREASON_ROW_FIRSTCHANGE	= DBREASON_ROW_DELETE + 1,
	DBREASON_ROW_INSERT	= DBREASON_ROW_FIRSTCHANGE + 1,
	DBREASON_ROW_RESYNCH	= DBREASON_ROW_INSERT + 1,
	DBREASON_ROW_UNDOCHANGE	= DBREASON_ROW_RESYNCH + 1,
	DBREASON_ROW_UNDOINSERT	= DBREASON_ROW_UNDOCHANGE + 1,
	DBREASON_ROW_UNDODELETE	= DBREASON_ROW_UNDOINSERT + 1,
	DBREASON_ROW_UPDATE	= DBREASON_ROW_UNDODELETE + 1,
	DBREASON_ROWSET_CHANGED	= DBREASON_ROW_UPDATE + 1
    };
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )

enum DBREASONENUM15
    {	DBREASON_ROWPOSITION_CHANGED	= DBREASON_ROWSET_CHANGED + 1,
	DBREASON_ROWPOSITION_CHAPTERCHANGED	= DBREASON_ROWPOSITION_CHANGED + 1,
	DBREASON_ROWPOSITION_CLEARED	= DBREASON_ROWPOSITION_CHAPTERCHANGED + 1,
	DBREASON_ROW_ASYNCHINSERT	= DBREASON_ROWPOSITION_CLEARED + 1
    };
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )
typedef DWORD DBCOMPAREOP;


enum DBCOMPAREOPSENUM
    {	DBCOMPAREOPS_LT	= 0,
	DBCOMPAREOPS_LE	= 1,
	DBCOMPAREOPS_EQ	= 2,
	DBCOMPAREOPS_GE	= 3,
	DBCOMPAREOPS_GT	= 4,
	DBCOMPAREOPS_BEGINSWITH	= 5,
	DBCOMPAREOPS_CONTAINS	= 6,
	DBCOMPAREOPS_NE	= 7,
	DBCOMPAREOPS_IGNORE	= 8,
	DBCOMPAREOPS_CASESENSITIVE	= 0x1000,
	DBCOMPAREOPS_CASEINSENSITIVE	= 0x2000
    };
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBCOMPAREOPSENUM20
    {	DBCOMPAREOPS_NOTBEGINSWITH	= 9,
	DBCOMPAREOPS_NOTCONTAINS	= 10
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
typedef DWORD DBASYNCHOP;


enum DBASYNCHOPENUM
    {	DBASYNCHOP_OPEN	= 0
    };
typedef DWORD DBASYNCHPHASE;


enum DBASYNCHPHASEENUM
    {	DBASYNCHPHASE_INITIALIZATION	= 0,
	DBASYNCHPHASE_POPULATION	= DBASYNCHPHASE_INITIALIZATION + 1,
	DBASYNCHPHASE_COMPLETE	= DBASYNCHPHASE_POPULATION + 1,
	DBASYNCHPHASE_CANCELED	= DBASYNCHPHASE_COMPLETE + 1
    };
#define DB_COUNTUNAVAILABLE -1
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
typedef DWORD DBSORT;


enum DBSORTENUM
    {	DBSORT_ASCENDING	= 0,
	DBSORT_DESCENDING	= DBSORT_ASCENDING + 1
    };
#if( OLEDBVER >= 0x0200 )
typedef DWORD DBCOMMANDPERSISTFLAG;


enum DBCOMMANDPERSISTFLAGENUM
    {	DBCOMMANDPERSISTFLAG_NOSAVE	= 0x1
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
#if( OLEDBVER >= 0x0210 )

enum DBCOMMANDPERSISTFLAGENUM21
    {	DBCOMMANDPERSISTFLAG_DEFAULT	= 0,
	DBCOMMANDPERSISTFLAG_PERSISTVIEW	= 0x2,
	DBCOMMANDPERSISTFLAG_PERSISTPROCEDURE	= 0x4
    };
typedef DWORD DBCONSTRAINTTYPE;


enum DBCONSTRAINTTYPEENUM
    {	DBCONSTRAINTTYPE_UNIQUE	= 0,
	DBCONSTRAINTTYPE_FOREIGNKEY	= 0x1,
	DBCONSTRAINTTYPE_PRIMARYKEY	= 0x2,
	DBCONSTRAINTTYPE_CHECK	= 0x3
    };
typedef DWORD DBUPDELRULE;


enum DBUPDELRULEENUM
    {	DBUPDELRULE_NOACTION	= 0,
	DBUPDELRULE_CASCADE	= 0x1,
	DBUPDELRULE_SETNULL	= 0x2,
	DBUPDELRULE_SETDEFAULT	= 0x3
    };
typedef DWORD DBMATCHTYPE;


enum DBMATCHTYPEENUM
    {	DBMATCHTYPE_FULL	= 0,
	DBMATCHTYPE_NONE	= 0x1,
	DBMATCHTYPE_PARTIAL	= 0x2
    };
typedef DWORD DBDEFERRABILITY;


enum DBDEFERRABILITYENUM
    {	DBDEFERRABILITY_DEFERRED	= 0x1,
	DBDEFERRABILITY_DEFERRABLE	= 0x2
    };
typedef struct tagDBCONSTRAINTDESC
    {
    DBID __RPC_FAR *pConstraintID;
    DBCONSTRAINTTYPE ConstraintType;
    DBORDINAL cColumns;
    /* [size_is] */ DBID __RPC_FAR *rgColumnList;
    DBID __RPC_FAR *pReferencedTableID;
    DBORDINAL cForeignKeyColumns;
    /* [size_is] */ DBID __RPC_FAR *rgForeignKeyColumnList;
    OLECHAR __RPC_FAR *pwszConstraintText;
    DBUPDELRULE UpdateRule;
    DBUPDELRULE DeleteRule;
    DBMATCHTYPE MatchType;
    DBDEFERRABILITY Deferrability;
    DB_URESERVE cReserved;
    /* [size_is] */ DBPROPSET __RPC_FAR *rgReserved;
    }	DBCONSTRAINTDESC;

#endif // OLEDBVER >= 0x0210
//@@@- V2.1
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
#define MDFF_BOLD                    0x01
#define MDFF_ITALIC                  0x02
#define MDFF_UNDERLINE               0x04
#define MDFF_STRIKEOUT               0x08
typedef struct tagMDAXISINFO
    {
    DBLENGTH cbSize;
    DBCOUNTITEM iAxis;
    DBCOUNTITEM cDimensions;
    DBCOUNTITEM cCoordinates;
    DBORDINAL __RPC_FAR *rgcColumns;
    LPOLESTR __RPC_FAR *rgpwszDimensionNames;
    }	MDAXISINFO;

#define PMDAXISINFO_GETAT(rgAxisInfo, iAxis) ((MDAXISINFO *)(((BYTE *)(rgAxisInfo)) +((iAxis) * (rgAxisInfo)[0].cbSize)))
#define MDAXISINFO_GETAT(rgAxisInfo, iAxis) (*PMDAXISINFO_GETAT((rgAxisInfo), (iAxis)))
#define MDAXIS_COLUMNS               0x00000000
#define MDAXIS_ROWS                  0x00000001
#define MDAXIS_PAGES                 0x00000002
#define MDAXIS_SECTIONS              0x00000003
#define MDAXIS_CHAPTERS              0x00000004
#define MDAXIS_SLICERS               0xffffffff
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
typedef struct tagRMTPACK
    {
    ISequentialStream __RPC_FAR *pISeqStream;
    ULONG cbData;
    ULONG cBSTR;
    /* [size_is] */ BSTR __RPC_FAR *rgBSTR;
    ULONG cVARIANT;
    /* [size_is] */ VARIANT __RPC_FAR *rgVARIANT;
    ULONG cIDISPATCH;
    /* [size_is] */ IDispatch __RPC_FAR *__RPC_FAR *rgIDISPATCH;
    ULONG cIUNKNOWN;
    /* [size_is] */ IUnknown __RPC_FAR *__RPC_FAR *rgIUNKNOWN;
    ULONG cPROPVARIANT;
    /* [size_is] */ PROPVARIANT __RPC_FAR *rgPROPVARIANT;
    ULONG cArray;
    /* [size_is] */ VARIANT __RPC_FAR *rgArray;
    }	RMTPACK;


#endif // GUID_DEFS_ONLY


extern RPC_IF_HANDLE DBStructureDefinitions_v0_0_c_ifspec;
extern RPC_IF_HANDLE DBStructureDefinitions_v0_0_s_ifspec;
#endif /* __DBStructureDefinitions_INTERFACE_DEFINED__ */

/* interface __MIDL_itf_oledb_0257 */
/* [local] */ 

#ifndef GUID_DEFS_ONLY



extern RPC_IF_HANDLE __MIDL_itf_oledb_0257_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0257_v0_0_s_ifspec;

#ifndef __IAccessor_INTERFACE_DEFINED__
#define __IAccessor_INTERFACE_DEFINED__

/* interface IAccessor */
/* [unique][uuid][object] */ 

typedef DWORD DBACCESSORFLAGS;


enum DBACCESSORFLAGSENUM
    {	DBACCESSOR_INVALID	= 0,
	DBACCESSOR_PASSBYREF	= 0x1,
	DBACCESSOR_ROWDATA	= 0x2,
	DBACCESSOR_PARAMETERDATA	= 0x4,
	DBACCESSOR_OPTIMIZED	= 0x8,
	DBACCESSOR_INHERITED	= 0x10
    };
typedef DWORD DBBINDSTATUS;


enum DBBINDSTATUSENUM
    {	DBBINDSTATUS_OK	= 0,
	DBBINDSTATUS_BADORDINAL	= 1,
	DBBINDSTATUS_UNSUPPORTEDCONVERSION	= 2,
	DBBINDSTATUS_BADBINDINFO	= 3,
	DBBINDSTATUS_BADSTORAGEFLAGS	= 4,
	DBBINDSTATUS_NOINTERFACE	= 5,
	DBBINDSTATUS_MULTIPLESTORAGE	= 6
    };

EXTERN_C const IID IID_IAccessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a8c-2a1c-11ce-ade5-00aa0044773d")
    IAccessor : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE AddRefAccessor( 
            /* [in] */ HACCESSOR hAccessor,
            /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateAccessor( 
            /* [in] */ DBACCESSORFLAGS dwAccessorFlags,
            /* [in] */ DBCOUNTITEM cBindings,
            /* [size_is][in] */ const DBBINDING __RPC_FAR rgBindings[  ],
            /* [in] */ DBLENGTH cbRowSize,
            /* [out] */ HACCESSOR __RPC_FAR *phAccessor,
            /* [size_is][out] */ DBBINDSTATUS __RPC_FAR rgStatus[  ]) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetBindings( 
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ DBACCESSORFLAGS __RPC_FAR *pdwAccessorFlags,
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcBindings,
            /* [size_is][size_is][out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE ReleaseAccessor( 
            /* [in] */ HACCESSOR hAccessor,
            /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccessor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccessor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccessor __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRefAccessor )( 
            IAccessor __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateAccessor )( 
            IAccessor __RPC_FAR * This,
            /* [in] */ DBACCESSORFLAGS dwAccessorFlags,
            /* [in] */ DBCOUNTITEM cBindings,
            /* [size_is][in] */ const DBBINDING __RPC_FAR rgBindings[  ],
            /* [in] */ DBLENGTH cbRowSize,
            /* [out] */ HACCESSOR __RPC_FAR *phAccessor,
            /* [size_is][out] */ DBBINDSTATUS __RPC_FAR rgStatus[  ]);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBindings )( 
            IAccessor __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ DBACCESSORFLAGS __RPC_FAR *pdwAccessorFlags,
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcBindings,
            /* [size_is][size_is][out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseAccessor )( 
            IAccessor __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount);
        
        END_INTERFACE
    } IAccessorVtbl;

    interface IAccessor
    {
        CONST_VTBL struct IAccessorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccessor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccessor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccessor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccessor_AddRefAccessor(This,hAccessor,pcRefCount)	\
    (This)->lpVtbl -> AddRefAccessor(This,hAccessor,pcRefCount)

#define IAccessor_CreateAccessor(This,dwAccessorFlags,cBindings,rgBindings,cbRowSize,phAccessor,rgStatus)	\
    (This)->lpVtbl -> CreateAccessor(This,dwAccessorFlags,cBindings,rgBindings,cbRowSize,phAccessor,rgStatus)

#define IAccessor_GetBindings(This,hAccessor,pdwAccessorFlags,pcBindings,prgBindings)	\
    (This)->lpVtbl -> GetBindings(This,hAccessor,pdwAccessorFlags,pcBindings,prgBindings)

#define IAccessor_ReleaseAccessor(This,hAccessor,pcRefCount)	\
    (This)->lpVtbl -> ReleaseAccessor(This,hAccessor,pcRefCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IAccessor_RemoteAddRefAccessor_Proxy( 
    IAccessor __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IAccessor_RemoteAddRefAccessor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IAccessor_RemoteCreateAccessor_Proxy( 
    IAccessor __RPC_FAR * This,
    /* [in] */ DBACCESSORFLAGS dwAccessorFlags,
    /* [in] */ DBCOUNTITEM cBindings,
    /* [size_is][unique][in] */ DBBINDING __RPC_FAR *rgBindings,
    /* [in] */ DBLENGTH cbRowSize,
    /* [out] */ HACCESSOR __RPC_FAR *phAccessor,
    /* [size_is][unique][out][in] */ DBBINDSTATUS __RPC_FAR *rgStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IAccessor_RemoteCreateAccessor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IAccessor_RemoteGetBindings_Proxy( 
    IAccessor __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [out] */ DBACCESSORFLAGS __RPC_FAR *pdwAccessorFlags,
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcBindings,
    /* [size_is][size_is][out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IAccessor_RemoteGetBindings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IAccessor_RemoteReleaseAccessor_Proxy( 
    IAccessor __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IAccessor_RemoteReleaseAccessor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccessor_INTERFACE_DEFINED__ */


#ifndef __IRowset_INTERFACE_DEFINED__
#define __IRowset_INTERFACE_DEFINED__

/* interface IRowset */
/* [unique][uuid][object][local] */ 

typedef DWORD DBROWOPTIONS;


EXTERN_C const IID IID_IRowset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a7c-2a1c-11ce-ade5-00aa0044773d")
    IRowset : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddRefRows( 
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetData( 
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextRows( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseRows( 
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][in] */ DBROWOPTIONS __RPC_FAR rgRowOptions[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RestartPosition( 
            /* [in] */ HCHAPTER hReserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowset __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRefRows )( 
            IRowset __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetData )( 
            IRowset __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextRows )( 
            IRowset __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseRows )( 
            IRowset __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][in] */ DBROWOPTIONS __RPC_FAR rgRowOptions[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RestartPosition )( 
            IRowset __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved);
        
        END_INTERFACE
    } IRowsetVtbl;

    interface IRowset
    {
        CONST_VTBL struct IRowsetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowset_AddRefRows(This,cRows,rghRows,rgRefCounts,rgRowStatus)	\
    (This)->lpVtbl -> AddRefRows(This,cRows,rghRows,rgRefCounts,rgRowStatus)

#define IRowset_GetData(This,hRow,hAccessor,pData)	\
    (This)->lpVtbl -> GetData(This,hRow,hAccessor,pData)

#define IRowset_GetNextRows(This,hReserved,lRowsOffset,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> GetNextRows(This,hReserved,lRowsOffset,cRows,pcRowsObtained,prghRows)

#define IRowset_ReleaseRows(This,cRows,rghRows,rgRowOptions,rgRefCounts,rgRowStatus)	\
    (This)->lpVtbl -> ReleaseRows(This,cRows,rghRows,rgRowOptions,rgRefCounts,rgRowStatus)

#define IRowset_RestartPosition(This,hReserved)	\
    (This)->lpVtbl -> RestartPosition(This,hReserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowset_AddRefRows_Proxy( 
    IRowset __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
    /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
    /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);


void __RPC_STUB IRowset_AddRefRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowset_GetData_Proxy( 
    IRowset __RPC_FAR * This,
    /* [in] */ HROW hRow,
    /* [in] */ HACCESSOR hAccessor,
    /* [out] */ void __RPC_FAR *pData);


void __RPC_STUB IRowset_GetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowset_GetNextRows_Proxy( 
    IRowset __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBROWOFFSET lRowsOffset,
    /* [in] */ DBROWCOUNT cRows,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
    /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);


void __RPC_STUB IRowset_GetNextRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowset_ReleaseRows_Proxy( 
    IRowset __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
    /* [size_is][in] */ DBROWOPTIONS __RPC_FAR rgRowOptions[  ],
    /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
    /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);


void __RPC_STUB IRowset_ReleaseRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowset_RestartPosition_Proxy( 
    IRowset __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved);


void __RPC_STUB IRowset_RestartPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowset_INTERFACE_DEFINED__ */


#ifndef __IRowsetInfo_INTERFACE_DEFINED__
#define __IRowsetInfo_INTERFACE_DEFINED__

/* interface IRowsetInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRowsetInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a55-2a1c-11ce-ade5-00aa0044773d")
    IRowsetInfo : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [in] */ const ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetReferencedRowset( 
            /* [in] */ DBORDINAL iOrdinal,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppReferencedRowset) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetSpecification( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSpecification) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetInfo __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProperties )( 
            IRowsetInfo __RPC_FAR * This,
            /* [in] */ const ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReferencedRowset )( 
            IRowsetInfo __RPC_FAR * This,
            /* [in] */ DBORDINAL iOrdinal,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppReferencedRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpecification )( 
            IRowsetInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSpecification);
        
        END_INTERFACE
    } IRowsetInfoVtbl;

    interface IRowsetInfo
    {
        CONST_VTBL struct IRowsetInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetInfo_GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)	\
    (This)->lpVtbl -> GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)

#define IRowsetInfo_GetReferencedRowset(This,iOrdinal,riid,ppReferencedRowset)	\
    (This)->lpVtbl -> GetReferencedRowset(This,iOrdinal,riid,ppReferencedRowset)

#define IRowsetInfo_GetSpecification(This,riid,ppSpecification)	\
    (This)->lpVtbl -> GetSpecification(This,riid,ppSpecification)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetInfo_RemoteGetProperties_Proxy( 
    IRowsetInfo __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowsetInfo_RemoteGetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetInfo_RemoteGetReferencedRowset_Proxy( 
    IRowsetInfo __RPC_FAR * This,
    /* [in] */ DBORDINAL iOrdinal,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppReferencedRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowsetInfo_RemoteGetReferencedRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetInfo_RemoteGetSpecification_Proxy( 
    IRowsetInfo __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSpecification,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowsetInfo_RemoteGetSpecification_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetInfo_INTERFACE_DEFINED__ */


#ifndef __IRowsetLocate_INTERFACE_DEFINED__
#define __IRowsetLocate_INTERFACE_DEFINED__

/* interface IRowsetLocate */
/* [unique][uuid][object][local] */ 

typedef DWORD DBCOMPARE;


enum DBCOMPAREENUM
    {	DBCOMPARE_LT	= 0,
	DBCOMPARE_EQ	= DBCOMPARE_LT + 1,
	DBCOMPARE_GT	= DBCOMPARE_EQ + 1,
	DBCOMPARE_NE	= DBCOMPARE_GT + 1,
	DBCOMPARE_NOTCOMPARABLE	= DBCOMPARE_NE + 1
    };

EXTERN_C const IID IID_IRowsetLocate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a7d-2a1c-11ce-ade5-00aa0044773d")
    IRowsetLocate : public IRowset
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Compare( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cbBookmark1,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark1,
            /* [in] */ DBBKMARK cbBookmark2,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark2,
            /* [out] */ DBCOMPARE __RPC_FAR *pComparison) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRowsAt( 
            /* [in] */ HWATCHREGION hReserved1,
            /* [in] */ HCHAPTER hReserved2,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRowsByBookmark( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
            /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
            /* [size_is][out] */ HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Hash( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cBookmarks,
            /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
            /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
            /* [size_is][out] */ DBHASHVALUE __RPC_FAR rgHashedValues[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgBookmarkStatus[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetLocateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetLocate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetLocate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRefRows )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetData )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextRows )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseRows )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][in] */ DBROWOPTIONS __RPC_FAR rgRowOptions[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RestartPosition )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Compare )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cbBookmark1,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark1,
            /* [in] */ DBBKMARK cbBookmark2,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark2,
            /* [out] */ DBCOMPARE __RPC_FAR *pComparison);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowsAt )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ HWATCHREGION hReserved1,
            /* [in] */ HCHAPTER hReserved2,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowsByBookmark )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
            /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
            /* [size_is][out] */ HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hash )( 
            IRowsetLocate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cBookmarks,
            /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
            /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
            /* [size_is][out] */ DBHASHVALUE __RPC_FAR rgHashedValues[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgBookmarkStatus[  ]);
        
        END_INTERFACE
    } IRowsetLocateVtbl;

    interface IRowsetLocate
    {
        CONST_VTBL struct IRowsetLocateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetLocate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetLocate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetLocate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetLocate_AddRefRows(This,cRows,rghRows,rgRefCounts,rgRowStatus)	\
    (This)->lpVtbl -> AddRefRows(This,cRows,rghRows,rgRefCounts,rgRowStatus)

#define IRowsetLocate_GetData(This,hRow,hAccessor,pData)	\
    (This)->lpVtbl -> GetData(This,hRow,hAccessor,pData)

#define IRowsetLocate_GetNextRows(This,hReserved,lRowsOffset,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> GetNextRows(This,hReserved,lRowsOffset,cRows,pcRowsObtained,prghRows)

#define IRowsetLocate_ReleaseRows(This,cRows,rghRows,rgRowOptions,rgRefCounts,rgRowStatus)	\
    (This)->lpVtbl -> ReleaseRows(This,cRows,rghRows,rgRowOptions,rgRefCounts,rgRowStatus)

#define IRowsetLocate_RestartPosition(This,hReserved)	\
    (This)->lpVtbl -> RestartPosition(This,hReserved)


#define IRowsetLocate_Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)	\
    (This)->lpVtbl -> Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)

#define IRowsetLocate_GetRowsAt(This,hReserved1,hReserved2,cbBookmark,pBookmark,lRowsOffset,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> GetRowsAt(This,hReserved1,hReserved2,cbBookmark,pBookmark,lRowsOffset,cRows,pcRowsObtained,prghRows)

#define IRowsetLocate_GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)	\
    (This)->lpVtbl -> GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)

#define IRowsetLocate_Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)	\
    (This)->lpVtbl -> Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetLocate_Compare_Proxy( 
    IRowsetLocate __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBBKMARK cbBookmark1,
    /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark1,
    /* [in] */ DBBKMARK cbBookmark2,
    /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark2,
    /* [out] */ DBCOMPARE __RPC_FAR *pComparison);


void __RPC_STUB IRowsetLocate_Compare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetLocate_GetRowsAt_Proxy( 
    IRowsetLocate __RPC_FAR * This,
    /* [in] */ HWATCHREGION hReserved1,
    /* [in] */ HCHAPTER hReserved2,
    /* [in] */ DBBKMARK cbBookmark,
    /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
    /* [in] */ DBROWOFFSET lRowsOffset,
    /* [in] */ DBROWCOUNT cRows,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
    /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);


void __RPC_STUB IRowsetLocate_GetRowsAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetLocate_GetRowsByBookmark_Proxy( 
    IRowsetLocate __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
    /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
    /* [size_is][out] */ HROW __RPC_FAR rghRows[  ],
    /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);


void __RPC_STUB IRowsetLocate_GetRowsByBookmark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetLocate_Hash_Proxy( 
    IRowsetLocate __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBBKMARK cBookmarks,
    /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
    /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
    /* [size_is][out] */ DBHASHVALUE __RPC_FAR rgHashedValues[  ],
    /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgBookmarkStatus[  ]);


void __RPC_STUB IRowsetLocate_Hash_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetLocate_INTERFACE_DEFINED__ */


#ifndef __IRowsetResynch_INTERFACE_DEFINED__
#define __IRowsetResynch_INTERFACE_DEFINED__

/* interface IRowsetResynch */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowsetResynch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a84-2a1c-11ce-ade5-00aa0044773d")
    IRowsetResynch : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVisibleData( 
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResynchRows( 
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsResynched,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRowsResynched,
            /* [size_is][size_is][out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetResynchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetResynch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetResynch __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetResynch __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisibleData )( 
            IRowsetResynch __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResynchRows )( 
            IRowsetResynch __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsResynched,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRowsResynched,
            /* [size_is][size_is][out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus);
        
        END_INTERFACE
    } IRowsetResynchVtbl;

    interface IRowsetResynch
    {
        CONST_VTBL struct IRowsetResynchVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetResynch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetResynch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetResynch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetResynch_GetVisibleData(This,hRow,hAccessor,pData)	\
    (This)->lpVtbl -> GetVisibleData(This,hRow,hAccessor,pData)

#define IRowsetResynch_ResynchRows(This,cRows,rghRows,pcRowsResynched,prghRowsResynched,prgRowStatus)	\
    (This)->lpVtbl -> ResynchRows(This,cRows,rghRows,pcRowsResynched,prghRowsResynched,prgRowStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetResynch_GetVisibleData_Proxy( 
    IRowsetResynch __RPC_FAR * This,
    /* [in] */ HROW hRow,
    /* [in] */ HACCESSOR hAccessor,
    /* [out] */ void __RPC_FAR *pData);


void __RPC_STUB IRowsetResynch_GetVisibleData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetResynch_ResynchRows_Proxy( 
    IRowsetResynch __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
    /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsResynched,
    /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRowsResynched,
    /* [size_is][size_is][out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus);


void __RPC_STUB IRowsetResynch_ResynchRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetResynch_INTERFACE_DEFINED__ */


#ifndef __IRowsetScroll_INTERFACE_DEFINED__
#define __IRowsetScroll_INTERFACE_DEFINED__

/* interface IRowsetScroll */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowsetScroll;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a7e-2a1c-11ce-ade5-00aa0044773d")
    IRowsetScroll : public IRowsetLocate
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetApproximatePosition( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pulPosition,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRowsAtRatio( 
            /* [in] */ HWATCHREGION hReserved1,
            /* [in] */ HCHAPTER hReserved2,
            /* [in] */ DBCOUNTITEM ulNumerator,
            /* [in] */ DBCOUNTITEM ulDenominator,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetScrollVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetScroll __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetScroll __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRefRows )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetData )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextRows )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseRows )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][in] */ DBROWOPTIONS __RPC_FAR rgRowOptions[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RestartPosition )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Compare )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cbBookmark1,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark1,
            /* [in] */ DBBKMARK cbBookmark2,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark2,
            /* [out] */ DBCOMPARE __RPC_FAR *pComparison);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowsAt )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ HWATCHREGION hReserved1,
            /* [in] */ HCHAPTER hReserved2,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowsByBookmark )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
            /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
            /* [size_is][out] */ HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hash )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cBookmarks,
            /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
            /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
            /* [size_is][out] */ DBHASHVALUE __RPC_FAR rgHashedValues[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgBookmarkStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetApproximatePosition )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pulPosition,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowsAtRatio )( 
            IRowsetScroll __RPC_FAR * This,
            /* [in] */ HWATCHREGION hReserved1,
            /* [in] */ HCHAPTER hReserved2,
            /* [in] */ DBCOUNTITEM ulNumerator,
            /* [in] */ DBCOUNTITEM ulDenominator,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        END_INTERFACE
    } IRowsetScrollVtbl;

    interface IRowsetScroll
    {
        CONST_VTBL struct IRowsetScrollVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetScroll_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetScroll_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetScroll_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetScroll_AddRefRows(This,cRows,rghRows,rgRefCounts,rgRowStatus)	\
    (This)->lpVtbl -> AddRefRows(This,cRows,rghRows,rgRefCounts,rgRowStatus)

#define IRowsetScroll_GetData(This,hRow,hAccessor,pData)	\
    (This)->lpVtbl -> GetData(This,hRow,hAccessor,pData)

#define IRowsetScroll_GetNextRows(This,hReserved,lRowsOffset,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> GetNextRows(This,hReserved,lRowsOffset,cRows,pcRowsObtained,prghRows)

#define IRowsetScroll_ReleaseRows(This,cRows,rghRows,rgRowOptions,rgRefCounts,rgRowStatus)	\
    (This)->lpVtbl -> ReleaseRows(This,cRows,rghRows,rgRowOptions,rgRefCounts,rgRowStatus)

#define IRowsetScroll_RestartPosition(This,hReserved)	\
    (This)->lpVtbl -> RestartPosition(This,hReserved)


#define IRowsetScroll_Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)	\
    (This)->lpVtbl -> Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)

#define IRowsetScroll_GetRowsAt(This,hReserved1,hReserved2,cbBookmark,pBookmark,lRowsOffset,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> GetRowsAt(This,hReserved1,hReserved2,cbBookmark,pBookmark,lRowsOffset,cRows,pcRowsObtained,prghRows)

#define IRowsetScroll_GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)	\
    (This)->lpVtbl -> GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)

#define IRowsetScroll_Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)	\
    (This)->lpVtbl -> Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)


#define IRowsetScroll_GetApproximatePosition(This,hReserved,cbBookmark,pBookmark,pulPosition,pcRows)	\
    (This)->lpVtbl -> GetApproximatePosition(This,hReserved,cbBookmark,pBookmark,pulPosition,pcRows)

#define IRowsetScroll_GetRowsAtRatio(This,hReserved1,hReserved2,ulNumerator,ulDenominator,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> GetRowsAtRatio(This,hReserved1,hReserved2,ulNumerator,ulDenominator,cRows,pcRowsObtained,prghRows)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetScroll_GetApproximatePosition_Proxy( 
    IRowsetScroll __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBBKMARK cbBookmark,
    /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pulPosition,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows);


void __RPC_STUB IRowsetScroll_GetApproximatePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetScroll_GetRowsAtRatio_Proxy( 
    IRowsetScroll __RPC_FAR * This,
    /* [in] */ HWATCHREGION hReserved1,
    /* [in] */ HCHAPTER hReserved2,
    /* [in] */ DBCOUNTITEM ulNumerator,
    /* [in] */ DBCOUNTITEM ulDenominator,
    /* [in] */ DBROWCOUNT cRows,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
    /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);


void __RPC_STUB IRowsetScroll_GetRowsAtRatio_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetScroll_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oledb_0263 */
/* [local] */ 

//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )


extern RPC_IF_HANDLE __MIDL_itf_oledb_0263_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0263_v0_0_s_ifspec;

#ifndef __IChapteredRowset_INTERFACE_DEFINED__
#define __IChapteredRowset_INTERFACE_DEFINED__

/* interface IChapteredRowset */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IChapteredRowset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a93-2a1c-11ce-ade5-00aa0044773d")
    IChapteredRowset : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE AddRefChapter( 
            /* [in] */ HCHAPTER hChapter,
            /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE ReleaseChapter( 
            /* [in] */ HCHAPTER hChapter,
            /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChapteredRowsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IChapteredRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IChapteredRowset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IChapteredRowset __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRefChapter )( 
            IChapteredRowset __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseChapter )( 
            IChapteredRowset __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount);
        
        END_INTERFACE
    } IChapteredRowsetVtbl;

    interface IChapteredRowset
    {
        CONST_VTBL struct IChapteredRowsetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChapteredRowset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChapteredRowset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChapteredRowset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChapteredRowset_AddRefChapter(This,hChapter,pcRefCount)	\
    (This)->lpVtbl -> AddRefChapter(This,hChapter,pcRefCount)

#define IChapteredRowset_ReleaseChapter(This,hChapter,pcRefCount)	\
    (This)->lpVtbl -> ReleaseChapter(This,hChapter,pcRefCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IChapteredRowset_RemoteAddRefChapter_Proxy( 
    IChapteredRowset __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IChapteredRowset_RemoteAddRefChapter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IChapteredRowset_RemoteReleaseChapter_Proxy( 
    IChapteredRowset __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IChapteredRowset_RemoteReleaseChapter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChapteredRowset_INTERFACE_DEFINED__ */


#ifndef __IRowsetFind_INTERFACE_DEFINED__
#define __IRowsetFind_INTERFACE_DEFINED__

/* interface IRowsetFind */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowsetFind;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a9d-2a1c-11ce-ade5-00aa0044773d")
    IRowsetFind : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FindNextRow( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ void __RPC_FAR *pFindValue,
            /* [in] */ DBCOMPAREOP CompareOp,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetFindVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetFind __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetFind __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetFind __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindNextRow )( 
            IRowsetFind __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ void __RPC_FAR *pFindValue,
            /* [in] */ DBCOMPAREOP CompareOp,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        END_INTERFACE
    } IRowsetFindVtbl;

    interface IRowsetFind
    {
        CONST_VTBL struct IRowsetFindVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetFind_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetFind_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetFind_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetFind_FindNextRow(This,hChapter,hAccessor,pFindValue,CompareOp,cbBookmark,pBookmark,lRowsOffset,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> FindNextRow(This,hChapter,hAccessor,pFindValue,CompareOp,cbBookmark,pBookmark,lRowsOffset,cRows,pcRowsObtained,prghRows)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetFind_FindNextRow_Proxy( 
    IRowsetFind __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ HACCESSOR hAccessor,
    /* [in] */ void __RPC_FAR *pFindValue,
    /* [in] */ DBCOMPAREOP CompareOp,
    /* [in] */ DBBKMARK cbBookmark,
    /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
    /* [in] */ DBROWOFFSET lRowsOffset,
    /* [in] */ DBROWCOUNT cRows,
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
    /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);


void __RPC_STUB IRowsetFind_FindNextRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetFind_INTERFACE_DEFINED__ */


#ifndef __IRowPosition_INTERFACE_DEFINED__
#define __IRowPosition_INTERFACE_DEFINED__

/* interface IRowPosition */
/* [unique][uuid][object] */ 

typedef DWORD DBPOSITIONFLAGS;


enum DBPOSITIONFLAGSENUM
    {	DBPOSITION_OK	= 0,
	DBPOSITION_NOROW	= DBPOSITION_OK + 1,
	DBPOSITION_BOF	= DBPOSITION_NOROW + 1,
	DBPOSITION_EOF	= DBPOSITION_BOF + 1
    };

EXTERN_C const IID IID_IRowPosition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a94-2a1c-11ce-ade5-00aa0044773d")
    IRowPosition : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE ClearRowPosition( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetRowPosition( 
            /* [out] */ HCHAPTER __RPC_FAR *phChapter,
            /* [out] */ HROW __RPC_FAR *phRow,
            /* [out] */ DBPOSITIONFLAGS __RPC_FAR *pdwPositionFlags) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetRowset( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IUnknown __RPC_FAR *pRowset) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetRowPosition( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ HROW hRow,
            /* [in] */ DBPOSITIONFLAGS dwPositionFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowPositionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowPosition __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowPosition __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowPosition __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearRowPosition )( 
            IRowPosition __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowPosition )( 
            IRowPosition __RPC_FAR * This,
            /* [out] */ HCHAPTER __RPC_FAR *phChapter,
            /* [out] */ HROW __RPC_FAR *phRow,
            /* [out] */ DBPOSITIONFLAGS __RPC_FAR *pdwPositionFlags);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowset )( 
            IRowPosition __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            IRowPosition __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRowPosition )( 
            IRowPosition __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ HROW hRow,
            /* [in] */ DBPOSITIONFLAGS dwPositionFlags);
        
        END_INTERFACE
    } IRowPositionVtbl;

    interface IRowPosition
    {
        CONST_VTBL struct IRowPositionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowPosition_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowPosition_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowPosition_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowPosition_ClearRowPosition(This)	\
    (This)->lpVtbl -> ClearRowPosition(This)

#define IRowPosition_GetRowPosition(This,phChapter,phRow,pdwPositionFlags)	\
    (This)->lpVtbl -> GetRowPosition(This,phChapter,phRow,pdwPositionFlags)

#define IRowPosition_GetRowset(This,riid,ppRowset)	\
    (This)->lpVtbl -> GetRowset(This,riid,ppRowset)

#define IRowPosition_Initialize(This,pRowset)	\
    (This)->lpVtbl -> Initialize(This,pRowset)

#define IRowPosition_SetRowPosition(This,hChapter,hRow,dwPositionFlags)	\
    (This)->lpVtbl -> SetRowPosition(This,hChapter,hRow,dwPositionFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_RemoteClearRowPosition_Proxy( 
    IRowPosition __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowPosition_RemoteClearRowPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_RemoteGetRowPosition_Proxy( 
    IRowPosition __RPC_FAR * This,
    /* [out] */ HCHAPTER __RPC_FAR *phChapter,
    /* [out] */ HROW __RPC_FAR *phRow,
    /* [out] */ DBPOSITIONFLAGS __RPC_FAR *pdwPositionFlags,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowPosition_RemoteGetRowPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_RemoteGetRowset_Proxy( 
    IRowPosition __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowPosition_RemoteGetRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_RemoteInitialize_Proxy( 
    IRowPosition __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowPosition_RemoteInitialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_RemoteSetRowPosition_Proxy( 
    IRowPosition __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ HROW hRow,
    /* [in] */ DBPOSITIONFLAGS dwPositionFlags,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowPosition_RemoteSetRowPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowPosition_INTERFACE_DEFINED__ */


#ifndef __IRowPositionChange_INTERFACE_DEFINED__
#define __IRowPositionChange_INTERFACE_DEFINED__

/* interface IRowPositionChange */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRowPositionChange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0997a571-126e-11d0-9f8a-00a0c9a0631e")
    IRowPositionChange : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OnRowPositionChange( 
            /* [in] */ DBREASON eReason,
            /* [in] */ DBEVENTPHASE ePhase,
            /* [in] */ BOOL fCantDeny) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowPositionChangeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowPositionChange __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowPositionChange __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowPositionChange __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRowPositionChange )( 
            IRowPositionChange __RPC_FAR * This,
            /* [in] */ DBREASON eReason,
            /* [in] */ DBEVENTPHASE ePhase,
            /* [in] */ BOOL fCantDeny);
        
        END_INTERFACE
    } IRowPositionChangeVtbl;

    interface IRowPositionChange
    {
        CONST_VTBL struct IRowPositionChangeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowPositionChange_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowPositionChange_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowPositionChange_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowPositionChange_OnRowPositionChange(This,eReason,ePhase,fCantDeny)	\
    (This)->lpVtbl -> OnRowPositionChange(This,eReason,ePhase,fCantDeny)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPositionChange_RemoteOnRowPositionChange_Proxy( 
    IRowPositionChange __RPC_FAR * This,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowPositionChange_RemoteOnRowPositionChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowPositionChange_INTERFACE_DEFINED__ */


#ifndef __IViewRowset_INTERFACE_DEFINED__
#define __IViewRowset_INTERFACE_DEFINED__

/* interface IViewRowset */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IViewRowset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a97-2a1c-11ce-ade5-00aa0044773d")
    IViewRowset : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetSpecification( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OpenViewRowset( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IViewRowsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IViewRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IViewRowset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IViewRowset __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpecification )( 
            IViewRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenViewRowset )( 
            IViewRowset __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        END_INTERFACE
    } IViewRowsetVtbl;

    interface IViewRowset
    {
        CONST_VTBL struct IViewRowsetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewRowset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewRowset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewRowset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewRowset_GetSpecification(This,riid,ppObject)	\
    (This)->lpVtbl -> GetSpecification(This,riid,ppObject)

#define IViewRowset_OpenViewRowset(This,pUnkOuter,riid,ppRowset)	\
    (This)->lpVtbl -> OpenViewRowset(This,pUnkOuter,riid,ppRowset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewRowset_RemoteGetSpecification_Proxy( 
    IViewRowset __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IViewRowset_RemoteGetSpecification_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewRowset_RemoteOpenViewRowset_Proxy( 
    IViewRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IViewRowset_RemoteOpenViewRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IViewRowset_INTERFACE_DEFINED__ */


#ifndef __IViewChapter_INTERFACE_DEFINED__
#define __IViewChapter_INTERFACE_DEFINED__

/* interface IViewChapter */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IViewChapter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a98-2a1c-11ce-ade5-00aa0044773d")
    IViewChapter : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetSpecification( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OpenViewChapter( 
            /* [in] */ HCHAPTER hSource,
            /* [out] */ HCHAPTER __RPC_FAR *phViewChapter) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IViewChapterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IViewChapter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IViewChapter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IViewChapter __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpecification )( 
            IViewChapter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenViewChapter )( 
            IViewChapter __RPC_FAR * This,
            /* [in] */ HCHAPTER hSource,
            /* [out] */ HCHAPTER __RPC_FAR *phViewChapter);
        
        END_INTERFACE
    } IViewChapterVtbl;

    interface IViewChapter
    {
        CONST_VTBL struct IViewChapterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewChapter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewChapter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewChapter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewChapter_GetSpecification(This,riid,ppRowset)	\
    (This)->lpVtbl -> GetSpecification(This,riid,ppRowset)

#define IViewChapter_OpenViewChapter(This,hSource,phViewChapter)	\
    (This)->lpVtbl -> OpenViewChapter(This,hSource,phViewChapter)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewChapter_RemoteGetSpecification_Proxy( 
    IViewChapter __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IViewChapter_RemoteGetSpecification_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewChapter_RemoteOpenViewChapter_Proxy( 
    IViewChapter __RPC_FAR * This,
    /* [in] */ HCHAPTER hSource,
    /* [out] */ HCHAPTER __RPC_FAR *phViewChapter,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IViewChapter_RemoteOpenViewChapter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IViewChapter_INTERFACE_DEFINED__ */


#ifndef __IViewSort_INTERFACE_DEFINED__
#define __IViewSort_INTERFACE_DEFINED__

/* interface IViewSort */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IViewSort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a9a-2a1c-11ce-ade5-00aa0044773d")
    IViewSort : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetSortOrder( 
            /* [out] */ DBORDINAL __RPC_FAR *pcValues,
            /* [out] */ DBORDINAL __RPC_FAR *__RPC_FAR prgColumns[  ],
            /* [out] */ DBSORT __RPC_FAR *__RPC_FAR prgOrders[  ]) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetSortOrder( 
            /* [in] */ DBORDINAL cValues,
            /* [size_is][in] */ const DBORDINAL __RPC_FAR rgColumns[  ],
            /* [size_is][in] */ const DBSORT __RPC_FAR rgOrders[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IViewSortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IViewSort __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IViewSort __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IViewSort __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSortOrder )( 
            IViewSort __RPC_FAR * This,
            /* [out] */ DBORDINAL __RPC_FAR *pcValues,
            /* [out] */ DBORDINAL __RPC_FAR *__RPC_FAR prgColumns[  ],
            /* [out] */ DBSORT __RPC_FAR *__RPC_FAR prgOrders[  ]);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSortOrder )( 
            IViewSort __RPC_FAR * This,
            /* [in] */ DBORDINAL cValues,
            /* [size_is][in] */ const DBORDINAL __RPC_FAR rgColumns[  ],
            /* [size_is][in] */ const DBSORT __RPC_FAR rgOrders[  ]);
        
        END_INTERFACE
    } IViewSortVtbl;

    interface IViewSort
    {
        CONST_VTBL struct IViewSortVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewSort_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewSort_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewSort_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewSort_GetSortOrder(This,pcValues,prgColumns,prgOrders)	\
    (This)->lpVtbl -> GetSortOrder(This,pcValues,prgColumns,prgOrders)

#define IViewSort_SetSortOrder(This,cValues,rgColumns,rgOrders)	\
    (This)->lpVtbl -> SetSortOrder(This,cValues,rgColumns,rgOrders)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewSort_RemoteGetSortOrder_Proxy( 
    IViewSort __RPC_FAR * This,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcValues,
    /* [size_is][size_is][out] */ DBORDINAL __RPC_FAR *__RPC_FAR *prgColumns,
    /* [size_is][size_is][out] */ DBORDINAL __RPC_FAR *__RPC_FAR *prgOrders,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IViewSort_RemoteGetSortOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewSort_RemoteSetSortOrder_Proxy( 
    IViewSort __RPC_FAR * This,
    /* [in] */ DBORDINAL cValues,
    /* [size_is][in] */ const DBORDINAL __RPC_FAR *rgColumns,
    /* [size_is][in] */ const DBSORT __RPC_FAR *rgOrders,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IViewSort_RemoteSetSortOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IViewSort_INTERFACE_DEFINED__ */


#ifndef __IViewFilter_INTERFACE_DEFINED__
#define __IViewFilter_INTERFACE_DEFINED__

/* interface IViewFilter */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IViewFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a9b-2a1c-11ce-ade5-00aa0044773d")
    IViewFilter : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetFilter( 
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows,
            /* [out] */ DBCOMPAREOP __RPC_FAR *__RPC_FAR pCompareOps[  ],
            /* [out] */ void __RPC_FAR *pCriteriaData) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetFilterBindings( 
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcBindings,
            /* [out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetFilter( 
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBCOUNTITEM cRows,
            /* [in] */ DBCOMPAREOP __RPC_FAR CompareOps[  ],
            /* [in] */ void __RPC_FAR *pCriteriaData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IViewFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IViewFilter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IViewFilter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IViewFilter __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFilter )( 
            IViewFilter __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows,
            /* [out] */ DBCOMPAREOP __RPC_FAR *__RPC_FAR pCompareOps[  ],
            /* [out] */ void __RPC_FAR *pCriteriaData);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFilterBindings )( 
            IViewFilter __RPC_FAR * This,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcBindings,
            /* [out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFilter )( 
            IViewFilter __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBCOUNTITEM cRows,
            /* [in] */ DBCOMPAREOP __RPC_FAR CompareOps[  ],
            /* [in] */ void __RPC_FAR *pCriteriaData);
        
        END_INTERFACE
    } IViewFilterVtbl;

    interface IViewFilter
    {
        CONST_VTBL struct IViewFilterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewFilter_GetFilter(This,hAccessor,pcRows,pCompareOps,pCriteriaData)	\
    (This)->lpVtbl -> GetFilter(This,hAccessor,pcRows,pCompareOps,pCriteriaData)

#define IViewFilter_GetFilterBindings(This,pcBindings,prgBindings)	\
    (This)->lpVtbl -> GetFilterBindings(This,pcBindings,prgBindings)

#define IViewFilter_SetFilter(This,hAccessor,cRows,CompareOps,pCriteriaData)	\
    (This)->lpVtbl -> SetFilter(This,hAccessor,cRows,CompareOps,pCriteriaData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [local] */ HRESULT STDMETHODCALLTYPE IViewFilter_GetFilter_Proxy( 
    IViewFilter __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows,
    /* [out] */ DBCOMPAREOP __RPC_FAR *__RPC_FAR pCompareOps[  ],
    /* [out] */ void __RPC_FAR *pCriteriaData);


void __RPC_STUB IViewFilter_GetFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewFilter_RemoteGetFilterBindings_Proxy( 
    IViewFilter __RPC_FAR * This,
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcBindings,
    /* [size_is][size_is][out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IViewFilter_RemoteGetFilterBindings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IViewFilter_SetFilter_Proxy( 
    IViewFilter __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [in] */ DBCOUNTITEM cRows,
    /* [in] */ DBCOMPAREOP __RPC_FAR CompareOps[  ],
    /* [in] */ void __RPC_FAR *pCriteriaData);


void __RPC_STUB IViewFilter_SetFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IViewFilter_INTERFACE_DEFINED__ */


#ifndef __IRowsetView_INTERFACE_DEFINED__
#define __IRowsetView_INTERFACE_DEFINED__

/* interface IRowsetView */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRowsetView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a99-2a1c-11ce-ade5-00aa0044773d")
    IRowsetView : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateView( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetView( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ REFIID riid,
            /* [out] */ HCHAPTER __RPC_FAR *phChapterSource,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetView __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetView __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateView )( 
            IRowsetView __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetView )( 
            IRowsetView __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ REFIID riid,
            /* [out] */ HCHAPTER __RPC_FAR *phChapterSource,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView);
        
        END_INTERFACE
    } IRowsetViewVtbl;

    interface IRowsetView
    {
        CONST_VTBL struct IRowsetViewVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetView_CreateView(This,pUnkOuter,riid,ppView)	\
    (This)->lpVtbl -> CreateView(This,pUnkOuter,riid,ppView)

#define IRowsetView_GetView(This,hChapter,riid,phChapterSource,ppView)	\
    (This)->lpVtbl -> GetView(This,hChapter,riid,phChapterSource,ppView)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetView_RemoteCreateView_Proxy( 
    IRowsetView __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowsetView_RemoteCreateView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetView_RemoteGetView_Proxy( 
    IRowsetView __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ REFIID riid,
    /* [out] */ HCHAPTER __RPC_FAR *phChapterSource,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowsetView_RemoteGetView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetView_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oledb_0272 */
/* [local] */ 

#endif // OLEDBVER >= 0x0150
//@@@- V1.5
//@@@+ deprecated
#ifdef deprecated


extern RPC_IF_HANDLE __MIDL_itf_oledb_0272_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0272_v0_0_s_ifspec;

#ifndef __IRowsetExactScroll_INTERFACE_DEFINED__
#define __IRowsetExactScroll_INTERFACE_DEFINED__

/* interface IRowsetExactScroll */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowsetExactScroll;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a7f-2a1c-11ce-ade5-00aa0044773d")
    IRowsetExactScroll : public IRowsetScroll
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetExactPosition( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pulPosition,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetExactScrollVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetExactScroll __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetExactScroll __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRefRows )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetData )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextRows )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseRows )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][in] */ DBROWOPTIONS __RPC_FAR rgRowOptions[  ],
            /* [size_is][out] */ DBREFCOUNT __RPC_FAR rgRefCounts[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RestartPosition )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Compare )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cbBookmark1,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark1,
            /* [in] */ DBBKMARK cbBookmark2,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark2,
            /* [out] */ DBCOMPARE __RPC_FAR *pComparison);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowsAt )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HWATCHREGION hReserved1,
            /* [in] */ HCHAPTER hReserved2,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [in] */ DBROWOFFSET lRowsOffset,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowsByBookmark )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
            /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
            /* [size_is][out] */ HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hash )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cBookmarks,
            /* [size_is][in] */ const DBBKMARK __RPC_FAR rgcbBookmarks[  ],
            /* [size_is][in] */ const BYTE __RPC_FAR *__RPC_FAR rgpBookmarks[  ],
            /* [size_is][out] */ DBHASHVALUE __RPC_FAR rgHashedValues[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgBookmarkStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetApproximatePosition )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pulPosition,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowsAtRatio )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HWATCHREGION hReserved1,
            /* [in] */ HCHAPTER hReserved2,
            /* [in] */ DBCOUNTITEM ulNumerator,
            /* [in] */ DBCOUNTITEM ulDenominator,
            /* [in] */ DBROWCOUNT cRows,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsObtained,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prghRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExactPosition )( 
            IRowsetExactScroll __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBBKMARK cbBookmark,
            /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pulPosition,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows);
        
        END_INTERFACE
    } IRowsetExactScrollVtbl;

    interface IRowsetExactScroll
    {
        CONST_VTBL struct IRowsetExactScrollVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetExactScroll_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetExactScroll_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetExactScroll_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetExactScroll_AddRefRows(This,cRows,rghRows,rgRefCounts,rgRowStatus)	\
    (This)->lpVtbl -> AddRefRows(This,cRows,rghRows,rgRefCounts,rgRowStatus)

#define IRowsetExactScroll_GetData(This,hRow,hAccessor,pData)	\
    (This)->lpVtbl -> GetData(This,hRow,hAccessor,pData)

#define IRowsetExactScroll_GetNextRows(This,hReserved,lRowsOffset,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> GetNextRows(This,hReserved,lRowsOffset,cRows,pcRowsObtained,prghRows)

#define IRowsetExactScroll_ReleaseRows(This,cRows,rghRows,rgRowOptions,rgRefCounts,rgRowStatus)	\
    (This)->lpVtbl -> ReleaseRows(This,cRows,rghRows,rgRowOptions,rgRefCounts,rgRowStatus)

#define IRowsetExactScroll_RestartPosition(This,hReserved)	\
    (This)->lpVtbl -> RestartPosition(This,hReserved)


#define IRowsetExactScroll_Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)	\
    (This)->lpVtbl -> Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)

#define IRowsetExactScroll_GetRowsAt(This,hReserved1,hReserved2,cbBookmark,pBookmark,lRowsOffset,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> GetRowsAt(This,hReserved1,hReserved2,cbBookmark,pBookmark,lRowsOffset,cRows,pcRowsObtained,prghRows)

#define IRowsetExactScroll_GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)	\
    (This)->lpVtbl -> GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)

#define IRowsetExactScroll_Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)	\
    (This)->lpVtbl -> Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)


#define IRowsetExactScroll_GetApproximatePosition(This,hReserved,cbBookmark,pBookmark,pulPosition,pcRows)	\
    (This)->lpVtbl -> GetApproximatePosition(This,hReserved,cbBookmark,pBookmark,pulPosition,pcRows)

#define IRowsetExactScroll_GetRowsAtRatio(This,hReserved1,hReserved2,ulNumerator,ulDenominator,cRows,pcRowsObtained,prghRows)	\
    (This)->lpVtbl -> GetRowsAtRatio(This,hReserved1,hReserved2,ulNumerator,ulDenominator,cRows,pcRowsObtained,prghRows)


#define IRowsetExactScroll_GetExactPosition(This,hChapter,cbBookmark,pBookmark,pulPosition,pcRows)	\
    (This)->lpVtbl -> GetExactPosition(This,hChapter,cbBookmark,pBookmark,pulPosition,pcRows)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetExactScroll_GetExactPosition_Proxy( 
    IRowsetExactScroll __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBBKMARK cbBookmark,
    /* [size_is][in] */ const BYTE __RPC_FAR *pBookmark,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pulPosition,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pcRows);


void __RPC_STUB IRowsetExactScroll_GetExactPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetExactScroll_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oledb_0273 */
/* [local] */ 

#endif // deprecated
//@@@- deprecated


extern RPC_IF_HANDLE __MIDL_itf_oledb_0273_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0273_v0_0_s_ifspec;

#ifndef __IRowsetChange_INTERFACE_DEFINED__
#define __IRowsetChange_INTERFACE_DEFINED__

/* interface IRowsetChange */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowsetChange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a05-2a1c-11ce-ade5-00aa0044773d")
    IRowsetChange : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DeleteRows( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetData( 
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ void __RPC_FAR *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertRow( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ void __RPC_FAR *pData,
            /* [out] */ HROW __RPC_FAR *phRow) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetChangeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetChange __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetChange __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetChange __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteRows )( 
            IRowsetChange __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetData )( 
            IRowsetChange __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ void __RPC_FAR *pData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertRow )( 
            IRowsetChange __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ void __RPC_FAR *pData,
            /* [out] */ HROW __RPC_FAR *phRow);
        
        END_INTERFACE
    } IRowsetChangeVtbl;

    interface IRowsetChange
    {
        CONST_VTBL struct IRowsetChangeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetChange_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetChange_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetChange_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetChange_DeleteRows(This,hReserved,cRows,rghRows,rgRowStatus)	\
    (This)->lpVtbl -> DeleteRows(This,hReserved,cRows,rghRows,rgRowStatus)

#define IRowsetChange_SetData(This,hRow,hAccessor,pData)	\
    (This)->lpVtbl -> SetData(This,hRow,hAccessor,pData)

#define IRowsetChange_InsertRow(This,hReserved,hAccessor,pData,phRow)	\
    (This)->lpVtbl -> InsertRow(This,hReserved,hAccessor,pData,phRow)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetChange_DeleteRows_Proxy( 
    IRowsetChange __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
    /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);


void __RPC_STUB IRowsetChange_DeleteRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetChange_SetData_Proxy( 
    IRowsetChange __RPC_FAR * This,
    /* [in] */ HROW hRow,
    /* [in] */ HACCESSOR hAccessor,
    /* [in] */ void __RPC_FAR *pData);


void __RPC_STUB IRowsetChange_SetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetChange_InsertRow_Proxy( 
    IRowsetChange __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ HACCESSOR hAccessor,
    /* [in] */ void __RPC_FAR *pData,
    /* [out] */ HROW __RPC_FAR *phRow);


void __RPC_STUB IRowsetChange_InsertRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetChange_INTERFACE_DEFINED__ */


#ifndef __IRowsetUpdate_INTERFACE_DEFINED__
#define __IRowsetUpdate_INTERFACE_DEFINED__

/* interface IRowsetUpdate */
/* [unique][uuid][object][local] */ 

typedef DWORD DBPENDINGSTATUS;


enum DBPENDINGSTATUSENUM
    {	DBPENDINGSTATUS_NEW	= 0x1,
	DBPENDINGSTATUS_CHANGED	= 0x2,
	DBPENDINGSTATUS_DELETED	= 0x4,
	DBPENDINGSTATUS_UNCHANGED	= 0x8,
	DBPENDINGSTATUS_INVALIDROW	= 0x10
    };

EXTERN_C const IID IID_IRowsetUpdate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a6d-2a1c-11ce-ade5-00aa0044773d")
    IRowsetUpdate : public IRowsetChange
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetOriginalData( 
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPendingRows( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBPENDINGSTATUS dwRowStatus,
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcPendingRows,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prgPendingRows,
            /* [size_is][size_is][out] */ DBPENDINGSTATUS __RPC_FAR *__RPC_FAR *prgPendingStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRowStatus( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBPENDINGSTATUS __RPC_FAR rgPendingStatus[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Undo( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcRowsUndone,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prgRowsUndone,
            /* [size_is][size_is][out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Update( 
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcRows,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prgRows,
            /* [size_is][size_is][out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetUpdateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetUpdate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetUpdate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetUpdate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteRows )( 
            IRowsetUpdate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBROWSTATUS __RPC_FAR rgRowStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetData )( 
            IRowsetUpdate __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ void __RPC_FAR *pData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertRow )( 
            IRowsetUpdate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ void __RPC_FAR *pData,
            /* [out] */ HROW __RPC_FAR *phRow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOriginalData )( 
            IRowsetUpdate __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPendingRows )( 
            IRowsetUpdate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBPENDINGSTATUS dwRowStatus,
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcPendingRows,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prgPendingRows,
            /* [size_is][size_is][out] */ DBPENDINGSTATUS __RPC_FAR *__RPC_FAR *prgPendingStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowStatus )( 
            IRowsetUpdate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [size_is][out] */ DBPENDINGSTATUS __RPC_FAR rgPendingStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Undo )( 
            IRowsetUpdate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcRowsUndone,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prgRowsUndone,
            /* [size_is][size_is][out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Update )( 
            IRowsetUpdate __RPC_FAR * This,
            /* [in] */ HCHAPTER hReserved,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcRows,
            /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prgRows,
            /* [size_is][size_is][out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus);
        
        END_INTERFACE
    } IRowsetUpdateVtbl;

    interface IRowsetUpdate
    {
        CONST_VTBL struct IRowsetUpdateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetUpdate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetUpdate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetUpdate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetUpdate_DeleteRows(This,hReserved,cRows,rghRows,rgRowStatus)	\
    (This)->lpVtbl -> DeleteRows(This,hReserved,cRows,rghRows,rgRowStatus)

#define IRowsetUpdate_SetData(This,hRow,hAccessor,pData)	\
    (This)->lpVtbl -> SetData(This,hRow,hAccessor,pData)

#define IRowsetUpdate_InsertRow(This,hReserved,hAccessor,pData,phRow)	\
    (This)->lpVtbl -> InsertRow(This,hReserved,hAccessor,pData,phRow)


#define IRowsetUpdate_GetOriginalData(This,hRow,hAccessor,pData)	\
    (This)->lpVtbl -> GetOriginalData(This,hRow,hAccessor,pData)

#define IRowsetUpdate_GetPendingRows(This,hReserved,dwRowStatus,pcPendingRows,prgPendingRows,prgPendingStatus)	\
    (This)->lpVtbl -> GetPendingRows(This,hReserved,dwRowStatus,pcPendingRows,prgPendingRows,prgPendingStatus)

#define IRowsetUpdate_GetRowStatus(This,hReserved,cRows,rghRows,rgPendingStatus)	\
    (This)->lpVtbl -> GetRowStatus(This,hReserved,cRows,rghRows,rgPendingStatus)

#define IRowsetUpdate_Undo(This,hReserved,cRows,rghRows,pcRowsUndone,prgRowsUndone,prgRowStatus)	\
    (This)->lpVtbl -> Undo(This,hReserved,cRows,rghRows,pcRowsUndone,prgRowsUndone,prgRowStatus)

#define IRowsetUpdate_Update(This,hReserved,cRows,rghRows,pcRows,prgRows,prgRowStatus)	\
    (This)->lpVtbl -> Update(This,hReserved,cRows,rghRows,pcRows,prgRows,prgRowStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetUpdate_GetOriginalData_Proxy( 
    IRowsetUpdate __RPC_FAR * This,
    /* [in] */ HROW hRow,
    /* [in] */ HACCESSOR hAccessor,
    /* [out] */ void __RPC_FAR *pData);


void __RPC_STUB IRowsetUpdate_GetOriginalData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetUpdate_GetPendingRows_Proxy( 
    IRowsetUpdate __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBPENDINGSTATUS dwRowStatus,
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcPendingRows,
    /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prgPendingRows,
    /* [size_is][size_is][out] */ DBPENDINGSTATUS __RPC_FAR *__RPC_FAR *prgPendingStatus);


void __RPC_STUB IRowsetUpdate_GetPendingRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetUpdate_GetRowStatus_Proxy( 
    IRowsetUpdate __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
    /* [size_is][out] */ DBPENDINGSTATUS __RPC_FAR rgPendingStatus[  ]);


void __RPC_STUB IRowsetUpdate_GetRowStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetUpdate_Undo_Proxy( 
    IRowsetUpdate __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcRowsUndone,
    /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prgRowsUndone,
    /* [size_is][size_is][out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus);


void __RPC_STUB IRowsetUpdate_Undo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetUpdate_Update_Proxy( 
    IRowsetUpdate __RPC_FAR * This,
    /* [in] */ HCHAPTER hReserved,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcRows,
    /* [size_is][size_is][out] */ HROW __RPC_FAR *__RPC_FAR *prgRows,
    /* [size_is][size_is][out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus);


void __RPC_STUB IRowsetUpdate_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetUpdate_INTERFACE_DEFINED__ */


#ifndef __IRowsetIdentity_INTERFACE_DEFINED__
#define __IRowsetIdentity_INTERFACE_DEFINED__

/* interface IRowsetIdentity */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRowsetIdentity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a09-2a1c-11ce-ade5-00aa0044773d")
    IRowsetIdentity : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsSameRow( 
            /* [in] */ HROW hThisRow,
            /* [in] */ HROW hThatRow) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetIdentityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetIdentity __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetIdentity __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetIdentity __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsSameRow )( 
            IRowsetIdentity __RPC_FAR * This,
            /* [in] */ HROW hThisRow,
            /* [in] */ HROW hThatRow);
        
        END_INTERFACE
    } IRowsetIdentityVtbl;

    interface IRowsetIdentity
    {
        CONST_VTBL struct IRowsetIdentityVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetIdentity_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetIdentity_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetIdentity_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetIdentity_IsSameRow(This,hThisRow,hThatRow)	\
    (This)->lpVtbl -> IsSameRow(This,hThisRow,hThatRow)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetIdentity_RemoteIsSameRow_Proxy( 
    IRowsetIdentity __RPC_FAR * This,
    /* [in] */ HROW hThisRow,
    /* [in] */ HROW hThatRow,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IRowsetIdentity_RemoteIsSameRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetIdentity_INTERFACE_DEFINED__ */


#ifndef __IRowsetNotify_INTERFACE_DEFINED__
#define __IRowsetNotify_INTERFACE_DEFINED__

/* interface IRowsetNotify */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRowsetNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a83-2a1c-11ce-ade5-00aa0044773d")
    IRowsetNotify : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OnFieldChange( 
            /* [in] */ IRowset __RPC_FAR *pRowset,
            /* [in] */ HROW hRow,
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][in] */ DBORDINAL __RPC_FAR rgColumns[  ],
            /* [in] */ DBREASON eReason,
            /* [in] */ DBEVENTPHASE ePhase,
            /* [in] */ BOOL fCantDeny) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OnRowChange( 
            /* [in] */ IRowset __RPC_FAR *pRowset,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [in] */ DBREASON eReason,
            /* [in] */ DBEVENTPHASE ePhase,
            /* [in] */ BOOL fCantDeny) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OnRowsetChange( 
            /* [in] */ IRowset __RPC_FAR *pRowset,
            /* [in] */ DBREASON eReason,
            /* [in] */ DBEVENTPHASE ePhase,
            /* [in] */ BOOL fCantDeny) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetNotify __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetNotify __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetNotify __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnFieldChange )( 
            IRowsetNotify __RPC_FAR * This,
            /* [in] */ IRowset __RPC_FAR *pRowset,
            /* [in] */ HROW hRow,
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][in] */ DBORDINAL __RPC_FAR rgColumns[  ],
            /* [in] */ DBREASON eReason,
            /* [in] */ DBEVENTPHASE ePhase,
            /* [in] */ BOOL fCantDeny);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRowChange )( 
            IRowsetNotify __RPC_FAR * This,
            /* [in] */ IRowset __RPC_FAR *pRowset,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
            /* [in] */ DBREASON eReason,
            /* [in] */ DBEVENTPHASE ePhase,
            /* [in] */ BOOL fCantDeny);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRowsetChange )( 
            IRowsetNotify __RPC_FAR * This,
            /* [in] */ IRowset __RPC_FAR *pRowset,
            /* [in] */ DBREASON eReason,
            /* [in] */ DBEVENTPHASE ePhase,
            /* [in] */ BOOL fCantDeny);
        
        END_INTERFACE
    } IRowsetNotifyVtbl;

    interface IRowsetNotify
    {
        CONST_VTBL struct IRowsetNotifyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetNotify_OnFieldChange(This,pRowset,hRow,cColumns,rgColumns,eReason,ePhase,fCantDeny)	\
    (This)->lpVtbl -> OnFieldChange(This,pRowset,hRow,cColumns,rgColumns,eReason,ePhase,fCantDeny)

#define IRowsetNotify_OnRowChange(This,pRowset,cRows,rghRows,eReason,ePhase,fCantDeny)	\
    (This)->lpVtbl -> OnRowChange(This,pRowset,cRows,rghRows,eReason,ePhase,fCantDeny)

#define IRowsetNotify_OnRowsetChange(This,pRowset,eReason,ePhase,fCantDeny)	\
    (This)->lpVtbl -> OnRowsetChange(This,pRowset,eReason,ePhase,fCantDeny)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetNotify_RemoteOnFieldChange_Proxy( 
    IRowsetNotify __RPC_FAR * This,
    /* [in] */ IRowset __RPC_FAR *pRowset,
    /* [in] */ HROW hRow,
    /* [in] */ DBORDINAL cColumns,
    /* [size_is][in] */ DBORDINAL __RPC_FAR *rgColumns,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);


void __RPC_STUB IRowsetNotify_RemoteOnFieldChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetNotify_RemoteOnRowChange_Proxy( 
    IRowsetNotify __RPC_FAR * This,
    /* [in] */ IRowset __RPC_FAR *pRowset,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR *rghRows,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);


void __RPC_STUB IRowsetNotify_RemoteOnRowChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetNotify_RemoteOnRowsetChange_Proxy( 
    IRowsetNotify __RPC_FAR * This,
    /* [in] */ IRowset __RPC_FAR *pRowset,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);


void __RPC_STUB IRowsetNotify_RemoteOnRowsetChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetNotify_INTERFACE_DEFINED__ */


#ifndef __IRowsetIndex_INTERFACE_DEFINED__
#define __IRowsetIndex_INTERFACE_DEFINED__

/* interface IRowsetIndex */
/* [unique][uuid][object][local] */ 

typedef DWORD DBSEEK;


enum DBSEEKENUM
    {	DBSEEK_INVALID	= 0,
	DBSEEK_FIRSTEQ	= 0x1,
	DBSEEK_LASTEQ	= 0x2,
	DBSEEK_AFTEREQ	= 0x4,
	DBSEEK_AFTER	= 0x8,
	DBSEEK_BEFOREEQ	= 0x10,
	DBSEEK_BEFORE	= 0x20
    };
#define	DBSEEK_GE	DBSEEK_AFTEREQ
#define	DBSEEK_GT	DBSEEK_AFTER
#define	DBSEEK_LE	DBSEEK_BEFOREEQ
#define	DBSEEK_LT	DBSEEK_BEFORE
typedef DWORD DBRANGE;


enum DBRANGEENUM
    {	DBRANGE_INCLUSIVESTART	= 0,
	DBRANGE_INCLUSIVEEND	= 0,
	DBRANGE_EXCLUSIVESTART	= 0x1,
	DBRANGE_EXCLUSIVEEND	= 0x2,
	DBRANGE_EXCLUDENULLS	= 0x4,
	DBRANGE_PREFIX	= 0x8,
	DBRANGE_MATCH	= 0x10
    };
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBRANGEENUM20
    {	DBRANGE_MATCH_N_SHIFT	= 0x18,
	DBRANGE_MATCH_N_MASK	= 0xff
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0

EXTERN_C const IID IID_IRowsetIndex;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a82-2a1c-11ce-ade5-00aa0044773d")
    IRowsetIndex : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetIndexInfo( 
            /* [out][in] */ DBORDINAL __RPC_FAR *pcKeyColumns,
            /* [size_is][size_is][out] */ DBINDEXCOLUMNDESC __RPC_FAR *__RPC_FAR *prgIndexColumnDesc,
            /* [out][in] */ ULONG __RPC_FAR *pcIndexProperties,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgIndexProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Seek( 
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBORDINAL cKeyValues,
            /* [in] */ void __RPC_FAR *pData,
            /* [in] */ DBSEEK dwSeekOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRange( 
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBORDINAL cStartKeyColumns,
            /* [in] */ void __RPC_FAR *pStartData,
            /* [in] */ DBORDINAL cEndKeyColumns,
            /* [in] */ void __RPC_FAR *pEndData,
            /* [in] */ DBRANGE dwRangeOptions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetIndexVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetIndex __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetIndex __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetIndex __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIndexInfo )( 
            IRowsetIndex __RPC_FAR * This,
            /* [out][in] */ DBORDINAL __RPC_FAR *pcKeyColumns,
            /* [size_is][size_is][out] */ DBINDEXCOLUMNDESC __RPC_FAR *__RPC_FAR *prgIndexColumnDesc,
            /* [out][in] */ ULONG __RPC_FAR *pcIndexProperties,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgIndexProperties);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Seek )( 
            IRowsetIndex __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBORDINAL cKeyValues,
            /* [in] */ void __RPC_FAR *pData,
            /* [in] */ DBSEEK dwSeekOptions);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRange )( 
            IRowsetIndex __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBORDINAL cStartKeyColumns,
            /* [in] */ void __RPC_FAR *pStartData,
            /* [in] */ DBORDINAL cEndKeyColumns,
            /* [in] */ void __RPC_FAR *pEndData,
            /* [in] */ DBRANGE dwRangeOptions);
        
        END_INTERFACE
    } IRowsetIndexVtbl;

    interface IRowsetIndex
    {
        CONST_VTBL struct IRowsetIndexVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetIndex_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetIndex_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetIndex_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetIndex_GetIndexInfo(This,pcKeyColumns,prgIndexColumnDesc,pcIndexProperties,prgIndexProperties)	\
    (This)->lpVtbl -> GetIndexInfo(This,pcKeyColumns,prgIndexColumnDesc,pcIndexProperties,prgIndexProperties)

#define IRowsetIndex_Seek(This,hAccessor,cKeyValues,pData,dwSeekOptions)	\
    (This)->lpVtbl -> Seek(This,hAccessor,cKeyValues,pData,dwSeekOptions)

#define IRowsetIndex_SetRange(This,hAccessor,cStartKeyColumns,pStartData,cEndKeyColumns,pEndData,dwRangeOptions)	\
    (This)->lpVtbl -> SetRange(This,hAccessor,cStartKeyColumns,pStartData,cEndKeyColumns,pEndData,dwRangeOptions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetIndex_GetIndexInfo_Proxy( 
    IRowsetIndex __RPC_FAR * This,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcKeyColumns,
    /* [size_is][size_is][out] */ DBINDEXCOLUMNDESC __RPC_FAR *__RPC_FAR *prgIndexColumnDesc,
    /* [out][in] */ ULONG __RPC_FAR *pcIndexProperties,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgIndexProperties);


void __RPC_STUB IRowsetIndex_GetIndexInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetIndex_Seek_Proxy( 
    IRowsetIndex __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [in] */ DBORDINAL cKeyValues,
    /* [in] */ void __RPC_FAR *pData,
    /* [in] */ DBSEEK dwSeekOptions);


void __RPC_STUB IRowsetIndex_Seek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetIndex_SetRange_Proxy( 
    IRowsetIndex __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [in] */ DBORDINAL cStartKeyColumns,
    /* [in] */ void __RPC_FAR *pStartData,
    /* [in] */ DBORDINAL cEndKeyColumns,
    /* [in] */ void __RPC_FAR *pEndData,
    /* [in] */ DBRANGE dwRangeOptions);


void __RPC_STUB IRowsetIndex_SetRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetIndex_INTERFACE_DEFINED__ */


#ifndef __ICommand_INTERFACE_DEFINED__
#define __ICommand_INTERFACE_DEFINED__

/* interface ICommand */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ICommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a63-2a1c-11ce-ade5-00aa0044773d")
    ICommand : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [out][in] */ DBPARAMS __RPC_FAR *pParams,
            /* [out] */ DBROWCOUNT __RPC_FAR *pcRowsAffected,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetDBSession( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICommand __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICommand __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Cancel )( 
            ICommand __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Execute )( 
            ICommand __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [out][in] */ DBPARAMS __RPC_FAR *pParams,
            /* [out] */ DBROWCOUNT __RPC_FAR *pcRowsAffected,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDBSession )( 
            ICommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession);
        
        END_INTERFACE
    } ICommandVtbl;

    interface ICommand
    {
        CONST_VTBL struct ICommandVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICommand_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#define ICommand_Execute(This,pUnkOuter,riid,pParams,pcRowsAffected,ppRowset)	\
    (This)->lpVtbl -> Execute(This,pUnkOuter,riid,pParams,pcRowsAffected,ppRowset)

#define ICommand_GetDBSession(This,riid,ppSession)	\
    (This)->lpVtbl -> GetDBSession(This,riid,ppSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommand_RemoteCancel_Proxy( 
    ICommand __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommand_RemoteCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommand_RemoteExecute_Proxy( 
    ICommand __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [in] */ HACCESSOR hAccessor,
    /* [in] */ ULONG cParamSets,
    /* [unique][in] */ GUID __RPC_FAR *pGuid,
    /* [in] */ ULONG ulGuidOffset,
    /* [unique][in] */ RMTPACK __RPC_FAR *pInputParams,
    /* [unique][out][in] */ RMTPACK __RPC_FAR *pOutputParams,
    /* [in] */ ULONG cBindings,
    /* [size_is][unique][in] */ DBBINDING __RPC_FAR *rgBindings,
    /* [size_is][unique][out][in] */ DBSTATUS __RPC_FAR *rgStatus,
    /* [unique][out][in] */ LONG __RPC_FAR *pcRowsAffected,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


void __RPC_STUB ICommand_RemoteExecute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommand_RemoteGetDBSession_Proxy( 
    ICommand __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommand_RemoteGetDBSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICommand_INTERFACE_DEFINED__ */


#ifndef __IMultipleResults_INTERFACE_DEFINED__
#define __IMultipleResults_INTERFACE_DEFINED__

/* interface IMultipleResults */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IMultipleResults;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a90-2a1c-11ce-ade5-00aa0044773d")
    IMultipleResults : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetResult( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DB_LRESERVE reserved,
            /* [in] */ REFIID riid,
            /* [out] */ DBROWCOUNT __RPC_FAR *pcRowsAffected,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMultipleResultsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMultipleResults __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMultipleResults __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMultipleResults __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResult )( 
            IMultipleResults __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DB_LRESERVE reserved,
            /* [in] */ REFIID riid,
            /* [out] */ DBROWCOUNT __RPC_FAR *pcRowsAffected,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        END_INTERFACE
    } IMultipleResultsVtbl;

    interface IMultipleResults
    {
        CONST_VTBL struct IMultipleResultsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMultipleResults_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMultipleResults_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMultipleResults_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMultipleResults_GetResult(This,pUnkOuter,reserved,riid,pcRowsAffected,ppRowset)	\
    (This)->lpVtbl -> GetResult(This,pUnkOuter,reserved,riid,pcRowsAffected,ppRowset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IMultipleResults_RemoteGetResult_Proxy( 
    IMultipleResults __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DB_LRESERVE reserved,
    /* [in] */ REFIID riid,
    /* [unique][out][in] */ DBROWCOUNT __RPC_FAR *pcRowsAffected,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IMultipleResults_RemoteGetResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMultipleResults_INTERFACE_DEFINED__ */


#ifndef __IConvertType_INTERFACE_DEFINED__
#define __IConvertType_INTERFACE_DEFINED__

/* interface IConvertType */
/* [unique][uuid][object] */ 

typedef DWORD DBCONVERTFLAGS;


enum DBCONVERTFLAGSENUM
    {	DBCONVERTFLAGS_COLUMN	= 0,
	DBCONVERTFLAGS_PARAMETER	= 0x1
    };
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBCONVERTFLAGSENUM20
    {	DBCONVERTFLAGS_ISLONG	= 0x2,
	DBCONVERTFLAGS_ISFIXEDLENGTH	= 0x4,
	DBCONVERTFLAGS_FROMVARIANT	= 0x8
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0

EXTERN_C const IID IID_IConvertType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a88-2a1c-11ce-ade5-00aa0044773d")
    IConvertType : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CanConvert( 
            /* [in] */ DBTYPE wFromType,
            /* [in] */ DBTYPE wToType,
            /* [in] */ DBCONVERTFLAGS dwConvertFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConvertTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IConvertType __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IConvertType __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IConvertType __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanConvert )( 
            IConvertType __RPC_FAR * This,
            /* [in] */ DBTYPE wFromType,
            /* [in] */ DBTYPE wToType,
            /* [in] */ DBCONVERTFLAGS dwConvertFlags);
        
        END_INTERFACE
    } IConvertTypeVtbl;

    interface IConvertType
    {
        CONST_VTBL struct IConvertTypeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConvertType_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConvertType_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConvertType_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConvertType_CanConvert(This,wFromType,wToType,dwConvertFlags)	\
    (This)->lpVtbl -> CanConvert(This,wFromType,wToType,dwConvertFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IConvertType_RemoteCanConvert_Proxy( 
    IConvertType __RPC_FAR * This,
    /* [in] */ DBTYPE wFromType,
    /* [in] */ DBTYPE wToType,
    /* [in] */ DBCONVERTFLAGS dwConvertFlags,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IConvertType_RemoteCanConvert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IConvertType_INTERFACE_DEFINED__ */


#ifndef __ICommandPrepare_INTERFACE_DEFINED__
#define __ICommandPrepare_INTERFACE_DEFINED__

/* interface ICommandPrepare */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ICommandPrepare;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a26-2a1c-11ce-ade5-00aa0044773d")
    ICommandPrepare : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Prepare( 
            /* [in] */ ULONG cExpectedRuns) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Unprepare( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICommandPrepareVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICommandPrepare __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICommandPrepare __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICommandPrepare __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Prepare )( 
            ICommandPrepare __RPC_FAR * This,
            /* [in] */ ULONG cExpectedRuns);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unprepare )( 
            ICommandPrepare __RPC_FAR * This);
        
        END_INTERFACE
    } ICommandPrepareVtbl;

    interface ICommandPrepare
    {
        CONST_VTBL struct ICommandPrepareVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICommandPrepare_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICommandPrepare_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICommandPrepare_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICommandPrepare_Prepare(This,cExpectedRuns)	\
    (This)->lpVtbl -> Prepare(This,cExpectedRuns)

#define ICommandPrepare_Unprepare(This)	\
    (This)->lpVtbl -> Unprepare(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandPrepare_RemotePrepare_Proxy( 
    ICommandPrepare __RPC_FAR * This,
    /* [in] */ ULONG cExpectedRuns,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommandPrepare_RemotePrepare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandPrepare_RemoteUnprepare_Proxy( 
    ICommandPrepare __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommandPrepare_RemoteUnprepare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICommandPrepare_INTERFACE_DEFINED__ */


#ifndef __ICommandProperties_INTERFACE_DEFINED__
#define __ICommandProperties_INTERFACE_DEFINED__

/* interface ICommandProperties */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ICommandProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a79-2a1c-11ce-ade5-00aa0044773d")
    ICommandProperties : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [in] */ const ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetProperties( 
            /* [in] */ ULONG cPropertySets,
            /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICommandPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICommandProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICommandProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICommandProperties __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProperties )( 
            ICommandProperties __RPC_FAR * This,
            /* [in] */ const ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProperties )( 
            ICommandProperties __RPC_FAR * This,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);
        
        END_INTERFACE
    } ICommandPropertiesVtbl;

    interface ICommandProperties
    {
        CONST_VTBL struct ICommandPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICommandProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICommandProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICommandProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICommandProperties_GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)	\
    (This)->lpVtbl -> GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)

#define ICommandProperties_SetProperties(This,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> SetProperties(This,cPropertySets,rgPropertySets)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandProperties_RemoteGetProperties_Proxy( 
    ICommandProperties __RPC_FAR * This,
    /* [in] */ const ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommandProperties_RemoteGetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandProperties_RemoteSetProperties_Proxy( 
    ICommandProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommandProperties_RemoteSetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICommandProperties_INTERFACE_DEFINED__ */


#ifndef __ICommandText_INTERFACE_DEFINED__
#define __ICommandText_INTERFACE_DEFINED__

/* interface ICommandText */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ICommandText;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a27-2a1c-11ce-ade5-00aa0044773d")
    ICommandText : public ICommand
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetCommandText( 
            /* [out][in] */ GUID __RPC_FAR *pguidDialect,
            /* [out] */ LPOLESTR __RPC_FAR *ppwszCommand) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetCommandText( 
            /* [in] */ REFGUID rguidDialect,
            /* [unique][in] */ LPCOLESTR pwszCommand) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICommandTextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICommandText __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICommandText __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICommandText __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Cancel )( 
            ICommandText __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Execute )( 
            ICommandText __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [out][in] */ DBPARAMS __RPC_FAR *pParams,
            /* [out] */ DBROWCOUNT __RPC_FAR *pcRowsAffected,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDBSession )( 
            ICommandText __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommandText )( 
            ICommandText __RPC_FAR * This,
            /* [out][in] */ GUID __RPC_FAR *pguidDialect,
            /* [out] */ LPOLESTR __RPC_FAR *ppwszCommand);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCommandText )( 
            ICommandText __RPC_FAR * This,
            /* [in] */ REFGUID rguidDialect,
            /* [unique][in] */ LPCOLESTR pwszCommand);
        
        END_INTERFACE
    } ICommandTextVtbl;

    interface ICommandText
    {
        CONST_VTBL struct ICommandTextVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICommandText_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICommandText_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICommandText_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICommandText_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#define ICommandText_Execute(This,pUnkOuter,riid,pParams,pcRowsAffected,ppRowset)	\
    (This)->lpVtbl -> Execute(This,pUnkOuter,riid,pParams,pcRowsAffected,ppRowset)

#define ICommandText_GetDBSession(This,riid,ppSession)	\
    (This)->lpVtbl -> GetDBSession(This,riid,ppSession)


#define ICommandText_GetCommandText(This,pguidDialect,ppwszCommand)	\
    (This)->lpVtbl -> GetCommandText(This,pguidDialect,ppwszCommand)

#define ICommandText_SetCommandText(This,rguidDialect,pwszCommand)	\
    (This)->lpVtbl -> SetCommandText(This,rguidDialect,pwszCommand)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandText_RemoteGetCommandText_Proxy( 
    ICommandText __RPC_FAR * This,
    /* [unique][out][in] */ GUID __RPC_FAR *pguidDialect,
    /* [out] */ LPOLESTR __RPC_FAR *ppwszCommand,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommandText_RemoteGetCommandText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandText_RemoteSetCommandText_Proxy( 
    ICommandText __RPC_FAR * This,
    /* [in] */ REFGUID rguidDialect,
    /* [unique][in] */ LPCOLESTR pwszCommand,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommandText_RemoteSetCommandText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICommandText_INTERFACE_DEFINED__ */


#ifndef __ICommandWithParameters_INTERFACE_DEFINED__
#define __ICommandWithParameters_INTERFACE_DEFINED__

/* interface ICommandWithParameters */
/* [unique][uuid][object] */ 

typedef struct tagDBPARAMBINDINFO
    {
    LPOLESTR pwszDataSourceType;
    LPOLESTR pwszName;
    DBLENGTH ulParamSize;
    DBPARAMFLAGS dwFlags;
    BYTE bPrecision;
    BYTE bScale;
    }	DBPARAMBINDINFO;


EXTERN_C const IID IID_ICommandWithParameters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a64-2a1c-11ce-ade5-00aa0044773d")
    ICommandWithParameters : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetParameterInfo( 
            /* [out][in] */ DB_UPARAMS __RPC_FAR *pcParams,
            /* [size_is][size_is][out] */ DBPARAMINFO __RPC_FAR *__RPC_FAR *prgParamInfo,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppNamesBuffer) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE MapParameterNames( 
            /* [in] */ DB_UPARAMS cParamNames,
            /* [size_is][in] */ const OLECHAR __RPC_FAR *__RPC_FAR rgParamNames[  ],
            /* [size_is][out] */ DB_LPARAMS __RPC_FAR rgParamOrdinals[  ]) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetParameterInfo( 
            /* [in] */ DB_UPARAMS cParams,
            /* [size_is][unique][in] */ const DB_UPARAMS __RPC_FAR rgParamOrdinals[  ],
            /* [size_is][unique][in] */ const DBPARAMBINDINFO __RPC_FAR rgParamBindInfo[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICommandWithParametersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICommandWithParameters __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICommandWithParameters __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICommandWithParameters __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameterInfo )( 
            ICommandWithParameters __RPC_FAR * This,
            /* [out][in] */ DB_UPARAMS __RPC_FAR *pcParams,
            /* [size_is][size_is][out] */ DBPARAMINFO __RPC_FAR *__RPC_FAR *prgParamInfo,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppNamesBuffer);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MapParameterNames )( 
            ICommandWithParameters __RPC_FAR * This,
            /* [in] */ DB_UPARAMS cParamNames,
            /* [size_is][in] */ const OLECHAR __RPC_FAR *__RPC_FAR rgParamNames[  ],
            /* [size_is][out] */ DB_LPARAMS __RPC_FAR rgParamOrdinals[  ]);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameterInfo )( 
            ICommandWithParameters __RPC_FAR * This,
            /* [in] */ DB_UPARAMS cParams,
            /* [size_is][unique][in] */ const DB_UPARAMS __RPC_FAR rgParamOrdinals[  ],
            /* [size_is][unique][in] */ const DBPARAMBINDINFO __RPC_FAR rgParamBindInfo[  ]);
        
        END_INTERFACE
    } ICommandWithParametersVtbl;

    interface ICommandWithParameters
    {
        CONST_VTBL struct ICommandWithParametersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICommandWithParameters_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICommandWithParameters_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICommandWithParameters_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICommandWithParameters_GetParameterInfo(This,pcParams,prgParamInfo,ppNamesBuffer)	\
    (This)->lpVtbl -> GetParameterInfo(This,pcParams,prgParamInfo,ppNamesBuffer)

#define ICommandWithParameters_MapParameterNames(This,cParamNames,rgParamNames,rgParamOrdinals)	\
    (This)->lpVtbl -> MapParameterNames(This,cParamNames,rgParamNames,rgParamOrdinals)

#define ICommandWithParameters_SetParameterInfo(This,cParams,rgParamOrdinals,rgParamBindInfo)	\
    (This)->lpVtbl -> SetParameterInfo(This,cParams,rgParamOrdinals,rgParamBindInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandWithParameters_RemoteGetParameterInfo_Proxy( 
    ICommandWithParameters __RPC_FAR * This,
    /* [out][in] */ DB_UPARAMS __RPC_FAR *pcParams,
    /* [size_is][size_is][out] */ DBPARAMINFO __RPC_FAR *__RPC_FAR *prgParamInfo,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgNameOffsets,
    /* [out][in] */ DBLENGTH __RPC_FAR *pcbNamesBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppNamesBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommandWithParameters_RemoteGetParameterInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandWithParameters_RemoteMapParameterNames_Proxy( 
    ICommandWithParameters __RPC_FAR * This,
    /* [in] */ DB_UPARAMS cParamNames,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgParamNames,
    /* [size_is][out] */ DB_LPARAMS __RPC_FAR *rgParamOrdinals,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommandWithParameters_RemoteMapParameterNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandWithParameters_RemoteSetParameterInfo_Proxy( 
    ICommandWithParameters __RPC_FAR * This,
    /* [in] */ DB_UPARAMS cParams,
    /* [size_is][unique][in] */ const DB_UPARAMS __RPC_FAR *rgParamOrdinals,
    /* [size_is][unique][in] */ const DBPARAMBINDINFO __RPC_FAR *rgParamBindInfo,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ICommandWithParameters_RemoteSetParameterInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICommandWithParameters_INTERFACE_DEFINED__ */


#ifndef __IColumnsRowset_INTERFACE_DEFINED__
#define __IColumnsRowset_INTERFACE_DEFINED__

/* interface IColumnsRowset */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IColumnsRowset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a10-2a1c-11ce-ade5-00aa0044773d")
    IColumnsRowset : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetAvailableColumns( 
            /* [out][in] */ DBORDINAL __RPC_FAR *pcOptColumns,
            /* [size_is][size_is][out] */ DBID __RPC_FAR *__RPC_FAR *prgOptColumns) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetColumnsRowset( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBORDINAL cOptColumns,
            /* [size_is][in] */ const DBID __RPC_FAR rgOptColumns[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppColRowset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IColumnsRowsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IColumnsRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IColumnsRowset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IColumnsRowset __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAvailableColumns )( 
            IColumnsRowset __RPC_FAR * This,
            /* [out][in] */ DBORDINAL __RPC_FAR *pcOptColumns,
            /* [size_is][size_is][out] */ DBID __RPC_FAR *__RPC_FAR *prgOptColumns);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColumnsRowset )( 
            IColumnsRowset __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBORDINAL cOptColumns,
            /* [size_is][in] */ const DBID __RPC_FAR rgOptColumns[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppColRowset);
        
        END_INTERFACE
    } IColumnsRowsetVtbl;

    interface IColumnsRowset
    {
        CONST_VTBL struct IColumnsRowsetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IColumnsRowset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IColumnsRowset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IColumnsRowset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IColumnsRowset_GetAvailableColumns(This,pcOptColumns,prgOptColumns)	\
    (This)->lpVtbl -> GetAvailableColumns(This,pcOptColumns,prgOptColumns)

#define IColumnsRowset_GetColumnsRowset(This,pUnkOuter,cOptColumns,rgOptColumns,riid,cPropertySets,rgPropertySets,ppColRowset)	\
    (This)->lpVtbl -> GetColumnsRowset(This,pUnkOuter,cOptColumns,rgOptColumns,riid,cPropertySets,rgPropertySets,ppColRowset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsRowset_RemoteGetAvailableColumns_Proxy( 
    IColumnsRowset __RPC_FAR * This,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcOptColumns,
    /* [size_is][size_is][out] */ DBID __RPC_FAR *__RPC_FAR *prgOptColumns,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IColumnsRowset_RemoteGetAvailableColumns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsRowset_RemoteGetColumnsRowset_Proxy( 
    IColumnsRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DBORDINAL cOptColumns,
    /* [size_is][unique][in] */ const DBID __RPC_FAR *rgOptColumns,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppColRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IColumnsRowset_RemoteGetColumnsRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IColumnsRowset_INTERFACE_DEFINED__ */


#ifndef __IColumnsInfo_INTERFACE_DEFINED__
#define __IColumnsInfo_INTERFACE_DEFINED__

/* interface IColumnsInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IColumnsInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a11-2a1c-11ce-ade5-00aa0044773d")
    IColumnsInfo : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetColumnInfo( 
            /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
            /* [size_is][size_is][out] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgInfo,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE MapColumnIDs( 
            /* [in] */ DBORDINAL cColumnIDs,
            /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDs[  ],
            /* [size_is][out] */ DBORDINAL __RPC_FAR rgColumns[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IColumnsInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IColumnsInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IColumnsInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IColumnsInfo __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColumnInfo )( 
            IColumnsInfo __RPC_FAR * This,
            /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
            /* [size_is][size_is][out] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgInfo,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MapColumnIDs )( 
            IColumnsInfo __RPC_FAR * This,
            /* [in] */ DBORDINAL cColumnIDs,
            /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDs[  ],
            /* [size_is][out] */ DBORDINAL __RPC_FAR rgColumns[  ]);
        
        END_INTERFACE
    } IColumnsInfoVtbl;

    interface IColumnsInfo
    {
        CONST_VTBL struct IColumnsInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IColumnsInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IColumnsInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IColumnsInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IColumnsInfo_GetColumnInfo(This,pcColumns,prgInfo,ppStringsBuffer)	\
    (This)->lpVtbl -> GetColumnInfo(This,pcColumns,prgInfo,ppStringsBuffer)

#define IColumnsInfo_MapColumnIDs(This,cColumnIDs,rgColumnIDs,rgColumns)	\
    (This)->lpVtbl -> MapColumnIDs(This,cColumnIDs,rgColumnIDs,rgColumns)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsInfo_RemoteGetColumnInfo_Proxy( 
    IColumnsInfo __RPC_FAR * This,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
    /* [size_is][size_is][out] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgInfo,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgNameOffsets,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgcolumnidOffsets,
    /* [out][in] */ DBLENGTH __RPC_FAR *pcbStringsBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IColumnsInfo_RemoteGetColumnInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsInfo_RemoteMapColumnIDs_Proxy( 
    IColumnsInfo __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumnIDs,
    /* [size_is][in] */ const DBID __RPC_FAR *rgColumnIDs,
    /* [size_is][out] */ DBORDINAL __RPC_FAR *rgColumns,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IColumnsInfo_RemoteMapColumnIDs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IColumnsInfo_INTERFACE_DEFINED__ */


#ifndef __IDBCreateCommand_INTERFACE_DEFINED__
#define __IDBCreateCommand_INTERFACE_DEFINED__

/* interface IDBCreateCommand */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDBCreateCommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a1d-2a1c-11ce-ade5-00aa0044773d")
    IDBCreateCommand : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateCommand( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppCommand) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBCreateCommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBCreateCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBCreateCommand __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBCreateCommand __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateCommand )( 
            IDBCreateCommand __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppCommand);
        
        END_INTERFACE
    } IDBCreateCommandVtbl;

    interface IDBCreateCommand
    {
        CONST_VTBL struct IDBCreateCommandVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBCreateCommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBCreateCommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBCreateCommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBCreateCommand_CreateCommand(This,pUnkOuter,riid,ppCommand)	\
    (This)->lpVtbl -> CreateCommand(This,pUnkOuter,riid,ppCommand)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBCreateCommand_RemoteCreateCommand_Proxy( 
    IDBCreateCommand __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppCommand,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBCreateCommand_RemoteCreateCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBCreateCommand_INTERFACE_DEFINED__ */


#ifndef __IDBCreateSession_INTERFACE_DEFINED__
#define __IDBCreateSession_INTERFACE_DEFINED__

/* interface IDBCreateSession */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDBCreateSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a5d-2a1c-11ce-ade5-00aa0044773d")
    IDBCreateSession : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateSession( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBCreateSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBCreateSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBCreateSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBCreateSession __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateSession )( 
            IDBCreateSession __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession);
        
        END_INTERFACE
    } IDBCreateSessionVtbl;

    interface IDBCreateSession
    {
        CONST_VTBL struct IDBCreateSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBCreateSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBCreateSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBCreateSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBCreateSession_CreateSession(This,pUnkOuter,riid,ppDBSession)	\
    (This)->lpVtbl -> CreateSession(This,pUnkOuter,riid,ppDBSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBCreateSession_RemoteCreateSession_Proxy( 
    IDBCreateSession __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBCreateSession_RemoteCreateSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBCreateSession_INTERFACE_DEFINED__ */


#ifndef __ISourcesRowset_INTERFACE_DEFINED__
#define __ISourcesRowset_INTERFACE_DEFINED__

/* interface ISourcesRowset */
/* [unique][uuid][object] */ 

typedef DWORD DBSOURCETYPE;


enum DBSOURCETYPEENUM
    {	DBSOURCETYPE_DATASOURCE	= 1,
	DBSOURCETYPE_ENUMERATOR	= 2
    };
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )

enum DBSOURCETYPEENUM20
    {	DBSOURCETYPE_DATASOURCE_TDP	= 1,
	DBSOURCETYPE_DATASOURCE_MDP	= 3
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.5
#if( OLEDBVER >= 0x0250 )

enum DBSOURCETYPEENUM25
    {	DBSOURCETYPE_BINDER	= 4
    };
#endif // OLEDBVER >= 0x0250
//@@@- V2.5

EXTERN_C const IID IID_ISourcesRowset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a1e-2a1c-11ce-ade5-00aa0044773d")
    ISourcesRowset : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetSourcesRowset( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgProperties[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSourcesRowset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISourcesRowsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISourcesRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISourcesRowset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISourcesRowset __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourcesRowset )( 
            ISourcesRowset __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgProperties[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSourcesRowset);
        
        END_INTERFACE
    } ISourcesRowsetVtbl;

    interface ISourcesRowset
    {
        CONST_VTBL struct ISourcesRowsetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISourcesRowset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISourcesRowset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISourcesRowset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISourcesRowset_GetSourcesRowset(This,pUnkOuter,riid,cPropertySets,rgProperties,ppSourcesRowset)	\
    (This)->lpVtbl -> GetSourcesRowset(This,pUnkOuter,riid,cPropertySets,rgProperties,ppSourcesRowset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ISourcesRowset_RemoteGetSourcesRowset_Proxy( 
    ISourcesRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgProperties,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSourcesRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ISourcesRowset_RemoteGetSourcesRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISourcesRowset_INTERFACE_DEFINED__ */


#ifndef __IDBProperties_INTERFACE_DEFINED__
#define __IDBProperties_INTERFACE_DEFINED__

/* interface IDBProperties */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDBProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a8a-2a1c-11ce-ade5-00aa0044773d")
    IDBProperties : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetPropertyInfo( 
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
            /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetProperties( 
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBProperties __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProperties )( 
            IDBProperties __RPC_FAR * This,
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropertyInfo )( 
            IDBProperties __RPC_FAR * This,
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
            /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProperties )( 
            IDBProperties __RPC_FAR * This,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);
        
        END_INTERFACE
    } IDBPropertiesVtbl;

    interface IDBProperties
    {
        CONST_VTBL struct IDBPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBProperties_GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)	\
    (This)->lpVtbl -> GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)

#define IDBProperties_GetPropertyInfo(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)	\
    (This)->lpVtbl -> GetPropertyInfo(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)

#define IDBProperties_SetProperties(This,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> SetProperties(This,cPropertySets,rgPropertySets)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBProperties_RemoteGetProperties_Proxy( 
    IDBProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBProperties_RemoteGetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBProperties_RemoteGetPropertyInfo_Proxy( 
    IDBProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
    /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
    /* [out][in] */ ULONG __RPC_FAR *pcOffsets,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgDescOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbDescBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBProperties_RemoteGetPropertyInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBProperties_RemoteSetProperties_Proxy( 
    IDBProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBProperties_RemoteSetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBProperties_INTERFACE_DEFINED__ */


#ifndef __IDBInitialize_INTERFACE_DEFINED__
#define __IDBInitialize_INTERFACE_DEFINED__

/* interface IDBInitialize */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDBInitialize;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a8b-2a1c-11ce-ade5-00aa0044773d")
    IDBInitialize : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBInitializeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBInitialize __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBInitialize __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBInitialize __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            IDBInitialize __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Uninitialize )( 
            IDBInitialize __RPC_FAR * This);
        
        END_INTERFACE
    } IDBInitializeVtbl;

    interface IDBInitialize
    {
        CONST_VTBL struct IDBInitializeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBInitialize_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBInitialize_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBInitialize_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBInitialize_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define IDBInitialize_Uninitialize(This)	\
    (This)->lpVtbl -> Uninitialize(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBInitialize_RemoteInitialize_Proxy( 
    IDBInitialize __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBInitialize_RemoteInitialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBInitialize_RemoteUninitialize_Proxy( 
    IDBInitialize __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBInitialize_RemoteUninitialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBInitialize_INTERFACE_DEFINED__ */


#ifndef __IDBInfo_INTERFACE_DEFINED__
#define __IDBInfo_INTERFACE_DEFINED__

/* interface IDBInfo */
/* [unique][uuid][object] */ 

typedef DWORD DBLITERAL;


enum DBLITERALENUM
    {	DBLITERAL_INVALID	= 0,
	DBLITERAL_BINARY_LITERAL	= 1,
	DBLITERAL_CATALOG_NAME	= 2,
	DBLITERAL_CATALOG_SEPARATOR	= 3,
	DBLITERAL_CHAR_LITERAL	= 4,
	DBLITERAL_COLUMN_ALIAS	= 5,
	DBLITERAL_COLUMN_NAME	= 6,
	DBLITERAL_CORRELATION_NAME	= 7,
	DBLITERAL_CURSOR_NAME	= 8,
	DBLITERAL_ESCAPE_PERCENT	= 9,
	DBLITERAL_ESCAPE_UNDERSCORE	= 10,
	DBLITERAL_INDEX_NAME	= 11,
	DBLITERAL_LIKE_PERCENT	= 12,
	DBLITERAL_LIKE_UNDERSCORE	= 13,
	DBLITERAL_PROCEDURE_NAME	= 14,
	DBLITERAL_QUOTE	= 15,
	DBLITERAL_SCHEMA_NAME	= 16,
	DBLITERAL_TABLE_NAME	= 17,
	DBLITERAL_TEXT_COMMAND	= 18,
	DBLITERAL_USER_NAME	= 19,
	DBLITERAL_VIEW_NAME	= 20
    };
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
#define DBLITERAL_QUOTE_PREFIX DBLITERAL_QUOTE

enum DBLITERALENUM20
    {	DBLITERAL_CUBE_NAME	= 21,
	DBLITERAL_DIMENSION_NAME	= 22,
	DBLITERAL_HIERARCHY_NAME	= 23,
	DBLITERAL_LEVEL_NAME	= 24,
	DBLITERAL_MEMBER_NAME	= 25,
	DBLITERAL_PROPERTY_NAME	= 26,
	DBLITERAL_SCHEMA_SEPARATOR	= 27,
	DBLITERAL_QUOTE_SUFFIX	= 28
    };
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
#define DBLITERAL_ESCAPE_PERCENT_PREFIX DBLITERAL_ESCAPE_PERCENT
#define DBLITERAL_ESCAPE_UNDERSCORE_PREFIX DBLITERAL_ESCAPE_UNDERSCORE

enum DBLITERALENUM21
    {	DBLITERAL_ESCAPE_PERCENT_SUFFIX	= 29,
	DBLITERAL_ESCAPE_UNDERSCORE_SUFFIX	= 30
    };
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
typedef struct tagDBLITERALINFO
    {
    LPOLESTR pwszLiteralValue;
    LPOLESTR pwszInvalidChars;
    LPOLESTR pwszInvalidStartingChars;
    DBLITERAL lt;
    BOOL fSupported;
    ULONG cchMaxLen;
    }	DBLITERALINFO;


EXTERN_C const IID IID_IDBInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a89-2a1c-11ce-ade5-00aa0044773d")
    IDBInfo : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetKeywords( 
            /* [out] */ LPOLESTR __RPC_FAR *ppwszKeywords) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetLiteralInfo( 
            /* [in] */ ULONG cLiterals,
            /* [size_is][in] */ const DBLITERAL __RPC_FAR rgLiterals[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcLiteralInfo,
            /* [size_is][size_is][out] */ DBLITERALINFO __RPC_FAR *__RPC_FAR *prgLiteralInfo,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppCharBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBInfo __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetKeywords )( 
            IDBInfo __RPC_FAR * This,
            /* [out] */ LPOLESTR __RPC_FAR *ppwszKeywords);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLiteralInfo )( 
            IDBInfo __RPC_FAR * This,
            /* [in] */ ULONG cLiterals,
            /* [size_is][in] */ const DBLITERAL __RPC_FAR rgLiterals[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcLiteralInfo,
            /* [size_is][size_is][out] */ DBLITERALINFO __RPC_FAR *__RPC_FAR *prgLiteralInfo,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppCharBuffer);
        
        END_INTERFACE
    } IDBInfoVtbl;

    interface IDBInfo
    {
        CONST_VTBL struct IDBInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBInfo_GetKeywords(This,ppwszKeywords)	\
    (This)->lpVtbl -> GetKeywords(This,ppwszKeywords)

#define IDBInfo_GetLiteralInfo(This,cLiterals,rgLiterals,pcLiteralInfo,prgLiteralInfo,ppCharBuffer)	\
    (This)->lpVtbl -> GetLiteralInfo(This,cLiterals,rgLiterals,pcLiteralInfo,prgLiteralInfo,ppCharBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBInfo_RemoteGetKeywords_Proxy( 
    IDBInfo __RPC_FAR * This,
    /* [unique][out][in] */ LPOLESTR __RPC_FAR *ppwszKeywords,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBInfo_RemoteGetKeywords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBInfo_RemoteGetLiteralInfo_Proxy( 
    IDBInfo __RPC_FAR * This,
    /* [in] */ ULONG cLiterals,
    /* [size_is][unique][in] */ const DBLITERAL __RPC_FAR *rgLiterals,
    /* [out][in] */ ULONG __RPC_FAR *pcLiteralInfo,
    /* [size_is][size_is][out] */ DBLITERALINFO __RPC_FAR *__RPC_FAR *prgLiteralInfo,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgLVOffsets,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgICOffsets,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgISCOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbCharBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppCharBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBInfo_RemoteGetLiteralInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBInfo_INTERFACE_DEFINED__ */


#ifndef __IDBDataSourceAdmin_INTERFACE_DEFINED__
#define __IDBDataSourceAdmin_INTERFACE_DEFINED__

/* interface IDBDataSourceAdmin */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDBDataSourceAdmin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a7a-2a1c-11ce-ade5-00aa0044773d")
    IDBDataSourceAdmin : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateDataSource( 
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DestroyDataSource( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetCreationProperties( 
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
            /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE ModifyDataSource( 
            /* [in] */ ULONG cPropertySets,
            /* [size_is][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBDataSourceAdminVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBDataSourceAdmin __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBDataSourceAdmin __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBDataSourceAdmin __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateDataSource )( 
            IDBDataSourceAdmin __RPC_FAR * This,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DestroyDataSource )( 
            IDBDataSourceAdmin __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCreationProperties )( 
            IDBDataSourceAdmin __RPC_FAR * This,
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
            /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ModifyDataSource )( 
            IDBDataSourceAdmin __RPC_FAR * This,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);
        
        END_INTERFACE
    } IDBDataSourceAdminVtbl;

    interface IDBDataSourceAdmin
    {
        CONST_VTBL struct IDBDataSourceAdminVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBDataSourceAdmin_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBDataSourceAdmin_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBDataSourceAdmin_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBDataSourceAdmin_CreateDataSource(This,cPropertySets,rgPropertySets,pUnkOuter,riid,ppDBSession)	\
    (This)->lpVtbl -> CreateDataSource(This,cPropertySets,rgPropertySets,pUnkOuter,riid,ppDBSession)

#define IDBDataSourceAdmin_DestroyDataSource(This)	\
    (This)->lpVtbl -> DestroyDataSource(This)

#define IDBDataSourceAdmin_GetCreationProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)	\
    (This)->lpVtbl -> GetCreationProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)

#define IDBDataSourceAdmin_ModifyDataSource(This,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> ModifyDataSource(This,cPropertySets,rgPropertySets)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_RemoteCreateDataSource_Proxy( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBDataSourceAdmin_RemoteCreateDataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_RemoteDestroyDataSource_Proxy( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBDataSourceAdmin_RemoteDestroyDataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_RemoteGetCreationProperties_Proxy( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
    /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
    /* [out][in] */ ULONG __RPC_FAR *pcOffsets,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgDescOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbDescBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBDataSourceAdmin_RemoteGetCreationProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_RemoteModifyDataSource_Proxy( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBDataSourceAdmin_RemoteModifyDataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBDataSourceAdmin_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oledb_0294 */
/* [local] */ 

//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )


extern RPC_IF_HANDLE __MIDL_itf_oledb_0294_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0294_v0_0_s_ifspec;

#ifndef __IDBAsynchNotify_INTERFACE_DEFINED__
#define __IDBAsynchNotify_INTERFACE_DEFINED__

/* interface IDBAsynchNotify */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDBAsynchNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a96-2a1c-11ce-ade5-00aa0044773d")
    IDBAsynchNotify : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OnLowResource( 
            /* [in] */ DB_DWRESERVE dwReserved) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OnProgress( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBASYNCHOP eOperation,
            /* [in] */ DBCOUNTITEM ulProgress,
            /* [in] */ DBCOUNTITEM ulProgressMax,
            /* [in] */ DBASYNCHPHASE eAsynchPhase,
            /* [in] */ LPOLESTR pwszStatusText) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OnStop( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBASYNCHOP eOperation,
            /* [in] */ HRESULT hrStatus,
            /* [in] */ LPOLESTR pwszStatusText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBAsynchNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBAsynchNotify __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBAsynchNotify __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBAsynchNotify __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLowResource )( 
            IDBAsynchNotify __RPC_FAR * This,
            /* [in] */ DB_DWRESERVE dwReserved);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnProgress )( 
            IDBAsynchNotify __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBASYNCHOP eOperation,
            /* [in] */ DBCOUNTITEM ulProgress,
            /* [in] */ DBCOUNTITEM ulProgressMax,
            /* [in] */ DBASYNCHPHASE eAsynchPhase,
            /* [in] */ LPOLESTR pwszStatusText);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnStop )( 
            IDBAsynchNotify __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBASYNCHOP eOperation,
            /* [in] */ HRESULT hrStatus,
            /* [in] */ LPOLESTR pwszStatusText);
        
        END_INTERFACE
    } IDBAsynchNotifyVtbl;

    interface IDBAsynchNotify
    {
        CONST_VTBL struct IDBAsynchNotifyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBAsynchNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBAsynchNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBAsynchNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBAsynchNotify_OnLowResource(This,dwReserved)	\
    (This)->lpVtbl -> OnLowResource(This,dwReserved)

#define IDBAsynchNotify_OnProgress(This,hChapter,eOperation,ulProgress,ulProgressMax,eAsynchPhase,pwszStatusText)	\
    (This)->lpVtbl -> OnProgress(This,hChapter,eOperation,ulProgress,ulProgressMax,eAsynchPhase,pwszStatusText)

#define IDBAsynchNotify_OnStop(This,hChapter,eOperation,hrStatus,pwszStatusText)	\
    (This)->lpVtbl -> OnStop(This,hChapter,eOperation,hrStatus,pwszStatusText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchNotify_RemoteOnLowResource_Proxy( 
    IDBAsynchNotify __RPC_FAR * This,
    /* [in] */ DB_DWRESERVE dwReserved);


void __RPC_STUB IDBAsynchNotify_RemoteOnLowResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchNotify_RemoteOnProgress_Proxy( 
    IDBAsynchNotify __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [in] */ DBCOUNTITEM ulProgress,
    /* [in] */ DBCOUNTITEM ulProgressMax,
    /* [in] */ DBASYNCHPHASE eAsynchPhase,
    /* [string][unique][in] */ LPOLESTR pwszStatusText);


void __RPC_STUB IDBAsynchNotify_RemoteOnProgress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchNotify_RemoteOnStop_Proxy( 
    IDBAsynchNotify __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [in] */ HRESULT hrStatus,
    /* [string][unique][in] */ LPOLESTR pwszStatusText);


void __RPC_STUB IDBAsynchNotify_RemoteOnStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBAsynchNotify_INTERFACE_DEFINED__ */


#ifndef __IDBAsynchStatus_INTERFACE_DEFINED__
#define __IDBAsynchStatus_INTERFACE_DEFINED__

/* interface IDBAsynchStatus */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDBAsynchStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a95-2a1c-11ce-ade5-00aa0044773d")
    IDBAsynchStatus : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Abort( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBASYNCHOP eOperation) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBASYNCHOP eOperation,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgress,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgressMax,
            /* [out] */ DBASYNCHPHASE __RPC_FAR *peAsynchPhase,
            /* [out] */ LPOLESTR __RPC_FAR *ppwszStatusText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBAsynchStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBAsynchStatus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBAsynchStatus __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBAsynchStatus __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Abort )( 
            IDBAsynchStatus __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBASYNCHOP eOperation);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStatus )( 
            IDBAsynchStatus __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBASYNCHOP eOperation,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgress,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgressMax,
            /* [out] */ DBASYNCHPHASE __RPC_FAR *peAsynchPhase,
            /* [out] */ LPOLESTR __RPC_FAR *ppwszStatusText);
        
        END_INTERFACE
    } IDBAsynchStatusVtbl;

    interface IDBAsynchStatus
    {
        CONST_VTBL struct IDBAsynchStatusVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBAsynchStatus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBAsynchStatus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBAsynchStatus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBAsynchStatus_Abort(This,hChapter,eOperation)	\
    (This)->lpVtbl -> Abort(This,hChapter,eOperation)

#define IDBAsynchStatus_GetStatus(This,hChapter,eOperation,pulProgress,pulProgressMax,peAsynchPhase,ppwszStatusText)	\
    (This)->lpVtbl -> GetStatus(This,hChapter,eOperation,pulProgress,pulProgressMax,peAsynchPhase,ppwszStatusText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchStatus_RemoteAbort_Proxy( 
    IDBAsynchStatus __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBAsynchStatus_RemoteAbort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchStatus_RemoteGetStatus_Proxy( 
    IDBAsynchStatus __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgress,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgressMax,
    /* [out] */ DBASYNCHPHASE __RPC_FAR *peAsynchPhase,
    /* [out] */ LPOLESTR __RPC_FAR *ppwszStatusText,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBAsynchStatus_RemoteGetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBAsynchStatus_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oledb_0296 */
/* [local] */ 

#endif // OLEDBVER >= 0x0150
//@@@- V1.5


extern RPC_IF_HANDLE __MIDL_itf_oledb_0296_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0296_v0_0_s_ifspec;

#ifndef __ISessionProperties_INTERFACE_DEFINED__
#define __ISessionProperties_INTERFACE_DEFINED__

/* interface ISessionProperties */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISessionProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a85-2a1c-11ce-ade5-00aa0044773d")
    ISessionProperties : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetProperties( 
            /* [in] */ ULONG cPropertySets,
            /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISessionPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISessionProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISessionProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISessionProperties __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProperties )( 
            ISessionProperties __RPC_FAR * This,
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProperties )( 
            ISessionProperties __RPC_FAR * This,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);
        
        END_INTERFACE
    } ISessionPropertiesVtbl;

    interface ISessionProperties
    {
        CONST_VTBL struct ISessionPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISessionProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISessionProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISessionProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISessionProperties_GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)	\
    (This)->lpVtbl -> GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)

#define ISessionProperties_SetProperties(This,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> SetProperties(This,cPropertySets,rgPropertySets)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ISessionProperties_RemoteGetProperties_Proxy( 
    ISessionProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ISessionProperties_RemoteGetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ISessionProperties_RemoteSetProperties_Proxy( 
    ISessionProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ISessionProperties_RemoteSetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISessionProperties_INTERFACE_DEFINED__ */


#ifndef __IIndexDefinition_INTERFACE_DEFINED__
#define __IIndexDefinition_INTERFACE_DEFINED__

/* interface IIndexDefinition */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IIndexDefinition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a68-2a1c-11ce-ade5-00aa0044773d")
    IIndexDefinition : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateIndex( 
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBID __RPC_FAR *pIndexID,
            /* [in] */ DBORDINAL cIndexColumnDescs,
            /* [size_is][in] */ const DBINDEXCOLUMNDESC __RPC_FAR rgIndexColumnDescs[  ],
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppIndexID) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DropIndex( 
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pIndexID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIndexDefinitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIndexDefinition __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIndexDefinition __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIndexDefinition __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateIndex )( 
            IIndexDefinition __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBID __RPC_FAR *pIndexID,
            /* [in] */ DBORDINAL cIndexColumnDescs,
            /* [size_is][in] */ const DBINDEXCOLUMNDESC __RPC_FAR rgIndexColumnDescs[  ],
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppIndexID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropIndex )( 
            IIndexDefinition __RPC_FAR * This,
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pIndexID);
        
        END_INTERFACE
    } IIndexDefinitionVtbl;

    interface IIndexDefinition
    {
        CONST_VTBL struct IIndexDefinitionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIndexDefinition_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIndexDefinition_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIndexDefinition_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIndexDefinition_CreateIndex(This,pTableID,pIndexID,cIndexColumnDescs,rgIndexColumnDescs,cPropertySets,rgPropertySets,ppIndexID)	\
    (This)->lpVtbl -> CreateIndex(This,pTableID,pIndexID,cIndexColumnDescs,rgIndexColumnDescs,cPropertySets,rgPropertySets,ppIndexID)

#define IIndexDefinition_DropIndex(This,pTableID,pIndexID)	\
    (This)->lpVtbl -> DropIndex(This,pTableID,pIndexID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IIndexDefinition_RemoteCreateIndex_Proxy( 
    IIndexDefinition __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [in] */ DBORDINAL cIndexColumnDescs,
    /* [size_is][in] */ const DBINDEXCOLUMNDESC __RPC_FAR *rgIndexColumnDescs,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [unique][out][in] */ DBID __RPC_FAR *__RPC_FAR *ppIndexID,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IIndexDefinition_RemoteCreateIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IIndexDefinition_RemoteDropIndex_Proxy( 
    IIndexDefinition __RPC_FAR * This,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IIndexDefinition_RemoteDropIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIndexDefinition_INTERFACE_DEFINED__ */


#ifndef __ITableDefinition_INTERFACE_DEFINED__
#define __ITableDefinition_INTERFACE_DEFINED__

/* interface ITableDefinition */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITableDefinition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a86-2a1c-11ce-ade5-00aa0044773d")
    ITableDefinition : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateTable( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBORDINAL cColumnDescs,
            /* [size_is][in] */ const DBCOLUMNDESC __RPC_FAR rgColumnDescs[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DropTable( 
            /* [unique][in] */ DBID __RPC_FAR *pTableID) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE AddColumn( 
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [out][in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc,
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppColumnID) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DropColumn( 
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pColumnID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITableDefinitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITableDefinition __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITableDefinition __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITableDefinition __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateTable )( 
            ITableDefinition __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBORDINAL cColumnDescs,
            /* [size_is][in] */ const DBCOLUMNDESC __RPC_FAR rgColumnDescs[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropTable )( 
            ITableDefinition __RPC_FAR * This,
            /* [unique][in] */ DBID __RPC_FAR *pTableID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddColumn )( 
            ITableDefinition __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [out][in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc,
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppColumnID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropColumn )( 
            ITableDefinition __RPC_FAR * This,
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pColumnID);
        
        END_INTERFACE
    } ITableDefinitionVtbl;

    interface ITableDefinition
    {
        CONST_VTBL struct ITableDefinitionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITableDefinition_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITableDefinition_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITableDefinition_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITableDefinition_CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)	\
    (This)->lpVtbl -> CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)

#define ITableDefinition_DropTable(This,pTableID)	\
    (This)->lpVtbl -> DropTable(This,pTableID)

#define ITableDefinition_AddColumn(This,pTableID,pColumnDesc,ppColumnID)	\
    (This)->lpVtbl -> AddColumn(This,pTableID,pColumnDesc,ppColumnID)

#define ITableDefinition_DropColumn(This,pTableID,pColumnID)	\
    (This)->lpVtbl -> DropColumn(This,pTableID,pColumnID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ITableDefinition_RemoteCreateTable_Proxy( 
    ITableDefinition __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [in] */ DBORDINAL cColumnDescs,
    /* [size_is][in] */ const DBCOLUMNDESC __RPC_FAR *rgColumnDescs,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [unique][out][in] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ BOOL __RPC_FAR *pfTableCreated,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ITableDefinition_RemoteCreateTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITableDefinition_RemoteDropTable_Proxy( 
    ITableDefinition __RPC_FAR * This,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ITableDefinition_RemoteDropTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITableDefinition_RemoteAddColumn_Proxy( 
    ITableDefinition __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc,
    /* [unique][out][in] */ DBID __RPC_FAR *__RPC_FAR *ppColumnID,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ITableDefinition_RemoteAddColumn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITableDefinition_RemoteDropColumn_Proxy( 
    ITableDefinition __RPC_FAR * This,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pColumnID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ITableDefinition_RemoteDropColumn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITableDefinition_INTERFACE_DEFINED__ */


#ifndef __IOpenRowset_INTERFACE_DEFINED__
#define __IOpenRowset_INTERFACE_DEFINED__

/* interface IOpenRowset */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IOpenRowset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a69-2a1c-11ce-ade5-00aa0044773d")
    IOpenRowset : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OpenRowset( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pIndexID,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOpenRowsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOpenRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOpenRowset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOpenRowset __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenRowset )( 
            IOpenRowset __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pIndexID,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        END_INTERFACE
    } IOpenRowsetVtbl;

    interface IOpenRowset
    {
        CONST_VTBL struct IOpenRowsetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOpenRowset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOpenRowset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOpenRowset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOpenRowset_OpenRowset(This,pUnkOuter,pTableID,pIndexID,riid,cPropertySets,rgPropertySets,ppRowset)	\
    (This)->lpVtbl -> OpenRowset(This,pUnkOuter,pTableID,pIndexID,riid,cPropertySets,rgPropertySets,ppRowset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IOpenRowset_RemoteOpenRowset_Proxy( 
    IOpenRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IOpenRowset_RemoteOpenRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOpenRowset_INTERFACE_DEFINED__ */


#ifndef __IDBSchemaRowset_INTERFACE_DEFINED__
#define __IDBSchemaRowset_INTERFACE_DEFINED__

/* interface IDBSchemaRowset */
/* [unique][uuid][object] */ 

#define CRESTRICTIONS_DBSCHEMA_ASSERTIONS                      3
#define CRESTRICTIONS_DBSCHEMA_CATALOGS                        1
#define CRESTRICTIONS_DBSCHEMA_CHARACTER_SETS                  3
#define CRESTRICTIONS_DBSCHEMA_COLLATIONS                      3
#define CRESTRICTIONS_DBSCHEMA_COLUMNS                         4
#define CRESTRICTIONS_DBSCHEMA_CHECK_CONSTRAINTS               3
#define CRESTRICTIONS_DBSCHEMA_CONSTRAINT_COLUMN_USAGE         4
#define CRESTRICTIONS_DBSCHEMA_CONSTRAINT_TABLE_USAGE          3
#define CRESTRICTIONS_DBSCHEMA_KEY_COLUMN_USAGE                7
#define CRESTRICTIONS_DBSCHEMA_REFERENTIAL_CONSTRAINTS         3
#define CRESTRICTIONS_DBSCHEMA_TABLE_CONSTRAINTS               7
#define CRESTRICTIONS_DBSCHEMA_COLUMN_DOMAIN_USAGE             4
#define CRESTRICTIONS_DBSCHEMA_INDEXES                         5
#define CRESTRICTIONS_DBSCHEMA_OBJECT_ACTIONS                  1
#define CRESTRICTIONS_DBSCHEMA_OBJECTS                         1
#define CRESTRICTIONS_DBSCHEMA_COLUMN_PRIVILEGES               6
#define CRESTRICTIONS_DBSCHEMA_TABLE_PRIVILEGES                5
#define CRESTRICTIONS_DBSCHEMA_USAGE_PRIVILEGES                6
#define CRESTRICTIONS_DBSCHEMA_PROCEDURES                      4
#define CRESTRICTIONS_DBSCHEMA_SCHEMATA                        3
#define CRESTRICTIONS_DBSCHEMA_SQL_LANGUAGES                   0
#define CRESTRICTIONS_DBSCHEMA_STATISTICS                      3
#define CRESTRICTIONS_DBSCHEMA_TABLES                          4
#define CRESTRICTIONS_DBSCHEMA_TRANSLATIONS                    3
#define CRESTRICTIONS_DBSCHEMA_PROVIDER_TYPES                  2
#define CRESTRICTIONS_DBSCHEMA_VIEWS                           3
#define CRESTRICTIONS_DBSCHEMA_VIEW_COLUMN_USAGE               3
#define CRESTRICTIONS_DBSCHEMA_VIEW_TABLE_USAGE                3
#define CRESTRICTIONS_DBSCHEMA_PROCEDURE_PARAMETERS            4
#define CRESTRICTIONS_DBSCHEMA_FOREIGN_KEYS                    6
#define CRESTRICTIONS_DBSCHEMA_PRIMARY_KEYS                    3
#define CRESTRICTIONS_DBSCHEMA_PROCEDURE_COLUMNS               4
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
#define CRESTRICTIONS_DBSCHEMA_TABLES_INFO                     4
#define CRESTRICTIONS_MDSCHEMA_CUBES                           3
#define CRESTRICTIONS_MDSCHEMA_DIMENSIONS                      5
#define CRESTRICTIONS_MDSCHEMA_HIERARCHIES                     6
#define CRESTRICTIONS_MDSCHEMA_LEVELS                          7
#define CRESTRICTIONS_MDSCHEMA_MEASURES                        5
#define CRESTRICTIONS_MDSCHEMA_PROPERTIES                      9
#define CRESTRICTIONS_MDSCHEMA_MEMBERS                         12
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
#define CRESTRICTIONS_DBSCHEMA_TRUSTEE		                     4
#endif // OLEDBVER >= 0x0210
//@@@- V2.1

EXTERN_C const IID IID_IDBSchemaRowset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a7b-2a1c-11ce-ade5-00aa0044773d")
    IDBSchemaRowset : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetRowset( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFGUID rguidSchema,
            /* [in] */ ULONG cRestrictions,
            /* [size_is][in] */ const VARIANT __RPC_FAR rgRestrictions[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetSchemas( 
            /* [out][in] */ ULONG __RPC_FAR *pcSchemas,
            /* [size_is][size_is][out] */ GUID __RPC_FAR *__RPC_FAR *prgSchemas,
            /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgRestrictionSupport) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBSchemaRowsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBSchemaRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBSchemaRowset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBSchemaRowset __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowset )( 
            IDBSchemaRowset __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ REFGUID rguidSchema,
            /* [in] */ ULONG cRestrictions,
            /* [size_is][in] */ const VARIANT __RPC_FAR rgRestrictions[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSchemas )( 
            IDBSchemaRowset __RPC_FAR * This,
            /* [out][in] */ ULONG __RPC_FAR *pcSchemas,
            /* [size_is][size_is][out] */ GUID __RPC_FAR *__RPC_FAR *prgSchemas,
            /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgRestrictionSupport);
        
        END_INTERFACE
    } IDBSchemaRowsetVtbl;

    interface IDBSchemaRowset
    {
        CONST_VTBL struct IDBSchemaRowsetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBSchemaRowset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBSchemaRowset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBSchemaRowset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBSchemaRowset_GetRowset(This,pUnkOuter,rguidSchema,cRestrictions,rgRestrictions,riid,cPropertySets,rgPropertySets,ppRowset)	\
    (This)->lpVtbl -> GetRowset(This,pUnkOuter,rguidSchema,cRestrictions,rgRestrictions,riid,cPropertySets,rgPropertySets,ppRowset)

#define IDBSchemaRowset_GetSchemas(This,pcSchemas,prgSchemas,prgRestrictionSupport)	\
    (This)->lpVtbl -> GetSchemas(This,pcSchemas,prgSchemas,prgRestrictionSupport)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBSchemaRowset_RemoteGetRowset_Proxy( 
    IDBSchemaRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFGUID rguidSchema,
    /* [in] */ ULONG cRestrictions,
    /* [size_is][unique][in] */ const VARIANT __RPC_FAR *rgRestrictions,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBSchemaRowset_RemoteGetRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBSchemaRowset_RemoteGetSchemas_Proxy( 
    IDBSchemaRowset __RPC_FAR * This,
    /* [out][in] */ ULONG __RPC_FAR *pcSchemas,
    /* [size_is][size_is][out] */ GUID __RPC_FAR *__RPC_FAR *prgSchemas,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgRestrictionSupport,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IDBSchemaRowset_RemoteGetSchemas_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBSchemaRowset_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oledb_0301 */
/* [local] */ 

//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )


extern RPC_IF_HANDLE __MIDL_itf_oledb_0301_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0301_v0_0_s_ifspec;

#ifndef __IMDDataset_INTERFACE_DEFINED__
#define __IMDDataset_INTERFACE_DEFINED__

/* interface IMDDataset */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IMDDataset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a07cccd1-8148-11d0-87bb-00c04fc33942")
    IMDDataset : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FreeAxisInfo( 
            /* [in] */ DBCOUNTITEM cAxes,
            /* [size_is][in] */ MDAXISINFO __RPC_FAR *rgAxisInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAxisInfo( 
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcAxes,
            /* [size_is][size_is][out] */ MDAXISINFO __RPC_FAR *__RPC_FAR *prgAxisInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAxisRowset( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBCOUNTITEM iAxis,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCellData( 
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBORDINAL ulStartCell,
            /* [in] */ DBORDINAL ulEndCell,
            /* [out] */ void __RPC_FAR *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSpecification( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSpecification) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMDDatasetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMDDataset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMDDataset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMDDataset __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeAxisInfo )( 
            IMDDataset __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cAxes,
            /* [size_is][in] */ MDAXISINFO __RPC_FAR *rgAxisInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxisInfo )( 
            IMDDataset __RPC_FAR * This,
            /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcAxes,
            /* [size_is][size_is][out] */ MDAXISINFO __RPC_FAR *__RPC_FAR *prgAxisInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxisRowset )( 
            IMDDataset __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBCOUNTITEM iAxis,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCellData )( 
            IMDDataset __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBORDINAL ulStartCell,
            /* [in] */ DBORDINAL ulEndCell,
            /* [out] */ void __RPC_FAR *pData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpecification )( 
            IMDDataset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSpecification);
        
        END_INTERFACE
    } IMDDatasetVtbl;

    interface IMDDataset
    {
        CONST_VTBL struct IMDDatasetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMDDataset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMDDataset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMDDataset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMDDataset_FreeAxisInfo(This,cAxes,rgAxisInfo)	\
    (This)->lpVtbl -> FreeAxisInfo(This,cAxes,rgAxisInfo)

#define IMDDataset_GetAxisInfo(This,pcAxes,prgAxisInfo)	\
    (This)->lpVtbl -> GetAxisInfo(This,pcAxes,prgAxisInfo)

#define IMDDataset_GetAxisRowset(This,pUnkOuter,iAxis,riid,cPropertySets,rgPropertySets,ppRowset)	\
    (This)->lpVtbl -> GetAxisRowset(This,pUnkOuter,iAxis,riid,cPropertySets,rgPropertySets,ppRowset)

#define IMDDataset_GetCellData(This,hAccessor,ulStartCell,ulEndCell,pData)	\
    (This)->lpVtbl -> GetCellData(This,hAccessor,ulStartCell,ulEndCell,pData)

#define IMDDataset_GetSpecification(This,riid,ppSpecification)	\
    (This)->lpVtbl -> GetSpecification(This,riid,ppSpecification)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IMDDataset_FreeAxisInfo_Proxy( 
    IMDDataset __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cAxes,
    /* [size_is][in] */ MDAXISINFO __RPC_FAR *rgAxisInfo);


void __RPC_STUB IMDDataset_FreeAxisInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMDDataset_GetAxisInfo_Proxy( 
    IMDDataset __RPC_FAR * This,
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcAxes,
    /* [size_is][size_is][out] */ MDAXISINFO __RPC_FAR *__RPC_FAR *prgAxisInfo);


void __RPC_STUB IMDDataset_GetAxisInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMDDataset_GetAxisRowset_Proxy( 
    IMDDataset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DBCOUNTITEM iAxis,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


void __RPC_STUB IMDDataset_GetAxisRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMDDataset_GetCellData_Proxy( 
    IMDDataset __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [in] */ DBORDINAL ulStartCell,
    /* [in] */ DBORDINAL ulEndCell,
    /* [out] */ void __RPC_FAR *pData);


void __RPC_STUB IMDDataset_GetCellData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMDDataset_GetSpecification_Proxy( 
    IMDDataset __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSpecification);


void __RPC_STUB IMDDataset_GetSpecification_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMDDataset_INTERFACE_DEFINED__ */


#ifndef __IMDFind_INTERFACE_DEFINED__
#define __IMDFind_INTERFACE_DEFINED__

/* interface IMDFind */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IMDFind;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a07cccd2-8148-11d0-87bb-00c04fc33942")
    IMDFind : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FindCell( 
            /* [in] */ DBORDINAL ulStartingOrdinal,
            /* [in] */ DBCOUNTITEM cMembers,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszMember,
            /* [out] */ DBORDINAL __RPC_FAR *pulCellOrdinal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindTuple( 
            /* [in] */ ULONG ulAxisIdentifier,
            /* [in] */ DBORDINAL ulStartingOrdinal,
            /* [in] */ DBCOUNTITEM cMembers,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszMember,
            /* [out] */ ULONG __RPC_FAR *pulTupleOrdinal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMDFindVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMDFind __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMDFind __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMDFind __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindCell )( 
            IMDFind __RPC_FAR * This,
            /* [in] */ DBORDINAL ulStartingOrdinal,
            /* [in] */ DBCOUNTITEM cMembers,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszMember,
            /* [out] */ DBORDINAL __RPC_FAR *pulCellOrdinal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindTuple )( 
            IMDFind __RPC_FAR * This,
            /* [in] */ ULONG ulAxisIdentifier,
            /* [in] */ DBORDINAL ulStartingOrdinal,
            /* [in] */ DBCOUNTITEM cMembers,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszMember,
            /* [out] */ ULONG __RPC_FAR *pulTupleOrdinal);
        
        END_INTERFACE
    } IMDFindVtbl;

    interface IMDFind
    {
        CONST_VTBL struct IMDFindVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMDFind_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMDFind_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMDFind_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMDFind_FindCell(This,ulStartingOrdinal,cMembers,rgpwszMember,pulCellOrdinal)	\
    (This)->lpVtbl -> FindCell(This,ulStartingOrdinal,cMembers,rgpwszMember,pulCellOrdinal)

#define IMDFind_FindTuple(This,ulAxisIdentifier,ulStartingOrdinal,cMembers,rgpwszMember,pulTupleOrdinal)	\
    (This)->lpVtbl -> FindTuple(This,ulAxisIdentifier,ulStartingOrdinal,cMembers,rgpwszMember,pulTupleOrdinal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IMDFind_FindCell_Proxy( 
    IMDFind __RPC_FAR * This,
    /* [in] */ DBORDINAL ulStartingOrdinal,
    /* [in] */ DBCOUNTITEM cMembers,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszMember,
    /* [out] */ DBORDINAL __RPC_FAR *pulCellOrdinal);


void __RPC_STUB IMDFind_FindCell_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMDFind_FindTuple_Proxy( 
    IMDFind __RPC_FAR * This,
    /* [in] */ ULONG ulAxisIdentifier,
    /* [in] */ DBORDINAL ulStartingOrdinal,
    /* [in] */ DBCOUNTITEM cMembers,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszMember,
    /* [out] */ ULONG __RPC_FAR *pulTupleOrdinal);


void __RPC_STUB IMDFind_FindTuple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMDFind_INTERFACE_DEFINED__ */


#ifndef __IMDRangeRowset_INTERFACE_DEFINED__
#define __IMDRangeRowset_INTERFACE_DEFINED__

/* interface IMDRangeRowset */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IMDRangeRowset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa0-2a1c-11ce-ade5-00aa0044773d")
    IMDRangeRowset : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRangeRowset( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBORDINAL ulStartCell,
            /* [in] */ DBORDINAL ulEndCell,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMDRangeRowsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMDRangeRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMDRangeRowset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMDRangeRowset __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRangeRowset )( 
            IMDRangeRowset __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBORDINAL ulStartCell,
            /* [in] */ DBORDINAL ulEndCell,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        END_INTERFACE
    } IMDRangeRowsetVtbl;

    interface IMDRangeRowset
    {
        CONST_VTBL struct IMDRangeRowsetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMDRangeRowset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMDRangeRowset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMDRangeRowset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMDRangeRowset_GetRangeRowset(This,pUnkOuter,ulStartCell,ulEndCell,riid,cPropertySets,rgPropertySets,ppRowset)	\
    (This)->lpVtbl -> GetRangeRowset(This,pUnkOuter,ulStartCell,ulEndCell,riid,cPropertySets,rgPropertySets,ppRowset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IMDRangeRowset_GetRangeRowset_Proxy( 
    IMDRangeRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DBORDINAL ulStartCell,
    /* [in] */ DBORDINAL ulEndCell,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


void __RPC_STUB IMDRangeRowset_GetRangeRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMDRangeRowset_INTERFACE_DEFINED__ */


#ifndef __IAlterTable_INTERFACE_DEFINED__
#define __IAlterTable_INTERFACE_DEFINED__

/* interface IAlterTable */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IAlterTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa5-2a1c-11ce-ade5-00aa0044773d")
    IAlterTable : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AlterColumn( 
            /* [in] */ DBID __RPC_FAR *pTableId,
            /* [in] */ DBID __RPC_FAR *pColumnId,
            /* [in] */ DBCOLUMNDESCFLAGS ColumnDescFlags,
            /* [in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AlterTable( 
            /* [in] */ DBID __RPC_FAR *pTableId,
            /* [in] */ DBID __RPC_FAR *pNewTableId,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAlterTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAlterTable __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAlterTable __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAlterTable __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AlterColumn )( 
            IAlterTable __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableId,
            /* [in] */ DBID __RPC_FAR *pColumnId,
            /* [in] */ DBCOLUMNDESCFLAGS ColumnDescFlags,
            /* [in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AlterTable )( 
            IAlterTable __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableId,
            /* [in] */ DBID __RPC_FAR *pNewTableId,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);
        
        END_INTERFACE
    } IAlterTableVtbl;

    interface IAlterTable
    {
        CONST_VTBL struct IAlterTableVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAlterTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAlterTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAlterTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAlterTable_AlterColumn(This,pTableId,pColumnId,ColumnDescFlags,pColumnDesc)	\
    (This)->lpVtbl -> AlterColumn(This,pTableId,pColumnId,ColumnDescFlags,pColumnDesc)

#define IAlterTable_AlterTable(This,pTableId,pNewTableId,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> AlterTable(This,pTableId,pNewTableId,cPropertySets,rgPropertySets)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAlterTable_AlterColumn_Proxy( 
    IAlterTable __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableId,
    /* [in] */ DBID __RPC_FAR *pColumnId,
    /* [in] */ DBCOLUMNDESCFLAGS ColumnDescFlags,
    /* [in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc);


void __RPC_STUB IAlterTable_AlterColumn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAlterTable_AlterTable_Proxy( 
    IAlterTable __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableId,
    /* [in] */ DBID __RPC_FAR *pNewTableId,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);


void __RPC_STUB IAlterTable_AlterTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAlterTable_INTERFACE_DEFINED__ */


#ifndef __IAlterIndex_INTERFACE_DEFINED__
#define __IAlterIndex_INTERFACE_DEFINED__

/* interface IAlterIndex */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IAlterIndex;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa6-2a1c-11ce-ade5-00aa0044773d")
    IAlterIndex : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AlterIndex( 
            /* [in] */ DBID __RPC_FAR *pTableId,
            /* [in] */ DBID __RPC_FAR *pIndexId,
            /* [in] */ DBID __RPC_FAR *pNewIndexId,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySet[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAlterIndexVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAlterIndex __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAlterIndex __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAlterIndex __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AlterIndex )( 
            IAlterIndex __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableId,
            /* [in] */ DBID __RPC_FAR *pIndexId,
            /* [in] */ DBID __RPC_FAR *pNewIndexId,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySet[  ]);
        
        END_INTERFACE
    } IAlterIndexVtbl;

    interface IAlterIndex
    {
        CONST_VTBL struct IAlterIndexVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAlterIndex_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAlterIndex_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAlterIndex_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAlterIndex_AlterIndex(This,pTableId,pIndexId,pNewIndexId,cPropertySets,rgPropertySet)	\
    (This)->lpVtbl -> AlterIndex(This,pTableId,pIndexId,pNewIndexId,cPropertySets,rgPropertySet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAlterIndex_AlterIndex_Proxy( 
    IAlterIndex __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableId,
    /* [in] */ DBID __RPC_FAR *pIndexId,
    /* [in] */ DBID __RPC_FAR *pNewIndexId,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySet[  ]);


void __RPC_STUB IAlterIndex_AlterIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAlterIndex_INTERFACE_DEFINED__ */


#ifndef __IRowsetChapterMember_INTERFACE_DEFINED__
#define __IRowsetChapterMember_INTERFACE_DEFINED__

/* interface IRowsetChapterMember */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowsetChapterMember;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa8-2a1c-11ce-ade5-00aa0044773d")
    IRowsetChapterMember : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsRowInChapter( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ HROW hRow) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetChapterMemberVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetChapterMember __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetChapterMember __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetChapterMember __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsRowInChapter )( 
            IRowsetChapterMember __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ HROW hRow);
        
        END_INTERFACE
    } IRowsetChapterMemberVtbl;

    interface IRowsetChapterMember
    {
        CONST_VTBL struct IRowsetChapterMemberVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetChapterMember_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetChapterMember_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetChapterMember_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetChapterMember_IsRowInChapter(This,hChapter,hRow)	\
    (This)->lpVtbl -> IsRowInChapter(This,hChapter,hRow)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetChapterMember_IsRowInChapter_Proxy( 
    IRowsetChapterMember __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ HROW hRow);


void __RPC_STUB IRowsetChapterMember_IsRowInChapter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetChapterMember_INTERFACE_DEFINED__ */


#ifndef __ICommandPersist_INTERFACE_DEFINED__
#define __ICommandPersist_INTERFACE_DEFINED__

/* interface ICommandPersist */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_ICommandPersist;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa7-2a1c-11ce-ade5-00aa0044773d")
    ICommandPersist : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DeleteCommand( 
            /* [in] */ DBID __RPC_FAR *pCommandID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentCommand( 
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppCommandID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCommand( 
            /* [in] */ DBID __RPC_FAR *pCommandID,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveCommand( 
            /* [in] */ DBID __RPC_FAR *pCommandID,
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICommandPersistVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICommandPersist __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICommandPersist __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICommandPersist __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteCommand )( 
            ICommandPersist __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pCommandID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentCommand )( 
            ICommandPersist __RPC_FAR * This,
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppCommandID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadCommand )( 
            ICommandPersist __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pCommandID,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveCommand )( 
            ICommandPersist __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pCommandID,
            /* [in] */ DWORD dwFlags);
        
        END_INTERFACE
    } ICommandPersistVtbl;

    interface ICommandPersist
    {
        CONST_VTBL struct ICommandPersistVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICommandPersist_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICommandPersist_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICommandPersist_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICommandPersist_DeleteCommand(This,pCommandID)	\
    (This)->lpVtbl -> DeleteCommand(This,pCommandID)

#define ICommandPersist_GetCurrentCommand(This,ppCommandID)	\
    (This)->lpVtbl -> GetCurrentCommand(This,ppCommandID)

#define ICommandPersist_LoadCommand(This,pCommandID,dwFlags)	\
    (This)->lpVtbl -> LoadCommand(This,pCommandID,dwFlags)

#define ICommandPersist_SaveCommand(This,pCommandID,dwFlags)	\
    (This)->lpVtbl -> SaveCommand(This,pCommandID,dwFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICommandPersist_DeleteCommand_Proxy( 
    ICommandPersist __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pCommandID);


void __RPC_STUB ICommandPersist_DeleteCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICommandPersist_GetCurrentCommand_Proxy( 
    ICommandPersist __RPC_FAR * This,
    /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppCommandID);


void __RPC_STUB ICommandPersist_GetCurrentCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICommandPersist_LoadCommand_Proxy( 
    ICommandPersist __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pCommandID,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB ICommandPersist_LoadCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICommandPersist_SaveCommand_Proxy( 
    ICommandPersist __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pCommandID,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB ICommandPersist_SaveCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICommandPersist_INTERFACE_DEFINED__ */


#ifndef __IRowsetRefresh_INTERFACE_DEFINED__
#define __IRowsetRefresh_INTERFACE_DEFINED__

/* interface IRowsetRefresh */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowsetRefresh;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa9-2a1c-11ce-ade5-00aa0044773d")
    IRowsetRefresh : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RefreshVisibleData( 
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBCOUNTITEM cRows,
            /* [in] */ const HROW __RPC_FAR rghRows[  ],
            /* [in] */ BOOL fOverWrite,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsRefreshed,
            /* [out] */ HROW __RPC_FAR *__RPC_FAR *prghRowsRefreshed,
            /* [out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastVisibleData( 
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetRefreshVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetRefresh __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetRefresh __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetRefresh __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RefreshVisibleData )( 
            IRowsetRefresh __RPC_FAR * This,
            /* [in] */ HCHAPTER hChapter,
            /* [in] */ DBCOUNTITEM cRows,
            /* [in] */ const HROW __RPC_FAR rghRows[  ],
            /* [in] */ BOOL fOverWrite,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsRefreshed,
            /* [out] */ HROW __RPC_FAR *__RPC_FAR *prghRowsRefreshed,
            /* [out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLastVisibleData )( 
            IRowsetRefresh __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [in] */ HACCESSOR hAccessor,
            /* [out] */ void __RPC_FAR *pData);
        
        END_INTERFACE
    } IRowsetRefreshVtbl;

    interface IRowsetRefresh
    {
        CONST_VTBL struct IRowsetRefreshVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetRefresh_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetRefresh_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetRefresh_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetRefresh_RefreshVisibleData(This,hChapter,cRows,rghRows,fOverWrite,pcRowsRefreshed,prghRowsRefreshed,prgRowStatus)	\
    (This)->lpVtbl -> RefreshVisibleData(This,hChapter,cRows,rghRows,fOverWrite,pcRowsRefreshed,prghRowsRefreshed,prgRowStatus)

#define IRowsetRefresh_GetLastVisibleData(This,hRow,hAccessor,pData)	\
    (This)->lpVtbl -> GetLastVisibleData(This,hRow,hAccessor,pData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetRefresh_RefreshVisibleData_Proxy( 
    IRowsetRefresh __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBCOUNTITEM cRows,
    /* [in] */ const HROW __RPC_FAR rghRows[  ],
    /* [in] */ BOOL fOverWrite,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pcRowsRefreshed,
    /* [out] */ HROW __RPC_FAR *__RPC_FAR *prghRowsRefreshed,
    /* [out] */ DBROWSTATUS __RPC_FAR *__RPC_FAR *prgRowStatus);


void __RPC_STUB IRowsetRefresh_RefreshVisibleData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetRefresh_GetLastVisibleData_Proxy( 
    IRowsetRefresh __RPC_FAR * This,
    /* [in] */ HROW hRow,
    /* [in] */ HACCESSOR hAccessor,
    /* [out] */ void __RPC_FAR *pData);


void __RPC_STUB IRowsetRefresh_GetLastVisibleData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetRefresh_INTERFACE_DEFINED__ */


#ifndef __IParentRowset_INTERFACE_DEFINED__
#define __IParentRowset_INTERFACE_DEFINED__

/* interface IParentRowset */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IParentRowset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aaa-2a1c-11ce-ade5-00aa0044773d")
    IParentRowset : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetChildRowset( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBORDINAL iOrdinal,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IParentRowsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IParentRowset __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IParentRowset __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IParentRowset __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChildRowset )( 
            IParentRowset __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBORDINAL iOrdinal,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        END_INTERFACE
    } IParentRowsetVtbl;

    interface IParentRowset
    {
        CONST_VTBL struct IParentRowsetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParentRowset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IParentRowset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IParentRowset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IParentRowset_GetChildRowset(This,pUnkOuter,iOrdinal,riid,ppRowset)	\
    (This)->lpVtbl -> GetChildRowset(This,pUnkOuter,iOrdinal,riid,ppRowset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IParentRowset_GetChildRowset_Proxy( 
    IParentRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DBORDINAL iOrdinal,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


void __RPC_STUB IParentRowset_GetChildRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IParentRowset_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oledb_0310 */
/* [local] */ 

#endif // OLEDBVER >= 0x0200
//@@@- V2.0


extern RPC_IF_HANDLE __MIDL_itf_oledb_0310_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0310_v0_0_s_ifspec;

#ifndef __IErrorRecords_INTERFACE_DEFINED__
#define __IErrorRecords_INTERFACE_DEFINED__

/* interface IErrorRecords */
/* [unique][uuid][object] */ 

#define IDENTIFIER_SDK_MASK	0xF0000000
#define IDENTIFIER_SDK_ERROR	0x10000000
typedef struct tagERRORINFO
    {
    HRESULT hrError;
    DWORD dwMinor;
    CLSID clsid;
    IID iid;
    DISPID dispid;
    }	ERRORINFO;


EXTERN_C const IID IID_IErrorRecords;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a67-2a1c-11ce-ade5-00aa0044773d")
    IErrorRecords : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE AddErrorRecord( 
            /* [in] */ ERRORINFO __RPC_FAR *pErrorInfo,
            /* [in] */ DWORD dwLookupID,
            /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
            /* [in] */ IUnknown __RPC_FAR *punkCustomError,
            /* [in] */ DWORD dwDynamicErrorID) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetBasicErrorInfo( 
            /* [in] */ ULONG ulRecordNum,
            /* [out] */ ERRORINFO __RPC_FAR *pErrorInfo) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetCustomErrorObject( 
            /* [in] */ ULONG ulRecordNum,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetErrorInfo( 
            /* [in] */ ULONG ulRecordNum,
            /* [in] */ LCID lcid,
            /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfo) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetErrorParameters( 
            /* [in] */ ULONG ulRecordNum,
            /* [out] */ DISPPARAMS __RPC_FAR *pdispparams) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetRecordCount( 
            /* [out] */ ULONG __RPC_FAR *pcRecords) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IErrorRecordsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IErrorRecords __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IErrorRecords __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IErrorRecords __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddErrorRecord )( 
            IErrorRecords __RPC_FAR * This,
            /* [in] */ ERRORINFO __RPC_FAR *pErrorInfo,
            /* [in] */ DWORD dwLookupID,
            /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
            /* [in] */ IUnknown __RPC_FAR *punkCustomError,
            /* [in] */ DWORD dwDynamicErrorID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBasicErrorInfo )( 
            IErrorRecords __RPC_FAR * This,
            /* [in] */ ULONG ulRecordNum,
            /* [out] */ ERRORINFO __RPC_FAR *pErrorInfo);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCustomErrorObject )( 
            IErrorRecords __RPC_FAR * This,
            /* [in] */ ULONG ulRecordNum,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorInfo )( 
            IErrorRecords __RPC_FAR * This,
            /* [in] */ ULONG ulRecordNum,
            /* [in] */ LCID lcid,
            /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfo);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorParameters )( 
            IErrorRecords __RPC_FAR * This,
            /* [in] */ ULONG ulRecordNum,
            /* [out] */ DISPPARAMS __RPC_FAR *pdispparams);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRecordCount )( 
            IErrorRecords __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pcRecords);
        
        END_INTERFACE
    } IErrorRecordsVtbl;

    interface IErrorRecords
    {
        CONST_VTBL struct IErrorRecordsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IErrorRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IErrorRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IErrorRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IErrorRecords_AddErrorRecord(This,pErrorInfo,dwLookupID,pdispparams,punkCustomError,dwDynamicErrorID)	\
    (This)->lpVtbl -> AddErrorRecord(This,pErrorInfo,dwLookupID,pdispparams,punkCustomError,dwDynamicErrorID)

#define IErrorRecords_GetBasicErrorInfo(This,ulRecordNum,pErrorInfo)	\
    (This)->lpVtbl -> GetBasicErrorInfo(This,ulRecordNum,pErrorInfo)

#define IErrorRecords_GetCustomErrorObject(This,ulRecordNum,riid,ppObject)	\
    (This)->lpVtbl -> GetCustomErrorObject(This,ulRecordNum,riid,ppObject)

#define IErrorRecords_GetErrorInfo(This,ulRecordNum,lcid,ppErrorInfo)	\
    (This)->lpVtbl -> GetErrorInfo(This,ulRecordNum,lcid,ppErrorInfo)

#define IErrorRecords_GetErrorParameters(This,ulRecordNum,pdispparams)	\
    (This)->lpVtbl -> GetErrorParameters(This,ulRecordNum,pdispparams)

#define IErrorRecords_GetRecordCount(This,pcRecords)	\
    (This)->lpVtbl -> GetRecordCount(This,pcRecords)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_RemoteAddErrorRecord_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ERRORINFO __RPC_FAR *pErrorInfo,
    /* [in] */ DWORD dwLookupID,
    /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
    /* [in] */ IUnknown __RPC_FAR *punkCustomError,
    /* [in] */ DWORD dwDynamicErrorID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IErrorRecords_RemoteAddErrorRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_RemoteGetBasicErrorInfo_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [out] */ ERRORINFO __RPC_FAR *pErrorInfo,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IErrorRecords_RemoteGetBasicErrorInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_RemoteGetCustomErrorObject_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IErrorRecords_RemoteGetCustomErrorObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_RemoteGetErrorInfo_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [in] */ LCID lcid,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfo,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IErrorRecords_RemoteGetErrorInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_RemoteGetErrorParameters_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [out] */ DISPPARAMS __RPC_FAR *pdispparams,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IErrorRecords_RemoteGetErrorParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_RemoteGetRecordCount_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pcRecords,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IErrorRecords_RemoteGetRecordCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IErrorRecords_INTERFACE_DEFINED__ */


#ifndef __IErrorLookup_INTERFACE_DEFINED__
#define __IErrorLookup_INTERFACE_DEFINED__

/* interface IErrorLookup */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IErrorLookup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a66-2a1c-11ce-ade5-00aa0044773d")
    IErrorLookup : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetErrorDescription( 
            /* [in] */ HRESULT hrError,
            /* [in] */ DWORD dwLookupID,
            /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR __RPC_FAR *pbstrSource,
            /* [out] */ BSTR __RPC_FAR *pbstrDescription) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetHelpInfo( 
            /* [in] */ HRESULT hrError,
            /* [in] */ DWORD dwLookupID,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR __RPC_FAR *pbstrHelpFile,
            /* [out] */ DWORD __RPC_FAR *pdwHelpContext) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE ReleaseErrors( 
            /* [in] */ const DWORD dwDynamicErrorID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IErrorLookupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IErrorLookup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IErrorLookup __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IErrorLookup __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorDescription )( 
            IErrorLookup __RPC_FAR * This,
            /* [in] */ HRESULT hrError,
            /* [in] */ DWORD dwLookupID,
            /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR __RPC_FAR *pbstrSource,
            /* [out] */ BSTR __RPC_FAR *pbstrDescription);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpInfo )( 
            IErrorLookup __RPC_FAR * This,
            /* [in] */ HRESULT hrError,
            /* [in] */ DWORD dwLookupID,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR __RPC_FAR *pbstrHelpFile,
            /* [out] */ DWORD __RPC_FAR *pdwHelpContext);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseErrors )( 
            IErrorLookup __RPC_FAR * This,
            /* [in] */ const DWORD dwDynamicErrorID);
        
        END_INTERFACE
    } IErrorLookupVtbl;

    interface IErrorLookup
    {
        CONST_VTBL struct IErrorLookupVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IErrorLookup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IErrorLookup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IErrorLookup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IErrorLookup_GetErrorDescription(This,hrError,dwLookupID,pdispparams,lcid,pbstrSource,pbstrDescription)	\
    (This)->lpVtbl -> GetErrorDescription(This,hrError,dwLookupID,pdispparams,lcid,pbstrSource,pbstrDescription)

#define IErrorLookup_GetHelpInfo(This,hrError,dwLookupID,lcid,pbstrHelpFile,pdwHelpContext)	\
    (This)->lpVtbl -> GetHelpInfo(This,hrError,dwLookupID,lcid,pbstrHelpFile,pdwHelpContext)

#define IErrorLookup_ReleaseErrors(This,dwDynamicErrorID)	\
    (This)->lpVtbl -> ReleaseErrors(This,dwDynamicErrorID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorLookup_RemoteGetErrorDescription_Proxy( 
    IErrorLookup __RPC_FAR * This,
    /* [in] */ HRESULT hrError,
    /* [in] */ DWORD dwLookupID,
    /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR __RPC_FAR *pbstrSource,
    /* [out] */ BSTR __RPC_FAR *pbstrDescription,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IErrorLookup_RemoteGetErrorDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorLookup_RemoteGetHelpInfo_Proxy( 
    IErrorLookup __RPC_FAR * This,
    /* [in] */ HRESULT hrError,
    /* [in] */ DWORD dwLookupID,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR __RPC_FAR *pbstrHelpFile,
    /* [out] */ DWORD __RPC_FAR *pdwHelpContext,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IErrorLookup_RemoteGetHelpInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorLookup_RemoteReleaseErrors_Proxy( 
    IErrorLookup __RPC_FAR * This,
    /* [in] */ const DWORD dwDynamicErrorID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IErrorLookup_RemoteReleaseErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IErrorLookup_INTERFACE_DEFINED__ */


#ifndef __ISQLErrorInfo_INTERFACE_DEFINED__
#define __ISQLErrorInfo_INTERFACE_DEFINED__

/* interface ISQLErrorInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISQLErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a74-2a1c-11ce-ade5-00aa0044773d")
    ISQLErrorInfo : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetSQLInfo( 
            /* [out] */ BSTR __RPC_FAR *pbstrSQLState,
            /* [out] */ LONG __RPC_FAR *plNativeError) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISQLErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLErrorInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLErrorInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLErrorInfo __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSQLInfo )( 
            ISQLErrorInfo __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbstrSQLState,
            /* [out] */ LONG __RPC_FAR *plNativeError);
        
        END_INTERFACE
    } ISQLErrorInfoVtbl;

    interface ISQLErrorInfo
    {
        CONST_VTBL struct ISQLErrorInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLErrorInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLErrorInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLErrorInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLErrorInfo_GetSQLInfo(This,pbstrSQLState,plNativeError)	\
    (This)->lpVtbl -> GetSQLInfo(This,pbstrSQLState,plNativeError)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ISQLErrorInfo_RemoteGetSQLInfo_Proxy( 
    ISQLErrorInfo __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbstrSQLState,
    /* [out] */ LONG __RPC_FAR *plNativeError,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ISQLErrorInfo_RemoteGetSQLInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISQLErrorInfo_INTERFACE_DEFINED__ */


#ifndef __IGetDataSource_INTERFACE_DEFINED__
#define __IGetDataSource_INTERFACE_DEFINED__

/* interface IGetDataSource */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IGetDataSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a75-2a1c-11ce-ade5-00aa0044773d")
    IGetDataSource : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetDataSource( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDataSource) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetDataSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGetDataSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGetDataSource __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGetDataSource __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDataSource )( 
            IGetDataSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDataSource);
        
        END_INTERFACE
    } IGetDataSourceVtbl;

    interface IGetDataSource
    {
        CONST_VTBL struct IGetDataSourceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetDataSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGetDataSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGetDataSource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGetDataSource_GetDataSource(This,riid,ppDataSource)	\
    (This)->lpVtbl -> GetDataSource(This,riid,ppDataSource)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IGetDataSource_RemoteGetDataSource_Proxy( 
    IGetDataSource __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDataSource,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB IGetDataSource_RemoteGetDataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGetDataSource_INTERFACE_DEFINED__ */


#ifndef __ITransactionLocal_INTERFACE_DEFINED__
#define __ITransactionLocal_INTERFACE_DEFINED__

/* interface ITransactionLocal */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionLocal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a5f-2a1c-11ce-ade5-00aa0044773d")
    ITransactionLocal : public ITransaction
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetOptionsObject( 
            /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE StartTransaction( 
            /* [in] */ ISOLEVEL isoLevel,
            /* [in] */ ULONG isoFlags,
            /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions,
            /* [out] */ ULONG __RPC_FAR *pulTransactionLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionLocalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITransactionLocal __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITransactionLocal __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITransactionLocal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Commit )( 
            ITransactionLocal __RPC_FAR * This,
            /* [in] */ BOOL fRetaining,
            /* [in] */ DWORD grfTC,
            /* [in] */ DWORD grfRM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Abort )( 
            ITransactionLocal __RPC_FAR * This,
            /* [unique][in] */ BOID __RPC_FAR *pboidReason,
            /* [in] */ BOOL fRetaining,
            /* [in] */ BOOL fAsync);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTransactionInfo )( 
            ITransactionLocal __RPC_FAR * This,
            /* [out] */ XACTTRANSINFO __RPC_FAR *pinfo);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOptionsObject )( 
            ITransactionLocal __RPC_FAR * This,
            /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartTransaction )( 
            ITransactionLocal __RPC_FAR * This,
            /* [in] */ ISOLEVEL isoLevel,
            /* [in] */ ULONG isoFlags,
            /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions,
            /* [out] */ ULONG __RPC_FAR *pulTransactionLevel);
        
        END_INTERFACE
    } ITransactionLocalVtbl;

    interface ITransactionLocal
    {
        CONST_VTBL struct ITransactionLocalVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionLocal_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionLocal_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionLocal_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionLocal_Commit(This,fRetaining,grfTC,grfRM)	\
    (This)->lpVtbl -> Commit(This,fRetaining,grfTC,grfRM)

#define ITransactionLocal_Abort(This,pboidReason,fRetaining,fAsync)	\
    (This)->lpVtbl -> Abort(This,pboidReason,fRetaining,fAsync)

#define ITransactionLocal_GetTransactionInfo(This,pinfo)	\
    (This)->lpVtbl -> GetTransactionInfo(This,pinfo)


#define ITransactionLocal_GetOptionsObject(This,ppOptions)	\
    (This)->lpVtbl -> GetOptionsObject(This,ppOptions)

#define ITransactionLocal_StartTransaction(This,isoLevel,isoFlags,pOtherOptions,pulTransactionLevel)	\
    (This)->lpVtbl -> StartTransaction(This,isoLevel,isoFlags,pOtherOptions,pulTransactionLevel)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionLocal_RemoteGetOptionsObject_Proxy( 
    ITransactionLocal __RPC_FAR * This,
    /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ITransactionLocal_RemoteGetOptionsObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionLocal_RemoteStartTransaction_Proxy( 
    ITransactionLocal __RPC_FAR * This,
    /* [in] */ ISOLEVEL isoLevel,
    /* [in] */ ULONG isoFlags,
    /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions,
    /* [unique][out][in] */ ULONG __RPC_FAR *pulTransactionLevel,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ITransactionLocal_RemoteStartTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionLocal_INTERFACE_DEFINED__ */


#ifndef __ITransactionJoin_INTERFACE_DEFINED__
#define __ITransactionJoin_INTERFACE_DEFINED__

/* interface ITransactionJoin */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionJoin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a5e-2a1c-11ce-ade5-00aa0044773d")
    ITransactionJoin : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetOptionsObject( 
            /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE JoinTransaction( 
            /* [in] */ IUnknown __RPC_FAR *punkTransactionCoord,
            /* [in] */ ISOLEVEL isoLevel,
            /* [in] */ ULONG isoFlags,
            /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionJoinVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITransactionJoin __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITransactionJoin __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITransactionJoin __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOptionsObject )( 
            ITransactionJoin __RPC_FAR * This,
            /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *JoinTransaction )( 
            ITransactionJoin __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *punkTransactionCoord,
            /* [in] */ ISOLEVEL isoLevel,
            /* [in] */ ULONG isoFlags,
            /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions);
        
        END_INTERFACE
    } ITransactionJoinVtbl;

    interface ITransactionJoin
    {
        CONST_VTBL struct ITransactionJoinVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionJoin_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionJoin_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionJoin_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionJoin_GetOptionsObject(This,ppOptions)	\
    (This)->lpVtbl -> GetOptionsObject(This,ppOptions)

#define ITransactionJoin_JoinTransaction(This,punkTransactionCoord,isoLevel,isoFlags,pOtherOptions)	\
    (This)->lpVtbl -> JoinTransaction(This,punkTransactionCoord,isoLevel,isoFlags,pOtherOptions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionJoin_RemoteGetOptionsObject_Proxy( 
    ITransactionJoin __RPC_FAR * This,
    /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ITransactionJoin_RemoteGetOptionsObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionJoin_RemoteJoinTransaction_Proxy( 
    ITransactionJoin __RPC_FAR * This,
    /* [unique][in] */ IUnknown __RPC_FAR *punkTransactionCoord,
    /* [in] */ ISOLEVEL isoLevel,
    /* [in] */ ULONG isoFlags,
    /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ITransactionJoin_RemoteJoinTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionJoin_INTERFACE_DEFINED__ */


#ifndef __ITransactionObject_INTERFACE_DEFINED__
#define __ITransactionObject_INTERFACE_DEFINED__

/* interface ITransactionObject */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a60-2a1c-11ce-ade5-00aa0044773d")
    ITransactionObject : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetTransactionObject( 
            /* [in] */ ULONG ulTransactionLevel,
            /* [out] */ ITransaction __RPC_FAR *__RPC_FAR *ppTransactionObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITransactionObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITransactionObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITransactionObject __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTransactionObject )( 
            ITransactionObject __RPC_FAR * This,
            /* [in] */ ULONG ulTransactionLevel,
            /* [out] */ ITransaction __RPC_FAR *__RPC_FAR *ppTransactionObject);
        
        END_INTERFACE
    } ITransactionObjectVtbl;

    interface ITransactionObject
    {
        CONST_VTBL struct ITransactionObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionObject_GetTransactionObject(This,ulTransactionLevel,ppTransactionObject)	\
    (This)->lpVtbl -> GetTransactionObject(This,ulTransactionLevel,ppTransactionObject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionObject_RemoteGetTransactionObject_Proxy( 
    ITransactionObject __RPC_FAR * This,
    /* [in] */ ULONG ulTransactionLevel,
    /* [out] */ ITransaction __RPC_FAR *__RPC_FAR *ppTransactionObject,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);


void __RPC_STUB ITransactionObject_RemoteGetTransactionObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionObject_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oledb_0324 */
/* [local] */ 

//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
#if 0  // to get around a MIDL limitation
typedef 
enum _TRUSTEE_TYPE
    {	TRUSTEE_IS_UNKNOWN	= 0,
	TRUSTEE_IS_USER	= TRUSTEE_IS_UNKNOWN + 1,
	TRUSTEE_IS_GROUP	= TRUSTEE_IS_USER + 1,
	TRUSTEE_IS_DOMAIN	= TRUSTEE_IS_GROUP + 1,
	TRUSTEE_IS_ALIAS	= TRUSTEE_IS_DOMAIN + 1,
	TRUSTEE_IS_WELL_KNOWN_GROUP	= TRUSTEE_IS_ALIAS + 1,
	TRUSTEE_IS_DELETED	= TRUSTEE_IS_WELL_KNOWN_GROUP + 1,
	TRUSTEE_IS_INVALID	= TRUSTEE_IS_DELETED + 1,
	TRUSTEE_IS_COMPUTER	= TRUSTEE_IS_INVALID + 1
    }	TRUSTEE_TYPE;

typedef 
enum _TRUSTEE_FORM
    {	TRUSTEE_IS_SID	= 0,
	TRUSTEE_IS_NAME	= TRUSTEE_IS_SID + 1,
	TRUSTEE_BAD_FORM	= TRUSTEE_IS_NAME + 1
    }	TRUSTEE_FORM;

typedef 
enum _MULTIPLE_TRUSTEE_OPERATION
    {	NO_MULTIPLE_TRUSTEE	= 0,
	TRUSTEE_IS_IMPERSONATE	= NO_MULTIPLE_TRUSTEE + 1
    }	MULTIPLE_TRUSTEE_OPERATION;

typedef struct _TRUSTEE_A
    {
    struct _TRUSTEE_A __RPC_FAR *pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
    TRUSTEE_FORM TrusteeForm;
    TRUSTEE_TYPE TrusteeType;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ LPSTR ptstrName;
        /* [case()] */ SID __RPC_FAR *pSid;
        }	;
    }	TRUSTEE_A;

typedef struct _TRUSTEE_A __RPC_FAR *PTRUSTEE_A;

typedef struct _TRUSTEE_A TRUSTEEA;

typedef struct _TRUSTEE_A __RPC_FAR *PTRUSTEEA;

typedef struct _TRUSTEE_W
    {
    struct _TRUSTEE_W __RPC_FAR *pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
    TRUSTEE_FORM TrusteeForm;
    TRUSTEE_TYPE TrusteeType;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ LPWSTR ptstrName;
        /* [case()] */ SID __RPC_FAR *pSid;
        }	;
    }	TRUSTEE_W;

typedef struct _TRUSTEE_W __RPC_FAR *PTRUSTEE_W;

typedef struct _TRUSTEE_W TRUSTEEW;

typedef struct _TRUSTEE_W __RPC_FAR *PTRUSTEEW;

typedef TRUSTEE_A TRUSTEE_;

typedef PTRUSTEE_A PTRUSTEE_;

typedef TRUSTEEA TRUSTEE;

typedef PTRUSTEEA PTRUSTEE;

typedef 
enum _ACCESS_MODE
    {	NOT_USED_ACCESS	= 0,
	GRANT_ACCESS	= NOT_USED_ACCESS + 1,
	SET_ACCESS	= GRANT_ACCESS + 1,
	DENY_ACCESS	= SET_ACCESS + 1,
	REVOKE_ACCESS	= DENY_ACCESS + 1,
	SET_AUDIT_SUCCESS	= REVOKE_ACCESS + 1,
	SET_AUDIT_FAILURE	= SET_AUDIT_SUCCESS + 1
    }	ACCESS_MODE;

typedef 
enum _SE_OBJECT_TYPE
    {	SE_UNKNOWN_OBJECT_TYPE	= 0,
	SE_FILE_OBJECT	= SE_UNKNOWN_OBJECT_TYPE + 1,
	SE_SERVICE	= SE_FILE_OBJECT + 1,
	SE_PRINTER	= SE_SERVICE + 1,
	SE_REGISTRY_KEY	= SE_PRINTER + 1,
	SE_LMSHARE	= SE_REGISTRY_KEY + 1,
	SE_KERNEL_OBJECT	= SE_LMSHARE + 1,
	SE_WINDOW_OBJECT	= SE_KERNEL_OBJECT + 1,
	SE_DS_OBJECT	= SE_WINDOW_OBJECT + 1,
	SE_DS_OBJECT_ALL	= SE_DS_OBJECT + 1,
	SE_PROVIDER_DEFINED_OBJECT	= SE_DS_OBJECT_ALL + 1,
	SE_WMIGUID_OBJECT	= SE_PROVIDER_DEFINED_OBJECT + 1
    }	SE_OBJECT_TYPE;

typedef struct _EXPLICIT_ACCESS_A
    {
    DWORD grfAccessPermissions;
    ACCESS_MODE grfAccessMode;
    DWORD grfInheritance;
    TRUSTEE_A Trustee;
    }	EXPLICIT_ACCESS_A;

typedef struct _EXPLICIT_ACCESS_A __RPC_FAR *PEXPLICIT_ACCESS_A;

typedef struct _EXPLICIT_ACCESS_A EXPLICIT_ACCESSA;

typedef struct _EXPLICIT_ACCESS_A __RPC_FAR *PEXPLICIT_ACCESSA;

typedef struct _EXPLICIT_ACCESS_W
    {
    DWORD grfAccessPermissions;
    ACCESS_MODE grfAccessMode;
    DWORD grfInheritance;
    TRUSTEE_W Trustee;
    }	EXPLICIT_ACCESS_W;

typedef struct _EXPLICIT_ACCESS_W __RPC_FAR *PEXPLICIT_ACCESS_W;

typedef struct _EXPLICIT_ACCESS_W EXPLICIT_ACCESSW;

typedef struct _EXPLICIT_ACCESS_W __RPC_FAR *PEXPLICIT_ACCESSW;

typedef EXPLICIT_ACCESS_A EXPLICIT_ACCESS_;

typedef PEXPLICIT_ACCESS_A PEXPLICIT_ACCESS_;

typedef EXPLICIT_ACCESSA EXPLICIT_ACCESS;

typedef PEXPLICIT_ACCESSA PEXPLICIT_ACCESS;

typedef ULONG ACCESS_RIGHTS;

typedef ULONG __RPC_FAR *PACCESS_RIGHTS;

typedef ULONG INHERIT_FLAGS;

typedef ULONG __RPC_FAR *PINHERIT_FLAGS;

typedef struct _ACTRL_ACCESS_ENTRYA
    {
    TRUSTEE_A Trustee;
    ULONG fAccessFlags;
    ACCESS_RIGHTS Access;
    ACCESS_RIGHTS ProvSpecificAccess;
    INHERIT_FLAGS Inheritance;
    LPSTR lpInheritProperty;
    }	ACTRL_ACCESS_ENTRYA;

typedef struct _ACTRL_ACCESS_ENTRYA __RPC_FAR *PACTRL_ACCESS_ENTRYA;

typedef struct _ACTRL_ACCESS_ENTRYW
    {
    TRUSTEE_W Trustee;
    ULONG fAccessFlags;
    ACCESS_RIGHTS Access;
    ACCESS_RIGHTS ProvSpecificAccess;
    INHERIT_FLAGS Inheritance;
    LPWSTR lpInheritProperty;
    }	ACTRL_ACCESS_ENTRYW;

typedef struct _ACTRL_ACCESS_ENTRYW __RPC_FAR *PACTRL_ACCESS_ENTRYW;

typedef ACTRL_ACCESS_ENTRYA ACTRL_ACCESS_ENTRY;

typedef PACTRL_ACCESS_ENTRYA PACTRL_ACCESS_ENTRY;

typedef struct _ACTRL_ACCESS_ENTRY_LISTA
    {
    ULONG cEntries;
    /* [size_is] */ ACTRL_ACCESS_ENTRYA __RPC_FAR *pAccessList;
    }	ACTRL_ACCESS_ENTRY_LISTA;

typedef struct _ACTRL_ACCESS_ENTRY_LISTA __RPC_FAR *PACTRL_ACCESS_ENTRY_LISTA;

typedef struct _ACTRL_ACCESS_ENTRY_LISTW
    {
    ULONG cEntries;
    /* [size_is] */ ACTRL_ACCESS_ENTRYW __RPC_FAR *pAccessList;
    }	ACTRL_ACCESS_ENTRY_LISTW;

typedef struct _ACTRL_ACCESS_ENTRY_LISTW __RPC_FAR *PACTRL_ACCESS_ENTRY_LISTW;

typedef ACTRL_ACCESS_ENTRY_LISTA ACTRL_ACCESS_ENTRY_LIST;

typedef PACTRL_ACCESS_ENTRY_LISTA PACTRL_ACCESS_ENTRY_LIST;

typedef struct _ACTRL_PROPERTY_ENTRYA
    {
    LPSTR lpProperty;
    PACTRL_ACCESS_ENTRY_LISTA pAccessEntryList;
    ULONG fListFlags;
    }	ACTRL_PROPERTY_ENTRYA;

typedef struct _ACTRL_PROPERTY_ENTRYA __RPC_FAR *PACTRL_PROPERTY_ENTRYA;

typedef struct _ACTRL_PROPERTY_ENTRYW
    {
    LPWSTR lpProperty;
    PACTRL_ACCESS_ENTRY_LISTW pAccessEntryList;
    ULONG fListFlags;
    }	ACTRL_PROPERTY_ENTRYW;

typedef struct _ACTRL_PROPERTY_ENTRYW __RPC_FAR *PACTRL_PROPERTY_ENTRYW;

typedef ACTRL_PROPERTY_ENTRYA ACTRL_PROPERTY_ENTRY;

typedef PACTRL_PROPERTY_ENTRYA PACTRL_PROPERTY_ENTRY;

typedef struct _ACTRL_ALISTA
    {
    ULONG cEntries;
    /* [size_is] */ PACTRL_PROPERTY_ENTRYA pPropertyAccessList;
    }	ACTRL_ACCESSA;

typedef struct _ACTRL_ALISTA __RPC_FAR *PACTRL_ACCESSA;

typedef struct _ACTRL_ALISTA ACTRL_AUDITA;

typedef struct _ACTRL_ALISTA __RPC_FAR *PACTRL_AUDITA;

typedef struct _ACTRL_ALISTW
    {
    ULONG cEntries;
    /* [size_is] */ PACTRL_PROPERTY_ENTRYW pPropertyAccessList;
    }	ACTRL_ACCESSW;

typedef struct _ACTRL_ALISTW __RPC_FAR *PACTRL_ACCESSW;

typedef struct _ACTRL_ALISTW ACTRL_AUDITW;

typedef struct _ACTRL_ALISTW __RPC_FAR *PACTRL_AUDITW;

typedef ACTRL_ACCESSA ACTRL_ACCESS;

typedef PACTRL_ACCESSA PACTRL_ACCESS;

typedef ACTRL_AUDITA ACTRL_AUDIT;

typedef PACTRL_AUDITA PACTRL_AUDIT;

typedef struct _TRUSTEE_ACCESSA
    {
    LPSTR lpProperty;
    ACCESS_RIGHTS Access;
    ULONG fAccessFlags;
    ULONG fReturnedAccess;
    }	TRUSTEE_ACCESSA;

typedef struct _TRUSTEE_ACCESSA __RPC_FAR *PTRUSTEE_ACCESSA;

typedef struct _TRUSTEE_ACCESSW
    {
    LPWSTR lpProperty;
    ACCESS_RIGHTS Access;
    ULONG fAccessFlags;
    ULONG fReturnedAccess;
    }	TRUSTEE_ACCESSW;

typedef struct _TRUSTEE_ACCESSW __RPC_FAR *PTRUSTEE_ACCESSW;

typedef TRUSTEE_ACCESSA TRUSTEE_ACCESS;

typedef PTRUSTEE_ACCESSA PTRUSTEE_ACCESS;

typedef struct _ACTRL_OVERLAPPED
    {
    union 
        {
        PVOID Provider;
        ULONG Reserved1;
        }	;
    ULONG Reserved2;
    HANDLE hEvent;
    }	ACTRL_OVERLAPPED;

typedef struct _ACTRL_OVERLAPPED __RPC_FAR *PACTRL_OVERLAPPED;

typedef struct _ACTRL_ACCESS_INFOA
    {
    ULONG fAccessPermission;
    LPSTR lpAccessPermissionName;
    }	ACTRL_ACCESS_INFOA;

typedef struct _ACTRL_ACCESS_INFOA __RPC_FAR *PACTRL_ACCESS_INFOA;

typedef struct _ACTRL_ACCESS_INFOW
    {
    ULONG fAccessPermission;
    LPWSTR lpAccessPermissionName;
    }	ACTRL_ACCESS_INFOW;

typedef struct _ACTRL_ACCESS_INFOW __RPC_FAR *PACTRL_ACCESS_INFOW;

typedef ACTRL_ACCESS_INFOA ACTRL_ACCESS_INFO;

typedef PACTRL_ACCESS_INFOA PACTRL_ACCESS_INFO;

typedef struct _ACTRL_CONTROL_INFOA
    {
    LPSTR lpControlId;
    LPSTR lpControlName;
    }	ACTRL_CONTROL_INFOA;

typedef struct _ACTRL_CONTROL_INFOA __RPC_FAR *PACTRL_CONTROL_INFOA;

typedef struct _ACTRL_CONTROL_INFOW
    {
    LPWSTR lpControlId;
    LPWSTR lpControlName;
    }	ACTRL_CONTROL_INFOW;

typedef struct _ACTRL_CONTROL_INFOW __RPC_FAR *PACTRL_CONTROL_INFOW;

typedef ACTRL_CONTROL_INFOA ACTRL_CONTROL_INFO;

typedef PACTRL_CONTROL_INFOA PACTRL_CONTROL_INFO;

#else
#include <accctrl.h>
#endif


extern RPC_IF_HANDLE __MIDL_itf_oledb_0324_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0324_v0_0_s_ifspec;

#ifndef __ITrusteeAdmin_INTERFACE_DEFINED__
#define __ITrusteeAdmin_INTERFACE_DEFINED__

/* interface ITrusteeAdmin */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_ITrusteeAdmin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa1-2a1c-11ce-ade5-00aa0044773d")
    ITrusteeAdmin : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareTrustees( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee1,
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTrustee( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteTrustee( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTrusteeProperties( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTrusteeProperties( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
            /* [in] */ const ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrusteeAdminVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrusteeAdmin __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrusteeAdmin __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrusteeAdmin __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompareTrustees )( 
            ITrusteeAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee1,
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateTrustee )( 
            ITrusteeAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteTrustee )( 
            ITrusteeAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTrusteeProperties )( 
            ITrusteeAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTrusteeProperties )( 
            ITrusteeAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
            /* [in] */ const ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);
        
        END_INTERFACE
    } ITrusteeAdminVtbl;

    interface ITrusteeAdmin
    {
        CONST_VTBL struct ITrusteeAdminVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrusteeAdmin_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrusteeAdmin_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrusteeAdmin_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrusteeAdmin_CompareTrustees(This,pTrustee1,pTrustee2)	\
    (This)->lpVtbl -> CompareTrustees(This,pTrustee1,pTrustee2)

#define ITrusteeAdmin_CreateTrustee(This,pTrustee,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> CreateTrustee(This,pTrustee,cPropertySets,rgPropertySets)

#define ITrusteeAdmin_DeleteTrustee(This,pTrustee)	\
    (This)->lpVtbl -> DeleteTrustee(This,pTrustee)

#define ITrusteeAdmin_SetTrusteeProperties(This,pTrustee,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> SetTrusteeProperties(This,pTrustee,cPropertySets,rgPropertySets)

#define ITrusteeAdmin_GetTrusteeProperties(This,pTrustee,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)	\
    (This)->lpVtbl -> GetTrusteeProperties(This,pTrustee,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrusteeAdmin_CompareTrustees_Proxy( 
    ITrusteeAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee1,
    /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee2);


void __RPC_STUB ITrusteeAdmin_CompareTrustees_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrusteeAdmin_CreateTrustee_Proxy( 
    ITrusteeAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);


void __RPC_STUB ITrusteeAdmin_CreateTrustee_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrusteeAdmin_DeleteTrustee_Proxy( 
    ITrusteeAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee);


void __RPC_STUB ITrusteeAdmin_DeleteTrustee_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrusteeAdmin_SetTrusteeProperties_Proxy( 
    ITrusteeAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);


void __RPC_STUB ITrusteeAdmin_SetTrusteeProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrusteeAdmin_GetTrusteeProperties_Proxy( 
    ITrusteeAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
    /* [in] */ const ULONG cPropertyIDSets,
    /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);


void __RPC_STUB ITrusteeAdmin_GetTrusteeProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrusteeAdmin_INTERFACE_DEFINED__ */


#ifndef __ITrusteeGroupAdmin_INTERFACE_DEFINED__
#define __ITrusteeGroupAdmin_INTERFACE_DEFINED__

/* interface ITrusteeGroupAdmin */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_ITrusteeGroupAdmin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa2-2a1c-11ce-ade5-00aa0044773d")
    ITrusteeGroupAdmin : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddMember( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMemberTrustee) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteMember( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMemberTrustee) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMember( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMemberTrustee,
            /* [out] */ BOOL __RPC_FAR *pfStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMembers( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
            /* [out] */ ULONG __RPC_FAR *pcMembers,
            /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *prgMembers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMemberships( 
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
            /* [out] */ ULONG __RPC_FAR *pcMemberships,
            /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *prgMemberships) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrusteeGroupAdminVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrusteeGroupAdmin __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrusteeGroupAdmin __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrusteeGroupAdmin __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddMember )( 
            ITrusteeGroupAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMemberTrustee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteMember )( 
            ITrusteeGroupAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMemberTrustee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsMember )( 
            ITrusteeGroupAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMemberTrustee,
            /* [out] */ BOOL __RPC_FAR *pfStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMembers )( 
            ITrusteeGroupAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
            /* [out] */ ULONG __RPC_FAR *pcMembers,
            /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *prgMembers);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMemberships )( 
            ITrusteeGroupAdmin __RPC_FAR * This,
            /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
            /* [out] */ ULONG __RPC_FAR *pcMemberships,
            /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *prgMemberships);
        
        END_INTERFACE
    } ITrusteeGroupAdminVtbl;

    interface ITrusteeGroupAdmin
    {
        CONST_VTBL struct ITrusteeGroupAdminVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrusteeGroupAdmin_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrusteeGroupAdmin_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrusteeGroupAdmin_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrusteeGroupAdmin_AddMember(This,pMembershipTrustee,pMemberTrustee)	\
    (This)->lpVtbl -> AddMember(This,pMembershipTrustee,pMemberTrustee)

#define ITrusteeGroupAdmin_DeleteMember(This,pMembershipTrustee,pMemberTrustee)	\
    (This)->lpVtbl -> DeleteMember(This,pMembershipTrustee,pMemberTrustee)

#define ITrusteeGroupAdmin_IsMember(This,pMembershipTrustee,pMemberTrustee,pfStatus)	\
    (This)->lpVtbl -> IsMember(This,pMembershipTrustee,pMemberTrustee,pfStatus)

#define ITrusteeGroupAdmin_GetMembers(This,pMembershipTrustee,pcMembers,prgMembers)	\
    (This)->lpVtbl -> GetMembers(This,pMembershipTrustee,pcMembers,prgMembers)

#define ITrusteeGroupAdmin_GetMemberships(This,pTrustee,pcMemberships,prgMemberships)	\
    (This)->lpVtbl -> GetMemberships(This,pTrustee,pcMemberships,prgMemberships)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrusteeGroupAdmin_AddMember_Proxy( 
    ITrusteeGroupAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
    /* [in] */ TRUSTEE_W __RPC_FAR *pMemberTrustee);


void __RPC_STUB ITrusteeGroupAdmin_AddMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrusteeGroupAdmin_DeleteMember_Proxy( 
    ITrusteeGroupAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
    /* [in] */ TRUSTEE_W __RPC_FAR *pMemberTrustee);


void __RPC_STUB ITrusteeGroupAdmin_DeleteMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrusteeGroupAdmin_IsMember_Proxy( 
    ITrusteeGroupAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
    /* [in] */ TRUSTEE_W __RPC_FAR *pMemberTrustee,
    /* [out] */ BOOL __RPC_FAR *pfStatus);


void __RPC_STUB ITrusteeGroupAdmin_IsMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrusteeGroupAdmin_GetMembers_Proxy( 
    ITrusteeGroupAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pMembershipTrustee,
    /* [out] */ ULONG __RPC_FAR *pcMembers,
    /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *prgMembers);


void __RPC_STUB ITrusteeGroupAdmin_GetMembers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrusteeGroupAdmin_GetMemberships_Proxy( 
    ITrusteeGroupAdmin __RPC_FAR * This,
    /* [in] */ TRUSTEE_W __RPC_FAR *pTrustee,
    /* [out] */ ULONG __RPC_FAR *pcMemberships,
    /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *prgMemberships);


void __RPC_STUB ITrusteeGroupAdmin_GetMemberships_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrusteeGroupAdmin_INTERFACE_DEFINED__ */


#ifndef __IObjectAccessControl_INTERFACE_DEFINED__
#define __IObjectAccessControl_INTERFACE_DEFINED__

/* interface IObjectAccessControl */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IObjectAccessControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa3-2a1c-11ce-ade5-00aa0044773d")
    IObjectAccessControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetObjectAccessRights( 
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [out][in] */ ULONG __RPC_FAR *pcAccessEntries,
            /* [out][in] */ EXPLICIT_ACCESS_W __RPC_FAR *__RPC_FAR *prgAccessEntries) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectOwner( 
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *ppOwner) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsObjectAccessAllowed( 
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [in] */ EXPLICIT_ACCESS_W __RPC_FAR *pAccessEntry,
            /* [out] */ BOOL __RPC_FAR *pfResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetObjectAccessRights( 
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [in] */ ULONG cAccessEntries,
            /* [out][in] */ EXPLICIT_ACCESS_W __RPC_FAR *prgAccessEntries) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetObjectOwner( 
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [in] */ TRUSTEE_W __RPC_FAR *pOwner) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IObjectAccessControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IObjectAccessControl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IObjectAccessControl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IObjectAccessControl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetObjectAccessRights )( 
            IObjectAccessControl __RPC_FAR * This,
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [out][in] */ ULONG __RPC_FAR *pcAccessEntries,
            /* [out][in] */ EXPLICIT_ACCESS_W __RPC_FAR *__RPC_FAR *prgAccessEntries);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetObjectOwner )( 
            IObjectAccessControl __RPC_FAR * This,
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *ppOwner);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsObjectAccessAllowed )( 
            IObjectAccessControl __RPC_FAR * This,
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [in] */ EXPLICIT_ACCESS_W __RPC_FAR *pAccessEntry,
            /* [out] */ BOOL __RPC_FAR *pfResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetObjectAccessRights )( 
            IObjectAccessControl __RPC_FAR * This,
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [in] */ ULONG cAccessEntries,
            /* [out][in] */ EXPLICIT_ACCESS_W __RPC_FAR *prgAccessEntries);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetObjectOwner )( 
            IObjectAccessControl __RPC_FAR * This,
            /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
            /* [in] */ TRUSTEE_W __RPC_FAR *pOwner);
        
        END_INTERFACE
    } IObjectAccessControlVtbl;

    interface IObjectAccessControl
    {
        CONST_VTBL struct IObjectAccessControlVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectAccessControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IObjectAccessControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IObjectAccessControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IObjectAccessControl_GetObjectAccessRights(This,pObject,pcAccessEntries,prgAccessEntries)	\
    (This)->lpVtbl -> GetObjectAccessRights(This,pObject,pcAccessEntries,prgAccessEntries)

#define IObjectAccessControl_GetObjectOwner(This,pObject,ppOwner)	\
    (This)->lpVtbl -> GetObjectOwner(This,pObject,ppOwner)

#define IObjectAccessControl_IsObjectAccessAllowed(This,pObject,pAccessEntry,pfResult)	\
    (This)->lpVtbl -> IsObjectAccessAllowed(This,pObject,pAccessEntry,pfResult)

#define IObjectAccessControl_SetObjectAccessRights(This,pObject,cAccessEntries,prgAccessEntries)	\
    (This)->lpVtbl -> SetObjectAccessRights(This,pObject,cAccessEntries,prgAccessEntries)

#define IObjectAccessControl_SetObjectOwner(This,pObject,pOwner)	\
    (This)->lpVtbl -> SetObjectOwner(This,pObject,pOwner)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IObjectAccessControl_GetObjectAccessRights_Proxy( 
    IObjectAccessControl __RPC_FAR * This,
    /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
    /* [out][in] */ ULONG __RPC_FAR *pcAccessEntries,
    /* [out][in] */ EXPLICIT_ACCESS_W __RPC_FAR *__RPC_FAR *prgAccessEntries);


void __RPC_STUB IObjectAccessControl_GetObjectAccessRights_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IObjectAccessControl_GetObjectOwner_Proxy( 
    IObjectAccessControl __RPC_FAR * This,
    /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
    /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *ppOwner);


void __RPC_STUB IObjectAccessControl_GetObjectOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IObjectAccessControl_IsObjectAccessAllowed_Proxy( 
    IObjectAccessControl __RPC_FAR * This,
    /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
    /* [in] */ EXPLICIT_ACCESS_W __RPC_FAR *pAccessEntry,
    /* [out] */ BOOL __RPC_FAR *pfResult);


void __RPC_STUB IObjectAccessControl_IsObjectAccessAllowed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IObjectAccessControl_SetObjectAccessRights_Proxy( 
    IObjectAccessControl __RPC_FAR * This,
    /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
    /* [in] */ ULONG cAccessEntries,
    /* [out][in] */ EXPLICIT_ACCESS_W __RPC_FAR *prgAccessEntries);


void __RPC_STUB IObjectAccessControl_SetObjectAccessRights_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IObjectAccessControl_SetObjectOwner_Proxy( 
    IObjectAccessControl __RPC_FAR * This,
    /* [in] */ SEC_OBJECT __RPC_FAR *pObject,
    /* [in] */ TRUSTEE_W __RPC_FAR *pOwner);


void __RPC_STUB IObjectAccessControl_SetObjectOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IObjectAccessControl_INTERFACE_DEFINED__ */


#ifndef __ISecurityInfo_INTERFACE_DEFINED__
#define __ISecurityInfo_INTERFACE_DEFINED__

/* interface ISecurityInfo */
/* [unique][uuid][object][local] */ 

//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
typedef DWORD ACCESS_MASK;


enum ACCESS_MASKENUM
    {	PERM_EXCLUSIVE	= 0x200L,
	PERM_READDESIGN	= 0x400L,
	PERM_WRITEDESIGN	= 0x800L,
	PERM_WITHGRANT	= 0x1000L,
	PERM_REFERENCE	= 0x2000L,
	PERM_CREATE	= 0x4000L,
	PERM_INSERT	= 0x8000L,
	PERM_DELETE	= 0x10000L,
	PERM_READCONTROL	= 0x20000L,
	PERM_WRITEPERMISSIONS	= 0x40000L,
	PERM_WRITEOWNER	= 0x80000L,
	PERM_MAXIMUM_ALLOWED	= 0x2000000L,
	PERM_ALL	= 0x10000000L,
	PERM_EXECUTE	= 0x20000000L,
	PERM_READ	= 0x80000000L,
	PERM_UPDATE	= 0x40000000L,
	PERM_DROP	= 0x100L
    };
#define PERM_DESIGN 							PERM_WRITEDESIGN
#endif // OLEDBVER >= 0x0210
//@@@- V2.1

EXTERN_C const IID IID_ISecurityInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aa4-2a1c-11ce-ade5-00aa0044773d")
    ISecurityInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCurrentTrustee( 
            /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *ppTrustee) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectTypes( 
            /* [out] */ ULONG __RPC_FAR *cObjectTypes,
            /* [out] */ GUID __RPC_FAR *__RPC_FAR *rgObjectTypes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPermissions( 
            /* [in] */ GUID ObjectType,
            /* [out] */ ACCESS_MASK __RPC_FAR *pPermissions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISecurityInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISecurityInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISecurityInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISecurityInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentTrustee )( 
            ISecurityInfo __RPC_FAR * This,
            /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *ppTrustee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetObjectTypes )( 
            ISecurityInfo __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *cObjectTypes,
            /* [out] */ GUID __RPC_FAR *__RPC_FAR *rgObjectTypes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPermissions )( 
            ISecurityInfo __RPC_FAR * This,
            /* [in] */ GUID ObjectType,
            /* [out] */ ACCESS_MASK __RPC_FAR *pPermissions);
        
        END_INTERFACE
    } ISecurityInfoVtbl;

    interface ISecurityInfo
    {
        CONST_VTBL struct ISecurityInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISecurityInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISecurityInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISecurityInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISecurityInfo_GetCurrentTrustee(This,ppTrustee)	\
    (This)->lpVtbl -> GetCurrentTrustee(This,ppTrustee)

#define ISecurityInfo_GetObjectTypes(This,cObjectTypes,rgObjectTypes)	\
    (This)->lpVtbl -> GetObjectTypes(This,cObjectTypes,rgObjectTypes)

#define ISecurityInfo_GetPermissions(This,ObjectType,pPermissions)	\
    (This)->lpVtbl -> GetPermissions(This,ObjectType,pPermissions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISecurityInfo_GetCurrentTrustee_Proxy( 
    ISecurityInfo __RPC_FAR * This,
    /* [out] */ TRUSTEE_W __RPC_FAR *__RPC_FAR *ppTrustee);


void __RPC_STUB ISecurityInfo_GetCurrentTrustee_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISecurityInfo_GetObjectTypes_Proxy( 
    ISecurityInfo __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *cObjectTypes,
    /* [out] */ GUID __RPC_FAR *__RPC_FAR *rgObjectTypes);


void __RPC_STUB ISecurityInfo_GetObjectTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISecurityInfo_GetPermissions_Proxy( 
    ISecurityInfo __RPC_FAR * This,
    /* [in] */ GUID ObjectType,
    /* [out] */ ACCESS_MASK __RPC_FAR *pPermissions);


void __RPC_STUB ISecurityInfo_GetPermissions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISecurityInfo_INTERFACE_DEFINED__ */


#ifndef __ITableCreation_INTERFACE_DEFINED__
#define __ITableCreation_INTERFACE_DEFINED__

/* interface ITableCreation */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_ITableCreation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733abc-2a1c-11ce-ade5-00aa0044773d")
    ITableCreation : public ITableDefinition
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetTableDefinition( 
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [out] */ DBORDINAL __RPC_FAR *pcColumnDescs,
            /* [size_is][size_is][out] */ DBCOLUMNDESC __RPC_FAR *__RPC_FAR prgColumnDescs[  ],
            /* [out] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR prgPropertySets[  ],
            /* [out] */ ULONG __RPC_FAR *pcConstraintDescs,
            /* [size_is][size_is][out] */ DBCONSTRAINTDESC __RPC_FAR *__RPC_FAR prgConstraintDescs[  ],
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppwszStringBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITableCreationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITableCreation __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITableCreation __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITableCreation __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateTable )( 
            ITableCreation __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBORDINAL cColumnDescs,
            /* [size_is][in] */ const DBCOLUMNDESC __RPC_FAR rgColumnDescs[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropTable )( 
            ITableCreation __RPC_FAR * This,
            /* [unique][in] */ DBID __RPC_FAR *pTableID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddColumn )( 
            ITableCreation __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [out][in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc,
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppColumnID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropColumn )( 
            ITableCreation __RPC_FAR * This,
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pColumnID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTableDefinition )( 
            ITableCreation __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [out] */ DBORDINAL __RPC_FAR *pcColumnDescs,
            /* [size_is][size_is][out] */ DBCOLUMNDESC __RPC_FAR *__RPC_FAR prgColumnDescs[  ],
            /* [out] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR prgPropertySets[  ],
            /* [out] */ ULONG __RPC_FAR *pcConstraintDescs,
            /* [size_is][size_is][out] */ DBCONSTRAINTDESC __RPC_FAR *__RPC_FAR prgConstraintDescs[  ],
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppwszStringBuffer);
        
        END_INTERFACE
    } ITableCreationVtbl;

    interface ITableCreation
    {
        CONST_VTBL struct ITableCreationVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITableCreation_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITableCreation_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITableCreation_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITableCreation_CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)	\
    (This)->lpVtbl -> CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)

#define ITableCreation_DropTable(This,pTableID)	\
    (This)->lpVtbl -> DropTable(This,pTableID)

#define ITableCreation_AddColumn(This,pTableID,pColumnDesc,ppColumnID)	\
    (This)->lpVtbl -> AddColumn(This,pTableID,pColumnDesc,ppColumnID)

#define ITableCreation_DropColumn(This,pTableID,pColumnID)	\
    (This)->lpVtbl -> DropColumn(This,pTableID,pColumnID)


#define ITableCreation_GetTableDefinition(This,pTableID,pcColumnDescs,prgColumnDescs,pcPropertySets,prgPropertySets,pcConstraintDescs,prgConstraintDescs,ppwszStringBuffer)	\
    (This)->lpVtbl -> GetTableDefinition(This,pTableID,pcColumnDescs,prgColumnDescs,pcPropertySets,prgPropertySets,pcConstraintDescs,prgConstraintDescs,ppwszStringBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [local] */ HRESULT STDMETHODCALLTYPE ITableCreation_GetTableDefinition_Proxy( 
    ITableCreation __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [out] */ DBORDINAL __RPC_FAR *pcColumnDescs,
    /* [size_is][size_is][out] */ DBCOLUMNDESC __RPC_FAR *__RPC_FAR prgColumnDescs[  ],
    /* [out] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR prgPropertySets[  ],
    /* [out] */ ULONG __RPC_FAR *pcConstraintDescs,
    /* [size_is][size_is][out] */ DBCONSTRAINTDESC __RPC_FAR *__RPC_FAR prgConstraintDescs[  ],
    /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppwszStringBuffer);


void __RPC_STUB ITableCreation_GetTableDefinition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITableCreation_INTERFACE_DEFINED__ */


#ifndef __ITableDefinitionWithConstraints_INTERFACE_DEFINED__
#define __ITableDefinitionWithConstraints_INTERFACE_DEFINED__

/* interface ITableDefinitionWithConstraints */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_ITableDefinitionWithConstraints;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aab-2a1c-11ce-ade5-00aa0044773d")
    ITableDefinitionWithConstraints : public ITableCreation
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddConstraint( 
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBCONSTRAINTDESC __RPC_FAR *pConstraintDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTableWithConstraints( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBORDINAL cColumnDescs,
            /* [out][size_is][in] */ DBCOLUMNDESC __RPC_FAR rgColumnDescs[  ],
            /* [in] */ ULONG cConstraintDescs,
            /* [size_is][in] */ DBCONSTRAINTDESC __RPC_FAR rgConstraintDescs[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [out][size_is][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DropConstraint( 
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBID __RPC_FAR *pConstraintID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITableDefinitionWithConstraintsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITableDefinitionWithConstraints __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITableDefinitionWithConstraints __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITableDefinitionWithConstraints __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateTable )( 
            ITableDefinitionWithConstraints __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBORDINAL cColumnDescs,
            /* [size_is][in] */ const DBCOLUMNDESC __RPC_FAR rgColumnDescs[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropTable )( 
            ITableDefinitionWithConstraints __RPC_FAR * This,
            /* [unique][in] */ DBID __RPC_FAR *pTableID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddColumn )( 
            ITableDefinitionWithConstraints __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [out][in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc,
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppColumnID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropColumn )( 
            ITableDefinitionWithConstraints __RPC_FAR * This,
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pColumnID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTableDefinition )( 
            ITableDefinitionWithConstraints __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [out] */ DBORDINAL __RPC_FAR *pcColumnDescs,
            /* [size_is][size_is][out] */ DBCOLUMNDESC __RPC_FAR *__RPC_FAR prgColumnDescs[  ],
            /* [out] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR prgPropertySets[  ],
            /* [out] */ ULONG __RPC_FAR *pcConstraintDescs,
            /* [size_is][size_is][out] */ DBCONSTRAINTDESC __RPC_FAR *__RPC_FAR prgConstraintDescs[  ],
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppwszStringBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddConstraint )( 
            ITableDefinitionWithConstraints __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBCONSTRAINTDESC __RPC_FAR *pConstraintDesc);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateTableWithConstraints )( 
            ITableDefinitionWithConstraints __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBORDINAL cColumnDescs,
            /* [out][size_is][in] */ DBCOLUMNDESC __RPC_FAR rgColumnDescs[  ],
            /* [in] */ ULONG cConstraintDescs,
            /* [size_is][in] */ DBCONSTRAINTDESC __RPC_FAR rgConstraintDescs[  ],
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [out][size_is][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropConstraint )( 
            ITableDefinitionWithConstraints __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pTableID,
            /* [in] */ DBID __RPC_FAR *pConstraintID);
        
        END_INTERFACE
    } ITableDefinitionWithConstraintsVtbl;

    interface ITableDefinitionWithConstraints
    {
        CONST_VTBL struct ITableDefinitionWithConstraintsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITableDefinitionWithConstraints_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITableDefinitionWithConstraints_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITableDefinitionWithConstraints_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITableDefinitionWithConstraints_CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)	\
    (This)->lpVtbl -> CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)

#define ITableDefinitionWithConstraints_DropTable(This,pTableID)	\
    (This)->lpVtbl -> DropTable(This,pTableID)

#define ITableDefinitionWithConstraints_AddColumn(This,pTableID,pColumnDesc,ppColumnID)	\
    (This)->lpVtbl -> AddColumn(This,pTableID,pColumnDesc,ppColumnID)

#define ITableDefinitionWithConstraints_DropColumn(This,pTableID,pColumnID)	\
    (This)->lpVtbl -> DropColumn(This,pTableID,pColumnID)


#define ITableDefinitionWithConstraints_GetTableDefinition(This,pTableID,pcColumnDescs,prgColumnDescs,pcPropertySets,prgPropertySets,pcConstraintDescs,prgConstraintDescs,ppwszStringBuffer)	\
    (This)->lpVtbl -> GetTableDefinition(This,pTableID,pcColumnDescs,prgColumnDescs,pcPropertySets,prgPropertySets,pcConstraintDescs,prgConstraintDescs,ppwszStringBuffer)


#define ITableDefinitionWithConstraints_AddConstraint(This,pTableID,pConstraintDesc)	\
    (This)->lpVtbl -> AddConstraint(This,pTableID,pConstraintDesc)

#define ITableDefinitionWithConstraints_CreateTableWithConstraints(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,cConstraintDescs,rgConstraintDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)	\
    (This)->lpVtbl -> CreateTableWithConstraints(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,cConstraintDescs,rgConstraintDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)

#define ITableDefinitionWithConstraints_DropConstraint(This,pTableID,pConstraintID)	\
    (This)->lpVtbl -> DropConstraint(This,pTableID,pConstraintID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITableDefinitionWithConstraints_AddConstraint_Proxy( 
    ITableDefinitionWithConstraints __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [in] */ DBCONSTRAINTDESC __RPC_FAR *pConstraintDesc);


void __RPC_STUB ITableDefinitionWithConstraints_AddConstraint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITableDefinitionWithConstraints_CreateTableWithConstraints_Proxy( 
    ITableDefinitionWithConstraints __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [in] */ DBORDINAL cColumnDescs,
    /* [out][size_is][in] */ DBCOLUMNDESC __RPC_FAR rgColumnDescs[  ],
    /* [in] */ ULONG cConstraintDescs,
    /* [size_is][in] */ DBCONSTRAINTDESC __RPC_FAR rgConstraintDescs[  ],
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [out][size_is][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


void __RPC_STUB ITableDefinitionWithConstraints_CreateTableWithConstraints_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITableDefinitionWithConstraints_DropConstraint_Proxy( 
    ITableDefinitionWithConstraints __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [in] */ DBID __RPC_FAR *pConstraintID);


void __RPC_STUB ITableDefinitionWithConstraints_DropConstraint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITableDefinitionWithConstraints_INTERFACE_DEFINED__ */


#ifndef __IRow_INTERFACE_DEFINED__
#define __IRow_INTERFACE_DEFINED__

/* interface IRow */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733ab4-2a1c-11ce-ade5-00aa0044773d")
    IRow : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetColumns( 
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSourceRowset( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
            /* [out] */ HROW __RPC_FAR *phRow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [unique][in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBID __RPC_FAR *pColumnID,
            /* [in] */ REFGUID rguidColumnType,
            /* [in] */ DWORD dwBindFlags,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRow __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColumns )( 
            IRow __RPC_FAR * This,
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourceRowset )( 
            IRow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
            /* [out] */ HROW __RPC_FAR *phRow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IRow __RPC_FAR * This,
            /* [unique][in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ DBID __RPC_FAR *pColumnID,
            /* [in] */ REFGUID rguidColumnType,
            /* [in] */ DWORD dwBindFlags,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);
        
        END_INTERFACE
    } IRowVtbl;

    interface IRow
    {
        CONST_VTBL struct IRowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRow_GetColumns(This,cColumns,rgColumns)	\
    (This)->lpVtbl -> GetColumns(This,cColumns,rgColumns)

#define IRow_GetSourceRowset(This,riid,ppRowset,phRow)	\
    (This)->lpVtbl -> GetSourceRowset(This,riid,ppRowset,phRow)

#define IRow_Open(This,pUnkOuter,pColumnID,rguidColumnType,dwBindFlags,riid,ppUnk)	\
    (This)->lpVtbl -> Open(This,pUnkOuter,pColumnID,rguidColumnType,dwBindFlags,riid,ppUnk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [local] */ HRESULT STDMETHODCALLTYPE IRow_GetColumns_Proxy( 
    IRow __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumns,
    /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]);


void __RPC_STUB IRow_GetColumns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRow_GetSourceRowset_Proxy( 
    IRow __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [out] */ HROW __RPC_FAR *phRow);


void __RPC_STUB IRow_GetSourceRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRow_Open_Proxy( 
    IRow __RPC_FAR * This,
    /* [unique][in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DBID __RPC_FAR *pColumnID,
    /* [in] */ REFGUID rguidColumnType,
    /* [in] */ DWORD dwBindFlags,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);


void __RPC_STUB IRow_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRow_INTERFACE_DEFINED__ */


#ifndef __IRowChange_INTERFACE_DEFINED__
#define __IRowChange_INTERFACE_DEFINED__

/* interface IRowChange */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowChange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733ab5-2a1c-11ce-ade5-00aa0044773d")
    IRowChange : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetColumns( 
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowChangeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowChange __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowChange __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowChange __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColumns )( 
            IRowChange __RPC_FAR * This,
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]);
        
        END_INTERFACE
    } IRowChangeVtbl;

    interface IRowChange
    {
        CONST_VTBL struct IRowChangeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowChange_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowChange_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowChange_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowChange_SetColumns(This,cColumns,rgColumns)	\
    (This)->lpVtbl -> SetColumns(This,cColumns,rgColumns)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [local] */ HRESULT STDMETHODCALLTYPE IRowChange_SetColumns_Proxy( 
    IRowChange __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumns,
    /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]);


void __RPC_STUB IRowChange_SetColumns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowChange_INTERFACE_DEFINED__ */


#ifndef __IRowSchemaChange_INTERFACE_DEFINED__
#define __IRowSchemaChange_INTERFACE_DEFINED__

/* interface IRowSchemaChange */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowSchemaChange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aae-2a1c-11ce-ade5-00aa0044773d")
    IRowSchemaChange : public IRowChange
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DeleteColumns( 
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDs[  ],
            /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddColumns( 
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][in] */ const DBCOLUMNINFO __RPC_FAR rgNewColumnInfo[  ],
            /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowSchemaChangeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowSchemaChange __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowSchemaChange __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowSchemaChange __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColumns )( 
            IRowSchemaChange __RPC_FAR * This,
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteColumns )( 
            IRowSchemaChange __RPC_FAR * This,
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDs[  ],
            /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddColumns )( 
            IRowSchemaChange __RPC_FAR * This,
            /* [in] */ DBORDINAL cColumns,
            /* [size_is][in] */ const DBCOLUMNINFO __RPC_FAR rgNewColumnInfo[  ],
            /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]);
        
        END_INTERFACE
    } IRowSchemaChangeVtbl;

    interface IRowSchemaChange
    {
        CONST_VTBL struct IRowSchemaChangeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowSchemaChange_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowSchemaChange_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowSchemaChange_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowSchemaChange_SetColumns(This,cColumns,rgColumns)	\
    (This)->lpVtbl -> SetColumns(This,cColumns,rgColumns)


#define IRowSchemaChange_DeleteColumns(This,cColumns,rgColumnIDs,rgdwStatus)	\
    (This)->lpVtbl -> DeleteColumns(This,cColumns,rgColumnIDs,rgdwStatus)

#define IRowSchemaChange_AddColumns(This,cColumns,rgNewColumnInfo,rgColumns)	\
    (This)->lpVtbl -> AddColumns(This,cColumns,rgNewColumnInfo,rgColumns)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowSchemaChange_DeleteColumns_Proxy( 
    IRowSchemaChange __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumns,
    /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDs[  ],
    /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ]);


void __RPC_STUB IRowSchemaChange_DeleteColumns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowSchemaChange_AddColumns_Proxy( 
    IRowSchemaChange __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumns,
    /* [size_is][in] */ const DBCOLUMNINFO __RPC_FAR rgNewColumnInfo[  ],
    /* [size_is][out][in] */ DBCOLUMNACCESS __RPC_FAR rgColumns[  ]);


void __RPC_STUB IRowSchemaChange_AddColumns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowSchemaChange_INTERFACE_DEFINED__ */


#ifndef __IGetRow_INTERFACE_DEFINED__
#define __IGetRow_INTERFACE_DEFINED__

/* interface IGetRow */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IGetRow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aaf-2a1c-11ce-ade5-00aa0044773d")
    IGetRow : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRowFromHROW( 
            /* [unique][in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ HROW hRow,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetURLFromHROW( 
            /* [in] */ HROW hRow,
            /* [out] */ LPOLESTR __RPC_FAR *ppwszURL) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetRowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGetRow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGetRow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGetRow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowFromHROW )( 
            IGetRow __RPC_FAR * This,
            /* [unique][in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ HROW hRow,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetURLFromHROW )( 
            IGetRow __RPC_FAR * This,
            /* [in] */ HROW hRow,
            /* [out] */ LPOLESTR __RPC_FAR *ppwszURL);
        
        END_INTERFACE
    } IGetRowVtbl;

    interface IGetRow
    {
        CONST_VTBL struct IGetRowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetRow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGetRow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGetRow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGetRow_GetRowFromHROW(This,pUnkOuter,hRow,riid,ppUnk)	\
    (This)->lpVtbl -> GetRowFromHROW(This,pUnkOuter,hRow,riid,ppUnk)

#define IGetRow_GetURLFromHROW(This,hRow,ppwszURL)	\
    (This)->lpVtbl -> GetURLFromHROW(This,hRow,ppwszURL)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGetRow_GetRowFromHROW_Proxy( 
    IGetRow __RPC_FAR * This,
    /* [unique][in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ HROW hRow,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);


void __RPC_STUB IGetRow_GetRowFromHROW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGetRow_GetURLFromHROW_Proxy( 
    IGetRow __RPC_FAR * This,
    /* [in] */ HROW hRow,
    /* [out] */ LPOLESTR __RPC_FAR *ppwszURL);


void __RPC_STUB IGetRow_GetURLFromHROW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGetRow_INTERFACE_DEFINED__ */


#ifndef __IBindResource_INTERFACE_DEFINED__
#define __IBindResource_INTERFACE_DEFINED__

/* interface IBindResource */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBindResource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733ab1-2a1c-11ce-ade5-00aa0044773d")
    IBindResource : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Bind( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ LPCOLESTR pwszURL,
            /* [in] */ DBBINDURLFLAG dwBindURLFlags,
            /* [in] */ REFGUID rguid,
            /* [in] */ REFIID riid,
            /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
            /* [unique][out][in] */ DBIMPLICITSESSION __RPC_FAR *pImplSession,
            /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBindResourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBindResource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBindResource __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBindResource __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Bind )( 
            IBindResource __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ LPCOLESTR pwszURL,
            /* [in] */ DBBINDURLFLAG dwBindURLFlags,
            /* [in] */ REFGUID rguid,
            /* [in] */ REFIID riid,
            /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
            /* [unique][out][in] */ DBIMPLICITSESSION __RPC_FAR *pImplSession,
            /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);
        
        END_INTERFACE
    } IBindResourceVtbl;

    interface IBindResource
    {
        CONST_VTBL struct IBindResourceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBindResource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBindResource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBindResource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBindResource_Bind(This,pUnkOuter,pwszURL,dwBindURLFlags,rguid,riid,pAuthenticate,pImplSession,pdwBindStatus,ppUnk)	\
    (This)->lpVtbl -> Bind(This,pUnkOuter,pwszURL,dwBindURLFlags,rguid,riid,pAuthenticate,pImplSession,pdwBindStatus,ppUnk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IBindResource_RemoteBind_Proxy( 
    IBindResource __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ LPCOLESTR pwszURL,
    /* [in] */ DBBINDURLFLAG dwBindURLFlags,
    /* [in] */ REFGUID rguid,
    /* [in] */ REFIID riid,
    /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [in] */ IUnknown __RPC_FAR *pSessionUnkOuter,
    /* [unique][in] */ IID __RPC_FAR *piid,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession,
    /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);


void __RPC_STUB IBindResource_RemoteBind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBindResource_INTERFACE_DEFINED__ */


#ifndef __IScopedOperations_INTERFACE_DEFINED__
#define __IScopedOperations_INTERFACE_DEFINED__

/* interface IScopedOperations */
/* [unique][uuid][object] */ 

typedef DWORD DBCOPYFLAGS;


enum DBCOPYFLAGSENUM
    {	DBCOPY_ASYNC	= 0x100,
	DBCOPY_REPLACE_EXISTING	= 0x200,
	DBCOPY_ALLOW_EMULATION	= 0x400,
	DBCOPY_NON_RECURSIVE	= 0x800,
	DBCOPY_ATOMIC	= 0x1000
    };
typedef DWORD DBMOVEFLAGS;


enum DBMOVEFLAGSENUM
    {	DBMOVE_REPLACE_EXISTING	= 0x1,
	DBMOVE_ASYNC	= 0x100,
	DBMOVE_DONT_UPDATE_LINKS	= 0x200,
	DBMOVE_ALLOW_EMULATION	= 0x400,
	DBMOVE_ATOMIC	= 0x1000
    };
typedef DWORD DBDELETEFLAGS;


enum DBDELETEFLAGSENUM
    {	DBDELETE_ASYNC	= 0x100,
	DBDELETE_ATOMIC	= 0x1000
    };

EXTERN_C const IID IID_IScopedOperations;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733ab0-2a1c-11ce-ade5-00aa0044773d")
    IScopedOperations : public IBindResource
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszSourceURLs[  ],
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszDestURLs[  ],
            /* [in] */ DWORD dwCopyFlags,
            /* [unique][in] */ IAuthenticate __RPC_FAR *pAuthenticate,
            /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ],
            /* [size_is][out] */ LPOLESTR __RPC_FAR rgpwszNewURLs[  ],
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszSourceURLs[  ],
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszDestURLs[  ],
            /* [in] */ DWORD dwMoveFlags,
            /* [unique][in] */ IAuthenticate __RPC_FAR *pAuthenticate,
            /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ],
            /* [size_is][out] */ LPOLESTR __RPC_FAR rgpwszNewURLs[  ],
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszURLs[  ],
            /* [in] */ DWORD dwDeleteFlags,
            /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ]) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OpenRowset( 
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pIndexID,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScopedOperationsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IScopedOperations __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IScopedOperations __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IScopedOperations __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Bind )( 
            IScopedOperations __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ LPCOLESTR pwszURL,
            /* [in] */ DBBINDURLFLAG dwBindURLFlags,
            /* [in] */ REFGUID rguid,
            /* [in] */ REFIID riid,
            /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
            /* [unique][out][in] */ DBIMPLICITSESSION __RPC_FAR *pImplSession,
            /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy )( 
            IScopedOperations __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszSourceURLs[  ],
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszDestURLs[  ],
            /* [in] */ DWORD dwCopyFlags,
            /* [unique][in] */ IAuthenticate __RPC_FAR *pAuthenticate,
            /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ],
            /* [size_is][out] */ LPOLESTR __RPC_FAR rgpwszNewURLs[  ],
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            IScopedOperations __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszSourceURLs[  ],
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszDestURLs[  ],
            /* [in] */ DWORD dwMoveFlags,
            /* [unique][in] */ IAuthenticate __RPC_FAR *pAuthenticate,
            /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ],
            /* [size_is][out] */ LPOLESTR __RPC_FAR rgpwszNewURLs[  ],
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IScopedOperations __RPC_FAR * This,
            /* [in] */ DBCOUNTITEM cRows,
            /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszURLs[  ],
            /* [in] */ DWORD dwDeleteFlags,
            /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ]);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenRowset )( 
            IScopedOperations __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [unique][in] */ DBID __RPC_FAR *pTableID,
            /* [unique][in] */ DBID __RPC_FAR *pIndexID,
            /* [in] */ REFIID riid,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);
        
        END_INTERFACE
    } IScopedOperationsVtbl;

    interface IScopedOperations
    {
        CONST_VTBL struct IScopedOperationsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScopedOperations_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IScopedOperations_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IScopedOperations_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IScopedOperations_Bind(This,pUnkOuter,pwszURL,dwBindURLFlags,rguid,riid,pAuthenticate,pImplSession,pdwBindStatus,ppUnk)	\
    (This)->lpVtbl -> Bind(This,pUnkOuter,pwszURL,dwBindURLFlags,rguid,riid,pAuthenticate,pImplSession,pdwBindStatus,ppUnk)


#define IScopedOperations_Copy(This,cRows,rgpwszSourceURLs,rgpwszDestURLs,dwCopyFlags,pAuthenticate,rgdwStatus,rgpwszNewURLs,ppStringsBuffer)	\
    (This)->lpVtbl -> Copy(This,cRows,rgpwszSourceURLs,rgpwszDestURLs,dwCopyFlags,pAuthenticate,rgdwStatus,rgpwszNewURLs,ppStringsBuffer)

#define IScopedOperations_Move(This,cRows,rgpwszSourceURLs,rgpwszDestURLs,dwMoveFlags,pAuthenticate,rgdwStatus,rgpwszNewURLs,ppStringsBuffer)	\
    (This)->lpVtbl -> Move(This,cRows,rgpwszSourceURLs,rgpwszDestURLs,dwMoveFlags,pAuthenticate,rgdwStatus,rgpwszNewURLs,ppStringsBuffer)

#define IScopedOperations_Delete(This,cRows,rgpwszURLs,dwDeleteFlags,rgdwStatus)	\
    (This)->lpVtbl -> Delete(This,cRows,rgpwszURLs,dwDeleteFlags,rgdwStatus)

#define IScopedOperations_OpenRowset(This,pUnkOuter,pTableID,pIndexID,riid,cPropertySets,rgPropertySets,ppRowset)	\
    (This)->lpVtbl -> OpenRowset(This,pUnkOuter,pTableID,pIndexID,riid,cPropertySets,rgPropertySets,ppRowset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IScopedOperations_RemoteCopy_Proxy( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszSourceURLs,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszDestURLs,
    /* [in] */ DWORD dwCopyFlags,
    /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [size_is][out] */ DBSTATUS __RPC_FAR *rgdwStatus,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgulNewURLOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbStringsBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);


void __RPC_STUB IScopedOperations_RemoteCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IScopedOperations_RemoteMove_Proxy( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszSourceURLs,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszDestURLs,
    /* [in] */ DWORD dwMoveFlags,
    /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [size_is][out] */ DBSTATUS __RPC_FAR *rgdwStatus,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgulNewURLOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbStringsBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);


void __RPC_STUB IScopedOperations_RemoteMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IScopedOperations_RemoteDelete_Proxy( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszURLs,
    /* [in] */ DWORD dwDeleteFlags,
    /* [size_is][out] */ DBSTATUS __RPC_FAR *rgdwStatus);


void __RPC_STUB IScopedOperations_RemoteDelete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IScopedOperations_RemoteOpenRowset_Proxy( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus);


void __RPC_STUB IScopedOperations_RemoteOpenRowset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IScopedOperations_INTERFACE_DEFINED__ */


#ifndef __ICreateRow_INTERFACE_DEFINED__
#define __ICreateRow_INTERFACE_DEFINED__

/* interface ICreateRow */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ICreateRow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733ab2-2a1c-11ce-ade5-00aa0044773d")
    ICreateRow : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateRow( 
            /* [unique][in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ LPCOLESTR pwszURL,
            /* [in] */ DBBINDURLFLAG dwBindURLFlags,
            /* [in] */ REFGUID rguid,
            /* [in] */ REFIID riid,
            /* [unique][in] */ IAuthenticate __RPC_FAR *pAuthenticate,
            /* [unique][out][in] */ DBIMPLICITSESSION __RPC_FAR *pImplSession,
            /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
            /* [out] */ LPOLESTR __RPC_FAR *ppwszNewURL,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICreateRowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICreateRow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICreateRow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICreateRow __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateRow )( 
            ICreateRow __RPC_FAR * This,
            /* [unique][in] */ IUnknown __RPC_FAR *pUnkOuter,
            /* [in] */ LPCOLESTR pwszURL,
            /* [in] */ DBBINDURLFLAG dwBindURLFlags,
            /* [in] */ REFGUID rguid,
            /* [in] */ REFIID riid,
            /* [unique][in] */ IAuthenticate __RPC_FAR *pAuthenticate,
            /* [unique][out][in] */ DBIMPLICITSESSION __RPC_FAR *pImplSession,
            /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
            /* [out] */ LPOLESTR __RPC_FAR *ppwszNewURL,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);
        
        END_INTERFACE
    } ICreateRowVtbl;

    interface ICreateRow
    {
        CONST_VTBL struct ICreateRowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICreateRow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICreateRow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICreateRow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICreateRow_CreateRow(This,pUnkOuter,pwszURL,dwBindURLFlags,rguid,riid,pAuthenticate,pImplSession,pdwBindStatus,ppwszNewURL,ppUnk)	\
    (This)->lpVtbl -> CreateRow(This,pUnkOuter,pwszURL,dwBindURLFlags,rguid,riid,pAuthenticate,pImplSession,pdwBindStatus,ppwszNewURL,ppUnk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ICreateRow_RemoteCreateRow_Proxy( 
    ICreateRow __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ LPCOLESTR pwszURL,
    /* [in] */ DBBINDURLFLAG dwBindURLFlags,
    /* [in] */ REFGUID rguid,
    /* [in] */ REFIID riid,
    /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [in] */ IUnknown __RPC_FAR *pSessionUnkOuter,
    /* [unique][in] */ IID __RPC_FAR *piid,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession,
    /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
    /* [unique][out][in] */ LPOLESTR __RPC_FAR *ppwszNewURL,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);


void __RPC_STUB ICreateRow_RemoteCreateRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICreateRow_INTERFACE_DEFINED__ */


#ifndef __IDBBinderProperties_INTERFACE_DEFINED__
#define __IDBBinderProperties_INTERFACE_DEFINED__

/* interface IDBBinderProperties */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDBBinderProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733ab3-2a1c-11ce-ade5-00aa0044773d")
    IDBBinderProperties : public IDBProperties
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBBinderPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBBinderProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBBinderProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBBinderProperties __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProperties )( 
            IDBBinderProperties __RPC_FAR * This,
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropertyInfo )( 
            IDBBinderProperties __RPC_FAR * This,
            /* [in] */ ULONG cPropertyIDSets,
            /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
            /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
            /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProperties )( 
            IDBBinderProperties __RPC_FAR * This,
            /* [in] */ ULONG cPropertySets,
            /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IDBBinderProperties __RPC_FAR * This);
        
        END_INTERFACE
    } IDBBinderPropertiesVtbl;

    interface IDBBinderProperties
    {
        CONST_VTBL struct IDBBinderPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBBinderProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBBinderProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBBinderProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBBinderProperties_GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)	\
    (This)->lpVtbl -> GetProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertySets,prgPropertySets)

#define IDBBinderProperties_GetPropertyInfo(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)	\
    (This)->lpVtbl -> GetPropertyInfo(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)

#define IDBBinderProperties_SetProperties(This,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> SetProperties(This,cPropertySets,rgPropertySets)


#define IDBBinderProperties_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDBBinderProperties_Reset_Proxy( 
    IDBBinderProperties __RPC_FAR * This);


void __RPC_STUB IDBBinderProperties_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBBinderProperties_INTERFACE_DEFINED__ */


#ifndef __IColumnsInfo2_INTERFACE_DEFINED__
#define __IColumnsInfo2_INTERFACE_DEFINED__

/* interface IColumnsInfo2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IColumnsInfo2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733ab8-2a1c-11ce-ade5-00aa0044773d")
    IColumnsInfo2 : public IColumnsInfo
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetRestrictedColumnInfo( 
            /* [in] */ DBORDINAL cColumnIDMasks,
            /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDMasks[  ],
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
            /* [size_is][size_is][out] */ DBID __RPC_FAR *__RPC_FAR *prgColumnIDs,
            /* [size_is][size_is][out] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgColumnInfo,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IColumnsInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IColumnsInfo2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IColumnsInfo2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IColumnsInfo2 __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColumnInfo )( 
            IColumnsInfo2 __RPC_FAR * This,
            /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
            /* [size_is][size_is][out] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgInfo,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MapColumnIDs )( 
            IColumnsInfo2 __RPC_FAR * This,
            /* [in] */ DBORDINAL cColumnIDs,
            /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDs[  ],
            /* [size_is][out] */ DBORDINAL __RPC_FAR rgColumns[  ]);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRestrictedColumnInfo )( 
            IColumnsInfo2 __RPC_FAR * This,
            /* [in] */ DBORDINAL cColumnIDMasks,
            /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDMasks[  ],
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
            /* [size_is][size_is][out] */ DBID __RPC_FAR *__RPC_FAR *prgColumnIDs,
            /* [size_is][size_is][out] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgColumnInfo,
            /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);
        
        END_INTERFACE
    } IColumnsInfo2Vtbl;

    interface IColumnsInfo2
    {
        CONST_VTBL struct IColumnsInfo2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IColumnsInfo2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IColumnsInfo2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IColumnsInfo2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IColumnsInfo2_GetColumnInfo(This,pcColumns,prgInfo,ppStringsBuffer)	\
    (This)->lpVtbl -> GetColumnInfo(This,pcColumns,prgInfo,ppStringsBuffer)

#define IColumnsInfo2_MapColumnIDs(This,cColumnIDs,rgColumnIDs,rgColumns)	\
    (This)->lpVtbl -> MapColumnIDs(This,cColumnIDs,rgColumnIDs,rgColumns)


#define IColumnsInfo2_GetRestrictedColumnInfo(This,cColumnIDMasks,rgColumnIDMasks,dwFlags,pcColumns,prgColumnIDs,prgColumnInfo,ppStringsBuffer)	\
    (This)->lpVtbl -> GetRestrictedColumnInfo(This,cColumnIDMasks,rgColumnIDMasks,dwFlags,pcColumns,prgColumnIDs,prgColumnInfo,ppStringsBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsInfo2_RemoteGetRestrictedColumnInfo_Proxy( 
    IColumnsInfo2 __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumnIDMasks,
    /* [size_is][unique][in] */ const DBID __RPC_FAR *rgColumnIDMasks,
    /* [in] */ DWORD dwFlags,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
    /* [size_is][size_is][unique][out][in] */ DBID __RPC_FAR *__RPC_FAR *prgColumnIDs,
    /* [size_is][size_is][unique][out][in] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgColumnInfo,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgNameOffsets,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgcolumnidOffsets,
    /* [out][in] */ DBLENGTH __RPC_FAR *pcbStringsBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);


void __RPC_STUB IColumnsInfo2_RemoteGetRestrictedColumnInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IColumnsInfo2_INTERFACE_DEFINED__ */


#ifndef __IRegisterProvider_INTERFACE_DEFINED__
#define __IRegisterProvider_INTERFACE_DEFINED__

/* interface IRegisterProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRegisterProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733ab9-2a1c-11ce-ade5-00aa0044773d")
    IRegisterProvider : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetURLMapping( 
            /* [in] */ LPCOLESTR pwszURL,
            /* [in] */ DB_DWRESERVE dwReserved,
            /* [out] */ CLSID __RPC_FAR *pclsidProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetURLMapping( 
            /* [unique][in] */ LPCOLESTR pwszURL,
            /* [in] */ DB_DWRESERVE dwReserved,
            /* [unique][in] */ REFCLSID rclsidProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterProvider( 
            /* [unique][in] */ LPCOLESTR pwszURL,
            /* [in] */ DB_DWRESERVE dwReserved,
            /* [unique][in] */ REFCLSID rclsidProvider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRegisterProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRegisterProvider __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRegisterProvider __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRegisterProvider __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetURLMapping )( 
            IRegisterProvider __RPC_FAR * This,
            /* [in] */ LPCOLESTR pwszURL,
            /* [in] */ DB_DWRESERVE dwReserved,
            /* [out] */ CLSID __RPC_FAR *pclsidProvider);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetURLMapping )( 
            IRegisterProvider __RPC_FAR * This,
            /* [unique][in] */ LPCOLESTR pwszURL,
            /* [in] */ DB_DWRESERVE dwReserved,
            /* [unique][in] */ REFCLSID rclsidProvider);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnregisterProvider )( 
            IRegisterProvider __RPC_FAR * This,
            /* [unique][in] */ LPCOLESTR pwszURL,
            /* [in] */ DB_DWRESERVE dwReserved,
            /* [unique][in] */ REFCLSID rclsidProvider);
        
        END_INTERFACE
    } IRegisterProviderVtbl;

    interface IRegisterProvider
    {
        CONST_VTBL struct IRegisterProviderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRegisterProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRegisterProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRegisterProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRegisterProvider_GetURLMapping(This,pwszURL,dwReserved,pclsidProvider)	\
    (This)->lpVtbl -> GetURLMapping(This,pwszURL,dwReserved,pclsidProvider)

#define IRegisterProvider_SetURLMapping(This,pwszURL,dwReserved,rclsidProvider)	\
    (This)->lpVtbl -> SetURLMapping(This,pwszURL,dwReserved,rclsidProvider)

#define IRegisterProvider_UnregisterProvider(This,pwszURL,dwReserved,rclsidProvider)	\
    (This)->lpVtbl -> UnregisterProvider(This,pwszURL,dwReserved,rclsidProvider)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IRegisterProvider_RemoteGetURLMapping_Proxy( 
    IRegisterProvider __RPC_FAR * This,
    /* [in] */ LPCOLESTR pwszURL,
    /* [in] */ DB_DWRESERVE dwReserved,
    /* [out] */ CLSID __RPC_FAR *pclsidProvider);


void __RPC_STUB IRegisterProvider_RemoteGetURLMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRegisterProvider_SetURLMapping_Proxy( 
    IRegisterProvider __RPC_FAR * This,
    /* [unique][in] */ LPCOLESTR pwszURL,
    /* [in] */ DB_DWRESERVE dwReserved,
    /* [unique][in] */ REFCLSID rclsidProvider);


void __RPC_STUB IRegisterProvider_SetURLMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRegisterProvider_UnregisterProvider_Proxy( 
    IRegisterProvider __RPC_FAR * This,
    /* [unique][in] */ LPCOLESTR pwszURL,
    /* [in] */ DB_DWRESERVE dwReserved,
    /* [unique][in] */ REFCLSID rclsidProvider);


void __RPC_STUB IRegisterProvider_UnregisterProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRegisterProvider_INTERFACE_DEFINED__ */


#ifndef __IGetSession_INTERFACE_DEFINED__
#define __IGetSession_INTERFACE_DEFINED__

/* interface IGetSession */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IGetSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733aba-2a1c-11ce-ade5-00aa0044773d")
    IGetSession : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSession( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGetSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGetSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGetSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSession )( 
            IGetSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession);
        
        END_INTERFACE
    } IGetSessionVtbl;

    interface IGetSession
    {
        CONST_VTBL struct IGetSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGetSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGetSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGetSession_GetSession(This,riid,ppSession)	\
    (This)->lpVtbl -> GetSession(This,riid,ppSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGetSession_GetSession_Proxy( 
    IGetSession __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession);


void __RPC_STUB IGetSession_GetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGetSession_INTERFACE_DEFINED__ */


#ifndef __IGetSourceRow_INTERFACE_DEFINED__
#define __IGetSourceRow_INTERFACE_DEFINED__

/* interface IGetSourceRow */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IGetSourceRow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733abb-2a1c-11ce-ade5-00aa0044773d")
    IGetSourceRow : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSourceRow( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRow) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetSourceRowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGetSourceRow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGetSourceRow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGetSourceRow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourceRow )( 
            IGetSourceRow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRow);
        
        END_INTERFACE
    } IGetSourceRowVtbl;

    interface IGetSourceRow
    {
        CONST_VTBL struct IGetSourceRowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetSourceRow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGetSourceRow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGetSourceRow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGetSourceRow_GetSourceRow(This,riid,ppRow)	\
    (This)->lpVtbl -> GetSourceRow(This,riid,ppRow)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGetSourceRow_GetSourceRow_Proxy( 
    IGetSourceRow __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRow);


void __RPC_STUB IGetSourceRow_GetSourceRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGetSourceRow_INTERFACE_DEFINED__ */


#ifndef __IRowsetCurrentIndex_INTERFACE_DEFINED__
#define __IRowsetCurrentIndex_INTERFACE_DEFINED__

/* interface IRowsetCurrentIndex */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IRowsetCurrentIndex;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733abd-2a1c-11ce-ade5-00aa0044773d")
    IRowsetCurrentIndex : public IRowsetIndex
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetIndex( 
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppIndexID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIndex( 
            /* [in] */ DBID __RPC_FAR *pIndexID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRowsetCurrentIndexVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRowsetCurrentIndex __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRowsetCurrentIndex __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRowsetCurrentIndex __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIndexInfo )( 
            IRowsetCurrentIndex __RPC_FAR * This,
            /* [out][in] */ DBORDINAL __RPC_FAR *pcKeyColumns,
            /* [size_is][size_is][out] */ DBINDEXCOLUMNDESC __RPC_FAR *__RPC_FAR *prgIndexColumnDesc,
            /* [out][in] */ ULONG __RPC_FAR *pcIndexProperties,
            /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgIndexProperties);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Seek )( 
            IRowsetCurrentIndex __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBORDINAL cKeyValues,
            /* [in] */ void __RPC_FAR *pData,
            /* [in] */ DBSEEK dwSeekOptions);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRange )( 
            IRowsetCurrentIndex __RPC_FAR * This,
            /* [in] */ HACCESSOR hAccessor,
            /* [in] */ DBORDINAL cStartKeyColumns,
            /* [in] */ void __RPC_FAR *pStartData,
            /* [in] */ DBORDINAL cEndKeyColumns,
            /* [in] */ void __RPC_FAR *pEndData,
            /* [in] */ DBRANGE dwRangeOptions);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIndex )( 
            IRowsetCurrentIndex __RPC_FAR * This,
            /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppIndexID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIndex )( 
            IRowsetCurrentIndex __RPC_FAR * This,
            /* [in] */ DBID __RPC_FAR *pIndexID);
        
        END_INTERFACE
    } IRowsetCurrentIndexVtbl;

    interface IRowsetCurrentIndex
    {
        CONST_VTBL struct IRowsetCurrentIndexVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetCurrentIndex_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRowsetCurrentIndex_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRowsetCurrentIndex_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRowsetCurrentIndex_GetIndexInfo(This,pcKeyColumns,prgIndexColumnDesc,pcIndexProperties,prgIndexProperties)	\
    (This)->lpVtbl -> GetIndexInfo(This,pcKeyColumns,prgIndexColumnDesc,pcIndexProperties,prgIndexProperties)

#define IRowsetCurrentIndex_Seek(This,hAccessor,cKeyValues,pData,dwSeekOptions)	\
    (This)->lpVtbl -> Seek(This,hAccessor,cKeyValues,pData,dwSeekOptions)

#define IRowsetCurrentIndex_SetRange(This,hAccessor,cStartKeyColumns,pStartData,cEndKeyColumns,pEndData,dwRangeOptions)	\
    (This)->lpVtbl -> SetRange(This,hAccessor,cStartKeyColumns,pStartData,cEndKeyColumns,pEndData,dwRangeOptions)


#define IRowsetCurrentIndex_GetIndex(This,ppIndexID)	\
    (This)->lpVtbl -> GetIndex(This,ppIndexID)

#define IRowsetCurrentIndex_SetIndex(This,pIndexID)	\
    (This)->lpVtbl -> SetIndex(This,pIndexID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRowsetCurrentIndex_GetIndex_Proxy( 
    IRowsetCurrentIndex __RPC_FAR * This,
    /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppIndexID);


void __RPC_STUB IRowsetCurrentIndex_GetIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRowsetCurrentIndex_SetIndex_Proxy( 
    IRowsetCurrentIndex __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pIndexID);


void __RPC_STUB IRowsetCurrentIndex_SetIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRowsetCurrentIndex_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oledb_0343 */
/* [local] */ 

#endif // OLEDBVER >= 0x0210
//@@@- V2.1
//
// IID values
//

// IID_IAccessor                 = {0x0c733a8c,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowset                   = {0x0c733a7c,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetInfo               = {0x0c733a55,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetLocate             = {0x0c733a7d,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetResynch            = {0x0c733a84,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetScroll             = {0x0c733a7e,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetChange             = {0x0c733a05,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetUpdate             = {0x0c733a6d,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetIdentity           = {0x0c733a09,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetNotify             = {0x0c733a83,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetIndex              = {0x0c733a82,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ICommand                  = {0x0c733a63,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IMultipleResults          = {0x0c733a90,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IConvertType              = {0x0c733a88,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ICommandPrepare           = {0x0c733a26,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ICommandProperties        = {0x0c733a79,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ICommandText              = {0x0c733a27,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ICommandWithParameters    = {0x0c733a64,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IColumnsRowset            = {0x0c733a10,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IColumnsInfo              = {0x0c733a11,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IDBCreateCommand          = {0x0c733a1d,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IDBCreateSession          = {0x0c733a5d,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ISourcesRowset            = {0x0c733a1e,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IDBProperties             = {0x0c733a8a,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IDBInitialize             = {0x0c733a8b,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IDBInfo                   = {0x0c733a89,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IDBDataSourceAdmin        = {0x0c733a7a,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ISessionProperties        = {0x0c733a85,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IIndexDefinition          = {0x0c733a68,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ITableDefinition          = {0x0c733a86,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IOpenRowset               = {0x0c733a69,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IDBSchemaRowset           = {0x0c733a7b,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IErrorRecords             = {0x0c733a67,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IErrorLookup              = {0x0c733a66,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ISQLErrorInfo             = {0x0c733a74,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IGetDataSource            = {0x0c733a75,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ITransactionLocal         = {0x0c733a5f,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ITransactionJoin          = {0x0c733a5e,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ITransactionObject        = {0x0c733a60,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//@@@+ V1.5
#if( OLEDBVER >= 0x0150 )
//IID_IChapteredRowset           = {0x0c733a93,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//IID_IDBAsynchNotify            = {0x0c733a96,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//IID_IDBAsynchStatus            = {0x0c733a95,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//IID_IRowsetFind                = {0x0c733a9d,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//IID_IRowPosition               = {0x0c733a94,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//IID_IRowPositionChange         = {0x0997a571,0x126e,0x11d0,{0x9f,0x8a,0x00,0xa0,0xc9,0xa0,0x63,0x1e}}
//IID_IViewRowset                = {0x0c733a97,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//IID_IViewChapter               = {0x0c733a98,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//IID_IViewSort                  = {0x0c733a9a,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//IID_IViewFilter                = {0x0c733a9b,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
//IID_IRowsetView                = {0x0c733a99,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
#endif // OLEDBVER >= 0x0150
//@@@- V1.5
//@@@+ V2.0
#if( OLEDBVER >= 0x0200 )
// IID_IMDDataset                = {0xa07cccd1,0x8148,0x11d0,{0x87,0xbb,0x00,0xc0,0x4f,0xc3,0x39,0x42}}
// IID_IMDFind                   = {0xa07cccd2,0x8148,0x11d0,{0x87,0xbb,0x00,0xc0,0x4f,0xc3,0x39,0x42}}
// IID_IMDRangeRowset            = {0x0c733aa0,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IAlterTable               = {0x0c733aa5,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IAlterIndex               = {0x0c733aa6,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ICommandPersist           = {0x0c733aa7,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetChapterMember      = {0x0c733aa8,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetRefresh            = {0x0c733aa9,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IParentRowset             = {0x0c733aaa,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
#endif // OLEDBVER >= 0x0200
//@@@- V2.0
//@@@+ V2.1
#if( OLEDBVER >= 0x0210 )
// IID_ITrusteeAdmin				= {0c733aa1,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ITrusteeGroupAdmin		= {0c733aa2,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IObjectAccessControl		= {0c733aa3,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ISecurityInfo				= {0c733aa4,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRow						= {0c733ab4,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowChange				= {0c733ab5,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowSchemaChange			= {0c733aae,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IGetRow					= {0c733aaf,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IScopedOperations			= {0c733ab0,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IBindResource				= {0c733ab1,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ICreateRow				= {0c733ab2,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IDBResetProperties		= {0c733ab3,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IColumnsInfo2				= {0c733ab8,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRegisterProvider 		= {0c733ab9,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IGetSession		 		= {0c733aba,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IGetSourceRow		 		= {0c733abb,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_ITableCreation	 		= {0c733abc,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
// IID_IRowsetCurrentIndex 		= {0c733abd,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
#endif // OLEDBVER >= 0x0210
//@@@- V2.1
#include <poppack.h>     // restore original structure packing


extern RPC_IF_HANDLE __MIDL_itf_oledb_0343_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oledb_0343_v0_0_s_ifspec;

#ifdef OLEDBPROXY
/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long __RPC_FAR *, unsigned long            , LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* [local] */ HRESULT STDMETHODCALLTYPE IAccessor_AddRefAccessor_Proxy( 
    IAccessor __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IAccessor_AddRefAccessor_Stub( 
    IAccessor __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IAccessor_CreateAccessor_Proxy( 
    IAccessor __RPC_FAR * This,
    /* [in] */ DBACCESSORFLAGS dwAccessorFlags,
    /* [in] */ DBCOUNTITEM cBindings,
    /* [size_is][in] */ const DBBINDING __RPC_FAR rgBindings[  ],
    /* [in] */ DBLENGTH cbRowSize,
    /* [out] */ HACCESSOR __RPC_FAR *phAccessor,
    /* [size_is][out] */ DBBINDSTATUS __RPC_FAR rgStatus[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IAccessor_CreateAccessor_Stub( 
    IAccessor __RPC_FAR * This,
    /* [in] */ DBACCESSORFLAGS dwAccessorFlags,
    /* [in] */ DBCOUNTITEM cBindings,
    /* [size_is][unique][in] */ DBBINDING __RPC_FAR *rgBindings,
    /* [in] */ DBLENGTH cbRowSize,
    /* [out] */ HACCESSOR __RPC_FAR *phAccessor,
    /* [size_is][unique][out][in] */ DBBINDSTATUS __RPC_FAR *rgStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IAccessor_GetBindings_Proxy( 
    IAccessor __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [out] */ DBACCESSORFLAGS __RPC_FAR *pdwAccessorFlags,
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcBindings,
    /* [size_is][size_is][out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IAccessor_GetBindings_Stub( 
    IAccessor __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [out] */ DBACCESSORFLAGS __RPC_FAR *pdwAccessorFlags,
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcBindings,
    /* [size_is][size_is][out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IAccessor_ReleaseAccessor_Proxy( 
    IAccessor __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IAccessor_ReleaseAccessor_Stub( 
    IAccessor __RPC_FAR * This,
    /* [in] */ HACCESSOR hAccessor,
    /* [unique][out][in] */ DBREFCOUNT __RPC_FAR *pcRefCount,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowsetInfo_GetProperties_Proxy( 
    IRowsetInfo __RPC_FAR * This,
    /* [in] */ const ULONG cPropertyIDSets,
    /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetInfo_GetProperties_Stub( 
    IRowsetInfo __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowsetInfo_GetReferencedRowset_Proxy( 
    IRowsetInfo __RPC_FAR * This,
    /* [in] */ DBORDINAL iOrdinal,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppReferencedRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetInfo_GetReferencedRowset_Stub( 
    IRowsetInfo __RPC_FAR * This,
    /* [in] */ DBORDINAL iOrdinal,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppReferencedRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowsetInfo_GetSpecification_Proxy( 
    IRowsetInfo __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSpecification);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetInfo_GetSpecification_Stub( 
    IRowsetInfo __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSpecification,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IChapteredRowset_AddRefChapter_Proxy( 
    IChapteredRowset __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IChapteredRowset_AddRefChapter_Stub( 
    IChapteredRowset __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IChapteredRowset_ReleaseChapter_Proxy( 
    IChapteredRowset __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IChapteredRowset_ReleaseChapter_Stub( 
    IChapteredRowset __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [out] */ DBREFCOUNT __RPC_FAR *pcRefCount,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowPosition_ClearRowPosition_Proxy( 
    IRowPosition __RPC_FAR * This);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_ClearRowPosition_Stub( 
    IRowPosition __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowPosition_GetRowPosition_Proxy( 
    IRowPosition __RPC_FAR * This,
    /* [out] */ HCHAPTER __RPC_FAR *phChapter,
    /* [out] */ HROW __RPC_FAR *phRow,
    /* [out] */ DBPOSITIONFLAGS __RPC_FAR *pdwPositionFlags);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_GetRowPosition_Stub( 
    IRowPosition __RPC_FAR * This,
    /* [out] */ HCHAPTER __RPC_FAR *phChapter,
    /* [out] */ HROW __RPC_FAR *phRow,
    /* [out] */ DBPOSITIONFLAGS __RPC_FAR *pdwPositionFlags,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowPosition_GetRowset_Proxy( 
    IRowPosition __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_GetRowset_Stub( 
    IRowPosition __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowPosition_Initialize_Proxy( 
    IRowPosition __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_Initialize_Stub( 
    IRowPosition __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowPosition_SetRowPosition_Proxy( 
    IRowPosition __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ HROW hRow,
    /* [in] */ DBPOSITIONFLAGS dwPositionFlags);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPosition_SetRowPosition_Stub( 
    IRowPosition __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ HROW hRow,
    /* [in] */ DBPOSITIONFLAGS dwPositionFlags,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowPositionChange_OnRowPositionChange_Proxy( 
    IRowPositionChange __RPC_FAR * This,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowPositionChange_OnRowPositionChange_Stub( 
    IRowPositionChange __RPC_FAR * This,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewRowset_GetSpecification_Proxy( 
    IViewRowset __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewRowset_GetSpecification_Stub( 
    IViewRowset __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewRowset_OpenViewRowset_Proxy( 
    IViewRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewRowset_OpenViewRowset_Stub( 
    IViewRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewChapter_GetSpecification_Proxy( 
    IViewChapter __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewChapter_GetSpecification_Stub( 
    IViewChapter __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewChapter_OpenViewChapter_Proxy( 
    IViewChapter __RPC_FAR * This,
    /* [in] */ HCHAPTER hSource,
    /* [out] */ HCHAPTER __RPC_FAR *phViewChapter);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewChapter_OpenViewChapter_Stub( 
    IViewChapter __RPC_FAR * This,
    /* [in] */ HCHAPTER hSource,
    /* [out] */ HCHAPTER __RPC_FAR *phViewChapter,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewSort_GetSortOrder_Proxy( 
    IViewSort __RPC_FAR * This,
    /* [out] */ DBORDINAL __RPC_FAR *pcValues,
    /* [out] */ DBORDINAL __RPC_FAR *__RPC_FAR prgColumns[  ],
    /* [out] */ DBSORT __RPC_FAR *__RPC_FAR prgOrders[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewSort_GetSortOrder_Stub( 
    IViewSort __RPC_FAR * This,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcValues,
    /* [size_is][size_is][out] */ DBORDINAL __RPC_FAR *__RPC_FAR *prgColumns,
    /* [size_is][size_is][out] */ DBORDINAL __RPC_FAR *__RPC_FAR *prgOrders,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewSort_SetSortOrder_Proxy( 
    IViewSort __RPC_FAR * This,
    /* [in] */ DBORDINAL cValues,
    /* [size_is][in] */ const DBORDINAL __RPC_FAR rgColumns[  ],
    /* [size_is][in] */ const DBSORT __RPC_FAR rgOrders[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewSort_SetSortOrder_Stub( 
    IViewSort __RPC_FAR * This,
    /* [in] */ DBORDINAL cValues,
    /* [size_is][in] */ const DBORDINAL __RPC_FAR *rgColumns,
    /* [size_is][in] */ const DBSORT __RPC_FAR *rgOrders,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewFilter_GetFilterBindings_Proxy( 
    IViewFilter __RPC_FAR * This,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pcBindings,
    /* [out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewFilter_GetFilterBindings_Stub( 
    IViewFilter __RPC_FAR * This,
    /* [out][in] */ DBCOUNTITEM __RPC_FAR *pcBindings,
    /* [size_is][size_is][out] */ DBBINDING __RPC_FAR *__RPC_FAR *prgBindings,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowsetView_CreateView_Proxy( 
    IRowsetView __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetView_CreateView_Stub( 
    IRowsetView __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowsetView_GetView_Proxy( 
    IRowsetView __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ REFIID riid,
    /* [out] */ HCHAPTER __RPC_FAR *phChapterSource,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetView_GetView_Stub( 
    IRowsetView __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ REFIID riid,
    /* [out] */ HCHAPTER __RPC_FAR *phChapterSource,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppView,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowsetIdentity_IsSameRow_Proxy( 
    IRowsetIdentity __RPC_FAR * This,
    /* [in] */ HROW hThisRow,
    /* [in] */ HROW hThatRow);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetIdentity_IsSameRow_Stub( 
    IRowsetIdentity __RPC_FAR * This,
    /* [in] */ HROW hThisRow,
    /* [in] */ HROW hThatRow,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowsetNotify_OnFieldChange_Proxy( 
    IRowsetNotify __RPC_FAR * This,
    /* [in] */ IRowset __RPC_FAR *pRowset,
    /* [in] */ HROW hRow,
    /* [in] */ DBORDINAL cColumns,
    /* [size_is][in] */ DBORDINAL __RPC_FAR rgColumns[  ],
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetNotify_OnFieldChange_Stub( 
    IRowsetNotify __RPC_FAR * This,
    /* [in] */ IRowset __RPC_FAR *pRowset,
    /* [in] */ HROW hRow,
    /* [in] */ DBORDINAL cColumns,
    /* [size_is][in] */ DBORDINAL __RPC_FAR *rgColumns,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowsetNotify_OnRowChange_Proxy( 
    IRowsetNotify __RPC_FAR * This,
    /* [in] */ IRowset __RPC_FAR *pRowset,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR rghRows[  ],
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetNotify_OnRowChange_Stub( 
    IRowsetNotify __RPC_FAR * This,
    /* [in] */ IRowset __RPC_FAR *pRowset,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ const HROW __RPC_FAR *rghRows,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);

/* [local] */ HRESULT STDMETHODCALLTYPE IRowsetNotify_OnRowsetChange_Proxy( 
    IRowsetNotify __RPC_FAR * This,
    /* [in] */ IRowset __RPC_FAR *pRowset,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRowsetNotify_OnRowsetChange_Stub( 
    IRowsetNotify __RPC_FAR * This,
    /* [in] */ IRowset __RPC_FAR *pRowset,
    /* [in] */ DBREASON eReason,
    /* [in] */ DBEVENTPHASE ePhase,
    /* [in] */ BOOL fCantDeny);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommand_Cancel_Proxy( 
    ICommand __RPC_FAR * This);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommand_Cancel_Stub( 
    ICommand __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommand_Execute_Proxy( 
    ICommand __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [out][in] */ DBPARAMS __RPC_FAR *pParams,
    /* [out] */ DBROWCOUNT __RPC_FAR *pcRowsAffected,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommand_Execute_Stub( 
    ICommand __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [in] */ HACCESSOR hAccessor,
    /* [in] */ ULONG cParamSets,
    /* [unique][in] */ GUID __RPC_FAR *pGuid,
    /* [in] */ ULONG ulGuidOffset,
    /* [unique][in] */ RMTPACK __RPC_FAR *pInputParams,
    /* [unique][out][in] */ RMTPACK __RPC_FAR *pOutputParams,
    /* [in] */ ULONG cBindings,
    /* [size_is][unique][in] */ DBBINDING __RPC_FAR *rgBindings,
    /* [size_is][unique][out][in] */ DBSTATUS __RPC_FAR *rgStatus,
    /* [unique][out][in] */ LONG __RPC_FAR *pcRowsAffected,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommand_GetDBSession_Proxy( 
    ICommand __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommand_GetDBSession_Stub( 
    ICommand __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IMultipleResults_GetResult_Proxy( 
    IMultipleResults __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DB_LRESERVE reserved,
    /* [in] */ REFIID riid,
    /* [out] */ DBROWCOUNT __RPC_FAR *pcRowsAffected,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IMultipleResults_GetResult_Stub( 
    IMultipleResults __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DB_LRESERVE reserved,
    /* [in] */ REFIID riid,
    /* [unique][out][in] */ DBROWCOUNT __RPC_FAR *pcRowsAffected,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IConvertType_CanConvert_Proxy( 
    IConvertType __RPC_FAR * This,
    /* [in] */ DBTYPE wFromType,
    /* [in] */ DBTYPE wToType,
    /* [in] */ DBCONVERTFLAGS dwConvertFlags);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IConvertType_CanConvert_Stub( 
    IConvertType __RPC_FAR * This,
    /* [in] */ DBTYPE wFromType,
    /* [in] */ DBTYPE wToType,
    /* [in] */ DBCONVERTFLAGS dwConvertFlags,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommandPrepare_Prepare_Proxy( 
    ICommandPrepare __RPC_FAR * This,
    /* [in] */ ULONG cExpectedRuns);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandPrepare_Prepare_Stub( 
    ICommandPrepare __RPC_FAR * This,
    /* [in] */ ULONG cExpectedRuns,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommandPrepare_Unprepare_Proxy( 
    ICommandPrepare __RPC_FAR * This);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandPrepare_Unprepare_Stub( 
    ICommandPrepare __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommandProperties_GetProperties_Proxy( 
    ICommandProperties __RPC_FAR * This,
    /* [in] */ const ULONG cPropertyIDSets,
    /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandProperties_GetProperties_Stub( 
    ICommandProperties __RPC_FAR * This,
    /* [in] */ const ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommandProperties_SetProperties_Proxy( 
    ICommandProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandProperties_SetProperties_Stub( 
    ICommandProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommandText_GetCommandText_Proxy( 
    ICommandText __RPC_FAR * This,
    /* [out][in] */ GUID __RPC_FAR *pguidDialect,
    /* [out] */ LPOLESTR __RPC_FAR *ppwszCommand);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandText_GetCommandText_Stub( 
    ICommandText __RPC_FAR * This,
    /* [unique][out][in] */ GUID __RPC_FAR *pguidDialect,
    /* [out] */ LPOLESTR __RPC_FAR *ppwszCommand,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommandText_SetCommandText_Proxy( 
    ICommandText __RPC_FAR * This,
    /* [in] */ REFGUID rguidDialect,
    /* [unique][in] */ LPCOLESTR pwszCommand);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandText_SetCommandText_Stub( 
    ICommandText __RPC_FAR * This,
    /* [in] */ REFGUID rguidDialect,
    /* [unique][in] */ LPCOLESTR pwszCommand,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommandWithParameters_GetParameterInfo_Proxy( 
    ICommandWithParameters __RPC_FAR * This,
    /* [out][in] */ DB_UPARAMS __RPC_FAR *pcParams,
    /* [size_is][size_is][out] */ DBPARAMINFO __RPC_FAR *__RPC_FAR *prgParamInfo,
    /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppNamesBuffer);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandWithParameters_GetParameterInfo_Stub( 
    ICommandWithParameters __RPC_FAR * This,
    /* [out][in] */ DB_UPARAMS __RPC_FAR *pcParams,
    /* [size_is][size_is][out] */ DBPARAMINFO __RPC_FAR *__RPC_FAR *prgParamInfo,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgNameOffsets,
    /* [out][in] */ DBLENGTH __RPC_FAR *pcbNamesBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppNamesBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommandWithParameters_MapParameterNames_Proxy( 
    ICommandWithParameters __RPC_FAR * This,
    /* [in] */ DB_UPARAMS cParamNames,
    /* [size_is][in] */ const OLECHAR __RPC_FAR *__RPC_FAR rgParamNames[  ],
    /* [size_is][out] */ DB_LPARAMS __RPC_FAR rgParamOrdinals[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandWithParameters_MapParameterNames_Stub( 
    ICommandWithParameters __RPC_FAR * This,
    /* [in] */ DB_UPARAMS cParamNames,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgParamNames,
    /* [size_is][out] */ DB_LPARAMS __RPC_FAR *rgParamOrdinals,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ICommandWithParameters_SetParameterInfo_Proxy( 
    ICommandWithParameters __RPC_FAR * This,
    /* [in] */ DB_UPARAMS cParams,
    /* [size_is][unique][in] */ const DB_UPARAMS __RPC_FAR rgParamOrdinals[  ],
    /* [size_is][unique][in] */ const DBPARAMBINDINFO __RPC_FAR rgParamBindInfo[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICommandWithParameters_SetParameterInfo_Stub( 
    ICommandWithParameters __RPC_FAR * This,
    /* [in] */ DB_UPARAMS cParams,
    /* [size_is][unique][in] */ const DB_UPARAMS __RPC_FAR *rgParamOrdinals,
    /* [size_is][unique][in] */ const DBPARAMBINDINFO __RPC_FAR *rgParamBindInfo,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IColumnsRowset_GetAvailableColumns_Proxy( 
    IColumnsRowset __RPC_FAR * This,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcOptColumns,
    /* [size_is][size_is][out] */ DBID __RPC_FAR *__RPC_FAR *prgOptColumns);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsRowset_GetAvailableColumns_Stub( 
    IColumnsRowset __RPC_FAR * This,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcOptColumns,
    /* [size_is][size_is][out] */ DBID __RPC_FAR *__RPC_FAR *prgOptColumns,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IColumnsRowset_GetColumnsRowset_Proxy( 
    IColumnsRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DBORDINAL cOptColumns,
    /* [size_is][in] */ const DBID __RPC_FAR rgOptColumns[  ],
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppColRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsRowset_GetColumnsRowset_Stub( 
    IColumnsRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DBORDINAL cOptColumns,
    /* [size_is][unique][in] */ const DBID __RPC_FAR *rgOptColumns,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppColRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IColumnsInfo_GetColumnInfo_Proxy( 
    IColumnsInfo __RPC_FAR * This,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
    /* [size_is][size_is][out] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgInfo,
    /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsInfo_GetColumnInfo_Stub( 
    IColumnsInfo __RPC_FAR * This,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
    /* [size_is][size_is][out] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgInfo,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgNameOffsets,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgcolumnidOffsets,
    /* [out][in] */ DBLENGTH __RPC_FAR *pcbStringsBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IColumnsInfo_MapColumnIDs_Proxy( 
    IColumnsInfo __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumnIDs,
    /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDs[  ],
    /* [size_is][out] */ DBORDINAL __RPC_FAR rgColumns[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsInfo_MapColumnIDs_Stub( 
    IColumnsInfo __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumnIDs,
    /* [size_is][in] */ const DBID __RPC_FAR *rgColumnIDs,
    /* [size_is][out] */ DBORDINAL __RPC_FAR *rgColumns,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBCreateCommand_CreateCommand_Proxy( 
    IDBCreateCommand __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppCommand);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBCreateCommand_CreateCommand_Stub( 
    IDBCreateCommand __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppCommand,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBCreateSession_CreateSession_Proxy( 
    IDBCreateSession __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBCreateSession_CreateSession_Stub( 
    IDBCreateSession __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ISourcesRowset_GetSourcesRowset_Proxy( 
    ISourcesRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgProperties[  ],
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSourcesRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ISourcesRowset_GetSourcesRowset_Stub( 
    ISourcesRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgProperties,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppSourcesRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBProperties_GetProperties_Proxy( 
    IDBProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBProperties_GetProperties_Stub( 
    IDBProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBProperties_GetPropertyInfo_Proxy( 
    IDBProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
    /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
    /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
    /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBProperties_GetPropertyInfo_Stub( 
    IDBProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
    /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
    /* [out][in] */ ULONG __RPC_FAR *pcOffsets,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgDescOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbDescBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBProperties_SetProperties_Proxy( 
    IDBProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBProperties_SetProperties_Stub( 
    IDBProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBInitialize_Initialize_Proxy( 
    IDBInitialize __RPC_FAR * This);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBInitialize_Initialize_Stub( 
    IDBInitialize __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBInitialize_Uninitialize_Proxy( 
    IDBInitialize __RPC_FAR * This);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBInitialize_Uninitialize_Stub( 
    IDBInitialize __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBInfo_GetKeywords_Proxy( 
    IDBInfo __RPC_FAR * This,
    /* [out] */ LPOLESTR __RPC_FAR *ppwszKeywords);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBInfo_GetKeywords_Stub( 
    IDBInfo __RPC_FAR * This,
    /* [unique][out][in] */ LPOLESTR __RPC_FAR *ppwszKeywords,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBInfo_GetLiteralInfo_Proxy( 
    IDBInfo __RPC_FAR * This,
    /* [in] */ ULONG cLiterals,
    /* [size_is][in] */ const DBLITERAL __RPC_FAR rgLiterals[  ],
    /* [out][in] */ ULONG __RPC_FAR *pcLiteralInfo,
    /* [size_is][size_is][out] */ DBLITERALINFO __RPC_FAR *__RPC_FAR *prgLiteralInfo,
    /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppCharBuffer);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBInfo_GetLiteralInfo_Stub( 
    IDBInfo __RPC_FAR * This,
    /* [in] */ ULONG cLiterals,
    /* [size_is][unique][in] */ const DBLITERAL __RPC_FAR *rgLiterals,
    /* [out][in] */ ULONG __RPC_FAR *pcLiteralInfo,
    /* [size_is][size_is][out] */ DBLITERALINFO __RPC_FAR *__RPC_FAR *prgLiteralInfo,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgLVOffsets,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgICOffsets,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgISCOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbCharBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppCharBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_CreateDataSource_Proxy( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_CreateDataSource_Stub( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppDBSession,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_DestroyDataSource_Proxy( 
    IDBDataSourceAdmin __RPC_FAR * This);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_DestroyDataSource_Stub( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_GetCreationProperties_Proxy( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
    /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
    /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
    /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_GetCreationProperties_Stub( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertyInfoSets,
    /* [size_is][size_is][out] */ DBPROPINFOSET __RPC_FAR *__RPC_FAR *prgPropertyInfoSets,
    /* [out][in] */ ULONG __RPC_FAR *pcOffsets,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgDescOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbDescBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppDescBuffer,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_ModifyDataSource_Proxy( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBDataSourceAdmin_ModifyDataSource_Stub( 
    IDBDataSourceAdmin __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBAsynchNotify_OnLowResource_Proxy( 
    IDBAsynchNotify __RPC_FAR * This,
    /* [in] */ DB_DWRESERVE dwReserved);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchNotify_OnLowResource_Stub( 
    IDBAsynchNotify __RPC_FAR * This,
    /* [in] */ DB_DWRESERVE dwReserved);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBAsynchNotify_OnProgress_Proxy( 
    IDBAsynchNotify __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [in] */ DBCOUNTITEM ulProgress,
    /* [in] */ DBCOUNTITEM ulProgressMax,
    /* [in] */ DBASYNCHPHASE eAsynchPhase,
    /* [in] */ LPOLESTR pwszStatusText);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchNotify_OnProgress_Stub( 
    IDBAsynchNotify __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [in] */ DBCOUNTITEM ulProgress,
    /* [in] */ DBCOUNTITEM ulProgressMax,
    /* [in] */ DBASYNCHPHASE eAsynchPhase,
    /* [string][unique][in] */ LPOLESTR pwszStatusText);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBAsynchNotify_OnStop_Proxy( 
    IDBAsynchNotify __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [in] */ HRESULT hrStatus,
    /* [in] */ LPOLESTR pwszStatusText);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchNotify_OnStop_Stub( 
    IDBAsynchNotify __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [in] */ HRESULT hrStatus,
    /* [string][unique][in] */ LPOLESTR pwszStatusText);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBAsynchStatus_Abort_Proxy( 
    IDBAsynchStatus __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchStatus_Abort_Stub( 
    IDBAsynchStatus __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBAsynchStatus_GetStatus_Proxy( 
    IDBAsynchStatus __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgress,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgressMax,
    /* [out] */ DBASYNCHPHASE __RPC_FAR *peAsynchPhase,
    /* [out] */ LPOLESTR __RPC_FAR *ppwszStatusText);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBAsynchStatus_GetStatus_Stub( 
    IDBAsynchStatus __RPC_FAR * This,
    /* [in] */ HCHAPTER hChapter,
    /* [in] */ DBASYNCHOP eOperation,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgress,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pulProgressMax,
    /* [out] */ DBASYNCHPHASE __RPC_FAR *peAsynchPhase,
    /* [out] */ LPOLESTR __RPC_FAR *ppwszStatusText,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ISessionProperties_GetProperties_Proxy( 
    ISessionProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][in] */ const DBPROPIDSET __RPC_FAR rgPropertyIDSets[  ],
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ISessionProperties_GetProperties_Stub( 
    ISessionProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertyIDSets,
    /* [size_is][unique][in] */ const DBPROPIDSET __RPC_FAR *rgPropertyIDSets,
    /* [out][in] */ ULONG __RPC_FAR *pcPropertySets,
    /* [size_is][size_is][out] */ DBPROPSET __RPC_FAR *__RPC_FAR *prgPropertySets,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ISessionProperties_SetProperties_Proxy( 
    ISessionProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ISessionProperties_SetProperties_Stub( 
    ISessionProperties __RPC_FAR * This,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IIndexDefinition_CreateIndex_Proxy( 
    IIndexDefinition __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [in] */ DBID __RPC_FAR *pIndexID,
    /* [in] */ DBORDINAL cIndexColumnDescs,
    /* [size_is][in] */ const DBINDEXCOLUMNDESC __RPC_FAR rgIndexColumnDescs[  ],
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppIndexID);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IIndexDefinition_CreateIndex_Stub( 
    IIndexDefinition __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [in] */ DBORDINAL cIndexColumnDescs,
    /* [size_is][in] */ const DBINDEXCOLUMNDESC __RPC_FAR *rgIndexColumnDescs,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [unique][out][in] */ DBID __RPC_FAR *__RPC_FAR *ppIndexID,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IIndexDefinition_DropIndex_Proxy( 
    IIndexDefinition __RPC_FAR * This,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IIndexDefinition_DropIndex_Stub( 
    IIndexDefinition __RPC_FAR * This,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ITableDefinition_CreateTable_Proxy( 
    ITableDefinition __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [in] */ DBORDINAL cColumnDescs,
    /* [size_is][in] */ const DBCOLUMNDESC __RPC_FAR rgColumnDescs[  ],
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITableDefinition_CreateTable_Stub( 
    ITableDefinition __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [in] */ DBORDINAL cColumnDescs,
    /* [size_is][in] */ const DBCOLUMNDESC __RPC_FAR *rgColumnDescs,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [unique][out][in] */ DBID __RPC_FAR *__RPC_FAR *ppTableID,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ BOOL __RPC_FAR *pfTableCreated,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ITableDefinition_DropTable_Proxy( 
    ITableDefinition __RPC_FAR * This,
    /* [unique][in] */ DBID __RPC_FAR *pTableID);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITableDefinition_DropTable_Stub( 
    ITableDefinition __RPC_FAR * This,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ITableDefinition_AddColumn_Proxy( 
    ITableDefinition __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [out][in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc,
    /* [out] */ DBID __RPC_FAR *__RPC_FAR *ppColumnID);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITableDefinition_AddColumn_Stub( 
    ITableDefinition __RPC_FAR * This,
    /* [in] */ DBID __RPC_FAR *pTableID,
    /* [in] */ DBCOLUMNDESC __RPC_FAR *pColumnDesc,
    /* [unique][out][in] */ DBID __RPC_FAR *__RPC_FAR *ppColumnID,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ITableDefinition_DropColumn_Proxy( 
    ITableDefinition __RPC_FAR * This,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pColumnID);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITableDefinition_DropColumn_Stub( 
    ITableDefinition __RPC_FAR * This,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pColumnID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IOpenRowset_OpenRowset_Proxy( 
    IOpenRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IOpenRowset_OpenRowset_Stub( 
    IOpenRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBSchemaRowset_GetRowset_Proxy( 
    IDBSchemaRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFGUID rguidSchema,
    /* [in] */ ULONG cRestrictions,
    /* [size_is][in] */ const VARIANT __RPC_FAR rgRestrictions[  ],
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBSchemaRowset_GetRowset_Stub( 
    IDBSchemaRowset __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ REFGUID rguidSchema,
    /* [in] */ ULONG cRestrictions,
    /* [size_is][unique][in] */ const VARIANT __RPC_FAR *rgRestrictions,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IDBSchemaRowset_GetSchemas_Proxy( 
    IDBSchemaRowset __RPC_FAR * This,
    /* [out][in] */ ULONG __RPC_FAR *pcSchemas,
    /* [size_is][size_is][out] */ GUID __RPC_FAR *__RPC_FAR *prgSchemas,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgRestrictionSupport);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDBSchemaRowset_GetSchemas_Stub( 
    IDBSchemaRowset __RPC_FAR * This,
    /* [out][in] */ ULONG __RPC_FAR *pcSchemas,
    /* [size_is][size_is][out] */ GUID __RPC_FAR *__RPC_FAR *prgSchemas,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgRestrictionSupport,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IErrorRecords_AddErrorRecord_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ERRORINFO __RPC_FAR *pErrorInfo,
    /* [in] */ DWORD dwLookupID,
    /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
    /* [in] */ IUnknown __RPC_FAR *punkCustomError,
    /* [in] */ DWORD dwDynamicErrorID);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_AddErrorRecord_Stub( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ERRORINFO __RPC_FAR *pErrorInfo,
    /* [in] */ DWORD dwLookupID,
    /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
    /* [in] */ IUnknown __RPC_FAR *punkCustomError,
    /* [in] */ DWORD dwDynamicErrorID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetBasicErrorInfo_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [out] */ ERRORINFO __RPC_FAR *pErrorInfo);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetBasicErrorInfo_Stub( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [out] */ ERRORINFO __RPC_FAR *pErrorInfo,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetCustomErrorObject_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetCustomErrorObject_Stub( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppObject,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetErrorInfo_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [in] */ LCID lcid,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfo);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetErrorInfo_Stub( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [in] */ LCID lcid,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfo,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetErrorParameters_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [out] */ DISPPARAMS __RPC_FAR *pdispparams);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetErrorParameters_Stub( 
    IErrorRecords __RPC_FAR * This,
    /* [in] */ ULONG ulRecordNum,
    /* [out] */ DISPPARAMS __RPC_FAR *pdispparams,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetRecordCount_Proxy( 
    IErrorRecords __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pcRecords);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorRecords_GetRecordCount_Stub( 
    IErrorRecords __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pcRecords,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IErrorLookup_GetErrorDescription_Proxy( 
    IErrorLookup __RPC_FAR * This,
    /* [in] */ HRESULT hrError,
    /* [in] */ DWORD dwLookupID,
    /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR __RPC_FAR *pbstrSource,
    /* [out] */ BSTR __RPC_FAR *pbstrDescription);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorLookup_GetErrorDescription_Stub( 
    IErrorLookup __RPC_FAR * This,
    /* [in] */ HRESULT hrError,
    /* [in] */ DWORD dwLookupID,
    /* [in] */ DISPPARAMS __RPC_FAR *pdispparams,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR __RPC_FAR *pbstrSource,
    /* [out] */ BSTR __RPC_FAR *pbstrDescription,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IErrorLookup_GetHelpInfo_Proxy( 
    IErrorLookup __RPC_FAR * This,
    /* [in] */ HRESULT hrError,
    /* [in] */ DWORD dwLookupID,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR __RPC_FAR *pbstrHelpFile,
    /* [out] */ DWORD __RPC_FAR *pdwHelpContext);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorLookup_GetHelpInfo_Stub( 
    IErrorLookup __RPC_FAR * This,
    /* [in] */ HRESULT hrError,
    /* [in] */ DWORD dwLookupID,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR __RPC_FAR *pbstrHelpFile,
    /* [out] */ DWORD __RPC_FAR *pdwHelpContext,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IErrorLookup_ReleaseErrors_Proxy( 
    IErrorLookup __RPC_FAR * This,
    /* [in] */ const DWORD dwDynamicErrorID);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IErrorLookup_ReleaseErrors_Stub( 
    IErrorLookup __RPC_FAR * This,
    /* [in] */ const DWORD dwDynamicErrorID,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ISQLErrorInfo_GetSQLInfo_Proxy( 
    ISQLErrorInfo __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbstrSQLState,
    /* [out] */ LONG __RPC_FAR *plNativeError);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ISQLErrorInfo_GetSQLInfo_Stub( 
    ISQLErrorInfo __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbstrSQLState,
    /* [out] */ LONG __RPC_FAR *plNativeError,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IGetDataSource_GetDataSource_Proxy( 
    IGetDataSource __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDataSource);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IGetDataSource_GetDataSource_Stub( 
    IGetDataSource __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppDataSource,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ITransactionLocal_GetOptionsObject_Proxy( 
    ITransactionLocal __RPC_FAR * This,
    /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionLocal_GetOptionsObject_Stub( 
    ITransactionLocal __RPC_FAR * This,
    /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ITransactionLocal_StartTransaction_Proxy( 
    ITransactionLocal __RPC_FAR * This,
    /* [in] */ ISOLEVEL isoLevel,
    /* [in] */ ULONG isoFlags,
    /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions,
    /* [out] */ ULONG __RPC_FAR *pulTransactionLevel);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionLocal_StartTransaction_Stub( 
    ITransactionLocal __RPC_FAR * This,
    /* [in] */ ISOLEVEL isoLevel,
    /* [in] */ ULONG isoFlags,
    /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions,
    /* [unique][out][in] */ ULONG __RPC_FAR *pulTransactionLevel,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ITransactionJoin_GetOptionsObject_Proxy( 
    ITransactionJoin __RPC_FAR * This,
    /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionJoin_GetOptionsObject_Stub( 
    ITransactionJoin __RPC_FAR * This,
    /* [out] */ ITransactionOptions __RPC_FAR *__RPC_FAR *ppOptions,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ITransactionJoin_JoinTransaction_Proxy( 
    ITransactionJoin __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *punkTransactionCoord,
    /* [in] */ ISOLEVEL isoLevel,
    /* [in] */ ULONG isoFlags,
    /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionJoin_JoinTransaction_Stub( 
    ITransactionJoin __RPC_FAR * This,
    /* [unique][in] */ IUnknown __RPC_FAR *punkTransactionCoord,
    /* [in] */ ISOLEVEL isoLevel,
    /* [in] */ ULONG isoFlags,
    /* [in] */ ITransactionOptions __RPC_FAR *pOtherOptions,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE ITransactionObject_GetTransactionObject_Proxy( 
    ITransactionObject __RPC_FAR * This,
    /* [in] */ ULONG ulTransactionLevel,
    /* [out] */ ITransaction __RPC_FAR *__RPC_FAR *ppTransactionObject);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionObject_GetTransactionObject_Stub( 
    ITransactionObject __RPC_FAR * This,
    /* [in] */ ULONG ulTransactionLevel,
    /* [out] */ ITransaction __RPC_FAR *__RPC_FAR *ppTransactionObject,
    /* [out] */ IErrorInfo __RPC_FAR *__RPC_FAR *ppErrorInfoRem);

/* [local] */ HRESULT STDMETHODCALLTYPE IScopedOperations_Copy_Proxy( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszSourceURLs[  ],
    /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszDestURLs[  ],
    /* [in] */ DWORD dwCopyFlags,
    /* [unique][in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ],
    /* [size_is][out] */ LPOLESTR __RPC_FAR rgpwszNewURLs[  ],
    /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IScopedOperations_Copy_Stub( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszSourceURLs,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszDestURLs,
    /* [in] */ DWORD dwCopyFlags,
    /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [size_is][out] */ DBSTATUS __RPC_FAR *rgdwStatus,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgulNewURLOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbStringsBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);

/* [local] */ HRESULT STDMETHODCALLTYPE IScopedOperations_Move_Proxy( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszSourceURLs[  ],
    /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszDestURLs[  ],
    /* [in] */ DWORD dwMoveFlags,
    /* [unique][in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ],
    /* [size_is][out] */ LPOLESTR __RPC_FAR rgpwszNewURLs[  ],
    /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IScopedOperations_Move_Stub( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszSourceURLs,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszDestURLs,
    /* [in] */ DWORD dwMoveFlags,
    /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [size_is][out] */ DBSTATUS __RPC_FAR *rgdwStatus,
    /* [size_is][size_is][out] */ ULONG __RPC_FAR *__RPC_FAR *prgulNewURLOffsets,
    /* [out][in] */ ULONG __RPC_FAR *pcbStringsBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);

/* [local] */ HRESULT STDMETHODCALLTYPE IScopedOperations_Delete_Proxy( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR rgpwszURLs[  ],
    /* [in] */ DWORD dwDeleteFlags,
    /* [size_is][out][in] */ DBSTATUS __RPC_FAR rgdwStatus[  ]);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IScopedOperations_Delete_Stub( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ DBCOUNTITEM cRows,
    /* [size_is][in] */ LPCOLESTR __RPC_FAR *rgpwszURLs,
    /* [in] */ DWORD dwDeleteFlags,
    /* [size_is][out] */ DBSTATUS __RPC_FAR *rgdwStatus);

/* [local] */ HRESULT STDMETHODCALLTYPE IScopedOperations_OpenRowset_Proxy( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][out][in] */ DBPROPSET __RPC_FAR rgPropertySets[  ],
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IScopedOperations_OpenRowset_Stub( 
    IScopedOperations __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [unique][in] */ DBID __RPC_FAR *pTableID,
    /* [unique][in] */ DBID __RPC_FAR *pIndexID,
    /* [in] */ REFIID riid,
    /* [in] */ ULONG cPropertySets,
    /* [size_is][unique][in] */ DBPROPSET __RPC_FAR *rgPropertySets,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppRowset,
    /* [in] */ ULONG cTotalProps,
    /* [size_is][out] */ DBPROPSTATUS __RPC_FAR *rgPropStatus);

/* [local] */ HRESULT STDMETHODCALLTYPE IBindResource_Bind_Proxy( 
    IBindResource __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ LPCOLESTR pwszURL,
    /* [in] */ DBBINDURLFLAG dwBindURLFlags,
    /* [in] */ REFGUID rguid,
    /* [in] */ REFIID riid,
    /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [unique][out][in] */ DBIMPLICITSESSION __RPC_FAR *pImplSession,
    /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IBindResource_Bind_Stub( 
    IBindResource __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ LPCOLESTR pwszURL,
    /* [in] */ DBBINDURLFLAG dwBindURLFlags,
    /* [in] */ REFGUID rguid,
    /* [in] */ REFIID riid,
    /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [in] */ IUnknown __RPC_FAR *pSessionUnkOuter,
    /* [unique][in] */ IID __RPC_FAR *piid,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession,
    /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);

/* [local] */ HRESULT STDMETHODCALLTYPE ICreateRow_CreateRow_Proxy( 
    ICreateRow __RPC_FAR * This,
    /* [unique][in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ LPCOLESTR pwszURL,
    /* [in] */ DBBINDURLFLAG dwBindURLFlags,
    /* [in] */ REFGUID rguid,
    /* [in] */ REFIID riid,
    /* [unique][in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [unique][out][in] */ DBIMPLICITSESSION __RPC_FAR *pImplSession,
    /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
    /* [out] */ LPOLESTR __RPC_FAR *ppwszNewURL,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICreateRow_CreateRow_Stub( 
    ICreateRow __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkOuter,
    /* [in] */ LPCOLESTR pwszURL,
    /* [in] */ DBBINDURLFLAG dwBindURLFlags,
    /* [in] */ REFGUID rguid,
    /* [in] */ REFIID riid,
    /* [in] */ IAuthenticate __RPC_FAR *pAuthenticate,
    /* [in] */ IUnknown __RPC_FAR *pSessionUnkOuter,
    /* [unique][in] */ IID __RPC_FAR *piid,
    /* [iid_is][unique][out][in] */ IUnknown __RPC_FAR *__RPC_FAR *ppSession,
    /* [unique][out][in] */ DBBINDURLSTATUS __RPC_FAR *pdwBindStatus,
    /* [unique][out][in] */ LPOLESTR __RPC_FAR *ppwszNewURL,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);

/* [local] */ HRESULT STDMETHODCALLTYPE IColumnsInfo2_GetRestrictedColumnInfo_Proxy( 
    IColumnsInfo2 __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumnIDMasks,
    /* [size_is][in] */ const DBID __RPC_FAR rgColumnIDMasks[  ],
    /* [in] */ DWORD dwFlags,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
    /* [size_is][size_is][out] */ DBID __RPC_FAR *__RPC_FAR *prgColumnIDs,
    /* [size_is][size_is][out] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgColumnInfo,
    /* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IColumnsInfo2_GetRestrictedColumnInfo_Stub( 
    IColumnsInfo2 __RPC_FAR * This,
    /* [in] */ DBORDINAL cColumnIDMasks,
    /* [size_is][unique][in] */ const DBID __RPC_FAR *rgColumnIDMasks,
    /* [in] */ DWORD dwFlags,
    /* [out][in] */ DBORDINAL __RPC_FAR *pcColumns,
    /* [size_is][size_is][unique][out][in] */ DBID __RPC_FAR *__RPC_FAR *prgColumnIDs,
    /* [size_is][size_is][unique][out][in] */ DBCOLUMNINFO __RPC_FAR *__RPC_FAR *prgColumnInfo,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgNameOffsets,
    /* [size_is][size_is][out] */ DBBYTEOFFSET __RPC_FAR *__RPC_FAR *prgcolumnidOffsets,
    /* [out][in] */ DBLENGTH __RPC_FAR *pcbStringsBuffer,
    /* [size_is][size_is][unique][out][in] */ OLECHAR __RPC_FAR *__RPC_FAR *ppStringsBuffer);

/* [local] */ HRESULT STDMETHODCALLTYPE IRegisterProvider_GetURLMapping_Proxy( 
    IRegisterProvider __RPC_FAR * This,
    /* [in] */ LPCOLESTR pwszURL,
    /* [in] */ DB_DWRESERVE dwReserved,
    /* [out] */ CLSID __RPC_FAR *pclsidProvider);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IRegisterProvider_GetURLMapping_Stub( 
    IRegisterProvider __RPC_FAR * This,
    /* [in] */ LPCOLESTR pwszURL,
    /* [in] */ DB_DWRESERVE dwReserved,
    /* [out] */ CLSID __RPC_FAR *pclsidProvider);



/* end of Additional Prototypes */
#endif // OLEDBPROXY

#ifdef __cplusplus
}
#endif

#endif


// GUID_DEFS_ONLY

#endif
#pragma option pop /*P_O_Pop*/
