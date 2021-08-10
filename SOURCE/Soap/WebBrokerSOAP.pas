{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}
unit WebBrokerSOAP;

interface

uses Classes, HTTPApp, AutoDisp, Masks, WebNode, SOAPHTTPDisp;

type


  { Webbroker component that dispatches soap requests }
  THTTPSoapDispatcher = class(THTTPSoapDispatchNode, IWebDispatch)
  private
    FWebDispatch: TWebDispatch;
    procedure SetWebDispatch(const Value: TWebDispatch);
	protected
    function DispatchEnabled: Boolean;
    function DispatchMask: TMask;
    function DispatchMethodType: TMethodType;
    function DispatchRequest(Sender: TObject; Request: TWebRequest;
      Response: TWebResponse): Boolean;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property WebDispatch: TWebDispatch read FWebDispatch write SetWebDispatch;
  end;

function GetSOAPWebModule: TWebModule;

{$EXTERNALSYM SOAPWebModule}
threadvar
  SOAPWebModule:  TWebModule;

implementation

uses SysUtils, InvokeRegistry, SOAPConst, SOAPPasInv, OPConvert;

function GetSOAPWebModule: TWebModule;
begin
  Result := SOAPWebModule;
end;

{ THTTPSoapDispatcher }
constructor THTTPSoapDispatcher.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FWebDispatch := TWebDispatch.Create(Self);
  FWebDispatch.PathInfo := 'soap*';     { do not localize }
end;

destructor THTTPSoapDispatcher.Destroy;
begin
  FWebDispatch.Free;
  inherited Destroy;
end;

procedure THTTPSoapDispatcher.SetWebDispatch(const Value: TWebDispatch);
begin
 FWebDispatch.Assign(Value);
end;

function THTTPSoapDispatcher.DispatchEnabled: Boolean;
begin
  { Here we could check whether the 'Dispatcher' is set -
    See 105167 }
  Result := True;
end;

function THTTPSoapDispatcher.DispatchMask: TMask;
begin
  Result := FWebDispatch.Mask;
end;

function THTTPSoapDispatcher.DispatchMethodType: TMethodType;
begin
  Result := FWebDispatch.MethodType;
end;

{ DO NOT LOCALIZE }
const DefException =
   SSoapXMLHeader +
   ' <SOAP-ENV:Envelope' + ' ' +
   'xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/" >' +
   '<SOAP-ENV:Body> ' +
   '<SOAP-ENV:Fault> ' +
   '<faultcode>SOAP-ENV:Server</faultcode>' +
   '<faultstring>%s</faultstring>' +
   '</SOAP-ENV:Fault>' +
   '</SOAP-ENV:Body>' +
   '</SOAP-ENV:Envelope>';



function THTTPSoapDispatcher.DispatchRequest(Sender: TObject;
  Request: TWebRequest; Response: TWebResponse): Boolean;
var
  Path, SoapAction, WResp: WideString;
  Stream, RStream: TMemoryStream;
  BytesRead, ChunkSize: Integer;
  Buffer: array of Byte;
  Size: Integer;
  AConvert: IAdapterConverter;

  ConvertOptions: TSOAPConvertOptions;

begin
  Result := True;
  ConvertOptions := [];
  try
    if Owner is TWebModule then
      SOAPWebModule := TWebModule(Owner);
    try
      try
        { Make sure we have a dispatcher }
        if not Assigned(FSoapDispatcher) and not ((csDesigning in ComponentState) or (csLoading in ComponentState)) then
          raise Exception.Create(SNoDispatcher);
        { Retrieve the Convert options }
        if Supports(FSoapDispatcher, IAdapterConverter, AConvert) then
          ConvertOptions := AConvert.GetDomConverter.Options;
        { Get SOAPAction header sent over }
        SoapAction := Request.GetFieldByName(SHTTPSoapAction);
        { CGI/Apache remap headers with 'HTTP_' prefix }
        if SoapAction = '' then
          SoapAction := Request.GetFieldByName('HTTP_' + UpperCase(SHTTPSoapAction));
        { Get the path to which client posted - SOAPAction may not tell us
          which porttype to dispatch to; we'll then use the path }
        Path := Request.PathInfo;
        Stream := TMemoryStream.Create;
        try
          BytesRead := Length(Request.Content);
          if BytesRead < Request.ContentLength then
          begin
            SetLength(Buffer, Request.ContentLength);
            Stream.Write(Request.Content[1], BytesRead);
            repeat
              ChunkSize := Request.ReadClient(Buffer[0], Request.ContentLength - BytesRead);
              if ChunkSize > 0 then
              begin
                Stream.Write(Buffer[0], ChunkSize);
                Inc(BytesRead, ChunkSize);
              end;
            until ChunkSize = -1;
          end else
            Stream.Write(Request.Content[1], BytesRead);
          Stream.Position := 0;
          RStream := TMemoryStream.Create;
          try
            FSoapDispatcher.DispatchSOAP(Path, SoapAction, Stream, RStream);
            RStream.Position := 0;
            Size := RStream.Size;
            SetLength(WResp, (Size div 2));
            RStream.ReadBuffer(WResp[1], Size);
            Response.Content :=  UTF8Encode(WResp);
            if (soUTF8InHeader in ConvertOptions) then
              Response.ContentType := ContentTypeUTF8
            else
              Response.ContentType := ContentTypeNoUTF8;
            Result := True;
          finally
            RStream.Free;
          end;
        finally
          Stream.Free;
        end;
      except
        on E: Exception do
        begin
          { Default to 500, as required by spec. }
          Response.StatusCode := 500;
          { We may, however, return 200 instead }
          if (soReturnSuccessForFault in ConvertOptions) then
            Response.StatusCode := 200;
          Response.Content :=  UTF8Encode(Format(DefException, [E.Message]));
          if (soUTF8InHeader in ConvertOptions) then
            Response.ContentType := ContentTypeUTF8
          else
            Response.ContentType := ContentTypeNoUTF8;
          Result := True;
        end;
      end;
    except
      { Swallow any unexpected exception, it will bring down some web servers }
      Result := False;
    end;
  finally
    { Reset current SOAPWebModule }
    SOAPWebModule := nil;
  end;
end;

end.

