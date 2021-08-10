
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Web services description language (WSDL)        }
{       generation from RTTI                            }
{                                                       }
{   Copyright (c) 2001 Borland Software Corporation     }
{                                                       }
{*******************************************************}

unit WebServExp;

interface

uses
  SysUtils, Classes, {Variants, ActiveX,} IntfInfo, TypInfo, XMLIntf, XMLDoc, xmldom, XmlSchema,
  WSDLIntf, WSDLBind, XMLSchemaTags;

type

  ArgumentType = (argIn, argOut, argInOut, argReturn);

  TSchemaType = record
    TypeName: WideString;
    NameSpace: WideString;
    TypeInfo: PTypeinfo;
    NSPrefix: WideString;
    XSGenerated: Boolean;
  end;

  TSchemaTypeArray = array of TSchemaType;


  TWebServExp = class
  private
    Definition: IDefinition;
    ComplexTypeList: TStringList;
    bHasComplexTypes: Boolean;
    FServiceAddress: WideString;
    FBindingType: TBindingType;
    FWSDLElements: TWSDLElements;
    FImportNames: TWideStrings;
    FImportLocation: TWideStrings;
    FArrayAsComplexContent: Boolean;
    SchemaArray: TSchemaTypeArray;
    FTargetNameSpace: WideString;

    procedure GenerateWSDL(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument;  PortNames, Locations: array of WideString);
    procedure GenerateNestedArraySchema(SchemaDef: IXMLSchemaDef; ComplexType: IXMLComplexTypeDef; const ObjectTypeInfo: PTypeinfo; var Dimension: Integer; Namespace: WideString);
    procedure AddImports(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
    procedure AddTypes(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
    procedure AddMessages(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
    procedure AddPortTypes(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
    procedure AddBinding(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
    procedure AddServices(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument; PortNames: array of WideString; Locations: array of WideString);
    function  GetXMLSchemaType(const ParamTypeInfo: PTypeInfo): string;
    function  GetXMLSchemaTypeName(const ParamTypeInfo: PTypeInfo): WideString;
    function  IsComplexType(const ParamType: TTypeKind ):Boolean;
    procedure SetBindingType(const Value: TBindingType);
    procedure SetServiceAddress(const Value: WideString);
    function  GetImportNamespace(const Index: Integer): WideString;
    procedure SetImportNamespace(const Index: Integer; const Value: WideString);
    function  GetImportLocation(const Index: Integer): WideString;
    procedure SetImportLocation(const Index: Integer; const Value: WideString);
    procedure SetArrayType(const Value: Boolean);
    function  GetPrefixForURI(SchemaDef: IXMLSchemaDef; URI: WideString): WideString; overload;
    function  GetPrefixForURI(Def: IDefinition; URI: WideString): WideString; overload;
    function  GetPrefixForTypeInfo(const ObjectTypeInfo: PTypeinfo): WideString; overload;
    function  AddNamespaceURI(RootNode: IXMLNode; URI: WideString): WideString;
    function  GetNodeNameForURI(SchemaDef: IXMLSchemaDef; URI: WideString): WideString;
    procedure GenerateArraySchema(SchemaDef: IXMLSchemaDef; const ObjectTypeInfo: PTypeinfo; Namespace: WideString);
    procedure GenerateEnumSchema(SchemaDef: IXMLSchemaDef; const ObjectTypeInfo: PTypeinfo; Namespace: WideString);
    procedure GenerateClassSchema(SchemaDef: IXMLSchemaDef; const ObjectTypeInfo, ParentInfo: PTypeinfo; Namespace: WideString);
    procedure GenerateDerivedClassSchema(SchemaDef: IXMLSchemaDef; const ParentTypeInfo: PTypeinfo; Namespace: WideString);
    procedure GetAllSchemaTypes(const IntfMD: TIntfMetaData);
    procedure GetSchemaTypes(const ObjectTypeInfo, ParentInfo: PTypeinfo);
    function  FindOrAddSchema(const ObjectTypeInfo: PTypeinfo; const TnsURI: string): Boolean;
    procedure GetClassSchema(const ObjectTypeInfo, ParentInfo: PTypeinfo);
    procedure GetDerivedClassSchema(const ParentTypeInfo: PTypeinfo);
    function  IsSchemaGenerated(const ObjectTypeInfo: PTypeinfo; const TnsURI: WideString): Boolean;
    procedure GetArraySchema(const ObjectTypeInfo: PTypeinfo);

  public
    constructor Create;
    destructor Destroy; override;
    procedure GetWSDLForInterface(const IntfTypeInfo: Pointer; WSDLDoc: IWSDLDocument; PortNames, Locations: array of WideString);
    procedure GenerateXMLSchema(SchemaDef: IXMLSchemaDef; const ObjectTypeInfo, ParentInfo: PTypeinfo; Namespace: WideString);
    property ImportNames [const Index: Integer]: WideString read GetImportNamespace write SetImportNamespace;
    property ImportLocations[const Index: Integer]: WideString read GetImportLocation write SetImportLocation;
    property TargetNameSpace: WideString read FTargetNameSpace write FTargetNameSpace;

  published
    property ArrayAsComplexContent: Boolean read FArrayAsComplexContent write SetArrayType;
    property BindingType: TBindingType read FBindingType write SetBindingType;
    property ServiceAddress: WideString read FServiceAddress write SetServiceAddress;
    property WSDLElements: TWSDLElements read FWSDLElements write FWSDLElements default [weServiceIntf];
  end;


implementation

uses InvokeRegistry, SOAPConst;

{ WebServExp Implementation }
constructor TWebServExp.Create;
begin
  ComplexTypeList := TStringList.Create;
  FWSDLElements := [weServiceIntf];
  FImportNames := TWideStrings.Create;
  FImportLocation := TWideStrings.Create;
  FArrayAsComplexContent := True;
end;

destructor TWebServExp.Destroy;
begin
  ComplexTypeList.Free;
  FImportNames.Free;
  FImportLocation.Free;
  inherited Destroy;
end;

procedure TWebServExp.SetArrayType(const Value: Boolean);
begin
  FArrayAsComplexContent := Value;
end;

procedure TWebServExp.SetBindingType(const Value: TBindingType);
begin
  FBindingType := Value;
end;

procedure TWebServExp.SetServiceAddress(const Value: WideString);
begin
  FServiceAddress := Value;
end;

function  TWebServExp.GetImportNamespace(const Index: Integer): WideString;
begin
  if FImportNames.Count > Index  then
    Result := FImportNames.Strings[Index]
  else
    Result := '';
end;

function  TWebServExp.GetImportLocation(const Index: Integer): WideString;
begin
  if FImportLocation.Count > Index  then
    Result := FImportLocation.Strings[Index]
  else
    Result := '';
end;

procedure TWebServExp.SetImportNamespace(const Index: Integer; const Value: WideString);
begin
  FImportNames.Insert(Index, Value);
end;

procedure TWebServExp.SetImportLocation(const Index: Integer; const Value: WideString);
begin
  FImportLocation.Insert(Index, Value);
end;

procedure TWebServExp.GetWSDLForInterface(const IntfTypeInfo: Pointer; WSDLDoc: IWSDLDocument; PortNames,  Locations: array of WideString);
var
  IntfMD: TIntfMetaData;
begin

  bHasComplexTypes := False;
  GetIntfMetaData(IntfTypeInfo, IntfMD);
  GenerateWSDL(IntfMD, WSDLDoc, PortNames,  Locations);
end;


procedure TWebServExp.GenerateWSDL(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument; PortNames, Locations: array of WideString);
var
  Encoding: WideString;
begin
  if IntfMD.Name <> '' then
  begin
    { Add WSDL:Definitions and its attributes }
    Definition := WSDLDoc.Definition;
    Definition.Attributes[Sname] := IntfMD.Name+SService;
    if (TargetNamespace <> '') then
    begin
      Definition.Attributes[Stns]  := TargetNamespace;
      Definition.Attributes['xmlns:tns'] := TargetNamespace;
    end;
    //Definition.Attributes['xmlns:xsd'] := Xsdns;  //Need to auto generate Namespace prefix
    Definition.Attributes['xmlns:soap'] := Soapns;
    Definition.Attributes['xmlns:soapenc'] := SSoap11EncodingS5;

    { Add Encoding }
    if WSDLDoc.Encoding = '' then
    begin
      Encoding := InvRegistry.GetWSDLEncoding(IntfMD.Info, '', IntfMD.Name);
      if Encoding <> '' then
        WSDLDoc.Encoding := Encoding
      else
        WSDLDoc.Encoding := 'utf-8';
    end;

     { Set the Namespace prefix }
    (WSDLDoc as IXMLDocumentAccess).DocumentObject.NSPrefixBase := SNsPrefix;

     { Add WSDL Types }
    if (WeTypes in FWSDLElements) or (WeServiceIntf in FWSDLElements) then
      AddTypes(IntfMD, WSDLDoc);
     { Add Imports }
    if (WeImport in FWSDLElements) or (WeServiceImpl in FWSDLElements) then
      if (FImportNames.Count = FImportLocation.Count) then
        AddImports(IntfMD, WSDLDoc);
    { Add WSDL Message and its parts }
    if ((weMessage in FWSDLElements) or (weServiceIntf in FWSDLElements) ) then
      AddMessages(IntfMD, WSDLDoc);
    { Add WSDL PortType and its Operations }
    if ((wePortType in FWSDLElements) or (weServiceIntf in FWSDLElements) ) then
      AddPortTypes(IntfMD, WSDLDoc);
    { Add WSDL Binding for operations }
    if (WeBinding in FWSDLElements) or (weServiceIntf in FWSDLElements) then
      AddBinding(IntfMD, WSDLDoc);
    { Add WSDL Service and its port }
    if (WeService in FWSDLElements) or (WeServiceImpl in FWSDLElements) then
      AddServices(IntfMD, WSDLDoc, PortNames, Locations);
  end;
end;

procedure TWebServExp.AddImports(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
var
  Imports: IImports;
  Index: Integer;
begin
  Imports := WSDLDoc.Definition.Imports;
  for Index := 0 to FImportNames.Count -1 do
    Imports.Add(FImportNames.Strings[Index], FImportLocation.Strings[Index]);
end;

procedure TWebServExp.AddMessages(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
var
  IntfMethArray: TIntfMethEntryArray;
  ParamArray: TIntfParamEntryArray;
  Methods, Params, NoOfMethods, NoOfParams: Integer;
  ParamType: string;
  Messages: IMessages;
  NewMessage: IMessage;
  Parts: IParts;
  MethodExtName, ParamExtName: WideString;
begin

  IntfMethArray := nil;
  ParamArray    := nil;
  IntfMethArray := IntfMD.MDA;
  NoOfMethods   := Length(IntfMethArray);

  { Add WSDL Message and its parts }
  Messages := WSDLDoc.Definition.Messages;

  for Methods := 0 to NoOfMethods -1 do
  begin
    ParamArray := IntfMD.MDA[Methods].Params;
    NoOfParams := Length(ParamArray);

    { Add InOut parts }
    { Note: We always have a Message for the request - irrespective of in parameters }
    MethodExtName := InvRegistry.GetMethExternalName(IntfMD.Info, IntfMD.MDA[Methods].Name);
    NewMessage := Messages.Add(MethodExtName + SRequest);
    Parts := NewMessage.Parts;
    for Params := 0 to NoOfParams -2 do
    begin
      if not (pfOut in ParamArray[Params].Flags) then
      begin
        ParamType := GetXMLSchemaType(ParamArray[Params].Info);
        ParamExtName := InvRegistry.GetParamExternalName(IntfMD.Info, MethodExtName, ParamArray[Params].Name);
        Parts.Add(ParamExtName,'',ParamType);
      end;
    end;

    { Add Out parts }
    { Note: We always have a Message for the response - irrespective of return|out }
    NewMessage := Messages.Add(MethodExtName + SResponse);
    Parts := NewMessage.Parts;
    for Params := 0 to NoOfParams -2 do
      begin
        if ( (pfOut in ParamArray[Params].Flags) or (pfVar in ParamArray[Params].Flags) ) then
        begin
          ParamType := GetXMLSchemaType(ParamArray[Params].Info);
          ParamExtName := InvRegistry.GetParamExternalName(IntfMD.Info, MethodExtName, ParamArray[Params].Name);
          Parts.Add(ParamExtName,'',ParamType);
        end;
      end;

    { For Functions create a response }
    if IntfMD.MDA[Methods].ResultInfo <> nil then
    begin
      ParamType := GetXMLSchemaType(IntfMD.MDA[Methods].ResultInfo);
      Parts.Add(SReturn,'',ParamType);
    end;
  end;

end;

procedure TWebServExp.AddPortTypes(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
var
  IntfMethArray: TIntfMethEntryArray;
//  ParamArray: TIntfParamEntryArray;
  Methods, {Params,} NoOfMethods {, NoOfParams} : Integer;
  PortTypes: IPortTypes;
  PortType: IPortType;
  Operations: IOperations;
  PortExtName, MethodExtName: WideString;
//  HasOut: Boolean;
  TnsPre: WideString;
begin

  { Add WSDL PortType and its Operations }
  IntfMethArray := nil;
  (*
  ParamArray    := nil;
  *)
  IntfMethArray := IntfMD.MDA;
  NoOfMethods   := Length(IntfMethArray);

  PortTypes := WSDLDoc.Definition.PortTypes;
  PortExtName := InvRegistry.GetInterfaceExternalName(IntfMD.Info,'',IntfMD.Name);
  PortType := PortTypes.Add(PortExtName);
  TnsPre := GetPrefixForURI(WSDLDoc.Definition, TargetNameSpace);

  for Methods := 0 to NoOfMethods -1 do
  begin
    Operations := PortType.Operations;

    (* BB - It does not matter whether it's a function or procedure, we need the output node for interop
    HasOut := False;
    ParamArray := IntfMD.MDA[Methods].Params;
    NoOfParams := Length(ParamArray);

    for Params := 0 to NoOfParams -2 do
    begin
      if ((pfOut in ParamArray[Params].Flags) or (pfVar in ParamArray[Params].Flags)) then
        HasOut := True;
    end;

    if ( (IntfMD.MDA[Methods].ResultInfo <> nil) or HasOut ) then
    begin
    *)
      MethodExtName := InvRegistry.GetMethExternalName(IntfMD.Info, IntfMD.MDA[Methods].Name);
         { TODO -oJBB -cBug  : Use IXMLNode.GetPrefixedName instead }
      Operations.Add(MethodExtName, TnsPre+':'+MethodExtName+ SRequest, '',
                     TnsPre+':'+MethodExtName+ SResponse);
    (*
    end
    else
    begin
      MethodExtName := InvRegistry.GetMethExternalName(IntfMD.Info, IntfMD.MDA[Methods].Name);
         { TODO -oJBB -cBug  : Use IXMLNode.GetPrefixedName instead }
      Operations.Add(MethodExtName, TnsPre+':'+MethodExtName+ SRequest, '', '');
    end;
    *)
  end;
end;

procedure TWebServExp.AddBinding(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
var
  IntfMethArray: TIntfMethEntryArray;
  Methods, NoOfMethods: Integer;
  Bindings: IBindings;
  Binding: IBinding;
  BindOperations: IBindingOperations;
  NewBindOperation: IBindingOperation;
  NewNode, SoapBodyNode: IXMLNode;
  PortExtName, MethodExtName: WideString;
  TnsPre: WideString;
begin

  { Add WSDL Binding and its Operations }
  IntfMethArray := nil;
  IntfMethArray := IntfMD.MDA;
  NoOfMethods   := Length(IntfMethArray);

  Bindings := WSDLDoc.Definition.Bindings;
  PortExtName := InvRegistry.GetInterfaceExternalName(IntfMD.Info,'',IntfMD.Name);
  TnsPre := GetPrefixForURI(WSDLDoc.Definition, TargetNameSpace);
  Binding := Bindings.Add(PortExtName+SBinding,TnsPre + ':' + PortExtName);

  { Add Binding specific elements }
  if FBindingType = btSoap then
  begin
    { Add soap:binding }
    NewNode := Binding.AddChild(SBinding, Soapns);
    NewNode.Attributes[SStyle] := 'rpc';
    NewNode.Attributes[STransport] := SSoapHTTPTransport;
  end;

  for Methods := 0 to NoOfMethods -1 do
  begin
    BindOperations := Binding.BindingOperations;
    MethodExtName := InvRegistry.GetMethExternalName(IntfMD.Info, IntfMD.MDA[Methods].Name);
    NewBindOperation := BindOperations.Add(MethodExtName);

    if FBindingType = btSoap then
    begin
      { Add soap:operation }
      NewNode := NewBindOperation.AddChild(SOperation, Soapns);
      NewNode.Attributes[SSoapAction] := InvRegistry.GetActionURIOfInfo(IntfMD.Info, MethodExtName);
      NewNode.Attributes[SStyle] := 'rpc';  {TODO: BB Is this one necessary ?? }
    end;

    { Add input/output }
    NewNode := NewBindOperation.AddChild(SInput);
    if FBindingType = btSoap then
    begin
      SoapBodyNode := NewNode.AddChild(SBody, Soapns);
      //SoapBodyNode.Attributes[SParts] := '';
      SoapBodyNode.Attributes[SUse] := SSoapBodyUseEncoded;
      SoapBodyNode.Attributes[SEncodingStyle] := SSoap11EncodingS5;
      SoapBodyNode.Attributes[SNameSpace] := InvRegistry.GetNamespaceByGUID(IntfMD.IID);

      { According to the spec, we don't really need an <output..> node; however,
        the current version of Axis/Apache is not very happy when that node
        is missing:

          java.lang.NullPointerException
                at org.apache.axis.wsdl.WsdlAttributes.scanBindings(WsdlAttributes.java:271)
                at org.apache.axis.wsdl.WsdlAttributes.init(WsdlAttributes.java:114)
                at org.apache.axis.wsdl.WsdlAttributes.<init>(WsdlAttributes.java:109)
                at org.apache.axis.wsdl.Emitter.emit(Emitter.java:169)
                at org.apache.axis.wsdl.Emitter.emit(Emitter.java:134)
                at org.apache.axis.wsdl.Wsdl2java.main(Wsdl2java.java:199)
        Error in parsing: null

        I've relayed the issue; but in the meantime, we'll output a node anyway
      }
      { if IntfMD.MDA[Methods].ResultInfo <> nil  then }
      begin
        NewNode := NewBindOperation.AddChild(SOutput);
        SoapBodyNode := NewNode.AddChild(SBody, Soapns);
        //SoapBodyNode.Attributes[SParts] := '';
        SoapBodyNode.Attributes[SUse] :=  SSoapBodyUseEncoded;
        SoapBodyNode.Attributes[SEncodingStyle] :=  SSoap11EncodingS5;
        { TODO: Here it seems that more intuitive would be to use the Service's
                TargetNamespace; however, the latter is at the WSDLHTMLPublish component
                while the registry - that's disconnected from that component -
                still needs to resovlve types ???? }
        SoapBodyNode.Attributes[SNameSpace] := InvRegistry.GetNamespaceByGUID(IntfMD.IID);
      end;
    end;

    //Add soap:body
    //Add soap:Header
    //Add soap:Fault
  end;

end;

procedure TWebServExp.AddServices(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument; PortNames: array of WideString; Locations: array of WideString);
var
  Services: IServices;
  NewService: IService;
  NewPort: IPort;
  NewNode: IXMLNode;
  I: Integer;
  PortExtName: WideString;
  TnsPre: WideString;
begin

  Services := WSDLDoc.Definition.Services;
  PortExtName := InvRegistry.GetInterfaceExternalName(IntfMD.Info,'',IntfMD.Name);
  NewService := Services.Add(PortExtName + SService);
  for I := 0 to Length(Locations) - 1 do
  begin
    TnsPre := GetPrefixForURI(WSDLDoc.Definition, TargetNameSpace);
         { TODO -oJBB -cBug  : Use IXMLNode.GetPrefixedName instead }
    NewPort := NewService.Ports.Add(PortNames[I], TnsPre + ':' + PortExtName+SBinding);
    NewNode := NewPort.AddChild(SAddress, Soapns);
    NewNode.Attributes[SLocation] := Locations[I];
  end;
end;

procedure TWebServExp.AddTypes(const IntfMD: TIntfMetaData; WSDLDoc: IWSDLDocument);
var
{  NewNode: IXMLNode; }
  SchemaDef: IXMLSchemaDef;
  Index, Count: Integer;
  UniqueURI: TWideStrings;
begin
  { Collect all schema types to be generated }
  GetAllSchemaTypes(IntfMD);
  if  Length(SchemaArray) > 0 then
  begin
    UniqueURI := TWideStrings.Create;
    try
      { Get Unique URI's and namespace prefix }
      for Index := 0 to Length(SchemaArray) -1 do
      begin
        if (UniqueURI.IndexOf(SchemaArray[Index].NameSpace)= -1) then
          UniqueURI.Add(SchemaArray[Index].NameSpace);
        SchemaArray[Index].NSPrefix := GetPrefixForURI(Definition, SchemaArray[Index].NameSpace);
      end;

      { Add seperate schema nodes for each unique URI }
      for Count := 0 to UniqueURI.Count -1  do
      begin
        SchemaDef := WSDLDoc.Definition.Types.SchemaDefs.Add('',UniqueURI.Strings[Count]);
        for Index := 0 to Length(SchemaArray) -1 do
          GenerateXMLSchema(SchemaDef, SchemaArray[Index].TypeInfo, nil, UniqueURI.Strings[Count]);
      end;
    finally
      UniqueURI.Free;
    end;
  end;
end;

{ NOTE: Consider TOrdType and TFloatType subtypes of tkInteger and tkFloat... }
{ share with TypeTrans.pas ?? }
function TWebServExp.GetXMLSchemaType(const ParamTypeInfo: PTypeInfo):string;
var
  TypeName, URI, Prefix: WideString;
begin

  Prefix := '';
  case ParamTypeInfo^.Kind of
  tkClass, tkDynArray, tkEnumeration, tkSet:
    begin
      { See if it's a predefined XML Schema Type }
      URI := SXMLSchemaURI_2000_10;
      RemTypeRegistry.TypeInfoToXSD(ParamTypeInfo, URI , TypeName);
      if TypeName = '' then
      begin
        URI := SXMLSchemaURI_1999;
        RemTypeRegistry.TypeInfoToXSD(ParamTypeInfo, URI , TypeName);
      end;

      { Here if the URI did not match XMLNamespaces, we're dealing with a non-predefined XML Type }
      if ((URI <> SXMLSchemaURI_2000_10) and (URI <> SXMLSchemaURI_1999) and (URI <> SXMLSchemaURI_2001))  then
      begin
        Prefix := GetPrefixForTypeInfo(ParamTypeInfo);
        if Prefix <> '' then
          Result := Prefix + ':' + GetXMLSchemaTypeName(ParamTypeInfo)
        else
          Result := GetXMLSchemaTypeName(ParamTypeInfo);
      end
      else
      begin
        { We always publish 2001 XMLSchema currently }
        URI := SXMLSchemaURI_2001;
        Prefix := GetPrefixForURI(Definition, URI);
        if Prefix <> '' then
          Result := Prefix + ':' + TypeName
        else
          Result := TypeName;
      end;
      bHasComplexTypes := True;
    end;
  tkVariant:
  begin
    { Always get the prefix for 2001 XMLSchema }
    URI := SXMLSchemaURI_2001;
    Prefix := GetPrefixForURI(Definition, URI);
    if Prefix <> '' then
      Result := Prefix + ':' + SAnySimpleType
    else
      Result := SAnySimpleType;
  end
  else
    { Scalar types }
    URI := SXMLSchemaURI_2000_10;
    RemTypeRegistry.TypeInfoToXSD(ParamTypeInfo, URI , TypeName);
    if TypeName = '' then
    begin
      URI := SXMLSchemaURI_1999;
      RemTypeRegistry.TypeInfoToXSD(ParamTypeInfo, URI , TypeName);
    end;

    { Always get the prefix for 2001 XMLSchema }
    URI := SXMLSchemaURI_2001;
    if TypeName <> '' then
    begin
      Prefix := GetPrefixForURI(Definition, URI);
      if Prefix <> '' then
        Result := Prefix + ':' + TypeName
      else
        Result := TypeName;
    end
    else
      Result := SUnknown;
  end;
end;

function TWebServExp.GetXMLSchemaTypeName(const ParamTypeInfo: PTypeInfo ): WideString;
var
  URI: WideString;
begin
  Result := '';
  RemTypeRegistry.TypeInfoToXSD(ParamTypeInfo, URI, Result);
  if Result = '' then
    Result := ParamTypeInfo.Name;
end;

function TWebServExp.IsComplexType(const ParamType: TTypeKind ):Boolean;
begin
  case ParamType of
    tkClass, tkDynArray, tkEnumeration, tkSet: Result := True;
  else
    Result := False;
  end;
end;

function TWebServExp.GetPrefixForURI(Def: IDefinition; URI: WideString): WideString;
var
  NameSpaceNode: IXMLNode;
begin

  Result := '';
  if Definition <> nil then
  begin
    NamespaceNode := Def.FindNamespaceDecl(URI);
    if NamespaceNode <> nil then
    begin
      Result := NamespaceNode.LocalName;
      exit;
    end;
    Result := AddNamespaceURI(Def as IXMLNode, URI);
  end;
end;


function TWebServExp.GetPrefixForURI(SchemaDef: IXMLSchemaDef; URI: WideString): WideString;
var
  NameSpaceNode: IXMLNode;
begin
  Result := '';
  { Check if the XMLSchema root has it }
  NamespaceNode := SchemaDef.FindNamespaceDecl(URI);
  if NamespaceNode <> nil then
  begin
    Result := NamespaceNode.LocalName;
    exit;
  end
  else
  begin
    { Check if its a WSDL and if the root has it }
    if Definition <> nil then
    begin
      NamespaceNode := Definition.FindNamespaceDecl(URI);
      if NamespaceNode <> nil then
      begin
        Result := NamespaceNode.LocalName;
        exit;
      end
      else
        Result := AddNamespaceURI(Definition as IXMLNode, URI);
    end
    else
      Result := AddNamespaceURI(SchemaDef as IXMLNode, URI);
  end;
end;

function TWebServExp.AddNamespaceURI(RootNode: IXMLNode; URI: WideString): WideString;
begin
  Result := RootNode.OwnerDocument.GeneratePrefix(RootNode);
  RootNode.DeclareNamespace(Result, URI);
end;


function TWebServExp.GetNodeNameForURI(SchemaDef: IXMLSchemaDef; URI: WideString): WideString;
var
  NameSpaceNode: IXMLNode;
begin

  Result := '';
  { Check if the XMLSchema root has it }
  NamespaceNode := SchemaDef.FindNamespaceDecl(URI);
  if NamespaceNode <> nil then
  begin
    Result := NamespaceNode.NodeName;
    exit;
  end
  else
  begin
    { Check if its a WSDL and if the root has it }
    if Definition <> nil then
    begin
      NamespaceNode := Definition.FindNamespaceDecl(URI);
      if NamespaceNode <> nil then
        Result := NamespaceNode.NodeName;
    end;
  end;
end;


procedure TWebServExp.GenerateDerivedClassSchema(SchemaDef: IXMLSchemaDef; const ParentTypeInfo: PTypeinfo; Namespace:WideString);
var
  Count, Index: Integer;
  RegEntry: TRemRegEntry;
begin
  Count := RemClassRegistry.GetURICount;
  for Index := 0 to Count -1 do
  begin
    RegEntry := RemClassRegistry.GetURIMap(Index);
    if RegEntry.ClassType <> nil then
    begin
      if RegEntry.ClassType.InheritsFrom(GetTypeData(ParentTypeInfo).ClassType)
       and (RegEntry.ClassType <> GetTypeData(ParentTypeInfo).ClassType) then
      begin
        GenerateXMLSchema(SchemaDef, RegEntry.Info, ParentTypeInfo, Namespace);
      end;
    end;
  end;
end;

(*
{ Similar to TypInfo's GetPropInfos except that we don't walk up the base classes }
procedure GetPropInfosInternal(TypeInfo: PTypeInfo; PropList: PPropList); assembler;
asm
        { ->    EAX Pointer to type info        }
        {       EDX Pointer to prop list        }
        { <-    nothing                         }

        PUSH    EBX
        PUSH    ESI
        PUSH    EDI

        XOR     ECX,ECX
        MOV     ESI,EAX
        MOV     CL,[EAX].TTypeInfo.Name.Byte[0]
        MOV     EDI,EDX
        XOR     EAX,EAX
        MOVZX   ECX,[ESI].TTypeInfo.Name[ECX+1].TTypeData.PropCount
        REP     STOSD

@outerLoop:
        MOV     CL,[ESI].TTypeInfo.Name.Byte[0]
        LEA     ESI,[ESI].TTypeInfo.Name[ECX+1]
        MOV     CL,[ESI].TTypeData.UnitName.Byte[0]
        MOVZX   EAX,[ESI].TTypeData.UnitName[ECX+1].TPropData.PropCount
        TEST    EAX,EAX
        JE      @parent
        LEA     EDI,[ESI].TTypeData.UnitName[ECX+1].TPropData.PropList

@innerLoop:

        MOVZX   EBX,[EDI].TPropInfo.NameIndex
        MOV     CL,[EDI].TPropInfo.Name.Byte[0]
        CMP     dword ptr [EDX+EBX*4],0
        JNE     @alreadySet
        MOV     [EDX+EBX*4],EDI

@alreadySet:
        LEA     EDI,[EDI].TPropInfo.Name[ECX+1]
        DEC     EAX
        JNE     @innerLoop

@parent:
@exit:
        POP     EDI
        POP     ESI
        POP     EBX
end;

function GetPropListInternal(TypeInfo: PTypeInfo; out PropList: PPropList): Integer;
begin
  Result := GetTypeData(TypeInfo)^.PropCount;
  if Result > 0 then
  begin
    GetMem(PropList, Result * SizeOf(Pointer));
    FillChar(PropList^, Result * SizeOf(Pointer), 0);
    GetPropInfosInternal(TypeInfo, PropList);
  end;
end;

{ Similar to TypInfo's IsStoredProp although this version only handles cases
  where the attribute was assigned 'true' or 'false' directly }
function IsStoredPropInternal(Instance: TObject; PropInfo: PPropInfo): Boolean;
asm
        { ->    EAX Pointer to Instance         }
        {       EDX Pointer to prop info        }
        { <-    AL  Function result             }

        MOV     ECX,[EDX].TPropInfo.StoredProc
        TEST    ECX,0FFFFFF00H
        JE      @@returnCL
        MOV     CL, 1
@@returnCL:
        MOV     AL,CL
@@exit:
end;

{ Returns the TypeInfo of a class member }
function GetMemberTypeInfo(const ObjectTypeInfo: PTypeInfo; const MemberName: string): PTypeInfo;
var
  PropList: PPropList;
  Size, Props: Integer;
begin
  Result := nil;
  Size := GetPropListInternal(ObjectTypeInfo, PropList);
  try
    for Props := 0 to Size -1 do
    begin
      if PropList[Props] <> nil then
      begin
        { Either there's a match or send the only member's TypeInfo back }
        if SameText(PropList[Props].Name, MemberName) or ((MemberName = '') and (Size = 1)) then
        begin
          Result := PropList[Props].PropType^;
          Exit;
        end;
      end;
    end;
  finally
    if Size > 0 then
      FreeMem(PropList);
  end;
end;
 *)

procedure TWebServExp.GenerateClassSchema(SchemaDef: IXMLSchemaDef; const ObjectTypeInfo, ParentInfo: PTypeinfo; Namespace: WideString);
var
  Size, Props: integer;
  PropList: PPropList;
  ComplexType: IXMLComplexTypeDef;
  ElementType: IXMLElementDef;
  AttributeType: IXMLAttributeDef;
  ParamType: string;
  BaseName, Pre: WideString;
  AncInfo: PTypeInfo;
begin
  Size := GetPropListFlat(ObjectTypeInfo, PropList);
  try
    if ParentInfo <> nil then
    begin
      Pre := GetPrefixForTypeInfo(ParentInfo);
      if Pre <> '' then
        BaseName := Pre + ':' +  ParentInfo.Name
      else
        BaseName := ParentInfo.Name;
      ComplexType := SchemaDef.ComplexTypes.Add(GetXMLSchemaTypeName(ObjectTypeInfo), BaseName);
      if GetTypeData(ParentInfo).ParentInfo <> nil then
        AncInfo := GetTypeData(ParentInfo).ParentInfo^
      else
        AncInfo := nil;
      if (AncInfo <> nil) and (GetTypeData(AncInfo).ClassType = TRemotable) then
        AncInfo := nil;
      GenerateXMLSchema(SchemaDef, ParentInfo, AncInfo, Namespace);
      ComplexType := SchemaDef.ComplexTypes.Add(GetXMLSchemaTypeName(ObjectTypeInfo), BaseName)
    end else
      ComplexType := SchemaDef.ComplexTypes.Add(GetXMLSchemaTypeName(ObjectTypeInfo));

    for Props := 0 to Size -1 do
    begin
      if PropList[Props] <> nil then
      begin
        ParamType := GetXMLSchemaType(PropList[Props].PropType^);
        if IsStoredPropConst(nil, PropList[Props]) then
          ElementType := ComplexType.ElementDefs.Add(PropList[Props].Name, ParamType)
        else
          AttributeType := ComplexType.AttributeDefs.Add(PropList[Props].Name, ParamType);
        if IsComplexType(PropList[Props].PropType^.Kind) then
          GenerateXMLSchema(SchemaDef, PropList[Props].PropType^, nil, Namespace);
      end;
    end;
  finally
    if Size > 0 then
      FreeMem(PropList);
  end;
end;


procedure TWebServExp.GenerateEnumSchema(SchemaDef: IXMLSchemaDef; const ObjectTypeInfo: PTypeinfo; Namespace: WideString);
var
  SimpleType: IXMLSimpleTypeDef;
  TypeData: PTypeData;
  Index: Integer;
  Value: string;
begin
  { Here we need to shortcircuit ByteBool, WordBool and LongBool - the
    RTTI/Compiler treats them as enumerations with 256, 32K and 2G members
    respectively - We don't want to publish these members:) }
  if (ObjectTypeInfo = TypeInfo(System.ByteBool)) or
     (ObjectTypeInfo = TypeInfo(System.WordBool)) or
     (ObjectTypeInfo = TypeInfo(System.LongBool)) then
    raise Exception.Create(sInvalidBooleanParameter);
  TypeData := GetTypeData(ObjectTypeInfo);
  if TypeData <> nil then
  begin
    SimpleType := SchemaDef.SimpleTypes.Add(GetXMLSchemaTypeName(ObjectTypeInfo), 'string');
    for Index := 0 to TypeData.MaxValue do
    begin
      Value := GetEnumName(ObjectTypeInfo, Index);
      SimpleType.Enumerations.Add(Value);
    end;
  end;
end;


procedure TWebServExp.GenerateArraySchema(SchemaDef: IXMLSchemaDef; const ObjectTypeInfo: PTypeinfo; Namespace: WideString);
var
  ComplexType: IXMLComplexTypeDef;
  ElementType: IXMLElementDef;
  ElementTypeInfo: PTypeinfo;
  I, Dimensions: integer;
  ParamType, ArrayElementName: string;
  ArrayType: string;
  TypeName, Prefix, SoapEncPrefix: WideString;
  AttrDef: IXMLAttributeDef;
  DimString, ArrayName, TempName: string;
  XMLElementDefs: IXMLElementDefs;
begin
  if FArrayAsComplexContent then
  begin
    ElementTypeInfo := GetDynArrayNextInfo2(ObjectTypeInfo, ArrayName);
    Dimensions := 1;
    while (ElementTypeInfo <> nil) and  (ElementTypeInfo.Kind = tkDynArray ) and (ElementTypeInfo.Name[1] = '.') do
    begin
      Inc(Dimensions);
      ElementTypeInfo := GetDynArrayNextInfo2(ElementTypeInfo, TempName);
    end;
    if (ElementTypeInfo = nil) or (ElementTypeInfo.Name[1] = '.') then
      GetDynArrayElTypeInfo(ObjectTypeInfo, ElementTypeInfo, Dimensions);
    {
    if (ElementTypeInfo.Kind = tkDynArray) and (ArrayName <> '') and (ArrayName[1] <> '.') then
      GenerateArraySchema(RootNode, ElementTypeInfo, Namespace);
    if (ElementTypeInfo.Kind = tkClass) or (ElementTypeInfo.Kind = tkEnumeration) then
      GenerateXMLSchema(RootNode, ElementTypeInfo, nil, Namespace);
    }
    ParamType := GetXMLSchemaType(ElementTypeInfo);
    ArrayType := SArrayOf + ParamType;
    { Get Soap Encoding prefix }
    SoapEncPrefix := GetPrefixForURI(SchemaDef,  SSoap11EncodingS5);
    TypeName := GetXMLSchemaTypeName(ObjectTypeInfo);
    ComplexType := SchemaDef.ComplexTypes.Add(TypeName, SoapEncPrefix + ':' + SSoapEncodingArray, dmComplexRestriction);
    AttrDef:= ComplexType.AttributeDefs.Add(SoapEncPrefix + ':'+ SArrayType);
    { Get WSDL URI prefix }
    Prefix := GetNodeNameForURI(SchemaDef, Wsdlns);
    { Create dimension string }
    DimString := '[';
    if (Dimensions > 1) then
      for I := 1 to Dimensions-1 do
        DimString := DimString + ',';
    DimString := DimString + ']';
    { Blast it out }
    AttrDef.Attributes['n1'+':'+SArrayType] := ParamType + DimString;
    AttrDef.Attributes[Prefix+':'+'n1'] := Wsdlns;
  end
  else
  begin
    GetDynArrayElTypeInfo(ObjectTypeInfo, ElementTypeInfo, Dimensions);
    ParamType := GetXMLSchemaType(ElementTypeInfo);
    ArrayType := SArrayOf + ParamType;
    XMLElementDefs := SchemaDef.ElementDefs;
    Prefix := GetPrefixForURI(SchemaDef, Soapns);
    TypeName := GetXMLSchemaTypeName(ObjectTypeInfo);
    ElementType := XMLElementDefs.Add(TypeName, True, MakeNodeName(Prefix, SArray));
  {  ElementType := RootNode.SchemaDef.ElementDefs.Add(ObjectTypeInfo.Name, True, SSoapArray); }
  {  ElementType := SchemaDef.ElementDefs.Add(ObjectTypeInfo.Name, True, SSoapArray); }
    ComplexType := ElementType.DataType as IXMLComplexTypeDef;
    ComplexType.Attributes[SName] := ArrayType;

    if Dimensions > 1  then
      GenerateNestedArraySchema(SchemaDef, ComplexType, ElementTypeInfo, Dimensions, Namespace)
    else
    begin
      ArrayElementName := 'Dimension' + IntToStr(Dimensions);
      ParamType := GetXMLSchemaType(ElementTypeInfo);
      ElementType := ComplexType.ElementDefs.Add(ArrayElementName, ParamType);
      ElementType.Attributes[SMaxOccurs] := SUnbounded;

      if IsComplexType(ElementTypeInfo.Kind) then
        GenerateXMLSchema(SchemaDef, ElementTypeInfo, nil, Namespace);
    end;
  end;
end;


procedure TWebServExp.GenerateNestedArraySchema(SchemaDef: IXMLSchemaDef; ComplexType: IXMLComplexTypeDef; const ObjectTypeInfo: PTypeinfo; var Dimension: Integer; Namespace: WideString);
var
  ParamType: string;
  ArrayElementName: String;
  ElementType: IXMLElementDef;
  NestedType: IXMLComplexTypeDef;
begin
  while Dimension <> 0 do
  begin
    if Dimension > 1  then
    begin
      ArrayElementName := 'Dimension' + IntToStr(Dimension);
      ElementType := ComplexType.ElementDefs.Add(ArrayElementName, True);
      ElementType.Attributes[SMaxOccurs] := SUnbounded;
      NestedType := ElementType.DataType as IXMLComplexTypeDef;
      Dimension := Dimension -1;
      GenerateNestedArraySchema(SchemaDef, NestedType, ObjectTypeInfo, Dimension, Namespace);
    end
    else
    begin
      ArrayElementName := 'Dimension' + IntToStr(Dimension);
      ParamType := GetXMLSchemaType(ObjectTypeInfo);
      ElementType := ComplexType.ElementDefs.Add(ArrayElementName, ParamType);
      ElementType.Attributes[SMaxOccurs] := SUnbounded;
      Dimension := Dimension -1;

      if IsComplexType(ObjectTypeInfo.Kind) then
        GenerateXMLSchema(SchemaDef, ObjectTypeInfo, nil, Namespace);
    end;
  end; //while
end;


procedure TWebServExp.GenerateXMLSchema(SchemaDef: IXMLSchemaDef; const ObjectTypeInfo, ParentInfo: PTypeinfo; Namespace: WideString);
var
  TempURI, TempName: WideString;
  AncInfo: PTypeInfo;
begin
  if  IsComplexType(ObjectTypeInfo.Kind) then
  begin
    { NOTE: IsSchemaGenerated will toggle the generated flag if it returns false }
    if (not IsSchemaGenerated(ObjectTypeInfo, Namespace)) then
    begin
      case ObjectTypeInfo.Kind  of
        tkDynArray:     GenerateArraySchema(SchemaDef, ObjectTypeInfo, NameSpace);
        tkEnumeration:  GenerateEnumSchema(SchemaDef, ObjectTypeInfo, NameSpace);
        tkClass:
          begin
            { Determine the base class info. }
            if (ParentInfo = nil) and ((GetTypeData(ObjectTypeInfo).ParentInfo)^ <> nil) then
            begin
              AncInfo := (GetTypeData(ObjectTypeInfo).ParentInfo)^;
              if (AncInfo <> nil) and not RemTypeRegistry.TypeInfoToXSD(AncInfo, TempURI , TempName) then
                AncInfo := nil;
              if (AncInfo <> nil) and (GetTypeData(AncInfo).ClassType = TRemotable) then
                AncInfo := nil;
            end else
              AncInfo := ParentInfo;

            GenerateClassSchema(SchemaDef, ObjectTypeInfo, AncInfo, Namespace);
            { Generate XML Schema for registered derived classes }
            GenerateDerivedClassSchema(SchemaDef, ObjectTypeInfo, Namespace);
          end;
      end;
    end;
  end;
end;


procedure TWebServExp.GetAllSchemaTypes(const IntfMD: TIntfMetaData);
var
  Methods, Params, NoOfMethods, NoOfParams: Integer;
  IntfMethArray: TIntfMethEntryArray;
  ParamArray: TIntfParamEntryArray;
begin
  IntfMethArray := nil;
  ParamArray    := nil;
  IntfMethArray := IntfMD.MDA;
  NoOfMethods   := Length(IntfMethArray);

  for Methods := 0 to NoOfMethods -1 do
  begin
    ParamArray := IntfMD.MDA[Methods].Params;
    NoOfParams := Length(ParamArray);

    { Note: Skip this/Self }
    for Params := 0 to NoOfParams -2 do
    begin
      if IsComplexType(ParamArray[Params].Info.Kind) then
        GetSchemaTypes(ParamArray[Params].Info, nil);
    end;

    { For Function return type }
    if IntfMD.MDA[Methods].ResultInfo <> nil  then
    begin
      { If the return type is an object }
      if IsComplexType(IntfMD.MDA[Methods].ResultInfo.Kind) then
        GetSchemaTypes(IntfMD.MDA[Methods].ResultInfo, nil);
    end;
  end;
end;

procedure TWebServExp.GetDerivedClassSchema(const ParentTypeInfo: PTypeinfo);
var
  Count, Index: Integer;
  RegEntry: TRemRegEntry;
begin
  Count := RemClassRegistry.GetURICount;
  for Index := 0 to Count -1 do
  begin
    RegEntry := RemClassRegistry.GetURIMap(Index);
    if RegEntry.ClassType <> nil then
    begin
      if RegEntry.ClassType.InheritsFrom(GetTypeData(ParentTypeInfo).ClassType) then
        GetSchemaTypes(RegEntry.Info, ParentTypeInfo);
    end;
  end;
  { This code is suspcious - ParentTypeInfo will be the type of a class we're
    publishing. Why would we want to publish other classes that are sibling
    to this class ??  (BB)
    NOTE: It would make more sense to try to publish base types - up to
          TRemotable!!
  if GetTypeData(ParentTypeInfo).ParentInfo <> nil then
    GetDerivedClassSchema(GetTypeData(ParentTypeInfo).ParentInfo^);
  }
end;

function TWebServExp.FindOrAddSchema(const ObjectTypeInfo: PTypeinfo; const TnsURI: string): Boolean;
var
  Index: Integer;
begin
  Result := False;

  { Do not register Empty TnsURI or tkSet or any predefined type from XMLSchema }
  if ((TnsURI = '') or (ObjectTypeInfo.Kind = tkSet) or (TnsURI = SXMLSchemaURI_1999) or  (TnsURI = SXMLSchemaURI_2000_10) or
    (TnsURI = SXMLSchemaURI_2001))  then
  begin
    Result := True;
    Exit;
  end;

  for Index := 0 to Length(SchemaArray) -1 do
  begin
    if SchemaArray[Index].TypeInfo = ObjectTypeInfo then
    begin
      Result := True;
      Exit;
    end;
  end;

  { Add new type }
  Index := Length(SchemaArray);
  SetLength(SchemaArray, Index+1);
  SchemaArray[Index].TypeName := GetXMLSchemaTypeName(ObjectTypeInfo);
  SchemaArray[Index].NameSpace := TnsURI;
  SchemaArray[Index].TypeInfo := ObjectTypeInfo;
  SchemaArray[Index].XSGenerated := False;
end;

{ NOTE: IsSchemaGenerated has a nasty side-effect - if the generated flag is false, it will
        toggle it - Argghh!! }
function TWebServExp.IsSchemaGenerated(const ObjectTypeInfo: PTypeinfo; const TnsURI: WideString): Boolean;
var
  Index: Integer;
begin
  Result := True;
  for Index := 0 to Length(SchemaArray) -1 do
  begin
    if ((SchemaArray[Index].TypeInfo = ObjectTypeInfo) and
      (SchemaArray[Index].NameSpace = TnsURI) ) then
    begin
      if  SchemaArray[Index].XSGenerated = False then
      begin
        Result := False;
        SchemaArray[Index].XSGenerated := True;
      end
      else
        Result := True;
      Exit;
    end;
  end;
end;


function  TWebServExp.GetPrefixForTypeInfo(const ObjectTypeInfo: PTypeinfo): WideString;
var
  Index: Integer;
begin
  Result := '';
  for Index := 0 to Length(SchemaArray) -1 do
  begin
    if (SchemaArray[Index].TypeInfo = ObjectTypeInfo) then
    begin
      Result := SchemaArray[Index].NSPrefix;
      exit;
    end;
  end;
end;


procedure TWebServExp.GetSchemaTypes(const ObjectTypeInfo, ParentInfo: PTypeinfo);
var
  URI, Name: WideString;
  IsScalar, Registered: Boolean;
begin
  if  IsComplexType(ObjectTypeInfo.Kind) then
  begin
    Registered := RemClassRegistry.InfoToURI(ObjectTypeInfo, URI, Name, IsScalar);
    { NOTE: If the user forgot to register the type, and
            auto-registration is probably turned off ??? }
    if not Registered then
    begin
    { NOTE: If the user forgot to register the type, and
            auto-registration is probably turned off ??? }
      ;
    end;

    { Add to the SchemaArray to keep track of what complex type has }
    { already been encountered                                      }
    if (not FindOrAddSchema(ObjectTypeInfo, URI)) then
    begin
      case ObjectTypeInfo.Kind  of
        tkDynArray:  GetArraySchema(ObjectTypeInfo);
        //tkEnumeration:  GenerateEnumSchema(RootNode,ObjectTypeInfo);
        tkClass:
          begin
            GetClassSchema(ObjectTypeInfo, ParentInfo);
            { Get all the registered derived classes }
            GetDerivedClassSchema(ObjectTypeInfo);
          end;
      end;
    end;
  end;
end;

procedure TWebServExp.GetClassSchema(const ObjectTypeInfo, ParentInfo: PTypeinfo);
var
  Size, Props: integer;
  PropList: PPropList;
begin

  Size := GetPropList(ObjectTypeInfo, [tkUnknown..tkDynArray], nil);
  if Size > 0 then
  begin
    PropList := AllocMem(sizeof(TPropInfo) * Size);
    try
      Size := GetPropList(ObjectTypeInfo, PropList);
      for Props := 0 to Size -1 do
      begin
        if IsComplexType(PropList[Props].PropType^.Kind) then
          GetSchemaTypes(PropList[Props].PropType^, nil);
      end;
    finally
      FreeMem(PropList);
    end;
  end; //Size > 0
end;


procedure TWebServExp.GetArraySchema(const ObjectTypeInfo: PTypeinfo);
var
  ElementTypeInfo: PTypeInfo;
  Dimensions: Integer;
  ArrayName, TempName: String;
begin
  ElementTypeInfo := GetDynArrayNextInfo2(ObjectTypeInfo, ArrayName);
  Dimensions := 1;
  { When the compiler generates *intermediate* typeinfos for multidim arrays, the
    ElementTypeInfo name is '.#'; so we can use the '.' to detect this case }
  while (ElementTypeInfo <> nil) and  (ElementTypeInfo.Kind = tkDynArray ) and (ElementTypeInfo.Name[1] = '.') do
  begin
    Inc(Dimensions);
    ElementTypeInfo := GetDynArrayNextInfo2(ElementTypeInfo, TempName);
  end;
  if (ElementTypeInfo = nil) or (ElementTypeInfo.Name[1] = '.') then
    GetDynArrayElTypeInfo(ObjectTypeInfo, ElementTypeInfo, Dimensions);

  if (ElementTypeInfo.Kind = tkDynArray) and (ArrayName <> '') and (ArrayName[1] <> '.') then
    GetSchemaTypes(ElementTypeInfo, nil);
  if (ElementTypeInfo.Kind = tkClass) or (ElementTypeInfo.Kind = tkEnumeration) then
    GetSchemaTypes(ElementTypeInfo, nil);
  {
  GetDynArrayElTypeInfo(ObjectTypeInfo, ElementTypeInfo, Dim);
  if ElementTypeInfo <> nil then
    GetSchemaTypes(ElementTypeInfo, nil);
  }
end;

initialization

finalization
end.
