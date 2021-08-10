{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 1997, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


unit CGIHTTP;

interface

{$IFDEF MSWINDOWS}
uses Windows, Classes, HTTPApp, WebBroker, IniFiles;
{$ENDIF}
{$IFDEF LINUX}
uses Libc, Classes, HTTPApp, WebBroker, IniFiles;
{$ENDIF}

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
    function WriteHeaders(StatusCode: Integer; const StatusString, Headers: string): Boolean; override;
  end;

  TCGIRequestClass = class of TCGIRequest;

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
    procedure InitResponse; virtual;
  public
    constructor Create(HTTPRequest: TWebRequest);
    procedure SendResponse; override;
    procedure SendRedirect(const URI: string); override;
    procedure SendStream(AStream: TStream); override;
    function Sent: Boolean; override;
  end;

  TCGIResponseClass = class of TCGIResponse;

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
    function WriteClient(var Buffer; Count: Integer): Integer; override;
    function WriteString(const AString: string): Boolean; override;
  end;

  TWinCGIRequestClass = class of TWinCGIRequest;

  TWinCGIResponse = class(TCGIResponse);

  TWinCGIResponseClass = class of TWinCGIResponse;

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

  function AdjustHTTP(const Name: string): string;
  const
    SHttp = 'HTTP_';     { do not localize }
  begin
    if Pos(SHttp, Name) = 1 then
      Result := Copy(Name, 6, MaxInt)
    else 
      Result := SHttp + Name;
  end;

begin
  Result := GetEnvironmentVariable(Name);
  if Result = '' then
    Result := GetEnvironmentVariable(AdjustHTTP(Name));
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
var
  ReadNow, Size: Integer;
  Buffer: PChar;
begin
  SetLength(Result, Count);
  if Count > 0 then
  begin
    Size := Count;
    Buffer := PChar(Result);
    while Size > 0 do
    begin
      ReadNow := FileRead(TTextRec(Input).Handle, Buffer^, Size);
      if ReadNow = 0 then break;
      Inc(Buffer, ReadNow);
      Dec(Size, ReadNow);
    end;
    SetLength(Result, Count - Size);
  end;
end;

function TCGIRequest.TranslateURI(const URI: string): string;
var
  PathInfo: string;
  PathInfoPos: Integer;
  PathTranslated: string;
begin
  Result := URI;
  PathTranslated := GetStringVariable(5);
  if PathTranslated <> '' then
  begin
    PathInfo := GetStringVariable(4);
    PathInfoPos := Length(PathTranslated) - Length(PathInfo);
    if Copy(PathTranslated, PathInfoPos + 1, Length(PathInfo)) = PathInfo then
      Result := Copy(PathTranslated, 1, PathInfoPos) + URI;
  end;
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

function TCGIRequest.WriteHeaders(StatusCode: Integer; const StatusString,
  Headers: string): Boolean;
begin
  Result := WriteString(Format('Status: %s'#13#10'%s', [StatusString, Headers])); { do not localize }
end;

{ TCGIResponse }

constructor TCGIResponse.Create(HTTPRequest: TWebRequest);
begin
  inherited Create(HTTPRequest);
  InitResponse;
end;

procedure TCGIResponse.InitResponse;
begin
  if FHTTPRequest.ProtocolVersion = '' then
    Version := '1.0';  { do not localize }
  StatusCode := 200;
  LastModified := -1;
  Expires := -1;
  Date := -1;
  ContentType := 'text/html';  { do not localize }
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
  // Service not available
  Result := '';
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
    if Value <> FIntegerVariables[Index] then
      FIntegerVariables[Index] := Value;
end;

procedure TCGIResponse.SetLogMessage(const Value: string);
begin
  // Service not available
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
    else StatusString := '200 OK';                                              {do not localize }
    AddHeaderItem(Location, 'Location: %s'#13#10);                              {do not localize }
    AddHeaderItem(Allow, 'Allow: %s'#13#10);                                    {do not localize }
    for I := 0 to Cookies.Count - 1 do
      AddHeaderItem(Cookies[I].HeaderValue, 'Set-Cookie: %s'#13#10);            {do not localize }
    AddHeaderItem(DerivedFrom, 'Derived-From: %s'#13#10);                       {do not localize }
    if Expires > 0 then
      AddHeaderItem(Format(FormatDateTime(sDateFormat + ' "GMT"',               {do not localize}
        Expires), [DayOfWeekStr(Expires), MonthStr(Expires)]), 'Expires: %s'#13#10);  {do not localize}

    if LastModified > 0 then
      AddHeaderItem(Format(FormatDateTime(sDateFormat +
        ' "GMT"', LastModified), [DayOfWeekStr(LastModified),                   {do not localize}
        MonthStr(LastModified)]), 'Last-Modified: %s'#13#10);                         {do not localize}
    AddHeaderItem(Title, 'Title: %s'#13#10);                                    {do not localize }
    AddHeaderItem(WWWAuthenticate, 'WWW-Authenticate: %s'#13#10);               {do not localize }
    AddCustomHeaders(Headers);
    AddHeaderItem(ContentVersion, 'Content-Version: %s'#13#10);                 {do not localize }
    AddHeaderItem(ContentEncoding, 'Content-Encoding: %s'#13#10);               {do not localize }
    AddHeaderItem(ContentType, 'Content-Type: %s'#13#10);                       {do not localize }
    if (Content <> '') or (ContentStream <> nil) then
      AddHeaderItem(IntToStr(ContentLength), 'Content-Length: %s'#13#10);       {do not localize }
    Headers := Headers + 'Content:'#13#10#13#10;                                {do not localize }
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

procedure TCGIResponse.SendRedirect(const URI: string);
begin
  Location := URI;
  StatusCode := 302;
  ContentType := 'text/html';  { do not localize }
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
  if IniFileName = '' then
    IniFileName := 'WinCGI';   { do not localize }
  FIniFile := TIniFile.Create(IniFileName);
  if ContentFile = '' then
    ContentFile := FIniFile.ReadString('System', 'Content File', 'ContentFile');  { do not localize }
  if OutputFile = '' then
    OutputFile := FIniFile.ReadString('System', 'Output File', 'OutputFile.html'); { do not localize }
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
  Result := FIniFile.ReadString('Extra Headers', Name, '');  { do not localize }
end;

function TWinCGIRequest.GetStringVariable(Index: Integer): string;

  function AcceptSection: string;
  var
    Section: TStringList;
    I: Integer;
  begin
    Section := TStringList.Create;
    try
      FIniFile.ReadSection('Accept', Section);  { do not localize }
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
      Result := FIniFile.ReadString('CGI', WinCGIServerVariables[Index], '');  { do not localize }
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

end.

