
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       XML Data File to XML Schema Translator          }
{                                                       }
{     Copyright (c) 2000 Borland Software Corporation   }
{                                                       }
{*******************************************************}

unit XMLDataToSchema;

interface

uses Variants, SysUtils, Classes, XMLDOM, XMLDoc, XMLIntf, XMLSchema;

type

{ TXMLDataTranslator }

  TXMLDataImporter = class(TXMLSchemaTranslator)
  private
    FXMLDoc: IXMLDocument;
  protected
    function AddComplexType(const Node: IXMLNode): DOMString;
    function GetDataType(const Node: IXMLNode): DOMString;
    function IsComplexType(const Node: IXMLNode): Boolean;
    procedure Translate(const FileName: WideString; const SchemaDef: IXMLSchemaDef); override;
    procedure ValidateExistingType(const ExistingType: IXMLComplexTypeDef;
      const Node: IXMLNode);
    { Data member access }
    property XMLDoc: IXMLDocument read FXMLDoc;
  end;

const
  SXMLDataExtension = '.xml';

implementation

uses XMLSchemaTags;

const
  TypeSuffix = 'Type';
  
resourcestring
  SDescription = 'XMLData to XML Schema Translator (.xml -> .xsd)';

var
  TranslatorFactory: IXMLSchemaTranslatorFactory;

{ TXMLDataImporter }

function TXMLDataImporter.GetDataType(const Node: IXMLNode): DOMString;
const
  Digits = ['0'..'9'];
var
  Len, I: Integer;
  Value: string;
begin
  { Basic routine to try and determine the data type of a node's value.
    Currently only tries to detect integers and decimals }
  Value := VarToStr(Node.NodeValue);
  if Value = '' then
  begin
    Result := xsdString;
    Exit;
  end;
  Len := Length(Value);
  Result := '';
  for I := 1 to Len do
    if not (Value[I] in (Digits + [DecimalSeparator])) then
    begin
      Result := xsdString;
      Exit;
    end else if Value[I] = DecimalSeparator then
      Result := xsdDecimal;
  if Result = '' then
    Result := xsdInteger;
end;

function TXMLDataImporter.IsComplexType(const Node: IXMLNode): Boolean;
var
  I: Integer;
begin
  Result :=  Node.AttributeNodes.Count > 0;
  if not Result then
    for I := 0 to Node.ChildNodes.Count - 1 do
      if Node.ChildNodes[I].NodeType = ntElement then
      begin
        Result := True;
        Break;
      end;
end;

function TXMLDataImporter.AddComplexType(const Node: IXMLNode): DOMString;

  function MakeTypeName(const Name: string): DOMString;
  var
    TypePos: Integer;
  begin
    TypePos := Pos(TypeSuffix, Name);
    if (TypePos = 0) or (TypePos <> (Length(Name) + 1 - Length(TypeSuffix))) then
      Result := Name + TypeSuffix
    else
      Result := Name;
  end;

  procedure ProcessChildNodes(ComplexTypeDef: IXMLComplexTypeDef);
  var
    I: Integer;
    BaseName, ChildType: DOMString;
    ChildNode: IXMLNode;
    ElementDef: IXMLElementDef;
  begin
    with ComplexTypeDef do
      for I := 0 to Node.ChildNodes.Count - 1 do
      begin
        ChildNode := Node.ChildNodes[I];
        if ChildNode.NodeType = ntElement then
        begin
          BaseName := ExtractLocalName(ChildNode.NodeName);
          ElementDef := ElementDefs.Find(BaseName);
          if not Assigned(ElementDef) then
          begin
            if IsComplexType(ChildNode) then
              ChildType := AddComplexType(ChildNode) else
              ChildType := GetDataType(ChildNode);
            ElementDefs.Add(BaseName, ChildType);
          end else
          begin
            ElementDef.MaxOccurs := SUnbounded;
            { Determine if this node is different than any we've already seen }
            if ElementDef.DataType.IsComplex then
              ValidateExistingType(ElementDef.DataType as IXMLComplexTypeDef,
                ChildNode);
          end;
        end;
      end;
  end;

  procedure ProcessAttributes(ComplexTypeDef: IXMLComplexTypeDef);
  var
    I: Integer;
    BaseName: DOMString;
    AttributeNode: IXMLNode;
  begin
    with ComplexTypeDef do
      for I := 0 to Node.AttributeNodes.Count - 1 do
      begin
        AttributeNode := Node.AttributeNodes[I];
        BaseName := ExtractLocalName(AttributeNode.NodeName);
        { Ignore 'xmlns' and any other reserved xml attributes }
        if Pos('xml', attributeNode.Prefix) <> 1 then
          if AttributeDefs.IndexOfItem(BaseName) = -1 then
            AttributeDefs.Add(BaseName, GetDataType(AttributeNode));
      end;
  end;

var
  NewType, ExistingType: IXMLComplexTypeDef;
begin
  Result := MakeTypeName(ExtractLocalName(Node.NodeName));
  ExistingType := SchemaDef.ComplexTypes.Find(Result);
  if ExistingType = nil then
  begin
    if not Node.IsTextElement then
    begin
      NewType := SchemaDef.ComplexTypes.Add(Result);
      ProcessChildNodes(NewType);
    end else
      NewType := SchemaDef.ComplexTypes.Add(Result, xsdString, dmSimpleRestriction, cmEmpty);
    ProcessAttributes(NewType);
  end else
    ValidateExistingType(ExistingType, Node);
end;

procedure TXMLDataImporter.ValidateExistingType(
  const ExistingType: IXMLComplexTypeDef; const Node: IXMLNode);
var
  I, J: Integer;
  BaseName, ChildType: DOMString;
  AttrNode, ChildNode: IXMLNode;
  AttrDef: IXMLAttributeDef;
  ElementDef: IXMLElementDef;
begin
  if not Node.IsTextElement then
    for I := 0 to Node.ChildNodes.Count - 1 do
    begin
      ChildNode := Node.ChildNodes[I];
      if ChildNode.NodeType <> ntElement then continue;
      BaseName := ExtractLocalName(ChildNode.NodeName);
      ElementDef := ExistingType.ElementDefs.Find(BaseName);
      { If element didn't occur previously, then add it now }
      if not Assigned(ElementDef) then
      begin
        if IsComplexType(ChildNode) then
          ChildType := AddComplexType(ChildNode) else
          ChildType := GetDataType(ChildNode);
        ExistingType.ElementDefs.Add(BaseName, ChildType);
      end else
      begin
        { Check if the element is repeated in this node, if it wasn't previously }
        if ElementDef.MaxOccurs <> SUnbounded then
          for J := I + 1 to Node.ChildNodes.Count - 1 do
            if Node.GetChildNodes[J].NodeName = ChildNode.NodeName then
            begin
              ElementDef.MaxOccurs := SUnbounded;
              Break;
            end;
        { Validate the children of this node as well }
        if ElementDef.DataType.IsComplex then
          ValidateExistingType(ElementDef.DataType as IXMLComplexTypeDef, ChildNode);
      end;
    end;

  { If an attribute didn't occur previously, then add it now }
  for I := 0 to Node.AttributeNodes.Count - 1 do
  begin
    AttrNode := Node.AttributeNodes[I];
    BaseName := ExtractLocalName(AttrNode.NodeName);
    AttrDef := ExistingType.AttributeDefs.Find(BaseName);
    if not Assigned(AttrDef) then
      ExistingType.AttributeDefs.Add(BaseName, GetDataType(AttrNode));
  end;

  { If an existing element doesn't appear here, then mark it as optional }
  for I := 0 to ExistingType.ElementDefs.Count - 1 do
  begin
    ElementDef := ExistingType.ElementDefs[I];
    if (ElementDef.MinOccurs <> '0') and
       (Node.ChildNodes.FindNode(ElementDef.Name) = nil) then
      ElementDef.MinOccurs := '0';
  end;

end;

procedure TXMLDataImporter.Translate(const FileName: WideString;
  const SchemaDef: IXMLSchemaDef);
begin
  inherited;
  FXMLDoc := LoadXMLDocument(FileName);
  if Assigned(XMLDoc.DocumentElement) then
  begin
    if XMLDoc.DocumentElement.NamespaceURI <> '' then
      with XMLDoc.DocumentElement do
        SchemaDef.SetTargetNamespace(NamespaceURI, Prefix);
    if IsComplexType(XMLDoc.DocumentElement) then
    begin
      SchemaDef.ElementDefs.Add(ExtractLocalName(XMLDoc.DocumentElement.NodeName),
        XMLDoc.DocumentElement.NodeName+TypeSuffix);
      AddComplexType(XMLDoc.DocumentElement);
    end;
  end;
end;

initialization
  TranslatorFactory := TXMLSchemaTranslatorFactory.Create(TXMLDataImporter, nil,
    SXMLDataExtension, SDescription);
  RegisterSchemaTranslator(TranslatorFactory);
finalization
  UnRegisterSchemaTranslator(TranslatorFactory);
end.

