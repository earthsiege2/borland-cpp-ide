unit IdTCPServer;

interface

uses
  Classes, sysutils,
  IdComponent, IdException, IdSocketHandle, IdTCPConnection, IdThread,
    IdThreadMgr, IdThreadMgrDefault,
  IdIntercept;

type
  TIdTCPServer = class;

  TIdListenerThread = class(TIdThread)
  protected
    FAcceptWait: Integer;
    FBindingList: TList;
    FServer: TIdTCPServer;
  public
    procedure AfterRun; override;
    constructor Create(axServer: TIdTCPServer); reintroduce;
    destructor Destroy; override;
    procedure Run; override;

    property AcceptWait: integer read FAcceptWait write FAcceptWait;
    property Server: TIdTCPServer read FServer;
  end;

  TIdTCPServerConnection = class(TIdTCPConnection)
  protected
    function GetServer: TIdTCPServer;
  public
  published
    property Server: TIdTCPServer read GetServer;
  end;

  TIdPeerThread = class(TIdThread)
  protected
    FConnection: TIdTCPServerConnection;

    procedure AfterRun; override;
    procedure BeforeRun; override;
  public
    procedure Run; override;
    property Connection: TIdTCPServerConnection read FConnection;
  end;

  TIdServerThreadEvent = procedure(AThread: TIdPeerThread) of object;

  TIdTCPServer = class(TIdComponent)
  protected
    FAcceptWait: integer;
    FActive, FImplicitThreadMgrCreated: Boolean;
    FThreadMgr: TIdThreadMgr;
    FBindings: TIdSocketHandles;
    FListenerThread: TIdListenerThread;
    FTerminateWaitTime: Integer;
    FThreadClass: TIdThreadClass;
    FThreads: TThreadList;
    FOnExecute, FOnConnect, FOnDisconnect: TIdServerThreadEvent;

    FIntercept: TIdServerIntercept;
    procedure DoConnect(axThread: TIdPeerThread); virtual;
    procedure DoDisconnect(axThread: TIdPeerThread); virtual;
    function DoExecute(AThread: TIdPeerThread): boolean; virtual;
    function GetDefaultPort: integer;
    procedure Notification(AComponent: TComponent; Operation: TOperation);
      override;
    procedure SetAcceptWait(AValue: integer);
    procedure SetActive(AValue: Boolean); virtual;
    procedure SetBindings(const abValue: TIdSocketHandles);
    procedure SetDefaultPort(const AValue: integer);
    procedure SetIntercept(const Value: TIdServerIntercept);
    procedure SetThreadMgr(const Value: TIdThreadMgr);
    procedure TerminateAllThreads;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Loaded; override;
    property AcceptWait: integer read FAcceptWait write SetAcceptWait;
    property ImplicitThreadMgrCreated: Boolean read FImplicitThreadMgrCreated;
    property ThreadClass: TIdThreadClass read FThreadClass write FThreadClass;
    property Threads: TThreadList read FThreads;
  published
    property Active: boolean read FActive write SetActive default False;
    property Bindings: TIdSocketHandles read FBindings write SetBindings;
    property DefaultPort: integer read GetDefaultPort write SetDefaultPort;
    property Intercept: TIdServerIntercept read FIntercept write SetIntercept;
    property OnConnect: TIdServerThreadEvent read FOnConnect write FOnConnect;
    property OnExecute: TIdServerThreadEvent read FOnExecute write FOnExecute;
    property OnDisconnect: TIdServerThreadEvent read FOnDisconnect write
      FOnDisconnect;
    property TerminateWaitTime: Integer read FTerminateWaitTime write
      FTerminateWaitTime
    default 5000;
    property ThreadMgr: TIdThreadMgr read FThreadMgr write SetThreadMgr;
  end;
  EIdTCPServerError = class(EIdException);
  EIdAcceptWaitCannotBeModifiedWhileServerIsActive = class(EIdTCPServerError);
  EIdNoExecuteSpecified = class(EIdTCPServerError);

implementation

uses
  IdGlobal, IdResourceStrings, IdStack, IdStackConsts;

constructor TIdTCPServer.Create(AOwner: TComponent);
begin
  inherited;
  FAcceptWait := 1000;
  FTerminateWaitTime := 5000;
  FThreads := TThreadList.Create;
  FBindings := TIdSocketHandles.Create(Self);
  FThreadClass := TIdPeerThread;
end;

destructor TIdTCPServer.Destroy;
begin
  Active := False;
  TerminateAllThreads;
  FreeAndNil(FBindings);
  FreeAndNil(FThreads);
  inherited;
end;

procedure TIdTCPServer.DoConnect(axThread: TIdPeerThread);
begin
  if assigned(OnConnect) then
  begin
    OnConnect(axThread);
  end;
end;

procedure TIdTCPServer.DoDisconnect(axThread: TIdPeerThread);
begin
  if assigned(OnDisconnect) then
  begin
    OnDisconnect(axThread);
  end;
end;

function TIdTCPServer.DoExecute(AThread: TIdPeerThread): boolean;
begin
  result := assigned(OnExecute);
  if result then
  begin
    OnExecute(AThread);
  end;
end;

function TIdTCPServer.GetDefaultPort: integer;
begin
  result := FBindings.DefaultPort;
end;

procedure TIdTCPServer.Loaded;
begin
  inherited;
  if Active then
  begin
    FActive := False;
    Active := True;
  end;
end;

procedure TIdTCPServer.Notification(AComponent: TComponent; Operation:
  TOperation);
begin
  inherited;
  if (Operation = opRemove) then
  begin
    if (AComponent = FThreadMgr) then
    begin
      FThreadMgr := nil;
    end
    else
      if (AComponent = FIntercept) then
    begin
      FIntercept := nil;
    end;
  end;
end;

procedure TIdTCPServer.SetAcceptWait(AValue: integer);
begin
  if Active then
  begin
    raise
      EIdAcceptWaitCannotBeModifiedWhileServerIsActive.Create(RSAcceptWaitCannotBeModifiedWhileServerIsActive);
  end;
  FAcceptWait := AValue;
end;

procedure TIdTCPServer.SetActive(AValue: Boolean);
var
  i: Integer;
begin
  if (not (csDesigning in ComponentState)) and (FActive <> AValue)
    and (not (csLoading in ComponentState)) then
  begin
    if AValue then
    begin
      if Bindings.Count = 0 then
      begin
        Bindings.Add;
      end;

      for i := 0 to Bindings.Count - 1 do
      begin
        with Bindings[i] do
        begin
          AllocateSocket;
          SetSockOpt(Id_SOL_SOCKET, Id_SO_REUSEADDR, PChar(@Id_SO_True),
            SizeOf(Id_SO_True));
          Bind;
          Listen;
        end;
      end;

      FImplicitThreadMgrCreated := not assigned(ThreadMgr);
      if ImplicitThreadMgrCreated then
      begin
        ThreadMgr := TIdThreadMgrDefault.Create(Self);
      end;
      ThreadMgr.ThreadClass := ThreadClass;
      FListenerThread := TIdListenerThread.Create(Self);
      FListenerThread.AcceptWait := AcceptWait;
      FListenerThread.Start;
    end
    else
    begin
      FListenerThread.Stop;
      for i := 0 to Bindings.Count - 1 do
      begin
        Bindings[i].CloseSocket(False);
      end;
      TerminateAllThreads;
      if ImplicitThreadMgrCreated then
      begin
        FreeAndNil(FThreadMgr);
      end;
      FImplicitThreadMgrCreated := false;

      FListenerThread.WaitFor;
      FListenerThread.Free;
    end;
  end;
  FActive := AValue;
end;

procedure TIdTCPServer.SetBindings(const abValue: TIdSocketHandles);
begin
  FBindings.Assign(abValue);
end;

procedure TIdTCPServer.SetDefaultPort(const AValue: integer);
begin
  FBindings.DefaultPort := AValue;
end;

procedure TIdTCPServer.SetIntercept(const Value: TIdServerIntercept);
begin
  FIntercept := Value;
  if assigned(FIntercept) then
  begin
    FIntercept.FreeNotification(Self);
  end;
end;

procedure TIdTCPServer.SetThreadMgr(const Value: TIdThreadMgr);
begin
  FThreadMgr := Value;
  if Value <> nil then
  begin
    Value.FreeNotification(self);
  end;
end;

procedure TIdTCPServer.TerminateAllThreads;
var
  i: integer;
  list: TList;
  Thread: TIdPeerThread;
const
  LSleepTime: integer = 250;
begin
  list := Threads.LockList;
  try
    for i := 0 to list.Count - 1 do
    begin
      Thread := TIdPeerThread(list[i]);
      Thread.Connection.DisconnectSocket;
    end;
  finally Threads.UnlockList;
  end;
  for i := 1 to (TerminateWaitTime div LSleepTime) do
  begin
    Sleep(LSleepTime);
    list := Threads.LockList;
    try
      if list.Count = 0 then
      begin
        break;
      end;
    finally Threads.UnlockList;
    end;
  end;
end;

procedure TIdListenerThread.AfterRun;
var
  i: Integer;
begin
  inherited;
  for i := Server.Bindings.Count - 1 downto 0 do
  begin
    Server.Bindings[i].CloseSocket;
  end;
end;

constructor TIdListenerThread.Create(axServer: TIdTCPServer);
begin
  inherited Create;
  FBindingList := TList.Create;
  FServer := axServer;
end;

destructor TIdListenerThread.Destroy;
begin
  FBindinglist.Free;
  inherited;
end;

procedure TIdListenerThread.Run;
var
  Peer: TIdTCPServerConnection;
  Thread: TIdPeerThread;
  i: Integer;
begin
  FBindingList.Clear;
  for i := 0 to Server.Bindings.Count - 1 do
  begin
    FBindingList.Add(TObject(Server.Bindings[i].Handle));
  end;
  if GStack.WSSelect(FBindingList, nil, nil, AcceptWait) > 0 then
  begin
    if not Terminated then
    begin
      for i := 0 to FBindingList.Count - 1 do
      begin
        Peer := TIdTCPServerConnection.Create(Server);
        with Peer do
        begin
          Binding.Accept(TIdStackSocketHandle(FBindingList[i]));
          if Assigned(Server.Intercept) then
          begin
            try
              Peer.Intercept := Server.Intercept.Accept(Binding);
              Peer.InterceptEnabled := True;
            except
              FreeAndNil(Peer);
            end;
          end;
        end;
        if Peer <> nil then
        begin
          Thread := TIdPeerThread(Server.ThreadMgr.GetThread);
          Thread.FConnection := Peer;
          Server.Threads.Add(Thread);
          Thread.Start;
        end;
      end;
    end;
  end;
end;

function TIdTCPServerConnection.GetServer: TIdTCPServer;
begin
  result := Owner as TIdTCPServer;
end;

procedure TIdPeerThread.AfterRun;
begin
  with Connection.Server do
  begin
    DoDisconnect(Self);
    ThreadMgr.ReleaseThread(Self);
    Threads.Remove(Self);
  end;
  FreeAndNil(FConnection);
end;

procedure TIdPeerThread.BeforeRun;
begin
  Connection.Server.DoConnect(Self);
end;

procedure TIdPeerThread.Run;
begin
  try
    if not Connection.Server.DoExecute(Self) then
    begin
      raise EIdNoExecuteSpecified.Create(RSNoExecuteSpecified);
    end;
  except
    on E: EIdSocketError do
    begin
      case E.LastError of
        Id_WSAECONNABORTED,
          Id_WSAECONNRESET:
          Connection.Disconnect;
      end;
    end;
    on EIdClosedSocket do ;
  else
    raise;
  end;
  if not Connection.Connected then
  begin
    Stop;
  end;
end;

end.
