{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 1997, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit SqlConst;

interface

const
  DRIVERS_KEY = 'Installed Drivers';            { Do not localize }
  CONNECTIONS_KEY = 'Installed Connections';    { Do not localize }
  DRIVERNAME_KEY = 'DriverName';                { Do not localize }
  HOSTNAME_KEY = 'HostName';                    { Do not localize }
  ROLENAME_KEY = 'RoleName';                    { Do not localize }
  DATABASENAME_KEY = 'Database';                { Do not localize }
  MAXBLOBSIZE_KEY = 'BlobSize';                 { Do not localize }          
  VENDORLIB_KEY = 'VendorLib';                  { Do not localize }
  DLLLIB_KEY = 'LibraryName';                   { Do not localize }
  GETDRIVERFUNC_KEY = 'GetDriverFunc';          { Do not localize }
  AUTOCOMMIT_KEY = 'AutoCommit';                { Do not localize }
  BLOCKINGMODE_KEY = 'BlockingMode';            { Do not localize }
  WAITONLOCKS_KEY= 'WaitOnLocks';               { Do not localize }
  COMMITRETAIN_KEY = 'CommitRetain';            { Do not localize }
  TRANSISOLATION_KEY = '%s TransIsolation';     { Do not localize }
  SQLDIALECT_KEY = 'SqlDialect';                { Do not localize }
  SQLLOCALE_CODE_KEY = 'LocaleCode';            { Do not localize }
  ERROR_RESOURCE_KEY = 'ErrorResourceFile';     { Do not localize }
  SQLSERVER_CHARSET_KEY = 'ServerCharSet';      { Do not localize }
  SREADCOMMITTED = 'readcommited';              { Do not localize }
  SREPEATREAD = 'repeatableread';               { Do not localize }
  SDIRTYREAD = 'dirtyread';                     { Do not localize }
  SDRIVERREG_SETTING = 'Driver Registry File';           { Do not localize }
  SCONNECTIONREG_SETTING = 'Connection Registry File';   { Do not localize }
  szUSERNAME         = 'USER_NAME';             { Do not localize }
  szPASSWORD         = 'PASSWORD';              { Do not localize }
  SLocaleCode        = 'LCID';                  { Do not localize }
  ROWSETSIZE_KEY     = 'RowsetSize';            { Do not localize }
  OSAUTHENTICATION   = 'Os Authentication';     { Do not localize }
{$IFDEF MSWINDOWS}
  SDriverConfigFile = 'dbxdrivers.ini';            { Do not localize }
  SConnectionConfigFile = 'dbxconnections.ini';    { Do not localize }
  SDBEXPRESSREG_SETTING = '\Software\Borland\DBExpress'; { Do not localize }
{$ENDIF}
{$IFDEF LINUX}
  SDBEXPRESSREG_USERPATH = '/.borland/';          { Do not localize }
  SDBEXPRESSREG_GLOBALPATH = '/usr/local/etc/';   { Do not localize }
  SDriverConfigFile = 'dbxdrivers';                  { Do not localize }
  SConnectionConfigFile = 'dbxconnections';          { Do not localize }
  SConfExtension = '.conf';                       { Do not localize }
{$ENDIF}

resourcestring
  SLoginError = 'Cannot connect to database ''%s''';
  SMonitorActive = 'Cannot change connection on Active Monitor';
  SMissingConnection = 'Missing SQLConnection property';
  SDatabaseOpen = 'Cannot perform this operation on an open connection';
  SDatabaseClosed = 'Cannot perform this operation on a closed connection';
  SMissingSQLConnection = 'SQLConnection property required for this operation';
  SConnectionNameMissing = 'Connection name missing';
  SEmptySQLStatement = 'No SQL statement available';
  SNoParameterValue = 'No value for parameter ''%s''';
  SNoParameterType = 'No parameter type for parameter ''%s''';
  SParameterTypes = ';Input;Output;Input/Output;Result';
  SDataTypes = ';String;SmallInt;Integer;Word;Boolean;Float;Currency;BCD;Date;Time;DateTime;;;;Blob;Memo;Graphic;;;;;Cursor;';
  SResultName = 'Result';
  SNoTableName = 'Missing TableName property';
  SNoSqlStatement = 'Missing query, table name or procedure name';
  SNoDataSetField = 'Missing DataSetField property';
  SNoCachedUpdates = 'Not in cached update mode';
  SMissingDataBaseName = 'Missing Database property';
  SMissingDataSet = 'Missing DataSet property';
  SMissingDriverName = 'Missing DriverName property';
  SPrepareError = 'Unable to execute Query';
  SObjectNameError = 'Table/Procedure not found';
  SSQLDataSetOpen = 'Unable to determine field names for %s';
  SNoActiveTrans = 'There is no active transaction';
  SActiveTrans = 'A transaction is already active';
  SDllLoadError = 'Unable to Load %s';
  SDllProcLoadError = 'Unable to Find Procedure %s';
  SConnectionEditor = '&Edit Connection Properties';
  SCommandTextEditor = '&Edit CommandText';
  SMissingDLLName = 'DLL/Shared Library Name not Set';
  SMissingDriverRegFile = 'Driver/Connection Registry File ''%s'' not found';
  STableNameNotFound = 'Cannot find TableName in CommandText';
  SNoCursor = 'Cursor not returned from Query';
  SMetaDataOpenError = 'Unable to Open Metadata';
  SErrorMappingError = 'SQL Error: Error mapping failed';
  SStoredProcsNotSupported = 'Stored Procedures not supported by ''%s'' Server';
  SPackagesNotSupported = 'Packages are not supported by ''%s'' Server';
  SDBXUNKNOWNERROR = 'DBX Error: No Mapping for Error Code Found';
  SDBXNOCONNECTION = 'DBX Error: Connection not found, error message cannot be retrieved';
  SDBXNOMETAOBJECT = 'DBX Error: MetadataObject not found, error message cannot be retrieved';
  SDBXNOCOMMAND = 'DBX Error: Command not found, error message cannot be retrieved';
  SDBXNOCURSOR = 'DBX Error: Cursor not found, error message cannot be retrieved';
  SNOMEMORY = 'DBX Error: Insufficient Memory for Operation';
  SINVALIDFLDTYPE = 'DBX Error: Invalid Field Type';
  SINVALIDHNDL = 'DBX Error: Invalid Handle';
  SINVALIDTIME = 'DBX Error: Invalid Time';
  SNOTSUPPORTED = 'DBX Error: Operation Not Supported';
  SINVALIDXLATION = 'DBX Error: Invalid Translation';
  SINVALIDPARAM = 'DBX Error: Invalid Parameter';
  SOUTOFRANGE = 'DBX Error: Argument out of Range';
  SSQLPARAMNOTSET = 'DBX Error: Parameter Not Set';
  SEOF = 'DBX Error: Result set at EOF';
  SINVALIDUSRPASS = 'DBX Error: Invalid Username/Password';
  SINVALIDPRECISION = 'DBX Error: Invalid Precision';
  SINVALIDLEN = 'DBX Error: Invalid Length';
  SINVALIDXISOLEVEL = 'DBX Error: Invalid Transaction Isolation Level';
  SINVALIDTXNID = 'DBX Error: Invalid Transaction ID';
  SDUPLICATETXNID = 'DBX Error: Duplicate Transaction ID';
  SDRIVERRESTRICTED = 'dbExpress: Application is not licensed to use this feature';
  SLOCALTRANSACTIVE = 'DBX Error: Local Transaction already active';
  SMultiConnNotSupported = 'Multiple Connections not supported by %s driver';
  SConfFileMoveError = 'Unable to move %s to %s';
  SMissingConfFile = 'Configuration file %s not found';
  SObjectViewNotTrue = 'ObjectView must be True for Table with Object fields';
  SDriverNotInConfigFile = 'Driver (%s) not found in Cfg file (%s)';
  SObjectTypenameRequired = 'Object type name required as parameter value';
  SCannotCreateFile = 'Cannot create file %s';
// used in SqlReg.pas
  SDlgFilterTxt = 'Text files (*.txt)|*.txt|All files (*.*)|*.*';
  SLogFileFilter = 'Log files (*.log)';

const

  DbxError : array[0..18] of String = ( '', SNOMEMORY, SINVALIDFLDTYPE,
                SINVALIDHNDL, SINVALIDTIME,
                SNOTSUPPORTED, SINVALIDXLATION, SINVALIDPARAM, SOUTOFRANGE,
                SSQLPARAMNOTSET, SEOF, SINVALIDUSRPASS, SINVALIDPRECISION,
                SINVALIDLEN, SINVALIDXISOLEVEL, SINVALIDTXNID, SDUPLICATETXNID,
                SDRIVERRESTRICTED, SLOCALTRANSACTIVE );

implementation

end.
