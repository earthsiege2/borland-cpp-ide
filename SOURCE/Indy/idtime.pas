unit IdTime;

interface

uses
  Classes, IdTCPClient;

type
  TIdTime = class(TIdTCPClient)
  protected
    FBaseDate: TDateTime;
    FRoundTripDelay: Cardinal;
    FTimeout: Integer;
    function GetDateTimeCard: Cardinal;
    function GetDateTime: TDateTime;
  public
    constructor Create(AOwner: TComponent); override;
    function SyncTime: boolean;
    property DateTimeCard: Cardinal read GetDateTimeCard;
    property DateTime: TDateTime read GetDateTime;
    property RoundTripDelay: Cardinal read FRoundTripDelay;
  published
    property BaseDate: TDateTime read FBaseDate write FBaseDate;
    property Timeout: Integer read FTimeout write FTimeout default 2500;
  end;

implementation

uses
  IdGlobal, IdTCPConnection,
  SysUtils;

constructor TIdTime.Create(AOwner: TComponent);
begin
  inherited;
  Port := IdPORT_TIME;
  FBaseDate := 2;
  FTimeout := 2500;
end;

function TIdTime.GetDateTime: TDateTime;
var
  BufCard: Cardinal;
begin
  BufCard := GetDateTimeCard;
  if BufCard <> 0 then
  begin
    Result := ((BufCard / (24 * 60 * 60) + (FRoundTripDelay div 1000)) +
      Int(fBaseDate))
      - IdGlobal.TimeZoneBias;
  end
  else
  begin
    Result := 0;
  end;
end;

function TIdTime.GetDateTimeCard: Cardinal;
var
  TimeBeforeRetrieve: Cardinal;
begin
  Result := 0;
  Connect;
  try
    TimeBeforeRetrieve := IdGlobal.GetTickCount;
    repeat
      if ReadFromStack(True, FTimeout) = 0 then
      begin
        Exit;
      end;
    until (CurrentReadBufferSize >= SizeOf(Result));
    Result := ReadCardinal;
    if IdGlobal.GetTickCount >= TimeBeforeRetrieve then
    begin
      FRoundTripDelay := (IdGlobal.GetTickCount - TimeBeforeRetrieve) div 2
    end
    else
    begin
      FRoundTripDelay := (High(Cardinal) - TimeBeforeRetrieve +
        IdGlobal.GetTickCount) div 2;
    end;
  finally Disconnect;
  end;
end;

function TIdTime.SyncTime: boolean;
var
  BufTime: TDateTime;
begin
  BufTime := DateTime;
  result := BufTime <> 0;
  if result then
  begin
    result := SetLocalTime(BufTime);
  end;
end;

end.
