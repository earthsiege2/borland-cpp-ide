
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       SOAP WSDL XML Data Binding                      }
{                                                       }
{  Copyright (c) 2001 Borland Software Corporation      }
{                                                       }
{*******************************************************}

unit WSDLBind;

interface

{$IFDEF MSWINDOWS}
{ URLMON.H defines another IBinding and references the type...
  The compiler must see this before it sees the IBinding
  introduced in this unit - otherwise, references will cause
  ambiguity errors }
(*$HPPEMIT '#include <urlmon.h>' *)
{$ENDIF}


uses xmldom, XMLDoc, XMLIntf, XMLSchema;

const
  SBinding = 'binding';
  SDefinitions = 'definitions';
  SFault = 'fault';
  SImport = 'import';
  SInput = 'input';
  SLocation = 'location';
  SMessage = 'message';
  SNamespace = 'namespace';
  SOperation = 'operation';
  SOutput = 'output';
  SPart = 'part';
  SPort = 'port';
  SPortType = 'portType';
  SService = 'service';
  SType = 'type';
  STypes = 'types';

type

{ Forward Declarations }

  IDocumentation = interface;
  IDocumentationCollection = interface;
  IDocumented = interface;

  IImport = interface;
  IImports = interface;

  ITypes = interface;

  IPart = interface;
  IParts = interface;
  IMessage = interface;
  IMessages = interface;

  IParam = interface;
  IFault = interface;
  IFaults = interface;
  IOperation = interface;
  IOperations = interface;
  IPortType = interface;
  IPortTypes = interface;

  IBindingOperation = interface;
  IBindingOperations = interface;
  IBinding = interface;
  IBindings = interface;

  IPort = interface;
  IPorts = interface;
  IService = interface;
  IServices = interface;

  IDefinition = interface;
  IWSDLDocument = interface;

{ IDocumentation }

// To disambiguiate between IXMLDocument in msxml.h and the
// one defined in Xmlintf.pas
{$IFDEF MSWINDOWS}
(*$HPPEMIT 'namespace Wsdlbind {'         *)
(*$HPPEMIT 'using Xmlintf::IXMLDocument;'  *)
(*$HPPEMIT '};'                            *)
{$ENDIF}

  IDocumentation = interface(IXMLNode)
    ['{22E6AC24-DEC1-4EB6-A305-C966250CD56F}']
  end;

{ IDocumentationCollection }

  IDocumentationCollection = interface(IXMLNodeCollection)
    ['{2BA090C5-A91E-42BA-928B-75FB816B195F}']
    { Property Accessors }
    function GetDocumentation(Index: Integer): IDocumentation;
    { Methods & Properties }
    function Add(const Text: WideString): IDocumentation;
    function Insert(Index: Integer): IDocumentation;
    property Documentation[Index: Integer]: IDocumentation read GetDocumentation; default;
  end;

{ IDocumented }

  IDocumented = interface(IXMLNode)
    ['{DC197A33-3BB6-4415-A1E1-995FB3BE35A9}']
    { Property Accessors }
    function GetDocumentationCollection: IDocumentationCollection;
    { Methods & Properties }
    property Documentation: IDocumentationCollection read GetDocumentationCollection;
  end;

{ IImport }

  IImport = interface(IDocumented)
    ['{B50B5058-46EA-46CE-A737-23ECE26F5711}']
    { Property Accessors }
    function GetNamespace: WideString;
    function GetLocation: WideString;
    procedure SetNamespace(Value: WideString);
    procedure SetLocation(Value: WideString);
    { Methods & Properties }
    property Namespace: WideString read GetNamespace write SetNamespace;
    property Location: WideString read GetLocation write SetLocation;
  end;

{ IImports }

  IImports = interface(IXMLNodeCollection)
    ['{2BA090C5-A91E-42BA-928B-75FB816B195F}']
    { Property Accessors }
    function GetImport(Index: Integer): IImport;
    { Methods & Properties }
    function Add(const Namespace, Location: WideString): IImport;
    function Insert(Index: Integer): IImport;
    property Import[Index: Integer]: IImport read GetImport; default;
  end;

{ IXMLSchemaDefs }

  IXMLSchemaDefs = interface(IXMLNodeCollection)
    ['{9657EAAE-DEC2-4A79-AED1-9114578F72BC}']
    { Property Accessors }
    function GetXMLSchemaDef(Index: Integer): IXMLSchemaDef;
    { Methods & Properties }
    function Add(const NamespaceURI: WideString = '';
      const TargetNamespace: WideString = ''): IXMLSchemaDef;
    property SchemaDef[Index: Integer]: IXMLSchemaDef read GetXMLSchemaDef; default;
  end;

{ ITypes }

  ITypes = interface(IDocumented)
    ['{AAB2EBF2-79E2-42AA-A3D2-5C4ADCF51B93}']
    { Property Accessors }
    function GetSchemaDefs: IXMLSchemaDefs;
    { Methods & Properties }
    property SchemaDefs: IXMLSchemaDefs read GetSchemaDefs;
  end;

{ IPartType }

  IPart = interface(IDocumented)
    ['{EFD70258-38DE-4BF8-B503-C17022588EAF}']
    { Property Accessors }
    function GetName: WideString;
    function GetType_: WideString;
    function GetElement: WideString;
    procedure SetName(Value: WideString);
    procedure SetType_(Value: WideString);
    procedure SetElement(Value: WideString);
    { Methods & Properties }
    property Name: WideString read GetName write SetName;
    property Type_: WideString read GetType_ write SetType_;
    property Element: WideString read GetElement write SetElement;
  end;

{ IParts }

  IParts = interface(IXMLNodeCollection)
    ['{7D69B10B-77BA-43AE-8581-F2A5E3B36C95}']
    { Property Accessors }
    function GetPart(Index: Integer): IPart;
    { Methods & Properties }
    function Add(const Name, Element: WideString; const AType: WideString = ''): IPart;
    function Insert(Index: Integer): IPart;
    property Part[Index: Integer]: IPart read GetPart; default;
  end;

{ IMessageType }

  IMessage = interface(IDocumented)
    ['{6DD2446C-7E8C-4CBA-BCB0-C318EFFE722A}']
    { Property Accessors }
    function GetName: WideString;
    function GetParts: IParts;
    procedure SetName(Value: WideString);
    { Methods & Properties }
    property Name: WideString read GetName write SetName;
    property Parts: IParts read GetParts;
  end;

{ IMessages }

  IMessages = interface(IXMLNodeCollection)
    ['{1716B6D5-6087-4DB3-B729-1003C7424C2B}']
    { Property Accessors }
    function GetMessage(Index: Integer): IMessage;
    { Methods & Properties }
    function Add(const Name: WideString): IMessage;
    function Insert(Index: Integer): IMessage;
    property Message[Index: Integer]: IMessage read GetMessage; default;
  end;

{ IParam }

  IParam = interface(IDocumented)
    ['{66FF002F-6534-421F-93B8-57FDADBE23B5}']
    { Property Accessors }
    function GetName: WideString;
    function GetMessage: WideString;
    procedure SetName(Value: WideString);
    procedure SetMessage(Value: WideString);
    { Methods & Properties }
    property Name: WideString read GetName write SetName;
    property Message: WideString read GetMessage write SetMessage;
  end;

{ IFault }

  IFault = interface(IParam)
    ['{6B1A1E80-231D-4D0C-AFB9-9E2ECBC5A323}']
  end;

  IFaults = interface(IXMLNodeCollection)
    ['{67FD5C06-F745-4AD1-8B12-92552EA4AB92}']
    { Property Accessors }
    function GetFault(Index: Integer): IFault;
    { Methods & Properties }
    function Add(const Name, Message: WideString): IFault;
    function Insert(Index: Integer): IFault;
    property Fault[Index: Integer]: IFault read GetFault; default;
  end;

{ IOperation }

  IOperation = interface(IDocumented)
    ['{84BC9B4C-019A-4614-A050-A0BB165E7CC2}']
    { Property Accessors }
    function GetName: WideString;
    function GetInput: IParam;
    function GetOutput: IParam;
    function GetFaults: IFaults;
    procedure SetName(Value: WideString);
    { Methods & Properties }
    property Name: WideString read GetName write SetName;
    property Input: IParam read GetInput;
    property Output: IParam read GetOutput;
    property Faults: IFaults read GetFaults;
  end;

{ IOperations }

  IOperations = interface(IXMLNodeCollection)
    ['{52270B19-5C86-4C77-AF4F-A620655ED9E2}']
    { Property Accessors }
    function GetOperation(Index: Integer): IOperation;
    { Methods & Properties }
    function Add(const Name: WideString): IOperation; overload;
    // Review with Ramesh....
    function Add(const Name, InputMessage, InputName, OutputMessage: WideString): IOperation; overload;
    function Insert(Index: Integer): IOperation;
    property Operation[Index: Integer]: IOperation read GetOperation; default;
  end;

{ IPortType }

  IPortType = interface(IDocumented)
    ['{53334349-D65E-44A6-8FBA-3694418BA70A}']
    { Property Accessors }
    function GetName: WideString;
    function GetOperations: IOperations;
    procedure SetName(Value: WideString);
    { Methods & Properties }
    property Name: WideString read GetName write SetName;
    property Operations: IOperations read GetOperations;
  end;

{ IPortTypes }

  IPortTypes = interface(IXMLNodeCollection)
    ['{5A702461-CE49-44FE-A665-74E7D3974FBE}']
    { Property Accessors }
    function GetPortType(Index: Integer): IPortType;
    { Methods & Properties }
    function Add(const Name: WideString): IPortType;
    function Insert(Index: Integer): IPortType;
    property PortType[Index: Integer]: IPortType read GetPortType; default;
  end;

{ IBindingInput }

  IBindingInput = interface(IParam)
    ['{B4EB7EA0-A298-4527-BF5B-DCC6DD36EE12}']
  end;

{ IBindingOutput }

  IBindingOutput = interface(IParam)
    ['{EEA06E96-EF0D-409D-BBE2-DFE554C50F23}']
  end;

{ IBinding_operationType }

  IBindingOperation = interface(IDocumented)
    ['{2A4A10F1-269F-427C-9FAC-305B53743F8B}']
    { Property Accessors }
    function GetName: WideString;
    function GetInput: IBindingInput;
    function GetOutput: IBindingOutput;
    function GetFaults: IFaults;
    procedure SetName(Value: WideString);
    { Methods & Properties }
    property Name: WideString read GetName write SetName;
    property Input: IBindingInput read GetInput;
    property Output: IBindingOutput read GetOutput;
    property Faults: IFaults read GetFaults;
  end;

{ IBindingOperations }

  IBindingOperations = interface(IXMLNodeCollection)
    ['{D579620B-8339-4271-98A4-D3FDBAF3B0A6}']
    { Property Accessors }
    function GetBindingOperation(Index: Integer): IBindingOperation;
    { Methods & Properties }
    function Add(const Name: WideString): IBindingOperation;
    function Insert(Index: Integer): IBindingOperation;
    property BindingOperation[Index: Integer]: IBindingOperation
      read GetBindingOperation; default;
  end;

{ IBinding }

  IBinding = interface(IDocumented)
    ['{1910D8C3-7492-405E-9D9F-62311D24B603}']
    { Property Accessors }
    function GetBindingOperations: IBindingOperations;
    function GetName: WideString;
    function GetType_: WideString;
    procedure SetName(Value: WideString);
    procedure SetType_(Value: WideString);
    { Methods & Properties }
    property BindingOperations: IBindingOperations read GetBindingOperations;
    property Name: WideString read GetName write SetName;
    property Type_: WideString read GetType_ write SetType_;
  end;

{ IBindings }

  IBindings = interface(IXMLNodeCollection)
    ['{C8FE02C7-D726-4214-9FF4-90782EB7ACCA}']
    { Property Accessors }
    function GetBinding(Index: Integer): IBinding;
    { Methods & Properties }
    function Add(const Name, AType: WideString): IBinding;
    function Insert(Index: Integer): IBinding;
    property Binding[Index: Integer]: IBinding
      read GetBinding; default;
  end;

{ IPort }

  IPort = interface(IDocumented)
    ['{10D0E981-A053-4C0F-AE5A-785D2B0D97FD}']
    { Property Accessors }
    function GetName: WideString;
    function GetBinding: WideString;
    procedure SetName(Value: WideString);
    procedure SetBinding(Value: WideString);
    { Methods & Properties }
    property Name: WideString read GetName write SetName;
    property Binding: WideString read GetBinding write SetBinding;
  end;

{ IPorts }

  IPorts = interface(IXMLNodeCollection)
    ['{360DDA1F-E58E-4355-8711-25140D488497}']
    { Property Accessors }
    function GetPort(Index: Integer): IPort;
    { Methods & Properties }
    function Add(const Name, ABinding: WideString): IPort;
    function Insert(Index: Integer): IPort;
    property Port[Index: Integer]: IPort read GetPort; default;
  end;

{ IService }

  IService = interface(IDocumented)
    ['{360DDA1F-E58E-4355-8711-25140D488497}']
    { Property Accessors }
    function GetName: WideString;
    function GetPorts: IPorts;
    procedure SetName(Value: WideString);
    { Methods & Properties }
    property Name: WideString read GetName write SetName;
    property Ports: IPorts read GetPorts;
  end;

{ IServices }

  IServices = interface(IXMLNodeCollection)
    ['{A791AA0C-C8C5-48A1-8B6A-DEF9302B7E17}']
    { Property Accessors }
    function GetService(Index: Integer): IService;
    { Methods & Properties }
    function Add(const Name: WideString): IService;
    function Insert(Index: Integer): IService;
    property Service[Index: Integer]: IService read GetService; default;
  end;

{ IDefinition }

  IDefinition = interface(IXMLNode)
    ['{F3DF8F67-804A-40C4-A6C6-EDFBEA22FC47}']
    { Property Accessors }
    function GetTargetNamespace: WideString;
    function GetName: WideString;
    function GetImports: IImports;
    function GetTypes: ITypes;
    function GetMessages: IMessages;
    function GetPortTypes: IPortTypes;
    function GetBindings: IBindings;
    function GetServices: IServices;
    procedure SetTargetNamespace(Value: WideString);
    procedure SetName(Value: WideString);
    { Methods & Properties }
    property Name: WideString read GetName write SetName;
    property TargetNamespace: WideString read GetTargetNamespace write SetTargetNamespace;
    property Imports: IImports read GetImports;
    property Types: ITypes read GetTypes; // Read/write?
    property Messages: IMessages read GetMessages;
    property PortTypes: IPortTypes read GetPortTypes;
    property Bindings: IBindings read GetBindings;
    property Services: IServices read GetServices;
  end;

{ IWSDLDocument }

  IWSDLDocument = interface(IXMLDocument)
    { Property Accessors }
    function GetDefinition: IDefinition;
    procedure SetDefinition(const Value: IDefinition);
    { Methods & Properties }
    property Definition: IDefinition read GetDefinition write SetDefinition;
  end;

{ ======================================================================== }
{                          Implementing Classes                            }
{ ======================================================================== }

{ Forward Declarations }

  TDocumentation = class;
  TDocumentationCollection = class;
  TDocumented = class;

  TImport = class;
  TImports = class;

  TTypes = class;

  TPart = class;
  TParts = class;
  TMessage = class;
  TMessages = class;

  TParam = class;
  TFaults = class;
  TOperation = class;
  TPortType = class;
  TPortTypes = class;

  TBindingOperation = class;
  TBindingOperations = class;
  TBinding = class;
  TBindings = class;

  TPort = class;
  TPorts = class;
  TService = class;
  TServices = class;

  TDefinition = class;

{ TDocumentation }

  TDocumentation = class(TXMLNode, IDocumentation)
  end;

{ TDocumentationCollection }

  TDocumentationCollection = class(TXMLNodeCollection, IDocumentationCollection)
  protected
    { IDocumentationCollection }
    function Add(const Text: WideString): IDocumentation;
    function Insert(Index: Integer): IDocumentation;
    function GetDocumentation(Index: Integer): IDocumentation;
  end;

{ TDocumented }

  TDocumented = class(TXMLNode, IDocumented)
  private
    FDocumentation: IDocumentationCollection;
  protected
    { IDocumented }
    function GetDocumentationCollection: IDocumentationCollection;
  public
    procedure AfterConstruction; override;
  end;

{ TImport }

  TImport = class(TDocumented, IImport)
  protected
    { IImport }
    function GetNamespace: WideString;
    function GetLocation: WideString;
    procedure SetNamespace(Value: WideString);
    procedure SetLocation(Value: WideString);
  end;

{ TImports }

  TImports = class(TXMLNodeCollection, IImports)
  protected
    { IImports }
    function GetImport(Index: Integer): IImport;
    function Add(const Namespace, Location: WideString): IImport;
    function Insert(Index: Integer): IImport;
  end;


{ TXMLSchemaDefs }

  TXMLSchemaDefs = class(TXMLNodeCollection, IXMLSchemaDefs)
  protected
    { ISchemaDefs }
    function Add(const NamespaceURI: WideString = '';
      const TargetNamespace: WideString = ''): IXMLSchemaDef;
    function GetXMLSchemaDef(Index: Integer): IXMLSchemaDef;
  end;

{ TTypes }

  TTypes = class(TDocumented, ITypes)
  private
    FSchemaDefs: IXMLSchemaDefs;
  protected
    { ITypes }
    function GetSchemaDefs: IXMLSchemaDefs;
  public
    procedure AfterConstruction; override;
  end;

{ TPart }

  TPart = class(TDocumented, IPart)
  protected
    { IPart }
    function GetName: WideString;
    function GetType_: WideString;
    function GetElement: WideString;
    procedure SetName(Value: WideString);
    procedure SetType_(Value: WideString);
    procedure SetElement(Value: WideString);
  end;

{ TParts }

  TParts = class(TXMLNodeCollection, IParts)
  protected
    { IParts }
    function GetPart(Index: Integer): IPart;
    function Add(const Name, Element: WideString; const AType: WideString = ''): IPart;
    function Insert(Index: Integer): IPart;
  end;

{ TMessage }

  TMessage = class(TDocumented, IMessage)
  private
    FParts: IParts;
  protected
    { IMessage }
    function GetName: WideString;
    function GetParts: IParts;
    procedure SetName(Value: WideString);
  public
    procedure AfterConstruction; override;
  end;

{ TMessages }

  TMessages = class(TXMLNodeCollection, IMessages)
  protected
    { IMessages }
    function GetMessage(Index: Integer): IMessage;
    function Add(const Name: WideString): IMessage;
    function Insert(Index: Integer): IMessage;
  end;

{ TParam }

  TParam = class(TDocumented, IParam, IBindingInput, IBindingOutput)
  protected
    { IParam }
    function GetName: WideString;
    function GetMessage: WideString;
    procedure SetName(Value: WideString);
    procedure SetMessage(Value: WideString);
  end;

{ TFaults }

  TFaults = class(TXMLNodeCollection, IFaults)
  protected
    { IFaults }
    function GetFault(Index: Integer): IFault;
    function Add(const Name, Message: WideString): IFault;
    function Insert(Index: Integer): IFault;
  end;

{ TOperation }

  TOperation = class(TDocumented, IOperation)
  private
    FFaults: IFaults;
  protected
    { IOperation }
    function GetName: WideString;
    function GetInput: IParam;
    function GetOutput: IParam;
    function GetFaults: IFaults;
    procedure SetName(Value: WideString);
  public
    procedure AfterConstruction; override;
  end;

{ TOperations }

  TOperations = class(TXMLNodeCollection, IOperations)
  protected
    { IOperations }
    function Add(const Name: WideString): IOperation; overload;
    function Add(const Name, InputMessage, InputName, OutputMessage: WideString): IOperation; overload;
    function GetOperation(Index: Integer): IOperation;
    function Insert(Index: Integer): IOperation;
  end;

{ TPortType }

  TPortType = class(TDocumented, IPortType)
  private
    FOperations: IOperations;
  protected
    { IPortType }
    function GetName: WideString;
    function GetOperations: IOperations;
    procedure SetName(Value: WideString);
  public
    procedure AfterConstruction; override;
  end;

{ TPortTypes }

  TPortTypes = class(TXMLNodeCollection, IPortTypes)
  protected
    { IPortTypes }
    function Add(const Name: WideString): IPortType; overload;
    function Insert(Index: Integer): IPortType;
    function GetPortType(Index: Integer): IPortType;
  end;

{ TBindingOperation }

  TBindingOperation = class(TDocumented, IBindingOperation)
  private
    FFaults: IFaults;
  protected
    { IBindingOperation }
    function GetName: WideString;
    function GetInput: IBindingInput;
    function GetOutput: IBindingOutput;
    function GetFaults: IFaults;
    procedure SetName(Value: WideString);
  public
    procedure AfterConstruction; override;
  end;

{ TBindingOperations }

  TBindingOperations = class(TXMLNodeCollection, IBindingOperations)
  protected
    { IBindingOperations }
    function GetBindingOperation(Index: Integer): IBindingOperation;
    function Add(const Name: WideString): IBindingOperation;
    function Insert(Index: Integer): IBindingOperation;
  end;

{ TBinding }

  TBinding = class(TDocumented, IBinding)
  private
    FBindingOperations: IBindingOperations;
  protected
    { IBindingType }
    function GetBindingOperations: IBindingOperations;
    function GetName: WideString;
    function GetType_: WideString;
    procedure SetName(Value: WideString);
    procedure SetType_(Value: WideString);
  public
    procedure AfterConstruction; override;
  end;

{ TBindings }

  TBindings = class(TXMLNodeCollection, IBindings)
  protected
    { IBindings }
    function GetBinding(Index: Integer): IBinding;
    function Add(const Name, AType: WideString): IBinding;
    function Insert(Index: Integer): IBinding;
  end;

{ TPortType }

  TPort = class(TDocumented, IPort)
  protected
    { IPort }
    function GetName: WideString;
    function GetBinding: WideString;
    procedure SetName(Value: WideString);
    procedure SetBinding(Value: WideString);
  end;

{ TPorts }

  TPorts = class(TXMLNodeCollection, IPorts)
  protected
    { IPorts }
    function GetPort(Index: Integer): IPort;
    function Add(const Name, Binding: WideString): IPort;
    function Insert(Index: Integer): IPort;
  end;

{ TService }

  TService = class(TDocumented, IService)
  private
    FPorts: IPorts;
  protected
    { IService }
    function GetName: WideString;
    function GetPorts: IPorts;
    procedure SetName(Value: WideString);
  public
    procedure AfterConstruction; override;
  end;

{ TServices }

  TServices = class(TXMLNodeCollection, IServices)
  protected
    { IServices }
    function GetService(Index: Integer): IService;
    function Add(const Name: WideString): IService;
    function Insert(Index: Integer): IService;
  end;

{ TDefinition }

  TDefinition = class(TDocumented, IDefinition)
  private
    FImports: IImports;
    FMessages: IMessages;
    FPortTypes: IPortTypes;
    FBindings: IBindings;
    FServices: IServices;
  protected
    { IDefinition }
    function GetTargetNamespace: WideString;
    function GetName: WideString;
    function GetImports: IImports;
    function GetTypes: ITypes;
    function GetMessages: IMessages;
    function GetPortTypes: IPortTypes;
    function GetBindings: IBindings;
    function GetServices: IServices;
    procedure SetTargetNamespace(Value: WideString);
    procedure SetName(Value: WideString);
  public
    procedure AfterConstruction; override;
  end;

{ TWSDLDocument }

  TWSDLDocument = class(TXMLDocument, IWSDLDocument)
  protected
    function GetDefinition: IDefinition;
    procedure SetDefinition(const Value: IDefinition);
    procedure LoadData; override;
  public
    procedure AfterConstruction; override;
    property Definition: IDefinition read GetDefinition write SetDefinition;
  end;


{ Global Functions }

function GetDefinition(Doc: TXMLDocument): IDefinition;
function LoadWSDLDoc(const FileName: WideString): IWSDLDocument;
function NewWSDLDoc: IWSDLDocument;

implementation

uses XMLSchemaTags, WSDLIntf;

{ Global Functions }

function GetDefinition(Doc: TXMLDocument): IDefinition;
begin
  Doc.Active := True;
  if not Assigned(Doc.DocumentElement) then
    Doc.DocumentElement := Doc.CreateNode(SDefinitions);
  Result := TDefinition.Create(Doc.DOMDocument.DocumentElement, nil, Doc) as IDefinition
end;

function LoadWSDLDoc(const FileName: WideString): IWSDLDocument;
begin
  Result := TWSDLDocument.Create(nil);
  Result.LoadFromFile(FileName);
end;

function NewWSDLDoc: IWSDLDocument;
begin
  Result := TWSDLDocument.Create(nil);
  Result.Active := True;
end;

{ TDocumentationCollection }

function TDocumentationCollection.Add(const Text: WideString): IDocumentation;
begin
  Result := AddItem(-1) as IDocumentation;
  if Text <> '' then
    Result.Text := Text;
end;

function TDocumentationCollection.GetDocumentation(
  Index: Integer): IDocumentation;
begin
  Result := List[Index] as IDocumentation;
end;

function TDocumentationCollection.Insert(Index: Integer): IDocumentation;
begin
  Result := AddItem(Index) as IDocumentation;
end;

{ TDocumented }

procedure TDocumented.AfterConstruction;
begin
  RegisterChildNode(SDocumentation, TDocumentation);
  FDocumentation := CreateCollection(TDocumentationCollection, IDocumentation,
    SDocumentation) as IDocumentationCollection;
  inherited;
end;

function TDocumented.GetDocumentationCollection: IDocumentationCollection;
begin
  Result := FDocumentation;
end;

{ TImport }

function TImport.GetNamespace: WideString;
begin
  Result := AttributeNodes[SNamespace].Text;
end;

procedure TImport.SetNamespace(Value: WideString);
begin
  SetAttribute(SNamespace, Value);
end;

function TImport.GetLocation: WideString;
begin
  Result := AttributeNodes[SLocation].Text;
end;

procedure TImport.SetLocation(Value: WideString);
begin
  SetAttribute(SLocation, Value);
end;

{ TImports }

function TImports.Add(const Namespace, Location: WideString): IImport;
begin
  Result := AddItem(-1) as IImport;
  if Namespace <> '' then
    Result.Namespace := Namespace;
  if Location <> '' then
    Result.Location := Location;
end;

function TImports.GetImport(
  Index: Integer): IImport;
begin
  Result := List[Index] as IImport;
end;

function TImports.Insert(Index: Integer): IImport;
begin
  Result := AddItem(Index) as IImport;
end;

{ TXMLSchemaDefs }

function TXMLSchemaDefs.Add(const NamespaceURI, TargetNamespace: WideString): IXMLSchemaDef;
var
  ItemNS: WideString;
begin
  if NamespaceURI <> '' then
    ItemNS := NamespaceURI else
    ItemNS := XMLSchemaURI;
  Result := AddChild(ItemTag, ItemNS) as IXMLSchemaDef;
  if TargetNamespace <> '' then
    Result.SetTargetNamespace(TargetNamespace, '');
end;

function TXMLSchemaDefs.GetXMLSchemaDef(Index: Integer): IXMLSchemaDef;
begin
  Result := List[Index] as IXMLSchemaDef;
end;

{ TTypes }

procedure TTypes.AfterConstruction;
begin
  RegisterChildNode(SSchema, TXMLSchemaDef, SXMLSchemaURI_1999);
  RegisterChildNode(SSchema, TXMLSchemaDef, SXMLSchemaURI_2000_10);
  RegisterChildNode(SSchema, TXMLSchemaDef, SXMLSchemaURI_2001);
  FSchemaDefs := CreateCollection(TXMLSchemaDefs, IXMLSchemaDef, SSchema, XMLSchemaURI) as IXMLSchemaDefs;
  inherited;
end;

function TTypes.GetSchemaDefs: IXMLSchemaDefs;
begin
  Result := FSchemaDefs;
end;

{ TPart }

function TPart.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TPart.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TPart.GetType_: WideString;
begin
  Result := AttributeNodes[SType].Text;
end;

procedure TPart.SetType_(Value: WideString);
begin
  SetAttribute(SType, Value);
end;

function TPart.GetElement: WideString;
begin
  Result := AttributeNodes[SElement].Text;
end;

procedure TPart.SetElement(Value: WideString);
begin
  SetAttribute(SElement, Value);
end;

{ TParts }

function TParts.Add(const Name, Element: WideString; const AType: WideString = ''): IPart;
begin
  Result := AddItem(-1) as IPart;
  if Name <> '' then
    Result.Name := Name;
  if Element <> '' then
    Result.Element := Element;
  if AType <> '' then
    Result.Type_ := AType;
end;

function TParts.Insert(Index: Integer): IPart;
begin
  Result := AddItem(Index) as IPart;
end;

function TParts.GetPart(Index: Integer): IPart;
begin
  Result := List[Index] as IPart;
end;

{ TMessage }

procedure TMessage.AfterConstruction;
begin
  RegisterChildNode(SPart, TPart);
  FParts := CreateCollection(TParts, IPart, SPart) as IParts;
  inherited;
end;

function TMessage.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TMessage.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TMessage.GetParts: IParts;
begin
  Result := FParts;
end;

{ TMessages }

function TMessages.Add(const Name: WideString): IMessage;
begin
  Result := AddItem(-1) as IMessage;
  if Name <> '' then
    Result.Name := Name;
end;

function TMessages.GetMessage(Index: Integer): IMessage;
begin
  Result := List[Index] as IMessage;
end;

function TMessages.Insert(Index: Integer): IMessage;
begin
  Result := AddItem(Index) as IMessage;
end;

{ TParam }

function TParam.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TParam.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TParam.GetMessage: WideString;
begin
  Result := AttributeNodes[SMessage].Text;
end;

procedure TParam.SetMessage(Value: WideString);
begin
  SetAttribute(SMessage, Value);
end;

{ TFaults }

function TFaults.Add(const Name, Message: WideString): IFault;
begin
  Result := AddItem(-1) as IFault;
  if Name <> '' then
    Result.Name := Name;
  if Message <> '' then
    Result.Message := Message; 
end;

function TFaults.GetFault(
  Index: Integer): IFault;
begin
  Result := List[Index] as IFault;
end;

function TFaults.Insert(Index: Integer): IFault;
begin
  Result := AddItem(Index) as IFault;
end;

{ TOperation }

procedure TOperation.AfterConstruction;
begin
  RegisterChildNodes([SInput, SOutput, SFault], [TParam, TParam, TParam]);
  FFaults := CreateCollection(TFaults, IFault, SFault) as IFaults;
  inherited;
end;

function TOperation.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TOperation.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TOperation.GetInput: IParam;
begin
  Result := ChildNodes[SInput] as IParam;
end;

function TOperation.GetOutput: IParam;
begin
  Result := ChildNodes[SOutput] as IParam;
end;

function TOperation.GetFaults: IFaults;
begin
  Result := FFaults;
end;

{ TOperations }

function TOperations.Add(const Name: WideString): IOperation;
begin
  Result := AddItem(-1) as IOperation;
  if Name <> '' then
    Result.Name := Name;
end;

function TOperations.Add(const Name, InputMessage, InputName,
  OutputMessage: WideString): IOperation;
begin
  Result := Add(Name);
  if InputMessage <> '' then
    Result.Input.Message := InputMessage;
  if InputName <> '' then
    Result.Input.Name := InputName;
  if OutputMessage <> '' then
    Result.Output.Message := OutputMessage;
end;

function TOperations.GetOperation(
  Index: Integer): IOperation;
begin
  Result := List[Index] as IOperation;
end;

function TOperations.Insert(Index: Integer): IOperation;
begin
  Result := AddItem(Index) as IOperation;
end;

{ TPortType }

procedure TPortType.AfterConstruction;
begin
  RegisterChildNode(SOperation, TOperation);
  FOperations := CreateCollection(TOperations, IOperation, SOperation) as IOperations;
  inherited;
end;

function TPortType.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TPortType.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TPortType.GetOperations: IOperations;
begin
  Result := FOperations;
end;

{ TPortTypes }

function TPortTypes.Add(const Name: WideString): IPortType;
begin
  Result := AddItem(-1) as IPortType;
  if Name <> '' then
    Result.Name := Name;
end;

function TPortTypes.GetPortType(
  Index: Integer): IPortType;
begin
  Result := List[Index] as IPortType;
end;

function TPortTypes.Insert(Index: Integer): IPortType;
begin
  Result := AddItem(Index) as IPortType;
end;

{ TBindingOperation }

procedure TBindingOperation.AfterConstruction;
begin
  RegisterChildNodes([SInput, SOutput, SFault], [TParam, TParam, TParam]);
  FFaults := CreateCollection(TFaults, IFault, SFault) as IFaults;
  inherited;
end;

function TBindingOperation.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TBindingOperation.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TBindingOperation.GetInput: IBindingInput;
begin
  Result := ChildNodes[SInput] as IBindingInput;
end;

function TBindingOperation.GetOutput: IBindingOutput;
begin
  Result := ChildNodes[SOutput] as IBindingOutput;
end;

function TBindingOperation.GetFaults: IFaults;
begin
  Result := FFaults;
end;

{ TBindingOperations }

function TBindingOperations.Add(const Name: WideString): IBindingOperation;
begin
  Result := AddItem(-1) as IBindingOperation;
  if Name <> '' then
    Result.Name := Name;
end;

function TBindingOperations.Insert(Index: Integer): IBindingOperation;
begin
  Result := AddItem(Index) as IBindingOperation;
end;

function TBindingOperations.GetBindingOperation(Index: Integer): IBindingOperation;
begin
  Result := List[Index] as IBindingOperation;
end;

{ TBinding }

procedure TBinding.AfterConstruction;
begin
  RegisterChildNode(SOperation, TBindingOperation);
  FBindingOperations := CreateCollection(TBindingOperations, IBindingOperation,
    SOperation) as IBindingOperations;
  inherited;
end;

function TBinding.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TBinding.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TBinding.GetType_: WideString;
begin
  Result := AttributeNodes[SType].Text;
end;

procedure TBinding.SetType_(Value: WideString);
begin
  SetAttribute(SType, Value);
end;

function TBinding.GetBindingOperations: IBindingOperations;
begin
  Result := FBindingOperations;
end;

{ TBindings }

function TBindings.Add(const Name, AType: WideString): IBinding;
begin
  Result := AddItem(-1) as IBinding;
  if Name <> '' then
    Result.Name := Name;
  if AType <> '' then
    Result.Type_ := AType;
end;

function TBindings.GetBinding(Index: Integer): IBinding;
begin
  Result := List[Index] as IBinding;
end;

function TBindings.Insert(Index: Integer): IBinding;
begin
  Result := AddItem(Index) as IBinding;
end;

{ TPort }

function TPort.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TPort.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TPort.GetBinding: WideString;
begin
  Result := AttributeNodes[SBinding].Text;
end;

procedure TPort.SetBinding(Value: WideString);
begin
  SetAttribute(SBinding, Value);
end;

{ TPorts }

function TPorts.Add(const Name, Binding: WideString): IPort;
begin
  Result := AddItem(-1) as IPort;
  if Name <> '' then
    Result.Name := Name;
  if Binding <> '' then
    Result.Binding := Binding;
end;

function TPorts.Insert(Index: Integer): IPort;
begin
  Result := AddItem(Index) as IPort;
end;

function TPorts.GetPort(Index: Integer): IPort;
begin
  Result := List[Index] as IPort;
end;

{ TService }

procedure TService.AfterConstruction;
begin
  RegisterChildNode(SPort, TPort);
  FPorts := CreateCollection(TPorts, IPort, SPort) as IPorts;
  inherited;
end;

function TService.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TService.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TService.GetPorts: IPorts;
begin
  Result := FPorts;
end;

{ TServices }

function TServices.Add(const Name: WideString): IService;
begin
  Result := AddItem(-1) as IService;
  if Name <> '' then
    Result.Name := Name;
end;

function TServices.Insert(Index: Integer): IService;
begin
  Result := AddItem(Index) as IService;
end;

function TServices.GetService(Index: Integer): IService;
begin
  Result := List[Index] as IService;
end;

{ TDefinition }

procedure TDefinition.AfterConstruction;
begin
  FBindings := CreateCollection(TBindings, IBinding, SBinding) as IBindings;
  FImports := CreateCollection(TImports, IImport, SImport) as IImports;
  FMessages := CreateCollection(TMessages, IMessage, SMessage) as IMessages;
  FPortTypes := CreateCollection(TPortTypes, IPortType, SPortType) as IPortTypes;
  FServices := CreateCollection(TServices, IService, SService) as IServices;
  RegisterChildNodes([SImport, STypes, SMessage, SPortType, SBinding, SService],
    [TImport, TTypes, TMessage, TPortType, TBinding, TService]);
  inherited;
end;

function TDefinition.GetTargetNamespace: WideString;
begin
  Result := AttributeNodes[STargetNamespace].Text;
end;

procedure TDefinition.SetTargetNamespace(Value: WideString);
begin
  SetAttribute(STargetNamespace, Value);
end;

function TDefinition.GetName: WideString;
begin
  Result := AttributeNodes[SName].Text;
end;

procedure TDefinition.SetName(Value: WideString);
begin
  SetAttribute(SName, Value);
end;

function TDefinition.GetImports: IImports;
begin
  Result := FImports;
end;

function TDefinition.GetTypes: ITypes;
begin
  Result := ChildNodes['types'] as ITypes;
end;

function TDefinition.GetMessages: IMessages;
begin
  Result := FMessages;
end;

function TDefinition.GetPortTypes: IPortTypes;
begin
  Result := FPortTypes;
end;

function TDefinition.GetBindings: IBindings;
begin
  Result := FBindings;
end;

function TDefinition.GetServices: IServices;
begin
  Result := FServices;
end;

{ TWSDLDocument }

procedure TWSDLDocument.AfterConstruction;
begin
  RegisterDocBinding(SDefinitions, TDefinition, wsdlns);
  inherited;
  Options := Options + [doNodeAutoIndent];
end;

function TWSDLDocument.GetDefinition: IDefinition;
begin
  Result := GetDocumentElement as IDefinition;
end;

procedure TWSDLDocument.LoadData;
begin
  inherited;
  if IsEmptyDoc then
  begin
    Version := '1.0';
    Node.AddChild(SDefinitions, wsdlns);
    DocumentElement.DeclareNamespace(SXMLSchemaPrefix, XMLSchemaURI);
  end;
end;

procedure TWSDLDocument.SetDefinition(const Value: IDefinition);
begin
  DocumentElement := Value;
end;

end.
