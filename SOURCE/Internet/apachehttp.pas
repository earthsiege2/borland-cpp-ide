{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


unit ApacheHTTP;

interface

uses Classes, HTTPD, HTTPApp;

type
  TApacheRequest = class(TWebRequest)
  private
    FContent: string;
    FContentType: string;
    FRequest_rec: Prequest_rec;
  protected
    function GetStringVariable(Index: Integer): string; override;
    function GetDateVariable(Index: Integer): TDateTime; override;
    function GetIntegerVariable(Index: Integer): Integer; override;
  public
    constructor Create(var r: request_rec);
    function GetFieldByName(const Name: string): string; override;
    function ReadClient(var Buffer; Count: Integer): Integer; override;
    function ReadString(Count: Integer): string; override;
    function TranslateURI(const URI: string): string; override;
    function WriteClient(var Buffer; Count: Integer): Integer; override;
    function WriteString(const AString: string): Boolean; override;
    function WriteHeaders(StatusCode: Integer; const StatusString, Headers: string): Boolean; override;
  end;

  TApacheResponse = class(TWebResponse)
  private
    FStatusCode: integer;
    FReturnCode: integer;
    FStringVariables: array[0..MAX_STRINGS - 1] of string;
    FIntegerVariables: array[0..MAX_INTEGERS - 1] of Integer;
    FDateVariables: array[0..MAX_DATETIMES - 1] of TDateTime;
    FContent: string;
    FLogMsg: string;
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
    property ReturnCode: integer read FReturnCode write FReturnCode;
  end;

implementation

uses SysUtils, Math;

// TApacheRequest methods

constructor TApacheRequest.Create(var r: request_rec);
begin
  FRequest_rec := @r;
  FContent := '';
  FContentType := FRequest_rec^.content_type;

  // The ancestor's constructor must be called after fRequest_rec is initialized
  inherited Create;
end;

function TApacheRequest.GetFieldByName(const Name: string): string;
begin
  Result := ap_table_get(FRequest_rec^.headers_in, pchar(Name));
end;

function TApacheRequest.GetStringVariable(Index: Integer): string;
const
  MaxChunkSize = 10240;
var
  len, BytesRead, Size: Integer;
  p, buf: pchar;
begin
  case Index of
    0: Result := FRequest_rec^.method;
    1: Result := FRequest_rec^.protocol;
    2: Result := FRequest_rec^.unparsed_uri;
    3: Result := FRequest_rec^.args;
    4: Result := FRequest_rec^.path_info;
    5: Result := FRequest_rec^.filename;
    7: Result := '';       // Request Date
    9: Result := ap_table_get(FRequest_rec^.headers_in, 'From');
    10: Result := FRequest_rec^.hostname;
    12: Result := ap_table_get(FRequest_rec^.headers_in, 'Referer');
    13: Result := ap_table_get(FRequest_rec^.headers_in, 'User-Agent');
    14: Result := FRequest_rec^.content_encoding;
    15: Result := ap_table_get(FRequest_rec^.headers_in, 'Content-Type');
    16: Result := ap_table_get(FRequest_rec^.headers_in, 'Content-Length');
    19: Result := '';      // Expires
    20: Result := ap_table_get(FRequest_rec^.headers_in, 'Title');
    21: Result := FRequest_rec^.connection^.remote_ip;
    22: Result := ap_get_remote_host(FRequest_rec^.connection, FRequest_rec^.per_dir_config, REMOTE_HOST);
    23: begin
          Result := FRequest_rec^.unparsed_uri;
          p := Strscan(pchar(Result), '?');
          if p <> nil then
            len := p - pchar(Result)
          else
            len := length(Result);
          Result := copy(Result, 1, len - length(PathInfo));
        end;
    24: Result := IntToStr(ap_get_server_port(FRequest_rec));
    25: begin
          if FContent = '' then
          begin
            ap_setup_client_block(FRequest_rec, REQUEST_CHUNKED_DECHUNK);
            if ap_should_client_block(FRequest_rec) = 1 then
            begin
              BytesRead := 0;
              SetLength(FContent, ContentLength);
              buf := PChar(FContent);
              Size := ContentLength;
              while BytesRead < ContentLength do
              begin
                len := ap_get_client_block(FRequest_rec, buf, Min(MaxChunkSize, Size));
                if len = 0 then
                  break;
                Inc(BytesRead, len);
                Inc(buf, len);
                Dec(Size, len);
              end;
              SetLength(FContent, BytesRead);
            end;
          end;
          Result := FContent;
        end;
    27: Result := ap_table_get(FRequest_rec^.headers_in, 'Cookie');
   else
      Result := '';
  end;
end;

function TApacheRequest.GetDateVariable(Index: Integer): TDateTime;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  if Value <> '' then
    Result := ParseDate(Value)
  else Result := -1;
end;

function TApacheRequest.GetIntegerVariable(Index: Integer): Integer;
var
  Value: string;
begin
  Value := GetStringVariable(Index);
  if Value <> '' then
    Result := StrToInt(Value)
  else Result := -1;
end;

function TApacheRequest.ReadClient(var Buffer; Count: Integer): Integer;
begin
  // Use content property instead
  Result := -1;
end;

function TApacheRequest.ReadString(Count: Integer): string;
var
  Len: Integer;
begin
  SetLength(Result, Count);
  Len := ReadClient(Pointer(Result)^, Count);
  SetLength(Result, Len);
end;

function TApacheRequest.TranslateURI(const URI: string): string;
begin
  Result := ap_server_root_relative(FRequest_rec^.pool, pchar(URI));
{$IFDEF MSWINDOWS}
  Result := UnixPathToDosPath(Result);
{$ENDIF}
end;

function TApacheRequest.WriteClient(var Buffer; Count: Integer): Integer;
begin
  Result := 0;
  if Count > 0 then
    Result := ap_rwrite(Buffer, Count, FRequest_rec)
end;

function TApacheRequest.WriteString(const AString: string): Boolean;
begin
  Result := true;
  if Astring <> '' then
    Result := ap_rputs(pchar(Astring), FRequest_rec) = length(Astring)
end;

function TApacheRequest.WriteHeaders(StatusCode: Integer; const StatusString, Headers: string): Boolean;
begin
  FRequest_rec.status := StatusCode;
  ap_send_http_header(FRequest_rec);
  Result := true;
end;

// TApacheResponse methods

constructor TApacheResponse.Create(HTTPRequest: TWebRequest);
begin
  inherited Create(HTTPRequest);

  InitResponse;
end;

procedure TApacheResponse.InitResponse;
begin
  if FHTTPRequest.ProtocolVersion = '' then
    Version := '1.0';
  StatusCode := HTTP_OK;
  ReturnCode := AP_OK;
  LastModified := -1;
  Expires := -1;
  Date := -1;
  ContentType := 'text/html';
end;

function TApacheResponse.GetContent: string;
begin
  Result := FContent;
end;

function TApacheResponse.GetDateVariable(Index: Integer): TDateTime;
begin
  if (Index >= Low(FDateVariables)) and (Index <= High(FDateVariables)) then
    Result := FDateVariables[Index]
  else Result := 0.0;
end;

function TApacheResponse.GetIntegerVariable(Index: Integer): Integer;
begin
  if (Index >= Low(FIntegerVariables)) and (Index <= High(FIntegerVariables)) then
    Result := FIntegerVariables[Index]
  else Result := -1;
end;

function TApacheResponse.GetLogMessage: string;
begin
  Result := fLogMsg;
end;

function TApacheResponse.GetStatusCode: Integer;
begin
  result := FStatusCode;
end;

function TApacheResponse.GetStringVariable(Index: Integer): string;
begin
  if (Index >= Low(FStringVariables)) and (Index <= High(FStringVariables)) then
    Result := FStringVariables[Index];
end;

function TApacheResponse.Sent: Boolean;
begin
  Result := FSent;
end;

procedure TApacheResponse.SetContent(const Value: string);
begin
  FContent := Value;
  if ContentStream = nil then
    ContentLength := Length(FContent);
end;

procedure TApacheResponse.SetDateVariable(Index: Integer; const Value: TDateTime);
begin
  if (Index >= Low(FDateVariables)) and (Index <= High(FDateVariables)) then
    if Value <> FDateVariables[Index] then
      FDateVariables[Index] := Value;
end;

procedure TApacheResponse.SetIntegerVariable(Index: Integer; Value: Integer);
begin
  if (Index >= Low(FIntegerVariables)) and (Index <= High(FIntegerVariables)) then
    if Value <> FIntegerVariables[Index] then
      FIntegerVariables[Index] := Value;
end;

procedure TApacheResponse.SetLogMessage(const Value: string);
begin
  FLogMsg := Value;
end;

procedure TApacheResponse.SetStatusCode(Value: Integer);
begin
  if FStatusCode <> Value then
  begin
    FStatusCode := Value;
    ReasonString := StatusString(Value);
  end;
end;

procedure TApacheResponse.SetStringVariable(Index: Integer; const Value: string);
begin
  if (Index >= Low(FStringVariables)) and (Index <= High(FStringVariables)) then
    FStringVariables[Index] := Value;
end;

procedure TApacheResponse.SendResponse;
var
  i: Integer;
  ServerMsg: string;

procedure AddHeaderItem(const Key, Value: string);
begin
  if (Key <> '') and (Value <> '') then
    with TApacheRequest(FHTTPRequest) do
    ap_table_set(FRequest_rec.headers_out, pchar(Key), pchar(Value));
end;

procedure AddCustomHeaders;
var
  i: integer;
  Name: string;
begin
  for i := 0 to FCustomHeaders.Count - 1 do
  begin
    Name := FCustomHeaders.Names[I];
    addHeaderItem(Name, FCustomHeaders.values[Name]);
  end;
end;

begin
  if HTTPRequest.ProtocolVersion <> '' then
  begin
    if StatusCode > 0 then
      ServerMsg := Format('%d %s', [StatusCode, ReasonString]);

    AddHeaderItem('Allow', Allow); {do not localize}

    for I := 0 to Cookies.Count - 1 do
    begin
      if (Cookies[I].HeaderValue <> '') then
        with TApacheRequest(FHTTPRequest) do
          ap_table_add(FRequest_rec.headers_out, pchar('Set-Cookie'), {do not localize}
           PChar(Cookies[I].HeaderValue));
    end;

    AddHeaderItem('Derived-From', DerivedFrom); {do not localize}

    if Expires > 0 then
      AddHeaderItem(Format(FormatDateTime(sDateFormat + ' "GMT"',               {do not localize}
        Expires), [DayOfWeekStr(Expires), MonthStr(Expires)]), 'Expires: %s'#13#10);  {do not localize}

    if LastModified > 0 then
      AddHeaderItem(Format(FormatDateTime(sDateFormat +
        ' "GMT"', LastModified), [DayOfWeekStr(LastModified),                   {do not localize}
        MonthStr(LastModified)]), 'Last-Modified: %s'#13#10);                         {do not localize}

    AddHeaderItem('Title', Title);  {do not localize}
    AddHeaderItem('WWW-Authenticate', WWWAuthenticate); {do not localize}
    AddCustomHeaders;
    AddHeaderItem('Content-Version', ContentVersion); {do not localize}

    if ContentType <> '' then
      TApacheRequest(FHTTPRequest).FRequest_rec.content_type := ap_pstrdup(TApacheRequest(FHTTPRequest).FRequest_rec.pool, pchar(ContentType));

    if ContentEncoding <> '' then
      TApacheRequest(FHTTPRequest).FRequest_rec.content_encoding := ap_pstrdup(TApacheRequest(FHTTPRequest).FRequest_rec.pool, pchar(ContentEncoding));

    if (Content <> '') or (ContentStream <> nil) then
      AddHeaderItem('Content-Length', IntToStr(ContentLength));  {do not localize}

    HTTPRequest.WriteHeaders(StatusCode, ServerMsg, '');
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

procedure TApacheResponse.SendRedirect(const URI: string);
begin
  with TApacheRequest(FHTTPRequest) do
  begin
    ap_table_set(FRequest_rec.headers_out, 'Location', pchar(URI)); {do not localize}
    FStatusCode := REDIRECT;
  end;
  FSent := False;
end;

procedure TApacheResponse.SendStream(AStream: TStream);
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

end.
