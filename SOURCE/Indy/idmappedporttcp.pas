unit IdMappedPortTCP;

interface

uses
  Classes, IdTCPClient, IdTCPServer;

const
  ID_MAPPED_PORT_TCP_PORT = 0;
type
  TIdMappedPortTCPData = class
  public
    OutboundClient: TIdTCPClient;
    ReadList: TList;

    constructor Create;
    destructor Destroy; override;
  end;

  TBeforeClientConnectEvent = procedure(ASender: TComponent; AThread:
    TIdPeerThread;
    AClient: TIdTCPClient) of object;

  TIdMappedPortTCP = class(TIdTCPServer)
  protected
    FMappedPort: integer;
    FMappedHost: string;
    FOnBeforeClientConnect: TBeforeClientConnectEvent;

    procedure DoConnect(AThread: TIdPeerThread); override;
    function DoExecute(AThread: TIdPeerThread): boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property MappedHost: string read FMappedHost write FMappedHost;
    property MappedPort: integer read FMappedPort write FMappedPort default
      ID_MAPPED_PORT_TCP_PORT;
    property OnBeforeClientConnect: TBeforeClientConnectEvent read
      FOnBeforeClientConnect
    write FOnBeforeClientConnect;
  end;

implementation

uses
  IdGlobal, IdStack,
  SysUtils;

constructor TIdMappedPortTCP.Create(AOwner: TComponent);
begin
  inherited;
  FMappedPort := ID_MAPPED_PORT_TCP_PORT;
end;

procedure TIdMappedPortTCP.DoConnect(AThread: TIdPeerThread);
begin
  inherited;
  AThread.Data := TIdMappedPortTCPData.Create;
  with TIdMappedPortTCPData(AThread.Data) do
  begin
    OutboundClient := TIdTCPClient.Create(nil);
    with OutboundClient do
    begin
      Port := MappedPort;
      Host := MappedHost;
      if Assigned(FOnBeforeClientConnect) then
      begin
        FOnBeforeClientConnect(Self, AThread, OutboundClient);
      end;
      Connect;
    end;
  end;
end;

function TIdMappedPortTCP.DoExecute(AThread: TIdPeerThread): boolean;
var
  LData: TIdMappedPortTCPData;
begin
  result := true;
  LData := TIdMappedPortTCPData(AThread.Data);
  try
    with LData.ReadList do
    begin
      Clear;
      Add(TObject(AThread.Connection.Binding.Handle));
      Add(TObject(LData.OutboundClient.Binding.Handle));
      if GStack.WSSelect(LData.ReadList, nil, nil, IdTimeoutInfinite) > 0 then
      begin
        if IndexOf(TObject(AThread.Connection.Binding.Handle)) > -1 then
        begin
          LData.OutboundClient.Write(AThread.Connection.CurrentReadBuffer);
        end;
        if IndexOf(TObject(LData.OutboundClient.Binding.Handle)) > -1 then
        begin
          AThread.Connection.Write(LData.OutboundClient.CurrentReadBuffer);
        end;
      end;
    end;
  finally
    if not LData.OutboundClient.Connected then
    begin
      AThread.Connection.Disconnect;
    end;
  end;
end;

constructor TIdMappedPortTCPData.Create;
begin
  ReadList := TList.Create;
end;

destructor TIdMappedPortTCPData.Destroy;
begin
  FreeAndNil(ReadList);
  FreeAndNil(OutboundClient);
  inherited;
end;

end.
