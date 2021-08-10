
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit ActnList;

{$T-,H+,X+}

interface

uses Classes, Messages, ImgList;

type

{ TContainedAction }

  TCustomActionList = class;

  TContainedAction = class(TBasicAction)
  private
    FCategory: string;
    FActionList: TCustomActionList;
    function GetIndex: Integer;
    function IsCategoryStored: Boolean;
    procedure SetCategory(const Value: string);
    procedure SetIndex(Value: Integer);
    procedure SetActionList(AActionList: TCustomActionList);
  protected
    procedure ReadState(Reader: TReader); override;
    procedure SetParentComponent(AParent: TComponent); override;
  public
    destructor Destroy; override;
    function Execute: Boolean; override;
    function GetParentComponent: TComponent; override;
    function HasParent: Boolean; override;
    function Update: Boolean; override;
    property ActionList: TCustomActionList read FActionList write SetActionList;
    property Index: Integer read GetIndex write SetIndex stored False;
  published
    property Category: string read FCategory write SetCategory stored IsCategoryStored;
  end;

  TContainedActionClass = class of TContainedAction;

{ TCustomActionList }

  TActionEvent = procedure (Action: TBasicAction; var Handled: Boolean) of object;

  TCustomActionList = class(TComponent)
  private
    FActions: TList;
    FImageChangeLink: TChangeLink;
    FImages: TCustomImageList;
    FOnChange: TNotifyEvent;
    FOnExecute: TActionEvent;
    FOnUpdate: TActionEvent;
    procedure AddAction(Action: TContainedAction);
    function GetAction(Index: Integer): TContainedAction;
    function GetActionCount: Integer;
    procedure ImageListChange(Sender: TObject);
    procedure RemoveAction(Action: TContainedAction);
    procedure SetAction(Index: Integer; Value: TContainedAction);
    procedure SetImages(Value: TCustomImageList);
  protected
    procedure Change; virtual;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure SetChildOrder(Component: TComponent; Order: Integer); override;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnExecute: TActionEvent read FOnExecute write FOnExecute;
    property OnUpdate: TActionEvent read FOnUpdate write FOnUpdate;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function ExecuteAction(Action: TBasicAction): Boolean; override;
    function IsShortCut(var Message: TWMKey): Boolean;
    function UpdateAction(Action: TBasicAction): Boolean; override;
    property Actions[Index: Integer]: TContainedAction read GetAction write SetAction; default;
    property ActionCount: Integer read GetActionCount;
    property Images: TCustomImageList read FImages write SetImages;
  end;

{ TActionList }

  TActionList = class(TCustomActionList)
  published
    property Images;
    property OnChange;
    property OnExecute;
    property OnUpdate;
  end;

{ TControlAction }

  THintEvent = procedure (var HintStr: string; var CanShow: Boolean) of object;

  TCustomAction = class(TContainedAction)
  private
    FDisableIfNoHandler: Boolean;
    FCaption: string;
    FChecked: Boolean;
    FEnabled: Boolean;
    FHelpContext: THelpContext;
    FHint: string;
    FImageIndex: TImageIndex;
    FShortCut: TShortCut;
    FVisible: Boolean;
    FOnHint: THintEvent;
    procedure SetCaption(const Value: string);
    procedure SetChecked(Value: Boolean);
    procedure SetEnabled(Value: Boolean);
    procedure SetHelpContext(Value: THelpContext);
    procedure SetHint(const Value: string);
    procedure SetImageIndex(Value: TImageIndex);
    procedure SetShortCut(Value: TShortCut);
    procedure SetVisible(Value: Boolean);
  protected
    FImage: TObject;
    FMask: TObject;
    procedure AssignTo(Dest: TPersistent); override;
    procedure SetName(const Value: TComponentName); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function DoHint(var HintStr: string): Boolean; dynamic;
    function Execute: Boolean; override;
    property Caption: string read FCaption write SetCaption;
    property Checked: Boolean read FChecked write SetChecked default False;
    property DisableIfNoHandler: Boolean read FDisableIfNoHandler write FDisableIfNoHandler default True;
    property Enabled: Boolean read FEnabled write SetEnabled default True;
    property HelpContext: THelpContext read FHelpContext write SetHelpContext default 0;
    property Hint: string read FHint write SetHint;
    property ImageIndex: TImageIndex read FImageIndex write SetImageIndex default -1;
    property ShortCut: TShortCut read FShortCut write SetShortCut default 0;
    property Visible: Boolean read FVisible write SetVisible default True;
    property OnHint: THintEvent read FOnHint write FOnHint;
  end;

  TAction = class(TCustomAction)
  published
    property Caption;
    property Checked;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property Visible;
    property OnExecute;
    property OnHint;
    property OnUpdate;
  end;

{ TControlActionLink }

  TActionLink = class(TBasicActionLink)
  protected
    function IsCaptionLinked: Boolean; virtual;
    function IsCheckedLinked: Boolean; virtual;
    function IsEnabledLinked: Boolean; virtual;
    function IsHelpContextLinked: Boolean; virtual;
    function IsHintLinked: Boolean; virtual;
    function IsImageIndexLinked: Boolean; virtual;
    function IsShortCutLinked: Boolean; virtual;
    function IsVisibleLinked: Boolean; virtual;
    procedure SetCaption(const Value: string); virtual;
    procedure SetChecked(Value: Boolean); virtual;
    procedure SetEnabled(Value: Boolean); virtual;
    procedure SetHelpContext(Value: THelpContext); virtual;
    procedure SetHint(const Value: string); virtual;
    procedure SetImageIndex(Value: Integer); virtual;
    procedure SetShortCut(Value: TShortCut); virtual;
    procedure SetVisible(Value: Boolean); virtual;
  end;

  TActionLinkClass = class of TActionLink;

{ Action registration }

  TEnumActionProc = procedure (const Category: string; ActionClass: TBasicActionClass;
    Info: Pointer) of object;

procedure RegisterActions(const CategoryName: string;
  const AClasses: array of TBasicActionClass; Resource: TComponentClass);
procedure UnRegisterActions(const AClasses: array of TBasicActionClass);
procedure EnumRegisteredActions(Proc: TEnumActionProc; Info: Pointer);
function CreateAction(AOwner: TComponent; ActionClass: TBasicActionClass): TBasicAction;

const
  RegisterActionsProc: procedure (const CategoryName: string;
    const AClasses: array of TBasicActionClass; Resource: TComponentClass) = nil;
  UnRegisterActionsProc: procedure (const AClasses: array of TBasicActionClass) = nil;
  EnumRegisteredActionsProc: procedure (Proc: TEnumActionProc; Info: Pointer) = nil;
  CreateActionProc: function (AOwner: TComponent; ActionClass: TBasicActionClass): TBasicAction = nil;

implementation

uses SysUtils, Forms, Menus, Consts, Graphics, Controls;

procedure RegisterActions(const CategoryName: string;
  const AClasses: array of TBasicActionClass; Resource: TComponentClass);
begin
  if Assigned(RegisterActionsProc) then
    RegisterActionsProc(CategoryName, AClasses, Resource) else
    raise Exception.CreateRes(@SInvalidActionRegistration);
end;

procedure UnRegisterActions(const AClasses: array of TBasicActionClass);
begin
  if Assigned(UnRegisterActionsProc) then
    UnRegisterActionsProc(AClasses) else
    raise Exception.CreateRes(@SInvalidActionUnregistration);
end;

procedure EnumRegisteredActions(Proc: TEnumActionProc; Info: Pointer);
begin
  if Assigned(EnumRegisteredActionsProc) then
    EnumRegisteredActionsProc(Proc, Info) else
    raise Exception.CreateRes(@SInvalidActionEnumeration);
end;

function CreateAction(AOwner: TComponent; ActionClass: TBasicActionClass): TBasicAction;
begin
  if Assigned(CreateActionProc) then
    Result := CreateActionProc(AOwner, ActionClass) else
    raise Exception.CreateRes(@SInvalidActionCreation);
end;

{ TContainedAction }

destructor TContainedAction.Destroy;
begin
  if ActionList <> nil then ActionList.RemoveAction(Self);
  inherited Destroy;
end;

function TContainedAction.GetIndex: Integer;
begin
  if ActionList <> nil then
    Result := ActionList.FActions.IndexOf(Self) else
    Result := -1;
end;

function TContainedAction.IsCategoryStored: Boolean;
begin
  Result := True;//GetParentComponent <> ActionList;
end;

function TContainedAction.GetParentComponent: TComponent;
begin
  if ActionList <> nil then
    Result := ActionList else
    Result := inherited GetParentComponent;
end;

function TContainedAction.HasParent: Boolean;
begin
  if ActionList <> nil then
    Result := True else
    Result := inherited HasParent;
end;

procedure TContainedAction.ReadState(Reader: TReader);
begin
  inherited ReadState(Reader);
  if Reader.Parent is TCustomActionList then
    ActionList := TCustomActionList(Reader.Parent);
end;

procedure TContainedAction.SetIndex(Value: Integer);
var
  CurIndex, Count: Integer;
begin
  CurIndex := GetIndex;
  if CurIndex >= 0 then
  begin
    Count := ActionList.FActions.Count;
    if Value < 0 then Value := 0;
    if Value >= Count then Value := Count - 1;
    if Value <> CurIndex then
    begin
      ActionList.FActions.Delete(CurIndex);
      ActionList.FActions.Insert(Value, Self);
    end;
  end;
end;

procedure TContainedAction.SetCategory(const Value: string);
begin
  if Value <> Category then
  begin
    FCategory := Value;
    if ActionList <> nil then
      ActionList.Change;
  end;
end;

procedure TContainedAction.SetActionList(AActionList: TCustomActionList);
begin
  if AActionList <> ActionList then
  begin
    if ActionList <> nil then ActionList.RemoveAction(Self);
    if AActionList <> nil then AActionList.AddAction(Self);
  end;
end;

procedure TContainedAction.SetParentComponent(AParent: TComponent);
begin
  if not (csLoading in ComponentState) and (AParent is TCustomActionList) then
    ActionList := TCustomActionList(AParent);
end;

function TContainedAction.Execute: Boolean;
begin
  Result := (ActionList <> nil) and ActionList.ExecuteAction(Self) or
    Application.ExecuteAction(Self) or inherited Execute or
    (SendAppMessage(CM_ACTIONEXECUTE, 0, Longint(Self)) = 1);
end;

function TContainedAction.Update: Boolean;
begin
  Result := (ActionList <> nil) and ActionList.UpdateAction(Self) or
    Application.UpdateAction(Self) or inherited Update or
    (SendAppMessage(CM_ACTIONUPDATE, 0, Longint(Self)) = 1);
end;

{ TCustomActionList }

constructor TCustomActionList.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FActions := TList.Create;
  FImageChangeLink := TChangeLink.Create;
  FImageChangeLink.OnChange := ImageListChange;
end;

destructor TCustomActionList.Destroy;
begin
  FImageChangeLink.Free;
  while FActions.Count > 0 do TContainedAction(FActions.Last).Free;
  FActions.Free;
  inherited Destroy;
end;

procedure TCustomActionList.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
  Action: TAction;
begin
  for I := 0 to FActions.Count - 1 do
  begin
    Action := FActions[I];
    if Action.Owner = Root then Proc(Action);
  end;
end;

procedure TCustomActionList.SetChildOrder(Component: TComponent; Order: Integer);
begin
  if FActions.IndexOf(Component) >= 0 then
    (Component as TContainedAction).Index := Order;
end;

function TCustomActionList.GetAction(Index: Integer): TContainedAction;
begin
  Result := FActions[Index];
end;

function TCustomActionList.GetActionCount: Integer;
begin
  Result := FActions.Count;
end;

procedure TCustomActionList.SetAction(Index: Integer; Value: TContainedAction);
begin
  TContainedAction(FActions[Index]).Assign(Value);
end;

procedure TCustomActionList.SetImages(Value: TCustomImageList);
begin
  if Images <> nil then Images.UnRegisterChanges(FImageChangeLink);
  FImages := Value;
  if Images <> nil then
  begin
    Images.RegisterChanges(FImageChangeLink);
    Images.FreeNotification(Self);
  end;
end;

procedure TCustomActionList.ImageListChange(Sender: TObject);
begin
  if Sender = Images then Change;
end;

procedure TCustomActionList.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Operation = opRemove then
    if AComponent = Images then
      Images := nil
    else if (AComponent is TContainedAction) then
      RemoveAction(TContainedAction(AComponent));
end;

procedure TCustomActionList.AddAction(Action: TContainedAction);
begin
  FActions.Add(Action);
  Action.FActionList := Self;
  Action.FreeNotification(Self);
end;

procedure TCustomActionList.RemoveAction(Action: TContainedAction);
begin
  if FActions.Remove(Action) >= 0 then
    Action.FActionList := nil;
end;

procedure TCustomActionList.Change;
var
  I: Integer;
begin
  if Assigned(FOnChange) then FOnChange(Self);
  for I := 0 to FActions.Count - 1 do
    TContainedAction(FActions[I]).Change;
  if csDesigning in ComponentState then
  begin
    if (Owner is TForm) and (TForm(Owner).Designer <> nil) then
      TForm(Owner).Designer.Modified;
  end;
end;

function TCustomActionList.IsShortCut(var Message: TWMKey): Boolean;
var
  I: Integer;
  ShortCut: TShortCut;
  ShiftState: TShiftState;
begin
  ShiftState := KeyDataToShiftState(Message.KeyData);
  ShortCut := Menus.ShortCut(Message.CharCode, ShiftState);
  for I := 0 to FActions.Count - 1 do
    if TCustomAction(FActions[I]).ShortCut = ShortCut then
    begin
      Result := TCustomAction(FActions[I]).Execute;
      Exit;
    end;
  Result := False;
end;

function TCustomActionList.ExecuteAction(Action: TBasicAction): Boolean;
begin
  Result := False;
  if Assigned(FOnExecute) then FOnExecute(Action, Result);
end;

function TCustomActionList.UpdateAction(Action: TBasicAction): Boolean;
begin
  Result := False;
  if Assigned(FOnUpdate) then FOnUpdate(Action, Result);
end;

{ TActionLink }

function TActionLink.IsCaptionLinked: Boolean;
begin
  Result := Action is TCustomAction;
end;

function TActionLink.IsCheckedLinked: Boolean;
begin
  Result := Action is TCustomAction;
end;

function TActionLink.IsEnabledLinked: Boolean;
begin
  Result := Action is TCustomAction;
end;

function TActionLink.IsHelpContextLinked: Boolean;
begin
  Result := Action is TCustomAction;
end;

function TActionLink.IsHintLinked: Boolean;
begin
  Result := Action is TCustomAction;
end;

function TActionLink.IsImageIndexLinked: Boolean;
begin
  Result := Action is TCustomAction;
end;

function TActionLink.IsShortCutLinked: Boolean;
begin
  Result := Action is TCustomAction;
end;

function TActionLink.IsVisibleLinked: Boolean;
begin
  Result := Action is TCustomAction;
end;

procedure TActionLink.SetCaption(const Value: string);
begin
end;

procedure TActionLink.SetChecked(Value: Boolean);
begin
end;

procedure TActionLink.SetEnabled(Value: Boolean);
begin
end;

procedure TActionLink.SetHelpContext(Value: THelpContext);
begin
end;

procedure TActionLink.SetHint(const Value: string);
begin
end;

procedure TActionLink.SetImageIndex(Value: Integer);
begin
end;


procedure TActionLink.SetShortCut(Value: TShortCut);
begin
end;

procedure TActionLink.SetVisible(Value: Boolean);
begin
end;

{ TCustomAction }

constructor TCustomAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDisableIfNoHandler := True;
  FEnabled := True;
  FImageIndex := -1;
  FVisible := True;
end;

destructor TCustomAction.Destroy;
begin
  FImage.Free;
  FMask.Free;
  inherited Destroy;
end;

procedure TCustomAction.AssignTo(Dest: TPersistent);
begin
  if Dest is TCustomAction then
    with TCustomAction(Dest) do
    begin
      Caption := Self.Caption;
      Checked := Self.Checked;
      Enabled := Self.Enabled;
      HelpContext := Self.HelpContext;
      Hint := Self.Hint;
      ImageIndex := Self.ImageIndex;
      ShortCut := Self.ShortCut;
      Visible := Self.Visible;
    end else inherited AssignTo(Dest);
end;

procedure TCustomAction.SetCaption(const Value: string);
var
  I: Integer;
begin
  if Value <> FCaption then
  begin
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TActionLink then
        TActionLink(FClients[I]).SetCaption(Value);
    FCaption := Value;
    Change;
  end;
end;

procedure TCustomAction.SetChecked(Value: Boolean);
var
  I: Integer;
begin
  if Value <> FChecked then
  begin
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TActionLink then
        TActionLink(FClients[I]).SetChecked(Value);
    FChecked := Value;
    Change;
  end;
end;

procedure TCustomAction.SetEnabled(Value: Boolean);
var
  I: Integer;
begin
  if Value <> FEnabled then
  begin
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TActionLink then
        TActionLink(FClients[I]).SetEnabled(Value);
    FEnabled := Value;
    Change;
  end;
end;

procedure TCustomAction.SetHelpContext(Value: THelpContext);
var
  I: Integer;
begin
  if Value <> FHelpContext then
  begin
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TActionLink then
        TActionLink(FClients[I]).SetHelpContext(Value);
    FHelpContext := Value;
    Change;
  end;
end;

procedure TCustomAction.SetHint(const Value: string);
var
  I: Integer;
begin
  if Value <> FHint then
  begin
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TActionLink then
        TActionLink(FClients[I]).SetHint(Value);
    FHint := Value;
    Change;
  end;
end;

procedure TCustomAction.SetImageIndex(Value: TImageIndex);
var
  I: Integer;
begin
  if Value <> FImageIndex then
  begin
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TActionLink then
        TActionLink(FClients[I]).SetImageIndex(Value);
    FImageIndex := Value;
    Change;
  end;
end;

procedure TCustomAction.SetShortCut(Value: TShortCut);
var
  I: Integer;
begin
  if Value <> FShortCut then
  begin
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TActionLink then
        TActionLink(FClients[I]).SetShortCut(Value);
    FShortCut := Value;
    Change;
  end;
end;

procedure TCustomAction.SetVisible(Value: Boolean);
var
  I: Integer;
begin
  if Value <> FVisible then
  begin
    for I := 0 to FClients.Count - 1 do
      if TBasicActionLink(FClients[I]) is TActionLink then
        TActionLink(FClients[I]).SetVisible(Value);
    FVisible := Value;
    Change;
  end;
end;

procedure TCustomAction.SetName(const Value: TComponentName);
var
  ChangeText: Boolean;
begin
  ChangeText := (Name = Caption) and ((Owner = nil) or
    not (csLoading in Owner.ComponentState));
  inherited SetName(Value);
  { Don't update caption to name if we've got clients connected. }
  if ChangeText and (FClients.Count = 0) then Caption := Value;
end;

function TCustomAction.DoHint(var HintStr: string): Boolean;
begin
  Result := True;
  if Assigned(FOnHint) then FOnHint(HintStr, Result);
end;

function TCustomAction.Execute: Boolean;
begin
  Update;
  Result := Enabled and inherited Execute;
end;

end.

