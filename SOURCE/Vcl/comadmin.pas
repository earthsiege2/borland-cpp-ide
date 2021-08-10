{ *********************************************************************** }
{                                                                         }
{ Delphi Runtime Library                                                  }
{                                                                         }
{ Copyright (c) 1999-2001 Borland Software Corporation                    }
{                                                                         }
{ *********************************************************************** }

{ ***************************************************** }
{       COM+ Administration Interface Unit              }
{ ***************************************************** }

unit COMAdmin;

interface

uses
  Windows, ActiveX;

{$HPPEMIT '#include <comadmin.h>'}

const
  COMAdminMajorVersion = 1;
  COMAdminMinorVersion = 0;

  LIBID_COMAdmin: TGUID = '{F618C513-DFB8-11D1-A2CF-00805FC79235}';
  {$EXTERNALSYM LIBID_COMAdmin}

  IID_ICOMAdminCatalog: TGUID = '{DD662187-DFC2-11D1-A2CF-00805FC79235}';
  {$EXTERNALSYM IID_ICOMAdminCatalog}
  CLASS_COMAdminCatalog: TGUID = '{F618C514-DFB8-11D1-A2CF-00805FC79235}';
  IID_ICatalogObject: TGUID = '{6EB22871-8A19-11D0-81B6-00A0C9231C29}';
  {$EXTERNALSYM IID_ICatalogObject}
  CLASS_COMAdminCatalogObject: TGUID = '{F618C515-DFB8-11D1-A2CF-00805FC79235}';
  IID_ICatalogCollection: TGUID = '{6EB22872-8A19-11D0-81B6-00A0C9231C29}';
  {$EXTERNALSYM IID_ICatalogCollection}
  CLASS_COMAdminCatalogCollection: TGUID = '{F618C516-DFB8-11D1-A2CF-00805FC79235}';

type
  COMAdminApplicationInstallOptions = TOleEnum;
  {$EXTERNALSYM COMAdminApplicationInstallOptions}
const
  COMAdminInstallNoUsers = $00000000;
  {$EXTERNALSYM COMAdminInstallNoUsers}
  COMAdminInstallUsers = $00000001;
  {$EXTERNALSYM COMAdminInstallUsers}
  COMAdminInstallForceOverwriteOfFiles = $00000002;
  {$EXTERNALSYM COMAdminInstallForceOverwriteOfFiles}

type
  COMAdminApplicationExportOptions = TOleEnum;
  {$EXTERNALSYM COMAdminApplicationExportOptions}
const
  COMAdminExportNoUsers = $00000000;
  {$EXTERNALSYM COMAdminExportNoUsers}
  COMAdminExportUsers = $00000001;
  {$EXTERNALSYM COMAdminExportUsers}
  COMAdminExportApplicationProxy = $00000002;
  {$EXTERNALSYM COMAdminExportApplicationProxy}
  COMAdminExportForceOverwriteOfFiles = $00000004;
  {$EXTERNALSYM COMAdminExportForceOverwriteOfFiles}

type
  COMAdminThreadingModels = TOleEnum;
  {$EXTERNALSYM COMAdminThreadingModels}
const
  COMAdminThreadingModelApartment = $00000000;
  {$EXTERNALSYM COMAdminThreadingModelApartment}
  COMAdminThreadingModelFree = $00000001;
  {$EXTERNALSYM COMAdminThreadingModelFree}
  COMAdminThreadingModelMain = $00000002;
  {$EXTERNALSYM COMAdminThreadingModelMain}
  COMAdminThreadingModelBoth = $00000003;
  {$EXTERNALSYM COMAdminThreadingModelBoth}
  COMAdminThreadingModelNeutral = $00000004;
  {$EXTERNALSYM COMAdminThreadingModelNeutral}
  COMAdminThreadingModelNotSpecified = $00000005;
  {$EXTERNALSYM COMAdminThreadingModelNotSpecified}

type
  COMAdminTransactionOptions = TOleEnum;
  {$EXTERNALSYM COMAdminTransactionOptions}
const
  COMAdminTransactionIgnored = $00000000;
  {$EXTERNALSYM COMAdminTransactionIgnored}
  COMAdminTransactionNone = $00000001;
  {$EXTERNALSYM COMAdminTransactionNone}
  COMAdminTransactionSupported = $00000002;
  {$EXTERNALSYM COMAdminTransactionSupported}
  COMAdminTransactionRequired = $00000003;
  {$EXTERNALSYM COMAdminTransactionRequired}
  COMAdminTransactionRequiresNew = $00000004;
  {$EXTERNALSYM COMAdminTransactionRequiresNew}

type
  COMAdminSynchronizationOptions = TOleEnum;
  {$EXTERNALSYM COMAdminSynchronizationOptions}
const
  COMAdminSynchronizationIgnored = $00000000;
  {$EXTERNALSYM COMAdminSynchronizationIgnored}
  COMAdminSynchronizationNone = $00000001;
  {$EXTERNALSYM COMAdminSynchronizationNone}
  COMAdminSynchronizationSupported = $00000002;
  {$EXTERNALSYM COMAdminSynchronizationSupported}
  COMAdminSynchronizationRequired = $00000003;
  {$EXTERNALSYM COMAdminSynchronizationRequired}
  COMAdminSynchronizationRequiresNew = $00000004;
  {$EXTERNALSYM COMAdminSynchronizationRequiresNew}

type
  COMAdminActivationOptions = TOleEnum;
  {$EXTERNALSYM COMAdminActivationOptions}
const
  COMAdminActivationInproc = $00000000;
  {$EXTERNALSYM COMAdminActivationInproc}
  COMAdminActivationLocal = $00000001;
  {$EXTERNALSYM COMAdminActivationLocal}

type
  COMAdminAccessChecksLevelOptions = TOleEnum;
  {$EXTERNALSYM COMAdminAccessChecksLevelOptions}
const
  COMAdminAccessChecksApplicationLevel = $00000000;
  {$EXTERNALSYM COMAdminAccessChecksApplicationLevel}
  COMAdminAccessChecksApplicationComponentLevel = $00000001;
  {$EXTERNALSYM COMAdminAccessChecksApplicationComponentLevel}

type
  COMAdminAuthenticationLevelOptions = TOleEnum;
  {$EXTERNALSYM COMAdminAuthenticationLevelOptions}
const
  COMAdminAuthenticationDefault = $00000000;
  {$EXTERNALSYM COMAdminAuthenticationDefault}
  COMAdminAuthenticationNone = $00000001;
  {$EXTERNALSYM COMAdminAuthenticationNone}
  COMAdminAuthenticationConnect = $00000002;
  {$EXTERNALSYM COMAdminAuthenticationConnect}
  COMAdminAuthenticationCall = $00000003;
  {$EXTERNALSYM COMAdminAuthenticationCall}
  COMAdminAuthenticationPacket = $00000004;
  {$EXTERNALSYM COMAdminAuthenticationPacket}
  COMAdminAuthenticationIntegrity = $00000005;
  {$EXTERNALSYM COMAdminAuthenticationIntegrity}
  COMAdminAuthenticationPrivacy = $00000006;
  {$EXTERNALSYM COMAdminAuthenticationPrivacy}

type
  COMAdminImpersonationLevelOptions = TOleEnum;
  {$EXTERNALSYM COMAdminImpersonationLevelOptions}
const
  COMAdminImpersonationAnonymous = $00000001;
  {$EXTERNALSYM COMAdminImpersonationAnonymous}
  COMAdminImpersonationIdentify = $00000002;
  {$EXTERNALSYM COMAdminImpersonationIdentify}
  COMAdminImpersonationImpersonate = $00000003;
  {$EXTERNALSYM COMAdminImpersonationImpersonate}
  COMAdminImpersonationDelegate = $00000004;
  {$EXTERNALSYM COMAdminImpersonationDelegate}

type
  COMAdminAuthenticationCapabilitiesOptions = TOleEnum;
  {$EXTERNALSYM COMAdminAuthenticationCapabilitiesOptions}
const
  COMAdminAuthenticationCapabilitiesNone = $00000000;
  {$EXTERNALSYM COMAdminAuthenticationCapabilitiesNone}
  COMAdminAuthenticationCapabilitiesStaticCloaking = $00000020;
  {$EXTERNALSYM COMAdminAuthenticationCapabilitiesStaticCloaking}
  COMAdminAuthenticationCapabilitiesDynamicCloaking = $00000040;
  {$EXTERNALSYM COMAdminAuthenticationCapabilitiesDynamicCloaking}
  COMAdminAuthenticationCapabilitiesSecureReference = $00000002;
  {$EXTERNALSYM COMAdminAuthenticationCapabilitiesSecureReference}

type
  COMAdminOS = TOleEnum;
  {$EXTERNALSYM COMAdminOS}
const
  COMAdminOSWindows3_1 = $00000001;
  {$EXTERNALSYM COMAdminOSWindows3_1}
  COMAdminOSWindows9x = $00000002;
  {$EXTERNALSYM COMAdminOSWindows9x}
  COMAdminOSWindowsNT = $00000003;
  {$EXTERNALSYM COMAdminOSWindowsNT}
  COMAdminOSWindowsNTEnterprise = $00000004;
  {$EXTERNALSYM COMAdminOSWindowsNTEnterprise}

type
  COMAdminServiceOptions = TOleEnum;
  {$EXTERNALSYM COMAdminServiceOptions}
const
  COMAdminServiceLoadBalanceRouter = $00000001;
  {$EXTERNALSYM COMAdminServiceLoadBalanceRouter}
  COMAdminServiceIMDB = $00000002;
  {$EXTERNALSYM COMAdminServiceIMDB}

type
  COMAdminServiceStatusOptions = TOleEnum;
  {$EXTERNALSYM COMAdminServiceStatusOptions}
const
  COMAdminServiceStopped = $00000000;
  {$EXTERNALSYM COMAdminServiceStopped}
  COMAdminServiceStartPending = $00000001;
  {$EXTERNALSYM COMAdminServiceStartPending}
  COMAdminServiceStopPending = $00000002;
  {$EXTERNALSYM COMAdminServiceStopPending}
  COMAdminServiceRunning = $00000003;
  {$EXTERNALSYM COMAdminServiceRunning}
  COMAdminServiceContinuePending = $00000004;
  {$EXTERNALSYM COMAdminServiceContinuePending}
  COMAdminServicePausePending = $00000005;
  {$EXTERNALSYM COMAdminServicePausePending}
  COMAdminServicePaused = $00000006;
  {$EXTERNALSYM COMAdminServicePaused}
  COMAdminServiceUnknownState = $00000007;
  {$EXTERNALSYM COMAdminServiceUnknownState}

type
  COMAdminFileFlags = TOleEnum;
  {$EXTERNALSYM COMAdminFileFlags}
const
  COMAdminFileFlagLoadable = $00000001;
  {$EXTERNALSYM COMAdminFileFlagLoadable}
  COMAdminFileFlagCOM = $00000002;
  {$EXTERNALSYM COMAdminFileFlagCOM}
  COMAdminFileFlagContainsPS = $00000004;
  {$EXTERNALSYM COMAdminFileFlagContainsPS}
  COMAdminFileFlagContainsComp = $00000008;
  {$EXTERNALSYM COMAdminFileFlagContainsComp}
  COMAdminFileFlagContainsTLB = $00000010;
  {$EXTERNALSYM COMAdminFileFlagContainsTLB}
  COMAdminFileFlagSelfReg = $00000020;
  {$EXTERNALSYM COMAdminFileFlagSelfReg}
  COMAdminFileFlagSelfUnReg = $00000040;
  {$EXTERNALSYM COMAdminFileFlagSelfUnReg}
  COMAdminFileFlagUnloadableDLL = $00000080;
  {$EXTERNALSYM COMAdminFileFlagUnloadableDLL}
  COMAdminFileFlagDoesNotExist = $00000100;
  {$EXTERNALSYM COMAdminFileFlagDoesNotExist}
  COMAdminFileFlagAlreadyInstalled = $00000200;
  {$EXTERNALSYM COMAdminFileFlagAlreadyInstalled}
  COMAdminFileFlagBadTLB = $00000400;
  {$EXTERNALSYM COMAdminFileFlagBadTLB}
  COMAdminFileFlagGetClassObjFailed = $00000800;
  {$EXTERNALSYM COMAdminFileFlagGetClassObjFailed}
  COMAdminFileFlagClassNotAvailable = $00001000;
  {$EXTERNALSYM COMAdminFileFlagClassNotAvailable}
  COMAdminFileFlagRegistrar = $00002000;
  {$EXTERNALSYM COMAdminFileFlagRegistrar}
  COMAdminFileFlagNoRegistrar = $00004000;
  {$EXTERNALSYM COMAdminFileFlagNoRegistrar}
  COMAdminFileFlagDLLRegsvrFailed = $00008000;
  {$EXTERNALSYM COMAdminFileFlagDLLRegsvrFailed}
  COMAdminFileFlagRegTLBFailed = $00010000;
  {$EXTERNALSYM COMAdminFileFlagRegTLBFailed}
  COMAdminFileFlagRegistrarFailed = $00020000;
  {$EXTERNALSYM COMAdminFileFlagRegistrarFailed}
  COMAdminFileFlagError = $00040000;
  {$EXTERNALSYM COMAdminFileFlagError}

type
  COMAdminComponentFlags = TOleEnum;
  {$EXTERNALSYM COMAdminComponentFlags}
const
  COMAdminCompFlagTypeInfoFound = $00000001;
  {$EXTERNALSYM COMAdminCompFlagTypeInfoFound}
  COMAdminCompFlagCOMPlusPropertiesFound = $00000002;
  {$EXTERNALSYM COMAdminCompFlagCOMPlusPropertiesFound}
  COMAdminCompFlagProxyFound = $00000004;
  {$EXTERNALSYM COMAdminCompFlagProxyFound}
  COMAdminCompFlagInterfacesFound = $00000008;
  {$EXTERNALSYM COMAdminCompFlagInterfacesFound}
  COMAdminCompFlagAlreadyInstalled = $00000010;
  {$EXTERNALSYM COMAdminCompFlagAlreadyInstalled}
  COMAdminCompFlagNotInApplication = $00000020;
  {$EXTERNALSYM COMAdminCompFlagNotInApplication}

type
  COMAdminErrorCodes = TOleEnum;
  {$EXTERNALSYM COMAdminErrorCodes}
const
  COMAdminErrObjectErrors = $80110401;
  {$EXTERNALSYM COMAdminErrObjectErrors}
  COMAdminErrObjectInvalid = $80110402;
  {$EXTERNALSYM COMAdminErrObjectInvalid}
  COMAdminErrKeyMissing = $80110403;
  {$EXTERNALSYM COMAdminErrKeyMissing}
  COMAdminErrAlreadyInstalled = $80110404;
  {$EXTERNALSYM COMAdminErrAlreadyInstalled}
  COMAdminErrAppFileWriteFail = $80110407;
  {$EXTERNALSYM COMAdminErrAppFileWriteFail}
  COMAdminErrAppFileReadFail = $80110408;
  {$EXTERNALSYM COMAdminErrAppFileReadFail}
  COMAdminErrAppFileVersion = $80110409;
  {$EXTERNALSYM COMAdminErrAppFileVersion}
  COMAdminErrBadPath = $8011040A;
  {$EXTERNALSYM COMAdminErrBadPath}
  COMAdminErrApplicationExists = $8011040B;
  {$EXTERNALSYM COMAdminErrApplicationExists}
  COMAdminErrRoleExists = $8011040C;
  {$EXTERNALSYM COMAdminErrRoleExists}
  COMAdminErrCantCopyFile = $8011040D;
  {$EXTERNALSYM COMAdminErrCantCopyFile}
  COMAdminErrNoUser = $8011040F;
  {$EXTERNALSYM COMAdminErrNoUser}
  COMAdminErrInvalidUserids = $80110410;
  {$EXTERNALSYM COMAdminErrInvalidUserids}
  COMAdminErrNoRegistryCLSID = $80110411;
  {$EXTERNALSYM COMAdminErrNoRegistryCLSID}
  COMAdminErrBadRegistryProgID = $80110412;
  {$EXTERNALSYM COMAdminErrBadRegistryProgID}
  COMAdminErrAuthenticationLevel = $80110413;
  {$EXTERNALSYM COMAdminErrAuthenticationLevel}
  COMAdminErrUserPasswdNotValid = $80110414;
  {$EXTERNALSYM COMAdminErrUserPasswdNotValid}
  COMAdminErrCLSIDOrIIDMismatch = $80110418;
  {$EXTERNALSYM COMAdminErrCLSIDOrIIDMismatch}
  COMAdminErrRemoteInterface = $80110419;
  {$EXTERNALSYM COMAdminErrRemoteInterface}
  COMAdminErrDllRegisterServer = $8011041A;
  {$EXTERNALSYM COMAdminErrDllRegisterServer}
  COMAdminErrNoServerShare = $8011041B;
  {$EXTERNALSYM COMAdminErrNoServerShare}
  COMAdminErrDllLoadFailed = $8011041D;
  {$EXTERNALSYM COMAdminErrDllLoadFailed}
  COMAdminErrBadRegistryLibID = $8011041E;
  {$EXTERNALSYM COMAdminErrBadRegistryLibID}
  COMAdminErrAppDirNotFound = $8011041F;
  {$EXTERNALSYM COMAdminErrAppDirNotFound}
  COMAdminErrRegistrarFailed = $80110423;
  {$EXTERNALSYM COMAdminErrRegistrarFailed}
  COMAdminErrCompFileDoesNotExist = $80110424;
  {$EXTERNALSYM COMAdminErrCompFileDoesNotExist}
  COMAdminErrCompFileLoadDLLFail = $80110425;
  {$EXTERNALSYM COMAdminErrCompFileLoadDLLFail}
  COMAdminErrCompFileGetClassObj = $80110426;
  {$EXTERNALSYM COMAdminErrCompFileGetClassObj}
  COMAdminErrCompFileClassNotAvail = $80110427;
  {$EXTERNALSYM COMAdminErrCompFileClassNotAvail}
  COMAdminErrCompFileBadTLB = $80110428;
  {$EXTERNALSYM COMAdminErrCompFileBadTLB}
  COMAdminErrCompFileNotInstallable = $80110429;
  {$EXTERNALSYM COMAdminErrCompFileNotInstallable}
  COMAdminErrNotChangeable = $8011042A;
  {$EXTERNALSYM COMAdminErrNotChangeable}
  COMAdminErrNotDeletable = $8011042B;
  {$EXTERNALSYM COMAdminErrNotDeletable}
  COMAdminErrSession = $8011042C;
  {$EXTERNALSYM COMAdminErrSession}
  COMAdminErrCompMoveLocked = $8011042D;
  {$EXTERNALSYM COMAdminErrCompMoveLocked}
  COMAdminErrCompMoveBadDest = $8011042E;
  {$EXTERNALSYM COMAdminErrCompMoveBadDest}
  COMAdminErrRegisterTLB = $80110430;
  {$EXTERNALSYM COMAdminErrRegisterTLB}
  COMAdminErrSystemApp = $80110433;
  {$EXTERNALSYM COMAdminErrSystemApp}
  COMAdminErrCompFileNoRegistrar = $80110434;
  {$EXTERNALSYM COMAdminErrCompFileNoRegistrar}
  COMAdminErrCoReqCompInstalled = $80110435;
  {$EXTERNALSYM COMAdminErrCoReqCompInstalled}
  COMAdminErrServiceNotInstalled = $80110436;
  {$EXTERNALSYM COMAdminErrServiceNotInstalled}
  COMAdminErrPropertySaveFailed = $80110437;
  {$EXTERNALSYM COMAdminErrPropertySaveFailed}
  COMAdminErrObjectExists = $80110438;
  {$EXTERNALSYM COMAdminErrObjectExists}
  COMAdminErrRegFileCorrupt = $8011043B;
  {$EXTERNALSYM COMAdminErrRegFileCorrupt}
  COMAdminErrPropertyOverflow = $8011043C;
  {$EXTERNALSYM COMAdminErrPropertyOverflow}
  COMAdminErrNotInRegistry = $8011043E;
  {$EXTERNALSYM COMAdminErrNotInRegistry}
  COMAdminErrObjectNotPoolable = $8011043F;
  {$EXTERNALSYM COMAdminErrObjectNotPoolable}
  COMAdminErrApplidMatchesClsid = $80110446;
  {$EXTERNALSYM COMAdminErrApplidMatchesClsid}
  COMAdminErrRoleDoesNotExist = $80110447;
  {$EXTERNALSYM COMAdminErrRoleDoesNotExist}
  COMAdminErrStartAppNeedsComponents = $80110448;
  {$EXTERNALSYM COMAdminErrStartAppNeedsComponents}
  COMAdminErrRequiresDifferentPlatform = $80110449;
  {$EXTERNALSYM COMAdminErrRequiresDifferentPlatform}
  COMAdminErrQueuingServiceNotAvailable = $80110602;
  {$EXTERNALSYM COMAdminErrQueuingServiceNotAvailable}
  COMAdminErrObjectParentMissing = $80110808;
  {$EXTERNALSYM COMAdminErrObjectParentMissing}
  COMAdminErrObjectDoesNotExist = $80110809;
  {$EXTERNALSYM COMAdminErrObjectDoesNotExist}
  COMAdminErrCanNotExportAppProxy = $8011044A;
  {$EXTERNALSYM COMAdminErrCanNotExportAppProxy}
  COMAdminErrCanNotStartApp = $8011044B;
  {$EXTERNALSYM COMAdminErrCanNotStartApp}
  COMAdminErrCanNotExportSystemApp = $8011044C;
  {$EXTERNALSYM COMAdminErrCanNotExportSystemApp}
  COMAdminErrCanNotSubscribeToComponent = $8011044D;
  {$EXTERNALSYM COMAdminErrCanNotSubscribeToComponent}

type

  // *********************************************************************//
  // Forward declaration of types defined in TypeLibrary                    
  // *********************************************************************//
  ICOMAdminCatalog = interface;
  ICOMAdminCatalogDisp = dispinterface;
  ICatalogObject = interface;
  ICatalogObjectDisp = dispinterface;
  ICatalogCollection = interface;
  ICatalogCollectionDisp = dispinterface;

  // *********************************************************************//
  // Declaration of CoClasses defined in Type Library                       
  // *********************************************************************//
  COMAdminCatalog = ICOMAdminCatalog;
  COMAdminCatalogObject = ICatalogObject;
  COMAdminCatalogCollection = ICatalogCollection;


  // *********************************************************************//
  // Declaration of structures, unions and aliases.                         
  // *********************************************************************//
  PPSafeArray1 = ^PSafeArray; {*}

  ICOMAdminCatalog = interface(IDispatch)
    ['{DD662187-DFC2-11D1-A2CF-00805FC79235}']
    function  GetCollection(const bstrCollName: WideString): IDispatch; safecall;
    function  Connect(const bstrConnectString: WideString): IDispatch; safecall;
    function  Get_MajorVersion: Integer; safecall;
    function  Get_MinorVersion: Integer; safecall;
    function  GetCollectionByQuery(const bstrCollName: WideString; var aQuery: PSafeArray): IDispatch; safecall;
    procedure ImportComponent(const bstrApplIdOrName: WideString; 
                              const bstrCLSIDOrProgId: WideString); safecall;
    procedure InstallComponent(const bstrApplIdOrName: WideString; const bstrDLL: WideString; 
                               const bstrTLB: WideString; const bstrPSDLL: WideString); safecall;
    procedure ShutdownApplication(const bstrApplIdOrName: WideString); safecall;
    procedure ExportApplication(const bstrApplIdOrName: WideString; 
                                const bstrApplicationFile: WideString; lOptions: Integer); safecall;
    procedure InstallApplication(const bstrApplicationFile: WideString; 
                                 const bstrDestinationDirectory: WideString; lOptions: Integer; 
                                 const bstrUserId: WideString; const bstrPassword: WideString; 
                                 const bstrRSN: WideString); safecall;
    procedure StopRouter; safecall;
    procedure RefreshRouter; safecall;
    procedure StartRouter; safecall;
    procedure Reserved1; safecall;
    procedure Reserved2; safecall;
    procedure InstallMultipleComponents(const bstrApplIdOrName: WideString; 
                                        var varFileNames: PSafeArray; var varCLSIDS: PSafeArray); safecall;
    procedure GetMultipleComponentsInfo(const bstrApplIdOrName: WideString; 
                                        var varFileNames: PSafeArray; out varCLSIDS: PSafeArray; 
                                        out varClassNames: PSafeArray; 
                                        out varFileFlags: PSafeArray; 
                                        out varComponentFlags: PSafeArray); safecall;
    procedure RefreshComponents; safecall;
    procedure BackupREGDB(const bstrBackupFilePath: WideString); safecall;
    procedure RestoreREGDB(const bstrBackupFilePath: WideString); safecall;
    procedure QueryApplicationFile(const bstrApplicationFile: WideString; 
                                   out bstrApplicationName: WideString; 
                                   out bstrApplicationDescription: WideString; 
                                   out bHasUsers: WordBool; out bIsProxy: WordBool; 
                                   out varFileNames: PSafeArray); safecall;
    procedure StartApplication(const bstrApplIdOrName: WideString); safecall;
    function  ServiceCheck(lService: Integer): Integer; safecall;
    procedure InstallMultipleEventClasses(const bstrApplIdOrName: WideString; 
                                          var varFileNames: PSafeArray; var varCLSIDS: PSafeArray); safecall;
    procedure InstallEventClass(const bstrApplIdOrName: WideString; const bstrDLL: WideString; 
                                const bstrTLB: WideString; const bstrPSDLL: WideString); safecall;
    procedure GetEventClassesForIID(const bstrIID: WideString; out varCLSIDS: PSafeArray; 
                                    out varProgIDs: PSafeArray; out varDescriptions: PSafeArray); safecall;
    property MajorVersion: Integer read Get_MajorVersion;
    property MinorVersion: Integer read Get_MinorVersion;
  end;

  ICOMAdminCatalogDisp = dispinterface
    ['{DD662187-DFC2-11D1-A2CF-00805FC79235}']
    function  GetCollection(const bstrCollName: WideString): IDispatch; dispid 1;
    function  Connect(const bstrConnectString: WideString): IDispatch; dispid 2;
    property MajorVersion: Integer readonly dispid 3;
    property MinorVersion: Integer readonly dispid 4;
    function  GetCollectionByQuery(const bstrCollName: WideString; 
                                   var aQuery: {??PSafeArray} OleVariant): IDispatch; dispid 5;
    procedure ImportComponent(const bstrApplIdOrName: WideString; 
                              const bstrCLSIDOrProgId: WideString); dispid 6;
    procedure InstallComponent(const bstrApplIdOrName: WideString; const bstrDLL: WideString; 
                               const bstrTLB: WideString; const bstrPSDLL: WideString); dispid 7;
    procedure ShutdownApplication(const bstrApplIdOrName: WideString); dispid 8;
    procedure ExportApplication(const bstrApplIdOrName: WideString; 
                                const bstrApplicationFile: WideString; lOptions: Integer); dispid 9;
    procedure InstallApplication(const bstrApplicationFile: WideString; 
                                 const bstrDestinationDirectory: WideString; lOptions: Integer; 
                                 const bstrUserId: WideString; const bstrPassword: WideString; 
                                 const bstrRSN: WideString); dispid 10;
    procedure StopRouter; dispid 11;
    procedure RefreshRouter; dispid 12;
    procedure StartRouter; dispid 13;
    procedure Reserved1; dispid 14;
    procedure Reserved2; dispid 15;
    procedure InstallMultipleComponents(const bstrApplIdOrName: WideString; 
                                        var varFileNames: {??PSafeArray} OleVariant; 
                                        var varCLSIDS: {??PSafeArray} OleVariant); dispid 16;
    procedure GetMultipleComponentsInfo(const bstrApplIdOrName: WideString; 
                                        var varFileNames: {??PSafeArray} OleVariant; 
                                        out varCLSIDS: {??PSafeArray} OleVariant; 
                                        out varClassNames: {??PSafeArray} OleVariant; 
                                        out varFileFlags: {??PSafeArray} OleVariant; 
                                        out varComponentFlags: {??PSafeArray} OleVariant); dispid 17;
    procedure RefreshComponents; dispid 18;
    procedure BackupREGDB(const bstrBackupFilePath: WideString); dispid 19;
    procedure RestoreREGDB(const bstrBackupFilePath: WideString); dispid 20;
    procedure QueryApplicationFile(const bstrApplicationFile: WideString; 
                                   out bstrApplicationName: WideString; 
                                   out bstrApplicationDescription: WideString; 
                                   out bHasUsers: WordBool; out bIsProxy: WordBool; 
                                   out varFileNames: {??PSafeArray} OleVariant); dispid 21;
    procedure StartApplication(const bstrApplIdOrName: WideString); dispid 22;
    function  ServiceCheck(lService: Integer): Integer; dispid 23;
    procedure InstallMultipleEventClasses(const bstrApplIdOrName: WideString; 
                                          var varFileNames: {??PSafeArray} OleVariant; 
                                          var varCLSIDS: {??PSafeArray} OleVariant); dispid 24;
    procedure InstallEventClass(const bstrApplIdOrName: WideString; const bstrDLL: WideString; 
                                const bstrTLB: WideString; const bstrPSDLL: WideString); dispid 25;
    procedure GetEventClassesForIID(const bstrIID: WideString; 
                                    out varCLSIDS: {??PSafeArray} OleVariant; 
                                    out varProgIDs: {??PSafeArray} OleVariant; 
                                    out varDescriptions: {??PSafeArray} OleVariant); dispid 26;
  end;

  ICatalogObject = interface(IDispatch)
    ['{6EB22871-8A19-11D0-81B6-00A0C9231C29}']
    function  Get_Value(const bstrPropName: WideString): OleVariant; safecall;
    procedure Set_Value(const bstrPropName: WideString; retval: OleVariant); safecall;
    function  Get_Key: OleVariant; safecall;
    function  Get_Name: OleVariant; safecall;
    function  IsPropertyReadOnly(const bstrPropName: WideString): WordBool; safecall;
    function  Get_Valid: WordBool; safecall;
    function  IsPropertyWriteOnly(const bstrPropName: WideString): WordBool; safecall;
    property Value[const bstrPropName: WideString]: OleVariant read Get_Value write Set_Value;
    property Key: OleVariant read Get_Key;
    property Name: OleVariant read Get_Name;
    property Valid: WordBool read Get_Valid;
  end;

  ICatalogObjectDisp = dispinterface
    ['{6EB22871-8A19-11D0-81B6-00A0C9231C29}']
    property Value[const bstrPropName: WideString]: OleVariant dispid 1;
    property Key: OleVariant readonly dispid 2;
    property Name: OleVariant readonly dispid 3;
    function  IsPropertyReadOnly(const bstrPropName: WideString): WordBool; dispid 4;
    property Valid: WordBool readonly dispid 5;
    function  IsPropertyWriteOnly(const bstrPropName: WideString): WordBool; dispid 6;
  end;

  ICatalogCollection = interface(IDispatch)
    ['{6EB22872-8A19-11D0-81B6-00A0C9231C29}']
    function  Get__NewEnum: IUnknown; safecall;
    function  Get_Item(lIndex: Integer): IDispatch; safecall;
    function  Get_Count: Integer; safecall;
    procedure Remove(lIndex: Integer); safecall;
    function  Add: IDispatch; safecall;
    procedure Populate; safecall;
    function  SaveChanges: Integer; safecall;
    function  GetCollection(const bstrCollName: WideString; varObjectKey: OleVariant): IDispatch; safecall;
    function  Get_Name: OleVariant; safecall;
    function  Get_AddEnabled: WordBool; safecall;
    function  Get_RemoveEnabled: WordBool; safecall;
    function  GetUtilInterface: IDispatch; safecall;
    function  Get_DataStoreMajorVersion: Integer; safecall;
    function  Get_DataStoreMinorVersion: Integer; safecall;
    procedure PopulateByKey(aKeys: PSafeArray); safecall;
    procedure PopulateByQuery(const bstrQueryString: WideString; lQueryType: Integer); safecall;
    property _NewEnum: IUnknown read Get__NewEnum;
    property Item[lIndex: Integer]: IDispatch read Get_Item;
    property Count: Integer read Get_Count;
    property Name: OleVariant read Get_Name;
    property AddEnabled: WordBool read Get_AddEnabled;
    property RemoveEnabled: WordBool read Get_RemoveEnabled;
    property DataStoreMajorVersion: Integer read Get_DataStoreMajorVersion;
    property DataStoreMinorVersion: Integer read Get_DataStoreMinorVersion;
  end;

  ICatalogCollectionDisp = dispinterface
    ['{6EB22872-8A19-11D0-81B6-00A0C9231C29}']
    property _NewEnum: IUnknown readonly dispid -4;
    property Item[lIndex: Integer]: IDispatch readonly dispid 1;
    property Count: Integer readonly dispid 1610743810;
    procedure Remove(lIndex: Integer); dispid 1610743811;
    function  Add: IDispatch; dispid 1610743812;
    procedure Populate; dispid 2;
    function  SaveChanges: Integer; dispid 3;
    function  GetCollection(const bstrCollName: WideString; varObjectKey: OleVariant): IDispatch; dispid 4;
    property Name: OleVariant readonly dispid 6;
    property AddEnabled: WordBool readonly dispid 7;
    property RemoveEnabled: WordBool readonly dispid 8;
    function  GetUtilInterface: IDispatch; dispid 9;
    property DataStoreMajorVersion: Integer readonly dispid 10;
    property DataStoreMinorVersion: Integer readonly dispid 11;
    procedure PopulateByKey(aKeys: {??PSafeArray} OleVariant); dispid 12;
    procedure PopulateByQuery(const bstrQueryString: WideString; lQueryType: Integer); dispid 13;
  end;

implementation

end.

