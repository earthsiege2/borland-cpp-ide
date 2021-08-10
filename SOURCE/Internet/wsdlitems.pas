
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       WSDL Items                                      }
{                                                       }
{   Copyright (c) 2001 Borland Software Corporation     }
{                                                       }
{*******************************************************}

unit WSDLItems;

interface

uses
  {$IFDEF MSWINDOWS}Windows, Messages, {$ENDIF}SysUtils, Variants, Classes, TypInfo, XMLIntf, XMLDoc,
  xmldom, XmlSchema, {$IFDEF MSWINDOWS}msxmldom, {$ENDIF}WSDLIntf, WSDLBind, HTTPUtil;

type

  TWSDLItems = class;

  IWSDLItems = interface
  ['{F71B4B05-C5AB-4484-B994-64F3F9E805C7}']
    function GetWSDLItems: TWSDLItems;
    function GetWSDLDoc: IWSDLDocument;
    procedure Load(const WSDLFileName: WideString);
  end;

  IQualifiedName = interface
  ['{0173ABA2-34AB-4CB1-ADF0-AA99C98FCFBD}']
    function  GetName: WideString;
    procedure SetName(const name: WideString);
    function  GetNamespace: WideString;
    procedure SetNamespace(const ns: WideString);
    property  Name: WideString read GetName write SetName;
    property  Namespace: WideString read GetNamespace write SetNamespace;
  end;

  { Options passed to Proc. when iterating through imports }
  IterateImportOptions = (ioBeforeLoad, ioLoaded);

  { Callback when iterating through imports of a WSDL document }
  TWSDLIterateProc = procedure (const Options: IterateImportOptions;
                                const WSDLItems: IWSDLItems;
                                const XMLSchemaDoc: IXMLSchemaDoc;
                                const Name: WideString) of object;

  { Helper class to get WSDL Items }
  TWSDLItems = class(TWSDLDocument, IWSDLItems)
  private
    FWSDLStreamLoader: IStreamLoader;
    { Helper methods to Import WSDL documents }

    function  GetGenericBindingAttribute(const BindingName: WideString;
                                         const NodeName: WideString;
                                         const Namespace: WideString;
                                         Attribute: WideString): WideString;
    function MakeTNSName(const Name: WideString): WideString;
  public
    constructor Create(AOwner: TComponent); overload; override;
    constructor Create(const WSDLItems: TWSDLItems; const StreamLoader: IStreamLoader); overload; virtual;

    { IWSDLItems }
    function GetWSDLItems: TWSDLItems;
    function GetWSDLDoc: IWSDLDocument;
    procedure Load(const WSDLFileName: WideString);

    function CompareName(const NodeName: WideString;
                         const OtherName: WideString;
                         const TNS: WideString = ''): boolean;

    { Helper methods to get WSDL Items }
    function  GetName: WideString;
    function  GetTargetNamespace: WideString;
    function  GetTargetNamespacePrefix: WideString;
    procedure GetServices(ServiceNames: TWideStrings; QualifiedNames: Boolean = False);
    function  GetServiceNode(const ServiceName: WideString): IXMLNode;
    procedure GetMessages(MessageNames: TWideStrings; QualifiedNames: Boolean = False);
    function  GetMessageNode(const MessageName: WideString): IXMLNode;
    procedure GetParts(const MessageName: WideString; PartNames: TWideStrings; QualifiedNames: Boolean = False);
    function  GetPartNode(const MessageName, PartName: WideString): IXMLNode;
    procedure GetPortTypes(PortTypeNames: TWideStrings; SkipHttpBindings: Boolean = True;
                                                        QualifiedNames: Boolean = False);
    function  GetPortTypeNode(const PortTypeName: WideString): IXMLNode;
    procedure GetOperations(const PortTypeName: WideString; OperationNames: TWideStrings; QualifiedNames: Boolean = False);
    function  GetOperationNode(const PortTypeName, OperationName: WideString): IXMLNode;

    procedure GetPortsForService(const ServiceName: WideString; PortNames: TWideStrings;
                                 SkipHttpBindings: Boolean = True; QualifiedNames: Boolean = False);
    function  GetBindingForServicePort(const ServiceName, PortName: WideString): IQualifiedName;
    function  GetServiceAndPortOfBinding(const BindingName: IQualifiedName;
                                         var ServiceName: WideString;
                                         var PortName: WideString): Boolean;
    function  GetSoapAddressForServicePort(const ServiceName, PortName: WideString): WideString;
    procedure GetImports(ImportNames: TWideStrings);
    procedure IterateImports(IterateProc: TWSDLIterateProc);
    function  GetLocationForImport(const ImportNameSpace: WideString): WideString;
    function  HasTypesNode: Boolean;
    procedure GetSchemas(SchemaNames: TWideStrings);
    function  GetSchemaNode(const SchemaTns: WideString) : IXMLNode;
    procedure GetBindings(BindingNames: TWideStrings; QualifiedNames: Boolean = False);
    function  GetBindingType(const BindingName: WideString): WideString;
    function  GetBindingOfType(const BindingTypeName: WideString;
                               const TNS: WideString = ''): IQualifiedName;
    function  GetSoapBindingAttribute(const BindingName: WideString; Attribute: WideString): WideString;
    function  GetHttpBindingAttribute(const BindingName: WideString; Attribute: WideString): WideString; overload;
    function  GetHttpBindingAttribute(const QualifiedName: IQualifiedName; Attribute: WideString): WideString; overload;
    procedure GetOperationsForBinding(const BindingName: WideString; OperationNames: TWideStrings; QualifiedNames: Boolean = False);
    function  GetSoapOperationAttribute(const BindingName, Operation, Attribute: WideString): WideString;
    function  GetSoapAction(const BindingName, Operation: WideString): WideString;
    function  GetSoapOperationStyle(const BindingName, Operation: WideString): WideString;
    procedure GetSoapActionList(const BindingName: WideString; ActionList: TWideStrings; QualifiedNames: Boolean = False);
    function  GetSoapBodyAttribute(const BindingName, Operation, IOType, Attribute: WideString): WideString;
    function  GetSoapBodyInputAttribute(const BindingName, Operation, Attribute: WideString): WideString;
    function  GetSoapBodyOutputAttribute(const BindingName, Operation, Attribute: WideString): WideString;
    function  GetSoapBodyNamespace(const BindingPortType: WideString): WideString;

//    procedure GetSoapHeaderAttribute(const BindingName, Operation, IOType, Attribute: WideString; SoapHeaderAttrs: TWideStrings);
//    procedure GetSoapFaultsForOperation(const BindingName, Operation: WideString; FaultNames: TWideStrings);
//    function  GetSoapFaultAttribute(const BindingName, Operation, FaultName, Attribute: WideString): WideString;
    function GetPartsForOperation(const PortTypeName, OperationName: WideString; OperationIndex: Integer; PartNames: TWideStrings): Boolean;

    property StreamLoader: IStreamLoader read FWSDLStreamLoader;
    property TargetNamespace: WideString read GetTargetNamespace;
  end;

{ Helper functions }
function HasDefinition(const WSDLDoc: IWSDLDocument): Boolean; overload;
function HasDefinition(const WSDLItems: IWSDLItems): Boolean; overload;

function NewQualifiedName(const Name: WideString = ''; const Namespace: WideString = ''): IQualifiedName;

implementation

uses SOAPConst;

type

  TQualifiedName = class(TInterfacedObject, IQualifiedName)
  private
    FName: WideString;
    FNamespace: WideString;
  public
    function  GetName: WideString;
    procedure SetName(const name: WideString);
    function  GetNamespace: WideString;
    procedure SetNamespace(const ns: WideString);
  end;

function NewQualifiedName(const Name: WideString; const Namespace: WideString): IQualifiedName;
begin
  Result := TQualifiedName.Create;
  Result.Name := Name;
  Result.Namespace := Namespace;
end;

function  TQualifiedName.GetName: WideString;
begin
  Result := FName;
end;

procedure TQualifiedName.SetName(const name: WideString);
begin
  FName := name;
end;

function  TQualifiedName.GetNamespace: WideString;
begin
  Result := FNamespace;
end;

procedure TQualifiedName.SetNamespace(const ns: WideString);
begin
  FNamespace := ns;
end;

constructor TWSDLItems.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FWSDLStreamLoader := HTTPUtil.GetDefaultStreamLoader;
end;

constructor TWSDLItems.Create(const WSDLItems: TWSDLItems; const StreamLoader: IStreamLoader);
begin
  inherited Create(nil);
  if Assigned(StreamLoader) then
    FWSDLStreamLoader := StreamLoader
  else if Assigned(WSDLItems) then
    FWSDLStreamLoader := WSDLItems.StreamLoader;
end;

procedure TWSDLItems.Load(const WSDLFileName: WideString);
var
  Stream: TMemoryStream;
begin
  Stream := TMemoryStream.Create;
  try
    FWSDLStreamLoader.Load(WSDLFileName, Stream);
    LoadFromStream(Stream);
    FileName := WSDLFIleName;
  finally;
    Stream.Free;
  end;
end;

{ Returns whether the WSDL/XML document had a <definition> node }
function HasDefinition(const WSDLDoc: IWSDLDocument): Boolean;
var
  XMLNodeList: IXMLNodeList;
begin
  XMLNodeList := WSDLDoc.ChildNodes;
  Result := (XMLNodeList <> nil) and (XMLNodeList.FindNode(SDefinitions, Wsdlns) <> nil);
end;

function HasDefinition(const WSDLItems: IWSDLItems): Boolean;
begin
  Result := HasDefinition(WSDLItems.GetWSDLDoc);
end;


{ TWSDLItems implementation }

function TWSDLItems.GetWSDLItems: TWSDLItems;
begin
  Result := Self;
end;

function TWSDLItems.GetWSDLDoc: IWSDLDocument;
begin
  Result := Self;
end;

{ Returns the path of the underlying WSDL document }
function TWSDLItems.GetName: WideString;
begin
  Result := Definition.Name;
end;

function TWSDLItems.GetTargetNamespace: WideString;
begin
  Result := Definition.GetTargetNamespace;
end;

function TWSDLItems.GetTargetNamespacePrefix: WideString;
var
  XMLNode: IXMLNode;
begin
  Result := '';
  XMLNode := Definition.FindNamespaceDecl(GetTargetNamespace);
  if XMLNode <> nil then
    Result := ExtractLocalName(XMLNode.NodeName);
end;

function TWSDLItems.CompareName(const NodeName: WideString;
                                const OtherName: WideString;
                                const TNS: WideString): boolean;
var
  LocalName1, LocalName2: WideString;
  Prefix1, Prefix2: WideString;
  TNS1, TNS2: WideString;
begin
  Result := False;
  LocalName1 := ExtractLocalName(NodeName);
  LocalName2 := ExtractLocalName(OtherName);

  { Check local names first }
  if (LocalName1 <> LocalName2) then
    Exit;

  { Extract Prefixes }
  Prefix1 := ExtractPrefix(NodeName);
  Prefix2 := ExtractPrefix(OtherName);

  { Check Prefixes }
  { NOTE: Technically this is not accurate. In cases where there are imports
          similar prefixes don't imply same namespace.... }
  if Prefix1 = Prefix2 then
  begin
    Result := True;
    Exit;
  end;

  { First prefix }
  if (Prefix1 = '') then
    TNS1 := GetTargetNamespace
  else
    TNS1 := Definition.FindNamespaceURI(Prefix1);

  { Second prefix may be overriden }
  if (TNS <> '') then
    TNS2 := TNS
  else
  begin
    if Prefix2 = '' then
      TNS2 := GetTargetNamespace
    else
      TNS2 := Definition.FindNamespaceURI(Prefix2);
  end;

  { Compare actual namespaces }
  Result := SameNamespace(TNS1, TNS2);
end;

function TWSDLItems.MakeTNSName(const Name: WideString): WideString;
begin
  Result := MakeNodeName(GetTargetNamespacePrefix, Name)
end;

procedure TWSDLItems.GetServices(ServiceNames: TWideStrings; QualifiedNames: Boolean = False);
var
  Count, Index: Integer;
  Services: IServices;
  Service: IService;
  Imports: IImports;
  WSDLItems: IWSDLItems;
begin
  Services := Definition.Services;
  if Services <> nil then
  begin
    for Count:= 0 to Services.Count-1 do
    begin
      Service := Services[Count];
      if QualifiedNames then
      begin
        ServiceNames.Add(MakeTNSName(Service.Name))
      end
      else
        ServiceNames.Add(Service.Name);
    end;
  end;

  { Get any imported WSDL }
  Imports := Definition.Imports;
  if Imports <> nil then
  begin
    for Index := 0 to Imports.Count -1 do
    begin
      WSDLItems := TWSDLItems.Create(Self, nil);
      WSDLItems.Load(Imports[Index].Location);
      if HasDefinition(WSDLItems) then
        WSDLItems.GetWSDLItems.GetServices(ServiceNames, QualifiedNames);
    end;
  end;
end;

function TWSDLItems.GetServiceNode(const ServiceName: WideString): IXMLNode;
var
  Count: Integer;
  Services: IServices;
  ServiceNode: IXMLNode;
begin
  Services := Definition.Services;
  for Count:= 0 to Services.Count-1 do
    if (ServiceName = Services[Count].Name) then
    begin
      ServiceNode := Services[Count] as IXMLNode;
      break;
    end;
  Result := ServiceNode;
end;

procedure TWSDLItems.GetPortsForService(const ServiceName: WideString;
                                        PortNames: TWideStrings;
                                        SkipHttpBindings: Boolean = True;
                                        QualifiedNames: Boolean = False);
var
  I,Index,Count: Integer;
  Services: IServices;
  Service: IService;
  Ports: IPorts;
  Port: IPort;
  PortName: WideString;
  Imports: IImports;
  WSDLItems: IWSDLItems;
begin
  Services := Definition.Services;
  if Services <> nil then
  begin
    for Count := 0 to Services.Count -1 do
    begin
      Service := Services[Count];
      if (CompareName(Service.Name, ServiceName)) then
      begin
        Ports := Service.Ports;
        for I := 0 to Ports.Count-1 do
        begin
          Port := Ports[I];
          PortName := MakeTNSName(Port.Name);

          { Check for HTTP Binding if we're skipping }
          if SkipHttpBindings and
            (GetHttpBindingAttribute(GetBindingForServicePort(ServiceName, PortName), SVerb) <> '') then
            continue;

          if QualifiedNames then
            PortNames.Add(PortName)
          else
            PortNames.Add(Port.Name);
        end;
      end;
    end;
  end;

  { Get any imported WSDL }
  Imports := Definition.Imports;
  if Imports <> nil then
  begin
    for Index := 0 to Imports.Count -1 do
    begin
      WSDLItems := TWSDLItems.Create(Self, nil);
      WSDLItems.Load(Imports[Index].Location);
      if HasDefinition(WSDLItems) then
        WSDLItems.GetWSDLItems.GetPortsForService(ServiceName, PortNames, QualifiedNames);
    end;
  end;
end;

function TWSDLItems.GetBindingForServicePort(const ServiceName, PortName: WideString): IQualifiedName;
var
  I, Index, Count: Integer;
  Services: IServices;
  Ports: IPorts;
  Port: IPort;
  Imports: IImports;
  WSDLItems: IWSDLItems;
begin
  Result := nil;

  Services := Definition.Services;
  if Services <> nil then
  begin
    for Count := 0 to Services.Count -1 do
    begin
      if CompareName(Services[Count].Name, ServiceName) then
      begin
        Ports := Services[Count].Ports;
        for I := 0 to Ports.Count-1 do
        begin
          if CompareName(Ports[I].Name, PortName) then
          begin
            Port := Ports[I];
            Result := NewQualifiedName(Port.Binding);
            Exit;
          end;
        end;
      end;
    end;
  end;

  { Get any imported WSDL }
  Imports := Definition.Imports;
  if Imports <> nil then
  begin
    for Index := 0 to Imports.Count -1 do
    begin
      WSDLItems := TWSDLItems.Create(Self, nil);
      WSDLItems.Load(Imports[Index].Location);
      if HasDefinition(WSDLItems) then
        Result := WSDLItems.GetWSDLItems.GetBindingForServicePort(ServiceName, PortName);
      if Result <> nil then
        Exit;
    end;
  end;
end;

function TWSDLItems.GetSoapAddressForServicePort(const ServiceName, PortName: WideString): WideString;
var
  I, Index, Count: Integer;
  Services: IServices;
  AddressNode: IXMLNode;
  Ports: IPorts;
  WSDLItems: IWSDLItems;
  Imports: IImports;
begin
  Result := '';

  Services := Definition.Services;
  if Services <> nil then
  begin
    for Count := 0 to Services.Count -1 do
    begin
      if CompareName(Services[Count].Name, ServiceName) then
      begin
        Ports := Services[Count].Ports;
        for I := 0 to Ports.Count-1 do
        begin
          if CompareName(Ports[I].Name, PortName) then
          begin
            if (Ports[I].ChildNodes <> nil) then
            begin
              AddressNode := Ports[I].ChildNodes.FindNode(SAddress, Soapns);
              if AddressNode <> nil then
              begin
                Result := AddressNode.Attributes[SLocation];
                Exit;
              end;
            end;
          end;
        end;
      end;
    end;
  end;

  { Get any imported WSDL }
  Imports := Definition.Imports;
  if Imports <> nil then
  begin
    for Index := 0 to Imports.Count -1 do
    begin
      WSDLItems := TWSDLItems.Create(Self, nil);
      WSDLItems.Load(Imports[Index].Location);
      if HasDefinition(WSDLItems) then
        Result := WSDLItems.GetWSDLItems.GetSoapAddressForServicePort(ServiceName, PortName);
      if Result <> '' then
        Exit;
    end;
  end;
end;

procedure TWSDLItems.GetMessages(MessageNames: TWideStrings; QualifiedNames: Boolean);
var
  Count: Integer;
  Messages: IMessages;
  MessageName: WideString;
begin
  Messages := Definition.Messages;
  for Count:= 0 to  Messages.Count-1 do
  begin
    MessageName := Messages[Count].Name;
    if QualifiedNames then
      MessageNames.Add(MakeTNSName(MessageName))
    else
      MessageNames.Add(MessageName);
  end;
end;

function TWSDLItems.GetMessageNode(const MessageName: WideString): IXMLNode;
var
 Count: Integer;
 MessageNode: IXMLNode;
 Messages: IMessages;
begin
  Messages := Definition.Messages;
  for Count := 0 to  Messages.Count-1 do
    if CompareName(Messages[Count].Name, MessageName) then
    begin
      MessageNode := Messages[Count] as IXMLNode;
      break;
    end;

  Result := MessageNode;
end;

procedure TWSDLItems.GetParts(const MessageName: WideString; PartNames: TWideStrings; QualifiedNames: Boolean);
var
  I, Count: Integer;
  Messages: IMessages;
  Parts: IParts;
  Part: IPart;
begin
  Parts := nil;
  Messages := Definition.Messages;
  for Count := 0 to  Messages.Count-1 do
  begin
    if CompareName(Messages[Count].Name, MessageName) then
    begin
      Parts := Messages[Count].Parts;
      break;
    end;
  end;

  if Parts <> nil then
    for I := 0 to Parts.Count -1 do
    begin
      Part := Parts[I];
      if QualifiedNames then
        PartNames.Add(MakeTNSName(Part.Name))
      else
        PartNames.Add(Part.Name);
    end;
end;


function TWSDLItems.GetPartNode(const MessageName, PartName: WideString): IXMLNode;
var
  I, Count: Integer;
  Messages: IMessages;
  Parts: IParts;
begin
  Result := nil;
  Parts := nil;

  Messages := Definition.Messages;
  for Count := 0 to Messages.Count-1 do
    if CompareName(Messages[Count].Name, MessageName) then
    begin
      Parts := Messages[Count].Parts;
      break;
    end;

  if Parts <> nil then
  begin
    for I := 0 to Parts.Count -1 do
    begin
      if CompareName(Parts[I].Name, PartName) then
      begin
        Result := Parts[I] as IXMLNode;
        Exit;
      end;
    end;
  end;
end;


procedure TWSDLItems.GetPortTypes(PortTypeNames: TWideStrings; SkipHttpBindings: Boolean;
                                  QualifiedNames: Boolean);
var
  Count, Index: Integer;
  PortTypes: IPortTypes;
  Imports: IImports;
  PortTypeName: string;
  WSDLItems: IWSDLItems;
begin
  PortTypes := Definition.PortTypes;
  for Count:= 0 to PortTypes.Count-1 do
  begin
    PortTypeName:= PortTypes[Count].Name;
    if SkipHttpBindings and (GetHttpBindingAttribute(GetBindingOfType(PortTypeName), SVerb) <> '') then
      continue;
    if QualifiedNames then
      PortTypeNames.Add(MakeTNSName(PortTypeName))
    else
      PortTypeNames.Add(PortTypeName);
  end;

  { Get any imported WSDL }
  Imports := Definition.Imports;
  if Imports <> nil then
  begin
    for Index := 0 to Imports.Count -1 do
    begin
      WSDLItems := TWSDLItems.Create(Self, nil);
      WSDLItems.Load(Imports[Index].Location);
      if HasDefinition(WSDLItems) then
        WSDLItems.GetWSDLItems.GetPortTypes(PortTypeNames, SkipHttpBindings, QualifiedNames);
    end;
  end;
end;

function TWSDLItems.GetPortTypeNode(const PortTypeName: WideString): IXMLNode;
var
  Count: Integer;
  PortTypes: IPortTypes;
begin
  Result := nil;
  PortTypes := Definition.PortTypes;
  for Count:= 0 to PortTypes.Count-1 do
    if CompareName(PortTypes[Count].Name, PortTypeName) then
    begin
      Result := PortTypes[Count] as IXMLNode;
      Exit;
    end;
end;

procedure TWSDLItems.GetOperations(const PortTypeName: WideString; OperationNames: TWideStrings; QualifiedNames: Boolean);
var
  I, Count: Integer;
  PortTypes: IPortTypes;
  Operations: IOperations;
  Operation: IOperation;
begin
  PortTypes := Definition.PortTypes;

  for Count:= 0 to PortTypes.Count-1 do
    if CompareName(PortTypes[Count].Name, PortTypeName) then
    begin
      Operations := PortTypes[Count].Operations;
      break;
    end;

  if Operations <> nil then
  begin
    for I:=0 to Operations.Count -1 do
    begin
      Operation := Operations[I];
      if QualifiedNames then
        OperationNames.Add(MakeTNSName(Operation.Name))
      else
        OperationNames.Add(Operation.Name);
    end;
  end;
end;

function TWSDLItems.GetOperationNode(const PortTypeName, OperationName: WideString): IXMLNode;
var
  I, Count: Integer;
  PortTypes: IPortTypes;
  Operations: IOperations;
begin
  Operations := nil;
  PortTypes := Definition.PortTypes;

  for Count:= 0 to PortTypes.Count-1 do
    if CompareName(PortTypes[Count].Name, PortTypeName) then
    begin
      Operations := PortTypes[Count].Operations;
      break;
    end;

  if Operations <> nil then
  begin
    for I:=0 to Operations.Count -1 do
    begin
      if CompareName(Operations[I].Name, OperationName) then
      begin
        Result := Operations[I] as IXMLNode;
        Exit;
      end;
    end;
  end;
end;

(*
procedure TWSDLItems.GetInOutMessagesForOperation(const PortTypeName, OperationName: WideString; OperationIndex: Integer; InOutMessages: TWideStrings);
var
  I, Count: Integer;
  InOutMessageName: WideString;
  PortTypes: IPortTypes;
  Operations: IOperations;
begin

  PortTypes := Definition.PortTypes;

  for Count:= 0 to PortTypes.Count-1 do
    if (PortTypeName = PortTypes[Count].Name) then
    begin
      Operations := PortTypes[Count].Operations;
      break;
    end;

  for I:=0 to Operations.Count -1 do
    if ((OperationName = Operations[I].Name) and (OperationIndex = I)) then
    begin
      if (Operations[I].Input.Message <> '') then
      begin
        InOutMessageName := SInput + ', ' + Operations[I].Input.Message;
        InOutMessages.Add(InOutMessageName);
      end;
      if (Operations[I].Output.Message <> '') then
      begin
        InOutMessageName := SOutput + ', ' + Operations[I].Output.Message;
        InOutMessages.Add(InOutMessageName);
      end;
    end;
end;
*)


function TWSDLItems.GetPartsForOperation(const PortTypeName, OperationName: WideString; OperationIndex: Integer; PartNames: TWideStrings): Boolean;
var
  I,Index,Count: Integer;
  PortTypes: IPortTypes;
  Operations: IOperations;
  Imports: IImports;
  WSDLItems: IWSDLItems;
begin
  Result := False;
  PortTypes := Definition.PortTypes;

  for Count:= 0 to PortTypes.Count-1 do
  begin
    if CompareName(PortTypes[Count].Name, PortTypeName) then
    begin
      Operations := PortTypes[Count].Operations;
      break;
    end;
  end;

  if (Operations <> nil) and (Operations.Count > 0) then
  begin
    for I:=0 to Operations.Count -1 do
    begin
      if CompareName(Operations[I].Name, OperationName) and (OperationIndex = I) then
      begin
        if (Operations[I].Input.Message <> '') then
        begin
          GetParts(Operations[I].Input.Message, PartNames);
          Result := True;
        end;
      end;
    end;
  end
  else
  begin
    { Get any imported WSDL }
    Imports := Definition.Imports;
    if Imports <> nil then
    begin
      for Index := 0 to Imports.Count -1 do
      begin
        WSDLItems := TWSDLItems.Create(Self, nil);
        WSDLItems.Load(Imports[Index].Location);
        if HasDefinition(WSDLItems) then
          if (WSDLItems.GetWSDLItems.GetPartsForOperation(PortTypeName, OperationName, OperationIndex, PartNames)) then
          begin
            Result := True;
            Exit;
          end;
      end;
    end;
  end;
end;


procedure TWSDLItems.GetImports(ImportNames: TWideStrings);
var
  Count: Integer;
  Imports: IImports;
begin

  Imports := Definition.Imports;
  for Count := 0 to Imports.Count -1 do
    ImportNames.Add(Imports[Count].Namespace);
end;


procedure TWSDLItems.IterateImports(IterateProc: TWSDLIterateProc);
var
  Index: Integer;
  Imports: IImports;
  ImportWSDLItems: IWSDLItems;
  SchemaDoc: IXMLSchemaDoc;
  Stream: TMemoryStream;
begin
  Imports := Definition.Imports;
  if Imports <> nil then
  begin
    for Index := 0 to Imports.Count -1 do
    begin
      Stream := TMemoryStream.Create;
      try
        IterateProc(ioBeforeLoad, nil, nil, Imports[Index].Location);
        StreamLoader.Load(Imports[Index].Location, Stream);
        { Check if it's a WSDL document }
        ImportWSDLItems := TWSDLItems.Create(Self, nil);
        ImportWSDLItems.GetWSDLItems.LoadFromStream(Stream);
        if HasDefinition(ImportWSDLItems) then
        begin
          { Recurse - depth first }
          ImportWSDLItems.GetWSDLItems.IterateImports(IterateProc);
          { Invoke proc }
          IterateProc(ioLoaded, ImportWSDLItems, nil, Imports[Index].Location);
        end
        else
        begin
          SchemaDoc := TXMLSchemaDoc.Create(nil);
          SchemaDoc.LoadFromStream(Stream);
          SchemaDoc.Active := True;
          SchemaDoc.FileName := Imports[Index].Location;
          IterateProc(ioLoaded, nil, SchemaDoc, Imports[Index].Location);
        end;
      finally
        Stream.Free;
      end;
    end;
  end;
end;

function TWSDLItems.GetLocationForImport(const ImportNameSpace: WideString): WideString;
var
  Count: Integer;
  Location: WideString;
  Imports: IImports;
begin

  Imports := Definition.Imports;
  for Count := 0 to Imports.Count -1 do
    if (ImportNameSpace = Imports[Count].Namespace) then
    begin
      Location := Imports[Count].Location;
      break;
    end;

  Result := Location;
end;

procedure TWSDLItems.GetBindings(BindingNames: TWideStrings; QualifiedNames: Boolean);
var
  Count: Integer;
  Bindings: IBindings;
  Binding: IBinding;
begin
  Bindings := Definition.Bindings;
  for Count := 0 to Bindings.Count -1 do
  begin
    Binding := Bindings[Count];
    if QualifiedNames then
      BindingNames.Add(MakeTNSName(Binding.Name))
    else
      BindingNames.Add(Binding.Name);
  end;
end;

function TWSDLItems.GetServiceAndPortOfBinding(const BindingName: IQualifiedName;
                                               var ServiceName: WideString;
                                               var PortName: WideString): Boolean;
var
  Count, I: Integer;
  Services: IServices;
  Ports: IPorts;
  Service: IService;
  Port: IPort;
  Imports: IImports;
  WSDLItems: IWSDLItems;
begin
  Result := False;
  Services := Definition.Services;
  if Services <> nil then
  begin
    for Count := 0 to Services.Count -1 do
    begin
      Service := Services[Count];
      Ports := Service.Ports;
      for I := 0 to Ports.Count-1 do
      begin
        Port := Ports[I];
        if CompareName(Port.Binding, BindingName.Name, BindingName.Namespace) then
        begin
          ServiceName := Service.Name;
          PortName := Port.Name;
          Result := True;
          Exit;
        end;
      end;
    end;
  end;
  { Get any imported WSDL }
  if not Result then
  begin
    Imports := Definition.Imports;
    if Imports <> nil then
    begin
      for I := 0 to Imports.Count -1 do
      begin
        WSDLItems := TWSDLItems.Create(Self, nil);
        WSDLItems.Load(Imports[I].Location);
        if HasDefinition(WSDLItems) then
          Result := WSDLItems.GetWSDLItems.GetServiceAndPortOfBinding(BindingName, ServiceName, PortName);
        if Result then
          Exit;
      end;
    end;
  end;
end;

{ Returns PortType that maps to the specified Binding }
function TWSDLItems.GetBindingType(const BindingName: WideString): WideString;
var
  Count: Integer;
  BindingTypeName: WideString;
  Bindings: IBindings;
begin
  Bindings := Definition.Bindings;
  for Count := 0 to Bindings.Count -1 do
    if CompareName(Bindings[Count].Name, BindingName) then
    begin
      BindingTypeName := Bindings[Count].Type_;
      break;
    end;
  Result := BindingTypeName;
end;

{ Returns the Binding whose type="xxx" attribute value corresponds to the specified name (i.e. a PortType name) }
function  TWSDLItems.GetBindingOfType(const BindingTypeName: WideString;
                                      const TNS: WideString): IQualifiedName;
var
  Count: Integer;
  Bindings: IBindings;
  Binding: IBinding;
  Imports: IImports;
  I: Integer;
  WSDLItems: IWSDLItems;
  NS: WideString;
begin
  Result := nil;
  Bindings := Definition.Bindings;
  for Count := 0 to Bindings.Count -1 do
  begin
    Binding := Bindings[Count];
    if CompareName(Binding.Type_, BindingTypeName, TNS) then
    begin
      Result := NewQualifiedName(Binding.Name, GetTargetNamespace);
      break;
    end;
  end;

  { Get any imported WSDL }
  if Result = nil then
  begin
    Imports := Definition.Imports;
    if Imports <> nil then
    begin

      { Keep namespace for comparisons }
      if TNS = '' then
        NS := TargetNamespace
      else
        NS := TNS;

      for I := 0 to Imports.Count -1 do
      begin
        WSDLItems := TWSDLItems.Create(Self, nil);
        WSDLItems.Load(Imports[I].Location);
        if HasDefinition(WSDLItems) then
          Result := WSDLItems.GetWSDLItems.GetBindingOfType(BindingTypeName, NS);
        if Result <> nil then
          Exit;
      end;
    end;
  end;
end;

function  TWSDLItems.GetGenericBindingAttribute(const BindingName: WideString;
                                                const NodeName: WideString;
                                                const Namespace: WideString;
                                                Attribute: WideString): WideString;
var
  I,Count: Integer;
  Bindings: IBindings;
  Node: IXMLNode;
  XMLNodeList: IXMLNodeList;
begin
  Result := '';
  Bindings := Definition.Bindings;
  for Count := 0 to Bindings.Count -1 do
  begin
    if CompareName(Bindings[Count].Name, BindingName) then
    begin
      for I := 0 to Bindings[Count].ChildNodes.Count -1 do
      begin
        XMLNodeList := Bindings[Count].ChildNodes;
        Node := XMLNodeList.FindNode(NodeName, Namespace);
        if Node <> nil then
        begin
          if Node.HasAttribute(Attribute) then
          begin
            Result := Node.GetAttribute(Attribute);
            Exit;
          end;
        end;
      end;
    end;
  end;
end;

{ Retrieve <soap:binding attribute=xxxxx> values - For example, the 'transport' }
{ - 'http://schemas.xmlsoap.org/soap/http' - or the style ( 'rpc' vs. 'document'}
function TWSDLItems.GetSoapBindingAttribute(const BindingName: WideString; Attribute: WideString): WideString;
begin
  Result := GetGenericBindingAttribute(BindingName, SBinding, Soapns, Attribute);
end;

{ Retrieve <http:binding attribute=xxxx> values - For example, 'verb' (GET or POST }
function TWSDLItems.GetHttpBindingAttribute(const BindingName: WideString; Attribute: WideString): WideString;
begin
  Result := GetGenericBindingAttribute(BindingName, SBinding, Httpns, Attribute);
end;

function TWSDLItems.GetHttpBindingAttribute(const QualifiedName: IQualifiedName; Attribute: WideString): WideString;
begin
  Result := '';
  if QualifiedName <> nil then
    Result := GetHttpBindingAttribute(QualifiedName.Name, Attribute);
end;

procedure TWSDLItems.GetOperationsForBinding(const BindingName: WideString;
                                             OperationNames: TWideStrings;
                                             QualifiedNames: Boolean);
var
  I,Count: Integer;
  Bindings: IBindings;
  BindOperations: IBindingOperations;
  BindOperation: IBindingOperation;
begin
  Bindings := Definition.Bindings;
  for Count := 0 to Bindings.Count -1 do
  begin
    if CompareName(Bindings[Count].Name, BindingName) then
    begin
      BindOperations := Bindings[Count].BindingOperations;
      for I := 0 to BindOperations.Count -1 do
      begin
        BindOperation := BindOperations[I];
        if QualifiedNames then
          OperationNames.Add(MakeTNSName(BindOperation.Name))
        else
          OperationNames.Add(BindOperation.Name);
      end;
      break;
    end;
  end;
end;

function TWSDLItems.GetSoapOperationAttribute(const BindingName,Operation, Attribute: WideString): WideString;
var
  Count, I: Integer;
  Bindings: IBindings;
  BindOperations: IBindingOperations;
  SoapOperationNode: IXMLNode;
  Imports: IImports;
  WSDLItems: IWSDLItems;
  XMLNodeList: IXMLNodeList;
begin
  Result := '';
  Bindings := Definition.Bindings;

  for Count := 0 to Bindings.Count -1 do
  begin
    if CompareName(Bindings[Count].Name, BindingName) then
    begin
      BindOperations := Bindings[Count].BindingOperations;
      for I := 0 to BindOperations.Count -1 do
      begin
        if CompareName(BindOperations[I].Name, Operation) then
        begin
          XMLNodeList := BindOperations[I].ChildNodes;
          if XMLNodeList <> nil then
          begin
            SoapOperationNode := XMLNodeList.FindNode(SOperation, Soapns);
            if SoapOperationNode <> nil then
            begin
              if SoapOperationNode.HasAttribute(Attribute) then
              begin
                Result := SoapOperationNode.Attributes[Attribute];
                Exit;
              end;
            end;
          end;
        end;
      end;
    end;
  end;

  { Get any imported WSDL }
  Imports := Definition.Imports;
  if Imports <> nil then
  begin
    for I := 0 to Imports.Count -1 do
    begin
      WSDLItems := TWSDLItems.Create(Self, nil);
      WSDLItems.Load(Imports[I].Location);
      if HasDefinition(WSDLItems) then
        Result := WSDLItems.GetWSDLItems.GetSoapOperationAttribute(BindingName, Operation, Attribute);
      if Result <> '' then
        Exit;
    end;
  end;
end;

{ Returns the value of the 'soapAction' attribute for the specified Binding/Operation }
function TWSDLItems.GetSoapAction(const BindingName, Operation: WideString): WideString;
begin
  Result := GetSoapOperationAttribute(BindingName, Operation, SSoapAction);
end;

{ Returns  the value of the style="xxxx" attribute of the <soap:operation ..> node
  for the specified Binding/Operation combination }
function TWSDLItems.GetSoapOperationStyle(const BindingName, Operation: WideString): WideString;
begin
  Result := GetSoapOperationAttribute(BindingName, Operation, SStyle);
end;


procedure TWSDLItems.GetSoapActionList(const BindingName: WideString; ActionList: TWideStrings; QualifiedNames: Boolean);
var
  Operations: TWideStrings;
  I: Integer;
  Operation: WideString;
begin
  Operations := TWideStrings.Create;
  try
    GetOperationsForBinding(BindingName, Operations, QualifiedNames);
    for I := 0 to (Operations.Count-1) do
    begin
      Operation := Operations.Strings[I];
      ActionList.Add(Operation+'='+GetSoapAction(BindingName, Operation));
    end;
  finally
    Operations.Free;
  end;
end;

function  TWSDLItems.GetSoapBodyInputAttribute(const BindingName, Operation, Attribute: WideString): WideString;
begin
  Result := GetSoapBodyAttribute(BindingName, Operation, SInput, Attribute);
end;

function  TWSDLItems.GetSoapBodyOutputAttribute(const BindingName, Operation, Attribute: WideString): WideString;
begin
  Result := GetSoapBodyAttribute(BindingName, Operation, SOutput, Attribute);
end;

function TWSDLItems.GetSoapBodyAttribute(const BindingName, Operation, IOType, Attribute: WideString): WideString;
var
  I, Index, Count: Integer;
  Bindings: IBindings;
  BindOperations: IBindingOperations;
  IONode, SoapBodyNode: IXMLNode;
  Attr: WideString;
  Imports: IImports;
  WSDLItems: IWSDLItems;
  XMLNodeList: IXMLNodeList;
begin
  Result := '';
  Attr := '';
  Bindings := Definition.Bindings;
  for Count := 0 to Bindings.Count -1 do
  begin
    if CompareName(Bindings[Count].Name, BindingName) then
    begin
      BindOperations := Bindings[Count].BindingOperations;
      for I := 0 to BindOperations.Count -1 do
      begin
        if CompareName(BindOperations[I].Name, Operation) then
        begin
          XMLNodeList := BindOperations[I].ChildNodes;
          IONode := XMLNodeList.FindNode(IOType, Wsdlns);
          if (IONode <> nil) and (IONode.HasChildNodes) then
          begin
            XMLNodeList := IONode.ChildNodes;
            SoapBodyNode := XMLNodeList.FindNode(SBody, Soapns);
            if SoapBodyNode <> nil then
            begin
              if SoapBodyNode.HasAttribute(Attribute) then
              begin
                Result := SoapBodyNode.Attributes[Attribute];
                Exit;
              end;
            end;
          end;
        end;
      end;
    end;
  end;

  { Get any imported WSDL }
  Imports := Definition.Imports;
  if Imports <> nil then
  begin
    for Index := 0 to Imports.Count -1 do
    begin
      WSDLItems := TWSDLItems.Create(Self, nil);
      WSDLItems.Load(Imports[Index].Location);
      if HasDefinition(WSDLItems) then
        Result := WSDLItems.GetWSDLItems.GetSoapBodyAttribute(BindingName, Operation, IOType, Attribute);
      if Result <> '' then
        Exit;
    end;
  end;
end;

function TWSDLItems.GetSoapBodyNamespace(const BindingPortType: WideString): WideString;
var
  Index, Count, I: Integer;
  Bindings: IBindings;
  BindOperations: IBindingOperations;
  Imports: IImports;
  WSDLItems: IWSDLItems;

  function FindSoapBodyNamespace(const Node: IXMLNode): WideString;
  var
    SoapBodyNode: IXMLNode;
  begin
    Result := '';
    if Node.HasChildNodes then
    begin
      SoapBodyNode := Node.ChildNodes.FindNode(SBody, Soapns);
      if Assigned(SoapBodyNode) and SoapBodyNode.HasAttribute(SNamespace) then
         Result := SoapBodyNode.Attributes[SNamespace];
    end;
  end;

begin
  Result := '';
  Bindings := Definition.Bindings;
  for Count := 0 to Bindings.Count -1 do
  begin
    if CompareName(BindingPortType, Bindings[Count].Type_) then
    begin
      BindOperations := Bindings[Count].BindingOperations;
      for I := 0 to BindOperations.Count -1 do
      begin
        Result := FindSoapBodyNamespace(BindOperations[I].Input);
        if Result <> '' then Exit;
        Result := FindSoapBodyNamespace(BindOperations[I].Output);
        if Result <> '' then Exit;
      end;
      break;
    end;
  end;

  { Get any imported WSDL }
  Imports := Definition.Imports;
  if Imports <> nil then
  begin
    for Index := 0 to Imports.Count -1 do
    begin
      WSDLItems := TWSDLItems.Create(Self, nil);
      WSDLItems.Load(Imports[Index].Location);
      if HasDefinition(WSDLItems) then
      begin
        Result := WSDLItems.GetWSDLItems.GetSoapBodyNamespace(BindingPortType);
        if Result <> '' then
          Exit;
      end;
    end;
  end;
end;
(*
procedure TWSDLItems.GetSoapHeaderAttribute(const BindingName, Operation, IOType, Attribute: WideString; SoapHeaderAttrs: TWideStrings);
var
  I,J,K,Count: Integer;
  Bindings: IBindings;
  BindOperations: IBindingOperations;
  IONode, SoapHeaderNode: IXMLNode;
begin

  Bindings := Definition.Bindings;

  for Count := 0 to Bindings.Count -1 do
    if (BindingName = Bindings[Count].Name) then
    begin
      BindOperations := Bindings[Count].BindingOperations;
      for I := 0 to BindOperations.Count -1 do
      begin
        if (Operation = BindOperations[I].Name) then
          for J := 0 to BindOperations[I].ChildNodes.Count -1 do
            if (BindOperations[I].ChildNodes.Nodes[J].NodeName = IOType) then
            begin
              IONode := BindOperations[I].ChildNodes.Nodes[J];
              for K := 0 to IONode.ChildNodes.Count -1 do
                if (IONode.ChildNodes.Nodes[K].NodeName = SWSDLSoapHeader) then
                begin
                  SoapHeaderNode := IONode.ChildNodes[K];
                  if (SoapHeaderNode.Attributes[Attribute] <> Null) then
                    SoapHeaderAttrs.Add(SoapHeaderNode.Attributes[Attribute]);
                end;
              break;
            end;
      end;
      break;
    end;
end;


procedure TWSDLItems.GetSoapFaultsForOperation(const BindingName, Operation: WideString; FaultNames: TWideStrings);
var
  I,J,K,Count: Integer;
  Bindings: IBindings;
  BindOperations: IBindingOperations;
  FaultNode, SoapFaultNode: IXMLNode;
begin

  Bindings := Definition.Bindings;

  for Count := 0 to Bindings.Count -1 do
    if (BindingName = Bindings[Count].Name) then
    begin
      BindOperations := Bindings[Count].BindingOperations;
      for I := 0 to BindOperations.Count -1 do
        if (Operation = BindOperations[I].Name) then
        begin
          for J := 0 to BindOperations[I].ChildNodes.Count -1 do
            if (BindOperations[I].ChildNodes.Nodes[J].NodeName = SFault) then
            begin
              FaultNode := BindOperations[I].ChildNodes.Nodes[J];
              for K := 0 to FaultNode.ChildNodes.Count -1 do
                if (FaultNode.ChildNodes.Nodes[K].NodeName = SWSDLSoapFault) then
                begin
                  SoapFaultNode := FaultNode.ChildNodes[K];
                  if (SoapFaultNode.Attributes[SName] <> Null) then
                    FaultNames.Add(SoapFaultNode.Attributes[SName]);
                end;
            end;
          break;
        end; { end if operation }
      break;
    end; { end if BindingName }
end;


function TWSDLItems.GetSoapFaultAttribute(const BindingName, Operation, FaultName, Attribute: WideString): WideString;
var
  I,J,K,Count: Integer;
  Bindings: IBindings;
  BindOperations: IBindingOperations;
  FaultNode, SoapFaultNode: IXMLNode;
  Attr: WideString;
begin

  Bindings := Definition.Bindings;

  for Count := 0 to Bindings.Count -1 do
    if (BindingName = Bindings[Count].Name) then
    begin
      BindOperations := Bindings[Count].BindingOperations;
      for I := 0 to BindOperations.Count -1 do
        if (Operation = BindOperations[I].Name) then
        begin
          for J := 0 to BindOperations[I].ChildNodes.Count -1 do
            if (BindOperations[I].ChildNodes.Nodes[J].NodeName = SFault) then
            begin
              FaultNode := BindOperations[I].ChildNodes.Nodes[J];
              for K := 0 to FaultNode.ChildNodes.Count -1 do
                if (FaultNode.ChildNodes.Nodes[K].NodeName = SWSDLSoapFault) then
                begin
                  SoapFaultNode := FaultNode.ChildNodes[K];
                  if (SoapFaultNode.Attributes[SName] <> Null) then
                    if (FaultName = SoapFaultNode.Attributes[SName]) then
                      if (SoapFaultNode.Attributes[Attribute] <> Null) then
                         Attr := SoapFaultNode.Attributes[Attribute];
                end;
            end;
          break;
        end; { end if operation }
      break;
    end; { end if BindingName }
  Result := Attr;
end;
*)

function TWSDLItems.HasTypesNode: Boolean;
begin
  Result := False;
  if (Definition.Types <> nil) then
    Result := True;
end;


procedure TWSDLItems.GetSchemas(SchemaNames: TWideStrings);
var
  Types: ITypes;
  Tns: WideString;
  Index: Integer;
begin

  Types := Definition.Types;

  if (Types <> nil) and (Types.SchemaDefs.Count > 0) then
  begin
    for Index := 0 to Types.SchemaDefs.Count - 1 do
    begin
      Tns := Types.SchemaDefs[Index].Attributes[sTns];
      SchemaNames.Add(Tns);
    end;
  end;

end;


function TWSDLItems.GetSchemaNode(const SchemaTns: WideString) : IXMLNode;
var
  Index: Integer;
  Types: ITypes;
  SchemaRootNode: IXMLNode;
begin

  Types := Definition.Types;
  if (Types <> nil) and (Types.SchemaDefs.Count > 0) then
  begin
    for Index := 0 to Types.SchemaDefs.Count - 1 do
    begin
      if ( SchemaTns = Types.SchemaDefs[Index].Attributes[sTns] ) then
      begin
        SchemaRootNode := Types.SchemaDefs[Index] as IXMLNode;
        break;
      end;
    end;
  end;
  Result := SchemaRootNode;
end;

end.
