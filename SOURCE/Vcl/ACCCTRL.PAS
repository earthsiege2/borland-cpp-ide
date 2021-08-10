
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

unit AccCtrl;

{$WEAKPACKAGEUNIT}

interface

(*$HPPEMIT '#include <accCtrl.h>' *)

uses
  Windows;

{ Definition: TRUSTEE_TYPE }
{ This enumerated type specifies the type of trustee account for the trustee }
{ returned by the API described in this document. }
{ TRUSTEE_IS_UNKNOWN - The trustee is an unknown, but not necessarily invalid }
{                      type.  This field is not validated on input to the APIs }
{                      that take Trustees. }
{ TRUSTEE_IS_USER      The trustee account is a user account. }
{ TRUSTEE_IS_GROUP     The trustee account is a group account. }

type
  TRUSTEE_TYPE = ( 
    TRUSTEE_IS_UNKNOWN,
    TRUSTEE_IS_USER,
    TRUSTEE_IS_GROUP,
    TRUSTEE_IS_DOMAIN,
    TRUSTEE_IS_ALIAS,
    TRUSTEE_IS_WELL_KNOWN_GROUP,
    TRUSTEE_IS_DELETED,
    TRUSTEE_IS_INVALID
  );
  {$EXTERNALSYM TRUSTEE_TYPE}
  
{ Definition: TRUSTEE_FORM }
{ This enumerated type specifies the form the trustee identifier is in for a }
{ particular trustee. }
{ TRUSTEE_IS_SID       The trustee is identified with a SID rather than with a name. }
{ TRUSTEE_IS_NAME      The trustee is identified with a name. }

  TRUSTEE_FORM = (
    TRUSTEE_IS_SID,
    TRUSTEE_IS_NAME,
    TRUSTEE_BAD_FORM
  );
  {$EXTERNALSYM TRUSTEE_FORM}

{ Definition: MULTIPLE_TRUSTEE_OPERATION }
{ If the trustee is a multiple trustee, this enumerated type specifies the type. }
{ TRUSTEE_IS_IMPERSONATE       The trustee is an impersonate trustee and the multiple }
{                          trustee field in the trustee points to another trustee }
{                          that is a trustee for the server that will be doing the }
{                          impersonation. }

  MULTIPLE_TRUSTEE_OPERATION = ( 
    NO_MULTIPLE_TRUSTEE,
    TRUSTEE_IS_IMPERSONATE
  );
  {$EXTERNALSYM MULTIPLE_TRUSTEE_OPERATION}

{ Definition: TRUSTEE }
{ This structure is used to pass account information into and out of the system }
{ using the API defined in this document. }
{ PMultipleTrustee     - if NON-NULL, points to another trustee structure, as }
{                    defined by the multiple trustee operation field. }
{ MultipleTrusteeOperation - Defines the multiple trustee operation/type. }
{ TrusteeForm - defines if the trustee is defined by name or SID. }
{ TrusteeType - defines if the trustee type is unknown, a user or a group. }
{ PwcsName     - points to the trustee name or the trustee SID. }

  P_TRUSTEE_A = ^_TRUSTEE_A; 
  {$EXTERNALSYM P_TRUSTEE_A}
  _TRUSTEE_A = packed record
    pMultipleTrustee: P_TRUSTEE_A;
    MultipleTrusteeOperation: MULTIPLE_TRUSTEE_OPERATION;
    TrusteeForm: TRUSTEE_FORM;
    TrusteeType: TRUSTEE_TYPE;
    ptstrName: PAnsiChar;
  end;
  {$EXTERNALSYM _TRUSTEE_A}
  P_TRUSTEE_W = ^_TRUSTEE_W; 
  {$EXTERNALSYM P_TRUSTEE_W}
  _TRUSTEE_W = packed record
    pMultipleTrustee: P_TRUSTEE_W;
    MultipleTrusteeOperation: MULTIPLE_TRUSTEE_OPERATION;
    TrusteeForm: TRUSTEE_FORM;
    TrusteeType: TRUSTEE_TYPE;
    ptstrName: PAnsiChar;
  end;
  {$EXTERNALSYM _TRUSTEE_W}
  P_TRUSTEE_ = P_TRUSTEE_A;
  TRUSTEEA = _TRUSTEE_A;
  {$EXTERNALSYM TRUSTEEA}
  TRUSTEEW = _TRUSTEE_W;
  {$EXTERNALSYM TRUSTEEW}
  TRUSTEE = TRUSTEEA;
  PTRUSTEEA = ^TRUSTEEA;
  {$EXTERNALSYM PTRUSTEEA}
  PTRUSTEEW = ^TRUSTEEW;
  {$EXTERNALSYM PTRUSTEEW}
  PTRUSTEE = PTRUSTEEA;
  TRUSTEE_A = TRUSTEEA;
  {$EXTERNALSYM TRUSTEE_A}
  TRUSTEE_W = TRUSTEEW;
  {$EXTERNALSYM TRUSTEE_W}
  TRUSTEE_ = TRUSTEE_A;
  PTRUSTEE_A = PTRUSTEEA;
  {$EXTERNALSYM PTRUSTEE_A}
  PTRUSTEE_W = PTRUSTEEW;
  {$EXTERNALSYM PTRUSTEE_W}
  PTRUSTEE_ = PTRUSTEE_A;

{ Definition: ACCESS_MODE }
{ This enumerated type specifies how permissions are (requested)/to be applied }
{  for the trustee by the access control entry.  On input this field can by any }
{  of the values, although it is not meaningful to mix access control and audit }
{  control entries.  On output this field will be either SET_ACCESS, DENY_ACCESS, }
{ SET_AUDIT_SUCCESS, SET_AUDIT_FAILURE. }
{ The following descriptions define how this type effects an explicit access }
{ request to apply access permissions to an object. }
{ GRANT_ACCESS - The trustee will have at least the requested permissions upon }
{                successful completion of the command. (If the trustee has }
{                additional permissions they will not be removed). }
{ SET_ACCESS - The trustee will have exactly the requested permissions upon }
{              successful completion of the command. }
{ DENY_ACCESS - The trustee will be denied the specified permissions. }
{ REVOKE_ACCESS - Any explicit access rights the trustee has will be revoked. }
{ SET_AUDIT_SUCCESS - The trustee will be audited for successful opens of the }
{                     object using the requested permissions. }
{ SET_AUDIT_FAILURE - The trustee will be audited for failed opens of the object }
{                     using the requested permissions. }


  ACCESS_MODE = ( 
    NOT_USED_ACCESS,
    GRANT_ACCESS,
    SET_ACCESS,
    DENY_ACCESS,
    REVOKE_ACCESS,
    SET_AUDIT_SUCCESS,
    SET_AUDIT_FAILURE
  );
  {$EXTERNALSYM ACCESS_MODE}

{ Definition: Inheritance flags }
{ These bit masks are provided to allow simple application of inheritance in }
{ explicit access requests on containers. }
{ NO_INHERITANCE       The specific access permissions will only be applied to }
{                  the container, and will not be inherited by objects created }
{                  within the container. }
{ SUB_CONTAINERS_ONLY_INHERIT  The specific access permissions will be inherited }
{                              and applied to sub containers created within the }
{                              container, and will be applied to the container }
{                              itself. }
{ SUB_OBJECTS_ONLY_INHERIT     The specific access permissions will only be inherited }
{                              by objects created within the specific container. }
{                              The access permissions will not be applied to the }
{                              container itself. }
{ SUB_CONTAINERS_AND_OBJECTS_INHERIT   The specific access permissions will be }
{                                      inherited by containers created within the }
{                                      specific container, will be applied to }
{                                      objects created within the container, but }
{                                      will not be applied to the container itself. }

const
  NO_INHERITANCE                          = $0; 
  {$EXTERNALSYM NO_INHERITANCE}
  SUB_OBJECTS_ONLY_INHERIT                = $1;
  {$EXTERNALSYM SUB_OBJECTS_ONLY_INHERIT}
  SUB_CONTAINERS_ONLY_INHERIT             = $2;
  {$EXTERNALSYM SUB_CONTAINERS_ONLY_INHERIT}
  SUB_CONTAINERS_AND_OBJECTS_INHERIT      = $3;
  {$EXTERNALSYM SUB_CONTAINERS_AND_OBJECTS_INHERIT}
  INHERIT_NO_PROPAGATE                    = $4;
  {$EXTERNALSYM INHERIT_NO_PROPAGATE}
  INHERIT_ONLY                            = $8;
  {$EXTERNALSYM INHERIT_ONLY}

{ Informational bit that is returned }

  INHERITED_ACCESS_ENTRY                  = $10; 
  {$EXTERNALSYM INHERITED_ACCESS_ENTRY}

{ Informational bit that tells where a node was inherited from.  Valid only }
{ for NT 5 APIs }

  INHERITED_PARENT                        = $10000000; 
  {$EXTERNALSYM INHERITED_PARENT}
  INHERITED_GRANDPARENT                   = $20000000;
  {$EXTERNALSYM INHERITED_GRANDPARENT}

{ Definition: }
{ This enumerated type defines the objects supported by the get/set API within }
{ this document.  See section 3.1, Object Types for a detailed definition of the }
{ supported object types, and their name formats. }

type
  SE_OBJECT_TYPE = ( 
    SE_UNKNOWN_OBJECT_TYPE,
    SE_FILE_OBJECT,
    SE_SERVICE,
    SE_PRINTER,
    SE_REGISTRY_KEY,
    SE_LMSHARE,
    SE_KERNEL_OBJECT,
    SE_WINDOW_OBJECT,
    SE_DS_OBJECT,
    SE_DS_OBJECT_ALL,
    SE_PROVIDER_DEFINED_OBJECT,
    SE_WMIGUID_OBJECT
  );
  {$EXTERNALSYM SE_OBJECT_TYPE}

{ Definition: EXPLICIT_ACCESS }
{ This structure is used to pass access control entry information into and out }
{ of the system using the API defined in this document. }
{ grfAccessPermissions - This contains the access permissions to assign for the }
{                     trustee.  It is in the form of an NT access mask. }
{ grfAccessMode - This field defines how the permissions are to be applied for }
{                 the trustee. }
{ grfInheritance - For containers, this field defines how the access control }
{                  entry is/(is requested) to be inherited on }
{                  objects/sub-containers created within the container. }
{ Trustee - This field contains the definition of the trustee account the }
{           explicit access applies to. }

  PEXPLICIT_ACCESS_A = ^EXPLICIT_ACCESS_A;
  {$EXTERNALSYM PEXPLICIT_ACCESS_A}
  EXPLICIT_ACCESS_A = packed record
    grfAccessPermissions: DWORD;
    grfAccessMode: ACCESS_MODE;
    grfInheritance: DWORD;
    Trustee: TRUSTEE_A;
  end;
  {$EXTERNALSYM EXPLICIT_ACCESS_A}
  PEXPLICIT_ACCESS_W = ^EXPLICIT_ACCESS_W;
  {$EXTERNALSYM PEXPLICIT_ACCESS_W}
  EXPLICIT_ACCESS_W = packed record
    grfAccessPermissions: DWORD;
    grfAccessMode: ACCESS_MODE;
    grfInheritance: DWORD;
    Trustee: TRUSTEE_W;
  end;
  {$EXTERNALSYM EXPLICIT_ACCESS_W}
  PEXPLICIT_ACCESS_ = PEXPLICIT_ACCESS_A;
  EXPLICIT_ACCESSA = EXPLICIT_ACCESS_A;
  {$EXTERNALSYM EXPLICIT_ACCESSA}
  EXPLICIT_ACCESSW = EXPLICIT_ACCESS_W;
  {$EXTERNALSYM EXPLICIT_ACCESSW}
  EXPLICIT_ACCESS = EXPLICIT_ACCESSA;
  PEXPLICIT_ACCESSA = ^EXPLICIT_ACCESS_A;
  {$EXTERNALSYM PEXPLICIT_ACCESSA}
  PEXPLICIT_ACCESSW = ^EXPLICIT_ACCESS_W;
  {$EXTERNALSYM PEXPLICIT_ACCESSW}
  PEXPLICIT_ACCESS = PEXPLICIT_ACCESSA;

{ ---------------------------------------------------------------------------- }

{                                  NT5 APIs }

{ ---------------------------------------------------------------------------- }

{ Default provider }

const
  ACCCTRL_DEFAULT_PROVIDERA       = 'Windows NT Access Provider';
  {$EXTERNALSYM ACCCTRL_DEFAULT_PROVIDERA}
  ACCCTRL_DEFAULT_PROVIDERW       = 'Windows NT Access Provider';
  {$EXTERNALSYM ACCCTRL_DEFAULT_PROVIDERW}
  ACCCTRL_DEFAULT_PROVIDER = ACCCTRL_DEFAULT_PROVIDERA;

{ / Access rights }

type
  ACCESS_RIGHTS = ULONG; 
  {$EXTERNALSYM ACCESS_RIGHTS}
  PACCESS_RIGHTS = ^ACCESS_RIGHTS;
  {$EXTERNALSYM PACCESS_RIGHTS}

{ Inheritance flags }

  INHERIT_FLAGS = ULONG; 
  {$EXTERNALSYM INHERIT_FLAGS}
  PINHERIT_FLAGS = ^INHERIT_FLAGS;
  {$EXTERNALSYM PINHERIT_FLAGS}

{ Access / Audit structures }

  PACTRL_ACCESS_ENTRYA = ^ACTRL_ACCESS_ENTRYA;
  {$EXTERNALSYM PACTRL_ACCESS_ENTRYA}
  ACTRL_ACCESS_ENTRYA = packed record
    Trustee: TRUSTEE_A;
    fAccessFlags: ULONG;
    Access: ACCESS_RIGHTS;
    ProvSpecificAccess: ACCESS_RIGHTS;
    Inheritance: INHERIT_FLAGS;
    lpInheritProperty: PAnsiChar;
  end;
  {$EXTERNALSYM ACTRL_ACCESS_ENTRYA}
  PACTRL_ACCESS_ENTRYW = ^ACTRL_ACCESS_ENTRYW;
  {$EXTERNALSYM PACTRL_ACCESS_ENTRYW}
  ACTRL_ACCESS_ENTRYW = packed record
    Trustee: TRUSTEE_W;
    fAccessFlags: ULONG;
    Access: ACCESS_RIGHTS;
    ProvSpecificAccess: ACCESS_RIGHTS;
    Inheritance: INHERIT_FLAGS;
    lpInheritProperty: PAnsiChar;
  end;
  {$EXTERNALSYM ACTRL_ACCESS_ENTRYW}
  PACTRL_ACCESS_ENTRY = PACTRL_ACCESS_ENTRYA;

  PACTRL_ACCESS_ENTRY_LISTA = ^ACTRL_ACCESS_ENTRY_LISTA;
  {$EXTERNALSYM PACTRL_ACCESS_ENTRY_LISTA}
  ACTRL_ACCESS_ENTRY_LISTA = packed record
    cEntries: ULONG;
    pAccessList: ^ACTRL_ACCESS_ENTRYA;
  end;
  {$EXTERNALSYM ACTRL_ACCESS_ENTRY_LISTA}
  PACTRL_ACCESS_ENTRY_LISTW = ^ACTRL_ACCESS_ENTRY_LISTW;
  {$EXTERNALSYM PACTRL_ACCESS_ENTRY_LISTW}
  ACTRL_ACCESS_ENTRY_LISTW = packed record
    cEntries: ULONG;
    pAccessList: ^ACTRL_ACCESS_ENTRYW;
  end;
  {$EXTERNALSYM ACTRL_ACCESS_ENTRY_LISTW}
  PACTRL_ACCESS_ENTRY_LIST = PACTRL_ACCESS_ENTRY_LISTA;

  PACTRL_PROPERTY_ENTRYA = ^ACTRL_PROPERTY_ENTRYA;
  {$EXTERNALSYM PACTRL_PROPERTY_ENTRYA}
  ACTRL_PROPERTY_ENTRYA = packed record
    lpProperty: PAnsiChar;
    pAccessEntryList: PACTRL_ACCESS_ENTRY_LISTA;
    fListFlags: ULONG;
  end;
  {$EXTERNALSYM ACTRL_PROPERTY_ENTRYA}
  PACTRL_PROPERTY_ENTRYW = ^ACTRL_PROPERTY_ENTRYW;
  {$EXTERNALSYM PACTRL_PROPERTY_ENTRYW}
  ACTRL_PROPERTY_ENTRYW = packed record
    lpProperty: PAnsiChar;
    pAccessEntryList: PACTRL_ACCESS_ENTRY_LISTW;
    fListFlags: ULONG;
  end;
  {$EXTERNALSYM ACTRL_PROPERTY_ENTRYW}
  PACTRL_PROPERTY_ENTRY = PACTRL_PROPERTY_ENTRYA;

  PACTRL_ACCESSA = ^ACTRL_ACCESSA;
  {$EXTERNALSYM PACTRL_ACCESSA}
  ACTRL_ACCESSA = packed record
    cEntries: ULONG;
    pPropertyAccessList: PACTRL_PROPERTY_ENTRYA;
  end;
  {$EXTERNALSYM ACTRL_ACCESSA}
  PACTRL_ACCESSW = ^ACTRL_ACCESSW;
  {$EXTERNALSYM PACTRL_ACCESSW}
  ACTRL_ACCESSW = packed record
    cEntries: ULONG;
    pPropertyAccessList: PACTRL_PROPERTY_ENTRYW;
  end;
  {$EXTERNALSYM ACTRL_ACCESSW}
  PACTRL_ACCESS = PACTRL_ACCESSA;
  PPACTRL_ACCESSA = ^PACTRL_ACCESSA;
  {$EXTERNALSYM PPACTRL_ACCESSA}
  PPACTRL_ACCESSW = ^PACTRL_ACCESSW;
  {$EXTERNALSYM PPACTRL_ACCESSW}
  PPACTRL_ACCESS = PPACTRL_ACCESSA;
  ACTRL_AUDITA = ACTRL_ACCESSA;
  {$EXTERNALSYM ACTRL_AUDITA}
  ACTRL_AUDITW = ACTRL_ACCESSW;
  {$EXTERNALSYM ACTRL_AUDITW}
  ACTRL_AUDIT = ACTRL_AUDITA;
  PACTRL_AUDITA = ^ACTRL_AUDITA;
  {$EXTERNALSYM PACTRL_AUDITA}
  PACTRL_AUDITW = ^ACTRL_AUDITW;
  {$EXTERNALSYM PACTRL_AUDITW}
  PACTRL_AUDIT = PACTRL_AUDITA;
  PPACTRL_AUDITA = ^PACTRL_AUDITA;
  {$EXTERNALSYM PPACTRL_AUDITA}
  PPACTRL_AUDITW = ^PACTRL_AUDITW;
  {$EXTERNALSYM PPACTRL_AUDITW}
  PPACTRL_AUDIT = PPACTRL_AUDITA;

{ TRUSTEE_ACCESS flags }

const
  TRUSTEE_ACCESS_ALLOWED          = $00000001; 
  {$EXTERNALSYM TRUSTEE_ACCESS_ALLOWED}
  TRUSTEE_ACCESS_READ             = $00000002;
  {$EXTERNALSYM TRUSTEE_ACCESS_READ}
  TRUSTEE_ACCESS_WRITE            = $00000004;
  {$EXTERNALSYM TRUSTEE_ACCESS_WRITE}

  TRUSTEE_ACCESS_EXPLICIT         = $00000001;
  {$EXTERNALSYM TRUSTEE_ACCESS_EXPLICIT}
  TRUSTEE_ACCESS_READ_WRITE       = TRUSTEE_ACCESS_READ or
                                     TRUSTEE_ACCESS_WRITE;
  {$EXTERNALSYM TRUSTEE_ACCESS_READ_WRITE}

  TRUSTEE_ACCESS_ALL              = $FFFFFFFF;
  {$EXTERNALSYM TRUSTEE_ACCESS_ALL}

type
  PTRUSTEE_ACCESSA = ^TRUSTEE_ACCESSA;
  {$EXTERNALSYM PTRUSTEE_ACCESSA}
  TRUSTEE_ACCESSA = packed record
    lpProperty: PAnsiChar;
    Access: ACCESS_RIGHTS;
    fAccessFlags: ULONG;
    fReturnedAccess: ULONG;
  end;
  {$EXTERNALSYM TRUSTEE_ACCESSA}
  PTRUSTEE_ACCESSW = ^TRUSTEE_ACCESSW;
  {$EXTERNALSYM PTRUSTEE_ACCESSW}
  TRUSTEE_ACCESSW = packed record
    lpProperty: PAnsiChar;
    Access: ACCESS_RIGHTS;
    fAccessFlags: ULONG;
    fReturnedAccess: ULONG;
  end;
  {$EXTERNALSYM TRUSTEE_ACCESSW}
  PTRUSTEE_ACCESS = PTRUSTEE_ACCESSA;

{ Generic permission values }

const
  ACTRL_RESERVED              = $00000000;
  {$EXTERNALSYM ACTRL_RESERVED}
  ACTRL_PERM_1                = $00000001;
  {$EXTERNALSYM ACTRL_PERM_1}
  ACTRL_PERM_2                = $00000002;
  {$EXTERNALSYM ACTRL_PERM_2}
  ACTRL_PERM_3                = $00000004;
  {$EXTERNALSYM ACTRL_PERM_3}
  ACTRL_PERM_4                = $00000008;
  {$EXTERNALSYM ACTRL_PERM_4}
  ACTRL_PERM_5                = $00000010;
  {$EXTERNALSYM ACTRL_PERM_5}
  ACTRL_PERM_6                = $00000020;
  {$EXTERNALSYM ACTRL_PERM_6}
  ACTRL_PERM_7                = $00000040;
  {$EXTERNALSYM ACTRL_PERM_7}
  ACTRL_PERM_8                = $00000080;
  {$EXTERNALSYM ACTRL_PERM_8}
  ACTRL_PERM_9                = $00000100;
  {$EXTERNALSYM ACTRL_PERM_9}
  ACTRL_PERM_10               = $00000200;
  {$EXTERNALSYM ACTRL_PERM_10}
  ACTRL_PERM_11               = $00000400;
  {$EXTERNALSYM ACTRL_PERM_11}
  ACTRL_PERM_12               = $00000800;
  {$EXTERNALSYM ACTRL_PERM_12}
  ACTRL_PERM_13               = $00001000;
  {$EXTERNALSYM ACTRL_PERM_13}
  ACTRL_PERM_14               = $00002000;
  {$EXTERNALSYM ACTRL_PERM_14}
  ACTRL_PERM_15               = $00004000;
  {$EXTERNALSYM ACTRL_PERM_15}
  ACTRL_PERM_16               = $00008000;
  {$EXTERNALSYM ACTRL_PERM_16}
  ACTRL_PERM_17               = $00010000;
  {$EXTERNALSYM ACTRL_PERM_17}
  ACTRL_PERM_18               = $00020000;
  {$EXTERNALSYM ACTRL_PERM_18}
  ACTRL_PERM_19               = $00040000;
  {$EXTERNALSYM ACTRL_PERM_19}
  ACTRL_PERM_20               = $00080000;
  {$EXTERNALSYM ACTRL_PERM_20}

{ Access permissions }

  ACTRL_ACCESS_ALLOWED            = $00000001;
  {$EXTERNALSYM ACTRL_ACCESS_ALLOWED}
  ACTRL_ACCESS_DENIED             = $00000002;
  {$EXTERNALSYM ACTRL_ACCESS_DENIED}
  ACTRL_AUDIT_SUCCESS             = $00000004;
  {$EXTERNALSYM ACTRL_AUDIT_SUCCESS}
  ACTRL_AUDIT_FAILURE             = $00000008;
  {$EXTERNALSYM ACTRL_AUDIT_FAILURE}

{ Property list flags }

  ACTRL_ACCESS_PROTECTED          = $00000001;
  {$EXTERNALSYM ACTRL_ACCESS_PROTECTED}

{ Standard and object rights }

  ACTRL_SYSTEM_ACCESS             = $04000000;
  {$EXTERNALSYM ACTRL_SYSTEM_ACCESS}
  ACTRL_DELETE                    = $08000000;
  {$EXTERNALSYM ACTRL_DELETE}
  ACTRL_READ_CONTROL              = $10000000;
  {$EXTERNALSYM ACTRL_READ_CONTROL}
  ACTRL_CHANGE_ACCESS             = $20000000;
  {$EXTERNALSYM ACTRL_CHANGE_ACCESS}
  ACTRL_CHANGE_OWNER              = $40000000;
  {$EXTERNALSYM ACTRL_CHANGE_OWNER}
  ACTRL_SYNCHRONIZE               = $80000000;
  {$EXTERNALSYM ACTRL_SYNCHRONIZE}
  ACTRL_STD_RIGHTS_ALL            = $f8000000;
  {$EXTERNALSYM ACTRL_STD_RIGHTS_ALL}
  ACTRL_STD_RIGHT_REQUIRED        =  ACTRL_STD_RIGHTS_ALL and not ACTRL_SYNCHRONIZE;
  {$EXTERNALSYM ACTRL_STD_RIGHT_REQUIRED}

  ACTRL_DS_OPEN                               = ACTRL_RESERVED;
  {$EXTERNALSYM ACTRL_DS_OPEN}
  ACTRL_DS_CREATE_CHILD                       = ACTRL_PERM_1;
  {$EXTERNALSYM ACTRL_DS_CREATE_CHILD}
  ACTRL_DS_DELETE_CHILD                       = ACTRL_PERM_2;
  {$EXTERNALSYM ACTRL_DS_DELETE_CHILD}
  ACTRL_DS_LIST                               = ACTRL_PERM_3;
  {$EXTERNALSYM ACTRL_DS_LIST}
  ACTRL_DS_SELF                               = ACTRL_PERM_4;
  {$EXTERNALSYM ACTRL_DS_SELF}
  ACTRL_DS_READ_PROP                          = ACTRL_PERM_5;
  {$EXTERNALSYM ACTRL_DS_READ_PROP}
  ACTRL_DS_WRITE_PROP                         = ACTRL_PERM_6;
  {$EXTERNALSYM ACTRL_DS_WRITE_PROP}
  ACTRL_DS_DELETE_TREE                        = ACTRL_PERM_7;
  {$EXTERNALSYM ACTRL_DS_DELETE_TREE}
  ACTRL_DS_LIST_OBJECT                        = ACTRL_PERM_8;
  {$EXTERNALSYM ACTRL_DS_LIST_OBJECT}
  ACTRL_DS_CONTROL_ACCESS                     = ACTRL_PERM_9;
  {$EXTERNALSYM ACTRL_DS_CONTROL_ACCESS}

  ACTRL_FILE_READ                             = ACTRL_PERM_1; 
  {$EXTERNALSYM ACTRL_FILE_READ}
  ACTRL_FILE_WRITE                            = ACTRL_PERM_2;
  {$EXTERNALSYM ACTRL_FILE_WRITE}
  ACTRL_FILE_APPEND                           = ACTRL_PERM_3;
  {$EXTERNALSYM ACTRL_FILE_APPEND}
  ACTRL_FILE_READ_PROP                        = ACTRL_PERM_4;
  {$EXTERNALSYM ACTRL_FILE_READ_PROP}
  ACTRL_FILE_WRITE_PROP                       = ACTRL_PERM_5;
  {$EXTERNALSYM ACTRL_FILE_WRITE_PROP}
  ACTRL_FILE_EXECUTE                          = ACTRL_PERM_6;
  {$EXTERNALSYM ACTRL_FILE_EXECUTE}
  ACTRL_FILE_READ_ATTRIB                      = ACTRL_PERM_8;
  {$EXTERNALSYM ACTRL_FILE_READ_ATTRIB}
  ACTRL_FILE_WRITE_ATTRIB                     = ACTRL_PERM_9;
  {$EXTERNALSYM ACTRL_FILE_WRITE_ATTRIB}
  ACTRL_FILE_CREATE_PIPE                      = ACTRL_PERM_10;
  {$EXTERNALSYM ACTRL_FILE_CREATE_PIPE}
  ACTRL_DIR_LIST                              = ACTRL_PERM_1;
  {$EXTERNALSYM ACTRL_DIR_LIST}
  ACTRL_DIR_CREATE_OBJECT                     = ACTRL_PERM_2;
  {$EXTERNALSYM ACTRL_DIR_CREATE_OBJECT}
  ACTRL_DIR_CREATE_CHILD                      = ACTRL_PERM_3;
  {$EXTERNALSYM ACTRL_DIR_CREATE_CHILD}
  ACTRL_DIR_DELETE_CHILD                      = ACTRL_PERM_7;
  {$EXTERNALSYM ACTRL_DIR_DELETE_CHILD}
  ACTRL_DIR_TRAVERSE                          = ACTRL_PERM_6;
  {$EXTERNALSYM ACTRL_DIR_TRAVERSE}
  ACTRL_KERNEL_TERMINATE                      = ACTRL_PERM_1;
  {$EXTERNALSYM ACTRL_KERNEL_TERMINATE}
  ACTRL_KERNEL_THREAD                         = ACTRL_PERM_2;
  {$EXTERNALSYM ACTRL_KERNEL_THREAD}
  ACTRL_KERNEL_VM                             = ACTRL_PERM_3;
  {$EXTERNALSYM ACTRL_KERNEL_VM}
  ACTRL_KERNEL_VM_READ                        = ACTRL_PERM_4;
  {$EXTERNALSYM ACTRL_KERNEL_VM_READ}
  ACTRL_KERNEL_VM_WRITE                       = ACTRL_PERM_5;
  {$EXTERNALSYM ACTRL_KERNEL_VM_WRITE}
  ACTRL_KERNEL_DUP_HANDLE                     = ACTRL_PERM_6;
  {$EXTERNALSYM ACTRL_KERNEL_DUP_HANDLE}
  ACTRL_KERNEL_PROCESS                        = ACTRL_PERM_7;
  {$EXTERNALSYM ACTRL_KERNEL_PROCESS}
  ACTRL_KERNEL_SET_INFO                       = ACTRL_PERM_8;
  {$EXTERNALSYM ACTRL_KERNEL_SET_INFO}
  ACTRL_KERNEL_GET_INFO                       = ACTRL_PERM_9;
  {$EXTERNALSYM ACTRL_KERNEL_GET_INFO}
  ACTRL_KERNEL_CONTROL                        = ACTRL_PERM_10;
  {$EXTERNALSYM ACTRL_KERNEL_CONTROL}
  ACTRL_KERNEL_ALERT                          = ACTRL_PERM_11;
  {$EXTERNALSYM ACTRL_KERNEL_ALERT}
  ACTRL_KERNEL_GET_CONTEXT                    = ACTRL_PERM_12;
  {$EXTERNALSYM ACTRL_KERNEL_GET_CONTEXT}
  ACTRL_KERNEL_SET_CONTEXT                    = ACTRL_PERM_13;
  {$EXTERNALSYM ACTRL_KERNEL_SET_CONTEXT}
  ACTRL_KERNEL_TOKEN                          = ACTRL_PERM_14;
  {$EXTERNALSYM ACTRL_KERNEL_TOKEN}
  ACTRL_KERNEL_IMPERSONATE                    = ACTRL_PERM_15;
  {$EXTERNALSYM ACTRL_KERNEL_IMPERSONATE}
  ACTRL_KERNEL_DIMPERSONATE                   = ACTRL_PERM_16;
  {$EXTERNALSYM ACTRL_KERNEL_DIMPERSONATE}
  ACTRL_PRINT_SADMIN                          = ACTRL_PERM_1;
  {$EXTERNALSYM ACTRL_PRINT_SADMIN}
  ACTRL_PRINT_SLIST                           = ACTRL_PERM_2;
  {$EXTERNALSYM ACTRL_PRINT_SLIST}
  ACTRL_PRINT_PADMIN                          = ACTRL_PERM_3;
  {$EXTERNALSYM ACTRL_PRINT_PADMIN}
  ACTRL_PRINT_PUSE                            = ACTRL_PERM_4;
  {$EXTERNALSYM ACTRL_PRINT_PUSE}
  ACTRL_PRINT_JADMIN                          = ACTRL_PERM_5;
  {$EXTERNALSYM ACTRL_PRINT_JADMIN}
  ACTRL_SVC_GET_INFO                          = ACTRL_PERM_1;
  {$EXTERNALSYM ACTRL_SVC_GET_INFO}
  ACTRL_SVC_SET_INFO                          = ACTRL_PERM_2;
  {$EXTERNALSYM ACTRL_SVC_SET_INFO}
  ACTRL_SVC_STATUS                            = ACTRL_PERM_3;
  {$EXTERNALSYM ACTRL_SVC_STATUS}
  ACTRL_SVC_LIST                              = ACTRL_PERM_4;
  {$EXTERNALSYM ACTRL_SVC_LIST}
  ACTRL_SVC_START                             = ACTRL_PERM_5;
  {$EXTERNALSYM ACTRL_SVC_START}
  ACTRL_SVC_STOP                              = ACTRL_PERM_6;
  {$EXTERNALSYM ACTRL_SVC_STOP}
  ACTRL_SVC_PAUSE                             = ACTRL_PERM_7;
  {$EXTERNALSYM ACTRL_SVC_PAUSE}
  ACTRL_SVC_INTERROGATE                       = ACTRL_PERM_8;
  {$EXTERNALSYM ACTRL_SVC_INTERROGATE}
  ACTRL_SVC_UCONTROL                          = ACTRL_PERM_9;
  {$EXTERNALSYM ACTRL_SVC_UCONTROL}
  ACTRL_REG_QUERY                             = ACTRL_PERM_1;
  {$EXTERNALSYM ACTRL_REG_QUERY}
  ACTRL_REG_SET                               = ACTRL_PERM_2;
  {$EXTERNALSYM ACTRL_REG_SET}
  ACTRL_REG_CREATE_CHILD                      = ACTRL_PERM_3;
  {$EXTERNALSYM ACTRL_REG_CREATE_CHILD}
  ACTRL_REG_LIST                              = ACTRL_PERM_4;
  {$EXTERNALSYM ACTRL_REG_LIST}
  ACTRL_REG_NOTIFY                            = ACTRL_PERM_5;
  {$EXTERNALSYM ACTRL_REG_NOTIFY}
  ACTRL_REG_LINK                              = ACTRL_PERM_6;
  {$EXTERNALSYM ACTRL_REG_LINK}
  ACTRL_WIN_CLIPBRD                           = ACTRL_PERM_1;
  {$EXTERNALSYM ACTRL_WIN_CLIPBRD}
  ACTRL_WIN_GLOBAL_ATOMS                      = ACTRL_PERM_2;
  {$EXTERNALSYM ACTRL_WIN_GLOBAL_ATOMS}
  ACTRL_WIN_CREATE                            = ACTRL_PERM_3;
  {$EXTERNALSYM ACTRL_WIN_CREATE}
  ACTRL_WIN_LIST_DESK                         = ACTRL_PERM_4;
  {$EXTERNALSYM ACTRL_WIN_LIST_DESK}
  ACTRL_WIN_LIST                              = ACTRL_PERM_5;
  {$EXTERNALSYM ACTRL_WIN_LIST}
  ACTRL_WIN_READ_ATTRIBS                      = ACTRL_PERM_6;
  {$EXTERNALSYM ACTRL_WIN_READ_ATTRIBS}
  ACTRL_WIN_WRITE_ATTRIBS                     = ACTRL_PERM_7;
  {$EXTERNALSYM ACTRL_WIN_WRITE_ATTRIBS}
  ACTRL_WIN_SCREEN                            = ACTRL_PERM_8;
  {$EXTERNALSYM ACTRL_WIN_SCREEN}
  ACTRL_WIN_EXIT                              = ACTRL_PERM_9;
  {$EXTERNALSYM ACTRL_WIN_EXIT}

type
  PACTRL_OVERLAPPED = ^ACTRL_OVERLAPPED;
  {$EXTERNALSYM PACTRL_OVERLAPPED}
  ACTRL_OVERLAPPED = packed record
    case Integer of
      0: (Provider: Pointer; Rsrvd2: ULONG; hEvnt: THandle);
      1: (Reserved1: ULONG; Reserved2: ULONG; hEvent: THandle);
  end;
  {$EXTERNALSYM ACTRL_OVERLAPPED}

  PACTRL_ACCESS_INFOA = ^ACTRL_ACCESS_INFOA;
  {$EXTERNALSYM PACTRL_ACCESS_INFOA}
  ACTRL_ACCESS_INFOA = packed record
    fAccessPermission: ULONG;
    lpAccessPermissionName: PAnsiChar;
  end;
  {$EXTERNALSYM ACTRL_ACCESS_INFOA}
  PACTRL_ACCESS_INFOW = ^ACTRL_ACCESS_INFOW;
  {$EXTERNALSYM PACTRL_ACCESS_INFOW}
  ACTRL_ACCESS_INFOW = packed record
    fAccessPermission: ULONG;
    lpAccessPermissionName: PAnsiChar;
  end;
  {$EXTERNALSYM ACTRL_ACCESS_INFOW}
  PACTRL_ACCESS_INFO = PACTRL_ACCESS_INFOA;
  PPACTRL_ACCESS_INFOA = ^PACTRL_ACCESS_INFOA;
  {$EXTERNALSYM PPACTRL_ACCESS_INFOA}
  PPACTRL_ACCESS_INFOW = ^PACTRL_ACCESS_INFOW;
  {$EXTERNALSYM PPACTRL_ACCESS_INFOW}
  PPACTRL_ACCESS_INFO = PPACTRL_ACCESS_INFOA;

  PACTRL_CONTROL_INFOA = ^ACTRL_CONTROL_INFOA;
  {$EXTERNALSYM PACTRL_CONTROL_INFOA}
  ACTRL_CONTROL_INFOA = packed record
    lpControlId: PAnsiChar;
    lpControlName: PAnsiChar;
  end;
  {$EXTERNALSYM ACTRL_CONTROL_INFOA}
  PACTRL_CONTROL_INFOW = ^ACTRL_CONTROL_INFOW;
  {$EXTERNALSYM PACTRL_CONTROL_INFOW}
  ACTRL_CONTROL_INFOW = packed record
    lpControlId: PAnsiChar;
    lpControlName: PAnsiChar;
  end;
  {$EXTERNALSYM ACTRL_CONTROL_INFOW}
  PACTRL_CONTROL_INFO = PACTRL_CONTROL_INFOA;
  PPACTRL_CONTROL_INFOA = ^PACTRL_CONTROL_INFOA;
  {$EXTERNALSYM PPACTRL_CONTROL_INFOA}
  PPACTRL_CONTROL_INFOW = ^PACTRL_CONTROL_INFOW;
  {$EXTERNALSYM PPACTRL_CONTROL_INFOW}
  PPACTRL_CONTROL_INFO = PPACTRL_CONTROL_INFOA;
const
  ACTRL_ACCESS_NO_OPTIONS                     = $00000000; 
  {$EXTERNALSYM ACTRL_ACCESS_NO_OPTIONS}
  ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES        = $00000001;
  {$EXTERNALSYM ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES}

implementation

end.
