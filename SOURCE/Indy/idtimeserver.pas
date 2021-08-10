unit IdTimeServer;

interface

uses
  Classes,
  IdTCPServer;

type
  TIdTimeServer = class(TIdTCPServer)
  protected
    FBaseDate: TDateTime;

    function DoExecute(AThread: TIdPeerThread): boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property BaseDate: TDateTime read FBaseDate write FBaseDate;
  end;

implementation

uses
  IdGlobal,
  IdStack, SysUtils;

constructor TIdTimeServer.Create(AOwner: TComponent);
begin
  inherited;
  DefaultPort := IdPORT_TIME;
  FBaseDate := 2;
end;

function TIdTimeServer.DoExecute(AThread: TIdPeerThread): boolean;
begin
  result := true;
  with AThread.Connection do
  begin
    WriteCardinal(Trunc(extended(Now + IdGlobal.TimeZoneBias - Int(FBaseDate)) *
      24 * 60 * 60));
    Disconnect;
  end;
end;

end.
