unit IdEcho;

interface

uses
  Classes,
  IdGlobal,
  IdTCPClient;

type
  TIdEcho = class(TIdTCPClient)
  protected
    FEchoTime: Cardinal;
  public
    constructor Create(AOwner: TComponent); override;
    function Echo(AText: string): string;
    property EchoTime: Cardinal read FEchoTime;
  published
    property Port default IdPORT_ECHO;
  end;

implementation

uses
  IdComponent,
  IdTCPConnection,
  SysUtils;

constructor TIdEcho.Create(AOwner: TComponent);
begin
  inherited;
  Port := IdPORT_ECHO;
end;

function TIdEcho.Echo(AText: string): string;
var
  StartTime: Cardinal;
begin
  BeginWork(wmWrite, Length(AText) + 2);
  try
    StartTime := IdGlobal.GetTickCount;
    Write(AText);
  finally
    EndWork(wmWrite);
  end;
  BeginWork(wmRead);
  try
    Result := CurrentReadBuffer;
    if IdGlobal.GetTickCount >= StartTime then
      FEchoTime := IdGlobal.GetTickCount - StartTime
    else
      FEchoTime := High(Cardinal) - StartTime;
  finally
    EndWork(wmRead);
  end;
end;

end.
