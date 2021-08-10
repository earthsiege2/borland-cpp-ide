unit IdFinger;

interface

uses
  Classes,
  IdGlobal,
  IdTCPClient;

const
  Id_TIdFinger_VerboseOutput = False;
type
  TIdFinger = class(TIdTCPClient)
  protected
    FQuery: string;
    FVerboseOutput: Boolean;
    procedure SetCompleteQuery(AQuery: string);
    function GetCompleteQuery: string;
  public
    constructor Create(AOwner: TComponent); override;
    function Finger: string;
  published
    property Query: string read FQuery write FQuery;
    property CompleteQuery: string read GetCompleteQuery write SetCompleteQuery;
    property VerboseOutput: Boolean read FVerboseOutPut write FVerboseOutPut
    default Id_TIdFinger_VerboseOutput;
    property Port default IdPORT_FINGER;
  end;

implementation

uses
  IdTCPConnection,
  SysUtils;

constructor TIdFinger.Create(AOwner: TComponent);
begin
  inherited;
  Port := IdPORT_FINGER;
  FVerboseOutput := Id_TIdFinger_VerboseOutput;
end;

function TIdFinger.Finger: string;
var
  QStr: string;
begin
  QStr := FQuery;
  if VerboseOutPut then
  begin
    QStr := QStr + '/W';
  end;
  Connect;
  try
    Result := '';
    WriteLn(QStr);
    Result := AllData;
  finally
    Disconnect;
  end;
end;

function TIdFinger.GetCompleteQuery: string;
begin
  Result := FQuery + '@' + Host;
end;

procedure TIdFinger.SetCompleteQuery(AQuery: string);
var
  p: Integer;
begin
  p := RPos('@', AQuery, -1);
  if (p <> 0) then
  begin
    if (p < Length(AQuery)) then
    begin
      Host := Copy(AQuery, p + 1, Length(AQuery));
    end;
    FQuery := Copy(AQuery, 1, p - 1);
  end
  else
  begin
    FQuery := AQuery;
  end;
end;

end.
