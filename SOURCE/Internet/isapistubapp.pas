
{*******************************************************}
{                                                       }
{   Borland Delphi Visual Component Library             }
{   CGI/WinCGI Web server application components        }
{                                                       }
{  Copyright (c) 1997-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

{$DENYPACKAGEUNIT}

unit IsapiStubApp;

interface

uses Windows, Classes, IsapiHTTP, HTTPApp, WebBroker, IniFiles, Isapi2;

type
  TISAPIStubRequest = class(TISAPIRequest)
  public
    function TranslateURI(const URI: string): string; override;
    function WriteString(const AString: string): Boolean; override;
  end;

  TISAPIStubResponse = class(TISAPIResponse)
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

implementation

uses SysUtils, BrkrConst, ISAPIApp;

type
  TISAPIStubFactory = class(TISAPIFactory)
  protected
    function NewRequest(var AECB: TEXTENSION_CONTROL_BLOCK): TISAPIRequest; override;
    function NewResponse(ISAPIRequest: TISAPIRequest): TISAPIResponse; override;
  end;

{ TISAPIStubRequest }


function TISAPIStubRequest.TranslateURI(const URI: string): string;
begin
  Assert(False, 'Unexpected call');
end;

function TISAPIStubRequest.WriteString(const AString: string): Boolean;
begin
  if AString <> '' then
    Result := WriteClient(Pointer(AString)^, Length(AString)) = Length(AString)
  else Result := False;
end;

{ TISAPIResponse }

function TISAPIStubResponse.GetContent: string;
begin
  Assert(False, 'Unexpected call');
end;

function TISAPIStubResponse.GetDateVariable(Index: Integer): TDateTime;
begin
  Assert(False, 'Unexpected call');
  Result := Now;
end;

function TISAPIStubResponse.GetIntegerVariable(Index: Integer): Integer;
begin
  Assert(False, 'Unexpected call');
  Result := 0;
end;

function TISAPIStubResponse.GetLogMessage: string;
begin
//  Result := TISAPIRequest(HTTPRequest).ECB.lpszLogData;
end;

function TISAPIStubResponse.GetStatusCode: Integer;
begin
  Assert(False, 'Unexpected call');
  Result := 0;
end;

function TISAPIStubResponse.GetStringVariable(Index: Integer): string;
begin
  Assert(False, 'Unexpected call');
end;

procedure TISAPIStubResponse.SetContent(const Value: string);
begin
  Assert(False, 'Unexpected call');
end;

procedure TISAPIStubResponse.SetDateVariable(Index: Integer; const Value: TDateTime);
begin
  Assert(False, 'Unexpected call');
end;

procedure TISAPIStubResponse.SetIntegerVariable(Index: Integer; Value: Integer);
begin
  Assert(False, 'Unexpected call');
end;

procedure TISAPIStubResponse.SetLogMessage(const Value: string);
begin
//  StrPLCopy(TISAPIRequest(HTTPRequest).ECB.lpszLogData, Value, HSE_LOG_BUFFER_LEN);
end;

procedure TISAPIStubResponse.SetStatusCode(Value: Integer);
begin
  Assert(False, 'Unexpected call');
end;

procedure TISAPIStubResponse.SetStringVariable(Index: Integer; const Value: string);
begin
  Assert(False, 'Unexpected call');
end;

procedure TISAPIStubResponse.SendResponse;
begin
  // Ignore SendResponse, COM object is responsible for
  // formatting headers and content into HTTP response
  // This method will be called because the FSent instance
  // variable is not being set.
end;

procedure TISAPIStubResponse.SendRedirect(const URI: string);
begin
  Assert(False, 'Unexpected call');
end;

procedure TISAPIStubResponse.SendStream(AStream: TStream);
begin
  Assert(False, 'Unexpected call');
end;

procedure TISAPIStubResponse.InitResponse;
begin
  // Do not initialize properties.  The
  // COM objects is responsible for setting all
  // response fields.
end;

{ TISAPIStubFactory }

function TISAPIStubFactory.NewRequest(var AECB: TEXTENSION_CONTROL_BLOCK): TISAPIRequest;
begin
  Result := TISAPIStubRequest.Create(@AECB);
end;

function TISAPIStubFactory.NewResponse(
  ISAPIRequest: TISAPIRequest): TISAPIResponse;
begin
  Result := TISAPIStubResponse.Create(ISAPIRequest);
end;

initialization
  TISAPIStubFactory.Create;
end.

