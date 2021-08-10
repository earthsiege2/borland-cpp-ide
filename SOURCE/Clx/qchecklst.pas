{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QCheckLst;

{$T-,H+,X+}

interface

uses
  Types, SysUtils, Qt, Classes, QGraphics, QControls, QStdCtrls, QImgList;

type
  TCheckListBox = class(TCustomListBox)
  private
    FAllowGrayed: Boolean;
    FFlat: Boolean;
    FOnClickCheck: TNotifyEvent;
    FSaveStates: TList;
    procedure ResetItemHeight;
    procedure SetChecked(Index: Integer; AChecked: Boolean);
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
    function GetItemEnabled(Index: Integer): Boolean;
    procedure SetItemEnabled(Index: Integer; const Value: Boolean);
  protected
    procedure ClickCheck; dynamic;
    procedure CreateWidget; override;
    procedure DeleteString(Index: Integer); override;
    procedure DrawCheck(R: TRect; AState: TCheckBoxState; AEnabled: Boolean); virtual;
    function DrawItem(Index: Integer; Rect: TRect;
      State: TOwnerDrawState): Boolean; override;
    function GetCheckWidth: Integer; virtual;
    function GetItemData(Index: Integer): LongInt; override;
    procedure KeyPress(var Key: Char); override;
    procedure MeasureItem(Control: TWinControl; Index: Integer;
      var Height, Width: Integer); override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure ResetContent; override;
    procedure SetItemData(Index: Integer; AData: LongInt); override;
    procedure SaveWidgetState; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Checked[Index: Integer]: Boolean read GetChecked write SetChecked;
    property ItemEnabled[Index: Integer]: Boolean read GetItemEnabled write SetItemEnabled;
    property State[Index: Integer]: TCheckBoxState read GetState write SetState;
  published
    property Style; { Must be published before Items }
    property Align;
    property AllowGrayed: Boolean read FAllowGrayed write FAllowGrayed default False;
    property Anchors;
    property BorderStyle;
    property Color;
    property Columns;
    property ColumnLayout;
    property Constraints;
    property DragMode;
    property Enabled;
    property Flat: Boolean read FFlat write SetFlat default True;
    property Font;
    property ItemHeight;
    property Items;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property RowLayout;
    property Rows;
    property ShowHint;
    property Sorted;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnClick;
    property OnClickCheck: TNotifyEvent read FOnClickCheck write FOnClickCheck;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnDrawItem;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnMeasureItem;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
  end;

implementation

uses QConsts;

{$R QCheckLst.res}

const
  NumImages = 10;

type
  TCheckListImage = (ciCheck, ciCheckGray, ciGray, ciUncheck);

var
  DefImages: TImageList = nil;
  FCheckHeight,
  FCheckWidth: Integer;
  ImageResNames: array[0..NumImages-1] of PChar = (
    'CLB_CHK', 'CLB_CHK3D', 'CLB_DIS', 'CLB_DIS3D', 'CLB_GRY', 'CLB_GRY3D',
    'CLB_GRYCHK', 'CLB_GRYCHK3D', 'CLB_UNCHK', 'CLB_UNCHK3D');

function DefaultImages: TImageList;
var
  B: TBitmap;
  I: Integer;
begin
  if not Assigned(DefImages) then
  begin
    DefImages := TImageList.CreateSize(12, 12);
    B := TBitmap.Create;
    try
      for I := 0 to NumImages - 1 do
      begin
        B.LoadFromResourceName(HInstance, ImageResNames[I]);
        DefImages.AddMasked(B, clOlive);
      end;
    finally
      B.Free;
    end;
  end;
  Result := DefImages;
end;

procedure GetCheckSize;
begin
  FCheckHeight := DefaultImages.Height;
  FCheckWidth := DefaultImages.Width;
end;

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

procedure TCheckListBox.CreateWidget;
begin
  inherited CreateWidget;
  ResetItemHeight;
end;

function TCheckListBox.GetCheckWidth: Integer;
begin
  Result := FCheckWidth + 2;
end;

procedure TCheckListBox.ResetItemHeight;
begin
end;

function TCheckListBox.DrawItem(Index: Integer; Rect: TRect;
  State: TOwnerDrawState): Boolean;
var
  R: TRect;
  SaveEvent: TDrawItemEvent;
  ACheckWidth: Integer;
  Enable: Boolean;
begin
  if (Style = lbStandard) and Assigned(OnDrawItem) then
  begin
    { Force lbStandard list to ignore OnDrawItem event. }
    SaveEvent := OnDrawItem;
    OnDrawItem := nil;
    try
      Result := inherited DrawItem(Index, Rect, State);
    finally
      OnDrawItem := SaveEvent;
    end;
  end
  else begin
    R := Rect;
    R.Left := GetCheckWidth;
    Result := inherited DrawItem(Index, R, State);
  end;

  Enable := True;
  ACheckWidth := GetCheckWidth;
  if Index < Items.Count then
  begin
    R := Rect;
    R.Right := R.Left + ACheckWidth;
    Rect.Left := R.Right + 1;
    Enable := (Self.Enabled and GetItemEnabled(Index));
    Canvas.Brush.Color := clWindow;
    Canvas.FillRect(R);
    DrawCheck(R, GetState(Index), Enable);
  end;

  if Result then Exit;

  if odSelected in State then
  begin
    Canvas.Brush.Color := clHighlight;
    if Enable then
      Canvas.Font.Color := clHighlightText
    else
      Canvas.Font.Color := clGray;
  end
  else begin
    Canvas.Brush.Color := Color;
    if not Enable then
      Canvas.Font.Color := clGray
    else
      Canvas.Font.Color := Font.Color;
  end;

  Canvas.FillRect(Rect);
  Canvas.TextRect(Rect, Rect.Left, Rect.Top, Items[Index],
    Integer(AlignmentFlags_AlignLeft) or Integer(AlignmentFlags_AlignVCenter));

  if odFocused in State then Canvas.DrawFocusRect(Rect);
  Result := True;
end;

procedure TCheckListBox.DrawCheck(R: TRect; AState: TCheckBoxState; AEnabled: Boolean);
const
  ImageIndex: array[Boolean, Boolean, TCheckBoxState] of Integer =
    (((3, 7, 7), (2, 6, 6)), ((9, 1, 5), (8, 0, 4)));
var
  DrawRect: TRect;
begin
  DrawRect.Left := R.Left + (R.Right - R.Left - FCheckWidth) div 2;
  DrawRect.Top := R.Top + (R.Bottom - R.Top - FCheckWidth) div 2;
  DrawRect.Right := DrawRect.Left + FCheckWidth;
  DrawRect.Bottom := DrawRect.Top + FCheckHeight;

  if Flat then
  begin
    Inc(DrawRect.Left);
    Inc(DrawRect.Top);
    Dec(DrawRect.Right);
    Dec(DrawRect.Bottom);
  end;

  Canvas.Brush.Color := clWindow;
  Canvas.FillRect(DrawRect);

  if Flat then
  begin
    Dec(DrawRect.Left);
    Dec(DrawRect.Top);
  end;

  DefaultImages.Draw(Canvas, DrawRect.Left, DrawRect.Top, ImageIndex[AEnabled, FFlat, AState]);
end;

procedure TCheckListBox.SetChecked(Index: Integer; AChecked: Boolean);
begin
  if AChecked <> GetChecked(Index) then
  begin
    TCheckListBoxDataWrapper(GetWrapper(Index)).SetChecked(AChecked);
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
  R.Right := R.Left + GetCheckWidth;
  InvalidateRect(R, not (csOpaque in ControlStyle));
  Update;
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
    Index := ItemAtPos(Point(X,Y), True);
    if (Index <> -1) and GetItemEnabled(Index) then
      if X - ItemRect(Index).Left < GetCheckWidth then
      begin
        ItemIndex := Index;
        ToggleClickCheck(Index);
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
  if Integer(Result) = -1 then
    raise EListError.CreateResFmt(@SListIndexError, [Index]);
  if (Result <> nil) and (not (Result is TCheckListBoxDataWrapper)) then
    Result := nil;
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
    Update;
  end;
end;

procedure TCheckListBox.MeasureItem(Control: TWinControl; Index: Integer;
  var Height, Width: Integer);
begin
  Width := Width + GetCheckWidth;
  inherited MeasureItem(Control, Index, Height, Width);
end;

procedure TCheckListBox.SaveWidgetState;
var
  I: Integer;
begin
  inherited SaveWidgetState;
  if Items.Count > 0 then
  begin
    FSaveStates := TList.Create;
    for I := 0 to Items.Count - 1 do
      FSaveStates.Add(MakeSaveState(State[I], not ItemEnabled[I]));
  end;
end;

destructor TCheckListBox.Destroy;
var
  I: Integer;
begin
  for I := 0 to Items.Count - 1 do
    if HaveWrapper(I) then
      GetWrapper(I).Free;
  FSaveStates.Free;
  inherited Destroy;
end;

initialization

  GetCheckSize;

finalization

  FreeAndNil(DefImages);

end.
