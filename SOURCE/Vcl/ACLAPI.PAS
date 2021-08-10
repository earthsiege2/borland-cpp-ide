
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       Win32 Security API Interface Unit               }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Inprise Corporation                 }
{                                                       }
{*******************************************************}

unit AclApi;

{$WEAKPACKAGEUNIT}

//  Contents:    public header file for acl and trusted server access control
//               APIs

interface

(*HPPEMIT '#include <aclApi.h>' *)

uses
  Windows, AccCtrl;

type
  PPSID = ^PSID;
  {$EXTERNALSYM PPSID}
  PPSECURITY_DESCRIPTOR = ^PSECURITY_DESCRIPTOR;
  {$EXTERNALSYM PPSECURITY_DESCRIPTOR}

function SetEntriesInAclA(cCountOfExplicitEntries: ULONG; pListOfExplicitEntries: PEXPLICIT_ACCESS_A;
         OldAcl: PACL; var NewAcl: ACL): DWORD; stdcall; {use localfree to release NewAcl}
function SetEntriesInAclW(cCountOfExplicitEntries: ULONG; pListOfExplicitEntries: PEXPLICIT_ACCESS_W;
         OldAcl: PACL; var NewAcl: ACL): DWORD; stdcall; {use localfree to release NewAcl}
function SetEntriesInAcl(cCountOfExplicitEntries: ULONG; pListOfExplicitEntries: PEXPLICIT_ACCESS_;
         OldAcl: PACL; var NewAcl: ACL): DWORD; stdcall; {use localfree to release NewAcl}
function GetExplicitEntriesFromAclA(var pacl: ACL; var pcCountOfExplicitEntries: ULONG;
         pListOfExplicitEntries: PEXPLICIT_ACCESS_A): DWORD; stdcall; {use localfree to release pListOfExplicitEntries}
function GetExplicitEntriesFromAclW(var pacl: ACL; var pcCountOfExplicitEntries: ULONG;
         pListOfExplicitEntries: PEXPLICIT_ACCESS_W): DWORD; stdcall; {use localfree to release pListOfExplicitEntries}
function GetExplicitEntriesFromAcl(var pacl: ACL; var pcCountOfExplicitEntries: ULONG;
         pListOfExplicitEntries: PEXPLICIT_ACCESS_): DWORD; stdcall; {use localfree to release pListOfExplicitEntries}
function GetEffectiveRightsFromAclA(var pacl: ACL; var pTrustee: TRUSTEE_A;
         var pAccessRights: ACCESS_MASK): DWORD; stdcall;
function GetEffectiveRightsFromAclW(var pacl: ACL; var pTrustee: TRUSTEE_W;
         var pAccessRights: ACCESS_MASK): DWORD; stdcall;
function GetEffectiveRightsFromAcl(var pacl: ACL; var pTrustee: TRUSTEE_;
         var pAccessRights: ACCESS_MASK): DWORD; stdcall;
function GetAuditedPermissionsFromAclA(var pacl: ACL; var pTrustee: TRUSTEE_A;
         var pSuccessfulAuditedRights: ACCESS_MASK; var pFailedAuditRights: ACCESS_MASK): DWORD; stdcall;
function GetAuditedPermissionsFromAclW(var pacl: ACL; var pTrustee: TRUSTEE_W;
         var pSuccessfulAuditedRights: ACCESS_MASK; var pFailedAuditRights: ACCESS_MASK): DWORD; stdcall;
function GetAuditedPermissionsFromAcl(var pacl: ACL; var pTrustee: TRUSTEE_;
         var pSuccessfulAuditedRights: ACCESS_MASK; var pFailedAuditRights: ACCESS_MASK): DWORD; stdcall;
function GetNamedSecurityInfoA(pObjectName: PAnsiChar; ObjectType: SE_OBJECT_TYPE;
         SecurityInfo: SECURITY_INFORMATION; ppsidOwner, ppsidGroup: PPSID; ppDacl, ppSacl: PACL;
         var ppSecurityDescriptor: PSECURITY_DESCRIPTOR): DWORD; stdcall; {use localfree to release ppSecurityDescriptor}
function GetNamedSecurityInfoW(pObjectName: PAnsiChar; ObjectType: SE_OBJECT_TYPE;
         SecurityInfo: SECURITY_INFORMATION; ppsidOwner, ppsidGroup: PPSID; ppDacl, ppSacl: PACL;
         var ppSecurityDescriptor: PSECURITY_DESCRIPTOR): DWORD; stdcall; {use localfree to release ppSecurityDescriptor}
function GetNamedSecurityInfo(pObjectName: PAnsiChar; ObjectType: SE_OBJECT_TYPE;
         SecurityInfo: SECURITY_INFORMATION; ppsidOwner, ppsidGroup: PPSID; ppDacl, ppSacl: PACL;
         var ppSecurityDescriptor: PSECURITY_DESCRIPTOR): DWORD; stdcall; {use localfree to release ppSecurityDescriptor}
function GetSecurityInfo(handle: THandle; ObjectType: SE_OBJECT_TYPE;
         SecurityInfo: SECURITY_INFORMATION; ppsidOwner, ppsidGroup: PPSID; ppDacl, ppSacl: PACL;
         var ppSecurityDescriptor: PPSECURITY_DESCRIPTOR): DWORD; stdcall; {use localfree to release ppSecurityDescriptor}

function SetNamedSecurityInfoA(pObjectName: PAnsiChar; ObjectType: SE_OBJECT_TYPE;
         SecurityInfo: SECURITY_INFORMATION; ppsidOwner, ppsidGroup: PPSID;
         ppDacl, ppSacl: PACL): DWORD; stdcall;
function SetNamedSecurityInfoW(pObjectName: PAnsiChar; ObjectType: SE_OBJECT_TYPE;
         SecurityInfo: SECURITY_INFORMATION; ppsidOwner, ppsidGroup: PPSID;
         ppDacl, ppSacl: PACL): DWORD; stdcall;
function SetNamedSecurityInfo(pObjectName: PAnsiChar; ObjectType: SE_OBJECT_TYPE;
         SecurityInfo: SECURITY_INFORMATION; ppsidOwner, ppsidGroup: PPSID;
         ppDacl, ppSacl: PACL): DWORD; stdcall;

function SetSecurityInfo(handle: THandle; ObjectType: SE_OBJECT_TYPE;
         SecurityInfo: SECURITY_INFORMATION; ppsidOwner, ppsidGroup: PPSID;
         ppDacl, ppSacl: PACL): DWORD; stdcall;

//----------------------------------------------------------------------------
// The following API are provided for trusted servers to use to
// implement access control on their own objects.
//----------------------------------------------------------------------------

function BuildSecurityDescriptorA(pOwner, pGroup: PTRUSTEE_A; cCountOfAccessEntries: ULONG;
         pListOfAccessEntries: PEXPLICIT_ACCESS_A; cCountOfAuditEntries: ULONG;
         pListOfAuditEntries: PEXPLICIT_ACCESS_A; pOldSD: PSECURITY_DESCRIPTOR;
         var pSizeNewSD: ULONG; var pNewSD: SECURITY_DESCRIPTOR): DWORD; stdcall; {use localfree to release pNewSD}
function BuildSecurityDescriptorW(pOwner, pGroup: PTRUSTEE_W; cCountOfAccessEntries: ULONG;
         pListOfAccessEntries: PEXPLICIT_ACCESS_W; cCountOfAuditEntries: ULONG;
         pListOfAuditEntries: PEXPLICIT_ACCESS_W; pOldSD: PSECURITY_DESCRIPTOR;
         var pSizeNewSD: ULONG; var pNewSD: SECURITY_DESCRIPTOR): DWORD; stdcall; {use localfree to release pNewSD}
function BuildSecurityDescriptor(pOwner, pGroup: PTRUSTEE_; cCountOfAccessEntries: ULONG;
         pListOfAccessEntries: PEXPLICIT_ACCESS_; cCountOfAuditEntries: ULONG;
         pListOfAuditEntries: PEXPLICIT_ACCESS_; pOldSD: PSECURITY_DESCRIPTOR;
         var pSizeNewSD: ULONG; var pNewSD: SECURITY_DESCRIPTOR): DWORD; stdcall; {use localfree to release pNewSD}

function LookupSecurityDescriptorPartsA(pOwner, pGroup: PTRUSTEE_A; cCountOfAccessEntries: PULONG;
         pListOfAccessEntries: PEXPLICIT_ACCESS_A; cCountOfAuditEntries: PULONG;
         pListOfAuditEntries: PEXPLICIT_ACCESS_A; var pSD: SECURITY_DESCRIPTOR): DWORD; stdcall;
function LookupSecurityDescriptorPartsW(pOwner, pGroup: PTRUSTEE_W; cCountOfAccessEntries: PULONG;
         pListOfAccessEntries: PEXPLICIT_ACCESS_W; cCountOfAuditEntries: PULONG;
         pListOfAuditEntries: PEXPLICIT_ACCESS_W; var pSD: SECURITY_DESCRIPTOR): DWORD; stdcall;
function LookupSecurityDescriptorParts(pOwner, pGroup: PTRUSTEE_; cCountOfAccessEntries: PULONG;
         pListOfAccessEntries: PEXPLICIT_ACCESS_; cCountOfAuditEntries: PULONG;
         pListOfAuditEntries: PEXPLICIT_ACCESS_; var pSD: SECURITY_DESCRIPTOR): DWORD; stdcall;

//----------------------------------------------------------------------------
// The following helper API are provided for building
// access control structures.
//----------------------------------------------------------------------------

procedure BuildExplicitAccessWithNameA(pExplicitAccess: PEXPLICIT_ACCESS_A;
          pTrusteeName: PAnsiChar; AccessPermissions: DWORD; AccessMode: ACCESS_MODE;
          Ineritance: DWORD); stdcall;
procedure BuildExplicitAccessWithNameW(pExplicitAccess: PEXPLICIT_ACCESS_W;
          pTrusteeName: PAnsiChar; AccessPermissions: DWORD; AccessMode: ACCESS_MODE;
          Ineritance: DWORD); stdcall;
procedure BuildExplicitAccessWithName(pExplicitAccess: PEXPLICIT_ACCESS_;
          pTrusteeName: PAnsiChar; AccessPermissions: DWORD; AccessMode: ACCESS_MODE;
          Ineritance: DWORD); stdcall;

procedure BuildImpersonateExplicitAccessWithNameA(pExplicitAccess: PEXPLICIT_ACCESS_A;
          pTrusteeName: PAnsiChar; pTrustee: PTRUSTEE_A; AccessPermissions: DWORD;
          AccessMode: ACCESS_MODE; Inheritance: DWORD); stdcall; {obsolete}
procedure BuildImpersonateExplicitAccessWithNameW(pExplicitAccess: PEXPLICIT_ACCESS_W;
          pTrusteeName: PAnsiChar; pTrustee: PTRUSTEE_W; AccessPermissions: DWORD;
          AccessMode: ACCESS_MODE; Inheritance: DWORD); stdcall; {obsolete}
procedure BuildImpersonateExplicitAccessWithName(pExplicitAccess: PEXPLICIT_ACCESS_;
          pTrusteeName: PAnsiChar; pTrustee: PTRUSTEE_; AccessPermissions: DWORD;
          AccessMode: ACCESS_MODE; Inheritance: DWORD); stdcall; {obsolete}

procedure BuildTrusteeWithNameA(pTrustee: PTRUSTEE_A; pName: PAnsiChar); stdcall;
procedure BuildTrusteeWithNameW(pTrustee: PTRUSTEE_W; pName: PAnsiChar); stdcall;
procedure BuildTrusteeWithName(pTrustee: PTRUSTEE_; pName: PAnsiChar); stdcall;

procedure BuildImpersonateTrusteeA(pTrustee: PTRUSTEE_A; pImpersonateTrustee: PTRUSTEE_A); stdcall; {obsolete}
procedure BuildImpersonateTrusteeW(pTrustee: PTRUSTEE_W; pImpersonateTrustee: PTRUSTEE_W); stdcall; {obsolete}
procedure BuildImpersonateTrustee(pTrustee: PTRUSTEE_; pImpersonateTrustee: PTRUSTEE_); stdcall; {obsolete}

procedure BuildTrusteeWithSidA(pTrustee: PTRUSTEE_A; pSidIn: PSID); stdcall;
procedure BuildTrusteeWithSidW(pTrustee: PTRUSTEE_W; pSidIn: PSID); stdcall;
procedure BuildTrusteeWithSid(pTrustee: PTRUSTEE_; pSidIn: PSID); stdcall;

function GetTrusteeNameA(var pTrustee: TRUSTEE_A): PAnsiChar; stdcall;
function GetTrusteeNameW(var pTrustee: TRUSTEE_W): PAnsiChar; stdcall;
function GetTrusteeName(var pTrustee: TRUSTEE_): PAnsiChar; stdcall;

function GetTrusteeTypeA(var pTrustee: TRUSTEE_A): TRUSTEE_TYPE; stdcall;
function GetTrusteeTypeW(var pTrustee: TRUSTEE_W): TRUSTEE_TYPE; stdcall;
function GetTrusteeType(var pTrustee: TRUSTEE_): TRUSTEE_TYPE; stdcall;

function GetTrusteeFormA(var pTrustee: TRUSTEE_A): TRUSTEE_FORM; stdcall;
function GetTrusteeFormW(var pTrustee: TRUSTEE_W): TRUSTEE_FORM; stdcall;
function GetTrusteeForm(var pTrustee: TRUSTEE_): TRUSTEE_FORM; stdcall;

function GetMultipleTrusteeOperationA(pTrustee: PTRUSTEE_A): MULTIPLE_TRUSTEE_OPERATION; stdcall; {obsolete}
function GetMultipleTrusteeOperationW(pTrustee: PTRUSTEE_W): MULTIPLE_TRUSTEE_OPERATION; stdcall; {obsolete}
function GetMultipleTrusteeOperation(pTrustee: PTRUSTEE_): MULTIPLE_TRUSTEE_OPERATION; stdcall; {obsolete}

function GetMultipleTrusteeA(pTrustee: PTrustee_A): PTRUSTEE_A; stdcall; {obsolete}
function GetMultipleTrusteeW(pTrustee: PTrustee_W): PTRUSTEE_W; stdcall; {obsolete}
function GetMultipleTrustee(pTrustee: PTrustee_): PTRUSTEE_; stdcall; {obsolete}

implementation

const
  ModName = 'ACLAPI.DLL';

procedure BuildExplicitAccessWithNameA;  external ModName name 'BuildExplicitAccessWithNameA';
{$EXTERNALSYM BuildExplicitAccessWithNameA}
procedure BuildExplicitAccessWithNameW;  external ModName name 'BuildExplicitAccessWithNameW';
{$EXTERNALSYM BuildExplicitAccessWithNameW}
procedure BuildExplicitAccessWithName;  external ModName name 'BuildExplicitAccessWithNameA';
{$EXTERNALSYM BuildExplicitAccessWithName}
procedure BuildImpersonateExplicitAccessWithNameA; external ModName name 'BuildImpersonateExplicitAccessWithNameA';
{$EXTERNALSYM BuildImpersonateExplicitAccessWithNameA}
procedure BuildImpersonateExplicitAccessWithNameW; external ModName name 'BuildImpersonateExplicitAccessWithNameW';
{$EXTERNALSYM BuildImpersonateExplicitAccessWithNameW}
procedure BuildImpersonateExplicitAccessWithName; external ModName name 'BuildImpersonateExplicitAccessWithNameA';
{$EXTERNALSYM BuildImpersonateExplicitAccessWithName}
procedure BuildImpersonateTrusteeA;      external ModName name 'BuildImpersonateTrusteeA';
{$EXTERNALSYM BuildImpersonateTrusteeA}
procedure BuildImpersonateTrusteeW;      external ModName name 'BuildImpersonateTrusteeW';
{$EXTERNALSYM BuildImpersonateTrusteeW}
procedure BuildImpersonateTrustee;      external ModName name 'BuildImpersonateTrusteeA';
{$EXTERNALSYM BuildImpersonateTrustee}
function BuildSecurityDescriptorA;      external ModName name 'BuildSecurityDescriptorA';
{$EXTERNALSYM BuildSecurityDescriptorA}
function BuildSecurityDescriptorW;      external ModName name 'BuildSecurityDescriptorW';
{$EXTERNALSYM BuildSecurityDescriptorW}
function BuildSecurityDescriptor;      external ModName name 'BuildSecurityDescriptorA';
{$EXTERNALSYM BuildSecurityDescriptor}
procedure BuildTrusteeWithNameA;         external ModName name 'BuildTrusteeWithNameA';
{$EXTERNALSYM BuildTrusteeWithNameA}
procedure BuildTrusteeWithNameW;         external ModName name 'BuildTrusteeWithNameW';
{$EXTERNALSYM BuildTrusteeWithNameW}
procedure BuildTrusteeWithName;         external ModName name 'BuildTrusteeWithNameA';
{$EXTERNALSYM BuildTrusteeWithName}
procedure BuildTrusteeWithSidA;          external ModName name 'BuildTrusteeWithSidA';
{$EXTERNALSYM BuildTrusteeWithSidA}
procedure BuildTrusteeWithSidW;          external ModName name 'BuildTrusteeWithSidW';
{$EXTERNALSYM BuildTrusteeWithSidW}
procedure BuildTrusteeWithSid;          external ModName name 'BuildTrusteeWithSidA';
{$EXTERNALSYM BuildTrusteeWithSid}
function GetAuditedPermissionsFromAclA; external ModName name 'GetAuditedPermissionsFromAclA';
{$EXTERNALSYM GetAuditedPermissionsFromAclA}
function GetAuditedPermissionsFromAclW; external ModName name 'GetAuditedPermissionsFromAclW';
{$EXTERNALSYM GetAuditedPermissionsFromAclW}
function GetAuditedPermissionsFromAcl; external ModName name 'GetAuditedPermissionsFromAclA';
{$EXTERNALSYM GetAuditedPermissionsFromAcl}
function GetEffectiveRightsFromAclA;    external ModName name 'GetEffectiveRightsFromAclA';
{$EXTERNALSYM GetEffectiveRightsFromAclA}
function GetEffectiveRightsFromAclW;    external ModName name 'GetEffectiveRightsFromAclW';
{$EXTERNALSYM GetEffectiveRightsFromAclW}
function GetEffectiveRightsFromAcl;    external ModName name 'GetEffectiveRightsFromAclA';
{$EXTERNALSYM GetEffectiveRightsFromAcl}
function GetExplicitEntriesFromAclA;    external ModName name 'GetExplicitEntriesFromAclA';
{$EXTERNALSYM GetExplicitEntriesFromAclA}
function GetExplicitEntriesFromAclW;    external ModName name 'GetExplicitEntriesFromAclW';
{$EXTERNALSYM GetExplicitEntriesFromAclW}
function GetExplicitEntriesFromAcl;    external ModName name 'GetExplicitEntriesFromAclA';
{$EXTERNALSYM GetExplicitEntriesFromAcl}
function GetMultipleTrusteeOperationA;  external ModName name 'GetMultipleTrusteeOperationA';
{$EXTERNALSYM GetMultipleTrusteeOperationA}
function GetMultipleTrusteeOperationW;  external ModName name 'GetMultipleTrusteeOperationW';
{$EXTERNALSYM GetMultipleTrusteeOperationW}
function GetMultipleTrusteeOperation;  external ModName name 'GetMultipleTrusteeOperationA';
{$EXTERNALSYM GetMultipleTrusteeOperation}
function GetMultipleTrusteeA;           external ModName name 'GetMultipleTrusteeA';
{$EXTERNALSYM GetMultipleTrusteeA}
function GetMultipleTrusteeW;           external ModName name 'GetMultipleTrusteeW';
{$EXTERNALSYM GetMultipleTrusteeW}
function GetMultipleTrustee;           external ModName name 'GetMultipleTrusteeA';
{$EXTERNALSYM GetMultipleTrustee}
function GetNamedSecurityInfoA;         external ModName name 'GetNamedSecurityInfoA';
{$EXTERNALSYM GetNamedSecurityInfoA}
function GetNamedSecurityInfoW;         external ModName name 'GetNamedSecurityInfoW';
{$EXTERNALSYM GetNamedSecurityInfoW}
function GetNamedSecurityInfo;         external ModName name 'GetNamedSecurityInfoA';
{$EXTERNALSYM GetNamedSecurityInfo}
function GetSecurityInfo;               external ModName name 'GetSecurityInfo';
{$EXTERNALSYM GetSecurityInfo}
function GetTrusteeFormA;               external ModName name 'GetTrusteeFormA';
{$EXTERNALSYM GetTrusteeFormA}
function GetTrusteeFormW;               external ModName name 'GetTrusteeFormW';
{$EXTERNALSYM GetTrusteeFormW}
function GetTrusteeForm;               external ModName name 'GetTrusteeFormA';
{$EXTERNALSYM GetTrusteeForm}
function GetTrusteeNameA;               external ModName name 'GetTrusteeNameA';
{$EXTERNALSYM GetTrusteeNameA}
function GetTrusteeNameW;               external ModName name 'GetTrusteeNameW';
{$EXTERNALSYM GetTrusteeNameW}
function GetTrusteeName;               external ModName name 'GetTrusteeNameA';
{$EXTERNALSYM GetTrusteeName}
function GetTrusteeTypeA;               external ModName name 'GetTrusteeTypeA';
{$EXTERNALSYM GetTrusteeTypeA}
function GetTrusteeTypeW;               external ModName name 'GetTrusteeTypeW';
{$EXTERNALSYM GetTrusteeTypeW}
function GetTrusteeType;               external ModName name 'GetTrusteeTypeA';
{$EXTERNALSYM GetTrusteeType}
function LookupSecurityDescriptorPartsA; external ModName name 'LookupSecurityDescriptorPartsA';
{$EXTERNALSYM LookupSecurityDescriptorPartsA}
function LookupSecurityDescriptorPartsW; external ModName name 'LookupSecurityDescriptorPartsW';
{$EXTERNALSYM LookupSecurityDescriptorPartsW}
function LookupSecurityDescriptorParts; external ModName name 'LookupSecurityDescriptorPartsA';
{$EXTERNALSYM LookupSecurityDescriptorParts}
function SetEntriesInAclA;              external ModName name 'SetEntriesInAclA';
{$EXTERNALSYM SetEntriesInAclA}
function SetEntriesInAclW;              external ModName name 'SetEntriesInAclW';
{$EXTERNALSYM SetEntriesInAclW}
function SetEntriesInAcl;              external ModName name 'SetEntriesInAclA';
{$EXTERNALSYM SetEntriesInAcl}
function SetNamedSecurityInfoA;         external ModName name 'SetNamedSecurityInfoA';
{$EXTERNALSYM SetNamedSecurityInfoA}
function SetNamedSecurityInfoW;         external ModName name 'SetNamedSecurityInfoW';
{$EXTERNALSYM SetNamedSecurityInfoW}
function SetNamedSecurityInfo;         external ModName name 'SetNamedSecurityInfoA';
{$EXTERNALSYM SetNamedSecurityInfo}
function SetSecurityInfo;               external ModName name 'SetSecurityInfo';
{$EXTERNALSYM SetSecurityInfo}

end.


