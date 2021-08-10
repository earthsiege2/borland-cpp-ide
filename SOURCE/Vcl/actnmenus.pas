
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 1995-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit ActnMenus;

interface

(*$HPPEMIT '#pragma link "dclact.lib"'*)

uses Windows, Messages, Classes, Controls, Contnrs, Registry, Graphics,
  ActnList, ToolWin, ExtCtrls, ActnMan, ActnCtrls, Menus;

type

{ TMenuStack }

  TCustomActionMenuBar = class;

  TMenuStack = class(TStack)
  private
    function GetBars(const Index: Integer): TCustomActionMenuBar;
  protected
    property Bars[const Index: Integer]: TCustomActionMenuBar read GetBars;
  public
    procedure Push(Container: TCustomActionMenuBar);
    function Pop: TCustomActionMenuBar;
    function Peek: TCustomActionMenuBar;
  end;

{ TCustomActionMenuBar }

  TAnimationStyle = (asNone, asDefault, asUnFold, asSlide, asFade);
  TMenuPopupEvent = procedure(Sender: TObject;
    Item: TCustomActionControl) of object;
  TCustomActionPopupMenu = class;
  TCustomPopupClass = class of TCustomActionPopupMenu;
  TGetPopupClassEvent = procedure(Sender: TObject;
    var PopupClass: TCustomPopupClass);

  TCustomActionMenuBar = class(TCustomActionDockBar)
  private
    FAnimatePopups: Boolean;
    FAnimationStyle: TAnimationStyle;
    FCommandSound: String;
    FDelayItem: TCustomActionControl;
    FDragItem: TCustomActionControl;
    FExpandable: Boolean;
    FExpanded: Boolean;
    FInMenuLoop: Boolean;
    FItemKeyed: Boolean;
    FParentMenu: TCustomActionMenuBar;
    FParentControl: TCustomActionControl;
    FPopupStack: TMenuStack;
    FRegistry: TRegistry;
    FOnPopup: TMenuPopupEvent;
    FExpandDelay: Integer;
    FPopupSound: string;
    FRootMenu: TCustomActionMenuBar;
    FDefaultFont: Boolean;
    FOnGetPopupClass: TGetPopupClassEvent;
    procedure WMKeyDown(var Message:  TWMKeyDown); message WM_KEYDOWN;
    procedure CMEnterMenuLoop(var Message: TMessage); message CM_ENTERMENULOOP;
    procedure CMItemClicked(var Message: TCMItemMsg); message CM_ITEMCLICKED;
    procedure WMMouseActivate(var Message: TWMMouseActivate); message WM_MOUSEACTIVATE;
    procedure WMSysKeyDown(var Message: TWMSysKeyDown); message WM_SYSKEYDOWN;
    procedure SetParentMenu(const Value: TCustomActionMenuBar);
    procedure CMItemKeyed(var Message: TCMItemMsg); message CM_ITEMKEYED;
  protected
    FChildMenu: TCustomActionMenuBar;
    FExpandTimer: TTimer;
    FPopupTimer: TTimer;
    procedure Animate(Show: Boolean = True);
    procedure ClearSubMenus;
    procedure CleanupStack;
    function CreateControl(AnItem: TActionClientItem): TCustomActionControl; override;
    function CreatePopup(AOwner: TCustomActionMenuBar;
      Item: TCustomActionControl): TCustomActionPopupMenu; virtual;
    procedure DoItemSelected(AnItem: TCustomActionControl);
    function DoGetPopupClass: TCustomPopupClass; dynamic;
    function DoItemClicked(AnItem: TCustomActionControl): TActionClientItem; virtual;
    function DoItemKeyed(AnItem: TCustomActionControl): TActionClientItem; virtual;
    procedure DoMenuDelay(Sender: TObject);
    procedure DoneMenuLoop; virtual;
    procedure ExecAction(Action: TContainedAction); virtual;
    procedure Expand(Full: Boolean); virtual;
    procedure ExpandTimer(Sender: TObject);
    procedure GetDefaultSounds;
    function GetDesignMode: Boolean; override;
    function GetControlClass(AnItem: TActionClientItem): TCustomActionControlClass; override;
    function GetPopupClass: TCustomPopupClass;
    function GetMouseHoverItem(Msg: TMsg): TCustomActionControl;
    function GetSelected: TActionClientItem;
    procedure InitMenuLoop;
    function IsDesignMsg(var Msg: TMsg): Boolean;
    function NewPopup: TCustomActionPopupMenu; virtual;
    property PopupStack: TMenuStack read FPopupStack;
    function ProcessMenuLoop: TActionClientItem; virtual;
    procedure ProcessMouseMsg(var Msg: TMsg); virtual;
    procedure SelectItem(AnItem: TCustomActionControl);
    procedure Select(const Forward: Boolean);
    procedure SetDesignMode(const Value: Boolean); override;
    procedure SetPersistentHotkeys(const Value: Boolean); override;
    procedure WndProc(var Message: TMessage); override;
    property DelayItem: TCustomActionControl read FDelayItem write FDelayItem;
    property Expandable: Boolean read FExpandable write FExpandable;
    property Expanded: Boolean read FExpanded write FExpanded;
    property ParentMenu: TCustomActionMenuBar read FParentMenu write SetParentMenu;
    property Selected: TActionClientItem read GetSelected;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CloseMenu; virtual;
    procedure TrackMenu; virtual;
    property AnimationStyle: TAnimationStyle read FAnimationStyle write FAnimationStyle;
    property ExpandDelay: Integer read FExpandDelay write FExpandDelay;
    property InMenuLoop: Boolean read FInMenuLoop write FInMenuLoop;
    property ParentControl: TCustomActionControl read FParentControl write FParentControl;
    property RootMenu: TCustomActionMenuBar read FRootMenu write FRootMenu;
    property OnGetPopupClass: TGetPopupClassEvent read FOnGetPopupClass
      write FOnGetPopupClass;
    property OnPopup: TMenuPopupEvent read FOnPopup write FOnPopup;
  end;

{ TCustomMenuExpandBtn }

  TCustomMenuExpandBtn = class(TCustomUtilityButton)
  protected
    procedure DrawBackground(var PaintRect: TRect); override;
    procedure DrawFrame(ARect: TRect; Down: Boolean); override;
    procedure DragOver(Source: TObject; X: Integer; Y: Integer;
      State: TDragState; var Accept: Boolean); override;
  end;

{ TCustomActionPopupMenu }

  TCustomMenuItem = class;

  TCustomActionPopupMenu = class(TCustomActionMenuBar)
  private
    FExpandBtn: TCustomMenuExpandBtn;
    FExpandedSize: TPoint;
    FMenuSize: TPoint;
  protected
    procedure AddEdges(AnItem: TCustomMenuItem); virtual;
    procedure CMMouseLeave(var Message: TMessage); message CM_MOUSELEAVE;
    procedure CMVisibleChanged(var Message: TMessage);
      message CM_VISIBLECHANGED;
    function CreateControl(AnItem: TActionClientItem): TCustomActionControl; override;
    procedure CreateControls; override;
    procedure CreateParams(var Params: TCreateParams); override;
    function DesignWndProc(var Message: TMessage): Boolean; override;
    procedure ExecAction(Action: TContainedAction); override;
    procedure ExpandClick(Sender: TObject);
    function GetBarHeight: Integer; override;
    function GetControlClass(AnItem: TActionClientItem): TCustomActionControlClass; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation);
      override;
    procedure PositionPopup(AnOwner: TCustomActionBar;
      ParentItem: TCustomActionControl);
    procedure SetActionClient(const Value: TActionClient); override;
    procedure SetupExpandBtn;
    procedure SetOrientation(const Value: TBarOrientation); override;
    procedure WMKeyDown(var Message: TWMKeyDown); message WM_KEYDOWN;
    procedure WMPrint(var Message: TMessage); message WM_PRINT;
    procedure WMPrintClient(var Message: TMessage); message WM_PRINTCLIENT;
    procedure VisibleChanging; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CloseMenu; override;
    procedure Expand(Full: Boolean); override;
    procedure Popup(X, Y: Integer);
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    property ExpandBtn: TCustomMenuExpandBtn read FExpandBtn write FExpandBtn;
  end;

{ TCustomizeActionToolBar }

  TCustomizeActionToolBarClass = class of TCustomizeActionToolBar;

  TCustomizeActionToolBar = class(TCustomActionPopupMenu)
  private
    FActionBar: TCustomActionToolBar;
    FAddlItem: TActionClientItem;
    FResetAction: TCustomAction;
    FResetItem: TActionClientItem;
    procedure CMItemSelected(var Message: TCMItemMsg); message CM_ITEMSELECTED;
  protected
    function CanAutoSize(var NewWidth: Integer;
      var NewHeight: Integer): Boolean; override;
    procedure Clear; override;
    function DoItemClicked(AnItem: TCustomActionControl): TActionClientItem; override;
    function GetActionControl(const Index: Integer): TCustomActionControl; override;
    function GetControlClass(AnItem: TActionClientItem): TCustomActionControlClass; override;
    procedure GetSubMenuControlClass(Sender: TCustomActionBar; AnItem: TActionClient;
      var ControlClass: TCustomActionControlClass);
    function DoGetPopupClass: TCustomPopupClass; override;
    function NewPopup: TCustomActionPopupMenu; override;
    procedure SetActionClient(const Value: TActionClient); override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure CloseMenu; override;
    function ItemCount: Integer; override;
    destructor Destroy; override;
  end;

{ TCustomizeActionLink }

  TCustomizeActionLink = class(TActionClientLink)
  protected
    procedure SetEnabled(Value: Boolean); override;
  end;

{ TCustomizeActionClientItem }

  TCustomizeActionClientItem = class(TActionClientItem)
  protected
    function GetActionLinkClass: TActionClientLinkClass; override;
  end;

{ TCustomActionMainMenuBar }

  TCustomActionMainMenuBar = class(TCustomActionMenuBar)
  private
    FInActive: Boolean;
    procedure SetInActive(const Value: Boolean);
  protected
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    function CanAutoSize(var NewWidth: Integer;
      var NewHeight: Integer): Boolean; override;
    function CreateControl(AnItem: TActionClientItem): TCustomActionControl; override;
    function DesignWndProc(var Message: TMessage): Boolean; override;
    procedure DoneMenuLoop; override;
    function GetControlClass(AnItem: TActionClientItem): TCustomActionControlClass; override;
    procedure ProcessMouseMsg(var Msg: tagMSG); override;
    procedure SetDesignMode(const Value: Boolean); override;
    procedure CMWininichange(var Message: TMessage);
      message CM_WININICHANGE;
    procedure WMKeyDown(var Message: TWMKeyDown); message WM_KEYDOWN;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
  public
    constructor Create(AOwner: TComponent); override;
    procedure CloseMenu; override;
    property Inactive: Boolean read FInActive write SetInActive;
    property PersistentHotKeys;
  end;

{ TActionMainMenuBar }

  TActionMainMenuBar = class(TCustomActionMainMenuBar)
  published
    property ActionManager;
    property Align default alTop;
    property AllowHiding default False;
    property Anchors;
    property AnimationStyle default asDefault;
    property BiDiMode default bdLeftToRight;
    property Caption;
    property Color default clMenu;
    property Constraints;
    property EdgeBorders default [ebTop];
    property EdgeInner default esRaised;
    property EdgeOuter default esLowered;
    property Enabled;
    property ExpandDelay default 4000;
    property Font;
    property HorzMargin;    
    property ParentBiDiMode;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property ShowHint;
    property Spacing;
    property VertMargin;
    property Visible;
    property OnCanResize;
    property OnClick;
    property OnControlCreated;
    property OnConstrainedResize;
    property OnContextPopup;
    property OnDockDrop;
    property OnDockOver;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnGetControlClass;
    property OnGetSiteInfo;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnPaint;
    property OnResize;
    property OnStartDock;
    property OnStartDrag;
    property OnUnDock;
  end;

{ TCustomMenuItem }

  TMenuEdges = set of TEdgeBorder;

  TCustomMenuItem = class(TCustomActionControl)
  private
    FEdges: TMenuEdges;
    FMenu: TCustomActionMenuBar;
    FMouseSelected: Boolean;
    FShortCutBounds: TRect;
    procedure SetEdges(const Value: TMenuEdges);
    procedure CMMouseEnter(var Message: TMessage); message CM_MOUSEENTER;
    procedure CMTextchanged(var Message: TMessage); message CM_TEXTCHANGED;
  protected
    procedure CalcLayout; override;
    procedure DoDragDrop(DragObject: TObject; X: Integer; Y: Integer); override;
    procedure DrawDesignFocus(var PaintRect: TRect); override;
    procedure DrawEdge(Edges: TMenuEdges); virtual;
    procedure DrawSubMenuGlyph; virtual;
    procedure DrawUnusedEdges; virtual;
    function GetImageSize: TPoint; override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X: Integer;
      Y: Integer); override;
    procedure Paint; override;
    procedure PositionChanged; override;
    procedure SetSelected(Value: Boolean); override;
    procedure DragOver(Source: TObject; X: Integer; Y: Integer;
      State: TDragState; var Accept: Boolean); override;
    property Menu: TCustomActionMenuBar read FMenu;
    property MouseSelected: Boolean read FMouseSelected;
    property ShortCutBounds: TRect read FShortCutBounds write FShortCutBounds;
  public
    constructor Create(AOwner: TComponent); override;
    procedure CalcBounds; override;
    procedure Click; override;
    destructor Destroy; override;
    procedure Keyed; override;
    procedure DragDrop(Source: TObject; X: Integer; Y: Integer); override;
    property Edges: TMenuEdges read FEdges write SetEdges;
  end;

{ TCustomMenuButton }

  TCustomMenuButton = class(TCustomButtonControl)
  protected
    procedure BeginAutoDrag; override;
    procedure DoDragDrop(DragObject: TObject; X: Integer; Y: Integer);
      override;    
    procedure DragOver(Source: TObject; X: Integer; Y: Integer;
      State: TDragState; var Accept: Boolean); override;
    procedure DrawText(var ARect: TRect; var Flags: Cardinal; Text: string); override;
    procedure CMMouseEnter(var Message: TMessage); message CM_MOUSEENTER;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
      X: Integer; Y: Integer); override;
    procedure Paint; override;
  public
    destructor Destroy; override;
    procedure Click; override;
    procedure Keyed; override;
  end;

{ TCustomAddRemoveItem }

  TCustomAddRemoveItem = class(TCustomMenuItem)
  protected
    function IsActionVisible: Boolean;
    procedure SetEnabled(Value: Boolean); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X: Integer;
      Y: Integer); override;
  public
    procedure CalcBounds; override;  
  end;

  TMenuItemControlClass = class of TCustomMenuItem;
  TAddRemoveItemClass = class of TCustomAddRemoveItem;
  TMenuButtonControlClass = class of TCustomMenuButton;

type
  TUpdateActnMenusProc = procedure;

var
  MenuItemControlClass: TMenuItemControlClass;
  MenuAddRemoveItemClass: TAddRemoveItemClass;
  MenuButtonControlClass: TMenuButtonControlClass;
  MenuPopupClass: TCustomPopupClass;
  MenuCustomizePopupClass: TCustomizeActionToolBarClass;
  UpdateActnMenusProc: TUpdateActnMenusProc;

implementation

uses SysUtils, Forms, Dialogs, StdCtrls, Consts, MMSystem, GraphUtil,
  CommCtrl, Buttons, StdActnMenus, ExtActns, ListActns;

{ TMenuStack }

function TMenuStack.GetBars(const Index: Integer): TCustomActionMenuBar;
begin
  Result := TCustomActionMenuBar(List[Index]);
end;

function TMenuStack.Peek: TCustomActionMenuBar;
begin
  Result := TCustomActionMenuBar(inherited PeekItem);
end;

function TMenuStack.Pop: TCustomActionMenuBar;
begin
  Result := TCustomActionMenuBar(PopItem);
end;

procedure TMenuStack.Push(Container: TCustomActionMenuBar);
begin
  PushItem(Pointer(Container));
end;

type
  TApplicationClass = class(TApplication);

{ TMenuList }

  TMenuList = class(TList)
  private
    function GetMenu(const Index: Integer): TCustomActionMenuBar;
  protected
    procedure Notify(Ptr: Pointer; Action: TListNotification); override;
  public
    property Menus[const Index: Integer]: TCustomActionMenuBar read GetMenu;
  end;

{ TMenuList }

function TMenuList.GetMenu(const Index: Integer): TCustomActionMenuBar;
begin
  Result := TCustomActionMenuBar(Items[Index]);
end;

var
  MenuKeyHook: HHOOK;
  MenuCallWndHook: HHOOK;
  MenuList: TMenuList;
  ActiveMenu: TCustomActionMenuBar;

{ Hooks required for Main Menu Support }

function GetMsgHook(Code: Integer; WParam: wParam; Msg: PMsg): Longint; stdcall;

  function HandleMsg: Boolean;
  begin
    Result := (Msg.Message = WM_SYSKEYDOWN) or (Msg.Message = WM_SYSCHAR) or
              (Msg.Message = WM_SYSKEYUP);
  end;

  function ParentFormEnabled(Ctrl: TWinControl): Boolean;
  var
    ParentFrm: TCustomForm;
  begin
    Result := False;
    if Assigned(Ctrl) then
    begin
      ParentFrm := GetParentForm(Ctrl);
      if Assigned(ParentFrm) then
        Result := GetWindowLong(ParentFrm.Handle, GWL_STYLE) and WS_DISABLED <> WS_DISABLED;
    end;
  end;

  function CheckForm(AForm: TCustomForm): TCustomActionMenuBar;
  var
    I: Integer;
  begin
    Result := nil;
    if (AForm <> nil) and
       (GetWindowLong(AForm.Handle, GWL_STYLE) and WS_DISABLED <> WS_DISABLED) and
       AForm.Visible then
      for I := 0 to MenuList.Count - 1 do
        if MenuList.Menus[I].Enabled and (MenuList.Menus[I] is TCustomActionMainMenuBar) and
           (MenuList.Menus[I].Owner = AForm) then
          Result := MenuList.Menus[I];
  end;

var
  Item: TActionClientItem;
  Menu: TCustomActionMenuBar;
begin
  if (Code = HC_ACTION) and HandleMsg then
    case Msg.Message of
      WM_SYSKEYDOWN:
        if Msg.wParam = VK_MENU then
        begin
          if ActiveMenu = nil then
          begin
            Menu := CheckForm(Screen.ActiveForm);
            if Menu = nil then
              Menu := CheckForm(Application.MainForm);
            if Menu <> nil then
            begin
              Menu.PersistentHotkeys := True;
              ActiveMenu := Menu;
              FillChar(Msg^, SizeOf(Msg), 0);
            end;
          end
          else
            if not ActiveMenu.DesignMode and ActiveMenu.InMenuLoop then
            begin
              ActiveMenu.CloseMenu;
              Application.ProcessMessages;
              FillChar(Msg^, SizeOf(TMsg), 0);
            end;
        end;
      WM_SYSKEYUP:
        if (Msg.wParam <> VK_SPACE) and Assigned(ActiveMenu) and
           not ActiveMenu.InMenuLoop then
        begin
          if Msg.wParam = VK_MENU then
            if ActiveMenu.HasItems and (ActiveMenu.Items.Count > 0) then
            begin
              Item := ActiveMenu.FindFirstVisibleItem;
              if Assigned(Item) then
                Item.Control.Selected := True;
            end;
          PostMessage(ActiveMenu.Handle, CM_ENTERMENULOOP, 0, 0);
        end;
      WM_SYSCHAR:
      begin
        Menu := CheckForm(Screen.ActiveForm);
        Item := nil;
        if Menu <> nil then
          Item := Menu.FindAccelItem(Msg.wParam);
        if Item = nil then
          Menu := CheckForm(Application.MainForm);
        if Menu <> nil then
          Item := Menu.FindAccelItem(Msg.wParam);
        if (Item <> nil) and ParentFormEnabled(Menu) then
        begin
          ActiveMenu := Menu;
          GetParentForm(ActiveMenu).SetFocus;
          Item.Control.Keyed;
          PostMessage(ActiveMenu.Handle, CM_ENTERMENULOOP, 0, 0);
        end;
        if Msg.wParam <> VK_SPACE then
          FillChar(Msg^, SizeOf(Msg), 0);
      end;
    end;
  Result := CallNextHookEx(MenuKeyHook, Code, WParam, Longint(Msg));
end;

function CallWndHook(Code: Integer; WParam: wParam; Msg: PCWPStruct): Longint; stdcall;
var
  I: Integer;
  ParentForm: TCustomForm;
begin
  case Msg.message of
    WM_SETTINGCHANGE:
      if Assigned(UpdateActnMenusProc) then
        UpdateActnMenusProc;
    WM_SYSCOMMAND:
      case Msg.wParam and $FFF0 of
        SC_MINIMIZE:
          if Assigned(ActiveMenu) then
          begin
            ParentForm := GetParentForm(ActiveMenu);
            if Assigned(ParentForm) and (ParentForm.Handle = Msg.hwnd) and
               Assigned(ActiveMenu) then
              ActiveMenu.CloseMenu;
          end;
      end;
    WM_WINDOWPOSCHANGING:
      if Assigned(ActiveMenu) then
      begin
        ParentForm := GetParentForm(ActiveMenu);
        if Assigned(ParentForm) and (ParentForm.Handle = Msg.hwnd) then
          if (PWindowPos(Msg.lParam).flags and SWP_NOMOVE <> SWP_NOMOVE) or
             (PWindowPos(Msg.lParam).flags and SWP_HIDEWINDOW = SWP_HIDEWINDOW) then
          begin
            ActiveMenu.CloseMenu;
            ActiveMenu := nil;
          end;
      end;
    WM_ACTIVATEAPP:
      begin
        if Assigned(ActiveMenu) then
        begin
          ActiveMenu.CloseMenu;
          ActiveMenu := nil;
          Application.ProcessMessages;
        end;
        if not Assigned(ActionBarDesigner) then
          for I := 0 to MenuList.Count - 1 do
            if MenuList.Menus[I] is TCustomActionMainMenuBar then
              TCustomActionMainMenuBar(MenuList.Menus[I]).Inactive := Msg.wParam = 0;
      end;
  end;
  Result := CallNextHookEx(MenuCallWndHook, Code, WParam, Longint(Msg));
end;

procedure AddMenuToList(Menu: TCustomActionMenuBar);
begin
  if MenuList = nil then
    MenuList := TMenuList.Create;
  if Assigned(Menu) and (MenuList.IndexOf(Menu) = -1) then
    MenuList.Add(Menu);
end;

procedure RemoveMenuFromList(Menu: TCustomActionMenuBar);
begin
  if Assigned(MenuList) then
    MenuList.Remove(Menu);
  if MenuList.Count = 0 then
    FreeAndNil(MenuList);
end;

procedure TMenuList.Notify(Ptr: Pointer; Action: TListNotification);
begin
  if (Action = lnAdded) and (Count = 1) then
    MenuCallWndHook := SetWindowsHookEx(WH_CALLWNDPROC, @CallWndHook, 0,
      GetCurrentThreadID)
  else if (Action = lnDeleted) and (Count = 0) then
  begin
    if MenuKeyHook <> 0 then
      UnHookWindowsHookEx(MenuKeyHook);
    if MenuCallWndHook <> 0 then
      UnHookWindowsHookEx(MenuCallWndHook);
  end;
  inherited Notify(Ptr, Action);
end;

{ TCustomActionMenuBar }

constructor TCustomActionMenuBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FAnimationStyle := asDefault;
  FRegistry := TRegistry.Create;
  EdgeOuter := esNone;
  // Expand delay interval should probably come from the registry (somewhere)
  FExpandDelay := 4000;
  FDefaultFont := True;
  FAnimatePopups := True;
  AddMenuToList(Self);
end;

destructor TCustomActionMenuBar.Destroy;
begin
  RemoveMenuFromList(Self);
  if Assigned(FParentMenu) then
    FParentMenu.FChildMenu := nil;
  FreeAndNil(FRegistry);
  inherited Destroy;
end;

procedure TCustomActionMenuBar.Animate(Show: Boolean = True);
type
  TAnimationStyle = array[Boolean] of Integer;
var
  Animate: BOOL;
  P: TPoint;
const
  HideShow: array[Boolean] of Integer = (AW_HIDE, 0);
  UnfoldAnimationStyle: TAnimationStyle =
    (AW_VER_POSITIVE or AW_HOR_POSITIVE or AW_SLIDE,
     AW_VER_NEGATIVE or AW_HOR_POSITIVE or AW_SLIDE);
  SlideAnimationStyle: TAnimationStyle =
    (AW_VER_POSITIVE or AW_SLIDE, AW_VER_NEGATIVE or AW_SLIDE);
  FadeAnimationStyle: TAnimationStyle = (AW_BLEND, AW_BLEND);

  procedure DefaultSystemAnimation;
  begin
    SystemParametersInfo(SPI_GETMENUANIMATION, 0, @Animate, 0);
    if Assigned(AnimateWindowProc) and (FParentMenu.FAnimatePopups or
       not Show) and Animate then
    begin
      SystemParametersInfo(SPI_GETMENUFADE, 0, @Animate, 0);
      if Animate then
        AnimateWindowProc(Handle, 180, AW_BLEND or HideShow[Show])
      else
      begin
        P := FParentControl.ClientToScreen(Point(FParentControl.Left, FParentControl.Top));
        AnimateWindowProc(Handle, 180, UnfoldAnimationStyle[Top < P.Y] or
          HideShow[Show]);
      end;
    end;
  end;

  procedure DoAnimation(Style: TAnimationStyle);
  begin
    if Assigned(AnimateWindowProc) and FParentMenu.FAnimatePopups or not Show then
    begin
      P := FParentControl.ClientToScreen(Point(FParentControl.Left, FParentControl.Top));
      if (FAnimationStyle = asSlide) and not Show then exit;
      if FParentControl is TCustomMenuItem then
        P := Point(FParentControl.Left + FParentControl.Parent.Left,
          FParentControl.Top + FParentControl.Parent.Top)
      else
        P := FParentControl.ClientToScreen(Point(FParentControl.Left, FParentControl.Top));
      AnimateWindowProc(Handle, 180, Style[P.Y > Top + 2] or HideShow[Show]);
    end;
  end;

begin
  if DesignMode then exit;
  case FAnimationStyle of
    asDefault: DefaultSystemAnimation;
    asUnFold : DoAnimation(UnfoldAnimationStyle);
    asSlide  : DoAnimation(SlideAnimationStyle);
    asFade   : DoAnimation(FadeAnimationStyle);
  end;
end;

procedure TCustomActionMenuBar.CleanupStack;
begin
  if not FPopupStack.Peek.FInMenuLoop then
    FPopupStack.Peek.CloseMenu;
end;

procedure TCustomActionMenuBar.ClearSubMenus;
var
  I: Integer;
begin
  if not FInMenuLoop then exit;
  for I := 1 to FPopupStack.Count - 1 do
    FPopupStack.Peek.CloseMenu;
  Application.ProcessMessages;
end;

procedure TCustomActionMenuBar.CloseMenu;
begin
  if Assigned(RootMenu) then
    RootMenu.DelayItem := nil;
  if Assigned(ParentMenu) then
    ParentMenu.FAnimatePopups := False;
  InMenuLoop := False;
  if Assigned(RootMenu) and Assigned(RootMenu.PopupStack) then
  begin
    if RootMenu.PopupStack.Peek = RootMenu then
    begin
      FInMenuLoop := False;
      if Assigned(Selected) then
        Selected.Control.Selected := False;
    end
    else
      RootMenu.PopupStack.Pop.Free;
  end;
end;

procedure TCustomActionMenuBar.CMItemClicked(var Message: TCMItemMsg);
begin
  if not FInMenuLoop then
  begin
    PostMessage(Handle, Message.Msg, 0, LongInt(Message.Sender));
    TrackMenu;
  end;
end;

procedure TCustomActionMenuBar.CMEnterMenuLoop(var Message: TMessage);
begin
  TrackMenu;
end;

procedure TCustomActionMenuBar.CMItemKeyed(var Message: TCMItemMsg);
begin
  if not FInMenuLoop then
  begin
    PostMessage(Handle, CM_ITEMKEYED, 0, LongInt(Message.Sender));
    TrackMenu;
  end;
end;

function TCustomActionMenuBar.CreateControl(
  AnItem: TActionClientItem): TCustomActionControl;
const
  Alignment: array [TBarOrientation] of TAlign = (alNone, alNone, alTop,
    alTop);
begin
  Result := inherited CreateControl(AnItem);
  Result.ShowHint := False;
  AnItem.ShowCaption := True;
  if not Result.Separator then
    Result.Enabled := Result.Enabled and (Assigned(AnItem.Action) or
      (AnItem.HasItems and (AnItem.Items.VisibleCount > 0)));
end;

function TCustomActionMenuBar.CreatePopup(AOwner: TCustomActionMenuBar;
  Item: TCustomActionControl): TCustomActionPopupMenu;
var
  OldVisible: Boolean;
  I: Integer;
begin
  Result := nil;
  if not InMenuLoop or (AOwner = nil) or (Item = nil) or (FPopupStack.Count = 0) or
     (FPopupStack.Peek.ParentControl = Item) or (Item.ActionClient = nil) or
     (Item.ActionClient.Items.VisibleCount = 0) then
    exit;
  FDelayItem := nil;
  Result := NewPopup;
  with Result do
  begin
    RootMenu := Self.RootMenu;
    Item.ActionClient.ChildActionBar := Result;
    ParentMenu := AOwner;
    FInMenuLoop := True;
    ParentControl := Item;
    Parent := Self;
    OldVisible := Item.ActionClient.Visible;
    ActionClient := Item.ActionClient;
    for I := 0 to ItemCount - 1 do
      if Assigned(Items[I].Action) then
        Items[I].Action.Update;
    Item.ActionClient.Visible := OldVisible;
    if Assigned(FOnPopup) then
      FOnPopup(Self, Item);
    Expanded := Self.Expanded or Self.DesignMode or (FindFirstVisibleItem = nil);
    if Expanded then
      Expand(False);
    DesignMode := AOwner.DesignMode;
    Show;
  end;
  FPopupStack.Push(Result);
  FExpandTimer.Enabled := Result.Expandable and not Result.Expanded;
end;

procedure TCustomActionMenuBar.DoItemSelected(AnItem: TCustomActionControl);
begin
  if AnItem is TCustomMenuItem then
    RootMenu.FDelayItem := AnItem
  else
    FDelayItem := nil;
  RootMenu.FPopupTimer.Enabled := True;
  // Reset the expand timer every time new item is selected
  if not RootMenu.FPopupStack.Peek.Expandable {or (AnItem.Owner = Self)} then
    exit;
  RootMenu.FExpandTimer.Enabled := False;
  // Tag = 1 indicates that when the timer fires that it should only
  // highlight the expand button rather than expand the popup menu
  if Selected <> FindFirstVisibleItem then
    RootMenu.FExpandTimer.Tag := 1;
  RootMenu.FExpandTimer.Enabled := not DesignMode;
end;

procedure TCustomActionMenuBar.ExecAction(Action: TContainedAction);
begin
  if (Action = nil) or (csDesigning in ComponentState) then exit;
  if not DesignMode then
  begin
    if Length(RootMenu.FCommandSound) > 0 then
      sndPlaySound(PChar(RootMenu.FCommandSound), SND_NOSTOP or SND_ASYNC);
    Action.Execute;
  end;
end;

function TCustomActionMenuBar.DoGetPopupClass: TCustomPopupClass;
begin
  if Assigned(FOnGetPopupClass) then
    FOnGetPopupClass(Self, Result)
  else
    Result := GetPopupClass;
end;

function TCustomActionMenuBar.DoItemClicked(
  AnItem: TCustomActionControl): TActionClientItem;
var
  SelectionFade: BOOL;
  I: Integer;
begin
  Result := nil;
  if (AnItem.Owner = Self) then
  begin
    if Assigned(AnItem.ActionClient.ChildActionBar) then
    begin
      CloseMenu;
      exit;
    end;
    ClearSubMenus;
    FDelayItem := nil;
  end;
  if AnItem.ActionClient.HasItems then
  begin
    if Assigned(FDelayItem) then
    begin
      while FPopupStack.Peek <> FDelayItem.Parent do
        FPopupStack.Pop.Free;
      FDelayItem := nil;
    end;
    Application.ProcessMessages;
    CreatePopup(FPopupStack.Peek, AnItem);
    FAnimatePopups := False;
  end
  else
  begin
    Result := AnItem.ActionClient;
    if not DesignMode then
    begin
      SystemParametersInfo(SPI_GETSELECTIONFADE, 0, @SelectionFade, 0);
      if (FPopupStack.Count > 1) and SelectionFade then
      begin
        for I := 1 to FPopupStack.Count - 2 do
          FPopupStack.Bars[I].Visible := False;
        FPopupStack.Peek.Animate(False);
      end;
      ClearSubMenus;
      CloseMenu;
    end;
  end;
end;

function TCustomActionMenuBar.DoItemKeyed(
  AnItem: TCustomActionControl): TActionClientItem;
var
  Item: TActionClientItem;
begin
  FItemKeyed := True;
  Result := DoItemClicked(AnItem);
  if not Assigned(Result) then
  begin
    // if the keyboard was used to display the popup then automatically
    // select the first item if the mouse was used no item is selected
    Item := FPopupStack.Peek.FindFirstVisibleItem;
    if Assigned(Item) and Assigned(Item.Control) then
      Item.Control.Selected := True;
  end;
end;

procedure TCustomActionMenuBar.GetDefaultSounds;

  function ReadSoundSetting(KeyStr: string): string;
  var
    S: string;
  begin
    FRegistry.RootKey := HKEY_CURRENT_USER;
    Result := '';
    if FRegistry.OpenKeyReadOnly('\AppEvents\Schemes\Apps\.Default\' + KeyStr) then { do not localize }
    try
      S := FRegistry.ReadString('');
      SetLength(Result, 4096);
      SetLength(Result, ExpandEnvironmentStrings(PChar(S), PChar(Result), 4096) - 1);
    finally
      FRegistry.CloseKey;
    end;
  end;

begin
  FPopupSound := ReadSoundSetting('MenuPopup\.Current');      { do not localize }
  FCommandSound := ReadSoundSetting('MenuCommand\.Current');  { do not localize }
end;

function TCustomActionMenuBar.IsDesignMsg(var Msg: TMsg): Boolean;
var
  ParentForm: TCustomForm;
begin
  Result := DesignMode and not Mouse.IsDragging;
  if Result then
  begin
    Result := Assigned(FDragItem) or Mouse.IsDragging;
    if Result then  // Allow mouse up to end the drag operation
    begin
      Result := (Msg.message <> WM_LBUTTONUP);
      exit;
    end;
    ParentForm := GetParentForm(RootMenu);
    Result := Assigned(ParentForm) and (GetForeGroundWindow <> ParentForm.Handle);
    if csDesigning in ComponentState then
      Result := Result and (Msg.Message <> CM_ITEMCLICKED);
  end;
end;

procedure TCustomActionMenuBar.DoMenuDelay(Sender: TObject);
var
  P: TPoint;
begin
  FPopupTimer.Enabled := False;
  if DelayItem = nil then exit;
  if (FDelayItem.Parent = nil) or
     Assigned(FDelayItem.ActionClient.ChildActionBar) then exit;
  while (RootMenu.PopupStack.Count > 1) and
        (RootMenu.PopupStack.Peek <> FDelayItem.Parent)  do
    RootMenu.PopupStack.Pop.Free;
  GetCursorPos(P);
  if PtInRect(FDelayItem.BoundsRect, FPopupStack.Peek.ScreenToClient(P)) then
    CreatePopup(FPopupStack.Peek, FDelayItem);
end;

procedure TCustomActionMenuBar.DoneMenuLoop;
begin
  CloseMenu;
  ActiveMenu := nil;
  if Assigned(ActionBarDesigner) then
    ActionBarDesigner.SetActiveMenu(nil);
  FAnimatePopups := True;
  ShowCaret(0);
  FreeAndNil(FPopupTimer);
  FreeAndNil(FPopupStack);
  FreeAndNil(FExpandTimer);
end;

procedure TCustomActionMenuBar.Expand(Full: Boolean);
var
  I: Integer;
begin
  FExpanded := True;
  if Full then
    RootMenu.Expanded := Full;
  FExpandable := False;
  if not HasItems then exit;
  DisableAlign;
  try
    for I := 0 to Items.Count - 1 do
      Items[I].Control.Visible := Items[I].Visible;
  finally
    EnableAlign;
  end;
end;

procedure TCustomActionMenuBar.ExpandTimer(Sender: TObject);
begin
  FExpandTimer.Enabled := False;
  if RootMenu.PopupStack.Peek.Expandable then
    // Tag = 1 indicates that when the timer fires that it should only
    // highlight the expand button rather than expand the popup menu
    if FExpandTimer.Tag = 1 then
      with TCustomActionPopupMenu(FPopupStack.Peek).ExpandBtn do
        Flat := False
    else
    begin
      FExpanded := True;
      FPopupStack.Peek.Expand(True);
    end;
end;

function TCustomActionMenuBar.GetControlClass(
  AnItem: TActionClientItem): TCustomActionControlClass;
begin
  Result := MenuItemControlClass
end;

function TCustomActionMenuBar.GetDesignMode: Boolean;
begin
  Result := inherited GetDesignMode;
  if not Result and Assigned(FParentMenu) then
    Result := FParentMenu.DesignMode;
end;

function TCustomActionMenuBar.GetMouseHoverItem(Msg: TMsg): TCustomActionControl;
var
  I: Integer;
  Control: TControl;
  ARootMenu: TCustomActionMenuBar;
begin
  Result := nil;
  Control := nil;
  ARootMenu := RootMenu;
  if Assigned(ARootMenu) then
  begin
    for I := ARootMenu.PopupStack.Count - 1 downto 0 do
      if WindowFromPoint(Msg.pt) = ARootMenu.PopupStack.Bars[I].Handle then
        with ARootMenu.PopupStack.Bars[I] do
          Control := ControlAtPos(ScreenToClient(Msg.Pt), True);

    if Control is TCustomActionControl then
      Result := TCustomActionControl(Control);
  end;
end;

function TCustomActionMenuBar.GetPopupClass: TCustomPopupClass;
begin
  Result := MenuPopupClass;
end;

function TCustomActionMenuBar.GetSelected: TActionClientItem;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to ItemCount - 1 do
    if Assigned(ActionControls[I]) and ActionControls[I].Selected then
    begin
      Result := ActionControls[I].ActionClient;
      break;
    end;
end;

procedure TCustomActionMenuBar.InitMenuLoop;
var
  DelayTime: DWORD;
begin
  GetDefaultSounds;
  FExpanded := False;
  FDelayItem := nil;
  if csDesigning in ComponentState then
    DelayTime := 1
  else
  begin
    SystemParametersInfo(SPI_GETMENUSHOWDELAY, 0, @DelayTime, 0);
    if DelayTime = 0 then
      Inc(Delaytime);
  end;
  FPopupTimer := TTimer.Create(nil);
  FPopupTimer.OnTimer := DoMenuDelay;
  FPopupTimer.Interval := DelayTime;
  FPopupStack := TMenuStack.Create;
  FPopupStack.Push(Self);
  FExpandTimer := TTimer.Create(nil);
  with FExpandTimer do
  begin
    Enabled := False;
    Interval := FExpandDelay;
    OnTimer := ExpandTimer;
  end;
  FInMenuLoop := True;
  HideCaret(0);
  ActiveMenu := Self;
  if Assigned(ActionBarDesigner) then
    ActionBarDesigner.SetActiveMenu(ActiveMenu);
end;

procedure TCustomActionMenuBar.ProcessMouseMsg(var Msg: TMsg);
var
  Item: TCustomActionControl;
  Control: TControl;
  Form: TCustomForm;
begin
  Item := GetMouseHoverItem(Msg);
  if not Assigned(Item) then
    case Msg.message of
      WM_MOUSEMOVE:
        if Mouse.IsDragging and
           (WindowFromPoint(Msg.pt) <> RootMenu.PopupStack.Peek.Handle) then
        begin
          Form := GetParentForm(Self);
          if Assigned(Form) then
          begin
            Control := Form.ControlAtPos(ScreenToClient(Msg.pt), False, True);
            if Assigned(Control) and ((Control is TCustomActionBar) or
               (Control is TCustomActionControl)) then
              RootMenu.CloseMenu;
          end;
        end;
      WM_MBUTTONDOWN,
      WM_RBUTTONDOWN,
      WM_LBUTTONDOWN:
        RootMenu.CloseMenu;
    end;
  DispatchMessage(Msg);
end;

function TCustomActionMenuBar.ProcessMenuLoop: TActionClientItem;
var
  Msg: TMsg;
begin
  Result := nil;
  if FInMenuLoop then exit;
  InitMenuLoop;
  try
    repeat
      if PeekMessage(Msg, 0, 0, 0, PM_REMOVE) then
      begin
        // Allow keystroke messages to be propagated to the IDE at designtime
        if (csDesigning in ComponentState) and
           TApplicationClass(Application).IsKeyMsg(Msg) then
          Continue;
        if IsDesignMsg(Msg) then
        begin
          TranslateMessage(Msg);
          DispatchMessage(Msg);
          Continue;
        end;
        case Msg.message of
          CM_RELEASE,
          WM_CLOSE:
            begin
              CloseMenu;
              Application.ProcessMessages;
              DispatchMessage(Msg);
            end;
          WM_NCRBUTTONDOWN,
          WM_NCLBUTTONDOWN:
            begin
              if not (csDesigning in ComponentState) or
                 (Msg.hwnd = GetParentForm(Self).Handle) then
              begin
                CloseMenu;
                Application.ProcessMessages;
              end;
              DispatchMessage(Msg);
            end;
          WM_KEYFIRST..WM_KEYLAST:
            begin
              if not PersistentHotKeys then
                PersistentHotkeys := True;
              FPopupStack.Peek.WndProc(TMessage((@Msg.message)^));
            end;
          WM_MOUSEFIRST..WM_MOUSELAST: ProcessMouseMsg(Msg);
          CM_ITEMSELECTED: DoItemSelected(TCustomActionControl(Msg.lParam));
          CM_ITEMKEYED  :
            Result := DoItemKeyed(TCustomActionControl(Msg.lParam));
          CM_ITEMCLICKED:
            Result := DoItemClicked(TCustomActionControl(Msg.lParam));
        else
          TranslateMessage(Msg);
          DispatchMessage(Msg);
        end;
        CleanupStack;
      end
      else
        TApplicationClass(Application).Idle(Msg);
    until not FInMenuLoop;
  finally
    DoneMenuLoop;
  end;
end;

procedure TCustomActionMenuBar.Select(const Forward: Boolean);
var
  NextItem: TActionClientItem;

  procedure SkipItems(const Forward: Boolean);
  begin
    while Assigned(NextItem) and ((NextItem.Separator) or
       (Assigned(NextItem.Control) and (not NextItem.Control.Visible))) do
      if Forward then
        NextItem := FindNext(NextItem)
      else
        NextItem := FindPrevious(NextItem);
  end;

begin
  if Forward then
    NextItem := FindNext(Selected)
  else
    NextItem := FindPrevious(Selected);
  if not DesignMode then
    SkipItems(Forward);
  if NextItem = nil then exit;
  if (RootMenu.PopupStack.Peek = Self) then
    if DesignMode and (KeyboardStateToShiftState = [ssCtrl]) and
       Assigned(NextItem) and Assigned(Selected) then
      Selected.Index := NextItem.Index
    else
      SelectItem(NextItem.Control)
  else
    if (NextItem.Control.Parent = Self) and Assigned(NextItem.Action) then
    begin
      RootMenu.PopupStack.Peek.FInMenuLoop := False;
      RootMenu.FDelayItem := nil;
      NextItem.Control.Selected := True;
    end
    else
      NextItem.Control.Keyed;
  if Assigned(ActionBarDesigner) then
    ActionBarDesigner.SetSelection(NextItem);
end;

procedure TCustomActionMenuBar.SelectItem(AnItem: TCustomActionControl);
begin
  if (AnItem = nil) then exit;
  AnItem.Selected := True;
  if csDesigning in ComponentState then
    ActionBarDesigner.SetSelection(AnItem.ActionClient);
end;

procedure TCustomActionMenuBar.SetDesignMode(const Value: Boolean);
begin
  if DesignMode and not Value and FInMenuLoop then
    CloseMenu;
  inherited SetDesignMode(Value);
end;

procedure TCustomActionMenuBar.SetParentMenu(
  const Value: TCustomActionMenuBar);
begin
  if FParentMenu <> Value then
  begin
    FParentMenu := Value;
    if Assigned(FParentMenu) then
    begin
      FParentMenu.FChildMenu := Self;
      PersistentHotkeys := FParentMenu.PersistentHotkeys;
      if Assigned(FParentMenu.OnGetControlClass) then
        OnGetControlClass := FParentMenu.OnGetControlClass;
      FAnimationStyle := FParentMenu.AnimationStyle;
    end;
  end;
end;

procedure TCustomActionMenuBar.SetPersistentHotkeys(const Value: Boolean);
var
  I: Integer;
  UpdatePopups: Boolean;
begin
  UpdatePopups := (Value <> PersistentHotkeys) and Value;
  inherited SetPersistentHotkeys(Value);
  if UpdatePopups and Assigned(FPopupStack) then
    for I := 0 to FPopupStack.Count - 1 do
      TCustomActionMenuBar(FPopupStack.List[I]).PersistentHotkeys := True;
end;

procedure TCustomActionMenuBar.TrackMenu;
var
  Item: TActionClientItem;
begin
  if InMenuLoop then exit;
  FRootMenu := Self;
  Item := ProcessMenuLoop;
  if Assigned(Item) then
    ExecAction(Item.Action);
end;

procedure TCustomActionMenuBar.WndProc(var Message: TMessage);
begin
  case Message.Msg of
    WM_NCHITTEST: Message.Result := HTCLIENT;
  end;
  inherited WndProc(Message);
end;

procedure TCustomActionMenuBar.WMKeyDown(var Message: TWMKeyDown);
var
  Item: TActionClientItem;
begin
  inherited;
  if not FInMenuLoop then exit;
  if (RootMenu <> nil) and (Chr(Message.CharCode) in ['0'..'9', 'A'..'Z']) then
  begin
    Item := RootMenu.PopupStack.Peek.FindAccelItem(Message.CharCode);
    if Assigned(Item) then
      Item.Control.Keyed;
  end;
  case Message.CharCode of
    VK_UP  : Select(False);
    VK_DOWN: Select(True);
    VK_HOME: SelectItem(FindFirstVisibleItem.Control);
    VK_END : SelectItem(FindLastVisibleItem.Control);
    VK_RETURN:
      if Assigned(Selected) then
        Selected.Control.Keyed;
    VK_ESCAPE:
      if DesignMode and Assigned(FDragItem) then
        DragDone(False)
      else
        if Mouse.IsDragging then
          CancelDrag
        else
          CloseMenu;
  end;
end;

procedure TCustomActionMenuBar.WMMouseActivate(var Message: TWMMouseActivate);
begin
  inherited;
  if FInMenuLoop then
    Message.Result := MA_NOACTIVATE;
end;

procedure TCustomActionMenuBar.WMSysKeyDown(var Message: TWMSysKeyDown);
var
  Item: TActionClientItem;
begin
  inherited;
  if not FInMenuLoop then exit;
  if (RootMenu <> nil) and
     (Chr(Message.CharCode) in ['0'..'9', 'A'..'Z']) then
  begin
    Item := RootMenu.PopupStack.Peek.FindAccelItem(Message.CharCode);
    if Assigned(Item) and Assigned(Item.Control) then
      Item.Control.Keyed;
  end;
  if (Message.CharCode = VK_MENU) then
    RootMenu.CloseMenu;
end;

{ TCustomMenuExpandBtn }

procedure TCustomMenuExpandBtn.DragOver(Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
 // This control should not participate in drag/drop at all
end;

procedure TCustomMenuExpandBtn.DrawBackground(var PaintRect: TRect);
begin
  OffsetRect(PaintRect, 0, 1);
  InflateRect(PaintRect, -2, -4);
  if MouseInControl then
    Canvas.Brush.Color := GetHighLightColor(Color)
  else
    Canvas.Brush.Color := Color;
  inherited DrawBackGround(PaintRect);
end;

procedure TCustomMenuExpandBtn.DrawFrame(ARect: TRect; Down: Boolean);
begin
  OffsetRect(ARect, 0, 1);
  InflateRect(ARect, -2, -4);
  inherited DrawFrame(ARect, Down);
end;

{ TCustomActionPopupMenu }

constructor TCustomActionPopupMenu.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csNoDesignVisible];
  Visible := False;
  Align := alNone;
  Orientation := boTopToBottom;
  EdgeBorders := [ebLeft, ebTop, ebRight, ebBottom];
  EdgeInner := esRaised;
  EdgeOuter := esRaised;
  VertMargin := 1;
  FExpandBtn := nil;
  if AOwner is TCustomActionBar then
    ActionManager := TCustomActionBar(AOwner).ActionManager;
end;

destructor TCustomActionPopupMenu.Destroy;
begin
  if Assigned(ActionClient) then
    ActionClient.ChildActionBar := nil;
  Visible := False;
  FreeAndNil(FExpandBtn);
  inherited Destroy;
end;

procedure TCustomActionPopupMenu.AddEdges(AnItem: TCustomMenuItem);
var
  PrevItem: TActionClientItem;
  NextItem: TActionClientItem;
  Edges: TMenuEdges;
begin
  if (AnItem = nil) or (AnItem.ActionClient = nil) then exit;
  PrevItem := FindPreviousVisibleItem(AnItem.ActionClient);
  NextItem := FindNextVisibleItem(AnItem.ActionClient);
  if AnItem.ActionClient.Unused then
  begin
    Edges := [];
    if FExpanded and ((PrevItem = nil) or not PrevItem.Unused) then
      if AnItem.ActionClient <> FindFirst then
        Edges := Edges + [ebTop];
    if FExpanded and ((NextItem = nil) or not NextItem.Unused) then
      if AnItem.ActionClient <> FindLast then
        Edges := Edges + [ebBottom];
    AnItem.Edges := Edges;
  end
  else
  begin
    if Assigned(PrevItem) and PrevItem.Unused then
      if PrevItem.Control is TCustomMenuItem then
        with PrevItem.Control as TCustomMenuItem do
          Edges := Edges + [ebBottom];
    if Assigned(NextItem) and NextItem.Unused then
      if NextItem.Control is TCustomMenuItem then
        with NextItem.Control as TCustomMenuItem do
          Edges := Edges + [ebTop];
  end;
end;

procedure TCustomActionPopupMenu.CMMouseLeave(var Message: TMessage);
begin
  inherited;
  if Assigned(Selected) and not Assigned(Selected.ChildActionBar) then
    Selected.Control.Selected := False;
end;

procedure TCustomActionPopupMenu.CMVisibleChanged(var Message: TMessage);
begin
  inherited;
  if not (csDesigning in ComponentState) and Visible and Assigned(RootMenu) and
     (Length(RootMenu.FPopupSound) > 0) then
    sndPlaySound(PChar(RootMenu.FPopupSound), SND_NOSTOP or SND_ASYNC);
end;

function TCustomActionPopupMenu.CreateControl(
  AnItem: TActionClientItem): TCustomActionControl;
begin
  Result := inherited CreateControl(AnItem);
  if (Result is TCustomMenuItem) then
    AddEdges(Result as TCustomMenuItem);
  if not Expanded and Result.ActionClient.Unused then
  begin
    FExpandable := True;
    Result.Visible := False;
  end;
  Result.CalcBounds;
  if Result.Visible then
  begin
    Inc(FMenuSize.Y, Result.Height);
    if Result.Width > FMenuSize.X then
      FMenuSize.X := Result.Width + 3;
  end;
  Inc(FExpandedSize.Y, Result.Height);
  if AnItem.Visible then
    if (Result.Width + 3 > FExpandedSize.X) then
      FExpandedSize.X := Result.Width + 3;
  if Visible then
    if Expanded then
      SetBounds(Left, Top, FExpandedSize.X, FExpandedSize.Y)
    else
      SetBounds(Left, Top, FMenuSize.X, FMenuSize.Y)
end;

procedure TCustomActionPopupMenu.CreateControls;
var
  I: Integer;
begin
  FMenuSize := Point(4, VertMargin * 2 + 4);
  FExpandedSize := Point(3, VertMargin * 2 + 4);
  inherited CreateControls;
  I := GetBannerWidth(beEither);
  Inc(FMenuSize.X, I);
  Inc(FExpandedSize.X, I);
  if FExpandable and (FindFirstVisibleItem <> nil) then
  begin
    SetupExpandBtn;
    Inc(FMenuSize.Y, GetSystemMetrics(SM_CYMENU));
  end;
  SetBounds(Left, Top, FMenuSize.X, FMenuSize.Y);
end;

procedure TCustomActionPopupMenu.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  with Params do
  begin
    if Assigned(Parent) and not (Parent is TCustomForm) then
      Style := Style and not WS_CHILD or WS_POPUP or WS_OVERLAPPED;
    WindowClass.Style := CS_SAVEBITS or CS_DBLCLKS or not (CS_HREDRAW or not CS_VREDRAW);
    if not DesignMode then
      ExStyle := ExStyle or WS_EX_TOPMOST;
  end;
end;

function TCustomActionPopupMenu.DesignWndProc(var Message: TMessage): Boolean;
begin
  Result := True;
end;

procedure TCustomActionPopupMenu.ExecAction(Action: TContainedAction);
begin
  Hide;
  inherited ExecAction(Action);
end;

procedure TCustomActionPopupMenu.Expand(Full: Boolean);
var
  I: Integer;
begin
  FExpanded := True;
  FExpandedSize.Y := VertMargin * 2 + 4;
  DisableAlign;
  try
    inherited Expand(Full);
    for I := 0 to Items.Count - 1 do
      if Items[I].Visible then
        if (Items[I].Control is TCustomMenuItem) then
        begin
          AddEdges(TCustomMenuItem(Items[I].Control));
          Items[I].Control.CalcBounds;
          Inc(FExpandedSize.Y, Items[I].Control.Height);
        end
        else
          Inc(FExpandedSize.Y, Items[I].Control.Height);
    // Reposition menu in case new size no longer fits at the previous location
    SetBounds(Left, Top, Width, Height);
    if Assigned(FParentControl) then
      PositionPopup(TCustomActionBar(FParentControl.Owner), FParentControl);
  finally
    EnableAlign;
  end;
end;

procedure TCustomActionPopupMenu.ExpandClick(Sender: TObject);
begin
  while RootMenu.PopupStack.Peek <> Self do
    RootMenu.PopupStack.Pop.Free;
  Expand(True);
end;

function TCustomActionPopupMenu.GetBarHeight: Integer;
begin
  if Expanded then
    if AlignDisabled then
      Result := Height
    else
      Result := FExpandedSize.Y
  else
    Result := FMenuSize.Y;
end;

procedure TCustomActionPopupMenu.Popup(X, Y: Integer);
begin
  if ItemCount = 0 then exit;
  ParentWindow := Application.Handle;
  SetBounds(X, Y, FMenuSize.X, FMenuSize.Y);
  FRootMenu := Self;
  Show;
  if FindFirstVisibleItem = nil then
    Expand(False);
  Visible := True;
  TrackMenu;
  Visible := False;
end;

procedure TCustomActionPopupMenu.PositionPopup(AnOwner: TCustomActionBar;
  ParentItem: TCustomActionControl);

  function MonitorSize(A, B: Integer): Integer;
  begin
    Result := B;
    if A > 0 then
      Inc(Result, A);
  end;

var
  P: TPoint;
  R: TRect;
  Item: TActionClientItem;
  LeftAlign: BOOL;
  Monitor: TMonitor;
begin
  if (AnOwner = nil) or (ParentControl = nil) then exit;
  with ParentControl do
    case AnOwner.Orientation of
      boLeftToRight: P := AnOwner.ClientToScreen(Point(Left + 1, Top + Height));
      boRightToLeft: P := AnOwner.ClientToScreen(Point(Left - Self.Width +
        Width, Top + Height));
    else
      // Popup menus overlap slightly
      if AnOwner.FindFirstVisibleItem.Control = FParentControl then
        P := AnOwner.ClientToScreen(Point(Left + Width - 5, Top - 3))
      else
      begin
        Item := FindFirstVisibleItem;
        if Assigned(Item) then
          P := AnOwner.ClientToScreen(Point(Left + Width - 5, Top - 3));
      end;
    end;
  // Adjust the position if the menu goes off the edge of the screen
  LeftAlign := True;
  SystemParametersInfo(SPI_GETMENUDROPALIGNMENT, 0, @LeftAlign, 0);
  R.TopLeft := FParentControl.ClientToScreen(FParentControl.BoundsRect.TopLeft);
  R.BottomRight := FParentControl.ClientToScreen(FParentControl.BoundsRect.BottomRight);
  Monitor := Screen.MonitorFromRect(R, mdNearest);
  if P.X < Monitor.Left then P.X := Monitor.Left;
  if P.X + Width > MonitorSize(Monitor.Left, Monitor.Width) then
  begin
    P.X := MonitorSize(Monitor.Left, Monitor.Width) - Width;
    if P.X + Width > Monitor.Left + Monitor.Width - AnOwner.Left +
       AnOwner.Width then
      P.X := AnOwner.Left - Width + 2;
  end;
  if P.Y + Height > MonitorSize(Monitor.Top, Monitor.Height) then
    P.Y := P.Y - FParentControl.Height - Height;
  SetBounds(P.X, P.Y, Width, Height);
end;

procedure TCustomActionPopupMenu.SetActionClient(const Value: TActionClient);
const
  InnerEdge: array[Boolean] of TEdgeStyle = (esRaised, esNone);
begin
  FExpandable := False;
  inherited SetActionClient(Value);
end;

procedure TCustomActionPopupMenu.SetBounds(ALeft, ATop, AWidth,
  AHeight: Integer);
begin
  if Expanded then
    inherited SetBounds(ALeft, ATop, FExpandedSize.X, FExpandedSize.Y)
  else
    inherited SetBounds(ALeft, ATop, FMenuSize.X, FMenuSize.Y);
end;

procedure TCustomActionPopupMenu.SetupExpandBtn;
begin
  if FExpandBtn = nil then
  begin
    FExpandBtn := TCustomMenuExpandBtn.Create(Self);
    with FExpandBtn do
    begin
      Align := alCustom;
      AutoScroll := True;
      Parent := Self;
      ArrowSize := 2;
      Hint := SExpand;
      ArrowType := atArrows;
      Direction := sdDown;
      Transparent := Self.ActionClient.HasBackground and
        not (Self.ActionClient.BackgroundLayout in [blLeftBanner, blRightBanner]);
      OnClick := ExpandClick;
    end;
  end;
end;

procedure TCustomActionPopupMenu.SetOrientation(const Value: TBarOrientation);
begin
  // Popup menus can only have vertical orientation
  if Value in [boTopToBottom, boBottomToTop] then
    inherited SetOrientation(Value);
end;

procedure TCustomActionPopupMenu.WMKeyDown(var Message: TWMKeyDown);
var
  Item: TActionClientItem;
  SelIndex: Integer;
begin
  case Message.CharCode of
    VK_SUBTRACT:
      if DesignMode and (Selected <> nil) then
      begin
        Item := TActionClientItem(Items.Insert(Selected.Index));
        Item.Caption := '-';
        Item.Control.Visible := True;
        Item.Control.Selected := True;
      end;
    VK_LEFT:
      if Assigned(FChildMenu) then
      begin
        FChildMenu.FInMenuLoop := False;
        Message.Result := 0;
      end
      else
        if Assigned(FParentMenu) then
          FParentMenu.Dispatch(Message);
    VK_RIGHT:
      begin
        if Assigned(Selected) and Assigned(Selected) then
        begin
          if DesignMode and not Selected.HasItems and
             not Selected.Separator and (Selected.Action = nil) then
            if ssCtrl in KeyboardStateToShiftState then
            begin
              Selected.Items.Add;
              Selected.Control.Invalidate;
            end;
          if Selected.HasItems and
             (Selected.Control.Enabled or DesignMode) then
            Selected.Control.Keyed
          else
            if FPopupStack = nil then
              Parent.Dispatch(Message);
        end
        else
          Parent.Dispatch(Message);
      end;
    VK_DOWN:
      if (Message.CharCode = VK_DOWN) and FExpandable and
         ((Selected = FindLastVisibleItem) or
         (ssCtrl in KeyboardStateToShiftState)) then
      begin
        FExpandBtn.Click;
        SelectItem(FindFirstVisibleItem.Control);
        exit;
      end;
    VK_INSERT:
      begin
        if not (csDesigning in ComponentState) then exit;
        if Selected = nil then exit;
        Item := Selected;
        SelIndex := Item.Index;
        if (ssShift in KeyboardStateToShiftState) then
          Inc(SelIndex);
        Item := TActionClientItem(ActionClient.Items.Insert(SelIndex));
        Item.Control.Selected := True;
        NotifyDesigner(Self);
      end;
    VK_DELETE:
      begin
        if not DesignMode or (Selected = nil) then exit;
        Item := Selected;
        if Item.HasItems and
           (MessageDlg(Format(SDeleteItemWithSubItems,
            [Item.Caption]), mtConfirmation, mbOKCancel, 0) <> mrOk) then
          exit;
        SelIndex := Item.Index;
        if SelIndex = ItemCount - 1 then
          Item := FindPrevious(Item, False)
        else
          Item := FindNext(Item, False);
        Dec(FExpandedSize.Y, ActionClient.Items[SelIndex].Control.Height);
        ActionClient.Items.Delete(SelIndex);
        if Assigned(Item) then
          Item.Control.Selected := True
        else
          PostMessage(RootMenu.Handle, CM_ITEMSELECTED, 0,
            LongInt(ParentControl));
        SetBounds(Left, Top, Width, FExpandedSize.Y);
        NotifyDesigner(Self);
      end;
  end;
  inherited;
end;

procedure TCustomActionPopupMenu.WMPrint(var Message: TMessage);
begin
  inherited;
  NCPaint(Message.WParam);
end;

procedure TCustomActionPopupMenu.WMPrintClient(var Message: TMessage);
var
  AHandle: HDC;
begin
  inherited;
  AHandle := Canvas.Handle;
  try
    Canvas.Handle := Message.WParam;
    Canvas.Brush.Color := Color;
    Canvas.FillRect(ClientRect);
    PaintTo(Message.WParam, 0, 0);
  finally
    Canvas.Handle := AHandle;
  end;
end;

procedure TCustomActionPopupMenu.VisibleChanging;
var
  Item: TActionClientItem;
begin
  inherited VisibleChanging;
  if not Visible then
  begin
    Item := FindFirstVisibleItem;
    if Assigned(Item) and Item.Separator then
    begin
      Item.Control.Visible := False;
      Dec(FMenuSize.Y, Item.Control.Height);
    end;
    Item := FindLastVisibleItem;
    if Assigned(Item) and Item.Separator then
    begin
      Item.Control.Visible := False;
      Dec(FMenuSize.Y, Item.Control.Height);
    end;
    PositionPopup(FParentMenu, FParentControl);
    if Assigned(FParentMenu) then
      Animate(True);
  end;
end;

function TCustomActionPopupMenu.GetControlClass(
  AnItem: TActionClientItem): TCustomActionControlClass;
begin
  Result := MenuItemControlClass;
end;

procedure TCustomActionPopupMenu.CloseMenu;
begin
  Visible := False;
  inherited CloseMenu;
end;

{ TCustomAddRemoveItem }

procedure TCustomAddRemoveItem.CalcBounds;
var
  R: TRect;
begin
  inherited CalcBounds;
  Width := Width + 18;
  GlyphPos := Point(GlyphPos.X + 18, GlyphPos.Y);
  R := TextBounds;
  OffsetRect(R, 18,0);
  TextBounds := R;
end;

function TCustomAddRemoveItem.IsActionVisible: Boolean;
var
  I: Integer;
  OwnerItems: TActionClients;
begin
  Result := False;
  OwnerItems := Menu.RootMenu.ParentControl.ActionBar.ActionClient.Items;
  for I := 0 to OwnerItems.Count - 1 do
    if OwnerItems[I].Action = ActionClient.Action then
    begin
      Result := OwnerItems[I].Visible;
      break;
    end;
end;

procedure TCustomAddRemoveItem.MouseUp(Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  Invalidate;
end;

procedure TCustomAddRemoveItem.SetEnabled(Value: Boolean);
begin
  inherited SetEnabled(True);
end;

{ TCustomizeActionToolBar }

constructor TCustomizeActionToolBar.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  if AOwner is TCustomActionToolBar then
    FActionBar := TCustomActionToolBar(AOwner);
end;

destructor TCustomizeActionToolBar.Destroy;
begin
  FResetAction.Free;
  inherited Destroy;
end;

procedure TCustomizeActionToolBar.Clear;
begin
end;

procedure TCustomizeActionToolBar.CMItemSelected(var Message: TCMItemMsg);
begin
  CloseMenu;
end;

function TCustomizeActionToolBar.GetActionControl(
  const Index: Integer): TCustomActionControl;
begin
  if (Index >= 0) and (Index < ItemCount) then
    Result := ActionClient.Items[Index].Control
  else
    Result := nil;
end;

function TCustomizeActionToolBar.ItemCount: Integer;
begin
  if Assigned(ActionClient) then
    Result := ActionClient.Items.Count
  else
    Result := 0;
end;

function TCustomizeActionToolBar.GetControlClass(
  AnItem: TActionClientItem): TCustomActionControlClass;
begin
  if AnItem.ParentItem <> TCustomizeActionToolbar(RootMenu).FAddlItem then
    Result := MenuItemControlClass
  else
    Result := MenuAddRemoveItemClass;
end;

type
  TWinCtrlClass = class(TWinControl);

function TCustomizeActionToolBar.DoItemClicked(
  AnItem: TCustomActionControl): TActionClientItem;

  function FindItem(MatchItem: TActionClientItem): TActionClientItem;
  var
    I: Integer;
    OwnerItems: TActionClients;
  begin
    Result := nil;
    OwnerItems := RootMenu.ParentControl.ActionBar.ActionClient.Items;
    for I := 0 to OwnerItems.Count - 1 do
      if OwnerItems[I].Action = MatchItem.Action then
      begin
        Result := OwnerItems[I];
        break;
      end;
  end;

var
  Item: TActionClientItem;
begin
  if not AnItem.Separator and (AnItem is MenuAddRemoveItemClass) then
  begin
    Item := FindItem(AnItem.ActionClient);
    if Assigned(Item) then
      Item.Visible := not Item.Visible
    else
    begin
      Item := TActionClientItem(RootMenu.ParentControl.ActionBar.ActionClient.Items.Insert(AnItem.ActionClient.Index));
      Item.Action := AnItem.ActionClient.Action;
    end;
    FActionBar.Realign;
    with FActionBar do
      FActionBar.SetBounds(Left, Top, Width, Height);
    Result := nil;
  end
  else if AnItem.ActionClient = FResetItem then
  begin
    CloseMenu;
    Result := AnItem.ActionClient;
    PostMessage(FActionBar.Handle, CM_RESETBAR, 0, 0);
  end
  else
    Result := inherited DoItemClicked(AnItem);
end;

function TCustomizeActionToolBar.DoGetPopupClass: TCustomPopupClass;
begin
  Result := MenuPopupClass;
end;

type
  TActionManagerClass = class(TCustomActionManager);

procedure TCustomizeActionToolBar.SetActionClient(
  const Value: TActionClient);

  procedure AddSeparator(ActionClients: TActionClients);
  begin
    with ActionClients.Add do
    begin
      Caption := '-';
      UsageCount := -1;
    end;
  end;

  procedure AddItems(ToItems, FromItems: TActionclients; Count: Integer);
  var
    I, X: Integer;
    Skip: Boolean;
    Item: TActionClientItem;
  begin
    for I := 0 to Count do
    begin
      Skip := False;
      for X := 0 to ToItems.Count - 1 do
        if ToItems[X].Action = FromItems[I].Action then
        begin
          Skip := True;
          break;
        end;
      if Skip then Continue;
      Item := ToItems.Add;
      Item.Assign(FromItems[I]);
      Item.Items := nil;
      Item.UsageCount := -1;
    end;
  end;

var
  ActionBarItem: TActionBarItem;
begin
  if Assigned(Value) and Assigned(FActionBar) then
  begin
    ActionBarItem := nil;
    if Assigned(FActionBar.ActionManager.DefaultActionBars) then
      with FActionBar do
        ActionBarItem := TActionBarItem(ActionManager.DefaultActionBars.FindItemID(ActionClient.Index));
    if Assigned(ActionBarItem) then
    begin
      if Value.Items.Count > 0 then
        AddSeparator(Value.Items);
      FAddlItem := Value.Items.Add;
      FAddlItem.Caption := SAddRemoveButtons;
      AddItems(FAddlItem.Items, ActionBarItem.Items, ActionBarItem.Items.Count - 1);
      with TActionBarItem(RootMenu.ParentControl.ActionBar.ActionClient) do
        AddItems(FAddlItem.Items, Items, Items.Count - 2);
      if ActionBarItem.Items.Count > 0 then
      begin
        FResetAction := TCustomAction.Create(Self);
        with FResetAction do
          Caption := SResetActionToolbar;
        if FAddlItem.Items.Count > 0 then
          AddSeparator(Value.Items);
        FResetItem := Value.Items.Add;
        with FResetItem do
        begin
          Action := FResetAction;
          UsageCount := -1;
        end;
      end;
    end;
  end;
  inherited SetActionClient(Value);
  ActionClient.Items.Customizable := False;
end;

procedure TCustomizeActionToolBar.CloseMenu;
begin
  inherited CloseMenu;
end;

{ TCustomizeActionLink }

procedure TCustomizeActionLink.SetEnabled(Value: Boolean);
begin
  if Assigned(FClient.Control) then
    FClient.Control.Enabled := True;
end;

{ TCustomizeActionClientItem }

function TCustomizeActionClientItem.GetActionLinkClass: TActionClientLinkClass;
begin
  Result := TCustomizeActionLink;
end;

{ TCustomActionMainMenuBar }

constructor TCustomActionMainMenuBar.Create(AOwner: TComponent);
var
  HotKeys: BOOL;
begin
  inherited Create(AOwner);
  Font.Assign(Screen.MenuFont);
  EdgeBorders := [ebTop];
  EdgeInner := esRaised;
  EdgeOuter := esLowered;
  SystemParametersInfo(SPI_GETMENUUNDERLINES, 0, @HotKeys, 0);
  Align := alTop;
  PersistentHotKeys := HotKeys;
  AllowHiding := False;
  HorzMargin := 1;
  Height := 29;
  AddMenuToList(Self);
  if (MenuKeyHook = 0) and not Assigned(ActionBarDesigner) then
    MenuKeyHook := SetWindowsHookEx(WH_GETMESSAGE, @GetMsgHook, 0,
      GetCurrentThreadID);
end;

procedure TCustomActionMainMenuBar.AlignControls(AControl: TControl;
  var Rect: TRect);
begin
  if AControl is TCustomActionPopupMenu then exit;
  inherited AlignControls(AControl, Rect);
end;

procedure TCustomActionMainMenuBar.WMKeyDown(var Message: TWMKeyDown);
var
  Popup: TCustomActionBar;
begin
  case Orientation of
    boLeftToRight,
    boRightToLeft:
      case Message.CharCode of
        VK_RIGHT: Select(Orientation = boLeftToRight);
        VK_LEFT : Select(Orientation <> boLeftToRight);
        VK_DOWN,
        VK_UP:
          if Assigned(Selected) and Assigned(Selected) then
          begin
            if DesignMode and not Selected.HasItems then
              if ssCtrl in KeyboardStateToShiftState then
              begin
                Selected.Items.Add;
                NotifyDesigner(Self);
              end
              else
                exit;
            if Selected.HasItems then
            begin
              Popup := CreatePopup(Self, Selected.Control);
              Popup.FindFirst.Control.Selected := True;
              Message.CharCode := 0;
              exit;
            end;
          end;
      end;
    boTopToBottom,
    boBottomToTop:
      case Message.CharCode of
        VK_RIGHT:
          if Assigned(Selected) and Assigned(Selected) and
             Selected.HasItems then
            Selected.Control.Keyed;
        VK_LEFT: Select(True);
      end;
  end;
  inherited;
end;

type
  TCustomFormType = class(TCustomForm);

function TCustomActionMainMenuBar.CreateControl(
  AnItem: TActionClientItem): TCustomActionControl;
begin
  Result := inherited CreateControl(AnItem);
  with Result as GetControlClass(AnItem) do
    Spacing := 2;
end;

function TCustomActionMainMenuBar.DesignWndProc(
  var Message: TMessage): Boolean;
begin
  if (Message.Msg =  WM_KEYDOWN) and ((Message.WParam = VK_RIGHT) or
     (Message.WParam = VK_LEFT) or (Message.WParam = VK_DOWN) or
     (Message.WParam = VK_UP)) then
    Result := True
  else
    Result := False;
end;

procedure TCustomActionMainMenuBar.DoneMenuLoop;
var
  HotKeys: BOOL;
begin
  inherited DoneMenuLoop;
  SystemParametersInfo(SPI_GETMENUUNDERLINES, 0, @HotKeys, 0);
  if not HotKeys then
    PersistentHotkeys := False;
end;

function TCustomActionMainMenuBar.GetControlClass(
  AnItem: TActionClientItem): TCustomActionControlClass;
begin
  Result := MenuButtonControlClass;
end;

procedure TCustomActionMainMenuBar.WMNCHitTest(var Message: TWMNCHitTest);
begin
  inherited;
  if DesignMode then
    Message.Result := HTCLIENT;
end;

procedure TCustomActionMainMenuBar.ProcessMouseMsg(var Msg: tagMSG);
var
  Item: TCustomActionControl;
begin
  inherited ProcessMouseMsg(Msg);
  case Msg.message of
    WM_LBUTTONDOWN,
    WM_RBUTTONDOWN:
      begin
        Item := GetMouseHoverItem(Msg);
        if Assigned(Item) then
        begin
          if (Item.Owner = Self) then
            if not Item.Selected then
              Item.Click;
        end
        else
        begin
          if not DesignMode then
            CloseMenu;
          DispatchMessage(Msg);
        end;
      end;
  end;
end;

procedure TCustomActionMainMenuBar.CMWininichange(var Message: TMessage);
begin
  inherited;
  Font.Assign(Screen.MenuFont);
  Resize;
end;

function TCustomActionMainMenuBar.CanAutoSize(var NewWidth,
  NewHeight: Integer): Boolean;
begin
  Result := False;
  if not AlignDisabled then
  begin
    NewHeight := GetBarHeight;
    NewWidth := GetBarWidth;
  end;
end;

procedure TCustomActionMainMenuBar.SetDesignMode(const Value: Boolean);
begin
  if DesignMode and not Value then
  begin
    ClearSubMenus;
    CloseMenu;
  end;
  inherited SetDesignMode(Value);
end;

procedure TCustomActionMainMenuBar.SetInActive(const Value: Boolean);
begin
  if FInActive <> Value then
  begin
    FInActive := Value;
    Invalidate;
  end;
end;

{ TCustomMenuItem }

constructor TCustomMenuItem.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle - [csCaptureMouse];
  Margins := Rect(2,0,10,0);
  Spacing := 5;   // Distance between Caption and ShortcutText
  if AOwner is TCustomActionMenuBar then
    FMenu := TCustomActionMenuBar(AOwner);
end;

destructor TCustomMenuItem.Destroy;
begin
  if Assigned(ActionClient) and (ActionClient.ChildActionBar is TCustomActionMenuBar) then
    TCustomActionMenuBar(ActionClient.ChildActionbar).CloseMenu;
  inherited Destroy;
end;

procedure TCustomMenuItem.DrawSubMenuGlyph;
const
  ArrowPos = 11;
  ArrowColor: array[Boolean] of Integer = (clBtnText, clWhite);
begin
  with Canvas do
  begin
    Pen.Color := ArrowColor[Selected];
    Brush.Color := Pen.Color;
  end;
  if Selected then
    Canvas.Pen.Color := clHighlightText;
  DrawArrow(Canvas, sdRight, Point(Width - ArrowPos, Height div 2 - 3), 3);
end;

procedure TCustomMenuItem.Paint;
var
  Flags: Cardinal;
  ShortCutRect: TRect;
begin
  inherited Paint;
  if IsChecked and not HasGlyph then
    DrawGlyph(GlyphPos);
  if ShowShortCut then
  begin
    Flags := DrawTextBiDiModeFlags(DT_RIGHT);
    ShortCutRect := FShortCutBounds;
    OffsetRect(ShortCutRect, Width - 21 - FShortCutBounds.Right, 0);
    DrawText(ShortCutRect, Flags, ActionClient.ShortCutText);
  end;
  if Assigned(ActionClient) and ActionClient.HasItems and
     (ActionClient.Items.VisibleCount > 0) then
    DrawSubMenuGlyph;
  DrawUnusedEdges;
end;

procedure TCustomMenuItem.DrawUnusedEdges;
const
  Edge: array[Boolean] of Integer = (BDR_RAISEDINNER, BDR_SUNKENOUTER);
var
  PaintRect: TRect;
begin
  PaintRect := ClientRect;
  if (ebTop in FEdges) then
    Windows.DrawEdge(Canvas.Handle, PaintRect, Edge[ActionClient.Unused], Byte(Edges));
  if (ebBottom in FEdges) then
    Windows.DrawEdge(Canvas.Handle, PaintRect, Edge[ActionClient.Unused], BF_BOTTOM);
  if (ebRight in FEdges) then
    if ebTop in Edges then
      Inc(PaintRect.Top);
end;

procedure TCustomMenuItem.Click;
begin
  GetParentForm(Menu.RootMenu).SetFocus;
// Do nothing here since menu items are only ever really clicked when the
// user lets the mouse button up while over an item
end;

function TCustomMenuItem.GetImageSize: TPoint;
begin
  Result := inherited GetImageSize;
  if (Result.X > 0) and (Result.X < 16) then
    Result.X := 16;
end;

procedure TCustomMenuItem.Keyed;
begin
  SetSelected(True);
  FMouseSelected := False;
  if Action is TCustomAction then
    with TCustomAction(Action) do
      if (GroupIndex > 0) and not AutoCheck then
        Checked := True;
  inherited Keyed;
end;

procedure TCustomMenuItem.SetEdges(const Value: TMenuEdges);
var
  NewHeight: Integer;
  LastItem: TActionClientItem;
begin
  if FEdges <> Value then
  begin
    NewHeight := Height;
    if (ebTop in Value) and not (ebTop in FEdges) then
      Inc(NewHeight)
    else
      if not (ebTop in Value) and (ebTop in FEdges) then
        Dec(NewHeight);
    if (ebBottom in Value) and not (ebBottom in FEdges) then
      Inc(NewHeight)
    else
      if not (ebBottom in Value) and (ebBottom in FEdges) then
        Dec(NewHeight);
    LastItem := ActionBar.FindLastVisibleItem;
    if Assigned(LastItem) and (Self = LastItem.Control) then
      Inc(NewHeight);
    FEdges := Value;
    Height := NewHeight;
    Invalidate;
  end;
end;

type
  TMenuActionBarClass = class(TCustomActionMenuBar);

procedure TCustomMenuItem.CMMouseEnter(var Message: TMessage);
begin
  inherited;
  if (DragMode = dmAutomatic) or Assigned(ActionClient) and
     Assigned(ActionClient.ChildActionBar) then
    exit;
  if csDesigning in ComponentState then
    SetSelected(True)
  else
    if not Separator then
    if Enabled then
    begin
      SetSelected(True);
      if not ActionBar.DesignMode then
        FMouseSelected := True;
    end
    else
      if Assigned(Menu) then
        with TMenuActionBarClass(Menu) do
          TMenuActionBarClass(RootMenu).DelayItem := nil;
end;

procedure TCustomMenuItem.SetSelected(Value: Boolean);
begin
  if not Value then
    FMouseSelected := False;
  inherited SetSelected(Value);
  if Assigned(Menu) then
    TMenuActionBarClass(Menu).DoItemSelected(Self);
end;

procedure TCustomMenuItem.DrawDesignFocus(var PaintRect: TRect);
begin
  with Canvas, ClientRect do
  begin
    Brush.Color := clHighlight;
    if not ActionClient.HasItems then
    begin
      Pen.Color := clBlack;
      Brush.Style := bsClear;
    end
    else
      Pen.Color := clGreen;
    Pen.Width := 2;
    if Assigned(ActionClient) and ActionClient.HasItems then
    begin
      PatBlt(Handle, Left, Top, Width, 2, PATINVERT);
      PatBlt(Handle, Left + Width - 4, Top + 2, 2, Height, PATINVERT);
      PatBlt(Handle, Left + 3, Top + Height - 2, Width - 7, 2, PATINVERT);
      PatBlt(Handle, Left + 1, Top + 2, 2, Height, PATINVERT);
    end
    else
    begin
      PaintRect := ClientRect;
      Inc(PaintRect.Left, 2);
      if ActionClient.Unused then
      begin
        Inc(PaintRect.Top);
        Dec(PaintRect.Bottom);
      end
      else
      begin
        Inc(PaintRect.Top);
        Dec(PaintRect.Right, 2);
      end;
      inherited DrawDesignFocus(PaintRect);
    end;
  end;
end;

procedure TCustomMenuItem.DragDrop(Source: TObject; X, Y: Integer);
begin
  inherited DragDrop(Source, X, Y);
  if (ActionBar is TCustomActionMenuBar) then
    with ActionBar as TCustomActionMenuBar do
      if (RootMenu <> nil) and Assigned(RootMenu.Parent) then
        Windows.SetFocus(RootMenu.Parent.Handle);
end;

procedure TCustomMenuItem.DragOver(Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  if (Source is TActionItemDragObject) then
    with Source as TActionItemDragObject do
    begin
      if (ActionClient = ClientItem) and
         (ActionClient.ChildActionBar is TCustomActionMenuBar) then
        with ActionClient.ChildActionBar as TCustomActionMenuBar do
          CloseMenu;
      if Assigned(Menu.RootMenu.DelayItem) and
         (Menu.RootMenu.DelayItem.ActionClient = ClientItem) then
        Menu.RootMenu.DelayItem := nil;
    end;
  inherited DragOver(Source, X, Y, State, Accept);
  if Accept and (ActionBar is TCustomActionMenuBar) then
    if TCustomActionMenuBar(ActionBar).InMenuLoop then
      Selected := True
end;

procedure TCustomMenuItem.CMTextchanged(var Message: TMessage);
begin
  inherited;
  if Separator then
    Height := GetSystemMetrics(SM_CYMENU) div 2
  else
    Height := GetSystemMetrics(SM_CYMENU);
end;

procedure TCustomMenuItem.CalcBounds;
const
  ImageOffset: array[Boolean] of Integer = (24, 0);
var
  AWidth, AHeight: Integer;
  NewTextBounds: TRect;
begin
  inherited CalcBounds;
  if Separator then
    AHeight := GetSystemMetrics(SM_CYMENU) div 3 * 2
  else
    if Height < GetSystemMetrics(SM_CYMENU) then
      AHeight := GetSystemMetrics(SM_CYMENU)
    else
      AHeight := Height;
  if ActionClient = nil then exit;
  NewTextBounds := TextBounds;
  OffsetRect(NewTextBounds, 24 - TextBounds.Left,
    AHeight div 2 - TextBounds.Bottom div 2 - 1);
  TextBounds := NewTextBounds;
  ShortCutBounds := Rect(0,0,0,0);
  if ActionClient.ShortCut <> 0 then
  begin
    Windows.DrawText(Canvas.Handle, PChar(ActionClient.ShortCutText), -1,
      FShortCutBounds, DT_CALCRECT);
    // Left offset is determined when the item is painted to make it ight justified
    OffsetRect(FShortCutBounds, 0, TextBounds.Top);
    AWidth := Width + FShortCutBounds.Right + ImageOffset[HasGlyph] + Spacing + 21;
  end
  else
    AWidth := TextBounds.Right + TextBounds.Left;
  SetBounds(Left, Top, AWidth, AHeight);
end;

procedure TCustomMenuItem.CalcLayout;
begin
  inherited CalcLayout;
  GlyphPos := Point(Margins.Left, Height div 2 - GetImageSize.Y div 2 + 1);
end;

procedure TCustomMenuItem.DrawEdge(Edges: TMenuEdges);
var
  Clrs: array[Boolean] of TColor;
begin
  Clrs[False] := GetHighLightColor(ActionBar.Color);
  Clrs[True] := GetShadowColor(ActionBar.Color);
  Canvas.Pen.Color := Clrs[False];
  Canvas.MoveTo(ClientRect.Right, ClientRect.Top);
  if ebTop in Edges then
    Canvas.LineTo(ClientRect.Left, ClientRect.Top)
  else
    Canvas.MoveTo(ClientRect.Left, ClientRect.Top);
  if ebLeft in Edges then
    Canvas.LineTo(ClientRect.Left, ClientRect.Bottom)
  else
    Canvas.MoveTo(ClientRect.Left, ClientRect.Bottom);
  Canvas.Pen.Color := Clrs[True];
  Canvas.Pen.Width := 1;
  Canvas.MoveTo(ClientRect.Right - 1, ClientRect.Top);
  Canvas.LineTo(ClientRect.Right - 1, ClientRect.Bottom);
  Canvas.MoveTo(ClientRect.Right - 2, ClientRect.Top);
  Canvas.Pen.Color := Clrs[True];
  if Assigned(ActionClient) and not ActionClient.Unused and (ebRight in Edges) then
    Canvas.LineTo(ClientRect.Right - 2, ClientRect.Bottom + 1)
  else
    Canvas.MoveTo(ClientRect.Right - 2, ClientRect.Bottom - 1);
  if ebBottom in Edges then
    Canvas.LineTo(ClientRect.Left, ClientRect.Bottom - 1);
end;

procedure TCustomMenuItem.PositionChanged;
begin
  inherited PositionChanged;
  if Assigned(ActionClient) then
    ActionClient.CheckUnused := True;
  if not TMenuActionBarClass(Menu).Expanded then
    TMenuActionBarClass(Menu).Expand(True);
end;

type
  TActionBarClass = class(TCustomActionBar);

procedure TCustomMenuItem.DoDragDrop(DragObject: TObject; X, Y: Integer);
var
  NewItem, NewCategory: TActionClientItem;
  I, Idx: Integer;
begin
  if Assigned(ActionClient) then
    Idx := ActionClient.Index
  else
    Idx := 0;

  if DragObject is TCategoryDragObject then
  begin
    ActionBar.DisableAlign;
    ActionBar.ActionClient.Items.BeginUpdate;
    with DragObject as TCategoryDragObject do
    begin
      with TActionManagerClass(ActionBar.ActionManager) do
        NewCategory :=  GetActionClientItemClass.Create(ActionBar.ActionClient.Items);
      try
        try
          NewCategory.UsageCount := 1;
          NewCategory.Caption := Category;
          NewCategory.LastSession := ActionBar.ActionManager.ActionBars.SessionCount;
          NewCategory.Index := Idx;
          NewCategory.Items.BeginUpdate;
          for I := 0 to ActionCount - 1 do
          begin
            NewItem := TActionClientItem.Create(NewCategory.Items);
            NewItem.Action := Actions[I];
            NewItem.LastSession := NewCategory.LastSession;
          end;
          TActionBarClass(ActionBar).CreateControl(NewCategory);
          NewCategory.Control.Enabled := ActionCount > 0;
        finally
          NewCategory.Items.EndUpdate;
        end;
      finally
        ActionBar.ActionClient.Items.EndUpdate;
        ActionBar.EnableAlign;
        NotifyDesigner(ActionBar);
      end;
    end;
  end
  else
    inherited DoDragDrop(DragObject, X, Y);
end;

procedure TCustomMenuItem.MouseUp(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  if Button <> mbLeft then exit;
  if Assigned(ActionClient) and Assigned(ActionClient.ChildActionBar) then exit;
  if Action is TCustomAction then
    with TCustomAction(Action) do
      if (GroupIndex > 0) and not AutoCheck then
        Checked := True;
  ResetUsageData;
  PostMessage(Parent.Handle, CM_ITEMCLICKED, 0, LongInt(Self));
end;

{ TCustomMenuButton }

procedure TCustomMenuButton.BeginAutoDrag;
begin
  Click;
  inherited BeginAutoDrag;
end;

procedure TCustomMenuButton.Click;
begin
  SetSelected(True);
  inherited Click;
  if Assigned(ActionClient) and not Assigned(ActionClient.Action) then
    PostMessage(ActionBar.Handle, CM_ITEMCLICKED, 0, LongInt(Self));
end;

procedure TCustomMenuButton.CMMouseEnter(var Message: TMessage);
begin
  inherited;
  if Assigned(ActionClient) and Assigned(ActionClient.Action) then exit;
  if ActionBar is TCustomActionMenuBar then
    if not ActionBar.DesignMode and not Selected and
       TCustomActionMenuBar(ActionBar).InMenuLoop then
      Click;
end;

destructor TCustomMenuButton.Destroy;
begin
  if Assigned(ActionClient) and (ActionClient.ChildActionBar is TCustomActionMenuBar) then
    TCustomActionMenuBar(ActionClient.ChildActionbar).CloseMenu;
  inherited Destroy;
end;

procedure TCustomMenuButton.DoDragDrop(DragObject: TObject; X, Y: Integer);
begin
  if DragObject is TCategoryDragObject then
  begin
    TActionBarClass(ActionBar).DoDropCategory(TCategoryDragObject(DragObject),
      Left + X, Top + Y);
  end
  else
    inherited DoDragDrop(DragObject, X, Y);
  if ActionBar is TCustomActionMenuBar then
    TCustomActionMenuBar(ActionBar).InMenuLoop := False;
end;

procedure TCustomMenuButton.DragOver(Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  inherited DragOver(Source, X, Y, State, Accept);
  if Accept and (ActionBar is TCustomActionMenuBar) then
  begin
    if Source is TActionItemDragObject then
      with Source as TActionItemDragObject do
        if (ClientItem = ActionClient) and Assigned(ActionBar) and
           (ActionBar is TCustomActionMenuBar) then
          with ActionBar as TCustomActionMenuBar do
            ClearSubMenus;
    if not Selected then
      Click;
  end;
end;

procedure TCustomMenuButton.DrawText(var ARect: TRect; var Flags: Cardinal;
  Text: string);
var
  S: string;
begin
  S := Text;
  if Parent is TCustomActionMainMenuBar then
    with Parent as TCustomActionMainMenuBar do
      if not PersistentHotkeys then
        if Pos('&', S) > 0 then
          Delete(S, Pos('&', S), 1);
  inherited DrawText(ARect, Flags, S);
end;

procedure TCustomMenuButton.Keyed;
begin
  SetSelected(True);
  inherited Keyed;
end;

procedure TCustomMenuButton.MouseDown(Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if (Button = mbLeft) and (ActionBar is TCustomActionMainMenuBar) and
     not TCustomActionMainMenuBar(ActionBar).InMenuLoop then
    Click
  else
    inherited MouseDown(Button, Shift, X, Y);
end;

procedure TCustomMenuButton.Paint;
var
  OldState: TButtonState;
begin
  OldState := State;
  if Assigned(ActionClient.ChildActionBar) then
    FState := bsDown;
  inherited Paint;
  FState := OldState;
end;

procedure TCustomActionPopupMenu.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if not (csDestroying in ComponentState) and (Operation = opRemove) then
    if AComponent is TControl then
      with AComponent as TControl do
      begin
        Visible := False;
        Resize;
      end;
end;

function TCustomizeActionToolBar.CanAutoSize(var NewWidth,
  NewHeight: Integer): Boolean;
begin
  Result := False;
end;

function TCustomActionMenuBar.NewPopup: TCustomActionPopupMenu;
begin
  Result := DoGetPopupClass.Create(Self);
end;

function TCustomizeActionToolBar.NewPopup: TCustomActionPopupMenu;
begin
  Result := inherited NewPopup;
  Result.OnGetControlClass := GetSubMenuControlClass;
end;

procedure TCustomizeActionToolBar.GetSubMenuControlClass(
  Sender: TCustomActionBar; AnItem: TActionClient;
  var ControlClass: TCustomActionControlClass);
begin
  if AnItem is TActionClientItem then
    with AnItem as TActionClientItem do
      if ParentItem = FAddlItem then
        ControlClass := MenuAddRemoveItemClass
      else
        ControlClass := MenuItemControlClass;
end;

procedure TCustomActionMainMenuBar.CloseMenu;
begin
  ClearSubMenus;
  inherited CloseMenu;
end;

initialization
  UpdateActnMenusProc := nil;
  MenuKeyHook := 0;
  MenuCallWndHook := 0;
  MenuList := nil;
end.
