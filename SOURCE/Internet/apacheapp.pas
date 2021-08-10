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


unit ApacheApp;

interface

uses SysUtils, Classes, HTTPD, ApacheHTTP, HTTPApp, WebBroker;

type
  { TApacheApplication }

  TApacheFactory = class;

  TApacheRequestEvent = function (Req: Prequest_rec): integer;
  TApacheInitEvent = procedure (Server: PServer_rec; Pool: Ppool);
  TApacheCreateDirConfigEvent = function (Pool: Ppool; szDir: pchar): pointer;
  TApacheCreateSvrConfigEvent = function (Pool: Ppool; Server: Pserver_rec): pointer;
  TApacheMergeConfigEvent = function (Pool: Ppool; BaseConf, NewConf: pointer): pointer;

  TApacheApplication = class(TWebApplication)
  private
    FFactory: TApacheFactory;

    procedure SetFactory(Value: TApacheFactory);
    function GetFactory: TApacheFactory;
    procedure ApacheHandleException(Sender: TObject);

  protected
    function NewRequest(var r: request_rec): TApacheRequest;
    function NewResponse(ApacheRequest: TApacheRequest): TApacheResponse;

  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Initialize; override;
    function ProcessRequest(var r: request_rec): ap_int;
  end;

  TApacheFactory = class(TObject)
  private
    FApplication: TApacheApplication;

  protected
    function NewRequest(var r: request_rec): TApacheRequest; virtual;
    function NewResponse(ApacheRequest: TApacheRequest): TApacheResponse; virtual;

  public
    constructor Create;
  end;

function apache_handlers(r: Prequest_rec): integer; cdecl; export;
procedure set_module(defModule: Pmodule);

var
  // Default content-typehandler is "<modulename>-content"
  ContentType: array [0..255] of char;
  default_handler: array [0..1] of handler_rec
                = ((content_type: ContentType; handler: apache_handlers),
                   (content_type: nil; handler: nil));

  request_handlers: phandler_rec = @default_handler;
  apache_module: module;
  {$EXTERNALSYM apache_module}

  ApacheOnInit: TApacheInitEvent = nil;
  ApacheOnChildInit: TApacheInitEvent = nil;
  ApacheOnChildExit: TApacheInitEvent = nil;
  ApacheOnCreateDirConfig: TApacheCreateDirConfigEvent = nil;
  ApacheOnMergeDirConfig: TApacheMergeConfigEvent = nil;
  ApacheOnCreateServerConfig: TApacheCreateSvrConfigEvent = nil;
  ApacheOnMergeServerConfig: TApacheMergeConfigEvent = nil;
  ApacheOnLogger: TApacheRequestEvent = nil;
  ApacheOnFixUps: TApacheRequestEvent = nil;
  ApacheOnTypeChecker: TApacheRequestEvent = nil;
  ApacheOnAuthChecker: TApacheRequestEvent = nil;
  ApacheOnCheckUserId: TApacheRequestEvent = nil;
  ApacheOnHeaderParser: TApacheRequestEvent = nil;
  ApacheOnAccessChecker: TApacheRequestEvent = nil;
  ApacheOnPostReadRequest: TApacheRequestEvent = nil;
  ApacheOnTranslateHandler: TApacheRequestEvent = nil;

var
  ModuleName: array[0..255] of char;

implementation

uses
{$IFDEF MSWINDOWS}
  Windows,
{$ENDIF}
  BrkrConst;

var
  default_module_ptr: Pmodule;  

// Helper functions

procedure set_module(defModule: Pmodule);
begin
  default_module_ptr := defModule;
end;

function GetContentType: string;
var
  p1, p2: pchar;
begin
{$IFDEF MSWINDOWS}
  p1 := strrscan(ModuleName, '\');               {do not localize}
{$ENDIF}
{$IFDEF LINUX}
  p1 := strrscan(ModuleName, '/');               {do not localize}
{$ENDIF}
  if p1 <> nil then p1 := p1 + 1
  else p1 := ModuleName;
  p2 := strrscan(ModuleName, '.');               {do not localize}
  if p2 = nil then p2 := p1 + strlen(p1);
  SetString(result, p1, p2 - p1);
  result := LowerCase(result) + '-handler';      {do not localize}
end;

// Apache dispatch interface

function apache_handlers(r: Prequest_rec): integer; cdecl; export;
begin
  result := (Application as TApacheApplication).ProcessRequest(r^);
end;

procedure apache_init(server: Pserver_rec; pool: Ppool); cdecl; export;
begin
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnInit) then
    ApacheOnInit(server, pool);
end;

procedure apache_child_init(Server: Pserver_rec; Pool: Ppool); cdecl; export;
begin
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnChildInit) then
    ApacheOnChildInit(server, pool);
end;

procedure apache_child_exit(server: Pserver_rec; pool: Ppool); cdecl; export;
begin
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnChildExit) then
    ApacheOnChildExit(server, pool);
end;

function apache_create_dir_config(pool: Ppool; szDir: pchar): pointer; cdecl; export;
begin
  result := nil;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnCreateDirConfig) then
    result := ApacheOnCreateDirConfig(pool, szDir);
end;

function apache_merge_dir_config(pool: Ppool; base_conf, new_conf: pointer): pointer; cdecl; export;
begin
  result := base_conf;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnMergeDirConfig) then
    result := ApacheOnMergeDirConfig(pool, base_conf, new_conf);
end;

function apache_create_server_config(pool: Ppool; server: Pserver_rec): pointer; cdecl; export;
begin
  result := server;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnCreateServerConfig) then
    result := ApacheOnCreateServerConfig(pool, server);
end;

function apache_merge_server_config(pool: Ppool; base_conf, new_conf: pointer): pointer; cdecl; export;
begin
  result := base_conf;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnMergeServerConfig) then
    result := ApacheOnMergeServerConfig(pool, base_conf, new_conf);
end;

function apache_logger(r: Prequest_rec): integer; cdecl; export;
begin
  result := 0;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnLogger) then
    result := ApacheOnLogger(r);
end;

function apache_fixer_upper(r: Prequest_rec): integer; cdecl; export;
begin
  result := 0;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnFixUps) then
    result := ApacheOnFixUps(r);
end;

function apache_type_checker(r: Prequest_rec): integer; cdecl; export;
begin
  result := 0;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnTypeChecker) then
    result := ApacheOnTypeChecker(r);
end;

function apache_auth_checker(r: Prequest_rec): integer; cdecl; export;
begin
  result := 0;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnAuthChecker) then
    result := ApacheOnAuthChecker(r);
end;

function apache_check_user_id(r: Prequest_rec): integer; cdecl; export;
begin
  result := 0;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnCheckUserId) then
    result := ApacheOnCheckUserId(r);
end;

function apache_header_parser(r: Prequest_rec): integer; cdecl; export;
begin
  result := 0;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnHeaderParser) then
    result := ApacheOnHeaderParser(r);
end;

function apache_access_checker(r: Prequest_rec): integer; cdecl; export;
begin
  result := 0;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnAccessChecker) then
    result := ApacheOnAccessChecker(r);
end;

function apache_post_read_request(r: Prequest_rec): integer; cdecl; export;
begin
  result := 0;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnPostReadRequest) then
    result := ApacheOnPostReadRequest(r);
end;

function apache_translate_handler(r: Prequest_rec): integer; cdecl; export;
begin
  result := 0;
  with (Application as TApacheApplication) do
  if Assigned(ApacheOnTranslateHandler) then
    result := ApacheOnTranslateHandler(r);
end;

// TApacheApplication

procedure HandleServerException(E: TObject; var r: request_rec);
var
  ErrorMessage, EMsg: string;
begin
  if E is Exception then
    EMsg := Exception(E).Message
  else
    EMsg := '';
  ErrorMessage := Format(sInternalServerError, [E.ClassName, EMsg]);
  r.content_type := 'text/html';
  ap_table_set(r.headers_out, 'Content-Length', pchar(IntToStr(Length(ErrorMessage))));
  ap_send_http_header(@r);
  ap_rputs(pchar(ErrorMessage), @r);
end;

constructor TApacheApplication.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);

  Classes.ApplicationHandleException := ApacheHandleException;
  FFactory := nil;
end;

destructor TApacheApplication.Destroy;
begin
  Classes.ApplicationHandleException := nil;

  inherited Destroy;
end;

procedure TApacheApplication.Initialize;
begin
  { NOTE: Use the pointer and not the apache_module instance directly to
          allow another module to be set (C++Builder uses that technique) }
  with default_module_ptr^ do
  begin
    // STANDARD_MODULE_STUFF
    // must appear in all module records.
    version := MODULE_MAGIC_NUMBER_MAJOR;
    minor_version := MODULE_MAGIC_NUMBER_MINOR;
    module_index := -1;
    name := ModuleName;
    dynamic_load_handle := nil;
    next := nil;
    magic := MODULE_MAGIC_COOKIE;
    cmds := nil;
    handlers := request_handlers;

    if Assigned(ApacheOnInit) then
      init := apache_init
    else init := nil;

    if Assigned(ApacheOnCreateDirConfig) then
      create_dir_config := apache_create_dir_config
    else create_dir_config := nil;

    if Assigned(ApacheOnMergeDirConfig) then
      merge_dir_config := apache_merge_dir_config
    else merge_dir_config := nil;

    if Assigned(ApacheOnCreateServerConfig) then
      create_server_config := apache_create_server_config
    else create_server_config := nil;

    if Assigned(ApacheOnMergeServerConfig) then
      merge_server_config := apache_merge_server_config
    else merge_server_config := nil;

    if Assigned(ApacheOnTranslateHandler) then
      translate_handler := apache_translate_handler
    else translate_handler := nil;

    if Assigned(ApacheOnCheckUserId) then
      ap_check_user_id := apache_check_user_id
    else ap_check_user_id := nil;

    if Assigned(ApacheOnAuthChecker) then
      auth_checker := apache_auth_checker
    else auth_checker := nil;

    if Assigned(ApacheOnAccessChecker) then
      access_checker := apache_access_checker
    else access_checker := nil;

    if Assigned(ApacheOnTypeChecker) then
      type_checker := apache_type_checker
    else type_checker := nil;

    if Assigned(ApacheOnFixUps) then
      fixer_upper := apache_fixer_upper
    else fixer_upper := nil;

    if Assigned(ApacheOnLogger) then
      logger := apache_logger
    else logger := nil;

    if Assigned(ApacheOnHeaderParser) then
      header_parser := apache_header_parser
    else header_parser := nil;

    if Assigned(ApacheOnChildInit) then
      child_init := apache_child_init
    else child_init := nil;

    if Assigned(ApacheOnChildExit) then
      child_exit := apache_child_exit
    else child_exit := nil;

    if Assigned(ApacheOnPostReadRequest) then
      post_read_request := apache_post_read_request
    else post_read_request := nil;
  end;
end;

function TApacheApplication.ProcessRequest(var r: request_rec): ap_int;
var
  HTTPRequest: TApacheRequest;
  HTTPResponse: TApacheResponse;
begin
  try
    HTTPRequest := NewRequest(r);
    try
      HTTPResponse := NewResponse(HTTPRequest);
      try
        { NOTE: Most exceptions will be handled in the except clause below.
                or via a handler }
        HandleRequest(HTTPRequest, HTTPResponse);
        Result := HTTPResponse.ReturnCode;  { Typically will be AP_OK }
      finally
        HTTPResponse.Free;
      end;
    finally
      HTTPRequest.Free;
    end;
  except
    HandleServerException(ExceptObject, r);
    { NOTE: Tell Apache we've handled this request; so there's no need to
            pass this on to other modules }
    Result := AP_OK;
  end;
end;

procedure TApacheApplication.ApacheHandleException(Sender: TObject);
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


procedure TApacheApplication.SetFactory(Value: TApacheFactory);
begin
  Assert(FFactory = nil, 'Duplication ApacheFactory');
  FFactory := Value;
end;

function TApacheApplication.GetFactory: TApacheFactory;
begin
  if not Assigned(FFactory) then
    FFactory := TApacheFactory.Create;
  Result := FFactory;
end;

function TApacheApplication.NewRequest(var r: request_rec): TApacheRequest;
begin
  Result := GetFactory.NewRequest(r);
end;

function TApacheApplication.NewResponse(ApacheRequest: TApacheRequest): TApacheResponse;
begin
  Result := GetFactory.NewResponse(ApacheRequest);
end;

// TApacheFactory

constructor TApacheFactory.Create;
begin
  inherited Create;

  FApplication := Application as TApacheApplication;
  FApplication.SetFactory(Self);
end;

function TApacheFactory.NewRequest(var r: request_rec): TApacheRequest;
begin
  Result := TApacheRequest.Create(r);
end;

function TApacheFactory.NewResponse(ApacheRequest: TApacheRequest): TApacheResponse;
begin
  Result := TApacheResponse.Create(ApacheRequest);
end;

procedure InitApplication;
begin
  set_module(@apache_module);
  Application := TApacheApplication.Create(nil);
  GetModuleFileName(HInstance, ModuleName, SizeOf(ModuleName));
  StrLCopy(ContentType, pchar(GetContentType), sizeof(ContentType) - 1);
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

initialization
  InitApplication;
  AddExitProc(DoneApplication);
end.
