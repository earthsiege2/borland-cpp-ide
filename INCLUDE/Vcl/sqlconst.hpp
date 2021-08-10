// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SqlConst.pas' rev: 6.00

#ifndef SqlConstHPP
#define SqlConstHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sqlconst
{
//-- type declarations -------------------------------------------------------
typedef AnsiString SqlConst__1[19];

//-- var, const, procedure ---------------------------------------------------
#define DRIVERS_KEY "Installed Drivers"
#define CONNECTIONS_KEY "Installed Connections"
#define DRIVERNAME_KEY "DriverName"
#define HOSTNAME_KEY "HostName"
#define ROLENAME_KEY "RoleName"
#define DATABASENAME_KEY "Database"
#define MAXBLOBSIZE_KEY "BlobSize"
#define VENDORLIB_KEY "VendorLib"
#define DLLLIB_KEY "LibraryName"
#define GETDRIVERFUNC_KEY "GetDriverFunc"
#define AUTOCOMMIT_KEY "AutoCommit"
#define BLOCKINGMODE_KEY "BlockingMode"
#define WAITONLOCKS_KEY "WaitOnLocks"
#define COMMITRETAIN_KEY "CommitRetain"
#define TRANSISOLATION_KEY "%s TransIsolation"
#define SQLDIALECT_KEY "SqlDialect"
#define SQLLOCALE_CODE_KEY "LocaleCode"
#define ERROR_RESOURCE_KEY "ErrorResourceFile"
#define SQLSERVER_CHARSET_KEY "ServerCharSet"
#define SREADCOMMITTED "readcommited"
#define SREPEATREAD "repeatableread"
#define SDIRTYREAD "dirtyread"
#define SDRIVERREG_SETTING "Driver Registry File"
#define SCONNECTIONREG_SETTING "Connection Registry File"
#define szUSERNAME "USER_NAME"
#define szPASSWORD "PASSWORD"
#define SLocaleCode "LCID"
#define ROWSETSIZE_KEY "RowsetSize"
#define OSAUTHENTICATION "Os Authentication"
#define SDriverConfigFile "dbxdrivers.ini"
#define SConnectionConfigFile "dbxconnections.ini"
#define SDBEXPRESSREG_SETTING "\\Software\\Borland\\DBExpress"
extern PACKAGE System::ResourceString _SLoginError;
#define Sqlconst_SLoginError System::LoadResourceString(&Sqlconst::_SLoginError)
extern PACKAGE System::ResourceString _SMonitorActive;
#define Sqlconst_SMonitorActive System::LoadResourceString(&Sqlconst::_SMonitorActive)
extern PACKAGE System::ResourceString _SMissingConnection;
#define Sqlconst_SMissingConnection System::LoadResourceString(&Sqlconst::_SMissingConnection)
extern PACKAGE System::ResourceString _SDatabaseOpen;
#define Sqlconst_SDatabaseOpen System::LoadResourceString(&Sqlconst::_SDatabaseOpen)
extern PACKAGE System::ResourceString _SDatabaseClosed;
#define Sqlconst_SDatabaseClosed System::LoadResourceString(&Sqlconst::_SDatabaseClosed)
extern PACKAGE System::ResourceString _SMissingSQLConnection;
#define Sqlconst_SMissingSQLConnection System::LoadResourceString(&Sqlconst::_SMissingSQLConnection)
extern PACKAGE System::ResourceString _SConnectionNameMissing;
#define Sqlconst_SConnectionNameMissing System::LoadResourceString(&Sqlconst::_SConnectionNameMissing)
extern PACKAGE System::ResourceString _SEmptySQLStatement;
#define Sqlconst_SEmptySQLStatement System::LoadResourceString(&Sqlconst::_SEmptySQLStatement)
extern PACKAGE System::ResourceString _SNoParameterValue;
#define Sqlconst_SNoParameterValue System::LoadResourceString(&Sqlconst::_SNoParameterValue)
extern PACKAGE System::ResourceString _SNoParameterType;
#define Sqlconst_SNoParameterType System::LoadResourceString(&Sqlconst::_SNoParameterType)
extern PACKAGE System::ResourceString _SParameterTypes;
#define Sqlconst_SParameterTypes System::LoadResourceString(&Sqlconst::_SParameterTypes)
extern PACKAGE System::ResourceString _SDataTypes;
#define Sqlconst_SDataTypes System::LoadResourceString(&Sqlconst::_SDataTypes)
extern PACKAGE System::ResourceString _SResultName;
#define Sqlconst_SResultName System::LoadResourceString(&Sqlconst::_SResultName)
extern PACKAGE System::ResourceString _SNoTableName;
#define Sqlconst_SNoTableName System::LoadResourceString(&Sqlconst::_SNoTableName)
extern PACKAGE System::ResourceString _SNoSqlStatement;
#define Sqlconst_SNoSqlStatement System::LoadResourceString(&Sqlconst::_SNoSqlStatement)
extern PACKAGE System::ResourceString _SNoDataSetField;
#define Sqlconst_SNoDataSetField System::LoadResourceString(&Sqlconst::_SNoDataSetField)
extern PACKAGE System::ResourceString _SNoCachedUpdates;
#define Sqlconst_SNoCachedUpdates System::LoadResourceString(&Sqlconst::_SNoCachedUpdates)
extern PACKAGE System::ResourceString _SMissingDataBaseName;
#define Sqlconst_SMissingDataBaseName System::LoadResourceString(&Sqlconst::_SMissingDataBaseName)
extern PACKAGE System::ResourceString _SMissingDataSet;
#define Sqlconst_SMissingDataSet System::LoadResourceString(&Sqlconst::_SMissingDataSet)
extern PACKAGE System::ResourceString _SMissingDriverName;
#define Sqlconst_SMissingDriverName System::LoadResourceString(&Sqlconst::_SMissingDriverName)
extern PACKAGE System::ResourceString _SPrepareError;
#define Sqlconst_SPrepareError System::LoadResourceString(&Sqlconst::_SPrepareError)
extern PACKAGE System::ResourceString _SObjectNameError;
#define Sqlconst_SObjectNameError System::LoadResourceString(&Sqlconst::_SObjectNameError)
extern PACKAGE System::ResourceString _SSQLDataSetOpen;
#define Sqlconst_SSQLDataSetOpen System::LoadResourceString(&Sqlconst::_SSQLDataSetOpen)
extern PACKAGE System::ResourceString _SNoActiveTrans;
#define Sqlconst_SNoActiveTrans System::LoadResourceString(&Sqlconst::_SNoActiveTrans)
extern PACKAGE System::ResourceString _SActiveTrans;
#define Sqlconst_SActiveTrans System::LoadResourceString(&Sqlconst::_SActiveTrans)
extern PACKAGE System::ResourceString _SDllLoadError;
#define Sqlconst_SDllLoadError System::LoadResourceString(&Sqlconst::_SDllLoadError)
extern PACKAGE System::ResourceString _SDllProcLoadError;
#define Sqlconst_SDllProcLoadError System::LoadResourceString(&Sqlconst::_SDllProcLoadError)
extern PACKAGE System::ResourceString _SConnectionEditor;
#define Sqlconst_SConnectionEditor System::LoadResourceString(&Sqlconst::_SConnectionEditor)
extern PACKAGE System::ResourceString _SCommandTextEditor;
#define Sqlconst_SCommandTextEditor System::LoadResourceString(&Sqlconst::_SCommandTextEditor)
extern PACKAGE System::ResourceString _SMissingDLLName;
#define Sqlconst_SMissingDLLName System::LoadResourceString(&Sqlconst::_SMissingDLLName)
extern PACKAGE System::ResourceString _SMissingDriverRegFile;
#define Sqlconst_SMissingDriverRegFile System::LoadResourceString(&Sqlconst::_SMissingDriverRegFile)
extern PACKAGE System::ResourceString _STableNameNotFound;
#define Sqlconst_STableNameNotFound System::LoadResourceString(&Sqlconst::_STableNameNotFound)
extern PACKAGE System::ResourceString _SNoCursor;
#define Sqlconst_SNoCursor System::LoadResourceString(&Sqlconst::_SNoCursor)
extern PACKAGE System::ResourceString _SMetaDataOpenError;
#define Sqlconst_SMetaDataOpenError System::LoadResourceString(&Sqlconst::_SMetaDataOpenError)
extern PACKAGE System::ResourceString _SErrorMappingError;
#define Sqlconst_SErrorMappingError System::LoadResourceString(&Sqlconst::_SErrorMappingError)
extern PACKAGE System::ResourceString _SStoredProcsNotSupported;
#define Sqlconst_SStoredProcsNotSupported System::LoadResourceString(&Sqlconst::_SStoredProcsNotSupported)
extern PACKAGE System::ResourceString _SPackagesNotSupported;
#define Sqlconst_SPackagesNotSupported System::LoadResourceString(&Sqlconst::_SPackagesNotSupported)
extern PACKAGE System::ResourceString _SDBXUNKNOWNERROR;
#define Sqlconst_SDBXUNKNOWNERROR System::LoadResourceString(&Sqlconst::_SDBXUNKNOWNERROR)
extern PACKAGE System::ResourceString _SDBXNOCONNECTION;
#define Sqlconst_SDBXNOCONNECTION System::LoadResourceString(&Sqlconst::_SDBXNOCONNECTION)
extern PACKAGE System::ResourceString _SDBXNOMETAOBJECT;
#define Sqlconst_SDBXNOMETAOBJECT System::LoadResourceString(&Sqlconst::_SDBXNOMETAOBJECT)
extern PACKAGE System::ResourceString _SDBXNOCOMMAND;
#define Sqlconst_SDBXNOCOMMAND System::LoadResourceString(&Sqlconst::_SDBXNOCOMMAND)
extern PACKAGE System::ResourceString _SDBXNOCURSOR;
#define Sqlconst_SDBXNOCURSOR System::LoadResourceString(&Sqlconst::_SDBXNOCURSOR)
extern PACKAGE System::ResourceString _SNOMEMORY;
#define Sqlconst_SNOMEMORY System::LoadResourceString(&Sqlconst::_SNOMEMORY)
extern PACKAGE System::ResourceString _SINVALIDFLDTYPE;
#define Sqlconst_SINVALIDFLDTYPE System::LoadResourceString(&Sqlconst::_SINVALIDFLDTYPE)
extern PACKAGE System::ResourceString _SINVALIDHNDL;
#define Sqlconst_SINVALIDHNDL System::LoadResourceString(&Sqlconst::_SINVALIDHNDL)
extern PACKAGE System::ResourceString _SINVALIDTIME;
#define Sqlconst_SINVALIDTIME System::LoadResourceString(&Sqlconst::_SINVALIDTIME)
extern PACKAGE System::ResourceString _SNOTSUPPORTED;
#define Sqlconst_SNOTSUPPORTED System::LoadResourceString(&Sqlconst::_SNOTSUPPORTED)
extern PACKAGE System::ResourceString _SINVALIDXLATION;
#define Sqlconst_SINVALIDXLATION System::LoadResourceString(&Sqlconst::_SINVALIDXLATION)
extern PACKAGE System::ResourceString _SINVALIDPARAM;
#define Sqlconst_SINVALIDPARAM System::LoadResourceString(&Sqlconst::_SINVALIDPARAM)
extern PACKAGE System::ResourceString _SOUTOFRANGE;
#define Sqlconst_SOUTOFRANGE System::LoadResourceString(&Sqlconst::_SOUTOFRANGE)
extern PACKAGE System::ResourceString _SSQLPARAMNOTSET;
#define Sqlconst_SSQLPARAMNOTSET System::LoadResourceString(&Sqlconst::_SSQLPARAMNOTSET)
extern PACKAGE System::ResourceString _SEOF;
#define Sqlconst_SEOF System::LoadResourceString(&Sqlconst::_SEOF)
extern PACKAGE System::ResourceString _SINVALIDUSRPASS;
#define Sqlconst_SINVALIDUSRPASS System::LoadResourceString(&Sqlconst::_SINVALIDUSRPASS)
extern PACKAGE System::ResourceString _SINVALIDPRECISION;
#define Sqlconst_SINVALIDPRECISION System::LoadResourceString(&Sqlconst::_SINVALIDPRECISION)
extern PACKAGE System::ResourceString _SINVALIDLEN;
#define Sqlconst_SINVALIDLEN System::LoadResourceString(&Sqlconst::_SINVALIDLEN)
extern PACKAGE System::ResourceString _SINVALIDXISOLEVEL;
#define Sqlconst_SINVALIDXISOLEVEL System::LoadResourceString(&Sqlconst::_SINVALIDXISOLEVEL)
extern PACKAGE System::ResourceString _SINVALIDTXNID;
#define Sqlconst_SINVALIDTXNID System::LoadResourceString(&Sqlconst::_SINVALIDTXNID)
extern PACKAGE System::ResourceString _SDUPLICATETXNID;
#define Sqlconst_SDUPLICATETXNID System::LoadResourceString(&Sqlconst::_SDUPLICATETXNID)
extern PACKAGE System::ResourceString _SDRIVERRESTRICTED;
#define Sqlconst_SDRIVERRESTRICTED System::LoadResourceString(&Sqlconst::_SDRIVERRESTRICTED)
extern PACKAGE System::ResourceString _SLOCALTRANSACTIVE;
#define Sqlconst_SLOCALTRANSACTIVE System::LoadResourceString(&Sqlconst::_SLOCALTRANSACTIVE)
extern PACKAGE System::ResourceString _SMultiConnNotSupported;
#define Sqlconst_SMultiConnNotSupported System::LoadResourceString(&Sqlconst::_SMultiConnNotSupported)
extern PACKAGE System::ResourceString _SConfFileMoveError;
#define Sqlconst_SConfFileMoveError System::LoadResourceString(&Sqlconst::_SConfFileMoveError)
extern PACKAGE System::ResourceString _SMissingConfFile;
#define Sqlconst_SMissingConfFile System::LoadResourceString(&Sqlconst::_SMissingConfFile)
extern PACKAGE System::ResourceString _SObjectViewNotTrue;
#define Sqlconst_SObjectViewNotTrue System::LoadResourceString(&Sqlconst::_SObjectViewNotTrue)
extern PACKAGE System::ResourceString _SDriverNotInConfigFile;
#define Sqlconst_SDriverNotInConfigFile System::LoadResourceString(&Sqlconst::_SDriverNotInConfigFile)
extern PACKAGE System::ResourceString _SObjectTypenameRequired;
#define Sqlconst_SObjectTypenameRequired System::LoadResourceString(&Sqlconst::_SObjectTypenameRequired)
extern PACKAGE System::ResourceString _SCannotCreateFile;
#define Sqlconst_SCannotCreateFile System::LoadResourceString(&Sqlconst::_SCannotCreateFile)
extern PACKAGE System::ResourceString _SDlgFilterTxt;
#define Sqlconst_SDlgFilterTxt System::LoadResourceString(&Sqlconst::_SDlgFilterTxt)
extern PACKAGE System::ResourceString _SLogFileFilter;
#define Sqlconst_SLogFileFilter System::LoadResourceString(&Sqlconst::_SLogFileFilter)
extern PACKAGE AnsiString DbxError[19];

}	/* namespace Sqlconst */
using namespace Sqlconst;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SqlConst
