
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit XMLBrokr;

interface

uses Classes, HTTPApp, Db, DbClient, Provider,
  WebComp, Masks, Midas;

type

{ TXMLBroker }

  TRequestRecordsEvent = procedure (Sender: TObject; Request: TWebRequest;
     out RecCount: Integer; var OwnerData: OleVariant; var Records: string) of object;
  TRequestUpdateEvent = procedure (Sender: TObject; Request: TWebRequest;
     Response: TWebResponse; var Handled: Boolean) of object;
  TGetErrorResponseEvent = procedure (Sender: TObject; ErrorCount: Integer; XMLErrors: string; Request: TWebRequest;
     Response: TWebResponse; var Handled: Boolean) of object;
  TGetResponseEvent = procedure (Sender: TObject;Request: TWebRequest;
     Response: TWebResponse; var Handled: Boolean) of object;

  TXMLParams = class(TParams)
  protected
    procedure AssignTo(Dest: TPersistent); override;
  public
    procedure AssignStrings(Value: TStrings);
  end;

  TXMLOption = (xoQuote);
  TXMLOptions = set of TXMLOption;

  TWebDispatch = class;

  TXMLBroker = class(TComponent, IWebDispatch)
  private
    FWebDispatch: TWebDispatch;
    FAppServer: IAppServer;
    FProviderName: string;
    FRemoteServer: TCustomRemoteServer;
    FParams: TXMLParams;
    FMaxRecords: Integer;
    FRequestRecords: TRequestRecordsEvent;
    FBeforeDispatch: THTTPMethodEvent;
    FAfterDispatch: THTTPMethodEvent;
    FRequestUpdate: TRequestUpdateEvent;
    FMaxErrors: Integer;
    FReconcileProducer: TCustomContentProducer;
    FGetResponse: TGetResponseEvent;
    FGetErrorResponse: TGetErrorResponseEvent;
    FErrors: string;
    FErrorCount: Integer;
    FNotify: TList;
  protected
    procedure AS_FetchParams;
    function AS_GetRecords(Count: Integer; out RecsOut: Integer;
      Options: Integer; const CommandText: WideString; Params: OleVariant; var OwnerData: OleVariant): OleVariant;
    function AS_ApplyUpdates(Delta: OleVariant; MaxErrors: Integer;
      out ErrorCount: Integer): OleVariant;
    { IWebDispatch }
    function DispatchEnabled: Boolean;
    function DispatchMethodType: TMethodType;
    function DispatchRequest(Sender: TObject; Request: TWebRequest; Response: TWebResponse): Boolean;
    function DispatchMask: TMask;
    function DispatchSubItems: IInterfaceList;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetWebDispatch(const Value: TWebDispatch);
    function GetAppServer: IAppServer;
    function GetHasAppServer: Boolean;
    procedure SetAppServer(Value: IAppServer);
    procedure SetProviderName(const Value: string);
    procedure SetRemoteServer(Value: TCustomRemoteServer);
    function GetConnected: Boolean;
    procedure SetConnected(Value: Boolean);
    procedure CheckInactive;
    procedure SetParams(const Value: TXMLParams);
    function GetErrorResponse(ErrorCount: Integer; XMLErrors: string;
      Request: TWebRequest; Response: TWebResponse): Boolean;
    function GetResponse(Request: TWebRequest;
      Response: TWebResponse): Boolean;
    function GetProducerName(Request: TWebRequest): string;
    function GetRedirect(Request: TWebRequest): string;
    procedure SendConnectEvent(Connecting: Boolean);
    function GetNotify(Index: Integer): TObject;
    function GetNotifyCount: Integer;
    procedure SetReconcileProducer(const Value: TCustomContentProducer);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetXMLRecords(var RecsOut: Integer;
      var OwnerData: OleVariant; XMLOptions: TXMLOptions): string;
    function ApplyXMLUpdates(const Delta: string; out ErrorCount: Integer): string;
    function GetDelta(Request: TWebRequest): string;
    function GetErrors: string;
    function GetErrorCount: Integer;
    function HTMLSubmitFormName: string;
    function SubmitFormVarName: string;
    function RowSetVarName(Path: TStrings): string;
    function MasterRowSetVarName(Path: TStrings): string;
    property HasAppServer: Boolean read GetHasAppServer;
    procedure SetProvider(Provider: TComponent);
    property AppServer: IAppServer read GetAppServer write SetAppServer;
    function RequestRecords(Sender: TObject; Request: TWebRequest; out RecCount: Integer;
      var OwnerData: OleVariant; XMLOptions: TXMLOptions): string; virtual;
    function RequestUpdate(Sender: TObject; Request: TWebRequest;
      Response: TWebResponse): Boolean; virtual;
    procedure FetchParams; virtual;
    procedure AddNotify(ANotify: TObject);
    procedure RemoveNotify(ANotify: TObject);
    property Notify[Index: Integer]: TObject read GetNotify;
    property NotifyCount: Integer read GetNotifyCount;
  published
    property Connected: Boolean read GetConnected write SetConnected stored False;
    property MaxRecords: Integer read FMaxRecords write FMaxRecords default -1;
    property MaxErrors: Integer read FMaxErrors write FMaxErrors default -1;
    property Params: TXMLParams read FParams write SetParams;
    property ProviderName: string read FProviderName write SetProviderName;
    property RemoteServer: TCustomRemoteServer read FRemoteServer write SetRemoteServer;
    property WebDispatch: TWebDispatch read FWebDispatch write SetWebDispatch;
    property OnRequestRecords: TRequestRecordsEvent read FRequestRecords write FRequestRecords;
    property OnRequestUpdate: TRequestUpdateEvent read FRequestUpdate write FRequestUpdate;
    property BeforeDispatch: THTTPMethodEvent read FBeforeDispatch write FBeforeDispatch;
    property AfterDispatch: THTTPMethodEvent read FAfterDispatch write FAfterDispatch;
    property ReconcileProducer: TCustomContentProducer read FReconcileProducer write SetReconcileProducer;
    property OnGetErrorResponse: TGetErrorResponseEvent read FGetErrorResponse write FGetErrorResponse;
    property OnGetResponse: TGetResponseEvent read FGetResponse write FGetResponse;
  end;

  TWebPathInfo = class;

  TWebDispatch = class(TPersistent)
  private
    FPathInfo: TWebPathInfo;
    FMethodType: TMethodType;
    FEnabled: Boolean;
    function GetMask: TMask;
  protected
    procedure AssignTo(Dest: TPersistent); override;
    procedure SetPathInfo(const Value: string);
    function GetPathInfo: string;
  public
    constructor Create(AComponent: TComponent);
    destructor Destroy; override;
    property Mask: TMask read GetMask;
  published
    property Enabled: Boolean read FEnabled write FEnabled default True;
    property MethodType: TMethodType read FMethodType write FMethodType default mtPost;
    property PathInfo: string read GetPathInfo write SetPathInfo;
  end;

  TWebPathInfo = class
  private
    FMask: TMask;
    FMaskPathInfo: string;
    FPathInfo: string;
    FOwner: TComponent;
    function GetMask: TMask;
    function GetPathInfo: string;
    procedure SetPathInfo(const Value: string);
  public
    constructor Create(AOwner: TComponent);
    destructor Destroy; override;
    property Mask: TMask read GetMask;
    property PathInfo: string read GetPathInfo write SetPathInfo;
  end;

  INotifyConnectionChange = interface
  ['{0BC29A90-0EEC-11D3-AFED-00C04FB16EC3}']
    procedure ConnectionChange(Sender: TComponent; Connected: Boolean);
  end;

const
  sProducer = 'PRODUCER';
  sPostDelta = 'postdelta';
  sRedirect = 'REDIRECT';

function FormatXML(const Value: string; XMLOptions: TXMLOptions): string;

implementation

uses Windows, Messages, DbConsts, MidConst, ActiveX, ComObj, WebConst, sysutils, DbWeb, Forms,
  DsIntf, WbmConst;

{ TLocalAppServer }

type

  TLocalAppServer = class(TInterfacedObject, IAppServer, ISupportErrorInfo)
  private
    FProvider: TCustomProvider;
  protected
    { IDispatch }
    function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
    function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
    function GetIDsOfNames(const IID: TGUID; Names: Pointer;
      NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
    function Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
    { IAppServer }
    function AS_ApplyUpdates(const ProviderName: WideString; Delta: OleVariant; MaxErrors: Integer;
                             out ErrorCount: Integer; var OwnerData: OleVariant): OleVariant; safecall;
    function AS_GetRecords(const ProviderName: WideString; Count: Integer; out RecsOut: Integer;
                           Options: Integer; const CommandText: WideString; var Params: OleVariant; 
                           var OwnerData: OleVariant): OleVariant; safecall;
    function AS_DataRequest(const ProviderName: WideString; Data: OleVariant): OleVariant; safecall;
    function AS_GetProviderNames: OleVariant; safecall;
    function AS_GetParams(const ProviderName: WideString; var OwnerData: OleVariant): OleVariant; safecall;
    function AS_RowRequest(const ProviderName: WideString; Row: OleVariant; RequestType: Integer;
                           var OwnerData: OleVariant): OleVariant; safecall;
    procedure AS_Execute(const ProviderName: WideString; const CommandText: WideString; var Params: OleVariant;
                         var OwnerData: OleVariant); safecall;
    { ISupportErrorInfo }
    function InterfaceSupportsErrorInfo(const iid: TIID): HResult; stdcall;
  public
    constructor Create(AProvider: TCustomProvider);
    function SafeCallException(ExceptObject: TObject;
      ExceptAddr: Pointer): HResult; override;
  end;

{ TLocalAppServer }

// Copied from dbclient
constructor TLocalAppServer.Create(AProvider: TCustomProvider);
begin
  FProvider := AProvider;
end;

function TLocalAppServer.GetTypeInfoCount(out Count: Integer): HResult;
begin
  Result := E_NOTIMPL;
end;

function TLocalAppServer.GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult;
begin
  Result := E_NOTIMPL;
end;

function TLocalAppServer.GetIDsOfNames(const IID: TGUID; Names: Pointer;
  NameCount, LocaleID: Integer; DispIDs: Pointer): HResult;
begin
  Result := E_NOTIMPL;
end;

function TLocalAppServer.Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
  Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult;
begin
  Result := E_NOTIMPL;
end;

function TLocalAppServer.AS_ApplyUpdates(const ProviderName: WideString;
  Delta: OleVariant; MaxErrors: Integer; out ErrorCount: Integer;
  var OwnerData: OleVariant): OleVariant;
begin
  Result := FProvider.ApplyUpdates(Delta, MaxErrors, ErrorCount, OwnerData);
end;

function TLocalAppServer.AS_GetRecords(const ProviderName: WideString; Count: Integer;
  out RecsOut: Integer; Options: Integer; const CommandText: WideString; var Params, OwnerData: OleVariant): OleVariant;
begin
  Result := FProvider.GetRecords(Count, RecsOut, Options, CommandText, Params, OwnerData);
end;

function TLocalAppServer.AS_GetProviderNames: OleVariant;
begin
  Result := NULL;
end;

function TLocalAppServer.AS_DataRequest(const ProviderName: WideString;
  Data: OleVariant): OleVariant;
begin
  Result := FProvider.DataRequest(Data);
end;

function TLocalAppServer.AS_GetParams(const ProviderName: WideString;
  var OwnerData: OleVariant): OleVariant;
begin
  Result := FProvider.GetParams(OwnerData);
end;

function TLocalAppServer.AS_RowRequest(const ProviderName: WideString;
  Row: OleVariant; RequestType: Integer; var OwnerData: OleVariant): OleVariant;
begin
  Result := FProvider.RowRequest(Row, RequestType, OwnerData);
end;

procedure TLocalAppServer.AS_Execute(const ProviderName: WideString;
  const CommandText: WideString; var Params, OwnerData: OleVariant);
begin
  FProvider.Execute(CommandText, Params, OwnerData);
end;

function TLocalAppServer.InterfaceSupportsErrorInfo(const iid: TIID): HResult;
begin
  if IsEqualGUID(IAppServer, iid) then
    Result := S_OK else
    Result := S_FALSE;
end;

function TLocalAppServer.SafeCallException(ExceptObject: TObject;
  ExceptAddr: Pointer): HResult;
begin
  Result := HandleSafeCallException(ExceptObject, ExceptAddr, IAppServer, '', '');
end;

{ TXMLBroker }

procedure TXMLBroker.SetRemoteServer(Value: TCustomRemoteServer);
begin
  if Value = FRemoteServer then Exit;
  AppServer := nil;
  if Assigned(Value) then
  begin
    CheckInactive;
    Value.FreeNotification(Self);
    FRemoteServer := Value;
    SendConnectEvent(True);
  end
  else
  begin
    FRemoteServer := Value;
    SendConnectEvent(False);
  end;
end;

constructor TXMLBroker.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FWebDispatch := TWebDispatch.Create(Self);
  FParams := TXMLParams.Create(Self);
  FMaxRecords := -1;
  FMaxErrors := -1;
  FNotify := TList.Create;
end;

destructor TXMLBroker.Destroy;
begin
  inherited Destroy;
  FWebDispatch.Free;
  SetRemoteServer(nil);
  AppServer := nil;
  FParams.Free;
  FNotify.Free;
end;

procedure TXMLBroker.CheckInactive;
begin
  if Connected then
    if ([csUpdating, csDesigning] * ComponentState) <> [] then
      Connected := False else
      DatabaseError(SDataSetOpen, Self);
end;

function TXMLBroker.GetAppServer: IAppServer;
var
  ProvComp: TComponent;
begin
  Result := nil;
  if not HasAppServer then
  begin
    if ProviderName <> '' then
      if Assigned(RemoteServer) then
        RemoteServer.Connected := True
      else
      begin
        if Assigned(Owner) then
        begin
          ProvComp := Owner.FindComponent(ProviderName);
          if Assigned(ProvComp) and (ProvComp is TCustomProvider) then
            FAppServer := TLocalAppServer.Create(TCustomProvider(ProvComp));
        end;
      end;
    if not HasAppServer then
      DatabaseError(SNoDataProvider, Self);
  end;
  if Assigned(FAppServer) then
    Result := FAppServer
  else if Assigned(RemoteServer) then
    Result := RemoteServer.GetServer;
end;

function TXMLBroker.GetHasAppServer: Boolean;
begin
  Result := Assigned(FAppServer) or
    (Assigned(FRemoteServer) and FRemoteServer.Connected);
end;

procedure TXMLBroker.SetAppServer(Value: IAppServer);
begin
  FAppServer := Value;
  SendConnectEvent(FAppServer <> nil);
end;

procedure TXMLBroker.SetProvider(Provider: TComponent);
begin
  if Provider is TCustomProvider then
    AppServer := TLocalAppServer.Create(TCustomProvider(Provider));
end;

procedure TXMLBroker.SetProviderName(const Value: string);
begin
  if Value = FProviderName then Exit;
  if (Value <> '') then
  begin
    CheckInactive;
    FProviderName := Value;
    SendConnectEvent(True);
  end
  else
  begin
    FProviderName := Value;
    SendConnectEvent(False);
  end;
end;

function TXMLBroker.AS_GetRecords(Count: Integer; out RecsOut: Integer;
  Options: Integer; const CommandText: WideString; Params: OleVariant; var OwnerData: OleVariant): OleVariant;
begin
  Result := AppServer.AS_GetRecords(ProviderName, Count, RecsOut, Options, CommandText, Params, OwnerData);
  UnPackParams(Params, Self.Params);
end;

function FormatXML(const Value: string; XMLOptions: TXMLOptions): string;
var
  P: PChar;
begin
  Result := Value;
  P := PChar(Value);
  if (P[0] = '<') and (P[1] = '?') then
  begin
    P := StrPos(P, '?>');
    if P <> nil then
      Delete(Result, 1, (P - PChar(Value)) + 2);
  end;
  if xoQuote in XMLOptions then
    Result := '''' + TrimRight(Result) + '''';
end;

function TXMLBroker.GetXMLRecords(
  var RecsOut: Integer; var OwnerData: OleVariant;
  XMLOptions: TXMLOptions): string;
var
  ByteArray: OleVariant;
  Options: TGetRecordOptions;
begin
  Options := [grMetaData, grXML, grReset];
  RecsOut := 0;
  ByteArray := AS_GetRecords(MaxRecords, RecsOut, Byte(Options), '', PackageParams(Params), OwnerData);
  Result := FormatXML(VariantArrayToString(ByteArray),
     XMLOptions);
end;

function TXMLBroker.RequestRecords(Sender: TObject; Request: TWebRequest;
  out RecCount: Integer; var OwnerData: OleVariant;
  XMLOptions: TXMLOptions): string;
begin
  Result := '';
  if Assigned(FRequestRecords) then
    FRequestRecords(Sender, Request, RecCount, OwnerData, Result);
  if Result = '' then
    Result := GetXMLRecords(RecCount, OwnerData, XMLOptions);
end;

procedure TXMLBroker.SetParams(const Value: TXMLParams);
begin
  FParams.Assign(Value);
end;

//{$DEFINE DEBUG}













function TXMLBroker.ApplyXMLUpdates(const Delta: string; out ErrorCount: Integer): string;
var
  XMLDelta: OleVariant;
  XMLErrors: OleVariant;
begin


  XMLDelta := StringToVariantArray('<?xml version="1.0" standalone="yes"?>' + Delta);


  if Delta = '' then
    ErrorCount := 0
  else
    XMLErrors := AS_ApplyUpdates(XMLDelta, MaxErrors, ErrorCount);
  if ErrorCount > 0 then
  begin


    Result := VariantArrayToString(XMLErrors)
  end
  else
    Result := '';
end;

function TXMLBroker.AS_ApplyUpdates(Delta: OleVariant; MaxErrors: Integer;
  out ErrorCount: Integer): OleVariant;
var
  OwnerData: OleVariant;
begin
  Result := AppServer.AS_ApplyUpdates(ProviderName, Delta, MaxErrors, ErrorCount, OwnerData);
end;

function TXMLBroker.GetConnected: Boolean;
begin
  Result := HasAppServer;
end;

procedure TXMLBroker.SetConnected(Value: Boolean);
begin
  if HasAppServer <> Value then
    if Value then
      GetAppServer
    else
    begin
      AppServer := nil;
      if Assigned(RemoteServer) then
        RemoteServer.Connected := False;
    end;
end;

function TXMLBroker.DispatchEnabled: Boolean;
begin
  Result := FWebDispatch.Enabled;
end;

function TXMLBroker.DispatchMask: TMask;
begin
  Result := FWebDispatch.Mask;

end;

function TXMLBroker.DispatchMethodType: TMethodType;
begin
  Result := FWebDispatch.MethodType;
end;

function TXMLBroker.DispatchRequest(Sender: TObject;
  Request: TWebRequest; Response: TWebResponse): Boolean;
begin
  Result := False;
  if Assigned(FBeforeDispatch) then
    FBeforeDispatch(Self, Request, Response, Result);
  if not Result then
    Result := RequestUpdate(Sender, Request, Response);
  if Assigned(FAfterDispatch) then
    FAfterDispatch(Self, Request, Response, Result);
end;

function TXMLBroker.RequestUpdate(Sender: TObject; Request: TWebRequest; Response: TWebResponse): Boolean;
var
  Delta: string;
  ErrorCount: Integer;
  XMLErrors: string;
begin
  Result := False;
  if Assigned(FRequestUpdate) then
    FRequestUpdate(Sender, Request, Response, Result);
  if not Result then
  begin
    Delta := GetDelta(Request);
    if Delta <> '' then
      XMLErrors := ApplyXMLUpdates(Delta, ErrorCount)
    else
      ErrorCount := 0;
    if ErrorCount > 0 then
      Result := GetErrorResponse(ErrorCount, XMLErrors, Request, Response)
    else
      Result := GetResponse(Request, Response);
  end;
end;

function TXMLBroker.GetErrors: string;
begin
  Result := FErrors;
end;

function TXMLBroker.GetErrorCount: integer;
begin
  Result := FErrorCount;
end;

function TXMLBroker.GetErrorResponse(ErrorCount: Integer; XMLErrors: string;
  Request: TWebRequest; Response: TWebResponse): Boolean;
begin
  Result := False;
  FErrors := XMLErrors;
  FErrorCount := ErrorCount;
  try
    if Assigned(FGetErrorResponse) then
      FGetErrorResponse(Self, ErrorCount, XMLErrors, Request, Response, Result);
    if (not Result) and Assigned(FReconcileProducer) then
    begin
      Response.Content := FReconcileProducer.Content;
      Result := True;
    end;
  finally
    FErrors := '';
    FErrorCount := 0;
  end;
  if not Result then
    raise Exception.CreateResFmt(@sApplyUpdatesError, [ErrorCount]);
end;

function TXMLBroker.GetResponse(
  Request: TWebRequest; Response: TWebResponse): Boolean;
var
  Producer: TComponent;
  Redirect: string;
begin
  Result := False;
  if Assigned(FGetResponse) then
    FGetResponse(Self, Request, Response, Result);
  if not Result then
  begin
    Redirect := GetRedirect(Request);
    if Redirect <> '' then
    begin
      Response.SendRedirect(Redirect);
      Result := True;
    end;
  end;
  if not Result then
  begin
    Producer := Owner.FindComponent(GetProducerName(Request));
    if Assigned(Producer) and (Producer is TCustomContentProducer) then
    begin
      Response.Content := TCustomContentProducer(Producer).Content;
      Result := True;
    end;
  end;
end;

function TXMLBroker.GetProducerName(Request: TWebRequest): string;
begin
  Result := Request.ContentFields.Values[SProducer];
end;

function TXMLBroker.GetRedirect(Request: TWebRequest): string;
begin
  Result := Request.ContentFields.Values[SRedirect];
end;

function TXMLBroker.GetDelta(Request: TWebRequest): string;
begin
  Result := Request.ContentFields.Values[SPostDelta];
end;

function TXMLBroker.DispatchSubItems: IInterfaceList;
begin
  Result := nil;
end;

procedure TXMLBroker.SetWebDispatch(const Value: TWebDispatch);
begin
  FWebDispatch.Assign(Value);
end;

function TXMLBroker.HTMLSubmitFormName: string;
begin
  Result := Format('Submit_%s', [Name]);
end;

function TXMLBroker.SubmitFormVarName: string;
begin
  Result := HTMLSubmitFormName;
end;

procedure TXMLBroker.AS_FetchParams;
var
  OwnerData: OleVariant;
begin
  UnpackParams(AppServer.AS_GetParams(ProviderName, OwnerData), Params);
end;

procedure TXMLBroker.FetchParams;
begin
  AS_FetchParams;
end;

function TXMLBroker.RowSetVarName(Path: TStrings): string;
var
  I: Integer;
begin
  Result := Name;
  if Assigned(Path) then
    for I := Path.Count - 1 downto 0 do
      Result := Format('%s_%s', [Result, Path[I]]);
  Result := Format(ScriptRowSetVarName, [Result]);
end;

function TXMLBroker.MasterRowSetVarName(Path: TStrings): string;
var
  I: Integer;
begin
  Result := Name;
  if Assigned(Path) and (Path.Count > 1) then
    for I := Path.Count - 2 downto 0 do
      Result := Format('%s_%s', [Result, Path[I]]);
  Result := Format(ScriptRowSetVarName, [Result]);
end;

procedure TXMLBroker.AddNotify(ANotify: TObject);
begin
  FNotify.Add(ANotify);
end;

procedure TXMLBroker.RemoveNotify(ANotify: TObject);
begin
  FNotify.Remove(ANotify);
end;

function TXMLBroker.GetNotify(Index: Integer): TObject;
begin
  Result := FNotify[Index];
end;

function TXMLBroker.GetNotifyCount: Integer;
begin
  Result := FNotify.Count;
end;

procedure TXMLBroker.SendConnectEvent(Connecting: Boolean);
var
  I: Integer;
  ConnectionChange: INotifyConnectionChange;
begin
  for I := 0 to NotifyCount - 1 do
    if Notify[I].GetInterface(INotifyConnectionChange, ConnectionChange) then
      ConnectionChange.ConnectionChange(Self, Connecting);
end;

procedure TXMLBroker.SetReconcileProducer(
  const Value: TCustomContentProducer);
begin
  if FReconcileProducer <> Value then
  begin
    FReconcileProducer := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

procedure TXMLBroker.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) then
  begin
    if AComponent = FReconcileProducer then
      FReconcileProducer := nil
    else if AComponent = FRemoteServer then
      FRemoteServer := nil;
  end;
end;

{ TXMLParams }

procedure TXMLParams.AssignStrings(Value: TStrings);
var
  ParamName: string;
  Param: TParam;
  I: Integer;
begin
  for I := 0 to Value.Count - 1 do
  begin
    ParamName := Value.Names[I];
    Param := FindParam(ParamName);
    if Assigned(Param) then
      Param.Value := Value.Values[ParamName];
  end;
end;

procedure TXMLParams.AssignTo(Dest: TPersistent);
begin
  if Dest is TXMLParams then TXMLParams(Dest).Assign(Self)
  else inherited AssignTo(Dest);
end;

{ TWebDispatch }

constructor TWebDispatch.Create(AComponent: TComponent);
begin
  inherited Create;
  FEnabled := True;
  FMethodType := mtPost;
  FPathInfo := TWebPathInfo.Create(AComponent);
end;

destructor TWebDispatch.Destroy;
begin
  inherited;
  FPathInfo.Free;
end;

procedure TWebDispatch.SetPathInfo(const Value: string);
begin
  FPathInfo.PathInfo := Value;
end;

procedure TWebDispatch.AssignTo(Dest: TPersistent);
begin
  if Dest is TWebDispatch then
    with TWebDispatch(Dest) do
    begin
      PathInfo := Self.PathInfo;
      MethodType := Self.MethodType;
      Enabled := Self.Enabled;
    end else inherited AssignTo(Dest);
end;

function TWebDispatch.GetPathInfo: string;
begin
  Result := FPathInfo.PathInfo;
end;

function TWebDispatch.GetMask: TMask;
begin
  Result := FPathInfo.Mask;
end;

{ TWebPathInfo }

constructor TWebPathInfo.Create(AOwner: TComponent);
begin
  FMaskPathInfo := '';
  FMask := TMask.Create(FMaskPathInfo);
  FOwner := AOwner;
end;

destructor TWebPathInfo.Destroy;
begin
  FMask.Free;
  inherited;
end;

function TWebPathInfo.GetMask: TMask;
var
  Mask: TMask;
  NewValue: string;
begin
  if PathInfo <> FMaskPathInfo then
  begin
    FMaskPathInfo := PathInfo;
    if FMaskPathInfo <> '' then NewValue := DosPathToUnixPath(FMaskPathInfo);
    if (NewValue <> '') and (NewValue[1] <> '/') then Insert('/', NewValue, 1);
    Mask := TMask.Create(NewValue);
    try
      FPathInfo := NewValue;
      FMask.Free;
      FMask := nil;
    except
      Mask.Free;
      raise;
    end;
    FMask := Mask;
  end;
  Result := FMask;
end;

function TWebPathInfo.GetPathInfo: string;
begin
  Result := FPathInfo;
  if Result = '' then
    if Assigned(FOwner) then
      Result := FOwner.Name;
end;

procedure TWebPathInfo.SetPathInfo(const Value: string);
begin
  if Assigned(FOwner) and (Value = FOwner.Name) then
    FPathInfo := ''
  else
    FPathInfo := Value;
end;

end.
