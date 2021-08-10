
{*******************************************************}
{                                                       }
{  Borland Delphi Visual Component Library              }
{  ISAPI/NSAPI Web server application components        }
{                                                       }
{  Copyright (c) 1997-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

{$DENYPACKAGEUNIT}

unit ISAPIApp;

interface

uses Windows, SyncObjs, Classes, HTTPApp, WebBroker, IsapiHTTP, Isapi2;

type

  TISAPIFactory = class;

  TISAPIApplication = class(TWebApplication)
  private
    FFactory: TISAPIFactory;
    procedure SetFactory(Value: TISAPIFactory);
    function GetFactory: TISAPIFactory;
    function NewRequest(var AECB: TEXTENSION_CONTROL_BLOCK): TISAPIRequest;
    function NewResponse(ISAPIRequest: TISAPIRequest): TISAPIResponse;
    procedure ISAPIHandleException(Sender: TObject);
  public
    // These are the entry points relayed from the ISAPI DLL imports
    function GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL;
    function HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD;
    function TerminateExtension(dwFlags: DWORD): BOOL;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  TISAPIFactory = class(TObject)
  private
    FApplication: TISAPIApplication;
  protected
    function NewRequest(var AECB: TEXTENSION_CONTROL_BLOCK): TISAPIRequest; virtual;
    function NewResponse(ISAPIRequest: TISAPIRequest): TISAPIResponse; virtual;
  public
    constructor Create;
  end;

function GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL; stdcall;
function HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD; stdcall;
function TerminateExtension(dwFlags: DWORD): BOOL; stdcall;

var
  DispatchThread: function (AECB: PEXTENSION_CONTROL_BLOCK): Boolean of object;

implementation

uses SysUtils, BrkrConst;

{ TISAPIApplication }

procedure HandleServerException(E: TObject; var ECB: TEXTENSION_CONTROL_BLOCK);
var
  ResultText, ResultHeaders: string;
  Size: DWORD;
  EMsg: string;
begin
  ECB.dwHTTPStatusCode := 500;
  if E is Exception then
    EMsg := Exception(E).Message
  else
    EMsg := '';
  ResultText := Format(sInternalServerError, [E.ClassName, EMsg]);
  ResultHeaders := Format(
    'Content-Type: text/html'#13#10 +     { do not localize }
    'Content-Length: %d'#13#10 +          { do not localize }
    'Content:'#13#10#13#10, [Length(ResultText)]); { do not localize }
  ECB.ServerSupportFunction(ECB.ConnID, HSE_REQ_SEND_RESPONSE_HEADER,
    PChar('500 ' + EMsg), @Size, LPDWORD(ResultHeaders));
  Size := Length(ResultText);
  ECB.WriteClient(ECB.ConnID, Pointer(ResultText), Size, 0);
end;

function TISAPIApplication.GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL;
begin
  try
    Ver.dwExtensionVersion := MakeLong(HSE_VERSION_MINOR, HSE_VERSION_MAJOR);
    StrLCopy(Ver.lpszExtensionDesc, PChar(Title), HSE_MAX_EXT_DLL_NAME_LEN);
    Integer(Result) := 1; // This is so that the Apache web server will know what "True" really is
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
    HandleServerException(ExceptObject, ECB);
    Result := HSE_STATUS_ERROR;
  end;
end;

function TISAPIApplication.NewRequest(var AECB: TEXTENSION_CONTROL_BLOCK): TISAPIRequest;
begin
  Result := GetFactory.NewRequest(AECB);
end;

function TISAPIApplication.NewResponse(ISAPIRequest: TISAPIRequest): TISAPIResponse;
begin
  Result := GetFactory.NewResponse(ISAPIRequest);
end;

procedure TISAPIApplication.SetFactory(Value: TISAPIFactory);
begin
  Assert(FFactory = nil, 'Duplication ISAPIFactory');  { do not localize }
  FFactory := Value;
end;

function TISAPIApplication.GetFactory: TISAPIFactory;
begin
  if not Assigned(FFactory) then
    FFactory := TISAPIFactory.Create;
  Result := FFactory;
end;

function TISAPIApplication.TerminateExtension(dwFlags: DWORD): BOOL;
begin
  Integer(Result) := 1; // This is so that the Apache web server will know what "True" really is
end;

// ISAPI interface

function GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL;
begin
  Result := (Application as TISAPIApplication).GetExtensionVersion(Ver);
end;

function HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD;
begin
  if Assigned(DispatchThread) then 
  begin
    if DispatchThread(@ECB) then
      Result := HSE_STATUS_PENDING
    else
      Result := HSE_STATUS_ERROR;
  end
  else
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
  try
    Application.Free;
    Application := nil;
  except
    on E:Exception do
      if Assigned(HandleShutdownException) then
      begin
        Application := nil;  // Application of no use at this point so clear it
        Classes.ApplicationHandleException := nil;
        HandleShutdownException(E);
      end;
  end;
end;
                      
procedure TISAPIApplication.ISAPIHandleException(Sender: TObject);
var
  Handled: Boolean;
  Intf: IWebExceptionHandler;
  E: TObject;
begin
  Handled := False;
  if (ExceptObject is Exception) and
      Supports(Sender, IWebExceptionHandler, Intf) then
    Intf.HandleException(Exception(ExceptObject), Handled);
  if not Handled then
  begin
    E := ExceptObject;
    AcquireExceptionObject;
    raise E;
  end;
end;

constructor TISAPIApplication.Create(AOwner: TComponent);
begin
  FFactory := nil;
  inherited;
end;

destructor TISAPIApplication.Destroy;
begin
  if Assigned(FFactory) then  
    FreeAndNil(FFactory);
  inherited;
end;

{ TISAPIFactory }

constructor TISAPIFactory.Create;
begin
  inherited;
  FApplication := Application as TISAPIApplication;
  FApplication.SetFactory(Self);

  Classes.ApplicationHandleException := TISAPIApplication(FApplication).ISAPIHandleException;
end;

function TISAPIFactory.NewRequest(var AECB: TEXTENSION_CONTROL_BLOCK): TISAPIRequest;
begin
  Result := TISAPIRequest.Create(@AECB);
end;

function TISAPIFactory.NewResponse(ISAPIRequest: TISAPIRequest): TISAPIResponse;
begin
  Result := TISAPIResponse.Create(ISAPIRequest);
end;

initialization
  InitApplication;
  AddExitProc(DoneApplication);
end.
