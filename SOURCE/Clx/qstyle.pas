{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QStyle;

{$R-,T-,H+,X+}

interface

uses
  QTypes, Classes, Types, Qt, QGraphics;

type
  TScrollBarControl = (sbcAddButton, sbcSubButton, sbcAddPage, sbcSubPage,
    sbcSlider, sbcNone);
  TScrollBarControls = set of TScrollBarControl;

  TBeforeDrawButtonEvent = procedure(Sender, Source: TObject; Canvas: TCanvas;
    var DefaultDraw: Boolean) of object;
  TAfterDrawButtonEvent = procedure(Sender, Source: TObject; Canvas: TCanvas) of object;
  TBeforeDrawMenuItemEvent = procedure(Sender, Source: TObject; Canvas: TCanvas;
    Highlighted, Enabled: Boolean; const Rect: TRect; Checkable: Boolean;
    CheckMaxWidth, LabelWidth: Integer; var DefaultDraw: Boolean) of object;
  TAfterDrawMenuItemEvent = procedure(Sender, Source: TObject; Canvas: TCanvas;
    Highlighted, Enabled: Boolean; const Rect: TRect; Checkable: Boolean;
    CheckMaxWidth, LabelWidth: Integer) of object;
  TDrawButtonFrameEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Down: Boolean; var DefaultDraw: Boolean) of object;
  TDrawFocusRectEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    AtBorder: Boolean; var DefaultDraw: Boolean) of object;
  TDrawHintEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    var DefaultDraw: Boolean) of object;
  TDrawCheckEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Checked, Grayed, Down, Enabled: Boolean; var DefaultDraw: Boolean) of object;
  TDrawMenuFrameEvent = procedure(Sender: TObject; Canvas: TCanvas; const R: TRect;
    LineWidth: Integer; var DefaultDraw: Boolean) of object;
  TDrawRadioEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Checked, Down, Enabled: Boolean; var DefaultDraw: Boolean) of object;
  //only called when QFrame::FrameStyle = StyledPanel
  TDrawFrameEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Sunken: Boolean; LineWidth: Integer; var DefaultDraw: Boolean) of object;
  TDrawMenuCheckEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Checked, Enabled: Boolean) of object;
  TBeforeDrawItemEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect; Flags: Integer;
    Enabled: Boolean; Bitmap: TBitmap; const Text: WideString; Length: Integer; Color: TColor;
    var DefaultDraw: Boolean) of object;
  TAfterDrawItemEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect; Flags: Integer;
    Enabled: Boolean; Bitmap: TBitmap; const Text: WideString; Length: Integer; Color: TColor) of object;
  TDrawComboButtonEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Sunken, ReadOnly, Enabled: Boolean; var DefaultDraw: Boolean) of object;
  TDrawMaskEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect) of object;
  TDrawRadioMaskEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect; Checked: Boolean) of object;
  TGetItemRectEvent = procedure(Sender: TObject; Canvas: TCanvas; var Rect: TRect; Flags: Integer;
    Enabled: Boolean; Bitmap: TBitmap; const Text: WideString) of object;
  TPolishEvent = procedure(Sender, Source: TObject) of object;
  TDrawHeaderSectionEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Down: Boolean; var DefaultDraw: Boolean) of object;
  TButtonRectEvent = procedure(Sender: TObject; var Rect: TRect) of object;
  TDrawArrowEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect; Arrow: ArrowType; Down, Enabled: Boolean) of object;
  TDrawCheckMaskEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Checked, Grayed: Boolean) of object;
  TTabMetricsEvent = procedure(Sender, Source: TObject; var HorizonalPadding, VerticalPadding,
    Overlap: Integer) of object;
  TDrawTabEvent = procedure(Sender, Source: TObject; Canvas: TCanvas; Index, HorizonalPadding,
    VerticalPadding, Overlap: Integer; Selected: Boolean) of object;
  TScrollBarMetricsEvent = procedure(Sender: TObject; ScrollBar: QScrollBarH; var SliderLength,
    ButtonSize: Integer) of object;
  TDrawScrollBarEvent = procedure(Sender: TObject; ScrollBar: QScrollBarH; Canvas: TCanvas;
    const Rect: TRect; SliderStart, SliderLength, ButtonSize: Integer; Controls: TScrollBarControls;
    DownControl: TScrollBarControl; var DefaultDraw: Boolean) of object;
  TDrawTrackBarEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect; Horizontal,
    TickAbove, TickBelow: Boolean; var DefaultDraw: Boolean) of object;
  TDrawTrackBarGrooveEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Horizontal: Boolean; var DefaultDraw: Boolean) of object;
  TDrawSplitterEvent = procedure(Sender: TObject; Canvas: TCanvas; const Rect: TRect;
    Vertical: Boolean; var DefaultDraw: Boolean) of object;
  TExtraMenuItemWidthEvent = procedure(Sender, Source: TObject; HasCheckmark: Boolean;
    ImageWidth: Integer; FontMetrics: QFontMetricsH; var ExtraWidth: Integer) of object;
  TSubmenuIndicatorWidthEvent = procedure(Sender: TObject; FontMetrics: QFontMetricsH;
    var Width: Integer) of object;
  TMenuItemHeightEvent = procedure(Sender, Source: TObject; Checkable: Boolean;
    FontMetrics: QFontMetricsH; var Height: Integer) of object;

  TDefaultStyle = (dsWindows,
                   dsMotif,
                   dsMotifPlus,
                   dsCDE,
                   dsQtSGI,
                   dsPlatinum,
                   dsSystemDefault);

  { TStyle }
  TStyle = class
  private
    FHandle: QClxStyleH;
    FHooks: QClxStyleHooksH;
    FOnChange: TNotifyEvent;
    FDrawFocusRect: TDrawFocusRectEvent;
    FBeforeDrawMenuItem: TBeforeDrawMenuItemEvent;
    FAfterDrawMenuItem: TAfterDrawMenuItemEvent;
    FDrawMenuFrame: TDrawMenuFrameEvent;
    FBeforeDrawButton: TBeforeDrawButtonEvent;
    FAfterDrawButton: TAfterDrawButtonEvent;
    FDrawButtonFrame: TDrawButtonFrameEvent;
    FDrawButtonLabel: TBeforeDrawButtonEvent;
    FDrawCheck: TDrawCheckEvent;
    FDrawRadio: TDrawRadioEvent;
    FDefaultStyle: TDefaultStyle;
    FDrawMenuCheck: TDrawMenuCheckEvent;
    FAfterDrawItem: TAfterDrawItemEvent;
    FBeforeDrawItem: TBeforeDrawItemEvent;
    FDrawComboButton: TDrawComboButtonEvent;
    FDrawButtonMask: TDrawMaskEvent;
    FGetItemRect: TGetItemRectEvent;
    FDrawHeaderSection: TDrawHeaderSectionEvent;
    FDrawHint: TDrawHintEvent;
    FHeaderSectionRect: TButtonRectEvent;
    FButtonRect: TButtonRectEvent;
    FDrawArrow: TDrawArrowEvent;
    FDrawRadioMask: TDrawRadioMaskEvent;
    FDrawCheckMask: TDrawCheckMaskEvent;
    FComboButtonRect: TButtonRectEvent;
    FComboButtonFocusRect: TButtonRectEvent;
    FDrawComboButtonMask: TDrawMaskEvent;
    FTabMetrics: TTabMetricsEvent;
    FDrawTab: TDrawTabEvent;
    FDrawTabMask: TDrawTabEvent;
    FScrollBarMetrics: TScrollBarMetricsEvent;
    FDrawScrollBar: TDrawScrollBarEvent;
    FDrawTrackBar: TDrawTrackBarEvent;
    FDrawTrackBarMask: TDrawTrackBarEvent;
    FDrawTrackBarGroove: TDrawTrackBarGrooveEvent;
    FDrawTrackBarGrooveMask: TDrawTrackBarGrooveEvent;
    FDrawSplitter: TDrawSplitterEvent;
    FExtraMenuItemWidth: TExtraMenuItemWidthEvent;
    FSubmenuIndicatorWidth: TSubmenuIndicatorWidthEvent;
    FMenuItemHeight: TMenuItemHeightEvent;
    FDrawFrame: TDrawFrameEvent;
    procedure BevelButtonRectHook(var x, y, w, h: Integer) cdecl;
    procedure ButtonRectHook(var x, y, w, h: Integer) cdecl;
    procedure ComboButtonRectHook(var x, y, w, h: Integer) cdecl;
    procedure ComboButtonFocusRectHook(var x, y, w, h: Integer) cdecl;
    procedure DrawArrowHook(p: QPainterH; _type: ArrowType; down: Boolean; x, y, w, h: Integer; g: QColorGroupH; enabled: Boolean; fill: QBrushH) cdecl;
    procedure DrawBevelButtonHook(p: QPainterH; x, y, w, h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH; var Stage: Integer) cdecl;
    procedure DrawButtonHook(p: QPainterH; x, y, w, h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH; var Stage: Integer) cdecl;
    procedure DrawButtonMaskHook(p: QPainterH; x, y, w, h: Integer) cdecl;
    procedure DrawCheckHook(p: QPainterH; x, y, w, h: Integer; g: QColorGroupH; State: Integer; Down, Enabled: Boolean; var Stage: Integer) cdecl;
    procedure DrawComboButtonHook(p: QPainterH; x, y, w, h: Integer; g: QColorGroupH; sunken, editable, enabled: Boolean; fill: QBrushH; var Stage: Integer); cdecl;
    procedure DrawComboButtonMaskHook(p: QPainterH; x, y, w, h: Integer) cdecl;
    procedure DrawFocusRectHook(p1: QPainterH; p2: PRect; p3: QColorGroupH; bg: QColorH; p5: Boolean; var Stage: Integer) cdecl;
    procedure DrawIndicatorMaskHook(p: QPainterH; x, y, w, h, state: Integer) cdecl;
    procedure DrawItemHook(p: QPainterH; x, y, w, h, flags: Integer; g: QColorGroupH; enabled: Boolean; pixmap: QPixmapH; text: PString; len: Integer; penColor: QColorH; var Stage: Integer) cdecl;
    procedure DrawMenuCheckHook(p: QPainterH; x, y, w, h: Integer; g: QColorGroupH; act, dis: Boolean) cdecl;
    procedure DrawPopupMenuItemHook(p: QPainterH; checkable: Boolean; maxpmw: Integer;
      tab: Integer; mi: QMenuItemH; itemID: Integer; act: Boolean; enabled: Boolean;
      x: Integer; y: Integer; w: Integer; h: Integer; var Stage: Integer) cdecl;
    procedure DrawPopupPanelHook(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorGroupH; lineWidth: Integer; fill: QBrushH; var Stage: Integer) cdecl;
    procedure DrawPushButtonHook(btn: QPushButtonH; p: QPainterH; var Stage: Integer) cdecl;
    procedure DrawPushButtonLabelHook(btn: QPushButtonH; p: QPainterH; var Stage: Integer) cdecl;
    procedure DrawRadioHook(p: QPainterH; x, y, w, h: Integer; g: QColorGroupH; _on, down, enabled: Boolean; var Stage: Integer) cdecl;
    procedure DrawRadioMaskHook(p: QPainterH; x, y, w, h: Integer; _on: Boolean) cdecl;
    procedure DrawScrollBarHook(p1: QPainterH; p2: QScrollBarH; sliderStart: Integer; controls, activeControl: Integer; var Stage: Integer) cdecl;
    procedure DrawSliderHook(p: QPainterH; x, y, w, h: Integer; g: QColorGroupH; p7: Orientation; tickAbove, tickBelow: Boolean; var Stage: Integer) cdecl;
    procedure DrawSliderMaskHook(p: QPainterH; x, y, w, h: Integer; p6: Orientation; tickAbove: Boolean; tickBelow: Boolean) cdecl;
    procedure DrawSliderGrooveHook(p: QPainterH; x, y, w, h: Integer; g: QColorGroupH; c: QCOORD; p8: Orientation; var Stage: Integer) cdecl;
    procedure DrawSliderGrooveMaskHook(p: QPainterH; x, y, w, h: Integer; c: QCOORD; p8: Orientation) cdecl;
    procedure DrawSplitterHook(p: QPainterH; x, y, w, h: Integer; g: QColorGroupH; p7: Orientation; var Stage: Integer) cdecl;
    procedure DrawTabHook(p1: QPainterH; p2: QTabBarH; index: Integer; selected: Boolean) cdecl;
    procedure DrawTabMaskHook(p1: QPainterH; p2: QTabBarH; index: Integer; selected: Boolean) cdecl;
    procedure DrawPanelHook(p: QPainterH; x, y, w, h: Integer; p6: QColorGroupH; sunken: Boolean; lineWidth: Integer; fill: QBrushH; var Stage: Integer) cdecl;
    procedure ExtraMenuItemWidthHook(checkable: Boolean; maxpmw: Integer; mi: QMenuItemH; fm: QFontMetricsH; var Retval: Integer) cdecl;
    procedure ItemRectHook(p: QPainterH; var x, y, w, h: Integer; flags: Integer; enabled: Boolean; pixmap: QPixmapH; text: PString; len: Integer) cdecl;
    procedure MenuItemHeightHook(checkable: Boolean; mi: QMenuItemH; fm: QFontMetricsH; var Height: Integer) cdecl;
    procedure ScrollBarMetricsHook(p1: QScrollBarH; var sliderMin, sliderMax, sliderLength, buttonDim: Integer) cdecl;
    procedure SubmenuIndicatorWidthHook(fm: QFontMetricsH; var Retval: Integer) cdecl;
    procedure TabBarMetricsHook(p1: QTabBarH; var hFrame, vFrame, overlap: Integer) cdecl;

    function GetButtonShift: TPoint;
    function GetCheckSize: TSize;
    function GetDefaultFrameWidth: Integer;
    function GetHandle: QClxStyleH;
    function GetMaxSliderDragDistance: Integer;
    function GetRadioSize: TSize;
    function GetSliderLength: Integer;
    procedure SetAfterDrawButton(const Value: TAfterDrawButtonEvent);
    procedure SetAfterDrawItem(const Value: TAfterDrawItemEvent);
    procedure SetAfterDrawMenuItem(const Value: TAfterDrawMenuItemEvent);
    procedure SetBeforeDrawButton(const Value: TBeforeDrawButtonEvent);
    procedure SetBeforeDrawItem(const Value: TBeforeDrawItemEvent);
    procedure SetBeforeDrawMenuItem(const Value: TBeforeDrawMenuItemEvent);
    procedure SetButtonRect(const Value: TButtonRectEvent);
    procedure SetButtonShift(const Value: TPoint);
    procedure SetCheckSize(const Value: TSize);
    procedure SetComboButtonRect(const Value: TButtonRectEvent);
    procedure SetComboButtonFocusRect(const Value: TButtonRectEvent);
    procedure SetDefaultFrameWidth(const Value: Integer);
    procedure SetDefaultStyle(const Value: TDefaultStyle); virtual;
    procedure SetDrawArrow(const Value: TDrawArrowEvent);
    procedure SetDrawButtonMask(const Value: TDrawMaskEvent);
    procedure SetDrawButtonFrame(const Value: TDrawButtonFrameEvent);
    procedure SetDrawButtonLabel(const Value: TBeforeDrawButtonEvent);
    procedure SetDrawCheck(const Value: TDrawCheckEvent);
    procedure SetDrawCheckMask(const Value: TDrawCheckMaskEvent);
    procedure SetDrawComboButton(const Value: TDrawComboButtonEvent);
    procedure SetDrawComboButtonMask(const Value: TDrawMaskEvent);
    procedure SetDrawFocusRect(const Value: TDrawFocusRectEvent);
    procedure SetDrawHint(const Value: TDrawHintEvent);
    procedure SetDrawHeaderSection(const Value: TDrawHeaderSectionEvent);
    procedure SetDrawMenuCheck(const Value: TDrawMenuCheckEvent);
    procedure SetDrawMenuFrame(const Value: TDrawMenuFrameEvent);
    procedure SetDrawRadio(const Value: TDrawRadioEvent);
    procedure SetDrawRadioMask(const Value: TDrawRadioMaskEvent);
    procedure SetDrawScrollBar(const Value: TDrawScrollBarEvent);
    procedure SetDrawTrackBar(const Value: TDrawTrackBarEvent);
    procedure SetDrawTrackBarMask(const Value: TDrawTrackBarEvent);
    procedure SetDrawTrackBarGroove(const Value: TDrawTrackBarGrooveEvent);
    procedure SetDrawTrackBarGrooveMask(const Value: TDrawTrackBarGrooveEvent);
    procedure SetDrawSplitter(const Value: TDrawSplitterEvent);
    procedure SetDrawTab(const Value: TDrawTabEvent);
    procedure SetDrawTabMask(const Value: TDrawTabEvent);
    procedure SetExtraMenuItemWidth(const Value: TExtraMenuItemWidthEvent);
    procedure SetGetItemRect(const Value: TGetItemRectEvent);
    procedure SetHeaderSectionRect(const Value: TButtonRectEvent);
    procedure SetMaxSliderDragDistance(const Value: Integer);
    procedure SetMenuItemHeight(const Value: TMenuItemHeightEvent);
    procedure SetRadioSize(const Value: TSize);
    procedure SetScrollBarMetrics(const Value: TScrollBarMetricsEvent);
    procedure SetSliderLength(const Value: Integer);
    procedure SetSubmenuIndicatorWidth(const Value: TSubmenuIndicatorWidthEvent);
    procedure SetTabMetrics(const Value: TTabMetricsEvent);
    procedure SetDrawFrame(const Value: TDrawFrameEvent);
  protected
    procedure Changed(Sender: TObject); dynamic;
    procedure CreateHandle; virtual;
    procedure DoAfterDrawButton(Source: TObject; Canvas: TCanvas); virtual;
    procedure DoAfterDrawItem(Canvas: TCanvas; const Rect: TRect; Flags: Integer; Enabled: Boolean;
      Bitmap: TBitmap; const Text: WideString; Length: Integer; Color: TColor); virtual;
    function DoBeforeDrawButton(Source: TObject; Canvas: TCanvas): Boolean; virtual;
    function DoBeforeDrawItem(Canvas: TCanvas; const Rect: TRect; Flags: Integer; Enabled: Boolean;
      Bitmap: TBitmap; const Text: WideString; Length: Integer; Color: TColor): Boolean; virtual;
    procedure DoButtonRect(var Rect: TRect); virtual;
    procedure DoComboButtonRect(var Rect: TRect); virtual;
    procedure DoComboButtonFocusRect(var Rect: TRect); virtual;
    procedure DoDrawArrow(Canvas: TCanvas; const Rect: TRect; Arrow: ArrowType; Down, Enabled: Boolean); virtual;
    function DoDrawButtonFrame(Canvas: TCanvas; const Rect: TRect; Down: Boolean): Boolean; virtual;
    function DoDrawButtonLabel(Source: TObject; Canvas: TCanvas): Boolean; virtual;
    procedure DoDrawButtonMask(Canvas: TCanvas; const Rect: TRect); virtual;
    function DoDrawCheck(Canvas: TCanvas; const Rect: TRect; Checked, Grayed, Down, Enabled: Boolean): Boolean; virtual;
    procedure DoDrawCheckMask(Canvas: TCanvas; const Rect: TRect; Checked, Grayed: Boolean); virtual;
    function DoDrawComboButton(Canvas: TCanvas; const Rect: TRect; Sunken, ReadOnly,
      Enabled: Boolean): Boolean; virtual;
    procedure DoDrawComboButtonMask(Canvas: TCanvas; const Rect: TRect); virtual;
    function DoDrawFocusRect(Canvas: TCanvas; const Rect: TRect; AtBorder: Boolean): Boolean; virtual;
    function DoDrawHeaderSection(Canvas: TCanvas; const Rect: TRect; Down: Boolean): Boolean; virtual;
    function DoDrawMenuFrame(Canvas: TCanvas; const R: TRect; LineWidth: Integer): Boolean; virtual;
    procedure DoDrawMenuItem(Source: TObject; Canvas: TCanvas; Highlighted, Enabled: Boolean;
      const Rect: TRect; Checkable: Boolean; CheckMaxWidth, LabelWidth: Integer; var Stage: Integer); virtual;
    procedure DoDrawMenuCheck(Canvas: TCanvas; const Rect: TRect; Highlighted, Enabled: Boolean); virtual;
    procedure DoDrawRadioMask(Canvas: TCanvas; const Rect: TRect; Checked: Boolean); virtual;
    function DoDrawRadio(Canvas: TCanvas; const Rect: TRect; Checked, Down, Enabled: Boolean): Boolean; virtual;
    function DoDrawScrollBar(ScrollBar: QScrollBarH; Canvas: TCanvas;
      const Rect: TRect; SliderStart, SliderLength, ButtonSize: Integer; Controls: TScrollBarControls;
      DownControl: TScrollBarControl): Boolean; virtual;
    function DoDrawTrackBar(Canvas: TCanvas; const Rect: TRect; Horizontal, TickAbove,
      TickBelow: Boolean): Boolean; virtual;
    function DoDrawTrackBarMask(Canvas: TCanvas; const Rect: TRect; Horizontal, TickAbove,
      TickBelow: Boolean): Boolean; virtual;
    function DoDrawTrackBarGroove(Canvas: TCanvas; const Rect: TRect; Horizontal: Boolean): Boolean; virtual;
    function DoDrawTrackBarGrooveMask(Canvas: TCanvas; const Rect: TRect; Horizontal: Boolean): Boolean; virtual;
    function DoDrawSplitter(Canvas: TCanvas; const Rect: TRect; Vertical: Boolean): Boolean; virtual;
    procedure DoDrawTab(Source: TObject; Canvas: TCanvas; Index, HorizontalPadding,
      VerticalPadding, Overlap: Integer; Selected: Boolean); virtual;
    procedure DoDrawTabMask(Source: TObject; Canvas: TCanvas; Index, HorizontalPadding,
      VerticalPadding, Overlap: Integer; Selected: Boolean); virtual;
    procedure DoExtraMenuItemWidth(Source: TObject; HasCheckmark: Boolean;
      ImageWidth: Integer; FontMetrics: QFontMetricsH; var ExtraWidth: Integer); virtual;
    procedure DoGetItemRect(Canvas: TCanvas; var Rect: TRect; Flags: Integer; Enabled: Boolean;
      Bitmap: TBitmap; const Text: WideString);
    function DoDrawFrame(Canvas: TCanvas; const Rect: TRect; Sunken: Boolean;
      LineWidth: Integer): Boolean; virtual;
    procedure DoHeaderSectionRect(var Rect: TRect); virtual;
    procedure DoMenuItemHeight(Source: TObject; Checkable: Boolean; FontMetrics: QFontMetricsH;
      var Height: Integer); virtual;
    procedure DoScrollBarMetrics(ScrollBar: QScrollBarH; var SliderMin, SliderMax,
      SliderLength, ButtonSize: Integer); virtual;
    procedure DoSubmenuIndicatorWidth(FontMetrics: QFontMetricsH; var Width: Integer); virtual;
    procedure DoTabMetrics(Source: TObject; var HorizontalPadding, VerticalPadding,
      Overlap: Integer); virtual;
    procedure StyleDestroyedHook; cdecl;
    procedure StyleDestroyed; virtual;
  public
    constructor Create; virtual;
    procedure HandleNeeded;
    procedure Refresh;
    function GetHooks: QClxStyleHooksH;
    property ButtonShift: TPoint read GetButtonShift write SetButtonShift;
    property CheckSize: TSize read GetCheckSize write SetCheckSize;
    property DefaultStyle: TDefaultStyle read FDefaultStyle write SetDefaultStyle;
    property Handle: QClxStyleH read GetHandle;
    property Hooks: QClxStyleHooksH read GetHooks;
    property MaxSliderDragDistance: Integer read GetMaxSliderDragDistance
      write SetMaxSliderDragDistance;
    property RadioSize: TSize read GetRadioSize write SetRadioSize;
    property SliderLength: Integer read GetSliderLength write SetSliderLength;
    //Events
    property AfterDrawButton: TAfterDrawButtonEvent read FAfterDrawButton
      write SetAfterDrawButton;
    property AfterDrawItem: TAfterDrawItemEvent read FAfterDrawItem
      write SetAfterDrawItem;
    property AfterDrawMenuItem: TAfterDrawMenuItemEvent read FAfterDrawMenuItem
      write SetAfterDrawMenuItem;
    property BeforeDrawButton: TBeforeDrawButtonEvent read FBeforeDrawButton
      write SetBeforeDrawButton;
    property BeforeDrawItem: TBeforeDrawItemEvent read FBeforeDrawItem
      write SetBeforeDrawItem;
    property BeforeDrawMenuItem: TBeforeDrawMenuItemEvent read FBeforeDrawMenuItem
      write SetBeforeDrawMenuItem;
    property ButtonRect: TButtonRectEvent read FButtonRect write SetButtonRect;
    property ComboButtonRect: TButtonRectEvent read FComboButtonRect
      write SetComboButtonRect;
    property ComboButtonFocusRect: TButtonRectEvent read FComboButtonFocusRect
      write SetComboButtonFocusRect;
    property DefaultFrameWidth: Integer read GetDefaultFrameWidth write
      SetDefaultFrameWidth;
    property DrawHint: TDrawHintEvent read FDrawHint write SetDrawHint;
    property DrawArrow: TDrawArrowEvent read FDrawArrow write SetDrawArrow;
    property DrawButtonLabel: TBeforeDrawButtonEvent read FDrawButtonLabel
      write SetDrawButtonLabel;
    property DrawButtonFrame: TDrawButtonFrameEvent read FDrawButtonFrame
      write SetDrawButtonFrame;
    property DrawButtonMask: TDrawMaskEvent read FDrawButtonMask
      write SetDrawButtonMask;
    property DrawCheck: TDrawCheckEvent read FDrawCheck write SetDrawCheck;
    property DrawCheckMask: TDrawCheckMaskEvent read FDrawCheckMask write SetDrawCheckMask;
    property DrawComboButton: TDrawComboButtonEvent read FDrawComboButton
      write SetDrawComboButton;
    property DrawComboButtonMask: TDrawMaskEvent read FDrawComboButtonMask
      write SetDrawComboButtonMask;
    property DrawFocusRect: TDrawFocusRectEvent read FDrawFocusRect write SetDrawFocusRect;
    property DrawHeaderSection: TDrawHeaderSectionEvent read FDrawHeaderSection
      write SetDrawHeaderSection;
    property DrawMenuCheck: TDrawMenuCheckEvent read FDrawMenuCheck write SetDrawMenuCheck;
    property DrawMenuFrame: TDrawMenuFrameEvent read FDrawMenuFrame write SetDrawMenuFrame;
    property DrawRadio: TDrawRadioEvent read FDrawRadio write SetDrawRadio;
    property DrawRadioMask: TDrawRadioMaskEvent read FDrawRadioMask write SetDrawRadioMask;
    property DrawScrollBar: TDrawScrollBarEvent read FDrawScrollBar
      write SetDrawScrollBar;
    property DrawTrackBar: TDrawTrackBarEvent read FDrawTrackBar write SetDrawTrackBar;
    property DrawTrackBarMask: TDrawTrackBarEvent read FDrawTrackBarMask write SetDrawTrackBarMask;
    property DrawTrackBarGroove: TDrawTrackBarGrooveEvent read FDrawTrackBarGroove
      write SetDrawTrackBarGroove;
    property DrawTrackBarGrooveMask: TDrawTrackBarGrooveEvent read FDrawTrackBarGrooveMask
      write SetDrawTrackBarGrooveMask;
    property DrawSplitter: TDrawSplitterEvent read FDrawSplitter write SetDrawSplitter;
    property DrawTab: TDrawTabEvent read FDrawTab write SetDrawTab;
    property DrawTabMask: TDrawTabEvent read FDrawTabMask write SetDrawTabMask;
    property ExtraMenuItemWidth: TExtraMenuItemWidthEvent
      read FExtraMenuItemWidth write SetExtraMenuItemWidth;
    property GetItemRect: TGetItemRectEvent read FGetItemRect write SetGetItemRect;
    property DrawFrame: TDrawFrameEvent read FDrawFrame write SetDrawFrame;
    property HeaderSectionRect: TButtonRectEvent read FHeaderSectionRect
      write SetHeaderSectionRect;
    property MenuItemHeight: TMenuItemHeightEvent read FMenuItemHeight
      write SetMenuItemHeight;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property ScrollBarMetrics: TScrollBarMetricsEvent read FScrollBarMetrics
      write SetScrollBarMetrics;
    property SubmenuIndicatorWidth: TSubmenuIndicatorWidthEvent read FSubmenuIndicatorWidth
      write SetSubmenuIndicatorWidth;
    property TabMetrics: TTabMetricsEvent read FTabMetrics write SetTabMetrics;
  end;

  TApplicationStyle = class(TStyle)
  private
    FRecreating: Boolean;
    FOnPolish: TPolishEvent;
    procedure PolishHook(p1: QApplicationH) cdecl;
    procedure SetOnPolish(const Value: TPolishEvent);
  protected
    procedure DoPolish(Source: TObject); virtual;
    procedure CreateHandle; override;
    procedure SetDefaultStyle(const Value: TDefaultStyle); override;
    procedure StyleDestroyed; override;
  public
    destructor Destroy; override;
    property OnPolish: TPolishEvent read FOnPolish write SetOnPolish;
  end;

  TWidgetStyle = class(TStyle)
  private
    FOnPolish: TPolishEvent;
    procedure PolishHook(p1: QWidgetH) cdecl;
    procedure SetOnPolish(const Value: TPolishEvent);
  protected
    procedure DoPolish(Source: TObject); virtual;
    procedure SetDefaultStyle(const Value: TDefaultStyle); override;
  public
    property OnPolish: TPolishEvent read FOnPolish write SetOnPolish;
  end;

const
  cStyles: array [TDefaultStyle] of string = ('Windows 95',  { do not localize }
                                              'Motif',       { do not localize }
                                              'MotifPlus',   { do not localize }
                                              'CDE',         { do not localize }
                                              'Qt SGI',      { do not localize }
                                              'Platinum',    { do not localize }
                                              '');           { do not localize }
                
implementation

{$IFDEF LINUX}
uses
  SysUtils, QControls, QForms, IniFiles, Libc;
{$ENDIF}
{$IFDEF MSWINDOWS}
uses
  SysUtils, QControls, QForms, IniFiles;
{$ENDIF}

type
  QClxStyle_polish_Event = procedure (p1: QWidgetH) of object cdecl;
  QClxStyle_unPolish_Event = procedure (p1: QWidgetH) of object cdecl;
  QClxStyle_polish2_Event = procedure (p1: QApplicationH) of object cdecl;
  QClxStyle_unPolish2_Event = procedure (p1: QApplicationH) of object cdecl;
  QClxStyle_polish3_Event = procedure (p1: QPaletteH) of object cdecl;
  QClxStyle_itemRect_Event = procedure (p: QPainterH; var x: Integer; var y: Integer; var w: Integer; var h: Integer; flags: Integer; enabled: Boolean; pixmap: QPixmapH; text: PString; len: Integer) of object cdecl;
  QClxStyle_drawItem_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; g: QColorGroupH; enabled: Boolean; pixmap: QPixmapH; text: PString; len: Integer; penColor: QColorH; var Stage: Integer) of object cdecl;
  QClxStyle_drawSeparator_Event = procedure (p: QPainterH; x1: Integer; y1: Integer; x2: Integer; y2: Integer; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer; var Stage: Integer) of object cdecl;
  QClxStyle_drawRect_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorH; lineWidth: Integer; fill: QBrushH) of object cdecl;
  QClxStyle_drawRectStrong_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer; fill: QBrushH) of object cdecl;
  QClxStyle_drawButton_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH; var Stage: Integer) of object cdecl;
  QClxStyle_buttonRect_Event = procedure(var x: Integer; var y: Integer; var w: Integer; var h: Integer) of object cdecl;
  QClxStyle_drawButtonMask_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer) of object cdecl;
  QClxStyle_drawBevelButton_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH; var Stage: Integer) of object cdecl;
  QClxStyle_bevelButtonRect_Event = procedure (var x: Integer; var y: Integer; var w: Integer; var h: Integer) of object cdecl;
  QClxStyle_drawToolButton_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH) of object cdecl;
  QClxStyle_drawToolButton2_Event = procedure (btn: QToolButtonH; p: QPainterH) of object cdecl;
  QClxStyle_toolButtonRect_Event = function (x: Integer; y: Integer; w: Integer; h: Integer): PRect of object cdecl;
  QClxStyle_drawPanel_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorGroupH; sunken: Boolean; lineWidth: Integer; fill: QBrushH; var Stage: Integer) of object cdecl;
  QClxStyle_drawPopupPanel_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorGroupH; lineWidth: Integer; fill: QBrushH; var Stage: Integer) of object cdecl;
  QClxStyle_drawArrow_Event = procedure (p: QPainterH; _type: ArrowType; down: Boolean; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; enabled: Boolean; fill: QBrushH) of object cdecl;
  QClxStyle_exclusiveIndicatorSize_Event = function(): QSizeH of object cdecl;
  QClxStyle_drawExclusiveIndicator_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; _on, down, enabled: Boolean; var Stage: Integer) of object cdecl;
  QClxStyle_drawExclusiveIndicatorMask_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; on: Boolean) of object cdecl;
  QClxStyle_drawIndicatorMask_Event = procedure (p: QPainterH; x, y, w, h, state: Integer) of object cdecl;
  QClxStyle_indicatorSize_Event = function (): QSizeH of object cdecl;
  QClxStyle_drawIndicator_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; state: Integer; down: Boolean; enabled: Boolean; var Stage: Integer) of object cdecl;
  QClxStyle_drawFocusRect_Event = procedure (p1: QPainterH; p2: PRect; p3: QColorGroupH; bg: QColorH; p5: Boolean; var Stage: Integer) of object cdecl;
  QClxStyle_drawComboButton_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; editable: Boolean; enabled: Boolean; fill: QBrushH; var Stage: Integer) of object cdecl;
  QClxStyle_comboButtonRect_Event = procedure(var x: Integer; var y: Integer; var w: Integer; var h: Integer) of object cdecl;
  QClxStyle_comboButtonFocusRect_Event = procedure(var x: Integer; var y: Integer; var w: Integer; var h: Integer) of object cdecl;
  QClxStyle_drawComboButtonMask_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer) of object cdecl;
  QClxStyle_drawPushButton_Event = procedure (btn: QPushButtonH; p: QPainterH; var Stage: Integer) of object cdecl;
  QClxStyle_drawPushButtonLabel_Event = procedure (btn: QPushButtonH; p: QPainterH; var Stage: Integer) of object cdecl;
  QClxStyle_pushButtonContentsRect_Event = function (btn: QPushButtonH): PRect of object cdecl;
  QClxStyle_menuButtonIndicatorWidth_Event = function (h: Integer): Integer of object cdecl;
  QClxStyle_getButtonShift_Event = procedure (x: PInteger; y: PInteger) of object cdecl;
  QClxStyle_defaultFrameWidth_Event = function (): Integer of object cdecl;
  QClxStyle_tabbarMetrics_Event = procedure (p1: QTabBarH; var p2, p3, p4: Integer) of object cdecl;
  QClxStyle_drawTab_Event = procedure (p1: QPainterH; p2: QTabBarH; index: Integer; selected: Boolean) of object cdecl;
  QClxStyle_drawTabMask_Event = procedure (p1: QPainterH; p2: QTabBarH; index: Integer; selected: Boolean) of object cdecl;
  QClxStyle_scrollBarMetrics_Event = procedure (p1: QScrollBarH; var sliderMin, sliderMax, sliderLength, buttonDim: Integer) of object cdecl;
  QClxStyle_drawScrollBarControls_Event = procedure (p1: QPainterH; p2: QScrollBarH; sliderStart: Integer; controls, activeControl: Integer; var Stage: Integer) of object cdecl;
  QClxStyle_sliderLength_Event = function (): Integer of object cdecl;
  QClxStyle_drawSlider_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; p7: Orientation; tickAbove: Boolean; tickBelow: Boolean; var Stage: Integer) of object cdecl;
  QClxStyle_drawSliderMask_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: Orientation; tickAbove: Boolean; tickBelow: Boolean) of object cdecl;
  QClxStyle_drawSliderGroove_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; c: QCOORD; p8: Orientation; var Stage: Integer) of object cdecl;
  QClxStyle_drawSliderGrooveMask_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; c: QCOORD; p7: Orientation) of object cdecl;
  QClxStyle_maximumSliderDragDistance_Event = function (): Integer of object cdecl;
  QClxStyle_splitterWidth_Event = function (): Integer of object cdecl;
  QClxStyle_drawSplitter_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; p7: Orientation; var Stage: Integer) of object cdecl;
  QClxStyle_drawCheckMark_Event = procedure (p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; act: Boolean; dis: Boolean) of object cdecl;
  QClxStyle_polishPopupMenu_Event = procedure (p1: QPopupMenuH) of object cdecl;
  QClxStyle_extraPopupMenuItemWidth_Event = procedure (checkable: Boolean; maxpmw: Integer; mi: QMenuItemH; fm: QFontMetricsH; var Retval: Integer) of object cdecl;
  QClxStyle_popupSubmenuIndicatorWidth_Event = procedure(fm: QFontMetricsH; var Retval: Integer) of object cdecl;
  QClxStyle_popupMenuItemHeight_Event = procedure(checkable: Boolean; mi: QMenuItemH; fm: QFontMetricsH; var Height: Integer) of object cdecl;
  QClxStyle_drawPopupMenuItem_Event = procedure (p: QPainterH; checkable: Boolean; maxpmw: Integer; tab: Integer; mi: QMenuItemH; itemID: Integer; act: Boolean; enabled: Boolean; x: Integer; y: Integer; w: Integer; h: Integer; var Stage: Integer) of object cdecl;
  QClxStyle_scrollBarExtent_Event = function (): QSizeH of object cdecl;
  QClxStyle_buttonDefaultIndicatorWidth_Event = function (): Integer of object cdecl;
  QClxStyle_toolBarHandleExtend_Event = function (): Integer of object cdecl;
  QClxStyle_drawToolBarHandle_Event = procedure (p: QPainterH; r: PRect; orientation: Orientation; highlight: Boolean; cg: QColorGroupH; drawBorder: Boolean) of object cdecl;
  QClxStyle_StyleDestroyed_Event = procedure of object cdecl;

{$IFDEF LINUX}
type
  TKAppResetStyle = procedure cdecl;
var
  AppResetStyle: TKAppResetStyle = nil;
{$ENDIF}

{ TStyle }

function TStyle.GetHandle: QClxStyleH;
begin
  HandleNeeded;
  Result := FHandle;
end;

function TStyle.GetHooks: QClxStyleHooksH;
begin
  HandleNeeded;
  Result := FHooks;
end;

procedure TStyle.HandleNeeded;
begin
  if FHandle = nil then
    CreateHandle;
end;

procedure TStyle.CreateHandle;
var
  Temp: WideString;
  Method: TMethod;
begin
  if FDefaultStyle = dsSystemDefault then
    FHandle := Application.Style.Handle
  else
  begin
    Temp := cStyles[FDefaultStyle];
    FHooks := QClxStyleHooks_create;
    FHandle := QClxStyle_create(@Temp, FHooks);
    QClxStyle_StyleDestroyed_Event(Method) := StyleDestroyedHook;
    QClxStyleHooks_hook_StyleDestroyed(FHooks, Method);
  end;
end;

procedure TStyle.StyleDestroyedHook;
begin
  try
    StyleDestroyed;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.StyleDestroyed;
begin
  if Assigned(FHooks) then
    QClxStyleHooks_hook_StyleDestroyed(FHooks, NullHook);
  FHandle := nil;
  FHooks := nil;
end;

procedure TStyle.DrawFocusRectHook(p1: QPainterH; p2: PRect;
  p3: QColorGroupH; bg: QColorH; p5: Boolean; var Stage: Integer);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p1;
      Canvas.Start(False);
      if DoDrawFocusRect(Canvas, p2^, p5) then
        Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

function TStyle.DoDrawFocusRect(Canvas: TCanvas; const Rect: TRect;
  AtBorder: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FDrawFocusRect) then
    FDrawFocusRect(Self, Canvas, Rect, AtBorder, Result);
end;

procedure TStyle.Refresh;
begin
  QClxStyle_refresh(Handle);
  QPixmapCache_clear;
end;

procedure TStyle.SetDrawFocusRect(const Value: TDrawFocusRectEvent);
var
  Method: TMethod;
begin
  FDrawFocusRect := Value;
  if Assigned(FDrawFocusRect) then
    QClxStyle_drawFocusRect_Event(Method) := DrawFocusRectHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawFocusRect(Hooks, Method);
  Refresh;
end;

procedure TStyle.SetDrawHint(const Value: TDrawHintEvent);
begin
  FDrawHint := Value;
  Refresh;
end;

procedure TStyle.DoAfterDrawButton(Source: TObject; Canvas: TCanvas);
begin
  if Assigned(FAfterDrawButton) then
    FAfterDrawButton(Self, Source, Canvas);
end;

function TStyle.DoBeforeDrawButton(Source: TObject; Canvas: TCanvas): Boolean;
begin
  Result := True;
  if Assigned(FBeforeDrawButton) then
    FBeforeDrawButton(Self, Source, Canvas, Result);
end;

procedure TStyle.DoDrawMenuItem(Source: TObject; Canvas: TCanvas;
  Highlighted, Enabled: Boolean; const Rect: TRect; Checkable: Boolean;
  CheckMaxWidth, LabelWidth: Integer; var Stage: Integer);
var
  DefaultDraw: Boolean;
begin
  DefaultDraw := True;
  case Stage of
    DrawStage_Pre:
      begin
        if Assigned(FBeforeDrawMenuItem) then FBeforeDrawMenuItem(Self, Source, Canvas,
          Highlighted, Enabled, Rect, Checkable, CheckMaxWidth, LabelWidth, DefaultDraw);
        if DefaultDraw then Stage := DrawStage_DefaultDraw;
      end;
    DrawStage_Post:
      if Assigned(FAfterDrawMenuItem) then FAfterDrawMenuItem(Self, Source, Canvas,
        Highlighted, Enabled, Rect, Checkable, CheckMaxWidth, LabelWidth);
  end;
end;

function TStyle.DoDrawButtonLabel(Source: TObject; Canvas: TCanvas): Boolean;
begin
  Result := True;
  if Assigned(FDrawButtonLabel) then
    FDrawButtonLabel(Self, Source, Canvas, Result);
end;

procedure TStyle.DrawPopupMenuItemHook(p: QPainterH;
  checkable: Boolean; maxpmw, tab: Integer; mi: QMenuItemH; itemID: Integer;
  act, enabled: Boolean; x, y, w, h: Integer; var Stage: Integer);
var
  Canvas: TCanvas;
  R: TRect;
  Source: TObject;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      R := Rect(x, y, x+w, y+h);
      Canvas.Start(False);
      Source := FindObject(QObjectH(mi));
      if Source <> nil then
        DoDrawMenuItem(Source, Canvas, act, enabled, R, checkable, maxpmw, tab, Stage);
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.DrawPushButtonHook(btn: QPushButtonH; p: QPainterH; var Stage: Integer);
var
  Canvas: TCanvas;
  Source: TObject;
begin
  try
    Source := FindControl(btn);
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      case Stage of
        DrawStage_Pre:
          if DoBeforeDrawButton(Source, Canvas) then
            Stage := DrawStage_DefaultDraw;
        DrawStage_Post:
          DoAfterDrawButton(Source, Canvas);
      end;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.DrawPushButtonLabelHook(btn: QPushButtonH;
  p: QPainterH; var Stage: Integer);
var
  Canvas: TCanvas;
  Source: TObject;
begin
  try
    Source := FindControl(btn);
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
       if DoDrawButtonLabel(Source, Canvas) then
         Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetAfterDrawButton(const Value: TAfterDrawButtonEvent);
var
  Method: TMethod;
begin
  FAfterDrawButton := Value;
  if Assigned(FBeforeDrawButton) then
    Exit;
  if Assigned(FAfterDrawButton) then
    QClxStyle_drawPushButton_Event(Method) := DrawPushButtonHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawPushButton(Hooks, Method);
  Refresh;
end;

procedure TStyle.SetBeforeDrawButton(const Value: TBeforeDrawButtonEvent);
var
  Method: TMethod;
begin
  FBeforeDrawButton := Value;
  if Assigned(FAfterDrawButton) then
    Exit;
  if Assigned(FBeforeDrawButton) then
    QClxStyle_drawPushButton_Event(Method) := DrawPushButtonHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawPushButton(Hooks, Method);
  Refresh;
end;

procedure TStyle.SetAfterDrawMenuItem(const Value: TAfterDrawMenuItemEvent);
var
  Method: TMethod;
begin
  FAfterDrawMenuItem := Value;
  if Assigned(FBeforeDrawMenuItem) then
    Exit;
  if Assigned(FAfterDrawMenuItem) then
    QClxStyle_drawPopupMenuItem_Event(Method) := DrawPopupMenuItemHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawPopupMenuItem(Hooks, Method);
  Refresh;
end;

procedure TStyle.SetBeforeDrawMenuItem(const Value: TBeforeDrawMenuItemEvent);
var
  Method: TMethod;
begin
  FBeforeDrawMenuItem := Value;
  if Assigned(FAfterDrawMenuItem) then
    Exit;
  if Assigned(FBeforeDrawMenuItem) then
    QClxStyle_drawPopupMenuItem_Event(Method) := DrawPopupMenuItemHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawPopupMenuItem(Hooks, Method);
  Refresh;
end;

procedure TStyle.SetDrawButtonLabel(const Value: TBeforeDrawButtonEvent);
var
  Method: TMethod;
begin
  FDrawButtonLabel := Value;
  if Assigned(FDrawButtonLabel) then
    QClxStyle_drawPushButtonLabel_Event(Method) := DrawPushButtonLabelHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawPushButtonLabel(Hooks, Method);
  Refresh;
end;

procedure TStyle.DrawPopupPanelHook(p: QPainterH; x, y, w,
  h: Integer; p6: QColorGroupH; lineWidth: Integer; fill: QBrushH; var Stage: Integer);
var
  Canvas: TCanvas;
  R: TRect;
begin
  try
    Canvas := TCanvas.Create;
    try
      R := Rect(x, y, x+w, y+h);
      Canvas.Handle := p;
      Canvas.Start(False);
       if DoDrawMenuFrame(Canvas, R, LineWidth) then
         Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

function TStyle.DoDrawMenuFrame(Canvas: TCanvas; const R: TRect;
  LineWidth: Integer): Boolean;
begin
  Result := True;
  if Assigned(FDrawMenuFrame) then
    FDrawMenuFrame(Self, Canvas, R, LineWidth, Result);
end;

procedure TStyle.SetDrawMenuFrame(const Value: TDrawMenuFrameEvent);
var
  Method: TMethod;
begin
  FDrawMenuFrame := Value;
  if Assigned(FDrawMenuFrame) then
    QClxStyle_drawPopupPanel_Event(Method) := DrawPopupPanelHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawPopupPanel(Hooks, Method);
  Refresh;
end;

procedure TStyle.DrawButtonHook(p: QPainterH; x, y, w, h: Integer;
  g: QColorGroupH; sunken: Boolean; fill: QBrushH;
  var Stage: Integer);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      if DoDrawButtonFrame(Canvas, Rect(x, y, x+w, y+h), sunken) then
        Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

function TStyle.DoDrawButtonFrame(Canvas: TCanvas; const Rect: TRect;
  Down: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FDrawButtonFrame) then
    FDrawButtonFrame(Self, Canvas, Rect, Down, Result);
end;

procedure TStyle.SetDrawButtonFrame(const Value: TDrawButtonFrameEvent);
var
  Method: TMethod;
begin
  FDrawButtonFrame := Value;
  if Assigned(FDrawButtonFrame) then
    QClxStyle_drawButton_Event(Method) := DrawButtonHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawButton(Hooks, Method);
  Refresh;
end;

constructor TStyle.Create;
begin
  inherited Create;
  FDefaultStyle := dsSystemDefault;
end;

procedure TStyle.DoGetItemRect(Canvas: TCanvas; var Rect: TRect; Flags: Integer;
  Enabled: Boolean; Bitmap: TBitmap; const Text: WideString);
begin
  if Assigned(FGetItemRect) then
    FGetItemRect(Self, Canvas, Rect, Flags, Enabled, Bitmap, Text);
end;

procedure TStyle.ItemRectHook(p: QPainterH; var x, y, w, h: Integer; flags: Integer;
  enabled: Boolean; pixmap: QPixmapH; text: PString; len: Integer);
var
  Canvas: TCanvas;
  R: TRect;
  Bitmap: TBitmap;
begin
  try
    Canvas := TCanvas.Create;
    try
      Bitmap := TBitmap.Create;
      try
        R := Rect(x, y, x+w, y+h);
        Canvas.Handle := p;
        Bitmap.Handle := pixmap;
        Canvas.Start(False);
        DoGetItemRect(Canvas, R, flags, enabled, Bitmap, text^);
        Canvas.Stop;
        x := R.Top;
        y := R.Left;
        w := R.Right - R.Left;
        h := R.Bottom - R.Top;
      finally
        Bitmap.Free;
      end;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetGetItemRect(const Value: TGetItemRectEvent);
var
  Method: TMethod;
begin
  FGetItemRect := Value;
  if Assigned(FGetItemRect) then
    QClxStyle_itemRect_Event(Method) := ItemRectHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_itemRect(Hooks, Method);
end;

function TStyle.DoDrawHeaderSection(Canvas: TCanvas; const Rect: TRect;
  Down: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FDrawHeaderSection) then
    FDrawHeaderSection(Self, Canvas, Rect, Down, Result);
end;

procedure TStyle.DrawBevelButtonHook(p: QPainterH; x, y, w, h: Integer;
  g: QColorGroupH; sunken: Boolean; fill: QBrushH; var Stage: Integer);
var
  Canvas: TCanvas;
  R: TRect;
begin
  try
    Canvas := TCanvas.Create;
    try
      R := Rect(x, y, x+w, y+h);
      Canvas.Handle := p;
      Canvas.Start(False);
       if DoDrawHeaderSection(Canvas, R, sunken) then
         Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawHeaderSection(const Value: TDrawHeaderSectionEvent);
var
  Method: TMethod;
begin
  FDrawHeaderSection := Value;
  if Assigned(FDrawHeaderSection) then
    QClxStyle_drawBevelButton_Event(Method) := DrawBevelButtonHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawBevelButton(Hooks, Method);
  Refresh;
end;

procedure TStyle.BevelButtonRectHook(var x, y, w, h: Integer);
var
  R: TRect;
begin
  try
    R := Rect(x, y, x+w, y+h);
    DoHeaderSectionRect(R);
    x := R.Left;
    y := R.Top;
    w := R.Right - R.Left;
    h := R.Bottom - R.Top;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.DoHeaderSectionRect(var Rect: TRect);
begin
  if Assigned(FHeaderSectionRect) then
    FHeaderSectionRect(Self, Rect);
end;

procedure TStyle.SetHeaderSectionRect(const Value: TButtonRectEvent);
var
  Method: TMethod;
begin
  FHeaderSectionRect := Value;
  if Assigned(FHeaderSectionRect) then
    QClxStyle_bevelButtonRect_Event(Method) := BevelButtonRectHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_bevelButtonRect(Hooks, Method);
  Refresh;
end;

procedure TStyle.ButtonRectHook(var x, y, w, h: Integer);
var
  R: TRect;
begin
  try
    R := Rect(x, y, x+w, y+h);
    DoButtonRect(R);
    x := R.Left;
    y := R.Top;
    w := R.Right - R.Left;
    h := R.Bottom - R.Top;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.DoButtonRect(var Rect: TRect);
begin
  if Assigned(FButtonRect) then
    FButtonRect(Self, Rect);
end;

procedure TStyle.SetButtonRect(const Value: TButtonRectEvent);
var
  Method: TMethod;
begin
  FButtonRect := Value;
  if Assigned(FButtonRect) then
    QClxStyle_buttonRect_Event(Method) := ButtonRectHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_buttonRect(Hooks, Method);
  Refresh;
end;

procedure TStyle.DoDrawArrow(Canvas: TCanvas; const Rect: TRect;
  Arrow: ArrowType; Down, Enabled: Boolean);
begin
  if Assigned(FDrawArrow) then
    FDrawArrow(Self, Canvas, Rect, Arrow, Down, Enabled);
end;

procedure TStyle.DrawArrowHook(p: QPainterH; _type: ArrowType;
  down: Boolean; x, y, w, h: Integer; g: QColorGroupH; enabled: Boolean;
  fill: QBrushH);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      DoDrawArrow(Canvas, Rect(x, y, x+w, y+h), _type, down, enabled);
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawArrow(const Value: TDrawArrowEvent);
var
  Method: TMethod;
begin
  FDrawArrow := Value;
  if Assigned(FDrawArrow) then
    QClxStyle_drawArrow_Event(Method) := DrawArrowHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawArrow(Hooks, Method);
  Refresh;
end;

procedure TStyle.DrawRadioMaskHook(p: QPainterH; x, y, w, h: Integer; _on: Boolean);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      DoDrawRadioMask(Canvas, Rect(x, y, x+w, y+h), _on);
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawRadioMask(const Value: TDrawRadioMaskEvent);
var
  Method: TMethod;
begin
  FDrawRadioMask := Value;
  if Assigned(FDrawRadioMask) then
    QClxStyle_drawExclusiveIndicatorMask_event(Method) := DrawRadioMaskHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawExclusiveIndicatorMask(Hooks, Method);
  Refresh;
end;

procedure TStyle.DoDrawRadioMask(Canvas: TCanvas; const Rect: TRect; Checked: Boolean);
begin
  if Assigned(FDrawRadioMask) then
    FDrawRadioMask(Self, Canvas, Rect, Checked);
end;

procedure TStyle.DoDrawCheckMask(Canvas: TCanvas; const Rect: TRect; Checked, Grayed: Boolean);
begin
  if Assigned(FDrawCheckMask) then
    FDrawCheckMask(Self, Canvas, Rect, Checked, Grayed);
end;

procedure TStyle.DrawIndicatorMaskHook(p: QPainterH; x, y, w, h, state: Integer);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      DoDrawCheckMask(Canvas, Rect(x, y, x+w, y+h), Boolean(state and $02),
        Boolean(state and $01));
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawCheckMask(const Value: TDrawCheckMaskEvent);
var
  Method: TMethod;
begin
  FDrawCheckMask := Value;
  if Assigned(FDrawCheckMask) then
    QClxStyle_drawIndicatorMask_event(Method) := DrawIndicatorMaskHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawIndicatorMask(Hooks, Method);
  Refresh;
end;

procedure TStyle.ComboButtonRectHook(var x, y, w, h: Integer);
var
  R: TRect;
begin
  try
    R := Rect(x, y, x+w, y+h);
    DoComboButtonRect(R);
    x := R.Left;
    y := R.Top;
    w := R.Right - R.Left;
    h := R.Bottom - R.Top;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.DoComboButtonRect(var Rect: TRect);
begin
  if Assigned(FComboButtonRect) then
    FComboButtonRect(Self, Rect);
end;

procedure TStyle.SetComboButtonRect(const Value: TButtonRectEvent);
var
  Method: TMethod;
begin
  FComboButtonRect := Value;
  if Assigned(FComboButtonRect) then
    QClxStyle_comboButtonRect_event(Method) := ComboButtonRectHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_comboButtonRect(Hooks, Method);
  Refresh;
end;

procedure TStyle.ComboButtonFocusRectHook(var x, y, w, h: Integer);
var
  R: TRect;
begin
  try
    R := Rect(x, y, x+w, y+h);
    DoComboButtonFocusRect(R);
    x := R.Left;
    y := R.Top;
    w := R.Right - R.Left;
    h := R.Bottom - R.Top;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.DoComboButtonFocusRect(var Rect: TRect);
begin
  if Assigned(FComboButtonFocusRect) then
    FComboButtonFocusRect(Self, Rect);
end;

procedure TStyle.SetComboButtonFocusRect(const Value: TButtonRectEvent);
var
  Method: TMethod;
begin
  FComboButtonFocusRect := Value;
  if Assigned(FComboButtonFocusRect) then
    QClxStyle_comboButtonFocusRect_event(Method) := ComboButtonFocusRectHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_comboButtonFocusRect(Hooks, Method);
  Refresh;
end;

procedure TStyle.DoDrawComboButtonMask(Canvas: TCanvas; const Rect: TRect);
begin
  if Assigned(FDrawComboButtonMask) then
    FDrawComboButtonMask(Self, Canvas, Rect);
end;

procedure TStyle.DrawComboButtonMaskHook(p: QPainterH; x, y, w,
  h: Integer);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      DoDrawButtonMask(Canvas, Rect(x, y, x+w, y+h));
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawComboButtonMask(const Value: TDrawMaskEvent);
var
  Method: TMethod;
begin
  FDrawComboButtonMask := Value;
  if Assigned(FDrawComboButtonMask) then
    QClxStyle_DrawComboButtonMask_Event(Method) := DrawComboButtonMaskHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_DrawComboButtonMask(Hooks, Method);
  Refresh;
end;

function TStyle.GetDefaultFrameWidth: Integer;
begin
  Result := QClxStyle_defaultFrameWidth(Handle);
end;

procedure TStyle.SetDefaultFrameWidth(const Value: Integer);
begin
  QClxStyle_setDefaultFrameWidth(Handle, Value);
  Refresh;
end;

procedure TStyle.DoTabMetrics(Source: TObject; var HorizontalPadding, VerticalPadding,
  Overlap: Integer);
begin
  if Assigned(FTabMetrics) then
    FTabMetrics(Self, Source, HorizontalPadding, VerticalPadding, Overlap);
end;

procedure TStyle.SetTabMetrics(const Value: TTabMetricsEvent);
var
  Method: TMethod;
begin
  FTabMetrics := Value;
  if Assigned(FTabMetrics) then
    QClxStyle_tabBarMetrics_Event(Method) := TabBarMetricsHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_tabBarMetrics(Hooks, Method);
  Refresh;
end;

procedure TStyle.TabBarMetricsHook(p1: QTabBarH; var hFrame, vFrame, overlap: Integer);
var
  Source: TObject;
begin
  try
    Source := FindControl(p1);
    DoTabMetrics(Source, hFrame, vFrame, overlap);
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.DoDrawTab(Source: TObject; Canvas: TCanvas; Index, HorizontalPadding,
  VerticalPadding, Overlap: Integer; Selected: Boolean);
begin
  if Assigned(FDrawTab) then
    FDrawTab(Self, Source, Canvas, Index, HorizontalPadding, VerticalPadding,
    Overlap, Selected);
end;

procedure TStyle.DrawTabHook(p1: QPainterH; p2: QTabBarH; index: Integer;
  selected: Boolean);
var
  Canvas: TCanvas;
  Source: TObject;
  HorizontalPadding,
  VerticalPadding,
  Overlap: Integer;
begin
  try
    Canvas := TCanvas.Create;
    try
      QClxStyle_tabBarMetrics(Handle, P2, @HorizontalPadding, @VerticalPadding,
        @Overlap);
      Source := FindControl(p2);
      Canvas.Handle := p1;
      Canvas.Start(False);
      DoDrawTab(Source, Canvas, index, HorizontalPadding, VerticalPadding,
        Overlap, selected);
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawTab(const Value: TDrawTabEvent);
var
  Method: TMethod;
begin
  FDrawTab := Value;
  if Assigned(FDrawTab) then
    QClxStyle_drawTab_event(Method) := DrawTabHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawTab(Hooks, Method);
  Refresh;
end;

procedure TStyle.DoDrawTabMask(Source: TObject; Canvas: TCanvas; Index,
  HorizontalPadding, VerticalPadding, Overlap: Integer; Selected: Boolean);
begin
  if Assigned(FDrawTabMask) then
    FDrawTabMask(Self, Source, Canvas, Index, HorizontalPadding,
    VerticalPadding, Overlap, Selected);
end;

procedure TStyle.DrawTabMaskHook(p1: QPainterH; p2: QTabBarH;
  index: Integer; selected: Boolean);
var
  Canvas: TCanvas;
  Source: TObject;
  HorizontalPadding,
  VerticalPadding,
  Overlap: Integer;
begin
  try
    Canvas := TCanvas.Create;
    try
      QClxStyle_tabBarMetrics(Handle, P2, @HorizontalPadding, @VerticalPadding,
        @Overlap);
      Source := FindControl(p2);
      Canvas.Handle := p1;
      Canvas.Start(False);
      DoDrawTabMask(Source, Canvas, index, HorizontalPadding, VerticalPadding,
        Overlap, selected);
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;


procedure TStyle.SetDrawTabMask(const Value: TDrawTabEvent);
var
  Method: TMethod;
begin
  FDrawTabMask := Value;
  if Assigned(FDrawTabMask) then
    QClxStyle_DrawTabMask_event(Method) := DrawTabMaskHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_DrawTabMask(Hooks, Method);
  Refresh;
end;

procedure TStyle.DoScrollBarMetrics(ScrollBar: QScrollBarH; var SliderMin,
  SliderMax, SliderLength, ButtonSize: Integer);
var
  StockLen, StockSize: Integer;
begin
  if Assigned(FScrollBarMetrics) then
  begin
    StockLen := SliderLength;
    StockSize := ButtonSize;
    FScrollBarMetrics(Self, ScrollBar, SliderLength, ButtonSize);
    SliderMin := SliderMin + (ButtonSize - StockSize);
    SliderMax := SliderMax - (ButtonSize - StockSize) - (SliderLength - StockLen);
  end;
end;

procedure TStyle.ScrollBarMetricsHook(p1: QScrollBarH; var sliderMin,
  sliderMax, sliderLength, buttonDim: Integer);
begin
  try
    DoScrollBarMetrics(p1, sliderMin, sliderMax, sliderLength, buttonDim);
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetScrollBarMetrics(const Value: TScrollBarMetricsEvent);
var
  Method: TMethod;
begin
  FScrollBarMetrics := Value;
  if Assigned(FScrollBarMetrics) then
    QClxStyle_scrollBarMetrics_event(Method) := ScrollBarMetricsHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_scrollBarMetrics(Hooks, Method);
  Refresh;
end;

function TStyle.DoDrawScrollBar(ScrollBar: QScrollBarH; Canvas: TCanvas;
  const Rect: TRect; SliderStart, SliderLength, ButtonSize: Integer; Controls: TScrollBarControls;
  DownControl: TScrollBarControl): Boolean;
begin
  Result := True;
  if Assigned(FDrawScrollBar) then
    FDrawScrollBar(Self, ScrollBar, Canvas, Rect, SliderStart,
    SliderLength, ButtonSize, Controls, DownControl, Result);
end;

procedure TStyle.DrawScrollBarHook(p1: QPainterH; p2: QScrollBarH;
  sliderStart: Integer; controls, activeControl: Integer;
  var Stage: Integer);
var
  Canvas: TCanvas;
  Size: TSize;
  SliderMin, SliderMax,
  SliderLength, ButtonSize: Integer;
  ControlSet: TScrollBarControls;
  DownControl: TScrollBarControl;
begin
  try
    Canvas := TCanvas.Create;
    try
      QClxStyle_scrollBarMetrics(Handle, p2, @SliderMin, @SliderMax, @SliderLength,
        @ButtonSize);
      ControlSet := [];
      if (controls and Integer(QStyleScrollControl_AddLine)) <> 0 then
        Include(ControlSet, sbcAddButton);
      if (controls and Integer(QStyleScrollControl_SubLine)) <> 0 then
        Include(ControlSet, sbcSubButton);
      if (controls and Integer(QStyleScrollControl_AddPage)) <> 0 then
        Include(ControlSet, sbcAddPage);
      if (controls and Integer(QStyleScrollControl_SubPage)) <> 0 then
        Include(ControlSet, sbcSubPage);
      if (controls and Integer(QStyleScrollControl_Slider)) <> 0 then
        Include(ControlSet, sbcSlider);

      case QStyleScrollControl(activeControl) of
        QStyleScrollControl_AddLine: DownControl := sbcAddButton;
        QStyleScrollControl_SubLine: DownControl := sbcSubButton;
        QStyleScrollControl_AddPage: DownControl := sbcAddPage;
        QStyleScrollControl_SubPage: DownControl := sbcSubPage;
        QStyleScrollControl_Slider: DownControl := sbcSlider;
      else
        DownControl := sbcNone;
      end;

      QWidget_size(p2, @Size);
      Canvas.Handle := p1;
      Canvas.Start(False);
      if DoDrawScrollBar(p2, Canvas, Rect(0, 0, Size.cx, Size.cy), sliderStart,
        SliderLength, ButtonSize, ControlSet, DownControl) then
        Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawScrollBar(const Value: TDrawScrollBarEvent);
var
  Method: TMethod;
begin
  FDrawScrollBar := Value;
  if Assigned(FDrawScrollBar) then
    QClxStyle_drawScrollBarControls_Event(Method) := DrawScrollBarHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawScrollBarControls(Hooks, Method);
  Refresh;
end;

function TStyle.GetSliderLength: Integer;
begin
  Result := QClxStyle_sliderLength(Handle);
end;

procedure TStyle.SetSliderLength(const Value: Integer);
begin
  QClxStyle_setSliderLength(Handle, Value);
  Refresh;
end;

function TStyle.DoDrawTrackBar(Canvas: TCanvas; const Rect: TRect; Horizontal,
  TickAbove, TickBelow: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FDrawTrackBar) then
    FDrawTrackBar(Self, Canvas, Rect, Horizontal,
    TickAbove, TickBelow, Result);
end;

procedure TStyle.DrawSliderHook(p: QPainterH; x, y, w, h: Integer;
  g: QColorGroupH; p7: Orientation; tickAbove, tickBelow: Boolean;
  var Stage: Integer);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      if DoDrawTrackBar(Canvas, Rect(x, y, x+w, y+h), p7 = Orientation_Horizontal,
        tickAbove, tickBelow) then
        Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawTrackBar(const Value: TDrawTrackBarEvent);
var
  Method: TMethod;
begin
  FDrawTrackBar := Value;
  if Assigned(FDrawTrackBar) then
    QClxStyle_drawSlider_Event(Method) := DrawSliderHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawSlider(Hooks, Method);
  Refresh;
end;

function TStyle.DoDrawTrackBarMask(Canvas: TCanvas; const Rect: TRect; Horizontal,
  TickAbove, TickBelow: Boolean): Boolean;
begin
  if Assigned(FDrawTrackBarMask) then
    FDrawTrackBarMask(Self, Canvas, Rect, Horizontal, TickAbove,
    TickBelow, Result);
end;

procedure TStyle.DrawSliderMaskHook(p: QPainterH; x, y, w, h: Integer;
  p6: Orientation; tickAbove, tickBelow: Boolean);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      DoDrawTrackBarMask(Canvas, Rect(x, y, x+w, y+h), p6 = Orientation_Horizontal,
        tickAbove, tickBelow);
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawTrackBarMask(const Value: TDrawTrackBarEvent);
var
  Method: TMethod;
begin
  FDrawTrackBarMask := Value;
  if Assigned(FDrawTrackBarMask) then
    QClxStyle_drawSliderMask_Event(Method) := DrawSliderMaskHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawSliderMask(Hooks, Method);
  Refresh;
end;

function TStyle.DoDrawTrackBarGroove(Canvas: TCanvas; const Rect: TRect;
  Horizontal: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FDrawTrackBarGroove) then
    FDrawTrackBarGroove(Self, Canvas, Rect, Horizontal, Result);
end;

procedure TStyle.DrawSliderGrooveHook(p: QPainterH; x, y, w, h: Integer;
  g: QColorGroupH; c: QCOORD; p8: Orientation; var Stage: Integer);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      if DoDrawTrackBarGroove(Canvas, Rect(x, y, x+w, y+h), p8 = Orientation_Horizontal) then
        Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawTrackBarGroove(const Value: TDrawTrackBarGrooveEvent);
var
  Method: TMethod;
begin
  FDrawTrackBarGroove := Value;
  if Assigned(FDrawTrackBarGroove) then
    QClxStyle_drawSliderGroove_Event(Method) := DrawSliderGrooveHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawSliderGroove(Hooks, Method);
  Refresh;
end;

function TStyle.DoDrawTrackBarGrooveMask(Canvas: TCanvas; const Rect: TRect;
  Horizontal: Boolean): Boolean;
begin
  if Assigned(FDrawTrackBarGrooveMask) then
    FDrawTrackBarGrooveMask(Self, Canvas, Rect, Horizontal, Result);
end;

procedure TStyle.DrawSliderGrooveMaskHook(p: QPainterH; x, y, w, h: Integer;
  c: QCOORD; p8: Orientation);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      DoDrawTrackBarGrooveMask(Canvas, Rect(x, y, x+w, y+h), p8 = Orientation_Horizontal);
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawTrackBarGrooveMask(const Value: TDrawTrackBarGrooveEvent);
var
  Method: TMethod;
begin
  FDrawTrackBarGrooveMask := Value;
  if Assigned(FDrawTrackBarGrooveMask) then
    QClxStyle_drawSliderGrooveMask_Event(Method) := DrawSliderGrooveMaskHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawSliderGrooveMask(Hooks, Method);
  Refresh;
end;

function TStyle.GetMaxSliderDragDistance: Integer;
begin
  Result := QClxStyle_maximumSliderDragDistance(Handle);
end;

procedure TStyle.SetMaxSliderDragDistance(const Value: Integer);
begin
  QClxStyle_setMaximumSliderDragDistance(Handle, Value);
  Refresh;
end;

function TStyle.DoDrawSplitter(Canvas: TCanvas; const Rect: TRect;
  Vertical: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FDrawSplitter) then
    FDrawSplitter(Self, Canvas, Rect, Vertical, Result);
end;

procedure TStyle.DrawSplitterHook(p: QPainterH; x, y, w, h: Integer;
  g: QColorGroupH; p7: Orientation; var Stage: Integer);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      if DoDrawSplitter(Canvas, Rect(x, y, x+w, y+h), p7 = Orientation_Vertical) then
        Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawSplitter(const Value: TDrawSplitterEvent);
var
  Method: TMethod;
begin
  FDrawSplitter := Value;
  if Assigned(FDrawSplitter) then
    QClxStyle_drawSplitter_event(Method) := DrawSplitterHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawSplitter(Hooks, Method);
  Refresh;
end;

procedure TStyle.DoExtraMenuItemWidth(Source: TObject;
  HasCheckmark: Boolean; ImageWidth: Integer; FontMetrics: QFontMetricsH;
  var ExtraWidth: Integer);
begin
  if Assigned(FExtraMenuItemWidth) then
    FExtraMenuItemWidth(Self, Source, HasCheckmark, ImageWidth,
      FontMetrics, ExtraWidth);
end;

procedure TStyle.ExtraMenuItemWidthHook(checkable: Boolean;
  maxpmw: Integer; mi: QMenuItemH; fm: QFontMetricsH; var Retval: Integer);
var
  Source: TObject;
begin
  try
    Source := FindObject(QWidgetH(mi));
    if Source <> nil then
      DoExtraMenuItemWidth(Source, checkable, maxpmw, fm, Retval);
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetExtraMenuItemWidth(const Value: TExtraMenuItemWidthEvent);
var
  Method: TMethod;
begin
  FExtraMenuItemWidth := Value;
  if Assigned(FExtraMenuItemWidth) then
    QClxStyle_extraPopupMenuItemWidth_Event(Method) := ExtraMenuItemWidthHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_extraPopupMenuItemWidth(Hooks, Method);
  Refresh;
end;

procedure TStyle.DoSubmenuIndicatorWidth(FontMetrics: QFontMetricsH; var Width: Integer);
begin
  if Assigned(FSubmenuIndicatorWidth) then
    FSubmenuIndicatorWidth(Self, FontMetrics, Width);
end;

procedure TStyle.SetSubmenuIndicatorWidth(const Value: TSubmenuIndicatorWidthEvent);
var
  Method: TMethod;
begin
  FSubmenuIndicatorWidth := Value;
  if Assigned(FSubmenuIndicatorWidth) then
    QClxStyle_popupSubmenuIndicatorWidth_Event(Method) := SubMenuIndicatorWidthHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_popupSubmenuIndicatorWidth(Hooks, Method);
  Refresh;
end;

procedure TStyle.SubmenuIndicatorWidthHook(fm: QFontMetricsH; var Retval: Integer);
begin
  try
    DoSubmenuIndicatorWidth(fm, Retval);
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.DoMenuItemHeight(Source: TObject; Checkable: Boolean;
  FontMetrics: QFontMetricsH; var Height: Integer);
begin
  if Assigned(FMenuItemHeight) then
    FMenuItemHeight(Self, Source, Checkable, FontMetrics, Height);
end;

procedure TStyle.MenuItemHeightHook(checkable: Boolean; mi: QMenuItemH;
  fm: QFontMetricsH; var Height: Integer);
var
  Source: TObject;
begin
  try
    Source := FindObject(QWidgetH(mi));
    if Source <> nil then
      DoMenuItemHeight(Source, checkable, fm, Height);
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetMenuItemHeight(const Value: TMenuItemHeightEvent);
var
  Method: TMethod;
begin
  FMenuItemHeight := Value;
  if Assigned(FMenuItemHeight) then
    QClxStyle_popupMenuItemHeight_Event(Method) := MenuItemHeightHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_popupMenuItemHeight(Hooks, Method);
  Refresh;
end;

type
  TAppStyleAddr = procedure;
  PQStyleH = ^QStyleH;

var
  App_Style: TAppStyleAddr = nil;

function ObtainOwnershipofAppStyle: QStyleH;
begin
  Result := nil;
{$IFDEF LINUX}
  if not Assigned(App_Style) then
    App_Style := dlsym(RTLD_DEFAULT, '_12QApplication.app_style');
{$ENDIF}
  if Assigned(App_Style) then
  begin
    Result := PQStyleH(@App_Style)^;
    PQStyleH(@App_Style)^ := nil;
  end;
end;

procedure TStyle.SetDefaultStyle(const Value: TDefaultStyle);
begin
  if FDefaultStyle <> Value then
  begin
    FDefaultStyle := Value;
    Changed(Self);
  end;
end;

procedure TStyle.Changed(Sender: TObject);
begin
  Refresh;
  if Assigned(FOnChange) then
    FOnChange(Self);
end;

function TStyle.GetButtonShift: TPoint;
begin
  QClxStyle_buttonShift(Handle, @(Result.x), @(Result.y));
end;

procedure TStyle.SetButtonShift(const Value: TPoint);
begin
  QClxStyle_setButtonShift(Handle, Value.x, Value.y);
  Refresh;
end;

function TStyle.DoDrawCheck(Canvas: TCanvas; const Rect: TRect;
  Checked, Grayed, Down, Enabled: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FDrawCheck) then
    FDrawCheck(Self, Canvas, Rect, Checked, Grayed, Down, Enabled, Result);
end;

procedure TStyle.DrawCheckHook(p: QPainterH; x, y, w, h: Integer;
  g: QColorGroupH; State: Integer; Down, Enabled: Boolean;
  var Stage: Integer);
var
  Canvas: TCanvas;
  R: TRect;
begin
  try
    Canvas := TCanvas.Create;
    try
      R := Rect(x, y, x+w, y+h);
      Canvas.Handle := p;
      Canvas.Start(False);
       if DoDrawCheck(Canvas, R, Boolean(State and $02), Boolean(State and $01),
         Down, Enabled) then
         Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawCheck(const Value: TDrawCheckEvent);
var
  Method: TMethod;
begin
  FDrawCheck := Value;
  if Assigned(FDrawCheck) then
    QClxStyle_drawIndicator_Event(Method) := DrawCheckHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawIndicator(Hooks, Method);
  Refresh;
end;

function TStyle.DoDrawRadio(Canvas: TCanvas; const Rect: TRect; Checked, Down,
  Enabled: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FDrawRadio) then
    FDrawRadio(Self, Canvas, Rect, Checked, Down, Enabled, Result);
end;

procedure TStyle.DrawRadioHook(p: QPainterH; x, y, w, h: Integer;
  g: QColorGroupH; _on, down, enabled: Boolean; var Stage: Integer);
var
  Canvas: TCanvas;
  R: TRect;
begin
  try
    Canvas := TCanvas.Create;
    try
      R := Rect(x, y, x+w, y+h);
      Canvas.Handle := p;
      Canvas.Start(False);
       if DoDrawRadio(Canvas, R, _on, down, enabled) then
         Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawRadio(const Value: TDrawRadioEvent);
var
  Method: TMethod;
begin
  FDrawRadio := Value;
  if Assigned(FDrawRadio) then
    QClxStyle_drawExclusiveIndicator_Event(Method) := DrawRadioHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawExclusiveIndicator(Hooks, Method);
  Refresh;
end;


function TStyle.GetCheckSize: TSize;
begin
  QClxStyle_indicatorSize(Handle, @Result);
end;

function TStyle.GetRadioSize: TSize;
begin
  QClxStyle_exclusiveIndicatorSize(Handle, @Result);
end;

procedure TStyle.SetCheckSize(const Value: TSize);
begin
  QClxStyle_setIndicatorSize(Handle, @Value);
  Refresh;
end;

procedure TStyle.SetRadioSize(const Value: TSize);
begin
  QClxStyle_setExclusiveIndicatorSize(Handle, @Value);
  Refresh;
end;

procedure TStyle.DrawPanelHook(p: QPainterH; x, y, w, h: Integer;
  p6: QColorGroupH; sunken: Boolean; lineWidth: Integer; fill: QBrushH;
  var Stage: Integer);
var
  Canvas: TCanvas;
  R: TRect;
begin
  try
    Canvas := TCanvas.Create;
    try
      R := Rect(x, y, x+w, y+h);
      Canvas.Handle := p;
      Canvas.Start(False);
       if DoDrawFrame(Canvas, R, sunken, lineWidth) then
         Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

function TStyle.DoDrawFrame(Canvas: TCanvas; const Rect: TRect; Sunken: Boolean;
  LineWidth: Integer): Boolean;
begin
  Result := True;
  if Assigned(FDrawFrame) then
    FDrawFrame(Self, Canvas, Rect, Sunken, LineWidth, Result);
end;

procedure TStyle.SetDrawFrame(const Value: TDrawFrameEvent);
var
  Method: TMethod;
begin
  FDrawFrame := Value;
  if Assigned(FDrawFrame) then
    QClxStyle_drawPanel_Event(Method) := DrawPanelHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawPanel(Hooks, Method);
  Refresh;
end;

procedure TStyle.DoDrawMenuCheck(Canvas: TCanvas; const Rect: TRect; Highlighted,
  Enabled: Boolean);
begin
  if Assigned(FDrawMenuCheck) then
    FDrawMenuCheck(Self, Canvas, Rect, Highlighted, Enabled);
end;

procedure TStyle.DrawMenuCheckHook(p: QPainterH; x, y, w, h: Integer;
  g: QColorGroupH; act, dis: Boolean);
var
  Canvas: TCanvas;
  R: TRect;
begin
  try
    Canvas := TCanvas.Create;
    try
      R := Rect(x, y, x+w, y+h);
      Canvas.Handle := p;
      Canvas.Start(False);
      DoDrawMenuCheck(Canvas, R, act, dis);
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawMenuCheck(const Value: TDrawMenuCheckEvent);
var
  Method: TMethod;
begin
  FDrawMenuCheck := Value;
  if Assigned(FDrawMenuCheck) then
    QClxStyle_drawCheckMark_Event(Method) := DrawMenuCheckHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawCheckMark(Hooks, Method);
  Refresh;
end;

procedure TStyle.DrawItemHook(p: QPainterH; x, y, w, h, flags: Integer;
  g: QColorGroupH; enabled: Boolean; pixmap: QPixmapH; text: PString;
  len: Integer; penColor: QColorH; var Stage: Integer);
var
  Canvas: TCanvas;
  R: TRect;
  Bitmap: TBitmap;
  Color: TColor;
begin
  try
    Canvas := TCanvas.Create;
    try
      Bitmap := TBitmap.Create;
      try
        if penColor = nil then
          Color := clText
        else
          Color := QColorColor(penColor);
        Bitmap.Handle := pixmap;
        Canvas.Handle := p;
        Canvas.Start(False);
        R := Rect(x, y, x+w, y+h);
        case Stage of
          DrawStage_Pre:
            if DoBeforeDrawItem(Canvas, R, flags, enabled, Bitmap, text^, len, Color) then
              Stage := DrawStage_DefaultDraw;
          DrawStage_Post:
            DoAfterDrawItem(Canvas, R, flags, enabled, Bitmap, text^, len, Color);
        end;
        Canvas.Stop;
      finally
        Bitmap.Free;
      end;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.DoAfterDrawItem(Canvas: TCanvas; const Rect: TRect;
  Flags: Integer; Enabled: Boolean; Bitmap: TBitmap; const Text: WideString;
  Length: Integer; Color: TColor);
begin
  if Assigned(FAfterDrawItem) then
    FAfterDrawItem(Self, Canvas, Rect, Flags, Enabled, Bitmap, Text, Length, Color);
end;

function TStyle.DoBeforeDrawItem(Canvas: TCanvas; const Rect: TRect;
  Flags: Integer; Enabled: Boolean; Bitmap: TBitmap; const Text: WideString;
  Length: Integer; Color: TColor): Boolean;
begin
  Result := True;
  if Assigned(FBeforeDrawItem) then
    FBeforeDrawItem(Self, Canvas, Rect, Flags, Enabled, Bitmap, Text, Length,
      Color, Result);
end;

procedure TStyle.SetAfterDrawItem(const Value: TAfterDrawItemEvent);
var
  Method: TMethod;
begin
  FAfterDrawItem := Value;
  if Assigned(FBeforeDrawItem) then
    Exit;
  if Assigned(FAfterDrawItem) then
    QClxStyle_drawItem_Event(Method) := DrawItemHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawItem(Hooks, Method);
  Refresh;
end;

procedure TStyle.SetBeforeDrawItem(const Value: TBeforeDrawItemEvent);
var
  Method: TMethod;
begin
  FBeforeDrawItem := Value;
  if Assigned(FAfterDrawItem) then
    Exit;
  if Assigned(FBeforeDrawItem) then
    QClxStyle_drawItem_Event(Method) := DrawItemHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawItem(Hooks, Method);
  Refresh;
end;

function TStyle.DoDrawComboButton(Canvas: TCanvas; const Rect: TRect; Sunken,
  ReadOnly, Enabled: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FDrawComboButton) then
    FDrawComboButton(Self, Canvas, Rect, Sunken, ReadOnly, Enabled, Result);
end;

procedure TStyle.DrawComboButtonHook(p: QPainterH; x, y, w, h: Integer;
  g: QColorGroupH; sunken, editable, enabled: Boolean; fill: QBrushH;
  var Stage: Integer);
var
  Canvas: TCanvas;
  R: TRect;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      R := Rect(x, y, x+w, y+h);
      if DoDrawComboButton(Canvas, R, sunken, not editable, enabled) then
        Stage := DrawStage_DefaultDraw;
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawComboButton(const Value: TDrawComboButtonEvent);
var
  Method: TMethod;
begin
  FDrawComboButton := Value;
  if Assigned(FDrawComboButton) then
    QClxStyle_drawComboButton_Event(Method) := DrawComboButtonHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_drawComboButton(Hooks, Method);
  Refresh;
end;

procedure TStyle.DoDrawButtonMask(Canvas: TCanvas; const Rect: TRect);
begin
  if Assigned(FDrawButtonMask) then
    FDrawButtonMask(Self, Canvas, Rect);
end;

procedure TStyle.DrawButtonMaskHook(p: QPainterH; x, y, w, h: Integer);
var
  Canvas: TCanvas;
begin
  try
    Canvas := TCanvas.Create;
    try
      Canvas.Handle := p;
      Canvas.Start(False);
      DoDrawButtonMask(Canvas, Rect(x, y, x+w, y+h));
      Canvas.Stop;
    finally
      Canvas.Free;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TStyle.SetDrawButtonMask(const Value: TDrawMaskEvent);
var
  Method: TMethod;
begin
  FDrawButtonMask := Value;
  if Assigned(FDrawButtonMask) then
    QClxStyle_DrawButtonMask_Event(Method) := DrawButtonMaskHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_DrawButtonMask(Hooks, Method);
  Refresh;
end;

procedure ResetSystemStyle;
begin
{$IFDEF LINUX}
  if Assigned(LoadThemeHook) and not Assigned(AppResetStyle) then
    AppResetStyle := dlsym(LoadThemeHook(), 'KApplication_resetGUIStyle');
  if Assigned(AppResetStyle) then
    AppResetStyle
  else
{$ENDIF}
    QApplication_setStyle(QWindowsStyle_create);
end;

{ TApplicationStyle }

destructor TApplicationStyle.Destroy;
begin
  if Assigned(FHooks) then
    QClxStyleHooks_hook_StyleDestroyed(FHooks, NullHook);
  if Assigned(Application) and not (Application.Terminated) then
    ResetSystemStyle;
  inherited Destroy;
end;

procedure TApplicationStyle.CreateHandle;
var
  Temp: WideString;
  Method: TMethod;
  TempStyle: QStyleH;
begin
  if (FDefaultStyle = dsSystemDefault) then
  begin
{$IFDEF LINUX}
    if FRecreating then
      ResetSystemStyle;
{$ENDIF}
    TempStyle := ObtainOwnershipofAppStyle;
    FHooks := QClxStyleHooks_create;
    FHandle := QClxStyle_create(TempStyle, FHooks);
  end
  else
  begin
    FHooks := QClxStyleHooks_create;
    Temp := cStyles[FDefaultStyle];
    FHandle := QClxStyle_create(@Temp, FHooks);
  end;
  QClxStyle_StyleDestroyed_Event(Method) := StyleDestroyedHook;
  QClxStyleHooks_hook_StyleDestroyed(FHooks, Method);
  QApplication_setStyle(FHandle);
end;

procedure TApplicationStyle.StyleDestroyed;
begin
  if not FRecreating then
  begin
    if Assigned(FHooks) then
      QClxStyleHooks_hook_StyleDestroyed(FHooks, NullHook);
    FHandle := nil;
    FHooks := nil;
    if Assigned(Application) and not Application.Terminated then
      HandleNeeded;
  end;
end;

procedure TApplicationStyle.DoPolish(Source: TObject);
begin
  if Assigned(FOnPolish) then
    FOnPolish(Self, Source);
end;

procedure TApplicationStyle.PolishHook(p1: QApplicationH);
begin
  try
    DoPolish(Application);
  except
    Application.HandleException(Self);
  end;
end;

procedure TApplicationStyle.SetDefaultStyle(const Value: TDefaultStyle);
begin
  if FDefaultStyle <> Value then
  begin
    FRecreating := True;
    try
      FHandle := nil;
      FHooks := nil;
      FDefaultStyle := Value;
      HandleNeeded;
    finally
      FRecreating := False;
    end;
    Changed(Self);
  end;
end;

procedure TApplicationStyle.SetOnPolish(const Value: TPolishEvent);
var
  Method: TMethod;
begin
  FOnPolish := Value;
  if Assigned(FOnPolish) then
    QClxStyle_polish2_Event(Method) := PolishHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_polish2(Hooks, Method);
  Refresh;
end;

{ TWidgetStyle }

procedure TWidgetStyle.DoPolish(Source: TObject);
begin
  if Assigned(FOnPolish) then
    FOnPolish(Self, Source);
end;

procedure TWidgetStyle.PolishHook(p1: QWidgetH);
var
  Source: TObject;
begin
  try
    TWidgetControl(Source) := FindControl(p1);
    DoPolish(Source);
  except
    Application.HandleException(Self);
  end;
end;

procedure TWidgetStyle.SetDefaultStyle(const Value: TDefaultStyle);
begin
  if FDefaultStyle <> Value then
  begin
    if FDefaultStyle <> dsSystemDefault then
    begin
      if Assigned(FHandle) then
        QClxStyle_destroy(FHandle);
    end;
    FHandle := nil;
    FDefaultStyle := Value;
    HandleNeeded;
    Changed(Self);
  end;
end;

procedure TWidgetStyle.SetOnPolish(const Value: TPolishEvent);
var
  Method: TMethod;
begin
  FOnPolish := Value;
  if Assigned(FOnPolish) then
    QClxStyle_polish_Event(Method) := PolishHook
  else
    Method := NullHook;
  QClxStyleHooks_hook_polish(Hooks, Method);
  Refresh;
end;
          
end.
