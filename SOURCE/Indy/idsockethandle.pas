unit IdSocketHandle;

interface

uses
  Classes,
  IdException,
  IdGlobal,
  IdStack, IdStackConsts;

type
  TIdSocketHandle = class;

  TIdSocketHandles = class(TOwnedCollection)
  protected
    FDefaultPort: integer;

    function GetItem(Index: Integer): TIdSocketHandle;
    procedure SetItem(Index: Integer; const Value: TIdSocketHandle);
  public
    constructor Create(AOwner: TComponent); reintroduce;
    function Add: TIdSocketHandle; reintroduce;
    function BindingByHandle(const AHandle: TIdStackSocketHandle):
      TIdSocketHandle;
    property Items[Index: Integer]: TIdSocketHandle read GetItem write SetItem;
      default;

    property DefaultPort: integer read FDefaultPort write FDefaultPort;
  end;

  TIdSocketHandle = class(TCollectionItem)
  protected
    FHandle: TIdStackSocketHandle;
    FHandleAllocated: Boolean;
    FIP, FPeerIP: string;
    FPort, FPeerPort: integer;
  public
    procedure Accept(ASocket: TIdStackSocketHandle);
    procedure AllocateSocket(const ASocketType: Integer = Id_SOCK_STREAM;
      const AProtocol: Integer = Id_IPPROTO_IP);

    procedure Assign(Source: TPersistent); override;
    procedure Bind;
    procedure CloseSocket(const AResetLocal: boolean = True); virtual;
    function Connect(const AFamily: Integer = Id_PF_INET): Integer; virtual;
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;
    procedure Listen(const anQueueCount: integer = 5);
    function Readable(AMSec: Integer = IdTimeoutDefault): boolean;
    function Recv(var ABuf; ALen, AFlags: Integer): Integer;
    function RecvFrom(var ABuffer; const ALength, AFlags: Integer; var VIP:
      string;
      var VPort: Integer): Integer; virtual;
    procedure Reset(const AResetLocal: boolean = True);
    function Send(var Buf; len, flags: Integer): Integer;
    procedure SendTo(const AIP: string; const APort: Integer; var ABuffer;
      const ABufferSize: Integer);
    procedure SetPeer(const asIP: string; anPort: integer);
    procedure SetSockOpt(level, optname: Integer; optval: PChar; optlen:
      Integer);
    procedure UpdateBindingLocal;
    procedure UpdateBindingPeer;

    property HandleAllocated: Boolean read FHandleAllocated;
    property Handle: TIdStackSocketHandle read FHandle;
    property PeerIP: string read FPeerIP;
    property PeerPort: integer read FPeerPort;
  published
    property IP: string read FIP write FIP;
    property Port: integer read FPort write FPort;
  end;
  EIdSocketHandleError = class(EIdException);
  EIdPackageSizeTooBig = class(EIdSocketHandleError);
  EIdNotAllBytesSent = class(EIdSocketHandleError);
  EIdCouldNotBindSocket = class(EIdSocketHandleError);
implementation

uses
  IdAntiFreezeBase,
  IdComponent,
  IdResourceStrings;

procedure TIdSocketHandle.AllocateSocket(const ASocketType: Integer =
  Id_SOCK_STREAM;
  const AProtocol: Integer = Id_IPPROTO_IP);
begin

  CloseSocket;
  FHandle := GStack.CreateSocketHandle(ASocketType, AProtocol);
  FHandleAllocated := True;
end;

procedure TIdSocketHandle.CloseSocket(const AResetLocal: boolean = True);
begin
  if HandleAllocated then
  begin
    FHandleAllocated := False;
    GStack.WSShutdown(Handle, Id_SD_Send);
    GStack.WSCloseSocket(Handle);
    Reset(AResetLocal);
  end;
end;

function TIdSocketHandle.Connect(const AFamily: Integer = Id_PF_INET): Integer;
begin
  result := GStack.WSConnect(Handle, AFamily, PeerIP, PeerPort);
  if result <> Id_Socket_Error then
  begin
    UpdateBindingLocal;
    UpdateBindingPeer;
  end;
end;

destructor TIdSocketHandle.Destroy;
begin
  CloseSocket;
  inherited;
end;

function TIdSocketHandle.Recv(var ABuf; ALen, AFlags: Integer): Integer;
begin
  result := GStack.WSRecv(Handle, ABuf, ALen, AFlags);
end;

function TIdSocketHandle.Send(var Buf; len, flags: Integer): Integer;
begin
  result := GStack.WSSend(Handle, Buf, len, flags);
end;

procedure TIdSocketHandle.SetSockOpt(level, optname: Integer; optval: PChar;
  optlen: Integer);
begin
  GStack.CheckForSocketError(GStack.WSSetSockOpt(Handle, level, optname, optval,
    optlen));
end;

procedure TIdSocketHandle.SendTo(const AIP: string; const APort: Integer; var
  ABuffer;
  const ABufferSize: Integer);
var
  BytesOut: Integer;
begin
  BytesOut := GStack.WSSendTo(Handle, ABuffer, ABufferSize, 0, AIP, APort);
  if BytesOut = Id_SOCKET_ERROR then
  begin
    if GStack.WSGetLastError() = Id_WSAEMSGSIZE then
    begin
      raise EIdPackageSizeTooBig.Create(RSPackageSizeTooBig);
    end
    else
    begin
      GStack.CheckForSocketError;
    end;
  end
  else
    if BytesOut <> ABufferSize then
  begin
    raise EIdNotAllBytesSent.Create(RSNotAllBytesSent);
  end;
end;

function TIdSocketHandle.RecvFrom(var ABuffer; const ALength, AFlags: Integer;
  var VIP: string;
  var VPort: Integer): Integer;
begin
  result := GStack.WSRecvFrom(Handle, ABuffer, ALength, AFlags, VIP, VPort);
end;

procedure TIdSocketHandle.Bind;
begin
  if GStack.CheckForSocketError(GStack.WSBind(Handle, Id_PF_INET, IP, Port),
    [Id_WSAEADDRINUSE]) then
  begin
    raise EIdCouldNotBindSocket.Create(RSCouldNotBindSocket);
  end;
  UpdateBindingLocal;
end;

procedure TIdSocketHandle.SetPeer(const asIP: string; anPort: integer);
begin
  FPeerIP := asIP;
  FPeerPort := anPort;
end;

procedure TIdSocketHandle.Listen(const anQueueCount: integer);
begin
  GStack.CheckForSocketError(GStack.WSListen(Handle, anQueueCount));
end;

procedure TIdSocketHandle.Accept(ASocket: TIdStackSocketHandle);
var
  LAcceptedSocket: TIdStackSocketHandle;
begin
  LAcceptedSocket := GStack.WSAccept(ASocket, FIP, FPort);
  GStack.CheckForSocketError(LAcceptedSocket);
  FHandle := LAcceptedSocket;
  FHandleAllocated := True;
  UpdateBindingLocal;
  UpdateBindingPeer;
end;

constructor TIdSocketHandle.Create(ACollection: TCollection);
begin
  inherited;
  Reset;
  if assigned(ACollection) then
  begin
    Port := TIdSocketHandles(ACollection).DefaultPort;
  end;
end;

function TIdSocketHandle.Readable(AMSec: Integer = IdTimeoutDefault): boolean;
var
  ReadList: TList;
begin
  if not FHandleAllocated then
  begin
    raise EIdConnClosedGracefully.Create(RSConnectionClosedGracefully);
  end;

  if GAntiFreeze <> nil then
  begin
    if GAntiFreeze.Active then
    begin
      if AMSec = IdTimeoutInfinite then
      begin
        repeat
          result := Readable(GAntiFreeze.IdleTimeOut);
        until result;
        exit;
      end
      else
        if AMSec > GAntiFreeze.IdleTimeOut then
      begin
        result := Readable(AMSec - GAntiFreeze.IdleTimeOut);
        if result then
        begin
          exit;
        end
        else
        begin
          AMSec := GAntiFreeze.IdleTimeOut;
        end;
      end;
    end;
  end;
  ReadList := TList.Create;
  try
    ReadList.Add(Pointer(Handle));
    Result := GStack.WSSelect(ReadList, nil, nil, AMSec) = 1;
    TIdAntiFreezeBase.DoProcess(result = false);
  finally ReadList.free;
  end;
end;

procedure TIdSocketHandle.Assign(Source: TPersistent);
var
  LSource: TIdSocketHandle;
begin
  if ClassType <> Source.ClassType then
  begin
    inherited
  end
  else
  begin
    LSource := TIdSocketHandle(Source);
    IP := LSource.IP;
    Port := LSource.Port;
    FPeerIP := LSource.PeerIP;
    FPeerPort := LSource.PeerPort;
  end;
end;

procedure TIdSocketHandle.UpdateBindingLocal;
var
  LFamily: integer;
begin
  GStack.WSGetSockName(Handle, LFamily, FIP, FPort);
end;

procedure TIdSocketHandle.UpdateBindingPeer;
var
  LFamily: integer;
begin
  GStack.WSGetPeerName(Handle, LFamily, FPeerIP, FPeerPort);
end;

procedure TIdSocketHandle.Reset(const AResetLocal: boolean = True);
begin
  FHandleAllocated := False;
  FHandle := Id_INVALID_SOCKET;
  if AResetLocal then
  begin
    FIP := '';
    FPort := 0;
  end;
  FPeerIP := '';
  FPeerPort := 0;
end;

function TIdSocketHandles.Add: TIdSocketHandle;
begin
  result := inherited Add as TIdSocketHandle;
  result.Port := DefaultPort;
end;

function TIdSocketHandles.BindingByHandle(const AHandle: TIdStackSocketHandle):
  TIdSocketHandle;
var
  i: integer;
begin
  Result := nil;
  i := Count - 1;
  while (i >= 0) and (Items[i].Handle <> AHandle) do
  begin
    dec(i);
  end;
  if i >= 0 then
  begin
    Result := Items[i];
  end;
end;

constructor TIdSocketHandles.Create(AOwner: TComponent);
begin
  inherited Create(AOwner, TIdSocketHandle);
end;

function TIdSocketHandles.GetItem(Index: Integer): TIdSocketHandle;
begin
  result := TIdSocketHandle(inherited Items[index]);
end;

procedure TIdSocketHandles.SetItem(Index: Integer; const Value:
  TIdSocketHandle);
begin
  inherited SetItem(Index, Value);
end;

end.
