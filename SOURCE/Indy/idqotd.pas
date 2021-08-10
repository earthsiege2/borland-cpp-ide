unit IdQotd;

interface

uses
  Classes,
  IdGlobal,
  IdTCPClient;

type
  TIdQOTD = class(TIdTCPClient)
  protected
    function GetQuote: string;
  public
    constructor Create(AOwner: TComponent); override;
    property Quote: string read GetQuote;
  published
    property Port default IdPORT_QOTD;
  end;

implementation

uses
  SysUtils;

constructor TIdQOTD.Create(AOwner: TComponent);
begin
  inherited;
  Port := IdPORT_QOTD;
end;

function TIdQOTD.GetQuote: string;
begin
  Result := ConnectAndGetAll;
end;

end.
