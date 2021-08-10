unit IdUDPServer;

interface

uses
  Classes,
  IdComponent, IdException, IdGlobal, IdSocketHandle, IdStackConsts, IdThread,
    IdUDPBase;

type
  TUDPReadEvent = procedure(Sender: TObject; AData: TStream; ABinding:
    TIdSocketHandle) of object;

  TIdUDPServer = class;

  TIdUDPListenerThread = class(TIdThread)
  protected
    IncomingData: TIdSocketHandle;
    FAcceptWait: integer;
    FBuffer: TMemoryStream;
    FBufferSize: integer;
  public
    FServer: TIdUDPServer;

    constructor Create(const ABufferSize: integer; Owner: TIdUDPServer);
      reintroduce;
    destructor Destroy; override;
    procedure Run; override;
    procedure UDPRead;

    property AcceptWait: integer read FAcceptWait write FAcceptWait;
  published
  end;

  TIdUDPServer = class(TIdUDPBase)
  protected
    FBindings: TIdSocketHandles;
    FCurrentBinding: TIdSocketHandle;
    FListenerThread: TIdUDPListenerThread;
    FOnUDPRead: TUDPReadEvent;
    FThreadedEvent: boolean;

    function GetDefaultPort: integer;
    procedure SetBindings(const Value: TIdSocketHandles);
    procedure SetDefaultPort(const AValue: integer);
    procedure PacketReceived(AData: TStream; ABinding: TIdSocketHandle);
    procedure DoUDPRead(AData: TStream; ABinding: TIdSocketHandle); virtual;
    function GetBinding: TIdSocketHandle; override;
    procedure CloseBinding; override;
    procedure BroadcastEnabledChanged; override;
    function GetActive: Boolean; override;
  public
    constructor Create(axOwner: TComponent); override;
    destructor Destroy; override;

  published
    property Bindings: TIdSocketHandles read FBindings write SetBindings;
    property DefaultPort: integer read GetDefaultPort write SetDefaultPort;
    property OnUDPRead: TUDPReadEvent read FOnUDPRead write FOnUDPRead;
    property ThreadedEvent: boolean read FThreadedEvent write FThreadedEvent
      default False;
  end;
  EIdUDPServerException = class(EIdUDPException);
  EIdNoBindingsSpecified = class(EIdUDPServerException);

implementation

uses
  IdResourceStrings, IdStack, SysUtils;

procedure TIdUDPServer.BroadcastEnabledChanged;
var
  i: integer;
begin
  if Assigned(FCurrentBinding) then
  begin
    for i := 0 to Bindings.Count - 1 do
    begin
      SetBroadcastFlag(BroadcastEnabled, Bindings[i]);
    end;
  end;
end;

procedure TIdUDPServer.CloseBinding;
var
  i: integer;
begin
  if Assigned(FCurrentBinding) then
  begin
    FListenerThread.Stop;
    for i := 0 to Bindings.Count - 1 do
    begin
      Bindings[i].CloseSocket;
    end;
    FreeAndNil(FListenerThread);
    FCurrentBinding := nil;
  end;
end;

constructor TIdUDPServer.Create(axOwner: TComponent);
begin
  inherited;
  FBindings := TIdSocketHandles.Create(Self);
end;

destructor TIdUDPServer.Destroy;
begin
  Active := False;
  FreeAndNil(FBindings);
  inherited;
end;

procedure TIdUDPServer.DoUDPRead(AData: TStream; ABinding: TIdSocketHandle);
begin
  if assigned(OnUDPRead) then
  begin
    OnUDPRead(Self, AData, ABinding);
  end;
end;

function TIdUDPServer.GetActive: Boolean;
begin
  Result := inherited GetActive or
    (Assigned(FCurrentBinding) and FCurrentBinding.HandleAllocated);
end;

function TIdUDPServer.GetBinding: TIdSocketHandle;
var
  i: integer;
begin
  if not Assigned(FCurrentBinding) then
  begin
    if Bindings.Count < 1 then
    begin
      if DefaultPort > 0 then
      begin
        Bindings.Add;
      end
      else
      begin
        raise EIdNoBindingsSpecified.Create(RSNoBindingsSpecified);
      end;
    end;
    for i := 0 to Bindings.Count - 1 do
    begin
      Bindings[i].AllocateSocket(Id_SOCK_DGRAM);
      Bindings[i].Bind;
    end;
    FCurrentBinding := Bindings[0];
    FListenerThread := TIdUDPListenerThread.Create(BufferSize, Self);
    FListenerThread.Start;
    BroadcastEnabledChanged;
  end;
  Result := FCurrentBinding;
end;

function TIdUDPServer.GetDefaultPort: integer;
begin
  result := FBindings.DefaultPort;
end;

procedure TIdUDPServer.PacketReceived(AData: TStream;
  ABinding: TIdSocketHandle);
begin
  FCurrentBinding := ABinding;
  DoUDPRead(AData, ABinding);
end;

procedure TIdUDPServer.SetBindings(const Value: TIdSocketHandles);
begin
  FBindings.Assign(Value);
end;

procedure TIdUDPServer.SetDefaultPort(const AValue: integer);
begin
  FBindings.DefaultPort := AValue;
end;

constructor TIdUDPListenerThread.Create(const ABufferSize: integer; Owner:
  TIdUDPServer);
begin
  inherited Create(True);
  FAcceptWait := 1000;
  FBuffer := TMemoryStream.Create;
  FBufferSize := ABufferSize;
  FServer := Owner;
end;

destructor TIdUDPListenerThread.Destroy;
begin
  FBuffer.Free;
  inherited;
end;

procedure TIdUDPListenerThread.Run;
var
  PeerIP: string;
  i, PeerPort, ByteCount: Integer;
  FReadList: TList;
begin
  FReadList := TList.Create;
  try
    FReadList.Capacity := FServer.Bindings.Count;
    for i := 0 to FServer.Bindings.Count - 1 do
    begin
      FReadList.Add(Pointer(FServer.Bindings[i].Handle));
    end;
    GStack.WSSelect(FReadList, nil, nil, AcceptWait);
    for i := 0 to FReadList.Count - 1 do
      if not Stopped then
      begin
        IncomingData :=
          FServer.Bindings.BindingByHandle(TIdStackSocketHandle(FReadList[i]));
        FBuffer.SetSize(FBufferSize);
        ByteCount := GStack.WSRecvFrom(IncomingData.Handle, FBuffer.Memory^,
          FBufferSize, 0
          , PeerIP, PeerPort);
        GStack.CheckForSocketError(ByteCount);
        if ByteCount = 0 then
        begin
          raise EIdUDPReceiveErrorZeroBytes.Create(RSUDPReceiveError0);
        end;
        FBuffer.SetSize(ByteCount);
        FBuffer.Position := 0;
        IncomingData.SetPeer(PeerIP, PeerPort);
        if FServer.ThreadedEvent then
        begin
          UDPRead;
        end
        else
        begin
          Synchronize(UDPRead);
        end;
      end;
  finally
    FReadList.Free;
  end;
end;

procedure TIdUDPListenerThread.UDPRead;
begin
  FServer.PacketReceived(FBuffer, IncomingData);
end;

end.
