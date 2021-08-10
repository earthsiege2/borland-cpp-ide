
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Controls;

{$P+,S-,W-,R-,T-,H+,X+}
{$C PRELOAD}

interface

{$R CONTROLS}

{ CommCtrl.hpp is not required in Controls.hpp }
(*$NOINCLUDE CommCtrl *)
uses Messages, Windows, MultiMon, Classes, Sysutils, Graphics, Menus, CommCtrl, Imm,
  ImgList, ActnList;

{ VCL control message IDs }

const
  CM_BASE                   = $B000;
  CM_ACTIVATE               = CM_BASE + 0;
  CM_DEACTIVATE             = CM_BASE + 1;
  CM_GOTFOCUS               = CM_BASE + 2;
  CM_LOSTFOCUS              = CM_BASE + 3;
  CM_CANCELMODE             = CM_BASE + 4;
  CM_DIALOGKEY              = CM_BASE + 5;
  CM_DIALOGCHAR             = CM_BASE + 6;
  CM_FOCUSCHANGED           = CM_BASE + 7;
  CM_PARENTFONTCHANGED      = CM_BASE + 8;
  CM_PARENTCOLORCHANGED     = CM_BASE + 9;
  CM_HITTEST                = CM_BASE + 10;
  CM_VISIBLECHANGED         = CM_BASE + 11;
  CM_ENABLEDCHANGED         = CM_BASE + 12;
  CM_COLORCHANGED           = CM_BASE + 13;
  CM_FONTCHANGED            = CM_BASE + 14;
  CM_CURSORCHANGED          = CM_BASE + 15;
  CM_CTL3DCHANGED           = CM_BASE + 16;
  CM_PARENTCTL3DCHANGED     = CM_BASE + 17;
  CM_TEXTCHANGED            = CM_BASE + 18;
  CM_MOUSEENTER             = CM_BASE + 19;
  CM_MOUSELEAVE             = CM_BASE + 20;
  CM_MENUCHANGED            = CM_BASE + 21;
  CM_APPKEYDOWN             = CM_BASE + 22;
  CM_APPSYSCOMMAND          = CM_BASE + 23;
  CM_BUTTONPRESSED          = CM_BASE + 24;
  CM_SHOWINGCHANGED         = CM_BASE + 25;
  CM_ENTER                  = CM_BASE + 26;
  CM_EXIT                   = CM_BASE + 27;
  CM_DESIGNHITTEST          = CM_BASE + 28;
  CM_ICONCHANGED            = CM_BASE + 29;
  CM_WANTSPECIALKEY         = CM_BASE + 30;
  CM_INVOKEHELP             = CM_BASE + 31;
  CM_WINDOWHOOK             = CM_BASE + 32;
  CM_RELEASE                = CM_BASE + 33;
  CM_SHOWHINTCHANGED        = CM_BASE + 34;
  CM_PARENTSHOWHINTCHANGED  = CM_BASE + 35;
  CM_SYSCOLORCHANGE         = CM_BASE + 36;
  CM_WININICHANGE           = CM_BASE + 37;
  CM_FONTCHANGE             = CM_BASE + 38;
  CM_TIMECHANGE             = CM_BASE + 39;
  CM_TABSTOPCHANGED         = CM_BASE + 40;
  CM_UIACTIVATE             = CM_BASE + 41;
  CM_UIDEACTIVATE           = CM_BASE + 42;
  CM_DOCWINDOWACTIVATE      = CM_BASE + 43;
  CM_CONTROLLISTCHANGE      = CM_BASE + 44;
  CM_GETDATALINK            = CM_BASE + 45;
  CM_CHILDKEY               = CM_BASE + 46;
  CM_DRAG                   = CM_BASE + 47;
  CM_HINTSHOW               = CM_BASE + 48;
  CM_DIALOGHANDLE           = CM_BASE + 49;
  CM_ISTOOLCONTROL          = CM_BASE + 50;
  CM_RECREATEWND            = CM_BASE + 51;
  CM_INVALIDATE             = CM_BASE + 52;
  CM_SYSFONTCHANGED         = CM_BASE + 53;
  CM_CONTROLCHANGE          = CM_BASE + 54;
  CM_CHANGED                = CM_BASE + 55;
  CM_DOCKCLIENT             = CM_BASE + 56;
  CM_UNDOCKCLIENT           = CM_BASE + 57;
  CM_FLOAT                  = CM_BASE + 58;
  CM_BORDERCHANGED          = CM_BASE + 59;
  CM_BIDIMODECHANGED        = CM_BASE + 60;
  CM_PARENTBIDIMODECHANGED  = CM_BASE + 61;
  CM_ALLCHILDRENFLIPPED     = CM_BASE + 62;
  CM_ACTIONUPDATE           = CM_BASE + 63;
  CM_ACTIONEXECUTE          = CM_BASE + 64;
  CM_HINTSHOWPAUSE          = CM_BASE + 65;
  CM_DOCKNOTIFICATION       = CM_BASE + 66;
  CM_MOUSEWHEEL             = CM_BASE + 67;

{ VCL control notification IDs }

const
  CN_BASE              = $BC00;
  CN_CHARTOITEM        = CN_BASE + WM_CHARTOITEM;
  CN_COMMAND           = CN_BASE + WM_COMMAND;
  CN_COMPAREITEM       = CN_BASE + WM_COMPAREITEM;
  CN_CTLCOLORBTN       = CN_BASE + WM_CTLCOLORBTN;
  CN_CTLCOLORDLG       = CN_BASE + WM_CTLCOLORDLG;
  CN_CTLCOLOREDIT      = CN_BASE + WM_CTLCOLOREDIT;
  CN_CTLCOLORLISTBOX   = CN_BASE + WM_CTLCOLORLISTBOX;
  CN_CTLCOLORMSGBOX    = CN_BASE + WM_CTLCOLORMSGBOX;
  CN_CTLCOLORSCROLLBAR = CN_BASE + WM_CTLCOLORSCROLLBAR;
  CN_CTLCOLORSTATIC    = CN_BASE + WM_CTLCOLORSTATIC;
  CN_DELETEITEM        = CN_BASE + WM_DELETEITEM;
  CN_DRAWITEM          = CN_BASE + WM_DRAWITEM;
  CN_HSCROLL           = CN_BASE + WM_HSCROLL;
  CN_MEASUREITEM       = CN_BASE + WM_MEASUREITEM;
  CN_PARENTNOTIFY      = CN_BASE + WM_PARENTNOTIFY;
  CN_VKEYTOITEM        = CN_BASE + WM_VKEYTOITEM;
  CN_VSCROLL           = CN_BASE + WM_VSCROLL;
  CN_KEYDOWN           = CN_BASE + WM_KEYDOWN;
  CN_KEYUP             = CN_BASE + WM_KEYUP;
  CN_CHAR              = CN_BASE + WM_CHAR;
  CN_SYSKEYDOWN        = CN_BASE + WM_SYSKEYDOWN;
  CN_SYSCHAR           = CN_BASE + WM_SYSCHAR;
  CN_NOTIFY            = CN_BASE + WM_NOTIFY;

{ TModalResult values }

const
  mrNone     = 0;
  mrOk       = idOk;
  mrCancel   = idCancel;
  mrAbort    = idAbort;
  mrRetry    = idRetry;
  mrIgnore   = idIgnore;
  mrYes      = idYes;
  mrNo       = idNo;
  mrAll      = mrNo + 1;
  mrNoToAll  = mrAll + 1;
  mrYesToAll = mrNoToAll + 1;

{ Cursor identifiers }

type
  TCursor = -32768..32767;
  {$NODEFINE TCursor}

  (*$HPPEMIT 'namespace Controls'}*)
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

type

{ Forward declarations }

  TDragObject = class;
  TControl = class;
  TWinControl = class;
  TDragImageList = class;

  TWinControlClass = class of TWinControl;

{ VCL control message records }

  TCMActivate = TWMNoParams;
  TCMDeactivate = TWMNoParams;
  TCMGotFocus = TWMNoParams;
  TCMLostFocus = TWMNoParams;
  TCMDialogKey = TWMKey;
  TCMDialogChar = TWMKey;
  TCMHitTest = TWMNCHitTest;
  TCMEnter = TWMNoParams;
  TCMExit = TWMNoParams;
  TCMDesignHitTest = TWMMouse;
  TCMWantSpecialKey = TWMKey;

  TCMMouseWheel = record
    Msg: Cardinal;
    ShiftState: TShiftState;
    Unused: Byte;
    WheelDelta: SmallInt;
    case Integer of
      0: (
        XPos: Smallint;
        YPos: Smallint);
      1: (
        Pos: TSmallPoint;
        Result: Longint);
  end;

  TCMCancelMode = record
    Msg: Cardinal;
    Unused: Integer;
    Sender: TControl;
    Result: Longint;
  end;

  TCMFocusChanged = record
    Msg: Cardinal;
    Unused: Integer;
    Sender: TWinControl;
    Result: Longint;
  end;

  TCMControlListChange = record
    Msg: Cardinal;
    Control: TControl;
    Inserting: LongBool;
    Result: Longint;
  end;

  TCMChildKey = record
    Msg: Cardinal;
    CharCode: Word;
    Unused: Word;
    Sender: TWinControl;
    Result: Longint;
  end;

  TCMControlChange = record
    Msg: Cardinal;
    Control: TControl;
    Inserting: LongBool;
    Result: Longint;
  end;

  TCMChanged = record
    Msg: Cardinal;
    Unused: Longint;
    Child: TControl;
    Result: Longint;
  end;

  TDragMessage = (dmDragEnter, dmDragLeave, dmDragMove, dmDragDrop, dmDragCancel,
    dmFindTarget);

  PDragRec = ^TDragRec;
  TDragRec = record
    Pos: TPoint;
    Source: TDragObject;
    Target: Pointer;
    Docking: Boolean;
  end;

  TCMDrag = packed record
    Msg: Cardinal;
    DragMessage: TDragMessage;
    Reserved1: Byte;
    Reserved2: Word;
    DragRec: PDragRec;
    Result: Longint;
  end;

  TDragDockObject = class;

  TCMDockClient = packed record
    Msg: Cardinal;
    DockSource: TDragDockObject;
    MousePos: TSmallPoint;
    Result: Integer;
  end;

  TCMUnDockClient = packed record
    Msg: Cardinal;
    NewTarget: TControl;
    Client: TControl;
    Result: Integer;
  end;

  TCMFloat = packed record
    Msg: Cardinal;
    Reserved: Integer;
    DockSource: TDragDockObject;
    Result: Integer;
  end;

  PDockNotifyRec = ^TDockNotifyRec;
  TDockNotifyRec = record
    ClientMsg: Cardinal;
    MsgWParam: Integer;
    MsgLParam: Integer;
  end;

  TCMDockNotification = packed record
    Msg: Cardinal;
    Client: TControl;
    NotifyRec: PDockNotifyRec;
    Result: Integer;
  end;

  TAlign = (alNone, alTop, alBottom, alLeft, alRight, alClient);

  TAlignSet = set of TAlign;

{ Dragging objects }

  TDragObject = class(TObject)
  private
    FDragTarget: Pointer;
    FDragHandle: HWND;
    FDragPos: TPoint;
    FDragTargetPos: TPoint;
    FMouseDeltaX: Double;
    FMouseDeltaY: Double;
    FCancelling: Boolean;
    function Capture: HWND;
    procedure MouseMsg(var Msg: TMessage);
    procedure ReleaseCapture(Handle: HWND);
  protected
    procedure Finished(Target: TObject; X, Y: Integer; Accepted: Boolean); virtual;
    function GetDragCursor(Accepted: Boolean; X, Y: Integer): TCursor; virtual;
    function GetDragImages: TDragImageList; virtual;
  public
    procedure Assign(Source: TDragObject); virtual;
    function GetName: string; virtual;
    procedure HideDragImage; virtual;
    function Instance: THandle; virtual;
    procedure ShowDragImage; virtual;
    property Cancelling: Boolean read FCancelling write FCancelling;
    property DragHandle: HWND read FDragHandle write FDragHandle;
    property DragPos: TPoint read FDragPos write FDragPos;
    property DragTargetPos: TPoint read FDragTargetPos write FDragTargetPos;
    property DragTarget: Pointer read FDragTarget write FDragTarget;
    property MouseDeltaX: Double read FMouseDeltaX;
    property MouseDeltaY: Double read FMouseDeltaX;
  end;

  TBaseDragControlObject = class(TDragObject)
  private
    FControl: TControl;
  protected
    procedure EndDrag(Target: TObject; X, Y: Integer); virtual;
    procedure Finished(Target: TObject; X, Y: Integer; Accepted: Boolean); override;
  public
    constructor Create(AControl: TControl); virtual;
    procedure Assign(Source: TDragObject); override;
    property Control: TControl read FControl write FControl;
  end;

  TDragControlObject = class(TBaseDragControlObject)
  protected
    function GetDragCursor(Accepted: Boolean; X, Y: Integer): TCursor; override;
    function GetDragImages: TDragImageList; override;
  public
    procedure HideDragImage; override;
    procedure ShowDragImage; override;
  end;

  TDragDockObject = class(TBaseDragControlObject)
  private
    FBrush: TBrush;
    FDockRect: TRect;
    FDropAlign: TAlign;
    FDropOnControl: TControl;
    FEraseDockRect: TRect;
    FFloating: Boolean;
    procedure SetBrush(Value: TBrush);
  protected
    procedure AdjustDockRect(ARect: TRect); virtual;
    procedure DrawDragDockImage; virtual;
    procedure EndDrag(Target: TObject; X, Y: Integer); override;
    procedure EraseDragDockImage; virtual;
    function GetDragCursor(Accepted: Boolean; X, Y: Integer): TCursor; override;
    function GetFrameWidth: Integer; virtual;
  public
    constructor Create(AControl: TControl); override;
    destructor Destroy; override;
    procedure Assign(Source: TDragObject); override;
    property Brush: TBrush read FBrush write SetBrush;
    property DockRect: TRect read FDockRect write FDockRect;
    property DropAlign: TAlign read FDropAlign;
    property DropOnControl: TControl read FDropOnControl;
    property Floating: Boolean read FFloating write FFloating;
    property FrameWidth: Integer read GetFrameWidth;
  end;

{ Controls }

  TControlCanvas = class(TCanvas)
  private
    FControl: TControl;
    FDeviceContext: HDC;
    FWindowHandle: HWnd;
    procedure SetControl(AControl: TControl);
  protected
    procedure CreateHandle; override;
  public
    destructor Destroy; override;
    procedure FreeHandle;
    procedure UpdateTextFlags;
    property Control: TControl read FControl write SetControl;
  end;

{ TControlActionLink }

  TControlActionLink = class(TActionLink)
  protected
    FClient: TControl;
    procedure AssignClient(AClient: TObject); override;
    function IsCaptionLinked: Boolean; override;
    function IsEnabledLinked: Boolean; override;
    function IsHintLinked: Boolean; override;
    function IsVisibleLinked: Boolean; override;
    function IsOnExecuteLinked: Boolean; override;
    function DoShowHint(var HintStr: string): Boolean; virtual;
    procedure SetCaption(const Value: string); override;
    procedure SetEnabled(Value: Boolean); override;
    procedure SetHint(const Value: string); override;
    procedure SetVisible(Value: Boolean); override;
    procedure SetOnExecute(Value: TNotifyEvent); override;
  end;

  TControlActionLinkClass = class of TControlActionLink;

{ TControl }

  TControlState = set of (csLButtonDown, csClicked, csPalette,
    csReadingState, csAlignmentNeeded, csFocusing, csCreating,
    csPaintCopy, csCustomPaint, csDestroyingHandle, csDocking);

  TControlStyle = set of (csAcceptsControls, csCaptureMouse,
    csDesignInteractive, csClickEvents, csFramed, csSetCaption, csOpaque,
    csDoubleClicks, csFixedWidth, csFixedHeight, csNoDesignVisible,
    csReplicatable, csNoStdEvents, csDisplayDragImage, csReflector,
    csActionClient, csMenuEvents);

  TMouseButton = (mbLeft, mbRight, mbMiddle);

  TDragMode = (dmManual, dmAutomatic);

  TDragState = (dsDragEnter, dsDragLeave, dsDragMove);

  TDragKind = (dkDrag, dkDock);

  TTabOrder = -1..32767;

  TCaption = type string;

  TDate = type TDateTime;

  TTime = type TDateTime;
  {$EXTERNALSYM TDate}
  {$EXTERNALSYM TTime}
  (*$HPPEMIT 'namespace Controls'*)
  (*$HPPEMIT '{'*)
  (*$HPPEMIT '    typedef System::TDateTime TDate;'*)
  (*$HPPEMIT '    typedef System::TDateTime TTime;'*)
  (*$HPPEMIT '}'*)


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

  TMouseEvent = procedure(Sender: TObject; Button: TMouseButton;
    Shift: TShiftState; X, Y: Integer) of object;
  TMouseMoveEvent = procedure(Sender: TObject; Shift: TShiftState;
    X, Y: Integer) of object;
  TKeyEvent = procedure(Sender: TObject; var Key: Word;
    Shift: TShiftState) of object;
  TKeyPressEvent = procedure(Sender: TObject; var Key: Char) of object;
  TDragOverEvent = procedure(Sender, Source: TObject; X, Y: Integer;
    State: TDragState; var Accept: Boolean) of object;
  TDragDropEvent = procedure(Sender, Source: TObject;
    X, Y: Integer) of object;
  TStartDragEvent = procedure(Sender: TObject;
    var DragObject: TDragObject) of object;
  TEndDragEvent = procedure(Sender, Target: TObject;
    X, Y: Integer) of object;
  TDockDropEvent = procedure(Sender: TObject; Source: TDragDockObject;
    X, Y: Integer) of object;
  TDockOverEvent = procedure(Sender: TObject; Source: TDragDockObject;
    X, Y: Integer; State: TDragState; var Accept: Boolean) of object;
  TUnDockEvent = procedure(Sender: TObject; Client: TControl;
    NewTarget: TWinControl; var Allow: Boolean) of object;
  TStartDockEvent = procedure(Sender: TObject;
    var DragObject: TDragDockObject) of object;
  TGetSiteInfoEvent = procedure(Sender: TObject; DockClient: TControl;
    var InfluenceRect: TRect; MousePos: TPoint; var CanDock: Boolean) of object;
  TCanResizeEvent = procedure(Sender: TObject; var NewWidth, NewHeight: Integer;
    var Resize: Boolean) of object;
  TConstrainedResizeEvent = procedure(Sender: TObject; var MinWidth, MinHeight,
    MaxWidth, MaxHeight: Integer) of object;
  TMouseWheelEvent = procedure(Sender: TObject; Shift: TShiftState;
    WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean) of object;
  TMouseWheelUpDownEvent = procedure(Sender: TObject; Shift: TShiftState;
    MousePos: TPoint; var Handled: Boolean) of object;
  TContextPopupEvent = procedure(Sender: TObject; MousePos: TPoint; var Handled: Boolean) of object;

  TWndMethod = procedure(var Message: TMessage) of object;

  // TDockOrientation indicates how a zone's child zones are arranged.
  // doNoOrient means a zone contains a TControl and not child zones.
  // doHorizontal means a zone's children are stacked top-to-bottom.
  // doVertical means a zone's children are arranged left-to-right.
  TDockOrientation = (doNoOrient, doHorizontal, doVertical);

  TControl = class(TComponent)
  private
    FParent: TWinControl;
    FWindowProc: TWndMethod;
    FLeft: Integer;
    FTop: Integer;
    FWidth: Integer;
    FHeight: Integer;
    FControlStyle: TControlStyle;
    FControlState: TControlState;
    FDesktopFont: Boolean;
    FVisible: Boolean;
    FEnabled: Boolean;
    FParentFont: Boolean;
    FParentColor: Boolean;
    FAlign: TAlign;
    FAutoSize: Boolean;
    FDragMode: TDragMode;
    FIsControl: Boolean;
    FBiDiMode: TBiDiMode;
    FParentBiDiMode: Boolean;
    FAnchors: TAnchors;
    FAnchorMove: Boolean;
    FText: PChar;
    FFont: TFont;
    FActionLink: TControlActionLink;
    FColor: TColor;
    FConstraints: TSizeConstraints;
    FCursor: TCursor;
    FDragCursor: TCursor;
    FPopupMenu: TPopupMenu;
    FHint: string;
    FFontHeight: Integer;
    FAnchorRules: TPoint;
    FOriginalParentSize: TPoint;
    FScalingFlags: TScalingFlags;
    FShowHint: Boolean;
    FParentShowHint: Boolean;
    FDragKind: TDragKind;
    FDockOrientation: TDockOrientation;
    FHostDockSite: TWinControl;
    FUndockWidth: Integer;
    FUndockHeight: Integer;
    FLRDockWidth: Integer;
    FTBDockHeight: Integer;
    FFloatingDockSiteClass: TWinControlClass;
    FOnCanResize: TCanResizeEvent;
    FOnConstrainedResize: TConstrainedResizeEvent;
    FOnMouseDown: TMouseEvent;
    FOnMouseMove: TMouseMoveEvent;
    FOnMouseUp: TMouseEvent;
    FOnDragDrop: TDragDropEvent;
    FOnDragOver: TDragOverEvent;
    FOnResize: TNotifyEvent;
    FOnStartDock: TStartDockEvent;
    FOnEndDock: TEndDragEvent;
    FOnStartDrag: TStartDragEvent;
    FOnEndDrag: TEndDragEvent;
    FOnClick: TNotifyEvent;
    FOnDblClick: TNotifyEvent;
    FOnContextPopup: TContextPopupEvent;
    procedure CalcDockSizes;
    function CheckNewSize(var NewWidth, NewHeight: Integer): Boolean;
    function CreateFloatingDockSite(Bounds: TRect): TWinControl;
    procedure DoActionChange(Sender: TObject);
    function DoCanAutoSize(var NewWidth, NewHeight: Integer): Boolean;
    function DoCanResize(var NewWidth, NewHeight: Integer): Boolean;
    procedure DoConstraintsChange(Sender: TObject);
    procedure DoConstrainedResize(var NewWidth, NewHeight: Integer);
    procedure DoDragMsg(var DragMsg: TCMDrag);
    procedure DoMouseDown(var Message: TWMMouse; Button: TMouseButton;
      Shift: TShiftState);
    procedure DoMouseUp(var Message: TWMMouse; Button: TMouseButton);
    procedure FontChanged(Sender: TObject);
    function GetAction: TBasicAction;
    function GetBoundsRect: TRect;
    function GetClientHeight: Integer;
    function GetClientWidth: Integer;
    function GetLRDockWidth: Integer;
    function GetMouseCapture: Boolean;
    function GetText: TCaption;
    function GetTBDockHeight: Integer;
    function GetUndockWidth: Integer;
    function GetUndockHeight: Integer;
    procedure InvalidateControl(IsVisible, IsOpaque: Boolean);
    function IsAnchorsStored: Boolean;
    function IsBiDiModeStored: Boolean;
    function IsCaptionStored: Boolean;
    function IsColorStored: Boolean;
    function IsEnabledStored: Boolean;
    function IsFontStored: Boolean;
    function IsHintStored: Boolean;
    function IsOnClickStored: Boolean;
    function IsShowHintStored: Boolean;
    function IsVisibleStored: Boolean;
    procedure ReadIsControl(Reader: TReader);
    procedure SetAnchors(Value: TAnchors);
    procedure SetAction(Value: TBasicAction);
    procedure SetAlign(Value: TAlign);
    procedure SetAutoSize(Value: Boolean);
    procedure SetBoundsRect(const Rect: TRect);
    procedure SetClientHeight(Value: Integer);
    procedure SetClientSize(Value: TPoint);
    procedure SetClientWidth(Value: Integer);
    procedure SetColor(Value: TColor);
    procedure SetCursor(Value: TCursor);
    procedure SetDesktopFont(Value: Boolean);
    procedure SetFont(Value: TFont);
    procedure SetHeight(Value: Integer);
    procedure SetHostDockSite(Value: TWinControl);
    procedure SetLeft(Value: Integer);
    procedure SetMouseCapture(Value: Boolean);
    procedure SetParentColor(Value: Boolean);
    procedure SetParentFont(Value: Boolean);
    procedure SetShowHint(Value: Boolean);
    procedure SetParentShowHint(Value: Boolean);
    procedure SetPopupMenu(Value: TPopupMenu);
    procedure SetText(const Value: TCaption);
    procedure SetTop(Value: Integer);
    procedure SetVisible(Value: Boolean);
    procedure SetWidth(Value: Integer);
    procedure SetZOrderPosition(Position: Integer);
    procedure UpdateAnchorRules;
    procedure WriteIsControl(Writer: TWriter);
    procedure WMLButtonDown(var Message: TWMLButtonDown); message WM_LBUTTONDOWN;
    procedure WMNCLButtonDown(var Message: TWMNCLButtonDown); message WM_NCLBUTTONDOWN;
    procedure WMRButtonDown(var Message: TWMRButtonDown); message WM_RBUTTONDOWN;
    procedure WMMButtonDown(var Message: TWMMButtonDown); message WM_MBUTTONDOWN;
    procedure WMLButtonDblClk(var Message: TWMLButtonDblClk); message WM_LBUTTONDBLCLK;
    procedure WMRButtonDblClk(var Message: TWMRButtonDblClk); message WM_RBUTTONDBLCLK;
    procedure WMMButtonDblClk(var Message: TWMMButtonDblClk); message WM_MBUTTONDBLCLK;
    procedure WMMouseMove(var Message: TWMMouseMove); message WM_MOUSEMOVE;
    procedure WMLButtonUp(var Message: TWMLButtonUp); message WM_LBUTTONUP;
    procedure WMRButtonUp(var Message: TWMRButtonUp); message WM_RBUTTONUP;
    procedure WMMButtonUp(var Message: TWMMButtonUp); message WM_MBUTTONUP;
    procedure WMCancelMode(var Message: TWMCancelMode); message WM_CANCELMODE;
    procedure WMWindowPosChanged(var Message: TWMWindowPosChanged); message WM_WINDOWPOSCHANGED;
    procedure CMVisibleChanged(var Message: TMessage); message CM_VISIBLECHANGED;
    procedure CMEnabledChanged(var Message: TMessage); message CM_ENABLEDCHANGED;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure CMColorChanged(var Message: TMessage); message CM_COLORCHANGED;
    procedure CMParentFontChanged(var Message: TMessage); message CM_PARENTFONTCHANGED;
    procedure CMSysFontChanged(var Message: TMessage); message CM_SYSFONTCHANGED;
    procedure CMParentColorChanged(var Message: TMessage); message CM_PARENTCOLORCHANGED;
    procedure CMParentShowHintChanged(var Message: TMessage); message CM_PARENTSHOWHINTCHANGED;
    procedure CMHintShow(var Message: TMessage); message CM_HINTSHOW;
    procedure CMHitTest(var Message: TCMHitTest); message CM_HITTEST;
    procedure CMMouseEnter(var Message: TMessage); message CM_MOUSEENTER;
    procedure CMMouseLeave(var Message: TMessage); message CM_MOUSELEAVE;
    procedure CMDesignHitTest(var Message: TCMDesignHitTest); message CM_DESIGNHITTEST;
    procedure CMFloat(var Message: TCMFloat); message CM_FLOAT;
    procedure CMBiDiModeChanged(var Message: TMessage); message CM_BIDIMODECHANGED;
    procedure CMParentBiDiModeChanged(var Message: TMessage); message CM_PARENTBIDIMODECHANGED;
    procedure WMContextMenu(var Message: TWMContextMenu); message WM_CONTEXTMENU;
  protected
    procedure ActionChange(Sender: TObject; CheckDefaults: Boolean); dynamic;
    procedure AdjustSize; dynamic;
    procedure AssignTo(Dest: TPersistent); override;
    procedure BeginAutoDrag; dynamic;
    function CanResize(var NewWidth, NewHeight: Integer): Boolean; virtual;
    function CanAutoSize(var NewWidth, NewHeight: Integer): Boolean; virtual;
    procedure Changed;
    procedure ChangeScale(M, D: Integer); dynamic;
    procedure Click; dynamic;
    procedure ConstrainedResize(var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer); virtual;
    procedure DblClick; dynamic;
    procedure DefaultDockImage(DragDockObject: TDragDockObject; Erase: Boolean); dynamic;
    procedure DefineProperties(Filer: TFiler); override;
    procedure DockTrackNoTarget(Source: TDragDockObject; X, Y: Integer); dynamic;
    procedure DoContextPopup(MousePos: TPoint; var Handled: Boolean); dynamic;
    procedure DoEndDock(Target: TObject; X, Y: Integer); dynamic;
    procedure DoDock(NewDockSite: TWinControl; var ARect: TRect); dynamic;
    procedure DoStartDock(var DragObject: TDragObject); dynamic;
    procedure DragCanceled; dynamic;
    procedure DragOver(Source: TObject; X, Y: Integer; State: TDragState;
      var Accept: Boolean); dynamic;
    procedure DoEndDrag(Target: TObject; X, Y: Integer); dynamic;
    procedure DoStartDrag(var DragObject: TDragObject); dynamic;
    procedure DrawDragDockImage(DragDockObject: TDragDockObject); dynamic;
    procedure EraseDragDockImage(DragDockObject: TDragDockObject); dynamic;
    function GetActionLinkClass: TControlActionLinkClass; dynamic;
    function GetClientOrigin: TPoint; virtual;
    function GetClientRect: TRect; virtual;
    function GetDeviceContext(var WindowHandle: HWnd): HDC; virtual;
    function GetDockEdge(MousePos: TPoint): TAlign; dynamic;
    function GetDragImages: TDragImageList; virtual;
    function GetEnabled: Boolean; virtual;
    function GetFloating: Boolean; virtual;
    function GetFloatingDockSiteClass: TWinControlClass; virtual;
    function GetPalette: HPALETTE; dynamic;
    function GetPopupMenu: TPopupMenu; dynamic;
    procedure Loaded; override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); dynamic;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); dynamic;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); dynamic;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure PositionDockRect(DragDockObject: TDragDockObject); dynamic;
    function PaletteChanged(Foreground: Boolean): Boolean; dynamic;
    procedure ReadState(Reader: TReader); override;
    procedure RequestAlign; dynamic;
    procedure Resize; dynamic;
    procedure SendCancelMode(Sender: TControl);
    procedure SendDockNotification(Msg: Cardinal; WParam, LParam: Integer);
    procedure SetDragMode(Value: TDragMode); virtual;
    procedure SetEnabled(Value: Boolean); virtual;
    procedure SetName(const Value: TComponentName); override;
    procedure SetParent(AParent: TWinControl); virtual;
    procedure SetParentComponent(Value: TComponent); override;
    procedure SetParentBiDiMode(Value: Boolean); virtual;
    procedure SetBiDiMode(Value: TBiDiMode); virtual;
    procedure SetZOrder(TopMost: Boolean); dynamic;
    procedure UpdateBoundsRect(const R: TRect);
    procedure VisibleChanging; dynamic;
    procedure WndProc(var Message: TMessage); virtual;
    property ActionLink: TControlActionLink read FActionLink write FActionLink;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default False;
    property Caption: TCaption read GetText write SetText stored IsCaptionStored;
    property Color: TColor read FColor write SetColor stored IsColorStored default clWindow;
    property DesktopFont: Boolean read FDesktopFont write SetDesktopFont default False;
    property DragKind: TDragKind read FDragKind write FDragKind default dkDrag;
    property DragCursor: TCursor read FDragCursor write FDragCursor default crDrag;
    property DragMode: TDragMode read FDragMode write SetDragMode default dmManual;
    property Font: TFont read FFont write SetFont stored IsFontStored;
    property IsControl: Boolean read FIsControl write FIsControl;
    property MouseCapture: Boolean read GetMouseCapture write SetMouseCapture;
    property ParentBiDiMode: Boolean read FParentBiDiMode write SetParentBiDiMode default True;
    property ParentColor: Boolean read FParentColor write SetParentColor default True;
    property ParentFont: Boolean read FParentFont write SetParentFont default True;
    property ParentShowHint: Boolean read FParentShowHint write SetParentShowHint default True;
    property PopupMenu: TPopupMenu read FPopupMenu write SetPopupMenu;
    property ScalingFlags: TScalingFlags read FScalingFlags write FScalingFlags;
    property Text: TCaption read GetText write SetText;
    property WindowText: PChar read FText write FText;
    property OnCanResize: TCanResizeEvent read FOnCanResize write FOnCanResize;
    property OnClick: TNotifyEvent read FOnClick write FOnClick stored IsOnClickStored;
    property OnConstrainedResize: TConstrainedResizeEvent read FOnConstrainedResize write FOnConstrainedResize;
    property OnContextPopup: TContextPopupEvent read FOnContextPopup write FOnContextPopup;
    property OnDblClick: TNotifyEvent read FOnDblClick write FOnDblClick;
    property OnDragDrop: TDragDropEvent read FOnDragDrop write FOnDragDrop;
    property OnDragOver: TDragOverEvent read FOnDragOver write FOnDragOver;
    property OnEndDock: TEndDragEvent read FOnEndDock write FOnEndDock;
    property OnEndDrag: TEndDragEvent read FOnEndDrag write FOnEndDrag;
    property OnMouseDown: TMouseEvent read FOnMouseDown write FOnMouseDown;
    property OnMouseMove: TMouseMoveEvent read FOnMouseMove write FOnMouseMove;
    property OnMouseUp: TMouseEvent read FOnMouseUp write FOnMouseUp;
    property OnResize: TNotifyEvent read FOnResize write FOnResize;
    property OnStartDock: TStartDockEvent read FOnStartDock write FOnStartDock;
    property OnStartDrag: TStartDragEvent read FOnStartDrag write FOnStartDrag;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure BeginDrag(Immediate: Boolean; Threshold: Integer = -1);
    procedure BringToFront;
    function ClientToScreen(const Point: TPoint): TPoint;
    procedure Dock(NewDockSite: TWinControl; ARect: TRect); dynamic;
    procedure DefaultHandler(var Message); override;
    function Dragging: Boolean;
    procedure DragDrop(Source: TObject; X, Y: Integer); dynamic;
    function DrawTextBiDiModeFlags(Flags: Longint): Longint;
    function DrawTextBiDiModeFlagsReadingOnly: Longint;
    property Enabled: Boolean read GetEnabled write SetEnabled stored IsEnabledStored default True;
    procedure EndDrag(Drop: Boolean);
    function GetControlsAlignment: TAlignment; dynamic;
    function GetParentComponent: TComponent; override;
    function GetTextBuf(Buffer: PChar; BufSize: Integer): Integer;
    function GetTextLen: Integer;
    function HasParent: Boolean; override;
    procedure Hide;
    procedure InitiateAction; virtual;
    procedure Invalidate; virtual;
    function IsRightToLeft: Boolean;
    function ManualDock(NewDockSite: TWinControl; DropControl: TControl = nil;
      ControlSide: TAlign = alNone): Boolean;
    function ManualFloat(ScreenPos: TRect): Boolean;
    function Perform(Msg: Cardinal; WParam, LParam: Longint): Longint;
    procedure Refresh;
    procedure Repaint; virtual;
    function ReplaceDockedControl(Control: TControl; NewDockSite: TWinControl;
      DropControl: TControl; ControlSide: TAlign): Boolean;
    function ScreenToClient(const Point: TPoint): TPoint;
    procedure SendToBack;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); virtual;
    procedure SetTextBuf(Buffer: PChar);
    procedure Show;
    procedure Update; virtual;
    function UseRightToLeftAlignment: Boolean; dynamic;
    function UseRightToLeftReading: Boolean;
    function UseRightToLeftScrollBar: Boolean;
    property Action: TBasicAction read GetAction write SetAction;
    property Align: TAlign read FAlign write SetAlign default alNone;
    property Anchors: TAnchors read FAnchors write SetAnchors stored IsAnchorsStored default [akLeft, akTop];
    property BiDiMode: TBiDiMode read FBiDiMode write SetBiDiMode stored IsBiDiModeStored;
    property BoundsRect: TRect read GetBoundsRect write SetBoundsRect;
    property ClientHeight: Integer read GetClientHeight write SetClientHeight stored False;
    property ClientOrigin: TPoint read GetClientOrigin;
    property ClientRect: TRect read GetClientRect;
    property ClientWidth: Integer read GetClientWidth write SetClientWidth stored False;
    property Constraints: TSizeConstraints read FConstraints write FConstraints;
    property ControlState: TControlState read FControlState write FControlState;
    property ControlStyle: TControlStyle read FControlStyle write FControlStyle;
    property DockOrientation: TDockOrientation read FDockOrientation write FDockOrientation;
    property Floating: Boolean read GetFloating;
    property FloatingDockSiteClass: TWinControlClass read GetFloatingDockSiteClass write FFloatingDockSiteClass;
    property HostDockSite: TWinControl read FHostDockSite write SetHostDockSite;
    property LRDockWidth: Integer read GetLRDockWidth write FLRDockWidth;
    property Parent: TWinControl read FParent write SetParent;
    property ShowHint: Boolean read FShowHint write SetShowHint stored IsShowHintStored;
    property TBDockHeight: Integer read GetTBDockHeight write FTBDockHeight;
    property UndockHeight: Integer read GetUndockHeight write FUndockHeight;
    property UndockWidth: Integer read GetUndockWidth write FUndockWidth;
    property Visible: Boolean read FVisible write SetVisible stored IsVisibleStored default True;
    property WindowProc: TWndMethod read FWindowProc write FWindowProc;
  published
    property Left: Integer read FLeft write SetLeft;
    property Top: Integer read FTop write SetTop;
    property Width: Integer read FWidth write SetWidth;
    property Height: Integer read FHeight write SetHeight;
    property Cursor: TCursor read FCursor write SetCursor default crDefault;
    property Hint: string read FHint write FHint stored IsHintStored;
  end;

  TControlClass = class of TControl;

  TCreateParams = record
    Caption: PChar;
    Style: DWORD;
    ExStyle: DWORD;
    X, Y: Integer;
    Width, Height: Integer;
    WndParent: HWnd;
    Param: Pointer;
    WindowClass: TWndClass;
    WinClassName: array[0..63] of Char;
  end;

{ TWinControlActionLink }

  TWinControlActionLink = class(TControlActionLink)
  protected
    FClient: TWinControl;
    procedure AssignClient(AClient: TObject); override;
    function IsHelpContextLinked: Boolean; override;
    procedure SetHelpContext(Value: THelpContext); override;
  end;

  TWinControlActionLinkClass = class of TWinControlActionLink;

{ TWinControl }

  TImeMode = (imDisable, imClose, imOpen, imDontCare,
              imSAlpha, imAlpha, imHira, imSKata, imKata,
              imChinese, imSHanguel, imHanguel);
  TImeName = type string;

  TBorderWidth = 0..MaxInt;

  TBevelCut = (bvNone, bvLowered, bvRaised, bvSpace);
  TBevelEdge = (beLeft, beTop, beRight, beBottom);
  TBevelEdges = set of TBevelEdge;
  TBevelKind = (bkNone, bkTile, bkSoft, bkFlat);
  TBevelWidth = 1..MaxInt;

  // IDockManager defines an interface for managing a dock site's docked
  // controls. The default VCL implementation of IDockManager is TDockTree.
  IDockManager = interface
    ['{8619FD79-C281-11D1-AA60-00C04FA370E8}']
    procedure BeginUpdate;
    procedure EndUpdate;
    procedure GetControlBounds(Control: TControl; out CtlBounds: TRect);
    procedure InsertControl(Control: TControl; InsertAt: TAlign;
      DropCtl: TControl);
    procedure LoadFromStream(Stream: TStream);
    procedure PaintSite(DC: HDC);
    procedure PositionDockRect(Client, DropCtl: TControl; DropAlign: TAlign;
      var DockRect: TRect);
    procedure RemoveControl(Control: TControl);
    procedure ResetBounds(Force: Boolean);
    procedure SaveToStream(Stream: TStream);
    procedure SetReplacingControl(Control: TControl);
  end;

  TWinControl = class(TControl)
  private
    FAlignLevel: Word;
    FBevelEdges: TBevelEdges;
    FBevelInner: TBevelCut;
    FBevelOuter: TBevelCut;
    FBevelKind: TBevelKind;
    FBevelWidth: TBevelWidth;
    FBorderWidth: TBorderWidth;
    FBrush: TBrush;
    FControls: TList;
    FCtl3D: Boolean;
    FDefWndProc: Pointer;
    FDockClients: TList;
    FDockSite: Boolean;
    FDockManager: IDockManager;
    FHandle: HWnd;
    FHelpContext: THelpContext;
    FImeMode: TImeMode;
    FImeName: TImeName;
    FObjectInstance: Pointer;
    FParentCtl3D: Boolean;
    FParentWindow: HWnd;
    FShowing: Boolean;
    FTabList: TList;
    FTabOrder: Integer;
    FTabStop: Boolean;
    FWheelAccumulator: Integer;
    FUseDockManager: Boolean;
    FWinControls: TList;
    FOnDockDrop: TDockDropEvent;
    FOnDockOver: TDockOverEvent;
    FOnEnter: TNotifyEvent;
    FOnExit: TNotifyEvent;
    FOnGetSiteInfo: TGetSiteInfoEvent;
    FOnKeyDown: TKeyEvent;
    FOnKeyPress: TKeyPressEvent;
    FOnKeyUp: TKeyEvent;
    FOnMouseWheel: TMouseWheelEvent;
    FOnMouseWheelDown: TMouseWheelUpDownEvent;
    FOnMouseWheelUp: TMouseWheelUpDownEvent;
    FOnUnDock: TUnDockEvent;
    procedure AlignControl(AControl: TControl);
    procedure CalcConstraints(var MinWidth, MinHeight, MaxWidth,
      MaxHeight: Integer);
    function GetControl(Index: Integer): TControl;
    function GetControlCount: Integer;
    function GetDockClientCount: Integer;
    function GetDockClients(Index: Integer): TControl;
    function GetHandle: HWnd;
    function GetTabOrder: TTabOrder;
    function GetVisibleDockClientCount: Integer;
    procedure Insert(AControl: TControl);
    procedure InvalidateFrame;
    function IsCtl3DStored: Boolean;
    function IsHelpContextStored: Boolean;
    function PrecedingWindow(Control: TWinControl): HWnd;
    procedure Remove(AControl: TControl);
    procedure RemoveFocus(Removing: Boolean);
    procedure SetBevelCut(Index: Integer; const Value: TBevelCut);
    procedure SetBevelEdges(const Value: TBevelEdges);
    procedure SetBevelKind(const Value: TBevelKind);
    procedure SetBevelWidth(const Value: TBevelWidth);
    procedure SetBorderWidth(Value: TBorderWidth);
    procedure SetCtl3D(Value: Boolean);
    procedure SetDockSite(Value: Boolean);
    procedure SetParentCtl3D(Value: Boolean);
    procedure SetParentWindow(Value: HWnd);
    procedure SetTabOrder(Value: TTabOrder);
    procedure SetTabStop(Value: Boolean);
    procedure SetUseDockManager(Value: Boolean);
    procedure SetZOrderPosition(Position: Integer);
    procedure UpdateTabOrder(Value: TTabOrder);
    procedure UpdateBounds;
    procedure UpdateShowing;
    function IsMenuKey(var Message: TWMKey): Boolean;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
    procedure WMCommand(var Message: TWMCommand); message WM_COMMAND;
    procedure WMNotify(var Message: TWMNotify); message WM_NOTIFY;
    procedure WMSysColorChange(var Message: TWMSysColorChange); message WM_SYSCOLORCHANGE;
    procedure WMHScroll(var Message: TWMHScroll); message WM_HSCROLL;
    procedure WMVScroll(var Message: TWMVScroll); message WM_VSCROLL;
    procedure WMCompareItem(var Message: TWMCompareItem); message WM_COMPAREITEM;
    procedure WMDeleteItem(var Message: TWMDeleteItem); message WM_DELETEITEM;
    procedure WMDrawItem(var Message: TWMDrawItem); message WM_DRAWITEM;
    procedure WMMeasureItem(var Message: TWMMeasureItem); message WM_MEASUREITEM;
    procedure WMEraseBkgnd(var Message: TWmEraseBkgnd); message WM_ERASEBKGND;
    procedure WMWindowPosChanged(var Message: TWMWindowPosChanged); message WM_WINDOWPOSCHANGED;
    procedure WMWindowPosChanging(var Message: TWMWindowPosChanging); message WM_WINDOWPOSCHANGING;
    procedure WMSize(var Message: TWMSize); message WM_SIZE;
    procedure WMMove(var Message: TWMMove); message WM_MOVE;
    procedure WMSetCursor(var Message: TWMSetCursor); message WM_SETCURSOR;
    procedure WMKeyDown(var Message: TWMKeyDown); message WM_KEYDOWN;
    procedure WMSysKeyDown(var Message: TWMKeyDown); message WM_SYSKEYDOWN;
    procedure WMKeyUp(var Message: TWMKeyUp); message WM_KEYUP;
    procedure WMSysKeyUp(var Message: TWMKeyUp); message WM_SYSKEYUP;
    procedure WMChar(var Message: TWMChar); message WM_CHAR;
    procedure WMSysCommand(var Message: TWMSysCommand); message WM_SYSCOMMAND;
    procedure WMCharToItem(var Message: TWMCharToItem); message WM_CHARTOITEM;
    procedure WMParentNotify(var Message: TWMParentNotify); message WM_PARENTNOTIFY;
    procedure WMVKeyToItem(var Message: TWMVKeyToItem); message WM_VKEYTOITEM;
    procedure WMDestroy(var Message: TWMDestroy); message WM_DESTROY;
    procedure WMNCCalcSize(var Message: TWMNCCalcSize); message WM_NCCALCSIZE;
    procedure WMNCDestroy(var Message: TWMNCDestroy); message WM_NCDESTROY;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
    procedure WMNCPaint(var Message: TMessage); message WM_NCPAINT;
    procedure WMQueryNewPalette(var Message: TMessage); message WM_QUERYNEWPALETTE;
    procedure WMPaletteChanged(var Message: TMessage); message WM_PALETTECHANGED;
    procedure WMWinIniChange(var Message: TMessage); message WM_WININICHANGE;
    procedure WMFontChange(var Message: TMessage); message WM_FONTCHANGE;
    procedure WMTimeChange(var Message: TMessage); message WM_TIMECHANGE;
    procedure WMSetFocus(var Message: TWMSetFocus); message WM_SETFOCUS;
    procedure WMKillFocus(var Message: TWMSetFocus); message WM_KILLFOCUS;
    procedure WMIMEStartComp(var Message: TMessage); message WM_IME_STARTCOMPOSITION;
    procedure WMIMEEndComp(var Message: TMessage); message WM_IME_ENDCOMPOSITION;
    procedure WMMouseWheel(var Message: TWMMouseWheel); message WM_MOUSEWHEEL;
    procedure WMContextMenu(var Message: TWMContextMenu); message WM_CONTEXTMENU;
    procedure CMChanged(var Message: TMessage); message CM_CHANGED;
    procedure CMChildKey(var Message: TMessage); message CM_CHILDKEY;
    procedure CMDialogKey(var Message: TCMDialogKey); message CM_DIALOGKEY;
    procedure CMDialogChar(var Message: TCMDialogChar); message CM_DIALOGCHAR;
    procedure CMFocusChanged(var Message: TCMFocusChanged); message CM_FOCUSCHANGED;
    procedure CMVisibleChanged(var Message: TMessage); message CM_VISIBLECHANGED;
    procedure CMEnabledChanged(var Message: TMessage); message CM_ENABLEDCHANGED;
    procedure CMColorChanged(var Message: TMessage); message CM_COLORCHANGED;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure CMBorderChanged(var Message: TMessage); message CM_BORDERCHANGED;
    procedure CMCursorChanged(var Message: TMessage); message CM_CURSORCHANGED;
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
    procedure CMParentCtl3DChanged(var Message: TMessage); message CM_PARENTCTL3DCHANGED;
    procedure CMShowingChanged(var Message: TMessage); message CM_SHOWINGCHANGED;
    procedure CMShowHintChanged(var Message: TMessage); message CM_SHOWHINTCHANGED;
    procedure CMEnter(var Message: TCMEnter); message CM_ENTER;
    procedure CMExit(var Message: TCMExit); message CM_EXIT;
    procedure CMDesignHitTest(var Message: TCMDesignHitTest); message CM_DESIGNHITTEST;
    procedure CMSysColorChange(var Message: TMessage); message CM_SYSCOLORCHANGE;
    procedure CMSysFontChanged(var Message: TMessage); message CM_SYSFONTCHANGED;
    procedure CMWinIniChange(var Message: TWMWinIniChange); message CM_WININICHANGE;
    procedure CMFontChange(var Message: TMessage); message CM_FONTCHANGE;
    procedure CMTimeChange(var Message: TMessage); message CM_TIMECHANGE;
    procedure CMDrag(var Message: TCMDrag); message CM_DRAG;
    procedure CNKeyDown(var Message: TWMKeyDown); message CN_KEYDOWN;
    procedure CNKeyUp(var Message: TWMKeyUp); message CN_KEYUP;
    procedure CNChar(var Message: TWMChar); message CN_CHAR;
    procedure CNSysKeyDown(var Message: TWMKeyDown); message CN_SYSKEYDOWN;
    procedure CNSysChar(var Message: TWMChar); message CN_SYSCHAR;
    procedure CMControlListChange(var Message: TMessage); message CM_CONTROLLISTCHANGE;
    procedure CMRecreateWnd(var Message: TMessage); message CM_RECREATEWND;
    procedure CMInvalidate(var Message: TMessage); message CM_INVALIDATE;
    procedure CMDockClient(var Message: TCMDockClient); message CM_DOCKCLIENT;
    procedure CMUnDockClient(var Message: TCMUnDockClient); message CM_UNDOCKCLIENT;
    procedure CMFloat(var Message: TCMFloat); message CM_FLOAT;
    procedure CMBiDiModeChanged(var Message: TMessage); message CM_BIDIMODECHANGED;
    procedure CMMouseWheel(var Message: TCMMouseWheel); message CM_MOUSEWHEEL;
  protected
    FDoubleBuffered: Boolean;
    FInImeComposition: Boolean;
    procedure ActionChange(Sender: TObject; CheckDefaults: Boolean); override;
    procedure AddBiDiModeExStyle(var ExStyle: DWORD);
    procedure AssignTo(Dest: TPersistent); override;
    procedure AdjustClientRect(var Rect: TRect); virtual;
    procedure AdjustSize; override;
    procedure AlignControls(AControl: TControl; var Rect: TRect); virtual;
    function CanAutoSize(var NewWidth, NewHeight: Integer): Boolean; override;
    function CanResize(var NewWidth, NewHeight: Integer): Boolean; override;
    procedure ChangeScale(M, D: Integer); override;
    procedure ConstrainedResize(var MinWidth, MinHeight, MaxWidth,
      MaxHeight: Integer); override;
    function CreateDockManager: IDockManager; dynamic;
    procedure CreateHandle; virtual;
    procedure CreateParams(var Params: TCreateParams); virtual;
    procedure CreateSubClass(var Params: TCreateParams;
      ControlClassName: PChar);
    procedure CreateWindowHandle(const Params: TCreateParams); virtual;
    procedure CreateWnd; virtual;
    procedure DestroyHandle;
    procedure DestroyWindowHandle; virtual;
    procedure DestroyWnd; virtual;
    procedure DoAddDockClient(Client: TControl; const ARect: TRect); dynamic;
    procedure DockOver(Source: TDragDockObject; X, Y: Integer; State: TDragState;
      var Accept: Boolean); dynamic;
    procedure DoDockOver(Source: TDragDockObject; X, Y: Integer; State: TDragState;
      var Accept: Boolean); dynamic;
    procedure DoEnter; dynamic;
    procedure DoExit; dynamic;
    procedure DoFlipChildren; dynamic;
    function DoKeyDown(var Message: TWMKey): Boolean;
    function DoKeyPress(var Message: TWMKey): Boolean;
    function DoKeyUp(var Message: TWMKey): Boolean;
    function DoMouseWheel(Shift: TShiftState; WheelDelta: Integer;
      MousePos: TPoint): Boolean; dynamic;
    function DoMouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean; dynamic;
    function DoMouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean; dynamic;
    procedure DoRemoveDockClient(Client: TControl); dynamic;
    function DoUnDock(NewTarget: TWinControl; Client: TControl): Boolean; dynamic;
    function FindNextControl(CurControl: TWinControl;
      GoForward, CheckTabStop, CheckParent: Boolean): TWinControl;
    procedure FixupTabList;
    function GetActionLinkClass: TControlActionLinkClass; override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    function GetClientOrigin: TPoint; override;
    function GetClientRect: TRect; override;
    function GetControlExtents: TRect; virtual;
    function GetDeviceContext(var WindowHandle: HWnd): HDC; override;
    function GetParentHandle: HWnd;
    procedure GetSiteInfo(Client: TControl; var InfluenceRect: TRect;
      MousePos: TPoint; var CanDock: Boolean); dynamic;
    function GetTopParentHandle: HWnd;
    function IsControlMouseMsg(var Message: TWMMouse): Boolean;
    procedure KeyDown(var Key: Word; Shift: TShiftState); dynamic;
    procedure KeyUp(var Key: Word; Shift: TShiftState); dynamic;
    procedure KeyPress(var Key: Char); dynamic;
    procedure MainWndProc(var Message: TMessage);
    procedure NotifyControls(Msg: Word);
    procedure PaintControls(DC: HDC; First: TControl);
    procedure PaintHandler(var Message: TWMPaint);
    procedure PaintWindow(DC: HDC); virtual;
    function PaletteChanged(Foreground: Boolean): Boolean; override;
    procedure ReadState(Reader: TReader); override;
    procedure RecreateWnd;
    procedure ReloadDockedControl(const AControlName: string;
      var AControl: TControl); dynamic;
    procedure ResetIme;
    function ResetImeComposition(Action: DWORD): Boolean;
    procedure ScaleControls(M, D: Integer);
    procedure SelectFirst;
    procedure SelectNext(CurControl: TWinControl;
      GoForward, CheckTabStop: Boolean);
    procedure SetChildOrder(Child: TComponent; Order: Integer); override;
    procedure SetIme;
    function SetImeCompositionWindow(Font: TFont; XPos, YPos: Integer): Boolean;
    procedure SetZOrder(TopMost: Boolean); override;
    procedure ShowControl(AControl: TControl); virtual;
    procedure WndProc(var Message: TMessage); override;
    property BevelEdges: TBevelEdges read FBevelEdges write SetBevelEdges default [beLeft, beTop, beRight, beBottom];
    property BevelInner: TBevelCut index 0 read FBevelInner write SetBevelCut default bvRaised;
    property BevelOuter: TBevelCut index 1 read FBevelOuter write SetBevelCut default bvLowered;
    property BevelKind: TBevelKind read FBevelKind write SetBevelKind default bkNone;
    property BevelWidth: TBevelWidth read FBevelWidth write SetBevelWidth default 1;
    property BorderWidth: TBorderWidth read FBorderWidth write SetBorderWidth default 0;
    property Ctl3D: Boolean read FCtl3D write SetCtl3D stored IsCtl3DStored;
    property DefWndProc: Pointer read FDefWndProc write FDefWndProc;
    property DockSite: Boolean read FDockSite write SetDockSite default False;
    property DockManager: IDockManager read FDockManager write FDockManager;
    property ImeMode: TImeMode read FImeMode write FImeMode default imDontCare;
    property ImeName: TImeName read FImeName write FImeName;
    property ParentCtl3D: Boolean read FParentCtl3D write SetParentCtl3D default True;
    property UseDockManager: Boolean read FUseDockManager write SetUseDockManager
      default False;
    property WheelAccumulator: Integer read FWheelAccumulator write FWheelAccumulator;
    property WindowHandle: HWnd read FHandle write FHandle;
    property OnDockDrop: TDockDropEvent read FOnDockDrop write FOnDockDrop;
    property OnDockOver: TDockOverEvent read FOnDockOver write FOnDockOver;
    property OnEnter: TNotifyEvent read FOnEnter write FOnEnter;
    property OnExit: TNotifyEvent read FOnExit write FOnExit;
    property OnGetSiteInfo: TGetSiteInfoEvent read FOnGetSiteInfo write FOnGetSiteInfo;
    property OnKeyDown: TKeyEvent read FOnKeyDown write FOnKeyDown;
    property OnKeyPress: TKeyPressEvent read FOnKeyPress write FOnKeyPress;
    property OnKeyUp: TKeyEvent read FOnKeyUp write FOnKeyUp;
    property OnMouseWheel: TMouseWheelEvent read FOnMouseWheel write FOnMouseWheel;
    property OnMouseWheelDown: TMouseWheelUpDownEvent read FOnMouseWheelDown
      write FOnMouseWheelDown;
    property OnMouseWheelUp: TMouseWheelUpDownEvent read FOnMouseWheelUp write
      FOnMouseWheelUp;
    property OnUnDock: TUnDockEvent read FOnUnDock write FOnUnDock;
  public
    constructor Create(AOwner: TComponent); override;
    constructor CreateParented(ParentWindow: HWnd);
    class function CreateParentedControl(ParentWindow: HWnd): TWinControl;
    destructor Destroy; override;
    procedure Broadcast(var Message);
    function CanFocus: Boolean; dynamic;
    function ContainsControl(Control: TControl): Boolean;
    function ControlAtPos(const Pos: TPoint; AllowDisabled: Boolean;
      AllowWinControls: Boolean = False): TControl;
    procedure DefaultHandler(var Message); override;
    procedure DisableAlign;
    property DockClientCount: Integer read GetDockClientCount;
    property DockClients[Index: Integer]: TControl read GetDockClients;
    procedure DockDrop(Source: TDragDockObject; X, Y: Integer); dynamic;
    property DoubleBuffered: Boolean read FDoubleBuffered write FDoubleBuffered;
    procedure EnableAlign;
    function FindChildControl(const ControlName: string): TControl;
    procedure FlipChildren(AllLevels: Boolean); dynamic;
    function Focused: Boolean; dynamic;
    procedure GetTabOrderList(List: TList); dynamic;
    function HandleAllocated: Boolean;
    procedure HandleNeeded;
    procedure InsertControl(AControl: TControl);
    procedure Invalidate; override;
    procedure MouseWheelHandler(var Message: TMessage); dynamic;
    procedure PaintTo(DC: HDC; X, Y: Integer);
    procedure RemoveControl(AControl: TControl);
    procedure Realign;
    procedure Repaint; override;
    procedure ScaleBy(M, D: Integer);
    procedure ScrollBy(DeltaX, DeltaY: Integer);
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    procedure SetFocus; virtual;
    procedure Update; override;
    procedure UpdateControlState;
    property VisibleDockClientCount: Integer read GetVisibleDockClientCount;
    property Brush: TBrush read FBrush;
    property Controls[Index: Integer]: TControl read GetControl;
    property ControlCount: Integer read GetControlCount;
    property Handle: HWnd read GetHandle;
    property ParentWindow: HWnd read FParentWindow write SetParentWindow;
    property Showing: Boolean read FShowing;
    property TabOrder: TTabOrder read GetTabOrder write SetTabOrder default -1;
    property TabStop: Boolean read FTabStop write SetTabStop default False;
  published
    property HelpContext: THelpContext read FHelpContext write FHelpContext stored IsHelpContextStored default 0;
  end;

  TGraphicControl = class(TControl)
  private
    FCanvas: TCanvas;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
  protected
    procedure Paint; virtual;
    property Canvas: TCanvas read FCanvas;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  TCustomControl = class(TWinControl)
  private
    FCanvas: TCanvas;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
  protected
    procedure Paint; virtual;
    procedure PaintWindow(DC: HDC); override;
    property Canvas: TCanvas read FCanvas;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  THintWindow = class(TCustomControl)
  private
    FActivating: Boolean;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
    procedure WMNCPaint(var Message: TMessage); message WM_NCPAINT;
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
  protected
    procedure CreateParams(var Params: TCreateParams); override;
    procedure Paint; override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ActivateHint(Rect: TRect; const AHint: string); virtual;
    procedure ActivateHintData(Rect: TRect; const AHint: string; AData: Pointer); virtual;
    function CalcHintRect(MaxWidth: Integer; const AHint: string;
      AData: Pointer): TRect; virtual;
    function IsHintMsg(var Msg: TMsg): Boolean; virtual;
    procedure ReleaseHandle;
    property BiDiMode;
    property Caption;
    property Color;
    property Canvas;
    property Font;
  end;

  THintWindowClass = class of THintWindow;

{ TDragImageList }

  TDragImageList = class(TCustomImageList)
  private
    FDragCursor: TCursor;
    FDragging: Boolean;
    FDragHandle: HWND;
    FDragHotspot: TPoint;
    FDragIndex: Integer;
    procedure CombineDragCursor;
    procedure SetDragCursor(Value: TCursor);
  protected
    procedure Initialize; override;
  public
    function BeginDrag(Window: HWND; X, Y: Integer): Boolean;
    function DragLock(Window: HWND; XPos, YPos: Integer): Boolean;
    function DragMove(X, Y: Integer): Boolean;
    procedure DragUnlock;
    function EndDrag: Boolean;
    function GetHotSpot: TPoint; override;
    procedure HideDragImage;
    function SetDragImage(Index, HotSpotX, HotSpotY: Integer): Boolean;
    procedure ShowDragImage;
    property DragCursor: TCursor read FDragCursor write SetDragCursor;
    property Dragging: Boolean read FDragging;
  end;

{ TImageList }

  TImageList = class(TDragImageList)
  published
    property BlendColor;
    property BkColor;
    property AllocBy;
    property DrawingStyle;
    property Height;
    property ImageType;
    property Masked;
    property OnChange;
    property ShareImages;
    property Width;
  end;

{ TDockZone }

  TDockTree = class;

  // TDockZone encapsulates a region into which other zones are contained.
  // A TDockZone can be a parent to other zones (when FChildZones <> nil) or
  // can contain only a control (when FChildControl <> nil).  A TDockZone also
  // stores pointers to previous and next siblings and its parent.  Parents
  // store a pointer to only the first child in a doubly-linked list of child
  // zones, though each child maintains a pointer to its parent.  Thus, the
  // data structure of relating TDockZones works out to a kind of a
  // doubly-linked list tree.  The FZoneLimit field of TDockZone represents
  // the coordinate of either the left or bottom of the zone, depending on
  // whether its parent zone's orientation is doVertical or doHorizontal.
  TDockZone = class
  private
    FChildControl: TControl;
    FChildZones: TDockZone;
    FNextSibling: TDockZone;
    FOrientation: TDockOrientation;
    FParentZone: TDockZone;
    FPrevSibling: TDockZone;
    FTree: TDockTree;
    FZoneLimit: Integer;
    function GetChildCount: Integer;
    function GetLimitBegin: Integer;
    function GetLimitSize: Integer;
    function GetTopLeft(Orient: Integer{TDockOrientation}): Integer;
    function GetHeightWidth(Orient: Integer{TDockOrientation}): Integer;
    function GetControlName: string;
    function SetControlName(const Value: string): Boolean;
  public
    constructor Create(Tree: TDockTree);
    procedure ResetChildren;
    procedure Update;
    property ChildCount: Integer read GetChildCount;
    property Height: Integer index Ord(doHorizontal) read GetHeightWidth;
    property Left: Integer index Ord(doVertical) read GetTopLeft;
    property LimitBegin: Integer read GetLimitBegin;
    property LimitSize: Integer read GetLimitSize;
    property Top: Integer index Ord(doHorizontal) read GetTopLeft;
    property Width: Integer index Ord(doVertical) read GetHeightWidth;
  end;

{ TDockTree }

  TForEachZoneProc = procedure(Zone: TDockZone) of object;

  TDockTreeClass = class of TDockTree;

  // TDockTree serves as a manager for a tree of TDockZones.  It is responsible
  // for inserting and removing controls (and thus zones) from the tree and
  // associated housekeeping, such as orientation, zone limits, parent zone
  // creation, and painting of controls into zone bounds.
  TDockTree = class(TInterfacedObject, IDockManager)
  private
    FBorderWidth: Integer;
    FBrush: TBrush;
    FDockSite: TWinControl;
    FGrabberSize: Integer;
    FGrabbersOnTop: Boolean;
    FOldRect: TRect;
    FOldWndProc: TWndMethod;
    FReplacementZone: TDockZone;
    FScaleBy: Double;
    FShiftScaleOrient: TDockOrientation;
    FShiftBy: Integer;
    FSizePos: TPoint;
    FSizingDC: HDC;
    FSizingWnd: HWND;
    FSizingZone: TDockZone;
    FTopZone: TDockZone;
    FTopXYLimit: Integer;
    FUpdateCount: Integer;
    FVersion: Integer;
    procedure ControlVisibilityChanged(Control: TControl; Visible: Boolean);
    procedure DrawSizeSplitter;
    function FindControlZone(Control: TControl): TDockZone;
    procedure ForEachAt(Zone: TDockZone; Proc: TForEachZoneProc);
    function GetNextLimit(AZone: TDockZone): Integer;
    procedure InsertNewParent(NewZone, SiblingZone: TDockZone;
      ParentOrientation: TDockOrientation; InsertLast: Boolean);
    procedure InsertSibling(NewZone, SiblingZone: TDockZone; InsertLast: Boolean);
    function InternalHitTest(const MousePos: TPoint; out HTFlag: Integer): TDockZone;
    procedure PruneZone(Zone: TDockZone);
    procedure RemoveZone(Zone: TDockZone);
    procedure ScaleZone(Zone: TDockZone);
    procedure SetNewBounds(Zone: TDockZone);
    procedure ShiftZone(Zone: TDockZone);
    procedure SplitterMouseDown(OnZone: TDockZone; MousePos: TPoint);
    procedure SplitterMouseUp;
    procedure UpdateZone(Zone: TDockZone);
    procedure WindowProc(var Message: TMessage);
  protected
    procedure AdjustDockRect(Control: TControl; var ARect: TRect); virtual;
    procedure BeginUpdate;
    procedure EndUpdate;
    procedure GetControlBounds(Control: TControl; out CtlBounds: TRect);
    function HitTest(const MousePos: TPoint; out HTFlag: Integer): TControl; virtual;
    procedure InsertControl(Control: TControl; InsertAt: TAlign;
      DropCtl: TControl); virtual;
    procedure LoadFromStream(Stream: TStream); virtual;
    procedure PaintDockFrame(Canvas: TCanvas; Control: TControl;
      const ARect: TRect); virtual;
    procedure PositionDockRect(Client, DropCtl: TControl; DropAlign: TAlign;
      var DockRect: TRect); virtual;
    procedure RemoveControl(Control: TControl); virtual;
    procedure SaveToStream(Stream: TStream); virtual;
    procedure SetReplacingControl(Control: TControl);
    procedure ResetBounds(Force: Boolean); virtual;
    procedure UpdateAll;
    property DockSite: TWinControl read FDockSite write FDockSite;
  public
    constructor Create(DockSite: TWinControl); virtual;
    destructor Destroy; override;
    procedure PaintSite(DC: HDC); virtual;
  end;

{ Mouse support }

  TMouse = class
  private
    FDragImmediate: Boolean;
    FDragThreshold: Integer;
    FMousePresent: Boolean;
    FNativeWheelSupport: Boolean;
    FScrollLines: Integer;
    FScrollLinesMessage: UINT;
    FWheelHwnd: HWND;
    FWheelMessage: UINT;
    FWheelPresent: Boolean;
    FWheelSupportMessage: UINT;
    procedure GetMouseData;
    procedure GetNativeData;
    procedure GetRegisteredData;
    function GetCursorPos: TPoint;
    procedure SetCursorPos(const Value: TPoint);
    function GetCapture: HWND;
    procedure SetCapture(const Value: HWND);
  public
    constructor Create;
    destructor Destroy; override;
    procedure SettingChanged(Setting: Integer);
    property Capture: HWND read GetCapture write SetCapture;
    property CursorPos: TPoint read GetCursorPos write SetCursorPos;
    property DragImmediate: Boolean read FDragImmediate write FDragImmediate default True;
    property DragThreshold: Integer read FDragThreshold write FDragThreshold default 5;
    property MousePresent: Boolean read FMousePresent;
    property RegWheelMessage: UINT read FWheelMessage;
    property WheelPresent: Boolean read FWheelPresent;
    property WheelScrollLines: Integer read FScrollLines;
  end;

var
  Mouse: TMouse;

{ Drag stuff }

function IsDragObject(Sender: TObject): Boolean;
function FindControl(Handle: HWnd): TWinControl;
function FindVCLWindow(const Pos: TPoint): TWinControl;
function FindDragTarget(const Pos: TPoint; AllowDisabled: Boolean): TControl;
function GetCaptureControl: TControl;
procedure SetCaptureControl(Control: TControl);
procedure CancelDrag;

{ Misc }

function CursorToString(Cursor: TCursor): string;
function StringToCursor(const S: string): TCursor;
procedure GetCursorValues(Proc: TGetStrProc);
function CursorToIdent(Cursor: Longint; var Ident: string): Boolean;
function IdentToCursor(const Ident: string; var Cursor: Longint): Boolean;

function GetShortHint(const Hint: string): string;
function GetLongHint(const Hint: string): string;

var
  CreationControl: TWinControl = nil;
  DefaultDockTreeClass: TDockTreeClass = TDockTree;
  
function InitWndProc(HWindow: HWnd; Message, WParam: Longint;
  LParam: Longint): Longint; stdcall;

const
  CTL3D_ALL = $FFFF;
  NullDockSite = TWinControl($FFFFFFFF);
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
    [akLeft, akTop, akRight, akBottom]);

var
  NewStyleControls: Boolean;

procedure ChangeBiDiModeAlignment(var Alignment: TAlignment);

function SendAppMessage(Msg: Cardinal; WParam, LParam: Longint): Longint;
procedure MoveWindowOrg(DC: HDC; DX, DY: Integer);

procedure SetImeMode(hWnd: HWND; Mode: TImeMode);
procedure SetImeName(Name: TImeName);
function Win32NLSEnableIME(hWnd: HWND; Enable: Boolean): Boolean;
function Imm32GetContext(hWnd: HWND): HIMC;
function Imm32ReleaseContext(hWnd: HWND; hImc: HIMC): Boolean;
function Imm32GetConversionStatus(hImc: HIMC; var Conversion, Sentence: DWORD): Boolean;
function Imm32SetConversionStatus(hImc: HIMC; Conversion, Sentence: DWORD): Boolean;
function Imm32SetOpenStatus(hImc: HIMC; fOpen: Boolean): Boolean;
function Imm32SetCompositionWindow(hImc: HIMC; lpCompForm: PCOMPOSITIONFORM): Boolean;
function Imm32SetCompositionFont(hImc: HIMC; lpLogfont: PLOGFONTA): Boolean;
function Imm32GetCompositionString(hImc: HIMC; dWord1: DWORD; lpBuf: pointer; dwBufLen: DWORD): Longint;
function Imm32IsIME(hKl: HKL): Boolean;
function Imm32NotifyIME(hImc: HIMC; dwAction, dwIndex, dwValue: DWORD): Boolean;

implementation

uses Consts, Forms, ActiveX;

var
  WindowAtom: TAtom;
  ControlAtom: TAtom;

{ BiDiMode support routines }

procedure ChangeBiDiModeAlignment(var Alignment: TAlignment);
begin
  case Alignment of
    taLeftJustify:  Alignment := taRightJustify;
    taRightJustify: Alignment := taLeftJustify;
  end;
end;

{ Initialization window procedure }

function InitWndProc(HWindow: HWnd; Message, WParam,
  LParam: Longint): Longint;
begin
  CreationControl.FHandle := HWindow;
  SetWindowLong(HWindow, GWL_WNDPROC,
    Longint(CreationControl.FObjectInstance));
  if (GetWindowLong(HWindow, GWL_STYLE) and WS_CHILD <> 0) and
    (GetWindowLong(HWindow, GWL_ID) = 0) then
    SetWindowLong(HWindow, GWL_ID, HWindow);
  SetProp(HWindow, MakeIntAtom(ControlAtom), THandle(CreationControl));
  SetProp(HWindow, MakeIntAtom(WindowAtom), THandle(CreationControl));
  asm
        PUSH    LParam
        PUSH    WParam
        PUSH    Message
        PUSH    HWindow
        MOV     EAX,CreationControl
        MOV     CreationControl,0
        CALL    [EAX].TWinControl.FObjectInstance
        MOV     Result,EAX
  end;
end;

{ Find a TWinControl given a window handle }

function FindControl(Handle: HWnd): TWinControl;
begin
  Result := nil;
  if Handle <> 0 then
  begin
    Result := Pointer(GetProp(Handle, MakeIntAtom(ControlAtom)));
  end;
end;

{ Send message to application object }

function SendAppMessage(Msg: Cardinal; WParam, LParam: Longint): Longint;
begin
  if Application.Handle <> 0 then
    Result := SendMessage(Application.Handle, Msg, WParam, LParam) else
    Result := 0;
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

function GetShortHint(const Hint: string): string;
var
  I: Integer;
begin
  I := AnsiPos('|', Hint);
  if I = 0 then
    Result := Hint else
    Result := Copy(Hint, 1, I - 1);
end;

function GetLongHint(const Hint: string): string;
var
  I: Integer;
begin
  I := AnsiPos('|', Hint);
  if I = 0 then
    Result := Hint else
    Result := Copy(Hint, I + 1, Maxint);
end;

{ Mouse capture management }

var
  CaptureControl: TControl = nil;

function GetCaptureControl: TControl;
begin
  Result := FindControl(GetCapture);
  if (Result <> nil) and (CaptureControl <> nil) and
    (CaptureControl.Parent = Result) then Result := CaptureControl;
end;

procedure SetCaptureControl(Control: TControl);
begin
  ReleaseCapture;
  CaptureControl := nil;
  if Control <> nil then
  begin
    if not (Control is TWinControl) then
    begin
      if Control.Parent = nil then Exit;
      CaptureControl := Control;
      Control := Control.Parent;
    end;
    SetCapture(TWinControl(Control).Handle);
  end;
end;

{ Drag-and-drop management }

type
  TDragOperation = (dopNone, dopDrag, dopDock);

  PSiteInfoRec = ^TSiteInfoRec;
  TSiteInfoRec = record
    Site: TWinControl;
    TopParent: HWND;
  end;

{ TSiteList }

  // TSiteList deals with the relative z-order positions of dock sites
  TSiteList = class(TList)
  public
    procedure AddSite(ASite: TWinControl);
    procedure Clear; override;
    function Find(ParentWnd: Hwnd; var Index: Integer): Boolean;
    function GetTopSite: TWinControl;
  end;

function TSiteList.Find(ParentWnd: Hwnd; var Index: Integer): Boolean;
begin
  Index := 0;
  Result := False;
  while Index < Count do
  begin
    Result := (PSiteInfoRec(Items[Index]).TopParent = ParentWnd);
    if Result then Exit;
    Inc(Index);
  end;
end;

procedure TSiteList.AddSite(ASite: TWinControl);

  function GetTopParent: HWND;
  var
    NextParent: HWND;
  begin
    NextParent := ASite.Handle;
    Result := NextParent;
    while NextParent <> 0 do
    begin
      Result := NextParent;
      NextParent := GetParent(NextParent);
    end;
  end;

var
  SI: PSiteInfoRec;
  Index: Integer;
begin
  New(SI);
  SI.Site := ASite;
  SI.TopParent := GetTopParent;
  if Find(SI.TopParent, Index) then
    Insert(Index, SI) else
    Add(SI);
end;

procedure TSiteList.Clear;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Dispose(PSiteInfoRec(Items[I]));
  inherited Clear;
end;

function TSiteList.GetTopSite: TWinControl;
var
  Index: Integer;
  DesktopWnd, CurrentWnd: HWND;
begin
  Result := nil;
  if Count = 0 then Exit
  else if Count = 1 then Result := PSiteInfoRec(Items[0]).Site
  else begin
    DesktopWnd := GetDesktopWindow;
    CurrentWnd := GetTopWindow(DesktopWnd);
    while (Result = nil) and (CurrentWnd <> 0) do
    begin
      if Find(CurrentWnd, Index) then
        Result := PSiteInfoRec(List[Index])^.Site
      else
        CurrentWnd := GetNextWindow(CurrentWnd, GW_HWNDNEXT);
    end;
  end;
end;

var
  DragControl: TControl;
  DragObject: TDragObject;
  DragFreeObject: Boolean;
  DragCapture: HWND;
  DragStartPos: TPoint;
  DragSaveCursor: HCURSOR;
  DragThreshold: Integer;
  ActiveDrag: TDragOperation;
  DragImageList: TDragImageList;
  DockSiteList: TList;
  QualifyingSites: TSiteList;

procedure DragTo(const Pos: TPoint); forward;
procedure DragDone(Drop: Boolean); forward;

function IsDragObject(Sender: TObject): Boolean;
var
  SenderClass: TClass;
begin
  SenderClass := Sender.ClassType;
  Result := True;
  while SenderClass <> nil do
    if SenderClass.ClassName = TDragObject.ClassName then Exit
    else SenderClass := SenderClass.ClassParent;
  Result := False;
end;

{ TDragObject }

procedure TDragObject.Assign(Source: TDragObject);
begin
  FDragTarget := Source.FDragTarget;
  FDragHandle := Source.FDragHandle;
  FDragPos := Source.FDragPos;
  FDragTargetPos := Source.FDragTargetPos;
  FMouseDeltaX := Source.FMouseDeltaX;
  FMouseDeltaY := Source.FMouseDeltaY;
end;

function TDragObject.Capture: HWND;
begin
  Result := AllocateHWND(MouseMsg);
  SetCapture(Result);
end;

procedure TDragObject.Finished(Target: TObject; X, Y: Integer; Accepted: Boolean);
begin
end;

function TDragObject.GetName: string;
begin
  Result := ClassName;
end;

procedure TDragObject.ReleaseCapture(Handle: HWND);
begin
  Windows.ReleaseCapture;
  DeallocateHWND(Handle);
end;

procedure TDragObject.MouseMsg(var Msg: TMessage);
var
  P: TPoint;
begin
  try
    case Msg.Msg of
      WM_MOUSEMOVE:
        begin
          P := SmallPointToPoint(TWMMouse(Msg).Pos);
          ClientToScreen(DragCapture, P);
          DragTo(P);
        end;
      WM_CAPTURECHANGED:
        DragDone(False);
      WM_LBUTTONUP, WM_RBUTTONUP:
        DragDone(True);
      { Forms.IsKeyMsg sends WM_KEYxxx messages here (+CN_BASE) when a
        TPUtilWindow has the mouse capture. }
      CN_KEYUP:
        if Msg.WParam = VK_CONTROL then DragTo(DragObject.DragPos);
      CN_KEYDOWN:
        begin
          case Msg.WParam of
            VK_CONTROL:
              DragTo(DragObject.DragPos);
            VK_ESCAPE:
              begin
                { Consume keystroke and cancel drag operation }
                Msg.Result := 1;
                DragDone(False);
              end;
          end;
        end;
    end;
  except
    if DragControl <> nil then DragDone(False);
    raise;
  end;
end;

function TDragObject.GetDragImages: TDragImageList;
begin
  Result := nil;
end;

function TDragObject.GetDragCursor(Accepted: Boolean; X, Y: Integer): TCursor;
begin
  if Accepted then Result := crDrag
  else Result := crNoDrop;
end;

procedure TDragObject.HideDragImage;
begin
  // do nothing
end;

function TDragObject.Instance: THandle;
begin
  Result := SysInit.HInstance;
end;

procedure TDragObject.ShowDragImage;
begin
  // do nothing
end;

{ TBaseDragControlObject }

constructor TBaseDragControlObject.Create(AControl: TControl);
begin
  FControl := AControl;
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

procedure TBaseDragControlObject.Finished(Target: TObject; X, Y: Integer; Accepted: Boolean);
begin
  if not Accepted then
  begin
    FControl.DragCanceled;
    Target := nil;
  end;
  EndDrag(Target, X, Y);
end;

{ TDragControlObject }

function TDragControlObject.GetDragCursor(Accepted: Boolean; X, Y: Integer): TCursor;
begin
  if Accepted then Result := Control.DragCursor
  else Result := crNoDrop;
end;

function TDragControlObject.GetDragImages: TDragImageList;
begin
  Result := Control.GetDragImages;
end;

procedure TDragControlObject.HideDragImage;
begin
  if Control.GetDragImages <> nil then
    Control.GetDragImages.HideDragImage;
end;

procedure TDragControlObject.ShowDragImage;
begin
  if Control.GetDragImages <> nil then
    Control.GetDragImages.ShowDragImage;
end;

{ TDragDockObject }

constructor TDragDockObject.Create(AControl: TControl);
begin
  inherited Create(AControl);
  FBrush := TBrush.Create;
  FBrush.Bitmap := AllocPatternBitmap(clBlack, clWhite);
end;

destructor TDragDockObject.Destroy;
begin
  FBrush.Free;
  inherited Destroy;
end;

procedure TDragDockObject.Assign(Source: TDragObject);
begin
  inherited Assign(Source);
  if Source is TDragDockObject then
  begin
    FDropAlign := TDragDockObject(Source).FDropAlign;
    FDropOnControl := TDragDockObject(Source).FDropOnControl;
    FFloating := TDragDockObject(Source).FFloating;
    FDockRect := TDragDockObject(Source).FDockRect;
    FEraseDockRect := TDragDockObject(Source).FEraseDockRect;
    FBrush.Assign(TDragDockObject(Source).FBrush);
  end;
end;

procedure TDragDockObject.SetBrush(Value: TBrush);
begin
  FBrush.Assign(Value);
end;

procedure TDragDockObject.EndDrag(Target: TObject; X, Y: Integer);
begin
  FControl.DoEndDock(Target, X, Y);
end;

procedure TDragDockObject.AdjustDockRect(ARect: TRect);
var
  DeltaX, DeltaY: Integer;

  function AbsMin(Value1, Value2: Integer): Integer;
  begin
    if Abs(Value1) < Abs(Value2) then Result := Value1
    else Result := Value2;
  end;

begin
  { Make sure dock rect is touching mouse point }
  if (ARect.Left > FDragPos.x) or (ARect.Right < FDragPos.x) then
    DeltaX := AbsMin(ARect.Left - FDragPos.x, ARect.Right - FDragPos.x)
  else DeltaX := 0;
  if (ARect.Top > FDragPos.y) or (ARect.Bottom < FDragPos.y) then
    DeltaY := AbsMin(ARect.Top - FDragPos.y, ARect.Bottom - FDragPos.y)
  else DeltaY := 0;
  if (DeltaX <> 0) or (DeltaY <> 0) then
    OffsetRect(FDockRect, -DeltaX, -DeltaY);
end;

procedure TDragDockObject.DrawDragDockImage;
begin
  FControl.DrawDragDockImage(Self);
end;

procedure TDragDockObject.EraseDragDockImage;
begin
  FControl.EraseDragDockImage(Self);
end;

function TDragDockObject.GetDragCursor(Accepted: Boolean; X, Y: Integer): TCursor;
begin
  Result := crDefault;
end;

function TDragDockObject.GetFrameWidth: Integer;
begin
  Result := 4;
end;

{ Drag dock functions }

type
  PCheckTargetInfo = ^TCheckTargetInfo;
  TCheckTargetInfo = record
    ClientWnd, TargetWnd: HWnd;
    CurrentWnd: HWnd;
    MousePos: TPoint;
    Found: Boolean;
  end;

function IsBeforeTargetWindow(Window: HWnd; Data: Longint): Bool; stdcall;
var
  R: TRect;
begin
  if Window = PCheckTargetInfo(Data)^.TargetWnd then
    Result := False
  else
  begin
    if PCheckTargetInfo(Data)^.CurrentWnd = 0 then
    begin
      GetWindowRect(Window, R);
      if PtInRect(R, PCheckTargetInfo(Data)^.MousePos) then
        PCheckTargetInfo(Data)^.CurrentWnd := Window;
    end;
    if Window = PCheckTargetInfo(Data)^.CurrentWnd then
    begin
      Result := False;
      PCheckTargetInfo(Data)^.Found := True;
    end
    else if Window = PCheckTargetInfo(Data)^.ClientWnd then
    begin
      Result := True;
      PCheckTargetInfo(Data)^.CurrentWnd := 0; // Look for next window
    end
    else
      Result := True;
  end;
end;

function DragFindWindow(const Pos: TPoint): HWND; forward;

function GetDockSiteAtPos(MousePos: TPoint; Client: TControl): TWinControl;
var
  I: Integer;
  R: TRect;
  Site: TWinControl;
  CanDock, ControlKeyDown: Boolean;

  function ValidDockTarget(Target: TWinControl): Boolean;
  var
    Info: TCheckTargetInfo;
    Control: TWinControl;
    R1, R2: TRect;
  begin
    Result := True;
    { Find handle for topmost container of current }
    Info.CurrentWnd := DragFindWindow(MousePos);
    if (GetWindow(Info.CurrentWnd, GW_OWNER) <> Application.Handle) then
    begin
      Control := FindControl(Info.CurrentWnd);
      if Control = nil then Exit;
      while Control.Parent <> nil do Control := Control.Parent;
      Info.CurrentWnd := Control.Handle;
    end;
    if Info.CurrentWnd = 0 then Exit;

    { Find handle for topmost container of target }
    Control := Target;
    while Control.Parent <> nil do Control := Control.Parent;
    Info.TargetWnd := Control.Handle;
    if Info.CurrentWnd = Info.TargetWnd then Exit;

    { Find handle for topmost container of client }
    if Client.Parent <> nil then
    begin
      Control := Client.Parent;
      while Control.Parent <> nil do Control := Control.Parent;
      Info.ClientWnd := Control.Handle;
    end
    else if Client is TWinControl then
      Info.ClientWnd := TWinControl(Client).Handle
    else
      Info.ClientWnd := 0;

    Info.Found := False;
    Info.MousePos := MousePos;
    EnumThreadWindows(GetCurrentThreadID, @IsBeforeTargetWindow, Longint(@Info));
    { CurrentWnd is in front of TargetWnd, so check whether they're overlapped. }
    if Info.Found then
    begin
      GetWindowRect(Info.CurrentWnd, R1);
      Target.GetSiteInfo(Client, R2, MousePos, CanDock);
      { Docking control's host shouldn't count as an overlapped window }
      if DragObject is TDragDockObject
      and (TDragDockObject(DragObject).Control.HostDockSite <> nil)
      and (TDragDockObject(DragObject).Control.HostDockSite.Handle = Info.CurrentWnd) then
        Exit;
      if IntersectRect(R1, R1, R2) then
        Result := False;
    end;
  end;

  function IsSiteChildOfClient: Boolean;
  begin
    if Client is TWinControl then
      Result := IsChild(TWinControl(Client).Handle, Site.Handle)
    else
      Result := False;
  end;

begin
  Result := nil;
  ControlKeyDown := (GetKeyState(VK_CONTROL) and not $7FFF) <> 0;
  if (DockSiteList = nil) or ControlKeyDown then Exit;
  QualifyingSites.Clear;
  for I := 0 to DockSiteList.Count - 1 do
  begin
    Site := TWinControl(DockSiteList[I]);
    if (Site <> Client) and Site.Showing and Site.Enabled and
      IsWindowVisible(Site.Handle) and (not IsSiteChildOfClient) and
      ((Client.HostDockSite <> Site) or (Site.VisibleDockClientCount > 1)) then
    begin
      CanDock := True;
      Site.GetSiteInfo(Client, R, MousePos, CanDock);
      if CanDock and PtInRect(R, MousePos) then
        QualifyingSites.AddSite(Site);
    end;
  end;
  if QualifyingSites.Count > 0 then
    Result := QualifyingSites.GetTopSite;
  if (Result <> nil) and not ValidDockTarget(Result) then
    Result := nil;
end;

procedure RegisterDockSite(Site: TWinControl; DoRegister: Boolean);
var
  Index: Integer;
begin
  if (Site <> nil) then
  begin
    if DockSiteList = nil then DockSiteList := TList.Create;
    Index := DockSiteList.IndexOf(Pointer(Site));
    if DoRegister then
    begin
      if Index = -1 then DockSiteList.Add(Pointer(Site));
    end
    else begin
      if Index <> -1 then DockSiteList.Delete(Index);
    end;
  end;
end;

{ Drag drop functions }

function DragMessage(Handle: HWND; Msg: TDragMessage;
  Source: TDragObject; Target: Pointer; const Pos: TPoint): Longint;
var
  DragRec: TDragRec;
begin
  Result := 0;
  if Handle <> 0 then
  begin
    DragRec.Pos := Pos;
    DragRec.Target := Target;
    DragRec.Source := Source;
    DragRec.Docking := ActiveDrag = dopDock;
    Result := SendMessage(Handle, CM_DRAG, Longint(Msg), Longint(@DragRec));
  end;
end;

function IsDelphiHandle(Handle: HWND): Boolean;
begin
  Result := (Handle <> 0) and
    (GetProp(Handle, MakeIntAtom(WindowAtom)) <> 0);
end;

function DragFindWindow(const Pos: TPoint): HWND;
begin
  Result := WindowFromPoint(Pos);
  while Result <> 0 do
    if not IsDelphiHandle(Result) then Result := GetParent(Result)
    else Exit;
end;

function DragFindTarget(const Pos: TPoint; var Handle: HWND;
  DragKind: TDragKind; Client: TControl): Pointer;
begin
  if DragKind = dkDrag then
  begin
    Handle := DragFindWindow(Pos);
    Result := Pointer(DragMessage(Handle, dmFindTarget, DragObject, nil, Pos));
  end
  else begin
    Result := GetDockSiteAtPos(Pos, Client);
    if Result <> nil then
      Handle := TWinControl(Result).Handle;
  end;
end;

function DoDragOver(DragMsg: TDragMessage): Boolean;
begin
  Result := False;
  if DragObject.DragTarget <> nil then
    Result := LongBool(DragMessage(DragObject.DragHandle, DragMsg, DragObject,
      DragObject.DragTarget, DragObject.DragPos));
end;

procedure DragTo(const Pos: TPoint);

  function GetDropCtl: TControl;
  var
    NextCtl: TControl;
    TargetCtl: TWinControl;
    CtlIdx: Integer;
  begin
    Result := nil;
    TargetCtl := TDragObject(DragObject).DragTarget;
    if (TargetCtl = nil) or not TargetCtl.UseDockManager or
      (TargetCtl.FDockClients = nil) or (TargetCtl.DockClientCount = 0) or
      ((TargetCtl.DockClientCount = 1) and
        (TargetCtl.FDockClients[0] = TDragDockObject(DragObject).Control)) then
      Exit;
    NextCtl := FindDragTarget(DragObject.DragPos, False);
    while (NextCtl <> nil) and (NextCtl <> TargetCtl) do
    begin
      CtlIdx := TargetCtl.FDockClients.IndexOf(NextCtl);
      if CtlIdx <> -1 then
      begin
        Result := TargetCtl.DockClients[CtlIdx];
        Exit;
      end
      else
        NextCtl := NextCtl.Parent;
    end;
  end;

var
  DragCursor: TCursor;
  Target: TControl;
  TargetHandle: HWND;
  DoErase: Boolean;
begin
  if (ActiveDrag <> dopNone) or (Abs(DragStartPos.X - Pos.X) >= DragThreshold) or
    (Abs(DragStartPos.Y - Pos.Y) >= DragThreshold) then
  begin
    Target := DragFindTarget(Pos, TargetHandle, DragControl.DragKind, DragControl);
    if (ActiveDrag = dopNone) and (DragImageList <> nil) then
      with DragStartPos do DragImageList.BeginDrag(GetDeskTopWindow, X, Y);
    if DragControl.DragKind = dkDrag then
    begin
      ActiveDrag := dopDrag;
      DoErase := False;
    end
    else begin
      DoErase := ActiveDrag <> dopNone;
      ActiveDrag := dopDock;
    end;
    if Target <> DragObject.DragTarget then
    begin
      DoDragOver(dmDragLeave);
      if DragObject = nil then Exit;
      DragObject.DragTarget := Target;
      DragObject.DragHandle := TargetHandle;
      DragObject.DragPos := Pos;
      DoDragOver(dmDragEnter);
      if DragObject = nil then Exit;
    end;
    DragObject.DragPos := Pos;
    if DragObject.DragTarget <> nil then
      DragObject.DragTargetPos := TControl(DragObject.DragTarget).ScreenToClient(Pos);
    DragCursor := TDragObject(DragObject).GetDragCursor(DoDragOver(dmDragMove),
      Pos.X, Pos.Y);
    if DragImageList <> nil then
    begin
      if (Target = nil) or (csDisplayDragImage in Target.ControlStyle) then
      begin
        DragImageList.DragCursor := DragCursor;
        if not DragImageList.Dragging then
          DragImageList.BeginDrag(GetDeskTopWindow, Pos.X, Pos.Y)
        else DragImageList.DragMove(Pos.X, Pos.Y);
      end
      else begin
        DragImageList.EndDrag;
        Windows.SetCursor(Screen.Cursors[DragCursor]);
      end;
    end;
    Windows.SetCursor(Screen.Cursors[DragCursor]);
    if ActiveDrag = dopDock then
    begin
      with TDragDockObject(DragObject) do
      begin
        if Target = nil then
          Control.DockTrackNoTarget(TDragDockObject(DragObject), Pos.X, Pos.Y)
        else begin
          FDropOnControl := GetDropCtl;
          if FDropOnControl = nil then
            with DragObject do
              FDropAlign := TWinControl(DragTarget).GetDockEdge(DragTargetPos)
          else
            FDropAlign := FDropOnControl.GetDockEdge(FDropOnControl.ScreenToClient(Pos));
        end;
      end;
      if DragObject <> nil then
        with TDragDockObject(DragObject) do
          if not CompareMem(@FDockRect, @FEraseDockRect, SizeOf(TRect)) then
          begin
            if DoErase then EraseDragDockImage;
            DrawDragDockImage;
            FEraseDockRect := FDockRect;
          end;
    end;
  end;
end;

procedure DragInit(ADragObject: TDragObject; Immediate: Boolean; Threshold: Integer);
begin
  DragObject := ADragObject;
  DragObject.DragTarget := nil;
  GetCursorPos(DragStartPos);
  DragObject.DragPos := DragStartPos;
  DragSaveCursor := Windows.GetCursor;
  DragCapture := DragObject.Capture;
  DragThreshold := Threshold;
  if ADragObject is TDragDockObject then
  begin
    with TDragDockObject(ADragObject), FDockRect do
    begin
      if Right - Left > 0 then
        FMouseDeltaX :=  (DragPos.x - Left) / (Right - Left) else
        FMouseDeltaX := 0;
      if Bottom - Top > 0 then
        FMouseDeltaY :=  (DragPos.y - Top) / (Bottom - Top) else
        FMouseDeltaY := 0;
      if Immediate then
      begin
        ActiveDrag := dopDock;
        DrawDragDockImage;
      end
      else ActiveDrag := dopNone;
    end;
  end
  else begin
    if Immediate then ActiveDrag := dopDrag
    else ActiveDrag := dopNone;
  end;
  DragImageList := DragObject.GetDragImages;
  if DragImageList <> nil then
    with DragStartPos do DragImageList.BeginDrag(GetDeskTopWindow, X, Y);
  QualifyingSites := TSiteList.Create;
  if ActiveDrag <> dopNone then DragTo(DragStartPos);
end;

procedure DragInitControl(Control: TControl; Immediate: Boolean; Threshold: Integer);
var
  DragObject: TDragObject;
  StartPos: TPoint;
begin
  DragControl := Control;
  try
    DragObject := nil;
    DragFreeObject := False;
    if Control.FDragKind = dkDrag then
    begin
      Control.DoStartDrag(DragObject);
      if DragControl = nil then Exit;
      if DragObject = nil then
      begin
        DragObject := TDragControlObject.Create(Control);
        DragFreeObject := True;
      end;
    end
    else begin
      Control.DoStartDock(DragObject);
      if DragControl = nil then Exit;
      if DragObject = nil then
      begin
        DragObject := TDragDockObject.Create(Control);
        DragFreeObject := True;
      end;
      with TDragDockObject(DragObject) do
      begin
        if Control is TWinControl then
          GetWindowRect(TWinControl(Control).Handle, FDockRect)
        else begin
          if (Control.Parent = nil) and not (Control is TWinControl) then
          begin
            GetCursorPos(StartPos);
            FDockRect.TopLeft := StartPos;
          end
          else
            FDockRect.TopLeft := Control.ClientToScreen(Point(0, 0));
          FDockRect.BottomRight := Point(FDockRect.Left + Control.Width,
            FDockRect.Top + Control.Height);
        end;
        FEraseDockRect := FDockRect;
      end;
    end;
    DragInit(DragObject, Immediate, Threshold);
  except
    DragControl := nil;
    raise;
  end;
end;

procedure DragDone(Drop: Boolean);

  function CheckUndock: Boolean;
  begin
    Result := DragObject.DragTarget <> nil;
    with DragControl do
      if Drop and (ActiveDrag = dopDock) then
        if Floating or (FHostDockSite = nil) then
          Result := True
        else if FHostDockSite <> nil then
          Result := FHostDockSite.DoUnDock(DragObject.DragTarget, DragControl);
  end;

var
  DragSave: TDragObject;
  DockObject: TDragDockObject;
  Accepted: Boolean;
  DragMsg: TDragMessage;
  TargetPos: TPoint;
  ParentForm: TCustomForm;
begin
  DockObject := nil;
  DragSave := nil;
  Accepted := False;
  if (DragObject = nil) or DragObject.Cancelling then Exit;  // recursion control
  try
    DragSave := DragObject;
    try
      DragObject.Cancelling := True;
      DragObject.ReleaseCapture(DragCapture);
      if ActiveDrag = dopDock then
      begin
        DockObject := DragObject as TDragDockObject;
        DockObject.EraseDragDockImage;
        DockObject.Floating := DockObject.DragTarget = nil;
      end;
      if (DragObject.DragTarget <> nil) and
        (TObject(DragObject.DragTarget) is TControl) then
        TargetPos := DragObject.DragTargetPos
      else
        TargetPos := DragObject.DragPos;
      Accepted := CheckUndock and
        (((ActiveDrag = dopDock) and DockObject.Floating) or
        ((ActiveDrag <> dopNone) and DoDragOver(dmDragLeave))) and
        Drop;
      if ActiveDrag = dopDock then
      begin
        if Accepted and DockObject.Floating then
        begin
          ParentForm := GetParentForm(DockObject.Control);
          if (ParentForm <> nil) and
            (ParentForm.ActiveControl = DockObject.Control) then
            ParentForm.ActiveControl := nil;
          DragControl.Perform(CM_FLOAT, 0, Integer(DragObject));
        end;
      end
      else begin
        if DragImageList <> nil then DragImageList.EndDrag
        else Windows.SetCursor(DragSaveCursor);
      end;
      DragControl := nil;
      DragObject := nil;
      if DragSave.DragTarget <> nil then
      begin
        DragMsg := dmDragDrop;
        if not Accepted then
        begin
          DragMsg := dmDragCancel;
          DragSave.FDragPos.X := 0;
          DragSave.FDragPos.Y := 0;
          TargetPos.X := 0;
          TargetPos.Y := 0;
        end;
        DragMessage(DragSave.DragHandle, DragMsg, DragSave,
          DragSave.DragTarget, DragSave.DragPos);
      end;
    finally
      QualifyingSites.Free;
      QualifyingSites := nil;
      DragSave.Cancelling := False;
      DragSave.Finished(DragSave.DragTarget, TargetPos.X, TargetPos.Y, Accepted);
      DragObject := nil;
    end;
  finally
    DragControl := nil;
    if DragFreeObject then DragSave.Free;
  end;
end;

procedure CancelDrag;
begin
  if DragObject <> nil then DragDone(False);
  DragControl := nil;
end;

function FindVCLWindow(const Pos: TPoint): TWinControl;
var
  Handle: HWND;
begin
  Handle := WindowFromPoint(Pos);
  Result := nil;
  while Handle <> 0 do
  begin
    Result := FindControl(Handle);
    if Result <> nil then Exit;
    Handle := GetParent(Handle);
  end;
end;

function FindDragTarget(const Pos: TPoint; AllowDisabled: Boolean): TControl;
var
  Window: TWinControl;
  Control: TControl;
begin
  Result := nil;
  Window := FindVCLWindow(Pos);
  if Window <> nil then
  begin
    Result := Window;
    Control := Window.ControlAtPos(Window.ScreenToClient(Pos), AllowDisabled);
    if Control <> nil then Result := Control;
  end;
end;

{ List helpers }

procedure ListAdd(var List: TList; Item: Pointer);
begin
  if List = nil then List := TList.Create;
  List.Add(Item);
end;

procedure ListRemove(var List: TList; Item: Pointer);
begin
  List.Remove(Item);
  if List.Count = 0 then
  begin
    List.Free;
    List := nil;
  end;
end;

{ Miscellaneous routines }

procedure MoveWindowOrg(DC: HDC; DX, DY: Integer);
var
  P: TPoint;
begin
  GetWindowOrgEx(DC, P);
  SetWindowOrgEx(DC, P.X - DX, P.Y - DY, nil);
end;

{ Object implementations }

{ TControlCanvas }

const
  CanvasListCacheSize = 4;

var
  CanvasList: TThreadList;

// Free the first available device context
procedure FreeDeviceContext;
var
  I: Integer;
begin
  with CanvasList.LockList do
  try
    for I := 0 to Count-1 do
      with TControlCanvas(Items[I]) do
        if TryLock then
        try
          FreeHandle;
          Exit;
        finally
          Unlock;
        end;
  finally
    CanvasList.UnlockList;
  end;
end;

procedure FreeDeviceContexts;
var
  I: Integer;
begin
  with CanvasList.LockList do
  try
    for I := Count-1 downto 0 do
      with TControlCanvas(Items[I]) do
        if TryLock then
        try
          FreeHandle;
        finally
          Unlock;
        end;
  finally
    CanvasList.UnlockList;
  end;
end;

destructor TControlCanvas.Destroy;
begin
  FreeHandle;
  inherited Destroy;
end;

procedure TControlCanvas.CreateHandle;
begin
  if FControl = nil then inherited CreateHandle else
  begin
    if FDeviceContext = 0 then
    begin
      with CanvasList.LockList do
      try
        if Count >= CanvasListCacheSize then FreeDeviceContext;
        FDeviceContext := FControl.GetDeviceContext(FWindowHandle);
        Add(Self);
      finally
        CanvasList.UnlockList;
      end;
    end;
    Handle := FDeviceContext;
    UpdateTextFlags;
  end;
end;

procedure TControlCanvas.FreeHandle;
begin
  if FDeviceContext <> 0 then
  begin
    Handle := 0;
    CanvasList.Remove(Self);
    ReleaseDC(FWindowHandle, FDeviceContext);
    FDeviceContext := 0;
  end;
end;

procedure TControlCanvas.SetControl(AControl: TControl);
begin
  if FControl <> AControl then
  begin
    FreeHandle;
    FControl := AControl;
  end;
end;

procedure TControlCanvas.UpdateTextFlags;
begin
  if Control = nil then Exit;
  if Control.UseRightToLeftReading then
    TextFlags := TextFlags or ETO_RTLREADING
  else
    TextFlags := TextFlags and not ETO_RTLREADING;
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
        if (Value > 0) and (Value < FMinHeight) then
          FMinHeight := Value;
        Change;
      end;
    1:
      if Value <> FMaxWidth then
      begin
        FMaxWidth := Value;
        if (Value > 0) and (Value < FMinWidth) then
          FMinWidth := Value;
        Change;
      end;
    2:
      if Value <> FMinHeight then
      begin
        FMinHeight := Value;
        if (FMaxHeight > 0) and (Value > FMaxHeight) then
          FMaxHeight := Value;
        Change;
      end;
    3:
      if Value <> FMinWidth then
      begin
        FMinWidth := Value;
        if (FMaxWidth > 0) and (Value > FMaxWidth) then
          FMaxWidth := Value;
        Change;
      end;
  end;
end;

procedure TSizeConstraints.Change;
begin
  if Assigned(FOnChange) then FOnChange(Self);
end;

{ TControlActionLink }

procedure TControlActionLink.AssignClient(AClient: TObject);
begin
  FClient := AClient as TControl;
end;

function TControlActionLink.DoShowHint(var HintStr: string): Boolean;
begin
  Result := True;
  if Action is TCustomAction then
  begin
    if TCustomAction(Action).DoHint(HintStr) and Application.HintShortCuts and
      (TCustomAction(Action).ShortCut <> scNone) then
    begin
      if HintStr <> '' then
        HintStr := Format('%s (%s)', [HintStr, ShortCutToText(TCustomAction(Action).ShortCut)]);
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

procedure TControlActionLink.SetCaption(const Value: string);
begin
  if IsCaptionLinked then FClient.Caption := Value;
end;

procedure TControlActionLink.SetEnabled(Value: Boolean);
begin
  if IsEnabledLinked then FClient.Enabled := Value;
end;

procedure TControlActionLink.SetHint(const Value: string);
begin
  if IsHintLinked then FClient.Hint := Value;
end;

procedure TControlActionLink.SetVisible(Value: Boolean);
begin
  if IsVisibleLinked then FClient.Visible := Value;
end;

procedure TControlActionLink.SetOnExecute(Value: TNotifyEvent);
begin
  if IsOnExecuteLinked then FClient.OnClick := Value;
end;

{ TControl }

constructor TControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FWindowProc := WndProc;
  FControlStyle := [csCaptureMouse, csClickEvents, csSetCaption, csDoubleClicks];
  FFont := TFont.Create;
  FFont.OnChange := FontChanged;
  FAnchors := [akLeft, akTop];
  FConstraints := TSizeConstraints.Create(Self);
  FConstraints.OnChange := DoConstraintsChange;
  FColor := clWindow;
  FVisible := True;
  FEnabled := True;
  FParentFont := True;
  FParentColor := True;
  FParentShowHint := True;
  FParentBiDiMode := True;
  FIsControl := False;
  FDragCursor := crDrag;
  FFloatingDockSiteClass := TCustomDockForm;
end;

destructor TControl.Destroy;
begin
  Application.ControlDestroyed(Self);
  if (FHostDockSite <> nil) and not (csDestroying in FHostDockSite.ComponentState) then
  begin
    FHostDockSite.Perform(CM_UNDOCKCLIENT, 0, Integer(Self));
    SetParent(nil);
    Dock(NullDockSite, BoundsRect);
    FHostDockSite := nil;
  end else
    SetParent(nil);
  FActionLink.Free;
  FActionLink := nil;
  FConstraints.Free;
  FFont.Free;
  StrDispose(FText);
  inherited Destroy;
end;

function TControl.GetDragImages: TDragImageList;
begin
  Result := nil;
end;

function TControl.GetEnabled: Boolean;
begin
  Result := FEnabled;
end;

function TControl.GetPalette: HPALETTE;
begin
  Result := 0;
end;

function TControl.HasParent: Boolean;
begin
  Result := FParent <> nil;
end;

function TControl.GetParentComponent: TComponent;
begin
  Result := Parent;
end;

procedure TControl.SetParentComponent(Value: TComponent);
begin
  if (Parent <> Value) and (Value is TWinControl) then
    SetParent(TWinControl(Value));
end;

function TControl.PaletteChanged(Foreground: Boolean): Boolean;
var
  OldPalette, Palette: HPALETTE;
  WindowHandle: HWnd;
  DC: HDC;
begin
  Result := False;
  if not Visible then Exit;
  Palette := GetPalette;
  if Palette <> 0 then
  begin
    DC := GetDeviceContext(WindowHandle);
    OldPalette := SelectPalette(DC, Palette, not Foreground);
    if RealizePalette(DC) <> 0 then Invalidate;
    SelectPalette(DC, OldPalette, True);
    ReleaseDC(WindowHandle, DC);
    Result := True;
  end;
end;

function TControl.GetAction: TBasicAction;
begin
  if ActionLink <> nil then
    Result := ActionLink.Action else
    Result := nil;
end;


procedure TControl.SetAnchors(Value: TAnchors);
begin
  if FAnchors <> Value then
  begin
    FAnchors := Value;
    UpdateAnchorRules;
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

function TControl.IsAnchorsStored: Boolean;
begin
  Result := Anchors <> AnchorAlign[Align];
end;

procedure TControl.SetDragMode(Value: TDragMode);
begin
  FDragMode := Value;
end;

procedure TControl.RequestAlign;
begin
  if Parent <> nil then Parent.AlignControl(Self);
end;

procedure TControl.Resize;
begin
  if Assigned(FOnResize) then FOnResize(Self);
end;

procedure TControl.ReadState(Reader: TReader);
begin
  Include(FControlState, csReadingState);
  if Reader.Parent is TWinControl then Parent := TWinControl(Reader.Parent);
  inherited ReadState(Reader);
  Exclude(FControlState, csReadingState);
  if Parent <> nil then
  begin
    Perform(CM_PARENTCOLORCHANGED, 0, 0);
    Perform(CM_PARENTFONTCHANGED, 0, 0);
    Perform(CM_PARENTSHOWHINTCHANGED, 0, 0);
    Perform(CM_SYSFONTCHANGED, 0, 0);
    Perform(CM_PARENTBIDIMODECHANGED, 0, 0);
  end;
end;

procedure TControl.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Operation = opRemove then
    if AComponent = PopupMenu then PopupMenu := nil
    else if AComponent = Action then Action := nil;
end;

procedure TControl.SetAlign(Value: TAlign);
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
  end;
  RequestAlign;
end;

procedure TControl.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  if CheckNewSize(AWidth, AHeight) and
    ((ALeft <> FLeft) or (ATop <> FTop) or
    (AWidth <> FWidth) or (AHeight <> FHeight)) then
  begin
    InvalidateControl(Visible, False);
    FLeft := ALeft;
    FTop := ATop;
    FWidth := AWidth;
    FHeight := AHeight;
    UpdateAnchorRules;
    Invalidate;
    Perform(WM_WINDOWPOSCHANGED, 0, 0);
    RequestAlign;
    if not (csLoading in ComponentState) then Resize;
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
        FAnchorRules.X := Width else
        FAnchorRules.X := Left
    else
      FAnchorRules.X := Left + Width div 2;
    if akBottom in Anchors then
      if akTop in Anchors then
        FAnchorRules.Y := Height else
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

procedure TControl.SetLeft(Value: Integer);
begin
  SetBounds(Value, FTop, FWidth, FHeight);
  Include(FScalingFlags, sfLeft);
end;

procedure TControl.SetTop(Value: Integer);
begin
  SetBounds(FLeft, Value, FWidth, FHeight);
  Include(FScalingFlags, sfTop);
end;

procedure TControl.SetWidth(Value: Integer);
begin
  SetBounds(FLeft, FTop, Value, FHeight);
  Include(FScalingFlags, sfWidth);
end;

procedure TControl.SetHeight(Value: Integer);
begin
  SetBounds(FLeft, FTop, FWidth, Value);
  Include(FScalingFlags, sfHeight);
end;

procedure TControl.Dock(NewDockSite: TWinControl; ARect: TRect);
var
  PrevDockSite: TWinControl;
begin
  if HostDockSite <> NewDockSite then
  begin
    if (FHostDockSite <> nil) and (FHostDockSite.FDockClients <> nil) then
      FHostDockSite.FDockClients.Remove(Self);
    if (NewDockSite <> nil) and (NewDockSite <> NullDockSite) and
      (NewDockSite.FDockClients <> nil) then
      NewDockSite.FDockClients.Add(Self);
  end;
  Include(FControlState, csDocking);
  try
    if NewDockSite <> NullDockSite then
      DoDock(NewDockSite, ARect);
    if FHostDockSite <> NewDockSite then
    begin
      PrevDockSite := FHostDockSite;
      if NewDockSite <> NullDockSite then
      begin
        FHostDockSite := NewDockSite;
        if NewDockSite <> nil then NewDockSite.DoAddDockClient(Self, ARect);
      end
      else
        FHostDockSite := nil;
      if PrevDockSite <> nil then PrevDockSite.DoRemoveDockClient(Self);
    end;
  finally
    Exclude(FControlState, csDocking);
  end;
end;

procedure TControl.DoDock(NewDockSite: TWinControl; var ARect: TRect);
begin
  { Erase TControls before UpdateboundsRect modifies position }
  if not (Self is TWinControl) then InvalidateControl(Visible, False);
  if Parent <> NewDockSite then
    UpdateBoundsRect(ARect) else
    BoundsRect := ARect;
  if (NewDockSite = nil) or (NewDockSite = NullDockSite) then Parent := nil;
end;

procedure TControl.SetHostDockSite(Value: TWinControl);
begin
  Dock(Value, BoundsRect);
end;

function TControl.GetBoundsRect: TRect;
begin
  Result.Left := Left;
  Result.Top := Top;
  Result.Right := Left + Width;
  Result.Bottom := Top + Height;
end;

procedure TControl.SetBoundsRect(const Rect: TRect);
begin
  with Rect do SetBounds(Left, Top, Right - Left, Bottom - Top);
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

procedure TControl.SetClientWidth(Value: Integer);
begin
  SetClientSize(Point(Value, ClientHeight));
end;

function TControl.GetClientHeight: Integer;
begin
  Result := ClientRect.Bottom;
end;

procedure TControl.SetClientHeight(Value: Integer);
begin
  SetClientSize(Point(ClientWidth, Value));
end;

function TControl.GetClientOrigin: TPoint;
begin
  if Parent = nil then
    raise EInvalidOperation.CreateFmt(SParentRequired, [Name]);
  Result := Parent.ClientOrigin;
  Inc(Result.X, FLeft);
  Inc(Result.Y, FTop);
end;

function TControl.ClientToScreen(const Point: TPoint): TPoint;
var
  Origin: TPoint;
begin
  Origin := ClientOrigin;
  Result.X := Point.X + Origin.X;
  Result.Y := Point.Y + Origin.Y;
end;

function TControl.ScreenToClient(const Point: TPoint): TPoint;
var
  Origin: TPoint;
begin
  Origin := ClientOrigin;
  Result.X := Point.X - Origin.X;
  Result.Y := Point.Y - Origin.Y;
end;

procedure TControl.SendCancelMode(Sender: TControl);
var
  Control: TControl;
begin
  Control := Self;
  while Control <> nil do
  begin
    if Control is TCustomForm then
      TCustomForm(Control).SendCancelMode(Sender);
    Control := Control.Parent;
  end;
end;

procedure TControl.SendDockNotification(Msg: Cardinal; WParam, LParam: Integer);
var
  NotifyRec: TDockNotifyRec;
begin
  if (FHostDockSite <> nil) and (DragObject = nil) and
    (ComponentState * [csLoading, csDestroying] = []) then
  begin
    with NotifyRec do
    begin
      ClientMsg := Msg;
      MsgWParam := WParam;
      MsgLParam := LParam;
    end;
    FHostDockSite.Perform(CM_DOCKNOTIFICATION, Integer(Self), Integer(@NotifyRec));
  end;
end;

procedure TControl.Changed;
begin
  Perform(CM_CHANGED, 0, Longint(Self));
end;

procedure TControl.ChangeScale(M, D: Integer);
var
  X, Y, W, H: Integer;
  Flags: TScalingFlags;
begin
  if M <> D then
  begin
    if csLoading in ComponentState then
      Flags := ScalingFlags else
      Flags := [sfLeft, sfTop, sfWidth, sfHeight, sfFont];
    if sfLeft in Flags then
      X := MulDiv(FLeft, M, D) else
      X := FLeft;
    if sfTop in Flags then
      Y := MulDiv(FTop, M, D) else
      Y := FTop;
    if (sfWidth in Flags) and not (csFixedWidth in ControlStyle) then
      if sfLeft in Flags then
        W := MulDiv(FLeft + FWidth, M, D) - X else
        W := MulDiv(FWidth, M, D)
    else W := FWidth;
    if (sfHeight in Flags) and not (csFixedHeight in ControlStyle) then
      if sfHeight in Flags then
        H := MulDiv(FTop + FHeight, M, D) - Y else
        H := MulDiv(FTop, M, D )
    else H := FHeight;
    SetBounds(X, Y, W, H);
    if not ParentFont and (sfFont in Flags) then
      Font.Size := MulDiv(Font.Size, M, D);
  end;
  FScalingFlags := [];
end;

procedure TControl.SetAutoSize(Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    if Value then AdjustSize;
  end;
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

procedure TControl.SetClientSize(Value: TPoint);
var
  Client: TRect;
begin
  Client := GetClientRect;
  SetBounds(FLeft, FTop, Width - Client.Right + Value.X, Height -
    Client.Bottom + Value.Y);
end;

procedure TControl.SetParent(AParent: TWinControl);
begin
  if FParent <> AParent then
  begin
    if AParent = Self then
      raise EInvalidOperation.CreateRes(@SControlParentSetToSelf);
    if FParent <> nil then
      FParent.RemoveControl(Self);
    if AParent <> nil then
    begin
      AParent.InsertControl(Self);
      UpdateAnchorRules;
    end;
  end;
end;

procedure TControl.SetVisible(Value: Boolean);
begin
  if FVisible <> Value then
  begin
    VisibleChanging;
    FVisible := Value;
    Perform(CM_VISIBLECHANGED, Ord(Value), 0);
    RequestAlign;
  end;
end;

procedure TControl.SetEnabled(Value: Boolean);
begin
  if FEnabled <> Value then
  begin
    FEnabled := Value;
    Perform(CM_ENABLEDCHANGED, 0, 0);
  end;
end;

function TControl.GetTextLen: Integer;
begin
  Result := Perform(WM_GETTEXTLENGTH, 0, 0);
end;

function TControl.GetTextBuf(Buffer: PChar; BufSize: Integer): Integer;
begin
  Result := Perform(WM_GETTEXT, BufSize, Longint(Buffer));
end;

function TControl.GetUndockHeight: Integer;
begin
  if FUndockHeight > 0 then Result := FUndockHeight
  else Result := Height;
end;

function TControl.GetUndockWidth: Integer;
begin
  if FUndockWidth > 0 then Result := FUndockWidth
  else Result := Width;
end;

function TControl.GetTBDockHeight: Integer;
begin
  if FTBDockHeight > 0 then Result := FTBDockHeight
  else Result := UndockHeight;
end;

function TControl.GetLRDockWidth: Integer;
begin
  if FLRDockWidth > 0 then Result := FLRDockWidth
  else Result := UndockWidth;
end;

procedure TControl.SetPopupMenu(Value: TPopupMenu);
begin
  FPopupMenu := Value;
  if Value <> nil then
  begin
    Value.ParentBiDiModeChanged(Self);
    Value.FreeNotification(Self);
  end;
end;

procedure TControl.SetTextBuf(Buffer: PChar);
begin
  Perform(WM_SETTEXT, 0, Longint(Buffer));
  Perform(CM_TEXTCHANGED, 0, 0);
end;

function TControl.GetText: TCaption;
var
  Len: Integer;
begin
  Len := GetTextLen;
  SetString(Result, PChar(nil), Len);
  if Len <> 0 then GetTextBuf(Pointer(Result), Len + 1);
end;

procedure TControl.SetText(const Value: TCaption);
begin
  if GetText <> Value then SetTextBuf(PChar(Value));
end;

procedure TControl.SetBiDiMode(Value: TBiDiMode);
begin
  if FBiDiMode <> Value then
  begin
    FBiDiMode := Value;
    FParentBiDiMode := False;
    Perform(CM_BIDIMODECHANGED, 0, 0);
  end;
end;

procedure TControl.FontChanged(Sender: TObject);
begin
  FParentFont := False;
  FDesktopFont := False;
  if Font.Height <> FFontHeight then
  begin
    Include(FScalingFlags, sfFont);
    FFontHeight := Font.Height;
  end;
  Perform(CM_FONTCHANGED, 0, 0);
end;

procedure TControl.SetFont(Value: TFont);
begin
  FFont.Assign(Value);
end;

function TControl.IsFontStored: Boolean;
begin
  Result := not ParentFont and not DesktopFont;
end;

function TControl.IsShowHintStored: Boolean;
begin
  Result := not ParentShowHint;
end;

function TControl.IsBiDiModeStored: Boolean;
begin
  Result := not ParentBiDiMode;
end;

procedure TControl.SetParentFont(Value: Boolean);
begin
  if FParentFont <> Value then
  begin
    FParentFont := Value;
    if FParent <> nil then Perform(CM_PARENTFONTCHANGED, 0, 0);
  end;
end;

procedure TControl.SetDesktopFont(Value: Boolean);
begin
  if FDesktopFont <> Value then
  begin
    FDesktopFont := Value;
    Perform(CM_SYSFONTCHANGED, 0, 0);
  end;
end;

procedure TControl.SetShowHint(Value: Boolean);
begin
  if FShowHint <> Value then
  begin
    FShowHint := Value;
    FParentShowHint := False;
    Perform(CM_SHOWHINTCHANGED, 0, 0);
  end;
end;

procedure TControl.SetParentShowHint(Value: Boolean);
begin
  if FParentShowHint <> Value then
  begin
    FParentShowHint := Value;
    if FParent <> nil then Perform(CM_PARENTSHOWHINTCHANGED, 0, 0);
  end;
end;

procedure TControl.SetColor(Value: TColor);
begin
  if FColor <> Value then
  begin
    FColor := Value;
    FParentColor := False;
    Perform(CM_COLORCHANGED, 0, 0);
  end;
end;

function TControl.IsColorStored: Boolean;
begin
  Result := not ParentColor;
end;

procedure TControl.SetParentColor(Value: Boolean);
begin
  if FParentColor <> Value then
  begin
    FParentColor := Value;
    if FParent <> nil then Perform(CM_PARENTCOLORCHANGED, 0, 0);
  end;
end;

procedure TControl.SetParentBiDiMode(Value: Boolean);
begin
  if FParentBiDiMode <> Value then
  begin
    FParentBiDiMode := Value;
    if FParent <> nil then Perform(CM_PARENTBIDIMODECHANGED, 0, 0);
  end;
end;

procedure TControl.SetCursor(Value: TCursor);
begin
  if FCursor <> Value then
  begin
    FCursor := Value;
    Perform(CM_CURSORCHANGED, 0, 0);
  end;
end;

function TControl.GetMouseCapture: Boolean;
begin
  Result := GetCaptureControl = Self;
end;

procedure TControl.SetMouseCapture(Value: Boolean);
begin
  if MouseCapture <> Value then
    if Value then SetCaptureControl(Self) else SetCaptureControl(nil);
end;

procedure TControl.BringToFront;
begin
  SetZOrder(True);
end;

procedure TControl.SendToBack;
begin
  SetZOrder(False);
end;

procedure TControl.SetZOrderPosition(Position: Integer);
var
  I, Count: Integer;
  ParentForm: TCustomForm;
begin
  if FParent <> nil then
  begin
    I := FParent.FControls.IndexOf(Self);
    if I >= 0 then
    begin
      Count := FParent.FControls.Count;
      if Position < 0 then Position := 0;
      if Position >= Count then Position := Count - 1;
      if Position <> I then
      begin
        FParent.FControls.Delete(I);
        FParent.FControls.Insert(Position, Self);
        InvalidateControl(Visible, True);
        ParentForm := ValidParentForm(Self);
        if csPalette in ParentForm.ControlState then
          TControl(ParentForm).PaletteChanged(True);
      end;
    end;
  end;
end;

procedure TControl.SetZOrder(TopMost: Boolean);
begin
  if FParent <> nil then
    if TopMost then
      SetZOrderPosition(FParent.FControls.Count - 1) else
      SetZOrderPosition(0);
end;

function TControl.GetDeviceContext(var WindowHandle: HWnd): HDC;
begin
  if Parent = nil then
    raise EInvalidOperation.CreateFmt(SParentRequired, [Name]);
  Result := Parent.GetDeviceContext(WindowHandle);
  SetViewportOrgEx(Result, Left, Top, nil);
  IntersectClipRect(Result, 0, 0, Width, Height);
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
    InvalidateRect(Parent.Handle, @Rect, not (IsOpaque or
      (csOpaque in Parent.ControlStyle) or BackgroundClipped));
  end;
end;

procedure TControl.Invalidate;
begin
  InvalidateControl(Visible, csOpaque in ControlStyle);
end;

procedure TControl.Hide;
begin
  Visible := False;
end;

procedure TControl.Show;
begin
  if Parent <> nil then Parent.ShowControl(Self);
  if not (csDesigning in ComponentState) or
    (csNoDesignVisible in ControlStyle) then Visible := True;
end;

procedure TControl.Update;
begin
  if Parent <> nil then Parent.Update;
end;

procedure TControl.Refresh;
begin
  Repaint;
end;

procedure TControl.Repaint;
var
  DC: HDC;
begin
  if (Visible or (csDesigning in ComponentState) and
    not (csNoDesignVisible in ControlStyle)) and (Parent <> nil) and
    Parent.HandleAllocated then
    if csOpaque in ControlStyle then
    begin
      DC := GetDC(Parent.Handle);
      try
        IntersectClipRect(DC, Left, Top, Left + Width, Top + Height);
        Parent.PaintControls(DC, Self);
      finally
        ReleaseDC(Parent.Handle, DC);
      end;
    end else
    begin
      Invalidate;
      Update;
    end;
end;

function TControl.GetControlsAlignment: TAlignment;
begin
  Result := taLeftJustify;
end;

function TControl.IsRightToLeft: Boolean;
begin
  Result := SysLocale.MiddleEast and (BiDiMode <> bdLeftToRight);
end;

function TControl.UseRightToLeftReading: Boolean;
begin
  Result := SysLocale.MiddleEast and (BiDiMode <> bdLeftToRight);
end;

function TControl.UseRightToLeftAlignment: Boolean;
begin
  Result := SysLocale.MiddleEast and (BiDiMode = bdRightToLeft);
end;

function TControl.UseRightToLeftScrollBar: Boolean;
begin
  Result := SysLocale.MiddleEast and
    (BiDiMode in [bdRightToLeft, bdRightToLeftNoAlign]);
end;

procedure TControl.BeginAutoDrag;
begin
  BeginDrag(Mouse.DragImmediate, Mouse.DragThreshold);
end;

procedure TControl.BeginDrag(Immediate: Boolean; Threshold: Integer);
var
  P: TPoint;
begin
  if (Self is TCustomForm) and (FDragKind <> dkDock) then
    raise EInvalidOperation.CreateRes(@SCannotDragForm);
  CalcDockSizes;
  if (DragControl = nil) or (DragControl = Pointer($FFFFFFFF)) then
  begin
    DragControl := nil;
    if csLButtonDown in ControlState then
    begin
      GetCursorPos(P);
      P := ScreenToClient(P);
      Perform(WM_LBUTTONUP, 0, Longint(PointToSmallPoint(P)));
    end;
    { Use default value when Threshold < 0 }
    if Threshold < 0 then
      Threshold := Mouse.DragThreshold;
    // prevent calling EndDrag within BeginDrag
    if DragControl <> Pointer($FFFFFFFF) then
      DragInitControl(Self, Immediate, Threshold);
  end;
end;

procedure TControl.EndDrag(Drop: Boolean);
begin
  if Dragging then DragDone(Drop)
  // prevent calling EndDrag within BeginDrag
  else if DragControl = nil then DragControl := Pointer($FFFFFFFF);
end;

procedure TControl.DragCanceled;
begin
end;

function TControl.Dragging: Boolean;
begin
  Result := DragControl = Self;
end;

procedure TControl.DragOver(Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  Accept := False;
  if Assigned(FOnDragOver) then
  begin
    Accept := True;
    FOnDragOver(Self, Source, X, Y, State, Accept);
  end;
end;

procedure TControl.DragDrop(Source: TObject; X, Y: Integer);
begin
  if Assigned(FOnDragDrop) then FOnDragDrop(Self, Source, X, Y);
end;

procedure TControl.DoStartDrag(var DragObject: TDragObject);
begin
  if Assigned(FOnStartDrag) then FOnStartDrag(Self, DragObject);
end;

procedure TControl.DoEndDrag(Target: TObject; X, Y: Integer);
begin
  if Assigned(FOnEndDrag) then FOnEndDrag(Self, Target, X, Y);
end;

procedure TControl.PositionDockRect(DragDockObject: TDragDockObject);
var
  NewWidth, NewHeight: Integer;
  TempX, TempY: Double;
begin
  with DragDockObject do
  begin
    if (DragTarget = nil) or (not TWinControl(DragTarget).UseDockManager) then
    begin
      NewWidth := Control.UndockWidth;
      NewHeight := Control.UndockHeight;
      // Drag position for dock rect is scaled relative to control's click point.
      TempX := DragPos.X - ((NewWidth) * FMouseDeltaX);
      TempY := DragPos.Y - ((NewHeight) * FMouseDeltaY);
      with FDockRect do
      begin
        Left := Round(TempX);
        Top := Round(TempY);
        Right := Left + NewWidth;
        Bottom := Top + NewHeight;
      end;
      { Allow DragDockObject final say on this new dock rect }
      AdjustDockRect(FDockRect);
    end
    else begin
      GetWindowRect(TWinControl(DragTarget).Handle, FDockRect);
      if TWinControl(DragTarget).UseDockManager and
        (TWinControl(DragTarget).DockManager <> nil) then
        TWinControl(DragTarget).DockManager.PositionDockRect(Control,
          DropOnControl, DropAlign, FDockRect);
    end;
  end;
end;

procedure TControl.DockTrackNoTarget(Source: TDragDockObject; X, Y: Integer);
begin
  PositionDockRect(Source);
end;

procedure TControl.DoEndDock(Target: TObject; X, Y: Integer);
begin
  if Assigned(FOnEndDock) then FOnEndDock(Self, Target, X, Y);
end;

procedure TControl.DoStartDock(var DragObject: TDragObject);
begin
  if Assigned(FOnStartDock) then FOnStartDock(Self, TDragDockObject(DragObject));
end;

procedure TControl.DefaultDockImage(DragDockObject: TDragDockObject;
  Erase: Boolean);
var
  DesktopWindow: HWND;
  DC: HDC;
  OldBrush: HBrush;
  DrawRect: TRect;
  PenSize: Integer;
begin
  with DragDockObject do
  begin
    PenSize := FrameWidth;
    if Erase then DrawRect := FEraseDockRect
    else DrawRect := FDockRect;
  end;
  DesktopWindow := GetDesktopWindow;
  DC := GetDCEx(DesktopWindow, 0, DCX_CACHE or DCX_LOCKWINDOWUPDATE);
  try
    OldBrush := SelectObject(DC, DragDockObject.Brush.Handle);
    with DrawRect do
    begin
      PatBlt(DC, Left + PenSize, Top, Right - Left - PenSize, PenSize, PATINVERT);
      PatBlt(DC, Right - PenSize, Top + PenSize, PenSize, Bottom - Top - PenSize, PATINVERT);
      PatBlt(DC, Left, Bottom - PenSize, Right - Left - PenSize, PenSize, PATINVERT);
      PatBlt(DC, Left, Top, PenSize, Bottom - Top - PenSize, PATINVERT);
    end;
    SelectObject(DC, OldBrush);
  finally
    ReleaseDC(DesktopWindow, DC);
  end;
end;

procedure TControl.DrawDragDockImage(DragDockObject: TDragDockObject);
begin
  DefaultDockImage(DragDockObject, False);
end;

procedure TControl.EraseDragDockImage(DragDockObject: TDragDockObject);
begin
  DefaultDockImage(DragDockObject, True);
end;

procedure TControl.DoDragMsg(var DragMsg: TCMDrag);
var
  S: TObject;
  Accepts, IsDockOp: Boolean;
begin
  with DragMsg, DragRec^ do
  begin
    S := Source;
    IsDockOp := S is TDragDockObject;
    if DragFreeObject and not IsDockOp then
      S := (S as TDragControlObject).Control;
    with ScreenToClient(Pos) do
      case DragMessage of
        dmDragEnter, dmDragLeave, dmDragMove:
          begin
            Accepts := True;
            if IsDockOp then
            begin
              TWinControl(Target).DockOver(TDragDockObject(S), X, Y,
                TDragState(DragMessage), Accepts)
            end
            else
              DragOver(S, X, Y, TDragState(DragMessage), Accepts);
            Result := Ord(Accepts);
          end;
        dmDragDrop:
          begin
            if IsDockOp then TWinControl(Target).DockDrop(TDragDockObject(S), X, Y)
            else DragDrop(S, X, Y);
          end;
      end;
  end;
end;

function TControl.ManualDock(NewDockSite: TWinControl; DropControl: TControl;
  ControlSide: TAlign): Boolean;
var
  R: TRect;
  DockObject: TDragDockObject;
  HostDockSiteHandle: THandle;
begin
  if (NewDockSite = nil) or (NewDockSite = NullDockSite) then
  begin
    if (HostDockSite <> nil) and HostDockSite.UseDockManager and
      (HostDockSite.DockManager <> nil) then
    begin
      HostDockSite.DockManager.GetControlBounds(Self, R);
      MapWindowPoints(HostDockSite.Handle, 0, R.TopLeft, 2);
    end
    else begin
      R.TopLeft := Point(Left, Top);
      if Parent <> nil then R.TopLeft := Parent.ClientToScreen(R.TopLeft);
    end;
    R := Bounds(R.Left, R.Top, UndockWidth, UndockHeight);
    Result := ManualFloat(R);
  end
  else
  begin
    CalcDockSizes;
    Result := (HostDockSite = nil) or HostDockSite.DoUndock(NewDockSite, Self);
    if Result then
    begin
      DockObject := TDragDockObject.Create(Self);
      try
        if HostDockSite <> nil then
          HostDockSiteHandle := HostDockSite.Handle else
          HostDockSiteHandle := 0;
        R := BoundsRect;
        if HostDockSiteHandle <> 0 then
          MapWindowPoints(HostDockSiteHandle, 0, R, 2);
        with DockObject do
        begin
          FDragTarget := NewDockSite;
          FDropAlign := ControlSide;
          FDropOnControl := DropControl;
          DockRect := R;
        end;
        MapWindowPoints(0, NewDockSite.Handle, R.TopLeft, 1);
        NewDockSite.DockDrop(DockObject, R.Left, R.Top);
      finally
        DockObject.Free;
      end;
    end;
  end;
end;

function TControl.ManualFloat(ScreenPos: TRect): Boolean;
var
  FloatHost: TWinControl;
begin
  Result := (HostDockSite = nil) or HostDockSite.DoUndock(nil, Self);
  if Result then
  begin
    FloatHost := CreateFloatingDockSite(ScreenPos);
    if FloatHost <> nil then
      Dock(FloatHost, Rect(0, 0, FloatHost.ClientWidth, FloatHost.ClientHeight))
    else
      Dock(FloatHost, ScreenPos);
  end;
end;

function TControl.ReplaceDockedControl(Control: TControl;
  NewDockSite: TWinControl; DropControl: TControl; ControlSide: TAlign): Boolean;
var
  OldDockSite: TWinControl;
begin
  Result := False;
  if (Control.HostDockSite = nil) or ((Control.HostDockSite.UseDockManager) and
    (Control.HostDockSite.DockManager <> nil)) then
  begin
    OldDockSite := Control.HostDockSite;
    if OldDockSite <> nil then
      OldDockSite.DockManager.SetReplacingControl(Control);
    try
      ManualDock(OldDockSite, nil, alTop);
    finally
      if OldDockSite <> nil then
        OldDockSite.DockManager.SetReplacingControl(nil);
    end;
    if Control.ManualDock(NewDockSite, DropControl, ControlSide) then
      Result := True;
  end;
end;

procedure TControl.DoConstraintsChange(Sender: TObject);
begin
  AdjustSize;
end;

function TControl.CanAutoSize(var NewWidth, NewHeight: Integer): Boolean;
begin
  Result := True;
end;

function TControl.CanResize(var NewWidth, NewHeight: Integer): Boolean;
begin
  Result := True;
  if Assigned(FOnCanResize) then FOnCanResize(Self, NewWidth, NewHeight, Result);
end;

function TControl.DoCanAutoSize(var NewWidth, NewHeight: Integer): Boolean;
var
  W, H: Integer;
begin
  if Align <> alClient then
  begin
    W := NewWidth;
    H := NewHeight;
    Result := CanAutoSize(W, H);
    if Align in [alNone, alLeft, alRight] then
      NewWidth := W;
    if Align in [alNone, alTop, alBottom] then
      NewHeight := H;
  end
  else Result := True;
end;

function TControl.DoCanResize(var NewWidth, NewHeight: Integer): Boolean;
begin
  Result := CanResize(NewWidth, NewHeight);
  if Result then DoConstrainedResize(NewWidth, NewHeight);
end;

procedure TControl.ConstrainedResize(var MinWidth, MinHeight, MaxWidth,
  MaxHeight: Integer);
begin
  if Assigned(FOnConstrainedResize) then FOnConstrainedResize(Self, MinWidth,
    MinHeight, MaxWidth, MaxHeight);
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

function TControl.Perform(Msg: Cardinal; WParam, LParam: Longint): Longint;
var
  Message: TMessage;
begin
  Message.Msg := Msg;
  Message.WParam := WParam;
  Message.LParam := LParam;
  Message.Result := 0;
  if Self <> nil then WindowProc(Message);
  Result := Message.Result;
end;

procedure TControl.CalcDockSizes;
begin
  if Floating then
  begin
    UndockHeight := Height;
    UndockWidth := Width;
  end
  else if HostDockSite <> nil then
  begin
    if (DockOrientation = doVertical) or
      (HostDockSite.Align in [alTop, alBottom]) then
      TBDockHeight := Height
    else if (DockOrientation = doHorizontal) or
      (HostDockSite.Align in [alLeft, alRight]) then
      LRDockWidth := Width;
  end;
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
end;

procedure TControl.WndProc(var Message: TMessage);
var
  Form: TCustomForm;
begin
  if (csDesigning in ComponentState) then
  begin
    Form := GetParentForm(Self);
    if (Form <> nil) and (Form.Designer <> nil) and
      Form.Designer.IsDesignMsg(Self, Message) then Exit;
  end
  else if (Message.Msg >= WM_KEYFIRST) and (Message.Msg <= WM_KEYLAST) then
  begin
    Form := GetParentForm(Self);
    if (Form <> nil) and Form.WantChildKey(Self, Message) then Exit;
  end
  else if (Message.Msg >= WM_MOUSEFIRST) and (Message.Msg <= WM_MOUSELAST) then
  begin
    if not (csDoubleClicks in ControlStyle) then
      case Message.Msg of
        WM_LBUTTONDBLCLK, WM_RBUTTONDBLCLK, WM_MBUTTONDBLCLK:
          Dec(Message.Msg, WM_LBUTTONDBLCLK - WM_LBUTTONDOWN);
      end;
    case Message.Msg of
      WM_MOUSEMOVE: Application.HintMouseMessage(Self, Message);
      WM_LBUTTONDOWN, WM_LBUTTONDBLCLK:
        begin
          if FDragMode = dmAutomatic then
          begin
            BeginAutoDrag;
            Exit;
          end;
          Include(FControlState, csLButtonDown);
        end;
      WM_LBUTTONUP:
        Exclude(FControlState, csLButtonDown);
    end;
  end
  else if Message.Msg = CM_VISIBLECHANGED then
    with Message do
      SendDockNotification(Msg, WParam, LParam);
  Dispatch(Message);
end;

procedure TControl.DefaultHandler(var Message);
var
  P: PChar;
begin
  with TMessage(Message) do
    case Msg of
      WM_GETTEXT:
        begin
          if FText <> nil then P := FText else P := '';
          Result := StrLen(StrLCopy(PChar(LParam), P, WParam - 1));
        end;
      WM_GETTEXTLENGTH:
        if FText = nil then Result := 0 else Result := StrLen(FText);
      WM_SETTEXT:
        begin
          P := StrNew(PChar(LParam));
          StrDispose(FText);
          FText := P;
          SendDockNotification(Msg, WParam, LParam);
        end;
    end;
end;

procedure TControl.ReadIsControl(Reader: TReader);
begin
  FIsControl := Reader.ReadBoolean;
end;

procedure TControl.WriteIsControl(Writer: TWriter);
begin
  Writer.WriteBoolean(FIsControl);
end;

procedure TControl.DefineProperties(Filer: TFiler);

  function DoWrite: Boolean;
  begin
    if Filer.Ancestor <> nil then
      Result := TControl(Filer.Ancestor).IsControl <> IsControl else
      Result := IsControl;
  end;

begin
  { The call to inherited DefinedProperties is omitted since the Left and
    Top special properties are redefined with real properties }
  Filer.DefineProperty('IsControl', ReadIsControl, WriteIsControl, DoWrite);
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

procedure TControl.DblClick;
begin
  if Assigned(FOnDblClick) then FOnDblClick(Self);
end;

procedure TControl.MouseDown(Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if Assigned(FOnMouseDown) then FOnMouseDown(Self, Button, Shift, X, Y);
end;

procedure TControl.DoMouseDown(var Message: TWMMouse; Button: TMouseButton;
  Shift: TShiftState);
begin
  if not (csNoStdEvents in ControlStyle) then
    with Message do
      MouseDown(Button, KeysToShiftState(Keys) + Shift, XPos, YPos);
end;

procedure TControl.WMLButtonDown(var Message: TWMLButtonDown);
begin
  SendCancelMode(Self);
  inherited;
  if csCaptureMouse in ControlStyle then MouseCapture := True;
  if csClickEvents in ControlStyle then Include(FControlState, csClicked);
  DoMouseDown(Message, mbLeft, []);
end;

procedure TControl.WMNCLButtonDown(var Message: TWMNCLButtonDown);
begin
  SendCancelMode(Self);
  inherited;
end;

procedure TControl.WMLButtonDblClk(var Message: TWMLButtonDblClk);
begin
  SendCancelMode(Self);
  inherited;
  if csCaptureMouse in ControlStyle then MouseCapture := True;
  if csClickEvents in ControlStyle then DblClick;
  DoMouseDown(Message, mbLeft, [ssDouble]);
end;

function TControl.GetPopupMenu: TPopupMenu;
begin
  Result := FPopupMenu;
end;

function TControl.CheckNewSize(var NewWidth, NewHeight: Integer): Boolean;
var
  W, H, W2, H2: Integer;
begin
  Result := False;
  W := NewWidth;
  H := NewHeight;
  if DoCanResize(W, H) then
  begin
    W2 := W;
    H2 := H;
    Result := not AutoSize or (DoCanAutoSize(W2, H2) and (W2 = W) and (H2 = H)) or
      DoCanResize(W2, H2);
    if Result then
    begin
      NewWidth := W2;
      NewHeight := H2;
    end;
  end;
end;

procedure TControl.WMRButtonDown(var Message: TWMRButtonDown);
begin
  inherited;
  DoMouseDown(Message, mbRight, []);
end;

procedure TControl.WMRButtonDblClk(var Message: TWMRButtonDblClk);
begin
  inherited;
  DoMouseDown(Message, mbRight, [ssDouble]);
end;

procedure TControl.WMMButtonDown(var Message: TWMMButtonDown);
begin
  inherited;
  DoMouseDown(Message, mbMiddle, []);
end;

procedure TControl.WMMButtonDblClk(var Message: TWMMButtonDblClk);
begin
  inherited;
  DoMouseDown(Message, mbMiddle, [ssDouble]);
end;

procedure TControl.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  if Assigned(FOnMouseMove) then FOnMouseMove(Self, Shift, X, Y);
end;

procedure TControl.WMMouseMove(var Message: TWMMouseMove);
begin
  inherited;
  if not (csNoStdEvents in ControlStyle) then
    with Message do MouseMove(KeysToShiftState(Keys), XPos, YPos);
end;

procedure TControl.MouseUp(Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if Assigned(FOnMouseUp) then FOnMouseUp(Self, Button, Shift, X, Y);
end;

procedure TControl.DoMouseUp(var Message: TWMMouse; Button: TMouseButton);
begin
  if not (csNoStdEvents in ControlStyle) then
    with Message do MouseUp(Button, KeysToShiftState(Keys), XPos, YPos);
end;

procedure TControl.WMLButtonUp(var Message: TWMLButtonUp);
begin
  inherited;
  if csCaptureMouse in ControlStyle then MouseCapture := False;
  if csClicked in ControlState then
  begin
    Exclude(FControlState, csClicked);
    if PtInRect(ClientRect, SmallPointToPoint(Message.Pos)) then Click;
  end;
  DoMouseUp(Message, mbLeft);
end;

procedure TControl.WMRButtonUp(var Message: TWMRButtonUp);
begin
  inherited;
  DoMouseUp(Message, mbRight);
end;

procedure TControl.WMMButtonUp(var Message: TWMMButtonUp);
begin
  inherited;
  DoMouseUp(Message, mbMiddle);
end;

procedure TControl.WMCancelMode(var Message: TWMCancelMode);
begin
  inherited;
  if MouseCapture then
  begin
    MouseCapture := False;
    if csLButtonDown in ControlState then Perform(WM_LBUTTONUP, 0,
      Integer($FFFFFFFF));
  end
  else
    Exclude(FControlState, csLButtonDown);
end;

procedure TControl.WMWindowPosChanged(var Message: TWMWindowPosChanged);
begin
  inherited;
  { Update min/max width/height to actual extents control will allow }
  if ComponentState * [csReading, csLoading] = [] then
  begin
    with Constraints do
    begin
      if (MaxWidth > 0) and (Width > MaxWidth) then
        FMaxWidth := Width
      else if (MinWidth > 0) and (Width < MinWidth) then
        FMinWidth := Width;
      if (MaxHeight > 0) and (Height > MaxHeight) then
        FMaxHeight := Height
      else if (MinHeight > 0) and (Height < MinHeight) then
        FMinHeight := Height;
    end;
    if Message.WindowPos <> nil then
      with Message.WindowPos^ do
        if (FHostDockSite <> nil) and not (csDocking in ControlState)  and
          (Flags and SWP_NOSIZE = 0) and (cx <> 0) and (cy <> 0) then
          CalcDockSizes;
  end;
end;

procedure TControl.CMVisibleChanged(var Message: TMessage);
begin
  if not (csDesigning in ComponentState) or
    (csNoDesignVisible in ControlStyle) then
    InvalidateControl(True, FVisible and (csOpaque in ControlStyle));
end;

procedure TControl.CMEnabledChanged(var Message: TMessage);
begin
  Invalidate;
end;

procedure TControl.CMFontChanged(var Message: TMessage);
begin
  Invalidate;
end;

procedure TControl.CMColorChanged(var Message: TMessage);
begin
  Invalidate;
end;

procedure TControl.CMParentColorChanged(var Message: TMessage);
begin
  if FParentColor then
  begin
    if Message.wParam <> 0 then
      SetColor(TColor(Message.lParam)) else
      SetColor(FParent.FColor);
    FParentColor := True;
  end;
end;

procedure TControl.CMParentBiDiModeChanged(var Message: TMessage);
begin
  if FParentBiDiMode then
  begin
    if FParent <> nil then BiDiMode := FParent.BiDiMode;
    FParentBiDiMode := True;
  end;
end;

procedure TControl.CMBiDiModeChanged(var Message: TMessage);
begin
  if (SysLocale.MiddleEast) and (Message.wParam = 0) then Invalidate;
end;

procedure TControl.CMParentShowHintChanged(var Message: TMessage);
begin
  if FParentShowHint then
  begin
    SetShowHint(FParent.FShowHint);
    FParentShowHint := True;
  end;
end;

procedure TControl.CMParentFontChanged(var Message: TMessage);
begin
  if FParentFont then
  begin
    if Message.wParam <> 0 then
      SetFont(TFont(Message.lParam)) else
      SetFont(FParent.FFont);
    FParentFont := True;
  end;
end;

procedure TControl.CMSysFontChanged(var Message: TMessage);
begin
  if FDesktopFont then
  begin
    SetFont(Screen.IconFont);
    FDesktopFont := True;
  end;
end;

procedure TControl.CMHitTest(var Message: TCMHitTest);
begin
  Message.Result := HTCLIENT;
end;

procedure TControl.CMMouseEnter(var Message: TMessage);
begin
  if FParent <> nil then
    FParent.Perform(CM_MOUSEENTER, 0, Longint(Self));
end;

procedure TControl.CMMouseLeave(var Message: TMessage);
begin
  if FParent <> nil then
    FParent.Perform(CM_MOUSELEAVE, 0, Longint(Self));
end;

procedure TControl.CMDesignHitTest(var Message: TCMDesignHitTest);
begin
  Message.Result := 0;
end;

function TControl.CreateFloatingDockSite(Bounds: TRect): TWinControl;
begin
  Result := nil;
  if (FloatingDockSiteClass <> nil) and
    (FloatingDockSiteClass <> TWinControlClass(ClassType)) then
  begin
    Result := FloatingDockSiteClass.Create(Application);
    with Bounds do
    begin
      Result.Top := Top;
      Result.Left := Left;
      Result.ClientWidth := Right - Left;
      Result.ClientHeight := Bottom - Top;
    end;
  end;
end;

procedure TControl.CMFloat(var Message: TCMFloat);
var
  FloatHost: TWinControl;

  procedure UpdateFloatingDockSitePos;
  var
    P: TPoint;
  begin
    P := Parent.ClientToScreen(Point(Left, Top));
    with Message.DockSource.DockRect do
      Parent.BoundsRect := Bounds(Left + Parent.Left - P.X,
        Top + Parent.Top - P.Y,
        Right - Left + Parent.Width - Width,
        Bottom - Top + Parent.Height - Height);
  end;

begin
  if Floating and (Parent <> nil) then
    UpdateFloatingDockSitePos
  else
  begin
    FloatHost := CreateFloatingDockSite(Message.DockSource.DockRect);
    if FloatHost <> nil then
    begin
      Message.DockSource.DragTarget := FloatHost;
      Message.DockSource.DragHandle := FloatHost.Handle;
    end;
  end;
end;

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

procedure TControl.DoActionChange(Sender: TObject);
begin
  if Sender = Action then ActionChange(Sender, False);
end;

function TControl.GetActionLinkClass: TControlActionLinkClass;
begin
  Result := TControlActionLink;
end;

function TControl.IsCaptionStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsCaptionLinked;
end;

function TControl.IsEnabledStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsEnabledLinked;
end;

function TControl.IsHintStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsHintLinked;
end;

function TControl.IsVisibleStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsVisibleLinked;
end;

function TControl.IsOnClickStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsOnExecuteLinked;
end;

procedure TControl.Loaded;
begin
  inherited Loaded;
  if Action <> nil then ActionChange(Action, True);
  UpdateAnchorRules;
end;

procedure TControl.AssignTo(Dest: TPersistent);
begin
  if Dest is TCustomAction then
    with TCustomAction(Dest) do
    begin
      Enabled := Self.Enabled;
      Hint := Self.Hint;
      Caption := Self.Caption;
      Visible := Self.Visible;
      OnExecute := Self.OnClick;
    end
  else inherited AssignTo(Dest);
end;

function TControl.GetDockEdge(MousePos: TPoint): TAlign;

  function MinVar(const Data: array of Double): Integer;
  var
    I: Integer;
  begin
    Result := 0;
    for I := Low(Data) + 1 to High(Data) do
      if Data[I] < Data[Result] then Result := I;
  end;

var
  T, L, B, R: Integer;
begin
  Result := alNone;
  R := Width;
  B := Height;
  // if Point is outside control, then we can determine side quickly
  if MousePos.X <= 0 then Result := alLeft
  else if MousePos.X >= R then Result := alRight
  else if MousePos.Y <= 0 then Result := alTop
  else if MousePos.Y >= B then Result := alBottom
  else begin
    // if MousePos is inside the control, then we need to figure out which side
    // MousePos is closest to.
    T := MousePos.Y;
    B := B - MousePos.Y;
    L := MousePos.X;
    R := R - MousePos.X;
    case MinVar([L, R, T, B]) of
      0: Result := alLeft;
      1: Result := alRight;
      2: Result := alTop;
      3: Result := alBottom;
    end;
  end;
end;

function TControl.GetFloating: Boolean;
begin
  Result := (HostDockSite <> nil) and (HostDockSite is FloatingDockSiteClass);
end;

function TControl.GetFloatingDockSiteClass: TWinControlClass;
begin
  Result := FFloatingDockSiteClass;
end;

procedure TControl.AdjustSize;
begin
  if not (csLoading in ComponentState) then SetBounds(Left, Top, Width, Height);
end;

function TControl.DrawTextBiDiModeFlags(Flags: Longint): Longint;
begin
  Result := Flags;
  { do not change center alignment }
  if UseRightToLeftAlignment then
    if Result and DT_RIGHT = DT_RIGHT then
      Result := Result and not DT_RIGHT { removing DT_RIGHT, makes it DT_LEFT }
    else if not (Result and DT_CENTER = DT_CENTER) then
      Result := Result or DT_RIGHT;
  Result := Result or DrawTextBiDiModeFlagsReadingOnly;
end;

function TControl.DrawTextBiDiModeFlagsReadingOnly: Longint;
begin
  if UseRightToLeftReading then
    Result := DT_RTLREADING
  else
    Result := 0;
end;

procedure TControl.InitiateAction;
begin
  if ActionLink <> nil then ActionLink.Update;
end;

procedure TControl.CMHintShow(var Message: TMessage);
begin
  if (ActionLink <> nil) and
    not ActionLink.DoShowHint(TCMHintShow(Message).HintInfo^.HintStr) then
    Message.Result := 1;
end;

procedure TControl.WMContextMenu(var Message: TWMContextMenu);
var
  Pt, Temp: TPoint;
  Handled: Boolean;
  PopupMenu: TPopupMenu;
begin
  if Message.Result <> 0 then Exit;
  if csDesigning in ComponentState then Exit;

  Pt := SmallPointToPoint(Message.Pos);
  if Pt.X < 0 then
    Temp := Pt
  else
  begin
    Temp := ScreenToClient(Pt);
    if not PtInRect(ClientRect, Temp) then
    begin
      inherited;
      Exit;
    end;
  end;

  Handled := False;
  DoContextPopup(Temp, Handled);
  Message.Result := Ord(Handled);
  if Handled then Exit;

  PopupMenu := GetPopupMenu;
  if (PopupMenu <> nil) and PopupMenu.AutoPopup then
  begin
    SendCancelMode(nil);
    PopupMenu.PopupComponent := Self;
    if Pt.X < 0 then
      Pt := ClientToScreen(Point(0,0));
    PopupMenu.Popup(Pt.X, Pt.Y);
    Message.Result := 1;
  end;

  if Message.Result = 0 then
    inherited;
end;

procedure TControl.DoContextPopup(MousePos: TPoint; var Handled: Boolean);
begin
  if Assigned(FOnContextPopup) then FOnContextPopup(Self, MousePos, Handled);
end;

{ TWinControlActionLink }

procedure TWinControlActionLink.AssignClient(AClient: TObject);
begin
  inherited AssignClient(AClient);
  FClient := AClient as TWinControl;
end;

function TWinControlActionLink.IsHelpContextLinked: Boolean;
begin
  Result := inherited IsHelpContextLinked and
    (FClient.HelpContext = (Action as TCustomAction).HelpContext);
end;

procedure TWinControlActionLink.SetHelpContext(Value: THelpContext);
begin
  if IsHelpContextLinked then FClient.HelpContext := Value
end;

{ TWinControl }

constructor TWinControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FObjectInstance := MakeObjectInstance(MainWndProc);
  FBrush := TBrush.Create;
  FBrush.Color := FColor;
  FParentCtl3D := True;
  FTabOrder := -1;
  FImeMode := imDontCare;
  if SysLocale.PriLangID = LANG_JAPANESE then
    FImeName := ''
  else
    FImeName := Screen.DefaultIme;
  FUseDockManager := False;
  FBevelEdges := [beLeft, beTop, beRight, beBottom];
  FBevelInner := bvRaised;
  FBevelOuter := bvLowered;
  FBevelWidth := 1;
end;

constructor TWinControl.CreateParented(ParentWindow: HWnd);
begin
  FParentWindow := ParentWindow;
  Create(nil);
end;

class function TWinControl.CreateParentedControl(ParentWindow: HWnd): TWinControl;
begin
  Result := TWinControl(NewInstance);
  Result.FParentWindow := ParentWindow;
  Result.Create(nil);
end;

destructor TWinControl.Destroy;
var
  I: Integer;
  Instance: TControl;
begin
  Destroying;
  if FDockSite then
  begin
    FDockSite := False;
    RegisterDockSite(Self, False);
  end;
  FDockManager := nil;
  FDockClients.Free;
  if Parent <> nil then RemoveFocus(True);
  if FHandle <> 0 then DestroyWindowHandle;
  I := ControlCount;
  while I <> 0 do
  begin
    Instance := Controls[I - 1];
    Remove(Instance);
    Instance.Destroy;
    I := ControlCount;
  end;
  FBrush.Free;
  if FObjectInstance <> nil then FreeObjectInstance(FObjectInstance);
  inherited Destroy;
end;

procedure TWinControl.FixupTabList;
var
  Count, I, J: Integer;
  List: TList;
  Control: TWinControl;
begin
  if FWinControls <> nil then
  begin
    List := TList.Create;
    try
      Count := FWinControls.Count;
      List.Count := Count;
      for I := 0 to Count - 1 do
      begin
        Control := FWinControls[I];
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

procedure TWinControl.ReadState(Reader: TReader);
begin
  DisableAlign;
  try
    inherited ReadState(Reader);
  finally
    EnableAlign;
  end;
  FixupTabList;
  if FParent <> nil then Perform(CM_PARENTCTL3DCHANGED, 0, 0);
  UpdateControlState;
end;

procedure TWinControl.AdjustClientRect(var Rect: TRect);
begin
  { WM_NCCALCSIZE performs our BorderWidth logic }
end;

procedure TWinControl.AlignControls(AControl: TControl; var Rect: TRect);
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
              SetBounds(NewLeft, NewTop, NewWidth, NewHeight);
            finally
              FAnchorMove := False;
            end;
          end;
        if AAlign = alNone then Exit;
      end;

      NewWidth := Right - Left;
      if (NewWidth < 0) or (AAlign in [alLeft, alRight]) then
        NewWidth := Control.Width;
      NewHeight := Bottom - Top;
      if (NewHeight < 0) or (AAlign in [alTop, alBottom]) then
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
      end;
    end;
    Control.FAnchorMove := True;
    try
      Control.SetBounds(NewLeft, NewTop, NewWidth, NewHeight);
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
  if FDockSite and FUseDockManager and (FDockManager <> nil) then
    FDockManager.ResetBounds(False);
  { D5 VCL Change (ME): Aligned controls that are not dock clients now
    get realigned.  Previously the code below was "else if AlignWork". }
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
      DoAlign(alNone);// Move anchored controls
    finally
      AlignList.Free;
    end;
  end;
  { Apply any constraints }
  if Showing then AdjustSize;
end;

procedure TWinControl.AlignControl(AControl: TControl);
var
  Rect: TRect;
begin
  if not HandleAllocated or (csDestroying in ComponentState) then Exit;
  if FAlignLevel <> 0 then
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

procedure TWinControl.DisableAlign;
begin
  Inc(FAlignLevel);
end;

procedure TWinControl.EnableAlign;
begin
  Dec(FAlignLevel);
  if FAlignLevel = 0 then
  begin
    if csAlignmentNeeded in ControlState then Realign;
  end;
end;

procedure TWinControl.Realign;
begin
  AlignControl(nil);
end;

procedure TWinControl.DoFlipChildren;
var
  Loop: Integer;
  TheWidth: Integer;
  FlippedList: TList;
begin
  FlippedList := TList.Create;
  try
    TheWidth := ClientWidth;
    for Loop := 0 to ControlCount - 1 do with Controls[Loop] do
      if (Owner = Self.Owner) then
      begin
        FlippedList.Add(Controls[Loop]);
        Left := TheWidth - Width - Left;
      end;
    { Allow controls that have associations to realign themselves }
    for Loop := 0 to FlippedList.Count - 1 do
      TControl(FlippedList[Loop]).Perform(CM_ALLCHILDRENFLIPPED, 0, 0);
  finally
    FlippedList.Free;
  end;
end;

procedure TWinControl.FlipChildren(AllLevels: Boolean);
var
  Loop: Integer;
  AlignList: TList;
begin
  if ControlCount = 0 then Exit;
  AlignList := TList.Create;
  DisableAlign;
  try
    { Collect all the Right and Left alignments }
    for Loop := 0 to ControlCount - 1 do with Controls[Loop] do
      if Align in [alLeft, alRight] then AlignList.Add(Controls[Loop]);
    { Flip 'em }
    DoFlipChildren;
  finally
    { Reverse the Right and Left alignments }
    while AlignList.Count > 0 do
    begin
      with TControl(AlignList.Items[AlignList.Count - 1]) do
        if Align = alLeft then
          Align := alRight
        else
          Align := alLeft;
      AlignList.Delete(AlignList.Count - 1);
    end;
    AlignList.Free;
    EnableAlign;
  end;
  if AllLevels then
    for Loop := 0 to ControlCount - 1 do
      if Controls[Loop] is TWinControl then
        TWinControl(Controls[Loop]).FlipChildren(True);
end;

function TWinControl.ContainsControl(Control: TControl): Boolean;
begin
  while (Control <> nil) and (Control <> Self) do Control := Control.Parent;
  Result := Control <> nil;
end;

procedure TWinControl.RemoveFocus(Removing: Boolean);
var
  Form: TCustomForm;
begin
  Form := GetParentForm(Self);
  if Form <> nil then Form.DefocusControl(Self, Removing);
end;

procedure TWinControl.Insert(AControl: TControl);
begin
  if AControl <> nil then
  begin
    if AControl is TWinControl then
    begin
      ListAdd(FWinControls, AControl);
      ListAdd(FTabList, AControl);
    end else
      ListAdd(FControls, AControl);
    AControl.FParent := Self;
  end;
end;

procedure TWinControl.Remove(AControl: TControl);
begin
  if AControl is TWinControl then
  begin
    ListRemove(FTabList, AControl);
    ListRemove(FWinControls, AControl);
  end else
    ListRemove(FControls, AControl);
  AControl.FParent := nil;
end;

procedure TWinControl.InsertControl(AControl: TControl);
begin
  AControl.ValidateContainer(Self);
  Perform(CM_CONTROLLISTCHANGE, Integer(AControl), Integer(True));
  Insert(AControl);
  if not (csReadingState in AControl.ControlState) then
  begin
    AControl.Perform(CM_PARENTCOLORCHANGED, 0, 0);
    AControl.Perform(CM_PARENTFONTCHANGED, 0, 0);
    AControl.Perform(CM_PARENTSHOWHINTCHANGED, 0, 0);
    AControl.Perform(CM_PARENTBIDIMODECHANGED, 0, 0);
    if AControl is TWinControl then
    begin
      AControl.Perform(CM_PARENTCTL3DCHANGED, 0, 0);
      UpdateControlState;
    end else
      if HandleAllocated then AControl.Invalidate;
    AlignControl(AControl);
  end;
  Perform(CM_CONTROLCHANGE, Integer(AControl), Integer(True));
end;

procedure TWinControl.RemoveControl(AControl: TControl);
begin
  Perform(CM_CONTROLCHANGE, Integer(AControl), Integer(False));
  if AControl is TWinControl then
    with TWinControl(AControl) do
    begin
      RemoveFocus(True);
      DestroyHandle;
    end
  else
    if HandleAllocated then
      AControl.InvalidateControl(AControl.Visible, False);
  Remove(AControl);
  Perform(CM_CONTROLLISTCHANGE, Integer(AControl), Integer(False));
  Realign;
end;

function TWinControl.GetControl(Index: Integer): TControl;
var
  N: Integer;
begin
  if FControls <> nil then N := FControls.Count else N := 0;
  if Index < N then
    Result := FControls[Index] else
    Result := FWinControls[Index - N];
end;

function TWinControl.GetControlCount: Integer;
begin
  Result := 0;
  if FControls <> nil then Inc(Result, FControls.Count);
  if FWinControls <> nil then Inc(Result, FWinControls.Count);
end;

procedure TWinControl.Broadcast(var Message);
var
  I: Integer;
begin
  for I := 0 to ControlCount - 1 do
  begin
    Controls[I].WindowProc(TMessage(Message));
    if TMessage(Message).Result <> 0 then Exit;
  end;
end;

procedure TWinControl.NotifyControls(Msg: Word);
var
  Message: TMessage;
begin
  Message.Msg := Msg;
  Message.WParam := 0;
  Message.LParam := 0;
  Message.Result := 0;
  Broadcast(Message);
end;

procedure TWinControl.CreateSubClass(var Params: TCreateParams;
  ControlClassName: PChar);
const
  CS_OFF = CS_OWNDC or CS_CLASSDC or CS_PARENTDC or CS_GLOBALCLASS;
  CS_ON = CS_VREDRAW or CS_HREDRAW;
var
  SaveInstance: THandle;
begin
  if ControlClassName <> nil then
    with Params do
    begin
      SaveInstance := WindowClass.hInstance;
      if not GetClassInfo(HInstance, ControlClassName, WindowClass) and
        not GetClassInfo(0, ControlClassName, WindowClass) and
        not GetClassInfo(MainInstance, ControlClassName, WindowClass) then
        GetClassInfo(WindowClass.hInstance, ControlClassName, WindowClass);
      WindowClass.hInstance := SaveInstance;
      WindowClass.style := WindowClass.style and not CS_OFF or CS_ON;
    end;
end;

procedure TWinControl.AddBiDiModeExStyle(var ExStyle: DWORD);
begin
  if UseRightToLeftReading then
    ExStyle := ExStyle or WS_EX_RTLREADING;
  if UseRightToLeftScrollbar then
    ExStyle := ExStyle or WS_EX_LEFTSCROLLBAR;
  if UseRightToLeftAlignment then
    if GetControlsAlignment = taLeftJustify then
      ExStyle := ExStyle or WS_EX_RIGHT
    else if GetControlsAlignment = taRightJustify then
      ExStyle := ExStyle or WS_EX_LEFT;
end;

procedure TWinControl.CreateParams(var Params: TCreateParams);
begin
  FillChar(Params, SizeOf(Params), 0);
  with Params do
  begin
    Caption := FText;
    Style := WS_CHILD or WS_CLIPSIBLINGS;
    AddBiDiModeExStyle(ExStyle);
    if csAcceptsControls in ControlStyle then
    begin
      Style := Style or WS_CLIPCHILDREN;
      ExStyle := ExStyle or WS_EX_CONTROLPARENT;
    end;
    if not (csDesigning in ComponentState) and not Enabled then
      Style := Style or WS_DISABLED;
    if FTabStop then Style := Style or WS_TABSTOP;
    X := FLeft;
    Y := FTop;
    Width := FWidth;
    Height := FHeight;
    if Parent <> nil then
      WndParent := Parent.GetHandle else
      WndParent := FParentWindow;
    WindowClass.style := CS_VREDRAW + CS_HREDRAW + CS_DBLCLKS;
    WindowClass.lpfnWndProc := @DefWindowProc;
    WindowClass.hCursor := LoadCursor(0, IDC_ARROW);
    WindowClass.hbrBackground := 0;
    WindowClass.hInstance := HInstance;
    StrPCopy(WinClassName, ClassName);
  end;
end;

procedure TWinControl.CreateWnd;
var
  Params: TCreateParams;
  TempClass: TWndClass;
  ClassRegistered: Boolean;
begin
  CreateParams(Params);
  with Params do
  begin
    if (WndParent = 0) and (Style and WS_CHILD <> 0) then
      if (Owner <> nil) and (csReading in Owner.ComponentState) and
        (Owner is TWinControl) then
        WndParent := TWinControl(Owner).Handle
      else
        raise EInvalidOperation.CreateFmt(SParentRequired, [Name]);
    FDefWndProc := WindowClass.lpfnWndProc;
    ClassRegistered := GetClassInfo(WindowClass.hInstance, WinClassName, TempClass);
    if not ClassRegistered or (TempClass.lpfnWndProc <> @InitWndProc) then
    begin
      if ClassRegistered then Windows.UnregisterClass(WinClassName,
        WindowClass.hInstance);
      WindowClass.lpfnWndProc := @InitWndProc;
      WindowClass.lpszClassName := WinClassName;
      if Windows.RegisterClass(WindowClass) = 0 then RaiseLastWin32Error;
    end;
    CreationControl := Self;
    CreateWindowHandle(Params);
    if FHandle = 0 then RaiseLastWin32Error;
  end;
  StrDispose(FText);
  FText := nil;
  UpdateBounds;
  Perform(WM_SETFONT, FFont.Handle, 1);
  if AutoSize then AdjustSize;
end;

procedure TWinControl.CreateWindowHandle(const Params: TCreateParams);
begin
  with Params do
    FHandle := CreateWindowEx(ExStyle, WinClassName, Caption, Style,
      X, Y, Width, Height, WndParent, 0, WindowClass.hInstance, Param);
end;

procedure TWinControl.DestroyWnd;
var
  Len: Integer;
begin
  Len := GetTextLen;
  if Len < 1 then FText := StrNew('') else
  begin
    FText := StrAlloc(Len + 1);
    GetTextBuf(FText, StrBufSize(FText));
  end;
  FreeDeviceContexts;
  DestroyWindowHandle;
end;

procedure TWinControl.DestroyWindowHandle;
begin
  Include(FControlState, csDestroyingHandle);
  try
    if not Windows.DestroyWindow(FHandle) then
      RaiseLastWin32Error;
  finally
    Exclude(FControlState, csDestroyingHandle);
  end;
  FHandle := 0;
end;

function TWinControl.PrecedingWindow(Control: TWinControl): HWnd;
var
  I: Integer;
begin
  for I := FWinControls.IndexOf(Control) + 1 to FWinControls.Count - 1 do
  begin
    Result := TWinControl(FWinControls[I]).FHandle;
    if Result <> 0 then Exit;
  end;
  Result := HWND_TOP;
end;

procedure TWinControl.CreateHandle;
var
  I: Integer;
begin
  if FHandle = 0 then
  begin
    CreateWnd;
    SetProp(FHandle, MakeIntAtom(ControlAtom), THandle(Self));
    SetProp(FHandle, MakeIntAtom(WindowAtom), THandle(Self));
    if Parent <> nil then
      SetWindowPos(FHandle, Parent.PrecedingWindow(Self), 0, 0, 0, 0,
        SWP_NOMOVE + SWP_NOSIZE + SWP_NOACTIVATE);
    for I := 0 to ControlCount - 1 do
      Controls[I].UpdateAnchorRules;
  end;
end;

procedure TWinControl.DestroyHandle;
var
  I: Integer;
begin
  if FHandle <> 0 then
  begin
    if FWinControls <> nil then
      for I := 0 to FWinControls.Count - 1 do
        TWinControl(FWinControls[I]).DestroyHandle;
    DestroyWnd;
  end;
end;

procedure TWinControl.RecreateWnd;
begin
  if FHandle <> 0 then Perform(CM_RECREATEWND, 0, 0);
end;

procedure TWinControl.CMRecreateWnd(var Message: TMessage);
var
  WasFocused: Boolean;
begin
  WasFocused := Focused;
  DestroyHandle;
  UpdateControlState;
  if WasFocused and (FHandle <> 0) then Windows.SetFocus(FHandle);
end;

procedure TWinControl.UpdateShowing;
var
  ShowControl: Boolean;
  I: Integer;
begin
  ShowControl := (FVisible or (csDesigning in ComponentState) and
    not (csNoDesignVisible in ControlStyle)) and
    not (csReadingState in ControlState);
  if ShowControl then
  begin
    if FHandle = 0 then CreateHandle;
    if FWinControls <> nil then
      for I := 0 to FWinControls.Count - 1 do
        TWinControl(FWinControls[I]).UpdateShowing;
  end;
  if FHandle <> 0 then
    if FShowing <> ShowControl then
    begin
      FShowing := ShowControl;
      try
        Perform(CM_SHOWINGCHANGED, 0, 0);
      except
        FShowing := not ShowControl;
        raise;
      end;
    end;
end;

procedure TWinControl.UpdateControlState;
var
  Control: TWinControl;
begin
  Control := Self;
  while Control.Parent <> nil do
  begin
    Control := Control.Parent;
    if not Control.Showing then Exit;
  end;
  if (Control is TCustomForm) or (Control.FParentWindow <> 0) then UpdateShowing;
end;

procedure TWinControl.SetParentWindow(Value: HWnd);
begin
  if (FParent = nil) and (FParentWindow <> Value) then
  begin
    if (FHandle <> 0) and (FParentWindow <> 0) and (Value <> 0) then
    begin
      FParentWindow := Value;
      Windows.SetParent(FHandle, Value);
      if (Win32MajorVersion >= 5) and (Win32Platform = VER_PLATFORM_WIN32_NT) then
        Perform(WM_CHANGEUISTATE, MakeWParam(UIS_INITIALIZE, UISF_HIDEACCEL or UISF_HIDEFOCUS), 0);
    end else
    begin
      DestroyHandle;
      FParentWindow := Value;
    end;
    UpdateControlState;
  end;
end;

procedure TWinControl.MainWndProc(var Message: TMessage);
begin
  try
    try
      WindowProc(Message);
    finally
      FreeDeviceContexts;
      FreeMemoryContexts;
    end;
  except
    Application.HandleException(Self);
  end;
end;

function TWinControl.ControlAtPos(const Pos: TPoint; AllowDisabled,
  AllowWinControls: Boolean): TControl;
var
  I: Integer;
  P: TPoint;
  vControl: TControl;
  function GetControlAtPos(AControl: TControl): Boolean;
  begin
    with AControl do
    begin
      P := Point(Pos.X - Left, Pos.Y - Top);
      Result := PtInRect(ClientRect, P) and
                ((csDesigning in ComponentState) and (Visible or
                not (csNoDesignVisible in ControlStyle)) or
                (Visible and (Enabled or AllowDisabled) and
                (Perform(CM_HITTEST, 0, Longint(PointToSmallPoint(P))) <> 0)));
      if Result then
        vControl := AControl;
    end;
  end;
begin
  vControl := nil;
  if AllowWinControls and
     (FWinControls <> nil) then
    for I := FWinControls.Count - 1 downto 0 do
      if GetControlAtPos(FWinControls[I]) then
        Break;
  if (FControls <> nil) and
     (vControl = nil) then
    for I := FControls.Count - 1 downto 0 do
      if GetControlAtPos(FControls[I]) then
        Break;
  Result := vControl;
end;

function TWinControl.IsControlMouseMsg(var Message: TWMMouse): Boolean;
var
  Control: TControl;
  P: TPoint;
begin
  if GetCapture = Handle then
  begin
    Control := nil;
    if (CaptureControl <> nil) and (CaptureControl.Parent = Self) then
      Control := CaptureControl;
  end else
    Control := ControlAtPos(SmallPointToPoint(Message.Pos), False);
  Result := False;
  if Control <> nil then
  begin
    P.X := Message.XPos - Control.Left;
    P.Y := Message.YPos - Control.Top;
    Message.Result := Control.Perform(Message.Msg, Message.Keys, Longint(PointToSmallPoint(P)));
    Result := True;
  end;
end;

procedure TWinControl.WndProc(var Message: TMessage);
var
  Form: TCustomForm;
  KeyState: TKeyboardState;
  WheelMsg: TCMMouseWheel;
begin
  case Message.Msg of
    WM_SETFOCUS:
      begin
        Form := GetParentForm(Self);
        if (Form <> nil) and not Form.SetFocusedControl(Self) then Exit;
      end;
    WM_KILLFOCUS:
      if csFocusing in ControlState then Exit;
    WM_NCHITTEST:
      begin
        inherited WndProc(Message);
        if (Message.Result = HTTRANSPARENT) and (ControlAtPos(ScreenToClient(
          SmallPointToPoint(TWMNCHitTest(Message).Pos)), False) <> nil) then
          Message.Result := HTCLIENT;
        Exit;
      end;
    WM_MOUSEFIRST..WM_MOUSELAST:
      if IsControlMouseMsg(TWMMouse(Message)) then
      begin
        if Message.Result = 0 then
          DefWindowProc(Handle, Message.Msg, Message.wParam, Message.lParam);
        Exit;
      end;
    WM_KEYFIRST..WM_KEYLAST:
      if Dragging then Exit;
    WM_CANCELMODE:
      if (GetCapture = Handle) and (CaptureControl <> nil) and
        (CaptureControl.Parent = Self) then
        CaptureControl.Perform(WM_CANCELMODE, 0, 0);
  else
    with Mouse do
      if WheelPresent and (RegWheelMessage <> 0) and
        (Message.Msg = RegWheelMessage) then
      begin
        GetKeyboardState(KeyState);
        with WheelMsg do
        begin
          Msg := Message.Msg;
          ShiftState := KeyboardStateToShiftState(KeyState);
          WheelDelta := Message.WParam;
          Pos := TSmallPoint(Message.LParam);
        end;
        MouseWheelHandler(TMessage(WheelMsg));
        Exit;
      end;
  end;
  inherited WndProc(Message);
end;

procedure TWinControl.DefaultHandler(var Message);
begin
  if FHandle <> 0 then
  begin
    with TMessage(Message) do
    begin
      if (Msg = WM_CONTEXTMENU) and (Parent <> nil) then
      begin
        Result := Parent.Perform(Msg, WParam, LParam);
        if Result <> 0 then Exit;
      end;
      case Msg of
        WM_CTLCOLORMSGBOX..WM_CTLCOLORSTATIC:
          Result := SendMessage(LParam, CN_BASE + Msg, WParam, LParam);
        CN_CTLCOLORMSGBOX..CN_CTLCOLORSTATIC:
          begin
            SetTextColor(WParam, ColorToRGB(FFont.Color));
            SetBkColor(WParam, ColorToRGB(FBrush.Color));
            Result := FBrush.Handle;
          end;
      else
        Result := CallWindowProc(FDefWndProc, FHandle, Msg, WParam, LParam);
      end;
      if Msg = WM_SETTEXT then
        SendDockNotification(Msg, WParam, LParam);
    end;
  end
  else
    inherited DefaultHandler(Message);
end;

function DoControlMsg(ControlHandle: HWnd; var Message): Boolean;
var
  Control: TWinControl;
begin
  DoControlMsg := False;
  Control := FindControl(ControlHandle);
  if Control <> nil then
    with TMessage(Message) do
    begin
      Result := Control.Perform(Msg + CN_BASE, WParam, LParam);
      DoControlMsg := True;
    end;
end;

procedure TWinControl.PaintHandler(var Message: TWMPaint);
var
  I, Clip, SaveIndex: Integer;
  DC: HDC;
  PS: TPaintStruct;
begin
  DC := Message.DC;
  if DC = 0 then DC := BeginPaint(Handle, PS);
  try
    if FControls = nil then PaintWindow(DC) else
    begin
      SaveIndex := SaveDC(DC);
      Clip := SimpleRegion;
      for I := 0 to FControls.Count - 1 do
        with TControl(FControls[I]) do
          if (Visible or (csDesigning in ComponentState) and
            not (csNoDesignVisible in ControlStyle)) and
            (csOpaque in ControlStyle) then
          begin
            Clip := ExcludeClipRect(DC, Left, Top, Left + Width, Top + Height);
            if Clip = NullRegion then Break;
          end;
      if Clip <> NullRegion then PaintWindow(DC);
      RestoreDC(DC, SaveIndex);
    end;
    PaintControls(DC, nil);
  finally
    if Message.DC = 0 then EndPaint(Handle, PS);
  end;
end;

procedure TWinControl.PaintWindow(DC: HDC);
var
  Message: TMessage;
begin
  Message.Msg := WM_PAINT;
  Message.WParam := DC;
  Message.LParam := 0;
  Message.Result := 0;
  DefaultHandler(Message);
end;

procedure TWinControl.PaintControls(DC: HDC; First: TControl);
var
  I, Count, SaveIndex: Integer;
  FrameBrush: HBRUSH;
begin
  if DockSite and UseDockManager and (DockManager <> nil) then
    DockManager.PaintSite(DC);
  if FControls <> nil then
  begin
    I := 0;
    if First <> nil then
    begin
      I := FControls.IndexOf(First);
      if I < 0 then I := 0;
    end;
    Count := FControls.Count;
    while I < Count do
    begin
      with TControl(FControls[I]) do
        if (Visible or (csDesigning in ComponentState) and
          not (csNoDesignVisible in ControlStyle)) and
          RectVisible(DC, Rect(Left, Top, Left + Width, Top + Height)) then
        begin
          if csPaintCopy in Self.ControlState then
            Include(FControlState, csPaintCopy);
          SaveIndex := SaveDC(DC);
          MoveWindowOrg(DC, Left, Top);
          IntersectClipRect(DC, 0, 0, Width, Height);
          Perform(WM_PAINT, DC, 0);
          RestoreDC(DC, SaveIndex);
          Exclude(FControlState, csPaintCopy);
        end;
      Inc(I);
    end;
  end;
  if FWinControls <> nil then
    for I := 0 to FWinControls.Count - 1 do
      with TWinControl(FWinControls[I]) do
        if FCtl3D and (csFramed in ControlStyle) and
          (Visible or (csDesigning in ComponentState) and
          not (csNoDesignVisible in ControlStyle)) then
        begin
          FrameBrush := CreateSolidBrush(ColorToRGB(clBtnShadow));
          FrameRect(DC, Rect(Left - 1, Top - 1, Left + Width, Top + Height),
            FrameBrush);
          DeleteObject(FrameBrush);
          FrameBrush := CreateSolidBrush(ColorToRGB(clBtnHighlight));
          FrameRect(DC, Rect(Left, Top, Left + Width + 1, Top + Height + 1),
            FrameBrush);
          DeleteObject(FrameBrush);
        end;
end;

procedure TWinControl.PaintTo(DC: HDC; X, Y: Integer);
var
  I, EdgeFlags, BorderFlags, SaveIndex: Integer;
  R: TRect;
begin
  Include(FControlState, csPaintCopy);
  SaveIndex := SaveDC(DC);
  MoveWindowOrg(DC, X, Y);
  IntersectClipRect(DC, 0, 0, Width, Height);
  BorderFlags := 0;
  EdgeFlags := 0;
  if GetWindowLong(Handle, GWL_EXSTYLE) and WS_EX_CLIENTEDGE <> 0 then
  begin
    EdgeFlags := EDGE_SUNKEN;
    BorderFlags := BF_RECT or BF_ADJUST
  end else
  if GetWindowLong(Handle, GWL_STYLE) and WS_BORDER <> 0 then
  begin
    EdgeFlags := BDR_OUTER;
    BorderFlags := BF_RECT or BF_ADJUST or BF_MONO;
  end;
  if BorderFlags <> 0 then
  begin
    SetRect(R, 0, 0, Width, Height);
    DrawEdge(DC, R, EdgeFlags, BorderFlags);
    MoveWindowOrg(DC, R.Left, R.Top);
    IntersectClipRect(DC, 0, 0, R.Right - R.Left, R.Bottom - R.Top);
  end;
  Perform(WM_ERASEBKGND, DC, 0);
  Perform(WM_PAINT, DC, 0);
  if FWinControls <> nil then
    for I := 0 to FWinControls.Count - 1 do
      with TWinControl(FWinControls[I]) do
        if Visible then PaintTo(DC, Left, Top);
  RestoreDC(DC, SaveIndex);
  Exclude(FControlState, csPaintCopy);
end;

procedure TWinControl.WMPaint(var Message: TWMPaint);
var
  DC, MemDC: HDC;
  MemBitmap, OldBitmap: HBITMAP;
  PS: TPaintStruct;
begin
  if not FDoubleBuffered or (Message. DC <> 0) then
  begin
    if not (csCustomPaint in ControlState) and (ControlCount = 0) then
      inherited
    else
      PaintHandler(Message);
  end
  else
  begin
    DC := GetDC(0);
    MemBitmap := CreateCompatibleBitmap(DC, ClientRect.Right, ClientRect.Bottom);
    ReleaseDC(0, DC);
    MemDC := CreateCompatibleDC(0);
    OldBitmap := SelectObject(MemDC, MemBitmap);
    try
      DC := BeginPaint(Handle, PS);
      Perform(WM_ERASEBKGND, MemDC, MemDC);
      Message.DC := MemDC;
      WMPaint(Message);
      Message.DC := 0;
      BitBlt(DC, 0, 0, ClientRect.Right, ClientRect.Bottom, MemDC, 0, 0, SRCCOPY);
      EndPaint(Handle, PS);
    finally
      SelectObject(MemDC, OldBitmap);
      DeleteDC(MemDC);
      DeleteObject(MemBitmap);
    end;
  end;
end;

procedure TWinControl.WMCommand(var Message: TWMCommand);
begin
  if not DoControlMsg(Message.Ctl, Message) then inherited;
end;

procedure TWinControl.WMNotify(var Message: TWMNotify);
begin
  if not DoControlMsg(Message.NMHdr^.hWndFrom, Message) then inherited;
end;

procedure TWinControl.WMSysColorChange(var Message: TWMSysColorChange);
begin
  Graphics.PaletteChanged;
  Perform(CM_SYSCOLORCHANGE, 0, 0);
end;

procedure TWinControl.WMWinIniChange(var Message: TMessage);
begin
  Perform(CM_WININICHANGE, Message.wParam, Message.lParam);
end;

procedure TWinControl.WMFontChange(var Message: TMessage);
begin
  Perform(CM_FONTCHANGE, 0, 0);
end;

procedure TWinControl.WMTimeChange(var Message: TMessage);
begin
  Perform(CM_TIMECHANGE, 0, 0);
end;

procedure TWinControl.WMHScroll(var Message: TWMHScroll);
begin
  if not DoControlMsg(Message.ScrollBar, Message) then inherited;
end;

procedure TWinControl.WMVScroll(var Message: TWMVScroll);
begin
  if not DoControlMsg(Message.ScrollBar, Message) then inherited;
end;

procedure TWinControl.WMCompareItem(var Message: TWMCompareItem);
begin
  if not DoControlMsg(Message.CompareItemStruct^.CtlID, Message) then inherited;
end;

procedure TWinControl.WMDeleteItem(var Message: TWMDeleteItem);
begin
  if not DoControlMsg(Message.DeleteItemStruct^.CtlID, Message) then inherited;
end;

procedure TWinControl.WMDrawItem(var Message: TWMDrawItem);
begin
  if not DoControlMsg(Message.DrawItemStruct^.CtlID, Message) then inherited;
end;

procedure TWinControl.WMMeasureItem(var Message: TWMMeasureItem);
begin
  if not DoControlMsg(Message.MeasureItemStruct^.CtlID, Message) then inherited;
end;

procedure TWinControl.WMEraseBkgnd(var Message: TWMEraseBkgnd);
begin
  { Only erase background if we're not doublebuffering or painting to memory. }
  if not FDoubleBuffered or
    (TMessage(Message).wParam = TMessage(Message).lParam) then
    FillRect(Message.DC, ClientRect, FBrush.Handle);
  Message.Result := 1;
end;

procedure TWinControl.WMWindowPosChanged(var Message: TWMWindowPosChanged);
var
  Framed, Moved, Sized: Boolean;
begin
  Framed := FCtl3D and (csFramed in ControlStyle) and (Parent <> nil) and
    (Message.WindowPos^.flags and SWP_NOREDRAW = 0);
  Moved := (Message.WindowPos^.flags and SWP_NOMOVE = 0) and
    IsWindowVisible(FHandle);
  Sized := (Message.WindowPos^.flags and SWP_NOSIZE = 0) and
    IsWindowVisible(FHandle);
  if Framed and (Moved or Sized) then
    InvalidateFrame;
  if not (csDestroyingHandle in ControlState) then
    UpdateBounds;
  inherited;
  if Framed and ((Moved or Sized) or (Message.WindowPos^.flags and
    (SWP_SHOWWINDOW or SWP_HIDEWINDOW) <> 0)) then
    InvalidateFrame;
end;

procedure TWinControl.WMWindowPosChanging(var Message: TWMWindowPosChanging);
begin
  if ComponentState * [csReading, csDestroying] = [] then
    with Message.WindowPos^ do
      if (flags and SWP_NOSIZE = 0) and not CheckNewSize(cx, cy) then
        flags := flags or SWP_NOSIZE;
  inherited;
end;

procedure TWinControl.WMSize(var Message: TWMSize);
begin
  UpdateBounds;
  inherited;
  Realign;
  if not (csLoading in ComponentState) then Resize;
end;

procedure TWinControl.WMMove(var Message: TWMMove);
begin
  inherited;
  UpdateBounds;
end;

procedure TWinControl.WMSetCursor(var Message: TWMSetCursor);
var
  Cursor: TCursor;
  Control: TControl;
  P: TPoint;
begin
  with Message do
    if CursorWnd = FHandle then
      case Smallint(HitTest) of
        HTCLIENT:
          begin
            Cursor := Screen.Cursor;
            if Cursor = crDefault then
            begin
              GetCursorPos(P);
              Control := ControlAtPos(ScreenToClient(P), False);
              if (Control <> nil) then
                if csDesigning in Control.ComponentState then
                  Cursor := crArrow
                else
                  Cursor := Control.FCursor;
              if Cursor = crDefault then
                if csDesigning in ComponentState then
                  Cursor := crArrow
                else
                  Cursor := FCursor;
            end;
            if Cursor <> crDefault then
            begin
              Windows.SetCursor(Screen.Cursors[Cursor]);
              Result := 1;
              Exit;
            end;
          end;
        HTERROR:
          if (MouseMsg = WM_LBUTTONDOWN) and (Application.Handle <> 0) and
            (GetForegroundWindow <> GetLastActivePopup(Application.Handle)) then
          begin
            Application.BringToFront;
            Exit;
          end;
      end;
  inherited;
end;

procedure TWinControl.WMSetFocus(var Message: TWMSetFocus);
begin
  inherited;
  SetIme;
end;

procedure TWinControl.WMKillFocus(var Message: TWMSetFocus);
begin
  inherited;
  ResetIme;
end;

procedure TWinControl.WMIMEStartComp(var Message: TMessage);
begin
  FInImeComposition := True;
  inherited;
end;

procedure TWinControl.WMIMEEndComp(var Message: TMessage);
begin
  FInImeComposition := False;
  inherited;
end;

function TWinControl.SetImeCompositionWindow(Font: TFont;
  XPos, YPos: Integer): Boolean;
var
  H: HIMC;
  CForm: TCompositionForm;
  LFont: TLogFont;
begin
  Result := False;
  H := Imm32GetContext(Handle);
  if H <> 0 then
  begin
    with CForm do
    begin
      dwStyle := CFS_POINT;
      ptCurrentPos.x := XPos;
      ptCurrentPos.y := YPos;
    end;
    Imm32SetCompositionWindow(H, @CForm);
    if Assigned(Font) then
    begin
      GetObject(Font.Handle, SizeOf(TLogFont), @LFont);
      Imm32SetCompositionFont(H, @LFont);
    end;
    Imm32ReleaseContext(Handle, H);
    Result := True;
  end;
end;

function TWinControl.ResetImeComposition(Action: DWORD): Boolean;
var
  H: HIMC;
begin
  Result := False;
  if FInImeComposition then
  begin
    H := Imm32GetContext(Handle);
    if H <> 0 then
    begin
      Result := Imm32NotifyIME(H, NI_COMPOSITIONSTR, Action, 0);
      Imm32ReleaseContext(Handle, H);
    end;
  end;
end;

procedure TWinControl.SetIme;
var
  I: Integer;
  HandleToSet: HKL;
begin
  if not SysLocale.FarEast then Exit;
  if FImeName <> '' then
  begin
    if (AnsiCompareText(FImeName, Screen.DefaultIme) <> 0) and (Screen.Imes.Count <> 0) then
    begin
      HandleToSet := Screen.DefaultKbLayout;
      if FImeMode <> imDisable then
      begin
        I := Screen.Imes.IndexOf(FImeName);
        if I >= 0 then
          HandleToSet := HKL(Screen.Imes.Objects[I]);
      end;
      ActivateKeyboardLayout(HandleToSet, KLF_ACTIVATE);
    end;
  end;
  SetImeMode(Handle, FImeMode);
end;

procedure TWinControl.ResetIme;
begin
  if not SysLocale.FarEast then Exit;
  if FImeName <> '' then
  begin
    if AnsiCompareText(FImeName, Screen.DefaultIme) <> 0 then
      ActivateKeyboardLayout(Screen.DefaultKbLayout, KLF_ACTIVATE);
  end;
  if FImeMode = imDisable then Win32NLSEnableIME(Handle, TRUE);
end;

procedure TWinControl.DoAddDockClient(Client: TControl; const ARect: TRect);
begin
  Client.Parent := Self;
end;

procedure TWinControl.DoRemoveDockClient(Client: TControl);
begin
  // do nothing by default
end;

procedure TWinControl.DoEnter;
begin
  if Assigned(FOnEnter) then FOnEnter(Self);
end;

procedure TWinControl.DoExit;
begin
  if Assigned(FOnExit) then FOnExit(Self);
end;

procedure TWinControl.DockDrop(Source: TDragDockObject; X, Y: Integer);
begin
  if (Perform(CM_DOCKCLIENT, Integer(Source), Integer(SmallPoint(X, Y))) >= 0)
    and Assigned(FOnDockDrop) then
    FOnDockDrop(Self, Source, X, Y);
end;

procedure TWinControl.DoDockOver(Source: TDragDockObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  if Assigned(FOnDockOver) then
    FOnDockOver(Self, Source, X, Y, State, Accept);
end;

procedure TWinControl.DockOver(Source: TDragDockObject; X, Y: Integer; State: TDragState;
  var Accept: Boolean);
begin
  PositionDockRect(Source);
  DoDockOver(Source, X, Y, State, Accept);
end;

function TWinControl.DoUnDock(NewTarget: TWinControl; Client: TControl): Boolean;
begin
  Result := True;
  if Assigned(FOnUnDock) then FOnUnDock(Self, Client, NewTarget, Result);
  Result := Result and (Perform(CM_UNDOCKCLIENT, Integer(NewTarget), Integer(Client)) = 0);
end;

procedure TWinControl.ReloadDockedControl(const AControlName: string;
  var AControl: TControl);
begin
  AControl := Owner.FindComponent(AControlName) as TControl;
end;

function TWinControl.GetDockClientCount: Integer;
begin
  if FDockClients <> nil then Result := FDockClients.Count
  else Result := 0;
end;

function TWinControl.GetDockClients(Index: Integer): TControl;
begin
  if FDockClients <> nil then Result := FDockClients[Index]
  else Result := nil;
end;

procedure TWinControl.GetSiteInfo(Client: TControl; var InfluenceRect: TRect;
  MousePos: TPoint; var CanDock: Boolean);
const
  DefExpandoRect = 10;
begin
  GetWindowRect(Handle, InfluenceRect);
  InflateRect(InfluenceRect, DefExpandoRect, DefExpandoRect);
  if Assigned(FOnGetSiteInfo) then
    FOnGetSiteInfo(Self, Client, InfluenceRect, MousePos, CanDock);
end;

function TWinControl.GetVisibleDockClientCount: Integer;
var
  I: Integer;
begin
  Result := GetDockClientCount;
  if Result > 0 then
    for I := Result - 1 downto 0 do
      if not TControl(FDockClients[I]).Visible then Dec(Result);
end;

function TWinControl.CreateDockManager: IDockManager;
begin
  if (FDockManager = nil) and DockSite and UseDockManager then
    Result := DefaultDockTreeClass.Create(Self) else
    Result := FDockManager;
  DoubleBuffered := DoubleBuffered or (Result <> nil);
end;

procedure TWinControl.SetDockSite(Value: Boolean);
begin
  if Value <> FDockSite then
  begin
    FDockSite := Value;
    if not (csDesigning in ComponentState) then
    begin
      RegisterDockSite(Self, Value);
      if not Value then
      begin
        FDockClients.Free;
        FDockClients := nil;
        FDockManager := nil;
      end
      else begin
        if FDockClients = nil then FDockClients := TList.Create;
        FDockManager := CreateDockManager;
      end;
    end;
  end;
end;

procedure TWinControl.CMDockClient(var Message: TCMDockClient);
var
  DestRect: TRect;
  Form: TCustomForm;
begin
  with Message do
    if Result = 0 then
    begin
      { Map DockRect to dock site's client coordinates }
      DestRect := Message.DockSource.DockRect;
      MapWindowPoints(0, Handle, DestRect, 2);
      DisableAlign;
      try
        DockSource.Control.Dock(Self, DestRect);
        if FUseDockManager and (FDockManager <> nil) then
          FDockManager.InsertControl(DockSource.Control,
            DockSource.DropAlign, DockSource.DropOnControl);
      finally
        EnableAlign;
      end;
      Form := GetParentForm(Self);
      if Form <> nil then Form.BringToFront;
      Result := 1;
    end;
end;

procedure TWinControl.CMUnDockClient(var Message: TCMUnDockClient);
begin
  with Message do
  begin
    Result := 0;
    if FUseDockManager and (FDockManager <> nil) then
      FDockManager.RemoveControl(Client)
  end;
end;

procedure TWinControl.CMFloat(var Message: TCMFloat);
var
  WasVisible: Boolean;
begin
  if (FloatingDockSiteClass = ClassType) then
  begin
    WasVisible := Visible;
    try
      Dock(nil, Message.DockSource.FDockRect);
    finally
      if WasVisible then BringToFront;
    end;
  end
  else
    inherited;
end;

procedure TWinControl.KeyDown(var Key: Word; Shift: TShiftState);
begin
  if Assigned(FOnKeyDown) then FOnKeyDown(Self, Key, Shift);
end;

function TWinControl.DoKeyDown(var Message: TWMKey): Boolean;
var
  ShiftState: TShiftState;
  Form: TCustomForm;
begin
  Result := True;
  Form := GetParentForm(Self);
  if (Form <> nil) and (Form <> Self) and Form.KeyPreview and
    TWinControl(Form).DoKeyDown(Message) then Exit;
  with Message do
  begin
    ShiftState := KeyDataToShiftState(KeyData);
    if not (csNoStdEvents in ControlStyle) then
    begin
      KeyDown(CharCode, ShiftState);
      if CharCode = 0 then Exit;
    end;
  end;
  Result := False;
end;

procedure TWinControl.WMKeyDown(var Message: TWMKeyDown);
begin
  if not DoKeyDown(Message) then inherited;
end;

procedure TWinControl.WMSysKeyDown(var Message: TWMKeyDown);
begin
  if not DoKeyDown(Message) then inherited;
end;

procedure TWinControl.KeyUp(var Key: Word; Shift: TShiftState);
begin
  if Assigned(FOnKeyUp) then FOnKeyUp(Self, Key, Shift);
end;

function TWinControl.DoKeyUp(var Message: TWMKey): Boolean;
var
  ShiftState: TShiftState;
  Form: TCustomForm;
begin
  Result := True;
  Form := GetParentForm(Self);
  if (Form <> nil) and (Form <> Self) and Form.KeyPreview and
    TWinControl(Form).DoKeyUp(Message) then Exit;
  with Message do
  begin
    ShiftState := KeyDataToShiftState(KeyData);
    if not (csNoStdEvents in ControlStyle) then
    begin
      KeyUp(CharCode, ShiftState);
      if CharCode = 0 then Exit;
    end;
  end;
  Result := False;
end;

procedure TWinControl.WMKeyUp(var Message: TWMKeyUp);
begin
  if not DoKeyUp(Message) then inherited;
end;

procedure TWinControl.WMSysKeyUp(var Message: TWMKeyUp);
begin
  if not DoKeyUp(Message) then inherited;
end;

procedure TWinControl.KeyPress(var Key: Char);
begin
  if Assigned(FOnKeyPress) then FOnKeyPress(Self, Key);
end;

function TWinControl.DoKeyPress(var Message: TWMKey): Boolean;
var
  Form: TCustomForm;
  Ch: Char;
begin
  Result := True;
  Form := GetParentForm(Self);
  if (Form <> nil) and (Form <> Self) and Form.KeyPreview and
    TWinControl(Form).DoKeyPress(Message) then Exit;
  if not (csNoStdEvents in ControlStyle) then
    with Message do
    begin
      Ch := Char(CharCode);
      KeyPress(Ch);
      CharCode := Word(Ch);
      if Char(CharCode) = #0 then Exit;
    end;
  Result := False;
end;

procedure TWinControl.WMChar(var Message: TWMChar);
begin
  if not DoKeyPress(Message) then inherited;
end;

procedure TWinControl.CMMouseWheel(var Message: TCMMouseWheel);
begin
  with Message do
  begin
    Result := 0;
    if DoMouseWheel(ShiftState, WheelDelta, SmallPointToPoint(Pos)) then
      Message.Result := 1
    else if Parent <> nil then
      with TMessage(Message) do
        Result := Parent.Perform(CM_MOUSEWHEEL, WParam, LParam);
  end;
end;

procedure TWinControl.WMMouseWheel(var Message: TWMMouseWheel);
begin
  if not Mouse.WheelPresent then
  begin
    Mouse.FWheelPresent := True;
    Mouse.SettingChanged(SPI_GETWHEELSCROLLLINES);
  end;
  TCMMouseWheel(Message).ShiftState := KeysToShiftState(Message.Keys);
  MouseWheelHandler(TMessage(Message));
  if Message.Result = 0 then inherited;
end;

procedure TWinControl.MouseWheelHandler(var Message: TMessage);
var
  Form: TCustomForm;
begin
  Form := GetParentForm(Self);
  if (Form <> nil) and (Form <> Self) then Form.MouseWheelHandler(TMessage(Message))
  else with TMessage(Message) do
    Result := Perform(CM_MOUSEWHEEL, WParam, LParam);
end;

function TWinControl.DoMouseWheel(Shift: TShiftState; WheelDelta: Integer;
  MousePos: TPoint): Boolean;
var
  IsNeg: Boolean;
begin
  Result := False;
  if Assigned(FOnMouseWheel) then
    FOnMouseWheel(Self, Shift, WheelDelta, MousePos, Result);
  if not Result then
  begin
    Inc(FWheelAccumulator, WheelDelta);
    while Abs(FWheelAccumulator) >= WHEEL_DELTA do
    begin
      IsNeg := FWheelAccumulator < 0;
      FWheelAccumulator := Abs(FWheelAccumulator) - WHEEL_DELTA;
      if IsNeg then
      begin
        if FWheelAccumulator <> 0 then FWheelAccumulator := -FWheelAccumulator;
        Result := DoMouseWheelDown(Shift, MousePos);
      end
      else
        Result := DoMouseWheelUp(Shift, MousePos);
    end;
  end;
end;

function TWinControl.DoMouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean;
begin
  Result := False;
  if Assigned(FOnMouseWheelDown) then
    FOnMouseWheelDown(Self, Shift, MousePos, Result);
end;

function TWinControl.DoMouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean;
begin
  Result := False;
  if Assigned(FOnMouseWheelUp) then
    FOnMouseWheelUp(Self, Shift, MousePos, Result);
end;

procedure TWinControl.WMSysCommand(var Message: TWMSysCommand);
var
  Form: TCustomForm;

  function TraverseControls(Container: TWinControl): Boolean;
  var
    I: Integer;
    Control: TControl;
  begin
    Result := False;
    if Container.Showing then
      for I := 0 to Container.ControlCount - 1 do
      begin
        Control := Container.Controls[I];
        if Control.Visible and Control.Enabled then
        begin
          if (csMenuEvents in Control.ControlStyle) and
            (Control.Perform(WM_SYSCOMMAND, TMessage(Message).WParam,
              TMessage(Message).LParam) <> 0) or (Control is TWinControl) and
            TraverseControls(TWinControl(Control)) then
          begin
            Result := True;
            Exit;
          end;
        end;
      end;
  end;

begin
  with Message do
  begin
    if (CmdType and $FFF0 = SC_KEYMENU) and (Key <> VK_SPACE) and
      (Key <> Word('-')) and not IsIconic(FHandle) and (GetCapture = 0) and
      (Application.MainForm <> Self) then
    begin
      Form := GetParentForm(Self);
      if (Form <> nil) and
        (Form.Perform(CM_APPSYSCOMMAND, 0, Longint(@Message)) <> 0) then
        Exit;
    end;
    { Broadcast WMSysCommand to all controls which have a csMenuEvents style. }
    if (CmdType and $FFF0 = SC_KEYMENU) and TraverseControls(Self) then
      Exit;
  end;
  inherited;
end;

procedure TWinControl.WMCharToItem(var Message: TWMCharToItem);
begin
  if not DoControlMsg(Message.ListBox, Message) then inherited;
end;

procedure TWinControl.WMParentNotify(var Message: TWMParentNotify);
begin
  with Message do
    if (Event <> WM_CREATE) and (Event <> WM_DESTROY) or
      not DoControlMsg(Message.ChildWnd, Message) then inherited;
end;

procedure TWinControl.WMVKeyToItem(var Message: TWMVKeyToItem);
begin
  if not DoControlMsg(Message.ListBox, Message) then inherited;
end;

procedure TWinControl.WMDestroy(var Message: TWMDestroy);
begin
  inherited;
  RemoveProp(FHandle, MakeIntAtom(ControlAtom));
  RemoveProp(FHandle, MakeIntAtom(WindowAtom));
end;

procedure TWinControl.WMNCDestroy(var Message: TWMNCDestroy);
begin
  inherited;
  FHandle := 0;
  FShowing := False;
end;

procedure TWinControl.WMNCHitTest(var Message: TWMNCHitTest);
begin
  with Message do
    if (csDesigning in ComponentState) and (FParent <> nil) then
      Result := HTCLIENT
    else
      inherited;
end;

function TWinControl.PaletteChanged(Foreground: Boolean): Boolean;
var
  I: Integer;
begin
  Result := inherited PaletteChanged(Foreground);
  if Visible then
    for I := ControlCount - 1 downto 0 do
    begin
      if Foreground and Result then Exit;
      Result := Controls[I].PaletteChanged(Foreground) or Result;
    end;
end;

procedure TWinControl.WMQueryNewPalette(var Message: TMessage);
begin
  Include(FControlState, csPalette);
  Message.Result := Longint(PaletteChanged(True));
end;

procedure TWinControl.WMPaletteChanged(var Message: TMessage);
begin
  Message.Result := Longint(PaletteChanged(False));
end;

procedure TWinControl.CMShowHintChanged(var Message: TMessage);
begin
  inherited;
  NotifyControls(CM_PARENTSHOWHINTCHANGED);
end;

procedure TWinControl.CMBiDiModeChanged(var Message: TMessage);
begin
  inherited;
  if (SysLocale.MiddleEast) and (Message.wParam = 0) then RecreateWnd;
  NotifyControls(CM_PARENTBIDIMODECHANGED);
end;

procedure TWinControl.CMEnter(var Message: TCMEnter);
begin
  if SysLocale.MiddleEast then
    if UseRightToLeftReading then
    begin
      if Application.BiDiKeyboard <> '' then
        LoadKeyboardLayout(PChar(Application.BiDiKeyboard), KLF_ACTIVATE);
    end
    else
      if Application.NonBiDiKeyboard <> '' then
        LoadKeyboardLayout(PChar(Application.NonBiDiKeyboard), KLF_ACTIVATE);
  DoEnter;
end;

procedure TWinControl.CMExit(var Message: TCMExit);
begin
  DoExit;
end;

procedure TWinControl.CMDesignHitTest(var Message: TCMDesignHitTest);
begin
  if not IsControlMouseMsg(Message) then inherited;
end;

procedure TWinControl.CMChanged(var Message: TMessage);
begin
  if FParent <> nil then FParent.WindowProc(Message);
end;

procedure TWinControl.CMChildKey(var Message: TMessage);
begin
  if FParent <> nil then FParent.WindowProc(Message);
end;

procedure TWinControl.CMDialogKey(var Message: TCMDialogKey);
begin
  Broadcast(Message);
end;

procedure TWinControl.CMDialogChar(var Message: TCMDialogChar);
begin
  Broadcast(Message);
end;

procedure TWinControl.CMFocusChanged(var Message: TCMFocusChanged);
begin
  Broadcast(Message);
end;

procedure TWinControl.CMVisibleChanged(var Message: TMessage);
begin
  if not FVisible and (Parent <> nil) then RemoveFocus(False);
  if not (csDesigning in ComponentState) or
    (csNoDesignVisible in ControlStyle) then UpdateControlState;
end;

procedure TWinControl.CMShowingChanged(var Message: TMessage);
const
  ShowFlags: array[Boolean] of Word = (
    SWP_NOSIZE + SWP_NOMOVE + SWP_NOZORDER + SWP_NOACTIVATE + SWP_HIDEWINDOW,
    SWP_NOSIZE + SWP_NOMOVE + SWP_NOZORDER + SWP_NOACTIVATE + SWP_SHOWWINDOW);
begin
  SetWindowPos(FHandle, 0, 0, 0, 0, 0, ShowFlags[FShowing]);
end;

procedure TWinControl.CMEnabledChanged(var Message: TMessage);
begin
  if not Enabled and (Parent <> nil) then RemoveFocus(False);
  if HandleAllocated and not (csDesigning in ComponentState) then
    EnableWindow(FHandle, Enabled);
end;

procedure TWinControl.CMColorChanged(var Message: TMessage);
begin
  inherited;
  FBrush.Color := FColor;
  NotifyControls(CM_PARENTCOLORCHANGED);
end;

procedure TWinControl.CMFontChanged(var Message: TMessage);
begin
  inherited;
  if HandleAllocated then Perform(WM_SETFONT, FFont.Handle, 0);
  NotifyControls(CM_PARENTFONTCHANGED);
end;

procedure TWinControl.CMCursorChanged(var Message: TMessage);
var
  P: TPoint;
begin
  if GetCapture = 0 then
  begin
    GetCursorPos(P);
    if FindDragTarget(P, False) = Self then
      Perform(WM_SETCURSOR, Handle, HTCLIENT);
  end;
end;

procedure TWinControl.CMBorderChanged(var Message: TMessage);
begin
  inherited;
  if HandleAllocated then SetWindowPos(Handle, 0, 0,0,0,0, SWP_NOACTIVATE or
    SWP_NOZORDER or SWP_NOMOVE or SWP_NOSIZE or SWP_FRAMECHANGED);
end;

procedure TWinControl.CMCtl3DChanged(var Message: TMessage);
begin
  if (csFramed in ControlStyle) and (Parent <> nil) and HandleAllocated and
    IsWindowVisible(FHandle) then InvalidateFrame;
  NotifyControls(CM_PARENTCTL3DCHANGED);
end;

procedure TWinControl.CMParentCtl3DChanged(var Message: TMessage);
begin
  if FParentCtl3D then
  begin
    if Message.wParam <> 0 then
      SetCtl3D(Message.lParam <> 0) else
      SetCtl3D(FParent.FCtl3D);
    FParentCtl3D := True;
  end;
end;

procedure TWinControl.CMSysColorChange(var Message: TMessage);
begin
  Broadcast(Message);
end;

procedure TWinControl.CMWinIniChange(var Message: TWMWinIniChange);
begin
  Broadcast(Message);
end;

procedure TWinControl.CMFontChange(var Message: TMessage);
begin
  Broadcast(Message);
end;

procedure TWinControl.CMTimeChange(var Message: TMessage);
begin
  Broadcast(Message);
end;

procedure TWinControl.CMDrag(var Message: TCMDrag);
begin
  with Message, DragRec^ do
    case DragMessage of
      dmDragEnter, dmDragLeave, dmDragMove, dmDragDrop:
        if Target <> nil then TControl(Target).DoDragMsg(Message);
      dmFindTarget:
        begin
          Result := Longint(ControlAtPos(ScreenToClient(Pos), False));
          if Result = 0 then Result := Longint(Self);
        end;
    end;
end;

procedure TWinControl.CMControlListChange(var Message: TMessage);
begin
  if FParent <> nil then FParent.WindowProc(Message);
end;

procedure TWinControl.CMSysFontChanged(var Message: TMessage);
begin
  inherited;
  Broadcast(Message);
end;

function TWinControl.IsMenuKey(var Message: TWMKey): Boolean;
var
  Control: TWinControl;
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
      if Assigned(LocalPopupMenu) and (LocalPopupMenu.WindowHandle <> 0) and
        LocalPopupMenu.IsShortCut(Message) then Exit;
      Control := Control.Parent;
    end;
    Form := GetParentForm(Self);
    if (Form <> nil) and Form.IsShortCut(Message) then Exit;
  end;
  with Message do
    if SendAppMessage(CM_APPKEYDOWN, CharCode, KeyData) <> 0 then Exit;
  Result := False;
end;

procedure TWinControl.CNKeyDown(var Message: TWMKeyDown);
var
  Mask: Integer;
begin
  with Message do
  begin
    Result := 1;
    if IsMenuKey(Message) then Exit;
    if not (csDesigning in ComponentState) then
    begin
      if Perform(CM_CHILDKEY, CharCode, Integer(Self)) <> 0 then Exit;
      Mask := 0;
      case CharCode of
        VK_TAB:
          Mask := DLGC_WANTTAB;
        VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN:
          Mask := DLGC_WANTARROWS;
        VK_RETURN, VK_EXECUTE, VK_ESCAPE, VK_CANCEL:
          Mask := DLGC_WANTALLKEYS;
      end;
      if (Mask <> 0) and
        (Perform(CM_WANTSPECIALKEY, CharCode, 0) = 0) and
        (Perform(WM_GETDLGCODE, 0, 0) and Mask = 0) and
        (GetParentForm(Self).Perform(CM_DIALOGKEY,
        CharCode, KeyData) <> 0) then Exit;
    end;
    Result := 0;
  end;
end;

procedure TWinControl.CNKeyUp(var Message: TWMKeyUp);
begin
  if not (csDesigning in ComponentState) then
    with Message do
      case CharCode of
        VK_TAB, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
        VK_RETURN, VK_EXECUTE, VK_ESCAPE, VK_CANCEL:
          Result := Perform(CM_WANTSPECIALKEY, CharCode, 0);
      end;
end;

procedure TWinControl.CNChar(var Message: TWMChar);
begin
  if not (csDesigning in ComponentState) then
    with Message do
    begin
      Result := 1;
      if (Perform(WM_GETDLGCODE, 0, 0) and DLGC_WANTCHARS = 0) and
        (GetParentForm(Self).Perform(CM_DIALOGCHAR,
        CharCode, KeyData) <> 0) then Exit;
      Result := 0;
    end;
end;

procedure TWinControl.CNSysKeyDown(var Message: TWMKeyDown);
begin
  with Message do
  begin
    Result := 1;
    if IsMenuKey(Message) then Exit;
    if not (csDesigning in ComponentState) then
    begin
      if Perform(CM_CHILDKEY, CharCode, Integer(Self)) <> 0 then Exit;
      if GetParentForm(Self).Perform(CM_DIALOGKEY,
        CharCode, KeyData) <> 0 then Exit;
    end;
    Result := 0;
  end;
end;

procedure TWinControl.CNSysChar(var Message: TWMChar);
begin
  if not (csDesigning in ComponentState) then
    with Message do
      if CharCode <> VK_SPACE then
        Result := GetParentForm(Self).Perform(CM_DIALOGCHAR,
          CharCode, KeyData);
end;

procedure TWinControl.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
var
  WindowPlacement: TWindowPlacement;
begin
  if (ALeft <> FLeft) or (ATop <> FTop) or
    (AWidth <> FWidth) or (AHeight <> FHeight) then
  begin
    if HandleAllocated and not IsIconic(FHandle) then
      SetWindowPos(FHandle, 0, ALeft, ATop, AWidth, AHeight,
        SWP_NOZORDER + SWP_NOACTIVATE)
    else
    begin
      FLeft := ALeft;
      FTop := ATop;
      FWidth := AWidth;
      FHeight := AHeight;
      if HandleAllocated then
      begin
        WindowPlacement.Length := SizeOf(WindowPlacement);
        GetWindowPlacement(FHandle, @WindowPlacement);
        WindowPlacement.rcNormalPosition := BoundsRect;
        SetWindowPlacement(FHandle, @WindowPlacement);
      end;
    end;
    UpdateAnchorRules;
    RequestAlign;
  end;
end;

procedure TWinControl.ScaleControls(M, D: Integer);
var
  I: Integer;
begin
  for I := 0 to ControlCount - 1 do Controls[I].ChangeScale(M, D);
end;

procedure TWinControl.ChangeScale(M, D: Integer);
begin
  DisableAlign;
  try
    ScaleControls(M, D);
    inherited ChangeScale(M, D);
  finally
    EnableAlign;
  end;
end;

procedure TWinControl.ScaleBy(M, D: Integer);
const
  SWP_HIDE = SWP_NOSIZE + SWP_NOMOVE + SWP_NOZORDER + SWP_NOACTIVATE + SWP_HIDEWINDOW;
  SWP_SHOW = SWP_NOSIZE + SWP_NOMOVE + SWP_NOZORDER + SWP_NOACTIVATE + SWP_SHOWWINDOW;
var
  IsVisible: Boolean;
  R: TRect;
begin
  IsVisible := HandleAllocated and IsWindowVisible(Handle);
  if IsVisible then SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_HIDE);
  R := BoundsRect;
  ChangeScale(M, D);
  SetBounds(R.Left, R.Top, Width, Height);
  if IsVisible then SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_SHOW);
end;

procedure TWinControl.ScrollBy(DeltaX, DeltaY: Integer);
var
  IsVisible: Boolean;
  I: Integer;
  Control: TControl;
begin
  IsVisible := (FHandle <> 0) and IsWindowVisible(FHandle);
  if IsVisible then ScrollWindow(FHandle, DeltaX, DeltaY, nil, nil);
  for I := 0 to ControlCount - 1 do
  begin
    Control := Controls[I];
    if not (Control is TWinControl) or (TWinControl(Control).FHandle = 0) then
    begin
      Inc(Control.FLeft, DeltaX);
      Inc(Control.FTop, DeltaY);
    end else
      if not IsVisible then
        with TWinControl(Control) do
          SetWindowPos(FHandle, 0, FLeft + DeltaX, FTop + DeltaY,
            FWidth, FHeight, SWP_NOZORDER + SWP_NOACTIVATE);
  end;
  Realign;
end;

procedure TWinControl.ShowControl(AControl: TControl);
begin
  if Parent <> nil then Parent.ShowControl(Self);
end;

procedure TWinControl.SetZOrderPosition(Position: Integer);
var
  I, Count: Integer;
  Pos: HWND;
begin
  if FParent <> nil then
  begin
    if FParent.FControls <> nil then
      Dec(Position, FParent.FControls.Count);
    I := FParent.FWinControls.IndexOf(Self);
    if I >= 0 then
    begin
      Count := FParent.FWinControls.Count;
      if Position < 0 then Position := 0;
      if Position >= Count then Position := Count - 1;
      if Position <> I then
      begin
        FParent.FWinControls.Delete(I);
        FParent.FWinControls.Insert(Position, Self);
      end;
    end;
    if FHandle <> 0 then
    begin
      if Position = 0 then Pos := HWND_BOTTOM
      else if Position = FParent.FWinControls.Count - 1 then Pos := HWND_TOP
      else if Position > I then
        Pos := TWinControl(FParent.FWinControls[Position + 1]).Handle
      else if Position < I then
        Pos := TWinControl(FParent.FWinControls[Position]).Handle
      else Exit;
      SetWindowPos(FHandle, Pos, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE);
    end;
  end;
end;

procedure TWinControl.SetZOrder(TopMost: Boolean);
const
  WindowPos: array[Boolean] of Word = (HWND_BOTTOM, HWND_TOP);
var
  N, M: Integer;
begin
  if FParent <> nil then
  begin
    if TopMost then N := FParent.FWinControls.Count - 1 else N := 0;
    M := 0;
    if FParent.FControls <> nil then M := FParent.FControls.Count;
    SetZOrderPosition(M + N);
  end
  else if FHandle <> 0 then
    SetWindowPos(FHandle, WindowPos[TopMost], 0, 0, 0, 0,
      SWP_NOMOVE + SWP_NOSIZE);
end;

function TWinControl.GetDeviceContext(var WindowHandle: HWnd): HDC;
begin
  if csDesigning in ComponentState then
    Result := GetDCEx(Handle, 0, DCX_CACHE or DCX_CLIPSIBLINGS)
  else
    Result := GetDC(Handle);
  if Result = 0 then raise EOutOfResources.CreateRes(@SWindowDCError);
  WindowHandle := FHandle;
end;

function TWinControl.GetParentHandle: HWnd;
begin
  if Parent <> nil then
    Result := Parent.Handle
  else
    Result := ParentWindow;
end;

function TWinControl.GetTopParentHandle: HWnd;
var
  C: TWinControl;
begin
  C := Self;
  while C.Parent <> nil do
    C := C.Parent;
  Result := C.ParentWindow;
  if Result = 0 then Result := C.Handle;
end;

procedure TWinControl.Invalidate;
begin
  Perform(CM_INVALIDATE, 0, 0);
end;

procedure TWinControl.CMInvalidate(var Message: TMessage);
begin
  if HandleAllocated then
  begin
    if Parent <> nil then Parent.Perform(CM_INVALIDATE, 1, 0);
    if Message.WParam = 0 then
      InvalidateRect(FHandle, nil, not (csOpaque in ControlStyle));
  end;
end;

procedure TWinControl.Update;
begin
  if HandleAllocated then UpdateWindow(FHandle);
end;

procedure TWinControl.Repaint;
begin
  Invalidate;
  Update;
end;

procedure TWinControl.InvalidateFrame;
var
  R: TRect;
begin
  R := BoundsRect;
  InflateRect(R, 1, 1);
  InvalidateRect(Parent.FHandle, @R, True);
end;

function TWinControl.CanFocus: Boolean;
var
  Control: TWinControl;
  Form: TCustomForm;
begin
  Result := False;
  Form := GetParentForm(Self);
  if Form <> nil then
  begin
    Control := Self;
    while Control <> Form do
    begin
      if not (Control.FVisible and Control.Enabled) then Exit;
      Control := Control.Parent;
    end;
    Result := True;
  end;
end;

procedure TWinControl.SetFocus;
var
  Parent: TCustomForm;
begin
  Parent := GetParentForm(Self);
  if Parent <> nil then
    Parent.FocusControl(Self)
  else if ParentWindow <> 0 then
    Windows.SetFocus(Handle)
  else
    ValidParentForm(Self);
end;

function TWinControl.Focused: Boolean;
begin
  Result := (FHandle <> 0) and (GetFocus = FHandle);
end;

procedure TWinControl.HandleNeeded;
begin
  if FHandle = 0 then
  begin
    if Parent <> nil then Parent.HandleNeeded;
    CreateHandle;
  end;
end;

function TWinControl.GetHandle: HWnd;
begin
  HandleNeeded;
  Result := FHandle;
end;

function TWinControl.GetControlExtents: TRect;
var
  I: Integer;
begin
  Result := Rect(MaxInt, MaxInt, 0, 0);
  for I := 0 to ControlCount - 1 do
    with Controls[I] do
      if Visible or (csDesigning in ComponentState) and
        not (csNoDesignVisible in ControlStyle) then
      begin
        if Left < Result.Left then Result.Left := Left;
        if Top < Result.Top then Result.Top := Top;
        if Left + Width > Result.Right then Result.Right := Left + Width;
        if Top + Height > Result.Bottom then Result.Bottom := Top + Height;
      end;
end;

function TWinControl.GetClientOrigin: TPoint;
begin
  Result.X := 0;
  Result.Y := 0;
  Windows.ClientToScreen(Handle, Result);
end;

function TWinControl.GetClientRect: TRect;
begin
  Windows.GetClientRect(Handle, Result);
end;

procedure TWinControl.AdjustSize;
begin
  if not (csLoading in ComponentState) and HandleAllocated then
  begin
    SetWindowPos(Handle, 0, 0, 0, Width, Height, SWP_NOACTIVATE or SWP_NOMOVE or
      SWP_NOZORDER);
    RequestAlign;
  end;
end;

procedure TWinControl.SetBorderWidth(Value: TBorderWidth);
begin
  if FBorderWidth <> Value then
  begin
    FBorderWidth := Value;
    Perform(CM_BORDERCHANGED, 0, 0);
  end;
end;

procedure TWinControl.SetCtl3D(Value: Boolean);
begin
  if FCtl3D <> Value then
  begin
    FCtl3D := Value;
    FParentCtl3D := False;
    Perform(CM_CTL3DCHANGED, 0, 0);
  end;
end;

function TWinControl.IsCtl3DStored: Boolean;
begin
  Result := not ParentCtl3D;
end;

procedure TWinControl.SetParentCtl3D(Value: Boolean);
begin
  if FParentCtl3D <> Value then
  begin
    FParentCtl3D := Value;
    if FParent <> nil then Perform(CM_PARENTCTL3DCHANGED, 0, 0);
  end;
end;

function TWinControl.GetTabOrder: TTabOrder;
begin
  if FParent <> nil then
    Result := FParent.FTabList.IndexOf(Self)
  else
    Result := -1;
end;

procedure TWinControl.UpdateTabOrder(Value: TTabOrder);
var
  CurIndex, Count: Integer;
begin
  CurIndex := GetTabOrder;
  if CurIndex >= 0 then
  begin
    Count := FParent.FTabList.Count;
    if Value < 0 then Value := 0;
    if Value >= Count then Value := Count - 1;
    if Value <> CurIndex then
    begin
      FParent.FTabList.Delete(CurIndex);
      FParent.FTabList.Insert(Value, Self);
    end;
  end;
end;

procedure TWinControl.SetTabOrder(Value: TTabOrder);
begin
  if csReadingState in ControlState then
    FTabOrder := Value else
    UpdateTabOrder(Value);
end;

procedure TWinControl.SetTabStop(Value: Boolean);
var
  Style: Longint;
begin
  if FTabStop <> Value then
  begin
    FTabStop := Value;
    if HandleAllocated then
    begin
      Style := GetWindowLong(FHandle, GWL_STYLE) and not WS_TABSTOP;
      if Value then Style := Style or WS_TABSTOP;
      SetWindowLong(FHandle, GWL_STYLE, Style);
    end;
    Perform(CM_TABSTOPCHANGED, 0, 0);
  end;
end;

procedure TWinControl.SetUseDockManager(Value: Boolean);
begin
  if FUseDockManager <> Value then
  begin
    FUseDockManager := Value;
    if not (csDesigning in ComponentState) and Value then
      FDockManager := CreateDockManager;
  end;
end;

function TWinControl.HandleAllocated: Boolean;
begin
  Result := FHandle <> 0;
end;

procedure TWinControl.UpdateBounds;
var
  ParentHandle: HWnd;
  Rect: TRect;
  WindowPlacement: TWindowPlacement;
begin
  if IsIconic(FHandle) then
  begin
    WindowPlacement.Length := SizeOf(WindowPlacement);
    GetWindowPlacement(FHandle, @WindowPlacement);
    Rect := WindowPlacement.rcNormalPosition;
  end else
    GetWindowRect(FHandle, Rect);
  if GetWindowLong(FHandle, GWL_STYLE) and WS_CHILD <> 0 then
  begin
    ParentHandle := GetWindowLong(FHandle, GWL_HWNDPARENT);
    if ParentHandle <> 0 then
    begin
      Windows.ScreenToClient(ParentHandle, Rect.TopLeft);
      Windows.ScreenToClient(ParentHandle, Rect.BottomRight);
    end;
  end;
  FLeft := Rect.Left;
  FTop := Rect.Top;
  FWidth := Rect.Right - Rect.Left;
  FHeight := Rect.Bottom - Rect.Top;
  UpdateAnchorRules;
end;

procedure TWinControl.GetTabOrderList(List: TList);
var
  I: Integer;
  Control: TWinControl;
begin
  if FTabList <> nil then
    for I := 0 to FTabList.Count - 1 do
    begin
      Control := FTabList[I];
      List.Add(Control);
      Control.GetTabOrderList(List);
    end;
end;

function TWinControl.FindNextControl(CurControl: TWinControl;
  GoForward, CheckTabStop, CheckParent: Boolean): TWinControl;
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

procedure TWinControl.SelectNext(CurControl: TWinControl;
  GoForward, CheckTabStop: Boolean);
begin
  CurControl := FindNextControl(CurControl, GoForward,
    CheckTabStop, not CheckTabStop);
  if CurControl <> nil then CurControl.SetFocus;
end;

procedure TWinControl.SelectFirst;
var
  Form: TCustomForm;
  Control: TWinControl;
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

procedure TWinControl.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
  Control: TControl;
begin
  for I := 0 to ControlCount - 1 do
  begin
    Control := Controls[I];
    if Control.Owner = Root then Proc(Control);
  end;
end;

procedure TWinControl.SetChildOrder(Child: TComponent; Order: Integer);
begin
  if Child is TWinControl then
    TWinControl(Child).SetZOrderPosition(Order)
  else if Child is TControl then
    TControl(Child).SetZOrderPosition(Order);
end;


function TWinControl.CanResize(var NewWidth, NewHeight: Integer): Boolean;
begin
  Result := inherited CanResize(NewWidth, NewHeight);
end;

procedure TWinControl.CalcConstraints(var MinWidth, MinHeight, MaxWidth,
  MaxHeight: Integer);
type
  TScale = (sNone, sReg, sStretch, sOther);
var
  AdjustMinWidth, AdjustMinHeight, AdjustMaxWidth, AdjustMaxHeight: Integer;
  I, TotalMinWidth, TotalMaxWidth, TotalMinHeight, TotalMaxHeight: Integer;
  TotalMinWidth2, TotalMaxWidth2, TotalMinHeight2, TotalMaxHeight2: Integer;
  ControlMinWidth, ControlMaxWidth, ControlMinHeight, ControlMaxHeight: Integer;
  Control: TControl;
  R: TRect;

  WidthScale: TScale;
  HeightScale: TScale;

  procedure DoCalcConstraints(Control: TControl; var MinWidth, MinHeight,
    MaxWidth, MaxHeight: Integer);
  begin
    with Control do
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
    end;
  end;

begin
  if not HandleAllocated or (ControlCount = 0) then Exit;
  { Adjust min/max size to compensate for non-client area }
  R := GetClientRect;
  AdjustClientRect(R);
  if IsRectEmpty(R) then Exit; // Coming from an icon view, don't do constraints
  AdjustMinWidth := Width - (R.Right - R.Left);
  AdjustMinHeight := Height - (R.Bottom - R.Top);
  AdjustMaxWidth := Width - (R.Right - R.Left);
  AdjustMaxHeight := Height - (R.Bottom - R.Top);
  if MinWidth > 0 then Dec(MinWidth, AdjustMinWidth);
  if MinHeight > 0 then Dec(MinHeight, AdjustMinHeight);
  if MaxWidth > 0 then Dec(MaxWidth, AdjustMaxWidth);
  if MaxHeight > 0 then Dec(MaxHeight, AdjustMaxHeight);
  { Compare incoming min/max constraints with those that we calculate }
  try
    TotalMinWidth := 0;
    TotalMinWidth2 := 0;
    TotalMaxWidth := 0;
    TotalMaxWidth2 := 0;
    TotalMinHeight := 0;
    TotalMinHeight2 := 0;
    TotalMaxHeight := 0;
    TotalMaxHeight2 := 0;
    for I := 0 to ControlCount - 1 do
    begin
      Control := Controls[I];
      with Control do
        if Visible or (csDesigning in ComponentState) and
          not (csNoDesignVisible in ControlStyle) then
        begin
          DoCalcConstraints(Control, ControlMinWidth, ControlMinHeight,
            ControlMaxWidth, ControlMaxHeight);

          case Align of
            alTop, alBottom: WidthScale := sReg;
            alClient: WidthScale := sStretch;
            alNone:
              if Anchors * [akLeft, akRight] = [akLeft, akRight] then
              begin
                WidthScale := sReg;
                { Adjust Anchored controls }
                if ControlMinWidth > 0 then
                  ControlMinWidth := (R.Right - R.Left) - Width - ControlMinWidth;
                if ControlMaxWidth > 0 then
                  ControlMaxWidth := (R.Right - R.Left) + ControlMaxWidth - Width;
              end
              else
                WidthScale := sNone;
          else
            WidthScale := sOther;
          end;

          case Align of
            alLeft, alRight: HeightScale := sReg;
            alClient: HeightScale := sStretch;
            alNone:
              if Anchors * [akTop, akBottom] = [akTop, akBottom] then
              begin
                HeightScale := sReg;
                { Adjust Anchored controls }
                if ControlMinHeight > 0 then
                  ControlMinHeight := (R.Bottom - R.Top) - Height - ControlMinHeight;
                if ControlMaxHeight > 0 then
                  ControlMaxHeight := (R.Bottom - R.Top) + ControlMaxHeight - Height;
              end
              else
                HeightScale := sNone;
          else
            HeightScale := sOther;
          end;

          { Calculate min/max width }
          case WidthScale of
            sReg, sStretch:
              begin
                if (ControlMinWidth > 0) and (ControlMinWidth > MinWidth) then
                begin
                  MinWidth := ControlMinWidth;
                  if MinWidth > TotalMinWidth then
                    TotalMinWidth := MinWidth;
                end;
                if (ControlMaxWidth > 0) and (ControlMaxWidth < MaxWidth) then
                begin
                  MaxWidth := ControlMaxWidth;
                  if MaxWidth > TotalMaxWidth then
                    TotalMaxWidth := MaxWidth;
                end;
              end;
            sOther:
              begin
                Inc(TotalMinWidth2, Width);
                Inc(TotalMaxWidth2, Width);
              end;
          end;

          { Calculate min/max height }
          case HeightScale of
            sReg, sStretch:
              begin
                if (ControlMinHeight > 0) and (ControlMinHeight > MinHeight) then
                begin
                  MinHeight := ControlMinHeight;
                  if MinHeight > TotalMinHeight then
                    TotalMinHeight := MinHeight;
                end;
                if (ControlMaxHeight > 0) and (ControlMaxHeight < MaxHeight) then
                begin
                  MaxHeight := ControlMaxHeight;
                  if MaxHeight > TotalMaxHeight then
                    TotalMaxHeight := MaxHeight;
                end;
              end;
            sOther:
              begin
                Inc(TotalMinHeight2, Height);
                Inc(TotalMaxHeight2, Height);
              end;
          end;
        end;
    end;
    if (TotalMinWidth > 0) and (TotalMinWidth+TotalMinWidth2 > MinWidth) then
      MinWidth := TotalMinWidth+TotalMinWidth2;
    if (TotalMaxWidth > 0) and ((MaxWidth = 0) or (TotalMaxWidth+TotalMaxWidth2 > MaxWidth)) then
      MaxWidth := TotalMaxWidth+TotalMaxWidth2;
    if (TotalMinHeight > 0) and (TotalMinHeight+TotalMinHeight2 > MinHeight) then
      MinHeight := TotalMinHeight+TotalMinHeight2;
    if (TotalMaxHeight > 0) and ((MaxHeight = 0) or (TotalMaxHeight+TotalMaxHeight2 > MaxHeight)) then
      MaxHeight := TotalMaxHeight+TotalMaxHeight2;
  finally
    if MinWidth > 0 then Inc(MinWidth, AdjustMinWidth);
    if MinHeight > 0 then Inc(MinHeight, AdjustMinHeight);
    if MaxWidth > 0 then Inc(MaxWidth, AdjustMaxWidth);
    if MaxHeight > 0 then Inc(MaxHeight, AdjustMaxHeight);
  end;
end;

procedure TWinControl.ConstrainedResize(var MinWidth, MinHeight, MaxWidth,
  MaxHeight: Integer);
begin
  CalcConstraints(MinWidth, MinHeight, MaxWidth, MaxHeight);
  inherited ConstrainedResize(MinWidth, MinHeight, MaxWidth, MaxHeight);
end;

procedure TWinControl.ActionChange(Sender: TObject; CheckDefaults: Boolean);
begin
  inherited ActionChange(Sender, CheckDefaults);
  if Sender is TCustomAction then
    with TCustomAction(Sender) do
    if not CheckDefaults or (Self.HelpContext = 0) then
      Self.HelpContext := HelpContext;
end;

function TWinControl.GetActionLinkClass: TControlActionLinkClass;
begin
  Result := TWinControlActionLink;
end;

function TWinControl.IsHelpContextStored: Boolean;
begin
  Result := (ActionLink = nil) or not ActionLink.IsHelpContextLinked;
end;

procedure TWinControl.AssignTo(Dest: TPersistent);
begin
  inherited AssignTo(Dest);
  if Dest is TCustomAction then TCustomAction(Dest).HelpContext := HelpContext;
end;

function TWinControl.CanAutoSize(var NewWidth, NewHeight: Integer): Boolean;
var
  I, LeftOffset, TopOffset: Integer;
  Extents, R: TRect;
begin
  Result := True;
  { Restrict size to visible extents of children }
  if HandleAllocated and (Align <> alClient) and
    (not (csDesigning in ComponentState) or (ControlCount > 0)) then
  begin
    Extents := GetControlExtents;
    { Here's where HandleAllocated is needed }
    R := GetClientRect;
    AdjustClientRect(R);
    DisableAlign;
    try
      for I := 0 to ControlCount - 1 do
        with Controls[I] do
          if Visible or (csDesigning in ComponentState) and
            not (csNoDesignVisible in ControlStyle) then
          begin
            if Self.Align in [alNone, alLeft, alRight] then
              LeftOffset := Extents.Left - R.Left else
              LeftOffset := 0;
            if Self.Align in [alNone, alTop, alBottom] then
              TopOffset := Extents.Top - R.Top else
              TopOffset := 0;
            SetBounds(Left - LeftOffset, Top - TopOffset, Width, Height);
          end;
    finally
      Exclude(FControlState, csAlignmentNeeded);
      EnableAlign;
    end;
    if Align in [alNone, alLeft, alRight] then
      if Extents.Right - Extents.Left > 0 then
      begin
        NewWidth := Extents.Right - Extents.Left + Width - (R.Right - R.Left);
        if Align = alRight then RequestAlign;
      end
      else
        NewWidth := 0;
    if Align in [alNone, alTop, alBottom] then
      if Extents.Bottom - Extents.Top > 0 then
      begin
        NewHeight := Extents.Bottom - Extents.Top + Height - (R.Bottom - R.Top);
        if Align = alBottom then RequestAlign;
      end
      else
        NewHeight := 0;
  end;
end;

procedure TWinControl.SetBevelCut(Index: Integer; const Value: TBevelCut);
begin
  case Index of
    0: { BevelInner }
      if Value <> FBevelInner then
      begin
        FBevelInner := Value;
        Perform(CM_BORDERCHANGED, 0, 0);
      end;
    1: { BevelOuter }
      if Value <> FBevelOuter then
      begin
        FBevelOuter := Value;
        Perform(CM_BORDERCHANGED, 0, 0);
      end;
  end;
end;

procedure TWinControl.SetBevelEdges(const Value: TBevelEdges);
begin
  if Value <> FBevelEdges then
  begin
    FBevelEdges := Value;
    Perform(CM_BORDERCHANGED, 0, 0);
  end;
end;

procedure TWinControl.SetBevelKind(const Value: TBevelKind);
begin
  if Value <> FBevelKind then
  begin
    FBevelKind := Value;
    Perform(CM_BORDERCHANGED, 0, 0);
  end;
end;

procedure TWinControl.SetBevelWidth(const Value: TBevelWidth);
begin
  if Value <> FBevelWidth then
  begin
    FBevelWidth := Value;
    Perform(CM_BORDERCHANGED, 0, 0);
  end;
end;

procedure TWinControl.WMNCCalcSize(var Message: TWMNCCalcSize);
var
  EdgeSize: Integer;
begin
  inherited;
  with Message.CalcSize_Params^ do
  begin
    InflateRect(rgrc[0], -BorderWidth, -BorderWidth);
    if BevelKind <> bkNone then
    begin
      EdgeSize := 0;
      if BevelInner <> bvNone then Inc(EdgeSize, BevelWidth);
      if BevelOuter <> bvNone then Inc(EdgeSize, BevelWidth);
      with rgrc[0] do
      begin
        if beLeft in BevelEdges then Inc(Left, EdgeSize);
        if beTop in BevelEdges then Inc(Top, EdgeSize);
        if beRight in BevelEdges then Dec(Right, EdgeSize);
        if beBottom in BevelEdges then Dec(Bottom, EdgeSize);
      end;
    end;
  end;
end;

procedure TWinControl.WMNCPaint(var Message: TMessage);
const
  InnerStyles: array[TBevelCut] of Integer = (0, BDR_SUNKENINNER, BDR_RAISEDINNER, 0);
  OuterStyles: array[TBevelCut] of Integer = (0, BDR_SUNKENOUTER, BDR_RAISEDOUTER, 0);
  EdgeStyles: array[TBevelKind] of Integer = (0, 0, BF_SOFT, BF_FLAT);
  Ctl3DStyles: array[Boolean] of Integer = (BF_MONO, 0);
var
  DC: HDC;
  RC, RW, SaveRW: TRect;
  EdgeSize: Integer;
  WinStyle: Longint;
begin
  { Get window DC that is clipped to the non-client area }
  if (BevelKind <> bkNone) or (BorderWidth > 0) then
  begin
    DC := GetWindowDC(Handle);
    try
      Windows.GetClientRect(Handle, RC);
      GetWindowRect(Handle, RW);
      MapWindowPoints(0, Handle, RW, 2);
      OffsetRect(RC, -RW.Left, -RW.Top);
      ExcludeClipRect(DC, RC.Left, RC.Top, RC.Right, RC.Bottom);
      { Draw borders in non-client area }
      SaveRW := RW;
      InflateRect(RC, BorderWidth, BorderWidth);
      RW := RC;
      if BevelKind <> bkNone then
      begin
        EdgeSize := 0;
        if BevelInner <> bvNone then Inc(EdgeSize, BevelWidth);
        if BevelOuter <> bvNone then Inc(EdgeSize, BevelWidth);
        with RW do
        begin
          WinStyle := GetWindowLong(Handle, GWL_STYLE);
          if beLeft in BevelEdges then Dec(Left, EdgeSize);
          if beTop in BevelEdges then Dec(Top, EdgeSize);
          if beRight in BevelEdges then Inc(Right, EdgeSize);
          if (WinStyle and WS_VSCROLL) <> 0 then Inc(Right, GetSystemMetrics(SM_CYVSCROLL));
          if beBottom in BevelEdges then Inc(Bottom, EdgeSize);
          if (WinStyle and WS_HSCROLL) <> 0 then Inc(Bottom, GetSystemMetrics(SM_CXHSCROLL));
        end;
        DrawEdge(DC, RW, InnerStyles[BevelInner] or OuterStyles[BevelOuter],
          Byte(BevelEdges) or EdgeStyles[BevelKind] or Ctl3DStyles[Ctl3D] or BF_ADJUST);
      end;
      IntersectClipRect(DC, RW.Left, RW.Top, RW.Right, RW.Bottom);
      RW := SaveRW;
      { Erase parts not drawn }
      OffsetRect(RW, -RW.Left, -RW.Top);
      Windows.FillRect(DC, RW, Brush.Handle);
    finally
      ReleaseDC(Handle, DC);
    end;
  end;
  inherited;
end;

function TWinControl.FindChildControl(const ControlName: string): TControl;
var
  I: Integer;
begin
  Result := nil;
  if FWinControls <> nil then
    for I := 0 to FWinControls.Count - 1 do
      if CompareText(TWinControl(FWinControls[I]).Name, ControlName) = 0 then
      begin
        Result := FWinControls[I];
        Exit;
      end;
end;

procedure TWinControl.WMContextMenu(var Message: TWMContextMenu);
var
  Ctrl: TControl;
begin
  if Message.Result <> 0 then Exit;
  Ctrl := ControlAtPos(ScreenToClient(SmallPointToPoint(Message.Pos)), False);
  if Ctrl <> nil then
    Message.Result := Ctrl.Perform(WM_CONTEXTMENU, 0, Integer(Message.Pos));

  if Message.Result = 0 then
    inherited;
end;

{ TGraphicControl }

constructor TGraphicControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCanvas := TControlCanvas.Create;
  TControlCanvas(FCanvas).Control := Self;
end;

destructor TGraphicControl.Destroy;
begin
  if CaptureControl = Self then SetCaptureControl(nil);
  FCanvas.Free;
  inherited Destroy;
end;

procedure TGraphicControl.WMPaint(var Message: TWMPaint);
begin
  if Message.DC <> 0 then
  begin
    Canvas.Lock;
    try
      Canvas.Handle := Message.DC;
      try
        Paint;
      finally
        Canvas.Handle := 0;
      end;
    finally
      Canvas.Unlock;
    end;
  end;
end;

procedure TGraphicControl.Paint;
begin
end;

{ THintWindow }

constructor THintWindow.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Color := $80FFFF;
  Canvas.Font := Screen.HintFont;
  Canvas.Brush.Style := bsClear;
end;

procedure THintWindow.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  with Params do
  begin
    Style := WS_POPUP or WS_BORDER;
    WindowClass.Style := WindowClass.Style or CS_SAVEBITS;
    if NewStyleControls then ExStyle := WS_EX_TOOLWINDOW;
    AddBiDiModeExStyle(ExStyle);
  end;
end;

procedure THintWindow.WMNCHitTest(var Message: TWMNCHitTest);
begin
  Message.Result := HTTRANSPARENT;
end;

procedure THintWindow.WMNCPaint(var Message: TMessage);
var
  DC: HDC;
  R: TRect;
begin
  DC := GetWindowDC(Handle);
  try
    R := Rect(0, 0, Width, Height);
    DrawEdge(DC, R, BDR_RAISEDOUTER, BF_RECT);
  finally
    ReleaseDC(Handle, DC);
  end;
end;

procedure THintWindow.Paint;
var
  R: TRect;
begin
  R := ClientRect;
  Inc(R.Left, 2);
  Inc(R.Top, 2);
  Canvas.Font.Color := clInfoText;
  DrawText(Canvas.Handle, PChar(Caption), -1, R, DT_LEFT or DT_NOPREFIX or
    DT_WORDBREAK or DrawTextBiDiModeFlagsReadingOnly);
end;

function THintWindow.IsHintMsg(var Msg: TMsg): Boolean;
begin
  with Msg do
    Result := ((Message >= WM_KEYFIRST) and (Message <= WM_KEYLAST)) or
      ((Message = CM_ACTIVATE) or (Message = CM_DEACTIVATE)) or
      (Message = CM_APPKEYDOWN) or (Message = CM_APPSYSCOMMAND) or
      (Message = WM_COMMAND) or ((Message > WM_MOUSEMOVE) and
      (Message <= WM_MOUSELAST)) or (Message = WM_NCMOUSEMOVE);
end;

procedure THintWindow.ReleaseHandle;
begin
  DestroyHandle;
end;

procedure THintWindow.CMTextChanged(var Message: TMessage);
begin
  inherited;
  { Avoid flicker when calling ActivateHint }
  if FActivating then Exit;
  Width := Canvas.TextWidth(Caption) + 6;
  Height := Canvas.TextHeight(Caption) + 4;
end;

procedure THintWindow.ActivateHint(Rect: TRect; const AHint: string);
begin
  FActivating := True;
  try
    Caption := AHint;
    Inc(Rect.Bottom, 4);
    UpdateBoundsRect(Rect);
    if Rect.Top + Height > Screen.DesktopHeight then
      Rect.Top := Screen.DesktopHeight - Height;
    if Rect.Left + Width > Screen.DesktopWidth then
      Rect.Left := Screen.DesktopWidth - Width;
    if Rect.Left < Screen.DesktopLeft then Rect.Left := Screen.DesktopLeft;
    if Rect.Bottom < Screen.DesktopTop then Rect.Bottom := Screen.DesktopTop;
    SetWindowPos(Handle, HWND_TOPMOST, Rect.Left, Rect.Top, Width, Height,
      SWP_SHOWWINDOW or SWP_NOACTIVATE);
    Invalidate;
  finally
    FActivating := False;
  end;
end;

procedure THintWindow.ActivateHintData(Rect: TRect; const AHint: string; AData: Pointer);
begin
  ActivateHint(Rect, AHint);
end;

function THintWindow.CalcHintRect(MaxWidth: Integer; const AHint: string; AData: Pointer): TRect;
begin
  Result := Rect(0, 0, MaxWidth, 0);
  DrawText(Canvas.Handle, PChar(AHint), -1, Result, DT_CALCRECT or DT_LEFT or
    DT_WORDBREAK or DT_NOPREFIX or DrawTextBiDiModeFlagsReadingOnly);
  Inc(Result.Right, 6);
  Inc(Result.Bottom, 2);
end;

{ TDragImageList }

function ClientToWindow(Handle: HWND; X, Y: Integer): TPoint;
var
  Rect: TRect;
  Point: TPoint;
begin
  Point.X := X;
  Point.Y := Y;
  ClientToScreen(Handle, Point);
  GetWindowRect(Handle, Rect);
  Result.X := Point.X - Rect.Left;
  Result.Y := Point.Y - Rect.Top;
end;

procedure TDragImageList.Initialize;
begin
  inherited Initialize;
  DragCursor := crNone;
end;

procedure TDragImageList.CombineDragCursor;
var
  TempList: HImageList;
  Point: TPoint;
begin
  if DragCursor <> crNone then
  begin
    TempList := ImageList_Create(GetSystemMetrics(SM_CXCURSOR),
      GetSystemMetrics(SM_CYCURSOR), ILC_MASK, 1, 1);
    try
      ImageList_AddIcon(TempList, Screen.Cursors[DragCursor]);
      ImageList_AddIcon(TempList, Screen.Cursors[DragCursor]);
      ImageList_SetDragCursorImage(TempList, 0, 0, 0);
      ImageList_GetDragImage(nil, @Point);
      ImageList_SetDragCursorImage(TempList, 1, Point.X, Point.Y);
    finally
      ImageList_Destroy(TempList);
    end;
  end;
end;

function TDragImageList.SetDragImage(Index, HotSpotX, HotSpotY: Integer): Boolean;
begin
  if HandleAllocated then
  begin
    FDragIndex := Index;
    FDragHotspot.x := HotSpotX;
    FDragHotspot.y := HotSpotY;
    ImageList_BeginDrag(Handle, Index, HotSpotX, HotSpotY);
    Result := True;
    FDragging := Result;
  end
  else Result := False;
end;

procedure TDragImageList.SetDragCursor(Value: TCursor);
begin
  if Value <> DragCursor then
  begin
    FDragCursor := Value;
    if Dragging then CombineDragCursor;
  end;
end;

function TDragImageList.GetHotSpot: TPoint;
begin
  Result := inherited GetHotSpot;
  if HandleAllocated and Dragging then
    ImageList_GetDragImage(nil, @Result);
end;

function TDragImageList.BeginDrag(Window: HWND; X, Y: Integer): Boolean;
begin
  Result := False;
  if HandleAllocated then
  begin
    if not Dragging then SetDragImage(FDragIndex, FDragHotspot.x, FDragHotspot.y);
    CombineDragCursor;
    Result := DragLock(Window, X, Y);
    if Result then ShowCursor(False);
  end;
end;

function TDragImageList.DragLock(Window: HWND; XPos, YPos: Integer): Boolean;
begin
  Result := False;
  if HandleAllocated and (Window <> FDragHandle) then
  begin
    DragUnlock;
    FDragHandle := Window;
    with ClientToWindow(FDragHandle, XPos, YPos) do
      Result := ImageList_DragEnter(FDragHandle, X, Y);
  end;
end;

procedure TDragImageList.DragUnlock;
begin
  if HandleAllocated and (FDragHandle <> 0) then
  begin
    ImageList_DragLeave(FDragHandle);
    FDragHandle := 0;
  end;
end;

function TDragImageList.DragMove(X, Y: Integer): Boolean;
begin
  if HandleAllocated then
    with ClientToWindow(FDragHandle, X, Y) do
      Result := ImageList_DragMove(X, Y)
  else
    Result := False;
end;

procedure TDragImageList.ShowDragImage;
begin
  if HandleAllocated then ImageList_DragShowNoLock(True);
end;

procedure TDragImageList.HideDragImage;
begin
  if HandleAllocated then ImageList_DragShowNoLock(False);
end;

function TDragImageList.EndDrag: Boolean;
begin
  if HandleAllocated and Dragging then
  begin
    DragUnlock;
    Result := ImageList_EndDrag;
    FDragging := False;
    DragCursor := crNone;
    ShowCursor(True);
  end
  else Result := False;
end;

{ TCustomControl }

constructor TCustomControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCanvas := TControlCanvas.Create;
  TControlCanvas(FCanvas).Control := Self;
end;

destructor TCustomControl.Destroy;
begin
  FCanvas.Free;
  inherited Destroy;
end;

procedure TCustomControl.WMPaint(var Message: TWMPaint);
begin
  Include(FControlState, csCustomPaint);
  inherited;
  Exclude(FControlState, csCustomPaint);
end;

procedure TCustomControl.PaintWindow(DC: HDC);
begin
  FCanvas.Lock;
  try
    FCanvas.Handle := DC;
    try
      TControlCanvas(FCanvas).UpdateTextFlags;
      Paint;
    finally
      FCanvas.Handle := 0;
    end;
  finally
    FCanvas.Unlock;
  end;
end;

procedure TCustomControl.Paint;
begin
end;

{ TDockZone }

constructor TDockZone.Create(Tree: TDockTree);
begin
  FTree := Tree;
end;

function TDockZone.GetChildCount: Integer;
var
  Zone: TDockZone;
begin
  Result := 0;
  Zone := FChildZones;
  while Zone <> nil do
  begin
    Zone := Zone.FNextSibling;
    Inc(Result);
  end;
end;

function TDockZone.GetLimitBegin: Integer;
var
  CheckZone: TDockZone;
begin
  if FTree.FTopZone = Self then CheckZone := Self
  else CheckZone := FParentZone;
  if CheckZone.FOrientation = doHorizontal then Result := Top
  else if CheckZone.FOrientation = doVertical then Result := Left
  else raise Exception.Create('');
end;

function TDockZone.GetLimitSize: Integer;
var
  CheckZone: TDockZone;
begin
  if FTree.FTopZone = Self then CheckZone := Self
  else CheckZone := FParentZone;
  if CheckZone.FOrientation = doHorizontal then Result := Height
  else if CheckZone.FOrientation = doVertical then Result := Width
  else raise Exception.Create('');
end;

function TDockZone.GetTopLeft(Orient: Integer{TDockOrientation}): Integer;
var
  Zone: TDockZone;
  R: TRect;
begin
  Zone := Self;
  while Zone <> FTree.FTopZone do
  begin
    if (Zone.FParentZone.FOrientation = TDockOrientation(Orient)) and
      (Zone.FPrevSibling <> nil) then
    begin
      Result := Zone.FPrevSibling.FZoneLimit;
      Exit;
    end
    else
      Zone := Zone.FParentZone;
  end;
  R := FTree.FDockSite.ClientRect;
  FTree.FDockSite.AdjustClientRect(R);
  case TDockOrientation(Orient) of
    doVertical: Result := R.Left;
    doHorizontal: Result := R.Top;
  else
    Result := 0;
  end;
end;

function TDockZone.GetHeightWidth(Orient: Integer{TDockOrientation}): Integer;
var
  Zone: TDockZone;
  R: TRect;
begin
  if (Self = FTree.FTopZone) or ((FParentZone = FTree.FTopZone) and
    (FChildControl <> nil) and (FTree.FTopZone.ChildCount = 1)) then
  begin
    R := FTree.FDockSite.ClientRect;
    FTree.FDockSite.AdjustClientRect(R);
    if TDockOrientation(Orient) = doHorizontal then
      Result := R.Bottom - R.Top
    else
      Result := R.Right - R.Left;
  end
  else begin
    Zone := Self;
    while Zone <> FTree.FTopZone do
    begin
      if Zone.FParentZone.FOrientation = TDockOrientation(Orient) then
      begin
        Result := Zone.FZoneLimit - Zone.LimitBegin;
        Exit;
      end
      else
        Zone := Zone.FParentZone;
    end;
    if FTree.FTopZone.FOrientation = TDockOrientation(Orient) then
      Result := FTree.FTopXYLimit
    else
      Result := FTree.FTopZone.FZoneLimit;
  end;
end;

procedure TDockZone.ResetChildren;
var
  OldLimit: Integer;
  NewLimit: Integer;
  ChildNode: TDockZone;
begin
  case FOrientation of
    doHorizontal: NewLimit := Height;
    doVertical: NewLimit := Width;
  else
    Exit;
  end;
  ChildNode := FChildZones;
  OldLimit := NewLimit;
  NewLimit := NewLimit div ChildCount;
  ChildNode.FZoneLimit := ChildNode.LimitBegin + NewLimit;
  ChildNode.Update;
  ChildNode := ChildNode.FNextSibling;
  while ChildNode <> nil do
  begin
    ChildNode.FZoneLimit := ChildNode.FPrevSibling.FZoneLimit + NewLimit;
    if ChildNode.FNextSibling = nil then
      ChildNode.FZoneLimit := ChildNode.FZoneLimit + (OldLimit mod NewLimit);
    ChildNode.Update;
    ChildNode := ChildNode.FNextSibling;
  end;
end;

function TDockZone.GetControlName: string;
begin
  Result := '';
  if FChildControl <> nil then
  begin
    if FChildControl.Name = '' then
      raise Exception.CreateRes(@SDockedCtlNeedsName);
    Result := FChildControl.Name;
  end;
end;

function TDockZone.SetControlName(const Value: string): Boolean;
var
  Client: TControl;
begin
  Client := nil;
  with FTree do
  begin
    FDockSite.ReloadDockedControl(Value, Client);
    Result := Client <> nil;
    if Result then
    begin
      FReplacementZone := Self;
      try
        Client.ManualDock(FDockSite, nil, alNone);
      finally
        FReplacementZone := nil;
      end;
    end;
  end;
end;

procedure TDockZone.Update;

  function ParentNotLast: Boolean;
  var
    Parent: TDockZone;
  begin
    Result := False;
    Parent := FParentZone;
    while Parent <> nil do
    begin
      if Parent.FNextSibling <> nil then
      begin
        Result := True;
        Exit;
      end;
      Parent := Parent.FParentZone;
    end;
  end;

var
  NewWidth, NewHeight: Integer;
  R: TRect;
begin
  if (FChildControl <> nil) and (FTree.FUpdateCount = 0) then
  begin
    FChildControl.DockOrientation := FParentZone.FOrientation;
    NewWidth := Width;
    NewHeight := Height;
    if ParentNotLast then
    begin
      if FParentZone.FOrientation = doHorizontal then
        Dec(NewWidth, FTree.FBorderWidth)
      else
        Dec(NewHeight, FTree.FBorderWidth);
    end;
    if (FNextSibling <> nil) or ((FParentZone <> FTree.FTopZone) and
      ((FParentZone.FOrientation = FTree.FTopZone.FOrientation) and
      (FZoneLimit < FTree.FTopXYLimit)) or
      ((FParentZone.FOrientation <> FTree.FTopZone.FOrientation) and
      (FZoneLimit < FTree.FTopZone.FZoneLimit))) then
    begin
      if FParentZone.FOrientation = doHorizontal then
        Dec(NewHeight, FTree.FBorderWidth)
      else
        Dec(NewWidth, FTree.FBorderWidth);
    end;
    R := Bounds(Left, Top, NewWidth, NewHeight);
    FTree.AdjustDockRect(FChildControl, R);
    FChildControl.BoundsRect := R;
  end;
end;

{ TDockTree }

const
  GrabberSize = 12;

constructor TDockTree.Create(DockSite: TWinControl);
var
  I: Integer;
begin
  inherited Create;
  FBorderWidth := 4;
  FDockSite := DockSite;
  FVersion := $00040000;
  FGrabberSize := GrabberSize;
  FGrabbersOnTop := (DockSite.Align <> alTop) and (DockSite.Align <> alBottom);
  FTopZone := TDockZone.Create(Self);
  FBrush := TBrush.Create;
  FBrush.Bitmap := AllocPatternBitmap(clBlack, clWhite);
  // insert existing controls into tree
  BeginUpdate;
  try
    for I := 0 to DockSite.ControlCount - 1 do
      InsertControl(DockSite.Controls[I], alLeft, nil);
    FTopZone.ResetChildren;
  finally
    EndUpdate;
  end;
  if not (csDesigning in DockSite.ComponentState) then
  begin
    FOldWndProc := FDockSite.WindowProc;
    FDockSite.WindowProc := WindowProc;
  end;
end;

destructor TDockTree.Destroy;
begin
  if @FOldWndProc <> nil then
    FDockSite.WindowProc := FOldWndProc;
  PruneZone(FTopZone);
  FBrush.Free;
  inherited Destroy;
end;

procedure TDockTree.AdjustDockRect(Control: TControl; var ARect: TRect);
begin
  { Allocate room for the caption on the left if docksite is horizontally
    oriented, otherwise allocate room for the caption on the top. }
  if FDockSite.Align in [alTop, alBottom] then
    Inc(ARect.Left, GrabberSize) else
    Inc(ARect.Top, GrabberSize);
end;

procedure TDockTree.BeginUpdate;
begin
  Inc(FUpdateCount);
end;

procedure TDockTree.EndUpdate;
begin
  Dec(FUpdateCount);
  if FUpdateCount <= 0 then
  begin
    FUpdateCount := 0;
    UpdateAll;
  end;
end;

function TDockTree.FindControlZone(Control: TControl): TDockZone;
var
  CtlZone: TDockZone;

  procedure DoFindControlZone(StartZone: TDockZone);
  begin
    if StartZone.FChildControl = Control then
      CtlZone := StartZone
    else begin
      // Recurse sibling
      if (CtlZone = nil) and (StartZone.FNextSibling <> nil) then
        DoFindControlZone(StartZone.FNextSibling);
      // Recurse child
      if (CtlZone = nil) and (StartZone.FChildZones <> nil) then
        DoFindControlZone(StartZone.FChildZones);
    end;
  end;

begin
  CtlZone := nil;
  if (Control <> nil) and (FTopZone <> nil) then DoFindControlZone(FTopZone);
  Result := CtlZone;
end;

procedure TDockTree.ForEachAt(Zone: TDockZone; Proc: TForEachZoneProc);

  procedure DoForEach(Zone: TDockZone);
  begin
    Proc(Zone);
    // Recurse sibling
    if Zone.FNextSibling <> nil then DoForEach(Zone.FNextSibling);
    // Recurse child
    if Zone.FChildZones <> nil then DoForEach(Zone.FChildZones);
  end;

begin
  if Zone = nil then Zone := FTopZone;
  DoForEach(Zone);
end;

procedure TDockTree.GetControlBounds(Control: TControl; out CtlBounds: TRect);
var
  Z: TDockZone;
begin
  Z := FindControlZone(Control);
  if Z = nil then
    FillChar(CtlBounds, SizeOf(CtlBounds), 0)
  else
    with Z do
      CtlBounds := Bounds(Left, Top, Width, Height);
end;

function TDockTree.HitTest(const MousePos: TPoint; out HTFlag: Integer): TControl;
var
  Zone: TDockZone;
begin
  Zone := InternalHitTest(MousePos, HTFlag);
  if Zone <> nil then Result := Zone.FChildControl
  else Result := nil;
end;

procedure TDockTree.InsertControl(Control: TControl; InsertAt: TAlign;
  DropCtl: TControl);
const
  OrientArray: array[TAlign] of TDockOrientation = (doNoOrient, doHorizontal,
    doHorizontal, doVertical, doVertical, doNoOrient);
  MakeLast: array[TAlign] of Boolean = (False, False, True, False, True, False);
var
  Sibling, Me: TDockZone;
  InsertOrientation, CurrentOrientation: TDockOrientation;
  NewWidth, NewHeight: Integer;
  R: TRect;
begin
  if not Control.Visible then Exit;
  if FReplacementZone <> nil then
  begin
    FReplacementZone.FChildControl := Control;
    FReplacementZone.Update;
  end
  else if FTopZone.FChildZones = nil then
  begin
    // Tree is empty, so add first child
    R := FDockSite.ClientRect;
    FDockSite.AdjustClientRect(R);
    NewWidth := R.Right - R.Left;
    NewHeight := R.Bottom - R.Top;
    if FDockSite.AutoSize then
    begin
      if NewWidth = 0 then NewWidth := Control.UndockWidth;
      if NewHeight = 0 then NewHeight := Control.UndockHeight;
    end;
    R := Bounds(R.Left, R.Top, NewWidth, NewHeight);
    AdjustDockRect(Control, R);
    Control.BoundsRect := R;
    Me := TDockZone.Create(Self);
    FTopZone.FChildZones := Me;
    Me.FParentZone := FTopZone;
    Me.FChildControl := Control;
  end
  else begin
    // Default to right-side docking
    if InsertAt in [alClient, alNone] then InsertAt := alRight;
    Me := FindControlZone(Control);
    if Me <> nil then RemoveZone(Me);
    Sibling := FindControlZone(DropCtl);
    InsertOrientation := OrientArray[InsertAt];
    if FTopZone.ChildCount = 1 then
    begin
      // Tree only has one child, and a second is being added, so orientation and
      // limits must be set up
      FTopZone.FOrientation := InsertOrientation;
      case InsertOrientation of
        doHorizontal:
          begin
            FTopZone.FZoneLimit := FTopZone.FChildZones.Width;
            FTopXYLimit := FTopZone.FChildZones.Height;
          end;
        doVertical:
          begin
            FTopZone.FZoneLimit := FTopZone.FChildZones.Height;
            FTopXYLimit := FTopZone.FChildZones.Width;
          end;
      end;
    end;
    Me := TDockZone.Create(Self);
    Me.FChildControl := Control;
    if Sibling <> nil then CurrentOrientation := Sibling.FParentZone.FOrientation
    else CurrentOrientation := FTopZone.FOrientation;
    if InsertOrientation = doNoOrient then
      InsertOrientation := CurrentOrientation;
    // Control is being dropped into a zone with the same orientation we
    // are requesting, so we just need to add ourselves to the sibling last
    if InsertOrientation = CurrentOrientation then InsertSibling(Me, Sibling,
      MakeLast[InsertAt])
    // Control is being dropped into a zone with a different orientation than
    // we are requesting
    else InsertNewParent(Me, Sibling, InsertOrientation, MakeLast[InsertAt]);
  end;
  { Redraw client dock frames }
  FDockSite.Invalidate;
end;

procedure TDockTree.InsertNewParent(NewZone, SiblingZone: TDockZone;
  ParentOrientation: TDockOrientation; InsertLast: Boolean);
var
  NewParent: TDockZone;
begin
  NewParent := TDockZone.Create(Self);
  NewParent.FOrientation := ParentOrientation;
  if SiblingZone = nil then
  begin
    // if SiblingZone is nil, then we need to insert zone as a child of the top
    NewParent.FZoneLimit := FTopXYLimit;
    FTopXYLimit := FTopZone.FZoneLimit;
    FShiftScaleOrient := ParentOrientation;
    FScaleBy := 0.5;
    if InsertLast then
    begin
      NewParent.FChildZones := FTopZone;
      FTopZone.FParentZone := NewParent;
      FTopZone.FNextSibling := NewZone;
      NewZone.FPrevSibling := FTopZone;
      NewZone.FParentZone := NewParent;
      FTopZone := NewParent;
      ForEachAt(NewParent.FChildZones, ScaleZone);
    end
    else begin
      NewParent.FChildZones := NewZone;
      FTopZone.FParentZone := NewParent;
      FTopZone.FPrevSibling := NewZone;
      NewZone.FNextSibling := FTopZone;
      NewZone.FParentZone := NewParent;
      FTopZone := NewParent;
      ForEachAt(NewParent.FChildZones, ScaleZone);
      FShiftBy := FTopZone.FZoneLimit div 2;
      ForEachAt(NewParent.FChildZones, ShiftZone);
      NewZone.FZoneLimit := FTopZone.FZoneLimit div 2;
    end;
    ForEachAt(nil, UpdateZone);
  end
  else begin
    // if SiblingZone is not nil, we need to insert a new parent zone for me
    // and my SiblingZone
    NewParent.FZoneLimit := SiblingZone.FZoneLimit;
    NewParent.FParentZone := SiblingZone.FParentZone;
    NewParent.FPrevSibling := SiblingZone.FPrevSibling;
    if NewParent.FPrevSibling <> nil then
      NewParent.FPrevSibling.FNextSibling := NewParent;
    NewParent.FNextSibling := SiblingZone.FNextSibling;
    if NewParent.FNextSibling <> nil then
      NewParent.FNextSibling.FPrevSibling := NewParent;
    if NewParent.FParentZone.FChildZones = SiblingZone then
      NewParent.FParentZone.FChildZones := NewParent;
    NewZone.FParentZone := NewParent;
    SiblingZone.FParentZone := NewParent;
    if InsertLast then
    begin
      // insert after SiblingZone
      NewParent.FChildZones := SiblingZone;
      SiblingZone.FPrevSibling := nil;
      SiblingZone.FNextSibling := NewZone;
      NewZone.FPrevSibling := SiblingZone;
    end
    else begin
      // insert before SiblingZone
      NewParent.FChildZones := NewZone;
      SiblingZone.FPrevSibling := NewZone;
      SiblingZone.FNextSibling := nil;
      NewZone.FNextSibling := SiblingZone;
    end;
    // Set bounds of new children
  end;
  NewParent.ResetChildren;
  ForEachAt(nil, UpdateZone);
end;

procedure TDockTree.InsertSibling(NewZone, SiblingZone: TDockZone;
  InsertLast: Boolean);
begin
  if SiblingZone = nil then
  begin
    // If sibling is nil then make me the a child of the top
    SiblingZone := FTopZone.FChildZones;
    if InsertLast then
      while SiblingZone.FNextSibling <> nil do
        SiblingZone := SiblingZone.FNextSibling;
  end;
  if InsertLast then
  begin
    // Insert me after sibling
    NewZone.FParentZone := SiblingZone.FParentZone;
    NewZone.FPrevSibling := SiblingZone;
    NewZone.FNextSibling := SiblingZone.FNextSibling;
    if NewZone.FNextSibling <> nil then
      NewZone.FNextSibling.FPrevSibling := NewZone;
    SiblingZone.FNextSibling := NewZone;
  end
  else begin
    // insert before sibling
    NewZone.FNextSibling := SiblingZone;
    NewZone.FPrevSibling := SiblingZone.FPrevSibling;
    if NewZone.FPrevSibling <> nil then
      NewZone.FPrevSibling.FNextSibling := NewZone;
    SiblingZone.FPrevSibling := NewZone;
    NewZone.FParentZone := SiblingZone.FParentZone;
    if NewZone.FParentZone.FChildZones = SiblingZone then
      NewZone.FParentZone.FChildZones := NewZone;
  end;
  // Set up zone limits for all siblings
  SiblingZone.FParentZone.ResetChildren;
end;

function TDockTree.InternalHitTest(const MousePos: TPoint; out HTFlag: Integer): TDockZone;
var
  ResultZone: TDockZone;

  procedure DoFindZone(Zone: TDockZone);
  var
    ZoneTop, ZoneLeft: Integer;
  begin
    // Check for hit on bottom splitter...
    if (Zone.FParentZone.FOrientation = doHorizontal) and
      ((MousePos.Y <= Zone.FZoneLimit) and
      (MousePos.Y >= Zone.FZoneLimit - FBorderWidth)) then
    begin
      HTFlag := HTBORDER;
      ResultZone := Zone;
    end
    // Check for hit on left splitter...
    else if (Zone.FParentZone.FOrientation = doVertical) and
      ((MousePos.X <= Zone.FZoneLimit) and
      (MousePos.X >= Zone.FZoneLimit - FBorderWidth)) then
    begin
      HTFlag := HTBORDER;
      ResultZone := Zone;
    end
    // Check for hit on grabber...
    else if Zone.FChildControl <> nil then
    begin
      ZoneTop := Zone.Top;
      ZoneLeft := Zone.Left;
      if FGrabbersOnTop then
      begin
        if (MousePos.Y >= ZoneTop) and (MousePos.Y <= ZoneTop + FGrabberSize) and
          (MousePos.X >= ZoneLeft) and (MousePos.X <= ZoneLeft + Zone.Width) then
        begin
          ResultZone := Zone;
          with Zone.FChildControl do
            if MousePos.X > Left + Width - 15 then HTFlag := HTCLOSE
            else HTFlag := HTCAPTION;
        end;
      end
      else begin
        if (MousePos.X >= ZoneLeft) and (MousePos.X <= ZoneLeft + FGrabberSize) and
          (MousePos.Y >= ZoneTop) and (MousePos.Y <= ZoneTop + Zone.Height) then
        begin
          ResultZone := Zone;
          if MousePos.Y < Zone.FChildControl.Top + 15 then HTFlag := HTCLOSE
          else HTFlag := HTCAPTION;
        end;
      end;
    end;
    // Recurse to next zone...
    if (ResultZone = nil) and (Zone.FNextSibling <> nil) then
      DoFindZone(Zone.FNextSibling);
    if (ResultZone = nil) and (Zone.FChildZones <> nil) then
      DoFindZone(Zone.FChildZones);
  end;

  function FindControlAtPos(const Pos: TPoint): TControl;
  var
    I: Integer;
    P: TPoint;
  begin
    for I := FDockSite.ControlCount - 1 downto 0 do
    begin
      Result := FDockSite.Controls[I];
      with Result do
      begin
        { Control must be Visible and Showing }
        if not Result.Visible or ((Result is TWinControl) and
           not TWinControl(Result).Showing) then continue;
        P := Point(Pos.X - Left, Pos.Y - Top);
        if PtInRect(ClientRect, P) then Exit;
      end;
    end;
    Result := nil;
  end;

var
  CtlAtPos: TControl;
begin
  ResultZone := nil;
  HTFlag := HTNOWHERE;
  CtlAtPos := FindControlAtPos(MousePos);
  if (CtlAtPos <> nil) and (CtlAtPos.HostDockSite = FDockSite) then
  begin
    ResultZone := FindControlZone(CtlAtPos);
    if ResultZone <> nil then HTFlag := HTCLIENT;
  end
  else if (FTopZone.FChildZones <> nil) and (FTopZone.ChildCount >= 1) and
    (CtlAtPos = nil) then
    DoFindZone(FTopZone.FChildZones);
  Result := ResultZone;
end;

var
  TreeStreamEndFlag: Integer = -1;

procedure TDockTree.LoadFromStream(Stream: TStream);

  procedure ReadControlName(var ControlName: string);
  var
    Size: Integer;
  begin
    ControlName := '';
    Stream.Read(Size, SizeOf(Size));
    if Size > 0 then
    begin
      SetLength(ControlName, Size);
      Stream.Read(Pointer(ControlName)^, Size);
    end;
  end;

var
  CompName: string;
  Client: TControl;
  Level, LastLevel, I, InVisCount: Integer;
  Zone, LastZone, NextZone: TDockZone;
begin
  PruneZone(FTopZone);
  BeginUpdate;
  try
    // read stream version
    Stream.Read(I, SizeOf(I));
    // read invisible dock clients
    Stream.Read(InVisCount, SizeOf(InVisCount));
    for I := 0 to InVisCount - 1 do
    begin
      ReadControlName(CompName);
      if CompName <> '' then
      begin
        FDockSite.ReloadDockedControl(CompName, Client);
        if Client <> nil then
        begin
          Client.Visible := False;
          Client.ManualDock(FDockSite);
        end;
      end;
    end;
    // read top zone data
    Stream.Read(FTopXYLimit, SizeOf(FTopXYLimit));
    LastLevel := 0;
    LastZone := nil;
    // read dock zone tree
    while True do
    begin
      with Stream do
      begin
        Read(Level, SizeOf(Level));
        if Level = TreeStreamEndFlag then Break;
        Zone := TDockZone.Create(Self);
        Read(Zone.FOrientation, SizeOf(Zone.FOrientation));
        Read(Zone.FZoneLimit, SizeOf(Zone.FZoneLimit));
        ReadControlName(CompName);
        if CompName <> '' then
          if not Zone.SetControlName(CompName) then
          begin
            {Remove dock zone if control cannot be found}
            Zone.Free;
            Continue;
          end;
      end;
      if Level = 0 then FTopZone := Zone
      else if Level = LastLevel then
      begin
        LastZone.FNextSibling := Zone;
        Zone.FPrevSibling := LastZone;
        Zone.FParentZone := LastZone.FParentZone;
      end
      else if Level > LastLevel then
      begin
        LastZone.FChildZones := Zone;
        Zone.FParentZone := LastZone;
      end
      else if Level < LastLevel then
      begin
        NextZone := LastZone;
        for I := 1 to LastLevel - Level do NextZone := NextZone.FParentZone;
        NextZone.FNextSibling := Zone;
        Zone.FPrevSibling := NextZone;
        Zone.FParentZone := NextZone.FParentZone;
      end;
      LastLevel := Level;
      LastZone := Zone;
    end;
  finally
    EndUpdate;
  end;
//  ResetBounds(True);
end;

procedure TDockTree.PaintDockFrame(Canvas: TCanvas; Control: TControl;
  const ARect: TRect);

  procedure DrawCloseButton(Left, Top: Integer);
  begin
    DrawFrameControl(Canvas.Handle, Rect(Left, Top, Left+FGrabberSize-2,
      Top+FGrabberSize-2), DFC_CAPTION, DFCS_CAPTIONCLOSE);
  end;

  procedure DrawGrabberLine(Left, Top, Right, Bottom: Integer);
  begin
    with Canvas do
    begin
      Pen.Color := clBtnHighlight;
      MoveTo(Right, Top);
      LineTo(Left, Top);
      LineTo(Left, Bottom);
      Pen.Color := clBtnShadow;
      LineTo(Right, Bottom);
      LineTo(Right, Top-1);
    end;
  end;

begin
  with ARect do
    if FDockSite.Align in [alTop, alBottom] then
    begin
      DrawCloseButton(Left+1, Top+1);
      DrawGrabberLine(Left+3, Top+FGrabberSize+1, Left+5, Bottom-2);
      DrawGrabberLine(Left+6, Top+FGrabberSize+1, Left+8, Bottom-2);
    end
    else
    begin
      DrawCloseButton(Right-FGrabberSize+1, Top+1);
      DrawGrabberLine(Left+2, Top+3, Right-FGrabberSize-2, Top+5);
      DrawGrabberLine(Left+2, Top+6, Right-FGrabberSize-2, Top+8);
    end;
end;

procedure TDockTree.PaintSite(DC: HDC);
var
  Canvas: TControlCanvas;
  Control: TControl;
  I: Integer;
  R: TRect;
begin
  Canvas := TControlCanvas.Create;
  try
    Canvas.Control := FDockSite;
    Canvas.Lock;
    try
      Canvas.Handle := DC;
      try
        for I := 0 to FDockSite.ControlCount - 1 do
        begin
          Control := FDockSite.Controls[I];
          if Control.Visible and (Control.HostDockSite = FDockSite) then
          begin
            R := Control.BoundsRect;
            AdjustDockRect(Control, R);
            Dec(R.Left, 2 * (R.Left - Control.Left));
            Dec(R.Top, 2 * (R.Top - Control.Top));
            Dec(R.Right, 2 * (Control.Width - (R.Right - R.Left)));
            Dec(R.Bottom, 2 * (Control.Height - (R.Bottom - R.Top)));
            PaintDockFrame(Canvas, Control, R);
          end;
        end;
      finally
        Canvas.Handle := 0;
      end;
    finally
      Canvas.Unlock;
    end;
  finally
    Canvas.Free;
  end;
end;

procedure TDockTree.PositionDockRect(Client, DropCtl: TControl;
  DropAlign: TAlign; var DockRect: TRect);
var
  VisibleClients,
  NewX, NewY, NewWidth, NewHeight: Integer;
begin
  VisibleClients := FDockSite.VisibleDockClientCount;
  { When docksite has no controls in it, or 1 or less clients then the
    dockrect should only be based on the client area of the docksite }
  if (DropCtl = nil) or (DropCtl.DockOrientation = doNoOrient) or
     {(DropCtl = Client) or }(VisibleClients < 2) then
  begin
    DockRect := Rect(0, 0, FDockSite.ClientWidth, FDockSite.ClientHeight);
    { When there is exactly 1 client we divide the docksite client area in half}
    if VisibleClients > 0 then
    with DockRect do
      case DropAlign of
        alLeft: Right := Right div 2;
        alRight: Left := Right div 2;
        alTop: Bottom := Bottom div 2;
        alBottom: Top := Bottom div 2;
      end;
  end
  else begin
  { Otherwise, if the docksite contains more than 1 client, set the coordinates
    for the dockrect based on the control under the mouse }
    NewX := DropCtl.Left;
    NewY := DropCtl.Top;
    NewWidth := DropCtl.Width;
    NewHeight := DropCtl.Height;
    if DropAlign in [alLeft, alRight] then
      NewWidth := DropCtl.Width div 2
    else if DropAlign in [alTop, alBottom] then
      NewHeight := DropCtl.Height div 2;
    case DropAlign of
      alRight: Inc(NewX, NewWidth);
      alBottom: Inc(NewY, NewHeight);
    end;
    DockRect := Bounds(NewX, NewY, NewWidth, NewHeight);
  end;
  MapWindowPoints(FDockSite.Handle, 0, DockRect, 2);
end;

procedure TDockTree.PruneZone(Zone: TDockZone);

  procedure DoPrune(Zone: TDockZone);
  begin
    // Recurse sibling
    if Zone.FNextSibling <> nil then
      DoPrune(Zone.FNextSibling);
    // Recurse child
    if Zone.FChildZones <> nil then
      DoPrune(Zone.FChildZones);
    // Free zone
    Zone.Free;
  end;

begin
  if Zone = nil then Exit;
  // Delete children recursively
  if Zone.FChildZones <> nil then DoPrune(Zone.FChildZones);
  // Fixup all pointers to this zone
  if Zone.FPrevSibling <> nil then
    Zone.FPrevSibling.FNextSibling := Zone.FNextSibling
  else if Zone.FParentZone <> nil then
    Zone.FParentZone.FChildZones := Zone.FNextSibling;
  if Zone.FNextSibling <> nil then
    Zone.FNextSibling.FPrevSibling := Zone.FPrevSibling;
  // Free this zone
  if Zone = FTopZone then FTopZone := nil;
  Zone.Free;
end;

procedure TDockTree.RemoveControl(Control: TControl);
var
  Z: TDockZone;
begin
  Z := FindControlZone(Control);
  if (Z <> nil) then
  begin
    if Z = FReplacementZone then
      Z.FChildControl := nil
    else
     RemoveZone(Z);
    Control.DockOrientation := doNoOrient;
    { Redraw client dock frames }
    FDockSite.Invalidate;
  end;
end;

procedure TDockTree.RemoveZone(Zone: TDockZone);
var
  Sibling, LastChild: TDockZone;
  ZoneChildCount: Integer;
begin
  if Zone = nil then
    raise Exception.Create(SDockTreeRemoveError + SDockZoneNotFound);
  if Zone.FChildControl = nil then
    raise Exception.Create(SDockTreeRemoveError + SDockZoneHasNoCtl);
  ZoneChildCount := Zone.FParentZone.ChildCount;
  if ZoneChildCount = 1 then
  begin
    FTopZone.FChildZones := nil;
    FTopZone.FOrientation := doNoOrient;
  end
  else if ZoneChildCount = 2 then
  begin
    // This zone has only one sibling zone
    if Zone.FPrevSibling = nil then Sibling := Zone.FNextSibling
    else Sibling := Zone.FPrevSibling;
    if Sibling.FChildControl <> nil then
    begin
      // Sibling is a zone with one control and no child zones
      if Zone.FParentZone = FTopZone then
      begin
        // If parent is top zone, then just remove the zone
        FTopZone.FChildZones := Sibling;
        Sibling.FPrevSibling := nil;
        Sibling.FNextSibling := nil;
        Sibling.FZoneLimit := FTopZone.LimitSize;
        Sibling.Update;
      end
      else begin
        // Otherwise, move sibling's control up into parent zone and dispose of sibling
        Zone.FParentZone.FOrientation := doNoOrient;
        Zone.FParentZone.FChildControl := Sibling.FChildControl;
        Zone.FParentZone.FChildZones := nil;
        Sibling.Free;
      end;
      ForEachAt(Zone.FParentZone, UpdateZone);
    end
    else begin
      // Sibling is a zone with child zones, so sibling must be made topmost
      // or collapsed into higher zone.
      if Zone.FParentZone = FTopZone then
      begin
        // Zone is a child of topmost zone, so sibling becomes topmost
        Sibling.FZoneLimit := FTopXYLimit;
        FTopXYLimit := FTopZone.FZoneLimit;
        FTopZone.Free;
        FTopZone := Sibling;
        Sibling.FNextSibling := nil;
        Sibling.FPrevSibling := nil;
        Sibling.FParentZone := nil;
        UpdateAll;
      end
      else begin
        // Zone's parent is not the topmost zone, so child zones must be
        // collapsed into parent zone
        Sibling.FChildZones.FPrevSibling := Zone.FParentZone.FPrevSibling;
        if Sibling.FChildZones.FPrevSibling = nil then
          Zone.FParentZone.FParentZone.FChildZones := Sibling.FChildZones
        else
          Sibling.FChildZones.FPrevSibling.FNextSibling := Sibling.FChildZones;
        LastChild := Sibling.FChildZones;
        LastChild.FParentZone := Zone.FParentZone.FParentZone;
        repeat
          LastChild := LastChild.FNextSibling;
          LastChild.FParentZone := Zone.FParentZone.FParentZone;
        until LastChild.FNextSibling = nil;
        LastChild.FNextSibling := Zone.FParentZone.FNextSibling;
        if LastChild.FNextSibling <> nil then
          LastChild.FNextSibling.FPrevSibling := LastChild;
        ForEachAt(LastChild.FParentZone, UpdateZone);
        Zone.FParentZone.Free;
        Sibling.Free;
      end;
    end;
  end
  else begin
    // This zone has multiple sibling zones
    if Zone.FPrevSibling = nil then
    begin
      // First zone in parent's child list, so make next one first and remove
      // from list
      Zone.FParentZone.FChildZones := Zone.FNextSibling;
      Zone.FNextSibling.FPrevSibling := nil;
      Zone.FNextSibling.Update;
    end
    else begin
      // Not first zone in parent's child list, so remove zone from list and fix
      // up adjacent siblings
      Zone.FPrevSibling.FNextSibling := Zone.FNextSibling;
      if Zone.FNextSibling <> nil then
        Zone.FNextSibling.FPrevSibling := Zone.FPrevSibling;
      Zone.FPrevSibling.FZoneLimit := Zone.FZoneLimit;
      Zone.FPrevSibling.Update;
    end;
    ForEachAt(Zone.FParentZone, UpdateZone);
  end;
  Zone.Free;
end;

procedure TDockTree.ResetBounds(Force: Boolean);
var
  R: TRect;
begin
  if not (csLoading in FDockSite.ComponentState) and
    (FTopZone <> nil) and (FDockSite.DockClientCount > 0) then
  begin
    R := FDockSite.ClientRect;
    FDockSite.AdjustClientRect(R);
    if Force or (not CompareMem(@R, @FOldRect, SizeOf(TRect))) then
    begin
      FOldRect := R;
      case FTopZone.FOrientation of
        doHorizontal:
          begin
            FTopZone.FZoneLimit := R.Right - R.Left;
            FTopXYLimit := R.Bottom - R.Top;
          end;
        doVertical:
          begin
            FTopZone.FZoneLimit := R.Bottom - R.Top;
            FTopXYLimit := R.Right - R.Left;
          end;
      end;
      if FDockSite.DockClientCount > 0 then
      begin
        SetNewBounds(nil);
        if FUpdateCount = 0 then ForEachAt(nil, UpdateZone);
      end;
    end;
  end;
end;

procedure TDockTree.ScaleZone(Zone: TDockZone);
begin
  if Zone = nil then Exit;
  if (Zone <> nil) and (Zone.FParentZone.FOrientation = FShiftScaleOrient) then
    with Zone do
      FZoneLimit := Integer(Round(FZoneLimit * FScaleBy));
end;

procedure TDockTree.SaveToStream(Stream: TStream);

  procedure WriteControlName(ControlName: string);
  var
    NameLen: Integer;
  begin
    NameLen := Length(ControlName);
    Stream.Write(NameLen, SizeOf(NameLen));
    if NameLen > 0 then Stream.Write(Pointer(ControlName)^, NameLen);
  end;

  procedure DoSaveZone(Zone: TDockZone; Level: Integer);
  begin
    with Stream do
    begin
      Write(Level, SizeOf(Level));
      Write(Zone.FOrientation, SizeOf(Zone.FOrientation));
      Write(Zone.FZoneLimit, SizeOf(Zone.FZoneLimit));
      WriteControlName(Zone.GetControlName);
    end;
    // Recurse child
    if Zone.FChildZones <> nil then
      DoSaveZone(Zone.FChildZones, Level + 1);
    // Recurse sibling
    if Zone.FNextSibling <> nil then
      DoSaveZone(Zone.FNextSibling, Level);
  end;

var
  I, NVCount: Integer;
  Ctl: TControl;
  NonVisList: TStringList;
begin
  // write stream version
  Stream.Write(FVersion, SizeOf(FVersion));
  // get list of non-visible dock clients
  NonVisList := TStringList.Create;
  try
    for I := 0 to FDockSite.DockClientCount - 1 do
    begin
      Ctl := FDockSite.DockClients[I];
      if (not Ctl.Visible) and (Ctl.Name <> '') then
        NonVisList.Add(Ctl.Name);
    end;
    // write non-visible dock client list
    NVCount := NonVisList.Count;
    Stream.Write(NVCount, SizeOf(NVCount));
    for I := 0 to NVCount - 1 do WriteControlName(NonVisList[I]);
  finally
    NonVisList.Free;
  end;
  // write top zone data
  Stream.Write(FTopXYLimit, SizeOf(FTopXYLimit));
  // write all zones from tree
  DoSaveZone(FTopZone, 0);
  Stream.Write(TreeStreamEndFlag, SizeOf(TreeStreamEndFlag));
end;

procedure TDockTree.SetNewBounds(Zone: TDockZone);

  procedure DoSetNewBounds(Zone: TDockZone);
  begin
    if Zone <> nil then
    begin
      if (Zone.FNextSibling = nil) and (Zone <> FTopZone) then
      begin
        if Zone.FParentZone = FTopZone then Zone.FZoneLimit := FTopXYLimit
        else Zone.FZoneLimit := Zone.FParentZone.FParentZone.FZoneLimit;
      end;
      if Zone.FChildZones <> nil then DoSetNewBounds(Zone.FChildZones);
      if Zone.FNextSibling <> nil then DoSetNewBounds(Zone.FNextSibling);
    end;
  end;

begin
  if Zone = nil then Zone := FTopZone.FChildZones;
  DoSetNewBounds(Zone);
  { Redraw client dock frames }
  FDockSite.Invalidate;
end;

procedure TDockTree.SetReplacingControl(Control: TControl);
begin
  FReplacementZone := FindControlZone(Control);
end;

procedure TDockTree.ShiftZone(Zone: TDockZone);
begin
  if (Zone <> nil) and (Zone <> FTopZone) and
    (Zone.FParentZone.FOrientation = FShiftScaleOrient) then
    Inc(Zone.FZoneLimit, FShiftBy);
end;

procedure TDockTree.SplitterMouseDown(OnZone: TDockZone; MousePos: TPoint);
begin
  FSizingZone := OnZone;
  Mouse.Capture := FDockSite.Handle;
  FSizingWnd := FDockSite.Handle;
  FSizingDC := GetDCEx(FSizingWnd, 0, DCX_CACHE or DCX_CLIPSIBLINGS or
    DCX_LOCKWINDOWUPDATE);
  FSizePos := MousePos;
  DrawSizeSplitter;
end;

procedure TDockTree.SplitterMouseUp;
begin
  Mouse.Capture := 0;
  DrawSizeSplitter;
  ReleaseDC(FSizingWnd, FSizingDC);
  if FSizingZone.FParentZone.FOrientation = doHorizontal then
    FSizingZone.FZoneLimit := FSizePos.y + (FBorderWidth div 2) else
    FSizingZone.FZoneLimit := FSizePos.x + (FBorderWidth div 2);
  SetNewBounds(FSizingZone.FParentZone);
  ForEachAt(FSizingZone.FParentZone, UpdateZone);
  FSizingZone := nil;
end;

procedure TDockTree.UpdateAll;
begin
  if (FUpdateCount = 0) and (FDockSite.DockClientCount > 0) then
    ForEachAt(nil, UpdateZone);
end;

procedure TDockTree.UpdateZone(Zone: TDockZone);
begin
  if FUpdateCount = 0 then Zone.Update;
end;

procedure TDockTree.DrawSizeSplitter;
var
  R: TRect;
  PrevBrush: HBrush;
begin
  if FSizingZone <> nil then
  begin
    with R do
    begin
      if FSizingZone.FParentZone.FOrientation = doHorizontal then
      begin
        Left := FSizingZone.Left;
        Top := FSizePos.Y - (FBorderWidth div 2);
        Right := Left + FSizingZone.Width;
        Bottom := Top + FBorderWidth;
      end
      else begin
        Left := FSizePos.X - (FBorderWidth div 2);
        Top := FSizingZone.Top;
        Right := Left + FBorderWidth;
        Bottom := Top + FSizingZone.Height;
      end;
    end;
    PrevBrush := SelectObject(FSizingDC, FBrush.Handle);
    with R do
      PatBlt(FSizingDC, Left, Top, Right - Left, Bottom - Top, PATINVERT);
    SelectObject(FSizingDC, PrevBrush);
  end;
end;

function TDockTree.GetNextLimit(AZone: TDockZone): Integer;
var
  LimitResult: Integer;

  function Min(I1, I2: Integer): Integer;
  begin
    if I1 > I2 then Result := I2
    else Result := I1;
  end;

  procedure DoGetNextLimit(Zone: TDockZone);
  begin
    if (Zone <> AZone) and
      (Zone.FParentZone.FOrientation = AZone.FParentZone.FOrientation) and
      (Zone.FZoneLimit > AZone.FZoneLimit) and ((Zone.FChildControl = nil) or
      ((Zone.FChildControl <> nil) and (Zone.FChildControl.Visible))) then
      LimitResult := Min(LimitResult, Zone.FZoneLimit);
    if Zone.FNextSibling <> nil then DoGetNextLimit(Zone.FNextSibling);
    if Zone.FChildZones <> nil then DoGetNextLimit(Zone.FChildZones);
  end;

begin
  if AZone.FNextSibling <> nil then
    LimitResult := AZone.FNextSibling.FZoneLimit
  else
    LimitResult := AZone.FZoneLimit + AZone.LimitSize;
  DoGetNextLimit(FTopZone.FChildZones);
  Result := LimitResult;
end;

procedure TDockTree.ControlVisibilityChanged(Control: TControl;
  Visible: Boolean);

  function GetDockAlign(Client, DropCtl: TControl): TAlign;
  var
    CRect, DRect: TRect;
  begin
    Result := alRight;
    if DropCtl <> nil then
    begin
      CRect := Client.BoundsRect;
      DRect := DropCtl.BoundsRect;
      if (CRect.Top <= DRect.Top) and (CRect.Bottom < DRect.Bottom) and
         (CRect.Right >= DRect.Right) then
        Result := alTop
      else if (CRect.Left <= DRect.Left) and (CRect.Right < DRect.Right) and
         (CRect.Bottom >= DRect.Bottom) then
        Result := alLeft
      else if CRect.Top >= ((DRect.Top + DRect.Bottom) div 2) then
        Result := alBottom;
    end;
  end;

var
  HitTest: Integer;
  DropCtlZone: TDockZone;
  DropCtl: TControl;
begin
  if Visible then
  begin
    if FindControlZone(Control) = nil then
    begin
      DropCtlZone := InternalHitTest(Point(Control.Left, Control.Top), HitTest);
      if DropCtlZone <> nil then DropCtl := DropCtlZone.FChildControl
      else DropCtl := nil;
      InsertControl(Control, GetDockAlign(Control, DropCtl), DropCtl);
    end;
  end
  else
    RemoveControl(Control)
end;

procedure TDockTree.WindowProc(var Message: TMessage);

  procedure CalcSplitterPos;
  var
    MinWidth,
    TestLimit: Integer;
  begin
    MinWidth := FGrabberSize;
    if (FSizingZone.FParentZone.FOrientation = doHorizontal) then
    begin
      TestLimit := FSizingZone.Top + MinWidth;
      if FSizePos.y <= TestLimit then FSizePos.y := TestLimit;
      TestLimit := GetNextLimit(FSizingZone) - MinWidth;
      if FSizePos.y >= TestLimit then FSizePos.y := TestLimit;
    end
    else begin
      TestLimit := FSizingZone.Left + MinWidth;
      if FSizePos.x <= TestLimit then FSizePos.x := TestLimit;
      TestLimit := GetNextLimit(FSizingZone) - MinWidth;
      if FSizePos.x >= TestLimit then FSizePos.x := TestLimit;
    end;
  end;

const
  SizeCursors: array[TDockOrientation] of TCursor = (crDefault, crVSplit, crHSplit);
var
  TempZone: TDockZone;
  Control: TControl;
  P: TPoint;
  R: TRect;
  HitTestValue: Integer;
  Msg: TMsg;
begin
  case Message.Msg of
    CM_DOCKNOTIFICATION:
      with TCMDockNotification(Message) do
        if (NotifyRec.ClientMsg = CM_VISIBLECHANGED) then
          ControlVisibilityChanged(Client, Boolean(NotifyRec.MsgWParam));
    WM_MOUSEMOVE:
      if FSizingZone <> nil then
      begin
        DrawSizeSplitter;
        FSizePos := SmallPointToPoint(TWMMouse(Message).Pos);
        CalcSplitterPos;
        DrawSizeSplitter;
      end;
    WM_LBUTTONDBLCLK:
      begin
        TempZone := InternalHitTest(SmallPointToPoint(TWMMouse(Message).Pos),
          HitTestValue);
        if TempZone <> nil then
          with TempZone do
            if (FChildControl <> nil) and (HitTestValue = HTCAPTION) then
            begin
              CancelDrag;
              FChildControl.ManualDock(nil, nil, alTop);
            end;
      end;
    WM_LBUTTONDOWN:
      begin
        P := SmallPointToPoint(TWMMouse(Message).Pos);
        TempZone := InternalHitTest(P, HitTestValue);
        if (TempZone <> nil) then
        begin
          if HitTestValue = HTBORDER then
            SplitterMouseDown(TempZone, P)
          else if HitTestValue = HTCAPTION then
          begin
            if (not PeekMessage(Msg, FDockSite.Handle, WM_LBUTTONDBLCLK,
              WM_LBUTTONDBLCLK, PM_NOREMOVE)) and
              (TempZone.FChildControl is TWinControl) then
              TWinControl(TempZone.FChildControl).SetFocus;
	    if (TempZone.FChildControl.DragKind = dkDock) and
              (TempZone.FChildControl.DragMode = dmAutomatic)then
                TempZone.FChildControl.BeginDrag(False);
	    Exit;
          end;
        end;
      end;
    WM_LBUTTONUP:
      if FSizingZone = nil then
      begin
        P := SmallPointToPoint(TWMMouse(Message).Pos);
        TempZone := InternalHitTest(P, HitTestValue);
        if (TempZone <> nil) and (HitTestValue = HTCLOSE) then
        begin
          if TempZone.FChildControl is TCustomForm then
            TCustomForm(TempZone.FChildControl).Close
          else
            TempZone.FChildControl.Visible := False;
        end;
      end
      else
        SplitterMouseUp;
    WM_SETCURSOR:
      begin
        GetCursorPos(P);
        P := FDockSite.ScreenToClient(P);
        with TWMSetCursor(Message) do
          if (Smallint(HitTest) = HTCLIENT) and (CursorWnd = FDockSite.Handle)
            and (FDockSite.VisibleDockClientCount > 0) then
          begin
            TempZone := InternalHitTest(P, HitTestValue);
            if (TempZone <> nil) and (HitTestValue = HTBORDER) then
            begin
              Windows.SetCursor(Screen.Cursors[SizeCursors[TempZone.FParentZone.FOrientation]]);
              Result := 1;
              Exit;
            end;
          end;
      end;
    CM_HINTSHOW:
      with TCMHintShow(Message) do
      begin
        FOldWndProc(Message);
        if Result = 0 then
        begin
          Control := HitTest(HintInfo^.CursorPos, HitTestValue);
          if HitTestValue = HTBORDER then
            HintInfo^.HintStr := ''
          else if (Control <> nil) and (HitTestValue in [HTCAPTION, HTCLOSE]) then
          begin
            R := Control.BoundsRect;
            AdjustDockRect(Control, R);
            Dec(R.Left, 2 * (R.Left - Control.Left));
            Dec(R.Top, 2 * (R.Top - Control.Top));
            Dec(R.Right, 2 * (Control.Width - (R.Right - R.Left)));
            Dec(R.Bottom, 2 * (Control.Height - (R.Bottom - R.Top)));
            HintInfo^.HintStr := Control.Caption;
            HintInfo^.CursorRect := R;
          end;
        end;
        Exit;
      end;
  end;
  FOldWndProc(Message);
end;

{ TMouse }

constructor TMouse.Create;
begin
  inherited Create;
  FDragImmediate := True;
  FDragThreshold := 5;
  // Mouse wheel is natively supported on Windows 98 and higher
  // and Windows NT 4.0 and higher.
  FNativeWheelSupport :=
    ((Win32Platform = VER_PLATFORM_WIN32_NT) and (Win32MajorVersion >= 4)) or
    ((Win32Platform = VER_PLATFORM_WIN32_WINDOWS) and
    ((Win32MajorVersion > 4) or
    ((Win32MajorVersion = 4) and (Win32MinorVersion >= 10))));
  SettingChanged(0);
end;

destructor TMouse.Destroy;
begin
  Capture := 0;
  inherited Destroy;
end;

function TMouse.GetCapture: HWND;
begin
  Result := Windows.GetCapture;
end;

function TMouse.GetCursorPos: TPoint;
begin
  Win32Check(Windows.GetCursorPos(Result));
end;

procedure TMouse.GetMouseData;
begin
  FMousePresent := BOOL(GetSystemMetrics(SM_MOUSEPRESENT));
end;

procedure TMouse.GetNativeData;
begin
  FWheelPresent := BOOL(GetSystemMetrics(SM_MOUSEWHEELPRESENT));
  if FWheelPresent then
    SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, @FScrollLines, 0);
end;

procedure TMouse.GetRegisteredData;
var
  HasWheel: BOOL;
begin
  FWheelHwnd := HwndMsWheel(FWheelMessage, FWheelSupportMessage,
    FScrollLinesMessage, HasWheel, FScrollLines);
  FWheelPresent := FWheelMessage <> 0;
end;

procedure TMouse.SetCapture(const Value: HWND);
begin
  if Capture <> Value then
  begin
    if Value = 0 then ReleaseCapture
    else Windows.SetCapture(Value);
  end;
end;

procedure TMouse.SetCursorPos(const Value: TPoint);
begin
  Win32Check(Windows.SetCursorPos(Value.x, Value.y));
end;

procedure TMouse.SettingChanged(Setting: Integer);
begin
  case Setting of
    0:
      begin
        GetMouseData;
        if not FNativeWheelSupport then GetRegisteredData
        else GetNativeData;
      end;
    SPI_GETWHEELSCROLLLINES:
      if FWheelPresent then
      begin
        if FNativeWheelSupport then
          SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, @FScrollLines, 0)
        else
          FScrollLines := SendMessage(FWheelHwnd, FScrollLinesMessage, 0, 0)
      end;
  end;
end;

{ Input Method Editor (IME) support code }

var
  IMM32DLL: THandle = 0;
  _WINNLSEnableIME: function(hwnd: HWnd; bool: LongBool): Boolean stdcall;
  _ImmGetContext: function(hWnd: HWND): HIMC stdcall;
  _ImmReleaseContext: function(hWnd: HWND; hImc: HIMC): Boolean stdcall;
  _ImmGetConversionStatus: function(hImc: HIMC; var Conversion, Sentence: DWORD): Boolean stdcall;
  _ImmSetConversionStatus: function(hImc: HIMC; Conversion, Sentence: DWORD): Boolean stdcall;
  _ImmSetOpenStatus: function(hImc: HIMC; fOpen: Boolean): Boolean stdcall;
  _ImmSetCompositionWindow: function(hImc: HIMC; lpCompForm: PCOMPOSITIONFORM): Boolean stdcall;
  _ImmSetCompositionFont: function(hImc: HIMC; lpLogfont: PLOGFONTA): Boolean stdcall;
  _ImmGetCompositionString: function(hImc: HIMC; dWord1: DWORD; lpBuf: pointer; dwBufLen: DWORD): Longint stdcall;
  _ImmIsIME: function(hKl: HKL): Boolean stdcall;
  _ImmNotifyIME: function(hImc: HIMC; dwAction, dwIndex, dwValue: DWORD): Boolean stdcall;

procedure InitIMM32;
var
  UserHandle: THandle;
  OldError: Longint;
begin
  if not Syslocale.FarEast then Exit;
  OldError := SetErrorMode(SEM_NOOPENFILEERRORBOX);
  try
    if not Assigned(_WINNLSEnableIME) then
    begin
      UserHandle := GetModuleHandle('USER32');
      @_WINNLSEnableIME := GetProcAddress(UserHandle, 'WINNLSEnableIME');
    end;

    if IMM32DLL = 0 then
    begin
      IMM32DLL := LoadLibrary('IMM32.DLL');
      if IMM32DLL <> 0 then
      begin
        @_ImmGetContext := GetProcAddress(IMM32DLL, 'ImmGetContext');
        @_ImmReleaseContext := GetProcAddress(IMM32DLL, 'ImmReleaseContext');
        @_ImmGetConversionStatus := GetProcAddress(IMM32DLL, 'ImmGetConversionStatus');
        @_ImmSetConversionStatus := GetProcAddress(IMM32DLL, 'ImmSetConversionStatus');
        @_ImmSetOpenStatus := GetProcAddress(IMM32DLL, 'ImmSetOpenStatus');
        @_ImmSetCompositionWindow := GetProcAddress(IMM32DLL, 'ImmSetCompositionWindow');
        @_ImmSetCompositionFont := GetProcAddress(IMM32DLL, 'ImmSetCompositionFontA');
        @_ImmGetCompositionString := GetProcAddress(IMM32DLL, 'ImmGetCompositionStringA');
        @_ImmIsIME := GetProcAddress(IMM32DLL, 'ImmIsIME');
        @_ImmNotifyIME := GetProcAddress(IMM32DLL, 'ImmNotifyIME');
      end;
    end;
  finally
    SetErrorMode(OldError);
  end;
end;

function Win32NLSEnableIME(hWnd: HWnd; Enable: Boolean): Boolean;
begin
  if Assigned(_WINNLSEnableIME) then
    Result := _WINNLSEnableIME(hWnd, Enable)
  else
    Result := False;
end;

procedure SetImeMode(hWnd: HWnd; Mode: TImeMode);
const
  ModeMap: array [imSAlpha..imHanguel] of Byte =  // flags in use are all < 255
    ( { imSAlpha: } IME_CMODE_ALPHANUMERIC,
      { imAlpha:  } IME_CMODE_ALPHANUMERIC or IME_CMODE_FULLSHAPE,
      { imHira:   } IME_CMODE_NATIVE or IME_CMODE_FULLSHAPE,
      { imSKata:  } IME_CMODE_NATIVE or IME_CMODE_KATAKANA,
      { imKata:   } IME_CMODE_NATIVE or IME_CMODE_KATAKANA or IME_CMODE_FULLSHAPE,
      { imChinese:} IME_CMODE_NATIVE or IME_CMODE_FULLSHAPE,
      { imSHanguel} IME_CMODE_NATIVE,
      { imHanguel } IME_CMODE_NATIVE or IME_CMODE_FULLSHAPE );
var
  IMC: HIMC;
  Conv, Sent: DWORD;
begin
  if (not SysLocale.FarEast) or (Mode = imDontCare) then Exit;

  if Mode = imDisable then
  begin
    Win32NLSEnableIME(hWnd, FALSE);
    Exit;
  end;

  Win32NLSEnableIME(hWnd, TRUE);

  if IMM32DLL = 0 then Exit;

  IMC := _ImmGetContext(hWnd);
  if IMC = 0 then Exit;

  _ImmGetConversionStatus(IMC, Conv, Sent);

  case Mode of
    imClose: _ImmSetOpenStatus(IMC, FALSE);
    imOpen : _ImmSetOpenStatus(IMC, TRUE);
  else
    _ImmSetOpenStatus(IMC, TRUE);
    _ImmGetConversionStatus(IMC, Conv, Sent);
    Conv := Conv and
     (not(IME_CMODE_LANGUAGE or IME_CMODE_FULLSHAPE)) or ModeMap[Mode];
  end;
  _ImmSetConversionStatus(IMC, Conv, Sent);
  _ImmReleaseContext(hWnd, IMC);
end;

procedure SetImeName(Name: TImeName);
var
  I: Integer;
  HandleToSet: HKL;
begin
  if not SysLocale.FarEast then Exit;
  if (Name <> '') and (Screen.Imes.Count <> 0) then
  begin
    HandleToSet := Screen.DefaultKbLayout;
    I := Screen.Imes.IndexOf(Name);
    if I >= 0 then HandleToSet := HKL(Screen.Imes.Objects[I]);
    ActivateKeyboardLayout(HandleToSet, KLF_ACTIVATE);
  end;
end;

function Imm32GetContext(hWnd: HWND): HIMC;
begin
  if IMM32DLL <> 0 then
    Result := _ImmGetContext(hWnd)
  else
    Result := 0;
end;

function Imm32ReleaseContext(hWnd: HWND; hImc: HIMC): Boolean;
begin
  if IMM32DLL <> 0 then
    Result := _ImmReleaseContext(hWnd, hImc)
  else
    Result := False;
end;

function Imm32GetConversionStatus(hImc: HIMC; var Conversion, Sentence: DWORD): Boolean;
begin
  if IMM32DLL <> 0 then
    Result := _ImmGetConversionStatus(hImc, Conversion, Sentence)
  else
    Result := False;
end;

function Imm32SetConversionStatus(hImc: HIMC; Conversion, Sentence: DWORD): Boolean;
begin
  if IMM32DLL <> 0 then
    Result := _ImmSetConversionStatus(hImc, Conversion, Sentence)
  else
    Result := False;
end;

function Imm32SetOpenStatus(hImc: HIMC; fOpen: Boolean): Boolean;
begin
  if IMM32DLL <> 0 then
    Result := _ImmSetOpenStatus(hImc, fOpen)
  else
    Result := False;
end;

function Imm32SetCompositionWindow(hImc: HIMC; lpCompForm: PCOMPOSITIONFORM): Boolean;
begin
  if IMM32DLL <> 0 then
    Result := _ImmSetCompositionWindow(hImc, lpCompForm)
  else
    Result := False;
end;

function Imm32SetCompositionFont(hImc: HIMC; lpLogfont: PLOGFONTA): Boolean;
begin
  if IMM32DLL <> 0 then
    Result := _ImmSetCompositionFont(hImc, lpLogFont)
  else
    Result := False;
end;

function Imm32GetCompositionString(hImc: HIMC; dWord1: DWORD; lpBuf: pointer; dwBufLen: DWORD): Longint;
begin
  if IMM32DLL <> 0 then
    Result := _ImmGetCompositionString(hImc, dWord1, lpBuf, dwBufLen)
  else
    Result := 0;
end;

function Imm32IsIME(hKl: HKL): Boolean;
begin
  if IMM32DLL <> 0 then
    Result := _ImmIsIME(hKl)
  else
    Result := False;
end;

function Imm32NotifyIME(hImc: HIMC; dwAction, dwIndex, dwValue: DWORD): Boolean;
begin
  if IMM32DLL <> 0 then
    Result := _ImmNotifyIME(hImc, dwAction, dwIndex, dwValue)
  else
    Result := False;
end;

{ Initialization and cleanup }

procedure DoneControls;
begin
  Application.Free;
  Application := nil;
  Screen.Free;
  Screen := nil;
  Mouse.Free;
  Mouse := nil;
  CanvasList.Free;
  GlobalDeleteAtom(ControlAtom);
  GlobalDeleteAtom(WindowAtom);
  if IMM32DLL <> 0 then FreeLibrary(IMM32DLL);
end;

procedure InitControls;
var
  AtomText: array[0..31] of Char;
begin
  WindowAtom := GlobalAddAtom(StrFmt(AtomText, 'Delphi%.8X',
    [GetCurrentProcessID]));
  ControlAtom := GlobalAddAtom(
    StrFmt(AtomText, 'ControlOfs%.8X%.8X', [HInstance, GetCurrentThreadID]));
  CanvasList := TThreadList.Create;
  InitIMM32;
  Mouse := TMouse.Create;
  Screen := TScreen.Create(nil);
  Application := TApplication.Create(nil);
  InitCtl3D;
  Application.ShowHint := True;
  RegisterIntegerConsts(TypeInfo(TCursor), IdentToCursor, CursorToIdent);
end;

initialization
  NewStyleControls := Lo(GetVersion) >= 4;
  InitControls;

finalization
  DockSiteList.Free;
  DoneControls;

end.
