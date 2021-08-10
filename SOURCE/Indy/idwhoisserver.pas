unit IdWhoIsServer;

interface

uses
  Classes,
  IdGlobal,
  IdTCPServer;

type
  TGetEvent = procedure(AThread: TIdPeerThread; ALookup: string) of object;

  TIdWhoIsServer = class(TIdTCPserver)
  protected
    FOnCommandLookup: TGetEvent;
    function DoExecute(AThread: TIdPeerThread): boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property OnCommandLookup: TGetEvent read FOnCommandLookup write
      FOnCommandLookup;
    property DefaultPort default IdPORT_WHOIS;
  end;

implementation

constructor TIdWhoIsServer.Create(AOwner: TComponent);
begin
  inherited;
  DefaultPort := IdPORT_WHOIS;
end;

function TIdWhoIsServer.DoExecute(AThread: TIdPeerThread): boolean;
var
  Response: string;
begin
  result := true;
  with AThread.Connection do
  begin
    while Connected do
    begin
      Response := ReadLn;
      if Connected then
      begin
        if Assigned(OnCommandLookup) then
        begin
          OnCommandLookup(AThread, Response);
        end;
      end;
    end;
    Disconnect;
  end;
end;

end.
