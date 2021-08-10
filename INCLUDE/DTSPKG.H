//
// DTSPackage COM Server Header file.
//

#ifndef DTSPackage_H_
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define DTSPackage_H_

#ifndef DTSPackageVersion_Major
	#define DTSPackageVersion_Major 1
	#define DTSPackageVersion_Minor 0
#endif // DTSPackageVersion_Major

#ifndef DTSPackage_VersionOnly

/////////////////////////////////////////////////////////////////////////////////////////
// Constant enumerations.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef DTSPackage_CONSTANTS_
#define DTSPackage_CONSTANTS_

#ifdef DTSPackage_ODL_
	#define DTS_ENUM_BEGIN(tdef, hstring)	[helpcontext(H_##tdef), helpstring(hstring)] enum
		// item = value, ...
	#define DTS_ENUM_END(tdef)				tdef, *LP##tdef
#else
	#define DTS_ENUM_BEGIN(tdef, hstring)	DWORD tdef, *LP##tdef; enum tag##tdef
		// item = value, ...
	#define DTS_ENUM_END(tdef)				
#endif

typedef DTS_ENUM_BEGIN(DTSPackageError, "Error ranges for DTSPackage creation and execution") {
	DTSPackage_E_NotImplemented						= 1001,
	DTSPackage_E_OrdOutOfRange						= 1002,
	DTSPackage_E_NameNotFound						= 1003,
	DTSPackage_E_NameDup							= 1004,
	DTSPackage_E_NoStepsDefined						= 1005,
	DTSPackage_E_Column_OutOfRange					= 1006,
	DTSPackage_E_ColumnNeedsNameOrOrdinal			= 1007,
	DTSPackage_E_WrongCollection					= 1008,
	DTSPackage_E_DatatypeNotFound					= 1009,
	DTSPackage_E_NeedConnectionInfo					= 1010,
	DTSPackage_E_ODBC_NeedConnectionInfo			= 1011,
	DTSPackage_E_NoStepsToExecute					= 1012,
	DTSPackage_E_DescribeNeedsQuery					= 1013,
	DTSPackage_E_ColumnsNotDescribed				= 1014,
	DTSPackage_E_Step_CyclicDependency				= 1015,
	DTSPackage_E_UsageBeforeDescribeOnly			= 1016,
	DTSPackage_E_AxScript_CantInitializeEngine		= 1017,
	DTSPackage_E_AxScript_RequiredParams			= 1018,
	DTSPackage_E_AxScript_ParseError				= 1019,
	DTSPackage_E_AxScript_BadFunctionName			= 1020,
	DTSPackage_E_AxScript_CantAddGlobals			= 1021,
	DTSPackage_E_AxScript_RunTimeError				= 1022,
	DTSPackage_E_BadStepStatusValue					= 1023,
	DTSPackage_E_BadStepResultValue					= 1024,
	DTSPackage_E_BadTaskResultValue					= 1025,
	DTSPackage_E_BadPrecedenceBasis					= 1026,
	DTSPackage_E_BadStepTask						= 1027,
	DTSPackage_E_RequireConnectionProperties		= 1028,
	DTSPackage_E_ConnectionRequiresValidTaskName	= 1029,
	DTSPackage_E_ConnectionInUse					= 1030,
	DTSPackage_E_CannotFindConnection				= 1031,
	DTSPackage_E_PumpTask_RequireXforms				= 1032,
	DTSPackage_E_PumpTask_RequireSrcAndDestColumns	= 1033,
	DTSPackage_E_PumpTask_RequireRowsetDataSrcInfo	= 1034,
	DTSPackage_E_PumpTask_RequireXformServer		= 1035,
	DTSPackage_E_BadPrecedenceStep					= 1036,
	DTSPackage_E_CreateProcTask_Timeout				= 1037,
	DTSPackage_E_BadGUIDValue						= 1038,
	DTSPackage_E_RequireNameForExecOrStg			= 1039,
	DTSPackage_E_CantFindVersionInStg				= 1040,
	DTSPackage_E_CantSetCommandProps				= 1041,
	DTSPackage_E_BadPriorityClass					= 1042,
	DTSPackage_E_BadRelativePriority				= 1043,
	DTSPackage_E_CantFindPackageInStg				= 1044,
	DTSPackage_E_EncryptStg_CantCreateOrWrite		= 1045,
	DTSPackage_E_EncryptStg_CantOpenOrRead			= 1046,
	DTSPackage_E_EncryptStg_HandsOnStg				= 1047,
	DTSPackage_E_EncryptStg_UnsupportedFlags		= 1048,
	DTSPackage_E_EncryptStg_PasswordNotMatching		= 1049,
	DTSPackage_E_EncryptStg_RequirePassword			= 1050,
	DTSPackage_E_EncryptStg_StreamTooLarge			= 1051,
	DTSPackage_E_Security_InvalidPassword			= 1052,
	DTSPackage_E_Security_RequireBothPasswords		= 1053,
	DTSPackage_E_Security_OperatorNotPriveleged		= 1054,
	DTSPackage_E_SQLTask_RequireSQL					= 1055,
	DTSPackage_E_UnknownOleDBProperty				= 1056,
	DTSPackage_E_RequireConnectionID				= 1057,
	DTSPackage_E_RequireColumnNameAndOrdinal		= 1058,
	DTSPackage_E_PropertyStringTooLong				= 1059,
	DTSPackage_E_CantChangeLoadedPkgName			= 1060,
	DTSPackage_E_NoXformDispatch					= 1061,
	DTSPackage_E_CannotPersistProperty				= 1062,
	DTSPackage_E_ExecutionCanceled					= 1063,
	DTSPackage_E_FailedOnStepError					= 1064,
	DTSPackage_E_BadForceMode						= 1065,
	DTSPackage_E_MultiPackageStgNeedsID				= 1066,
	DTSPackage_E_BadSQLServerStorageFlags			= 1067,
	DTSPackage_E_NoPackageDataFromServer			= 1068,
	DTSPackage_E_NeedDestinationColumnDefinitions	= 1069,
	DTSPackage_E_DSO_OnlyOneSession					= 1070,
	DTSPackage_E_DSO_OnlyOneRowset					= 1071,
	DTSPackage_E_DSO_ProviderStringRequired			= 1072,
	DTSPackage_E_DSO_CantRelaunchPackage			= 1073,
	DTSPackage_E_DSO_OnlyOneCommand					= 1074,
	DTSPackage_E_BadPackageDSORowsetTask			= 1075,
	DTSPackage_E_AbandonedRowQueueDest				= 1076,
	DTSPackage_E_DataDrivenQueryTask_RequireXforms	= 1077,
	DTSPackage_E_NeedDataDrivenQueries				= 1078,
	DTSPackage_E_NeedDataDrivenQueryAndColumns		= 1079,
	DTSPackage_E_HostFailedPersistence				= 1080,
	DTSPackage_E_BadLookupConnectionProvider		= 1081,
	DTSPackage_E_CreateProcessNullCommandLine		= 1082,
	DTSPackage_E_GeneralTaskFailure					= 1083,
	DTSPackage_E_XfrTask_SrcInfoIncomplete			= 1084,
	DTSPackage_E_XfrTask_DestInfoIncomplete			= 1085,
	DTSPackage_E_XfrTask_InvalidCopyDataOption		= 1086,
	DTSPackage_E_XfrTask_InvalidObjectType			= 1087,
	DTSPackage_E_XfrTask_InvalidObjectName			= 1088,
	DTSPackage_E_XfrTask_InvalidOwnerName			= 1089,
	DTSPackage_E_XfrTask_CantCreateDMOObject		= 1090,
	DTSPackage_E_XfrTask_CantConnectToSrc			= 1091,
	DTSPackage_E_XfrTask_CantGetSrcDB				= 1092,
	DTSPackage_E_XfrTask_IndexOutOfRange			= 1093,
	DTSPackage_E_BadStepScriptResultValue			= 1094,
	DTSPackage_E_AxScript_CantModifyDuringExecute	= 1095,

	DTSPackage_E_Repos_NotRegistered				= 1100,
	DTSPackage_E_Repos_CantScanCatalog				= 1101,
	DTSPackage_E_Repos_ScannedObjectNotFound		= 1102,
	DTSPackage_E_Repos_ScannedColumnNotFound		= 1103,
	DTSPackage_E_Repos_BadStorageFlags				= 1104,
	DTSPackage_E_Repos_CantParseName				= 1105,
	DTSPackage_E_Repos_ScannedSchemaNotFound		= 1106,
	DTSPackage_E_Repos_UnscannedColumnNotFound		= 1107,
 	DTSPackage_E_Repos_DuplicatePackageName			= 1108,
	DTSPackage_E_Repos_ScanRequiresSchemaRowset		= 1109,
	DTSPackage_E_Repos_GeneralError					= 1110,
	DTSPackage_E_Repos_InvalidMetadataOptions		= 1111,
	DTSPackage_E_Repos_PackageNotFound				= 1112,

	DTSPackage_E_Lineage_BadOptions					= 1120,
	DTSPackage_E_Lineage_NoRepositoryContext		= 1121,
	DTSPackage_E_Lineage_CantOpenRepository			= 1122,
	DTSPackage_E_Lineage_RepositoryError			= 1123,
	DTSPackage_E_Lineage_PackageVersionFrozen		= 1124,
	DTSPackage_E_Lineage_ErrorWritingToRepos		= 1125,

	DTSPackage_E_Trx_InvalidIsolationLevel			= 1130,
	DTSPackage_E_Trx_TaskCannotJoinTransaction		= 1131,
	DTSPackage_E_Trx_ConnCannotJoinTransaction		= 1132,
	DTSPackage_E_Trx_BeginFailed					= 1133,
	DTSPackage_E_Trx_StepCommitFailed				= 1134,
	DTSPackage_E_Trx_PackageCommitFailed			= 1135,
	DTSPackage_E_Trx_DTCNotAvailable				= 1136,
	DTSPackage_E_Trx_TrxNoLongerActive				= 1137,

	DTSPackage_E_MailTask_NoMAPIInterfaceLayer		= 1150,
	DTSPackage_E_MailTask_CantInitializeMAPI		= 1151,
	DTSPackage_E_MailTask_LogonFailure				= 1152,
	DTSPackage_E_MailTask_SendFailure				= 1153,
	DTSPackage_E_MailTask_NotInitialized			= 1154,
	DTSPackage_E_MailTask_GeneralFailure 			= 1155,

	DTSPackage_E_BulkInsertTask_RequireTableName	= 1156,
	DTSPackage_E_BulkInsertTask_RequireDataFile		= 1157,

	DTSPackage_E_InvalidFastLoadOptions				= 1170,
	DTSPackage_E_EncryptStg_CantInit				= 1171,
	DTSPackage_E_NoFastLoadWithDataLink				= 1172,
	DTSPackage_E_NoFastLoad							= 1173,
	DTSPackage_E_ProcTaskReturnCodeNotSuccess		= 1174,
	DTSPackage_E_SaveTo70OrLater					= 1175,
	DTSPackage_E_SQLServerLicenseError				= 1176,

} DTS_ENUM_END(DTSPackageError);

typedef DTS_ENUM_BEGIN(DTSStepExecStatus, "Execution status of this DTSStep") {
	DTSStepExecStat_Waiting				= 0x0001,
	DTSStepExecStat_InProgress			= 0x0002,
	DTSStepExecStat_Inactive			= 0x0003,
	DTSStepExecStat_Completed			= 0x0004,		// Or'd with completion bits below.
} DTS_ENUM_END(DTSStepExecStatus);

typedef DTS_ENUM_BEGIN(DTSStepExecResult, "Execution Result of this DTSStep") {
	DTSStepExecResult_Success			= 0x0000,
	DTSStepExecResult_Failure			= 0x0001,
} DTS_ENUM_END(DTSStepExecResult);

typedef DTS_ENUM_BEGIN(DTSStepScriptResult, "Return code from Active Script associated with a step indicating flow of control for task execution") {
	DTSStepScriptResult_ExecuteTask				= 0x0000,
	DTSStepScriptResult_DontExecuteTask			= 0x0001,
	DTSStepScriptResult_RetryLater				= 0x0002,
} DTS_ENUM_END(DTSStepScriptResult);

typedef DTS_ENUM_BEGIN(DTSTaskExecResult, "Execution Result of Task") {
	DTSTaskExecResult_Success			= 0x0000,
	DTSTaskExecResult_Failure			= 0x0001,
	DTSTaskExecResult_RetryStep			= 0x0002,
} DTS_ENUM_END(DTSTaskExecResult);

typedef DTS_ENUM_BEGIN(DTSStepPrecedenceBasis, "Step precedence is based either on Step Status or Result") {
	DTSStepPrecedenceBasis_ExecStatus			= 0x0000,
	DTSStepPrecedenceBasis_ExecResult			= 0x0001,
} DTS_ENUM_END(DTSStepPrecedenceBasis);

typedef DTS_ENUM_BEGIN(DTSStepRelativePriority, "Win32 Thread Relative Priority to be used for Step Task") {
	DTSStepRelativePriority_Lowest			= 0x0001,
	DTSStepRelativePriority_BelowNormal		= 0x0002,
	DTSStepRelativePriority_Normal			= 0x0003,
	DTSStepRelativePriority_AboveNormal		= 0x0004,
	DTSStepRelativePriority_Highest			= 0x0005,
} DTS_ENUM_END(DTSStepRelativePriority);

typedef DTS_ENUM_BEGIN(DTSPackagePriorityClass, "Win32 Process Priority Class to be used for the package.") {
	DTSPriorityClass_Low			= 0x0001,
	DTSPriorityClass_Normal			= 0x0002,
	DTSPriorityClass_High			= 0x0003,
} DTS_ENUM_END(DTSPackagePriorityClass);

typedef DTS_ENUM_BEGIN(DTSIsolationLevel, "Isolation level at which Package transaction executes (default is ReadCommitted).") {
	DTSIsoLevel_Chaos				= 0x10,
	DTSIsoLevel_ReadUncommitted		= 0x100,
	DTSIsoLevel_Browse				= 0x100,
	DTSIsoLevel_CursorStability		= 0x1000,
	DTSIsoLevel_ReadCommitted		= 0x1000,
	DTSIsoLevel_RepeatableRead		= 0x10000,
	DTSIsoLevel_Serializable		= 0x100000,
	DTSIsoLevel_Isolated			= 0x100000
} DTS_ENUM_END(DTSIsolationLevel);

typedef DTS_ENUM_BEGIN(DTSForceMode, "Overrides default handling of associated property") {
	DTSForceMode_Default				= 0x0000,
	DTSForceMode_Always					= 0x0001,
	DTSForceMode_Never					= 0x0002,
} DTS_ENUM_END(DTSForceMode);

typedef DTS_ENUM_BEGIN(DTSErrorMode, "Handling of Error conditions encountered while executing Steps in the Package") {
#ifdef DTSPackage_INTERNAL
	DTSErrorMode_Unknown			= 0x0000,		// Not yet set
#endif // DTSPackage_INTERNAL

	DTSErrorMode_Continue			= 0x0001,		// Log exceptions (if specified) and continue
	DTSErrorMode_FailStep			= 0x0002,		// Fail Step Execution
	DTSErrorMode_FailPackage		= 0x0003,		// Fail Package Execution.
} DTS_ENUM_END(DTSErrorMode);

typedef DTS_ENUM_BEGIN(DTSCustomTaskUIFlags, "Specifies flags indicating the type of UI supported by the custom task") {
	DTSCustomTaskUIFlags_Default			= 0x0000,
	DTSCustomTaskUIFlags_DoesCustomToolTip	= 0x0001,
} DTS_ENUM_END(DTSCustomTaskUIFlags);

typedef DTS_ENUM_BEGIN(DTSRepositoryStorageFlags, "Specifies Repository options when saving or loading the DTS Package") {
	DTSReposFlag_Default					= 0x0000,

	// How to connect to the repository.
	DTSReposFlag_UseTrustedConnection		= 0x0100,		// Use NT integrated security to connect to Repository (MS SQL Server-hosted Repository only)
} DTS_ENUM_END(DTSRepositoryStorageFlags);

typedef DTS_ENUM_BEGIN(DTSSQLServerStorageFlags, "Specifies Repository options when saving or loading the DTS Package") {
	DTSSQLStgFlag_Default					= 0x0000,

	// How to connect to the server.
	DTSSQLStgFlag_UseTrustedConnection		= 0x0100,		// Use NT integrated security to connect to SQL Server
} DTS_ENUM_END(DTSSQLServerStorageFlags);

typedef DTS_ENUM_BEGIN(DTSRepositoryMetadataOptions, "Specifies metadata scanning and resolution options when storing the DTS Package to a Repository") {
	DTSReposMetadata_Default					= 0x0000,		// Does no scanner resolution

	// These indicate whether to attempt any scanner resolution at all.  Note that scanning is only
	// done at the Catalog level; an inconsistency at a lower level will be an error.
	DTSReposMetadata_RequireScannedCatalog		= 0x0001,		// Requires that any database objects must have been scanned into repository
	DTSReposMetadata_UseScannedCatalogIfPresent	= 0x0002,		// Will use any scanned objects found; nonscanned references will create local objects

	// These are ignored unless one of the scanned-resolution options above is set.
	// If neither of the _Scan options is set, then no scanning will be done;
	// if _RequireAllScanned is set, the SaveToRepository will fail, otherwise
	// a local reference will be created for the object.
	DTSReposMetadata_ScanCatalogIfNotFound		= 0x0004,		// The Package will issue a scan on all catalogs that are not found already scanned
	DTSReposMetadata_ScanCatalogAlways			= 0x0008,		// The Package will scan all Catalogs referenced, re-scanning if already scanned
} DTS_ENUM_END(DTSRepositoryMetadataOptions);

typedef DTS_ENUM_BEGIN(DTSSQLObjectType, "Indicates types of objects available on Microsoft SQL Server. This is in sync with SQLDMO_OBJECT_TYPE in SQL-DMO") {
	// Database objects, value is power(2, sysobjects.sysstat & 0x0f), plus UDDTs in 0.
	// These values can be bitmasked together for object listings.
	DTSSQLObj_UserDefinedDatatype =           0x00000001,    // 1
	DTSSQLObj_SystemTable =                   0x00000002,    // 2
	DTSSQLObj_View =                          0x00000004,    // 4
	DTSSQLObj_UserTable =                     0x00000008,    // 8
	DTSSQLObj_StoredProcedure =               0x00000010,    // 16
	DTSSQLObj_Default =                       0x00000040,    // 64
	DTSSQLObj_Rule =                          0x00000080,    // 128
	DTSSQLObj_Trigger =                       0x00000100,    // 256
	DTSSQLObj_AllDatabaseUserObjects =        0x000001fd,    // All but system tables
	DTSSQLObj_AllDatabaseObjects =            0x000001ff,    // All including system tables

} DTS_ENUM_END(DTSSQLObjectType);

typedef DTS_ENUM_BEGIN(DTSTransfer_CopyDataOption, "Specifies flags indicating if data should be copied, and whether existing data should be replaced or appended to.") {
	DTSTransfer_DontCopyData = 0x0000,
	DTSTransfer_ReplaceData	= 0x0001,
	DTSTransfer_AppendData	= 0x0002,
} DTS_ENUM_END(DTSTransfer_CopyDataOption);

typedef DTS_ENUM_BEGIN(DTSTransfer_ScriptOption, "Specifies scripting option. This is in sync with SQLDMO_SCRIPT_TYPE in SQL-DMO.") {
        // What's included in the Script method output.
        DTSTransfer_Script_Default 				= 0x0004, 	// Object creation only
        DTSTransfer_Script_Drops 					= 0x0001, 	// Include object drops
        DTSTransfer_Script_ObjectPermissions 		= 0x0002, 	// Include object permissions
        DTSTransfer_Script_PrimaryObject 			= 0x0004, 	// Include object creation
        DTSTransfer_Script_ClusteredIndexes 		= 0x0008,   // Include clustered index creation (table only)
        DTSTransfer_Script_Triggers 				= 0x0010,   // Include trigger creation (table only)
        DTSTransfer_Script_DatabasePermissions	= 0x0020,   // Database (statement) permissions
        DTSTransfer_Script_Permissions 			= 0x0022,   // Both database and object permissions (for scripting users).
        DTSTransfer_Script_ToFileOnly 			= 0x0040,   // If not set, a string is returned (if file nonnull, both are done)
        DTSTransfer_Script_Bindings 				= 0x0080,   // Include rule/default bindings (table only)
        DTSTransfer_Script_AppendToFile 			= 0x0100,   // Append to output file if it already exists.
        DTSTransfer_Script_NoDRI 					= 0x0200,   // Do not include DRI (intended for use if targeting pre-6.0 server with scripts)
        DTSTransfer_Script_UDDTsToBaseType 		= 0x0400,   // Convert UserDefinedDatatypes to base type when creating columns (table only)
		// 0x0800 available.
        DTSTransfer_Script_IncludeIfNotExists 	= 0x1000,   // Include "if not exists" on object creation.
        DTSTransfer_Script_NonClusteredIndexes	= 0x2000,   // Include nonclustered index creation (table only)
        DTSTransfer_Script_Indexes 				= 0x12008,  // Include all index creation (table only)
        DTSTransfer_Script_Aliases 				= 0x4000,   // For users, script aliases
        DTSTransfer_Script_NoCommandTerm 			= 0x8000,   // Do not append "GO" to commands.
        DTSTransfer_Script_DRIIndexes 			= 0x10000,  // Script DRI-generated indexes as indexes if NoDRI is specified.
        DTSTransfer_Script_IncludeHeaders 		= 0x20000,  // Include descriptive header in individual object script output.
        DTSTransfer_Script_OwnerQualify 			= 0x40000,  // Owner-qualify DROP statements (and CREATE where possible).
        DTSTransfer_Script_TimestampToBinary 		= 0x80000,  // Convert timestamp columns to binary(8) (for replication, etc.).
        DTSTransfer_Script_SortedData 			= 0x100000, // If the index or constraint was clustered, append sorted_data
        DTSTransfer_Script_SortedDataReorg 		= 0x200000, // Same as DTSTransfer_Script_SortedData, but Reorg is used to preserve fillfactor.
        DTSTransfer_Script_TransferDefault 		= 0x800670ff,  // The default script type for Transfer. This is combination of following flags:
                                                        // DTSTransfer_Script_PrimaryObject | DTSTransfer_Script_Bindings | DTSTransfer_Script_ClusteredIndexes | DTSTransfer_Script_NonClusteredIndexes |
                                                        // DTSTransfer_Script_Triggers| DTSTransfer_Script_ToFileOnly|DTSTransfer_Script_Permissions| DTSTransfer_Script_IncludeHeaders|
                                                        // DTSTransfer_Script_Aliases|DTSTransfer_Script_IncludeIfNotExists|DTSTransfer_Script_OwnerQualify
        // DRI-restrictive flags.  These may be combined with PrimaryObject as desired.
        // These are to be used to include or exclude specific DRI components, such
        // as for multi-pass scripting.
        DTSTransfer_Script_DRI_NonClustered 		= 0x00400000,
        DTSTransfer_Script_DRI_Clustered 			= 0x00800000,
        DTSTransfer_Script_DRI_Checks				= 0x01000000,
        DTSTransfer_Script_DRI_Defaults 			= 0x02000000,
        DTSTransfer_Script_DRI_UniqueKeys 		= 0x04000000,
        DTSTransfer_Script_DRI_ForeignKeys		= 0x08000000,
        DTSTransfer_Script_DRI_PrimaryKey 		= 0x10000000,
        DTSTransfer_Script_DRI_AllKeys 			= 0x1c000000, 	// Bitmask of all key types (PK, FK, Unique).
        DTSTransfer_Script_DRI_AllConstraints 	= 0x1f000000,   // Bitmask of all constraint types (PK, FK, Unique, Check, Default).
        DTSTransfer_Script_DRI_All 				= 0x1fc00000,   // All the foregoing (specifying this and not PrimaryObject gets just DRI output).
        DTSTransfer_Script_DRIWithNoCheck 		= 0x20000000,   // Script DRI with nocheck (not included in _DRI_All).
        DTSTransfer_Script_NoIdentity 			= 0x40000000,   // Script with no IDENTITY attribute (e.g. for Replication).

        DTSTransfer_Script_UseQuotedIdentifiers = 0x80000000,   // Scripts with quoted identifiers. Also will cause Transfer to SET QUOTED_IDENTIFIER ON on the destination.
                                                          // !!! When scripting out from 7.0: StoreProcedure, View and Trigger carry their own QI and AnsiNulls setting
                                                          //     (based on the setting when the original object was created), and this flag does not affect them anymore.
                                                          //     At the end of these object scripting, they set QI to the setting according to this flag,
                                                          //     and AnsiNulls to ON (ODBC default).
} DTS_ENUM_END(DTSTransfer_ScriptOption);

typedef DTS_ENUM_BEGIN(DTSTransfer_ScriptOptionEx, "Specifies extended scripting option. This is in sync with SQLDMO_SCRIPT2_TYPE in SQL-DMO.") {
        // Optional Script parameter.
        DTSTransfer_ScriptEx_TransferDefault  = 0x1010,   // Default
	    DTSTransfer_ScriptEx_AnsiPadding      = 0x0001,   // Explicitly SET ANSI PADDING on or off before the create table
        DTSTransfer_ScriptEx_AnsiFile         = 0x0002,   // Generate ANSI output file
        DTSTransfer_ScriptEx_UnicodeFile      = 0x0004,   // Generate UNICODE output file
        DTSTransfer_ScriptEx_NonStop          = 0x0008,   // When error during script file generation, log error and continue.
                                                   // This is a special case for Convert(scptxfr70.exe), not a general purpose flag
                                                   // If client uses this flag to generate output files, they are running on their own risk
                                                   // This flag affects script out (and only the part used by Convert), it does not affect transfer in.
        DTSTransfer_ScriptEx_NoFG             = 0x0010,   // Do not generate 'ON <filegroup>'. For Replication
        DTSTransfer_ScriptEx_MarkTriggers     = 0x0020,   // Mark system triggers. For Replication single table script only.
        DTSTransfer_ScriptEx_OnlyUserTriggers = 0x0040,   // Only script user triggers. For Replication single table script only.
        DTSTransfer_ScriptEx_EncryptPWD       = 0x0080,   // Script encrypted password for logins
        DTSTransfer_ScriptEx_SeparateXPs      = 0x0100,   // Script XP to a separate file (Convert)
        DTSTransfer_ScriptEx_NoWhatIfIndexes  = 0x0200,   // Do not script What-If indexes (default: script out)
        // Following are SQLAgent related scripting flags
        DTSTransfer_ScriptEx_AgentNotify      = 0x0400,   // Script Notification for SQLAgent alert object
        DTSTransfer_ScriptEx_AgentAlertJob    = 0x0800,   // Include Job in Alert scripting
		//FT-Indexing
        DTSTransfer_ScriptEx_FullTextIndex    = 0x1000,   // Include full-text index scripting (table only)

} DTS_ENUM_END(DTSTransfer_ScriptOptionEx);


typedef DTS_ENUM_BEGIN(DTSBulkInsert_DataFileType, "Specifies the type of datafile used for BULK INSERT") {
	DTSBulkInsert_DataFileType_Char					= 0x0000,
	DTSBulkInsert_DataFileType_Native				= 0x0001,
	DTSBulkInsert_DataFileType_WideChar				= 0x0002,
	DTSBulkInsert_DataFileType_WideNative			= 0x0003,
} DTS_ENUM_END(DTSBulkInsert_DataFileType);

// These are not a bitmask; each implies all prior (lesser-numbered) ones.
typedef DTS_ENUM_BEGIN(DTSLineageOptions, "Specifies how Package Execution Lineage should be presented and recorded") {
	DTSLineage_None							= 0x0000,		// Default
	DTSLineage_AddLineageVariables			= 0x0001,
	DTSLineage_WriteToReposIfAvailable		= 0x0002,
	DTSLineage_WriteToReposRequired			= 0x0003,
} DTS_ENUM_END(DTSLineageOptions);

// This is a bitmask.
typedef DTS_ENUM_BEGIN(DTSFastLoadOptions, "Options specific to PumpTask.UseFastLoad") {
	DTSFastLoad_NoOptions					= 0x0000,
	DTSFastLoad_KeepNulls					= 0x0001,
	DTSFastLoad_CheckConstraints			= 0x0002,
	DTSFastLoad_TableLock					= 0x0004,
	DTSFastLoad_Default						= 0x0002,		// DTSFastLoad_CheckConstraints
} DTS_ENUM_END(DTSFastLoadOptions);

#endif	// DTSPackage_CONSTANTS_

/////////////////////////////////////////////////////////////////////////////////////////
// Interface definitions.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef DTSPackage_ODL_		// Skip if in .odl file.

// Optional parameter definitions.  For C explicit values will have to be specified,
// as indicated within the CPPDEFAULT() expansion.
//
// DTSPackage Parameter sequencing is as follows ("optional" in accordance with C++ usage):
// 	Nonoptional parameters
//		Nonoptional Return value if any
//		Optional additional parameters
//		Optional return value, if any
//
#ifndef CPPDEFAULT
#ifdef __cplusplus
#define CPPDEFAULT(DefaultParamValue)	DefaultParamValue
#else
#define CPPDEFAULT(DefaultParamValue)
#endif
#endif

// Define constants to document parameter usage.
#define DTS_IN
#define DTS_OUT
#define DTS_INOUT
#define DTS_RETVAL

///////////////////////////////////////////////////////////////////////////////////////
// Class definitions and typedefs
///////////////////////////////////////////////////////////////////////////////////////

#ifndef DTSPackage_INTERNAL 

// Forward-define all interfaces.
#define DTS_FWD_DEFINE_INTERFACE(itf)					\
	interface IDTS##itf;								\
	typedef interface IDTS##itf * LPDTS##itf;

DTS_FWD_DEFINE_INTERFACE(StdObject)

// Repeat the IDispatch members because C doesn't provide inheritance.
#define DTSPackage_DISPATCH_BASE(itf)														\
		STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj) PURE;				\
		STDMETHOD_(ULONG,AddRef) (THIS) PURE;												\
		STDMETHOD_(ULONG,Release) (THIS) PURE;												\
		STDMETHOD(GetTypeInfoCount)(THIS_ UINT * pcTypeInfo) PURE;							\
		STDMETHOD(GetTypeInfo)(THIS_ UINT iTypeInfo, LCID lcid, ITypeInfo ** ppTI) PURE;	\
		STDMETHOD(GetIDsOfNames)(THIS_ REFIID riid, LPOLESTR * rgszNames, UINT cNames,		\
								LCID lcid, DISPID * rgdispid) PURE;							\
		STDMETHOD(Invoke)(THIS_ DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags,	\
								DISPPARAMS * pdispparams, LPVARIANT pvarResult,				\
								LPEXCEPINFO pexcepinfo, UINT * puArgErr) PURE;

// This is the base class for all DTSPackage OleAut objects.  It is never instantiated by itself.
// The members are copied into all derived classes so that C clients can reference
// them, since the DECLARE_INTERFACE_ macro doesn't provide inheritance in C.  The
// undef/def of INTERFACE is likewise required for C programmers.
#undef INTERFACE
#define INTERFACE IDTSStdObject
DECLARE_INTERFACE_(INTERFACE, IDispatch)
{
	DTSPackage_DISPATCH_BASE(IDTSStdObject)
};

#endif	// ndef DTSPackage_INTERNAL


/////////////////////////////////////////////////////////////////////////////////
// Define the DTSPackage GUIDGEN templates.
/////////////////////////////////////////////////////////////////////////////////

#define DEFINE_DTSPackage_GUID(name, lval) \
      DEFINE_GUID(name, 0x##lval, 0xEB1C, 0x11CF, 0xAE, 0x6E, 0x0, 0xAA, 0x0, 0x4A, 0x34, 0xD5);
#define DEFINE_DTSPackage_DTSCatID(name, lval) \
      DEFINE_GUID(name, 0x##lval, 0xA282, 0x11D1, 0xB7, 0xD9, 0x0, 0xC0, 0x4F, 0xB6, 0xEF, 0xD5);

/////////////////////////////////////////////////////////////////////////////////
//	SQLDTS Library UUID
/////////////////////////////////////////////////////////////////////////////////
DEFINE_DTSPackage_GUID(LIBID_DTSPackageLibrary, 10010001)

/////////////////////////////////////////////////////////////////////////////////
// Internal base interfaces.
/////////////////////////////////////////////////////////////////////////////////
DEFINE_DTSPackage_GUID(IID_IDTSPrivate, 10010002)
DEFINE_DTSPackage_GUID(IID_IDTSInternal, 1001003)

DEFINE_DTSPackage_GUID(IID_IDTSStdObject, 10010004)

DEFINE_DTSPackage_GUID(IID_IDTSStdCollection, 10010009)

DEFINE_DTSPackage_GUID(CLSID_DTSRunPackage, 1001000A)
DEFINE_DTSPackage_GUID(IID_IDTSRunPackage, 1001000B)

DEFINE_DTSPackage_GUID(IID_IDTSPackageDSODataSource, 10010011)
DEFINE_DTSPackage_GUID(IID_IDTSPackageDSOSession, 10010012)
DEFINE_DTSPackage_GUID(IID_IDTSPackageDSOCommand, 10010013)
DEFINE_DTSPackage_GUID(IID_IDTSPackageDSORowset, 10010014)

DEFINE_DTSPackage_GUID(IID_IDTSRowQueueDataSource, 10010021)
DEFINE_DTSPackage_GUID(IID_IDTSRowQueueSession, 10010022)
DEFINE_DTSPackage_GUID(IID_IDTSRowQueueRowset, 10010023)

/////////////////////////////////////////////////////////////////////////////////
// OLEDB rowset provider CLSIDs
/////////////////////////////////////////////////////////////////////////////////
DEFINE_DTSPackage_GUID(CLSID_DTSPackageDSO, 10010031)
DEFINE_DTSPackage_GUID(CLSID_DTSRowQueue, 10010032)

/////////////////////////////////////////////////////////////////////////////////
// Automation generic-property interfaces
/////////////////////////////////////////////////////////////////////////////////
DEFINE_DTSPackage_GUID(IID_IDTSProperties, 10020001)
DEFINE_DTSPackage_GUID(IID_IDTSProperty, 10020002)

/////////////////////////////////////////////////////////////////////////////////
// Repository OBJID base GUIDs and private management classes.
/////////////////////////////////////////////////////////////////////////////////
DEFINE_DTSPackage_GUID(GUID_DTSSystem, 10020101)
DEFINE_DTSPackage_GUID(GUID_DTSPackageModel, 10020102)
DEFINE_DTSPackage_GUID(CLSID_DTSRepositoryManager, 10020103)
DEFINE_DTSPackage_GUID(IID_IDTSRepositoryManager, 10020104)
DEFINE_DTSPackage_GUID(IID_IDTSRepositoryPackageEnum, 10020105)
DEFINE_DTSPackage_GUID(GUID_DTSDataSourceModel, 10020106)

DEFINE_DTSPackage_GUID(IID_IDTSRepositoryPackageLineageEnum, 10020107)
DEFINE_DTSPackage_GUID(IID_IDTSRepositoryDataSourceEnum, 10020108)
DEFINE_DTSPackage_GUID(IID_IDTSRepositoryCatalogEnum, 10020109)
DEFINE_DTSPackage_GUID(IID_IDTSRepositoryStepLineageEnum, 10020110)

/////////////////////////////////////////////////////////////////////////////////
// Category id of DTS custom tasks.
/////////////////////////////////////////////////////////////////////////////////
DEFINE_DTSPackage_GUID(CATID_DTSCustomTask, 10020200)	//we will use the same id as the Package clsid.

/////////////////////////////////////////////////////////////////////////////////
// DTS Category id (not COM category ID) of DTS SQL Server categories.
/////////////////////////////////////////////////////////////////////////////////
DEFINE_DTSPackage_DTSCatID(DTSCATID_Local, B8C30000)
DEFINE_DTSPackage_DTSCatID(DTSCATID_Repository, B8C30001)
DEFINE_DTSPackage_DTSCatID(DTSCATID_LocalDefault, B8C30002)

/////////////////////////////////////////////////////////////////////////////////
// DTS Package interfaces
/////////////////////////////////////////////////////////////////////////////////

DEFINE_DTSPackage_GUID(CLSID_DTSPackage, 10020200)
DEFINE_DTSPackage_GUID(CLSID_DTSPropertiesProvider, 10020201)

DEFINE_DTSPackage_GUID(IID_IDTSPackage, 10020205)
DEFINE_DTSPackage_GUID(IID_IDTSPropertiesProvider, 10020206)

DEFINE_DTSPackage_GUID(IID_IDTSSteps, 10020302)
DEFINE_DTSPackage_GUID(IID_IDTSStep, 10020305)

DEFINE_DTSPackage_GUID(IID_IDTSColumns, 10020402)
DEFINE_DTSPackage_GUID(IID_IDTSColumn, 10020405)

DEFINE_DTSPackage_GUID(IID_IDTSLookups, 10020502)
DEFINE_DTSPackage_GUID(IID_IDTSLookup, 10020505)

DEFINE_DTSPackage_GUID(IID_IDTSPackageEvents, 10020605)

DEFINE_DTSPackage_GUID(IID_IDTSPackageLog, 10020705)

DEFINE_DTSPackage_GUID(IID_IDTSCustomTask, 10020904)
DEFINE_DTSPackage_GUID(IID_IDTSTasks, 10020905)
DEFINE_DTSPackage_GUID(IID_IDTSTask, 10020906)

DEFINE_DTSPackage_GUID(IID_IDTSActiveScriptTask, 10020907)
DEFINE_DTSPackage_GUID(IID_IDTSDataPumpTask, 10020908)
DEFINE_DTSPackage_GUID(IID_IDTSCreateProcessTask, 10020909)
DEFINE_DTSPackage_GUID(IID_IDTSExecPackageTask, 1002090B)
DEFINE_DTSPackage_GUID(IID_IDTSExecuteSQLTask, 1002090C)
DEFINE_DTSPackage_GUID(IID_IDTSDataDrivenQueryTask, 1002090D)
DEFINE_DTSPackage_GUID(IID_IDTSTransferObjectsTask, 1002090E)
DEFINE_DTSPackage_GUID(IID_IDTSSendMailTask, 1002090F)
DEFINE_DTSPackage_GUID(IID_IDTSBulkInsertTask, 10020910)

//Though we define these class ids these are used just to identify our internally
//implemented task objects. These cannot be cocreated.
DEFINE_DTSPackage_GUID(CLSID_DTSActiveScriptTask, 10020907)
DEFINE_DTSPackage_GUID(CLSID_DTSDataPumpTask, 10020908)
DEFINE_DTSPackage_GUID(CLSID_DTSCreateProcessTask, 10020909)
DEFINE_DTSPackage_GUID(CLSID_DTSExecPackageTask, 1002090B)
DEFINE_DTSPackage_GUID(CLSID_DTSExecuteSQLTask, 1002090C)
DEFINE_DTSPackage_GUID(CLSID_DTSDataDrivenQueryTask, 1002090D)
DEFINE_DTSPackage_GUID(CLSID_DTSTransferObjectsTask, 1002090E)
DEFINE_DTSPackage_GUID(CLSID_DTSSendMailTask, 1002090F)
DEFINE_DTSPackage_GUID(CLSID_DTSBulkInsertTask, 10020910)

DEFINE_DTSPackage_GUID(IID_IDTSGlobalVariables, 10020A05)
DEFINE_DTSPackage_GUID(IID_IDTSGlobalVariable, 10020A06)

DEFINE_DTSPackage_GUID(IID_IDTSPrecedenceConstraints, 10020B05)
DEFINE_DTSPackage_GUID(IID_IDTSPrecedenceConstraint, 10020B06)

DEFINE_DTSPackage_GUID(IID_IDTSConnections, 10020C05)
DEFINE_DTSPackage_GUID(IID_IDTSConnection, 10020C06)

DEFINE_DTSPackage_GUID(IID_IDTSTransformations, 10020D05)
DEFINE_DTSPackage_GUID(IID_IDTSTransformation, 10020D06)

DEFINE_DTSPackage_GUID(IID_IDTSOleDBProperties, 10020E05)
DEFINE_DTSPackage_GUID(IID_IDTSOleDBProperty, 10020E06)

DEFINE_DTSPackage_GUID(IID_IDTSSavedPackageInfos, 10020F05)
DEFINE_DTSPackage_GUID(IID_IDTSSavedPackageInfo, 10020F06)

DEFINE_DTSPackage_GUID(IID_IDTSPropertyBag, 10021005)
DEFINE_DTSPackage_GUID(IID_IDTSPersistPropertyBag, 10021006)

DEFINE_DTSPackage_GUID(IID_IDTSCustomTaskUI, 10022005)
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////





/* DTSPackage Automation interface definitions generated:  11/13/1998, 00:30:30 */

/* Forward definitions */

DTS_FWD_DEFINE_INTERFACE(Properties)		// LPDTSProperties
DTS_FWD_DEFINE_INTERFACE(Property)		// LPDTSProperty
DTS_FWD_DEFINE_INTERFACE(Package)		// LPDTSPackage
DTS_FWD_DEFINE_INTERFACE(PropertiesProvider)		// LPDTSPropertiesProvider
DTS_FWD_DEFINE_INTERFACE(Steps)		// LPDTSSteps
DTS_FWD_DEFINE_INTERFACE(Step)		// LPDTSStep
DTS_FWD_DEFINE_INTERFACE(Tasks)		// LPDTSTasks
DTS_FWD_DEFINE_INTERFACE(Task)		// LPDTSTask
DTS_FWD_DEFINE_INTERFACE(CustomTask)		// LPDTSCustomTask
DTS_FWD_DEFINE_INTERFACE(ActiveScriptTask)		// LPDTSActiveScriptTask
DTS_FWD_DEFINE_INTERFACE(DataPumpTask)		// LPDTSDataPumpTask
DTS_FWD_DEFINE_INTERFACE(CreateProcessTask)		// LPDTSCreateProcessTask
DTS_FWD_DEFINE_INTERFACE(ExecuteSQLTask)		// LPDTSExecuteSQLTask
DTS_FWD_DEFINE_INTERFACE(DataDrivenQueryTask)		// LPDTSDataDrivenQueryTask
DTS_FWD_DEFINE_INTERFACE(TransferObjectsTask)		// LPDTSTransferObjectsTask
DTS_FWD_DEFINE_INTERFACE(SendMailTask)		// LPDTSSendMailTask
DTS_FWD_DEFINE_INTERFACE(BulkInsertTask)		// LPDTSBulkInsertTask
DTS_FWD_DEFINE_INTERFACE(GlobalVariables)		// LPDTSGlobalVariables
DTS_FWD_DEFINE_INTERFACE(GlobalVariable)		// LPDTSGlobalVariable
DTS_FWD_DEFINE_INTERFACE(PrecedenceConstraints)		// LPDTSPrecedenceConstraints
DTS_FWD_DEFINE_INTERFACE(PrecedenceConstraint)		// LPDTSPrecedenceConstraint
DTS_FWD_DEFINE_INTERFACE(OleDBProperties)		// LPDTSOleDBProperties
DTS_FWD_DEFINE_INTERFACE(OleDBProperty)		// LPDTSOleDBProperty
DTS_FWD_DEFINE_INTERFACE(Connections)		// LPDTSConnections
DTS_FWD_DEFINE_INTERFACE(Connection)		// LPDTSConnection
DTS_FWD_DEFINE_INTERFACE(Transformations)		// LPDTSTransformations
DTS_FWD_DEFINE_INTERFACE(Transformation)		// LPDTSTransformation
DTS_FWD_DEFINE_INTERFACE(Columns)		// LPDTSColumns
DTS_FWD_DEFINE_INTERFACE(Column)		// LPDTSColumn
DTS_FWD_DEFINE_INTERFACE(Lookups)		// LPDTSLookups
DTS_FWD_DEFINE_INTERFACE(Lookup)		// LPDTSLookup
DTS_FWD_DEFINE_INTERFACE(SavedPackageInfo)		// LPDTSSavedPackageInfo
DTS_FWD_DEFINE_INTERFACE(SavedPackageInfos)		// LPDTSSavedPackageInfos
DTS_FWD_DEFINE_INTERFACE(PropertyBag)		// LPDTSPropertyBag
DTS_FWD_DEFINE_INTERFACE(PersistPropertyBag)		// LPDTSPersistPropertyBag
DTS_FWD_DEFINE_INTERFACE(PackageEvents)		// LPDTSPackageEvents
DTS_FWD_DEFINE_INTERFACE(PackageLog)		// LPDTSPackageLog
DTS_FWD_DEFINE_INTERFACE(CustomTaskUI)		// LPDTSCustomTaskUI

/* Interface definitions */

#undef INTERFACE
#define INTERFACE IDTSProperties
DECLARE_INTERFACE_(IDTSProperties, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSProperties)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSProperty **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSProperty
DECLARE_INTERFACE_(IDTSProperty, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSProperty)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetValue)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetValue)(THIS_ DTS_IN VARIANT NewValue) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetType)(THIS_ DTS_RETVAL long *pRetVal) PURE;
	STDMETHOD(GetGet)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(GetSet)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSPackage
DECLARE_INTERFACE_(IDTSPackage, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSPackage)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetSteps)(THIS_ DTS_RETVAL IDTSSteps **pRetVal) PURE;
	STDMETHOD(GetTasks)(THIS_ DTS_RETVAL IDTSTasks **pRetVal) PURE;
	STDMETHOD(GetConnections)(THIS_ DTS_RETVAL IDTSConnections **pRetVal) PURE;
	STDMETHOD(GetGlobalVariables)(THIS_ DTS_RETVAL IDTSGlobalVariables **pRetVal) PURE;
	STDMETHOD(GetPackageID)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetWriteCompletionStatusToNTEventLog)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetWriteCompletionStatusToNTEventLog)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetLogFileName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetLogFileName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetFailOnError)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetFailOnError)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetVersionID)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetCreatorName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetCreatorComputerName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetCreationDate)(THIS_ DTS_RETVAL DATE *pRetVal) PURE;
	STDMETHOD(GetPackagePriorityClass)(THIS_ DTS_RETVAL DTSPackagePriorityClass *pRetVal) PURE;
	STDMETHOD(SetPackagePriorityClass)(THIS_ DTS_IN DTSPackagePriorityClass NewValue) PURE;
	STDMETHOD(GetMaxConcurrentSteps)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetMaxConcurrentSteps)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(Execute)(THIS) PURE;
	STDMETHOD(SaveToStorageFile)(THIS_ DTS_IN BSTR UNCFile,
		DTS_IN BSTR OwnerPassword CPPDEFAULT(= NULL),
		DTS_IN BSTR OperatorPassword CPPDEFAULT(= NULL),
		DTS_IN VARIANT *pVarPersistStgOfHost CPPDEFAULT(= NULL),
		DTS_IN VARIANT_BOOL bReusePasswords CPPDEFAULT(= VARIANT_TRUE)) PURE;
	STDMETHOD(SaveToRepository)(THIS_ DTS_IN BSTR RepositoryServerName,
		DTS_IN BSTR RepositoryDatabaseName,
		DTS_IN BSTR RepositoryUserName,
		DTS_IN BSTR RepositoryUserPassword,
		DTS_IN DTSRepositoryStorageFlags Flags CPPDEFAULT(= DTSReposFlag_Default),
		DTS_IN BSTR CategoryID CPPDEFAULT(= NULL),
		DTS_IN VARIANT *pVarPersistStgOfHost CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(RemoveFromRepository)(THIS_ DTS_IN BSTR RepositoryServerName,
		DTS_IN BSTR RepositoryDatabaseName,
		DTS_IN BSTR RepositoryUserName,
		DTS_IN BSTR RepositoryUserPassword,
		DTS_IN BSTR PackageID,
		DTS_IN BSTR VersionID CPPDEFAULT(= NULL),
		DTS_IN BSTR PackageName CPPDEFAULT(= NULL),
		DTS_IN DTSRepositoryStorageFlags Flags CPPDEFAULT(= DTSReposFlag_Default)) PURE;
	STDMETHOD(LoadFromStorageFile)(THIS_ DTS_IN BSTR UNCFile,
		DTS_IN BSTR Password,
		DTS_IN BSTR PackageID,
		DTS_IN BSTR VersionID CPPDEFAULT(= NULL),
		DTS_IN BSTR Name CPPDEFAULT(= NULL),
		DTS_IN VARIANT *pVarPersistStgOfHost CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(LoadFromRepository)(THIS_ DTS_IN BSTR RepositoryServerName,
		DTS_IN BSTR RepositoryDatabaseName,
		DTS_IN BSTR RepositoryUserName,
		DTS_IN BSTR RepositoryUserPassword,
		DTS_IN BSTR PackageID,
		DTS_IN BSTR VersionID CPPDEFAULT(= NULL),
		DTS_IN BSTR PackageName CPPDEFAULT(= NULL),
		DTS_IN DTSRepositoryStorageFlags Flags CPPDEFAULT(= DTSReposFlag_Default),
		DTS_IN VARIANT *pVarPersistStgOfHost CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(GetSavedPackageInfos)(THIS_ DTS_IN BSTR UNCFile,
		DTS_RETVAL IDTSSavedPackageInfos **pRetVal) PURE;
	STDMETHOD(UnInitialize)(THIS) PURE;
	STDMETHOD(SaveToSQLServer)(THIS_ DTS_IN BSTR ServerName,
		DTS_IN BSTR ServerUserName,
		DTS_IN BSTR ServerPassword,
		DTS_IN DTSSQLServerStorageFlags Flags CPPDEFAULT(= DTSSQLStgFlag_Default),
		DTS_IN BSTR PackageOwnerPassword CPPDEFAULT(= NULL),
		DTS_IN BSTR PackageOperatorPassword CPPDEFAULT(= NULL),
		DTS_IN BSTR PackageCategoryID CPPDEFAULT(= NULL),
		DTS_IN VARIANT *pVarPersistStgOfHost CPPDEFAULT(= NULL),
		DTS_IN VARIANT_BOOL bReusePasswords CPPDEFAULT(= VARIANT_TRUE)) PURE;
	STDMETHOD(LoadFromSQLServer)(THIS_ DTS_IN BSTR ServerName,
		DTS_IN BSTR ServerUserName,
		DTS_IN BSTR ServerPassword,
		DTS_IN DTSSQLServerStorageFlags Flags CPPDEFAULT(= DTSSQLStgFlag_Default),
		DTS_IN BSTR PackagePassword CPPDEFAULT(= NULL),
		DTS_IN BSTR PackageGuid CPPDEFAULT(= NULL),
		DTS_IN BSTR PackageVersionGuid CPPDEFAULT(= NULL),
		DTS_IN BSTR PackageName CPPDEFAULT(= NULL),
		DTS_IN VARIANT *pVarPersistStgOfHost CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(RemoveFromSQLServer)(THIS_ DTS_IN BSTR ServerName,
		DTS_IN BSTR ServerUserName,
		DTS_IN BSTR ServerPassword,
		DTS_IN DTSSQLServerStorageFlags Flags CPPDEFAULT(= DTSSQLStgFlag_Default),
		DTS_IN BSTR PackageGuid CPPDEFAULT(= NULL),
		DTS_IN BSTR PackageVersionGuid CPPDEFAULT(= NULL),
		DTS_IN BSTR PackageName CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(SaveAs)(THIS_ DTS_IN BSTR NewName) PURE;
	STDMETHOD(GetDTSVersionInfo)(THIS_ DTS_OUT long *VersionMajor,
		DTS_OUT long *VersionMinor,
		DTS_OUT long *VersionBuild,
		DTS_OUT BSTR *VersionComments) PURE;
	STDMETHOD(GetLineageOptions)(THIS_ DTS_RETVAL DTSLineageOptions *pRetVal) PURE;
	STDMETHOD(SetLineageOptions)(THIS_ DTS_IN DTSLineageOptions NewValue) PURE;
	STDMETHOD(GetUseTransaction)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetUseTransaction)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetTransactionIsolationLevel)(THIS_ DTS_RETVAL DTSIsolationLevel *pRetVal) PURE;
	STDMETHOD(SetTransactionIsolationLevel)(THIS_ DTS_IN DTSIsolationLevel NewValue) PURE;
	STDMETHOD(GetAutoCommitTransaction)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetAutoCommitTransaction)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetRepositoryMetadataOptions)(THIS_ DTS_RETVAL DTSRepositoryMetadataOptions *pRetVal) PURE;
	STDMETHOD(SetRepositoryMetadataOptions)(THIS_ DTS_IN DTSRepositoryMetadataOptions NewValue) PURE;
	STDMETHOD(GetUseOLEDBServiceComponents)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetUseOLEDBServiceComponents)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetLastExecutionLineage)(THIS_ DTS_OUT long *LineageShort,
		DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(StartPreparationForStepsExecutingOnMainThread)(THIS) PURE;
	STDMETHOD(EndPreparationForStepsExecutingOnMainThread)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSPropertiesProvider
DECLARE_INTERFACE_(IDTSPropertiesProvider, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSPropertiesProvider)

	STDMETHOD(GetPropertiesForObject)(THIS_ DTS_IN IDispatch *pObject,
		DTS_RETVAL IDTSProperties **pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSSteps
DECLARE_INTERFACE_(IDTSSteps, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSSteps)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSStep **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
	STDMETHOD(Add)(THIS_ DTS_IN IDTSStep *Object) PURE;
	STDMETHOD(Remove)(THIS_ DTS_IN VARIANT Index) PURE;
	STDMETHOD(Insert)(THIS_ DTS_IN VARIANT Position,
		DTS_IN IDTSStep *Object) PURE;
	STDMETHOD(New)(THIS_ DTS_RETVAL IDTSStep **pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSStep
DECLARE_INTERFACE_(IDTSStep, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSStep)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetPrecedenceConstraints)(THIS_ DTS_RETVAL IDTSPrecedenceConstraints **pRetVal) PURE;
	STDMETHOD(GetExecutionStatus)(THIS_ DTS_RETVAL DTSStepExecStatus *pRetVal) PURE;
	STDMETHOD(SetExecutionStatus)(THIS_ DTS_IN DTSStepExecStatus NewValue) PURE;
	STDMETHOD(GetExecutionResult)(THIS_ DTS_RETVAL DTSStepExecResult *pRetVal) PURE;
	STDMETHOD(GetTaskName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetTaskName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetCommitSuccess)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetCommitSuccess)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetRollbackFailure)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetRollbackFailure)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetActiveXScript)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetActiveXScript)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetScriptLanguage)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetScriptLanguage)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetFunctionName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetFunctionName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetAddGlobalVariables)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetAddGlobalVariables)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetRelativePriority)(THIS_ DTS_RETVAL DTSStepRelativePriority *pRetVal) PURE;
	STDMETHOD(SetRelativePriority)(THIS_ DTS_IN DTSStepRelativePriority NewValue) PURE;
	STDMETHOD(GetCloseConnection)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetCloseConnection)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetExecuteInMainThread)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetExecuteInMainThread)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetIsPackageDSORowset)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetIsPackageDSORowset)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(Execute)(THIS) PURE;
	STDMETHOD(GetExecutionErrorInfo)(THIS_ DTS_OUT long *pErrorCode,
		DTS_OUT BSTR *pbstrSource,
		DTS_OUT BSTR *pbstrDescription,
		DTS_OUT BSTR *pbstrHelpFile,
		DTS_OUT long *pHelpContext,
		DTS_OUT BSTR *pbstrIDofInterfaceWithError) PURE;
	STDMETHOD(GetJoinTransactionIfPresent)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetJoinTransactionIfPresent)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetStartTime)(THIS_ DTS_RETVAL DATE *pRetVal) PURE;
	STDMETHOD(GetFinishTime)(THIS_ DTS_RETVAL DATE *pRetVal) PURE;
	STDMETHOD(GetExecutionTime)(THIS_ DTS_RETVAL double *pRetVal) PURE;
	STDMETHOD(GetDisableStep)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetDisableStep)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSTasks
DECLARE_INTERFACE_(IDTSTasks, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSTasks)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSTask **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
	STDMETHOD(Add)(THIS_ DTS_IN IDTSTask *Object) PURE;
	STDMETHOD(Remove)(THIS_ DTS_IN VARIANT Index) PURE;
	STDMETHOD(Insert)(THIS_ DTS_IN VARIANT Position,
		DTS_IN IDTSTask *Object) PURE;
	STDMETHOD(New)(THIS_ DTS_IN BSTR bstrID,
		DTS_RETVAL IDTSTask **pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSTask
DECLARE_INTERFACE_(IDTSTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSTask)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
	STDMETHOD(GetCustomTask)(THIS_ DTS_RETVAL IDTSCustomTask **pRetVal) PURE;
	STDMETHOD(GetCustomTaskID)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSCustomTask
DECLARE_INTERFACE_(IDTSCustomTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSCustomTask)

	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSActiveScriptTask
DECLARE_INTERFACE_(IDTSActiveScriptTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSActiveScriptTask)

	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
	STDMETHOD(CheckSyntax)(THIS) PURE;
	STDMETHOD(GetActiveXScript)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetActiveXScript)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetFunctionName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetFunctionName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetScriptLanguage)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetScriptLanguage)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetAddGlobalVariables)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetAddGlobalVariables)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSDataPumpTask
DECLARE_INTERFACE_(IDTSDataPumpTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSDataPumpTask)

	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
	STDMETHOD(GetSourceConnectionID)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetSourceConnectionID)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetSourceObjectName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSourceObjectName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetSourceSQLStatement)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSourceSQLStatement)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDestinationConnectionID)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetDestinationConnectionID)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetDestinationObjectName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDestinationObjectName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDestinationSQLStatement)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDestinationSQLStatement)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetProgressRowCount)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetProgressRowCount)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetMaximumErrorCount)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetMaximumErrorCount)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetExceptionFileName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetExceptionFileName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetFetchBufferSize)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetFetchBufferSize)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetSourceCommandProperties)(THIS_ DTS_RETVAL IDTSOleDBProperties **pRetVal) PURE;
	STDMETHOD(GetDestinationCommandProperties)(THIS_ DTS_RETVAL IDTSOleDBProperties **pRetVal) PURE;
	STDMETHOD(GetTransformations)(THIS_ DTS_RETVAL IDTSTransformations **pRetVal) PURE;
	STDMETHOD(GetUseFastLoad)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetUseFastLoad)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetInsertCommitSize)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetInsertCommitSize)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetDestinationColumnDefinitions)(THIS_ DTS_RETVAL IDTSColumns **pRetVal) PURE;
	STDMETHOD(GetExceptionFileColumnDelimiter)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetExceptionFileColumnDelimiter)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetExceptionFileRowDelimiter)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetExceptionFileRowDelimiter)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetLookups)(THIS_ DTS_RETVAL IDTSLookups **pRetVal) PURE;
	STDMETHOD(GetAllowIdentityInserts)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetAllowIdentityInserts)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetFirstRow)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetFirstRow)(THIS_ DTS_IN VARIANT NewValue) PURE;
	STDMETHOD(GetLastRow)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetLastRow)(THIS_ DTS_IN VARIANT NewValue) PURE;
	STDMETHOD(GetFastLoadOptions)(THIS_ DTS_RETVAL DTSFastLoadOptions *pRetVal) PURE;
	STDMETHOD(SetFastLoadOptions)(THIS_ DTS_IN DTSFastLoadOptions NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSCreateProcessTask
DECLARE_INTERFACE_(IDTSCreateProcessTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSCreateProcessTask)

	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
	STDMETHOD(GetProcessCommandLine)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetProcessCommandLine)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetSuccessReturnCode)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetSuccessReturnCode)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetTimeout)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetTimeout)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetTerminateProcessAfterTimeout)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetTerminateProcessAfterTimeout)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetFailPackageOnTimeout)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetFailPackageOnTimeout)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSExecuteSQLTask
DECLARE_INTERFACE_(IDTSExecuteSQLTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSExecuteSQLTask)

	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
	STDMETHOD(GetSQLStatement)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSQLStatement)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetConnectionID)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetConnectionID)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetCommandTimeout)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetCommandTimeout)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetCommandProperties)(THIS_ DTS_RETVAL IDTSOleDBProperties **pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSDataDrivenQueryTask
DECLARE_INTERFACE_(IDTSDataDrivenQueryTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSDataDrivenQueryTask)

	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
	STDMETHOD(GetSourceConnectionID)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetSourceConnectionID)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetSourceObjectName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSourceObjectName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetSourceSQLStatement)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSourceSQLStatement)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDestinationConnectionID)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetDestinationConnectionID)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetDestinationObjectName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDestinationObjectName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDestinationSQLStatement)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDestinationSQLStatement)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetProgressRowCount)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetProgressRowCount)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetMaximumErrorCount)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetMaximumErrorCount)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetExceptionFileName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetExceptionFileName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetFetchBufferSize)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetFetchBufferSize)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetSourceCommandProperties)(THIS_ DTS_RETVAL IDTSOleDBProperties **pRetVal) PURE;
	STDMETHOD(GetDestinationCommandProperties)(THIS_ DTS_RETVAL IDTSOleDBProperties **pRetVal) PURE;
	STDMETHOD(GetTransformations)(THIS_ DTS_RETVAL IDTSTransformations **pRetVal) PURE;
	STDMETHOD(GetLookups)(THIS_ DTS_RETVAL IDTSLookups **pRetVal) PURE;
	STDMETHOD(GetDestinationColumnDefinitions)(THIS_ DTS_RETVAL IDTSColumns **pRetVal) PURE;
	STDMETHOD(GetInsertQuery)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetInsertQuery)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetInsertQueryColumns)(THIS_ DTS_RETVAL IDTSColumns **pRetVal) PURE;
	STDMETHOD(GetUpdateQuery)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetUpdateQuery)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetUpdateQueryColumns)(THIS_ DTS_RETVAL IDTSColumns **pRetVal) PURE;
	STDMETHOD(GetDeleteQuery)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDeleteQuery)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDeleteQueryColumns)(THIS_ DTS_RETVAL IDTSColumns **pRetVal) PURE;
	STDMETHOD(GetUserQuery)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetUserQuery)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetUserQueryColumns)(THIS_ DTS_RETVAL IDTSColumns **pRetVal) PURE;
	STDMETHOD(GetExceptionFileColumnDelimiter)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetExceptionFileColumnDelimiter)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetExceptionFileRowDelimiter)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetExceptionFileRowDelimiter)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetFirstRow)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetFirstRow)(THIS_ DTS_IN VARIANT NewValue) PURE;
	STDMETHOD(GetLastRow)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetLastRow)(THIS_ DTS_IN VARIANT NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSTransferObjectsTask
DECLARE_INTERFACE_(IDTSTransferObjectsTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSTransferObjectsTask)

	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
	STDMETHOD(AddObjectForTransfer)(THIS_ DTS_IN BSTR ObjectName,
		DTS_IN BSTR OwnerName,
		DTS_IN DTSSQLObjectType Type) PURE;
	STDMETHOD(GetObjectForTransfer)(THIS_ DTS_IN LONG Index,
		DTS_OUT BSTR *ObjectName,
		DTS_OUT BSTR *OwnerName,
		DTS_OUT DTSSQLObjectType *Type) PURE;
	STDMETHOD(ResetObjectsList)(THIS) PURE;
	STDMETHOD(CancelExecution)(THIS) PURE;
	STDMETHOD(GetSourceServer)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSourceServer)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetSourceLogin)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSourceLogin)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetSourcePassword)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSourcePassword)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetSourceUseTrustedConnection)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetSourceUseTrustedConnection)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetSourceDatabase)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSourceDatabase)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDestinationServer)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDestinationServer)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDestinationLogin)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDestinationLogin)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDestinationPassword)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDestinationPassword)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDestinationUseTrustedConnection)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetDestinationUseTrustedConnection)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetDestinationDatabase)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDestinationDatabase)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetScriptFileDirectory)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetScriptFileDirectory)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetCopyAllObjects)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetCopyAllObjects)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetIncludeDependencies)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetIncludeDependencies)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetIncludeLogins)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetIncludeLogins)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetIncludeUsers)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetIncludeUsers)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetDropDestinationObjectsFirst)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetDropDestinationObjectsFirst)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetCopySchema)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetCopySchema)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetCopyData)(THIS_ DTS_RETVAL DTSTransfer_CopyDataOption *pRetVal) PURE;
	STDMETHOD(SetCopyData)(THIS_ DTS_IN DTSTransfer_CopyDataOption NewValue) PURE;
	STDMETHOD(GetScriptOption)(THIS_ DTS_RETVAL DTSTransfer_ScriptOption *pRetVal) PURE;
	STDMETHOD(SetScriptOption)(THIS_ DTS_IN DTSTransfer_ScriptOption NewValue) PURE;
	STDMETHOD(GetScriptOptionEx)(THIS_ DTS_RETVAL DTSTransfer_ScriptOptionEx *pRetVal) PURE;
	STDMETHOD(SetScriptOptionEx)(THIS_ DTS_IN DTSTransfer_ScriptOptionEx NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSSendMailTask
DECLARE_INTERFACE_(IDTSSendMailTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSSendMailTask)

	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
	STDMETHOD(InitializeMAPI)(THIS) PURE;
	STDMETHOD(UnInitializeMAPI)(THIS) PURE;
	STDMETHOD(Logon)(THIS_ DTS_RETVAL BSTR *ErrorString) PURE;
	STDMETHOD(Logoff)(THIS) PURE;
	STDMETHOD(ResolveName)(THIS_ DTS_IN BSTR Address,
		DTS_RETVAL BSTR *ErrorString) PURE;
	STDMETHOD(GetDefaultProfileName)(THIS_ DTS_RETVAL BSTR *DefaultProfile) PURE;
	STDMETHOD(ShowAddressBook)(THIS_ DTS_IN long hwndParent,
		DTS_RETVAL BSTR *Address) PURE;
	STDMETHOD(GetProfile)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetProfile)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetPassword)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetPassword)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetToLine)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetToLine)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetCCLine)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetCCLine)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetSubject)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSubject)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetMessageText)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetMessageText)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetFileAttachments)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetFileAttachments)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetIsNTService)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetIsNTService)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetSaveMailInSentItemsFolder)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetSaveMailInSentItemsFolder)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSBulkInsertTask
DECLARE_INTERFACE_(IDTSBulkInsertTask, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSBulkInsertTask)

	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(Execute)(THIS_ DTS_IN IDispatch *pPackage,
		DTS_IN IDispatch *pPackageEvents,
		DTS_IN IDispatch *pPackageLog,
		DTS_OUT DTSTaskExecResult *pTaskResult) PURE;
	STDMETHOD(GetDestinationTableName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDestinationTableName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetConnectionID)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetConnectionID)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetBatchSize)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetBatchSize)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetCheckConstraints)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetCheckConstraints)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetCodepage)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetCodepage)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDataFile)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDataFile)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDataFileType)(THIS_ DTS_RETVAL DTSBulkInsert_DataFileType *pRetVal) PURE;
	STDMETHOD(SetDataFileType)(THIS_ DTS_IN DTSBulkInsert_DataFileType NewValue) PURE;
	STDMETHOD(GetFieldTerminator)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetFieldTerminator)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetRowTerminator)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetRowTerminator)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetFormatFile)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetFormatFile)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetFirstRow)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetFirstRow)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetLastRow)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetLastRow)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetKeepIdentity)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetKeepIdentity)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetKeepNulls)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetKeepNulls)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetMaximumErrors)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetMaximumErrors)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetSortedData)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetSortedData)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetTableLock)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetTableLock)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSGlobalVariables
DECLARE_INTERFACE_(IDTSGlobalVariables, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSGlobalVariables)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSGlobalVariable **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
	STDMETHOD(Add)(THIS_ DTS_IN IDTSGlobalVariable *Object) PURE;
	STDMETHOD(Remove)(THIS_ DTS_IN VARIANT Index) PURE;
	STDMETHOD(Insert)(THIS_ DTS_IN VARIANT Position,
		DTS_IN IDTSGlobalVariable *Object) PURE;
	STDMETHOD(New)(THIS_ DTS_IN BSTR Name,
		DTS_RETVAL IDTSGlobalVariable **pRetVal) PURE;
	STDMETHOD(AddGlobalVariable)(THIS_ DTS_IN BSTR Name,
		DTS_IN VARIANT Value) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSGlobalVariable
DECLARE_INTERFACE_(IDTSGlobalVariable, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSGlobalVariable)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetValue)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetValue)(THIS_ DTS_IN VARIANT NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSPrecedenceConstraints
DECLARE_INTERFACE_(IDTSPrecedenceConstraints, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSPrecedenceConstraints)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSPrecedenceConstraint **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
	STDMETHOD(Add)(THIS_ DTS_IN IDTSPrecedenceConstraint *Object) PURE;
	STDMETHOD(Remove)(THIS_ DTS_IN VARIANT Index) PURE;
	STDMETHOD(Insert)(THIS_ DTS_IN VARIANT Position,
		DTS_IN IDTSPrecedenceConstraint *Object) PURE;
	STDMETHOD(New)(THIS_ DTS_IN BSTR StepName,
		DTS_RETVAL IDTSPrecedenceConstraint **pRetVal) PURE;
	STDMETHOD(AddConstraint)(THIS_ DTS_IN BSTR StepName) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSPrecedenceConstraint
DECLARE_INTERFACE_(IDTSPrecedenceConstraint, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSPrecedenceConstraint)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetStepName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetStepName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetPrecedenceBasis)(THIS_ DTS_RETVAL DTSStepPrecedenceBasis *pRetVal) PURE;
	STDMETHOD(SetPrecedenceBasis)(THIS_ DTS_IN DTSStepPrecedenceBasis NewValue) PURE;
	STDMETHOD(GetValue)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetValue)(THIS_ DTS_IN VARIANT NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSOleDBProperties
DECLARE_INTERFACE_(IDTSOleDBProperties, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSOleDBProperties)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSOleDBProperty **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSOleDBProperty
DECLARE_INTERFACE_(IDTSOleDBProperty, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSOleDBProperty)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetValue)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetValue)(THIS_ DTS_IN VARIANT NewValue) PURE;
	STDMETHOD(GetPropertySet)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetPropertyID)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSConnections
DECLARE_INTERFACE_(IDTSConnections, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSConnections)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSConnection **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
	STDMETHOD(Add)(THIS_ DTS_IN IDTSConnection *Object) PURE;
	STDMETHOD(Remove)(THIS_ DTS_IN VARIANT Index) PURE;
	STDMETHOD(Insert)(THIS_ DTS_IN VARIANT Position,
		DTS_IN IDTSConnection *Object) PURE;
	STDMETHOD(New)(THIS_ DTS_IN BSTR ProviderID,
		DTS_RETVAL IDTSConnection **pRetVal) PURE;
	STDMETHOD(BeginAcquireMultipleConnections)(THIS) PURE;
	STDMETHOD(EndAcquireMultipleConnections)(THIS) PURE;
	STDMETHOD(NewDataLink)(THIS_ DTS_IN BSTR UDLPath,
		DTS_RETVAL IDTSConnection **pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSConnection
DECLARE_INTERFACE_(IDTSConnection, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSConnection)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDescription)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetID)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetID)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetReusable)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetReusable)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetConnectImmediate)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetConnectImmediate)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetConnected)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(GetInUse)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(GetConnectionProperties)(THIS_ DTS_RETVAL IDTSOleDBProperties **pRetVal) PURE;
	STDMETHOD(GetLastOwnerTaskName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetDataSource)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetDataSource)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetUserID)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetUserID)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetPassword)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetPassword)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetConnectionTimeout)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetConnectionTimeout)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetProviderID)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetCatalog)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetCatalog)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetUseTrustedConnection)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetUseTrustedConnection)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(AcquireConnection)(THIS_ DTS_IN BSTR TaskName,
		DTS_RETVAL LPUNKNOWN *pRetVal) PURE;
	STDMETHOD(ReleaseConnection)(THIS) PURE;
	STDMETHOD(GetInTransaction)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(GetUseDSL)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetUseDSL)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetUDLPath)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSTransformations
DECLARE_INTERFACE_(IDTSTransformations, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSTransformations)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSTransformation **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
	STDMETHOD(Add)(THIS_ DTS_IN IDTSTransformation *Object) PURE;
	STDMETHOD(Remove)(THIS_ DTS_IN VARIANT Index) PURE;
	STDMETHOD(Insert)(THIS_ DTS_IN VARIANT Position,
		DTS_IN IDTSTransformation *Object) PURE;
	STDMETHOD(New)(THIS_ DTS_IN BSTR bstrID,
		DTS_RETVAL IDTSTransformation **pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSTransformation
DECLARE_INTERFACE_(IDTSTransformation, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSTransformation)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetTransformServer)(THIS_ DTS_RETVAL IDispatch **pRetVal) PURE;
	STDMETHOD(GetTransformServerProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetTransformServerParameter)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetTransformServerParameter)(THIS_ DTS_IN VARIANT NewValue) PURE;
	STDMETHOD(GetTransformFlags)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetTransformFlags)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetSourceColumns)(THIS_ DTS_RETVAL IDTSColumns **pRetVal) PURE;
	STDMETHOD(GetDestinationColumns)(THIS_ DTS_RETVAL IDTSColumns **pRetVal) PURE;
	STDMETHOD(GetForceSourceBlobsBuffered)(THIS_ DTS_RETVAL DTSForceMode *pRetVal) PURE;
	STDMETHOD(SetForceSourceBlobsBuffered)(THIS_ DTS_IN DTSForceMode NewValue) PURE;
	STDMETHOD(GetForceBlobsInMemory)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetForceBlobsInMemory)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetInMemoryBlobSize)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetInMemoryBlobSize)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetTransformServerID)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSColumns
DECLARE_INTERFACE_(IDTSColumns, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSColumns)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSColumn **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
	STDMETHOD(Add)(THIS_ DTS_IN IDTSColumn *Object) PURE;
	STDMETHOD(Remove)(THIS_ DTS_IN VARIANT Index) PURE;
	STDMETHOD(Insert)(THIS_ DTS_IN VARIANT Position,
		DTS_IN IDTSColumn *Object) PURE;
	STDMETHOD(New)(THIS_ DTS_IN BSTR Name,
		DTS_IN long Ordinal,
		DTS_RETVAL IDTSColumn **pRetVal) PURE;
	STDMETHOD(AddColumn)(THIS_ DTS_IN BSTR Name,
		DTS_IN long Ordinal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSColumn
DECLARE_INTERFACE_(IDTSColumn, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSColumn)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetOrdinal)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetOrdinal)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetFlags)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetFlags)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetSize)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetSize)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetDataType)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetDataType)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetPrecision)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetPrecision)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetNumericScale)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetNumericScale)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetNullable)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetNullable)(THIS_ DTS_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetColumnID)(THIS_ DTS_RETVAL VARIANT *pRetVal) PURE;
	STDMETHOD(SetColumnID)(THIS_ DTS_IN VARIANT NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSLookups
DECLARE_INTERFACE_(IDTSLookups, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSLookups)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSLookup **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
	STDMETHOD(Add)(THIS_ DTS_IN IDTSLookup *Object) PURE;
	STDMETHOD(Remove)(THIS_ DTS_IN VARIANT Index) PURE;
	STDMETHOD(Insert)(THIS_ DTS_IN VARIANT Position,
		DTS_IN IDTSLookup *Object) PURE;
	STDMETHOD(New)(THIS_ DTS_IN BSTR Name,
		DTS_RETVAL IDTSLookup **pRetVal) PURE;
	STDMETHOD(AddLookup)(THIS_ DTS_IN BSTR Name,
		DTS_IN BSTR Query,
		DTS_IN long ConnectionID,
		DTS_IN long MaxCacheRows) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSLookup
DECLARE_INTERFACE_(IDTSLookup, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSLookup)

	STDMETHOD(GetParent)(THIS_ DTS_RETVAL IDTSStdObject **pRetVal) PURE;
	STDMETHOD(GetProperties)(THIS_ DTS_RETVAL IDTSProperties **pRetVal) PURE;
	STDMETHOD(GetName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetName)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetConnectionID)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetConnectionID)(THIS_ DTS_IN LONG NewValue) PURE;
	STDMETHOD(GetQuery)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(SetQuery)(THIS_ DTS_IN BSTR NewValue) PURE;
	STDMETHOD(GetMaxCacheRows)(THIS_ DTS_RETVAL LONG *pRetVal) PURE;
	STDMETHOD(SetMaxCacheRows)(THIS_ DTS_IN LONG NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSSavedPackageInfo
DECLARE_INTERFACE_(IDTSSavedPackageInfo, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSSavedPackageInfo)

	STDMETHOD(GetPackageName)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetDescription)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetPackageID)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetVersionID)(THIS_ DTS_RETVAL BSTR *pRetVal) PURE;
	STDMETHOD(GetPackageCreationDate)(THIS_ DTS_RETVAL DATE *pRetVal) PURE;
	STDMETHOD(GetVersionSaveDate)(THIS_ DTS_RETVAL DATE *pRetVal) PURE;
	STDMETHOD(GetIsVersionEncrypted)(THIS_ DTS_RETVAL VARIANT_BOOL *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSSavedPackageInfos
DECLARE_INTERFACE_(IDTSSavedPackageInfos, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSSavedPackageInfos)

	STDMETHOD(Item)(THIS_ DTS_IN VARIANT Index,
		DTS_RETVAL IDTSSavedPackageInfo **pRetVal) PURE;
	STDMETHOD(Get_NewEnum)(THIS_ DTS_RETVAL IUnknown **ppEnum) PURE;
	STDMETHOD(GetCount)(THIS_ DTS_RETVAL long *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSPropertyBag
DECLARE_INTERFACE_(IDTSPropertyBag, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSPropertyBag)

	STDMETHOD(Read)(THIS_ DTS_IN BSTR bstrPropertyName,
		DTS_RETVAL VARIANT *pValue) PURE;
	STDMETHOD(Write)(THIS_ DTS_IN BSTR bstrPropertyName,
		DTS_IN VARIANT Value) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSPersistPropertyBag
DECLARE_INTERFACE_(IDTSPersistPropertyBag, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSPersistPropertyBag)

	STDMETHOD(Load)(THIS_ DTS_IN IDTSPropertyBag *IDTSPropertyBag) PURE;
	STDMETHOD(Save)(THIS_ DTS_IN IDTSPropertyBag *IDTSPropertyBag) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSPackageEvents
DECLARE_INTERFACE_(IDTSPackageEvents, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSPackageEvents)

	STDMETHOD(OnStart)(THIS_ DTS_IN BSTR EventSource) PURE;
	STDMETHOD(OnFinish)(THIS_ DTS_IN BSTR EventSource) PURE;
	STDMETHOD(OnError)(THIS_ DTS_IN BSTR EventSource,
		DTS_IN long ErrorCode,
		DTS_IN BSTR Source,
		DTS_IN BSTR Description,
		DTS_IN BSTR HelpFile,
		DTS_IN long HelpContext,
		DTS_IN BSTR IDofInterfaceWithError,
		DTS_OUT VARIANT_BOOL *pbCancel) PURE;
	STDMETHOD(OnProgress)(THIS_ DTS_IN BSTR EventSource,
		DTS_IN BSTR ProgressDescription,
		DTS_IN long PercentComplete,
		DTS_IN long ProgressCountLow,
		DTS_IN long ProgressCountHigh) PURE;
	STDMETHOD(OnQueryCancel)(THIS_ DTS_IN BSTR EventSource,
		DTS_OUT VARIANT_BOOL *pbCancel) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSPackageLog
DECLARE_INTERFACE_(IDTSPackageLog, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSPackageLog)

};

#undef INTERFACE
#define INTERFACE IDTSCustomTaskUI
DECLARE_INTERFACE_(IDTSCustomTaskUI, IDTSStdObject)
{
	DTSPackage_DISPATCH_BASE(IDTSCustomTaskUI)

	STDMETHOD(Initialize)(THIS_ DTS_IN IDTSTask *pTask) PURE;
	STDMETHOD(GetUIInfo)(THIS_ DTS_OUT BSTR *pbstrToolTip,
		DTS_OUT BSTR *pbstrDescription,
		DTS_OUT long *plVersion,
		DTS_OUT DTSCustomTaskUIFlags *pFlags) PURE;
	STDMETHOD(New)(THIS_ DTS_IN long hwndParent) PURE;
	STDMETHOD(Edit)(THIS_ DTS_IN long hwndParent) PURE;
	STDMETHOD(Delete)(THIS_ DTS_IN long hwndParent) PURE;
	STDMETHOD(Help)(THIS_ DTS_IN long hwndParent) PURE;
	STDMETHOD(CreateCustomToolTip)(THIS_ DTS_IN long hwndParent,
		DTS_IN long x,
		DTS_IN long y,
		DTS_OUT long *plTipWindow) PURE;
};


#endif // ndef DTSPackage_ODL_

#endif // ndef DTSPackage_VersionOnly

#pragma option pop /*P_O_Pop*/
#endif // def DTSPackage_H_

