
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997, 1999 Inprise Corporation    }
{                                                       }
{*******************************************************}

unit BdeConst;

interface

resourcestring
  SAutoSessionExclusive = 'Cannot enable AutoSessionName property with more than one session on a form or data-module';
  SAutoSessionExists = 'Cannot add a session to the form or data-module while session ''%s'' has AutoSessionName enabled';
  SAutoSessionActive = 'Cannot modify SessionName while AutoSessionName is enabled';
  SDuplicateDatabaseName = 'Duplicate database name ''%s''';
  SDuplicateSessionName = 'Duplicate session name ''%s''';
  SInvalidSessionName = 'Invalid session name %s';
  SDatabaseNameMissing = 'Database name missing';
  SSessionNameMissing = 'Session name missing';
  SDatabaseOpen = 'Cannot perform this operation on an open database';
  SDatabaseClosed = 'Cannot perform this operation on a closed database';
  SDatabaseHandleSet = 'Database handle owned by a different session';
  SSessionActive = 'Cannot perform this operation on an active session';
  SHandleError = 'Error creating cursor handle';
  SInvalidFloatField = 'Cannot convert field ''%s'' to a floating point value';
  SInvalidIntegerField = 'Cannot convert field ''%s'' to an integer value';
  STableMismatch = 'Source and destination tables are incompatible';
  SFieldAssignError = 'Fields ''%s'' and ''%s'' are not assignment compatible';
  SNoReferenceTableName = 'ReferenceTableName not specified for field ''%s''';
  SCompositeIndexError = 'Cannot use array of Field values with Expression Indices';
  SInvalidBatchMove = 'Invalid batch move parameters';
  SEmptySQLStatement = 'No SQL statement available';
  SNoParameterValue = 'No value for parameter ''%s''';
  SNoParameterType = 'No parameter type for parameter ''%s''';
  SLoginError = 'Cannot connect to database ''%s''';
  SInitError = 'An error occurred while attempting to initialize the Borland Database Engine (error $%.4x)';
  SDatabaseEditor = 'Da&tabase Editor...';
  SExplore = 'E&xplore';
  SLinkDetail = '''%s'' cannot be opened';
  SLinkMasterSource = 'The MasterSource property of ''%s'' must be linked to a DataSource';
  SLinkMaster = 'Unable to open the MasterSource Table';
  SGQEVerb = 'S&QL Builder...';
  SBindVerb = 'Define &Parameters...';
  SIDAPILangID = '0009';
  SDisconnectDatabase = 'Database is currently connected. Disconnect and continue?';
  SBDEError = 'BDE error $%.4x';
  SLookupSourceError = 'Unable to use duplicate DataSource and LookupSource';
  SLookupTableError = 'LookupSource must be connected to TTable component';
  SLookupIndexError = '%s must be the lookup table''s active index';
  SParameterTypes = ';Input;Output;Input/Output;Result';
  SInvalidParamFieldType = 'Must have a valid field type selected';
  STruncationError = 'Parameter ''%s'' truncated on output';
  SDataTypes = ';String;SmallInt;Integer;Word;Boolean;Float;Currency;BCD;Date;Time;DateTime;;;;Blob;Memo;Graphic;;;;;Cursor;';
  SResultName = 'Result';
  SDBCaption = '%s%s%s Database';
  SParamEditor = '%s%s%s Parameters';
  SIndexFilesEditor = '%s%s%s Index Files';
  SNoIndexFiles = '(None)';
  SIndexDoesNotExist = 'Index does not exist. Index: %s';
  SNoTableName = 'Missing TableName property';
  SNoDataSetField = 'Missing DataSetField property';
  SBatchExecute = 'E&xecute';
  SNoCachedUpdates = 'Not in cached update mode';
  SInvalidAliasName = 'Invalid alias name %s';
  SNoFieldAccess = 'Cannot access field ''%s'' in a filter';
  SUpdateSQLEditor = '&UpdateSQL Editor...';
  SNoDataSet = 'No dataset association';
  SUntitled = 'Untitled Application';
  SUpdateWrongDB = 'Cannot update, %s is not owned by %s';
  SUpdateFailed = 'Update failed';
  SSQLGenSelect = 'Must select at least one key field and one update field';
  SSQLNotGenerated = 'Update SQL statements not generated, exit anyway?';
  SSQLDataSetOpen = 'Unable to determine field names for %s';
  SLocalTransDirty = 'The transaction isolation level must be dirty read for local databases';
  SMissingDataSet = 'Missing DataSet property';
  SNoProvider = 'No provider available';
  SNotAQuery = 'Dataset is not a query';

implementation

end.
