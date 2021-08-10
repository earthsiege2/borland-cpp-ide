unit IdQotdServer;

interface

uses
  Classes,
  IdGlobal,
  IdTCPServer;

type
  TIdQOTDGetEvent = procedure(Thread: TIdPeerThread) of object;

  TIdQOTDServer = class(TIdTCPServer)
  protected
    FOnCommandQOTD: TIdQOTDGetEvent;
    function DoExecute(Thread: TIdPeerThread): boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property OnCommandQOTD: TIdQOTDGetEvent read fOnCommandQOTD
    write fOnCommandQOTD;
    property DefaultPort default IdPORT_QOTD;
  end;

implementation

uses
  SysUtils;

constructor TIdQOTDServer.Create(AOwner: TComponent);
begin
  inherited;
  DefaultPort := IdPORT_QOTD;
end;

function TIdQOTDServer.DoExecute(Thread: TIdPeerThread): boolean;
begin
  result := true;
  if Thread.Connection.Connected then
  begin
    if assigned(OnCommandQOTD) then
    begin
      OnCommandQOTD(Thread);
    end;
  end;
  Thread.Connection.Disconnect;
end;

end.
