{*******************************************************}
{                                                       }
{       Borland Delphi Test Server                      }
{                                                       }
{  Copyright (c) 2001 Borland Software Corporation      }
{                                                       }
{*******************************************************}

unit SvrHTTP;

{$WARN SYMBOL_PLATFORM OFF}

interface


uses SysUtils, Windows, Messages, Classes, Registry, SyncObjs, ScktComp,
  WebBroker, HTTPApp, Controls, ComCtrls, WinSock,
  ReqImpl, WebLib, ComObj, ActiveX, SvrLog, HTTPParse;

const
  toEOL           = Char(5);
  toGET           = Char(6);
  toHEAD          = Char(7);
  toPUT           = Char(8);
  toDELETE        = Char(9);
  toPOST          = Char(10);
  toPATCH         = Char(11);
  toCOPY          = Char(12);
  toUserAgent     = Char(13);
  toAccept        = Char(14);
  toContentType   = Char(15);
  toContentLength = Char(16);
  toReferer       = Char(17);
  toAuthorization = Char(18);
  toCacheControl  = Char(19);
  toDate          = Char(20);
  toFrom          = Char(21);
  toHost          = Char(22);
  toIfModified    = Char(23);
  toContentEncoding = Char(24);
  toContentVersion= Char(25);
  toAllow         = Char(26);
  toConnection    = Char(27);
  toCookie        = Char(28);

  hcGET            = $14F5;
  hcPUT            = $4AF5;
  hcDELETE         = $92B2;
  hcPOST           = $361D;
  hcCacheControl   = $4FF6;
  hcDate           = $0EE6;
  hcFrom           = $418F;
  hcHost           = $3611;
  hcIfModified     = $DDF0;
  hcAllow          = $3D80;
  hcUserAgent      = $E890;
  hcAccept         = $1844;
  hcContentEncoding= $C586;
  hcContentVersion = $EDF4;
  hcContentType    = $F0E0;
  hcContentLength  = $B0C4;
  hcReferer        = $CEA5;
  hcAuthorization  = $ABCA;
  hcConnection     = $0EDE;
  hcCookie         = $27B3;

type
  TCustomWebServer = class;
  TWebServerRequest = class;
  TWebServerThread = class;

{ EWebServerException }

  EWebServerException = class(Exception)
  private
    FRequest: TWebServerRequest;
  public
    constructor Create(const Message: string; ARequest: TWebServerRequest);
    property Request: TWebServerRequest read FRequest;
  end;

{ TWebServerRequest }

  TWebServerRequest = class(TWebRequest)
  private
    FClientSocket: TServerClientWinSocket;
    FRequestBufferStream: TStream;
    FRequestBuffer: string;
    FParserContent: string;
    FReadParserContent: Integer;
    FLogBuffer: string;
    FRequestLine: string;
    FUserName: string;
    FPassword: string;
    FLastModified: TDateTime;
    {Unknown other headers}
    FStringVariable: array[0..28] of string;
    FExtHeaders: TStringList;
    procedure SetStringVariable(Index: Integer; const Value: string);
    procedure SetIntegerVariable(Index: Integer; Value: Integer);
    procedure SetDateVariable(Index: Integer; Value: TDateTime);
    property StringVariable[I: Integer]: string read GetStringVariable write SetStringVariable;
    property IntegerVariable[I: Integer]: Integer read GetIntegerVariable write SetIntegerVariable;
    property DateVariable[I: Integer]: TDateTime read GetDateVariable write SetDateVariable;
    function GetRequestBuffer: string;
  protected
    function GetStringVariable(Index: Integer): string; override;
    function GetDateVariable(Index: Integer): TDateTime; override;
    function GetIntegerVariable(Index: Integer): Integer; override;
  public
    constructor Create(APort: Integer;
      ARemoteAddress, ARemoteHost: string);
    destructor Destroy; override;
    function GetFieldByName(const Name: string): string; override;
    function ReadClient(var Buffer; Count: Integer): Integer; override;
    function ReadString(Count: Integer): string; override;
    function TranslateURI(const URI: string): string; override;
    function WriteClient(var Buffer; Count: Integer): Integer; override;
    function WriteString(const AString: string): Boolean; override;
    property RequestBuffer: string read GetRequestBuffer;
   public
    // Write HTTP header string
    function WriteHeaders(StatusCode: Integer; const StatusString, Headers: string): Boolean; override;
    procedure AddExtHeader(Name, Value: string);
  end;

{ TWebServerResponse }

  TWebServerResponse = class(TWebResponse)
  private
    FClientSocket: TServerClientWinSocket;
    FRequest: TWebServerRequest;
    FDate: TDateTime;
    {Response Header}
    FVersion: string;
    FStatusCode: Integer;
    FReasonString: string;
    FServer: string;
    FWWWAuthenticate: string;
    FRealm: string;
    {Entity Header }
    FAllow: string;
    FContentEncoding: string;
    FContentType: string;
    FContentLength: Integer;
    FContentVersion: string;
    FDerivedFrom: string;
    FExpires: TDateTime;
    FLastModified: TDateTime;
    FTitle: string;
    FContent: string;
    FContentStream: TStream;

    FStringVariables: array[0..MAX_STRINGS - 1] of string;
    FIntegerVariables: array[0..MAX_INTEGERS - 1] of Integer;
    FDateVariables: array[0..MAX_DATETIMES - 1] of TDateTime;
    FSent: Boolean;
  protected
    procedure SetStatusCode(Value: Integer); override;
    procedure SetContent(const Value: string); override;
    procedure SetContentStream(Value: TStream); override;
    function GetStringVariable(Index: Integer): string;  override;
    procedure SetStringVariable(Index: Integer; const Value: string);  override;
    function GetDateVariable(Index: Integer): TDateTime;  override;
    procedure SetDateVariable(Index: Integer; const Value: TDateTime);  override;
    function GetIntegerVariable(Index: Integer): Integer;  override;
    procedure SetIntegerVariable(Index: Integer; Value: Integer);  override;
    function GetContent: string;  override;
    function GetStatusCode: Integer;  override;
    function GetLogMessage: string; override;
    procedure SetLogMessage(const Value: string); override;
  public
    procedure SendResponse;  override;
    procedure SendRedirect(const URI: string);  override;
    procedure SendStream(AStream: TStream);  override;
    function Sent: Boolean; override;
    constructor Create(Request: TWebServerRequest; AClientSocket: TServerClientWinSocket);
    destructor Destroy; override;
    property Request: TWebServerRequest read FRequest;
    property Version: string read FVersion write FVersion;
    property StatusCode: Integer read FStatusCode write SetStatusCode;
    property ReasonString: string read FReasonString write FReasonString;
    property Date: TDateTime read FDate;
    property Server: string read FServer write FServer;
    property WWWAuthenticate: string read FWWWAuthenticate write FWWWAuthenticate;
    property Realm: string read FRealm write FRealm;
    property Allow: string read FAllow write FAllow;
    property ContentEncoding: string read FContentEncoding write FContentEncoding;
    property ContentType: string read FContentType write FContentType;
    property ContentLength: Integer read FContentLength write FContentLength;
    property ContentVersion: string read FContentVersion write FContentVersion;
    property DerivedFrom: string read FDerivedFrom write FDerivedFrom;
    property Expires: TDateTime read FExpires write FExpires;
    property LastModified: TDateTime read FLastModified write FLastModified;
    property Title: string read FTitle write FTitle;
    property Content: string read FContent write SetContent;
    property ContentStream: TStream read FContentStream write SetContentStream;
  end;

{ TWebServerThread }

  TWebServerThread = class(TServerClientThread)
  private
    FRegistry: TRegistry;
    function DoFileAccess(Request: TWebServerRequest; IsHeadMethod: Boolean): Boolean;
    procedure ParseCommand(Parser: THTTPParser; Request: TWebServerRequest);
    procedure LogRequest(Request: TWebServerRequest);
    function GetFile(Request: TWebServerRequest): Boolean;
    function Head(Request: TWebServerRequest): Boolean;
    procedure CommandError(Request: TWebServerRequest);
    procedure URLNotFound(Request: TWebServerRequest);
    procedure ServerError(Request: TWebServerRequest; const ErrorMsg: string);
  protected
    procedure HandleException; override;
    procedure Error(ErrorEvent: TErrorEvent; var ErrorCode: Integer); override;
  public
    constructor Create(CreateSuspended: Boolean; ASocket: TServerClientWinSocket);
    destructor Destroy; override;
    procedure ClientExecute; override;
    { Utility functions }
    function GetMIMEType(const FileName: string): string;
  end;

{ TWebServerSocket }

  TWebServerWinSocket = class(TServerWinSocket)
  private
    FServerComponent: TCustomWebServer;
  protected
    function DoCreateThread(ClientSocket: TServerClientWinSocket): TServerClientThread; override;
  public
    constructor Create(AOwner: TCustomWebServer; ASocket: TSocket);
    property ServerComponent: TCustomWebServer read FServerComponent;
  end;

  THTTPMethodEvent =
    procedure (Sender: TObject; ClientSocket: TServerClientWinSocket;
      Request: TWebServerRequest; var Handled: Boolean) of object;
  THTTPErrorEvent =
    procedure (Sender: TObject; ClientSocket: TServerClientWinSocket;
      Request: TWebServerRequest; var Handled: Boolean) of object;
  TWebServerErrorEvent =
    procedure (Sender: TObject; ClientSocket: TServerClientWinSocket;
      Request: TWebServerRequest; const ErrorMsg: string;
      var Handled: Boolean) of object;

{ TCustomWebServer }

  TServerLog = class;
  TCustomWebServer = class(TCustomServerSocket)
  private
    FLog: TServerLog;
    FOnLog: THTTPLogEvent;
    FSearchPath: string;
    FDefaultURL: string;
    FExpandedSearchPath: string;
    procedure EventEvent(Sender: TObject; Socket: TCustomWinSocket;
      SocketEvent: TSocketEvent);
    procedure ErrorEvent(Sender: TObject; Socket: TCustomWinSocket;
      ErrorEvent: TErrorEvent; var ErrorCode: Integer);
    function GetTranslatedDefaultURL: string;
    function GetExpandedSearchPath: string;
    procedure SetSearchPath(const Value: string);
  protected
    procedure DoActivate(Value: Boolean); override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure LogRequest(Request: TWebServerRequest;
      ClientSocket: TServerClientWinSocket);
    procedure LogError(AErrorEvent: TErrorEvent; AErrorCode: Integer;
      const AErrorMsg: string);
  public
    property OnLog: THTTPLogEvent read FOnLog write FOnLog;
    property SearchPath: string read FSearchPath write SetSearchPath;
    property ExpandedSearchPath: string read GetExpandedSearchPath;
    property DefaultURL: string read FDefaultURL write FDefaultURL;
    property TranslatedDefaultURL: string read GetTranslatedDefaultURL;
    property Port;
    property Active;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  TServerLog = class(TCustomServerLog)
  private
    FWebServer: TCustomWebServer;
  protected
    procedure DoOnLog(Transaction: TTransactionLogEntry;
      var Release: Boolean); override;
  public
    constructor Create(AServer: TCustomWebServer);
  end;


const
  DateFormat = 'ddd, dd mmm yyyy hh:mm:ss';    { Do not localize }
  Methods: array[TMethodType] of string = (
    '', 'GET', 'PUT', 'POST', 'HEAD');         { Do not localize }

function HexToChar(Hi, Lo: Char): Char;

implementation

uses Forms, EncdDecd, Consts, BrkrConst, SvrConst;

function LocalTimeToUTCTime(DateTime: TDateTime): TDateTime; forward;
function IsDir(Path: string): Boolean;  forward;
procedure StripTrailingSlash(var Path: string);  forward;
procedure AddTrailingSlash(var Path: string);  forward;
function UnixPathToDosPath(const Path: string): string;  forward;
function DosPathToUnixPath(const Path: string): string; forward;

const
  viMethod = 0;
  viProtocolVersion = 1;
  viURL = 2;
  viQuery = 3;
  viPathInfo = 4;
  viPathTranslated = 5;
  viCacheControl = 6;
  viDate = 7;
  viAccept = 8;
  viFrom = 9;
  viHost = 10;
  viIfModified = 11;
  viReferer = 12;
  viUserAgent = 13;
  viContentEncoding = 14;
  viContentType = 15;
  viContentLength = 16;
  viContentVersion = 17;
  viDerivedFrom = 18;
  viExpires = 19;
  viTitle = 20;
  viRemoteAddr = 21;
  viRemoteHost = 22;
  viScriptName = 23;
  viServerPort = 24;
  viContent = 25;
  viConnection = 26;
  viCookie = 27;
  viAuthorization = 28;

  CGIServerVariables: array[viMethod..viAuthorization] of string = (
    'REQUEST_METHOD',                          { Do not localize }
    'SERVER_PROTOCOL',                         { Do not localize }
    'URL',                                     { Do not localize }
    'QUERY_STRING',                            { Do not localize }
    'PATH_INFO',                               { Do not localize }
    'PATH_TRANSLATED',                         { Do not localize }
    'HTTP_CACHE_CONTROL',                      { Do not localize }
    'HTTP_DATE',                               { Do not localize }
    'HTTP_ACCEPT',                             { Do not localize }
    'HTTP_FROM',                               { Do not localize }
    'HTTP_HOST',                               { Do not localize }
    'HTTP_IF_MODIFIED_SINCE',                  { Do not localize }
    'HTTP_REFERER',                            { Do not localize }
    'HTTP_USER_AGENT',                         { Do not localize }
    'HTTP_CONTENT_ENCODING',                   { Do not localize }
    'HTTP_CONTENT_TYPE',                       { Do not localize }
    'HTTP_CONTENT_LENGTH',                     { Do not localize }
    'HTTP_CONTENT_VERSION',                    { Do not localize }
    'HTTP_DERIVED_FROM',                       { Do not localize }
    'HTTP_EXPIRES',                            { Do not localize }
    'HTTP_TITLE',                              { Do not localize }
    'REMOTE_ADDR',                             { Do not localize }
    'REMOTE_HOST',                             { Do not localize }
    'SCRIPT_NAME',                             { Do not localize }
    'SERVER_PORT',                             { Do not localize }
    '',                                        { Do not localize }
    'HTTP_CONNECTION',                         { Do not localize }
    'HTTP_COOKIE',                             { Do not localize }
    'HTTP_AUTHORIZATION');                     { Do not localize }

const
  ParseBufSize = 4096;

const

  Months: array[1..12] of string = (
    'Jan', 'Feb', 'Mar', 'Apr',            { Do not localize }
    'May', 'Jun', 'Jul', 'Aug',            { Do not localize }
    'Sep', 'Oct', 'Nov', 'Dec');           { Do not localize }

procedure BinToHex(Buffer, Text: PChar; BufSize: Integer); assembler;
asm
        PUSH    ESI
        PUSH    EDI
        MOV     ESI,EAX
        MOV     EDI,EDX
        MOV     EDX,0
        JMP     @@1
@@0:    DB      '0123456789ABCDEF'   { do not localize }
@@1:    LODSB
        MOV     DL,AL
        AND     DL,0FH
        MOV     AH,@@0.Byte[EDX]
        MOV     DL,AL
        SHR     DL,4
        MOV     AL,@@0.Byte[EDX]
        STOSW
        DEC     ECX
        JNE     @@1
        POP     EDI
        POP     ESI
end;

function HexToBin(Text, Buffer: PChar; BufSize: Integer): Integer; assembler;
asm
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        MOV     ESI,EAX
        MOV     EDI,EDX
        MOV     EBX,EDX
        MOV     EDX,0
        JMP     @@1
@@0:    DB       0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1
        DB      -1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1
        DB      -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
        DB      -1,10,11,12,13,14,15
@@1:    LODSW
        CMP     AL,'0'
        JB      @@2
        CMP     AL,'f'
        JA      @@2
        MOV     DL,AL
        MOV     AL,@@0.Byte[EDX-'0']
        CMP     AL,-1
        JE      @@2
        SHL     AL,4
        CMP     AH,'0'
        JB      @@2
        CMP     AH,'f'
        JA      @@2
        MOV     DL,AH
        MOV     AH,@@0.Byte[EDX-'0']
        CMP     AH,-1
        JE      @@2
        OR      AL,AH
        STOSB
        DEC     ECX
        JNE     @@1
@@2:    MOV     EAX,EDI
        SUB     EAX,EBX
        POP     EBX
        POP     EDI
        POP     ESI
end;

function HexToChar(Hi, Lo: Char): Char;
asm
        XOR     ECX,ECX
        CMP     AL,'0'
        JB      @@1
        CMP     AL,'f'
        JA      @@1
        MOV     CL,AL
        MOV     AL,@@0.Byte[ECX-'0']
        CMP     AL,-1
        JE      @@1
        SHL     AL,4
        CMP     DL,'0'
        JB      @@1
        CMP     DL,'f'
        JA      @@1
        MOV     CL,DL
        MOV     AH,@@0.Byte[ECX-'0']
        CMP     AH,-1
        JE      @@1
        OR      AL,AH
        JMP     @@2
@@0:    DB       0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1
        DB      -1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1
        DB      -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
        DB      -1,10,11,12,13,14,15
@@1:    MOV     AL,20H
@@2:
end;

{ EWebServerException }

constructor EWebServerException.Create(const Message: string;
  ARequest: TWebServerRequest);
begin
  inherited Create(Message);
  FRequest := ARequest;
end;

procedure ConvertPluses(var S: string);
var
  I: Integer;
begin
  for I := 1 to Length(S) do if S[I] = '+' then S[I] := ' ';
end;

function PrintableToReadable(const S: string): string;
begin
  Result := S;
{  SetString(Result, PChar(nil), Length(S));}
end;

{ TWebServerRequest}

constructor TWebServerRequest.Create(APort: Integer;
  ARemoteAddress, ARemoteHost: string);
begin
  inherited Create;
  //  IntegerVariable[viExpires] := -1;
  //  IntegerVariable[viDate] := -1;
  FLastModified := -1;
  //  IntegerVariable[viIfModified] := -1;
  IntegerVariable[viContentLength] := 0;
  IntegerVariable[viServerPort] := APort;
  StringVariable[viRemoteAddr] := ARemoteAddress;
  StringVariable[viRemoteHost] := ARemoteHost;
  FExtHeaders := TStringList.Create;
end;

destructor TWebServerRequest.Destroy;
begin
  FExtHeaders.Free;
  inherited Destroy;
end;

procedure TWebServerRequest.AddExtHeader(Name, Value: string);
begin
  FExtHeaders.Add(Name + '=' + Value);
end;

function TWebServerRequest.GetFieldByName(const Name: string): string;

  function NameToIndex(const AName: string): Integer;
  var
    I: Integer;
  begin
    Result := -1;
    for I := Low(CGIServerVariables) to High(CGIServerVariables) do
    begin
      if CompareText(CGIServerVariables[I], AName) = 0 then
      begin
        Result := I;
        Exit;
      end;
    end;
  end;

  function StripHTTP(const Name: string): string;
  begin
    if Pos('HTTP_', Name) = 1 then  { do not localize }
      Result := Copy(Name, 6, MaxInt)
    else Result := Name;
  end;

var
  Index: Integer;
begin
  Index := NameToIndex(Name);
  if Index = -1 then
    Index := NameToIndex(StripHTTP(Name));
  if Index <> -1 then
    Result := FStringVariable[Index]
  else
    Result := FExtHeaders.Values[Name];
end;

function TWebServerRequest.GetStringVariable(Index: Integer): string;
begin
  Assert(Index <= High(FStringVariable), 'Index out of bounds');  { do not localize }
  case Index of
    25: if (FStringVariable[Index] = '') and (ContentLength <> 0) then
      FStringVariable[Index] := ReadString(ContentLength);
  end;
  Result := FStringVariable[Index];
end;

function TWebServerRequest.GetDateVariable(Index: Integer): TDateTime;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  if Value <> '' then
    Result := ParseDate(Value)
  else Result := -1;
end;

function TWebServerRequest.GetIntegerVariable(Index: Integer): Integer;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  if Value <> '' then
    Result := StrToInt(Value)
  else Result := -1;
end;

function TWebServerRequest.ReadClient(var Buffer; Count: Integer): Integer;

type
  TBytes = array[0..MaxInt - 1] of Byte;
var
  L: Integer;
begin

  Result := 0;
  L := 0;
  if FReadParserContent < Length(FParserContent) then
  begin
    L := Length(FParserContent) - FReadParserContent;
    if Count < L then L := Count;
    Move(FParserContent[FReadParserContent+1], Buffer, L);
    FReadParserContent := FReadParserContent + L;
    Count := Count - L;
    Result := L;
  end;

  if Count > 0 then
    if Assigned(FRequestBufferStream) then
      Result := Result + FRequestBufferStream.Read(TBytes(Buffer)[L], Count)
    else
      Result := Result + FClientSocket.ReceiveBuf(TBytes(Buffer)[L], Count)
end;

function TWebServerRequest.ReadString(Count: Integer): string;
var
  Len: Integer;
begin
  SetLength(Result, Count);
  Len := ReadClient(Pointer(Result)^, Count);
  if Len > 0 then
    SetLength(Result, Len)
  else Result := '';
end;

function TWebServerRequest.TranslateURI(const URI: string): string;
begin
  // Not implemented
  Result := URI;
end;

function TWebServerRequest.WriteClient(var Buffer; Count: Integer): Integer;
var
  S: string;
begin
  Result := Count;
  try
    SetString(S, PChar(@Buffer), Count);
    FLogBuffer := FLogBuffer + S;
    FClientSocket.SendBuf(Buffer, Count);
  except
    Result := 0;
  end;
end;

function TWebServerRequest.WriteString(const AString: string): Boolean;
begin
  Result := WriteClient(Pointer(AString)^, Length(AString)) = Length(AString);
end;

function TWebServerRequest.WriteHeaders(StatusCode: Integer;
  const StatusString, Headers: string): Boolean;
var
  FVersion: string;
begin
  FVersion := '1.1';
  Result := WriteString(Format('HTTP/%s %s'#13#10'%s', [FVersion, StatusString, Headers])); { do not localize }
end;

procedure TWebServerRequest.SetStringVariable(
  Index: Integer; const Value: string);
begin
  FStringVariable[Index] := Value;
  case Index of
    viMethod: UpdateMethodType;
  end;
end;

procedure TWebServerRequest.SetDateVariable(Index: Integer;
  Value: TDateTime);
begin
  StringVariable[Index] := DateTimeToStr(Value)
end;

procedure TWebServerRequest.SetIntegerVariable(Index, Value: Integer);
begin
  StringVariable[Index] := IntToStr(Value);
end;

function TWebServerRequest.GetRequestBuffer: string;
var
  Pos: Integer;
begin
  if Length(FRequestBuffer) = 0 then
  begin
    SetLength(FRequestBuffer, FRequestBufferStream.Size);
    Pos := FRequestBufferStream.Position;
    try
      FRequestBufferStream.Seek(0, soFromBeginning);
      FRequestBufferStream.Read(Pointer(FRequestBuffer)^, FRequestBufferStream.Size);
    finally
      FRequestBufferStream.Seek(Pos, soFromBeginning);
    end;
  end;
  Result := FRequestBuffer;
end;

{ TWebServerResponse }

constructor TWebServerResponse.Create(Request: TWebServerRequest;
  AClientSocket: TServerClientWinSocket);
begin
  inherited Create(Request);
  FClientSocket := AClientSocket;
  FRequest := Request;
  if FRequest.ProtocolVersion <> '' then;
    FVersion := '1.0';  
  StatusCode := 200;
  FServer := 'Delphi Test Server/1.0';       { Do not localize }
  FLastModified := -1;
  FExpires := -1;
  FDate := LocalTimeToUTCTime(Now);
end;

destructor TWebServerResponse.Destroy;
begin
  // Log response
  TWebServerWinSocket(FClientSocket.ServerWinSocket).ServerComponent.FLog.LogResponse(
      Self.Request.FLogBuffer);
  Self.Request.FLogBuffer := '';
  FContentStream.Free;
  inherited Destroy;
end;

function TWebServerResponse.GetStringVariable(Index: Integer): string;
begin
  if (Index >= 0) and (Index <= High(FStringVariables)) then
    Result := FStringVariables[Index];
end;

procedure TWebServerResponse.SetStringVariable(Index: Integer; const Value: string);
begin
  if (Index >= Low(FStringVariables)) and (Index <= High(FStringVariables)) then
    FStringVariables[Index] := Value;
end;

procedure TWebServerResponse.SetDateVariable(Index: Integer; const Value: TDateTime);
begin
  if (Index >= Low(FDateVariables)) and (Index <= High(FDateVariables)) then
    if Value <> FDateVariables[Index] then
      FDateVariables[Index] := Value;
end;

procedure TWebServerResponse.SetIntegerVariable(Index: Integer; Value: Integer);
begin
  if (Index >= Low(FIntegerVariables)) and (Index <= High(FIntegerVariables)) then
    if Value <> FDateVariables[Index] then
      FIntegerVariables[Index] := Value;
end;

function TWebServerResponse.GetContent: string;
begin
  Result := FContent;
end;

function TWebServerResponse.GetDateVariable(Index: Integer): TDateTime;
begin
  if (Index >= 0) and (Index < 3) then
    Result := FDateVariables[Index]
  else Result := -1;
end;

function TWebServerResponse.GetIntegerVariable(Index: Integer): Integer;
begin
  if (Index >= 0) and (Index < 2) then
    Result := FIntegerVariables[Index]
  else Result := -1;
end;

function TWebServerResponse.GetStatusCode: Integer;
begin
  Result := FStatusCode;
end;

procedure TWebServerResponse.SetStatusCode(Value: Integer);
begin
  if FStatusCode <> Value then
  begin

    FStatusCode := Value;
    case Value of
      100: FReasonString := 'Continue';                  { Do not localize }
      101: FReasonString := 'Switching Protocols';       { Do not localize }
      200: FReasonString := 'OK';                        { Do not localize }
      201: FReasonString := 'Created';                   { Do not localize }
      202: FReasonString := 'Accepted';                  { Do not localize }
      203: FReasonString := 'Non-Authoritative Information';  { Do not localize }
      204: FReasonString := 'No Content';                 { Do not localize }
      205: FReasonString := 'Reset Content';              { Do not localize }
      206: FReasonString := 'Partial Content';            { Do not localize }
      300: FReasonString := 'Multiple Choices';           { Do not localize }
      301: FReasonString := 'Moved Permanently';          { Do not localize }
      302: FReasonString := 'Moved Temporarily';          { Do not localize }
      303: FReasonString := 'See Other';                  { Do not localize }
      304: FReasonString := 'Not Modified';               { Do not localize }
      305: FReasonString := 'Use Proxy';                  { Do not localize }
      400: FReasonString := 'Bad Request';                { Do not localize }
      401: FReasonString := 'Unauthorized';               { Do not localize }
      402: FReasonString := 'Payment Required';           { Do not localize }
      403: FReasonString := 'Forbidden';                  { Do not localize }
      404: FReasonString := 'Not Found';                  { Do not localize }
      405: FReasonString := 'Method Not Allowed';         { Do not localize }
      406: FReasonString := 'None Acceptable';            { Do not localize }
      407: FReasonString := 'Proxy Authentication Required';  { Do not localize }
      408: FReasonString := 'Request Timeout';             { Do not localize }
      409: FReasonString := 'Conflict';                    { Do not localize }
      410: FReasonString := 'Gone';                        { Do not localize }
      411: FReasonString := 'Length Required';             { Do not localize }
      412: FReasonString := 'Unless True';                 { Do not localize }
      500: FReasonString := 'Internal Server Error';       { Do not localize }
      501: FReasonString := 'Not Implemented';             { Do not localize }
      502: FReasonString := 'Bad Gateway';                 { Do not localize }
      503: FReasonString := 'Service Unavailable';         { Do not localize }
      504: FReasonString := 'Gateway Timeout';             { Do not localize }
    end;
  end;
end;

function TWebServerResponse.GetLogMessage: string;
begin
  // Service not available
  Result := '';
end;

procedure TWebServerResponse.SetLogMessage(const Value: string);
begin
  // Service not available
end;

procedure TWebServerResponse.SetContent(const Value: string);
begin
  FContent := Value;
  FContentLength := Length(FContent);
end;

procedure TWebServerResponse.SetContentStream(Value: TStream);
begin
  FContentStream := Value;
  FContentLength := FContentStream.Size;
end;

procedure TWebServerResponse.SendResponse;
var
  Header: string;

  procedure AddHeaderItem(const Item, FormatStr: string);
  begin
    if Item <> '' then
      Header := Header + Format(FormatStr, [Item]);
  end;

var
  StatusString: string;
begin
  if FRequest.ProtocolVersion <> '' then
  begin
    //Header := Format('HTTP/%s %d %s'#13#10, [FVersion, FStatusCode, FReasonString]);
    if (FReasonString <> '') and (FStatusCode > 0) then
      StatusString := Format('%d %s', [FStatusCode, FReasonString])
    else StatusString := '200 OK';                  { do not localize }
    AddHeaderItem(Location, 'Location: %s'#13#10);  { do not localize }
    if FDate > 0 then
      Header := Header +
        FormatDateTime('Date: ' + DateFormat + ' GMT'#13#10, FDate);  { do not localize }
    AddHeaderItem(FServer, 'Server: %s'#13#10);                       { do not localize }
    AddHeaderItem(FWWWAuthenticate, 'WWW-Authenticate: %s');          { do not localize }
    if FRealm <> '' then
      AddHeaderItem(FRealm, 'Realm="%s"'#13#10)                       { do not localize }
    else if FWWWAuthenticate <> '' then
      Header := Header + #13#10;
    AddHeaderItem(FAllow, 'Allow: %s'#13#10);                         { do not localize }
    AddHeaderItem(FContentVersion, 'Content-Version: %s'#13#10);      { do not localize }
    AddHeaderItem(FDerivedFrom, 'Derived-From: %s'#13#10);            { do not localize }
    if Expires > 0 then
      AddHeaderItem(Format(FormatDateTime(sDateFormat + ' "GMT"',               {do not localize}
        Expires), [DayOfWeekStr(Expires), MonthStr(Expires)]), 'Expires: %s'#13#10);  {do not localize}

    if LastModified > 0 then
      AddHeaderItem(Format(FormatDateTime(sDateFormat +
        ' "GMT"', LastModified), [DayOfWeekStr(LastModified),                   {do not localize}
        MonthStr(LastModified)]), 'Last-Modified: %s'#13#10);                         {do not localize}
    AddHeaderItem(FTitle, 'Title: %s'#13#10);                        { do not localize }
    AddHeaderItem(FContentEncoding, 'Content-Encoding: %s'#13#10);   { do not localize }
    AddHeaderItem(FContentType, 'Content-Type: %s'#13#10);           { do not localize }
    if (FContent <> '') or (FContentStream <> nil) then
      AddHeaderItem(IntToStr(FContentLength), 'Content-Length: %s'#13#10);  { do not localize }
    Header := Header + 'Content:'#13#10#13#10;                       { do not localize }
    if ContentStream = nil then
      Header := Header + FContent;
    HTTPRequest.WriteHeaders(StatusCode, StatusString, Header);
  end else if FContentStream = nil then
    HTTPRequest.WriteString(FContent);
  if FContentStream <> nil then
  begin
    FClientSocket.SendStream(FContentStream);
    // not logged.
    FContentStream := nil;
  end;
end;

procedure TWebServerResponse.SendStream(AStream: TStream);
begin
  FClientSocket.SendStream(AStream);
end;

procedure TWebServerResponse.SendRedirect(const URI: string);
begin
  Location := URI;
  StatusCode := 302;
  ContentType := 'text/html';  { do not localize }
  Content := Format(sDocumentMoved, [URI]);
  SendResponse;
end;

function TWebServerResponse.Sent: Boolean;
begin
  Result := FSent;
end;

{ TWebServerThread }

constructor TWebServerThread.Create(CreateSuspended: Boolean;
  ASocket: TServerClientWinSocket);
begin
  FRegistry := TRegistry.Create;
  FRegistry.RootKey := HKEY_CLASSES_ROOT;
  inherited Create(CreateSuspended, ASocket);
end;

destructor TWebServerThread.Destroy;
begin
  FRegistry.Free;
  inherited Destroy;
end;

procedure TWebServerThread.ParseCommand(Parser: THTTPParser; Request: TWebServerRequest);

  procedure SkipLine;
  begin
    Parser.CopyToEOL;
    Parser.SkipEOL;
  end;

  procedure AddExtHeader;
  var
    Field, Value: string;
  begin
    Field := Parser.TokenString;
    if Parser.NextToken = ':' then
    begin
      Parser.NextToken;
      Value := Parser.CopyToEOL;
    end;
    Request.AddExtHeader(Field, Value);
    Parser.NextToken;
//    Parser.SkipEOL;
  end;

  function ParseCommand: Boolean;
  var
    EndURL: Integer;
    URLString: string;
    Temp, Method: string;
  begin
    case Parser.Token of
      toGET: Request.StringVariable[viMethod] := 'GET';                         { do not localize }
      toPUT: Request.StringVariable[viMethod] := 'PUT';                         { do not localize }
      toDELETE: Request.StringVariable[viMethod] := 'ANY' {hmDelete};           { do not localize }
      toPOST: Request.StringVariable[viMethod] := 'POST';                       { do not localize }
      toPATCH: Request.StringVariable[viMethod] := 'ANY' {hmPatch};             { do not localize }
      toCOPY: Request.StringVariable[viMethod] := 'ANY' {hmCopy};               { do not localize }
      toHEAD: Request.StringVariable[viMethod] := 'HEAD';                       { do not localize }
    end;
    Method := Parser.TokenString;
    Parser.NextToken;
    Temp := Parser.CopyToEOL;
    Request.FRequestLine := Method + Temp;
    URLString := TrimLeft(Temp);
    EndURL := Pos(' ', URLString);
    if EndURL > 0 then
    begin
      Request.StringVariable[viProtocolVersion] := TrimRight(Copy(URLString, EndURL + 1, MaxInt));
      Delete(URLString, EndURL, MaxInt);
    end;
    EndURL := Pos('?', URLString);
    if EndURL > 0 then
    begin
      Temp := Copy(URLString, EndURL + 1, MaxInt);
      ConvertPluses(Temp);
      Request.StringVariable[viQuery] := Temp;
    end else EndURL := MaxInt;
    Temp := Copy(URLString, 1, EndURL - 1);
    if Temp = '/' then
      Temp := '';
    Request.StringVariable[viPathInfo] := Temp;
    Result := Request.StringVariable[viProtocolVersion] = '';
    if not Result then Parser.NextToken;
  end;

  procedure ParseUserAgent;
  begin
    with Parser do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if Request.StringVariable[viUserAgent] = '' then
        Request.StringVariable[viUserAgent] := TrimLeft(CopyToEOL)
      else CopyToEOL;
      NextToken;
    end;
  end;

  procedure ParseConnection;
  begin
    with Parser do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if Request.StringVariable[viConnection] = '' then
        Request.StringVariable[viConnection] := TrimLeft(CopyToEOL)
      else CopyToEOL;
      NextToken;
    end;
  end;

  procedure ParseCookie;
  begin
    with Parser do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if Request.StringVariable[viCookie] = '' then
        Request.StringVariable[viCookie] := TrimLeft(CopyToEOL)
      else CopyToEOL;
      NextToken;
    end;
  end;

  procedure ParseContentType;
  begin
    with Parser do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if Request.StringVariable[viContentType] = '' then
        Request.StringVariable[viContentType] := TrimLeft(CopyToEOL)
      else CopyToEOL;
      NextToken;
    end;
  end;

  procedure ParseContentLen;
  begin
    with Parser, Request do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if Token = toInteger then IntegerVariable[viContentLength] := TokenInt;
      CopyToEol;
      NextToken;
    end;
  end;

  procedure ParseAccept;
  var
    Temp: string;
  begin
    with Parser, Request do
    begin
      NextToken;
      if Token = ':' then NextToken;
      Temp := StringVariable[viAccept];
      if Temp <> '' then
        Insert(', ', Temp, Length(Accept) + 1);
      Insert(CopyToEOL, Temp, MaxInt);
      StringVariable[viAccept] := Temp;
      NextToken;
    end;
  end;

  procedure ParseAuthorization;
  var
    DecodedStr: string;
    I: Integer;
  begin
    with Parser, Request do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if TokenSymbolIs('BASIC') then  { do not localize }
      begin
        NextToken;
        StringVariable[viAuthorization] := TrimLeft(CopyToEOL);
        DecodedStr := DecodeString(StringVariable[viAuthorization]);
        if DecodedStr <> '' then
        begin
          I := Pos(':', DecodedStr);
          if I > 0 then
          begin
            FUserName := Copy(DecodedStr, 1, I - 1);
            FPassword := Copy(DecodedStr, I + 1, MaxInt);
          end;
        end;
      end else
      begin
        NextToken;
        StringVariable[viAuthorization] := TrimLeft(CopyToEOL);
      end;
      NextToken;
    end;
  end;

  procedure ParseReferer;
  begin
    with Parser, Request do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if StringVariable[viReferer] = '' then
        StringVariable[viReferer] := TrimLeft(CopyToEOL)
      else CopyToEOL;
      NextToken;
    end;
  end;

  procedure ParseHost;
  begin
    with Parser, Request do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if StringVariable[viHost] = '' then
        StringVariable[viHost] := TrimLeft(CopyToEOL)
      else CopyToEOL;
      NextToken;
    end;
  end;

  function ParseDate: TDateTime;
  var
    Month, Day, Year, Hour, Minute, Sec: Integer;

    function GetMonth: Boolean;
    begin
      Month := 1;
      while not Parser.TokenSymbolIs(Months[Month]) and (Month < 13) do Inc(Month);
      Result := Month < 13;
    end;

    procedure GetTime;
    begin
      with Parser do
      begin
        Hour := TokenInt;
        NextToken;
        if Token = ':' then NextToken;
        Minute := TokenInt;
        NextToken;
        if Token = ':' then NextToken;
        Sec := TokenInt;
        NextToken;
      end;
    end;

  begin
    with Parser do
    begin
      HeaderField := False;
      try
        NextToken;
        if Token = ':' then NextToken;
        NextToken;
        if Token = ',' then NextToken;
        if GetMonth then
        begin
          NextToken;
          Day := TokenInt;
          NextToken;
          GetTime;
          Year := TokenInt;
        end else
        begin
          Day := TokenInt;
          NextToken;
          if Token = '-' then NextToken;
          GetMonth;
          NextToken;
          if Token = '-' then NextToken;
          Year := TokenInt;
          if Year < 100 then Inc(Year, 1900);
          NextToken;
          GetTime;
        end;
        Result := EncodeDate(Year, Month, Day) + EncodeTime(Hour, Minute, Sec, 0);
      finally
        HeaderField := True;
      end;
    end;
  end;

  procedure ParseDateField;
  begin
    Request.DateVariable[viDate] := ParseDate;
  end;

  procedure ParseIfModified;
  begin
    Request.DateVariable[viIfModified] := ParseDate;
  end;

  procedure DoGetCommand;
  begin
    GetFile(Request);
  end;

  procedure DoPostCommand;
  begin
    GetFile(Request);
  end;

  procedure DoHeadCommand;
  begin
    if not Head(Request) then
      URLNotFound(Request);
  end;

var
  P: PChar;
  L: Integer;
begin
  try
    while Parser.Token <> toEOF do with Parser do
    begin
      case Token of
        toGET,
        toPUT,
        toDELETE,
        toPOST,
        toPATCH,
        toCOPY,
        toHEAD: if ParseCommand then Break;
        toDate: ParseDateField;
        toIfModified: ParseIfModified;
        toAccept: ParseAccept;
        toUserAgent: ParseUserAgent;
        toContentType: ParseContentType;
        toContentLength: ParseContentLen;
        toReferer: ParseReferer;
        toAuthorization: ParseAuthorization;
        toHost: ParseHost;
        toConnection: ParseConnection;
        toCookie: ParseCookie;
        toEOL: Break; // At content
      else
        AddExtHeader;
      end;
    end;
    L := Request.IntegerVariable[viContentLength];
    Request.FRequestBufferStream := Parser.BufferRequest(L);
    Request.FReadParserContent := 0;
    P := Parser.SourcePtr;
    while (P^ <> #0) do Inc(P);
    SetString(Request.FParserContent, Parser.SourcePtr, P - Parser.SourcePtr);
    Parser.SourcePtr := P;
    Parser.TokenPtr := P;

    Self.LogRequest(Request);
    case Request.MethodType of
      mtGet: DoGetCommand;
      mtHead: DoHeadCommand;
      mtPost: DoPostCommand;
    else
      // CommandError(Request);
    end;
  except
    on EParserError do
      CommandError(Request);
  end;
end;

procedure TWebServerThread.HandleException;
var
  ExceptObj: Exception;
begin
  ExceptObj := Exception(ExceptObject);
  if ExceptObj is EWebServerException then
    ServerError(EWebServerException(ExceptObj).Request, ExceptObj.Message)
  else ServerError(nil, ExceptObj.Message);
end;

procedure TWebServerThread.Error(ErrorEvent: TErrorEvent; var ErrorCode: Integer);
begin
  inherited Error(ErrorEvent, ErrorCode);
  if ErrorCode <> 0 then
    TWebServerWinSocket(ClientSocket.ServerWinSocket).ServerComponent.LogError(
      ErrorEvent, ErrorCode, SysErrorMessage(ErrorCode));
end;

procedure TWebServerThread.ClientExecute;
var
  SocketStream: TWinSocketStream;
  HTTPParser: THTTPParser;
  Request: TWebServerRequest;
begin
  CoInitialize(nil);
  try
    while not Terminated and ClientSocket.Connected do
    begin
      Request :=
        TWebServerRequest.Create(TWebServerWinSocket(ServerSocket).ServerComponent.Port,
          ClientSocket.RemoteAddress,
          ClientSocket.RemoteHost);
      Request.FClientSocket := ClientSocket;
      try
        try
          try
            SocketStream := TWinSocketStream.Create(ClientSocket, 60000);
            try
              HTTPParser := THTTPParser.Create(SocketStream);
              try
                ParseCommand(HTTPParser, Request);
              finally
                HTTPParser.Free;
              end;
            finally
              SocketStream.Free;
            end;
          except
            on E: Exception do
              raise EWebServerException.Create(E.Message, Request);
          end;
        except
          HandleException;
        end;
        if CompareText(Request.Connection, 'Keep-Alive') <> 0 then  { do not localize }
          ClientSocket.Close;
      finally
        Request.Free;
      end;
      //ClientSocket.Close;
    end;
  finally
    CoUninitialize;
  end;
end;

function TWebServerThread.DoFileAccess(Request: TWebServerRequest;
  IsHeadMethod: Boolean): Boolean;

  function CheckFileExists(const AFileName: string): Boolean;
  begin
    Result := GetFileAttributes(PChar(AFileName)) <> DWORD(-1);
  end;

  function SearchForFile(ADirList: string): string;
  var
    I, P, L: Integer;
    FileName: string;
  begin
    FileName := Request.PathInfo;
    P := Pos('/', FileName);
    while P <> 0 do
    begin
      if P = Length(FileName) then
        Delete(FileName, P, 1)
      else
        Delete(FileName, 1, P);
      P := Pos('/', FileName);
    end;
    if (FileName <> '') then
    begin
      P := 1;
      L := Length(ADirList);
      while P <= L do
      begin
        I := P;
        while (P <= L) and (ADirList[P] <> ';') do Inc(P);
        Result := Copy(ADirList, I, P - I);
        if (Result <> '') and not IsDelimiter(':\', Result, Length(Result)) then
          Result := Result + '\';
        Result := ExpandFileName(Result + FileName);
        if CheckFileExists(Result) then Exit;
        Inc(P);
      end;
    end;
    Result := '';
  end;

  function SearchForCoClass(var ClsID: TGuid; var ID: string): Boolean;
  begin
    Result := ReqImpl.SearchForCoClass(Request, ID, ClsID);
  end;

var
  FileDate: TDateTime;
  Response: TWebServerResponse;
  FileName: string;
  ClsID: TGUID;
  HaveCoClass: Boolean;
  ComWebApp: IWebBroker;
  DefaultURL: string;
  ID: string;
begin
  Result := False;
  if Request.PathInfo = '' then
  begin
    DefaultURL := TWebServerWinSocket(ServerSocket).ServerComponent.TranslatedDefaultURL;
    if DefaultURL <> '' then
    begin
      Response := TWebServerResponse.Create(Request, ClientSocket);
      with Response do
      try
        Response.SendRedirect(DefaultURL);
      finally
        Free;
      end;
      Result := True;
    end;
  end
  else
  begin
    HaveCoClass := SearchForCoClass(ClsId, ID);
    if HaveCoClass then
    begin
      Response := TWebServerResponse.Create(Request, ClientSocket);
      with Response do
      try
        ComWebApp := CreateComObject(ClsID) as IWebBroker;
        // Using stub parameter is always true.
        ComWebApp.HandleRequest(TWebRequestImpl.Create(Request, Response,
          True));
      finally
        Free;
      end;
      Result := True;
    end
    else
    begin
      FileName := SearchForFile(
        TWebServerWinSocket(ServerSocket).ServerComponent.ExpandedSearchpath);
      if FileName <> '' then
      begin
        with TWebServerResponse.Create(Request, ClientSocket) do
        try
          FileDate := LocalTimeToUTCTime(FileDateToDateTime(FileAge(FileName)));
          if (Request.IfModifiedSince > -1) and (FileDate <= Request.IfModifiedSince) then
          begin
            StatusCode := 304;
          end else
          begin
            LastModified := FileDate;
            ContentType := GetMIMEType(FileName);
            if not IsHeadMethod then
              ContentStream := TFileStream.Create(FileName, fmOpenRead or
                fmShareDenyWrite);
          end;
          SendResponse;
        finally
          Free;
        end;
        Result := True;
      end
    end;
  end;

  if not Result then URLNotFound(Request);
end;

(* Not used
procedure TWebServerThread.DumpRequest(Request: TWebServerRequest;
  Response: TWebServerResponse);
var
  S: string;
  I: Integer;
begin
  Response.ContentType := 'text/html';
  S := '<HTML><TABLE>';
  for I := Low(CGIServerVariables) to High(CGIServerVariables) do
  begin
    S := Format('%s<TR><TD>%s</TD><TD>%s</TD></TR>'#13#10,
      [S, CGIServerVariables[I], Request.GetStringVariable(I)]);
  end;
  S := S + '</TABLE></HTML>';
  S := S + '<p>RequestBuffer:</p><pre>' + Request.FRequestBuffer + '**end**</pre>';
  S := S + '</HTML>';
  Response.Content := S;
end;
*)

procedure TWebServerThread.LogRequest(Request: TWebServerRequest);
begin
  TWebServerWinSocket(ServerSocket).ServerComponent.LogRequest(Request, ClientSocket);
end;

function TWebServerThread.GetFile(Request: TWebServerRequest): Boolean;
begin
  Result := DoFileAccess(Request, False);
end;

function TWebServerThread.Head(Request: TWebServerRequest): Boolean;
begin
  Result := DoFileAccess(Request, True);
end;

procedure TWebServerThread.CommandError(Request: TWebServerRequest);
var
  Response: TWebServerResponse;
begin
  Response := TWebServerResponse.Create(Request, ClientSocket);
  with Response do
  try
    ContentType := 'text/html';  { do not localize }
    StatusCode := 400;
    Content := sBadRequest;
    SendResponse;
  finally
    Response.Free;
  end;
end;

procedure TWebServerThread.URLNotFound(Request: TWebServerRequest);
var
  Response: TWebServerResponse;
begin
  Response := TWebServerResponse.Create(Request, ClientSocket);
  with Response do
  try
    ContentType := 'text/html';  { do not localize }
    StatusCode := 404;
    Content := sNotFound;
    SendResponse;
  finally
    Response.Free;
  end;
end;

procedure TWebServerThread.ServerError(Request: TWebServerRequest;
  const ErrorMsg: string);
var
  Response: TWebServerResponse;
begin
  Response := TWebServerResponse.Create(Request, ClientSocket);
  with Response do
  try
    ContentType := 'text/html';  { do not localize }
    // StatusCode := 500;
    // 200 Let's browser display content
    StatusCode := 200;
    ReasonString := ErrorMsg;
    Content := Format(sInternalServerError, [ErrorMsg]);
    SendResponse;
  finally
    Response.Free;
  end;
end;

function TWebServerThread.GetMIMEType(const FileName: string): string;
var
  Ext: string;
begin
  Result := 'application/octet-stream';  { do not localize }
  Ext := ExtractFileExt(FileName);
  if (CompareText(Ext, '.exe') = 0) or (CompareText(Ext, '.dll') = 0) then  { do not localize }
    Exit
  else if FRegistry.OpenKey(Ext, False) then
  try
    if FRegistry.ValueExists('Content Type') then  { do not localize }
      Result := FRegistry.ReadString('Content Type');  { do not localize }
  finally;
    FRegistry.CloseKey;
  end;
end;

{ TWebServerWinSocket }

constructor TWebServerWinSocket.Create(AOwner: TCustomWebServer; ASocket: TSocket);
begin
  inherited Create(ASocket);
  FServerComponent := AOwner;
  ServerType := stThreadBlocking;
end;

function TWebServerWinSocket.DoCreateThread(ClientSocket: TServerClientWinSocket): TServerClientThread;
begin
  Result := TWebServerThread.Create(False, ClientSocket);
end;

{ TCustomWebServer }

constructor TCustomWebServer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FServerSocket := TWebServerWinSocket.Create(Self, INVALID_SOCKET);
  FServerSocket.OnSocketEvent := EventEvent;
  FServerSocket.OnErrorEvent := ErrorEvent;
  FServerSocket.ThreadCacheSize := 10;
  FLog := TServerLog.Create(Self);
end;

procedure TCustomWebServer.EventEvent(Sender: TObject; Socket: TCustomWinSocket;
    SocketEvent: TSocketEvent);
begin
  Event(Socket, SocketEvent);
end;

procedure TCustomWebServer.ErrorEvent(Sender: TObject; Socket: TCustomWinSocket;
    ErrorEvent: TErrorEvent; var ErrorCode: Integer);
begin
  Error(Socket, ErrorEvent, ErrorCode);
end;

destructor TCustomWebServer.Destroy;
begin
  inherited Destroy;
  FLog.Free;
end;

procedure TCustomWebServer.LogRequest(Request: TWebServerRequest;
  ClientSocket: TServerClientWinSocket);
begin
  FLog.LogRequest(Request);
end;

procedure TCustomWebServer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
end;

{ TAccessList }

type
  TAccessList = class(TStringList)
    procedure DefineProperties(Filer: TFiler); override;
    procedure ReadData(Reader: TReader);
    procedure WriteData(Writer: TWriter);
  end;

procedure TAccessList.DefineProperties(Filer: TFiler);

  function DoWrite: Boolean;
  begin
    if Filer.Ancestor <> nil then
    begin
      Result := True;
      if Filer.Ancestor is TStrings then
        Result := not Equals(TStrings(Filer.Ancestor))
    end
    else Result := Count > 0;
  end;

begin
  Filer.DefineProperty('AccessList', ReadData, WriteData, DoWrite);  { do not localize }
end;

procedure TAccessList.ReadData(Reader: TReader);
begin
  Reader.ReadListBegin;
  Clear;
  while not Reader.EndOfList do Add(DecodeString(Reader.ReadString));
  Reader.ReadListEnd;
end;

procedure TAccessList.WriteData(Writer: TWriter);
var
  I: Integer;
begin
  Writer.WriteListBegin;
  for I := 0 to Count - 1 do Writer.WriteString(EncodeString(Get(I)));
  Writer.WriteListEnd;
end;

procedure TCustomWebServer.DoActivate(Value: Boolean);
begin
  try
    inherited DoActivate(Value);
  except
    on E: Exception do
    begin
      LogError(eeConnect, 0, E.message);
      raise;
    end;
  end;
end;

function TCustomWebServer.GetTranslatedDefaultURL: string;
var
  S: string;
begin
  S := FDefaultURL;
  Result := S;
  if S <> '' then
  begin
    if (CompareText(Copy(S, 1, 4), 'http') <> 0) and  { do not localize }
      (CompareText(Copy(S, 1, 2), '//') <> 0) then
    begin
      Result := 'http:';  { do not localize }
      if Copy(S, 1, 2) = '//' then
        Result := Result + S
      else
      begin
        Result := Result + '//';
        if S[1] = '/' then
          Delete(S, 1, 1);
        Result := Format('%slocalhost:%d/%s', [Result, Port, S])  { do not localize }
      end;
    end;
  end;
end;

procedure TCustomWebServer.LogError(AErrorEvent: TErrorEvent;
  AErrorCode: Integer; const AErrorMsg: string);
begin
  FLog.LogError(AErrorEvent, AErrorCode, AErrorMsg);
end;

{ Utility functions }

function LocalTimeToUTCTime(DateTime: TDateTime): TDateTime;
var
  TimeZoneInfo: TTimeZoneInformation;
  Bias: TDateTime;
begin
  if GetTimeZoneInformation(TimeZoneInfo) <> DWORD(-1) then
  begin
    Bias := EncodeTime(Abs(TimeZoneInfo.Bias) div 60, Abs(TimeZoneInfo.Bias) mod 60, 0, 0);
    if TimeZoneInfo.Bias < 0 then
      Result := DateTime - Bias
    else Result := DateTime + Bias;
  end else Result := DateTime;
end;

function IsDir(Path: string): Boolean;
var
  Attr: Integer;
begin
  StripTrailingSlash(Path);
  Attr := FileGetAttr(Path);
  Result := (Attr <> -1) and (Attr and FILE_ATTRIBUTE_DIRECTORY <> 0);
end;

procedure StripTrailingSlash(var Path: string);
begin
  if (Path <> '') and (Path[Length(Path)] = '\') then
    Delete(Path, Length(Path), 1);
end;

procedure AddTrailingSlash(var Path: string);
begin
  if (Path = '') or (Path[Length(Path)] <> '\') then
    Insert('\', Path, Length(Path) + 1);
end;

function TranslateChar(const Str: string; FromChar, ToChar: Char): string;
var
  I: Integer;
begin
  Result := Str;
  for I := 1 to Length(Result) do
    if Result[I] = FromChar then
      Result[I] := ToChar
    else if Result[I] = '?' then Break;
end;

function UnixPathToDosPath(const Path: string): string;
begin
  Result := TranslateChar(Path, '/', '\');
end;

function DosPathToUnixPath(const Path: string): string;
begin
  Result := TranslateChar(Path, '\', '/');
end;

{ TServerLog }

constructor TServerLog.Create(AServer: TCustomWebServer);
begin
  inherited Create;
  FWebServer := AServer;
end;

procedure TServerLog.DoOnLog(Transaction: TTransactionLogEntry; var Release: Boolean);
begin
  if Assigned(FWebServer.FOnLog) then FWebServer.FOnLog(Self, Transaction, Release);
end;

function ExpandRootMacro(const InString: string): string;
var
  P: array[0..4096] of char;
  StartLen: Integer;
begin
  Result := InString;
  StartLen := 0;
  while not ((AnsiPos('$', Result) = 0) or (StartLen = Length(Result))) do
  begin
    StartLen := Length(Result);
    Result := StringReplace(Result, '$(', '%', [rfReplaceAll, rfIgnoreCase]);
    Result := StringReplace(Result, ')', '%', [rfReplaceAll, rfIgnoreCase]);

    ExpandEnvironmentStrings(PChar(Result), P, SizeOf(P));
    Result := P;
  end;
end;

function TCustomWebServer.GetExpandedSearchPath: string;
begin
  if (FExpandedSearchPath = '') and (SearchPath <> '') then
    FExpandedSearchPath := ExpandRootMacro(SearchPath);
  Result := FExpandedSearchPath;
end;

procedure TCustomWebServer.SetSearchPath(const Value: string);
begin
  FSearchPath := Value;
  FExpandedSearchPath := '';
end;

function GetBaseExePath: string;
var
  ModuleName: array[0..255] of Char;
begin
  GetModuleFileName(hInstance, ModuleName, sizeof(ModuleName));
  Result := ExtractFilePath(ModuleName);
end;

function GetRootDir: string;
var
  LongPath: string;
begin
  LongPath := GetBaseExePath;
  //---- remove trailing slash if present ----
  if IsPathDelimiter(LongPath, Length(LongPath)) then
    Delete(LongPath, Length(LongPath), 1);
  //---- remove last "bin" type dir to get product root dir ----
  Result := ExtractFilePath(LongPath);
  if Result = '' then Result := LongPath; // no subdir present (this is an outer dir)
  //---- remove trailing slash if present ----
  if IsPathDelimiter(Result, Length(Result)) then
    Delete(Result, Length(Result), 1);
end;

procedure InitialializeRootDirVariable(const AMacro: string);
var
  EnvVar: array[0..4096] of char;
begin
  if GetEnvironmentVariable(PChar(AMacro), EnvVar, Sizeof(EnvVar)) = 0 then
    SetEnvironmentVariable(PChar(AMacro), PChar(GetRootDir));
end;

initialization
  InitialializeRootDirVariable('DELPHI');  { do not localize }
end.
