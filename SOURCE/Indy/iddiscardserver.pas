unit IdDiscardServer;

interface

uses
  Classes,
  IdTCPServer;

type
  TIdDISCARDServer = class(TIdTCPServer)
  protected
    function DoExecute(Thread: TIdPeerThread): boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
  end;

implementation

uses
  IdGlobal,
  SysUtils;

constructor TIdDISCARDServer.Create(AOwner: TComponent);
begin
  inherited;
  DefaultPort := IdPORT_DISCARD;
end;

function TIdDISCARDServer.DoExecute(Thread: TIdPeerThread): boolean;
begin
  result := true;
  with Thread.Connection do
  begin
    while Connected do
    begin
      RemoveXBytesFromBuffer(CurrentReadBufferSize);
    end;
  end;
end;

end.
