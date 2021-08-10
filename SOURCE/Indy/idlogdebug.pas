unit IdLogDebug;

interface

uses
  Classes,
  IdLogBase,
  IdException,
  IdSocketHandle;

type
  TIdLogDebugTarget = (ltFile, ltDebugOutput, ltEvent);
const
  ID_TIDLOGDEBUG_TARGET = ltFile;
type
  TLogItemEvent = procedure(ASender: TComponent; var AText: string) of object;

  TIdLogDebug = class(TIdLogBase)
  protected
    FFilename: string;
    FFileStream: TFileStream;
    FOnLogItem: TLogItemEvent;
    FTarget: TIdLogDebugTarget;

    procedure Log(AText: string); override;
    procedure SetActive(const AValue: Boolean); override;
    procedure SetTarget(const AValue: TIdLogDebugTarget);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property Filename: string read FFilename write FFilename;
    property OnLogItem: TLogItemEvent read FOnLogItem write FOnLogItem;
    property Target: TIdLogDebugTarget read FTarget write SetTarget default
      ID_TIDLOGDEBUG_TARGET;
  end;
  EIdCanNotChangeTarget = class(EIdException);

implementation

uses
  IdGlobal,
  IdResourceStrings,
  SysUtils;

constructor TIdLogDebug.Create(AOwner: TComponent);
begin
  inherited;
  FTarget := ID_TIDLOGDEBUG_TARGET;
end;

destructor TIdLogDebug.Destroy;
begin
  Active := False;
  inherited;
end;

procedure TIdLogDebug.Log(AText: string);
var
  s: string;
begin
  if assigned(OnLogItem) then
  begin
    OnLogItem(Self, AText);
  end;
  case Target of
    ltFile:
      begin
        FFileStream.WriteBuffer(PChar(AText)^, Length(AText));
        s := EOL;
        FFileStream.WriteBuffer(PChar(s)^, Length(s));
      end;
    ltDebugOutput:
      begin
        DebugOutput(AText + EOL);
      end;
  end;
end;

procedure TIdLogDebug.SetActive(const AValue: Boolean);
begin
  if AValue then
  begin
    case Target of
      ltFile:
        if not (csLoading in ComponentState) then
        begin
          if FileExists(Filename) then
          begin
            FFileStream := TFileStream.Create(Filename, fmOpenReadWrite);
          end
          else
          begin
            FFileStream := TFileStream.Create(Filename, fmCreate);
          end;
          FFileStream.Position := FFileStream.Size;
        end;
    end;
  end
  else
  begin
    case Target of
      ltFile:
        begin
          FreeAndNil(FFileStream);
        end;
    end;
  end;
  inherited;
end;

procedure TIdLogDebug.SetTarget(const AValue: TIdLogDebugTarget);
begin
  if ([csLoading, csDesigning] * ComponentState = []) and Active then
  begin
    raise EIdCanNotChangeTarget.Create(RSCannotChangeDebugTargetAtWhileActive);
  end;
  FTarget := AValue;
end;

end.
