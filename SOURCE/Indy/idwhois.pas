unit IdWhois;

interface

uses
  Classes,
  IdGlobal,
  IdTCPClient;

type
  TIdWhois = class(TIdTCPClient)
  public
    constructor Create(AOwner: TComponent); override;
    function WhoIs(const ADomain: string): string;
  published
    property Port default IdPORT_WHOIS;
  end;

implementation

uses
  IdTCPConnection;

constructor TIdWHOIS.Create(AOwner: TComponent);
begin
  inherited;
  Host := 'whois.internic.net';
  Port := IdPORT_WHOIS;
end;

function TIdWHOIS.WhoIs(const ADomain: string): string;
begin
  Connect;
  try
    WriteLn(ADomain);
    Result := AllData;
  finally Disconnect;
  end;
end;

end.
