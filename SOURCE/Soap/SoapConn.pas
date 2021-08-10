
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       SOAP client-side invoker                        }
{                                                       }
{       Copyright (c) 2000 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit SOAPConn;

interface

uses
  SysUtils, Variants, Classes, Midas, DBClient, SOAPHTTPTrans, Rio, SOAPHTTPClient, SOAPMidas;

type

  { TSoapConnection }
  TSoapConnection = class(TCustomRemoteServer)
  private
    FRIO: THTTPRIO;
    FURL: string;
    FAppServer: IAppServer;
    FSOAPServer: IAppServerSOAP;
    FUseSOAPAdapter: Boolean;
    FOnAfterExecute: TAfterExecuteEvent;
    FOnBeforeExecute: TBeforeExecuteEvent;
    function GetAgent: string;
    function GetPassword: string;
    function GetProxy: string;
    function GetProxyByPass: string;
    function GetUserName: string;
    procedure SetAgent(const Value: string);
    procedure SetPassword(const Value: string);
    procedure SetProxy(const Value: string);
    procedure SetProxyByPass(const Value: string);
    procedure SetURL(const Value: string);
    procedure SetUserName(const Value: string);
  protected
    procedure DoConnect; override;
    function GetConnected: Boolean; override;
    function GetServerList: OleVariant; override;
    procedure DoDisconnect; override;
    procedure GetProviderNames(Proc: TGetStrProc); override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor  Destroy; override;
    function    GetServer: IAppServer; override;
    function    GetSOAPServer: IAppServerSOAP;
  published
    property Agent: string read GetAgent write SetAgent;
    { Publish standard DataSnap Connection properties}
    property Connected;
    property AfterConnect;
    property BeforeConnect;
    property AfterDisconnect;
    property BeforeDisconnect;
    property Password: string read GetPassword write SetPassword;
    property Proxy: string read GetProxy write SetProxy;
    property ProxyByPass: string read GetProxyByPass write SetProxyByPass;
    property URL: string read FURL write SetURL;
    property UserName: string read GetUserName write SetUserName;
    property UseSOAPAdapter: Boolean read FUseSOAPAdapter write FUseSOAPAdapter;
    property OnAfterExecute: TAfterExecuteEvent read FOnAfterExecute write FOnAfterExecute;
    property OnBeforeExecute: TBeforeExecuteEvent read FOnBeforeExecute write FOnBeforeExecute;
  end;


implementation

uses {$IFDEF MSWINDOWS}Windows{$ENDIF}{$IFDEF LINUX}Libc{$ENDIF}, InvokeRegistry, SOAPConst, Types, ComObj;

type
  TSOAPAppServerAdapter = class(TInterfacedObject, IAppServer)
  private
    FSOAPServer: IAppServerSOAP;
    function SafeCallException(ExceptObject: TObject;
                               ExceptAddr: Pointer): HResult; override;
  public
    constructor Create(const AppServerSOAP: IAppServerSOAP);
    { IAppServer }
    function  AS_ApplyUpdates(const ProviderName: WideString; Delta: OleVariant;
                              MaxErrors: Integer; out ErrorCount: Integer; var OwnerData: OleVariant): OleVariant; safecall;
    function  AS_GetRecords(const ProviderName: WideString; Count: Integer; out RecsOut: Integer;
                            Options: Integer; const CommandText: WideString;
                            var Params: OleVariant; var OwnerData: OleVariant): OleVariant; safecall;
    function  AS_DataRequest(const ProviderName: WideString; Data: OleVariant): OleVariant; safecall;
    function  AS_GetProviderNames: OleVariant; safecall;
    function  AS_GetParams(const ProviderName: WideString; var OwnerData: OleVariant): OleVariant; safecall;
    function  AS_RowRequest(const ProviderName: WideString; Row: OleVariant; RequestType: Integer;
                            var OwnerData: OleVariant): OleVariant; safecall;
    procedure AS_Execute(const ProviderName: WideString; const CommandText: WideString;
                         var Params: OleVariant; var OwnerData: OleVariant); safecall;
    { IDispatch: NOTE Methods of IDispatch are not exposed via SOAP }
    function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
    function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
    function GetIDsOfNames(const IID: TGUID; Names: Pointer;
                           NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
    function Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
                    Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
  end;

constructor TSOAPAppServerAdapter.Create(const AppServerSOAP: IAppServerSOAP);
begin
  inherited Create;
  FSOAPServer := AppServerSOAP;
end;

function TSOAPAppServerAdapter.AS_ApplyUpdates(const ProviderName: WideString; Delta: OleVariant;
                          MaxErrors: Integer; out ErrorCount: Integer; var OwnerData: OleVariant): OleVariant; safecall;
begin
  Result := FSOAPServer.SAS_ApplyUpdates(ProviderName, Delta, MaxErrors, ErrorCount, OwnerData);
end;

function TSOAPAppServerAdapter.AS_GetRecords(const ProviderName: WideString; Count: Integer; out RecsOut: Integer;
                        Options: Integer; const CommandText: WideString;
                        var Params: OleVariant; var OwnerData: OleVariant): OleVariant; safecall;
begin
  Result := FSOAPServer.SAS_GetRecords(ProviderName, Count, RecsOut, Options, CommandText, Params, OwnerData);
end;

function TSOAPAppServerAdapter.AS_DataRequest(const ProviderName: WideString; Data: OleVariant): OleVariant; safecall;
begin
  Result := FSOAPServer.SAS_DataRequest(ProviderName, Data);
end;

function TSOAPAppServerAdapter.AS_GetProviderNames: OleVariant; safecall;
var
  Names: TWideStringDynArray;
  I, Count: Integer;
begin
  VarClear(Result);
  Names := FSOAPServer.SAS_GetProviderNames;
  if Length(Names) > 0 then
  begin
    Count := Length(Names);
    Result := VarArrayCreate([0, Count-1], varVariant);
    for I := 0 to Length(Names)-1 do
      Result[I] := Variant(Names[I]);
  end
end;

function TSOAPAppServerAdapter.AS_GetParams(const ProviderName: WideString; var OwnerData: OleVariant): OleVariant; safecall;
begin
  Result := FSOAPServer.SAS_GetParams(ProviderName, OwnerData);
end;

function TSOAPAppServerAdapter.AS_RowRequest(const ProviderName: WideString; Row: OleVariant; RequestType: Integer;
                        var OwnerData: OleVariant): OleVariant; safecall;
begin
  Result := FSOAPServer.SAS_RowRequest(ProviderName, Row, RequestType, OwnerData);
end;

procedure TSOAPAppServerAdapter.AS_Execute(const ProviderName: WideString; const CommandText: WideString;
                     var Params: OleVariant; var OwnerData: OleVariant); safecall;
begin
  FSOAPServer.SAS_Execute(ProviderName, CommandText, Params, OwnerData);
end;

function TSOAPAppServerAdapter.GetTypeInfoCount(out Count: Integer): HResult; stdcall;
begin
  Result := E_NOTIMPL;
end;

function TSOAPAppServerAdapter.GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
begin
  Result := E_NOTIMPL;
end;

function TSOAPAppServerAdapter.GetIDsOfNames(const IID: TGUID; Names: Pointer;
  NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
begin
  Result := E_NOTIMPL;
end;

function TSOAPAppServerAdapter.Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
  Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
begin
  Result := E_NOTIMPL;
end;

function TSOAPAppServerAdapter.SafeCallException(ExceptObject: TObject;
                                                 ExceptAddr: Pointer): HResult;
begin
  Result := HandleSafeCallException(ExceptObject, ExceptAddr, IAppServer, '', '');
end;



{ TSoapConnection }
constructor TSoapConnection.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  { FUseSOAPAdapter should be disabled when talking to SOAP
    Services that only expose IAppServer - i.e. Delphi/6 &
    Kylix/2 servers - until these are updated }
  FUseSOAPAdapter := True;
end;

destructor TSoapConnection.Destroy;
begin
  inherited;
end;

procedure TSoapConnection.DoDisconnect;
begin
  inherited;
  { Clean link to remote SOAP Server }
  FAppServer := nil;
  FSOAPServer := nil;
  if Assigned(FRIO) then
    FRIO := nil;
end;

procedure TSoapConnection.GetProviderNames(Proc: TGetStrProc);
var
  List: Variant;
  I: Integer;
begin
  Connected := True;
  VarClear(List);
  try
    List := FAppServer.AS_GetProviderNames;
  except
    { Assume any errors means the list is not available. }
  end;
  if VarIsArray(List) and (VarArrayDimCount(List) = 1) then
    for I := VarArrayLowBound(List, 1) to VarArrayHighBound(List, 1) do
      Proc(List[I]);
end;

function TSoapConnection.GetServer: IAppServer;
begin
  Connected := True;
  Result := FAppServer;
end;

{ Provides direct access to the underlying SOAP Server that
  implements IAppServer }
function TSoapConnection.GetSOAPServer: IAppServerSOAP;
begin
  Result := FSOAPServer;
end;

function TSoapConnection.GetServerList: OleVariant;
begin
end;

procedure TSoapConnection.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
end;

procedure TSoapConnection.DoConnect;
begin
  if (URL = '') then
    raise Exception.Create(SNoURL);
  if not Assigned(FRIO) then
  try
    FRIO := THTTPRIO.Create(nil);
    if FUseSOAPAdapter then
    begin
      FSOAPServer := FRIO as IAppServerSOAP;
      FAppServer := TSOAPAppServerAdapter.Create(FSOAPServer);
    end
    else
      FAppServer := FRIO as IAppServer;
    if Assigned(FOnAfterExecute) then
      FRIO.OnAfterExecute := FOnAfterExecute;
    if Assigned(FOnBeforeExecute) then
      FRIO.OnBeforeExecute := FOnBeforeExecute;
    FRIO.URL := FURL;
  except
    Connected := False;
  end;
end;

function TSoapConnection.GetConnected: Boolean;
begin
  Result := Assigned(FRIO) and (Assigned(FRIO.HTTPWebNode));
end;

function TSoapConnection.GetAgent: string;
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    Result := FRIO.HTTPWebNode.Agent;
end;

function TSoapConnection.GetPassword: string;
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    Result := FRIO.HTTPWebNode.Password;
end;

function TSoapConnection.GetProxy: string;
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    Result := FRIO.HTTPWebNode.Proxy;
end;

function TSoapConnection.GetProxyByPass: string;
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    Result := FRIO.HTTPWebNode.ProxyByPass;
end;

function TSoapConnection.GetUserName: string;
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    Result := FRIO.HTTPWebNode.Username;
end;

procedure TSoapConnection.SetURL(const Value: string);
begin
  if Value <> FURL then
  begin
    FURL := Value;
    Connected := False;
  end;
end;

procedure TSoapConnection.SetAgent(const Value: string);
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    FRIO.HTTPWebNode.Agent := Value
  else if not (csLoading in ComponentState) then
    raise Exception.Create(SNoURL);
end;

procedure TSoapConnection.SetPassword(const Value: string);
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    FRIO.HTTPWebNode.Password := Value
  else if not (csLoading in ComponentState) then
    raise Exception.Create(SNoURL);
end;

procedure TSoapConnection.SetProxy(const Value: string);
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    FRIO.HTTPWebNode.Proxy := Value
  else if not (csLoading in ComponentState) then
    raise Exception.Create(SNoURL);
end;

procedure TSoapConnection.SetProxyByPass(const Value: string);
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    FRIO.HTTPWebNode.ProxyByPass := Value
  else if not (csLoading in ComponentState) then
    raise Exception.Create(SNoURL);
end;

procedure TSoapConnection.SetUserName(const Value: string);
begin
  if Assigned(FRIO) and Assigned(FRIO.HTTPWebNode) then
    FRIO.HTTPWebNode.UserName := Value
  else if not (csLoading in ComponentState) then
    raise Exception.Create(SNoURL);
end;

end.
