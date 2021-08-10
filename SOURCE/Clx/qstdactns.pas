{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QStdActns;

{$H+,X+}
  
interface

uses Classes, QActnList, QStdCtrls, QForms, QClipbrd;

type

{ Hint actions }

  THintAction = class(TCustomAction)
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Hint;
  end;

{ Edit actions }

  TEditAction = class(TAction)
  private
    FEditControl: TCustomEdit;
    FMemoControl: TCustomMemo;
    procedure SetEditControl(Value: TCustomEdit);
    procedure SetMemoControl(Value: TCustomMemo);
  protected
    function GetEditControl(Target: TObject): TCustomEdit; virtual;
    function GetMemoControl(Target: TObject): TCustomMemo; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
    property EditControl: TCustomEdit read FEditControl write SetEditControl;
    property MemoControl: TCustomMemo read FMemoControl write SetMemoControl;
  end;

  TEditCut = class(TEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TEditCopy = class(TEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TEditPaste = class(TEditAction)
  public
    procedure UpdateTarget(Target: TObject); override;
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TEditSelectAll = class(TEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

  TEditDelete = class(TEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

{ MDI Window actions }

  TWindowAction = class(TAction)
  private
    FForm: TForm;
    procedure SetForm(Value: TForm);
  protected
    function GetForm(Target: TObject): TForm; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
    property Form: TForm read FForm write SetForm;
  end;

  TWindowClose = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

  TWindowCascade = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TWindowTile = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TWindowMinimizeAll = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

{ Help actions }

  THelpAction = class(TAction)
  public
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
  end;

  THelpContents = class(THelpAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  THelpTopicSearch = class(THelpAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

implementation

uses SysUtils, QConsts, QSearch;

{ THintAction }

constructor THintAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  DisableIfNoHandler := False;
end;

{ TEditAction }

function TEditAction.GetEditControl(Target: TObject): TCustomEdit;
begin
  { We could hard cast Target as a TCustomEdit since HandlesTarget "should" be
    called before ExecuteTarget and UpdateTarget, however, we're being safe. }
  Result := Target as TCustomEdit;
end;

function TEditAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := ((((EditControl <> nil) and (Target = EditControl)) or
    ((EditControl = nil) and (Target is TCustomEdit))) and TCustomEdit(Target).Focused) or
    ((((MemoControl <> nil) and (Target = MemoControl)) or
    ((MemoControl = nil) and (Target is TCustomMemo))) and TCustomMemo(Target).Focused);
end;

procedure TEditAction.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = EditControl) then EditControl := nil;
  if (Operation = opRemove) and (AComponent = MemoControl) then MemoControl := nil;
end;

procedure TEditAction.UpdateTarget(Target: TObject);
begin
  if (Self is TEditCut) or (Self is TEditCopy) or (Self is TEditDelete) then
    Enabled := ((Target is TCustomEdit) and (GetEditControl(Target).SelLength > 0)) or
      ((Target is TCustomMemo) and (GetMemoControl(Target).SelLength > 0));
end;

procedure TEditAction.SetEditControl(Value: TCustomEdit);
begin
  if Value <> FEditControl then
  begin
    FEditControl := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

function TEditAction.GetMemoControl(Target: TObject): TCustomMemo;
begin
  Result := Target as TCustomMemo;
end;

procedure TEditAction.SetMemoControl(Value: TCustomMemo);
begin
  if Value <> FMemoControl then
  begin
    FMemoControl := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

{ TEditCopy }

procedure TEditCopy.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomEdit then
    GetEditControl(Target).CopyToClipboard
  else if Target is TCustomMemo then
    GetMemoControl(Target).CopyToClipboard;
end;

{ TEditCut }

procedure TEditCut.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomEdit then
    GetEditControl(Target).CutToClipboard
  else if Target is TCustomMemo then
    GetMemoControl(Target).CutToClipboard;
end;

{ TEditPaste }

procedure TEditPaste.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomEdit then
    GetEditControl(Target).PasteFromClipboard
  else if Target is TCustomMemo then
    GetMemoControl(Target).PasteFromClipboard;
end;

procedure TEditPaste.UpdateTarget(Target: TObject);
begin
  Enabled := Clipboard.Provides('text/plain'); // do not localize
end;

{ TEditSelectAll }

procedure TEditSelectAll.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomEdit then
    GetEditControl(Target).SelectAll
  else if Target is TCustomMemo then
    GetMemoControl(Target).SelectAll;
end;

procedure TEditSelectAll.UpdateTarget(Target: TObject);
begin
  Enabled := ((Target is TCustomEdit) and (Length(GetEditControl(Target).Text) > 0)) or
    ((Target is TCustomMemo) and (Length(GetMemoControl(Target).Text) > 0));
end;

{ TEditDelete }

procedure TEditDelete.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomEdit then
    GetEditControl(Target).Clear
  else if Target is TCustomMemo then
    GetMemoControl(Target).Clear;
end;

{ TWindowAction }

function TWindowAction.GetForm(Target: TObject): TForm;
begin
  { We could hard cast Target as a TForm since HandlesTarget "should" be called
    before ExecuteTarget and UpdateTarget, however, we're being safe. }
  Result := (Target as TForm);
end;

function TWindowAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := ((Form <> nil) and (Target = Form) or
    (Form = nil) and (Target is TForm)) and
    (TForm(Target).FormStyle = fsMDIForm);
end;

procedure TWindowAction.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = Form) then Form := nil;
end;

procedure TWindowAction.UpdateTarget(Target: TObject);
begin
   Enabled := GetForm(Target).MDIChildCount > 0;
end;

procedure TWindowAction.SetForm(Value: TForm);
begin
  if Value <> FForm then
  begin
    FForm := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

{ TWindowClose }

procedure TWindowClose.ExecuteTarget(Target: TObject);
begin
  with GetForm(Target) do
    if ActiveMDIChild <> nil then ActiveMDIChild.Close;
end;

procedure TWindowClose.UpdateTarget(Target: TObject);
begin
   Enabled := GetForm(Target).ActiveMDIChild <> nil;
end;

{ TWindowCascade }

procedure TWindowCascade.ExecuteTarget(Target: TObject);
begin
   GetForm(Target).Cascade;
end;

{ TWindowTile }

procedure TWindowTile.ExecuteTarget(Target: TObject);
begin
  GetForm(Target).Tile;
end;

{ TWindowMinimizeAll }

procedure TWindowMinimizeAll.ExecuteTarget(Target: TObject);
var
  I: Integer;
begin
  { Must be done backwards through the MDIChildren array }
  with GetForm(Target) do
    for I := MDIChildCount - 1 downto 0 do
      MDIChildren[I].WindowState := wsMinimized;
end;

{ THelpAction }

function THelpAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := True;
end;

procedure THelpAction.UpdateTarget(Target: TObject);
begin
  Enabled := Assigned(Application);
end;

{ THelpContents }

procedure THelpContents.ExecuteTarget(Target: TObject);
begin
  Application.HelpSystem.ShowTableOfContents;
end;

{ THelpTopicSearch }

procedure THelpTopicSearch.ExecuteTarget(Target: TObject);
begin
  Application.HelpSystem.ShowHelp('','');
end;

end.
