
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 2000,2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit BandActn;

interface

(*$HPPEMIT '#pragma link "dclact.lib"'*)

uses Graphics, Classes, Messages, Controls, ActnList, ActnMan, Forms,
  CustomizeDlg;

type
  TCustomizeActionBars = class(TAction)
  private
    FCustomizeDlg: TCustomizeDlg;
    FActionManager: TCustomActionManager;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ExecuteTarget(Target: TObject); override;
    function HandlesTarget(Target: TObject): Boolean; override;
  published
    property ActionManager: TCustomActionManager read FActionManager
      write FActionManager;
  end;

implementation

uses Windows, Consts;

{ TCustomizeActionBars }

constructor TCustomizeActionBars.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Caption := SCustomize;
end;

procedure TCustomizeActionBars.ExecuteTarget(Target: TObject);
begin
  if FCustomizeDlg = nil then
    FCustomizeDlg := TCustomizeDlg.Create(Application);
  FCustomizeDlg.ActionManager := TCustomActionManager(ActionList);
  FCustomizeDlg.Show;
end;

function TCustomizeActionBars.HandlesTarget(Target: TObject): Boolean;
begin
  Result := ActionList is TCustomActionManager;
end;

end.
