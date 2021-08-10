{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{       SOAP           Support                          }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}
{
  Central registry for interfaces with RTTI and the classes that implement them.
  Classes that are used as parameter types in methods of interfaces are registered
  in a separate registry.
}
unit InvokeRegistry;

{$IFDEF NO_SOAP_RUNTIME}
{ If SOAP components are not packaged }
(*$HPPEMIT '#pragma link "dclsoap.lib"' *)
{$ENDIF}

{$IFDEF MSWINDOWS}
{ SOAP/Windows is currently implemented with WININET }
(*$HPPEMIT '#if defined(__WIN32__)'     *)
(*$HPPEMIT '#pragma link "wininet.lib"' *)
(*$HPPEMIT '#endif'                     *)
{$ENDIF}

interface

uses SysUtils, TypInfo, IntfInfo, Classes, {$IFDEF MSWINDOWS}Windows{$ENDIF}
  {$IFDEF LINUX}Libc{$ENDIF}, XMLSchema;

type

  InvString = WideString;

  TInvokableClass = class(TInterfacedObject)
  public
    constructor Create; virtual;
  end;
  TInvokableClassClass = class of TInvokableClass;

  TDataContext = class;

  { ======================================================================================
    Serialization options apply to remotable classes - i.e. type derived from TRemotable.
    Usually these types simple represent an XML <complextype> with zero or more elements;
    however, the are times when they are really shells for another type.
    For example, if a schema describes a type that returns an array with 'truncated'
    attribute describing whether the data was truncated, you'll need a 'TRemotable-derived'
    type to properly deserialize the data. However, in such a case, the
    'TRemotable-derived' type is really just a shell to house the array and the
    attribute fields. The 'TRemotable-derived' type is not involved in the
    [de]serialization process. It's stealth!

    Serialization options can either be registered for a particular ClassType. Or it can
    be set by an instance of a class itself via TRemotable's FSerializationOptions member.

    NOTE: Currently Serialization options are only for Client usage. i.e. They are used by
    the WSDL importer when creating types from a WSDL. Servers should *NOT* register any
    types with these options as the WSDL publishing logic will ignore all serialization
    options. IOW, these flags are here to adapt the language binding to constructs that don't
    easily map to a native type - like the example of an array with an attribute. Servers,
    don't need to resort to any of these flags since all of a server's needs can be
    mapped to SOAP without use of holder classes.
    ====================================================================================== }
  SerializationOptions  = (xoHolderClass, xoAttributeOnLastMember, xoInlineArrays, xoLiteralParam,
                           xoOption5, xoOption6, xoOption7, xoOption8, xoOption9, xoOptionA,
                           xoOptionB, xoOptionC, xoOptionD, xoOptionE, xoOptionF, xoOptionG,
                           xoOptionH, xoOptionI);
  TSerializationOptions = set of SerializationOptions;

{$M+}
  TRemotable = class
  private
    FDataContext: TDataContext;
    procedure SetDataContext(Value: TDataContext);
  protected
    FSerializationOptions: TSerializationOptions;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    property DataContext: TDataContext read FDataContext write SetDataContext;
    property SerializationOptions: TSerializationOptions read FSerializationOptions;
  end;
{$M-}
  TRemotableXS = class(TRemotable)
  public
    function NativeToXS: WideString; virtual;
    procedure XSToNative(Data: WideString); virtual;
  end;
  PTRemotable = ^TRemotable;
  TRemotableClass = class of TRemotable;
  TRemotableXSClass = class of TRemotableXS;
{$M+}
  { ERemotableException is the base class for handling fault packets with
    information in the <detail> nodes. It's also the base exception thrown
    when no suitable (registered) ERemotableException-derived class is found
    for a particular fault or when there is no <detail> node sent. }
  ERemotableException = class(Exception)
  private
    FFaultActor: WideString;
    FFaultCode: WideString;
    FFaultDetail: WideString;
  public
    constructor CreateRem;  virtual;
    property FaultActor:  WideString read FFaultActor write FFaultActor;
    property FaultCode:   WideString read FFaultCode  write FFaultCode;
    property FaultDetail: WideString read FFaultDetail write FFaultDetail;
  end;
{$M-}
  ERemotableExceptionClass = class of ERemotableException;

  { Used when registering a class factory  - Specify a factory callback
    if you need to control the lifetime of the object - otherwise SOAP
    will create the implementation class using the virtual constructor }
  TCreateInstanceProc = procedure(out obj: TObject);

  InvRegClassEntry = record
    ClassType: TClass;
    Proc: TCreateInstanceProc;
    URI: string;
  end;

  ExtNameMapItem = record
    Name: string;
    ExtName: WideString;
  end;

  MethParamNameMapItem = record
    MethName: string;
    ParamNameMap: array of ExtNameMapItem;
  end;

  { Options that govern how we invokes methods of this interface }
  TIntfInvokeOption = (ioDefault,
                       ioDocument,
                       ioLiteral,
                       ioHasDefaultSOAPAction,
                       ioHasReturnParamNames,
                       ioHasNamespace );
  TIntfInvokeOptions= set of TIntfInvokeOption;

  InvRegIntfEntry = record
    Name: string;                             { Native name of interface    }
    ExtName: Widestring;                      { PortTypeName                }
    UnitName: string;                         { Filename of interface       }
    GUID: TGUID;                              { GUID of interface           }
    Info: PTypeInfo;                          { Typeinfo of interface       }
    DefImpl: TClass;                          { Metaclass of implementation }
    Namespace: Widestring;                    { XML Namespace of type       }
    WSDLEncoding: WideString;                 { Encoding                    }
    Documentation: string;                    { Description of interface    }
    DefaultSOAPAction: string;                { SOAPAction of interface     }
    ReturnParamNames: string;                 { Return Parameter names      }
    InvokeOptions: TIntfInvokeOptions;        { Invoke Options              }
    MethNameMap: array of ExtNameMapItem;             { Renamed methods     }
    MethParamNameMap: array of MethParamNameMapItem;  { Renamed parameters  }
  end;
  TInvRegIntfEntryArray = array of InvRegIntfEntry;

  TInvokableClassRegistry = class(TInterfacedObject)
  private
    FLock: TRTLCriticalSection;
    FRegClasses: array of InvRegClassEntry;
    FRegIntfs: array of InvRegIntfEntry;
    procedure DeleteFromReg(AClass: TClass; Info: PTypeInfo);
  public
    constructor Create;
    destructor Destroy; override;
    { Basic Registration Routines }
    procedure RegisterInterface(Info: PTypeInfo; const Namespace: InvString; const WSDLEncoding: InvString; const Doc: string; const ExtName: InvString); overload;
    procedure RegisterInterface(Info: PTypeInfo; const Namespace: InvString; const WSDLEncoding: InvString; const Doc: string); overload;
    procedure RegisterInterface(Info: PTypeInfo; const Namespace: InvString; const WSDLEncoding: InvString); overload;
    procedure RegisterInterface(Info: PTypeInfo; const Namespace: InvString); overload;
    procedure RegisterInterface(Info: PTypeInfo); overload;
    procedure RegisterExternalMethName(Info: PTypeInfo; InternalName: string; const ExternalName: InvString);
    procedure RegisterExternalParamName(Info: PTypeInfo; MethodName, InternalName: string; const ExternalName: InvString);
    procedure RegisterInvokableClass(AClass: TClass; CreateProc: TCreateInstanceProc); overload;
    procedure RegisterInvokableClass(AClass: TClass); overload;

    { SOAPAction - related API }
    procedure RegisterDefaultSOAPAction(Info: PTypeInfo; const DefSOAPAction: InvString);
    function  GetActionURIOfInfo(const IntfInfo: PTypeInfo; const MethodName: WideString): string;
    function  GetActionURIOfIID(const AGUID: TGUID): string;

    procedure RegisterReturnParamNames(Info: PTypeInfo; const RetParamNames: string);
    function  GetReturnParamNames(const IntfInfo: PTypeInfo): string;

    procedure RegisterInvokeOptions(Info: PTypeInfo; const InvokeOption: TIntfInvokeOption); overload;
    procedure RegisterInvokeOptions(Info: PTypeInfo; const InvokeOptions: TIntfInvokeOptions); overload;

  private
    procedure Lock; virtual;
    procedure UnLock; virtual;

  public
    function  GetNamespaceByGUID(const AGUID: TGUID): string;
    function  GetInfoForURI(const PathURI, ActionURI: string; var ACLass : TClass;  var IntfInfo: PTypeInfo; var AMeth: string): Boolean;
    function  GetIntfInvokeOptions(const IntfInfo: PTypeInfo): TIntfInvokeOptions; overload;
    function  GetIntfInvokeOptions(const AGUID: TGUID): TIntfInvokeOptions; overload;
    procedure GetInterfaceInfoFromName(const UnitName,  IntfName: string; var Info: PTypeInfo; var IID: TGUID);
    function  GetInterfaceTypeInfo(const AGUID: TGUID): Pointer;
    function  GetInvokableObjectFromClass(AClass: TClass): TObject;
    function  GetRegInterfaceEntry(Index: Integer): InvRegIntfEntry;
    procedure GetClassFromIntfInfo(Info: PTypeInfo; var AClass: TClass);
    function  GetInterfaceCount: Integer;
    function  GetInterfaceExternalName(Info: PTypeInfo; Namespace: string; InternalIntfName: string): InvString; overload;
    function  GetInterfaceExternalName(Info: PTypeInfo; Namespace: string): InvString; overload;
    function  GetInterfaceExternalName(Info: PTypeInfo): InvString; overload;
    function  GetWSDLEncoding(Info: PTypeInfo; Namespace: string; InternalIntfName: string): InvString; overload;
    function  GetWSDLEncoding(Info: PTypeInfo; Namespace: string): InvString; overload;
    function  GetWSDLEncoding(Info: PTypeInfo): InvString; overload;
    procedure UnRegisterInterface(Info: PTypeInfo);
    procedure UnRegisterInvokableClass(AClass: TClass);
    function  GetParamExternalName(Info: PTypeInfo;  MethodName, InternalParamName: string): InvString;
    function  GetParamInternalName(Info: PTypeInfo;  MethodName: string; ExternalParamName: InvString): string;
    function  GetMethExternalName(Info: PTypeInfo;  MethodIntName: string): InvString;
    function  GetMethInternalName(Info: PTypeInfo;  MethodExtName: InvString): string;
  end;

  { Classes used to register classes that map from pascal to/from XSD }

  TObjMultiOptions = (ocDefault, ocMultiRef, ocNoMultiRef);
  TRemRegEntry = record
    ClassType: TClass;
    Info: PTypeInfo;
    URI: WideString;
    Name: WideString;
    ExtName: WideString;
    IsScalar: Boolean;
    MultiRefOpt: TObjMultiOptions;
    SerializationOpt: TSerializationOptions;
  end;

  ETypeRegistryException = class(Exception);

  TRemotableTypeRegistry = class
  private
    FAutoRegister: Boolean;
    FLock:    TRTLCriticalSection;
    URIMap:   array of TRemRegEntry;
    function  GetEntry(Info: PTypeInfo; var Found: Boolean; Name: WideString=''): Integer;
    procedure DeleteEntryFromURIMap(Info: PTypeInfo);
    function  GetSimpleBuiltInXSDType(const URI, TypeName: WideString): PTypeInfo;
    function  GetRegisteredClassForBuiltInXSD(const TypeName: WideString): TClass;
  protected
    procedure Lock; virtual;
    procedure UnLock; virtual;
  public
    constructor Create;
    destructor Destroy; override;

    { Remotable class registration }
    procedure RegisterXSClass(AClass: TClass; URI: WideString; Name: WideString; ExtName: WideString; IsScalar: Boolean; MultiRefOpt: TObjMultiOptions); overload;
    procedure RegisterXSClass(AClass: TClass; URI: WideString; Name: WideString; ExtName: WideString; IsScalar: Boolean); overload;
    procedure RegisterXSClass(AClass: TClass; URI: WideString; Name: WideString; ExtName: WideString); overload;
    procedure RegisterXSClass(AClass: TClass; URI: WideString; Name: WideString); overload;
    procedure RegisterXSClass(AClass: TClass; URI: WideString); overload;
    procedure RegisterXSClass(AClass: TClass); overload;

    { TypeInfo registration }
    procedure RegisterXSInfo(Info: PTypeInfo; URI: WideString; Name: WideString; ExtName: WideString); overload;
    procedure RegisterXSInfo(Info: PTypeInfo; URI: WideString; Name: WideString); overload;
    procedure RegisterXSInfo(Info: PTypeInfo; URI: WideString); overload;
    procedure RegisterXSInfo(Info: PTypeInfo); overload;

    { TypeInfo registration via a Holder class }
    procedure RegisterHolderClsMember(ClsTypeInfo: PTypeInfo; URI: WideString = ''; Name: WideString = ''; ExtName: WideString = '');

    { Query routines to conver Native Type to XML name and namespace }
    function  ClassToURI(AClass: TClass; var URI, Name: WideString; var IsScalar: Boolean; tryToRegister: Boolean = True): Boolean;
    function  InfoToURI(Info: PTypeInfo; var URI, Name: WideString; var IsScalar: Boolean; tryToRegister: Boolean = True): Boolean;
    function  TypeInfoToXSD(Info: PTypeInfo; var URI, TypeName: WideString): Boolean;
    procedure GetXSDInfoForClass(Info: PTypeInfo; var URI, TypeName: WideString);

    { Query routines to convert XML name/namespace to Native TypeInfo }
    function  URIToClass(URI, Name: WideString; var IsScalar: Boolean): TClass;
    function  XSDToTypeInfo(URI, TypeName: WideString): PTypeInfo;
    function  URIToInfo(const URI, Name: WideString): PTypeInfo;

    { Query registry information }
    function  GetURICount: Integer;
    function  GetURIMap(Index: Integer): TRemRegEntry; overload;
    function  GetURIMap(Index: Integer; out RegEntry: TRemRegEntry): boolean; overload;

    { Class options }
    function  IsClassScalar(AClass: TClass): Boolean;
    function  ClassOptions(AClass: TClass): TObjMultiOptions;

    { Variant-related conversions }
    function  VariantToInfo(V: Variant; TryAllSchema: Boolean): PTypeInfo;
    function  GetVarTypeFromXSD(URI, TypeName: InvString): TVarType;

    { Serialization options }
    procedure RegisterSerializeOptions(AClass: TClass; SerialOpt: TSerializationOptions);
    function  SerializeOptions(AClass: TClass): TSerializationOptions;

    { Unregister API }
    procedure UnRegisterXSClass(AClass: TClass);
    procedure UnRegisterXSInfo(Info: PTypeInfo);

    { Name mappings: Internal <-> External }
    procedure RegisterExternalPropName(Info: PTypeInfo; InternalName: string; const ExternalName: InvString);
    function  GetExternalPropName(Info: PTypeInfo; InternalName: string): InvString;
    function  GetInternalPropName(Info: PTypeInfo; ExternalName: InvString): string;

    { Flag to automatically register types }
    property AutoRegisterNativeTypes: Boolean read FAutoRegister write FAutoRegister;
  end;

  TRemotableClassRegistry       = TRemotableTypeRegistry;
  TPascalRemotableTypeRegistry  = TRemotableTypeRegistry;
  TPascalRemotableClassRegistry = TRemotableTypeRegistry;

{ Forward ref. structure to satisfy DynamicArray<Type>        }
{ encountered before declaration of Type itself in .HPP file  }
(*$HPPEMIT 'namespace Invokeregistry {'                      *)
(*$HPPEMIT 'struct TDynToClear;'                             *)
(*$HPPEMIT '};'                                              *)
(*$HPPEMIT 'using Invokeregistry::TDynToClear;'              *)

  TDynToClear = record
    P: Pointer;
    Info: PTypeInfo;
  end;

  TDataContext = class
  protected
    FObjsToDestroy: array of TObject;
    DataOffset: Integer;
    Data: array of Byte;
    DataP: array of Pointer;
    VarToClear: array of Pointer;
    DynArrayToClear: array of TDynToClear;
    StrToClear: array of Pointer;
  public
    constructor Create;
    destructor Destroy; override;
    function  AllocData(Size: Integer): Pointer;
    procedure SetDataPointer(Index: Integer; P: Pointer);
    function  GetDataPointer(Index: Integer): Pointer;
    procedure AddObjectToDestroy(Obj: TObject);
    procedure RemoveObjectToDestroy(Obj: TObject);
    procedure AddDynArrayToClear(P: Pointer; Info: PTypeInfo);
    procedure AddVariantToClear(P: PVarData);
    procedure AddStrToClear(P: Pointer);
  end;

  TInvContext = class(TDataContext)
  private
    ResultP: Pointer;
  public
    procedure SetMethodInfo(const MD: TIntfMethEntry);
    procedure SetParamPointer(Param: Integer; P: Pointer);
    function  GetParamPointer(Param: Integer): Pointer;
    function  GetResultPointer: Pointer;
    procedure SetResultPointer(P: Pointer);
    procedure AllocServerData(const MD: TIntfMethEntry);
  end;

function  GetRemotableDataContext: Pointer;
procedure SetRemotableDataContext(Value: Pointer);

function  InvRegistry:   TInvokableClassRegistry;
function  RemClassRegistry: TRemotableClassRegistry;
function  RemTypeRegistry: TRemotableTypeRegistry;

function  SubstituteStrings(const InputString: WideString;
                            const SubString: WideString;
                            const Replacement: WideString): WideString;
var
  AppNameSpacePrefix: string;

const
  XMLSchemaInstNamepspaces: array[0..2] of InvString =
    (SXMLSchemaInstURI_1999, SXMLSchemaInstURI_2000_10, SXMLSchemaInstURI);

  XMLSchemaNamepspaces: array[0..2] of InvString =
    (SXMLSchemaURI_1999, SXMLSchemaURI_2000_10, SXMLSchemaURI_2001);

  XMLBase64Types: array[0..1] of InvString = ('base64Binary', 'bin.base64');

  { Use 'AS_ATTRIBUTE' for members TRemotable-derived classes that you want
    sent/received as attributes. For example:

        ClassWithAttribute = class(TRemotable)
        private
          FData: string;
          FAttribute: string;
        published
          property Data: string read FData write FData;
          property Attribute: string read FAttribute write FAttribute stored AS_ATTRIBUTE;
        end;

    The member 'Attribute' above will be streamed as
    an attribute of the class' node
  }
  AS_ATTRIBUTE = False;

implementation

uses Variants, InvRules, SOAPConst, Types;

var
  InvRegistryV: TInvokableClassRegistry;
  RemClassRegistryV: TRemotableClassRegistry;
  RemTypeRegistryV: TRemotableTypeRegistry;

threadvar
  RemotableDataContext: Pointer;

function SubstituteStrings(const InputString: WideString; const SubString: WideString;
                           const Replacement: WideString): WideString;
var
  I: Integer;
begin
  Result := InputString;
  I := Pos(SubString, InputString);
  if I = 0 then
    Exit
  else
  begin
    Delete(Result, I, Length(SubString));
    Insert(Replacement, Result, I);
  end;
end;

function InvRegistry: TInvokableClassRegistry;
begin
  Result :=  InvRegistryV;
end;

function RemClassRegistry: TRemotableClassRegistry;
begin
  Result := RemTypeRegistryV;
end;

function RemTypeRegistry: TRemotableTypeRegistry;
begin
  Result := RemTypeRegistryV;
end;

function GetRemotableDataContext: Pointer;
begin
  Result := RemotableDataContext;
end;

procedure SetRemotableDataContext(Value: Pointer);
begin
  RemotableDataContext := Value;
end;

function TInvokableClassRegistry.GetInterfaceCount: Integer;
begin
  Result := 0;
  if FRegIntfs <> nil then
    Result := Length(FRegIntfs);
end;

function TInvokableClassRegistry.GetRegInterfaceEntry(Index: Integer): InvRegIntfEntry;
begin
  if Index < Length(FRegIntfs) then
    Result := FRegIntfs[Index];
end;

constructor TInvokableClassRegistry.Create;
begin
  inherited Create;
  InitializeCriticalSection(FLock);
end;

destructor TInvokableClassRegistry.Destroy;
begin
  DeleteCriticalSection(FLock);
  inherited Destroy;
end;

procedure TInvokableClassRegistry.Lock;
begin
  EnterCriticalSection(FLock);
end;

procedure TInvokableClassRegistry.UnLock;
begin
  LeaveCriticalSection(FLock);
end;

procedure TInvokableClassRegistry.RegisterInvokableClass(AClass: TClass);
begin
  RegisterInvokableClass(AClass, nil);
end;

procedure TInvokableClassRegistry.RegisterInvokableClass(AClass: TClass; CreateProc: TCreateInstanceProc);
var
  Index, I, J: Integer;
  Table: PInterfaceTable;

begin
  Lock;
  try
    Table := AClass.GetInterfaceTable;
    { If a class does not implement interfaces, we'll try it's parent }
    if Table = nil then
    begin
      if (AClass.ClassParent <> nil) then
      begin
        Table := AClass.ClassParent.GetInterfaceTable;
        {
        if Table <> nil then
          AClass := AClass.ClassParent;
        }
      end;
    end;
    if Table = nil then
      raise ETypeRegistryException.CreateFmt(SNoInterfacesInClass, [AClass.ClassName]);
    Index := Length(FRegClasses);
    SetLength(FRegClasses, Index + 1);
    FRegClasses[Index].ClassType := AClass;
    FRegClasses[Index].Proc := CreateProc;

    { Find out what Registered invokable interface this class implements }
    for I := 0 to Table.EntryCount - 1 do
    begin
      for J := 0 to Length(FRegIntfs) - 1 do
        if IsEqualGUID(FRegIntfs[J].GUID, Table.Entries[I].IID) then
          { NOTE: Don't replace an existing implementation           }
          {       This approach allows for better control  on which  }
          {       class implements a particular interface            }
          if FRegIntfs[J].DefImpl = nil then
            FRegIntfs[J].DefImpl := AClass;
    end;
  finally
    UnLock;
  end;
end;

procedure TInvokableClassRegistry.DeleteFromReg(AClass: TClass; Info: PTypeInfo);
var
  I, Index, ArrayLen: Integer;
begin
  Lock;
  try
    Index := -1;
    if Assigned(Info) then
      ArrayLen := Length(FRegIntfs)
    else
      ArrayLen := Length(FRegClasses);
    for I := 0 to ArrayLen - 1 do
    begin
      if (Assigned(Info) and (FRegIntfs[I].Info = Info)) or
        (Assigned(AClass) and (FRegClasses[I].ClassType = AClass)) then
      begin
        Index := I;
        break;
      end;
    end;
    if Index <> -1 then
    begin
      if Assigned(Info) then
      begin
        for I := Index to ArrayLen - 2 do
          FRegIntfs[I] := FRegIntfs[I+1];
        SetLength(FRegIntfs, Length(FRegIntfs) -1);
      end else
      begin
        for I := Index to ArrayLen - 2 do
          FRegClasses[I] := FRegClasses[I+1];
        SetLength(FRegClasses, Length(FRegClasses) -1);
      end;
    end;
  finally
    UnLock;
  end;
end;

procedure TInvokableClassRegistry.UnRegisterInvokableClass(AClass: TClass);
begin
  DeleteFromReg(AClass, Nil);
end;

procedure TInvokableClassRegistry.RegisterInterface(Info: PTypeInfo);
begin
  RegisterInterface(Info, '');
end;

procedure TInvokableClassRegistry.RegisterInterface(Info: PTypeInfo; const Namespace: InvString);
begin
  RegisterInterface(Info, Namespace, '');
end;

procedure TInvokableClassRegistry.RegisterInterface(Info: PTypeInfo; const Namespace: InvString;
                    const WSDLEncoding: InvString);
begin
  RegisterInterface(Info, Namespace, WSDLEncoding, '');
end;

procedure TInvokableClassRegistry.RegisterInterface(Info: PTypeInfo; const Namespace: InvString;
                    const WSDLEncoding: InvString; const Doc: string);
begin
  RegisterInterface(Info, Namespace, WSDLEncoding, Doc, '');
end;

procedure TInvokableClassRegistry.RegisterInterface(Info: PTypeInfo; const Namespace: InvString;
                    const WSDLEncoding: InvString; const Doc: string; const ExtName: InvString);
var
  Index: Integer;
  IntfMD: TIntfMetaData;
  I, J: Integer;
  Table: PInterfaceTable;
  URIApp: string;
begin
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
      if FRegIntfs[I].Info = Info then
        Exit;
    Index := Length(FRegIntfs);
    SetLength(FRegIntfs, Index + 1);
    GetIntfMetaData(Info, IntfMD, True);
    FRegIntfs[Index].GUID := IntfMD.IID;
    FRegIntfs[Index].Info := Info;
    FRegIntfs[Index].Name := IntfMD.Name;
    FRegIntfs[Index].UnitName := IntfMD.UnitName;
    FRegIntfs[Index].Documentation := Doc;
    FRegIntfs[Index].ExtName := ExtName;
    FRegIntfs[Index].WSDLEncoding := WSDLEncoding;

    if AppNameSpacePrefix <> '' then
      URIApp := AppNameSpacePrefix +  '-';

    { Auto-generate a namespace from the filename in which the interface was declared and
      the AppNameSpacePrefix }
    if Namespace = '' then
      FRegIntfs[Index].Namespace :=  'urn:' + URIApp + IntfMD.UnitName + '-' + IntfMD.Name
    else
    begin
      FRegIntfs[Index].Namespace := Namespace;
      FRegIntfs[Index].InvokeOptions := FRegIntfs[Index].InvokeOptions + [ioHasNamespace];
    end;

    if FRegIntfs[Index].DefImpl = nil then
    begin
      { NOTE: First class that implements this interface wins!! }
      for I := 0 to Length(FRegClasses) - 1 do
      begin
        { NOTE: We'll allow for a class whose parent implements interfaces }
        Table :=  FRegClasses[I].ClassType.GetInterfaceTable;
        if (Table = nil) then
        begin
          Table := FRegClasses[I].ClassType.ClassParent.GetInterfaceTable;
        end;
        for J := 0 to Table.EntryCount - 1 do
        begin
          if IsEqualGUID(IntfMD.IID, Table.Entries[J].IID) then
          begin
            FRegIntfs[Index].DefImpl := FRegClasses[I].ClassType;
            Exit;
          end;
        end;
      end;
    end;
  finally
    Unlock;
  end;
end;

procedure TInvokableClassRegistry.RegisterDefaultSOAPAction(Info: PTypeInfo; const DefSOAPAction: InvString);
var
  I: Integer;
begin
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if FRegIntfs[I].Info = Info then
      begin
        FRegIntfs[I].DefaultSOAPAction := DefSOAPAction;
        FRegIntfs[I].InvokeOptions := FRegIntfs[I].InvokeOptions + [ioHasDefaultSOAPAction];
        Exit;
      end;
    end;
  finally
    Unlock;
  end;
end;

procedure TInvokableClassRegistry.RegisterReturnParamNames(Info: PTypeInfo; const RetParamNames: string);
var
  I: Integer;
begin
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if FRegIntfs[I].Info = Info then
      begin
        FRegIntfs[I].ReturnParamNames := RetParamNames;
        FRegIntfs[I].InvokeOptions := FRegIntfs[I].InvokeOptions + [ioHasReturnParamNames];
        Exit;
      end;
    end;
  finally
    Unlock;
  end;
end;

procedure TInvokableClassRegistry.RegisterInvokeOptions(Info: PTypeInfo; const InvokeOption: TIntfInvokeOption);
var
  Options: TIntfInvokeOptions;
begin
  Options := GetIntfInvokeOptions(Info);
  Options := Options + [InvokeOption];
  RegisterInvokeOptions(info, Options);
end;

procedure TInvokableClassRegistry.RegisterInvokeOptions(Info: PTypeInfo; const InvokeOptions: TIntfInvokeOptions);
var
  I: Integer;
begin
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if FRegIntfs[I].Info = Info then
      begin
        FRegIntfs[I].InvokeOptions := InvokeOptions;
        Exit;
      end;
    end;
  finally
    Unlock;
  end;
end;

function TInvokableClassRegistry.GetIntfInvokeOptions(const IntfInfo: PTypeInfo): TIntfInvokeOptions;
var
  I: Integer;
begin
  Result := [];
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if IntfInfo = FRegIntfs[I].Info then
      begin
        Result := FRegIntfs[I].InvokeOptions;
        Exit;
      end;
    end;
  finally
    UnLock;
  end;
end;

function TInvokableClassRegistry.GetIntfInvokeOptions(const AGUID: TGUID): TIntfInvokeOptions;
begin
  Result := GetIntfInvokeOptions(GetInterfaceTypeInfo(AGUID));
end;

function TInvokableClassRegistry.GetInterfaceExternalName(Info: PTypeInfo): InvString;
begin
  Result := GetInterfaceExternalName(Info, '');
end;

function TInvokableClassRegistry.GetInterfaceExternalName(Info: PTypeInfo; Namespace: string): InvString;
begin
  Result := GetInterfaceExternalName(Info, Namespace, '');
end;

function TInvokableClassRegistry.GetInterfaceExternalName(Info: PTypeInfo; Namespace: string; InternalIntfName: string): InvString;
var
  Index: Integer;
begin
  Result := InternalIntfName;
  Lock;
  try
    for Index := 0 to Length(FRegIntfs) - 1 do
    begin
      if FRegIntfs[Index].Info = Info then
        if FRegIntfs[Index].Name = InternalIntfName then
        begin
          if FRegIntfs[Index].ExtName <> '' then
            Result := FRegIntfs[Index].ExtName;
          break;
        end;
    end;
  finally
    Unlock;
  end;
end;

function TInvokableClassRegistry.GetWSDLEncoding(Info: PTypeInfo): InvString;
begin
  Result := GetWSDLEncoding(Info, '');
end;

function TInvokableClassRegistry.GetWSDLEncoding(Info: PTypeInfo; Namespace: string): InvString;
begin
  Result := GetWSDLEncoding(Info, Namespace, '');
end;

function TInvokableClassRegistry.GetWSDLEncoding(Info: PTypeInfo; Namespace: string; InternalIntfName: string): InvString;
var
  Index: Integer;
begin
  Result := '';
  Lock;
  try
    for Index := 0 to Length(FRegIntfs) - 1 do
    begin
      if FRegIntfs[Index].Info = Info then
        if FRegIntfs[Index].Name = InternalIntfName then
        begin
          Result := FRegIntfs[Index].WSDLEncoding;
          break;
        end;
    end;
  finally
    Unlock;
  end;
end;

procedure TInvokableClassRegistry.UnRegisterInterface(Info: PTypeInfo);
begin
  DeleteFromReg(nil, Info);
end;

procedure TInvokableClassRegistry.RegisterExternalMethName(Info: PTypeInfo; InternalName: string; const ExternalName: InvString);
var
  I, J: Integer;
begin
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
      if FRegIntfs[I].Info = Info then
      begin
        J := Length(FRegIntfs[I].MethNameMap);
        SetLength(FRegIntfs[I].MethNameMap, J + 1);
        FRegIntfs[I].MethNameMap[J].Name := InternalName;
        FRegIntfs[I].MethNameMap[J].ExtName := ExternalName;
      end;
  finally
    Unlock;
  end;
end;

procedure TInvokableClassRegistry.RegisterExternalParamName(Info: PTypeInfo; MethodName, InternalName: string; const ExternalName: InvString);
var
  I, J, K: Integer;
begin
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
      if FRegIntfs[I].Info = Info then
      begin
        J := 0;
        while J <= Length(FRegIntfs[I].MethParamNameMap) -1 do
        begin
          if SameText(FRegIntfs[I].MethParamNameMap[J].MethName, MethodName) then
            break;
          J := J + 1;
        end;

        if J = Length(FRegIntfs[I].MethParamNameMap) then
        begin
          SetLength(FRegIntfs[I].MethParamNameMap, J + 1);
          FRegIntfs[I].MethParamNameMap[J].MethName := MethodName;
        end;
        K := Length(FRegIntfs[I].MethParamNameMap[J].ParamNameMap);
        SetLength(FRegIntfs[I].MethParamNameMap[J].ParamNameMap, K + 1);
        FRegIntfs[I].MethParamNameMap[J].ParamNameMap[K].Name := InternalName;
        FRegIntfs[I].MethParamNameMap[J].ParamNameMap[K].ExtName := ExternalName;
        break;
      end;
  finally
    Unlock;
  end;
end;

function TInvokableClassRegistry.GetParamExternalName(Info: PTypeInfo;  MethodName, InternalParamName: string): InvString;
var
  I, J, K: Integer;
begin
  Result := InternalParamName;
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
      if FRegIntfs[I].Info = Info then
      begin
        for J := 0 to Length(FRegIntfs[I].MethParamNameMap) -1 do
          if SameText(FRegIntfs[I].MethParamNameMap[J].MethName, MethodName) then
          begin
            for K := 0 to Length(FRegIntfs[I].MethParamNameMap[J].ParamNameMap) -1 do
              if SameText(FRegIntfs[I].MethParamNameMap[J].ParamNameMap[K].Name, InternalParamName) then
              begin
                if FRegIntfs[I].MethParamNameMap[J].ParamNameMap[K].ExtName <> '' then
                  Result := FRegIntfs[I].MethParamNameMap[J].ParamNameMap[K].ExtName;
                Exit;
              end;
          end;
      end;
  finally
    Unlock;
  end;
end;

function TInvokableClassRegistry.GetParamInternalName(Info: PTypeInfo;  MethodName: string; ExternalParamName: InvString): string;
var
  I, J, K: Integer;
begin
  Result := ExternalParamName;
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
      if FRegIntfs[I].Info = Info then
      begin
        for J := 0 to Length(FRegIntfs[I].MethParamNameMap) -1 do
          if SameText(FRegIntfs[I].MethParamNameMap[J].MethName, MethodName) then
          begin
            for K := 0 to Length(FRegIntfs[I].MethParamNameMap[J].ParamNameMap) -1 do
              if SameText(FRegIntfs[I].MethParamNameMap[J].ParamNameMap[K].ExtName, ExternalParamName) then
              begin
                if FRegIntfs[I].MethParamNameMap[J].ParamNameMap[K].Name <> '' then
                  Result := FRegIntfs[I].MethParamNameMap[J].ParamNameMap[K].Name;
                Exit;
              end;
          end;
      end;
  finally
    Unlock;
  end;
end;

function TInvokableClassRegistry.GetMethExternalName(Info: PTypeInfo;  MethodIntName: string): InvString;
var
  I, J: Integer;
begin
  Result := MethodIntName;
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if FRegIntfs[I].Info = Info then
      begin
        for J := 0 to Length(FRegIntfs[I].MethNameMap) -1 do
          if SameText(FRegIntfs[I].MethNameMap[J].Name, MethodIntName) then
          begin
            if FRegIntfs[I].MethNameMap[J].ExtName <> '' then
              Result := FRegIntfs[I].MethNameMap[J].ExtName;
            Exit;
          end;
      end;
    end;
  finally
    Unlock;
  end;
end;

function TInvokableClassRegistry.GetMethInternalName(Info: PTypeInfo;  MethodExtName: InvString): string;
var
  I, J: Integer;
begin
  Result := MethodExtName;
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if FRegIntfs[I].Info = Info then
      begin
        for J := 0 to Length(FRegIntfs[I].MethNameMap) -1 do
          if SameText(FRegIntfs[I].MethNameMap[J].ExtName, MethodExtName) then
          begin
            if FRegIntfs[I].MethNameMap[J].Name <> '' then
              Result := FRegIntfs[I].MethNameMap[J].Name;
            Exit;
          end;
      end;
    end;
  finally
    Unlock;
  end;
end;

function TInvokableClassRegistry.GetInterfaceTypeInfo(const AGUID: TGUID): Pointer;
var
  I: Integer;
begin
  Result := nil;
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if IsEqualGUID(AGUID, FRegIntfs[I].GUID) then
      begin
        Result := FRegIntfs[I].Info;
        Exit;
      end;
    end;
  finally
    UnLock;
  end;
end;

procedure TInvokableClassRegistry.GetInterfaceInfoFromName(
  const UnitName, IntfName: string; var Info: PTypeInfo; var IID: TGUID);
var
  I: Integer;
begin
  Info := nil;
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if SameText(IntfName, FRegIntfs[I].Name)
          and ((UnitName = '') or (SameText(UnitName, FRegIntfs[I].UnitName)))
      then
      begin
        Info := FRegIntfs[I].Info;
        IID := FRegIntfs[I].GUID;
      end;
    end;
  finally
    UnLock;
  end;
end;

function  TInvokableClassRegistry.GetActionURIOfIID(const AGUID: TGUID): string;
begin
  Result := GetActionURIOfInfo(GetInterfaceTypeInfo(AGUID), '');
end;

function TInvokableClassRegistry.GetActionURIOfInfo(const IntfInfo: PTypeInfo; const MethodName: WideString): string;
var
  I: Integer;
begin
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if IntfInfo = FRegIntfs[I].Info then
      begin
        { NOTE: Method name is ignored when an explicit SOAPAction is set unless it
                contains the Operation format specifier }
        if (ioHasDefaultSOAPAction in FRegIntfs[I].InvokeOptions) then
        begin
          Result := FRegIntfs[I].DefaultSOAPAction;
          if MethodName <> '' then
            Result := SubstituteStrings(Result, SOperationNameSpecifier, MethodName);
        end
        else
        begin
          { NOTE: For backward compatibility reasons, we use the Namespace#MethodName
                  as the default SOAPAction. If you need to customize the SOAPAction,
                  or if you can't use that logic (like when more than one interface
                  uses the same namespace), use the RegisterDefaultSOAPAction member
                  to specify another SOAPAction }
          Result := FRegIntfs[I].Namespace + '#' + MethodName;
        end;
        Exit;
      end;
    end;
  finally
    UnLock;
  end;
end;

function TInvokableClassRegistry.GetReturnParamNames(const IntfInfo: PTypeInfo): string;
var
  I: Integer;
begin
  Result := SDefaultReturnParamNames;
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if IntfInfo = FRegIntfs[I].Info then
      begin
        if (ioHasReturnParamNames in FRegIntfs[I].InvokeOptions) then
          Result := FRegIntfs[I].ReturnParamNames;
        Exit;
      end;
    end;
  finally
    UnLock;
  end;
end;

function TInvokableClassRegistry.GetInfoForURI(const PathURI, ActionURI: string; var AClass: TClass; var IntfInfo: PTypeInfo; var AMeth: string): Boolean;

  function FindViaSOAPAction: Boolean;
  var
    I: integer;
    SAPrefix, ActionPrefix: string;
  begin
    Result := False;
    // Presumes that an action is of the form:
    //    <Namespace>#<MethodName>
    // or
    //    <DefaultSOAPAction><Some other stuff that can be ignored>
    //
    // and that an interface is registered with a <namespace|defaultSOAPAction>
    // so we simply find the first registered interface with a namespace|defaultSOAPAction that
    // is an initial substring of the action
    //
    // NOTE: The method name portion in the first format is ignored!!
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      { If user specified a SOAPAction use that - otherwise default
        to how we generate SA from namespaces (i.e. GetActionURIOfInfo) }
      if (ioHasDefaultSOAPAction in FRegIntfs[I].InvokeOptions) then
        SAPrefix := FRegIntfs[I].DefaultSOAPAction
      else
        SAPrefix := FRegIntfs[I].Namespace;
      { If Default SOAPAction has #%operationName% }
      Delete(SAPrefix, Pos('#', SAPrefix), Length(SAPrefix));           { Do not localize }

      { Get the Prefix of the SOAPAction passed in }
      ActionPrefix := ActionURI;
      if ActionPrefix[1] = '"' then
        Delete(ActionPrefix, 1, 1);
      if ActionPrefix[Length(ActionPrefix)]='"' then
        Delete(ActionPrefix, Length(ActionPrefix), 1);
      Delete(ActionPrefix, Pos('#', ActionPrefix), Length(ActionPrefix));

      if ActionPrefix = SAPrefix then
      begin
        IntfInfo := FRegIntfs[I].Info;
        AClass := FRegIntfs[I].DefImpl;
        Result := True;
        break;
      end;
    end;
  end;

  function FindViaPath: Boolean;
  var
    I: Integer;
  begin
    Result := False;
    { If a URL is used for defining which interface to use
      then find the first interface whose name is a terminal substring of the
      path.
      NOTE: Doesn't consider interfaces with the same name but in different units!! }
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if  SameText(Copy(PathURI, LastDelimiter('/', PathURI) + 1, High(Integer)),FRegIntfs[I].Name) then
      begin
        IntfInfo := FRegIntfs[I].Info;
        AClass := FRegIntfs[I].DefImpl;
        Result := True;
        break;
      end;
    end
  end;

begin
  Result := False;
  Lock;
  try
    if ActionURI <> '' then
      Result := FindViaSOAPAction;
    if (Result = False) and (PathURI <> '') then
      Result := FindViaPath;
  finally
    UnLock;
  end;
end;

function TInvokableClassRegistry.GetNamespaceByGUID(const AGUID: TGUID): string;
var
  I: Integer;
begin
  Result := '';
  Lock;
  try
    for I := 0 to Length(FRegIntfs) - 1 do
    begin
      if IsEqualGUID(FRegIntfs[I].GUID, AGUID) then
      begin
        Result := FRegIntfs[I].Namespace;
        break;
      end;
    end;
  finally
    UnLock;
  end;
end;

function TInvokableClassRegistry.GetInvokableObjectFromClass(
  AClass: TClass): TObject;
var
  I: Integer;
  Found: Boolean;
begin
  Result := nil;
  Lock;
  Found := False;
  Try
    for I := 0 to Length(FRegClasses) - 1 do
      if FRegClasses[I].ClassType = AClass then
        if Assigned(FRegClasses[I].Proc) then
        begin
          FRegClasses[I].Proc(Result);
          Found := True;
        end;
    if not Found and  AClass.InheritsFrom(TInvokableClass) then
      Result := TInvokableClassClass(AClass).Create;
  finally
    UnLock;
  end;
end;

procedure TInvokableClassRegistry.GetClassFromIntfInfo(Info: PTypeInfo;
  var AClass: TClass);
var
  I: Integer;
begin
  AClass := nil;
  Lock;
  Try
    for I := 0 to Length(FRegIntfs) - 1 do
      if FRegIntfs[I].Info = Info then
      begin
        AClass := FRegIntfs[I].DefImpl;
        break;
      end;
  finally
    UnLock;
  end;
end;

{ TInvokableClass }

constructor TInvokableClass.Create;
begin
  inherited Create;
end;

{ TRemotable }

constructor TRemotable.Create;
begin
  inherited;
  if RemotableDataContext <> nil then
  begin
    TDataContext(RemotableDataContext).AddObjectToDestroy(Self);
    Self.DataContext := TDataContext(RemotableDataContext);
  end;
end;

destructor TRemotable.Destroy;
begin
  if RemotableDataContext <> nil then
  begin
    TDataContext(RemotableDataContext).RemoveObjectToDestroy(Self);
    Self.DataContext := nil;
  end;
  inherited Destroy;
end;

procedure TRemotable.SetDataContext(Value: TDataContext);
begin
  if (RemotableDataContext <> nil) and (RemotableDataContext = Self.DataContext) then
  begin
    TDataContext(RemotableDataContext).RemoveObjectToDestroy(Self);
  end;
  FDataContext := Value;
end;


{ TRemotableXS }

function TRemotableXS.NativeToXS: WideString;
begin
end;

procedure TRemotableXS.XSToNative(Data: WideString);
begin
end;

constructor TRemotableTypeRegistry.Create;
begin
  inherited Create;
  FAutoRegister := True;
  InitializeCriticalSection(FLock);
end;

destructor TRemotableTypeRegistry.Destroy;
begin
  inherited Destroy;
  DeleteCriticalSection(FLock);
end;

procedure TRemotableTypeRegistry.Lock;
begin
  EnterCriticalSection(FLock);
end;

procedure TRemotableTypeRegistry.UnLock;
begin
  LeaveCriticalSection(FLock);
end;

function TRemotableTypeRegistry.GetURICount: Integer;
begin
  Lock;
  try
    Result := Length(URIMap);
  finally
    UnLock;
  end;
end;

function TRemotableTypeRegistry.GetURIMap(Index: Integer; out RegEntry: TRemRegEntry): Boolean;
begin
  Result := (Index < Length(URIMap)) and (Index >= 0);
  RegEntry := GetURIMap(Index);
end;

function TRemotableTypeRegistry.GetURIMap(Index: Integer): TRemRegEntry;
begin
  Lock;
  Try
  if Index < Length(URIMap) then
    Result := URIMap[Index];
  finally
    UnLock;
  end;
end;

procedure TRemotableTypeRegistry.RegisterXSClass(AClass: TClass; URI: WideString; Name: WideString;
                                                 ExtName: WideString; IsScalar: Boolean);
begin
  RegisterXSClass(AClass, URI, Name, ExtName, IsScalar, ocDefault);
end;

procedure TRemotableTypeRegistry.RegisterXSClass(AClass: TClass; URI: WideString; Name: WideString;
                                                 ExtName: WideString);
begin
  RegisterXSClass(AClass, URI, Name, ExtName, False);
end;

procedure TRemotableTypeRegistry.RegisterXSClass(AClass: TClass; URI: WideString; Name: WideString);
begin
  RegisterXSClass(AClass, URI, Name, '');
end;

procedure TRemotableTypeRegistry.RegisterXSClass(AClass: TClass; URI: WideString);
begin
  RegisterXSClass(AClass, URI, '');
end;

procedure TRemotableTypeRegistry.RegisterXSClass(AClass: TClass);
begin
  RegisterXSClass(AClass, '');
end;

{ procedure TRemotableTypeRegistry.RegisterXSClass(AClass: TClass; URI: WideString = ''; Name: WideString = ''; ExtName: WideString = ''; IsScalar: Boolean = False; MultiRefOpt: TObjMultiOptions = ocDefault); }
procedure TRemotableTypeRegistry.RegisterXSClass(AClass: TClass; URI: WideString; Name: WideString; ExtName: WideString; IsScalar: Boolean; MultiRefOpt: TObjMultiOptions);
var
  Index: Integer;
  Found: Boolean;
  AppURI: WideString;
begin
  Lock;
  Try
    Index := GetEntry(AClass.ClassInfo, Found, Name);
    if not Found then
    begin
      if AppNameSpacePrefix <> '' then
        AppURI := AppNameSpacePrefix + '-';
      if URI = '' then
        URIMap[Index].URI := 'urn:' + AppURI + GetTypeData(AClass.ClassInfo).UnitName { do not localize }
      else
        URIMap[Index].URI := URI;
      if Name <> '' then
        URIMap[Index].Name := Name
      else
      begin
        URIMap[Index].Name := AClass.ClassName;
      end;
      URIMap[Index].ExtName := ExtName;
      URIMap[Index].ClassType := AClass;
      URIMap[Index].Info := AClass.ClassInfo;
      URIMap[Index].IsScalar := IsScalar;
      URIMap[Index].MultiRefOpt := MultiRefOpt;
    end;
  finally
    UnLock;
  end;
end;

procedure TRemotableTypeRegistry.RegisterXSInfo(Info: PTypeInfo);
begin
  RegisterXSInfo(Info, '');
end;

procedure TRemotableTypeRegistry.RegisterXSInfo(Info: PTypeInfo; URI: WideString);
begin
  RegisterXSInfo(Info, URI, '');
end;

procedure TRemotableTypeRegistry.RegisterXSInfo(Info: PTypeInfo; URI: WideString; Name: WideString);
begin
  RegisterXSInfo(Info, URI, Name, '');
end;

{ procedure TRemotableTypeRegistry.RegisterXSInfo(Info: PTypeInfo; URI: WideString = ''; Name: WideString = ''; ExtName: WideString = ''); }
procedure TRemotableTypeRegistry.RegisterXSInfo(Info: PTypeInfo; URI: WideString; Name: WideString; ExtName: WideString);
var
  Index: Integer;
  Found: Boolean;
  AppURI: WideString;
  UnitName: string;

  function GetEnumUnitName(Info: PTypeInfo): string;
  var
    P: ^ShortString;
    T: PTypeData;
    Size: Integer;
  begin
    T := GetTypeData(GetTypeData(Info)^.BaseType^);
    P := @T^.NameList;
    Size := T.MaxValue - T.MinValue;
    while Size >= 0  do
    begin
      Inc(Integer(P), Length(P^) + 1);
      Dec(Size);
    end;
    Result := P^;
  end;

begin
  Lock;
  Try
    { NOTE: Here we'll allow one (TypeInfo) type to map to many XML Types -
            For example, 'anyType' and 'anySimple' types both map to Variant.
            However, the first one registered will be the one under which
            the native type will be published!! }
    Index := GetEntry(Info, Found, Name);
    if Found then
      Exit;
    if AppNameSpacePrefix <> '' then
      AppURI := AppNameSpacePrefix + '-';
    if URI = '' then
    begin
      if Info.Kind = tkDynArray then
      begin
        UnitName := GetTypeData(Info).DynUnitName;
        URIMap[Index].URI := 'urn:' + AppURI +  UnitName;
      end
      else if Info.Kind = tkEnumeration then
      begin
        UnitName := GetEnumUnitName(Info);
        URIMap[Index].URI := 'urn:' + AppURI +  UnitName;
      end
      else if Info.Kind = tkClass then
        URIMap[Index].URI := 'urn:' + AppURI + GetTypeData(Info).UnitName
      else
        URIMap[Index].URI := 'urn:' + AppURI;
    end
    else
      URIMap[Index].URI := URI;
    if Name <> '' then
      URIMap[Index].Name := Name
    else
    begin
      URIMap[Index].Name := Info.Name;
    end;
    URIMap[Index].ExtName := ExtName;
    URIMap[Index].Info := Info;
    if Info.Kind = tkClass then
      URIMap[Index].ClassType := GetTypeData(Info).ClassType;
  finally
    UnLock;
  end;
end;

procedure TRemotableTypeRegistry.RegisterHolderClsMember(ClsTypeInfo: PTypeInfo; URI: WideString = ''; Name: WideString = ''; ExtName: WideString = '');
var
  MemberInfo: PTypeInfo;
begin
  MemberInfo := GetClsMemberTypeInfo(ClsTypeInfo);
  if MemberInfo <> nil then
    RegisterXSInfo(MemberInfo, URI, Name, ExtName);
end;

procedure TRemotableTypeRegistry.DeleteEntryFromURIMap(Info: PTypeInfo);
var
  I, Index: Integer;
  Found: Boolean;
begin
  Lock;
  try
    Index := GetEntry(Info, Found);
    if Found then
    begin
      for I := Index to Length(URIMap) -2 do
        URIMap[I] := URIMap[I+1];
    end;
    SetLength(URIMap, Length(URIMap) -1);
  finally
    UnLock;
  end;
end;

procedure TRemotableTypeRegistry.UnRegisterXSClass(AClass: TClass);
begin
  DeleteEntryFromURIMap(AClass.ClassInfo);
end;

procedure TRemotableTypeRegistry.UnRegisterXSInfo(Info: PTypeInfo);
begin
  DeleteEntryFromURIMap(Info);
end;

function TRemotableTypeRegistry.IsClassScalar(AClass: TClass): Boolean;
var
  I: Integer;
begin
  Result := False;
  Lock;
  Try
    for I := 0 to Length(URIMap) - 1 do
    begin
      if URIMap[I].ClassType = AClass then
      begin
        Result := URIMap[I].IsScalar;
        break;
      end;
    end;
  finally
    UnLock;
  end;
end;

function TRemotableTypeRegistry.ClassOptions(AClass: TClass): TObjMultiOptions;
var
  I: Integer;
begin
  Result := ocDefault;
  Lock;
  Try
    for I := 0 to Length(URIMap) - 1 do
    begin
      if URIMap[I].ClassType = AClass then
      begin
        Result := URIMap[I].MultiRefOpt;
        break;
      end;
    end;
  finally
    UnLock;
  end;
end;

procedure TRemotableTypeRegistry.RegisterSerializeOptions(AClass: TClass; SerialOpt: TSerializationOptions);
var
  I: Integer;
begin
  Lock;
  Try
    for I := 0 to Length(URIMap) - 1 do
    begin
      if URIMap[I].ClassType = AClass then
      begin
        URIMap[I].SerializationOpt := SerialOpt;
        break;
      end;
    end;
  finally
    UnLock;
  end;
end;

function TRemotableTypeRegistry.SerializeOptions(AClass: TClass): TSerializationOptions;
var
  I: Integer;
begin
  Result := [];
  Lock;
  Try
    for I := 0 to Length(URIMap) - 1 do
    begin
      if URIMap[I].ClassType = AClass then
      begin
        Result := URIMap[I].SerializationOpt;
        break;
      end;
    end;
  finally
    UnLock;
  end;
end;

procedure TRemotableTypeRegistry.RegisterExternalPropName(Info: PTypeInfo; InternalName: string; const ExternalName: InvString);
begin
end;

function TRemotableTypeRegistry.GetExternalPropName(Info: PTypeInfo; InternalName: string): InvString;
begin
  Result := InternalName;
end;

function TRemotableTypeRegistry.GetInternalPropName(Info: PTypeInfo; ExternalName: InvString): string;
begin
  Result := ExternalName;
end;

function TRemotableTypeRegistry.URIToInfo(const URI,
  Name: WideString): PTypeInfo;
var
  I: Integer;
begin
  Result := nil;
  Lock;
  Try
    for I := 0 to Length(URIMap) - 1 do
    begin
      if (URIMap[I].URI = URI) and (URIMap[I].Name = Name) then
      begin
        Result := URIMap[I].Info;
        break;
      end;
    end;
  finally
    UnLock;
  end;
end;

procedure TRemotableTypeRegistry.GetXSDInfoForClass(Info: PTypeInfo; var URI, TypeName: WideString);
var
  AClass: TClass;
  IsScalar: Boolean;
begin
  AClass := GetTypeData(Info).ClassType;
  ClassToURI(AClass, URI, TypeName, IsScalar);
end;

function TRemotableTypeRegistry.GetRegisteredClassForBuiltInXSD(const TypeName: WideString): TClass;
var
  IsScalar: Boolean;
begin
  Result := RemClassRegistry.URIToClass(XMLSchemaNameSpace, TypeName, IsScalar);
end;

function  TRemotableTypeRegistry.GetSimpleBuiltInXSDType(const URI, TypeName: WideString): PTypeInfo;
var
  I: Integer;
begin
  Result := nil;
  Lock;
  Try
    for I := 0 to Length(URIMap) -1 do
    begin
      if (URIMap[I].URI = URI) and (URIMap[I].Name = TypeName) then
      begin
        Result := URIMap[I].Info;
        break;
      end;
    end;
  finally
    UnLock;
  end;
end;

function TRemotableTypeRegistry.XSDToTypeInfo(URI, TypeName: WideString): PTypeInfo;
var
  AClass, BuiltinClass: TClass;
  IsScalar: Boolean;
  I: Integer;

  function IsBase64TypeName(TypeName: InvString): Boolean;
  var
    J: Integer;
  begin
    Result := False;
    for J := Low(XMLBase64Types) to High(XMLBase64Types) do
      if TypeName = XMLBase64Types[J] then
      begin
        Result := True;
        break;
      end;
  end;
begin
  Result := nil;
  if URI = XMLSchemaNameSpace then
  begin
    { First check if a registered class overrides default mapping }
    BuiltinClass := GetRegisteredClassForBuiltInXSD(TypeName);
    if BuiltinClass <> nil then
      Result := BuiltinClass.ClassInfo;
    { If not, check default mapping }
    if Result = nil then
      Result := GetSimpleBuiltInXSDType(URI, TypeName);
      if (Result = nil) and IsBase64TypeName(TypeName) then
        for I := Low(XMLBase64Types) to High(XMLBase64Types) do
        begin
          Result := GetSimpleBuiltInXSDType(URI, XMLBase64Types[I]);
          if Result <> nil then
            break;
        end;
  end else
  begin
    AClass := RemClassRegistry.URIToClass(URI, TypeName, IsScalar);
    if AClass <> nil then
    begin
      Result := AClass.ClassInfo;
      Exit;
    end;
    if AClass = nil then
    begin
      Result := RemClassRegistry.URIToInfo(URI, TypeName);
    end;
  end;
end;

function TRemotableTypeRegistry.VariantToInfo(V: Variant; TryAllSchema: Boolean): PTypeInfo;
var
 I: Integer;
begin
  Result := nil;
  case VarType(V) and VarTypeMask of
    varEmpty,
    varNull:
      raise ETypeRegistryException.Create(SUnsupportedVariant);
    varSmallint:
      Result := TypeInfo(System.SmallInt);
    varInteger:
      Result := TypeInfo(System.Integer);
    varSingle:
      Result := TypeInfo(System.Single);
    varDouble,
    varCurrency:
      Result := TypeInfo(System.Double);
    varDate:
      begin
        Result := RemClassRegistry.URIToInfo(XMLSchemaNameSpace, 'dateTime'); { do not localize }
        if Result = nil then
        begin
          for I := Low(XMLSchemaNamepspaces) to High(XMLSchemaNamepspaces) do
          begin
            Result := RemClassRegistry.URIToInfo(XMLSchemaNamepspaces[I], 'dateTime');
            if Result <> nil then
              break;
          end;
        end;
      end;
    varOleStr:
      Result := TypeInfo(System.WideString);
    varDispatch:
      raise ETypeRegistryException.Create(SNoVarDispatch);
    varError:
      raise ETypeRegistryException.Create(SNoErrorDispatch);
    varBoolean:
      Result := TypeInfo(System.Boolean);
    varVariant:
      Result := TypeInfo(System.Variant);
    varUnknown:
      raise ETypeRegistryException.Create(SUnsupportedVariant);
    varShortInt:
      Result := TypeInfo(System.ShortInt);
    varByte:
      Result := TypeInfo(System.Byte);
    varWord:
      Result := TypeInfo(System.Word);
    varLongWord:
      Result := TypeInfo(System.LongWord);
    varInt64:
      Result := TypeInfo(System.Int64);
    varString:
      Result := TypeInfo(System.WideString);
  end;
end;

function TRemotableTypeRegistry.GetVarTypeFromXSD(URI,
  TypeName: InvString): TVarType;
var
  Info: PTypeInfo;
begin
  Result := varUnknown;
  Info := XSDToTypeInfo(URI, TypeName);
  case Info.Kind of
    tkInteger:
      Result := varInteger;
    tkFloat:
      Result := varDouble;
    tkInt64:
      Result := varInt64;
    tkChar,
    tkWChar,
    tkWString,
    tkString,
    tkLString:
      Result := varOleStr;
  end;
end;

function TRemotableClassRegistry.GetEntry(Info: PTypeInfo; var Found: Boolean; Name: WideString): Integer;
begin
  Result := 0;
  Found := False;
  while Result < Length(URIMap) do
  begin
    if (Info <> nil) and (URIMap[Result].Info = Info) then
    begin
      if (Name = '') or (URIMap[Result].Name = Name) then
      begin
        Found := True;
        Exit;
      end;
    end;
    Inc(Result);
  end;
  SetLength(URIMap, Result + 1);
end;

function TRemotableTypeRegistry.URIToClass(URI, Name: WideString; var IsScalar: Boolean): TClass;
var
  I: Integer;
begin
  Result := nil;
  Lock;
  Try
    for I := 0 to Length(URIMap) - 1 do
    begin
      if (URIMap[I].URI = URI) and (URIMap[I].Name = Name) then
      begin
        Result := URIMap[I].ClassType;
        IsScalar := URIMap[I].IsScalar;
        break;
      end;
    end;
  finally
    UnLock;
  end;
end;

function TRemotableClassRegistry.InfoToURI(Info: PTypeInfo; var URI,
  Name: WideString; var IsScalar: Boolean; tryToRegister: Boolean): Boolean;
var
  I: Integer;
begin
  Result := False;
  Lock;
  Try
    if Info <> nil then
    begin
      { Look for an exact match first  }
      for I := 0 to Length(URIMap) - 1 do
      begin
        if (URIMap[I].Info = Info) then
        begin
          URI := URIMap[I].URI;
          Name :=  URIMap[I].Name;
          IsScalar := URIMap[I].IsScalar;
          Result := True;
          break;
        end;
      end;
      { Look for an equivalent match }
      if not Result then
      begin
        for I := 0 to Length(URIMap) - 1 do
        begin
          if SameTypeInfo(URIMap[I].Info, Info) then
          begin
            URI := URIMap[I].URI;
            Name :=  URIMap[I].Name;
            IsScalar := URIMap[I].IsScalar;
            Result := True;
            break;
          end;
        end;
      end;        
    end;
  finally
    UnLock;
  end;
  if (Result = false) and (FAutoRegister) and (tryToRegister) then
  begin
    RegisterXSInfo(Info);
    Result := InfoToURI(Info, URI, Name, IsScalar, False);
  end;
end;

function TRemotableTypeRegistry.ClassToURI(AClass: TClass; var URI,
  Name: WideString; var IsScalar: Boolean; tryToRegister: Boolean): Boolean;
var
  I: Integer;
begin
  Result := False;
  Lock;
  try
    for I := 0 to Length(URIMap)- 1 do
      if URIMap[I].ClassType = AClass  then
      begin
        URI := URIMap[I].URI;
        Name := URIMap[I].Name;
        IsScalar := URIMap[I].IsScalar;
        Result := True;
        break;
      end;
  finally
    UnLock;
  end;
  if (Result = false) and (FAutoRegister) and (tryToRegister) then
  begin
    RegisterXSClass(AClass);
    Result := ClassToURI(AClass, URI, Name, IsScalar, False);
  end;
end;

function TRemotableClassRegistry.TypeInfoToXSD(Info: PTypeInfo; var URI,
  TypeName: WideString): Boolean;
var
  IsScalar: Boolean;
begin
  if Info.Kind = tkClass then
    Result := ClassToURI(GetTypeData(Info).ClassType, URI, TypeName, IsScalar)
  else
    Result := InfoToURI(Info, URI, TypeName, IsScalar);
end;

{ ERemotableException }

constructor ERemotableException.CreateRem;
begin
  inherited Create('');
end;

{ TDataContext }

procedure TDataContext.SetDataPointer(Index: Integer; P: Pointer);
begin
  DataP[Index] := P;
end;

function TDataContext.GetDataPointer(Index: Integer): Pointer;
begin
  Result := DataP[Index];
end;

procedure TDataContext.AddVariantToClear(P: PVarData);
var
  I: Integer;
begin
  for I := 0 to Length(VarToClear) -1 do
    if VarToClear[I] = P then
      Exit;
  I := Length(VarToClear);
  SetLength(VarToClear, I + 1);
  VarToClear[I] := P;
end;

procedure TDataContext.AddStrToClear(P: Pointer);
var
  I: Integer;
begin
  { If this string is in the list already, we're set }
  for I := 0 to Length(StrToClear) -1 do
    if StrToClear[I] = P then
      Exit;
  I := Length(StrToClear);
  SetLength(StrToClear, I + 1);
  StrToClear[I] := P;
end;

constructor TDataContext.Create;
begin
  inherited;
end;

destructor TDataContext.Destroy;
var
  I: Integer;
  P: Pointer;
begin
  { Clean up objects we've allocated }
  for I := 0 to Length(FObjsToDestroy) - 1 do
  begin
     if (FObjsToDestroy[I] <> nil) and (FObjsToDestroy[I].InheritsFrom(TRemotable)) then
     begin
       TRemotable(FObjsToDestroy[I]).Free;
     end;
  end;
  SetLength(FObjsToDestroy, 0);

  { Clean Variants we allocated }
  for I := 0 to Length(VarToClear) - 1 do
  begin
    if Assigned(VarToClear[I]) then
      Variant( PVarData(VarToClear[I])^) := NULL;
  end;
  SetLength(VarToClear, 0);

  { Clean up dynamic arrays we allocated }
  for I := 0 to Length(DynArrayToClear) - 1 do
  begin
    if Assigned(DynArrayToClear[I].P) then
    begin
      P := Pointer( PInteger(DynArrayToClear[I].P)^);
      DynArrayClear(P, DynArrayToClear[I].Info)
    end;
  end;
  SetLength(DynArrayToClear, 0);

  { Clean up strings we allocated }
  for I := 0 to Length(StrToClear) - 1 do
  begin
    if Assigned(StrToClear[I]) then
      PString(StrToClear[I])^ := '';
  end;
  SetLength(StrToClear, 0);

  inherited;
end;

procedure TDataContext.AddDynArrayToClear(P: Pointer; Info: PTypeInfo);
var
  I: Integer;
begin
  for I := 0 to Length(DynArrayToClear) -1 do
    if DynArrayToClear[I].P = P then
      Exit;
  I := Length(DynArrayToClear);
  SetLength(DynArrayToClear, I + 1);
  DynArrayToClear[I].P := P;
  DynArrayToClear[I].Info := Info;
end;

procedure TDataContext.AddObjectToDestroy(Obj: TObject);
var
  Index, EmptySlot: Integer;
begin
  EmptySlot := -1;
  for Index := 0 to Length(FObjsToDestroy) -1 do
  begin
    if FObjsToDestroy[Index] = Obj then
      Exit;
    if FObjsToDestroy[Index] = nil then
      EmptySlot := Index;
  end;
  if EmptySlot <> -1 then
  begin
    FObjsToDestroy[EmptySlot] := Obj;
    Exit;
  end;
  Index := Length(FObjsToDestroy);
  SetLength(FObjsToDestroy, Index + 1);
  FObjsToDestroy[Index] := Obj;
end;

procedure TDataContext.RemoveObjectToDestroy(Obj: TObject);
var
  I: Integer;
begin
  I := 0;
  while I < Length(FObjsToDestroy) do
  begin
    if FObjsToDestroy[I] = Obj then
    begin
      FObjsToDestroy[I] := nil;
      break;
    end;
    Inc(I);
  end;
end;

function TDataContext.AllocData(Size: Integer): Pointer;
begin
  Result := @Data[DataOffset];
  Inc(DataOffset, Size);
end;

{ TInvContext }

const
  MAXINLINESIZE = sizeof(TVarData) + 4;

procedure TInvContext.SetMethodInfo(const MD: TIntfMethEntry);
begin
  SetLength(DataP, MD.ParamCount + 1);
  SetLength(Data, (MD.ParamCount + 1) * MAXINLINESIZE);
end;

procedure TInvContext.SetParamPointer(Param: Integer; P: Pointer);
begin
   SetDataPointer(Param,  P);
end;

function TInvContext.GetParamPointer(Param: Integer): Pointer;
begin
  Result := GetDataPointer(Param);
end;

function TInvContext.GetResultPointer: Pointer;
begin
  Result := ResultP;
end;

procedure TInvContext.SetResultPointer(P: Pointer);
begin
  ResultP := P;
end;

procedure TInvContext.AllocServerData(const MD: TIntfMethEntry);
var
  I: Integer;
  Info: PTypeInfo;
  P: Pointer;
begin
  for I := 0 to MD.ParamCount - 1 do
  begin
    P := AllocData(GetTypeSize(MD.Params[I].Info));
    SetParamPointer(I, P);
    if MD.Params[I].Info.Kind = tkVariant then
    begin
      Variant(PVarData(P)^) := NULL;
      AddVariantToClear(PVarData(P));
    end else if MD.Params[I].Info.Kind = tkDynArray then
    begin
      AddDynArrayToClear(P, MD.Params[I].Info);
    end else if MD.Params[I].Info.Kind = tkLString then
    begin
      PString(P)^ := '';
      AddStrToClear(P);
    end;
  end;
  if MD.ResultInfo <> nil then
  begin
    Info := MD.ResultInfo;
    case Info^.Kind of
      tkLString:
        begin
           P := AllocData(sizeof(PString));
           PString(P)^ := '';
           AddStrToClear(P);
        end;
      tkInt64:
        P := AllocData(sizeof(Int64));
      tkVariant:
        begin
          P := AllocData(sizeof(TVarData));
          Variant( PVarData(P)^ ) := NULL;
          AddVariantToClear(PVarData(P));
        end;
      tkDynArray:
        begin
          P := AllocData(GetTypeSize(Info));
          AddDynArrayToClear(P, MD.ResultInfo);
        end;
      else
        P := AllocData(GetTypeSize(Info));
    end;
    SetResultPointer(P);
  end;
end;

procedure InitBuiltIns;
begin
  { DO NOT LOCALIZE }
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Boolean), XMLSchemaNameSpace, 'boolean');

  RemClassRegistry.RegisterXSInfo(TypeInfo(System.ShortInt), XMLSchemaNameSpace, 'byte');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Byte), XMLSchemaNameSpace, 'unsignedByte');

  RemClassRegistry.RegisterXSInfo(TypeInfo(System.SmallInt), XMLSchemaNameSpace, 'short');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Word), XMLSchemaNameSpace, 'unsignedShort');

  RemClassRegistry.RegisterXSInfo(TypeInfo(System.LongWord), XMLSchemaNameSpace, 'unsignedInt');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Cardinal), XMLSchemaNameSpace, 'unsignedInt');

  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Integer), XMLSchemaNameSpace, 'int');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.LongInt), XMLSchemaNameSpace, 'int');

  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Int64), XMLSchemaNameSpace, 'long');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Int64), XMLSchemaNameSpace, 'unsignedLong');

  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Single), XMLSchemaNameSpace, 'float');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Double), XMLSchemaNameSpace, 'double');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Extended), XMLSchemaNameSpace, 'double');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Currency), XMLSchemaNameSpace, 'double');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Comp), XMLSchemaNameSpace, 'double');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Real), XMLSchemaNameSpace, 'double');

  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'string');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.WideString), XMLSchemaNameSpace, 'string');

  { Other types that we map to string with no validation }
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'anyURI');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'ENTITY');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'ENTITIES');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'gDay');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'gMonth');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'gMonthDay');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'gYear');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'gYearMonth');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'ID');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'IDREF');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'IDREFS');
   RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace,'language');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'Name');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'NMTOKEN');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'NMTOKENS');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'normalizedString');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'NOTATION');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'NCName');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'QName');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiString), XMLSchemaNameSpace, 'token');

  { Native Types that map to XML string }
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.ShortString), XMLSchemaNameSpace, 'string');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.AnsiChar), XMLSchemaNameSpace, 'string');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.WideChar), XMLSchemaNameSpace, 'string');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Char), XMLSchemaNameSpace, 'string');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.WideChar), XMLSchemaNameSpace, 'string');

  RemClassRegistry.RegisterXSInfo(TypeInfo(Types.TByteDynArray), XMLSchemaNameSpace, 'base64Binary');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Variant), XMLSchemaNameSpace, 'anySimpleType');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Variant), XMLSchemaNameSpace, 'anyType');
  RemClassRegistry.RegisterXSInfo(TypeInfo(System.Variant), XMLSchemaNameSpace, 'ur-type');

  RemClassRegistry.RegisterXSInfo(TypeInfo(Types.TByteDynArray), SSoap11EncodingS5, 'base64');

  RemClassRegistry.RegisterXSInfo(TypeInfo(TIntegerDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TCardinalDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TWordDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TSmallIntDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TByteDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TShortIntDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TInt64DynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TLongWordDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TSingleDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TDoubleDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TBooleanDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TStringDynArray), SBorlandTypeNamespace);
  RemClassRegistry.RegisterXSInfo(TypeInfo(TWideStringDynArray), SBorlandTypeNamespace);

end;

initialization
  InvRegistryV := TInvokableClassRegistry.Create;
  RemTypeRegistryV := TRemotableClassRegistry.Create;
  RemClassRegistryV:= RemTypeRegistry;
  InitBuiltIns;
finalization
  InvRegistryV.Free;
  RemClassRegistryV.Free;
end.

