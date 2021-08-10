{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       XML Document Support                            }
{                                                       }
{       Copyright (c) 2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit XSLProd;

interface

uses
{$IFDEF MSWINDOWS}
  Windows, Messages, SysUtils, Classes, HTTPApp, HTTPProd, XMLDoc, xmldom, XMLIntf,
  WebComp;
{$ENDIF}
{$IFDEF LINUX}
  SysUtils, Classes, HTTPApp, HTTPProd, XMLDoc, xmldom, XMLIntf,
  WebComp;
{$ENDIF}

type
  TCustomXSLPageProducer = class(TXMLDocument, IProduceContent, IProduceContentFrom,
    ISetAppDispatcher, IGetAppDispatcher, IProducerEditorViewSupport,
    IGetProducerTemplate)
  private
    FXMLData: TComponent;
    FDispatcher: TComponent;
    procedure SetXMLData(const Value: TComponent);
    function GetXSLStream(var AOwned: Boolean): TStream;
    function GetDispatcher: IWebDispatcherAccess;
    procedure SetDispatcher(Value: TComponent);
  protected
    function GetXMLDocument(out AXMLDocument: IXMLDocument): Boolean;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    function GetTemplateStream(out AOwned: Boolean): TStream;
    { IGetProducerTemplate }
    function GetProducerTemplateStream(out AOwned: Boolean): TStream;
    function GetProducerTemplateFileName: string;
    { IProducerEditorViewSupport }
    function HasScriptView: Boolean;
    function HasXMLBrowserView: Boolean;
    function HasXSLBrowserView: Boolean;
    function HasHTMLBrowserView: Boolean;
    function GetXMLData(var Owned: Boolean): TStream;
    function GetXSLData(var Owned: Boolean): TStream;
    function GetTemplateFileType: string;
    { ISetAppDispatcher }
    procedure SetAppDispatcher(const ADispatcher: TComponent);
    { IGetAppDispatcher }
    function GetAppDispatcher: TComponent;
    { IProduceContent }
    function ProduceContent: string;
    { IProduceContentFrom }
    function ProduceContentFromStream(Stream: TStream): string;
    function ProduceContentFromString(const S: string): string;
  public
    function ContentFromString(const S: string): string;
    function ContentFromStream(InStream: TStream): string; virtual;
    function Content: string; virtual;
    function ContentFromWideString(const S: WideString): string; virtual;
    property Dispatcher: IWebDispatcherAccess read GetDispatcher;
    property DispatcherComponent: TComponent read FDispatcher;
    property XMLData: TComponent read FXMLData write SetXMLData;
  end;

  TXSLPageProducer = class(TCustomXSLPageProducer)
  published
    property XMLData;
  end;

  EXSLPageProducerError = class(EWebBrokerException)
  end;

implementation

uses SiteConst;

function ExtractAttrValue(const AttrName, AttrLine: string;
  const Default: DOMString = ''): DOMString;
var
  P: PChar;
  LineLen, ItemPos: Integer;
begin
  ItemPos := Pos(AttrName, AttrLine);
  LineLen := Length(AttrLine);
  if ItemPos > 0 then
  begin
    Inc(ItemPos, Length(AttrName));
    while (ItemPos < LineLen) and not (AttrLine[ItemPos] in ['''','"']) do
      Inc(ItemPos);
    if ItemPos < LineLen then
    begin
      P := PChar(AttrLine)+ItemPos-1;
      Result := AnsiExtractQuotedStr(P, P^);
    end;
  end
  else
    Result := Default;
end;

procedure RaiseXSLPageProducerError(const Msg: string); overload;
begin
  raise EXSLPageProducerError.Create(Msg);
end;

procedure RaiseNoXMLDocument;
begin
  RaiseXSLPageProducerError(sNoXMLDocument);
end;

procedure RaiseNoXMLData;
begin
  RaiseXSLPageProducerError(sNoXMLData);
end;

{ TCustomXSLPageProducer }

function TCustomXSLPageProducer.ContentFromStream(InStream: TStream): string;
var
  XMLDocument: IXMLDocument;
  W: WideString;
begin
  if XMLData = nil then
    RaiseNoXMLData;
  if GetXMLDocument(XMLDocument) then
  begin
    Self.LoadFromStream(InStream);
    XMLDocument.Active := True;
    if Self.DocumentElement = nil then
      RaiseNoXMLDocument
    else if XMLDocument.Node = nil then
      RaiseNoXMLData;
    XMLDocument.Node.TransformNode(Self.DocumentElement, W);
    Result := W;
  end
  else
    RaiseNoXMLDocument;
end;

function TCustomXSLPageProducer.GetTemplateStream(out AOwned: Boolean): TStream;
begin
  Result := GetXSLStream(AOwned);
end;

function TCustomXSLPageProducer.GetXSLStream(var AOwned: Boolean): TStream;
begin
  if FileName <> '' then
  begin
    AOwned := True;
    Result := nil;
    if DesignerFileManager <> nil then
      Result := DesignerFileManager.GetStream(FileName, AOwned);
    if Result = nil then
      Result := TFileStream.Create(QualifyFileName(FileName), fmOpenRead or fmShareDenyNone);
  end
  else
  begin
    Result := TMemoryStream.Create;
    SaveToStream(Result);
  end;
  AOwned := True;
end;

procedure TCustomXSLPageProducer.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) then
  begin
    if AComponent = FXMLData then
      FXMLData := nil;
    if AComponent = FDispatcher then
      FDispatcher := nil;
  end;
end;

procedure TCustomXSLPageProducer.SetXMLData(const Value: TComponent);
begin
  if FXMLData <> Value then
  begin
    FXMLData := Value;
    if Value <> nil then
      Value.FreeNotification(Self);
  end;
end;

procedure TCustomXSLPageProducer.SetDispatcher(Value: TComponent);
begin
  if FDispatcher <> Value then
  begin
    if Value <> nil then Value.FreeNotification(Self);
    FDispatcher := Value;
  end;
end;

function TCustomXSLPageProducer.Content: string;
var
  W: WideString;
  XMLDocument: IXMLDocument;
begin
  if XMLData = nil then
    RaiseNoXMLData;
  if GetXMLDocument(XMLDocument) then
  begin
    Self.Active := True;
    if XMLDocument.Node = nil then
      RaiseNoXMLData
    else if XMLDocument.DocumentElement.ParentNode = nil then
      RaiseNoXMLData
    else if DocumentElement = nil then
      RaiseNoXMLDocument;

    XMLDocument.DocumentElement.ParentNode.TransformNode(Self.DocumentElement, W);
    Result := W;
  end
  else
    RaiseNoXMLDocument;
end;

procedure TCustomXSLPageProducer.SetAppDispatcher(
  const ADispatcher: TComponent);
begin
  SetDispatcher(ADispatcher);
end;

function TCustomXSLPageProducer.GetDispatcher: IWebDispatcherAccess;
begin
  if Assigned(FDispatcher) then
    Supports(IInterface(FDispatcher), IWebDispatcherAccess, Result)
  else
    Result := nil;
end;

function TCustomXSLPageProducer.ProduceContent: string;
begin
  Result := Content;
end;

function TCustomXSLPageProducer.ProduceContentFromStream(
  Stream: TStream): string;
begin
  Result := ContentFromStream(Stream);
end;

function TCustomXSLPageProducer.ProduceContentFromString(
  const S: string): string;
begin
  Result := ContentFromString(S);
end;

function TCustomXSLPageProducer.GetAppDispatcher: TComponent;
begin
  Result := FDispatcher;
end;

function TCustomXSLPageProducer.ContentFromString(const S: string): string;
var
  Temp: TStream;
begin
  Temp := TStringStream.Create(S);
  try
    Result := ContentFromStream(Temp)
  finally
    Temp.Free;
  end;
end;

function TCustomXSLPageProducer.ContentFromWideString(const S: WideString): string;
var
  XMLDocument: IXMLDocument;
  W: WideString;
begin
  if XMLData = nil then
    RaiseNoXMLData;
  if GetXMLDocument(XMLDocument) then
  begin
    Self.LoadFromXML(S);
    Active := True; 
    XMLDocument.Active := True;
    if Self.DocumentElement = nil then
      RaiseNoXMLDocument;
    XMLDocument.Node.TransformNode(Self.DocumentElement, W);
    Result := W;
  end
  else
    RaiseNoXMLDocument;
end;

function TCustomXSLPageProducer.GetXMLDocument(out AXMLDocument: IXMLDocument): Boolean;
var
  Stream: TStream;
  Owned: Boolean;
begin
  Result := Supports(IUnknown(XMLData), IXMLDocument, AXMLDocument);
  if Result then
    if (csDesigning in ComponentState) and (AXMLDocument.FileName <> '') then
    begin
      // Load the file when designing
      Result := False;
      AXMLDocument := nil;
    end;
  if not Result then
  begin
    Owned := False;
    Stream := GetXMLData(Owned);
    if Stream <> nil then
      try
        AXMLDocument := TXMLDocument.Create('');
        try
          AXMLDocument.LoadFromStream(Stream);
        except
          FreeAndNil(AXMLDocument);
          raise;
        end;
        Result := AXMLDocument <> nil;
      finally
        if Owned then
          Stream.Free;
      end;
  end;
end;

function TCustomXSLPageProducer.HasScriptView: Boolean;
begin
  Result := False;
end;

function TCustomXSLPageProducer.HasXMLBrowserView: Boolean;
begin
  Result := True;
end;

function TCustomXSLPageProducer.GetXMLData(var Owned: Boolean): TStream;
var
  XMLDocument: IXMLDocument;
  GetXMLStream: IGetXMLStream;
begin
  if Supports(IUnknown(XMLData), IGetXMLStream, GetXMLStream) then
    Result := GetXMLStream.GetXMLStream(Owned)
  else if Supports(IUnknown(XMLData), IXMLDocument, XMLDocument) then
  begin
    if (XMLDocument.FileName <> '') and (csDesigning in ComponentState) then
    begin
      // Load the file when designing
      Owned := True;
      Result := nil;
      if DesignerFileManager <> nil then
        Result := DesignerFileManager.GetStream(XMLDocument.FileName, Owned);
      if Result = nil then
        Result := TFileStream.Create(QualifyFileName(XMLDocument.FileName), fmOpenRead or fmShareDenyNone);
    end
    else
    begin
      Owned := True;
      Result := TMemoryStream.Create;
      try
        SaveToStream(Result);
      except
        FreeAndNil(Result);
        raise;
      end;
    end;
  end
  else
    Result := nil;
end;

function TCustomXSLPageProducer.GetXSLData(var Owned: Boolean): TStream;
begin
  Self.Active := True;
  Owned := True;
  Result := TMemoryStream.Create;
  try
    Self.SaveToStream(Result);
  except
    Result.Free;
    raise;
  end;
end;

function TCustomXSLPageProducer.HasHTMLBrowserView: Boolean;
begin
  Result := True;
end;

function TCustomXSLPageProducer.HasXSLBrowserView: Boolean;
begin
  Result := True;
end;

function TCustomXSLPageProducer.GetTemplateFileType: string;
begin
  Result := 'XSL';
end;

function TCustomXSLPageProducer.GetProducerTemplateFileName: string;
begin
  Result := FileName;
end;

function TCustomXSLPageProducer.GetProducerTemplateStream(
  out AOwned: Boolean): TStream;
begin
  Result := GetXSLStream(AOwned);
end;

end.
