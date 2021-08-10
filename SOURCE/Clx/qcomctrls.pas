{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QComCtrls;

{$R-,T-,H+,X+}

interface

uses
  Types, SysUtils, Classes, Qt, QTypes, QControls, QStdCtrls, QGraphics,
  Contnrs, QStdActns, QImgList, QMenus, QDialogs, QExtCtrls, QButtons;

type
  { Exception Classes }
  EListViewException = class(Exception);
  EListColumnException = class(Exception);
  EStatusBarException = class(Exception);
  EHeaderException = class(Exception);
  ERangeException = class(Exception);

{ TTab }

  TCustomTabControl = class;

  TTabButtons = (tbLeft, tbRight);
  TTabStyle = (tsTabs, tsButtons, tsFlatButtons, tsNoTabs);

  TTabChangedEvent = procedure(Sender: TObject; TabID: Integer) of object;
  TTabGetImageEvent = procedure(Sender: TObject; TabIndex: Integer;
    var ImageIndex: Integer) of object;
  TTabChangingEvent = procedure(Sender: TObject;
    var AllowChange: Boolean) of object;
  TDrawTabEvent = procedure(Control: TCustomTabControl; TabIndex: Integer;
    const Rect: TRect; Active: Boolean; var DefaultDraw: Boolean ) of object;

  TTabs = class;
  TTabControl = class;

  TTab = class(TCollectionItem)
  private
    FEnabled: Boolean;
    FCaption: TCaption;
    FTabRect: TRect;
    FRow: Integer;
    FImageIndex: Integer;
    FVisible: Boolean;
    FSelected: Boolean;
    FHighlighted: Boolean;
    function GetTabs: TTabs;
    function CalculateWidth: Integer;
    function CalculateHeight: Integer;
    procedure SetCaption(const Value: TCaption);
    procedure SetEnabled(const Value: Boolean);
    function GetHeight: Integer;
    function GetWidth: Integer;
    procedure SetHeight(const Value: Integer);
    procedure SetWidth(const Value: Integer);
    function GetLeft: Integer;
    function GetTop: Integer;
    procedure SetLeft(const Value: Integer);
    procedure SetTop(const Value: Integer);
    procedure SetVisible(const Value: Boolean);
    function GetImageIndex: Integer;
    procedure SetImageIndex(const Value: Integer);
    procedure SetSelected(const Value: Boolean);
    procedure SetHighlighted(const Value: Boolean);
  protected
    function GetDisplayName: string; override;
    property Left: Integer read GetLeft write SetLeft;
    property Top: Integer read GetTop write SetTop;
    property Height: Integer read GetHeight write SetHeight;
    property Width: Integer read GetWidth write SetWidth;
  public
    constructor Create(Collection: TCollection); override;
    procedure Assign(Source: TPersistent); override;
    property Tabs: TTabs read GetTabs;
    property Row: Integer read FRow;
    property TabRect: TRect read FTabRect;
  published
    property Caption: TCaption read FCaption write SetCaption;
    property Enabled: Boolean read FEnabled write SetEnabled default True;
    property Highlighted: Boolean read FHighlighted write SetHighlighted default False;
    property ImageIndex: Integer read GetImageIndex write SetImageIndex;
    property Selected: Boolean read FSelected write SetSelected default False;
    property Visible: Boolean read FVisible write SetVisible default True;
  end;

{ TTabs }

  TTabs = class(TCollection)
  private
    FTabControl: TCustomTabControl;
    FUpdating: Boolean;
    function GetItem(Index: Integer): TTab;
    procedure SetItem(Index: Integer; const Value: TTab);
    function CalculateTabHeight(const S: WideString): Integer;
  protected
    function GetOwner: TPersistent; override;
    procedure Update(Item: TCollectionItem); override;
    property TabControl: TCustomTabControl read FTabControl;
  public
    constructor Create(TabControl: TCustomTabControl);
    function Add(const ACaption: WideString): TTab;
    property Items[Index: Integer]: TTab read GetItem write SetItem; default;
  end;

{ TCustomTabControl }

  TTabSide = (tsLeft, tsTop, tsRight, tsBottom);

  TCustomTabControl = class(TCustomControl)
  private
    FBitmap: TBitmap;
    FButtons: array [TTabButtons] of TSpeedButton;
    FErase: Boolean;
    FDblBuffer: TBitmap;
    FFirstVisibleTab: Integer;
    FHotImages: TCustomImageList;
    FHotTrack: Boolean;
    FHotTrackColor: TColor;
    FImageBorder: Integer;
    FImageChangeLink: TChangeLink;
    FImages: TCustomImageList;
    FLastVisibleTab: Integer;
    FLayoutCount: Integer;
    FMouseOver: Integer;
    FMultiLine: Boolean;
    FMultiSelect: Boolean;
    FOwnerDraw: Boolean;
    FRaggedRight: Boolean;
    FRowCount: Integer;
    FShowFrame: Boolean;
    FStyle: TTabStyle;
    FTabIndex: Integer;
    FTabs: TTabs;
    FTabSize: TSmallPoint;
    FTracking: Integer;
    FOnChange: TNotifyEvent;
    FOnChanged: TTabChangedEvent;
    FOnChanging: TTabChangingEvent;
    FOnDrawTab: TDrawTabEvent;
    FOnGetImageIndex: TTabGetImageEvent;
    FUpdating: Boolean;
    function RightSide: Integer;
    procedure ButtonClick(Sender: TObject);
    procedure EraseControlFlag(const Value: Boolean = True);
    procedure DisplayScrollButtons;
    procedure DrawFocus;
    function GetTabHeight: Integer;
    procedure CalcImageTextOffset(const ARect: TRect; const S: WideString;
      Image: TCustomImageList; var ImagePos, TextPos: TPoint);
    procedure CalculateRows(SelectedRow: Integer);
    procedure CalculateTabPositions;
    procedure EnableScrollButtons;
    function FindNextVisibleTab(Index: Integer): Integer;
    function FindPrevVisibleTab(Index: Integer): Integer;
    procedure BeginDblBuffer;
    procedure EndDblBuffer;
    procedure StretchTabs(ARow: Integer);
    procedure CreateButtons;
    function GetDisplayRect: TRect;
    function GetImageRef: TCustomImageList;
    function GetTabIndex: Integer;
    function GetTotalTabHeight: Integer;
    function HasImages(ATab: TTab): Boolean;
    procedure InternalDrawTabFrame(ACanvas: TCanvas; const ARect: TRect; Tab: TTab; HotTracking: Boolean = False);
    procedure InternalDrawTabContents(ACanvas: TCanvas; const ARect: TRect; Tab: TTab; HotTracking: Boolean = False);
    procedure InternalDrawFrame(ACanvas: TCanvas; ARect: TRect; AShowFrame: Boolean = True;
      Sunken: Boolean = False; Fill : Boolean = True);
    function GetTabs: TTabs;
    procedure PositionButtons;
    function RightSideAdjustment: Integer;
    procedure SetTabs(const Value: TTabs);
    procedure SetHotTrack(const Value: Boolean);
    procedure SetHotTrackColor(const Value: TColor);
    procedure SetImages(const Value: TCustomImageList);
    procedure SetMultiLine(const Value: Boolean);
    procedure SetMultiSelect(const Value: Boolean);
    procedure DoHotTrack(const Value: Integer);
    procedure SetOwnerDraw(const Value: Boolean);
    procedure SetRaggedRight(const Value: Boolean);
    procedure SetStyle(Value: TTabStyle);
    procedure SetTabHeight(const Value: Smallint);
    procedure SetTabIndex(const Value: Integer);
    procedure SetTabWidth(const Value: Smallint);
    procedure TabsChanged;
    procedure SetShowFrame(const Value: Boolean);
    procedure DrawHighlight(Canvas: TCanvas; const Rect: TRect; ASelected, AHighlight,
      AEnabled: Boolean);
    procedure SetHotImages(const Value: TCustomImageList);
    procedure UnselectTabs;
  protected
    procedure AdjustClientRect(var Rect: TRect); override;
    procedure AdjustTabClientRect(var Rect: TRect); virtual;
    procedure AdjustTabRect(var Rect: TRect); virtual;
    function CanChange: Boolean; dynamic;
    function CanShowTab(TabIndex: Integer): Boolean; virtual;
    procedure Change; dynamic;
    procedure Changed(Value: Integer); dynamic;
    function DoMouseWheel(Shift: TShiftState; WheelDelta: Integer;
      const MousePos: TPoint): Boolean; override;
    function DoMouseWheelDown(Shift: TShiftState; const MousePos: TPoint): Boolean; override;
    function DoMouseWheelUp(Shift: TShiftState; const MousePos: TPoint): Boolean; override;
    function DrawTab(TabIndex: Integer; const Rect: TRect; Active: Boolean): Boolean; virtual;
    procedure EnabledChanged; override;
    procedure FontChanged; override;
    function GetImageIndex(ATabIndex: Integer): Integer; virtual;
    procedure ImageListChange(Sender: TObject); virtual;
    procedure KeyUp(var Key: Word; Shift: TShiftState); override;
    procedure Loaded; override;
    procedure LayoutTabs; virtual;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure MouseLeave(AControl: TControl); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure Paint; override;
    procedure Resize; override;
    procedure RequestAlign; override;
    procedure RequestLayout; dynamic;
    procedure UpdateTabImages;
    function WantKey(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; override;
    function WidgetFlags: Integer; override;
    property DisplayRect: TRect read GetDisplayRect;
    property HotImages: TCustomImageList read FHotImages write SetHotImages;
    property HotTrack: Boolean read FHotTrack write SetHotTrack default False;
    property HotTrackColor: TColor read FHotTrackColor write SetHotTrackColor default clBlue;
    property ImageBorder: Integer read FImageBorder write FImageBorder default 4;
    property Images: TCustomImageList read FImages write SetImages;
    property MultiLine: Boolean read FMultiLine write SetMultiLine default False;
    property MultiSelect: Boolean read FMultiSelect write SetMultiSelect default False;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    property OwnerDraw: Boolean read FOwnerDraw write SetOwnerDraw default False;
    property RaggedRight: Boolean read FRaggedRight write SetRaggedRight default False;
    property ShowFrame: Boolean read FShowFrame write SetShowFrame default False;
    property Style: TTabStyle read FStyle write SetStyle default tsTabs;
    property TabHeight: Smallint read FTabSize.Y write SetTabHeight default 0;
    property TabIndex: Integer read GetTabIndex write SetTabIndex default 0;
    property Tabs: TTabs read GetTabs write SetTabs;
    property TabWidth: Smallint read FTabSize.X write SetTabWidth default 0;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnChanged: TTabChangedEvent read FOnChanged write FOnChanged;
    property OnChanging: TTabChangingEvent read FOnChanging write FOnChanging;
    property OnDrawTab: TDrawTabEvent read FOnDrawTab write FOnDrawTab;
    property OnGetImageIndex: TTabGetImageEvent read FOnGetImageIndex write FOnGetImageIndex;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure BeginUpdate;
    procedure EndUpdate;
    function IndexOfTabAt(X, Y: Integer): Integer;
    procedure ScrollTabs(Delta: Integer);
    function TabRect(Index: Integer): TRect; //depricated;
    property Canvas;
    property RowCount: Integer read FRowCount;
    property TabStop default True;
  end;

{ TTabControl }

  TTabControl = class(TCustomTabControl)
  published
    property Anchors;
    property Align;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property HotImages;
    property HotTrack;
    property HotTrackColor;
    property Images;
    property MultiLine;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property RaggedRight;
    property ShowFrame;
    property ShowHint;
    property Style;
    property MultiSelect; { must be after Style due to streaming order }
    property TabHeight;
    property TabOrder;
    property TabStop;
    property Tabs;
    property TabIndex; { must be after Tabs due to streaming order }
    property TabWidth;
    property Visible;
    property OnChange;
    property OnChanged;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnGetImageIndex;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnResize;
    property OnStartDrag;
  end;

{ TTabSheet }

  TPageControl = class;

  TTabSheet = class(TCustomControl)
  private
    FBorderWidth: TBorderWidth;
    FImageIndex: TImageIndex;
    FHighlighted: Boolean;
    FPageControl: TPageControl;
    FTabVisible: Boolean;
    FOnHide: TNotifyEvent;
    FOnShow: TNotifyEvent;
    FTab: TTab;
    function GetPageIndex: Integer;
    function GetTabIndex: Integer;
    procedure SetBorderWidth(const Value : TBorderWidth);
    procedure SetHighlighted(const Value: Boolean);
    procedure SetImageIndex(const Value: TImageIndex);
    procedure SetPageControl(const Value: TPageControl);
    procedure SetPageIndex(const Value: Integer);
    procedure SetTabVisible(const Value: Boolean);
  protected
    procedure AdjustClientRect(var Rect: TRect); override;
    procedure DoHide; dynamic;
    procedure DoShow; dynamic;
    procedure EnabledChanged; override;
    procedure ReadState(Reader: TReader); override;
    procedure ShowingChanged; override;
    procedure TextChanged; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure InitWidget; override;
    property PageControl: TPageControl read FPageControl write SetPageControl;
    property TabIndex: Integer read GetTabIndex;
  published
    property BorderWidth: TBorderWidth read FBorderWidth write SetBorderWidth default 0;
    property Caption;
    property Color;
    property DragMode;
    property Enabled;
    property Font;
    property Height stored False;
    property Highlighted: Boolean read FHighlighted write SetHighlighted default False;
    property ImageIndex: TImageIndex read FImageIndex write SetImageIndex default 0;
    property Left stored False;
    property PageIndex: Integer read GetPageIndex write SetPageIndex stored False;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabVisible: Boolean read FTabVisible write SetTabVisible default True;
    property Top stored False;
    property Visible stored False;
    property Width stored False;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnHide: TNotifyEvent read FOnHide write FOnHide;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnResize;
    property OnShow: TNotifyEvent read FOnShow write FOnShow;
    property OnStartDrag;
  end;

{ TPageControl }

  TPageChangingEvent = procedure(Sender: TObject; NewPage: TTabSheet; var AllowChange: Boolean) of object;

  TPageControl = class(TCustomTabControl)
  private
    FPages: TList;
    FActivePage: TTabSheet;
    FOnPageChange: TNotifyEvent;
    FOnPageChanging: TPageChangingEvent;
    procedure DeleteTab(Page: TTabSheet; Index: Integer);
    function GetActivePageIndex: Integer;
    function GetPage(Index: Integer): TTabSheet;
    function GetPageCount: Integer;
    procedure SetActivePage(aPage: TTabSheet);
    procedure SetActivePageIndex(const Value: Integer);
    procedure ChangeActivePage(Page: TTabSheet);
    procedure MoveTab(CurIndex, NewIndex: Integer);
    procedure InsertPage(const APage: TTabSheet);
    procedure InsertTab(Page: TTabSheet);
    procedure RemovePage(const APage: TTabSheet);
    procedure UpdateTab(Page: TTabSheet);
  protected
    procedure DoContextPopup(const MousePos: TPoint; var Handled: Boolean); override;
    function CanShowTab(TabIndex: Integer): Boolean; override;
    procedure Changed(Value: Integer); override;
    procedure Change; override;
    function DesignEventQuery(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure PageChange; dynamic;
    procedure PageChanging(NewPage: TTabSheet; var AllowChange: Boolean); dynamic;
    procedure SetChildOrder(Child: TComponent; Order: Integer); override;
    procedure ShowControl(AControl: TControl); override;
    procedure UpdateActivePage; virtual;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function FindNextPage(CurPage: TTabSheet;
      GoForward, CheckTabVisible: Boolean): TTabSheet;
    procedure SelectNextPage(GoForward: Boolean);
    procedure Update; override;
    property ActivePageIndex: Integer read GetActivePageIndex
      write SetActivePageIndex;
    property PageCount: Integer read GetPageCount;
    property Pages[Index: Integer]: TTabSheet read GetPage;
  published
    property ActivePage: TTabSheet read FActivePage write SetActivePage;
    property Align;
    property Anchors;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property HotTrack;
    property HotTrackColor;
    property HotImages;
    property Images;
    property MultiLine;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property RaggedRight;
    property ShowFrame;
    property ShowHint;
    property Style;
    property TabHeight;
    property TabOrder;
    property TabStop;
    property TabWidth;
    property Visible;
    property OnChange: TNotifyEvent read FOnPageChange write FOnPageChange;
    property OnChanging;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnGetImageIndex;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnPageChanging: TPageChangingEvent read FOnPageChanging write FOnPageChanging;
    property OnResize;
    property OnStartDrag;
  end;

{ TStatusBar }

  TStatusBar = class;
  TStatusPanel = class;

  TPanelPosition = (ppLeft, ppRight);
  TStatusPanelStyle = (psText, psOwnerDraw);
  TStatusPanelBevel = (pbNone, pbLowered, pbRaised);

  TStatusPanels = class;

  TStatusPanel = class(TCollectionItem)
  private
    FAlignment: TAlignment;
    FBevel: TStatusPanelBevel;
    FBounds: TRect;
    FHidden: Boolean;
    FPanelPosition: TPanelPosition;
    FStyle: TStatusPanelStyle;
    FText: WideString;
    FVisible: Boolean;
    FWidth: Integer;
    procedure SetAlignment(const Value: TAlignment);
    procedure SetBevel(const Value: TStatusPanelBevel);
    procedure SetStyle(Value: TStatusPanelStyle);
    procedure SetText(const Value: WideString);
    procedure SetWidth(const Value: Integer);
    procedure SetPanelPosition(const Value: TPanelPosition);
    procedure SetVisible(const Value: Boolean);
    function GetStatusPanels: TStatusPanels;
  protected
    function GetDisplayName: string; override;
    property StatusPanels: TStatusPanels read GetStatusPanels;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
  published
    property Alignment: TAlignment read FAlignment write SetAlignment default taLeftJustify;
    property Bevel: TStatusPanelBevel read FBevel write SetBevel default pbLowered;
    property PanelPosition: TPanelPosition read FPanelPosition write SetPanelPosition default ppLeft;
    property Style: TStatusPanelStyle read FStyle write SetStyle default psText;
    property Text: WideString read FText write SetText;
    property Visible: Boolean read FVisible write SetVisible default True;
    property Width: Integer read FWidth write SetWidth default 50;
  end;

{ TStatusPanels }

  TStatusPanels = class(TCollection)
  private
    FFixedPanelCount: Integer;
    FStatusBar: TStatusBar;
    function GetItem(Index: Integer): TStatusPanel;
    procedure SetItem(Index: Integer; const Value: TStatusPanel);
  protected
    function GetOwner: TPersistent; override;
    procedure Update(Item: TCollectionItem); override;
    property StatusBar: TStatusBar read FStatusBar;
  public
    constructor Create(StatusBar: TStatusBar);
    function Add: TStatusPanel;
    property Items[Index: Integer]: TStatusPanel read GetItem write SetItem; default;
  end;

{ TStatusBar }

  TPanelClick = procedure(Sender: TObject; Panel: TStatusPanel) of object;
  TDrawPanelEvent = procedure(StatusBar: TStatusBar; Panel: TStatusPanel;
    const Rect: TRect) of object;

  TStatusBar = class(TCustomPanel)
  private
    FAutoHint: Boolean;
    FUpdateCount: Integer;
    FSimplePanel: Boolean;
    FSimpleText: WideString;
    FPanels: TStatusPanels;
    FOnDrawPanel: TDrawPanelEvent;
    FOnHint: TNotifyEvent;
    FSizeGrip: Boolean;
    FSizeGripHandle: QSizeGripH;
    FOnPanelClick: TPanelClick;
    function IsFontStored: Boolean;
    procedure SetPanels(const Value: TStatusPanels);
    procedure SetSimplePanel(const Value: Boolean);
    procedure SetSimpleText(const Value: WideString);
    procedure UpdatePanels;
    procedure SetSizeGrip(const Value: Boolean);
    procedure PositionSizeGrip;
    procedure ValidateSizeGrip;
    function GetPanel(PanelPosition: TPanelPosition;
      Index: Integer): TStatusPanel;
    function GetBorderWidth: TBorderWidth;
    procedure SetBorderWidth(const Value: TBorderWidth);
    procedure CMRecreateWindow(var Message: TMessage); message CM_RECREATEWINDOW;
  protected
    procedure ControlsAligned; override;
    procedure CursorChanged; override;
    function DoHint: Boolean; virtual;
    procedure DoPanelClick(Panel: TStatusPanel); dynamic;
    procedure DrawPanel(Panel: TStatusPanel; const Rect: TRect); dynamic;
    procedure EnabledChanged; override;
    procedure InitWidget; override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure Paint; override;
    procedure PaletteCreated; override;
    procedure RequestAlign; override;
    procedure Resize; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure BeginUpdate;
    procedure EndUpdate;
    function ExecuteAction(Action: TBasicAction): Boolean; override;
    function FindPanel(PanelPosition: TPanelPosition;
      Index: Integer): TStatusPanel;
    procedure FlipChildren(AllLevels: Boolean); override;
    procedure Invalidate; override;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    procedure Update; override;
    property Canvas;
    property Panel[PanelPosition: TPanelPosition; Index: Integer]: TStatusPanel
      read GetPanel;
  published
    property Action;
    property Align default alBottom;
    property Anchors;
    property AutoHint: Boolean read FAutoHint write FAutoHint default False;
    property BorderWidth: TBorderWidth read GetBorderWidth write SetBorderWidth default 0;
    property Color default clBackground;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font stored IsFontStored;
    property Panels: TStatusPanels read FPanels write SetPanels;
    property ParentColor default False;
    property ParentFont default True;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property SimplePanel: Boolean read FSimplePanel write SetSimplePanel default False;
    property SimpleText: WideString read FSimpleText write SetSimpleText;
    property SizeGrip: Boolean read FSizeGrip write SetSizeGrip default True;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnDrawPanel: TDrawPanelEvent read FOnDrawPanel write FOnDrawPanel;
    property OnEndDrag;
    property OnHint: TNotifyEvent read FOnHint write FOnHint;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnPanelClick: TPanelClick read FOnPanelClick write FOnPanelClick;
    property OnResize;
    property OnStartDrag;
  end;

{ TTrackBar }

  TTrackBarOrientation = (trHorizontal, trVertical);
  TTickMark = (tmBottomRight, tmTopLeft, tmBoth);
  TTickStyle = (tsNone, tsAuto);
  QTickSetting = (qtsNoMarks, qtsAbove, qtsLeft, qtsBelow, qtsRight, qtsBoth);

  TTrackBar = class(TWidgetControl)
  private
    FMin: Integer;
    FMax: Integer;
    FOnChange: TNotifyEvent;
    FTickMarks: TTickMark;
    FTickStyle: TTickStyle;
    FOrientation: TTrackBarOrientation;
    procedure ChangeAspectRatio;
    function GetHandle: QClxSliderH;
    procedure SetFrequency(const Value: Integer);
    procedure SetLineSize(const Value: Integer);
    procedure SetMax(const Value: Integer);
    procedure SetMin(const Value: Integer);
    procedure SetOrientation(const Value: TTrackBarOrientation);
    procedure SetPageSize(const Value: Integer);
    procedure SetPosition(const Value: Integer);
    procedure SetRange(const AMin, AMax: Integer);
    procedure SetTickMarks(const Value: TTickMark);
    procedure SetTickStyle(const Value: TTickStyle);
    function GetOrientation: TTrackBarOrientation;
    function GetFrequency: Integer;
    function GetRangeControl: QRangeControlH;
    function GetLineSize: Integer;
    function GetPageSize: Integer;
    function GetMax: Integer;
    function GetMin: Integer;
    function GetPosition: Integer;
    function GetTickMarks: TTickMark;
    function GetTickStyle: TTickStyle;
    procedure UpdateSettings;
    procedure ValueChangedHook(Value: Integer); cdecl;
  protected
    procedure Changed; dynamic;
    procedure CreateWidget; override;
    procedure HookEvents; override;
    procedure InitWidget; override;
    procedure Loaded; override;
    property RangeControl: QRangeControlH read GetRangeControl;
  public
    constructor Create(AOwner: TComponent); override;
    property Handle: QClxSliderH read GetHandle;
  published
    property Align;
    property Anchors;
    property Bitmap;
    property Constraints;
    property DragMode;
    property Enabled;
    property Frequency: Integer read GetFrequency write SetFrequency default 1;
    property Hint;
    property LineSize: Integer read GetLineSize write SetLineSize default 1;
    property Masked default False;
    property Max: Integer read GetMax write SetMax default 10;
    property Min: Integer read GetMin write SetMin default 0;
    property Orientation: TTrackBarOrientation read GetOrientation write SetOrientation default trHorizontal;
    property PageSize: Integer read GetPageSize write SetPageSize default 2;
    property ParentShowHint;
    property PopupMenu;
    property Position: Integer read GetPosition write SetPosition default 0;
    property ShowHint;
    property TabOrder;
    property TabStop default True;
    property TickMarks: TTickMark read GetTickMarks write SetTickMarks default tmBottomRight;
    property TickStyle: TTickStyle read GetTickStyle write SetTickStyle default tsAuto;
    property Visible;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnStartDrag;
  end;

{ TProgressBar }

  TProgressBarChangeEvent = procedure(Sender: TObject; var Text: WideString; NewPosition: Integer) of object;

  TProgressBarOrientation = (pbHorizontal, pbVertical);

  TProgressBar = class(TGraphicControl)
  private
    FBorderWidth: TBorderWidth;
    FFillColor: TColor;
    FFillArea: TRect;
    FSections: Integer;
    FStep: Integer;
    FMin: Integer;
    FMax: Integer;
    FOrientation: TProgressBarOrientation;
    FPosition: Integer;
    FPrevText: WideString;
    FShowCaption: Boolean;
    FSmooth: Boolean;
    FTransparent: Boolean;
    FText: TCaption;
    FTextColor: TColor;
    FTotalSteps: Integer;
    FWrapRange: Boolean;
    FOnChanging: TProgressBarChangeEvent;
    function AdjustToParent(const Rect: TRect): TRect;
    function CalcTextRect(Rect: TRect; const BoundingRect: TRect; const AText: WideString): TRect;
    procedure EraseText(const AText: WideString; BackgroundColor : TColor);
    procedure InternalPaint;
    procedure InternalDrawFrame;
    function ScalePosition(Value: Integer): Integer;
    procedure SetBorderWidth(const Value: TBorderWidth);
    procedure SetFillColor(const Value: TColor);
    procedure SetMax(const Value: Integer);
    procedure SetMin(const Value: Integer);
    procedure SetOrientation(const Value: TProgressBarOrientation);
    procedure SetPosition(Value: Integer);
    procedure SetRange(const AMin, AMax: Integer);
    procedure SetShowCaption(const Value: Boolean);
    procedure SetSmooth(const Value: Boolean);
    procedure SetStep(const Value: Integer);
    procedure SetTransparent(const Value: Boolean);
   protected
    procedure Changing(var Text: WideString; NewPosition: Integer); dynamic;
    procedure FontChanged; override;
    function GetText: TCaption; override;
    procedure Paint; override;
    procedure SetText(const Value: TCaption); override;
    property WrapRange: Boolean read FWrapRange write FWrapRange;
  public
    constructor Create(AOwner: TComponent); override;
    procedure StepBy(Delta: Integer);
    procedure StepIt; virtual;
  published
    property Align;
    property Anchors;
    property BorderWidth: TBorderWidth read FBorderWidth write SetBorderWidth default 0;
    property Caption;
    property Color;
    property Constraints;
    property DragMode;
    property Enabled;
    property FillColor: TColor read FFillColor write SetFillColor default clHighlight;
    property Font;
    property Hint;
    property Max: Integer read FMax write SetMax default 100;
    property Min: Integer read FMin write SetMin default 0;
    property Orientation: TProgressBarOrientation read FOrientation write SetOrientation default pbHorizontal;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property Position: Integer read FPosition write SetPosition default 0;
    property ShowCaption: Boolean read FShowCaption write SetShowCaption default False;
    property ShowHint;
    property Smooth: Boolean read FSmooth write SetSmooth default False;
    property Step: Integer read FStep write SetStep default 10;
    property Transparent: Boolean read FTransparent write SetTransparent default False;
    property Visible;
    property OnChanging: TProgressBarChangeEvent read FOnChanging write FOnChanging;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
  end;

  TMimeSourceFactory = class(TPersistent)
  private
    FFilePath: TStrings;
    procedure SetFilePath(const Value: TStrings);
  protected
    FHandle: QMimeSourceFactoryH;
    procedure CreateHandle; virtual;
    procedure DestroyWidget; virtual;
    function GetHandle: QMimeSourceFactoryH;
    function HandleAllocated: Boolean;
    procedure HandleNeeded;
    procedure DoGetDataHook(AbsoluteName: PWideString;
      var ResolvedData: QMimeSourceH); cdecl;
    procedure GetData(const AbsoluteName: string;
      var ResolvedData: QMimeSourceH); virtual;
  public
    constructor Create;
    destructor Destroy; override;
    procedure AddDataToFactory(const Name: WideString; Data: QMimeSourceH);
    procedure AddImageToFactory(const Name: WideString; Data: QImageH);
    procedure AddPixmapToFactory(const Name: WideString; Data: QPixmapH);
    procedure AddTextToFactory(const Name: WideString; const Data: string);
    function GetMimeSource(const MimeType: WideString): QMimeSourceH;
    procedure RegisterMimeType(const FileExt: WideString; const MimeType: string);
    property Handle: QMimeSourceFactoryH read GetHandle;
  published
    property FilePath: TStrings read FFilePath write SetFilePath;
  end;

{ TCustomTextViewer }

  TTextFormat = (tfPlainText, tfText, tfAutoText);

  TCustomTextViewer = class(TFrameControl)
  private
    FBrush: TBrush;
    FFactory: TMimeSourceFactory;
    FUseDefaultFactory: Boolean;
    FViewportHandle: QWidgetH;
    FViewportHook: QWidget_hookH;
    FTextColor: TColor;
    FFileName: TFileName;
    FUnderlineLink: Boolean;
    FLinkColor: TColor;
    FTextFormat: TTextFormat;
    FVScrollHandle: QScrollBarH;
    FHScrollHandle: QScrollBarH;
    FVScrollHook: QScrollBar_hookH;
    FHScrollHook: QScrollBar_hookH;
    procedure SubmitTextColor;
    procedure SetTextFormat(const Value: TTextFormat);
    procedure SetUnderlineLink(const Value: Boolean);
    function GetDocumentTitle: WideString;
    function GetIsTextSelected: Boolean;
    function GetSelectedText: WideString;
    function GetBrush: TBrush;
    procedure SetBrush(const Value: TBrush);
    procedure SetTextColor(const Value: TColor);
    function GetDocumentText: WideString;
    procedure SetLinkColor(const Value: TColor);
    procedure SetDocumentText(const Value: WideString); virtual;
    function GetFactory: TMimeSourceFactory;
    procedure SetFactory(const Value: TMimeSourceFactory);
    procedure SetDefaultFactory(const Value: Boolean);
    procedure SetFileName(const Value: TFileName);
    procedure UpdateViewableContents;
  protected
    procedure CreateWidget; override;
    function GetChildHandle: QWidgetH; override;
    function GetHandle: QTextViewH;
    procedure InitWidget; override;
    procedure PaperChanged(Sender: TObject);
    function ViewportHandle: QWidgetH;
    procedure WidgetDestroyed; override;
    property DocumentTitle: WideString read GetDocumentTitle;
    property Handle: QTextViewH read GetHandle;
    property BorderStyle default bsSunken3d;
    property Factory: TMimeSourceFactory read GetFactory write SetFactory;
    property FileName: TFileName read FFileName write SetFileName;
    property Height default 150;
    property IsTextSelected: Boolean read GetIsTextSelected;
    property LinkColor: TColor read FLinkColor write SetLinkColor
      default clBlue;
    property Paper: TBrush read GetBrush write SetBrush;
    property SelectedText: WideString read GetSelectedText;
    property Text: WideString read GetDocumentText write SetDocumentText;
    property TextColor: TColor read FTextColor write SetTextColor
      default clBlack;
    property TextFormat: TTextFormat read FTextFormat write SetTextFormat
      default tfAutoText;
    property UnderlineLink: Boolean read FUnderlineLink write SetUnderlineLink
      default True;
    property UseDefaultFactory: Boolean read FUseDefaultFactory
      write SetDefaultFactory;
    property Width default 200;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure SelectAll;
    procedure CopyToClipboard;
    procedure LoadFromFile(const AFileName: string); virtual;
    procedure LoadFromStream(Stream: TStream);
  end;

{ TTextViewer }

  TTextViewer = class(TCustomTextViewer)
  public
    property DocumentTitle;
    property Factory;
    property Handle;
    property IsTextSelected;
    property Paper;
    property SelectedText;
    property Text;
  published
    property Align;
    property Anchors;
    property BorderStyle;
    property Constraints;
    property DragMode;
    property Height;
    property FileName;
    property LinkColor;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property TextColor;
    property TextFormat;
    property UnderlineLink;
    property Width;
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
    property OnStartDrag;
  end;

{ TCustomTextBrowser }

  TRTBHighlightTextEvent = procedure (Sender: TObject; 
    const HighlightedText: WideString) of object;

  TCustomTextBrowser = class(TCustomTextViewer)
  private
    FBackwardAvailable: Boolean;
    FForwardAvailable: Boolean;
    FRTBHighlightText: TRTBHighlightTextEvent;
    FTextChanged: TNotifyEvent;
    procedure SetDocumentText(const Value: WideString); override;
    procedure HookBackwardAvailable(p1: Boolean); cdecl;
    procedure HookForwardAvailable(p1: Boolean); cdecl;
    procedure HookHighlightText(p1: PWideString); cdecl;
    procedure HookTextChanged; cdecl;
    procedure SetHighlightText(const Value: TRTBHighlightTextEvent);
    procedure SetTextChanged(const Value: TNotifyEvent);
  protected
    procedure CreateWidget; override;
    procedure WidgetDestroyed; override;
    procedure HookEvents; override;
    function GetHandle: QTextBrowserH;
    property Handle: QTextBrowserH read GetHandle;
    property OnHighlightText: TRTBHighlightTextEvent read FRTBHighlightText write SetHighlightText;
    property OnTextChanged: TNotifyEvent read FTextChanged write SetTextChanged;
  public
    procedure LoadFromFile(const AFileName: string); override;
    procedure ScrollToAnchor(const AnchorName: WideString);
    function CanGoBackward: Boolean;
    procedure Backward;
    function CanGoForward: Boolean;
    procedure Forward;
    procedure Home;
  end;

{ TTextBrowser }

  TTextBrowser = class(TCustomTextBrowser)
  public
    property DocumentTitle;
    property Handle;
    property IsTextSelected;
    property Paper;
    property SelectedText;
    property Text;
  published
    property Align;
    property Anchors;
    property BorderStyle;
    property Constraints;
    property DragMode;
    property Factory;
    property FileName;
    property Height;
    property LinkColor;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property TextColor;
    property TextFormat;
    property UnderlineLink;
    property Width;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnHighlightText;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
    property OnTextChanged;
  end;

{ TSpinEdit }

  TSEButtonType = (btNext, btPrev);
  TSEButtonStyle = (bsArrows, bsPlusMinus);
  TSEDownDirection = (sedNone, sedUp, sedDown);
  TSEChangedEvent = procedure (Sender: TObject; NewValue: Integer) of object;

  TCustomSpinEdit = class(TWidgetControl)
  private
    FButtonUpHook: QWidget_HookH;
    FButtonDownHook: QWidget_HookH;
    FEditHandle: QWidgetH;
    FEditHook: QWidget_HookH;
    FDownButtonHandle: QWidgetH;
    FMin: Integer;
    FMax: Integer;
    FUpButtonHandle: QWidgetH;
    FOnChanged: TSEChangedEvent;
    function GetButtonStyle: TSEButtonStyle;
    function GetCleanText: WideString;
    function GetIncrement: Integer;
    function GetMax: Integer;
    function GetMin: Integer;
    function GetPrefix: WideString;
    function GetRangeControl: QRangeControlH;
    function GetSuffix: WideString;
    function GetSpecialText: WideString;
    function GetValue: Integer;
    function GetWrap: Boolean;
    procedure ValueChangedHook(AValue: Integer); cdecl;
    procedure SetButtonStyle(AValue: TSEButtonStyle);
    procedure SetIncrement(AValue: Integer);
    procedure SetMax(AValue: Integer);
    procedure SetMin(AValue: Integer);
    procedure SetPrefix(const AValue: WideString);
    procedure SetRange(const AMin, AMax: Integer);
    procedure SetSuffix(const AValue: WideString);
    procedure SetSpecialText(const AValue: WideString);
    procedure SetWrap(AValue: Boolean);
    function GetHandle: QClxSpinBoxH;
    procedure SetValue(const AValue: Integer);
  protected
    procedure CreateWidget; override;
    procedure WidgetDestroyed; override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure HookEvents; override;
    procedure Change(AValue: Integer); dynamic;
    function GetText: TCaption; override;
    procedure InitWidget; override;
    procedure Loaded; override;
    procedure PaletteChanged(Sender: TObject); override;
    property ButtonStyle: TSEButtonStyle read GetButtonStyle write SetButtonStyle default bsArrows;
    property CleanText: WideString read GetCleanText;
    property Handle: QClxSpinBoxH read GetHandle;
    property Max: Integer read GetMax write SetMax default 100;
    property Min: Integer read GetMin write SetMin default 0;
    property Increment: Integer read GetIncrement write SetIncrement default 1;
    property Prefix: WideString read GetPrefix write SetPrefix;
    property RangeControl: QRangeControlH read GetRangeControl;
    property SpecialText: WideString read GetSpecialText write SetSpecialText;
    property Suffix: WideString read GetSuffix write SetSuffix;
    property TabStop default True;
    property Text: TCaption read GetText;
    property Value: Integer read GetValue write SetValue default 0;
    property Wrap: Boolean read GetWrap write SetWrap default False;
    property OnChanged: TSEChangedEvent read FOnChanged write FOnChanged;
  public
    constructor Create(AOwner: TComponent); override;
    procedure StepUp;
    procedure StepDown;
  end;

  TSpinEdit = class(TCustomSpinEdit)
  public
    property CleanText;
    property Text;
  published
    property Align;
    property Anchors;
    property ButtonStyle;
    property Constraints;
    property Color;
    property DragMode;
    property Enabled;
    property Hint;
    property Max;
    property Min;
    property Increment;
    property PopupMenu;
    property TabOrder;
    property TabStop;
    property Value;
    property Visible;
    property ParentShowHint;
    property Prefix;
    property ShowHint;
    property SpecialText;
    property Suffix;
    property Wrap;
    property OnChanged;
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
    property OnStartDrag;
  end;

  { forward class declarations }
  THeaderControl = class;
  TCustomHeaderControl = class;
  TCustomViewControl = class;
  TCustomViewItem = class;
  TCustomListView = class;
  TListItem = class;
  TListView = class;
  TCustomTreeView = class;
  TTreeNode = class;

{ TCustomHeaderSection }

  TCustomHeaderSection = class(TCollectionItem)
  private
    FAllowResize: Boolean;
    FAllowClick: Boolean;
    FMaxWidth: Integer;
    FWidth: Integer;
    FMinWidth: Integer;
    FHeader: TCustomHeaderControl;
    FImageIndex: TImageIndex;
    FAutoSize: Boolean;
    FText: WideString;
    procedure UpdateWidth;
    function Header: TCustomHeaderControl;
    procedure SetAllowClick(const Value: Boolean);
    procedure SetAllowResize(const Value: Boolean);
    procedure SetMaxWidth(const Value: Integer);
    procedure SetMinWidth(const Value: Integer);
    procedure SetWidth(Value: Integer);
    function GetLeft: Integer;
    function GetRight: Integer;
    procedure SetImageIndex(const Value: TImageIndex);
    procedure UpdateImage;
    procedure SetAutoSize(const Value: Boolean);
    function CalcSize: Integer;
  protected
    procedure AddSection; virtual;
    procedure AssignTo(Dest: TPersistent); override;
    function GetDisplayName: string; override;
    function GetWidth: Integer; virtual;
    procedure Resubmit; virtual;
    procedure SetWidthVal(const Value: Integer); virtual;
    property AllowClick: Boolean read FAllowClick write SetAllowClick;
    property AllowResize: Boolean read FAllowResize write SetAllowResize;
    property AutoSize: Boolean read FAutoSize write SetAutoSize;
    property ImageIndex: TImageIndex read FImageIndex write SetImageIndex;
    property Left: Integer read GetLeft;
    property MaxWidth: Integer read FMaxWidth write SetMaxWidth;
    property MinWidth: Integer read FMinWidth write SetMinWidth;
    property Right: Integer read GetRight;
    property Width: Integer read GetWidth write SetWidth;
  public
    constructor Create(Collection: TCollection); override;
  end;

{ THeaderSection }

  THeaderSection = class(TCustomHeaderSection)
  private
    procedure SetText(const Value: WideString);
  protected
    procedure AssignTo(Dest: TPersistent); override;
    procedure SetWidthVal(const Value: Integer); override;
    {$IF not (defined(LINUX) and defined(VER140))}
    function GetText: WideString;
    {$IFEND}
  public
    destructor Destroy; override;
    property Index;
    property Left;
    property Right;
  published
    property AllowClick default True;
    property AllowResize default True;
    property AutoSize default False;
    property ImageIndex default -1;
    property MaxWidth default 1000;
    property MinWidth;
    {$IF defined(LINUX) and defined(VER140)}
    property Text: WideString read FText write SetText;
    {$ELSE}
    property Text: WideString read GetText write SetText;
    {$IFEND}
    property Width default 50;
  end;

  THeaderSectionClass = class of TCustomHeaderSection;

{ TCustomHeaderSections }

  TCustomHeaderSections = class(TCollection)
  private
    FHeaderControl: TCustomHeaderControl;
    procedure UpdateImages;
  protected
    function GetOwner: TPersistent; override;
    procedure Update(Item: TCollectionItem); override;
    function GetItem(Index: Integer): TCustomHeaderSection;
    procedure SetItem(Index: Integer; Value: TCustomHeaderSection);
  public
    constructor Create(HeaderControl: TCustomHeaderControl; SectionClass: THeaderSectionClass);
    property Items[Index: Integer]: TCustomHeaderSection read GetItem write SetItem; default;
  end;


{ THeaderSections }

  THeaderSections = class(TCustomHeaderSections)
  protected
    function GetItem(Index: Integer): THeaderSection;
    procedure SetItem(Index: Integer; Value: THeaderSection);
  public
    function Add: THeaderSection;
    property Items[Index: Integer]: THeaderSection read GetItem write SetItem; default;
  end;

{ THeaderOrientation }

  THeaderOrientation = (hoHorizontal, hoVertical);

  TSectionNotifyEvent = procedure(HeaderControl: TCustomHeaderControl;
    Section: TCustomHeaderSection) of object;

  { Resize event is the same as HotTracking if Tracking = True }
  TCustomHeaderControl = class(TWidgetControl)
  private
    FClickable: Boolean;
    FDragReorder: Boolean;
    FResizable: Boolean;
    FTracking: Boolean;
    FOrientation: THeaderOrientation;
    FSections: TCustomHeaderSections;
    FMemStream: TMemoryStream;
    FOnSectionResize: TSectionNotifyEvent;
    FOnSectionClick: TSectionNotifyEvent;
    FOnSectionMoved: TSectionNotifyEvent;
    FCanvas: TCanvas;
    FImages: TCustomImageList;
    FImageChanges: TChangeLink;
    FDontResubmit: Boolean;
    procedure OnImageChanges(Sender: TObject);
    procedure SectionClicked(SectionIndex: Integer); cdecl;
    procedure SectionSizeChanged(SectionIndex: Integer; OldSize, NewSize: Integer); cdecl;
    procedure SectionMoved(FromIndex, ToIndex: Integer); cdecl;
    procedure SetClickable(const Value: Boolean);
    procedure SetDragReorder(const Value: Boolean);
    procedure SetOrientation(const Value: THeaderOrientation);
    procedure SetResizable(const Value: Boolean);
    procedure SetTracking(const Value: Boolean);
    procedure SetSections(const Value: TCustomHeaderSections);
    function GetSections: TCustomHeaderSections;
    procedure SetImages(const Value: TCustomImageList);
  protected
    procedure AssignTo(Dest: TPersistent); override;
    function GetHandle: QHeaderH; virtual;
    procedure CreateWidget; override;
    procedure HookEvents; override;
    procedure ChangeBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    procedure ColumnClicked(Section: TCustomHeaderSection); dynamic;
    procedure ColumnMoved(Section: TCustomHeaderSection); dynamic;
    procedure ColumnResized(Section: TCustomHeaderSection); dynamic;
    procedure ImageListChanged; dynamic;
    procedure InitWidget; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure RestoreWidgetState; override;
    procedure SaveWidgetState; override;
    property Align default alTop;
    property Canvas: TCanvas read FCanvas;
    property Clickable: Boolean read FClickable write SetClickable default False;
    property Handle: QHeaderH read GetHandle;
    property Height default 19;
    property DragReorder: Boolean read FDragReorder write SetDragReorder default False;
    property Images: TCustomImageList read FImages write SetImages;
    property Resizable: Boolean read FResizable write SetResizable default False;
    property Sections: TCustomHeaderSections read GetSections write SetSections;
    property Tracking: Boolean read FTracking write SetTracking default False;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnResize;
    property OnSectionClick: TSectionNotifyEvent read FOnSectionClick
      write FOnSectionClick;
    property OnSectionResize: TSectionNotifyEvent read FOnSectionResize
      write FOnSectionResize;
    property OnSectionMoved: TSectionNotifyEvent read FOnSectionMoved
      write FOnSectionMoved;
    property Orientation: THeaderOrientation read FOrientation
      write SetOrientation default hoHorizontal;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

{ THeaderControl }

  THeaderControl = class(TCustomHeaderControl)
  private
    procedure SetSections(const Value: THeaderSections);
    function GetSections: THeaderSections;
    procedure Init(AHeaderSectionClass: THeaderSectionClass);
  protected
    procedure CreateWidget; override;
    procedure InitWidget; override;
  public
    constructor Create(AOwner: TComponent); overload; override;
    constructor Create(AOwner: TComponent; AHeaderSectionClass: THeaderSectionClass); reintroduce; overload;
  public
    destructor Destroy; override;
    property Canvas;
  published
    property Align;
    property Anchors;
    property Clickable;
    property Constraints;
    property DragMode;
    property DragReorder;
    property Height;
    property Hint;
    property Images;
    property Orientation;
    property ParentShowHint;
    property PopupMenu;
    property Resizable;
    property Sections: THeaderSections read GetSections write SetSections;
    property ShowHint;
    property Tracking;
    property OnConstrainedResize;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnResize;
    property OnSectionClick;
    property OnSectionResize;
    property OnSectionMoved;
    property OnStartDrag;
  end;

{ TListColumn }

  TListColumn = class(TCustomHeaderSection)
  private
    FAlignment: TAlignment;
    FAutoSize: Boolean;
    procedure SetCaption(const Value: WideString);
    procedure SetAutoSize(const Value: Boolean);
    procedure SetAlignment(const Value: TAlignment);
    function HeaderIsListHeader: Boolean;
    {$IF not (defined(LINUX) and defined(VER140))}
    function GetCaption: WideString;
    {$IFEND}
  protected
    procedure AddSection; override;
    procedure AssignTo(Dest: TPersistent); override;
    function GetWidth: Integer; override;
    procedure Resubmit; override;
    procedure SetWidthVal(const Value: Integer); override;
    function ViewControl: TCustomViewControl;
  public
    destructor Destroy; override;
    property Index;
  published
    property Alignment: TAlignment read FAlignment write SetAlignment default taLeftJustify;
    property AllowClick default True;
    property AllowResize default True;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default False;
    {$IF defined(LINUX) and defined(VER140)}
    property Caption: WideString read FText write SetCaption;
    {$ELSE}
    property Caption: WideString read GetCaption write SetCaption;
    {$IFEND}
    property MaxWidth default 1000;
    property MinWidth default 0;
    property Width;
  end;

{ TListColumns }

  TListColumns = class(TCustomHeaderSections)
  private
    function GetItem(Index: Integer): TListColumn;
    procedure SetItem(Index: Integer; Value: TListColumn);
    function GetViewControl: TCustomViewControl;
  protected
    procedure Added(var Item: TCollectionItem); override;
    procedure Update(Item: TCollectionItem); override;
    property ViewControl: TCustomViewControl read GetViewControl;
  public
    function Add: TListColumn;
    property Items[Index: Integer]: TListColumn read GetItem write SetItem; default;
  end;

{ TViewItemsList }

  TListViewItemType = (itDefault, itCheckBox, itRadioButton, itController);

  TViewItemsList = class(TObjectList)
  protected
    function GetItem(Index: Integer): TCustomViewItem;
    procedure SetItem(Index: Integer; AObject: TCustomViewItem);
    property Items[Index: Integer]: TCustomViewItem read GetItem write SetItem; default;
  end;

{ TCustomViewItems }

  TCustomViewItems = class(TPersistent)
  private
    FUpdateCount: Cardinal;
    FOwner: TCustomViewControl;
    FItems: TViewItemsList;
    function GetItem(Index: Integer): TCustomViewItem;
    procedure SetItem(Index: Integer; const Value: TCustomViewItem);
    function GetCount: Integer;
  protected
    function GetHandle: QListViewH;
    function FindViewItem(ItemH: QListViewItemH): TCustomViewItem;
    procedure SetUpdateState(Updating: Boolean);
    property Owner: TCustomViewControl read FOwner;
    property Handle: QListViewH read GetHandle;
  public
    constructor Create(AOwner: TCustomViewControl); virtual;
    destructor Destroy; override;
    procedure BeginUpdate;
    procedure Clear;
    procedure EndUpdate;
    procedure ChangeItemTypes(NewType: TListViewItemType);
    function IndexOf(Value: TCustomViewItem): Integer;
    procedure Delete(Index: Integer);
    property Count: Integer read GetCount;
    property Item[Index: Integer]: TCustomViewItem read GetItem write SetItem; default;
  end;

{ TListItems }

  TListItemClass = class of TListItem;

  TListItems = class(TCustomViewItems)
  private
    FListItemClass: TListItemClass;
    function GetItem(Index: Integer): TListItem;
    procedure SetItem(Index: Integer; const Value: TListItem);
    function GetItemsOwner: TCustomListView;
  protected
    procedure DefineProperties(Filer: TFiler); override;
    function FindItem(ItemH: QListViewItemH): TListItem;
    procedure ReadData(Stream: TStream);
    procedure WriteData(Stream: TStream);
  public
    constructor Create(AOwner: TCustomViewControl); overload; override;
    constructor Create(AOwner: TCustomViewControl; AItemClass: TListItemClass); reintroduce; overload;
    function Add: TListItem;
    function AddItem(Item: TListItem; Index: Integer = -1): TListItem;
    function Insert(Index: Integer): TListItem;
    procedure SetItemClass(AListItemClass: TListItemClass);
    property Item[Index: Integer]: TListItem read GetItem write SetItem; default;
    property Owner: TCustomListView read GetItemsOwner;
  end;

  TItemState = (isNone, isFocused, isSelected, isActivating);
  TItemStates = set of TItemState;

{ TCustomViewItem }

  TCustomViewItem = class(TPersistent)
  private
    FSubItems: TStrings;
    FOwner: TCustomViewItems;
    FItemType: TListViewItemType;
    FParent: TCustomViewItem;
    FNextItem: TCustomViewItem;
    FPrevItem: TCustomViewItem;
    FLastChild: TCustomViewItem;
    FData: Pointer;
    FChecked: Boolean;
    FExpandable: Boolean;
    FSelectable: Boolean;
    FText: WideString;
    FStates: TItemStates;
    FImageIndex: TImageIndex;
    FDestroying: Boolean;
    function ViewControlValid: Boolean;
    procedure DetermineCreationType;
    procedure SetCaption(const Value: WideString);
    function GetChildCount: Integer;
    function GetTotalHeight: Integer;
    function GetExpanded: Boolean;
    procedure SetExpanded(const Value: Boolean);
    function GetHeight: Integer;
    function GetSelected: Boolean;
    procedure SetExpandable(const Value: Boolean);
    procedure SetSelectable(const Value: Boolean);
    procedure SetSelected(const Value: Boolean);
    procedure SetChecked(const Value: Boolean);
    procedure SetItemType(const Value: TListViewItemType);
    procedure SetParent(const Value: TCustomViewItem);
    function GetIndex: Integer;
    procedure SetImageIndex(const Value: TImageIndex);
    function GetSubItemImages(Column: Integer): Integer;
    procedure SetSubItemImages(Column: Integer; const Value: Integer);
    function ItemHook: QClxListViewHooksH;
    function GetWidth: Integer;
    procedure SetSubItems(const Value: TStrings);
    function GetSubItems: TStrings;
    procedure UpdateImages;
    function GetFocused: Boolean;
    procedure SetFocused(const Value: Boolean);
  protected
    FHandle: QListViewItemH;
    procedure Collapse;
    procedure CreateWidget(AParent, After: TCustomViewItem);
    procedure DestroyWidget;
    procedure Expand;
    function GetHandle: QListViewItemH;
    function HandleAllocated: Boolean;
    procedure ImageIndexChange(ColIndex: Integer; NewIndex: Integer); virtual;
    procedure InsertItem(AItem: TCustomViewItem);
    function ParentCount: Integer;
    procedure ReCreateItem;
    procedure RemoveItem(AItem: TCustomViewItem);
    procedure Repaint;
    procedure ResetFields; virtual;
    function ViewControl: TCustomViewControl;
    property Caption: WideString read FText write SetCaption;
    property Checked: Boolean read FChecked write SetChecked;
    property ChildCount: Integer read GetChildCount;
    property Data: Pointer read FData write FData;
    property Expandable: Boolean read FExpandable write SetExpandable;
    property Expanded: Boolean read GetExpanded write SetExpanded;
    property Focused: Boolean read GetFocused write SetFocused;
    property Handle: QListViewItemH read GetHandle;
    property Height: Integer read GetHeight;
    property ImageIndex: TImageIndex read FImageIndex write SetImageIndex;
    property Index: Integer read GetIndex;
    property ItemType: TListViewItemType read FItemType write SetItemType;
    property Owner: TCustomViewItems read FOwner;
    property Parent: TCustomViewItem read FParent write SetParent;
    property Selectable: Boolean read FSelectable write SetSelectable;
    property Selected: Boolean read GetSelected write SetSelected;
    property States: TItemStates read FStates;
    property SubItemImages[Column: Integer]: Integer read GetSubItemImages write SetSubItemImages;
    property SubItems: TStrings read GetSubItems write SetSubItems;
    property TotalHeight: Integer read GetTotalHeight;
    property Width: Integer read GetWidth;
  public
    constructor Create(AOwner: TCustomViewItems; AParent: TCustomViewItem = nil; After: TCustomViewItem = nil); virtual;
    destructor Destroy; override;
    procedure AssignTo(Dest: TPersistent); override;
    procedure Delete;
    function DisplayRect: TRect;
    procedure MakeVisible(PartialOK: Boolean);
  end;

{ TListItem }

  TListItem = class(TCustomViewItem)
  private
    function GetListView: TCustomListView;
    function GetOwnerlist: TListItems;
    function IsEqual(Item: TListItem): Boolean;
    {$IF not (defined(LINUX) and defined(VER140))}
    function GetCaption: WideString;
    procedure SetCaption(Value: WideString);
    {$IFEND}
  public
    destructor Destroy; override;
    {$IF defined(LINUX) and defined(VER140)}
    property Caption read FText write SetCaption;
    {$ELSE}
    property Caption read GetCaption write SetCaption;
    {$IFEND}
    property Checked;
    property Data;
    property Focused;
    property Handle;
    property ImageIndex;
    property Index;
    property ItemType;
    property ListView: TCustomListView read GetListView;
    property Owner: TListItems read GetOwnerList;
    property Selectable;
    property Selected;
    property SubItemImages;
    property SubItems;
  end;

{ TItemEditor }

  TItemEditor = class(TCustomEdit)
  private
    FMenuHook: QPopupMenu_hookH;
    FItem: TCustomViewItem;
    FEditing: Boolean;
    FShouldClose: Boolean;
    FPopup: QPopupMenuH;
    FFrame: QFrameH;
    FFrameHooks: QFrame_hookH;
    FViewControl: TCustomViewControl;
    procedure FrameDestroyedHook; cdecl;
    function PopupMenuFilter(Sender: QObjectH; Event: QEventH): Boolean; cdecl;
  protected
    procedure ClearMenuHook;
    procedure CreateWidget; override;
    procedure Execute; virtual;
    procedure EditFinished(Accepted: Boolean); virtual;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure HookEvents; override;
    procedure InitItem;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyUp(var Key: Word; Shift: TShiftState); override;
    procedure KeyPress(var Key: Char); override;
    procedure KeyString(var S: WideString; var Handled: Boolean); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

{ TCustomViewControl }

  TItemChange = (ctText, ctImage, ctState);
  TSortDirection = (sdAscending, sdDescending);
  TCustomDrawState = set of (cdsSelected, cdsGrayed, cdsDisabled, cdsChecked,
    cdsFocused, cdsDefault, cdsHot, cdsMarked, cdsIndeterminate);
  TCustomDrawStage = (cdPrePaint, cdPostPaint);

  TViewColumnRClickEvent = procedure(Sender: TObject; Column: TListColumn;
    const Point: TPoint) of object;
  TViewColumnEvent = procedure(Sender: TObject; Column: TListColumn) of object;
  TViewColumnClickEvent = TViewColumnEvent;
  TViewColumnResizeEvent = TViewColumnEvent;
  TViewColumnMovedEvent = TViewColumnEvent;
  TCustomDrawViewItemEvent = procedure(Sender: TCustomViewControl;
    Item: TCustomViewItem; Canvas: TCanvas; const Rect: TRect;
    State: TCustomDrawState; Stage: TCustomDrawStage;
    var DefaultDraw: Boolean) of object;
  TCustomDrawViewSubItemEvent = procedure(Sender: TCustomViewControl;
    Item: TCustomViewItem; SubItem: Integer; Canvas: TCanvas; const Rect: TRect;
    State: TCustomDrawState; Stage: TCustomDrawStage;
    var DefaultDraw: Boolean) of object;

  TCustomViewControl = class(TFrameControl)
  private
    FShowColumnSortIndicators: Boolean;
    FMultiSelect: Boolean;
    FRowSelect: Boolean;
    FShowColumnHeaders: Boolean;
    FImageList: TCustomImageList;
    FHeader: TCustomHeaderControl;
    FMemStream: TMemoryStream;
    FViewportHandle: QWidgetH;
    FViewportHooks: QWidget_hookH;
    FHScrollHooks: QScrollBar_hookH;
    FVScrollHooks: QScrollBar_hookH;
    FVScrollHandle: QScrollBarH;
    FHScrollHandle: QScrollBarH;
    FItemHooks: QClxListViewHooksH;
    FOnColumnClick: TViewColumnClickEvent;
    FColumnDragged: TViewColumnMovedEvent;
    FColumnResize: TViewColumnResizeEvent;
    FOnCustomDrawItem: TCustomDrawViewItemEvent;
    FOnCustomDrawSubItem: TCustomDrawViewSubItemEvent;
    FOnCustomDrawBranch: TCustomDrawViewItemEvent;
    FSorted: Boolean;
    FSortColumn: Integer;
    FSortDirection: TSortDirection;
    FOwnerDraw: Boolean;
    FTimer: TTimer;
    FAllowEdit: Boolean;
    FReadOnly: Boolean;
    FEditor: TItemEditor;
    FSelCount: Integer;
    FIndent: Integer;
    FImageLink: TChangeLink;
    procedure ImageListChange(Sender: TObject);
    procedure RepopulateItems; virtual;
    procedure CheckRemoveEditor;
    procedure SetIndent(const Value: Integer);
    function GetHandle: QListViewH;
    function GetIndent: Integer;
    procedure SetMultiSelect(const Value: Boolean);
    function GetMultiSelect: Boolean;
    function GetRowSelect: Boolean;
    procedure SetRowSelect(const Value: Boolean);
    procedure SetImageList(const Value: TCustomImageList);
    procedure ItemDestroyedHook(AItem: QListViewItemH); cdecl;
    procedure ItemDestroyed(AItem: QListViewItemH); virtual;
    procedure ItemPaintHook(p: QPainterH; item: QListViewItemH; column, width,
      alignment: Integer; var stage: Integer) cdecl;
    procedure BranchPaintHook(p: QPainterH; item: QListViewItemH;
    w, y, h: Integer; style: GUIStyle; var stage: Integer) cdecl;
    procedure ItemChangeHook(item: QListViewItemH; _type: TItemChange); cdecl;
    procedure ItemChange(item: QListViewItemH; _type: TItemChange); virtual;
    procedure ItemChangingHook(item: QListViewItemH; _type: TItemChange;
      var Allow: Boolean); cdecl;
    procedure ItemChanging(item: QListViewItemH; _type: TItemChange;
      var Allow: Boolean); virtual;
    procedure ItemSelectedHook(item: QListViewItemH; wasSelected: Boolean); cdecl;
    procedure ItemSelected(item: QListViewItemH; wasSelected: Boolean); virtual;
    procedure ItemExpandingHook(item: QListViewItemH; Expand: Boolean;
      var Allow: Boolean); cdecl;
    procedure ItemExpanding(item: QListViewItemH; Expand: Boolean;
      var Allow: Boolean); virtual;
    procedure ItemExpandedHook(item: QListViewItemH; Expand: Boolean); cdecl;
    procedure ItemExpanded(item: QListViewItemH; Expand: Boolean); virtual;
    procedure ItemCheckedHook(item: QListViewItemH; Checked: Boolean); cdecl;
    procedure ItemChecked(item: QListViewItemH; Checked: Boolean); virtual;
    function GetColumnClick: Boolean;
    procedure SetColumnClick(const Value: Boolean);
    procedure SetColumns(const Value: TListColumns);
    function GetColumns: TListColumns;
    procedure SetShowColumnSortIndicators(const Value: Boolean);
    function GetColumnResize: Boolean;
    procedure SetColumnResize(const Value: Boolean);
    function GetColumnMove: Boolean;
    procedure SetColumnMove(const Value: Boolean);
    procedure SetSorted(const Value: Boolean);
    procedure SetOwnerDraw(const Value: Boolean);
    procedure TimerIntervalElapsed(Sender: TObject);
    procedure StartEditTimer;
    procedure EditItem;
    procedure ViewportDestroyed; cdecl;
  protected
    procedure BeginAutoDrag; override;
    procedure ColorChanged; override;
    procedure CreateWidget; override;
    function CreateEditor: TItemEditor; virtual;
    function DoCustomDrawViewItem(Item: TCustomViewItem; Canvas: TCanvas; const Rect: TRect;
      State: TCustomDrawState; Stage: TCustomDrawStage): Boolean; virtual;
    function DoCustomDrawViewSubItem(Item: TCustomViewItem; SubItem: Integer; Canvas: TCanvas;
      const Rect: TRect; State: TCustomDrawState; Stage: TCustomDrawStage): Boolean; virtual;
    function DoCustomDrawViewBranch(Item: TCustomViewItem; Canvas: TCanvas; const Rect: TRect;
      State: TCustomDrawState; Stage: TCustomDrawStage): Boolean; virtual;
    procedure DoDrawItem(Item: TCustomViewItem; Canvas: TCanvas; const Rect: TRect;
      State: TOwnerDrawState); virtual;
    procedure DoEditing(AItem: TCustomViewItem; var AllowEdit: Boolean); dynamic;
    procedure DoEdited(AItem: TCustomViewItem; var S: WideString); dynamic;
    procedure DoGetImageIndex(item: TCustomViewItem); virtual;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    function FindDropTarget: TCustomViewItem;
    function GetChildHandle: QWidgetH; override;
    procedure HookEvents; override;
    procedure InitWidget; override;
    function IsCustomDrawn: Boolean; virtual;
    function IsOwnerDrawn: Boolean; virtual;
    function NeedKey(Key: Integer; Shift: TShiftState;
      const KeyText: WideString): Boolean; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure ImageListChanged; virtual;
    procedure SetShowColumnHeaders(const Value: Boolean);
    procedure UpdateControl;
    function ViewportHandle: QWidgetH;
    procedure WidgetDestroyed; override;
    property ColumnClick: Boolean read GetColumnClick write SetColumnClick default False;
    property ColumnResize: Boolean read GetColumnResize write SetColumnResize default False;
    property ColumnMove: Boolean read GetColumnMove write SetColumnMove default True;
    property Columns: TListColumns read GetColumns write SetColumns;
    property Images: TCustomImageList read FImageList write SetImageList;
    property Height default 97;
    property Indent: Integer read GetIndent write SetIndent default 20;
    property MultiSelect: Boolean read GetMultiSelect write SetMultiSelect;
    property OwnerDraw: Boolean read FOwnerDraw write SetOwnerDraw default False;
    property ParentColor default False;
    property ReadOnly: Boolean read FReadOnly write FReadOnly default False;
    property RowSelect: Boolean read GetRowSelect write SetRowSelect default False;
    property SelCount: Integer read FSelCount default 0;
    property ShowColumnHeaders: Boolean read FShowColumnHeaders
      write SetShowColumnHeaders default False;
    property ShowColumnSortIndicators: Boolean read FShowColumnSortIndicators
      write SetShowColumnSortIndicators default False;
    property SortColumn: Integer read FSortColumn write FSortColumn default 0;
    property SortDirection: TSortDirection read FSortDirection
      write FSortDirection default sdAscending;
    property Sorted: Boolean read FSorted write SetSorted default False;
    property TabStop default True;
    property Width default 121;
    property OnColumnClick: TViewColumnClickEvent read FOnColumnClick
      write FOnColumnClick;
    property OnColumnDragged: TViewColumnMovedEvent read FColumnDragged
      write FColumnDragged;
    property OnColumnResize: TViewColumnResizeEvent read FColumnResize
      write FColumnResize;
    property OnCustomDrawBranch: TCustomDrawViewItemEvent read FOnCustomDrawBranch
      write FOnCustomDrawBranch;
    property OnCustomDrawItem: TCustomDrawViewItemEvent read FOnCustomDrawItem
      write FOnCustomDrawItem;
    property OnCustomDrawSubItem: TCustomDrawViewSubItemEvent read FOnCustomDrawSubItem
      write FOnCustomDrawSubItem;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure InvertSelection;
    function IsEditing: Boolean;
    procedure Sort(Column: Integer; Direction: TSortDirection);
    property Handle: QListViewH read GetHandle;
  end;

{ TCustomListView }

  TItemFind = (ifData, ifPartialString, ifExactString, ifNearest);
  TSearchDirection = (sdAbove, sdBelow, sdAll);
  TViewStyle = (vsList, vsReport);

  TLVNotifyEvent = procedure (Sender: TObject; Item: TListItem) of object;
  TLVChangeEvent = procedure (Sender: TObject; Item: TListItem;
    Change: TItemChange) of object;
  TLVChangingEvent = procedure (Sender: TObject; Item: TListItem;
    Change: TItemChange; var AllowChange: Boolean) of object;
  TLVItemExitViewportEnterEvent = TNotifyEvent;
  TLVSelectItemEvent = procedure (Sender: TObject; Item: TListItem;
    Selected: Boolean) of object;
  TLVItemClickEvent = procedure (Sender: TObject; Button: TMouseButton;
    Item: TListItem; const Pt: TPoint; ColIndex: Integer) of object;
  TLVItemDoubleClickEvent = TLVNotifyEvent;
  TLVEditingEvent = procedure (Sender: TObject; Item: TListItem;
    var AllowEdit: Boolean) of object;
  TLVEditedEvent = procedure (Sender: TObject; Item: TListItem;
    var S: WideString) of object;
  TLVButtonDownEvent = procedure (Sender: TObject; Button: TMouseButton;
    Item: TListItem; const Pt: TPoint; ColIndex: Integer) of object;
  TLVViewportButtonDownEvent = procedure (Sender: TObject; Button: TMouseButton;
    const Pt: TPoint) of object;
  TListViewDrawItemEvent = procedure(Sender: TCustomListView; Item: TListItem;
    Canvas: TCanvas; const Rect: TRect; State: TOwnerDrawState) of object;

  TCustomListView = class(TCustomViewControl)
  private
    FSelected: TListItem;
    FItems: TListItems;
    FCheckBoxes: Boolean;
    FOnInsert: TLVNotifyEvent;
    FOnChange: TLVChangeEvent;
    FOnChanging: TLVChangingEvent;
    FOnDeletion: TLVNotifyEvent;
    FOnSelectItem: TLVSelectItemEvent;
    FOnItemClick: TLVItemClickEvent;
    FOnItemDoubleClick: TLVItemDoubleClickEvent;
    FOnItemEnter: TLVNotifyEvent;
    FOnItemExitViewportEnter: TLVItemExitViewportEnterEvent;
    FOnMouseDown: TLVButtonDownEvent;
    FOnViewportMouseDown: TLVViewportButtonDownEvent;
    FOnEditing: TLVEditingEvent;
    FOnEdited: TLVEditedEvent;
    FViewStyle: TViewStyle;
    FDownsHooked: Boolean;
    FOnGetImageIndex: TLVNotifyEvent;
    FOnDrawItem: TListViewDrawItemEvent;
    procedure RepopulateItems; override;
    procedure SetItems(const Value: TListItems);
    procedure SetCheckBoxes(const Value: Boolean);
    procedure UpdateItemTypes;
    procedure HookMouseDowns;
    procedure DoItemDoubleClick(ListItem: QListViewItemH); cdecl;
    procedure DoItemClick(Button: Integer; ListItem: QListViewItemH;
      Pt: PPoint; ColIndex: Integer); cdecl;
    procedure DoOnItemEnter(ListItem: QListViewItemH); cdecl;
    procedure DoOnItemExitViewportEnter; cdecl;
    procedure DoLVMouseDown(Button: Integer; ListItem: QListViewItemH;
      Pt: PPoint; ColIndex: Integer); cdecl;
    procedure SetOnItemDoubleClick(const Value: TLVItemDoubleClickEvent);
    procedure SetOnItemEnter(const Value: TLVNotifyEvent);
    procedure SetOnItemExitViewportEnter(const Value: TLVItemExitViewportEnterEvent);
    procedure SetOnMouseDown(const Value: TLVButtonDownEvent);
    procedure SetOnViewportButtonDown(const Value: TLVViewportButtonDownEvent);
    procedure SetViewStyle(const Value: TViewStyle);
    function GetSelected: TListItem;
    procedure SetSelected(const Value: TListItem);
    function GetItemFocused: TListItem;
    procedure SetItemFocused(const Value: TListItem);
    procedure SetTopItem(const AItem: TListItem);
    function GetTopItem: TListItem;
  protected
    procedure DoDrawItem(Item: TCustomViewItem; Canvas: TCanvas; const Rect: TRect;
      State: TOwnerDrawState); override;
    procedure DoEdited(AItem: TCustomViewItem; var S: WideString); override;
    procedure DoEditing(AItem: TCustomViewItem; var AllowEdit: Boolean); override;
    procedure DoGetImageIndex(item: TCustomViewItem); override;
    function GetDropTarget: TListItem;
    procedure HookEvents; override;
    procedure ImageListChanged; override;
    procedure Init(AListItemClass: TListItemClass); virtual;
    procedure InitWidget; override;
    function IsOwnerDrawn: Boolean; override;
    procedure ItemChange(item: QListViewItemH; _type: TItemChange); override;
    procedure ItemChanging(item: QListViewItemH; _type: TItemChange;
      var Allow: Boolean); override;
    procedure ItemChecked(item: QListViewItemH; Checked: Boolean); override;
    procedure ItemDestroyed(AItem: QListViewItemH); override;
    procedure ItemSelected(item: QListViewItemH; wasSelected: Boolean); override;
    procedure RestoreWidgetState; override;
    procedure SaveWidgetState; override;
    property CheckBoxes: Boolean read FCheckBoxes write SetCheckBoxes
      default False;
    property Height default 150;
    property Items: TListItems read FItems write SetItems;
    property ReadOnly default False;
    property SortDirection default sdAscending;
    property ViewStyle: TViewStyle read FViewStyle write SetViewStyle
      default vsList;
    property OnChange: TLVChangeEvent read FOnChange write FOnChange;
    property OnChanging: TLVChangingEvent read FOnChanging write FOnChanging;
    property OnDeletion: TLVNotifyEvent read FOnDeletion write FOnDeletion;
    property OnDrawItem: TListViewDrawItemEvent read FOnDrawItem write FOnDrawItem;
    property OnEdited: TLVEditedEvent read FOnEdited write FOnEdited;
    property OnEditing: TLVEditingEvent read FOnEditing write FOnEditing;
    property OnGetImageIndex: TLVNotifyEvent read FOnGetImageIndex
      write FOnGetImageIndex;
    property OnInsert: TLVNotifyEvent read FOnInsert write FOnInsert;
    property OnItemClick: TLVItemClickEvent read FOnItemClick write FOnItemClick;
    property OnItemDoubleClick: TLVItemDoubleClickEvent read FOnItemDoubleClick
      write SetOnItemDoubleClick;
    property OnItemEnter: TLVNotifyEvent read FOnItemEnter write SetOnItemEnter;
    property OnItemExitViewportEnter: TLVItemExitViewportEnterEvent
      read FOnItemExitViewportEnter write SetOnItemExitViewportEnter;
    property OnItemMouseDown: TLVButtonDownEvent read FOnMouseDown
      write SetOnMouseDown;
    property OnSelectItem: TLVSelectItemEvent read FOnSelectItem
      write FOnSelectItem;
    property OnViewPortMouseDown: TLVViewportButtonDownEvent
      read FOnViewportMouseDown write SetOnViewportButtonDown;
  public
    constructor Create(AOwner: TComponent); overload; override;
    constructor Create(AOwner: TComponent; AListItemClass: TListItemClass); reintroduce; overload;
    destructor Destroy; override;
    function AlphaSort: Boolean;
    function FindData(StartIndex: Integer; Value: Pointer; Inclusive,
      Wrap: Boolean): TListItem;
    function FindCaption(StartIndex: Integer; const Value: WideString;
      Partial, Inclusive, Wrap: Boolean): TListItem;
    function GetItemAt(X, Y: Integer): TListItem;
    function GetNearestItem(const Point: TPoint;
      Direction: TSearchDirection): TListItem;
    function GetNextItem(StartItem: TListItem; Direction: TSearchDirection;
      States: TItemStates): TListItem;
    procedure Scroll(DX, DY: Integer);
    procedure UpdateItems(FirstIndex, LastIndex: Integer);
    property DropTarget: TListItem read GetDropTarget;
    property ItemFocused: TListItem read GetItemFocused write SetItemFocused;
    property Selected: TListItem read GetSelected write SetSelected;
    property TopItem: TListItem read GetTopItem write SetTopItem;
  end;

{ TListView }

  TListView = class(TCustomListView)
  public
    property SortColumn;
  published
    property Align;
    property Anchors;
    property BorderStyle default bsSunken3d;
    property CheckBoxes default False;
    property Color;
    property ColumnClick default True;
    property ColumnMove default True;
    property ColumnResize default True;
    property Columns;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property Height;
    property Hint;
    property Images;
    property Items;
    property MultiSelect default False;
    property OwnerDraw;
    property RowSelect default False;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ReadOnly;
    property SelCount;
    property ShowColumnSortIndicators;
    property ShowHint;
    property SortDirection;
    property Sorted;
    property TabOrder;
    property TabStop;
    property ViewStyle;
    property Visible;
    property Width;
    property OnChange;
    property OnChanging;
    property OnClick;
    property OnColumnClick;
    property OnColumnDragged;
    property OnColumnResize;
    property OnContextPopup;
    property OnCustomDrawItem;
    property OnCustomDrawSubItem;
    property OnDblClick;
    property OnDeletion;
    property OnDragDrop;
    property OnDragOver;
    property OnDrawItem;
    property OnEdited;
    property OnEditing;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnGetImageIndex;
    property OnInsert;
    property OnItemClick;
    property OnItemDoubleClick;
    property OnItemEnter;
    property OnItemExitViewportEnter;
    property OnItemMouseDown;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnResize;
    property OnSelectItem;
    property OnStartDrag;
    property OnViewPortMouseDown;
  end;

{ ETreeViewError }

  ETreeViewError = class(Exception);

{ TTreeNodes }

  TNodeAttachMode = (naAdd, naAddFirst, naAddChild, naAddChildFirst, naInsert);
  TAddMode = (taAddFirst, taAdd, taInsert);
  TTreeNodeClass = class of TTreeNode;

  TTreeNodes = class(TCustomViewItems)
  private
    FNodeClass: TTreeNodeClass;
    function GetItem(Index: Integer): TTreeNode;
    function GetNodesOwner: TCustomTreeView;
    procedure ReadData(Stream: TStream);
    procedure WriteData(Stream: TStream);
  protected
    function CreateNode(ParentNode: TTreeNode = nil; AfterNode: TTreeNode = nil): TTreeNode;
    procedure DefineProperties(Filer: TFiler); override;
    function InternalAddObject(Node: TTreeNode; const S: WideString;
      Ptr: Pointer; AddMode: TAddMode): TTreeNode;
    function FindItem(ItemH: QListViewItemH): TTreeNode;
    function FindPrevSibling(ANode: TTreeNode): TTreeNode;
  public
    function Add(Node: TTreeNode; const S: WideString): TTreeNode;
    function AddChild(Node: TTreeNode; const S: WideString): TTreeNode;
    function AddChildFirst(Node: TTreeNode; const S: WideString): TTreeNode;
    function AddChildObject(Node: TTreeNode; const S: WideString; Ptr: Pointer): TTreeNode;
    function AddChildObjectFirst(Node: TTreeNode; const S: WideString; Ptr: Pointer): TTreeNode;
    function AddFirst(Node: TTreeNode; const S: WideString): TTreeNode;
    function AddObject(Node: TTreeNode; const S: WideString; Ptr: Pointer): TTreeNode;
    function AddObjectFirst(Node: TTreeNode; const S: WideString; Ptr: Pointer): TTreeNode;
    procedure Assign(Dest: TPersistent); override;
    procedure Clear;
    procedure Delete(Node: TTreeNode);
    function GetFirstNode: TTreeNode;
    function GetNode(ItemH: QListViewItemH): TTreeNode;
    function Insert(Node: TTreeNode; const S: WideString): TTreeNode;
    function InsertObject(Node: TTreeNode; const S: WideString; Ptr: Pointer): TTreeNode;
    procedure SetNodeClass(NewNodeClass: TTreeNodeClass);
    property Item[Index: Integer]: TTreeNode read GetItem; default;
    property Owner: TCustomTreeView read GetNodesOwner;
  end;

{ TTreeNode }

  PNodeInfo = ^TNodeInfo;
  TNodeInfo = packed record
    ImageIndex: Integer;
    SelectedIndex: Integer;
    StateIndex: Integer;
    SubItemCount: Integer;
    Data: Pointer;
    Count: Integer;
    Text: string[255];
  end;

  TTreeNode = class(TCustomViewItem)
  private
    FDeleting: Boolean;
    FSelectedIndex: Integer;
    function DoCanExpand(Expand: Boolean): Boolean;
    procedure ExpandItem(Expand: Boolean; Recurse: Boolean);
    function GetCount: Integer;
    function GetItem(Index: Integer): TTreeNode;
    function GetLevel: Integer;
    function GetParent: TTreeNode;
    function GetIndex: Integer;
    function GetTreeView: TCustomTreeView;
    function IsNodeVisible: Boolean;
    function IsEqual(Node: TTreeNode): Boolean;
    procedure SetItem(Index: Integer; const Value: TTreeNode);
    function GetNodeOwner: TTreeNodes;
    procedure SetNodeParent(const Value: TTreeNode);
    procedure SetSelectedIndex(const Value: Integer);
    function GetDropTarget: Boolean;
    {$IF not (defined(LINUX) and defined(VER140))}
    function GetSelected: Boolean;
    procedure SetSelected(const Value: Boolean);
    function GetExpandable: Boolean;
    procedure SetExpandable(const Value: Boolean);
    function GetCaption: WideString;
    procedure SetCaption(const Value: WideString);
    {$IFEND}
  protected
    function CompareCount(CompareMe: Integer): Boolean;
    function GetAbsoluteIndex: Integer;
    procedure ImageIndexChange(ColIndex: Integer; NewIndex: Integer); override;
    procedure ReadData(Stream: TStream; Info: PNodeInfo);
    procedure WriteData(Stream: TStream; Info: PNodeInfo);
  public
    constructor Create(AOwner: TCustomViewItems; AParent:
      TCustomViewItem = nil; After: TCustomViewItem = nil); override;
    destructor Destroy; override;
    procedure AssignTo(Dest: TPersistent); override;
    procedure Collapse(Recurse: Boolean);
    function AlphaSort(Ascending: Boolean): Boolean;
    procedure Delete;
    procedure DeleteChildren;
    function EditText: Boolean;
    procedure Expand(Recurse: Boolean);
    function getFirstChild: TTreeNode;
    function GetLastChild: TTreeNode;
    function GetNext: TTreeNode;
    function GetNextChild(Value: TTreeNode): TTreeNode;
    function getNextSibling: TTreeNode;
    function GetNextVisible: TTreeNode;
    function GetPrev: TTreeNode;
    function GetPrevChild(Value: TTreeNode): TTreeNode;
    function getPrevSibling: TTreeNode;
    function GetPrevVisible: TTreeNode;
    function HasAsParent(Value: TTreeNode): Boolean;
    function IndexOf(Value: TTreeNode): Integer;
    procedure MoveTo(Destination: TTreeNode; Mode: TNodeAttachMode); virtual;
    property AbsoluteIndex: Integer read GetAbsoluteIndex;
    property Checked;
    property Count: Integer read GetCount;
    property Data;
    property Deleting: Boolean read FDeleting;
    property DropTarget: Boolean read GetDropTarget;
    property Focused: Boolean read GetSelected write SetSelected;
    property Expanded;
    property Handle;
    {$IF defined(LINUX) and defined(VER140)}
    property HasChildren: Boolean read FExpandable write SetExpandable;
    {$ELSE}
    property HasChildren: Boolean read GetExpandable write SetExpandable;
    {$IFEND}
    property Height;
    property ImageIndex;
    property Index: Integer read GetIndex;
    property IsVisible: Boolean read IsNodeVisible;
    property ItemType;
    property Item[Index: Integer]: TTreeNode read GetItem write SetItem; default;
    property Level: Integer read GetLevel;
    property Owner: TTreeNodes read GetNodeOwner;
    property Parent: TTreeNode read GetParent write SetNodeParent;
    property Selected;
    property SelectedIndex: Integer read FSelectedIndex write SetSelectedIndex; 
    {$IF defined(LINUX) and defined(VER140)}
    property Text: WideString read FText write SetCaption;
    {$ELSE}
    property Text: WideString read GetCaption write SetCaption;
    {$IFEND}
    property TotalHeight;
    property TreeView: TCustomTreeView read GetTreeView;
    property Selectable;
    property SubItemImages;
    property SubItems;
  end;

{ TCustomTreeView }

  TSortType = (stNone, stText);

  TTVItemNotifyEvent = procedure(Sender: TObject; Node: TTreeNode) of object;
  TTVDeletedEvent = TTVItemNotifyEvent;
  TTVItemEnterEvent = TTVItemNotifyEvent;
  TTVItemExitViewportEnterEvent = TNotifyEvent;
  TTVChangedEvent = TTVItemNotifyEvent;
  TTVChangingEvent = procedure(Sender: TObject; Node: TTreeNode;
    var AllowChange: Boolean) of object;
  TTVExpandingEvent = procedure(Sender: TObject; Node: TTreeNode;
    var AllowExpansion: Boolean) of object;
  TTVCollapsingEvent = procedure(Sender: TObject; Node: TTreeNode;
    var AllowCollapse: Boolean) of object;
  TTVExpandedEvent = TTVItemNotifyEvent;
  TTVCollapsedEvent = TTVExpandedEvent;
  TTVSelectItemEvent = procedure(Sender: TObject; Node: TTreeNode;
    Selected: Boolean) of object;
  TTVEditingEvent = procedure (Sender: TObject; Node: TTreeNode;
    var AllowEdit: Boolean) of object;
  TTVEditedEvent = procedure (Sender: TObject; Node: TTreeNode;
    var S: WideString) of object;
  TTVItemClickEvent = procedure (Sender: TObject; Button: TMouseButton;
    Node: TTreeNode; const Pt: TPoint) of object;
  TTVItemDoubleClickEvent = procedure (Sender: TObject;
    Node: TTreeNode) of object;
  TTVButtonDownEvent = procedure (Sender: TObject; Button: TMouseButton;
    Node: TTreeNode; const Pt: TPoint) of object;
  TTVViewportButtonDownEvent = procedure (Sender: TObject; Button: TMouseButton;
    const Pt: TPoint) of object;

  TCustomTreeView = class(TCustomViewControl)
  private
    FTreeNodes: TTreeNodes;
    FSelectedNode: TTreeNode;
    FLastNode: TTreeNode;
    FSortType: TSortType;
    FShowButtons: Boolean;
    FMemStream: TMemoryStream;
    FOnChange: TTVChangedEvent;
    FOnChanging: TTVChangingEvent;
    FOnCollapsing: TTVCollapsingEvent;
    FOnDeletion: TTVExpandedEvent;
    FOnCollapsed: TTVExpandedEvent;
    FOnExpanded: TTVExpandedEvent;
    FOnExpanding: TTVExpandingEvent;
    FAutoExpand: Boolean;
    FOnMouseDown: TTVButtonDownEvent;
    FOnInsert: TTVDeletedEvent;
    FOnItemClick: TTVItemClickEvent;
    FOnItemDoubleClick: TTVItemDoubleClickEvent;
    FOnItemEnter: TTVItemEnterEvent;
    FOnItemExitViewportEnter: TTVItemExitViewportEnterEvent;
    FOnViewportMouseDown: TTVViewportButtonDownEvent;
    FOnEdited: TTVEditedEvent;
    FOnEditing: TTVEditingEvent;
    FOnGetImageIndex: TTVExpandedEvent;
    FOnGetSelectedIndex: TTVExpandedEvent;
    FFullExpansion: Boolean;
    FItemMargin: Integer;
    procedure RepopulateItems; override;
    procedure DoAutoExpand(ExpandedNode: TTreeNode);
    procedure SetSortType(const Value: TSortType);
    procedure SetAutoExpand(const Value: Boolean);
    function GetSelected: TTreeNode;
    procedure SetSelected(const Value: TTreeNode);
    procedure SetItemMargin(const Value: Integer);
    procedure HookMouseDowns;
    procedure DoItemClick(p1: Integer; p2: QListViewItemH; p3: PPoint;
      p4: Integer); cdecl;
    procedure DoItemDoubleClick(p1: QListViewItemH); cdecl;
    procedure DoOnItemEnter(item: QListViewItemH); cdecl;
    procedure DoOnItemExitViewportEnter; cdecl;
    procedure DoOnMouseDown(p1: Integer; p2: QListViewItemH; p3: PPoint; p4: Integer); cdecl;
    procedure SetOnItemDoubleClick(const Value: TTVItemDoubleClickEvent);
    procedure SetOnItemEnter(const Value: TTVItemEnterEvent);
    procedure SetOnItemExitViewportEnter(const Value: TTVItemExitViewportEnterEvent);
    procedure SetOnMouseDown(const Value: TTVButtonDownEvent);
    procedure SetOnViewportButtonDown(const Value: TTVViewportButtonDownEvent);
    procedure SetShowButtons(const Value: Boolean);
    procedure SetItems(const Value: TTreeNodes);
    procedure SetTopItem(const AItem: TTreeNode);
    function GetTopItem: TTreeNode;
    procedure ItemChanging(item: QListViewItemH; _type: TItemChange;
      var Allow: Boolean); override;
    procedure ItemDestroyed(AItem: QListViewItemH); override;
    procedure ItemExpanding(item: QListViewItemH; Expand: Boolean;
      var Allow: Boolean); override;
    procedure ItemExpanded(item: QListViewItemH; Expand: Boolean); override;
    procedure ItemChecked(item: QListViewItemH; Checked: Boolean); override;
    procedure ItemSelected(item: QListViewItemH; wasSelected: Boolean); override;
  protected
    function CanCollapse(Node: TTreeNode): Boolean; dynamic;
    function CanExpand(Node: TTreeNode): Boolean; dynamic;
    procedure Change(Node: TTreeNode); dynamic;
    procedure Collapse(Node: TTreeNode); dynamic;
    procedure Delete(Node: TTreeNode); dynamic;
    procedure DoEdited(AItem: TCustomViewItem; var S: WideString); override;
    procedure DoEditing(AItem: TCustomViewItem; var AllowEdit: Boolean); override;
    procedure DoGetImageIndex(item: TCustomViewItem); override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    function GetDropTarget: TTreeNode;
    procedure Expand(Node: TTreeNode); dynamic;
    procedure HookEvents; override;
    procedure ImageListChanged; override;
    procedure Init(ANodeClass: TTreeNodeClass); virtual;
    procedure InitWidget; override;
    function IsCustomDrawn: Boolean; override;
    procedure Loaded; override;
    procedure RestoreWidgetState; override;
    procedure SaveWidgetState; override;
    property AutoExpand: Boolean read FAutoExpand write SetAutoExpand default False;
    property ItemMargin: Integer read FItemMargin write SetItemMargin default 1;
    property Items: TTreeNodes read FTreeNodes write SetItems;
    property ShowButtons: Boolean read FShowButtons write SetShowButtons default True;
    property SortType: TSortType read FSortType write SetSortType default stNone;
    property OnChange: TTVChangedEvent read FOnChange write FOnChange;
    property OnChanging: TTVChangingEvent read FOnChanging write FOnChanging;
    property OnCollapsed: TTVExpandedEvent read FOnCollapsed write FOnCollapsed;
    property OnCollapsing: TTVCollapsingEvent read FOnCollapsing write FOnCollapsing;
    property OnDeletion: TTVExpandedEvent read FOnDeletion write FOnDeletion;
    property OnEdited: TTVEditedEvent read FOnEdited write FOnEdited;
    property OnEditing: TTVEditingEvent read FOnEditing write FOnEditing;
    property OnExpanding: TTVExpandingEvent read FOnExpanding write FOnExpanding;
    property OnExpanded: TTVExpandedEvent read FOnExpanded write FOnExpanded;
    property OnGetImageIndex: TTVExpandedEvent read FOnGetImageIndex
      write FOnGetImageIndex;
    property OnGetSelectedIndex: TTVExpandedEvent read FOnGetSelectedIndex
      write FOnGetSelectedIndex;
    property OnInsert: TTVDeletedEvent read FOnInsert write FOnInsert;
    property OnItemClick: TTVItemClickEvent read FOnItemClick write FOnItemClick;
    property OnItemDoubleClick: TTVItemDoubleClickEvent read FOnItemDoubleClick
      write SetOnItemDoubleClick;
    property OnItemEnter: TTVItemEnterEvent read FOnItemEnter write SetOnItemEnter;
    property OnItemExitViewportEnter: TTVItemExitViewportEnterEvent
      read FOnItemExitViewportEnter write SetOnItemExitViewportEnter;
    property OnItemMouseDown: TTVButtonDownEvent read FOnMouseDown
      write SetOnMouseDown;
    property OnViewPortMouseDown: TTVViewportButtonDownEvent
      read FOnViewportMouseDown write SetOnViewportButtonDown;
  public
    constructor Create(AOwner: TComponent); overload; override;
    constructor Create(AOwner: TComponent; ANodeClass: TTreeNodeClass); reintroduce; overload;
    destructor Destroy; override;
    function AlphaSort: Boolean;
    procedure FullCollapse;
    procedure FullExpand;
    function GetNodeAt(X, Y: Integer): TTreeNode;
    procedure LoadFromFile(const FileName: string);
    procedure LoadFromStream(Stream: TStream);
    procedure SaveToFile(const FileName: string);
    procedure SaveToStream(Stream: TStream);
    procedure SelectAll(Select: Boolean);
    property DropTarget: TTreeNode read GetDropTarget;
    property Selected: TTreeNode read GetSelected write SetSelected;
    property TopItem: TTreeNode read GetTopItem write SetTopItem;
  end;

{ TTreeView }

  TTreeView = class(TCustomTreeView)
  {$IF not (defined(LINUX) and defined(VER140))}
  private
    function GetSelCount: Integer;
  {$IFEND}
  public
    property SortColumn;
  published
    property Align;
    property Anchors;
    property AutoExpand default False;
    property BorderStyle default bsSunken3d;
    property Color;
    property ColumnClick default True;
    property ColumnMove default True;
    property ColumnResize default True;
    property Columns;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property Height;
    property Hint;
    property Images;
    property ItemMargin;
    property Items;
    property Indent;
    property MultiSelect default False;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ReadOnly;
    property RowSelect;
    {$IF defined(LINUX) and defined(VER140)}
    property SelectionCount: Integer read FSelCount default 0;
    {$ELSE}
    property SelectionCount: Integer read GetSelCount default 0;
    {$IFEND}
    property ShowColumnHeaders;
    property ShowColumnSortIndicators;
    property ShowButtons;
    property ShowHint;
    property Sorted default False;
    property SortType;
    property TabOrder;
    property TabStop;
    property Visible;
    property Width;
    property OnChange;
    property OnChanging;
    property OnClick;
    property OnCollapsed;
    property OnCollapsing;
    property OnColumnClick;
    property OnColumnDragged;
    property OnColumnResize;
    property OnContextPopup;
    property OnCustomDrawBranch;
    property OnCustomDrawItem;
    property OnCustomDrawSubItem;
    property OnDblClick;
    property OnDeletion;
    property OnDragDrop;
    property OnDragOver;
    property OnEdited;
    property OnEditing;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnExpanding;
    property OnExpanded;
    property OnGetImageIndex;
    property OnGetSelectedIndex;
    property OnInsert;
    property OnItemClick;
    property OnItemDoubleClick;
    property OnItemEnter;
    property OnItemExitViewportEnter;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
    property OnItemMouseDown;
    property OnViewPortMouseDown;
  end;

{ TIconView }

  TArrangement = (arLeftToRight, arTopToBottom);
  TResizeMode = (rmFixed, rmAdjust);
  TItemTextPos = (itpBottom, itpRight);

  TCustomIconView = class;
  TIconViewItems = class;
  TIconView = class;

  TIconViewItem = class(TPersistent)
  private
    FOwner: TIconViewItems;
    FDestroying: Boolean;
    FImageIndex: TImageIndex;
    FStates: TItemStates;
    FAllowRename: Boolean;
    FCaption: WideString;
    FSelectable: Boolean;
    procedure SetAllowRename(const Value: Boolean);
    function GetHandle: QIconViewItemH;
    procedure SetCaption(const Value: WideString);
    function GetIndex: Integer;
    function GetSelected: Boolean;
    procedure SetSelected(const Value: Boolean);
    procedure SetSelectable(const Value: Boolean);
    function IconViewValid: Boolean;
    procedure UpdateImage;
    procedure SetImageIndex(const Value: TImageIndex);
    procedure SetStates(const Value: TItemStates);
    function GetIconView: TCustomIconView;
    function GetLeft: Integer;
    function GetTop: Integer;
    function GetWidth: Integer;
    function GetHeight: Integer;
  protected
    FHandle: QIconViewItemH;
    procedure CreateWidget(AfterItem: TIconViewItem);
    procedure InitWidget;
    procedure DestroyWidget;
    function HandleAllocated: Boolean;
    function IsEqual(AItem: TIconViewItem): Boolean;
    property IconView: TCustomIconView read GetIconView;
  public
    constructor Create(AOwner: TIconViewItems; AfterItem: TIconViewItem = nil);
    destructor Destroy; override;
    function BoundingRect: TRect;
    function IconRect: TRect;
    procedure MakeVisible;
    procedure Move(const Pt: TPoint);
    procedure MoveBy(const Pt: TPoint);
    procedure Repaint;
    function TextRect: TRect;
    property AllowRename: Boolean read FAllowRename write SetAllowRename
      default True;
    property Caption: WideString read FCaption write SetCaption;
    property Handle: QIconViewItemH read GetHandle;
    property Height: Integer read GetHeight;
    property ImageIndex: TImageIndex read FImageIndex write SetImageIndex;
    property Index: Integer read GetIndex;
    property Left: Integer read GetLeft;
    property Selectable: Boolean read FSelectable write SetSelectable
      default True;
    property Selected: Boolean read GetSelected write SetSelected;
    property States: TItemStates read FStates write SetStates;
    property Top: Integer read GetTop;
    property Width: Integer read GetWidth;
  end;

{ TiconViewItems }

  TIconViewItemClass = class of TIconViewItem;

  TIconViewItems = class(TPersistent)
  private
    FOwner: TCustomIconView;
    FIconViewItemClass: TIconViewItemClass;
    FUpdateCount: Integer;
    FItems: TObjectList;
  protected
    procedure DefineProperties(Filer: TFiler); override;
    function FindItem(ItemH: QIconViewItemH): TIconViewItem;
    function GetCount: Integer;
    function GetItem(Index: Integer): TIconViewItem;
    function IconViewHandle: QIconViewH;
    procedure ReadData(Stream: TStream);
    procedure SetItem(Index: Integer; AObject: TIconViewItem);
    procedure SetUpdateState(Updating: Boolean); virtual;
    procedure UpdateImages;
    procedure WriteData(Stream: TStream);
  public
    constructor Create(AOwner: TCustomIconView); overload;
    constructor Create(AOwner: TCustomIconView;
      AItemClass: TIconViewItemClass); overload;
    destructor Destroy; override;
    function Add: TIconViewItem;
    procedure BeginUpdate;
    procedure Clear;
    procedure Delete(Index: Integer);
    procedure EndUpdate;
    function IndexOf(Value: TIconViewItem): Integer;
    function Insert(Index: Integer): TIconViewItem;
    procedure SetItemClass(AItemClass: TIconViewItemClass);
    property Count: Integer read GetCount;
    property Item[Index: Integer]: TIconViewItem read GetItem write SetItem; default;
    property Owner: TCustomIconView read FOwner;
  end;

{ TIconOptions }

  TIconArrangement = (iaTop, iaLeft);

  TIconOptions = class(TPersistent)
  private
    FAutoArrange: Boolean;
    FArrangement: TIconArrangement;
    FWrapText: Boolean;
    FIconView: TCustomIconView;
    procedure SetArrangement(Value: TIconArrangement);
    procedure SetAutoArrange(Value: Boolean);
    procedure SetWrapText(Value: Boolean);
  public
    constructor Create(AOwner: TCustomIconView);
  published
    property Arrangement: TIconArrangement read FArrangement
      write SetArrangement default ialeft;
    property AutoArrange: Boolean read FAutoArrange write SetAutoArrange
      default True;
    property WrapText: Boolean read FWrapText write SetWrapText
      default True;
  end;

{ TCustomIconView }

  TIVItemMouseEvent = procedure(Sender: TObject; Button: TMouseButton;
    Item: TIconViewItem; const Pt: TPoint) of object;
  TIVMouseEvent = procedure(Sender: TObject; Button: TMouseButton;
    const Pt: TPoint) of object;
  TIVItemEvent = procedure(Sender: TObject; Item: TIconViewItem) of object;
  TIVSelectItemEvent = procedure(Sender: TObject; Item: TIconViewItem;
    Selected: Boolean) of object;
  TIVItemDoubleClickEvent = TIVItemEvent;
  TIVItemExitViewportEnterEvent = TNotifyEvent;
  TIVItemEnterEvent = TIVItemEvent;
  TIVEditedEvent = procedure(Sender: TObject; Item: TIconViewItem; 
    const NewName: WideString) of object;
  TIVItemClickEvent = procedure(Sender: TObject; Item: TIconViewItem) of object;
  TIVViewportClickedEvent = TIVMouseEvent;
  TIVChangeEvent = procedure (Sender: TObject; Item: TIconViewItem;
    Change: TItemChange) of object;
  TIVChangingEvent = procedure (Sender: TObject; Item: TIconViewItem;
    Change: TItemChange; var AllowChange: Boolean) of object;

  TCustomIconView = class(TFrameControl)
  private
    FItemsMovable: Boolean;
    FMultiSelect: Boolean;
    FResizeMode: TResizeMode;
    FShowToolTips: Boolean;
    FSort: Boolean;
    FSpacing: Integer;
    FSelCount: Integer;
    FTextPosition: TItemTextPos;
    FSortDirection: TSortDirection;
    FItemHooks: QClxIconViewHooksH;
    FIconViewItems: TIconViewItems;
    FOnItemClicked: TIVItemClickEvent;
    FOnItemDoubleClick: TIVItemDoubleClickEvent;
    FOnItemEnter: TIVItemEnterEvent;
    FOnItemExitViewportEnter: TIVItemExitViewportEnterEvent;
    FOnEdited: TIVEditedEvent;
    FOnItemChange: TIVChangeEvent;
    FOnItemChanging: TIVChangingEvent;
    FImages: TCustomImageList;
    FImageChanges: TChangeLink;
    FViewportHandle: QWidgetH;
    FViewportHooks: QWidget_hookH;
    FOnSelectItem: TIVSelectItemEvent;
    FIconOptions: TIconOptions;
    FSelected: TIconViewItem;
    procedure OnImageChanges(Sender: TObject);
    function GetHandle: QIconViewH;
    procedure SetMultiSelect(const Value: Boolean);
    procedure SetSpacing(const Value: Integer);
    procedure SetTextPos(const Value: TItemTextPos);
    procedure SetResizeMode(const Value: TResizeMode);
    procedure SetShowToolTips(const Value: Boolean);
    procedure SetIconViewItems(const Value: TIconViewItems);
    procedure SetSort(const Value: Boolean);
    procedure SetSortDirection(const Value: TSortDirection);
    procedure SetItemsMovable(const Value: Boolean);
    procedure DoItemClicked(item: QIconViewItemH); cdecl;
    procedure DoItemDoubleClicked(item: QIconViewItemH); cdecl;
    procedure DoItemEnter(item: QIconViewItemH); cdecl;
    procedure DoViewportEnter; cdecl;
    procedure DoEdited(item: QIconViewItemH; p2: PWideString); cdecl;
    procedure ItemDestroyedHook(item: QIconViewItemH); cdecl;
    procedure ChangingHook(item: QIconViewItemH; _type: TItemChange;
      var Allow: Boolean); cdecl;
    procedure ChangeHook(item: QIconViewItemH; _type: TItemChange); cdecl;
    procedure SelectedHook(item: QIconViewItemH; Value: Boolean); cdecl;
    procedure PaintCellHook(p: QPainterH; item: QIconViewItemH;
      cg: QColorGroupH; var stage: Integer); cdecl;
    procedure PaintFocusHook(p: QPainterH; item: QIconViewItemH;
      cg: QColorGroupH; var stage: Integer); cdecl;
    procedure SetOnItemClicked(const Value: TIVItemClickEvent);
    procedure SetOnItemDoubleClick(const Value: TIVItemDoubleClickEvent);
    procedure SetOnItemEnter(const Value: TIVItemEnterEvent);
    procedure SetOnItemExitViewportEnter(const Value: TIVItemExitViewportEnterEvent);
    procedure SetOnEdited(const Value: TIVEditedEvent);
    procedure SetImages(const Value: TCustomImageList);
    procedure SetSelected(const Value: TIconViewItem);
    procedure SetIconOptions(const Value: TIconOptions);
  protected
    procedure BeginAutoDrag; override;
    procedure ColorChanged; override;
    procedure CreateWidget; override;
    procedure DoChange(Item: TIconViewItem; Change: TItemChange); dynamic;
    procedure DoChanging(Item: TIconViewItem; Change: TItemChange;
      var AllowChange: Boolean); dynamic;
    procedure HookEvents; override;
    procedure ImageListChanged; dynamic;
    procedure InitWidget; override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    function ViewportHandle: QWidgetH;
    procedure WidgetDestroyed; override;
    property BorderStyle default bsSunken3d;
    property Height default 97;
    property IconOptions: TIconOptions read FIconOptions write SetIconOptions;
    property Images: TCustomImageList read FImages write SetImages;
    property Items: TIconViewItems read FIconViewItems write SetIconViewItems;
    property ItemsMovable: Boolean read FItemsMovable write SetItemsMovable
      default True;
    property MultiSelect: Boolean read FMultiSelect write SetMultiSelect
      default False;
    property ParentColor default False;
    property ResizeMode: TResizeMode read FResizeMode write SetResizeMode
      default rmAdjust;
    property SelCount: Integer read FSelCount;
    property Selected: TIconViewItem read FSelected write SetSelected;
    property ShowToolTips: Boolean read FShowToolTips write SetShowToolTips
      default True;
    property Sort: Boolean read FSort write SetSort default False;
    property SortDirection: TSortDirection read FSortDirection
      write SetSortDirection default sdAscending;
    property Spacing: Integer read FSpacing write SetSpacing default 5;
    property TabStop default True;
    property TextPosition: TItemTextPos read FTextPosition write SetTextPos
      default itpBottom;
    property Width default 121;
    property OnChange: TIVChangeEvent read FOnItemChange write FOnItemChange;
    property OnChanging: TIVChangingEvent read FOnItemChanging
      write FOnItemChanging;
    property OnItemDoubleClick: TIVItemDoubleClickEvent read FOnItemDoubleClick
      write SetOnItemDoubleClick;
    property OnItemExitViewportEnter: TIVItemExitViewportEnterEvent
      read FOnItemExitViewportEnter write SetOnItemExitViewportEnter;
    property OnItemEnter: TIVItemEnterEvent read FOnItemEnter
      write SetOnItemEnter;
    property OnEdited: TIVEditedEvent read FOnEdited
      write SetOnEdited;
    property OnItemClicked: TIVItemClickEvent read FOnItemClicked
      write SetOnItemClicked;
    property OnSelectItem: TIVSelectItemEvent read FOnSelectItem
      write FOnSelectItem;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Handle: QIconViewH read GetHandle;
    procedure Clear;
    procedure SelectAll(Select: Boolean);
    function FindItemByText(const Str: WideString): TIconViewItem;
    function FindItemByPoint(const Pt: TPoint): TIconViewItem;
    function GetNextItem(StartItem: TIconViewItem; Direction: TSearchDirection;
      States: TItemStates): TIconViewItem;
    procedure RepaintItem(AItem: TIconViewItem);
    procedure EnsureItemVisible(AItem: TIconViewItem);
    function FindVisibleItem(First: Boolean; const ARect: TRect): TIconViewItem;
    procedure UpdateControl;
    procedure UpdateItems(FirstIndex, LastIndex: Integer);
  end;

{ TIconView }

  TIconView = class(TCustomIconView)
  public
    property SelCount;
    property Selected;
  published
    property Align;
    property Anchors;
    property BorderStyle;
    property Color;
    property Constraints;
    property DragMode;
    property Height;
    property Hint;
    property IconOptions;
    property Images;
    property Items;
    property ItemsMovable;
    property MultiSelect;
    property ParentColor;
    property ParentShowHint;
    property PopupMenu;
    property ResizeMode;
    property ShowHint;
    property ShowToolTips;
    property Sort;
    property SortDirection;
    property Spacing;
    property TabOrder;
    property TabStop;
    property TextPosition;
    property Width;
    property Visible;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnItemDoubleClick;
    property OnItemExitViewportEnter;
    property OnItemEnter;
    property OnEdited;
    property OnItemClicked;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnSelectItem;
    property OnStartDrag;
  end;

{ TToolBar }

  TToolButtonStyle = (tbsButton, tbsCheck, tbsDropDown, tbsSeparator, tbsDivider);

  TToolButtonState = (tbsChecked, tbsPressed, tbsEnabled, tbsHidden,
    tbsIndeterminate, tbsWrap, tbsEllipses, tbsMarked);

  TToolBar = class;
  TToolButton = class;

  { TToolButtonActionLink }

  TToolButtonActionLink = class(TControlActionLink)
  protected
    FClient: TToolButton;
    procedure AssignClient(AClient: TObject); override;
    function IsCheckedLinked: Boolean; override;
    function IsImageIndexLinked: Boolean; override;
    procedure SetChecked(Value: Boolean); override;
    procedure SetImageIndex(Value: Integer); override;
  end;

  TToolButtonActionLinkClass = class of TToolButtonActionLink;

  TToolButton = class(TCustomControl)
  private
    FAllowAllUp: Boolean;
    FAutoSize: Boolean;
    FDown: Boolean;
    FGrouped: Boolean;
    FMouseIn: Boolean;
    FImageIndex: TImageIndex;
    FIndeterminate: Boolean;
    FMarked: Boolean;
    FDropDownMenu: TPopupMenu;
    FMenuDropped: Boolean;
    FWrap: Boolean;
    FStyle: TToolButtonStyle;
    FUpdateCount: Integer;
    FJustChecked: Boolean;
    { FShowCaption: Boolean; }
    FCaption: TCaption;
    function DropDownRect: TRect;
    function GetIndex: Integer;
    function IsCheckedStored: Boolean;
    function IsImageIndexStored: Boolean;
    function IsWidthStored: Boolean;
    { procedure ResizeButton; }
    procedure SetAutoSize(Value: Boolean);
    procedure SetDown(Value: Boolean);
    procedure SetDropDownMenu(Value: TPopupMenu);
    procedure SetGrouped(Value: Boolean);
    procedure SetImageIndex(Value: TImageIndex);
    procedure SetIndeterminate(Value: Boolean);
    procedure SetMarked(Value: Boolean);
    procedure SetStyle(Value: TToolButtonStyle);
    procedure SetWrap(Value: Boolean);
    procedure SetAllowAllUp(const Value: Boolean);
  protected
    FToolBar: TToolBar;
    procedure ActionChange(Sender: TObject; CheckDefaults: Boolean); override;
    procedure AssignTo(Dest: TPersistent); override;
    procedure BeginUpdate; virtual;
    procedure DoPaint(Canvas: TCanvas);
    function DropDownWidth: Integer; virtual;
    procedure EndUpdate; virtual;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure InitWidget; override;
    function IsEnabled: Boolean;
    function GetActionLinkClass: TControlActionLinkClass; override;
    function GetText: TCaption; override;
    procedure MouseEnter(AControl: TControl); override;
    procedure MouseLeave(AControl: TControl); override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure Paint; override;
    procedure SetName(const Value: TComponentName); override;
    procedure SetParent(const Value: TWidgetControl); override;
    procedure SetText(const Value: TCaption); override;
    procedure SetToolBar(AToolBar: TToolBar);
    procedure ValidateContainer(AComponent: TComponent); override;
    function WantKey(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
    function CheckMenuDropDown: Boolean; dynamic;
    procedure Click; override;
    procedure ChangeBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    property Index: Integer read GetIndex;
    property Toolbar: TToolBar read FToolBar write SetToolBar;
  published
    property Style: TToolButtonStyle read FStyle write SetStyle default tbsButton;
    property Action;
    property AllowAllUp: Boolean read FAllowAllUp write SetAllowAllUp default False;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default False;
    property Caption;
    property Down: Boolean read FDown write SetDown stored IsCheckedStored default False;
    property DragMode;
    property DropDownMenu: TPopupMenu read FDropDownMenu write SetDropDownMenu;
    property Enabled;
    property Grouped: Boolean read FGrouped write SetGrouped default False;
    property ImageIndex: TImageIndex read FImageIndex write SetImageIndex stored IsImageIndexStored default -1;
    property Indeterminate: Boolean read FIndeterminate write SetIndeterminate default False;
    property Marked: Boolean read FMarked write SetMarked default False;
    property ParentShowHint;
    property PopupMenu;
    { property ShowCaption: Boolean read FShowCaption write SetShowCaption; }
    property Wrap: Boolean read FWrap write SetWrap default False;
    property ShowHint;
    property Visible;
    property Width stored IsWidthStored;
    property OnClick;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
  end;

{ TToolBar }

  TGroupChangeReason = (gcDownState, gcAllowAllUp);

  TToolBar = class(TCustomControl)
  private
    FButtonWidth: Integer;
    FButtonHeight: Integer;
    FWrapable: Boolean;
    FAutoSize: Boolean;
    FBorderWidth: TBorderWidth;
    FControls: TList;
    FEdgeBorders: TEdgeBorders;
    FEdgeOuter: TEdgeStyle;
    FEdgeInner: TEdgeStyle;
    FIndent: Integer;
    FFlat: Boolean;
    FList: Boolean;
    FShowCaptions: Boolean;
    FHotImages: TCustomImageList;
    FImages: TCustomImageList;
    FDisabledImages: TCustomImageList;
    FImageWidth: Integer;
    FImageHeight: Integer;
    FImageChangeLink: TChangeLink;
    FResizeCount: Integer;
    FRightEdge: Integer;
    procedure AdjustSize; reintroduce;
    procedure DoPaint(ACanvas: TCanvas);
    function EdgeSpacing(Edge: TEdgeBorder): Integer;
    function GetControl(Index: Integer): TControl;
    procedure GroupChange(Requestor: TToolButton; Reason: TGroupChangeReason);
    function HasImages: Boolean;
    procedure ImageListChange(Sender: TObject);
    procedure InternalSetButtonWidth(const Value: Integer; RestrictSize: Boolean);
    function LastControl: TControl;
    procedure ResizeButtons(Button: TToolButton);
    procedure SetWrapable(const Value: Boolean);
    procedure SetButtonHeight(const Value: Integer);
    procedure SetButtonWidth(const Value: Integer);
    procedure SetAutoSize(const Value: Boolean);
    procedure SetBorderWidth(const Value: TBorderWidth);
    procedure SetEdgeBorders(const Value: TEdgeBorders);
    procedure SetEdgeInner(const Value: TEdgeStyle);
    procedure SetEdgeOuter(const Value: TEdgeStyle);
    procedure SetIndent(const Value: Integer);
    procedure SetFlat(const Value: Boolean);
    procedure SetShowCaptions(const Value: Boolean);
    procedure SetDisabledImages(const Value: TCustomImageList);
    procedure SetHotImages(const Value: TCustomImageList);
    procedure SetImages(const Value: TCustomImageList);
    procedure SetList(const Value: Boolean);
  protected
    procedure ControlsAligned; override;
    procedure ControlsListChanged(Control: TControl; Inserting: Boolean); override;
    function CustomAlignInsertBefore(C1, C2: TControl): Boolean; override;
    procedure CustomAlignPosition(Control: TControl; var NewLeft, NewTop, NewWidth,
      NewHeight: Integer; var AlignRect: TRect); override;
    procedure DoResize;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure FontChanged; override;
    procedure InitWidget; override;
    procedure AdjustClientRect(var Rect: TRect); override;
    procedure Loaded; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure Paint; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function ButtonCount: Integer;
    function ControlCount: Integer;
    procedure Invalidate; override;
    property Controls[Index: Integer]: TControl read GetControl;
  published
    property Align default alTop;
    property Anchors;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default False;
    property Bitmap;
    property BorderWidth: TBorderWidth read FBorderWidth write SetBorderWidth default 0;
    property ButtonHeight: Integer read FButtonHeight write SetButtonHeight default 22;
    property ButtonWidth: Integer read FButtonWidth write SetButtonWidth default 23;
    property Caption;
    property Color;
    property Constraints;
    property DisabledImages: TCustomImageList read FDisabledImages write SetDisabledImages;
    property DragMode;
    property EdgeBorders: TEdgeBorders read FEdgeBorders write SetEdgeBorders default [ebTop];
    property EdgeInner: TEdgeStyle read FEdgeInner write SetEdgeInner default esRaised;
    property EdgeOuter: TEdgeStyle read FEdgeOuter write SetEdgeOuter default esLowered;
    property Enabled;
    property Flat: Boolean read FFlat write SetFlat default False;
    property Font;
    property Height default 32;
    property HotImages: TCustomImageList read FHotImages write SetHotImages;
    property Images: TCustomImageList read FImages write SetImages;
    property Indent: Integer read FIndent write SetIndent default 1;
    property List: Boolean read FList write SetList default False;
    property Masked default False;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowCaptions: Boolean read FShowCaptions write SetShowCaptions default False;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Visible;
    property Wrapable: Boolean read FWrapable write SetWrapable default True;
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

{ Utility functions }

function DefaultMimeFactory: TMimeSourceFactory;
procedure SetDefaultMimeFactory(Value: TMimeSourceFactory);
procedure CheckRange(AMin, AMax: Integer);

implementation

uses
  QConsts, QActnList, Math, QForms;

const
  STATUSBAR_HEIGHT = 19;
  SIZE_GRIP_SIZE = 15;
  SCROLL_BUTTON_WIDTH = 17;
  SELECTED_TAB_SIZE_DELTA = 2;
  FRAME_BORDER_WIDTH = 2;
  TAB_FLAT_BORDER = 4;
  STATUS_PANEL_SPACER = 2;
  TabDefaultHeightMap: array [TTabStyle] of Integer = (19, 24, 25, 18);
  TabDefaultWidthMap: array [TTabStyle] of Integer = (45, 45, 53, 40);
  TabDefaultBorderWidthMap: array [TTabStyle] of Integer = (2, 4, 6, 0);
  TabDefaultTextOffsetMap: array [TTabStyle] of Integer = (-1, 1, 1, 0);
  TabButtonsLeftMap: array [TTabStyle] of Integer = (SELECTED_TAB_SIZE_DELTA, 0, -4, 0);

  FrameMap: array [Boolean] of Integer =
    (Integer(QFrameShape_NoFrame) or Integer(QFrameShadow_Plain),
    (Integer(QFrameShape_PopUpPanel) or Integer(QFrameShadow_Raised)));

  BevelShadowStyle: array [TStatusPanelBevel] of QControls.TBorderStyle =
    (bsNone, bsSunkenPanel, bsRaisedPanel);

{ Helper routines }

function ButtonToMouseButton(Button: Integer): TMouseButton;
begin
  case Button of
    Integer(ButtonState_MidButton): Result := mbMiddle;
    Integer(ButtonState_RightButton): Result := mbRight;
    else
      Result := mbLeft;
  end;
end;

procedure CheckRange(AMin, AMax: Integer);
begin
  if (AMax < AMin) or (AMin > AMax) then
    raise ERangeException.Create(Format(SInvalidRangeError,[AMin, AMax]));
end;

{ TProgressBar }

constructor TProgressBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Width := 150;
  Height := 18;
  Max := 100;
  FStep := 10;
  FFillColor := clHighlight;
  ControlStyle := ControlStyle - [csSetCaption];
end;

procedure TProgressBar.FontChanged;
begin
  inherited;
  FTextColor := Font.Color;
end;

function TProgressBar.GetText: TCaption;
begin
  Result := FText;
end;

function TProgressBar.AdjustToParent(const Rect: TRect): TRect;
var
  H, W: Integer;
begin
  H := Rect.Bottom - Rect.Top;
  W := Rect.Right - Rect.Left;
  Result.Top := Rect.Top + Top;
  Result.Left := Rect.Left + Left;
  Result.Right := Result.Left + W;
  Result.Bottom := Result.Top + H;
end;

procedure TProgressBar.EraseText(const AText: WideString; BackgroundColor : TColor);
var
  Rect: TRect;
  PrevBrush: TBrushRecall;
begin
  PrevBrush := TBrushRecall.Create(Canvas.Brush);
  try
    Rect := CalcTextRect(ClientRect, ClientRect, AText);
    Canvas.Brush.Color := BackgroundColor;
    Canvas.FillRect(Rect);
  finally
    PrevBrush.Free;
  end;
end;

function TProgressBar.CalcTextRect(Rect: TRect; const BoundingRect: TRect;
  const AText: WideString): TRect;
const
  cTextFlags = Integer(AlignmentFlags_AlignHCenter)
    or Integer(AlignmentFlags_AlignVCenter);
begin
  Canvas.TextExtent(AText, Rect, cTextFlags);
  IntersectRect(Result, Rect, BoundingRect);
end;

procedure TProgressBar.InternalPaint;
const
  cTextFlags = Integer(AlignmentFlags_AlignHCenter)
              or Integer(AlignmentFlags_AlignVCenter);
  cTextBorder = 4;
  cSectionSpacer = 2;
var
  Rect: TRect;
  PrevRect: TRect;
  TextRect: TRect;
  PrevPen: TPenRecall;
  PrevBrush: TBrushRecall;
  PrevFont: TFontRecall;

  function CalcSectionSize(const BoundingRect: TRect): Integer;
  begin
    if Orientation = pbHorizontal then
      Result := 2 * (BoundingRect.Bottom - BoundingRect.Top - 1) div 3
    else
      Result := 2 * (BoundingRect.Right - BoundingRect.Left - 1) div 3;
  end;

  procedure DrawSpacer(Rect: TRect; SectionSize: Integer);
  var
    PrevBrush: TBrushRecall;
    PrevPen: TPenRecall;
  begin
    if not Transparent then
    begin
      PrevBrush := nil;
      PrevPen := TPenRecall.Create(Canvas.Pen);
      try
        PrevBrush := TBrushRecall.Create(Canvas.Brush);
        Canvas.Pen.Color := Color;
        Canvas.Pen.Width := 1;
        Canvas.Brush.Style := bsClear;
        InflateRect(Rect, 1, 1);
        Canvas.Rectangle(Rect);
      finally
        PrevBrush.Free;
        PrevPen.Free;
      end;
    end;
  end;

  function SectionCount(const ARect: TRect; FillArea: TRect; SectionSize: Integer): Integer;
  var
    TotalPixels: Integer;
  begin
    if Orientation = pbHorizontal then
      TotalPixels := FillArea.Right - ARect.Left
    else
      TotalPixels := ARect.Bottom - FillArea.Top;

    Result := ((TotalPixels - cSectionSpacer) div
                (CalcSectionSize(ARect) + cSectionSpacer)) + 1;
  end;

  procedure DrawSections(BoundingRect: TRect; var FillArea: TRect);
  var
    SectionSize: Integer;
    Sections: Integer;
    I: Integer;
  begin
    InflateRect(FillArea, -1, -1);
    InflateRect(BoundingRect, -1, -1);
    SectionSize := CalcSectionSize(BoundingRect);

    { Draw an empty the progress bar }
    if Position = Min then
    begin
      if not Transparent then
      begin
        Canvas.Brush.Color := Color;
        Canvas.FillRect(BoundingRect);
      end;
      InflateRect(FillArea, 1, 1);
      Exit;
    end;

    if SectionSize <> 0 then
    begin
      Sections := SectionCount(BoundingRect, FillArea, SectionSize);

      if FSections <> Sections then
      begin
        FSections := Sections;

        { Draw each section }
        for I := 0 to Sections - 1 do
        begin
          if Orientation = pbHorizontal then
          begin
            FillArea.Left := BoundingRect.Left + (I * (SectionSize + cSectionSpacer));
            FillArea.Right := FillArea.Left + SectionSize;
            FillArea.Right := Math.Min(FillArea.Right, BoundingRect.Right - 1);
            Canvas.FillRect(FillArea);
            DrawSpacer(FillArea, SectionSize);
            Inc(FillArea.Right, cSectionSpacer);
            FillArea.Left := FillArea.Right;
          end else
          begin
            FillArea.Bottom := BoundingRect.Bottom - (I * (SectionSize + cSectionSpacer));
            FillArea.Top := FillArea.Bottom - SectionSize;
            FillArea.Top := Math.Max(FillArea.Top, BoundingRect.Top + 1);
            Canvas.FillRect(FillArea);
            DrawSpacer(FillArea, SectionSize);
            Dec(FillArea.Top, cSectionSpacer);
            FillArea.Bottom := FillArea.Top;
          end;
        end;

        if Orientation = pbHorizontal then
          Dec(FillArea.Right, cSectionSpacer)
        else
          Inc(FillArea.Top, cSectionSpacer);
      end else
        if Orientation = pbHorizontal then
          FillArea.Right := BoundingRect.Left + (Sections * (SectionSize + cSectionSpacer))
        else
          FillArea.Top := BoundingRect.Bottom - (Sections * (SectionSize + cSectionSpacer));
    end;

    InflateRect(FillArea, 1, 1);
  end;

  function PaintProgress(var ARect: TRect): Boolean;
  var
    TotalPixels: Integer;
    Rect: TRect;
  begin
    Result := False;
    PrevRect := ARect;
    Rect := ARect;
    Canvas.SetClipRect(AdjustToParent(ARect));
    try
      if (FTotalSteps > 0) then
      begin
        { Calculate the size of the fill area in pixels based on the position }
        case Orientation of
          pbHorizontal:
            begin
              TotalPixels := ARect.Right - ARect.Left;
              ARect.Right := ARect.Left + ((ScalePosition(Position) * TotalPixels) div FTotalSteps);
              ARect.Right := Math.Min(ARect.Right, ClientWidth);
            end;
          pbVertical:
            begin
              TotalPixels := ARect.Bottom - ARect.Top;
              ARect.Top := ARect.Bottom - ((ScalePosition(Position) * TotalPixels) div FTotalSteps);
              ARect.Top := Math.Min(ARect.Top, ClientHeight);
            end;
        end;

        if EqualRect(FFillArea, ARect) then Exit;
        FFillArea := ARect;
        Result := True;

        Canvas.Brush.Color := FillColor;

       { Draw the progress }
        if Smooth then
          Canvas.FillRect(ARect)
        else
          DrawSections(PrevRect, ARect);

        { Calculate the rest of the non-progress area if not transparent }
        if not Transparent then
        begin
          Rect := PrevRect;
          if Orientation = pbHorizontal then
          begin
            Rect.Left := ARect.Right;
            if Rect.Left > Rect.Right then Rect.Left := Rect.Right;
          end else
          begin
            Rect.Bottom := ARect.Top;
            if Rect.Bottom < Rect.Top then Rect.Bottom := Rect.Top;
          end;
        end;
      end;

      if not Transparent then
      begin
        Canvas.Brush.Color := Color;
        Canvas.FillRect(Rect);
      end;
    finally
      Canvas.ResetClipRegion;
    end;
  end;

  procedure XORText(const BoundingRect: TRect; FillRect, TextRect: TRect;
    const Caption: WideString; TextFlags: Integer);

    procedure DrawText(BackgroundColor, FontColor: TColor);
    begin
      EraseText(FPrevText, BackgroundColor);
      Canvas.Brush.Color := BackgroundColor;
      Canvas.FillRect(TextRect);
      Canvas.Font.Color := FontColor;
      Canvas.TextRect(TextRect, TextRect.Left, TextRect.Top, Caption, cTextFlags);
    end;

  begin
    { Qt doesn't handle XORing text very well in windows. So instead we will
      paint the text twice with different colors for inside and outside of
      the fill area. By using SetClipRect we can achieve an XORed look.
    }
    try
      if Transparent then Canvas.Brush.Style := bsClear;

      if Orientation = pbHorizontal then
      begin
        FillRect.Left := BoundingRect.Left;
        TextRect.Top := BoundingRect.Top;
        TextRect.Bottom := BoundingRect.Bottom;

        if (FillRect.Right > TextRect.Left) and (FillRect.Right < TextRect.Right) then
          Canvas.SetClipRect(AdjustToParent(FillRect));

        { Draw the text that is inside of the fill area }
        if FillRect.Right > TextRect.Left then
          DrawText(FillColor, clHighlightText);

        if FillRect.Right < TextRect.Right then
        begin
          { Draw the text that is outside of the fill area }
          if (FillRect.Right > TextRect.Left) then
          begin
            Rect := BoundingRect;
            Rect.Left := FillRect.Right;
            Canvas.SetClipRect(AdjustToParent(Rect));
          end;
          DrawText(Color, FTextColor);
        end;
      end else
      begin
        FillRect.Bottom := BoundingRect.Bottom;
        TextRect.Right := BoundingRect.Right;
        TextRect.Left := BoundingRect.Left;

        if (FillRect.Top > TextRect.Top) and (FillRect.Top < TextRect.Bottom) then
          Canvas.SetClipRect(AdjustToParent(FillRect));

        { Draw the text that is inside of the fill area }
        if FillRect.Top < TextRect.Bottom then
          DrawText(FillColor, clHighlightText);

        if FillRect.Top > TextRect.Top then
        begin
          { Draw the text that is outside of the fill area }
          if (FillRect.Top < TextRect.Bottom) then
          begin
            Rect := BoundingRect;
            Rect.Bottom := FillRect.Top;
            Canvas.SetClipRect(AdjustToParent(Rect));
          end;
          DrawText(Color, FTextColor);
        end;
      end;
    finally
      Canvas.ResetClipRegion;
    end;
  end;

begin
  Canvas.Start;
  PrevPen := nil;
  PrevFont := nil;
  PrevBrush := TBrushRecall.Create(Canvas.Brush);
  try
    PrevFont := TFontRecall.Create(Canvas.Font);
    PrevPen := TPenRecall.Create(Canvas.Pen);
    Canvas.Brush.Style := bsSolid;

    Rect := Classes.Rect(0, 0, Width, Height);
    { Adjust for the frame }
    InflateRect(Rect, -1, -1);
    { Adjust for the BorderWidth }
    InflateRect(Rect, -BorderWidth, -BorderWidth);

    if IsRectEmpty(Rect) then Exit;

    TextRect := Rect;

    { Adjust the fill area depending on where the text will be displayed }
    if not Smooth then
    begin
      if ShowCaption and (Caption <> '') then
      begin
        if Orientation = pbHorizontal then
        begin
          Rect.Right := Rect.Right - (Canvas.TextWidth(Caption) + (cTextBorder * 2));
          if Rect.Right < Rect.Left then Rect.Right := Rect.Left;
          TextRect.Left := Rect.Right;
        end else
        begin
          Rect.Top := Rect.Top + Canvas.TextHeight(Caption);
          if Rect.Top > Rect.Bottom then Rect.Top := Rect.Bottom;
          TextRect.Bottom := Rect.Top;
        end;
      end;
    end;

    { Paint the progress area }
    if PaintProgress(Rect) then
      { Draw the text }
      if ShowCaption and (Caption <> '')then
      begin
        Canvas.Font := Font;
        Canvas.Font.Color := FTextColor;
        if Smooth then
        begin
          TextRect := CalcTextRect(TextRect, PrevRect, Caption);
          XORText(PrevRect, Rect, TextRect, Caption, cTextFlags);
          Exit;
        end else
        begin
          Canvas.SetClipRect(AdjustToParent(TextRect));
          if not Transparent then
          begin
            Canvas.Brush.Color := Color;
            Canvas.FillRect(TextRect);
          end else
            Canvas.Brush.Style := bsClear;
        end;
        Canvas.TextRect(TextRect, TextRect.Left, TextRect.Top, Caption, cTextFlags);
      end;
  finally
    PrevPen.Free;
    PrevFont.Free;
    PrevBrush.Free;
    Canvas.Stop;
  end;
end;

procedure TProgressBar.InternalDrawFrame;
var
  R: TRect;

  procedure DrawBorder(ARect: TRect);
  const
    BorderWidthAdj: array[Boolean] of Integer = (0,1);
  var
    PrevBrush: TBrushRecall;
    PrevPen: TPenRecall;
    i : Integer;
  begin
    with Canvas do
    begin
      PrevBrush := nil;
      PrevPen := TPenRecall.Create(Pen);
      try
        PrevBrush := TBrushRecall.Create(Brush);
        Brush.Style := bsClear;
        if Transparent then
          Pen.Style := psClear
        else
          Pen.Style := psSolid;
        Pen.Color := Color;
        for i := 1 to BorderWidth + BorderWidthAdj[Smooth] do
          if not IsRectEmpty(ARect) then
          begin
            Rectangle(ARect);
            InflateRect(ARect, -1, -1);
          end;
      finally
        PrevPen.Free;
        PrevBrush.Free;
      end;
    end;
  end;

begin
  R := Rect(0 , 0, Width, Height);
  { Draw frame }
  DrawEdge(Canvas, R, esNone, esLowered, [ebLeft, ebTop, ebBottom, ebRight]);
  InflateRect(R, -1, -1);
  DrawBorder(R);
end;

function TProgressBar.ScalePosition(Value: Integer): Integer;
begin
  { Adjust the Position to fit in the scale of 0 to FTotalSteps }
  Result := Abs(Value - Min);
end;

procedure TProgressBar.SetBorderWidth(const Value: TBorderWidth);
begin
  if FBorderWidth <> Value then
  begin
    FBorderWidth := Value;
    RequestAlign;
    Invalidate;
  end;
end;

procedure TProgressBar.SetFillColor(const Value: TColor);
begin
  if FFillColor <> Value then
  begin
    FFillColor := Value;
    Invalidate;
  end;
end;

procedure TProgressBar.Paint;
var
  PrevBrush: TBrushRecall;
  PrevPen: TPenRecall;
begin
  PrevBrush := nil;
  PrevPen := TPenRecall.Create(Canvas.Pen);
  try
    PrevBrush := TBrushRecall.Create(Canvas.Brush);
    FFillArea := Rect(-1, -1, -1, -1);
    FSections := -1;
    InternalDrawFrame;
    InternalPaint;
  finally
    PrevPen.Free;
    PrevBrush.Free;
  end;
end;

procedure TProgressBar.SetText(const Value: TCaption);
begin
  if FText <> Value then
  begin
    FText := Value;
    Invalidate;
  end;
end;

procedure TProgressBar.Changing(var Text: WideString; NewPosition: Integer);
begin
  if Assigned(FOnChanging) then
    FOnChanging(Self, Text, NewPosition);
end;

procedure TProgressBar.SetMax(const Value: Integer);
begin
  if FMax <> Value then
  begin
    SetRange(Min, Value);
    if Value < Position then
      FPosition := Value;
    FMax := Value;
    Invalidate;
  end;
end;

procedure TProgressBar.SetMin(const Value: Integer);
begin
  if FMin <> Value then
  begin
    SetRange(Value, Max);
    FPosition := Value;
    FMin := Value;
    Invalidate;
  end;
end;

procedure TProgressBar.SetOrientation(const Value: TProgressBarOrientation);
begin
  if FOrientation <> Value then
  begin
    FOrientation := Value;
    Invalidate;
  end;
end;

procedure TProgressBar.SetPosition(Value: Integer);
var
  Text: WideString;
begin
  if FPosition <> Value then
  begin
    FPosition := Value;
    if (FPosition > Max) or (FPosition < Min) then
    begin
      if WrapRange then
      begin
        if FTotalSteps > 0 then
          if Value > Max then
            FPosition := (ScalePosition(Value) mod (FTotalSteps + 1)) + Min
          else
            FPosition := Max - (ScalePosition(Value) mod (FTotalSteps + 1)) + 1
        else
          FPosition := Value;
      end else
        if FPosition > Max then FPosition := Max else FPosition := Min;
    end;
    Text := Caption;
    FPrevText := Text;
    Changing(Text, Position);
    if Caption <> Text then
      FText := Text;
    if (Transparent or ((Position = 0) and (Value <= Max))) then
      Invalidate
    else
      if (Parent <> nil) and Visible then
        InternalPaint;
  end;
end;

procedure TProgressBar.SetRange(const AMin, AMax: Integer);
begin
  if not (csLoading in ComponentState) then
    CheckRange(AMin, AMax);
  FTotalSteps := AMax - AMin;
end;

procedure TProgressBar.SetShowCaption(const Value: Boolean);
begin
  if FShowCaption <> Value then
  begin
    FShowCaption := Value;
    Invalidate;
  end;
end;

procedure TProgressBar.SetSmooth(const Value: Boolean);
begin
  if FSmooth <> Value then
  begin
    FSmooth := Value;
    Invalidate;
  end;
end;

procedure TProgressBar.SetStep(const Value: Integer);
begin
  if FStep <> Value then
    FStep := Value;
end;

procedure TProgressBar.SetTransparent(const Value: Boolean);
begin
  if FTransparent <> Value then
  begin
    FTransparent := Value;
    Invalidate;
  end;
end;

procedure TProgressBar.StepBy(Delta: Integer);
begin
  Position := Position + Delta;
end;

procedure TProgressBar.StepIt;
begin
  WrapRange := True;
  try
    Position := Position + FStep;
  finally
    WrapRange := False;
  end;
end;

{ TTrackBar }

procedure TTrackBar.Changed;
begin
  if Assigned(FOnChange) then
    FOnChange(Self);
end;

constructor TTrackBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);

  { Height and Width set initally for Vertical so that ChangeAspectRatio in
    SetOrientation can change to the proper aspect ratio for Horizontal when
    called in InitWidget }
  Width := 45;
  Height := 150;
  FOrientation := trVertical;
  TabStop := True;
  FTickMarks := tmBottomRight;
  ControlStyle := ControlStyle - [csDoubleClicks];
  InputKeys := [ikArrows];
end;

procedure TTrackBar.CreateWidget;
var
  Method: TMethod;
begin
  FHandle := QClxSlider_create(ParentWidget, PChar(Name), Method);
  Hooks := QSlider_hook_create(FHandle);
end;

procedure TTrackBar.InitWidget;
begin
  inherited InitWidget;
  LineSize := 1;
  PageSize := 2;
  Frequency := 1;
  Min := 0;
  Max := 10;
  TickMarks := tmBottomRight;
  TickStyle := tsAuto;
  Orientation := trHorizontal;
  QWidget_setFocusPolicy(FHandle, QWidgetFocusPolicy_ClickFocus);
  UpdateSettings;
//  SetRange(Min, Max);
end;

procedure TTrackBar.HookEvents;
var
  Method: TMethod;
begin
  QSlider_valueChanged_Event(Method) := ValueChangedHook;
  QSlider_hook_hook_valueChanged(QSlider_hookH(Hooks), Method);
  QSlider_sliderMoved_Event(Method) := ValueChangedHook;
  QSlider_hook_hook_valueChanged(QSlider_hookH(Hooks), Method);
  inherited HookEvents;
end;

procedure TTrackBar.Loaded;
begin
  inherited Loaded;
  if Orientation = trVertical then
    ChangeAspectRatio;
  SetRange(FMin, FMax);
end;

procedure TTrackBar.ChangeAspectRatio;
begin
  SetBounds(Left, Top, Height, Width);
end;

function TTrackBar.GetHandle: QClxSliderH;
begin
  HandleNeeded;
  Result := QClxSliderH(FHandle);
end;

function TTrackBar.GetOrientation: TTrackBarOrientation;
begin
  Result := TTrackBarOrientation(QSlider_orientation(Handle));
end;

procedure TTrackBar.SetFrequency(const Value: Integer);
begin
  { Note: if Frequency is set to 0 then the QT determines the Tick interval from
    the LineSize. }
  QSlider_setTickInterval(Handle, Value);
end;

procedure TTrackBar.SetLineSize(const Value: Integer);
begin
  QRangeControl_setSteps(RangeControl, Value, PageSize);
end;

procedure TTrackBar.SetMax(const Value: Integer);
begin
  if (csLoading in ComponentState) then
    SetRange(FMin, Value)
  else
    SetRange(Min, Value);
end;

procedure TTrackBar.SetMin(const Value: Integer);
begin
  if (csLoading in ComponentState) then
    SetRange(Value, FMax)
  else
    SetRange(Value, Max);
end;

procedure TTrackBar.SetOrientation(const Value: TTrackBarOrientation);
begin
  if FOrientation <> Value then
  begin
    FOrientation := Value;
    QSlider_setOrientation(Handle, Qt.Orientation(Value));
    ChangeAspectRatio;
    UpdateSettings;
  end;
end;

procedure TTrackBar.SetPageSize(const Value: Integer);
begin
  QRangeControl_setSteps(RangeControl, LineSize, Value);
end;

procedure TTrackBar.SetPosition(const Value: Integer);
begin
  QRangeControl_setValue(RangeControl, Value);
end;

procedure TTrackBar.SetRange(const AMin, AMax: Integer);
begin
  FMin := AMin;
  FMax := AMax;

  if not HandleAllocated or (csLoading in ComponentState) then
    Exit;

  try
    CheckRange(AMin, AMax);
  except
    FMin := Min;
    FMax := Max;
    raise;
  end;

  QRangeControl_setRange(RangeControl, FMin, FMax);
  Invalidate;
end;

procedure TTrackBar.SetTickMarks(const Value: TTickMark);
begin
  if FTickMarks <> Value then
  begin
    FTickMarks := Value;
    UpdateSettings;
  end;
end;

procedure TTrackBar.SetTickStyle(const Value: TTickStyle);
begin
  if FTickStyle <> Value then
  begin
    FTickStyle := Value;
    case FTickStyle of
      tsAuto: UpdateSettings;
      tsNone: QSlider_setTickmarks(Handle, QSliderTickSetting_NoMarks);
    end;
  end;
end;

function TTrackBar.GetFrequency: Integer;
begin
  Result := QSlider_tickInterval(Handle);
end;

function TTrackBar.GetRangeControl: QRangeControlH;
begin
  Result := QSlider_to_QRangeControl(Handle);
end;

function TTrackBar.GetLineSize: Integer;
begin
  Result := QRangeControl_lineStep(RangeControl);
end;

function TTrackBar.GetPageSize: Integer;
begin
  Result := QRangeControl_pageStep(RangeControl);
end;

function TTrackBar.GetMax: Integer;
begin
  Result := QRangeControl_maxValue(RangeControl);
end;

function TTrackBar.GetMin: Integer;
begin
  Result := QRangeControl_minValue(RangeControl);
end;

function TTrackBar.GetPosition: Integer;
begin
  Result := QRangeControl_value(RangeControl);
end;

function TTrackBar.GetTickMarks: TTickMark;
const
  TickSettingMap:
    array [Ord(QSliderTickSetting_Above)..Ord(QSliderTickSetting_Both)] of TTickMark = (tmTopLeft, tmBottomRight, tmBoth);
var
  TickSetting: Integer;
begin
  TickSetting := Integer(QSlider_tickMarks(Handle));
  if TickSetting = Integer(QSliderTickSetting_NoMarks) then
    Result := FTickMarks
  else
    Result := TickSettingMap[TickSetting];
end;

function TTrackBar.GetTickStyle: TTickStyle;
begin
  Result := FTickStyle;
end;

procedure TTrackBar.UpdateSettings;
const
  TickMarksMap: array [TTickMark, TTrackBarOrientation] of QSliderTickSetting =
    ((QSliderTickSetting_Below, QSliderTickSetting_Right),
     (QSliderTickSetting_Above, QSliderTickSetting_Left),
     (QSliderTickSetting_Both, QSliderTickSetting_Both));

begin
  if TickStyle <> tsNone then
  QSlider_setTickMarks(Handle, TickMarksMap[FTickMarks, Orientation]);
end;

procedure TTrackBar.ValueChangedHook(Value: Integer);
begin
  { The Value parameter from Qt is not used }
  try
    Changed;
  except
    Application.HandleException(Self);
  end;
end;

{ TStatusPanel }

constructor TStatusPanel.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  Width := 50;
  FBevel := pbLowered;
  FVisible := True;
end;

destructor TStatusPanel.Destroy;
begin
  if PanelPosition = ppRight then
    Dec(StatusPanels.FFixedPanelCount);
  inherited Destroy;
end;

procedure TStatusPanel.Assign(Source: TPersistent);
begin
  if Source is TStatusPanel then
  begin
    Text := TStatusPanel(Source).Text;
    Width := TStatusPanel(Source).Width;
    Alignment := TStatusPanel(Source).Alignment;
    Bevel := TStatusPanel(Source).Bevel;
  end else
    inherited Assign(Source);
end;

function TStatusPanel.GetDisplayName: string;
begin
  Result := Text;
  if Result = '' then
    Result := inherited GetDisplayName;
end;

procedure TStatusPanel.SetAlignment(const Value: TAlignment);
begin
  if FAlignment <> Value then
  begin
    FAlignment := Value;
    Changed(False);
  end;
end;

procedure TStatusPanel.SetBevel(const Value: TStatusPanelBevel);
begin
  if FBevel <> Value then
  begin
    FBevel := Value;
    Changed(False);
  end;
end;

procedure TStatusPanel.SetStyle(Value: TStatusPanelStyle);
begin
  if FStyle <> Value then
  begin
    FStyle := Value;
    Changed(False);
  end;
end;

procedure TStatusPanel.SetText(const Value: WideString);
begin
  if FText <> Value then
  begin
    FText := Value;
    Changed(False);
  end;
end;

procedure TStatusPanel.SetWidth(const Value: Integer);
begin
  if FWidth <> Value then
  begin
    FWidth := Value;
    Changed(True);
  end;
end;

procedure TStatusPanel.SetPanelPosition(const Value: TPanelPosition);
begin
  if FPanelPosition <> Value then
  begin
    if FPanelPosition = ppRight then
      Dec(StatusPanels.FFixedPanelCount);
    FPanelPosition := Value;
    if FPanelPosition = ppRight then
      Inc(StatusPanels.FFixedPanelCount);
    Changed(False);
  end;
end;

procedure TStatusPanel.SetVisible(const Value: Boolean);
begin
  if FVisible <> Value then
  begin
    FVisible := Value;
    Changed(False);
  end;
end;

function TStatusPanel.GetStatusPanels: TStatusPanels;
begin
  Result := TStatusPanels(Collection);
end;

{ TStatusPanels }

constructor TStatusPanels.Create(StatusBar: TStatusBar);
begin
  inherited Create(TStatusPanel);
  FStatusBar := StatusBar;
end;

function TStatusPanels.Add: TStatusPanel;
begin
  Result := TStatusPanel(inherited Add);
end;

function TStatusPanels.GetItem(Index: Integer): TStatusPanel;
begin
  Result := TStatusPanel(inherited GetItem(Index));
end;

function TStatusPanels.GetOwner: TPersistent;
begin
  Result := FStatusBar;
end;

procedure TStatusPanels.Update(Item: TCollectionItem);
begin
  StatusBar.UpdatePanels;
end;

procedure TStatusPanels.SetItem(Index: Integer; const Value: TStatusPanel);
begin
  inherited SetItem(Index, Value);
  FStatusBar.Update;
end;

{ TStatusBar }

function TStatusBar.FindPanel(PanelPosition: TPanelPosition;
  Index: Integer): TStatusPanel;
var
  I, Count: Integer;
begin
  Result := nil;
  Count := 0;
  for I := 0 to Panels.Count-1 do
    if Panels[I].PanelPosition = PanelPosition then
    begin
      if Count = Index then
      begin
        Result := Panels[I];
        Break;
      end;
      Inc(Count);
    end;
end;

function TStatusBar.ExecuteAction(Action: TBasicAction): Boolean;
begin
  if AutoHint and (Action is THintAction) and not DoHint then
  begin
    if SimplePanel or (Panels.Count = 0) then
      SimpleText := THintAction(Action).Hint
    else
      Panels[0].Text := THintAction(Action).Hint;
    Result := True;
  end else
    Result := inherited ExecuteAction(Action);
end;

procedure TStatusBar.BeginUpdate;
begin
  Inc(FUpdateCount);
end;

constructor TStatusBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle - [csAcceptsControls, csSetCaption]
    + [csNoFocus];
  Align := alBottom;
  FPanels := TStatusPanels.Create(Self);
  FSizeGrip := True;
  BorderStyle := bsNone;
  BevelInner := bvNone;
  BevelOuter := bvNone;
  ParentColor := False;
end;

destructor TStatusBar.Destroy;
begin
  FreeAndNil(FPanels);
  inherited Destroy;
end;

function TStatusBar.DoHint: Boolean;
begin
  if Assigned(FOnHint) then
  begin
    FOnHint(Self);
    Result := True;
  end else
    Result := False;
end;

procedure TStatusBar.CursorChanged;
var
  I: Integer;
begin
  inherited;
  for I := 0 to ControlCount-1 do
    Controls[I].Cursor := Cursor;
end;

procedure TStatusBar.ControlsAligned;
begin
  inherited ControlsAligned;
  UpdatePanels;
end;

procedure TStatusBar.DoPanelClick(Panel: TStatusPanel);
begin
  if Assigned(FOnPanelClick) then
    FOnPanelClick(Self, Panel);
end;

procedure TStatusBar.DrawPanel(Panel: TStatusPanel; const Rect: TRect);
var
  PrevBrush: TBrushRecall;
begin
  if Assigned(FOnDrawPanel) then
    FOnDrawPanel(Self, Panel, Rect)
  else
  begin
    PrevBrush := TBrushRecall.Create(Canvas.Brush);
    try
      Canvas.Brush.Color := Color;
      Canvas.FillRect(Rect);
    finally
      PrevBrush.Free;
    end;
  end;
end;

procedure TStatusBar.EnabledChanged;
var
  I: Integer;
begin
  inherited;
  for I := 0 to ControlCount-1 do
    Controls[I].Enabled := Enabled;
end;

procedure TStatusBar.Resize;
begin
  inherited;
  ValidateSizeGrip;
  UpdatePanels;
end;

function TStatusBar.GetPanel(PanelPosition: TPanelPosition;
  Index: Integer): TStatusPanel;
begin
  Result := FindPanel(PanelPosition, Index);
  if Result = nil then raise EListError.Create(Format(SListIndexError,[Index]));
end;

procedure TStatusBar.EndUpdate;
begin
  Dec(FUpdateCount);
  if FUpdateCount = 0 then
    Update;
end;

procedure TStatusBar.FlipChildren(AllLevels: Boolean);
var
  I: Integer;
begin
  if HandleAllocated and
     (not SimplePanel) and (Panels.Count > 0) then
  begin
    BeginUpdate;
    try
      { Flip 'em }
      for I := 0 to Panels.Count - 1 do
      begin
        if Panels[I].PanelPosition = ppLeft then
          Panels[I].PanelPosition := ppRight
        else
          Panels[I].PanelPosition := ppLeft;
      end;
    finally
      EndUpdate;
    end;
  end;
end;

procedure TStatusBar.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  inherited;
  ValidateSizeGrip;
end;

procedure TStatusBar.InitWidget;
begin
  Height := STATUSBAR_HEIGHT;
  BorderWidth := 0;
  Color := clBackground;
end;

procedure TStatusBar.MouseUp(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
var
  I: Integer;
  Point: TPoint;
begin
  inherited MouseUp(Button, Shift, X, Y);
  Point.X := X;
  Point.Y := Y;
  for I := 0 to Panels.Count - 1 do
    if PtInRect(Panels[I].FBounds, Point) then
    begin
      DoPanelClick(Panels[I]);
      Break;
    end;
end;

procedure TStatusBar.Invalidate;
begin
  inherited Invalidate;
  ValidateSizeGrip;
end;

function TStatusBar.IsFontStored: Boolean;
begin
  Result := not ParentFont;
end;

procedure TStatusBar.PaletteCreated;
begin
  // We don't want a SizeGrip to show up by default when the component is
  // created off the palette. The default is left True so we can read in old
  // StatusBar's from VCL
  SizeGrip := False;
end;

procedure TStatusBar.RequestAlign;
begin
  inherited RequestAlign;
  Invalidate;
end;

procedure TStatusBar.Paint;
const
  cTextFlags: array [TAlignment] of Integer = ( Integer(AlignmentFlags_AlignLeft),
                                              Integer(AlignmentFlags_AlignRight),
                                              Integer(AlignmentFlags_AlignHCenter));
  cEdgeInner: array [TStatusPanelBevel] of TEdgeStyle = (esNone, esNone, esRaised);
  cEdgeOuter: array [TStatusPanelBevel] of TEdgeStyle = (esNone, esLowered, esNone);
var
  I: Integer;
  R: TRect;
begin
  Canvas.Font := Font;
  if (Panels.Count = 0) or SimplePanel then
  begin
    R := Rect(BorderWidth, STATUS_PANEL_SPACER - BorderWidth, Width - BorderWidth,
      Height - BorderWidth);
    { Find out where the Right border is }
    for I := 0 to Panels.Count - 1 do
      if Panels[I].PanelPosition = ppRight then
        R.Right := Panels[I].FBounds.Left - STATUS_PANEL_SPACER;

    DrawEdge(Canvas, R, esNone, cEdgeOuter[pbLowered], [ebLeft, ebTop, ebBottom, ebRight]);
    if SimplePanel then
      Canvas.TextRect(R, R.Left, R.Top, SimpleText,
        Integer(AlignmentFlags_AlignVCenter) or cTextFlags[taLeftJustify]);
  end;

  if not (Panels.Count = 0) then
    for I := 0 to Panels.Count - 1 do
      if Panels[I].Visible and (not Panels[I].FHidden) then
      begin
        R := Panels[I].FBounds;
        DrawEdge(Canvas, R, cEdgeInner[Panels[I].Bevel], cEdgeOuter[Panels[I].Bevel],
          [ebLeft, ebTop, ebBottom, ebRight]);
        InflateRect(R, -STATUS_PANEL_SPACER, -STATUS_PANEL_SPACER);

        if Panels[I].Style = psOwnerDraw then
          DrawPanel(Panels[I], R)
        else
        begin
          if R.Right - R.Left > STATUS_PANEL_SPACER then
          Canvas.TextRect(R, R.Left, R.Top, Panels[I].Text,
            Integer(AlignmentFlags_AlignVCenter) or cTextFlags[Panels[I].Alignment]);
        end;

        InflateRect(R, STATUS_PANEL_SPACER, STATUS_PANEL_SPACER);
      end;
end;

procedure TStatusBar.SetPanels(const Value: TStatusPanels);
begin
  FPanels.Assign(Value);
end;

procedure TStatusBar.SetSimplePanel(const Value: Boolean);
begin
  if FSimplePanel <> Value then
  begin
    FSimplePanel := Value;
    UpdatePanels;
  end;
end;

procedure TStatusBar.SetSimpleText(const Value: WideString);
begin
  if FSimpleText <> Value then
  begin
    FSimpleText := Value;
    Invalidate;
  end;
end;

procedure TStatusBar.Update;
begin
  if FUpdateCount = 0 then
  begin
    inherited Update;
    UpdatePanels;
  end;
end;

procedure TStatusBar.UpdatePanels;
const
  cSizeGripMap: array [Boolean] of Integer = (0, SIZE_GRIP_SIZE + STATUS_PANEL_SPACER);
var
  LeftSide: Integer;
  RightSide: Integer;
  NewLeft: Integer;
  NewRight: Integer;
  LastLeft: Integer;
  I: Integer;
  R: TRect;
begin
  if HandleAllocated and (Panels <> nil) then
  begin
    LeftSide := BorderWidth;
    RightSide := Width - BorderWidth;
    NewLeft := LeftSide;
    LastLeft := -1;


    for I := 0 to Panels.Count-1 do
    begin
      if (Panels[I].PanelPosition = ppRight) and Panels[I].Visible then
      begin
        NewLeft := RightSide - Panels[I].Width;

        TStatusPanel(Panels[I]).FBounds := Rect(NewLeft,
          STATUS_PANEL_SPACER + BorderWidth, RightSide, Height - BorderWidth);

        R := TStatusPanel(Panels[I]).FBounds;
        RightSide := NewLeft - STATUS_PANEL_SPACER;
      end;
    end;

    for I := 0 to Panels.Count-1 do
    begin
      if (Panels[I].PanelPosition = ppLeft) and Panels[I].Visible then
      begin
        NewRight := LeftSide + Panels[I].Width;
        NewRight := Min(NewRight, RightSide);
        Panels[I].FHidden := (NewRight <= LeftSide - STATUS_PANEL_SPACER) or SimplePanel;
        if Panels[I].FHidden then Continue;

        TStatusPanel(Panels[I]).FBounds := Rect(LeftSide,
          STATUS_PANEL_SPACER + BorderWidth, NewRight,
          Height - BorderWidth);

        R := TStatusPanel(Panels[I]).FBounds;
        LeftSide := NewRight + STATUS_PANEL_SPACER;
        LastLeft := I;
      end;
    end;
    
    if LastLeft > -1 then
    begin
      NewLeft := Max(NewLeft - STATUS_PANEL_SPACER, RightSide);
      TStatusPanel(Panels[LastLeft]).FBounds.Right := NewLeft;
    end;

    Invalidate;
  end;
end;

procedure TStatusBar.SetSizeGrip(const Value: Boolean);
begin
  if FSizeGrip <> Value then
  begin
    FSizeGrip := Value;
    ValidateSizeGrip;
  end;
end;

type
  TOpenCustomForm = class(TCustomForm);

procedure TStatusBar.ValidateSizeGrip;
var
  Form: TCustomForm;
  APoint, P: TPoint;
begin
  Form := GetParentForm(Self);
  if (Form <> nil) and
    (TOpenCustomForm(Form).BorderStyle in [fbsSizeable, fbsSizeToolWin]) then
  begin
    P := Point(Width, Height);
    QWidget_mapToParent(Handle, @APoint, @P);
    if (APoint.X = Form.ClientWidth) {and (APoint.Y = Form.ClientHeight)} then
    begin
      if FSizeGripHandle = nil then
        FSizeGripHandle := QSizeGrip_Create(Handle, nil);

      PositionSizeGrip;
      Exit;
    end;
  end;
  if FSizeGripHandle <> nil then
    QWidget_hide(FSizeGripHandle);
end;

procedure TStatusBar.PositionSizeGrip;
var
  NewGripSizeHeight: Integer;
  NewGripSizeLeft: Integer;
begin
  if FSizeGripHandle <> nil then
  begin
    NewGripSizeHeight := Height - (BorderWidth * 2) - 6;
    NewGripSizeLeft := Width - SIZE_GRIP_SIZE - BorderWidth - 2;
    QWidget_setGeometry(FSizeGripHandle,
      NewGripSizeLeft,
      BorderWidth + 4,
      SIZE_GRIP_SIZE,
      NewGripSizeHeight);

    QWidget_raise(FSizeGripHandle);

    if SizeGrip and (Align in [alBottom, alRight, alClient]) then
      QWidget_show(FSizeGripHandle)
    else
      QWidget_hide(FSizeGripHandle);
  end;
end;

function TStatusBar.GetBorderWidth: TBorderWidth;
begin
  Result := inherited BorderWidth;
end;

procedure TStatusBar.SetBorderWidth(const Value: TBorderWidth);
begin
  inherited BorderWidth := Value;
  PositionSizeGrip;
  Update;
end;

procedure TStatusBar.CMRecreateWindow(var Message: TMessage);
begin
  ValidateSizeGrip;
end;

{ TTab }

procedure TTab.Assign(Source: TPersistent);
begin
  if Source is TTab then
  begin
    Caption := TTab(Source).Caption;
    Enabled := TTab(Source).Enabled;
    FTabRect := TTab(Source).TabRect;
    Highlighted := TTab(Source).Highlighted;
    ImageIndex := TTab(Source).ImageIndex;
    Selected := TTab(Source).Selected;
    Visible := TTab(Source).Visible;
  end
  else
    inherited Assign(Source);
end;

constructor TTab.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  Tabs.BeginUpdate;
  try
    Width := TabDefaultWidthMap[Tabs.TabControl.Style];
    Height := TabDefaultHeightMap[Tabs.TabControl.Style];
    FVisible := True;
    FEnabled := True;
    FImageIndex := Index;
  finally
    Tabs.EndUpdate;
  end;
end;

function TTab.GetTabs: TTabs;
begin
  Result := TTabs(Collection);
end;

function TTab.CalculateWidth: Integer;
var
  ImageRef: TCustomImageList;
begin
  Result := TabDefaultWidthMap[Tabs.TabControl.Style];

  if Caption <> '' then
  begin
    { Set the Width based on the width of the caption and Images }
    Result := Tabs.TabControl.Canvas.TextWidth(Caption) +
      (TabDefaultBorderWidthMap[Tabs.TabControl.Style] * 4);

    ImageRef := Tabs.TabControl.GetImageRef;
    if Tabs.TabControl.HasImages(Self) then
      Result := Result + ImageRef.Width + (Tabs.TabControl.ImageBorder * 2);

    if Result < TabDefaultWidthMap[Tabs.TabControl.Style] then
      Result := TabDefaultWidthMap[Tabs.TabControl.Style];
  end;
end;

function TTab.CalculateHeight: Integer;
begin
  Result := Tabs.CalculateTabHeight(Caption);
end;

procedure TTab.SetCaption(const Value: TCaption);
begin
  if FCaption <> Value then
  begin
    FCaption := Value;
    Tabs.BeginUpdate;
    try
      Width := CalculateWidth;
      Height := CalculateHeight;
    finally
      Tabs.EndUpdate;
    end;
  end;
end;

procedure TTab.SetEnabled(const Value: Boolean);
begin
  if FEnabled <> Value then
  begin
    FEnabled := Value;
    Changed(True);
  end;
end;

function TTab.GetDisplayName: string;
begin
  Result := FCaption;
  if Result = '' then
    Result := inherited GetDisplayName;
end;

function TTab.GetHeight: Integer;
begin
  Result := TabRect.Bottom - TabRect.Top;
end;

function TTab.GetWidth: Integer;
begin
  Result := TabRect.Right - TabRect.Left;
end;

procedure TTab.SetHeight(const Value: Integer);
var
  NewValue: Integer;
begin
  if Value <> (FTabRect.Bottom - FTabRect.Top) then
  begin
    Tabs.FUpdating := True;
    try
      if Value = 0 then
        NewValue := CalculateHeight
      else
        NewValue := Value;

      if FTabRect.Bottom <> FTabRect.Top + NewValue then
      begin
        FTabRect.Bottom := FTabRect.Top + NewValue;
        Changed(True);
      end;
    finally
      Tabs.FUpdating := False;
    end;
  end;
end;

procedure TTab.SetWidth(const Value: Integer);
var
  NewValue: Integer;
begin
  if Value <> (FTabRect.Right - FTabRect.Left) then
  begin
    Tabs.FUpdating := True;
    try
      if Value = 0 then
        NewValue := CalculateWidth
      else
        NewValue := Value;
      if FTabRect.Right <> FTabRect.Left + NewValue then
      begin
        FTabRect.Right := FTabRect.Left + NewValue;
        Changed(True);
      end;
    finally
      Tabs.FUpdating := False;
    end;
  end;
end;

function TTab.GetLeft: Integer;
begin
  Result := TabRect.Left;
end;

function TTab.GetTop: Integer;
begin
  Result := TabRect.Top;
end;

procedure TTab.SetLeft(const Value: Integer);
begin
  if TabRect.Left <> Value then
  begin
    Tabs.FUpdating := True;
    try
      FTabRect.Right := Value + Width;
      FTabRect.Left := Value;
      Changed(True);
    finally
      Tabs.FUpdating := False;
    end;
  end;
end;

procedure TTab.SetTop(const Value: Integer);
begin
  if TabRect.Top <> Value then
  begin
    Tabs.FUpdating := True;
    try
      FTabRect.Bottom := Value + Height;
      FTabRect.Top := Value;
      Changed(True);
    finally
      Tabs.FUpdating := False;
    end;
  end;
end;

procedure TTab.SetVisible(const Value: Boolean);
begin
  if FVisible <> Value then
  begin
    FVisible := Value;
    Changed(True);
  end;
end;

function TTab.GetImageIndex: Integer;
begin
  Result := FImageIndex;
end;

procedure TTab.SetImageIndex(const Value: Integer);
begin
  if FImageIndex <> Value then
  begin
    FImageIndex := Value;
    Changed(True);
  end;
end;

procedure TTab.SetSelected(const Value: Boolean);
begin
  if FSelected <> Value then
  begin
    if Value and (Index <> Tabs.TabControl.TabIndex) then
      if (Tabs.TabControl.Style = tsTabs) then
        Exit
      else
        if not Tabs.TabControl.MultiSelect then
          Tabs.TabControl.MultiSelect := True;
    FSelected := Value;
    Changed(True);
  end;
end;

procedure TTab.SetHighlighted(const Value: Boolean);
begin
  if FHighlighted <> Value then
  begin
    FHighlighted := Value;
    Changed(True);
  end;
end;

{ TTabs }

function TTabs.Add(const ACaption: WideString): TTab;
begin
  Result := TTab(inherited Add);
  Result.FCaption := ACaption;
  Result.Changed(True);
end;

constructor TTabs.Create(TabControl: TCustomTabControl);
begin
  inherited Create(TTab);
  FTabControl := TabControl;
end;

function TTabs.GetItem(Index: Integer): TTab;
begin
  Result := TTab(inherited GetItem(Index));
end;

function TTabs.GetOwner: TPersistent;
begin
  Result := FTabControl;
end;

procedure TTabs.Update(Item: TCollectionItem);
begin
  if FUpdating then Exit;
  FUpdating := True;
  if Item = nil then
  begin
    FTabControl.RequestLayout;
  end else
    FTabControl.Invalidate;
  FUpdating := False;
end;

procedure TTabs.SetItem(Index: Integer; const Value: TTab);
begin
  inherited SetItem(Index, Value);
  if Assigned(TabControl) then
    TabControl.Invalidate;
end;

function TTabs.CalculateTabHeight(const S: WideString): Integer;
var
  ImageRef: TCustomImageList;
begin
  { Set the Height based on the height of the caption and Images }
  with TabControl.Canvas do
    if S = '' then
      Result := TextHeight('Zy')
    else
      Result := TextHeight(S);

  ImageRef := TabControl.GetImageRef;
  if Assigned(ImageRef) then
    if Result < ImageRef.Height then
      Result := ImageRef.Height + 4;

  if Result < TabDefaultHeightMap[TabControl.Style] then
    Result := TabDefaultHeightMap[TabControl.Style];
end;

{ TTabButton }

type
  TTabButtonDirection = (tbdLeft, tbdRight);

  TTabScrollButton = class(TSpeedButton)
  private
    FTimer: TTimer;
    FInitialDelay: Word;
    FDelay: Word;
    FDirection: TTabButtonDirection;
    procedure TimerExpired(Sender: TObject);
    procedure SetDirection(const Value: TTabButtonDirection);
  protected
    procedure ChangeScale(MV, DV, MH, DH: Integer); override;
    procedure EnabledChanged; override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
                         X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState;
                       X, Y: Integer); override;
    procedure Paint; override;
    procedure VisibleChanged; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Delay: Word read FDelay write FDelay default 50;
    property InitialDelay: Word read FInitialDelay write FInitialDelay default 400;
    property Direction: TTabButtonDirection read FDirection write SetDirection;
  end;

constructor TTabScrollButton.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FInitialDelay := 400;
  FDelay := 50;
  ControlStyle := ControlStyle + [csNoDesignVisible];
end;

destructor TTabScrollButton.Destroy;
begin
  FreeAndNil(FTimer);
  inherited Destroy;
end;

procedure TTabScrollButton.TimerExpired(Sender: TObject);
begin
  FTimer.Interval := FDelay;
  if (FState = bsDown) and MouseCapture then
  begin
    try
      Click;
    except
      FTimer.Enabled := False;
      raise;
    end;
  end;
end;

procedure TTabScrollButton.SetDirection(const Value: TTabButtonDirection);
begin
  if FDirection <> Value then
    FDirection := Value;
end;

procedure TTabScrollButton.ChangeScale(MV, DV, MH, DH: Integer);
begin
  { Don't scale }
end;

procedure TTabScrollButton.EnabledChanged;
begin
  { Don't notify }
end;

procedure TTabScrollButton.MouseDown(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
begin
  inherited MouseDown(Button, Shift, X, Y);
  if FTimer = nil then
  begin
    FTimer := TTimer.Create(Self);
    FTimer.OnTimer := TimerExpired;
  end;
  FTimer.Interval := FInitialDelay;
  FTimer.Enabled := True;
end;

procedure TTabScrollButton.MouseUp(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  if FTimer <> nil then
    FTimer.Enabled := False;
end;

procedure TTabScrollButton.Paint;
const
  EnabledColors: array [Boolean] of TColor = (clActiveMid, clBlack);
var
  PaintRect: TRect;
  Offset: TPoint;
  PrevPen: TPenRecall;
  PrevBrush: TBrushRecall;
begin
  inherited Paint;
  with Canvas do
  begin
    Offset := Point(0,0);
    PaintRect := Rect(0, 0, Width - 1, Height - 1);

    case FState of
      bsDown:
        begin
          Inc(Offset.X);
          Inc(Offset.Y);
        end;
    end;

    PrevPen := nil;
    PrevBrush := TBrushRecall.Create(Brush);
    try
      PrevPen := TPenRecall.Create(Pen);
      Pen.Color := EnabledColors[Enabled];
      Brush.Color := EnabledColors[Enabled];
      Pen.Width := 1;

      case Direction of
        tbdLeft:
          Polygon([ Point(4 + Offset.X, 7 + Offset.Y),
                    Point(7 + Offset.X, 4 + Offset.Y),
                    Point(7 + Offset.X, 10 + Offset.Y),
                    Point(4 + Offset.X, 7 + Offset.Y)]);
        tbdRight:
          Polygon([ Point(6 + Offset.X, 4 + Offset.Y),
                    Point(6 + Offset.X, 10 + Offset.Y),
                    Point(9 + Offset.X, 7 + Offset.Y),
                    Point(6 + Offset.X, 4 + Offset.Y)]);
      end;
    finally
      PrevPen.Free;
      PrevBrush.Free;
    end;
  end;
end;

procedure TTabScrollButton.VisibleChanged;
begin
  inherited;
  if Visible then Parent.Invalidate;
end;

{ TCustomTabControl }

procedure TabControlError(const S: string);
begin
  raise EListError.Create(S);
end;

constructor TCustomTabControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csAcceptsControls, csDoubleClicks, csClickEvents, csOpaque];

  FTabs := TTabs.Create(Self);

  Width := 289;
  Height := 193;
  FRowCount := 0;
  FFirstVisibleTab := 0;
  FLastVisibleTab := 0;
  FImageBorder := 3;
  FImageChangeLink := TChangeLink.Create;
  FImageChangeLink.OnChange := ImageListChange;
  FMouseOver := -1;
  FShowFrame := False;
  FHotTrackColor := clBlue;
  FTracking := -1;
  TabStop := True;
  InputKeys := [ikArrows];

  FBitmap := TBitmap.Create;
  FBitmap.Height := 2;
  FBitmap.Width := 2;
  FBitmap.Canvas.Pen.Color := clActiveLight;
  FBitmap.Canvas.Polyline([Point(0,1),Point(0,1)]);
  FBitmap.Canvas.Polyline([Point(1,0),Point(1,0)]);

  FBitmap.Canvas.Pen.Color := clBackground;
  FBitmap.Canvas.Polyline([Point(0,0),Point(0,0)]);
  FBitmap.Canvas.Polyline([Point(1,1),Point(1,1)]);

  FDblBuffer := TBitmap.Create;
  CreateButtons;
end;

procedure TCustomTabControl.BeginUpdate;
begin
  Tabs.BeginUpdate;
end;

destructor TCustomTabControl.Destroy;
begin
  FreeAndNil(FDblBuffer);
  FreeAndNil(FBitmap);
  FreeAndNil(FImageChangeLink);
  FreeAndNil(FTabs);
  inherited Destroy;
end;

procedure TCustomTabControl.EndUpdate;
begin
  Tabs.EndUpdate;
end;

function TCustomTabControl.IndexOfTabAt(X, Y: Integer): Integer;
var
  I: Integer;
  Rect: TRect;
begin
  Result := -1;
  if Tabs.Count > 0 then
    for I := FFirstVisibleTab to FLastVisibleTab do
    begin
      Rect := Tabs[I].TabRect;
      if Rect.Right > RightSide then Rect.Right := RightSide;
      if PtInRect(Rect, Point(X, Y)) and Tabs[I].Visible then
      begin
        Result := I;
        Break;
      end;
  end;
end;

function TCustomTabControl.TabRect(Index: Integer): TRect;
begin
  Result := Tabs[Index].TabRect;
end;

procedure TCustomTabControl.ScrollTabs(Delta: Integer);
var
  I: Integer;
begin
  if not FMultiLine then
  begin
    for I := 0 to Abs(Delta)-1 do
      if Delta < 0 then
        FButtons[tbLeft].Click
      else
        FButtons[tbRight].Click;
  end;
end;

procedure TCustomTabControl.Changed(Value: Integer);
begin
  if Assigned(FOnChanged) then
    FOnChanged(Self, Value);
end;

procedure TCustomTabControl.DrawHighlight(Canvas: TCanvas; const Rect: TRect;
  ASelected, AHighlight, AEnabled: Boolean);
const
  StyleAdjustment: array [TTabStyle] of Integer = (1, 0, 1, 0);
var
  PrevBrush: TBrushRecall;
  R: TRect;
begin
  if ASelected and ((Style in [tsButtons, tsFlatButtons]) and not AHighlight) then
     Canvas.Brush.Bitmap := FBitmap;

  R := Rect;

  if (Style = tsTabs) then
  begin
    Inc(R.Bottom);
    if ASelected then
      InflateRect(R, SELECTED_TAB_SIZE_DELTA, SELECTED_TAB_SIZE_DELTA)
    else Inc(R.Bottom);
  end;

  PrevBrush := TBrushRecall.Create(Canvas.Brush);
  try
    if AHighlight then
    begin
      if AEnabled then
        Canvas.Brush.Color := clActiveHighlight
      else
        Canvas.Brush.Color := clDisabledHighlight;
      Canvas.Brush.Bitmap := nil;
    end;

    Canvas.Brush.Style := bsSolid;
    Canvas.FillRect(R);
  finally
    PrevBrush.Free;
  end;

  Canvas.Brush.Bitmap := nil;
end;

function TCustomTabControl.DrawTab(TabIndex: Integer; const Rect: TRect;
  Active: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FOnDrawTab) then
    FOnDrawTab(Self, TabIndex, Rect, Active, Result);
end;

procedure TCustomTabControl.EnabledChanged;
begin
  inherited;
  EnableScrollButtons;
end;

procedure TCustomTabControl.FontChanged;
begin
  inherited;
  Canvas.Font := Font;
  RequestLayout;
end;

function TCustomTabControl.GetImageIndex(ATabIndex: Integer): Integer;
begin
  Result := Tabs[ATabIndex].ImageIndex;
  if Assigned(FOnGetImageIndex) then
    FOnGetImageIndex(Self, ATabIndex, Result);
end;

procedure TCustomTabControl.AdjustTabRect(var Rect: TRect);
begin
  case Style of
    tsTabs:
      begin
        Inc(Rect.Top, 1);
      end;
    tsButtons:
      begin
        Dec(Rect.Right, 3);
        Inc(Rect.Top, 3);
      end;
    tsFlatButtons:
      begin
        InflateRect(Rect, -2, -2);
        Inc(Rect.Left, 2);
        Dec(Rect.Right, 1);
        Inc(Rect.Top);
        Inc(Rect.Bottom);
      end;
  end;
end;

procedure TCustomTabControl.AdjustTabClientRect(var Rect: TRect);
begin
 { Adjust the Tabs rectangle to ignore the Borders }
  case Style of
    tsTabs:
      begin
        InflateRect(Rect, -TabDefaultBorderWidthMap[Style] - 1,
          -TabDefaultBorderWidthMap[Style] - 1);
        Inc(Rect.Bottom, TabDefaultBorderWidthMap[Style] - 1);
        Dec(Rect.Left, TabDefaultBorderWidthMap[Style] - 1);
      end;
    tsButtons:
      begin
        InflateRect(Rect, -2, -2);
        Dec(Rect.Right, 3);
        Inc(Rect.Top, 3);
      end;
    tsFlatButtons:
      begin
        InflateRect(Rect, -4, -4);
        Inc(Rect.Left, 2);
        Dec(Rect.Right, TAB_FLAT_BORDER + 1);
        Inc(Rect.Bottom);
        Inc(Rect.Top);
      end;
  end;
end;

procedure TCustomTabControl.Loaded;
begin
  inherited Loaded;
  if Images <> nil then
    UpdateTabImages;
  RequestLayout;
end;

procedure TCustomTabControl.UpdateTabImages;
var
  I: Integer;
begin
  for I := 0 to FTabs.Count - 1 do
    FTabs[I].ImageIndex := GetImageIndex(I);
  TabsChanged;
end;

function TCustomTabControl.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Tabs.Count - 1 do
    if IsAccel(Key, Tabs[I].Caption) and (ssAlt in Shift) then
    begin
      TabIndex := Tabs[I].Index;
      SetFocus;
      Result := True;
      Break;
    end else
      Result := inherited WantKey(Key, Shift, KeyText);
end;

function TCustomTabControl.WidgetFlags: Integer;
begin
  Result := inherited WidgetFlags or Integer(WidgetFlags_WRepaintNoErase);
end;

procedure TCustomTabControl.SetTabIndex(const Value: Integer);

  function CalculateFirstVisibleTab(Value: Integer): Integer;
  var
    vTotalWidth: Integer;
  begin
    vTotalWidth := 0;
    if Value > 0 then
      repeat
        { Set Width because we might get here before LayoutTabs}
        Tabs[Value].Width := TabWidth;
        if Tabs[Value].Visible then
          Inc(vTotalWidth, Tabs[Value].Width);
        if (vTotalWidth + Tabs[Value - 1].Width +
            (SELECTED_TAB_SIZE_DELTA * 2) <= Rightside) then
          Dec(Value);
      until (Value = 0) or
        (vTotalWidth + (SELECTED_TAB_SIZE_DELTA * 2) >= Rightside);
    Result := Value;
  end;

begin
  if FTabIndex <> Value then
  begin
    if (Value <> -1) and (Value < 0) or (Value > Tabs.Count-1) then
      { Don't raise exception to maximize compatibility with VCL }
      Exit;

    if CanChange then
    begin
      if not MultiLine and (Value <> -1) and ((Value <= FFirstVisibleTab) or
        (Value >= FLastVisibleTab)) then
      begin
        if (Value >= FLastVisibleTab) then
        begin
          FLastVisibleTab := Value;
          FFirstVisibleTab := CalculateFirstVisibleTab(Value);
          { Sanity Check. The RightSide function bases its result on whether or
            not the TabScrollButtons are visible and this is determined in part
            by the variable FFirstVisibleTab. Since this is what we are
            calculating this becomes a chicken & egg situation. We need to
            recalculate it again if FFirstVisibleTab is greater than 0 so we can
            be assured of an accurate result. }
          if FFirstVisibleTab > 0 then FFirstVisibleTab := CalculateFirstVisibleTab(Value);
        end else
          FFirstVisibleTab := Value;
      end;

      if Value = -1 then
        EraseControlFlag;
      if FTracking <> -1 then
        Tabs[FTracking].Selected := False;
      FTracking := -1;
      FTabIndex := Value;
      Change;
      Changed(FTabIndex);
      if Multiline and (FLastVisibleTab = Tabs.Count - 1) then
      begin
        if FTabIndex <> -1 then
          CalculateRows(Tabs[FTabIndex].Row);
        { Reset to prevent Layout }
        FLayoutCount := 0;
        Invalidate;
      end else
        RequestLayout;
    end;
  end;
end;

function TCustomTabControl.GetDisplayRect: TRect;
begin
  Result := ClientRect;
  Inc(Result.Top, GetTotalTabHeight + 1);
end;

function TCustomTabControl.GetImageRef: TCustomImageList;
begin
  if Assigned(Images) then
    Result := Images
  else if Assigned(HotImages) and HotTrack then
    Result := HotImages
  else
    Result := nil;
end;

function TCustomTabControl.GetTabIndex: Integer;
begin
  Result := FTabIndex;
end;

function TCustomTabControl.GetTabHeight: Integer;
begin
  Result := TabHeight;
  if Result = 0 then
    Result := Tabs.CalculateTabHeight('');
end;

procedure TCustomTabControl.CalcImageTextOffset(const ARect: TRect; const S: WideString;
  Image: TCustomImageList; var ImagePos, TextPos: TPoint);
var
  TotalWidth: Integer;
  TotalHeight: Integer;
begin
  if Assigned(Image) then
  begin
  TotalWidth := Canvas.TextWidth(S) + (ImageBorder * 2) + Image.Width;
    TotalHeight := Image.Height;
    ImagePos.X := ((ARect.Right - ARect.Left) - TotalWidth) div 2;
    ImagePos.Y := ((ARect.Bottom - ARect.Top) - TotalHeight) div 2;
    TextPos.X := ImagePos.X + (ImageBorder * 2) + Image.Width;
  end else
  begin
    ImagePos := Point(0,0);
    TotalWidth := Canvas.TextWidth(S);
    TextPos.X := ((ARect.Right - ARect.Left) - TotalWidth) div 2;
  end;

  TotalHeight := Canvas.TextHeight(S);
  TextPos.Y := ((ARect.Bottom - ARect.Top) - TotalHeight) div 2;
end;

procedure TCustomTabControl.CalculateRows(SelectedRow: Integer);
var
  I: Integer;
begin
  if Style = tsTabs then
  begin
    for I := FLastVisibleTab downto FFirstVisibleTab do
    begin
      if Tabs[I].Row > SelectedRow then Continue;
      if (Tabs[I].Row = SelectedRow) then
        Tabs[I].FRow := 1
      else
        if Tabs[I].Row < SelectedRow then
          Tabs[I].FRow := Tabs[I].Row + 1;
    end;
    CalculateTabPositions;
  end;
end;

procedure TCustomTabControl.CalculateTabPositions;
const
  TopSpace: array [TTabStyle] of Integer = (2, 0, 0, 0);
var
  LTabHeight: Integer;
  I: Integer;
begin
  LTabHeight := GetTabHeight;
  for I := FFirstVisibleTab to FLastVisibleTab do
  begin
    if not Tabs[I].Visible then Continue;
    if not MultiLine then
      Tabs[I].Top := TopSpace[Style]
    else
      case Style of
        tsTabs:
          Tabs[I].Top := LTabHeight * (FRowCount - Tabs[I].Row) + SELECTED_TAB_SIZE_DELTA;
        tsButtons, tsFlatButtons:
            Tabs[I].Top := LTabHeight * (Tabs[I].Row - 1);
        tsNoTabs:
          Tabs[I].Top := 0;
      end;
    Tabs[I].Height := LTabHeight;
  end;
end;

procedure TCustomTabControl.EnableScrollButtons;
begin
  FUpdating := True;
  try
    FButtons[tbLeft].Enabled := Enabled and (FFirstVisibleTab > 0);
    FButtons[tbRight].Enabled := Enabled and (FLastVisibleTab < Tabs.Count) and
                                  (Tabs.Count > 0) and
                                  ((FLastVisibleTab <> -1) and
                                  (Tabs[FLastVisibleTab].TabRect.Right > RightSide)) and not
                                  ((FLastVisibleTab = Tabs.Count - 1) and
                                  (Tabs[FLastVisibleTab].Width > RightSide));
  finally
    FUpdating := False;
  end;
end;

function TCustomTabControl.FindNextVisibleTab(Index: Integer): Integer;

  function BackTrack: Integer;
  var
    vLeft: Integer;
  begin
    Result := Index - 1;
    vLeft := RightSide;
    while (Result > 0) and (vLeft > 0) do
    begin
      if Tabs[Result].Visible then
        Dec(vLeft, Tabs[Result].Width);
      Dec(Result);
    end;
  end;

begin
  while (Index < Tabs.Count) and not Tabs[Index].Visible do
    Inc(Index);
  Result := Min(Index, Tabs.Count - 1);
end;

function TCustomTabControl.FindPrevVisibleTab(Index: Integer): Integer;
begin
  Result := 0;
  while (Index >= 0) and not Tabs[Index].Visible do
    Dec(Index);
  if Index > -1 then Result := Index;
end;

procedure TCustomTabControl.BeginDblBuffer;
begin
  with FDblBuffer do
  begin
    Height := GetTotalTabHeight;
    Width := Self.Width;
    Canvas.Font := Self.Canvas.Font;
    Canvas.Brush := Self.Canvas.Brush;
    Canvas.Pen := Self.Canvas.Pen;
    Canvas.FillRect(Rect(0, 0, Width, Height));
  end;
end;

procedure TCustomTabControl.EndDblBuffer;
begin
  Canvas.Draw(0, 0, FDblBuffer);
end;

procedure TCustomTabControl.StretchTabs(ARow: Integer);
var
  Stretch: Integer;
  I: Integer;
  FirstTab, LastTab: TTab;
  TabCount: Integer;

  procedure CalcRowStats(Row: Integer; var AFirstTab, ALastTab: TTab; var ATabCount: Integer);
  var
    I: Integer;
  begin
    ATabCount := 0;
    AFirstTab := nil;
    ALastTab := nil;
    for I := FFirstVisibleTab to FLastVisibleTab do
    begin
      if Tabs[I].FRow = Row then
      begin
        Inc(ATabCount);
        if AFirstTab = nil then
          AFirstTab := Tabs[I];
        ALastTab := Tabs[I];
      end else
        if (AFirstTab <> nil) and (ALastTab <> nil) then
          Break;
    end;
  end;

begin
  CalcRowStats(ARow, FirstTab, LastTab, TabCount);
  if TabCount < 1 then Exit;
  Stretch := RightSide - LastTab.TabRect.Right;

  Tabs[FirstTab.Index].Width := Tabs[FirstTab.Index].Width + (Stretch div TabCount);
  for I := FirstTab.Index + 1 to LastTab.Index do
  begin
    if not Tabs[I].Visible then Continue;
    Tabs[I].Width := Tabs[I].Width + (Stretch div TabCount);
    Tabs[I].Left := Tabs[I - 1].TabRect.Right;
  end;
  Tabs[LastTab.Index].Width := Tabs[LastTab.Index].Width + (Stretch mod TabCount);
  if LastTab.Index > FirstTab.Index then
    Tabs[LastTab.Index].Left := Tabs[LastTab.Index - 1].TabRect.Right;
end;

function TCustomTabControl.GetTotalTabHeight: Integer;
const
  SpaceBetweenTabAndFrame: array [TTabStyle] of Integer = (1, 0, -1, 0);
var
  I: Integer;
  vCurrRow: Integer;
  vRowCount: Integer;
begin
  Result := 0;
  if (Tabs.Count > 0) and not (Style = tsNoTabs) then
  begin
    if MultiLine then
    begin
    vCurrRow := -1;
    vRowCount := 0;
    for I := 0 to Tabs.Count - 1 do
      if Tabs[I].Visible and (vCurrRow <> Tabs[I].Row) then
      begin
        Inc(vRowCount);
        vCurrRow := Tabs[I].Row;
      end;
    end
    else
      vRowCount := 1;

    Result := vRowCount * GetTabHeight;
    Inc(Result, SpaceBetweenTabAndFrame[Style] + SELECTED_TAB_SIZE_DELTA);
  end;
end;

function TCustomTabControl.GetTabs: TTabs;
begin
  Result := TTabs(FTabs);
end;

function TCustomTabControl.HasImages(ATab: TTab): Boolean;
var
  ImageRef: TCustomImageList;
begin
  ImageRef := GetImageRef;
  Result := Assigned(ImageRef) and (ImageRef.Count > 0);
  if Result and (ATab <> nil) then
    Result := (ATab.ImageIndex > -1) and
      (GetImageIndex(ATab.Index) < ImageRef.Count) and
      (GetImageIndex(ATab.Index) >= 0);
end;

function TCustomTabControl.RightSide: Integer;
begin
  DisplayScrollButtons;
  if FButtons[tbLeft].Visible then
    Result := FButtons[tbLeft].Left - 1
  else
    Result := Width + RightSideAdjustment;
end;

procedure TCustomTabControl.ButtonClick(Sender: TObject);
begin
  BeginUpdate;
  try
    if Sender = FButtons[tbLeft] then
      FFirstVisibleTab := FindPrevVisibleTab(FFirstVisibleTab - 1);

    if Sender = FButtons[tbRight] then
      if (Tabs[FLastVisibleTab].TabRect.Right > RightSide) or
         (FindNextVisibleTab(FLastVisibleTab + 1) < Tabs.Count) then
         FFirstVisibleTab := FindNextVisibleTab(FFirstVisibleTab + 1);
  finally
    EndUpdate;
  end;
end;

procedure TCustomTabControl.EraseControlFlag(const Value: Boolean = True);
begin
  FErase := Value;
end;

procedure TCustomTabControl.CreateButtons;
var
  Button: TTabButtons;
begin
  if FButtons[tbLeft] = nil then
  begin
    for Button := tbLeft to tbRight do
    begin
      FButtons[Button] := TTabScrollButton.Create(Self);
      with FButtons[Button] do
      begin
        Parent := Self;
        Visible := False;
        Top := 2;
        Width := SCROLL_BUTTON_WIDTH;
        Height := SCROLL_BUTTON_WIDTH;
        OnClick := ButtonClick;
        Visible := False;
        TTabScrollButton(FButtons[Button]).Direction := TTabButtonDirection(Button);
      end;
    end;
  end;
end;

procedure TCustomTabControl.DisplayScrollButtons;
var
  IsShowing: Boolean;
begin
  PositionButtons;
  IsShowing := False;
  if (FLastVisibleTab > -1) and (FLastVisibleTab <= Tabs.Count - 1) and
    not Multiline then
  begin
    IsShowing := (Tabs.Count > 0) and (FFirstVisibleTab > 0) or
              (FLastVisibleTab < Tabs.Count -1) or
              (Tabs[FLastVisibleTab].TabRect.Right >= Width +
               RightSideAdjustment);
  end;

  FButtons[tbLeft].Visible := IsShowing;
  FButtons[tbRight].Visible := IsShowing;
end;

procedure TCustomTabControl.DrawFocus;
const
  FocusRectAdjust: array[TTabStyle] of Integer = (2, 0, 0, 0);
var
  R,
  Rect: TRect;
begin
  if Focused and TabStop and not (csDesigning in ComponentState) and
    (TabIndex > -1) and Tabs[TabIndex].Visible then
  begin
    R := Classes.Rect(0, 0, RightSide, GetTotalTabHeight);
    Rect := Tabs[TabIndex].TabRect;
    AdjustTabClientRect(Rect);
    InflateRect(Rect, FocusRectAdjust[Style], FocusRectAdjust[Style]);
    Canvas.Start;
    try
      Canvas.SetClipRect(R);
      Canvas.DrawFocusRect(Rect);
    finally
      InflateRect(Rect, -FocusRectAdjust[Style], -FocusRectAdjust[Style]);
      Canvas.ResetClipRegion;
      Canvas.Stop;
    end;
  end;
end;

procedure TCustomTabControl.LayoutTabs;
var
  I,
  NewLeft,
  PrevTab,
  CurrTab,
  NextTab,
  MinTabs,
  NumTabs: Integer;
begin
  if (Style = tsNoTabs) then Exit;

  FRowCount := 0;
  MinTabs := 0;
  NumTabs := 0;

  FUpdating := True;
  try
    if Tabs.Count < 1 then Exit;
    FLayoutCount := 0;

    { Tabs start at 2 so that a selected tab will be flush with the left border }
    NewLeft := TabButtonsLeftMap[Style];
    FRowCount := 1;
    FLastVisibleTab := Tabs.Count - 1;

    { Find another Tab if the current one has been hidden }
    if (TabIndex <> -1) and not Tabs[TabIndex].Visible then
    begin
      PrevTab := TabIndex;
      NextTab := FindNextVisibleTab(TabIndex);
      if not Tabs[NextTab].Visible then NextTab := FindPrevVisibleTab(TabIndex);
      if not Tabs[NextTab].Visible then NextTab := PrevTab;
      TabIndex := NextTab;
    end;

    for I := FFirstVisibleTab to FLastVisibleTab do
    begin
      if not Tabs[I].Visible then Continue;

      { Set initial Height and Width }
      Tabs[I].Height := TabHeight;
      Tabs[I].Width := TabWidth;

      if MultiLine then
      begin
        { Check to see if Tab will fit on current row }
        if (NewLeft + Tabs[I].Width > RightSide) then
        begin
          Inc(FRowCount);
          NewLeft := TabButtonsLeftMap[Style];
        end;

        Tabs[I].FRow := FRowCount;
      end else
        if (NewLeft > RightSide) and (I > 0) then
        begin
          FLastVisibleTab := FindPrevVisibleTab(I - 1);
          Break;
        end;

      Tabs[I].Left := NewLeft;
      NewLeft := Tabs[I].TabRect.Right;

      if (NewLeft * 2) < RightSide then Inc(MinTabs);
      Inc(NumTabs);
    end;

    { Make sure the last visible tab is properly set. }
    if not MultiLine and
        (Tabs[FLastVisibleTab].TabRect.Left + SELECTED_TAB_SIZE_DELTA > RightSide) then
      FLastVisibleTab := FindPrevVisibleTab(FLastVisibleTab - 1);

    { Check here to see if the last row has enough tabs to fill it. If not then
      steal a tab from the prev row until we do or until the prev row is left
      with the min number of tabs. }
    if (FRowCount > 1) and (Style = tsTabs) then
    begin
      CurrTab := FLastVisibleTab;
      repeat
        Dec(CurrTab);
      until Tabs[CurrTab].Row <> FRowCount;

      while ((NewLeft * 2) < RightSide) and (NumTabs > MinTabs) and
        (CurrTab > 0) do
      begin
        Tabs[CurrTab].FRow := FRowCount;
        Inc(NewLeft, Tabs[CurrTab].Width);
        Dec(NumTabs);
        Dec(CurrTab);
      end;

      NewLeft := TabButtonsLeftMap[Style];
      for I := CurrTab + 1 to FLastVisibleTab do
      begin
        Tabs[I].Left := NewLeft;
        Inc(NewLeft, Tabs[I].Width);
      end
    end;

    { Recalculate all the rows of the selected Row and below if the Selected Tab is
      not on the first row }
    if MultiLine and (TabIndex <> -1) and (Tabs[TabIndex].Row > 1) and
        (FRowCount >= Tabs[TabIndex].Row) then
      CalculateRows(Tabs[TabIndex].Row);

    { Set the Top for each Tab based on its row }
    CalculateTabPositions;

    { Adjust each Tab's width to fit in its row if there is no fixed TabWidth and
      RaggedRight is not specified }
    if (not RaggedRight) and MultiLine and (TabWidth = 0) and (FRowCount > 1) then
      for I := 1 to FRowCount do
        StretchTabs(I);
  finally
    FUpdating := False;
  end;
end;

procedure TCustomTabControl.PositionButtons;
begin
  FButtons[tbRight].Top := GetTotalTabHeight - FButtons[tbRight].Height - 2;
  FButtons[tbLeft].Top := GetTotalTabHeight - FButtons[tbLeft].Height - 2;

  FButtons[tbRight].Left := Width - SCROLL_BUTTON_WIDTH;
  FButtons[tbLeft].Left := Width - ((SCROLL_BUTTON_WIDTH) * 2);
end;

function TCustomTabControl.RightSideAdjustment: Integer;
const
  Adjustment: array [TTabStyle] of Integer = (-2, 3, 6, 0);
begin
  Result := Adjustment[Style];
end;

procedure TCustomTabControl.SetTabs(const Value: TTabs);
begin
  FTabs.Assign(Value);
  RequestLayout;
end;

procedure TCustomTabControl.SetHotTrack(const Value: Boolean);
begin
  if FHotTrack <> Value then
  begin
    FHotTrack := Value;
    RequestLayout;
  end;
end;

procedure TCustomTabControl.SetHotTrackColor(const Value: TColor);
begin
  if FHotTrackColor <> Value then
  begin
    FHotTrackColor := Value;
  end;
end;

procedure TCustomTabControl.SetImages(const Value: TCustomImageList);
begin
  if Images <> nil then
    Images.UnRegisterChanges(FImageChangeLink);
  FImages := Value;
  if Images <> nil then
  begin
    Images.RegisterChanges(FImageChangeLink);
    Images.FreeNotification(Self);
  end;
  ImageListChange(Value);
end;

procedure TCustomTabControl.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = Images) then
    Images := nil;
end;

procedure TCustomTabControl.AdjustClientRect(var Rect: TRect);
begin
  { Don't include the tab area }
  Inc(Rect.Top, GetTotalTabHeight);
  InflateRect(Rect, -(FRAME_BORDER_WIDTH * 2), -(FRAME_BORDER_WIDTH * 2));

  { This can happen if the TabControl is not very tall }
  if Rect.Bottom < Rect.Top then
    Rect.Bottom := Rect.Top;
end;

function TCustomTabControl.CanChange: Boolean;
begin
  Result := True;
  if Assigned(FOnChanging) then
    FOnChanging(Self, Result);
end;

function TCustomTabControl.CanShowTab(TabIndex: Integer): Boolean;
begin
  Result := True;
end;

procedure TCustomTabControl.Change;
begin
  if Assigned(FOnChange) then
    FOnChange(Self);
end;

procedure TCustomTabControl.InternalDrawTabFrame(ACanvas: TCanvas; const ARect: TRect; Tab: TTab;
  HotTracking: Boolean = False);
var
  R: TRect;
  PrevPen: TPenRecall;

  procedure DrawTabFrame(Erase: Boolean);
  begin
    with ACanvas do
    begin
      if Erase then Pen.Color := clBackground else Pen.Color:= clBtnHighlight;
      Polyline([Point(R.Left, R.Bottom),
                Point(R.Left, R.Top + 2),
                Point(R.Left + 1, R.Top + 1),
                Point(R.Left + 2, R.Top),
                Point(R.Right - 3, R.Top)]);

      if Erase then Pen.Color := clBackground else Pen.Color:= clBtnShadow;
      Polyline([Point(R.Right - 2, R.Top + 2),
                Point(R.Right - 2, R.Bottom)]);

      if Erase then Pen.Color := clBackground else Pen.Color:= clBlack;
      Polyline([Point(R.Right - 2, R.Top + 1),
                Point(R.Right - 1, R.Top + 2),
                Point(R.Right - 1, R.Bottom)]);
    end;
  end;

begin
  if not Tab.Visible then Exit;
  with ACanvas do
  begin
    Start;
    try
      if not MultiLine then
        SetClipRect(ARect);
      R := Tab.TabRect;
      AdjustTabRect(R);
      case Style of
        tsTabs:
        begin
          if Tab.Index = TabIndex then
          begin
            Dec(R.Top, SELECTED_TAB_SIZE_DELTA);
            Inc(R.Right, SELECTED_TAB_SIZE_DELTA);
            Dec(R.Left, SELECTED_TAB_SIZE_DELTA);
            Inc(R.Bottom, SELECTED_TAB_SIZE_DELTA - 1);
          end;

          if DrawTab(Tab.Index, R, Tab.Enabled) then
          begin
            { Erase the frame area }
            PrevPen:= TPenRecall.Create(Pen);
            try
              Brush.Style := bsSolid;
              Pen.Color:= clBackground;
              Inc(R.Bottom, 1);
              Rectangle(R);
              InflateRect(R, -1, -1);
              Rectangle(R);
              InflateRect(R, 1, 1);
              Dec(R.Bottom, 1);
              if TabIndex = Tab.Index then
              begin
                InflateRect(R, -SELECTED_TAB_SIZE_DELTA, -SELECTED_TAB_SIZE_DELTA);
                Rectangle(R);
                InflateRect(R, SELECTED_TAB_SIZE_DELTA, SELECTED_TAB_SIZE_DELTA);
              end;

              DrawTabFrame(False);
            finally
              PrevPen.Free;
            end;
          end;
        end;
        tsButtons:
          begin
            InternalDrawFrame(ACanvas, R, True, (Tab.Index = TabIndex) or (Tab.Selected),
              True);
          end;
        tsFlatButtons:
          begin
            PrevPen := TPenRecall.Create(Pen);
            try
              Pen.Color:= clBtnShadow;
              MoveTo(R.Right, R.Top);
              LineTo(R.Right, R.Bottom - 1);
              Pen.Color:= clBtnHighlight;
              MoveTo(R.Right + 1, R.Top);
              LineTo(R.Right + 1, R.Bottom - 1);
            finally
              PrevPen.Free;
            end;

            Dec(R.Right, TAB_FLAT_BORDER);
            if (Tab.Index = TabIndex) or (Tab.Selected) then
              InternalDrawFrame(ACanvas, R, True, True, True)
            else
            begin
              Brush.Style := bsSolid;
              FillRect(R);
            end;
          end;
      end;
    finally
      if not MultiLine then
        ResetClipRegion;
      Stop;
    end;
  end;
end;

procedure TCustomTabControl.InternalDrawTabContents(ACanvas: TCanvas; const ARect: TRect; Tab: TTab;
  HotTracking: Boolean = False);
const
  TextFlags: array [TTabStyle] of Integer = ( Integer(AlignmentFlags_AlignLeft),
                                              Integer(AlignmentFlags_AlignHCenter),
                                              Integer(AlignmentFlags_AlignHCenter),
                                              0);
var
  PrevFontColor: TColor;
  R: TRect;
  ImageOffset: TPoint;
  TextOffset: TPoint;
  ImageRef: TCustomImageList;

  procedure CalcSelectedOffset(var Point: TPoint);
  begin
    if (Tab.Index = TabIndex) or Tab.Selected then
    begin
      Inc(Point.X, TabDefaultTextOffsetMap[Style]);
      Inc(Point.Y, TabDefaultTextOffsetMap[Style]);
    end;
  end;

begin
  if not Tab.Visible then Exit;
  PrevFontColor := Canvas.Font.Color;
  with ACanvas do
  begin
    Start;
    try
      if not MultiLine then
        SetClipRect(ARect);
      R := Tab.TabRect;
      AdjustTabClientRect(R);

      if not HotTracking then
        DrawHighlight(ACanvas, R, (TabIndex = Tab.Index), Tab.Highlighted, Tab.Enabled);

      ImageRef := Images;
      if HotTrack and Assigned(HotImages) then
        ImageRef := HotImages;

      if Assigned(ImageRef) and HasImages(Tab) then
      begin
        CalcImageTextOffset(R, Tab.Caption, ImageRef, ImageOffset, TextOffset);
        CalcSelectedOffset(ImageOffset);
        CalcSelectedOffset(TextOffset);
        if ((ImageRef = HotImages) and Hottracking) or (ImageRef = Images) then
        ImageRef.Draw(ACanvas, R.Left + ImageOffset.X, R.Top + ImageOffset.Y,
          GetImageIndex(Tab.Index), itImage, Tab.Enabled and Enabled);
      end else
      begin
        CalcImageTextOffset(R, Tab.Caption, nil, ImageOffset, TextOffset);
        CalcSelectedOffset(TextOffset);
      end;

      { Draw Text }
      if not Tab.Enabled or not Enabled then
      begin
        { offset the first text slightly to give the recessed disabled look }
        Font.Color := clDisabledLight;
        TextRect(R, R.Left + TextOffset.X + 1, R.Top + TextOffset.Y + 1, Tab.Caption,
                    Integer(AlignmentFlags_SingleLine) or
                    Integer(AlignmentFlags_ShowPrefix));
        Font.Color := clDisabledText;
      end else
        if HotTracking and (Style <> tsFlatButtons) then
          Font.Color := HotTrackColor
        else
          if Tab.Highlighted then
            Font.Color := clHighlightedText;

      TextRect(R, R.Left + TextOffset.X, R.Top + TextOffset.Y, Tab.Caption,
                Integer(AlignmentFlags_SingleLine) or
                Integer(AlignmentFlags_ShowPrefix));
    finally
      Font.Color := PrevFontColor;
      if not Multiline then
        ResetClipRegion;
      Stop;
    end;
  end;
end;

procedure TCustomTabControl.InternalDrawFrame(ACanvas: TCanvas; ARect: TRect; AShowFrame: Boolean = True;
  Sunken: Boolean = False; Fill : Boolean = True);
const
  FrameColorOuter: array [Boolean] of TColor = (clActiveLight, clActiveShadow);
  FrameColorInner: array [Boolean] of TColor = (clBackground, clActiveDark);
  FrameRectOffset: array [Boolean] of Integer = (3, -1);
var
  PrevPen: TPenRecall;
  PrevBrush: TBrushRecall;
  DrawRegion: QRegionH;
  ControlRegion: QRegionH;
  VControl: TControl;
  I: Integer;
  R: TRect;

  function DisplayFrame: Boolean;
  begin
    Result := AShowFrame or (Style = tsTabs);
  end;

begin
  with ACanvas do
  try
    Start;
    if (csDesigning in ComponentState) and not AShowFrame and (Style = tsNoTabs) then
    begin
      PrevPen := nil;
      PrevBrush := TBrushRecall.Create(Canvas.Brush);
      try
        PrevPen := TPenRecall.Create(Canvas.Pen);
        Pen.Style := psDot;
        Brush.Style := bsSolid;
        if Fill then FillRect(ARect);
        Rectangle(0, GetTotalTabHeight, Width, Height);
        Exit;
      finally
        PrevBrush.Free;
        PrevPen.Free;
      end;
    end;

    Dec(ARect.Bottom, 1);
    Dec(ARect.Right, 1);
    if DisplayFrame then
    begin
      PrevPen := TPenRecall.Create(Canvas.Pen);
      try
        Pen.Color := FrameColorOuter[Sunken];
        Polyline([Point(ARect.Left, ARect.Bottom),
                        Point(ARect.Left, ARect.Top),
                        Point(ARect.Right - 1, ARect.Top)]);
        Pen.Color := FrameColorInner[Sunken];
        Polyline([Point(ARect.Left + 1, ARect.Bottom - 1),
                        Point(ARect.Left + 1, ARect.Top + 1),
                        Point(ARect.Right - 2, ARect.Top + 1)]);
        Pen.Color := FrameColorOuter[not Sunken];
        Polyline([Point(ARect.Right, ARect.Top),
                        Point(ARect.Right, ARect.Bottom),
                        Point(ARect.Left, ARect.Bottom)]);
        Pen.Color := FrameColorInner[not Sunken];
        Polyline([Point(ARect.Right -1, ARect.Top + 1),
                        Point(ARect.Right - 1, ARect.Bottom - 1),
                        Point(ARect.Left + 1, ARect.Bottom - 1)]);
      finally
        PrevPen.Free;
      end;
    end;

    InflateRect(ARect, FrameRectOffset[DisplayFrame], FrameRectOffset[DisplayFrame]);
    Inc(ARect.Top);
    Inc(ARect.Left);

    { Clear the interior of the page }
    if Fill then
    begin
      FillRect(ARect);
    end else
    begin
      DrawRegion := QRegion_create(@ARect, QRegionRegionType_Rectangle);
      try
        { Erase the interior excluding any opaque controls }
        for I := 0 to ControlCount - 1 do
        begin
          VControl := TControl(Controls[I]);
          if (VControl.Visible or ((csDesigning in VControl.ComponentState) and
            not (csNoDesignVisible in VControl.ControlStyle))) and
            (csOpaque in VControl.ControlStyle) then
          begin
            R := VControl.BoundsRect;
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
          QWidget_erase(Self.Handle, DrawRegion);
      finally
        QRegion_destroy(DrawRegion);
      end;
    end;
  finally
    Stop;
  end;
end;

procedure TCustomTabControl.Paint;
const
  TabFrameAdj: array [Boolean] of Integer = (0, SELECTED_TAB_SIZE_DELTA);
var
  I: Integer;
  R: TRect;
begin
  inherited Paint;
  if FLayoutCount > 0 then LayoutTabs;

  EnableScrollButtons;
  DisplayScrollButtons;
  
  Canvas.Brush.Color := Color;
  Canvas.Brush.Style := bsSolid;

  R := Rect(0, GetTotalTabHeight, Width, Height);
  InternalDrawFrame(Canvas, R, ShowFrame, False, FErase);
  EraseControlFlag(False);

  if (Style <> tsNoTabs) and (Tabs.Count > 0) then
  begin
    BeginDblBuffer;
    try
      R := Rect(0, 0, RightSide, GetTotalTabHeight + 1);
      for I := FFirstVisibleTab to FLastVisibleTab do
        if Tabs[I].Visible then
          if I <> TabIndex then
          begin
            InternalDrawTabFrame(FDblBuffer.Canvas, R, Tabs[I], (I = FMouseOver) and HotTrack);
            InternalDrawTabContents(FDblBuffer.Canvas, R, Tabs[I], (I = FMouseOver) and HotTrack);
          end;
    finally
      EndDblBuffer;
    end;

    if (TabIndex >= FFirstVisibleTab) and (TabIndex <= FLastVisibleTab) and
      (TabIndex > -1) then
    begin
      { Draw Selected Tab }
      InternalDrawTabFrame(Canvas, R, Tabs[TabIndex], (TabIndex = FMouseOver) and HotTrack);
      InternalDrawTabContents(Canvas, R, Tabs[TabIndex], (TabIndex = FMouseOver) and HotTrack);
      DrawFocus;
    end;
  end;
end;

procedure TCustomTabControl.RequestAlign;
begin
  inherited RequestAlign;
  RequestLayout;
end;

procedure TCustomTabControl.RequestLayout;
begin
  if FUpdating then Exit;
  Inc(FLayoutCount);
  Invalidate;
end;

procedure TCustomTabControl.Resize;
begin
  inherited Resize;
  PositionButtons;
  RequestLayout;
end;

procedure TCustomTabControl.MouseUp(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer);
var
  vTabIndex: Integer;
begin
  if Button <> mbLeft then Exit;

  vTabIndex := IndexOfTabAt(X, Y);
  if vTabIndex = -1 then Exit;

  if not Tabs[vTabIndex].Enabled then Exit;

  { Mark tab as selected if CTRL down. If the user clicks on the currently
    selected tab then unselect the rest }
  if (ssCtrl in Shift) and MultiSelect and
    (Style in [tsButtons, tsFlatButtons]) then
  begin
    Tabs[vTabIndex].Selected := not Tabs[vTabIndex].Selected;
    if vTabIndex = TabIndex then
    begin
      TabIndex := -1;
      UnselectTabs;
    end;
    Invalidate;
  end else
  begin
    UnselectTabs;
    if (vTabIndex > -1) and (vTabIndex <> TabIndex) then
      if (Style <> tsFlatButtons) or (FTracking = vTabIndex) then
        TabIndex := vTabIndex;
  end;
  { Call inherited last. This allows the OnChanging, OnPageChanging and OnChanged
    events to fire before the Mouse up. }
  inherited MouseUp(Button, Shift, X, Y);
end;

procedure TCustomTabControl.MouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer);
begin
  inherited MouseDown(Button, Shift, X, Y);
  if (Button = mbLeft) and (Style = tsFlatButtons) then
  begin
    FTracking := IndexOfTabAt(X, Y);
    FMouseOver := -1;
    DoHotTrack(FTracking);
  end;
end;

procedure TCustomTabControl.DoHotTrack(const Value: Integer);

  procedure DrawHotTrack(Erase: Boolean);
  var
    R, Rect: TRect;
  begin
    if FMouseOver > -1 then
    begin
      R := Classes.Rect(0, 0, RightSide, GetTotalTabHeight + 1);
      case Style of
        tsTabs, tsButtons:
        begin
          if HotTrack then
          begin
            InternalDrawTabContents(Canvas, R, Tabs[FMouseOver], not Erase);
            if Erase then
            begin
              if (FMouseOver <> TabIndex) and (FMouseOver >= FFirstVisibleTab) and
                (FMouseOver <= FLastVisibleTab) then
              begin
                InternalDrawTabFrame(Canvas, R, Tabs[TabIndex], not Erase);
                InternalDrawTabContents(Canvas, R, Tabs[TabIndex], not Erase);
              end;
              DrawFocus;
            end;
          end;
        end;
        tsFlatButtons:
        begin
          if not (HotTrack) and (FTracking > -1) and (FMouseOver <> FTracking)
            and (FTracking <> TabIndex) then
          begin
            InternalDrawTabFrame(Canvas, R, Tabs[FTracking]);
            InternalDrawTabContents(Canvas, R, Tabs[FTracking]);
          end;

          if Erase then
          begin
            InternalDrawTabFrame(Canvas, R, Tabs[FMouseOver]);
            InternalDrawTabContents(Canvas, R, Tabs[FMouseOver]);
          end else
          begin
            Canvas.Start;
            try
              Canvas.SetClipRect(R);
              if (FMouseOver <> TabIndex) then
              begin
                Rect := Tabs[FMouseOver].TabRect;
                AdjustTabRect(Rect);
                Dec(Rect.Right, TAB_FLAT_BORDER);
                DrawShadePanel(Canvas, Rect, False, 1, Palette.ColorGroup(cgActive));
              end;
              InternalDrawTabContents(Canvas, R, Tabs[FMouseOver], HotTrack);
              if (FMouseOver = TabIndex) and
                ((FTracking = -1) or (FTracking = TabIndex)) then DrawFocus;
            finally
              Canvas.ResetClipRegion;
              Canvas.Stop;
            end;
          end;
          if FMouseOver = TabIndex then
            DrawFocus;
        end;
      end;
    end;
  end;

begin
  if (FMouseOver <> Value) then
  begin
    if MultiLine or ((FMouseOver >= FFirstVisibleTab) and
        (FMouseOver <= FLastVisibleTab)) then
      DrawHotTrack(True);
    FMouseOver := Value;
    if HotTrack or (FTracking = Value) then
      DrawHotTrack(False);
  end;
end;

procedure TCustomTabControl.MouseLeave(AControl: TControl);
begin
  inherited MouseLeave(AControl);
  // When the mouse leaves at high speed it might leave a tab highlighted. Kill it.
  DoHotTrack(-1);
end;

procedure TCustomTabControl.MouseMove(Shift: TShiftState; X, Y: Integer);
var
  Index: Integer;
begin
  inherited MouseMove(Shift, X, Y);
  Index := IndexOfTabAt(X, Y);
  if (Index = -1) or (Tabs[Index].TabRect.Left <= RightSide) then
    DoHotTrack(Index);
end;

function TCustomTabControl.DoMouseWheel(Shift: TShiftState;
  WheelDelta: Integer; const MousePos: TPoint): Boolean;
begin
  inherited DoMouseWheel(Shift, WheelDelta, MousePos);
  Result := True;
end;

function TCustomTabControl.DoMouseWheelDown(Shift: TShiftState;
  const MousePos: TPoint): Boolean;
begin
  Result := inherited DoMouseWheelDown(Shift, MousePos);
  if TabIndex > 0 then
    TabIndex := TabIndex - 1;
end;

function TCustomTabControl.DoMouseWheelUp(Shift: TShiftState;
  const MousePos: TPoint): Boolean;
begin
  Result := inherited DoMouseWheelUp(Shift, MousePos);
  if TabIndex < Tabs.Count-1 then
    TabIndex := TabIndex + 1;
end;

procedure TCustomTabControl.ImageListChange(Sender: TObject);
begin
  RequestLayout;
end;

procedure TCustomTabControl.KeyUp(var Key: Word; Shift: TShiftState);
var
  Delta: Integer;

  function RangeCheckTracking(const Value: Integer): Integer;
  begin
    Result := Value;
    if (Result > Tabs.Count - 1) or (Result < -1) then
      Result := FTracking;
  end;

  procedure ChangeTracking(const Delta: ShortInt);
  begin
    if FTracking = -1 then
      FTracking := RangeCheckTracking(TabIndex + Delta)
    else
    begin
      Tabs[FTracking].Selected := False;
      FTracking := RangeCheckTracking(FTracking + Delta);
    end;
    if FTracking > -1 then
      Tabs[FTracking].Selected := True;
    if not Multiline then
      ScrollTabs(Delta);
  end;

  procedure ChangeTabIndex(const Delta: Integer);
  begin
    if (TabIndex + Delta > Tabs.Count - 1) or (TabIndex + Delta < 0) then
      Exit
    else
      TabIndex := TabIndex + Delta;
  end;

begin
  inherited KeyUp(Key, Shift);
  Delta := 0;

  case Key of
    Key_Tab:
      if (ssCtrl in Shift) then
        if ssShift in Shift then
          Delta := -1
        else
          Delta := 1;
    Key_Right, Key_Down:
      if not (Shift = [ssAlt]) then
        Delta := 1;
    Key_Left, Key_Up:
      if not (Shift = [ssAlt]) then
        Delta := -1;
    Key_Home:
      if not (Shift = [ssAlt]) then
        if FTracking <> -1 then
          Delta := - FTracking
        else
          Delta := -TabIndex;
    Key_End:
      if not (Shift = [ssAlt]) then
        if FTracking <> -1 then
          Delta := Tabs.Count - FTracking - 1
        else
          Delta := Tabs.Count - TabIndex - 1;
    Key_Return, Key_Enter, Key_Space:
      if not (Shift = [ssAlt]) then
        if FTracking <> -1 then
          TabIndex := FTracking;
  end;

  if Delta <> 0 then
    if (Style = tsTabs) or (Key = Key_Tab) then
      ChangeTabIndex(Delta)
    else
      ChangeTracking(Delta);
end;

procedure TCustomTabControl.SetMultiLine(const Value: Boolean);
begin
  if FMultiLine <> Value then
  begin
    FMultiLine := Value;
    FFirstVisibleTab := 0;
    FLastVisibleTab := Tabs.Count-1;
    RequestLayout;
  end;
end;

procedure TCustomTabControl.SetMultiSelect(const Value: Boolean);
begin
  if FMultiSelect <> Value then
  begin
    FMultiSelect := Value;
    if not FMultiSelect then
      UnselectTabs;
    Invalidate;
  end;
end;

procedure TCustomTabControl.SetOwnerDraw(const Value: Boolean);
begin
  if FOwnerDraw <> Value then
  begin
    FOwnerDraw := Value;
  end;
end;

procedure TCustomTabControl.SetRaggedRight(const Value: Boolean);
begin
  if FRaggedRight <> Value then
  begin
    FRaggedRight := Value;
    RequestLayout;
  end;
end;

procedure TCustomTabControl.SetStyle(Value: TTabStyle);
begin
  if FStyle <> Value then
  begin
    FStyle := Value;
    if csDesigning in ComponentState then
      FShowFrame := FShowFrame and (Value = tsTabs);
    EraseControlFlag;
    RequestLayout;
  end;
end;

procedure TCustomTabControl.SetTabHeight(const Value: Smallint);
begin
  if FTabSize.Y <> Value then
  begin
    if Value < 0 then
      raise EInvalidOperation.CreateFmt(SPropertyOutOfRange, [Self.Classname]);
    FTabSize.Y := Value;
    TabsChanged;
  end;
end;

procedure TCustomTabControl.SetTabWidth(const Value: Smallint);
begin
  if FTabSize.X <> Value then
  begin
    if Value < 0 then
      raise EInvalidOperation.CreateFmt(SPropertyOutOfRange, [Self.Classname]);
    FTabSize.X := Value;
    TabsChanged;
  end;
end;

procedure TCustomTabControl.TabsChanged;
begin
  RequestLayout;
end;

procedure TCustomTabControl.SetShowFrame(const Value: Boolean);
begin
  if FShowFrame <> Value then
  begin
    FShowFrame := Value;
    EraseControlFlag;
    Invalidate;
  end;
end;

procedure TCustomTabControl.SetHotImages(const Value: TCustomImageList);
begin
  if HotImages <> nil then
    HotImages.UnRegisterChanges(FImageChangeLink);
  FHotImages := Value;
  if HotImages <> nil then
  begin
    HotImages.RegisterChanges(FImageChangeLink);
    HotImages.FreeNotification(Self);
  end;
  ImageListChange(Value);
end;

procedure TCustomTabControl.UnselectTabs;
var
  I: Integer;
begin
  for I := 0 to Tabs.Count-1 do
    if Tabs[I].Selected then
      Tabs[I].Selected := False;
end;

{ TTabSheet }

constructor TTabSheet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Align := alClient;
  ControlStyle := ControlStyle + [csAcceptsControls, csNoDesignVisible];
  Visible := False;
  TabVisible := True;
end;

destructor TTabSheet.Destroy;
begin
  if (FPageControl <> nil) and
    not (csDestroying in FPageControl.ComponentState) then
    FPageControl.RemovePage(Self);
  inherited Destroy;
end;

procedure TTabSheet.InitWidget;
begin
  inherited;
  QWidget_setFocusPolicy(Handle, QWidgetFocusPolicy_NoFocus);
end;

function TTabSheet.GetTabIndex: Integer;
begin
  if Assigned(FTab) then
    Result := FTab.Index
  else
    Result := -1;
end;

procedure TTabSheet.AdjustClientRect(var Rect: TRect);
begin
  inherited AdjustClientRect(Rect);
  InflateRect(Rect, -BorderWidth, -BorderWidth);
  if Rect.Bottom < Rect.Top then
    Rect.Bottom := Rect.Top;
end;

procedure TTabSheet.DoHide;
begin
  if Assigned(FOnHide) then FOnHide(Self);
end;

procedure TTabSheet.DoShow;
begin
  if Assigned(FOnShow) then FOnShow(Self);
end;

procedure TTabSheet.EnabledChanged;
begin
  inherited;
  if Assigned(FPageControl) then
    FPageControl.UpdateTab(Self);
end;

procedure TTabSheet.ReadState(Reader: TReader);
begin
  inherited ReadState(Reader);
  if Reader.Parent is TPageControl then
    PageControl := TPageControl(Reader.Parent);
end;

procedure TTabSheet.TextChanged;
begin
  if Assigned(FPageControl) then
    FPageControl.UpdateTab(Self);
end;

procedure TTabSheet.ShowingChanged;
begin
  inherited;
  try
    if Showing then
      DoShow
    else
      DoHide;
  except
    Application.HandleException(Self);
  end;
end;

procedure TTabSheet.SetBorderWidth(const Value : TBorderWidth);
begin
  if FBorderWidth <> Value then
  begin
    FBorderWidth := Value;
    Realign;
    Invalidate;
  end;
end;

procedure TTabSheet.SetHighlighted(const Value: Boolean);
begin
  if FHighlighted <> Value then
    FHighlighted := Value;
  if Assigned(FPageControl) then
    FPageControl.UpdateTab(Self);
end;

procedure TTabSheet.SetImageIndex(const Value: TImageIndex);
begin
  if FImageIndex <> Value then
    FImageIndex := Value;
  if Assigned(FPageControl) then
    FPageControl.UpdateTab(Self);
end;

procedure TTabSheet.SetPageControl(const Value: TPageControl);
begin
  if PageControl <> Value then
  begin
    if PageControl <> nil then PageControl.RemovePage(Self);
    Parent := Value;
    if Value <> nil then Value.InsertPage(Self);
  end;
end;

function TTabSheet.GetPageIndex: Integer;
begin
  if PageControl <> nil then
    Result := PageControl.FPages.IndexOf(Self)
  else
    Result := -1;
end;

procedure TTabSheet.SetPageIndex(const Value: Integer);
var
  I, MaxPageIndex: Integer;
begin
  if PageControl <> nil then
begin
    MaxPageIndex := PageControl.PageCount - 1;
    if Value > MaxPageIndex then
      raise EListError.CreateResFmt(@SPageIndexError, [Value, MaxPageIndex]);
    I := TabIndex;
    PageControl.FPages.Move(PageIndex, Value);
    PageControl.TabIndex := PageIndex;
    if I >= 0 then PageControl.MoveTab(I, PageControl.TabIndex);
  end;
end;

procedure TTabSheet.SetTabVisible(const Value: Boolean);
begin
  if FTabVisible <> Value then
    FTabVisible := Value;
  if Assigned(FPageControl) then
    FPageControl.UpdateTab(Self);
end;

{ TPageControl }

constructor TPageControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle - [csAcceptsControls];
  FPages := TList.Create;
end;

procedure TPageControl.DoContextPopup(const MousePos: TPoint; var Handled: Boolean);
begin
  { Since the TTabSheet doesn't cover the entire client area (there is a 4 pixel
    border) we don't want the popup to display for the PageControl unless it is
    within the Tab area. }
  Handled := (MousePos.Y > GetTotalTabHeight) and
              (ControlAtPos(MousePos, False, True) = nil);
  if not Handled then inherited DoContextPopup(MousePos, Handled);
end;

function TPageControl.CanShowTab(TabIndex: Integer): Boolean;
begin
  Result := TTabSheet(FPages[TabIndex]).Enabled;
end;

procedure TPageControl.Changed(Value: Integer);
begin
  inherited Changed(Value);
  ActivePageIndex := Value;
end;

procedure TPageControl.Change;
var
  Form: TCustomForm;
begin
  UpdateActivePage;
  if csDesigning in ComponentState then
  begin
    Form := GetParentForm(Self);
    if (Form <> nil) and (Form.DesignerHook <> nil) then Form.DesignerHook.Modified;
  end;
  inherited Change;
end;

procedure TPageControl.ChangeActivePage(Page: TTabSheet);
var
  ParentForm: TCustomForm;
  AllowChange: Boolean;
begin
  AllowChange := True;
  if FActivePage <> Page then
  begin
    if not (csLoading in ComponentState) then
      PageChanging(Page, AllowChange);
    if not AllowChange then Exit;

    ParentForm := GetParentForm(Self);
    if (ParentForm <> nil) and (FActivePage <> nil) and
      FActivePage.ContainsControl(ParentForm.ActiveControl) then
    begin
      ParentForm.ActiveControl := FActivePage;
      if ParentForm.ActiveControl <> FActivePage then
      begin
        TabIndex := FActivePage.TabIndex;
        Exit;
      end;
    end;
    if Page <> nil then
    begin
      Page.Visible := True;
      Page.BringToFront;
      if (ParentForm <> nil) and (FActivePage <> nil) and
        (ParentForm.ActiveControl = FActivePage) then
        if Page.CanFocus then
          ParentForm.ActiveControl := Page else
          ParentForm.ActiveControl := Self;
    end;
    if FActivePage <> nil then FActivePage.Visible := False;
    FActivePage := Page;
    if not (csLoading in ComponentState) then
      PageChange;
    if (ParentForm <> nil) and (FActivePage <> nil) and
      (ParentForm.ActiveControl = FActivePage) then
      FActivePage.SelectFirst;
  end;
end;

destructor TPageControl.Destroy;
begin
  FPages.Free;
  inherited Destroy;
end;

function TPageControl.FindNextPage(CurPage: TTabSheet; GoForward,
  CheckTabVisible: Boolean): TTabSheet;
var
  I, StartIndex: Integer;
begin
  if (PageCount > 0) then
  begin
    StartIndex := FPages.IndexOf(CurPage);
    if StartIndex = -1 then
      if GoForward then
        StartIndex := PageCount - 1
      else
        StartIndex := 0;
    I := StartIndex;
    repeat
      if GoForward then
      begin
        Inc(I);
        if I = PageCount then
          I := 0;
      end else
      begin
        if I = 0 then
          I := PageCount;
        Dec(I);
      end;
      Result := Pages[I];
      if not CheckTabVisible or Result.TabVisible then
        Exit;
    until I = StartIndex;
  end;
  Result := nil;
end;

procedure TPageControl.DeleteTab(Page: TTabSheet; Index: Integer);
var
  UpdateIndex: Boolean;
begin
  UpdateIndex := Page = ActivePage;
  Tabs.Delete(Index);
  if UpdateIndex then
  begin
    if Index >= Tabs.Count then
      Index := Tabs.Count - 1;
    TabIndex := Index;
  end;
  UpdateActivePage;
end;

function TPageControl.GetActivePageIndex: Integer;
begin
  if ActivePage <> nil then
    Result := ActivePage.GetPageIndex
  else
    Result := -1;
end;

function TPageControl.DesignEventQuery(Sender: QObjectH; Event: QEventH): Boolean;
var
  Index: Integer;
  MousePos: TPoint;
  Control: TControl;
begin
  Result := False;
  if (Sender = Handle) and
    (QEvent_type(Event) in [QEventType_MouseButtonPress,
     QEventType_MouseButtonRelease, QEventType_MouseButtonDblClick]) then
  begin
    MousePos := Point(QMouseEvent_x(QMouseEventH(Event)),
      QMouseEvent_y(QMouseEventH(Event)));
    Control := ControlAtPos(MousePos, True, True);
    if (Control is TTabScrollButton) then
      Result := Control.Enabled
    else
    begin
      Index := IndexOfTabAt(MousePos.X, MousePos.Y);
      Result := (Index <> -1) and (Index <> TabIndex);
    end;
  end;
end;

procedure TPageControl.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
begin
  for I := 0 to FPages.Count - 1 do Proc(TComponent(FPages[I]));
end;

function TPageControl.GetPage(Index: Integer): TTabSheet;
begin
  Result := TTabSheet(FPages[Index]);
end;

function TPageControl.GetPageCount: Integer;
begin
  Result := FPages.Count;
end;

procedure TPageControl.MoveTab(CurIndex, NewIndex: Integer);
begin
  Tabs[CurIndex].Index := NewIndex;
end;

procedure TPageControl.InsertPage(const APage: TTabSheet);
begin
  BeginUpdate;
  try
    FPages.Add(aPage);
    APage.FPageControl := Self;
    InsertTab(APage);
    UpdateActivePage;
  finally
    EndUpdate;
  end;
end;

procedure TPageControl.InsertTab(Page: TTabSheet);
begin
  Page.FTab := TTab(Tabs.Add(Page.Caption));
  UpdateTab(Page);
  UpdateActivePage;
end;

procedure TPageControl.RemovePage(const APage: TTabSheet);
var
  NextSheet: TTabSheet;
begin
  NextSheet := FindNextPage(aPage, True, not (csDesigning in ComponentState));
  if NextSheet = APage then NextSheet := nil;
  DeleteTab(APage, APage.PageIndex);
  APage.FPageControl := nil;
  FPages.Remove(APage);
  SetActivePage(NextSheet);
end;

procedure TPageControl.UpdateTab(Page: TTabSheet);
begin
  if Assigned(FTabs) then
  begin
    Tabs[Page.TabIndex].Caption := Page.Caption;
    Tabs[Page.TabIndex].ImageIndex := Page.ImageIndex;
    Tabs[Page.TabIndex].Highlighted := Page.Highlighted;
    Tabs[Page.TabIndex].Visible := Page.TabVisible;
  end;
end;

procedure TPageControl.SelectNextPage(GoForward: Boolean);
var
  Page: TTabSheet;
begin
  Page := FindNextPage(ActivePage, GoForward, True);
  if (Page <> nil) and (Page <> ActivePage) then
  begin
    TabIndex := Page.TabIndex;
  end;
end;

procedure TPageControl.SetActivePage(aPage: TTabSheet);
begin
  if (aPage <> nil) and (aPage.PageControl <> Self) then Exit;
  ChangeActivePage(aPage);
  if aPage = nil then
    TabIndex := -1
  else if aPage = FActivePage then
  begin
    TabIndex := aPage.PageIndex;
  end;
end;

procedure TPageControl.SetActivePageIndex(const Value: Integer);
begin
  if (Value > -1) and (Value < PageCount) then
    ActivePage := TTabSheet(Pages[Value])
  else
    ActivePage := nil;
end;

procedure TPageControl.PageChange;
begin
  if Assigned(FOnPageChange) then
    FOnPageChange(Self);
end;

procedure TPageControl.PageChanging(NewPage: TTabSheet; var AllowChange: Boolean);
begin
  if Assigned(FOnPageChanging) then
    FOnPageChanging(Self, NewPage, AllowChange);
end;

procedure TPageControl.SetChildOrder(Child: TComponent; Order: Integer);
begin
  TTabSheet(Child).PageIndex := Order;
end;

procedure TPageControl.ShowControl(AControl: TControl);
begin
  if (AControl is TTabSheet) and (TTabSheet(AControl).PageControl = Self) then
    SetActivePage(TTabSheet(AControl));
  inherited ShowControl(AControl);
end;

procedure TPageControl.UpdateActivePage;
begin
  if TabIndex >= 0 then
    SetActivePage(FPages[TabIndex])
  else
    SetActivePage(nil);
end;

procedure TPageControl.Update;
begin
  if Style = tsNoTabs then Realign;   
  inherited Update;
end;

{ utility routines for TreeView/TreeNode }

procedure TreeViewError(const Msg: string);
begin
  raise ETreeViewError.Create(Msg);
end;

procedure TreeViewErrorFmt(const Msg: string; Format: array of const);
begin
  raise ETreeViewError.CreateFmt(Msg, Format);
end;

type
  TListViewHeader = class(TCustomHeaderControl)
  private
    FHidden: Boolean;
    FHiddenChanging: Boolean;
    procedure SetSections(const Value: TListColumns);
    function GetSections: TListColumns;
    procedure SetHidden(const Value: Boolean);
    function ListViewHandle: QListViewH;
    function ViewControl: TCustomViewControl;
  protected
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    function GetHandle: QHeaderH; override;
    procedure ColumnClicked(Section: TCustomHeaderSection); override;
    procedure ColumnMoved(Section: TCustomHeaderSection); override;
    procedure ColumnResized(Section: TCustomHeaderSection); override;
    procedure CreateWidget; override;
    procedure DestroyWidget; override;
    procedure HookEvents; override;
    procedure InitWidget; override;
    procedure Update; override;
    procedure UpdateWidgetShowing; override;
    property Handle: QHeaderH read GetHandle;
    property Hidden: Boolean read FHidden write SetHidden default True;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property Sections: TListColumns read GetSections write SetSections;
  end;

type
  TSubItems = class(TStringList)
  private
    FOwner: TCustomViewItem;
  protected
    function GetHandle: QListViewItemH;
    function HandleAllocated: Boolean;
    function Add(const S: string): Integer; override;
    procedure Delete(Index: Integer); override;
    procedure Put(Index: Integer; const S: string); override;
    procedure PutObject(Index: Integer; AObject: TObject); override;
    procedure InsertItem(Index: Integer; const S: string; AObject: TObject); override;
  public
    constructor Create(AOwner: TCustomViewItem);
    procedure Insert(Index: Integer; const S: string); override;
    procedure AssignTo(Dest: TPersistent); override;
    property Handle: QListViewItemH read GetHandle;
    property Owner: TCustomViewItem read FOwner;
  end;

procedure TCustomViewItems.Delete(Index: Integer);
begin
  FItems[Index].Delete;
end;

function TCustomViewItems.FindViewItem(ItemH: QListViewItemH): TCustomViewItem;
var
  I: Integer;
begin
  Result := nil;
  if ItemH = nil then
    Exit;
  Result := TCustomViewItem(QClxObjectMap_find(ItemH));
  if Assigned(Result) then
    Exit;
  for I := 0 to Count-1 do
  begin
    if FItems[I].Handle = ItemH then
    begin
      Result := FItems[I];
      Exit;
    end;
  end;
end;

{ TSubItems }

function TSubItems.Add(const S: string): Integer;
var
  WS: WideString;
begin
  Result := inherited Add(S);
  Objects[Result] := Pointer(-1);
  if HandleAllocated and FOwner.ViewControlValid and
  FOwner.ViewControl.ShowColumnHeaders then
  begin
    WS := S;
    QListViewItem_setText(Handle, Result+1, PWideString(@WS));
  end;
end;

procedure TSubItems.AssignTo(Dest: TPersistent);
var
  I: Integer;
begin
  if Dest is TSubItems then
  begin
    BeginUpdate;
    try
      TStrings(Dest).Clear;
      for I := 0 to Count-1 do
        TStrings(Dest).AddObject(Strings[I], Objects[I]);
    finally
      EndUpdate;
    end;
  end
  else
    inherited AssignTo(Dest);
end;

constructor TSubItems.Create(AOwner: TCustomViewItem);
begin
  inherited Create;
  FOwner := AOwner;
end;

procedure TSubItems.Delete(Index: Integer);
begin
  inherited Delete(Index);
  if HandleAllocated then
    QListViewItem_setText(Handle, Index+1, nil);
end;

function TSubItems.GetHandle: QListViewItemH;
begin
  if FOwner.HandleAllocated then
    Result := FOwner.Handle
  else
    Result := nil;
end;

function TSubItems.HandleAllocated: Boolean;
begin
  Result := Handle <> nil;
end;

procedure TSubItems.Insert(Index: Integer; const S: string);
begin
  inherited Insert(Index, S);
  Objects[Index] := Pointer(-1);
end;

procedure TSubItems.InsertItem(Index: Integer; const S: string; AObject: TObject);
var
  WS: WideString;
begin
  inherited InsertItem(Index, S, AObject);
  if HandleAllocated and FOwner.ViewControlValid and
  FOwner.ViewControl.ShowColumnHeaders then
  begin
    Inc(Index);
    WS := S;
    QListViewItem_setText(FOwner.Handle, Index, PWideString(@WS));
    FOwner.ImageIndexChange(Index, Integer(AObject));
  end;
end;

procedure TSubItems.Put(Index: Integer; const S: string);
var
  WS: WideString;
begin
  inherited Put(Index, S);
  if HandleAllocated and FOwner.ViewControlValid and
  FOwner.ViewControl.ShowColumnHeaders then
  begin
    WS := S;
    QListViewItem_setText(Handle, Index+1, PWideString(@WS));
  end;
end;

procedure TSubItems.PutObject(Index: Integer; AObject: TObject);
begin
  if Integer(Objects[Index]) <> Integer(AObject) then
  begin
    inherited PutObject(Index, AObject);
    Inc(Index);
    FOwner.ImageIndexChange(Index, Integer(AObject));
  end;
end;

{ TCustomViewControl }

constructor TCustomViewControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csCaptureMouse, csClickEvents, csDoubleClicks];
  FImageLink := TChangeLink.Create;
  FImageLink.OnChange := ImageListChange; 
  FHeader := TListViewHeader.Create(Self);
  FIndent := 20;
  FTimer := TTimer.Create(nil);
  FTimer.Enabled := False;
  FTimer.Interval := 500;
  FTimer.OnTimer := TimerIntervalElapsed;
  FSortDirection := sdAscending;
  ParentColor := False;
  TabStop := True;
  BorderStyle := bsSunken3d;

  InputKeys := [ikChars, ikArrows];
  Height := 97;
  Width := 121;
end;

destructor TCustomViewControl.Destroy;
begin
  CheckRemoveEditor;
  if Assigned(FMemStream) then
    FreeAndNil(FMemStream);
  FTimer.Free;
  FHeader.Free;
  FImageLink.Free;
  inherited Destroy;
  if Assigned(FItemHooks) then
    QClxListViewHooks_destroy(FItemHooks);
end;

procedure TCustomViewControl.ColorChanged;
begin
  inherited ColorChanged;
  UpdateControl;
end;

procedure TCustomViewControl.CreateWidget;
begin
  FHandle := QListView_create(ParentWidget, nil);
  Hooks := QListView_hook_create(FHandle);
  FItemHooks := QClxListViewHooks_create;

  FViewportHandle := QScrollView_viewport(Handle);
  QClxObjectMap_add(FViewportHandle, Integer(Self));
  FHScrollHandle := QScrollView_horizontalScrollBar(Handle);
  QClxObjectMap_add(FHScrollHandle, Integer(Self));
  FVScrollHandle := QScrollView_verticalScrollBar(Handle);
  QClxObjectMap_add(FVScrollHandle, Integer(Self));
end;

const
  cSelMode: array [Boolean] of QListViewSelectionMode = (QListViewSelectionMode_Single,
  QListViewSelectionMode_Extended);
  cSortDirection: array [TSortDirection] of Boolean = (True, False);

procedure TCustomViewControl.InitWidget;
begin
  inherited InitWidget;
  QWidget_setMouseTracking(FViewportHandle, True);
  QWidget_setAcceptDrops(FViewportHandle, True);
  QListView_setShowSortIndicator(Handle, FShowColumnSortIndicators);
  QListView_setTreeStepSize(Handle, FIndent);
  TListViewHeader(FHeader).Hidden := not FShowColumnHeaders;
  QListView_setSelectionMode(Handle, cSelMode[FMultiSelect]);
  QListView_setAllColumnsShowFocus(Handle, FRowSelect);
  if Sorted then
    QListView_setSorting(Handle, SortColumn, cSortDirection[SortDirection])
  else
    QListView_setSorting(Handle, -1, False);
  UpdateControl;
end;

function TCustomViewControl.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  if (Sender = QScrollView_verticalScrollBar(Handle)) or
  (Sender = QScrollView_horizontalScrollBar(Handle)) then
  begin
    Result := False;
    case QEvent_type(Event) of
      QEventType_MouseButtonPress,
      QEventType_MouseButtonDblClick,
      QEventType_FocusIn:
        CheckRemoveEditor;
    end;
    Exit;
  end;
 
  if (QEvent_type(Event) = QEventType_FocusIn) then
    CheckRemoveEditor;
  Result := inherited EventFilter(Sender, Event);
end;

procedure TCustomViewControl.ItemChangeHook(item: QListViewItemH; _type: TItemChange);
begin
  try
    ItemChange(item, _type);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomViewControl.ItemChangingHook(item: QListViewItemH; _type: TItemChange;
  var Allow: Boolean);
begin
  try
    ItemChanging(item, _type, Allow);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomViewControl.ItemCheckedHook(item: QListViewItemH; Checked: Boolean);
begin
  try
    ItemChecked(item, Checked);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomViewControl.ItemChecked(item: QListViewItemH; Checked: Boolean);
begin
  { stubbed for children }
end;

procedure TCustomViewControl.ItemDestroyedHook(AItem: QListViewItemH);
begin
  try
    ItemDestroyed(AItem);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomViewControl.ItemDestroyed(AItem: QListViewItemH);
begin
  { stubbed for children }
end;

procedure TCustomViewControl.ItemSelectedHook(item: QListViewItemH; wasSelected: Boolean);
begin
  try
    ItemSelected(item, wasSelected);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomViewControl.ItemChange(item: QListViewItemH; _type: TItemChange);
begin
  { stubbed for children }
end;

procedure TCustomViewControl.ItemChanging(item: QListViewItemH; _type: TItemChange;
  var Allow: Boolean);
begin
  { stubbed for children }
end;

procedure TCustomViewControl.ItemSelected(item: QListViewItemH; wasSelected: Boolean);
begin
  { stubbed for children }
end;

procedure TCustomViewControl.DoGetImageIndex(item: TCustomViewItem);
begin
  { stubbed for children }
end;

procedure TCustomViewControl.DoEditing(AItem: TCustomViewItem; var AllowEdit: Boolean);
begin
  { stubbed for children }
end;

procedure TCustomViewControl.DoEdited(AItem: TCustomViewItem; var S: WideString);
begin
  { stubbed for children }
end;

procedure TCustomViewControl.ItemExpandingHook(item: QListViewItemH; Expand: Boolean;
  var Allow: Boolean);
begin
  try
    ItemExpanding(item, Expand, Allow);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomViewControl.ItemExpanding(item: QListViewItemH; Expand: Boolean;
  var Allow: Boolean);
begin
  { stubbed for children }
end;

procedure TCustomViewControl.ItemExpandedHook(item: QListViewItemH; Expand: Boolean);
begin
  try
    ItemExpanded(item, Expand);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomViewControl.ItemExpanded(item: QListViewItemH; Expand: Boolean);
begin
  { stubbed for children }
end;

function TCustomViewControl.IsEditing: Boolean;
begin
  Result := Assigned(FEditor) and FEditor.FEditing;
end;

procedure TCustomViewControl.StartEditTimer;
begin
  if not ReadOnly then
    FTimer.Enabled := True;
  FAllowEdit := False;
end;

procedure TCustomViewControl.TimerIntervalElapsed(Sender: TObject);
begin
  if Visible then
  begin
    FTimer.Enabled := False;
    FAllowEdit := True;
  end;
end;

procedure TCustomViewControl.CheckRemoveEditor;
begin
  if not Assigned(FEditor) then
    Exit;
  FEditor.EditFinished(True);
  FEditor := nil;
end;

procedure TCustomViewControl.EditItem;
begin
  CheckRemoveEditor;
  if not (csDesigning in ComponentState) and not ReadOnly then
  begin
    FEditor := CreateEditor;
    FEditor.Execute;
  end;
end;

function TCustomViewControl.FindDropTarget: TCustomViewItem;
var
  Pt: TPoint;
begin
  if HandleAllocated then
  begin
    QCursor_pos(@Pt);
    QWidget_mapFromGlobal(ViewportHandle, @Pt, @Pt);
    Result := TCustomViewItem(QClxObjectMap_find(QListView_itemAt(Handle, @Pt)));
  end
  else
    Result := nil;
end;

function TCustomViewControl.CreateEditor: TItemEditor;
begin
  Result := TItemEditor.Create(Self);
end;

function TCustomViewControl.GetHandle: QListViewH;
begin
  HandleNeeded;
  Result := QListViewH(FHandle);
end;

function TCustomViewControl.GetIndent: Integer;
begin
  Result := FIndent;
end;

procedure TCustomViewControl.SetIndent(const Value: Integer);
begin
  if FIndent <> Value then
  begin
    FIndent := Value;
    if FIndent < 0 then
      FIndent := 0;
    if HandleAllocated then
    begin
      QListView_setTreeStepSize(Handle, FIndent);
      UpdateControl;
    end;
  end;
end;

procedure TCustomViewControl.SetMultiSelect(const Value: Boolean);
begin
  if MultiSelect <> Value then
  begin
    FMultiSelect := Value;
    if HandleAllocated then
    begin
      if FMultiSelect then
        QListView_selectAll(Handle, False);
      QListView_setSelectionMode(Handle, cSelMode[FMultiSelect]);
    end;
  end;
end;

function TCustomViewControl.GetMultiSelect: Boolean;
begin
  Result := FMultiSelect;
end;

function TCustomViewControl.GetRowSelect: Boolean;
begin
  Result := FRowSelect;
end;

procedure TCustomViewControl.SetRowSelect(const Value: Boolean);
begin
  if RowSelect <> Value then
  begin
    FRowSelect := Value;
    if HandleAllocated then
      QListView_setAllColumnsShowFocus(Handle, FRowSelect);
  end;
end;

procedure TCustomViewControl.InvertSelection;
begin
  if HandleAllocated then
    QListView_invertSelection(Handle);
end;

procedure TCustomViewControl.SetImageList(const Value: TCustomImageList);
begin
  if FImageList <> Value then
  begin
    if Assigned(FImageList) then
      FImageList.UnRegisterChanges(FImageLink);
    FImageList := Value;
    if Assigned(FImageList) then
      FImageList.RegisterChanges(FImageLink);
    ImageListChanged;
  end;
end;

procedure TCustomViewControl.ImageListChange(Sender: TObject);
begin
  ImageListChanged;
end;

procedure TCustomViewControl.ImageListChanged;
begin
  { stubbed out for children }
end;

function TCustomViewControl.NeedKey(Key: Integer; Shift: TShiftState;
const KeyText: WideString): Boolean;
begin
  Result := inherited NeedKey(Key, Shift, KeyText) and (Shift * [ssShift, ssAlt, ssCtrl] = []);
end;

procedure TCustomViewControl.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);

  if (AComponent = FImageList) then
  begin
    if (Operation = opRemove) then
      FImageList := nil;
    ImageListChanged;
  end;
end;

procedure TCustomViewControl.SetOwnerDraw(const Value: Boolean);
begin
  if Value <> FOwnerDraw then
  begin
    FOwnerDraw := Value;
    if HandleAllocated then
      QWidget_update(ViewportHandle);
  end;
end;

type
  TViewControlItemPaint_event = procedure(p: QPainterH; item: QListViewItemH; column,
    width, alignment: Integer; var stage: Integer) of object cdecl;
  TViewControlBranchPaint_event = procedure(p: QPainterH; item: QListViewItemH;
    w, y, h: Integer; style: GUIStyle; var stage: Integer) of object cdecl;
  TViewControlItemSelected_event = procedure (item: QListViewItemH;
    wasSelected: Boolean) of object cdecl;
  TViewControlItemChange_event = procedure (item: QListViewItemH;
    _type: TItemChange) of object cdecl;
  TViewControlItemChanging_event = procedure (item: QListViewItemH;
    _type: TItemChange; var Allow: Boolean) of object cdecl;
  TViewControlItemExpanding_event = procedure (item: QListViewItemH;
    Expanding: Boolean; var Allow: Boolean) of object cdecl;
  TViewControlItemExpanded_event = procedure (item: QListViewItemH;
    Expanding: Boolean) of object cdecl;
  TViewControlItemChecked_event = procedure (item: QListViewItemH;
    Checked: Boolean) of object cdecl;
  TViewControlItemDestroyed_event = procedure (item: QListViewItemH) of object cdecl;

procedure TCustomViewControl.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  TViewControlItemPaint_event(Method) := ItemPaintHook;
  QClxListViewHooks_hook_PaintCell(FItemHooks, Method);
  TViewControlBranchPaint_event(Method) := BranchPaintHook;
  QClxListViewHooks_hook_paintBranches(FItemHooks, Method);
  TViewControlItemSelected_event(Method) := ItemSelectedHook;
  QClxListViewHooks_hook_setSelected(FItemHooks, Method);
  TViewControlItemChange_event(Method) := ItemChangeHook;
  QClxListViewHooks_hook_change(FItemHooks, Method);
  TViewControlItemChanging_event(Method) := ItemChangingHook;
  QClxListViewHooks_hook_changing(FItemHooks, Method);
  TViewControlItemExpanding_event(Method) := ItemExpandingHook;
  QClxListViewHooks_hook_expanding(FItemHooks, Method);
  TViewControlItemExpanded_event(Method) := ItemExpandedHook;
  QClxListViewHooks_hook_expanded(FItemHooks, Method);
  TViewControlItemChecked_event(Method) := ItemCheckedHook;
  QClxListViewHooks_hook_checked(FItemHooks, Method);
  TViewControlItemDestroyed_event(Method) := ItemDestroyedHook;
  QClxListViewHooks_hook_destroyed(FItemHooks, Method);

  TEventFilterMethod(Method) := MainEventFilter;

  FViewportHooks := QWidget_hook_create(FViewportHandle);
  Qt_hook_hook_events(FViewportHooks, Method);
  FHScrollHooks := QScrollBar_hook_create(FHScrollHandle);
  Qt_hook_hook_events(FHScrollHooks, Method);
  FVScrollHooks := QScrollBar_hook_create(FVScrollHandle);
  Qt_hook_hook_events(FVScrollHooks, Method);
  QObject_destroyed_event(Method) := ViewportDestroyed;
  QObject_hook_hook_destroyed(FViewportHooks, Method);
end;

function TCustomViewControl.IsCustomDrawn: Boolean;
begin
  Result := IsOwnerDrawn or Assigned(FOnCustomDrawItem) or
            Assigned(FOnCustomDrawSubItem) or Assigned(FOnCustomDrawBranch);
end;

function TCustomViewControl.IsOwnerDrawn: Boolean;
begin
  Result := False;
end;

function TCustomViewControl.DoCustomDrawViewItem(Item: TCustomViewItem;
  Canvas: TCanvas; const Rect: TRect; State: TCustomDrawState;
  Stage: TCustomDrawStage): Boolean;
begin
  Result := True;
  if Assigned(FOnCustomDrawItem) then FOnCustomDrawItem(Self, Item,
    Canvas, Rect, State, Stage, Result);
end;

function TCustomViewControl.DoCustomDrawViewSubItem(Item: TCustomViewItem;
  SubItem: Integer; Canvas: TCanvas; const Rect: TRect; State: TCustomDrawState;
  Stage: TCustomDrawStage): Boolean;
begin
  Result := True;
  if Assigned(FOnCustomDrawSubItem) then FOnCustomDrawSubItem(Self, Item,
    SubItem, Canvas, Rect, State, Stage, Result);
end;

procedure TCustomViewControl.DoDrawItem(Item: TCustomViewItem; Canvas: TCanvas;
  const Rect: TRect; State: TOwnerDrawState);
begin
  { Implemented by descendants }
end;

procedure TCustomViewControl.BeginAutoDrag;
begin
  BeginDrag(False, Mouse.DragThreshold);
end;

procedure TCustomViewControl.BranchPaintHook(p: QPainterH;
  item: QListViewItemH; w, y, h: Integer; style: GUIStyle;
  var stage: Integer);
var
  Canvas: TCanvas;
  State: TCustomDrawState;
  ListItem: TCustomViewItem;
  R: TRect;
begin
  if not IsCustomDrawn then
  begin
    stage := DrawStage_DefaultDraw;
    Exit;
  end;

  try
    State := [];
    ListItem := TCustomViewItem(FindObject(QObjectH(item)));
    if not Assigned(ListItem) then
      Exit;
    if ListItem.Selected then
      Include(State, cdsSelected);
    if not ListItem.Selectable then
      Include(State, cdsDisabled);

    R := Rect(0, 0, w - 1, h - 1);
    Canvas := TCanvas.Create;
    Canvas.Handle := p;
    Canvas.Start(False);

    if DoCustomDrawViewBranch(ListItem, Canvas, R, State, TCustomDrawStage(stage)) then
      stage := DrawStage_DefaultDraw;

    Canvas.Stop;
    Canvas.ReleaseHandle;
    Canvas.Free;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomViewControl.ItemPaintHook(p: QPainterH;
  item: QListViewItemH; column, width, alignment: Integer;
  var stage: Integer);

  function CDSStateToODState(cds: TCustomDrawState): TOwnerDrawState;
  begin
    Result := [];
    if cdsSelected in cds then Include(Result, odSelected);
    if cdsGrayed in cds then Include(Result, odGrayed);
    if cdsDisabled in cds then Include(Result, odDisabled);
    if cdsChecked in cds then Include(Result, odChecked);
    if cdsFocused in cds then Include(Result, odFocused);
    if cdsDefault in cds then Include(Result, odDefault);
  end;

var
  Canvas: TCanvas;
  State: TCustomDrawState;
  ListItem: TCustomViewItem;
  R: TRect;
  I: Integer;
begin
  ListItem := TCustomViewItem(FindObject(QObjectH(item)));
  if not Assigned(ListItem) then
    Exit;
  DoGetImageIndex(ListItem);
  if not IsCustomDrawn then
  begin
    stage := DrawStage_DefaultDraw;
    Exit;
  end;

  try
    State := [];
    if ListItem.Selected then
      Include(State, cdsSelected);
    if not ListItem.Selectable then
      Include(State, cdsDisabled);

    Canvas := TCanvas.Create;
    Canvas.Handle := p;
    Canvas.Start(False);
    if cdsSelected in State then
    begin
      Canvas.Brush.Color := clHighlight;
      Canvas.Font.Color := clHighlightText;
    end
    else begin
      Canvas.Brush.Color := Color;
      Canvas.Font.Color := Font.Color;
    end;

    R := Rect(0, 0, width, ListItem.Height);

    if IsOwnerDrawn then
    begin
      for I := 1 to Columns.Count - 1 do
        Inc(R.Right, Columns[I].Width);
      DoDrawItem(ListItem, Canvas, R, CDSStateToODState(State));
    end
    else begin
      if column = 0 then
      begin
        if DoCustomDrawViewItem(ListItem, Canvas, R, State, TCustomDrawStage(stage)) then
          stage := DrawStage_DefaultDraw;
      end
      else if column < Columns.Count then
      begin
        I := 0;
        while I < column do
        begin
          R.Left := R.Left + Columns[I].Width;
          Inc(I);
        end;
        R.Right := R.Left + Columns[I].Width;
        QPainter_translate(p, -R.Left, 0);
        try
          if DoCustomDrawViewSubItem(ListItem, column, Canvas, R, State,
          TCustomDrawStage(stage)) then
            stage := DrawStage_DefaultDraw;
        finally
          QPainter_translate(p, R.Left, 0);
        end;
      end;
    end;
    Canvas.Stop;
    Canvas.ReleaseHandle;
    Canvas.Free;
  except
    Application.HandleException(Self);
  end;
end;

function TCustomViewControl.GetColumnClick: Boolean;
begin
  Result := FHeader.Clickable;
end;

function TCustomViewControl.GetColumnMove: Boolean;
begin
  Result := FHeader.DragReorder;
end;

function TCustomViewControl.GetColumnResize: Boolean;
begin
  Result := FHeader.Resizable;
end;

function TCustomViewControl.GetColumns: TListColumns;
begin
  Result := TListViewHeader(FHeader).GetSections;
end;

procedure TCustomViewControl.SetColumnClick(const Value: Boolean);
begin
  if ColumnClick <> Value then
    FHeader.Clickable := Value;
end;

procedure TCustomViewControl.SetShowColumnHeaders(const Value: Boolean);
begin
  if FShowColumnHeaders <> Value then
  begin
    FShowColumnHeaders := Value;
    if HandleAllocated then
      TListViewHeader(FHeader).Hidden := not FShowColumnHeaders;
  end;
end;

procedure TCustomViewControl.SetColumnMove(const Value: Boolean);
begin
  if ColumnMove <> Value then
    FHeader.DragReorder := Value;
end;

procedure TCustomViewControl.SetColumnResize(const Value: Boolean);
begin
  if ColumnResize <> Value then
    FHeader.Resizable := Value;
end;

procedure TCustomViewControl.SetColumns(const Value: TListColumns);
begin
  FHeader.SetSections(Value);
end;

procedure TCustomViewControl.SetShowColumnSortIndicators(const Value: Boolean);
begin
  if FShowColumnSortIndicators <> Value then
  begin
    FShowColumnSortIndicators := Value;
    Sorted := FShowColumnSortIndicators;
    if ShowColumnHeaders and HandleAllocated then
      QListView_setShowSortIndicator(Handle, FShowColumnSortIndicators);
  end;
end;

procedure TCustomViewControl.RepopulateItems;
begin
  { stubbed for children }
end;

procedure TCustomViewControl.UpdateControl;
begin
  if HandleAllocated then
  begin
    QWidget_update(FHeader.Handle);
    QListView_triggerUpdate(Handle);
  end;
end;

function TCustomViewControl.DoCustomDrawViewBranch(Item: TCustomViewItem;
  Canvas: TCanvas; const Rect: TRect; State: TCustomDrawState;
  Stage: TCustomDrawStage): Boolean;
begin
  Result := True;
  if Assigned(FOnCustomDrawBranch) then FOnCustomDrawBranch(Self, Item,
    Canvas, Rect, State, Stage, Result);
end;

procedure TCustomViewControl.ViewportDestroyed;
begin
  try
    CheckRemoveEditor;
  except
    Application.HandleException(Self);
  end;
end;

function TCustomViewControl.ViewportHandle: QWidgetH;
begin
  HandleNeeded;
  Result := FViewportHandle;
end;

function TCustomViewControl.GetChildHandle: QWidgetH;
begin
  Result := ViewportHandle;
end;

procedure TCustomViewControl.WidgetDestroyed;
begin
  CheckRemoveEditor;
  QClxObjectMap_remove(FViewportHandle);
  FViewportHandle := nil;
  if Assigned(FViewportHooks) then
  begin
    QWidget_hook_destroy(FViewportHooks);
    FViewportHooks := nil;
  end;
  QClxObjectMap_remove(FVScrollHandle);
  FVScrollHandle := nil;
  if Assigned(FVScrollHooks) then
  begin
    QScrollBar_hook_destroy(FVScrollHooks);
    FVScrollHooks := nil;
  end;
  QClxObjectMap_remove(FHScrollHandle);
  FHScrollHandle := nil;
  if Assigned(FHScrollHandle) then
  begin
    QScrollBar_hook_destroy(FHScrollHooks);
    FHScrollHooks := nil;
  end;
  inherited WidgetDestroyed;
end;

procedure TCustomViewControl.Sort(Column: Integer; Direction: TSortDirection);
begin
  SortColumn := Column;
  SortDirection := Direction;
  Sorted := True;
end;

procedure TCustomViewControl.SetSorted(const Value: Boolean);
begin
  FSorted := Value;
  if HandleAllocated then
  begin
    if FSorted then
      QListView_setSorting(Handle, SortColumn, cSortDirection[SortDirection])
    else
      QListView_setSorting(Handle, -1, cSortDirection[SortDirection]);
  end;
end;

{ TItemEditor }

constructor TItemEditor.Create(AOwner: TComponent);
begin
  inherited Create(nil);
  if AOwner is TCustomViewControl then
    FViewControl := TCustomViewControl(AOwner);
  InitItem;
end;

destructor TItemEditor.Destroy;
begin
  if Assigned(FViewControl) then
    FViewControl.FEditor := nil;
  inherited Destroy;
end;

procedure TItemEditor.CreateWidget;
begin
  FFrame := QFrame_create(FViewControl.ViewportHandle, nil, 0, True);
  FFrameHooks := QFrame_hook_Create(FFrame);
  QFrame_setFrameStyle(FFrame,
    Integer(QFrameShape_Box) or Integer(QFrameShadow_Plain));
  QWidget_setBackgroundMode(FFrame, QWidgetBackgroundMode_PaletteBase);
  FHandle := QClxLineEdit_create(FFrame, nil);
  Hooks := QLineEdit_hook_create(Handle);
end;

procedure TItemEditor.FrameDestroyedHook;
begin
  try
    FFrame := nil;
    QFrame_hook_destroy(FFrameHooks);
    FFrameHooks := nil;
  except
    Application.HandleException(Self);
  end;
end;

procedure TItemEditor.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  QObject_destroyed_event(Method) := FrameDestroyedHook;
  QObject_hook_hook_destroyed(FFrameHooks, Method);
end;

procedure TItemEditor.InitItem;
var
  Obj: TObject;
begin
  if FViewControl is TCustomViewControl then
  begin
    Obj := TObject(QClxObjectMap_find(QListView_currentItem(FViewControl.Handle)));
    if Obj is TCustomViewItem then
      FItem := TCustomViewItem(Obj);
  end;
end;

procedure TItemEditor.KeyDown(var Key: Word; Shift: TShiftState);
begin
  FViewControl.KeyDown(Key, Shift);  
end;

procedure TItemEditor.KeyUp(var Key: Word; Shift: TShiftState);
begin
  FViewControl.KeyUp(Key, Shift);
end;

procedure TItemEditor.KeyPress(var Key: Char);
begin
  FViewControl.KeyPress(Key);
end;

procedure TItemEditor.KeyString(var S: WideString; var Handled: Boolean);
begin
  FViewControl.KeyString(S, Handled);
end;

function TItemEditor.PopupMenuFilter(Sender: QObjectH; Event: QEventH): Boolean;
var
  FocusedWidget: QWidgetH;
begin
  try
    case QEvent_type(Event) of
      QEventType_MouseButtonPress:
      begin
        FocusedWidget := QApplication_focusWidget(Application.Handle);
        if not ((FocusedWidget = Handle) or
        (FocusedWidget = FPopup)) then
          FShouldClose := True;
      end;
      QEventType_Destroy:
        ClearMenuHook;
    end;
  except
    Application.HandleException(Self);
  end;
  Result := False;
end;

procedure TItemEditor.ClearMenuHook;
begin
  if Assigned(FMenuHook) then
  begin
    QPopupMenu_hook_destroy(FMenuHook);
    FPopup := nil;
    FMenuHook := nil;
  end;
end;

function TItemEditor.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
var
  Obj: QObjectH;
  Method: TMethod;
begin
  if FEditing then
  begin
    if FShouldClose then
      EditFinished(True);
    case QEvent_type(Event) of
      QEventType_ChildRemoved:
      begin
        Result := False;
        Obj := QChildEvent_child(QChildEventH(Event));
        if FPopup = Obj then
          ClearMenuHook;
        Exit;
      end;
      QEventType_ChildInserted:
      begin
        Result := False;
        Obj := QChildEvent_child(QChildEventH(Event));
        if QObject_isA(Obj, 'QPopupMenu') then
        begin
          FPopup := QPopupMenuH(Obj);
          FMenuHook := QPopupMenu_hook_create(Obj);
          TEventFilterMethod(Method) := PopupMenuFilter;
          Qt_hook_hook_events(FMenuHook, Method);
        end;
        Exit;
      end;
      QEventType_FocusOut:
        if QFocusEvent_reason <> QFocusEventReason_Popup then
          EditFinished(True);
      QEventType_KeyPress:
      begin
        case QKeyEvent_key(QKeyEventH(Event)) of
          Key_Up,
          Key_Down:
          begin
            Result := True;
            Exit;
          end;
          Key_Escape: EditFinished(False);
          Key_Return,
          Key_Enter: EditFinished(True);
        end;
      end;
    end;
  end;
  Result := inherited EventFilter(Sender, Event);
end;

procedure TItemEditor.Execute;
var
  Pt: TPoint;
  Offset: Integer;
  ListItem: QListViewItemH;
  ListHandle: QListViewH;
  Allow: Boolean;
  Pixmap: QPixmapH;
  PixmapWidth: Integer;
begin
  if not Assigned(FItem) then
    EditFinished(False);
  FEditing := True;
  Allow := True;
  FViewControl.DoEditing(FItem, Allow);
  if not Allow then
  begin
    EditFinished(False);
    Exit;
  end;
  HandleNeeded;
  ListHandle := FViewControl.Handle;
  ListItem := FItem.Handle;
  Pt := FItem.DisplayRect.BottomRight;
  if (Pt.X = -1) and (Pt.Y = -1) then
    FItem.MakeVisible(False);
  Offset := 0;
  PixmapWidth := 0;
  Pixmap := QListViewItem_pixmap(ListItem, 0);
  if Assigned(Pixmap) then
    PixmapWidth := QPixmap_width(Pixmap);
  while Assigned(ListItem) do
  begin
    ListItem := QListViewItem_parent(ListItem);
    Inc(Offset);
  end;
  Pt.X := Offset * QListView_treeStepSize(ListHandle);
  if not QListView_rootIsDecorated(ListHandle) then
    Dec(Pt.X, QListView_treeStepSize(ListHandle));
  Inc(Pt.X, PixmapWidth);
  Pt.Y := QListViewItem_itemPos(FItem.Handle);
  QScrollView_contentsToViewport(ListHandle, @Pt, @Pt);
  Left := QFrame_frameWidth(FFrame);
  Top := QFrame_frameWidth(FFrame);
  Width := QListView_columnWidth(ListHandle, 0);
  QWidget_setGeometry(FFrame, Pt.X, Pt.Y,
    (QListView_columnWidth(ListHandle, 0) - Pt.X),
    QListViewItem_height(FItem.Handle));
  Width := (QListView_columnWidth(ListHandle, 0) - Pt.X) -
           (QFrame_frameWidth(FFrame) * 2);
  BorderStyle := bsNone;
  Text := FItem.Caption;
  SelectAll;
  QWidget_show(FFrame);
  QWidget_setFixedHeight(Handle, QListViewItem_height(FItem.Handle) -
    (QFrame_frameWidth(FFrame) * 2));
  QWidget_show(Handle);
  SetFocus;
end;

procedure TItemEditor.EditFinished(Accepted: Boolean);
var
  S: WideString;
begin
  if Assigned(FFrame) and Visible then
  begin
    if FEditing then
    begin
      FEditing := False;
      ClearMenuHook;
      if Assigned(FViewControl) and not (csDestroying in FViewControl.ComponentState) then
        if Accepted and (Text <> FItem.Caption) then
        begin
          S := Text;
          FViewControl.DoEdited(FItem, S);
          FItem.Caption := S;
        end;
      Visible := False;
      if Assigned(FFrame) then
        QApplication_postEvent(Application.Handle,
          QCustomEvent_create(QEventType_CMDestroyWidget, FFrame));
      if Assigned(FViewControl) and not (csDestroying in FViewControl.ComponentState) then
        FViewControl.SetFocus;
    end;
  end;
end;

{ TCustomViewItem }

constructor TCustomViewItem.Create(AOwner: TCustomViewItems; AParent, After: TCustomViewItem);
begin
  inherited Create;
  FOwner := AOwner;
  FParent := AParent;
  FPrevItem := After;
  if Assigned(FPrevItem) then
    FPrevItem.FNextItem := Self;
  FImageIndex := -1;
  FSelectable := True;
  FExpandable := False;

  if Assigned(Owner) then
  begin
    DetermineCreationType;
    CreateWidget(AParent, After);
  end;
end;

destructor TCustomViewItem.Destroy;
var
  Child: TCustomViewItem;
begin
  FDestroying := True;
  if ViewControlValid and not (csDestroying in Owner.Owner.ComponentState) then
  begin
    Owner.BeginUpdate;
    try
      if HandleAllocated then
        while QListViewItem_childCount(Handle) > 0 do
        begin
          Child := Owner.FindViewItem(QListViewItem_firstChild(Handle));
          if Child is TCustomViewItem then
            Child.Free;
        end;
      if not Assigned(Parent) or (Assigned(Parent) and not Parent.FDestroying) then
      begin
        if Selected then
        begin
          Selected := False;
          if Assigned(FNextItem) then
            FNextItem.Selected := True
          else if Assigned(FPrevItem) then
            FPrevItem.Selected := True
          else if Assigned(Parent) then
            Parent.Selected := True;
        end;
      end;
    finally
      Owner.EndUpdate;
    end;
  end;
  Parent := nil;
  if Assigned(FNextItem) then
    FNextItem.FPrevItem := FPrevItem;
  if Assigned(FPrevItem) then
    FPrevItem.FNextItem := FNextItem;
  if Assigned(Owner) then
    Owner.FItems.Extract(Self);
  if Assigned(FSubItems) then
    FSubItems.Free;
  if HandleAllocated then
    DestroyWidget;
  inherited Destroy;
end;

procedure TCustomViewItem.AssignTo(Dest: TPersistent);
begin
  if Dest is TCustomViewItem then
  begin
    TCustomViewItem(Dest).Selected := Selected;
    TCustomViewItem(Dest).Selectable := Selectable;
    TCustomViewItem(Dest).Expanded := Expanded;
    TCustomViewItem(Dest).Expandable := Expandable;
    TCustomViewItem(Dest).Caption := Caption;
    TCustomViewItem(Dest).Checked := Checked;
    TCustomViewItem(Dest).Data := Data;
    TCustomViewItem(Dest).Focused := Focused;
    TCustomViewItem(Dest).ImageIndex := ImageIndex;
    TCustomViewItem(Dest).ItemType := ItemType;
    TCustomViewItem(Dest).SubItems.Assign(SubItems);
  end             
  else
    inherited AssignTo(Dest);
end;

procedure TCustomViewItem.Collapse;
begin
  Expanded := False;
end;

procedure TCustomViewItem.CreateWidget(AParent, After: TCustomViewItem);
const
  cType: array [TListViewItemType] of QCheckListItemType = (QCheckListItemtype_CheckBox,
    QCheckListItemtype_CheckBox, QCheckListItemtype_RadioButton, QCheckListItemtype_Controller);
var
  ParentH: QListViewItemH;
  AfterH: QListViewItemH;
  ParentListViewH: QListViewH;
begin
  ParentH := nil;
  AfterH := nil;
  ParentListViewH := nil;
  FHandle := nil;

  if Assigned(AParent) then
    ParentH := AParent.Handle
  else
    if ViewControlValid then
      ParentListViewH := ViewControl.Handle
    else
      ParentListViewH := nil;

  if Assigned(After) then
    AfterH := After.Handle;
  case FItemType of
    itDefault:
    begin
      if Assigned(ParentListViewH) then
        FHandle := QClxListViewItem_create(ParentListViewH, AfterH, ItemHook)
      else
        FHandle := QClxListViewItem_create(ParentH, AfterH, ItemHook);
    end;
    else
    begin
      if Assigned(ParentListViewH) then
        FHandle := QClxCheckListItem_create(ParentListViewH,
          PWideString(@FText), cType[FItemType], ItemHook)
      else
        FHandle := QClxCheckListItem_create(ParentH, PWideString(@FText),
          cType[FItemType], ItemHook);
      if Assigned(AfterH) then
        QListViewItem_moveItem(FHandle, AfterH);
    end;
  end;
  QClxObjectMap_add(FHandle, Integer(Self));
end;

procedure TCustomViewItem.Delete;
begin
  Free;
end;

procedure TCustomViewItem.DestroyWidget;
begin
  if HandleAllocated then
  begin
    Selected := False;
    if Assigned(FNextItem) then
      FNextItem.Selected := True
    else if Assigned(FPrevItem) then
      FPrevItem.Selected := True
    else if Assigned(Parent) then
      Parent.Selected := True;
    QClxObjectMap_remove(FHandle);
    if Assigned(Owner) and ViewControlValid then
      QListViewItem_destroy(FHandle);
  end;
  FHandle := nil;
end;

procedure TCustomViewItem.DetermineCreationType;
begin
  if Assigned(Owner) and (Owner.Owner is TCustomListView) then
    if TCustomListView(Owner.Owner).CheckBoxes then
      FItemType := itCheckBox;
end;

procedure TCustomViewItem.Expand;
begin
  Expanded := True;
end;

function TCustomViewItem.GetChildCount: Integer;
begin
  if ViewControlValid and HandleAllocated then
    Result := QListViewItem_childCount(Handle)
  else
    Result := -1;
end;

function TCustomViewItem.GetFocused: Boolean;
begin
  if ViewControlValid and HandleAllocated then
    Result := QListView_currentItem(Owner.Owner.Handle) = Handle
  else
    Result := False;
end;

function TCustomViewItem.GetHeight: Integer;
begin
  if ViewControlValid and HandleAllocated then
    Result := QListViewItem_height(Handle)
  else
    Result := -1;
end;

function TCustomViewItem.GetSubItemImages(Column: Integer): Integer;
begin
  if (Column >= 0) and (Column < SubItems.Count) then
    Result := Integer(SubItems.Objects[Column])
  else
    Result := -1;
end;

function TCustomViewItem.GetExpanded: Boolean;
begin
  if HandleAllocated then
    Result := QListViewItem_isOpen(Handle)
  else
    Result := False;
end;

function TCustomViewItem.GetHandle: QListViewItemH;
begin
  if not HandleAllocated and not FDestroying then
    CreateWidget(FParent, FPrevItem);
  Result := FHandle;
end;

function TCustomViewItem.GetSubItems: TStrings;
begin
  if not Assigned(FSubItems) then
    FSubItems := TSubItems.Create(Self);
  Result := FSubItems;
end;

function TCustomViewItem.GetTotalHeight: Integer;
begin
  if ViewControlValid and HandleAllocated then
    Result := QListViewItem_totalHeight(Handle)
  else
    Result := -1;
end;

function TCustomViewItem.GetIndex: Integer;
begin
  if Assigned(Owner) then
    Result := Owner.FItems.IndexOf(Self)
  else
    Result := -1;
end;

function TCustomViewItem.GetSelected: Boolean;
begin
  if HandleAllocated then
    Result := QListViewItem_isSelected(Handle)
  else
    Result := False;
end;

function TCustomViewItem.HandleAllocated: Boolean;
begin
  Result := FHandle <> nil;
end;

procedure TCustomViewItem.ImageIndexChange(ColIndex, NewIndex: Integer);
var
  Pixmap: QPixmapH;
begin
  if ViewControlValid and HandleAllocated and Assigned(ViewControl.Images) then
  begin
    Pixmap := ViewControl.Images.GetPixmap(NewIndex);
    if Assigned(Pixmap) then
      QListViewItem_setPixmap(Handle, ColIndex, Pixmap)
    else
    begin
      Pixmap := QPixmap_create;
      try
        QListViewItem_setPixmap(Handle, ColIndex, Pixmap);
      finally
        QPixmap_destroy(Pixmap);
      end;
    end;
  end;
end;

procedure TCustomViewItem.InsertItem(AItem: TCustomViewItem);
begin
  if Assigned(AItem) then
  begin
    AItem.FParent := Self;
    AItem.FPrevItem := FLastChild;
    AItem.FNextItem := nil;
    if HandleAllocated and AItem.HandleAllocated then
      QListViewItem_insertItem(Handle, AItem.Handle);
    if Assigned(FLastChild) then
    begin
      FLastChild.FNextItem := AItem;
      if HandleAllocated then
        QListViewItem_moveItem(AItem.Handle, FLastChild.Handle);
    end;
    FLastChild := AItem;
  end;
end;

function TCustomViewItem.ParentCount: Integer;
var
  Temp: QListViewItemH;
begin
  Result := 0;
  if ViewControlValid and HandleAllocated then
  begin
    Temp := QListViewItem_parent(Handle);
    while Assigned(Temp) do
    begin
      Inc(Result);
      Temp := QListViewItem_parent(Temp);
    end;
  end;
end;

procedure TCustomViewItem.ReCreateItem;
begin
  FDestroying := True;
  try
    DestroyWidget;
    CreateWidget(FParent, FPrevItem);
    ResetFields;
  finally
    FDestroying := False;
  end;
end;

procedure TCustomViewItem.RemoveItem(AItem: TCustomViewItem);
begin
  if Assigned(AItem) then
  begin
    if FLastChild = AItem then
      FLastChild := AItem.FPrevItem;
    if HandleAllocated then
    begin
      if AItem.HandleAllocated then
        QListViewItem_takeItem(Handle, AItem.Handle);
      if HandleAllocated and (QListViewItem_childCount(Handle) = 0) then
        Expandable := False;
    end;
    AItem.FParent := nil;
  end;
end;

procedure TCustomViewItem.Repaint;
begin
  if HandleAllocated then
    QListViewItem_repaint(Handle);
end;

procedure TCustomViewItem.ResetFields;
var
  I: Integer;
  Temp: WideString;
begin
  if HandleAllocated then
  begin
    if ViewControlValid then
    begin
      QListViewItem_setText(Handle, 0, PWideString(@FText));
      if ItemType <> itDefault then
        QCheckListItem_setOn(QCheckListItemH(FHandle), FChecked);
      QListViewItem_setExpandable(Handle, FExpandable);
      QListViewItem_setSelectable(Handle, FSelectable);
    end;
    if Assigned(FSubItems) then
      for I := 0 to SubItems.Count-1 do
      begin
        Temp := SubItems[I];
        QListViewItem_setText(Handle, I + 1, PWideString(@Temp));
        ImageIndexChange(I + 1, SubItemImages[I]);
      end;
  end;
end;

procedure TCustomViewItem.SetCaption(const Value: WideString);
begin
  if Caption <> Value then
  begin
    if HandleAllocated then
    begin
      if Assigned(Owner) then
        QListViewItem_setText(Handle, 0, PWideString(@Value));
      QListViewItem_text(Handle, PWideString(@FText), 0);
    end
    else
      FText := Value;
  end;
end;

procedure TCustomViewItem.SetChecked(const Value: Boolean);
begin
  if Checked <> Value then
  begin
    if ViewControlValid and HandleAllocated and (ItemType <> itDefault) then
      QCheckListItem_setOn(QCheckListItemH(Handle), Value);
    FChecked := Value;
  end;
end;

procedure TCustomViewItem.SetSubItemImages(Column: Integer;
  const Value: Integer);
begin
  if (Column >= 0) and (Column < SubItems.Count) then
    SubItems.Objects[Column] := Pointer(Value);
end;

procedure TCustomViewItem.SetExpandable(const Value: Boolean);
begin
  if Expandable <> Value then
  begin
    FExpandable := Value;
    if ViewControlValid and HandleAllocated then
      QListViewItem_setExpandable(Handle, FExpandable);
  end;
end;

procedure TCustomViewItem.SetExpanded(const Value: Boolean);
var
  AItem: QListViewItemH;
  ARect: TRect;
begin
  if (Expanded <> Value) and HandleAllocated then
  begin
    QListViewItem_setOpen(Handle, Value);
    if not Expanded and ViewControlValid then
    begin
      AItem := QListView_currentItem(ViewControl.Handle);
      while Assigned(AItem) do
      begin
        if (AItem = Handle) then
          Break;
        AItem := QListViewItem_parent(AItem);
      end;

      if Assigned(AItem) then
      begin
        repeat
          QListView_itemRect(ViewControl.Handle, @ARect, AItem);
          if QListViewItem_isOpen(AItem) or
          ((ARect.Right >= 0) and (ARect.Bottom >= 0)) then
          begin
            QListView_setCurrentItem(ViewControl.Handle, AItem);
            Exit;
          end;
          AItem := QListViewItem_parent(AItem);
        until not Assigned(AItem);
      end;
    end;
  end;
end;

procedure TCustomViewItem.SetFocused(const Value: Boolean);
begin
  if ViewControlValid and HandleAllocated and (Value <> GetFocused) then
    QListView_setCurrentItem(ViewControl.Handle, Handle);
end;

procedure TCustomViewItem.SetImageIndex(const Value: TImageIndex);
begin
  if FImageIndex <> Value then
  begin
    FImageIndex := Value;
    ImageIndexChange(0, FImageIndex);
  end;
end;

procedure TCustomViewItem.SetItemType(const Value: TListViewItemType);
var
  ChildrenArray: array of QListViewItemH;
  Temp: QListViewItemH;
  I: Integer;
begin
  if FItemType <> Value then
  begin
    if (Value = itRadioButton) then
      if (not Assigned(FParent)) or (FParent.ItemType <> itController) then
         raise EListViewException.Create(sListRadioItemBadParent);
    if HandleAllocated then
    begin
      if ViewControlValid then
      begin
        SetLength(ChildrenArray, QListViewItem_childCount(Handle));

        if Length(ChildrenArray) > 0 then
        begin
          I := 0;
          while True do
          begin
            Temp := QListViewItem_firstChild(Handle);
            if not Assigned(Temp) then
              Break;
            QListViewItem_takeItem(Handle, Temp);
            ChildrenArray[I] := Temp;
            Inc(I);
          end;
        end;
      end;
      FItemType := Value;
      ReCreateItem;
      if ViewControlValid and (Length(ChildrenArray) > 0) then
      begin
        I := 0;
        while (I < Length(ChildrenArray)) and (Assigned(ChildrenArray[I])) do
        begin
          QListViewItem_insertItem(Handle, ChildrenArray[I]);
          Inc(I);
        end;
      end;
    end;
  end;
end;

procedure TCustomViewItem.SetParent(const Value: TCustomViewItem);
begin
  if Assigned(FPrevItem) then
    FPrevItem.FNextItem := FNextItem;
  if Assigned(FNextItem) then
    FNextItem.FPrevItem := FPrevItem;
  if Assigned(FParent) then
    FParent.RemoveItem(Self);
  FPrevItem := nil;
  FNextItem := nil;
  FParent := Value;
  if Assigned(FParent) then
    FParent.InsertItem(Self);
end;

procedure TCustomViewItem.SetSelectable(const Value: Boolean);
begin
  if Selectable <> Value then
  begin
    FSelectable := Value;
    if ViewControlValid and HandleAllocated then
      QListViewItem_setSelectable(Handle, FSelectable);
  end;
end;

procedure TCustomViewItem.SetSelected(const Value: Boolean);
begin
  if (Selected <> Value) and HandleAllocated then
  begin
    if ViewControlValid then
      QListView_setSelected(ViewControl.Handle, Handle, Value)
    else
      QListViewItem_setSelected(Handle, Value);
    if Value and ViewControlValid and ViewControl.Visible then
      MakeVisible(False);
  end;
end;

function TCustomViewItem.ViewControl: TCustomViewControl;
begin
  Result := nil;
  if ViewControlValid then
    Result := Owner.Owner; 
end;

function TCustomViewItem.ViewControlValid: Boolean;
begin
  Result := Assigned(FOwner) and Assigned(FOwner.FOwner) and
    not (csRecreating in FOwner.FOwner.ControlState);
end;

function TCustomViewItem.ItemHook: QClxListViewHooksH;
begin
  Result := nil;
  if ViewControlValid then
    Result := ViewControl.FItemHooks;
end;

function TCustomViewItem.DisplayRect: TRect;
begin
  if ViewControlValid and HandleAllocated then
    QListView_itemRect(ViewControl.Handle, @Result, Handle)
  else
    Result := Rect(0, 0, -1, -1);
end;

function TCustomViewItem.GetWidth: Integer;
var
  R: TRect;
begin
  R := DisplayRect;
  Result := R.Right - R.Left;
end;

procedure TCustomViewItem.SetSubItems(const Value: TStrings);
begin
  if SubItems <> Value then
    SubItems.Assign(Value);
end;

procedure TCustomViewItem.UpdateImages;
var
  I: Integer;
  ImgList: TCustomImageList;
  EmptyPix: QPixmapH;
  Pixmap: QPixmapH;
begin
  if HandleAllocated then
  begin
    ImgList := ViewControl.Images;
    EmptyPix := QPixmap_create;
    try
      if Assigned(ImgList) then
      begin
        Pixmap := ImgList.GetPixmap(ImageIndex);
        if not Assigned(Pixmap) then
          Pixmap := EmptyPix;
        QListViewItem_setPixmap(Handle, 0, Pixmap);
        for I := 0 to SubItems.Count-1 do
        begin
          Pixmap := ImgList.GetPixmap(SubItemImages[I]); 
          if not Assigned(Pixmap) then
            Pixmap := EmptyPix;
          QListViewItem_setPixmap(Handle, I+1, Pixmap);
        end;
      end
      else
      begin
        QListViewItem_setPixmap(Handle, 0, EmptyPix);
        for I := 0 to SubItems.Count-1 do
          QListViewItem_setPixmap(Handle, I+1, EmptyPix);
      end;
    finally
      if Assigned(EmptyPix) then
        QPixmap_destroy(EmptyPix);
    end;
  end;
end;

procedure TCustomViewItem.MakeVisible(PartialOK: Boolean);
var
  ARect: TRect;
begin
  if ViewControlValid and HandleAllocated then
  begin
    if PartialOK then
    begin
      ARect := DisplayRect;
      if (ARect.Left <> -1) and (ARect.Top <> -1) and
      (ARect.Right <> -1) and (ARect.Bottom <> -1) then
        Exit;  
    end;
    QListView_ensureItemVisible(ViewControl.Handle, Handle);
  end;
end;

{ TCustomViewItems }

procedure TCustomViewItems.Clear;
begin
  BeginUpdate;
  try
    FItems.Clear;
    if Owner.HandleAllocated then
      QListView_clear(Owner.Handle);
  finally
    EndUpdate;
  end;
end;

constructor TCustomViewItems.Create(AOwner: TCustomViewControl);
begin
  inherited Create;
  FOwner := AOwner;
  FItems := TViewItemsList.Create;
end;

destructor TCustomViewItems.Destroy;
begin
  try
    BeginUpdate;
    FItems.Free;
  finally
    EndUpdate;
  end;
  inherited Destroy;
end;

function TCustomViewItems.GetHandle: QListViewH;
begin
  if Owner <> nil then
    Result := Owner.Handle
  else
    Result := nil;
end;

function TCustomViewItems.GetItem(Index: Integer): TCustomViewItem;
begin
  Result := FItems[Index];
end;

procedure TCustomViewItems.ChangeItemTypes(NewType: TListViewItemType);
var
  I: Integer;
begin
  BeginUpdate;
  try
    for I := 0 to Count-1 do
      Item[I].ItemType := NewType;
  finally                
    EndUpdate;
  end;
end;

function TCustomViewItems.IndexOf(Value: TCustomViewItem): Integer;
begin
  Result := FItems.IndexOf(Value);
end;

procedure TCustomViewItems.SetItem(Index: Integer; const Value: TCustomViewItem);
begin
  if (Index < Count-1) and (Index >= 0) then
    if Assigned(FItems[Index]) then
      FItems[Index].Assign(Value)
    else
      FItems[Index] := Value;
end;

function TCustomViewItems.GetCount: Integer;
begin
  Result := FItems.Count;
end;

procedure TCustomViewItems.BeginUpdate;
begin
  if FUpdateCount = 0 then
    SetUpdateState(True);
  Inc(FUpdateCount);
end;

procedure TCustomViewItems.EndUpdate;
begin
  Dec(FUpdateCount);
  if FUpdateCount = 0 then
    SetUpdateState(False);
end;

procedure TCustomViewItems.SetUpdateState(Updating: Boolean);
begin
  if not (csDestroying in Owner.ComponentState) and Owner.HandleAllocated then
  begin
    if FUpdateCount = 0 then
    begin
      QWidget_setUpdatesEnabled(Owner.Handle, not Updating);
      QWidget_setUpdatesEnabled(QScrollView_viewport(Owner.Handle), not Updating);
      if not Updating then
        QListView_triggerUpdate(Owner.Handle);
    end;
  end;
end;

{ TCustomListView }

function TCustomListView.IsOwnerDrawn: Boolean;
begin
  Result := FOwnerDraw and (ViewStyle = vsReport) and Assigned(FOnDrawItem);
end;

procedure TCustomListView.ItemChange(item: QListViewItemH; _type: TItemChange);
begin
  if Assigned(FOnChange) then
    FOnChange(Self, FItems.FindItem(item), _type);
end;

procedure TCustomListView.ItemChanging(item: QListViewItemH; _type: TItemChange;
  var Allow: Boolean);
var
  AItem: TListItem;
begin
  AItem := FItems.FindItem(item);
  if Assigned(AItem) and not AItem.FDestroying then
  begin
    if Assigned(FOnChanging) then
      FOnChanging(Self, AItem, _type, Allow);
    if (AItem <> FSelected) and (_type = ctState) then
      StartEditTimer;
  end;
end;

procedure TCustomListView.ItemChecked(item: QListViewItemH; Checked: Boolean);
var
  AItem: TListItem;
begin
  AItem := Items.FindItem(item);
  if Assigned(AItem) then
    AItem.FChecked := Checked;
  StartEditTimer;
end;

procedure TCustomListView.ItemDestroyed(AItem: QListViewItemH);
var
  ListItem: TListItem;
begin
  if QClxObjectMap_find(AItem) <> 0 then
    ListItem := FItems.FindItem(AItem)
  else
    ListItem := nil;
  if Assigned(ListItem) then
  begin
    QClxObjectMap_remove(ListItem.FHandle);
    ListItem.FHandle := nil;
    if not (csDestroying in ComponentState) and (FHeader is TListViewHeader) then
      if (not TListViewHeader(FHeader).FHiddenChanging) and not ListItem.FDestroying then
        ListItem.Free;
  end;
end;

procedure TCustomListView.ItemSelected(item: QListViewItemH; wasSelected: Boolean);
const
  cIncSelCount: array [Boolean] of Integer = (-1, 1);
var
  AItem: TListItem;
begin
  Inc(FSelCount, cIncSelCount[wasSelected]);
  AItem := FItems.FindItem(item);
  if FSelCount > 0 then
    FSelected := AItem
  else
    FSelected := nil;
  if Assigned(FOnSelectItem) then
    FOnSelectItem(Self, AItem, wasSelected);
end;

function TCustomListView.AlphaSort: Boolean;
begin
  Result := True;
  try
    { The 0th column is the one associated with the TListItem }
    if HandleAllocated then
      QListView_setSorting(Handle, 0, SortDirection = sdAscending);
  except
    Result := False;
  end;
end;

procedure TCustomListView.SetTopItem(const AItem: TListItem);
var
  NewTopH: Integer;
begin
  if Assigned(AItem) and HandleAllocated then
  begin
    NewTopH := QListView_itemPos(Handle, AItem.Handle);
    QListView_setContentsPos(Handle, QScrollView_contentsX(Handle), NewTopH);
  end;
end;

function TCustomListView.GetTopItem: TListItem;
begin
  Result := GetItemAt(1, 1);
end;

function TCustomListView.GetDropTarget: TListItem;
var
  Temp: TCustomViewItem;
begin
  Result := nil;
  Temp := FindDropTarget;
  if Temp is TListItem then
    Result := TListItem(Temp);
end;

function TCustomListView.FindData(StartIndex: Integer; Value: Pointer;
  Inclusive, Wrap: Boolean): TListItem;
var
  I: Integer;
  Item: TListItem;
begin
  Result := nil;
  if Inclusive then Dec(StartIndex);
  for I := StartIndex + 1 to Items.Count - 1 do
  begin
    Item := Items[I];
    if (Item <> nil) and (Item.Data = Value) then
    begin
      Result := Item;
      Exit;
    end;
  end;
  if Wrap then
  begin
    if Inclusive then Inc(StartIndex);
    for I := 0 to StartIndex - 1 do
    begin
      Item := Items[I];
      if (Item <> nil) and (Item.Data = Value) then
      begin
        Result := Item;
        Exit;
      end;
    end;
  end;
end;

function TCustomListView.GetItemAt(X, Y: Integer): TListItem;
var
  Temp: QListViewItemH;
  Pt: TPoint;
begin
  Result := nil;
  if HandleAllocated then
  begin
    Pt := Types.Point(X, Y);
    Temp := QListView_itemAt(Handle, @Pt);
    Result := Items.FindItem(Temp);
  end;
end;

function TCustomListView.GetSelected: TListItem;
begin
  Result := FSelected;
end;

procedure TCustomListView.SetSelected(const Value: TListItem);
begin
  if not (csDestroying in ComponentState) then
  begin
    if Assigned(FSelected) and not MultiSelect then
      FSelected.Selected := False;
    if Assigned(Value) then
      Value.Selected := True;
  end;
  FSelected := Value;
end;

procedure TCustomListView.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  QListView_mouseButtonClicked_Event(Method) := DoItemClick;
  QListView_hook_hook_mouseButtonClicked(QListView_hookH(Hooks), Method);
end;

procedure TCustomListView.ImageListChanged;
var
  I: Integer;
begin
  for I := 0 to Items.Count-1 do
    Items[I].UpdateImages;
end;

function TCustomListView.FindCaption(StartIndex: Integer;
  const Value: WideString; Partial, Inclusive, Wrap: Boolean): TListItem;
const
  cInclusive: array [Boolean] of Integer = (1, 0);
var
  I: Integer;
begin
  Result := nil;
  if (StartIndex < 0) or (StartIndex >= Items.Count) then
    Exit;

  if not Partial then
  begin
    for I := StartIndex + cInclusive[Inclusive] to Items.Count-1 do
    begin
      Result := Items[I];
      if WideCompareText(Value, Result.Caption) = 0 then
        Exit;
    end;
    if Wrap then
    for I := 0 to StartIndex - cInclusive[not Inclusive] do
    begin
      Result := Items[I];
      if WideCompareText(Value, Result.Caption) = 0 then
        Exit;
    end;
    Result := nil;
  end
  else
  begin
    for I := StartIndex + cInclusive[Inclusive] to Items.Count-1 do
    begin
      Result := Items[I];
      if Pos(Value, Result.Caption) = 1 then
        Exit;
    end;
    if Wrap then
    for I := 0 to StartIndex - cInclusive[not Inclusive] do
    begin
      Result := Items[I];
      if Pos(Value, Result.Caption) = 1 then
        Exit;
    end;
    Result := nil;
  end;
end;

procedure TCustomListView.Scroll(DX, DY: Integer);
begin
  if HandleAllocated then
    QScrollView_scrollBy(Handle, DX, DY);
end;

function TCustomListView.GetItemFocused: TListItem;
begin
  if HandleAllocated then
    Result := TListItem(QClxObjectMap_find(QListView_currentItem(Handle)))
  else
    Result := nil;
end;

procedure TCustomListView.SetItemFocused(const Value: TListItem);
begin
  if Assigned(Value) and HandleAllocated then
    QListView_setCurrentItem(Handle, Value.Handle);
end;

procedure TCustomListView.InitWidget;
begin
  inherited InitWidget;
  ShowColumnHeaders := FViewStyle = vsReport;
  QListView_setRootIsDecorated(Handle, False);
end;

procedure TCustomListView.SetCheckBoxes(const Value: Boolean);
begin
  if FCheckBoxes <> Value then
  begin
    FCheckBoxes := Value;
    UpdateItemTypes;
  end;
end;

procedure TCustomListView.UpdateItemTypes;
const
  cNewType: array [Boolean] of TListViewItemType = (itDefault, itCheckBox);
begin
  FItems.ChangeItemTypes(cNewType[FCheckBoxes]);
end;

procedure TCustomListView.UpdateItems(FirstIndex, LastIndex: Integer);
var
  I: Integer;
begin
  for I := FirstIndex to LastIndex do
    Items[I].Repaint;
end;

constructor TCustomListView.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Init(TListItem);
end;

constructor TCustomListView.Create(AOwner: TComponent;
  AListItemClass: TListItemClass);
begin
  inherited Create(AOwner);
  Init(AListItemClass);
end;

destructor TCustomListView.Destroy;
begin
  if Assigned(FMemStream) then
    FreeAndNil(FMemStream);
  FItems.Free;
  inherited Destroy;
end;

procedure TCustomListView.Init(AListItemClass: TListItemClass);
begin
  FItems := TListItems.Create(Self, AListItemClass);
  FViewStyle := vsList;
  ColumnClick := True;
  ColumnMove := True;
  ColumnResize := True;
  Palette.ColorRole := crBase;
  Palette.TextColorRole := crText;
end;

procedure TCustomListView.DoGetImageIndex(item: TCustomViewItem);
begin
  if Assigned(FOnGetImageIndex) and (item is TListItem) then
    FonGetImageIndex(Self, TListItem(item));
end;

procedure TCustomListView.DoDrawItem(Item: TCustomViewItem; Canvas: TCanvas;
  const Rect: TRect; State: TOwnerDrawState);
begin
  if Assigned(FOnDrawItem) then
    FOnDrawItem(Self, TListItem(Item), Canvas, Rect, State);
end;

procedure TCustomListView.DoEditing(AItem: TCustomViewItem; var AllowEdit: Boolean);
begin
  if Assigned(FOnEditing) and (AItem is TListItem) then
    FOnEditing(Self, TListItem(AItem), AllowEdit);
end;

procedure TCustomListView.DoEdited(AItem: TCustomViewItem; var S: WideString);
begin
  if Assigned(FOnEdited) and (AItem is TListItem) then
    FOnEdited(Self, TListItem(AItem), S);
end;

procedure TCustomListView.SetItems(const Value: TListItems);
begin
  if FItems <> Value then
    FItems.Assign(Value);
end;

function TCustomListView.GetNearestItem(const Point: TPoint;
  Direction: TSearchDirection): TListItem;
var
  Temp: TListItem;
begin
  Result := nil;
  Temp := GetItemAt(Point.x, Point.y);
  if Assigned(Temp) and Temp.HandleAllocated then
  begin
    case Direction of
      sdAbove: Result := Items.FindItem(QListViewItem_itemAbove(Temp.Handle));
      sdBelow: Result := Items.FindItem(QListViewItem_itemBelow(Temp.Handle));
    end;
  end;
end;

function TCustomListView.GetNextItem(StartItem: TListItem;
  Direction: TSearchDirection; States: TItemStates): TListItem;
var
  AIndex: Integer;
begin
  Result := nil;
  if Assigned(StartItem) and StartItem.HandleAllocated and HandleAllocated then
  begin
    AIndex := StartItem.Index;
    while True do
    begin
      case Direction of
        sdAbove: Result := Items.FindItem(QListViewItem_itemAbove(StartItem.Handle));
        sdBelow: Result := Items.FindItem(QListViewItem_itemBelow(StartItem.Handle));
        sdAll:
        begin
          Inc(AIndex);
          if AIndex = StartItem.Index then
          begin
            Result := nil;
            Exit;
          end;
          if AIndex >= Items.Count then
            AIndex := 0;
          Result := Items[AIndex];
        end;
      end;
      if Result = nil then
        Exit;
      if (Result.States * States <> []) then
        Exit;
      StartItem := Result;
    end;
  end;
end;

procedure TCustomListView.DoItemClick(Button: Integer; ListItem: QListViewItemH;
  Pt: PPoint; ColIndex: Integer);
var
  AItem: TListItem;
begin
  try
    AItem := FItems.FindItem(ListItem);
    if Assigned(AItem) then
    begin
      if Assigned(FOnItemClick) then
        FOnItemClick(Self, ButtonToMouseButton(Button), AItem, Pt^, ColIndex);
      if (ColIndex = 0) and FAllowEdit then
        EditItem;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomListView.SetOnItemDoubleClick(const Value: TLVItemDoubleClickEvent);
var
  Method: TMethod;
begin
  FOnItemDoubleClick := Value;
  if Assigned(FOnItemDoubleClick) then
    QListView_doubleClicked_Event(Method) := DoItemDoubleClick
  else
    Method := NullHook;

  QListView_hook_hook_doubleClicked(QListView_hookH(Hooks), Method);
end;

procedure TCustomListView.DoItemDoubleClick(ListItem: QListViewItemH);
var
  AItem: TListItem;
begin
  if Assigned(FOnItemDoubleClick) then
  try
    AItem := FItems.FindItem(ListItem);
    FOnItemDoubleClick(Self, AItem);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomListView.SetOnItemEnter(const Value: TLVNotifyEvent);
var
  Method: TMethod;
begin
  FOnItemEnter := Value;
  if Assigned(FOnItemEnter) then
    QListView_onItem_Event(Method) := DoOnItemEnter
  else
    Method := NullHook;

  QListView_hook_hook_onItem(QListView_hookH(Hooks), Method);
end;

procedure TCustomListView.SetOnItemExitViewportEnter(const Value: TLVItemExitViewportEnterEvent);
var
  Method: TMethod;
begin
  FOnItemExitViewportEnter := Value;
  if Assigned(FOnItemExitViewportEnter) then
    QListView_onViewport_Event(Method) := DoOnItemExitViewportEnter
  else
    Method := NullHook;

  QListView_hook_hook_onViewport(QListView_hookH(Hooks), Method);
end;

procedure TCustomListView.DoOnItemEnter(ListItem: QListViewItemH);
var
  AItem: TListItem;
begin
  if Assigned(FOnItemEnter) then
  try
    AItem := FItems.FindItem(ListItem);
    FOnItemEnter(Self, AItem);
  except 
    Application.HandleException(Self);
  end;
end;

procedure TCustomListView.DoOnItemExitViewportEnter;
begin
  if Assigned(FOnItemExitViewportEnter) then
  try
    FOnItemExitViewportEnter(Self);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomListView.SetOnMouseDown(const Value: TLVButtonDownEvent);
begin
  FOnMouseDown := Value;
  HookMouseDowns;
end;

procedure TCustomListView.DoLVMouseDown(Button: Integer; ListItem: QListViewItemH; Pt: PPoint; ColIndex: Integer);
var
  AItem: TListItem;
begin
  try
    AItem := FItems.FindItem(ListItem);
    if Assigned(FOnMouseDown) and Assigned(AItem) then
      FOnMouseDown(Self, ButtonToMouseButton(Button), AItem, Pt^, ColIndex)
    else if Assigned(FOnViewportMouseDown) and not Assigned(AItem) then
      FOnViewportMouseDown(Self, ButtonToMouseButton(Button), Pt^);
  except 
    Application.HandleException(Self);
  end;
end;

procedure TCustomListView.SetOnViewportButtonDown(const Value: TLVViewportButtonDownEvent);
begin
  FOnViewportMouseDown := Value;
  HookMouseDowns;
end;

procedure TCustomListView.HookMouseDowns;
var
  Method: TMethod;
begin
  if Assigned(FOnMouseDown) or Assigned(FOnViewportMouseDown) then
  begin
    if FDownsHooked then
      Exit;
    QListView_mouseButtonPressed_Event(Method) := DoLVMouseDown;
    FDownsHooked := True;
  end
  else
  begin
    Method := NullHook;
    FDownsHooked := False;
  end;

  QListView_hook_hook_mouseButtonPressed(QListView_hookH(Hooks), Method);
end;

procedure TCustomListView.SetViewStyle(const Value: TViewStyle);
begin
  if FViewStyle <> Value then
  begin
    FViewStyle := Value;
    ShowColumnHeaders := FViewStyle = vsReport;
  end;
end;

procedure TCustomListView.RepopulateItems;
var
  I: Integer;
begin
  if HandleAllocated then
  begin
    if (QListView_childCount(Handle) = 0) and (QListView_columns(Handle) > 0) then
    begin
      Items.BeginUpdate;
      try
        for I := 0 to Items.Count-1 do
          Items[I].ReCreateItem;
      finally
        Items.EndUpdate;
      end;
    end
    else
    begin
      Items.BeginUpdate;
      try
        for I := 0 to Items.Count-1 do
          Items[I].ResetFields;
      finally
        Items.EndUpdate;
      end;
    end;
  end;
end;

procedure TCustomListView.RestoreWidgetState;
begin
  inherited RestoreWidgetState;
  if Assigned(FMemStream) then
  begin
    FMemStream.Position := 0;
    FItems.ReadData(FMemStream);
    FreeAndNil(FMemStream);
  end;
end;

procedure TCustomListView.SaveWidgetState;
begin
  inherited SaveWidgetState;
  FMemStream := TMemoryStream.Create;
  FItems.WriteData(FMemStream);
  FItems.Clear;
end;

{ TTreeStrings }
type
  TTreeStrings = class(TStrings)
  private
    FOwner: TTreeNodes;
  protected
    function Get(Index: Integer): string; override;
    function GetBufStart(Buffer: PChar; var Level: Integer): PChar;
    function GetCount: Integer; override;
    function GetObject(Index: Integer): TObject; override;
    procedure PutObject(Index: Integer; AObject: TObject); override;
  public
    constructor Create(AOwner: TTreeNodes);
    function Add(const S: string): Integer; override;
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Insert(Index: Integer; const S: string); override;
    procedure LoadTreeFromStream(Stream: TStream);
    procedure SaveTreeToStream(Stream: TStream);
    property Owner: TTreeNodes read FOwner;
  end;

constructor TTreeStrings.Create(AOwner: TTreeNodes);
begin
  inherited Create;
  FOwner := AOwner;
end;

function TTreeStrings.Get(Index: Integer): string;
const
  TabChar = #9;
var
  Level, I: Integer;
  Node: TTreeNode;
begin
  Result := '';
  Node := Owner.Item[Index];
  if not Assigned(Node) then
    Exit;
  Level := Node.Level;
  for I := 0 to Level - 1 do
    Result := Result + TabChar;
  Result := Result + Node.Text;
end;

function TTreeStrings.GetBufStart(Buffer: PChar; var Level: Integer): PChar;
begin
  Level := 0;
  while True do
  begin
    case Buffer^ of
      #32: Inc(Buffer);
      #9:
      begin
        Inc(Buffer);
        Inc(Level);
      end;
      else
        Break;
    end;
  end;
  Result := Buffer;
end;

function TTreeStrings.GetObject(Index: Integer): TObject;
begin
  Result := Owner.Item[Index];
  if Assigned(Result) then
    Result := TTreeNode(Result).Data;
end;

procedure TTreeStrings.PutObject(Index: Integer; AObject: TObject);
var
  Node: TTreeNode;
begin
  Node := Owner.Item[Index];
  if Assigned(Node) then
    Node.Data := AObject;
end;

function TTreeStrings.GetCount: Integer;
begin
  Result := Owner.Count;
end;

procedure TTreeStrings.Clear;
begin
  Owner.Clear;
end;

procedure TTreeStrings.Delete(Index: Integer);
begin
  Owner.Item[Index].Delete;
end;

function TTreeStrings.Add(const S: string): Integer;
var
  Level, OldLevel, I: Integer;
  NewStr: string;
  Node: TTreeNode;
begin
  Result := GetCount;
  if (Length(S) = 1) and (S[1] = Chr($1A)) then
    Exit;
  Node := nil;
  OldLevel := 0;
  NewStr := GetBufStart(PChar(S), Level);
  if Result > 0 then
  begin
    Node := Owner.Item[Result-1];
    OldLevel := Node.Level;
  end;
  if (Level > OldLevel) or not Assigned(Node) then
  begin
    if Level - OldLevel > 1 then
      TreeViewError(sInvalidLevel);
  end
  else begin
    for I := OldLevel downto Level do
    begin
      Node := Node.Parent;
      if not Assigned(Node) and (I - Level > 0) then
        TreeViewError(sInvalidLevel);
    end;
  end;
  Owner.AddChild(Node, NewStr);
end;

procedure TTreeStrings.Insert(Index: Integer; const S: string);
begin
  Owner.Insert(Owner.Item[Index], S);
end;

procedure TTreeStrings.LoadTreeFromStream(Stream: TStream);
var
  List: TStringList;
  ANode, NextNode: TTreeNode;
  ALevel, I: Integer;
  CurrStr: string;
  StartSub, EndSub: PChar;
  SubItemStart: Integer;
begin
  try
    List := nil;
    Owner.BeginUpdate;
    try
      List := TStringList.Create;
      Clear;
      List.LoadFromStream(Stream);
      ANode := nil;
      for I := 0 to List.Count - 1 do
      begin
        CurrStr := GetBufStart(PChar(List[I]), ALevel);
        SubItemStart := Pos(#9, CurrStr);
        if SubItemStart <> 0 then
          SetLength(CurrStr, SubItemStart-1);
        if ANode = nil then
          ANode := Owner.AddChild(nil, CurrStr)
        else if ANode.Level = ALevel then
          ANode := Owner.AddChild(ANode.Parent, CurrStr)
        else if ANode.Level = (ALevel - 1) then
          ANode := Owner.AddChild(ANode, CurrStr)
        else if ANode.Level > ALevel then
        begin
          NextNode := ANode.Parent;
          while NextNode.Level > ALevel do
            NextNode := NextNode.Parent;
          ANode := Owner.AddChild(NextNode.Parent, CurrStr);
        end
        else
          TreeViewErrorFmt(sInvalidLevelEx, [ALevel, CurrStr]);
        if Assigned(ANode) and (SubItemStart <> 0) then
        begin
          StartSub := PChar(List[I]) + SubItemStart + ALevel;
          while True do
            case StartSub^ of
              #9, #32: Inc(StartSub);
              #10, #0: Break;
              else
              begin
                EndSub := StartSub;
                while True do
                  case EndSub^ of
                    #32, #10, #9, #0: Break;
                    else
                      Inc(EndSub);
                  end;
                SetString(CurrStr, StartSub, EndSub-StartSub);
                StartSub := EndSub;
                ANode.SubItems.Add(CurrStr);
              end;
            end;
        end;
      end;
    finally
      List.Free;
      Owner.EndUpdate;
    end;
  except
    Owner.Owner.Invalidate; { force repaint on exception }
    raise;
  end;
end;

procedure TTreeStrings.SaveTreeToStream(Stream: TStream);
const
  TabChar = #9;
var                   
  I: Integer;
  J: Integer;
  ANode: TTreeNode;
  NodeStr: string;
begin
  if Count > 0 then
  begin
    ANode := Owner[0];
    while Assigned(ANode) do
    begin
      NodeStr := ANode.Text;
      for I := 0 to ANode.Level - 1 do
        NodeStr := TabChar + NodeStr;
      for J := 0 to ANode.SubItems.Count-1 do
        NodeStr := NodeStr + TabChar + ANode.SubItems[J];
      NodeStr := NodeStr + sLineBreak;
      Stream.Write(PChar(NodeStr)^, Length(NodeStr));
      ANode := ANode.GetNext;
    end;
  end;
end;

{ TCustomTreeView }

constructor TCustomTreeView.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Init(TTreeNode);
end;

destructor TCustomTreeView.Destroy;
begin
  if Assigned(FMemStream) then
    FreeAndNil(FMemStream);
  FTreeNodes.Free;
  inherited Destroy;
end;

procedure TCustomTreeView.ItemChanging(item: QListViewItemH; _type: TItemChange;
  var Allow: Boolean);
var
  AItem: TTreeNode;
begin
  if _type <> ctState then
    Exit;
  AItem := FTreeNodes.FindItem(item);
  if not Assigned(AItem) or (Assigned(AItem) and AItem.FDestroying) then
    Exit;
  if Assigned(FOnChanging) then
    FOnChanging(Self, AItem, Allow);
  if AItem <> FSelectedNode then
    StartEditTimer;
end;

procedure TCustomTreeView.ItemChecked(item: QListViewItemH; Checked: Boolean);
var
  AItem: TTreeNode;
begin
  AItem := FTreeNodes.FindItem(item);
  if Assigned(AItem) then
    AItem.FChecked := Checked;   
  StartEditTimer;
end;

procedure TCustomTreeView.ItemDestroyed(AItem: QListViewItemH);
var
  ANode: TTreeNode;
begin
  if QClxObjectMap_find(AItem) <> 0 then
    ANode := FTreeNodes.FindItem(AItem)
  else
    ANode := nil;
  if Assigned(ANode) then
  begin
    QClxObjectMap_remove(ANode.FHandle);
    ANode.FHandle := nil;
    if not (csDestroying in ComponentState) and (FHeader is TListViewHeader) then
      if (not TListViewHeader(FHeader).FHiddenChanging) and not ANode.FDestroying then
        ANode.Free;
  end;
end;

procedure TCustomTreeView.ItemExpanding(item: QListViewItemH; Expand: Boolean;
  var Allow: Boolean);
var
  Node: TTreeNode;
begin
  Node := FTreeNodes.FindItem(item);
  if Assigned(Node) and Node.Expanded <> Expand then
    Allow := Node.DoCanExpand(Expand);
end;

procedure TCustomTreeView.ItemExpanded(item: QListViewItemH; Expand: Boolean);
var
  Node: TTreeNode;
begin
  Node := FTreeNodes.FindItem(item);
  if not Assigned(Node) then
    Exit;
  if Expand then
  begin
    if AutoExpand and not FFullExpansion then
      DoAutoExpand(Node);
    if Assigned(FOnExpanded) then
      FOnExpanded(Self, Node);
  end
  else
    if Assigned(FOnCollapsed) then
      FOnCollapsed(Self, Node);
end;

procedure TCustomTreeView.ItemSelected(item: QListViewItemH; wasSelected: Boolean);
const
  cIncSelCount: array [Boolean] of Integer = (-1, 1);
var
  AItem: TTreeNode;
begin
  Inc(FSelCount, cIncSelCount[wasSelected]);
  AItem := FTreeNodes.FindItem(item); 
  if wasSelected and Assigned(AItem) and not AItem.FDestroying then
    FSelectedNode := AItem
  else
    FSelectedNode := nil;
  if Assigned(FSelectedNode) then
    Change(AItem);
end;

procedure TCustomTreeView.SetItems(const Value: TTreeNodes);
begin
  FTreeNodes.Assign(Value);
end;

procedure TCustomTreeView.SetTopItem(const AItem: TTreeNode);
var
  NewTopH: Integer;
begin
  if Assigned(AItem) and HandleAllocated then
  begin
    NewTopH := QListView_itemPos(Handle, AItem.Handle);
    QListView_setContentsPos(Handle, QScrollView_contentsX(Handle), NewTopH);
  end;
end;

function TCustomTreeView.GetDropTarget: TTreeNode;
var
  Temp: TCustomViewItem;
begin
  Result := nil;
  Temp := FindDropTarget;
  if Temp is TTreeNode then
    Result := TTreeNode(Temp);
end;

function TCustomTreeView.GetTopItem: TTreeNode;
begin
  Result := GetNodeAt(1, 1);
end;

constructor TCustomTreeView.Create(AOwner: TComponent; ANodeClass: TTreeNodeClass);
begin
  inherited Create(AOwner);
  Init(ANodeClass);
end;

procedure TCustomTreeView.Init(ANodeClass: TTreeNodeClass);
begin
  FTreeNodes := TTreeNodes.Create(Self);
  FTreeNodes.SetNodeClass(ANodeClass);
  FShowButtons := True;
  FItemMargin := 1;
  ColumnClick := True;
  ColumnMove := True;
  ColumnResize := True;
end;

function TCustomTreeView.IsCustomDrawn: Boolean;
begin
  Result := Assigned(FOnCustomDrawItem) or Assigned(FOnCustomDrawSubItem) or
            Assigned(FOnCustomDrawBranch);
end;

procedure TCustomTreeView.InitWidget;
begin
  inherited InitWidget;
  QListView_setRootIsDecorated(Handle, FShowButtons);
end;

procedure TCustomTreeView.DoGetImageIndex(item: TCustomViewItem);
var
  Pixmap: QPixmapH;
begin
  if item is TTreeNode then
  begin
    QWidget_setUpdatesEnabled(Handle, False);
    try
      if Assigned(FOnGetImageIndex) then
        FOnGetImageIndex(Self, TTreeNode(item));
      if Assigned(Images) then
      begin
        Pixmap := Images.GetPixmap(TTreeNode(item).ImageIndex);
        if Assigned(Pixmap) then
          QListViewItem_setPixmap(item.Handle, 0, Pixmap);
      end;
      if Item.Selected then
      begin
        if Assigned(FOnGetSelectedIndex) then
          FOnGetSelectedIndex(Self, TTreeNode(item));
        if Assigned(Images) then
        begin
          Pixmap := Images.GetPixmap(TTreeNode(item).SelectedIndex);
          if Assigned(Pixmap) then
            QListViewItem_setPixmap(item.Handle, 0, Pixmap);
        end;
      end;
    finally
      QWidget_setUpdatesEnabled(Handle, True);
    end;
  end;
end;

procedure TCustomTreeView.DoEditing(AItem: TCustomViewItem; var AllowEdit: Boolean);
begin
  if Assigned(FOnEditing) and (AItem is TTreeNode) then
    FOnEditing(Self, TTreeNode(AItem), AllowEdit);
end;

procedure TCustomTreeView.DoEdited(AItem: TCustomViewItem; var S: WideString);
begin
  if Assigned(FOnEdited) and (AItem is TTreeNode) then
    FOnEdited(Self, TTreeNode(AItem), S);
end;

procedure TCustomTreeView.FullCollapse;
var
  Node: TTreeNode;
begin
  Node := Items.GetFirstNode;
  while Node <> nil do
  begin
    Node.Collapse(True);
    Node := Node.GetNextSibling;
  end;
end;

procedure TCustomTreeView.FullExpand;
var
  Node: TTreeNode;
begin
  Node := Items.GetFirstNode;
  Items.BeginUpdate;
  FFullExpansion := True;
  try
    while Node <> nil do
    begin
      Node.Expand(True);
      Node := Node.GetNextSibling;
    end;
  finally
    FFullExpansion := False;
    Items.EndUpdate;
  end;
end;

function TCustomTreeView.GetNodeAt(X, Y: Integer): TTreeNode;
var
  Temp: QListViewItemH;
  Pt: Types.TPoint;
begin
  Result := nil;
  if HandleAllocated then
  begin
    Pt := Types.Point(X, Y);
    Temp := QListView_itemAt(Handle, @Pt);
    Result := FTreeNodes.FindItem(Temp);
  end;
end;

procedure TCustomTreeView.LoadFromFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmOpenRead);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TCustomTreeView.LoadFromStream(Stream: TStream);
begin
  with TTreeStrings.Create(Items) do
    try
      LoadTreeFromStream(Stream);
    finally
      Free;
    end;
end;

procedure TCustomTreeView.SaveToFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmCreate);
  try
    SaveToStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TCustomTreeView.SaveToStream(Stream: TStream);
begin
  with TTreeStrings.Create(Items) do
    try
      SaveTreeToStream(Stream);
    finally
      Free;
    end;
end;

function TCustomTreeView.AlphaSort: Boolean;
var
  Node: TTreeNode;
begin
  Result := True;
  if HandleAllocated then
  begin
    SortColumn := 0;
    Sorted := True;
    Node := FTreeNodes.GetFirstNode;
    while Node <> nil do
    begin
      if Node.HasChildren then
        Node.AlphaSort(SortDirection = sdAscending);
      Node := Node.GetNext;
    end;
  end
  else
    Result := False;
end;

function TCustomTreeView.CanCollapse(Node: TTreeNode): Boolean;
begin
  Result := True;
  if Assigned(FOnCollapsing) then
    FOnCollapsing(Self, Node, Result);
end;

function TCustomTreeView.CanExpand(Node: TTreeNode): Boolean;
begin
  Result := True;
  if Assigned(FOnExpanding) then
    FOnExpanding(Self, Node, Result);
end;

procedure TCustomTreeView.Change(Node: TTreeNode);
begin
  if Assigned(FOnChange) then
    FOnChange(Self, Node);
end;

procedure TCustomTreeView.Collapse(Node: TTreeNode);
begin
  if Assigned(Node) then
    Node.Expanded := False;
end;

procedure TCustomTreeView.Delete(Node: TTreeNode);
begin
  if Assigned(Node) then
    Node.Delete;
end;

function TCustomTreeView.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  if QEvent_type(Event) = QEventType_FocusIn then
    if (Items.Count > 0) and not Assigned(Selected) then
      QListView_setSelected(Handle, QListView_firstChild(Handle), True);
  Result := inherited EventFilter(Sender, Event);
end;

procedure TCustomTreeView.Expand(Node: TTreeNode);
begin
  if Assigned(Node) then
    Node.Expanded := True;
end;

procedure TCustomTreeView.Loaded;
begin
  inherited Loaded;
  if csDesigning in ComponentState then
    FullExpand;
end;

procedure TCustomTreeView.SetSortType(const Value: TSortType);
begin
  if SortType <> Value then
  begin
    FSortType := Value;
    if (SortType in [stText]) then
      AlphaSort;
  end;
end;

procedure TCustomTreeView.SetAutoExpand(const Value: Boolean);
begin
  if FAutoExpand <> Value then
    FAutoExpand := Value;
end;

function TCustomTreeView.GetSelected: TTreeNode;
begin
  Result := FSelectedNode;
end;

procedure TCustomTreeView.SetSelected(const Value: TTreeNode);
begin
  if not (csDestroying in ComponentState) then
  begin
    if Assigned(FSelectedNode) and not MultiSelect then
      FSelectedNode.Selected := False;
    if Assigned(Value) then
      Value.Selected := True;
  end;
end;

procedure TCustomTreeView.SetItemMargin(const Value: Integer);
begin
  if ItemMargin <> Value then
  begin
    FItemMargin := Value;
    if HandleAllocated then
      QListView_setItemMargin(Handle, FItemMargin);
  end;
end;

procedure TCustomTreeView.SelectAll(Select: Boolean);
begin
  MultiSelect := True;
  if HandleAllocated then
    QListView_selectAll(Handle, Select);
end;

procedure TCustomTreeView.SetOnItemDoubleClick(const Value: TTVItemDoubleClickEvent);
var
  Method: TMethod;
begin
  FOnItemDoubleClick := Value;
  if Assigned(FOnItemDoubleClick) then
    QListView_doubleClicked_Event(Method) := DoItemDoubleClick
  else
    Method := NullHook;
  QListView_hook_hook_doubleClicked(QListView_hookH(Hooks), Method);
end;

procedure TCustomTreeView.SetOnItemEnter(const Value: TTVItemEnterEvent);
var
  Method: TMethod;
begin
  FOnItemEnter := Value;
  if Assigned(FOnItemEnter) then
    QListView_onItem_Event(Method) := DoOnItemEnter
  else
    Method := NullHook;
  QListView_hook_hook_onItem(QListView_hookH(Hooks), Method);
end;

procedure TCustomTreeView.SetOnItemExitViewportEnter(const Value: TTVItemExitViewportEnterEvent);
var
  Method: TMethod;
begin
  FOnItemExitViewportEnter := Value;
  if Assigned(FOnItemExitViewportEnter) then
    QListView_onViewport_Event(Method) := DoOnItemExitViewportEnter
  else
    Method := NullHook;
  QListView_hook_hook_onViewport(QListView_hookH(Hooks), Method);
end;

procedure TCustomTreeView.SetOnMouseDown(const Value: TTVButtonDownEvent);
begin
  FOnMouseDown := Value;
  HookMouseDowns;
end;

procedure TCustomTreeView.SetOnViewportButtonDown(const Value: TTVViewportButtonDownEvent);
begin
  FOnViewportMouseDown := Value;
  HookMouseDowns;
end;

procedure TCustomTreeView.DoItemClick(p1: Integer; p2: QListViewItemH; p3: PPoint;
  p4: Integer);
var
  AItem: TTreeNode;
  SelNode: TTreeNode;
begin
  try
    AItem := FTreeNodes.FindItem(p2);
    if AutoExpand and Assigned(AItem) then
    begin
      SelNode := Selected;
      try
        DoAutoExpand(AItem);
      finally
        Selected := SelNode;
      end;
    end;
    if Assigned(AItem) then
    begin
      if Assigned(FOnItemClick) then
        FOnItemClick(Self, ButtonToMouseButton(p1), AItem, p3^);
      if (p4 = 0) and FAllowEdit then
        EditItem;
    end;
  except 
    Application.HandleException(Self);
  end;
end;

procedure TCustomTreeView.DoItemDoubleClick(p1: QListViewItemH);
var
  SelectedItem: TTreeNode;
begin
  if Assigned(FOnItemDoubleClick) then
  try
    SelectedItem := FTreeNodes.FindItem(p1);
    FOnItemDoubleClick(Self, SelectedItem);
  except 
    Application.HandleException(Self);
  end;
end;

procedure TCustomTreeView.DoOnItemEnter(item: QListViewItemH);
var
  SelectedItem: TTreeNode;
begin
  if Assigned(FOnItemEnter) then
  try
    SelectedItem := FTreeNodes.FindItem(item);
    FOnItemEnter(Self, SelectedItem);
  except 
    Application.HandleException(Self);
  end;
end;

procedure TCustomTreeView.DoOnItemExitViewportEnter;
begin
  if Assigned(FOnItemExitViewportEnter) then
  try
    FOnItemExitViewportEnter(Self);
  except 
    Application.HandleException(Self);
  end;
end;

procedure TCustomTreeView.DoOnMouseDown(p1: Integer; p2: QListViewItemH;
  p3: PPoint; p4: Integer);
var
  AItem: TTreeNode;
begin
  try
    AItem := FTreeNodes.FindItem(p2);
    if Assigned(FOnMouseDown) and (p2 <> nil) then
      FOnMouseDown(Self, ButtonToMouseButton(p1), AItem, p3^)
    else if Assigned(FOnViewportMouseDown) and (AItem = nil) then
      FOnViewportMouseDown(Self, ButtonToMouseButton(p1), p3^);
  except 
    Application.HandleException(Self);
  end;
end;

procedure TCustomTreeView.HookMouseDowns;
var
  Method: TMethod;
begin
  if Assigned(FOnMouseDown) or Assigned(FOnViewportMouseDown) then
    QListView_mouseButtonPressed_Event(Method) := DoOnMouseDown
  else
    Method := NullHook;

  QListView_hook_hook_mouseButtonPressed(QListView_hookH(Hooks), Method);
end;

procedure TCustomTreeView.DoAutoExpand(ExpandedNode: TTreeNode);
var
  Node: TTreeNode;
  ParentNode: TTreeNode;
begin
  if ExpandedNode = nil then
    Exit;
  Items.BeginUpdate;
  try
    ParentNode := ExpandedNode;
    if Assigned(ParentNode) then
      while ParentNode.GetParent <> nil do
        ParentNode := ParentNode.GetParent;

    Node := Items.GetFirstNode;
    if Assigned(Node) then
    begin
      while True do
      begin
        if Node = nil then
          Exit;
        if Node = ParentNode then
        begin
          Node := Node.getNextSibling;
          Continue;
        end;
        Node.Collapse(False);
        Node := Node.getNextSibling;
      end;
    end;
  finally
    if not ExpandedNode.Expanded then
      ExpandedNode.Expand(False);
    Items.EndUpdate;
  end;
end;

procedure TCustomTreeView.SetShowButtons(const Value: Boolean);
begin
  if FShowButtons <> Value then
  begin
    FShowButtons := Value;
    if HandleAllocated then
      QListView_setRootIsDecorated(Handle, FShowButtons);
  end;
end;

procedure TCustomTreeView.RepopulateItems;
var
  I: Integer;
begin
  if HandleAllocated then
  begin
    if (QListView_childCount(Handle) = 0) and (QListView_columns(Handle) > 0) then
    begin
      Items.BeginUpdate;
      try
        for I := 0 to Items.Count-1 do
          Items[I].ReCreateItem;
      finally
        Items.EndUpdate;
      end;
    end
    else
    begin
      Items.BeginUpdate;
      try
        for I := 0 to Items.Count-1 do
          Items[I].ResetFields;
      finally
        Items.EndUpdate;
      end;
    end;
  end;
end;

procedure TCustomTreeView.RestoreWidgetState;
begin
  inherited RestoreWidgetState;
  if Assigned(FMemStream) then
  begin
    FMemStream.Position := 0;
    FTreeNodes.ReadData(FMemStream);
    FreeAndNil(FMemStream);
  end;
end;

procedure TCustomTreeView.SaveWidgetState;
begin
  inherited SaveWidgetState;
  FMemStream := TMemoryStream.Create;
  FTreeNodes.WriteData(FMemStream);
  FTreeNodes.Clear;
end;

procedure TCustomTreeView.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  QListView_mouseButtonClicked_Event(Method) := DoItemClick;
  QListView_hook_hook_mouseButtonClicked(QListView_hookH(Hooks), Method);
end;

procedure TCustomTreeView.ImageListChanged;
var
  I: Integer;
begin
  for I := 0 to FTreeNodes.Count-1 do
    FTreeNodes[i].UpdateImages;
end;

{ TTreeView }

{$IF not (defined(LINUX) and defined(VER140))}
function TTreeView.GetSelCount: Integer;
begin
  Result := FSelCount;
end;
{$IFEND}

{ TViewItemsList }

function TViewItemsList.GetItem(Index: Integer): TCustomViewItem;
begin
  Result := TCustomViewItem(inherited GetItem(Index));
end;

procedure TViewItemsList.SetItem(Index: Integer; AObject: TCustomViewItem);
begin
  inherited SetItem(Index, AObject);
end;

{ TCustomHeaderControl }

constructor TCustomHeaderControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCanvas := TControlCanvas.Create;
  TControlCanvas(FCanvas).Control := Self;
  FImageChanges := TChangeLink.Create;
  FImageChanges.OnChange := OnImageChanges;

  FOrientation := hoHorizontal;
  FTracking := True;
  FDragReorder := False;
  Height := 19;
  Align := alTop;
end;

destructor TCustomHeaderControl.Destroy;
begin
  if Assigned(FMemStream) then
    FreeAndNil(FMemStream);
  FImageChanges.Free;
  FCanvas.Free;
  inherited Destroy;
end;

procedure TCustomHeaderControl.AssignTo(Dest: TPersistent);
var
  I: Integer;
begin
  if Dest is TCustomHeaderControl then
  begin
    TCustomHeaderControl(Dest).Sections.Clear;
    for I := 0 to Sections.Count - 1 do
      TCustomHeaderControl(Dest).Sections.Add.Assign(Sections[I]);
  end
  else
    inherited Assign(Dest);
end;

procedure TCustomHeaderControl.ChangeBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  inherited ChangeBounds(ALeft, ATop, AWidth, AHeight);
  Invalidate;
end;

procedure TCustomHeaderControl.ColumnClicked(Section: TCustomHeaderSection);
begin
  if Assigned(FOnSectionClick) then
    FOnSectionClick(Self, Section);
end;

procedure TCustomHeaderControl.ColumnMoved(Section: TCustomHeaderSection);
begin
  if Assigned(FOnSectionMoved) then
    FOnSectionMoved(Self, Section);
end;

procedure TCustomHeaderControl.ColumnResized(Section: TCustomHeaderSection);
begin
  if Assigned(FOnSectionResize) then
    FOnSectionResize(Self, Section);
end;

procedure TCustomHeaderControl.CreateWidget;
begin
  FHandle := QHeader_create(ParentWidget, nil);
  Hooks := QHeader_hook_create(FHandle);
end;

function TCustomHeaderControl.GetHandle: QHeaderH;
begin
  HandleNeeded;
  Result := QHeaderH(FHandle);
end;

function TCustomHeaderControl.GetSections: TCustomHeaderSections;
begin
  Result := FSections;
end;

procedure TCustomHeaderControl.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  QHeader_sectionClicked_Event(Method) := SectionClicked;
  QHeader_hook_hook_sectionClicked(QHeader_hookH(Hooks), Method);
  QHeader_sizeChange_Event(Method) := SectionSizeChanged;
  QHeader_hook_hook_sizeChange(QHeader_hookH(Hooks), Method);
  QHeader_moved_Event(Method) := SectionMoved;
  QHeader_hook_hook_moved(QHeader_hookH(Hooks), Method);
end;

procedure TCustomHeaderControl.ImageListChanged;
begin
  FSections.UpdateImages;
end;

procedure TCustomHeaderControl.InitWidget;
begin
  inherited InitWidget;
  if FDragReorder then
    FClickable := True;
  QHeader_setClickEnabled(Handle, FClickable, -1);
  QHeader_setResizeEnabled(Handle, FResizable, -1);
  QHeader_setTracking(Handle, FTracking);
  QHeader_setMovingEnabled(Handle, FDragReorder);
end;

procedure TCustomHeaderControl.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);

  if (AComponent = FImages) then
  begin
    if (Operation = opRemove) then
      FImages := nil;
    ImageListChanged;
  end;
end;

procedure TCustomHeaderControl.OnImageChanges(Sender: TObject);
begin
  ImageListChanged;
end;

procedure TCustomHeaderControl.RestoreWidgetState;
begin
  inherited RestoreWidgetState;
  if Assigned(FMemStream) then
  begin
    FMemStream.Position := 0;
    FSections.Clear;
    FMemStream.ReadComponent(Self);
    FreeAndNil(FMemStream);
  end;
end;

procedure TCustomHeaderControl.SaveWidgetState;
begin
  inherited SaveWidgetState;
  if not Assigned(FMemStream) then
    FMemStream := TMemoryStream.Create
  else
    FMemStream.Clear;
  FMemStream.WriteComponent(Self);
end;

procedure TCustomHeaderControl.SectionClicked(SectionIndex: Integer);
begin
  try
    if (SectionIndex >= 0) and (SectionIndex < FSections.Count) then
      ColumnClicked(Sections[SectionIndex]);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomHeaderControl.SectionMoved(FromIndex, ToIndex: Integer);
var
  FromSection: TCustomHeaderSection;
begin
  if (FromIndex <> ToIndex) and (FromIndex <> ToIndex-1) then
  begin
    try
      FDontResubmit := True;
      try
        if ToIndex > FromIndex then
          Dec(ToIndex);
        FromSection := Sections[FromIndex];
        FromSection.SetIndex(ToIndex);
        ColumnMoved(FromSection);
      except
        Application.HandleException(Self);
      end;
    finally
      FDontResubmit := False;
    end;
  end;
end;

procedure TCustomHeaderControl.SectionSizeChanged(SectionIndex, OldSize,
  NewSize: Integer);
begin
  if OldSize <> NewSize then
  begin
    try
      { This by-passes the MaxWidth and MinWidth. Is there a way to make Qt
        happy with min/max widths on sections? }
      if (SectionIndex >= 0) and (SectionIndex < FSections.Count) then
      begin
        FSections[SectionIndex].FWidth := NewSize;
        ColumnResized(FSections[SectionIndex]);
      end;
    except
      Application.HandleException(Self);
    end;
  end;
end;

procedure TCustomHeaderControl.SetClickable(const Value: Boolean);
var
  I: Integer;
begin
  if Clickable <> Value then
  begin
    FClickable := Value;
    for I := 0 to Sections.Count-1 do
      Sections[I].AllowClick := FClickable;
    if not FClickable then
      DragReorder := False;
    if HandleAllocated then
      QWidget_update(Handle);
  end;
end;

procedure TCustomHeaderControl.SetDragReorder(const Value: Boolean);
begin
  if DragReorder <> Value then
  begin
    FDragReorder := Value;
    if HandleAllocated then
      QHeader_setMovingEnabled(Handle, FDragReorder);
    if FDragReorder then
      Clickable := True;
  end;
end;

procedure TCustomHeaderControl.SetImages(const Value: TCustomImageList);
begin
  if FImages <> Value then
  begin
    if Assigned(FImages) then
      FImages.UnRegisterChanges(FImageChanges);
    FImages := Value;
    if Assigned(FImages) then
      FImages.RegisterChanges(FImageChanges);
    ImageListChanged;
  end;
end;

procedure TCustomHeaderControl.SetOrientation(const Value: THeaderOrientation);
const
  cOrientation: array [THeaderOrientation] of Qt.Orientation =
    (Orientation_Horizontal, Orientation_Vertical);
begin
  if FOrientation <> Value then
  begin
    FOrientation := Value;
    if Align <> alNone then
      if FOrientation = hoHorizontal then
        Align := alTop
      else
        Align := alLeft;
    if HandleAllocated then
      QHeader_setOrientation(Handle, cOrientation[FOrientation]);
  end;
end;

procedure TCustomHeaderControl.SetResizable(const Value: Boolean);
var
  I: Integer;
begin
  if Resizable <> Value then
  begin
    FResizable := Value;
    for I := 0 to Sections.Count-1 do
      Sections[I].AllowResize := FResizable;
  end;
end;

procedure TCustomHeaderControl.SetSections(const Value: TCustomHeaderSections);
begin
  FSections.Assign(Value);
end;

procedure TCustomHeaderControl.SetTracking(const Value: Boolean);
begin
  if Tracking <> Value then
  begin
    FTracking := Value;
    if HandleAllocated then
      QHeader_setTracking(Handle, FTracking);
  end;
end;

{ THeaderSections }

function THeaderSections.Add: THeaderSection;
begin
  Result := THeaderSection(inherited Add);
end;

function THeaderSections.GetItem(Index: Integer): THeaderSection;
begin
  Result := THeaderSection(inherited GetItem(Index));
end;

procedure THeaderSections.SetItem(Index: Integer; Value: THeaderSection);
begin
  inherited SetItem(Index, Value);
end;

{ TCustomHeaderSection }

procedure TCustomHeaderSection.AddSection;
begin
  QHeader_addLabel(Header.Handle, nil, FWidth);
  QHeader_setClickEnabled(Header.Handle, FAllowClick,
    QHeader_mapToIndex(Header.Handle, Index));
  QHeader_setResizeEnabled(Header.Handle, FAllowResize,
    QHeader_mapToIndex(Header.Handle, Index));
end;

procedure TCustomHeaderSection.AssignTo(Dest: TPersistent);
begin
  if Dest is TCustomHeaderSection then
  begin
    TCustomHeaderSection(Dest).AllowResize := FAllowResize;
    TCustomHeaderSection(Dest).AllowClick := FAllowClick;
    TCustomHeaderSection(Dest).MaxWidth := FMaxWidth;
    TCustomHeaderSection(Dest).Width := FWidth;
    TCustomHeaderSection(Dest).MinWidth := FMinWidth;
  end
  else
    inherited AssignTo(Dest);
end;

constructor TCustomHeaderSection.Create(Collection: TCollection);
begin
  inherited Create(Collection);

  if (Collection is TCustomHeaderSections) and
  (TCustomHeaderSections(Collection).GetOwner is TCustomHeaderControl) then
    FHeader := TCustomHeaderControl(TCustomHeaderSections(Collection).GetOwner)
  else
    raise EHeaderException.CreateRes(@sOwnerNotCustomHeaderSections);

  FAllowClick := True;
  FAllowResize := True;
  FWidth := 50;
  FImageIndex := -1;
  MaxWidth := 1000;
  MinWidth := 0;
  AddSection;
end;

function TCustomHeaderSection.CalcSize: Integer;
const
  cMargin = 4 shl 1;
var
  fm: QFontMetricsH;
  Pixmap: QPixmapH;
  ISet: QIconSetH;
begin
  if not AutoSize then
  begin
    Result := FWidth;
    Exit;
  end
  else
    Result := 0;
  if FText <> '' then
  begin
    fm := QFontMetrics_create(Header.Font.Handle);
    try
      Result := QFontMetrics_width(fm, PWideString(@FText),
                Length(FText)) + cMargin;
    finally
      QFontMetrics_destroy(fm);
    end;
  end;
  ISet := QHeader_iconSet(Header.Handle, QHeader_mapToIndex(Header.Handle, Index));
  if Assigned(ISet) then
  begin
    Pixmap := QPixmap_create;
    try
      QIconSet_pixmap(ISet, Pixmap, QIconSetSize_Small, QIconSetMode_Normal);
      Inc(Result, QPixmap_width(Pixmap) + 2 + cMargin);
    finally
      QPixmap_destroy(Pixmap);
    end;
  end;
end;

function TCustomHeaderSection.Header: TCustomHeaderControl;
begin
  Result := FHeader;
end;

function TCustomHeaderSection.GetDisplayName: string;
begin
  Result := FText;
  if Result = '' then
    Result := inherited GetDisplayName;
end;

function TCustomHeaderSection.GetLeft: Integer;
begin
  if Header.HandleAllocated then
    Result := QHeader_sectionPos(Header.Handle,
      QHeader_mapToIndex(Header.Handle, Index))
  else
    Result := -1;
end;

procedure TCustomHeaderSection.Resubmit;
var
  AHandle: QHeaderH;
begin
  if Header = nil then
    Exit;
  if Header.HandleAllocated then
  begin
    AHandle := Header.Handle;
    QWidget_setUpdatesEnabled(AHandle, False);
    try
      QHeader_setLabel(AHandle, QHeader_mapToIndex(Header.Handle, Index),
        @FText, CalcSize);
      UpdateImage;
      QHeader_setClickEnabled(AHandle, FAllowClick,
        QHeader_mapToIndex(Header.Handle, Index));
      QHeader_setResizeEnabled(AHandle, FAllowResize,
        QHeader_mapToIndex(Header.Handle, Index));
    finally
      QWidget_setUpdatesEnabled(AHandle, True);
    end;
  end;
end;

procedure TCustomHeaderSection.SetAutoSize(const Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    if Header.HandleAllocated then
      QHeader_setLabel(Header.Handle, QHeader_mapToIndex(Header.Handle, Index),
        PWideString(@FText), CalcSize);
  end;
end;

function TCustomHeaderSection.GetRight: Integer;
begin
  Result := Left + Width;
end;

function TCustomHeaderSection.GetWidth: Integer;
begin
  if Header.HandleAllocated and not (csRecreating in Header.ControlState) then
    FWidth := QHeader_sectionSize(Header.Handle,
      QHeader_mapToIndex(Header.Handle, Index));
  Result := FWidth;
end;

procedure TCustomHeaderSection.SetAllowClick(const Value: Boolean);
begin
  if FAllowClick <> Value then
  begin
    FAllowClick := Value;
    if Header.HandleAllocated then
    begin
      QHeader_setClickEnabled(Header.Handle, FAllowClick,
        QHeader_mapToIndex(Header.Handle, Index));
      QWidget_update(Header.Handle);
    end;
  end;
end;

procedure TCustomHeaderSection.SetAllowResize(const Value: Boolean);
begin
  if FAllowResize <> Value then
  begin
    FAllowResize := Value;
    if Header.HandleAllocated then
    begin
      QHeader_setResizeEnabled(Header.Handle, FAllowResize,
        QHeader_mapToIndex(Header.Handle, Index));
      QWidget_update(Header.Handle);
    end;
  end;
end;

procedure TCustomHeaderSection.SetImageIndex(const Value: TImageIndex);
begin
  if FImageIndex <> Value then
  begin
    FImageIndex := Value;
    UpdateImage;
  end;
end;

procedure TCustomHeaderSection.SetMaxWidth(const Value: Integer);
begin
  if FMaxWidth <> Value then
  begin
    FMaxWidth := Value;
    if FMaxWidth < FMinWidth then
      FMaxWidth := FMinWidth + 1;
    UpdateWidth;
  end;
end;

procedure TCustomHeaderSection.SetMinWidth(const Value: Integer);
begin
  if FMinWidth <> Value then
  begin
    FMinWidth := Value;
    if FMinWidth > FMaxWidth then
      FMinWidth := FMaxWidth - 1;  
    UpdateWidth;
  end;
end;

procedure TCustomHeaderSection.SetWidth(Value: Integer);
begin
  if FWidth <> Value then
  begin
    if ((Value < MinWidth) and (Value >= 0)) then
      Value := MinWidth
    else if ((MaxWidth > 0) and (Value > MaxWidth)) then
      Value := MaxWidth;

    SetWidthVal(Value);
  end;
end;

procedure TCustomHeaderSection.SetWidthVal(const Value: Integer);
begin
  FWidth := Value;
end;

procedure TCustomHeaderSection.UpdateImage;
var
  Pixmap: QPixmapH;
  IconSet: QIconSetH;
begin
  if Header.HandleAllocated then
  begin
    if Assigned(Header.FImages) then
      Pixmap := Header.FImages.GetPixmap(FImageIndex)
    else
      Pixmap := nil;
    IconSet := QHeader_iconSet(Header.Handle,
      QHeader_mapToIndex(Header.Handle, Index));
    if not Assigned(IconSet) then
    begin
      IconSet := QIconset_create;
      try
        QHeader_setLabel(Header.Handle, QHeader_mapToIndex(Header.Handle, Index),
          IconSet, PWideString(@FText), CalcSize);
      finally
        QIconSet_destroy(IconSet);
      end;
    end;
    IconSet := QHeader_iconSet(Header.Handle,
      QHeader_mapToIndex(Header.Handle, Index));
    if not Assigned(Pixmap) then
      QIconSet_reset(IconSet, QPixmap_create, QIconSetSize_Small)
    else
      QIconSet_setPixmap(IconSet, Pixmap, QIconSetSize_Small, QIconSetMode_Normal);
    QWidget_update(Header.Handle);
  end;
end;

procedure TCustomHeaderSection.UpdateWidth;
begin
  if FWidth > FMaxWidth then
    Width := FMaxWidth
  else if FWidth < FMinWidth then
    Width := FMinWidth;
end;

{ TListColumn }

procedure TListColumn.AddSection;
begin
  if HeaderIsListHeader and not TListViewHeader(Header).Hidden then
  begin
    if Collection.Count <> QListView_columns(ViewControl.Handle) then
      QListView_addColumn(ViewControl.Handle, nil, FWidth);
    QHeader_setClickEnabled(Header.Handle, FAllowClick,
      QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index));
    QHeader_setResizeEnabled(Header.Handle, FAllowResize,
      QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index));
    if QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index) = 0 then { repopulate dormant items }
      ViewControl.RepopulateItems;  
  end;
  Alignment := taLeftJustify;
end;

function TListColumn.HeaderIsListHeader: Boolean;
begin
  Result := Assigned(FHeader) and (Header is TListViewHeader);
end;

{$IF not (defined(LINUX) and defined(VER140))}
function TListColumn.GetCaption: WideString;
begin
  Result := FText;
end;
{$IFEND}

procedure TListColumn.AssignTo(Dest: TPersistent);
begin
  inherited AssignTo(Dest);
  if Dest is TListColumn then
  begin
    TListColumn(Dest).Caption := Caption;
    TListColumn(Dest).Alignment := Alignment;
    TListColumn(Dest).AutoSize := AutoSize;
  end;
end;

destructor TListColumn.Destroy;
var
  Empty: WideString;
begin
  if not (csDestroying in ViewControl.ComponentState) and HeaderIsListHeader then
    if not TListViewHeader(Header).Hidden then
    begin
      if QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index) = 0 then
      begin
        if QListView_columns(ViewControl.Handle) > 1 then
        begin
          QListView_removeColumn(ViewControl.Handle,
            QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index));
          ViewControl.RepopulateItems;
        end
        else
        begin
          Empty := '';
          QListView_setColumnText(ViewControl.Handle, 0, @Empty);
          QListView_setColumnWidthMode(ViewControl.Handle, 0,
            QListViewWidthMode_Maximum);
        end;
      end
      else if QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index) <> 0 then
        QListView_removeColumn(ViewControl.Handle,
          QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index));
    end;
  inherited Destroy;
end;

function TListColumn.GetWidth: Integer;
begin
  if Header.HandleAllocated and not (csRecreating in Header.ControlState) and
  HeaderIsListHeader and (not TListViewHeader(Header).Hidden) then
    FWidth := QListView_columnWidth(ViewControl.Handle,
      QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index));
  Result := FWidth;
end;

const
  ColAlignmentFlags: array [TAlignment] of Integer =
    (Integer(AlignmentFlags_AlignLeft), Integer(AlignmentFlags_AlignRight),
     Integer(AlignmentFlags_AlignCenter));
  ColAutoSize: array [Boolean] of QListViewWidthMode = (QListViewWidthMode_Manual,
                                                        QListViewWidthMode_Maximum);

procedure TListColumn.Resubmit;
var
  AHandle: QHeaderH;
begin
  if (Header <> nil) and Header.HandleAllocated then
  begin
    AHandle := Header.Handle;
    if not TListViewHeader(Header).Hidden then
      QWidget_setUpdatesEnabled(AHandle, False);
    try
      QListView_setColumnText(ViewControl.Handle,
        QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index), PWideString(@FText));
      QListView_setColumnAlignment(ViewControl.Handle,
        QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index), ColAlignmentFlags[FAlignment]);
      QListView_setColumnWidth(ViewControl.Handle,
        QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index), Width);
      QHeader_setClickEnabled(AHandle, FAllowClick,
        QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index));
      QHeader_setResizeEnabled(AHandle, FAllowResize,
        QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index));
    finally
      if not TListViewHeader(Header).Hidden then
        QWidget_setUpdatesEnabled(AHandle, True);
    end;
  end;
end;

procedure TListColumn.SetAlignment(const Value: TAlignment);
begin
  if (Value <> Alignment) and
  (QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index) <> 0) then
  begin
    FAlignment := Value;
    if not TListViewHeader(Header).Hidden and ViewControl.HandleAllocated then
      QListView_setColumnAlignment(ViewControl.Handle,
        QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index),
        ColAlignmentFlags[Value]);
  end;
end;

procedure TListColumn.SetAutoSize(const Value: Boolean);
begin
  if AutoSize <> Value then
  begin
    FAutoSize := Value;
    if not TListViewHeader(Header).Hidden and ViewControl.HandleAllocated then
      QListView_setColumnWidthMode(ViewControl.Handle,
        QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index),
        ColAutoSize[Value]);
  end;
end;

procedure TListColumn.SetCaption(const Value: WideString);
begin
  if FText <> Value then
  begin
    FText := Value;
    if ViewControl.HandleAllocated and not TListViewHeader(Header).Hidden then
      QListView_setColumnText(ViewControl.Handle,
        QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index),
        PWideString(@FText));
  end;
end;

procedure TListColumn.SetWidthVal(const Value: Integer);
begin
  FWidth := Value;
  if ViewControl.HandleAllocated and not TListViewHeader(Header).Hidden then
    QListView_setColumnWidth(ViewControl.Handle,
      QHeader_mapToIndex(QListView_header(ViewControl.Handle), Index), FWidth);
  ViewControl.UpdateControl;
end;

function TListColumn.ViewControl: TCustomViewControl;
begin
  Result := TCustomViewControl(Header.Owner);
end;

{ TListViewHeader }

constructor TListViewHeader.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FSections := TListColumns.Create(Self, TListColumn);
end;

destructor TListViewHeader.Destroy;
begin
  FSections.Free;
  inherited Destroy;
end;

procedure TListViewHeader.ColumnClicked(Section: TCustomHeaderSection);
begin
  if Assigned(ViewControl.FOnColumnClick) then
    ViewControl.FOnColumnClick(Owner, Section as TListColumn);
end;

procedure TListViewHeader.ColumnMoved(Section: TCustomHeaderSection);
begin
  if Assigned(ViewControl.FColumnDragged) then
    ViewControl.FColumnDragged(Owner, Section as TListColumn);
end;

procedure TListViewHeader.ColumnResized(Section: TCustomHeaderSection);
begin
  if Assigned(ViewControl.FColumnResize) then
    ViewControl.FColumnResize(Owner, Section as TListColumn);
end;

procedure TListViewHeader.CreateWidget;
begin
  if Hidden then
    FHandle := QHeader_create(ParentWidget, nil)
  else
    FHandle := QListView_header(ListViewHandle);
  Hooks := QHeader_hook_create(FHandle);
end;

procedure TListViewHeader.DestroyWidget;
begin
  if not (csRecreating in ControlState) then
    FSections.Clear;
  if Hidden and not FHiddenChanging then
    inherited DestroyWidget
  else
  begin
    if Assigned(Hooks) then
    begin
      QHeader_hook_destroy(QHeader_hookH(Hooks));
      Hooks := nil;
    end;
    QClxObjectMap_remove(FHandle);
    FHandle := nil;
  end;
end;

function TListViewHeader.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  if Hidden then
    Result := inherited EventFilter(Sender, Event)
  else
    Result := False;
end;
             
function TListViewHeader.GetHandle: QHeaderH;
begin
  HandleNeeded;
  if not Hidden and (FHandle <> QListView_header(ListViewHandle)) then
    RecreateWidget;
  Result := QHeaderH(FHandle);
end;

function TListViewHeader.GetSections: TListColumns;
begin
  Result := TListColumns(inherited GetSections);
end;

procedure TListViewHeader.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  if not Hidden then
  begin
    if QClxObjectMap_find(Handle) <> 0 then
      QClxObjectMap_remove(Handle);
    QClxObjectMap_add(Handle, Integer(Owner));
    if csDesigning in ComponentState then
    begin
      TEventFilterMethod(Method) := ViewControl.MainEventFilter;
      Qt_hook_hook_events(Hooks, Method);
    end;
  end;
end;

procedure TListViewHeader.InitWidget;
begin
  inherited InitWidget;
  Visible := not Hidden;
end;

function TListViewHeader.ListViewHandle: QListViewH;
begin
  Result := TCustomViewControl(Owner).Handle;
end;

procedure TListViewHeader.SetHidden(const Value: Boolean);
begin
  if FHidden <> Value then
  begin
    FHidden := Value;
    FHiddenChanging := True;
    try
      while QListView_columns(ListViewHandle) > 1 do
        QListView_removeColumn(ListViewHandle, 1);
      RecreateWidget;
      if Hidden then
      begin
        if QListView_columns(ListViewHandle) = 0 then
          QListView_addColumn(ListViewHandle, nil, 50);
        QListView_setColumnWidthMode(ListViewHandle, 0,
          QListViewWidthMode_Maximum);
      end
      else
      begin
        QListView_setShowSortIndicator(ListViewHandle,
          ViewControl.ShowColumnSortIndicators);
        if ViewControl.Columns.Count > 0 then
          QListView_setColumnWidthMode(ListViewHandle, 0,
            ColAutoSize[ViewControl.Columns[0].AutoSize]);
      end;
      ViewControl.RepopulateItems;
    finally
      FHiddenChanging := False;
    end;
  end;
end;

procedure TListViewHeader.SetSections(const Value: TListColumns);
begin
  inherited SetSections(Value);
end;

procedure TListViewHeader.Update;
begin
  if (not Hidden) and not (csDestroying in ViewControl.ComponentState) and
  HandleAllocated then
    QWidget_update(Handle);
end;

procedure TListViewHeader.UpdateWidgetShowing;
begin
  if HandleAllocated then
  begin
    if Hidden then
      QWidget_hide(QListView_header(ListViewHandle))
    else
      QWidget_show(QListView_header(ListViewHandle));
    QListView_triggerUpdate(ListViewHandle);
  end;
end;

function TListViewHeader.ViewControl: TCustomViewControl;
begin
  Result := TCustomViewControl(Owner);
end;

{ THeaderControl }

function THeaderControl.GetSections: THeaderSections;
begin
  Result := THeaderSections(inherited GetSections);
end;

procedure THeaderControl.CreateWidget;
begin
  FHandle := QHeader_create(ParentWidget, nil);
  Hooks := QHeader_hook_create(Handle);
end;

procedure THeaderControl.SetSections(const Value: THeaderSections);
begin
  inherited SetSections(Value);
end;

destructor THeaderControl.Destroy;
begin
  FSections.Free;
  inherited Destroy;
end;

procedure THeaderControl.InitWidget;
begin
  inherited InitWidget;
  QHeader_setTracking(Handle, FTracking);
end;

constructor THeaderControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Init(THeaderSection);
end;

constructor THeaderControl.Create(AOwner: TComponent; AHeaderSectionClass: THeaderSectionClass);
begin
  inherited Create(AOwner);
  Init(AHeaderSectionClass);
end;

procedure THeaderControl.Init(AHeaderSectionClass: THeaderSectionClass);
begin
  FSections := THeaderSections.Create(Self, AHeaderSectionClass);
end;

{ TListColumns }

function TListColumns.Add: TListColumn;
begin
  Result := TListColumn(inherited Add);
end;

procedure TListColumns.Added(var Item: TCollectionItem);
begin
  if not (Item is TListColumn) then
    Exit;
  if Assigned(ViewControl) then
  begin
    BeginUpdate;
    try
      ViewControl.RepopulateItems;
    finally
      EndUpdate;
    end;
  end;
end;

function TListColumns.GetItem(Index: Integer): TListColumn;
begin
  Result := TListColumn(inherited GetItem(Index));
end;

function TListColumns.GetViewControl: TCustomViewControl;
begin
  if FHeaderControl is TListViewHeader then
    Result := FHeaderControl.Owner as TCustomViewControl
  else
    Result := nil;
end;

procedure TListColumns.SetItem(Index: Integer; Value: TListColumn);
begin
  inherited SetItem(Index, Value);
end;

procedure TListColumns.Update(Item: TCollectionItem);
var
  I: Integer;
begin
  if Assigned(ViewControl) then
    if not ViewControl.FHeader.FDontResubmit then
    begin
      if not Assigned(Item) then
      begin
        for I := 0 to Count-1 do
          Items[I].Resubmit;
      end
      else if Item is TListColumn then
        TListColumn(Item).Resubmit;
      if not Assigned(Item) and not (csDestroying in ViewControl.ComponentState) then
        ViewControl.UpdateControl;
    end;
end;

{ TCustomHeaderSections }

constructor TCustomHeaderSections.Create(HeaderControl: TCustomHeaderControl;
  SectionClass: THeaderSectionClass);
begin
  inherited Create(SectionClass);
  FHeaderControl := HeaderControl;
end;

function TCustomHeaderSections.GetItem(Index: Integer): TCustomHeaderSection;
begin
  Result := TCustomHeaderSection(inherited GetItem(Index));
end;

function TCustomHeaderSections.GetOwner: TPersistent;
begin
  Result := FHeaderControl;
end;

procedure TCustomHeaderSections.SetItem(Index: Integer; Value: TCustomHeaderSection);
begin
  inherited SetItem(Index, Value);
end;

procedure TCustomHeaderSections.Update(Item: TCollectionItem);
var
  I: Integer;
begin
  if Owner is TCustomHeaderControl then
    if not TCustomHeaderControl(Owner).FDontResubmit then
    begin
      if not Assigned(Item) then
      begin
        for I := 0 to Count-1 do
          Items[I].Resubmit;
      end
      else if Item is TCustomHeaderSection then
        TCustomHeaderSection(Item).Resubmit;
      if TCustomHeaderControl(Owner).HandleAllocated then
        QWidget_repaint(TCustomHeaderControl(Owner).Handle);
    end;
end;

procedure TCustomHeaderSections.UpdateImages;
var
  I: Integer;
begin
  for I := 0 to Count-1 do
    Items[I].UpdateImage;
end;

{ TListItems }

function TListItems.Add: TListItem;
var
  After: TListItem;
begin
  if FItems.Count > 0 then
    After := Item[FItems.Count-1]
  else
    After := nil;
  Result := FListItemClass.Create(Self, nil, After);
  FItems.Add(Result);
  if Assigned(Owner) and Assigned(Owner.FOnInsert) then
    Owner.FOnInsert(Owner, Result);
end;

function TListItems.AddItem(Item: TListItem; Index: Integer): TListItem;
begin
  if Index < 0 then
    Index := 0
  else if Index >= Count then
    Index := Count-1;
  BeginUpdate;
  try
    if not Assigned(Item) then
      Result := FListItemClass.Create(Self, FItems[Index].Parent, nil)
    else
      Result := Item;
    FItems.Insert(Index, Result);
    if (Result <> Item) and Assigned(Item) then
      Result.Assign(Item);
  finally
    EndUpdate;
  end;
end;

constructor TListItems.Create(AOwner: TCustomViewControl);
begin
  inherited Create(AOwner);
  SetItemClass(TListItem);
end;

constructor TListItems.Create(AOwner: TCustomViewControl;
  AItemClass: TListItemClass);
begin
  inherited Create(AOwner);
  SetItemClass(AItemClass);
end;

procedure TListItems.DefineProperties(Filer: TFiler);

  function WriteItems: Boolean;
  var
    I: Integer;
    Items: TListItems;
  begin
    Items := TListItems(Filer.Ancestor);
    if (Items = nil) then
      Result := Count > 0
    else if (Items.Count <> Count) then
      Result := True
    else
    begin
      Result := False;
      for I := 0 to Count - 1 do
      begin
        Result := not Item[I].IsEqual(Items[I]);
        if Result then Break;
      end
    end;
  end;

begin
  inherited DefineProperties(Filer);
  Filer.DefineBinaryProperty('Data', ReadData, WriteData, WriteItems);
end;

function TListItems.FindItem(ItemH: QListViewItemH): TListItem;
var
  Temp: TCustomViewItem;
begin
  Temp := FindViewItem(ItemH);
  if Temp is TListItem then
    Result := TListItem(Temp)
  else
    Result := nil;
end;

function TListItems.GetItem(Index: Integer): TListItem;
begin
  Result := TListItem(inherited GetItem(Index));
end;

function TListItems.GetItemsOwner: TCustomListView;
begin
  Result := FOwner as TCustomListView;
end;

function TListItems.Insert(Index: Integer): TListItem;
begin
  Result := AddItem(nil, Index);
end;

type
  PItemHeader = ^TItemHeader;
  TItemHeader = packed record
    Size, Count: Integer;
    Items: record end;
  end;
  PItemInfo = ^TItemInfo;
  TItemInfo = packed record
    ImageIndex: Integer;
    StateIndex: Integer;
    OverlayIndex: Integer;
    SubItemCount: Integer;
    Data: Pointer;
    Caption: string[255];
  end;
  ShortStr = string[255];
  PShortStr = ^ShortStr;

procedure TListItems.ReadData(Stream: TStream);
var
  I, J, Size, L, Len: Integer;
  ItemHeader: PItemHeader;
  ItemInfo: PItemInfo;
  PStr: PShortStr;
  PInt: PInteger;
begin
  Clear;
  Stream.ReadBuffer(Size, SizeOf(Integer));
  ItemHeader := AllocMem(Size);
  try
    Stream.ReadBuffer(ItemHeader^.Count, Size - SizeOf(Integer));
    ItemInfo := @ItemHeader^.Items;
    PStr := nil;
    for I := 0 to ItemHeader^.Count - 1 do
    begin
      with Add do
      begin
        Caption := ItemInfo^.Caption;
        ImageIndex := ItemInfo^.ImageIndex;
        Data := ItemInfo^.Data;
        PStr := @ItemInfo^.Caption;
        Inc(Integer(PStr), Length(PStr^) + 1);
        Len := 0;
        for J := 0 to ItemInfo^.SubItemCount - 1 do
        begin
          SubItems.Add(PStr^);
          L := Length(PStr^);
          Inc(Len, L + 1);
          Inc(Integer(PStr), L + 1);
        end;
      end;
      Inc(Integer(ItemInfo), SizeOf(TItemInfo) - 255 +
        Length(ItemInfo.Caption) + Len);
    end;
    //read subitem images, if present.
    if PChar(PStr) - PChar(ItemHeader) < Size then
    begin
      PInt := Pointer(PStr);
      for I := 0 to Count - 1 do
        with Item[I] do
          if Assigned(FSubItems) then
            for J := 0 to SubItems.Count - 1 do
            begin
              SubItemImages[J] := PInt^;
              Inc(PInt);
            end;
    end;
  finally
    FreeMem(ItemHeader, Size);
  end;
end;

procedure TListItems.SetItem(Index: Integer; const Value: TListItem);
begin
  inherited SetItem(Index, Value);
end;

procedure TListItems.SetItemClass(AListItemClass: TListItemClass);
begin
  FListItemClass := AListItemClass;
end;

procedure TListItems.WriteData(Stream: TStream);
var
  I, J, Size, L, Len: Integer;
  ItemHeader: PItemHeader;
  ItemInfo: PItemInfo;
  PStr: PShortStr;
  PInt: PInteger;

  function GetLength(const S: string): Integer;
  begin
    Result := Length(S);
    if Result > 255 then Result := 255;
  end;

begin
  Size := SizeOf(TItemHeader);
  for I := 0 to Count - 1 do
  begin
    L := GetLength(Item[I].Caption) + 1;
    for J := 0 to Item[I].SubItems.Count - 1 do
    begin
      Inc(L, GetLength(Item[I].SubItems[J]) + 1);
      Inc(L, SizeOf(Integer));
    end;
    Inc(Size, SizeOf(TItemInfo) - 255 + L);
  end;
  ItemHeader := AllocMem(Size);
  try
    ItemHeader^.Size := Size;
    ItemHeader^.Count := Count;
    ItemInfo := @ItemHeader^.Items;
    PStr := nil;
    for I := 0 to Count - 1 do
    begin
      with Item[I] do
      begin
        ItemInfo^.Caption := Caption;
        ItemInfo^.ImageIndex := ImageIndex;
        ItemInfo^.OverlayIndex := -1 {OverlayIndex};
        ItemInfo^.StateIndex := -1 {StateIndex};
        ItemInfo^.Data := Data;
        ItemInfo^.SubItemCount := SubItems.Count;
        PStr := @ItemInfo^.Caption;
        Inc(Integer(PStr), Length(ItemInfo^.Caption) + 1);
        Len := 0;
        for J := 0 to SubItems.Count - 1 do
        begin
          PStr^ := SubItems[J];
          L := Length(PStr^);
          Inc(Len, L + 1);
          Inc(Integer(PStr), L + 1);
        end;
      end;
      Inc(Integer(ItemInfo), SizeOf(TItemInfo) - 255 +
        Length(ItemInfo^.Caption) + Len);
    end;
    //write SubItem images.
    PInt := Pointer(PStr);
    for I := 0 to Count - 1 do
    begin
      with Item[I] do
        for J := 0 to SubItems.Count - 1 do
        begin
          PInt^ := SubItemImages[J];
          Inc(PInt);
        end;
    end;
    Stream.WriteBuffer(ItemHeader^, Size);
  finally
    FreeMem(ItemHeader, Size);
  end;
end;

{ THeaderSection }

destructor THeaderSection.Destroy;
begin
  if not (csDestroying in Header.ComponentState) and Header.HandleAllocated then
    QHeader_removeLabel(Header.Handle, QHeader_mapToIndex(Header.Handle, Index));
  inherited Destroy;
end;

procedure THeaderSection.AssignTo(Dest: TPersistent);
begin
  inherited AssignTo(Dest);
  if Dest is THeaderSection then
    THeaderSection(Dest).Text := Text;
end;

{$IF not (defined(LINUX) and defined(VER140))}
function THeaderSection.GetText: WideString;
begin
  Result := FText;
end;
{$IFEND}


procedure THeaderSection.SetText(const Value: WideString);
begin
  if Text <> Value then
  begin
    FText := Value;
    if Header.HandleAllocated then
      QHeader_setLabel(Header.Handle, QHeader_mapToIndex(Header.Handle, Index),
        PWideString(@FText), CalcSize);
  end;
end;

procedure THeaderSection.SetWidthVal(const Value: Integer);
begin
  FWidth := Value;
  if Header.HandleAllocated then
    QHeader_setLabel(Header.Handle, QHeader_mapToIndex(Header.Handle, Index),
      PWideString(@FText), CalcSize);
end;

{ TTreeNode }

constructor TTreeNode.Create(AOwner: TCustomViewItems; AParent:
  TCustomViewItem = nil; After: TCustomViewItem = nil);
begin
  inherited Create(AOwner, AParent, After);
  FSelectedIndex := -1;
end;

destructor TTreeNode.Destroy;
begin
  if ViewControlValid then
  begin
    if TreeView.FLastNode = Self then
      TreeView.FLastNode := TTreeNode(FPrevItem);
    if Assigned(TreeView.FOnDeletion) then
      TreeView.FOnDeletion(TreeView, Self);
  end;
  inherited Destroy;
end;

function TTreeNode.AlphaSort(Ascending: Boolean): Boolean;

  procedure UpdateNodes(ANode: TCustomViewItem);
  var
    TempNext: TCustomViewItem;
    TempPrev: TCustomViewItem;
    TempItem: QListViewItemH;
  begin
    if Assigned(Owner) then
    begin
      TempItem := QListViewItem_firstChild(ANode.Handle);
      if Assigned(TempItem) then
      begin
        TempPrev := Owner.FindItem(TempItem);
        if Assigned(TempPrev) then
        begin
          TempPrev.FPrevItem := nil;
          while Assigned(TempItem) do
          begin
            UpdateNodes(TempPrev);
            TempItem := QListViewItem_nextSibling(TempItem);
            if not Assigned(TempItem) then
              Break;
            TempNext := Owner.FindItem(TempItem);
            TempPrev.FNextItem := TempNext;
            if Assigned(TempNext) then
              TempNext.FPrevItem := TempPrev;
            TempPrev := TempNext;
          end;
          ANode.FLastChild := TempPrev;
        end;
      end;
    end;
  end;

begin
  Result := HandleAllocated;
  if Result then
  begin
    QListViewItem_sortChildItems(Handle, 0, Ascending);
    UpdateNodes(Self);
    if ViewControlValid then
      ViewControl.UpdateControl;
  end;
end;

procedure TTreeNode.AssignTo(Dest: TPersistent);
var
  Node: TTreeNode;
begin
  inherited AssignTo(Dest);
  if Dest is TTreeNode then
  begin
    Node := TTreeNode(Dest);
    Node.Text := Text;
    Node.HasChildren := HasChildren;
    Node.SelectedIndex := SelectedIndex;
  end;
end;

procedure TTreeNode.Collapse(Recurse: Boolean);
begin
  ExpandItem(False, Recurse);
end;

function TTreeNode.CompareCount(CompareMe: Integer): Boolean;
var
  Count: integer;
  Node: TTreeNode;
Begin
  Count := 0;
  Result := False;
  Node := GetFirstChild;
  while Node <> nil do
  begin
    Inc(Count);
    Node := Node.GetNextChild(Node);
    if Count > CompareMe then
      Exit;
  end;
  if Count = CompareMe then
    Result := True;
end;

procedure TTreeNode.Delete;
begin
  if not Deleting then
    Free;
end;

procedure TTreeNode.DeleteChildren;
var
  Node: TTreeNode;
begin
  Node := getFirstChild;
  while Node <> nil do
  begin
    Node.Free;
    Node := getFirstChild;
  end;
end;

function TTreeNode.DoCanExpand(Expand: Boolean): Boolean;
begin
  Result := False;
  if HasChildren then
  begin
    if Expand then
      Result := TreeView.CanExpand(Self)
    else
      Result := TreeView.CanCollapse(Self);
  end;
end;

function TTreeNode.EditText: Boolean;
begin
  if ViewControlValid then
  begin
    Selected := True;
    ViewControl.EditItem;
  end;
  Result := Assigned(ViewControl.FEditor) and ViewControl.FEditor.FEditing;
end;

procedure TTreeNode.Expand(Recurse: Boolean);
begin
  ExpandItem(True, Recurse);
end;

procedure TTreeNode.ExpandItem(Expand, Recurse: Boolean);
var
  Node: TTreeNode;

begin
  if Recurse then
  begin
    Node := Self; 
    repeat
      Node.ExpandItem(Expand, False);
      Node := Node.GetNext;
    until (Node = nil) or (not Node.HasAsParent(Self));
  end
  else
    Expanded := Expand;
end;

function TTreeNode.GetAbsoluteIndex: Integer;
var
  Node: TTreeNode;
begin
  Result := -1;
  Node := Self;
  while Node <> nil do
  begin
    Inc(Result);
    Node := Node.GetPrev;
  end;
end;

function TTreeNode.GetCount: Integer;
var
  Node: TTreeNode;
begin
  Result := 0;
  Node := GetFirstChild;
  while Node <> nil do
  begin
    Inc(Result);
    Node := Node.GetNextChild(Node);
  end;
end;

{$IF not (defined(LINUX) and defined(VER140))}
function TTreeNode.GetSelected: Boolean;
begin
  Result := inherited GetSelected;
end;

procedure TTreeNode.SetSelected(const Value: Boolean);
begin
  inherited SetSelected(Value);
end;

function TTreeNode.GetExpandable: Boolean;
begin
  Result := FExpandable;
end;

procedure TTreeNode.SetExpandable(const Value: Boolean);
begin
  inherited SetExpandable(Value);
end;

function TTreeNode.GetCaption: WideString;
begin
  Result := FText;
end;

procedure TTreeNode.SetCaption(const Value: WideString);
begin
  inherited SetCaption(Value);
end;
{$IFEND}

function TTreeNode.GetDropTarget: Boolean;
begin
  if ViewControlValid then
    Result := TreeView.DropTarget = Self
  else
    Result := False;
end;

function TTreeNode.getFirstChild: TTreeNode;
begin
  if HandleAllocated then
    Result := Owner.FindItem(QListViewItem_firstChild(Handle))
  else
    Result := nil;
end;

function TTreeNode.GetIndex: Integer;
var
  Node: TTreeNode;
begin
  Result := -1;
  Node := Self;
  while Node <> nil do
  begin
    Inc(Result);
    Node := Node.GetPrevSibling;
  end;
end;

function TTreeNode.GetItem(Index: Integer): TTreeNode;
begin
  Result := GetFirstChild;
  while Assigned(Result) and (Index > 0) do
  begin
    Result := GetNextChild(Result);
    Dec(Index);
  end;
  if Result = nil then
    TreeViewError(Format(SListIndexError,[Index]));
end;

function TTreeNode.GetLastChild: TTreeNode;
begin
  if FLastChild is TTreeNode then
    Result := TTreeNode(FLastChild)
  else
    Result := nil;
end;

function TTreeNode.GetLevel: Integer;
begin
  if HandleAllocated then
    Result := QListViewItem_Depth(Handle)
  else
    Result := -1;
end;

function TTreeNode.GetNext: TTreeNode;
var
  ChildNodeID, ParentID: QListViewItemH;
begin
  Result := nil;
  if HandleAllocated then
  begin
    ChildNodeID := QListViewItem_firstChild(Handle);

    if ChildNodeID = nil then
      ChildNodeID := QListViewItem_nextSibling(Handle);
    ParentID := Handle;
    while (ChildNodeID = nil) and (ParentID <> nil) do
    begin
      ParentID := QListViewItem_parent(ParentID);
      if ParentID = nil then
        Break;
      ChildNodeID := QListViewItem_nextSibling(ParentID);
    end;
    Result := TTreeNodes(FOwner).FindItem(ChildNodeID);
  end;
end;

function TTreeNode.GetNextChild(Value: TTreeNode): TTreeNode;
begin
  if Value <> nil then
    Result := Value.GetNextSibling
  else
    Result := nil;
end;

function TTreeNode.getNextSibling: TTreeNode;
begin
  if HandleAllocated then
    Result := Owner.FindItem(QListViewItem_nextSibling(Handle))
  else
    Result := nil;
end;

function TTreeNode.GetNextVisible: TTreeNode;
begin
  Result := GetNext;
  while Assigned(Result) and not Result.IsNodeVisible do
    Result := Result.GetNext;
end;

function TTreeNode.GetNodeOwner: TTreeNodes;
begin
  Result := FOwner as TTreeNodes;
end;

function TTreeNode.GetParent: TTreeNode;
begin
  Result := FParent as TTreeNode;
end;

function TTreeNode.GetPrev: TTreeNode;
var
  Node: TTreeNode;
begin
  Result := GetPrevSibling;
  if Result <> nil then
  begin
    Node := Result;
    repeat
      Result := Node;
      Node := Result.GetLastChild;
    until Node = nil;
  end else
    Result := Parent;
end;

function TTreeNode.GetPrevChild(Value: TTreeNode): TTreeNode;
begin
  if Value <> nil then
    Result := Value.GetPrevSibling
  else
    Result := nil;
end;

function TTreeNode.getPrevSibling: TTreeNode;
begin
  Result := nil;
  if Assigned(Owner) then
    Result := Owner.FindPrevSibling(Self);
end;

function TTreeNode.GetPrevVisible: TTreeNode;
begin
  Result := GetPrev;
  while Assigned(Result) and not Result.IsNodeVisible do
    Result := Result.GetPrev;
end;

function TTreeNode.GetTreeView: TCustomTreeView;
begin
  Result := FOwner.FOwner as TCustomTreeView;
end;

function TTreeNode.HasAsParent(Value: TTreeNode): Boolean;
begin
  if Value <> nil then
  begin
    if Parent = nil then
      Result := False
    else if Parent = Value then
      Result := True
    else
      Result := Parent.HasAsParent(Value);
  end
  else
    Result := True;
end;

function TTreeNode.IndexOf(Value: TTreeNode): Integer;
var
  Node: TTreeNode;
begin
  Result := -1;
  Node := GetFirstChild;
  while Node <> nil do
  begin
    Inc(Result);
    if Node = Value then
      Break;
    Node := GetNextChild(Node);
  end;
  if Node = nil then
    Result := -1;
end;

procedure TTreeNode.ImageIndexChange(ColIndex: Integer; NewIndex: Integer);
var
  Pixmap: QPixmapH;
begin
  if HandleAllocated and ViewControlValid and Assigned(ViewControl.Images) then
  begin
    if Selected then
    begin
      Pixmap := ViewControl.Images.GetPixmap(SelectedIndex);
      if Assigned(Pixmap) then
      begin
        QListViewItem_setPixmap(Handle, 0, Pixmap);
        Exit;
      end;
    end;
    inherited ImageIndexChange(ColIndex, NewIndex);
  end;
end;

function TTreeNode.IsEqual(Node: TTreeNode): Boolean;
begin
  Result := (Text = Node.Text) and (Data = Node.Data);
end;

function TTreeNode.IsNodeVisible: Boolean;
var
  R: TRect;
begin
  if HandleAllocated then
  begin
    QListView_itemRect(Owner.Owner.Handle, @R, Handle);
    Result := not ((R.Right = -1) and (R.Bottom = -1));
  end
  else
    Result := False;
end;

procedure TTreeNode.MoveTo(Destination: TTreeNode; Mode: TNodeAttachMode);
var
  OldOnChange: TTVChangedEvent;
  NextSib: TTreeNode;
begin
  OldOnChange := TreeView.OnChange;
  TreeView.OnChange := nil;
  Owner.BeginUpdate;
  try
    if not Assigned(Destination) or
    (Assigned(Destination) and Destination.HasAsParent(Self))
    and (Destination <> Self) then
      Exit;

    case Mode of
      naAdd:
      begin
        Parent := Destination.Parent;
        if not Assigned(Parent) then
        begin
          if ViewControlValid then
          begin
            QListView_insertItem(ViewControl.Handle, Handle);
            if Assigned(TreeView.FLastNode) then
            begin
              QListViewItem_moveItem(Handle, TreeView.FLastNode.Handle);
              if Assigned(FPrevItem) then
                FPrevItem.FNextItem := FNextItem;
              if Assigned(FNextItem) then
                FNextItem.FPrevItem := FPrevItem;
              FPrevItem := TreeView.FLastNode;
              TreeView.FLastNode.FNextItem := Self;
            end;
            FNextItem := nil;
            TreeView.FLastNode := Self;
          end;
        end;
      end;
      naAddFirst:
      begin
        Parent := Destination.Parent;
        if not Assigned(Parent) then
        begin
          if ViewControlValid then
          begin
            QListView_insertItem(ViewControl.Handle, Handle);
            NextSib := TreeView.Items.FindItem(QListView_firstChild(ViewControl.Handle));
          end
          else
            NextSib := nil;
        end
        else
          NextSib := Parent.getFirstChild;
        if Assigned(NextSib) then
        begin
          QListViewItem_moveItem(Handle, NextSib.Handle);
          QListViewItem_moveItem(NextSib.Handle, Handle);
          if Assigned(FPrevItem) then
            FPrevItem.FNextItem := FNextItem;
          if Assigned(FNextItem) then
            FNextItem.FPrevItem := FPrevItem;
          FPrevItem := nil;
          FNextItem := NextSib;
          NextSib.FPrevItem := Self;
        end;
      end;
      naAddChild:
        Parent := Destination;
      naAddChildFirst:
      begin
        Parent := Destination;
        if Parent.FLastChild = Self then
          Parent.FLastChild := FPrevItem;
        if Assigned(FPrevItem) then
          FPrevItem.FNextItem := FNextItem;
        if Assigned(FNextItem) then
          FNextItem.FPrevItem := FPrevItem;
        FPrevItem := nil;
        FNextItem := Parent.getFirstChild;
        if Assigned(FNextItem) then
        begin
          FNextItem.FPrevItem := Self;
          QListViewItem_moveItem(Handle, FNextItem.Handle);
          QListViewItem_moveItem(FNextItem.Handle, Handle);
        end
        else
          Parent.FLastChild := Self;
      end;
      naInsert:
      begin
        Parent := Destination.Parent;
        if Assigned(FPrevItem) then
          FPrevItem.FNextItem := FNextItem;
        if Assigned(FNextItem) then
          FNextItem.FPrevItem := FPrevItem;
        FPrevItem := Destination.FPrevItem;
        FNextItem := Destination;
        FNextItem.FPrevItem := Self;
        if Assigned(FPrevItem) then
          FPrevItem.FNextItem := Self;
        if not Assigned(Parent) and ViewControlValid then
          QListView_insertItem(ViewControl.Handle, Handle);
        if Assigned(FNextItem) then
        begin
          QListViewItem_moveItem(Handle, FNextItem.Handle);
          QListViewItem_moveItem(FNextItem.Handle, Handle);
        end;
      end;
    end;

    if Assigned(Parent) then
    begin
      Parent.HasChildren := True;
      Parent.Expanded := True;
    end;
  finally
    TreeView.OnChange := OldOnChange;
    Owner.EndUpdate;
  end;
end;

procedure TTreeNode.ReadData(Stream: TStream; Info: PNodeInfo);
var
  I, Size, ItemCount: Integer;
  PStr: PShortStr;
  PInt: PInteger;
begin
  Stream.ReadBuffer(Size, SizeOf(Size));
  Stream.ReadBuffer(Info^, Size);
  Text := Info^.Text;
  ImageIndex := Info^.ImageIndex;
  SelectedIndex := Info^.SelectedIndex;
  Data := Info^.Data;
  ItemCount := Info^.Count;

  PStr := @Info^.Text;
  Inc(Integer(PStr), Length(PStr^) + 1);
  for I := 0 to Info^.SubItemCount - 1 do
  begin
    SubItems.Add(PStr^);
    Integer(PStr) := Integer(PStr) + (Length(PStr^) + 1);
  end;

  if (Size - (Integer(@PStr^[0]) - Integer(Info))) <> 0 then
  begin
    PInt := Pointer(PStr);
    for I := 0 to SubItems.Count - 1 do
    begin
      SubItemImages[I] := PInt^;
      Inc(PInt);
    end;
  end;

  for I := 0 to ItemCount - 1 do
    Owner.AddChild(Self, '').ReadData(Stream, Info);
end;

procedure TTreeNode.SetItem(Index: Integer; const Value: TTreeNode);
begin
  Item[Index].Assign(Value);
end;

procedure TTreeNode.SetNodeParent(const Value: TTreeNode);
begin
  if Parent <> Value then
    SetParent(Value);
end;

procedure TTreeNode.SetSelectedIndex(const Value: Integer);
begin
  if FSelectedIndex <> Value then
  begin
    FSelectedIndex := Value;
    if Selected then
      ImageIndexChange(0, ImageIndex);
  end;
end;

procedure TTreeNode.WriteData(Stream: TStream; Info: PNodeInfo);

  function GetLength(const S: string): Integer;
  begin
    Result := Length(S);
    if Result > 255 then Result := 255;
  end;

var
  I, Size, L, ItemCount: Integer;
  PStr: PShortStr;
  PInt: PInteger;
begin
  L := GetLength(Text);
  for I := 0 to SubItems.Count - 1 do
  begin
    Inc(L, GetLength(SubItems[I]) + 1);
    Inc(L, SizeOf(Integer));
  end;
  Size := SizeOf(TNodeInfo) + L - 255;
  Info^.Text := Text;
  Info^.ImageIndex := ImageIndex;
  Info^.SelectedIndex := SelectedIndex;
  Info^.Data := Data;
  ItemCount := Count;
  Info^.Count := ItemCount;
  Info^.SubItemCount := SubItems.Count;

  PStr := @Info^.Text;
  Inc(Integer(PStr), Length(Info^.Text) + 1);

  for I := 0 to SubItems.Count - 1 do
  begin
    PStr^ := SubItems[I];
    Integer(PStr) := Integer(PStr) + (Length(PStr^) + 1);
  end;
  //write SubItem images.
  PInt := Pointer(PStr);
  for I := 0 to SubItems.Count - 1 do
  begin
    PInt^ := SubItemImages[I];
    Inc(PInt);
  end;
  Stream.WriteBuffer(Size, SizeOf(Size));
  Stream.WriteBuffer(Info^, Size);

  for I := 0 to ItemCount - 1 do
    Item[I].WriteData(Stream, Info);
end;

{ TTreeNodes }

function TTreeNodes.Add(Node: TTreeNode; const S: WideString): TTreeNode;
begin
  Result := AddObject(Node, S, nil);
end;

function TTreeNodes.AddChild(Node: TTreeNode; const S: WideString): TTreeNode;
begin
  Result := AddChildObject(Node, S, nil);
end;

function TTreeNodes.AddChildFirst(Node: TTreeNode;
  const S: WideString): TTreeNode;
begin
  Result := AddChildObjectFirst(Node, S, nil);
end;

function TTreeNodes.AddChildObject(Node: TTreeNode; const S: WideString;
  Ptr: Pointer): TTreeNode;
begin
  Result := InternalAddObject(Node, S, Ptr, taAdd);
end;

function TTreeNodes.AddChildObjectFirst(Node: TTreeNode; const S: WideString;
  Ptr: Pointer): TTreeNode;
begin
  Result := InternalAddObject(Node, S, Ptr, taAddFirst);
end;

function TTreeNodes.AddFirst(Node: TTreeNode; const S: WideString): TTreeNode;
begin
  Result := AddObjectFirst(Node, S, nil);
end;

function TTreeNodes.AddObject(Node: TTreeNode; const S: WideString;
  Ptr: Pointer): TTreeNode;
begin
  if Assigned(Node) then
    Node := Node.Parent;
  Result := InternalAddObject(Node, S, Ptr, taAdd);
end;

function TTreeNodes.AddObjectFirst(Node: TTreeNode; const S: WideString;
  Ptr: Pointer): TTreeNode;
begin
  if Assigned(Node) then
    Node := Node.Parent;
  Result := InternalAddObject(Node, S, Ptr, taAddFirst);
end;

procedure TTreeNodes.Assign(Dest: TPersistent);
var
  TreeNodes: TTreeNodes;
  MemStream: TMemoryStream;
begin
  if Dest is TTreeNodes then
  begin
    TreeNodes := TTreeNodes(Dest);
    Clear;
    MemStream := TMemoryStream.Create;
    try
      TreeNodes.WriteData(MemStream);
      MemStream.Position := 0;
      ReadData(MemStream);
    finally
      MemStream.Free;
    end;
  end
  else
    inherited Assign(Dest);
end;

procedure TTreeNodes.Clear;
begin
  BeginUpdate;
  try
    FItems.Clear;
    if Owner.HandleAllocated then
      QListView_clear(Owner.Handle);
  finally
    EndUpdate;
  end;
end;

function TTreeNodes.CreateNode(ParentNode, AfterNode: TTreeNode): TTreeNode;
begin
  Result := FNodeClass.Create(Self, ParentNode, AfterNode);
end;

procedure TTreeNodes.DefineProperties(Filer: TFiler);

  function WriteNodes: Boolean;
  var
    I: Integer;
    Nodes: TTreeNodes;
  begin
    Nodes := TTreeNodes(Filer.Ancestor);
    if Nodes = nil then
      Result := Count > 0
    else if Nodes.Count <> Count then
      Result := True
    else
    begin
      Result := False;
      for I := 0 to Count - 1 do
      begin
        Result := not Item[I].IsEqual(Nodes[I]);
        if Result then Break;
      end
    end;
  end;

begin
  inherited DefineProperties(Filer);
  Filer.DefineBinaryProperty('Data', ReadData, WriteData, WriteNodes);
end;

procedure TTreeNodes.Delete(Node: TTreeNode);
begin
  if Assigned(Node) then
    Node.Delete;
end;

function TTreeNodes.FindItem(ItemH: QListViewItemH): TTreeNode;
var
  Temp: TCustomViewItem;
begin
  Temp := FindViewItem(ItemH);
  if Temp is TTreeNode then
    Result := TTreeNode(Temp)
  else
    Result := nil;
end;

function TTreeNodes.FindPrevSibling(ANode: TTreeNode): TTreeNode;
var
  Node: TTreeNode;
  Node2: TTreeNode;
begin
  Result := nil;
  if ANode.FPrevItem is TTreeNode then
    Result := TTreeNode(ANode.FPrevItem);
  if not Assigned(Result) then
  begin
    if Assigned(ANode.Parent) then
      Node := ANode.Parent.getFirstChild
    else
      Node := GetFirstNode;

    if Node <> ANode then
    begin
      while Assigned(Node) do
      begin
        Node2 := Node;
        Node := Node.getNextSibling;
        if Node = ANode then
        begin
          Result := Node2;
          Exit;
        end;
      end;
    end;
  end;
end;

function TTreeNodes.GetFirstNode: TTreeNode;
begin
  if Owner.HandleAllocated then
    Result := FindItem(QListView_firstChild(Handle))
  else if Count > 0 then
    Result := Item[0]
  else
    Result := nil;
end;

function TTreeNodes.GetItem(Index: Integer): TTreeNode;
begin
  Result := TTreeNode(inherited GetItem(Index));
end;

function TTreeNodes.GetNode(ItemH: QListViewItemH): TTreeNode;
begin
  Result := FindItem(ItemH);
end;

function TTreeNodes.GetNodesOwner: TCustomTreeView;
begin
  Result := FOwner as TCustomTreeView;
end;

function TTreeNodes.Insert(Node: TTreeNode; const S: WideString): TTreeNode;
begin
  Result := InternalAddObject(Node, S, nil, taInsert);
end;

function TTreeNodes.InsertObject(Node: TTreeNode; const S: WideString;
  Ptr: Pointer): TTreeNode;
begin
  if Node <> nil then
    Node := Node.Parent;
  Result := InternalAddObject(Node, S, Ptr, taInsert);
end;

function TTreeNodes.InternalAddObject(Node: TTreeNode; const S: WideString;
  Ptr: Pointer; AddMode: TAddMode): TTreeNode;
var
  ParentNode, AfterNode: TTreeNode;
begin
  Result := nil;
  ParentNode := Node;
  AfterNode := nil;

  try
    case AddMode of
      taAdd:
        if Assigned(ParentNode) then
          AfterNode := ParentNode.GetLastChild
        else if Assigned(Owner) then
          AfterNode := Owner.FLastNode;
      taInsert:
      begin
        if Assigned(Node) then
          ParentNode := Node.Parent
        else
          ParentNode := nil;
        if Assigned(Node) then
          AfterNode := Node.getPrevSibling;
      end;
    end;

    Result := CreateNode(ParentNode, AfterNode);
    FItems.Add(Result);
    if (AddMode = taAdd) then
      if not Assigned(Result.Parent) and Assigned(Owner) then
        Owner.FLastNode := Result
      else if Assigned(Result.Parent) then
        Result.Parent.FLastChild := Result;
    if Assigned(Result.Parent) then
    begin
      if not Assigned(Result.Parent.FLastChild) then
        Result.Parent.FLastChild := Result;
      Result.Parent.HasChildren := True;
    end;
    Result.Data := Ptr;
    Result.Text := S;
    if Assigned(Owner) and Owner.Visible and (FUpdateCount = 0) then
      if not Assigned(Result.Parent) or
      (Assigned(Result.Parent) and Result.Parent.Expanded) then
        Result.MakeVisible(False);
    if Assigned(Owner.FOnInsert) then
      Owner.FOnInsert(Owner, Result);
  except
    Result.Free;
    raise;
  end;
end;

procedure TTreeNodes.ReadData(Stream: TStream);
var
  I, Count: Integer;
  NodeInfo: TNodeInfo;
begin
  if Owner.HandleAllocated then BeginUpdate;
  try
    Clear;
    Stream.ReadBuffer(Count, SizeOf(Count));
    for I := 0 to Count - 1 do
      Add(nil, '').ReadData(Stream, @NodeInfo);
  finally
    if Owner.HandleAllocated then EndUpdate;
  end;
end;

procedure TTreeNodes.WriteData(Stream: TStream);
var
  I: Integer;
  Node: TTreeNode;
  NodeInfo: TNodeInfo;
begin
  I := 0;
  Node := GetFirstNode;
  while Node <> nil do
  begin
    Inc(I);
    Node := Node.GetNextSibling;
  end;
  Stream.WriteBuffer(I, SizeOf(I));
  Node := GetFirstNode;
  while Node <> nil do
  begin
    Node.WriteData(Stream, @NodeInfo);
    Node := Node.GetNextSibling;
  end;
  Stream.Position := 0;
end;

procedure TTreeNodes.SetNodeClass(NewNodeClass: TTreeNodeClass);
begin
  FNodeClass := NewNodeClass;
end;

{ TListItem }

destructor TListItem.Destroy;
begin
  if ViewControlValid and Assigned(ListView.FOnDeletion) then
    ListView.FOnDeletion(ListView, Self);
  inherited Destroy;
end;

function TListItem.IsEqual(Item: TListItem): Boolean;
begin
  Result := (Caption = Item.Caption) and (Data = Item.Data);
end;

{$IF not (defined(LINUX) and defined(VER140))}
function TListItem.GetCaption: WideString;
begin
  Result := FText;
end;

procedure TListItem.SetCaption(Value: WideString);
begin
  inherited SetCaption(Value);
end;
{$IFEND}

function TListItem.GetListView: TCustomListView;
begin
  Result := Owner.FOwner as TCustomListView;
end;

function TListItem.GetOwnerlist: TListItems;
begin
  Result := FOwner as TListItems;
end;

{ TCustomSpinEdit }

constructor TCustomSpinEdit.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  TabStop := True;
  Palette.ColorRole := crBase;
  Palette.TextColorRole := crText;
  Color := clBase;
  Height := 23;
  InputKeys := [ikArrows];
end;

procedure TCustomSpinEdit.StepUp;
begin
  QSpinBox_stepUp(Handle);
end;

procedure TCustomSpinEdit.StepDown;
begin
  QSpinBox_stepDown(Handle);
end;

function TCustomSpinEdit.GetHandle: QClxSpinBoxH;
begin
  HandleNeeded;
  Result := QClxSpinBoxH(FHandle);
end;

function TCustomSpinEdit.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
var
  R: TRect;
  P: TPoint;
begin
  { Since Qt is not sending any messages for the up or down button when disabled
    we decided to only show any popup menu if a right click happens to the left
    of the buttons. }
  if (QEvent_type(Event) = QEventType_MouseButtonPress) and
    (QMouseEvent_button(QMouseEventH(Event)) = ButtonState_RightButton) then
    begin
      QWidget_geometry(QWidgetH(FUpButtonHandle), @R);
      P.X := QMouseEvent_x(QMouseEventH(Event));
      P.Y := QMouseEvent_y(QMouseEventH(Event));
      if Sender <> Handle then
        QWidget_mapToParent(QWidgetH(Sender), @P, @P);
      if P.X >= R.Left then
      begin
        Result := False;
        Exit;
      end;
    end;

  if (Sender = FEditHandle) or
      (Sender = FUpButtonHandle) or
      (Sender = FDownButtonHandle) then
  begin
    Result := inherited EventFilter(Sender, Event);

    { Internal Qt aggregated controls should return False (not handled) at this
      point but there are a few exceptions:

      1. The right mouse press: This is handled in EventFilter depending
         on whether the PopupMenu was activated.
      2. Enter and Leave messages should only come from the container. }
    if ((QEvent_type(Event) = QEventType_MouseButtonPress) and
      (QMouseEvent_button(QMouseEventH(Event)) = ButtonState_RightButton)) then
        Exit
    else
      if (QEvent_type(Event) = QEventType_Enter) or
          (QEvent_type(Event) = QEventType_Leave) then
      begin
        { When the focus leaves we force the button up. There is the very likely
          chance that if the OnClick event displays a modal form and the mouse
          click was on a button then it would keep incrementing the value }
        if (Sender = FUpButtonHandle) or (Sender = FDownButtonHandle) then
          QButton_setDown(QButtonH(Sender), False);
        Result := True;
      end else
        Result := False;
  end
  else
    Result := inherited EventFilter(Sender, Event);
end;

procedure TCustomSpinEdit.CreateWidget;
var
  Method: TMethod;
begin
  FHandle := QClxSpinBox_create(0, 100, 1, ParentWidget, nil);
  Hooks := QSpinBox_hook_create(FHandle);

  FEditHandle := QClxSpinBox_editor(Handle);
  FUpButtonHandle := QClxSpinBox_upButton(Handle);
  FDownButtonHandle := QClxSpinBox_downButton(Handle);

  FEditHook := QWidget_hook_create(FEditHandle);
  FButtonUpHook := QWidget_hook_create(FUpButtonHandle);
  FButtonDownHook := QWidget_hook_create(FDownButtonHandle);

  { How to handle Qt aggregated internal controls:

    1. Hook each internal control to point to the MainEventFilter.
      ( You get events first so squash ones you don't want QT to process
       and let the others through. )
    2. Call QClxObjectMap_add for each control passing in the handle and a
      reference to the host control cast as an Integer.
    3. Call QWidget_setMouseTracking for each control with the handle and True.
      ( Qt has this off by default. This allows us to get mouse move messages
      even when the mouse button is not pressed. ) }
  TEventFilterMethod(Method) := MainEventFilter;
  Qt_hook_hook_events(FEditHook, Method);
  Qt_hook_hook_events(FButtonUpHook, Method);
  Qt_hook_hook_events(FButtonDownHook, Method);

  QClxObjectMap_add(FEditHandle, Integer(Self));
  QClxObjectMap_add(FUpButtonHandle, Integer(Self));
  QClxObjectMap_add(FDownButtonHandle, Integer(Self));

  QWidget_setMouseTracking(FEditHandle, True);
  QWidget_setMouseTracking(FUpButtonHandle, True);
  QWidget_setMouseTracking(FDownButtonHandle, True);
end;

procedure TCustomSpinEdit.WidgetDestroyed;
begin
  QClxObjectMap_remove(FEditHandle);
  QClxObjectMap_remove(FUpButtonHandle);
  QClxObjectMap_remove(FDownButtonHandle);
  QWidget_hook_destroy(FEditHook);
  QWidget_hook_destroy(FButtonUpHook);
  QWidget_hook_destroy(FButtonDownHook);
  inherited WidgetDestroyed;
end;

function TCustomSpinEdit.GetButtonStyle: TSEButtonStyle;
begin
  Result := TSEButtonStyle(QSpinBox_buttonSymbols(Handle));
end;

function TCustomSpinEdit.GetCleanText: WideString;
begin
  QSpinBox_cleanText(Handle, PWideString(@Result));
end;

function TCustomSpinEdit.GetIncrement: Integer;
begin
  Result := QSpinBox_lineStep(Handle);
end;

function TCustomSpinEdit.GetMax: Integer;
begin
  Result := QSpinBox_maxValue(Handle);
end;

function TCustomSpinEdit.GetMin: Integer;
begin
  Result := QSpinBox_minValue(Handle);
end;

function TCustomSpinEdit.GetPrefix: WideString;
begin
  QSpinBox_prefix(Handle, PWideString(@Result));
end;

function TCustomSpinEdit.GetRangeControl: QRangeControlH;
begin
  Result := QSpinBox_to_QRangeControl(Handle);
end;

function TCustomSpinEdit.GetSuffix: WideString;
begin
  QSpinBox_suffix(Handle, PWideString(@Result));
end;

function TCustomSpinEdit.GetSpecialText: WideString;
begin
  QSpinBox_specialValueText(Handle, PWideString(@Result));
end;

procedure TCustomSpinEdit.Change(AValue: Integer);
begin
  if Assigned(FOnChanged) then
    FOnChanged(Self, AValue);
end;

function TCustomSpinEdit.GetText: TCaption;
begin
  QSpinBox_text(Handle, PWideString(@Result));
end;

procedure TCustomSpinEdit.InitWidget;
begin
  inherited InitWidget;
  SetRange(Min, Max);
end;

procedure TCustomSpinEdit.Loaded;
begin
  inherited Loaded;
  SetRange(FMin, FMax);
end;

procedure TCustomSpinEdit.PaletteChanged(Sender: TObject);
begin
  inherited;
  QWidget_setPalette(FEditHandle, (Sender as TPalette).Handle, True);
end;

function TCustomSpinEdit.GetWrap: Boolean;
begin
  Result := QSpinBox_wrapping(Handle);
end;

procedure TCustomSpinEdit.SetMin(AValue: Integer);
begin
  if (csLoading in ComponentState) then
    SetRange(AValue, FMax)
  else
    SetRange(AValue, Max);
end;

procedure TCustomSpinEdit.SetMax(AValue: Integer);
begin
  if (csLoading in ComponentState) then
    SetRange(FMin, AValue)
  else
    SetRange(Min, AValue);
end;

procedure TCustomSpinEdit.SetButtonStyle(AValue: TSEButtonStyle);
begin
  QSpinBox_setButtonSymbols(Handle, QSpinBoxButtonSymbols(AValue));
end;

procedure TCustomSpinEdit.SetIncrement(AValue: Integer);
begin
  QSpinBox_setLineStep(Handle, AValue);
end;

procedure TCustomSpinEdit.SetPrefix(const AValue: WideString);
begin
  QSpinBox_setPrefix(Handle, PWideString(@AValue));
end;

procedure TCustomSpinEdit.SetRange(const AMin, AMax: Integer);
begin
  FMin := AMin;
  FMax := AMax;

  if not HandleAllocated or (csLoading in ComponentState) then
    Exit;

  try
    CheckRange(AMin, AMax);
  except
    FMin := Min;
    FMax := Max;
    raise;
  end;

  QRangeControl_setRange(RangeControl, FMin, FMax);

  if Value < Min then
    Value := Min
  else if Value > Max then Value := Max;
end;

procedure TCustomSpinEdit.SetSuffix(const AValue: WideString);
begin
  QSpinBox_setSuffix(Handle, PWideString(@AValue));
end;

procedure TCustomSpinEdit.SetSpecialText(const AValue: WideString);
begin
  QSpinBox_setSpecialValueText(Handle, PWideString(@AValue));
end;

procedure TCustomSpinEdit.SetWrap(AValue: Boolean);
begin
  QSpinBox_setWrapping(Handle, AValue);
end;

procedure TCustomSpinEdit.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  QSpinBox_valueChanged_Event(Method) := ValueChangedHook;
  QSpinBox_hook_hook_valueChanged(QSpinBox_hookH(Hooks), Method);
end;

procedure TCustomSpinEdit.ValueChangedHook(AValue: Integer);
begin
  try
    Change(AValue);
  except
    Application.HandleException(Self);
  end;
end;

function TCustomSpinEdit.GetValue: Integer;
begin
  Result := StrToIntDef(CleanText, Min);
end;

{ wrapper for the default Mime Factory }
type
  TDefaultFactory = class(TMimeSourceFactory)
  protected
    procedure CreateHandle; override;
    procedure DestroyWidget; override;
  end;

var
  PrivateFactory: TMimeSourceFactory;

type
  TMimeFactoryStrings = class(TStringList)
  private
    FOwner: TMimeSourceFactory;
  protected
    function Add(const S: string): Integer; override;
    procedure Delete(Index: Integer); override;
    procedure Put(Index: Integer; const S: string); override;
    procedure ResetFilePath;
  public
    constructor Create(AOwner: TMimeSourceFactory);
    procedure Insert(Index: Integer; const S: string); override;
    procedure Assign(Source: TPersistent); override;
  end;

{ global routines for the Default Factory }

function DefaultMimeFactory: TMimeSourceFactory;
begin
  if PrivateFactory = nil then
    PrivateFactory := TDefaultFactory.Create;
  Result := PrivateFactory;
end;

procedure SetDefaultMimeFactory(Value: TMimeSourceFactory);
begin
  if Assigned(Value) then
  begin
    PrivateFactory := Value;
    QMimeSourceFactory_setDefaultFactory(Value.Handle);
  end;
end;

{ TBrowserStrings }

function TMimeFactoryStrings.Add(const S: string): Integer;
var
  Temp: WideString;
begin
  Result := inherited Add(S);

  if Assigned(FOwner) then
  begin
    Temp := S;
    QMimeSourceFactory_addFilePath(FOwner.Handle, PWideString(@Temp));
  end;
end;

procedure TMimeFactoryStrings.Assign(Source: TPersistent);
begin
  inherited Assign(Source);
  ResetFilePath;
end;

constructor TMimeFactoryStrings.Create(AOwner: TMimeSourceFactory);
begin
  inherited Create;
  FOwner := AOwner;
end;

procedure TMimeFactoryStrings.Delete(Index: Integer);
begin
  inherited Delete(Index);
  ResetFilePath;
end;

procedure TMimeFactoryStrings.Insert(Index: Integer; const S: string);
begin
  inherited Insert(Index, S);
  ResetFilePath;
end;

procedure TMimeFactoryStrings.Put(Index: Integer; const S: string);
begin
  inherited Put(Index, S);
  ResetFilePath;
end;

procedure TMimeFactoryStrings.ResetFilePath;
var
  Temp: QStringListH;
begin
  if Assigned(FOwner) then
  begin
    Temp := TStringsToQStringList(Self);
    try
      QMimeSourceFactory_setFilePath(FOwner.Handle, Temp);
    finally
      QStringList_destroy(Temp);
    end;
  end;
end;

procedure TCustomSpinEdit.SetValue(const AValue: Integer);
begin
  QSpinBox_setValue(Handle, AValue);
end;

{ TMimeSourceFactory }

constructor TMimeSourceFactory.Create;
begin
  inherited Create;
  FFilePath := TMimeFactoryStrings.Create(Self);
end;

destructor TMimeSourceFactory.Destroy;
begin
  DestroyWidget;
  FFilePath.Free;
  inherited Destroy;
end;

type
  TMimeSourceFactory_datacallback = procedure (AbsoluteName: PWideString;
    var ResolvedData: QMimeSourceH) of object cdecl;

procedure TMimeSourceFactory.CreateHandle;
var
  Method: TMethod;
begin
  FHandle := QClxMimeSourceFactory_create;
  TMimeSourceFactory_datacallback(Method) := DoGetDataHook;
  QClxMimeSourceFactory_setDataCallBack(QClxMimeSourceFactoryH(FHandle), Method);
end;

procedure TMimeSourceFactory.DoGetDataHook(AbsoluteName: PWideString;
  var ResolvedData: QMimeSourceH);
begin
  try
    GetData(AbsoluteName^, ResolvedData);
  except
    Application.HandleException(Self);
  end;
end;

procedure TMimeSourceFactory.GetData(const AbsoluteName: string;
  var ResolvedData: QMimeSourceH);
begin
  { stubbed for children }
end;

function TMimeSourceFactory.GetHandle: QMimeSourceFactoryH;
begin
  HandleNeeded;
  Result := FHandle;
end;

function TMimeSourceFactory.HandleAllocated: Boolean;
begin
  Result := FHandle <> nil;
end;

procedure TMimeSourceFactory.HandleNeeded;
begin
  if not HandleAllocated then
    CreateHandle;
end;

procedure TMimeSourceFactory.SetFilePath(const Value: TStrings);
begin
  FFilePath.Assign(Value);
end;

procedure TMimeSourceFactory.RegisterMimeType(const FileExt: WideString;
  const MimeType: string);
begin
  QMimeSourceFactory_setExtensionType(Handle, PWideString(@FileExt),
    PChar(MimeType));
end;

procedure TMimeSourceFactory.AddTextToFactory(const Name: WideString;
  const Data: string);
begin
  QMimeSourceFactory_setText(Handle, PWideString(@Name), @Data);
end;

procedure TMimeSourceFactory.AddImageToFactory(const Name: WideString;
  Data: QImageH);
begin
  QMimeSourceFactory_setImage(Handle, PWideString(@Name), Data);
end;

procedure TMimeSourceFactory.AddPixmapToFactory(const Name: WideString;
  Data: QPixmapH);
begin
  QMimeSourceFactory_setPixmap(Handle, PWideString(@Name), Data);
end;

procedure TMimeSourceFactory.AddDataToFactory(const Name: WideString;
  Data: QMimeSourceH);
begin
  QMimeSourceFactory_setData(Handle, PWideString(@Name), Data);
end;

procedure TMimeSourceFactory.DestroyWidget;
begin
  QMimeSourceFactory_destroy(FHandle);
end;

function TMimeSourceFactory.GetMimeSource(const MimeType: WideString): QMimeSourceH;
begin
  Result := QMimeSourceFactory_data(Handle, PWideString(@MimeType));
end;

{ TDefaultFactory }

procedure TDefaultFactory.DestroyWidget;
begin
  FHandle := nil;
end;

procedure TDefaultFactory.CreateHandle;
begin
  FHandle := QMimeSourceFactory_defaultFactory;
end;

{ TCustomTextViewer }

procedure TCustomTextViewer.CopyToClipboard;
begin
  QTextView_copy(Handle);
end;

constructor TCustomTextViewer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FBrush := TBrush.Create;
  FBrush.OnChange := PaperChanged;

  InputKeys := [ikArrows, ikNav];
  Width := 200;
  Height := 150;
  FLinkColor := clBlue;
  FTextColor := clBlack;
  FTextFormat := tfAutoText;
  FUnderlineLink := True;
  Color := clWhite;
  BorderStyle := bsSunken3d;
end;

procedure TCustomTextViewer.CreateWidget;
begin
  FHandle := QTextView_create(ParentWidget, PChar(Name));
  Hooks := QTextView_hook_create(FHandle);
end;

destructor TCustomTextViewer.Destroy;
begin
  FBrush.Free;
  inherited Destroy;
end;

function TCustomTextViewer.GetBrush: TBrush;
var
  Temp: QBrushH;
begin
  if HandleAllocated then
  begin
    Temp := QTextView_paper(Handle);
    if FBrush.Handle <> Temp then
      FBrush.Handle := Temp;
  end;
  Result := FBrush;
end;

function TCustomTextViewer.GetDocumentTitle: WideString;
begin
  if HandleAllocated then
    QTextView_documentTitle(Handle, PWideString(@Result))
  else
    Result := '';
end;

function TCustomTextViewer.GetHandle: QTextViewH;
begin
  HandleNeeded;
  Result := QTextViewH(FHandle);
end;

function TCustomTextViewer.GetIsTextSelected: Boolean;
begin
  if HandleAllocated then
    Result := QTextView_hasSelectedText(Handle)
  else
    Result := False;
end;

function TCustomTextViewer.GetSelectedText: WideString;
begin
  if HandleAllocated then
    QTextView_selectedText(Handle, PWideString(@Result))
  else
    Result := '';
end;

function TCustomTextViewer.GetDocumentText: WideString;
begin
  if HandleAllocated then
    QTextView_text(Handle, PWideString(@Result))
  else
    Result := '';
end;

const
  cQtTextFormat: array [TTextFormat] of Qt.TextFormat = (TextFormat_PlainText,
    TextFormat_RichText, TextFormat_AutoText);

procedure TCustomTextViewer.LoadFromFile(const AFileName: string);
var
  Stream: TStream;
begin
  if AFileName = '' then
  begin
    Text := '';
    FFileName := '';
    Exit;
  end;

  Stream := TFileStream.Create(AFileName, fmOpenRead or fmShareDenyWrite);
  try
    LoadFromStream(Stream);
    FFileName := AFileName;
  finally
    Stream.Free;
  end;
end;

procedure TCustomTextViewer.LoadFromStream(Stream: TStream);
var
  Temp: string;
begin
  if Stream.Size > 0 then
  begin
    Stream.Position := 0;
    SetLength(Temp, Stream.Size);
    Stream.Read(PChar(Temp)^, Length(Temp));
  end
  else
    Temp := '';

  Text := Temp;
end;

procedure TCustomTextViewer.SelectAll;
begin
  if HandleAllocated then
    QTextView_selectAll(Handle);
end;

procedure TCustomTextViewer.SetBrush(const Value: TBrush);
begin
  if FBrush <> Value then
  begin
    FBrush.Handle := Value.Handle;
    if HandleAllocated then
      QTextView_setPaper(Handle, FBrush.Handle);
  end;
end;

procedure TCustomTextViewer.SetLinkColor(const Value: TColor);
begin
  if LinkColor <> Value then
  begin
    FLinkColor := Value;
    if HandleAllocated then
    begin
      QTextView_setLinkColor(Handle, QColor(FLinkColor));
      UpdateViewableContents;
    end;
  end;
end;

procedure TCustomTextViewer.SetDocumentText(const Value: WideString);
var
  PaperRecall: TBrushRecall;
begin
  PaperRecall := TBrushRecall.Create(Paper);
  try
    if HandleAllocated then
      QTextView_setText(Handle, @Value);
    SubmitTextColor;
  finally
    PaperRecall.Free;
  end;
end;

procedure TCustomTextViewer.SetTextColor(const Value: TColor);
begin
  if FTextColor <> Value then
  begin
    FTextColor := Value;
    SubmitTextColor;
  end;
end;

procedure TCustomTextViewer.SetTextFormat(const Value: TTextFormat);
begin
  if TextFormat <> Value then
  begin
    FTextFormat := Value;
    if HandleAllocated then
      QTextView_setTextFormat(Handle, cQtTextFormat[FTextFormat]);
  end;
end;

procedure TCustomTextViewer.SetUnderlineLink(const Value: Boolean);
begin
  if UnderlineLink <> Value then
  begin
    FUnderlineLink := Value;
    if HandleAllocated then
    begin
      QTextView_setLinkUnderline(Handle, FUnderlineLink);
      UpdateViewableContents;
    end;
  end;
end;

function TCustomTextViewer.GetFactory: TMimeSourceFactory;
begin
  if FUseDefaultFactory then
  begin
    Result := DefaultMimeFactory;
    Exit;
  end;
  
  if FFactory = nil then
    Factory := TMimeSourceFactory.Create;
  Result := FFactory;
end;

procedure TCustomTextViewer.SetFactory(const Value: TMimeSourceFactory);
begin
  if Value = nil then

    UseDefaultFactory := True
  else
  begin
    FFactory := Value;
    FUseDefaultFactory := False;
    QTextView_setMimeSourceFactory(Handle, FFactory.Handle);
  end;
end;

procedure TCustomTextViewer.SetDefaultFactory(const Value: Boolean);
begin
  if not FUseDefaultFactory and Assigned(FFactory) then
    FreeAndNil(FFactory);
  FUseDefaultFactory := Value;
  QTextView_setMimeSourceFactory(Handle, DefaultMimeFactory.Handle);
end;

procedure TCustomTextViewer.WidgetDestroyed;
begin
  QClxObjectMap_remove(FViewportHandle);
  QClxObjectMap_remove(FVScrollHandle);
  QClxObjectMap_remove(FHScrollHandle);
  if Assigned(FViewportHook) then
  begin
    QWidget_hook_destroy(FViewportHook);
    FViewportHook := nil;
  end;
  if Assigned(FVScrollHook) then
  begin
    QScrollbar_hook_destroy(FVScrollHook);
    FVScrollHook := nil;
  end;
  if Assigned(FHScrollHook) then
  begin
    QScrollbar_hook_destroy(FHScrollHook);
    FHScrollHook := nil;
  end;
  FViewportHandle := nil;
  inherited WidgetDestroyed;
end;

function TCustomTextViewer.ViewportHandle: QWidgetH;
begin
  HandleNeeded;
  Result := FViewportHandle;
end;

function TCustomTextViewer.GetChildHandle: QWidgetH;
begin
  Result := ViewportHandle;
end;

procedure TCustomTextViewer.InitWidget;
var
  Method: TMethod;
begin
  inherited InitWidget;
  FViewportHandle := QScrollView_viewport(QScrollViewH(FHandle));
  FVScrollHandle := QScrollView_verticalScrollBar(Handle);
  FHScrollHandle := QScrollView_horizontalScrollBar(Handle);
  QClxObjectMap_add(FViewportHandle, Integer(Self));
  QClxObjectMap_add(FVScrollHandle, Integer(Self));
  QClxObjectMap_add(FHScrollHandle, Integer(Self));

  TEventFilterMethod(Method) := MainEventFilter;

  FViewportHook := QWidget_hook_create(FViewportHandle);
  Qt_hook_hook_events(FViewportHook, Method);

  FVScrollHook := QScrollBar_hook_create(FVScrollHandle);
  Qt_hook_hook_events(FVScrollHook, Method);

  FHScrollHook := QScrollBar_hook_create(FHScrollHandle);
  Qt_hook_hook_events(FHScrollHook, Method);

  QWidget_setMouseTracking(FViewportHandle, True);
  QWidget_setAcceptDrops(FViewportHandle, True);

  SubmitTextColor;
  QTextView_setLinkColor(Handle, QColor(FLinkColor));
  QTextView_setTextFormat(Handle, cQtTextFormat[FTextFormat]);
  QTextView_setLinkUnderline(Handle, FUnderlineLink);
end;

procedure TCustomTextViewer.PaperChanged(Sender: TObject);
begin
  if HandleAllocated then
  begin
    QWidget_update(ViewportHandle);
    Repaint;
  end;
end;

procedure TCustomTextViewer.SubmitTextColor;
var
  QC: QColorH;
begin
  if HandleAllocated then
  begin
    QC := QColor_create(QColor(FTextColor));
    try
      QColorGroup_setColor(QTextView_paperColorGroup(Handle), QColorGroupColorRole(crText), QC);
      UpdateViewableContents;
    finally
      QColor_destroy(QC);
    end;
  end;
end;

procedure TCustomTextViewer.SetFileName(const Value: TFileName);
begin
  LoadFromFile(Value);
end;

procedure TCustomTextViewer.UpdateViewableContents;
begin
  if HandleAllocated then
  begin
    QScrollView_updateContents(Handle, 0,0, QScrollView_visibleWidth(Handle),
    QScrollView_visibleHeight(Handle));
  end;
end;

{ TCustomTextBrowser }

procedure TCustomTextBrowser.Backward;
begin
  if HandleAllocated then
    QTextBrowser_backward(Handle);
end;

function TCustomTextBrowser.CanGoBackward: Boolean;
begin
  Result := FBackwardAvailable;
end;

function TCustomTextBrowser.CanGoForward: Boolean;
begin
  Result := FForwardAvailable;
end;

procedure TCustomTextBrowser.CreateWidget;
begin
  FHandle := QTextBrowser_create(ParentWidget, nil);
  Hooks := QTextBrowser_hook_create(FHandle);
end;

procedure TCustomTextBrowser.Forward;
begin
  if HandleAllocated then
    QTextBrowser_Forward(Handle);
end;

function TCustomTextBrowser.GetHandle: QTextBrowserH;
begin
  HandleNeeded;
  Result := QTextBrowserH(FHandle);
end;

procedure TCustomTextBrowser.Home;
begin
  if HandleAllocated then
    QTextBrowser_Home(Handle);
end;

procedure TCustomTextBrowser.HookBackwardAvailable(p1: Boolean);
begin
  try
    FBackwardAvailable := p1;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomTextBrowser.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  QTextBrowser_backwardAvailable_Event(Method) := HookBackwardAvailable;
  QTextBrowser_hook_hook_backwardAvailable(QTextBrowser_hookH(Hooks), Method);
  QTextBrowser_forwardAvailable_Event(Method) := HookForwardAvailable;
  QTextBrowser_hook_hook_forwardAvailable(QTextBrowser_hookH(Hooks), Method);
end;

procedure TCustomTextBrowser.HookForwardAvailable(p1: Boolean);
begin
  try
    FForwardAvailable := p1;
  except
    Application.HandleException(Self);
  end;
end;
                 
procedure TCustomTextBrowser.HookHighlightText(p1: PWideString);
begin
  if Assigned(FRTBHighlightText) then
  try
    FRTBHighlightText(Self, p1^);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomTextBrowser.HookTextChanged;
begin
  if Assigned(FTextChanged) then
  try
    FTextChanged(Self);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomTextBrowser.LoadFromFile(const AFileName: string);
var
  WFileName: WideString;
begin
  FFileName := AFileName;
  if HandleAllocated then
  begin
    if FFileName = '' then
      QTextView_setText(Handle, nil)
    else
    begin
      WFileName := AFileName;
      QTextBrowser_setSource(Handle, PWideString(@WFileName));
    end;
  end;
end;

procedure TCustomTextBrowser.ScrollToAnchor(const AnchorName: WideString);
begin
  if HandleAllocated then
    QTextBrowser_scrollToAnchor(Handle, PWideString(@AnchorName));
end;

procedure TCustomTextBrowser.SetDocumentText(const Value: WideString);
begin
  QTextBrowser_setText(Handle, PWideString(@Value), nil);
  SubmitTextColor;
end;

procedure TCustomTextBrowser.SetHighlightText(const Value: TRTBHighlightTextEvent);
var
  Method: TMethod;          
begin
  FRTBHighlightText := Value;
  if Assigned(FRTBHighlightText) then
    QTextBrowser_highlighted_Event(Method) := HookHighlightText
  else
    Method := NullHook;

  QTextBrowser_hook_hook_highlighted(QTextBrowser_hookH(Hooks), Method);
end;

procedure TCustomTextBrowser.SetTextChanged(const Value: TNotifyEvent);
var
  Method: TMethod;
begin                                                                     
  FTextChanged := Value;
  if Assigned(FTextChanged) then
    QTextBrowser_textChanged_Event(Method) := HookTextChanged
  else
    Method := NullHook;

  QTextBrowser_hook_hook_textChanged(QTextBrowser_hookH(Hooks), Method);
end;

procedure TCustomTextBrowser.WidgetDestroyed;
begin
  QClxObjectMap_remove(FViewportHandle);
  FViewportHandle := nil;
  inherited WidgetDestroyed;
end;

{ TCustomIconView }

const
  cIVQtSelect: array [Boolean] of QIconViewSelectionMode =
    (QIconViewSelectionMode_Single, QIconViewSelectionMode_Extended);
  cIVQtResizeMode: array [TResizeMode] of QIconViewResizeMode =
    (QIconViewResizeMode_Fixed, QIconViewResizeMode_Adjust);
  cIVResizeMode: array [Boolean] of TResizeMode = (rmAdjust, rmFixed);
  cIVTextPos: array [Boolean] of TItemTextPos = (itpRight, itpBottom);
  cIVQtTextPos: array [TItemTextPos] of QIconViewItemTextPos =
    (QIconViewItemTextPos_Bottom, QIconViewItemTextPos_Right);
  cIVQtArrangement: array [TIconArrangement] of QIconViewArrangement =
    (QIconViewArrangement_TopToBottom, QIconViewArrangement_LeftToRight);

constructor TCustomIconView.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FIconViewItems := TIconViewItems.Create(Self);
  FIconOptions := TIconOptions.Create(Self);
  FImageChanges := TChangeLink.Create;
  FImageChanges.OnChange := OnImageChanges;
  FItemsMovable := True;
  FResizeMode := rmAdjust;
  FShowToolTips := True;
  FSpacing := 5;
  FSortDirection := sdAscending;
  ParentColor := False;
  Width := 121;
  Height := 97;
  TabStop := True;
  InputKeys := [ikArrows, ikReturns, ikNav];
  BorderStyle := bsSunken3d;
end;

procedure TCustomIconView.BeginAutoDrag;
begin
  BeginDrag(False, Mouse.DragThreshold);
end;

procedure TCustomIconView.ChangeHook(item: QIconViewItemH; _type: TItemChange);
var
  AItem: TIconViewItem;
begin
  try
    AItem := Items.FindItem(item);
    if Assigned(AItem) then
      DoChange(AItem, _type);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomIconView.ChangingHook(item: QIconViewItemH; _type: TItemChange;
  var Allow: Boolean);
var
  AItem: TIconViewItem;
begin
  try
    AItem := Items.FindItem(item);
    if Assigned(AItem) then
      DoChanging(AItem, _type, Allow);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomIconView.ColorChanged;
begin
  inherited ColorChanged;
  UpdateControl;
end;

procedure TCustomIconView.CreateWidget;
begin
  FHandle := QIconView_create(ParentWidget, nil, WidgetFlags);
  Hooks := QIconView_hook_create(FHandle);
  FItemHooks := QClxIconViewHooks_create;
  FViewportHandle := QScrollView_viewport(QScrollViewH(FHandle));
  QClxObjectMap_add(FViewportHandle, Integer(Self));
end;

destructor TCustomIconView.Destroy;
begin
  FIconViewItems.Free;
  FIconOptions.Free;
  FImageChanges.Free;
  inherited Destroy;
end;

procedure TCustomIconView.Clear;
begin
  FIconViewItems.Clear;
end;

procedure TCustomIconView.DoChange(Item: TIconViewItem; Change: TItemChange);
begin
  if Assigned(FOnItemChange) then
    FOnItemChange(Self, Item, Change);
end;

procedure TCustomIconView.DoChanging(Item: TIconViewItem; Change: TItemChange;
  var AllowChange: Boolean);
begin
  if Assigned(FOnItemChanging) then
    FOnItemChanging(Self, Item, Change, AllowChange);
end;

procedure TCustomIconView.DoItemDoubleClicked(item: QIconViewItemH);
begin
  if Assigned(FOnItemDoubleClick) then
    try
      FOnItemDoubleClick(Self, Items.FindItem(item));
    except
      Application.HandleException(Self);
    end;
end;

procedure TCustomIconView.DoItemEnter(item: QIconViewItemH);
begin
  if Assigned(FOnItemEnter) then
    try
      FOnItemEnter(Self, Items.FindItem(item));
    except
      Application.HandleException(Self);
    end;
end;

procedure TCustomIconView.DoEdited(item: QIconViewItemH; p2: PWideString);
var
  AItem: TIconViewItem;
begin
  if Assigned(FOnEdited) then
    try
      AItem := Items.FindItem(item);
      if Assigned(AItem) then
        FOnEdited(Self, AItem, p2^);
    except
      Application.HandleException(Self);
    end;
end;

procedure TCustomIconView.DoItemClicked(item: QIconViewItemH);
var
  AItem: TIconViewItem;
begin
  if Assigned(FOnItemClicked) then
    try
      AItem := Items.FindItem(item);
      if Assigned(AItem) then
        FOnItemClicked(Self, AItem);
    except
      Application.HandleException(Self);
    end;
end;

procedure TCustomIconView.DoViewportEnter;
begin
  if Assigned(FOnItemExitViewportEnter) then
    try
      FOnItemExitViewportEnter(Self);
    except
      Application.HandleException(Self);
    end;
end;

procedure TCustomIconView.EnsureItemVisible(AItem: TIconViewItem);
begin
  if Assigned(AItem) and HandleAllocated then
    QIconView_ensureItemVisible(Handle, AItem.Handle); 
end;

function TCustomIconView.FindItemByPoint(const Pt: TPoint): TIconViewItem;
begin
  if HandleAllocated then
    Result := Items.FindItem(QIconView_findItem(Handle, PPoint(@Pt)))
  else
    Result := nil;
end;

function TCustomIconView.FindItemByText(const Str: WideString): TIconViewItem;
var
  I: Integer;
begin
  for I := 0 to Items.Count-1 do
  begin
    Result := Items[I];
    if Result.Caption = Str then
      Exit;
  end;
  Result := nil;
end;

function TCustomIconView.FindVisibleItem(First: Boolean;
  const ARect: TRect): TIconViewItem;
begin
  if HandleAllocated then
  begin
    if First then { find the first visible item }
      Result := Items.FindItem(QIconView_findFirstVisibleItem(Handle, @ARect))
    else { find the last visible item }
      Result := Items.FindItem(QIconView_findLastVisibleItem(Handle, @ARect));
  end
  else
    Result := nil;
end;

function TCustomIconView.GetHandle: QIconViewH;
begin
  HandleNeeded;
  Result := QIconViewH(FHandle);
end;

function TCustomIconView.GetNextItem(StartItem: TIconViewItem;
  Direction: TSearchDirection; States: TItemStates): TIconViewItem;
var
  AIndex: Integer;
begin
  Result := nil;
  if HandleAllocated and Assigned(StartItem) then
  begin
    if Direction = sdAbove then
      Result := Items.FindItem(QIconViewItem_prevItem(StartItem.Handle))
    else if Direction = sdBelow then
      Result := Items.FindItem(QIconViewItem_nextItem(StartItem.Handle))
    else
    begin
      AIndex := StartItem.Index;
      while True do
      begin
        Inc(AIndex);
        if AIndex < Items.Count then
        begin
          Result := Items[AIndex];
          if Result = StartItem then
            Result := nil;
          if Result = nil then
            Exit;
          if (Result.States * States <> []) then
            Exit;
        end
        else
        begin
          Result := nil;
          Exit;
        end;
      end;
    end;
  end;
end;

type
  TIconView_ChangingEvent = procedure(item: QIconViewItemH; _type: TItemChange;
    var Allow: Boolean) of object cdecl;
  TIconView_ChangeEvent = procedure(item: QIconViewItemH;
    _type: TItemChange) of object  cdecl;
  TIconView_DestroyedEvent = procedure(item: QIconViewItemH) of object cdecl;
  TIconView_SelectedEvent = procedure(item: QIconViewItemH;
    Value: Boolean) of object cdecl;
  TIconView_PaintCellEvent = procedure(p: QPainterH;
    item: QIconViewItemH; cg: QColorGroupH; var stage: Integer) of object cdecl;
  TIconView_PaintFocusEvent = procedure(p: QPainterH; item: QIconViewItemH;
    cg: QColorGroupH; var stage: Integer) of object cdecl;

procedure TCustomIconView.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  TEventFilterMethod(Method) := MainEventFilter;
  FViewportHooks := QWidget_hook_create(FViewportHandle);
  Qt_hook_hook_events(FViewportHooks, Method);
  TIconView_ChangingEvent(Method) := ChangingHook;
  QClxIconViewHooks_hook_changing(FItemHooks, Method);
  TIconView_ChangeEvent(Method) := ChangeHook;
  QClxIconViewHooks_hook_change(FItemHooks, Method);
  TIconView_DestroyedEvent(Method) := ItemDestroyedHook;
  QClxIconViewHooks_hook_destroyed(FItemHooks, Method);
  TIconView_SelectedEvent(Method) := SelectedHook;
  QClxIconViewHooks_hook_setSelected(FItemHooks, Method);
  TIconView_PaintCellEvent(Method) := PaintCellHook;
  QClxIconViewHooks_hook_PaintItem(FItemHooks, Method);
  TIconView_PaintFocusEvent(Method) := PaintFocusHook;
  QClxIconViewHooks_hook_PaintFocus(FItemHooks, Method);
end;

procedure TCustomIconView.ImageListChanged;
begin
  FIconViewItems.UpdateImages;
end;

procedure TCustomIconView.ItemDestroyedHook(item: QIconViewItemH);
var
  AItem: TIconViewItem;
begin
  try
    AItem := Items.FindItem(item);
    if Assigned(Item) then
    begin
      QClxObjectMap_remove(item);
      AItem.FHandle := nil;
      if not AItem.FDestroying then
        AItem.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomIconView.InitWidget;
begin
  inherited InitWidget;
  QIconView_setWordWrapIconText(Handle, IconOptions.WrapText);
  QIconView_setItemsMovable(Handle, FItemsMovable);
  QIconView_setSorting(Handle, FSort, FSortDirection = sdAscending);
  QIconView_setShowToolTips(Handle, FShowToolTips);
  QIconView_setAutoArrange(Handle, IconOptions.AutoArrange);
  QIconView_setResizeMode(Handle, cIVQtResizeMode[FResizeMode]);
  QIconView_setArrangement(Handle, cIVQtArrangement[IconOptions.Arrangement]);
  QIconView_setItemTextPos(Handle, cIVQtTextPos[FTextPosition]);
  QIconView_setSpacing(Handle, FSpacing);
  QIconView_setGridX(Handle, -1);
  QIconView_setGridY(Handle, -1);
  QIconView_setSelectionMode(Handle, cIVQtSelect[FMultiSelect]);
  QWidget_setMouseTracking(Handle, True);
  QWidget_setAcceptDrops(Handle, True);
  QWidget_setMouseTracking(FViewportHandle, True);
  QWidget_setAcceptDrops(FViewportHandle, True);
end;

procedure TCustomIconView.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (AComponent = FImages) then
  begin
    if (Operation = opRemove) then
      FImages := nil;
    ImageListChanged;
  end;
end;

procedure TCustomIconView.OnImageChanges(Sender: TObject);
begin
  ImageListChanged;
end;

procedure TCustomIconView.PaintCellHook(p: QPainterH; item: QIconViewItemH;
  cg: QColorGroupH; var stage: Integer);
begin
  try
    stage := DrawStage_DefaultDraw;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomIconView.PaintFocusHook(p: QPainterH; item: QIconViewItemH;
  cg: QColorGroupH; var stage: Integer);
begin
  try
    stage := DrawStage_DefaultDraw;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomIconView.RepaintItem(AItem: TIconViewItem);
begin
  if Assigned(AItem) and HandleAllocated then
    QIconView_repaintItem(Handle, AItem.Handle);
end;

procedure TCustomIconView.SelectAll(Select: Boolean);
begin
  if HandleAllocated then
    QIconView_selectAll(Handle, Select);
end;

procedure TCustomIconView.SelectedHook(item: QIconViewItemH; Value: Boolean);
const
  cIncSelCount: array [Boolean] of Integer = (-1, 1);
var
  AItem: TIconViewItem;
begin
  try
    Inc(FSelCount, cIncSelCount[Value]);
    if FSelCount < 0 then
      FSelCount := 0;
    AItem := Items.FindItem(item);
    if FSelCount > 0 then
    begin
      if (FSelected = AItem) and Value then
        Dec(FSelCount)
      else
        FSelected := AItem;
    end
    else
      FSelected := nil;

    if Assigned(AItem) then
    begin
      if Value then
        AItem.FStates := [isSelected, isFocused]
      else
        AItem.FStates := [isNone];
      if Assigned(FOnSelectItem) then
        FOnSelectItem(Self, AItem, AItem.Selected);
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomIconView.SetIconOptions(const Value: TIconOptions);
begin
  if (FIconOptions <> Value) and Assigned(Value) then
  begin
    FIconOptions.Arrangement := Value.Arrangement;
    FIconOptions.AutoArrange := Value.AutoArrange;
    FIconOptions.WrapText := Value.WrapText;
  end;
end;

procedure TCustomIconView.SetIconViewItems(const Value: TIconViewItems);
begin
  if FIconViewItems <> Value then
    FIconViewItems.Assign(Value);
end;

procedure TCustomIconView.SetImages(const Value: TCustomImageList);
begin
  if Value <> FImages then
  begin
    if Assigned(FImages) then
      FImages.UnRegisterChanges(FImageChanges);
    FImages := Value;
    if Assigned(FImages) then
      FImages.RegisterChanges(FImageChanges);
    ImageListChanged;
  end;
end;

procedure TCustomIconView.SetItemsMovable(const Value: Boolean);
begin
  if FItemsMovable <> Value then
  begin
    FItemsMovable := Value;
    if HandleAllocated then
      QIconView_setItemsMovable(Handle, FItemsMovable);
  end;
end;

procedure TCustomIconView.SetMultiSelect(const Value: Boolean);
begin
  if (FMultiSelect <> Value) then
  begin
    FMultiSelect := Value;
    if HandleAllocated then
    begin
      if not Value then
        QIconView_clearSelection(Handle);
      QIconView_setSelectionMode(Handle, cIVQtSelect[FMultiSelect]);
    end;
  end;
end;

procedure TCustomIconView.SetOnItemClicked(const Value: TIVItemClickEvent);
var
  Method: TMethod;
begin                                                                     
  FOnItemClicked := Value;
  if Assigned(FOnItemClicked) then
    QIconView_clicked_Event(Method) := DoItemClicked
  else
    Method := NullHook;

  QIconView_hook_hook_clicked(QIconView_hookH(Hooks), Method);
end;

procedure TCustomIconView.SetOnItemDoubleClick(const Value: TIVItemDoubleClickEvent);
var
  Method: TMethod;
begin                                                                     
  FOnItemDoubleClick := Value;
  if Assigned(FOnItemDoubleClick) then
    QIconView_doubleClicked_Event(Method) := DoItemDoubleClicked
  else
    Method := NullHook;

  QIconView_hook_hook_doubleClicked(QIconView_hookH(Hooks), Method);
end;

procedure TCustomIconView.SetOnItemEnter(const Value: TIVItemEnterEvent);
var
  Method: TMethod;
begin
  FOnItemEnter := Value;
  if Assigned(FOnItemEnter) then
    QIconView_onItem_Event(Method) := DoItemEnter
  else
    Method := NullHook;

  QIconView_hook_hook_onItem(QIconView_hookH(Hooks), Method);
end;

procedure TCustomIconView.SetOnItemExitViewportEnter(const Value: TIVItemExitViewportEnterEvent);
var
  Method: TMethod;
begin
  FOnItemExitViewportEnter := Value;
  if Assigned(FOnItemExitViewportEnter) then
    QIconView_onViewport_Event(Method) := DoViewportEnter
  else
    Method := NullHook;

  QIconView_hook_hook_onItem(QIconView_hookH(Hooks), Method);
end;

procedure TCustomIconView.SetOnEdited(const Value: TIVEditedEvent);
var
  Method: TMethod;
begin
  FOnEdited := Value;
  if Assigned(FOnEdited) then
    QIconView_itemRenamed_Event(Method) := DoEdited
  else
    Method := NullHook;

  QIconView_hook_hook_itemRenamed(QIconView_hookH(Hooks), Method);
end;

procedure TCustomIconView.SetResizeMode(const Value: TResizeMode);
begin
  if (FResizeMode <> Value) then
  begin
    FResizeMode := Value;
    if HandleAllocated then
      QIconView_setResizeMode(Handle, cIVQtResizeMode[FResizeMode]);
  end;
end;

procedure TCustomIconView.SetSelected(const Value: TIconViewItem);
begin
  if not (csDestroying in ComponentState) then
    if Assigned(Value) then
      Value.Selected := True;
  FSelected := Value;
end;

procedure TCustomIconView.SetShowToolTips(const Value: Boolean);
begin
  if (FShowToolTips <> Value) then
  begin
    FShowToolTips := Value;
    if HandleAllocated then
      QIconView_setShowToolTips(Handle, FShowToolTips);
  end;
end;

procedure TCustomIconView.SetSort(const Value: Boolean);
begin
  if FSort <> Value then
  begin
    FSort := Value;
    if HandleAllocated then
    begin
      QIconView_setSorting(Handle, FSort, FSortDirection = sdAscending);
      if FSort then
        QIconView_sort(Handle, FSortDirection = sdAscending);
    end;
  end;
end;

procedure TCustomIconView.SetSortDirection(const Value: TSortDirection);
begin
  if FSortDirection <> Value then
  begin
    FSortDirection := Value;
    if Sort then
    begin
      if HandleAllocated then
        QIconView_sort(Handle, FSortDirection = sdAscending);
    end
    else
      Sort := True;
  end;
end;

procedure TCustomIconView.SetSpacing(const Value: Integer);
begin
  if (FSpacing <> Value) then
  begin
    FSpacing := Value;
    if HandleAllocated then
      QIconView_setSpacing(Handle, FSpacing);
  end;
end;

procedure TCustomIconView.SetTextPos(const Value: TItemTextPos);
begin
  if (FTextPosition <> Value) then
  begin
    FTextPosition := Value;
    if HandleAllocated then
      QIconView_setItemTextPos(Handle, cIVQtTextPos[FTextPosition]);
  end;
end;

function TCustomIconView.ViewportHandle: QWidgetH;
begin
  HandleNeeded;
  Result := FViewportHandle;
end;

procedure TCustomIconView.WidgetDestroyed;
begin
  QClxIconViewHooks_hook_destroyed(FItemHooks, NullHook);
  QClxIconViewHooks_destroy(FItemHooks);
  FItemHooks := nil;
  QClxObjectMap_remove(FViewportHandle);
  FViewportHandle := nil;
  inherited WidgetDestroyed;
end;

procedure TCustomIconView.UpdateItems(FirstIndex, LastIndex: Integer);
var
  I: Integer;
begin
  if HandleAllocated then
  begin
    Items.BeginUpdate;
    try
      for I := FirstIndex to LastIndex do
        QIconViewItem_repaint(Items[I].Handle);
    finally
      Items.EndUpdate;
    end;
  end;
end;

procedure TCustomIconView.UpdateControl;
begin
  if HandleAllocated then
    QIconView_updateContents(Handle);
end;

{ TIconViewItems }

constructor TIconViewItems.Create(AOwner: TCustomIconView);
begin
  inherited Create;
  FOwner := AOwner;
  FItems := TObjectList.Create;
  SetItemClass(TIconViewItem);
end;

constructor TIconViewItems.Create(AOwner: TCustomIconView;
  AItemClass: TIconViewItemClass);
begin
  inherited Create;
  FOwner := AOwner;
  FItems := TObjectList.Create;
  SetItemClass(AItemClass);
end;

destructor TIconViewItems.Destroy;
begin
  FItems.Free;
  inherited Destroy;
end;

type
  PIconItemHeader = ^TIconItemHeader;
  TIconItemHeader = packed record
    Size: Integer;
    Count: Integer;
    Items: record end;
  end;
  PIconItemInfo = ^TIconItemInfo;
  TIconItemInfo = packed record
    ImageIndex: Integer;
    Caption: string[255];
  end;

function TIconViewItems.Add: TIconViewItem;
begin
  BeginUpdate;
  try
    Result := TIconViewItem.Create(Self);
    FItems.Add(Result);
  finally
    EndUpdate;
  end;
end;

procedure TIconViewItems.BeginUpdate;
begin
  if FUpdateCount = 0 then
    SetUpdateState(True);
  Inc(FUpdateCount);
end;

procedure TIconViewItems.Clear;
begin
  FItems.Clear;
end;

procedure TIconViewItems.DefineProperties(Filer: TFiler);

  function WriteItems: Boolean;
  var
    I: Integer;
    Items: TIconViewItems;
  begin
    Items := TIconViewItems(Filer.Ancestor);
    if (Items = nil) then
      Result := Count > 0
    else if (Items.Count <> Count) then
      Result := True
    else
    begin
      Result := False;
      for I := 0 to Count - 1 do
      begin
        Result := not Item[I].IsEqual(Items[I]);
        if Result then Break;
      end
    end;
  end;

begin
  inherited DefineProperties(Filer);
  Filer.DefineBinaryProperty('Data', ReadData, WriteData, WriteItems);
end;

procedure TIconViewItems.Delete(Index: Integer);
begin
  FItems.Delete(Index);
end;

procedure TIconViewItems.EndUpdate;
begin
  Dec(FUpdateCount);
  if FUpdateCount = 0 then
    SetUpdateState(False);
end;

procedure TIconViewItems.ReadData(Stream: TStream);
var
  I, Size: Integer;
  ItemHeader: PIconItemHeader;
  ItemInfo: PIconItemInfo;
begin
  Clear;
  Stream.ReadBuffer(Size, SizeOf(Integer));
  ItemHeader := AllocMem(Size);
  try
    Stream.ReadBuffer(ItemHeader^.Count, Size - SizeOf(Integer));
    ItemInfo := @ItemHeader^.Items;
    for I := 0 to ItemHeader^.Count - 1 do
    begin
      with Add do
      begin
        Caption := ItemInfo^.Caption;
        ImageIndex := ItemInfo^.ImageIndex;
      end;
      Inc(Integer(ItemInfo), SizeOf(TIconItemInfo) - 255 +
        Length(ItemInfo.Caption));
    end;
  finally
    FreeMem(ItemHeader, Size);
  end;
end;

procedure TIconViewItems.WriteData(Stream: TStream);
var
  I, Size, L: Integer;
  ItemHeader: PIconItemHeader;
  ItemInfo: PIconItemInfo;
  PStr: PShortStr;

  function GetLength(const S: string): Integer;
  begin
    Result := Length(S);
    if Result > 255 then Result := 255;
  end;

begin
  Size := SizeOf(TIconItemHeader);
  for I := 0 to Count - 1 do
  begin
    L := GetLength(Item[I].Caption);
    Inc(Size, SizeOf(TIconItemInfo) - 255 + L);
  end;
  ItemHeader := AllocMem(Size);
  try
    ItemHeader^.Size := Size;
    ItemHeader^.Count := Count;
    ItemInfo := @ItemHeader^.Items;
    for I := 0 to Count - 1 do
    begin
      with Item[I] do
      begin
        ItemInfo^.Caption := Caption;
        ItemInfo^.ImageIndex := ImageIndex;
        PStr := @ItemInfo^.Caption;
        Inc(Integer(PStr), Length(ItemInfo^.Caption) + 1);
      end;
      Inc(Integer(ItemInfo), SizeOf(TIconItemInfo) - 255 +
        Length(ItemInfo^.Caption));
    end;
    Stream.WriteBuffer(ItemHeader^, Size);
  finally
    FreeMem(ItemHeader, Size);
  end;
end;

function TIconViewItems.FindItem(ItemH: QIconViewItemH): TIconViewItem;
var
  I: Integer;
begin
  Result := nil;
  if not Assigned(ItemH) then
    Exit; 
  Result := TIconViewItem(QClxObjectMap_find(ItemH));
  if Result is TIconViewItem then
    Exit;
  for I := 0 to Count-1 do
  begin
    Result := Item[I];
    if Result.Handle = ItemH then
      Exit;
  end;
  Result := nil;
end;

function TIconViewItems.GetCount: Integer;
begin
  Result := FItems.Count;
end;

function TIconViewItems.GetItem(Index: Integer): TIconViewItem;
begin
  Result := TIconViewItem(FItems[Index]);
end;

function TIconViewItems.IndexOf(Value: TIconViewItem): Integer;
begin
  Result := FItems.IndexOf(Value);
end;

function TIconViewItems.Insert(Index: Integer): TIconViewItem;
begin
  Result := Add;
  FItems.Move(Result.Index, Index);
end;

function TIconViewItems.IconViewHandle: QIconViewH;
begin
  if Assigned(FOwner) then
    Result := FOwner.Handle
  else
    Result := nil;
end;

procedure TIconViewItems.SetItem(Index: Integer; AObject: TIconViewItem);
begin
  FItems[Index] := AObject;
end;

procedure TIconViewItems.SetItemClass(AItemClass: TIconViewItemClass);
begin
  FIconViewItemClass := AItemClass;
end;

procedure TIconViewItems.SetUpdateState(Updating: Boolean);
begin
  if not (csDestroying in Owner.ComponentState) and Owner.HandleAllocated then
  begin
    if (FUpdateCount = 0) then
    begin
      QWidget_setUpdatesEnabled(IconViewHandle, not Updating);
      QWidget_setUpdatesEnabled(QScrollView_viewport(IconViewHandle), not Updating);
      if not Updating then
        QIconView_updateContents(IconViewHandle);
    end;
  end;
end;

procedure TIconViewItems.UpdateImages;
var
  I: Integer;
begin
  for I := 0 to Count-1 do
    Item[I].UpdateImage;
end;

{ TIconViewItem }

constructor TIconViewItem.Create(AOwner: TIconViewItems; AfterItem: TIconViewItem = nil);
begin
  inherited Create;
  FOwner := AOwner;
  FImageIndex := -1;
  FAllowRename := True;
  FSelectable := True;
  States := [isNone];
  CreateWidget(AfterItem);
end;

procedure TIconViewItem.CreateWidget(AfterItem: TIconViewItem);
var
  AfterH: QIconViewItemH;
  ParentH: QIconViewH;
begin
  if IconViewValid then
  begin
    IconView.HandleNeeded;
    if Assigned(AfterItem) then
      AfterH := AfterItem.Handle
    else
      AfterH := nil;

    ParentH := IconView.Handle;

    FHandle := QClxIconViewItem_create(ParentH, AfterH, IconView.FItemHooks);
    QClxObjectMap_add(FHandle, Integer(Self));
    InitWidget;
  end;
end;

destructor TIconViewItem.Destroy;
begin
  FDestroying := True;
  if Assigned(FOwner) then
    FOwner.FItems.Extract(Self);
  if IconViewValid then
    if IconView.FSelected = Self then
      IconView.FSelected := nil;
  DestroyWidget;
  inherited Destroy;
end;

procedure TIconViewItem.DestroyWidget;
begin
  if HandleAllocated then
    QIconViewItem_destroy(FHandle);
end;

function TIconViewItem.HandleAllocated: Boolean;
begin
  Result := FHandle <> nil;
end;

procedure TIconViewItem.InitWidget;
begin
  QIconViewItem_setDragEnabled(Handle, False);
  QIconViewItem_setDropEnabled(Handle, True);
  QIconViewItem_setRenameEnabled(Handle, FAllowRename);
  QIconViewItem_setText(Handle, @FCaption);
  QIconViewItem_setSelectable(Handle, FSelectable);
  if Assigned(FOwner) and (FOwner.FUpdateCount = 0) then
    QIconView_ensureItemVisible(IconView.Handle, Handle);
end;

function TIconViewItem.IsEqual(AItem: TIconViewItem): Boolean;
begin
  if Assigned(AItem) then
    Result := (Caption = AItem.Caption) and (ImageIndex = AItem.ImageIndex)
  else
    Result := False;
end;

function TIconViewItem.BoundingRect: TRect;
begin
  if HandleAllocated then
    QIconViewItem_rect(Handle, @Result)
  else
    Result := Rect(-1, -1, -1, -1);
end;

function TIconViewItem.GetHandle: QIconViewItemH;
begin
  Result := FHandle;
end;

function TIconViewItem.GetHeight: Integer;
begin
  if HandleAllocated then
    Result := QIconViewItem_height(Handle)
  else
    Result := -1;
end;

function TIconViewItem.GetIconView: TCustomIconView;
begin
  if FOwner.FOwner is TCustomIconView then
    Result := TCustomIconView(FOwner.FOwner)
  else
    Result := nil;
end;

function TIconViewItem.GetIndex;
begin
  Result := FOwner.IndexOf(Self);
end;

function TIconViewItem.GetLeft: Integer;
begin
  if HandleAllocated then
    Result := QIconViewItem_x(Handle)
  else
    Result := -1;
end;

function TIconViewItem.GetSelected: Boolean;
begin
  if HandleAllocated then
    Result := QIconViewItem_isSelected(Handle)
  else
    Result := False;
end;

function TIconViewItem.GetTop: Integer;
begin
  if HandleAllocated then
    Result := QIconViewItem_y(Handle)
  else
    Result := -1;
end;

function TIconViewItem.GetWidth: Integer;
begin
  if HandleAllocated then
    Result := QIconViewItem_width(Handle)
  else
    Result := -1;
end;

function TIconViewItem.IconRect: TRect;
begin
  if HandleAllocated then
    QIconViewItem_pixmapRect(Handle, @Result, False)
  else
    Result := Rect(-1, -1, -1, -1);
end;

function TIconViewItem.IconViewValid: Boolean;
begin
  Result := Assigned(FOwner) and Assigned(FOwner.FOwner);
end;

procedure TIconViewItem.MakeVisible;
begin
  if HandleAllocated then
    QIconView_ensureItemVisible(IconView.Handle, Handle);
end;

procedure TIconViewItem.Move(const Pt: TPoint);
begin
  if HandleAllocated then
  begin
    QIconViewItem_move(Handle, @Pt);
    if IconViewValid then
      IconView.UpdateControl;
  end;
end;

procedure TIconViewItem.MoveBy(const Pt: TPoint);
begin
  if HandleAllocated then
  begin
    QIconViewItem_moveBy(Handle, @Pt);
    if IconViewValid then
      IconView.UpdateControl;
  end;
end;

procedure TIconViewItem.Repaint;
begin
  if HandleAllocated then
    QIconViewItem_repaint(Handle);
end;

procedure TIconViewItem.SetAllowRename(const Value: Boolean);
begin
  if (FAllowRename <> Value) then
  begin
    FAllowRename := Value;
    if HandleAllocated then
      QIconViewItem_setRenameEnabled(Handle, FAllowRename);
  end;
end;

procedure TIconViewItem.SetCaption(const Value: WideString);
begin
  FCaption := Value;
  if HandleAllocated then
    QIconViewItem_setText(Handle, @FCaption);
end;

procedure TIconViewItem.SetImageIndex(const Value: TImageIndex);
begin
  if FImageIndex <> Value then
  begin
    FImageIndex := Value;
    UpdateImage;
  end;
end;

procedure TIconViewItem.SetSelectable(const Value: Boolean);
begin
  if (FSelectable <> Value) then
  begin
    FSelectable := Value;
    if HandleAllocated then
      QIconViewItem_setSelectable(Handle, FSelectable);
  end;
end;

procedure TIconViewItem.SetSelected(const Value: Boolean);
begin
  if (Selected <> Value) and HandleAllocated then
    QIconViewItem_setSelected(Handle, Value, True);
end;

procedure TIconViewItem.SetStates(const Value: TItemStates);
begin
  if FStates <> Value then
  begin
    FStates := Value;
    if not (isNone in FStates) then
    begin
      Selected := True;
      FStates := FStates - [isNone];
    end
    else
    begin
      Selected := False;
      FStates := [isNone];
    end;
  end;
end;

function TIconViewItem.TextRect: TRect;
begin
  if HandleAllocated then
    QIconViewItem_textRect(Handle, @Result, False)
  else
    Result := Rect(-1, -1, -1, -1);
end;

procedure TIconViewItem.UpdateImage;
var
  Imgs: TCustomImageList;
  EmptyPix: QPixmapH;
  Pixmap: QPixmapH;
begin
  if IconViewValid and FOwner.FOwner.HandleAllocated then
  begin
    EmptyPix := QPixmap_create;
    try
      Imgs := FOwner.FOwner.FImages;
      if Assigned(Imgs) then
      begin
        Pixmap := Imgs.GetPixmap(FImageIndex);
        if Assigned(Pixmap) then
          QIconViewItem_setPixmap(Handle, Pixmap)
        else
          QIconViewItem_setPixmap(Handle, EmptyPix);
      end
      else
        QIconViewItem_setPixmap(Handle, EmptyPix);      
    finally
      QPixmap_destroy(EmptyPix);
    end;
  end;
end;

{ TToolButton }

const
  TBSpacing = 3;

constructor TToolButton.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csCaptureMouse, csSetCaption, csClickEvents];
  FWidth := 23;
  FHeight := 22;
  FImageIndex := -1;
  FDown := False;
  FGrouped := False;
  FStyle := tbsButton;
  FAutoSize := False;
  FAllowAllUp := False;
  FIndeterminate := False;
  FMarked := False;
  FWrap := False;
end;

procedure TToolButton.MouseDown(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
var
  PopupPt: TPoint;
begin
  if (Style in [tbsDropDown, tbsButton, tbsCheck]) and (Button = mbLeft) and IsEnabled then
  begin
    if Down and Grouped and not AllowAllUp then
      ControlState := ControlState - [csClicked];
    FJustChecked := (Style = tbsCheck) and not Down;
    Down := True;

    if (Style = tbsDropDown) then
    begin
      if FMenuDropped then
      begin
        if Assigned(FDropDownMenu) then
          QWidget_hide(FDropDownMenu.Handle);
        FMenuDropped := False;
        Down := False;
      end else
      begin
        if PtInRect(DropDownRect, Types.Point(X, Y)) then
        begin
          PopupPt := ClientToScreen(Types.Point(0, Height));
          FMenuDropped := True;
          try
            if Assigned(FDropDownMenu) then
              QPopupMenu_exec(FDropDownMenu.Handle, @PopupPt, 0);
          finally
            FMenuDropped := False;
            Down := False;
            if GetMouseGrabControl = Self then
              SetMouseGrabControl(nil);
          end;
          Exit;
        end;
      end;
    end;
  end;
  inherited MouseDown(Button, Shift, X, Y);
end;

procedure TToolButton.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseMove(Shift, X, Y);
  if (Style = tbsDropDown) and MouseCapture then
    Down := (X >= 0) and (X < ClientWidth) and (Y >= 0) and (Y <= ClientHeight);
end;

procedure TToolButton.Click;
begin
  if not (Style in [tbsSeparator, tbsDivider]) then
    inherited Click;
end;

procedure TToolButton.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Operation = opRemove then
  begin
    if AComponent = DropDownMenu then
      DropDownMenu := nil;
  end;
end;

procedure TToolButton.ChangeBounds(ALeft, ATop, AWidth, AHeight: Integer);
var
  ResizeWidth,
  ResizeHeight: Boolean;
  NeedsUpdate: Boolean;
begin
  if ((AWidth <> Width) or (AHeight <> Height)) and
  (FToolBar <> nil) and (FToolBar.FResizeCount = 0)
  and not (csLoading in ComponentState) then
  begin
    NeedsUpdate := (Style in [tbsSeparator, tbsDivider]) and (AWidth <> Width) and
      not FToolBar.ShowCaptions;
    if Style = tbsDropDown then
      AWidth := FToolBar.ButtonWidth + AWidth - Width;
    ResizeWidth := not (Style in [tbsSeparator, tbsDivider]) and
      (AWidth <> FToolBar.ButtonWidth);
    ResizeHeight := AHeight <> FToolBar.ButtonHeight;
    if NeedsUpdate then inherited ChangeBounds(ALeft, ATop, AWidth, AHeight);
    if csDesigning in ComponentState then
    begin
      if ResizeWidth then FToolBar.ButtonWidth := AWidth;
      if ResizeHeight then FToolBar.ButtonHeight := AHeight;
    end;
  end else
    inherited ChangeBounds(ALeft, ATop, AWidth, AHeight);
end;

procedure TToolButton.Paint;
begin
  DoPaint(Canvas);
end;

procedure TToolButton.DoPaint(Canvas: TCanvas);

  function CaptionRect(var R: TRect): TRect;
  begin
    { R -> image rect. Result -> Text rect. }
    R.Right := R.Right - DropDownWidth;
    Result := R;
    if FToolBar.HasImages then
    begin
      if FToolBar.List then
      begin
        R.Left := R.Left + TBSpacing;
        R.Right := R.Left + FToolBar.FImageWidth;
        R.Top := ((R.Bottom - R.Top) div 2) - (FToolBar.FImageHeight div 2);
        R.Bottom := R.Top + FToolBar.FImageHeight;
        Result.Left := R.Right;
      end
      else begin
        R.Left := ((R.Right - R.Left) div 2) - (FToolBar.FImageWidth div 2);
        R.Top := R.Top + TBSpacing;
        R.Right := R.Left + FToolBar.FImageWidth;
        R.Bottom := R.Top + FToolBar.FImageHeight;
      end;
    end;
    if FToolBar.List then
      Result.Top := Result.Top + TBSpacing
    else if FToolBar.HasImages then
      Result.Top := R.Bottom + TBSpacing
    else
      Result.Top := R.Top + TBSpacing;
    Result.Left := Result.Left + TBSpacing;
    Result.Right := Result.Right - TBSpacing;
    Result.Bottom := Result.Bottom - TBSpacing;
  end;

  procedure DrawDropDown;
  var
    R: TRect;
    MidX,
    MidY: Integer;
    Pts: array of TPoint;
  begin
    R := DropDownRect;
    if Down and not FMenuDropped then
      OffsetRect(R, 2, 2);
    Canvas.Pen.Color := clButtonText;
    Canvas.Brush.Color := clButtonText;
    MidX := R.Left + (R.Right - R.Left) div 2;
    MidY := R.Top + (R.Bottom - R.Top) div 2;
    if FMenuDropped then
    begin
      MidX := MidX + 1;
      MidY := MidY + 1;
    end;
    SetLength(Pts, 4);
    Pts[0] := Types.Point(MidX - 2, MidY - 1);
    Pts[1] := Types.Point(MidX + 2, MidY - 1);
    Pts[2] := Types.Point(MidX, MidY + 1);
    Pts[3] := Pts[0];
    Canvas.Polygon(Pts);
    if FMenuDropped then
    begin
      if FToolBar.Flat then
      begin
        Dec(R.Top);
        Inc(R.Bottom);
        DrawEdge(Canvas, R, esNone, esLowered, ebRect);
      end
      else begin
        Dec(R.Top, 1);
        Inc(R.Bottom);
        DrawEdge(Canvas, R, esLowered, esLowered, ebRect);
      end
    end else
      if not FToolBar.Flat or (FToolBar.Flat and FMouseIn) then
        DrawEdge(Canvas, R, esRaised, esLowered, [ebLeft]);
  end;

var
  R: TRect;
  CR: TRect;
  DrawFlags: Integer;
  TBColor: TColor;
  BrushColor,
  PenColor,
  PatternColor: TColor;
  BrushStyle: TBrushStyle;
  PenStyle: TPenStyle;
  Ind: Boolean;
begin
  if FToolBar = nil then Exit;
  BrushStyle := Canvas.Brush.Style;
  PenStyle := Canvas.Pen.Style;
  BrushColor := Canvas.Brush.Color;
  PenColor := Canvas.Pen.Color;
  Ind := FIndeterminate and not Down;
  if Ind then
    PatternColor := clBtnHighlight
  else
    PatternColor := clHighlight;

  try
    if FToolBar.Flat then
      TBColor := FToolBar.Color
    else
      TBColor := clBtnFace;

    if Style in [tbsDropDown, tbsButton, tbsCheck] then
    begin
      DrawFlags := Integer(AlignmentFlags_ShowPrefix) or Integer(AlignmentFlags_AlignVCenter);
      if FToolBar.List then
        DrawFlags := DrawFlags or Integer(AlignmentFlags_AlignLeft)
      else
        DrawFlags := DrawFlags or Integer(AlignmentFlags_AlignHCenter);

      R := Types.Rect(0, 0, Width, Height);

      Canvas.Brush.Color := TBColor;
      if ((Down and (Style = tbsCheck)) or Ind or Marked) and IsEnabled then
      begin
        Canvas.TiledDraw(Rect(R.Left, R.Top, R.Right - DropDownWidth, R.Bottom),
          AllocPatternBitmap(clBtnFace, PatternColor));
        Canvas.FillRect(Rect(R.Right - DropDownWidth, R.Top, R.Right, R.Bottom));
      end
      else begin
        Canvas.Brush.Color := TBColor;
        Canvas.FillRect(R);
      end;

      if not FToolBar.Flat then
      begin
        DrawButtonFace(Canvas, R, 1, Down and not FMenuDropped, False,
          False, clNone);
        if Style = tbsDropDown then DrawDropDown;
      end
      else begin
        if not Down or FMenuDropped then
        begin
          if ((FMouseIn or FMenuDropped) and IsEnabled)
          or (csDesigning in ComponentState) then
            DrawEdge(Canvas, R, esNone, esRaised, [ebTop, ebLeft, ebRight, ebBottom])
          else if not (Ind or Marked) or not IsEnabled then
          begin
            Canvas.Brush.Color := TBColor;
            Canvas.FillRect(R);
          end;
        end
        else
          if not FMenuDropped then
          DrawEdge(Canvas, R, esNone, esLowered, [ebTop, ebLeft, ebRight, ebBottom]);
        if Style = tbsDropDown then DrawDropDown;
      end;

      R := ClientRect;
      CR := CaptionRect(R);
      if Down and not FMenuDropped then
      begin
        OffsetRect(R, 2, 2);
        OffsetRect(CR, 2, 2);
      end;

      //draw image
      Canvas.Brush.Style := bsSolid;
      if (FImageIndex > -1) and FToolBar.HasImages then
      begin
        Canvas.Brush.Color := TBColor;
        if not (Ind or Marked) or not IsEnabled then Canvas.FillRect(R);
        if Assigned(FToolBar.HotImages) and (FMouseIn or FMenuDropped) and IsEnabled
        and (FImageIndex < FToolBar.HotImages.Count) then
          FToolbar.HotImages.Draw(Canvas, R.Left, R.Top, FImageIndex, itImage, not Ind)
        else if Assigned(FToolBar.DisabledImages) and not IsEnabled and
          (FImageIndex < FToolBar.DisabledImages.Count) then
          FToolbar.DisabledImages.Draw(Canvas, R.Left, R.Top, FImageIndex,
            itImage, not Ind)
        else if Assigned(FToolBar.Images) and
          (FImageIndex < FToolBar.Images.Count) then
          FToolBar.Images.Draw(Canvas, R.Left, R.Top, FImageIndex, itImage,
            IsEnabled and not Ind);
      end;

      { draw caption }
      if (FCaption <> '') and FToolBar.FShowCaptions then
      begin
        Canvas.Font := FToolBar.Font;
        if not IsEnabled then
          Canvas.Font.Color := clDisabledText;
        Canvas.TextRect(CR, CR.Left, CR.Top, FCaption, DrawFlags);
      end;
    end;

    if (Style = tbsSeparator) and FToolBar.Flat then
    begin
      R := Types.Rect(Width div 2, 3, Width, Height - 3);
      DrawEdge(Canvas, R, esRaised, esLowered, [ebLeft]);
    end;

    if Style = tbsDivider then
    begin
      R := Types.Rect(Width div 2, 1, Width, Height - 2);
      DrawEdge(Canvas, R, esRaised, esLowered, [ebLeft]);
    end;

    if (Style in [tbsSeparator, tbsDivider]) and (csDesigning in ComponentState) then
    begin
      Canvas.Pen.Style := psDot;
      Canvas.Pen.Color := clBlack;
      Canvas.Brush.Style := bsClear;
      Canvas.Rectangle(ClientRect);
    end;

  finally
    Canvas.Brush.Style := BrushStyle;
    Canvas.Pen.Style := PenStyle;
    Canvas.Brush.Color := BrushColor;
    Canvas.Pen.Color := PenColor;
  end;
end;

procedure TToolButton.SetAutoSize(Value: Boolean);
begin
  if Value <> AutoSize then
  begin
    FAutoSize := Value;
    if not (csLoading in ComponentState) and (FToolBar <> nil) and
      FToolBar.ShowCaptions then
    begin
      FToolBar.ResizeButtons(Self);
    end;
  end;
end;

procedure TToolButton.SetName(const Value: TComponentName);
var
  ChangeText: Boolean;
begin
  ChangeText := Name = Caption;
  inherited SetName(Value);
  if ChangeText then Caption := Value;  
end;

procedure TToolButton.SetParent(const Value: TWidgetControl);
begin
  inherited SetParent(Value);
  if Value is TToolBar then FToolBar := TToolBar(Value);
end;


procedure TToolButton.SetToolBar(AToolBar: TToolBar);
begin
  if FToolBar <> AToolBar then
  begin
    FToolBar := AToolBar;
    Parent := FToolBar;
    FToolBar.ResizeButtons(Self);
  end;
end;

procedure TToolButton.SetDown(Value: Boolean);
begin
  if Value <> FDown then
  begin
    FDown := Value;
    Invalidate;
    if FToolBar <> nil then
    begin
      if Grouped and (Style = tbsCheck) and (FToolBar <> nil) then
        FToolBar.GroupChange(Self, gcDownState);
    end;
  end;
end;

procedure TToolButton.SetDropDownMenu(Value: TPopupMenu);
begin
  if Value <> FDropDownMenu then
  begin
    FDropDownMenu := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

procedure TToolButton.SetGrouped(Value: Boolean);
begin
  if FGrouped <> Value then
  begin
    FGrouped := Value;
  end;
end;

procedure TToolButton.SetImageIndex(Value: TImageIndex);
begin
  if FImageIndex <> Value then
  begin
    FImageIndex := Value;
    Invalidate;
  end;
end;

procedure TToolButton.SetMarked(Value: Boolean);
begin
  if FMarked <> Value then
  begin
    FMarked := Value;
    Invalidate;
  end;
end;

procedure TToolButton.SetIndeterminate(Value: Boolean);
begin
  if FIndeterminate <> Value then
  begin
    if Value then SetDown(False);
    FIndeterminate := Value;
    Invalidate;
  end;
end;

procedure TToolButton.SetStyle(Value: TToolButtonStyle);
var
  ResizeNeeded: Boolean;
begin
  if FStyle <> Value then
  begin
    ResizeNeeded := (Value = tbsDropDown) or
      (Style in [tbsDropDown, tbsSeparator, tbsDivider]);
    FStyle := Value;
    if not (csLoading in ComponentState) and (FToolBar <> nil) then
    begin
      if FToolBar.ShowCaptions then
      begin
//        FToolBar.FButtonWidth := 0;
//        FToolBar.FButtonHeight := 0;
        FToolBar.ResizeButtons(nil);
      end;
      if ResizeNeeded then
        FToolBar.ResizeButtons(Self);
    end;
//    if Style in [tbsSeparator, tbsDivider] then
//      Wrap := True;
    if ResizeNeeded then
      FToolBar.Realign
    else
      Invalidate;
  end;
end;

procedure TToolButton.SetWrap(Value: Boolean);
begin
  if FWrap <> Value then
  begin
    FWrap := Value;
    if FToolBar <> nil then
      FToolBar.Realign;
  end;
end;

procedure TToolButton.BeginUpdate;
begin
  Inc(FUpdateCount);
end;

function TToolButton.DropDownWidth: Integer;
begin
  if Style = tbsDropDown then
    Result := 14
  else
    Result := 0;
end;

procedure TToolButton.EndUpdate;
begin
  Dec(FUpdateCount);
end;

function TToolButton.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
{$IFDEF MSWINDOWS}
var
  P: PPoint;
{$ENDIF}
begin
  if QEvent_type(Event) = QEventType_MouseButtonRelease then
  begin
    if (Style in [tbsDropDown, tbsButton])
    and (QMouseEvent_button(QMouseEventH(Event)) = ButtonState_LeftButton) and IsEnabled then
    begin
{$IFDEF MSWINDOWS}
      if Style = tbsDropDown then
      begin
        P := QMouseEvent_pos(QMouseEventH(Event));
        Result := PtInRect(DropDownRect, P^);
        if Result then Exit;
      end;
{$ENDIF}
      Down := False;
    end;
    if (Style = tbsCheck) and not FJustChecked and (not Grouped or AllowAllUp) then
    Down := False;
    FJustChecked := False;
  end;
  Result := inherited EventFilter(Sender, Event);
end;

procedure TToolButton.InitWidget;
begin
  QWidget_setFocusPolicy(Handle, QWidgetFocusPolicy_NoFocus);
end;

function TToolButton.IsEnabled: Boolean;
begin
  Result := Enabled;
  if FToolBar <> nil then Result := Result and FToolBar.Enabled;
end;


function TToolButton.GetIndex: Integer;
begin
  Result := -1;
  if FToolBar <> nil then
    Result := FToolBar.FControls.IndexOf(Self);
end;

function TToolButton.IsWidthStored: Boolean;
begin
  Result := Style in [tbsSeparator, tbsDivider];
end;

function TToolButton.CheckMenuDropDown: Boolean;
begin
  Result := False;
{  Result := not (csDesigning in ComponentState) and ((DropdownMenu <> nil) and
    DropdownMenu.AutoPopup or (MenuItem <> nil)) and (FToolBar <> nil) and
    FToolBar.CheckMenuDropdown(Self);}
end;

function TToolButton.IsCheckedStored: Boolean;
begin
  Result := (ActionLink = nil) or not TToolButtonActionLink(ActionLink).IsCheckedLinked;
end;

function TToolButton.IsImageIndexStored: Boolean;
begin
  Result := (ActionLink = nil) or not TToolButtonActionLink(ActionLink).IsImageIndexLinked;
end;

procedure TToolButton.ActionChange(Sender: TObject; CheckDefaults: Boolean);
begin
  inherited ActionChange(Sender, CheckDefaults);
  if Sender is TCustomAction then
    with TCustomAction(Sender) do
    begin
      if not CheckDefaults or (Self.Down = False) then
        Self.Down := Checked;
      if not CheckDefaults or (Self.ImageIndex = -1) then
        Self.ImageIndex := ImageIndex;
    end;
end;

function TToolButton.GetActionLinkClass: TControlActionLinkClass;
begin
  Result := TToolButtonActionLink;
end;

procedure TToolButton.AssignTo(Dest: TPersistent);
begin
  inherited AssignTo(Dest);
  if Dest is TCustomAction then
    with TCustomAction(Dest) do
    begin
      Checked := Self.Down;
      ImageIndex := Self.ImageIndex;
    end;
end;

procedure TToolButton.ValidateContainer(AComponent: TComponent);
var
  W: Integer;
begin
  inherited ValidateContainer(AComponent);
  { Update non-stored Width and Height if inserting into TToolBar }
  if (csLoading in ComponentState) and (AComponent is TToolBar) then
  begin
    if Style in [tbsDivider, tbsSeparator] then
      W := Width else
      W := TToolBar(AComponent).ButtonWidth;
    SetBounds(Left, Top, W, TToolBar(AComponent).ButtonHeight);
  end;
end;

function TToolButton.GetText: TCaption;
begin
  Result := FCaption;
end;

procedure TToolButton.SetText(const Value: TCaption);
begin
  if FCaption <> Value then
  begin
    FCaption := Value;       
    if Assigned(FToolBar) then FToolBar.ResizeButtons(nil);
    Invalidate;
  end;
end;

procedure TToolButton.SetAllowAllUp(const Value: Boolean);
begin
  if FAllowAllUp <> Value then
  begin
    FAllowAllUp := Value;
    if FToolBar <> nil then
      FToolBar.GroupChange(Self, gcAllowAllUp);
  end;
end;

procedure TToolButton.MouseEnter(AControl: TControl);
begin
  inherited MouseEnter(AControl);
  FMouseIn := True;
  Paint;
end;

procedure TToolButton.MouseLeave(AControl: TControl);
begin
  inherited MouseLeave(AControl);
  FMouseIn := False;
  Paint;
end;

function TToolButton.DropDownRect: TRect;
begin
  Result := Types.Rect(Width - DropDownWidth, 1, Width, Height - 1);
end;

function TToolButton.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  if IsAccel(Key, Caption) and (ssAlt in Shift) then
  begin
    Click;
    Result := True;
  end else
    Result := inherited WantKey(Key, Shift, KeyText);
end;

{ TToolBar }

function TBControlSort(Item1, Item2: Pointer): Integer;
var
  C1, C2: TControl;
begin
  Result := 0;
  C1 := TControl(Item1);
  C2 := TControl(Item2);
  if C1 = C2 then Exit;
  if C1.Top = C2.Top then
  begin
    if C1.Left <= C2.Left then
      Result := -1
    else
      Result := 1
  end
  else begin
    if C1.Top < C2.Top then
      Result := -1
    else
      Result := 1;
  end;
end;

function TToolBar.ButtonCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to ControlCount - 1 do
    if (Controls[I] is TToolButton) then Inc(Result);
end;

procedure TToolBar.ControlsAligned;
begin
  inherited ControlsAligned;
  FControls.Sort(@TBControlSort);
  DoResize;
end;

procedure TToolBar.ControlsListChanged(Control: TControl;
  Inserting: Boolean);
begin
  inherited ControlsListChanged(Control, Inserting);
  if Inserting then
  begin
    if LastControl <> nil then
    begin
      Control.Left := LastControl.Left + LastControl.Width;
      Control.Top := LastControl.Top;
    end
    else begin
      Control.Left := ClientRect.Left;
      Control.Top := ClientRect.Top;
    end;
    Control.Height := FButtonHeight;
    if Control is TWidgetControl then
      TWidgetControl(Control).HandleNeeded;
    if (Control is TToolButton)
    and not (TToolButton(Control).Style in [tbsSeparator, tbsDivider])
    and not TToolButton(Control).AutoSize then
    begin
      Inc(FResizeCount);
      try
        Control.Width := FButtonWidth;
      finally
        Dec(FResizeCount);
      end;
    end;
    Control.Align := alCustom;
    FControls.Add(Control);
  end
  else
    FControls.Remove(Control);
  Realign;
  if AutoSize then AdjustSize;
end;

constructor TToolBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FControls := TList.Create;
  ControlStyle := [csAcceptsControls, csCaptureMouse, csClickEvents,
    csDoubleClicks, csMenuEvents, csSetCaption, csNoFocus];
  FResizeCount := 0;
  Width := 150;
  Height := 29;
  Align := alTop;
  FButtonWidth := 23;
  FButtonHeight := 22;
  FBorderWidth := 0;
  FIndent := 1;
  FAutoSize := False;
  FList := False;
  FEdgeBorders := [ebTop];
  FEdgeInner := esRaised;
  FEdgeOuter := esLowered;
  Wrapable := True;
  FImageChangeLink := TChangeLink.Create;
  FImageChangeLink.OnChange := ImageListChange;
end;

procedure TToolBar.AdjustClientRect(var Rect: TRect);
begin
  Rect.Left := FIndent + FBorderWidth + EdgeSpacing(ebLeft);
  Rect.Right := Width - 2 - FBorderWidth + EdgeSpacing(ebRight);
  Rect.Top := 2 + FBorderWidth + EdgeSpacing(ebTop);
  Rect.Bottom := Height - 3 - FBorderWidth + EdgeSpacing(ebBottom);
end;

function TToolBar.GetControl(Index: Integer): TControl;
begin
  Result := TControl(FControls[Index]);
end;

procedure TToolBar.Paint;
begin
  inherited Paint;
  DoPaint(Canvas);
end;

procedure TToolBar.DoResize;
begin
  if not AutoSize then Exit;
  AdjustSize;
end;

procedure TToolBar.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Operation = opRemove then
  begin
    if AComponent = FImages then
    begin
      FImages := nil;
      Repaint;
    end;
    if AComponent = FDisabledImages then
    begin
      FDisabledImages := nil;
      Repaint;
    end;
    if AComponent = FHotImages then
    begin
      FHotImages := nil;
      Repaint;
    end;
  end;
end;

procedure TToolBar.SetAutoSize(const Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    DoResize;
  end;
end;

procedure TToolBar.SetButtonHeight(const Value: Integer);
var
  I: Integer;
begin
  if FButtonHeight <> Value then
  begin
    Inc(FResizeCount);
    try
      ControlState := ControlState + [csAlignDisabled];
      try
        FButtonHeight := Value;
        for I := 0 to ControlCount - 1 do
          Controls[I].Height := FButtonHeight;
      finally
        ControlState := ControlState - [csAlignDisabled];
        Realign;
      end;
    finally
      Dec(FResizeCount);
    end;
  end;
end;

procedure TToolBar.InternalSetButtonWidth(const Value: Integer; RestrictSize: Boolean);
var
  I: Integer;
begin
  if RestrictSize and ShowCaptions then Exit;
  ControlState := ControlState + [csAlignDisabled];
  Inc(FResizeCount);
  try
    FButtonWidth := Value;
    for I := 0 to ControlCount - 1 do
      if Controls[I] is TToolButton then
      with TToolButton(Controls[I]) do
      begin
        if not AutoSize and not (Style in [tbsSeparator, tbsDivider]) then
          Width := FButtonWidth + DropDownWidth
        else
          Width := Width + DropDownWidth;
      end;
  finally
    Dec(FResizeCount);
    ControlState := ControlState - [csAlignDisabled];
    ReAlign;
  end;
end;

procedure TToolBar.SetButtonWidth(const Value: Integer);
begin
  InternalSetButtonWidth(Value, True);
end;

procedure TToolBar.SetWrapable(const Value: Boolean);
begin
  if FWrapable <> Value then
  begin
    FWrapable := Value;
    Realign;
  end;
end;

function TToolBar.LastControl: TControl;
begin
  Result := nil;
  if ControlCount > 0 then
    Result := Controls[ControlCount - 1];
end;

procedure TToolBar.Loaded;
begin
  inherited Loaded;
  SetButtonWidth(FButtonWidth);
end;

procedure TToolBar.SetBorderWidth(const Value: TBorderWidth);
begin
  if FBorderWidth <> Value then
  begin
    FBorderWidth := Value;
    Realign;
  end;
end;

procedure TToolBar.SetEdgeBorders(const Value: TEdgeBorders);
begin
  FEdgeBorders := Value;
  DoResize;
  Invalidate;
end;

procedure TToolBar.SetEdgeInner(const Value: TEdgeStyle);
begin
  FEdgeInner := Value;
  DoResize;
  Invalidate;
end;

procedure TToolBar.SetEdgeOuter(const Value: TEdgeStyle);
begin
  FEdgeOuter := Value;
  DoResize;
  Invalidate;
end;

function TToolBar.EdgeSpacing(Edge: TEdgeBorder): Integer;
begin
  Result := 0;
  if (Edge in FEdgeBorders) then
  begin
    if FEdgeInner in [esRaised, esLowered] then Inc(Result);
    if FEdgeOuter in [esRaised, esLowered] then Inc(Result);
  end;
end;

procedure TToolBar.AdjustSize;
var
  NewHeight: Integer;
begin
  if FAutoSize and (FControls.Count > 0) then
  begin
    NewHeight := 0;
    case Align of
      alTop, alBottom:
        begin
          if LastControl <> nil then
            NewHeight := LastControl.Top + LastControl.Height;
          NewHeight :=  NewHeight + FBorderWidth + EdgeSpacing(ebBottom);
          Height := NewHeight;
        end;
      alLeft, alRight:
        Width := FRightEdge + FBorderWidth + EdgeSpacing(ebLeft)
          + EdgeSpacing(ebRight);
    end;
  end;
end;

procedure TToolBar.SetIndent(const Value: Integer);
begin
  if FIndent <> Value then
  begin
    FIndent := Value;
    DoResize;
    Realign;
  end;
end;

procedure TToolBar.SetFlat(const Value: Boolean);
begin
  FFlat := Value;
  Invalidate;
end;

procedure TToolBar.SetShowCaptions(const Value: Boolean);
begin
  if FShowCaptions <> Value then
  begin
    FShowCaptions := Value;
    FButtonHeight := 0;
    FButtonWidth := 0;
    ResizeButtons(nil);
  end;
end;

procedure TToolBar.SetDisabledImages(const Value: TCustomImageList);
begin
  if FDisabledImages <> nil then FDisabledImages.UnRegisterChanges(FImageChangeLink);
  FDisabledImages := Value;
  if FDisabledImages <> nil then
  begin
    FDisabledImages.RegisterChanges(FImageChangeLink);
    FDisabledImages.FreeNotification(Self);
  end;
  ImageListChange(Value);
end;

procedure TToolBar.SetHotImages(const Value: TCustomImageList);
begin
  if FHotImages <> nil then FHotImages.UnRegisterChanges(FImageChangeLink);
  FHotImages := Value;
  if FHotImages <> nil then
  begin
    FHotImages.RegisterChanges(FImageChangeLink);
    FHotImages.FreeNotification(Self);
  end;
  ImageListChange(Value);
end;

procedure TToolBar.SetImages(const Value: TCustomImageList);
begin
  if FImages <> nil then FImages.UnRegisterChanges(FImageChangeLink);
  FImages := Value;
  if FImages <> nil then
  begin
    FImages.RegisterChanges(FImageChangeLink);
    FImages.FreeNotification(Self);
  end;
  ImageListChange(Value);
end;

procedure TToolBar.ImageListChange(Sender: TObject);
begin
  FImageWidth := 0;
  FImageHeight := 0;
  if Assigned(FImages) then
  begin
    FImageWidth := FImages.Width;
    FImageHeight := FImages.Height;
  end
  else if Assigned(FHotImages) then
  begin
    FImageWidth := FHotImages.Width;
    FImageHeight := FHotImages.Height;
  end
  else if Assigned(FDisabledImages) then
  begin
    FImageWidth := FDisabledImages.Width;
    FImageHeight := FDisabledImages.Height;
  end;
  ResizeButtons(nil);
  Invalidate;
end;

procedure TToolBar.ResizeButtons(Button: TToolButton);
var
  BtnIndex,
  I: Integer;
  NewWidth,
  NewHeight,
  AWidth,
  AHeight: Integer;
  ABtn: TToolButton;
  ASize: TSize;
  AImageList: TCustomImageList;
begin
  Inc(FResizeCount);
  ControlState := ControlState + [csAlignDisabled];
  ABtn := nil;
  AWidth := 0;
  try
    if Button <> nil then
      BtnIndex := FControls.IndexOf(Button)
    else
      BtnIndex := 0;
    if not ShowCaptions then
    begin
      NewWidth := ButtonWidth; //is this necessary??
      NewHeight := ButtonHeight;
    end else
    begin
      NewWidth := 0;
      NewHeight := 0;
    end;
    for I := BtnIndex to ControlCount - 1 do
    begin
      if Controls[I] is TToolButton then
      begin
        ABtn := TToolButton(Controls[I]);
        if ABtn.Style in [tbsSeparator, tbsDivider] then Continue;
        AWidth := 23;
        AHeight := 22;
        if not FShowCaptions and HasImages then
        begin
          if Assigned(Images) then
            AImageList := Images
          else if Assigned(DisabledImages) then
            AImageList := DisabledImages
          else if Assigned(HotImages) then
            AImageList := HotImages
          else
            AImageList := nil;
          if AImageList <> nil then
          begin
            AWidth := AImageList.Width + (TBSpacing *2) + 1;
            AHeight := AImageList.Height + (TBSpacing *2) + 1;
          end;
        end;
        if (ABtn.Caption <> '') and (ABtn.Style in [tbsButton, tbsCheck, tbsDropDown])
        and FShowCaptions then
        begin
          ASize := Canvas.TextExtent(ABtn.Caption, Integer(AlignmentFlags_ShowPrefix) or
            Integer(AlignmentFlags_AlignCenter));
          AWidth :=  ASize.cx + (TBSpacing * 3);
          AHeight := ASize.cy + (TBSpacing * 2) + 1;
          if HasImages then
          begin
            if FList then
              AWidth := AWidth + TBSpacing + FImageWidth
            else
              AHeight := AHeight + TBSpacing + FImageHeight;
            if AHeight < (FImageHeight + (TBSpacing * 2) + 1) then
               AHeight := FImageHeight + (TBSpacing *2) + 1;
          end;
        end;
        if AHeight > NewHeight then NewHeight := AHeight;
        if AWidth > NewWidth then NewWidth := AWidth;
        if ABtn.AutoSize then
          ABtn.Width := AWidth;
      end;

      if ABtn <> nil then
        if ABtn.AutoSize then
          ABtn.Width := AWidth + ABtn.DropDownWidth
//        else if not ShowCaptions then
//          ABtn.Width := ButtonWidth + ABtn.DropDownWidth;

    end;
  finally
    Dec(FResizeCount);
    ControlState := ControlState - [csAlignDisabled];
  end;
  if NewHeight = 0 then
    ButtonHeight := 22
  else
    ButtonHeight := NewHeight;
  if NewWidth = 0 then
    InternalSetButtonWidth(23, False)
  else
    InternalSetButtonWidth(NewWidth, False);

  AdjustSize;
  Invalidate;
end;

procedure TToolBar.SetList(const Value: Boolean);
begin
  FList := Value;
  ResizeButtons(nil);
end;

destructor TToolBar.Destroy;                                                  
begin
  FControls.Free;
  FImageChangeLink.Free;
  inherited Destroy;
end;

procedure TToolBar.GroupChange(Requestor: TToolButton; Reason: TGroupChangeReason);

  procedure ApplyToGroup(Index: Integer; Dir: SmallInt;
    Reason: TGroupChangeReason);
  var
    Control: TControl;
  begin
    Inc(Index, Dir);
    while (Index >= 0) and (Index < ControlCount) do
    begin
      Control := Controls[Index];
      if (Control is TToolButton) and TToolButton(Control).Grouped then
        case Reason of
          gcAllowAllUp:
            TToolButton(Control).FAllowAllUp := Requestor.AllowAllUp;
          gcDownState:
            begin
              TToolButton(Control).FDown := False;
              Control.Invalidate;
            end;
        end
      else Break;
      Inc(Index, Dir);
    end;
  end;

begin
  ApplyToGroup(FControls.IndexOf(Requestor), -1, Reason);
  ApplyToGroup(FControls.IndexOf(Requestor), 1, Reason);
end;

function TToolBar.CustomAlignInsertBefore(C1, C2: TControl): Boolean;
begin
  Result := False;
  case Align of
    alTop, alBottom, alNone, alClient:
      if C1.Top = C2.Top then
        Result := C1.Left < C2.Left
      else
        Result := C1.Top < C2.Top;
    alLeft, alRight:
      if C1.Left = C2.Left then
        Result := C1.Top < C2.Top
      else
        Result := C1.Left < C2.Left;
  end;
  FRightEdge := 0;
end;

procedure TToolBar.CustomAlignPosition(Control: TControl; var NewLeft, NewTop, NewWidth,
      NewHeight: Integer; var AlignRect: TRect);
begin
  if Wrapable then
  begin
    case Align of
      alTop, alBottom, alNone, alClient:
        if (((AlignRect.Left + Control.Width) > AlignRect.Right)
        and (AlignRect.Left > ClientRect.Left)) then
        begin
          Inc(AlignRect.Top, NewHeight);
          NewLeft := ClientRect.Left;
          AlignRect.Left := NewLeft + Control.Width;
          NewTop := AlignRect.Top;
        end else
          Inc(AlignRect.Left, NewWidth);
     alLeft, alRight:
       begin
         if (((AlignRect.Top + Control.Height) > AlignRect.Bottom)
         and (AlignRect.Top > ClientRect.Top)) then
         begin
           AlignRect.Left := FRightEdge;
           NewTop := ClientRect.Top;
           AlignRect.Top := NewTop + Control.Height;
           NewLeft := AlignRect.Left;
         end else
           Inc(AlignRect.Top, NewHeight);
         if AlignRect.Left + Control.Width > FRightEdge then
           FRightEdge := AlignRect.Left + Control.Width;
       end;
    end
  end else
  begin
    case Align of
      alTop, alBottom, alNone, alClient:
        begin
          NewLeft := AlignRect.Left;
          NewTop := AlignRect.Top;
          if (Control is TToolButton)
          and TToolButton(Control).Wrap then
          begin
            Inc(AlignRect.Top, ButtonHeight);
            AlignRect.Left := ClientRect.Left;
          end else
            Inc(AlignRect.Left, NewWidth);
        end;
      alLeft, alRight:
        begin
          NewLeft := AlignRect.Left;
          NewTop := AlignRect.Top;
          if (Control is TToolButton)
          and TToolButton(Control).Wrap then
          begin
            Inc(AlignRect.Left, ButtonWidth);
            AlignRect.Top := ClientRect.Top;
          end else
            Inc(AlignRect.Top, NewHeight);
          if AlignRect.Left + Control.Width > FRightEdge then
           FRightEdge := AlignRect.Left + Control.Width;
        end;
    end;
  end;
end;

function TToolBar.HasImages: Boolean;
begin
  Result := (FImages <> nil) or (FDisabledImages <> nil) or
    (FHotImages <> nil);
end;

procedure TToolBar.Invalidate;
var
  I: Integer;
begin
  inherited Invalidate;
  for I := 0 to ControlCount - 1 do
    Controls[I].Invalidate;
end;

function TToolBar.ControlCount: Integer;
begin
  Result := FControls.Count;
end;

procedure TToolBar.DoPaint(ACanvas: TCanvas);
var
  R: TRect;
begin
  if not Masked and not Assigned(Bitmap) then
  begin
    ACanvas.Brush.Color := Color;
    ACanvas.FillRect(BoundsRect);
  end;
  R := Types.Rect(0, 0, Width, Height);
  DrawEdge(ACanvas, R, FEdgeInner, FEdgeOuter, FEdgeBorders);
end;

procedure TToolBar.FontChanged;
begin
  inherited FontChanged;
  Canvas.Font := Font;
  ResizeButtons(nil);
end;

procedure TToolBar.InitWidget;
begin
  inherited;
  TabStop := False;
end;

function TToolBar.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  if (QEvent_type(Event) = QEventType_Resize) then
    Result := True
  else
    Result := inherited EventFilter(Sender, Event);
end;

{ TToolButtonActionLink }

procedure TToolButtonActionLink.AssignClient(AClient: TObject);
begin
  inherited AssignClient(AClient);
  FClient := AClient as TToolButton;
end;

function TToolButtonActionLink.IsCheckedLinked: Boolean;
begin
  Result := inherited IsCheckedLinked and
    (FClient.Down = (Action as TCustomAction).Checked);
end;

function TToolButtonActionLink.IsImageIndexLinked: Boolean;
begin
  Result := inherited IsImageIndexLinked and
    (FClient.ImageIndex = (Action as TCustomAction).ImageIndex);
end;

procedure TToolButtonActionLink.SetChecked(Value: Boolean);
begin
  if IsCheckedLinked then FClient.Down := Value;
end;

procedure TToolButtonActionLink.SetImageIndex(Value: Integer);
begin
  if IsImageIndexLinked then FClient.ImageIndex := Value;
end;

{ TIconOptions }

constructor TIconOptions.Create(AOwner: TCustomIconView);
begin
  inherited Create;
  FIconView := AOwner;
  FArrangement := iaLeft;
  FAutoArrange := True;
  FWrapText := True;
end;

procedure TIconOptions.SetArrangement(Value: TIconArrangement);
begin
  if (FArrangement <> Value) then
  begin
    FArrangement := Value;
    if FIconView.HandleAllocated then
      QIconView_setArrangement(FIconView.Handle, cIVQtArrangement[FArrangement]);
  end;
end;

procedure TIconOptions.SetAutoArrange(Value: Boolean);
begin
  if (FAutoArrange <> Value) then
  begin
    FAutoArrange := Value;
    if FIconView.HandleAllocated then
      QIconView_setAutoArrange(FIconView.Handle, FAutoArrange);
  end;
end;

procedure TIconOptions.SetWrapText(Value: Boolean);
begin
  if (FWrapText <> Value) then
  begin
    FWrapText := Value;
    if FIconView.HandleAllocated then
      QIconView_setWordWrapIconText(FIconView.Handle, FWrapText);
  end;
end;

end.
