
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit CheckLst;

{$T-,H+,X+}

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls,
  StdCtrls;

type
  TCheckListBox = class(TCustomListBox)
  private
    FAllowGrayed: Boolean;
    FFlat: Boolean;
    FStandardItemHeight: Integer;
    FOnClickCheck: TNotifyEvent;
    FSaveStates: TList;
    procedure ResetItemHeight;
    procedure DrawCheck(R: TRect; AState: TCheckBoxState; AEnabled: Boolean);
    procedure SetChecked(Index: Integer; Checked: Boolean);
    function GetChecked(Index: Integer): Boolean;
    procedure SetState(Index: Integer; AState: TCheckBoxState);
    function GetState(Index: Integer): TCheckBoxState;
    procedure ToggleClickCheck(Index: Integer);
    procedure InvalidateCheck(Index: Integer);
    function CreateWrapper(Index: Integer): TObject;
    function ExtractWrapper(Index: Integer): TObject;
    function GetWrapper(Index: Integer): TObject;
    function HaveWrapper(Index: Integer): Boolean;
    procedure SetFlat(Value: Boolean);
    procedure CNDrawItem(var Message: TWMDrawItem); message CN_DRAWITEM;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure WMDestroy(var Msg : TWMDestroy);message WM_DESTROY;
    function GetItemEnabled(Index: Integer): Boolean;
    procedure SetItemEnabled(Index: Integer; const Value: Boolean);
  protected
    procedure DrawItem(Index: Integer; Rect: TRect;
      State: TOwnerDrawState); override;
    function InternalGetItemData(Index: Integer): Longint; override;
    procedure InternalSetItemData(Index: Integer; AData: Longint); override;
    procedure SetItemData(Index: Integer; AData: LongInt); override;
    function GetItemData(Index: Integer): LongInt; override;
    procedure KeyPress(var Key: Char); override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure ResetContent; override;
    procedure DeleteString(Index: Integer); override;
    procedure ClickCheck; dynamic;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWnd; override;
    procedure DestroyWnd; override;
    function GetCheckWidth: Integer;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Checked[Index: Integer]: Boolean read GetChecked write SetChecked;
    property ItemEnabled[Index: Integer]: Boolean read GetItemEnabled write SetItemEnabled;
    property State[Index: Integer]: TCheckBoxState read GetState write SetState;
  published
    property OnClickCheck: TNotifyEvent read FOnClickCheck write FOnClickCheck;
    property Align;
    property AllowGrayed: Boolean read FAllowGrayed write FAllowGrayed default False;
    property Anchors;
    property BiDiMode;
    property BorderStyle;
    property Color;
    property Columns;
    property Constraints;
    property Ctl3D;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property Flat: Boolean read FFlat write SetFlat default True;
    //property ExtendedSelect;
    property Font;
    property ImeMode;
    property ImeName;
    property IntegralHeight;
    property ItemHeight;
    property Items;
    //property MultiSelect;
    property ParentBiDiMode;
    property ParentColor;
    property ParentCtl3D;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property Sorted;
    property Style;
    property TabOrder;
    property TabStop;
    property TabWidth;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnDrawItem;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMeasureItem;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

implementation

uses Consts;

type
  TCheckListBoxDataWrapper = class
  private
    FData: LongInt;
    FState: TCheckBoxState;
    FDisabled: Boolean;
    procedure SetChecked(Check: Boolean);
    function GetChecked: Boolean;
  public
    class function GetDefaultState: TCheckBoxState;
    property Checked: Boolean read GetChecked write SetChecked;
    property State: TCheckBoxState read FState write FState;
    property Disabled: Boolean read FDisabled write FDisabled;
  end;

var
  FCheckWidth, FCheckHeight: Integer;

procedure GetCheckSize;
begin
  with TBitmap.Create do
    try
      Handle := LoadBitmap(0, PChar(32759));
      FCheckWidth := Width div 4;
      FCheckHeight := Height div 3;
    finally
      Free;
    end;
end;

function MakeSaveState(State: TCheckBoxState; Disabled: Boolean): TObject;
begin
  Result := TObject((Byte(State) shl 16) or Byte(Disabled));
end;

function GetSaveState(AObject: TObject): TCheckBoxState;
begin
  Result := TCheckBoxState(Integer(AObject) shr 16);
end;

function GetSaveDisabled(AObject: TObject): Boolean;
begin
  Result := Boolean(Integer(AObject) and $FF);
end;

{ TCheckListBoxDataWrapper }

procedure TCheckListBoxDataWrapper.SetChecked(Check: Boolean);
begin
  if Check then FState := cbChecked else FState := cbUnchecked;
end;

function TCheckListBoxDataWrapper.GetChecked: Boolean;
begin
  Result := FState = cbChecked;
end;

class function TCheckListBoxDataWrapper.GetDefaultState: TCheckBoxState;
begin
  Result := cbUnchecked;
end;

{ TCheckListBox }

constructor TCheckListBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FFlat := True;
end;

destructor TCheckListBox.Destroy;
begin
  FSaveStates.Free;
  inherited;
end;

procedure TCheckListBox.CreateWnd;
begin
  inherited CreateWnd;
  if FSaveStates <> nil then
  begin
    FSaveStates.Free;
    FSaveStates := nil;
  end;
  ResetItemHeight;
end;
    
procedure TCheckListBox.DestroyWnd;
var
  I: Integer;
begin
  if Items.Count > 0 then
  begin
    FSaveStates := TList.Create;
    for I := 0 to Items.Count - 1 do
      FSaveStates.Add(MakeSaveState(State[I], not ItemEnabled[I]));
  end;
  inherited DestroyWnd;
end;

procedure TCheckListBox.CreateParams(var Params: TCreateParams);
begin
  inherited;
  with Params do
    if Style and (LBS_OWNERDRAWFIXED or LBS_OWNERDRAWVARIABLE) = 0 then
      Style := Style or LBS_OWNERDRAWFIXED;
end;
    
function TCheckListBox.GetCheckWidth: Integer;
begin
  Result := FCheckWidth + 2;
end;

procedure TCheckListBox.CMFontChanged(var Message: TMessage);
begin
  inherited;
  ResetItemHeight;
end;

procedure TCheckListBox.ResetItemHeight;
begin
  if HandleAllocated and (Style = lbStandard) then
  begin
    Canvas.Font := Font;
    FStandardItemHeight := Canvas.TextHeight('Wg');
    Perform(LB_SETITEMHEIGHT, 0, FStandardItemHeight);
  end;
end;
    
procedure TCheckListBox.DrawItem(Index: Integer; Rect: TRect;
  State: TOwnerDrawState);
var
  R: TRect;
  SaveEvent: TDrawItemEvent;
  ACheckWidth: Integer;
  Enable: Boolean;
begin
  ACheckWidth := GetCheckWidth;
  if Index < Items.Count then
  begin
    R := Rect;
    if not UseRightToLeftAlignment then
    begin
      R.Right := Rect.Left;
      R.Left := R.Right - ACheckWidth;
    end
    else
    begin
      R.Left := Rect.Right;
      R.Right := R.Left + ACheckWidth;
    end;
    Enable := Self.Enabled and GetItemEnabled(Index);
    DrawCheck(R, GetState(Index), Enable);
    if not Enable then
      Canvas.Font.Color := clGrayText;
  end;

  if (Style = lbStandard) and Assigned(OnDrawItem) then
  begin
    { Force lbStandard list to ignore OnDrawItem event. }
    SaveEvent := OnDrawItem;
    OnDrawItem := nil;
    try
      inherited;
    finally
      OnDrawItem := SaveEvent;
    end;
  end
  else
    inherited;
end;

procedure TCheckListBox.CNDrawItem(var Message: TWMDrawItem);
begin
  with Message.DrawItemStruct^ do
    if not UseRightToLeftAlignment then
      rcItem.Left := rcItem.Left + GetCheckWidth
    else
      rcItem.Right := rcItem.Right - GetCheckWidth;
  inherited;
end;

procedure TCheckListBox.DrawCheck(R: TRect; AState: TCheckBoxState; AEnabled: Boolean);
var
  DrawState: Integer;
  DrawRect: TRect;
  OldBrushColor: TColor;
  OldBrushStyle: TBrushStyle;
  OldPenColor: TColor;
  Rgn, SaveRgn: HRgn;
begin
  SaveRgn := 0;
  DrawRect.Left := R.Left + (R.Right - R.Left - FCheckWidth) div 2;
  DrawRect.Top := R.Top + (R.Bottom - R.Top - FCheckWidth) div 2;
  DrawRect.Right := DrawRect.Left + FCheckWidth;
  DrawRect.Bottom := DrawRect.Top + FCheckHeight;
  case AState of
    cbChecked:
      DrawState := DFCS_BUTTONCHECK or DFCS_CHECKED;
    cbUnchecked:
      DrawState := DFCS_BUTTONCHECK;
    else // cbGrayed
      DrawState := DFCS_BUTTON3STATE or DFCS_CHECKED;
  end;
  if not AEnabled then
    DrawState := DrawState or DFCS_INACTIVE;
  with Canvas do
  begin
    if Flat then
    begin
      { Remember current clipping region }
      SaveRgn := CreateRectRgn(0,0,0,0);
      GetClipRgn(Handle, SaveRgn);
      { Clip 3d-style checkbox to prevent flicker }
      with DrawRect do
        Rgn := CreateRectRgn(Left + 2, Top + 2, Right - 2, Bottom - 2);
      SelectClipRgn(Handle, Rgn);
      DeleteObject(Rgn);
    end;
    DrawFrameControl(Handle, DrawRect, DFC_BUTTON, DrawState);
    if Flat then
    begin
      SelectClipRgn(Handle, SaveRgn);
      DeleteObject(SaveRgn);
      { Draw flat rectangle in-place of clipped 3d checkbox above }
      OldBrushStyle := Brush.Style;
      OldBrushColor := Brush.Color;
      OldPenColor := Pen.Color;
      Brush.Style := bsClear;
      Pen.Color := clBtnShadow;
      with DrawRect do
        Rectangle(Left + 1, Top + 1, Right - 1, Bottom - 1);
      Brush.Style := OldBrushStyle;
      Brush.Color := OldBrushColor;
      Pen.Color := OldPenColor;
    end;
  end;
end;

procedure TCheckListBox.SetChecked(Index: Integer; Checked: Boolean);
begin
  if Checked <> GetChecked(Index) then
  begin
    TCheckListBoxDataWrapper(GetWrapper(Index)).SetChecked(Checked);
    InvalidateCheck(Index);
  end;
end;

procedure TCheckListBox.SetItemEnabled(Index: Integer; const Value: Boolean);
begin
  if Value <> GetItemEnabled(Index) then
  begin
    TCheckListBoxDataWrapper(GetWrapper(Index)).Disabled := not Value;
    InvalidateCheck(Index);
  end;
end;

procedure TCheckListBox.SetState(Index: Integer; AState: TCheckBoxState);
begin
  if AState <> GetState(Index) then
  begin
    TCheckListBoxDataWrapper(GetWrapper(Index)).State := AState;
    InvalidateCheck(Index);
  end;
end;
    
procedure TCheckListBox.InvalidateCheck(Index: Integer);
var
  R: TRect;
begin
  R := ItemRect(Index);
  if not UseRightToLeftAlignment then
    R.Right := R.Left + GetCheckWidth
  else
    R.Left := R.Right - GetCheckWidth;
  InvalidateRect(Handle, @R, not (csOpaque in ControlStyle));
  UpdateWindow(Handle);
end;
    
function TCheckListBox.GetChecked(Index: Integer): Boolean;
begin
  if HaveWrapper(Index) then
    Result := TCheckListBoxDataWrapper(GetWrapper(Index)).GetChecked
  else
    Result := False;
end;

function TCheckListBox.GetItemEnabled(Index: Integer): Boolean;
begin
  if HaveWrapper(Index) then
    Result := not TCheckListBoxDataWrapper(GetWrapper(Index)).Disabled
  else
    Result := True;
end;

function TCheckListBox.GetState(Index: Integer): TCheckBoxState;
begin
  if HaveWrapper(Index) then
    Result := TCheckListBoxDataWrapper(GetWrapper(Index)).State
  else
    Result := TCheckListBoxDataWrapper.GetDefaultState;
end;

procedure TCheckListBox.KeyPress(var Key: Char);
begin
  inherited;
  if (Key = ' ') then ToggleClickCheck(ItemIndex);
end;
    
procedure TCheckListBox.MouseDown(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
var
  Index: Integer;
begin
  inherited;
  if Button = mbLeft then
  begin
    Index := ItemAtPos(Point(X,Y),True);
    if (Index <> -1) and GetItemEnabled(Index) then
      if not UseRightToLeftAlignment then
      begin
        if X - ItemRect(Index).Left < GetCheckWidth then
          ToggleClickCheck(Index)
      end
      else
      begin
        Dec(X, ItemRect(Index).Right - GetCheckWidth);
        if (X > 0) and (X < GetCheckWidth) then
          ToggleClickCheck(Index)
      end;
  end;
end;

procedure TCheckListBox.ToggleClickCheck;
var
  State: TCheckBoxState;
begin
  if (Index >= 0) and (Index < Items.Count) and GetItemEnabled(Index) then
  begin
    State := Self.State[Index];
    case State of
      cbUnchecked:
        if AllowGrayed then State := cbGrayed else State := cbChecked;
      cbChecked: State := cbUnchecked;
      cbGrayed: State := cbChecked;
    end;
    Self.State[Index] := State;
    ClickCheck;
  end;
end;

procedure TCheckListBox.ClickCheck;
begin
  if Assigned(FOnClickCheck) then FOnClickCheck(Self);
end;

function TCheckListBox.GetItemData(Index: Integer): LongInt;
begin
  Result := 0;
  if HaveWrapper(Index) then
    Result := TCheckListBoxDataWrapper(GetWrapper(Index)).FData;
end;

function TCheckListBox.GetWrapper(Index: Integer): TObject;
begin
  Result := ExtractWrapper(Index);
  if Result = nil then
    Result := CreateWrapper(Index);
end;

function TCheckListBox.ExtractWrapper(Index: Integer): TObject;
begin
  Result := TCheckListBoxDataWrapper(inherited GetItemData(Index));
  if LB_ERR = Integer(Result) then
    raise EListError.CreateResFmt(@SListIndexError, [Index]);
  if (Result <> nil) and (not (Result is TCheckListBoxDataWrapper)) then
    Result := nil;
end;

function TCheckListBox.InternalGetItemData(Index: Integer): LongInt;
begin
  Result := inherited GetItemData(Index);
end;

procedure TCheckListBox.InternalSetItemData(Index: Integer; AData: LongInt);
begin
  inherited SetItemData(Index, AData);
end;

function TCheckListBox.CreateWrapper(Index: Integer): TObject;
begin
  Result := TCheckListBoxDataWrapper.Create;
  inherited SetItemData(Index, LongInt(Result));
end;

function TCheckListBox.HaveWrapper(Index: Integer): Boolean;
begin
  Result := ExtractWrapper(Index) <> nil;
end;

procedure TCheckListBox.SetItemData(Index: Integer; AData: LongInt);
var
  Wrapper: TCheckListBoxDataWrapper;
  SaveState: TObject;
begin
  Wrapper := TCheckListBoxDataWrapper(GetWrapper(Index));
  Wrapper.FData := AData;
  if FSaveStates <> nil then
    if FSaveStates.Count > 0 then
    begin
      SaveState := FSaveStates[0];
      Wrapper.FState := GetSaveState(SaveState);
      Wrapper.FDisabled := GetSaveDisabled(SaveState);
      FSaveStates.Delete(0);
    end;
end;

procedure TCheckListBox.ResetContent;
var
  I: Integer;
begin
  for I := 0 to Items.Count - 1 do
    if HaveWrapper(I) then
      GetWrapper(I).Free;
  inherited;
end;

procedure TCheckListBox.DeleteString(Index: Integer);
begin
  if HaveWrapper(Index) then
    GetWrapper(Index).Free;
  inherited;
end;

procedure TCheckListBox.SetFlat(Value: Boolean);
begin
  if Value <> FFlat then
  begin
    FFlat := Value;
    Invalidate;
  end;
end;

procedure TCheckListBox.WMDestroy(var Msg: TWMDestroy);
var
  i: Integer;
begin
  for i := 0 to Items.Count -1 do
    ExtractWrapper(i).Free;
  inherited;
end;

initialization
  GetCheckSize;

end.
