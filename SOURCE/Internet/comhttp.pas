
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       COM Web server application components           }
{                                                       }
{       Copyright (c) 1997-2001 Borland Software Corp   }
{                                                       }
{*******************************************************}

unit ComHTTP;

interface

uses Windows, Classes, HTTPApp, WebReq, IniFiles,
WebLib, SysUtils;

type
  TCOMWebRequest = class(TWebRequest)
  private
    FIntf: IWebRequest;
    function UsingStub: Boolean;
  protected
    function GetStringVariable(Index: Integer): string; override;
    function GetDateVariable(Index: Integer): TDateTime; override;
    function GetIntegerVariable(Index: Integer): Integer; override;
    function GetInternalPathInfo: string; override;
    function GetInternalScriptName: string; override;
  public
    constructor Create(ARequest: IWebRequest);
    function GetFieldByName(const Name: string): string; override;
    function ReadClient(var Buffer; Count: Integer): Integer; override;
    function ReadString(Count: Integer): string; override;
    function TranslateURI(const URI: string): string; override;
    function WriteClient(var Buffer; Count: Integer): Integer; override;
    function WriteString(const AString: string): Boolean; override;
    function WriteHeaders(StatusCode: Integer; const StatusString, Headers: string): Boolean; override;
  end;

  TCOMWebResponse = class(TWebResponse)
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

  TComWebRequestHandler = class(TWebRequestHandler)
  private
    function NewRequest(ARequest: IWebRequest): TCOMWebRequest;
    function NewResponse(COMWebRequest: TCOMWebRequest): TCOMWebResponse;
    procedure HandleServerException(E: Exception;
      ARequest: IWebRequest);
    procedure HandleException(Sender: TObject);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Run(ARequest: IWebRequest);
  end;

implementation

uses BrkrConst, Variants;


{ TCGIRequest }

constructor TCOMWebRequest.Create(ARequest: IWebRequest);
begin
  FIntf := ARequest;
  inherited Create;
end;

function TCOMWebRequest.GetFieldByName(const Name: string): string;
begin
  Result := FIntf.GetFieldByName(Name);
end;

function VariantArrayToString(const V: OleVariant): string;
var
  P: Pointer;
  Size: Integer;
begin
  Result := '';
  if VarIsArray(V) and (VarType(V) and varTypeMask = varByte) then
  begin
    Size := VarArrayHighBound(V, 1) - VarArrayLowBound(V, 1) + 1;
    if Size > 0 then
    begin
      SetLength(Result, Size);
      P := VarArrayLock(V);
      try
        Move(P^, Result[1], Size);
      finally
        VarArrayUnlock(V);
      end;
    end;
  end;
end;

function TCOMWebRequest.GetStringVariable(Index: Integer): string;
begin
  Result := VariantArrayToString(FIntf.GetStringVariable(Index));
end;

function TCOMWebRequest.GetDateVariable(Index: Integer): TDateTime;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  if Value <> '' then
    Result := ParseDate(Value)
  else Result := -1;
end;

function TCOMWebRequest.GetIntegerVariable(Index: Integer): Integer;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  Result := StrToIntDef(Value, -1)
end;

function BufferToVariantArray(var Buffer; Count: Integer): OleVariant;
var
  P: Pointer;
begin
  Result := NULL;
  if Count > 0 then
  begin
    Result := VarArrayCreate([0, Count - 1], varByte);
    P := VarArrayLock(Result);
    try
      Move(Buffer, P^, Count);
    finally
      VarArrayUnlock(Result);
    end;
  end;
end;

function TCOMWebRequest.ReadClient(var Buffer; Count: Integer): Integer;
var
  V: OleVariant;
  P: Pointer;
begin
  Result := FIntf.ReadClient(V, Count);
  if Result > 0 then
  begin
    P := VarArrayLock(V);
    try
      Move(P^, Buffer, Result);
    finally
      VarArrayUnlock(V);
    end;
  end;
end;

function TCOMWebRequest.ReadString(Count: Integer): string;
var
  V: OleVariant;
begin
  if Count > 0 then
  begin
    FIntf.ReadString(V, Count);
    Result := VariantArrayToString(V);
  end;
  SetLength(Result, Count);
end;

function TCOMWebRequest.TranslateURI(const URI: string): string;
begin
end;

function TCOMWebRequest.WriteClient(var Buffer; Count: Integer): Integer;
var
  V: OleVariant;
begin
  V := BufferToVariantArray(Buffer, Count);
  Result := FIntf.WriteClient(V);
end;

function StringToVariantArray(const S: string): OleVariant;
var
  P: Pointer;
begin
  Result := NULL;
  if Length(S) > 0 then
  begin
    Result := VarArrayCreate([0, Length(S) - 1], varByte);
    P := VarArrayLock(Result);
    try
      Move(S[1], P^, Length(S));
    finally
      VarArrayUnlock(Result);
    end;
  end;
end;

function TCOMWebRequest.WriteString(const AString: string): Boolean;
begin
  if AString <> '' then
    Result := FIntf.WriteClient(StringToVariantArray(AString)) = Length(AString)
  else Result := False;
end;

function TCOMWebRequest.WriteHeaders(StatusCode: Integer; const StatusString,
  Headers: string): Boolean;
begin
  Result := FIntf.WriteHeaders(StatusCode, StringToVariantArray(StatusString),
    StringToVariantArray(Headers));
end;

{ TCGIResponse }

constructor TCOMWebResponse.Create(HTTPRequest: TWebRequest);
begin
  inherited Create(HTTPRequest);
  if FHTTPRequest.ProtocolVersion = '' then
    Version := '1.0';   {do not localize}
  StatusCode := 200;
  LastModified := -1;
  Expires := -1;
  Date := -1;
  ContentType := 'text/html';  {do not localize}
end;

function TCOMWebResponse.GetContent: string;
begin
  Result := FContent;
end;

function TCOMWebResponse.GetDateVariable(Index: Integer): TDateTime;
begin
  if (Index >= 0) and (Index < 3) then
    Result := FDateVariables[Index]
  else Result := -1;
end;

function TCOMWebResponse.GetIntegerVariable(Index: Integer): Integer;
begin
  if (Index >= 0) and (Index < 2) then
    Result := FIntegerVariables[Index]
  else Result := -1;
end;

function TCOMWebResponse.GetLogMessage: string;
begin
//  Result := TCGIRequest(HTTPRequest).ECB.lpszLogData;
end;

function TCOMWebResponse.GetStatusCode: Integer;
begin
  Result := FStatusCode;
end;

function TCOMWebResponse.GetStringVariable(Index: Integer): string;
begin
  if (Index >= 0) and (Index < 12) then
    Result := FStringVariables[Index];
end;

function TCOMWebResponse.Sent: Boolean;
begin
  Result := FSent;
end;

procedure TCOMWebResponse.SetContent(const Value: string);
begin
  FContent := Value;
  if ContentStream = nil then
    ContentLength := Length(FContent);
end;

procedure TCOMWebResponse.SetDateVariable(Index: Integer; const Value: TDateTime);
begin
  if (Index >= Low(FDateVariables)) and (Index <= High(FDateVariables)) then
    if Value <> FDateVariables[Index] then
      FDateVariables[Index] := Value;
end;

procedure TCOMWebResponse.SetIntegerVariable(Index: Integer; Value: Integer);
begin
  if (Index >= Low(FIntegerVariables)) and (Index <= High(FIntegerVariables)) then
    if Value <> FDateVariables[Index] then
      FIntegerVariables[Index] := Value;
end;

procedure TCOMWebResponse.SetLogMessage(const Value: string);
begin
//  StrPLCopy(TCGIRequest(HTTPRequest).ECB.lpszLogData, Value, HSE_LOG_BUFFER_LEN);
end;

procedure TCOMWebResponse.SetStatusCode(Value: Integer);
begin
  if FStatusCode <> Value then
  begin
    FStatusCode := Value;
    ReasonString := StatusString(Value);
  end;
end;

procedure TCOMWebResponse.SetStringVariable(Index: Integer; const Value: string);
begin
  if (Index >= Low(FStringVariables)) and (Index <= High(FStringVariables)) then
    FStringVariables[Index] := Value;
end;

procedure TCOMWebResponse.SendResponse;
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
    if (ReasonString <> '') and (StatusCode > 0) then
      StatusString := Format('%d %s', [StatusCode, ReasonString])               {do not localize}
    else StatusString := '200 OK';                                              {do not localize}
    AddHeaderItem(Location, 'Location: %s'#13#10);                              {do not localize}
    AddHeaderItem(Allow, 'Allow: %s'#13#10);                                    {do not localize}
    for I := 0 to Cookies.Count - 1 do
      AddHeaderItem(Cookies[I].HeaderValue, 'Set-Cookie: %s'#13#10);            {do not localize}
    AddHeaderItem(DerivedFrom, 'Derived-From: %s'#13#10);                       {do not localize}
    if Expires > 0 then
      AddHeaderItem(Format(FormatDateTime(sDateFormat + ' "GMT"',               {do not localize}
        Expires), [DayOfWeekStr(Expires), MonthStr(Expires)]), 'Expires: %s'#13#10);  {do not localize}

    if LastModified > 0 then
      AddHeaderItem(Format(FormatDateTime(sDateFormat +
        ' "GMT"', LastModified), [DayOfWeekStr(LastModified),                   {do not localize}
        MonthStr(LastModified)]), 'Last-Modified: %s'#13#10);                         {do not localize}
    AddHeaderItem(Title, 'Title: %s'#13#10);                                    {do not localize}
    AddHeaderItem(WWWAuthenticate, 'WWW-Authenticate: %s'#13#10);               {do not localize}
    AddCustomHeaders(Headers);
    AddHeaderItem(ContentVersion, 'Content-Version: %s'#13#10);                 {do not localize}
    AddHeaderItem(ContentEncoding, 'Content-Encoding: %s'#13#10);               {do not localize}
    AddHeaderItem(ContentType, 'Content-Type: %s'#13#10);                       { do not localize }
    if (Content <> '') or (ContentStream <> nil) then
      AddHeaderItem(IntToStr(ContentLength), 'Content-Length: %s'#13#10);       {do not localize}
    Headers := Headers + 'Content:'#13#10#13#10;                                {do not localize}
    HTTPRequest.WriteHeaders(StatusCode, StatusString, Headers);
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

procedure TCOMWebResponse.SendRedirect(const URI: string);
begin
  Location := URI;
  StatusCode := 302;
  ContentType := 'text/html';  {do not localize}
  Content := Format(sDocumentMoved, [URI]);
  SendResponse;
end;

procedure TCOMWebResponse.SendStream(AStream: TStream);
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

{ TComWebRequestHandler }

procedure TComWebRequestHandler.HandleServerException(E: Exception; ARequest: IWebRequest);
var
  ResultText, ResultHeaders, StatusString: string;
begin
  ResultText := Format(sInternalServerError, [E.ClassName, E.Message]);
  StatusString := Format('500 %s', [E.Message]);  {do not localize}
  ResultHeaders := Format(
    'Status: 500'#13#10+                  { do not localize }
    'Content-Type: text/html'#13#10 +     { do not localize }
    'Content-Length: %d'#13#10 +          { do not localize }
    'Content:'#13#10#13#10, [Length(ResultText)]); { do not localize }
  ARequest.WriteHeaders(500, StringToVariantArray(StatusString),
    StringToVariantArray(ResultHeaders));
  ARequest.WriteClient(StringToVariantArray(ResultText));
  { COM web modules don't have a way to mark as sent }
  // ARequest.Sent;
end;

function TComWebRequestHandler.NewRequest(ARequest: IWebRequest): TCOMWebRequest;
begin
  Result := TCOMWebRequest.Create(ARequest);
end;

procedure TComWebRequestHandler.Run(
  ARequest: IWebRequest);
var
  HTTPRequest: TCOMWebRequest;
  HTTPResponse: TCOMWebResponse;
begin
  try
    HTTPRequest := NewRequest(ARequest);
    try
      HTTPResponse := NewResponse(HTTPRequest);
      try
        HandleRequest(HTTPRequest, HTTPResponse);
      finally
        HTTPResponse.Free;
      end;
    finally
      HTTPRequest.Free;
    end;
  except
    HandleServerException(Exception(ExceptObject), ARequest);
  end;
end;

function TComWebRequestHandler.NewResponse(COMWebRequest: TCOMWebRequest): TCOMWebResponse;
begin
  Result := TCOMWebResponse.Create(COMWebRequest)
end;

function TCOMWebRequest.GetInternalPathInfo: string;
var
  P: Integer;
begin
  if UsingStub then
  begin
    Result := PathInfo;
    Assert(Length(Result) > 0, 'Unexpected length');  { do not localize }
    Assert(Result[1] = '/', 'Unexpected value');      { do not localize }
    Delete(Result, 1, 1);
    // Remove first section of path.  This is a reference
    // to the COM object.
    P := Pos('/', Result);   {do not localize}
    if P > 0 then
      Delete(Result, 1, P-1)
    else
      Result := '/';
  end
  else
    Result := inherited GetInternalPathInfo;
end;

function TCOMWebRequest.UsingStub: Boolean;
begin
  Result := FIntf.UsingStub;
end;

function TCOMWebRequest.GetInternalScriptName: string;
var
  P: Integer;
  ComApp: string;
begin
  if UsingStub then
  begin
    ComApp := PathInfo;
    Assert(Length(ComApp) > 0, 'Unexpected length');  { do not localize }
    Assert(ComApp[1] = '/', 'Unexpected value');      { do not localize }
    Delete(ComApp, 1, 1);
    // Remove the trailing section of the path.
    P := Pos('/', ComApp);  {do not localize}
    if P > 0 then
      Delete(ComApp, P, MaxInt);
    Result := ScriptName + '/' + ComApp; {do not localize}
  end
  else
    Result := inherited GetInternalScriptName;
end;

constructor TComWebRequestHandler.Create(AOwner: TComponent);
begin
  inherited;
  Classes.ApplicationHandleException := HandleException;
end;

destructor TComWebRequestHandler.Destroy;
begin
  Classes.ApplicationHandleException := nil;
  inherited;
end;

procedure TComWebRequestHandler.HandleException(Sender: TObject);
var
  Handled: Boolean;
  Intf: IWebExceptionHandler;
  E: TObject;
begin
  Handled := False;
  if (ExceptObject is Exception) and
    not (ExceptObject is EAbort) and
    Supports(Sender, IWebExceptionHandler, Intf) then
      Intf.HandleException(Exception(ExceptObject), Handled);
  if not Handled then
  begin
    E := ExceptObject;
    AcquireExceptionObject;
    raise E;
  end;
end;

end.

