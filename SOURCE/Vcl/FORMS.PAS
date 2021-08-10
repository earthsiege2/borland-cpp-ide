{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Forms;

{$P+,S-,W-,R-,T-,H+,X+}
{$C PRELOAD}

interface

uses Messages, Windows, SysUtils, Classes, Graphics, Menus, Controls, Imm,
  ActnList, MultiMon;

type

{ Forward declarations }

  TScrollingWinControl = class;
  TCustomForm = class;
  TForm = class;
  TMonitor = class;

{ TControlScrollBar }

  TScrollBarKind = (sbHorizontal, sbVertical);
  TScrollBarInc = 1..32767;
  TScrollBarStyle = (ssRegular, ssFlat, ssHotTrack);

  TControlScrollBar = class(TPersistent)
  private
    FControl: TScrollingWinControl;
    FIncrement: TScrollBarInc;
    FPageIncrement: TScrollbarInc;
    FPosition: Integer;
    FRange: Integer;
    FCalcRange: Integer;
    FKind: TScrollBarKind;
    FMargin: Word;
    FVisible: Boolean;
    FTracking: Boolean;
    FScaled: Boolean;
    FSmooth: Boolean;
    FDelay: Integer;
    FButtonSize: Integer;
    FColor: TColor;
    FParentColor: Boolean;
    FSize: Integer;
    FStyle: TScrollBarStyle;
    FThumbSize: Integer;
    FPageDiv: Integer;
    FLineDiv: Integer;
    FUpdateNeeded: Boolean;
    constructor Create(AControl: TScrollingWinControl; AKind: TScrollBarKind);
    procedure CalcAutoRange;
    function ControlSize(ControlSB, AssumeSB: Boolean): Integer;
    procedure DoSetRange(Value: Integer);
    function GetScrollPos: Integer;
    function NeedsScrollBarVisible: Boolean;
    function IsIncrementStored: Boolean;
    procedure ScrollMessage(var Msg: TWMScroll);
    procedure SetButtonSize(Value: Integer);
    procedure SetColor(Value: TColor);
    procedure SetParentColor(Value: Boolean);
    procedure SetPosition(Value: Integer);
    procedure SetRange(Value: Integer);
    procedure SetSize(Value: Integer);
    procedure SetStyle(Value: TScrollBarStyle);
    procedure SetThumbSize(Value: Integer);
    procedure SetVisible(Value: Boolean);
    function IsRangeStored: Boolean;
    procedure Update(ControlSB, AssumeSB: Boolean);
  public
    procedure Assign(Source: TPersistent); override;
    procedure ChangeBiDiPosition;
    property Kind: TScrollBarKind read FKind;
    function IsScrollBarVisible: Boolean;
    property ScrollPos: Integer read GetScrollPos;
  published
    property ButtonSize: Integer read FButtonSize write SetButtonSize default 0;
    property Color: TColor read FColor write SetColor default clBtnHighlight;
    property Increment: TScrollBarInc read FIncrement write FIncrement stored IsIncrementStored default 8;
    property Margin: Word read FMargin write FMargin default 0;
    property ParentColor: Boolean read FParentColor write SetParentColor default True;
    property Position: Integer read FPosition write SetPosition default 0;
    property Range: Integer read FRange write SetRange stored IsRangeStored default 0;
    property Smooth: Boolean read FSmooth write FSmooth default False;
    property Size: Integer read FSize write SetSize default 0;
    property Style: TScrollBarStyle read FStyle write SetStyle default ssRegular;
    property ThumbSize: Integer read FThumbSize write SetThumbSize default 0;
    property Tracking: Boolean read FTracking write FTracking default False;
    property Visible: Boolean read FVisible write SetVisible default True;
  end;

{ TScrollingWinControl }

  TWindowState = (wsNormal, wsMinimized, wsMaximized);

  TScrollingWinControl = class(TWinControl)
  private
    FHorzScrollBar: TControlScrollBar;
    FVertScrollBar: TControlScrollBar;
    FAutoScroll: Boolean;
    FAutoRangeCount: Integer;
    FUpdatingScrollBars: Boolean;
    procedure CalcAutoRange;
    procedure ScaleScrollBars(M, D: Integer);
    procedure SetAutoScroll(Value: Boolean);
    procedure SetHorzScrollBar(Value: TControlScrollBar);
    procedure SetVertScrollBar(Value: TControlScrollBar);
    procedure UpdateScrollBars;
    procedure WMSize(var Message: TWMSize); message WM_SIZE;
    procedure WMHScroll(var Message: TWMHScroll); message WM_HSCROLL;
    procedure WMVScroll(var Message: TWMVScroll); message WM_VSCROLL;
    procedure CMBiDiModeChanged(var Message: TMessage); message CM_BIDIMODECHANGED;
  protected
    procedure AdjustClientRect(var Rect: TRect); override;
    procedure AlignControls(AControl: TControl; var ARect: TRect); override;
    function AutoScrollEnabled: Boolean; virtual;
    procedure AutoScrollInView(AControl: TControl); virtual;
    procedure ChangeScale(M, D: Integer); override;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWnd; override;
    procedure DoFlipChildren; override;
    property AutoScroll: Boolean read FAutoScroll write SetAutoScroll default True;
    procedure Resizing(State: TWindowState); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure DisableAutoRange;
    procedure EnableAutoRange;
    procedure ScrollInView(AControl: TControl);
  published
    property HorzScrollBar: TControlScrollBar read FHorzScrollBar write SetHorzScrollBar;
    property VertScrollBar: TControlScrollBar read FVertScrollBar write SetVertScrollBar;
  end;

{ TScrollBox }

  TFormBorderStyle = (bsNone, bsSingle, bsSizeable, bsDialog, bsToolWindow,
    bsSizeToolWin);
  TBorderStyle = bsNone..bsSingle;

  TScrollBox = class(TScrollingWinControl)
  private
    FBorderStyle: TBorderStyle;
    procedure SetBorderStyle(Value: TBorderStyle);
    procedure WMNCHitTest(var Message: TMessage); message WM_NCHITTEST;
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
  protected
    procedure CreateParams(var Params: TCreateParams); override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Align;
    property Anchors;
    property AutoScroll;
    property AutoSize;
    property BiDiMode;
    property BorderStyle: TBorderStyle read FBorderStyle write SetBorderStyle default bsSingle;
    property Constraints;
    property DockSite;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property Color nodefault;
    property Ctl3D;
    property Font;
    property ParentBiDiMode;
    property ParentColor;
    property ParentCtl3D;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnCanResize;
    property OnClick;
    property OnConstrainedResize;
    property OnContextPopup;
    property OnDblClick;
    property OnDockDrop;
    property OnDockOver;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnGetSiteInfo;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnMouseWheel;
    property OnMouseWheelDown;
    property OnMouseWheelUp;
    property OnResize;
    property OnStartDock;
    property OnStartDrag;
    property OnUnDock;
  end;

{ TCustomFrame }

  TCustomFrame = class(TScrollingWinControl)
  private
    procedure AddActionList(ActionList: TCustomActionList);
    procedure RemoveActionList(ActionList: TCustomActionList);
  protected
    procedure CreateParams(var Params: TCreateParams); override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure SetParent(AParent: TWinControl); override;
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TCustomFrameClass = class of TCustomFrame;

{ TFrame }

  TFrame = class(TCustomFrame)
  published
    property Align;
    property Anchors;
    property AutoScroll;
    property AutoSize;
    property BiDiMode;
    property Constraints;
    property DockSite;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property Color nodefault;
    property Ctl3D;
    property Font;
    property ParentBiDiMode;
    property ParentColor;
    property ParentCtl3D;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnCanResize;
    property OnClick;
    property OnConstrainedResize;
    property OnContextPopup;
    property OnDblClick;
    property OnDockDrop;
    property OnDockOver;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnGetSiteInfo;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnMouseWheel;
    property OnMouseWheelDown;
    property OnMouseWheelUp;
    property OnResize;
    property OnStartDock;
    property OnStartDrag;
    property OnUnDock;
  end;

{ IDesigner }

  IDesigner = interface(IDesignerNotify)
    ['{ABBE7256-5495-11D1-9FB5-0020AF3D82DA}']
    function GetCustomForm: TCustomForm;
    procedure SetCustomForm(Value: TCustomForm);
    function GetIsControl: Boolean;
    procedure SetIsControl(Value: Boolean);
    function IsDesignMsg(Sender: TControl; var Message: TMessage): Boolean;
    procedure PaintGrid;
    procedure ValidateRename(AComponent: TComponent;
      const CurName, NewName: string);
    function UniqueName(const BaseName: string): string;
    function GetRoot: TComponent;
    property IsControl: Boolean read GetIsControl write SetIsControl;
    property Form: TCustomForm read GetCustomForm write SetCustomForm;
  end;

{ IOleForm }

  IOleForm = interface
    ['{CD02E1C1-52DA-11D0-9EA6-0020AF3D82DA}']
    procedure OnDestroy;
    procedure OnResize;
  end;
  
{ TCustomForm }

  TFormStyle = (fsNormal, fsMDIChild, fsMDIForm, fsStayOnTop);
  TBorderIcon = (biSystemMenu, biMinimize, biMaximize, biHelp);
  TBorderIcons = set of TBorderIcon;
  TPosition = (poDesigned, poDefault, poDefaultPosOnly, poDefaultSizeOnly,
    poScreenCenter, poDesktopCenter, poMainFormCenter, poOwnerFormCenter);
  TDefaultMonitor = (dmDesktop, dmPrimary, dmMainForm, dmActiveForm);
  TPrintScale = (poNone, poProportional, poPrintToFit);
  TShowAction = (saIgnore, saRestore, saMinimize, saMaximize);
  TTileMode = (tbHorizontal, tbVertical);
  TModalResult = Low(Integer)..High(Integer);
  TCloseAction = (caNone, caHide, caFree, caMinimize);
  TCloseEvent = procedure(Sender: TObject; var Action: TCloseAction) of object;
  TCloseQueryEvent = procedure(Sender: TObject;
    var CanClose: Boolean) of object;
  TFormState = set of (fsCreating, fsVisible, fsShowing, fsModal,
    fsCreatedMDIChild, fsActivated);
  TShortCutEvent = procedure (var Msg: TWMKey; var Handled: Boolean) of object;

  TCustomForm = class(TScrollingWinControl)
  private
    FActiveControl: TWinControl;
    FFocusedControl: TWinControl;
    FBorderIcons: TBorderIcons;
    FBorderStyle: TFormBorderStyle;
    FSizeChanging: Boolean;
    FWindowState: TWindowState;
    FShowAction: TShowAction;
    FKeyPreview: Boolean;
    FActive: Boolean;
    FFormStyle: TFormStyle;
    FPosition: TPosition;
    FDefaultMonitor: TDefaultMonitor;
    FTileMode: TTileMode;
    FDropTarget: Boolean;
    FOldCreateOrder: Boolean;
    FPrintScale: TPrintScale;
    FCanvas: TControlCanvas;
    FHelpFile: string;
    FIcon: TIcon;
    FInCMParentBiDiModeChanged: Boolean;
    FMenu: TMainMenu;
    FModalResult: TModalResult;
    FDesigner: IDesigner;
    FClientHandle: HWND;
    FWindowMenu: TMenuItem;
    FPixelsPerInch: Integer;
    FObjectMenuItem: TMenuItem;
    FOleForm: IOleForm;
    FClientWidth: Integer;
    FClientHeight: Integer;
    FTextHeight: Integer;
    FDefClientProc: TFarProc;
    FClientInstance: TFarProc;
    FActiveOleControl: TWinControl;
    FSavedBorderStyle: TFormBorderStyle;
    FOnActivate: TNotifyEvent;
    FOnClose: TCloseEvent;
    FOnCloseQuery: TCloseQueryEvent;
    FOnDeactivate: TNotifyEvent;
    FOnHelp: THelpEvent;
    FOnHide: TNotifyEvent;
    FOnPaint: TNotifyEvent;
    FOnShortCut: TShortCutEvent;
    FOnShow: TNotifyEvent;
    FOnCreate: TNotifyEvent;
    FOnDestroy: TNotifyEvent;
    procedure RefreshMDIMenu;
    procedure ClientWndProc(var Message: TMessage);
    procedure CloseModal;
    function GetActiveMDIChild: TForm;
    function GetCanvas: TCanvas;
    function GetIconHandle: HICON;
    function GetMDIChildCount: Integer;
    function GetMDIChildren(I: Integer): TForm;
    function GetMonitor: TMonitor;
    function GetPixelsPerInch: Integer;
    function GetScaled: Boolean;
    function GetTextHeight: Integer;
    procedure IconChanged(Sender: TObject);
    function IsAutoScrollStored: Boolean;
    function IsClientSizeStored: Boolean;
    function IsForm: Boolean;
    function IsFormSizeStored: Boolean;
    function IsIconStored: Boolean;
    procedure MergeMenu(MergeState: Boolean);
    procedure ReadIgnoreFontProperty(Reader: TReader);
    procedure ReadTextHeight(Reader: TReader);
    procedure SetActive(Value: Boolean);
    procedure SetActiveControl(Control: TWinControl);
    procedure SetBorderIcons(Value: TBorderIcons);
    procedure SetBorderStyle(Value: TFormBorderStyle);
    procedure SetClientHeight(Value: Integer);
    procedure SetClientWidth(Value: Integer);
    procedure SetDesigner(ADesigner: IDesigner);
    procedure SetFormStyle(Value: TFormStyle);
    procedure SetIcon(Value: TIcon);
    procedure SetMenu(Value: TMainMenu);
    procedure SetPixelsPerInch(Value: Integer);
    procedure SetPosition(Value: TPosition);
    procedure SetScaled(Value: Boolean);
    procedure SetVisible(Value: Boolean);
    procedure SetWindowFocus;
    procedure SetWindowMenu(Value: TMenuItem);
    procedure SetObjectMenuItem(Value: TMenuItem);
    procedure SetWindowState(Value: TWindowState);
    procedure SetWindowToMonitor;
    procedure WritePixelsPerInch(Writer: TWriter);
    procedure WriteTextHeight(Writer: TWriter);
    function NormalColor: TColor;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
    procedure WMEraseBkgnd(var Message: TWMEraseBkgnd); message WM_ERASEBKGND;
    procedure WMIconEraseBkgnd(var Message: TWMEraseBkgnd); message WM_ICONERASEBKGND;
    procedure WMQueryDragIcon(var Message: TWMQueryDragIcon); message WM_QUERYDRAGICON;
    procedure WMNCCreate(var Message: TWMNCCreate); message WM_NCCREATE;
    procedure WMNCLButtonDown(var Message: TWMNCLButtonDown); message WM_NCLBUTTONDOWN;
    procedure WMDestroy(var Message: TWMDestroy); message WM_DESTROY;
    procedure WMCommand(var Message: TWMCommand); message WM_COMMAND;
    procedure WMInitMenuPopup(var Message: TWMInitMenuPopup); message WM_INITMENUPOPUP;
    procedure WMMenuChar(var Message: TWMMenuChar); message WM_MENUCHAR;
    procedure WMMenuSelect(var Message: TWMMenuSelect); message WM_MENUSELECT;
    procedure WMActivate(var Message: TWMActivate); message WM_ACTIVATE;
    procedure WMClose(var Message: TWMClose); message WM_CLOSE;
    procedure WMQueryEndSession(var Message: TWMQueryEndSession); message WM_QUERYENDSESSION;
    procedure WMSysCommand(var Message: TWMSysCommand); message WM_SYSCOMMAND;
    procedure WMShowWindow(var Message: TWMShowWindow); message WM_SHOWWINDOW;
    procedure WMMDIActivate(var Message: TWMMDIActivate); message WM_MDIACTIVATE;
    procedure WMNextDlgCtl(var Message: TWMNextDlgCtl); message WM_NEXTDLGCTL;
    procedure WMEnterMenuLoop(var Message: TMessage); message WM_ENTERMENULOOP;
    procedure WMHelp(var Message: TWMHelp); message WM_HELP;
    procedure WMGetMinMaxInfo(var Message: TWMGetMinMaxInfo); message WM_GETMINMAXINFO;
    procedure WMSettingChange(var Message: TMessage); message WM_SETTINGCHANGE;
    procedure WMWindowPosChanging(var Message: TWMWindowPosChanging); message WM_WINDOWPOSCHANGING;
    procedure CMActionExecute(var Message: TMessage); message CM_ACTIONEXECUTE;
    procedure CMActionUpdate(var Message: TMessage); message CM_ACTIONUPDATE;
    procedure CMActivate(var Message: TCMActivate); message CM_ACTIVATE;
    procedure CMAppSysCommand(var Message: TMessage); message CM_APPSYSCOMMAND;
    procedure CMBiDiModeChanged(var Message: TMessage); message CM_BIDIMODECHANGED;
    procedure CMDeactivate(var Message: TCMDeactivate); message CM_DEACTIVATE;
    procedure CMDialogKey(var Message: TCMDialogKey); message CM_DIALOGKEY;
    procedure CMColorChanged(var Message: TMessage); message CM_COLORCHANGED;
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure CMMenuChanged(var Message: TMessage); message CM_MENUCHANGED;
    procedure CMShowingChanged(var Message: TMessage); message CM_SHOWINGCHANGED;
    procedure CMIconChanged(var Message: TMessage); message CM_ICONCHANGED;
    procedure CMRelease(var Message: TMessage); message CM_RELEASE;
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
    procedure CMUIActivate(var Message); message CM_UIACTIVATE;
    procedure CMParentBiDiModeChanged(var Message: TMessage); message CM_PARENTBIDIMODECHANGED;
    procedure CMParentFontChanged(var Message: TMessage); message CM_PARENTFONTCHANGED;
  protected
    FActionLists: TList;
    FFormState: TFormState;
    procedure Activate; dynamic;
    procedure ActiveChanged; dynamic;
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    procedure BeginAutoDrag; override;
    procedure ChangeScale(M, D: Integer); override;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWindowHandle(const Params: TCreateParams); override;
    procedure CreateWnd; override;
    procedure Deactivate; dynamic;
    procedure DefineProperties(Filer: TFiler); override;
    procedure DestroyWindowHandle; override;
    procedure DoClose(var Action: TCloseAction); dynamic;
    procedure DoCreate; virtual;
    procedure DoDestroy; virtual;
    procedure DoHide; dynamic;
    procedure DoShow; dynamic;
    function GetClientRect: TRect; override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    function GetFloating: Boolean; override;
    procedure Loaded; override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure Paint; dynamic;
    procedure PaintWindow(DC: HDC); override;
    function PaletteChanged(Foreground: Boolean): Boolean; override;
    function QueryInterface(const IID: TGUID; out Obj): HResult; override;
    procedure ReadState(Reader: TReader); override;
    procedure RequestAlign; override;
    procedure SetChildOrder(Child: TComponent; Order: Integer); override;
    procedure SetParentBiDiMode(Value: Boolean); override;
    procedure DoDock(NewDockSite: TWinControl; var ARect: TRect); override;
    procedure SetParent(AParent: TWinControl); override;
    procedure UpdateActions; virtual;
    procedure UpdateWindowState;
    procedure ValidateRename(AComponent: TComponent;
      const CurName, NewName: string); override;
    procedure VisibleChanging; override;
    procedure WndProc(var Message: TMessage); override;
    procedure Resizing(State: TWindowState); override;
    property ActiveMDIChild: TForm read GetActiveMDIChild;
    property BorderIcons: TBorderIcons read FBorderIcons write SetBorderIcons stored IsForm
      default [biSystemMenu, biMinimize, biMaximize];
    property AutoScroll stored IsAutoScrollStored;
    property ClientHandle: HWND read FClientHandle;
    property ClientHeight write SetClientHeight stored IsClientSizeStored;
    property ClientWidth write SetClientWidth stored IsClientSizeStored;
    property Ctl3D default True;
    property DefaultMonitor: TDefaultMonitor read FDefaultMonitor write FDefaultMonitor
      stored IsForm default dmActiveForm;
    property FormStyle: TFormStyle read FFormStyle write SetFormStyle
      stored IsForm default fsNormal;
    property Height stored IsFormSizeStored;
    property HorzScrollBar stored IsForm;
    property Icon: TIcon read FIcon write SetIcon stored IsIconStored;
    property MDIChildCount: Integer read GetMDIChildCount;
    property MDIChildren[I: Integer]: TForm read GetMDIChildren;
    property OldCreateOrder: Boolean read FOldCreateOrder write FOldCreateOrder;
    property ObjectMenuItem: TMenuItem read FObjectMenuItem write SetObjectMenuItem
      stored IsForm;
    property PixelsPerInch: Integer read GetPixelsPerInch write SetPixelsPerInch
      stored False;
    property ParentFont default False;
    property PopupMenu stored IsForm;
    property Position: TPosition read FPosition write SetPosition stored IsForm
      default poDesigned;
    property PrintScale: TPrintScale read FPrintScale write FPrintScale stored IsForm
      default poProportional;
    property Scaled: Boolean read GetScaled write SetScaled stored IsForm default True;
    property TileMode: TTileMode read FTileMode write FTileMode default tbHorizontal;
    property VertScrollBar stored IsForm;
    property Visible write SetVisible default False;
    property Width stored IsFormSizeStored;
    property WindowMenu: TMenuItem read FWindowMenu write SetWindowMenu stored IsForm;
    property OnActivate: TNotifyEvent read FOnActivate write FOnActivate stored IsForm;
    property OnCanResize stored IsForm;
    property OnClick stored IsForm;
    property OnClose: TCloseEvent read FOnClose write FOnClose stored IsForm;
    property OnCloseQuery: TCloseQueryEvent read FOnCloseQuery write FOnCloseQuery
      stored IsForm;
    property OnCreate: TNotifyEvent read FOnCreate write FOnCreate stored IsForm;
    property OnDblClick stored IsForm;
    property OnDestroy: TNotifyEvent read FOnDestroy write FOnDestroy stored IsForm;
    property OnDeactivate: TNotifyEvent read FOnDeactivate write FOnDeactivate stored IsForm;
    property OnDragDrop stored IsForm;
    property OnDragOver stored IsForm;
    property OnHelp: THelpEvent read FOnHelp write FOnHelp;
    property OnHide: TNotifyEvent read FOnHide write FOnHide stored IsForm;
    property OnKeyDown stored IsForm;
    property OnKeyPress stored IsForm;
    property OnKeyUp stored IsForm;
    property OnMouseDown stored IsForm;
    property OnMouseMove stored IsForm;
    property OnMouseUp stored IsForm;
    property OnPaint: TNotifyEvent read FOnPaint write FOnPaint stored IsForm;
    property OnResize stored IsForm;
    property OnShortCut: TShortCutEvent read FOnShortCut write FOnShortCut;
    property OnShow: TNotifyEvent read FOnShow write FOnShow stored IsForm;
  public
    constructor Create(AOwner: TComponent); override;
    constructor CreateNew(AOwner: TComponent; Dummy: Integer = 0); virtual;
    destructor Destroy; override;
    procedure AfterConstruction; override;
    procedure BeforeDestruction; override;
    procedure Close;
    function CloseQuery: Boolean; virtual;
    procedure DefaultHandler(var Message); override;
    procedure DefocusControl(Control: TWinControl; Removing: Boolean);
    procedure Dock(NewDockSite: TWinControl; ARect: TRect); override;
    procedure FocusControl(Control: TWinControl);
    function GetFormImage: TBitmap;
    procedure Hide;
    function IsShortCut(var Message: TWMKey): Boolean; dynamic;
    procedure MouseWheelHandler(var Message: TMessage); override;
    procedure Print;
    procedure Release;
    procedure SendCancelMode(Sender: TControl);
    procedure SetFocus; override;
    function SetFocusedControl(Control: TWinControl): Boolean; virtual;
    procedure Show;
    function ShowModal: Integer; virtual;
    function WantChildKey(Child: TControl; var Message: TMessage): Boolean; virtual;
    property Active: Boolean read FActive;
    property ActiveControl: TWinControl read FActiveControl write SetActiveControl
      stored IsForm;
    property Action;
    property ActiveOleControl: TWinControl read FActiveOleControl write FActiveOleControl;
    property BorderStyle: TFormBorderStyle read FBorderStyle write SetBorderStyle
      stored IsForm default bsSizeable;
    property Canvas: TCanvas read GetCanvas;
    property Caption stored IsForm;
    property Color nodefault;
    property Designer: IDesigner read FDesigner write SetDesigner;
    property DropTarget: Boolean read FDropTarget write FDropTarget;
    property Font;
    property FormState: TFormState read FFormState;
    property HelpFile: string read FHelpFile write FHelpFile;
    property KeyPreview: Boolean read FKeyPreview write FKeyPreview
      stored IsForm default False;
    property Menu: TMainMenu read FMenu write SetMenu stored IsForm;
    property ModalResult: TModalResult read FModalResult write FModalResult;
    property Monitor: TMonitor read GetMonitor;
    property OleFormObject: IOleForm read FOleForm write FOleForm;
    property WindowState: TWindowState read FWindowState write SetWindowState
      stored IsForm default wsNormal;
  end;
  
  TCustomFormClass = class of TCustomForm;

  { TCustomActiveForm }

  TActiveFormBorderStyle = (afbNone, afbSingle, afbSunken, afbRaised);

  TCustomActiveForm = class(TCustomForm)
  private
    FAxBorderStyle: TActiveFormBorderStyle;
    procedure SetAxBorderStyle(Value: TActiveFormBorderStyle);
  protected
    procedure CreateParams(var Params: TCreateParams); override;
  public
    constructor Create(AOwner: TComponent); override;
    function WantChildKey(Child: TControl; var Message: TMessage): Boolean; override;
    property Visible;
  published
    property ActiveControl;
    property Anchors;
    property AutoScroll;
    property AutoSize;
    property AxBorderStyle: TActiveFormBorderStyle read FAxBorderStyle
      write SetAxBorderStyle default afbSingle;
    property BorderWidth;
    property Caption stored True;
    property Color;
    property Constraints;
    property Font;
    property Height stored True;
    property HorzScrollBar;
    property KeyPreview;
    property OldCreateOrder;
    property PixelsPerInch;
    property PopupMenu;
    property PrintScale;
    property Scaled;
    property ShowHint;
    property VertScrollBar;
    property Width stored True;
    property OnActivate;
    property OnClick;
    property OnCreate;
    property OnContextPopup;
    property OnDblClick;
    property OnDestroy;
    property OnDeactivate;
    property OnDragDrop;
    property OnDragOver;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnPaint;
  end;

{ TForm }

  TForm = class(TCustomForm)
  public
    procedure ArrangeIcons;
    procedure Cascade;
    procedure Next;
    procedure Previous;
    procedure Tile;
    property ActiveMDIChild;
    property ClientHandle;
    property DockManager;
    property MDIChildCount;
    property MDIChildren;
    property TileMode;
  published
    property Action;
    property ActiveControl;
    property Align;
    property Anchors;
    property AutoScroll;
    property AutoSize;
    property BiDiMode;
    property BorderIcons;
    property BorderStyle;
    property BorderWidth;
    property Caption;
    property ClientHeight;
    property ClientWidth;
    property Color;
    property Constraints;
    property Ctl3D;
    property UseDockManager;
    property DefaultMonitor;
    property DockSite;
    property DragKind;
    property DragMode;
    property Enabled;
    property ParentFont default False;
    property Font;
    property FormStyle;
    property Height;
    property HelpFile;
    property HorzScrollBar;
    property Icon;
    property KeyPreview;
    property Menu;
    property OldCreateOrder;
    property ObjectMenuItem;
    property ParentBiDiMode;
    property PixelsPerInch;
    property PopupMenu;
    property Position;
    property PrintScale;
    property Scaled;
    property ShowHint;
    property VertScrollBar;
    property Visible;
    property Width;
    property WindowState;
    property WindowMenu;
    property OnActivate;
    property OnCanResize;
    property OnClick;
    property OnClose;
    property OnCloseQuery;
    property OnConstrainedResize;
    property OnContextPopup;
    property OnCreate;
    property OnDblClick;
    property OnDestroy;
    property OnDeactivate;
    property OnDockDrop;
    property OnDockOver;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnGetSiteInfo;
    property OnHide;
    property OnHelp;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnMouseWheel;
    property OnMouseWheelDown;
    property OnMouseWheelUp;
    property OnPaint;
    property OnResize;
    property OnShortCut;
    property OnShow;
    property OnStartDock;
    property OnUnDock;
  end;

  TFormClass = class of TForm;

{ TCustomDockForm }

  TCustomDockForm = class(TCustomForm)
  private
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTESt;
    procedure WMNCLButtonDown(var Message: TWMNCLButtonDown); message WM_NCLBUTTONDOWN;
    procedure CMControlListChange(var Message: TMessage); message CM_CONTROLLISTCHANGE;
    procedure CMDockNotification(var Message: TCMDockNotification); message CM_DOCKNOTIFICATION;
    procedure CMUnDockClient(var Message: TCMUnDockClient); message CM_UNDOCKCLIENT;
    procedure CMVisibleChanged(var Message: TMessage); message CM_VISIBLECHANGED;
  protected
    procedure DoAddDockClient(Client: TControl; const ARect: TRect); override;
    procedure DoRemoveDockClient(Client: TControl); override;
    procedure GetSiteInfo(Client: TControl; var InfluenceRect: TRect;
      MousePos: TPoint; var CanDock: Boolean); override;
    procedure Loaded; override;
  public
    constructor Create(AOwner: TComponent); override;
    property AutoScroll default False;
    property BorderStyle default bsSizeToolWin;
    property FormStyle default fsStayOnTop;
  published
    property PixelsPerInch;
  end;

{ TDataModule }

  TDataModule = class(TComponent)
  private
    FDesignSize: TPoint;
    FDesignOffset: TPoint;
    FOnCreate: TNotifyEvent;
    FOnDestroy: TNotifyEvent;
    FOldCreateOrder: Boolean;
    procedure ReadHeight(Reader: TReader);
    procedure ReadHorizontalOffset(Reader: TReader);
    procedure ReadVerticalOffset(Reader: TReader);
    procedure ReadWidth(Reader: TReader);
    procedure WriteWidth(Writer: TWriter);
    procedure WriteHorizontalOffset(Writer: TWriter);
    procedure WriteVerticalOffset(Writer: TWriter);
    procedure WriteHeight(Writer: TWriter);
  protected
    procedure DoCreate; virtual;
    procedure DoDestroy; virtual;
    procedure DefineProperties(Filer: TFiler); override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure ReadState(Reader: TReader); override;
  public
    constructor Create(AOwner: TComponent); override;
    constructor CreateNew(AOwner: TComponent; Dummy: Integer = 0); virtual;
    destructor Destroy; override;
    procedure AfterConstruction; override;
    procedure BeforeDestruction; override;
    property DesignOffset: TPoint read FDesignOffset write FDesignOffset;
    property DesignSize: TPoint read FDesignSize write FDesignSize;
  published
    property OldCreateOrder: Boolean read FOldCreateOrder write FOldCreateOrder;
    property OnCreate: TNotifyEvent read FOnCreate write FOnCreate;
    property OnDestroy: TNotifyEvent read FOnDestroy write FOnDestroy;
  end;

{ TMonitor }

  TMonitor = class
  private
    FHandle: HMONITOR;
    FMonitorNum: Integer;
    function GetLeft: Integer;
    function GetHeight: Integer;
    function GetTop: Integer;
    function GetWidth: Integer;
  public
    property Handle: HMONITOR read FHandle;
    property MonitorNum: Integer read FMonitorNum;
    property Left: Integer read GetLeft;
    property Height: Integer read GetHeight;
    property Top: Integer read GetTop;
    property Width: Integer read GetWidth;
  end;

{ TScreen }

  PCursorRec = ^TCursorRec;
  TCursorRec = record
    Next: PCursorRec;
    Index: Integer;
    Handle: HCURSOR;
  end;

  TScreen = class(TComponent)
  private
    FFonts: TStrings;
    FImes: TStrings;
    FDefaultIme: string;
    FDefaultKbLayout: HKL;
    FPixelsPerInch: Integer;
    FCursor: TCursor;
    FCursorCount: Integer;
    FForms: TList;
    FCustomForms: TList;
    FDataModules: TList;
    FMonitors: TList;
    FCursorList: PCursorRec;
    FDefaultCursor: HCURSOR;
    FActiveControl: TWinControl;
    FActiveCustomForm: TCustomForm;
    FActiveForm: TForm;
    FLastActiveControl: TWinControl;
    FLastActiveCustomForm: TCustomForm;
    FFocusedForm: TCustomForm;
    FSaveFocusedList: TList;
    FHintFont: TFont;
    FIconFont: TFont;
    FMenuFont: TFont;
    FAlignLevel: Word;
    FControlState: TControlState;
    FOnActiveControlChange: TNotifyEvent;
    FOnActiveFormChange: TNotifyEvent;
    procedure AlignForm(AForm: TCustomForm);
    procedure AlignForms(AForm: TCustomForm; var Rect: TRect);
    procedure AddDataModule(DataModule: TDataModule);
    procedure AddForm(AForm: TCustomForm);
    procedure CreateCursors;
    procedure DeleteCursor(Index: Integer);
    procedure DestroyCursors;
    procedure IconFontChanged(Sender: TObject);
    function GetCustomFormCount: Integer;
    function GetCustomForms(Index: Integer): TCustomForm;
    function GetCursors(Index: Integer): HCURSOR;
    function GetDataModule(Index: Integer): TDataModule;
    function GetDataModuleCount: Integer;
    function GetDefaultIME: String;
    function GetDesktopTop: Integer;
    function GetDesktopLeft: Integer;
    function GetDesktopHeight: Integer;
    function GetDesktopWidth: Integer;
    function GetImes: TStrings;
    function GetHeight: Integer;
    function GetMonitor(Index: Integer): TMonitor;
    function GetMonitorCount: Integer;
    function GetFonts: TStrings;
    function GetForm(Index: Integer): TForm;
    function GetFormCount: Integer;
    procedure GetMetricSettings;
    function GetWidth: Integer;
    procedure InsertCursor(Index: Integer; Handle: HCURSOR);
    procedure RemoveDataModule(DataModule: TDataModule);
    procedure RemoveForm(AForm: TCustomForm);
    procedure SetCursors(Index: Integer; Handle: HCURSOR);
    procedure SetCursor(Value: TCursor);
    procedure SetHintFont(Value: TFont);
    procedure SetIconFont(Value: TFont);
    procedure SetMenuFont(Value: TFont);
    procedure UpdateLastActive;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure DisableAlign;
    procedure EnableAlign;
    procedure Realign;
    procedure ResetFonts;
    property ActiveControl: TWinControl read FActiveControl;
    property ActiveCustomForm: TCustomForm read FActiveCustomForm;
    property ActiveForm: TForm read FActiveForm;
    property CustomFormCount: Integer read GetCustomFormCount;
    property CustomForms[Index: Integer]: TCustomForm read GetCustomForms;
    property Cursor: TCursor read FCursor write SetCursor;
    property Cursors[Index: Integer]: HCURSOR read GetCursors write SetCursors;
    property DataModules[Index: Integer]: TDataModule read GetDataModule;
    property DataModuleCount: Integer read GetDataModuleCount;
    property MonitorCount: Integer read GetMonitorCount;
    property Monitors[Index: Integer]: TMonitor read GetMonitor;
    property DesktopHeight: Integer read GetDesktopHeight;
    property DesktopLeft: Integer read GetDesktopLeft;
    property DesktopTop: Integer read GetDesktopTop;
    property DesktopWidth: Integer read GetDesktopWidth;
    property HintFont: TFont read FHintFont write SetHintFont;
    property IconFont: TFont read FIconFont write SetIconFont;
    property MenuFont: TFont read FMenuFont write SetMenuFont;
    property Fonts: TStrings read GetFonts;
    property FormCount: Integer read GetFormCount;
    property Forms[Index: Integer]: TForm read GetForm;
    property Imes: TStrings read GetImes;
    property DefaultIme: string read GetDefaultIme;
    property DefaultKbLayout: HKL read FDefaultKbLayout;
    property Height: Integer read GetHeight;
    property PixelsPerInch: Integer read FPixelsPerInch;
    property Width: Integer read GetWidth;
    property OnActiveControlChange: TNotifyEvent
      read FOnActiveControlChange write FOnActiveControlChange;
    property OnActiveFormChange: TNotifyEvent
      read FOnActiveFormChange write FOnActiveFormChange;
  end;

{ TApplication }

  TTimerMode = (tmShow, tmHide);

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
    HintStr: string;
    HintData: Pointer;
  end;

  TCMHintShow = record
    Msg: Cardinal;
    Reserved: Integer;
    HintInfo: PHintInfo;
    Result: Integer;
  end;

  TCMHintShowPause = record
    Msg: Cardinal;
    WasActive: Integer;
    Pause: PInteger;
    Result: Integer;
  end;

  TMessageEvent = procedure (var Msg: TMsg; var Handled: Boolean) of object;
  TExceptionEvent = procedure (Sender: TObject; E: Exception) of object;
  TIdleEvent = procedure (Sender: TObject; var Done: Boolean) of object;
  TShowHintEvent = procedure (var HintStr: string; var CanShow: Boolean;
    var HintInfo: THintInfo) of object;
  TWindowHook = function (var Message: TMessage): Boolean of object;

  TApplication = class(TComponent)
  private
    FHandle: HWnd;
    FBiDiMode: TBiDiMode;
    FBiDiKeyboard: string;
    FNonBiDiKeyboard: string;
    FObjectInstance: Pointer;
    FMainForm: TForm;
    FMouseControl: TControl;
    FHelpFile: string;
    FHint: string;
    FHintActive: Boolean;
    FUpdateFormatSettings: Boolean;
    FUpdateMetricSettings: Boolean;
    FShowMainForm: Boolean;
    FHintColor: TColor;
    FHintControl: TControl;
    FHintCursorRect: TRect;
    FHintHidePause: Integer;
    FHintPause: Integer;
    FHintShortCuts: Boolean;
    FHintShortPause: Integer;
    FHintWindow: THintWindow;
    FShowHint: Boolean;
    FTimerMode: TTimerMode;
    FTimerHandle: Word;
    FTitle: string;
    FTopMostList: TList;
    FTopMostLevel: Integer;
    FIcon: TIcon;
    FTerminate: Boolean;
    FActive: Boolean;
    FAllowTesting: Boolean;
    FTestLib: THandle;
    FHandleCreated: Boolean;
    FRunning: Boolean;
    FWindowHooks: TList;
    FWindowList: Pointer;
    FDialogHandle: HWnd;
    FOnActionExecute: TActionEvent;
    FOnActionUpdate: TActionEvent;
    FOnException: TExceptionEvent;
    FOnMessage: TMessageEvent;
    FOnHelp: THelpEvent;
    FOnHint: TNotifyEvent;
    FOnIdle: TIdleEvent;
    FOnDeactivate: TNotifyEvent;
    FOnActivate: TNotifyEvent;
    FOnMinimize: TNotifyEvent;
    FOnRestore: TNotifyEvent;
    FOnShortCut: TShortCutEvent;
    FOnShowHint: TShowHintEvent;
    function CheckIniChange(var Message: TMessage): Boolean;
    function DispatchAction(Msg: Longint; Action: TBasicAction): Boolean; 
    procedure DoActionIdle;
    function DoMouseIdle: TControl;
    procedure DoNormalizeTopMosts(IncludeMain: Boolean);
    function GetCurrentHelpFile: string;
    function GetDialogHandle: HWND;
    function GetExeName: string;
    function GetIconHandle: HICON;
    function GetTitle: string;
    procedure HintTimerExpired;
    procedure IconChanged(Sender: TObject);
    procedure Idle(const Msg: TMsg);
    function InvokeHelp(Command: Word; Data: Longint): Boolean;
    function IsDlgMsg(var Msg: TMsg): Boolean;
    function IsHintMsg(var Msg: TMsg): Boolean;
    function IsKeyMsg(var Msg: TMsg): Boolean;
    function IsMDIMsg(var Msg: TMsg): Boolean;
    function IsShortCut(var Message: TWMKey): Boolean;
    procedure NotifyForms(Msg: Word);
    function ProcessMessage(var Msg: TMsg): Boolean;
    procedure SetBiDiMode(Value: TBiDiMode);
    procedure SetDialogHandle(Value: HWnd);
    procedure SetHandle(Value: HWnd);
    procedure SetHint(const Value: string);
    procedure SetHintColor(Value: TColor);
    procedure SetIcon(Value: TIcon);
    procedure SetShowHint(Value: Boolean);
    procedure SetTitle(const Value: string);
    procedure StartHintTimer(Value: Integer; TimerMode: TTimerMode);
    procedure StopHintTimer;
    procedure WndProc(var Message: TMessage);
    procedure UpdateVisible;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure ActivateHint(CursorPos: TPoint);
    procedure BringToFront;
    procedure ControlDestroyed(Control: TControl);
    procedure CancelHint;
    procedure CreateForm(InstanceClass: TComponentClass; var Reference);
    procedure CreateHandle;
    function ExecuteAction(Action: TBasicAction): Boolean; reintroduce;
    procedure HandleException(Sender: TObject);
    procedure HandleMessage;
    function HelpCommand(Command: Integer; Data: Longint): Boolean;
    function HelpContext(Context: THelpContext): Boolean;
    function HelpJump(const JumpID: string): Boolean;
    procedure HideHint;
    procedure HintMouseMessage(Control: TControl; var Message: TMessage);
    procedure HookMainWindow(Hook: TWindowHook);
    procedure Initialize;
    function IsRightToLeft: Boolean;
    function MessageBox(const Text, Caption: PChar; Flags: Longint): Integer;
    procedure Minimize;
    procedure NormalizeAllTopMosts;
    procedure NormalizeTopMosts;
    procedure ProcessMessages;
    procedure Restore;
    procedure RestoreTopMosts;
    procedure Run;
    procedure ShowException(E: Exception);
    procedure Terminate;
    procedure UnhookMainWindow(Hook: TWindowHook);
    function UpdateAction(Action: TBasicAction): Boolean; reintroduce;
    function UseRightToLeftAlignment: Boolean;
    function UseRightToLeftReading: Boolean;
    function UseRightToLeftScrollBar: Boolean;
    property Active: Boolean read FActive;
    property AllowTesting: Boolean read FAllowTesting write FAllowTesting;
    property CurrentHelpFile: string read GetCurrentHelpFile;
    property DialogHandle: HWnd read GetDialogHandle write SetDialogHandle;
    property ExeName: string read GetExeName;
    property Handle: HWnd read FHandle write SetHandle;
    property HelpFile: string read FHelpFile write FHelpFile;
    property Hint: string read FHint write SetHint;
    property HintColor: TColor read FHintColor write SetHintColor;
    property HintHidePause: Integer read FHintHidePause write FHintHidePause;
    property HintPause: Integer read FHintPause write FHintPause;
    property HintShortCuts: Boolean read FHintShortCuts write FHintShortCuts;
    property HintShortPause: Integer read FHintShortPause write FHintShortPause;
    property Icon: TIcon read FIcon write SetIcon;
    property MainForm: TForm read FMainForm;
    property BiDiMode: TBiDiMode read FBiDiMode
      write SetBiDiMode default bdLeftToRight;
    property BiDiKeyboard: string read FBiDiKeyboard write FBiDiKeyboard;
    property NonBiDiKeyboard: string read FNonBiDiKeyboard write FNonBiDiKeyboard;
    property ShowHint: Boolean read FShowHint write SetShowHint;
    property ShowMainForm: Boolean read FShowMainForm write FShowMainForm;
    property Terminated: Boolean read FTerminate;
    property Title: string read GetTitle write SetTitle;
    property UpdateFormatSettings: Boolean read FUpdateFormatSettings
      write FUpdateFormatSettings;
    property UpdateMetricSettings: Boolean read FUpdateMetricSettings
      write FUpdateMetricSettings;
    property OnActionExecute: TActionEvent read FOnActionExecute write FOnActionExecute;
    property OnActionUpdate: TActionEvent read FOnActionUpdate write FOnActionUpdate;
    property OnActivate: TNotifyEvent read FOnActivate write FOnActivate;
    property OnDeactivate: TNotifyEvent read FOnDeactivate write FOnDeactivate;
    property OnException: TExceptionEvent read FOnException write FOnException;
    property OnIdle: TIdleEvent read FOnIdle write FOnIdle;
    property OnHelp: THelpEvent read FOnHelp write FOnHelp;
    property OnHint: TNotifyEvent read FOnHint write FOnHint;
    property OnMessage: TMessageEvent read FOnMessage write FOnMessage;
    property OnMinimize: TNotifyEvent read FOnMinimize write FOnMinimize;
    property OnRestore: TNotifyEvent read FOnRestore write FOnRestore;
    property OnShowHint: TShowHintEvent read FOnShowHint write FOnShowHint;
    property OnShortCut: TShortCutEvent read FOnShortCut write FOnShortCut;
  end;

{ Global objects }

var
  Application: TApplication;
  Screen: TScreen;
  Ctl3DBtnWndProc: Pointer = nil;  { obsolete }
  Ctl3DDlgFramePaint: function(Window: HWnd; Msg, wParam, lParam: Longint): Longint stdcall = nil; { obsolete }
  Ctl3DCtlColorEx: function(Window: HWnd; Msg, wParam, lParam: Longint): Longint stdcall = nil; { obsolete }
  HintWindowClass: THintWindowClass = THintWindow;

function GetParentForm(Control: TControl): TCustomForm;
function ValidParentForm(Control: TControl): TCustomForm;

function DisableTaskWindows(ActiveWindow: HWnd): Pointer;
procedure EnableTaskWindows(WindowList: Pointer);

function MakeObjectInstance(Method: TWndMethod): Pointer;
procedure FreeObjectInstance(ObjectInstance: Pointer);

function IsAccel(VK: Word; const Str: string): Boolean;

function  Subclass3DWnd(Wnd: HWnd): Boolean; { obsolete }
procedure Subclass3DDlg(Wnd: HWnd; Flags: Word); { obsolete }
procedure SetAutoSubClass(Enable: Boolean); { obsolete }
function AllocateHWnd(Method: TWndMethod): HWND;
procedure DeallocateHWnd(Wnd: HWND);
procedure DoneCtl3D;  { obsolete }
procedure InitCtl3D;  { obsolete }

function KeysToShiftState(Keys: Word): TShiftState;
function KeyDataToShiftState(KeyData: Longint): TShiftState;
function KeyboardStateToShiftState(const KeyboardState: TKeyboardState): TShiftState;

function ForegroundTask: Boolean;

implementation

uses ActiveX, Math, Printers, Consts, CommCtrl, FlatSB, StdActns;

var
  FocusMessages: Boolean = True;
  FocusCount: Integer = 0;

const
  DefHintColor = clInfoBk;  { default hint window color }
  DefHintPause = 500;       { default pause before hint window displays (ms)}
  DefHintShortPause = 0;    { default reshow pause to 0, was DefHintPause div 10 }
  DefHintHidePause = DefHintPause * 5;

procedure ShowMDIClientEdge(ClientHandle: THandle; ShowEdge: Boolean);
var
  Style: Longint;
begin
  if ClientHandle <> 0 then
  begin
    Style := GetWindowLong(ClientHandle, GWL_EXSTYLE);
    if ShowEdge then
      if Style and WS_EX_CLIENTEDGE = 0 then
        Style := Style or WS_EX_CLIENTEDGE
      else
        Exit
    else if Style and WS_EX_CLIENTEDGE <> 0 then
      Style := Style and not WS_EX_CLIENTEDGE
    else
      Exit;
    SetWindowLong(ClientHandle, GWL_EXSTYLE, Style);
    SetWindowPos(ClientHandle, 0, 0,0,0,0, SWP_FRAMECHANGED or SWP_NOACTIVATE or
      SWP_NOMOVE or SWP_NOSIZE or SWP_NOZORDER);
  end;
end;

{ Task window management }

type
  PTaskWindow = ^TTaskWindow;
  TTaskWindow = record
    Next: PTaskWindow;
    Window: HWnd;
  end;

var
  TaskActiveWindow: HWnd = 0;
  TaskFirstWindow: HWnd = 0;
  TaskFirstTopMost: HWnd = 0;
  TaskWindowList: PTaskWindow = nil;

procedure DoneApplication;
begin
  with Application do
  begin
    if Handle <> 0 then ShowOwnedPopups(Handle, False);
    ShowHint := False;
    Destroying;
    DestroyComponents;
  end;
end;

function DoDisableWindow(Window: HWnd; Data: Longint): Bool; stdcall;
var
  P: PTaskWindow;
begin
  if (Window <> TaskActiveWindow) and IsWindowVisible(Window) and
    IsWindowEnabled(Window) then
  begin
    New(P);
    P^.Next := TaskWindowList;
    P^.Window := Window;
    TaskWindowList := P;
    EnableWindow(Window, False);
  end;
  Result := True;
end;

function DisableTaskWindows(ActiveWindow: HWnd): Pointer;
var
  SaveActiveWindow: HWND;
  SaveWindowList: Pointer;
begin
  Result := nil;
  SaveActiveWindow := TaskActiveWindow;
  SaveWindowList := TaskWindowList;
  TaskActiveWindow := ActiveWindow;
  TaskWindowList := nil;
  try
    try
      EnumThreadWindows(GetCurrentThreadID, @DoDisableWindow, 0);
      Result := TaskWindowList;
    except
      EnableTaskWindows(TaskWindowList);
      raise;
    end;
  finally
    TaskWindowList := SaveWindowList;
    TaskActiveWindow := SaveActiveWindow;
  end;
end;

procedure EnableTaskWindows(WindowList: Pointer);
var
  P: PTaskWindow;
begin
  while WindowList <> nil do
  begin
    P := WindowList;
    if IsWindow(P^.Window) then EnableWindow(P^.Window, True);
    WindowList := P^.Next;
    Dispose(P);
  end;
end;

function DoFindWindow(Window: HWnd; Param: Longint): Bool; stdcall;
begin
  if (Window <> TaskActiveWindow) and (Window <> Application.FHandle) and
    IsWindowVisible(Window) and IsWindowEnabled(Window) then
    if GetWindowLong(Window, GWL_EXSTYLE) and WS_EX_TOPMOST = 0 then
    begin
      if TaskFirstWindow = 0 then TaskFirstWindow := Window;
    end else
    begin
      if TaskFirstTopMost = 0 then TaskFirstTopMost := Window;
    end;
  Result := True;
end;

function FindTopMostWindow(ActiveWindow: HWnd): HWnd;
begin
  TaskActiveWindow := ActiveWindow;
  TaskFirstWindow := 0;
  TaskFirstTopMost := 0;
  EnumThreadWindows(GetCurrentThreadID, @DoFindWindow, 0);
  if TaskFirstWindow <> 0 then
    Result := TaskFirstWindow else
    Result := TaskFirstTopMost;
end;

function SendFocusMessage(Window: HWnd; Msg: Word): Boolean;
var
  Count: Integer;
begin
  Count := FocusCount;
  SendMessage(Window, Msg, 0, 0);
  Result := FocusCount = Count;
end;

{ Check if this is the active Windows task }

type
  PCheckTaskInfo = ^TCheckTaskInfo;
  TCheckTaskInfo = record
    FocusWnd: HWnd;
    Found: Boolean;
  end;

function CheckTaskWindow(Window: HWnd; Data: Longint): Bool; stdcall;
begin
  Result := True;
  if PCheckTaskInfo(Data)^.FocusWnd = Window then
  begin
    Result := False;
    PCheckTaskInfo(Data)^.Found := True;
  end;
end;

function ForegroundTask: Boolean;
var
  Info: TCheckTaskInfo;
begin
  Info.FocusWnd := GetActiveWindow;
  Info.Found := False;
  EnumThreadWindows(GetCurrentThreadID, @CheckTaskWindow, Longint(@Info));
  Result := Info.Found;
end;

function FindGlobalComponent(const Name: string): TComponent;
var
  I: Integer;
begin
  for I := 0 to Screen.FormCount - 1 do
  begin
    Result := Screen.Forms[I];
    if not (csInline in Result.ComponentState) and
      (CompareText(Name, Result.Name) = 0) then Exit;
  end;
  for I := 0 to Screen.DataModuleCount - 1 do
  begin
    Result := Screen.DataModules[I];
    if CompareText(Name, Result.Name) = 0 then Exit;
  end;
  Result := nil;
end;

{ CTL3D32.DLL support for NT 3.51 has been removed.  Ctl3D properties of
  VCL controls use extended window style flags on Win95 and later OS's.  }

procedure InitCtl3D;
begin
end;

procedure DoneCtl3D;
begin
end;

function Subclass3DWnd(Wnd: HWnd): Boolean;
begin
  Result := False;
end;

procedure Subclass3DDlg(Wnd: HWnd; Flags: Word);
begin
end;

procedure SetAutoSubClass(Enable: Boolean);
begin
end;

const
  InstanceCount = 313;

{ Object instance management }

type
  PObjectInstance = ^TObjectInstance;
  TObjectInstance = packed record
    Code: Byte;
    Offset: Integer;
    case Integer of
      0: (Next: PObjectInstance);
      1: (Method: TWndMethod);
  end;

type
  PInstanceBlock = ^TInstanceBlock;
  TInstanceBlock = packed record
    Next: PInstanceBlock;
    Code: array[1..2] of Byte;
    WndProcPtr: Pointer;
    Instances: array[0..InstanceCount] of TObjectInstance;
  end;

var
  InstBlockList: PInstanceBlock;
  InstFreeList: PObjectInstance;

{ Standard window procedure }
{ In    ECX = Address of method pointer }
{ Out   EAX = Result }

function StdWndProc(Window: HWND; Message, WParam: Longint;
  LParam: Longint): Longint; stdcall; assembler;
asm
        XOR     EAX,EAX
        PUSH    EAX
        PUSH    LParam
        PUSH    WParam
        PUSH    Message
        MOV     EDX,ESP
        MOV     EAX,[ECX].Longint[4]
        CALL    [ECX].Pointer
        ADD     ESP,12
        POP     EAX
end;

{ Allocate an object instance }

function CalcJmpOffset(Src, Dest: Pointer): Longint;
begin
  Result := Longint(Dest) - (Longint(Src) + 5);
end;

function MakeObjectInstance(Method: TWndMethod): Pointer;
const
  BlockCode: array[1..2] of Byte = (
    $59,       { POP ECX }
    $E9);      { JMP StdWndProc }
  PageSize = 4096;
var
  Block: PInstanceBlock;
  Instance: PObjectInstance;
begin
  if InstFreeList = nil then
  begin
    Block := VirtualAlloc(nil, PageSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    Block^.Next := InstBlockList;
    Move(BlockCode, Block^.Code, SizeOf(BlockCode));
    Block^.WndProcPtr := Pointer(CalcJmpOffset(@Block^.Code[2], @StdWndProc));
    Instance := @Block^.Instances;
    repeat
      Instance^.Code := $E8;  { CALL NEAR PTR Offset }
      Instance^.Offset := CalcJmpOffset(Instance, @Block^.Code);
      Instance^.Next := InstFreeList;
      InstFreeList := Instance;
      Inc(Longint(Instance), SizeOf(TObjectInstance));
    until Longint(Instance) - Longint(Block) >= SizeOf(TInstanceBlock);
    InstBlockList := Block;
  end;
  Result := InstFreeList;
  Instance := InstFreeList;
  InstFreeList := Instance^.Next;
  Instance^.Method := Method;
end;

{ Free an object instance }

procedure FreeObjectInstance(ObjectInstance: Pointer);
begin
  if ObjectInstance <> nil then
  begin
    PObjectInstance(ObjectInstance)^.Next := InstFreeList;
    InstFreeList := ObjectInstance;
  end;
end;

var
  UtilWindowClass: TWndClass = (
    style: 0;
    lpfnWndProc: @DefWindowProc;
    cbClsExtra: 0;
    cbWndExtra: 0;
    hInstance: 0;
    hIcon: 0;
    hCursor: 0;
    hbrBackground: 0;
    lpszMenuName: nil;
    lpszClassName: 'TPUtilWindow');

function AllocateHWnd(Method: TWndMethod): HWND;
var
  TempClass: TWndClass;
  ClassRegistered: Boolean;
begin
  UtilWindowClass.hInstance := HInstance;
  ClassRegistered := GetClassInfo(HInstance, UtilWindowClass.lpszClassName,
    TempClass);
  if not ClassRegistered or (TempClass.lpfnWndProc <> @DefWindowProc) then
  begin
    if ClassRegistered then
      Windows.UnregisterClass(UtilWindowClass.lpszClassName, HInstance);
    Windows.RegisterClass(UtilWindowClass);
  end;
  Result := CreateWindowEx(WS_EX_TOOLWINDOW, UtilWindowClass.lpszClassName,
    '', WS_POPUP {!0}, 0, 0, 0, 0, 0, 0, HInstance, nil);
  if Assigned(Method) then
    SetWindowLong(Result, GWL_WNDPROC, Longint(MakeObjectInstance(Method)));
end;

procedure DeallocateHWnd(Wnd: HWND);
var
  Instance: Pointer;
begin
  Instance := Pointer(GetWindowLong(Wnd, GWL_WNDPROC));
  DestroyWindow(Wnd);
  if Instance <> @DefWindowProc then FreeObjectInstance(Instance);
end;

{ Utility mapping functions }

{ Convert mouse message to TMouseButton }

function KeysToShiftState(Keys: Word): TShiftState;
begin
  Result := [];
  if Keys and MK_SHIFT <> 0 then Include(Result, ssShift);
  if Keys and MK_CONTROL <> 0 then Include(Result, ssCtrl);
  if Keys and MK_LBUTTON <> 0 then Include(Result, ssLeft);
  if Keys and MK_RBUTTON <> 0 then Include(Result, ssRight);
  if Keys and MK_MBUTTON <> 0 then Include(Result, ssMiddle);
  if GetKeyState(VK_MENU) < 0 then Include(Result, ssAlt);
end;

{ Convert keyboard message data to TShiftState }

function KeyDataToShiftState(KeyData: Longint): TShiftState;
const
  AltMask = $20000000;
begin
  Result := [];
  if GetKeyState(VK_SHIFT) < 0 then Include(Result, ssShift);
  if GetKeyState(VK_CONTROL) < 0 then Include(Result, ssCtrl);
  if KeyData and AltMask <> 0 then Include(Result, ssAlt);
end;

{ Convert GetKeyboardState output to TShiftState }

function KeyboardStateToShiftState(const KeyboardState: TKeyboardState): TShiftState;
begin
  Result := [];
  if KeyboardState[VK_SHIFT] and $80 <> 0 then Include(Result, ssShift);
  if KeyboardState[VK_CONTROL] and $80 <> 0 then Include(Result, ssCtrl);
  if KeyboardState[VK_MENU] and $80 <> 0 then Include(Result, ssAlt);
  if KeyboardState[VK_LBUTTON] and $80 <> 0 then Include(Result, ssLeft);
  if KeyboardState[VK_RBUTTON] and $80 <> 0 then Include(Result, ssRight);
  if KeyboardState[VK_MBUTTON] and $80 <> 0 then Include(Result, ssMiddle);
end;

function IsAccel(VK: Word; const Str: string): Boolean;
begin
  Result := CompareText(Char(VK), GetHotKey(Str)) = 0;
end;

{ Form utility functions }

function GetParentForm(Control: TControl): TCustomForm;
begin
  while Control.Parent <> nil do Control := Control.Parent;
  if Control is TCustomForm then
    Result := TCustomForm(Control) else
    Result := nil;
end;

function ValidParentForm(Control: TControl): TCustomForm;
begin
  Result := GetParentForm(Control);
  if Result = nil then
    raise EInvalidOperation.CreateFmt(SParentRequired, [Control.Name]);
end;

{ TControlScrollBar }

constructor TControlScrollBar.Create(AControl: TScrollingWinControl;
  AKind: TScrollBarKind);
begin
  inherited Create;
  FControl := AControl;
  FKind := AKind;
  FPageIncrement := 80;
  FIncrement := FPageIncrement div 10;
  FVisible := True;
  FDelay := 10;
  FLineDiv := 4;
  FPageDiv := 12;
  FColor := clBtnHighlight;
  FParentColor := True;
  FUpdateNeeded := True;
end;

function TControlScrollBar.IsIncrementStored: Boolean;
begin
  Result := not Smooth;
end;

procedure TControlScrollBar.Assign(Source: TPersistent);
begin
  if Source is TControlScrollBar then
  begin
    Visible := TControlScrollBar(Source).Visible;
    Range := TControlScrollBar(Source).Range;
    Position := TControlScrollBar(Source).Position;
    Increment := TControlScrollBar(Source).Increment;
    Exit;
  end;
  inherited Assign(Source);
end;

procedure TControlScrollBar.ChangeBiDiPosition;
begin
  if Kind = sbHorizontal then
    if IsScrollBarVisible then
      if not FControl.UseRightToLeftScrollBar then
        Position := 0
      else
        Position := Range;
end;

procedure TControlScrollBar.CalcAutoRange;
var
  I: Integer;
  NewRange, AlignMargin: Integer;

  procedure ProcessHorz(Control: TControl);
  begin
    if Control.Visible then
      case Control.Align of
        alLeft, alNone:
          if (Control.Align = alLeft) or (Control.Anchors * [akLeft, akRight] = [akLeft]) then
            NewRange := Max(NewRange, Position + Control.Left + Control.Width);
        alRight: Inc(AlignMargin, Control.Width);
      end;
  end;

  procedure ProcessVert(Control: TControl);
  begin
    if Control.Visible then
      case Control.Align of
        alTop, alNone:
          if (Control.Align = alTop) or (Control.Anchors * [akTop, akBottom] = [akTop]) then
            NewRange := Max(NewRange, Position + Control.Top + Control.Height);
        alBottom: Inc(AlignMargin, Control.Height);
      end;
  end;

begin
  if FControl.FAutoScroll then
  begin
    if FControl.AutoScrollEnabled then
    begin
      NewRange := 0;
      AlignMargin := 0;
      for I := 0 to FControl.ControlCount - 1 do
        if Kind = sbHorizontal then
          ProcessHorz(FControl.Controls[I]) else
          ProcessVert(FControl.Controls[I]);
      DoSetRange(NewRange + AlignMargin + Margin);
    end
    else DoSetRange(0);
  end;
end;

function TControlScrollBar.IsScrollBarVisible: Boolean;
var
  Style: Longint;
begin
  Style := WS_HSCROLL;
  if Kind = sbVertical then Style := WS_VSCROLL;
  Result := (Visible) and
            (GetWindowLong(FControl.Handle, GWL_STYLE) and Style <> 0);
end;

function TControlScrollBar.ControlSize(ControlSB, AssumeSB: Boolean): Integer;
var
  BorderAdjust: Integer;

  function ScrollBarVisible(Code: Word): Boolean;
  var
    Style: Longint;
  begin
    Style := WS_HSCROLL;
    if Code = SB_VERT then Style := WS_VSCROLL;
    Result := GetWindowLong(FControl.Handle, GWL_STYLE) and Style <> 0;
  end;

  function Adjustment(Code, Metric: Word): Integer;
  begin
    Result := 0;
    if not ControlSB then
      if AssumeSB and not ScrollBarVisible(Code) then
        Result := -(GetSystemMetrics(Metric) - BorderAdjust)
      else if not AssumeSB and ScrollBarVisible(Code) then
        Result := GetSystemMetrics(Metric) - BorderAdjust;
  end;

begin
  BorderAdjust := Integer(GetWindowLong(FControl.Handle, GWL_STYLE) and
    (WS_BORDER or WS_THICKFRAME) <> 0);
  if Kind = sbVertical then
    Result := FControl.ClientHeight + Adjustment(SB_HORZ, SM_CXHSCROLL) else
    Result := FControl.ClientWidth + Adjustment(SB_VERT, SM_CYVSCROLL);
end;

function TControlScrollBar.GetScrollPos: Integer;
begin
  Result := 0;
  if Visible then Result := Position;
end;

function TControlScrollBar.NeedsScrollBarVisible: Boolean;
begin
  Result := FRange > ControlSize(False, False);
end;

procedure TControlScrollBar.ScrollMessage(var Msg: TWMScroll);
var
  Incr, FinalIncr, Count: Integer;
  CurrentTime, StartTime, ElapsedTime: Longint;

  function GetRealScrollPosition: Integer;
  var
    SI: TScrollInfo;
    Code: Integer;
  begin
    SI.cbSize := SizeOf(TScrollInfo);
    SI.fMask := SIF_TRACKPOS;
    Code := SB_HORZ;
    if FKind = sbVertical then Code := SB_VERT;
    Result := Msg.Pos;
    if FlatSB_GetScrollInfo(FControl.Handle, Code, SI) then
      Result := SI.nTrackPos;
  end;

begin
  with Msg do
  begin
    if FSmooth and (ScrollCode in [SB_LINEUP, SB_LINEDOWN, SB_PAGEUP, SB_PAGEDOWN]) then
    begin
      case ScrollCode of
        SB_LINEUP, SB_LINEDOWN:
          begin
            Incr := FIncrement div FLineDiv;
            FinalIncr := FIncrement mod FLineDiv;
            Count := FLineDiv;
          end;
        SB_PAGEUP, SB_PAGEDOWN:
          begin
            Incr := FPageIncrement;
            FinalIncr := Incr mod FPageDiv;
            Incr := Incr div FPageDiv;
            Count := FPageDiv;
          end;
      else
        Count := 0;
        Incr := 0;
        FinalIncr := 0;
      end;
      CurrentTime := 0;
      while Count > 0 do
      begin
        StartTime := GetCurrentTime;
        ElapsedTime := StartTime - CurrentTime;
        if ElapsedTime < FDelay then Sleep(FDelay - ElapsedTime);
        CurrentTime := StartTime;
        case ScrollCode of
          SB_LINEUP: SetPosition(FPosition - Incr);
          SB_LINEDOWN: SetPosition(FPosition + Incr);
          SB_PAGEUP: SetPosition(FPosition - Incr);
          SB_PAGEDOWN: SetPosition(FPosition + Incr);
        end;
        FControl.Update;
        Dec(Count);
      end;
      if FinalIncr > 0 then
      begin
        case ScrollCode of
          SB_LINEUP: SetPosition(FPosition - FinalIncr);
          SB_LINEDOWN: SetPosition(FPosition + FinalIncr);
          SB_PAGEUP: SetPosition(FPosition - FinalIncr);
          SB_PAGEDOWN: SetPosition(FPosition + FinalIncr);
        end;
      end;
    end
    else
      case ScrollCode of
        SB_LINEUP: SetPosition(FPosition - FIncrement);
        SB_LINEDOWN: SetPosition(FPosition + FIncrement);
        SB_PAGEUP: SetPosition(FPosition - ControlSize(True, False));
        SB_PAGEDOWN: SetPosition(FPosition + ControlSize(True, False));
        SB_THUMBPOSITION:
            if FCalcRange > 32767 then
              SetPosition(GetRealScrollPosition) else
              SetPosition(Pos);
        SB_THUMBTRACK:
          if Tracking then
            if FCalcRange > 32767 then
              SetPosition(GetRealScrollPosition) else
              SetPosition(Pos);
        SB_TOP: SetPosition(0);
        SB_BOTTOM: SetPosition(FCalcRange);
        SB_ENDSCROLL: begin end;
      end;
  end;
end;

procedure TControlScrollBar.SetButtonSize(Value: Integer);
const
  SysConsts: array[TScrollBarKind] of Integer = (SM_CXHSCROLL, SM_CXVSCROLL);
var
  NewValue: Integer;
begin
  if Value <> ButtonSize then
  begin
    NewValue := Value;
    if NewValue = 0 then
      Value := GetSystemMetrics(SysConsts[Kind]);
    FButtonSize := Value;
    FUpdateNeeded := True;
    FControl.UpdateScrollBars;
    if NewValue = 0 then
      FButtonSize := 0;
  end;
end;

procedure TControlScrollBar.SetColor(Value: TColor);
begin
  if Value <> Color then
  begin
    FColor := Value;
    FParentColor := False;
    FUpdateNeeded := True;
    FControl.UpdateScrollBars;
  end;
end;

procedure TControlScrollBar.SetParentColor(Value: Boolean);
begin
  if ParentColor <> Value then
  begin
    FParentColor := Value;
    if Value then Color := clBtnHighlight;
  end;
end;

procedure TControlScrollBar.SetPosition(Value: Integer);
var
  Code: Word;
  Form: TCustomForm;
  OldPos: Integer;
begin
  if csReading in FControl.ComponentState then
    FPosition := Value
  else
  begin
    if Value > FCalcRange then Value := FCalcRange
    else if Value < 0 then Value := 0;
    if Kind = sbHorizontal then
      Code := SB_HORZ else
      Code := SB_VERT;
    if Value <> FPosition then
    begin
      OldPos := FPosition;
      FPosition := Value;
      if Kind = sbHorizontal then
        FControl.ScrollBy(OldPos - Value, 0) else
        FControl.ScrollBy(0, OldPos - Value);
      if csDesigning in FControl.ComponentState then
      begin
        Form := GetParentForm(FControl);
        if (Form <> nil) and (Form.Designer <> nil) then Form.Designer.Modified;
      end;
    end;
    if FlatSB_GetScrollPos(FControl.Handle, Code) <> FPosition then
      FlatSB_SetScrollPos(FControl.Handle, Code, FPosition, True);
  end;
end;

procedure TControlScrollBar.SetSize(Value: Integer);
const
  SysConsts: array[TScrollBarKind] of Integer = (SM_CYHSCROLL, SM_CYVSCROLL);
var
  NewValue: Integer;
begin
  if Value <> Size then
  begin
    NewValue := Value;
    if NewValue = 0 then
      Value := GetSystemMetrics(SysConsts[Kind]);
    FSize := Value;
    FUpdateNeeded := True;
    FControl.UpdateScrollBars;
    if NewValue = 0 then
      FSize := 0;
  end;
end;

procedure TControlScrollBar.SetStyle(Value: TScrollBarStyle);
begin
  if Style <> Value then
  begin
    FStyle := Value;
    FUpdateNeeded := True;
    FControl.UpdateScrollBars;
  end;
end;

procedure TControlScrollBar.SetThumbSize(Value: Integer);
begin
  if Value <> ThumbSize then
  begin
    FThumbSize := Value;
    FUpdateNeeded := True;
    FControl.UpdateScrollBars;
  end;
end;

procedure TControlScrollBar.DoSetRange(Value: Integer);
begin
  FRange := Value;
  if FRange < 0 then FRange := 0;
  FControl.UpdateScrollBars;
end;

procedure TControlScrollBar.SetRange(Value: Integer);
begin
  FControl.FAutoScroll := False;
  FScaled := True;
  DoSetRange(Value);
end;

function TControlScrollBar.IsRangeStored: Boolean;
begin
  Result := not FControl.AutoScroll;
end;

procedure TControlScrollBar.SetVisible(Value: Boolean);
begin
  FVisible := Value;
  FControl.UpdateScrollBars;
end;

procedure TControlScrollBar.Update(ControlSB, AssumeSB: Boolean);
type
  TPropKind = (pkStyle, pkButtonSize, pkThumbSize, pkSize, pkBkColor);
const
  Props: array[TScrollBarKind, TPropKind] of Integer = (
    { Horizontal }
    (WSB_PROP_HSTYLE, WSB_PROP_CXHSCROLL, WSB_PROP_CXHTHUMB, WSB_PROP_CYHSCROLL,
     WSB_PROP_HBKGCOLOR),
    { Vertical }
    (WSB_PROP_VSTYLE, WSB_PROP_CYVSCROLL, WSB_PROP_CYVTHUMB, WSB_PROP_CXVSCROLL,
     WSB_PROP_VBKGCOLOR));
  Kinds: array[TScrollBarKind] of Integer = (WSB_PROP_HSTYLE, WSB_PROP_VSTYLE);
  Styles: array[TScrollBarStyle] of Integer = (FSB_REGULAR_MODE,
    FSB_ENCARTA_MODE, FSB_FLAT_MODE);
var
  Code: Word;
  ScrollInfo: TScrollInfo;

  procedure UpdateScrollProperties(Redraw: Boolean);
  begin
    FlatSB_SetScrollProp(FControl.Handle, Props[Kind, pkStyle], Styles[Style], Redraw);
    if ButtonSize > 0 then
      FlatSB_SetScrollProp(FControl.Handle, Props[Kind, pkButtonSize], ButtonSize, False);
    if ThumbSize > 0 then
      FlatSB_SetScrollProp(FControl.Handle, Props[Kind, pkThumbSize], ThumbSize, False);
    if Size > 0 then
      FlatSB_SetScrollProp(FControl.Handle, Props[Kind, pkSize], Size, False);
    FlatSB_SetScrollProp(FControl.Handle, Props[Kind, pkBkColor],
      ColorToRGB(Color), False);
  end;

begin
  FCalcRange := 0;
  Code := SB_HORZ;
  if Kind = sbVertical then Code := SB_VERT;
  if Visible then
  begin
    FCalcRange := Range - ControlSize(ControlSB, AssumeSB);
    if FCalcRange < 0 then FCalcRange := 0;
  end;
  ScrollInfo.cbSize := SizeOf(ScrollInfo);
  ScrollInfo.fMask := SIF_ALL;
  ScrollInfo.nMin := 0;
  if FCalcRange > 0 then
    ScrollInfo.nMax := Range else
    ScrollInfo.nMax := 0;
  ScrollInfo.nPage := ControlSize(ControlSB, AssumeSB) + 1;
  ScrollInfo.nPos := FPosition;
  ScrollInfo.nTrackPos := FPosition;
//  if FUpdateNeeded then
  begin
    UpdateScrollProperties(FUpdateNeeded);
    FUpdateNeeded := False;
  end;
  FlatSB_SetScrollInfo(FControl.Handle, Code, ScrollInfo, True);
  SetPosition(FPosition);
  FPageIncrement := (ControlSize(True, False) * 9) div 10;
  if Smooth then FIncrement := FPageIncrement div 10;
end;

{ TScrollingWinControl }

constructor TScrollingWinControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FHorzScrollBar := TControlScrollBar.Create(Self, sbHorizontal);
  FVertScrollBar := TControlScrollBar.Create(Self, sbVertical);
  FAutoScroll := True;
end;

destructor TScrollingWinControl.Destroy;
begin
  FHorzScrollBar.Free;
  FVertScrollBar.Free;
  inherited Destroy;
end;

procedure TScrollingWinControl.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  with Params.WindowClass do
    style := style and not (CS_HREDRAW or CS_VREDRAW);
end;

procedure TScrollingWinControl.CreateWnd;
begin
  inherited CreateWnd;
  //! Scroll bars don't move to the Left side of a TScrollingWinControl when the
  //! WS_EX_LEFTSCROLLBAR flag is set and InitializeFlatSB is called.
  //! A call to UnInitializeFlatSB does nothing.
  if not SysLocale.MiddleEast then InitializeFlatSB(Handle);
  UpdateScrollBars;
end;

procedure TScrollingWinControl.AlignControls(AControl: TControl; var ARect: TRect);
begin
  CalcAutoRange;
  inherited AlignControls(AControl, ARect);
end;

function TScrollingWinControl.AutoScrollEnabled: Boolean;
begin
  Result := not AutoSize and not (DockSite and UseDockManager);
end;

procedure TScrollingWinControl.DoFlipChildren;
var
  Loop: Integer;
  TheWidth: Integer;
  ScrollBarActive: Boolean;
  FlippedList: TList;
begin
  FlippedList := TList.Create;
  try
    TheWidth := ClientWidth;
    with HorzScrollBar do begin
      ScrollBarActive := (IsScrollBarVisible) and (TheWidth < Range);
      if ScrollBarActive then
      begin
        TheWidth := Range;
        Position := 0;
      end;
    end;

    for Loop := 0 to ControlCount - 1 do with Controls[Loop] do
    begin
      FlippedList.Add(Controls[Loop]);
      Left := TheWidth - Width - Left;
    end;
    
    { Allow controls that have associations to realign themselves }  
    for Loop := 0 to FlippedList.Count - 1 do
      TControl(FlippedList[Loop]).Perform(CM_ALLCHILDRENFLIPPED, 0, 0);

    if ScrollBarActive then
      HorzScrollBar.ChangeBiDiPosition;
  finally
     FlippedList.Free;
  end;
end;

procedure TScrollingWinControl.CalcAutoRange;
begin
  if FAutoRangeCount <= 0 then
  begin
    HorzScrollBar.CalcAutoRange;
    VertScrollBar.CalcAutoRange;
  end;
end;

procedure TScrollingWinControl.SetAutoScroll(Value: Boolean);
begin
  if FAutoScroll <> Value then
  begin
    FAutoScroll := Value;
    if Value then CalcAutoRange else
    begin
      HorzScrollBar.Range := 0;
      VertScrollBar.Range := 0;
    end;
  end;
end;

procedure TScrollingWinControl.SetHorzScrollBar(Value: TControlScrollBar);
begin
  FHorzScrollBar.Assign(Value);
end;

procedure TScrollingWinControl.SetVertScrollBar(Value: TControlScrollBar);
begin
  FVertScrollBar.Assign(Value);
end;

procedure TScrollingWinControl.UpdateScrollBars;
begin
  if not FUpdatingScrollBars and HandleAllocated then
    try
      FUpdatingScrollBars := True;
      if FVertScrollBar.NeedsScrollBarVisible then
      begin
        FHorzScrollBar.Update(False, True);
        FVertScrollBar.Update(True, False);
      end
      else if FHorzScrollBar.NeedsScrollBarVisible then
      begin
        FVertScrollBar.Update(False, True);
        FHorzScrollBar.Update(True, False);
      end
      else
      begin
        FVertScrollBar.Update(False, False);
        FHorzScrollBar.Update(True, False);
      end;
    finally
      FUpdatingScrollBars := False;
    end;
end;

procedure TScrollingWinControl.AutoScrollInView(AControl: TControl);
begin
  if (AControl <> nil) and not (csLoading in AControl.ComponentState) and
    not (csLoading in ComponentState) then
    ScrollInView(AControl);
end;

procedure TScrollingWinControl.DisableAutoRange;
begin
  Inc(FAutoRangeCount);
end;

procedure TScrollingWinControl.EnableAutoRange;
begin
  if FAutoRangeCount > 0 then
  begin
    Dec(FAutoRangeCount);
    if (FAutoRangeCount = 0) and (FHorzScrollBar.Visible or
      FVertScrollBar.Visible) then CalcAutoRange;
  end;
end;

procedure TScrollingWinControl.ScrollInView(AControl: TControl);
var
  Rect: TRect;
begin
  if AControl = nil then Exit;
  Rect := AControl.ClientRect;
  Dec(Rect.Left, HorzScrollBar.Margin);
  Inc(Rect.Right, HorzScrollBar.Margin);
  Dec(Rect.Top, VertScrollBar.Margin);
  Inc(Rect.Bottom, VertScrollBar.Margin);
  Rect.TopLeft := ScreenToClient(AControl.ClientToScreen(Rect.TopLeft));
  Rect.BottomRight := ScreenToClient(AControl.ClientToScreen(Rect.BottomRight));
  if Rect.Left < 0 then
    with HorzScrollBar do Position := Position + Rect.Left
  else if Rect.Right > ClientWidth then
  begin
    if Rect.Right - Rect.Left > ClientWidth then
      Rect.Right := Rect.Left + ClientWidth;
    with HorzScrollBar do Position := Position + Rect.Right - ClientWidth;
  end;
  if Rect.Top < 0 then
    with VertScrollBar do Position := Position + Rect.Top
  else if Rect.Bottom > ClientHeight then
  begin
    if Rect.Bottom - Rect.Top > ClientHeight then
      Rect.Bottom := Rect.Top + ClientHeight;
    with VertScrollBar do Position := Position + Rect.Bottom - ClientHeight;
  end;
end;

procedure TScrollingWinControl.ScaleScrollBars(M, D: Integer);
begin
  if M <> D then
  begin
    if not (csLoading in ComponentState) then
    begin
      HorzScrollBar.FScaled := True;
      VertScrollBar.FScaled := True;
    end;
    HorzScrollBar.Position := 0;
    VertScrollBar.Position := 0;
    if not FAutoScroll then
    begin
      with HorzScrollBar do if FScaled then Range := MulDiv(Range, M, D);
      with VertScrollBar do if FScaled then Range := MulDiv(Range, M, D);
    end;
  end;
  HorzScrollBar.FScaled := False;
  VertScrollBar.FScaled := False;
end;

procedure TScrollingWinControl.ChangeScale(M, D: Integer);
begin
  ScaleScrollBars(M, D);
  inherited ChangeScale(M, D);
end;

procedure TScrollingWinControl.Resizing(State: TWindowState);
begin
  // Overridden by TCustomFrame
end;

procedure TScrollingWinControl.WMSize(var Message: TWMSize);
var
  NewState: TWindowState;
begin
  Inc(FAutoRangeCount);
  try
    inherited;
    NewState := wsNormal;
    case Message.SizeType of
      SIZENORMAL: NewState := wsNormal;
      SIZEICONIC: NewState := wsMinimized;
      SIZEFULLSCREEN: NewState := wsMaximized;
    end;
    Resizing(NewState);
  finally
    Dec(FAutoRangeCount);
  end;
  FUpdatingScrollBars := True;
  try
    CalcAutoRange;
  finally
    FUpdatingScrollBars := False;
  end;
  if FHorzScrollBar.Visible or FVertScrollBar.Visible then
    UpdateScrollBars;
end;

procedure TScrollingWinControl.WMHScroll(var Message: TWMHScroll);
begin
  if (Message.ScrollBar = 0) and FHorzScrollBar.Visible then
    FHorzScrollBar.ScrollMessage(Message) else
    inherited;
end;

procedure TScrollingWinControl.WMVScroll(var Message: TWMVScroll);
begin
  if (Message.ScrollBar = 0) and FVertScrollBar.Visible then
    FVertScrollBar.ScrollMessage(Message) else
    inherited;
end;

procedure TScrollingWinControl.AdjustClientRect(var Rect: TRect);
begin
  Rect := Bounds(-HorzScrollBar.Position, -VertScrollBar.Position,
    Max(HorzScrollBar.Range, ClientWidth), Max(ClientHeight,
    VertScrollBar.Range));
  inherited AdjustClientRect(Rect);
end;

procedure TScrollingWinControl.CMBiDiModeChanged(var Message: TMessage);
var
  Save: Integer;
begin
  Save := Message.WParam;
  try
    { prevent inherited from calling Invalidate & RecreateWnd }
    if not (Self is TScrollBox) then Message.wParam := 1;
    inherited;
  finally
    Message.wParam := Save;
  end;
  if HandleAllocated then
  begin
    HorzScrollBar.ChangeBiDiPosition;
    UpdateScrollBars;
  end;
end;

{ TScrollBox }

constructor TScrollBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csAcceptsControls, csCaptureMouse, csClickEvents,
    csSetCaption, csDoubleClicks];
  Width := 185;
  Height := 41;
  FBorderStyle := bsSingle;
end;

procedure TScrollBox.CreateParams(var Params: TCreateParams);
const
  BorderStyles: array[TBorderStyle] of DWORD = (0, WS_BORDER);
begin
  inherited CreateParams(Params);
  with Params do
  begin
    Style := Style or BorderStyles[FBorderStyle];
    if NewStyleControls and Ctl3D and (FBorderStyle = bsSingle) then
    begin
      Style := Style and not WS_BORDER;
      ExStyle := ExStyle or WS_EX_CLIENTEDGE;
    end;
  end;
end;

procedure TScrollBox.SetBorderStyle(Value: TBorderStyle);
begin
  if Value <> FBorderStyle then
  begin
    FBorderStyle := Value;
    RecreateWnd;
  end;
end;

procedure TScrollBox.WMNCHitTest(var Message: TMessage);
begin
  DefaultHandler(Message);
end;

procedure TScrollBox.CMCtl3DChanged(var Message: TMessage);
begin
  if NewStyleControls and (FBorderStyle = bsSingle) then RecreateWnd;
  inherited;
end;

{ TCustomFrame }

constructor TCustomFrame.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csAcceptsControls, csCaptureMouse, csClickEvents,
    csSetCaption, csDoubleClicks];
  if (ClassType <> TFrame) and not (csDesignInstance in ComponentState) then
  begin
    if not InitInheritedComponent(Self, TFrame) then
      raise EResNotFound.CreateFmt(SResNotFound, [ClassName]);
  end
  else
  begin
    Width := 320;
    Height := 240;
  end;
end;

procedure TCustomFrame.CreateParams(var Params: TCreateParams);
begin
  inherited;
  if Parent = nil then
    Params.WndParent := Application.Handle;
end;

procedure TCustomFrame.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
  OwnedComponent: TComponent;
begin
  inherited GetChildren(Proc, Root);
  if Root = Self then
    for I := 0 to ComponentCount - 1 do
    begin
      OwnedComponent := Components[I];
      if not OwnedComponent.HasParent then Proc(OwnedComponent);
    end;
end;

procedure TCustomFrame.AddActionList(ActionList: TCustomActionList);
var
  Form: TCustomForm;
begin
  Form := GetParentForm(Self);
  if Form <> nil then
  begin
    if Form.FActionLists = nil then Form.FActionLists := TList.Create;
    Form.FActionLists.Add(ActionList);
  end;
end;

procedure TCustomFrame.RemoveActionList(ActionList: TCustomActionList);
var
  Form: TCustomForm;
begin
  Form := GetParentForm(Self);
  if (Form <> nil) and (Form.FActionLists <> nil) then
    Form.FActionLists.Remove(ActionList);
end;

procedure TCustomFrame.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  case Operation of
    opInsert:
      if AComponent is TCustomActionList then
        AddActionList(TCustomActionList(AComponent));
    opRemove:
      if AComponent is TCustomActionList then
        RemoveActionList(TCustomActionList(AComponent));
  end;
end;

procedure TCustomFrame.SetParent(AParent: TWinControl);

  procedure UpdateActionLists(Operation: TOperation);
  var
    I: Integer;
    Component: TComponent;
  begin
    for I := 0 to ComponentCount - 1 do
    begin
      Component := Components[I];
      if Component is TCustomActionList then
        case Operation of
          opInsert: AddActionList(TCustomActionList(Component));
          opRemove: RemoveActionList(TCustomActionList(Component));
        end;
    end;
  end;

begin
  if Parent <> nil then UpdateActionLists(opRemove);
  if (Parent = nil) and HandleAllocated then
    DestroyHandle;
  inherited;
  if Parent <> nil then UpdateActionLists(opInsert);
end;

{ TCustomActiveForm }

constructor TCustomActiveForm.Create(AOwner: TComponent);
begin
  FAxBorderStyle := afbSingle;
  inherited Create(AOwner);
  BorderStyle := bsNone;
  BorderIcons := [];
  TabStop := True;
end;

procedure TCustomActiveForm.SetAxBorderStyle(Value: TActiveFormBorderStyle);
begin
  if FAxBorderStyle <> Value then
  begin
    FAxBorderStyle := Value;
    if not (csDesigning in ComponentState) then RecreateWnd;
  end;
end;

procedure TCustomActiveForm.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  if not (csDesigning in ComponentState) then
    with Params do
    begin
      Style := Style and not WS_CAPTION;
      case FAxBorderStyle of
        afbNone: ;// do nothing
        afbSingle: Style := Style or WS_BORDER;
        afbSunken: ExStyle := ExStyle or WS_EX_CLIENTEDGE;
        afbRaised:
          begin
            Style := Style or WS_DLGFRAME;
            ExStyle := ExStyle or WS_EX_WINDOWEDGE;
          end;
      end;
    end;
end;

function TCustomActiveForm.WantChildKey(Child: TControl; var Message: TMessage): Boolean;
begin
  Result := ((Message.Msg = WM_CHAR) and (Message.WParam = VK_TAB)) or
    (Child.Perform(CN_BASE + Message.Msg, Message.WParam,
      Message.LParam) <> 0);
end;

{ TCustomForm }

constructor TCustomForm.Create(AOwner: TComponent);
begin
  GlobalNameSpace.BeginWrite;
  try
    CreateNew(AOwner);
    if (ClassType <> TForm) and not (csDesigning in ComponentState) then
    begin
      Include(FFormState, fsCreating);
      try
        if not InitInheritedComponent(Self, TForm) then
          raise EResNotFound.CreateFmt(SResNotFound, [ClassName]);
      finally
        Exclude(FFormState, fsCreating);
      end;
      if OldCreateOrder then DoCreate;
    end;
  finally
    GlobalNameSpace.EndWrite;
  end;
end;

procedure TCustomForm.AfterConstruction;
begin
  if not OldCreateOrder then DoCreate;
  if fsActivated in FFormState then
  begin
    Activate;
    Exclude(FFormState, fsActivated);
  end;
end;

constructor TCustomForm.CreateNew(AOwner: TComponent; Dummy: Integer);
begin
  inherited Create(AOwner);
  ControlStyle := [csAcceptsControls, csCaptureMouse, csClickEvents,
    csSetCaption, csDoubleClicks];
  Left := 0;
  Top := 0;
  Width := 320;
  Height := 240;
  Visible := False;
  ParentColor := False;
  ParentFont := False;
  Ctl3D := True;
  FBorderIcons := [biSystemMenu, biMinimize, biMaximize];
  FBorderStyle := bsSizeable;
  FWindowState := wsNormal;
  FDefaultMonitor := dmActiveForm;
  FIcon := TIcon.Create;
  FIcon.Width := GetSystemMetrics(SM_CXSMICON);
  FIcon.Height := GetSystemMetrics(SM_CYSMICON);
  FIcon.OnChange := IconChanged;
  FInCMParentBiDiModeChanged := False;
  FCanvas := TControlCanvas.Create;
  FCanvas.Control := Self;
  FPixelsPerInch := Screen.PixelsPerInch;
  FPrintScale := poProportional;
  FloatingDockSiteClass := TWinControlClass(ClassType);
  Screen.AddForm(Self);
end;

procedure TCustomForm.BeforeDestruction;
begin
  GlobalNameSpace.BeginWrite;
  Destroying;
  Screen.FSaveFocusedList.Remove(Self);
  RemoveFixupReferences(Self, '');
  if FOleForm <> nil then FOleForm.OnDestroy;
  if FormStyle <> fsMDIChild then Hide;
  if not OldCreateOrder then DoDestroy;
end;

destructor TCustomForm.Destroy;
begin
  if not (csDestroying in ComponentState) then GlobalNameSpace.BeginWrite;
  try
    if OldCreateOrder then DoDestroy;
    MergeMenu(False);
    if HandleAllocated then DestroyWindowHandle;
    Screen.RemoveForm(Self);
    FCanvas.Free;
    FIcon.Free;
    FreeAndNil(FActionLists);
    inherited Destroy;
  finally
    GlobalNameSpace.EndWrite;
  end;
end;

procedure TCustomForm.DoCreate;
begin
  if Assigned(FOnCreate) then
  try
    FOnCreate(Self);
  except
    Application.HandleException(Self);
  end;
  if fsVisible in FFormState then Visible := True;
end;

procedure TCustomForm.DoDestroy;
begin
  if Assigned(FOnDestroy) then
  try
    FOnDestroy(Self);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomForm.Loaded;
var
  Control: TWinControl;
begin
  inherited Loaded;
  if ActiveControl <> nil then
  begin
    Control := ActiveControl;
    FActiveControl := nil;
    if Control.CanFocus then SetActiveControl(Control);
  end;
end;

procedure TCustomForm.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  case Operation of
    opInsert:
      begin
        if AComponent is TCustomActionList then
        begin
          if FActionLists = nil then FActionLists := TList.Create;
          FActionLists.Add(AComponent);
        end
        else if not (csLoading in ComponentState) and (Menu = nil) and
          (AComponent.Owner = Self) and (AComponent is TMainMenu) then
          Menu := TMainMenu(AComponent);
      end;
    opRemove:
      begin
        if (FActionLists <> nil) and (AComponent is TCustomActionList) then
          FActionLists.Remove(AComponent)
        else
        begin
          if Menu = AComponent then Menu := nil;
          if WindowMenu = AComponent then WindowMenu := nil;
          if ObjectMenuItem = AComponent then ObjectMenuItem := nil;
        end;
      end;
  end;
  if FDesigner <> nil then
    FDesigner.Notification(AComponent, Operation);
end;

procedure TCustomForm.ReadState(Reader: TReader);
var
  NewTextHeight: Integer;
  Scaled: Boolean;
begin
  DisableAlign;
  try
    FClientWidth := 0;
    FClientHeight := 0;
    FTextHeight := 0;
    Scaled := False;
    FOldCreateOrder := not ModuleIsCpp;
    inherited ReadState(Reader);
    if (FPixelsPerInch <> 0) and (FTextHeight > 0) then
    begin
      if (sfFont in ScalingFlags) and (FPixelsPerInch <> Screen.PixelsPerInch) then
        Font.Height := MulDiv(Font.Height, Screen.PixelsPerInch, FPixelsPerInch);
      FPixelsPerInch := Screen.PixelsPerInch;
      NewTextHeight := GetTextHeight;
      if FTextHeight <> NewTextHeight then
      begin
        Scaled := True;
        ScaleScrollBars(NewTextHeight, FTextHeight);
        ScaleControls(NewTextHeight, FTextHeight);
        if sfWidth in ScalingFlags then
          FClientWidth := MulDiv(FClientWidth, NewTextHeight, FTextHeight);
        if sfHeight in ScalingFlags then
          FClientHeight := MulDiv(FClientHeight, NewTextHeight, FTextHeight);
      end;
    end;
    if FClientWidth > 0 then inherited ClientWidth := FClientWidth;
    if FClientHeight > 0 then inherited ClientHeight := FClientHeight;
    ScalingFlags := [];
    if not Scaled then
    begin
      { Forces all ScalingFlags to [] }
      ScaleScrollBars(1, 1);
      ScaleControls(1, 1);
    end;
    Perform(CM_PARENTBIDIMODECHANGED, 0, 0);
  finally
    EnableAlign;
  end;
end;

procedure TCustomForm.DefineProperties(Filer: TFiler);
begin
  inherited DefineProperties(Filer);
  Filer.DefineProperty('PixelsPerInch', nil, WritePixelsPerInch, not IsControl);
  Filer.DefineProperty('TextHeight', ReadTextHeight, WriteTextHeight, not IsControl);
  Filer.DefineProperty('IgnoreFontProperty', ReadIgnoreFontProperty, nil, False);
end;

procedure TCustomForm.ReadIgnoreFontProperty(Reader: TReader);
begin   // reroute BCB IgnoreFontProperty to use VCL locale font solution
  if Reader.ReadBoolean then
    ParentFont := True;
end;

procedure TCustomForm.ReadTextHeight(Reader: TReader);
begin
  FTextHeight := Reader.ReadInteger;
end;

procedure TCustomForm.WriteTextHeight(Writer: TWriter);
begin
  Writer.WriteInteger(GetTextHeight);
end;

procedure TCustomForm.WritePixelsPerInch(Writer: TWriter);
begin
  Writer.WriteInteger(GetPixelsPerInch);
end;

function TCustomForm.GetTextHeight: Integer;
begin
  Result := Canvas.TextHeight('0');
end;

procedure TCustomForm.BeginAutoDrag;
begin
  { Do nothing }
end;

procedure TCustomForm.ChangeScale(M, D: Integer);
var
  PriorHeight: Integer;
begin
  ScaleScrollBars(M, D);
  ScaleControls(M, D);
  if IsClientSizeStored then
  begin
    PriorHeight := ClientHeight;
    ClientWidth := MulDiv(ClientWidth, M, D);
    ClientHeight := MulDiv(PriorHeight, M, D);
  end;
  Font.Size := MulDiv(Font.Size, M, D);
end;

procedure TCustomForm.IconChanged(Sender: TObject);
begin
  if NewStyleControls then
  begin
    if HandleAllocated and (BorderStyle <> bsDialog) then
      SendMessage(Handle, WM_SETICON, 1, GetIconHandle);
  end else
    if IsIconic(Handle) then Invalidate;
end;

function TCustomForm.IsClientSizeStored: Boolean;
begin
  Result := not IsFormSizeStored;
end;

function TCustomForm.IsFormSizeStored: Boolean;
begin
  Result := AutoScroll or (HorzScrollBar.Range <> 0) or
    (VertScrollBar.Range <> 0);
end;

function TCustomForm.IsAutoScrollStored: Boolean;
begin
  Result := IsForm and
    (AutoScroll <> (BorderStyle in [bsSizeable, bsSizeToolWin]));
end;

procedure TCustomForm.DoClose(var Action: TCloseAction);
begin
  if Assigned(FOnClose) then FOnClose(Self, Action);
end;

procedure TCustomForm.DoHide;
begin
  if Assigned(FOnHide) then FOnHide(Self);
end;

procedure TCustomForm.DoShow;
begin
  if Assigned(FOnShow) then FOnShow(Self);
end;

function TCustomForm.GetClientRect: TRect;
begin
  if IsIconic(Handle) then
  begin
    SetRect(Result, 0, 0, 0, 0);
    AdjustWindowRectEx(Result, GetWindowLong(Handle, GWL_STYLE),
      Menu <> nil, GetWindowLong(Handle, GWL_EXSTYLE));
    SetRect(Result, 0, 0,
      Width - Result.Right + Result.Left,
      Height - Result.Bottom + Result.Top);
  end else
    Result := inherited GetClientRect;
end;

procedure TCustomForm.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
  OwnedComponent: TComponent;
begin
  inherited GetChildren(Proc, Root);
  if Root = Self then
    for I := 0 to ComponentCount - 1 do
    begin
      OwnedComponent := Components[I];
      if not OwnedComponent.HasParent then Proc(OwnedComponent);
    end;
end;

function TCustomForm.GetFloating: Boolean;
begin
  Result := (HostDockSite = nil) and (FloatingDockSiteClass = ClassType);
end;

procedure TCustomForm.SetChildOrder(Child: TComponent; Order: Integer);
var
  I, J: Integer;
begin
  if Child is TControl then
    inherited SetChildOrder(Child, Order)
  else
  begin
    Dec(Order, ControlCount);
    J := -1;
    for I := 0 to ComponentCount - 1 do
      if not Components[I].HasParent then
      begin
        Inc(J);
        if J = Order then
        begin
          Child.ComponentIndex := I;
          Exit;
        end;
      end;
  end;
end;

procedure TCustomForm.SetParentBiDiMode(Value: Boolean);
begin
  if ParentBiDiMode <> Value then
  begin
    inherited;
    { if there is no parent, then the parent is Application }
    if Parent = nil then
      Perform(CM_PARENTBIDIMODECHANGED, 0, 0);
  end;  
end;

procedure TCustomForm.SetClientWidth(Value: Integer);
begin
  if csReadingState in ControlState then
  begin
    FClientWidth := Value;
    ScalingFlags := ScalingFlags + [sfWidth];
  end else inherited ClientWidth := Value;
end;

procedure TCustomForm.SetClientHeight(Value: Integer);
begin
  if csReadingState in ControlState then
  begin
    FClientHeight := Value;
    ScalingFlags := ScalingFlags + [sfHeight];
  end else inherited ClientHeight := Value;
end;

procedure TCustomForm.SetVisible(Value: Boolean);
begin
  if fsCreating in FFormState then
    if Value then
      Include(FFormState, fsVisible) else
      Exclude(FFormState, fsVisible)
  else
  begin
    if Value and (Visible <> Value) then SetWindowToMonitor;
    inherited Visible := Value;
  end;
end;

procedure TCustomForm.VisibleChanging;
begin
  if (FormStyle = fsMDIChild) and Visible then
    raise EInvalidOperation.Create(SMDIChildNotVisible);
end;

function TCustomForm.WantChildKey(Child: TControl; var Message: TMessage): Boolean;
begin
  Result := False;
end;

procedure TCustomForm.SetParent(AParent: TWinControl);
begin
  if (Parent <> AParent) and (AParent <> Self) then
  begin
    if Parent = nil then DestroyHandle;
    inherited SetParent(AParent);
    if Parent = nil then UpdateControlState;
  end;
end;

procedure TCustomForm.ValidateRename(AComponent: TComponent;
  const CurName, NewName: string);
begin
  inherited ValidateRename(AComponent, CurName, NewName);
  if FDesigner <> nil then
    FDesigner.ValidateRename(AComponent, CurName, NewName);
end;

type
  TMenuItemAccess = class(TMenuItem);

procedure TCustomForm.WndProc(var Message: TMessage);
var
  FocusHandle: HWND;
  SaveIndex: Integer;
  MenuItem: TMenuItem;
  Canvas: TCanvas;
  DC: HDC;
begin
  with Message do
    case Msg of
      WM_ACTIVATE, WM_SETFOCUS, WM_KILLFOCUS:
        begin
          if not FocusMessages then Exit;
          if (Msg = WM_SETFOCUS) and not (csDesigning in ComponentState) then
          begin
            FocusHandle := 0;
            if FormStyle = fsMDIForm then
            begin
              if ActiveMDIChild <> nil then FocusHandle := ActiveMDIChild.Handle;
            end
            else if (FActiveControl <> nil) and (FActiveControl <> Self) then
              FocusHandle := FActiveControl.Handle;
            if FocusHandle <> 0 then
            begin
              Windows.SetFocus(FocusHandle);
              Exit;
            end;
          end;
        end;
      CM_EXIT:
        if HostDockSite <> nil then DeActivate;
      CM_ENTER:
        if HostDockSite <> nil then Activate;
      WM_WINDOWPOSCHANGING:
        if ([csLoading, csDesigning] * ComponentState = [csLoading]) then
        begin
          if (Position in [poDefault, poDefaultPosOnly]) and
            (WindowState <> wsMaximized) then
            with PWindowPos(Message.lParam)^ do flags := flags or SWP_NOMOVE;
          if (Position in [poDefault, poDefaultSizeOnly]) and
            (BorderStyle in [bsSizeable, bsSizeToolWin]) then
            with PWindowPos(Message.lParam)^ do flags := flags or SWP_NOSIZE;
        end;
      WM_DRAWITEM:
        with PDrawItemStruct(Message.LParam)^ do
          if (CtlType = ODT_MENU) and Assigned(Menu) then
          begin
            MenuItem := Menu.FindItem(itemID, fkCommand);
            if MenuItem <> nil then
            begin
              Canvas := TControlCanvas.Create;
              with Canvas do
              try
                SaveIndex := SaveDC(hDC);
                try
                  Handle := hDC;
                  Font := Screen.MenuFont;
                  Menus.DrawMenuItem(MenuItem, Canvas, rcItem,
                    TOwnerDrawState(LongRec(itemState).Lo));
                finally
                  Handle := 0;
                  RestoreDC(hDC, SaveIndex)
                end;
              finally
                Free;
              end;
              Exit;
            end;
          end;
      WM_MEASUREITEM:
        with PMeasureItemStruct(Message.LParam)^ do
          if (CtlType = ODT_MENU) and Assigned(Menu) then
          begin
            MenuItem := Menu.FindItem(itemID, fkCommand);
            if MenuItem <> nil then
            begin
              DC := GetWindowDC(Handle);
              try
                Canvas := TControlCanvas.Create;
                with Canvas do
                try
                  SaveIndex := SaveDC(DC);
                  try
                    Handle := DC;
                    Font := Screen.MenuFont;
                    TMenuItemAccess(MenuItem).MeasureItem(Canvas,
                      Integer(itemWidth), Integer(itemHeight));
                  finally
                    Handle := 0;
                    RestoreDC(DC, SaveIndex);
                  end;
                finally
                  Canvas.Free;
                end;
              finally
                ReleaseDC(Handle, DC);
              end;
              Exit;
            end;
          end;
    end;
  inherited WndProc(Message);
end;

procedure TCustomForm.ClientWndProc(var Message: TMessage);

  procedure Default;
  begin
    with Message do
      Result := CallWindowProc(FDefClientProc, ClientHandle, Msg, wParam, lParam);
  end;

  function MaximizedChildren: Boolean;
  var
    I: Integer;
  begin
    for I := 0 to MDIChildCount - 1 do
      if MDIChildren[I].WindowState = wsMaximized then
      begin
        Result := True;
        Exit;
      end;
    Result := False;
  end;

begin
  with Message do
    case Msg of
      WM_NCHITTEST:
        begin
          Default;
          if Result = HTCLIENT then Result := HTTRANSPARENT;
        end;
      WM_ERASEBKGND:
        begin
          FillRect(TWMEraseBkGnd(Message).DC, ClientRect, Brush.Handle);
          Result := 1;
        end;
      $3F://!
        begin
          Default;
          if FFormStyle = fsMDIForm then
            ShowMDIClientEdge(FClientHandle, (MDIChildCount = 0) or
            not MaximizedChildren);
        end;
    else
      Default;
    end;
end;

procedure TCustomForm.AlignControls(AControl: TControl; var Rect: TRect);
begin
  inherited AlignControls(AControl, Rect);
  if ClientHandle <> 0 then
    with Rect do
      SetWindowPos(FClientHandle, HWND_BOTTOM, Left, Top, Right - Left,
        Bottom - Top, SWP_NOZORDER + SWP_NOACTIVATE);
end;

procedure TCustomForm.CMBiDiModeChanged(var Message: TMessage);
var
  ExStyle: DWORD;
  Loop: Integer;
begin
  inherited;
  { inherited does not call RecreateWnd, so we need to call SetWindowLong }
  if HandleAllocated then
  begin
    ExStyle := DWORD(GetWindowLong(Handle, GWL_EXSTYLE))and (not WS_EX_RIGHT) and
      (not WS_EX_RTLREADING) and (not WS_EX_LEFTSCROLLBAR);
    AddBiDiModeExStyle(ExStyle);
    SetWindowLong(Handle, GWL_EXSTYLE, ExStyle);
  end;
  { Menus derive from TComponent, so we need to update them here. We cannot
    use FMenu because forms can have many menus. }
  for Loop := 0 to ComponentCount - 1 do
    if Components[Loop] is TMenu then
      TMenu(Components[Loop]).ParentBiDiModeChanged;
end;

procedure TCustomForm.CMParentBiDiModeChanged(var Message: TMessage);
begin
  { Prevent needless recursion }
  if FInCMParentBiDiModeChanged then Exit;
  FInCMParentBiDiModeChanged := True;
  try
    if ParentBiDiMode then
    begin
      { if there is no parent, then the parent is Application }
      if Parent = nil then
        BiDiMode := Application.BiDiMode
      else
        BiDiMode := Parent.BiDiMode;
      ParentBiDiMode := True;
    end;
  finally
    FInCMParentBiDiModeChanged := False;
  end;
end;

procedure TCustomForm.SetDesigner(ADesigner: IDesigner);
begin
  FDesigner := ADesigner;
end;

procedure TCustomForm.SetBorderIcons(Value: TBorderIcons);
begin
  if FBorderIcons <> Value then
  begin
    FBorderIcons := Value;
    if not (csDesigning in ComponentState) then RecreateWnd;
  end;
end;

procedure TCustomForm.SetBorderStyle(Value: TFormBorderStyle);
begin
  if FBorderStyle <> Value then
  begin
    FBorderStyle := Value;
    AutoScroll := FBorderStyle in [bsSizeable, bsSizeToolWin];
    if not (csDesigning in ComponentState) then RecreateWnd;
  end;
end;

procedure TCustomForm.Dock(NewDockSite: TWinControl; ARect: TRect);
var
  PrevDockSite, PrevParent: TWinControl;
begin
  PrevParent := Parent;
  PrevDockSite := HostDockSite;
  inherited Dock(NewDockSite, ARect);
  if (Parent <> nil) and (Parent = PrevParent) and
    (PrevDockSite <> HostDockSite) then RecreateWnd;
end;

procedure TCustomForm.DoDock(NewDockSite: TWinControl; var ARect: TRect);
begin
  if (NewDockSite <> HostDockSite) and
    ((NewDockSite = nil) or Floating) then
    if NewDockSite = nil then
      FBorderStyle := FSavedBorderStyle
    else begin
      FSavedBorderStyle := BorderStyle;
      FBorderStyle := bsNone;
    end;
  inherited DoDock(NewDockSite, ARect);
end;

function TCustomForm.GetActiveMDIChild: TForm;
begin
  Result := nil;
  if (FormStyle = fsMDIForm) and (FClientHandle <> 0) then
    Result := TForm(FindControl(SendMessage(FClientHandle, WM_MDIGETACTIVE, 0,
      0)));
end;

function TCustomForm.GetMDIChildCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  if (FormStyle = fsMDIForm) and (FClientHandle <> 0) then
    for I := 0 to Screen.FormCount - 1 do
      if Screen.Forms[I].FormStyle = fsMDIChild then Inc(Result);
end;

function TCustomForm.GetMDIChildren(I: Integer): TForm;
var
  J: Integer;
begin
  if (FormStyle = fsMDIForm) and (FClientHandle <> 0) then
    for J := 0 to Screen.FormCount - 1 do
    begin
      Result := Screen.Forms[J];
      if Result.FormStyle = fsMDIChild then
      begin
        Dec(I);
        if I < 0 then Exit;
      end;
    end;
  Result := nil;
end;

function EnumMonitorsProc(hm: HMONITOR; dc: HDC; r: PRect; Data: Pointer): Boolean; stdcall;
var
  L: TList;
  M: TMonitor;
begin
  L := TList(Data);
  M := TMonitor.Create;
  M.FHandle := hm;
  M.FMonitorNum := L.Count;
  L.Add(M);
  Result := True;
end;

function TCustomForm.GetMonitor: TMonitor;
var
  HM: HMonitor;
  I: Integer;
begin
  Result := nil;
  HM := MonitorFromWindow(Handle, MONITOR_DEFAULTTONEAREST);
  for I := 0 to Screen.MonitorCount - 1 do
    if Screen.Monitors[I].Handle = HM then
    begin
      Result := Screen.Monitors[I];
      Exit;
    end;

  //if we get here, the Monitors array has changed, so we need to clear and reinitialize it
  for i := 0 to Screen.MonitorCount-1 do
    TMonitor(Screen.FMonitors[i]).Free;
  Screen.FMonitors.Clear;
  EnumDisplayMonitors(0, nil, @EnumMonitorsProc, LongInt(Screen.FMonitors));
  for I := 0 to Screen.MonitorCount - 1 do
    if Screen.Monitors[I].Handle = HM then
    begin
      Result := Screen.Monitors[I];
      Exit;
    end;    
end;

function TCustomForm.GetCanvas: TCanvas;
begin
  Result := FCanvas;
end;

procedure TCustomForm.SetIcon(Value: TIcon);
begin
  FIcon.Assign(Value);
end;

function TCustomForm.IsForm: Boolean;
begin
  Result := not IsControl;
end;

function TCustomForm.IsIconStored: Boolean;
begin
  Result := IsForm and (Icon.Handle <> 0);
end;

procedure TCustomForm.SetFormStyle(Value: TFormStyle);
var
  OldStyle: TFormStyle;
begin
  if FFormStyle <> Value then
  begin
    if (Value = fsMDIChild) and (Position = poDesigned) then
      Position := poDefault;
    if not (csDesigning in ComponentState) then DestroyHandle;
    OldStyle := FFormStyle;
    FFormStyle := Value;
    if ((Value = fsMDIForm) or (OldStyle = fsMDIForm)) and not Ctl3d then
      Color := NormalColor;
    if not (csDesigning in ComponentState) then UpdateControlState;
    if Value = fsMDIChild then Visible := True;
  end;
end;

procedure TCustomForm.RefreshMDIMenu;
var
  MenuHandle, WindowMenuHandle: HMenu;
  Redraw: Boolean;
begin
  if (FormStyle = fsMDIForm) and (ClientHandle <> 0) then
  begin
    MenuHandle := 0;
    if Menu <> nil then MenuHandle := Menu.Handle;
    WindowMenuHandle := 0;
    if WindowMenu <> nil then WindowMenuHandle := WindowMenu.Handle;
    Redraw := Windows.GetMenu(Handle) <> MenuHandle;
    SendMessage(ClientHandle, WM_MDISETMENU, MenuHandle, WindowMenuHandle);
    if Redraw then DrawMenuBar(Handle);
  end;
end;

procedure TCustomForm.SetObjectMenuItem(Value: TMenuItem);
begin
  FObjectMenuItem := Value;
  if Value <> nil then
  begin
    Value.FreeNotification(Self);
    Value.Enabled := False;
  end;
end;

procedure TCustomForm.SetWindowMenu(Value: TMenuItem);
begin
  if FWindowMenu <> Value then
  begin
    FWindowMenu := Value;
    if Value <> nil then Value.FreeNotification(Self);
    RefreshMDIMenu;
  end;
end;

procedure TCustomForm.SetMenu(Value: TMainMenu);
var
  I: Integer;
begin
  if Value <> nil then
    for I := 0 to Screen.FormCount - 1 do
      if (Screen.Forms[I].Menu = Value) and (Screen.Forms[I] <> Self) then
        raise EInvalidOperation.CreateFmt(sDuplicateMenus, [Value.Name]);
  if FMenu <> nil then FMenu.WindowHandle := 0;
  FMenu := Value;
  if Value <> nil then Value.FreeNotification(Self);
  if (Value <> nil) and ((csDesigning in ComponentState) or
   (BorderStyle <> bsDialog)) then
  begin
    if not (Menu.AutoMerge or (FormStyle = fsMDIChild)) or
      (csDesigning in ComponentState) then
    begin
      if HandleAllocated then
      begin
        if Windows.GetMenu(Handle) <> Menu.Handle then
          Windows.SetMenu(Handle, Menu.Handle);
        Value.WindowHandle := Handle;
      end;
    end
    else if FormStyle <> fsMDIChild then
      if HandleAllocated then Windows.SetMenu(Handle, 0);
  end
  else if HandleAllocated then Windows.SetMenu(Handle, 0);
  if Active then MergeMenu(True);
  RefreshMDIMenu;
end;

function TCustomForm.GetPixelsPerInch: Integer;
begin
  Result := FPixelsPerInch;
  if Result = 0 then Result := Screen.PixelsPerInch;
end;

procedure TCustomForm.SetPixelsPerInch(Value: Integer);
begin
  if (Value <> GetPixelsPerInch) and ((Value = 0) or (Value >= 36))
    and (not (csLoading in ComponentState) or (FPixelsPerInch <> 0)) then
    FPixelsPerInch := Value;
end;

procedure TCustomForm.SetPosition(Value: TPosition);
begin
  if FPosition <> Value then
  begin
    FPosition := Value;
    if not (csDesigning in ComponentState) then RecreateWnd;
  end;
end;

function TCustomForm.GetScaled: Boolean;
begin
  Result := FPixelsPerInch <> 0;
end;

procedure TCustomForm.SetScaled(Value: Boolean);
begin
  if Value <> GetScaled then
  begin
    FPixelsPerInch := 0;
    if Value then FPixelsPerInch := Screen.PixelsPerInch;
  end;
end;

procedure TCustomForm.CMColorChanged(var Message: TMessage);
begin
  inherited;
  if FCanvas <> nil then FCanvas.Brush.Color := Color;
end;

function TCustomForm.NormalColor: TColor;
begin
  Result := clWindow;
  if FormStyle = fsMDIForm then Result := clAppWorkSpace;
end;

procedure TCustomForm.CMCtl3DChanged(var Message: TMessage);
begin
  inherited;
  if Ctl3D then
  begin
     if Color = NormalColor then Color := clBtnFace
  end
  else if Color = clBtnFace then Color := NormalColor;
end;

procedure TCustomForm.CMFontChanged(var Message: TMessage);
begin
  inherited;
  if FCanvas <> nil then FCanvas.Font := Font;
end;

procedure TCustomForm.CMMenuChanged(var Message: TMessage);
begin
  RefreshMDIMenu;
  SetMenu(FMenu);
end;

procedure TCustomForm.SetWindowState(Value: TWindowState);
const
  ShowCommands: array[TWindowState] of Integer =
    (SW_SHOWNORMAL, SW_MINIMIZE, SW_SHOWMAXIMIZED);
begin
  if FWindowState <> Value then
  begin
    FWindowState := Value;
    if not (csDesigning in ComponentState) and Showing then
      ShowWindow(Handle, ShowCommands[Value]);
  end;
end;

procedure TCustomForm.SetWindowToMonitor;
var
  AppMon, WinMon: HMONITOR;
  I, J: Integer;
  ALeft, ATop: Integer;
begin
    if (FDefaultMonitor <> dmDesktop) and (Application.MainForm <> nil) then
    begin
      AppMon := 0;
      if FDefaultMonitor = dmMainForm then
        AppMon := Application.MainForm.Monitor.Handle
      else if (FDefaultMonitor = dmActiveForm) and (Screen.ActiveCustomForm <> nil) then
        AppMon := Screen.ActiveCustomForm.Monitor.Handle
      else if FDefaultMonitor = dmPrimary then
        AppMon := Screen.Monitors[0].Handle;
      WinMon := Monitor.Handle;
      for I := 0 to Screen.MonitorCount - 1 do
        if (Screen.Monitors[I].Handle = AppMon) then
          if (AppMon <> WinMon) then
            for J := 0 to Screen.MonitorCount - 1 do
              if (Screen.Monitors[J].Handle = WinMon) then
              begin
                if FPosition = poScreenCenter then
                  SetBounds(Screen.Monitors[I].Left + ((Screen.Monitors[I].Width - Width) div 2),
                    Screen.Monitors[I].Top + ((Screen.Monitors[I].Height - Height) div 2),
                     Width, Height)
                else
                if FPosition = poMainFormCenter then
                begin
                  SetBounds(Screen.Monitors[I].Left + ((Screen.Monitors[I].Width - Width) div 2),
                    Screen.Monitors[I].Top + ((Screen.Monitors[I].Height - Height) div 2),
                     Width, Height)
                end
                else
                begin
                  ALeft := Screen.Monitors[I].Left + Left - Screen.Monitors[J].Left;
                  if ALeft + Width > Screen.Monitors[I].Left + Screen.Monitors[I].Width then
                    ALeft := Screen.Monitors[I].Left + Screen.Monitors[I].Width - Width;
                  ATop := Screen.Monitors[I].Top + Top - Screen.Monitors[J].Top;
                  if ATop + Height > Screen.Monitors[I].Top + Screen.Monitors[I].Height then
                    ATop := Screen.Monitors[I].Top + Screen.Monitors[I].Height - Height;
                  SetBounds(ALeft, ATop, Width, Height);
                end;
              end;
    end;
end;

procedure TCustomForm.CreateParams(var Params: TCreateParams);
var
  Icons: TBorderIcons;
  CreateStyle: TFormBorderStyle;
begin
  inherited CreateParams(Params);
  with Params do
  begin
    if (Parent = nil) and (ParentWindow = 0) then
    begin
      WndParent := Application.Handle;
      Style := Style and not (WS_CHILD or WS_GROUP or WS_TABSTOP);
    end;
    WindowClass.style := CS_DBLCLKS;
    if (csDesigning in ComponentState) and (Parent = nil) then
      Style := Style or (WS_CAPTION or WS_THICKFRAME or WS_MINIMIZEBOX or
        WS_MAXIMIZEBOX or WS_SYSMENU)
    else
    begin
      if FPosition in [poDefault, poDefaultPosOnly] then
      begin
        X := Integer(CW_USEDEFAULT);
        Y := Integer(CW_USEDEFAULT);
      end;
      Icons := FBorderIcons;
      CreateStyle := FBorderStyle;
      if (FormStyle = fsMDIChild) and (CreateStyle in [bsNone, bsDialog]) then
        CreateStyle := bsSizeable;
      case CreateStyle of
        bsNone:
          begin
            if (Parent = nil) and (ParentWindow = 0) then
              Style := Style or WS_POPUP;
            Icons := [];
          end;
        bsSingle, bsToolWindow:
          Style := Style or (WS_CAPTION or WS_BORDER);
        bsSizeable, bsSizeToolWin:
          begin
            Style := Style or (WS_CAPTION or WS_THICKFRAME);
            if FPosition in [poDefault, poDefaultSizeOnly] then
            begin
              Width := Integer(CW_USEDEFAULT);
              Height := Integer(CW_USEDEFAULT);
            end;
          end;
        bsDialog:
          begin
            Style := Style or WS_POPUP or WS_CAPTION;
            ExStyle := WS_EX_DLGMODALFRAME or WS_EX_WINDOWEDGE;
            AddBiDiModeExStyle(ExStyle);
            if not NewStyleControls then
              Style := Style or WS_DLGFRAME or DS_MODALFRAME;
            Icons := Icons * [biSystemMenu, biHelp];
            WindowClass.style := CS_DBLCLKS or CS_SAVEBITS or
              CS_BYTEALIGNWINDOW;
          end;
      end;
      if CreateStyle in [bsToolWindow, bsSizeToolWin] then
      begin
        ExStyle := WS_EX_TOOLWINDOW;
        AddBiDiModeExStyle(ExStyle);
        Icons := Icons * [biSystemMenu];
      end;
      if CreateStyle in [bsSingle, bsSizeable, bsNone] then
      begin
        if (FormStyle <> fsMDIChild) or (biSystemMenu in Icons) then
        begin
          if biMinimize in Icons then Style := Style or WS_MINIMIZEBOX;
          if biMaximize in Icons then Style := Style or WS_MAXIMIZEBOX;
        end;
        if FWindowState = wsMinimized then Style := Style or WS_MINIMIZE else
          if FWindowState = wsMaximized then Style := Style or WS_MAXIMIZE;
      end else FWindowState := wsNormal;
      if biSystemMenu in Icons then Style := Style or WS_SYSMENU;
      if (biHelp in Icons) then ExStyle := ExStyle or WS_EX_CONTEXTHELP;
      if csInline in ComponentState then
        Style := Style and not WS_CAPTION;
      if FormStyle = fsMDIChild then WindowClass.lpfnWndProc := @DefMDIChildProc;
    end;
  end;
end;

procedure TCustomForm.CreateWnd;
var
  ClientCreateStruct: TClientCreateStruct;
begin
  inherited CreateWnd;
  if NewStyleControls then
    if BorderStyle <> bsDialog then
      SendMessage(Handle, WM_SETICON, 1, GetIconHandle) else
      SendMessage(Handle, WM_SETICON, 1, 0);
  if not (csDesigning in ComponentState) then
    case FormStyle of
      fsMDIForm:
        begin
          with ClientCreateStruct do
          begin
            idFirstChild := $FF00;
            hWindowMenu := 0;
            if FWindowMenu <> nil then hWindowMenu := FWindowMenu.Handle;
          end;
          FClientHandle := Windows.CreateWindowEx(WS_EX_CLIENTEDGE, 'MDICLIENT',
            nil, WS_CHILD or WS_VISIBLE or WS_GROUP or WS_TABSTOP or
            WS_CLIPCHILDREN or WS_HSCROLL or WS_VSCROLL or WS_CLIPSIBLINGS or
            MDIS_ALLCHILDSTYLES, 0, 0, ClientWidth, ClientHeight, Handle, 0,
            HInstance, @ClientCreateStruct);
          FClientInstance := MakeObjectInstance(ClientWndProc);
          FDefClientProc := Pointer(GetWindowLong(FClientHandle, GWL_WNDPROC));
          SetWindowLong(FClientHandle, GWL_WNDPROC, Longint(FClientInstance));
        end;
      fsStayOnTop:
        SetWindowPos(Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE or
          SWP_NOSIZE or SWP_NOACTIVATE);
    end;
end;

procedure TCustomForm.CreateWindowHandle(const Params: TCreateParams);
var
  CreateStruct: TMDICreateStruct;
begin
  if (FormStyle = fsMDIChild) and not (csDesigning in ComponentState) then
  begin
    if (Application.MainForm = nil) or
      (Application.MainForm.ClientHandle = 0) then
      raise EInvalidOperation.Create(SNoMDIForm);
    with CreateStruct do
    begin
      szClass := Params.WinClassName;
      szTitle := Params.Caption;
      hOwner := HInstance;
      X := Params.X;
      Y := Params.Y;
      cX := Params.Width;
      cY := Params.Height;
      style := Params.Style;
      lParam := Longint(Params.Param);
    end;
    WindowHandle := SendMessage(Application.MainForm.ClientHandle,
      WM_MDICREATE, 0, Longint(@CreateStruct));
    Include(FFormState, fsCreatedMDIChild);
  end else
  begin
    inherited CreateWindowHandle(Params);
    Exclude(FFormState, fsCreatedMDIChild);
  end;
end;

procedure TCustomForm.DestroyWindowHandle;
begin
  if fsCreatedMDIChild in FFormState then
    SendMessage(Application.MainForm.ClientHandle, WM_MDIDESTROY, Handle, 0)
  else
    inherited DestroyWindowHandle;
  FClientHandle := 0;
end;

procedure TCustomForm.DefaultHandler(var Message);
begin
  if ClientHandle <> 0 then
    with TMessage(Message) do
      if Msg = WM_SIZE then
        Result := DefWindowProc(Handle, Msg, wParam, lParam) else
        Result := DefFrameProc(Handle, ClientHandle, Msg, wParam, lParam)
  else
    inherited DefaultHandler(Message)
end;

procedure TCustomForm.SetActiveControl(Control: TWinControl);
begin
  if FActiveControl <> Control then
  begin
    if not ((Control = nil) or (Control <> Self) and
      (GetParentForm(Control) = Self) and ((csLoading in ComponentState) or
        Control.CanFocus)) then
      raise EInvalidOperation.Create(SCannotFocus);
    FActiveControl := Control;
    if not (csLoading in ComponentState) then
    begin
      if FActive then SetWindowFocus;
      ActiveChanged;
    end;
  end;
end;

procedure TCustomForm.DefocusControl(Control: TWinControl; Removing: Boolean);
begin
  if Removing and Control.ContainsControl(FFocusedControl) then
    FFocusedControl := Control.Parent;
  if Control.ContainsControl(FActiveControl) then SetActiveControl(nil);
end;

procedure TCustomForm.FocusControl(Control: TWinControl);
var
  WasActive: Boolean;
begin
  WasActive := FActive;
  SetActiveControl(Control);
  if not WasActive then SetFocus;
end;

function TCustomForm.SetFocusedControl(Control: TWinControl): Boolean;
var
  FocusHandle: HWnd;
  TempControl: TWinControl;
begin
  Result := False;
  Inc(FocusCount);
  if FDesigner = nil then
    if Control <> Self then
      FActiveControl := Control else
      FActiveControl := nil;
  Screen.FActiveControl := Control;
  Screen.FActiveCustomForm := Self;
  Screen.FCustomForms.Remove(Self);
  Screen.FCustomForms.Insert(0, Self);
  if Self is TForm then
  begin
    Screen.FActiveForm := TForm(Self);
    Screen.FForms.Remove(Self);
    Screen.FForms.Insert(0, Self);
  end
  else Screen.FActiveForm := nil;
  if not (csFocusing in Control.ControlState) then
  begin
    Control.ControlState := Control.ControlState + [csFocusing];
    try
      if Screen.FFocusedForm <> Self then
      begin
        if Screen.FFocusedForm <> nil then
        begin
          FocusHandle := Screen.FFocusedForm.Handle;
          Screen.FFocusedForm := nil;
          if not SendFocusMessage(FocusHandle, CM_DEACTIVATE) then Exit;
        end;
        Screen.FFocusedForm := Self;
        if not SendFocusMessage(Handle, CM_ACTIVATE) then Exit;
      end;
      if FFocusedControl = nil then FFocusedControl := Self;
      if FFocusedControl <> Control then
      begin
        while (FFocusedControl <> nil) and not
          FFocusedControl.ContainsControl(Control) do
        begin
          FocusHandle := FFocusedControl.Handle;
          FFocusedControl := FFocusedControl.Parent;
          if not SendFocusMessage(FocusHandle, CM_EXIT) then Exit;
        end;
        while FFocusedControl <> Control do
        begin
          TempControl := Control;
          while TempControl.Parent <> FFocusedControl do
            TempControl := TempControl.Parent;
          FFocusedControl := TempControl;
          if not SendFocusMessage(TempControl.Handle, CM_ENTER) then Exit;
        end;
        TempControl := Control.Parent;
        while TempControl <> nil do
        begin
          if TempControl is TScrollingWinControl then
            TScrollingWinControl(TempControl).AutoScrollInView(Control);
          TempControl := TempControl.Parent;
        end;
        Perform(CM_FOCUSCHANGED, 0, Longint(Control));
        if (FActiveOleControl <> nil) and (FActiveOleControl <> Control) then
          FActiveOleControl.Perform(CM_UIDEACTIVATE, 0, 0);
      end;
    finally
      Control.ControlState := Control.ControlState - [csFocusing];
    end;
    Screen.UpdateLastActive;
    Result := True;
  end;
end;

procedure TCustomForm.ActiveChanged;
begin
end;

procedure TCustomForm.SetWindowFocus;
var
  FocusControl: TWinControl;
begin
  if (FActiveControl <> nil) and (FDesigner = nil) then
    FocusControl := FActiveControl else
    FocusControl := Self;
  Windows.SetFocus(FocusControl.Handle);
  if GetFocus = FocusControl.Handle then
    FocusControl.Perform(CM_UIACTIVATE, 0, 0);
end;

procedure TCustomForm.SetActive(Value: Boolean);
begin
  FActive := Value;
  if FActiveOleControl <> nil then
    FActiveOleControl.Perform(CM_DOCWINDOWACTIVATE, Ord(Value), 0);
  if Value then
  begin
    if (ActiveControl = nil) and not (csDesigning in ComponentState) then
      ActiveControl := FindNextControl(nil, True, True, False);
    MergeMenu(True);
    SetWindowFocus;
  end;
end;

procedure TCustomForm.SendCancelMode(Sender: TControl);
begin
  if Active and (ActiveControl <> nil) then
    ActiveControl.Perform(CM_CANCELMODE, 0, Longint(Sender));
  if (FormStyle = fsMDIForm) and (ActiveMDIChild <> nil) then
    ActiveMDIChild.SendCancelMode(Sender);
end;

procedure TCustomForm.MergeMenu(MergeState: Boolean);
var
  AMergeMenu: TMainMenu;
begin
  if not (fsModal in FFormState) and
    (Application.MainForm <> nil) and
    (Application.MainForm.Menu <> nil) and
    (Application.MainForm <> Self) and
    ((FormStyle = fsMDIChild) or (Application.MainForm.FormStyle <> fsMDIForm)) then
  begin
    AMergeMenu := nil;
    if not (csDesigning in ComponentState) and (Menu <> nil) and
      (Menu.AutoMerge or (FormStyle = fsMDIChild)) then AMergeMenu := Menu;
    with Application.MainForm.Menu do
      if MergeState then Merge(AMergeMenu) else Unmerge(AMergeMenu);
  end;
end;

procedure DoNestedActivation(Msg: Cardinal; Control: TWinControl; Form: TCustomForm);
begin
  if Control = nil then Exit;
  { Find the closest parent which is a form }
  while (Control.Parent <> nil) and not (Control is TCustomForm) do
    Control := Control.Parent;
  if Assigned(Control) and (Control <> Form) then
    SendMessage(Control.Handle, Msg, 0, 0)
end;

procedure TCustomForm.Activate;
begin
  DoNestedActivation(CM_ACTIVATE, ActiveControl, Self);
  if Assigned(FOnActivate) then FOnActivate(Self);
end;

procedure TCustomForm.Deactivate;
begin
  DoNestedActivation(CM_DEACTIVATE, ActiveControl, Self);
  if Assigned(FOnDeactivate) then FOnDeactivate(Self);
end;

procedure TCustomForm.Paint;
begin
  if Assigned(FOnPaint) then FOnPaint(Self);
end;

function TCustomForm.GetIconHandle: HICON;
begin
  Result := FIcon.Handle;
  if Result = 0 then Result := Application.GetIconHandle;
end;

procedure TCustomForm.PaintWindow(DC: HDC);
begin
  FCanvas.Lock;
  try
    FCanvas.Handle := DC;
    try
      if FDesigner <> nil then FDesigner.PaintGrid else Paint;
    finally
      FCanvas.Handle := 0;
    end;
  finally
    FCanvas.Unlock;
  end;
end;

function TCustomForm.PaletteChanged(Foreground: Boolean): Boolean;
var
  I: Integer;
  Active, Child: TForm;
begin
  Result := False;
  Active := ActiveMDIChild;
  if Assigned(Active) then
    Result := Active.PaletteChanged(Foreground);
  for I := 0 to MDIChildCount-1 do
  begin
    if Foreground and Result then Exit;
    Child := MDIChildren[I];
    if Active = Child then Continue;
    Result := Child.PaletteChanged(Foreground) or Result;
  end;
  if Foreground and Result then Exit;
  Result := inherited PaletteChanged(Foreground);
end;

procedure TCustomForm.WMPaint(var Message: TWMPaint);
var
  DC: HDC;
  PS: TPaintStruct;
begin
  if not IsIconic(Handle) then
  begin
    ControlState := ControlState + [csCustomPaint];
    inherited;
    ControlState := ControlState - [csCustomPaint];
  end
  else
  begin
    DC := BeginPaint(Handle, PS);
    DrawIcon(DC, 0, 0, GetIconHandle);
    EndPaint(Handle, PS);
  end;
end;

procedure TCustomForm.WMIconEraseBkgnd(var Message: TWMIconEraseBkgnd);
begin
  if FormStyle = fsMDIChild then
  if (FormStyle = fsMDIChild) and not (csDesigning in ComponentState) then
    FillRect(Message.DC, ClientRect, Application.MainForm.Brush.Handle)
  else inherited;
end;

procedure TCustomForm.WMEraseBkgnd(var Message: TWMEraseBkgnd);
begin
  if not IsIconic(Handle) then inherited else
  begin
    Message.Msg := WM_ICONERASEBKGND;
    DefaultHandler(Message);
  end;
end;

procedure TCustomForm.WMQueryDragIcon(var Message: TWMQueryDragIcon);
begin
  Message.Result := GetIconHandle;
end;

procedure TCustomForm.WMNCCreate(var Message: TWMNCCreate);

  procedure ModifySystemMenu;
  var
    SysMenu: HMENU;
  begin
    if (FBorderStyle <> bsNone) and (biSystemMenu in FBorderIcons) and
      (FormStyle <> fsMDIChild) then
    begin
      { Modify the system menu to look more like it's s'pose to }
      SysMenu := GetSystemMenu(Handle, False);
      if FBorderStyle = bsDialog then
      begin
        { Make the system menu look like a dialog which has only
          Move and Close }
        DeleteMenu(SysMenu, SC_TASKLIST, MF_BYCOMMAND);
        DeleteMenu(SysMenu, 7, MF_BYPOSITION);
        DeleteMenu(SysMenu, 5, MF_BYPOSITION);
        DeleteMenu(SysMenu, SC_MAXIMIZE, MF_BYCOMMAND);
        DeleteMenu(SysMenu, SC_MINIMIZE, MF_BYCOMMAND);
        DeleteMenu(SysMenu, SC_SIZE, MF_BYCOMMAND);
        DeleteMenu(SysMenu, SC_RESTORE, MF_BYCOMMAND);
      end else
      begin
        { Else just disable the Minimize and Maximize items if the
          corresponding FBorderIcon is not present }
        if not (biMinimize in FBorderIcons) then
          EnableMenuItem(SysMenu, SC_MINIMIZE, MF_BYCOMMAND or MF_GRAYED);
        if not (biMaximize in FBorderIcons) then
          EnableMenuItem(SysMenu, SC_MAXIMIZE, MF_BYCOMMAND or MF_GRAYED);
      end;
    end;
  end;

begin
  inherited;
  SetMenu(FMenu);
  if not (csDesigning in ComponentState) then ModifySystemMenu;
end;

procedure TCustomForm.WMNCLButtonDown(var Message: TWMNCLButtonDown);
begin
  if (Message.HitTest = HTCAPTION) and (DragKind = dkDock) and not
    (csDesigning in ComponentState) and not IsIconic(Handle) then
  begin
    { Activate window since we override WM_NCLBUTTON behavior }
    SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_NOZORDER or SWP_NOMOVE or
      SWP_NOSIZE);
    PostMessage(Handle, WM_NCLBUTTONUP, TMessage(Message).WParam,
      TMessage(Message).LParam);
    if Active then BeginDrag(not Floating);
  end
  else
    inherited;
end;

procedure TCustomForm.WMDestroy(var Message: TWMDestroy);
begin
  if NewStyleControls then SendMessage(Handle, WM_SETICON, 1, 0);
  if (FMenu <> nil) and (FormStyle <> fsMDIChild) then
  begin
    Windows.SetMenu(Handle, 0);
    FMenu.WindowHandle := 0;
  end;
  inherited;
end;

procedure TCustomForm.WMCommand(var Message: TWMCommand);
begin
  with Message do
    if (Ctl <> 0) or (Menu = nil) or not Menu.DispatchCommand(ItemID) then
      inherited;
end;

procedure TCustomForm.WMInitMenuPopup(var Message: TWMInitMenuPopup);
begin
  if FMenu <> nil then FMenu.DispatchPopup(Message.MenuPopup);
end;

procedure TCustomForm.WMMenuChar(var Message: TWMMenuChar);
begin
  if (Menu <> nil) then
  begin
    Menu.ProcessMenuChar(Message);
    if Message.Result = MNC_IGNORE then
      // if we don't know what to do with it, give the default handler a try
      // Specifically, this covers odd MDI system hotkeys, like Alt+Minus
      inherited;
  end
  else
    inherited;
end;

procedure TCustomForm.WMMenuSelect(var Message: TWMMenuSelect);
var
  MenuItem: TMenuItem;
  ID: Integer;
  FindKind: TFindItemKind;
begin
  if FMenu <> nil then
    with Message do
    begin
      MenuItem := nil;
      if (MenuFlag <> $FFFF) or (IDItem <> 0) then
      begin
        FindKind := fkCommand;
        ID := IDItem;
        if MenuFlag and MF_POPUP <> 0 then
        begin
          FindKind := fkHandle;
          ID := GetSubMenu(Menu, ID);
        end;
        MenuItem := FMenu.FindItem(ID, FindKind);
      end;
      if MenuItem <> nil then
        Application.Hint := GetLongHint(MenuItem.Hint) else
        Application.Hint := '';
    end;
end;

procedure TCustomForm.WMActivate(var Message: TWMActivate);
begin
  if (FormStyle <> fsMDIForm) or (csDesigning in ComponentState) then
    SetActive(Message.Active <> WA_INACTIVE);
end;

procedure TCustomForm.Resizing(State: TWindowState);
begin
  if not (csDesigning in ComponentState) then
    FWindowState := State;
  if State <> wsMinimized then
    RequestAlign;
  if FOleForm <> nil then FOleForm.OnResize;
end;

procedure TCustomForm.WMClose(var Message: TWMClose);
begin
  Close;
end;

procedure TCustomForm.WMQueryEndSession(var Message: TWMQueryEndSession);
begin
  Message.Result := Integer(CloseQuery and CallTerminateProcs);
end;

procedure TCustomForm.CMAppSysCommand(var Message: TMessage);
type
  PWMSysCommand = ^TWMSysCommand;
begin
  Message.Result := 0;
  if (csDesigning in ComponentState) or (FormStyle = fsMDIChild) or
   (Menu = nil) or Menu.AutoMerge then
    with PWMSysCommand(Message.lParam)^ do
    begin
      SendCancelMode(nil);
      if SendAppMessage(CM_APPSYSCOMMAND, CmdType, Key) <> 0 then
        Message.Result := 1;;
    end;
end;

procedure TCustomForm.WMSysCommand(var Message: TWMSysCommand);
begin
  with Message do
  begin
    if (CmdType and $FFF0 = SC_MINIMIZE) and (Application.MainForm = Self) then
      Application.WndProc(TMessage(Message))
    else if (CmdType and $FFF0 <> SC_MOVE) or (csDesigning in ComponentState) or
      (Align = alNone) or (WindowState = wsMinimized) then
      inherited;
    if ((CmdType and $FFF0 = SC_MINIMIZE) or (CmdType and $FFF0 = SC_RESTORE)) and
      not (csDesigning in ComponentState) and (Align <> alNone) then
      RequestAlign;
  end;
end;

procedure TCustomForm.WMShowWindow(var Message: TWMShowWindow);
const
  ShowCommands: array[saRestore..saMaximize] of Integer =
    (SW_SHOWNOACTIVATE, SW_SHOWMINNOACTIVE, SW_SHOWMAXIMIZED);
begin
  with Message do
    case Status of
      SW_PARENTCLOSING:
        begin
          if IsIconic(Handle) then FShowAction := saMinimize else
            if IsZoomed(Handle) then FShowAction := saMaximize else
              FShowAction := saRestore;
          inherited;
        end;
      SW_PARENTOPENING:
        if FShowAction <> saIgnore then
        begin
          ShowWindow(Handle, ShowCommands[FShowAction]);
          FShowAction := saIgnore;
        end;
    else
      inherited;
    end;
end;

procedure TCustomForm.WMMDIActivate(var Message: TWMMDIActivate);
var
  IsActive: Boolean;
begin
  inherited;
  if FormStyle = fsMDIChild then
  begin
    IsActive := Message.ActiveWnd = Handle;
    SetActive(IsActive);
    if IsActive and (csPalette in Application.MainForm.ControlState) then
      Application.MainForm.PaletteChanged(True);
  end;
end;

procedure TCustomForm.WMNextDlgCtl(var Message: TWMNextDlgCtl);
begin
  with Message do
    if Handle then
      Windows.SetFocus(Message.CtlFocus) else
      SelectNext(FActiveControl, not BOOL(CtlFocus), True);
end;

procedure TCustomForm.WMEnterMenuLoop(var Message: TMessage);
begin
  SendCancelMode(nil);
  inherited;
end;

procedure TCustomForm.WMHelp(var Message: TWMHelp);

  function GetMenuHelpContext(Menu: TMenu): Integer;
  begin
    Result := 0;
    if Menu = nil then Exit;
    Result := Menu.GetHelpContext(Message.HelpInfo.iCtrlID, True);
    if Result = 0 then
      Result := Menu.GetHelpContext(Message.HelpInfo.hItemHandle, False);
  end;

var
  Control: TWinControl;
  ContextID: Integer;
  Pt: TSmallPoint;
begin
  if csDesigning in ComponentState then
    inherited
  else
  begin
    with Message.HelpInfo^ do
    begin
      if iContextType = HELPINFO_WINDOW then
      begin
        Control := FindControl(hItemHandle);
        while (Control <> nil) and (Control.HelpContext = 0) do
          Control := Control.Parent;
        if Control = nil then Exit;
        ContextID := Control.HelpContext;
        Pt := PointToSmallPoint(Control.ClientToScreen(Point(0, 0)));
      end
      else
      begin
        ContextID := GetMenuHelpContext(FMenu);
        if ContextID = 0 then
          ContextID := GetMenuHelpContext(PopupMenu);
        Pt := PointToSmallPoint(ClientToScreen(Point(0,0)));
      end;
    end;
    if (biHelp in BorderIcons) then
    begin
      Application.HelpCommand(HELP_SETPOPUP_POS, Longint(Pt));
      Application.HelpCommand(HELP_CONTEXTPOPUP, ContextID);
    end
    else
      Application.HelpContext(ContextID);
  end;
end;

procedure TCustomForm.WMGetMinMaxInfo(var Message: TWMGetMinMaxInfo);
begin
  if not (csReading in ComponentState) and FSizeChanging then
    with Message.MinMaxInfo^, Constraints do
    begin
      with ptMinTrackSize do
      begin
        if MinWidth > 0 then X := MinWidth;
        if MinHeight > 0 then Y := MinHeight;
      end;
      with ptMaxTrackSize do
      begin
        if MaxWidth > 0 then X := MaxWidth;
        if MaxHeight > 0 then Y := MaxHeight;
      end;
      ConstrainedResize(ptMinTrackSize.X, ptMinTrackSize.Y, ptMaxTrackSize.X,
        ptMaxTrackSize.Y);
    end;
  inherited;
end;

procedure TCustomForm.WMWindowPosChanging(var Message: TWMWindowPosChanging);
begin
  with Message.WindowPos^ do
    FSizeChanging := (ComponentState * [csReading, csDestroying] = []) and
      (flags and SWP_NOSIZE = 0) and ((cx <> Width) or (cy <> Height));
  try
    inherited;
  finally
    FSizeChanging := False;
  end;
end;

procedure TCustomForm.CMActivate(var Message: TCMActivate);
begin
  if not (csReading in ComponentState) then
    Activate else
    Include(FFormState, fsActivated);
end;

procedure TCustomForm.CMDeactivate(var Message: TCMDeactivate);
begin
  if not (csReading in ComponentState) then
    Deactivate else
    Exclude(FFormState, fsActivated);
end;

procedure TCustomForm.CMDialogKey(var Message: TCMDialogKey);
begin
  if GetKeyState(VK_MENU) >= 0 then
    with Message do
      case CharCode of
        VK_TAB:
          if GetKeyState(VK_CONTROL) >= 0 then
          begin
            SelectNext(FActiveControl, GetKeyState(VK_SHIFT) >= 0, True);
            Result := 1;
            Exit;
          end;
        VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN:
          begin
            if FActiveControl <> nil then
            begin
              TForm(FActiveControl.Parent).SelectNext(FActiveControl,
                (CharCode = VK_RIGHT) or (CharCode = VK_DOWN), False);
              Result := 1;
            end;
            Exit;
          end;
      end;
  inherited;
end;

procedure TCustomForm.CMShowingChanged(var Message: TMessage);
const
  ShowCommands: array[TWindowState] of Integer =
    (SW_SHOWNORMAL, SW_SHOWMINNOACTIVE, SW_SHOWMAXIMIZED);
var
  X, Y: Integer;
  NewActiveWindow: HWnd;
  CenterForm: TCustomForm;
begin
  if not (csDesigning in ComponentState) and (fsShowing in FFormState) then
    raise EInvalidOperation.Create(SVisibleChanged);
  Application.UpdateVisible;
  Include(FFormState, fsShowing);
  try
    if not (csDesigning in ComponentState) then
      if Showing then
      begin
        try
          DoShow;
        except
          Application.HandleException(Self);
        end;
        if (FPosition = poScreenCenter) or
           ((FPosition = poMainFormCenter) and (FormStyle = fsMDIChild)) then
        begin
          if FormStyle = fsMDIChild then
          begin
            X := (Application.MainForm.ClientWidth - Width) div 2;
            Y := (Application.MainForm.ClientHeight - Height) div 2;
          end else
          begin
            X := (Screen.Width - Width) div 2;
            Y := (Screen.Height - Height) div 2;
          end;
          if X < 0 then X := 0;
          if Y < 0 then Y := 0;
          SetBounds(X, Y, Width, Height);
          if Visible then SetWindowToMonitor;
        end
        else if FPosition in [poMainFormCenter, poOwnerFormCenter] then
        begin
          CenterForm := Application.MainForm;
          if (FPosition = poOwnerFormCenter) and (Owner is TCustomForm) then
            CenterForm := TCustomForm(Owner);
          if Assigned(CenterForm) then
          begin
            X := ((CenterForm.Width - Width) div 2) + CenterForm.Left;
            Y := ((CenterForm.Height - Height) div 2) + CenterForm.Top;
          end else
          begin
            X := (Screen.Width - Width) div 2;
            Y := (Screen.Height - Height) div 2;
          end;
          if X < 0 then X := 0;
          if Y < 0 then Y := 0;
          SetBounds(X, Y, Width, Height);
          if Visible then SetWindowToMonitor;
        end
        else if FPosition = poDesktopCenter then
        begin
          if FormStyle = fsMDIChild then
          begin
            X := (Application.MainForm.ClientWidth - Width) div 2;
            Y := (Application.MainForm.ClientHeight - Height) div 2;
          end else
          begin
            X := (Screen.DesktopWidth - Width) div 2;
            Y := (Screen.DesktopHeight - Height) div 2;
          end;
          if X < 0 then X := 0;
          if Y < 0 then Y := 0;
          SetBounds(X, Y, Width, Height);
        end;
        FPosition := poDesigned;
        if FormStyle = fsMDIChild then
        begin
          { Fake a size message to get MDI to behave }
          if FWindowState = wsMaximized then
          begin
            SendMessage(Application.MainForm.ClientHandle, WM_MDIRESTORE, Handle, 0);
            ShowWindow(Handle, SW_SHOWMAXIMIZED);
          end
          else
          begin
            ShowWindow(Handle, ShowCommands[FWindowState]);
            CallWindowProc(@DefMDIChildProc, Handle, WM_SIZE, SIZE_RESTORED,
              Width or (Height shl 16));
            BringToFront;
          end;
          SendMessage(Application.MainForm.ClientHandle,
            WM_MDIREFRESHMENU, 0, 0);
        end
        else
          ShowWindow(Handle, ShowCommands[FWindowState]);
      end else
      begin
        try
          DoHide;
        except
          Application.HandleException(Self);
        end;
        if Screen.ActiveForm = Self then
          MergeMenu(False);
        if FormStyle = fsMDIChild then
          DestroyHandle
        else if fsModal in FFormState then
          SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_HIDEWINDOW or
            SWP_NOSIZE or SWP_NOMOVE or SWP_NOZORDER or SWP_NOACTIVATE)
        else
        begin
          NewActiveWindow := 0;
          if (GetActiveWindow = Handle) and not IsIconic(Handle) then
            NewActiveWindow := FindTopMostWindow(Handle);
          if NewActiveWindow <> 0 then
          begin
            SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_HIDEWINDOW or
              SWP_NOSIZE or SWP_NOMOVE or SWP_NOZORDER or SWP_NOACTIVATE);
            SetActiveWindow(NewActiveWindow);
          end else
            ShowWindow(Handle, SW_HIDE);
        end;
      end;
  finally
    Exclude(FFormState, fsShowing);
  end;
end;

procedure TCustomForm.CMIconChanged(var Message: TMessage);
begin
  if FIcon.Handle = 0 then IconChanged(nil);
end;

procedure TCustomForm.CMRelease;
begin
  Free;
end;

procedure TCustomForm.CMTextChanged(var Message: TMessage);
begin
  inherited;
  if (FormStyle = fsMDIChild) and (Application.MainForm <> nil) and
    (Application.MainForm.ClientHandle <> 0) then
    SendMessage(Application.MainForm.ClientHandle, WM_MDIREFRESHMENU, 0, 0);
end;

procedure TCustomForm.CMUIActivate(var Message);
begin
  inherited;
end;

procedure TCustomForm.CMParentFontChanged(var Message: TMessage);
var
  F: TFont;
begin
  if ParentFont then
    if Message.wParam <> 0 then
      Font.Assign(TFont(Message.lParam))
    else
    begin
      F := TFont.Create;  // get locale defaults
      try
        Font.Assign(F);
      finally
        F.Free
      end;
    end;
end;

procedure TCustomForm.Close;
var
  CloseAction: TCloseAction;
begin
  if fsModal in FFormState then
    ModalResult := mrCancel
  else
    if CloseQuery then
    begin
      if FormStyle = fsMDIChild then
        if biMinimize in BorderIcons then
          CloseAction := caMinimize else
          CloseAction := caNone
      else
        CloseAction := caHide;
      DoClose(CloseAction);
      if CloseAction <> caNone then
        if Application.MainForm = Self then Application.Terminate
        else if CloseAction = caHide then Hide
        else if CloseAction = caMinimize then WindowState := wsMinimized
        else Release;
    end;
end;

function TCustomForm.CloseQuery: Boolean;
var
  I: Integer;
begin
  if FormStyle = fsMDIForm then
  begin
    Result := False;
    for I := 0 to MDIChildCount - 1 do
      if not MDIChildren[I].CloseQuery then Exit;
  end;
  Result := True;
  if Assigned(FOnCloseQuery) then FOnCloseQuery(Self, Result);
end;

procedure TCustomForm.CloseModal;
var
  CloseAction: TCloseAction;
begin
  try
    CloseAction := caNone;
    if CloseQuery then
    begin
      CloseAction := caHide;
      if Assigned(FOnClose) then FOnClose(Self, CloseAction);
    end;
    case CloseAction of
      caNone: ModalResult := 0;
      caFree: Release;
    end;
  except
    ModalResult := 0;
    Application.HandleException(Self);
  end;
end;

function TCustomForm.GetFormImage: TBitmap;
var
  Ofs: Integer;
begin
  Result := TBitmap.Create;
  try
    Result.Width := ClientWidth;
    Result.Height := ClientHeight;
    Result.Canvas.Brush := Brush;
    Result.Canvas.FillRect(ClientRect);
    Result.Canvas.Lock;
    try
      if GetWindowLong(Handle, GWL_STYLE) and WS_BORDER <> 0 then
        Ofs := -1  // Don't draw form border
      else
        Ofs := 0;  // There is no border
      PaintTo(Result.Canvas.Handle, Ofs, Ofs);
    finally
      Result.Canvas.Unlock;
    end;
  except
    Result.Free;
    raise;
  end;
end;

procedure TCustomForm.Print;
var
  FormImage: TBitmap;
  Info: PBitmapInfo;
  InfoSize: DWORD;
  Image: Pointer;
  ImageSize: DWORD;
  Bits: HBITMAP;
  DIBWidth, DIBHeight: Longint;
  PrintWidth, PrintHeight: Longint;
begin
  Printer.BeginDoc;
  try
    FormImage := GetFormImage;
    Canvas.Lock;
    try
      { Paint bitmap to the printer }
      with Printer, Canvas do
      begin
        Bits := FormImage.Handle;
        GetDIBSizes(Bits, InfoSize, ImageSize);
        Info := AllocMem(InfoSize);
        try
          Image := AllocMem(ImageSize);
          try
            GetDIB(Bits, 0, Info^, Image^);
            with Info^.bmiHeader do
            begin
              DIBWidth := biWidth;
              DIBHeight := biHeight;
            end;
            case PrintScale of
              poProportional:
                begin
                  PrintWidth := MulDiv(DIBWidth, GetDeviceCaps(Handle,
                    LOGPIXELSX), PixelsPerInch);
                  PrintHeight := MulDiv(DIBHeight, GetDeviceCaps(Handle,
                    LOGPIXELSY), PixelsPerInch);
                end;
              poPrintToFit:
                begin
                  PrintWidth := MulDiv(DIBWidth, PageHeight, DIBHeight);
                  if PrintWidth < PageWidth then
                    PrintHeight := PageHeight
                  else
                  begin
                    PrintWidth := PageWidth;
                    PrintHeight := MulDiv(DIBHeight, PageWidth, DIBWidth);
                  end;
                end;
            else
              PrintWidth := DIBWidth;
              PrintHeight := DIBHeight;
            end;
            StretchDIBits(Canvas.Handle, 0, 0, PrintWidth, PrintHeight, 0, 0,
              DIBWidth, DIBHeight, Image, Info^, DIB_RGB_COLORS, SRCCOPY);
          finally
            FreeMem(Image, ImageSize);
          end;
        finally
          FreeMem(Info, InfoSize);
        end;
      end;
    finally
      Canvas.Unlock;
      FormImage.Free;
    end;
  finally
    Printer.EndDoc;
  end;
end;

procedure TCustomForm.Hide;
begin
  Visible := False;
end;

procedure TCustomForm.Show;
begin
  Visible := True;
  BringToFront;
end;

procedure TCustomForm.SetFocus;
begin
  if not FActive then
  begin
    if not (Visible and Enabled) then
      raise EInvalidOperation.Create(SCannotFocus);
    SetWindowFocus;
  end;
end;

procedure TCustomForm.Release;
begin
  PostMessage(Handle, CM_RELEASE, 0, 0);
end;

function TCustomForm.ShowModal: Integer;
var
  WindowList: Pointer;
  SaveFocusCount: Integer;
  SaveCursor: TCursor;
  SaveCount: Integer;
  ActiveWindow: HWnd;
begin
  CancelDrag;
  if Visible or not Enabled or (fsModal in FFormState) or
    (FormStyle = fsMDIChild) then
    raise EInvalidOperation.Create(SCannotShowModal);
  if GetCapture <> 0 then SendMessage(GetCapture, WM_CANCELMODE, 0, 0);
  ReleaseCapture;
  Include(FFormState, fsModal);
  ActiveWindow := GetActiveWindow;
  SaveFocusCount := FocusCount;
  Screen.FSaveFocusedList.Insert(0, Screen.FFocusedForm);
  Screen.FFocusedForm := Self;
  SaveCursor := Screen.Cursor;
  Screen.Cursor := crDefault;
  SaveCount := Screen.FCursorCount;
  WindowList := DisableTaskWindows(0);
  try
    Show;
    try
      SendMessage(Handle, CM_ACTIVATE, 0, 0);
      ModalResult := 0;
      repeat
        Application.HandleMessage;
        if Application.FTerminate then ModalResult := mrCancel else
          if ModalResult <> 0 then CloseModal;
      until ModalResult <> 0;
      Result := ModalResult;
      SendMessage(Handle, CM_DEACTIVATE, 0, 0);
      if GetActiveWindow <> Handle then ActiveWindow := 0;
    finally
      Hide;
    end;
  finally
    if Screen.FCursorCount = SaveCount then
      Screen.Cursor := SaveCursor
    else Screen.Cursor := crDefault;
    EnableTaskWindows(WindowList);
    if Screen.FSaveFocusedList.Count > 0 then
    begin
      Screen.FFocusedForm := Screen.FSaveFocusedList.First;
      Screen.FSaveFocusedList.Remove(Screen.FFocusedForm);
    end else Screen.FFocusedForm := nil;
    if ActiveWindow <> 0 then SetActiveWindow(ActiveWindow);
    FocusCount := SaveFocusCount;
    Exclude(FFormState, fsModal);
  end;
end;

procedure TCustomForm.UpdateActions;
var
  I: Integer;
  
  procedure TraverseClients(Container: TWinControl);
  var
    I: Integer;
    Control: TControl;
  begin
    if Container.Showing then
      for I := 0 to Container.ControlCount - 1 do
      begin
        Control := Container.Controls[I];
        if (csActionClient in Control.ControlStyle) and Control.Visible then
            Control.InitiateAction;
        if Control is TWinControl then
          TraverseClients(TWinControl(Control));
      end;
  end;

begin
  if (csDesigning in ComponentState) or not Showing then Exit;
  { Update form }
  InitiateAction;
  { Update main menu's top-most items }
  if Menu <> nil then
    for I := 0 to Menu.Items.Count - 1 do
      with Menu.Items[I] do
        if Visible then InitiateAction;
  { Update any controls }
  TraverseClients(Self);
end;

procedure TCustomForm.UpdateWindowState;
var
  Placement: TWindowPlacement;
begin
  if HandleAllocated then
  begin
    Placement.length := SizeOf(TWindowPlacement);
    GetWindowPlacement(Handle, @Placement);
    case Placement.showCmd of
      SW_SHOWMINIMIZED: FWindowState := wsMinimized;
      SW_SHOWMAXIMIZED: FWindowState := wsMaximized;
    else
      FWindowState := wsNormal;
    end;
  end;
end;

procedure TCustomForm.RequestAlign;
begin
  if Parent = nil then
    Screen.AlignForm(Self)
  else
    inherited RequestAlign;
end;

procedure TCustomForm.WMSettingChange(var Message: TMessage);
begin
  inherited;
  if Message.WParam = SPI_SETWORKAREA then
    RequestAlign;
end;

procedure TCustomForm.CMActionExecute(var Message: TMessage);

  function ProcessExecute(Control: TControl): Boolean;
  begin
    Result := (Control <> nil) and
      Control.ExecuteAction(TBasicAction(Message.LParam));
  end;

  function TraverseClients(Container: TWinControl): Boolean;
  var
    I: Integer;
    Control: TControl;
  begin
    if Container.Showing then
      for I := 0 to Container.ControlCount - 1 do
      begin
        Control := Container.Controls[I];
        if Control.Visible and ProcessExecute(Control) or
          (Control is TWinControl) and TraverseClients(TWinControl(Control)) then
        begin
          Result := True;
          Exit;
        end;
      end;
    Result := False;
  end;

begin
  if (csDesigning in ComponentState) or not Showing then Exit;
  { Find a target for given Command (Message.LParam). }
  if ProcessExecute(ActiveControl) or ProcessExecute(Self) or
    TraverseClients(Self) then
    Message.Result := 1;
end;

procedure TCustomForm.CMActionUpdate(var Message: TMessage);

  function ProcessUpdate(Control: TControl): Boolean;
  begin
    Result := (Control <> nil) and
      Control.UpdateAction(TBasicAction(Message.LParam));
  end;

  function TraverseClients(Container: TWinControl): Boolean;
  var
    I: Integer;
    Control: TControl;
  begin
    if Container.Showing then
      for I := 0 to Container.ControlCount - 1 do
      begin
        Control := Container.Controls[I];
        if Control.Visible and ProcessUpdate(Control) or
          (Control is TWinControl) and TraverseClients(TWinControl(Control)) then
        begin
          Result := True;
          Exit;
        end;
      end;
    Result := False;
  end;

begin
  if (csDesigning in ComponentState) or not Showing then Exit;
  { Find a target for given Command (Message.LParam). }
  if ProcessUpdate(ActiveControl) or ProcessUpdate(Self) or
    TraverseClients(Self) then
    Message.Result := 1;
end;

function TCustomForm.IsShortCut(var Message: TWMKey): Boolean;

  function DispatchShortCut: Boolean;
  var
    I: Integer;
  begin
    if FActionLists <> nil then
      for I := 0 to FActionLists.Count - 1 do
        if TCustomActionList(FActionLists[I]).IsShortCut(Message) then
        begin
          Result := True;
          Exit;
        end;
    Result := False;
  end;

begin
  Result := False;
  if Assigned(FOnShortCut) then FOnShortCut(Message, Result);
  Result := Result or (Menu <> nil) and (Menu.WindowHandle <> 0) and
    Menu.IsShortCut(Message) or DispatchShortCut;
end;

function TCustomForm.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if IsEqualIID(IID, IDesignerNotify) or IsEqualIID(IID, IDesigner) then
  begin
    Result := S_OK;
    IUnknown(Obj) := Designer;
  end
  else
    Result := inherited QueryInterface(IID, Obj);
end;

procedure TCustomForm.MouseWheelHandler(var Message: TMessage);
begin
  with Message do
  begin
    if FFocusedControl <> nil then
      Result := FFocusedControl.Perform(CM_MOUSEWHEEL, WParam, LParam)
    else
      inherited MouseWheelHandler(Message);
  end;
end;

{ TForm }

procedure TForm.Tile;
const
  TileParams: array[TTileMode] of Word = (MDITILE_HORIZONTAL, MDITILE_VERTICAL);
begin
  if (FFormStyle = fsMDIForm) and (ClientHandle <> 0) then
    SendMessage(ClientHandle, WM_MDITILE, TileParams[FTileMode], 0);
end;

procedure TForm.Cascade;
begin
  if (FFormStyle = fsMDIForm) and (ClientHandle <> 0) then
    SendMessage(ClientHandle, WM_MDICASCADE, 0, 0);
end;

procedure TForm.ArrangeIcons;
begin
  if (FFormStyle = fsMDIForm) and (ClientHandle <> 0) then
    SendMessage(ClientHandle, WM_MDIICONARRANGE, 0, 0);
end;

procedure TForm.Next;
begin
  if (FFormStyle = fsMDIForm) and (ClientHandle <> 0) then
    SendMessage(ClientHandle, WM_MDINEXT, 0, 0);
end;

procedure TForm.Previous;
begin
  if (FormStyle = fsMDIForm) and (ClientHandle <> 0) then
    SendMessage(FClientHandle, WM_MDINEXT, 0, 1);
end;

{ TCustomDockForm }

constructor TCustomDockForm.Create(AOwner: TComponent);
begin
  CreateNew(AOwner);
  AutoScroll := False;
  BorderStyle := bsSizeToolWin;
  DockSite := True;
  FormStyle := fsStayOnTop;
end;

procedure TCustomDockForm.DoAddDockClient(Client: TControl; const ARect: TRect);
var
  S: string;
  I: Integer;
begin
  if DockClientCount = 1 then
  begin
    { Use first docked control }
    with Client do
    begin
      SetString(S, nil, GetTextLen + 1);
      GetTextBuf(PChar(S), Length(S));
      { Search for first CR/LF and end string there }
      for I := 1 to Length(S) do
        if S[I] in [#13, #10] then
        begin
          SetLength(S, I - 1);
          Break;
        end;
    end;
    Caption := S;
  end;
  inherited DoAddDockClient(Client, ARect);
  Client.Align := alClient;
  if not (csLoading in ComponentState) then
    Visible := True;
end;

procedure TCustomDockForm.DoRemoveDockClient(Client: TControl);
begin
  inherited DoRemoveDockClient(Client);
  if DockClientCount = 0 then Release;
end;

procedure TCustomDockForm.Loaded;
var
  I: Integer;
begin
  { Make sure we dock controls after streaming }
  for I := 0 to ControlCount - 1 do
    Controls[I].Dock(Self, ClientRect);
  inherited Loaded;
end;

procedure TCustomDockForm.GetSiteInfo(Client: TControl;
  var InfluenceRect: TRect; MousePos: TPoint; var CanDock: Boolean);
begin
  CanDock := DockClientCount = 0;
end;

procedure TCustomDockForm.WMNCHitTest(var Message: TWMNCHitTest);
begin
  inherited;
  if not (csDesigning in ComponentState) and (Message.Result = HTCLIENT) then
    Message.Result := HTCAPTION;
end;

procedure TCustomDockForm.WMNCLButtonDown(var Message: TWMNCLButtonDown);
begin
  if (Message.HitTest = HTCAPTION) and (DragKind <> dkDock) and not
    (csDesigning in ComponentState) and not IsIconic(Handle) and
    (DockClientCount > 0) then
  begin
    { Activate window since we override WM_NCLBUTTON behavior }
    SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_NOZORDER or SWP_NOMOVE or
      SWP_NOSIZE);
    PostMessage(Handle, WM_NCLBUTTONUP, TMessage(Message).WParam,
      TMessage(Message).LParam);
    if Active then DockClients[0].BeginDrag(True);
  end
  else
    inherited;
end;

procedure TCustomDockForm.CMControlListChange(var Message: TMessage);
begin
  inherited;
  if Message.LParam = 0 then
  begin
    Perform(CM_UNDOCKCLIENT, 0, Message.WParam);
    if TControl(Message.WParam).HostDockSite = Self then
      TControl(Message.WParam).Dock(NullDockSite, TControl(Message.WParam).BoundsRect);
  end;
end;

procedure TCustomDockForm.CMDockNotification(var Message: TCMDockNotification);
var
  S: string;
  I: Integer;
begin
  inherited;
  case Message.NotifyRec^.ClientMsg of
    CM_VISIBLECHANGED: Visible := Message.Client.Visible;
    WM_SETTEXT:
      begin
        SetString(S, nil, Message.Client.GetTextLen + 1);
        Message.Client.GetTextBuf(PChar(S), Length(S));
        { Search for first CR/LF and end string there }
        for I := 1 to Length(S) do
          if S[I] in [#13, #10] then
          begin
            SetLength(S, I - 1);
            Break;
          end;
        Caption := S;
      end;
  end;
end;

procedure TCustomDockForm.CMUnDockClient(var Message: TCMUnDockClient);
begin
  inherited;
  Message.Client.Align := alNone;
end;

procedure TCustomDockForm.CMVisibleChanged(var Message: TMessage);
var
  I: Integer;
begin
  inherited;
  if not (csDestroying in ComponentState) then
    for I := 0 to DockClientCount - 1 do
      DockClients[I].Visible := Visible;
end;

{ TDataModule }

constructor TDataModule.Create(AOwner: TComponent);
begin
  GlobalNameSpace.BeginWrite;
  try
    CreateNew(AOwner);
    if (ClassType <> TDataModule) and not (csDesigning in ComponentState) then
    begin
      if not InitInheritedComponent(Self, TDataModule) then
        raise EResNotFound.CreateFmt(SResNotFound, [ClassName]);
      if OldCreateOrder then DoCreate;
    end;
  finally
    GlobalNameSpace.EndWrite;
  end;
end;

procedure TDataModule.AfterConstruction;
begin
  if not OldCreateOrder then DoCreate;
end;

constructor TDataModule.CreateNew(AOwner: TComponent; Dummy: Integer);
begin
  inherited Create(AOwner);
  Screen.AddDataModule(Self);
end;

procedure TDataModule.BeforeDestruction;
begin
  GlobalNameSpace.BeginWrite;
  Destroying;
  RemoveFixupReferences(Self, '');
  if not OldCreateOrder then DoDestroy;
end;

destructor TDataModule.Destroy;
begin
  if not (csDestroying in ComponentState) then GlobalNameSpace.BeginWrite;
  try
    if OldCreateOrder then DoDestroy;
    Screen.RemoveDataModule(Self);
    inherited Destroy;
  finally
    GlobalNameSpace.EndWrite;
  end;
end;

procedure TDataModule.DoCreate;
begin
  if Assigned(FOnCreate) then
  try
    FOnCreate(Self);
  except
    Application.HandleException(Self);
  end;
end;

procedure TDataModule.DoDestroy;
begin
  if Assigned(FOnDestroy) then
  try
    FOnDestroy(Self);
  except
    Application.HandleException(Self);
  end;
end;

procedure TDataModule.DefineProperties(Filer: TFiler);
var
  Ancestor: TDataModule;

  function DoWriteWidth: Boolean;
  begin
    Result := True;
    if Ancestor <> nil then Result := FDesignSize.X <> Ancestor.FDesignSize.X;
  end;

  function DoWriteHorizontalOffset: Boolean;
  begin
    if Ancestor <> nil then
      Result := FDesignOffset.X <> Ancestor.FDesignOffset.X else
      Result := FDesignOffset.X <> 0;
  end;

  function DoWriteVerticalOffset: Boolean;
  begin
    if Ancestor <> nil then
      Result := FDesignOffset.Y <> Ancestor.FDesignOffset.Y else
      Result := FDesignOffset.Y <> 0;
  end;

  function DoWriteHeight: Boolean;
  begin
    Result := True;
    if Ancestor <> nil then Result := FDesignSize.Y <> Ancestor.FDesignSize.Y;
  end;

begin
  inherited DefineProperties(Filer);
  Ancestor := TDataModule(Filer.Ancestor);
  Filer.DefineProperty('Height', ReadHeight, WriteHeight, DoWriteHeight);
  Filer.DefineProperty('HorizontalOffset', ReadHorizontalOffset,
    WriteHorizontalOffset, DoWriteHorizontalOffset);
  Filer.DefineProperty('VerticalOffset', ReadVerticalOffset,
    WriteVerticalOffset, DoWriteVerticalOffset);
  Filer.DefineProperty('Width', ReadWidth, WriteWidth, DoWriteWidth);
end;

procedure TDataModule.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
  OwnedComponent: TComponent;
begin
  inherited GetChildren(Proc, Root);
  if Root = Self then
    for I := 0 to ComponentCount - 1 do
    begin
      OwnedComponent := Components[I];
      if not OwnedComponent.HasParent then Proc(OwnedComponent);
    end;
end;

procedure TDataModule.ReadState(Reader: TReader);
begin
  FOldCreateOrder := not ModuleIsCPP;
  inherited ReadState(Reader);
end;

procedure TDataModule.ReadWidth(Reader: TReader);
begin
  FDesignSize.X := Reader.ReadInteger;
end;

procedure TDataModule.ReadHorizontalOffset(Reader: TReader);
begin
  FDesignOffset.X := Reader.ReadInteger;
end;

procedure TDataModule.ReadVerticalOffset(Reader: TReader);
begin
  FDesignOffset.Y := Reader.ReadInteger;
end;

procedure TDataModule.ReadHeight(Reader: TReader);
begin
  FDesignSize.Y := Reader.ReadInteger;
end;

procedure TDataModule.WriteWidth(Writer: TWriter);
begin
  Writer.WriteInteger(FDesignSize.X);
end;

procedure TDataModule.WriteHorizontalOffset(Writer: TWriter);
begin
  Writer.WriteInteger(FDesignOffset.X);
end;

procedure TDataModule.WriteVerticalOffset(Writer: TWriter);
begin
  Writer.WriteInteger(FDesignOffset.Y);
end;

procedure TDataModule.WriteHeight(Writer: TWriter);
begin
  Writer.WriteInteger(FDesignSize.Y);
end;

{ TMonitor }

function TMonitor.GetLeft: Integer;
var
  MonInfo: TMonitorInfo;
begin
  MonInfo.cbSize := SizeOf(MonInfo);
  GetMonitorInfo(FHandle, @MonInfo);
  Result := MonInfo.rcMonitor.Left;
end;

function TMonitor.GetHeight: Integer;
var
  MonInfo: TMonitorInfo;
begin
  MonInfo.cbSize := SizeOf(MonInfo);
  GetMonitorInfo(FHandle, @MonInfo);
  Result := MonInfo.rcMonitor.Bottom - MonInfo.rcMonitor.Top;
end;

function TMonitor.GetTop: Integer;
var
  MonInfo: TMonitorInfo;
begin
  MonInfo.cbSize := SizeOf(MonInfo);
  GetMonitorInfo(FHandle, @MonInfo);
  Result := MonInfo.rcMonitor.Top;
end;

function TMonitor.GetWidth: Integer;
var
  MonInfo: TMonitorInfo;
begin
  MonInfo.cbSize := SizeOf(MonInfo);
  GetMonitorInfo(FHandle, @MonInfo);
  Result := MonInfo.rcMonitor.Right - MonInfo.rcMonitor.Left;
end;


{ TScreen }

const
  IDC_NODROP =    PChar(32767);
  IDC_DRAG   =    PChar(32766);
  IDC_HSPLIT =    PChar(32765);
  IDC_VSPLIT =    PChar(32764);
  IDC_MULTIDRAG = PChar(32763);
  IDC_SQLWAIT =   PChar(32762);
  IDC_HANDPT =   PChar(32761);

function EnumFontsProc(var LogFont: TLogFont; var TextMetric: TTextMetric;
  FontType: Integer; Data: Pointer): Integer; stdcall;
var
  S: TStrings;
  Temp: string;
begin
  S := TStrings(Data);
  Temp := LogFont.lfFaceName;
  if (S.Count = 0) or (AnsiCompareText(S[S.Count-1], Temp) <> 0) then
    S.Add(Temp);
  Result := 1;
end;

constructor TScreen.Create(AOwner: TComponent);
var
  DC: HDC;
begin
  inherited Create(AOwner);
  CreateCursors;
  FDefaultKbLayout := GetKeyboardLayout(0);
  FForms := TList.Create;
  FCustomForms := TList.Create;
  FDataModules := TList.Create;
  FMonitors := TList.Create;
  FSaveFocusedList := TList.Create;
  DC := GetDC(0);
  FPixelsPerInch := GetDeviceCaps(DC, LOGPIXELSY);
  ReleaseDC(0, DC);
  EnumDisplayMonitors(0, nil, @EnumMonitorsProc, LongInt(FMonitors));
  FIconFont := TFont.Create;
  FMenuFont := TFont.Create;
  FHintFont := TFont.Create;
  GetMetricSettings;
  FIconFont.OnChange := IconFontChanged;
  FMenuFont.OnChange := IconFontChanged;
  FHintFont.OnChange := IconFontChanged;
end;

destructor TScreen.Destroy;
var
  I: Integer;
begin
  FHintFont.Free;
  FMenuFont.Free;
  FIconFont.Free;
  FDataModules.Free;
  FCustomForms.Free;
  FForms.Free;
  FFonts.Free;
  FImes.Free;
  FSaveFocusedList.Free;
  if FMonitors <> nil then
    for I := 0 to FMonitors.Count - 1 do
      TMonitor(FMonitors[I]).Free;
  FMonitors.Free;
  DestroyCursors;
  inherited Destroy;
end;

function TScreen.GetHeight: Integer;
begin
  Result := GetSystemMetrics(SM_CYSCREEN);
end;

function TScreen.GetWidth: Integer;
begin
  Result := GetSystemMetrics(SM_CXSCREEN);
end;

function TScreen.GetDesktopTop: Integer;
begin
  Result := GetSystemMetrics(SM_YVIRTUALSCREEN);
end;

function TScreen.GetDesktopLeft: Integer;
begin
  Result := GetSystemMetrics(SM_XVIRTUALSCREEN);
end;

function TScreen.GetDesktopHeight: Integer;
begin
  Result := GetSystemMetrics(SM_CYVIRTUALSCREEN);
end;

function TScreen.GetDesktopWidth: Integer;
begin
  Result := GetSystemMetrics(SM_CXVIRTUALSCREEN);
end;

function TScreen.GetMonitor(Index: Integer): TMonitor;
begin
  Result := FMonitors[Index];
end;

function TScreen.GetMonitorCount: Integer;
begin
  if FMonitors.Count = 0 then
    Result := GetSystemMetrics(SM_CMONITORS)
  else
    Result := FMonitors.Count;
end;

function TScreen.GetForm(Index: Integer): TForm;
begin
  Result := FForms[Index];
end;

function TScreen.GetFormCount: Integer;
begin
  Result := FForms.Count;
end;

function TScreen.GetCustomForms(Index: Integer): TCustomForm;
begin
  Result := FCustomForms[Index];
end;

function TScreen.GetCustomFormCount: Integer;
begin
  Result := FCustomForms.Count;
end;

procedure TScreen.UpdateLastActive;
begin
  if FLastActiveCustomForm <> FActiveCustomForm then
  begin
    FLastActiveCustomForm := FActiveCustomForm;
    if Assigned(FOnActiveFormChange) then FOnActiveFormChange(Self);
  end;
  if FLastActiveControl <> FActiveControl then
  begin
    FLastActiveControl := FActiveControl;
    if Assigned(FOnActiveControlChange) then FOnActiveControlChange(Self);
  end;
end;

procedure TScreen.AddForm(AForm: TCustomForm);
begin
  FCustomForms.Add(AForm);
  if AForm is TForm then
  begin
    FForms.Add(AForm);
    Application.UpdateVisible;
  end;
end;

procedure TScreen.RemoveForm(AForm: TCustomForm);
begin
  FCustomForms.Remove(AForm);
  FForms.Remove(AForm);
  Application.UpdateVisible;
  if (FCustomForms.Count = 0) and (Application.FHintWindow <> nil) then
    Application.FHintWindow.ReleaseHandle;
end;

procedure TScreen.AddDataModule(DataModule: TDataModule);
begin
  FDataModules.Add(DataModule);
end;

procedure TScreen.RemoveDataModule(DataModule: TDataModule);
begin
  FDataModules.Remove(DataModule);
end;

procedure TScreen.CreateCursors;
const
  CursorMap: array[crSizeAll..crArrow] of PChar = (
    IDC_SIZEALL, IDC_HANDPT, IDC_HELP, IDC_APPSTARTING, IDC_NO, IDC_SQLWAIT,
    IDC_MULTIDRAG, IDC_VSPLIT, IDC_HSPLIT, IDC_NODROP, IDC_DRAG, IDC_WAIT,
    IDC_UPARROW, IDC_SIZEWE, IDC_SIZENWSE, IDC_SIZENS, IDC_SIZENESW, IDC_SIZE,
    IDC_IBEAM, IDC_CROSS, IDC_ARROW);
var
  I: Integer;
  Instance: THandle;
begin
  FDefaultCursor := LoadCursor(0, IDC_ARROW);
  for I := Low(CursorMap) to High(CursorMap) do
  begin
    if ((I >= crSqlWait) and (I <= crDrag)) or (I = crHandPoint) then
      Instance := HInstance else
      Instance := 0;
    InsertCursor(I, LoadCursor(Instance, CursorMap[I]));
  end;
end;

procedure TScreen.DestroyCursors;
var
  P, Next: PCursorRec;
  Hdl: THandle;
begin
  P := FCursorList;
  while P <> nil do
  begin
    if ((P^.Index >= crSqlWait) and (P^.Index <= crDrag)) or
      (P^.Index = crHandPoint) or (P^.Index > 0) then
      DestroyCursor(P^.Handle);
    Next := P^.Next;
    Dispose(P);
    P := Next;
  end;
  Hdl := LoadCursor(0, IDC_ARROW);
  if Hdl <> FDefaultCursor then
    DestroyCursor(FDefaultCursor);
end;

procedure TScreen.DeleteCursor(Index: Integer);
var
  P, Q: PCursorRec;
begin
  P := FCursorList;
  Q := nil;
  while (P <> nil) and (P^.Index <> Index) do
  begin
    Q := P;
    P := P^.Next;
  end;
  if P <> nil then
  begin
    DestroyCursor(P^.Handle);
    if Q = nil then FCursorList := P^.Next else Q^.Next := P^.Next;
    Dispose(P);
  end;
end;

procedure TScreen.InsertCursor(Index: Integer; Handle: HCURSOR);
var
  P: PCursorRec;
begin
  New(P);
  P^.Next := FCursorList;
  P^.Index := Index;
  P^.Handle := Handle;
  FCursorList := P;
end;

function TScreen.GetImes: TStrings;
const
  KbLayoutRegkeyFmt = 'System\CurrentControlSet\Control\Keyboard Layouts\%.8x';  // do not localize
  KbLayoutRegSubkey = 'layout text'; // do not localize
var
  TotalKbLayout, I, Bufsize: Integer;
  KbList: array[0..63] of HKL;
  qKey: HKey;
  ImeFileName: array [Byte] of Char;
  RegKey: array [0..63] of Char;
begin
  if FImes = nil then
  begin
    FImes := TStringList.Create;

    FDefaultIme := '';
    TotalKbLayout := GetKeyboardLayoutList(64, KbList);

    for I := 0 to TotalKbLayout - 1 do
    begin
      if Imm32IsIME(KbList[I]) then
      begin
        if RegOpenKeyEx(HKEY_LOCAL_MACHINE,
          StrFmt(RegKey, KbLayoutRegKeyFmt, [KbList[I]]), 0, KEY_READ,
          qKey) = ERROR_SUCCESS then
        try
          Bufsize := sizeof(ImeFileName);
          if RegQueryValueEx(qKey, KbLayoutRegSubKey, nil, nil,
               @ImeFileName, @Bufsize) = ERROR_SUCCESS then
          begin
            FImes.AddObject(ImeFileName, TObject(KbList[I]));
            if KbList[I] = FDefaultKbLayout then
              FDefaultIme := ImeFileName;
          end;
        finally
          RegCloseKey(qKey);
        end;
      end;
    end;
    TStringList(FImes).Duplicates := dupIgnore;
    TStringList(FImes).Sorted := TRUE;
  end;
  Result := FImes;
end;

function TScreen.GetDefaultIme: String;
begin
  GetImes;  // load Ime list, find default
  Result := FDefaultIme;
end;

procedure TScreen.IconFontChanged(Sender: TObject);
begin
  Application.NotifyForms(CM_SYSFONTCHANGED);
end;

function TScreen.GetDataModule(Index: Integer): TDataModule;
begin
  Result := FDataModules[Index];
end;

function TScreen.GetDataModuleCount: Integer;
begin
  Result := FDataModules.Count;
end;

function TScreen.GetCursors(Index: Integer): HCURSOR;
var
  P: PCursorRec;
begin
  Result := 0;
  if Index <> crNone then
  begin
    P := FCursorList;
    while (P <> nil) and (P^.Index <> Index) do P := P^.Next;
    if P = nil then Result := FDefaultCursor else Result := P^.Handle;
  end;
end;

procedure TScreen.SetCursor(Value: TCursor);
var
  P: TPoint;
  Handle: HWND;
  Code: Longint;
begin
  if Value <> Cursor then
  begin
    FCursor := Value;
    if Value = crDefault then
    begin
      { Reset the cursor to the default by sending a WM_SETCURSOR to the
        window under the cursor }
      GetCursorPos(P);
      Handle := WindowFromPoint(P);
      if (Handle <> 0) and
        (GetWindowThreadProcessId(Handle, nil) = GetCurrentThreadId) then
      begin
        Code := SendMessage(Handle, WM_NCHITTEST, 0, LongInt(PointToSmallPoint(P)));
        SendMessage(Handle, WM_SETCURSOR, Handle, MakeLong(Code, WM_MOUSEMOVE));
        Exit;
      end;
    end;
    Windows.SetCursor(Cursors[Value]);
  end;
  Inc(FCursorCount);
end;

procedure TScreen.SetCursors(Index: Integer; Handle: HCURSOR);
begin
  if Index = crDefault then
    if Handle = 0 then
      FDefaultCursor := LoadCursor(0, IDC_ARROW)
    else
      FDefaultCursor := Handle
  else if Index <> crNone then
  begin
    DeleteCursor(Index);
    if Handle <> 0 then InsertCursor(Index, Handle);
  end;
end;

procedure TScreen.SetHintFont(Value: TFont);
begin
  FHintFont.Assign(Value);
end;

procedure TScreen.SetIconFont(Value: TFont);
begin
  FIconFont.Assign(Value);
end;

procedure TScreen.SetMenuFont(Value: TFont);
begin
  FMenuFont.Assign(Value);
end;

procedure TScreen.GetMetricSettings;
var
  LogFont: TLogFont;
  NonClientMetrics: TNonClientMetrics;
begin
  if SystemParametersInfo(SPI_GETICONTITLELOGFONT, SizeOf(LogFont), @LogFont, 0) then
    FIconFont.Handle := CreateFontIndirect(LogFont)
  else
    FIconFont.Handle := GetStockObject(SYSTEM_FONT);
  NonClientMetrics.cbSize := SizeOf(NonClientMetrics);
  if SystemParametersInfo(SPI_GETNONCLIENTMETRICS, 0, @NonClientMetrics, 0) then
  begin
    FHintFont.Handle := CreateFontIndirect(NonClientMetrics.lfStatusFont);
    FMenuFont.Handle := CreateFontIndirect(NonClientMetrics.lfMenuFont);
  end else
  begin
    FHintFont.Size := 8;
    FMenuFont.Handle := GetStockObject(SYSTEM_FONT);
  end;
end;

procedure TScreen.DisableAlign;
begin
  Inc(FAlignLevel);
end;

procedure TScreen.EnableAlign;
begin
  Dec(FAlignLevel);
  if (FAlignLevel = 0) and (csAlignmentNeeded in FControlState) then Realign;
end;

procedure TScreen.Realign;
begin
  AlignForm(nil);
end;

procedure TScreen.AlignForms(AForm: TCustomForm; var Rect: TRect);
var
  AlignList: TList;

  function InsertBefore(C1, C2: TCustomForm; AAlign: TAlign): Boolean;
  begin
    Result := False;
    case AAlign of
      alTop: Result := C1.Top < C2.Top;
      alBottom: Result := (C1.Top + C1.Height) > (C2.Top + C2.Height);
      alLeft: Result := C1.Left < C2.Left;
      alRight: Result := (C1.Left + C1.Width) > (C2.Left + C2.Width);
    end;
  end;

  procedure DoPosition(Form: TCustomForm; AAlign: TAlign);
  var
    NewLeft, NewTop, NewWidth, NewHeight: Integer;
  begin
    with Rect do
    begin
      NewWidth := Right - Left;
      if (NewWidth < 0) or (AAlign in [alLeft, alRight]) then
        NewWidth := Form.Width;
      NewHeight := Bottom - Top;
      if (NewHeight < 0) or (AAlign in [alTop, alBottom]) then
        NewHeight := Form.Height;
      if (AAlign = alTop) and (Form.WindowState = wsMaximized) then
      begin
        NewLeft := Form.Left;
        NewTop := Form.Top;
        NewWidth := GetSystemMetrics(SM_CXMAXIMIZED);
      end
      else
      begin
        NewLeft := Left;
        NewTop := Top;
      end;
      case AAlign of
        alTop: Inc(Top, NewHeight);
        alBottom:
          begin
            Dec(Bottom, NewHeight);
            NewTop := Bottom;
          end;
        alLeft: Inc(Left, NewWidth);
        alRight:
          begin
            Dec(Right, NewWidth);
            NewLeft := Right;
          end;
      end;
    end;
    Form.SetBounds(NewLeft, NewTop, NewWidth, NewHeight);
    if Form.WindowState = wsMaximized then
    begin
      Dec(NewWidth, NewLeft);
      Dec(NewHeight, NewTop);
    end;
    { Adjust client rect if Form didn't resize as we expected }
    if (Form.Width <> NewWidth) or (Form.Height <> NewHeight) then
      with Rect do
        case AAlign of
          alTop: Dec(Top, NewHeight - Form.Height);
          alBottom: Inc(Bottom, NewHeight - Form.Height);
          alLeft: Dec(Left, NewWidth - Form.Width);
          alRight: Inc(Right, NewWidth - Form.Width);
          alClient:
            begin
              Inc(Right, NewWidth - Form.Width);
              Inc(Bottom, NewHeight - Form.Height);
            end;
        end;
  end;

  procedure DoAlign(AAlign: TAlign);
  var
    I, J: Integer;
    Form: TCustomForm;
  begin
    AlignList.Clear;
    if (AForm <> nil) and (AForm.Parent = nil) and
      not (csDesigning in AForm.ComponentState) and
      AForm.Visible and (AForm.Align = AAlign) and
      (AForm.WindowState <> wsMinimized) then
      AlignList.Add(AForm);
    for I := 0 to CustomFormCount - 1 do
    begin
      Form := TCustomForm(CustomForms[I]);
      if (Form.Parent = nil) and (Form.Align = AAlign) and
        not (csDesigning in Form.ComponentState) and
        Form.Visible and (Form.WindowState <> wsMinimized) then
      begin
        if Form = AForm then Continue;
        J := 0;
        while (J < AlignList.Count) and not InsertBefore(Form,
          TCustomForm(AlignList[J]), AAlign) do Inc(J);
        AlignList.Insert(J, Form);
      end;
    end;
    for I := 0 to AlignList.Count - 1 do
      DoPosition(TCustomForm(AlignList[I]), AAlign);
  end;

  function AlignWork: Boolean;
  var
    I: Integer;
  begin
    Result := True;
    for I := CustomFormCount - 1 downto 0 do
      with TCustomForm(CustomForms[I]) do
        if (Parent = nil) and not (csDesigning in ComponentState) and
          (Align <> alNone) and Visible and (WindowState <> wsMinimized) then Exit;
    Result := False;
  end;

begin
  if AlignWork then
  begin
    AlignList := TList.Create;
    try
      DoAlign(alTop);
      DoAlign(alBottom);
      DoAlign(alLeft);
      DoAlign(alRight);
      DoAlign(alClient);
    finally
      AlignList.Free;
    end;
  end;
end;

procedure TScreen.AlignForm(AForm: TCustomForm);
var
  Rect: TRect;
begin
  if FAlignLevel <> 0 then
    Include(FControlState, csAlignmentNeeded)
  else
  begin
    DisableAlign;
    try
      SystemParametersInfo(SPI_GETWORKAREA, 0, @Rect, 0);
      AlignForms(AForm, Rect);
    finally
      Exclude(FControlState, csAlignmentNeeded);
      EnableAlign;
    end;
  end;
end;

function TScreen.GetFonts: TStrings;
var
  DC: HDC;
  LFont: TLogFont;
begin
  if FFonts = nil then
  begin
    FFonts := TStringList.Create;
    DC := GetDC(0);
    try
      FFonts.Add('Default');
      FillChar(LFont, sizeof(LFont), 0);
      LFont.lfCharset := DEFAULT_CHARSET;
      EnumFontFamiliesEx(DC, LFont, @EnumFontsProc, LongInt(FFonts), 0);
      TStringList(FFonts).Sorted := TRUE;
    finally
      ReleaseDC(0, DC);
    end;
  end;
  Result := FFonts;
end;

procedure TScreen.ResetFonts;
begin
  FreeAndNil(FFonts);
end;

{ Hint functions }

function GetHint(Control: TControl): string;
begin
  while Control <> nil do
    if Control.Hint = '' then
      Control := Control.Parent
    else
    begin
      Result := Control.Hint;
      Exit;
    end;
  Result := '';
end;

function GetHintControl(Control: TControl): TControl;
begin
  Result := Control;
  while (Result <> nil) and not Result.ShowHint do Result := Result.Parent;
  if (Result <> nil) and (csDesigning in Result.ComponentState) then Result := nil;
end;

procedure HintTimerProc(Wnd: HWnd; Msg, TimerID, SysTime: Longint); stdcall;
begin
  if Application <> nil then 
  try
    Application.HintTimerExpired;
  except
    Application.HandleException(Application);
  end;    
end;

{ DLL specific hint routines - Only executed in the context of a DLL to
  simulate hooks the .EXE has in the message loop }
var
  HintThreadID: DWORD;
  HintDoneEvent: THandle;

procedure HintMouseThread(Param: Integer); stdcall;
var
  P: TPoint;
begin
  HintThreadID := GetCurrentThreadID;
  while WaitForSingleObject(HintDoneEvent, 100) = WAIT_TIMEOUT do
  begin
    if (Application <> nil) and (Application.FHintControl <> nil) then
    begin
      GetCursorPos(P);
      if FindVCLWindow(P) = nil then
        Application.CancelHint;
    end;
  end;
end;

var
  HintHook: HHOOK;
  HintThread: THandle;

function HintGetMsgHook(nCode: Integer; wParam: Longint; var Msg: TMsg): Longint; stdcall;
begin
  Result := CallNextHookEx(HintHook, nCode, wParam, Longint(@Msg));
  if (nCode >= 0) and (Application <> nil) then Application.IsHintMsg(Msg);
end;

procedure HookHintHooks;
var
  ThreadID: DWORD;
begin
  if not Application.FRunning then
  begin
    if HintHook = 0 then
      HintHook := SetWindowsHookEx(WH_GETMESSAGE, @HintGetMsgHook, 0, GetCurrentThreadID);
    if HintDoneEvent = 0 then
      HintDoneEvent := CreateEvent(nil, False, False, nil);
    if HintThread = 0 then
      HintThread := CreateThread(nil, 1000, @HintMouseThread, nil, 0, ThreadID);
  end;
end;

procedure UnhookHintHooks;
begin
  if HintHook <> 0 then UnhookWindowsHookEx(HintHook);
  HintHook := 0;
  if HintThread <> 0 then
  begin
    SetEvent(HintDoneEvent);
    if GetCurrentThreadId <> HintThreadID then
      WaitForSingleObject(HintThread, INFINITE);
    CloseHandle(HintThread);
    HintThread := 0;
  end;
end;

function GetAnimation: Boolean;
var
  Info: TAnimationInfo;
begin
  Info.cbSize := SizeOf(TAnimationInfo);
  if SystemParametersInfo(SPI_GETANIMATION, SizeOf(Info), @Info, 0) then
    Result := Info.iMinAnimate <> 0 else
    Result := False;
end;

procedure SetAnimation(Value: Boolean);
var
  Info: TAnimationInfo;
begin
  Info.cbSize := SizeOf(TAnimationInfo);
  BOOL(Info.iMinAnimate) := Value;
  SystemParametersInfo(SPI_SETANIMATION, SizeOf(Info), @Info, 0);
end;

procedure ShowWinNoAnimate(Handle: HWnd; CmdShow: Integer);
var
  Animation: Boolean;
begin
  Animation := GetAnimation;
  if Animation then SetAnimation(False);
  ShowWindow(Handle, CmdShow);
  if Animation then SetAnimation(True);
end;

{ TApplication }

var
  WindowClass: TWndClass = (
    style: 0;
    lpfnWndProc: @DefWindowProc;
    cbClsExtra: 0;
    cbWndExtra: 0;
    hInstance: 0;
    hIcon: 0;
    hCursor: 0;
    hbrBackground: 0;
    lpszMenuName: nil;
    lpszClassName: 'TApplication');

constructor TApplication.Create(AOwner: TComponent);
var
  P: PChar;
  ModuleName: array[0..255] of Char;
begin
  inherited Create(AOwner);
  FBiDiMode := bdLeftToRight;
  FTopMostList := TList.Create;
  FWindowHooks := TList.Create;
  FHintControl := nil;
  FHintWindow := nil;
  FHintColor := DefHintColor;
  FHintPause := DefHintPause;
  FHintShortCuts := True;
  FHintShortPause := DefHintShortPause;
  FHintHidePause := DefHintHidePause;
  FShowHint := False;
  FActive := True;
  FIcon := TIcon.Create;
  FIcon.Handle := LoadIcon(MainInstance, 'MAINICON');
  FIcon.OnChange := IconChanged;
  GetModuleFileName(MainInstance, ModuleName, SizeOf(ModuleName));
  OemToAnsi(ModuleName, ModuleName);
  P := AnsiStrRScan(ModuleName, '\');
  if P <> nil then StrCopy(ModuleName, P + 1);
  P := AnsiStrScan(ModuleName, '.');
  if P <> nil then P^ := #0;
  AnsiLower(ModuleName + 1);
  FTitle := ModuleName;
  if not IsLibrary then CreateHandle;
  UpdateFormatSettings := True;
  UpdateMetricSettings := True;
  FShowMainForm := True;
  FAllowTesting := True;
  FTestLib := 0;
end;

destructor TApplication.Destroy;
begin
  if FTestLib > 32 then
    FreeLibrary(FTestLib);
  if (FHandle <> 0) and FHandleCreated and (HelpFile <> '') then
    HelpCommand(HELP_QUIT, 0);
  FActive := False;
  CancelHint;
  ShowHint := False;
  inherited Destroy;
  UnhookMainWindow(CheckIniChange);
  if (FHandle <> 0) and FHandleCreated then
  begin
    if NewStyleControls then SendMessage(FHandle, WM_SETICON, 1, 0);
    DestroyWindow(FHandle);
  end;
  if FObjectInstance <> nil then FreeObjectInstance(FObjectInstance);
  FWindowHooks.Free;
  FTopMostList.Free;
  FIcon.Free;
end;

procedure TApplication.CreateHandle;
var
  TempClass: TWndClass;
  SysMenu: HMenu;
begin
  if not FHandleCreated and not IsConsole then
  begin
    FObjectInstance := MakeObjectInstance(WndProc);
    if not GetClassInfo(HInstance, WindowClass.lpszClassName, TempClass) then
    begin
      WindowClass.hInstance := HInstance;
      if Windows.RegisterClass(WindowClass) = 0 then
        raise EOutOfResources.Create(SWindowClass);
    end;
    FHandle := CreateWindow(WindowClass.lpszClassName, PChar(FTitle),
      WS_POPUP or WS_CAPTION or WS_CLIPSIBLINGS or WS_SYSMENU
      or WS_MINIMIZEBOX,
      GetSystemMetrics(SM_CXSCREEN) div 2,
      GetSystemMetrics(SM_CYSCREEN) div 2,
      0, 0, 0, 0, HInstance, nil);
    FTitle := '';
    FHandleCreated := True;
    SetWindowLong(FHandle, GWL_WNDPROC, Longint(FObjectInstance));
    if NewStyleControls then
    begin
      SendMessage(FHandle, WM_SETICON, 1, GetIconHandle);
      SetClassLong(FHandle, GCL_HICON, GetIconHandle);
    end;
    SysMenu := GetSystemMenu(FHandle, False);
    DeleteMenu(SysMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    DeleteMenu(SysMenu, SC_SIZE, MF_BYCOMMAND);
    if NewStyleControls then DeleteMenu(SysMenu, SC_MOVE, MF_BYCOMMAND);
  end;
end;

procedure TApplication.ControlDestroyed(Control: TControl);
begin
  if FMainForm = Control then FMainForm := nil;
  if FMouseControl = Control then FMouseControl := nil;
  if Screen.FActiveControl = Control then Screen.FActiveControl := nil;
  if Screen.FActiveCustomForm = Control then
  begin
    Screen.FActiveCustomForm := nil;
    Screen.FActiveForm := nil;
  end;
  if Screen.FFocusedForm = Control then Screen.FFocusedForm := nil;
  if FHintControl = Control then FHintControl := nil;
  Screen.UpdateLastActive;
end;

type
  PTopMostEnumInfo = ^TTopMostEnumInfo;
  TTopMostEnumInfo = record
    TopWindow: HWND;
    IncludeMain: Boolean;
  end;

function GetTopMostWindows(Handle: HWND; Info: Pointer): BOOL; stdcall;
begin
  Result := True;
  if GetWindow(Handle, GW_OWNER) = Application.Handle then
    if (GetWindowLong(Handle, GWL_EXSTYLE) and WS_EX_TOPMOST <> 0) and
      ((Application.MainForm = nil) or PTopMostEnumInfo(Info)^.IncludeMain or
      (Handle <> Application.MainForm.Handle)) then
      Application.FTopMostList.Add(Pointer(Handle))
    else
    begin
      PTopMostEnumInfo(Info)^.TopWindow := Handle;
      Result := False;
    end;
end;

procedure TApplication.DoNormalizeTopMosts(IncludeMain: Boolean);
var
  I: Integer;
  Info: TTopMostEnumInfo;
begin
  if Application.Handle <> 0 then
  begin
    if FTopMostLevel = 0 then
    begin
      Info.TopWindow := Handle;
      Info.IncludeMain := IncludeMain;
      EnumWindows(@GetTopMostWindows, Longint(@Info));
      if FTopMostList.Count <> 0 then
      begin
        Info.TopWindow := GetWindow(Info.TopWindow, GW_HWNDPREV);
        if GetWindowLong(Info.TopWindow, GWL_EXSTYLE) and WS_EX_TOPMOST <> 0 then
          Info.TopWindow := HWND_NOTOPMOST;
        for I := FTopMostList.Count - 1 downto 0 do
          SetWindowPos(HWND(FTopMostList[I]), Info.TopWindow, 0, 0, 0, 0,
            SWP_NOMOVE or SWP_NOSIZE or SWP_NOACTIVATE);
      end;
    end;
    Inc(FTopMostLevel);
  end;
end;

procedure TApplication.NormalizeTopMosts;
begin
  DoNormalizeTopMosts(False);
end;

procedure TApplication.NormalizeAllTopMosts;
begin
  DoNormalizeTopMosts(True);
end;

procedure TApplication.RestoreTopMosts;
var
  I: Integer;
begin
  if (Application.Handle <> 0) and (FTopMostLevel > 0) then
  begin
    Dec(FTopMostLevel);
    if FTopMostLevel = 0 then
    begin
      for I := FTopMostList.Count - 1 downto 0 do
        SetWindowPos(HWND(FTopMostList[I]), HWND_TOPMOST, 0, 0, 0, 0,
          SWP_NOMOVE or SWP_NOSIZE or SWP_NOACTIVATE);
      FTopMostList.Clear;
    end;
  end;
end;

function TApplication.IsRightToLeft: Boolean;
begin
  Result := SysLocale.MiddleEast and (FBiDiMode <> bdLeftToRight);
end;

function TApplication.UseRightToLeftReading: Boolean;
begin
  Result := SysLocale.MiddleEast and (FBiDiMode <> bdLeftToRight);
end;

function TApplication.UseRightToLeftAlignment: Boolean;
begin
  Result := SysLocale.MiddleEast and (FBiDiMode = bdRightToLeft);
end;

function TApplication.UseRightToLeftScrollBar: Boolean;
begin
  Result := SysLocale.MiddleEast and
            (FBiDiMode in [bdRightToLeft, bdRightToLeftNoAlign]);
end;

function TApplication.CheckIniChange(var Message: TMessage): Boolean;
begin
  Result := False;
  case Message.Msg of
    WM_WININICHANGE:
      begin
        if UpdateFormatSettings then
        begin
          SetThreadLocale(LOCALE_USER_DEFAULT);
          GetFormatSettings;
        end;
        if UpdateMetricSettings then
        begin
          Screen.GetMetricSettings;
          { Update the hint window font }
          if ShowHint then
          begin
            SetShowHint(False);
            SetShowHint(True);
          end;
        end;
      end;
  end;
end;

procedure TApplication.WndProc(var Message: TMessage);
type
  TInitTestLibrary = function(Size: DWord; PAutoClassInfo: Pointer): Boolean; stdcall;

var
  I: Integer;
  SaveFocus, TopWindow: HWnd;
  InitTestLibrary: TInitTestLibrary;

  procedure Default;
  begin
    with Message do
      Result := DefWindowProc(FHandle, Msg, WParam, LParam);
  end;

  procedure DrawAppIcon;
  var
    DC: HDC;
    PS: TPaintStruct;
  begin
    with Message do
    begin
      DC := BeginPaint(FHandle, PS);
      DrawIcon(DC, 0, 0, GetIconHandle);
      EndPaint(FHandle, PS);
    end;
  end;

begin
  try
    Message.Result := 0;
    for I := 0 to FWindowHooks.Count - 1 do
      if TWindowHook(FWindowHooks[I]^)(Message) then Exit;
    CheckIniChange(Message);
    with Message do
      case Msg of
        WM_SYSCOMMAND:
          case WParam and $FFF0 of
            SC_MINIMIZE: Minimize;
            SC_RESTORE: Restore;
          else
            Default;  
          end;
        WM_CLOSE:
          if MainForm <> nil then MainForm.Close;
{        WM_SYSCOLORCHANGE:
          if (Ctl3DHandle <> 0) and (Ctl3DHandle <> INVALID_HANDLE_VALUE) and
            (@Ctl3DColorChange <> nil) then
            Ctl3DColorChange;
}        WM_PAINT:
          if IsIconic(FHandle) then DrawAppIcon else Default;
        WM_ERASEBKGND:
          begin
            Message.Msg := WM_ICONERASEBKGND;
            Default;
          end;
        WM_QUERYDRAGICON:
          Result := GetIconHandle;
        WM_SETFOCUS:
          begin
            PostMessage(FHandle, CM_ENTER, 0, 0);
            Default;
          end;
        WM_ACTIVATEAPP:
          begin
            Default;
            FActive := TWMActivateApp(Message).Active;
            if TWMActivateApp(Message).Active then
            begin
              RestoreTopMosts;
              PostMessage(FHandle, CM_ACTIVATE, 0, 0)
            end
            else
            begin
              NormalizeTopMosts;
              PostMessage(FHandle, CM_DEACTIVATE, 0, 0);
            end;
          end;
        WM_ENABLE:
          if TWMEnable(Message).Enabled then
          begin
            RestoreTopMosts;
            if FWindowList <> nil then
            begin
              EnableTaskWindows(FWindowList);
              FWindowList := nil;
            end;
            Default;
          end else
          begin
            Default;
            if FWindowList = nil then
              FWindowList := DisableTaskWindows(Handle);
            NormalizeAllTopMosts;
          end;
        WM_CTLCOLORMSGBOX..WM_CTLCOLORSTATIC:
          Result := SendMessage(LParam, CN_BASE + Msg, WParam, LParam);
        WM_ENDSESSION: if TWMEndSession(Message).EndSession then FTerminate := True;
        WM_COPYDATA:
          if (PCopyDataStruct(Message.lParam)^.dwData = DWORD($DE534454)) and
            (FAllowTesting) then
            if FTestLib = 0 then
            begin
              FTestLib := SafeLoadLibrary('vcltest3.dll');
              if FTestLib <> 0 then
              begin
                Result := 0;
                @InitTestLibrary := GetProcAddress(FTestLib, 'RegisterAutomation');
                if @InitTestLibrary <> nil then
                  InitTestLibrary(PCopyDataStruct(Message.lParam)^.cbData,
                    PCopyDataStruct(Message.lParam)^.lpData);
              end
              else
              begin
                Result := GetLastError;
                FTestLib := 0;
              end;
            end
            else
              Result := 0;
        CM_ACTIONEXECUTE, CM_ACTIONUPDATE:
          Message.Result := Ord(DispatchAction(Message.Msg, TBasicAction(Message.LParam)));
        CM_APPKEYDOWN:
          if IsShortCut(TWMKey(Message)) then Result := 1;
        CM_APPSYSCOMMAND:
          if MainForm <> nil then
            with MainForm do
              if (Handle <> 0) and IsWindowEnabled(Handle) and
                IsWindowVisible(Handle) then
              begin
                FocusMessages := False;
                SaveFocus := GetFocus;
                Windows.SetFocus(Handle);
                Perform(WM_SYSCOMMAND, WParam, LParam);
                Windows.SetFocus(SaveFocus);
                FocusMessages := True;
                Result := 1;
              end;
        CM_ACTIVATE:
          if Assigned(FOnActivate) then FOnActivate(Self);
        CM_DEACTIVATE:
          if Assigned(FOnDeactivate) then FOnDeactivate(Self);
        CM_ENTER:
          if not IsIconic(FHandle) and (GetFocus = FHandle) then
          begin
            TopWindow := FindTopMostWindow(0);
            if TopWindow <> 0 then Windows.SetFocus(TopWindow);
          end;
        CM_INVOKEHELP: InvokeHelp(WParam, LParam);
        CM_WINDOWHOOK:
          if wParam = 0 then
            HookMainWindow(TWindowHook(Pointer(LParam)^)) else
            UnhookMainWindow(TWindowHook(Pointer(LParam)^));
        CM_DIALOGHANDLE:
          if wParam = 1 then
            Result := FDialogHandle
          else
            FDialogHandle := lParam;
        WM_SETTINGCHANGE:
          begin
            Mouse.SettingChanged(wParam);
            Default;
          end;
        WM_FONTCHANGE:
          begin
            Screen.ResetFonts;
            Default;
          end;
      else
        Default;
      end;
  except
    HandleException(Self);
  end;
end;

function TApplication.GetIconHandle: HICON;
begin
  Result := FIcon.Handle;
  if Result = 0 then Result := LoadIcon(0, IDI_APPLICATION);
end;

procedure TApplication.Minimize;
begin
  if not IsIconic(FHandle) then
  begin
    NormalizeTopMosts;
    SetActiveWindow(FHandle);
    if (MainForm <> nil) and (ShowMainForm or MainForm.Visible) then
    begin
      SetWindowPos(FHandle, MainForm.Handle, MainForm.Left, MainForm.Top,
        MainForm.Width, 0, SWP_SHOWWINDOW);
      DefWindowProc(FHandle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
    end else
      ShowWinNoAnimate(FHandle, SW_MINIMIZE);
    if Assigned(FOnMinimize) then FOnMinimize(Self);
  end;
end;

procedure TApplication.Restore;
begin
  if IsIconic(FHandle) then
  begin
    SetActiveWindow(FHandle);
    if (MainForm <> nil) and (ShowMainForm or MainForm.Visible) then
      DefWindowProc(FHandle, WM_SYSCOMMAND, SC_RESTORE, 0)
    else ShowWinNoAnimate(FHandle, SW_RESTORE);
    SetWindowPos(FHandle, 0, GetSystemMetrics(SM_CXSCREEN) div 2,
      GetSystemMetrics(SM_CYSCREEN) div 2, 0, 0, SWP_SHOWWINDOW);
    if (FMainForm <> nil) and (FMainForm.FWindowState = wsMinimized) and
      not FMainForm.Visible then
    begin
      FMainForm.WindowState := wsNormal;
      FMainForm.Show;
    end;
    RestoreTopMosts;
    if Screen.ActiveControl <> nil then
      Windows.SetFocus(Screen.ActiveControl.Handle);
    if Assigned(FOnRestore) then FOnRestore(Self);
  end;
end;

procedure TApplication.BringToFront;
var
  TopWindow: HWnd;
begin
  if Handle <> 0 then
  begin
    TopWindow := GetLastActivePopup(Handle);
    if (TopWindow <> 0) and (TopWindow <> Handle) and
      IsWindowVisible(TopWindow) and IsWindowEnabled(TopWindow) then
      SetForegroundWindow(TopWindow);
  end;
end;

function TApplication.GetTitle: string;
var
  Buffer: array[0..255] of Char;
begin
  if FHandleCreated then
    SetString(Result, Buffer, GetWindowText(FHandle, Buffer,
      SizeOf(Buffer))) else
    Result := FTitle;
end;

procedure TApplication.SetIcon(Value: TIcon);
begin
  FIcon.Assign(Value);
end;

procedure TApplication.SetBiDiMode(Value: TBiDiMode);
var
  Loop: Integer;
begin
  if FBiDiMode <> Value then
  begin
    FBiDiMode := Value;
    with Screen do
      for Loop := 0 to FormCount-1 do
        Forms[Loop].Perform(CM_PARENTBIDIMODECHANGED, 0, 0);
  end;
end;

procedure TApplication.SetTitle(const Value: string);
begin
  if FHandleCreated then
  begin
    if (GetTitle <> Value) or (FTitle <> '') then
    begin
      SetWindowText(FHandle, PChar(Value));
      FTitle := '';
    end;
  end
  else
    FTitle := Value;
end;

procedure TApplication.SetHandle(Value: HWnd);
begin
  if not FHandleCreated and (Value <> FHandle) then
  begin
    if FHandle <> 0 then UnhookMainWindow(CheckIniChange);
    FHandle := Value;
    if FHandle <> 0 then HookMainWindow(CheckIniChange);
  end;
end;

function TApplication.IsDlgMsg(var Msg: TMsg): Boolean;
begin
  Result := False;
  if FDialogHandle <> 0 then
    Result := IsDialogMessage(FDialogHandle, Msg);
end;

{
function TApplication.IsIdleMessage(const Msg: TMsg): Boolean;
const
  WM_SYSTIMER = $118;
begin
  with Msg do
    if (Message = WM_MOUSEMOVE) or (Message = WM_NCMOUSEMOVE) then
    begin
      if (Message = FLastMsg.Message) and (pt.X = FLastMsg.pt.X) and (pt.Y = FLastMsg.pt.Y) then
        Result := False
      else
      begin
        FLastMsg := Msg;
        Result := True;
      end;
    end
    else
      Result := Message <> WM_SYSTIMER;
end;
}
function TApplication.IsMDIMsg(var Msg: TMsg): Boolean;
begin
  Result := False;
  if (MainForm <> nil) and (MainForm.FormStyle = fsMDIForm) and
    (Screen.ActiveForm <> nil) and
    (Screen.ActiveForm.FormStyle = fsMDIChild) then
    Result := TranslateMDISysAccel(MainForm.ClientHandle, Msg);
end;

function TApplication.IsKeyMsg(var Msg: TMsg): Boolean;
var
  Wnd: HWND;
begin
  Result := False;
  with Msg do
    if (Message >= WM_KEYFIRST) and (Message <= WM_KEYLAST) then
    begin
      Wnd := GetCapture;
      if Wnd = 0 then
      begin
        Wnd := HWnd;
        if (MainForm <> nil) and (Wnd = MainForm.ClientHandle) then
          Wnd := MainForm.Handle
        else
        begin
          // Find the nearest VCL component.  Non-VCL windows won't know what
          // to do with CN_BASE offset messages anyway.
          // TOleControl.WndProc needs this for TranslateAccelerator
          while (FindControl(Wnd) = nil) and (Wnd <> 0) do
            Wnd := GetParent(Wnd);
          if Wnd = 0 then Wnd := HWnd;
        end;
        if SendMessage(Wnd, CN_BASE + Message, WParam, LParam) <> 0 then
          Result := True;
      end
      else if (LongWord(GetWindowLong(Wnd, GWL_HINSTANCE)) = HInstance) then
      begin
        if SendMessage(Wnd, CN_BASE + Message, WParam, LParam) <> 0 then
          Result := True;
      end;
    end;
end;

function TApplication.IsHintMsg(var Msg: TMsg): Boolean;
begin
  Result := False;
  if (FHintWindow <> nil) and FHintWindow.IsHintMsg(Msg) then
    CancelHint;
end;

function TApplication.IsShortCut(var Message: TWMKey): Boolean;
begin
  Result := False;
  if Assigned(FOnShortCut) then FOnShortCut(Message, Result);
  Result := Result or (MainForm <> nil) and IsWindowEnabled(MainForm.Handle) and
    MainForm.IsShortCut(TWMKey(Message))
end;

function TApplication.ProcessMessage(var Msg: TMsg): Boolean;
var
  Handled: Boolean;
begin
  Result := False;
  if PeekMessage(Msg, 0, 0, 0, PM_REMOVE) then
  begin
    Result := True;
    if Msg.Message <> WM_QUIT then
    begin
      Handled := False;
      if Assigned(FOnMessage) then FOnMessage(Msg, Handled);
      if not IsHintMsg(Msg) and not Handled and not IsMDIMsg(Msg) and
        not IsKeyMsg(Msg) and not IsDlgMsg(Msg) then
      begin
        TranslateMessage(Msg);
        DispatchMessage(Msg);
      end;
    end
    else
      FTerminate := True;
  end;
end;

procedure TApplication.ProcessMessages;
var
  Msg: TMsg;
begin
  while ProcessMessage(Msg) do {loop};
end;

procedure TApplication.HandleMessage;
var
  Msg: TMsg;
begin
  if not ProcessMessage(Msg) then Idle(Msg);
end;

procedure TApplication.HookMainWindow(Hook: TWindowHook);
var
  WindowHook: ^TWindowHook;
begin
  if not FHandleCreated then
  begin
    if FHandle <> 0 then
      SendMessage(FHandle, CM_WINDOWHOOK, 0, Longint(@@Hook));
  end else
  begin
    FWindowHooks.Expand;
    New(WindowHook);
    WindowHook^ := Hook;
    FWindowHooks.Add(WindowHook);
  end;
end;

procedure TApplication.UnhookMainWindow(Hook: TWindowHook);
var
  I: Integer;
  WindowHook: ^TWindowHook;
begin
  if not FHandleCreated then
  begin
    if FHandle <> 0 then
      SendMessage(FHandle, CM_WINDOWHOOK, 1, Longint(@@Hook));
  end else
    for I := 0 to FWindowHooks.Count - 1 do
    begin
      WindowHook := FWindowHooks[I];
      if (TMethod(WindowHook^).Code = TMethod(Hook).Code) and
        (TMethod(WindowHook^).Data = TMethod(Hook).Data) then
      begin
        Dispose(WindowHook);
        FWindowHooks.Delete(I);
        Break;
      end;
    end;
end;

procedure TApplication.Initialize;
begin
  if InitProc <> nil then TProcedure(InitProc);
end;

procedure TApplication.CreateForm(InstanceClass: TComponentClass; var Reference);
var
  Instance: TComponent;
begin
  Instance := TComponent(InstanceClass.NewInstance);
  TComponent(Reference) := Instance;
  try
    Instance.Create(Self);
  except
    TComponent(Reference) := nil;
    raise;
  end;
  if (FMainForm = nil) and (Instance is TForm) then
  begin
    TForm(Instance).HandleNeeded;
    FMainForm := TForm(Instance);
  end;
end;

procedure TApplication.Run;
begin
  FRunning := True;
  try
    AddExitProc(DoneApplication);
    if FMainForm <> nil then
    begin
      case CmdShow of
        SW_SHOWMINNOACTIVE: FMainForm.FWindowState := wsMinimized;
        SW_SHOWMAXIMIZED: MainForm.WindowState := wsMaximized;
      end;
      if FShowMainForm then
        if FMainForm.FWindowState = wsMinimized then
          Minimize else
          FMainForm.Visible := True;
      repeat
        HandleMessage
      until Terminated;
    end;
  finally
    FRunning := False;
  end;
end;

procedure TApplication.Terminate;
begin
  if CallTerminateProcs then PostQuitMessage(0);
end;

procedure TApplication.HandleException(Sender: TObject);
begin
  if GetCapture <> 0 then SendMessage(GetCapture, WM_CANCELMODE, 0, 0);
  if ExceptObject is Exception then
  begin
    if not (ExceptObject is EAbort) then
      if Assigned(FOnException) then
        FOnException(Sender, Exception(ExceptObject))
      else
        ShowException(Exception(ExceptObject));
  end else
    SysUtils.ShowException(ExceptObject, ExceptAddr);
end;

function TApplication.MessageBox(const Text, Caption: PChar; Flags: Longint): Integer;
var
  ActiveWindow: HWnd;
  WindowList: Pointer;
  MBMonitor, AppMonitor: HMonitor;
  MonInfo: TMonitorInfo;
  Rect: TRect;
begin
  ActiveWindow := GetActiveWindow;
  MBMonitor := MonitorFromWindow(ActiveWindow, MONITOR_DEFAULTTONEAREST);
  AppMonitor := MonitorFromWindow(Handle, MONITOR_DEFAULTTONEAREST);
  if MBMonitor <> AppMonitor then
  begin
    MonInfo.cbSize := Sizeof(TMonitorInfo);
    GetMonitorInfo(MBMonitor, @MonInfo);
    GetWindowRect(Handle, Rect);
    SetWindowPos(Handle, 0,
      MonInfo.rcMonitor.Left + ((MonInfo.rcMonitor.Right - MonInfo.rcMonitor.Left) div 2),
      MonInfo.rcMonitor.Top + ((MonInfo.rcMonitor.Bottom - MonInfo.rcMonitor.Top) div 2),
      0, 0, SWP_NOACTIVATE or SWP_NOREDRAW or SWP_NOSIZE or SWP_NOZORDER);
  end;
  WindowList := DisableTaskWindows(0);
  if UseRightToLeftReading then Flags := Flags or MB_RTLREADING;
  try
    Result := Windows.MessageBox(Handle, Text, Caption, Flags);
  finally
    if MBMonitor <> AppMonitor then
      SetWindowPos(Handle, 0,
        Rect.Left + ((Rect.Right - Rect.Left) div 2),
        Rect.Top + ((Rect.Bottom - Rect.Top) div 2),
        0, 0, SWP_NOACTIVATE or SWP_NOREDRAW or SWP_NOSIZE or SWP_NOZORDER);
    EnableTaskWindows(WindowList);
    SetActiveWindow(ActiveWindow);
  end;
end;

procedure TApplication.ShowException(E: Exception);
var
  Msg: string;
begin
  Msg := E.Message;
  if (Msg <> '') and (AnsiLastChar(Msg) > '.') then Msg := Msg + '.';
  MessageBox(PChar(Msg), PChar(GetTitle), MB_OK + MB_ICONSTOP);
end;

function TApplication.InvokeHelp(Command: Word; Data: Longint): Boolean;
var
  CallHelp: Boolean;
  HelpHandle: HWND;
  ActiveForm: TCustomForm;
begin
  Result := False;
  CallHelp := True;
  ActiveForm := Screen.ActiveCustomForm;
  if Assigned(ActiveForm) and Assigned(ActiveForm.FOnHelp) then
    Result := ActiveForm.FOnHelp(Command, Data, CallHelp)
  else if Assigned(FOnHelp) then
    Result := FOnHelp(Command, Data, CallHelp);
  if CallHelp then
    if Assigned(ActiveForm) and ActiveForm.HandleAllocated and (ActiveForm.FHelpFile <> '') then
    begin
      HelpHandle := ActiveForm.Handle;
      Result := WinHelp(HelpHandle, PChar(ActiveForm.FHelpFile), Command, Data);
    end
    else
    if FHelpFile <> '' then
    begin
      HelpHandle := Handle;
      if FMainForm <> nil then HelpHandle := FMainForm.Handle;
      Result := WinHelp(HelpHandle, PChar(FHelpFile), Command, Data);
    end else
      if not FHandleCreated then
        PostMessage(FHandle, CM_INVOKEHELP, Command, Data);
end;

function TApplication.HelpContext(Context: THelpContext): Boolean;
begin
  Result := InvokeHelp(HELP_CONTEXT, Context);
end;

function TApplication.HelpCommand(Command: Integer; Data: Longint): Boolean;
begin
  Result := InvokeHelp(Command, Data);
end;

function TApplication.HelpJump(const JumpID: string): Boolean;
var
  Command: array[0..255] of Char;
begin
  Result := True;
  if InvokeHelp(HELP_CONTENTS, 0) then
  begin
    StrLFmt(Command, SizeOf(Command) - 1, 'JumpID("","%s")', [JumpID]);
    Result := InvokeHelp(HELP_COMMAND, Longint(@Command));
  end;
end;

function TApplication.GetExeName: string;
begin
  Result := ParamStr(0);
end;

procedure TApplication.SetShowHint(Value: Boolean);
begin
  if FShowHint <> Value then
  begin
    FShowHint := Value;
    if FShowHint then
    begin
      FHintWindow := HintWindowClass.Create(Self);
      FHintWindow.Color := FHintColor;
    end else
    begin
      FHintWindow.Free;
      FHintWindow := nil;
    end;
  end;
end;

procedure TApplication.SetHintColor(Value: TColor);
begin
  if FHintColor <> Value then
  begin
    FHintColor := Value;
    if FHintWindow <> nil then
      FHintWindow.Color := FHintColor;
  end;
end;

procedure TApplication.DoActionIdle;
var
  I: Integer;
begin
  for I := 0 to Screen.CustomFormCount - 1 do
    with Screen.CustomForms[I] do
      if HandleAllocated and IsWindowVisible(Handle) and
        IsWindowEnabled(Handle) then
        UpdateActions;
end;

function TApplication.DoMouseIdle: TControl;
var
  CaptureControl: TControl;
  P: TPoint;
begin
  GetCursorPos(P);
  Result := FindDragTarget(P, True);
  if (Result <> nil) and (csDesigning in Result.ComponentState) then
    Result := nil;
  CaptureControl := GetCaptureControl;
  if FMouseControl <> Result then
  begin
    if ((FMouseControl <> nil) and (CaptureControl = nil)) or
      ((CaptureControl <> nil) and (FMouseControl = CaptureControl)) then
      FMouseControl.Perform(CM_MOUSELEAVE, 0, 0);
    FMouseControl := Result;
    if ((FMouseControl <> nil) and (CaptureControl = nil)) or
      ((CaptureControl <> nil) and (FMouseControl = CaptureControl)) then
      FMouseControl.Perform(CM_MOUSEENTER, 0, 0);
  end;
end;

procedure TApplication.Idle(const Msg: TMsg);
var
  Control: TControl;
  Done: Boolean;
begin
  Control := DoMouseIdle;
  if FShowHint and (FMouseControl = nil) then
    CancelHint;
  Application.Hint := GetLongHint(GetHint(Control));
  Done := True;
  try
    if Assigned(FOnIdle) then FOnIdle(Self, Done);
    if Done then DoActionIdle;
  except
    HandleException(Self);
  end;
  if Done then WaitMessage;
end;

procedure TApplication.NotifyForms(Msg: Word);
var
  I: Integer;
begin
  for I := 0 to Screen.FormCount - 1 do Screen.Forms[I].Perform(Msg, 0, 0);
end;

procedure TApplication.IconChanged(Sender: TObject);
begin
  if NewStyleControls then
  begin
    SendMessage(FHandle, WM_SETICON, 1, GetIconHandle);
    SetClassLong(FHandle, GCL_HICON, GetIconHandle);
  end
  else
    if IsIconic(FHandle) then InvalidateRect(FHandle, nil, True);
  NotifyForms(CM_ICONCHANGED);
end;

procedure TApplication.SetHint(const Value: string);
begin
  if FHint <> Value then
  begin
    FHint := Value;
    if Assigned(FOnHint) then
      FOnHint(Self)
    else
      { Fire THintAction to anyone interested }
      with THintAction.Create(Self) do
      begin
        Hint := Value;
        try
          Execute;
        finally
          Free;
        end;
      end;
  end;
end;

var
  AppVisible: Boolean = False;

procedure TApplication.UpdateVisible;

  procedure SetVisible(Value: Boolean);
  const
    ShowFlags: array[Boolean] of Word = (
      SWP_NOSIZE + SWP_NOMOVE + SWP_NOZORDER + SWP_NOACTIVATE + SWP_HIDEWINDOW,
      SWP_NOSIZE + SWP_NOMOVE + SWP_NOZORDER + SWP_NOACTIVATE + SWP_SHOWWINDOW);
  begin
    // Don't auto-update visibility if somebody else has hidden app window
    if (IsWindowVisible(FHandle) = AppVisible) and (AppVisible <> Value) then
    begin
      SetWindowPos(FHandle, 0, 0, 0, 0, 0, ShowFlags[Value]);
      AppVisible := Value;
    end;
  end;

var
  I: Integer;
  Form: TForm;
begin
  if FHandle <> 0 then
  begin
    for I := 0 to Screen.FormCount - 1 do
    begin
      Form := Screen.Forms[I];
      if Form.Visible and ((Form.ParentWindow = 0) or Form.HandleAllocated or
        not IsChild(Form.Handle, Form.ParentWindow)) then
      begin
        SetVisible(True);
        Exit;
      end;
    end;
    SetVisible(False);
  end;
end;

{ Hint window processing }

procedure TApplication.StartHintTimer(Value: Integer; TimerMode: TTimerMode);
begin
  StopHintTimer;
  FTimerHandle := SetTimer(0, 0, Value, @HintTimerProc);
  FTimerMode := TimerMode;
  if FTimerHandle = 0 then CancelHint;
end;

procedure TApplication.StopHintTimer;
begin
  if FTimerHandle <> 0 then
  begin
    KillTimer(0, FTimerHandle);
    FTimerHandle := 0;
  end;
end;

procedure TApplication.HintMouseMessage(Control: TControl; var Message: TMessage);
var
  NewHintControl: TControl;
  Pause: Integer;
  WasHintActive: Boolean;
  P: TPoint;
begin
  NewHintControl := GetHintControl(FindDragTarget(Control.ClientToScreen(SmallPointToPoint(TWMMouse(Message).Pos)), True));
  if (NewHintControl = nil) or not NewHintControl.ShowHint then
    CancelHint
  else
  begin
    if (NewHintControl <> FHintControl) or
      (not PtInRect(FHintCursorRect, Control.ClientToScreen(SmallPointToPoint(TWMMouse(Message).Pos)))) then
    begin
      WasHintActive := FHintActive;
      if WasHintActive then
        Pause := FHintShortPause else
        Pause := FHintPause;
      NewHintControl.Perform(CM_HINTSHOWPAUSE, Ord(WasHintActive), Longint(@Pause));
      { Show hint immediately if no pause }
      if WasHintActive and (Pause = 0) then
      begin
        FHintActive := WasHintActive;
        FHintControl := NewHintControl;
        GetCursorPos(P);
        ActivateHint(P);
      end
      else
      begin
        CancelHint;
        FHintActive := WasHintActive;
        FHintControl := NewHintControl;
        StartHintTimer(Pause, tmShow);
      end;
    end;
  end;
end;

procedure TApplication.HintTimerExpired;
var
  P: TPoint;
begin
  StopHintTimer;
  case FTimerMode of
    tmHide:
      HideHint;
    tmShow:
      begin
        GetCursorPos(P);
        ActivateHint(P);
      end;
  end;
end;

procedure TApplication.HideHint;
begin
  if (FHintWindow <> nil) and FHintWindow.HandleAllocated and
    IsWindowVisible(FHintWindow.Handle) then
    ShowWindow(FHintWindow.Handle, SW_HIDE);
end;

procedure TApplication.CancelHint;
begin
  if FHintControl <> nil then
  begin
    HideHint;
    FHintControl := nil;
    FHintActive := False;
    UnhookHintHooks;
    StopHintTimer;
  end;
end;

procedure TApplication.ActivateHint(CursorPos: TPoint);
var
  ClientOrigin, ParentOrigin: TPoint;
  HintInfo: THintInfo;
  CanShow: Boolean;
  HintWinRect: TRect;

  { Return number of scanlines between the scanline containing cursor hotspot
    and the last scanline included in the cursor mask. }
  function GetCursorHeightMargin: Integer;
  var
    IconInfo: TIconInfo;
    BitmapInfoSize, BitmapBitsSize, ImageSize: DWORD;
    Bitmap: PBitmapInfoHeader;
    Bits: Pointer;
    BytesPerScanline: Integer;

      function FindScanline(Source: Pointer; MaxLen: Cardinal;
        Value: Cardinal): Cardinal; assembler;
      asm
              PUSH    ECX
              MOV     ECX,EDX
              MOV     EDX,EDI
              MOV     EDI,EAX
              POP     EAX
              REPE    SCASB
              MOV     EAX,ECX
              MOV     EDI,EDX
      end;

  begin
    { Default value is entire icon height }
    Result := GetSystemMetrics(SM_CYCURSOR);
    if GetIconInfo(GetCursor, IconInfo) then
    try
      GetDIBSizes(IconInfo.hbmMask, BitmapInfoSize, BitmapBitsSize);
      Bitmap := AllocMem(DWORD(BitmapInfoSize) + BitmapBitsSize);
      try
      Bits := Pointer(DWORD(Bitmap) + BitmapInfoSize);
      if GetDIB(IconInfo.hbmMask, 0, Bitmap^, Bits^) and
        (Bitmap^.biBitCount = 1) then
      begin
        { Point Bits to the end of this bottom-up bitmap }
        with Bitmap^ do
        begin
          BytesPerScanline := ((biWidth * biBitCount + 31) and not 31) div 8;
          ImageSize := biWidth * BytesPerScanline;
          Bits := Pointer(DWORD(Bits) + BitmapBitsSize - ImageSize);
          { Use the width to determine the height since another mask bitmap
            may immediately follow }
          Result := FindScanline(Bits, ImageSize, $FF);
          { In case the and mask is blank, look for an empty scanline in the
            xor mask. }
          if (Result = 0) and (biHeight >= 2 * biWidth) then
            Result := FindScanline(Pointer(DWORD(Bits) - ImageSize),
            ImageSize, $00);
          Result := Result div BytesPerScanline;
        end;
        Dec(Result, IconInfo.yHotSpot);
      end;
      finally
        FreeMem(Bitmap, BitmapInfoSize + BitmapBitsSize);
      end;
    finally
      if IconInfo.hbmColor <> 0 then DeleteObject(IconInfo.hbmColor);
      if IconInfo.hbmMask <> 0 then DeleteObject(IconInfo.hbmMask);
    end;
  end;

  procedure ValidateHintWindow(HintClass: THintWindowClass);
  begin
    if HintClass = nil then HintClass := HintWindowClass;
    if (FHintWindow = nil) or (FHintWindow.ClassType <> HintClass) then
    begin
      FHintWindow.Free;
      FHintWindow := HintClass.Create(Self);
    end;
  end;

begin
  FHintActive := False;
  if FShowHint and (FHintControl <> nil) and ForegroundTask and
    (FHintControl = GetHintControl(FindDragTarget(CursorPos, True))) then
  begin
    HintInfo.HintControl := FHintControl;
    HintInfo.HintPos := CursorPos;
    Inc(HintInfo.HintPos.Y, GetCursorHeightMargin);
    HintInfo.HintMaxWidth := Screen.Width;
    HintInfo.HintColor := FHintColor;
    HintInfo.CursorRect := FHintControl.BoundsRect;
    ClientOrigin := FHintControl.ClientOrigin;
    ParentOrigin.X := 0;
    ParentOrigin.Y := 0;
    if FHintControl.Parent <> nil then
      ParentOrigin := FHintControl.Parent.ClientOrigin
    else if (FHintControl is TWinControl) and
      (TWinControl(FHintControl).ParentWindow <> 0) then
      Windows.ClientToScreen(TWinControl(FHintControl).ParentWindow, ParentOrigin);
    OffsetRect(HintInfo.CursorRect, ParentOrigin.X - ClientOrigin.X,
      ParentOrigin.Y - ClientOrigin.Y);
    HintInfo.CursorPos := FHintControl.ScreenToClient(CursorPos);
    HintInfo.HintStr := GetShortHint(GetHint(FHintControl));
    HintInfo.ReshowTimeout := 0;
    HintInfo.HideTimeout := FHintHidePause;
    HintInfo.HintWindowClass := HintWindowClass;
    HintInfo.HintData := nil;
    CanShow := FHintControl.Perform(CM_HINTSHOW, 0, Longint(@HintInfo)) = 0;
    if CanShow and Assigned(FOnShowHint) then
      FOnShowHint(HintInfo.HintStr, CanShow, HintInfo);
    FHintActive := CanShow and (FHintControl <> nil);
    if FHintActive and (HintInfo.HintStr <> '') then
    begin
      ValidateHintWindow(HintInfo.HintWindowClass);
      { make the hint have the same BiDiMode as the activating control }
      FHintWindow.BiDiMode := FHintControl.BiDiMode;
      { calculate the width of the hint based on HintStr and MaxWidth }
      with HintInfo do
        HintWinRect := FHintWindow.CalcHintRect(HintMaxWidth, HintStr, HintData);
      OffsetRect(HintWinRect, HintInfo.HintPos.X, HintInfo.HintPos.Y);
      if FHintWindow.UseRightToLeftAlignment then
        with HintWinRect do
        begin
          Dec(Left, FHintWindow.Canvas.TextWidth(HintInfo.HintStr) + 5);
          Dec(Right, FHintWindow.Canvas.TextWidth(HintInfo.HintStr) + 5);
        end;

      { Convert the client's rect to screen coordinates }
      with HintInfo do
      begin
        FHintCursorRect.TopLeft := FHintControl.ClientToScreen(CursorRect.TopLeft);
        FHintCursorRect.BottomRight := FHintControl.ClientToScreen(CursorRect.BottomRight);
      end;

      FHintWindow.Color := HintInfo.HintColor;
      FHintWindow.ActivateHintData(HintWinRect, HintInfo.HintStr, HintInfo.HintData);
      HookHintHooks;
      if HintInfo.ReshowTimeout > 0 then
        StartHintTimer(HintInfo.ReshowTimeout, tmShow)
      else StartHintTimer(HintInfo.HideTimeout, tmHide);
      Exit;
    end;
  end;
  if HintInfo.ReshowTimeout > 0 then
    StartHintTimer(HintInfo.ReshowTimeout, tmShow)
  else CancelHint;
end;

function TApplication.GetCurrentHelpFile: string;
var
  ActiveForm: TCustomForm;
begin
  ActiveForm := Screen.ActiveCustomForm;
  if Assigned(ActiveForm) and (ActiveForm.FHelpFile <> '') then
    Result := ActiveForm.HelpFile
  else
    Result := HelpFile;
end;

function TApplication.GetDialogHandle: HWND;
begin
  if not FHandleCreated then
    Result := SendMessage(Handle, CM_DIALOGHANDLE, 1, 0)
  else
    Result := FDialogHandle;
end;

procedure TApplication.SetDialogHandle(Value: HWND);
begin
  if not FHandleCreated then
    SendMessage(Handle, CM_DIALOGHANDLE, 0, Value);
  FDialogHandle := Value;
end;

function TApplication.DispatchAction(Msg: Longint; Action: TBasicAction): Boolean;
var
  Form: TCustomForm;
begin
  Form := Screen.ActiveForm;
  Result := (Form <> nil) and (Form.Perform(Msg, 0, Longint(Action)) = 1) or
    (MainForm <> Form) and (MainForm <> nil) and
    (MainForm.Perform(Msg, 0, Longint(Action)) = 1);
  { Disable action if no "user" handler is available }
  if not Result and (Action is TCustomAction) and TCustomAction(Action).Enabled and
     TCustomAction(Action).DisableIfNoHandler then
    TCustomAction(Action).Enabled := Assigned(Action.OnExecute);
end;

function TApplication.ExecuteAction(Action: TBasicAction): Boolean;
begin
  Result := False;
  if Assigned(FOnActionExecute) then FOnActionExecute(Action, Result);
end;

function TApplication.UpdateAction(Action: TBasicAction): Boolean;
begin
  Result := False;
  if Assigned(FOnActionUpdate) then FOnActionUpdate(Action, Result);
end;

initialization
  Classes.FindGlobalComponent := FindGlobalComponent;

finalization
  if Application <> nil then DoneApplication;
  if HintDoneEvent <> 0 then CloseHandle(HintDoneEvent);

end.
