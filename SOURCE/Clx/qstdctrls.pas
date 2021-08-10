{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QStdCtrls;

{$R-,T-,H+,X+}

interface

uses Types, Qt, SysUtils, Classes, QTypes, QControls, QForms, QMenus,
  QGraphics, QActnList, QStyle;

type
  TCustomGroupBox = class(TFrameControl)
  private
    FCaption: TCaption;
    function GetHandle: QGroupBoxH;
  protected
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    procedure CreateWidget; override;
    procedure FontChanged; override;
    function GetText: TCaption; override;
    procedure InitWidget; override;
    procedure SetText(const Value: TCaption); override;
    function GetAlignment: TAlignment;
    procedure SetAlignment(const Value: TAlignment);
    function WantKey(Key: Integer; Shift: TShiftState; const KeyText: WideString): Boolean; override;
    function WidgetFlags: Integer; override;
    property Alignment: TAlignment read GetAlignment write SetAlignment default taLeftJustify;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Invalidate; override;
    property Handle: QGroupBoxH read GetHandle;
  end;

  TGroupBox = class(TCustomGroupBox)
  published
    property Align default alNone;
    property Alignment;
    property Anchors;
    property Bitmap;
    property BorderStyle default bsEtched;
    property Caption;
    property Color default clBackground;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property Masked default False;
    property ParentColor default True;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint default False;
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
    property OnStartDrag;
  end;

type
  TLCDMode = (lcdHexadecimal, lcdDecimal, lcdOctal, lcdBinary);
  TLCDSegmentStyle = (ssOutline, ssFilled, ssFlat);
  TLCDPointSize = (ptSmall, ptLarge);
  TNumDigits = 0..99;

  TCustomLCDNumber = class(TFrameControl)
  private
    FValue: AnsiString;
    FOnOverflow: TNotifyEvent;
    FAutoSize: Boolean;
    FMode: TLCDMode;
    FSegmentStyle: TLCDSegmentStyle;
    FPtSize: TLCDPointSize;
    FNumDigits: TNumDigits;
    procedure SetMode(const Value: TLCDMode);
    procedure SetNumDigits(const Value: TNumDigits);
    procedure SetPointSize(const Value: TLCDPointSize);
    procedure SetSegmentStyle(const Value: TLCDSegmentStyle);
    procedure SetValue(const Value: AnsiString);
    procedure DoOverflow; cdecl;
    procedure SetOnOverflow(const Value: TNotifyEvent);
    procedure ResizeView;
    procedure SetAutoSize(const Value: Boolean);
    function GetHandle: QLCDNumberH;
  protected
    procedure CreateWidget; override;
    procedure ColorChanged; override;
    property AutoSize: Boolean read FAutoSize write SetAutoSize;
    property BorderStyle default bsEmbossed;
    property Color default clBackground;
    property Digits: TNumDigits read FNumDigits write SetNumDigits;
    property Mode: TLCDMode read FMode write SetMode;
    property PointSize: TLCDPointSize read FPtSize write SetPointSize;
    property SegmentStyle: TLCDSegmentStyle read FSegmentStyle write SetSegmentStyle;
    property Value: AnsiString read FValue write SetValue;
    property OnOverflow: TNotifyEvent read FOnOverflow write SetOnOverflow;
  public
    constructor Create(AOwner: TComponent); override;
    property Handle: QLCDNumberH read GetHandle;
  end;

  TLCDNumber = class(TCustomLCDNumber)
  protected
    procedure InitWidget; override;
  published
    property Align;
    property Anchors;
    property AutoSize default False;
    property Bitmap;
    property BorderStyle;
    property Color;
    property Constraints;
    property Digits default 4;
    property DragMode;
    property Hint;
    property Mode default lcdDecimal;
    property ParentColor;
    property ParentShowHint;
    property PointSize default ptSmall;
    property SegmentStyle default ssOutline;
    property ShowHint;
    property Value;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnOverflow;
    property OnStartDrag;
    property OnClick;
    property OnDblClick;
    property OnMouseMove;
    property OnMouseDown;
    property OnMouseUp;
  end;

type
  TTextLayout = (tlTop, tlCenter, tlBottom);

  TCustomLabel = class(TFrameControl)
  private
    FAutoSize: Boolean;
    FFocusControl: TWidgetControl;
    FShowAccel: Boolean;
    procedure DoAutoSize;
    procedure GetSize(var AWidth, AHeight: Integer);
    function GetAlignment: TAlignment;
    procedure SetAlignment(const Value: TAlignment);
    procedure SetFocusControl(const Value: TWidgetControl);
    procedure SetLayout(const Value: TTextLayout);
    procedure SetWordWrap(const Value: Boolean);
    function GetLayout: TTextLayout;
    function GetWordWrap: Boolean;
    function GetHandle: QLabelH;
    function GetTransparent: Boolean;
    procedure SetTransparent(const Value: Boolean);
    procedure SetShowAccel(const Value: Boolean);
  protected
    function GetText: TCaption; override;
    procedure SetText(const Value: TCaption); override;
    procedure CreateWidget; override;
    procedure FontChanged; override;
    function GetLabelText: WideString; virtual;
    procedure InitWidget; override;
    procedure Loaded; override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure SetAutoSize(Value: Boolean); virtual;
    procedure TextChanged; override;
    function WantKey(Key: Integer; Shift: TShiftState;
      const KeyText: WideString): Boolean; override;
    property Alignment: TAlignment read GetAlignment write SetAlignment
      default taLeftJustify;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default True;
    property BorderStyle default bsNone;
    property Caption: TCaption read GetText write SetText;
    property FocusControl: TWidgetControl read FFocusControl write SetFocusControl;
    property Layout: TTextLayout read GetLayout write SetLayout default tlTop;
    property ParentColor default True;
    property ShowAccelChar: Boolean read FShowAccel write SetShowAccel default True;
    property ShowHint default False;
    property Transparent: Boolean read GetTransparent write SetTransparent default False;
    property WordWrap: Boolean read GetWordWrap write SetWordWrap default False;
  public
    constructor Create(AOwner: TComponent); override;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    property Handle: QLabelH read GetHandle;
  end;

  TLabel = class(TCustomLabel)
  published
    property Align;
    property Alignment;
    property Anchors;
    property AutoSize;
    property Bitmap;
    property BorderStyle;
    property Caption; 
    property Color;
    property Constraints;
    property DragMode;
    property Enabled;
    property FocusControl;
    property Font;
    property Masked;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property ShowAccelChar;
    property ShowHint;  
    property Transparent;
    property Layout;
    property Visible;
    property WordWrap;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
  end;

  TEditCharCase = (ecNormal, ecUpperCase, ecLowerCase);
  TEchoMode = (emNormal, emNone, emPassword);

  TCustomEdit = class(TWidgetControl)
  private
    FOnChange: TNotifyEvent;
    FOnReturnPressed: TNotifyEvent;
    FCharCase: TEditCharCase;
    FAutoSize: Boolean;
    FHideSelection: Boolean;
    FIgnoreEvents: Boolean;
    FMaxLength: Integer;
    function FontHeight: Integer;
    function GetAlignment: TAlignment;
    function GetBorderStyle: TControlBorderStyle;
    function GetEchoMode: TEchoMode;
    function GetHandle: QClxLineEditH;
    function GetModified: Boolean;
    procedure ReturnPressedHook; cdecl;
    procedure SetAlignment(const Value: TAlignment);
    procedure SetBorderStyle(const Value: TControlBorderStyle);
    procedure SetEchoMode(const Value: TEchoMode);
    procedure SetMaxLength(const Value: Integer);
    procedure SetModified(const Value: Boolean);
    procedure SetOnReturnPressed(const Value: TNotifyEvent);
    procedure TextChangedHook(Text: PWideString); cdecl;
    function GetAutoSelect: Boolean;
    procedure SetAutoSelect(const Value: Boolean);
    function GetReadOnly: Boolean;
    procedure SetReadOnly(const Value: Boolean);
    procedure SetAutoSize(const Value: Boolean);
    procedure SetHideSelection(const Value: Boolean);
    procedure UpdateHeight;
  protected
    procedure Change; virtual;
    procedure CreateWidget; override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure FontChanged; override;
    function GetSelLength: Integer; virtual;
    function GetSelStart: Integer; virtual;
    function GetSelText: WideString; virtual;
    function GetText: TCaption; override;
    procedure HookEvents; override;
    procedure InitWidget; override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure Loaded; override;
    procedure SetSelLength(Value: Integer); virtual;
    procedure SetSelStart(Value: Integer); virtual;
    procedure SetSelText(const Value: WideString); virtual;
    procedure SetText(const Value: TCaption); override;
    property Alignment: TAlignment read GetAlignment write SetAlignment default taLeftJustify;
    property AutoSelect: Boolean read GetAutoSelect write SetAutoSelect default True;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default True;
    property BorderStyle: TControlBorderStyle read GetBorderStyle write SetBorderStyle default bsSingle;
    property CharCase: TEditCharCase read FCharCase write FCharCase default ecNormal;
    property Color default clBase;
    property DragMode default dmManual;
    property EchoMode: TEchoMode read GetEchoMode write SetEchoMode default emNormal;
    property HideSelection: Boolean read FHideSelection write SetHideSelection default True;
    property MaxLength: Integer read FMaxLength write SetMaxLength default -1;
    property ParentColor default False;
    property ReadOnly: Boolean read GetReadOnly write SetReadOnly default False;
    property ShowHint default False;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnReturnPressed: TNotifyEvent read FOnReturnPressed write SetOnReturnPressed;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Clear; virtual;
    procedure ClearSelection;
    procedure CopyToClipboard;         
    procedure CutToClipboard; virtual;
    function GetSelTextBuf(Buffer: PChar; BufSize: Integer): Integer;
    procedure PasteFromClipboard; virtual;
    procedure SelectAll;
    procedure SetSelTextBuf(Buffer: PChar);
    property Handle: QClxLineEditH read GetHandle;
    property Modified: Boolean read GetModified write SetModified;
    property SelLength: Integer read GetSelLength write SetSelLength;
    property SelStart: Integer read GetSelStart write SetSelStart;
    property SelText: WideString read GetSelText write SetSelText;
    property Text: TCaption read GetText write SetText;
  published
    property TabStop default True;
  end;

  TEdit = class(TCustomEdit)
  published
    property Anchors;
    property AutoSelect;
    property AutoSize;
    property Alignment;
    property BorderStyle;
    property CharCase;
    property Color;
    property Constraints;
    property DragMode;
    property EchoMode;
    property Enabled;
    property Font;
    property HideSelection;
    property MaxLength;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ReadOnly;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Text;
    property Visible;
    property OnChange;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnReturnPressed;
    property OnStartDrag;
  end;

  TCaretPos = record
    Line,
    Col: Integer;
  end;

  TMemoSelection = record
    case Integer of
      0: (Line1, Col1, Line2, Col2: Integer);
      1: (TopLeft, BottomRight: TCaretPos);
  end;

  TWrapMode = (wmNone, wmWidth, wmPixel, wmColumn);
  TWrapBreak = (wbWhitespace, wbAnywhere);
  TScrollStyle = (ssNone, ssHorizontal, ssVertical, ssBoth, ssAutoHorizontal,
    ssAutoVertical, ssAutoBoth);

  TCustomMemo = class(TFrameControl)
  private
    FLines: TStrings;
    FOnReturnPressed: TNotifyEvent;
    FOnChange: TNotifyEvent;
    FWantTabs: Boolean;
    FWantReturns: Boolean;
    FScrollBars: TScrollStyle;
    FWrapMode: TWrapMode;
    FWordWrap: Boolean;
    FMaxLength: Integer;
    function CaretPosToPos(CaretPos: TCaretPos): Integer;
    function GetAlignment: TAlignment;
    function GetCaretPos: TCaretPos;
    function GetHandle: QOpenMultiLineEditH;
    function GetHMargin: Integer;
    function GetModified: Boolean;
    function GetReadOnly: Boolean;
    function GetSelection: TMemoSelection;
    function GetTextWidth(LineNum: Integer): Integer;
    function GetWrapBreak: TWrapBreak;
    function GetWrapValue: Integer;
    procedure InternalSetWrapMode(NewMode: TWrapMode);
    function PosToCaretPos(Pos: Integer): TCaretPos;
    procedure ReturnPressedHook; cdecl;
    procedure TextChangedHook; cdecl;
    procedure CMKeyDown(var Msg: TCMKeyDown); message CM_KEYDOWN;
  protected
    procedure Change; virtual;
    procedure CreateWidget; override;
    procedure FontChanged; override;
    function GetSelLength: Integer; virtual;
    function GetSelStart: Integer; virtual;
    function GetSelText: WideString; virtual;
    function GetText: TCaption; override;
    procedure HookEvents; override;
    procedure InitWidget; override;
    function LineLength(Index: Integer): Integer;
    procedure Loaded; override;
    function NeedKey(Key: Integer; Shift: TShiftState;
      const KeyText: WideString): Boolean; override;
    procedure ReturnPressed; virtual;
    procedure SetText(const Value: TCaption); override;
    procedure SetSelText(const Value: WideString); virtual;
    procedure SetSelStart(const Value: Integer); virtual;
    procedure SetSelLength(const Value: Integer); virtual;
    procedure SetModified(const Value: Boolean); virtual;
    procedure SetReadOnly(const Value: Boolean); virtual;
    procedure SetCaretPos(const Value: TCaretPos);
    procedure SetHMargin(const Value: Integer);
    procedure SetLines(const Value: TStrings);
    procedure SetScrollBars(const Value: TScrollStyle);
    procedure SetWordWrap(const Value: Boolean);
    procedure SetMaxLength(const Value: Integer);
    procedure SetAlignment(const Value: TAlignment);
    procedure SetWrapMode(const Value: TWrapMode);
    procedure SetWrapValue(const Value: Integer);
    procedure SetWrapBreak(const Value: TWrapBreak);
    property ParentColor default False;
    property ScrollBars: TScrollStyle read FScrollBars write SetScrollBars default ssNone;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnReturnPressed: TNotifyEvent read FOnReturnPressed write FOnReturnPressed;

    property ReadOnly: Boolean read GetReadOnly write SetReadOnly default False;
    property HMargin: Integer read GetHMargin write SetHMargin default 3;
    property Alignment: TAlignment read GetAlignment write SetAlignment default taLeftJustify;
    property BorderStyle default bsSunken3d;
    property Lines: TStrings read FLines write SetLines;
    property MaxLength: Integer read FMaxLength write SetMaxLength default -1;
    property ShowHint default False;
    property TabStop default True;
    property WantReturns: Boolean read FWantReturns write FWantReturns default True;
    property WantTabs: Boolean read FWantTabs write FWantTabs default False;
    property WordWrap: Boolean read FWordWrap write SetWordWrap default True;
    property WrapAtValue: Integer read GetWrapValue write SetWrapValue default -1;
    property WrapBreak: TWrapBreak read GetWrapBreak write SetWrapBreak default wbWhitespace;
    property WrapMode: TWrapMode read FWrapMode write SetWrapMode default wmWidth;
  public
    procedure Append(const Text: WideString);
    function AtEOF: Boolean;
    procedure Clear; virtual;
    procedure ClearSelection;
    procedure UnSelect;
    procedure CopyToClipboard;
    procedure CutToClipboard;
    function GetTextBuf(Buffer: PChar; BufSize: Integer): Integer; // depricated
    function GetTextLen: Integer; // depricated
    function HasSelection: Boolean;
    procedure Insert(const Text: WideString; Mark: Boolean = False); overload;
    procedure Insert(const Text: WideString; Column, Row: Integer;
      Mark: Boolean = False); overload;
    procedure PasteFromClipboard;
    procedure SelectAll;
    property CaretPos: TCaretPos read GetCaretPos write SetCaretPos;
    property Handle: QOpenMultiLineEditH read GetHandle;
    property Modified: Boolean read GetModified write SetModified;
    property Selection: TMemoSelection read GetSelection;
    property SelLength: Integer read GetSelLength write SetSelLength;
    property SelStart: Integer read GetSelStart write SetSelStart;
    property SelText: WideString read GetSelText write SetSelText;
    property Text: TCaption read GetText write SetText;
    property TextWidth[LineNum: Integer]: Integer read GetTextWidth;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  TMemo = class(TCustomMemo)
  published
    property Align;
    property Alignment;
    property Anchors;
    property BorderStyle;
    property Color;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property HMargin;
    property Lines;
    property MaxLength;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ReadOnly;
    property ScrollBars;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Visible;
    property WantReturns;
    property WantTabs;
    property WordWrap;
    property WrapAtValue;
    property WrapBreak;
    property WrapMode;
    property OnChange;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
  end;

  TComboBoxStyle = (csDropDown, csDropDownList, csOwnerDrawFixed,
    csOwnerDrawVariable);

  TComboBoxInsertMode = (ciNone, ciTop, ciCurrent, ciBottom, ciAfterCurrent,
    ciBeforeCurrent);

  TOwnerDrawState = set of (odSelected, odGrayed, odDisabled, odChecked,
    odFocused, odDefault, odHotLight, odInactive, odNoAccel, odNoFocusRect,
    odReserved1, odReserved2, odComboBoxEdit);

  TComboBoxHighlightEvent = procedure(Sender: TObject; Index: Integer) of object;

  TDrawItemEvent = procedure(Sender: TObject; Index: Integer;
    Rect: TRect; State: TOwnerDrawState; var Handled: Boolean) of object;

  TMeasureItemEvent = procedure(Control: TWinControl; Index: Integer;
    var Height: Integer) of object;

  TCustomComboBox = class(TWidgetControl)
  private
    FCanvas: TCanvas;
    FItems: TStrings;
    FMaxItems: Integer;
    FMaxLength: Integer;
    FStyle: TComboBoxStyle;
    FEditHook: QLineEdit_hookH;
    FEditHandle: QLineEditH;
    FListHook: QListBox_hookH;
    FListBoxHandle: QListBoxH;
    FListBoxDrawHooks: QClxListBoxHooksH;
    FItemHeight: Integer;
    FJustDropped: Boolean;
    FMemStream: TMemoryStream;
    FOnChange: TNotifyEvent;
    FOnHighlighted: TComboBoxHighlightEvent;
    FOnSelect: TNotifyEvent;
    FCharCase: TEditCharCase;
    FOnCloseUp: TNotifyEvent;
    FOnDrawItem: TDrawItemEvent;
    FOnMeasureItem: TMeasureItemEvent;
    FOnDropDown: TNotifyEvent;
    function AdjustHeight: Integer;
    procedure ChangeHook(Text: PWideString); cdecl;
    function EditEventFilter(Sender: QObjectH; Event: QEventH): Boolean; cdecl;
    function ListEventFilter(Sender: QObjectH; Event: QEventH): Boolean; cdecl;
    function EditHandle: QLineEditH;
    function GetAutoComplete: Boolean;
    function GetDropDownCount: Integer;
    function GetHandle: QOpenComboBoxH;
    function GetItemIndex: Integer;
    procedure HighlightedHook(Index: Integer); cdecl;
    procedure SelectedHook(Index: Integer); cdecl;
    procedure SetAutoComplete(const Value: Boolean);
    procedure SetDropDownCount(const Value: Integer);
    procedure SetItemIndex(const Value: Integer);
    procedure SetItems(const Value: TStrings);
    procedure SetMaxItems(const Value: Integer);
    function GetInsertMode: TComboBoxInsertMode;
    procedure SetInsertMode(const Value: TComboBoxInsertMode);
    procedure SetDuplicates(const Value: TDuplicates);
    function GetDuplicates: TDuplicates;
    function GetDroppedDown: Boolean;
    procedure SetDroppedDown(const Value: Boolean);
    function GetSelLength: Integer;
    function GetSelStart: Integer;
    function GetSelText: WideString;
    procedure SetSelLength(const Value: Integer);
    procedure SetSelStart(const Value: Integer);
    procedure SetSelText(const Value: WideString);
    procedure ItemPaintHook(listBox: QListBoxH; p: QPainterH; Index: Integer;
      Rect: PRect; Flags: Integer; var Handled: Boolean); cdecl;
    procedure ItemMeasureHook(index: Integer; var height, width: Integer); cdecl;
    procedure SetSorted(const Value: Boolean);
    function GetSorted: Boolean;
    procedure SetItemHeight(const Value: Integer);
    function GetItemHeight: integer;
    procedure DoDropDown;
    procedure DoCloseUp;
    procedure CMKeyDown(var Msg: TCMKeyDown); message CM_KEYDOWN;
    procedure SetMaxLength(const Value: Integer);
  protected
    function ListBoxHandle: QListBoxH;
    procedure Change; dynamic;
    procedure Click; override;
    procedure CloseUp; dynamic;
    procedure CreateWidget; override;
    procedure CursorChanged; override;
    procedure HookEvents; override;
    procedure DestroyWidget; override;
    function DrawItem(Index: Integer; Rect: TRect;
      State: TOwnerDrawState): Boolean; virtual;
    procedure DoEnter; override;
    procedure DoExit; override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure MeasureItem(Control: TWinControl; Index: Integer;
      var Height, Width: Integer); virtual;
    procedure DropDown; dynamic;
    procedure FontChanged; override;
    procedure Highlighted(Index: Integer); dynamic;
    procedure InitWidget; override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyUp(var Key: Word; Shift: TShiftState); override;
    procedure Loaded; override;
    procedure PaletteChanged(Sender: TObject); override;
    function GetText: TCaption; override;
    procedure SetText(const Value: TCaption); override;
    procedure RestoreWidgetState; override;
    procedure SaveWidgetState; override;        
    procedure Select; dynamic;
    procedure SetStyle(Value: TComboBoxStyle); virtual;
    property AutoComplete: Boolean read GetAutoComplete write SetAutoComplete default False;
    property DropDownCount: Integer read GetDropDownCount write SetDropDownCount default 8;
    property Duplicates: TDuplicates read GetDuplicates write SetDuplicates default dupAccept;
    property InsertMode: TComboBoxInsertMode read GetInsertMode write SetInsertMode default ciNone;
    property ItemHeight: Integer read GetItemHeight write SetItemHeight default 16;
    property MaxItems: Integer read FMaxItems write SetMaxItems default -1;
    property MaxLength: Integer read FMaxLength write SetMaxLength default -1;
    property ParentColor default False;
    property Sorted: Boolean read GetSorted write SetSorted default False;
    property Style: TComboBoxStyle read FStyle write SetStyle default csDropDown;
    property Text: TCaption read GetText write SetText;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnCloseUp: TNotifyEvent read FOnCloseUp write FOnCloseUp;
    property OnDropDown: TNotifyEvent read FOnDropDown write FOnDropDown;
    property OnHighlighted: TComboBoxHighlightEvent read FOnHighlighted write FOnHighlighted;
    property OnSelect: TNotifyEvent read FOnSelect write FOnSelect;
    property OnDrawItem: TDrawItemEvent read FOnDrawItem write FOnDrawItem;
    property OnMeasureItem: TMeasureItemEvent read FOnMeasureItem write FOnMeasureItem;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Clear;
    function Focused: Boolean; override;
    procedure SelectAll;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    procedure Sort;
    property Canvas: TCanvas read FCanvas;
    property DroppedDown: Boolean read GetDroppedDown write SetDroppedDown;
    property Handle: QOpenComboBoxH read GetHandle;
    property Items: TStrings read FItems write SetItems;
    property ItemIndex: Integer read GetItemIndex write SetItemIndex default -1;
    property SelLength: Integer read GetSelLength write SetSelLength;
    property SelStart: Integer read GetSelStart write SetSelStart;
    property SelText: WideString read GetSelText write SetSelText;
  published
    property CharCase: TEditCharCase read FCharCase write FCharCase default ecNormal;
    property TabStop default True;
  end;

  TComboBox = class(TCustomComboBox)
  published
    property Style; { Must be published before Items }
    property Anchors;
    property AutoComplete;
    property CharCase;
    property Color default clBase;
    property Constraints;
    property DragMode;
    property DropDownCount;
    property Duplicates;
    property Enabled;
    property Font;
    property InsertMode;
    property ItemHeight;
    property Items;
    property ItemIndex;
    property MaxItems;
    property MaxLength;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint default False;
    property Sorted;
    property TabOrder;
    property TabStop;
    property Text;
    property Visible;
    property OnChange;
    property OnClick;
    property OnCloseUp;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnDrawItem;
    property OnDropDown;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnHighlighted;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnMeasureItem;
    property OnSelect;
    property OnStartDrag;
  end;

{ TButtonControl }

  TButtonControl = class;

  TToggleState = (tsOff, tsNoChange, tsOn);
  TToggledEvent = procedure(Sender: TObject; Toggled: Boolean) of object;
  TStateChangedEvent = procedure(Sender: TObject; State: TToggleState) of object;

  TButtonActionLink = class(TWidgetControlActionLink)
  protected
    FClient: TButtonControl;
    procedure AssignClient(AClient: TObject); override;
    function IsCheckedLinked: Boolean; override;
    procedure SetChecked(Value: Boolean); override;
  end;

  TButtonActionLinkClass = class of TButtonActionLink;

  TButtonControl = class(TWidgetControl)
  private
    FClicksDisabled: Boolean;
    FAccelChar: Char;
    FOnStateChanged: TStateChangedEvent;
    function IsCheckedStored: Boolean;
    procedure StateChangedHook(State: Integer); cdecl;
    function GetAutoRepeat: Boolean;
    function GetDown: Boolean;
    function GetHandle: QButtonH;
    function GetState: TToggleState;
    procedure SetAutoRepeat(const Value: Boolean);
    procedure SetDown(const Value: Boolean);
    function IsToggleButton: Boolean;
  protected
    function GetText: TCaption; override;
    procedure SetText(const Value: TCaption); override;
    procedure ActionChange(Sender: TObject; CheckDefaults: Boolean); override;
    function GetActionLinkClass: TControlActionLinkClass; override;
    function GetChecked: Boolean; virtual;
    procedure HookEvents; override;
    procedure SetChecked(Value: Boolean); virtual;
    procedure StateChanged(State: TToggleState); dynamic;
    function WantKey(Key: Integer; Shift: TShiftState;
      const KeyText: WideString): Boolean; override;
    property Caption: TCaption read GetText write SetText;
    property Checked: Boolean read GetChecked write SetChecked stored IsCheckedStored default False;
    property Down: Boolean read GetDown write SetDown;
    property State: TToggleState read GetState;
    property AutoRepeat: Boolean read GetAutoRepeat write SetAutoRepeat default False;
    property ClicksDisabled: Boolean read FClicksDisabled write FClicksDisabled;
    property OnStateChanged: TStateChangedEvent read FOnStateChanged write FOnStateChanged;
  public
    constructor Create(AOwner: TComponent); override;
    function AccelChar: Char;
    procedure AnimateClick;
    procedure Toggle; virtual;
    property Handle: QButtonH read GetHandle;
  end;

  TButton = class(TButtonControl)
  private
    FCancel: Boolean;
    FDefault: Boolean;
    FModalResult: TModalResult;
    FOnToggled: TToggledEvent;
    function GetHandle: QPushButtonH;
    function GetToggleButton: Boolean;
    procedure SetOnToggled(const Value: TToggledEvent);
    procedure SetToggleButton(const Value: Boolean);
    procedure ToggleHook(IsToggled: Boolean); cdecl;
    procedure SetDefault(const Value: Boolean);
  protected
    procedure BeginAutoDrag; override;
    procedure CreateWidget; override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure KeyUp(var Key: Word; Shift: TShiftState); override;
    function NeedKey(Key: Integer; Shift: TShiftState;
      const KeyText: WideString): Boolean; override;
    procedure Toggled(IsToggled: Boolean); dynamic;
    function WantKey(Key: Integer; Shift: TShiftState;
      const KeyText: WideString): Boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Click; override;
    property Handle: QPushButtonH read GetHandle;
    property Down;
  published
    property Action;
    property Anchors;
    property Bitmap;
    property Cancel: Boolean read FCancel write FCancel default False;
    property Caption;
    property Color default clBtnFace;
    property Constraints;
    property Default: Boolean read FDefault write SetDefault default False;
    property DragMode;
    property Enabled;
    property Font;
    property ModalResult: TModalResult read FModalResult write FModalResult default mrNone;
    property ParentColor default False;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint default False;
    property TabOrder;
    property TabStop default True;
    property ToggleButton: Boolean read GetToggleButton write SetToggleButton default False;
    property Visible;
    property OnClick;
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
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
    property OnStateChanged;
    property OnToggled: TToggledEvent read FOnToggled write SetOnToggled;
  end;

  TCheckBoxState = (cbUnchecked, cbChecked, cbGrayed);

  TCustomCheckBox = class(TButtonControl)
  private
    FAllowGrayed: Boolean;
    FState: TCheckBoxState;
    function GetHandle: QCheckBoxH;
    procedure SetState(Value: TCheckBoxState);
    procedure SetAllowGrayed(const Value: Boolean);
  protected
    procedure CreateWidget; override;
    function GetChecked: Boolean; override;
    procedure SetChecked(Value: Boolean); override;
    procedure StateChanged(State: TToggleState); override;
    function WantKey(Key: Integer; Shift: TShiftState;
      const KeyText: WideString): Boolean; override;
    property AllowGrayed: Boolean read FAllowGrayed write SetAllowGrayed default False;
    property State: TCheckBoxState read FState write SetState default cbUnchecked;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Toggle; override;
    property Handle: QCheckBoxH read GetHandle;
  published
    property TabStop default True;
  end;

  TCheckBox = class(TCustomCheckBox)
  published
    property Action;
    property AllowGrayed;
    property Anchors;
    property Bitmap;
    property Caption;
    property Checked;
    property Color default clBackground;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
    property Masked default False;
    property ParentColor default True;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint default False;
    property State;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnClick;
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
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
  end;

  TRadioButton = class(TButtonControl)
  private
    procedure ClickedHook; cdecl;
    function GetHandle: QRadioButtonH;
    procedure TurnSiblingsOff;
  protected
    procedure CreateWidget; override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    function GetChecked: Boolean; override;
    procedure HookEvents; override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X,
      Y: Integer); override;
    procedure SetChecked(Value: Boolean); override;
    function WantKey(Key: Integer; Shift: TShiftState;
      const KeyText: WideString): Boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Click; override;
    property Handle: QRadioButtonH read GetHandle;
  published
    property Action;
    property Anchors;
    property Bitmap;
    property Caption;
    property Checked;
    property Color default clBackground;
    property Constraints;
    property DragMode;
    property Enabled;
    property Font;
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
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyString;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDrag;
  end;

const
  QEventType_LBClick = QEventType(Integer(QEventType_ClxBase) + $20);

type
  TListBoxLayout = (llFixedNumber, llFitToWidth, llVariable);
  TListBoxStyle = (lbStandard, lbOwnerDrawFixed, lbOwnerDrawVariable);


  TCustomListBox = class(TFrameControl)
  private
    FDeleting: Boolean;
    FItems: TStrings;
    { FTabWidth: Integer; }
    FCanvas: TCanvas;
    FStyle: TListBoxStyle;
    FOnDrawItem: TDrawItemEvent;
    FOnMeasureItem: TMeasureItemEvent;
    FViewportHook: QWidget_hookH;
    FViewportHandle: QWidgetH;
    FDrawHooks: QClxListBoxHooksH;
    FItemHeight: Integer;
    FSaveItems: TStringList;
    FExtendedSelect: Boolean;
    FMultiSelect: Boolean;
    FClicking: Boolean;
    procedure DrawEmptyFocus;
    function GetHandle: QListBoxH;
    function GetColumns: Integer;
    function GetItemIndex: Integer;
    function GetSelCount: Integer;
    function GetSelected(Index: Integer): Boolean;
    function GetTopIndex: Integer;
    procedure SetColumns(const Value: Integer);
    procedure SetExtendedSelect(const Value: Boolean);
    procedure SetItemIndex(const Value: Integer);
    procedure SetItems(const Value: TStrings);
    procedure SetMultiSelect(const Value: Boolean);
    procedure SetSelected(Index: Integer; const Value: Boolean);
    procedure SetSorted(const Value: Boolean);
    procedure SetTopIndex(const Value: Integer);
    function GetRows: Integer;
    procedure SetRows(const Value: Integer);
    function GetColumnLayout: TListBoxLayout;
    function GetRowLayout: TListBoxLayout;
    procedure SetColumnLayout(const Value: TListBoxLayout);
    procedure SetRowLayout(const Value: TListBoxLayout);
    function ViewportEventFilter(Sender: QObjectH; Event: QEventH): Boolean; cdecl;
    procedure ItemPaintHook(listBox: QListBoxH; p: QPainterH; Index: Integer;
      Rect: PRect; Flags: Integer; var Handled: Boolean); cdecl;
    procedure ItemMeasureHook(index: Integer; var height, width: Integer); cdecl;
    procedure SetStyle(const Value: TListBoxStyle);
    function GetSorted: Boolean;
    procedure SetItemHeight(const Value: Integer);
    procedure SelChangeHook; cdecl;
    procedure AdjustHeight;
  protected
    procedure Changed; virtual;
    procedure CreateWidget; override;
    function GetChildHandle: QWidgetH; override;
    procedure DblClick; override;
    procedure DeleteString(Index: Integer); dynamic;
    function DrawItem(Index: Integer; Rect: TRect;
      State: TOwnerDrawState): Boolean; virtual;
    procedure EnabledChanged; override;
    procedure MeasureItem(Control: TWinControl; Index: Integer;
      var Height, Width: Integer); virtual;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; override;
    procedure FontChanged; override;
    function GetItemData(Index: Integer): LongInt; dynamic;
    procedure InitWidget; override;
    procedure HookEvents; override;
    procedure Loaded; override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure ResetContent; dynamic;
    procedure RestoreWidgetState; override;
    procedure SaveWidgetState; override;
    procedure SetItemData(Index: Integer; AData: LongInt); dynamic;
    procedure WidgetDestroyed; override;
    property BorderStyle default bsSunken3d;
    property Columns: Integer read GetColumns write SetColumns default 1;
    property ColumnLayout: TListBoxLayout read GetColumnLayout write SetColumnLayout default llFixedNumber;
    property ExtendedSelect: Boolean read FExtendedSelect write SetExtendedSelect default True;
    property ItemHeight: Integer read FItemHeight write SetItemHeight default 16;
    property MultiSelect: Boolean read FMultiSelect write SetMultiSelect default False;
    property ParentColor default False;
    property RowLayout: TListBoxLayout read GetRowLayout write SetRowLayout default llVariable;
    property Rows: Integer read GetRows write SetRows default 1;
    property Sorted: Boolean read GetSorted write SetSorted default False;
    property Style: TListBoxStyle read FStyle write SetStyle default lbStandard;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Clear;
    procedure ClearSelection;
    function ItemAtPos(Pos: Types.TPoint; Existing: Boolean): Integer;
    function ItemRect(Index: Integer): TRect;
    function ItemVisible(Index: Integer): Boolean;
    procedure MakeCurrentVisible;
    procedure Sort;
    procedure Update; override;
    function VisibleItemCount: Integer;
    property Canvas: TCanvas read FCanvas;
    property Handle: QListBoxH read GetHandle;
    property Items: TStrings read FItems write SetItems;
    property ItemIndex: Integer read GetItemIndex write SetItemIndex;
    property SelCount: Integer read GetSelCount;
    property Selected[Index: Integer]: Boolean read GetSelected write SetSelected;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    property TopIndex: Integer read GetTopIndex write SetTopIndex;
    property OnDrawItem: TDrawItemEvent read FOnDrawItem write FOnDrawItem;
    property OnMeasureItem: TMeasureItemEvent read FOnMeasureItem write FOnMeasureItem;
  published
    property TabStop default True;
  end;

  TListBox = class(TCustomListBox)
  published
    property Style; { Must be published before Items }
    property Align;
    property Anchors;
    property BorderStyle;
    property Color default clBase;
    property Columns;
    property ColumnLayout;
    property Constraints;
    property DragMode;
    property Enabled;
    property ExtendedSelect;
    property Font;
    property ItemHeight;
    property Items;
    property MultiSelect;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property RowLayout;
    property Rows;
    property ShowHint default False;
    property Sorted;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnDrawItem;
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

  TScrollCode = (scLineUp, scLineDown, scPageUp, scPageDown, scPosition,
    scTrack, scTop, scBottom, scEndScroll);

  TScrollEvent = procedure(Sender: TObject; ScrollCode: TScrollCode;
    var ScrollPos: Integer) of object;

  TScrollBar = class(TWidgetControl)
  private
    FParamsChanging: Boolean;
    FKind: TScrollBarKind;
    FRangeControl: QRangeControlH;
    FOnChange: TNotifyEvent;
    FOnScroll: TScrollEvent;
    procedure DoScroll(Code: TScrollCode);
    function GetHandle: QScrollBarH;
    procedure NextLineHook; cdecl;
    procedure NextPageHook; cdecl;
    procedure PrevLineHook; cdecl;
    procedure PrevPageHook; cdecl;
    procedure SetKind(Value: TScrollBarKind);
    procedure SetMax(Value: Integer);
    procedure SetMin(Value: Integer);
    procedure SetPosition(Value: Integer);
    function GetTracking: Boolean;
    procedure SetTracking(const Value: Boolean);
    procedure SliderPressedHook; cdecl;
    procedure SliderReleasedHook; cdecl;
    procedure ValueChangedHook(Value: Integer); cdecl;
    function GetPosition: Integer;
    function GetLargeChange: TScrollBarInc;
    function GetMax: Integer;
    function GetMin: Integer;
    function GetSmallChange: TScrollBarInc;
    function RangeControl: QRangeControlH;
    procedure SetLargeChange(const Value: TScrollBarInc);
    procedure SetSmallChange(const Value: TScrollBarInc);
  protected
    procedure Change; dynamic;
    procedure CreateWidget; override;
    procedure HookEvents; override;
    procedure InitWidget; override;
    procedure KeyUp(var Key: Word; Shift: TShiftState); override;
    procedure Loaded; override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer); override;
    procedure Scroll(ScrollCode: TScrollCode; var ScrollPos: Integer); dynamic;
    procedure TabStopChanged; override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure SetParams(APosition, AMin, AMax: Integer);
    property Handle: QScrollBarH read GetHandle;
  published
    property Align default alNone;
    property Anchors;
    property Bitmap;
    property Color default clBackground;
    property Constraints;
    property DragMode;
    property Enabled;
    property Kind: TScrollBarKind read FKind write SetKind default sbHorizontal;
    property LargeChange: TScrollBarInc read GetLargeChange write SetLargeChange default 1;
    property Max: Integer read GetMax write SetMax default 100;
    property Min: Integer read GetMin write SetMin default 0;
    property ParentColor default True;
    property ParentShowHint;
    property PopupMenu;
    property Position: Integer read GetPosition write SetPosition default 0;
    property ShowHint default False;
    property SmallChange: TScrollBarInc read GetSmallChange write SetSmallChange default 1;
    property TabOrder;
    property TabStop default True;
    property Track: Boolean read GetTracking write SetTracking default True;
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
    property OnScroll: TScrollEvent read FOnScroll write FOnScroll;
    property OnStartDrag;
  end;

implementation

uses QConsts, QClipbrd;

const
  AlignmentFlags: array[TAlignment] of Integer =
    (Integer(AlignmentFlags_AlignLeft), Integer(AlignmentFlags_AlignRight),
     Integer(AlignmentFlags_AlignHCenter));

  AlignmentFlags_AlignmentMask = $FFF8;
  AlignmentFlags_LayoutMask = $FFC7;

  ClxListBoxItem_Selected = $01;
  ClxListBoxItem_Grayed = $02;
  ClxListBoxItem_Focused = $04;

type
  QClxListItem_paint_Event = procedure(listBox: QListBoxH; p: QPainterH; Index: Integer; Rect: PRect;
    Flags: Integer; var Handled: Boolean) of object cdecl;
  QClxListItem_measure_Event = procedure(index: Integer; var height,
    width: Integer) of object cdecl;

  TCustomListBoxStrings = class(TStrings)
  private
    FSorted: Boolean;
    FPutting: Boolean;
    FOwner: TWidgetControl;
    function ListBoxHandle: QListBoxH; virtual; abstract;
    function DrawHooks: QClxListBoxHooksH; virtual; abstract;
    procedure SetSorted(const Value: Boolean);
  protected
    function Get(Index: Integer): string; override;
    function GetCount: Integer; override;
    procedure Put(Index: Integer; const S: string); override;
    property Sorted: Boolean read FSorted write SetSorted;
  public
    function Add(const S: string): Integer; override;
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Exchange(Index1, Index2: Integer); override;
    procedure Insert(Index: Integer; const S: string); override;
    procedure Move(CurIndex, NewIndex: Integer); override;
    procedure Sort;
  end;

  TRowState = record
    RowLayout, ColLayout: TListBoxLayout;
    Rows, Cols: Integer;
  end;

  TListBoxStrings = class(TCustomListBoxStrings)
  private
    FRowState: TRowState;
    function ListBoxHandle: QListBoxH; override;
    function DrawHooks: QClxListBoxHooksH; override;
  protected
    function GetObject(Index: Integer): TObject; override;
    procedure PutObject(Index: Integer; AObject: TObject); override;
    procedure SetUpdateState(Updating: Boolean); override;
  end;

  TComboBoxStrings = class(TCustomListBoxStrings)
  private
    FDuplicates: TDuplicates;
    function ListBoxHandle: QListBoxH; override;
    function DrawHooks: QClxListBoxHooksH; override;
    procedure SetDuplicates(const Value: TDuplicates);
  protected
    function GetObject(Index: Integer): TObject; override;
    procedure PutObject(Index: Integer; AObject: TObject); override;
  public
    constructor Create;
    procedure Insert(Index: Integer; const S: string); override;
    property Duplicates: TDuplicates read FDuplicates write SetDuplicates;
  end;

function QAlignmentToTAlignment(Value: Integer): TAlignment;
begin
  Result := taLeftJustify;

  if Value and Integer(AlignmentFlags_AlignHCenter) <> 0 then
    Result := taCenter
  else if Value and Integer(AlignmentFlags_AlignRight) <> 0 then
    Result := taRightJustify;
end;

{ TCustomListBoxStrings }

function TCustomListBoxStrings.Add(const S: string): Integer;
begin
  if not Sorted or (csRecreating in FOwner.ControlState) then
    Result := GetCount
  else begin
    { Can't do this on the Qt side since the ComboBox secretly creates its own
      listbox, so adding to a sorted ListBox, ComboBox is gonna be kind of slow...
      recommend turning off Sorted and calling Sort as needed. }
    Result := 0;
    while (Result < GetCount) and (AnsiCompareStr(S, Strings[Result]) > 0) do
      Inc(Result);
  end;
  Insert(Result, S);
end;

procedure TCustomListBoxStrings.Clear;
begin
  QListBox_clear(ListBoxHandle);
end;

procedure TCustomListBoxStrings.Delete(Index: Integer);
begin
  TCustomListBox(FOwner).FDeleting := True;
  try
    QListBox_removeItem(ListBoxHandle, Index);
  finally
    TCustomListBox(FOwner).FDeleting := False
  end;
end;

procedure TCustomListBoxStrings.Exchange(Index1, Index2: Integer);
var
  TempData: TObject;
  TempString: string;
begin
  TempString := Strings[Index1];
  TempData := GetObject(Index1);
  Strings[Index1] := Strings[Index2];
  PutObject(Index1, GetObject(Index2));
  Strings[Index2] := TempString;
  PutObject(Index2, TempData);
end;

function TCustomListBoxStrings.Get(Index: Integer): string;
var
  Item: QListBoxItemH;
  WItem: WideString;
begin
  Item := QListBox_item(ListBoxHandle, Index);
  if Item = nil then Error(SListIndexError, Index);
  QListBoxItem_text(Item, PWideString(@WItem));
  Result := WItem;
end;

function TCustomListBoxStrings.GetCount: Integer;
begin
  Result := QListBox_count(ListBoxHandle);
end;

procedure TCustomListBoxStrings.Insert(Index: Integer; const S: string);
var
  Item: QClxListBoxItemH;
  WS: WideString;
begin
  WS := S;
  Item := QClxListBoxItem_create(PWideString(@WS), DrawHooks, nil);
  if Index >= GetCount then Index := -1;
  QListBox_insertItem(ListBoxHandle, Item, Index);
end;

procedure TCustomListBoxStrings.Move(CurIndex, NewIndex: Integer);
var
  TempData: TObject;
  TempString: string;
begin
  if CurIndex <> NewIndex then
  begin
    TempString := Get(CurIndex);
    TempData := GetObject(CurIndex);
    Delete(CurIndex);
    InsertObject(NewIndex, TempString, TempData);
  end;
end;

procedure TCustomListBoxStrings.Put(Index: Integer; const S: string);
var
  CurIndex: Integer;
begin
  FPutting := True;
  try
    CurIndex := QListBox_currentItem(ListBoxHandle);
    inherited Put(Index, S);
    QListBox_setCurrentItem(ListBoxHandle, CurIndex);
  finally
    FPutting := False;
  end;
end;

procedure TCustomListBoxStrings.SetSorted(const Value: Boolean);
begin
  if FSorted <> Value then
  begin
    FSorted := Value;
    Sort;
  end;
end;

procedure TCustomListBoxStrings.Sort;
begin
  QListBox_sort(ListBoxHandle, True);
  { QWidget_update and QWidget_repaint have no effect here }
  QListBox_triggerUpdate(ListBoxHandle, False);
end;

{ TListBoxStrings }

function TListBoxStrings.ListBoxHandle: QListBoxH;
begin
  Result := QListBoxH(FOwner.Handle);
end;

function TListBoxStrings.DrawHooks: QClxListBoxHooksH;
begin
  Result := TCustomListBox(FOwner).FDrawHooks;
end;

function TListBoxStrings.GetObject(Index: Integer): TObject;
begin
  Result := TObject(TCustomListBox(FOwner).GetItemData(Index));
end;

procedure TListBoxStrings.PutObject(Index: Integer; AObject: TObject);
begin
  TCustomListBox(FOwner).SetItemData(Index, Integer(AObject));
end;

procedure TListBoxStrings.SetUpdateState(Updating: Boolean);
begin
  if Updating then
  begin
    FRowState.RowLayout := TCustomListBox(FOwner).GetRowLayout;
    FRowState.ColLayout := TCustomListBox(FOwner).GetColumnLayout;
    FRowState.Rows := TCustomListBox(FOwner).Rows;
    FRowState.Cols := TCustomListBox(FOwner).Columns;
  end
  else begin
    if FRowState.RowLayout = llFixedNumber then
      TCustomListBox(FOwner).Rows := FRowState.Rows
    else
      TCustomListBox(FOwner).RowLayout := FRowState.RowLayout;
      
    if FRowState.ColLayout = llFixedNumber then
      TCustomListBox(FOwner).Columns := FRowState.Cols
    else
      TCustomListBox(FOwner).ColumnLayout := FRowState.ColLayout;
  end;
  inherited SetUpdateState(Updating);
end;

{ TComboBoxStrings }

function TComboBoxStrings.ListBoxHandle: QListBoxH;
begin
  Result := TCustomComboBox(FOwner).ListBoxHandle;
end;

function TComboBoxStrings.DrawHooks: QClxListBoxHooksH;
begin
  Result := TCustomComboBox(FOwner).FListBoxDrawHooks;
end;

procedure TComboBoxStrings.Insert(Index: Integer; const S: string);
begin
  if Cardinal(GetCount) >= Cardinal(TCustomComboBox(FOwner).MaxItems) then
    Exit;
    case Duplicates of
    dupIgnore:
      if IndexOf(S) > -1 then Exit;
    dupError:
      if IndexOf(S) > -1 then
        Error(@SDuplicateString, 0);
    end;
  inherited Insert(Index, S);
end;

procedure TComboBoxStrings.SetDuplicates(const Value: TDuplicates);
begin
  if Duplicates <> Value then
  begin
    FDuplicates := Value;
    QComboBox_setDuplicatesEnabled(TCustomComboBox(FOwner).Handle, FDuplicates = dupAccept);
  end;
end;

constructor TComboBoxStrings.Create;
begin
  inherited Create;
  FDuplicates := dupAccept;
end;

function TComboBoxStrings.GetObject(Index: Integer): TObject;
var
  Item: QClxListBoxItemH;
begin
  Result := nil;
  Item := QClxListBoxItemH(QListBox_item(ListBoxHandle, Index));
  if Item <> nil then
    Result := TObject(QClxListBoxItem_getData(Item));
end;

procedure TComboBoxStrings.PutObject(Index: Integer; AObject: TObject);
var
  Item: QClxListBoxItemH;
begin
  Item := QClxListBoxItemH(QListBox_item(ListBoxHandle, Index));
  if Item <> nil then
    QClxListBoxItem_setData(Item, Pointer(AObject));
end;

{ TCustomGroupBox }

procedure TCustomGroupBox.AlignControls(AControl: TControl;
  var Rect: TRect);

begin
  QFrame_contentsRect(Handle, @Rect);
  if Caption <> '' then
    Inc(Rect.Top, Font.Height div 2);
  inherited AlignControls(AControl, Rect);
end;

constructor TCustomGroupBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csAcceptsControls, csCaptureMouse, csClickEvents,
    csSetCaption, csDoubleClicks, csReplicatable];
  Palette.ColorRole := crBackground;
  Palette.TextColorRole := crForeground;
  TabStop := False;
  Width := 185;
  Height := 105;
end;

procedure TCustomGroupBox.CreateWidget;
begin
  FHandle := QGroupBox_create(ParentWidget, nil);
end;

procedure TCustomGroupBox.FontChanged;
begin
  inherited FontChanged;
  Invalidate;
end;

function TCustomGroupBox.GetText: TCaption;
begin
  Result := FCaption;
end;

procedure TCustomGroupBox.Invalidate;
begin
  inherited;
  InvalidateRect(ClientRect, True);
end;


procedure TCustomGroupBox.SetText(const Value: TCaption);
var
  NeedAlign: Boolean;
begin
  NeedAlign := ((Value = '') and (Caption <> '')) or
    ((Value <> '') and (Caption = ''));
  if Caption <> Value then
  begin
    FCaption := Value;
    QGroupBox_setTitle(Handle, PWideString(@FCaption));
    if NeedAlign then Realign;
    Invalidate;
    TextChanged;
  end;
end;

procedure TCustomGroupBox.SetAlignment(const Value: TAlignment);
begin
  if Value <> Alignment then
  begin
    QGroupBox_setAlignment(Handle, AlignmentFlags[Value]);
    Invalidate;
  end;
end;

function TCustomGroupBox.GetAlignment: TAlignment;
begin
  Result := QAlignmentToTAlignment(QGroupBox_alignment(Handle));
end;

function TCustomGroupBox.GetHandle: QGroupBoxH;
begin
  HandleNeeded;
  Result := QGroupBoxH(FHandle);
end;

procedure TCustomGroupBox.InitWidget;
begin
  inherited InitWidget;
  BorderStyle := bsEtched;
end;

function TCustomGroupBox.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  if IsAccel(Key, Caption) and CanFocus then
  begin
    SelectFirst;
    Result := True;
  end else
    Result := inherited WantKey(Key, Shift, KeyText);
end;

function TCustomGroupBox.WidgetFlags: Integer;
begin
  Result := inherited WidgetFlags or Integer(WidgetFlags_WPaintDesktop) or Integer(WidgetFlags_WRepaintNoErase);
end;

{ TCustomLabel }

constructor TCustomLabel.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csNoFocus];
  Palette.ColorRole := crBackground;
  Palette.TextColorRole := crForeground;
  TabStop := False;
  FAutoSize := True;
  FShowAccel := True;
end;

procedure TCustomLabel.CreateWidget;
begin
  FHandle := QLabel_create(ParentWidget, nil, WidgetFlags);
  Hooks := QWidget_hook_create(FHandle);
end;

procedure TCustomLabel.DoAutoSize;
var
  NewLeft,
  NewWidth,
  NewHeight: Integer;
begin
  if FAutoSize then
  begin
    NewLeft := Left;
    NewWidth := Width;
    NewHeight := Height;
    GetSize(NewWidth, NewHeight);
    if Alignment = taRightJustify then
      NewLeft := Left - NewWidth + Width;
    SetBounds(NewLeft, Top, NewWidth, NewHeight);
end;
end;

procedure TCustomLabel.GetSize(var AWidth, AHeight: Integer);
const
  WrapFlag: array[Boolean] of Integer =
    (0, Integer(AlignmentFlags_WordBreak));
var
  FM: QFontMetricsH;
  Str: WideString;
  R: TRect;
  Extra: Integer;
  begin
    FM := QFontMetrics_create(Font.Handle);
    try
      Str := GetText;
      QFontMetrics_boundingRect(FM, @R, 0, 0, AWidth, MaxInt,
      QLabel_alignment(Handle) or WrapFlag[WordWrap],
        @Str, -1, 0, nil, nil);
      if Align in [alLeft, alRight, alNone, alCustom] then
        AWidth := R.Right - R.Left;
      if Align in [alBottom, alTop, alNone, alCustom] then
        AHeight := R.Bottom - R.Top;
      Extra := QFrame_frameWidth(Handle);
      if Extra > 0 then
      begin
        Inc(AWidth, Extra * 2);
        Inc(AHeight, Extra * 2);
        QFrame_contentsRect(Handle, @R);
        Inc(AHeight, R.Top * 2);
        Inc(AWidth, R.Left * 2);
      end;
    finally
      QFontMetrics_destroy(FM);
  end;
end;

procedure TCustomLabel.FontChanged;
begin
  inherited FontChanged;
  if not (csLoading in ComponentState) then
    DoAutoSize;
end;

procedure TCustomLabel.TextChanged;
begin
  inherited TextChanged;
  if not (csLoading in ComponentState) then
    DoAutoSize;
end;

function TCustomLabel.GetAlignment: TAlignment;
begin
  Result := QAlignmentToTAlignment(QLabel_alignment(Handle));
end;

function TCustomLabel.GetText: TCaption;
begin
  QLabel_text(Handle, PWideString(@Result));
end;

function TCustomLabel.GetHandle: QLabelH;
begin
  HandleNeeded;
  Result := QLabelH(FHandle);
end;

function TCustomLabel.GetLabelText: WideString;
begin
  Result := Caption; //For compatibility. Not used by underlying Qt Label.
end;

function TCustomLabel.GetLayout: TTextLayout;
var
  Value: Integer;
begin
  Value := QLabel_alignment(Handle);
  if Value and Integer(AlignmentFlags_AlignTop) <> 0 then
    Result := tlTop
  else
    if Value and Integer(AlignmentFlags_AlignBottom) <> 0 then
      Result := tlBottom
    else
      Result := tlCenter; { default }
end;

function TCustomLabel.GetWordWrap: Boolean;
begin
  Result := QLabel_alignment(Handle) and Integer(AlignmentFlags_WordBreak) <> 0;
end;

procedure TCustomLabel.InitWidget;
var
  AlignFlags: Integer;
begin
  inherited InitWidget;
  BorderStyle := bsNone;
  Layout := tlTop;
  AlignFlags := QLabel_alignment(Handle);
  QLabel_setAlignment(Handle, AlignFlags or Integer(AlignmentFlags_ShowPrefix)
    or Integer(AlignmentFlags_AlignTop) or Integer(AlignmentFlags_AlignLeft));
  QWidget_setFocusPolicy(Handle, QWidgetFocusPolicy_NoFocus);
end;

procedure TCustomLabel.Loaded;
begin
  inherited Loaded;
  if Align = alNone then SetAutoSize(FAutoSize);
end;

procedure TCustomLabel.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
end;

procedure TCustomLabel.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  inherited SetBounds(ALeft, ATop, AWidth, AHeight);
  Update;
end;

procedure TCustomLabel.SetAlignment(const Value: TAlignment);
var
  AlignFlags: Word;
begin
  if Alignment <> Value then
  begin
    AlignFlags := QLabel_alignment(Handle);
    AlignFlags := AlignFlags and AlignmentFlags_AlignmentMask or AlignmentFlags[Value];
    QLabel_setAlignment(Handle, AlignFlags);
  end;
end;

procedure TCustomLabel.SetAutoSize(Value: Boolean);
begin
  FAutoSize := Value;
  DoAutoSize;
end;

procedure TCustomLabel.SetShowAccel(const Value: Boolean);
var
  Flags: Integer;
begin
  if FShowAccel <> Value then
  begin
    FShowAccel := Value;
    Flags := QLabel_alignment(Handle);
    if FShowAccel then
      Flags := Flags or Integer(AlignmentFlags_ShowPrefix)
    else
      Flags := Flags and not Integer(AlignmentFlags_ShowPrefix);
    QLabel_setAlignment(Handle, Flags);
  end;
end;

procedure TCustomLabel.SetText(const Value: TCaption);
begin
  if Caption <> Value then
  begin
    QLabel_setText(Handle, PWideString(@Value));
    if Assigned(FFocusControl) then
      QLabel_setBuddy(Handle, FFocusControl.Handle);
    TextChanged;
  end;
end;

procedure TCustomLabel.SetFocusControl(const Value: TWidgetControl);
var
  Buddy: QWidgetH;
begin
  if Value <> FFocusControl then
  begin
    if Value <> nil then
      Buddy := Value.Handle
    else
      Buddy := nil;
    QLabel_setBuddy(Handle, Buddy);
    FFocusControl := Value;
    { Note: Qt will force the ShowPrefix alignment flag when a buddy is assigned,
      no matter what flags are passed to QLabel::setAlignment }
  end;
end;

procedure TCustomLabel.SetLayout(const Value: TTextLayout);
const
  LayoutFlags: array[TTextLayout] of Integer =
    (Integer(AlignmentFlags_AlignTop), Integer(AlignmentFlags_AlignVCenter),
     Integer(AlignmentFlags_AlignBottom));
var
  AlignFlags: Word;
begin
  if Layout <> Value then
  begin;
    AlignFlags := QLabel_alignment(Handle);
    AlignFlags := AlignFlags and AlignmentFlags_LayoutMask;
    QLabel_setAlignment(Handle, AlignFlags or LayoutFlags[Value]);
  end;
end;

procedure TCustomLabel.SetWordWrap(const Value: Boolean);
const
  WordWrapFlags: array[Boolean] of Integer = (0, Integer(AlignmentFlags_WordBreak));
var
  Flags: Word;
begin
  if WordWrap = Value then Exit;
  Flags := QLabel_alignment(Handle) and ($FFFF - Integer(AlignmentFlags_WordBreak));
  QLabel_setAlignment(Handle, Flags or WordWrapFlags[Value]);
end;

function EditCharCaseHandler(Event: QKeyEventH; CharCase: TEditCharCase; Handle: QLineEditH): Boolean;
var
  KeyEvent: QKeyEventH;
  Key: Integer;
  KeyText: WideString;
  Offset: Integer;
  S : WideString;
begin
  Result := False;
  if Handle = nil then Exit;
  Offset := 0;
  Key := QKeyEvent_ascii(Event);
  if Key = 0 then
  begin
    QKeyEvent_text(Event, @S);
    if Length(S) = 0 then Exit;
    case CharCase of
      ecLowerCase:
	KeyText := WideLowerCase(S);
      ecUpperCase:
	KeyText := WideUpperCase(S);
    end;
    if WideSameStr(KeyText, S) then Exit;
  end
  else
  begin
    case CharCase of
      ecLowerCase:
        if Key in [$41..$5A, Key_AGrave..Key_THORN] then
          Offset := $20
        else Exit;
      ecUpperCase:
        if (Key in [Key_AGrave_lower..Key_THORN_lower])
        or (Key in [$61..$7A]) then
          Offset := -$20
        else Exit;
    end;
    Key := Key + Offset;
    KeyText := Chr(Key);
  end;
  KeyEvent := QKeyEvent_create(QEventType_KeyPress, Key, Key,
    Integer(ButtonState_NoButton), PWideString(@KeyText), False, 1);
  QApplication_sendEvent(Handle, KeyEvent);
  Result := True;
end;

function TCustomLabel.GetTransparent: Boolean;
begin
  Result := Masked;
end;

procedure TCustomLabel.SetTransparent(const Value: Boolean);
begin
  Masked := Value;
end;

function TCustomLabel.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  if IsAccel(Key, Caption) and Assigned(FocusControl) then
  begin
    FocusControl.SetFocus;
    Result := True;
  end else
    Result := inherited WantKey(Key, Shift, KeyText);
end;

{ TCustomEdit }

procedure TCustomEdit.Clear;
begin
  QLineEdit_clear(Handle);
end;

procedure TCustomEdit.ClearSelection;
begin
  QClxLineEdit_clearSelection(Handle);
end;

procedure TCustomEdit.CopyToClipboard;
begin
  QLineEdit_copy(Handle);
end;

constructor TCustomEdit.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Palette.ColorRole := crBase;
  Palette.TextColorRole := crText;
  FAutoSize := True;
  FMaxLength := -1;
  FCharCase := ecNormal;
  FHideSelection := True;
  ParentColor := False;
  TabStop := True;
  InputKeys := [ikChars, ikEdit, ikArrows];
end;

procedure TCustomEdit.CreateWidget;
begin
  FHandle := QClxLineEdit_create(ParentWidget, nil);
  Hooks := QLineEdit_hook_create(Handle);
end;

procedure TCustomEdit.CutToClipboard;
begin
  QLineEdit_cut(Handle);
end;

procedure TCustomEdit.TextChangedHook(Text: PWideString);
begin
  try
    QClxLineEdit_resetSelection(Handle);
    Modified := True;
    Change;
  except
    Application.HandleException(Self);
  end;
end;

function TCustomEdit.GetAlignment: TAlignment;
begin
  Result := QAlignmentToTAlignment(QLineEdit_alignment(Handle));
end;

function TCustomEdit.GetBorderStyle: TControlBorderStyle;
begin
  if QLineEdit_frame(Handle) then
    Result := bsSingle
  else
    Result := bsNone;
end;

function TCustomEdit.GetEchoMode: TEchoMode;
begin
  Result := TEchoMode(QLineEdit_echoMode(Handle));
end;

function TCustomEdit.GetModified: Boolean;
begin
  Result := QLineEdit_edited(Handle);
end;

function TCustomEdit.GetSelLength: Integer;
begin
  Result := Length(SelText);
end;

function TCustomEdit.GetSelStart: Integer;
begin
  Result := QClxLineEdit_selStart(Handle);
end;

function TCustomEdit.GetSelText: WideString;
begin
  QClxLineEdit_markedText(Handle, PWideString(@Result));
end;

function TCustomEdit.GetSelTextBuf(Buffer: PChar; BufSize: Integer): Integer;
var
  ASelText: AnsiString;
begin
  { Provided for compatibility. Causes unnecessary copying and a Unicode
    to MBCS translation }
  ASelText := SelText;
  StrLCopy(Buffer, PChar(Pointer(ASelText)), BufSize - 1);
  Result := StrLen(Buffer);
end;

function TCustomEdit.GetText: TCaption;
begin
  QLineEdit_text(Handle, PWideString(@Result));
end;

procedure TCustomEdit.PasteFromClipboard;
var
  WValue: WideString;
begin
  if not ReadOnly then
  begin
    WValue := Clipboard.AsText;
    if CharCase = ecUpperCase then
      WValue := WideUpperCase(WValue)
    else if CharCase = ecLowerCase then
      WValue := WideLowerCase(WValue);
    QLineEdit_insert(Handle, PWideString(@WValue));
    QClxLineEdit_resetSelection(Handle);
  end;
end;

procedure TCustomEdit.SelectAll;
begin
  QLineEdit_selectAll(Handle);
end;

procedure TCustomEdit.SetAlignment(const Value: TAlignment);
begin
  if Value <> Alignment then QLineEdit_setAlignment(Handle, AlignmentFlags[Value]);
end;

procedure TCustomEdit.SetBorderStyle(const Value: TControlBorderStyle);
begin
  if BorderStyle <> Value then QLineEdit_setFrame(Handle, Boolean(Value));
end;

procedure TCustomEdit.SetEchoMode(const Value: TEchoMode);
begin
  if EchoMode <> Value then QLineEdit_setEchoMode(Handle, QLineEditEchoMode(Value));
end;

procedure TCustomEdit.SetMaxLength(const Value: Integer);
begin
  if FMaxLength <> Value then
  begin
    if Value < 0 then
    begin
      FMaxLength := -1;
      QLineEdit_setMaxLength(Handle, 32767);
    end
    else begin
      FMaxLength := Value;
      QLineEdit_setMaxLength(Handle, FMaxLength);
    end;
  end;
end;

procedure TCustomEdit.SetModified(const Value: Boolean);
begin
  if Modified <> Value then QLineEdit_setEdited(Handle, Value);
end;

procedure TCustomEdit.SetOnReturnPressed(const Value: TNotifyEvent);
var
  Method: TMethod;
begin
  FOnReturnPressed := Value;
  if Assigned(FOnReturnPressed) then
    QLineEdit_returnPressed_Event(Method) := ReturnPressedHook
  else
    Method := NullHook;
  QLineEdit_hook_hook_returnPressed(QLineEdit_hookH(Hooks), Method);
end;

procedure TCustomEdit.SetSelLength(Value: Integer);
begin
  { Workaround for Qt bug when SelLength < 0 and SelStart < Abs(SelLength) }
  if SelStart + Value < 0 then Value := -SelStart;
  QClxLineEdit_setSelection(Handle, SelStart, Value);
  Invalidate;
end;

procedure TCustomEdit.SetSelStart(Value: Integer);
begin
  if SelStart <> Value then
    QClxLineEdit_setSelStart(Handle, Value);
end;

procedure TCustomEdit.SetSelText(const Value: WideString);
begin                     
  QClxLineEdit_setMarkedText(Handle, PWideString(@Value));
end;

procedure TCustomEdit.SetSelTextBuf(Buffer: PChar);
begin
  SetSelText(Buffer);
end;

procedure TCustomEdit.SetText(const Value: TCaption);
begin
  if Text <> Value then
  begin
    QLineEdit_setText(Handle, PWideString(@Value));
    QClxLineEdit_resetSelection(Handle);
    TextChanged;
  end;
end;

procedure TCustomEdit.UpdateHeight;
begin
  if AutoSize then SetBounds(Left, Top, Width, FontHeight);
end;

function TCustomEdit.GetHandle: QClxLineEditH;
begin
  HandleNeeded;
  Result := QClxLineEditH(FHandle);
end;

procedure TCustomEdit.Change;
begin
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure TCustomEdit.ReturnPressedHook;
begin
  if Assigned(FOnReturnPressed) then
  try
    FOnReturnPressed(Self);
  except
    Application.HandleException(Self);
  end;
end;

function TCustomEdit.GetAutoSelect: Boolean;
begin
  Result := QClxLineEdit_autoSelect(Handle);
end;

procedure TCustomEdit.SetAutoSelect(const Value: Boolean);
begin
  if AutoSelect <> Value then
    QClxLineEdit_setAutoSelect(Handle, Value);
end;

function TCustomEdit.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;

  procedure ForwardEvent;
  begin
    FIgnoreEvents := True;
    try
      QApplication_sendEvent(Sender, Event);
      inherited EventFilter(Sender, Event);
      Result := True;
    finally
      FIgnoreEvents := False;
    end;
  end;

var
  Key: Integer;
  ShiftState: TShiftState;
begin
  if FIgnoreEvents then
  begin
    Result := False;
    Exit;
  end;

  case QEvent_type(Event) of
    QEventType_mouseButtonPress:
      if QMouseEvent_button(QMouseEventH(Event)) = ButtonState_RightButton then
        Result := inherited EventFilter(Sender, Event)
      else begin
        ForwardEvent;
        Exit;
      end;
    QEventType_mouseButtonRelease,
    QEventType_keyRelease:
      begin
        Key := QKeyEvent_key(QKeyEventH(Event));
        if (Key <> Key_Tab) and (Key <> Key_Backtab) then
        ForwardEvent;
      end;
    QEventType_keyPress:
      begin
        if not (csDesigning in ComponentState) then
        begin
          Result := False;
          Key := QKeyEvent_key(QKeyEventH(Event));
          ShiftState := ButtonStateToShiftState(QKeyEvent_state(QKeyEventH(Event)));
          if (ShiftState = [ssCtrl]) then
          begin
            case Key of
              Key_V:
                PasteFromClipboard;
              Key_X:
                CutToClipboard;
              Key_C
              {$IFDEF MSWINDOWS}
              , Key_Insert
              {$ENDIF}
                : CopyToClipboard;
            end;
           Result := (Key in [Key_V, Key_X, Key_C])
             {$IFDEF MSWINDOWS} or (Key = Key_Insert) {$ENDIF};
          end;

          if (ShiftState = [ssShift]) then
          case Key of
            Key_Insert:
              begin
                PasteFromClipboard;
                Result := True;
              end;
            Key_Delete:
              begin
                CutToClipboard;
                Result := True;
            end;
          end;

          if not Result and (CharCase <> ecNormal) then
            Result := EditCharCaseHandler(QKeyEventH(Event), CharCase, Handle);
          if not Result then Result := inherited EventFilter(Sender, Event);
        end
      end;
  else
    Result := inherited EventFilter(Sender, Event);
  end;
end;

function TCustomEdit.FontHeight: Integer;
var
  FM: QFontMetricsH;
begin
  FM := QFontMetrics_create(Font.Handle);
  try
    QWidget_FontMetrics(Handle, FM);
    Result := QFontMetrics_height(FM) + 8;
  finally
    QFontMetrics_destroy(FM);
  end;
end;
                       
procedure TCustomEdit.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  QLineEdit_textChanged_Event(Method) := TextChangedHook;
  QLineEdit_hook_hook_textChanged(QLineEdit_hookH(Hooks), Method);
end;

procedure TCustomEdit.InitWidget;
begin
  inherited InitWidget;
  AutoSelect := True;
  SelStart := 0;
  UpdateHeight;
end;

procedure TCustomEdit.KeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited KeyDown(Key, Shift);
  if (Shift - [ssCtrl, ssAlt] = Shift) and (Key >= $20) and (Key <= $FF)
  and ((MaxLength > -1) and (Length(Text) >= MaxLength) and (SelLength = 0)) then
  begin
    Key := 0;
    Beep;
  end;
end;

procedure TCustomEdit.Loaded;
begin
  inherited Loaded;
  UpdateHeight;
  QLineEdit_setEdited(Handle, False);
end;

function TCustomEdit.GetReadOnly: Boolean;
begin
  Result := QLineEdit_isReadOnly(Handle);
end;

procedure TCustomEdit.SetReadOnly(const Value: Boolean);
begin
  if ReadOnly <> Value then
    QLineEdit_setReadOnly(Handle, Value);
end;

procedure TCustomEdit.SetAutoSize(const Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    UpdateHeight;
  end;
end;

procedure TCustomEdit.SetHideSelection(const Value: Boolean);
begin
  if HideSelection <> Value then
  begin
    FHideSelection := Value;
    QClxLineEdit_setHideSelection(Handle, Value);
  end;
end;

procedure TCustomEdit.FontChanged;
begin
  inherited FontChanged;
  UpdateHeight;
end;

{ TButtonControl }

function TButtonControl.AccelChar: Char;
begin
  Result := FAccelChar;
end;

procedure TButtonControl.AnimateClick;
begin
  QButton_animateClick(Handle);
  Click;
end;

constructor TButtonControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Palette.ColorRole := crButton;
  Palette.TextColorRole := crButtonText;
end;

function TButtonControl.GetAutoRepeat: Boolean;
begin
  Result := QButton_autoRepeat(Handle);
end;

function TButtonControl.GetChecked: Boolean;
begin
  Result := False;
end;

function TButtonControl.GetDown: Boolean;
begin
  if IsToggleButton then
    Result := State = tsOn
  else
    Result := QButton_isDown(Handle);
end;

function TButtonControl.GetState: TToggleState;
begin
  Result := TToggleState(QButton_state(Handle));
end;

function TButtonControl.GetText: TCaption;
begin
  QButton_text(Handle, PWideString(@Result));
end;

procedure TButtonControl.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  QButton_stateChanged_Event(Method) := StateChangedHook;
  QButton_hook_hook_stateChanged(QButton_hookH(Hooks), Method);
end;

function TButtonControl.IsCheckedStored: Boolean;
begin
  Result := (ActionLink = nil) or not TButtonActionLink(ActionLink).IsCheckedLinked;
end;

procedure TButtonControl.SetAutoRepeat(const Value: Boolean);
begin
  if AutoRepeat <> Value then QButton_setAutoRepeat(Handle, Value);
end;

procedure TButtonControl.SetChecked(Value: Boolean);
begin
end;

procedure TButtonControl.SetDown(const Value: Boolean);
begin
  if (Down <> Value) and IsToggleButton then
  begin
    if ((State = tsOff) and Value) or ((State = tsOn) and not Value) then
      QButton_toggle(Handle)
  end;
end;

procedure TButtonControl.SetText(const Value: TCaption);
begin
  if Caption <> Value then
  begin
    QButton_setText(Handle, PWideString(@Value));
    FAccelChar := Char(QButton_accel(Handle));
    QButton_setAccel(Handle, 0);
    TextChanged;
  end;
end;

procedure TButtonControl.StateChangedHook(State: Integer);
begin
  try
    StateChanged(TToggleState(State));
  except
    Application.HandleException(Self);
  end;
end;

procedure TButtonControl.Toggle;
begin
  QButton_toggle(Handle);
end;

function TButtonControl.GetHandle: QButtonH;
begin
  HandleNeeded;
  Result := QButtonH(FHandle);
end;

procedure TButtonControl.ActionChange(Sender: TObject; CheckDefaults: Boolean);
begin
  inherited ActionChange(Sender, CheckDefaults);
  if Sender is TCustomAction then
    with TCustomAction(Sender) do
    begin
      if not CheckDefaults or (Self.Checked = False) then
        Self.Checked := Checked;
    end;
end;

function TButtonControl.GetActionLinkClass: TControlActionLinkClass;
begin
  Result := TButtonActionLink;
end;

procedure TButtonControl.StateChanged(State: TToggleState);
begin
  if Assigned(FOnStateChanged) then FOnStateChanged(Self, State);
end;

function TButtonControl.IsToggleButton: Boolean;
begin
  Result := QButton_isToggleButton(Handle);
end;

function TButtonControl.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  Result := IsAccel(Key, Caption) and Enabled;
  if Result then Click else
    Result := inherited WantKey(Key, Shift, KeyText);
end;

{ TButton }

procedure TButton.BeginAutoDrag;
begin
  BeginDrag(False, Mouse.DragThreshold);
end;

procedure TButton.Click;
var
  Form: TCustomForm;
begin
  Form := GetParentForm(Self);
  if Form <> nil then Form.ModalResult := ModalResult;
  inherited Click;
end;

procedure TButton.CreateWidget;
begin
  FHandle := QPushButton_create(ParentWidget, nil);
  Hooks := QButton_hook_create(Handle);
end;

function TButton.GetHandle: QPushButtonH;
begin
  HandleNeeded;
  Result := QPushButtonH(FHandle);
end;

function TButton.GetToggleButton: Boolean;
begin
  Result := QButton_isToggleButton(Handle);
end;

procedure TButton.KeyUp(var Key: Word; Shift: TShiftState);
begin
  inherited KeyUp(Key, Shift);
  if (Key = Key_Space) and (Shift - [ssAlt, ssShift] = Shift) then
    Click;
end;

function TButton.NeedKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  Result := ((Key = Key_Enter) or (Key = Key_Return)) and (Shift = []);
  if Result then Click;
end;

procedure TButton.SetDefault(const Value: Boolean);
begin
  if Default <> Value then
  begin
    FDefault := Value;
    QPushButton_setDefault(Handle, Value);
  end;
end;

procedure TButton.ToggleHook(IsToggled: Boolean);
begin
  try
    Toggled(IsToggled);
  except
    Application.HandleException(Self);
  end;
end;

procedure TButton.Toggled(IsToggled: Boolean);
begin
  if Assigned(FOnToggled) then FOnToggled(Self, IsToggled);
end;

procedure TButton.SetToggleButton(const Value: Boolean);
begin
  if ToggleButton <> Value then QPushButton_setToggleButton(Handle, Value);
end;

procedure TButton.SetOnToggled(const Value: TToggledEvent);
var
  Method: TMethod;
begin
  FOnToggled := Value;
  if Assigned(FOnToggled) then
    QButton_toggled_Event(Method) := ToggleHook
  else
    Method := NullHook;
  QButton_hook_hook_Toggled(QButton_hookH(Hooks), Method);
end;

constructor TButton.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle - [csDoubleClicks];
  ParentColor := False;
  TabStop := True;
  Width := 75;
  Height := 25;
end;

function TButton.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  case QEvent_type(Event) of
    QEventType_MouseButtonDblClick:
      if not (csDoubleClicks in ControlStyle) and not (csDesigning in ComponentState) then
      begin
        QButton_animateClick(Handle);
        Click;
        Result := True;
        Exit;
      end;
  end;
  Result := inherited EventFilter(Sender, Event);
end;

function TButton.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  Result := inherited WantKey(Key, Shift, KeyText);
  if not Result then
  begin
    if IsAccel(Key, Caption) then
    begin
      Click;
      Result := True;
    end
    else
      case Key of
        Key_Return, Key_Enter:
          begin
            Result := FDefault and Enabled and Visible;
            if Result then Click;
          end;
        Key_Escape:
          begin
            Result := FCancel and Enabled and Visible;
            if Result then Click;
          end;
      end;
  end;
end;

{ TCustomComboBox }

function TCustomComboBox.AdjustHeight: Integer;
var
  FM: QFontMetricsH;
begin
  if Style in [csOwnerDrawFixed, csOwnerDrawVariable] then
    Result := FItemHeight + 6
  else begin
    FM := QFontMetrics_create(Font.Handle);
    try
      QWidget_FontMetrics(Handle, FM);
      Result := QFontMetrics_height(FM) + 8;
    finally
      QFontMetrics_destroy(FM);
    end;
  end;
end;

procedure TCustomComboBox.Change;
begin
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure TCustomComboBox.Click;
var
  NewText: WideString;
begin
  if DroppedDown then
  begin
    if FJustDropped then
      FJustDropped := False
    else begin
      QListBox_currentText(ListBoxHandle, PWideString(@NewText));
      Text := NewText;
      SelectAll;
    end;
  end;
  inherited Click;
end;

procedure TCustomComboBox.ChangeHook(Text: PWideString);
begin
  try
    Change;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomComboBox.Clear;
begin
  FItems.Clear;
end;

constructor TCustomComboBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FItems := TComboBoxStrings.Create;
  TComboBoxStrings(FItems).FOwner := Self;
  FCanvas := TControlCanvas.Create;
  TControlCanvas(FCanvas).Control := Self;
  FStyle := csDropDown;
  FMaxItems := -1;
  Palette.ColorRole := crBase;
  Palette.TextColorRole := crText;
  FItemHeight := 16;
  Width := 140;
  ParentColor := False;
  TabStop := True;
  FMaxLength := -1;
  InputKeys := [ikChars, ikArrows, ikNav];
end;

procedure TCustomComboBox.CreateWidget;
begin
  FHandle := QOpenComboBox_create(FStyle = csDropDown, ParentWidget, nil);
  FListBoxDrawHooks := QClxListBoxHooks_create;
  Hooks := QComboBox_hook_create(Handle);
end;

procedure TCustomComboBox.CursorChanged;
begin
  inherited CursorChanged;
  if not QComboBox_editable(Handle) and (EditHandle <> nil) then
    QWidget_setCursor(EditHandle, Screen.Cursors[Cursor]);
  if ListBoxHandle <> nil then
     QWidget_setCursor(ListboxHandle, Screen.Cursors[Cursor]);
end;

procedure TCustomComboBox.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  QComboBox_textChanged_Event(Method) := ChangeHook;
  QComboBox_hook_hook_textChanged(QComboBox_hookH(Hooks), Method);
  QComboBox_activated_Event(Method) := SelectedHook;
  QComboBox_hook_hook_activated(QComboBox_hookH(Hooks), Method);
  QComboBox_highlighted_Event(Method) := HighlightedHook;
  QComboBox_hook_hook_highlighted(QComboBox_hookH(Hooks), Method);
  if Style = csOwnerDrawVariable then
    QClxListItem_measure_Event(Method) := ItemMeasureHook
  else
    Method := NullHook;
  QClxListBoxHooks_hook_measure(FListBoxDrawHooks, Method);
  QClxListItem_paint_Event(Method) := ItemPaintHook;
  QClxListBoxHooks_hook_paint(FListBoxDrawHooks, Method);
end;

destructor TCustomComboBox.Destroy;
begin
  FItems.Free;
  FCanvas.Free;
  inherited Destroy;
end;

procedure TCustomComboBox.DropDown;
begin
  QOpenComboBox_popup(Handle);
end;

function TCustomComboBox.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  if QEvent_Type(Event) = QEventType_MouseButtonRelease then
    // Ignore the click.  This only gets called if the listbox is dropped down and you
    // click on the dropdown button. All other clicks are handled by the edit control and the
    // listbox control.
    Result := False
  else
    Result := inherited EventFilter(Sender, Event);
end;

function TCustomComboBox.EditEventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  try
    if (csDesigning in ComponentState) and (QEvent_type(Event) <> QEventType_Paint) then
    begin
      { route to MainEventFilter to handle events in the designer }
      Result := MainEventFilter(Sender, Event);
      Exit;
    end;
    Result := False;
    case QEvent_type(Event) of
      QEventType_KeyPress:
        begin
          if CharCase <> ecNormal then
            Result := EditCharCaseHandler(QKeyEventH(Event), CharCase, EditHandle);
          if not Result then EventFilter(Sender, Event);
        end;
      QEventType_MouseButtonPress..QEventType_MouseMove,
      QEventType_KeyRelease..QEventType_Leave,
      QEventType_DragEnter..QEventType_DragResponse:
        Result := EventFilter(Sender, Event);
    end;
  except
    Application.HandleException(Self);
    Result := False;
  end;
end;

function TCustomComboBox.EditHandle: QLineEditH;
var
  Method: TMethod;
begin
  Result := nil;
  // When QComboBox_editable is False, there is no Edit control
  // and so this function must return nil.
  if not QComboBox_editable(Handle) then
    FEditHandle := nil
  else
  begin
    if FEditHandle = nil then
    begin
      FEditHandle := QComboBox_lineEdit(Handle);
      if FEditHandle = nil then Exit;
      if not QComboBox_editable(Handle) then
        QWidget_setCursor(FEditHandle, Screen.Cursors[Cursor]);
      QClxObjectMap_add(FEditHandle, Integer(Self));
      QWidget_setMouseTracking(FEditHandle, True);
      QWidget_setAcceptDrops(FEditHandle, True);
    end;
    if (FEditHandle <> nil) and not Assigned(FEditHook) then
    begin
      FEditHook := QLineEdit_hook_create(FEditHandle);
      TEventFilterMethod(Method) := EditEventFilter;
      Qt_hook_hook_events(FEditHook, Method);
    end;
  end;
  Result := FEditHandle;
end;

function TCustomComboBox.Focused: Boolean;
begin
  Result := QWidget_hasFocus(Handle) or ((EditHandle <> nil) and QWidget_hasFocus(EditHandle))
    or QWidget_hasFocus(ListBoxHandle);
end;

procedure TCustomComboBox.FontChanged;
begin
  inherited FontChanged;
  Height := AdjustHeight;
end;

function TCustomComboBox.GetAutoComplete: Boolean;
begin
  Result := QComboBox_autoCompletion(Handle);
end;

function TCustomComboBox.GetDropDownCount: Integer;
begin
  Result := QComboBox_sizeLimit(Handle);
end;

function TCustomComboBox.GetDuplicates: TDuplicates;
begin
  Result := TComboBoxStrings(Items).Duplicates;
end;

function TCustomComboBox.GetDroppedDown: Boolean;
begin
  Result := (ListBoxHandle <> nil) and (QWidget_isVisible(ListBoxHandle));
end;

function TCustomComboBox.GetHandle: QOpenComboBoxH;
begin
  HandleNeeded;
  Result := QOpenComboBoxH(FHandle);
end;

function TCustomComboBox.GetInsertMode: TComboBoxInsertMode;
begin
  Result := TComboBoxInsertMode(QComboBox_insertionPolicy(Handle));
end;

function TCustomComboBox.GetItemIndex: Integer;
begin
  Result := QComboBox_currentItem(Handle);
end;

function TCustomComboBox.GetSelLength: Integer;
begin
  Result := Length(GetSelText);
end;

function TCustomComboBox.GetSelStart: Integer;
begin
  if EditHandle <> nil then
    Result := QLineEdit_cursorPosition(EditHandle)
  else
    Result := -1;
end;

function TCustomComboBox.GetSelText: WideString;
begin
  if EditHandle <> nil then
    QLineEdit_markedText(EditHandle, PWideString(@Result))
  else
    Result := '';
end;

function TCustomComboBox.GetText: TCaption;
begin
  QComboBox_currentText(Handle, PWideString(@Result));
end;

procedure TCustomComboBox.HighlightedHook(Index: Integer);
begin
  try
    FJustDropped := False;
    if DroppedDown then
      Highlighted(Index);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomComboBox.InitWidget;
begin
  inherited InitWidget;
  InsertMode := ciNone;
  QComboBox_setDuplicatesEnabled(Handle, Duplicates = dupAccept);
  QComboBox_setSizeLimit(Handle, 8);
  EditHandle;
  ListBoxHandle;
  ItemIndex := -1;
end;

procedure TCustomComboBox.KeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited KeyDown(Key, Shift);
  case Key of
    Key_Return, Key_Enter:
      begin
        if (MaxItems > -1) and (Items.Count >= MaxItems) then Key := 0;
        if DroppedDown then
        begin
          Key := 0;
          CloseUp;
        end;
      end;
    Key_Escape:
      CloseUp;
  end;
end;

procedure TCustomComboBox.KeyUp(var Key: Word; Shift: TShiftState);
begin
  case Key of
    Key_Down, Key_Up, Key_PageUp, Key_PageDown, Key_End, Key_Home:
      if DroppedDown then Click;
  end;
  inherited KeyUp(Key, Shift);
end;

function TCustomComboBox.ListBoxHandle: QListBoxH;
var
  Method: TMethod;
begin
  if (FListBoxHandle = nil) then
  begin
    FListBoxHandle := QComboBox_listBox(Handle);
    if (FListBoxHandle <> nil) then
    begin
      QWidget_setCursor(FListboxHandle, Screen.Cursors[Cursor]);
      if not Assigned(FListHook) then
      begin
        FListHook := QListBox_hook_create(FListBoxHandle);
        TEventFilterMethod(Method) := ListEventFilter;
        Qt_hook_hook_events(FListHook, Method);
      end;
    end;
  end;
  Result := FListBoxHandle;
end;

procedure TCustomComboBox.Loaded;
begin
  inherited;
  Height := AdjustHeight;
end;

procedure TCustomComboBox.CMKeyDown(var Msg: TCMKeyDown);
begin
  if (InsertMode <> ciNone) and ((Msg.Key = Key_Enter)
    or (Msg.Key = Key_Return)) then
    Exit
  else
    inherited;
end;

procedure TCustomComboBox.PaletteChanged(Sender: TObject);
begin
  inherited PaletteChanged(Sender);
  if EditHandle <> nil then
    QWidget_setPalette(EditHandle, (Sender as TPalette).Handle, True);
  if ListBoxHandle <> nil then
    QWidget_setPalette(ListBoxHandle, (Sender as TPalette).Handle, True);
end;

procedure TCustomComboBox.SelectedHook(Index: Integer);
begin
  try
    Click;
    if Style <> csDropDown then Change;
    Select;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomComboBox.Select;
begin
  if Assigned(FOnSelect) then FOnSelect(Self);
end;

procedure TCustomComboBox.SetAutoComplete(const Value: Boolean);
begin
  if AutoComplete <> Value then QComboBox_setAutoCompletion(Handle, Value);
end;

procedure TCustomComboBox.SetDropDownCount(const Value: Integer);
begin
  if DropDownCount <> Value then QComboBox_setSizeLimit(Handle, Value);
end;

procedure TCustomComboBox.SetDuplicates(const Value: TDuplicates);
begin
  TComboBoxStrings(Items).Duplicates := Value;
end;

procedure TCustomComboBox.SetInsertMode(const Value: TComboBoxInsertMode);
begin
  if InsertMode <> Value then
    QComboBox_setInsertionPolicy(Handle, QComboBoxPolicy(Value));
end;

procedure TCustomComboBox.SetDroppedDown(const Value: Boolean);
begin
  if Value <> GetDroppedDown then DropDown else CloseUp;
end;

procedure TCustomComboBox.SetItemIndex(const Value: Integer);
begin
  QComboBox_setCurrentItem(Handle, Value);
end;

procedure TCustomComboBox.SetItems(const Value: TStrings);
begin
  FItems.Assign(Value);
end;

procedure TCustomComboBox.SetMaxItems(const Value: Integer);
begin
  if MaxItems <> Value then
  begin
    FMaxItems := Value;
    if Value >= 0 then
      QComboBox_setMaxCount(Handle, FMaxItems)
    else
      QComboBox_setMaxCount(Handle, MaxInt);
  end;
end;

procedure TCustomComboBox.SetMaxLength(const Value: Integer);
begin
  if FMaxLength <> Value then
  begin
    if Value < 0 then
      FMaxLength := -1
    else
      FMaxLength := Value;
    if EditHandle <> nil then
    begin
      if FMaxLength > -1 then
        QLineEdit_setMaxLength(EditHandle, FMaxLength)
      else
        QLineEdit_setMaxLength(EditHandle, MaxInt);
    end;
  end;
end;

procedure TCustomComboBox.SetSelLength(const Value: Integer);
begin
  if EditHandle <> nil then
    QLineEdit_setSelection(EditHandle, SelStart, Value);
end;

procedure TCustomComboBox.SetSelStart(const Value: Integer);
begin
  if EditHandle <> nil then
    QLineEdit_setCursorPosition(EditHandle, Value);
end;

procedure TCustomComboBox.SetSelText(const Value: WideString);
begin
  //Note the QComboBox's hosted QLineEdit does not preserve its
  //own selection state when focus leaves; this routine will
  //not replace selected text in a QComboBox without focus.
  if EditHandle <> nil then
    if Value <> '' then
      QLineEdit_insert(EditHandle, PWideString(@Value))
    else
      //QLineEdit also won't replace marked text with an empty string.
      if QLineEdit_hasMarkedText(EditHandle) then
        QLineEdit_del(EditHandle);
end;

procedure TCustomComboBox.SetStyle(Value: TComboBoxStyle);
var
  Method: TMethod;
begin
  if FStyle <> Value then
  begin
    FStyle := Value;
    RecreateWidget;
    Height := AdjustHeight;
    if FStyle = csDropDownList then
      InputKeys := InputKeys - [ikEdit]
    else
      InputKeys := InputKeys + [ikEdit];
    case FStyle of
      csDropDown, csDropDownList:
        begin
          Method := NullHook;
          QClxListBoxHooks_hook_paint(FListBoxDrawHooks, Method);
        end;
      csOwnerDrawFixed, csOwnerDrawVariable:
        begin
          QClxListItem_paint_Event(Method) := ItemPaintHook;
          QClxListBoxHooks_hook_paint(FListBoxDrawHooks, Method);
        end;
    end;
  end;
end;

procedure TCustomComboBox.DestroyWidget;
begin
  if Assigned(FEditHook) then
    QLineEdit_hook_destroy(FEditHook);
  if Assigned(FListHook) then
    QListBox_hook_destroy(FListHook);
  if Assigned(FEditHandle) then
    QClxObjectMap_remove(FEditHandle);
  FEditHook := nil;
  FListHook := nil;
  FListBoxDrawHooks := nil;
  FEditHandle := nil;
  FListBoxHandle := nil;
  inherited DestroyWidget;
end;

procedure TCustomComboBox.SelectAll;
begin
  if EditHandle <> nil then
    QLineEdit_selectAll(EditHandle);
end;

procedure TCustomComboBox.SetText(const Value: TCaption);
var
  ValueIndex: integer;
begin
  if Text <> Value then
  begin
    ValueIndex := Items.IndexOf(Value);
    if ValueIndex > 0 then
    begin
      QComboBox_setCurrentItem(Handle, ValueIndex);
    end else
    begin
      QComboBox_setEditText(Handle, @Value);
    end;
    TextChanged;
  end;
end;

procedure TCustomComboBox.RestoreWidgetState;
begin
  inherited RestoreWidgetState;
  if FMemStream <> nil then
  begin
    FMemStream.Position := 0;
    FMemStream.ReadComponent(Self);
    FreeAndNil(FMemStream);
  end;
end;

procedure TCustomComboBox.SaveWidgetState;
begin
  inherited SaveWidgetState;
  FMemStream := TMemoryStream.Create;
  FMemStream.WriteComponent(Self);
end;

procedure TCustomComboBox.Highlighted(Index: Integer);
begin
  if Assigned(FOnHighlighted) then FOnHighlighted(Self, Index);
end;

procedure TCustomComboBox.ItemMeasureHook(index: Integer;
  var height, width: Integer);
begin
  if FStyle in [csOwnerDrawVariable] then
  try
    height := FItemHeight;
    MeasureItem(Self, index, height, width);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomComboBox.ItemPaintHook(listBox: QListBoxH; p: QPainterH;
  Index: Integer; Rect: PRect; Flags: Integer; var Handled: Boolean);
var
  State: TOwnerDrawState;
begin
  try
    Handled := Style in [csOwnerDrawFixed, csOwnerDrawVariable];
    if not Handled then Exit;
    State := [];
    FCanvas.Handle := p;
    FCanvas.Start(False);
    FCanvas.Font := Font;
    if Boolean(Flags and ClxListBoxItem_Selected) then
    begin
      Include(State, odSelected);
      FCanvas.Brush.Color := clHighlight;
      FCanvas.Font.Color := clHighlightText;
    end
    else begin
      FCanvas.Brush.Color := Color;
      FCanvas.Font.Color := clWindowText;
    end;
    if Boolean(Flags and ClxListBoxItem_Grayed) then
    begin
      Include(State, odGrayed);
      FCanvas.Font.Color := clGrayText;
    end;
    if Boolean(Flags and ClxListBoxItem_Focused) then
      Include(State, odFocused);
    if Boolean(Flags and ClxListBoxItem_Selected) then Include(State, odSelected);
    if Boolean(Flags and ClxListBoxItem_Grayed) then Include(State, odGrayed);
    if Boolean(Flags and ClxListBoxItem_Focused) then Include(State, odFocused);
    QPainter_translate(FCanvas.Handle, -Rect.Left, -Rect.Top);
    try
      Handled := DrawItem(Index, Rect^, State);
    finally
      QPainter_translate(FCanvas.Handle, Rect.Left, Rect.Top);
    end;
    FCanvas.Stop;
    FCanvas.Handle := nil;
  except
    Application.HandleException(Self);
  end;
end;

function TCustomComboBox.DrawItem(Index: Integer; Rect: TRect;
  State: TOwnerDrawState): Boolean;
begin
  Result := Assigned(FOnDrawItem);
  if Result then
  begin
    if odSelected in State then
    begin
      Canvas.Brush.Color := clHighlight;
      Canvas.FillRect(Rect);
    end;
    FOnDrawItem(Self, Index, Rect, State, Result);
  end
end;

procedure TCustomComboBox.DoEnter;
begin
  if EditHandle <> nil then
    SelectAll;
  inherited DoEnter;
end;

procedure TCustomComboBox.DoExit;
begin
  if (Style <> csDropDownList) and (EditHandle <> nil) then
    QLineEdit_deselect(EditHandle);
  inherited DoExit;
end;

procedure TCustomComboBox.MeasureItem(Control: TWinControl;
  Index: Integer; var Height, Width: Integer);
begin
  if Assigned(FOnMeasureItem) then FOnMeasureItem(Control, Index, Height);
end;

procedure TCustomComboBox.SetSorted(const Value: Boolean);
begin
  if Sorted <> Value then
    TComboBoxStrings(FItems).Sorted := Value;
end;

procedure TCustomComboBox.Sort;
begin
  TComboBoxStrings(Items).Sort;
end;

function TCustomComboBox.GetSorted: Boolean;
begin
  Result := TComboBoxStrings(FItems).Sorted;
end;

procedure TCustomComboBox.SetItemHeight(const Value: Integer);
begin
  if FItemHeight <> Value then
  begin
    FItemHeight := Value;
    RecreateWidget;
    Height := AdjustHeight;
  end;
end;

function TCustomCombobox.GetItemHeight: integer;
begin
  if FStyle in [csOwnerDrawFixed, csOwnerDrawVariable] then
    Result := FItemHeight
  else
    // The choice of 6 in the statement below is based of the value in AdjustHeight
    Result := AdjustHeight - 6;
end;

function TCustomComboBox.ListEventFilter(Sender: QObjectH;
  Event: QEventH): Boolean;

  function IsNavKey(aKey: Word): Boolean;
  begin
    case aKey of
      Key_Down, Key_Up, Key_PageUp, Key_PageDown, Key_End, Key_Home:
        Result := True;
    else
      Result := False;
    end;
  end;

var
  Key: Word;
  ShiftState: TShiftState;
begin
  Result := False;
  try
    if (csDesigning in ComponentState) then
    begin
      { route to MainEventFilter to handle events in the designer }
      Result := MainEventFilter(Sender, Event);
      Exit;
    end;
    case QEvent_type(Event) of
      QEventType_ApplicationPaletteChange,
      QEventType_ParentPaletteChange:
        Result := EventFilter(Sender, Event);
      QEventType_hide: DoCloseUp;
      QEventType_show:
        begin
          FJustDropped := True;
          DoDropDown;
        end;
      QEventType_KeyPress:
        begin
          Key := QKeyEvent_Key(QKeyEventH(Event));
          if IsNavKey(Key) then
          begin
            Result := EventFilter(Sender, Event);
            if Style <> csDropDown then Change;
            Exit;
          end;
          if EditHandle <> nil then
          begin
            QWidget_SetFocus(EditHandle);
            QListBox_ClearSelection(ListBoxHandle);
            if not ((QKeyEvent_key(QKeyEventH(Event)) = Key_Return) or
              (QKeyEvent_key(QKeyEventH(Event)) = Key_Enter)) then
            QApplication_SendEvent(EditHandle, Event);
          end;
        end;
      QEventType_KeyRelease:
        begin
          Key := QKeyEvent_Key(QKeyEventH(Event));
          ShiftState := ButtonStateToShiftState(QKeyEvent_State(QKeyEventH(Event)));
          KeyUp(Key, ShiftState);
        end;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomComboBox.DoCloseUp;
begin
  FJustDropped := False;
  if Assigned(FOnCloseUp) then FOnCloseUp(Self);
end;

procedure TCustomComboBox.CloseUp;
begin
  QWidget_hide(ListBoxHandle);
end;

procedure TCustomComboBox.DoDropDown;
var
  Size: TSize;
  I: Integer;
begin
  if Assigned(FOnDropDown) then FOnDropDown(Self);
  QListBox_sizeHint(ListBoxHandle, @Size);
  Size.cx := Width;
    if Items.Count > DropDownCount then
      I := DropDownCount
    else
      I := Items.Count;
    Size.cy := I * ItemHeight;
  Inc(Size.cy, QFrame_frameWidth(ListBoxHandle) * 2);
  QWidget_resize(ListBoxHandle, @Size);
  if Items.IndexOf(Text) < 0 then
    QListbox_clearSelection(ListBoxHandle);
  Application.CancelHint;
end;

procedure TCustomComboBox.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  AHeight := AdjustHeight;
  inherited SetBounds(ALeft, ATop, AWidth, AHeight);
end;

{ TCustomCheckBox }

constructor TCustomCheckBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Palette.TextColorRole := crForeground;
  Palette.ColorRole := crBackground;
  TabStop := True;
  ControlStyle := ControlStyle - [csClickEvents];
end;

procedure TCustomCheckBox.CreateWidget;
begin
  FHandle := QCheckBox_create(ParentWidget, nil);
  Hooks := QButton_hook_create(Handle);
end;

function TCustomCheckBox.GetChecked: Boolean;
begin
  Result := QCheckBox_isChecked(Handle);
end;

function TCustomCheckBox.GetHandle: QCheckBoxH;
begin
  HandleNeeded;
  Result := QCheckBoxH(FHandle);
end;

procedure TCustomCheckBox.SetAllowGrayed(const Value: Boolean);
begin
  if FAllowGrayed <> Value then
  begin
    FAllowGrayed := Value;
    QCheckBox_setTriState(Handle, Value);
    if State = cbGrayed then
      QCheckBox_setNoChange(Handle);
  end;
end;

procedure TCustomCheckBox.SetChecked(Value: Boolean);
begin
  if Value then State := cbChecked else State := cbUnchecked;
end;

procedure TCustomCheckBox.SetState(Value: TCheckBoxState);
begin
  if FState <> Value then
  begin
    FState := Value;
    case Value of
      cbChecked: QCheckBox_setChecked(Handle, True);
      cbUnChecked: QCheckBox_setChecked(Handle, False);
      cbGrayed: if FAllowGrayed then QCheckBox_setNoChange(Handle);
    end;
  end;
end;

procedure TCustomCheckBox.StateChanged(State: TToggleState);
begin
  case State of
    tsOff: FState := cbUnchecked;
    tsNoChange: FState := cbGrayed;
    tsOn: FState := cbChecked;
  end;
  inherited StateChanged(State);
  Click;
end;

procedure TCustomCheckBox.Toggle;
begin
  case State of
    cbUnchecked:
      if AllowGrayed then State := cbGrayed else State := cbChecked;
    cbGrayed: State := cbChecked;
    cbChecked: State := cbUnchecked;
  end;
end;

function TCustomCheckBox.WantKey(Key: Integer;
  Shift: TShiftState; const KeyText: WideString): Boolean;
begin
  if IsAccel(Key, Caption) and CanFocus then
  begin
    SetFocus;
    if Focused then Toggle;
    Result := True;
  end else
    Result := inherited WantKey(Key, Shift, KeyText);
end;

{ TCustomListBox }

type
  TSelectionMode = (qsmSingle, qsmMulti, qsmExtended);
const
  SelectionFlags: array[Boolean, Boolean] of TSelectionMode =
    ((qsmSingle, qsmSingle), (qsmMulti, qsmExtended));

procedure TCustomListBox.Clear;
begin
  FItems.Clear;
  QListBox_clear(Handle);
end;

procedure TCustomListBox.ClearSelection;
begin
  QListBox_clearSelection(Handle);
end;

constructor TCustomListBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FStyle := lbStandard;
  FDrawHooks := QClxListBoxHooks_create;
  FItems := TListBoxStrings.Create;
  FDeleting := False;
  TListBoxStrings(FItems).FOwner := Self;
  FCanvas := TControlCanvas.Create;
  TControlCanvas(FCanvas).Control := Self;
  Palette.ColorRole := crBase;
  Palette.TextColorRole := crText;
  ExtendedSelect := True;
  Width := 121;
  Height := 97;
  FItemHeight := 16;
  ParentColor := False;
  TabStop := True;
  InputKeys := [ikChars, ikArrows, ikNav];
end;

function TCustomListBox.GetChildHandle: QWidgetH;
begin
  Result := FViewportHandle;
end;

procedure TCustomListBox.Changed;
begin
end;

procedure TCustomListBox.CreateWidget;
begin
  FHandle := QListBox_create(ParentWidget, nil, 0);
  Hooks := QListBox_hook_create(Handle);
  FViewportHook := QWidget_hook_create(QScrollView_viewport(Handle));
end;

destructor TCustomListBox.Destroy;
begin
  FItems.Free;
  FCanvas.Free;
  QClxListBoxHooks_destroy(FDrawHooks);
  inherited Destroy;
end;

procedure TCustomListBox.DblClick;
var
  MousePos: TPoint;
begin
  MousePos := ScreenToClient(Mouse.CursorPos);
  if ItemAtPos(MousePos, True) > -1 then
    inherited DblClick;
end;

procedure TCustomListBox.DrawEmptyFocus;
begin
  if (Items.Count = 0) and Focused then
    FCanvas.DrawFocusRect(Rect(0, 0, ClientWidth - QFrame_frameWidth(Handle)*2,
      ItemHeight));
end;

procedure TCustomListBox.EnabledChanged;
begin
  inherited EnabledChanged;
  //Force Qt to use the correct brush for disabled painting.
  ColorChanged;
  Repaint;
end;

function TCustomListBox.GetColumnLayout: TListBoxLayout;
begin
  Result := TListBoxLayout(QListBox_columnMode(Handle));
end;

function TCustomListBox.GetColumns: Integer;
begin
  Result := QListBox_numColumns(Handle);
end;

function TCustomListBox.GetHandle: QListBoxH;
begin
  HandleNeeded;
  Result := QListBoxH(FHandle);
end;

function TCustomListBox.GetItemIndex: Integer;
begin
  Result := QListBox_currentItem(Handle);
  if not QListBox_isSelected(Handle, QListBox_item(Handle, Result))
    then Result := -1;
end;

function TCustomListBox.GetRowLayout: TListBoxLayout;
begin
  Result := TListBoxLayout(QListBox_rowMode(Handle));
end;

function TCustomListBox.GetRows: Integer;
begin
  Result := QListBox_numRows(Handle);
end;

function TCustomListBox.GetSelCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  I := 0;
  while (I < Items.Count) do
  begin
    if Selected[I] then Inc(Result);
    Inc(I);
  end;
end;

function TCustomListBox.GetSelected(Index: Integer): Boolean;
begin
  if (Index < 0) or (Index >= Items.Count) then
    TList.Error(SListIndexError, Index);
  Result := QListBox_isSelected(Handle, Index);
end;

function TCustomListBox.GetTopIndex: Integer;
begin
  Result := QListBox_topItem(Handle);
end;

function TCustomListBox.ItemAtPos(Pos: TPoint; Existing: Boolean): Integer;
var
  P: TPoint;
begin
  P := Types.TPoint(Point(Pos.X, Pos.Y));
  Result := QListBox_index(Handle, QListBox_itemAt(Handle, @P));
  if (Result = -1) and not Existing then Result := Items.Count;
end;

function TCustomListBox.ItemRect(Index: Integer): TRect;
var
  Item: QListBoxItemH;
begin
  Item := QListBox_item(Handle, Index);
  QListBox_itemRect(Handle, @Result, Item);
end;

function TCustomListBox.ItemVisible(Index: Integer): Boolean;
begin
  Result := QListBox_itemVisible(Handle, Index);
end;

procedure TCustomListBox.Loaded;
begin
  inherited Loaded;
  //Force QListBox to have at least one column. Qt doesn't.
  QListBox_setColumnMode(Handle, Columns);
end;

procedure TCustomListBox.MakeCurrentVisible;
begin
  QListBox_ensureCurrentVisible(Handle);
end;

procedure TCustomListBox.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  inherited SetBounds(ALeft, ATop, AWidth, AHeight);
  QListBox_triggerUpdate(Handle, True);
end;

procedure TCustomListBox.SetColumnLayout(const Value: TListBoxLayout);
begin
  if ColumnLayout <> Value then
    QListBox_setColumnMode(Handle, QListBoxLayoutMode(Value));
end;

procedure TCustomListBox.SetColumns(const Value: Integer);
begin
  if Columns <> Value then
    QListBox_setColumnMode(Handle, Value)
end;

procedure TCustomListBox.SetExtendedSelect(const Value: Boolean);
begin
  if FExtendedSelect <> Value then
  begin
    FExtendedSelect := Value;
    QListBox_setSelectionMode(Handle, QListBoxSelectionMode(SelectionFlags[MultiSelect, Value]));
  end;
end;

procedure TCustomListBox.SetItemIndex(const Value: Integer);
begin
  if ItemIndex <> Value then
    if Value < 0 then ClearSelection
    else QListBox_setSelected(Handle, Value, True);
end;

procedure TCustomListBox.SetItems(const Value: TStrings);
begin
  FItems.Assign(Value);
end;

procedure TCustomListBox.SetMultiSelect(const Value: Boolean);
begin
  if FMultiSelect <> Value then
  begin
    FMultiSelect := Value;
    QListBox_setSelectionMode(Handle,
      QListBoxSelectionMode(SelectionFlags[MultiSelect, ExtendedSelect]));
  end;
end;

procedure TCustomListBox.SetRowLayout(const Value: TListBoxLayout);
begin
  if RowLayout <> Value then
    QListBox_setRowMode(Handle, QListBoxLayoutMode(Value));
end;

procedure TCustomListBox.SetRows(const Value: Integer);
begin
  if Rows <> Value then
    QListBox_setRowMode(Handle, Value);
end;

procedure TCustomListBox.SetSelected(Index: Integer; const Value: Boolean);
begin
  QListBox_setSelected(Handle, Index, Value);
end;

procedure TCustomListBox.SetSorted(const Value: Boolean);
begin
  if Sorted <> Value then
    TListBoxStrings(FItems).Sorted := Value;
end;

procedure TCustomListBox.SetTopIndex(const Value: Integer);
begin
  if TopIndex <> Value then QListBox_setTopItem(Handle, Value);
end;

function TCustomListBox.VisibleItemCount: Integer;
begin
  Result := QListBox_numItemsVisible(Handle);
end;

procedure TCustomListBox.HookEvents;
var
  Method: TMethod;
begin
  inherited HookEvents;
  TEventFilterMethod(Method) := ViewportEventFilter;
  Qt_hook_hook_events(FViewportHook, Method);

  QListBox_selectionChanged_Event(Method) := SelChangeHook;
  QListBox_hook_hook_selectionChanged(QListBox_hookH(Hooks), Method);

  if Style = lbOwnerDrawVariable then
    QClxListItem_measure_Event(Method) := ItemMeasureHook
  else
    Method := NullHook;
  QClxListBoxHooks_hook_measure(FDrawHooks, Method);
  QClxListItem_paint_Event(Method) := ItemPaintHook;
  QClxListBoxHooks_hook_paint(FDrawHooks, Method);
end;

function TCustomListBox.ViewportEventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  try
    if Sender <> FViewportHandle then
    begin
      Result := False;
      Exit;
    end;
    case QEvent_type(Event) of
      QEventType_MouseButtonPress,
      QEventType_MouseButtonRelease,
      QEventType_MouseButtonDblClick,
      QEventType_MouseMove:
        Result := MainEventFilter(Sender, Event);
    else
      Result := False;
    end;
  except
    Application.HandleException(Self);
    Result := False;
  end;
end;

procedure TCustomListBox.ItemPaintHook(listBox: QListBoxH; p: QPainterH; Index: Integer;
  Rect: PRect; Flags: Integer; var Handled: Boolean);
var
  State: TOwnerDrawState;
  SaveHandle: QPainterH;
begin
  try
    State := [];
    SaveHandle := FCanvas.Handle;
    try
      FCanvas.Handle := p;
      FCanvas.Font := Font;
      QPainter_translate(FCanvas.Handle, -Rect.Left, -Rect.Top);
      try
        if Boolean(Flags and ClxListBoxItem_Selected) then
        begin
          Include(State, odSelected);
          FCanvas.Brush.Color := clHighlight;
          FCanvas.Font.Color := clHighlightText;
        end
        else begin
          FCanvas.Brush.Color := Color;
          FCanvas.Font.Color := clWindowText;
        end;
        if Boolean(Flags and ClxListBoxItem_Grayed) then
        begin
          Include(State, odGrayed);
          FCanvas.Font.Color := clGrayText;
        end;
        if Boolean(Flags and ClxListBoxItem_Selected) then Include(State, odSelected);
        if Boolean(Flags and ClxListBoxItem_Grayed) then Include(State, odGrayed);
        if Boolean(Flags and ClxListBoxItem_Focused) then Include(State, odFocused);
        Handled := DrawItem(Index, Rect^, State);
        if ItemIndex < 0 then DrawEmptyFocus;
      finally
        QPainter_translate(FCanvas.Handle, Rect.Left, Rect.Top);
      end;
      FCanvas.Stop;
    finally
      FCanvas.Handle := SaveHandle;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomListBox.ItemMeasureHook(index: Integer;
  var height, width: Integer);
begin
  try
    height := FItemHeight;
//    if Style = lbOwnerDrawVariable then
      MeasureItem(Self, index, FItemHeight, width)
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomListBox.SetStyle(const Value: TListBoxStyle);
begin
  if FStyle <> Value then
  begin
    FStyle := Value;
    RecreateWidget;
    AdjustHeight;
  end;
end;

function TCustomListBox.DrawItem(Index: Integer; Rect: TRect;
  State: TOwnerDrawState): Boolean;
begin
  Result := (Style in [lbOwnerDrawFixed, lbOwnerDrawVariable]) and
    Assigned(FOnDrawItem);
  if Result then FOnDrawItem(Self, Index, Rect, State, Result)
end;

procedure TCustomListBox.MeasureItem(Control: TWinControl;
  Index: Integer; var Height, Width: Integer);
begin
  if (Style = lbOwnerDrawVariable) and Assigned(FOnMeasureItem) then
    FOnMeasureItem(Control, Index, Height);
end;

procedure TCustomListBox.Sort;
begin
  QListBox_sort(Handle, True);
  { QWidget_update and QWidget_repaint have no effect here }
  QListBox_triggerUpdate(Handle, False);
end;

function TCustomListBox.GetSorted: Boolean;
begin
  Result := TListBoxStrings(FItems).Sorted;
end;

procedure TCustomListBox.SetItemHeight(const Value: Integer);
begin
  if FStyle in [lbOwnerDrawFixed, lbOwnerDrawVariable] then
  begin
    if FItemHeight <> Value then
    begin
      FItemHeight := Value;
      RecreateWidget;
    end else
    AdjustHeight;
  end;
end;

procedure TCustomListBox.RestoreWidgetState;
begin
  inherited;
  FItems.Assign(FSaveItems);
  FontChanged;
  FSaveItems.Free;
end;

procedure TCustomListBox.SaveWidgetState;
begin
  inherited;
  FSaveItems := TStringList.Create;
  FSaveItems.Assign(FItems);
end;

function TCustomListBox.GetItemData(Index: Integer): LongInt;
var
  Item: QClxListBoxItemH;
begin
  Result := -1;
  Item := QClxListBoxItemH(QListBox_item(Handle, Index));
  if Item <> nil then
    Result := Longint(QClxListBoxItem_getData(Item));
end;

procedure TCustomListBox.SetItemData(Index, AData: Integer);
var
  Item: QClxListBoxItemH;
begin
  Item := QClxListBoxItemH(QListBox_item(Handle, Index));
  if Item <> nil then
    QClxListBoxItem_setData(Item, Pointer(AData));
end;

procedure TCustomListBox.SelChangeHook;
begin
  try
    { Don't call click if deleting an item }
    if not TCustomListBoxStrings(Items).FPutting and (not FClicking) and 
      (not FDeleting) then
      //Click;
      QApplication_postEvent(Handle, QCustomEvent_create(QEventType_LBClick, Self));
    Changed;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomListBox.ResetContent;
begin
  FItems.Clear;
end;

procedure TCustomListBox.DeleteString(Index: Integer);
begin
  FItems.Delete(Index);
end;

procedure TCustomListBox.Update;
begin
  if HandleAllocated then
    QListBox_triggerUpdate(Handle, False);
  inherited;
end;

procedure TCustomListBox.MouseDown(Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  //Rely on Qt's SelectionChanged() signal for single clicks.
  if (Button <> mbLeft) or (ItemAtPos(Point(X, Y), True) <> ItemIndex) then
    ControlState := ControlState - [csClicked];
  inherited MouseDown(Button, Shift, X, Y);
end;

function TCustomListBox.EventFilter(Sender: QObjectH;
  Event: QEventH): Boolean;
begin
  Result := inherited EventFilter(Sender, Event);
  case QEvent_type(Event) of
    QEventType_MouseButtonPress:
      // don't select on a right-click (Qt default behavior)
      Result := QMouseEvent_button(QMouseEventH(Event)) = ButtonState_RightButton;
    QEventType_LBClick:
      if not FClicking then
      begin
        FClicking := True;
        try
          Click;
          Result := True;
        finally
          FClicking := False;
        end;
      end;
  end;
end;

procedure TCustomListBox.FontChanged;
begin
  inherited FontChanged;
  AdjustHeight;
end;

procedure TCustomListBox.AdjustHeight;
var
  FM: QFontMetricsH;
begin
  if not (Style in [lbOwnerDrawFixed, lbOwnerDrawVariable]) then
  begin
    FM := QFontMetrics_create(Font.Handle);
    try
      QWidget_FontMetrics(Handle, FM);
      FItemHeight := QFontMetrics_height(FM);
    finally
      QFontMetrics_destroy(FM);
    end;
  end;
end;

procedure TCustomListBox.InitWidget;
begin
  inherited InitWidget;
  FViewportHandle := QScrollView_viewport(Handle);
  QClxObjectMap_add(FViewportHandle, Integer(Self));
  BorderStyle := bsSunken3d;
  QListBox_setColumnMode(Handle, 1);
end;

procedure TCustomListBox.WidgetDestroyed;
begin
  QClxObjectMap_remove(FViewportHandle);
  inherited WidgetDestroyed;
end;

{ TButtonActionLink }

procedure TButtonActionLink.AssignClient(AClient: TObject);
begin
  inherited AssignClient(AClient);
  FClient := AClient as TButtonControl;
end;

function TButtonActionLink.IsCheckedLinked: Boolean;
begin
  Result := inherited IsCheckedLinked and
    (FClient.Checked = (Action as TCustomAction).Checked);
end;

procedure TButtonActionLink.SetChecked(Value: Boolean);
begin
  if IsCheckedLinked then
  begin
    FClient.ClicksDisabled := True;
    try
      FClient.Checked := Value;
    finally
      FClient.ClicksDisabled := False;
    end;
  end;
end;

type
  TMemoStrings = class(TStrings)
  private
    Memo: TCustomMemo;
    FMultipleAdd: Boolean;
    FChanged: Boolean;
    FChanging: Boolean;
  protected
    procedure Changed;
    function Get(Index: Integer): string; override;
    function GetCount: Integer; override;
    function GetTextStr: string; override;
    procedure SetTextStr(const Value: string); override;
    procedure SetUpdateState(Updating: Boolean); override;
  public
    function Add(const S: string): Integer; override;
    procedure AddStrings(Strings: TStrings); override;
    procedure Assign(Source: TPersistent); override;
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Insert(Index: Integer; const S: string); override;
    procedure LoadFromFile(const Filename: string); override;
  end;

{ TMemoStrings }

function CopyRemoveCR(Source: string): string;
var
  Count: Integer;
  BufPtr, BufPos, BufEnd: PChar;
  CRFound: Boolean;
  CRChar: Char;
  Stream: TStringStream;
begin
  CRFound := False;
  CRChar := #13;
  BufPtr := @Source[1];
  BufPos := BufPtr;
  Count := Length(Source);
  BufEnd := BufPtr + Count;
  Stream := TStringStream.Create('');
  try
    if Count > 0 then
    begin
      while BufPos < BufEnd do
      begin
        if BufPos^ = #13 then
        begin
          if (BufPos < BufEnd - 1) and ((BufPos + 1)^ = #10) then
          begin
            Stream.WriteBuffer(BufPtr^, BufPos - BufPtr);
            BufPtr := BufPos + 1;
          end else if BufPos = BufEnd - 1 then
            CRFound := True;
        end else if CRFound then
        begin
          if BufPos^ <> #10 then
            Stream.WriteBuffer(CRChar, 1);
          CRFound := False;
        end;
        Inc(BufPos);
      end;
      Stream.WriteBuffer(BufPtr^, BufPos - BufPtr);
    end;
    Result := Stream.DataString;
  finally
    Stream.Free;
  end;
end;

function CopyAddCR(Source: string): string;
var
  Count: Integer;
  BufPtr, BufPos, BufEnd: PChar;
  CRFound: Boolean;
  CRChar: Char;
  Stream: TStringStream;
begin
  CRFound := False;
  CRChar := #13;
  BufPtr := @Source[1];
  BufPos := BufPtr;
  Count := Length(Source);
  BufEnd := BufPtr + Count;
  Stream := TStringStream.Create('');
  try
    if Count > 0 then
    begin
      while BufPos < BufEnd do
      begin
        if BufPos^ = #13 then
        begin
          if (BufPos < BufEnd - 1) and ((BufPos + 1)^ = #10) then
          begin
            Stream.WriteBuffer(BufPtr^, BufPos - BufPtr + 2);
            Inc(BufPos);
            BufPtr := BufPos + 1;
          end else if BufPos = BufEnd - 1 then
            CRFound := True;
        end else if CRFound then
          CRFound := False
        else if BufPos^ = #10 then
        begin
          Stream.WriteBuffer(BufPtr^, BufPos - BufPtr);
          Stream.WriteBuffer(CRChar, 1);
          BufPtr := BufPos;
        end;
        Inc(BufPos);
      end;
      Stream.WriteBuffer(BufPtr^, BufPos - BufPtr);
    end;
    Result := Stream.DataString;
  finally
    Stream.Free;
  end;
end;

function TMemoStrings.Add(const S: string): Integer;
var
  CaretPos: TCaretPos;
begin
  Insert(-1, S);
  //Workaround for QMultiLineEdit bug when inserting a first, blank line.
  if FMultipleAdd and (S = '') and (Count = 0) then Insert(-1, S);
  Result := Count - 1;
  if Result < 0 then Result := 0;
  CaretPos.Line := Result;
  CaretPos.Col := 0;
  if not (csLoading in Memo.ComponentState) then
    Memo.SetCaretPos(CaretPos);
end;

procedure TMemoStrings.AddStrings(Strings: TStrings);
begin
  FMultipleAdd := True;
  try
    inherited AddStrings(Strings);
  finally
    FMultipleAdd := False;
  end;
end;

procedure TMemoStrings.Assign(Source: TPersistent);
var
  I, L, Size, Cnt: Integer;
  P: PChar;
  S, LB, NewText: string;
begin
  if Source is TStrings then
  with TStrings(Source) do
  begin
    Cnt := Count;
    Size := 0;
    LB := sLineBreak;
    for I := 0 to Cnt - 1 do Inc(Size, Length(Strings[I]) + Length(LB));
    SetString(NewText, nil, Size);
    P := Pointer(NewText);
    for I := 0 to Count - 1 do
    begin
      S := Strings[I];
      L := Length(S);
      if L <> 0 then
      begin
        System.Move(Pointer(S)^, P^, L);
        Inc(P, L);
      end;
      L := Length(LB);
      if L <> 0 then
      begin
        System.Move(Pointer(LB)^, P^, L);
        Inc(P, L);
      end;
    end;
    SetTextStr(NewText);
  end;
end;

procedure TMemoStrings.Changed;
begin
  Memo.Change;
end;

procedure TMemoStrings.Clear;
begin
  QMultiLineEdit_clear(Memo.Handle);
  Memo.Modified := False;
end;

procedure TMemoStrings.Delete(Index: Integer);
begin
  QMultiLineEdit_removeLine(Memo.Handle, Index);
  Changed;
end;

function TMemoStrings.Get(Index: Integer): string;
var
  WLine: WideString;
begin
  QMultiLineEdit_textLine(Memo.Handle, PWideString(@WLine), Index);
  Result := WLine;
end;

function TMemoStrings.GetCount: Integer;
begin
  Result := QMultiLineEdit_numLines(Memo.Handle);
  if (Result > 0) and (Get(Result-1) = '') then
    Dec(Result);
end;

function TMemoStrings.GetTextStr: string;
begin
  Result := Memo.Text;
  //an empty QMultiLineEdit *always* has a linefeed in it.
  if Result = #10 then
    Result := '';
end;

procedure TMemoStrings.Insert(Index: Integer; const S: string);
var
  CaretPos: TCaretPos;
  WS: WideString;
begin
  WS := S;
  QMultiLineEdit_insertLine(Memo.Handle, PWideString(@WS), Index);

  //Work around QMultiLineEdit bugs.
  CaretPos.Line := Index + 1;
  CaretPos.Col := 0;
  Memo.SetCaretPos(CaretPos);
  if Pos(#10, S) > -1 then Memo.Repaint;

  Changed;
end;

procedure TMemoStrings.LoadFromFile(const Filename: string);
begin
  inherited LoadFromFile(Filename);
  Memo.Modified := False;
end;

procedure TMemoStrings.SetTextStr(const Value: string);
var
  WTemp: WideString;
begin
  FChanging := True;
  try
    Clear;
  finally
    FChanging := False;
  end;
  WTemp := CopyRemoveCR(Value);
  QMultiLineEdit_setText(Memo.Handle, PWideString(@WTemp));
end;

procedure TMemoStrings.SetUpdateState(Updating: Boolean);
begin
  inherited SetUpdateState(Updating);
  QOpenTableView_setAutoUpdate(Memo.Handle, not Updating);
  if not Updating then
    QTableView_repaint(Memo.Handle, True);
  if not Updating and FChanged then Changed;
  FChanged := False;
end;

{ TCustomMemo }

function CountCRs(const S: string; MaxChars: Integer = -1): Integer;
var
  P: PChar;
  CharCount: Integer;
begin
  Result := 0;
  if MaxChars < 0 then
    CharCount := Length(S)
  else
    CharCount := MaxChars;
  P := AnsiStrScan(PChar(S), #13);
  while (P <> nil) and (P - PChar(S) < CharCount + Result) do
  begin
    Inc(Result);
    Inc(P);
    P := AnsiStrScan(P, #13);
  end;
end;

procedure TCustomMemo.Append(const Text: WideString);
begin
  QMultiLineEdit_append(Handle, PWideString(@Text));
end;

function TCustomMemo.AtEOF: Boolean;
begin
  Result := QMultiLineEdit_atEnd(Handle);
end;

procedure TCustomMemo.Change;
begin
  if not TMemoStrings(Lines).FChanging then
  begin
    TMemoStrings(Lines).FChanging := True;
    try
      Modified := True;
      if Assigned(FOnChange) then FOnChange(Self);
    finally
      TMemoStrings(Lines).FChanging := False;
    end;
  end;
end;

procedure TCustomMemo.Clear;
begin
  FLines.Clear;
end;

procedure TCustomMemo.UnSelect;
begin
  QMultiLineEdit_deselect(Handle);
end;

procedure TCustomMemo.ClearSelection;
begin
  if HasSelection then QMultiLineEdit_insert(Handle, nil);
end;

procedure TCustomMemo.CopyToClipboard;
begin
  QMultiLineEdit_copy(Handle);
end;

constructor TCustomMemo.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FLines := TMemoStrings.Create;
  TMemoStrings(FLines).Memo := Self;
  FWantReturns := True;
  FWantTabs := False;
  FMaxLength := -1;
  FWordWrap := True;
  FWrapMode := wmWidth;
  FScrollBars := ssNone; 
  Palette.ColorRole := crBase;
  Palette.TextColorRole := crText;
  ParentColor := False;
  TabStop := True;
  InputKeys := [ikArrows, ikChars, ikNav, ikEdit];
  Height := 89;
  Width := 185; 
end;

procedure TCustomMemo.CreateWidget;
begin
  FHandle := QOpenMultiLineEdit_create(ParentWidget, nil);
  Hooks := QMultiLineEdit_hook_create(Handle);
end;

procedure TCustomMemo.CMKeyDown(var Msg: TCMKeyDown);
var
  KeyEvent: QKeyEventH;
begin
  if ((Msg.Key = Key_Return) or (Msg.Key = Key_Enter)) then
  begin
    Msg.Handled := not FWantReturns;
    if Msg.Handled then
    begin
      if Msg.Shift = [ssCtrl] then
      begin
        //QMultiLineEdit does not respond to <Ctrl-Enter>
        KeyEvent := QKeyEvent_create(QEventType_KeyPress, Key_Return, $0D, 0,
          nil, False, 1);
        try
          QOpenWidget_keyPressEvent(QOpenWidgetH(Handle), KeyEvent);
        finally
          QKeyEvent_destroy(KeyEvent);
        end;
      end else
        inherited;
    end;
  end
  else
    inherited;
end;

procedure TCustomMemo.CutToClipboard;
begin
  QMultiLineEdit_cut(Handle);
end;

destructor TCustomMemo.Destroy;
begin
  FLines.Free;
  inherited Destroy;
end;

function TCustomMemo.GetCaretPos: TCaretPos;
begin
  QMultiLineEdit_cursorPosition(Handle, @Result.Line, @Result.Col);
end;

function TCustomMemo.GetHandle: QOpenMultiLineEditH;
begin
  HandleNeeded;
  Result := QOpenMultiLineEditH(FHandle);
end;

function TCustomMemo.GetHMargin: Integer;
begin
  Result := QMultiLineEdit_hMargin(Handle);
end;

function TCustomMemo.GetModified: Boolean;
begin
  Result := QMultiLineEdit_edited(Handle);
end;

function TCustomMemo.GetReadOnly: Boolean;
begin
  Result := QMultiLineEdit_isReadOnly(Handle);
end;

function TCustomMemo.GetSelection: TMemoSelection;
begin
  QOpenMultiLineEdit_getMarkedRegion(Handle, @Result.Line1, @Result.Col1,
    @Result.Line2, @Result.Col2);
end;

function TCustomMemo.GetSelLength: Integer;
begin
  Result := Length(SelText);
end;

function TCustomMemo.GetSelStart: Integer;
var
  Caret: TCaretPos;
begin
  if not HasSelection then
    Caret := CaretPos
  else
    Caret := Selection.TopLeft;
  Result := CaretPosToPos(Caret);
end;

function TCustomMemo.GetSelText: WideString;
begin
  QOpenMultiLineEdit_MarkedText(Handle, PWideString(@Result));
end;

function TCustomMemo.GetText: TCaption;
begin
  QOpenMultiLineEdit_getText(Handle, PWideString(@Result));
  if (Length(Result) > 0) and (Result[Length(Result)] = #10) then
    Delete(Result, Length(Result), 1);
{$IFDEF MSWINDOWS}
  Result := CopyAddCR(Result);
{$ENDIF}
end;

function TCustomMemo.GetTextWidth(LineNum: Integer): Integer;
begin
  Result := QOpenMultiLineEdit_textWidth(Handle, LineNum);
end;

procedure TCustomMemo.Insert(const Text: WideString; Mark: Boolean = False);
begin
  QOpenMultiLineEdit_insert(Handle, PWideString(@Text), Mark);
end;

function TCustomMemo.HasSelection: Boolean;
begin
  Result := QOpenMultiLineEdit_hasMarkedText(Handle);
end;

procedure TCustomMemo.Insert(const Text: WideString; Column, Row: Integer;
  Mark: Boolean = False);
begin
  QMultiLineEdit_insertAt(Handle, PWideString(@Text), Column, Row, Mark);
end;

procedure TCustomMemo.PasteFromClipboard;
begin
  QMultiLineEdit_paste(Handle);
end;

procedure TCustomMemo.SelectAll;
begin
  QMultiLineEdit_selectAll(Handle);
end;

procedure TCustomMemo.SetCaretPos(const Value: TCaretPos);
begin
  QMultiLineEdit_setCursorPosition(Handle, Value.Line, Value.Col, False);
end;

procedure TCustomMemo.SetHMargin(const Value: Integer);
begin
  if Value <> HMargin then
    QMultiLineEdit_setHMargin(Handle, Value);
end;

procedure TCustomMemo.SetLines(const Value: TStrings);
begin
  FLines.Assign(Value);
end;

procedure TCustomMemo.SetModified(const Value: Boolean);
begin
  if Value <> Modified then QMultiLineEdit_setEdited(Handle, Value);
end;

procedure TCustomMemo.SetReadOnly(const Value: Boolean);
begin
  if Value <> ReadOnly then QMultiLineEdit_setReadOnly(Handle, Value);
end;

procedure TCustomMemo.SetText(const Value: TCaption);
begin
  if (Value <> Text) then
  begin
    TMemoStrings(Lines).SetTextStr(Value);
    TextChanged;
  end;
end;

procedure TCustomMemo.SetSelStart(const Value: Integer);
var
  Chars, Line, LLen: Integer;
  Pos: TCaretPos;
begin
  Chars := 0;
  Line := -1;
  repeat
    Inc(Line);
    LLen := LineLength(Line);
    Chars := Chars + LLen;
  until Chars > Value;
  Pos.Line := Line;
  Pos.Col := Value - (Chars - LLen) ;
  SetCaretPos(Pos);
end;

procedure TCustomMemo.SetSelLength(const Value: Integer);
var
  SelEnd: TCaretPos;
begin
  SelEnd := PosToCaretPos(GetSelStart + Value);
  QMultiLineEdit_setCursorPosition(Handle, SelEnd.Line, SelEnd.Col, True);
end;

procedure TCustomMemo.ReturnPressedHook;
begin
  try
    ReturnPressed;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomMemo.TextChangedHook;
begin
  try
    if (TMemoStrings(Lines).UpdateCount = 0)
    and not TMemoStrings(Lines).FChanging then
      Change
    else
      TMemoStrings(Lines).FChanged := True;
  except
    Application.HandleException(Self);
  end;
end;

function TCustomMemo.LineLength(Index: Integer): Integer;
begin
  { Qt returns length only up to the end of line's text, even
    though QMultiLineEdit_text returns embedded LF's / CRLF's. }
  Result := QOpenMultiLineEdit_lineLength(Handle, Index) + Length(sLineBreak); 
end;

procedure TCustomMemo.Loaded;
begin
  inherited Loaded;
  QMultiLineEdit_setEdited(Handle, False);
end;

function TCustomMemo.CaretPosToPos(CaretPos: TCaretPos): Integer;
var
  L, E: Integer;
begin
  L := 0;
  E := CaretPos.Line;
  Result := CaretPos.Col;
  while L < E do
  begin
    Inc(Result, LineLength(L));
    Inc(L);
  end;
end;

function TCustomMemo.PosToCaretPos(Pos: Integer): TCaretPos;
var
  Len, Offset: Integer;
begin
  Len := 0;
  Offset := 0;
  Result.Line := -1;
  repeat
    Inc(Offset, Len);
    Inc(Result.Line);
    if Result.Line < Lines.Count then
      Len := LineLength(Result.Line);
  until (Offset + Len >= Pos) or (Result.Line >= Lines.Count);
  Result.Col := Pos - Offset;
end;

procedure TCustomMemo.ReturnPressed;
begin
  if Assigned(FOnReturnPressed) then FOnReturnPressed(Self);
end;

procedure TCustomMemo.FontChanged;
begin
  QWidget_setFont(Handle, Font.Handle);
  inherited FontChanged;
end;

procedure TCustomMemo.SetWordWrap(const Value: Boolean);
begin
  if WordWrap <> Value then
  begin
    FWordWrap := Value;
    if FWordWrap then
      InternalSetWrapMode(FWrapMode)
    else
      InternalSetWrapMode(wmNone);
  end;
end;

procedure TCustomMemo.InitWidget;
begin
  inherited InitWidget;
  InternalSetWrapMode(wmWidth);
  WrapBreak := wbWhitespace;
  QMultiLineEdit_setEdited(Handle, False);
  WrapAtValue := -1;
  ScrollBars := ssNone;
  BorderStyle := bsSunken3d;
end;

function TCustomMemo.GetTextLen: Integer;
begin
  Result := Length(Text);
end;

function TCustomMemo.GetTextBuf(Buffer: PChar; BufSize: Integer): Integer;
var
  LText: string;
begin
  { Provided for compatibility. Causes unnecessary copying. }
  LText := Text;
  StrLCopy(Buffer, PChar(LText), BufSize-1);
  Result := StrLen(Buffer);
end;

procedure TCustomMemo.SetMaxLength(const Value: Integer);
var
  S: string;
  CPos: TCaretPos;
begin
  if FMaxLength <> Value then
  begin
    if Value < 0 then
      FMaxLength := -1
    else
      FMaxLength := Value;

    //Qt documentation says MaxLength truncates text, but it doesn't
    if (FMaxLength > -1) and (QOpenMultiLineEdit_textLength(Handle) > FMaxLength) then
    begin
      S := Text;
      CPos := CaretPos;
      SetLength(S, FMaxLength {$IFDEF MSWINDOWS} + CountCRs(S, FMaxLength) {$ENDIF});
      Text := S;
      CaretPos := CPos;
    end;
    QMultiLineEdit_setMaxLength(Handle, FMaxLength);
  end;
end;

function TCustomMemo.GetAlignment: TAlignment;
begin
  Result := QAlignmentToTAlignment(QMultiLineEdit_alignment(Handle));
end;

procedure TCustomMemo.SetAlignment(const Value: TAlignment);
var
  S: WideString;
  Workaround: Boolean;
  CPos: TCaretPos;
begin
  if Value <> Alignment then
  begin
    Workaround := Alignment = taLeftJustify;
    if Workaround then
    begin
      CPos := CaretPos;
      S := Text;
      Lines.Clear;
    end;
    QMultiLineEdit_setAlignment(Handle, AlignmentFlags[Value]);
    if Workaround then
    begin
      TMemoStrings(Lines).SetTextStr(S);
      CaretPos := CPos;
    end;
  end;
end;

procedure TCustomMemo.SetSelText(const Value: WideString);
begin
  QOpenMultiLineEdit_insert(Handle, PWideString(@Value), True);
end;

procedure TCustomMemo.SetScrollBars(const Value: TScrollStyle);
const
  ScrollFlags: array[TScrollStyle] of Cardinal = (
    0,                                          //ssNone
    Cardinal(QTableFlags_hScrollBar),           //ssHorizontal
    Cardinal(QTableFlags_vScrollBar),           //ssVertical
    Cardinal(QTableFlags_hScrollBar)
      or Cardinal(QTableFlags_vScrollBar),      //ssBoth
    Cardinal(QTableFlags_autoHScrollBar),       //ssAutoHorizontal
    Cardinal(QTableFlags_autoVScrollBar),       //ssAutoVertical
    Cardinal(QTableFlags_autoHScrollBar)
      or Cardinal(QTableFlags_autoVScrollBar)   //ssAutoBoth
  );

  ScrollFlagMask = $0000000F;

var
  Resize: QResizeEventH;
  Size: TSize;
begin
  HandleNeeded;
  FScrollBars := Value;
  QOpenMultiLineEdit_clearTableFlags(Handle, ScrollFlagMask);
  QOpenMultiLineEdit_setTableFlags(Handle, ScrollFlags[FScrollBars]);
  //force the QMultiLineEdit to recalc it's "client" area
  Size.cx := Width;
  Size.cy := Height;
  Resize := QResizeEvent_create(@Size, @Size);
  try
    QOpenWidget_resizeEvent(QOpenWidgetH(Handle), Resize);
  finally
    QResizeEvent_destroy(Resize);
  end;
end;

procedure TCustomMemo.SetWrapMode(const Value: TWrapMode);
begin
  if WrapMode <> Value then
  begin
    FWrapMode := Value;
    if FWordWrap then
      InternalSetWrapMode(FWrapMode);
  end;
end;

function TCustomMemo.GetWrapValue: Integer;
begin
  Result := QMultiLineEdit_wrapColumnOrWidth(Handle);
end;

procedure TCustomMemo.SetWrapValue(const Value: Integer);
begin
  if WrapAtValue <> Value then
    QMultiLineEdit_setWrapColumnOrWidth(Handle, Value);
end;

procedure TCustomMemo.InternalSetWrapMode(NewMode: TWrapMode);
begin
  case NewMode of
    wmNone:
      QMultiLineEdit_setWordWrap(Handle, QMultiLineEditWordWrap_NoWrap);
    wmWidth:
      QMultiLineEdit_setWordWrap(Handle, QMultiLineEditWordWrap_WidgetWidth);
    wmPixel:
      QMultiLineEdit_setWordWrap(Handle, QMultiLineEditWordWrap_FixedPixelWidth);
    wmColumn:
      QMultiLineEdit_setWordWrap(Handle, QMultiLineEditWordWrap_FixedColumnWidth);
  end;
  SetScrollBars(FScrollBars);
end;

function TCustomMemo.GetWrapBreak: TWrapBreak;
begin
  Result := TWrapBreak(QMultiLineEdit_wrapPolicy(Handle));
end;

procedure TCustomMemo.SetWrapBreak(const Value: TWrapBreak);
begin
  if WrapBreak <> Value then
    case Value of
      wbWhitespace:
        QMultiLineEdit_setWrapPolicy(Handle, QMultiLineEditWrapPolicy_AtWhiteSpace);
      wbAnywhere:
        QMultiLineEdit_setWrapPolicy(Handle, QMultiLineEditWrapPolicy_Anywhere);
    end;
end;

function TCustomMemo.NeedKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  Result := (((Key = Key_Tab) or (Key = Key_BackTab)) and FWantTabs)
    or inherited NeedKey(Key, Shift, KeyText);
end;

procedure TCustomMemo.HookEvents;
var
  Method: TMethod;
begin
  inherited;
  QMultiLineEdit_textChanged_Event(Method) := TextChangedHook;
  QMultiLineEdit_hook_hook_textChanged(QMultiLineEdit_hookH(Hooks), Method);
  QMultiLineEdit_returnPressed_Event(Method) := ReturnPressedHook;
  QMultiLineEdit_hook_hook_returnPressed(QMultiLineEdit_hookH(Hooks), Method);
end;

{ TRadioButton }

procedure TRadioButton.TurnSiblingsOff;
var
  I: Integer;
  Sibling: TControl;
begin
  if Parent <> nil then
    with Parent do
      for I := 0 to ControlCount - 1 do
      begin
        Sibling := Controls[I];
        if (Sibling <> Self) and (Sibling is TRadioButton) then
          TRadioButton(Sibling).SetChecked(False);
      end;
  if not QRadioButton_isChecked(Handle) then
    QRadioButton_setChecked(Handle, True);
end;

procedure TRadioButton.Click;
begin
  TabStop := Checked;
  TurnSiblingsOff;
  inherited Click;
end;

procedure TRadioButton.ClickedHook;
begin
  try
    Click;
  except
    Application.HandleException(Self);
  end;
end;

constructor TRadioButton.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Width := 113;
  Height := 17;
  ControlStyle := [csSetCaption, csDoubleClicks];
  Palette.ColorRole := crBackground;
  Palette.TextColorRole := crForeground;
  TabStop := True;
end;

procedure TRadioButton.CreateWidget;
begin
  FHandle := QRadioButton_create(ParentWidget, nil);
  Hooks := QButton_hook_create(Handle);
end;

function TRadioButton.GetChecked: Boolean;
begin
  Result := QRadioButton_isChecked(Handle);
end;

function TRadioButton.GetHandle: QRadioButtonH;
begin
  HandleNeeded;
  Result := QRadioButtonH(FHandle);
end;

procedure TRadioButton.HookEvents;
var
  Method: TMethod;
begin
  inherited;
  QButton_clicked_Event(Method) := ClickedHook;
  QButton_hook_hook_Clicked(QButton_hookH(Hooks), Method);
end;

procedure TRadioButton.MouseDown(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
begin
  if not (ssDouble in Shift) then
    inherited MouseDown(Button, Shift, X, Y)
  else if Button = mbLeft then
    DblClick;
end;

procedure TRadioButton.SetChecked(Value: Boolean);
begin
  TabStop := Value;
  if Checked <> Value then
  begin
    if HandleAllocated then
      QRadioButton_setChecked(Handle, Value);
    if Value then
    begin
      TurnSiblingsOff;
      { inherited Changed; }
      if not ClicksDisabled then Click;
    end;
  end;
end;

function TRadioButton.EventFilter(Sender: QObjectH;
  Event: QEventH): Boolean;
var
  E: QEventType;

  function IsSpaceKey: Boolean;
  begin
    Result := ((E = QEventType_KeyPress) or (E = QEventType_KeyRelease))
    and (QKeyEvent_key(QKeyEventH(Event)) = Key_Space);
  end;

  function IsMouseEvent: Boolean;
  begin
    Result := (E = QEventType_MouseButtonPress) or (E = QEventType_MouseButtonRelease);
  end;

begin
  Result := inherited EventFilter(Sender, Event);
  if not Result then
  begin
    E := QEvent_type(Event);
    Result := ((IsSpaceKey or IsMouseEvent) and Checked)
      or (E = QEventType_MouseButtonDblClick);
  end;
end;

function TRadioButton.WantKey(Key: Integer; Shift: TShiftState;
  const KeyText: WideString): Boolean;
begin
  if IsAccel(Key, Caption) and CanFocus then
  begin
    SetFocus;
    Checked := True;
    Result := True;
  end else
    Result := inherited WantKey(Key, Shift, KeyText);
end;

{ TScrollBar }

procedure TScrollBar.Change;
begin
  if Assigned(FOnChange) then FOnChange(Self);
end;

constructor TScrollBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Palette.ColorRole := crButton;
  Palette.TextColorRole := crButtonText;
  FKind := sbHorizontal;
  Width := 121;
  Height := 18;
  TabStop := True;
  ControlStyle := [csFramed, csDoubleClicks, csOpaque];
  InputKeys := [ikArrows];
end;

procedure TScrollBar.CreateWidget;
begin
  FHandle := QScrollBar_create(ParentWidget, nil);
  Hooks := QScrollBar_hook_create(FHandle);
end;

procedure TScrollBar.DoScroll(Code: TScrollCode);
var
  NewPos,
  ScrollPos: Integer;
begin
  if FParamsChanging then Exit;
  NewPos := Position;
  case Code of
    scPageDown:
      Inc(NewPos, LargeChange);
    scPageUp:
      Dec(NewPos, LargeChange);
    scLineDown:
      Inc(NewPos, SmallChange);
    scLineUp:
      Dec(NewPos, SmallChange);
  end;
  if NewPos > Max then NewPos := Max;
  if NewPos < Min then NewPos := Min;
  ScrollPos := NewPos;
  Scroll(Code, ScrollPos);
  if ScrollPos <> NewPos then
  begin
    case Code of
      scPageDown:
        Dec(ScrollPos, LargeChange);
      scPageUp:
        Inc(ScrollPos, LargeChange);
      scLineDown:
        Dec(ScrollPos, SmallChange);
      scLineUp:
        Inc(ScrollPos, SmallChange);
    end;
    Position := ScrollPos;
  end;
end;

function TScrollBar.GetHandle: QScrollBarH;
begin
  HandleNeeded;
  Result := QScrollBarH(FHandle);
end;

function TScrollBar.GetLargeChange: TScrollBarInc;
begin
  Result := QRangeControl_pageStep(RangeControl);
end;

function TScrollBar.GetMax: Integer;
begin
  Result := QRangeControl_maxValue(RangeControl);
end;

function TScrollBar.GetMin: Integer;
begin
  Result := QRangeControl_minValue(RangeControl);
end;

function TScrollBar.GetPosition: Integer;
begin
  Result := QRangeControl_value(RangeControl);
end;

function TScrollBar.GetSmallChange: TScrollBarInc;
begin
  Result := QRangeControl_lineStep(RangeControl);
end;

function TScrollBar.GetTracking: Boolean;
begin
  Result := QScrollBar_tracking(Handle);
end;

procedure TScrollBar.HookEvents;
var
  Method: TMethod;
begin
  QScrollBar_valueChanged_Event(Method) := ValueChangedHook;
  QScrollBar_hook_hook_valueChanged(QScrollBar_hookH(Hooks), Method);
  QScrollBar_sliderPressed_Event(Method) := SliderPressedHook;
  QScrollBar_hook_hook_sliderPressed(QScrollBar_hookH(Hooks), Method);
  QScrollBar_sliderReleased_Event(Method) := SliderReleasedHook;
  QScrollBar_hook_hook_sliderReleased(QScrollBar_hookH(Hooks), Method);
  QScrollBar_nextLine_Event(Method) := NextLineHook;
  QScrollBar_hook_hook_nextLine(QScrollBar_hookH(Hooks), Method);
  QScrollBar_prevLine_Event(Method) := PrevLineHook;
  QScrollBar_hook_hook_prevLine(QScrollBar_hookH(Hooks), Method);
  QScrollBar_nextPage_Event(Method) := NextPageHook;
  QScrollBar_hook_hook_nextPage(QScrollBar_hookH(Hooks), Method);
  QScrollBar_prevPage_Event(Method) := PrevPageHook;
  QScrollBar_hook_hook_prevPage(QScrollBar_hookH(Hooks), Method);
  inherited HookEvents;
end;

procedure TScrollBar.InitWidget;
begin
  inherited InitWidget;
  SmallChange := 1;
  LargeChange := 1;
  Max := 100;
  Min := 0;
  Track := True;
  QScrollBar_setOrientation(Handle, Orientation(sbHorizontal));
end;

procedure TScrollBar.KeyUp(var Key: Word; Shift: TShiftState);
begin
  inherited KeyUp(Key, Shift);
  case Key of
    Key_Left, Key_Right, Key_Up, Key_Down, Key_PageUp,
    Key_PageDown, Key_Home, Key_End:
      if Enabled and Visible then DoScroll(scEndScroll);
  end;
end;

procedure TScrollBar.Loaded;
begin
  inherited;
  QScrollBar_setOrientation(Handle, Orientation(Kind));
end;

procedure TScrollBar.MouseUp(Button: TMouseButton; Shift: TShiftState; X,
  Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  if Enabled and Visible then DoScroll(scEndScroll);
end;


procedure TScrollBar.NextLineHook;
begin
  try
    DoScroll(scLineDown);
    if Position = Max then DoScroll(scBottom);
  except
    Application.HandleException(Self);
  end;
end;

procedure TScrollBar.NextPageHook;
begin
  try
    DoScroll(scPageDown);
    if Position = Max then DoScroll(scBottom);
  except
    Application.HandleException(Self);
  end;
end;

procedure TScrollBar.PrevLineHook;
begin
  try
    DoScroll(scLineUp);
    if Position = Min then DoScroll(scTop);
  except
    Application.HandleException(Self);
  end;
end;

procedure TScrollBar.PrevPageHook;
begin
  try
    DoScroll(scPageUp);
    if Position = Min then DoScroll(scTop);
  except
    Application.HandleException(Self);
  end;
end;

function TScrollBar.RangeControl: QRangeControlH;
begin
  if not Assigned(FRangeControl) then
    FRangeControl := QScrollBar_to_QRangeControl(Handle);
  Result := FRangeControl;
end;

procedure TScrollBar.Scroll(ScrollCode: TScrollCode;
  var ScrollPos: Integer);
begin
  if Assigned(FOnScroll) then FOnScroll(Self, ScrollCode, ScrollPos);
end;

procedure TScrollBar.SetKind(Value: TScrollBarKind);
begin
  { TScrollBarKind maps directly to Qt::Orientation. This could change! }
  if Kind <> Value then
  begin
    FKind := Value;
    QScrollBar_setOrientation(Handle, Orientation(FKind));
    if not (csLoading in ComponentState) then
      SetBounds(Left, Top, Height, Width);
  end;
end;

procedure TScrollBar.SetLargeChange(const Value: TScrollBarInc);
begin
  if Value <> LargeChange then
    QRangeControl_setSteps(RangeControl, SmallChange, Value);
end;

procedure TScrollBar.SetMax(Value: Integer);
begin
  SetParams(Position, Min, Value);
end;

procedure TScrollBar.SetMin(Value: Integer);
begin
  SetParams(Position, Value, Max);
end;

procedure TScrollBar.SetParams(APosition, AMin, AMax: Integer);
begin
  if AMax < AMin then
    raise EInvalidOperation.Create(SScrollBarRange);
  if APosition < AMin then APosition := AMin;
  if APosition > AMax then APosition := AMax;
  FParamsChanging := True;
  try
    if (Min <> AMin) or (Max <> AMax) then
      QRangeControl_setRange(RangeControl, AMin, AMax);
    if Position <> APosition then
    begin
      if Position <> APosition then
        QRangeControl_setValue(RangeControl, APosition);
      Enabled := True;
      DoScroll(scPosition);
    end;
  finally
    FParamsChanging := False;
  end;
end;

procedure TScrollBar.SetPosition(Value: Integer);
begin
  SetParams(Value, Min, Max);
end;

procedure TScrollBar.SetSmallChange(const Value: TScrollBarInc);
begin
  if Value <> SmallChange then
    QRangeControl_SetSteps(RangeControl, Value, LargeChange);
end;

procedure TScrollBar.SetTracking(const Value: Boolean);
begin
  if Track <> Value then
    QScrollBar_setTracking(Handle, Value);
end;

procedure TScrollBar.SliderPressedHook;
begin
  if Track then
  try
    DoScroll(scTrack);
  except
    Application.HandleException(Self);
  end;
end;

procedure TScrollBar.SliderReleasedHook;
begin
  try
    DoScroll(scPosition);
  except
    Application.HandleException(Self);
  end;
end;

procedure TScrollBar.TabStopChanged;
begin
  inherited TabStopChanged;
  if TabStop then
    QWidget_setFocusPolicy(Handle, QWidgetFocusPolicy_ClickFocus)
  else
    QWidget_setFocusPolicy(Handle, QWidgetFocusPolicy_NoFocus)
end;

procedure TScrollBar.ValueChangedHook(Value: Integer);
begin
  try
    DoScroll(scTrack);
    if Position = Min then DoScroll(scTop)
    else if Position = Max then DoScroll(scBottom);
    Change;
  except
    Application.HandleException(Self);
  end;
end;

{ TCustomLCDNumber }
const
  cLCDMode: array [TLCDMode] of QLCDNumberMode = (QLCDNumberMode_Hex,
    QLCDNumberMode_Dec, QLCDNumberMode_Oct, QLCDNumberMode_Bin);
  cLCDPtSize: array [TLCDPointSize] of Boolean = (True, False);
  cLCDSegStyle: array [TLCDSegmentStyle] of QLCDNumberSegmentStyle =
    (QLCDNumberSegmentStyle_Outline, QLCDNumberSegmentStyle_Filled,
     QLCDNumberSegmentStyle_Flat);

procedure TCustomLCDNumber.CreateWidget;
begin
  FHandle := QLCDNumber_create(ParentWidget, nil);
  Hooks := QLCDNumber_hook_create(Handle);
end;

function TCustomLCDNumber.GetHandle: QLCDNumberH;
begin
  HandleNeeded;
  Result := QLCDNumberH(FHandle);
end;

procedure TCustomLCDNumber.SetMode(const Value: TLCDMode);
begin
  if Value <> FMode then
  begin
    FMode := Value;
    SetValue(Self.Value);
    if HandleAllocated then
      QLCDNumber_setMode(Handle, cLCDMode[Value]);
  end;
end;

procedure TCustomLCDNumber.SetNumDigits(const Value: TNumDigits);
begin
  if FNumDigits <> Value then
  begin
    FNumDigits := Value;
    SetValue(Self.Value);
    if HandleAllocated then
    begin
      QLCDNumber_setNumDigits(Handle, Value);
      Invalidate;
    end;
    SetValue(Self.Value);
  end;
end;

procedure TCustomLCDNumber.SetPointSize(const Value: TLCDPointSize);
begin
  if FPtSize <> Value then
  begin
    FPtSize := Value;
    if HandleAllocated then
    begin
      QLCDNumber_setSmallDecimalPoint(Handle, cLCDPtSize[Value]);
      Invalidate;
    end;
  end;
end;

procedure TCustomLCDNumber.SetValue(const Value: AnsiString);
var
  i: Integer;
  ErrorVal: Integer;
  FloatVal: Extended;
  WS: WideString;
begin
  FValue := Value;
  if AutoSize then
    ResizeView;
  if HandleAllocated then
  begin
    Val(FValue, i, ErrorVal);
    if ErrorVal <> 0 then
    begin
      if not TextToFloat(PChar(FValue), FloatVal, fvExtended) then
      begin
        WS := FValue;
        QLCDNumber_display(Handle, @WS);
      end
      else
        QLCDNumber_display(Handle, FloatVal);
    end
    else
      QLCDNumber_display(Handle, i);
  end;
end;

procedure TCustomLCDNumber.SetSegmentStyle(const Value: TLCDSegmentStyle);
begin
  if FSegmentStyle <> Value then
  begin
    FSegmentStyle := Value;
    if HandleAllocated then
      QLCDNumber_setSegmentStyle(Handle, cLCDSegStyle[Value]);
  end;
end;

procedure TCustomLCDNumber.DoOverflow;
begin
  if Assigned(FOnOverflow) then
  try
    FOnOverflow(Self);
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomLCDNumber.SetOnOverflow(const Value: TNotifyEvent);
var
  Method: TMethod;
begin               
  FOnOverflow := Value;
  if Assigned(FOnOverflow) then
    QLCDNumber_overflow_Event(Method) := DoOverflow
  else
    Method := NullHook;
  QLCDNumber_hook_hook_overflow(QLCDNumber_hookH(Hooks), Method);
end;

procedure TCustomLCDNumber.ResizeView;
const
  cPtSize: array [Boolean] of Integer = (0, 1);

var
  ErrorCode: Integer;
  IntVal: Integer;
  ExtendedVal: Extended;
  DigitCount: Integer;
  i: Integer;
begin
  Val(FValue, IntVal, ErrorCode);

  if ErrorCode <> 0 then
    if not TextToFloat(PChar(FValue), ExtendedVal, fvExtended) then
    begin
      Digits := Length(FValue) + cPtSize[PointSize = ptLarge];
      Exit;
    end
    else
      IntVal := Trunc(ExtendedVal);

  DigitCount := -1;
  i := 0;

  case Mode of
    lcdBinary:
    begin
      while IntVal <> $00 do
      begin
        if Boolean(IntVal and $01) then
          DigitCount := i;
        IntVal := IntVal shr 1;
        Inc(i, 1);
      end;
      if DigitCount = -1 then
        Digits := Length(FValue)
      else
        Digits := DigitCount + 1;
    end;
    lcdOctal:
    begin
      while IntVal <> $00 do
      begin
        if Boolean(IntVal and $07) then
          DigitCount := i;
        IntVal := IntVal shr 3;
        Inc(i, 3);
      end;
      if DigitCount = -1 then
        Digits := Length(FValue)
      else
        Digits := DigitCount + 1;
    end;
    lcdDecimal: Digits := Length(FValue);
    lcdHexadecimal: Digits := Length(IntToHex(IntVal, SizeOf(IntVal)));
  end;
end;

procedure TCustomLCDNumber.SetAutoSize(const Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    if FAutoSize then
      ResizeView; 
  end;
end;

procedure TCustomLCDNumber.ColorChanged;
var
  QC: QColorH;
begin
  inherited ColorChanged;
  QC := QColor(Color);
  try
    QWidget_setBackgroundColor(Handle, QC);
  finally
    QColor_destroy(QC);
  end;
end;

constructor TCustomLCDNumber.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FValue := '1';
  FNumDigits := 4;
  FMode := lcdDecimal;
  FPtSize := ptSmall;
  FSegmentStyle := ssOutline;
  BorderStyle := bsEmbossed;
  ControlStyle := ControlStyle + [csNoFocus];
end;

{ TLCDNumber }

procedure TLCDNumber.InitWidget;
begin
  QLCDNumber_setNumDigits(Handle, FNumDigits);
  QLCDNumber_setMode(Handle, cLCDMode[FMode]);
  QLCDNumber_setSmallDecimalPoint(Handle, cLCDPtSize[FPtSize]);
  QLCDNumber_setSegmentStyle(Handle, cLCDSegStyle[FSegmentStyle]);
  SetValue(FValue);
end;

end.

