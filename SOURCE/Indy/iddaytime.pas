unit IdDayTime;

interface

uses
  Classes,
  IdGlobal,
  IdTCPClient;

type
  TIdDayTime = class(TIdTCPClient)
  protected
    function GetDayTimeStr: string;
  public
    constructor Create(AOwner: TComponent); override;
    property DayTimeStr: string read GetDayTimeStr;
  published
    property Port default IdPORT_DAYTIME;
  end;

implementation

uses
  SysUtils;

constructor TIdDayTime.Create(AOwner: TComponent);
begin
  inherited;
  Port := IdPORT_DAYTIME;
end;

function TIdDayTime.GetDayTimeStr: string;
begin
  Result := Trim(ConnectAndGetAll);
end;

end.
