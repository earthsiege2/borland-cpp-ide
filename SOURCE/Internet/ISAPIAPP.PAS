
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       ISAPI/NSAPI Web server application components   }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

{$DENYPACKAGEUNIT}

unit ISAPIApp;

interface

uses Windows, Classes, HTTPApp, WebBroker, ISAPI2;

type
  TISAPIRequest = class(TWebRequest)
  private
    FECB: PEXTENSION_CONTROL_BLOCK;
  protected
    function GetStringVariable(Index: Integer): string; override;
    function GetDateVariable(Index: Integer): TDateTime; override;
    function GetIntegerVariable(Index: Integer): Integer; override;
  public
    constructor Create(AECB: PEXTENSION_CONTROL_BLOCK);
    function GetFieldByName(const Name: string): string; override;
    function ReadClient(var Buffer; Count: Integer): Integer; override;
    function ReadString(Count: Integer): string; override;
    function TranslateURI(const URI: string): string; override;
    function WriteClient(var Buffer; Count: Integer): Integer; override;
    function WriteString(const AString: string): Boolean; override;
    property ECB: PEXTENSION_CONTROL_BLOCK read FECB;
  end;

  TISAPIResponse = class(TWebResponse)
  private
    FStatusCode: Integer;
    FStringVariables: array[0..MAX_STRINGS - 1] of string;
    FIntegerVariables: array[0..MAX_INTEGERS - 1] of Integer;
    FDateVariables: array[0..MAX_DATETIMES - 1] of TDateTime;
    FContent: string;
    FSent: Boolean;
  protected
    function GetContent: string; override;
    function GetDateVariable(Index: Integer): TDateTime; override;
    function GetIntegerVariable(Index: Integer): Integer; override;
    function GetLogMessage: string; override;
    function GetStatusCode: Integer; override;
    function GetStringVariable(Index: Integer): string; override;
    procedure SetContent(const Value: string); override;
    procedure SetDateVariable(Index: Integer; const Value: TDateTime); override;
    procedure SetIntegerVariable(Index: Integer; Value: Integer); override;
    procedure SetLogMessage(const Value: string); override;
    procedure SetStatusCode(Value: Integer); override;
    procedure SetStringVariable(Index: Integer; const Value: string); override;
  public
    constructor Create(HTTPRequest: TWebRequest);
    procedure SendResponse; override;
    procedure SendRedirect(const URI: string); override;
    procedure SendStream(AStream: TStream); override;
    function Sent: Boolean; override;
  end;

  TISAPIApplication = class(TWebApplication)
  private
    function NewRequest(var AECB: TEXTENSION_CONTROL_BLOCK): TISAPIRequest;
    function NewResponse(ISAPIRequest: TISAPIRequest): TISAPIResponse;
  public
    // These are the entry points relayed from the ISAPI DLL imports
    function GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL;
    function HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD;
    function TerminateExtension(dwFlags: DWORD): BOOL;
  end;

function GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL; stdcall;
function HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD; stdcall;
function TerminateExtension(dwFlags: DWORD): BOOL; stdcall;

implementation

uses SysUtils, BrkrConst;

const
  ServerVariables: array[0..28] of string = (
    '',
    'SERVER_PROTOCOL',
    'URL',
    '',
    '',
    '',
    'HTTP_CACHE_CONTROL',
    'HTTP_DATE',
    'HTTP_ACCEPT',
    'HTTP_FROM',
    'HTTP_HOST',
    'HTTP_IF_MODIFIED_SINCE',
    'HTTP_REFERER',
    'HTTP_USER_AGENT',
    'HTTP_CONTENT_ENCODING',
    'CONTENT_TYPE',
    'CONTENT_LENGTH',
    'HTTP_CONTENT_VERSION',
    'HTTP_DERIVED_FROM',
    'HTTP_EXPIRES',
    'HTTP_TITLE',
    'REMOTE_ADDR',
    'REMOTE_HOST',
    'SCRIPT_NAME',
    'SERVER_PORT',
    '',
    'HTTP_CONNECTION',
    'HTTP_COOKIE',
    'HTTP_AUTHORIZATION');

{ TISAPIRequest }

constructor TISAPIRequest.Create(AECB: PEXTENSION_CONTROL_BLOCK);
begin
  FECB := AECB;
  inherited Create;
end;

function TISAPIRequest.GetFieldByName(const Name: string): string;
var
  Buffer: array[0..4095] of Char;
  Size: DWORD;
begin
  Size := SizeOf(Buffer);
  if ECB.GetServerVariable(ECB.ConnID, PChar(Name), @Buffer, Size) then
  begin
    if Size > 0 then Dec(Size);
    SetString(Result, Buffer, Size);
  end else Result := '';
end;

function TISAPIRequest.GetStringVariable(Index: Integer): string;
begin
  case Index of
    0: Result := ECB.lpszMethod;
    3: Result := ECB.lpszQueryString;
    4: Result := ECB.lpszPathInfo;
    5: Result := ECB.lpszPathTranslated;
    1..2, 6..24, 26..28: Result := GetFieldByName(ServerVariables[Index]);
    25: if ECB.cbAvailable > 0 then
      SetString(Result, PChar(ECB.lpbData), ECB.cbAvailable);
   else
      Result := '';
  end;
end;

function TISAPIRequest.GetDateVariable(Index: Integer): TDateTime;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  if Value <> '' then
    Result := ParseDate(Value)
  else Result := -1;
end;

function TISAPIRequest.GetIntegerVariable(Index: Integer): Integer;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  if Value <> '' then
    Result := StrToInt(Value)
  else Result := -1;
end;

function TISAPIRequest.ReadClient(var Buffer; Count: Integer): Integer;
begin
  Result := Count;
  if not ECB.ReadClient(ECB.ConnID, @Buffer, DWORD(Result)) then
    Result := -1;
end;

function TISAPIRequest.ReadString(Count: Integer): string;
var
  Len: Integer;
begin
  SetLength(Result, Count);
  Len := ReadClient(Pointer(Result)^, Count);
  if Len > 0 then
    SetLength(Result, Len)
  else Result := '';
end;

function TISAPIRequest.TranslateURI(const URI: string): string;
var
  PathBuffer: array[0..1023] of Char;
  Size: Integer;
begin
  StrCopy(PathBuffer, PChar(URI));
  Size := SizeOf(PathBuffer);
  if ECB.ServerSupportFunction(ECB.ConnID, HSE_REQ_MAP_URL_TO_PATH,
    @PathBuffer, @Size, nil) then
    Result := PathBuffer
  else Result := '';
end;

function TISAPIRequest.WriteClient(var Buffer; Count: Integer): Integer;
begin
  Result := Count;
  if not ECB.WriteClient(ECB.ConnID, @Buffer, DWORD(Result), 0) then
    Result := -1;
end;

function TISAPIRequest.WriteString(const AString: string): Boolean;
begin
  Result := WriteClient(Pointer(AString)^, Length(AString)) = Length(AString);
end;

{ TISAPIResponse }

constructor TISAPIResponse.Create(HTTPRequest: TWebRequest);
begin
  inherited Create(HTTPRequest);
  if FHTTPRequest.ProtocolVersion = '' then
    Version := '1.0';
  StatusCode := 200;
  LastModified := -1;
  Expires := -1;
  Date := -1;
  ContentType := 'text/html';
end;

function TISAPIResponse.GetContent: string;
begin
  Result := FContent;
end;

function TISAPIResponse.GetDateVariable(Index: Integer): TDateTime;
begin
  if (Index >= Low(FDateVariables)) and (Index <= High(FDateVariables)) then
    Result := FDateVariables[Index]
  else Result := 0.0;
end;

function TISAPIResponse.GetIntegerVariable(Index: Integer): Integer;
begin
  if (Index >= Low(FIntegerVariables)) and (Index <= High(FIntegerVariables)) then
    Result := FIntegerVariables[Index]
  else Result := -1;
end;

function TISAPIResponse.GetLogMessage: string;
begin
  Result := TISAPIRequest(HTTPRequest).ECB.lpszLogData;
end;

function TISAPIResponse.GetStatusCode: Integer;
begin
  Result := FStatusCode;
end;

function TISAPIResponse.GetStringVariable(Index: Integer): string;
begin
  if (Index >= Low(FStringVariables)) and (Index <= High(FStringVariables)) then
    Result := FStringVariables[Index];
end;

function TISAPIResponse.Sent: Boolean;
begin
  Result := FSent;
end;

procedure TISAPIResponse.SetContent(const Value: string);
begin
  FContent := Value;
  if ContentStream = nil then
    ContentLength := Length(FContent);
end;

procedure TISAPIResponse.SetDateVariable(Index: Integer; const Value: TDateTime);
begin
  if (Index >= Low(FDateVariables)) and (Index <= High(FDateVariables)) then
    if Value <> FDateVariables[Index] then
      FDateVariables[Index] := Value;
end;

procedure TISAPIResponse.SetIntegerVariable(Index: Integer; Value: Integer);
begin
  if (Index >= Low(FIntegerVariables)) and (Index <= High(FIntegerVariables)) then
    if Value <> FIntegerVariables[Index] then
      FIntegerVariables[Index] := Value;
end;

procedure TISAPIResponse.SetLogMessage(const Value: string);
begin
  StrPLCopy(TISAPIRequest(HTTPRequest).ECB.lpszLogData, Value, HSE_LOG_BUFFER_LEN);
end;

{!! Strings not to be resourced !!}
procedure TISAPIResponse.SetStatusCode(Value: Integer);
begin
  if FStatusCode <> Value then
  begin
    FStatusCode := Value;
    ReasonString := StatusString(Value);
  end;
end;

procedure TISAPIResponse.SetStringVariable(Index: Integer; const Value: string);
begin
  if (Index >= Low(FStringVariables)) and (Index <= High(FStringVariables)) then
    FStringVariables[Index] := Value;
end;

procedure TISAPIResponse.SendResponse;
var
  StatusString: string;
  Headers: string;
  I: Integer;

  procedure AddHeaderItem(const Item, FormatStr: string);
  begin
    if Item <> '' then
      Headers := Headers + Format(FormatStr, [Item]);
  end;

begin
  if HTTPRequest.ProtocolVersion <> '' then
  begin
    TISAPIRequest(HTTPRequest).ECB.dwHttpStatusCode := StatusCode;
    if (ReasonString <> '') and (StatusCode > 0) then
      StatusString := Format('%d %s', [StatusCode, ReasonString])
    else StatusString := '200 OK';
    AddHeaderItem(Allow, 'Allow: %s'#13#10);
    for I := 0 to Cookies.Count - 1 do
      AddHeaderItem(Cookies[I].HeaderValue, 'Set-Cookie: %s'#13#10);
    AddHeaderItem(DerivedFrom, 'Derived-From: %s'#13#10);
    if Expires > 0 then
      Headers := Headers +
        Format(FormatDateTime('"Expires: "' + sDateFormat + ' "GMT"'#13#10, Expires),
          [DayOfWeekStr(Expires), MonthStr(Expires)]);
    if LastModified > 0 then
      Headers := Headers +
        Format(FormatDateTime('"Last-Modified: "' + sDateFormat + ' "GMT"'#13#10,
          LastModified), [DayOfWeekStr(LastModified), MonthStr(LastModified)]);
    AddHeaderItem(Title, 'Title: %s'#13#10);
    AddHeaderItem(WWWAuthenticate, 'WWW-Authenticate: %s'#13#10);
    AddCustomHeaders(Headers);
    AddHeaderItem(ContentVersion, 'Content-Version: %s'#13#10);
    AddHeaderItem(ContentEncoding, 'Content-Encoding: %s'#13#10);
    AddHeaderItem(ContentType, 'Content-Type: %s'#13#10);
    if (Content <> '') or (ContentStream <> nil) then
      AddHeaderItem(IntToStr(ContentLength), 'Content-Length: %s'#13#10);
    Headers := Headers + 'Content:'#13#10#13#10;
    with TISAPIRequest(FHTTPRequest) do
      ECB.ServerSupportFunction(ECB.ConnID, HSE_REQ_SEND_RESPONSE_HEADER,
        PChar(StatusString), nil, LPDWORD(Headers));
  end;
  if ContentStream = nil then
    HTTPRequest.WriteString(Content)
  else if ContentStream <> nil then
  begin
    SendStream(ContentStream);
    ContentStream := nil; // Drop the stream
  end;
  FSent := True;
end;

procedure TISAPIResponse.SendRedirect(const URI: string);
begin
  with TISAPIRequest(FHTTPRequest) do
    ECB.ServerSupportFunction(ECB.ConnID, HSE_REQ_SEND_URL_REDIRECT_RESP,
      PChar(URI), nil, nil);
  FSent := True;
end;

procedure TISAPIResponse.SendStream(AStream: TStream);
var
  Buffer: array[0..8191] of Byte;
  BytesToSend: Integer;
begin
  while AStream.Position < AStream.Size do
  begin
    BytesToSend := AStream.Read(Buffer, SizeOf(Buffer));
    FHTTPRequest.WriteClient(Buffer, BytesToSend);
  end;
end;

{ TISAPIApplication }

procedure HandleServerException(E: Exception; var ECB: TEXTENSION_CONTROL_BLOCK);
var
  ResultText, ResultHeaders: string;
  Size: DWORD;
begin
  ECB.dwHTTPStatusCode := 500;
  ResultText := Format(sInternalServerError, [E.ClassName, E.Message]);
  ResultHeaders := Format(
    'Content-Type: text/html'#13#10 +     //Not resourced
    'Content-Length: %d'#13#10 +          //Not resourced
    'Content:'#13#10#13#10, [Length(ResultText)]); //Not resourced
  ECB.ServerSupportFunction(ECB.ConnID, HSE_REQ_SEND_RESPONSE_HEADER,
    PChar('500 ' + E.Message), @Size, LPDWORD(ResultHeaders));
  Size := Length(ResultText);
  ECB.WriteClient(ECB.ConnID, Pointer(ResultText), Size, 0);
end;

function TISAPIApplication.GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL;
begin
  try
    Ver.dwExtensionVersion := MakeLong(HSE_VERSION_MINOR, HSE_VERSION_MAJOR);
    StrLCopy(Ver.lpszExtensionDesc, PChar(Title), HSE_MAX_EXT_DLL_NAME_LEN);
    Result := BOOL(1); // This is so that the Apache web server will know what "True" really is
  except
    Result := False;
  end;
end;

function TISAPIApplication.HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD;
var
  HTTPRequest: TISAPIRequest;
  HTTPResponse: TISAPIResponse;
begin
  try
    HTTPRequest := NewRequest(ECB);
    try
      HTTPResponse := NewResponse(HTTPRequest);
      try
        if HandleRequest(HTTPRequest, HTTPResponse) then
          Result := HSE_STATUS_SUCCESS
        else Result := HSE_STATUS_ERROR;
      finally
        HTTPResponse.Free;
      end;
    finally
      HTTPRequest.Free;
    end;
  except
    HandleServerException(Exception(ExceptObject), ECB);
    Result := HSE_STATUS_ERROR;
  end;
end;

function TISAPIApplication.NewRequest(var AECB: TEXTENSION_CONTROL_BLOCK): TISAPIRequest;
begin
  Result := TISAPIRequest.Create(@AECB);
end;

function TISAPIApplication.NewResponse(ISAPIRequest: TISAPIRequest): TISAPIResponse;
begin
  Result := TISAPIResponse.Create(ISAPIRequest);
end;

function TISAPIApplication.TerminateExtension(dwFlags: DWORD): BOOL;
begin
  Result := BOOL(1); // This is so that the Apache web server will know what "True" really is
end;

// ISAPI interface

function GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL;
begin
  Result := (Application as TISAPIApplication).GetExtensionVersion(Ver);
end;

function HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD;
begin
  Result := (Application as TISAPIApplication).HttpExtensionProc(ECB);
end;

function TerminateExtension(dwFlags: DWORD): BOOL;
begin
  Result := (Application as TISAPIApplication).TerminateExtension(dwFlags);
end;

procedure InitApplication;
begin
  Application := TISAPIApplication.Create(nil);
end;

procedure DoneApplication;
begin
  Application.Free;
  Application := nil;
end;

initialization
  InitApplication;
finalization
  DoneApplication;
end.
