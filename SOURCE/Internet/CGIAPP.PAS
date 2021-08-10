
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       CGI/WinCGI Web server application components    }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

{$DENYPACKAGEUNIT}

unit CGIApp;

interface

uses Windows, Classes, HTTPApp, WebBroker, IniFiles;

type
  TCGIRequest = class(TWebRequest)
  private
    FContent: string;
  protected
    function GetStringVariable(Index: Integer): string; override;
    function GetDateVariable(Index: Integer): TDateTime; override;
    function GetIntegerVariable(Index: Integer): Integer; override;
  public
    constructor Create;
    function GetFieldByName(const Name: string): string; override;
    function ReadClient(var Buffer; Count: Integer): Integer; override;
    function ReadString(Count: Integer): string; override;
    function TranslateURI(const URI: string): string; override;
    function WriteClient(var Buffer; Count: Integer): Integer; override;
    function WriteString(const AString: string): Boolean; override;
  end;

  TCGIResponse = class(TWebResponse)
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

  TWinCGIRequest = class(TCGIRequest)
  private
    FIniFile: TIniFile;
    FClientData, FServerData: TFileStream;
  protected
    function GetStringVariable(Index: Integer): string; override;
  public
    constructor Create(IniFileName, ContentFile, OutputFile: string);
    destructor Destroy; override;
    function GetFieldByName(const Name: string): string; override;
    function ReadClient(var Buffer; Count: Integer): Integer; override;
    function ReadString(Count: Integer): string; override;
    function TranslateURI(const URI: string): string; override;
    function WriteClient(var Buffer; Count: Integer): Integer; override;
    function WriteString(const AString: string): Boolean; override;
  end;

  TWinCGIResponse = class(TCGIResponse);

  TCGIApplication = class(TWebApplication)
  private
    FOutputFileName: string;
    function NewRequest: TCGIRequest;
    function NewResponse(CGIRequest: TCGIRequest): TCGIResponse;
  public
    procedure Run; override;
  end;

implementation

uses SysUtils, BrkrConst;

const
  CGIServerVariables: array[0..28] of string = (
    'REQUEST_METHOD',
    'SERVER_PROTOCOL',
    'URL',
    'QUERY_STRING',
    'PATH_INFO',
    'PATH_TRANSLATED',
    'HTTP_CACHE_CONTROL',
    'HTTP_DATE',
    'HTTP_ACCEPT',
    'HTTP_FROM',
    'HTTP_HOST',
    'HTTP_IF_MODIFIED_SINCE',
    'HTTP_REFERER',
    'HTTP_USER_AGENT',
    'HTTP_CONTENT_ENCODING',
    'HTTP_CONTENT_TYPE',
    'HTTP_CONTENT_LENGTH',
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

{ TCGIRequest }

constructor TCGIRequest.Create;
begin
  inherited Create;
  FContent := ReadString(ContentLength);
end;

function TCGIRequest.GetFieldByName(const Name: string): string;
var
  Buffer: array[0..4095] of Char;

  function StripHTTP(const Name: string): string;
  begin
    if Pos('HTTP_', Name) = 1 then
      Result := Copy(Name, 6, MaxInt)
    else Result := Name;
  end;

begin
  SetString(Result, Buffer, GetEnvironmentVariable(PChar(Name), Buffer, SizeOf(Buffer)));
  if Result = '' then
    SetString(Result, Buffer, GetEnvironmentVariable(PChar(StripHTTP(Name)), Buffer, SizeOf(Buffer)));
end;

function TCGIRequest.GetStringVariable(Index: Integer): string;
begin
  if Index = 25 then
    Result := FContent
  else Result := GetFieldByName(CGIServerVariables[Index]);
end;

function TCGIRequest.GetDateVariable(Index: Integer): TDateTime;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  if Value <> '' then
    Result := ParseDate(Value)
  else Result := -1;
end;

function TCGIRequest.GetIntegerVariable(Index: Integer): Integer;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  Result := StrToIntDef(Value, -1)
end;

function TCGIRequest.ReadClient(var Buffer; Count: Integer): Integer;
begin
  Result := FileRead(TTextRec(Input).Handle, Buffer, Count);
end;

function TCGIRequest.ReadString(Count: Integer): string;
begin
  SetLength(Result, Count);
  if Count > 0 then
    SetLength(Result, FileRead(TTextRec(Input).Handle, Pointer(Result)^, Count));
end;

function TCGIRequest.TranslateURI(const URI: string): string;
begin
end;

function TCGIRequest.WriteClient(var Buffer; Count: Integer): Integer;
begin
  Result := FileWrite(TTextRec(Output).Handle, Buffer, Count);
end;

function TCGIRequest.WriteString(const AString: string): Boolean;
begin
  if AString <> '' then
    Result := FileWrite(TTextRec(Output).Handle, Pointer(AString)^, Length(AString)) = Length(AString)
  else Result := False;
end;

{ TCGIResponse }

constructor TCGIResponse.Create(HTTPRequest: TWebRequest);
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

function TCGIResponse.GetContent: string;
begin
  Result := FContent;
end;

function TCGIResponse.GetDateVariable(Index: Integer): TDateTime;
begin
  if (Index >= 0) and (Index < 3) then
    Result := FDateVariables[Index]
  else Result := -1;
end;

function TCGIResponse.GetIntegerVariable(Index: Integer): Integer;
begin
  if (Index >= 0) and (Index < 2) then
    Result := FIntegerVariables[Index]
  else Result := -1;
end;

function TCGIResponse.GetLogMessage: string;
begin
//  Result := TCGIRequest(HTTPRequest).ECB.lpszLogData;
end;

function TCGIResponse.GetStatusCode: Integer;
begin
  Result := FStatusCode;
end;

function TCGIResponse.GetStringVariable(Index: Integer): string;
begin
  if (Index >= 0) and (Index < 12) then
    Result := FStringVariables[Index];
end;

function TCGIResponse.Sent: Boolean;
begin
  Result := FSent;
end;

procedure TCGIResponse.SetContent(const Value: string);
begin
  FContent := Value;
  if ContentStream = nil then
    ContentLength := Length(FContent);
end;

procedure TCGIResponse.SetDateVariable(Index: Integer; const Value: TDateTime);
begin
  if (Index >= Low(FDateVariables)) and (Index <= High(FDateVariables)) then
    if Value <> FDateVariables[Index] then
      FDateVariables[Index] := Value;
end;

procedure TCGIResponse.SetIntegerVariable(Index: Integer; Value: Integer);
begin
  if (Index >= Low(FIntegerVariables)) and (Index <= High(FIntegerVariables)) then
    if Value <> FDateVariables[Index] then
      FIntegerVariables[Index] := Value;
end;

procedure TCGIResponse.SetLogMessage(const Value: string);
begin
//  StrPLCopy(TCGIRequest(HTTPRequest).ECB.lpszLogData, Value, HSE_LOG_BUFFER_LEN);
end;

procedure TCGIResponse.SetStatusCode(Value: Integer);
begin
  if FStatusCode <> Value then
  begin
    FStatusCode := Value;
    ReasonString := StatusString(Value);
  end;
end;

procedure TCGIResponse.SetStringVariable(Index: Integer; const Value: string);
begin
  if (Index >= Low(FStringVariables)) and (Index <= High(FStringVariables)) then
    FStringVariables[Index] := Value;
end;

procedure TCGIResponse.SendResponse;
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
      StatusString := Format('%d %s', [StatusCode, ReasonString])
    else StatusString := '200 OK';
    AddHeaderItem(StatusString, 'Status: %s'#13#10);
    AddHeaderItem(Location, 'Location: %s'#13#10);
    AddHeaderItem(Allow, 'Allow: %s'#13#10);
    for I := 0 to Cookies.Count - 1 do
      AddHeaderItem(Cookies[I].HeaderValue, 'Set-Cookie: %s'#13#10);
    AddHeaderItem(DerivedFrom, 'Derived-From: %s'#13#10);
    if Expires > 0 then
      Format(FormatDateTime('"Expires: "' + sDateFormat + ' "GMT"'#13#10, Expires),
        [DayOfWeekStr(Expires), MonthStr(Expires)]);
    if LastModified > 0 then
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
    HTTPRequest.WriteString(Headers);
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

procedure TCGIResponse.SendRedirect(const URI: string);
begin
  Location := URI;
  StatusCode := 302;
  ContentType := 'text/html';
  Content := Format(sDocumentMoved, [URI]);
  SendResponse;
end;

procedure TCGIResponse.SendStream(AStream: TStream);
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

const
  WinCGIServerVariables: array[0..28] of string = (
    'Request Method',
    'Request Protocol',
    'Url',
    'Query String',
    'Logical Path',
    'Physical Path',
    'Cache Control',
    'Date',
    'Accept',
    'From',
    'Host',
    'If-Modified-Since',
    'Referer',
    'User-Agent',
    'Content-Encoding',
    'Content Type',
    'Content Length',
    'Content Version',
    'Derived-From',
    'Expires',
    'Title',
    'Remote Address',
    'Remote Host',
    'Executable Path',
    'Server Port',
    '',
    'Connection',
    'Cookie',
    'Authorization');

{ TWinCGIRequest }

constructor TWinCGIRequest.Create(IniFileName, ContentFile, OutputFile: string);
begin
  FIniFile := TIniFile.Create(IniFileName);
  if ContentFile = '' then
    ContentFile := FIniFile.ReadString('System', 'Content File', '');
  if OutputFile = '' then
    OutputFile := FIniFile.ReadString('System', 'Output File', '');
  if FileExists(ContentFile) then
    FClientData := TFileStream.Create(ContentFile, fmOpenRead or fmShareDenyNone);
  if FileExists(OutputFile) then
    FServerData := TFileStream.Create(OutputFile, fmOpenWrite or fmShareDenyNone)
  else FServerData := TFileStream.Create(OutputFile, fmCreate);
  inherited Create;
end;

destructor TWinCGIRequest.Destroy;
begin
  FIniFile.Free;
  if FClientData <> nil then
    FClientData.Free;
  FServerData.Free;
  inherited Destroy;
end;

function TWinCGIRequest.GetFieldByName(const Name: string): string;
begin
  Result := FIniFile.ReadString('Extra Headers', Name, '');
end;

function TWinCGIRequest.GetStringVariable(Index: Integer): string;

  function AcceptSection: string;
  var
    Section: TStringList;
    I: Integer;
  begin
    Section := TStringList.Create;
    try
      FIniFile.ReadSection('Accept', Section);
      Result := '';
      for I := 0 to Section.Count - 1 do
        Result := Result + Section[I] + ',';
      if Result <> '' then SetLength(Result, Length(Result) - 1);
    finally
      Section.Free;
    end;
  end;

begin
  case Index of
    0..1,3..5,15..16,
    21..24, 26, 28:
      Result := FIniFile.ReadString('CGI', WinCGIServerVariables[Index], '');
    25: Result := FContent;
    27: Result := FIniFile.ReadString('Extra Headers', WinCGIServerVariables[Index], '');
    8: Result := AcceptSection;
  else
    if (Index >= Low(WinCGIServerVariables)) and (Index <= High(WinCGIServerVariables)) then
      Result := GetFieldByName(WinCGIServerVariables[Index])
    else Result := '';
  end;
end;

function TWinCGIRequest.ReadClient(var Buffer; Count: Integer): Integer;
begin
  if FClientData <> nil then
    Result := FClientData.Read(Buffer, Count)
  else Result := 0;
end;

function TWinCGIRequest.ReadString(Count: Integer): string;
begin
  if (Count > 0) and (FClientData <> nil) then
  begin
    SetLength(Result, Count);
    SetLength(Result, FClientData.Read(Pointer(Result)^, Count));
  end else Result := '';
end;

function TWinCGIRequest.TranslateURI(const URI: string): string;
begin
end;

function TWinCGIRequest.WriteClient(var Buffer; Count: Integer): Integer;
begin
  Result := FServerData.Write(Buffer, Count);
end;

function TWinCGIRequest.WriteString(const AString: string): Boolean;
begin
  if AString <> '' then
    Result := FServerData.Write(Pointer(AString)^, Length(AString)) = Length(AString)
  else Result := False;
end;

{ TCGIApplication }

procedure HandleServerException(E: Exception; const OutputFile: string);
var
  ResultText, ResultHeaders: string;
  OutFile: TStream;
begin
  ResultText := Format(sInternalServerError, [E.ClassName, E.Message]);
  ResultHeaders := Format(
    'Status: 500 %s'#13#10+               //Not resourced
    'Content-Type: text/html'#13#10 +     //Not resourced
    'Content-Length: %d'#13#10 +          //Not resourced
    'Content:'#13#10#13#10, [E.Message, Length(ResultText)]); //Not resourced
  if IsConsole then
  begin
    FileWrite(TTextRec(Output).Handle, Pointer(ResultHeaders)^, Length(ResultHeaders));
    FileWrite(TTextRec(Output).Handle, Pointer(ResultText)^, Length(ResultText));
  end else
  begin
    if FileExists(OutputFile) then
      OutFile := TFileStream.Create(OutputFile, fmOpenWrite or fmShareDenyNone)
    else OutFile := TFileStream.Create(OutputFile, fmCreate);
    try
      OutFile.Write(Pointer(ResultHeaders)^, Length(ResultHeaders));
      OutFile.Write(Pointer(ResultText)^, Length(ResultText));
    finally
      OutFile.Free;
    end;
  end;
end;

function TCGIApplication.NewRequest: TCGIRequest;
var
  Buffer: array[0..MAX_PATH] of Char;
begin
  if IsConsole then
    Result := TCGIRequest.Create
  else
  begin
    Result := TWinCGIRequest.Create(ParamStr(1), ParamStr(2), ParamStr(3));
    FOutputFileName := ParamStr(3);
    if FOutputFileName = '' then
      SetString(FOutputFileName, Buffer, GetPrivateProfileString('System',
        'Output File', '', Buffer, SizeOf(Buffer), PChar(ParamStr(1))));
  end;
end;

function TCGIApplication.NewResponse(CGIRequest: TCGIRequest): TCGIResponse;
begin
  if IsConsole then
    Result := TCGIResponse.Create(CGIRequest)
  else Result := TWinCGIResponse.Create(CGIRequest);
end;

procedure TCGIApplication.Run;
var
  HTTPRequest: TCGIRequest;
  HTTPResponse: TCGIResponse;
begin
  inherited Run;
  if IsConsole then
  begin
    Rewrite(Output);
    Reset(Input);
  end;
  try
    HTTPRequest := NewRequest;
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
    HandleServerException(Exception(ExceptObject), FOutputFileName);
  end;
end;

procedure InitApplication;
begin
  Application := TCGIApplication.Create(nil);
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

