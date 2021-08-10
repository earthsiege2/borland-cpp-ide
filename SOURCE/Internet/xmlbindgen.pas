
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       XML Data Binding Code Generation                }
{                                                       }
{       Copyright (c) 2001 Borland Software Corp.       }
{                                                       }
{*******************************************************}

unit XMLBindGen;

interface

uses
  SysUtils, Classes, Variants, XMLSchema, XMLDoc, XMLIntf, xmldom;

const                                { Do not localize anything in this unit. }
  { AppInfo }
  aiDBWizPrefix = 'xdb';
  aiIdentifierName = 'identifierName';
  aiDataType = 'dataType';
  aiBound = 'bound';
  aiReadOnly = 'ReadOnly';
  aiRepeated = 'repeated';
  aiDocElement = 'docElement';

  { Code }
  SIndex = 'Index';
  SInteger = 'Integer';
  SIndexCode = SIndex + ': ' + SInteger;
  SBegin = 'begin';
  SEnd = 'end;';
  SAdd = 'Add';
  SInsert = 'Insert';
  SOverride = ' override;';
  SPrivate = 'private';
  SProtected = 'protected';
  SPublic = 'public';
  SPublished = 'published';
  STrue = 'True';
  SFalse = 'False';

  { Option Categories }
  SCodeGen = 'CodeGen';
  SDataTypeMap = 'DataTypeMap';

  { Code Gen Options }
  cgPropGetPrefix = 'PropGetPrefix';
  cgPropSetPrefix = 'PropSetPrefix';
  cgClassPrefix = 'ClassPrefix';
  cgInterfacePrefix = 'IntfPrefix';
  cgListTypeSuffix = 'NodeListSuffix';
  cgNodeIntfBase = 'NodeIntfBase';
  cgNodeClassBase = 'NodeClassBase';
  cgCollIntfBase = 'CollIntfBase';
  cgCollClassBase = 'CollClassBase';
  cgDefaultDataType = 'DefDataType';

  NativeTypes: array[0..20] of string = ('string','Variant','WideString',
    'Boolean','Integer','Double','Char','WideChar','Shortint','Smallint',
    'Byte','Word','Extended','Longint','Cardinal','Single','Extended','Comp',
    'Currency','TDateTime','Int64');

resourcestring
  { Comments }
  SPropertyAccessors = '  { Property Accessors }';
  SMethodsAndProps = '  { Methods & Properties }';
  SForwardDecl = 'Forward Decls';
  SGlobalFunctions = 'Global Functions';           

type

  TXMLBindingType = (btComplexType, btSimpleType, btComplexElement,
    btCollectionElement, btSimpleElement, btAttribute, btComplexTypeList,
    btSimpleTypeList, btNone);

  TOptionChangeEvent = procedure(const SectionName, OptionName: string;
    const Value: Variant) of object;

  TBindingOptions = class(TPersistent)
  private
    FSectionName: string;
    FOptions: TStringList;
    FOnOptionChange: TOptionChangeEvent;
    function GetOptionData(const Name: string): TObject;
    procedure SetOptionData(const Name: string; const Value: TObject);
  protected
    procedure SetOption(const Name: string; const Value: Variant);
    property SectionName: string read FSectionName;
    procedure AssignTo(Dest: TPersistent); override;
    procedure DoOptionChange(const OptionName: string; const Value: Variant);
  public
    constructor Create(const SectionName: string;
      OnChangeEvent: TOptionChangeEvent = nil);
    destructor Destroy; override;
    procedure EnsureOption(const OptionStr: string);
    function GetOptionValue(const Name: string): Variant;
    function GetOption(const Name: string; const Default: Variant): Variant;
    procedure InitializeOptions(const Values: array of string); overload;
    procedure InitializeOptions(const Values: TStrings); overload;
    function IsTrue(const Name: string): Boolean;
    property Options[const Name: string]: Variant read GetOptionValue write SetOption; default;
    property OptionData[const Name: string]: TObject read GetOptionData write SetOptionData;
    procedure Assign(Source: TPersistent); override;
    procedure Clear;
    property OnOptionChange: TOptionChangeEvent read FOnOptionChange write FOnOptionChange;
  end;

{ =========================================================================== }
{                     Databinding Interfaces                                  }
{ =========================================================================== }

{ IXMLBindingAppInfo }

  { This interface is used to persist data binding settings into an
    AppInfo node of the source schema document.  It is use by the
    various IXMLBindingInfo interfaces defined below }

  IXMLBindingAppInfo = interface(IXMLAppInfo)
    ['{3FF5455B-C787-4EA8-ADCF-AB0F66874D13}']
    { Property Accessors }
    function GetBindingAppInfoURI: DOMString;
    function GetBound: Variant;
    function GetDataType: Variant;
    function GetDocElement: Variant;
    function GetIdentifierName: Variant;
    function GetPropReadOnly: Variant;
    function GetRepeated: Variant;
    procedure SetBindingAppInfoURI(const Value: DOMString);
    procedure SetBound(const Value: Variant);
    procedure SetDataType(const Value: Variant);
    procedure SetDocElement(const Value: Variant);
    procedure SetIdentifierName(const Value: Variant);
    procedure SetPropReadOnly(const Value: Variant);
    procedure SetRepeated(const Value: Variant);
    { Public Properties & Methods }
    function HasValueFor(const AttrName: DOMString): Boolean;
    procedure RemoveValue(const AttrName: DOMString);
    property BindingAppInfoURI: DOMString read GetBindingAppInfoURI write SetBindingAppInfoURI;
    property Bound: Variant read GetBound write SetBound;
    property DataType: Variant read GetDataType write SetDataType;
    property DocElement: Variant read GetDocElement write SetDocElement;
    property IdentifierName: Variant read GetIdentifierName write SetIdentifierName;
    property PropReadOnly: Variant read GetPropReadOnly write SetPropReadOnly;
    property Repeated: Variant read GetRepeated write SetRepeated;
  end;

{ IXMLBindingInfo }

  { This interface contains the common properties used to bind all schema
    components (complextypes, elements, attributes, etc.) }

  IXMLBindingInfo = interface
    ['{1937F2F8-298E-42A6-983C-EA6BA68D30B8}']
    { Property Accessors }
    function GetBindingType: TXMLBindingType;
    function GetBound: Boolean;
    function GetDataType: string;
    function GetDocumentation: string;
    function GetIdentifierName: string;
    function GetSourceName: string;
    function GetSourceType: string;
    procedure SetBindingType(const Value: TXMLBindingType);
    procedure SetBound(const Value: Boolean);
    procedure SetDataType(const Value: string);
    procedure SetDocumentation(const Value: string);
    procedure SetIdentifierName(const Value: string);
    { Public Methods and Properties }
    property BindingType: TXMLBindingType read GetBindingType write SetBindingType;
    property Bound: Boolean read GetBound write SetBound;
    property DataType: string read GetDataType write SetDataType;
    property Documentation: string read GetDocumentation write SetDocumentation;
    property IdentifierName: string read GetIdentifierName write SetIdentifierName;
    property SourceName: string read GetSourceName;
    property SourceType: string read GetSourceType;
  end;

{ IXMLDataTypeBinding  }

  IXMLDataTypeBinding = interface(IXMLBindingInfo)
    ['{24C2FDBD-58BB-443A-9AD6-9256B9668026}']
    { Property Accessors }
    function GetRepeated: Boolean;
    procedure SetRepeated(const Value: Boolean);
    { Public Methods and Properties }
    function TypeDef: IXMLTypeDef;
    property Repeated: Boolean read GetRepeated write SetRepeated;
  end;

{ IXMLComplexTypeBinding }

  { This interface contains the properties needed to bind a complex type to
    a class/interface definition. }

  IXMLPropertyBinding = interface;
    
  IXMLComplexTypeBinding = interface(IXMLDataTypeBinding)
    ['{87908153-1958-48D0-98CE-B0FF93337113}']
    { Property Accessors }
    function GetDocElementName: DOMString;
    procedure SetDocElementName(const Value: DOMString);
    { Public Methods and Properties }
    function AncestorClass: string;
    function AncestorInterface: string;
    function ClassIdent: string;
    function CollectionItem: IXMLPropertyBinding;
    function CollectionItemName: string;
    function ComplexTypeDef: IXMLComplexTypeDef;
    function IsDocElement: Boolean;
    function PureCollection: Boolean;
    property DocElementName: DOMString read GetDocElementName write SetDocElementName;
  end;

{ IXMLDataTypeListBinding }

  IXMLDataTypeListBinding = interface(IXMLComplexTypeBinding)
    ['{80994C17-4BDE-4A6F-A506-026CE43746BC}']
    function ItemBindInfo: IXMLDataTypeBinding;
  end;

{ IXMLPropertyBinding }

  { This interface contains the properties needed to bind either an attribute
    or an element to a property in class/interface definition }

  IXMLPropertyBinding = interface(IXMLBindingInfo)
    ['{565D9C12-E6E5-4F47-8264-1AF2459D7BBF}']
    { Property Accessors }
    function GetPropReadOnly: Boolean;
    function GetSchemaItem: IXMLTypedSchemaItem;
    procedure SetPropReadOnly(const Value: Boolean);
    procedure SetDataType(const Value: string);
    { Public Methods and Properties }
    function IsListProp: Boolean;
    function TypeBindInfo: IXMLDataTypeBinding;
    property DataType: string read GetDataType write SetDataType;
    property SchemaItem: IXMLTypedSchemaItem read GetSchemaItem;
    property PropReadOnly: Boolean read GetPropReadOnly write SetPropReadOnly; { Element / Attr }
  end;

{ IXMLBindingManager }

  TCodeWriter = class;
  TCodeWriterClass = class of TCodeWriter;
  TIdentifierCheckEvent = procedure(var Identifier: string) of object;

  IXMLBindingManager = interface
    { Property Accessors }
    function GetBindingAppInfoURI: DOMString;
    function GetClassNameStr: string;
    function GetCodeGenOptions: TBindingOptions;
    function GetNativeTypeMap: TBindingOptions;
    procedure SetBindingAppInfoURI(const Value: DOMString);
    procedure SetClassNameStr(const Value: string);
    { Methods and Properties }
    procedure DoIdentifierCheck(var Identifier: string);
    function GetBindableItems(const Schema: IXMLSchemaDef): IInterfaceList;
    function GetBindingInfo(const ASchemaItem: IInterface): IXMLBindingInfo; overload;
    function GetBindingInfo(const TypeDef: IXMLTypeDef): IXMLDataTypeBinding; overload;
    function GetBindingInfo(const ComplexTypeDef: IXMLComplexTypeDef): IXMLComplexTypeBinding; overload;
    function GetBindingInfo(const PropertyItem: IXMLTypedSchemaItem): IXMLPropertyBinding; overload;
    function GetListBindingInfo(const TypeDef: IXMLTypeDef): IXMLDataTypeListBinding;
    function GenerateBinding(const BindableItems: IInterfaceList;
      const Writers: array of TCodeWriterClass): string; overload;
    function GenerateBinding(const BindableItem: IXMLComplexTypeDef;
      const Writers: array of TCodeWriterClass): string; overload;
    procedure SetOnIdentifierCheck(const Value: TIdentifierCheckEvent);
    function SchemaTypeToNativeType(const XMLType: Variant): string;

    property BindingAppInfoURI: DOMString read GetBindingAppInfoURI write
      SetBindingAppInfoURI;
    property ClassNameStr: string read GetClassNameStr write SetClassNameStr;
    property CodeGenOptions: TBindingOptions read GetCodeGenOptions;
    property NativeTypeMap: TBindingOptions read GetNativeTypeMap;
  end;

{ *** Classes *** }

{ TXMLBindingAppInfo }

  TXMLBindingAppInfo = class(TXMLAnnotationItem, IXMLBindingAppInfo)
  private
    FBindingAppInfoURI: DOMString;
  protected
    function GetValue(const AttrName: DOMString): Variant;
    procedure SetValue(const AttrName: DOMString; const Value: Variant);
    { IXMLBindingAppInfo }
    function GetBindingAppInfoURI: DOMString;
    function GetBound: Variant;
    function GetDataType: Variant;
    function GetDocElement: Variant;
    function GetIdentifierName: Variant;
    function GetPropReadOnly: Variant;
    function GetRepeated: Variant;
    function HasValueFor(const AttrName: DOMString): Boolean;
    procedure RemoveValue(const AttrName: DOMString);
    procedure SetBindingAppInfoURI(const Value: DOMString);
    procedure SetBound(const Value: Variant);
    procedure SetDataType(const Value: Variant);
    procedure SetDocElement(const Value: Variant);
    procedure SetIdentifierName(const Value: Variant);
    procedure SetPropReadOnly(const Value: Variant);
    procedure SetRepeated(const Value: Variant);
  end;

{ TXMLBindingInfo }

  TXMLBindingInfo = class(TInterfacedObject, IXMLBindingInfo)
  private
    FBindingManager: IXMLBindingManager;
    FSchemaItem: IXMLSchemaItem;
    FBindingAppInfo: IXMLBindingAppInfo;
  protected
    function GetBindingAppInfo: IXMLBindingAppInfo;
    function HasAppInfo(const AppInfoName: string): Boolean;
    function MakeIdentifier: string; virtual;
    procedure RemoveAppInfo(const AppInfoName: string);
    property BindingManager: IXMLBindingManager read FBindingManager;
  protected
    { IXMLBindingInfo }
    function GetBindingType: TXMLBindingType; virtual; abstract;
    function GetBound: Boolean; virtual;
    function GetDataType: string; virtual; abstract;
    function GetDocumentation: string;
    function GetIdentifierName: string; virtual;
    function GetSourceName: string;
    function GetSourceType: string; virtual; abstract;
    procedure SetBindingType(const Value: TXMLBindingType); virtual;
    procedure SetBound(const Value: Boolean);
    procedure SetDataType(const Value: string);
    procedure SetDocumentation(const Value: string);
    procedure SetIdentifierName(const Value: string); virtual;
    { Data member access }
    property BindingAppInfo: IXMLBindingAppInfo read GetBindingAppInfo;
    property SchemaItem: IXMLSchemaItem read FSchemaItem;
  public
    constructor Create(const ASchemaItem: IXMLSchemaItem;
      const BindingManager: IXMLBindingManager);
  end;


{ TXMLDataTypeBinding }

  TXMLDataTypeBinding = class(TXMLBindingInfo, IXMLDataTypeBinding)
  private
    FTypeDef: IXMLTypeDef;
  protected
    { IXMLDataTypeBinding }
    function GetRepeated: Boolean; virtual;
    function TypeDef: IXMLTypeDef;
    procedure SetRepeated(const Value: Boolean);
  public
    procedure AfterConstruction; override;
  end;

{ TXMLSimpleTypeBinding }

  TXMLSimpleTypeBinding = class(TXMLDataTypeBinding, IXMLDataTypeBinding)
  private
    FSimpleTypeDef: IXMLSimpleTypeDef;
  protected
    { IXMLBindingInfo }
    function GetBindingType: TXMLBindingType; override;
    function GetDataType: string; override;
    function GetIdentifierName: string; override;
    function GetSourceType: string; override;
    function SimpleTypeDef: IXMLSimpleTypeDef;
    procedure SetIdentifierName(const Value: string); override;
  public
    procedure AfterConstruction; override;
  end;

{ TXMLComplexTypeBinding }

  TXMLComplexTypeBinding = class(TXMLDataTypeBinding, IXMLComplexTypeBinding)
  private
    FComplexTypeDef: IXMLComplexTypeDef;
  protected
    function BaseBindingInfo: IXMLComplexTypeBinding;
    function HasComplexBase: Boolean;
    function MakeIdentifier: string; override;
  protected
    { IXMLBindingInfo }
    function GetBindingType: TXMLBindingType; override;
    function GetDataType: string; override;
    function GetSourceType: string; override;
    { IXMLComplexTypeBinding }
    function AncestorClass: string; virtual;
    function AncestorInterface: string; virtual;
    function ClassIdent: string; virtual;
    function CollectionItem: IXMLPropertyBinding;
    function CollectionItemName: string;
    function ComplexTypeDef: IXMLComplexTypeDef;
    function GetDocElementName: DOMString;
    function IsDocElement: Boolean;
    function PureCollection: Boolean;
    procedure SetDocElementName(const Value: DOMString);
  public
    procedure AfterConstruction; override;
  end;

{ TXMLDataTypeListBinding }

  TXMLDataTypeListBinding = class(TXMLComplexTypeBinding, IXMLDataTypeListBinding)
  private
    FListTypeSuffix: string;
    FSimpleType: Boolean;
  protected
    function AncestorClass: string; override;
    function AncestorInterface: string; override;
    function ClassIdent: string; override;
    function CollectionItemName: string;
    function GetIdentifierName: string; override;
    function GetRepeated: Boolean; override;
    function ItemBindInfo: IXMLDataTypeBinding;
    function PureCollection: Boolean;
    property ListTypeSuffix: string read FListTypeSuffix write FListTypeSuffix;
  public
    procedure AfterConstruction; override;
  end;

{ TXMLPropertyBinding }

  TXMLPropertyBinding = class(TXMLBindingInfo, IXMLPropertyBinding)
  private
    FSchemaItem: IXMLTypedSchemaItem;
  protected
    function ReadDataType: string;
    { IXMLBindingInfo }
    function GetBindingType: TXMLBindingType; override;
    function GetBound: Boolean; override;
    function GetDataType: string; override;
    function GetSchemaItem: IXMLTypedSchemaItem;
    function GetSourceType: string; override;
    procedure SetBindingType(const Value: TXMLBindingType); override;
    { IXMLPropertyBinding }
    function TypeBindInfo: IXMLDataTypeBinding;
    function GetPropReadOnly: Boolean;
    function IsListProp: Boolean;
    procedure SetPropReadOnly(const Value: Boolean);
    procedure SetDataType(const Value: string);
  public
    procedure AfterConstruction; override;
  end;

{ =========================================================================== }
{                     Code Generation Classes                                 }
{ =========================================================================== }

{ TCodeWriter }

{ Contains methods used for writing code structures which are common to
  different elements of the generated unit.  This is the base class for
  all other code writers. }

  TCodeWriter = class(TStringList)
  private
    FBindingManager: IXMLBindingManager;
    FModified: Boolean;
  protected
    function PropGetPrefix: string;
    function PropSetPrefix: string;
    property BindingManager: IXMLBindingManager read FBindingManager;
  public
    constructor Create(BindingManager: IXMLBindingManager); reintroduce;
    procedure Generate(const BindingInfo: IXMLComplexTypeBinding); virtual;
    procedure Changed; override;
    procedure Write(const Code: string; Indent: Integer = 0); overload;
    procedure Write(const FmtLine: string; Params: array of const;
      Indent: Integer = 0); overload;
    procedure WriteLine;
    procedure WriteAfterConstruction(const OverrideStr: string = ''; Indent: Integer = 0);
    procedure WriteRegisterChildNode(const TagName, ChildClass: string);
    procedure WriteClassDecl(const Name, AncestorName, IntfName: string);
    procedure WriteCollCreate(const DataMember, CollClass, ItemInterface,
      ItemTag, CollInterface: string);
    procedure WriteCollGetItem(const DataType: string; Indent: Integer = 0);
    procedure WriteCollItemInit(const ItemTag, ItemInterface: string);
    procedure WriteCollItemProp(const DataType: string);
    procedure WriteComment(const Comment: string; Indent: Integer = 0;
      LinePadding: Integer = 0);
    procedure WriteDataMember(const Name, DataType: string);
    procedure WriteDataProperty(const Name, DataType: string; HasWriter: Boolean);
    procedure WriteDeclComment(const Comment: string; LinePadding: Integer = 2);
    procedure WriteFunction(const FuncCode, DataType: string; Indent: Integer = 0); overload;
    procedure WriteFunction(const FuncName, DataType: string;
      const ParamNames, ParamTypes: array of string; Indent: Integer = 0); overload;
    procedure WriteGetMethod(const Name, DataType: string;
      Indent: Integer; Indexed: Boolean = False);
    procedure WriteGetBindFunc(const SourceName, DataType: string);
    procedure WriteLoadBindFunc(const SourceName, DataType: string);
    procedure WriteNewBindFunc(const SourceName, DataType: string);
    procedure WriteGuid;
    procedure WriteIntfDecl(const Name, AncestorType: string);
    procedure WriteMethodBody(const Template: string; Params: array of const);
    procedure WriteProperty(const Name, DataType: string; HasWriter: Boolean;
      Indexed: Boolean = False);
    procedure WriteSetMethod(const Name, DataType: string;
      Indent: Integer; Indexed: Boolean = False);
    property Modified: Boolean read FModified write FModified;
  end;

{ TForwardDecl }

  TForwardDecl = class(TCodeWriter)
  public
    procedure AfterConstruction; override;
  end;

{ TPropertyContainer }

{ Base class for interface and implementation section entries which contain
  property declarations and code. }

  PCodeWriter = ^TCodeWriter;
  TCodeWriterArray = array of TCodeWriter;

  TPropertyContainer = class(TCodeWriter)
  private
    FCodeWriters: TCodeWriterArray;
    FBindingInfo: IXMLComplexTypeBinding;
    FTypeDef: IXMLComplexTypeDef;
  protected
    procedure AppendCode; overload;
    procedure AppendCode(const CodeLists: array of TCodeWriter); overload;
    procedure InitCodeWriters(CodeWriters: array of PCodeWriter;
      CodeLines: array of string);
    procedure WriteCollectionMethods(Writer: TCodeWriter;
      ItemInfo: IXMLDataTypeBinding; Indent: Integer); virtual;
    procedure WriteCollAdd(Writer: TCodeWriter; ItemInfo: IXMLDataTypeBinding;
      Indent: Integer); virtual;
    procedure WriteCollInsert(Writer: TCodeWriter; ItemInfo: IXMLDataTypeBinding;
      Indent: Integer); virtual;
    procedure WriteListBinding(const ItemInfo: IXMLDataTypeBinding); virtual;
    procedure WriteMethods; virtual;
    procedure WriteProperties; virtual;
    procedure WriteProperty(const PropBindInfo: IXMLPropertyBinding;
      const Indexed: Boolean); virtual;
    property BindingInfo: IXMLComplexTypeBinding read FBindingInfo;
    property CodeWriters: TCodeWriterArray read FCodeWriters;
    property TypeDef: IXMLComplexTypeDef read FTypeDef;
  public
    destructor Destroy; override;
    procedure Generate(const BindingInfo: IXMLComplexTypeBinding); override;
  end;

{ TIntfSectionEntry }

{ Base class for Interface and Class Declarations }

  TIntfSectionEntry = class(TPropertyContainer)
  protected
    GetMethods: TCodeWriter;
    SetMethods: TCodeWriter;
    PrivateItems: TCodeWriter;
    ProtectedItems: TCodeWriter;
    PublicItems: TCodeWriter;
    PublishedItems: TCodeWriter;
    procedure WriteDecl; virtual;
  public
    procedure Generate(const BindingInfo: IXMLComplexTypeBinding); override;
  end;

{ TIntfForward }

  TIntfForward = class(TForwardDecl)
  public
    procedure Generate(const BindingInfo: IXMLComplexTypeBinding); override;
  end;

{ TIntfDecl }

  TIntfDecl = class(TIntfSectionEntry)
  protected
    procedure WriteDecl; override;
    procedure WriteListBinding(const ItemInfo: IXMLDataTypeBinding); override;
    procedure WriteProperty(const PropBindInfo: IXMLPropertyBinding;
      const Indexed: Boolean); override;
  end;

{ TClassForward }

  TClassForward = class(TForwardDecl)
  public
    procedure Generate(const BindingInfo: IXMLComplexTypeBinding); override;
  end;

{ TClassDecl }

  TClassDecl = class(TIntfSectionEntry)
  private
    FNeedsRegCode: Boolean;
  protected
    procedure WriteDecl; override;
    procedure WriteListBinding(const ItemInfo: IXMLDataTypeBinding); override;
    procedure WriteProperties; override;
    procedure WriteProperty(const PropBindInfo: IXMLPropertyBinding;
      const Indexed: Boolean); override;
    property NeedsRegCode: Boolean read FNeedsRegCode write FNeedsRegCode;
  end;

{ TXMLBindingManager }

  TXMLBindingManager = class(TInterfacedObject, IXMLBindingManager)
  private
    FBindingAppInfoURI: DOMString;
    FClassNameStr: string;
    FCodeGenOptions: TBindingOptions;
    FNativeTypeMap: TBindingOptions;
    FOnIdentifierCheck: TIdentifierCheckEvent;
  protected
    { IXMLBindingManger Property Accessors }
    function GetClassNameStr: string;
    function GetBindingAppInfoURI: DOMString;
    function GetCodeGenOptions: TBindingOptions;
    function GetNativeTypeMap: TBindingOptions;
    procedure SetBindingAppInfoURI(const Value: DOMString);
    procedure SetClassNameStr(const Value: string);
    { IXMLBindingManager Methods }
    procedure DoIdentifierCheck(var Identifier: string);
    function GetBindableItems(const Schema: IXMLSchemaDef): IInterfaceList;
    function GetBindingInfo(const ASchemaItem: IInterface): IXMLBindingInfo; overload;
    function GetBindingInfo(const TypeDef: IXMLTypeDef): IXMLDataTypeBinding; overload;
    function GetBindingInfo(const ComplexTypeDef: IXMLComplexTypeDef): IXMLComplexTypeBinding; overload;
    function GetBindingInfo(const PropertyItem: IXMLTypedSchemaItem): IXMLPropertyBinding; overload;
    function GetListBindingInfo(const TypeDef: IXMLTypeDef): IXMLDataTypeListBinding;
    function GenerateBinding(const BindableItems: IInterfaceList;
      const Writers: array of TCodeWriterClass): string; overload;
    function GenerateBinding(const BindableItem: IXMLComplexTypeDef;
      const Writers: array of TCodeWriterClass): string; overload;
    function SchemaTypeToNativeType(const XMLType: Variant): string;
    procedure SetOnIdentifierCheck(const Value: TIdentifierCheckEvent);
  public
    destructor Destroy; override;
    procedure AfterConstruction; override;
  end;

procedure MakeValidIdent(var Ident: string);

implementation

uses
  XMLSchemaTags;

const
  DefaultTypeMap: array[0..19] of string = (
    'string=WideString',
    'boolean=Boolean',
    'float=Single',
    'double=Double',
    'number=Double',
    'integer=Integer',
    'nonPositiveInteger=Integer',
    'negativeInteger=Integer',
    'long=Int64',
    'int=Integer',
    'short=SmallInt',
    'byte=ShortInt',
    'nonNegativeInteger=LongWord',
    'unsignedLong=Int64',
    'unsignedInt=LongWord',
    'unsignedShort=Word',
    'unsignedByte=Byte',
    'positiveInteger=LongWord',
    'anySimpleType=Variant',
    'ur-type=Variant');

  DefaultCode: array[0..9] of string = (
    cgPropGetPrefix+'=Get_',
    cgPropSetPrefix+'=Set_',
    cgClassPrefix+'=TXML',
    cgInterfacePrefix+'=IXML',
    cgListTypeSuffix+'=List',
    cgNodeIntfBase+'=IXMLNode',
    cgNodeClassBase+'=TXMLNode',
    cgCollIntfBase+'=IXMLNodeCollection',
    cgCollClassBase+'=TXMLNodeCollection',
    cgDefaultDataType+'=WideString');

{ Utiltity Routines }

{$IFDEF MSWINDOWS}
function CoCreateGuid(out guid: TGUID): HResult; stdcall;
  external 'ole32.dll' name 'CoCreateGuid';

function CreateGuid: TGuid;
begin
  CoCreateGuid(Result);
end;
{$ELSE}
function CreateGuid: TGuid;
begin
  {Need Linux CreateGuid Function}
  Result := GUID_NULL;
end;
{$ENDIF}

procedure MakeValidIdent(var Ident: string);
var
  I: Integer;
begin
  I := 1;
  while I <= Length(Ident) do
  begin
    if Ident[I] in ['A'..'Z','a'..'z','_','0'..'9'] then
      Inc(I)
    else if Ident[I] in LeadBytes then
      Delete(Ident, I, 2)
    else
      Delete(Ident, I, 1);
  end;
end;

{ TBindingOptions }

constructor TBindingOptions.Create(const SectionName: string;
  OnChangeEvent: TOptionChangeEvent = nil);
begin
  FOptions := TStringList.Create;
  FSectionName := SectionName;
  if Assigned(OnChangeEvent) then
    FOnOptionChange := OnChangeEvent;
  inherited Create;
end;

destructor TBindingOptions.Destroy;
var
  I: Integer;
begin
  { We are assumed to be the owner of any
    objects placed into the OptionData properties }
  for I := 0 to FOptions.Count - 1 do
    FOptions.Objects[I].Free;
  FOptions.Free;
  inherited;
end;

procedure TBindingOptions.Assign(Source: TPersistent);
var
  I, ValPos: Integer;
  S: string;
  Strings: TStrings;
begin
  if Source is TStrings then
  begin
    Strings := TStrings(Source);
    for I := 0 to Strings.Count - 1 do
    begin
      S := Strings[I];
      ValPos := Pos('=', S);
      if ValPos > 0 then
        SetOption(Copy(S, 1, ValPos-1), Copy(S, ValPos+1, MAXINT));
    end;
  end
  else
    inherited;
end;

procedure TBindingOptions.AssignTo(Dest: TPersistent);
begin
  if Dest is TStrings then
  begin
    TStrings(Dest).Assign(FOptions)
  end
  else
    inherited;
end;

procedure TBindingOptions.DoOptionChange(const OptionName: string;
  const Value: Variant);
begin
  if Assigned(OnOptionChange) then
    OnOptionChange(SectionName, OptionName, Value);
end;

procedure TBindingOptions.EnsureOption(const OptionStr: string);
var
  ValPos: Integer;
  Name, Value: string;
begin
  ValPos := Pos('=', OptionStr);
  Name := Copy(OptionStr, 1, ValPos-1);
  Value := Copy(OptionStr, ValPos+1, MAXINT);
  { Force option to exist in the list }
  if FOptions.Values[Name] <> Value then
    SetOption(Name, Value);
end;

function TBindingOptions.GetOption(const Name: string; const Default: Variant): Variant;
begin
  Result := FOptions.Values[Name];
  if (Result = '') and (VarToStr(Default) <> '') then
    Result := Default;
end;

function TBindingOptions.GetOptionValue(const Name: string): Variant;
begin
  Result := GetOption(Name, '');
end;

procedure TBindingOptions.SetOption(const Name: string; const Value: Variant);
var
  Index: Integer;
  StrValue: string;
begin
  StrValue := VarToStr(Value);
  if FOptions.Values[Name] = StrValue then Exit;
  if StrValue = '' then
  begin
    Index := FOptions.IndexOfName(Name);
    FOptions[Index] := Name+'=';
  end
  else
    FOptions.Values[Name] := StrValue;
  DoOptionChange(Name, Value);
end;

function TBindingOptions.GetOptionData(const Name: string): TObject;
var
  Index: Integer;
begin
  Index := FOptions.IndexOfName(Name);
  if Index <> -1 then
    Result := FOptions.Objects[Index]
  else
    Result := nil;
end;

procedure TBindingOptions.SetOptionData(const Name: string;
  const Value: TObject);
var
  Index: Integer;
begin
  Index := FOptions.IndexOfName(Name);
  if Index <> -1 then
    FOptions.Objects[Index] := Value;
end;

procedure TBindingOptions.InitializeOptions(const Values: array of string);
var
  I: Integer;
begin
  for I := 0 to High(Values) do
    EnsureOption(Values[I]);
end;

procedure TBindingOptions.InitializeOptions(const Values: TStrings);
var
  I: Integer;
begin
  for I := 0 to Values.Count - 1 do
    EnsureOption(Values[I]);
end;

procedure TBindingOptions.Clear;
begin
  FOptions.Clear;
  DoOptionChange('', VarNull);
end;

function TBindingOptions.IsTrue(const Name: string): Boolean;
var
  Value: Variant;
begin
  Value := GetOption(Name, '');
  Result := Value;
end;

{ TXMLBindingAppInfo }

function TXMLBindingAppInfo.GetValue(const AttrName: DOMString): Variant;
begin
  Result := GetAttributeNS(Attrname, FBindingAppInfoURI);
end;

procedure TXMLBindingAppInfo.SetValue(const AttrName: DOMString;
  const Value: Variant);
begin
  SetAttributeNS(MakeNodeName(aiDBWizPrefix, AttrName), FBindingAppInfoURI, Value);
end;

function TXMLBindingAppInfo.HasValueFor(const AttrName: DOMString): Boolean;
begin
  Result := HasAttribute(AttrName, FBindingAppInfoURI);
end;

procedure TXMLBindingAppInfo.RemoveValue(const AttrName: DOMString);
begin
  AttributeNodes.Delete(AttrName, FBindingAppInfoURI);
end;

function TXMLBindingAppInfo.GetPropReadOnly: Variant;
begin
  Result := GetValue(aiReadOnly);
end;

procedure TXMLBindingAppInfo.SetPropReadOnly(const Value: Variant);
begin
  SetValue(aiReadOnly, Value);
end;

function TXMLBindingAppInfo.GetBindingAppInfoURI: DOMString;
begin
  Result := FBindingAppInfoURI;
end;

procedure TXMLBindingAppInfo.SetBindingAppInfoURI(const Value: DOMString);
begin
  FBindingAppInfoURI := Value;
end;

function TXMLBindingAppInfo.GetBound: Variant;
begin
  Result := GetValue(aiBound);
end;

procedure TXMLBindingAppInfo.SetBound(const Value: Variant);
begin
  SetValue(aiBound, Value);
end;

function TXMLBindingAppInfo.GetIdentifierName: Variant;
begin
  Result := GetValue(aiIdentifierName);
end;

procedure TXMLBindingAppInfo.SetIdentifierName(const Value: Variant);
begin
  SetValue(aiIdentifierName, Value);
end;

function TXMLBindingAppInfo.GetDocElement: Variant;
begin
  Result := GetValue(aiDocElement);
end;

procedure TXMLBindingAppInfo.SetDocElement(const Value: Variant);
begin
  SetValue(aiDocElement, Value);
end;

function TXMLBindingAppInfo.GetDataType: Variant;
begin
  Result := GetValue(aiDataType);
end;

procedure TXMLBindingAppInfo.SetDataType(const Value: Variant);
begin
  SetValue(aiDataType, Value);
end;

function TXMLBindingAppInfo.GetRepeated: Variant;
begin
  Result := GetValue(aiRepeated);
end;

procedure TXMLBindingAppInfo.SetRepeated(const Value: Variant);
begin
  SetValue(aiRepeated, Value);
end;

{ TXMLBindingInfo }

constructor TXMLBindingInfo.Create(const ASchemaItem: IXMLSchemaItem;
  const BindingManager: IXMLBindingManager);
begin
  FSchemaItem := ASchemaItem;
  FBindingManager := BindingManager;
  inherited Create;
end;

function TXMLBindingInfo.HasAppInfo(const AppInfoName: string): Boolean;
begin
  Result := False;
  if not Assigned(FBindingAppInfo) and SchemaItem.HasAnnotation then
    GetBindingAppInfo;
  if Assigned(FBindingAppInfo) then
    Result := FBindingAppInfo.HasValueFor(AppInfoName);
end;

function TXMLBindingInfo.GetBindingAppInfo: IXMLBindingAppInfo;
begin
  if not Assigned(FBindingAppInfo) then
  begin
    FBindingAppInfo := SchemaItem.AppInfo.GetAppInfo(IXMLBindingAppInfo,
      TXMLBindingAppInfo) as IXMLBindingAppInfo;
    FBindingAppInfo.BindingAppInfoURI := BindingManager.BindingAppInfoURI;
  end;
  Result := FBindingAppInfo;
end;

procedure TXMLBindingInfo.RemoveAppInfo(const AppInfoName: string);
begin
  if HasAppInfo(AppInfoName) then
  begin
    BindingAppInfo.RemoveValue(AppInfoName);
    { If we remove the last item then remove the AppInfo element
      and also the Annotation element (if it's empty) }
    if BindingAppInfo.AttributeNodes.Count = 0 then
    begin
      SchemaItem.AppInfo.Remove(BindingAppInfo);
      SchemaItem.RemoveAnnotation;
    end;
  end;
end;

function TXMLBindingInfo.MakeIdentifier: string;
begin
  Result := ExtractLocalName(SchemaItem.Name);
  MakeValidIdent(Result);
  if Result = '' then Exit;
  BindingManager.DoIdentifierCheck(Result);
end;

{ IXMLBindingInfo }

function TXMLBindingInfo.GetDocumentation: string;
begin
  Result := XMLSchema.GetDocumentation(SchemaItem);
end;

procedure TXMLBindingInfo.SetDocumentation(const Value: string);
begin
  if SchemaItem.Documentation.Count = 1 then
    SchemaItem.Documentation[0].NodeValue := Value
  else if SchemaItem.Documentation.Count = 0 then
    SchemaItem.Documentation.Add.NodeValue := Value;
end;

function TXMLBindingInfo.GetIdentifierName: string;
begin
  if HasAppInfo(aiIdentifierName) then
    Result := VarToStr(BindingAppInfo.IdentifierName)
  else
    Result := MakeIdentifier;
end;

procedure TXMLBindingInfo.SetIdentifierName(const Value: string);
begin
  if MakeIdentifier <> Value then
    BindingAppInfo.IdentifierName := Value
  else
    RemoveAppInfo(aiIdentifierName);
end;

function TXMLBindingInfo.GetSourceName: string;
begin
  Result := SchemaItem.Name;
end;

function TXMLBindingInfo.GetBound: Boolean;
begin
  if HasAppInfo(aiBound) then
    Result := BindingAppInfo.Bound
  else
    Result := True;
end;

procedure TXMLBindingInfo.SetBound(const Value: Boolean);
begin
  if not Value then
    BindingAppInfo.Bound := SFalse
  else
    RemoveAppInfo(aiBound);
end;

procedure TXMLBindingInfo.SetDataType(const Value: string);
begin
  Assert(False);
end;

procedure TXMLBindingInfo.SetBindingType(const Value: TXMLBindingType);
begin
  Assert(False);
end;

{ TXMLDataTypeBinding }

procedure TXMLDataTypeBinding.AfterConstruction;
begin
  FTypeDef := SchemaItem as IXMLTypeDef;
  inherited;
end;

function TXMLDataTypeBinding.GetRepeated: Boolean;
begin
  if HasAppInfo(aiRepeated) then
    Result := BindingAppInfo.Repeated
  else
    Result := False;
end;

procedure TXMLDataTypeBinding.SetRepeated(const Value: Boolean);
begin
  if Value then
    BindingAppInfo.Repeated := STrue
  else
    RemoveAppInfo(aiRepeated);
end;

function TXMLDataTypeBinding.TypeDef: IXMLTypeDef;
begin
  Result := FTypeDef;
end;

{ TXMLSimpleTypeBinding }

procedure TXMLSimpleTypeBinding.AfterConstruction;
begin
  FSimpleTypeDef := SchemaItem as IXMLSimpleTypeDef;
  inherited;
end;

function TXMLSimpleTypeBinding.SimpleTypeDef: IXMLSimpleTypeDef;
begin
  Result := FSimpleTypeDef;
end;

function TXMLSimpleTypeBinding.GetBindingType: TXMLBindingType;
begin
  Result := btSimpleType;
end;

function TXMLSimpleTypeBinding.GetDataType: string;
begin
  Result := VarToStr(FSimpleTypeDef.GetAttribute(aiDataType));
  if Result = '' then
    Result := BindingManager.CodeGenOptions[cgNodeIntfBase];
end;

function TXMLSimpleTypeBinding.GetIdentifierName: string;
begin
  if not FSimpleTypeDef.IsBuiltInType then
  begin
    if HasAppInfo(aiIdentifierName) then
      Result := BindingAppInfo.IdentifierName else
      Result := BindingManager.SchemaTypeToNativeType(FSimpleTypeDef.BaseTypeName);
  end
  else
    { For built-in types, there will be no base type }
    Result := BindingManager.SchemaTypeToNativeType(FSimpleTypeDef.Name);
end;

procedure TXMLSimpleTypeBinding.SetIdentifierName(const Value: string);
begin
  if Assigned(FSimpleTypeDef.OwnerDocument) then
  begin
    if BindingManager.SchemaTypeToNativeType(FSimpleTypeDef.BaseTypeName) <> Value then
      BindingAppInfo.IdentifierName := Value else
      RemoveAppInfo(aiIdentifierName);
  end else
    BindingManager.NativeTypeMap[ExtractLocalName(SchemaItem.Name)] := Value;
end;

function TXMLSimpleTypeBinding.GetSourceType: string;
begin
  if FSimpleTypeDef.IsBuiltInType then
    Result := SBuiltInType
  else
    Result := VarToStr(FSimpleTypeDef.BaseTypeName);
end;

{ TXMLComplexTypeBinding }

procedure TXMLComplexTypeBinding.AfterConstruction;
begin
  SchemaItem.QueryInterface(IXMLComplexTypeDef, FComplexTypeDef);
  inherited;
end;

function TXMLComplexTypeBinding.MakeIdentifier: string;
begin
  Result := BindingManager.CodeGenOptions[cgInterfacePrefix] + inherited MakeIdentifier;
end;

function TXMLComplexTypeBinding.BaseBindingInfo: IXMLComplexTypeBinding;
begin
  Result := BindingManager.GetBindingInfo(FComplexTypeDef.BaseType as IXMLComplexTypeDef);
end;

function TXMLComplexTypeBinding.HasComplexBase: Boolean;
begin
  Result := Assigned(FComplexTypeDef) and
    (FComplexTypeDef.DerivationMethod in [dmComplexExtension, dmComplexRestriction]);
end;

function TXMLComplexTypeBinding.AncestorClass: string;
begin
  if HasComplexBase and Assigned(FComplexTypeDef.BaseType) then
    Result := BaseBindingInfo.ClassIdent
  else if PureCollection then
    Result := BindingManager.CodeGenOptions[cgCollClassBase]
  else
    Result := BindingManager.CodeGenOptions[cgNodeClassBase];
end;

function TXMLComplexTypeBinding.AncestorInterface: string;
begin
  if HasComplexBase then
    Result := BaseBindingInfo.IdentifierName
  else if PureCollection then
    Result := BindingManager.CodeGenOptions[cgCollIntfBase]
  else
    Result := BindingManager.CodeGenOptions[cgNodeIntfBase];
end;

function TXMLComplexTypeBinding.ClassIdent: string;
begin
  Result := BindingManager.CodeGenOptions[cgClassPrefix] + inherited MakeIdentifier;
end;

function TXMLComplexTypeBinding.ComplexTypeDef: IXMLComplexTypeDef;
begin
  Result := FComplexTypeDef;
end;

function TXMLComplexTypeBinding.GetDataType: string;
begin
  Result := GetIdentifierName;
end;

function TXMLComplexTypeBinding.GetDocElementName: DOMString;
begin
  if HasAppInfo(aiDocElement) then
    Result := BindingAppInfo.DocElement
  else
    Result := '';
end;

procedure TXMLComplexTypeBinding.SetDocElementName(const Value: DOMString);
begin
  if Value <> '' then
    BindingAppInfo.DocElement := Value
  else
    RemoveAppInfo(aiDocElement);
end;

function TXMLComplexTypeBinding.IsDocElement: Boolean;
begin
  Result := GetDocElementName <> '';
end;

function TXMLComplexTypeBinding.GetSourceType: string;
begin
  if FComplexTypeDef.DerivationMethod <> dmNone then
    Result := FComplexTypeDef.BaseTypeName
  else
    Result := 'ComplexType'; { Do not localize }
end;

function TXMLComplexTypeBinding.GetBindingType: TXMLBindingType;
begin
  Result := btComplexType;
end;

function TXMLComplexTypeBinding.PureCollection: Boolean;
begin
  Result := (FComplexTypeDef.ElementDefList.Count = 1) and
    FComplexTypeDef.ElementDefList[0].IsRepeating;
end;

function TXMLComplexTypeBinding.CollectionItemName: string;
begin
  Result := CollectionItem.IdentifierName;
end;

{ TXMLDataTypeListBinding }

procedure TXMLDataTypeListBinding.AfterConstruction;
begin
  inherited;
  ListTypeSuffix := BindingManager.CodeGenOptions[cgListTypeSuffix];
  FSimpleType := Supports(SchemaItem, IXMLSimpleTypeDef);
end;

function TXMLDataTypeListBinding.AncestorClass: string;
begin
  Result := BindingManager.CodeGenOptions[cgCollClassBase];
end;

function TXMLDataTypeListBinding.AncestorInterface: string;
begin
  Result := BindingManager.CodeGenOptions[cgCollIntfBase];
end;

function TXMLDataTypeListBinding.ClassIdent: string;
begin
  Result := inherited ClassIdent + ListTypeSuffix;
end;

function TXMLDataTypeListBinding.CollectionItemName: string;
begin
  if FSimpleType then
    Result := 'Value' { Do not localize }
  else
    Result := CollectionItem.IdentifierName;
end;

function TXMLDataTypeListBinding.GetIdentifierName: string;
begin
  Result := inherited GetIdentifierName + ListTypeSuffix;
end;

function TXMLDataTypeListBinding.GetRepeated: Boolean;
begin
  Result := False;
end;

function TXMLDataTypeListBinding.ItemBindInfo: IXMLDataTypeBinding;
begin
  Result := BindingManager.GetBindingInfo(TypeDef);
end;

function TXMLComplexTypeBinding.CollectionItem: IXMLPropertyBinding;
begin
  Result := BindingManager.GetBindingInfo(ComplexTypeDef.ElementDefList[0])
end;

function TXMLDataTypeListBinding.PureCollection: Boolean;
begin
  Result := False;
end;

{ TXMLPropertyBinding }

procedure TXMLPropertyBinding.AfterConstruction;
begin
  FSchemaItem := SchemaItem as IXMLTypedSchemaItem;
  inherited;
end;

function TXMLPropertyBinding.TypeBindInfo: IXMLDataTypeBinding;
begin
  Result := BindingManager.GetBindingInfo(FSchemaItem.DataType);
end;

function TXMLPropertyBinding.GetBound: Boolean;
begin
  Result := inherited GetBound;
  if Result then
    Result := BindingManager.GetBindingInfo(FSchemaItem.DataType).Bound;
end;

function TXMLPropertyBinding.ReadDataType: string;
begin
  if IsListProp then
    Result := BindingManager.GetListBindingInfo(FSchemaItem.DataType).IdentifierName
  else
    Result := BindingManager.GetBindingInfo(FSchemaItem.DataType).IdentifierName;
end;

function TXMLPropertyBinding.GetDataType: string;
begin
  if HasAppInfo(aiDataType) then
    Result := BindingAppInfo.DataType
  else
    Result := ReadDataType;
end;

procedure TXMLPropertyBinding.SetDataType(const Value: string);
begin
  if ReadDataType <> Value then
    BindingAppInfo.DataType := Value
  else
    RemoveAppInfo(aiDataType);
end;

function TXMLPropertyBinding.GetPropReadOnly: Boolean;
begin
  if (GetBindingType in [btAttribute, btSimpleElement]) and not HasAppInfo(aiReadOnly) then
    Result := False else
    Result := True;
end;

procedure TXMLPropertyBinding.SetPropReadOnly(const Value: Boolean);
begin
  if Value then
    BindingAppInfo.PropReadOnly := STrue
  else
    RemoveAppInfo(aiReadOnly);
end;

function TXMLPropertyBinding.GetSourceType: string;
begin
  Result := VarToStr(FSchemaItem.DataTypeName);
end;

function TXMLPropertyBinding.GetBindingType: TXMLBindingType;
begin
  if Supports(FSchemaItem, IXMLAttributeDef) then
    Result := btAttribute
  else if (FSchemaItem as IXMLElementDef).IsRepeating then
    Result := btCollectionElement
  else if not FSchemaItem.DataType.IsComplex then
    Result := btSimpleElement
  else
    Result := btComplexElement;
end;

procedure TXMLPropertyBinding.SetBindingType(const Value: TXMLBindingType);
var
  ElementDef: IXMLElementDef;
begin
  if Value <> GetBindingType then
  begin
    ElementDef := FSchemaItem as IXMLElementDef;
    TypeBindInfo.Repeated := (Value = btCollectionElement);
    case value of
      btCollectionElement:
        ElementDef.MaxOccurs := SUnbounded;
      btComplexType:
        ElementDef.MaxOccurs := '1';
    end;
  end;
end;

function TXMLPropertyBinding.IsListProp: Boolean;
begin
  Result := TypeBindInfo.Repeated and
    (GetBindingType in [btCollectionElement])
end;

function TXMLPropertyBinding.GetSchemaItem: IXMLTypedSchemaItem;
begin
  Result := FSchemaItem;
end;

{ =========================================================================== }
{                     Code Generation Classes                                 }
{ =========================================================================== }

{ TCodeWriter }

constructor TCodeWriter.Create(BindingManager: IXMLBindingManager);
begin
  FBindingManager := BindingManager;
  inherited Create;
end;

procedure TCodeWriter.Changed;
begin
  inherited;
  Modified := True;
end;

function TCodeWriter.PropGetPrefix: string;
begin
  Result := VarToStr(BindingManager.CodeGenOptions[cgPropGetPrefix]);
end;

function TCodeWriter.PropSetPrefix: string;
begin
  Result := VarToStr(BindingManager.CodeGenOptions[cgPropSetPrefix]);
end;

procedure TCodeWriter.Generate(const BindingInfo: IXMLComplexTypeBinding);
begin

end;

procedure TCodeWriter.WriteLine;
begin
  Add(''); { Write an empty line }
end;

procedure TCodeWriter.Write(const FmtLine: string;
  Params: array of const; Indent: Integer = 0);
begin
  Add(StringOfChar(' ', 2*Indent)+Format(FmtLine, Params));
end;

procedure TCodeWriter.Write(const Code: string; Indent: Integer = 0);
begin
  Write(Code, [], Indent);
end;

procedure TCodeWriter.WriteComment(const Comment: string; Indent: Integer = 0;
  LinePadding: Integer = 0);
begin
  if LinePadding > 0 then WriteLine;
  Write('{ %s }', [Comment], Indent);
  if LinePadding > 1 then WriteLine;
end;

procedure TCodeWriter.WriteDeclComment(const Comment: string;
  LinePadding: Integer = 2);
begin
  WriteComment(Comment, 0, LinePadding);
end;

procedure TCodeWriter.WriteMethodBody(const Template: string; Params: array of const);
begin
  Write(SBegin);
  Write(Template, Params, 1);
  Write(SEnd);
end;

procedure TCodeWriter.WriteFunction(const FuncCode, DataType: string;
  Indent: Integer = 0);
begin
  Write('function %s%s: %s;', [BindingManager.ClassNameStr, FuncCode, DataType], Indent);
end;

procedure TCodeWriter.WriteFunction(const FuncName, DataType: string;
  const ParamNames, ParamTypes: array of string; Indent: Integer);
var
  I: Integer;
  FuncCode: string;
begin
  FuncCode := FuncName+'(';
  for I := 0 to High(ParamNames) do
    FuncCode := FuncCode + 'const ' + ParamNames[I] + ': '+ ParamTypes[I] + '; ';
  System.Delete(FuncCode, Length(FuncCode)-1, 2);
  FuncCode := FuncCode + ')';
  WriteFunction(FuncCode, DataType, Indent);
end;

procedure TCodeWriter.WriteGetMethod(const Name, DataType: string;
  Indent: Integer; Indexed: Boolean = False);
const
  IndexPart: array[Boolean] of string = ('', '('+SIndexCode+')');
begin
  Write('function %s%s%s%s: %s;', [BindingManager.ClassNameStr,
    PropGetPrefix, Name, IndexPart[Indexed], DataType], Indent);
end;

procedure TCodeWriter.WriteSetMethod(const Name, DataType: string;
  Indent: Integer; Indexed: Boolean = False);
const
  IndexPart: array[Boolean] of string = ('', SIndexCode+'; ');
begin
  Write('procedure %s%s%s(%sValue: %s);', [BindingManager.ClassNameStr,
    PropSetPrefix, Name, IndexPart[Indexed], DataType], Indent);
end;

procedure TCodeWriter.WriteDataProperty(const Name, DataType: string;
  HasWriter: Boolean);
var
  NamePart, Writer: string;
begin
  NamePart := Format('property %s: %s read F%0:s', [Name, DataType]);
  if HasWriter then
    Writer := Format(' write F%s', [Name]);
  Write('%s%s;', [NamePart, Writer], 2);
end;

procedure TCodeWriter.WriteProperty(const Name, DataType: string;
  HasWriter: Boolean; Indexed: Boolean = False);
const
  IndexPart: array[Boolean] of string = ('', '['+SIndexCode+']');
  DefaultPart: array[Boolean] of string = ('', ' default;');
var
  NamePart, Reader, Writer: string;
begin
  NamePart := Format('property %s%s: %s', [Name, IndexPart[Indexed], DataType]);
  Reader := Format(' read %s%s', [PropGetPrefix, Name]);
  if HasWriter then
    Writer := Format(' write %s%s', [PropSetPrefix, Name]);
  Write('%s%s%s;%s', [NamePart, Reader, Writer, DefaultPart[Indexed]], 2);
end;

procedure TCodeWriter.WriteDataMember(const Name, DataType: string);
begin
  Write('F%s: %s;', [Name, DataType], 2);
end;

procedure TCodeWriter.WriteAfterConstruction(const OverrideStr: string = '';
  Indent: Integer = 0);
begin
  Write('procedure %sAfterConstruction;%s', [BindingManager.ClassNameStr,
    OverrideStr], Indent);
end;

procedure TCodeWriter.WriteGetBindFunc(const SourceName, DataType: string);
begin
  Write('function Get%s(Doc: IXMLDocument): %s;', [SourceName, DataType]);
end;

procedure TCodeWriter.WriteLoadBindFunc(const SourceName, DataType: string);
begin
  Write('function Load%s(const FileName: WideString): %s;', [SourceName, DataType]);
end;

procedure TCodeWriter.WriteNewBindFunc(const SourceName, DataType: string);
begin
  Write('function New%s: %s;', [SourceName, DataType]);
end;

procedure TCodeWriter.WriteClassDecl(const Name, AncestorName,
  IntfName: string);
var
  IntfStr: string;
begin
  if IntfName <> '' then IntfStr := ', '+IntfName;
  Write('%s = class(%s%s)', [Name, AncestorName, IntfStr], 1);
end;

procedure TCodeWriter.WriteIntfDecl(const Name, AncestorType: string);
begin
  Write('%s = interface(%s)', [Name, AncestorType], 1);
end;

procedure TCodeWriter.WriteGuid;
begin
  Write('[''%s'']', [GUIDToString(CreateGuid)], 2);
end;

procedure TCodeWriter.WriteCollCreate(const DataMember, CollClass, ItemInterface,
  ItemTag, CollInterface: string);
begin
  Write('F%s := CreateCollection(%s, %s, ''%s'') as %s;',
    [DataMember, CollClass, ItemInterface, ItemTag, CollInterface], 1);
end;

procedure TCodeWriter.WriteCollGetItem(const DataType: string; Indent: Integer = 0);
begin
  WriteFunction(string(BindingManager.CodeGenOptions[cgPropGetPrefix] +
    'Item(' + SIndexCode + ')'),
    DataType, Indent);
end;

procedure TCodeWriter.WriteCollItemInit(const ItemTag, ItemInterface: string);
begin
  Write('ItemTag := ''%s'';', [ItemTag], 1);
  Write('ItemInterface := %s;', [ItemInterface], 1);
end;

procedure TCodeWriter.WriteCollItemProp(const DataType: string);
begin
  Write('property Items[%s]: %s read %sItem; default;',
    [SIndexCode, DataType, PropGetPrefix], 2);
end;

procedure TCodeWriter.WriteRegisterChildNode(const TagName,
  ChildClass: string);
begin
  Write('RegisterChildNode(''%s'', %s);', [TagName, ChildClass], 1);
end;

{ TForwardDecl }

procedure TForwardDecl.AfterConstruction;
begin
  inherited;
  WriteComment(SForwardDecl, 0, 2);
end;

{ TPropertyContainer }

destructor TPropertyContainer.Destroy;
var
  I: Integer;
begin
  inherited;
  for I := High(CodeWriters) downto 0 do
    CodeWriters[I].Free;
end;

procedure TPropertyContainer.Generate(const BindingInfo: IXMLComplexTypeBinding);
begin
  FBindingInfo := BindingInfo;
  FTypeDef := BindingInfo.ComplexTypeDef;
end;

procedure TPropertyContainer.AppendCode(const CodeLists: array of TCodeWriter);
var
  I: Integer;
begin
  for I := 0 to High(CodeLists) do
    if CodeLists[I].Modified then
    begin
      AddStrings(CodeLists[I]);
      CodeLists[I].Clear;
    end;
end;

procedure TPropertyContainer.AppendCode;
begin
  AppendCode(FCodeWriters);
end;

procedure TPropertyContainer.InitCodeWriters(CodeWriters: array of PCodeWriter;
  CodeLines: array of string);
var
  I: Integer;
begin
  Assert(High(CodeWriters) = High(CodeLines));
  if not Assigned(FCodeWriters) then
    SetLength(FCodeWriters, High(CodeWriters) + 1);
  for I := 0 to High(CodeWriters) do
  begin
    if not Assigned(FCodeWriters[I]) then
    begin
      FCodeWriters[I] := TCodeWriter.Create(BindingManager);
      CodeWriters[I]^ := FCodeWriters[I];
    end else
      FCodeWriters[I].Clear;
    if CodeLines[I] <> '' then
    begin
      FCodeWriters[I].Write(CodeLines[I], 1);
      { Reset Modified flag for default code }
      FCodeWriters[I].Modified := False;
    end;
  end;
end;

procedure TPropertyContainer.WriteMethods;
begin
  { PureCollection list methods }
  if BindingInfo.PureCollection then
    with TypeDef.ElementDefList[0] do
      WriteListBinding(BindingManager.GetBindingInfo(DataType));
end;

procedure TPropertyContainer.WriteListBinding(const ItemInfo: IXMLDataTypeBinding);
begin
end;

procedure TPropertyContainer.WriteCollectionMethods(Writer: TCodeWriter;
  ItemInfo: IXMLDataTypeBinding; Indent: Integer);
begin
  WriteCollAdd(Writer, ItemInfo, Indent);
  WriteCollInsert(Writer, ItemInfo, Indent);
  if not BindingInfo.PureCollection then
    Writer.WriteCollGetItem(ItemInfo.IdentifierName, Indent);
end;

procedure TPropertyContainer.WriteCollAdd(Writer: TCodeWriter;
  ItemInfo: IXMLDataTypeBinding; Indent: Integer);
begin
  if ItemInfo.TypeDef.IsComplex then
    Writer.WriteFunction(SAdd, ItemInfo.IdentifierName, Indent)
  else
    Writer.WriteFunction(SAdd, string(BindingManager.CodeGenOptions[cgNodeIntfBase]),
      [BindingInfo.CollectionItemName], [ItemInfo.IdentifierName], Indent);
end;

procedure TPropertyContainer.WriteCollInsert(Writer: TCodeWriter;
  ItemInfo: IXMLDataTypeBinding; Indent: Integer);
begin
  if ItemInfo.TypeDef.IsComplex then
    Writer.WriteFunction(SInsert, ItemInfo.IdentifierName,
      [SIndex], [SInteger], Indent)
  else
    Writer.WriteFunction(SInsert, string(BindingManager.CodeGenOptions[cgNodeIntfBase]),
      [SIndex, BindingInfo.CollectionItemName],
      [SInteger, ItemInfo.IdentifierName], Indent);
end;

procedure TPropertyContainer.WriteProperties;
var
  I: Integer;
  PropBindInfo: IXMLPropertyBinding;
  ListBindInfo: IXMLDataTypeListBinding;
begin
  if Supports(BindingInfo, IXMLDataTypeListBinding, ListBindInfo) then
    WriteListBinding(ListBindInfo.ItemBindInfo)
  else
  begin
    { Attributes }
    for I := 0 to TypeDef.AttributeDefList.Count - 1 do
    begin
      PropBindInfo := BindingManager.GetBindingInfo(TypeDef.AttributeDefList[I]);
      if PropBindInfo.Bound then
        WriteProperty(PropBindInfo, False);
    end;
    { Elements }
    for I := 0 to TypeDef.ElementDefList.Count - 1 do
    begin
      PropBindInfo := BindingManager.GetBindingInfo(TypeDef.ElementDefList[I]);
      if PropBindInfo.Bound then
        WriteProperty(PropBindInfo, BindingInfo.PureCollection);
    end;
  end;
end;

procedure TPropertyContainer.WriteProperty(
  const PropBindInfo: IXMLPropertyBinding; const Indexed: Boolean);
begin
end;

{ TIntfSectionEntry }

procedure TIntfSectionEntry.Generate(const BindingInfo: IXMLComplexTypeBinding);
begin
  inherited;
  BindingManager.ClassNameStr := '';
  WriteDecl;
  WriteMethods;
  WriteProperties;
  AppendCode;
  Write(SEnd, 1);
end;

procedure TIntfSectionEntry.WriteDecl;
begin
  WriteDeclComment(BindingInfo.ClassIdent);
end;

{ TIntfForward }

procedure TIntfForward.Generate(const BindingInfo: IXMLComplexTypeBinding);
begin
  Write('%s = interface;', [BindingInfo.IdentifierName], 1);
end;

{ TIntfDecl }

procedure TIntfDecl.WriteDecl;
begin
  InitCodeWriters([@GetMethods, @SetMethods, @PublicItems],
    [SPropertyAccessors, '', SMethodsAndProps]);
  with BindingInfo do
  begin
    WriteDeclComment(IdentifierName);
    WriteIntfDecl(IdentifierName, AncestorInterface);
    WriteGuid;
  end;
end;

procedure TIntfDecl.WriteProperty(const PropBindInfo: IXMLPropertyBinding;
  const Indexed: Boolean);
begin
  with PropBindInfo do
  begin
    GetMethods.WriteGetMethod(IdentifierName, DataType, 2, Indexed);
    if not PropReadOnly then
      SetMethods.WriteSetMethod(IdentifierName, DataType, 2, Indexed);
    PublicItems.WriteProperty(IdentifierName, DataType, not PropReadOnly, Indexed);
  end;
end;

procedure TIntfDecl.WriteListBinding(const ItemInfo: IXMLDataTypeBinding);
begin
  WriteCollectionMethods(PublicItems, ItemInfo, 2);
  if not BindingInfo.PureCollection then
    PublicItems.WriteCollItemProp(ItemInfo.IdentifierName);
end;

{ TClassForward }

procedure TClassForward.Generate(const BindingInfo: IXMLComplexTypeBinding);
begin
  Write('%s = class;', [BindingInfo.ClassIdent], 1);
end;

{ TClassDecl }

procedure TClassDecl.WriteDecl;
begin
  inherited;
  InitCodeWriters([@PrivateItems, @GetMethods, @SetMethods,
    @ProtectedItems, @PublicItems],
    [SPrivate, '', '', '', SPublic]);
  NeedsRegCode := False;
  with BindingInfo do
    WriteClassDecl(ClassIdent, AncestorClass, IdentifierName);
  GetMethods.Write(SProtected, 1);
  GetMethods.WriteComment(BindingInfo.IdentifierName, 2);
end;

procedure TClassDecl.WriteProperty(const PropBindInfo: IXMLPropertyBinding;
  const Indexed: Boolean);
begin
  with PropBindInfo do
  begin
    GetMethods.WriteGetMethod(IdentifierName, DataType, 2, Indexed);
    if not PropReadOnly then
      SetMethods.WriteSetMethod(IdentifierName, DataType, 2, Indexed);
    if BindingType in [btComplexElement, btCollectionElement] then
      NeedsRegCode := True;
    if (BindingType = btCollectionElement) and not BindingInfo.PureCollection then
      PrivateItems.WriteDataMember(IdentifierName, DataType);
  end;
end;

procedure TClassDecl.WriteProperties;
begin
  inherited;
  if NeedsRegCode then
    PublicItems.WriteAfterConstruction(SOverride, 2);
end;

procedure TClassDecl.WriteListBinding(const ItemInfo: IXMLDataTypeBinding);
begin
  WriteCollectionMethods(ProtectedItems, ItemInfo, 2);
end;

{ TXMLBindingManager }

procedure TXMLBindingManager.AfterConstruction;
begin
  FBindingAppInfoURI := SHttp+'/www.borland.com/schemas/delphi/6.0/XMLDataBinding';
  FCodeGenOptions := TBindingOptions.Create(SCodeGen);
  FCodeGenOptions.InitializeOptions(DefaultCode);
  FNativeTypeMap := TBindingOptions.Create(SDataTypeMap);
  FNativeTypeMap.InitializeOptions(DefaultTypeMap);
  inherited;
end;

destructor TXMLBindingManager.Destroy;
begin
  FreeAndNil(FNativeTypeMap);
  FreeAndNil(FCodeGenOptions);
  inherited;
end;

function TXMLBindingManager.GetBindableItems(const Schema: IXMLSchemaDef): IInterfaceList;
var
  RepeatedSimpleTypes: IInterfaceList;

  procedure AddDataType(const DataType: IXMLComplexTypeDef; Repeated: Boolean);
  var
    I: Integer;
    BindingInfo: IXMLComplexTypeBinding;
  begin
    BindingInfo := GetBindingInfo(DataType);
    if Repeated then
      BindingInfo.Repeated := True;
    if Result.IndexOf(DataType) = -1 then
    begin
      Result.Add(DataType);
      for I := 0 to DataType.ElementDefList.Count - 1 do
        with DataType.ElementDefList[I] do
          if DataType.IsComplex then
            AddDataType(DataType as IXMLComplexTypeDef, IsRepeating and not
               BindingInfo.PureCollection)
          { SimpleType }
          else if IsRepeating and not BindingInfo.PureCollection then
          begin
            GetBindingInfo(DataType).Repeated := True;
            if RepeatedSimpleTypes.IndexOf(DataType) = -1 then
              RepeatedSimpleTypes.Add(DataType);
          end;
    end;
  end;

  procedure CheckOrderDependencies;
  var
    I, BaseIndex: Integer;
    BaseType: IXMLComplexTypeDef;
    ComplexType: IXMLComplexTypeDef;
  begin
    I := 0;
    while (I < Result.Count) and Supports(Result[I], IXMLComplexTypeDef, ComplexType) do
    begin
      if (ComplexType.BaseType <> nil) and ComplexType.BaseType.IsComplex then
      begin
        BaseType := ComplexType.BaseType as IXMLComplexTypeDef;
        BaseIndex := Result.IndexOf(BaseType);
        if BaseIndex > I then
        begin
          Result.Exchange(I, BaseIndex);
          Dec(I);
        end;
      end;
      Inc(I);
    end;
  end;

var
  I: Integer;
begin
  Result := TInterfaceList.Create;
  RepeatedSimpleTypes := TInterfaceList.Create;
  { First iterate global elements and get the complex types there }
  for I := 0 to Schema.ElementDefs.Count - 1 do
    with Schema.ElementDefs[I] do
      if DataType.IsComplex then
        AddDataType(DataType as IXMLComplexTypeDef, IsRepeating);
  { Next iterate global Complex types and get any nested local types as well }
  for I := 0 to Schema.ComplexTypes.Count - 1 do
    AddDataType(Schema.Complextypes[I], False);
  CheckOrderDependencies;
  { Append any repeated simple types so we can create collections for them too }
  for I := 0 to RepeatedSimpleTypes.Count - 1 do
    Result.Add(RepeatedSimpleTypes[I]);
end;


function TXMLBindingManager.GetBindingInfo(const ASchemaItem: IInterface): IXMLBindingInfo;
var
  TypeDef: IXMLTypeDef;
  TypedItem: IXMLTypedSchemaItem;
begin
  if Supports(ASchemaItem, IXMLTypeDef, TypeDef) then
    Result := GetBindingInfo(TypeDef)
  else if Supports(ASchemaItem, IXMLTypedSchemaItem, TypedItem) then
    Result := GetBindingInfo(TypedItem);
  Assert(Assigned(Result));
end;

function TXMLBindingManager.GetBindingInfo(const TypeDef: IXMLTypeDef): IXMLDataTypeBinding;
begin
  if TypeDef.IsComplex then
    Result := TXMLComplexTypeBinding.Create(TypeDef as IXMLComplexTypeDef, Self)
  else
    Result := TXMLSimpleTypeBinding.Create(TypeDef as IXMLSimpleTypeDef, Self);
end;

function TXMLBindingManager.GetBindingInfo(const ComplexTypeDef: IXMLComplexTypeDef): IXMLComplexTypeBinding;
begin
  Result := TXMLComplexTypeBinding.Create(ComplexTypeDef, Self);
end;

function TXMLBindingManager.GetBindingInfo(const PropertyItem: IXMLTypedSchemaItem): IXMLPropertyBinding;
begin
  Result := TXMLPropertyBinding.Create(PropertyItem, Self);
end;

function TXMLBindingManager.GetListBindingInfo(const TypeDef: IXMLTypeDef): IXMLDataTypeListBinding;
begin
  Result := TXMLDataTypeListBinding.Create(TypeDef, Self);
end;

function TXMLBindingManager.SchemaTypeToNativeType(const XMLType: Variant): string;
begin
  if not VarIsNull(XMLType) then
    Result := FNativeTypeMap[ExtractLocalName(XMLType)];
  if Result = '' then
    Result := FCodeGenOptions[cgDefaultDataType];
end;

procedure TXMLBindingManager.DoIdentifierCheck(var Identifier: string);
begin
  if Assigned(FOnIdentifierCheck) then
    FOnIdentifierCheck(Identifier);
end;

function TXMLBindingManager.GenerateBinding(const BindableItems: IInterfaceList;
  const Writers: array of TCodeWriterClass): string;
var
  CodeWriters: TCodeWriterArray;

  procedure CreateCodeWriters;
  var
    I: Integer;
  begin
    SetLength(CodeWriters, High(Writers) + 1);
    for I := 0 to High(Writers) do
      CodeWriters[I]:= Writers[I].Create(Self);
  end;

  procedure FreeCodeWriters;
  var
    I: Integer;
  begin
    for I := High(CodeWriters) downto 0 do
      CodeWriters[I].Free;
    CodeWriters := nil;
  end;

  procedure DoGenerate(const BindingInfo: IXMLComplexTypeBinding);
  var
    I: Integer;
  begin
    for I := 0 to High(CodeWriters) do
      CodeWriters[I].Generate(BindingInfo);
    { Genereate a list type as needed }
    if BindingInfo.Repeated then
      DoGenerate(GetListBindingInfo(BindingInfo.ComplexTypeDef));
  end;

var
  I: Integer;
  ComplexTypeDef: IXMLComplexTypeDef;
  ComplexBinding: IXMLComplexTypeBinding;
begin
  Result := '';
  CreateCodeWriters;
  for I := 0 to BindableItems.Count - 1 do
  begin
    if Supports(BindableItems[I], IXMLComplexTypeDef, ComplexTypeDef) then
    begin
      ComplexBinding := GetBindingInfo(ComplexTypeDef);
      if ComplexBinding.Bound then
        DoGenerate(ComplexBinding);
    end else
      DoGenerate(GetListBindingInfo(BindableItems[I] as IXMLTypeDef));
  end;
  { Concatenate all of the code writer code into list }
  for I := 0 to High(CodeWriters) do
    Result := Result + CodeWriters[I].Text;
  FreeCodeWriters;
end;

function TXMLBindingManager.GenerateBinding(const BindableItem: IXMLComplexTypeDef;
  const Writers: array of TCodeWriterClass): string;
var
  ItemList: IInterfaceList;
begin
  ItemList := TInterfaceList.Create;
  ItemList.Add(BindableItem);
  Result := GenerateBinding(ItemList, Writers);
end;

{ Property Accessors }

function TXMLBindingManager.GetBindingAppInfoURI: DOMString;
begin
  Result := FBindingAppInfoURI;
end;

function TXMLBindingManager.GetCodeGenOptions: TBindingOptions;
begin
  Result := FCodeGenOptions;
end;

function TXMLBindingManager.GetNativeTypeMap: TBindingOptions;
begin
  Result := FNativeTypeMap;
end;

procedure TXMLBindingManager.SetBindingAppInfoURI(const Value: DOMString);
begin
  FBindingAppInfoURI := Value;
end;

procedure TXMLBindingManager.SetOnIdentifierCheck(const Value: TIdentifierCheckEvent);
begin
  FOnIdentifierCheck := Value;
end;

function TXMLBindingManager.GetClassNameStr: string;
begin
  Result := FClassNameStr;
end;

procedure TXMLBindingManager.SetClassNameStr(const Value: string);
begin
  FClassNameStr := Value;
end;

end.

