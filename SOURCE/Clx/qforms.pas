{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QForms;

{$P+,S-,W-,R-,T-,H+,X+}

interface

uses
{$IFDEF LINUX}
  Xlib,
{$ENDIF}
{$IFDEF MSWINDOWS}
  Windows, Messages,
{$ENDIF}
  Qt, QTypes, SysUtils, Classes, Types, QGraphics, QControls, QMenus,
  QActnList, QStyle, HelpIntfs;

const
  QEventType_CMDestroyWidget = QEventType(Integer(QEventType_ClxBase) + $01);
  QEventType_CMQuit = QEventType(Integer(QEventType_ClxBase) + $02);
  QEventType_CMRelease = QEventType(Integer(QEventType_ClxBase) + $03);
  QEventType_CMScrolled = QEventType(Integer(QEventType_ClxBase) + $04);

type
  { forward declarations }

  TScrollingWidget = class;
  TCustomForm = class;
  TForm = class;

{ TControlScrollBar }

  TScrollBarKind = (sbHorizontal, sbVertical);
  TScrollBarInc = 1..32767;

  TControlScrollBar = class(TPersistent)
  private
    FControl: TScrollingWidget;
    FIncrement: TScrollBarInc;
    FPageIncrement: TScrollBarInc;
    FPosition: Integer;
    FRange: Integer;
    FKind: TScrollBarKind;
    FMargin: Word;
    FVisible: Boolean;
    FTracking: Boolean;
    FScaled: Boolean;
    FColor: TColor;
    FParentColor: Boolean;
    FUpdateNeeded: Boolean;
    FHandle: QScrollBarH;
    FHooks: QScrollBar_hookH;
    constructor Create(AControl: TScrollingWidget; AKind: TScrollBarKind);
    function CalcAutoRange: Integer;
    procedure DoSetRange(Value: Integer);
    function GetScrollPos: Integer;
    function HandleAllocated: Boolean;
    procedure SetColor(Value: TColor);
    procedure SetParentColor(Value: Boolean);
    procedure SetPosition(const Value: Integer);
    procedure SetRange(const Value: Integer);
    procedure SetVisible(const Value: Boolean);
    function IsRangeStored: Boolean;
    procedure Update;
    procedure SetIncrement(const Value: TScrollBarInc);
    procedure SetMargin(const Value: Word);
    procedure SetHandle(const Value: QScrollBarH);
    procedure SetTracking(const Value: Boolean);
  protected
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; cdecl;
  public
    procedure Assign(Source: TPersistent); override;
    function IsScrollBarVisible: Boolean;
    property Kind: TScrollBarKind read FKind;
    property Handle: QScrollBarH read FHandle write SetHandle;
    property ScrollPos: Integer read GetScrollPos;
  published
    property Color: TColor read FColor write SetColor default clBase;
    property Increment: TScrollBarInc read FIncrement write SetIncrement default 8;
    property Margin: Word read FMargin write SetMargin default 0;
    property ParentColor: Boolean read FParentColor write SetParentColor default True;
{$IFDEF MSWINDOWS}
    { Range must be published before Position }
    property Range: Integer read FRange write SetRange stored IsRangeStored default 0;
{$ENDIF}    
    property Position: Integer read FPosition write SetPosition default 0;
{$IFDEF LINUX}
    property Range: Integer read FRange write SetRange stored IsRangeStored default 0;
{$ENDIF}
    property Tracking: Boolean read FTracking write SetTracking default True;
    property Visible: Boolean read FVisible write SetVisible default True;
  end;

{ TScrollingWidget }

  TScrollingWidget = class(TFrameControl)
  private
    FHorzScrollBar: TControlScrollBar;
    FVertScrollBar: TControlScrollBar;
    FAutoScroll: Boolean;
    FIgnoreMoves: Boolean;
    FAutoRangeCount: Integer;
    FOldScrollPos: TSize;
    FUpdatingScrollBars: Boolean;
    FViewportHandle: QWidgetH;
    FViewportHook: QWidget_HookH;
    function CalcAutoRange: TSize;
    procedure ContentsMovingHook(x, y: Integer) cdecl;
    procedure ScaleScrollBars(MV, DV, MH, DH: Integer);
    procedure ScrollBarGeometryHook(sb: QScrollBarH; var x, y, w, h: Integer) cdecl;
    procedure SetAutoScroll(const Value: Boolean);
    procedure SetHorzScrollBar(const Value: TControlScrollBar);
    procedure SetVertScrollBar(const Value: TControlScrollBar);
    procedure UpdateScrollBars;
    function GetHandle: QOpenScrollViewH;
  protected
    procedure AdjustScrollRange(Kind: TScrollBarKind; var ARange: Integer); virtual;
    procedure AdjustClientRect(var Rect: TRect); override;
    procedure AlignControls(AControl: TControl; var ARect: TRect); override;
    function AutoScrollEnabled: Boolean; virtual;
    procedure AutoScrollInView(AControl: TControl); virtual;
    procedure ChangeScale(MV, DV, MH, DH: Integer); override;
    procedure ColorChanged; override;
    procedure ControlsListChanging(Control: TControl; Inserting: Boolean); override;
    procedure CreateWidget; override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    function GetAlignedPaintDevice: QPaintDeviceH; override;
    function GetChildHandle: QWidgetH; override;
    function GetClientOrigin: TPoint; override;
    function GetClientRect: TRect; override;
    function GetPaintDevice: QPaintDeviceH; override;
    procedure HookEvents; override;
    procedure InitWidget; override;
    procedure PaletteChanged(Sender: TObject); override;
    procedure Resize; override;
    procedure ScrollBarSize(ScrollBar: TControlScrollBar; var Position, Extent: Integer); virtual;
    procedure ScrollBarVisibleChanged(Sender: TControlScrollBar); virtual;
    function ViewportHandle: QWidgetH;
    function ViewportRect: TRect; override;
    procedure WidgetDestroyed; override;
    function WidgetFlags: Integer; override;
    property AutoScroll: Boolean read FAutoScroll write SetAutoScroll default True;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure DisableAutoRange;
    procedure EnableAutoRange;
    procedure ScrollBy(DeltaX, DeltaY: Integer); override;
    procedure ScrollInView(AControl: TControl);
    property BorderStyle default bsSunkenPanel;
    property Handle: QOpenScrollViewH read GetHandle;
  published
{$IFDEF MSWINDOWS}
    property VertScrollBar: TControlScrollBar read FVertScrollBar write SetVertScrollBar;
{$ENDIF}
    property HorzScrollBar: TControlScrollBar read FHorzScrollBar write SetHorzScrollBar;
{$IFDEF LINUX}
    property VertScrollBar: TControlScrollBar read FVertScrollBar write SetVertScrollBar;
{$ENDIF}
  end;

  TScrollingWinControl = TScrollingWidget; { Provided to simplify VCL source sharing }

{ TScrollBox }

  TScrollBox = class(TScrollingWidget)
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Align;
    property Anchors;
    property AutoScroll;
    property BorderStyle default bsSunken3d;
    property Color nodefault;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnClick;
    property OnConstrainedResize;
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
    property OnMouseWheel;
    property OnMouseWheelDown;
    property OnMouseWheelUp;
    property OnResize;
    property OnStartDrag;
  end;

{ TCustomFrame }

  TCustomFrame = class(TScrollingWidget)
  private
    procedure AddActionList(ActionList: TCustomActionList);
    procedure RemoveActionList(ActionList: TCustomActionList);
  protected
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure InitWidget; override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    property BorderStyle default bsNone;
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
    property BorderStyle;
    property Color nodefault;
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
    property TabStop;
    property Visible;
    property OnClick;
    property OnConstrainedResize;
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
    property OnMouseWheel;
    property OnMouseWheelDown;
    property OnMouseWheelUp;
    property OnResize;
    property OnStartDrag;
  end;

{ IDesignerHook }

  IDesignerHook = interface(IDesignerNotify)
    ['{ABBE7256-5495-11D1-9FB5-0020AF3D82DA}']
    function GetRoot: TComponent;
    function GetCustomForm: TCustomForm;
    function IsDesignEvent(Sender: TWidgetControl; SenderHandle: QObjectH;
      Event: QEventH): Boolean;
    procedure ControlPaintRequest(Control: TControl);
    procedure PaintGrid;
    procedure ValidateRename(AComponent: TComponent; const CurName, NewName: string);
    function UniqueName(const BaseName: string): string;
    property Form: TCustomForm read GetCustomForm;
    property Root: TComponent read GetRoot;
  end;

{ TCustomForm }

  TBorderIcon = (biSystemMenu, biMinimize, biMaximize, biHelp);
  TBorderIcons = set of TBorderIcon;
  TFormBorderStyle = (fbsNone, fbsSingle, fbsSizeable, fbsDialog, fbsToolWindow,
    fbsSizeToolWin);
  TFormStyle = (fsNormal, fsMDIChild, fsMDIForm, fsStayOnTop);
  TPosition = (poDesigned, poDefault, poDefaultPosOnly, poDefaultSizeOnly,
    poScreenCenter, poDesktopCenter, poMainFormCenter, poOwnerFormCenter);
  TWindowState = (wsNormal, wsMinimized, wsMaximized);
  TCloseAction = (caNone, caHide, caFree, caMinimize);
  TShowAction = (saIgnore, saRestore, saMinimize, saMaximize);
  TCloseEvent = procedure(Sender: TObject; var Action: TCloseAction) of object;
  TCloseQueryEvent = procedure(Sender: TObject;
    var CanClose: Boolean) of object;
  TModalResult = Low(Integer)..High(Integer);
  TFormState = set of (fsCreating, fsVisible, fsShowing, fsModal,
    fsActivated);
  TShortCutEvent = procedure(Key: Integer; Shift: TShiftState; var Handled: Boolean) of object;
   THelpEvent = function(HelpType: THelpType; HelpContext: THelpContext; 
                         const HelpKeyword: String; const HelpFile: String; 
                         var Handled: Boolean): Boolean of object;

  TCustomForm = class(TScrollingWidget)
  private
    FActiveControl: TWidgetControl;
    FFocusedControl: TWidgetControl;
    FBorderIcons: TBorderIcons;
    FActive: Boolean;
    FKeyPreview: Boolean;
    FDropTarget: Boolean;
    FShown: Boolean;
    FDesignerHook: IDesignerHook;
    FMenu: TMainMenu;
    FModalResult: TModalResult;
    FBorderStyle: TFormBorderStyle;
    FCanvas: TControlCanvas;
    FClientHeight: Integer;
    FClientWidth: Integer;
    FPixelsPerInch: Integer;
    FTextHeight: Integer;
    FTextWidth: Integer;
    FOnClose: TCloseEvent;
    FOnCloseQuery: TCloseQueryEvent;
    FOnHelp: THelpEvent;
    FOnCreate: TNotifyEvent;
    FOnLoaded: TNotifyEvent;
    FOnPaint: TNotifyEvent;
    FOnActivate: TNotifyEvent;
    FOnShortCut: TShortCutEvent;
    FOnShow: TNotifyEvent;
    FOnDeactivate: TNotifyEvent;
    FOnHide: TNotifyEvent;
    FOnDestroy: TNotifyEvent;
    FFormStyle: TFormStyle;
    FPosition: TPosition;
    FWindowState: TWindowState;
    FSizeGrip: Boolean;
    FGripper: QSizeGripH;
    FMenuHeight: Integer;
    FClientHandle: QWorkspaceH;
    FClientHooks: QWorkspace_hookH;
    FMDIParent: TForm;
    FMDIChildList: TList;
    FIcon: TIcon;
    procedure CheckGripper;
    function GetCanvas: TCanvas;
    function GetPixelsPerInch: Integer;
    function GetScaled: Boolean;
    function IsClientSizeStored: Boolean;
    function IsFormSizeStored: Boolean;
    procedure SetActiveControl(const Control: TWidgetControl);
    procedure SetClientHeight(Value: Integer);
    procedure SetClientWidth(Value: Integer);
    procedure SetDesignerHook(const Value: IDesignerHook);
    procedure SetMenu(const Value: TMainMenu);
    procedure SetPixelsPerInch(const Value: Integer);
    procedure SetScaled(const Value: Boolean);
    procedure SetVisible(Value: Boolean);
    procedure SetWidgetFocus;
    function IsForm: Boolean;
    procedure SetBorderStyle(const Value: TFormBorderStyle);
    procedure SetBorderIcons(const Value: TBorderIcons);
    procedure SetFormStyle(const Value: TFormStyle);
    procedure IgnoreIdent(Reader: TReader);
    procedure SetPosition(const Value: TPosition);
    procedure SetModalResult(const Value: TModalResult);
    procedure SetWindowState(const Value: TWindowState);
    procedure ShowWindowState;
    procedure SetMDIParent(const Value: TForm);
    function MDIChildList: TList;
    procedure WorkspaceNeeded;
    function GetMDIChildCount: Integer;
    function GetMDIChildren(I: Integer): TForm;
    procedure RemoveMDIChild(AForm: TCustomForm);
    procedure AppendMDIChild(AForm: TCustomForm);
    function GetClientHandle: QWorkspaceH;
    function GetActiveMDIChild: TForm;
    procedure SetIcon(const Value: TIcon);
    procedure MergeMenu(MergeState: Boolean);
    function GetTextHeight: Integer;
    function GetTextWidth: Integer;
    procedure ReadTextHeight(Reader: TReader);
    procedure ReadTextWidth(Reader: TReader);
    procedure WriteTextHeight(Writer: TWriter);
    procedure WriteTextWidth(Writer: TWriter);
    procedure WritePixelsPerInch(Writer: TWriter);
    procedure MDIChildActivated(w: QWidgetH); cdecl;
  protected
    FActionLists: TList;
    FFormState: TFormState;
    function ActionExecute(var BasicAction : TBasicAction): Boolean; dynamic;
    function ActionUpdate(var BasicAction : TBasicAction): Boolean; dynamic;
    procedure Activate; dynamic;
    procedure ActiveChanged; dynamic;
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    procedure BeginAutoDrag; override;
    procedure ChangeScale(MV, DV, MH, DH: Integer); override;
    procedure ColorChanged; override;
    procedure ControlsListChanging(Control: TControl; Inserting: Boolean); override;
    procedure CreateWidget; override;
    procedure Deactivate; dynamic;
    procedure DefineProperties(Filer: TFiler); override;
    procedure DoClose(var Action: TCloseAction); dynamic;
    procedure DoCreate; virtual;
    procedure DoDestroy; virtual;
    procedure DoHide; dynamic;
    procedure DoLoaded; dynamic;
    procedure DoShow; dynamic;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure FontChanged; override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    function GetClientRect: TRect; override;
    function GetClientOrigin: TPoint; override;
    function GetPaintDevice: QPaintDeviceH; override;
    function GetParentWidget: QWidgetH; override;
    function HandleCreateException: Boolean; dynamic;
    procedure IconChanged(Sender: TObject); virtual;
    procedure InitWidget; override;
    procedure Loaded; override;
    function MDIChildTop: Integer;
    function MDIChildLeft: Integer;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure Painting(Sender: QObjectH; EventRegion: QRegionH); override;
    procedure Paint; dynamic;
    procedure ParentFontChanged; override;
    function QueryInterface(const IID: TGUID; out Obj): HResult; override;
    procedure ReadState(Reader: TReader); override;
    procedure Resize; override;
    procedure SetChildOrder(Child: TComponent; Order: Integer); override;
    procedure SetInitialBounds; override;
    procedure SetParent(const AParent: TWidgetControl); override;
    procedure ShowingChanged; override;
    procedure UpdateActions; virtual;
    procedure ValidateRename(AComponent: TComponent;
      const CurName, NewName: string); override;
    function ViewportRect: TRect; override;
    procedure VisibleChanging; override;
    function WantKey(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; override;
    procedure WidgetDestroyed; override;
    function WidgetFlags: Integer; override;
    property ActiveMDIChild: TForm read GetActiveMDIChild;
    property BorderIcons: TBorderIcons read FBorderIcons write SetBorderIcons stored IsForm
      default [biSystemMenu, biMinimize, biMaximize];
    property BorderStyle: TFormBorderStyle read FBorderStyle write SetBorderStyle
      stored IsForm default fbsSizeable;
    property ClientHandle: QWorkspaceH read GetClientHandle;
    property ClientHeight write SetClientHeight stored IsClientSizeStored;
    property ClientWidth write SetClientWidth stored IsClientSizeStored;
    property FormStyle: TFormStyle read FFormStyle write SetFormStyle
      stored IsForm default fsNormal;
    property Height stored IsFormSizeStored;
    property Icon: TIcon read FIcon write SetIcon;
    property MDIChildCount: Integer read GetMDIChildCount;
    property MDIChildren[I: Integer]: TForm read GetMDIChildren;
    property MDIParent: TForm read FMDIParent write SetMDIParent;
    property PixelsPerInch: Integer read GetPixelsPerInch write SetPixelsPerInch
      stored False;
    property Position: TPosition read FPosition write SetPosition default poDesigned;
    property Scaled: Boolean read GetScaled write SetScaled default True;
    property SizeGrip: Boolean read FSizeGrip write FSizeGrip default True;
    property Visible write SetVisible default False;
    property Width stored IsFormSizeStored;
    property OnActivate: TNotifyEvent read FOnActivate write FOnActivate;
    property OnClose: TCloseEvent read FOnClose write FOnClose;
    property OnCloseQuery: TCloseQueryEvent read FOnCloseQuery write FOnCloseQuery;
    property OnCreate: TNotifyEvent read FOnCreate write FOnCreate;
    property OnDeactivate: TNotifyEvent read FOnDeactivate write FOnDeactivate;
    property OnDestroy: TNotifyEvent read FOnDestroy write FOnDestroy;
    property OnHelp: THelpEvent read FOnHelp write FOnHelp;
    property OnHide: TNotifyEvent read FOnHide write FOnHide;
    property OnLoaded: TNotifyEvent read FOnLoaded write FOnLoaded;
    property OnPaint: TNotifyEvent read FOnPaint write FOnPaint;
    property OnShortCut: TShortCutEvent read FOnShortCut write FOnShortCut;
    property OnShow: TNotifyEvent read FOnShow write FOnShow;
  public
    constructor Create(AOwner: TComponent); override;
    constructor CreateNew(AOwner: TComponent; Dummy: Integer = 0); virtual;
    destructor Destroy; override;
    procedure AfterConstruction; override;
    procedure BeforeDestruction; override;
    procedure Close;
    function CloseQuery: Boolean; virtual;
    procedure DefocusControl(Control: TWidgetControl; Removing: Boolean);
    procedure FocusControl(Control: TWidgetControl);
    procedure Hide;
    procedure InvokeHelp; override;
    function IsShortCut(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; dynamic;
    procedure Release;
    procedure SetFocus; override;
    function SetFocusedControl(Control: TWidgetControl): Boolean; virtual;
    procedure Show;
    function ShowModal: Integer; virtual;
    property Action;
    property Active: Boolean read FActive default True;
    property ActiveControl: TWidgetControl read FActiveControl write SetActiveControl;
    property Canvas: TCanvas read GetCanvas;
    property Caption;
    property Color nodefault;
    property DesignerHook: IDesignerHook read FDesignerHook write SetDesignerHook;
    property DropTarget: Boolean read FDropTarget write FDropTarget;
    property FocusedControl: TWidgetControl read FFocusedControl;
    property Font;
    property FormState: TFormState read FFormState;
    property HelpFile;
    property KeyPreview: Boolean read FKeyPreview write FKeyPreview default False;
    property Menu: TMainMenu read FMenu write SetMenu;
    property ModalResult: TModalResult read FModalResult write SetModalResult;
    property WindowState: TWindowState read FWindowState write SetWindowState
      stored IsForm default wsNormal;
  end;

  TCustomFormClass = class of TCustomForm;

{ TForm }

  TForm = class(TCustomForm)
  public
    procedure Cascade;
    procedure Next;
    procedure Previous;
    procedure Tile;
    property ActiveMDIChild;
    property ClientHandle;
    property MDIChildCount;
    property MDIChildren;
  published
    property Action;
    property ActiveControl;
    property Anchors;
    property AutoScroll;
    property Bitmap;
    property BorderIcons;
    property BorderStyle;
    property Caption;
    property ClientHeight;
    property ClientWidth;
    property Color;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property FormStyle;
    property Height;
    property HelpFile;
    property HelpKeyword;
    property HorzScrollBar;
    property Icon;
    property KeyPreview;
    property Menu;
    property ParentFont;
    property PixelsPerInch;
    property PopupMenu;
    property Position;
    property Scaled;
    property ShowHint;
    property VertScrollBar; 
    property Visible;
    property Width;
    property WindowState;
    property OnActivate;
    property OnClick;
    property OnClose;
    property OnCloseQuery;
    property OnConstrainedResize;
    property OnContextPopup;
    property OnCreate;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnDeactivate;
    property OnDestroy;
    property OnHelp;
    property OnHide;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnLoaded;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnMouseWheel;
    property OnMouseWheelDown;
    property OnMouseWheelUp;
    property OnPaint;
    property OnResize;
    property OnShow;
    property OnShortCut;
  end;

  TFormClass = class of TForm;

{ TScreen }

  PCursorRec = ^TCursorRec;
  TCursorRec = record
    Next: PCursorRec;
    Index: Integer;
    Handle: QCursorH;
  end;

  TScreen = class(TComponent)
  private
    FCursorList: PCursorRec;
    FPixelsPerInch: Integer;
    FCursor: TCursor;
    FCursorCount: Integer;
    FOnActiveControlChange: TNotifyEvent;
    FOnActiveFormChange: TNotifyEvent;
    FActiveControl: TWidgetControl;
    FSaveFocusedList: TList;
    FForms: TList;
    FCustomForms: TList;
    FDataModules: TList;
    FActiveCustomForm: TCustomForm;
    FActiveForm: TForm;
    FLastActiveControl: TWidgetControl;
    FLastActiveCustomForm: TCustomForm;
    FFocusedForm: TCustomForm;
    FHintFont: TFont;
    FDefaultCursor: QCursorH;
    FFonts: TStrings;
    procedure AddDataModule(DataModule: TDataModule);
    procedure AddForm(AForm: TCustomForm);
    procedure CreateCursors;
    procedure DeleteCursor(Index: Integer);
    function GetCursors(Index: Integer): QCursorH;
    function GetCustomFormCount: Integer;
    function GetCustomForms(Index: Integer): TCustomForm;
    function GetDataModule(Index: Integer): TDataModule;
    function GetDataModuleCount: Integer;
    function GetFonts: TStrings;
    function GetForm(Index: Integer): TForm;
    function GetFormCount: Integer;
    function GetPixelsPerInch: Integer;
    function GetHintFont: TFont;
    procedure InternalHintFontChanged(Sender: TObject);
    procedure InsertCursor(Index: Integer; Handle: QCursorH);
    procedure RemoveDataModule(DataModule: TDataModule);
    procedure RemoveForm(AForm: TCustomForm);
    procedure SetCursor(const Value: TCursor);
    procedure SetCursors(Index: Integer; const Value: QCursorH);
    procedure SetHintFont(Value: TFont);
    procedure UpdateLastActive;
    function GetHeight: Integer;
    function GetWidth: Integer;
    function GetActiveWidget: QWidgetH;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property ActiveControl: TWidgetControl read FActiveControl;
    property ActiveCustomForm: TCustomForm read FActiveCustomForm;
    property ActiveForm: TForm read FActiveForm;
    property ActiveWidget: QWidgetH read GetActiveWidget;
    property Cursor: TCursor read FCursor write SetCursor;
    property Cursors[Index: Integer]: QCursorH read GetCursors write SetCursors;
    property CustomFormCount: Integer read GetCustomFormCount;
    property CustomForms[Index: Integer]: TCustomForm read GetCustomForms;
    property DataModuleCount: Integer read GetDataModuleCount;
    property DataModules[Index: Integer]: TDataModule read GetDataModule;
    property Fonts: TStrings read GetFonts;
    property FormCount: Integer read GetFormCount;
    property Forms[Index: Integer]: TForm read GetForm;
    property Height: Integer read GetHeight;
    property HintFont: TFont read GetHintFont write SetHintFont;
    property PixelsPerInch: Integer read GetPixelsPerInch;
    property Width: Integer read GetWidth;
    property OnActiveControlChange: TNotifyEvent
      read FOnActiveControlChange write FOnActiveControlChange;
    property OnActiveFormChange: TNotifyEvent
      read FOnActiveFormChange write FOnActiveFormChange;
  end;

{ TApplication }

  TTimerMode = (tmShow, tmHide);

  TEventEvent = procedure (Sender: QObjectH; Event: QEventH; var Handled: Boolean) of object;
  TExceptionEvent = procedure (Sender: TObject; E: Exception) of object;
  TIdleEvent = procedure (Sender: TObject; var Done: Boolean) of object;

  TMessageButton = (smbOK, smbCancel, smbYes, smbNo, smbAbort, smbRetry,
    smbIgnore);
  TMessageButtons = set of TMessageButton;
  TMessageStyle = (smsInformation, smsWarning, smsCritical);
  TOnHelpEvent = TNotifyEvent;

  TApplication = class(TComponent)
  private
    FHelpSystem: IHelpSystem;
    FArgv: PPChar;
    FTerminated: Boolean;
    FActive: Boolean;
    FShowMainForm: Boolean;
    FHandle: QApplicationH;
    FHintShortCuts: Boolean;
    FHooks: QObject_hookH;
    FOnException: TExceptionEvent;
    FMainForm: TCustomForm;
    FAppWidget: QWidgetH;
    FQtAccels: Boolean;
    FTitle: WideString;
    FHint: WideString;
    FHintColor: TColor;
    FHintControl: TControl;
    FHintCursorRect: TRect;
    FHintHidePause: Integer;
    FHintPause: Integer;
    FHintShortPause: Integer;
    FHintTimer: TComponent;
    FTimerMode: TTimerMode;
    FHintWindow: THintWindow;
    FIdleTimer: TComponent;
    FMouseControl: TControl;
    FPalette: TPalette;
    FStyle: TApplicationStyle;
    FFont: TFont;
    FOnIdle: TIdleEvent;
    FOnHint: TNotifyEvent;
    FOnDeactivate: TNotifyEvent;
    FOnActivate: TNotifyEvent;
    FOnEvent: TEventEvent;
    FOnActionExecute: TActionEvent;
    FOnActionUpdate: TActionEvent;
    FOnShortCut: TShortCutEvent;
    FOnShowHint: TShowHintEvent;
    FOnModalBegin: TNotifyEvent;
    FOnModalEnd: TNotifyEvent;
    FOldCursor: TCursor;
    FHelpFile: string;
    FHelpKey: Integer;
    FHelpKeyword: string;
    FHelpContext: THelpContext;
    FHelpType: THelpType;
    FOnHelp: THelpEvent;
    FOnMinimize: TNotifyEvent;
    FOnRestore: TNotifyEvent;
    FTopMostList: TList;
    FIcon: TIcon;
    FTopMostLevel: Integer;
    FModalLevel: Integer;
    FHintActive: Boolean;
    FShowHint: Boolean;
    FMinimized: Boolean;
    FMainFormSet: Boolean;
    FKeyState: TShiftState;
    function ExecuteActionNotification(Action: TBasicAction): Boolean;
    function UpdateActionNotification(Action: TBasicAction): Boolean;
    function DoMouseIdle: TControl;
    procedure DoActionIdle;
    procedure DoDeactivate;
    procedure DoActivate;
    procedure StyleChanged(Sender: TObject);
    procedure PaletteChanged(Sender: TObject);
    procedure SetHandle(const Value: QApplicationH);
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; cdecl;
    function GetDesktop: QWidgetH;
    function GetFont: TFont;
    procedure SetFont(Value : TFont);
    procedure InternalFontChanged(Sender: TObject);
    procedure HintTimerExpired;
    procedure LoadTranslator;
    procedure SetTitle(const Value: WideString);
    procedure SetHint(const Value: WideString);
    procedure SetHintColor(Value: TColor);
    procedure SetShowHint(Value: Boolean);
    procedure StartHintTimer(Value: Integer; TimerMode: TTimerMode);
    procedure StopHintTimer;
    procedure HintTimerProc(Sender: TObject);
    function GetStyle: TApplicationStyle;
    procedure SetStyle(const Value: TApplicationStyle);
    procedure Quit;
    procedure UpdateVisible;
    function GetCurrentHelpFile: string;
    function GetExeName: string;
    procedure SetIcon(const Value: TIcon);
    function GetTopMostList: TList;
{$IFDEF LINUX}
    function GetDisplay: PDisplay;
{$ENDIF}
    function GetActiveState: Boolean;
    function GetAppWidget: QWidgetH;
    procedure WakeMainThread(Sender: TObject);
  protected
    property AppWidget: QWidgetH read GetAppWidget;
    procedure CreateHandle;
    property Hooks: QObject_hookH read FHooks;
    procedure IconChanged(Sender: TObject); virtual;
    procedure Idle(Sender: TObject); dynamic;
    procedure SetHelpContext(const Value: THelpContext);
    procedure SetHelpKeyword(const Value: String);
    function ValidateHelpSystem: Boolean;
    property TopMostList: TList read GetTopMostList;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure ActivateHint(CursorPos: TPoint);
    procedure BringToFront;
    procedure CancelHint;
    procedure ControlDestroyed(Control: TControl);
    procedure CreateForm(InstanceClass: TComponentClass; var Reference);
    function ExecuteAction(Action: TBasicAction): Boolean; override;
    procedure HandleException(Sender: TObject);
    procedure HandleMessage;
    procedure HideHint;
    procedure HintMouseMessage(Control: TControl; Shift: TShiftState; X, Y: Integer);
    procedure HookSynchronizeWakeup;
    procedure Initialize;
    function IsShortCut(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean;
    procedure InvokeHelp;
    function ContextHelp(const HelpContext: THelpContext): Boolean;
    function KeywordHelp(const HelpKeyword: string): Boolean;
    function MessageBox(const Text: WideString; const Caption: WideString = '';
      Buttons: TMessageButtons = [smbOK]; Style: TMessageStyle = smsInformation;
      Default: TMessageButton = smbOK; Escape: TMessageButton = smbCancel): TMessageButton;
    procedure Minimize;
    procedure ModalStarted(Sender: TObject);
    procedure ModalFinished(Sender: TObject);
    procedure NormalizeTopMosts;
    procedure ProcessMessages;
    procedure Restore;
    procedure RestoreTopMosts;
    procedure Run;
    procedure ShowException(E: Exception);
    procedure Terminate;
    procedure UnhookSynchronizeWakeup;
    function UpdateAction(Action: TBasicAction): Boolean; override;
    property Active: Boolean read FActive;
    property CurrentHelpFile: string read GetCurrentHelpFile;
    property Desktop: QWidgetH read GetDesktop;
{$IFDEF LINUX}
    property Display: PDisplay read GetDisplay;
{$ENDIF}
    property EnableQtAccelerators: Boolean read FQtAccels write FQtAccels;
    property ExeName: string read GetExeName;
    property Font: TFont read GetFont write SetFont;
    property Handle: QApplicationH read FHandle write SetHandle;
    property HelpFile: string read FHelpFile write FHelpFile;
    property HelpKey: Integer read FHelpKey write FHelpKey default Key_F1;
    property HelpSystem: IHelpSystem read FHelpSystem;
    property HelpWord: string read FHelpKeyword write SetHelpKeyword;
    property HelpContext: THelpContext read FHelpContext write SetHelpContext;
    property HelpType: THelpType read FHelpType write FHelpType;
    property Hint: WideString read FHint write SetHint;
    property HintColor: TColor read FHintColor write SetHintColor;
    property HintHidePause: Integer read FHintHidePause write FHintHidePause;
    property HintPause: Integer read FHintPause write FHintPause;
    property HintShortCuts: Boolean read FHintShortCuts write FHintShortCuts;
    property HintShortPause: Integer read FHintShortPause write FHintShortPause;
    property Icon: TIcon read FIcon write SetIcon;
    property KeyState: TShiftState read FKeyState;
    property MainForm: TCustomForm read FMainForm;
    property Palette: TPalette read FPalette;
    property ShowHint: Boolean read FShowHint write SetShowHint default True;
    property ShowMainForm: Boolean read FShowMainForm write FShowMainForm;
    property Style: TApplicationStyle read GetStyle write SetStyle;
    property Terminated: Boolean read FTerminated;
    property Title: WideString read FTitle write SetTitle;
    property OnActionExecute: TActionEvent read FOnActionExecute write FOnActionExecute;
    property OnActionUpdate: TActionEvent read FOnActionUpdate write FOnActionUpdate;
    property OnActivate: TNotifyEvent read FOnActivate write FOnActivate;
    property OnDeactivate: TNotifyEvent read FOnDeactivate write FOnDeactivate;
    property OnEvent: TEventEvent read FOnEvent write FOnEvent;
    property OnException: TExceptionEvent read FOnException write FOnException;
    property OnHelp: THelpEvent read FOnHelp write FOnHelp;
    property OnHint: TNotifyEvent read FOnHint write FOnHint;
    property OnIdle: TIdleEvent read FOnIdle write FOnIdle;
    property OnMinimize: TNotifyEvent read FOnMinimize write FOnMinimize;
    property OnModalBegin: TNotifyEvent read FOnModalBegin write FOnModalBegin;
    property OnModalEnd: TNotifyEvent read FOnModalEnd write FOnModalEnd;
    property OnRestore: TNotifyEvent read FOnRestore write FOnRestore;
    property OnShowHint: TShowHintEvent read FOnShowHint write FOnShowHint;
    property OnShortCut: TShortCutEvent read FOnShortCut write FOnShortCut;
  end;

{ Global objects }

var
  Application: TApplication;
  Screen: TScreen;
  Mouse: TMouse;
  HintWindowClass: THintWindowClass = THintWindow;

function GetParentForm(Control: TControl): TCustomForm;
function IsAccel(VK: Word; const Str: WideString): Boolean;
function ValidParentForm(Control: TControl): TCustomForm;

{ Unsupported internal hooks - The following hooks are not supported and could
  be removed between versions and should not be used by applications }

type
  TFormWidgetCreatedHook = procedure (Form: TCustomForm);
var
  FormWidgetCreatedHook: TFormWidgetCreatedHook;

implementation

{$IFDEF LINUX}
uses
  Math, Libc, QConsts, QStdActns, QExtCtrls;
{$ENDIF}
{$IFDEF MSWINDOWS}
uses
  Math, QConsts, QStdActns, QExtCtrls;
{$ENDIF}

{$IF Declared(Xlib)}
var
  WMNET_Initialized: Boolean;
  WMNET_Supported: Boolean = True;
  _NET_SUPPORTED: Atom;
  _NET_WM_STATE: Atom;
  _NET_WM_STATE_MODAL: Atom;
  _NET_WM_STATE_STICKY: Atom;
  _NET_WM_STATE_MAXIMIZED_VERT: Atom;
  _NET_WM_STATE_MAXIMIZED_HORZ: Atom;
  RootWindow: Window;

const
  _NET_WM_STATE_REMOVE = 0;
  _NET_WM_STATE_ADD = 1;
  _NET_WM_STATE_TOGGLE = 2;

type
  TLongIntArray = array of LongInt;
  TLongInts = array[0..1000] of LongInt;
  PLongInts = ^TLongInts;

function GetLongIntProperties(W: Window; Prop: Atom): TLongIntArray;
const
  Increment = 100;
var
  Offset: Integer;
  PropType: Atom;
  PropFormat: Longint;
  Items: Cardinal;
  BytesLeft: Cardinal;
  Data: PLongInts;
  I: Integer;
begin
  Offset := 0;
  SetLength(Result, 0);
  BytesLeft := 0;
  repeat
    if XGetWindowProperty(QtDisplay, W, Prop, Offset, Increment, 0,
      AnyPropertyType, @PropType, @PropFormat, @Items, @BytesLeft,
      @Data) <> Success then
      Exit;
    if Data = nil then Exit;
    if PropFormat <> 32 then Exit;
    SetLength(Result, Length(Result) + Integer(Items));
    for I := 0 to Items - 1 do
      Result[I + Offset] := Data^[I];
    Inc(Offset, Items);
    XFree(Data);
  until BytesLeft = 0;
end;

function HasProperty(W: Window; Prop: Atom): Boolean;
var
  PropType: Atom;
  PropFormat: Longint;
  Items: Cardinal;
  BytesLeft: Cardinal;
  Data: PLongInts;
begin
  Data := nil;
  Result := XGetWindowProperty(QtDisplay, W, Prop, 0, 0, 0, AnyPropertyType,
    @PropType, @PropFormat, @Items, @BytesLeft, @Data) = Success;
  if Data <> nil then
    XFree(Data);
end;

procedure WMNET_Init;
begin
  if WMNET_Initialized then Exit;
  WMNET_Initialized := True;

  _NET_SUPPORTED := XInternAtom(QtDisplay, '_NET_SUPPORTED', 1);
  _NET_WM_STATE := XInternAtom(QtDisplay, '_NET_WM_STATE', 1);
  _NET_WM_STATE_MODAL := XInternAtom(QtDisplay, '_NET_WM_STATE_MODAL', 1);
  _NET_WM_STATE_STICKY := XInternAtom(QtDisplay, '_NET_WM_STATE_STICKY', 1);
  _NET_WM_STATE_MAXIMIZED_VERT := XInternAtom(QtDisplay, '_NET_WM_STATE_MAXIMIZED_VERT', 1);
  _NET_WM_STATE_MAXIMIZED_HORZ := XInternAtom(QtDisplay, '_NET_WM_STATE_MAXIMIZED_HORZ', 1);
  if _NET_WM_STATE_MAXIMIZED_HORZ = 0 then
    // Account for spelling error in KDE 2.0/kdecore's netwm.cpp file
    _NET_WM_STATE_MAXIMIZED_HORZ := XInternAtom(QtDisplay, '_NET_WM_STATE_MAXIMIZED_HORIZ', 1);
  { Not used yet
  _NET_WM_STATE_SHADED := XInternAtom(QtDisplay, '_NET_WM_STATE_SHADED', 1);
  _NET_WM_STATE_SKIP_TASKBAR := XInternAtom(QtDisplay, '_NET_WM_STATE_SKIP_TASKBAR', 1);
  _NET_WM_STATE_SKIP_PAGER := XInternAtom(QtDisplay, '_NET_WM_STATE_SKIP_PAGER', 1); }

  RootWindow := XRootWindow(QtDisplay, XDefaultScreen(QtDisplay));

  WMNET_Supported := (_NET_SUPPORTED <> 0) and
    (_NET_WM_STATE <> 0) and
    (_NET_WM_STATE_MODAL <> 0) and
    (_NET_WM_STATE_STICKY  <> 0) and
    (_NET_WM_STATE_MAXIMIZED_VERT <> 0) and
    (_NET_WM_STATE_MAXIMIZED_HORZ <> 0) and
    HasProperty(RootWindow, _NET_SUPPORTED);
end;


function WMNET_IsMaximized(W: Window): Boolean;
var
  Atoms: TLongIntArray;
  I: Integer;
begin
  WMNET_Init;
  SetLength(Atoms, 0);
  if WMNET_Supported then
  begin
    Result := True;
    Atoms := GetLongIntProperties(W, _NET_WM_STATE);
    for I := Low(Atoms) to High(Atoms) do
      if (Cardinal(Atoms[I]) = _NET_WM_STATE_MAXIMIZED_HORZ) or
        (Cardinal(Atoms[I]) = _NET_WM_STATE_MAXIMIZED_VERT) then
        Exit;

  end;
  Result := False;
end;

procedure WMNET_SetMaximized(W: Window; Value: Boolean);

  procedure SendMaxMessage(W: Window; Action: Longint);
  var
    ClientMessage: XClientMessageEvent;
  begin
    ClientMessage.xwindow := W;
    ClientMessage.xtype := Xlib.ClientMessage;
    ClientMessage.display := QtDisplay;
    ClientMessage.format := 32;
    ClientMessage.message_type := _NET_WM_STATE;
    ClientMessage.data.l[0] := Action;
    ClientMessage.data.l[1] := _NET_WM_STATE_MAXIMIZED_VERT;
    ClientMessage.data.l[2] := _NET_WM_STATE_MAXIMIZED_HORZ;
    ClientMessage.data.l[3] := 0;
    ClientMessage.data.l[4] := 0;
    XSendEvent(QtDisplay, RootWindow, 0, SubstructureRedirectMask,
      @ClientMessage);
  end;

begin
  WMNET_Init;
  if not WMNET_Supported then Exit;
  if Value <> WMNET_IsMaximized(W) then
  begin
    SendMaxMessage(W, _NET_WM_STATE_ADD);
    if not WMNET_IsMaximized(W) then
      // This would only be true if either the window manager says it understand
      // the _NET_xxx protocols but doesn't or we are using a buggy KWIN
      // (bug #15430) that shipped with KDE 2.0. If it is the buggy KWIN we can
      // set it on by using TOGGLE. If this doesn't work the window manager is
      // hopeless.
      SendMaxMessage(W, _NET_WM_STATE_TOGGLE);
  end
  else
  begin
    SendMaxMessage(W, _NET_WM_STATE_REMOVE);
    if WMNET_IsMaximized(W) then
      // This should only be true if we are using a buggy KWIN that shipped with
      // KDE 2.0. It is a known bug (#15430) which can be worked around by
      // using ADD which, oddly enough, toggles.
      SendMaxMessage(W, _NET_WM_STATE_ADD);
  end;
end;

function InternalIsMaximized(Handle: QWidgetH): Boolean;
begin
  Result := WMNET_Supported and WMNET_IsMaximized(QWidget_winId(Handle));
end;
{$IFEND}

{$IF Declared(Windows)}
function InternalIsMaximized(Handle: QWidgetH): Boolean;
begin
  Result := IsZoomed(QWidget_winId(Handle));
end;
{$IFEND}

type
  TOpenControl = class(TControl);
  TOpenWidgetControl = class(TWidgetControl);

const
  DefHintColor = clInfoBk;  { default hint window color }
  DefHintPause = 500;       { default pause before hint window displays (ms)}
  DefHintShortPause = 0;    { default reshow pause to 0, was DefHintPause div 10 }
  DefHintHidePause = DefHintPause * 5;
  DefCursorHeight = 20;

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
    raise EInvalidOperation.CreateResFmt(@SParentRequired, [Control.Name]);
end;

procedure DoneApplication;
begin
  with Application do
  begin
    FreeAndNil(FIdleTimer);
    ShowHint := False;
    Destroying;
    DestroyComponents;
  end;
end;

function IsAccel(VK: Word; const Str: WideString): Boolean;
var
  HotKey: WideString;
begin
  Result := False;
  HotKey := GetHotKey(Str);
  if HotKey <> '' then
    Result := WideCompareText(WideChar(VK), HotKey) = 0;
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

var
  FocusCount: Integer;

type
  TFormWidget = class(TWidgetControl);

{ TControlScrollBar }

constructor TControlScrollBar.Create(AControl: TScrollingWidget;
  AKind: TScrollBarKind);
begin
  inherited Create;
  FControl := AControl;
  FTracking := True;
  FKind := AKind;
  FPageIncrement := 80;
  FIncrement := FPageIncrement div 10;
  FVisible := True;
  FColor := clBase;
  FParentColor := True;
  FUpdateNeeded := True;
end;

procedure TControlScrollBar.Assign(Source: TPersistent);
begin
  if Source is TControlScrollBar then
  begin
    Visible := TControlScrollBar(Source).Visible;
    Range := TControlScrollBar(Source).Range;
    Position := TControlScrollBar(Source).Position;
    Increment := TControlScrollBar(Source).Increment;
    Color := TControlScrollBar(Source).Color;
    Margin := TControlScrollBar(Source).Margin;
    Tracking := TControlScrollBar(Source).Tracking;
  end
  else inherited Assign(Source);
end;

function TControlScrollBar.CalcAutoRange: Integer;
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
  Result := 0;
  if FControl.FAutoScroll then
  begin
    if FControl.AutoScrollEnabled then
    begin
      NewRange := 0;
      AlignMargin := 0;
      for I := 0 to FControl.ControlCount - 1 do
      begin
        if Kind = sbHorizontal then
          ProcessHorz(FControl.Controls[I]) else
          ProcessVert(FControl.Controls[I]);
      end;
      Result := NewRange + AlignMargin + Margin;
      FControl.AdjustScrollRange(Kind, NewRange);
      DoSetRange(Result);
    end
    else DoSetRange(0);
  end;
end;

procedure TControlScrollBar.DoSetRange(Value: Integer);
begin
  if FRange <> Value then
  begin
    FRange := Value;
    if FRange < 0 then FRange := 0;
    if FRange = 0 then FPosition := 0;
    FControl.UpdateScrollBars;
  end;
end;

function TControlScrollBar.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  Result := False;
  try
    case QEvent_type(Event) of
      QEventType_hide, QEventType_show:
        FControl.ScrollBarVisibleChanged(Self);
    end;
  except
    Application.HandleException(Self);
  end;
end;

function TControlScrollBar.GetScrollPos: Integer;
begin
  Result := 0;
  if Visible then Result := Position;
end;

function TControlScrollBar.HandleAllocated: Boolean;
begin
  Result := FHandle <> nil;
end;

function TControlScrollBar.IsRangeStored: Boolean;
begin
  Result := True;
end;

function TControlScrollBar.IsScrollBarVisible: Boolean;
begin
  Result := FVisible and (FHandle <> nil) and QWidget_isVisible(FHandle);
end;

procedure TControlScrollBar.SetColor(Value: TColor);
begin
  if FColor <> Value then
  begin
    FParentColor := False;
    FColor := Value;
    Update;
  end;
end;

procedure TControlScrollBar.SetHandle(const Value: QScrollBarH);
var
  Method: TMethod;
begin
  FHandle := Value;
  if FHandle = nil then
  begin
    QScrollBar_hook_destroy(FHooks);
    FHooks := nil;
  end
  else begin
    FHooks := QScrollBar_hook_create(FHandle);
    TEventFilterMethod(Method) := EventFilter;
    Qt_hook_hook_events(FHooks, Method);
    Update;
  end;
end;

procedure TControlScrollBar.SetIncrement(const Value: TScrollBarInc);
begin
  if FIncrement <> Value then
  begin
    FIncrement := Value;
    Update;
  end;
end;

procedure TControlScrollBar.SetMargin(const Value: Word);
begin
  if FMargin <> Value then
  begin
    FMargin := Value;
    FControl.UpdateScrollBars;
  end;
end;

procedure TControlScrollBar.SetParentColor(Value: Boolean);
begin
  if FParentColor <> Value then
  begin
    FParentColor := Value;
    if FParentColor then FColor := FControl.Color;
    Update;
  end;
end;

procedure TControlScrollBar.SetPosition(const Value: Integer);
{$IFDEF MSWINDOWS}
var
  V: Integer;
begin
  V := Value;
  if V < 0 then V := 0;
  if V > Range then V := Range;
  if (FPosition <> V) then
  begin
    FPosition := V;
    Update;
  end;
{$ENDIF}
{$IFDEF LINUX}
begin
  if (FPosition <> Value) then
  begin
    FPosition := Value;
    Update;
  end;
{$ENDIF}
end;

procedure TControlScrollBar.SetRange(const Value: Integer);
begin
  if FRange <> Value then
  begin
    if not (csLoading in FControl.ComponentState) then
      FControl.FAutoScroll := False;
    FScaled := True;
    DoSetRange(Value);
  end;
end;

procedure TControlScrollBar.SetTracking(const Value: Boolean);
begin
  if FTracking <> Value then
  begin
    FTracking := Value;
    Update;
  end;
end;

procedure TControlScrollBar.SetVisible(const Value: Boolean);
begin
  if FVisible <> Value then
  begin
    FVisible := Value;
    Update;
    FControl.ScrollBarVisibleChanged(Self);
  end;
end;

procedure TControlScrollBar.Update;
var
  QC: QColorH;
  AColor: TColor;
begin
  if HandleAllocated then
  begin
    case Kind of
      sbVertical:
        if not FVisible then
        begin
          QScrollView_setVScrollBarMode(FControl.Handle,
            QScrollViewScrollBarMode_AlwaysOff);
          Exit;
        end
        else
          QScrollView_setVScrollBarMode(FControl.Handle,
            QScrollViewScrollBarMode_Auto);
      sbHorizontal:
        if not FVisible then
        begin
          QScrollView_setHScrollBarMode(FControl.Handle,
            QScrollViewScrollBarMode_AlwaysOff);
          Exit;
        end
        else
          QScrollView_setHScrollBarMode(FControl.Handle,
            QScrollViewScrollBarMode_Auto);
    end;

    QScrollBar_setLineStep(Handle, FIncrement);
    QScrollBar_setValue(Handle, FPosition);
    QScrollBar_setTracking(Handle, FTracking);
    if FParentColor then AColor := FControl.Color else AColor := FColor;
    QC := QColor(AColor);
    try
      QWidget_setBackgroundColor(FHandle, QC);
    finally
      QColor_destroy(QC);
    end;
  end;
end;

{ TScrollingWidget }

type
  TScrollBarGeometry_Event = procedure(sb: QScrollBarH; var x, y, w, h: Integer) of object cdecl;

procedure TScrollingWidget.AdjustClientRect(var Rect: TRect);
begin
  Rect := Bounds(-HorzScrollBar.Position, -VertScrollBar.Position,
    Max(HorzScrollBar.Range, ClientWidth), Max(ClientHeight,
    VertScrollBar.Range));
  inherited AdjustClientRect(Rect);
end;

procedure TScrollingWidget.AdjustScrollRange(Kind: TScrollBarKind; var ARange: Integer);
begin
  { Notification }
end;

procedure TScrollingWidget.AlignControls(AControl: TControl;
  var ARect: TRect);

  procedure AdjustForScrollbars(ExpSize: TSize);
  var
    HVisibleChanged,
    VVisibleChanged,
    HNeedsVisible,
    VNeedsVisible: Boolean;
  begin
    HVisibleChanged := ((ExpSize.cx > ARect.Right) and not QWidget_isVisible(FHorzScrollBar.Handle))
      or ((ExpSize.cx < ARect.Right) and QWidget_isVisible(FHorzScrollBar.Handle));
    HNeedsVisible := (ExpSize.cx > ARect.Right) or QWidget_isVisible(FHorzScrollBar.Handle);
    VVisibleChanged := False;
    VNeedsVisible := False;

    if HVisibleChanged then
    begin
      if HNeedsVisible then
        Dec(ARect.Bottom, QWidget_height(FHorzScrollBar.Handle))
      else
        Inc(ARect.Bottom, QWidget_height(FHorzScrollBar.Handle));
      //update vertical visible state based on horizontal state changing.
      VVisibleChanged := ((ExpSize.cy > ARect.Bottom) and not QWidget_isVisible(FVertScrollBar.Handle))
        or ((ExpSize.cy < ARect.Bottom) and QWidget_isVisible(FVertScrollBar.Handle));
      VNeedsVisible := (ExpSize.cy > ARect.Bottom) or QWidget_isVisible(FVertScrollBar.Handle);
    end;

    VVisibleChanged := VVisibleChanged or (((ExpSize.cy > ARect.Bottom) and not QWidget_isVisible(FVertScrollBar.Handle))
        or ((ExpSize.cy < ARect.Bottom) and QWidget_isVisible(FVertScrollBar.Handle)));
    VNeedsVisible := VNeedsVisible or ((ExpSize.cy > ARect.Bottom) or QWidget_isVisible(FVertScrollBar.Handle));

    if VVisibleChanged then
    begin
      if VNeedsVisible then
        Dec(ARect.Right, QWidget_width(FVertScrollBar.Handle))
      else
        Inc(ARect.Right, QWidget_width(FVertScrollBar.Handle));
      end;
      //recompute Horizontal visible state because the vertical changed.
      if not HVisibleChanged then
      begin
        HVisibleChanged := ((ExpSize.cx > ARect.Right) and not QWidget_isVisible(FHorzScrollBar.Handle))
          or ((ExpSize.cx < ARect.Right) and QWidget_isVisible(FHorzScrollBar.Handle));
        HNeedsVisible := (ExpSize.cx > ARect.Right) or QWidget_isVisible(FHorzScrollBar.Handle);
        if HVisibleChanged then
          if HNeedsVisible then
            Dec(ARect.Bottom, QWidget_height(FHorzScrollBar.Handle))
          else
            Inc(ARect.Bottom, QWidget_height(FHorzScrollBar.Handle));
    end;
  end;


var
  ExpSize: TSize;
begin
  FUpdatingScrollBars := True;
  try
    ExpSize := CalcAutoRange;
    AdjustForScrollBars(ExpSize);
  finally
    FUpdatingScrollBars := False;
  end;
  UpdateScrollBars;
  inherited AlignControls(AControl, ARect);
end;

function TScrollingWidget.AutoScrollEnabled: Boolean;
begin
  Result := FAutoScroll;
end;

procedure TScrollingWidget.AutoScrollInView(AControl: TControl);
begin
  if (AControl <> nil) and (AControl <> Self) and not (csLoading in AControl.ComponentState) and
    not (csLoading in ComponentState) then
    ScrollInView(AControl);
end;

function TScrollingWidget.CalcAutoRange: TSize;
begin
  FillChar(Result, SizeOf(Result), 0);
  if FAutoRangeCount <= 0 then
  begin
    Result.cx := HorzScrollBar.CalcAutoRange;
    Result.cy := VertScrollBar.CalcAutoRange;
  end;
end;

procedure TScrollingWidget.ContentsMovingHook(x, y: Integer);
begin
  try
    if not FIgnoreMoves then
    begin
      ScrollControls(FOldScrollPos.cx - x, FOldScrollPos.cy - y,
        (Visible or ((csDesigning in ComponentState) and Showing)) and HandleAllocated);
      FOldScrollPos.cx := x;
      FOldScrollPos.cy := y;
{$IFDEF LINUX}
      if QWidget_isVisible(Handle) or not (csDesigning in ComponentState) then
      begin
{$ENDIF}
      VertScrollBar.FPosition := y;
      HorzScrollBar.FPosition := x;
{$IFDEF LINUX}
      end;
{$ENDIF}
      if csDesigning in ComponentState then
        QApplication_sendEvent(Handle, QCustomEvent_create(QEventType_CMScrolled, Self));
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TScrollingWidget.ChangeScale(MV, DV, MH, DH: Integer);
begin
  ScaleScrollBars(MV, DV, MH, DH);
  inherited ChangeScale(MV, DV, MH, DH);
end;

function TScrollingWidget.GetAlignedPaintDevice: QPaintDeviceH;
begin
  Result := QWidget_to_QPaintDevice(ViewportHandle);
end;

function TScrollingWidget.GetChildHandle: QWidgetH;
begin
  Result := ViewportHandle;
end;

procedure TScrollingWidget.ColorChanged;
begin
  inherited ColorChanged;
  VertScrollBar.Update;
  HorzScrollBar.Update;
end;

procedure TScrollingWidget.ControlsListChanging(Control: TControl;
  Inserting: Boolean);
var
  WasVisible: Boolean;
{$IFDEF MSWINDOWS}
  PrevBounds: TRect;
{$ENDIF}
begin
  inherited ControlsListChanging(Control, Inserting);
  if Control is TWidgetControl then
    if Inserting then
    begin
      HandleNeeded;
      WasVisible := Control.Visible;
      TWidgetControl(Control).ParentWidget := ChildHandle;
      Control.Visible := WasVisible;
{$IFDEF MSWINDOWS}
      PrevBounds := Control.BoundsRect;
{$ENDIF}
      QScrollView_addChild(Handle, TWidgetControl(Control).Handle,
        Control.Left, Control.Top);
{$IFDEF MSWINDOWS}
      Control.BoundsRect := PrevBounds;
{$ENDIF}
    end
    else
      QScrollView_removeChild(Handle, TWidgetControl(Control).Handle);
end;

constructor TScrollingWidget.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FHorzScrollBar := TControlScrollBar.Create(Self, sbHorizontal);
  FVertScrollBar := TControlScrollBar.Create(Self, sbVertical);
  FAutoScroll := True;
  Palette.ColorRole := crBackground;
  Palette.TextColorRole := crForeground;
  BorderStyle := bsSunken3d;
end;

procedure TScrollingWidget.CreateWidget;
var
  Method: TMethod;
begin
  TScrollBarGeometry_Event(Method) := ScrollBarGeometryHook;
  FHandle := QOpenScrollView_create(Method, ParentWidget, nil, WidgetFlags);
  FViewportHandle := QScrollView_viewport(Handle);
  QClxObjectMap_add(FViewportHandle, Integer(Self));
end;

destructor TScrollingWidget.Destroy;
begin
  FHorzScrollBar.Free;
  FVertScrollBar.Free;
  inherited Destroy;
end;

procedure TScrollingWidget.DisableAutoRange;
begin
  Inc(FAutoRangeCount);
end;

procedure TScrollingWidget.EnableAutoRange;
begin
  if FAutoRangeCount > 0 then
  begin
    Dec(FAutoRangeCount);
    if (FAutoRangeCount = 0) and (FHorzScrollBar.Visible or
      FVertScrollBar.Visible) then CalcAutoRange;
  end;
end;

function TScrollingWidget.EventFilter(Sender: QObjectH;
  Event: QEventH): Boolean;
var
  EventType: QEventType;
begin
  Result := False;
  EventType := QEvent_type(Event);
  if EventType = QEventType_LayoutHint then
  begin
    Result := True;
    Exit;
  end;
  if Sender = ViewportHandle then
  begin
    case EventType of
      QEventType_Resize,
      QEventType_Move: Exit;
    end;
  end;
  Result := inherited EventFilter(Sender, Event);
end;

function TScrollingWidget.GetPaintDevice: QPaintDeviceH;
begin
  Result := QWidget_to_QPaintDevice(ViewportHandle);
end;

procedure TScrollingWidget.HookEvents;
var
  Method: TMethod;
begin
  Hooks := QScrollView_hook_create(Handle);
  FViewportHook := QWidget_hook_create(ViewportHandle);
  QScrollView_contentsMoving_Event(Method) := ContentsMovingHook;
  QScrollView_hook_hook_contentsMoving(QScrollView_hookH(Hooks), Method);
  TEventFilterMethod(Method) := MainEventFilter;
  Qt_hook_hook_events(FViewportHook, Method);
  inherited HookEvents;
end;

procedure TScrollingWidget.InitWidget;
begin
  inherited InitWidget;
  FHorzScrollBar.Handle := QScrollView_horizontalScrollBar(Handle);
  FVertScrollBar.Handle := QScrollView_verticalScrollBar(Handle);
  FOldScrollPos.cx := HorzScrollBar.FPosition;
  FOldScrollPos.cy := VertScrollbar.FPosition;
  QWidget_setBackgroundMode(ViewportHandle, QWidgetBackgroundMode_PaletteBackground);
  QScrollView_setResizePolicy(Handle, QScrollViewResizePolicy_Manual);
  QWidget_setFocusPolicy(Handle, QWidgetFocusPolicy_NoFocus);
end;

procedure TScrollingWidget.PaletteChanged(Sender: TObject);
begin
  inherited;
  QWidget_setPalette(ViewportHandle, (Sender as TPalette).Handle, True);
end;

procedure TScrollingWidget.Resize;
begin
  FUpdatingScrollBars := True;
  try
    CalcAutoRange;
  finally
    FUpdatingScrollBars := False;
  end;
  UpdateScrollBars;
  inherited Resize;
end;

procedure TScrollingWidget.ScaleScrollBars(MV, DV, MH, DH: Integer);
begin
  if (MV <> DV) or (MH <> DH) then
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
      with HorzScrollBar do if FScaled then Range := MulDiv(Range, MH, DH);
      with VertScrollBar do if FScaled then Range := MulDiv(Range, MV, DV);
    end;
  end;
  HorzScrollBar.FScaled := False;
  VertScrollBar.FScaled := False;
end;

procedure TScrollingWidget.ScrollBarVisibleChanged(Sender: TControlScrollBar);
begin
  Realign;
end;

procedure TScrollingWidget.ScrollBy(DeltaX, DeltaY: Integer);
begin
  HorzScrollBar.Position := HorzScrollBar.Position + DeltaX;
  VertScrollBar.Position := VertScrollBar.Position + DeltaY;
end;

procedure TScrollingWidget.ScrollInView(AControl: TControl);
var
  Rect: TRect;
begin
  if (csDestroying in ComponentState) or (AControl = nil) then
    Exit;
  Rect := AControl.ClientRect;
  Dec(Rect.Left, HorzScrollBar.Margin);
  Inc(Rect.Right, HorzScrollBar.Margin);
  Dec(Rect.Top, VertScrollBar.Margin);
  Inc(Rect.Bottom, VertScrollBar.Margin);
{$IFDEF LINUX}
  if AControl is TFrameControl then
  begin
    QWidget_mapToGlobal(TFrameControl(AControl).Handle, @Rect.TopLeft, @Rect.TopLeft);
    QWidget_mapToGlobal(TFrameControl(AControl).Handle, @Rect.BottomRight, @Rect.BottomRight);
    Rect.TopLeft := ScreenToClient(Rect.TopLeft);
    Rect.BottomRight := ScreenToClient(Rect.BottomRight);
  end else
{$ENDIF}
  begin
    Rect.TopLeft := ScreenToClient(AControl.ClientToScreen(Rect.TopLeft));
    Rect.BottomRight := ScreenToClient(AControl.ClientToScreen(Rect.BottomRight));
  end;
  if Rect.Left + ViewportRect.Left < 0 then
    with HorzScrollBar do Position := Rect.Left
  else if Rect.Right > ClientWidth then
  begin
    if Rect.Right - Rect.Left > ClientWidth then
      Rect.Right := Rect.Left + ClientWidth;
    with HorzScrollBar do Position := Rect.Right - ClientWidth;
  end;
  if Rect.Top + ViewportRect.Top < 0 then
    with VertScrollBar do Position := Rect.Top
  else if Rect.Bottom > ClientHeight then
  begin
    if Rect.Bottom - Rect.Top > ClientHeight then
      Rect.Bottom := Rect.Top + ClientHeight;
    with VertScrollBar do Position := Rect.Bottom - ClientHeight;
  end;
end;

procedure TScrollingWidget.SetAutoScroll(const Value: Boolean);
begin
  if FAutoScroll <> Value then
  begin
    FAutoScroll := Value;
    if Value then CalcAutoRange else
    begin
      if not (csLoading in ComponentState) then
      begin
        HorzScrollBar.Range := 0;
        VertScrollBar.Range := 0;
      end;
    end;
  end;
end;

procedure TScrollingWidget.SetHorzScrollBar(const Value: TControlScrollBar);
begin
  FHorzScrollBar.Assign(Value);
end;

procedure TScrollingWidget.SetVertScrollBar(const Value: TControlScrollBar);
begin
  FVertScrollBar.Assign(Value);
end;

procedure TScrollingWidget.UpdateScrollBars;
begin
{$IFDEF MSWINDOWS}
  if (csReading in ComponentState) and not (csDesigning in ComponentState) then Exit;
{$ENDIF}
  if not FUpdatingScrollBars and HandleAllocated then
    try
      FUpdatingScrollBars := True;
      QScrollView_resizeContents(Handle, FHorzScrollBar.Range + FHorzScrollBar.Margin,
        FVertScrollBar.Range + FVertScrollBar.Margin);
      QScrollBar_setValue(VertScrollBar.Handle, VertScrollBar.FPosition);
      QScrollBar_setValue(HorzScrollBar.Handle, HorzScrollBar.FPosition);
    finally
      FUpdatingScrollBars := False;
    end;
end;

function TScrollingWidget.ViewportHandle: QWidgetH;
begin
  if not (csDestroying in ComponentState) then
    HandleNeeded;
  Result := FViewportHandle;
end;

function TScrollingWidget.ViewportRect: TRect;
var
  Offset: TPoint;
begin
  QWidget_geometry(ViewportHandle, @Result);
  Offset := ClientRect.TopLeft;
  QScrollView_contentsToViewport(Handle, @Offset, @Offset);
  OffsetRect(Result, Offset.X, Offset.Y);
end;

procedure TScrollingWidget.WidgetDestroyed;
begin
  QClxObjectMap_remove(FViewportHandle);
  QWidget_hook_destroy(FViewportHook);
  inherited WidgetDestroyed;
end;

function TScrollingWidget.WidgetFlags: Integer;
begin
  Result := inherited WidgetFlags or Integer(WidgetFlags_WResizeNoErase);
end;

function TScrollingWidget.GetClientRect: TRect;
begin
  Result := inherited GetClientRect;
  if QWidget_isVisible(FVertScrollBar.FHandle) then
//  if FVertScrollBar.IsScrollBarVisible then
    Dec(Result.Right, QWidget_width(FVertScrollBar.Handle));
  if QWidget_isVisible(FHorzScrollBar.FHandle) then
//  if FHorzScrollBar.IsScrollBarVisible then
    Dec(Result.Bottom, QWidget_height(FHorzScrollBar.Handle));
end;

function TScrollingWidget.GetHandle: QOpenScrollViewH;
begin
  HandleNeeded;
  Result := QOpenScrollViewH(FHandle);
end;

function TScrollingWidget.GetClientOrigin: TPoint;
var
  P: TPoint;
begin
  Result := inherited GetClientOrigin;
  P := ViewportRect.TopLeft;
  Result.X := Result.X + P.X;
  Result.Y := Result.Y + P.Y;
end;

procedure TScrollingWidget.ScrollBarGeometryHook(sb: QScrollBarH; var x, y,
  w, h: Integer);
begin
  try
    if sb = HorzScrollBar.Handle then
      ScrollBarSize(HorzScrollBar, x, w)
    else if
      sb = VertScrollBar.Handle then
        ScrollBarSize(VertScrollBar, y, h);
  except
    Application.HandleException(Self);
  end;
end;

procedure TScrollingWidget.ScrollBarSize(ScrollBar: TControlScrollBar;
  var Position, Extent: Integer);
begin
  { notification }
end;

{ TScrollBox }

constructor TScrollBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csAcceptsControls, csCaptureMouse, csClickEvents,
    csSetCaption, csDoubleClicks];
  Width := 185;
  Height := 41;
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
      raise EResNotFound.CreateResFmt(@SResNotFound, [ClassName]);
  end
  else
  begin
    Width := 320;
    Height := 240;
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

procedure TCustomFrame.InitWidget;
begin
  inherited;
  BorderStyle := bsNone;
end;

procedure TCustomFrame.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  case Operation of
    opInsert:
      if AComponent is TCustomActionList then
        AddActionList(TCustomActionList(AComponent));
    opRemove:
      if AComponent is TCustomActionList then
        RemoveActionList(TCustomActionList(AComponent));
  end;
end;

{ TCustomForm }

procedure TCustomForm.Activate;
begin
  if Assigned(FOnActivate) then FOnActivate(Self);
end;

procedure TCustomForm.ActiveChanged;
begin
  { Notification }
end;

procedure TCustomForm.AfterConstruction;
begin
  DoCreate;
  if fsActivated in FFormState then
  begin
    Activate;
    Exclude(FFormState, fsActivated);
  end;
  { Inherited needs to be called after all the other construction stuff gets done
    so that any events assigned in the form's oncreate can be called in the inherited method, 
    in this case OnResize }
  inherited AfterConstruction;
end;

procedure TCustomForm.BeforeDestruction;
begin
  inherited BeforeDestruction;
  GlobalNameSpace.BeginWrite;
  try
    Destroying;
    Screen.FSaveFocusedList.Remove(Self);
    RemoveFixupReferences(Self, '');
    DoDestroy;
  except
    GlobalNameSpace.EndWrite;
    raise;
  end;
end;

procedure TCustomForm.ChangeScale(MV, DV, MH, DH: Integer);
var
  PriorHeight: Integer;
begin
  ScaleScrollBars(MV, DV, MH, DH);
  ScaleControls(MV, DV, MH, DH);
  if IsClientSizeStored then
  begin
    PriorHeight := ClientHeight;
    ClientWidth := MulDiv(ClientWidth, MH, DH);
    ClientHeight := MulDiv(PriorHeight, MV, DV);
  end;
  Font.Size := MulDiv(Font.Size, MV, DV);
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
        else if CloseAction = caHide then
          Hide
        else if CloseAction = caMinimize then
          WindowState := wsMinimized
        else
          Release;
    end;
end;

function TCustomForm.CloseQuery: Boolean;
begin
  Result := True;
  if Assigned(FOnCloseQuery) then FOnCloseQuery(Self, Result);
end;

procedure TCustomForm.ControlsListChanging(Control: TControl; Inserting: Boolean);
var
  WasVisible: Boolean;
begin
  inherited ControlsListChanging(Control, Inserting);

  if not (csDesigning in ComponentState) and (FormStyle = fsMDIForm)
  and (Control.Align = alNone) then
  begin
    HandleNeeded;
    if Control is TWidgetControl then
      if Inserting then
      begin
        WasVisible := Control.Visible;
        TWidgetControl(Control).ParentWidget := FClientHandle;
        Control.Visible := WasVisible;
      end
      else
        TWidgetControl(Control).ParentWidget := nil;
  end
  else
    inherited ControlsListChanging(Control, Inserting);
end;

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
    end;
  finally
    GlobalNameSpace.EndWrite;
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
  FBorderIcons := [biSystemMenu, biMinimize, biMaximize];
  FBorderStyle := fbsSizeable;
  FFormStyle := fsNormal;
  FActive := True;
  FSizeGrip := True;
  FWindowState := wsNormal;
  FIcon := TIcon.Create;
  // Qt will scale the icon image, so default to a large size.
  FIcon.Width := 32;
  FIcon.Height := 32;
  FIcon.OnChange := IconChanged;
  FPixelsPerInch := Screen.PixelsPerInch;
  FCanvas := TControlCanvas.Create;
  FCanvas.Control := Self;
  Screen.AddForm(Self);
end;

procedure TCustomForm.Deactivate;
begin
  if Assigned(FOnDeactivate) then FOnDeactivate(Self);
end;

procedure TCustomForm.DefineProperties(Filer: TFiler);
begin
  inherited DefineProperties(Filer);
  Filer.DefineProperty('PixelsPerInch', nil, WritePixelsPerInch, True); { do not localize }
  Filer.DefineProperty('TextHeight', ReadTextHeight, WriteTextHeight, Scaled); { do not localize }
  Filer.DefineProperty('TextWidth', ReadTextWidth, WriteTextWidth, Scaled); { do not localize }
  { Silently ignore Windows properties  - this allows us to read in VCL .DFMs
    more easily }
  Filer.DefineProperty('OldCreateOrder', IgnoreIdent, nil, False); { do not localize }
end;

procedure TCustomForm.ReadTextHeight(Reader: TReader);
begin
  FTextHeight := Reader.ReadInteger;
end;

procedure TCustomForm.ReadTextWidth(Reader: TReader);
begin
  FTextWidth := Reader.ReadInteger;
end;

procedure TCustomForm.WritePixelsPerInch(Writer: TWriter);
begin
  Writer.WriteInteger(GetPixelsPerInch);
end;

procedure TCustomForm.WriteTextHeight(Writer: TWriter);
begin
  Writer.WriteInteger(GetTextHeight);
end;

procedure TCustomForm.WriteTextWidth(Writer: TWriter);
begin
  Writer.WriteInteger(GetTextWidth);
end;

function TCustomForm.GetTextHeight: Integer;
begin
  Result := Canvas.TextHeight('0');
end;

function TCustomForm.GetTextWidth: Integer;
const
  TestPhrase = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdedfghijklmnopqrstuvwxyz ' +
    'abcdedfghijklmnopqrstuvwxyz abcdedfghijklmnopqrstuvwxyz ' +
    'abcdedfghijklmnopqrstuvwxyz 0123456789';
begin
  Result := (Canvas.TextWidth(TestPhrase) + Length(TestPhrase) div 2)
    div Length(TestPhrase);
end;

procedure TCustomForm.DefocusControl(Control: TWidgetControl;
  Removing: Boolean);
begin
  if Removing and Control.ContainsControl(FFocusedControl) then
    FFocusedControl := Control.Parent;
  if Control.ContainsControl(FActiveControl) then SetActiveControl(nil);
end;

destructor TCustomForm.Destroy;
begin
  if not (csDestroying in ComponentState) then GlobalNameSpace.BeginWrite;
  try
    Screen.RemoveForm(Self);
  finally
    GlobalNameSpace.EndWrite;
  end;
  MergeMenu(False);
  if Assigned(FMenu) then FMenu.Merge(nil);
  if (FormStyle = fsMDIChild) and not (csDesigning in ComponentState) then
    MDIParent := nil;
  if Assigned(FMDIChildList) then
    FreeAndNil(FMDIChildList);
  FreeAndNil(FActionLists);
  FIcon.Free;
  inherited Destroy;
  // This must be freed after since we might get a paint message while we
  // are being destroyed.
  FCanvas.Free;
end;

procedure TCustomForm.DoClose(var Action: TCloseAction);
begin
  if Assigned(FOnClose) then FOnClose(Self, Action);
end;

procedure TCustomForm.DoCreate;
begin
  if Assigned(FOnCreate) then
  try
    FOnCreate(Self);
  except
    if not HandleCreateException then
      raise;
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

procedure TCustomForm.DoHide;
begin
  if Assigned(FOnHide) then
    FOnHide(Self);
  QWidget_hide(Handle);
end;

procedure TCustomForm.DoShow;
var
  I: Integer;
{$IFDEF MSWINDOWS}
  X, Y: Integer;
{$ENDIF}
begin
{$IFDEF MSWINDOWS}
  Y := VertScrollBar.Position;
  X := HorzScrollBar.Position;
{$ENDIF}
  ShowWindowState;
  if not FShown then
  begin
    // need to forcibly fix up Widgets' positions because of some
    // semantic differences between our scrolling and Qt's.
    FIgnoreMoves := True;
    try
      for I := 0 to ControlCount - 1 do
        if Controls[I] is TWidgetControl then
        with TWidgetControl(Controls[I]) do
        begin
{$IFDEF LINUX}
          Top := Top + VertScrollBar.Position;
          Left := Left + HorzScrollBar.Position;
{$ENDIF}
{$IFDEF MSWINDOWS}
          Top := Top + Y;
          Left := Left + X;
{$ENDIF}
        end;
{$IFDEF MSWINDOWS}
      VertScrollBar.Position := Y;
      HorzScrollBar.Position := X;
{$ENDIF}
    finally
      FShown := True;
      FIgnoreMoves := False;
    end;
  end;
  if Assigned(FOnShow) then
    FOnShow(Self);
end;

procedure TCustomForm.FocusControl(Control: TWidgetControl);
var
  WasActive: Boolean;
begin
  WasActive := FActive;
  SetActiveControl(Control);
  if not WasActive then SetFocus;
end;

function TCustomForm.GetCanvas: TCanvas;
begin
  Result := FCanvas;
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

function TCustomForm.GetPixelsPerInch: Integer;
begin
  if FPixelsPerInch <> 0 then
    Result := FPixelsPerInch
  else
    Result := Screen.PixelsPerInch;
end;

function TCustomForm.GetScaled: Boolean;
begin
  Result := FPixelsPerInch <> 0;
end;

procedure TCustomForm.Hide;
begin
  Visible := False;
  MergeMenu(False);
end;

procedure TCustomForm.IconChanged(Sender: TObject);
begin
  QWidget_setIcon(Handle, FIcon.Handle);
end;

procedure TCustomForm.SetIcon(const Value: TIcon);
begin
  FIcon.Assign(Value);
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

procedure TCustomForm.InvokeHelp;
var
  EventHandled: Boolean;
begin
  EventHandled := false;
  if Assigned(FOnHelp) then
    FOnHelp(HelpType, HelpContext, HelpKeyword, Application.CurrentHelpFile, EventHandled);
  if not EventHandled then
  begin
    if HelpType = htKeyword then Application.KeywordHelp(HelpKeyword);
    if HelpType = htContext then Application.ContextHelp(HelpContext);
  end;
end;

procedure TCustomForm.Loaded;
var
  Control: TWidgetControl;
begin
  inherited Loaded;         
  if FIcon.Empty then SetIcon(Application.Icon);
  if ActiveControl <> nil then
  begin
    Control := ActiveControl;
    FActiveControl := nil;
    if Control.CanFocus then SetActiveControl(Control);
  end else
    ActiveControl := FindNextControl(nil, True, True, False);
  DoLoaded;
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
      if MergeState then
        Merge(AMergeMenu)
      else
        Unmerge(AMergeMenu);
  end;
end;

procedure TCustomForm.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if FDesignerHook <> nil then
    FDesignerHook.Notification(AComponent, Operation);
  case Operation of
    opInsert:
        if AComponent is TCustomActionList then
        begin
          if FActionLists = nil then FActionLists := TList.Create;
          FActionLists.Add(AComponent);
        end
        else if not (csLoading in ComponentState) and (Menu = nil) and
          (AComponent.Owner = Self) and (AComponent is TMainMenu) then
          Menu := TMainMenu(AComponent);
    opRemove:
        if (FActionLists <> nil) and (AComponent is TCustomActionList) then
          FActionLists.Remove(AComponent)
        else
        if Menu = AComponent then Menu := nil;
  end;
end;

procedure TCustomForm.Painting(Sender: QObjectH; EventRegion: QRegionH);
begin
  inherited Painting(Sender, EventRegion);
  if FDesignerHook <> nil then
  begin
    TControlCanvas(FCanvas).StartPaint;
    try
      FDesignerHook.PaintGrid;
    finally
      TControlCanvas(FCanvas).StopPaint;
    end;
  end;
end;

procedure TCustomForm.Paint;
begin
  if Assigned(FOnPaint) then FOnPaint(Self);
end;

procedure TCustomForm.ReadState(Reader: TReader);
var
  NewTextWidth, NewTextHeight: Integer;
  Scaled: Boolean;
begin
  DisableAlign;
  try
    FClientWidth := 0;
    FClientHeight := 0;
    FTextHeight := 0;         
    FTextWidth := 0;
    Scaled := False;
    inherited ReadState(Reader);
    if (FPixelsPerInch <> 0) and (FTextHeight > 0) and (FTextWidth > 0) and
      not (csDesigning in ComponentState) then
    begin
      if (sfFont in ScalingFlags) and (FPixelsPerInch <> Screen.PixelsPerInch) then
        Font.Height := MulDiv(Font.Height, Screen.PixelsPerInch, FPixelsPerInch);
      FPixelsPerInch := Screen.PixelsPerInch;
      NewTextHeight := GetTextHeight;
      if FTextWidth = 0 then
      begin
        NewTextWidth := NewTextHeight;
        FTextWidth := FTextHeight;
      end
      else
        NewTextWidth := GetTextWidth;
      if (FTextWidth <> NewTextWidth) or (FTextHeight <> NewTextHeight) then
      begin
        Scaled := True;
        ScaleScrollBars(NewTextHeight, FTextHeight, NewTextWidth,
          FTextWidth);
        ScaleControls(NewTextHeight, FTextHeight, NewTextWidth,
          FTextWidth);
        if sfWidth in ScalingFlags then
          FClientWidth := MulDiv(FClientWidth, NewTextWidth, FTextWidth);
        if sfHeight in ScalingFlags then
          FClientHeight := MulDiv(FClientHeight, NewTextHeight, FTextHeight);
      end;
    end;
    if FClientWidth > 0 then
      inherited ClientWidth := FClientWidth;
    if FClientHeight > 0 then
      inherited ClientHeight := FClientHeight;
    ScalingFlags := [];
    if not Scaled then
    begin
      // Force all ScalingFlags to []
      ScaleScrollBars(1, 1, 1, 1);
      ScaleControls(1, 1, 1, 1);
    end;
  finally
    EnableAlign;
  end;
end;

procedure TCustomForm.Release;
begin
  QApplication_postEvent(Application.Handle, QCustomEvent_create(QEventType_CMRelease, Self));
end;

procedure TCustomForm.SetActiveControl(const Control: TWidgetControl);
var
  AName: string;
begin
  if FActiveControl <> Control then
  begin
    if not ((Control = nil) or (Control <> Self) and
      (GetParentForm(Control) = Self) and ((csLoading in ComponentState) or
        Control.CanFocus)) then
    begin
      if Control.Name <> '' then AName := Control.Name else AName := SUnnamed;
      raise EInvalidOperation.CreateFmt(SCannotFocus, [AName]);
    end;
    FActiveControl := Control;
    if not (csLoading in ComponentState) then
    begin
      if FActive then SetWidgetFocus;
      ActiveChanged;
    end;
  end;
end;

procedure TCustomForm.SetChildOrder(Child: TComponent; Order: Integer);
var
  I, J: Integer;
begin
  if Child is TControl then
    inherited
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

procedure TCustomForm.SetClientHeight(Value: Integer);
begin
  if csReadingState in ControlState then
  begin
    FClientHeight := Value;
    ScalingFlags := ScalingFlags + [sfHeight];
  end else inherited ClientHeight := Value;
end;

procedure TCustomForm.SetClientWidth(Value: Integer);
begin
  { emulate windows behavior where windows with frames 
	  cannot be smaller than the frame size. }
  if Value < 100 then Value := 100;
  if csReadingState in ControlState then
  begin
    FClientWidth := Value;
    ScalingFlags := ScalingFlags + [sfWidth];
  end else inherited ClientWidth := Value;
end;

procedure TCustomForm.SetDesignerHook(const Value: IDesignerHook);
begin
  FDesignerHook := Value;
end;

procedure TCustomForm.SetFocus;
var
  AName: string;
begin
  if not FActive then
  begin
    if not (Visible and Enabled) and not (csDesigning in ComponentState) then
    begin
      if Name <> '' then AName := Name else AName := SUnnamed;
      raise EInvalidOperation.CreateFmt(SCannotFocus, [AName]);
    end;
    SetWidgetFocus;
  end;
end;

function TCustomForm.SetFocusedControl(Control: TWidgetControl): Boolean;
var
  FocusForm: TCustomForm;
  TempControl: TWidgetControl;
  Count: Integer;
begin
  Result := False;
  Inc(FocusCount);
  Count := FocusCount;
  if FDesignerHook = nil then
    if Control <> Self then
      FActiveControl := Control
    else
      FActiveControl := nil;
  Screen.FActiveControl := Control;
  Screen.FActiveCustomForm := Self;
  Screen.FCustomForms.Remove(Self);
  Screen.FCustomForms.Insert(0, Self);
  if Self is TForm then
  begin
    if Assigned(Screen.FActiveForm) then
      Screen.FActiveForm.FActive := False;
    Screen.FActiveForm := TForm(Self);
    Screen.FActiveForm.FActive := True;
    Screen.FForms.Remove(Self);
    Screen.FForms.Insert(0, Self);
  end
  else
    Screen.FActiveForm := nil;
  if not (csFocusing in Control.ControlState) then
  begin
    Control.ControlState := Control.ControlState + [csFocusing];
    try
      if Screen.FFocusedForm <> Self then
      begin
        if Screen.FFocusedForm <> nil then
        begin
          FocusForm := Screen.FFocusedForm;
          Screen.FFocusedForm := nil;
          MergeMenu(False);
          FocusForm.Deactivate;
          if Count <> FocusCount then Exit;
        end;
        Screen.FFocusedForm := Self;
        MergeMenu(True);
        Activate;
        if Count <> FocusCount then Exit;
      end;
      if FFocusedControl = nil then FFocusedControl := Self;
      if FFocusedControl <> Control then
      begin
        TempControl := nil;
        while (FFocusedControl <> nil) and not
          FFocusedControl.ContainsControl(Control) do
        begin
          TempControl := FFocusedControl;
          FFocusedControl := FFocusedControl.Parent;
          TFormWidget(TempControl).DoExit;
          if FocusCount <> Count then Exit;
        end;
        while FFocusedControl <> Control do
        begin
          TempControl := Control;
          while TempControl.Parent <> FFocusedControl do
            TempControl := TempControl.Parent;
          FFocusedControl := TempControl;
          TFormWidget(TempControl).DoEnter;
          if Count <> FocusCount then Exit;
        end;
        { This loop is suspect. Should be sending some message that this code
          is attached to. (I know I wrote it, give me a break) - cpj }
        while TempControl <> nil do
        begin
          if TempControl is TScrollingWidget then
            TScrollingWidget(TempControl).AutoScrollInView(Control);
          TempControl := TempControl.Parent;
        end;
      end;
    finally
      Control.ControlState := Control.ControlState - [csFocusing];
    end;
    Screen.UpdateLastActive;
    Result := True;
  end;
end;

procedure TCustomForm.SetMenu(const Value: TMainMenu);
var
  I: Integer;
begin
  if Value <> nil then
    for I := 0 to Screen.FormCount - 1 do
      if (Screen.Forms[I].Menu = Value) and (Screen.Forms[I] <> Self) then
        raise EInvalidOperation.CreateFmt(sDuplicateMenus, [Value.Name]);
  if Value <> nil then Value.FreeNotification(Self);
  if (Menu <> nil) then
    Menu.SetForm(nil);
  FMenu := Value;
  if (Value <> nil) and ((csDesigning in ComponentState) or
   (BorderStyle <> fbsDialog)) then
  begin
    if not (Menu.AutoMerge or (FormStyle = fsMDIChild)) or
      (csDesigning in ComponentState) then
    begin
      if HandleAllocated then
        Value.SetForm(Self);
    end;
  end;
  if Active then
  begin
    MergeMenu(False);
    MergeMenu(True);
  end;
//  RefreshMDIMenu;
  if not (csDestroying in ComponentState) then
  begin
    Resize;
    Realign;
  end;
end;

procedure TCustomForm.SetParent(const AParent: TWidgetControl);
begin
  inherited SetParent(AParent);
end;

procedure TCustomForm.SetPixelsPerInch(const Value: Integer);
begin
  if (Value <> PixelsPerInch) and ((Value = 0) or (Value >= 36))
    and (not (csLoading in ComponentState) or (FPixelsPerInch <> 0)) then
    FPixelsPerInch := Value;
end;

procedure TCustomForm.SetScaled(const Value: Boolean);
begin
  if Value <> GetScaled then
  begin
    if Value then
      FPixelsPerInch := Screen.PixelsPerInch
    else
      FPixelsPerInch := 0;
  end;
end;

procedure TCustomForm.SetWidgetFocus;
var
  FocusControl: TWidgetControl;
begin
  if (FActiveControl <> nil) and (FDesignerHook = nil) then
    FocusControl := FActiveControl else
    FocusControl := Self;
  QWidget_setFocus(FocusControl.Handle);
  QWidget_setActiveWindow(FocusControl.Handle);
end;

procedure TCustomForm.SetVisible(Value: Boolean);
begin
  if fsCreating in FFormState then
    if Value then
      Include(FFormState, fsVisible) else
      Exclude(FFormState, fsVisible)
  else
    inherited Visible := Value;
end;

procedure TCustomForm.Show;
begin
  ModalResult := mrNone;
  Visible := True;
  Resize;
  BringToFront;
end;

{ ModalStack should be changed to be a threadvar if we start to allow multiple
  thread to go modal at the same time. }
var
  ModalStack: TCustomForm = nil;

function TCustomForm.ShowModal: Integer;
var
  OldModalStack: TCustomForm;
  CaptureControl: TControl;
  SaveFocusCount: Integer;
  SaveCursor: TCursor;
  SaveCount: Integer;
  CloseAction: TCloseAction;
  ModalDoneSent: Boolean;
begin
  FModalResult := mrNone;
  ModalDoneSent := False;
  if not Visible then
  begin
    if Application.FTerminated then
    begin
      Result := -1;
      Exit;
    end;
    Application.ModalStarted(Self);
    try
      SaveFocusCount := FocusCount;
      Screen.FSaveFocusedList.Insert(0, Screen.FFocusedForm);
      Screen.FFocusedForm := Self;
      SaveCursor := Screen.Cursor;
      Screen.Cursor := crDefault;
      SaveCount := Screen.FCursorCount;
      Include(FFormState, fsModal);
      OldModalStack := ModalStack;
      ModalStack := Self;
      QOpenWidget_setWFlags(QOpenWidgetH(Handle), Cardinal(WidgetFlags_WType_Modal));
      QOpenWidget_setWState(QOpenWidgetH(Handle), Cardinal(WidgetState_WState_Modal));
      CaptureControl := GetCaptureControl;
      try
        SetCaptureControl(nil);
        Show;
        try
          Activate;
          QApplication_enter_loop(Application.Handle);
          try
            Application.ModalFinished(Self);
          finally
            ModalDoneSent := True;
          end;
        finally
          Hide;
        end;
        try
          CloseAction := caNone;
          if CloseQuery then
          begin
            CloseAction := caHide;
            if Assigned(FOnClose) then
              FOnClose(Self, CloseAction);
          end;
          case CloseAction of
            caNone: ModalResult := 0;
            caFree: Release;
          end;
        except
          ModalResult := 0;
          Application.HandleException(Self);
        end;
        Deactivate;
      finally
        SetCaptureControl(CaptureControl);
        QOpenWidget_clearWFlags(QOpenWidgetH(Handle), Cardinal(WidgetFlags_WType_Modal));
        QOpenWidget_clearWState(QOpenWidgetH(Handle), Cardinal(WidgetState_WState_Modal));
        ModalStack := OldModalStack;
        { If the ModalResult of a parent dialog was modified then we need to
          exit its modal loop }
        if (OldModalStack <> nil) and (OldModalStack.ModalResult <> mrNone) then
          QApplication_exit_loop(Application.Handle);
        if Screen.FCursorCount = SaveCount then
          Screen.Cursor := SaveCursor
        else
          Screen.Cursor := crDefault;
        if Screen.FSaveFocusedList.Count > 0 then
        begin
          Screen.FFocusedForm := Screen.FSaveFocusedList.First;
          Screen.FSaveFocusedList.Remove(Screen.FFocusedForm);
        end else Screen.FFocusedForm := nil;
        FocusCount := SaveFocusCount;
        Exclude(FFormState, fsModal);
      end;
    finally
      if not ModalDoneSent then
        Application.ModalFinished(Self);
    end;
  end;
  Result := ModalResult;
end;

procedure TCustomForm.UpdateActions;
var
  I: Integer;

  procedure TraverseClients(Container: TWidgetControl);
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
        if Control is TWidgetControl then
          TraverseClients(TWidgetControl(Control));
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

procedure TCustomForm.ValidateRename(AComponent: TComponent; const CurName,
  NewName: string);
begin
  inherited ValidateRename(AComponent, CurName, NewName);
  if FDesignerHook <> nil then
    FDesignerHook.ValidateRename(AComponent, CurName, NewName);
end;

function TCustomForm.IsShortCut(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;

  function DispatchShortCut: Boolean;
  var
    I: Integer;
  begin
    if FActionLists <> nil then
      for I := 0 to FActionLists.Count - 1 do
        if TCustomActionList(FActionLists[I]).IsShortCut(Key, Shift, KeyText) then
        begin
          Result := True;
          Exit;
        end;
    Result := False;
  end;

begin
  Result := False;
  if Assigned(FOnShortCut) then FOnShortCut(Key, Shift, Result);
  Result := Result or (Menu <> nil) and (Menu.Handle <> nil) and
    Menu.IsShortCut(Key, Shift, KeyText) or DispatchShortCut;
end;

function TCustomForm.IsForm: Boolean;
begin
  Result := True;  { Result := not IsControl; }
end;

procedure TCustomForm.SetBorderStyle(const Value: TFormBorderStyle);
begin
  if FBorderStyle <> Value then
  begin
    FBorderStyle := Value;
    if not (csDesigning in ComponentState) and
      not (csRecreating in ControlState) and HandleAllocated then
    begin
      QOpenWidget_clearWFlags(QOpenWidgetH(Handle),
        Integer(WidgetFlags_WStyle_Mask) or Integer(WidgetFlags_WType_Mask) or
        Integer(WidgetFlags_WX11BypassWM));
      ReSubmitFlags;
    end;
  end;
end;

function TCustomForm.WidgetFlags: Integer;
const
  BorderFlags: array[TFormBorderStyle] of Integer =
    (Integer(WidgetFlags_WStyle_NoBorder) or Integer(WidgetFlags_WStyle_Customize), { bsNone }
     Integer(WidgetFlags_WStyle_DialogBorder) or Integer(WidgetFlags_WStyle_Title), { bsSingle }
     Integer(WidgetFlags_WStyle_NormalBorder) or Integer(WidgetFlags_WStyle_Title), { bsSizeable }
     Integer(WidgetFlags_WStyle_Dialog) or Integer(WidgetFlags_WStyle_Title), { bsDialog }
     Integer(WidgetFlags_WStyle_Tool) or Integer(WidgetFlags_WStyle_DialogBorder), { bsToolWindow }
     Integer(WidgetFlags_WStyle_Tool) or Integer(WidgetFlags_WStyle_NormalBorder)); { bsSizeToolWin }

  FormStyleFlags: array[TFormStyle] of Integer =
    (0, 0, 0, Integer(WidgetFlags_WStyle_StaysOnTop));

  function BorderIconFlags(BI: TBorderIcons): Integer;
  begin
    Result := 0;
    if biSystemMenu in BI then Inc(Result, Integer(WidgetFlags_WStyle_SysMenu));
    if biMinimize in BI then Inc(Result, Integer(WidgetFlags_WStyle_Minimize));
    if biMaximize in BI then Inc(Result, Integer(WidgetFlags_WStyle_Maximize));
    if biHelp in BI then Inc(Result, Integer(WidgetFlags_WStyle_ContextHelp));
  end;

var
  Icons: TBorderIcons;
begin
  if csDesigning in ComponentState then
    Result := inherited WidgetFlags or BorderFlags[fbsSizeable] or
      (Integer(WidgetFlags_WStyle_SysMenu) or
      Integer(WidgetFlags_WStyle_Minimize) or
      Integer(WidgetFlags_WStyle_Maximize) or
      Integer(WidgetFlags_WType_TopLevel))
      {$IFDEF MSWINDOWS}
      or Integer(WidgetFlags_WStyle_Customize)
      {$ENDIF}
  else
  begin
    Icons := FBorderIcons;
    case FBorderStyle of
      fbsNone: Icons := [];
      fbsDialog: Icons := Icons * [biSystemMenu, biHelp];
    end;
    Result := inherited WidgetFlags or BorderFlags[FBorderStyle] or
      FormStyleFlags[FFormStyle] or BorderIconFlags(Icons) or
      Integer(WidgetFlags_WType_TopLevel)
      {$IFDEF MSWINDOWS}
      or Integer(WidgetFlags_WStyle_Customize)
      {$ENDIF};
  end;
end;

procedure TCustomForm.SetBorderIcons(const Value: TBorderIcons);
begin
  if Value <> FBorderIcons then
  begin
    FBorderIcons := Value;
    if not (csDesigning in ComponentState) and
      not (csRecreating in ControlState) and HandleAllocated then
      ReSubmitFlags;
  end;
end;

procedure TCustomForm.SetFormStyle(const Value: TFormStyle);
var
  I: Integer;
begin
  if FFormStyle <> Value then
  begin
    FFormStyle := Value;
    if not (csDesigning in ComponentState) then
    begin
      if not (csRecreating in ControlState) and HandleAllocated then
      begin
        ReSubmitFlags;
        WorkspaceNeeded;
        if FFormStyle = fsMDIForm then
        begin
          for I := 0 to ControlCount-1 do
            if Controls[I] is TWidgetControl then
              TOpenWidgetControl(Controls[I]).ReSubmitFlags;
        end
        else if Value = fsMDIChild then
        begin
          for I := 0 to MDIParent.MDIChildCount-1 do
            if MDIParent.MDIChildren[I].Visible and
            (MDIParent.MDIChildren[I].WindowState = wsMaximized) then
            begin
              WindowState := wsMaximized;
              Break;
            end;
          if WindowState <> wsMaximized then
          begin
            Position := poDefault;
            Top := MDIParent.MDIChildTop;
            Left := MDIParent.MDIChildLeft;
          end;
          Visible := True;
        end;
      end;
    end
    else if FFormStyle = fsMDIChild then
      Position := poDefault;
  end;
end;

function TCustomForm.ActionExecute(var BasicAction : TBasicAction): Boolean;

  function ProcessExecute(Control: TControl): Boolean;
  begin
    Result := (Control <> nil) and
      Control.ExecuteAction(BasicAction);
  end;

  function TraverseClients(Container: TWidgetControl): Boolean;
  var
    I: Integer;
    Control: TControl;
  begin
    if Container.Showing then
      for I := 0 to Container.ControlCount - 1 do
      begin
        Control := Container.Controls[I];
        if Control.Visible and ProcessExecute(Control) or
          (Control is TWidgetControl) and TraverseClients(TWidgetControl(Control)) then
        begin
          Result := True;
          Exit;
        end;
      end;
    Result := False;
  end;

begin
  Result := False;
  if (csDesigning in ComponentState) or not Showing then Exit;
  Result := ProcessExecute(ActiveControl) or ProcessExecute(Self) or
    TraverseClients(Self);
end;

function TCustomForm.ActionUpdate(var BasicAction : TBasicAction): Boolean;

  function ProcessUpdate(Control: TControl): Boolean;
  begin
    Result := (Control <> nil) and
      Control.UpdateAction(BasicAction);
  end;

  function TraverseClients(Container: TWidgetControl): Boolean;
  var
    I: Integer;
    Control: TControl;
  begin
    if Container.Showing then
      for I := 0 to Container.ControlCount - 1 do
      begin
        Control := Container.Controls[I];
        if Control.Visible and ProcessUpdate(Control) or
          (Control is TWidgetControl) and TraverseClients(TWidgetControl(Control)) then
        begin
          Result := True;
          Exit;
        end;
      end;
    Result := False;
  end;

begin
  Result := False;
  if (csDesigning in ComponentState) or not Showing then Exit;
  if ProcessUpdate(ActiveControl) or ProcessUpdate(Self) or
    TraverseClients(Self) then
      Result := True;
end;

procedure TCustomForm.IgnoreIdent(Reader: TReader);
begin
  Reader.ReadIdent;
end;

function TCustomForm.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
var
  EType: QEventType;
begin
  try
    Result := True;
    EType := QEvent_type(Event);
    case EType of
      QEventType_Paint:
        if not (csWidgetPainting in ControlState) then
        begin
          inherited EventFilter(Sender, Event);
          if Sender = Handle then CheckGripper;
          TControlCanvas(FCanvas).StartPaint;
          try
            Paint;
          finally
            TControlCanvas(FCanvas).StopPaint;
          end;
        end else
          Result := False;
      QEventType_Close:
        Close;
      QEventType_Move:
        begin
          Result := inherited EventFilter(Sender, Event);
          if QWidget_isMinimized(FHandle) then
            FWindowState := wsMinimized
          else
            if InternalIsMaximized(Handle) then
              FWindowState := wsMaximized
            else if FWindowState = wsMinimized then
              FWindowState := wsNormal;
          BoundsChanged;
        end;
      QEventType_Resize:
        begin
          Result := inherited EventFilter(Sender, Event);
          BoundsChanged;
        end;
      QEventType_FocusIn:
        if not (csDesigning in ComponentState) then
        begin
          if FormStyle = fsMDIForm then
          begin
            if Assigned(ActiveMDIChild) then
              ActiveMDIChild.SetFocus;
          end
          else if Assigned(FActiveControl) and (FActiveControl <> Self) then
            FActiveControl.SetFocus;
          Result := True;
        end;
      QEventType_ShowMaximized,
      QEventType_ShowNormal,
      QEventType_ShowMinimized:
      begin
        if not (csDesigning in ComponentState) then
        begin
          case EType of
            QEventType_ShowMaximized: WindowState := wsMaximized;
            QEventType_ShowNormal: WindowState := wsNormal;
            QEventType_ShowMinimized: WindowState := wsMinimized;
          end;
        end;
        Result := inherited EventFilter(Sender, Event);
      end;
    else
      Result := inherited EventFilter(Sender, Event);
    end;
  except
    Application.HandleException(Self);
    Result := False;
  end;
end;

procedure TCustomForm.SetInitialBounds;
var
  Bounds: TRect;
  DesktopWidget: QWidgetH;
  CenterOn: TCustomForm;
  Center: TPoint;
begin
  case FPosition of
    poDesigned:
      begin
        Bounds.Left := FLeft;
        Bounds.Top := FTop;
        Bounds.Right := FLeft + FWidth;
        Bounds.Bottom := FTop + FHeight;
      end;
     poDefault:
       Exit; { Take the widget's default settings }
     poDefaultPosOnly:
       begin
         QWidget_geometry(Handle, @Bounds);
         Bounds.Right := Bounds.Left + FWidth;
         Bounds.Bottom := Bounds.Top + FHeight;
       end;
     poDefaultSizeOnly:
       begin
         QWidget_geometry(Handle, @Bounds);
         Bounds.Right := Bounds.Right - Bounds.Left + FLeft;
         Bounds.Bottom := Bounds.Bottom - Bounds.Top + FTop;
         Bounds.Left := FLeft;
         Bounds.Top := FTop;
       end;
    poMainFormCenter, poOwnerFormCenter, poScreenCenter, poDesktopCenter:
      begin
        if (FPosition in [poScreenCenter, poDesktopCenter]) or
          (Application.MainForm = nil) or (Application.MainForm = Self) then
        begin
           DesktopWidget := QApplication_desktop;
           Center.X := QWidget_width(DesktopWidget) div 2;
           Center.Y := QWidget_height(DesktopWidget) div 2;
        end
        else
        begin
          if (FPosition = poMainFormCenter) or not (Owner is TCustomForm) then
            CenterOn := Application.MainForm
          else
            CenterOn := TCustomForm(Owner);
          Center.X := CenterOn.Left + CenterOn.Width div 2;
          Center.Y := CenterOn.Top + CenterOn.Height div 2;
        end;
        Bounds.Left := Center.X - FWidth div 2;
        Bounds.Top := Center.Y - FHeight div 2;
        Bounds.Right := Bounds.Left + FWidth;
        Bounds.Bottom := Bounds.Top + FHeight;
      end;
  end;
  QWidget_setGeometry(Handle, Bounds.Left, Bounds.Top, Bounds.Right-Bounds.Left,
    Bounds.Bottom-Bounds.Top);
end;

procedure TCustomForm.SetPosition(const Value: TPosition);
begin
  if FPosition <> Value then
  begin
    FPosition := Value;
    if HandleAllocated and not (csDesigning in ComponentState) then
      SetInitialBounds;
  end;
end;

procedure TCustomForm.ShowingChanged;
begin
  if not (csDesigning in ComponentState) and (fsShowing in FFormState) then
    raise EInvalidOperation.Create(SVisibleChanged);
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
      end
      else
      begin
        try
          DoHide;
          if Screen.ActiveForm = Self then
            MergeMenu(False);
          if Screen.FActiveControl = Self then
            Screen.FActiveControl := nil;
          if Screen.FActiveCustomForm = Self then
          begin
            Screen.FActiveCustomForm := nil;
            Screen.FActiveForm := nil;
          end;
          if Screen.FFocusedForm = Self then
            Screen.FFocusedForm := nil;
          Screen.UpdateLastActive;
        except
          Application.HandleException(Self);
        end;
      end;
  finally
    Exclude(FFormState, fsShowing);
  end;
end;

procedure TCustomForm.SetModalResult(const Value: TModalResult);
begin
  if FModalResult <> Value then
  begin
    FModalResult := Value;
    if (Value <> mrNone) and (ModalStack = Self) then
      QApplication_exit_loop(Application.Handle);
  end;
end;

procedure TCustomForm.DoLoaded;
begin
  if Assigned(FOnLoaded) then FOnLoaded(Self);
end;

function TCustomForm.GetClientRect: TRect;
begin
  Result := inherited GetClientRect;
  if Assigned(Menu) then
    Dec(Result.Bottom, FMenuHeight);
end;

procedure TCustomForm.InitWidget;
begin
  inherited InitWidget;
  TabStop := False;
  QWidget_setMouseTracking(ViewportHandle, True);
  QWidget_setAcceptDrops(ViewportHandle, True);
  QFrame_setFrameStyle(Handle, Integer(QFrameShape_NoFrame));
end;

procedure TCustomForm.SetWindowState(const Value: TWindowState);
begin
  if FWindowState <> Value then
  begin
    FWindowState := Value;
    if Showing then
      ShowWindowState;
  end;
end;

function TCustomForm.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  // Route the QueryInterface throught the DesignerHook first
  if (DesignerHook = nil) or (DesignerHook.QueryInterface(IID, Obj) <> 0) then
    Result := inherited QueryInterface(IID, Obj)
  else
    Result := 0;
end;

procedure TCustomForm.ShowWindowState;
begin
  if not (csDesigning in ComponentState) then
  begin
{$IF Declared(Xlib)}
    WMNET_Init;
{$IFEND}
    case FWindowState of
      wsNormal:
{$IF Declared(Xlib)}
        if WMNET_Supported and (FormStyle <> fsMDIChild) and
        WMNET_IsMaximized(QWidget_winId(Handle)) then
        begin
          QWidget_showNormal(Handle);
          WMNET_SetMaximized(QWidget_winId(Handle), False)
        end
        else
{$IFEND}
        QWidget_showNormal(Handle);
      wsMaximized:
{$IF Declared(Xlib)}
        if WMNET_Supported and (FormStyle <> fsMDIChild) then
        begin
          QWidget_showNormal(Handle);
          WMNET_SetMaximized(QWidget_winId(Handle), True)
        end
        else
{$IFEND}
        QWidget_showMaximized(Handle);
      wsMinimized: QWidget_showMinimized(Handle);
    end;
  end;
end;

procedure TCustomForm.BeginAutoDrag;
begin
  { notification }
end;

procedure TCustomForm.ColorChanged;
begin
  inherited ColorChanged;
  if Assigned(FGripper) then
    QWidget_setBackgroundColor(FGripper, QColor(Color));
  if FCanvas <> nil then
    FCanvas.Brush.Color := Color;
end;

procedure TCustomForm.Resize;
var
  Temp: Integer;
begin
  if ((FormStyle <> fsMDIChild) and ((Menu <> nil) and not Menu.AutoMerge))
  or (csDesigning in ComponentState) or (Menu = nil) then
  begin
    if Menu = nil then
      Temp := 0
    else
      Temp := QWidget_height(Menu.Handle);
    if FMenuHeight <> Temp then
    begin
      FMenuHeight := Temp;
      QOpenScrollView_setMargins(Handle, 0, FMenuHeight, 0, 0);
      QWidget_update(ViewportHandle);
    end;
  end;
  inherited Resize;
  CheckGripper;
end;

procedure TCustomForm.CheckGripper;
begin
  if FSizeGrip then
  begin
    if FGripper = nil then
      FGripper := QSizeGrip_create(Handle, nil);
    if HorzScrollBar.IsScrollBarVisible and VertScrollBar.IsScrollBarVisible then
    begin
      QScrollView_setCornerWidget(Handle, FGripper);
      QWidget_show(FGripper);
    end
    else
    begin
      QScrollView_setCornerWidget(Handle, nil);
      QWidget_hide(FGripper);
    end;
  end;
end;

procedure TCustomForm.CreateWidget;
begin
  {
    In most scenarios, you should not call inherited CreateWidget;
    It was done here because we know that our ancestor has implemented it and
    synchronizing code in two spots regarding such a touchy issue (as widget
    creation) would not have been a good idea.
  }
  inherited CreateWidget;
  WorkspaceNeeded;
  if Assigned(FormWidgetCreatedHook) then
    FormWidgetCreatedHook(Self);
end;

function TCustomForm.GetPaintDevice: QPaintDeviceH;
begin
  if (FormStyle = fsMDIForm) and not (csDesigning in ComponentState) then
    Result := QWidget_to_QPaintDevice(ClientHandle)
  else
    Result := inherited GetPaintDevice; 
end;

function TCustomForm.GetParentWidget: QWidgetH;
var
  I: Integer;
begin
  if (FormStyle = fsMDIChild) and not (csDesigning in ComponentState) then
  begin
    if not Assigned(MDIParent) then
    begin
      for I := 0 to Screen.FormCount-1 do
        if Screen.Forms[I].FormStyle = fsMDIForm then
        begin
          MDIParent := Screen.Forms[I];
          Result := MDIParent.ClientHandle;
          Exit;
        end;
      raise EInvalidOperation.CreateRes(@SNoMDIForm);
    end
    else
      Result := MDIParent.ClientHandle;
  end
  else
    Result := inherited GetParentWidget;
end;

procedure TCustomForm.SetMDIParent(const Value: TForm);
begin
  if FMDIParent <> Value then
    if not Assigned(Value) or (Value.FormStyle = fsMDIForm) then
    begin
      if Assigned(FMDIParent) then
        FMDIParent.RemoveMDIChild(Self);
      FMDIParent := Value;
      if Assigned(FMDIParent) then
        FMDIParent.AppendMDIChild(Self);
    end
    else
      raise EInvalidOperation.CreateResFmt(@SNotAnMDIForm, [ClassName]);
end;

procedure TCustomForm.AlignControls(AControl: TControl; var Rect: TRect);
var
  Size: TSize;
begin
  if Assigned(FMenu) then
  begin
    QWidget_sizeHint(FMenu.Handle, @Size);
    Size.cx := ClientWidth;
    QWidget_resize(FMenu.Handle, @Size);
  end;
  inherited AlignControls(AControl, Rect);

  if (FormStyle = fsMDIForm) and
  (ComponentState * [csDesigning, csDestroying] = []) then
     QWidget_setGeometry(ClientHandle, @Rect);
end;

function TCustomForm.ViewportRect: TRect;
begin
  Result := inherited ViewportRect;
  Dec(Result.Top, FMenuHeight);
  Dec(Result.Bottom, FMenuHeight);
end;

function TCustomForm.GetClientOrigin: TPoint;
begin
  Result := inherited GetClientOrigin;
  Inc(Result.Y, FMenuHeight);
end;

function TCustomForm.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  case Key of
    {$IFDEF LINUX}
    Key_Tab, Key_BackTab:
      if not (ssCtrl in Shift) then
      begin
        Result := SelectNext(FActiveControl, Key = Key_Tab, True);
        Exit;
      end;
    {$ENDIF}
    {$IFDEF MSWINDOWS}
    Key_Tab:
      if not (ssCtrl in Shift) then
      begin
        Result := SelectNext(FActiveControl, not (ssShift in Shift), True);
        Exit;
      end;
    {$ENDIF}
    Key_Left, Key_Right, Key_Up, Key_Down:
      begin
        if FActiveControl <> nil then
        begin
          Result := TForm(FActiveControl.Parent).SelectNext(FActiveControl,
            (Key = Key_Right) or (Key = Key_Down), False);
          Exit;
        end;
      end;
  end;
  Result := inherited WantKey(Key, Shift, KeyText);
end;

function TCustomForm.HandleCreateException: Boolean;
begin
  Application.HandleException(Self);
  Result := True;
end;

procedure TCustomForm.WidgetDestroyed;
begin
  inherited WidgetDestroyed;
  if not (csDesigning in ComponentState) then
    if Assigned(FClientHandle) then
    begin
      QWorkspace_hook_destroy(FClientHooks);
      FClientHooks := nil;
      QClxObjectMap_remove(FClientHandle);
      FClientHandle := nil;
    end;
end;

procedure TCustomForm.MDIChildActivated(w: QWidgetH);
var
  AControl: TControl;
begin
  try
    AControl := FindControl(w);
    if AControl is TCustomForm then
      TCustomForm(AControl).SetFocusedControl(TCustomForm(AControl));
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomForm.WorkspaceNeeded;
var
  Method: TMethod;
begin
  if not (csDesigning in ComponentState) and (FormStyle = fsMDIForm) and
  not Assigned(FClientHandle) then
  begin
    FClientHandle := QWorkspace_create(Handle, nil);
    FClientHooks := QWorkspace_hook_create(FClientHandle);
    QWorkspace_windowActivated_Event(Method) := MDIChildActivated;
    QWorkspace_hook_hook_windowActivated(FClientHooks, Method);
    QClxObjectMap_add(FClientHandle, Integer(Self));
    QScrollView_addChild(Handle, FClientHandle, 0, 0);
  end;
end;

function TCustomForm.GetMDIChildCount: Integer;
begin
  Result := MDIChildList.Count;    
end;

function TCustomForm.MDIChildLeft: Integer;
begin
  Result := (MDIChildList.Count * 10) mod
  QWidget_width(ClientHandle);
  Dec(Result, QFrame_frameWidth(Handle) + 10);
  if Result < 0 then
    Result := 0;
end;

function TCustomForm.MDIChildList: TList;
begin
  if not Assigned(FMDIChildList) then
    FMDIChildList := TList.Create;
  Result := FMDIChildList;
end;

function TCustomForm.MDIChildTop: Integer;
begin
  Result := (MDIChildList.Count * 10) mod
  QWidget_height(ClientHandle);
  Dec(Result, QFrame_frameWidth(Handle) + 10);
  if Result < 0 then
    Result := 0;
end;

function TCustomForm.GetMDIChildren(I: Integer): TForm;
begin
  Result := nil;
  if (I >= 0) and (I < MDIChildList.Count) then
    Result := TObject(MDIChildList[I]) as TForm;
end;

procedure TCustomForm.AppendMDIChild(AForm: TCustomForm);
begin
  MDIChildList.Add(AForm);
end;

procedure TCustomForm.RemoveMDIChild(AForm: TCustomForm);
begin
  MDIChildList.Extract(AForm);
end;

function TCustomForm.GetClientHandle: QWorkspaceH;
begin
  WorkspaceNeeded;
  Result := FClientHandle;
end;

function TCustomForm.GetActiveMDIChild: TForm;
begin
  Result := TForm(QClxObjectMap_find(QWorkspace_activeWindow(ClientHandle)));
end;

procedure TCustomForm.ParentFontChanged;
begin
  if (Parent <> nil) or (ParentWidget <> nil) then
    inherited
  else
    if ParentFont then
    begin
      Font := Application.Font;
      FParentFont := True;
    end;
end;

procedure TCustomForm.VisibleChanging;
begin                              
  if (FormStyle = fsMDIChild) and Visible then
    raise EInvalidOperation.Create(SMDIChildNotVisible);
end;

procedure TCustomForm.FontChanged;
begin
  inherited FontChanged;
  if Assigned(FCanvas) then
    FCanvas.Font := Font;
end;

{ TForm }

procedure TForm.Cascade;
begin
  if FormStyle = fsMDIForm then
    QWorkspace_cascade(ClientHandle);
end;

procedure TForm.Next;
begin
  if FormStyle = fsMDIForm then
    QWorkspace_next(ClientHandle);
end;

procedure TForm.Previous;
begin
  if FormStyle = fsMDIForm then
    QWorkspace_previous(ClientHandle);
end;

procedure TForm.Tile;
begin
  if FormStyle = fsMDIForm then
    QWorkspace_tile(ClientHandle);
end;

{ TScreen }

procedure TScreen.AddDataModule(DataModule: TDataModule);
begin
  FDataModules.Add(DataModule);
end;

procedure TScreen.AddForm(AForm: TCustomForm);
begin
  FCustomForms.Add(AForm);
  if AForm is TForm then
    FForms.Add(AForm);
end;

constructor TScreen.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Classes.AddDataModule := AddDataModule;
  Classes.RemoveDataModule := RemoveDataModule;
  FForms := TList.Create;
  FCustomForms := TList.Create;
  FDataModules := TList.Create;
  FSaveFocusedList := TList.Create;
end;

type
  TCustomCursor = record
    Cursor: TCursor;
    Bits: array[0..32*4-1] of Byte;
    Mask: array[0..32*4-1] of Byte;
    HotSpot: TPoint;
  end;

const
  CustomCursors: array[0..5] of TCustomCursor = (
  ( Cursor: crNo;
    Bits: (
      $03, $E0, $00, $00, $0C, $18, $00, $00,
      $11, $E4, $00, $00, $26, $12, $00, $00,
      $48, $11, $00, $00, $50, $25, $00, $00,
      $90, $4A, $80, $00, $A0, $92, $80, $00,
      $A1, $22, $80, $00, $A2, $42, $80, $00,
      $A4, $82, $80, $00, $A9, $04, $80, $00,
      $52, $05, $00, $00, $44, $09, $00, $00,
      $24, $32, $00, $00, $13, $C4, $00, $00,
      $0C, $18, $00, $00, $03, $E0, $00, $00,
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00);
    Mask: (
      $03, $E0, $00, $00, $0F, $F8, $00, $00,
      $1F, $FC, $00, $00, $3E, $1E, $00, $00,
      $78, $1F, $00, $00, $70, $3F, $00, $00, 
      $F0, $7B, $80, $00, $E0, $F3, $80, $00, 
      $E1, $E3, $80, $00, $E3, $C3, $80, $00, 
      $E7, $83, $80, $00, $EF, $07, $80, $00, 
      $7E, $07, $00, $00, $7C, $0F, $00, $00,
      $3C, $3E, $00, $00, $1F, $FC, $00, $00, 
      $0F, $F8, $00, $00, $03, $E0, $00, $00,
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00);
    HotSpot: (X: 15; Y: 15)),
  ( Cursor: crDrag;
    Bits: (
      $C0, $00, $00, $00, $A0, $00, $00, $00, 
      $90, $00, $00, $00, $88, $00, $00, $00,
      $84, $00, $00, $00, $82, $00, $00, $00,
      $81, $00, $00, $00, $80, $80, $00, $00, 
      $80, $40, $00, $00, $80, $20, $00, $00, 
      $81, $F0, $00, $00, $89, $00, $00, $00, 
      $99, $00, $00, $00, $AC, $FE, $00, $00,
      $CC, $82, $00, $00, $8A, $42, $00, $00, 
      $0A, $42, $00, $00, $09, $22, $00, $00, 
      $09, $22, $00, $00, $08, $C2, $00, $00, 
      $08, $02, $00, $00, $08, $02, $00, $00,
      $08, $02, $00, $00, $08, $02, $00, $00,
      $08, $02, $00, $00, $0F, $FE, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00);
    Mask: (
      $C0, $00, $00, $00, $E0, $00, $00, $00, 
      $F0, $00, $00, $00, $F8, $00, $00, $00, 
      $FC, $00, $00, $00, $FE, $00, $00, $00, 
      $FF, $00, $00, $00, $FF, $80, $00, $00, 
      $FF, $C0, $00, $00, $FF, $E0, $00, $00, 
      $FF, $F0, $00, $00, $FF, $00, $00, $00, 
      $FF, $00, $00, $00, $EF, $FE, $00, $00, 
      $CF, $FE, $00, $00, $8F, $FE, $00, $00,
      $0F, $FE, $00, $00, $0F, $FE, $00, $00, 
      $0F, $FE, $00, $00, $0F, $FE, $00, $00,
      $0F, $FE, $00, $00, $0F, $FE, $00, $00, 
      $0F, $FE, $00, $00, $0F, $FE, $00, $00, 
      $0F, $FE, $00, $00, $0F, $FE, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $00, $00, $00, $00, $00, $00, $00);
    HotSpot: (X: 0; Y: 0)),
  ( Cursor: crHSplit;
    Bits: (
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $01, $40, $00,
      $00, $01, $40, $00, $00, $01, $40, $00,
      $00, $01, $40, $00, $00, $11, $44, $00, 
      $00, $31, $46, $00, $00, $71, $47, $00, 
      $00, $FD, $5F, $80, $00, $71, $47, $00, 
      $00, $31, $46, $00, $00, $11, $44, $00, 
      $00, $01, $40, $00, $00, $01, $40, $00, 
      $00, $01, $40, $00, $00, $01, $40, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00);
    Mask: (
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $03, $E0, $00, $00, $03, $E0, $00, 
      $00, $03, $E0, $00, $00, $03, $E0, $00, 
      $00, $1B, $EC, $00, $00, $3B, $EE, $00, 
      $00, $7B, $EF, $00, $00, $FF, $FF, $80,
      $01, $FF, $FF, $C0, $00, $FF, $FF, $80,
      $00, $7B, $EF, $00, $00, $3B, $EE, $00,
      $00, $1B, $EC, $00, $00, $03, $E0, $00, 
      $00, $03, $E0, $00, $00, $03, $E0, $00,
      $00, $03, $E0, $00, $00, $00, $00, $00,
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00);
    HotSpot: (X: 15; Y: 15)),
  ( Cursor: crVSplit;
    Bits: (
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $02, $00, $00, $00, $07, $00, $00, 
      $00, $0F, $80, $00, $00, $1F, $C0, $00, 
      $00, $02, $00, $00, $00, $02, $00, $00, 
      $00, $00, $00, $00, $01, $FF, $FC, $00, 
      $00, $00, $00, $00, $01, $FF, $FC, $00, 
      $00, $00, $00, $00, $00, $02, $00, $00, 
      $00, $02, $00, $00, $00, $1F, $C0, $00, 
      $00, $0F, $80, $00, $00, $07, $00, $00, 
      $00, $02, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00);
    Mask: (
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $00, $00, $00, $00, $02, $00, $00,
      $00, $07, $00, $00, $00, $0F, $80, $00,
      $00, $1F, $C0, $00, $00, $3F, $E0, $00,
      $00, $3F, $E0, $00, $00, $07, $00, $00,
      $03, $FF, $FE, $00, $03, $FF, $FE, $00,
      $03, $FF, $FE, $00, $03, $FF, $FE, $00,
      $03, $FF, $FE, $00, $00, $07, $00, $00,
      $00, $3F, $E0, $00, $00, $3F, $E0, $00,
      $00, $1F, $C0, $00, $00, $0F, $80, $00,
      $00, $07, $00, $00, $00, $02, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00, 
      $00, $00, $00, $00, $00, $00, $00, $00);
    HotSpot: (X: 15; Y: 15)),
  ( Cursor: crMultiDrag;
    Bits: (
      $C0, $00, $00, $00, $A0, $00, $00, $00,
      $90, $00, $00, $00, $88, $00, $00, $00,
      $84, $00, $00, $00, $82, $00, $00, $00,
      $81, $00, $00, $00, $80, $80, $00, $00,
      $80, $40, $00, $00, $80, $20, $00, $00,
      $81, $F0, $00, $00, $89, $00, $00, $00,
      $99, $00, $00, $00, $AC, $FE, $00, $00, 
      $CC, $82, $00, $00, $8A, $43, $C0, $00, 
      $0A, $42, $40, $00, $09, $22, $78, $00, 
      $09, $22, $48, $00, $08, $C2, $48, $00,
      $08, $02, $48, $00, $08, $02, $48, $00, 
      $08, $02, $48, $00, $08, $02, $48, $00, 
      $08, $02, $48, $00, $0F, $FE, $48, $00, 
      $01, $00, $48, $00, $01, $FF, $C8, $00, 
      $00, $20, $08, $00, $00, $3F, $F8, $00,
      $00, $00, $00, $00, $00, $00, $00, $00);
    Mask: (
      $C0, $00, $00, $00, $E0, $00, $00, $00, 
      $F0, $00, $00, $00, $F8, $00, $00, $00,
      $FC, $00, $00, $00, $FE, $00, $00, $00,
      $FF, $00, $00, $00, $FF, $80, $00, $00, 
      $FF, $C0, $00, $00, $FF, $E0, $00, $00, 
      $FF, $F0, $00, $00, $FF, $00, $00, $00, 
      $FF, $00, $00, $00, $EF, $FE, $00, $00, 
      $CF, $FE, $00, $00, $8F, $FF, $C0, $00, 
      $0F, $FF, $C0, $00, $0F, $FF, $F8, $00, 
      $0F, $FF, $F8, $00, $0F, $FF, $F8, $00, 
      $0F, $FF, $F8, $00, $0F, $FF, $F8, $00,
      $0F, $FF, $F8, $00, $0F, $FF, $F8, $00,
      $0F, $FF, $F8, $00, $0F, $FF, $F8, $00,
      $01, $FF, $F8, $00, $01, $FF, $F8, $00,
      $00, $3F, $F8, $00, $00, $3F, $F8, $00,
      $00, $00, $00, $00, $00, $00, $00, $00);
    HotSpot: (X: 0; Y: 0)),
  ( Cursor: crSqlWait;
    Bits: (
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $00, $00, $00, $00, $3F, $FE, $00,
      $00, $35, $56, $00, $00, $1F, $FC, $00,
      $00, $10, $04, $00, $00, $10, $54, $00,
      $00, $0A, $A8, $00, $00, $05, $50, $00,
      $00, $03, $E0, $00, $00, $01, $C0, $00,
      $00, $01, $40, $00, $00, $01, $C0, $00,
      $00, $02, $20, $00, $00, $04, $90, $00,
      $00, $08, $88, $00, $00, $11, $44, $00,
      $00, $12, $A4, $00, $00, $1F, $FC, $00,
      $00, $35, $56, $00, $00, $3F, $FE, $00,
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $18, $C4, $00, $00, $25, $24, $00,
      $00, $11, $24, $00, $00, $09, $24, $00,
      $00, $25, $64, $00, $00, $18, $E7, $00,
      $00, $00, $10, $00, $00, $00, $00, $00);
    Mask: (
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $00, $00, $00, $00, $3F, $FE, $00,
      $00, $3F, $FE, $00, $00, $1F, $FC, $00,
      $00, $1F, $FC, $00, $00, $1F, $FC, $00,
      $00, $0F, $F8, $00, $00, $07, $F0, $00,
      $00, $03, $E0, $00, $00, $01, $C0, $00,
      $00, $01, $C0, $00, $00, $01, $C0, $00,
      $00, $03, $E0, $00, $00, $07, $F0, $00,
      $00, $0F, $F8, $00, $00, $1F, $FC, $00,
      $00, $1F, $FC, $00, $00, $1F, $FC, $00,
      $00, $3F, $FE, $00, $00, $3F, $FE, $00,
      $00, $00, $00, $00, $00, $00, $00, $00,
      $00, $18, $C4, $00, $00, $25, $24, $00,
      $00, $11, $24, $00, $00, $09, $24, $00,
      $00, $25, $64, $00, $00, $18, $E7, $00,
      $00, $00, $10, $00, $00, $00, $00, $00);
    HotSpot: (X: 15; Y: 15)));

procedure TScreen.CreateCursors;
type
  { Taken from qcursor.h }
  QCursorShape = (ArrowCursor, UpArrowCursor, CrossCursor, WaitCursor,
    IbeamCursor, SizeVerCursor, SizeHorCursor, SizeBDiagCursor, SizeFDiagCursor,
    SizeAllCursor, BlankCursor, SplitHCursor, SplitVCursor, PointingHandCursor,
    CustomCursor);

  procedure LoadCustomCursor(Cur: TCursor);
  type
    TCardinals = array[0..31] of Cardinal;
    PCardinals = ^TCardinals;
  var
    I: Integer;
    BitsBitmap: QBitmapH;
    MaskBitmap: QBitmapH;
  begin
    for I := Low(CustomCursors) to High(CustomCursors) do
      with CustomCursors[I] do
        if Cursor = Cur then
        begin
          BitsBitmap := QBitmap_create(32, 32, @Bits, False);
          MaskBitmap := QBitmap_create(32, 32, @Mask, False);
          InsertCursor(Cur, QCursor_create(BitsBitmap, MaskBitmap, HotSpot.X,
            HotSpot.Y));
          QBitmap_destroy(BitsBitmap);
          QBitmap_destroy(MaskBitmap);
          Exit;
        end;
  end;

const
  CursorMap: array[crSizeAll..crNone] of QCursorShape = (
    {crSizeAll}   SizeAllCursor,   {crHandPoint} PointingHandCursor,
    {crHelp}      CustomCursor,    {crAppStart}  WaitCursor,
    {crNo}        CustomCursor,    {crSQLWait}   CustomCursor,
    {crMultiDrag} CustomCursor,    {crVSplit}    SplitVCursor,
    {crHSplit}    SplitHCursor,    {crNoDrop}    CustomCursor,
    {crDrag}      CustomCursor,    {crHourGlass} WaitCursor,
    {crUpArrow}   UpArrowCursor,   {crSizeWE}    SizeHorCursor,
    {crSizeNWSE}  SizeFDiagCursor, {crSizeNS}    SizeVerCursor,
    {crSizeNESW}  SizeBDiagCursor, {crSize}      SizeAllCursor,
    {crIBeam}     IbeamCursor,     {crCross}     CrossCursor,
    {crArrow}     ArrowCursor,     {crNone}	 BlankCursor);
var
  I: Integer;
  Shape: QCursorShape;
begin
  for I := Low(CursorMap) to High(CursorMap) do
  begin
    Shape := CursorMap[I];
    if Shape <> CustomCursor then
      InsertCursor(I, QCursor_create(Ord(Shape)))
    else
      LoadCustomCursor(I);
  end;
  FDefaultCursor := Cursors[crArrow];
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
    QCursor_destroy(P^.Handle);
    if Q = nil then FCursorList := P^.Next else Q^.Next := P^.Next;
    Dispose(P);
  end;
end;

destructor TScreen.Destroy;
begin
  FHintFont.Free;
  FForms.Free;
  FCustomForms.Free;
  FDataModules.Free;
  FSaveFocusedList.Free;
  Classes.AddDataModule := nil;
  Classes.RemoveDataModule := nil;
  inherited Destroy;
end;

function TScreen.GetCursors(Index: Integer): QCursorH;
var
  P: PCursorRec;
begin
  P := FCursorList;
  while (P <> nil) and (P^.Index <> Index) do
    P := P^.Next;
  if P = nil then
    Result := FDefaultCursor
  else
    Result := P^.Handle;
end;

function TScreen.GetCustomFormCount: Integer;
begin
  Result := FCustomForms.Count;
end;

function TScreen.GetCustomForms(Index: Integer): TCustomForm;
begin
  Result := FCustomForms[Index];
end;

function TScreen.GetDataModule(Index: Integer): TDataModule;
begin
  Result := FDataModules[Index];
end;

function TScreen.GetDataModuleCount: Integer;
begin
  Result := FDataModules.Count;
end;

function TScreen.GetFonts: TStrings;

  procedure CreateFontList;
  var
    FontFamilies: QStringListH;
    FontDatabase: QFontDatabaseH;
  begin
    FFonts := TStringList.Create;
    FontFamilies := QStringList_create();
    try
      FontDatabase := QFontDatabase_create();
      try
        QFontDatabase_families(FontDatabase, FontFamilies, True);
        FFonts := QStringListToTStringList(FontFamilies);
      finally
        QFontDatabase_destroy(FontDatabase);
      end;
    finally
      QStringList_destroy(FontFamilies);
    end;
  end;

begin
  if FFonts = nil then
    CreateFontList;
  Result := FFonts;
end;

function TScreen.GetForm(Index: Integer): TForm;
begin
  Result := FForms[Index];
end;

function TScreen.GetFormCount: Integer;
begin
  Result := FForms.Count;
end;

function TScreen.GetPixelsPerInch: Integer;
var
  Metrics: QPaintDeviceMetricsH;
begin
  if FPixelsPerInch = 0 then
  begin
    // This assumes that the pixels per inch doesn't change often.
    // If it changes simply set FPixelsPerInch back to 0 and it will be acquired.
    Metrics := QPaintDeviceMetrics_create(QWidget_to_QPaintDevice(QApplication_desktop));
    FPixelsPerInch := QPaintDeviceMetrics_logicalDpiY(Metrics);
    QPaintDeviceMetrics_destroy(Metrics);
  end;
  Result := FPixelsPerInch;
end;

function TScreen.GetHintFont: TFont;
begin
  if FHintFont = nil then
  begin
    FHintFont := TFont.Create;
    FHintFont.Assign(Application.Font);
    FHintFont.Color := clInfoText;
    FHintFont.OnChange := InternalHintFontChanged;
  end;
  Result := FHintFont;
end;

procedure TScreen.InternalHintFontChanged(Sender: TObject);
begin
  if Application.FHintWindow <> nil then
    Application.FHintWindow.FontChanged;
end;

function TScreen.GetHeight: Integer;
begin
  Result := QWidget_height(QApplication_desktop);
end;

function TScreen.GetWidth: Integer;
begin
  Result := QWidget_width(QApplication_desktop);
end;

procedure TScreen.InsertCursor(Index: Integer; Handle: QCursorH);
var
  P: PCursorRec;
begin
  New(P);
  P^.Next := FCursorList;
  P^.Index := Index;
  P^.Handle := Handle;
  FCursorList := P;
end;

procedure TScreen.RemoveDataModule(DataModule: TDataModule);
begin
  FDataModules.Remove(DataModule);
end;

procedure TScreen.RemoveForm(AForm: TCustomForm);
begin
  FCustomForms.Remove(AForm);
  FForms.Remove(AForm);
  if (FCustomForms.Count = 0) and (Application.FHintWindow <> nil) then
    Application.FHintWindow.ReleaseHandle;
end;

procedure TScreen.SetCursor(const Value: TCursor);
begin
  if Value <> Cursor then
  begin
    FCursor := Value;
    if Value = crDefault then
      QApplication_restoreOverrideCursor
    else
      QApplication_setOverrideCursor(Cursors[Value], True);
  end;
  Inc(FCursorCount);
end;

procedure TScreen.SetCursors(Index: Integer; const Value: QCursorH);
begin
  if Index = crDefault then
    if Value = nil then
      FDefaultCursor := Cursors[crArrow]
    else
      FDefaultCursor := Value
  else
  begin
    DeleteCursor(Index);
    if Value <> nil then InsertCursor(Index, Value);
  end;
end;

procedure TScreen.SetHintFont(Value: TFont);
begin
  HintFont.Assign(Value);
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

function TScreen.GetActiveWidget: QWidgetH;
begin
  Result := nil;
  if ActiveForm <> nil then Result := ActiveForm.Handle;
end;

{ Hint functions }

function GetHint(Control: TControl): WideString;
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

{ TApplication }

{$IFDEF LINUX}
function TApplication.GetDisplay: PDisplay;
begin
  Result := QtDisplay;
end;
{$ENDIF}

function TApplication.GetStyle: TApplicationStyle;
begin
  if not Assigned(FStyle) then
  begin
    FStyle := TApplicationStyle.Create;
    FStyle.HandleNeeded;
  end;
  Result := FStyle;
end;

procedure TApplication.BringToFront;
begin
  if QWidget_isEnabled(MainForm.Handle) and QWidget_isVisible(MainForm.Handle) then
  begin
    QWidget_setActiveWindow(MainForm.Handle);
    QWidget_raise(MainForm.Handle);
  end;
end;

procedure TApplication.ControlDestroyed(Control: TControl);
begin
  if FMainForm = Control then FMainForm := nil;
  if Screen.FActiveControl = Control then Screen.FActiveControl := nil;
  if Screen.FActiveCustomForm = Control then
  begin
    Screen.FActiveCustomForm := nil;
    Screen.FActiveForm := nil;
  end;
  if Screen.FFocusedForm = Control then Screen.FFocusedForm := nil;
  if FHintControl = Control then FHintControl := nil;
  if FMouseControl = Control then
    FMouseControl := nil;
  Screen.UpdateLastActive;
end;

function TApplication.DoMouseIdle: TControl;
var
  CaptureControl: TControl;
  P: TPoint;
  Cursor: TCursor;
begin
  P := Mouse.CursorPos;
  Result := FindDragTarget(P, True);
  if (Result <> nil) and (csDesigning in Result.ComponentState) then
    Result := nil;
  CaptureControl := Mouse.Capture;
  if FMouseControl <> Result then
  begin
    if ((FMouseControl <> nil) and (CaptureControl = nil)) or
      ((CaptureControl <> nil) and (FMouseControl = CaptureControl)) then
    begin
      TOpenControl(FMouseControl).MouseLeave(FMouseControl);
      if csDesigning in FMouseControl.ComponentState then
        FMouseControl.Parent.Cursor := crArrow
      else if (not (FMouseControl is TWidgetControl)) and Assigned(FMouseControl.Parent) then
        FMouseControl.Parent.Cursor := FOldCursor;
    end;

    FMouseControl := Result;

    if ((FMouseControl <> nil) and (CaptureControl = nil)) or
      ((CaptureControl <> nil) and (FMouseControl = CaptureControl)) then
    begin
      if csDesigning in FMouseControl.ComponentState then
        Cursor := crArrow
      else
        Cursor := FMouseControl.Cursor;
      if (not (FMouseControl is TWidgetControl)) and Assigned(FMouseControl.Parent) then
      begin
        FOldCursor := FMouseControl.Parent.Cursor;
        FMouseControl.Parent.Cursor := Cursor;
      end;
      TOpenControl(FMouseControl).MouseEnter(FMouseControl);
    end;
  end;
end;

function GetCurrentThreadID: Integer;
{$IFDEF MSWINDOWS}
  external 'kernel32.dll' name 'GetCurrentThreadId';
{$ENDIF}
{$IFDEF LINUX}
  external 'libpthread.so.0' name 'pthread_self';
{$ENDIF}

procedure TApplication.IconChanged(Sender: TObject);
var
  I: Integer;
begin
  for I := 0 to Screen.FormCount - 1 do
    Screen.Forms[I].Icon := FIcon;
end;

procedure TApplication.ModalStarted(Sender: TObject);
begin
  Inc(FModalLevel);
  if (FModalLevel = 1) and Assigned(FOnModalBegin) then
    FOnModalBegin(Sender);
end;

procedure TApplication.ModalFinished(Sender: TObject);
begin
  Dec(FModalLevel);
  if (FModalLevel = 0) and Assigned(FOnModalEnd) then
    FOnModalEnd(Sender);
end;

procedure TApplication.SetIcon(const Value: TIcon);
begin
  FIcon.Assign(Value);
end;


procedure TApplication.SetHelpContext(const Value: THelpContext);
begin
  FHelpType := htContext;
  FHelpContext := Value;
end;


procedure TApplication.SetHelpKeyword(const Value: String);
begin
  FHelpType := htKeyword;
  FHelpKeyWord := Value;
end;

function TApplication.ValidateHelpSystem: Boolean;
begin
  Result := false;
  if FHelpSystem = nil then begin
    HelpIntfs.GetHelpSystem(FHelpSystem);
  end;
  if FHelpSystem <> nil then Result := true;
end;

procedure TApplication.Idle;
var
  Control: TControl;
  Done: Boolean;
begin
  Control := DoMouseIdle;
  if FShowHint and (FMouseControl = nil) then
    CancelHint;
  if Control <> nil then
    Application.Hint := GetLongHint(GetHint(Control));
  Done := True;
  try
    if Assigned(FOnIdle) then FOnIdle(Self, Done);
    if Done then DoActionIdle;
    TTimer(FIdleTimer).Interval := MaxInt;
  except
    on Exception do HandleException(Self);
  end;
end;

{$IFDEF LINUX}
type
  TAppTimer = class(TTimer)
  protected
    procedure TimerEvent(Sender: TObject);
  public
    constructor Create(AOwner: TComponent); override;
  end;
{$ENDIF}

constructor TApplication.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  if not Assigned(Classes.ApplicationHandleException) then
    Classes.ApplicationHandleException := HandleException;
  if not Assigned(Classes.ApplicationShowException) then
    Classes.ApplicationShowException := ShowException;
  FShowMainForm := True;
  FHintControl := nil;
  FHintWindow := nil;
  FHintColor := DefHintColor;
  FActive := True;
  FHintPause := DefHintPause;
  FHintShortCuts := True;
  FHintShortPause := DefHintShortPause;
  FHintHidePause := DefHintHidePause;
  FShowHint := True;
  FIdleTimer := TTimer.Create(nil);
  TTimer(FIdleTimer).Interval := MaxInt;
  TTimer(FIdleTimer).OnTimer := Idle;
  FQtAccels := False;
  if not IsLibrary then
  begin
    CreateHandle;
    Screen.CreateCursors;
  end;
  Style;
  FPalette := TPalette.Create;
  FPalette.OnChange := PaletteChanged;
  FIcon := TIcon.Create;
  FIcon.Width := 32;
  FIcon.Height := 32;
  FIcon.OnChange := IconChanged;
  ValidateHelpSystem;
  HelpKey := Key_F1;
  HookSynchronizeWakeup;
end;

procedure TApplication.CreateForm(InstanceClass: TComponentClass;
  var Reference);
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
  if not FMainFormSet and (Instance is TForm) then
  begin
    // FMainForm will be set to the first form created by TForm.Create but
    // it will be reset by CreateForm if one was created early, such as through
    // a splash screen. This allows applications that don't use CreateForm to
    // still have a main form but preserve the semantics the first CreateForm
    // being the main form.
    TForm(Instance).HandleNeeded;
    FMainForm := TForm(Instance);
    if TForm(Instance).ActiveControl = nil then
      TForm(Instance).SetFocusedControl(TForm(Instance));
    FMainFormSet := True;
  end;
end;

type
  PCharArray = array[0..0] of PChar;
{$IFDEF LINUX}
  TKApp = function (Argc: Integer; Argv: PPChar; AppName: PChar): QApplicationH; cdecl;
  TKAppDestroy = procedure (App: QApplicationH); cdecl;

var
  IsKApp: Boolean = False;
  KApp: TKApp = nil;
  KAppDestroy: TKAppDestroy = nil;
  AppTimer: TAppTimer = nil;
{$ENDIF}

function QClxApplication_create(argc: PInteger; argv: PPAnsiChar): QClxApplicationH; cdecl;
  external QtShareName name QtNamePrefix + 'QClxApplication_create';
procedure QApplication_destroy(handle: QApplicationH); cdecl;
  external QtShareName name QtNamePrefix + 'QClxApplication_destroy';

{$IFDEF MSWINDOWS}

type
{ Message structure }
  PMsg = ^tagMSG;
  tagMSG = packed record
    hwnd: LongWord;
    message: Cardinal;
    wParam: Longint;
    lParam: Longint;
    time: DWORD;
    pt: TPoint;
  end;

  TWndProc = function (Message: PMsg): Integer; stdcall;

var
  OldWndProc: TWndProc = nil;

function WndProc(Message: PMsg): Integer; stdcall;
var
  AWidget: QWidgetH;
  AControl: TControl;
begin
  Result := 0;

  case Message^.message of
    WM_ACTIVATEAPP:
    begin
      if Message^.wParam = 0 then
        Application.DoDeactivate
      else
        Application.DoActivate;
    end;
    WM_SYSCOMMAND:
    begin
      if Assigned(Application.FMainForm) then
        if Message^.hwnd = QWidget_winId(Application.FMainForm.Handle) then
          case Message^.WParam and $FFF0 of
            SC_MINIMIZE: Application.Minimize;
            SC_RESTORE: Application.Restore;
          end;
      end;
    WM_SIZE:
    begin
      if Message^.wParam = SIZE_RESTORED then
      begin
        AWidget := QWidget_find(Message^.hwnd);
        if Assigned(AWidget) then
        begin
          AControl := FindControl(AWidget);
          if AControl is TCustomForm then
            TCustomForm(AControl).FWindowState := wsNormal;
        end;
      end;
    end;
  end;

  if Assigned(OldWndProc) and (@WndProc <> @OldWndProc) then
    Result := OldWndProc(Message) or Result;
end;

function QClxApplication_setWndProcHook(NewProc: TWndProc): TWndProc; cdecl;
  external 'qtintf.dll' name '_QClxApplication_setWndProcHook';

{$ENDIF}

{$IFDEF LINUX}
procedure InitDynaProcs; forward;
{$ENDIF}

procedure TApplication.LoadTranslator;

  procedure InternalLoadTranslator( LibraryName : PChar);
{$IFDEF LINUX}
  var
    ModuleName,
    FileName: string;
    WFileName,
    WDelimiter: WideString;
    LangCode: PChar;  // Language and country code.  Example: en_US
    P: PChar;
    I: Integer;
    Translator: QTranslatorH;
    Module: HMODULE;
  begin
    Module := LoadLibrary(LibraryName);
    try
      ModuleName := GetModuleName(Module);
    finally
      if Module <> 0 then
        FreeLibrary(Module);
    end;

    if (Module = 0) or (ModuleName = '') then Exit;

    I := Length(ModuleName);
    while (I > 0) and (ModuleName[I] in ['0'..'9', '.']) do Dec(I);
    while (I < Length(ModuleName)) and not (ModuleName[I] in ['0'..'9']) do Inc(I);
    while (I < Length(ModuleName)) and not (ModuleName[I] = '.') do Inc(I);
    if ModuleName[I] = '.' then Dec(I);
    SetLength(ModuleName, I);
    ModuleName := StringReplace(ModuleName, '.so', '.qm', []);

    LangCode := getenv('LANG');
    if (LangCode = nil) or (LangCode^ = #0) then Exit;
    // look for modulename.en_US  (ignoring codeset and modifier suffixes)
    P := LangCode;
    while P^ in ['a'..'z', 'A'..'Z', '_'] do
      Inc(P);
    if P = LangCode then
      FileName := ModuleName
    else
    begin
      FileName := ModuleName + '.' + Copy(LangCode, 1, P - LangCode);

      if not FileExists(Filename) then
      begin
        // look for modulename.en    (ignoring country code and suffixes)
        I := Length(FileName);
        while (I > 0) and not (Filename[I] in ['.', '_']) do
          Dec(I);
        if (I-1 = Length(FileName)) or (I-1 < Length(ModuleName)) then Exit;
        SetLength(FileName, I-1);
        if not FileExists(FileName) then Exit;
      end;
    end;

    Translator := QTranslator_create(nil, nil);
    WFileName := FileName;
    WDelimiter := '_';
    if QTranslator_load(Translator, @WFileName, nil, @WDelimiter, nil) then
      QApplication_installTranslator(Handle, Translator);
  end;
{$ENDIF}
{$IFDEF MSWINDOWS}
  begin
  end;
{$ENDIF}

begin
  InternalLoadTranslator(Qt.QtShareName);
  InternalLoadTranslator(Qt.QtLibName);
end;

procedure TApplication.CreateHandle;
var
  Argc: Integer;
  I: Integer;
  Method: TMethod;
  Temp: string;
begin
  Argc := ParamCount + 1;
  FArgv := AllocMem((Argc + 1) * SizeOf(PChar));
  for I := 0 to Argc - 1 do
  begin
    Temp := ParamStr(I);
    PCharArray(FArgv^)[I] := AllocMem(Length(Temp)+1);
    StrCopy(PCharArray(FArgv^)[I], PChar(Temp));
  end;
  PCharArray(FArgv^)[Argc] := nil;
  if WideSameStr(FTitle, '') then
    FTitle := ChangeFileExt(ExtractFileName(PCharArray(FArgv^)[0]), '');
{$IFDEF LINUX}
  InitDynaProcs;
  if Assigned(KApp) then
  begin
    Temp := FTitle;
    FHandle := KApp(Argc, FArgv, PChar(Temp));
    IsKApp := FHandle <> nil;
    IsKApp := True;
  end;
  AppTimer := TAppTimer.Create(nil);
  if not IsKApp then
{$ENDIF}
    FHandle := QClxApplication_create(@Argc, PPAnsiChar(FArgv));
{$IFDEF MSWINDOWS}
  OldWndProc := QClxApplication_setWndProcHook(@WndProc);
{$ENDIF}
  FHooks := QObject_hook_create(FHandle);
  TEventFilterMethod(Method) := EventFilter;
  Qt_hook_hook_events(FHooks, Method);
  LoadTranslator;
  QApplication_setStartDragTime(99999);
  QApplication_setStartDragDistance(99999);
end;

destructor TApplication.Destroy;
type
  TExceptionEvent = procedure (E: Exception) of object;
var
  I: Integer;
  P: TNotifyEvent;
  E: TExceptionEvent;
begin
  UnhookSynchronizeWakeup;
  P := HandleException;
  if @P = @Classes.ApplicationHandleException then
    Classes.ApplicationHandleException := nil;
  E := ShowException;  
  if @E = @Classes.ApplicationShowException then
    Classes.ApplicationShowException := nil;
{$IFDEF LINUX}
  AppTimer.Free;
{$ENDIF}
  FActive := False;
  CancelHint;
  ShowHint := False;
  FStyle.Free;
  FStyle := nil;
  FFont.Free;
  FIcon.Free;
  if Assigned(FTopMostList) then
    FTopMostList.Free;
  if Assigned(FAppWidget) then
    QWidget_destroy(FAppWidget);
  if Assigned(FHooks) then
    QObject_hook_destroy(FHooks);
  FHelpSystem := nil;
  // The destructor needs to be called here to ensure all QWidgetH's are
  // destroyed prior to the application being destroyed. Destroying them after
  // the Qt application object is destroyed will cause bad things to happen. 
  inherited Destroy;
{$IFDEF LINUX}
  if IsKApp and Assigned(KAppDestroy) then
    KAppDestroy(FHandle)
  else
{$ENDIF}
  QApplication_destroy(FHandle);

  for I := 0 to ParamCount-1 do
    FreeMem(PCharArray(FArgv^)[I]);
  FreeMem(FArgv);
end;

procedure TApplication.DoDeactivate;
begin
  if Active then
  begin
    FKeyState := [];
    FActive := False;
    if Assigned(OnDeactivate) then
      OnDeactivate(Self);
  end;
end;

procedure TApplication.DoActivate;
begin
  if not Active then
  begin
{$IFDEF LINUX}
    if Assigned(AppTimer) then
      AppTimer.Enabled := False;
{$ENDIF}
    FActive := True;
    if Assigned(OnActivate) then
      OnActivate(Self);
  end;
end;

function TApplication.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;

  function ValidAppHandle(AHandle: QObjectH): Boolean;
  begin
    Result := (Assigned(FMainForm) and (FMainForm.HandleAllocated and
      ((Sender = FMainForm.Handle) or (Sender = FMainForm.ClientHandle)))) or
      (Sender = Handle) or (Sender = AppWidget);
  end;

  function ValidMainForm(AHandle: QObjectH): Boolean;
  begin
    Result := ValidAppHandle(AHandle) and Assigned(FMainForm);
  end;

var
  CMKeyDown: TCMKeyDown;
  Target: TObject;
begin
  try
    Result := False;
    if Assigned(FOnEvent) then
      FOnEvent(Sender, Event, Result);
    if Result then
      Exit;

    if QEvent_isQCustomEvent(Event) then
    begin
      case QEvent_type(Event) of
        QEventType_CMRelease:
        begin
          if ValidAppHandle(Sender) then
          begin
            Result := True;
            TObject(QCustomEvent_data(QCustomEventH(Event))).Free;
          end;
        end;
        QEventType_CMDestroyWidget:
        begin
          if Sender = Handle then
          begin
            Result := True;
            QWidget_destroy(QWidgetH(QCustomEvent_data(QCustomEventH(Event))));
          end;
        end;
        QEventType_CMQuit:
        begin
          FTerminated := True;
          Result := True;
          QApplication_quit(Handle);
        end;
        QEventType_CMActionExecute:
          Result := ExecuteActionNotification(TBasicAction(QCustomEvent_data(QCustomEventH(Event))));
        QEventType_CMActionUpdate:
          Result := UpdateActionNotification(TBasicAction(QCustomEvent_data(QCustomEventH(Event))));
        QEventType_MenuClick:
          begin
            Result := True;
            TMenuItem(QCustomEvent_data(QCustomEventH(Event))).Click;
          end;
      end;
      Exit;
    end;

    case QEvent_type(Event) of
{$IFDEF LINUX}
      QEventType_WindowDeactivate:
        AppTimer.Enabled := not QApplication_closingDown and Active;
      QEventType_WindowActivate:
        DoActivate;
      QEventType_Hide:
      begin
        if not (csDestroying in ComponentState) and ValidMainForm(Sender) and
        QHideEvent_spontaneous(QHideEventH(Event)) and QWidget_isMinimized(FMainForm.Handle) then
          Minimize;
      end;
      QEventType_Show:
      begin
        if not (csDestroying in ComponentState) and QShowEvent_spontaneous(QShowEventH(Event)) then
        begin
          if ValidMainForm(Sender) then
          begin
            if QWidget_isMaximized(QWidgetH(Sender)) then
              FMainForm.WindowState := wsMaximized
            else
              FMainForm.WindowState := wsNormal;
          end;
          Restore;
        end;
      end;
{$ENDIF}
      QEventType_Accel:
        Result := not FQtAccels;
        { We handle accelerator keys and don't forward the events to
          Qt, unless a Qt dialog is active }
      QEventType_KeyRelease:
        FKeyState := ButtonStateToShiftState(QKeyEvent_stateAfter(QKeyEventH(Event)));
      QEventType_KeyPress:
        begin
          FKeyState := ButtonStateToShiftState(QKeyEvent_stateAfter(QKeyEventH(Event)));
          Target := FindObject(Sender);
          if Target <> nil then
          begin
            with CMKeyDown do
            begin
              Msg := CM_KEYDOWN;
              Key := QKeyEvent_key(QKeyEventH(Event));
              Shift := ButtonStateToShiftState(QKeyEvent_state(QKeyEventH(Event)));
              Handled := False;
              QKeyEvent_text(QKeyEventH(Event), @KeyText);
            end;
            Target.Dispatch(CMKeyDown);
            Result := CMKeyDown.Handled;
            if Result then
              Exit;
          end;
        end;
      QEventType_ShowMaximized:
        if not (csDestroying in ComponentState) then
          if ValidMainForm(Sender) then
            FMainForm.WindowState := wsMaximized;
      QEventType_ShowNormal:
        if not (csDestroying in ComponentState) then
          if ValidMainForm(Sender) then
            FMainForm.WindowState := wsNormal;
      QEventType_ShowMinimized:
        if not (csDestroying in ComponentState) then
          if ValidMainForm(Sender) then
            FMainForm.WindowState := wsMinimized;
      QEventType_FocusOut:
        FActive := GetActiveState;
      QEventType_FocusIn:
        FActive := True;
    end;
    if Assigned(FIdleTimer) and (QEvent_type(Event) <> QEventType_Timer) then
      TTimer(FIdleTimer).Interval := 0;
  except
    Application.HandleException(Self);
    Result := False;
  end;
end;

function TApplication.GetDesktop: QWidgetH;
begin
  Result := QApplication_desktop;
end;

{ Hint window processing }

procedure TApplication.StartHintTimer(Value: Integer; TimerMode: TTimerMode);
begin
  StopHintTimer;
  FHintTimer := TTimer.Create(nil);
  TTimer(FHintTimer).OnTimer := HintTimerProc;
  TTimer(FHintTimer).Enabled := True;
  TTimer(FHintTimer).Interval := Value;

  FTimerMode := TimerMode;
  if FHintTimer = nil then CancelHint;
end;

procedure TApplication.StopHintTimer;
begin
  if FHintTimer <> nil then
  begin
    TTimer(FHintTimer).Enabled := False;
    FreeAndNil(FHintTimer);
  end;
end;

procedure TApplication.HintMouseMessage(Control: TControl; Shift: TShiftState; X, Y: Integer);
var
  NewHintControl: TControl;
  Pause: Integer;
  WasHintActive: Boolean;
  P: TPoint;
begin
  NewHintControl := GetHintControl(FindDragTarget(Control.ClientToScreen(Point(X, Y)), True));
  if (NewHintControl = nil) or not NewHintControl.ShowHint then
    CancelHint
  else
  begin
    if (NewHintControl <> FHintControl) or
      (not PtInRect(FHintCursorRect, Control.ClientToScreen(Point(X, Y)))) then
    begin
      WasHintActive := FHintActive;
      if WasHintActive then
        Pause := FHintShortPause
      else
        Pause := FHintPause;
      TOpenControl(NewHintControl).HintShowPause(WasHintActive, Pause);
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
  QWidget_isVisible(FHintWindow.Handle) then
    QWidget_hide(FHintWindow.Handle);
end;

procedure TApplication.CancelHint;
begin
  if FHintControl <> nil then
  begin
    HideHint;
    FHintControl := nil;
    FHintActive := False;
    StopHintTimer;
  end;
end;

procedure TApplication.HintTimerProc(Sender: TObject);
begin
  if Application <> nil then
  try
    Application.HintTimerExpired;
  except
   Application.HandleException(Application);
  end;
end;

procedure TApplication.ActivateHint(CursorPos: TPoint);
var
  ClientOrigin, ParentOrigin: TPoint;
  HintInfo: THintInfo;
  CanShow: Boolean;
  HintWinRect: TRect;
  ParentControl: TWidgetControl;
  
  function GetCursorHeightMargin: Integer;
  var
    P: TPoint;
    CurrentCursor: QCursorH;
    CursorBitmap: QPixmapH;
  begin
    CurrentCursor := Screen.Cursors[Screen.Cursor];
    QCursor_HotSpot(CurrentCursor, @P);
    CursorBitmap := QCursor_Bitmap(CurrentCursor);
    if CursorBitmap = nil then
      Result := DefCursorHeight
    else Result := P.Y - QPixmap_height(CursorBitmap);
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
  if FShowHint and (FHintControl <> nil) and {ForegroundTask and}
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
    else if (FHintControl is TWidgetControl) and
      (TWidgetControl(FHintControl).ParentWidget <> nil) then
      begin
        ParentControl := FindControl(TWidgetControl(FHintControl).ParentWidget);
        if ParentControl <> nil then
          ParentOrigin := FHintControl.ClientToScreen(ParentControl.ClientOrigin);
      end;
    OffsetRect(HintInfo.CursorRect, ParentOrigin.X - ClientOrigin.X,
      ParentOrigin.Y - ClientOrigin.Y);
    HintInfo.CursorPos := FHintControl.ScreenToClient(CursorPos);
    HintInfo.HintStr := GetShortHint(GetHint(FHintControl));
    HintInfo.ReshowTimeout := 0;
    HintInfo.HideTimeout := FHintHidePause;
    HintInfo.HintWindowClass := HintWindowClass;
    HintInfo.HintData := nil;
    CanShow := TOpenControl(FHintControl).HintShow(HintInfo);

    if CanShow and Assigned(FOnShowHint) then
      FOnShowHint(HintInfo.HintStr, CanShow, HintInfo);

    FHintActive := CanShow and (FHintControl <> nil);
    if FHintActive and (HintInfo.HintStr <> '') then
    begin
      ValidateHintWindow(HintInfo.HintWindowClass);
      { calculate the width of the hint based on HintStr and MaxWidth }
      with HintInfo do
        HintWinRect := FHintWindow.CalcHintRect(HintMaxWidth, HintStr, HintData);

      OffsetRect(HintWinRect, HintInfo.HintPos.X, HintInfo.HintPos.Y);
      { Convert the client's rect to screen coordinates }
      with HintInfo do
      begin
        FHintCursorRect.TopLeft := FHintControl.ClientToScreen(CursorRect.TopLeft);
        FHintCursorRect.BottomRight := FHintControl.ClientToScreen(CursorRect.BottomRight);
      end;

      FHintWindow.Color := HintInfo.HintColor;
      FHintWindow.ActivateHintData(HintWinRect, HintInfo.HintStr, HintInfo.HintData);
      if HintInfo.ReshowTimeout > 0 then
        StartHintTimer(HintInfo.ReshowTimeout, tmShow)
      else
        StartHintTimer(HintInfo.HideTimeout, tmHide);
    end;
  end;
end;

procedure TApplication.HandleException(Sender: TObject);
begin
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

procedure TApplication.HandleMessage;
begin
  QApplication_processOneEvent(Handle);
  if GetCurrentThreadID = Integer(MainThreadID) then
    CheckSynchronize;
end;

procedure TApplication.Initialize;
begin
  if InitProc <> nil then TProcedure(InitProc);
end;

function TApplication.IsShortCut(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  Result := False;
  if Assigned(FOnShortCut) then FOnShortCut(Key, Shift, Result);
  Result := Result or (MainForm <> nil) and MainForm.Enabled
    and (QApplication_activeWindow(Handle) = MainForm.Handle)
    and MainForm.IsShortCut(Key, Shift, KeyText);
end;

procedure TApplication.ProcessMessages;
begin
  QApplication_processEvents(Handle);
  if GetCurrentThreadID = Integer(MainThreadID) then
    CheckSynchronize;
end;

procedure TApplication.Run;
begin
  AddExitProc(DoneApplication);

  if FMainForm <> nil then
  begin
    if FShowMainForm and Assigned(FMainForm) then
    begin
      if FMainForm.FWindowState = wsMinimized then
        Minimize
      else
        FMainForm.Visible := True;
    end;
    while not FTerminated do
      HandleMessage;
  end;
end;

function TApplication.ExecuteActionNotification(Action: TBasicAction): Boolean;
var
  Form: TCustomForm;
begin
  Form := Screen.ActiveForm;
  Result := (Form <> nil) and (Form.ActionExecute(Action)) or
    (MainForm <> Form) and (MainForm <> nil) and
    (MainForm.ActionExecute(Action));
  { Disable action if no "user" handler is available }
  if not Result and (Action is TCustomAction) and TCustomAction(Action).Enabled and
    TCustomAction(Action).DisableIfNoHandler then
      TCustomAction(Action).Enabled := Assigned(Action.OnExecute);
end;

function TApplication.UpdateActionNotification(Action: TBasicAction): Boolean;
var
  Form: TCustomForm;
begin
  Form := Screen.ActiveForm;
  Result := (Form <> nil) and (Form.ActionUpdate(Action)) or
    (MainForm <> Form) and (MainForm <> nil) and
    (MainForm.ActionUpdate(Action));
  { Disable action if no "user" handler is available }
  if not Result and (Action is TCustomAction) and TCustomAction(Action).Enabled and
    TCustomAction(Action).DisableIfNoHandler then
      TCustomAction(Action).Enabled := Assigned(Action.OnExecute);
end;

procedure TApplication.DoActionIdle;
var
  I: Integer;
begin
  for I := 0 to Screen.CustomFormCount - 1 do
    with Screen.CustomForms[I] do
      if HandleAllocated and QWidget_isVisible(Handle) and
        QWidget_isEnabled(Handle) then
        UpdateActions;
end;

function TApplication.UpdateAction(Action: TBasicAction): Boolean;
begin
  Result := False;
  if Assigned(FOnActionUpdate) then FOnActionUpdate(Action, Result);
end;

procedure TApplication.SetHandle(const Value: QApplicationH);
begin
  FHandle := Value;
end;

procedure TApplication.SetTitle(const Value: WideString);
var
  AnsiTitle: AnsiString;
begin
  if FTitle <> Value then
  begin
    FTitle := Value;
    AnsiTitle := Value;
    QObject_setName(Handle, PChar(AnsiTitle));
    if Assigned(FMainForm) then
      FMainForm.Caption := FTitle;
  end;
end;

procedure TApplication.SetHint(const Value: WideString);
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

procedure TApplication.ShowException(E: Exception);
var
  Msg: string;
begin
  Msg := E.Message;
  if (Msg <> '') and (AnsiLastChar(Msg) > '.') then Msg := Msg + '.';
  MessageBox(Msg, '', [smbOk], smsCritical);
end;

procedure TApplication.InvokeHelp;
var
  ActiveForm : TCustomForm;
  ActiveControl: TWidgetControl;
begin
  ActiveForm := Screen.ActiveCustomForm;
  if Assigned(ActiveForm) then
  begin
    ActiveControl := ActiveForm.ActiveControl;
    if Assigned(ActiveControl) then
      ActiveControl.InvokeHelp
    else ActiveForm.InvokeHelp;
  end
  else begin
    if HelpType = htKeyword then KeywordHelp(HelpWord);
    if HelpType = htContext then ContextHelp(HelpContext);
  end;
end;

function TApplication.ContextHelp(const HelpContext: THelpContext): Boolean;
var
  EventHandled: Boolean;
begin
  EventHandled := false;
  Result := false;
  if Assigned(FOnHelp) then 
    Result := FOnHelp(htContext, HelpContext, '', CurrentHelpFile, 
                      EventHandled);
  if (not EventHandled) and (ValidateHelpSystem) then
  begin
    HelpSystem.ShowContextHelp(HelpContext, CurrentHelpFile);
    Result := true;
  end;
end;

function TApplication.KeywordHelp(const HelpKeyword: string): Boolean;
var
  EventHandled: Boolean;
begin
  EventHandled := false;
  Result := false;
  if Assigned(FOnHelp) then
     Result := FOnHelp(htKeyword, 0, HelpKeyword, CurrentHelpFile,
                       EventHandled);
  if (not EventHandled) and (ValidateHelpSystem) then
  begin
    HelpSystem.ShowHelp(HelpKeyword, CurrentHelpFile);
    Result := true;
  end;
end;

function TApplication.MessageBox(const Text, Caption: WideString;
  Buttons: TMessageButtons; Style: TMessageStyle; Default,
  Escape: TMessageButton): TMessageButton;
const
  flgDefault = $100;
  flgEscape  = $200;
var
  Bs: array [0..2] of Integer;
  B: Integer;
  I: TMessageButton;
  R: Integer;
  ParentH: QWidgetH;
begin
  if Application.Terminated then
  begin
    Result := Escape;
    Exit;
  end;

  // Ensure the mouse is not grabbed
  if QWidget_mouseGrabber <> nil then
    QWidget_releaseMouse(QWidget_mouseGrabber);
  // Ensure the keyboard is not grabbed
  if QWidget_keyboardGrabber <> nil then
    QWidget_releaseKeyboard(QWidget_keyboardGrabber);

  // Calculate what buttons to show
  B := 0;
  FillChar(Bs, SizeOf(Bs), 0);
  for I := Low(I) to High(I) do
    if I in Buttons then
    begin
      if B > High(Bs) then
        raise EInvalidOperation.CreateRes(@STooManyMessageBoxButtons);
      Bs[B] := Ord(I) + 1;
      if I = Default then
        Inc(Bs[B], flgDefault);
      if I = Escape then
        Inc(Bs[B], flgEscape);
      Inc(B);
    end;

  // Display the right dialog
  R := 0;
  if (Screen.ActiveCustomForm <> nil) and (Screen.ActiveCustomForm.HandleAllocated) then
    ParentH := Screen.ActiveCustomForm.Handle
  else
    ParentH := AppWidget;
  case Style of
    smsInformation:
      R := QMessageBox_information(ParentH, @Caption, @Text, Bs[0], Bs[1], Bs[2]);
    smsWarning:
      R := QMessageBox_warning(ParentH, @Caption, @Text, Bs[0], Bs[1], Bs[2]);
    smsCritical:
      R := QMessageBox_critical(ParentH, @Caption, @Text, Bs[0], Bs[1], Bs[2]);
  end;

  // Return which button was pressed as a TMessageButton
  Result := TMessageButton(R - 1);
end;

procedure TApplication.Terminate;
begin
  if (not Application.Terminated) and CallTerminateProcs then
    Quit;
end;

procedure TApplication.StyleChanged(Sender: TObject);
begin
end;

procedure TApplication.PaletteChanged(Sender: TObject);
begin
  QApplication_setPalette((Sender as TPalette).Handle, True, nil);
  StyleChanged(Sender); 
end;

procedure TApplication.SetStyle(const Value: TApplicationStyle);
begin
  if FStyle <> Value then
  begin
    if not Assigned(Value) then
    begin
      if Assigned(FStyle) then
        FStyle.Free;
      FStyle := TApplicationStyle.Create;
      FStyle.HandleNeeded;
      Exit;
    end
    else
      FStyle := Value;
    if (QApplication_style <> FStyle.Handle) and Assigned(Application) then
      FStyle.HandleNeeded;
  end;
end;

procedure TApplication.Quit;
begin
  QApplication_SendEvent(Handle, QCustomEvent_create(QEventType_CMQuit, nil));
end;

var
  FVisibleTLWidgets: TList;

procedure RestoreVisibleTLWidgets;
var
  I: Integer;
begin
  if Assigned(FVisibleTLWidgets) then
  begin
    for I := 0 to FVisibleTLWidgets.Count-1 do
      QWidget_show(QWidgetH(FVisibleTLWidgets[I]));
    FVisibleTLWidgets.Clear;
  end;
end;

procedure SaveVisibleTLWidgets;
var
  List: QWidgetListH;
  I: Integer;
  AWidget: QWidgetH;
begin
  List := QApplication_topLevelWidgets;
  if Assigned(List) then
  begin
    if not Assigned(FVisibleTLWidgets) then
      FVisibleTLWidgets := TList.Create;
    QWidgetList_first(List);

    for I := 0 to QWidgetList_count(List) - 1 do
    begin
      AWidget := QWidgetList_current(List);
      if QWidget_isVisible(AWidget) then
      begin
        FVisibleTLWidgets.Add(AWidget);
        if Assigned(Application.MainForm) and (Application.MainForm.Handle <> AWidget) then
          QWidget_hide(AWidget);
      end;
      QWidgetList_next(List);
    end;
    QWidgetList_destroy(List);
  end;
end;

procedure TApplication.Minimize;
begin
  if not FMinimized then
  begin
    NormalizeTopMosts;
    SaveVisibleTLWidgets;
    DoDeactivate;
    if Assigned(FMainForm) and not QWidget_isMinimized(FMainForm.Handle) then
      QWidget_showMinimized(FMainForm.Handle);
    FMinimized := True;
    if Assigned(FOnMinimize) then
      FOnMinimize(Self);
  end;
end;

procedure TApplication.Restore;
begin
  if FMinimized then
  begin
    RestoreTopMosts;
    RestoreVisibleTLWidgets;
    DoActivate;
    if Assigned(FMainForm) then
      QWidget_show(FMainForm.Handle);
    FMinimized := False;
    if Assigned(FOnRestore) then
      FOnRestore(Self);
  end;
end;

function TApplication.GetActiveState: Boolean;
var
  ActiveWidget: QWidgetH;
begin
  Result := false;
  ActiveWidget := QApplication_focusWidget(Handle);
  if ActiveWidget <> nil then Result := true;
end;

function TApplication.GetAppWidget: QWidgetH;
begin
  if not Assigned(FAppWidget) then
  begin
    FAppWidget := QWidget_create(nil, nil, 0);
    QWidget_setFocusPolicy(FAppWidget, QWidgetFocusPolicy_NoFocus);
  end;
  Result := FAppWidget;
end;

function TApplication.ExecuteAction(Action: TBasicAction): Boolean;
begin
  Result := False;
  if Assigned(FOnActionExecute) then
    FOnActionExecute(Action, Result);
end;

function TApplication.GetCurrentHelpFile: string;
var
  ActiveForm: TCustomForm;
begin
  ActiveForm := Screen.ActiveCustomForm;
  if Assigned(ActiveForm) and (ActiveForm.HelpFile <> '') then
    Result := ActiveForm.HelpFile
  else
    Result := HelpFile;
end;

function TApplication.GetExeName: string;
var
{$IF Declared(XLib)}
  FileName: array[0..FILENAME_MAX] of Char;
{$IFEND}
{$IF Declared(Windows)}
  FileName: array[0..MAX_PATH] of Char;
{$IFEND}
begin
  SetString(Result, FileName, 
  GetModuleFileName(MainInstance, FileName, SizeOf(FileName)));
end;

procedure TApplication.UpdateVisible;
begin
  // Not used and should be removed in CLX 2.0
end;

procedure TApplication.InternalFontChanged(Sender: TObject);
begin
  QApplication_setFont(FFont.Handle, False, nil);
end;

function TApplication.GetFont: TFont;
begin
  if FFont = nil then
  begin
    FFont := TFont.Create;
    FFont.OnChange := InternalFontChanged;
  end;
  Result := FFont;
end;

procedure TApplication.SetFont(Value: TFont);
begin
  Font.Assign(Value);
end;

procedure TApplication.NormalizeTopMosts;
var
  List: QWidgetListH;
  I: Integer;
  AControl: TObject;
begin
  if FTopMostLevel = 0 then
  begin
    List := QApplication_topLevelWidgets;
    if not Assigned(List) then
      Exit;
    QWidgetList_first(List);

    for I := 0 to QWidgetList_count(List) - 1 do
    begin
      if QOpenWidget_getWFlags(QOpenWidgetH(QWidgetList_current(List))) and
      Integer(WidgetFlags_WStyle_StaysOnTop) <> 0 then
      begin
        AControl := TObject(QClxObjectMap_find(QWidgetList_current(List)));
        if Assigned(AControl) and (AControl is TCustomForm) then
        begin
          TopMostList.Add(AControl);
          TCustomForm(AControl).FormStyle := fsNormal;
        end;
      end;
      QWidgetList_next(List);
    end;
    QWidgetList_destroy(List);
  end;
  Inc(FTopMostLevel);
end;

procedure TApplication.RestoreTopMosts;
var
  I: Integer;
begin
  if FTopMostLevel > 0 then
  begin
    Dec(FTopMostLevel);
    if FTopMostLevel = 0 then
    begin
      for I := TopMostList.Count-1 downto 0 do
        TCustomForm(TopMostList[I]).FormStyle := fsStayOnTop; 
      TopMostList.Clear;
    end;
  end;
end;

function TApplication.GetTopMostList: TList;
begin
  if not Assigned(FTopMostList) then
    FTopMostList := TList.Create;
  Result := FTopMostList;
end;

{$IFDEF LINUX}
var
  NextDbgUnlockX: procedure;

{ This routine is called by the debugger if the mouse is grabbed
  when the debugger stops the process. }
procedure MyDbgUnlockX;
begin
  if QWidget_mouseGrabber <> nil then
    QWidget_releaseMouse(QWidget_mouseGrabber);
  if Assigned(NextDbgUnlockX) then
    NextDbgUnlockX;
end;
procedure InitDynaProcs;
var
  ThemeLib: Pointer;
begin
  if Assigned(LoadThemeHook) then
  begin
    ThemeLib := LoadThemeHook();
    KApp := dlsym(ThemeLib, 'KApplication_create');
    KAppDestroy := dlsym(ThemeLib, 'KApplication_destroy');
  end;
end;

procedure TAppTimer.TimerEvent(Sender: TObject);
var
  Temp: Integer;
  FocusedWindow: WId;
begin
  XGetInputFocus(QtDisplay, @FocusedWindow, @Temp);
  if FocusedWindow = 0 then
    Exit;
  try
    if QWidget_find(FocusedWindow) = nil then
      if Application.Active then
        Application.DoDeactivate
    else
      Application.DoActivate;
  finally
    Enabled := False;
  end;
end;

constructor TAppTimer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Interval := 50;
  OnTimer := TimerEvent;
end;

{$ENDIF}

procedure TApplication.WakeMainThread(Sender: TObject);
begin
  QApplication_wakeUpGuiThread(Handle);
end;

procedure TApplication.HookSynchronizeWakeup;
begin
  if not Assigned(Classes.WakeMainThread) then
    Classes.WakeMainThread := WakeMainThread;
end;

procedure TApplication.UnhookSynchronizeWakeup;
var
  P: TNotifyEvent;
begin
  P := WakeMainThread;
  if @P = @Classes.WakeMainThread then
    Classes.WakeMainThread := nil;
end;

initialization
{$IFDEF LINUX}
  NextDbgUnlockX := DbgUnlockXProc;
  DbgUnlockXProc := MyDbgUnlockX;
{$ENDIF}
  Classes.RegisterFindGlobalComponentProc(FindGlobalComponent);

finalization
  Classes.UnregisterFindGlobalComponentProc(FindGlobalComponent);

end.
