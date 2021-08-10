#ifndef SQLNS_DEF_H_
#pragma option push -b -a8 -pc -A- /*P_O_Push*/

#ifdef  DO_SQLNS_ODL_CONSTANTS_
#define DONE_SQLNS_ODL_CONSTANTS_

#ifndef SQLNSVersion_Major
	#define SQLNSVersion_Major 7
	#define SQLNSVersion_Minor 0
#endif // SQLNSVersion_Major

/////////////////////////////////////////////////////////////////////////////////////////
// Constant enumerations.
/////////////////////////////////////////////////////////////////////////////////////////

#define IID_ISQLNamespace 00026f20-EB1C-11cf-AE6E-00AA004A34D5
#define IID_ISQLNamespaceObject 00026f21-EB1C-11cf-AE6E-00AA004A34D5
#define IID_ISQLNamespaceCommand 00026f22-EB1C-11cf-AE6E-00AA004A34D5
#define IID_ISQLNamespaceCommands 00026f23-EB1C-11cf-AE6E-00AA004A34D5
#define IID_IReplicationCustomization 00026f24-EB1C-11cf-AE6E-00AA004A34D5

#define LIBID_SQLNamespace 00026f30-EB1C-11cf-AE6E-00AA004A34D5
#define CLSID_SQLNamespace 00026f00-EB1C-11cf-AE6E-00AA004A34D5
#define CLSID_SQLNamespaceInternal 00026f10-EB1C-11cf-AE6E-00AA004A34D5


#endif //DO_SQLNS_ODL_CONSTANTS_


#ifdef DO_HELP_CONSTANTS_

//interfaces
#define H_NamespaceLibrary		100
#define H_Namespace				200
#define H_NamespaceObject		400
#define H_NamespaceCommand		600
#define H_NamespaceCommands		800

//enums
#define H_SQLNSRootType			2000
#define H_SQLNSObjectType		2200
#define H_SQLNSModality			2400
#define H_SQLNSCommandID		2600
#define H_SQLNSErrors			2800

#endif //DO_HELP_CONSTANTS_



#ifdef DO_ODL_TYPDEFS_


// To avoid the need to cast on bitwise operations (which defeats typesafety anyway),
// define the datatype as DWORD for C/CPP.  OleAut languages don't do typechecking
// and organize by the enum name.
#ifdef SQLNS_ODL_
	#define SQLNS_ENUM_BEGIN(tdef, hstring)	[helpcontext(H_##tdef), helpstring(hstring)] enum
		// item = value, ...
	#define SQLNS_ENUM_END(tdef)				tdef, *LP##tdef
#else
	#define SQLNS_ENUM_BEGIN(tdef, hstring)	DWORD tdef, *LP##tdef; enum tag##tdef
		// item = value, ...
	#define SQLNS_ENUM_END(tdef)				
#endif


typedef SQLNS_ENUM_BEGIN(SQLNSRootType, "The type of object to set as root")
{
	SQLNSRootType_DefaultRoot		= 0x0000,
	SQLNSRootType_ServerGroup		= 0x0001,
	SQLNSRootType_Server			= 0x0002,
	SQLNSRootType_Database			= 0x0003
} SQLNS_ENUM_END(SQLNSRootType);

typedef SQLNS_ENUM_BEGIN(SQLNSObjectType, "The type of object")
{
	SQLNSOBJECTTYPE_ROOT				= 0x0000,
	SQLNSOBJECTTYPE_EMPTY,
	SQLNSOBJECTTYPE_SERVER_GROUP,
	SQLNSOBJECTTYPE_SERVER,
	SQLNSOBJECTTYPE_DATABASES,
	SQLNSOBJECTTYPE_DATABASE,
    SQLNSOBJECTTYPE_MANAGEMENT,
    SQLNSOBJECTTYPE_SECURITY,
    SQLNSOBJECTTYPE_SERVICES,
	SQLNSOBJECTTYPE_LOGINS,
	SQLNSOBJECTTYPE_LOGIN,
	SQLNSOBJECTTYPE_BACKUPDEVICES,
	SQLNSOBJECTTYPE_BACKUPDEVICE,
	SQLNSOBJECTTYPE_DATABASE_PUBLICATIONS,
	SQLNSOBJECTTYPE_DATABASE_PUBLICATION,
	SQLNSOBJECTTYPE_DATABASE_PUB_SUBSCRIPTION,
	SQLNSOBJECTTYPE_DATABASE_PULL_SUBSCRIPTIONS,
	SQLNSOBJECTTYPE_DATABASE_PULL_SUBSCRIPTION,
	SQLNSOBJECTTYPE_DATABASE_USERS,
	SQLNSOBJECTTYPE_DATABASE_USER,
	SQLNSOBJECTTYPE_DATABASE_ROLES,
	SQLNSOBJECTTYPE_DATABASE_ROLE,
	SQLNSOBJECTTYPE_DATABASE_DIAGRAMS,
	SQLNSOBJECTTYPE_DATABASE_DIAGRAM,
	SQLNSOBJECTTYPE_DATABASE_TABLES,
	SQLNSOBJECTTYPE_DATABASE_TABLE,
	SQLNSOBJECTTYPE_DATABASE_VIEWS,
	SQLNSOBJECTTYPE_DATABASE_VIEW,
	SQLNSOBJECTTYPE_DATABASE_SPS,
	SQLNSOBJECTTYPE_DATABASE_SP,
	SQLNSOBJECTTYPE_DATABASE_EXTENDED_SPS,
	SQLNSOBJECTTYPE_DATABASE_EXTENDED_SP,
	SQLNSOBJECTTYPE_DATABASE_RULES,
	SQLNSOBJECTTYPE_DATABASE_RULE,
	SQLNSOBJECTTYPE_DATABASE_DEFAULTS,
	SQLNSOBJECTTYPE_DATABASE_DEFAULT,
	SQLNSOBJECTTYPE_DATABASE_UDDTS,								
	SQLNSOBJECTTYPE_DATABASE_UDDT,
	SQLNSOBJECTTYPE_JOBSERVER,
	SQLNSOBJECTTYPE_SQLMAIL,
	SQLNSOBJECTTYPE_DTC,
    SQLNSOBJECTTYPE_INDEXSERVER,
    SQLNSOBJECTTYPE_INDEXSERVER_CATALOGS,
    SQLNSOBJECTTYPE_INDEXSERVER_CATALOG,
	SQLNSOBJECTTYPE_ERRORLOGS,
	SQLNSOBJECTTYPE_ERRORLOG,
	SQLNSOBJECTTYPE_ERRORLOGENTRY,
	SQLNSOBJECTTYPE_ALERTS,
	SQLNSOBJECTTYPE_OPERATORS,
	SQLNSOBJECTTYPE_MSX_JOBS,
	SQLNSOBJECTTYPE_LOCAL_JOBS,
	SQLNSOBJECTTYPE_MULTI_JOBS,
	SQLNSOBJECTTYPE_LOCAL_JOB,
	SQLNSOBJECTTYPE_MULTI_JOB,
	SQLNSOBJECTTYPE_REMOTESERVERS,
	SQLNSOBJECTTYPE_LINKEDSERVERS,
	SQLNSOBJECTTYPE_SERVERROLES,
	SQLNSOBJECTTYPE_SERVERROLE,
	SQLNSOBJECTTYPE_ALERT,
	SQLNSOBJECTTYPE_OPERATOR,
	SQLNSOBJECTTYPE_REMOTESERVER,
	SQLNSOBJECTTYPE_LINKEDSERVER,
	SQLNSOBJECTTYPE_LINKEDSERVER_TABLES,
	SQLNSOBJECTTYPE_LINKEDSERVER_TABLE,
	SQLNSOBJECTTYPE_REPLICATION,
	SQLNSOBJECTTYPE_REPLICATION_PUBLISHERS,
	SQLNSOBJECTTYPE_REPLICATION_PUBLISHER,
	SQLNSOBJECTTYPE_REPLICATION_AGENTS,
	SQLNSOBJECTTYPE_REPLICATION_REPORTS,
	SQLNSOBJECTTYPE_REPLICATION_ALERTS,
	SQLNSOBJECTTYPE_REPLICATION_SUBSCRIPTION,
	// do not add between here and SQLNSOBJECTTYPE_REPLICATION_MERGE_AGENTS
	SQLNSOBJECTTYPE_REPLICATION_PUBLICATION,
	SQLNSOBJECTTYPE_REPLICATION_SNAPSHOT_AGENTS,
	SQLNSOBJECTTYPE_REPLICATION_LOGREADER_AGENTS,
	SQLNSOBJECTTYPE_REPLICATION_DISTRIBUTION_AGENTS,
	SQLNSOBJECTTYPE_REPLICATION_MERGE_AGENTS,
	SQLNSOBJECTTYPE_REPLICATION_MISC_AGENTS,
	//
	SQLNSOBJECTTYPE_REPLICATION_SNAPSHOT_AGENT,
	SQLNSOBJECTTYPE_REPLICATION_LOGREADER_AGENT,
	SQLNSOBJECTTYPE_REPLICATION_DISTRIBUTION_AGENT,
	SQLNSOBJECTTYPE_REPLICATION_MERGE_AGENT,
	SQLNSOBJECTTYPE_REPLICATION_MISC_AGENT,
	SQLNSOBJECTTYPE_REPLICATION_REPORT,
	SQLNSOBJECTTYPE_DTSPKGS,
	SQLNSOBJECTTYPE_DTS_LOCALPKGS,
	SQLNSOBJECTTYPE_DTS_REPOSPKGS,
	SQLNSOBJECTTYPE_DTS_METADATA,
	SQLNSOBJECTTYPE_DTSPKG,
	SQLNSOBJECTTYPE_DB_MAINT_PLANS,
	SQLNSOBJECTTYPE_DB_MAINT_PLAN,
	SQLNSOBJECTTYPE_WEBASSISTANTJOBS,
	SQLNSOBJECTTYPE_WEBASSISTANTJOB,
    SQLNSOBJECTTYPE_CURRENTACTIVITY,
    SQLNSOBJECTTYPE_CURRENTACTIVITY_PROCESSINFO,
    SQLNSOBJECTTYPE_CURRENTACTIVITY_PROCESSINFO_INFO,
    SQLNSOBJECTTYPE_CURRENTACTIVITY_LOCKEDPROCESSES,
    SQLNSOBJECTTYPE_CURRENTACTIVITY_SPID,
    SQLNSOBJECTTYPE_CURRENTACTIVITY_SPID_INFO,
    SQLNSOBJECTTYPE_CURRENTACTIVITY_LOCKEDOBJECTS,
    SQLNSOBJECTTYPE_CURRENTACTIVITY_LOCKEDOBJECT,
    SQLNSOBJECTTYPE_CURRENTACTIVITY_LOCKEDOBJECT_INFO

	//update SQLNSOBJECTTYPE_LAST is you add items at end

} SQLNS_ENUM_END(SQLNSObjectType);

#define SQLNSOBJECTTYPE_LAST SQLNSOBJECTTYPE_CURRENTACTIVITY_LOCKEDOBJECT_INFO

typedef SQLNS_ENUM_BEGIN(SQLNSModality, "Suggests the modality of the UI displayed")
{
	SQLNamespace_DontCare   = 0x0000,
	SQLNamespace_PreferModal	= 0x0001,
	SQLNamespace_PreferModeless	= 0x0002
} SQLNS_ENUM_END(SQLNSModality);







typedef SQLNS_ENUM_BEGIN(SQLNSCommandID, "Command IDs available in the SQLNamespace")
{
	SQLNS_CmdID_WIZARD_CREATEDB             =		1,
	SQLNS_CmdID_WIZARD_CREATEINDEX          ,
	SQLNS_CmdID_WIZARD_DTSIMPORT            ,
	SQLNS_CmdID_WIZARD_DTSEXPORT            ,
	SQLNS_CmdID_WIZARD_CREATEJOB            ,
	SQLNS_CmdID_WIZARD_SECURITY             ,
	SQLNS_CmdID_WIZARD_SP                   ,
	SQLNS_CmdID_WIZARD_VIEW                 ,
	SQLNS_CmdID_WIZARD_INDEXTUNING          ,
	SQLNS_CmdID_WIZARD_ALERT                ,
	SQLNS_CmdID_WIZARD_MAINTPLAN            ,
	SQLNS_CmdID_WIZARD_WEBASST              ,
	SQLNS_CmdID_WIZARD_BACKUP				,
	SQLNS_CmdID_WIZARD_CREATETRACE          ,
	SQLNS_CmdID_WIZARDS                     ,
	SQLNS_CmdID_PROPERTIES                  ,
	SQLNS_CmdID_DELETE                      ,
	SQLNS_CmdID_NEW_SERVER                  ,
	SQLNS_CmdID_NEW_JOB                     ,
	SQLNS_CmdID_NEW_ALERT                   ,
	SQLNS_CmdID_NEW_OPERATOR                ,
	SQLNS_CmdID_NEW_REMOTE_SERVER           ,
	SQLNS_CmdID_NEW_DATABASE                ,
	SQLNS_CmdID_NEW_TABLE                   ,
	SQLNS_CmdID_NEW_VIEW                    ,
	SQLNS_CmdID_NEW_STORED_PROCEDURE        ,
	SQLNS_CmdID_NEW_EXTENDED_STORED_PROCEDURE,
	SQLNS_CmdID_NEW_RULE                    ,
	SQLNS_CmdID_NEW_DEFAULT                 ,
	SQLNS_CmdID_NEW_UDDT                    ,
	SQLNS_CmdID_NEW_SERVER_GROUP            ,
	SQLNS_CmdID_NEW_DIAGRAM					,
	SQLNS_CmdID_NEW_DATABASE_ROLE			,
	SQLNS_CmdID_NEW_LOGIN                   ,
	SQLNS_CmdID_NEW_DBUSER                  ,
	SQLNS_CmdID_NEW_BACKUPDEVICE            ,
	SQLNS_CmdID_OPEN                        ,
	SQLNS_CmdID_JOBSERVER_ERRORLOG			,
	SQLNS_CmdID_JOB_START					,
	SQLNS_CmdID_JOB_HISTORY					,
	SQLNS_CmdID_JOB_STOP					,
	SQLNS_CmdID_JOBSERVER_TARGET_SERVERS    ,
	SQLNS_CmdID_EDIT_SERVER                 ,
	SQLNS_CmdID_OBJECT_PERMISSIONS          ,
	SQLNS_CmdID_OBJECT_DEPENDENCIES         ,
	SQLNS_CmdID_TABLE_INDEXES               ,
	SQLNS_CmdID_TABLE_TRIGGERS              ,
	//SQLNS_CmdID_JOB_STEPS					,
	SQLNS_CmdID_SVC_STOP					=		49,
	SQLNS_CmdID_SVC_PAUSE                   ,
	SQLNS_CmdID_SVC_START                   ,
	SQLNS_CmdID_SERVER_SECURITY             ,
	//SQLNS_CmdID_CONNECT					,
	//SQLNS_CmdID_SERVER_CONFIGURATION		,
	SQLNS_CmdID_ENLIST                      =		55,
	SQLNS_CmdID_DEFECT                      ,
	SQLNS_CmdID_EXPORT_JOB                  ,
	//SQLNS_CmdID_MULTI_SERVER_JOB_STATUS   ,
	SQLNS_CmdID_DTS_IMPORT					=		59,
	SQLNS_CmdID_DTS_EXPORT					,
	SQLNS_CmdID_DTS_RUN						,
	SQLNS_CmdID_ENLIST_REG_SERVERS          ,
	SQLNS_CmdID_TOOLS_MAINT_PLAN            ,
	SQLNS_CmdID_REPLICATION_PUBLISH         ,
	SQLNS_CmdID_REPLICATION_CONFIGURE       ,
	SQLNS_CmdID_REPLICATION_SUBSCRIBE       ,
	SQLNS_CmdID_REPLICATION_SCRIPT          ,
	SQLNS_CmdID_REPLICATION_UNINSTALL       ,
	SQLNS_CmdID_NEW_PUBLICATION             ,
	SQLNS_CmdID_PUSH_NEW_SUBSCRIPTION       ,
	SQLNS_CmdID_REPLICATION_RESOLVE_CONFLICTS,
	SQLNS_CmdID_NEW_SUBSCRIPTION            ,
	SQLNS_CmdID_REINIT_SUBSCRIPTION			,
	SQLNS_CmdID_SYNCHRONIZE_NOW			    ,
	SQLNS_CmdID_STOP_SYNCHRONIZING          ,
	SQLNS_CmdID_AGENT_ERROR_DETAILS			,
	SQLNS_CmdID_AGENT_HISTORY				,
	SQLNS_CmdID_SECURITY_LIST				,
	SQLNS_CmdID_GENERATE_SCRIPTS			,
	SQLNS_CmdID_DATABASE_BACKUP				,
	SQLNS_CmdID_DATABASE_RESTORE			,
	SQLNS_CmdID_DATABASE_SHRINKDB			,
	SQLNS_CmdID_PUBLISHING_PROPERTIES		,
	SQLNS_CmdID_NEW_LINKED_SERVER			,
	//more to come
} SQLNS_ENUM_END(SQLNSCommandID);

typedef SQLNS_ENUM_BEGIN(SQLNSErrors, "Error ranges available in the SQLNamespace")
{
	SQLNS_E_NotImplemented						= 1001,
	SQLNS_E_OrdOutOfRange						= 1002,
	SQLNS_E_NameNotFound						= 1003,
	SQLNS_E_NameDup								= 1004,
	SQLNS_E_Already_Initialized					= 1005,
	SQLNS_E_InvalidRootType						= 1006,
	SQLNS_E_RequireAppName						= 1007,
	SQLNS_E_InvalidObjectHandle					= 1008,
	SQLNS_E_NoDMOObject							= 1009,
	SQLNS_E_InvalidCommandName					= 1010,
	SQLNS_E_InvalidCommandID					= 1011,
	SQLNS_E_InvalidRootInfo						= 1012,
	SQLNS_E_InvalidServerName					= 1013,
	SQLNS_E_InvalidLoginInfo					= 1014,
	SQLNS_E_InvalidDBName						= 1015,
	SQLNS_E_InvalidConnectString				= 1016,
	SQLNS_E_SrvGrpNotFound						= 1017,
	SQLNS_E_ServerNotFound						= 1018,
	SQLNS_E_DatabaseNotFound					= 1019,
	SQLNS_E_InvalidServerVersion				= 1020,
	SQLNS_E_ExternalError						= 1100			//General, external error..we don't have a description for this error
	//more to come
} SQLNS_ENUM_END(SQLNSErrors);

#ifndef SQLNS_ODL_

#define SIZE_SQLOBJ_NAMELEN 128
typedef struct
  {
  DWORD						dwStructSize; // in Bytes
  DWORD						dwCreatePubAllowTypes;
  DWORD						dwPubPropPages;
  DWORD						dwConfigurePropPages;
  TCHAR						szDatabaseName[SIZE_SQLOBJ_NAMELEN + 2]; // database name should not be more than 128 TCHARs.
  } REPLICATION_CUSTOMIZE_INFO, *PREPLICATION_CUSTOMIZE_INFO;

#endif

// These flag groups are used to control the Create Publication wizard, 
// the publication property sheet, and Configure Publishing and 
// Distribution property sheet
//
// the caller may not want to allow all types of publications to be created
const long fAllowSnapshotPubs				= 0x01;
const long fAllowTransPubs					= 0x02;
const long fAllowMergePubs					= 0x04;
const long grfAllowAllPubTypes				= 0x07;

// You can select which property pages to display in the publication property
// sheet.  Note that some pages are dependent on the General page being displayed. 
// General page is always displayed.
const long fPubPropArticles					= 0x02;
const long fPubPropFilters					= 0x04;	// controls both Columns & Rows
const long fPubPropSubs						= 0x08;
const long fPubPropSubOptions				= 0x10;
const long fPubPropStatus					= 0x20;
const long fPubPropScript					= 0x40;
const long fPubPropACL						= 0x80;
const long grfPubPropAllPages				= 0xFF;
	
// You can select which property pages to display in the Configure Publishing
// and Distribution property sheet.
const long fConfigurePropDist				= 0x01;
const long fConfigurePropDBs				= 0x02;
const long fConfigurePropSubscribers		= 0x04;
const long fConfigurePropPublishers			= 0x08;
const long fConfigurePropAccessList			= 0x10;		// UNDONE: This page has been removed
const long grfConfigurePropAllPages			= 0x1F;

#ifdef SQLNS_ODL_
typedef long HSQLNSITEM, *PHSQLNSITEM;	//handle to a namespace item
#else
typedef DWORD HSQLNSITEM, *PHSQLNSITEM;	//handle to a namespace item
#endif





#endif //DO_ODL_TYPDEFS_

#define SQLNS_DEF_H_
#pragma option pop /*P_O_Pop*/
#endif //SQLNS_DEF_H_
