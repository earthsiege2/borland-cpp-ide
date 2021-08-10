unit IdUDPClient;

interface

uses
  IdUDPBase;

type
  TIdUDPClient = class(TIdUDPBase)
  protected
  public
    procedure Send(AData: string); overload;
    procedure SendBuffer(var ABuffer; const AByteCount: integer); overload;
  published
    property Host: string read FHost write FHost;
    property Port: Integer read FPort write FPort;
    property ReceiveTimeout;
  end;

implementation

procedure TIdUDPClient.Send(AData: string);
begin
  Send(Host, Port, AData);
end;

procedure TIdUDPClient.SendBuffer(var ABuffer; const AByteCount: integer);
begin
  SendBuffer(Host, Port, ABuffer, AByteCount);
end;

end.
