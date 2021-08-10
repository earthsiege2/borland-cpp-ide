{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{         SOAP Transports                               }
{                                                       }
{       Copyright (c) 2001 Inprise Corporation          }
{                                                       }
{*******************************************************}
{$IFDEF LINUX}
{$DEFINE USE_INDY}
{$ENDIF}
{$IFDEF MSWINDOWS}
//{$DEFINE USE_INDY}
{$ENDIF}

unit SOAPHTTPTrans;

interface

uses
  SysUtils, Classes, WebNode, WSDLNode, Types, IntfInfo,
{$IFDEF USE_INDY}
IdHTTP;
{$ELSE}
  WinSock, WinInet;
(*$HPPEMIT '#pragma link "wininet.lib"' *)
{$ENDIF}
type

  SOAPInvokeOptions = (soNoValueForEmptySOAPAction, soIgnoreInvalidCerts);
  TSOAPInvokeOptions= set of SOAPInvokeOptions;

  THTTPReqResp = class;

  { Provides access to HTTPReqResp component }
  IHTTPReqResp = interface
  ['{5FA6A197-32DE-4225-BC85-216CB80D1561}']
    function GetHTTPReqResp: THTTPReqResp;
  end;

  THTTPReqResp = class(TComponent, IInterface, IWebNode, IHTTPReqResp)
  private
    FUserSetURL: Boolean;
    FRefCount: Integer;
    FOwnerIsComponent: Boolean;
    FConnected: Boolean;
    FURL: string;
    FAgent: string;
    FUserName: string;
    FPassword: string;
    FURLHost: string;
    FURLSite: string;
    FURLPort: Integer;
    FURLScheme: Integer;
    FProxy: string;
    FProxyByPass: string;
{$IFNDEF USE_INDY}
    FInetRoot: HINTERNET;
    FInetConnect: HINTERNET;
{$ENDIF}
    FWSDLView: TWSDLView;
    FSoapAction: string;
    FUseUTF8InHeader: Boolean;
    FInvokeOptions: TSOAPInvokeOptions;
    procedure SetURL(const Value: string);
    function  GetSOAPAction: string;
    procedure SetSOAPAction(const SOAPAction: string);
    procedure SetWSDLView(const WSDLVIew: TWSDLView);
    function  GetSOAPActionHeader: string;
    procedure InitURL(const Value: string);
    procedure SetUsername(const NameValue: string);
    procedure SetPassword(const PasswordValue: string);
    procedure SetProxy(const ProxyValue: string);
  protected
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
  public
    constructor Create(Owner: TComponent); override;
    class function NewInstance: TObject; override;
    procedure AfterConstruction; override;
    destructor Destroy; override;
    function  GetHTTPReqResp: THTTPReqResp;
{$IFNDEF USE_INDY}
    procedure Check(Error: Boolean; ShowSOAPAction: Boolean = True);
    procedure Connect(Value: Boolean);
    function  Send(const S: WideString): Integer;
    function  SendGet: Integer;
    procedure Receive(Context: Integer; Resp: TStream);
{$ENDIF}
{$IFDEF USE_INDY}
    procedure SetupIndy(IndyHttp: TIDHttp);
{$ENDIF}
    procedure Get(Resp: TStream); virtual;
    {IWebNode}
    procedure BeforeExecute(const IntfMD: TIntfMetaData; const MethMD: TIntfMethEntry); virtual;
    procedure Execute(const DataMsg: WideString; Resp: TStream); virtual;
    property URL: string read FURL write SetURL;
    property SoapAction: string read GetSOAPAction write SetSOAPAction;
  published
    property WSDLView: TWSDLView read FWSDLView write SetWSDLView;
    property Agent: string read FAgent write FAgent;
    property UserName: string read FUserName write SetUserName;
    property Password: string read FPassword write SetPassword;
    property Proxy: string read FProxy write SetProxy;
    property ProxyByPass: string read FProxyByPass write FProxyByPass;
    property UseUTF8InHeader: Boolean read FUseUTF8InHeader write FUseUTF8InHeader;
    property InvokeOptions: TSOAPInvokeOptions read FInvokeOptions write FInvokeOptions;
  end;

implementation


uses Variants, SOAPConst, XMLDoc, XMLIntf,  WSDLIntf, InvokeRegistry, WSDLItems,
{$IFDEF MSWINDOWS}
Windows,
{$ENDIF}
{$IFNDEF USE_INDY}
xmldom;
{$ELSE}
IdIntercept, IdSSLIntercept, IdException, IdURI, IdGlobal;
{$ENDIF}

constructor THTTPReqResp.Create(Owner: TComponent);
begin
  inherited;
{$IFNDEF USE_INDY}
  FInetRoot := nil;
  FInetConnect := nil;
{$ENDIF}
  FUserSetURL := False;
  FInvokeOptions := [soIgnoreInvalidCerts];
  FAgent := 'Borland SOAP 1.1';
end;

destructor THTTPReqResp.Destroy;
begin
{$IFNDEF USE_INDY}
  if Assigned(FInetConnect) then
    InternetCloseHandle(FInetConnect);
  FInetConnect := nil;
  if Assigned(FInetRoot) then
    InternetCloseHandle(FInetRoot);
  FInetRoot := nil;
{$ENDIF}
  FConnected := False;
  inherited;
end;

class function THTTPReqResp.NewInstance: TObject;
begin
  Result := inherited NewInstance;
  THTTPReqResp(Result).FRefCount := 1;
end;

procedure THTTPReqResp.AfterConstruction;
begin
  inherited;
  FOwnerIsComponent := Assigned(Owner) and (Owner is TComponent);
  InterlockedDecrement(FRefCount);
end;

{ IInterface }

function THTTPReqResp._AddRef: Integer;
begin
  Result := InterlockedIncrement(FRefCount)
end;

function THTTPReqResp._Release: Integer;
begin
  Result := InterlockedDecrement(FRefCount);
  { If we are not being used as a TComponent, then use refcount to manage our
    lifetime as with TInterfacedObject. }
  if (Result = 0) and not FOwnerIsComponent then
    Destroy;
end;

{$IFNDEF USE_INDY}
procedure THTTPReqResp.Check(Error: Boolean; ShowSOAPAction: Boolean);
var
  ErrCode: Integer;
  S: string;
begin
  ErrCode := GetLastError;
  if Error and (ErrCode <> 0) then
  begin
    SetLength(S, 256);
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM or FORMAT_MESSAGE_FROM_HMODULE, Pointer(GetModuleHandle('wininet.dll')),
      ErrCode, 0, PChar(S), Length(S), nil);
    SetLength(S, StrLen(PChar(S)));
    while (Length(S) > 0) and (S[Length(S)] in [#10, #13]) do
      SetLength(S, Length(S) - 1);
    raise Exception.CreateFmt('%s - URL:%s - SOAPAction:%s', [S, FURL, SoapAction]);      { Do not localize }
  end;
end;
{$ENDIF}

function THTTPReqResp.GetHTTPReqResp: THTTPReqResp;
begin
  Result := Self;
end;

function THTTPReqResp.GetSOAPAction: string;
begin
  if (FSoapAction = '') and not (soNoValueForEmptySOAPAction in FInvokeOptions) then
    Result := '""'
  else
    Result := FSoapAction;
end;

procedure THTTPReqResp.SetSOAPAction(const SOAPAction: string);
begin
  FSoapAction := SOAPAction;
end;

procedure THTTPReqResp.SetWSDLView(const WSDLVIew: TWSDLView);
begin
  FWSDLView := WSDLView;
end;

procedure THTTPReqResp.SetURL(const Value: string);
begin
  if Value <> '' then
    FUserSetURL := True
  else
    FUserSetURL := False;
  InitURL(Value);
{$IFNDEF USE_INDY}
  { Here we always disconnect if a new URL comes in...
    this ensures that we don't keep a connection to
    a wrong host }
  Connect(False);
{$ENDIF}  
end;

procedure THTTPReqResp.InitURL(const Value: string);
{$IFNDEF USE_INDY}
var
  URLComp: TURLComponents;
  P: PChar;
{$ELSE}
const
  http = 'http://';
var
  IndyHTTP: TIDHttp;
  URI, Protocol, Host, path, Document, Port, Bookmark: string;
{$ENDIF}
begin
  if Value <> '' then
  begin
{$IFNDEF USE_INDY}
    FillChar(URLComp, SizeOf(URLComp), 0);
    URLComp.dwStructSize := SizeOf(URLComp);
    URLComp.dwSchemeLength := 1;
    URLComp.dwHostNameLength := 1;
    URLComp.dwURLPathLength := 1;
    P := PChar(Value);
    InternetCrackUrl(P, 0, 0, URLComp);
    if not (URLComp.nScheme in [INTERNET_SCHEME_HTTP, INTERNET_SCHEME_HTTPS]) then
      raise Exception.CreateFmt(SInvalidURL, [Value]);
    FURLScheme := URLComp.nScheme;
    FURLPort := URLComp.nPort;
    FURLHost := Copy(Value, URLComp.lpszHostName - P + 1, URLComp.dwHostNameLength);
    FURLSite := Copy(Value, URLComp.lpszUrlPath - P + 1, URLComp.dwUrlPathLength);
{$ELSE}
    IndyHTTP := TIDHttp.Create(Nil);
    try
      URI := Value;
      ParseURI(URI, Protocol, Host, Path, Document, Port, Bookmark);
      if Port <> '' then
        FURLPort := StrToInt(Port)
      else
        FURLPort := IndyHTTP.Port;
      if Host <> '' then
        FURLHost := Host
      else
        FURLHost := Copy(Value, Length(http)+1,
              Pos(':' + IntToStr(FURLPort), Value) - (Length(http)+1));
      FURLSite := StringReplace(Value, IndyHTTP.ProtoHeader +
         '://' + FURLHost + '/', '', [rfIgnoreCase]);
    finally
      IndyHTTP.Free;
    end;
{$ENDIF}
  end else
  begin
    FURLPort := 0;
    FURLHost := '';
    FURLSite := '';
    FURLScheme := 0;
  end;
  FURL := Value;
end;

procedure THTTPReqResp.SetUsername(const NameValue: string);
begin
  FUserName := NameValue;
  if Assigned(WSDLView) then
    WSDLView.UserName := NameValue;
end;

procedure THTTPReqResp.SetPassword(const PasswordValue: string);
begin
  FPassword := PasswordValue;
  if Assigned(WSDLView) then
    WSDLView.Password := PasswordValue;
end;

procedure THTTPReqResp.SetProxy(const ProxyValue: string);
begin
  FProxy := ProxyValue;
  if Assigned(WSDLView) then
    WSDLView.Proxy := ProxyValue;
end;


const
  MaxStatusTest = 4096;

function THTTPReqResp.GetSOAPActionHeader: string;
begin
  if (SoapAction = '') then
    Result := SHTTPSoapAction + ':'
  else if (SoapAction = '""') then
    Result := SHTTPSoapAction + ': ""'
  else
    Result := SHTTPSoapAction + ': ' + '"' + SoapAction + '"';
end;

{$IFNDEF USE_INDY}

procedure THTTPReqResp.Connect(Value: Boolean);
var
  AccessType: Integer;
begin
  if Value then
  begin
    { Yes, but what if we're connected to a different Host/Port?? }
    { So take advantage of a cached handle, we'll assume that
      Connect(False) will be called explicitly when we're switching
      Host. To that end, SetURL always disconnects }
    if (FConnected) then
      Exit;

    { Proxy?? }
    if Length(FProxy) > 0 then
      AccessType := INTERNET_OPEN_TYPE_PROXY
    else
      AccessType := INTERNET_OPEN_TYPE_PRECONFIG;

    { Also, could switch to new API introduced in IE4/Preview2}
    if InternetAttemptConnect(0) <> ERROR_SUCCESS then
      SysUtils.Abort;

    FInetRoot := InternetOpen(PChar(FAgent), AccessType, PChar(FProxy), PChar(FProxyByPass), 0);
    Check(not Assigned(FInetRoot));
    try
      FInetConnect := InternetConnect(FInetRoot, PChar(FURLHost), FURLPort, PChar(FUserName),
        PChar(FPassword), INTERNET_SERVICE_HTTP, 0, Cardinal(Self));
      Check(not Assigned(FInetConnect));
      FConnected := True;
    except
      InternetCloseHandle(FInetRoot);
      FInetRoot := nil;
    end;
  end
  else
  begin
    if Assigned(FInetConnect) then
      InternetCloseHandle(FInetConnect);
    FInetConnect := nil;
    if Assigned(FInetRoot) then
      InternetCloseHandle(FInetRoot);
    FInetRoot := nil;
    FConnected := False;
  end;
end;

procedure  THTTPReqResp.Receive(Context: Integer; Resp: TStream);
var
  Size, Downloaded, Status, Len, Index: DWord;
  S: string;
begin
  Len := SizeOf(Status);
  Index := 0;
  if HttpQueryInfo(Pointer(Context), HTTP_QUERY_STATUS_CODE or HTTP_QUERY_FLAG_NUMBER,
    @Status, Len, Index) and (Status >= 300) and (Status <> 500) then
  begin
    Index := 0;
    Size := MaxStatusTest;
    SetLength(S, Size);
    if HttpQueryInfo(Pointer(Context), HTTP_QUERY_STATUS_TEXT, @S[1], Size, Index) then
    begin
      SetLength(S, Size);
      raise Exception.CreateFmt('%s (%d) - ''%s''', [S, Status, FURL]);
    end;
  end;
  Len := 0;
  repeat
    Check(not InternetQueryDataAvailable(Pointer(Context), Size, 0, 0));
    if Size > 0 then
    begin
      SetLength(S, Size);
      Check(not InternetReadFile(Pointer(Context), @S[1], Size, Downloaded));
      Resp.Write(S[1], Size);
    end;
  until Size = 0;
end;

function THTTPReqResp.Send(const S: WideString): Integer;
var
  Request: HINTERNET;
  RetVal, Flags: DWord;
  P: Pointer;
  AcceptTypes: array of PChar;
  ActionHeader: string;
  WireData: string;
  ContentHeader: string;
begin
  if UseUTF8InHeader then
    ContentHeader := ContentHeaderUTF8
  else
    ContentHeader := ContentHeaderNoUTF8;

  { Connect }
  Connect(True);

  SetLength(AcceptTypes, 2);
  AcceptTypes[0] := PChar('text/xml');  { Do not localize }
  AcceptTypes[1] := nil;
  Flags := INTERNET_FLAG_KEEP_CONNECTION or INTERNET_FLAG_NO_CACHE_WRITE;
  if FURLScheme = INTERNET_SCHEME_HTTPS then
  begin
    Flags := Flags or INTERNET_FLAG_SECURE;
    if (soIgnoreInvalidCerts in InvokeOptions) then
      Flags := Flags or (INTERNET_FLAG_IGNORE_CERT_CN_INVALID or
                         INTERNET_FLAG_IGNORE_CERT_DATE_INVALID);
  end;

  Request := nil;
  try
    Request := HttpOpenRequest(FInetConnect, 'POST', PChar(FURLSite), nil,
      nil, Pointer(AcceptTypes), Flags, Integer(Self));
    Check(not Assigned(Request));

    { SOAPAction header }
    ActionHeader:= GetSOAPActionHeader;
    HttpAddRequestHeaders(Request, PChar(ActionHeader), Length(ActionHeader), HTTP_ADDREQ_FLAG_ADD);

    { Content-Type }
    HttpAddRequestHeaders(Request, PChar(ContentHeader), Length(ContentHeader), HTTP_ADDREQ_FLAG_ADD);
    WireData := UTF8Encode(S);
    while True do
    begin
      Check(not HttpSendRequest(Request, nil, 0, @WireData[1], Length(WireData)));
      RetVal := InternetErrorDlg(GetDesktopWindow(), Request, GetLastError,
        FLAGS_ERROR_UI_FILTER_FOR_ERRORS or FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS or
        FLAGS_ERROR_UI_FLAGS_GENERATE_DATA, P);
      case RetVal of
        ERROR_SUCCESS: break;
        ERROR_CANCELLED: SysUtils.Abort;
        ERROR_INTERNET_FORCE_RETRY: {Retry the operation};
      end;
    end;
  except
    if (Request <> nil) then
      InternetCloseHandle(Request);
    Request := nil;
    Connect(False);
  end;
  Result := Integer(Request);
end;

function THTTPReqResp.SendGet: Integer;
var
  Request: HINTERNET;
  LastError, RetVal, Flags, FlagsLen: DWord;
  P: Pointer;
  AcceptTypes: array of PChar;
begin
  { Connect }
  Connect(True);

  SetLength(AcceptTypes, 2);
  AcceptTypes[0] := PChar('*/*');  { Do not localize }
  AcceptTypes[1] := nil;
  Flags := INTERNET_FLAG_DONT_CACHE;
  if FURLScheme = INTERNET_SCHEME_HTTPS then
  begin
    Flags := Flags or INTERNET_FLAG_SECURE;
    if (soIgnoreInvalidCerts in InvokeOptions) then
      Flags := Flags or (INTERNET_FLAG_IGNORE_CERT_CN_INVALID or
                         INTERNET_FLAG_IGNORE_CERT_DATE_INVALID);
  end;

  Request := nil;
  try
    Request := HttpOpenRequest(FInetConnect, 'GET', PChar(FURLSite), nil,
      nil, Pointer(AcceptTypes), Flags, Integer(Self));
    Check(not Assigned(Request), False);

    while True do
    begin
      if (not HttpSendRequest(Request, nil, 0, nil, 0)) then
      begin
        LastError := GetLastError;
        { Handle INVALID_CA discreetly }
        if (LastError = ERROR_INTERNET_INVALID_CA) then
        begin
          FlagsLen := SizeOf(Flags);
          InternetQueryOption(Request, INTERNET_OPTION_SECURITY_FLAGS, Pointer(@Flags), FlagsLen);
          Flags := Flags or SECURITY_FLAG_IGNORE_UNKNOWN_CA;
          InternetSetOption(Request, INTERNET_OPTION_SECURITY_FLAGS, Pointer(@Flags), FlagsLen);
        end
        else
        begin
          RetVal := InternetErrorDlg(GetDesktopWindow(), Request, LastError,
                                     FLAGS_ERROR_UI_FILTER_FOR_ERRORS or
                                     FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS or
                                     FLAGS_ERROR_UI_FLAGS_GENERATE_DATA, P);
          case RetVal of
            ERROR_CANCELLED: SysUtils.Abort;
            ERROR_SUCCESS: break;
            ERROR_INTERNET_FORCE_RETRY: {Retry the operation};
          end;
        end;
      end
      else
        break;
    end;
  except
    if (Request <> nil) then
      InternetCloseHandle(Request);
    Request := nil;
    Connect(False);
  end;
  Result := Integer(Request);
end;
{$ENDIF}

{$IFDEF USE_INDY}
procedure THTTPReqResp.SetupIndy(IndyHttp: TIDHttp);
var
  ContentHeader, ActionHeader: string;
  Protocol, Host, path, Document, Port, Bookmark: string;
begin
  if UseUTF8InHeader then
    ContentHeader := ContentHeaderUTF8
  else
    ContentHeader := ContentHeaderNoUTF8;

  { SOAP-Action }
  ActionHeader := GetSOAPActionHeader;
  IndyHttp.Request.Accept := 'text/xml';
  IndyHttp.Request.UserAgent := Self.Agent;
  { UserName/Password for Basic Authentication }
  IndyHttp.Request.Username := FUserName;
  IndyHttp.Request.Password := FPassword;
  IndyHttp.Request.ExtraHeaders.Add(ActionHeader);
  IndyHttp.Request.Location := FUrl;
  { Proxy and potentially username/password combination }
  if FProxy <> '' then
  begin
    ParseURI(FProxy, Protocol, Host, path, Document, Port, Bookmark);
    IndyHttp.Request.ProxyServer := Host;
    IndyHttp.Request.ProxyPort := StrToInt(Port);
    IndyHttp.Request.ProxyUsername := FUserName;
    IndyHttp.Request.ProxyPassword := FPassword;
  end;
  IndyHttp.Request.Connection := Self.FURL;
  IndyHttp.Request.ContentType := 'text/xml';   { do not localize }
  IndyHttp.Host := FUrlHost;
  IndyHttp.Port := FUrlPort;
end;
{$ENDIF}

procedure THTTPReqResp.Get(Resp: TStream);
{$IFNDEF USE_INDY}
var
  Context: Integer;
{$ENDIF}
{$IFDEF USE_INDY}
  procedure LoadFromURL(URL: string; Stream: TStream);
  var
    IndyHTTP: TIDHttp;
    Protocol, Host, path, Document, Port, Bookmark: string;
  begin
    IndyHTTP := TIDHttp.Create(Nil);
    try
      IndyHttp.Request.Accept := 'text/xml, text/html, application/octet-stream';
      IndyHttp.Request.UserAgent := 'Mozilla/3.0 (compatible; Indy Library)'; { Do not localize }
      IndyHttp.Request.ContentType := 'text/xml';   { Do not localize }
      IndyHttp.Request.Location := URL;
      IndyHttp.Request.Connection := URL;
      { IndyHttp.Intercept := FIntercept; }
      IndyHttp.Get(URL, Stream);
      if FProxy <> '' then
      begin
       ParseURI(FProxy, Protocol, Host, path, Document, Port, Bookmark);
       IndyHttp.Request.ProxyServer := Host;
       IndyHttp.Request.ProxyPort := StrToInt(Port);
       IndyHttp.Request.ProxyUsername := FUserName;
       IndyHttp.Request.ProxyPassword := FPassword;
      end;
   finally
      IndyHTTP.Free;
    end;
  end;
{$ENDIF}
begin
  { GETs require a URL }
  if URL = '' then
    raise Exception.Create(SEmptyURL);
{$IFDEF USE_INDY}
  { GET with INDY }
  LoadFromURL(URL, Resp);
{$ELSE}
  Context := SendGet;
  try
    Receive(Context, Resp);
  finally
    if Context <> 0  then
      InternetCloseHandle(Pointer(Context));
    Connect(False);
  end;
{$ENDIF}
end;

{ Here the RIO can perform any transports specific setup before call - XML serialization is done }
procedure THTTPReqResp.BeforeExecute(const IntfMD: TIntfMetaData; const MethMD: TIntfMethEntry);
var
  MethName: InvString;
  Binding: InvString;
  QBinding: IQualifiedName;
begin
  if FUserSetURL then
  begin
    MethName := InvRegistry.GetMethExternalName(IntfMD.Info, MethMD.Name);
    FSoapAction := InvRegistry.GetActionURIOfInfo(IntfMD.Info, MethName);
  end
  else
  begin
    { User did *NOT* set a URL }
    if WSDLView <> nil then
    begin
    { Make sure WSDL is active }
      WSDLView.Activate;
      QBinding := WSDLView.WSDL.GetBindingForServicePort(WSDLView.Service, WSDLView.Port);
      if QBinding <> nil then
      begin
        Binding := QBinding.Name;
        MethName:=  InvRegistry.GetMethExternalName(WSDLView.IntfInfo, WSDLView.Operation);
        { TODO: Pass in QBinding here to fix namespace issues }
        FSoapAction := WSDLView.WSDL.GetSoapOperationAttribute(Binding, MethName, WSDLIntf.SSoapAction);
      end;
      {NOTE: In case we can't get the SOAPAction - see if we have something in the registry }
      {      It can't hurt:) }
      if FSoapAction = '' then
        InvRegistry.GetActionURIOfInfo(IntfMD.Info, MethName);
      { Retrieve URL }
      FURL := WSDLView.WSDL.GetSoapAddressForServicePort(WSDLView.Service, WSDLView.Port);
      if (FURL = '') then
        raise Exception.CreateFmt(sCantGetURL, [WSDLView.Service, WSDLView.Port, WSDLView.WSDL.FileName]);
      InitURL(FURL);
    end
    else
      raise Exception.Create(sNoWSDLURL);
  end;
end;

procedure THTTPReqResp.Execute(const DataMsg: WideString; Resp: TStream);

{$IFDEF USE_INDY}
  procedure PostData(const DataMsg: WideString; Response: TStream);
  var
    IndyHTTP: TIDHttp;
    Strings: TStrings;
    WireData: string;
  begin
    IndyHTTP := TIDHttp.Create(Nil);
    try
      SetupIndy(IndyHTTP);
      WireData := UTF8Encode(DataMsg);
      Strings := TStringList.Create;
      try
        Strings.Add(WireData);
        IndyHttp.Post(FUrl, Strings, Resp);
      finally
        Strings.Free;
      end;
    finally
      FreeAndNil(IndyHTTP);
    end;
  end;
{$ENDIF}

{$IFNDEF USE_INDY}
var
  Context: Integer;
{$ENDIF}
begin

{$IFNDEF USE_INDY}
  Context := Send(DataMsg);
  try
    try
      Receive(Context, Resp);
    except
      Connect(False);
    end;
  finally
    if Context <> 0  then
      InternetCloseHandle(Pointer(Context));
{  Connect(False); }
  end;
{$ELSE}
  PostData(DataMsg, Resp);
{$ENDIF}
end;

end.
