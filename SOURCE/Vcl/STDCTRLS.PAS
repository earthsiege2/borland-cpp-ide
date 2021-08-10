
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit StdCtrls;

{$R-,T-,H+,X+}

interface

uses Messages, Windows, SysUtils, Classes, Controls, Forms, Menus, Graphics;

type
  TCustomGroupBox = class(TCustomControl)
  private
    procedure CMDialogChar(var Message: TCMDialogChar); message CM_DIALOGCHAR;
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
    procedure WMSize(var Message: TMessage); message WM_SIZE;
  protected
    procedure AdjustClientRect(var Rect: TRect); override;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure Paint; override;
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TGroupBox = class(TCustomGroupBox)
  published
    property Align;
    property Anchors;
    property BiDiMode;
    property Caption;
    property Color;
    property Constraints;
    property Ctl3D;
    property DockSite;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
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
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDockDrop;
    property OnDockOver;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnGetSiteInfo;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
    property OnUnDock;
  end;

  TTextLayout = (tlTop, tlCenter, tlBottom);

  TCustomLabel = class(TGraphicControl)
  private
    FFocusControl: TWinControl;
    FAlignment: TAlignment;
    FAutoSize: Boolean;
    FLayout: TTextLayout;
    FWordWrap: Boolean;
    FShowAccelChar: Boolean;
    function GetTransparent: Boolean;
    procedure SetAlignment(Value: TAlignment);
    procedure SetFocusControl(Value: TWinControl);
    procedure SetShowAccelChar(Value: Boolean);
    procedure SetTransparent(Value: Boolean);
    procedure SetLayout(Value: TTextLayout);
    procedure SetWordWrap(Value: Boolean);
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure CMDialogChar(var Message: TCMDialogChar); message CM_DIALOGCHAR;
  protected
    procedure AdjustBounds; dynamic;
    procedure DoDrawText(var Rect: TRect; Flags: Longint); dynamic;
    function GetLabelText: string; virtual;
    procedure Loaded; override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure Paint; override;
    procedure SetAutoSize(Value: Boolean); virtual;
    property Alignment: TAlignment read FAlignment write SetAlignment
      default taLeftJustify;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default True;
    property FocusControl: TWinControl read FFocusControl write SetFocusControl;
    property ShowAccelChar: Boolean read FShowAccelChar write SetShowAccelChar default True;
    property Transparent: Boolean read GetTransparent write SetTransparent default False;
    property Layout: TTextLayout read FLayout write SetLayout default tlTop;
    property WordWrap: Boolean read FWordWrap write SetWordWrap default False;
  public
    constructor Create(AOwner: TComponent); override;
    property Canvas;
  end;

  TLabel = class(TCustomLabel)
  published
    property Align;
    property Alignment;
    property Anchors;
    property AutoSize;
    property BiDiMode;
    property Caption;
    property Color;
    property Constraints;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property FocusControl;
    property Font;
    property ParentBiDiMode;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
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
    property OnEndDock;
    property OnEndDrag;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

  TEditCharCase = (ecNormal, ecUpperCase, ecLowerCase);

  TCustomEdit = class(TWinControl)
  private
    FMaxLength: Integer;
    FBorderStyle: TBorderStyle;
    FPasswordChar: Char;
    FReadOnly: Boolean;
    FAutoSize: Boolean;
    FAutoSelect: Boolean;
    FHideSelection: Boolean;
    FOEMConvert: Boolean;
    FCharCase: TEditCharCase;
    FCreating: Boolean;
    FModified: Boolean;
    FOnChange: TNotifyEvent;
    procedure AdjustHeight;
    function GetModified: Boolean;
    function GetCanUndo: Boolean;
    procedure SetAutoSize(Value: Boolean);
    procedure SetBorderStyle(Value: TBorderStyle);
    procedure SetCharCase(Value: TEditCharCase);
    procedure SetHideSelection(Value: Boolean);
    procedure SetMaxLength(Value: Integer);
    procedure SetModified(Value: Boolean);
    procedure SetOEMConvert(Value: Boolean);
    procedure SetPasswordChar(Value: Char);
    procedure SetReadOnly(Value: Boolean);
    procedure SetSelText(const Value: string);
    procedure UpdateHeight;
    procedure WMSetFont(var Message: TWMSetFont); message WM_SETFONT;
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
    procedure CMEnter(var Message: TCMGotFocus); message CM_ENTER;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure CNCommand(var Message: TWMCommand); message CN_COMMAND;
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
  protected
    procedure Change; dynamic;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWindowHandle(const Params: TCreateParams); override;
    procedure CreateWnd; override;
    procedure DestroyWnd; override;
    procedure DoSetMaxLength(Value: Integer); virtual;
    function GetSelLength: Integer; virtual;
    function GetSelStart: Integer; virtual;
    function GetSelText: string; virtual;
    procedure SetSelLength(Value: Integer); virtual;
    procedure SetSelStart(Value: Integer); virtual;
    property AutoSelect: Boolean read FAutoSelect write FAutoSelect default True;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default True;
    property BorderStyle: TBorderStyle read FBorderStyle write SetBorderStyle default bsSingle;
    property CharCase: TEditCharCase read FCharCase write SetCharCase default ecNormal;
    property HideSelection: Boolean read FHideSelection write SetHideSelection default True;
    property MaxLength: Integer read FMaxLength write SetMaxLength default 0;
    property OEMConvert: Boolean read FOEMConvert write SetOEMConvert default False;
    property PasswordChar: Char read FPasswordChar write SetPasswordChar default #0;
    property ParentColor default False;
    property ReadOnly: Boolean read FReadOnly write SetReadOnly default False;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Clear; virtual;
    procedure ClearSelection;
    procedure CopyToClipboard;
    procedure CutToClipboard;
    procedure DefaultHandler(var Message); override;
    procedure PasteFromClipboard;
    procedure Undo;
    procedure ClearUndo;
    function GetSelTextBuf(Buffer: PChar; BufSize: Integer): Integer; virtual;
    procedure SelectAll;
    procedure SetSelTextBuf(Buffer: PChar);
    property CanUndo: Boolean read GetCanUndo;
    property Modified: Boolean read GetModified write SetModified;
    property SelLength: Integer read GetSelLength write SetSelLength;
    property SelStart: Integer read GetSelStart write SetSelStart;
    property SelText: string read GetSelText write SetSelText;
    property Text;
  published
    property TabStop default True;
  end;

  TEdit = class(TCustomEdit)
  published
    property Anchors;
    property AutoSelect;
    property AutoSize;
    property BiDiMode;
    property BorderStyle;
    property CharCase;
    property Color;
    property Constraints;
    property Ctl3D;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property Font;
    property HideSelection;
    property ImeMode;
    property ImeName;
    property MaxLength;
    property OEMConvert;
    property ParentBiDiMode;
    property ParentColor;
    property ParentCtl3D;
    property ParentFont;
    property ParentShowHint;
    property PasswordChar;
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
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

  TScrollStyle = (ssNone, ssHorizontal, ssVertical, ssBoth);

  TCustomMemo = class(TCustomEdit)
  private
    FLines: TStrings;
    FAlignment: TAlignment;
    FScrollBars: TScrollStyle;
    FWordWrap: Boolean;
    FWantReturns: Boolean;
    FWantTabs: Boolean;
    procedure WMGetDlgCode(var Message: TWMGetDlgCode); message WM_GETDLGCODE;
    procedure WMNCDestroy(var Message: TWMNCDestroy); message WM_NCDESTROY;
  protected
    function GetCaretPos: TPoint; virtual;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWindowHandle(const Params: TCreateParams); override;
    procedure KeyPress(var Key: Char); override;
    procedure Loaded; override;
    procedure SetAlignment(Value: TAlignment);
    procedure SetLines(Value: TStrings);
    procedure SetScrollBars(Value: TScrollStyle);
    procedure SetWordWrap(Value: Boolean);
    property Alignment: TAlignment read FAlignment write SetAlignment default taLeftJustify;
    property ScrollBars: TScrollStyle read FScrollBars write SetScrollBars default ssNone;
    property WantReturns: Boolean read FWantReturns write FWantReturns default True;
    property WantTabs: Boolean read FWantTabs write FWantTabs default False;
    property WordWrap: Boolean read FWordWrap write SetWordWrap default True;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetControlsAlignment: TAlignment; override;
    property CaretPos: TPoint read GetCaretPos;
    property Lines: TStrings read FLines write SetLines;
  end;

  TMemo = class(TCustomMemo)
  published
    property Align;
    property Alignment;
    property Anchors;
    property BiDiMode;
    property BorderStyle;
    property Color;
    property Constraints;
    property Ctl3D;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property Font;
    property HideSelection;
    property ImeMode;
    property ImeName;
    property Lines;
    property MaxLength;
    property OEMConvert;
    property ParentBiDiMode;
    property ParentColor;
    property ParentCtl3D;
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
    property OnChange;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

  TComboBoxStyle = (csDropDown, csSimple, csDropDownList, csOwnerDrawFixed,
    csOwnerDrawVariable);
  TOwnerDrawState = Windows.TOwnerDrawState;
  {$NODEFINE TOwnerDrawState}

  TDrawItemEvent = procedure(Control: TWinControl; Index: Integer;
    Rect: TRect; State: TOwnerDrawState) of object;

  TMeasureItemEvent = procedure(Control: TWinControl; Index: Integer;
    var Height: Integer) of object;

  TCustomComboBox = class(TWinControl)
  private
    FItems: TStrings;
    FCanvas: TCanvas;
    FCharCase: TEditCharCase;
    FSorted: Boolean;
    FStyle: TComboBoxStyle;
    FItemHeight: Integer;
    FMaxLength: Integer;
    FDropDownCount: Integer;
    FEditHandle: HWnd;
    FListHandle: HWnd;
    FEditInstance: Pointer;
    FListInstance: Pointer;
    FDefEditProc: Pointer;
    FDefListProc: Pointer;
    FIsFocused: Boolean;
    FFocusChanged: Boolean;
    FSaveItems: TStringList;
    FSaveIndex: Integer;
    FDroppingDown: Boolean;
    FOnChange: TNotifyEvent;
    FOnDropDown: TNotifyEvent;
    FOnDrawItem: TDrawItemEvent;
    FOnMeasureItem: TMeasureItemEvent;
    procedure AdjustDropDown;
    procedure EditWndProc(var Message: TMessage);
    function GetDroppedDown: Boolean;
    function GetItemIndex: Integer;
    function GetSelLength: Integer;
    function GetSelStart: Integer;
    function GetSelText: string;
    procedure ListWndProc(var Message: TMessage);
    procedure SetCharCase(Value: TEditCharCase);
    procedure SetDroppedDown(Value: Boolean);
    procedure SetItems(Value: TStrings);
    procedure SetItemIndex(Value: Integer);
    procedure SetSelLength(Value: Integer);
    procedure SetSelStart(Value: Integer);
    procedure SetSelText(const Value: string);
    procedure SetSorted(Value: Boolean);
    function  GetItemHeight: Integer;
    procedure SetItemHeight(Value: Integer);
    procedure SetMaxLength(Value: Integer);
    procedure WMCreate(var Message: TWMCreate); message WM_CREATE;
    procedure WMEraseBkgnd(var Message: TWMEraseBkgnd); message WM_ERASEBKGND;
    procedure CMCancelMode(var Message: TCMCancelMode); message CM_CANCELMODE;
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
    procedure CMParentColorChanged(var Message: TMessage); message CM_PARENTCOLORCHANGED;
    procedure CNCommand(var Message: TWMCommand); message CN_COMMAND;
    procedure CNDrawItem(var Message: TWMDrawItem); message CN_DRAWITEM;
    procedure CNMeasureItem(var Message: TWMMeasureItem); message CN_MEASUREITEM;
    procedure WMLButtonDown(var Message: TWMLButtonDown); message WM_LBUTTONDOWN;
    procedure WMDrawItem(var Message: TWMDrawItem); message WM_DRAWITEM;
    procedure WMMeasureItem(var Message: TWMMeasureItem); message WM_MEASUREITEM;
    procedure WMDeleteItem(var Message: TWMDeleteItem); message WM_DELETEITEM;
    procedure WMGetDlgCode(var Message: TWMGetDlgCode); message WM_GETDLGCODE;
  protected
    procedure ComboWndProc(var Message: TMessage; ComboWnd: HWnd;
      ComboProc: Pointer); virtual;
    procedure WndProc(var Message: TMessage); override;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWnd; override;
    procedure DestroyWnd; override;
    procedure DrawItem(Index: Integer; Rect: TRect;
      State: TOwnerDrawState); virtual;
    function GetComboControl: HWND; virtual;
    procedure MeasureItem(Index: Integer; var Height: Integer); virtual;
    procedure Change; dynamic;
    procedure DropDown; dynamic;
    procedure SetStyle(Value: TComboBoxStyle); virtual;
    property DropDownCount: Integer read FDropDownCount write FDropDownCount default 8;
    property EditHandle: HWnd read FEditHandle;
    property ItemHeight: Integer read GetItemHeight write SetItemHeight;
    property ListHandle: HWnd read FListHandle;
    property MaxLength: Integer read FMaxLength write SetMaxLength default 0;
    property ParentColor default False;
    property Sorted: Boolean read FSorted write SetSorted default False;
    property Style: TComboBoxStyle read FStyle write SetStyle default csDropDown;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnDropDown: TNotifyEvent read FOnDropDown write FOnDropDown;
    property OnDrawItem: TDrawItemEvent read FOnDrawItem write FOnDrawItem;
    property OnMeasureItem: TMeasureItemEvent read FOnMeasureItem write FOnMeasureItem;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Clear;
    function Focused: Boolean; override;
    procedure SelectAll;
    property CharCase: TEditCharCase read FCharCase write SetCharCase default ecNormal;
    property Canvas: TCanvas read FCanvas;
    property DroppedDown: Boolean read GetDroppedDown write SetDroppedDown;
    property Items: TStrings read FItems write SetItems;
    property ItemIndex: Integer read GetItemIndex write SetItemIndex;
    property SelLength: Integer read GetSelLength write SetSelLength;
    property SelStart: Integer read GetSelStart write SetSelStart;
    property SelText: string read GetSelText write SetSelText;
  published
    property TabStop default True;
  end;

  TComboBox = class(TCustomComboBox)
  published
    property Style; {Must be published before Items}
    property Anchors;
    property BiDiMode;
    property Color;
    property Constraints;
    property Ctl3D;
    property DragCursor;
    property DragKind;
    property DragMode;
    property DropDownCount;
    property Enabled;
    property Font;
    property ImeMode;
    property ImeName;
    property ItemHeight;
    property MaxLength;
    property ParentBiDiMode;
    property ParentColor;
    property ParentCtl3D;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property Sorted;
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
    property OnDrawItem;
    property OnDropDown;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMeasureItem;
    property OnStartDock;
    property OnStartDrag;
    property Items; { Must be published after OnMeasureItem }
  end;

{ TButtonControl }

  TButtonControl = class;

  TButtonActionLink = class(TWinControlActionLink)
  protected
    FClient: TButtonControl;
    procedure AssignClient(AClient: TObject); override;
    function IsCheckedLinked: Boolean; override;
    procedure SetChecked(Value: Boolean); override;
  end;

  TButtonActionLinkClass = class of TButtonActionLink;

  TButtonControl = class(TWinControl)
  private
    FClicksDisabled: Boolean;
    function IsCheckedStored: Boolean;
  protected
    procedure ActionChange(Sender: TObject; CheckDefaults: Boolean); override;
    function GetActionLinkClass: TControlActionLinkClass; override;
    function GetChecked: Boolean; virtual;
    procedure SetChecked(Value: Boolean); virtual;
    procedure WndProc(var Message: TMessage); override;
    property Checked: Boolean read GetChecked write SetChecked stored IsCheckedStored default False;
    property ClicksDisabled: Boolean read FClicksDisabled write FClicksDisabled;
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TButton = class(TButtonControl)
  private
    FDefault: Boolean;
    FCancel: Boolean;
    FActive: Boolean;
    FModalResult: TModalResult;
    procedure SetDefault(Value: Boolean);
    procedure CMDialogKey(var Message: TCMDialogKey); message CM_DIALOGKEY;
    procedure CMDialogChar(var Message: TCMDialogChar); message CM_DIALOGCHAR;
    procedure CMFocusChanged(var Message: TCMFocusChanged); message CM_FOCUSCHANGED;
    procedure CNCommand(var Message: TWMCommand); message CN_COMMAND;
    procedure WMEraseBkgnd(var Message: TWMEraseBkgnd); message WM_ERASEBKGND;
  protected
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWnd; override;
    procedure SetButtonStyle(ADefault: Boolean); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Click; override;
    function UseRightToLeftAlignment: Boolean; override;
  published
    property Action;
    property Anchors;
    property BiDiMode;
    property Cancel: Boolean read FCancel write FCancel default False;
    property Caption;
    property Constraints;
    property Default: Boolean read FDefault write SetDefault default False;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property Font;
    property ModalResult: TModalResult read FModalResult write FModalResult default 0;
    property ParentBiDiMode;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property TabStop default True;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

  TCheckBoxState = (cbUnchecked, cbChecked, cbGrayed);

  TCustomCheckBox = class(TButtonControl)
  private
    FAlignment: TLeftRight;
    FAllowGrayed: Boolean;
    FState: TCheckBoxState;
    procedure SetAlignment(Value: TLeftRight);
    procedure SetState(Value: TCheckBoxState);
    procedure WMSize(var Message: TMessage); message WM_SIZE;
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
    procedure CMDialogChar(var Message: TCMDialogChar); message CM_DIALOGCHAR;
    procedure CNCommand(var Message: TWMCommand); message CN_COMMAND;
  protected
    procedure Toggle; virtual;
    procedure Click; override;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWnd; override;
    function GetChecked: Boolean; override;
    procedure SetChecked(Value: Boolean); override;
    property Alignment: TLeftRight read FAlignment write SetAlignment default taRightJustify;
    property AllowGrayed: Boolean read FAllowGrayed write FAllowGrayed default False;
    property State: TCheckBoxState read FState write SetState default cbUnchecked;
  public
    constructor Create(AOwner: TComponent); override;
    function GetControlsAlignment: TAlignment; override;
  published
    property TabStop default True;
  end;

  TCheckBox = class(TCustomCheckBox)
  published
    property Action;
    property Alignment;
    property AllowGrayed;
    property Anchors;
    property BiDiMode;
    property Caption;
    property Checked;
    property Color;
    property Constraints;
    property Ctl3D;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property Font;
    property ParentBiDiMode;
    property ParentColor;
    property ParentCtl3D;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property State;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

  TRadioButton = class(TButtonControl)
  private
    FAlignment: TLeftRight;
    FChecked: Boolean;
    procedure SetAlignment(Value: TLeftRight);
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
    procedure CMDialogChar(var Message: TCMDialogChar); message CM_DIALOGCHAR;
    procedure CNCommand(var Message: TWMCommand); message CN_COMMAND;
  protected
    function GetChecked: Boolean; override;
    procedure SetChecked(Value: Boolean); override;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWnd; override;
  public
    constructor Create(AOwner: TComponent); override;
    function GetControlsAlignment: TAlignment; override;
  published
    property Action;
    property Alignment: TLeftRight read FAlignment write SetAlignment default taRightJustify;
    property Anchors;
    property BiDiMode;
    property Caption;
    property Checked;
    property Color;
    property Constraints;
    property Ctl3D;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
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
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

  TListBoxStyle = (lbStandard, lbOwnerDrawFixed, lbOwnerDrawVariable);

  TCustomListBox = class(TWinControl)
  private
    FItems: TStrings;
    FBorderStyle: TBorderStyle;
    FCanvas: TCanvas;
    FColumns: Integer;
    FItemHeight: Integer;
    FStyle: TListBoxStyle;
    FIntegralHeight: Boolean;
    FMultiSelect: Boolean;
    FSorted: Boolean;
    FExtendedSelect: Boolean;
    FTabWidth: Integer;
    FSaveItems: TStringList;
    FSaveTopIndex: Integer;
    FSaveItemIndex: Integer;
    FOnDrawItem: TDrawItemEvent;
    FOnMeasureItem: TMeasureItemEvent;
    function GetItemHeight: Integer;
    function GetItemIndex: Integer;
    function GetSelCount: Integer;
    function GetSelected(Index: Integer): Boolean;
    function GetTopIndex: Integer;
    procedure SetBorderStyle(Value: TBorderStyle);
    procedure SetColumnWidth;
    procedure SetColumns(Value: Integer);
    procedure SetExtendedSelect(Value: Boolean);
    procedure SetIntegralHeight(Value: Boolean);
    procedure SetItemHeight(Value: Integer);
    procedure SetItems(Value: TStrings);
    procedure SetItemIndex(Value: Integer);
    procedure SetMultiSelect(Value: Boolean);
    procedure SetSelected(Index: Integer; Value: Boolean);
    procedure SetSorted(Value: Boolean);
    procedure SetStyle(Value: TListBoxStyle);
    procedure SetTabWidth(Value: Integer);
    procedure SetTopIndex(Value: Integer);
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
    procedure WMSize(var Message: TWMSize); message WM_SIZE;
    procedure CNCommand(var Message: TWMCommand); message CN_COMMAND;
    procedure CNDrawItem(var Message: TWMDrawItem); message CN_DRAWITEM;
    procedure CNMeasureItem(var Message: TWMMeasureItem); message CN_MEASUREITEM;
    procedure WMLButtonDown(var Message: TWMLButtonDown); message WM_LBUTTONDOWN;
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
  protected
    FMoving: Boolean;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWnd; override;
    procedure DestroyWnd; override;
    procedure WndProc(var Message: TMessage); override;
    procedure DragCanceled; override;
    procedure DrawItem(Index: Integer; Rect: TRect;
      State: TOwnerDrawState); virtual;
    procedure MeasureItem(Index: Integer; var Height: Integer); virtual;
    function InternalGetItemData(Index: Integer): Longint; dynamic;
    procedure InternalSetItemData(Index: Integer; AData: Longint); dynamic;
    function GetItemData(Index: Integer): LongInt; dynamic;
    procedure SetItemData(Index: Integer; AData: LongInt); dynamic;
    procedure ResetContent; dynamic;
    procedure DeleteString(Index: Integer); dynamic;
    property BorderStyle: TBorderStyle read FBorderStyle write SetBorderStyle default bsSingle;
    property Columns: Integer read FColumns write SetColumns default 0;
    property ExtendedSelect: Boolean read FExtendedSelect write SetExtendedSelect default True;
    property IntegralHeight: Boolean read FIntegralHeight write SetIntegralHeight default False;
    property ItemHeight: Integer read GetItemHeight write SetItemHeight;
    property MultiSelect: Boolean read FMultiSelect write SetMultiSelect default False;
    property ParentColor default False;
    property Sorted: Boolean read FSorted write SetSorted default False;
    property Style: TListBoxStyle read FStyle write SetStyle default lbStandard;
    property TabWidth: Integer read FTabWidth write SetTabWidth default 0;
    property OnDrawItem: TDrawItemEvent read FOnDrawItem write FOnDrawItem;
    property OnMeasureItem: TMeasureItemEvent read FOnMeasureItem write FOnMeasureItem;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Clear;
    function ItemAtPos(Pos: TPoint; Existing: Boolean): Integer;
    function ItemRect(Index: Integer): TRect;
    property Canvas: TCanvas read FCanvas;
    property Items: TStrings read FItems write SetItems;
    property ItemIndex: Integer read GetItemIndex write SetItemIndex;
    property SelCount: Integer read GetSelCount;
    property Selected[Index: Integer]: Boolean read GetSelected write SetSelected;
    property TopIndex: Integer read GetTopIndex write SetTopIndex;
  published
    property TabStop default True;
  end;

  TListBox = class(TCustomListBox)
  published
    property Align;
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
    property ExtendedSelect;
    property Font;
    property ImeMode;
    property ImeName;
    property IntegralHeight;
    property ItemHeight;
    property Items;
    property MultiSelect;
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

  TScrollCode = (scLineUp, scLineDown, scPageUp, scPageDown, scPosition,
    scTrack, scTop, scBottom, scEndScroll);

  TScrollEvent = procedure(Sender: TObject; ScrollCode: TScrollCode;
    var ScrollPos: Integer) of object;

  TScrollBar = class(TWinControl)
  private
    FKind: TScrollBarKind;
    FPosition: Integer;
    FMin: Integer;
    FMax: Integer;
    FPageSize: Integer;
    FRTLFactor: Integer;
    FSmallChange: TScrollBarInc;
    FLargeChange: TScrollBarInc;
    FOnChange: TNotifyEvent;
    FOnScroll: TScrollEvent;
    procedure DoScroll(var Message: TWMScroll);
    function NotRightToLeft: Boolean;
    procedure SetKind(Value: TScrollBarKind);
    procedure SetMax(Value: Integer);
    procedure SetMin(Value: Integer);
    procedure SetPosition(Value: Integer);
    procedure SetPageSize(Value: Integer);
    procedure CNHScroll(var Message: TWMHScroll); message CN_HSCROLL;
    procedure CNVScroll(var Message: TWMVScroll); message CN_VSCROLL;
    procedure CNCtlColorScrollBar(var Message: TMessage); message CN_CTLCOLORSCROLLBAR;
    procedure WMEraseBkgnd(var Message: TWMEraseBkgnd); message WM_ERASEBKGND;
  protected
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWnd; override;
    procedure Change; dynamic;
    procedure Scroll(ScrollCode: TScrollCode; var ScrollPos: Integer); dynamic;
  public
    constructor Create(AOwner: TComponent); override;
    procedure SetParams(APosition, AMin, AMax: Integer);
  published
    property Align;
    property Anchors;
    property BiDiMode;
    property Constraints;
    property Ctl3D;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property Kind: TScrollBarKind read FKind write SetKind default sbHorizontal;
    property LargeChange: TScrollBarInc read FLargeChange write FLargeChange default 1;
    property Max: Integer read FMax write SetMax default 100;
    property Min: Integer read FMin write SetMin default 0;
    property PageSize: Integer read FPageSize write SetPageSize;
    property ParentBiDiMode;
    property ParentCtl3D;
    property ParentShowHint;
    property PopupMenu;
    property Position: Integer read FPosition write SetPosition default 0;
    property ShowHint;
    property SmallChange: TScrollBarInc read FSmallChange write FSmallChange default 1;
    property TabOrder;
    property TabStop default True;
    property Visible;
    property OnContextPopup;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnScroll: TScrollEvent read FOnScroll write FOnScroll;
    property OnStartDock;
    property OnStartDrag;
  end;

  TStaticBorderStyle = (sbsNone, sbsSingle, sbsSunken);

  TCustomStaticText = class(TWinControl)
  private
    FAlignment: TAlignment;
    FAutoSize: Boolean;
    FBorderStyle: TStaticBorderStyle;
    FFocusControl: TWinControl;
    FShowAccelChar: Boolean;
    procedure CMDialogChar(var Message: TCMDialogChar); message CM_DIALOGCHAR;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
    procedure AdjustBounds;
    procedure SetAlignment(Value: TAlignment);
    procedure SetAutoSize(Value: Boolean);
    procedure SetBorderStyle(Value: TStaticBorderStyle);
    procedure SetFocusControl(Value: TWinControl);
    procedure SetShowAccelChar(Value: Boolean);
  protected
    procedure CreateParams(var Params: TCreateParams); override;
    procedure Loaded; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    property Alignment: TAlignment read FAlignment write SetAlignment
      default taLeftJustify;
    property AutoSize: Boolean read FAutoSize write SetAutoSize default True;
    property BorderStyle: TStaticBorderStyle read FBorderStyle
      write SetBorderStyle default sbsNone;
    property FocusControl: TWinControl read FFocusControl write SetFocusControl;
    property ShowAccelChar: Boolean read FShowAccelChar write SetShowAccelChar
      default True;
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TStaticText = class(TCustomStaticText)
  published
    property Align;
    property Alignment;
    property Anchors;
    property AutoSize;
    property BiDiMode;
    property BorderStyle;
    property Caption;
    property Color;
    property Constraints;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property FocusControl;
    property Font;
    property ParentBiDiMode;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowAccelChar;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

implementation

uses Consts, ActnList;

function HasPopup(Control: TControl): Boolean;
begin
  Result := True;
  while Control <> nil do
    if TCustomEdit(Control).PopupMenu <> nil then Exit else Control := Control.Parent;
  Result := False;
end;

type
  TSelection = record
    StartPos, EndPos: Integer;
  end;

  TMemoStrings = class(TStrings)
  private
    Memo: TCustomMemo;
  protected
    function Get(Index: Integer): string; override;
    function GetCount: Integer; override;
    function GetTextStr: string; override;
    procedure Put(Index: Integer; const S: string); override;
    procedure SetTextStr(const Value: string); override;
    procedure SetUpdateState(Updating: Boolean); override;
  public
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Insert(Index: Integer; const S: string); override;
  end;

  TComboBoxStrings = class(TStrings)
  private
    ComboBox: TCustomComboBox;
  protected
    function Get(Index: Integer): string; override;
    function GetCount: Integer; override;
    function GetObject(Index: Integer): TObject; override;
    procedure PutObject(Index: Integer; AObject: TObject); override;
    procedure SetUpdateState(Updating: Boolean); override;
  public
    function Add(const S: string): Integer; override;
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    function IndexOf(const S: string): Integer; override;
    procedure Insert(Index: Integer; const S: string); override;
  end;

  TListBoxStrings = class(TStrings)
  private
    ListBox: TCustomListBox;
  protected
    procedure Put(Index: Integer; const S: string); override;
    function Get(Index: Integer): string; override;
    function GetCount: Integer; override;
    function GetObject(Index: Integer): TObject; override;
    procedure PutObject(Index: Integer; AObject: TObject); override;
    procedure SetUpdateState(Updating: Boolean); override;
  public
    function Add(const S: string): Integer; override;
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Exchange(Index1, Index2: Integer); override;
    function IndexOf(const S: string): Integer; override;
    procedure Insert(Index: Integer; const S: string); override;
    procedure Move(CurIndex, NewIndex: Integer); override;
  end;

const
  BorderStyles: array[TBorderStyle] of DWORD = (0, WS_BORDER);

{ TCustomGroupBox }

constructor TCustomGroupBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csAcceptsControls, csCaptureMouse, csClickEvents,
    csSetCaption, csDoubleClicks, csReplicatable];
  Width := 185;
  Height := 105;
end;

procedure TCustomGroupBox.AdjustClientRect(var Rect: TRect);
begin
  inherited AdjustClientRect(Rect);
  Canvas.Font := Font;
  Inc(Rect.Top, Canvas.TextHeight('0'));
  InflateRect(Rect, -1, -1);
  if Ctl3d then InflateRect(Rect, -1, -1);
end;

procedure TCustomGroupBox.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  with Params.WindowClass do
    style := style and not (CS_HREDRAW or CS_VREDRAW);
end;

procedure TCustomGroupBox.Paint;
var
  H: Integer;
  R: TRect;
  Flags: Longint;
begin
  with Canvas do
  begin
    Font := Self.Font;
    H := TextHeight('0');
    R := Rect(0, H div 2 - 1, Width, Height);
    if Ctl3D then
    begin
      Inc(R.Left);
      Inc(R.Top);
      Brush.Color := clBtnHighlight;
      FrameRect(R);
      OffsetRect(R, -1, -1);
      Brush.Color := clBtnShadow;
    end else
      Brush.Color := clWindowFrame;
    FrameRect(R);
    if Text <> '' then
    begin
      if not UseRightToLeftAlignment then
        R := Rect(8, 0, 0, H)
      else                         
        R := Rect(R.Right - Canvas.TextWidth(Text) - 8, 0, 0, H);
      Flags := DrawTextBiDiModeFlags(DT_SINGLELINE);
      DrawText(Handle, PChar(Text), Length(Text), R, Flags or DT_CALCRECT);
      Brush.Color := Color;
      DrawText(Handle, PChar(Text), Length(Text), R, Flags);
    end;
  end;
end;

procedure TCustomGroupBox.CMDialogChar(var Message: TCMDialogChar);
begin
  with Message do
    if IsAccel(CharCode, Caption) and CanFocus then
    begin
      SelectFirst;
      Result := 1;
    end else
      inherited;
end;

procedure TCustomGroupBox.CMTextChanged(var Message: TMessage);
begin
  Invalidate;
  Realign;
end;

procedure TCustomGroupBox.CMCtl3DChanged(var Message: TMessage);
begin
  inherited;
  Invalidate;
  Realign;
end;

procedure TCustomGroupBox.WMSize(var Message: TMessage);
begin
  inherited;
  Invalidate;
end;

{ TCustomLabel }

constructor TCustomLabel.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csOpaque, csReplicatable];
  Width := 65;
  Height := 17;
  FAutoSize := True;
  FShowAccelChar := True;
end;

function TCustomLabel.GetLabelText: string;
begin
  Result := Caption;
end;

procedure TCustomLabel.DoDrawText(var Rect: TRect; Flags: Longint);
var
  Text: string;
begin
  Text := GetLabelText;
  if (Flags and DT_CALCRECT <> 0) and ((Text = '') or FShowAccelChar and
    (Text[1] = '&') and (Text[2] = #0)) then Text := Text + ' ';
  if not FShowAccelChar then Flags := Flags or DT_NOPREFIX;
  Flags := DrawTextBiDiModeFlags(Flags);
  Canvas.Font := Font;
  if not Enabled then
  begin
    OffsetRect(Rect, 1, 1);
    Canvas.Font.Color := clBtnHighlight;
    DrawText(Canvas.Handle, PChar(Text), Length(Text), Rect, Flags);
    OffsetRect(Rect, -1, -1);
    Canvas.Font.Color := clBtnShadow;
    DrawText(Canvas.Handle, PChar(Text), Length(Text), Rect, Flags);
  end
  else
    DrawText(Canvas.Handle, PChar(Text), Length(Text), Rect, Flags);
end;

procedure TCustomLabel.Paint;
const
  Alignments: array[TAlignment] of Word = (DT_LEFT, DT_RIGHT, DT_CENTER);
  WordWraps: array[Boolean] of Word = (0, DT_WORDBREAK);
var
  Rect, CalcRect: TRect;
  DrawStyle: Longint;
begin
  with Canvas do
  begin
    if not Transparent then
    begin
      Brush.Color := Self.Color;
      Brush.Style := bsSolid;
      FillRect(ClientRect);
    end;
    Brush.Style := bsClear;
    Rect := ClientRect;
    { DoDrawText takes care of BiDi alignments }
    DrawStyle := DT_EXPANDTABS or WordWraps[FWordWrap] or Alignments[FAlignment];
    { Calculate vertical layout }
    if FLayout <> tlTop then
    begin
      CalcRect := Rect;
      DoDrawText(CalcRect, DrawStyle or DT_CALCRECT);
      if FLayout = tlBottom then OffsetRect(Rect, 0, Height - CalcRect.Bottom)
      else OffsetRect(Rect, 0, (Height - CalcRect.Bottom) div 2);
    end;
    DoDrawText(Rect, DrawStyle);
  end;
end;

procedure TCustomLabel.Loaded;
begin
  inherited Loaded;
  AdjustBounds;
end;

procedure TCustomLabel.AdjustBounds;
const
  WordWraps: array[Boolean] of Word = (0, DT_WORDBREAK);
var
  DC: HDC;
  X: Integer;
  Rect: TRect;
  AAlignment: TAlignment;
begin
  if not (csReading in ComponentState) and FAutoSize then
  begin
    Rect := ClientRect;
    DC := GetDC(0);
    Canvas.Handle := DC;
    DoDrawText(Rect, (DT_EXPANDTABS or DT_CALCRECT) or WordWraps[FWordWrap]);
    Canvas.Handle := 0;
    ReleaseDC(0, DC);
    X := Left;
    AAlignment := FAlignment;
    if UseRightToLeftAlignment then ChangeBiDiModeAlignment(AAlignment);
    if AAlignment = taRightJustify then Inc(X, Width - Rect.Right);
    SetBounds(X, Top, Rect.Right, Rect.Bottom);
  end;
end;

procedure TCustomLabel.SetAlignment(Value: TAlignment);
begin
  if FAlignment <> Value then
  begin
    FAlignment := Value;
    Invalidate;
  end;
end;

procedure TCustomLabel.SetAutoSize(Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    AdjustBounds;
  end;
end;

function TCustomLabel.GetTransparent: Boolean;
begin
  Result := not (csOpaque in ControlStyle);
end;

procedure TCustomLabel.SetFocusControl(Value: TWinControl);
begin
  FFocusControl := Value;
  if Value <> nil then Value.FreeNotification(Self);
end;

procedure TCustomLabel.SetShowAccelChar(Value: Boolean);
begin
  if FShowAccelChar <> Value then
  begin
    FShowAccelChar := Value;
    Invalidate;
  end;
end;

procedure TCustomLabel.SetTransparent(Value: Boolean);
begin
  if Transparent <> Value then
  begin
    if Value then
      ControlStyle := ControlStyle - [csOpaque] else
      ControlStyle := ControlStyle + [csOpaque];
    Invalidate;
  end;
end;

procedure TCustomLabel.SetLayout(Value: TTextLayout);
begin
  if FLayout <> Value then
  begin
    FLayout := Value;
    Invalidate;
  end;
end;

procedure TCustomLabel.SetWordWrap(Value: Boolean);
begin
  if FWordWrap <> Value then
  begin
    FWordWrap := Value;
    AdjustBounds;
    Invalidate;
  end;
end;

procedure TCustomLabel.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FFocusControl) then
    FFocusControl := nil;
end;

procedure TCustomLabel.CMTextChanged(var Message: TMessage);
begin
  Invalidate;
  AdjustBounds;
end;

procedure TCustomLabel.CMFontChanged(var Message: TMessage);
begin
  inherited;
  AdjustBounds;
end;

procedure TCustomLabel.CMDialogChar(var Message: TCMDialogChar);
begin
  if (FFocusControl <> nil) and Enabled and ShowAccelChar and
    IsAccel(Message.CharCode, Caption) then
    with FFocusControl do
      if CanFocus then
      begin
        SetFocus;
        Message.Result := 1;
      end;
end;

{ TCustomEdit }

constructor TCustomEdit.Create(AOwner: TComponent);
const
  EditStyle = [csClickEvents, csSetCaption, csDoubleClicks, csFixedHeight];
begin
  inherited Create(AOwner);
  if NewStyleControls then
    ControlStyle := EditStyle else
    ControlStyle := EditStyle + [csFramed];
  Width := 121;
  Height := 25;
  TabStop := True;
  ParentColor := False;
  FBorderStyle := bsSingle;
  FAutoSize := True;
  FAutoSelect := True;
  FHideSelection := True;
  AdjustHeight;
end;

procedure TCustomEdit.DoSetMaxLength(Value: Integer);
begin
  SendMessage(Handle, EM_LIMITTEXT, Value, 0)
end;

procedure TCustomEdit.SetAutoSize(Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    UpdateHeight;
  end;
end;

procedure TCustomEdit.SetBorderStyle(Value: TBorderStyle);
begin
  if FBorderStyle <> Value then
  begin
    FBorderStyle := Value;
    UpdateHeight;
    RecreateWnd;
  end;
end;

procedure TCustomEdit.SetCharCase(Value: TEditCharCase);
begin
  if FCharCase <> Value then
  begin
    FCharCase := Value;
    RecreateWnd;
  end;
end;

procedure TCustomEdit.SetHideSelection(Value: Boolean);
begin
  if FHideSelection <> Value then
  begin
    FHideSelection := Value;
    RecreateWnd;
  end;
end;

procedure TCustomEdit.SetMaxLength(Value: Integer);
begin
  if FMaxLength <> Value then
  begin
    FMaxLength := Value;
    if HandleAllocated then DoSetMaxLength(Value);
  end;
end;

procedure TCustomEdit.SetOEMConvert(Value: Boolean);
begin
  if FOEMConvert <> Value then
  begin
    FOEMConvert := Value;
    RecreateWnd;
  end;
end;

function TCustomEdit.GetModified: Boolean;
begin
  Result := FModified;
  if HandleAllocated then Result := SendMessage(Handle, EM_GETMODIFY, 0, 0) <> 0;
end;

function TCustomEdit.GetCanUndo: Boolean;
begin
  Result := False;
  if HandleAllocated then Result := SendMessage(Handle, EM_CANUNDO, 0, 0) <> 0;
end;

procedure TCustomEdit.SetModified(Value: Boolean);
begin
  if HandleAllocated then
    SendMessage(Handle, EM_SETMODIFY, Byte(Value), 0) else
    FModified := Value;
end;

procedure TCustomEdit.SetPasswordChar(Value: Char);
begin
  if FPasswordChar <> Value then
  begin
    FPasswordChar := Value;
    if HandleAllocated then
    begin
      SendMessage(Handle, EM_SETPASSWORDCHAR, Ord(FPasswordChar), 0);
      SetTextBuf(PChar(Text));
    end;
  end;
end;

procedure TCustomEdit.SetReadOnly(Value: Boolean);
begin
  if FReadOnly <> Value then
  begin
    FReadOnly := Value;
    if HandleAllocated then
      SendMessage(Handle, EM_SETREADONLY, Ord(Value), 0);
  end;
end;

function TCustomEdit.GetSelStart: Integer;
begin
  SendMessage(Handle, EM_GETSEL, Longint(@Result), 0);
end;

procedure TCustomEdit.SetSelStart(Value: Integer);
begin
  SendMessage(Handle, EM_SETSEL, Value, Value);
end;

function TCustomEdit.GetSelLength: Integer;
var
  Selection: TSelection;
begin
  SendMessage(Handle, EM_GETSEL, Longint(@Selection.StartPos), Longint(@Selection.EndPos));
  Result := Selection.EndPos - Selection.StartPos;
end;

procedure TCustomEdit.SetSelLength(Value: Integer);
var
  Selection: TSelection;
begin
  SendMessage(Handle, EM_GETSEL, Longint(@Selection.StartPos), Longint(@Selection.EndPos));
  Selection.EndPos := Selection.StartPos + Value;
  SendMessage(Handle, EM_SETSEL, Selection.StartPos, Selection.EndPos);
  SendMessage(Handle, EM_SCROLLCARET, 0,0);
end;

procedure TCustomEdit.Clear;
begin
  SetWindowText(Handle, '');
end;

procedure TCustomEdit.ClearSelection;
begin
  SendMessage(Handle, WM_CLEAR, 0, 0);
end;

procedure TCustomEdit.CopyToClipboard;
begin
  SendMessage(Handle, WM_COPY, 0, 0);
end;

procedure TCustomEdit.CutToClipboard;
begin
  SendMessage(Handle, WM_CUT, 0, 0);
end;

procedure TCustomEdit.PasteFromClipboard;
begin
  SendMessage(Handle, WM_PASTE, 0, 0);
end;

procedure TCustomEdit.Undo;
begin
  SendMessage(Handle, WM_UNDO, 0, 0);
end;

procedure TCustomEdit.ClearUndo;
begin
  SendMessage(Handle, EM_EMPTYUNDOBUFFER, 0, 0);
end;

procedure TCustomEdit.SelectAll;
begin
  SendMessage(Handle, EM_SETSEL, 0, -1);
end;

function TCustomEdit.GetSelTextBuf(Buffer: PChar; BufSize: Integer): Integer;
var
  P: PChar;
  StartPos: Integer;
begin
  StartPos := GetSelStart;
  Result := GetSelLength;
  P := StrAlloc(GetTextLen + 1);
  try
    GetTextBuf(P, StrBufSize(P));
    if Result >= BufSize then Result := BufSize - 1;
    StrLCopy(Buffer, P + StartPos, Result);
  finally
    StrDispose(P);
  end;
end;

procedure TCustomEdit.SetSelTextBuf(Buffer: PChar);
begin
  SendMessage(Handle, EM_REPLACESEL, 0, LongInt(Buffer));
end;

function TCustomEdit.GetSelText: string;
var
  P: PChar;
  SelStart, Len: Integer;
begin
  SelStart := GetSelStart;
  Len := GetSelLength;
  SetString(Result, PChar(nil), Len);
  if Len <> 0 then
  begin
    P := StrAlloc(GetTextLen + 1);
    try
      GetTextBuf(P, StrBufSize(P));
      Move(P[SelStart], Pointer(Result)^, Len);
    finally
      StrDispose(P);
    end;
  end;
end;

procedure TCustomEdit.SetSelText(const Value: String);
begin
  SendMessage(Handle, EM_REPLACESEL, 0, Longint(PChar(Value)));
end;

procedure TCustomEdit.CreateParams(var Params: TCreateParams);
const
  Passwords: array[Boolean] of DWORD = (0, ES_PASSWORD);
  ReadOnlys: array[Boolean] of DWORD = (0, ES_READONLY);
  CharCases: array[TEditCharCase] of DWORD = (0, ES_UPPERCASE, ES_LOWERCASE);
  HideSelections: array[Boolean] of DWORD = (ES_NOHIDESEL, 0);
  OEMConverts: array[Boolean] of DWORD = (0, ES_OEMCONVERT);
begin
  inherited CreateParams(Params);
  CreateSubClass(Params, 'EDIT');
  with Params do
  begin
    Style := Style or (ES_AUTOHSCROLL or ES_AUTOVSCROLL) or
      BorderStyles[FBorderStyle] or Passwords[FPasswordChar <> #0] or
      ReadOnlys[FReadOnly] or CharCases[FCharCase] or
      HideSelections[FHideSelection] or OEMConverts[FOEMConvert];
    if NewStyleControls and Ctl3D and (FBorderStyle = bsSingle) then
    begin
      Style := Style and not WS_BORDER;
      ExStyle := ExStyle or WS_EX_CLIENTEDGE;
    end;
  end;
end;

procedure TCustomEdit.CreateWindowHandle(const Params: TCreateParams);
var
  P: TCreateParams;
begin
  if SysLocale.FarEast and (Win32Platform <> VER_PLATFORM_WIN32_NT) and
    ((Params.Style and ES_READONLY) <> 0) then
  begin
    // Work around Far East Win95 API/IME bug.
    P := Params;
    P.Style := P.Style and (not ES_READONLY);
    inherited CreateWindowHandle(P);
    if WindowHandle <> 0 then
      SendMessage(WindowHandle, EM_SETREADONLY, Ord(True), 0);
  end
  else
    inherited CreateWindowHandle(Params);
end;

procedure TCustomEdit.CreateWnd;
begin
  FCreating := True;
  try
    inherited CreateWnd;
  finally
    FCreating := False;
  end;
  DoSetMaxLength(FMaxLength);
  Modified := FModified;
  if FPasswordChar <> #0 then
    SendMessage(Handle, EM_SETPASSWORDCHAR, Ord(FPasswordChar), 0);
  UpdateHeight;
end;

procedure TCustomEdit.DestroyWnd;
begin
  FModified := Modified;
  inherited DestroyWnd;
end;

procedure TCustomEdit.UpdateHeight;
begin
  if FAutoSize and (BorderStyle = bsSingle) then
  begin
    ControlStyle := ControlStyle + [csFixedHeight];
    AdjustHeight;
  end else
    ControlStyle := ControlStyle - [csFixedHeight];
end;

procedure TCustomEdit.AdjustHeight;
var
  DC: HDC;
  SaveFont: HFont;
  I: Integer;
  SysMetrics, Metrics: TTextMetric;
begin
  DC := GetDC(0);
  GetTextMetrics(DC, SysMetrics);
  SaveFont := SelectObject(DC, Font.Handle);
  GetTextMetrics(DC, Metrics);
  SelectObject(DC, SaveFont);
  ReleaseDC(0, DC);
  if NewStyleControls then
  begin
    if Ctl3D then I := 8 else I := 6;
    I := GetSystemMetrics(SM_CYBORDER) * I;
  end else
  begin
    I := SysMetrics.tmHeight;
    if I > Metrics.tmHeight then I := Metrics.tmHeight;
    I := I div 4 + GetSystemMetrics(SM_CYBORDER) * 4;
  end;
  Height := Metrics.tmHeight + I;
end;

procedure TCustomEdit.Change;
begin
  inherited Changed;
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure TCustomEdit.DefaultHandler(var Message);
begin
  case TMessage(Message).Msg of
    WM_SETFOCUS:
      if (Win32Platform = VER_PLATFORM_WIN32_WINDOWS) and
        not IsWindow(TWMSetFocus(Message).FocusedWnd) then
        TWMSetFocus(Message).FocusedWnd := 0;
  end;
  inherited;
end;

procedure TCustomEdit.WMSetFont(var Message: TWMSetFont);
begin
  inherited;
  if NewStyleControls and
    (GetWindowLong(Handle, GWL_STYLE) and ES_MULTILINE = 0) then
    SendMessage(Handle, EM_SETMARGINS, EC_LEFTMARGIN or EC_RIGHTMARGIN, 0);
end;

procedure TCustomEdit.CMCtl3DChanged(var Message: TMessage);
begin
  if NewStyleControls and (FBorderStyle = bsSingle) then
  begin
    UpdateHeight;
    RecreateWnd;
  end;
  inherited;
end;

procedure TCustomEdit.CMFontChanged(var Message: TMessage);
begin
  inherited;
  if (csFixedHeight in ControlStyle) and not ((csDesigning in
    ComponentState) and (csLoading in ComponentState)) then AdjustHeight;
end;

procedure TCustomEdit.CNCommand(var Message: TWMCommand);
begin
  if (Message.NotifyCode = EN_CHANGE) and not FCreating then Change;
end;

procedure TCustomEdit.CMEnter(var Message: TCMGotFocus);
begin
  if FAutoSelect and not (csLButtonDown in ControlState) and
    (GetWindowLong(Handle, GWL_STYLE) and ES_MULTILINE = 0) then SelectAll;
  inherited;
end;

procedure TCustomEdit.CMTextChanged(var Message: TMessage);
begin
  inherited;
  if not HandleAllocated or (GetWindowLong(Handle, GWL_STYLE) and
    ES_MULTILINE <> 0) then Change;
end;

{ TMemoStrings }

function TMemoStrings.GetCount: Integer;
begin
  Result := 0;
  if Memo.HandleAllocated then
  begin
    Result := SendMessage(Memo.Handle, EM_GETLINECOUNT, 0, 0);
    if SendMessage(Memo.Handle, EM_LINELENGTH, SendMessage(Memo.Handle,
      EM_LINEINDEX, Result - 1, 0), 0) = 0 then Dec(Result);
  end;
end;

function TMemoStrings.Get(Index: Integer): string;
var
  Text: array[0..4095] of Char;
begin
  Word((@Text)^) := SizeOf(Text);
  SetString(Result, Text, SendMessage(Memo.Handle, EM_GETLINE, Index,
    Longint(@Text)));
end;

procedure TMemoStrings.Put(Index: Integer; const S: string);
var
  SelStart: Integer;
begin
  SelStart := SendMessage(Memo.Handle, EM_LINEINDEX, Index, 0);
  if SelStart >= 0 then
  begin
    SendMessage(Memo.Handle, EM_SETSEL, SelStart, SelStart +
      SendMessage(Memo.Handle, EM_LINELENGTH, SelStart, 0));
    SendMessage(Memo.Handle, EM_REPLACESEL, 0, Longint(PChar(S)));
  end;
end;

procedure TMemoStrings.Insert(Index: Integer; const S: string);
var
  SelStart, LineLen: Integer;
  Line: string;
begin
  if Index >= 0 then
  begin
    SelStart := SendMessage(Memo.Handle, EM_LINEINDEX, Index, 0);
    if SelStart >= 0 then Line := S + #13#10 else
    begin
      SelStart := SendMessage(Memo.Handle, EM_LINEINDEX, Index - 1, 0);
      if SelStart < 0 then Exit;
      LineLen := SendMessage(Memo.Handle, EM_LINELENGTH, SelStart, 0);
      if LineLen = 0 then Exit;
      Inc(SelStart, LineLen);
      Line := #13#10 + s;
    end;
    SendMessage(Memo.Handle, EM_SETSEL, SelStart, SelStart);
    SendMessage(Memo.Handle, EM_REPLACESEL, 0, Longint(PChar(Line)));
  end;
end;

procedure TMemoStrings.Delete(Index: Integer);
const
  Empty: PChar = '';
var
  SelStart, SelEnd: Integer;
begin
  SelStart := SendMessage(Memo.Handle, EM_LINEINDEX, Index, 0);
  if SelStart >= 0 then
  begin
    SelEnd := SendMessage(Memo.Handle, EM_LINEINDEX, Index + 1, 0);
    if SelEnd < 0 then SelEnd := SelStart +
      SendMessage(Memo.Handle, EM_LINELENGTH, SelStart, 0);
    SendMessage(Memo.Handle, EM_SETSEL, SelStart, SelEnd);
    SendMessage(Memo.Handle, EM_REPLACESEL, 0, Longint(Empty));
  end;
end;

procedure TMemoStrings.Clear;
begin
  Memo.Clear;
end;

procedure TMemoStrings.SetUpdateState(Updating: Boolean);
begin
  if Memo.HandleAllocated then
  begin
    SendMessage(Memo.Handle, WM_SETREDRAW, Ord(not Updating), 0);
    if not Updating then
    begin   // WM_SETREDRAW causes visibility side effects in memo controls
      Memo.Perform(CM_SHOWINGCHANGED,0,0); // This reasserts the visibility we want
      Memo.Refresh;
    end;
  end;
end;

function TMemoStrings.GetTextStr: string;
begin
  Result := Memo.Text;
end;

procedure TMemoStrings.SetTextStr(const Value: string);
var
  NewText: string;
begin
  NewText := AdjustLineBreaks(Value);
  if (Length(NewText) <> Memo.GetTextLen) or (NewText <> Memo.Text) then
  begin
    if SendMessage(Memo.Handle, WM_SETTEXT, 0, Longint(NewText)) = 0 then
      raise EInvalidOperation.Create(SInvalidMemoSize);
    Memo.Perform(CM_TEXTCHANGED, 0, 0);
  end;
end;

{ TCustomMemo }

constructor TCustomMemo.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Width := 185;
  Height := 89;
  AutoSize := False;
  FWordWrap := True;
  FWantReturns := True;
  FLines := TMemoStrings.Create;
  TMemoStrings(FLines).Memo := Self;
end;

destructor TCustomMemo.Destroy;
begin
  FLines.Free;
  inherited Destroy;
end;

procedure TCustomMemo.CreateParams(var Params: TCreateParams);
const
  Alignments: array[Boolean, TAlignment] of DWORD =
    ((ES_LEFT, ES_RIGHT, ES_CENTER),(ES_RIGHT, ES_LEFT, ES_CENTER));
  ScrollBar: array[TScrollStyle] of DWORD = (0, WS_HSCROLL, WS_VSCROLL,
    WS_HSCROLL or WS_VSCROLL);
  WordWraps: array[Boolean] of DWORD = (0, ES_AUTOHSCROLL);
begin
  inherited CreateParams(Params);
  with Params do
  begin
    Style := Style and not WordWraps[FWordWrap] or ES_MULTILINE or
      Alignments[UseRightToLeftAlignment, FAlignment] or ScrollBar[FScrollBars];
  end;
end;

procedure TCustomMemo.CreateWindowHandle(const Params: TCreateParams);
begin
  with Params do
  begin
    if SysLocale.FarEast and (Win32Platform <> VER_PLATFORM_WIN32_NT) and
      ((Style and ES_READONLY) <> 0) then
    begin
      // Work around Far East Win95 API/IME bug.
      WindowHandle := CreateWindowEx(ExStyle, WinClassName, '',
        Style and (not ES_READONLY),
        X, Y, Width, Height, WndParent, 0, HInstance, Param);
      if WindowHandle <> 0 then
        SendMessage(WindowHandle, EM_SETREADONLY, Ord(True), 0);
    end
    else
      WindowHandle := CreateWindowEx(ExStyle, WinClassName, '', Style,
        X, Y, Width, Height, WndParent, 0, HInstance, Param);
    SendMessage(WindowHandle, WM_SETTEXT, 0, Longint(Caption));
  end;
end;

function TCustomMemo.GetCaretPos: TPoint;
begin
  Result.X := LongRec(SendMessage(Handle, EM_GETSEL, 0, 0)).Hi;
  Result.Y := SendMessage(Handle, EM_LINEFROMCHAR, Result.X, 0);
  Result.X := Result.X - SendMessage(Handle, EM_LINEINDEX, -1, 0);
end;

function TCustomMemo.GetControlsAlignment: TAlignment;
begin
  Result := FAlignment;
end;

procedure TCustomMemo.Loaded;
begin
  inherited Loaded;
  Modified := False;
end;

procedure TCustomMemo.SetAlignment(Value: TAlignment);
begin
  if FAlignment <> Value then
  begin
    FAlignment := Value;
    RecreateWnd;
  end;
end;

procedure TCustomMemo.SetLines(Value: TStrings);
begin
  FLines.Assign(Value);
end;

procedure TCustomMemo.SetScrollBars(Value: TScrollStyle);
begin
  if FScrollBars <> Value then
  begin
    FScrollBars := Value;
    RecreateWnd;
  end;
end;

procedure TCustomMemo.SetWordWrap(Value: Boolean);
begin
  if Value <> FWordWrap then
  begin
    FWordWrap := Value;
    RecreateWnd;
  end;
end;

procedure TCustomMemo.WMGetDlgCode(var Message: TWMGetDlgCode);
begin
  inherited;
  if FWantTabs then Message.Result := Message.Result or DLGC_WANTTAB
  else Message.Result := Message.Result and not DLGC_WANTTAB;
  if not FWantReturns then
    Message.Result := Message.Result and not DLGC_WANTALLKEYS;
end;

procedure TCustomMemo.WMNCDestroy(var Message: TWMNCDestroy);
begin
  inherited;
end;

procedure TCustomMemo.KeyPress(var Key: Char);
begin
  inherited KeyPress(Key);
  if (Key = Char(VK_RETURN)) and not FWantReturns then Key := #0;
end;

{ TComboBoxStrings }

function TComboBoxStrings.GetCount: Integer;
begin
  Result := SendMessage(ComboBox.Handle, CB_GETCOUNT, 0, 0);
end;

function TComboBoxStrings.Get(Index: Integer): string;
var
  Text: array[0..4095] of Char;
  Len: Integer;
begin
  Len := SendMessage(ComboBox.Handle, CB_GETLBTEXT, Index, Longint(@Text));
  if Len = CB_ERR then Len := 0;
  SetString(Result, Text, Len);
end;

function TComboBoxStrings.GetObject(Index: Integer): TObject;
begin
  Result := TObject(SendMessage(ComboBox.Handle, CB_GETITEMDATA, Index, 0));
  if Longint(Result) = CB_ERR then
    Error(SListIndexError, Index);
end;

procedure TComboBoxStrings.PutObject(Index: Integer; AObject: TObject);
begin
  SendMessage(ComboBox.Handle, CB_SETITEMDATA, Index, Longint(AObject));
end;

function TComboBoxStrings.Add(const S: string): Integer;
begin
  Result := SendMessage(ComboBox.Handle, CB_ADDSTRING, 0, Longint(PChar(S)));
  if Result < 0 then
    raise EOutOfResources.Create(SInsertLineError);
end;

procedure TComboBoxStrings.Insert(Index: Integer; const S: string);
begin
  if SendMessage(ComboBox.Handle, CB_INSERTSTRING, Index,
    Longint(PChar(S))) < 0 then
    raise EOutOfResources.Create(SInsertLineError);
end;

procedure TComboBoxStrings.Delete(Index: Integer);
begin
  SendMessage(ComboBox.Handle, CB_DELETESTRING, Index, 0);
end;

procedure TComboBoxStrings.Clear;
var
  S: string;
begin
  S := ComboBox.Text;
  SendMessage(ComboBox.Handle, CB_RESETCONTENT, 0, 0);
  ComboBox.Text := S;
  ComboBox.Update;
end;

procedure TComboBoxStrings.SetUpdateState(Updating: Boolean);
begin
  SendMessage(ComboBox.Handle, WM_SETREDRAW, Ord(not Updating), 0);
  if not Updating then ComboBox.Refresh;
end;

function TComboBoxStrings.IndexOf(const S: string): Integer;
begin
  Result := SendMessage(ComboBox.Handle, CB_FINDSTRINGEXACT, -1, LongInt(PChar(S)));
end;

{ TCustomComboBox }

constructor TCustomComboBox.Create(AOwner: TComponent);
const
  ComboBoxStyle = [csCaptureMouse, csSetCaption, csDoubleClicks,
    csFixedHeight, csReflector];
begin
  inherited Create(AOwner);
  if NewStyleControls then
    ControlStyle := ComboBoxStyle else
    ControlStyle := ComboBoxStyle + [csFramed];
  Width := 145;
  Height := 25;
  TabStop := True;
  ParentColor := False;
  FItems := TComboBoxStrings.Create;
  TComboBoxStrings(FItems).ComboBox := Self;
  FCanvas := TControlCanvas.Create;
  FItemHeight := 16;
  FStyle := csDropDown;
  FEditInstance := MakeObjectInstance(EditWndProc);
  FListInstance := MakeObjectInstance(ListWndProc);
  FDropDownCount := 8;
  FSaveIndex := -1;
end;

destructor TCustomComboBox.Destroy;
begin
  if HandleAllocated then DestroyWindowHandle;
  FreeObjectInstance(FListInstance);
  FreeObjectInstance(FEditInstance);
  FCanvas.Free;
  FItems.Free;
  FSaveItems.Free;
  inherited Destroy;
end;

procedure TCustomComboBox.Clear;
begin
  SetTextBuf('');
  FItems.Clear;
  FSaveIndex := -1;
end;

procedure TCustomComboBox.SelectAll;
begin
  SendMessage(Handle, CB_SETEDITSEL, 0, Integer($FFFF0000));
end;

function TCustomComboBox.GetDroppedDown: Boolean;
begin
  Result := LongBool(SendMessage(Handle, CB_GETDROPPEDSTATE, 0, 0));
end;

procedure TCustomComboBox.SetDroppedDown(Value: Boolean);
var
  R: TRect;
begin
  SendMessage(Handle, CB_SHOWDROPDOWN, Longint(Value), 0);
  R := ClientRect;
  InvalidateRect(Handle, @R, True);
end;

function TCustomComboBox.GetItemIndex: Integer;
begin
  Result := SendMessage(Handle, CB_GETCURSEL, 0, 0);
end;

procedure TCustomComboBox.SetItemIndex(Value: Integer);
begin
  if GetItemIndex <> Value then
    SendMessage(Handle, CB_SETCURSEL, Value, 0);
end;

function TCustomComboBox.GetSelStart: Integer;
begin
  SendMessage(Handle, CB_GETEDITSEL, Longint(@Result), 0);
end;

procedure TCustomComboBox.SetSelStart(Value: Integer);
var
  Selection: TSelection;
begin
  Selection.StartPos := Value;
  Selection.EndPos := Value;
  SendMessage(Handle, CB_SETEDITSEL, 0, MakeLParam(Selection.StartPos,
    Selection.EndPos));
end;

function TCustomComboBox.GetSelLength: Integer;
var
  Selection: TSelection;
begin
  SendMessage(Handle, CB_GETEDITSEL, Longint(@Selection.StartPos),
    Longint(@Selection.EndPos));
  Result := Selection.EndPos - Selection.StartPos;
end;

procedure TCustomComboBox.SetSelLength(Value: Integer);
var
  Selection: TSelection;
begin
  SendMessage(Handle, CB_GETEDITSEL, Longint(@Selection.StartPos),
    Longint(@Selection.EndPos));
  Selection.EndPos := Selection.StartPos + Value;
  SendMessage(Handle, CB_SETEDITSEL, 0, MakeLParam(Selection.StartPos,
    Selection.EndPos));
end;

function TCustomComboBox.GetSelText: string;
begin
  Result := '';
  if FStyle < csDropDownList then
    Result := Copy(Text, GetSelStart + 1, GetSelLength);
end;

procedure TCustomComboBox.SetSelText(const Value: string);
begin
  if FStyle < csDropDownList then
  begin
    HandleNeeded;
    SendMessage(FEditHandle, EM_REPLACESEL, 0, Longint(PChar(Value)));
  end;
end;

procedure TCustomComboBox.SetMaxLength(Value: Integer);
begin
  if Value < 0 then Value := 0;
  if FMaxLength <> Value then
  begin
    FMaxLength := Value;
    if HandleAllocated then SendMessage(Handle, CB_LIMITTEXT, Value, 0);
  end;
end;

procedure TCustomComboBox.SetSorted(Value: Boolean);
begin
  if FSorted <> Value then
  begin
    FSorted := Value;
    RecreateWnd;
  end;
end;

procedure TCustomComboBox.SetStyle(Value: TComboBoxStyle);
begin
  if FStyle <> Value then
  begin
    FStyle := Value;
    if Value = csSimple then
      ControlStyle := ControlStyle - [csFixedHeight] else
      ControlStyle := ControlStyle + [csFixedHeight];
    RecreateWnd;
  end;
end;

function TCustomComboBox.GetItemHeight: Integer;
begin
  if FStyle in [csOwnerDrawFixed, csOwnerDrawVariable] then
    Result := FItemHeight else
    Result := Perform(CB_GETITEMHEIGHT, 0, 0);
end;

procedure TCustomComboBox.SetItemHeight(Value: Integer);
begin
  if Value > 0 then
  begin
    FItemHeight := Value;
    RecreateWnd;
  end;
end;

procedure TCustomComboBox.SetItems(Value: TStrings);
begin
  Items.Assign(Value);
end;

procedure TCustomComboBox.CreateParams(var Params: TCreateParams);
const
  ComboBoxStyles: array[TComboBoxStyle] of DWORD = (
    CBS_DROPDOWN, CBS_SIMPLE, CBS_DROPDOWNLIST,
    CBS_DROPDOWNLIST or CBS_OWNERDRAWFIXED,
    CBS_DROPDOWNLIST or CBS_OWNERDRAWVARIABLE);
  CharCases: array[TEditCharCase] of DWORD = (0, CBS_UPPERCASE, CBS_LOWERCASE);
  Sorts: array[Boolean] of DWORD = (0, CBS_SORT);
begin
  inherited CreateParams(Params);
  CreateSubClass(Params, 'COMBOBOX');
  with Params do
  begin
    Style := Style or (WS_VSCROLL or CBS_HASSTRINGS or CBS_AUTOHSCROLL) or
      ComboBoxStyles[FStyle] or Sorts[FSorted] or CharCases[FCharCase];
  end;
end;

procedure TCustomComboBox.CreateWnd;
var
  ChildHandle: THandle;
begin
  inherited CreateWnd;
  SendMessage(Handle, CB_LIMITTEXT, FMaxLength, 0);
  if FSaveItems <> nil then
  begin
    FItems.Assign(FSaveItems);
    FSaveItems.Free;
    FSaveItems := nil;
    if FSaveIndex <> -1 then
    begin
      if FItems.Count < FSaveIndex then FSaveIndex := Items.Count;
      SendMessage(Handle, CB_SETCURSEL, FSaveIndex, 0);
    end;
  end;
  FEditHandle := 0;
  FListHandle := 0;
  if FStyle in [csDropDown, csSimple] then
  begin
    ChildHandle := GetWindow(GetComboControl, GW_CHILD);
    if ChildHandle <> 0 then
    begin
      if FStyle = csSimple then
      begin
        FListHandle := ChildHandle;
        FDefListProc := Pointer(GetWindowLong(FListHandle, GWL_WNDPROC));
        SetWindowLong(FListHandle, GWL_WNDPROC, Longint(FListInstance));
        ChildHandle := GetWindow(ChildHandle, GW_HWNDNEXT);
      end;
      FEditHandle := ChildHandle;
      FDefEditProc := Pointer(GetWindowLong(FEditHandle, GWL_WNDPROC));
      SetWindowLong(FEditHandle, GWL_WNDPROC, Longint(FEditInstance));
    end;
  end;
  if NewStyleControls and (FEditHandle <> 0) then
    SendMessage(FEditHandle, EM_SETMARGINS, EC_LEFTMARGIN or EC_RIGHTMARGIN, 0);
end;

procedure TCustomComboBox.DestroyWnd;
begin
  if FItems.Count > 0 then
  begin
    FSaveIndex := ItemIndex;
    FSaveItems := TStringList.Create;
    FSaveItems.Assign(FItems);
  end;
  inherited DestroyWnd;
end;

procedure TCustomComboBox.WMCreate(var Message: TWMCreate);
begin
  inherited;
  if WindowText <> nil then
    SetWindowText(Handle, WindowText);
end;

procedure TCustomComboBox.WMEraseBkgnd(var Message: TWMEraseBkgnd);
begin
  if Style = csSimple then
  begin
    FillRect(Message.DC, ClientRect, Parent.Brush.Handle);
    Message.Result := 1;
  end
  else
    DefaultHandler(Message);
end;

procedure TCustomComboBox.WMDrawItem(var Message: TWMDrawItem);
begin
  DefaultHandler(Message);
end;

procedure TCustomComboBox.WMMeasureItem(var Message: TWMMeasureItem);
begin
  DefaultHandler(Message);
end;

procedure TCustomComboBox.WMDeleteItem(var Message: TWMDeleteItem);
begin
  DefaultHandler(Message);
end;

procedure TCustomComboBox.WMGetDlgCode(var Message: TWMGetDlgCode);
begin
  inherited;
  if DroppedDown then Message.Result := Message.Result or DLGC_WANTALLKEYS;
end;

procedure TCustomComboBox.CMCancelMode(var Message: TCMCancelMode);
begin
  if Message.Sender <> Self then Perform(CB_SHOWDROPDOWN, 0, 0);
end;

procedure TCustomComboBox.CMCtl3DChanged(var Message: TMessage);
begin
  if NewStyleControls then RecreateWnd;
  inherited;
end;

procedure TCustomComboBox.CMParentColorChanged(var Message: TMessage);
begin
  inherited;
  if not NewStyleControls and (Style < csDropDownList) then Invalidate;
end;

procedure TCustomComboBox.EditWndProc(var Message: TMessage);
var
  P: TPoint;
  Form: TCustomForm;
begin
  if Message.Msg = WM_SYSCOMMAND then
  begin
    WndProc(Message);
    Exit;
  end
  else if (Message.Msg >= WM_KEYFIRST) and (Message.Msg <= WM_KEYLAST) then
  begin
    Form := GetParentForm(Self);
    if (Form <> nil) and Form.WantChildKey(Self, Message) then Exit;
  end;
  ComboWndProc(Message, FEditHandle, FDefEditProc);
  case Message.Msg of
    WM_LBUTTONDOWN, WM_LBUTTONDBLCLK:
      begin
        if DragMode = dmAutomatic then
        begin
          GetCursorPos(P);
          P := ScreenToClient(P);
          SendMessage(FEditHandle, WM_LBUTTONUP, 0,Longint(PointToSmallPoint(P)));
          BeginDrag(False);
        end;
      end;
    WM_SETFONT:
      if NewStyleControls then
        SendMessage(FEditHandle, EM_SETMARGINS, EC_LEFTMARGIN or EC_RIGHTMARGIN, 0);
  end;
end;

procedure TCustomComboBox.ListWndProc(var Message: TMessage);
begin
  ComboWndProc(Message, FListHandle, FDefListProc);
end;

function TCustomComboBox.GetComboControl: HWND;
begin
  Result := Handle;
end;

procedure TCustomComboBox.SetCharCase(Value: TEditCharCase);
begin
  if FCharCase <> Value then
  begin
    FCharCase := Value;
    RecreateWnd;
  end;
end;

procedure TCustomComboBox.ComboWndProc(var Message: TMessage; ComboWnd: HWnd;
  ComboProc: Pointer);
var
  Point: TPoint;
  Form: TCustomForm;
begin
  try
    with Message do
    begin
      case Msg of
        WM_SETFOCUS:
          begin
            Form := GetParentForm(Self);
            if (Form <> nil) and not Form.SetFocusedControl(Self) then Exit;
          end;
        WM_KILLFOCUS:
          if csFocusing in ControlState then Exit;
        WM_KEYDOWN, WM_SYSKEYDOWN:
          if (ComboWnd <> FListHandle) and DoKeyDown(TWMKey(Message)) then
            Exit;
        WM_CHAR:
          begin
            if DoKeyPress(TWMKey(Message)) then Exit;
            if ((TWMKey(Message).CharCode = VK_RETURN) or
              (TWMKey(Message).CharCode = VK_ESCAPE)) and DroppedDown then
            begin
              DroppedDown := False;
              Exit;
            end;
          end;
        WM_KEYUP, WM_SYSKEYUP:
          if DoKeyUp(TWMKey(Message)) then Exit;
        WM_MOUSEMOVE: Application.HintMouseMessage(Self, Message);
        WM_RBUTTONUP:
          if HasPopup(Self) then
          begin
            with TWMRButtonUp(Message) do
            begin
              Point.X := Pos.X;
              Point.Y := Pos.Y;
              MapWindowPoints(ComboWnd, Handle, Point, 1);
              Pos.X := Point.X;
              Pos.Y := Point.Y;
            end;
            WndProc(Message);
            Exit;
          end;
        WM_GETDLGCODE:
          if DroppedDown then
          begin
            Result := DLGC_WANTALLKEYS;
            Exit;
          end;
        WM_NCHITTEST:
          if csDesigning in ComponentState then
          begin
            Result := HTTRANSPARENT;
            Exit;
          end;
        CN_KEYDOWN, CN_CHAR, CN_SYSKEYDOWN, CN_SYSCHAR:
          begin
            WndProc(Message);
            Exit;
          end;
      end;
      Result := CallWindowProc(ComboProc, ComboWnd, Msg, WParam, LParam);
      if (Msg = WM_LBUTTONDBLCLK) and (csDoubleClicks in ControlStyle) then
        DblClick;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TCustomComboBox.WndProc(var Message: TMessage);
begin
    {for auto drag mode, let listbox handle itself, instead of TControl}
  if not (csDesigning in ComponentState) and
     ((Message.Msg = WM_LBUTTONDOWN) or (Message.Msg = WM_LBUTTONDBLCLK)) and
     not Dragging then
  begin
    if DragMode = dmAutomatic then
    begin
      if IsControlMouseMsg(TWMMouse(Message)) then
        Exit;
      ControlState := ControlState + [csLButtonDown];
      Dispatch(Message);  {overrides TControl's BeginDrag}
      Exit;
    end;
  end;
  with Message do
    case Msg of
      WM_SIZE:
        { Prevent TWinControl from handling WM_SIZE when adjusting drop-down
          listbox size. }
        if FDroppingDown then
        begin
          DefaultHandler(Message);
          Exit;
        end;
      WM_CTLCOLORMSGBOX..WM_CTLCOLORSTATIC:
        begin
          SetTextColor(WParam, ColorToRGB(Font.Color));
          SetBkColor(WParam, ColorToRGB(Brush.Color));
          Result := Brush.Handle;
          Exit;
        end;
      CN_CTLCOLORMSGBOX..CN_CTLCOLORSTATIC:
        if not NewStyleControls and (Style < csDropDownList) then
        begin
          Result := Parent.Brush.Handle;
          Exit;
        end;
      WM_CHAR:
        begin
          if DoKeyPress(TWMKey(Message)) then Exit;
          if ((TWMKey(Message).CharCode = VK_RETURN) or
            (TWMKey(Message).CharCode = VK_ESCAPE)) and DroppedDown then
          begin
            DroppedDown := False;
            Exit;
          end;
        end;
    end;
  inherited WndProc(Message);
end;

procedure TCustomComboBox.AdjustDropDown;
var
  ItemCount: Integer;
begin
  ItemCount := FItems.Count;
  if ItemCount > DropDownCount then ItemCount := DropDownCount;
  if ItemCount < 1 then ItemCount := 1;
  FDroppingDown := True;
  try
    SetWindowPos(Handle, 0, 0, 0, Width, ItemHeight * ItemCount +
      Height + 2, SWP_NOMOVE + SWP_NOZORDER + SWP_NOACTIVATE + SWP_NOREDRAW +
      SWP_HIDEWINDOW);
  finally
    FDroppingDown := False;
  end;
  SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE +
    SWP_NOZORDER + SWP_NOACTIVATE + SWP_NOREDRAW + SWP_SHOWWINDOW);
end;

procedure TCustomComboBox.CNCommand(var Message: TWMCommand);
begin
  case Message.NotifyCode of
    CBN_DBLCLK:
      DblClick;
    CBN_EDITCHANGE:
      Change;
    CBN_DROPDOWN:
      begin
        FFocusChanged := False;
        DropDown;
        AdjustDropDown;
        if FFocusChanged then
        begin
          PostMessage(Handle, WM_CANCELMODE, 0, 0);
          if not FIsFocused then PostMessage(Handle, CB_SHOWDROPDOWN, 0, 0);
        end;
      end;
    CBN_SELCHANGE:
      begin
        Text := Items[ItemIndex];
        Click;
        Change;
      end;
    CBN_SETFOCUS:
      begin
        FIsFocused := True;
        FFocusChanged := True;
        SetIme;
      end;
    CBN_KILLFOCUS:
      begin
        FIsFocused := False;
        FFocusChanged := True;
        ResetIme;
      end;
  end;
end;

procedure TCustomComboBox.Change;
begin
  inherited Changed;
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure TCustomComboBox.DrawItem(Index: Integer; Rect: TRect;
  State: TOwnerDrawState);
begin
  TControlCanvas(FCanvas).UpdateTextFlags;
  if Assigned(FOnDrawItem) then FOnDrawItem(Self, Index, Rect, State)
  else
  begin
    FCanvas.FillRect(Rect);
    FCanvas.TextOut(Rect.Left + 2, Rect.Top, Items[Index]);
  end;
end;

procedure TCustomComboBox.DropDown;
begin
  if Assigned(FOnDropDown) then FOnDropDown(Self);
end;

procedure TCustomComboBox.MeasureItem(Index: Integer; var Height: Integer);
begin
  if Assigned(FOnMeasureItem) then FOnMeasureItem(Self, Index, Height)
end;

procedure TCustomComboBox.CNDrawItem(var Message: TWMDrawItem);
var
  State: TOwnerDrawState;
begin
  with Message.DrawItemStruct^ do
  begin
    State := TOwnerDrawState(LongRec(itemState).Lo);
    if itemState and ODS_COMBOBOXEDIT <> 0 then
      Include(State, odComboBoxEdit);
    if itemState and ODS_DEFAULT <> 0 then
      Include(State, odDefault);  
    FCanvas.Handle := hDC;
    FCanvas.Font := Font;
    FCanvas.Brush := Brush;
    if (Integer(itemID) >= 0) and (odSelected in State) then
    begin
      FCanvas.Brush.Color := clHighlight;
      FCanvas.Font.Color := clHighlightText
    end;
    if Integer(itemID) >= 0 then
      DrawItem(itemID, rcItem, State) else
      FCanvas.FillRect(rcItem);
    if odFocused in State then DrawFocusRect(hDC, rcItem);
    FCanvas.Handle := 0;
  end;
end;

procedure TCustomComboBox.CNMeasureItem(var Message: TWMMeasureItem);
begin
  with Message.MeasureItemStruct^ do
  begin
    itemHeight := FItemHeight;
    if FStyle = csOwnerDrawVariable then
      MeasureItem(itemID, Integer(itemHeight));
  end;
end;

procedure TCustomComboBox.WMLButtonDown(var Message: TWMLButtonDown);
var
  Form: TCustomForm;
begin
  if (DragMode = dmAutomatic) and (Style = csDropDownList) and
      (Message.XPos < (Width - GetSystemMetrics(SM_CXHSCROLL))) then
  begin
    SetFocus;
    BeginDrag(False);
    Exit;
  end;
  inherited;
  if MouseCapture then
  begin
    Form := GetParentForm(Self);
    if (Form <> nil) and (Form.ActiveControl <> Self) then
      MouseCapture := False;
  end;
end;

function TCustomComboBox.Focused: Boolean;
var
  FocusedWnd: HWND;
begin
  Result := False;
  if HandleAllocated then
  begin
    FocusedWnd := GetFocus;
    Result := (FocusedWnd = FEditHandle) or (FocusedWnd = FListHandle);
  end;
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

{ TButtonControl }

constructor TButtonControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  if SysLocale.FarEast and (Win32Platform = VER_PLATFORM_WIN32_NT) then
    ImeMode := imDisable;
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

function TButtonControl.GetChecked: Boolean;
begin
  Result := False;
end;

function TButtonControl.IsCheckedStored: Boolean;
begin
  Result := (ActionLink = nil) or not TButtonActionLink(ActionLink).IsCheckedLinked;
end;

procedure TButtonControl.SetChecked(Value: Boolean);
begin
end;

procedure TButtonControl.WndProc(var Message: TMessage);
begin
  case Message.Msg of
    WM_LBUTTONDOWN, WM_LBUTTONDBLCLK:
      if not (csDesigning in ComponentState) and not Focused then
      begin
        FClicksDisabled := True;
        Windows.SetFocus(Handle);
        FClicksDisabled := False;
        if not Focused then Exit;
      end;
    CN_COMMAND:
      if FClicksDisabled then Exit;
  end;
  inherited WndProc(Message);
end;

{ TButton }

constructor TButton.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csSetCaption, csOpaque, csDoubleClicks];
  Width := 75;
  Height := 25;
  TabStop := True;
end;

procedure TButton.Click;
var
  Form: TCustomForm;
begin
  Form := GetParentForm(Self);
  if Form <> nil then Form.ModalResult := ModalResult;
  inherited Click;
end;

function TButton.UseRightToLeftAlignment: Boolean;
begin
  Result := False;
end;

procedure TButton.SetButtonStyle(ADefault: Boolean);
const
  BS_MASK = $000F;
var
  Style: Word;
begin
  if HandleAllocated then
  begin
    if ADefault then Style := BS_DEFPUSHBUTTON else Style := BS_PUSHBUTTON;
    if GetWindowLong(Handle, GWL_STYLE) and BS_MASK <> Style then
      SendMessage(Handle, BM_SETSTYLE, Style, 1);
  end;
end;

procedure TButton.SetDefault(Value: Boolean);
var
  Form: TCustomForm;
begin
  FDefault := Value;
  if HandleAllocated then
  begin
    Form := GetParentForm(Self);
    if Form <> nil then
      Form.Perform(CM_FOCUSCHANGED, 0, Longint(Form.ActiveControl));
  end;
end;

procedure TButton.CreateParams(var Params: TCreateParams);
const
  ButtonStyles: array[Boolean] of DWORD = (BS_PUSHBUTTON, BS_DEFPUSHBUTTON);
begin
  inherited CreateParams(Params);
  CreateSubClass(Params, 'BUTTON');
  Params.Style := Params.Style or ButtonStyles[FDefault];
end;

procedure TButton.CreateWnd;
begin
  inherited CreateWnd;
  FActive := FDefault;
end;

procedure TButton.CNCommand(var Message: TWMCommand);
begin
  if Message.NotifyCode = BN_CLICKED then Click;
end;

procedure TButton.CMDialogKey(var Message: TCMDialogKey);
begin
  with Message do
    if  (((CharCode = VK_RETURN) and FActive) or
      ((CharCode = VK_ESCAPE) and FCancel)) and
      (KeyDataToShiftState(Message.KeyData) = []) and CanFocus then
    begin
      Click;
      Result := 1;
    end else
      inherited;
end;

procedure TButton.CMDialogChar(var Message: TCMDialogChar);
begin
  with Message do
    if IsAccel(CharCode, Caption) and CanFocus then
    begin
      Click;
      Result := 1;
    end else
      inherited;
end;

procedure TButton.CMFocusChanged(var Message: TCMFocusChanged);
begin
  with Message do
    if Sender is TButton then
      FActive := Sender = Self
    else
      FActive := FDefault;
  SetButtonStyle(FActive);
  inherited;
end;

procedure TButton.WMEraseBkgnd(var Message: TWMEraseBkgnd);
begin
  DefaultHandler(Message);
end;

{ TCustomCheckBox }

constructor TCustomCheckBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Width := 97;
  Height := 17;
  TabStop := True;
  ControlStyle := [csSetCaption, csDoubleClicks];
  FAlignment := taRightJustify;
end;

function TCustomCheckBox.GetControlsAlignment: TAlignment;
begin
  if not UseRightToLeftAlignment then
    Result := taRightJustify
  else
    if FAlignment = taRightJustify then
      Result := taLeftJustify
    else
      Result := taRightJustify;
end;

procedure TCustomCheckBox.Toggle;
begin
  case State of
    cbUnchecked:
      if AllowGrayed then State := cbGrayed else State := cbChecked;
    cbChecked: State := cbUnchecked;
    cbGrayed: State := cbChecked;
  end;
end;

procedure TCustomCheckBox.Click;
begin
  inherited Changed;
  inherited Click;
end;

function TCustomCheckBox.GetChecked: Boolean;
begin
  Result := State = cbChecked;
end;

procedure TCustomCheckBox.SetAlignment(Value: TLeftRight);
begin
  if FAlignment <> Value then
  begin
    FAlignment := Value;
    RecreateWnd;
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
    if HandleAllocated then
      SendMessage(Handle, BM_SETCHECK, Integer(FState), 0);
    if not ClicksDisabled then Click;
  end;
end;

procedure TCustomCheckBox.CreateParams(var Params: TCreateParams);
const
  Alignments: array[Boolean, TLeftRight] of DWORD =
    ((BS_LEFTTEXT, 0), (0, BS_LEFTTEXT));
begin
  inherited CreateParams(Params);
  CreateSubClass(Params, 'BUTTON');
  with Params do
  begin
    Style := Style or BS_3STATE or
      Alignments[UseRightToLeftAlignment, FAlignment];
    WindowClass.style := WindowClass.style and not (CS_HREDRAW or CS_VREDRAW);
  end;
end;

procedure TCustomCheckBox.CreateWnd;
begin
  inherited CreateWnd;
  SendMessage(Handle, BM_SETCHECK, Integer(FState), 0);
end;

procedure TCustomCheckBox.WMSize(var Message: TMessage);
begin
  inherited;
  Invalidate;
end;

procedure TCustomCheckBox.CMCtl3DChanged(var Message: TMessage);
begin
  RecreateWnd;
end;

procedure TCustomCheckBox.CMDialogChar(var Message: TCMDialogChar);
begin
  with Message do
    if IsAccel(CharCode, Caption) and CanFocus then
    begin
      SetFocus;
      if Focused then Toggle;
      Result := 1;
    end else
      inherited;
end;

procedure TCustomCheckBox.CNCommand(var Message: TWMCommand);
begin
  if Message.NotifyCode = BN_CLICKED then Toggle;
end;

{ TRadioButton }

constructor TRadioButton.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Width := 113;
  Height := 17;
  ControlStyle := [csSetCaption, csDoubleClicks];
  FAlignment := taRightJustify;
end;

function TRadioButton.GetChecked: Boolean;
begin
  Result := FChecked;
end;

function TRadioButton.GetControlsAlignment: TAlignment;
begin
  if not UseRightToLeftAlignment then
    Result := taRightJustify
  else
    if FAlignment = taRightJustify then
      Result := taLeftJustify
    else
      Result := taRightJustify;
end;

procedure TRadioButton.SetAlignment(Value: TLeftRight);
begin
  if FAlignment <> Value then
  begin
    FAlignment := Value;
    RecreateWnd;
  end;
end;

procedure TRadioButton.SetChecked(Value: Boolean);

  procedure TurnSiblingsOff;
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
  end;

begin
  if FChecked <> Value then
  begin
    FChecked := Value;
    TabStop := Value;
    if HandleAllocated then
      SendMessage(Handle, BM_SETCHECK, Integer(Checked), 0);
    if Value then
    begin
      TurnSiblingsOff;
      inherited Changed;
      if not ClicksDisabled then Click;
    end;
  end;
end;

procedure TRadioButton.CreateParams(var Params: TCreateParams);
const
  Alignments: array[Boolean, TLeftRight] of DWORD =
    ((BS_LEFTTEXT, 0), (0, BS_LEFTTEXT));
begin
  inherited CreateParams(Params);
  CreateSubClass(Params, 'BUTTON');
  with Params do
    Style := Style or BS_RADIOBUTTON or
      Alignments[UseRightToLeftAlignment, FAlignment];
end;

procedure TRadioButton.CreateWnd;
begin
  inherited CreateWnd;
  SendMessage(Handle, BM_SETCHECK, Integer(FChecked), 0);
end;

procedure TRadioButton.CMCtl3DChanged(var Message: TMessage);
begin
  RecreateWnd;
end;

procedure TRadioButton.CMDialogChar(var Message: TCMDialogChar);
begin
  with Message do
    if IsAccel(Message.CharCode, Caption) and CanFocus then
    begin
      SetFocus;
      Result := 1;
    end else
      inherited;
end;

procedure TRadioButton.CNCommand(var Message: TWMCommand);
begin
  case Message.NotifyCode of
    BN_CLICKED: SetChecked(True);
    BN_DOUBLECLICKED: DblClick;
  end;
end;

{ TListBoxStrings }

function TListBoxStrings.GetCount: Integer;
begin
  Result := SendMessage(ListBox.Handle, LB_GETCOUNT, 0, 0);
end;

function TListBoxStrings.Get(Index: Integer): string;
var
  Len: Integer;
  Text: array[0..4095] of Char;
begin
  Len := SendMessage(ListBox.Handle, LB_GETTEXT, Index, Longint(@Text));
  if Len < 0 then Error(SListIndexError, Index);
  SetString(Result, Text, Len);
end;

function TListBoxStrings.GetObject(Index: Integer): TObject;
begin
  Result := TObject(ListBox.GetItemData(Index));
  if Longint(Result) = LB_ERR then Error(SListIndexError, Index);
end;

procedure TListBoxStrings.Put(Index: Integer; const S: string);
var
  I: Integer;
  TempData: Longint;
begin
  I := ListBox.ItemIndex;
  TempData := ListBox.InternalGetItemData(Index);
  // Set the Item to 0 in case it is an object that gets freed during Delete
  ListBox.InternalSetItemData(Index, 0);
  Delete(Index);
  InsertObject(Index, S, nil);
  ListBox.InternalSetItemData(Index, TempData);
  ListBox.ItemIndex := I;
end;

procedure TListBoxStrings.PutObject(Index: Integer; AObject: TObject);
begin
  ListBox.SetItemData(Index, LongInt(AObject));
end;

function TListBoxStrings.Add(const S: string): Integer;
begin
  Result := SendMessage(ListBox.Handle, LB_ADDSTRING, 0, Longint(PChar(S)));
  if Result < 0 then raise EOutOfResources.Create(SInsertLineError);
end;

procedure TListBoxStrings.Insert(Index: Integer; const S: string);
begin
  if SendMessage(ListBox.Handle, LB_INSERTSTRING, Index,
    Longint(PChar(S))) < 0 then
    raise EOutOfResources.Create(SInsertLineError);
end;

procedure TListBoxStrings.Delete(Index: Integer);
begin
  ListBox.DeleteString(Index);
end;

procedure TListBoxStrings.Exchange(Index1, Index2: Integer);
var
  TempData: Longint;
  TempString: string;
begin
  BeginUpdate;
  try
    TempString := Strings[Index1];
    TempData := ListBox.InternalGetItemData(Index1);
    Strings[Index1] := Strings[Index2];
    ListBox.InternalSetItemData(Index1, ListBox.InternalGetItemData(Index2));
    Strings[Index2] := TempString;
    ListBox.InternalSetItemData(Index2, TempData);
    if ListBox.ItemIndex = Index1 then
      ListBox.ItemIndex := Index2
    else if ListBox.ItemIndex = Index2 then
      ListBox.ItemIndex := Index1;  
  finally
    EndUpdate;
  end;
end;

procedure TListBoxStrings.Clear;
begin
  ListBox.ResetContent;
end;

procedure TListBoxStrings.SetUpdateState(Updating: Boolean);
begin
  SendMessage(ListBox.Handle, WM_SETREDRAW, Ord(not Updating), 0);
  if not Updating then ListBox.Refresh;
end;

function TListBoxStrings.IndexOf(const S: string): Integer;
begin
  Result := SendMessage(ListBox.Handle, LB_FINDSTRINGEXACT, -1, LongInt(PChar(S)));
end;

procedure TListBoxStrings.Move(CurIndex, NewIndex: Integer);
var
  TempData: Longint;
  TempString: string;
begin
  BeginUpdate;
  ListBox.FMoving := True;
  try
    if CurIndex <> NewIndex then
    begin
      TempString := Get(CurIndex);
      TempData := ListBox.InternalGetItemData(CurIndex);
      ListBox.InternalSetItemData(CurIndex, 0);
      Delete(CurIndex);
      Insert(NewIndex, TempString);
      ListBox.InternalSetItemData(NewIndex, TempData);
    end;
  finally
    ListBox.FMoving := False;
    EndUpdate;
  end;
end;

{ TCustomListBox }

constructor TCustomListBox.Create(AOwner: TComponent);
const
  ListBoxStyle = [csSetCaption, csDoubleClicks];
begin
  inherited Create(AOwner);
  if NewStyleControls then
    ControlStyle := ListBoxStyle else
    ControlStyle := ListBoxStyle + [csFramed];
  Width := 121;
  Height := 97;
  TabStop := True;
  ParentColor := False;
  FItems := TListBoxStrings.Create;
  TListBoxStrings(FItems).ListBox := Self;
  FCanvas := TControlCanvas.Create;
  TControlCanvas(FCanvas).Control := Self;
  FItemHeight := 16;
  FBorderStyle := bsSingle;
  FExtendedSelect := True;
end;

destructor TCustomListBox.Destroy;
begin
  inherited Destroy;
  FCanvas.Free;
  FItems.Free;
  FSaveItems.Free;
end;

function TCustomListBox.GetItemData(Index: Integer): LongInt;
begin
  Result := SendMessage(Handle, LB_GETITEMDATA, Index, 0);
end;

procedure TCustomListBox.SetItemData(Index: Integer; AData: LongInt);
begin
  SendMessage(Handle, LB_SETITEMDATA, Index, AData);
end;

function TCustomListBox.InternalGetItemData(Index: Integer): LongInt;
begin
  Result := GetItemData(Index);
end;

procedure TCustomListBox.InternalSetItemData(Index: Integer; AData: LongInt);
begin
  SetItemData(Index, AData);
end;

procedure TCustomListBox.DeleteString( Index: Integer );
begin
  SendMessage(Handle, LB_DELETESTRING, Index, 0);
end;

procedure TCustomListBox.ResetContent;
begin
  SendMessage(Handle, LB_RESETCONTENT, 0, 0);
end;

procedure TCustomListBox.Clear;
begin
  FItems.Clear;
end;

procedure TCustomListBox.SetColumnWidth;
var
  ColWidth: Integer;
begin
  if (FColumns > 0) and (Width > 0) then
  begin
    ColWidth := (Width + FColumns - 3) div FColumns;
    if ColWidth < 1 then ColWidth := 1;
    SendMessage(Handle, LB_SETCOLUMNWIDTH, ColWidth, 0);
  end;
end;

procedure TCustomListBox.SetColumns(Value: Integer);
begin
  if FColumns <> Value then
    if (FColumns = 0) or (Value = 0) then
    begin
      FColumns := Value;
      RecreateWnd;
    end else
    begin
      FColumns := Value;
      if HandleAllocated then SetColumnWidth;
    end;
end;

function TCustomListBox.GetItemIndex: Integer;
begin
  if MultiSelect then Result := SendMessage(Handle, LB_GETCARETINDEX, 0, 0)
  else Result := SendMessage(Handle, LB_GETCURSEL, 0, 0);
end;

function TCustomListBox.GetSelCount: Integer;
begin
  Result := SendMessage(Handle, LB_GETSELCOUNT, 0, 0);
end;

procedure TCustomListBox.SetItemIndex(Value: Integer);
begin
  if GetItemIndex <> Value then
    if MultiSelect then SendMessage(Handle, LB_SETCARETINDEX, Value, 0)
    else SendMessage(Handle, LB_SETCURSEL, Value, 0);
end;

procedure TCustomListBox.SetExtendedSelect(Value: Boolean);
begin
  if Value <> FExtendedSelect then
  begin
    FExtendedSelect := Value;
    RecreateWnd;
  end;
end;

procedure TCustomListBox.SetIntegralHeight(Value: Boolean);
begin
  if Value <> FIntegralHeight then
  begin
    FIntegralHeight := Value;
    RecreateWnd;
    RequestAlign;
  end;
end;

function TCustomListBox.GetItemHeight: Integer;
var
  R: TRect;
begin
  Result := FItemHeight;
  if HandleAllocated and (FStyle = lbStandard) then
  begin
    Perform(LB_GETITEMRECT, 0, Longint(@R));
    Result := R.Bottom - R.Top;
  end;
end;

procedure TCustomListBox.SetItemHeight(Value: Integer);
begin
  if (FItemHeight <> Value) and (Value > 0) then
  begin
    FItemHeight := Value;
    RecreateWnd;
  end;
end;

procedure TCustomListBox.SetTabWidth(Value: Integer);
begin
  if Value < 0 then Value := 0;
  if FTabWidth <> Value then
  begin
    FTabWidth := Value;
    RecreateWnd;
  end;
end;

procedure TCustomListBox.SetMultiSelect(Value: Boolean);
begin
  if FMultiSelect <> Value then
  begin
    FMultiSelect := Value;
    RecreateWnd;
  end;
end;

function TCustomListBox.GetSelected(Index: Integer): Boolean;
var
  R: Longint;
begin
  R := SendMessage(Handle, LB_GETSEL, Index, 0);
  if R = LB_ERR then
    raise EListError.CreateResFmt(@SListIndexError, [Index]);
  Result := LongBool(R);
end;

procedure TCustomListBox.SetSelected(Index: Integer; Value: Boolean);
begin
  if SendMessage(Handle, LB_SETSEL, Longint(Value), Index) = LB_ERR then
    raise EListError.CreateResFmt(@SListIndexError, [Index]);
end;

procedure TCustomListBox.SetSorted(Value: Boolean);
begin
  if FSorted <> Value then
  begin
    FSorted := Value;
    RecreateWnd;
  end;
end;

procedure TCustomListBox.SetStyle(Value: TListBoxStyle);
begin
  if FStyle <> Value then
  begin
    FStyle := Value;
    RecreateWnd;
  end;
end;

function TCustomListBox.GetTopIndex: Integer;
begin
  Result := SendMessage(Handle, LB_GETTOPINDEX, 0, 0);
end;

procedure TCustomListBox.SetBorderStyle(Value: TBorderStyle);
begin
  if FBorderStyle <> Value then
  begin
    FBorderStyle := Value;
    RecreateWnd;
  end;
end;

procedure TCustomListBox.SetTopIndex(Value: Integer);
begin
  if GetTopIndex <> Value then
    SendMessage(Handle, LB_SETTOPINDEX, Value, 0);
end;

procedure TCustomListBox.SetItems(Value: TStrings);
begin
  Items.Assign(Value);
end;

function TCustomListBox.ItemAtPos(Pos: TPoint; Existing: Boolean): Integer;
var
  Count: Integer;
  ItemRect: TRect;
begin
  if PtInRect(ClientRect, Pos) then
  begin
    Result := TopIndex;
    Count := Items.Count;
    while Result < Count do
    begin
      Perform(LB_GETITEMRECT, Result, Longint(@ItemRect));
      if PtInRect(ItemRect, Pos) then Exit;
      Inc(Result);
    end;
    if not Existing then Exit;
  end;
  Result := -1;
end;

function TCustomListBox.ItemRect(Index: Integer): TRect;
var
  Count: Integer;
begin
  Count := Items.Count;
  if (Index = 0) or (Index < Count) then
    Perform(LB_GETITEMRECT, Index, Longint(@Result))
  else if Index = Count then
  begin
    Perform(LB_GETITEMRECT, Index - 1, Longint(@Result));
    OffsetRect(Result, 0, Result.Bottom - Result.Top);
  end else FillChar(Result, SizeOf(Result), 0);
end;

procedure TCustomListBox.CreateParams(var Params: TCreateParams);
type
  PSelects = ^TSelects;
  TSelects = array[Boolean] of DWORD;
const
  Styles: array[TListBoxStyle] of DWORD =
    (0, LBS_OWNERDRAWFIXED, LBS_OWNERDRAWVARIABLE);
  Sorteds: array[Boolean] of DWORD = (0, LBS_SORT);
  MultiSelects: array[Boolean] of DWORD = (0, LBS_MULTIPLESEL);
  ExtendSelects: array[Boolean] of DWORD = (0, LBS_EXTENDEDSEL);
  IntegralHeights: array[Boolean] of DWORD = (LBS_NOINTEGRALHEIGHT, 0);
  MultiColumns: array[Boolean] of DWORD = (0, LBS_MULTICOLUMN);
  TabStops: array[Boolean] of DWORD = (0, LBS_USETABSTOPS);
  CSHREDRAW: array[Boolean] of DWORD = (CS_HREDRAW, 0);
var
  Selects: PSelects;
begin
  inherited CreateParams(Params);
  CreateSubClass(Params, 'LISTBOX');
  with Params do
  begin
    Selects := @MultiSelects;
    if FExtendedSelect then Selects := @ExtendSelects;
    Style := Style or (WS_HSCROLL or WS_VSCROLL or LBS_HASSTRINGS or
      LBS_NOTIFY) or Styles[FStyle] or Sorteds[FSorted] or
      Selects^[FMultiSelect] or IntegralHeights[FIntegralHeight] or
      MultiColumns[FColumns <> 0] or BorderStyles[FBorderStyle] or
      TabStops[FTabWidth <> 0];
    if NewStyleControls and Ctl3D and (FBorderStyle = bsSingle) then
    begin
      Style := Style and not WS_BORDER;
      ExStyle := ExStyle or WS_EX_CLIENTEDGE;
    end;
    WindowClass.style := WindowClass.style and not (CSHREDRAW[UseRightToLeftAlignment] or CS_VREDRAW);
  end;
end;

procedure TCustomListBox.CreateWnd;
var
  W, H: Integer;
begin
  W := Width;
  H := Height;
  inherited CreateWnd;
  SetWindowPos(Handle, 0, Left, Top, W, H, SWP_NOZORDER or SWP_NOACTIVATE);
  if FTabWidth <> 0 then
    SendMessage(Handle, LB_SETTABSTOPS, 1, Longint(@FTabWidth));
  SetColumnWidth;
  if FSaveItems <> nil then
  begin
    FItems.Assign(FSaveItems);
    SetTopIndex(FSaveTopIndex);
    SetItemIndex(FSaveItemIndex);
    FSaveItems.Free;
    FSaveItems := nil;
  end;
end;

procedure TCustomListBox.DestroyWnd;
begin
  if FItems.Count > 0 then
  begin
    FSaveItems := TStringList.Create;
    FSaveItems.Assign(FItems);
    FSaveTopIndex := GetTopIndex;
    FSaveItemIndex := GetItemIndex;
  end;
  inherited DestroyWnd;
end;

procedure TCustomListBox.WndProc(var Message: TMessage);
begin
  {for auto drag mode, let listbox handle itself, instead of TControl}
  if not (csDesigning in ComponentState) and ((Message.Msg = WM_LBUTTONDOWN) or
    (Message.Msg = WM_LBUTTONDBLCLK)) and not Dragging then
  begin
    if DragMode = dmAutomatic then
    begin
      if IsControlMouseMsg(TWMMouse(Message)) then
        Exit;
      ControlState := ControlState + [csLButtonDown];
      Dispatch(Message);  {overrides TControl's BeginDrag}
      Exit;
    end;
  end;
  inherited WndProc(Message);
end;

procedure TCustomListBox.WMLButtonDown(var Message: TWMLButtonDown);
var
  ItemNo : Integer;
  ShiftState: TShiftState;
begin
  ShiftState := KeysToShiftState(Message.Keys);
  if (DragMode = dmAutomatic) and FMultiSelect then
  begin
    if not (ssShift in ShiftState) or (ssCtrl in ShiftState) then
    begin
      ItemNo := ItemAtPos(SmallPointToPoint(Message.Pos), True);
      if (ItemNo >= 0) and (Selected[ItemNo]) then
      begin
        BeginDrag (False);
        Exit;
      end;
    end;
  end;
  inherited;
  if (DragMode = dmAutomatic) and not (FMultiSelect and
    ((ssCtrl in ShiftState) or (ssShift in ShiftState))) then
    BeginDrag(False);
end;

procedure TCustomListBox.CNCommand(var Message: TWMCommand);
begin
  case Message.NotifyCode of
    LBN_SELCHANGE:
      begin
        inherited Changed;
        Click;
      end;
    LBN_DBLCLK: DblClick;
  end;
end;

procedure TCustomListBox.WMPaint(var Message: TWMPaint);

  procedure PaintListBox;
  var
    DrawItemMsg: TWMDrawItem;
    MeasureItemMsg: TWMMeasureItem;
    DrawItemStruct: TDrawItemStruct;
    MeasureItemStruct: TMeasureItemStruct;
    R: TRect;
    Y, I, H, W: Integer;
  begin
    { Initialize drawing records }
    DrawItemMsg.Msg := CN_DRAWITEM;
    DrawItemMsg.DrawItemStruct := @DrawItemStruct;
    DrawItemMsg.Ctl := Handle;
    DrawItemStruct.CtlType := ODT_LISTBOX;
    DrawItemStruct.itemAction := ODA_DRAWENTIRE;
    DrawItemStruct.itemState := 0;
    DrawItemStruct.hDC := Message.DC;
    DrawItemStruct.CtlID := Handle;
    DrawItemStruct.hwndItem := Handle;

    { Intialize measure records }
    MeasureItemMsg.Msg := CN_MEASUREITEM;
    MeasureItemMsg.IDCtl := Handle;
    MeasureItemMsg.MeasureItemStruct := @MeasureItemStruct;
    MeasureItemStruct.CtlType := ODT_LISTBOX;
    MeasureItemStruct.CtlID := Handle;

    { Draw the listbox }
    Y := 0;
    I := TopIndex;
    GetClipBox(Message.DC, R);
    H := Height;
    W := Width;
    while Y < H do
    begin
      MeasureItemStruct.itemID := I;
      if I < Items.Count then
        MeasureItemStruct.itemData := Longint(Pointer(Items.Objects[I]));
      MeasureItemStruct.itemWidth := W;
      MeasureItemStruct.itemHeight := FItemHeight;
      DrawItemStruct.itemData := MeasureItemStruct.itemData;
      DrawItemStruct.itemID := I;
      Dispatch(MeasureItemMsg);
      DrawItemStruct.rcItem := Rect(0, Y, MeasureItemStruct.itemWidth,
        Y + Integer(MeasureItemStruct.itemHeight));
      Dispatch(DrawItemMsg);
      Inc(Y, MeasureItemStruct.itemHeight);
      Inc(I);
      if I >= Items.Count then break;
    end;
  end;

begin
  if Message.DC <> 0 then
    { Listboxes don't allow paint "sub-classing" like the other windows controls
      so we have to do it ourselves. }
    PaintListBox
  else inherited;
end;

procedure TCustomListBox.WMSize(var Message: TWMSize);
begin
  inherited;
  SetColumnWidth;
end;

procedure TCustomListBox.DragCanceled;
var
  M: TWMMouse;
  MousePos: TPoint;
begin
  with M do
  begin
    Msg := WM_LBUTTONDOWN;
    GetCursorPos(MousePos);
    Pos := PointToSmallPoint(ScreenToClient(MousePos));
    Keys := 0;
    Result := 0;
  end;
  DefaultHandler(M);
  M.Msg := WM_LBUTTONUP;
  DefaultHandler(M);
end;

procedure TCustomListBox.DrawItem(Index: Integer; Rect: TRect;
  State: TOwnerDrawState);
var
  Flags: Longint;
begin
  if Assigned(FOnDrawItem) then FOnDrawItem(Self, Index, Rect, State) else
  begin
    FCanvas.FillRect(Rect);
    if Index < Items.Count then
    begin
      Flags := DrawTextBiDiModeFlags(DT_SINGLELINE or DT_VCENTER or DT_NOPREFIX);
      if not UseRightToLeftAlignment then
        Inc(Rect.Left, 2)
      else
        Dec(Rect.Right, 2);
      DrawText(FCanvas.Handle, PChar(Items[Index]), Length(Items[Index]), Rect,
        Flags);
    end;
  end;
end;

procedure TCustomListBox.MeasureItem(Index: Integer; var Height: Integer);
begin
  if Assigned(FOnMeasureItem) then FOnMeasureItem(Self, Index, Height)
end;

procedure TCustomListBox.CNDrawItem(var Message: TWMDrawItem);
var
  State: TOwnerDrawState;
begin
  with Message.DrawItemStruct^ do
  begin
    State := TOwnerDrawState(LongRec(itemState).Lo);
    FCanvas.Handle := hDC;
    FCanvas.Font := Font;
    FCanvas.Brush := Brush;
    if (Integer(itemID) >= 0) and (odSelected in State) then
    begin
      FCanvas.Brush.Color := clHighlight;
      FCanvas.Font.Color := clHighlightText
    end;
    if Integer(itemID) >= 0 then
      DrawItem(itemID, rcItem, State) else
      FCanvas.FillRect(rcItem);
    if odFocused in State then DrawFocusRect(hDC, rcItem);
    FCanvas.Handle := 0;
  end;
end;

procedure TCustomListBox.CNMeasureItem(var Message: TWMMeasureItem);
begin
  with Message.MeasureItemStruct^ do
  begin
    itemHeight := FItemHeight;
    if FStyle = lbOwnerDrawVariable then
      MeasureItem(itemID, Integer(itemHeight));
  end;
end;

procedure TCustomListBox.CMCtl3DChanged(var Message: TMessage);
begin
  if NewStyleControls and (FBorderStyle = bsSingle) then RecreateWnd;
  inherited;
end;

{ TScrollBar }

constructor TScrollBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Width := 121;
  Height := GetSystemMetrics(SM_CYHSCROLL);
  TabStop := True;
  ControlStyle := [csFramed, csDoubleClicks, csOpaque];
  FKind := sbHorizontal;
  FPosition := 0;
  FMin := 0;
  FMax := 100;
  FSmallChange := 1;
  FLargeChange := 1;
  if SysLocale.FarEast and (Win32Platform = VER_PLATFORM_WIN32_NT) then
    ImeMode := imDisable;
end;

procedure TScrollBar.CreateParams(var Params: TCreateParams);
const
  Kinds: array[TScrollBarKind] of DWORD = (SBS_HORZ, SBS_VERT);
begin
  inherited CreateParams(Params);
  CreateSubClass(Params, 'SCROLLBAR');
  Params.Style := Params.Style or Kinds[FKind];
  if FKind = sbVertical then
    if not UseRightToLeftAlignment then
      Params.Style := Params.Style or SBS_RIGHTALIGN
    else
      Params.Style := Params.Style or SBS_LEFTALIGN;
  if NotRightToLeft then
    FRTLFactor := 1
  else
    FRTLFactor := -1;
end;

procedure TScrollBar.CreateWnd;
var
  ScrollInfo: TScrollInfo;
begin
  inherited CreateWnd;
  SetScrollRange(Handle, SB_CTL, FMin, FMax, False);
  ScrollInfo.cbSize := SizeOf(ScrollInfo);
  ScrollInfo.nPage := FPageSize;
  ScrollInfo.fMask := SIF_PAGE;
  SetScrollInfo(Handle, SB_CTL, ScrollInfo, False);
  if NotRightToLeft then
    SetScrollPos(Handle, SB_CTL, FPosition, True)
  else
    SetScrollPos(Handle, SB_CTL, FMax - FPosition, True);
end;

function TScrollBar.NotRightToLeft: Boolean;
begin
  Result := (not IsRightToLeft) or (FKind = sbVertical);
end;

procedure TScrollBar.SetKind(Value: TScrollBarKind);
begin
  if FKind <> Value then
  begin
    FKind := Value;
    if not (csLoading in ComponentState) then SetBounds(Left, Top, Height, Width);
    RecreateWnd;
  end;
end;

procedure TScrollBar.SetParams(APosition, AMin, AMax: Integer);
begin
  if AMax < AMin then
    raise EInvalidOperation.Create(SScrollBarRange);
  if APosition < AMin then APosition := AMin;
  if APosition > AMax then APosition := AMax;
  if (FMin <> AMin) or (FMax <> AMax) then
  begin
    FMin := AMin;
    FMax := AMax;
    if HandleAllocated then
      SetScrollRange(Handle, SB_CTL, AMin, AMax, FPosition = APosition);
  end;
  if FPosition <> APosition then
  begin
    FPosition := APosition;
    if HandleAllocated then
      if NotRightToLeft then
        SetScrollPos(Handle, SB_CTL, FPosition, True)
      else
        SetScrollPos(Handle, SB_CTL, FMax - FPosition, True);
    Enabled := True;
    Change;
  end;
end;

procedure TScrollBar.SetPosition(Value: Integer);
begin
  SetParams(Value, FMin, FMax);
end;

procedure TScrollBar.SetPageSize(Value: Integer);
var
  ScrollInfo: TScrollInfo;
begin
  if (FPageSize = Value) or (FPageSize > FMax) then exit;
  FPageSize := Value;
  ScrollInfo.cbSize := SizeOf(ScrollInfo);
  ScrollInfo.nPage := Value;
  ScrollInfo.fMask := SIF_PAGE;
  if HandleAllocated then
    SetScrollInfo(Handle, SB_CTL, ScrollInfo, True);
end;

procedure TScrollBar.SetMin(Value: Integer);
begin
  SetParams(FPosition, Value, FMax);
end;

procedure TScrollBar.SetMax(Value: Integer);
begin
  SetParams(FPosition, FMin, Value);
end;

procedure TScrollBar.Change;
begin
  inherited Changed;
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure TScrollBar.Scroll(ScrollCode: TScrollCode; var ScrollPos: Integer);
begin
  if Assigned(FOnScroll) then FOnScroll(Self, ScrollCode, ScrollPos);
end;

procedure TScrollBar.DoScroll(var Message: TWMScroll);
var
  ScrollPos: Integer;
  NewPos: Longint;
  ScrollInfo: TScrollInfo;
begin
  with Message do
  begin
    NewPos := FPosition;
    case TScrollCode(ScrollCode) of
      scLineUp:
        Dec(NewPos, FSmallChange * FRTLFactor);
      scLineDown:
        Inc(NewPos, FSmallChange * FRTLFactor);
      scPageUp:
        Dec(NewPos, FLargeChange * FRTLFactor);
      scPageDown:
        Inc(NewPos, FLargeChange * FRTLFactor);
      scPosition, scTrack:
        with ScrollInfo do
        begin
          cbSize := SizeOf(ScrollInfo);
          fMask := SIF_ALL;
          GetScrollInfo(Handle, SB_CTL, ScrollInfo);
          NewPos := nTrackPos;
          { We need to reverse the positioning because SetPosition below
            calls SetParams that reverses the position. This acts as a
            double negative. }
          if not NotRightToLeft then NewPos := FMax - NewPos;
        end;
      scTop:
        NewPos := FMin;
      scBottom:
        NewPos := FMax;
    end;
    if NewPos < FMin then NewPos := FMin;
    if NewPos > FMax then NewPos := FMax;
    ScrollPos := NewPos;
    Scroll(TScrollCode(ScrollCode), ScrollPos);
    SetPosition(ScrollPos);
  end;
end;

procedure TScrollBar.CNHScroll(var Message: TWMHScroll);
begin
  DoScroll(Message);
end;

procedure TScrollBar.CNVScroll(var Message: TWMVScroll);
begin
  DoScroll(Message);
end;

procedure TScrollBar.CNCtlColorScrollBar(var Message: TMessage);
begin
  with Message do
    CallWindowProc(DefWndProc, Handle, Msg, WParam, LParam);
end;

procedure TScrollBar.WMEraseBkgnd(var Message: TWMEraseBkgnd);
begin
  DefaultHandler(Message);
end;

{ TCustomStaticText }

constructor TCustomStaticText.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csCaptureMouse, csClickEvents, csSetCaption,
    csOpaque, csReplicatable, csDoubleClicks];
  Width := 65;
  Height := 17;
  FAutoSize := True;
  FShowAccelChar := True;
  AdjustBounds;
end;

procedure TCustomStaticText.CreateParams(var Params: TCreateParams);
const
  Alignments: array[Boolean, TAlignment] of DWORD =
    ((SS_LEFT, SS_RIGHT, SS_CENTER), (SS_RIGHT, SS_LEFT, SS_CENTER));
  Borders: array[TStaticBorderStyle] of DWORD = (0, WS_BORDER, SS_SUNKEN);
begin
  inherited CreateParams(Params);
  CreateSubClass(Params, 'STATIC');
  with Params do
  begin
    Style := Style or SS_NOTIFY or
      Alignments[UseRightToLeftAlignment, FAlignment] or Borders[FBorderStyle];
    if not FShowAccelChar then Style := Style or SS_NOPREFIX;
    WindowClass.style := WindowClass.style and not (CS_HREDRAW or CS_VREDRAW);
  end;
end;

procedure TCustomStaticText.CMDialogChar(var Message: TCMDialogChar);
begin
  if (FFocusControl <> nil) and Enabled and ShowAccelChar and
    IsAccel(Message.CharCode, Caption) then
    with FFocusControl do
      if CanFocus then
      begin
        SetFocus;
        Message.Result := 1;
      end;
end;

procedure TCustomStaticText.CMFontChanged(var Message: TMessage);
begin
  inherited;
  AdjustBounds;
end;

procedure TCustomStaticText.CMTextChanged(var Message: TMessage);
begin
  inherited;
  AdjustBounds;
  Invalidate;
end;

procedure TCustomStaticText.Loaded;
begin
  inherited Loaded;
  AdjustBounds;
end;

procedure TCustomStaticText.AdjustBounds;
var
  DC: HDC;
  SaveFont: HFont;
  TextSize: TSize;
begin
  if not (csReading in ComponentState) and FAutoSize then
  begin
    DC := GetDC(0);
    SaveFont := SelectObject(DC, Font.Handle);
    GetTextExtentPoint32(DC, PChar(Caption), Length(Caption), TextSize);
    SelectObject(DC, SaveFont);
    ReleaseDC(0, DC);
    SetBounds(Left, Top,
      TextSize.cx + (GetSystemMetrics(SM_CXBORDER) * 4),
      TextSize.cy + (GetSystemMetrics(SM_CYBORDER) * 4));
  end;
end;

procedure TCustomStaticText.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FFocusControl) then
    FFocusControl := nil;
end;

procedure TCustomStaticText.SetAlignment(Value: TAlignment);
begin
  if FAlignment <> Value then
  begin
    FAlignment := Value;
    RecreateWnd;
  end;
end;

procedure TCustomStaticText.SetAutoSize(Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    if Value then AdjustBounds;
  end;
end;

procedure TCustomStaticText.SetBorderStyle(Value: TStaticBorderStyle);
begin
  if FBorderStyle <> Value then
  begin
    FBorderStyle := Value;
    RecreateWnd;
  end;
end;

procedure TCustomStaticText.SetFocusControl(Value: TWinControl);
begin
  FFocusControl := Value;
  if Value <> nil then Value.FreeNotification(Self);
end;

procedure TCustomStaticText.SetShowAccelChar(Value: Boolean);
begin
  if FShowAccelChar <> Value then
  begin
    FShowAccelChar := Value;
    RecreateWnd;
  end;
end;

end.
