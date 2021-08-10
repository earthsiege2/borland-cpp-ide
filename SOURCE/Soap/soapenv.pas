{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit SOAPEnv;

interface

uses Classes, SysUtils, xmldom, XMLDoc, XMLIntf, OPConvert;

type
  TSoapEnvelope = class
  public
    function MakeEnvelope(Doc: IXMLDocument; Options: TSOAPConvertOptions): IXMLNode;
    function MakeHeader(ParentNode: IXMLNode): IXMLNode;
    function MakeBody(ParentNode: IXMLNOde): IXMLNode;
    function MakeFault(ParentNode: IXMLNOde): IXMLNode;
  end;

implementation

uses  SOAPConst;

function TSoapEnvelope.MakeEnvelope(Doc: IXMLDocument; Options: TSOAPConvertOptions): IXMLNode;
begin
  Result := Doc.CreateNode(SSoapNameSpacePre + ':' + SSoapEnvelope);
  Result.DeclareNamespace(SSoapNameSpacePre,SSoapNameSpace);
  Result.DeclareNamespace(SXMLSchemaNameSpacePre, XMLSchemaNameSpace);
  Result.DeclareNamespace(SXMLSchemaInstNameSpace99Pre, XMLSchemaInstNameSpace);
  if not (soDocument in Options) then
    Result.DeclareNamespace(SSoapEncodingPre, SSoap11EncodingS5);
  Doc.DocumentElement := Result;
end;


function TSoapEnvelope.MakeBody(ParentNode: IXMLNode): IXMLNode;
begin
   Result := ParentNode.AddChild(SSoapNameSpacePre + ':' + SSoapBody, SSoapNameSpace);
end;

function TSoapEnvelope.MakeHeader(ParentNode: IXMLNode): IXMLNode;
begin
  Result := ParentNode.AddChild(SSoapNameSpacePre + ':' + SSoapHeader, SSoapNameSpace);
end;

function TSoapEnvelope.MakeFault(ParentNode: IXMLNode): IXMLNode;
begin
   Result := ParentNode.AddChild(SSoapNameSpacePre + ':' + SSoapFault, SSoapNameSpace);
end;

end.
