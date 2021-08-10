{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QControls;

{$P+,S-,W-,R-,T-,H+,X+}

interface

uses
{$IFDEF LINUX}
  Xlib,
{$ENDIF}
{$IFDEF MSWINDOWS}
  Windows,
{$ENDIF}
  Qt, SysUtils, Classes, Types, QGraphics, QMenus, QTypes, Contnrs, QActnList,
  QStyle, QImgList;

const
  CM_BASE = $B000;                                                                    
  CM_PARENTSHOWHINTCHANGED = CM_BASE + 1;
  CM_PARENTCOLORCHANGED = CM_BASE + 2;
  CM_PARENTFONTCHANGED = CM_BASE + 3;
  CM_RECREATEWINDOW = CM_BASE + 4;
  CM_KEYDOWN = CM_BASE + 5;
  CM_WANTKEY = CM_BASE + 6;

  { TModalResult values }

  mrNone     = 0;
  mrOk       = mrNone + 1;
  mrCancel   = mrOk + 1;  
  mrYes      = mrCancel + 1;
  mrNo       = mrYes + 1;
  mrAbort    = mrNo + 1;
  mrRetry    = mrAbort + 1;
  mrIgnore   = mrRetry + 1;
  mrAll      = mrIgnore + 1;
  mrNoToAll  = mrAll + 1;
  mrYesToAll = mrNoToAll + 1;


{ Cursor identifiers }

type
  TCursor = -32768..32767;
  {$NODEFINE TCursor}

  (*$HPPEMIT 'namespace Qcontrols'}*)
  (*$HPPEMIT '{'}*)
  (*$HPPEMIT '#pragma option -b-'*)
  (*$HPPEMIT '  enum TCursor {crMin=-32768, crMax=32767};'}*)
  (*$HPPEMIT '#pragma option -b.'*)
  (*$HPPEMIT '}'*)

const
  crDefault     = TCursor(0);
  crNone        = TCursor(-1);
  crArrow       = TCursor(-2);
  crCross       = TCursor(-3);
  crIBeam       = TCursor(-4);
  crSize        = TCursor(-22);
  crSizeNESW    = TCursor(-6);
  crSizeNS      = TCursor(-7);
  crSizeNWSE    = TCursor(-8);
  crSizeWE      = TCursor(-9);
  crUpArrow     = TCursor(-10);
  crHourGlass   = TCursor(-11);
  crDrag        = TCursor(-12);
  crNoDrop      = TCursor(-13);
  crHSplit      = TCursor(-14);
  crVSplit      = TCursor(-15);
  crMultiDrag   = TCursor(-16);
  crSQLWait     = TCursor(-17);
  crNo          = TCursor(-18);
  crAppStart    = TCursor(-19);
  crHelp        = TCursor(-20);
  crHandPoint   = TCursor(-21);
  crSizeAll     = TCursor(-22);


const
  DrawStage_Pre = 0;
  DrawStage_Post = 1;
  DrawStage_DefaultDraw = 2;

  { min and max values for Word-size Qt keys }
  Key_Word_Lower = Key_Escape;
  Key_Word_Upper = Key_Help;

{ Exception Classes }
type
  EWidgetControlException = class(Exception);
  ECanvasException = class(Exception);

  TBevelCut = (bvNone, bvLowered, bvRaised);
  TBevelEdge = (beLeft, beTop, beRight, beBottom);
  TBevelEdges = set of TBevelEdge;
  
{ Generic message record }

  PMessage = ^TMessage;
  TMessage = record
    Msg: Cardinal;
  end;

  TBroadcastMessage = record
    Msg: Cardinal;
    Handled: Boolean;
  end;

  TCMKeyDown = record
    Msg: Cardinal;
    Handled: Boolean;
    Key: Integer;
    KeyText: WideString;
    Shift: TShiftState;
  end;

  TControl = class;
  TWidgetControl = class;

  THintWindowClass = class of THintWindow;

  PHintInfo = ^THintInfo;
  THintInfo = record
    HintControl: TControl;
    HintWindowClass: THintWindowClass;
    HintPos: TPoint;
    HintMaxWidth: Integer;
    HintColor: TColor;
    CursorRect: TRect;
    CursorPos: TPoint;
    ReshowTimeout: Integer;
    HideTimeout: Integer;
    HintStr: WideString;
    HintData: Pointer;
  end;

  TShowHintEvent = procedure (var HintStr: WideString; var CanShow: Boolean;
    var HintInfo: THintInfo) of object;

{ Dragging objects }

  TDragObject = class(TObject)
  private
    FDragTargetPos: TPoint;
    function GetIsInterApp: Boolean;
  protected
    procedure SetDragImage;
    procedure Finished(Target: TObject; X, Y: Integer; Accepted: Boolean); virtual;
    function GetDragImageIndex: Integer; virtual;
    function GetDragImageHotSpot: TPoint; virtual;
    function GetKeyState: TShiftState;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Assign(Source: TDragObject); virtual;
    procedure HideDragImage; virtual;
    procedure ShowDragImage; virtual;
    property DragTargetPos: TPoint read FDragTargetPos write FDragTargetPos;
    property IsInterAppDrag: Boolean read GetIsInterApp;
    property KeyState: TShiftState read GetKeyState;
  end;

  TBaseDragControlObject = class(TDragObject)
  private
    FControl: TControl;
  protected
    procedure EndDrag(Target: TObject; X, Y: Integer); virtual;
    procedure Finished(Target: TObject; X, Y: Integer; Accepted: Boolean); override;
  public
    constructor Create(AControl: TControl); virtual;
    destructor Destroy; override;
    procedure Assign(Source: TDragObject); override;
    property Control: TControl read FControl write FControl;
  end;

  TDragControlObject = class(TBaseDragControlObject)
  protected
    function GetDragImageHotSpot: TPoint; override;
    function GetDragImageIndex: Integer; override;
  public
    procedure HideDragImage; override;
    procedure ShowDragImage; override;
  end;

{ TControlCanvas }

  TControlCanvas = class(TCanvas)
  private
    FControl: TControl;
    FClipped: Boolean;
    procedure SetControl(AControl: TControl);
    procedure SetClipped(const Value: Boolean);
  protected
    procedure BeginPainting; override;
    procedure CreateHandle; override;
  public
    destructor Destroy; override;
    procedure FreeHandle;
    procedure StartPaint;
    procedure StopPaint;
    property Control: TControl read FControl write SetControl;
    property Clipped: Boolean read FClipped write SetClipped;
  end;

  TQtCanvas = class(TCanvas)
  private
    FQtHandle: QWidgetH;
    FClipped: Boolean;
    procedure SetQtHandle(AQtHandle: QWidgetH);
    procedure SetClipped(const Value: Boolean);
  protected
    procedure BeginPainting; override;
    procedure CreateHandle; override;
  public
    destructor Destroy; override;
    procedure FreeHandle;
    procedure StartPaint;
    procedure StopPaint;
    property QtHandle: QWidgetH read FQtHandle write SetQtHandle;
    property Clipped: Boolean read FClipped write SetClipped;
  end;

{ TControlActionLink }

  TControlActionLink = class(TActionLink)
  protected
    FClient: TControl;
    procedure AssignClient(AClient: TObject); override;
    function IsCaptionLinked: Boolean; override;
    function IsEnabledLinked: Boolean; override;
    function IsHelpLinked: Boolean; override;
    function IsHintLinked: Boolean; override;
    function IsVisibleLinked: Boolean; override;
    function IsOnExecuteLinked: Boolean; override;
    function DoShowHint(var HintStr: WideString): Boolean; virtual;
    procedure SetCaption(const Value: TCaption); override;
    procedure SetEnabled(Value: Boolean); override;
    procedure SetHelpContext(Value: THelpContext); override;
    procedure SetHelpKeyword(const Value: string); override;
    procedure SetHelpType(Value: THelpType); override;
    procedure SetHint(const Value: WideString); override;
    procedure SetVisible(Value: Boolean); override;
    procedure SetOnExecute(Value: TNotifyEvent); override;
  end;

  TControlActionLinkClass = class of TControlActionLink;

{ TControl }

  TAlign = (alNone, alTop, alBottom, alLeft, alRight, alClient, alCustom);

  TScalingFlags = set of (sfLeft, sfTop, sfWidth, sfHeight, sfFont);

  TAnchorKind = (akLeft, akTop, akRight, akBottom);
  TAnchors = set of TAnchorKind;

  TConstraintSize = 0..MaxInt;

  TSizeConstraints = class(TPersistent)
  private
    FControl: TControl;
    FMaxHeight: TConstraintSize;
    FMaxWidth: TConstraintSize;
    FMinHeight: TConstraintSize;
    FMinWidth: TConstraintSize;
    FOnChange: TNotifyEvent;
    procedure SetConstraints(Index: Integer; Value: TConstraintSize);
  protected
    procedure Change; dynamic;
    procedure AssignTo(Dest: TPersistent); override;
    property Control: TControl read FControl;
  public
    constructor Create(Control: TControl); virtual;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  published
    property MaxHeight: TConstraintSize index 0 read FMaxHeight write SetConstraints default 0;
    property MaxWidth: TConstraintSize index 1 read FMaxWidth write SetConstraints default 0;
    property MinHeight: TConstraintSize index 2 read FMinHeight write SetConstraints default 0;
    property MinWidth: TConstraintSize index 3 read FMinWidth write SetConstraints default 0;
  end;

  TControlState = set of (csLButtonDown, csClicked, csPalette,
    csReadingState, csAlignmentNeeded, csFocusing, csCreating,
    csPaintCopy, csCustomPaint, csDestroyingHandle,
    csRecreating, csWidgetPainting, csAlignDisabled);

  TControlStyle = set of (csAcceptsControls, csCaptureMouse,
    csDesignInteractive, csClickEvents, csFramed, csSetCaption, csOpaque,
    csDoubleClicks, csFixedWidth, csFixedHeight, csNoDesignVisible,
    csReplicatable, csNoStdEvents, csDisplayDragImage, csActionClient,
    csMenuEvents, csNoFocus);

  TInputKey = (ikAll, ikArrows, ikChars, ikReturns, ikTabs, ikEdit, ikNav, ikEsc);
  TInputKeys = set of TInputKey;

  TMouseButton = (mbLeft, mbRight, mbMiddle);

  TDragMode = (dmManual, dmAutomatic);

  TDragState = (dsDragEnter, dsDragLeave, dsDragMove);

  TMouseEvent = procedure(Sender: TObject; Button: TMouseButton;
    Shift: TShiftState; X, Y: Integer) of object;
  TMouseMoveEvent = procedure(Sender: TObject; Shift: TShiftState;
    X, Y: Integer) of object;
  TDragOverEvent = procedure(Sender, Source: TObject; X, Y: Integer;
    State: TDragState; var Accept: Boolean) of object;
  TDragDropEvent = procedure(Sender, Source: TObject;
    X, Y: Integer) of object;
  TStartDragEvent = procedure(Sender: TObject;
    var DragObject: TDragObject) of object;
  TEndDragEvent = procedure(Sender, Target: TObject;
    X, Y: Integer) of object;
  TKeyEvent = procedure(Sender: TObject; var Key: Word;
    Shift: TShiftState) of object;
  TMouseWheelEvent = procedure(Sender: TObject; Shift: TShiftState;
    WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean) of object;
  TMouseWheelUpDownEvent = procedure(Sender: TObject; Shift: TShiftState;
    MousePos: TPoint; var Handled: Boolean) of object;
  TKeyPressEvent = procedure(Sender: TObject; var Key: Char) of object;
  TKeyStringEvent = procedure(Sender: TObject; var S: WideString; var Handled: Boolean) of object;
  TConstrainedResizeEvent = procedure(Sender: TObject; var MinWidth, MinHeight,
    MaxWidth, MaxHeight: Integer) of object;
  TContextPopupEvent = procedure(Sender: TObject; MousePos: TPoint; var Handled: Boolean) of object;

  TControl = class(TComponent)
  private
    FVisible: Boolean;
    FHint: WideString;
    FAlign: TAlign;
    FControlState: TControlState;
    FControlStyle: TControlStyle;
    FCursor: TCursor;
    FParent: TWidgetControl;
    FEnabled: Boolean;
    FParentColor: Boolean;
    FColor: TColor;
    FActionLink: TControlActionLink;
    FFont: TFont;
    FFontHeight: Integer;
    FParentShowHint: Boolean;
    FPopupMenu: TPopupMenu;
    FScalingFlags: TScalingFlags;
    FSizedFlags: TScalingFlags;
    FShowHint: Boolean;
    FOnMouseDown: TMouseEvent;
    FOnMouseUp: TMouseEvent;
    FOnMouseMove: TMouseMoveEvent;
    FOnMouseWheel: TMouseWheelEvent;
    FOnMouseWheelDown: TMouseWheelUpDownEvent;
    FOnMouseWheelUp: TMouseWheelUpDownEvent;
    FOnResize: TNotifyEvent;
    FOnDblClick: TNotifyEvent;
    FOnClick: TNotifyEvent;
    FOnDragDrop: TDragDropEvent;
    FOnDragOver: TDragOverEvent;
    FOnEndDrag: TEndDragEvent;
    FOnStartDrag: TStartDragEvent;
    FDragMode: TDragMode;
    FConstraints: TSizeConstraints;
    FOnConstrainedResize: TConstrainedResizeEvent;
    FAnchors: TAnchors;
    FAnchorMove: Boolean;
    FAnchorRules: TPoint;
    FOriginalParentSize: TPoint;
    FOnContextPopup: TContextPopupEvent;
    FHelpContext: THelpContext;
    FHelpFile: string;
    FHelpKeyword: string;
    FHelpType: THelpType;
    FDragObject: TDragObject;
    procedure CMParentColorChanged(var Message: TMessage); message CM_PARENTCOLORCHANGED;
    procedure CMParentFontChanged(var Message: TMessage); message CM_PARENTFONTCHANGED;
    procedure DoActionChange(Sender: TObject);
    procedure DoConstraintsChange(Sender: TObject);
    procedure DoConstrainedResize(var NewWidth, NewHeight: Integer);
    function GetBoundsRect: TRect;
    function GetClientHeight: Integer;
    function GetClientWidth: Integer;
    procedure InternalFontChanged(Sender: TObject);
    function IsEnabledStored: Boolean;
    function IsHintStored: Boolean;
    function IsVisibleStored: Boolean;
    procedure InvalidateControl(IsVisible, IsOpaque: Boolean);
    function DoMouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer): Boolean;
    function DoMouseUp(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer): Boolean;
    procedure SetAlign(const Value: TAlign);
    procedure SetBoundsRect(const Value: TRect);
    procedure SetClientHeight(const Value: Integer);
    procedure SetClientSize(Value: TPoint);
    procedure SetClientWidth(const Value: Integer);
    procedure SetCursor(const Value: TCursor);
    procedure SetHeight(const Value: Integer);
    procedure SetLeft(const Value: Integer);
    procedure SetTop(const Value: Integer);
    procedure SetVisible(const Value: Boolean);
    procedure SetWidth(const Value: Integer);
    procedure SetZOrderPosition(Position: Integer);
    function IsColorStored: Boolean;
    function IsFontStored: Boolean;
    function IsShowHintStored: Boolean;
    function IsOnClickStored: Boolean;
    procedure SetFont(const Value: TFont);
    procedure SetParentColor(const Value: Boolean);
    procedure SetParentFont(const Value: Boolean);
    procedure SetPopupMenu(const Value: TPopupMenu);
    procedure SetDragMode(const Value: TDragMode);
    procedure UpdateAnchorRules;
    function GetColor: TColor;
    procedure SetConstraints(const Value: TSizeConstraints);
    function AreAnchorsStored: Boolean;
    procedure SetAnchors(const Value: TAnchors);
    procedure SetMouseCapture(const Value: Boolean);
    function GetMouseCapture: Boolean;
  protected
    FWidth: Integer;
    FLeft: Integer;
    FTop: Integer;
    FHeight: Integer;
    FParentFont: Boolean;
    procedure ActionChange(Sender: TObject; CheckDefaults: Boolean); dynamic;
    procedure AdjustPainter(Painter: QPainterH); virtual;
    procedure AdjustSize; dynamic;
    procedure BeginAutoDrag; dynamic;
    procedure BoundsChanged; dynamic;
    procedure ChangeBounds(ALeft, ATop, AWidth, AHeight: Integer); virtual;
    procedure ChangeScale(MV, DV, MH, DH: Integer); dynamic;
    procedure Click; dynamic;
    procedure ColorChanged; dynamic;
    procedure ControlsAligned; dynamic;
    procedure CursorChanged; dynamic;
    procedure ConstrainedResize(var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer); virtual;
    procedure DoContextPopup(const MousePos: TPoint; var Handled: Boolean); dynamic;
    function DoMouseWheel(Shift: TShiftState; WheelDelta: Integer;
      const MousePos: TPoint): Boolean; dynamic;
    function DoMouseWheelDown(Shift: TShiftState; const MousePos: TPoint): Boolean; dynamic;
    function DoMouseWheelUp(Shift: TShiftState; const MousePos: TPoint): Boolean; dynamic;
    procedure DoEndDrag(Target: TObject; X, Y: Integer); dynamic;
    procedure DoStartDrag(var DragObject: TDragObject); dynamic;
    procedure DragOver(Source: TObject; X, Y: Integer; State: TDragState;
      var Accept: Boolean); dynamic;
    procedure DblClick; dynamic;
    procedure DragCanceled; dynamic;
    procedure FontChanged; dynamic;
    procedure EnabledChanged; dynamic;
    function GetAction: TBasicAction;
    function GetActionLinkClass: TControlActionLinkClass; dynamic;
    function GetAlignedPaintDevice: QPaintDeviceH; virtual;
    function GetClientRect: TRect; virtual;
    function GetClientOrigin: TPoint; virtual;
    function GetDragImageIndex: Integer; virtual;
    function GetDragImageHotSpot: TPoint; virtual;
    function GetEnabled: Boolean; virtual;
    function GetPaintDevice: QPaintDeviceH; virtual;
    function GetPopupMenu: TPopupMenu; dynamic;
    function GetText: TCaption; virtual;
    function HintShow(var HintInfo : THintInfo): Boolean; dynamic;
    procedure HintShowPause(var WasActive: Boolean; var Pause: Integer); dynamic;
    function HitTest(X, Y: Integer): Boolean; dynamic;
    procedure Loaded; override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); dynamic;
    procedure MouseEnter(AControl: TControl); dynamic;
    procedure MouseLeave(AControl: TControl); dynamic;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); dynamic;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); dynamic;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure ParentColorChanged; dynamic;
    procedure ParentFontChanged; dynamic;
    procedure ParentShowHintChanged; dynamic;
    procedure PaintRequest; dynamic;
    procedure ReadState(Reader: TReader); override;
    procedure RequestAlign; dynamic;
    procedure Resize; dynamic;
    procedure SetAction(Value: TBasicAction);
    procedure SetColor(const Value: TColor);
    procedure SetEnabled(const Value: Boolean); virtual;
    procedure SetHelpContext(const Value: THelpContext); 
    procedure SetHelpKeyword(const Value: String); 
    procedure SetName(const Value: TComponentName); override;
    procedure SetShowHint(Value: Boolean);
    procedure SetParent(const Value: TWidgetControl); virtual;
    procedure SetParentComponent(Value: TComponent); override;
    procedure SetParentShowHint(Value: Boolean);
    procedure SetText(const Value: TCaption); virtual;
    procedure SetZOrder(TopMost: Boolean); virtual;
    procedure ShowHintChanged; dynamic;
    procedure SiblingsFlipped; dynamic;
    procedure TextChanged; dynamic;
    procedure UpdateBoundsRect(const R: TRect);
    procedure VisibleChanging; dynamic;
    procedure VisibleChanged; dynamic;
    function WantKey(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; dynamic;
    procedure CMParentShowHintChanged(var Message: TMessage); message CM_PARENTSHOWHINTCHANGED;
    property ActionLink: TControlActionLink read FActionLink write FActionLink;
    property Caption: TCaption read GetText write SetText;
    property Color: TColor read GetColor write SetColor stored IsColorStored default clWindow;
    property DragMode: TDragMode read FDragMode write SetDragMode default dmManual;
    property DragObject: TDragObject read FDragObject;
    property Font: TFont read FFont write SetFont stored IsFontStored;
    property MouseCapture: Boolean read GetMouseCapture write SetMouseCapture;
    property ParentColor: Boolean read FParentColor write SetParentColor default True;
    property ParentFont: Boolean read FParentFont write SetParentFont default True;
    property ParentShowHint: Boolean read FParentShowHint write SetParentShowHint default True;
    property PopupMenu: TPopupMenu read FPopupMenu write SetPopupMenu;
    property ScalingFlags: TScalingFlags read FScalingFlags write FScalingFlags;
    property Text: TCaption read GetText write SetText;
    property OnClick: TNotifyEvent read FOnClick write FOnClick stored IsOnClickStored;
    property OnConstrainedResize: TConstrainedResizeEvent read FOnConstrainedResize write FOnConstrainedResize;
    property OnContextPopup: TContextPopupEvent read FOnContextPopup write FOnContextPopup;
    property OnDblClick: TNotifyEvent read FOnDblClick write FOnDblClick;
    property OnDragDrop: TDragDropEvent read FOnDragDrop write FOnDragDrop;
    property OnDragOver: TDragOverEvent read FOnDragOver write FOnDragOver;
    property OnEndDrag: TEndDragEvent read FOnEndDrag write FOnEndDrag;
    property OnMouseDown: TMouseEvent read FOnMouseDown write FOnMouseDown;
    property OnMouseMove: TMouseMoveEvent read FOnMouseMove write FOnMouseMove;
    property OnMouseUp: TMouseEvent read FOnMouseUp write FOnMouseUp;
    property OnMouseWheel: TMouseWheelEvent read FOnMouseWheel write FOnMouseWheel;
    property OnMouseWheelDown: TMouseWheelUpDownEvent read FOnMouseWheelDown
      write FOnMouseWheelDown;
    property OnMouseWheelUp: TMouseWheelUpDownEvent read FOnMouseWheelUp write
      FOnMouseWheelUp;
    property OnResize: TNotifyEvent read FOnResize write FOnResize;
    property OnStartDrag: TStartDragEvent read FOnStartDrag write FOnStartDrag;
    property HelpFile: string read FHelpFile write FHelpFile;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure AfterConstruction; override;
    procedure BeginDrag(Immediate: Boolean; Threshold: Integer = -1);
    function ClientToParent(const Point: TPoint; AParent: TWidgetControl = nil): TPoint;
    procedure BringToFront;
    function ClientToScreen(const Point: TPoint): TPoint;
    function Dragging: Boolean;
    procedure DragDrop(Source: TObject; X, Y: Integer); dynamic;
    property Enabled: Boolean read GetEnabled write SetEnabled stored IsEnabledStored default True;
    procedure EndDrag(Drop: Boolean);
    function GetParentComponent: TComponent; override;
    function HasParent: Boolean; override;
    procedure Hide;
    procedure InitiateAction; virtual;
    procedure Invalidate; virtual;
    procedure Refresh;
    procedure Repaint; virtual;
    function ScreenToClient(const Point: TPoint): TPoint;
    function ParentToClient(const Point: TPoint; AParent: TWidgetControl = nil): TPoint;
    procedure SendToBack;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); virtual;
    procedure Show;
    procedure Update; virtual;
    property Action: TBasicAction read GetAction write SetAction;
    property Align: TAlign read FAlign write SetAlign default alNone;
    property Anchors: TAnchors read FAnchors write SetAnchors stored AreAnchorsStored default [akLeft, akTop];
    property BoundsRect: TRect read GetBoundsRect write SetBoundsRect;
    property ClientHeight: Integer read GetClientHeight write SetClientHeight stored False;
    property ClientOrigin: TPoint read GetClientOrigin;
    property ClientRect: TRect read GetClientRect;
    property ClientWidth: Integer read GetClientWidth write SetClientWidth stored False;
    property Constraints: TSizeConstraints read FConstraints write SetConstraints;
    property ControlState: TControlState read FControlState write FControlState;
    property ControlStyle: TControlStyle read FControlStyle write FControlStyle;
    property Parent: TWidgetControl read FParent write SetParent;
    property ShowHint: Boolean read FShowHint write SetShowHint stored IsShowHintStored;
    property Visible: Boolean read FVisible write SetVisible stored IsVisibleStored default True;
  published
    property HelpType: THelpType read FHelpType write FHelpType default htKeyword;
    property HelpContext: THelpContext read FHelpContext write SetHelpContext default 0;
    property HelpKeyword: string read FHelpKeyword write SetHelpKeyword;
    property Left: Integer read FLeft write SetLeft;
    property Top: Integer read FTop write SetTop;
    property Width: Integer read FWidth write SetWidth;
    property Height: Integer read FHeight write SetHeight;
    property Cursor: TCursor read FCursor write SetCursor default crDefault;
    property Hint: WideString read FHint write FHint stored IsHintStored;
  end;

{ TWidgetControlActionLink }

  TWidgetControlActionLink = class(TControlActionLink)
  protected
    FClient: TWidgetControl;
    procedure AssignClient(AClient: TObject); override;
  end;

  TWidgetControlActionLinkClass = class of TWidgetControlActionLink;

{ TWidgetControl }

  TEventFilterMethod = function (Sender: QObjectH; Event: QEventH): Boolean of object cdecl;
  TTabOrder = -1..32767;

  { Incomplete }
  TWidgetControl = class(TControl)
  private
    FParentWidget: QWidgetH;
    FAlignLevel: Word;
    FShowing: Boolean;
    FTabStop: Boolean;
    FBrush: TBrush;
    FControls: TList;
    FStyle: TWidgetStyle;
    FPalette: TWidgetPalette;
    FWidgets: TList;
    FTabList: TList;
    FTabOrder: Integer;
    FHooks: QWidget_hookH;
    FOnKeyDown: TKeyEvent;
    FOnKeyUp: TKeyEvent;
    FOnKeyPress: TKeyPressEvent;
    FOnKeyString: TKeyStringEvent;
    FOnExit: TNotifyEvent;
    FOnEnter: TNotifyEvent;
    FMasked: Boolean;
    FInputKeys: TInputKeys;
    procedure AlignControl(AControl: TControl);
    procedure DestroyedHook; cdecl;
    procedure DoFlipChildren;
    function CheckInputKeys(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean;
    function GetControl(Index: Integer): TControl;
    function GetControlCount: Integer;
    function GetHandle: QWidgetH;
    function GetHooks: QWidget_hookH;
    function GetTabOrder: TTabOrder;
    procedure Insert(AControl: TControl);
    function IsMenuKey(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean;
    procedure Remove(AControl: TControl);
    procedure RemoveFocus(Removing: Boolean);
    procedure SetInitialSize;
    procedure SetParentWidget(const Value: QWidgetH);
    procedure SetTabOrder(const Value: TTabOrder);
    procedure SetTabStop(const Value: Boolean);
    procedure UpdateBounds;
    procedure UpdateShowing;
    procedure UpdateTabOrder(Value: TTabOrder);
    function GetStyle: TWidgetStyle;
    procedure SetStyle(const Value: TWidgetStyle);
    function GetBitmap: TBitmap;
    procedure SetMasked(const Value: Boolean);
    procedure CMKeyDown(var Msg: TCMKeyDown); message CM_KEYDOWN;
    procedure SetBrush(const Value: TBrush);
    function IsBitmapStored: Boolean;
  protected
    FHandle: QWidgetH;
    procedure AdjustForFrame(var ALeft, ATop, AWidth, AHeight: Integer; ToQt: Boolean);
    procedure SetBitmap(const Value: TBitmap); virtual;
    procedure ActionChange(Sender: TObject; CheckDefaults: Boolean); override;
    procedure AdjustClientRect(var Rect: TRect); virtual;
    procedure AdjustPainter(Painter: QPainterH); override;
    function GetChildHandle: QWidgetH; virtual;
    function CustomAlignInsertBefore(C1, C2: TControl): Boolean; virtual;
    procedure CustomAlignPosition(Control: TControl; var NewLeft, NewTop, NewWidth,
      NewHeight: Integer; var AlignRect: TRect); virtual;
    procedure AlignControls(AControl: TControl; var Rect: TRect); virtual;
    procedure ChangeBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    procedure ChangeScale(MV, DV, MH, DH: Integer); override;
    procedure ColorChanged; override;
    procedure ControlsListChanging(Control: TControl; Inserting: Boolean); dynamic;
    procedure ControlsListChanged(Control: TControl; Inserting: Boolean); dynamic;
    procedure CreateHandle;
    procedure Painting(Sender: QObjectH; EventRegion: QRegionH); virtual;
    procedure EnabledChanged; override;
    procedure FontChanged; override;
    function GetAlignedPaintDevice: QPaintDeviceH; override;
    function GetPaintDevice: QPaintDeviceH; override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure InitWidget; virtual;
    procedure CreateWidget; virtual;
    procedure CursorChanged; override;
    procedure DestroyHandle;
    procedure DestroyWidget; virtual;
    procedure DoEnter; dynamic;
    procedure DoExit; dynamic;
    function DesignEventQuery(Sender: QObjectH; Event: QEventH): Boolean; dynamic;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; virtual;
    function MainEventFilter(Sender: QObjectH; Event: QEventH): Boolean; cdecl;
    function FindNextControl(CurControl: TWidgetControl; GoForward, CheckTabStop, CheckParent: Boolean): TWidgetControl;
    procedure FixupTabList;
    function GetActionLinkClass: TControlActionLinkClass; override;
    function GetClientOrigin: TPoint; override;
    function GetClientRect: TRect; override;
    function GetEnabled: Boolean; override;
    function GetParentWidget: QWidgetH; virtual;
    function GetText: TCaption; override;
    procedure HookEvents; virtual;
    procedure KeyDown(var Key: Word; Shift: TShiftState); dynamic;
    procedure KeyUp(var Key: Word; Shift: TShiftState); dynamic;
    procedure KeyPress(var Key: Char); dynamic;
    procedure KeyString(var S: WideString; var Handled: Boolean); dynamic;
    procedure MaskChanged; dynamic;
    function NeedKey(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; dynamic;
    procedure NotifyControls(Msg: Word);
    procedure PaletteChanged(Sender: TObject); dynamic;
    procedure RecreateWidget;
    procedure ReadState(Reader: TReader); override;
    procedure ResetEvents; virtual;
    procedure ReSubmitFlags;
    procedure RestoreWidgetState; virtual;
    procedure SaveWidgetState; virtual;
    procedure ScaleControls(MV, DV: Integer; MH: Integer = 0; DH: Integer = 0);
    procedure ScrollControls(DeltaX, DeltaY: Integer; IsVisible: Boolean);
    procedure SetChildOrder(Child: TComponent; Order: Integer); override;
    procedure SelectFirst;
    function SelectNext(CurControl: TWidgetControl; GoForward, CheckTabStop: Boolean): Boolean;
    procedure SetInitialBounds; virtual;
    procedure SetParent(const Value: TWidgetControl); override;
    procedure SetText(const Value: TCaption); override;
    procedure SetZOrder(TopMost: Boolean); override;
    procedure SetZOrderPosition(Position: Integer);
    procedure ShowingChanged; dynamic;
    procedure ShowControl(AControl: TControl); virtual;
    procedure ShowHintChanged; override;
    procedure StyleChanged(Sender: TObject); dynamic;
    procedure TabStopChanged; dynamic;
    procedure UpdateWidgetShowing; dynamic;
    function ViewportRect: TRect; virtual;
    procedure VisibleChanged; override;
    function WantKey(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; override;
    function WidgetFlags: Integer; virtual;
    procedure WidgetDestroyed; dynamic;
    { procedure CMShowHintChanged(var Message: TMessage); message CM_SHOWHINTCHANGED; }
    property Bitmap: TBitmap read GetBitmap write SetBitmap stored IsBitmapStored;
    property Hooks: QWidget_hookH read GetHooks write FHooks;
    property InputKeys: TInputKeys read FInputKeys write FInputKeys;
    property Masked: Boolean read FMasked write SetMasked default False;
    property Palette: TWidgetPalette read FPalette;
    property Style: TWidgetStyle read GetStyle write SetStyle;
    property OnEnter: TNotifyEvent read FOnEnter write FOnEnter;
    property OnExit: TNotifyEvent read FOnExit write FOnExit;
    property OnKeyDown: TKeyEvent read FOnKeyDown write FOnKeyDown;
    property OnKeyPress: TKeyPressEvent read FOnKeyPress write FOnKeyPress;
    property OnKeyString: TKeyStringEvent read FOnKeyString write FOnKeyString;
    property OnKeyUp: TKeyEvent read FOnKeyUp write FOnKeyUp;
  public
    constructor Create(AOwner: TComponent); override;
    constructor CreateParented(ParentWidget: QWidgetH);
    class function CreateParentedControl(ParentWidget: QWidgetH): TWidgetControl;
    destructor Destroy; override;
    procedure Broadcast(var Message);
    function CanFocus: Boolean; dynamic;
    function ContainsControl(Control: TControl): Boolean;
    function ControlAtPos(const Pos: TPoint; AllowDisabled: Boolean;
      AllowWidgets: Boolean = False): TControl;
    procedure DisableAlign;
    procedure EnableAlign;
    function FindChildControl(const ControlName: string): TControl;
    procedure FlipChildren(AllLevels: Boolean); dynamic;
    function Focused: Boolean; dynamic;
    procedure GetTabOrderList(List: TList); dynamic;
    function HandleAllocated: Boolean;
    procedure HandleNeeded;
    procedure InsertControl(AControl: TControl);
    procedure Invalidate; override;
    procedure InvalidateRect(Rect: TRect; EraseBackground: Boolean);
    procedure InvokeHelp; virtual; 
    procedure RemoveControl(AControl: TControl);
    procedure Realign;
    procedure Repaint; override;
    procedure ScaleBy(MV, DV: Integer; MH: Integer = 0; DH: Integer = 0);
    procedure ScrollBy(DeltaX, DeltaY: Integer); virtual;
    procedure SetFocus; virtual;
    procedure Update; override;
    procedure UpdateControlState;
    property Brush: TBrush read FBrush write SetBrush;
    property Controls[Index: Integer]: TControl read GetControl;
    property ControlCount: Integer read GetControlCount;
    property Handle: QWidgetH read GetHandle; { library }
    property ChildHandle: QWidgetH read GetChildHandle; { library }
    property ParentWidget: QWidgetH read GetParentWidget write SetParentWidget; { library }
    property Showing: Boolean read FShowing;
    property TabOrder: TTabOrder read GetTabOrder write SetTabOrder default -1;
    property TabStop: Boolean read FTabStop write SetTabStop default False;
  end;

  { Provided to simplify VCL source sharing }
  TWinControl = TWidgetControl;

{ TGraphicControl }

  TGraphicControl = class(TControl)
  private
    FCanvas: TCanvas;
  protected
    procedure Paint; virtual; 
    procedure PaintRequest; override;
    property Canvas: TCanvas read FCanvas;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

{ TCustomControl }

  TCustomControl = class(TWidgetControl)
  private
    FCanvas: TCanvas;
    procedure UpdateMask;
  protected
    procedure BoundsChanged; override;
    procedure CreateWidget; override;
    procedure Painting(Sender: QObjectH; EventRegion: QRegionH); override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure Paint; virtual;
    procedure MaskChanged; override;
    procedure DrawMask(Canvas: TCanvas); virtual;
    property Canvas: TCanvas read FCanvas;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Invalidate; override;
  end;

  THintWindow = class(TCustomControl)
  private
    FActivating: Boolean;
  protected
    procedure Paint; override;
    procedure TextChanged; override;
    function WidgetFlags: Integer; override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ActivateHint(Rect: TRect; const AHint: WideString); virtual;
    procedure ActivateHintData(Rect: TRect; const AHint: WideString; AData: Pointer); virtual;
    function CalcHintRect(MaxWidth: Integer; const AHint: WideString; AData: Pointer): TRect; virtual;
    procedure FontChanged; override;
    procedure ReleaseHandle;
    property Color;
  end;

  TBorderStyle = (bsNone, bsSingle, bsDouble, bsRaisedPanel, bsSunkenPanel,
    bsRaised3d, bsSunken3d, bsEtched, bsEmbossed);
  TControlBorderStyle = bsNone..bsSingle;

  TFrameControl = class(TWidgetControl)
  private
    FBorderStyle: TBorderStyle;
    function GetFrameRect: TRect;
    function GetHandle: QFrameH;
    function GetLineWidth: Integer;
    function GetMargin: Integer;
    function GetMidLineWidth: Integer;
    procedure SetFrameRect(const Value: TRect);
    procedure SetLineWidth(const Value: Integer);
    procedure SetMargin(const Value: Integer);
    procedure SetMidLineWidth(const Value: Integer);
    procedure SetBorderStyle(const Value: TBorderStyle);
  protected
    procedure CreateWidget; override;
    function GetClientOrigin: TPoint; override;
    procedure InitWidget; override;
    property BorderStyle: TBorderStyle read FBorderStyle write SetBorderStyle default bsNone;
    property FrameRect: TRect read GetFrameRect write SetFrameRect;
    property LineWidth: Integer read GetLineWidth write SetLineWidth;
    property Margin: Integer read GetMargin write SetMargin;
    property MidLineWidth: Integer read GetMidLineWidth write SetMidLineWidth;
  public
    constructor Create(AOwner: TComponent); override;
    function ContentsRect: TRect;
    property Handle: QFrameH read GetHandle;
  end;

  TMouse = class
  private
    FDragImmediate: Boolean;
    FDragThreshold: Integer;
    function GetCapture: TControl;
    function GetCursorPos: TPoint;
    procedure SetCapture(const Value: TControl);
    procedure SetCursorPos(const Value: TPoint);
  public
    constructor Create;
    destructor Destroy; override;
    property Capture: TControl read GetCapture write SetCapture;
    property CursorPos: TPoint read GetCursorPos write SetCursorPos;
    property DragImmediate: Boolean read FDragImmediate write FDragImmediate;
    property DragThreshold: Integer read FDragThreshold write FDragThreshold;
  end;

function GetShortHint(const Hint: WideString): WideString;
function GetLongHint(const Hint: WideString): WideString;
function GetMouseGrabControl: TControl;
procedure SetMouseGrabControl(Control: TControl);
function FindControl(Handle: QWidgetH): TWidgetControl; overload;
function FindControl(const Pos: TPoint): TWidgetControl; overload;
function FindObject(Handle: QObjectH): TObject;
function FindDragTarget(const Pos: TPoint; AllowDisabled: Boolean): TControl;
procedure AdjustForClient(var ARect: TRect);
function ButtonStateToShiftState(ButtonState: Qt.ButtonState): TShiftState;

{ Cursor related routins }

function CursorToString(Cursor: TCursor): string;
function StringToCursor(const S: string): TCursor;
procedure GetCursorValues(Proc: TGetStrProc);
function CursorToIdent(Cursor: Longint; var Ident: string): Boolean;
function IdentToCursor(const Ident: string; var Cursor: Longint): Boolean;

{ drag and drop routines }

{
  SaveDragDataToStream:
    In:
      Stream: Stream will be populated with the data from the drag originator
      Format: The identifier (mime type) of the format which will be saved in Stream
    Out:
      True if the data was successfully retrieved
}
function SaveDragDataToStream(Stream: TStream; const Format: string): Boolean;
{
  SupportedDragFormats:
    In:
      List: A TStrings decendant which will be populated with the mime types that the drag originator supports
}
procedure SupportedDragFormats(List: TStrings);
{
  AddDragFormat:
    In:
      Format: the identifier (mime type) of this data
      Stream: the data to be associated with Format
    Out:
      True if data was successfully written
}

function AddDragFormat(const Format: string; Stream: TStream): Boolean;
function InDragDropOperation: Boolean;

{
  DragImageList:
    Out:
      returns the global ImageList used for DragImages.  Uses TControl.DragImageIndex to determine the drag image
      and TControl.DragImageHotSpot to determine the offset from the cursor where the display image should be shown.
}
function DragImageList: TImageList;

{ Compatibility routines }
function GetCaptureControl: TControl;
procedure SetCaptureControl(Control: TControl);
procedure GetCursorPos(var P: TPoint);

procedure Beep;

const
  AnchorAlign: array[TAlign] of TAnchors = (
    { alNone }
    [akLeft, akTop],
    { alTop }
    [akLeft, akTop, akRight],
    { alBottom }
    [akLeft, akRight, akBottom],
    { alLeft }
    [akLeft, akTop, akBottom],
    { alRight }
    [akRight, akTop, akBottom],
    { alClient }
    [akLeft, akTop, akRight, akBottom],
    { alCustom }
    [akLeft, akTop]);

procedure AdjustForFrame(Widget: QWidgetH;
  var ALeft, ATop, AWidth, AHeight: Integer; ToQt: Boolean);

implementation

uses
  QConsts, QForms, TypInfo;

procedure Beep;
begin
  QApplication_beep;
end;

{ Hint management routines }

function GetShortHint(const Hint: WideString): WideString;
var
  I: Integer;
begin
  I := Pos('|', Hint);
  if I = 0 then
    Result := Hint
  else
    Result := Copy(Hint, 1, I - 1);
end;

function GetLongHint(const Hint: WideString): WideString;
var
  I: Integer;
begin
  I := Pos('|', Hint);
  if I = 0 then
    Result := Hint
  else
    Result := Copy(Hint, I + 1, Maxint);
end;

procedure ListAdd(var List: TList; Item: Pointer);
begin
  if List = nil then
    List := TList.Create;
  List.Add(Item);
end;

procedure ListRemove(var List: TList; Item: Pointer);
begin
  if List <> nil then
  begin
    List.Remove(Item);
    if List.Count = 0 then
    begin
      List.Free;
      List := nil;
    end;
  end;
end;

{ Cursor translation function }

const
  DeadCursors = 1;

const
  Cursors: array[0..21] of TIdentMapEntry = (
    (Value: crDefault;      Name: 'crDefault'),
    (Value: crArrow;        Name: 'crArrow'),
    (Value: crCross;        Name: 'crCross'),
    (Value: crIBeam;        Name: 'crIBeam'),
    (Value: crSizeNESW;     Name: 'crSizeNESW'),
    (Value: crSizeNS;       Name: 'crSizeNS'),
    (Value: crSizeNWSE;     Name: 'crSizeNWSE'),
    (Value: crSizeWE;       Name: 'crSizeWE'),
    (Value: crUpArrow;      Name: 'crUpArrow'),
    (Value: crHourGlass;    Name: 'crHourGlass'),
    (Value: crDrag;         Name: 'crDrag'),
    (Value: crNoDrop;       Name: 'crNoDrop'),
    (Value: crHSplit;       Name: 'crHSplit'),
    (Value: crVSplit;       Name: 'crVSplit'),
    (Value: crMultiDrag;    Name: 'crMultiDrag'),
    (Value: crSQLWait;      Name: 'crSQLWait'),
    (Value: crNo;           Name: 'crNo'),
    (Value: crAppStart;     Name: 'crAppStart'),
    (Value: crHelp;         Name: 'crHelp'),
    (Value: crHandPoint;    Name: 'crHandPoint'),
    (Value: crSizeAll;      Name: 'crSizeAll'),

    { Dead cursors }
    (Value: crSize;         Name: 'crSize'));

function CursorToString(Cursor: TCursor): string;
begin
  if not CursorToIdent(Cursor, Result) then FmtStr(Result, '%d', [Cursor]);
end;

function StringToCursor(const S: string): TCursor;
var
  L: Longint;
begin
  if not IdentToCursor(S, L) then L := StrToInt(S);
  Result := L;
end;

procedure GetCursorValues(Proc: TGetStrProc);
var
  I: Integer;
begin
  for I := Low(Cursors) to High(Cursors) - DeadCursors do Proc(Cursors[I].Name);
end;

function CursorToIdent(Cursor: Longint; var Ident: string): Boolean;
begin
  Result := IntToIdent(Cursor, Ident, Cursors);
end;

function IdentToCursor(const Ident: string; var Cursor: Longint): Boolean;
begin
  Result := IdentToInt(Ident, Cursor, Cursors);
end;

{ FindControl }

function FindControl(Handle: QWidgetH): TWidgetControl;
var
  Obj: TObject;
begin
  Result := nil;
  if Handle <> nil then
  begin
    Obj := TObject(QClxObjectMap_find(Handle));
    if Obj is TWidgetControl then
      Result := TWidgetControl(Obj);
  end;
end;

function FindObject(Handle: QObjectH): TObject;
begin
  Result := nil;
  if Handle <> nil then
    Result := TObject(QClxObjectMap_find(Handle));
end;

function FindControl(const Pos: TPoint): TWidgetControl;
var
  Handle: QWidgetH;
begin
  {$IFDEF MSWINDOWS}
  Handle := QApplication_widgetAt(@Pos, False);
  {$ENDIF}
  {$IFDEF LINUX}
  Handle := QApplication_widgetAt(@Pos, True);
  {$ENDIF}
  Result := FindControl(Handle);
end;

procedure AdjustForFrame(Widget: QWidgetH;
  var ALeft, ATop, AWidth, AHeight: Integer; ToQt: Boolean);
var
  FramePos: TSize;
  XAdjust: Integer;
  AGeom, AFrameGeom: TRect;
begin
  {$IFDEF LINUX}
  if not QWidget_isVisible(Widget) then Exit;
  {$ENDIF}

  if not QWidget_isTopLevel(Widget) then
    Exit;
  QWidget_Geometry(Widget, @AGeom);
  QWidget_frameGeometry(Widget, @AFrameGeom);
  QWidget_pos(Widget, @FramePos);

  Dec(AGeom.Right, AGeom.Left);
  Dec(AFrameGeom.Right, AFrameGeom.Left);
  XAdjust := (AFrameGeom.Right - AGeom.Right);
  if XAdjust <> 0 then
    XAdjust := XAdjust div 2;
  if ToQt then
  begin
    Inc(ALeft, XAdjust);
    Inc(ATop, AGeom.Top - FramePos.cy);
  end else
  begin
    Dec(ALeft, XAdjust);
    Dec(ATop, AGeom.Top - FramePos.cy);
  end;
end;

function FindDragTarget(const Pos: TPoint; AllowDisabled: Boolean): TControl;
var
  Widget: TWidgetControl;
  Control: TControl;
begin
  Result := nil;
  Widget := FindControl(Pos);
  if Widget <> nil then
  begin
    Result := Widget;
    Control := Widget.ControlAtPos(Widget.ScreenToClient(Pos), AllowDisabled);
    if Control <> nil then Result := Control;
  end;
end;

procedure AdjustForClient(var ARect: TRect);
begin
  Dec(ARect.Right, ARect.Left);
  Dec(ARect.Bottom, ARect.Top);
  ARect.Left := 0;
  ARect.Top := 0;
end;

{ Mouse utility routines }

function ButtonStateToShiftState(ButtonState: QT.ButtonState): TShiftState;
const
  StateMap: array[0..5] of TShiftState = ([ssLeft], [ssRight], [ssMiddle],
    [ssShift], [ssCtrl], [ssAlt]);
var
  I: Integer;
begin
  Result := [];
  for I := Low(StateMap) to High(StateMap) do
    if Integer(ButtonState) and (1 shl I) <> 0 then
      Result := Result + StateMap[I];
end;


{ Mouse Grab Management }

var
  MouseGrabControl: TControl = nil;
  MouseGrabWidget: TWidgetControl = nil;
  
function GetMouseGrabControl: TControl;
begin
  Result := FindControl(QWidget_mouseGrabber);
  if (Result <> nil) and (MouseGrabControl <> nil) and
  (MouseGrabControl.Parent = Result) then
    Result := MouseGrabControl;
end;

function GetCaptureControl: TControl;
begin
  Result := GetMouseGrabControl;
end;

procedure ReleaseMouseGrab;
var
  Grabber: QWidgetH;
begin
  Grabber := QWidget_mouseGrabber;
  if Grabber <> nil then
    QWidget_releaseMouse(Grabber);
  MouseGrabControl := nil;
end;

procedure SetMouseGrabControl(Control: TControl);
begin
  ReleaseMouseGrab;
  if Control <> nil then
  begin
    MouseGrabControl := Control;
    if not (Control is TWidgetControl) then
    begin
      if Control.Parent = nil then
      begin
        MouseGrabControl := nil;
        Exit;
      end;
      Control := Control.Parent;
    end;
    QWidget_grabMouse(TWidgetControl(Control).ChildHandle);
  end;
end;

procedure SetCaptureControl(Control: TControl);
begin
  SetMouseGrabControl(Control);
end;

procedure GetCursorPos(var P: TPoint);
begin
  QCursor_pos(@P);
end;

{ TControlActionLink }

procedure TControlActionLink.AssignClient(AClient: TObject);
begin
  FClient := AClient as TControl;
end;

function TControlActionLink.DoShowHint(var HintStr: WideString): Boolean;
begin
  Result := True;
  if Action is TCustomAction then
  begin
    Result := TCustomAction(Action).DoHint(HintStr);
    if Result and Application.HintShortCuts and
      (TCustomAction(Action).ShortCut <> scNone) then
    begin
      if HintStr <> '' then
        HintStr := WideFormat('%s (%s)', [HintStr, ShortCutToText(TCustomAction(Action).ShortCut)]);
    end;
  end;
end;

function TControlActionLink.IsCaptionLinked: Boolean;
begin
  Result := inherited IsCaptionLinked and
    (FClient.Caption = (Action as TCustomAction).Caption);
end;

function TControlActionLink.IsEnabledLinked: Boolean;
begin
  Result := inherited IsEnabledLinked and
    (FClient.Enabled = (Action as TCustomAction).Enabled);
end;

function TControlActionLink.IsHelpLinked: Boolean;
begin
  Result := inherited IsHelpLinked and
    (FClient.HelpContext = (Action as TCustomAction).HelpContext) and
    (FClient.HelpKeyword = (Action as TCustomAction).HelpKeyword) and
    (FClient.HelpType = (Action as TCustomAction).HelpType);
end;

function TControlActionLink.IsHintLinked: Boolean;
begin
  Result := inherited IsHintLinked and
    (FClient.Hint = (Action as TCustomAction).Hint);
end;

function TControlActionLink.IsVisibleLinked: Boolean;
begin
  Result := inherited IsVisibleLinked and
    (FClient.Visible = (Action as TCustomAction).Visible);
end;

function TControlActionLink.IsOnExecuteLinked: Boolean;
begin
  Result := inherited IsOnExecuteLinked and
    (@FClient.OnClick = @Action.OnExecute);
end;

procedure TControlActionLink.SetCaption(const Value: TCaption);
begin
  if IsCaptionLinked then              
    FClient.Caption := Value;
end;

procedure TControlActionLink.SetEnabled(Value: Boolean);
begin
  if IsEnabledLinked then
    FClient.Enabled := Value;
end;

procedure TControlActionLink.SetHelpContext(Value: THelpContext);
begin
  if IsHelpLinked then
   FClient.HelpContext := Value;
end;

procedure TControlActionLink.SetHelpKeyword(const Value: string);
begin
  if IsHelpLinked then
    FClient.HelpKeyword := Value;
end;

procedure TControlActionLink.SetHelpType(Value: THelpType);
begin
  if IsHelpLinked then
    FClient.HelpType := Value;
end;

procedure TControlActionLink.SetHint(const Value: WideString);
begin
  if IsHintLinked then
    FClient.Hint := Value;
end;

procedure TControlActionLink.SetVisible(Value: Boolean);
begin
  if IsVisibleLinked then
    FClient.Visible := Value;
end;

procedure TControlActionLink.SetOnExecute(Value: TNotifyEvent);
begin
  if IsOnExecuteLinked then
    FClient.OnClick := Value;
end;

{ drag and drop support routines }

type
  TDragOperation = (dopNone, dopDrag);

{$IFDEF LINUX}
  TX11DragFilter = class(TObject)
  private
    FHook: QObject_hookH;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; cdecl;
  protected
    property Hooks: QObject_hookH read FHook;
  public
    constructor Create(AObject: QObjectH);
    destructor Destroy; override;
  end;
{$ENDIF}

var
  DragFreeObject: Boolean;
{$IFDEF LINUX}
  X11DragFilter: TX11DragFilter;
  DragHooked: Boolean = False;
{$ENDIF}
  ClxDragObj: QClxDragObjectH = nil;
  DragControl: TControl = nil;
  InitialDragControl: TControl = nil;
  DragDropEvent: QDropEventH = nil;
  DragHappenned: Boolean = False;
  DragStartPos: TPoint;
  LastDragPos: TPoint;
  LastDragOverControl: TControl = nil;
  DragObject: TDragObject = nil;
  DragOp: TDragOperation;
  DragAccepted: Boolean;
  DragThreshold: Integer;
  ActivatingDrag: Boolean;
  DragImages: TImageList = nil;

function DragImageList: TImageList;
begin
  if not Assigned(DragImages) then
    DragImages := TImageList.Create(nil);
  Result := DragImages;
end;

function SaveDragDataToStream(Stream: TStream; const Format: string): Boolean;
var
  IO: QIODeviceH;
  ByteArray: QByteArrayH;
begin
  Result := False;
  if not Assigned(DragDropEvent) then
    Exit;
  if QDropEvent_provides(DragDropEvent, PChar(Format)) then
  begin
    try
      IO := IODeviceFromStream(Stream);
      ByteArray := nil;

      try
        ByteArray := QByteArray_create(0);
        QDropEvent_encodedData(DragDropEvent, ByteArray, PChar(Format));
        if not Boolean(QIODevice_writeBlock(IO, ByteArray)) then
          Stream.Size := 0;
      finally
        QIODevice_destroy(IO);
        if Assigned(ByteArray) then
          QByteArray_destroy(ByteArray);
      end;

      Result := True;
    except
      Result := False;
    end;
  end;
end;

procedure SupportedDragFormats(List: TStrings);
var
  I: Integer;
  Str: PChar;
begin
  if not Assigned(List) or not Assigned(DragDropEvent) then
    Exit;

  I := 0;
  while True do
  begin
    Str := QDropEvent_format(DragDropEvent, i);
    if Str = nil then
      Exit;
    List.Add(Str);
    Inc(I);
  end;
end;

function AddDragFormat(const Format: string; Stream: TStream): Boolean;
var
  IO: QIODeviceH;
  ByteArray: QByteArrayH;
begin
  Result := False;
  if not Assigned(Stream) then
    Exit;
  try
    IO := IODeviceFromStream(Stream);
    ByteArray := nil;

    try
      ByteArray := QByteArray_create(0);
      QIODevice_readAll(IO, ByteArray);
      QClxDragObject_addFormat(ClxDragObj, PChar(Format), ByteArray);
    finally
      QIODevice_destroy(IO);
      if Assigned(ByteArray) then
        QByteArray_destroy(ByteArray);
    end;
    
    Result := True;
  except
    Result := False;
  end;
end;

function InDragDropOperation: Boolean;
begin
  Result := DragObject <> nil;
end;

procedure DragDone(Drop: Boolean);
var
  APos, TargetPos: TPoint;
  AControl, TargetControl: TControl;
begin
  try
    if Assigned(DragObject) then
    begin
      GetCursorPos(APos);
      TargetControl := FindControl(APos);
      AControl := TargetControl;
      TargetPos := APos;
      if Assigned(AControl) then
      begin
        TargetPos := AControl.ScreenToClient(TargetPos);
        if AControl is TWidgetControl then
          AControl := TWidgetControl(AControl).ControlAtPos(TargetPos, False, False);
        if not Assigned(AControl) then
        begin
          AControl := TargetControl;
          TargetPos := AControl.ScreenToClient(APos);
        end;
        DragObject.Finished(AControl, TargetPos.X, TargetPos.Y, Drop);
      end;
    end;
  finally
    DragControl := nil;
    InitialDragControl := nil;
    if DragFreeObject and Assigned(DragObject) then
      FreeAndNil(DragObject);
    {$IFDEF LINUX}
    if Assigned(X11DragFilter) then
      X11DragFilter.Free;
    {$ENDIF}
    DragObject := nil;
    ClxDragObj := nil;
    DragDropEvent := nil;
    LastDragOverControl := nil;
    ActivatingDrag := False;
    DragOp := dopNone;
  end;
end;

procedure DragStart;
var
  Pt: TPoint;                            
begin
  try
    DragControl := InitialDragControl;
    LastDragOverControl := DragControl;
    DragObject := nil;
    DragFreeObject := False;
    if csLButtonDown in InitialDragControl.ControlState then
    begin
      Pt := Mouse.CursorPos;
      if not (InitialDragControl is TWidgetControl) then
      begin
        Pt := InitialDragControl.Parent.ScreenToClient(Pt);
        QApplication_sendEvent(InitialDragControl.Parent.Handle, QMouseEvent_create(QEventType_MouseButtonRelease, @Pt,
          Integer(ButtonState_LeftButton), Integer(ButtonState_LeftButton)))
      end
      else
        QApplication_sendEvent(TWidgetControl(InitialDragControl).Handle, QMouseEvent_create(QEventType_MouseButtonRelease, @Pt,
          Integer(ButtonState_LeftButton), Integer(ButtonState_LeftButton)));
    end;
    if InitialDragControl is TWidgetControl then
      ClxDragObj := QClxDragObject_create(TWidgetControl(InitialDragControl).Handle, nil)
    else
      ClxDragObj := QClxDragObject_create(InitialDragControl.Parent.Handle, nil);
    InitialDragControl.DoStartDrag(DragObject);
    if DragControl = nil then
      Exit;
    if DragObject = nil then
    begin
      DragObject := TDragControlObject.Create(InitialDragControl);
      DragFreeObject := True;
    end;
    GetCursorPos(LastDragPos);
    QDragObject_drag(ClxDragObj);
    DragHappenned := True;
  finally
    if Assigned(DragObject) then
      DragDone(False);
  end;
end;

procedure DragInitControl(Control: TControl; Immediate: Boolean; Threshold: Integer);
begin
  ActivatingDrag := True;
  if Immediate then
  begin
    DragThreshold := 0;
    InitialDragControl := Control;
    DragStart;
  end
  else
  begin
    DragThreshold := Threshold;
    InitialDragControl := Control;
  end;
end;

procedure CancelDrag;
begin
  if DragObject <> nil then
    DragDone(False);
  DragControl := nil;
  InitialDragControl := nil;
  ActivatingDrag := False;
  DragOp := dopNone;
  LastDragOverControl := nil;
end;

{ TControl }

procedure TControl.ActionChange(Sender: TObject; CheckDefaults: Boolean);
begin
  if Sender is TCustomAction then
    with TCustomAction(Sender) do
    begin
      if not CheckDefaults or (Self.Caption = '') or (Self.Caption = Self.Name) then
        Self.Caption := Caption;
      if not CheckDefaults or (Self.Enabled = True) then
        Self.Enabled := Enabled;
      if not CheckDefaults or (Self.Hint = '') then
        Self.Hint := Hint;
      if not CheckDefaults or (Self.Visible = True) then
        Self.Visible := Visible;
      if not CheckDefaults or not Assigned(Self.OnClick) then
        Self.OnClick := OnExecute;
    end;
end;

procedure TControl.AdjustPainter(Painter: QPainterH);
var
  R: TRect;
begin
  if (Parent.Width > 0) and (Parent.Height > 0) then
  begin
    R := Parent.ViewportRect;
    QPainter_setViewPort(Painter, Left, Top, R.Right - R.Left, R.Bottom - R.Top);
    QPainter_setClipRect(Painter, Left, Top, Width, Height);
  end;
end;

procedure TControl.BeginDrag(Immediate: Boolean; Threshold: Integer);
begin
  if Self is TCustomForm then
    raise EInvalidOperation.CreateRes(@SCannotDragForm);

  if DragControl = nil then
  begin
    if Threshold < 0 then
      Threshold := Mouse.DragThreshold;

    DragInitControl(Self, Immediate, Threshold);
  end;
end;

procedure TControl.BoundsChanged;
begin
  { Notification }
end;

procedure TControl.BringToFront;
begin
  SetZOrder(True);
end;

procedure TControl.ChangeScale(MV, DV, MH, DH: Integer);
var
  X, Y, W, H: Integer;
  Flags: TScalingFlags;
begin
  if (MV <> DV) or (MH <> DH) then
  begin
    if csLoading in ComponentState then
      Flags := ScalingFlags else
      Flags := [sfLeft, sfTop, sfWidth, sfHeight, sfFont];
    if sfLeft in Flags then
      X := MulDiv(FLeft, MH, DH) else
      X := FLeft;
    if sfTop in Flags then
      Y := MulDiv(FTop, MV, DV) else
      Y := FTop;
    if (sfWidth in Flags) and not (csFixedWidth in ControlStyle) then
      if sfLeft in Flags then
        W := MulDiv(FLeft + FWidth, MH, DH) - X else
        W := MulDiv(FWidth, MH, DH)
    else W := FWidth;
    if (sfHeight in Flags) and not (csFixedHeight in ControlStyle) then
      if sfHeight in Flags then
        H := MulDiv(FTop + FHeight, MV, DV) - Y else
        H := MulDiv(FTop, MV, DV )
    else H := FHeight;
    ChangeBounds(X, Y, W, H);
    if not ParentFont and (sfFont in Flags) then
      Font.Size := MulDiv(Font.Size, MV, DV);
  end;
  FScalingFlags := [];
end;

procedure TControl.Click;
begin
  { Call OnClick if assigned and not equal to associated action's OnExecute.
    If associated action's OnExecute assigned then call it, otherwise, call
    OnClick. }
  if Assigned(FOnClick) and (Action <> nil) and (@FOnClick <> @Action.OnExecute) then
    FOnClick(Self)
  else if not (csDesigning in ComponentState) and (ActionLink <> nil) then
    ActionLink.Execute
  else if Assigned(FOnClick) then
    FOnClick(Self);
end;

function TControl.ClientToScreen(const Point: TPoint): TPoint;
var
  Origin: TPoint;
begin
  Origin := ClientOrigin;
  Result.X := Point.X + Origin.X;
  Result.Y := Point.Y + Origin.Y;
end;

constructor TControl.Create(AOwner: TComponent);
begin
  Include(FControlState, csCreating);
  inherited Create(AOwner);
  FControlStyle := [csClickEvents, csSetCaption, csDoubleClicks];
  FConstraints := TSizeConstraints.Create(Self);
  FConstraints.OnChange := DoConstraintsChange;
  FAnchors := [akLeft, akTop];
  FSizedFlags := [];
  FFont := TFont.Create;
  FFont.OnChange := InternalFontChanged;
  FVisible := True;
  FParentFont := True;
  FParentShowHint := True;
  FParentColor := True;
  FEnabled := True;
  FColor := clWindow;
  FHelpType := htKeyword;
end;

procedure TControl.CursorChanged;
begin
  { Notification }
end;

function TControl.DoMouseWheel(Shift: TShiftState; WheelDelta: Integer;
  const MousePos: TPoint): Boolean;
begin
  Result := False;
  if Assigned(FOnMouseWheel) then
    FOnMouseWheel(Self, Shift, WheelDelta, MousePos, Result);
  if not Result then
  begin
    if WheelDelta < 0 then
      Result := DoMouseWheelDown(Shift, MousePos)
    else
      Result := DoMouseWheelUp(Shift, MousePos);
  end;
end;

function TControl.DoMouseWheelDown(Shift: TShiftState;
  const MousePos: TPoint): Boolean;
begin
  Result := False;
  if Assigned(FOnMouseWheelDown) then
    FOnMouseWheelDown(Self, Shift, MousePos, Result);
end;

function TControl.DoMouseWheelUp(Shift: TShiftState; const MousePos: TPoint): Boolean;
begin
  Result := False;
  if Assigned(FOnMouseWheelUp) then
    FOnMouseWheelUp(Self, Shift, MousePos, Result);
end;

procedure TControl.DblClick;
begin
  if Assigned(FOnDblClick) then
    FOnDblClick(Self);
end;

destructor TControl.Destroy;
begin
  FDragObject := nil;
  Application.ControlDestroyed(Self);
  SetParent(nil);
  FActionLink.Free;
  FActionLink := nil;
  FConstraints.Free;
  FFont.Free;
  inherited Destroy;
end;

function TControl.DoMouseDown(Button: TMouseButton; Shift: TShiftState; X,
  Y: Integer): Boolean;
var
  Temp: TPoint;
  PopupMenu: TPopupMenu;
  Control: TControl;
begin
  Result := False;
  if csCaptureMouse in ControlStyle then
    SetMouseGrabControl(Self)
  else if MouseGrabControl <> nil then
    ReleaseMouseGrab;

  MouseDown(Button, Shift, X, Y);

  if Button = mbRight then
  begin
    if csDesigning in ComponentState then Exit;

    Control := Self;
    while (Control <> nil) and not Result do
    begin
      Control.DoContextPopup(Point(X, Y), Result);
      Control := Control.Parent;
    end;

    if Result then Exit;

    Control := Self;
    PopupMenu := GetPopupMenu;
    while (PopupMenu = nil) and (Control <> nil) do
    begin
      PopupMenu := Control.GetPopupMenu;
      if PopupMenu = nil then
        Control := Control.Parent;
    end;
    if (PopupMenu <> nil) and PopupMenu.AutoPopup then
    begin
      Temp := ClientToScreen(Point(X, Y));
      PopupMenu.PopupComponent := Control;
      ReleaseMouseGrab;
      PopupMenu.Popup(Temp.X, Temp.Y);
      Result := True;
    end;
  end;
end;

procedure TControl.DragDrop(Source: TObject; X, Y: Integer);
begin
  if Assigned(FOnDragDrop) then
    FOnDragDrop(Self, Source, X, Y);
end;

function TControl.Dragging: Boolean;
begin
  Result := DragControl = Self;
end;

procedure TControl.EnabledChanged;
begin
  Invalidate;
end;

procedure TControl.EndDrag(Drop: Boolean);
begin
  if Dragging then
    DragDone(Drop);
end;

procedure TControl.FontChanged;
begin
  Invalidate;
end;

procedure TControl.DoActionChange(Sender: TObject);
begin
  if Sender = Action then
    ActionChange(Sender, False);
end;

function TControl.GetBoundsRect: TRect;
begin
  Result.Left := Left;
  Result.Top := Top;
  Result.Right := Left + Width;
  Result.Bottom := Top + Height;
end;

function TControl.GetClientHeight: Integer;
begin
  Result := ClientRect.Bottom;
end;

function TControl.GetClientOrigin: TPoint;
begin
  if Parent = nil then
    raise EInvalidOperation.CreateResFmt(@SParentRequired, [Name]);
  Result := Parent.ClientOrigin;
  Inc(Result.X, FLeft);
  Inc(Result.Y, FTop);
end;

function TControl.GetAction: TBasicAction;
begin
  if ActionLink <> nil then
    Result := ActionLink.Action
  else
    Result := nil;
end;

function TControl.GetAlignedPaintDevice: QPaintDeviceH;
begin
  if Parent = nil then
    raise EInvalidOperation.CreateFmt(SParentRequired, [Name]);
  Result := Parent.GetAlignedPaintDevice;
end;

function TControl.GetActionLinkClass: TControlActionLinkClass;
begin
  Result := TControlActionLink;
end;

function TControl.GetClientRect: TRect;
begin
  Result.Left := 0;
  Result.Top := 0;
  Result.Right := Width;
  Result.Bottom := Height;
end;

function TControl.GetClientWidth: Integer;
begin
  Result := ClientRect.Right;
end;

function TControl.GetEnabled: Boolean;
begin
  Result := FEnabled;
end;

function TControl.GetParentComponent: TComponent;
begin
  Result := Parent;
end;

function TControl.GetPopupMenu: TPopupMenu;
begin
  Result := FPopupMenu;
end;

function TControl.GetText: TCaption;
begin
  Result := ''; 
end;

function TControl.HasParent: Boolean;
begin
  Result := Parent <> nil;
end;

procedure TControl.Hide;
begin
  Visible := False;
end;

function TControl.HitTest(X, Y: Integer): Boolean;
begin
  Result := (X >= 0) and (Y >= 0) and (X < Width) and (Y < Height);
end;

procedure TControl.InitiateAction;
begin
  if ActionLink <> nil then
    ActionLink.Update;
end;

procedure TControl.InternalFontChanged(Sender: TObject);
begin
  FParentFont := False;
  if Font.Height <> FFontHeight then
  begin
    Include(FScalingFlags, sfFont);
    FFontHeight := Font.Height;
  end;
  FontChanged;
end;

procedure TControl.Invalidate;
begin
  InvalidateControl(Visible, csOpaque in ControlStyle);
end;

procedure TControl.InvalidateControl(IsVisible, IsOpaque: Boolean);
var
  Rect: TRect;

  function BackgroundClipped: Boolean;
  var
    R: TRect;
    List: TList;
    I: Integer;
    C: TControl;
  begin
    Result := True;
    List := FParent.FControls;
    I := List.IndexOf(Self);
    while I > 0 do
    begin
      Dec(I);
      C := List[I];
      with C do
        if C.Visible and (csOpaque in ControlStyle) then
        begin
          IntersectRect(R, Rect, BoundsRect);
          if EqualRect(R, Rect) then Exit;
        end;
    end;
    Result := False;
  end;

begin
  if (IsVisible or (csDesigning in ComponentState) and
    not (csNoDesignVisible in ControlStyle)) and (Parent <> nil) and
    Parent.HandleAllocated then
  begin
    Rect := BoundsRect;
    Parent.InvalidateRect(Rect, not (IsOpaque or
      (csOpaque in Parent.ControlStyle) or BackgroundClipped));
  end;
end;

function TControl.IsColorStored: Boolean;
begin
  Result := not ParentColor;
end;

function TControl.IsEnabledStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsEnabledLinked;
end;

function TControl.IsFontStored: Boolean;
begin
  Result := not ParentFont;
end;

function TControl.IsHintStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsHintLinked;
end;

function TControl.IsShowHintStored: Boolean;
begin
  Result := not ParentShowHint;
end;

function TControl.IsOnClickStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsOnExecuteLinked;
end;

function TControl.IsVisibleStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsVisibleLinked;
end;

procedure TControl.MouseDown(Button: TMouseButton; Shift: TShiftState; X,
  Y: Integer);
begin
  if Assigned(FOnMouseDown) then
    FOnMouseDown(Self, Button, Shift, X, Y);
end;

procedure TControl.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  Application.HintMouseMessage(Self, Shift, X, Y);
  if Assigned(FOnMouseMove) then
    FOnMouseMove(Self, Shift, X, Y);
end;

procedure TControl.MouseUp(Button: TMouseButton; Shift: TShiftState; X,
  Y: Integer);
begin
  if Assigned(FOnMouseUp) and not Dragging then
    FOnMouseUp(Self, Button, Shift, X, Y);
end;

procedure TControl.MouseEnter(AControl: TControl);
begin
  if FParent <> nil then
    FParent.MouseEnter(Self);
end;

procedure TControl.MouseLeave(AControl: TControl);
begin
  if FParent <> nil then
    FParent.MouseLeave(Self);
end;

procedure TControl.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Operation = opRemove then
    if AComponent = PopupMenu then
      PopupMenu := nil
    else if AComponent = Action then
      Action := nil;
end;

procedure TControl.ParentColorChanged;
begin
  if FParentColor and Assigned(Parent) then
  begin
    Color := Parent.Color;
    FParentColor := True;
  end;
end;

procedure TControl.ParentFontChanged;
begin
  if FParentFont and Assigned(Parent) then
  begin
    Font := Parent.Font;
    FParentFont := True;
  end;
end;

procedure TControl.ParentShowHintChanged;
var
  Message: TMessage;
begin
  CMParentShowHintChanged(Message);
end;

procedure TControl.Refresh;
begin
  Repaint;
end;

procedure TControl.Repaint;
begin
  if (Visible or (csDesigning in ComponentState) and
    not (csNoDesignVisible in ControlStyle)) and (Parent <> nil) and
    Parent.HandleAllocated then
  begin
    Invalidate;
    Update;
  end;
end;

procedure TControl.CMParentColorChanged(var Message: TMessage);
begin
  ParentColorChanged;
end;

procedure TControl.CMParentFontChanged(var Message: TMessage);
begin
  ParentFontChanged;
end;

procedure TControl.BeginAutoDrag;
begin
  BeginDrag(Mouse.DragImmediate, Mouse.DragThreshold);
end;

procedure TControl.DragCanceled;
begin
  { Notification }
end;

procedure TControl.DoStartDrag(var DragObject: TDragObject);
begin
  if Assigned(FOnStartDrag) then
    FOnStartDrag(Self, DragObject);
end;

procedure TControl.DoEndDrag(Target: TObject; X, Y: Integer);
begin
  if Assigned(FOnEndDrag) then
    FOnEndDrag(Self, Target, X, Y);
end;

procedure TControl.SetDragMode(const Value: TDragMode);
begin
  FDragMode := Value;
end;

procedure TControl.DragOver(Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  Accept := Assigned(FOnDragOver) or Assigned(FOnDragDrop);
  if Assigned(FOnDragOver) then
    FOnDragOver(Self, Source, X, Y, State, Accept);
end;

function TControl.GetDragImageIndex: Integer;
begin
  Result := -1;
end;

function TControl.GetDragImageHotSpot: TPoint;
begin
  Result := Point(-1, -1);
end;

procedure TControl.ColorChanged;
begin
  Invalidate;
end;

procedure TControl.AfterConstruction;
begin
  inherited AfterConstruction;
  Exclude(FControlState, csCreating);
end;

procedure TControl.SetConstraints(const Value: TSizeConstraints);
begin
  FConstraints.Assign(Value);
end;

procedure TControl.DoConstraintsChange(Sender: TObject);
begin
  AdjustSize;
end;

procedure TControl.AdjustSize;
begin
  if not (csLoading in ComponentState) then SetBounds(Left, Top, Width, Height);
end;

procedure TControl.DoConstrainedResize(var NewWidth, NewHeight: Integer);
var
  MinWidth, MinHeight, MaxWidth, MaxHeight: Integer;
begin
  if Constraints.MinWidth > 0 then
    MinWidth := Constraints.MinWidth
  else
    MinWidth := 0;
  if Constraints.MinHeight > 0 then
    MinHeight := Constraints.MinHeight
  else
    MinHeight := 0;
  if Constraints.MaxWidth > 0 then
    MaxWidth := Constraints.MaxWidth
  else
    MaxWidth := 0;
  if Constraints.MaxHeight > 0 then
    MaxHeight := Constraints.MaxHeight
  else
    MaxHeight := 0;
  { Allow override of constraints }
  ConstrainedResize(MinWidth, MinHeight, MaxWidth, MaxHeight);
  if (MaxWidth > 0) and (NewWidth > MaxWidth) then
    NewWidth := MaxWidth
  else if (MinWidth > 0) and (NewWidth < MinWidth) then
    NewWidth := MinWidth;
  if (MaxHeight > 0) and (NewHeight > MaxHeight) then
    NewHeight := MaxHeight
  else if (MinHeight > 0) and (NewHeight < MinHeight) then
    NewHeight := MinHeight;
end;

procedure TControl.ConstrainedResize(var MinWidth, MinHeight, MaxWidth,
  MaxHeight: Integer);
begin
  if Assigned(FOnConstrainedResize) then
    FOnConstrainedResize(Self, MinWidth, MinHeight, MaxWidth, MaxHeight);
end;

function TControl.AreAnchorsStored: Boolean;
begin
  Result := Anchors <> AnchorAlign[Align];
end;

procedure TControl.SetAnchors(const Value: TAnchors);
begin
  if FAnchors <> Value then
  begin
    FAnchors := Value;
    UpdateAnchorRules;
  end;
end;

procedure TControl.UpdateAnchorRules;
var
  Anchors: TAnchors;
begin
  if not FAnchorMove and not (csLoading in ComponentState) then
  begin
    Anchors := FAnchors;
    if Anchors = [akLeft, akTop] then Exit;
    if akRight in Anchors then
      if akLeft in Anchors then
        FAnchorRules.X := Width
      else
        FAnchorRules.X := Left
    else
      FAnchorRules.X := Left + Width div 2;
    if akBottom in Anchors then
      if akTop in Anchors then
        FAnchorRules.Y := Height
      else
        FAnchorRules.Y := Top
    else
      FAnchorRules.Y := Top + Height div 2;
    if (Parent <> nil) and not (csReading in Parent.ComponentState) then
      if Parent.HandleAllocated then
        FOriginalParentSize := Parent.ClientRect.BottomRight
      else
      begin
        FOriginalParentSize.X := Parent.Width;
        FOriginalParentSize.Y := Parent.Height;
      end;
  end;
end;

procedure TControl.Loaded;
begin
  inherited Loaded;
  UpdateAnchorRules;
end;

function TControl.ClientToParent(const Point: TPoint; AParent: TWidgetControl): TPoint;
var
  LParent: TWidgetControl;
begin
  if AParent = nil then
    AParent := Parent;
  if AParent = nil then
    raise EInvalidOperation.CreateFmt(SParentRequired, [Name]);
  Result := Point;
  Inc(Result.X, Left);
  Inc(Result.Y, Top);
  LParent := Parent;
  while LParent <> nil do
  begin
    if LParent.Parent <> nil then
    begin
      Inc(Result.X, LParent.Left);
      Inc(Result.Y, LParent.Top);
    end;
    if LParent = AParent then
      Break
    else
      LParent := LParent.Parent;
  end;
  if LParent = nil then
    raise EInvalidOperation.CreateFmt(SParentGivenNotAParent, [Name]);
end;

function TControl.ParentToClient(const Point: TPoint; AParent: TWidgetControl): TPoint;
var
  LParent: TWidgetControl;
begin
  if AParent = nil then
    AParent := Parent;
  if AParent = nil then
    raise EInvalidOperation.CreateFmt(SParentRequired, [Name]);
  Result := Point;
  Dec(Result.X, Left);
  Dec(Result.Y, Top);
  LParent := Parent;
  while LParent <> nil do
  begin
    if LParent.Parent <> nil then
    begin
      Dec(Result.X, LParent.Left);
      Dec(Result.Y, LParent.Top);
    end;
    if LParent = AParent then
      Break
    else
      LParent := LParent.Parent;
  end;
  if LParent = nil then
    raise EInvalidOperation.CreateFmt(SParentGivenNotAParent, [Name]);
end;

function TControl.GetMouseCapture: Boolean;
begin
  Result := Mouse.Capture = Self;
end;

procedure TControl.SetMouseCapture(const Value: Boolean);
begin
  if Value then
    Mouse.Capture := Self
  else
    Mouse.Capture := nil;
end;

procedure TControl.DoContextPopup(const MousePos: TPoint; var Handled: Boolean);
begin
  if Assigned(FOnContextPopup) then
    FOnContextPopup(Self, MousePos, Handled);
end;

procedure TControl.SetParentComponent(Value: TComponent);
begin
  if (Parent <> Value) and (Value is TWidgetControl) then
    SetParent(TWidgetControl(Value));
end;

procedure TControl.SetHelpContext(const Value: THelpContext);
begin
  if not (csLoading in ComponentState) then FHelpType := htContext;
  FHelpContext := Value;
end;

procedure TControl.SetHelpKeyword(const Value: String);
begin
  if not (csLoading in ComponentState) then FHelpType := htKeyword;
  FHelpKeyword := Value;
end;

procedure TControl.SetName(const Value: TComponentName);
var
  ChangeText: Boolean;
begin
  ChangeText := (csSetCaption in ControlStyle) and
    not (csLoading in ComponentState) and (Name = Text) and
    ((Owner = nil) or not (Owner is TControl) or
    not (csLoading in TControl(Owner).ComponentState));
  inherited SetName(Value);
  if ChangeText then Text := Value;
end;

function TControl.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  Result := False;
end;

{ TWidgetControl }

procedure TWidgetControl.ResetEvents;
var
  I, Count: Integer;
  PropInfo: PPropInfo;
  TempList: PPropList;
  OrigMethod: TMethod;
  NilMethod: TMethod;
begin
  Count := GetPropList(PTypeInfo(ClassInfo), TempList);
  if Count > 0 then
  begin
    try
      NilMethod.Code := nil;
      for I := 0 to Count - 1 do
      begin
        PropInfo := TempList^[I];
        if PropInfo^.PropType^.Kind = tkMethod then
        begin
          OrigMethod := GetMethodProp(Self, PropInfo);
          if Assigned(OrigMethod.Code) then
          begin
            SetMethodProp(Self, PropInfo, NilMethod);
            SetMethodProp(Self, PropInfo, OrigMethod);
          end;
        end;
      end;
    finally
      FreeMem(TempList);
    end;
  end;
end;

procedure TWidgetControl.RestoreWidgetState;
begin
  { This should restore any state stored in SaveWidgetState }
  FontChanged;
  PaletteChanged(Palette);
end;

procedure TWidgetControl.SaveWidgetState;
begin
{
  This is called when the widget is being recreated. Descendents should
  override this to preserve, temporarily, any state stored only in the widget.
}
end;

procedure TControl.RequestAlign;
begin
  if Parent <> nil then
    Parent.AlignControl(Self);
end;

procedure TControl.Resize;
begin
  if Assigned(FOnResize) then
    FOnResize(Self);
end;

function TControl.ScreenToClient(const Point: TPoint): TPoint;
var
  Origin: TPoint;
begin
  Origin := ClientOrigin;
  Result.X := Point.X - Origin.X;
  Result.Y := Point.Y - Origin.Y;
end;

procedure TControl.SendToBack;
begin
  SetZOrder(False);
end;

procedure TControl.SetAlign(const Value: TAlign);
var
  OldAlign: TAlign;
begin
  if FAlign <> Value then
  begin
    OldAlign := FAlign;
    FAlign := Value;
    Anchors := AnchorAlign[Value];
    if not (csLoading in ComponentState) and (not (csDesigning in ComponentState) or
      (Parent <> nil)) then
      if ((OldAlign in [alTop, alBottom]) = (Value in [alRight, alLeft])) and
        not (OldAlign in [alNone, alClient]) and not (Value in [alNone, alClient]) then
        SetBounds(Left, Top, Height, Width)
      else
        AdjustSize;
    RequestAlign;
  end;
end;

procedure TControl.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  ChangeBounds(ALeft, ATop, AWidth, AHeight);
  FSizedFlags := FSizedFlags + [sfLeft, sfTop, sfWidth, sfHeight];
end;

procedure TControl.SetBoundsRect(const Value: TRect);
begin
  with Value do
    SetBounds(Left, Top, Right - Left, Bottom - Top);
end;

procedure TControl.SetClientHeight(const Value: Integer);
begin
  SetClientSize(Point(ClientWidth, Value));
end;

procedure TControl.SetClientSize(Value: TPoint);
var
  Client: TRect;
begin
  Client := GetClientRect;
  ChangeBounds(FLeft, FTop, Width - Client.Right + Value.X, Height -
    Client.Bottom + Value.Y);
  FSizedFlags := FSizedFlags + [sfWidth, sfHeight];
end;

procedure TControl.SetClientWidth(const Value: Integer);
begin
  SetClientSize(Point(Value, ClientHeight));
end;

procedure TControl.SetColor(const Value: TColor);
begin
  if FColor <> Value then
  begin
    FColor := Value;
    FParentColor := False;
    ColorChanged;
  end;
end;

procedure TControl.SetCursor(const Value: TCursor);
begin
  if FCursor <> Value then
  begin
    FCursor := Value;
    CursorChanged;
  end;
end;

procedure TControl.SetAction(Value: TBasicAction);
begin
  if Value = nil then
  begin
    ActionLink.Free;
    ActionLink := nil;
    Exclude(FControlStyle, csActionClient);
  end
  else
  begin
    Include(FControlStyle, csActionClient);
    if ActionLink = nil then
      ActionLink := GetActionLinkClass.Create(Self);
    ActionLink.Action := Value;
    ActionLink.OnChange := DoActionChange;
    ActionChange(Value, csLoading in Value.ComponentState);
    Value.FreeNotification(Self);
  end;
end;

procedure TControl.SetEnabled(const Value: Boolean);
begin
  if FEnabled <> Value then
  begin
    FEnabled := Value;
    EnabledChanged;
  end;
end;

procedure TControl.SetFont(const Value: TFont);
begin
  Font.Assign(Value);
end;

procedure TControl.SetHeight(const Value: Integer);
begin
  ChangeBounds(FLeft, FTop, FWidth, Value);
  Include(FScalingFlags, sfHeight);
  Include(FSizedFlags, sfHeight);
end;

procedure TControl.SetLeft(const Value: Integer);
begin
  ChangeBounds(Value, FTop, FWidth, FHeight);
  Include(FScalingFlags, sfLeft);
  Include(FSizedFlags, sfLeft);
end;

procedure TControl.SetParent(const Value: TWidgetControl);
begin
  if FParent <> Value then
  begin
    if Value = Self then
      raise EInvalidOperation.CreateRes(@SControlParentSetToSelf);
    if FParent <> nil then
      FParent.RemoveControl(Self);
    if Value <> nil then
    begin
      Value.InsertControl(Self);
      UpdateAnchorRules;
    end;
  end;
end;

procedure TControl.SetParentColor(const Value: Boolean);
begin
  FParentColor := Value;
  ParentColorChanged;
end;

procedure TControl.SetParentFont(const Value: Boolean);
begin
  if FParentFont <> Value then
  begin
    FParentFont := Value;
    ParentFontChanged;
  end;
end;

procedure TControl.SetPopupMenu(const Value: TPopupMenu);
begin
  if Value <> nil then
    Value.FreeNotification(Self);
  FPopupMenu := Value;
end;

procedure TControl.SetShowHint(Value: Boolean);
begin
  if FShowHint <> Value then
  begin
    FShowHint := Value;
    FParentShowHint := False;
    ShowHintChanged;
  end;
end;

procedure TControl.SetParentShowHint(Value: Boolean);
begin
  if FParentShowHint <> Value then
  begin
    FParentShowHint := Value;
    if FParent <> nil then
      ParentShowHintChanged;
  end;
end;

procedure TControl.SetText(const Value: TCaption);
begin
  if GetText <> Value then 
    TextChanged;
end;

procedure TControl.SetTop(const Value: Integer);
begin
  ChangeBounds(FLeft, Value, FWidth, FHeight);
  Include(FScalingFlags, sfTop);
  Include(FSizedFlags, sfTop);
end;

procedure TControl.SetVisible(const Value: Boolean);
begin
  if FVisible <> Value then
  begin
    VisibleChanging;
    FVisible := Value;
    VisibleChanged;
    RequestAlign;
  end;
end;

procedure TControl.SetWidth(const Value: Integer);
begin
  ChangeBounds(FLeft, FTop, Value, FHeight);
  Include(FScalingFlags, sfWidth);
  Include(FSizedFlags, sfWidth);
end;

procedure TControl.SetZOrder(TopMost: Boolean);
begin
  if FParent <> nil then
    if TopMost then
      SetZOrderPosition(FParent.FControls.Count - 1)
    else
      SetZOrderPosition(0);
end;

procedure TControl.SetZOrderPosition(Position: Integer);
var
  I, Count: Integer;
begin
  if FParent <> nil then
  begin
    I := FParent.FControls.IndexOf(Self);
    if I >= 0 then
    begin
      Count := FParent.FControls.Count;
      if Position < 0 then
        Position := 0;
      if Position >= Count then
        Position := Count - 1;
      if Position <> I then
      begin
        FParent.FControls.Delete(I);
        FParent.FControls.Insert(Position, Self);
        InvalidateControl(Visible, True);
      end;
    end;
  end;
end;

procedure TControl.Show;
begin
  if Parent <> nil then
    Parent.ShowControl(Self);
  if not (csDesigning in ComponentState) or
  (csNoDesignVisible in ControlStyle) then
    Visible := True;
end;

procedure TControl.SiblingsFlipped;
begin
  { Notification }
end;

procedure TControl.ShowHintChanged;
begin
  { Notification }
end;

procedure TControl.Update;
begin
  if Parent <> nil then Parent.Update;
end;

procedure TControl.CMParentShowHintChanged(var Message: TMessage);
begin
  if FParentShowHint then
  begin
    SetShowHint(FParent.FShowHint);
    FParentShowHint := True;
  end;
end;

function TControl.HintShow(var HintInfo: THintInfo): Boolean;
begin
  Result := not ((ActionLink <> nil) and not ActionLink.DoShowHint(HintInfo.HintStr));
end;

procedure TControl.VisibleChanged;
begin
  InvalidateControl(True, csOpaque in ControlStyle);
end;

procedure TControl.HintShowPause(var WasActive: Boolean; var Pause: Integer);
begin
  { Notification }
end;

procedure TControl.TextChanged;
begin
  { Notification }
end;

procedure TControl.UpdateBoundsRect(const R: TRect);
begin
  FLeft := R.Left;
  FTop := R.Top;
  FWidth := R.Right - R.Left;
  FHeight := R.Bottom - R.Top;
  UpdateAnchorRules;
end;

procedure TControl.VisibleChanging;
begin
  { Notification }
end;

function TControl.GetPaintDevice: QPaintDeviceH;
begin
  if Parent = nil then
    raise EInvalidOperation.CreateFmt(SParentRequired, [Name]);
  if Align <> alNone then
    Result := Parent.GetAlignedPaintDevice
  else
    Result := Parent.GetPaintDevice;
end;

procedure TControl.PaintRequest;
begin
  { By default, ignore internal paint requests, overridden in TGraphicControl }
end;

function TControl.DoMouseUp(Button: TMouseButton; Shift: TShiftState; X,
  Y: Integer): Boolean;
begin
  Result := False;
  try
    MouseUp(Button, Shift, X, Y);
  finally
    if (csCaptureMouse in ControlStyle) and (GetMouseGrabControl = Self) then
      ReleaseMouseGrab;
  end;
end;

procedure TControl.ReadState(Reader: TReader);
begin
  Include(FControlState, csReadingState);
  if Reader.Parent is TWidgetControl then
    Parent := TWidgetControl(Reader.Parent);
  inherited ReadState(Reader);
  Exclude(FControlState, csReadingState);
  if Parent <> nil then
  begin
    ParentColorChanged;
    ParentFontChanged;
    ParentShowHintChanged;
  end;
end;

procedure TControl.ChangeBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  if (Width <> AWidth) or (Height <> AHeight) then
    DoConstrainedResize(AWidth, AHeight);
  if ((ALeft <> FLeft) or (ATop <> FTop) or
    (AWidth <> FWidth) or (AHeight <> FHeight)) then
  begin
    InvalidateControl(Visible, False);
    FLeft := ALeft;
    FTop := ATop;
    FWidth := AWidth;
    FHeight := AHeight;
    Invalidate;
    UpdateAnchorRules;
    BoundsChanged;
    RequestAlign;
    if not (csLoading in ComponentState) then
      Resize;
  end;
end;

function TControl.GetColor: TColor;
begin
  Result := FColor;
end;

procedure TControl.ControlsAligned;
begin
  { Notification }
end;

{ TWidgetControlActionLink }

procedure TWidgetControlActionLink.AssignClient(AClient: TObject);
begin
  inherited AssignClient(AClient);
  FClient := AClient as TWidgetControl;
end;


{ TWidgetControl }

procedure TWidgetControl.ActionChange(Sender: TObject; CheckDefaults: Boolean);
begin
  inherited ActionChange(Sender, CheckDefaults);
  if Sender is TCustomAction then
    if not CheckDefaults or (HelpContext = 0) then
      HelpContext := TCustomAction(Sender).HelpContext;
end;

procedure TWidgetControl.AdjustClientRect(var Rect: TRect);
begin
  { Notification }
end;

procedure TWidgetControl.AdjustForFrame(var ALeft, ATop, AWidth, AHeight: Integer; ToQt: Boolean);
begin
  QControls.AdjustForFrame(Handle, ALeft, ATop, AWidth, AHeight, ToQt);
end;

procedure TWidgetControl.AdjustPainter(Painter: QPainterH);
begin
  { No adjustment needed for TWidgetControl }
end;

procedure TWidgetControl.AlignControl(AControl: TControl);
var
  Rect: TRect;
begin 
  if not HandleAllocated or (csDestroying in ComponentState) or
  (csAlignDisabled in ControlState) then
    Exit;
  if (FAlignLevel <> 0) or (not HandleAllocated) then
    Include(FControlState, csAlignmentNeeded)
  else
  begin
    DisableAlign;
    try
      Rect := GetClientRect;
      AlignControls(AControl, Rect);
    finally
      Exclude(FControlState, csAlignmentNeeded);
      EnableAlign;
    end;
  end;
end;

procedure TWidgetControl.AlignControls(AControl: TControl; var Rect: TRect);
var
  AlignList: TList;

  function InsertBefore(C1, C2: TControl; AAlign: TAlign): Boolean;
  begin
    Result := False;
    case AAlign of
      alTop: Result := C1.Top < C2.Top;
      alBottom: Result := (C1.Top + C1.Height) >= (C2.Top + C2.Height);
      alLeft: Result := C1.Left < C2.Left;
      alRight: Result := (C1.Left + C1.Width) >= (C2.Left + C2.Width);
      alCustom: Result := CustomAlignInsertBefore(C1, C2);
    end;
  end;

  procedure DoPosition(Control: TControl; AAlign: TAlign);
  var
    NewLeft, NewTop, NewWidth, NewHeight: Integer;
    ParentSize: TPoint;
  begin
    with Rect do
    begin
      if (AAlign = alNone) or (Control.Anchors <> AnchorAlign[AAlign]) then
      begin
        with Control do
          if (FOriginalParentSize.X <> 0) and (FOriginalParentSize.Y <> 0) then
          begin
            NewLeft := Left;
            NewTop := Top;
            NewWidth := Width;
            NewHeight := Height;
            if Parent.HandleAllocated then
              ParentSize := Parent.ClientRect.BottomRight
            else
              ParentSize := Point(Parent.Width, Parent.Height);
            if akRight in Anchors then
              if akLeft in Anchors then
                // The AnchorRules.X is the original width
                NewWidth := ParentSize.X - (FOriginalParentSize.X - FAnchorRules.X)
              else
                // The AnchorRules.X is the original left
                NewLeft := ParentSize.X - (FOriginalParentSize.X - FAnchorRules.X)
            else if not (akLeft in Anchors) then
              // The AnchorRules.X is the original middle of the control
              NewLeft := MulDiv(FAnchorRules.X, ParentSize.X, FOriginalParentSize.X) -
                NewWidth div 2;
            if akBottom in Anchors then
              if akTop in Anchors then
                // The AnchorRules.Y is the original height
                NewHeight := ParentSize.Y - (FOriginalParentSize.Y - FAnchorRules.Y)
	      else
                // The AnchorRules.Y is the original top
                NewTop := ParentSize.Y - (FOriginalParentSize.Y - FAnchorRules.Y)
            else if not (akTop in Anchors) then
              // The AnchorRules.Y is the original middle of the control
              NewTop := MulDiv(FAnchorRules.Y, ParentSize.Y, FOriginalParentSize.Y) -
                NewHeight div 2;
            FAnchorMove := True;
            try
              ChangeBounds(NewLeft, NewTop, NewWidth, NewHeight);
            finally
              FAnchorMove := False;
            end;
          end;
        if AAlign = alNone then Exit;
      end;

      NewWidth := Right - Left;
      if (NewWidth < 0) or (AAlign in [alLeft, alRight, alCustom]) then
        NewWidth := Control.Width;
      NewHeight := Bottom - Top;
      if (NewHeight < 0) or (AAlign in [alTop, alBottom, alCustom]) then
        NewHeight := Control.Height;
      NewLeft := Left;
      NewTop := Top;
      case AAlign of
        alTop:
          Inc(Top, NewHeight);
        alBottom:
          begin
            Dec(Bottom, NewHeight);
            NewTop := Bottom;
          end;
        alLeft:
          Inc(Left, NewWidth);
        alRight:
          begin
            Dec(Right, NewWidth);
            NewLeft := Right;
          end;
        alCustom:
          CustomAlignPosition(Control, NewLeft, NewTop, NewWidth,
            NewHeight, Rect);
      end;
    end;
    Control.FAnchorMove := True;
    try
      Control.ChangeBounds(NewLeft, NewTop, NewWidth, NewHeight);
    finally
      Control.FAnchorMove := False;
    end;
    { Adjust client rect if control didn't resize as we expected }
    if (Control.Width <> NewWidth) or (Control.Height <> NewHeight) then
      with Rect do
	case AAlign of
          alTop: Dec(Top, NewHeight - Control.Height);
          alBottom: Inc(Bottom, NewHeight - Control.Height);
          alLeft: Dec(Left, NewWidth - Control.Width);
          alRight: Inc(Right, NewWidth - Control.Width);
          alClient:
            begin
              Inc(Right, NewWidth - Control.Width);
              Inc(Bottom, NewHeight - Control.Height);
            end;
        end;
  end;

  function Anchored(Align: TAlign; Anchors: TAnchors): Boolean;
  begin
    case Align of
      alLeft: Result := akLeft in Anchors;
      alTop: Result := akTop in Anchors;
      alRight: Result := akRight in Anchors;
      alBottom: Result := akBottom in Anchors;
      alClient: Result := Anchors = [akLeft, akTop, akRight, akBottom];
    else
      Result := False;
    end;
  end;

  procedure DoAlign(AAlign: TAlign);
  var
    I, J: Integer;
    Control: TControl;
  begin
    AlignList.Clear;
    if (AControl <> nil) and ((AAlign = alNone) or AControl.Visible or
      (csDesigning in AControl.ComponentState) and
      not (csNoDesignVisible in AControl.ControlStyle)) and
      (AControl.Align = AAlign) then
      AlignList.Add(AControl);
    for I := 0 to ControlCount - 1 do
    begin
      Control := Controls[I];
      if (Control.Align = AAlign) and ((AAlign = alNone) or (Control.Visible or
        (Control.ControlStyle * [csAcceptsControls, csNoDesignVisible] =
          [csAcceptsControls, csNoDesignVisible])) or
        (csDesigning in Control.ComponentState) and
        not (csNoDesignVisible in Control.ControlStyle)) then
      begin
        if Control = AControl then Continue;
        J := 0;
        while (J < AlignList.Count) and not InsertBefore(Control,
          TControl(AlignList[J]), AAlign) do Inc(J);
	AlignList.Insert(J, Control);
      end;
    end;
    for I := 0 to AlignList.Count - 1 do
      DoPosition(TControl(AlignList[I]), AAlign);
  end;

  function AlignWork: Boolean;
  var
    I: Integer;
  begin
    Result := True;
    for I := ControlCount - 1 downto 0 do
      if (Controls[I].Align <> alNone) or
        (Controls[I].Anchors <> [akLeft, akTop]) then Exit;
    Result := False;
  end;

begin
  if AlignWork then
  begin
    AdjustClientRect(Rect); 
    AlignList := TList.Create;
    try
      DoAlign(alTop);
      DoAlign(alBottom);
      DoAlign(alLeft);
      DoAlign(alRight);
      DoAlign(alClient);
      DoAlign(alCustom);
      DoAlign(alNone); { Move anchored controls }
      ControlsAligned;
    finally
      AlignList.Free;
    end;
  end;
  { Apply any constraints }
  if Showing then AdjustSize;
end;

procedure TWidgetControl.Broadcast(var Message);
var
  I: Integer;
begin
  for I := 0 to ControlCount - 1 do
  begin
    Controls[I].Dispatch(Message);
    if TBroadcastMessage(Message).Handled then
      Exit;
  end;
end;

function TWidgetControl.CanFocus: Boolean;
var
  Control: TWidgetControl;
  Form: TCustomForm;
begin
  Result := False;
  Form := GetParentForm(Self);
  if Form <> nil then
  begin
    Control := Self;
    while Control <> Form do
    begin
      if not (Control.FVisible and Control.Enabled)
      or (csNoFocus in ControlStyle) then
        Exit;
      Control := Control.Parent;
    end;
    Result := True;
  end;
end;

procedure TWidgetControl.ChangeBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  if (Width <> AWidth) or (Height <> AHeight) then
    DoConstrainedResize(AWidth, AHeight);
  if (ALeft <> FLeft) or (ATop <> FTop) or
    (AWidth <> FWidth) or (AHeight <> FHeight) then
  begin
    if HandleAllocated then
    begin
      {
         Qt sets the "geometry" of a widget based on the client area, VCL
         uses the entire control size which includes what QT refers to as the
         frame. We need to add the offset to the width and height so we agree.
      }
      AdjustForFrame(ALeft, ATop, AWidth, AHeight, True);
      QWidget_setGeometry(Handle, ALeft, ATop, AWidth, AHeight);
      UpdateBounds;
    end
    else
    begin
      FLeft := ALeft;
      FTop := ATop;
      FWidth := AWidth;
      FHeight := AHeight;
    end;
    RequestAlign;
    BoundsChanged;
  end;
end;

procedure TWidgetControl.ChangeScale(MV, DV, MH, DH: Integer);
begin
  DisableAlign;
  try
    ScaleControls(MV, DV, MH, DH);
    inherited ChangeScale(MV, DV, MH, DH);
  finally
    EnableAlign;
  end;
end;

function TWidgetControl.ContainsControl(Control: TControl): Boolean;
begin
  while (Control <> nil) and (Control <> Self) do
    Control := Control.Parent;
  Result := Control <> nil;
end;

function TWidgetControl.ControlAtPos(const Pos: TPoint; AllowDisabled,
  AllowWidgets: Boolean): TControl;
var
  I: Integer;
  vControl: TControl;

  function GetControlAtPos(AControl: TControl): Boolean;
  var
    P: TPoint;
  begin
    with AControl do
    begin
      P := Point(Pos.X - Left, Pos.Y - Top);
      Result := PtInRect(ClientRect, P) and
                ((csDesigning in ComponentState) and (Visible or
                not (csNoDesignVisible in ControlStyle)) or
                (Visible and (Enabled or AllowDisabled) and
                HitTest(P.X, P.Y)));
      if Result then
	vControl := AControl;
    end;
  end;

begin
  vControl := nil;
  if AllowWidgets and (FWidgets <> nil) then
    for I := FWidgets.Count - 1 downto 0 do
      if GetControlAtPos(FWidgets[I]) then
        Break;
  if (FControls <> nil) and (vControl = nil) then
    for I := FControls.Count - 1 downto 0 do
      if GetControlAtPos(FControls[I]) then
        Break;
  Result := vControl;
end;

procedure TWidgetControl.ControlsListChanged(Control: TControl;
  Inserting: Boolean);
begin
  { Notification }
end;

procedure TWidgetControl.ControlsListChanging(Control: TControl;
  Inserting: Boolean);
begin
  { Notification }
end;

constructor TWidgetControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FBrush := TBrush.Create;
  FTabStop := False;
  FColor := clNone;
  FPalette := TWidgetPalette.Create;
  FPalette.OnChange := PaletteChanged;
  FTabOrder := -1;
end;

procedure TWidgetControl.CreateHandle;
begin
  if FHandle = nil then
  begin
    CreateWidget;
    QClxObjectMap_add(FHandle, Integer(Self));
    SetInitialSize;
    InitWidget;
    HookEvents;
    if csRecreating in ControlState then
      ResetEvents;
    if (FHandle = nil) or (FHooks = nil) then
      raise EWidgetControlException.CreateResFmt(@SInvalidCreateWidget, [ClassName]);
    if (csDesigning in ComponentState) and (ParentWidget <> nil) then
      QWidget_setFocusProxy(FHandle, ParentWidget);
    SetInitialBounds;
    UpdateWidgetShowing; { Force the visible state }
    EnabledChanged; { Force enabled state }
    QWidget_setCursor(FHandle, Screen.Cursors[FCursor]);
    if csRecreating in ControlState then
      RestoreWidgetState;
    if not (csLoading in ComponentState) then
      // This simulates some arguably broken VCL behavior where VCL
      // will trigger an OnResize event when the handle is created
      // since Windows sends a WM_SIZE event when the handle is created and
      // VCL does nothing to stop the WM_SIZE triggering a resize event. This
      // will ensure a similar resize is sent in CLX which really is just a
      // "handle created" event.
      Resize;
  end;
end;

constructor TWidgetControl.CreateParented(ParentWidget: QWidgetH);
begin
  FParentWidget := ParentWidget;
  Create(nil);
end;

class function TWidgetControl.CreateParentedControl(ParentWidget: QWidgetH): TWidgetControl;
begin
  Result := CreateParented(ParentWidget);
end;

procedure TWidgetControl.CreateWidget;
begin
  { Default behavior, this should be overridden by a descendent }
  FHandle := QWidget_create(ParentWidget, nil, WidgetFlags);
  FHooks := QWidget_hook_create(FHandle);
end;

procedure TWidgetControl.CursorChanged;
begin
  if HandleAllocated and not (csDesigning in ComponentState) then
    QWidget_setCursor(Handle, Screen.Cursors[FCursor]);
end;

destructor TWidgetControl.Destroy;
var
  I: Integer;
  Instance: TControl;
begin
  Destroying;
  if Parent <> nil then
  begin
    RemoveFocus(True);
    SetParent(nil);
  end;
  I := ControlCount;
  while I <> 0 do
  begin
    Instance := Controls[I - 1];
    Remove(Instance);
    Instance.Destroy;
    I := ControlCount;
  end;
  if FHandle <> nil then
  begin
    DestroyWidget;
    FHandle := nil;
  end;
  FBrush.Free;
  FPalette.Free;
  if Assigned(FStyle) then
    FStyle.Free;
//  CheckObjectMap(Self);
  inherited Destroy;
end;

procedure TWidgetControl.DestroyHandle;
var
  I: Integer;
  ChildWidget: TWidgetControl;
begin
  if FHandle <> nil then
  begin
    if csRecreating in ControlState then
      SaveWidgetState;
    if FWidgets <> nil then
    begin
      for I := 0 to FWidgets.Count - 1 do
      begin
        ChildWidget := FWidgets[I];
        if csRecreating in ControlState then
          Include(ChildWidget.FControlState, csRecreating);
        ChildWidget.DestroyHandle;
      end;
    end;
    DestroyWidget;
    FHooks := nil;
  end;
end;

procedure TWidgetControl.DestroyWidget;
var
  TmpHandle: QWidgetH;
begin
  TmpHandle := FHandle;
  WidgetDestroyed;

  if (csRecreating in ControlState) and (not Assigned(Parent)
  or not (csRecreating in Parent.ControlState)) then
    QApplication_postEvent(Application.Handle, QCustomEvent_create(QEventType_CMDestroyWidget, TmpHandle))
  else
    QWidget_destroy(TmpHandle);
end;

procedure TWidgetControl.DisableAlign;
begin
  Inc(FAlignLevel);
end;

procedure TWidgetControl.DoEnter;
begin
  if Assigned(FOnEnter) then
    FOnEnter(Self);
end;

procedure TWidgetControl.DoExit;
begin
  if Assigned(FOnExit) then
    FOnExit(Self);
end;

function TWidgetControl.FindNextControl(CurControl: TWidgetControl;
  GoForward, CheckTabStop, CheckParent: Boolean): TWidgetControl;
var
  I, StartIndex: Integer;
  List: TList;
begin
  Result := nil;
  List := TList.Create;
  try
    GetTabOrderList(List);
    if List.Count > 0 then
    begin
      StartIndex := List.IndexOf(CurControl);
      if StartIndex = -1 then
        if GoForward then StartIndex := List.Count - 1 else StartIndex := 0;
      I := StartIndex;
      repeat
        if GoForward then
        begin
          Inc(I);
	  if I = List.Count then I := 0;
        end else
        begin
          if I = 0 then I := List.Count;
          Dec(I);
        end;
        CurControl := List[I];
        if CurControl.CanFocus and
          (not CheckTabStop or CurControl.TabStop) and
          (not CheckParent or (CurControl.Parent = Self)) then
          Result := CurControl;
      until (Result <> nil) or (I = StartIndex);
    end;
  finally
    List.Free;
  end;
end;

procedure TWidgetControl.DoFlipChildren;
var
  I: Integer;
  TheWidth: Integer;
  FlippedList: TList;
  Control: TControl;
begin
  FlippedList := TList.Create;
  try
    TheWidth := ClientWidth;
    for I := 0 to ControlCount - 1 do
    begin
      Control := Controls[I];
      if (Control.Owner = Self.Owner) or ((Owner = nil) and
        (Control.Owner = Self)) then
      begin
        FlippedList.Add(Control);
        Control.Left := TheWidth - Control.Width - Control.Left;
      end;
    end;
    { Allow controls that have associations to realign themselves }
    for I := 0 to FlippedList.Count - 1 do
      TControl(FlippedList[I]).SiblingsFlipped;
  finally
    FlippedList.Free;
  end;
end;

procedure TWidgetControl.EnableAlign;
begin
  Dec(FAlignLevel);
  if (FAlignLevel = 0) and (csAlignmentNeeded in ControlState) then
    Realign;
end;

procedure TWidgetControl.Painting(Sender: QObjectH; EventRegion: QRegionH);
var
  ForcedPaintEvent: QPaintEventH;
begin
  { Force the widget to paint (avoiding recursion) }
  ForcedPaintEvent := QPaintEvent_create(EventRegion, False);
  try
    Include(FControlState, csWidgetPainting);
    try
      {
         We call QObject_event() to ensure any filters see the paint
         event. If we call QOpenEvent_paintEvent() we will ignore filters.
      }
      QObject_event(Sender, ForcedPaintEvent);
    finally
      Exclude(FControlState, csWidgetPainting);
    end;
  finally
    QPaintEvent_destroy(ForcedPaintEvent);
  end;
end;

type
  TOpenApplication = class(TApplication);

const
  KeyPressKeys = [#8, #13, #27..#126, #128..#255];

function TWidgetControl.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;

  function TranslatePoint(Parent, Control: TControl; P: TPoint): TPoint;
  begin
    while Control <> Parent do
    begin
      Dec(P.X, Control.Left);
      Dec(P.Y, Control.Top);
      Control := Control.Parent;
    end;
    Result := P;
  end;

  function MouseEvent(Event: QMouseEventH): Boolean;
  var
    P: TPoint;
    ShiftState: TShiftState;
    Button: QT.ButtonState;
    MouseButton: TMouseButton;
    Control: TControl;
  begin
    P.X := QMouseEvent_x(Event);
    P.Y := QMouseEvent_y(Event);
    QWidget_mapToGlobal(QWidgetH(Sender), @P, @P);
    QWidget_mapFromGlobal(ChildHandle, @P, @P);
    if (MouseGrabControl <> nil) and (MouseGrabControl.Parent = Self) then
      Control := MouseGrabControl
    else if MouseGrabWidget <> Self then
      Control := ControlAtPos(P, False)
    else
      Control := Self;
    if Control = nil then
      Control := Self
    else if Control <> Self then
      P := TranslatePoint(Self, Control, P);
    ShiftState := ButtonStateToShiftState(QMouseEvent_state(Event));
    Button := QMouseEvent_button(Event);
    if Integer(ButtonState_MidButton) and Integer(Button) <> 0 then
      MouseButton := mbMiddle
    else if Integer(ButtonState_RightButton) and Integer(Button) <> 0 then
      MouseButton := mbRight
    else
      MouseButton := mbLeft;
    case QEvent_type(Event) of
      QEventType_MouseButtonPress:
      begin
        if MouseButton = mbLeft then
        begin
          Include(Control.FControlState, csLButtonDown);
          if (Control.FDragMode = dmAutomatic) and not ActivatingDrag then
          begin
            Control.BeginAutoDrag;
            if InDragDropOperation or DragHappenned then
            begin
              DragHappenned := False;
              Result := True;
              Exit;
            end;
          end;
        end;
        if Control = Self then
          MouseGrabWidget := Self;
        if csClickEvents in Control.ControlStyle then
          Include(Control.FControlState, csClicked);
        Result := Control.DoMouseDown(MouseButton, ShiftState, P.X, P.Y);
        if Result then
          Exit;
      end;
      QEventType_MouseButtonRelease:
      begin
        try
          if MouseButton = mbLeft then
            Exclude(Control.FControlState, csLButtonDown);
          if (DragOp <> dopNone) and not Assigned(DragControl) then
            CancelDrag;
          if csClicked in Control.ControlState then
          begin
            Exclude(Control.FControlState, csClicked);
            if PtInRect(Control.ClientRect, P) and (MouseButton <> mbRight)
            and (Control <> InitialDragControl) and Control.Enabled then
              Control.Click;
          end;
        finally
          if Control <> InitialDragControl then
            Control.DoMouseUp(MouseButton, ShiftState, P.X, P.Y)
          else if (csCaptureMouse in Control.ControlStyle) and (GetMouseGrabControl = Control) then
          begin                                                  
            Control.DoMouseUp(MouseButton, ShiftState, P.X, P.Y);
            ReleaseMouseGrab;
          end;
          MouseGrabWidget := nil;
          ActivatingDrag := False;
        end;
      end;
      QEventType_MouseButtonDblClick:
        begin
          if (MouseButton = mbLeft) and (Control.FDragMode = dmAutomatic) then
          begin
            Control.BeginAutoDrag;
            if InDragDropOperation or DragHappenned then
            begin
              DragHappenned := False;
              Result := True;
              Exit;
            end;
          end;
          if not (csDoubleClicks in Control.ControlStyle) then
            Control.MouseDown(MouseButton, ShiftState, P.X, P.Y)
          else begin
            if (csClickEvents in Control.ControlStyle) and
            (MouseButton = mbLeft) then
              Control.DblClick;
            Control.MouseDown(MouseButton, ShiftState + [ssDouble], P.X, P.Y);
          end;
        end;
      QEventType_MouseMove:
      begin
        if csLButtonDown in Control.ControlState then
          if DragOp = dopNone then
          begin
            if ActivatingDrag then
            begin
              GetCursorPos(DragStartPos);
              DragStartPos := Control.ScreenToClient(DragStartPos);
              LastDragOverControl := Control;
              DragOp := dopDrag;
            end;
          end
          else
            if (Abs(P.X - DragStartPos.X) >= DragThreshold) or
            (Abs(P.Y - DragStartPos.Y) >= DragThreshold) then
            begin
              if LastDragOverControl <> Control then
              begin
                LastDragOverControl := nil;
                ActivatingDrag := False;
                DragOp := dopNone;
              end
              else
                if not Assigned(InitialDragControl) then
                  InitialDragControl := Control;
                DragStart;
            end;
{$IFDEF LINUX}
        if not ((MouseGrabControl = nil) and ((P.X < 0) or (P.Y < 0))) then
{$ENDIF}
          Control.MouseMove(ShiftState, P.X, P.Y);
      end;
    end;
    Result := False; { Let the QT widget have the event. }
  end;

  function KeyEvent(Event: QKeyEventH): Boolean;
  var
    KeyCode: Word;
    KeyChar: Char;
    ShiftState: TShiftState;
    ParentForm: TCustomForm;
    S,
    EventText: WideString;
    A: AnsiString;
    Handled : Boolean;
    I: Integer;
    E: QKeyEventH;
    TextModified: Boolean;
    KeyCodeChanged,
    KeyCharChanged,
    KeyTextChanged: Boolean;
  begin
    KeyCode := QKeyEvent_key(Event);
    ShiftState := ButtonStateToShiftState(QKeyEvent_state(Event));
    ParentForm := GetParentForm(Self);
    KeyChar := Char(QKeyEvent_ascii(Event));
    case QEvent_type(Event) of
      QEventType_KeyPress:
        begin
          if (KeyCode = Key_Shift) then Include(ShiftState, ssShift);
          if (KeyCode = Key_Control) then Include(ShiftState, ssCtrl);
          if (KeyCode = Key_Alt) then Include(ShiftState, ssAlt);
          if Assigned(ParentForm) and ParentForm.KeyPreview then
            TWidgetControl(ParentForm).KeyDown(KeyCode, ShiftState);
          KeyDown(KeyCode, ShiftState);
          if KeyCode <> 0 then
          begin
            if KeyChar in KeyPressKeys then
            begin
              if Assigned(ParentForm) and ParentForm.KeyPreview then
                TWidgetControl(ParentForm).KeyPress(KeyChar);
              KeyPress(KeyChar);
              if KeyChar = #0 then
                KeyCode := 0;
            end;
          end else
          begin
            QKeyEvent_text(Event, @S);
            EventText := S;
            if Length(S) > 0 then
            begin
              Handled := False;
              KeyString(S, Handled);
              if not Handled then
              begin
                A := S;
                TextModified := False;
                for I := 1 to Length(A) do
                begin
                  KeyChar := Char(A[I]);
                  KeyPress(KeyChar);
                  if KeyChar = #0 then
                  begin
                    SetLength(A, I - 1);
                    TextModified := True;
                    Break;
                  end
                  else if KeyChar <> A[I] then
                  begin
                    A[I] := KeyChar;
                    TextModified := True;
                  end;
                end;
                if TextModified then
                  S := A;
              end;
            end;
          end;
        end;
      QEventType_KeyRelease:
      begin
        if Assigned(ParentForm) and ParentForm.KeyPreview then
          TWidgetControl(ParentForm).KeyUp(KeyCode, ShiftState);
        KeyUp(KeyCode, ShiftState);
      end;
    end;

    Result := False;
    KeyCodeChanged := KeyCode <> QKeyEvent_key(Event);
    KeyCharChanged := (KeyCode <> 0) and (KeyChar <> Char(QKeyEvent_ascii(Event)));
    KeyTextChanged := (KeyCode = 0) and (S <> EventText);

    if KeyCodeChanged or KeyCharChanged or KeyTextChanged then
    begin
      if not KeyTextChanged then
      begin
        if KeyCharChanged then
        begin
          S := KeyChar;
          KeyCode := Ord(KeyChar);
          KeyCodeChanged := True; 
        end
        else if KeyCode in [1..255] then
          S := Char(KeyCode)
        else S := '';
      end;

      if (KeyCodeChanged and (KeyCode <> 0)) or (KeyTextChanged and (S <> '')) then
      begin
        E := QKeyEvent_create(QEvent_type(Event), KeyCode, KeyCode,
          Integer(QKeyEvent_state(Event)), @S, QKeyEvent_isAutoRepeat(Event),
          QKeyEvent_count(Event));
        try
          if QEvent_type(Event) = QEventType_KeyPress then
            QOpenWidget_keyPressEvent(QOpenWidgetH(Handle), E)
          else
            QOpenWidget_keyReleaseEvent(QOpenWidgetH(Handle), E);
        finally
          QKeyEvent_destroy(E);
        end;
      end;
      Result := True;
      QKeyEvent_accept(Event);
    end;
  end;

  function WheelEvent(Event: QWheelEventH): Boolean;
  var
    P: TPoint;
    ShiftState: TShiftState;
    Control: TControl;
  begin
    Result := False;
    if not QObject_isWidgetType(Sender) then
      Exit;
    P := QWheelEvent_globalPos(Event)^;
    QWidget_mapFromGlobal(QWidgetH(Sender), @P, @P);
    if (MouseGrabControl <> nil) and (MouseGrabControl.Parent = Self) then
      Control := MouseGrabControl
    else if MouseGrabWidget <> Self then
      Control := ControlAtPos(P, False)
    else
      Control := Self;
    if Control = nil then
      Control := Self
    else if Control <> Self then
      P := TranslatePoint(Self, Control, P);
    ShiftState := ButtonStateToShiftState(QWheelEvent_state(Event));
    if Control.DoMouseWheel(ShiftState, QWheelEvent_delta(Event), P) then
      QWheelEvent_accept(Event);
  end;

  function FocusEvent(Event: QEventH): Boolean;
  var
    Form: TCustomForm;
  begin
    Form := GetParentForm(Self);
    Result := Assigned(Form) and not Form.SetFocusedControl(Self);
  end;

  procedure PaintControls;
  var
    I: Integer;
    Control: TControl;
    Form: TCustomForm;
  begin
    Form := nil;
    if FControls <> nil then
      for I := 0 to FControls.Count - 1 do
      begin
        Control := TControl(FControls[I]);
        if (Control.Visible or (csDesigning in Control.ComponentState) and
          not (csNoDesignVisible in Control.ControlStyle)) then
        begin
          Control.PaintRequest;
          if csDesigning in Control.ComponentState then
          begin
            if Form = nil then Form := GetParentForm(Control);
            if (Form <> nil) and (Form.DesignerHook <> nil) then
              Form.DesignerHook.ControlPaintRequest(Control);
          end;
        end;
      end;
  end;

  function PaintEvent(Sender: QObjectH; Event: QPaintEventH): Boolean;
  var
    I: Integer;
    R: TRect;
    DrawRegion: QRegionH;
    ControlRegion: QRegionH;
    AControl: TControl;
  begin
    if not (csWidgetPainting in ControlState) and QObject_isWidgetType(Sender) then
    begin
      R := Rect(0, 0, QWidget_width(QWidgetH(Sender)), QWidget_height(QWidgetH(Sender)));
      DrawRegion := QRegion_create(@R, QRegionRegionType_Rectangle);
      try
        { Paint the widget excluding any opaque controls }
        if FControls <> nil then
          for I := 0 to FControls.Count - 1 do
          begin
            AControl := TControl(FControls[I]);
            if (AControl.Visible or ((csDesigning in AControl.ComponentState) and
              not (csNoDesignVisible in AControl.ControlStyle))) and
              (csOpaque in AControl.ControlStyle) then
            begin
              R := AControl.BoundsRect;
              ControlRegion := QRegion_create(@R, QRegionRegionType_Rectangle);
              try
                QRegion_subtract(DrawRegion, DrawRegion, ControlRegion);
              finally
                QRegion_destroy(ControlRegion);
              end;
              if QRegion_isEmpty(DrawRegion) then
                Break;
            end;
          end;
        if not QRegion_isEmpty(DrawRegion) then
        begin
          ControlRegion := QPaintEvent_region(Event);
          QRegion_intersect(ControlRegion, ControlRegion, DrawRegion);
          Painting(Sender, ControlRegion);
        end;
      finally
        QRegion_destroy(DrawRegion);
      end;

      { Paint the nested controls }
      PaintControls;

      { We painted so squelch the event }
      Result := True;
    end
    else
      Result := False;
  end;

  function DNDEvent(DNDEvent: QDropEventH): Boolean;
  var
    Pt: TPoint;
    Control: TControl;
    SendDragObject: TObject;
    DragState: TDragState;
    EventType: QEventType;
  begin
    if Application.Terminated then
    begin
      DragDone(False);
      Result := True;
      Exit;
    end;
    if not Assigned(ClxDragObj) then
    begin
      Result := True;
      Exit;
    end;
    EventType := QEvent_type(DNDEvent);
    GetCursorPos(Pt);
    QWidget_mapFromGlobal(ChildHandle, @Pt, @Pt);

    if (MouseGrabControl <> nil) and (MouseGrabControl.Parent = Self) then
      Control := MouseGrabControl
    else if MouseGrabWidget <> Self then
      Control := ControlAtPos(Pt, False, True)
    else
      Control := Self;

    if Control = nil then
      Control := Self
    else if Control <> Self then
      Pt := TranslatePoint(Self, Control, Pt);
    DragDropEvent := DNDEvent;
    if not (QControls.DragObject is TBaseDragControlObject) then
      SendDragObject := QControls.DragObject
    else
      SendDragObject := DragControl;
    case EventType of
      QEventType_DragEnter,
      QEventType_DragMove,
      QEventType_DragLeave:
      begin
        if Control <> LastDragOverControl then
        begin
          DragState := dsDragLeave;
          if Assigned(LastDragOverControl) and LastDragOverControl.Enabled then
          begin
            LastDragPos := LastDragOverControl.ScreenToClient(LastDragPos);
            LastDragOverControl.DragOver(SendDragObject, LastDragPos.X,
              LastDragPos.Y, DragState, DragAccepted);
          end;
          LastDragOverControl := Control;
          DragState := dsDragEnter;
          if Assigned(LastDragOverControl) and LastDragOverControl.Enabled then
            LastDragOverControl.DragOver(SendDragObject, Pt.X,
              Pt.Y, DragState, DragAccepted);
        end
        else if Control.Enabled then
        begin
          if (LastDragPos.X <> Pt.X) or (LastDragPos.Y <> Pt.Y) then
          begin
            DragState := dsDragMove;
          Control.DragOver(SendDragObject, Pt.X, Pt.Y, DragState,
              DragAccepted);
          end;
        end;
        case EventType of
          QEventType_DragEnter:
          begin
            {$IFDEF LINUX}
            if Assigned(DragObject) and not DragHooked then
            begin
              DragHooked := True;
              X11DragFilter := TX11DragFilter.Create(Application.Handle);
            end;
            {$ENDIF}
          end;
          QEventType_DragMove:
            if Assigned(DragObject) then
              DragObject.SetDragImage;
        end;
        if EventType <> QEventType_DragLeave then
          QDropEvent_accept(DNDEvent, DragAccepted);
        LastDragPos := Pt;
        Result := True;
      end;
      QEventType_Drop:
      begin
        if Control.Enabled then
          Control.DragOver(SendDragObject, Pt.X, Pt.Y,
                           dsDragLeave, Result);
        if Result then
          Control.DragDrop(SendDragObject, Pt.X, Pt.Y);
        DragDone(Result);
        Result := True;
      end;
    end;
  end;

begin
  Result := False;
  case QEvent_type(Event) of
    QEventType_DragResponse:
    begin
      DragDone(QDragResponseEvent_dragAccepted(QDragResponseEventH(Event)));
      Result := True;
    end;
    QEventType_DragLeave,
    QEventType_DragEnter,
    QEventType_DragMove,
    QEventType_Drop:
      Result := DNDEvent(QDropEventH(Event));
    QEventType_MouseButtonPress,
    QEventType_MouseButtonRelease,
    QEventType_MouseButtonDblClick,
    QEventType_MouseMove:
      Result := MouseEvent(QMouseEventH(Event));
    QEventType_KeyPress,
    QEventType_KeyRelease:
      Result := KeyEvent(QKeyEventH(Event));
    QEventType_FocusIn:
      Result := FocusEvent(Event);
    QEventType_Move, QEventType_Resize:
      UpdateBounds;
    QEventType_Wheel:
      Result := WheelEvent(QWheelEventH(Event));
    QEventType_Paint:
      Result := PaintEvent(Sender, QPaintEventH(Event));
    QEventType_ApplicationPaletteChange:
      Result := Palette.Owned;
    QEventType_ParentPaletteChange:
      Result := not ParentColor;
    QEventType_Show,
    QEventType_Hide:
      if not (csDestroying in ComponentState) then
        UpdateShowing;
  end;
end;

function TWidgetControl.FindChildControl(const ControlName: string): TControl;
var
  I: Integer;
begin
  Result := nil;
  if FWidgets <> nil then
    for I := 0 to FWidgets.Count - 1 do
      if CompareText(TWidgetControl(FWidgets[I]).Name, ControlName) = 0 then
      begin
        Result := FWidgets[I];
        Exit;
      end;
end;

procedure TWidgetControl.FlipChildren(AllLevels: Boolean);
var
  Loop: Integer;
  AlignList: TList;
begin
  if ControlCount = 0 then Exit;
  AlignList := TList.Create;
  DisableAlign;
  try
    { Collect all the Right and Left alignments }
    for Loop := 0 to ControlCount - 1 do
      with Controls[Loop] do
        if Align in [alLeft, alRight] then
          AlignList.Add(Controls[Loop]);
    { Flip 'em }
    DoFlipChildren;
  finally
    { Reverse the Right and Left alignments }
    while AlignList.Count > 0 do
    begin
      with TControl(AlignList[AlignList.Count - 1]) do
        if Align = alLeft then
          Align := alRight
        else
          Align := alLeft;
      AlignList.Delete(AlignList.Count - 1);
    end;
    AlignList.Free;
    EnableAlign;
  end;
  if AllLevels and Assigned(FWidgets) then
    for Loop := 0 to FWidgets.Count - 1 do
      TWidgetControl(FWidgets[Loop]).FlipChildren(True);
end;

function TWidgetControl.Focused: Boolean;
var
  ParentForm: TCustomForm;
begin
  ParentForm := GetParentForm(Self);
  if ParentForm <> nil then
    Result := ParentForm.FocusedControl = Self
  else
    Result := QWidget_hasFocus(Handle);
end;

function TWidgetControl.GetActionLinkClass: TControlActionLinkClass;
begin
  Result := TWidgetControlActionLink;
end;

function TWidgetControl.GetAlignedPaintDevice: QPaintDeviceH;
begin
  Result := QWidget_to_QPaintDevice(ChildHandle);
end;

function TWidgetControl.GetClientOrigin: TPoint;
begin
  Result.X := 0;
  Result.Y := 0;
  QWidget_mapToGlobal(Handle, @Result, @Result);
end;

function TWidgetControl.GetClientRect: TRect;
begin
  QWidget_geometry(Handle, @Result);
  AdjustForClient(Result);
end;

function TWidgetControl.GetControl(Index: Integer): TControl;
var
  N: Integer;
begin
  if FControls <> nil then
    N := FControls.Count
  else
    N := 0;
  if Index < N then
    Result := FControls[Index]
  else
    Result := FWidgets[Index - N];
end;

function TWidgetControl.GetControlCount: Integer;
begin
  Result := 0;
  if FControls <> nil then
    Inc(Result, FControls.Count);
  if FWidgets <> nil then
    Inc(Result, FWidgets.Count);
end;

function TWidgetControl.GetHandle: QWidgetH;
begin
  HandleNeeded;
  Result := FHandle;
end;

function TWidgetControl.GetHooks: QWidget_hookH;
begin
  HandleNeeded;
  Result := FHooks;
end;

function TWidgetControl.GetParentWidget: QWidgetH;
begin
  if Assigned(FParentWidget) then
    Result := FParentWidget
  else if Assigned(Parent) then
    Result := Parent.ChildHandle
  else if (not Assigned(Application.MainForm) and (Self is TCustomForm)) or
  (Assigned(Application.MainForm) and not Application.MainForm.HandleAllocated) or
  (Application.MainForm = Self) then
    Result := nil
  else
    Result := TOpenApplication(Application).AppWidget;
end;

function TWidgetControl.GetTabOrder: TTabOrder;
begin
  if FParent <> nil then
    Result := FParent.FTabList.IndexOf(Self)
  else
    Result := -1;
end;

procedure TWidgetControl.GetTabOrderList(List: TList);
var
  I: Integer;
  Control: TWidgetControl;
begin
  if FTabList <> nil then
    for I := 0 to FTabList.Count - 1 do
    begin
      Control := FTabList[I];
      List.Add(Control);
      Control.GetTabOrderList(List);
    end;
end;

function TWidgetControl.HandleAllocated: Boolean;
begin
  Result := FHandle <> nil;
end;

procedure TWidgetControl.HandleNeeded;
begin
  if FHandle = nil then
  begin
    if Parent <> nil then
      Parent.HandleNeeded;
    CreateHandle;
  end;
end;

procedure TWidgetControl.HookEvents;
var
  Method: TMethod;
begin
  if FHooks = nil then
  begin
    HandleNeeded;
    FHooks := QWidget_hook_create(Handle);
  end;

  TEventFilterMethod(Method) := MainEventFilter;
  Qt_hook_hook_events(FHooks, Method);

  QObject_destroyed_event(Method) := Self.DestroyedHook;
  QObject_hook_hook_destroyed(FHooks, Method);
end;

procedure TWidgetControl.NotifyControls(Msg: Word);
var
  Message: TBroadcastMessage;
begin
  Message.Msg := Msg;
  Message.Handled := False;
  Broadcast(Message);
end;

procedure TWidgetControl.Insert(AControl: TControl);
begin
  if AControl <> nil then
  begin
    if AControl is TWidgetControl then
    begin
      ListAdd(FWidgets, AControl);
      ListAdd(FTabList, AControl);
    end
    else
      ListAdd(FControls, AControl);
    AControl.FParent := Self;
  end;
end;

procedure TWidgetControl.InsertControl(AControl: TControl);
begin
  AControl.ValidateContainer(Self);
  ControlsListChanging(AControl, True);
  Insert(AControl);
  if not (csReadingState in AControl.ControlState) then
  begin
    AControl.ParentColorChanged;
    AControl.ParentFontChanged;
    AControl.ParentShowHintChanged;
    if AControl is TWidgetControl then
      UpdateControlState
    else
      if HandleAllocated then
        AControl.Invalidate;
    AlignControl(AControl);
  end;
  ControlsListChanged(AControl, True);
end;

procedure TWidgetControl.Invalidate;
begin
  if HandleAllocated then
    QWidget_update(Handle);
end;

procedure TWidgetControl.InvalidateRect(Rect: TRect;
  EraseBackground: Boolean);
var
  DoesNotErase: Boolean;
begin
  if HandleAllocated then
  begin
    DoesNotErase := QWidget_testWFlags(Handle, Integer(WidgetFlags_WRepaintNoErase));
    if EraseBackGround then
    begin
      if DoesNotErase then
        QWidget_erase(ChildHandle, @Rect);
      QWidget_update(ChildHandle, @Rect);
    end
    else
    begin
      if not DoesNotErase then
        QOpenWidget_setWFlags(QOpenWidgetH(ChildHandle),
          QOpenWidget_getWFlags(QOpenWidgetH(ChildHandle)) or Integer(WidgetFlags_WRepaintNoErase));
      QWidget_update(ChildHandle, @Rect);
      if not DoesNotErase then
        QOpenWidget_setWFlags(QOpenWidgetH(ChildHandle),
          QOpenWidget_getWFlags(QOpenWidgetH(ChildHandle)) and not Integer(WidgetFlags_WRepaintNoErase));
    end;
  end;
end;

function TWidgetControl.IsBitmapStored: Boolean;
begin
  Result := not FPalette.IsBitmapEmpty;
end;

procedure TWidgetControl.KeyDown(var Key: Word; Shift: TShiftState);
begin
  if Assigned(FOnKeyDown) then
    FOnKeyDown(Self, Key, Shift);
  if Key = Application.HelpKey then
    InvokeHelp;
end;

procedure TWidgetControl.KeyPress(var Key: Char);
begin
  if Assigned(FOnKeyPress) then
    FOnKeyPress(Self, Key);
end;

procedure TWidgetControl.KeyUp(var Key: Word; Shift: TShiftState);
begin
  if Assigned(FOnKeyUp) then
    FOnKeyUp(Self, Key, Shift);
end;

procedure TWidgetControl.KeyString(var S: WideString; var Handled: Boolean);
begin
  if Assigned(FOnKeyString) then
    FOnKeyString(Self, S, Handled);
end;

function TWidgetControl.DesignEventQuery(Sender: QObjectH; Event: QEventH): Boolean;
begin
  Result := False;
end;

function TWidgetControl.MainEventFilter(Sender: QObjectH; Event: QEventH): Boolean; cdecl;
var
  Form: TCustomForm;
begin
  try
    if csDesigning in ComponentState then
    begin
      Form := GetParentForm(Self);
      if (Form <> nil) and (Form.DesignerHook <> nil) and
        Form.DesignerHook.IsDesignEvent(Self, Sender, Event) then
      begin
        Result := True;
        Exit;
      end;
    end;
    Result := EventFilter(Sender, Event);
  except
    Application.HandleException(Self);
    Result := False;
  end;
end;

procedure TWidgetControl.Realign;
begin
  AlignControl(nil);
end;

procedure TWidgetControl.Remove(AControl: TControl);
begin
  if AControl is TWidgetControl then
  begin
    ListRemove(FTabList, AControl);
    ListRemove(FWidgets, AControl);
  end
  else
    ListRemove(FControls, AControl);
  AControl.FParent := nil;
end;

procedure TWidgetControl.InvokeHelp;
begin
  case HelpType of
    htKeyword:
      if HelpKeyword <> '' then
      begin
        Application.KeywordHelp(HelpKeyword);
        Exit;
      end;
    htContext:
      if HelpContext <> 0 then
      begin
        Application.ContextHelp(HelpContext);
        Exit;
      end;
  end;
  if Parent <> nil then Parent.InvokeHelp;  
end;

procedure TWidgetControl.RemoveControl(AControl: TControl);
begin
  ControlsListChanging(AControl, False);
  if AControl is TWidgetControl then
    with TWidgetControl(AControl) do
    begin
      RemoveFocus(True);
    end
  else
    if HandleAllocated then
      AControl.InvalidateControl(AControl.Visible, False);
  Remove(AControl);
  ControlsListChanged(AControl, False);
  Realign;
end;

procedure TWidgetControl.RecreateWidget;
begin
  Include(FControlState, csRecreating);
  try
    DestroyHandle;
    CreateHandle;
    UpdateControlState;
  finally
    Exclude(FControlState, csRecreating);
  end;
end;

procedure TWidgetControl.RemoveFocus(Removing: Boolean);
var
  Form: TCustomForm;
begin
  Form := GetParentForm(Self);
  if Form <> nil then
    Form.DefocusControl(Self, Removing);
end;

procedure TWidgetControl.Repaint;
begin
  Invalidate;
  Update;
end;

procedure TWidgetControl.ScaleBy(MV, DV, MH, DH: Integer);
var
  IsVisible: Boolean;
  R: TRect;
begin
  if MH = 0 then MH := MV;
  if DH = 0 then DH := DV;
  IsVisible := Visible and HandleAllocated;
  if IsVisible then
    QWidget_setUpdatesEnabled(Handle, False);
  try
    R := BoundsRect;
    ChangeScale(MV, DV, MH, DH);
    SetBounds(R.Left, R.Top, Width, Height);
  finally
    if IsVisible then
    begin
      QWidget_setUpdatesEnabled(Handle, True);
      Invalidate;
    end;
  end;
end;

procedure TWidgetControl.ScrollBy(DeltaX, DeltaY: Integer);
var
  IsVisible: Boolean;
begin
  IsVisible := Visible and HandleAllocated;
  if IsVisible then
    QWidget_scroll(Handle, DeltaX, DeltaY);
  ScrollControls(DeltaX, DeltaY, IsVisible);
  Realign;
end;

procedure TWidgetControl.ScaleControls(MV, DV, MH, DH: Integer);
var
  I: Integer;
begin
  if MH = 0 then MH := MV;
  if DH = 0 then DH := DV;
  for I := 0 to ControlCount - 1 do
    Controls[I].ChangeScale(MV, DV, MH, DH);
end;

procedure TWidgetControl.ScrollControls(DeltaX, DeltaY: Integer; IsVisible: Boolean);
var
  I: Integer;
  Control: TControl;
begin
  for I := 0 to ControlCount - 1 do
  begin
    Control := Controls[I];
    if not (Control is TWidgetControl) then
    begin
      Inc(Control.FLeft, DeltaX);
      Inc(Control.FTop, DeltaY);
   end else
      if not IsVisible then
        with TWidgetControl(Control) do
          SetBounds(FLeft + DeltaX, FTop + DeltaY, FWidth, FHeight);
  end;
end;

function TWidgetControl.SelectNext(CurControl: TWidgetControl;
  GoForward, CheckTabStop: Boolean): Boolean;
begin
  CurControl := FindNextControl(CurControl, GoForward,
    CheckTabStop, not CheckTabStop);
  Result := (CurControl <> nil);
  if Result then
    CurControl.SetFocus;
end;

procedure TWidgetControl.SelectFirst;
var
  Form: TCustomForm;
  Control: TWidgetControl;
begin
  Form := GetParentForm(Self);
  if Form <> nil then
  begin
    Control := FindNextControl(nil, True, True, False);
    if Control = nil then
      Control := FindNextControl(nil, True, False, False);
    if Control <> nil then Form.ActiveControl := Control;
  end;
end;

procedure TWidgetControl.SetFocus;
var
  Parent: TCustomForm;
begin
  Parent := GetParentForm(Self);
  if Parent <> nil then
    Parent.FocusControl(Self)
  else if (ParentWidget <> nil) and HandleAllocated then
  begin
    QWidget_setFocus(Handle);
    QWidget_setActiveWindow(Handle);
  end
  else
    ValidParentForm(Self);
end;

procedure TWidgetControl.SetParentWidget(const Value: QWidgetH);
begin
  FVisible := False;
  FParent := nil;
  FParentWidget := Value;
end;

procedure TWidgetControl.SetTabOrder(const Value: TTabOrder);
begin
  if csReadingState in ControlState then
    FTabOrder := Value
  else
    UpdateTabOrder(Value);
end;

procedure TWidgetControl.SetTabStop(const Value: Boolean);
begin
  if FTabStop <> Value then
  begin
    FTabStop := Value;
    TabStopChanged;
  end;
end;

procedure TWidgetControl.SetChildOrder(Child: TComponent; Order: Integer);
begin
  if Child is TWidgetControl then
    TWidgetControl(Child).SetZOrderPosition(Order)
  else if Child is TControl then
    TControl(Child).SetZOrderPosition(Order);
end;

procedure TWidgetControl.SetZOrderPosition(Position: Integer);
var
  I, Count: Integer;
begin
  if Assigned(FParent) then
  begin
    if Assigned(FParent.FControls) then
      Dec(Position, FParent.FControls.Count);
    I := FParent.FWidgets.IndexOf(Self);
    if I >= 0 then
    begin
      Count := FParent.FWidgets.Count;
      if Position < 0 then
        Position := 0;
      if Position >= Count then
        Position := Count - 1;
      if Position <> I then
      begin
        FParent.FWidgets.Delete(I);
        FParent.FWidgets.Insert(Position, Self);
      end;
    end;
    if Assigned(FHandle) then
    begin
      if Position = 0 then
        QWidget_lower(FHandle)
      else if Position = FParent.FWidgets.Count-1 then
        QWidget_raise(FHandle)
      else if Position < I then
        QWidget_stackUnder(FHandle, TWidgetControl(FParent.FWidgets[Position+1]).Handle)
      else if Position > I then
        QWidget_stackUnder(FHandle, TWidgetControl(FParent.FWidgets[Position-1]).Handle);
    end;
  end;
end;

procedure TWidgetControl.SetZOrder(TopMost: Boolean);
var
  M, N: Integer;
begin
  if Assigned(FParent) then
  begin
    if TopMost then
      N := FParent.FWidgets.Count - 1
    else
      N := 0;
    M := 0;
    if Assigned(FParent.FControls) then
      M := FParent.FControls.Count;
    SetZOrderPosition(M + N);
  end
  else if TopMost then
  begin
    if HandleAllocated then
      QWidget_raise(FHandle);
    if FParent <> nil then
    begin
      FParent.FWidgets.Remove(Self);
      FParent.FWidgets.Add(Self);
    end;
  end
  else
  begin
    if HandleAllocated then
      QWidget_lower(Handle);
    if FParent <> nil then
    begin
      FParent.FWidgets.Remove(Self);
      FParent.FWidgets.Insert(0, Self);
    end;
  end;
end;

procedure TWidgetControl.ShowControl(AControl: TControl);
begin
  if Parent <> nil then
    Parent.ShowControl(Self);
end;

procedure TWidgetControl.ShowingChanged;
begin
  if HandleAllocated then
    UpdateWidgetShowing;
end;

procedure TWidgetControl.TabStopChanged;
begin
  { Notification }
end;

{$IFDEF LINUX}

function IsPaintOnHandle(display: Xlib.PDisplay; event: PXEvent;
  arg: XPointer): Bool; cdecl;
begin
  Result := Bool(((event^.xtype = Expose) or (event^.xtype = GraphicsExpose))
    and (event^.xexpose.xwindow = Window(arg)));
end;

procedure ForcePaints(Widget: QWidgetH);

  procedure ForcePaintsOn(Display: Xlib.PDisplay; W: Window);
  var
    Event: XEvent;
  begin
    while XCheckIfEvent(Display, @Event, IsPaintOnHandle, XPointer(W)) = XTrue do
      // Have Qt handle the event
      QApplication_x11ProcessEvent(Application.Handle, @Event);
  end;

  procedure ForcePaintsOnWidget(Display: Xlib.PDisplay; W: Window);
  type
    PWindows = ^TWindows;
    TWindows = array[0..255] of Window;
  var
    RootWindow: Window;
    ParentWindow: Window;
    NChildren: Cardinal;
    Children: PWindows;
    I: Integer;
  begin
    ForcePaintsOn(Display, W);
    XQueryTree(Display, W, @RootWindow, @ParentWindow, @Children, @NChildren);
    try
      if NChildren > 0 then
        for I := 0 to NChildren - 1 do
          ForcePaintsOnWidget(Display, Children^[I]);
    finally
      if Children <> nil then
        XFree(Children);
    end;
  end;

begin
  // Extract and send all Expose and GraphicsExpose events in the X queue
  ForcePaintsOnWidget(Xlib.PDisplay(QtDisplay), QWidget_winId(Widget));
  // Tell Qt to send all pending Paint events.
  QApplication_sendPostedEvents(nil, Integer(QEventType_Paint));
end;
{$ENDIF}
{$IFDEF MSWINDOWS}
procedure ForcePaints(Handle: QWidgetH);
begin
  UpdateWindow(QWidget_winId(Handle));
end;
{$ENDIF}

procedure TWidgetControl.Update;
begin
  if HandleAllocated then
    ForcePaints(Handle);
end;

procedure TWidgetControl.UpdateBounds;
var
  R: TRect;
  OldSize: TPoint;
begin
  if HandleAllocated then
  begin
    OldSize := Point(FWidth, FHeight);
    QWidget_geometry(FHandle, @R);
    FLeft := R.Left;
    FTop := R.Top;
    FWidth := R.Right - R.Left;
    FHeight := R.Bottom - R.Top;
    AdjustForFrame(FLeft, FTop, FWidth, FHeight, False);
    if (OldSize.X <> FWidth) or (OldSize.Y <> FHeight) then
      DoConstrainedResize(FWidth, FHeight);
    UpdateAnchorRules;
    Realign;
    if not (csLoading in ComponentState) and ((FWidth <> OldSize.X) or
      (FHeight <> OldSize.Y)) then
      Resize;
  end;
end;

procedure TWidgetControl.UpdateControlState;
var
  Control: TWidgetControl;
begin
  Control := Self;
  while Control.Parent <> nil do
  begin
    Control := Control.Parent;
    if not Control.Showing then
      Exit;
  end;
  if (Control is TCustomForm) or (Control.FParentWidget <> nil) then
    UpdateShowing;
end;

procedure TWidgetControl.UpdateShowing;
var
  ShowControl: Boolean;
  I: Integer;
  Widget: TWidgetControl;
begin
  ShowControl := (FVisible or (csDesigning in ComponentState) and
    not (csNoDesignVisible in ControlStyle)) and
    not (csReadingState in ControlState);
  if ShowControl then
  begin
    HandleNeeded;
    if FWidgets <> nil then
      for I := 0 to FWidgets.Count - 1 do
      begin
        Widget := TWidgetControl(FWidgets[I]);
        Widget.UpdateShowing;
        if Widget.Showing and Widget.Visible then
          TWidgetControl(FWidgets[I]).Resize;
      end;
  end;
  if HandleAllocated then
    if FShowing <> ShowControl then
    begin
       FShowing := ShowControl;
      try
        ShowingChanged;
      except
        FShowing := not ShowControl;
        raise;
      end;
    end;
end;

procedure TWidgetControl.UpdateWidgetShowing;
begin
  if FShowing then
    QWidget_show(Handle)
  else
    QWidget_hide(Handle);
end;

procedure TWidgetControl.UpdateTabOrder(Value: TTabOrder);
var
  CurIndex, Count: Integer;
begin
  CurIndex := GetTabOrder;
  if CurIndex >= 0 then
  begin
    Count := FParent.FTabList.Count;
    if Value < 0 then
      Value := 0;
    if Value >= Count then
      Value := Count - 1;
    if Value <> CurIndex then
    begin
      FParent.FTabList.Delete(CurIndex);
      FParent.FTabList.Insert(Value, Self);
    end;
  end;
end;

procedure TWidgetControl.VisibleChanged;
begin
  if not FVisible and (Parent <> nil) then RemoveFocus(False);
  UpdateControlState;
end;

procedure TWidgetControl.ShowHintChanged;
begin
  inherited ShowHintChanged;
  NotifyControls(CM_PARENTSHOWHINTCHANGED);
end;

procedure TWidgetControl.InitWidget;
const
  FocusPolicy: array[Boolean] of QWidgetFocusPolicy =
    (QWidgetFocusPolicy_ClickFocus, QWidgetFocusPolicy_NoFocus);
var
  I: Integer;
begin
{
  Initialize Widgets here
  Handle is created and Parent is set
}
  AdjustForFrame(FLeft, FTop, FWidth, FHeight, True);
  QWidget_setGeometry(Handle, FLeft, FTop, FWidth, FHeight);
  if Assigned(FStyle) then
    QWidget_setStyle(Handle, FStyle.Handle);

  QWidget_setMouseTracking(Handle, True);
  QWidget_setAcceptDrops(FHandle, True);
  QWidget_setFocusPolicy(Handle, FocusPolicy[csNoFocus in ControlStyle]);

  Masked := False;
  if FColor = clNone then
    FColor := TColor(-Ord(Palette.ColorRole)-1);
  FBrush.Color := FColor;
  for I := 0 to ControlCount - 1 do
    Controls[I].UpdateAnchorRules;
  if csAlignmentNeeded in FControlState then
    Realign;
end;

procedure TWidgetControl.SetParent(const Value: TWidgetControl);
begin
  if Value <> nil then
    FParentWidget := Value.ChildHandle;
  inherited SetParent(Value);
  if not (csDestroying in ComponentState) and HandleAllocated then
    ReSubmitFlags;
end;

procedure TWidgetControl.DestroyedHook;
begin
  try
    WidgetDestroyed;
  except
    Application.HandleException(Self);
  end;
end;

function TWidgetControl.GetEnabled: Boolean;
begin
  if csDesigning in ComponentState then
    Result := inherited GetEnabled
  else
    Result := QOpenWidget_getWState(QOpenWidgetH(Handle)) and Integer(WidgetState_WState_ForceDisabled) = 0;
end;

function TWidgetControl.IsMenuKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
var
  Control: TWidgetControl;
  Form: TCustomForm;
  LocalPopupMenu: TPopupMenu;
begin
  Result := True;
  if not (csDesigning in ComponentState) then
  begin
    Control := Self;
    while Control <> nil do
    begin
      LocalPopupMenu := Control.GetPopupMenu;
     if Assigned(LocalPopupMenu) and (LocalPopupMenu.Handle <> nil) and
      LocalPopupMenu.IsShortCut(Key, Shift, KeyText) then
        Exit;
      Control := Control.Parent;
    end;
    Form := GetParentForm(Self);
    if (Form <> nil) and Form.IsShortCut(Key, Shift, KeyText) then
      Exit;
  end;
  if Application.IsShortCut(Key, Shift, KeyText) then Exit;
  Result := False;
end;

procedure TWidgetControl.SetText(const Value: TCaption);
begin
  if Caption <> Value then
  begin
    QWidget_setCaption(Handle, @Value);
    TextChanged;
  end;
end;

function TWidgetControl.GetText: TCaption;
begin
  if HandleAllocated then
    QWidget_caption(Handle, @Result)
  else
    Result := ''; 
end;

function TWidgetControl.GetPaintDevice: QPaintDeviceH;
begin
  Result := QWidget_to_QPaintDevice(ChildHandle);
end;

function TWidgetControl.WidgetFlags: Integer;
begin
  Result := 0;
end;

procedure TWidgetControl.WidgetDestroyed;
begin
  if Assigned(FHooks) then
  begin
    QWidget_hook_destroy(FHooks);
    FHooks := nil;
  end;
  QClxObjectMap_remove(FHandle);
  FHandle := nil;
end;

procedure TWidgetControl.SetInitialBounds;
begin
  if HandleAllocated then
    QWidget_setGeometry(Handle, FLeft, FTop, FWidth, FHeight);
end;

procedure TWidgetControl.SetInitialSize;
var
  R: TRect;
begin
  if HandleAllocated then
  begin
    QWidget_Geometry(Handle, @R);
    if not (sfHeight in FSizedFlags) then
      FHeight := R.Bottom - R.Top;
    if not (sfWidth in FSizedFlags) then
      FWidth := R.Right - R.Left;
  end;
end;

procedure TWidgetControl.EnabledChanged;
begin
  if not (csDesigning in ComponentState) then
    QWidget_setEnabled(Handle, FEnabled);
  inherited EnabledChanged;
end;

procedure TWidgetControl.FontChanged;
begin
  QWidget_setFont(Handle, Font.Handle, True);
  Palette.TextColor := Font.Color;
  Invalidate;
  NotifyControls(CM_PARENTFONTCHANGED);
end;

procedure TWidgetControl.StyleChanged(Sender: TObject);
begin
  if not (csDestroying in ComponentState) and HandleAllocated then
    QWidget_setStyle(Handle, FStyle.Handle);
end;

procedure TWidgetControl.SetBitmap(const Value: TBitmap);
begin
  Palette.Bitmap := Value;
  if Value = nil then ColorChanged;
  Invalidate;
end;

procedure TWidgetControl.PaletteChanged(Sender: TObject);
begin
  QWidget_setPalette(Handle, (Sender as TPalette).Handle, True);
end;

function TWidgetControl.GetStyle: TWidgetStyle;
begin
  if not Assigned(FStyle) then
  begin
    FStyle := TWidgetStyle.Create;
    if HandleAllocated then
      QWidget_setStyle(Handle, FStyle.Handle);
    FStyle.OnChange := StyleChanged;
  end;
  Result := FStyle;
end;

procedure TWidgetControl.SetStyle(const Value: TWidgetStyle);
begin
  if FStyle <> Value then
  begin
    if not Assigned(Value) then
    begin
      if Assigned(FStyle) then
        FreeAndNil(FStyle);
      if HandleAllocated then
        QWidget_setStyle(Handle, QApplication_style);
      Exit;
    end
    else
      FStyle := Value;
    FStyle.OnChange := StyleChanged;
    if HandleAllocated then
      QWidget_setStyle(Handle, FStyle.Handle); 
  end;
end;

function TWidgetControl.CustomAlignInsertBefore(C1, C2: TControl): Boolean;
begin
  { Notification }
  Result := False;
end;

procedure TWidgetControl.CustomAlignPosition(Control: TControl; var NewLeft,
  NewTop, NewWidth, NewHeight: Integer; var AlignRect: TRect);
begin
  { Notification }
end;

function TWidgetControl.GetBitmap: TBitmap;
begin
  Result := FPalette.Bitmap;
end;

procedure TWidgetControl.ColorChanged;
begin
  HandleNeeded;
  if Bitmap.Empty then
  begin
    Palette.Color := FColor;
    FBrush.Color := FColor;
  end;
  NotifyControls(CM_PARENTCOLORCHANGED);
  inherited;
end;

procedure TWidgetControl.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
  Control: TControl;
begin
  for I := 0 to ControlCount - 1 do
  begin
    Control := Controls[I];
    if Control.Owner = Root then
      Proc(Control);
  end;
end;

procedure TWidgetControl.ReSubmitFlags;
var
  P: TPoint;
  F: Cardinal;
begin
  P := Point(FLeft, FTop);
  F := QOpenWidget_getWFlags(QOpenWidgetH(Handle));
  QWidget_reparent(Handle, ParentWidget, Cardinal(WidgetFlags) or F, @P, Showing);
  if (csDesigning in ComponentState) and (ParentWidget <> nil) then
    QWidget_setFocusProxy(FHandle, ParentWidget);
  //Qt seems to "lose" the widget flags _and_ widgetstate flags (such as MouseTracking, etc) when reparenting.
  QOpenWidget_clearWFlags(QOpenWidgetH(Handle), Integer($FFFFFFFF));
  QOpenWidget_setWFlags(QOpenWidgetH(Handle), Cardinal(WidgetFlags) or F);
  QWidget_setMouseTracking(Handle, True);
  QWidget_setAcceptDrops(Handle, True);
  UpdateWidgetShowing; { Force the current state of the widget }
end;

function TWidgetControl.GetChildHandle: QWidgetH;
begin
  Result := Handle;
end;

function TWidgetControl.ViewportRect: TRect;
begin
  Result := ClientRect;
end;

procedure TWidgetControl.SetMasked(const Value: Boolean);
begin
  if FMasked <> Value then
  begin
    FMasked := Value;
    MaskChanged;
  end;
end;

procedure TWidgetControl.MaskChanged;
begin
  QWidget_setAutoMask(Handle, FMasked);
end;

procedure TWidgetControl.CMKeyDown(var Msg: TCMKeyDown);
var
  ParentForm: TCustomForm;
  Wanted: Boolean;
begin
  with Msg do
  begin
    Wanted := False;
    if not NeedKey(Key, Shift, KeyText) then
    begin
      ParentForm := GetParentForm(Self);
      if Assigned(ParentForm) then
        Wanted := IsMenuKey(Key, Shift, KeyText)
          or ParentForm.WantKey(Key, Shift, KeyText)
      else
        Wanted := False;
    end;
    Handled := Wanted or Handled;
  end;
end;

function TWidgetControl.NeedKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  Result := (csDesigning in ComponentState) or
    CheckInputKeys(Key, Shift, KeyText);
end;

function TWidgetControl.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
var
  I: Integer;
begin
  Result := inherited WantKey(Key, Shift, KeyText);
  if not Result then
    for I := 0 to ControlCount - 1 do
    begin
      if Controls[I].Visible and Controls[I].Enabled then
        Result := Controls[I].WantKey(Key, Shift, KeyText);
      if Result then Exit;
    end;
end;

function TWidgetControl.CheckInputKeys(Key: Integer;
  Shift: TShiftState; const KeyText: WideString): Boolean;

  function IsArrowKey: Boolean;
  begin
    Result := (Key = Key_Left) or (Key = Key_Right) or
      (Key = Key_Down) or (Key = Key_Up);
  end;

  function IsNavKey: Boolean;
  begin
    Result := IsArrowKey or (Key = Key_Home) or (Key = Key_End) or
      (Key = Key_PageUp) or (Key = Key_PageDown);
  end;

  function IsTabKey: Boolean;
  begin
    Result := (Key = Key_Tab) or (Key = Key_BackTab);
  end;

  function IsReturnKey: Boolean;
  begin
    Result := (Key = Key_Enter) or (Key = Key_Return);
  end;

  function IsEditKey: Boolean;
  begin
    Result := (Key = Key_Backspace) or (Key = Key_Insert)
      or (Key = Key_Delete);
  end;

  function IsChar: Boolean;
  begin
    Result := ((Shift - [ssCtrl, ssAlt] = Shift)
      and ((Hi(Word(Key)) = 0) or (Length(KeyText) > 0))
      and not (IsEditKey or IsTabKey or IsReturnKey or (Key = Key_Escape)));
  end;

begin
  Result := ikAll in FInputKeys;
  if not Result then
  begin
    Result := ((ikChars in FInputKeys) and IsChar)
      or ((ikArrows in FInputKeys) and IsArrowKey)
      or ((ikNav in FInputKeys) and IsNavKey)
      or ((ikEdit in FInputKeys) and IsEditKey)
      or ((ikTabs in FInputKeys) and IsTabKey)
      or ((ikReturns in FInputKeys) and IsReturnKey)
      or ((ikEsc in FInputKeys) and (Key = Key_Escape));
  end;
end;

procedure TWidgetControl.SetBrush(const Value: TBrush);
begin
  FBrush.Assign(Value);
end;

procedure TWidgetControl.ReadState(Reader: TReader);
begin
  DisableAlign;
  try
    inherited ReadState(Reader);
  finally
    EnableAlign;
  end;
  FixupTabList;
  UpdateControlState;
end;

procedure TWidgetControl.FixupTabList;
var
  Count, I, J: Integer;
  List: TList;
  Control: TWidgetControl;
begin
  if FWidgets <> nil then
  begin
    List := TList.Create;
    try
      Count := FWidgets.Count;
      List.Count := Count;
      for I := 0 to Count - 1 do
      begin
        Control := FWidgets[I];
        J := Control.FTabOrder;
        if (J >= 0) and (J < Count) then List[J] := Control;
      end;
      for I := 0 to Count - 1 do
      begin
        Control := List[I];
        if Control <> nil then Control.UpdateTabOrder(I);
      end;
    finally
      List.Free;
    end;
  end;
end;

{ TGraphicControl }

constructor TGraphicControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCanvas := TControlCanvas.Create;
  TControlCanvas(FCanvas).Control := Self;
  Include(FControlStyle, csCaptureMouse);
end;

destructor TGraphicControl.Destroy;
begin
  FCanvas.Free;
  inherited Destroy;
end;

procedure TGraphicControl.Paint;
begin
  { Does nothing, it should be overridden by a descendent }
end;

procedure TGraphicControl.PaintRequest;
begin
  Paint;
end;

{ TCustomControl }

procedure TCustomControl.BoundsChanged;
begin
  inherited BoundsChanged;
  if Masked then
    UpdateMask;
end;
                                 
constructor TCustomControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCanvas := TControlCanvas.Create;
  TControlCanvas(FCanvas).Control := Self;
end;

procedure TCustomControl.CreateWidget;
begin
  FHandle := QWidget_create(ParentWidget, nil, WidgetFlags);
  FHooks := QWidget_hook_create(FHandle);
end;

destructor TCustomControl.Destroy;
begin
  inherited Destroy;
  // This is freed after calling inherited because the inherited destructor
  // can force a paint operation if a Invalidate is pending. We should keep
  // the canvas around as long as possible.
  FCanvas.Free;
end;

procedure TCustomControl.Painting(Sender: QObjectH; EventRegion: QRegionH);
begin
  TControlCanvas(FCanvas).StartPaint;
  try
    QPainter_setClipRegion(FCanvas.Handle, EventRegion);
    Paint;
  finally
    TControlCanvas(FCanvas).StopPaint;
  end;
end;

procedure TCustomControl.DrawMask(Canvas: TCanvas);
var
  R: TRect;
  I: Integer;
begin
  R := ClientRect;
  Canvas.Brush.Color := clMask;
  Canvas.FillRect(R);
  Canvas.Brush.Color := clDontMask;
  if FControls <> nil then
  for I := 0 to FControls.Count - 1 do
  begin
    R := TControl(FControls[I]).BoundsRect;
    Canvas.FillRect(R);
  end;
  if FWidgets <> nil then
  for I := 0 to FWidgets.Count - 1 do
  begin
    Canvas.Brush.Color := clDontMask;
    R := TWidgetControl(FWidgets[I]).BoundsRect;
    Canvas.FillRect(R);
  end;
end;

function TCustomControl.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  Result := inherited EventFilter(Sender, Event);
  case QEvent_type(Event) of
    QEventType_Resize,
    QEventType_FocusIn,
    QEventType_FocusOut:
      UpdateMask;
  end;
end;

procedure TCustomControl.Invalidate;
begin
  inherited Invalidate;
  UpdateMask;
end;

procedure TCustomControl.Paint;
begin
  { Notification }
end;

procedure TCustomControl.MaskChanged;
begin
  if Masked then
    UpdateMask
  else
    QWidget_clearMask(Handle);
end;

procedure TCustomControl.UpdateMask;
var
  QB: QBitmapH;
  QP: QPainterH;
  Canvas: TCanvas;
begin
  if not Masked or not HandleAllocated then Exit;
  QB := QBitmap_create(Width, Height, True, QPixmapOptimization_DefaultOptim);
  try
    QP := QPainter_create(QB, Handle);
    try
      Canvas := TCanvas.Create;
      try
        Canvas.Start(False);
        Canvas.Handle := QP;
        DrawMask(Canvas);
        Canvas.Stop;
      finally
        Canvas.Free;
      end;
      QWidget_setMask(Handle, QB);
    finally
      QPainter_destroy(QP);
    end;
  finally
    QBitmap_destroy(QB);
  end;
end;

{ TControlCanvas }

procedure TControlCanvas.BeginPainting;
begin
  if not QPainter_isActive(Handle) then
    QPainter_begin(Handle, Control.GetPaintDevice);
  Control.AdjustPainter(Handle);
end;

procedure TControlCanvas.CreateHandle;
begin
  if FControl = nil then
    inherited CreateHandle
  else
    Handle := QPainter_create;
end;

destructor TControlCanvas.Destroy;
begin
  FreeHandle;
  inherited Destroy;
end;

procedure TControlCanvas.FreeHandle;
var
  H: QPainterH;
begin
  H := FHandle;
  if H <> nil then
  begin
    Handle := nil;
    QPainter_destroy(H);
  end;
end;

procedure TControlCanvas.SetClipped(const Value: Boolean);
begin
  if StartCount > 0 then
    raise ECanvasException.CreateRes(@sInvalidSetClipped);
  FClipped := Value;
end;

procedure TControlCanvas.SetControl(AControl: TControl);
begin
  if FControl <> AControl then
  begin
    FreeHandle;
    FControl := AControl;
  end;
end;

procedure TControlCanvas.StartPaint;
begin
  Start;
end;

procedure TControlCanvas.StopPaint;
begin
  Stop;
end;

{ TQtCanvas }

procedure TQtCanvas.BeginPainting;
begin
  if not QPainter_isActive(Handle) then
    QPainter_begin(Handle, QWidget_to_QPaintDevice(FQtHandle));
end;

procedure TQtCanvas.CreateHandle;
begin
  Handle := QPainter_create;
end;

destructor TQtCanvas.Destroy;
begin
  FreeHandle;
  inherited Destroy;
end;

procedure TQtCanvas.FreeHandle;
var
  H: QPainterH;
begin
  H := FHandle;
  if H <> nil then
  begin
    Handle := nil;
    QPainter_destroy(H);
  end;
end;

procedure TQtCanvas.SetClipped(const Value: Boolean);
begin
  if StartCount > 0 then
    raise ECanvasException.CreateRes(@sInvalidSetClipped);
  FClipped := Value;
end;

procedure TQtCanvas.SetQtHandle(AQtHandle: QWidgetH);
begin
  if FQtHandle <> AQtHandle then
  begin
    FreeHandle;
    FQtHandle := AQtHandle;
  end;
end;

procedure TQtCanvas.StartPaint;
begin
  Start;
end;

procedure TQtCanvas.StopPaint;
begin
  Stop;
end;

{ THintWindow }

constructor THintWindow.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Parent := nil;

  Canvas.Font := Screen.HintFont;
end;

function THintWindow.WidgetFlags: Integer;
begin
  Result := Integer(WidgetFlags_WStyle_Customize)
              or Integer(WidgetFlags_WType_TopLevel)
              or Integer(WidgetFlags_WStyle_Tool)
              or Integer(WidgetFlags_WStyle_StaysOnTop)
              or Integer(WidgetFlags_WStyle_NoBorder);
end;

procedure THintWindow.ReleaseHandle;
begin
  DestroyHandle;
end;

procedure THintWindow.FontChanged;
begin
  Canvas.Font := Screen.HintFont;
  { Recalc the Height and Width }
  TextChanged;
  Invalidate;
end;

procedure THintWindow.TextChanged;
begin
  { Avoid flicker when calling ActivateHint }
  if FActivating then Exit;

  Width := Canvas.TextWidth(Caption) + 6;
  Height := Canvas.TextHeight(Caption) + 4;
end;

procedure THintWindow.Paint;
const
  TextFlags = Integer(AlignmentFlags_AlignLeft)
                or Integer(AlignmentFlags_AlignVCenter)
                or Integer(AlignmentFlags_WordBreak)
                or Integer(AlignmentFlags_DontClip);
var
  Rect: TRect;
  DefaultDraw: Boolean;
begin
  Rect := ClientRect;
  Canvas.Brush.Color := Color;
  Canvas.Brush.Style := bsSolid;

  if Assigned(Application.Style.DrawHint) then
  begin
    DefaultDraw := True;
    Application.Style.DrawHint(Self, Canvas, Rect, DefaultDraw);
    if not DefaultDraw then Exit;
  end;

  Canvas.Rectangle(Rect);
  Canvas.TextRect(Rect, 3, 0, Caption, TextFlags);
end;

procedure THintWindow.ActivateHint(Rect: TRect; const AHint: WideString);
begin
  FActivating := True;
  try
    Caption := AHint;
    if Rect.Bottom > Screen.Height then
    begin
      Rect.Top := Screen.Height - (Rect.Bottom - Rect.Top);
      Rect.Bottom := Screen.Height;
    end;
    if Rect.Right > Screen.Width then
    begin
      Rect.Left := Screen.Width - (Rect.Right - Rect.Left);
      Rect.Right := Screen.Width;
    end;
    if Rect.Left < 0 then Rect.Left := 0;
    if Rect.Bottom < 0 then Rect.Bottom := 0;

    SetBounds(Rect.Left, Rect.Top, Rect.Right - Rect.Left, Rect.Bottom - Rect.Top);

    QWidget_show(Handle);
    QWidget_raise(Handle);
  finally
    FActivating := False;
  end;
end;

procedure THintWindow.ActivateHintData(Rect: TRect; const AHint: WideString;
  AData: Pointer);
begin
  ActivateHint(Rect, AHint);
end;

function THintWindow.CalcHintRect(MaxWidth: Integer; const AHint: WideString;
  AData: Pointer): TRect;
const
  TextFlags = Integer(AlignmentFlags_AlignLeft) or
    Integer(AlignmentFlags_WordBreak) or Integer(AlignmentFlags_DontClip);
var
  fm: QFontMetricsH;
begin
  fm := QFontMetrics_create(Canvas.Font.Handle);
  try
    QFontMetrics_boundingRect(fm, @Result, 0, 0, MaxWidth, 0, TextFlags,
      @AHint, -1, 0, nil, nil);
  finally
    QFontMetrics_destroy(fm);
  end;
  Inc(Result.Bottom, 2);
  Dec(Result.Top, 2);
  Inc(Result.Right, 8);
end;

{ TFrameControl }

const
  cFCQtFrameStyles: array[TBorderStyle] of Integer = (
    Integer(QFrameShape_NoFrame),
    Integer(QFrameShape_Box) or Integer(QFrameShadow_Plain),
    Integer(QFrameShape_WinPanel) or Integer(QFrameShadow_Plain),
    Integer(QFrameShape_StyledPanel) or Integer(QFrameShadow_Raised),
    Integer(QFrameShape_StyledPanel) or Integer(QFrameShadow_Sunken),
    Integer(QFrameShape_WinPanel) or Integer(QFrameShadow_Raised),
    Integer(QFrameShape_WinPanel) or Integer(QFrameShadow_Sunken),
    Integer(QFrameShape_Box) or Integer(QFrameShadow_Sunken),
    Integer(QFrameShape_Box) or Integer(QFrameShadow_Raised));

constructor TFrameControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Palette.ColorRole := crBase;
  Palette.TextColorRole := crText;
end;

function TFrameControl.ContentsRect: TRect;
begin
  QFrame_contentsRect(Handle, @Result);
end;

procedure TFrameControl.CreateWidget;
begin
  FHandle := QFrame_create(ParentWidget, nil, WidgetFlags, True);
end;

procedure TFrameControl.InitWidget;
begin
  inherited InitWidget;
  QFrame_setFrameStyle(Handle, cFCQtFrameStyles[FBorderStyle]);
  MidLineWidth := 0;
  LineWidth := 1;
end;

function TFrameControl.GetClientOrigin: TPoint;
begin
  Result.X := QFrame_frameWidth(Handle);
  Result.Y := Result.X;
  QWidget_mapToGlobal(Handle, @Result, @Result);
end;

function TFrameControl.GetFrameRect: TRect;
begin
  QFrame_frameRect(Handle, @Result);
end;

function TFrameControl.GetHandle: QFrameH;
begin
  HandleNeeded;
  Result := QFrameH(FHandle);
end;

function TFrameControl.GetLineWidth: Integer;
begin
  Result := QFrame_lineWidth(Handle);
end;

function TFrameControl.GetMargin: Integer;
begin
  Result := QFrame_margin(Handle);
end;

function TFrameControl.GetMidLineWidth: Integer;
begin
  Result := QFrame_midLineWidth(Handle);
end;

procedure TFrameControl.SetFrameRect(const Value: TRect);
begin
  QFrame_setFrameRect(Handle, @Value);
end;

procedure TFrameControl.SetLineWidth(const Value: Integer);
begin
  if LineWidth <> Value then
    QFrame_setLineWidth(Handle, Value);
end;

procedure TFrameControl.SetMargin(const Value: Integer);
begin
  if Margin <> Value then
    QFrame_setMargin(Handle, Value);
end;

procedure TFrameControl.SetMidLineWidth(const Value: Integer);
begin
  if MidLineWidth <> Value then
    QFrame_setMidLineWidth(Handle, Value);
end;

procedure TFrameControl.SetBorderStyle(const Value: TBorderStyle);
begin
  if FBorderStyle <> Value then
  begin
    FBorderStyle := Value;
    if HandleAllocated then
      QFrame_setFrameStyle(Handle, cFCQtFrameStyles[FBorderStyle]);
    Invalidate;
  end;
end;

{$IFDEF LINUX}

constructor TX11DragFilter.Create(AObject: QObjectH);
var
  Method: TMethod;
begin
  inherited Create;
  FHook := QObject_hook_create(AObject);
  TEventFilterMethod(Method) := EventFilter;
  Qt_hook_hook_events(FHook, Method);
end;

destructor TX11DragFilter.Destroy;
begin
  QObject_hook_destroy(FHook);
  X11DragFilter := nil;
  DragHooked := False;
  inherited Destroy;
end;

function TX11DragFilter.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  Result := False;
  try
    if QEvent_type(Event) = QEventType_KeyPress then
      if QKeyEvent_key(QKeyEventH(Event)) = Key_Escape then
        CancelDrag;
  except
    Application.HandleException(Self);
  end;
end;

{$ENDIF}

{ TDragObject }

procedure TDragObject.Assign(Source: TDragObject);
begin
  FDragTargetPos := Source.FDragTargetPos;
end;

constructor TDragObject.Create;
begin
  inherited Create;
end;

destructor TDragObject.Destroy;
begin
  inherited Destroy;
end;

procedure TDragObject.Finished(Target: TObject; X, Y: Integer; Accepted: Boolean);
begin
  { Notification }
end;

function TDragObject.GetDragImageHotSpot: TPoint;
begin
  Result := Point(-1, -1);
end;

function TDragObject.GetDragImageIndex: Integer;
begin
  Result := -1;
end;

function TDragObject.GetKeyState: TShiftState;
begin
  Result := Application.KeyState;
end;

function TDragObject.GetIsInterApp: Boolean;
begin
  Result := False;
  if not Assigned(DragDropEvent) then
    Exit;
  Result := (QDropEvent_source(DragDropEvent) = nil) or (QDragObject_target = nil);
end;

procedure TDragObject.HideDragImage;
begin
  { Notification }
end;

procedure TDragObject.SetDragImage;
var
  Index: Integer;
  Pt: TPoint;
  Pixmap: QPixmapH;
begin
  Index := GetDragImageIndex;
  if Assigned(DragImages) then
  begin
    Pt := GetDragImageHotSpot;
    Pixmap := DragImages.GetPixmap(Index);
    if Assigned(Pixmap) then
      QDragObject_setPixmap(ClxDragObj, Pixmap, @Pt)
    else
    begin
      Pixmap := QPixmap_create;
      try
        QDragObject_setPixmap(ClxDragObj, Pixmap, @Pt);
      finally
        QPixmap_destroy(Pixmap);
      end;
    end;
  end;
end;

procedure TDragObject.ShowDragImage;
begin
  { Notification }
end;

{ TBaseDragControlObject }

constructor TBaseDragControlObject.Create(AControl: TControl);
begin
  inherited Create;
  FControl := AControl;
  FControl.FDragObject := Self;
end;

destructor TBaseDragControlObject.Destroy;
begin
  FControl.FDragObject := nil;
  inherited Destroy;
end;

procedure TBaseDragControlObject.Assign(Source: TDragObject);
begin
  inherited Assign(Source);
  if Source is TBaseDragControlObject then
    FControl := TBaseDragControlObject(Source).FControl;
end;

procedure TBaseDragControlObject.EndDrag(Target: TObject; X, Y: Integer);
begin
  FControl.DoEndDrag(Target, X, Y);
end;

procedure TBaseDragControlObject.Finished(Target: TObject; X, Y: Integer;
  Accepted: Boolean);
begin
  if not Accepted then
  begin
    FControl.DragCanceled;
    Target := nil;
  end;
  EndDrag(Target, X, Y);
end;

{ TDragControlObject }

function TDragControlObject.GetDragImageHotSpot: TPoint;
begin
  Result := Control.GetDragImageHotSpot;
end;

function TDragControlObject.GetDragImageIndex: Integer;
begin
  Result := Control.GetDragImageIndex;
end;

procedure TDragControlObject.HideDragImage;
var
  Pixmap: QPixmapH;
begin
  Pixmap := QPixmap_create;
  try
    QDragObject_setPixmap(ClxDragObj, Pixmap);
  finally
    QPixmap_destroy(Pixmap);
  end;
end;

procedure TDragControlObject.ShowDragImage;
begin
  SetDragImage;
end;

{ TMouse }

constructor TMouse.Create;
begin
  inherited Create;
  DragThreshold := 5;
  FDragImmediate := True;
end;

destructor TMouse.Destroy;
begin
  Capture := nil;
  inherited Destroy;
end;

function TMouse.GetCapture: TControl;
begin
  Result := MouseGrabControl;
end;

function TMouse.GetCursorPos: TPoint;
begin
  QControls.GetCursorPos(Result);
end;

procedure TMouse.SetCapture(const Value: TControl);
begin
  if Capture <> Value then
    SetMouseGrabControl(Value);
end;

procedure TMouse.SetCursorPos(const Value: TPoint);
begin
  QCursor_setPos(@Value);
end;

{ TSizeConstraints }

constructor TSizeConstraints.Create(Control: TControl);
begin
  inherited Create;
  FControl := Control;
end;

procedure TSizeConstraints.AssignTo(Dest: TPersistent);
begin
  if Dest is TSizeConstraints then
    with TSizeConstraints(Dest) do
    begin
      FMaxHeight := Self.FMaxHeight;
      FMaxWidth := Self.FMaxWidth;
      FMinHeight := Self.FMinHeight;
      FMaxHeight := Self.FMaxHeight;
      Change;
    end
  else inherited AssignTo(Dest);
end;

procedure TSizeConstraints.SetConstraints(Index: Integer;
  Value: TConstraintSize);
begin
  case Index of
    0:
      if Value <> FMaxHeight then
      begin
        FMaxHeight := Value;
        if (FMaxHeight > 0) and (FMaxHeight < FMinHeight) then
        begin
          FMinHeight := FMaxHeight;
          if Control is TWidgetControl then
            QWidget_setMinimumHeight(TWidgetControl(Control).Handle, FMinHeight);
        end;
        if Control is TWidgetControl then
          if FMaxHeight = 0 then
            QWidget_setMaximumHeight(TWidgetControl(Control).Handle, QClxWidget_MaxWidgetSize)
          else
            QWidget_setMaximumHeight(TWidgetControl(Control).Handle, FMaxHeight);
        Change;
      end;
    1:
      if Value <> FMaxWidth then
      begin
        FMaxWidth := Value;
        if (FMaxWidth > 0) and (FMaxWidth < FMinWidth) then
        begin
          FMinWidth := FMaxWidth;
          if Control is TWidgetControl then
            QWidget_setMinimumWidth(TWidgetControl(Control).Handle, FMinWidth);
        end;
        if Control is TWidgetControl then
          if FMaxWidth = 0 then
            QWidget_setMaximumWidth(TWidgetControl(Control).Handle, QClxWidget_MaxWidgetSize)
          else
            QWidget_setMaximumWidth(TWidgetControl(Control).Handle, FMaxWidth);
        Change;
      end;
    2:
      if Value <> FMinHeight then
      begin
        FMinHeight := Value;
        if (FMaxHeight > 0) and (Value > FMaxHeight) then
          FMaxHeight := Value;
        if Control is TWidgetControl then
          QWidget_setMinimumHeight(TWidgetControl(Control).Handle, FMinHeight);
        Change;
      end;
    3:
      if Value <> FMinWidth then
      begin
        FMinWidth := Value;
        if (FMaxWidth > 0) and (Value > FMaxWidth) then
          FMaxWidth := Value;
        if Control is TWidgetControl then
          QWidget_setMinimumWidth(TWidgetControl(Control).Handle, FMinWidth);
        Change;
      end;
  end;
  if Value = 0 then TControl(Control).RequestAlign;
end;

procedure TSizeConstraints.Change;
begin
  if Assigned(FOnChange) then
    FOnChange(Self);
end;

{
procedure ExceptionHandler(ExceptObject: TObject; ExceptAddr: Pointer);
begin
  if ExceptObject is Exception then
    Application.ShowException(Exception(ExceptObject));
end;
}

initialization
  Screen := TScreen.Create(nil);
  Application := TApplication.Create(nil);
  Mouse := TMouse.Create;
  StartClassGroup(TControl);
  ActivateClassGroup(TControl);
  GroupDescendentsWith(TCustomImageList, TControl);
  GroupDescendentsWith(TContainedAction, TControl);
  GroupDescendentsWith(TCustomActionList, TControl);
  RegisterIntegerConsts(TypeInfo(TCursor), IdentToCursor, CursorToIdent);
{
  if not Assigned(ExceptProc) then
    ExceptProc := @ExceptionHandler;
}

finalization
  if Assigned(DragImages) then
    FreeAndNil(DragImages);
  Application.Free;
  Application := nil;
  Mouse.Free;
  Mouse := nil;
  Screen.Free;
  Screen := nil;

end.

