unit IdAntiFreezeBase;

interface

uses
  Classes,
  IdBaseComponent,
  IdException;

const
  ID_Default_TIdAntiFreezeBase_Active = True;
  ID_Default_TIdAntiFreezeBase_ApplicationHasPriority = True;
  ID_Default_TIdAntiFreezeBase_IdleTimeOut = 250;
  ID_Default_TIdAntiFreezeBase_OnlyWhenIdle = True;

type
  TIdAntiFreezeBase = class(TIdBaseComponent)
  protected
    FActive: boolean;
    FApplicationHasPriority: boolean;
    FIdleTimeOut: Integer;
    FOnlyWhenIdle: Boolean;
  public
    constructor Create(AOwner: TComponent); override;
    class procedure DoProcess(const AIdle: boolean = true; const AOverride:
      boolean = false);
    destructor Destroy; override;
    procedure Process; virtual; abstract;
  published
    property Active: boolean read FActive write FActive
    default ID_Default_TIdAntiFreezeBase_Active;
    property ApplicationHasPriority: Boolean read FApplicationHasPriority
    write FApplicationHasPriority
      default ID_Default_TIdAntiFreezeBase_ApplicationHasPriority;
    property IdleTimeOut: integer read FIdleTimeOut write FIdleTimeOut
    default ID_Default_TIdAntiFreezeBase_IdleTimeOut;
    property OnlyWhenIdle: Boolean read FOnlyWhenIdle write FOnlyWhenIdle
    default ID_Default_TIdAntiFreezeBase_OnlyWhenIdle;
  end;
  EIdMoreThanOneTIdAntiFreeze = class(EIdException);

var
  GAntiFreeze: TIdAntiFreezeBase = nil;

implementation

uses
  IdGlobal,
  IdResourceStrings,
  SysUtils;

{ TIdAntiFreezeBase }

constructor TIdAntiFreezeBase.Create(AOwner: TComponent);
begin
  inherited;
  if csDesigning in ComponentState then
  begin
    if Assigned(GAntiFreeze) then
    begin
      raise EIdMoreThanOneTIdAntiFreeze.Create(RSOnlyOneAntiFreeze);
    end;
  end
  else
  begin
    GAntiFreeze := Self;
  end;
  FActive := ID_Default_TIdAntiFreezeBase_Active;
  FApplicationHasPriority :=
    ID_Default_TIdAntiFreezeBase_ApplicationHasPriority;
  IdleTimeOut := ID_Default_TIdAntiFreezeBase_IdleTimeOut;
  FOnlyWhenIdle := ID_Default_TIdAntiFreezeBase_OnlyWhenIdle;
end;

destructor TIdAntiFreezeBase.Destroy;
begin
  GAntiFreeze := nil;
  inherited;
end;

class procedure TIdAntiFreezeBase.DoProcess(const AIdle: boolean = true;
  const AOverride: boolean = false);
begin
  if (GAntiFreeze <> nil) and InMainThread then
  begin
    if ((GAntiFreeze.OnlyWhenIdle = false) or AIdle or AOverride) and
      GAntiFreeze.Active then
    begin
      GAntiFreeze.Process;
    end;
  end;
end;

end.
