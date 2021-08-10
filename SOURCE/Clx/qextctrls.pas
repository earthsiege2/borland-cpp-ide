{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QExtCtrls;

{$S-,W-,R-,H+,X+}

interface

uses
  SysUtils, Types, Classes, Qt, QTypes, QControls, QGraphics,
  QStdCtrls, QForms, QConsts;

type
  TShapeType = (stRectangle, stSquare, stRoundRect, stRoundSquare,
    stEllipse, stCircle);

  TShape = class(TGraphicControl)
  private
    FShape: TShapeType;
    procedure SetBrush(Value: TBrush);
    procedure SetPen(Value: TPen);
    procedure SetShape(Value: TShapeType);
    function GetBrush: TBrush;
    function GetPen: TPen;
  protected
    procedure ColorChanged; override;
    procedure Paint; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    procedure StyleChanged(Sender: TObject);
    property Align;
    property Anchors;
    property Brush: TBrush read GetBrush write SetBrush;
    property Color;
    property Constraints;
    property DragMode;
    property Enabled;
    property ParentShowHint;
    property Pen: TPen read GetPen write SetPen;
    property Shape: TShapeType read FShape write SetShape default stRectangle;
    property ShowHint;
    property Visible;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
  end;

  TPaintBox = class(TGraphicControl)
  private
    FOnPaint: TNotifyEvent;
  protected
    procedure Paint; override;
  public
    constructor Create(AOwner: TComponent); override;
    property Canvas;
  published
    property Align;
    property Anchors;
    property Color;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnPaint: TNotifyEvent read FOnPaint write FOnPaint;
    property OnStartDrag;
  end;

  TBevelStyle = (bsLowered, bsRaised);
  TBevelShape = (bsBox, bsFrame, bsTopLine, bsBottomLine, bsLeftLine,
    bsRightLine, bsSpacer);

  TBevel = class(TGraphicControl)
  private
    FStyle: TBevelStyle;
    FShape: TBevelShape;
    procedure SetStyle(Value: TBevelStyle);
    procedure SetShape(Value: TBevelShape);
  protected
    procedure Paint; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Align;
    property Anchors;
    property Constraints;
    property ParentShowHint;
    property Shape: TBevelShape read FShape write SetShape default bsBox;
    property ShowHint;
    property Style: TBevelStyle read FStyle write SetStyle default bsLowered;
    property Visible;
  end;

  TTimer = class(THandleComponent)
  private
    FInterval: Cardinal;
    FOnTimer: TNotifyEvent;
    FEnabled: Boolean;
    procedure SetEnabled(Value: Boolean);
    procedure SetInterval(Value: Cardinal);
  protected
    procedure CreateWidget; override;
    function GetHandle: QTimerH;
    procedure HookEvents; override;
    procedure Timer; virtual; cdecl;
  public
    constructor Create(AOwner: TComponent); override;
    property Handle: QTimerH read GetHandle;
  published
    property Enabled: Boolean read FEnabled write SetEnabled default True;
    property Interval: Cardinal read FInterval write SetInterval default 1000;
    property OnTimer: TNotifyEvent read FOnTimer write FOnTimer;
  end;

  TPanelBevel = TBevelCut;
  TBevelWidth = 1..MaxInt;
  TBorderWidth = 0..MaxInt;

  TCustomPanel = class(TCustomControl)
  private
    FBevelInner: TPanelBevel;
    FBevelOuter: TPanelBevel;
    FBevelWidth: TBevelWidth;
    FBorderWidth: TBorderWidth;
    FBorderStyle: TControlBorderStyle;
    FAlignment: TAlignment;
    FCaption: TCaption;
    procedure SetAlignment(const Value: TAlignment);
    procedure SetBevelInner(const Value: TPanelBevel);
    procedure SetBevelOuter(const Value: TPanelBevel);
    procedure SetBevelWidth(const Value: TBevelWidth);
    procedure SetBorderWidth(const Value: TBorderWidth);
    procedure SetBorderStyle(const Value: TControlBorderStyle);
    function GetHandle: QFrameH;
  protected
    procedure AdjustClientRect(var Rect: TRect); override;
    function GetText: TCaption; override;
    procedure SetText(const Value: TCaption); override;
    procedure CreateWidget; override;
    procedure Paint; override;
    property Alignment: TAlignment read FAlignment write SetAlignment default taCenter;
    property BevelInner: TPanelBevel read FBevelInner write SetBevelInner default bvNone;
    property BevelOuter: TPanelBevel read FBevelOuter write SetBevelOuter default bvRaised;
    property BevelWidth: TBevelWidth read FBevelWidth write SetBevelWidth default 1;
    property BorderWidth: TBorderWidth read FBorderWidth write SetBorderWidth default 0;
    property BorderStyle: TControlBorderStyle read FBorderStyle write SetBorderStyle default bsNone;
    property Color default clBtnFace;
    property Caption read GetText write SetText;
    property Handle: QFrameH read GetHandle;
    property ParentColor default True;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Invalidate; override;
  end;

  TPanel = class(TCustomPanel)
  published
    property Align default alNone;
    property Alignment;
    property Anchors;
    property BevelInner;
    property BevelOuter;
    property BevelWidth;
    property Bitmap;
    property BorderWidth;
    property BorderStyle;
    property Caption;
    property Color default clBackground;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property TabStop default False;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnResize;
    property OnStartDrag;
  end;

  TImage = class(TGraphicControl)
  private
    FPicture: TPicture;
    FOnProgress: TProgressEvent;
    FStretch: Boolean;
    FCenter: Boolean;
    FIncrementalDisplay: Boolean;
    FTransparent: Boolean;
    FDrawing: Boolean;
    FAutoSize: Boolean;
    function GetCanvas: TCanvas;
    procedure PictureChanged(Sender: TObject);
    procedure SetCenter(Value: Boolean);
    procedure SetPicture(Value: TPicture);
    procedure SetStretch(Value: Boolean);
    procedure SetTransparent(Value: Boolean);
    procedure SetAutoSize(const Value: Boolean);
  protected
    procedure DoAutoSize;
    function DestRect: TRect;
    function DoPaletteChange: Boolean;
    procedure Paint; override;
    procedure Progress(Sender: TObject; Stage: TProgressStage;
      PercentDone: Byte; RedrawNow: Boolean; const R: TRect;
      const Msg: WideString); dynamic;
    procedure Resize; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Canvas: TCanvas read GetCanvas;
  published
    property Align;
    property Anchors;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default False;
    property Center: Boolean read FCenter write SetCenter default False;
    property Constraints;
    property DragMode;
    property Enabled;
    property IncrementalDisplay: Boolean read FIncrementalDisplay write FIncrementalDisplay default False;
    property ParentShowHint;
    property Picture: TPicture read FPicture write SetPicture;
    property PopupMenu;
    property ShowHint;
    property Stretch: Boolean read FStretch write SetStretch default False;
    property Transparent: Boolean read FTransparent write SetTransparent default False;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnProgress: TProgressEvent read FOnProgress write FOnProgress;
    property OnStartDrag;
  end;

  NaturalNumber = 1..High(Integer);

  TCanResizeEvent = procedure(Sender: TObject; var NewSize: Integer;
    var Accept: Boolean) of object;

  TResizeStyle = (rsNone, rsLine, rsUpdate, rsPattern);

  TSplitter = class(TGraphicControl)
  private
    FOldCur: TCursor;
    FActiveControl: TWidgetControl;
    FAutoSnap: Boolean;
    FBeveled: Boolean;
    FBrush: TBrush;
    FControl: TControl;
    FDownPos: TPoint;
    FMinSize: NaturalNumber;
    FMaxSize: Integer;
    FNewSize: Integer;
    FOldKeyDown: TKeyEvent;
    FOldSize: Integer;
    FResizeStyle: TResizeStyle;
    FSplit: Integer;
    FOnCanResize: TCanResizeEvent;
    FOnMoved: TNotifyEvent;
    FOnPaint: TNotifyEvent;
    procedure CalcSplitSize(X, Y: Integer; var NewSize, Split: Integer);
    procedure DrawLine;
    function FindControl: TControl;
    procedure FocusKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure SetBeveled(Value: Boolean);
    procedure UpdateControlSize;
    procedure UpdateSize(X, Y: Integer);
    function CanResize(var NewSize: Integer): Boolean;
  protected
    function DoCanResize(var NewSize: Integer): Boolean; virtual;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure Paint; override;
    procedure RequestAlign; override;
    procedure StopSizing; dynamic;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Canvas;
  published
    property Align default alLeft;
    property Anchors;
    property AutoSnap: Boolean read FAutoSnap write FAutoSnap default True;
    property Beveled: Boolean read FBeveled write SetBeveled default False;
    property Color default clBtnFace;
    property Constraints;
    property Cursor default crHSplit;
    property Height default 22;
    property MinSize: NaturalNumber read FMinSize write FMinSize default 30;
    property ParentColor default False;
    property ParentShowHint;
    property ResizeStyle: TResizeStyle read FResizeStyle write FResizeStyle default rsPattern;
    property ShowHint;
    property Visible;
    property Width default 3;
    property OnCanResize: TCanResizeEvent read FOnCanResize write FOnCanResize;
    property OnMoved: TNotifyEvent read FOnMoved write FOnMoved;
    property OnPaint: TNotifyEvent read FOnPaint write FOnPaint;
  end;

  TOrientation = (orVertical, orHorizontal);

  TCustomRadioGroup = class(TCustomGroupBox)
  private
    FItems: TStrings;
    FButtons: TList;
    FItemIndex: Integer;
    FLastIndex: Integer;
    FColumns: Integer;
    FOrientation: TOrientation;
    procedure ClickedHook(Index: Integer); cdecl;
    procedure ForceLayout;
    function GetHandle: QButtonGroupH;
    procedure ItemsChange(Sender: TObject);
    procedure SetButtonCount(Value: Integer);
    procedure SetColumns(Value: Integer);
    procedure SetItemIndex(Value: Integer);
    procedure SetItems(Value: TStrings);
    procedure UpdateButtons;
    procedure SetOrientation(const Value: TOrientation);
  protected
    function CanModify: Boolean; virtual;
    procedure CreateWidget; override;
    procedure CursorChanged; override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure HookEvents; override;
    procedure Loaded; override;
    procedure RestoreWidgetState; override;
    procedure SaveWidgetState; override;
    procedure ShowingChanged; override;
    function WantKey(Key: Integer; Shift: TShiftState;
      const KeyText: WideString): Boolean; override;
    property Columns: Integer read FColumns write SetColumns default 1;
    property ItemIndex: Integer read FItemIndex write SetItemIndex default -1;
    property Items: TStrings read FItems write SetItems;
    property Orientation: TOrientation read FOrientation write SetOrientation
      default orVertical;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure SetFocus; override;
    property Handle: QButtonGroupH read GetHandle;
  end;

  TRadioGroup = class(TCustomRadioGroup)
  published
    property Items;
    property Orientation;
    property Align default alNone;
    property Alignment default taLeftJustify;
    property Bitmap;
    property Anchors;
    property Caption;
    property Color default clBackground;
    property Columns;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property ItemIndex;
    property Masked default False;
    property ParentColor default True;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint default False;
    property TabOrder;
    property TabStop default True;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnStartDrag;
  end;

{ TControlBar }

  TBandPaintOption = (bpoGrabber, bpoFrame);
  TBandPaintOptions = set of TBandPaintOption;

  TBandDragEvent = procedure (Sender: TObject; Control: TControl;
    var Drag: Boolean) of object;
  TBandInfoEvent = procedure (Sender: TObject; Control: TControl;
    var Insets: TRect; var PreferredSize, RowCount: Integer) of object;
  TBandMoveEvent = procedure (Sender: TObject; Control: TControl;
    var ARect: TRect) of object;
  TBandPaintEvent = procedure (Sender: TObject; Control: TControl;
    Canvas: TCanvas; var ARect: TRect; var Options: TBandPaintOptions) of object;

  TRowSize = 1..MaxInt;

  TCustomControlBar = class(TCustomControl)
  private
    FAligning: Boolean;
    FAutoDrag: Boolean;
    FGrabCursor: TCursor;
    FSaveCursor: TCursor;
    FDockingControl: TControl;
    FDragControl: TControl;
    FDragOffset: TPoint;
    FDrawing: Boolean;
    FItems: TList;
    FPicture: TPicture;
    FRowSize: TRowSize;
    FRowSnap: Boolean;
    FOnBandDrag: TBandDragEvent;
    FOnBandInfo: TBandInfoEvent;
    FOnBandMove: TBandMoveEvent;
    FOnBandPaint: TBandPaintEvent;
    FOnPaint: TNotifyEvent;
    FBevelEdges: TBevelEdges;
    FBevelOuter: TBevelCut;
    FBevelInner: TBevelCut;
    FAutoSize: Boolean;
    procedure AdjustSize; reintroduce;
    procedure MarkDirty;
    procedure DoAlignControl(AControl: TControl);
    function FindPos(AControl: TControl): Pointer;
    function HitTest2(X, Y: Integer): Pointer;
    function HitTest3(X, Y: Integer): TControl;
    procedure DockControl(AControl: TControl; const ARect: TRect;
      BreakList, IndexList, SizeList: TList; Parent: Pointer;
      ChangedPriorBreak: Boolean; Insets: TRect; PreferredSize,
      RowCount: Integer; Existing: Boolean);
    function EdgeSpacing(Edge: TBevelEdge): Integer;
    procedure PictureChanged(Sender: TObject);
    procedure SetPicture(const Value: TPicture);
    procedure SetRowSize(Value: TRowSize);
    procedure SetRowSnap(Value: Boolean);
    procedure UnDockControl(AControl: TControl);
    function UpdateItems(AControl: TControl): Boolean;
    procedure SetBevelEdges(const Value: TBevelEdges);
    procedure SetBevelInner(const Value: TBevelCut);
    procedure SetBevelOuter(const Value: TBevelCut);
    procedure SetAutoSize(const Value: Boolean);
  protected
    procedure AlignControls(AControl: TControl; var ARect: TRect); override;
    procedure ControlsListChanged(Control: TControl; Inserting: Boolean); override;
    procedure DoBandMove(Control: TControl; var ARect: TRect); virtual;
    procedure DoBandPaint(Control: TControl; Canvas: TCanvas; var ARect: TRect;
      var Options: TBandPaintOptions); virtual;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    function DragControl(AControl: TControl; X, Y: Integer;
      KeepCapture: Boolean = False): Boolean; virtual;
    function GetClientRect: TRect; override;
    procedure GetControlInfo(AControl: TControl; var Insets: TRect;
      var PreferredSize, RowCount: Integer); virtual;
    function HitTest(X, Y: Integer): TControl; reintroduce;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure Paint; override;
    procedure PaintControlFrame(Canvas: TCanvas; AControl: TControl;
      var ARect: TRect); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure FlipChildren(AllLevels: Boolean); override;
    procedure StickControls; virtual;
    property Picture: TPicture read FPicture write SetPicture;
  protected
    property AutoSize: Boolean read FAutoSize write SetAutoSize default False;
    property GrabCursor: TCursor read FGrabCursor write FGrabCursor default crDefault;
    property BevelEdges: TBevelEdges read FBevelEdges write SetBevelEdges
      default [beLeft, beTop, beRight, beBottom];
    property BevelInner: TBevelCut read FBevelInner write SetBevelInner default bvRaised;
    property BevelOuter: TBevelCut read FBevelOuter write SetBevelOuter default bvLowered;
    property Color default clBtnFace;
    property ParentColor default False;
    property RowSize: TRowSize read FRowSize write SetRowSize default 26;
    property RowSnap: Boolean read FRowSnap write SetRowSnap default True;
    property OnBandDrag: TBandDragEvent read FOnBandDrag write FOnBandDrag;
    property OnBandInfo: TBandInfoEvent read FOnBandInfo write FOnBandInfo;
    property OnBandMove: TBandMoveEvent read FOnBandMove write FOnBandMove;
    property OnBandPaint: TBandPaintEvent read FOnBandPaint write FOnBandPaint;
    property OnPaint: TNotifyEvent read FOnPaint write FOnPaint;
  end;

  TControlBar = class(TCustomControlBar)
  public
    property Canvas;
  published
    property Align;
    property Anchors;
    property AutoSize;
    property Color;
    property Constraints;
    property DragMode;
    property BevelEdges;
    property BevelInner;
    property BevelOuter;
    property Enabled;
    property GrabCursor;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property Picture;
    property PopupMenu;
    property RowSize;
    property RowSnap;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnBandDrag;
    property OnBandInfo;
    property OnBandMove;
    property OnBandPaint;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnPaint;
    property OnResize;
    property OnStartDrag;
  end;

procedure Frame3D(Canvas: TCanvas; var Rect: TRect;
  TopColor, BottomColor: TColor; Width: Integer);

implementation

{ Utility routines }

procedure Frame3D(Canvas: TCanvas; var Rect: TRect; TopColor, BottomColor: TColor;
  Width: Integer);

  procedure DoRect;
  var
    TopRight, BottomLeft: TPoint;
  begin
    with Canvas, Rect do
    begin
      TopRight.X := Right;
      TopRight.Y := Top;
      BottomLeft.X := Left;
      BottomLeft.Y := Bottom;
      Pen.Color := TopColor;
      PolyLine([BottomLeft, TopLeft, TopRight]);
      Pen.Color := BottomColor;
      Dec(BottomLeft.X);
      PolyLine([TopRight, BottomRight, BottomLeft]);
    end;
  end;

begin
  Canvas.Pen.Width := 1;
  Dec(Rect.Bottom);
  Dec(Rect.Right);
  while Width > 0 do
  begin
    Dec(Width);
    DoRect;
    InflateRect(Rect, -1, -1);
  end;
  Inc(Rect.Bottom);
  Inc(Rect.Right);
end;

{ TCustomPanel }

function TCustomPanel.GetHandle: QFrameH;
begin
  HandleNeeded;
  Result := QFrameH(FHandle);
end;

procedure TCustomPanel.SetAlignment(const Value: TAlignment);
begin
  if FAlignment <> Value then
  begin
    FAlignment := Value;
    Invalidate;
  end;
end;

procedure TCustomPanel.SetBevelWidth(const Value: TBevelWidth);
begin
  if FBevelWidth <> Value then
  begin
    FBevelWidth := Value;
    Invalidate;
  end;
end;

procedure TCustomPanel.SetBevelInner(const Value: TPanelBevel);
begin
  if BevelInner <> Value then
  begin
    FBevelInner := Value;
    Invalidate;
  end;
end;

procedure TCustomPanel.SetBevelOuter(const Value: TPanelBevel);
begin
  if BevelOuter <> Value then
  begin
    FBevelOuter := Value;
    Invalidate;
  end;
end;

procedure TCustomPanel.SetBorderWidth(const Value: TBorderWidth);
begin
  if FBorderWidth <> Value then
  begin
    FBorderWidth := Value;
    Realign;
    Invalidate;
  end;
end;

procedure TCustomPanel.Paint;
const
  Alignments: array[TAlignment] of Longint = (Integer(AlignmentFlags_AlignLeft),
                                              Integer(AlignmentFlags_AlignRight),
                                              Integer(AlignmentFlags_AlignHCenter));
  cColor: array [Boolean] of Integer = (clBtnShadow, clBtnHighlight);
var
  Rect: TRect;
  InflateSize: Integer;
begin
  Rect := GetClientRect;
  if BorderStyle = bsSingle then
  begin
    Frame3D(Canvas, Rect, clBlack, clBlack, 1);
    Inc(Rect.Top);
    Inc(Rect.Left);
  end;

  if BevelOuter <> bvNone then
    Frame3D(Canvas, Rect, cColor[not (BevelOuter = bvLowered)],
    cColor[BevelOuter = bvLowered], BevelWidth);

  if BevelInner <> bvNone then
  begin
    Frame3D(Canvas, Rect, Color, Color, BorderWidth);
    Frame3D(Canvas, Rect, cColor[not (BevelInner = bvLowered)],
    cColor[BevelInner = bvLowered], BevelWidth);
  end;

  with Canvas do
  begin
    InflateSize := -(BevelWidth div 2);
    InflateRect(Rect, InflateSize, InflateSize);
    if (Bitmap = nil) or Bitmap.Empty then
    begin
      Brush.Color := Color;
      if Color <> clBackground then
        FillRect(Rect)
      else
        QWidget_erase(Self.Handle, @Rect);
    end;
    Font := Self.Font;
    if Font.Color <> clBlack then { for the caption }
      Pen.Color := Font.Color
    else
      Pen.Color := clText;
    TextRect(ClientRect, 0, 0, Caption, Integer(AlignmentFlags_ExpandTabs) or
                                    Integer(AlignmentFlags_AlignVCenter) or
                                    Alignments[FAlignment]);
  end;
end;

procedure TCustomPanel.AdjustClientRect(var Rect: TRect);
var
  BevelSize: Integer;
begin
  inherited AdjustClientRect(Rect);
  InflateRect(Rect, -BorderWidth, -BorderWidth);
  BevelSize := 0;
  if BevelOuter <> bvNone then
    Inc(BevelSize, BevelWidth);
  if BevelInner <> bvNone then
    Inc(BevelSize, BevelWidth);
  InflateRect(Rect, -BevelSize, -BevelSize);
end;

procedure TCustomPanel.SetBorderStyle(const Value: TControlBorderStyle);
begin
  if FBorderStyle <> Value then
  begin
    FBorderStyle := Value;
    Invalidate;
  end;
end;

procedure TCustomPanel.CreateWidget;
begin
  FHandle := QFrame_create(ParentWidget, nil, WidgetFlags, False);
end;

constructor TCustomPanel.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csAcceptsControls, csCaptureMouse, csClickEvents,
    csSetCaption, csOpaque, csDoubleClicks, csReplicatable, csNoFocus];
  FBevelOuter := bvRaised;
  FBevelInner := bvNone;
  FBevelWidth := 1;
  FAlignment := taCenter;
  Height := 41;
  Width := 185;
  ParentColor := True;
end;

procedure TCustomPanel.Invalidate;
begin
  inherited;
  InvalidateRect(ClientRect, True);
end;

function TCustomPanel.GetText: TCaption;
begin
  Result := FCaption;
end;

procedure TCustomPanel.SetText(const Value: TCaption);
begin
  if Caption <> Value then
  begin
    FCaption := Value; 
    TextChanged;
    Invalidate;
  end;
end;

{ TShape }

constructor TShape.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csReplicatable, csOpaque];
  Width := 65;
  Height := 65;
  Canvas.Pen.Width := 0;
  Canvas.Pen.OnChange := StyleChanged;
  Canvas.Brush.OnChange := StyleChanged;
  ParentColor := False;
end;

procedure TShape.Paint;
var
  X, Y, W, H, S: Integer;
begin
  with Canvas do
  begin
    X := Pen.Width div 2;
    Y := X;
    W := Width - Pen.Width + 1;
    H := Height - Pen.Width + 1;
    if Pen.Width = 0 then
    begin
      Dec(W);
      Dec(H);
    end;
    if W < H then S := W else S := H;
    if FShape in [stSquare, stRoundSquare, stCircle] then
    begin
      Inc(X, (W - S) div 2);
      Inc(Y, (H - S) div 2);
      W := S;
      H := S;
    end;
    case FShape of
      stRectangle, stSquare:
        Rectangle(X, Y, X + W, Y + H);
      stRoundRect, stRoundSquare:
        RoundRect(X, Y, X + W, Y + H, S div 4, S div 4);
      stCircle, stEllipse:
        Ellipse(X, Y, X + W, Y + H);
    end;
  end;
end;

procedure TShape.StyleChanged(Sender: TObject);
begin
  Invalidate;
end;

procedure TShape.SetBrush(Value: TBrush);
begin
  Canvas.Brush.Assign(Value);
end;

procedure TShape.SetPen(Value: TPen);
begin
  Canvas.Pen.Assign(Value);
end;

procedure TShape.SetShape(Value: TShapeType);
begin
  if FShape <> Value then
  begin
    FShape := Value;
    Invalidate;
  end;
end;

function TShape.GetBrush: TBrush;
begin
  Result := Canvas.Brush;
end;

function TShape.GetPen: TPen;
begin
  Result := Canvas.Pen;
end;

procedure TShape.ColorChanged;
begin
  Brush.Color := Color;
  inherited;
end;

{ TPaintBox }

constructor TPaintBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csReplicatable];
  Width := 105;
  Height := 105;
end;

procedure TPaintBox.Paint;
begin
  Canvas.Font := Font;
  Canvas.Brush.Color := Color;
  if csDesigning in ComponentState then
    with Canvas do
    begin
      Pen.Style := psDash;
      Brush.Style := bsClear;
      Rectangle(0, 0, Width, Height);
    end;
  if Assigned(FOnPaint) then FOnPaint(Self);
end;

{ TBevel }

constructor TBevel.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csReplicatable];
  FStyle := bsLowered;
  FShape := bsBox;
  Width := 50;
  Height := 50;
end;

procedure TBevel.SetStyle(Value: TBevelStyle);
begin
  if Value <> FStyle then
  begin
    FStyle := Value;
    Invalidate;
  end;
end;

procedure TBevel.SetShape(Value: TBevelShape);
begin
  if Value <> FShape then
  begin
    FShape := Value;
    Invalidate;
  end;
end;

procedure TBevel.Paint;
var
  Color1, Color2: TColor;
  Temp: TColor;

  procedure BevelRect(const R: TRect);
  begin
    with Canvas do
    begin
      Pen.Color := Color1;
      PolyLine([Types.Point(R.Left, R.Bottom), Types.Point(R.Left, R.Top),
        Types.Point(R.Right, R.Top)]);
      Pen.Color := Color2;
      PolyLine([Types.Point(R.Right, R.Top), Types.Point(R.Right, R.Bottom),
        Types.Point(R.Left, R.Bottom)]);
    end;
  end;

  procedure BevelLine(C: TColor; X1, Y1, X2, Y2: Integer);
  begin
    with Canvas do
    begin
      Pen.Color := C;
      MoveTo(X1, Y1);
      LineTo(X2, Y2);
    end;
  end;

begin
  with Canvas do
  begin
    if (csDesigning in ComponentState) then
    begin
      if (FShape = bsSpacer) then
      begin
        Pen.Style := psDot;
        Pen.Mode  := pmCopy;
        Pen.Color := clBlack;
        Brush.Style := bsClear;
        Rectangle(0, 0, ClientWidth, ClientHeight);
        Exit;
      end
      else
      begin
        Pen.Style := psSolid;
        Pen.Mode  := pmCopy;
        Pen.Color := clBlack;
        Brush.Style := bsSolid;
      end;
    end;

    Pen.Width := 1;

    if FStyle = bsLowered then
    begin
      Color1 := clBtnShadow;
      Color2 := clBtnHighlight;
    end
    else
    begin
      Color1 := clBtnHighlight;
      Color2 := clBtnShadow;
    end;

    case FShape of
      bsBox: BevelRect(Types.Rect(0, 0, Width - 1, Height - 1));
      bsFrame:
        begin
          Temp := Color1;
          Color1 := Color2;
          BevelRect(Types.Rect(1, 1, Width - 1, Height - 1));
          Color2 := Temp;
          Color1 := Temp;
          BevelRect(Types.Rect(0, 0, Width - 2, Height - 2));
        end;
      bsTopLine:
        begin
          BevelLine(Color1, 0, 0, Width, 0);
          BevelLine(Color2, 0, 1, Width, 1);
        end;
      bsBottomLine:
        begin
          BevelLine(Color1, 0, Height - 2, Width, Height - 2);
          BevelLine(Color2, 0, Height - 1, Width, Height - 1);
        end;
      bsLeftLine:
        begin
          BevelLine(Color1, 0, 0, 0, Height);
          BevelLine(Color2, 1, 0, 1, Height);
        end;
      bsRightLine:
        begin
          BevelLine(Color1, Width - 2, 0, Width - 2, Height);
          BevelLine(Color2, Width - 1, 0, Width - 1, Height);
        end;
    end;
  end;
end;

{ TTimer }

constructor TTimer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Interval := 1000;
  Enabled := True;
end;

function TTimer.GetHandle: QTimerH;
begin
  HandleNeeded;
  Result := QTimerH(FHandle);
end;

procedure TTimer.SetEnabled(Value: Boolean);
begin
  if Value <> FEnabled then
  begin
    FEnabled := Value;
    if not (csDesigning in ComponentState) then
      if Value then
        QTimer_start(Handle, Interval, False)
      else
        QTimer_stop(Handle);
  end;
end;

procedure TTimer.SetInterval(Value: Cardinal);
begin
  if Value <> FInterval then
  begin
    FInterval := Value;
    if Enabled and not (csDesigning in ComponentState) then
      QTimer_changeInterval(Handle, Interval); { starts the timer going again }
  end;
end;

procedure TTimer.Timer;
begin
  if Assigned(FOnTimer) then
  try
    FOnTimer(Self);
  except
    Application.HandleException(Self);
  end;
end;

procedure TTimer.HookEvents;
var
  Timeout: TMethod;
begin
  QTimer_timeout_Event(Timeout) := Timer;
  QTimer_hook_hook_timeout(QTimer_hookH(Hooks), Timeout);
  inherited HookEvents;
end;

procedure TTimer.CreateWidget;
begin
  if not (csDesigning in ComponentState) then
  begin
    FHandle := QTimer_create(nil, nil);
    Hooks := QTimer_hook_create(FHandle);
  end;
end;

{ TSplitter }

type
  TOpenWidgetControl = class(TWidgetControl);

constructor TSplitter.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FResizeStyle := rsPattern;
  FAutoSnap := True;
  Width := 3;
  Height := 22;
  Align := alLeft;
  Cursor := crHSplit;
  FMinSize := 30;
  FOldSize := -1;
  Color := clBtnFace;
end;

destructor TSplitter.Destroy;
begin
  FBrush.Free;
  inherited Destroy;
end;

var
  FLineVisible: Boolean = False;

procedure TSplitter.DrawLine;
var
  P: TPoint;
  Painter: QPainterH;
  ParentWidget: QOpenWidgetH;
  PaintUnclipped: Boolean;
begin
  FLineVisible := not FLineVisible;
  P := Types.Point(Left, Top);
  if Align in [alLeft, alRight] then
    P.X := Left + FSplit
  else
    P.Y := Top + FSplit;

  if (Parent is TCustomForm) then
  with TCustomForm(Parent) do
  begin
    if (Menu <> nil) and (Menu.ParentWidget = Handle) and
    QWidget_isVisible(Menu.Handle) then
      Inc(P.Y, QWidget_height(Menu.Handle));
  end;

  ParentWidget := QOpenWidgetH(Parent.Handle);
  PaintUnclipped := QOpenWidget_getWFlags(ParentWidget) and Integer(WidgetFlags_WPaintUnclipped) <> 0;
  if not PaintUnclipped then
    QOpenWidget_setWFlags(ParentWidget, Integer(WidgetFlags_WPaintUnclipped));
  try
    Painter := QPainter_create;
    try
      QPainter_begin(Painter, QWidget_to_QPaintDevice(ParentWidget));
      try
        QPainter_setRasterOp(Painter, RasterOp_NotXorROP);
        if ResizeStyle = rsPattern then
          Canvas.Brush.Style := bsDense4
        else
          Canvas.Brush.Style := bsSolid;
        Canvas.Brush.Color := clForeground;
        QPainter_fillRect(Painter, P.X, P.Y, Width, Height, Canvas.Brush.Handle);
      finally
        QPainter_end(Painter);
      end;
    finally
      QPainter_destroy(Painter);
    end;
  finally
    if not PaintUnclipped then
      QOpenWidget_clearWFlags(ParentWidget, Integer(WidgetFlags_WPaintUnclipped));
  end;
end;

function TSplitter.FindControl: TControl;
var
  P: TPoint;
  I: Integer;
  R: TRect;
begin
  Result := nil;
  P := Types.Point(Left, Top);
  case Align of
    alLeft: Dec(P.X);
    alRight: Inc(P.X, Width);
    alTop: Dec(P.Y);
    alBottom: Inc(P.Y, Height);
  else
    Exit;
  end;
  for I := 0 to Parent.ControlCount - 1 do
  begin
    Result := Parent.Controls[I];
    if Result.Visible and Result.Enabled then
    begin
      R := Result.BoundsRect;
      if (R.Right - R.Left) = 0 then
        if Align in [alTop, alLeft] then
          Dec(R.Left)
        else
          Inc(R.Right);
      if (R.Bottom - R.Top) = 0 then
        if Align in [alTop, alLeft] then
          Dec(R.Top)
        else
          Inc(R.Bottom);
      if PtInRect(R, P) then
        Exit;
    end;
  end;
  Result := nil;
end;

procedure TSplitter.RequestAlign;
begin
  inherited RequestAlign;
  if (Cursor <> crVSplit) and (Cursor <> crHSplit) then
    Exit;
  if Align in [alBottom, alTop] then
    Cursor := crVSplit
  else
    Cursor := crHSplit;
end;

procedure TSplitter.Paint;
var
  R: TRect;
begin
  R := ClientRect;
  Canvas.Brush.Style := bsSolid;
  Canvas.Brush.Color := Color;
  Canvas.FillRect(R);
  if Beveled then
  begin
    if Align in [alLeft, alRight] then
      InflateRect(R, -1, 2)
    else
      InflateRect(R, 2, -1);

    OffsetRect(R, 1, 1);

    Canvas.Pen.Width := 2;
    Canvas.Pen.Color := clBtnHighlight;
    Canvas.MoveTo(R.Left, R.Top);
    Canvas.LineTo(R.Left, R.Bottom);
    Canvas.MoveTo(R.Right, R.Bottom);
    Canvas.LineTo(R.Right, R.Top);
    OffsetRect(R, -2, -2);
    Canvas.Pen.Color := clBtnShadow;
    Canvas.MoveTo(R.Left, R.Top);
    Canvas.LineTo(R.Left, R.Bottom);
    Canvas.MoveTo(R.Right, R.Bottom);
    Canvas.LineTo(R.Right, R.Top);
  end;

  if csDesigning in ComponentState then
    { Draw outline }
    with Canvas do
    begin
      Pen.Style := psDash;
      Brush.Style := bsSolid;
      Rectangle(0, 0, Width, Height-1);
    end;
  if Assigned(FOnPaint) then
    FOnPaint(Self);
end;

function TSplitter.DoCanResize(var NewSize: Integer): Boolean;
begin
  Result := CanResize(NewSize);
  if Result and (NewSize <= MinSize) and FAutoSnap then
    NewSize := 0;
end;

function TSplitter.CanResize(var NewSize: Integer): Boolean;
begin
  Result := True;
  if Assigned(FOnCanResize) then
    FOnCanResize(Self, NewSize, Result);
end;

procedure TSplitter.MouseDown(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
var
  I: Integer;
begin
  if Button = mbLeft then
  begin
    FOldCur := Screen.Cursor;
    Screen.Cursor := Cursor;
  end;
  inherited MouseDown(Button, Shift, X, Y);
  if Button = mbLeft then
  begin
    FControl := FindControl;
    FDownPos := Types.Point(X, Y);
    if Assigned(FControl) then
    begin
      if Align in [alLeft, alRight] then
      begin
        FMaxSize := Parent.ClientWidth - FMinSize;
        for I := 0 to Parent.ControlCount - 1 do
          with Parent.Controls[I] do
            if Align in [alLeft, alRight] then
              Dec(FMaxSize, Width);
        Inc(FMaxSize, FControl.Width);
      end
      else
      begin
        FMaxSize := Parent.ClientHeight - FMinSize;
        for I := 0 to Parent.ControlCount - 1 do
          with Parent.Controls[I] do
            if Align in [alTop, alBottom] then
              Dec(FMaxSize, Height);
        Inc(FMaxSize, FControl.Height);
      end;
      UpdateSize(X, Y);
      with ValidParentForm(Self) do
        if ActiveControl <> nil then
        begin
          FActiveControl := ActiveControl;
          FOldKeyDown := TOpenWidgetControl(FActiveControl).OnKeyDown;
          TOpenWidgetControl(FActiveControl).OnKeyDown := FocusKeyDown;
        end;
      if ResizeStyle in [rsLine, rsPattern] then
        DrawLine;
    end;
  end;
end;

procedure TSplitter.UpdateControlSize;
begin
  if FNewSize <> FOldSize then
  begin
    case Align of
      alLeft: FControl.Width := FNewSize;
      alTop: FControl.Height := FNewSize;
      alRight:
        begin
          Parent.DisableAlign;
          try
            FControl.Left := FControl.Left + (FControl.Width - FNewSize);
            FControl.Width := FNewSize;
          finally
            Parent.EnableAlign;
          end;
        end;
      alBottom:
        begin
          Parent.DisableAlign;
          try
            FControl.Top := FControl.Top + (FControl.Height - FNewSize);
            FControl.Height := FNewSize;
          finally
            Parent.EnableAlign;
          end;
        end;
    end;
    Update;
    if Assigned(FOnMoved) then FOnMoved(Self);
    FOldSize := FNewSize;
  end;
end;

procedure TSplitter.CalcSplitSize(X, Y: Integer; var NewSize, Split: Integer);
var
  S: Integer;
begin
  if Align in [alLeft, alRight] then
    Split := X - FDownPos.X
  else
    Split := Y - FDownPos.Y;
  S := 0;
  case Align of
    alLeft: S := FControl.Width + Split;
    alRight: S := FControl.Width - Split;
    alTop: S := FControl.Height + Split;
    alBottom: S := FControl.Height - Split;
  end;
  NewSize := S;
  if S < FMinSize then
    NewSize := FMinSize
  else if S > FMaxSize then
    NewSize := FMaxSize;
  if S <> NewSize then
  begin
    if Align in [alRight, alBottom] then
      S := S - NewSize else
      S := NewSize - S;
    Inc(Split, S);
  end;
end;

procedure TSplitter.UpdateSize(X, Y: Integer);
begin
  CalcSplitSize(X, Y, FNewSize, FSplit);
end;

procedure TSplitter.MouseMove(Shift: TShiftState; X, Y: Integer);
var
  NewSize, Split: Integer;
begin
  inherited MouseMove(Shift, X, Y);
  if (ssLeft in Shift) and Assigned(FControl) then
  begin
    CalcSplitSize(X, Y, NewSize, Split);
    if DoCanResize(NewSize) then
    begin
      if ResizeStyle in [rsLine, rsPattern] then
        DrawLine;
      FNewSize := NewSize;
      FSplit := Split;
      if ResizeStyle = rsUpdate then
        UpdateControlSize;
      if ResizeStyle in [rsLine, rsPattern] then
        DrawLine;
    end;
  end;
end;

procedure TSplitter.MouseUp(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
begin
  if Button = mbLeft then
    Screen.Cursor := FOldCur;
  inherited MouseUp(Button, Shift, X, Y);
  if Assigned(FControl) then
  begin
    if FLineVisible then DrawLine;
    UpdateControlSize;
    StopSizing;
  end;
end;

procedure TSplitter.FocusKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = Word(Key_Escape) then
    StopSizing
  else if Assigned(FOldKeyDown) then
    FOldKeyDown(Sender, Key, Shift);
end;

procedure TSplitter.SetBeveled(Value: Boolean);
begin
  FBeveled := Value;
  Repaint;
end;

procedure TSplitter.StopSizing;
begin
  if Assigned(FControl) then
  begin
    if FLineVisible then DrawLine;
    FControl := nil;
    if Assigned(FActiveControl) then
    begin
      TOpenWidgetControl(FActiveControl).OnKeyDown := FOldKeyDown;
      FActiveControl := nil;
    end;
  end;
  if Assigned(FOnMoved) then
    FOnMoved(Self);
end;

{ TImage }

constructor TImage.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csReplicatable];
  FPicture := TPicture.Create;
  FPicture.OnChange := PictureChanged;
  FPicture.OnProgress := Progress;
  FAutoSize := False;
  Height := 105;
  Width := 105;
end;

destructor TImage.Destroy;
begin
  FPicture.Free;
  inherited Destroy;
end;

function TImage.DestRect: TRect;
begin
  if Stretch then
    Result := ClientRect
  else if Center then
    Result := Types.Bounds((Width - Picture.Width) div 2, (Height - Picture.Height) div 2,
      Picture.Width, Picture.Height)
  else
    Result := Types.Rect(0, 0, Picture.Width, Picture.Height);
end;

procedure TImage.Paint;
var
  Save: Boolean;
begin
  Save := FDrawing;
  FDrawing := True;
  try
    with inherited Canvas do
      StretchDraw(DestRect, Picture.Graphic);
  finally
    FDrawing := Save;
  end;
  if csDesigning in ComponentState then
    with inherited Canvas do
    begin
      Pen.Style := psDash;
      Brush.Style := bsClear;
      Rectangle(0, 0, Width, Height);
    end;
end;

function TImage.DoPaletteChange: Boolean;
var
  ParentForm: TCustomForm;
  Tmp: TGraphic;
begin
  Result := False;
  Tmp := Picture.Graphic;
  if Visible and (not (csLoading in ComponentState)) and (Tmp <> nil) then
  begin
    ParentForm := GetParentForm(Self);
    if Assigned(ParentForm) and ParentForm.Active and ParentForm.HandleAllocated then
      if FDrawing then
      else
        Result := True;
  end;
end;

procedure TImage.Progress(Sender: TObject; Stage: TProgressStage;
  PercentDone: Byte; RedrawNow: Boolean; const R: TRect; const Msg: WideString);
begin
  if FIncrementalDisplay and RedrawNow then
  begin
    if DoPaletteChange then Update
    else Paint;
  end;
  if Assigned(FOnProgress) then FOnProgress(Sender, Stage, PercentDone, RedrawNow, R, Msg);
end;

function TImage.GetCanvas: TCanvas;
var
  Bitmap: TBitmap;
begin
  if Picture.Graphic = nil then
  begin
    Bitmap := TBitmap.Create;
    try
      Bitmap.Width := Width;
      Bitmap.Height := Height;
      Picture.Graphic := Bitmap;
    finally
      Bitmap.Free;
    end;
  end;
  if Picture.Graphic is TBitmap then
    Result := TBitmap(Picture.Graphic).Canvas
  else
    raise EInvalidOperation.CreateRes(@SImageCanvasNeedsBitmap);
end;

procedure TImage.SetAutoSize(const Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    Resize;
  end;
end;

procedure TImage.SetCenter(Value: Boolean);
begin
  if FCenter <> Value then
  begin
    FCenter := Value;
    PictureChanged(Self);
  end;
end;

procedure TImage.SetPicture(Value: TPicture);
begin
  FPicture.Assign(Value);
end;

procedure TImage.SetStretch(Value: Boolean);
begin
  if Value <> FStretch then
  begin
    FStretch := Value;
    PictureChanged(Self);
  end;
end;

procedure TImage.SetTransparent(Value: Boolean);
begin
  if Value <> FTransparent then
  begin
    FTransparent := Value;
    PictureChanged(Self);
  end;
end;

procedure TImage.PictureChanged(Sender: TObject);
var
  G: TGraphic;
begin
  if AutoSize and  (Picture.Width > 0) and (Picture.Height > 0) then
    SetBounds(Left, Top, Picture.Width, Picture.Height);
  G := Picture.Graphic;
  if G <> nil then
  begin
    { if not ((G is TMetaFile) or (G is TIcon)) then }
    G.Transparent := FTransparent;
    if (not G.Transparent and (not (G is TIcon))) and
    (Stretch or (G.Width >= Width) and (G.Height >= Height)) then
      ControlStyle := ControlStyle + [csOpaque]
    else
      ControlStyle := ControlStyle - [csOpaque];
    if DoPaletteChange and FDrawing then Update;
  end
  else ControlStyle := ControlStyle - [csOpaque];
  if not FDrawing then Invalidate;
end;

procedure TImage.DoAutoSize;
begin
  if Align in [alNone, alLeft, alRight] then
    Width := Picture.Width;
  if Align in [alNone, alTop, alBottom] then
    Height := Picture.Height;
end;

{ TGroupButton }

type
  TGroupButton = class(TRadioButton)
  private
  { FInClick: Boolean; }
    FRadioGroup: TCustomRadioGroup;
  protected
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyPress(var Key: Char); override;
  public
    constructor InternalCreate(RadioGroup: TCustomRadioGroup);
    destructor Destroy; override;
  end;

constructor TGroupButton.InternalCreate(RadioGroup: TCustomRadioGroup);
begin
  inherited Create(RadioGroup);
  FRadioGroup := RadioGroup;
  Parent := RadioGroup;
  RadioGroup.FButtons.Add(Self);
  Visible := RadioGroup.Visible;
  Enabled := RadioGroup.Enabled;
  Cursor := RadioGroup.Cursor;
  TabStop := False;
  InputKeys := [ikArrows];
  Masked := True;
end;

destructor TGroupButton.Destroy;
var
  RadioGroup: TCustomRadioGroup;
begin
  RadioGroup := TCustomRadioGroup(Owner);
  if not (csDestroying in RadioGroup.ComponentState) then
    QButtonGroup_remove(RadioGroup.Handle, Handle);
  RadioGroup.FButtons.Remove(Self);
  inherited Destroy;
end;

function TGroupButton.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  if not (csDesigning in ComponentState) and
    (QEvent_type(Event) = QEventType_MouseButtonPress) and
    (QMouseEvent_button(QMouseEventH(Event)) = ButtonState_LeftButton) then
  begin
    Result := not TCustomRadioGroup(Parent).CanModify;
  end
  else
    Result := inherited EventFilter(Sender, Event);
end;

procedure TGroupButton.KeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited KeyDown(Key, Shift);
  if (Key = Key_Down) or (Key = Key_Up) then
    if TCustomRadioGroup(Parent).CanModify then
    begin
      if not Checked then
        SetChecked(True);
    end
    else
      Key := 0;
end;

procedure TGroupButton.KeyPress(var Key: Char);
begin
  inherited KeyPress(Key);
  TCustomRadioGroup(Parent).KeyPress(Key);
  if (Key = #8) or (Key = #32) then
    if not TCustomRadioGroup(Parent).CanModify then Key := #0;
end;

{ TCustomRadioGroup }

procedure TCustomRadioGroup.ClickedHook(Index: Integer);
begin
  try
    FItemIndex := Index;
    if FItemIndex <> FLastIndex then
    begin
      FLastIndex := FItemIndex;
      if (Index >= 0) and (Index < FButtons.Count) then
        TWidgetControl(FButtons[Index]).SetFocus;
      Click;
    end;
  except
    Application.HandleException(Self);
  end;
end;

constructor TCustomRadioGroup.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle - [csClickEvents, csAcceptsControls];
  FItems := TStringList.Create;
  TStringList(FItems).OnChange := ItemsChange;
  FButtons := TList.Create;
  FItemIndex := -1;
  FLastIndex := -1;
  FColumns := 1;
  FOrientation := orVertical;
  InputKeys := [ikArrows];
  TabStop := True;
end;

//const
  //Yes, this is intentional. Makes more sense visually.
//  OrientMap: array[TOrientation] of Qt.Orientation = (
//    Orientation_Vertical, Orientation_Horizontal);

function TCustomRadioGroup.CanModify: Boolean;
begin
  Result := True;
end;

procedure TCustomRadioGroup.CreateWidget;
begin
  FHandle := QButtonGroup_create(FColumns, Qt.Orientation(FOrientation),
    ParentWidget, nil);
  Hooks := QButtonGroup_hook_create(Handle);
end;

procedure TCustomRadioGroup.CursorChanged;
var
  I: Integer;
begin
  inherited CursorChanged;
  for I := 0 to FButtons.Count - 1 do
    TGroupButton(FButtons[I]).Cursor := Cursor;
end;

destructor TCustomRadioGroup.Destroy;
begin
  SetButtonCount(0);
  TStringList(FItems).OnChange := nil;
  FItems.Free;
  FButtons.Free;
  inherited Destroy;
end;

function TCustomRadioGroup.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  try
    if (QEvent_type(Event) = QEventType_show) then
      ForceLayout;
    if (QEvent_type(Event) = QEventType_KeyPress) and
    (QKeyEvent_key(QKeyEventH(Event)) = Key_Tab) then
      Result := False
    else
      Result := inherited EventFilter(Sender, Event);
  except
    Application.HandleException(Self);
    Result := False;
  end;
end;

procedure TCustomRadioGroup.ForceLayout;
begin
  QGroupBox_setColumnLayout(Handle, FColumns, Qt.Orientation(FOrientation));
end;

function TCustomRadioGroup.GetHandle: QButtonGroupH;
begin
  HandleNeeded;
  Result := QButtonGroupH(FHandle);
end;

procedure TCustomRadioGroup.HookEvents;
var
  Method: TMethod;
begin
  QButtonGroup_clicked_Event(Method) := Self.ClickedHook;
  QButtonGroup_hook_hook_clicked(QButtonGroup_hookH(Hooks), Method);
  inherited HookEvents;
end;

procedure TCustomRadioGroup.ItemsChange(Sender: TObject);
var
  ResizeEvent: QResizeEventH;
  Size: TSize;
  I: Integer;
begin
  UpdateButtons;
  ShowingChanged;
  for I := 0 to FButtons.Count - 1 do
    with TGroupButton(FButtons[I]) do
    begin
      //calling QRadioButton::resizeEvent will force the button to update it's mask.
      //Once QWidget::updateMask is exposed, call that directly.
      Size.cx := Width;
      Size.cy := Height;
      ResizeEvent := QResizeEvent_create(@Size, @Size);
      try
        QOpenWidget_resizeEvent(QOpenWidgetH(Handle), ResizeEvent);
      finally
        QResizeEvent_destroy(ResizeEvent);
      end;
    end;
end;

procedure TCustomRadioGroup.RestoreWidgetState;
var
  S: TCaption;
begin
  inherited RestoreWidgetState;
  UpdateButtons;
  S := Caption;
  QGroupBox_setTitle(Handle, PWideString(@S));
end;

procedure TCustomRadioGroup.SaveWidgetState;
var
  I: Integer;
begin
  inherited SaveWidgetState;
  for I := FButtons.Count - 1 downto 0 do
    TGroupButton(FButtons[I]).Free;
  FButtons.Clear;
end;

procedure TCustomRadioGroup.Loaded;
begin
  inherited Loaded;
  ForceLayout;
end;

procedure TCustomRadioGroup.SetButtonCount(Value: Integer);
begin
  while FButtons.Count < Value do TGroupButton.InternalCreate(Self);
  while FButtons.Count > Value do TGroupButton(FButtons.Last).Free;
end;

procedure TCustomRadioGroup.SetColumns(Value: Integer);
begin
  if (Value > 0) and (FColumns <> Value) then
  begin
    FColumns := Value;
    ForceLayout;
  end;
end;

procedure TCustomRadioGroup.SetFocus;
var
  BtnIndex: Integer;
begin
  if FButtons.Count > 0 then
  begin
    if FItemIndex < 0 then BtnIndex := 0 else BtnIndex := FItemIndex;
    if FButtons.Count > FItemIndex then
      TGroupButton(FButtons[BtnIndex]).SetFocus;
  end else
    inherited SetFocus;
end;

procedure TCustomRadioGroup.SetItemIndex(Value: Integer);
begin
  if Value < -1 then Value := -1;
  if Value >= FButtons.Count then
    Value := FButtons.Count - 1;
  if FItemIndex <> Value then
  begin
    if Value >= 0 then
      QButtonGroup_setButton(Handle, Value)
    else 
      TGroupButton(FButtons[FItemIndex]).Checked := False;
    FItemIndex := Value;
  end;
end;

procedure TCustomRadioGroup.SetItems(Value: TStrings);
begin
  FItems.Assign(Value);
end;

procedure TCustomRadioGroup.SetOrientation(const Value: TOrientation);
begin
  if FOrientation <> Value then
  begin
    FOrientation := Value;
    ForceLayout;
  end;
end;

procedure TCustomRadioGroup.UpdateButtons;
var
  I: Integer;
begin
  SetButtonCount(FItems.Count);
  for I := 0 to FButtons.Count - 1 do
    TGroupButton(FButtons[I]).Caption := FItems[I];
  if (FItemIndex >= 0) and (FItemIndex < FButtons.Count) then
    TGroupButton(FButtons[FItemIndex]).Checked := True;
end;

procedure TCustomRadioGroup.ShowingChanged;
begin
  inherited ShowingChanged;
  ForceLayout;
end;

function TCustomRadioGroup.WantKey(Key: Integer;
  Shift: TShiftState; const KeyText: WideString): Boolean;
var
  I: Integer;
begin
  if IsAccel(Key, Caption) and CanFocus and (ItemIndex < 0)
  and (FButtons.Count > 0) then
  begin
    TGroupButton(FButtons[0]).Checked := True;
    SetFocus;
    Click;
    Result := True;
    Exit
  end;

  for I := 0 to FButtons.Count - 1 do
  begin
    Result := TGroupButton(FButtons[I]).WantKey(Key, Shift, KeyText);
    if Result then
    begin
      if FItemIndex <> I then
      begin
        FItemIndex := I;
        Click;
      end;
      Exit;
    end;
  end;
  Result := inherited WantKey(Key, Shift, KeyText);
end;

{ TCustomControlBar }

type
  PDockPos = ^TDockPos;
  TDockPos = record
    Control: TControl;
    Insets: TRect;
    Visible: Boolean;
    Break: Boolean;
    Pos: TPoint;
    Width: Integer;

    Height: Integer;
    RowCount: Integer;
    TempRow: Integer;
    Parent: PDockPos;
    SubItem: PDockPos;

    TempBreak: Boolean;
    TempPos: TPoint;
    TempWidth: Integer;
    Dirty: Boolean;
  end;

function CreateDockPos(AControl: TControl; Break: Boolean; Visible: Boolean;
  const APos: TPoint; AWidth, AHeight: Integer; Parent: PDockPos;
  const Insets: TRect; RowCount: Integer): PDockPos;
begin
  GetMem(Result, SizeOf(TDockPos));
  Result.Control := AControl;
  Result.Insets := Insets;
  Result.Visible := Visible;
  Result.Break := Break;
  Result.Pos := APos;
  Result.Width := AWidth;
  Result.Height := AHeight;
  Result.RowCount := RowCount;
  Result.TempRow := 1;
  Result.TempBreak := Break;
  Result.TempPos := APos;
  Result.TempWidth := AWidth;
  Result.Parent := Parent;
  Result.SubItem := nil;
end;

procedure FreeDockPos(Items: TList; DockPos: PDockPos);
var
  Tmp: PDockPos;
begin
  { Remove all subitems }
  while DockPos <> nil do
  begin
    Tmp := DockPos;
    Items.Remove(DockPos);
    DockPos := DockPos.SubItem;
    FreeMem(Tmp, SizeOf(TDockPos));
  end;
end;

procedure AdjustControlRect(var ARect: TRect; const Insets: TRect);
begin
  with Insets do
  begin
    Dec(ARect.Left, Left);
    Dec(ARect.Top, Top);
    Inc(ARect.Right, Right);
    Inc(ARect.Bottom, Bottom);
  end;
end;

constructor TCustomControlBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csAcceptsControls, csCaptureMouse, csClickEvents,
    csDoubleClicks, csOpaque, csNoFocus];
  FItems := TList.Create;
  FAutoDrag := True;
  FPicture := TPicture.Create;
  FPicture.OnChange := PictureChanged;
  FRowSize := 26;
  FRowSnap := True;
  FBevelEdges := [beLeft, beTop, beRight, beBottom];
  FBevelInner := bvRaised;
  FBevelOuter := bvLowered;
  Color := clBtnFace;
  Width := 100;
  Height := 50;
  FGrabCursor := crDefault;
  FSaveCursor := crNone;
end;

destructor TCustomControlBar.Destroy;
var
  I: Integer;
begin
  for I := 0 to FItems.Count - 1 do
    if FItems[I] <> nil then
      FreeMem(PDockPos(FItems[I]), SizeOf(TDockPos));
  FItems.Free;
  FPicture.Free;
  inherited Destroy;
end;

procedure TCustomControlBar.AlignControls(AControl: TControl; var ARect: TRect);
var
  I, J, X: Integer;
  DockPos: PDockPos;
  TotalSize, RowSize, RowSpace, Shift: Integer;
  RowHeight, PrevRowHeight: Integer;
  MoveBy: Integer;
  Pos: TPoint;
  CX: Integer;
  Control: TControl;
  UseTemp: Boolean;

  Row: Integer;
  RowCount: Integer;
  FirstIndex, LastIndex: Integer;
  InsertingControl: Boolean;
  SelfDirty: Boolean;
  R: TRect;

  TempRowSize, TempRowSpace: Integer;
  AdjustX: Integer;
  DockRect: TRect;
  PreferredSize: Integer;

  TmpDockPos: PDockPos;
  Redo: PDockPos;
  RedoCount: Integer;
  SkipRedo: Boolean;

  PaintEvent: QPaintEventH;

  function ShouldRedo(DockPos: PDockPos; const Pos: TPoint; Width: Integer): Boolean;
  begin
    { Determine whether this subitem has changed and will affect its
      parent(s). }
    if (DockPos^.Parent <> nil) and ((Pos.X <> DockPos^.Parent^.TempPos.X) or
      (Width <> DockPos^.Parent^.TempWidth)) then
    begin
      DockPos := DockPos^.Parent;
      { Update parents and re-perform align logic }
      repeat
        DockPos^.TempPos.X := Pos.X;
        DockPos^.TempWidth := Width;
        Redo := DockPos;
        DockPos := DockPos^.Parent;
      until DockPos = nil;
      Result := True;
    end
    else
      Result := False;
  end;

begin
  if FAligning then Exit;
  FAligning := True;
  try
    { Update items }
    InsertingControl := UpdateItems(AControl);
    if FItems.Count = 0 then Exit;
    RowCount := 0;
    FirstIndex := 0;
    LastIndex := FItems.Count - 1;

    { Find number of rows }
    for I := FirstIndex to LastIndex do
    begin
      DockPos := PDockPos(FItems[I]);
      { First item can't have Break set! }
      DockPos^.TempBreak := DockPos^.Break;
      if DockPos^.Break then
        Inc(RowCount);
    end;

    Redo := nil;
    SkipRedo := False;
    RedoCount := 2;
    repeat

      if Redo <> nil then
      begin
        SkipRedo := True;
        Dec(RedoCount);
      end;
      if RedoCount = 0 then Exit;

      RowHeight := 0;
      PrevRowHeight := 0;
      Row := 1;

      while Row <= RowCount do
      begin

        if Row = 1 then
          RowHeight := ClientRect.Top + EdgeSpacing(beTop);

        { Find first and last index for current row }
        if Row = 1 then
          FirstIndex := 0
        else
          FirstIndex := LastIndex + 1;
        LastIndex := FItems.Count - 1;
        for I := FirstIndex to LastIndex - 1 do
        begin
          DockPos := PDockPos(FItems[I + 1]);
          { First item can't have Break set }
          if DockPos^.Break or DockPos^.TempBreak then
          begin
            LastIndex := I;
            Break;
          end;
        end;

        { Set temp values for all controls }
        TotalSize := ARect.Right - ARect.Left;
        RowSize := 0;
        RowSpace := 0;

        for I := FirstIndex to LastIndex do
        begin
          DockPos := PDockPos(FItems[I]);

          if DockPos^.Break or DockPos^.TempBreak then
          begin
            RowSize := ClientRect.Left + EdgeSpacing(beLeft);
            RowSpace := 0;
            UseTemp := False;
            if UseTemp then
              DockPos^.TempPos.Y := RowHeight else
              DockPos^.Pos.Y := RowHeight;

            PrevRowHeight := RowHeight;
          end
          else UseTemp := False;

          Control := DockPos^.Control;
          if (csDesigning in ComponentState) or Control.Visible then
          begin
            { If control was moved/resized, update our info }
            if DockPos^.Parent = nil then
            begin
              PreferredSize := DockPos^.Width;
              Dec(PreferredSize, DockPos^.Insets.Left + DockPos^.Insets.Right);
              GetControlInfo(Control, DockPos^.Insets, PreferredSize,
                DockPos^.RowCount);
              DockPos^.Width := PreferredSize + DockPos^.Insets.Left +
                DockPos^.Insets.Right;
              if not InsertingControl and (DockPos^.Parent = nil) and
                (AControl = DockPos^.Control) then
              begin
                if UseTemp then
                begin
                  DockPos^.TempPos := Point(AControl.Left - ARect.Left -
                    DockPos^.Insets.Left, AControl.Top - ARect.Top - DockPos^.Insets.Top);
                  DockPos^.TempWidth := AControl.Width + DockPos^.Insets.Left +
                    DockPos^.Insets.Right;
                  DockRect := Bounds(DockPos^.TempPos.X, DockPos^.TempPos.Y,
                    DockPos^.TempWidth, DockPos^.Height);
                end
                else
                  DockRect := Bounds(DockPos^.Pos.X, DockPos^.Pos.Y,
                    DockPos^.Width, DockPos^.Height);
              end;

              { Let user adjust sizes }
              if DockPos = Redo then
                DockRect := Bounds(DockPos^.TempPos.X, DockPos^.TempPos.Y,
                  DockPos^.TempWidth, DockPos^.Height)
              else
                DockRect := Bounds(DockPos^.Pos.X, DockPos^.Pos.Y,
                  DockPos^.Width, DockPos^.Height);

              DoBandMove(Control, DockRect);
              DockPos^.TempWidth := DockRect.Right - DockRect.Left;
            end
            else
            begin
              { Use parent's position }
              with DockPos^.Parent^ do
              begin
                DockPos^.Pos := Pos;
                DockPos^.TempPos := TempPos;
                Inc(DockPos^.Pos.Y, Height);
                Inc(DockPos^.TempPos.Y, Height);
                DockPos^.Width := Width;
                DockPos^.TempWidth := TempWidth;
                DockRect := Bounds(DockPos^.TempPos.X, DockPos^.TempPos.Y,
                  DockPos^.TempWidth, DockPos^.Height);
              end;
            end;

            if DockPos = Redo then
            begin
              with DockPos^ do
              begin
                TempPos.X := DockRect.Left;
                TempPos.Y := DockRect.Top;
                TempWidth := DockRect.Right - DockRect.Left;
                Redo := nil;
                SkipRedo := False;
              end;
            end
            else
            begin
              with DockPos^ do
              begin
                Pos.X := DockRect.Left;
                Pos.Y := DockRect.Top;
              end;
            end;

            if UseTemp then
            begin
              Pos := DockPos^.TempPos;
              CX := DockPos^.TempWidth;
            end
            else
            begin
              Pos := DockRect.TopLeft;
              CX := DockRect.Right - DockRect.Left;
            end;

            { Make sure Pos is within bounds }
            if Pos.X < RowSize then
            begin
              { If a control is being resized/moved then adjust any controls to
                its left }
              if (RowSpace > 0) then
              begin
                TempRowSize := Pos.X;
                AdjustX := Pos.X;
                TempRowSpace := RowSpace;
                for J := I - 1 downto FirstIndex do
                begin
                  with PDockPos(FItems[J])^ do
                  begin
                    if (csDesigning in ComponentState) or Control.Visible then
                    begin
                      if TempPos.X + TempWidth > TempRowSize then
                      begin
                        X := TempPos.X + TempWidth - TempRowSize;
                        { Calculate adjusted rowspace }
                        if J < I - 1 then
                          Dec(TempRowSpace, AdjustX - (TempPos.X + TempWidth));
                        if X > TempRowSpace then
                          X := TempRowSpace;
                        AdjustX := TempPos.X;
                        Dec(TempPos.X, X);
                        Dec(TempRowSize, TempWidth);

                        TmpDockPos := PDockPos(FItems[J]);
                        if ShouldRedo(TmpDockPos, TmpDockPos^.TempPos,
                          TmpDockPos^.TempWidth) then
                          System.Break;

                        TmpDockPos := SubItem;
                        while TmpDockPos <> nil do
                          with TmpDockPos^ do
                          begin
                            Pos := PDockPos(FItems[J])^.Pos;
                            TempPos := PDockPos(FItems[J])^.TempPos;
                            Inc(Pos.Y, Parent.Height);
                            Inc(TempPos.Y, Parent.Height);
                            Width := PDockPos(FItems[J])^.Width;
                            TempWidth := PDockPos(FItems[J])^.TempWidth;
                            TmpDockPos := SubItem;
                          end;
                      end
                      else System.Break;
                    end;
                  end;
                end;
                AdjustX := RowSize - Pos.X;
                if AdjustX > RowSpace then
                  AdjustX := RowSpace;
                Dec(RowSpace, AdjustX);
                Dec(RowSize, AdjustX);
              end;
              Pos.X := RowSize;
            end;

            if (Redo <> nil) and not SkipRedo then Break;

            if Pos.Y <> PrevRowHeight then
              Pos.Y := PrevRowHeight;

            if Pos.Y + DockPos^.Height > RowHeight then
              RowHeight := Pos.Y + DockPos^.Height;

            Inc(RowSpace, Pos.X - RowSize);
            Inc(RowSize, Pos.X - RowSize + CX);

            if DockPos^.Parent = nil then
            begin
              DockPos^.TempPos := Pos;
              DockPos^.TempWidth := CX;
            end
            else
            begin
              if ShouldRedo(DockPos, Pos, CX) then
                System.Break
              else if not DockPos^.Break and (DockPos^.TempPos.X < Pos.X) then
              begin
                DockPos^.TempPos := Pos;
                DockPos^.TempWidth := CX;
              end;
            end;

            TmpDockPos := DockPos^.SubItem;
            while TmpDockPos <> nil do
              with TmpDockPos^ do
              begin
                Pos := DockPos^.Pos;
                TempPos := DockPos^.TempPos;
                Inc(Pos.Y, Parent.Height);
                Inc(TempPos.Y, Parent.Height);
                Width := DockPos^.Width;
                TempWidth := DockPos^.TempWidth;
                TmpDockPos := SubItem;
              end;
          end;
        end;

        if (Redo <> nil) and not SkipRedo then Break;

        { Determine whether controls on this row can fit }
        Shift := TotalSize - RowSize;
        if Shift < 0 then
        begin
          TotalSize := ARect.Right - ARect.Left;
          { Try to move all controls to fill space }
          AdjustX := RowSize;
          TempRowSpace := RowSpace;
          for I := LastIndex downto FirstIndex do
          begin
            DockPos := PDockPos(FItems[I]);

            Control := DockPos^.Control;
            if (csDesigning in ComponentState) or Control.Visible then
            begin
              if (DockPos^.TempPos.X + DockPos^.TempWidth) > TotalSize then
              begin
                MoveBy := (DockPos^.TempPos.X + DockPos^.TempWidth) - TotalSize;
                if I < LastIndex then
                  Dec(TempRowSpace, AdjustX - (DockPos^.TempPos.X +
                    DockPos^.TempWidth));
                if MoveBy <= TempRowSpace then
                  Shift := MoveBy else
                  Shift := TempRowSpace;
                if Shift <= TempRowSpace then
                begin
                  AdjustX := DockPos^.TempPos.X;
                  Dec(DockPos^.TempPos.X, Shift);
                  Dec(TotalSize, DockPos^.TempWidth);

                  if ShouldRedo(DockPos, DockPos^.TempPos, DockPos^.TempWidth) then
                    Break;

                  TmpDockPos := DockPos^.SubItem;
                  while TmpDockPos <> nil do
                    with TmpDockPos^ do
                    begin
                      TempPos := DockPos^.TempPos;
                      Inc(TempPos.Y, Parent.Height);
                      TmpDockPos := SubItem;
                    end;
                end
                else
                  Break;
              end;
            end;
          end;

          if (Redo <> nil) and not SkipRedo then Break;

          { Try to minimize all controls to fill space }
          if TotalSize < 0 then
          begin
            TotalSize := ARect.Right - ARect.Left;
            for I := LastIndex downto FirstIndex do
            begin
              DockPos := PDockPos(FItems[I]);
              Control := DockPos^.Control;
              if (csDesigning in ComponentState) or Control.Visible then
              begin
                if DockPos^.TempPos.X + DockPos^.TempWidth > TotalSize then
                begin
                  { Try to minimize control, move if it can't be resized }
                  DockPos^.TempWidth := DockPos^.TempWidth -
                    ((DockPos^.TempPos.X + DockPos^.TempWidth) - TotalSize);
{                  if DockPos^.TempWidth < Control.Constraints.MinWidth +
                    DockPos^.Insets.Left + DockPos^.Insets.Right then
                    DockPos^.TempWidth := Control.Constraints.MinWidth +
                      DockPos^.Insets.Left + DockPos^.Insets.Right;}
                  { Move control }
                  if DockPos^.TempPos.X + DockPos^.TempWidth > TotalSize then
                  begin
                    Dec(DockPos^.TempPos.X, (DockPos^.TempPos.X +
                      DockPos^.TempWidth) - TotalSize);
                    if DockPos^.TempPos.X < ARect.Left then
                      DockPos^.TempPos.X := ARect.Left;
                  end;

                  if ShouldRedo(DockPos, DockPos^.TempPos, DockPos^.TempWidth) then
                    Break;

                  TmpDockPos := DockPos^.SubItem;
                  while TmpDockPos <> nil do
                    with TmpDockPos^ do
                    begin
                      Pos := DockPos^.Pos;
                      TempPos := DockPos^.TempPos;
                      Inc(TempPos.Y, Parent.Height);
                      TempWidth := DockPos^.TempWidth;
                      TmpDockPos := SubItem;
                    end;
                end;
                Dec(TotalSize, DockPos^.TempWidth);
              end;
            end;
          end;

          if (Redo <> nil) and not SkipRedo then Break;

          { Done with first pass at minimizing. If we're still cramped for
            space then wrap last control if there are more than 1 controls on
            this row. }
          if (TotalSize < 0) and (FirstIndex <> LastIndex) then
          begin
            DockPos := PDockPos(FItems[LastIndex]);
            DockPos^.TempPos.X := 0;
            DockPos^.TempWidth := DockPos^.Width;
            DockPos^.TempBreak := True;
            Inc(RowCount);

            if ShouldRedo(DockPos, DockPos^.TempPos, DockPos^.TempWidth) then
              Break;

            TmpDockPos := DockPos^.SubItem;
            while TmpDockPos <> nil do
              with TmpDockPos^ do
              begin
                TempPos := DockPos^.TempPos;
                Inc(TempPos.Y, Parent.Height);
                TempWidth := DockPos^.TempWidth;
                TmpDockPos := SubItem;
              end;
          end
          else
            Inc(Row);
        end
        else
          Inc(Row);

      end;

    until Redo = nil;

    { Now position controls }
    for I := 0 to FItems.Count - 1 do
    begin
      DockPos := PDockPos(FItems[I]);
      with DockPos^ do
        if (Parent = nil) and ((csDesigning in ComponentState) or
          Control.Visible) then
        begin
          with Insets do
            R := Rect(Left + TempPos.X, Top + TempPos.Y,
              TempPos.X + TempWidth - Right,
              TempPos.Y + DockPos^.Height - Bottom);

          TmpDockPos := SubItem;
          while TmpDockPos <> nil do
          begin
            Inc(R.Bottom, TmpDockPos^.Height);
            TmpDockPos := TmpDockPos^.SubItem;
          end;
          if (R.Left <> Control.Left) or (R.Top <> Control.Top) or
            (R.Right - R.Left <> Control.Width) or
            (R.Bottom - R.Top <> Control.Height) then
          begin
            Dirty := True;
            SelfDirty := True;
            Control.BoundsRect := R;
          end;
        end;
    end;

    AdjustSize;
    if SelfDirty or (AControl <> nil) then
    {$IFDEF MSWINDOWS}
      InvalidateRect(ARect, False);
    {$ENDIF}
    {$IFDEF LINUX}
    begin    
      PaintEvent := QPaintEvent_create(@ARect, False);
      QApplication_sendEvent(Handle, PaintEvent);
    end;
    {$ENDIF}
    { Apply any constraints }
  finally
    FAligning := False;
  end;
end;

const
  DefaultInsets: TRect = (Left: 11; Top: 2; Right: 2; Bottom: 2);

function TCustomControlBar.UpdateItems(AControl: TControl): Boolean;
var
  I, J, Tmp, RepositionIndex: Integer;
  PrevBreak: Boolean;
  Control: TControl;
  Exists: Boolean;
  AddControls: TList;
  DockRect, R: TRect;
  Dirty: Boolean;
  IsVisible: Boolean;
  DockPos, TmpDockPos1, TmpDockPos2: PDockPos;
  BreakList: TList;
  IndexList: TList;
  SizeList: TList;
  ChangedPriorBreak: Boolean;

  procedure AddControl(List: TList; Control: TControl);
  var
     I: Integer;
  begin
    for I := 0 to List.Count - 1 do
      with TControl(List[I]) do
        if (Control.Top < Top) or (Control.Top = Top) and
          (Control.Left < Left) then
        begin
          List.Insert(I, Control);
          Exit;
        end;
    List.Add(Control);
  end;

begin
  Result := False;
  ChangedPriorBreak := False;
  AddControls := TList.Create;
  BreakList := TList.Create;
  IndexList := TList.Create;
  SizeList := TList.Create;
  try
    AddControls.Capacity := ControlCount;
    RepositionIndex := -1;
    Dirty := False;
    for I := 0 to ControlCount - 1 do
    begin
      Control := Controls[I];
      IsVisible := (csDesigning in ComponentState) or Control.Visible;
      Exists := False;
      for J := 0 to FItems.Count - 1 do
        if (PDockPos(FItems[J])^.Parent = nil) and
          (PDockPos(FItems[J])^.Control = Control) then
        begin
          Dirty := Dirty or PDockPos(FItems[J])^.Visible <> IsVisible;
          PDockPos(FItems[J])^.Visible := IsVisible;
          Exists := True;
          Break;
        end;
      if Exists and (Control = AControl) then
      begin
        RepositionIndex := J;
        DockPos := PDockPos(FItems[J]);
        with DockPos^ do
        begin
          SizeList.Add(TObject(Insets.Top + Insets.Bottom));
          if FDragControl <> nil then
            DockRect := Rect(Pos.X + Insets.Left, Pos.Y + Insets.Top,
              Pos.X + Width - Insets.Right, Pos.Y + Insets.Top + Control.Height)
          else
            DockRect := Control.BoundsRect;
          PrevBreak := Break;
        end;
        { If we were starting a row, then update any items to the right to
          begin starting the row. }
        if PrevBreak and (J + 1 < FItems.Count) then
        begin
          TmpDockPos1 := FItems[J + 1];
          if not TmpDockPos1.Break then
          begin
            TmpDockPos1.Break := True;
            TmpDockPos1.TempBreak := True;
            ChangedPriorBreak := True;
          end;
        end;

        { Remember the state of this item and its subitems }
        BreakList.Add(TObject(Ord(PrevBreak)));
        IndexList.Add(TObject(J));
        TmpDockPos1 := DockPos^.SubItem;
        while TmpDockPos1 <> nil do
        begin
          Tmp := FItems.IndexOf(TmpDockPos1);
          BreakList.Add(TObject(Ord(TmpDockPos1.Break)));
          IndexList.Add(TObject(Tmp));
          with TmpDockPos1^ do
            SizeList.Add(TObject(Insets.Top + Insets.Bottom));
          { If we were starting a row, then update any items to the right to
            begin starting the row. }
          if TmpDockPos1.Break then
          begin
            if Tmp + 1 < FItems.Count then
            begin
              TmpDockPos2 := FItems[Tmp + 1];
              if not TmpDockPos2.Break then
                TmpDockPos2.Break := True;
            end;
          end;
          TmpDockPos1 := TmpDockPos1^.SubItem;
        end;

        { Remove this item from consideration in DockControl. It's as if we are
          adding a new control. }
        FreeDockPos(FItems, DockPos);
      end
      else if not Exists then
      begin
        if Control = AControl then Result := True;
        AddControl(AddControls, Control);
      end;
    end;
    for I := 0 to AddControls.Count - 1 do
    begin
      R := TControl(AddControls[I]).BoundsRect;
      DockControl(TControl(AddControls[I]), R, BreakList, IndexList, SizeList,
        nil, ChangedPriorBreak, DefaultInsets, -1, -1, False);
    end;
    if RepositionIndex >= 0 then
      DockControl(AControl, DockRect, BreakList, IndexList, SizeList, nil,
        ChangedPriorBreak, DefaultInsets, -1, -1, True);
//    if Dirty then Invalidate;
  finally
    AddControls.Free;
    BreakList.Free;
    IndexList.Free;
    SizeList.Free;
  end;
end;

procedure TCustomControlBar.SetRowSize(Value: TRowSize);
begin
  if Value <> RowSize then
  begin
    FRowSize := Value;
  end;
end;

procedure TCustomControlBar.SetRowSnap(Value: Boolean);
begin
  if Value <> RowSnap then
  begin
    FRowSnap := Value;
  end;
end;

procedure TCustomControlBar.FlipChildren(AllLevels: Boolean);
begin
  { Do not flip controls }
end;

procedure TCustomControlBar.StickControls;
var
  I: Integer;
begin
  for I := 0 to FItems.Count - 1 do
    if FItems[I] <> nil then
      with PDockPos(FItems[I])^ do
      begin
        if Parent <> nil then
          Pos := Point(Parent^.Pos.X, Parent^.Pos.Y + Parent.Height)
        else
        begin
          Pos := Control.BoundsRect.TopLeft;
          Dec(Pos.X, Insets.Left);
          Dec(Pos.Y, Insets.Top);
        end;
        Width := Control.Width + Insets.Left + Insets.Right;
        Break := TempBreak;
      end;
end;

procedure TCustomControlBar.DockControl(AControl: TControl;
  const ARect: TRect; BreakList, IndexList, SizeList: TList; Parent: Pointer;
  ChangedPriorBreak: Boolean; Insets: TRect; PreferredSize, RowCount: Integer;
  Existing: Boolean);
var
  I, InsPos, Size, TotalSize: Integer;
  DockPos: PDockPos;
  MidPoint: TPoint;
  NewControlRect, ControlRect: TRect;
  IsVisible, DockBreak: Boolean;
  PrevBreak: Boolean;
  PrevIndex: Integer;
  NewHeight, PrevInsetHeight: Integer;
  NewLine: Boolean;

  procedure AddItem;
  var
    DockPos: PDockPos;
    H: Integer;
  begin
    if InsPos = 0 then DockBreak := True;
    if (PrevIndex <> InsPos) or ChangedPriorBreak then
    begin
      if DockBreak and (InsPos < FItems.Count) then
      begin
        DockPos := FItems[InsPos];
        if not NewLine and DockPos^.Break then
        begin
          DockPos^.Break := False;
          DockPos^.TempBreak := False;
        end;
      end;
    end;
    if RowSnap then
      H := RowSize else
      H := NewControlRect.Bottom - NewControlRect.Top;
    DockPos := CreateDockPos(AControl, DockBreak, IsVisible,
      NewControlRect.TopLeft, NewControlRect.Right - NewControlRect.Left,
      H, Parent, Insets, RowCount);
    if Parent <> nil then
      PDockPos(Parent).SubItem := DockPos;
    FItems.Insert(InsPos, DockPos);
    { If we're adding an item that spans more than one row, we need to add
      pseudo items which are linked to this item. }
    if RowCount > 1 then
    begin
      Dec(RowCount);
      Inc(NewControlRect.Top, RowSize);
      DockControl(AControl, NewControlRect, BreakList, IndexList, SizeList,
        DockPos, False, Insets, PreferredSize, RowCount, False);
    end;
  end;

begin
  FDockingControl := AControl;
  if BreakList.Count > 0 then
  begin
    PrevBreak := Boolean(BreakList[0]);
    BreakList.Delete(0);
  end
  else
    PrevBreak := False;
  if IndexList.Count > 0 then
  begin
    PrevIndex := Integer(IndexList[0]);
    IndexList.Delete(0);
  end
  else
    PrevIndex := -1;
  if SizeList.Count > 0 then
  begin
    PrevInsetHeight := Integer(SizeList[0]);
    SizeList.Delete(0);
  end
  else
    PrevInsetHeight := -1;

  InsPos := 0;
  Size := -MaxInt;
  TotalSize := -MaxInt;

  NewControlRect := ARect;
  if RowCount < 0 then
    with AControl do
    begin
      PreferredSize := ARect.Right - ARect.Left;
      Insets := DefaultInsets;
      if PrevInsetHeight < 0 then
        PrevInsetHeight := Insets.Top + Insets.Bottom;
      { Try to fit control into row size }
      NewHeight := PrevInsetHeight + NewControlRect.Bottom - NewControlRect.Top;
      if RowSnap then
      begin
        RowCount := NewHeight div RowSize;
        if RowCount = 0 then
          Inc(RowCount);
        if Existing and (NewHeight > RowSize * RowCount) then
          Inc(RowCount);
      end
      else
        RowCount := 1;
      GetControlInfo(AControl, Insets, PreferredSize, RowCount);
      if RowCount = 0 then RowCount := 1;
      if RowSnap and Existing and (NewHeight > RowSize * RowCount) then
        RowCount := NewHeight div RowSize + 1;
      NewControlRect.Right := NewControlRect.Left + PreferredSize;
      AdjustControlRect(NewControlRect, Insets);
      if RowSnap then
        NewControlRect.Bottom := NewControlRect.Top + RowSize * RowCount;
    end;

  IsVisible := (csDesigning in Self.ComponentState) or AControl.Visible;
  MidPoint.Y := NewControlRect.Top + RowSize div 2;
  DockBreak := False;
  NewLine := False;

  for I := 0 to FItems.Count - 1 do
  begin
    DockPos := PDockPos(FItems[I]);
    ControlRect := Rect(DockPos^.Pos.X, DockPos^.Pos.Y, DockPos^.Pos.X +
      DockPos^.Width, DockPos^.Pos.Y + DockPos^.Height );
    with ControlRect do
    begin
      if Bottom - Top > Size then
        Size := Bottom - Top;
      if Bottom > TotalSize then
        TotalSize := Bottom;

      if (NewControlRect.Left > Left) and (MidPoint.Y > Top) then
      begin
        DockBreak := False;
        InsPos := I + 1;
      end;
    end;

    if (I = FItems.Count - 1) or ((I + 1 = PrevIndex) and (PrevBreak)) or
      PDockPos(FItems[I + 1])^.Break then
    begin
      if MidPoint.Y < TotalSize then
      begin
        NewLine := (InsPos = 0) and (MidPoint.Y < ControlRect.Top);
        AddItem;
        Exit;
      end
      else
      begin
        DockBreak := (ControlRect.Left > NewControlRect.Left) or
          ((DockPos^.SubItem = nil));
        InsPos := I + 1;
      end;
      if RowSnap then
        Size := RowSize else
        Size := 0;
    end;
  end;
  AddItem;
end;

procedure TCustomControlBar.UnDockControl(AControl: TControl);
var
  I: Integer;
  DockPos: PDockPos;
begin
  FDockingControl := AControl;
  for I := 0 to FItems.Count - 1 do
  begin
    DockPos := PDockPos(FItems[I]);
    if DockPos^.Control = AControl then
    begin
      if DockPos^.Break and (I < FItems.Count - 1) then
        PDockPos(FItems[I + 1])^.Break := True;
      FreeDockPos(FItems, DockPos);
      Break;
    end;
  end;
end;

procedure TCustomControlBar.GetControlInfo(AControl: TControl; var Insets: TRect;
  var PreferredSize, RowCount: Integer);
begin
  if RowCount = 0 then RowCount := 1;
  if Assigned(FOnBandInfo) then FOnBandInfo(Self, AControl, Insets,
    PreferredSize, RowCount);
end;

procedure TCustomControlBar.PaintControlFrame(Canvas: TCanvas; AControl: TControl;
  var ARect: TRect);
const
  Offset = 3;
var
  R: TRect;
  Options: TBandPaintOptions;

  procedure DrawGrabber;
  begin
    with Canvas, R do
    begin
      Pen.Color := clBtnHighlight;
      MoveTo(R.Left+2, R.Top);
      LineTo(R.Left, R.Top);
      LineTo(R.Left, R.Bottom+1);
      Pen.Color := clBtnShadow;
      MoveTo(R.Right, R.Top);
      LineTo(R.Right, R.Bottom);
      LineTo(R.Left, R.Bottom);
    end;
  end;

begin
  Options := [bpoGrabber, bpoFrame];
  DoBandPaint(AControl, Canvas, ARect, Options);
  with Canvas do
  begin
    if not Assigned(Picture.Graphic) then
    begin
      Canvas.Brush.Color := Color;
      Canvas.FillRect(ARect);
    end;
    if bpoFrame in Options then
      DrawEdge(Canvas, ARect, esRaised, esNone, ebRect);
    if bpoGrabber in Options then
    begin
      R := Rect(ARect.Left + Offset, ARect.Top + 2, ARect.Left + Offset + 2,
        ARect.Bottom - 3);
      DrawGrabber;
    end;
  end;
end;

procedure TCustomControlBar.Paint;
const
  EdgeMap: array[TBevelCut] of TEdgeStyle = (esNone, esLowered, esRaised);
var
  I: Integer;
  DockPos: PDockPos;
  Control: TControl;
  R: TRect;
  Save: Boolean;
  Rgn, Rgn1: QRegionH;
begin
  with Canvas do
  begin
    R := ClientRect;
    Rgn := QRegion_create(@R, QRegionRegionType_rectangle);

    for I := 0 to FItems.Count - 1 do
    begin
      DockPos := PDockPos(FItems[I]);
      Control := DockPos^.Control;
      if (DockPos^.Parent = nil) and ((csDesigning in ComponentState) or
        Control.Visible) then
      begin
        R := Control.BoundsRect;
       if (not DockPos.Dirty) and MouseCapture then
        with DockPos^.Insets do //include the control frame in clipping region.
        begin
          Dec(R.Left, Left);
          Dec(R.Top, Top);
          Inc(R.Right, Right);
          Inc(R.Bottom, Bottom);
          Rgn1 := QRegion_create(@R, QRegionRegionType_Rectangle);
          QRegion_subtract(Rgn, Rgn, Rgn1);
          QRegion_destroy(Rgn1);
        end;
      end;
    end;
    QPainter_setClipRegion(Canvas.Handle, Rgn);

    R := ClientRect;
    if Picture.Graphic <> nil then
    begin
      Save := FDrawing;
      FDrawing := True;
      try
        // Tile image across client area
        Canvas.TiledDraw(R, Picture.Graphic);
      finally
        FDrawing := Save;
      end;
    end
    else begin
      Brush.Color := Color;
      Brush.Style := bsSolid;
      FillRect(R);
    end;

    QPainter_setClipping(Canvas.Handle, False);
    QRegion_destroy(Rgn);
    if Assigned(FOnPaint) then FOnPaint(Self);
    { Draw grabbers and frames for each control }

    for I := 0 to FItems.Count - 1 do
    begin
      DockPos := PDockPos(FItems[I]);
      Control := DockPos^.Control;
      if (DockPos^.Parent = nil) and ((csDesigning in ComponentState) or
        Control.Visible) then
      begin
        R := Control.BoundsRect;
        with DockPos^.Insets do
        begin
          Dec(R.Left, Left);
          Dec(R.Top, Top);
          Inc(R.Right, Right);
          Inc(R.Bottom, Bottom);
        end;
        if DockPos.Dirty or not MouseCapture then
          PaintControlFrame(Canvas, Control, R);
        DockPos.Dirty := False;
      end;
    end;

    R := Rect(0, 0, Width, Height);
    DrawEdge(Canvas, R, EdgeMap[FBevelInner], EdgeMap[FBevelOuter],
      TEdgeBorders(FBevelEdges));
  end;
end;

function TCustomControlBar.HitTest(X, Y: Integer): TControl;
var
  DockPos: PDockPos;
begin
  DockPos := HitTest2(X, Y);
  if DockPos <> nil then
    Result := DockPos^.Control else
    Result := nil;
end;

function TCustomControlBar.HitTest2(X, Y: Integer): Pointer;
var
  I: Integer;
  R: TRect;
begin
  for I := 0 to FItems.Count - 1 do
  begin
    Result := PDockPos(FItems[I]);
    with PDockPos(Result)^ do
      if (Parent = nil) and ((csDesigning in ComponentState) or
        Control.Visible) then
      begin
        R := Control.BoundsRect;
        with Insets do
        begin
          Dec(R.Left, Left);
          Dec(R.Top, Top);
          Inc(R.Right, Right);
          Inc(R.Bottom, Bottom);
        end;
        if PtInRect(R, Point(X, Y)) then Exit;
      end;
  end;
  Result := nil;
end;

function TCustomControlBar.HitTest3(X, Y: Integer): TControl;
var
  R: TRect;
  DockPos: PDockPos;
begin
  Result := nil;
  DockPos := HitTest2(X, Y);
  if DockPos <> nil then
  begin
    R := DockPos.Control.BoundsRect;
    R.Right := R.Left;
    Dec(R.Left, DockPos.Insets.Left);
    if PtInRect(R, Point(X, Y)) then
      Result := DockPos.Control;
  end;
end;

procedure TCustomControlBar.DoAlignControl(AControl: TControl);
var
  Rect: TRect;
begin
  if not HandleAllocated or (csDestroying in ComponentState) then Exit;
  DisableAlign;
  try
    Rect := GetClientRect;
    AlignControls(AControl, Rect);
  finally
    ControlState := ControlState - [csAlignmentNeeded];
    EnableAlign;
  end;
end;

procedure TCustomControlBar.MouseDown(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
var
  DockPos: PDockPos;

  procedure ResetDockItems;
  var
    I: Integer;
  begin
    for I := FItems.Count - 1 downto 0 do
      FreeMem(PDockPos(FItems[I]), SizeOf(TDockPos));
    FItems.Clear;
    FDragControl := nil;
    FDockingControl := nil;
    DoAlignControl(nil);
  end;

begin
  inherited MouseDown(Button, Shift, X, Y);
  if MouseCapture then
  begin
    ResetDockItems;
    if FDragControl <> nil then
      DockPos := FindPos(FDragControl) else
      DockPos := HitTest2(X, Y);
    if (DockPos <> nil) and (not (ssDouble in Shift) or not (FAutoDrag or
      (ssDouble in Shift)) or (csDesigning in ComponentState) or
      not DragControl(DockPos^.Control, X, Y, False)) then
    begin
      FDragControl := DockPos^.Control;
      if FDockingControl = FDragControl then
        FDockingControl := nil
      else
        StickControls;
      FDragOffset := Point(DockPos^.TempPos.X - X, DockPos^.TempPos.Y - Y);
    end;
  end;
end;

procedure TCustomControlBar.MouseMove(Shift: TShiftState; X, Y: Integer);
var
  DockPos: PDockPos;
  Delta: Integer;
  AControl: TControl;
begin
  inherited MouseMove(Shift, X, Y);
  AControl := HitTest3(X, Y);
  if (AControl <> nil) then
  begin
    if FSaveCursor = crNone then
    begin
      FSaveCursor := Cursor;
      Cursor := FGrabCursor;
    end
  end
  else if (FSaveCursor <> crNone) and not MouseCapture then
  begin
    Cursor := FSaveCursor;
    FSaveCursor := crNone;
  end;

  if MouseCapture then
  begin
    if FDragControl <> nil then
    begin
      DockPos := FindPos(FDragControl);
      if DockPos <> nil then
        with DockPos^ do
        begin
          Pos.X := X + FDragOffset.X;
          Pos.Y := Y + FDragOffset.Y;
          TempPos := Pos;
          TempWidth := Control.Width + Insets.Left + Insets.Right;
          { Detect a float operation }
          if not (csDesigning in ComponentState) and FAutoDrag then
          begin
            Delta := Control.Height;
            if (Pos.X < -Delta) or (Pos.Y < -Delta) or
              (Pos.X > ClientWidth + Delta) or (Pos.Y > ClientHeight + Delta) then
            begin
              if DragControl(Control, X, Y, True) then Exit;
            end;
          end;
          DoAlignControl(Control);
        end;
    end;
  end;
end;

procedure TCustomControlBar.MouseUp(Button: TMouseButton; Shift: TShiftState; X,
  Y: Integer);
var
  Control: TControl;
begin
  if FDragControl <> nil then
  begin
    Control := FDragControl;
    FDragControl := nil;
    if FDockingControl = Control then
      FDockingControl := nil
    else
      StickControls;
  end;

  Control := HitTest3(X, Y);
  if (Control <> nil) then
  begin
    if FSaveCursor = crNone then
    begin
      FSaveCursor := Cursor;
      Cursor := FGrabCursor;
    end
  end
  else if (FSaveCursor <> crNone) then
  begin
    Cursor := FSaveCursor;
    FSaveCursor := crNone;
  end;

  inherited MouseUp(Button, Shift, X, Y);
end;

function TCustomControlBar.FindPos(AControl: TControl): Pointer;
var
  I: Integer;
begin
  for I := 0 to FItems.Count - 1 do
    with PDockPos(FItems[I])^ do
    begin
      if (Parent = nil) and (Control = AControl) then
      begin
        Result := FItems[I];
        Exit;
      end;
    end;
  Result := nil;
end;

function TCustomControlBar.DragControl(AControl: TControl; X, Y: Integer;
  KeepCapture: Boolean): Boolean;
begin
  Result := True;
  if (AControl <> nil) and Assigned(FOnBandDrag) then
    FOnBandDrag(Self, AControl, Result);
end;

procedure TCustomControlBar.DoBandMove(Control: TControl; var ARect: TRect);
begin
  if Assigned(FOnBandMove) then FOnBandMove(Self, Control, ARect);
end;

procedure TCustomControlBar.DoBandPaint(Control: TControl; Canvas: TCanvas;
  var ARect: TRect; var Options: TBandPaintOptions);
begin
  if Assigned(FOnBandPaint) then FOnBandPaint(Self, Control, Canvas, ARect, Options);
end;

procedure TCustomControlBar.SetPicture(const Value: TPicture);
begin
  FPicture.Assign(Value);
end;

procedure TCustomControlBar.PictureChanged(Sender: TObject);
begin
  if Picture.Graphic <> nil then
    if FDrawing then Update;
  if not FDrawing then Invalidate;
end;

procedure TCustomControlBar.ControlsListChanged(Control: TControl; Inserting: Boolean);
begin
  inherited;
  if not Inserting then
  begin
    if Control = FDragControl then
      FDragControl := nil;
    UnDockControl(Control);
  end;
  AdjustSize;
  Repaint;
end;

procedure TCustomControlBar.SetBevelEdges(const Value: TBevelEdges);
begin
  FBevelEdges := Value;
  Invalidate;
end;

procedure TCustomControlBar.SetBevelInner(const Value: TBevelCut);
begin
  FBevelInner := Value;
  Invalidate;
end;

procedure TCustomControlBar.SetBevelOuter(const Value: TBevelCut);
begin
  FBevelOuter := Value;
  Invalidate;
end;

function TCustomControlBar.EdgeSpacing(Edge: TBevelEdge): Integer;
begin
  Result := 0;
  if (Edge in FBevelEdges) then
  begin
    if FBevelInner in [bvRaised, bvLowered] then Inc(Result);
    if FBevelOuter in [bvRaised, bvLowered] then Inc(Result);
  end;
end;

function TCustomControlBar.GetClientRect: TRect;
begin
  Result.Left := EdgeSpacing(beLeft);
  Result.Right := Width - EdgeSpacing(beRight);
  Result.Top := EdgeSpacing(beTop);
  Result.Bottom := Height - EdgeSpacing(beBottom);
end;

procedure TCustomControlBar.AdjustSize;
var
  I,
  Dim,
  NewDim: Integer;
  Resized: Boolean;
begin
  if FAutoSize and (FItems.Count > 0) then
  begin
    Resized := False;
    NewDim := 0;
    case Align of
      alTop, alBottom, alNone:
        begin
          for I := 0 to FItems.Count - 1 do
            with PDockPos(FItems[I])^ do
            begin
              Dim := Control.Top + Control.Height + Insets.Bottom;
              if Dim > NewDim then
                NewDim := Dim + EdgeSpacing(beBottom);
            end;
          if NewDim <> Height then
          begin
            Height := NewDim;
            Resized := True;
          end;
        end;
      alLeft, alRight:
        begin
          for I := 0 to FItems.Count -1 do
            with PDockPos(FItems[I])^ do
            begin
              Dim := Control.Left + Control.Width + Insets.Right;
              if Dim > NewDim then
                NewDim := Dim + EdgeSpacing(beLeft);
            end;
          if NewDim <> Width then
          begin
            Width := NewDim;
            Resized := True;
          end;
        end;
    end;
    if Resized then
    begin
      MarkDirty;
      Invalidate;
    end;
  end;
end;

procedure TCustomControlBar.SetAutoSize(const Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    AdjustSize;
  end;
end;

procedure TCustomControlBar.MarkDirty;
var
  I: Integer;
begin
  for I := 0 to FItems.Count - 1 do
    PDockPos(FItems[I]).Dirty := True;
end;

function TCustomControlBar.EventFilter(Sender: QObjectH;
  Event: QEventH): Boolean;
begin
{$IFDEF LINUX}
  if (QEvent_type(Event) = QEventtype_paint)
  and (not FAligning and MouseCapture) then
    Result := True
  else
{$ENDIF}
  Result := inherited EventFilter(Sender, Event);
end;

procedure TImage.Resize;
begin
  if FAutoSize then DoAutoSize;
  inherited Resize;
end;

{$IFDEF MSWINDOWS}
initialization
  StartClassGroup(TControl);
  GroupDescendentsWith(TTimer, QControls.TControl);

finalization
{$ENDIF}

end.

