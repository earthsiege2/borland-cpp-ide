
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       Win32 service API interface unit                }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Inprise Corporation                 }
{                                                       }
{*******************************************************}

unit WinSvc;

{$ALIGN ON}
{$MINENUMSIZE 4}
{$WEAKPACKAGEUNIT}

interface

uses Windows;

//
// Constants
//

const

//
// Service database names
//
  {$EXTERNALSYM SERVICES_ACTIVE_DATABASEA}
  SERVICES_ACTIVE_DATABASEA     = 'ServicesActive';
  {$EXTERNALSYM SERVICES_ACTIVE_DATABASEW}
  SERVICES_ACTIVE_DATABASEW     = 'ServicesActive';
  {$EXTERNALSYM SERVICES_ACTIVE_DATABASE}
  SERVICES_ACTIVE_DATABASE = SERVICES_ACTIVE_DATABASEA;
  {$EXTERNALSYM SERVICES_FAILED_DATABASEA}
  SERVICES_FAILED_DATABASEA     = 'ServicesFailed';
  {$EXTERNALSYM SERVICES_FAILED_DATABASEW}
  SERVICES_FAILED_DATABASEW     = 'ServicesFailed';
  {$EXTERNALSYM SERVICES_FAILED_DATABASE}
  SERVICES_FAILED_DATABASE = SERVICES_FAILED_DATABASEA;

//
// Character to designate that a name is a group
//
  {$EXTERNALSYM SC_GROUP_IDENTIFIERA}
  SC_GROUP_IDENTIFIERA          = '+';
  {$EXTERNALSYM SC_GROUP_IDENTIFIERW}
  SC_GROUP_IDENTIFIERW          = '+';
  {$EXTERNALSYM SC_GROUP_IDENTIFIER}
  SC_GROUP_IDENTIFIER = SC_GROUP_IDENTIFIERA;

//
// Value to indicate no change to an optional parameter
//
  {$EXTERNALSYM SERVICE_NO_CHANGE}
  SERVICE_NO_CHANGE              = $FFFFFFFF;

//
// Service State -- for Enum Requests (Bit Mask)
//
  {$EXTERNALSYM SERVICE_ACTIVE}
  SERVICE_ACTIVE                 = $00000001;
  {$EXTERNALSYM SERVICE_INACTIVE}
  SERVICE_INACTIVE               = $00000002;
  {$EXTERNALSYM SERVICE_STATE_ALL}
  SERVICE_STATE_ALL              = (SERVICE_ACTIVE   or
                                    SERVICE_INACTIVE);

//
// Controls
//
  {$EXTERNALSYM SERVICE_CONTROL_STOP}
  SERVICE_CONTROL_STOP           = $00000001;
  {$EXTERNALSYM SERVICE_CONTROL_PAUSE}
  SERVICE_CONTROL_PAUSE          = $00000002;
  {$EXTERNALSYM SERVICE_CONTROL_CONTINUE}
  SERVICE_CONTROL_CONTINUE       = $00000003;
  {$EXTERNALSYM SERVICE_CONTROL_INTERROGATE}
  SERVICE_CONTROL_INTERROGATE    = $00000004;
  {$EXTERNALSYM SERVICE_CONTROL_SHUTDOWN}
  SERVICE_CONTROL_SHUTDOWN       = $00000005;

//
// Service State -- for CurrentState
//
  {$EXTERNALSYM SERVICE_STOPPED}
  SERVICE_STOPPED                = $00000001;
  {$EXTERNALSYM SERVICE_START_PENDING}
  SERVICE_START_PENDING          = $00000002;
  {$EXTERNALSYM SERVICE_STOP_PENDING}
  SERVICE_STOP_PENDING           = $00000003;
  {$EXTERNALSYM SERVICE_RUNNING}
  SERVICE_RUNNING                = $00000004;
  {$EXTERNALSYM SERVICE_CONTINUE_PENDING}
  SERVICE_CONTINUE_PENDING       = $00000005;
  {$EXTERNALSYM SERVICE_PAUSE_PENDING}
  SERVICE_PAUSE_PENDING          = $00000006;
  {$EXTERNALSYM SERVICE_PAUSED}
  SERVICE_PAUSED                 = $00000007;

//
// Controls Accepted  (Bit Mask)
//
  {$EXTERNALSYM SERVICE_ACCEPT_STOP}
  SERVICE_ACCEPT_STOP            = $00000001;
  {$EXTERNALSYM SERVICE_ACCEPT_PAUSE_CONTINUE}
  SERVICE_ACCEPT_PAUSE_CONTINUE  = $00000002;
  {$EXTERNALSYM SERVICE_ACCEPT_SHUTDOWN}
  SERVICE_ACCEPT_SHUTDOWN        = $00000004;

//
// Service Control Manager object specific access types
//
  {$EXTERNALSYM SC_MANAGER_CONNECT}
  SC_MANAGER_CONNECT             = $0001;
  {$EXTERNALSYM SC_MANAGER_CREATE_SERVICE}
  SC_MANAGER_CREATE_SERVICE      = $0002;
  {$EXTERNALSYM SC_MANAGER_ENUMERATE_SERVICE}
  SC_MANAGER_ENUMERATE_SERVICE   = $0004;
  {$EXTERNALSYM SC_MANAGER_LOCK}
  SC_MANAGER_LOCK                = $0008;
  {$EXTERNALSYM SC_MANAGER_QUERY_LOCK_STATUS}
  SC_MANAGER_QUERY_LOCK_STATUS   = $0010;
  {$EXTERNALSYM SC_MANAGER_MODIFY_BOOT_CONFIG}
  SC_MANAGER_MODIFY_BOOT_CONFIG  = $0020;

  {$EXTERNALSYM SC_MANAGER_ALL_ACCESS}
  SC_MANAGER_ALL_ACCESS          = (STANDARD_RIGHTS_REQUIRED or
                                    SC_MANAGER_CONNECT or
                                    SC_MANAGER_CREATE_SERVICE or
                                    SC_MANAGER_ENUMERATE_SERVICE or
                                    SC_MANAGER_LOCK or
                                    SC_MANAGER_QUERY_LOCK_STATUS or
                                    SC_MANAGER_MODIFY_BOOT_CONFIG);

//
// Service object specific access type
//
  {$EXTERNALSYM SERVICE_QUERY_CONFIG}
  SERVICE_QUERY_CONFIG           = $0001;
  {$EXTERNALSYM SERVICE_CHANGE_CONFIG}
  SERVICE_CHANGE_CONFIG          = $0002;
  {$EXTERNALSYM SERVICE_QUERY_STATUS}
  SERVICE_QUERY_STATUS           = $0004;
  {$EXTERNALSYM SERVICE_ENUMERATE_DEPENDENTS}
  SERVICE_ENUMERATE_DEPENDENTS   = $0008;
  {$EXTERNALSYM SERVICE_START}
  SERVICE_START                  = $0010;
  {$EXTERNALSYM SERVICE_STOP}
  SERVICE_STOP                   = $0020;
  {$EXTERNALSYM SERVICE_PAUSE_CONTINUE}
  SERVICE_PAUSE_CONTINUE         = $0040;
  {$EXTERNALSYM SERVICE_INTERROGATE}
  SERVICE_INTERROGATE            = $0080;
  {$EXTERNALSYM SERVICE_USER_DEFINED_CONTROL}
  SERVICE_USER_DEFINED_CONTROL   = $0100;

  {$EXTERNALSYM SERVICE_ALL_ACCESS}
  SERVICE_ALL_ACCESS             = (STANDARD_RIGHTS_REQUIRED or
                                    SERVICE_QUERY_CONFIG or
                                    SERVICE_CHANGE_CONFIG or
                                    SERVICE_QUERY_STATUS or
                                    SERVICE_ENUMERATE_DEPENDENTS or
                                    SERVICE_START or
                                    SERVICE_STOP or
                                    SERVICE_PAUSE_CONTINUE or
                                    SERVICE_INTERROGATE or
                                    SERVICE_USER_DEFINED_CONTROL);


//
// Service Types (Bit Mask)
//
  {$EXTERNALSYM SERVICE_KERNEL_DRIVER}
  SERVICE_KERNEL_DRIVER         = $00000001;
  {$EXTERNALSYM SERVICE_FILE_SYSTEM_DRIVER}
  SERVICE_FILE_SYSTEM_DRIVER    = $00000002;
  {$EXTERNALSYM SERVICE_ADAPTER}
  SERVICE_ADAPTER               = $00000004;
  {$EXTERNALSYM SERVICE_RECOGNIZER_DRIVER}
  SERVICE_RECOGNIZER_DRIVER     = $00000008;

  {$EXTERNALSYM SERVICE_DRIVER}
  SERVICE_DRIVER                = (SERVICE_KERNEL_DRIVER or
                                   SERVICE_FILE_SYSTEM_DRIVER or
                                   SERVICE_RECOGNIZER_DRIVER);

  {$EXTERNALSYM SERVICE_WIN32_OWN_PROCESS}
  SERVICE_WIN32_OWN_PROCESS     = $00000010;
  {$EXTERNALSYM SERVICE_WIN32_SHARE_PROCESS}
  SERVICE_WIN32_SHARE_PROCESS   = $00000020;
  {$EXTERNALSYM SERVICE_WIN32}
  SERVICE_WIN32                 = (SERVICE_WIN32_OWN_PROCESS or
                                   SERVICE_WIN32_SHARE_PROCESS);

  {$EXTERNALSYM SERVICE_INTERACTIVE_PROCESS}
  SERVICE_INTERACTIVE_PROCESS   = $00000100;

  {$EXTERNALSYM SERVICE_TYPE_ALL}
  SERVICE_TYPE_ALL              = (SERVICE_WIN32 or
                                  SERVICE_ADAPTER or
                                  SERVICE_DRIVER or
                                  SERVICE_INTERACTIVE_PROCESS);

//
// Start Type
//
  {$EXTERNALSYM SERVICE_BOOT_START}
  SERVICE_BOOT_START            = $00000000;
  {$EXTERNALSYM SERVICE_SYSTEM_START}
  SERVICE_SYSTEM_START          = $00000001;
  {$EXTERNALSYM SERVICE_AUTO_START}
  SERVICE_AUTO_START            = $00000002;
  {$EXTERNALSYM SERVICE_DEMAND_START}
  SERVICE_DEMAND_START          = $00000003;
  {$EXTERNALSYM SERVICE_DISABLED}
  SERVICE_DISABLED              = $00000004;

//
// Error control type
//
  {$EXTERNALSYM SERVICE_ERROR_IGNORE}
  SERVICE_ERROR_IGNORE          = $00000000;
  {$EXTERNALSYM SERVICE_ERROR_NORMAL}
  SERVICE_ERROR_NORMAL          = $00000001;
  {$EXTERNALSYM SERVICE_ERROR_SEVERE}
  SERVICE_ERROR_SEVERE          = $00000002;
  {$EXTERNALSYM SERVICE_ERROR_CRITICAL}
  SERVICE_ERROR_CRITICAL        = $00000003;

type

//
// Handle Types
//

  {$EXTERNALSYM SC_HANDLE}
  SC_HANDLE = THandle;
  {$EXTERNALSYM LPSC_HANDLE}
  LPSC_HANDLE = ^SC_HANDLE;

  {$EXTERNALSYM SERVICE_STATUS_HANDLE}
  SERVICE_STATUS_HANDLE = DWORD;

//
// pointer to string pointer
//

  PLPSTRA = ^PAnsiChar;
  PLPWSTRW = ^PWideChar;
  PLPSTR = PLPSTRA;

//
// Service Status Structure
//

  PServiceStatus = ^TServiceStatus;
  {$EXTERNALSYM _SERVICE_STATUS}
  _SERVICE_STATUS = record
    dwServiceType: DWORD;
    dwCurrentState: DWORD;
    dwControlsAccepted: DWORD;
    dwWin32ExitCode: DWORD;
    dwServiceSpecificExitCode: DWORD;
    dwCheckPoint: DWORD;
    dwWaitHint: DWORD;
  end;
  {$EXTERNALSYM SERVICE_STATUS}
  SERVICE_STATUS = _SERVICE_STATUS;
  TServiceStatus = _SERVICE_STATUS;

//
// Service Status Enumeration Structure
//
  PEnumServiceStatusA = ^TEnumServiceStatusA;
  PEnumServiceStatusW = ^TEnumServiceStatusW;
  PEnumServiceStatus = PEnumServiceStatusA;
  {$EXTERNALSYM _ENUM_SERVICE_STATUSA}
  _ENUM_SERVICE_STATUSA = record
    lpServiceName: PAnsiChar;
    lpDisplayName: PAnsiChar;
    ServiceStatus: TServiceStatus;
  end;
{#BEGIN}
  {$EXTERNALSYM ENUM_SERVICE_STATUSA}
  ENUM_SERVICE_STATUSA = _ENUM_SERVICE_STATUSA;
  {$EXTERNALSYM _ENUM_SERVICE_STATUSW}
  _ENUM_SERVICE_STATUSW = record
    lpServiceName: PWideChar;
    lpDisplayName: PWideChar;
    ServiceStatus: TServiceStatus;
  end;
{#BEGIN}
  {$EXTERNALSYM ENUM_SERVICE_STATUSW}
  ENUM_SERVICE_STATUSW = _ENUM_SERVICE_STATUSW;
  {$EXTERNALSYM _ENUM_SERVICE_STATUS}
  _ENUM_SERVICE_STATUS = _ENUM_SERVICE_STATUSA;
  TEnumServiceStatusA = _ENUM_SERVICE_STATUSA;
  TEnumServiceStatusW = _ENUM_SERVICE_STATUSW;
  TEnumServiceStatus = TEnumServiceStatusA;

//
// Structures for the Lock API functions
//
  SC_LOCK = Pointer;
  {$EXTERNALSYM SC_LOCK}
  
  PQueryServiceLockStatusA = ^TQueryServiceLockStatusA;
  PQueryServiceLockStatusW = ^TQueryServiceLockStatusW;
  PQueryServiceLockStatus = PQueryServiceLockStatusA;
  {$EXTERNALSYM _QUERY_SERVICE_LOCK_STATUSA}
  _QUERY_SERVICE_LOCK_STATUSA = record
    fIsLocked: DWORD;
    lpLockOwner: PAnsiChar;
    dwLockDuration: DWORD;
  end;
  {$EXTERNALSYM _QUERY_SERVICE_LOCK_STATUSW}
  _QUERY_SERVICE_LOCK_STATUSW = record
    fIsLocked: DWORD;
    lpLockOwner: PWideChar;
    dwLockDuration: DWORD;
  end;
  {$EXTERNALSYM _QUERY_SERVICE_LOCK_STATUS}
  _QUERY_SERVICE_LOCK_STATUS = _QUERY_SERVICE_LOCK_STATUSA;
  {$EXTERNALSYM QUERY_SERVICE_LOCK_STATUSA}
  QUERY_SERVICE_LOCK_STATUSA = _QUERY_SERVICE_LOCK_STATUSA;
  {$EXTERNALSYM QUERY_SERVICE_LOCK_STATUSW}
  QUERY_SERVICE_LOCK_STATUSW = _QUERY_SERVICE_LOCK_STATUSW;
  {$EXTERNALSYM QUERY_SERVICE_LOCK_STATUS}
  QUERY_SERVICE_LOCK_STATUS = QUERY_SERVICE_LOCK_STATUSA;
  TQueryServiceLockStatusA = _QUERY_SERVICE_LOCK_STATUSA;
  TQueryServiceLockStatusW = _QUERY_SERVICE_LOCK_STATUSW;
  TQueryServiceLockStatus = TQueryServiceLockStatusA;

//
// Query Service Configuration Structure
//
  PQueryServiceConfigA = ^TQueryServiceConfigA;
  PQueryServiceConfigW = ^TQueryServiceConfigW;
  PQueryServiceConfig = PQueryServiceConfigA;
  {$EXTERNALSYM _QUERY_SERVICE_CONFIGA}
   _QUERY_SERVICE_CONFIGA = record
    dwServiceType: DWORD;
    dwStartType: DWORD;
    dwErrorControl: DWORD;
    lpBinaryPathName: PAnsiChar;
    lpLoadOrderGroup: PAnsiChar;
    dwTagId: DWORD;
    lpDependencies: PAnsiChar;
    lpServiceStartName: PAnsiChar;
    lpDisplayName: PAnsiChar;
  end;
  {$EXTERNALSYM _QUERY_SERVICE_CONFIGW}
   _QUERY_SERVICE_CONFIGW = record
    dwServiceType: DWORD;
    dwStartType: DWORD;
    dwErrorControl: DWORD;
    lpBinaryPathName: PWideChar;
    lpLoadOrderGroup: PWideChar;
    dwTagId: DWORD;
    lpDependencies: PWideChar;
    lpServiceStartName: PWideChar;
    lpDisplayName: PWideChar;
  end;
  {$EXTERNALSYM _QUERY_SERVICE_CONFIG}
  _QUERY_SERVICE_CONFIG = _QUERY_SERVICE_CONFIGA;
  {$EXTERNALSYM QUERY_SERVICE_CONFIGA}
  QUERY_SERVICE_CONFIGA = _QUERY_SERVICE_CONFIGA;
  {$EXTERNALSYM QUERY_SERVICE_CONFIGW}
  QUERY_SERVICE_CONFIGW = _QUERY_SERVICE_CONFIGW;
  {$EXTERNALSYM QUERY_SERVICE_CONFIG}
  QUERY_SERVICE_CONFIG = QUERY_SERVICE_CONFIGA;
  TQueryServiceConfigA = _QUERY_SERVICE_CONFIGA;
  TQueryServiceConfigW = _QUERY_SERVICE_CONFIGW;
  TQueryServiceConfig = TQueryServiceConfigA;

//
// Function Prototype for the Service Main Function
//










  {$EXTERNALSYM LPSERVICE_MAIN_FUNCTIONA}
  LPSERVICE_MAIN_FUNCTIONA = TFarProc;
  {$EXTERNALSYM LPSERVICE_MAIN_FUNCTIONW}
  LPSERVICE_MAIN_FUNCTIONW = TFarProc;
  {$EXTERNALSYM LPSERVICE_MAIN_FUNCTION}
  LPSERVICE_MAIN_FUNCTION = LPSERVICE_MAIN_FUNCTIONA;
  TServiceMainFunctionA = LPSERVICE_MAIN_FUNCTIONA;
  TServiceMainFunctionW = LPSERVICE_MAIN_FUNCTIONW;
  TServiceMainFunction = TServiceMainFunctionA;

//
// Service Start Table
//
  PServiceTableEntryA = ^TServiceTableEntryA;
  PServiceTableEntryW = ^TServiceTableEntryW;
  PServiceTableEntry = PServiceTableEntryA;
  {$EXTERNALSYM _SERVICE_TABLE_ENTRYA}
  _SERVICE_TABLE_ENTRYA = record
    lpServiceName: PAnsiChar;
    lpServiceProc: TServiceMainFunctionA;
  end;
  {$EXTERNALSYM _SERVICE_TABLE_ENTRYW}
  _SERVICE_TABLE_ENTRYW = record
    lpServiceName: PWideChar;
    lpServiceProc: TServiceMainFunctionW;
  end;
  {$EXTERNALSYM _SERVICE_TABLE_ENTRY}
  _SERVICE_TABLE_ENTRY = _SERVICE_TABLE_ENTRYA;
  {$EXTERNALSYM SERVICE_TABLE_ENTRYA}
  SERVICE_TABLE_ENTRYA = _SERVICE_TABLE_ENTRYA;
  {$EXTERNALSYM SERVICE_TABLE_ENTRYW}
  SERVICE_TABLE_ENTRYW = _SERVICE_TABLE_ENTRYW;
  {$EXTERNALSYM SERVICE_TABLE_ENTRY}
  SERVICE_TABLE_ENTRY = SERVICE_TABLE_ENTRYA;
  TServiceTableEntryA = _SERVICE_TABLE_ENTRYA;
  TServiceTableEntryW = _SERVICE_TABLE_ENTRYW;
  TServiceTableEntry = TServiceTableEntryA;

//
// Prototype for the Service Control Handler Function
//




  {$EXTERNALSYM LPHANDLER_FUNCTION}
  LPHANDLER_FUNCTION = TFarProc;
  THandlerFunction = LPHANDLER_FUNCTION;

///////////////////////////////////////////////////////////////////////////
// API Function Prototypes
///////////////////////////////////////////////////////////////////////////

{$EXTERNALSYM ChangeServiceConfigA}
function ChangeServiceConfigA(hService: SC_HANDLE; dwServiceType, dwStartType,
  dwErrorControl: DWORD; lpBinaryPathName, lpLoadOrderGroup: PAnsiChar;
  lpdwTagId: LPDWORD; lpDependencies, lpServiceStartName, lpPassword,
  lpDisplayName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM ChangeServiceConfigW}
function ChangeServiceConfigW(hService: SC_HANDLE; dwServiceType, dwStartType,
  dwErrorControl: DWORD; lpBinaryPathName, lpLoadOrderGroup: PWideChar;
  lpdwTagId: LPDWORD; lpDependencies, lpServiceStartName, lpPassword,
  lpDisplayName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM ChangeServiceConfig}
function ChangeServiceConfig(hService: SC_HANDLE; dwServiceType, dwStartType,
  dwErrorControl: DWORD; lpBinaryPathName, lpLoadOrderGroup: PChar;
  lpdwTagId: LPDWORD; lpDependencies, lpServiceStartName, lpPassword,
  lpDisplayName: PChar): BOOL; stdcall;
{$EXTERNALSYM CloseServiceHandle}
function CloseServiceHandle(hSCObject: SC_HANDLE): BOOL; stdcall;
{$EXTERNALSYM ControlService}
function ControlService(hService: SC_HANDLE; dwControl: DWORD;
  var lpServiceStatus: TServiceStatus): BOOL; stdcall;
{$EXTERNALSYM CreateServiceA}
function CreateServiceA(hSCManager: SC_HANDLE; lpServiceName, lpDisplayName: PAnsiChar;
  dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl: DWORD;
  lpBinaryPathName, lpLoadOrderGroup: PAnsiChar; lpdwTagId: LPDWORD; lpDependencies,
  lpServiceStartName, lpPassword: PAnsiChar): SC_HANDLE; stdcall;
{$EXTERNALSYM CreateServiceW}
function CreateServiceW(hSCManager: SC_HANDLE; lpServiceName, lpDisplayName: PWideChar;
  dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl: DWORD;
  lpBinaryPathName, lpLoadOrderGroup: PWideChar; lpdwTagId: LPDWORD; lpDependencies,
  lpServiceStartName, lpPassword: PWideChar): SC_HANDLE; stdcall;
{$EXTERNALSYM CreateService}
function CreateService(hSCManager: SC_HANDLE; lpServiceName, lpDisplayName: PChar;
  dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl: DWORD;
  lpBinaryPathName, lpLoadOrderGroup: PChar; lpdwTagId: LPDWORD; lpDependencies,
  lpServiceStartName, lpPassword: PChar): SC_HANDLE; stdcall;
{$EXTERNALSYM DeleteService}
function DeleteService(hService: SC_HANDLE): BOOL; stdcall;
{$EXTERNALSYM EnumDependentServicesA}
function EnumDependentServicesA(hService: SC_HANDLE; dwServiceState: DWORD;
  var lpServices: TEnumServiceStatusA; cbBufSize: DWORD; var pcbBytesNeeded,
  lpServicesReturned : DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumDependentServicesW}
function EnumDependentServicesW(hService: SC_HANDLE; dwServiceState: DWORD;
  var lpServices: TEnumServiceStatusW; cbBufSize: DWORD; var pcbBytesNeeded,
  lpServicesReturned : DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumDependentServices}
function EnumDependentServices(hService: SC_HANDLE; dwServiceState: DWORD;
  var lpServices: TEnumServiceStatus; cbBufSize: DWORD; var pcbBytesNeeded,
  lpServicesReturned : DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumServicesStatusA}
function EnumServicesStatusA(hSCManager: SC_HANDLE; dwServiceType,
  dwServiceState: DWORD; var lpServices: TEnumServiceStatusA; cbBufSize: DWORD;
  var pcbBytesNeeded, lpServicesReturned, lpResumeHandle: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumServicesStatusW}
function EnumServicesStatusW(hSCManager: SC_HANDLE; dwServiceType,
  dwServiceState: DWORD; var lpServices: TEnumServiceStatusW; cbBufSize: DWORD;
  var pcbBytesNeeded, lpServicesReturned, lpResumeHandle: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumServicesStatus}
function EnumServicesStatus(hSCManager: SC_HANDLE; dwServiceType,
  dwServiceState: DWORD; var lpServices: TEnumServiceStatus; cbBufSize: DWORD;
  var pcbBytesNeeded, lpServicesReturned, lpResumeHandle: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetServiceKeyNameA}
function GetServiceKeyNameA(hSCManager: SC_HANDLE; lpDisplayName,
  lpServiceName: PAnsiChar; var lpcchBuffer: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetServiceKeyNameW}
function GetServiceKeyNameW(hSCManager: SC_HANDLE; lpDisplayName,
  lpServiceName: PWideChar; var lpcchBuffer: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetServiceKeyName}
function GetServiceKeyName(hSCManager: SC_HANDLE; lpDisplayName,
  lpServiceName: PChar; var lpcchBuffer: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetServiceDisplayNameA}
function GetServiceDisplayNameA(hSCManager: SC_HANDLE; lpServiceName,
  lpDisplayName: PAnsiChar; var lpcchBuffer: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetServiceDisplayNameW}
function GetServiceDisplayNameW(hSCManager: SC_HANDLE; lpServiceName,
  lpDisplayName: PWideChar; var lpcchBuffer: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetServiceDisplayName}
function GetServiceDisplayName(hSCManager: SC_HANDLE; lpServiceName,
  lpDisplayName: PChar; var lpcchBuffer: DWORD): BOOL; stdcall;
{$EXTERNALSYM LockServiceDatabase}
function LockServiceDatabase(hSCManager: SC_HANDLE): SC_LOCK; stdcall;
{$EXTERNALSYM NotifyBootConfigStatus}
function NotifyBootConfigStatus(BootAcceptable: BOOL): BOOL; stdcall;
{$EXTERNALSYM OpenSCManagerA}
function OpenSCManagerA(lpMachineName, lpDatabaseName: PAnsiChar;
  dwDesiredAccess: DWORD): SC_HANDLE; stdcall;
{$EXTERNALSYM OpenSCManagerW}
function OpenSCManagerW(lpMachineName, lpDatabaseName: PWideChar;
  dwDesiredAccess: DWORD): SC_HANDLE; stdcall;
{$EXTERNALSYM OpenSCManager}
function OpenSCManager(lpMachineName, lpDatabaseName: PChar;
  dwDesiredAccess: DWORD): SC_HANDLE; stdcall;
{$EXTERNALSYM OpenServiceA}
function OpenServiceA(hSCManager: SC_HANDLE; lpServiceName: PAnsiChar;
  dwDesiredAccess: DWORD): SC_HANDLE; stdcall;
{$EXTERNALSYM OpenServiceW}
function OpenServiceW(hSCManager: SC_HANDLE; lpServiceName: PWideChar;
  dwDesiredAccess: DWORD): SC_HANDLE; stdcall;
{$EXTERNALSYM OpenService}
function OpenService(hSCManager: SC_HANDLE; lpServiceName: PChar;
  dwDesiredAccess: DWORD): SC_HANDLE; stdcall;
{$EXTERNALSYM QueryServiceConfigA}
function QueryServiceConfigA(hService: SC_HANDLE;
  lpServiceConfig: PQueryServiceConfigA; cbBufSize: DWORD;
  var pcbBytesNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM QueryServiceConfigW}
function QueryServiceConfigW(hService: SC_HANDLE;
  lpServiceConfig: PQueryServiceConfigW; cbBufSize: DWORD;
  var pcbBytesNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM QueryServiceConfig}
function QueryServiceConfig(hService: SC_HANDLE;
  lpServiceConfig: PQueryServiceConfig; cbBufSize: DWORD;
  var pcbBytesNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM QueryServiceLockStatusA}
function QueryServiceLockStatusA(hSCManager: SC_HANDLE;
  var lpLockStatus: TQueryServiceLockStatusA; cbBufSize: DWORD;
  var pcbBytesNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM QueryServiceLockStatusW}
function QueryServiceLockStatusW(hSCManager: SC_HANDLE;
  var lpLockStatus: TQueryServiceLockStatusW; cbBufSize: DWORD;
  var pcbBytesNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM QueryServiceLockStatus}
function QueryServiceLockStatus(hSCManager: SC_HANDLE;
  var lpLockStatus: TQueryServiceLockStatus; cbBufSize: DWORD;
  var pcbBytesNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM QueryServiceObjectSecurity}
function QueryServiceObjectSecurity(hService: SC_HANDLE;
  dwSecurityInformation: SECURITY_INFORMATION;
  lpSecurityDescriptor: PSECURITY_DESCRIPTOR; cbBufSize: DWORD;
  var pcbBytesNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM QueryServiceStatus}
function QueryServiceStatus(hService: SC_HANDLE; var
  lpServiceStatus: TServiceStatus): BOOL; stdcall;
{$EXTERNALSYM RegisterServiceCtrlHandlerA}
function RegisterServiceCtrlHandlerA(lpServiceName: PAnsiChar;
  lpHandlerProc: ThandlerFunction): SERVICE_STATUS_HANDLE; stdcall;
{$EXTERNALSYM RegisterServiceCtrlHandlerW}
function RegisterServiceCtrlHandlerW(lpServiceName: PWideChar;
  lpHandlerProc: ThandlerFunction): SERVICE_STATUS_HANDLE; stdcall;
{$EXTERNALSYM RegisterServiceCtrlHandler}
function RegisterServiceCtrlHandler(lpServiceName: PChar;
  lpHandlerProc: ThandlerFunction): SERVICE_STATUS_HANDLE; stdcall;
{$EXTERNALSYM SetServiceObjectSecurity}
function SetServiceObjectSecurity(hService: SC_HANDLE;
  dwSecurityInformation: SECURITY_INFORMATION;
  lpSecurityDescriptor: PSECURITY_DESCRIPTOR): BOOL; stdcall;
{$EXTERNALSYM SetServiceStatus}
function SetServiceStatus(hServiceStatus: SERVICE_STATUS_HANDLE;
  var lpServiceStatus: TServiceStatus): BOOL; stdcall;
{$EXTERNALSYM StartServiceCtrlDispatcherA}
function StartServiceCtrlDispatcherA(
  var lpServiceStartTable: TServiceTableEntryA): BOOL; stdcall;
{$EXTERNALSYM StartServiceCtrlDispatcherW}
function StartServiceCtrlDispatcherW(
  var lpServiceStartTable: TServiceTableEntryW): BOOL; stdcall;
{$EXTERNALSYM StartServiceCtrlDispatcher}
function StartServiceCtrlDispatcher(
  var lpServiceStartTable: TServiceTableEntry): BOOL; stdcall;
{$EXTERNALSYM StartServiceA}
function StartServiceA(hService: SC_HANDLE; dwNumServiceArgs: DWORD;
  var lpServiceArgVectors: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM StartServiceW}
function StartServiceW(hService: SC_HANDLE; dwNumServiceArgs: DWORD;
  var lpServiceArgVectors: PWideChar): BOOL; stdcall;
{$EXTERNALSYM StartService}
function StartService(hService: SC_HANDLE; dwNumServiceArgs: DWORD;
  var lpServiceArgVectors: PChar): BOOL; stdcall;
{$EXTERNALSYM UnlockServiceDatabase}
function UnlockServiceDatabase(ScLock: SC_LOCK): BOOL; stdcall;

implementation

const
  advapi32 = 'advapi32.dll';

function ChangeServiceConfigA;   external advapi32 name 'ChangeServiceConfigA';
function ChangeServiceConfigW;   external advapi32 name 'ChangeServiceConfigW';
function ChangeServiceConfig;   external advapi32 name 'ChangeServiceConfigA';
function CloseServiceHandle;       external advapi32 name 'CloseServiceHandle';
function ControlService;           external advapi32 name 'ControlService';
function CreateServiceA;         external advapi32 name 'CreateServiceA';
function CreateServiceW;         external advapi32 name 'CreateServiceW';
function CreateService;         external advapi32 name 'CreateServiceA';
function DeleteService;            external advapi32 name 'DeleteService';
function EnumDependentServicesA; external advapi32 name 'EnumDependentServicesA';
function EnumDependentServicesW; external advapi32 name 'EnumDependentServicesW';
function EnumDependentServices; external advapi32 name 'EnumDependentServicesA';
function EnumServicesStatusA;    external advapi32 name 'EnumServicesStatusA';
function EnumServicesStatusW;    external advapi32 name 'EnumServicesStatusW';
function EnumServicesStatus;    external advapi32 name 'EnumServicesStatusA';
function GetServiceKeyNameA;     external advapi32 name 'GetServiceKeyNameA';
function GetServiceKeyNameW;     external advapi32 name 'GetServiceKeyNameW';
function GetServiceKeyName;     external advapi32 name 'GetServiceKeyNameA';
function GetServiceDisplayNameA; external advapi32 name 'GetServiceDisplayNameA';
function GetServiceDisplayNameW; external advapi32 name 'GetServiceDisplayNameW';
function GetServiceDisplayName; external advapi32 name 'GetServiceDisplayNameA';
function LockServiceDatabase;      external advapi32 name 'LockServiceDatabase';
function NotifyBootConfigStatus;   external advapi32 name 'NotifyBootConfigStatus';
function OpenSCManagerA;         external advapi32 name 'OpenSCManagerA';
function OpenSCManagerW;         external advapi32 name 'OpenSCManagerW';
function OpenSCManager;         external advapi32 name 'OpenSCManagerA';
function OpenServiceA;           external advapi32 name 'OpenServiceA';
function OpenServiceW;           external advapi32 name 'OpenServiceW';
function OpenService;           external advapi32 name 'OpenServiceA';
function QueryServiceConfigA;    external advapi32 name 'QueryServiceConfigA';
function QueryServiceConfigW;    external advapi32 name 'QueryServiceConfigW';
function QueryServiceConfig;    external advapi32 name 'QueryServiceConfigA';
function QueryServiceLockStatusA;external advapi32 name 'QueryServiceLockStatusA';
function QueryServiceLockStatusW;external advapi32 name 'QueryServiceLockStatusW';
function QueryServiceLockStatus;external advapi32 name 'QueryServiceLockStatusA';
function QueryServiceObjectSecurity;external advapi32 name 'QueryServiceObjectSecurity';
function QueryServiceStatus;       external advapi32 name 'QueryServiceStatus';
function RegisterServiceCtrlHandlerA;external advapi32 name 'RegisterServiceCtrlHandlerA';
function RegisterServiceCtrlHandlerW;external advapi32 name 'RegisterServiceCtrlHandlerW';
function RegisterServiceCtrlHandler;external advapi32 name 'RegisterServiceCtrlHandlerA';
function SetServiceObjectSecurity; external advapi32 name 'SetServiceObjectSecurity';
function SetServiceStatus;         external advapi32 name 'SetServiceStatus';
function StartServiceCtrlDispatcherA;external advapi32 name 'StartServiceCtrlDispatcherA';
function StartServiceCtrlDispatcherW;external advapi32 name 'StartServiceCtrlDispatcherW';
function StartServiceCtrlDispatcher;external advapi32 name 'StartServiceCtrlDispatcherA';
function StartServiceA;          external advapi32 name 'StartServiceA';
function StartServiceW;          external advapi32 name 'StartServiceW';
function StartService;          external advapi32 name 'StartServiceA';
function UnlockServiceDatabase;    external advapi32 name 'UnlockServiceDatabase';

end.

