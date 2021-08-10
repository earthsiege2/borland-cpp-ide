
{*******************************************************}
{                                                       }
{    Borland Delphi Visual Component Library            }
{    CGI/WinCGI Web server application components       }
{                                                       }
{ Copyright (c) 1997,2001 Borland Software Corporation  }
{                                                       }
{*******************************************************}

unit CGIStubApp;

{$DENYPACKAGEUNIT}

interface

uses Windows, Classes, CGIHTTP, HTTPApp, WebBroker, IniFiles;

type
  TCGIStubRequest = class(TCGIRequest)
  public
    function TranslateURI(const URI: string): string; override;
  end;

  TCGIStubResponse = class(TCGIResponse)
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
    procedure InitResponse; override;
  public
    procedure SendResponse; override;
    procedure SendRedirect(const URI: string); override;
    procedure SendStream(AStream: TStream); override;
  end;

  TWinCGIStubRequest = class(TWinCGIRequest)
  public
    function ReadString(Count: Integer): string; override;
    function TranslateURI(const URI: string): string; override;
    function WriteString(const AString: string): Boolean; override;
  end;

  TWinCGIStubResponse = class(TCGIStubResponse);

implementation

uses SysUtils, BrkrConst, CGIApp;

type
  TCGIStubFactory = class(TCGIFactory)
  protected
    function NewRequest: TCGIRequest; override;
    function NewResponse(CGIRequest: TCGIRequest): TCGIResponse; override;
  end;

{ TCGIStubRequest }


function TCGIStubRequest.TranslateURI(const URI: string): string;
begin
  Assert(False, 'Unexpected call');
end;

{ TCGIResponse }

function TCGIStubResponse.GetContent: string;
begin
  Assert(False, 'Unexpected call');
end;

function TCGIStubResponse.GetDateVariable(Index: Integer): TDateTime;
begin
  Assert(False, 'Unexpected call');
  Result := Now;
end;

function TCGIStubResponse.GetIntegerVariable(Index: Integer): Integer;
begin
  Assert(False, 'Unexpected call');
  Result := 0;
end;

function TCGIStubResponse.GetLogMessage: string;
begin
//  Result := TCGIRequest(HTTPRequest).ECB.lpszLogData;
end;

function TCGIStubResponse.GetStatusCode: Integer;
begin
  Assert(False, 'Unexpected call');
  Result := 0;
end;

function TCGIStubResponse.GetStringVariable(Index: Integer): string;
begin
  Assert(False, 'Unexpected call');
end;

procedure TCGIStubResponse.SetContent(const Value: string);
begin
  Assert(False, 'Unexpected call');
end;

procedure TCGIStubResponse.SetDateVariable(Index: Integer; const Value: TDateTime);
begin
  Assert(False, 'Unexpected call');
end;

procedure TCGIStubResponse.SetIntegerVariable(Index: Integer; Value: Integer);
begin
  Assert(False, 'Unexpected call');
end;

procedure TCGIStubResponse.SetLogMessage(const Value: string);
begin
//  StrPLCopy(TCGIRequest(HTTPRequest).ECB.lpszLogData, Value, HSE_LOG_BUFFER_LEN);
end;

procedure TCGIStubResponse.SetStatusCode(Value: Integer);
begin
  Assert(False, 'Unexpected call');
end;

procedure TCGIStubResponse.SetStringVariable(Index: Integer; const Value: string);
begin
  Assert(False, 'Unexpected call');
end;

procedure TCGIStubResponse.SendResponse;
begin
  // Ignore SendResponse, COM object is responsible for
  // formatting headers and content into HTTP response
  // This method will be called because the FSent instance
  // variable is not being set.
end;

procedure TCGIStubResponse.SendRedirect(const URI: string);
begin
  Assert(False, 'Unexpected call');
end;

procedure TCGIStubResponse.SendStream(AStream: TStream);
begin
  Assert(False, 'Unexpected call');
end;


{ TWinCGIStubRequest }

function TWinCGIStubRequest.ReadString(Count: Integer): string;
begin
  Assert(False, 'Unexpected call');
end;

function TWinCGIStubRequest.TranslateURI(const URI: string): string;
begin
  Assert(False, 'Unexpected call');
end;

function TWinCGIStubRequest.WriteString(const AString: string): Boolean;
begin
  if AString <> '' then
    Result := WriteClient(Pointer(AString)^, Length(AString)) = Length(AString)
  else Result := False;
end;

procedure TCGIStubResponse.InitResponse;
begin
  // Do not initialize properties
end;

{ TCGIStubFactory }

function TCGIStubFactory.NewRequest: TCGIRequest;
var
  Buffer: array[0..MAX_PATH] of Char;
  S: string;
begin
  if IsConsole then
    Result := TCGIStubRequest.Create
  else
  begin
    Result := TWinCGIStubRequest.Create(ParamStr(1), ParamStr(2), ParamStr(3));
    OutputFileName := ParamStr(3);
    if OutputFileName = '' then
    begin
      SetString(S, Buffer, GetPrivateProfileString('System',              {do not localize}
        'Output File', '', Buffer, SizeOf(Buffer), PChar(ParamStr(1))));  {do not localize}
      OutputFileName := S;
    end;
  end;
end;

function TCGIStubFactory.NewResponse(
  CGIRequest: TCGIRequest): TCGIResponse;
begin
  if IsConsole then
    Result := TCGIStubResponse.Create(CGIRequest)
  else Result := TWinCGIStubResponse.Create(CGIRequest);
end;

initialization
  TCGIStubFactory.Create;
end.

