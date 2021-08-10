unit IdEchoServer;

interface

uses
  Classes,
  IdGlobal,
  IdTCPServer;

type
  TIdECHOServer = class(TIdTCPServer)
  private
  protected
    function DoExecute(AThread: TIdPeerThread): boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property DefaultPort default IdPORT_ECHO;
  end;

implementation

uses
  SysUtils;

constructor TIdECHOServer.Create(AOwner: TComponent);
begin
  inherited;
  DefaultPort := IdPORT_ECHO
end;

function TIdECHOServer.DoExecute(AThread: TIdPeerThread): boolean;
begin
  result := true;
  with AThread.Connection do
  begin
    while Connected do
    begin
      Write(CurrentReadBuffer);
    end;
  end;
end;

end.
