unit IdDayTimeServer;

interface

uses
  Classes,
  IdGlobal,
  IdTCPServer;

type
  TIdDayTimeServer = class(TIdTCPServer)
  protected
    FTimeZone: string;
    function DoExecute(AThread: TIdPeerThread): boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property TimeZone: string read FTimeZone write FTimeZone;
    property DefaultPort default IdPORT_DAYTIME;
  end;

implementation

uses
  SysUtils;

constructor TIdDayTimeServer.Create(AOwner: TComponent);
begin
  inherited;
  DefaultPort := IdPORT_DAYTIME;
  FTimeZone := 'EST';
end;

function TIdDayTimeServer.DoExecute(AThread: TIdPeerThread): boolean;
begin
  result := true;
  with AThread.Connection do
  begin
    Writeln(FormatDateTime('dddd, mmmm dd, yyyy hh:nn:ss', Now) + '-' +
      FTimeZone);
    Disconnect;
  end;
end;

end.
